#include "game/RaylibActor.h"
#include <cstdio>
#include <cstring>
#include <filesystem>
#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/KCollisionServer.h"
#include "Library/LiveActor/LiveActorFlag.h"
#include "Library/Matrix/MatrixUtil.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Yaml/ByamlUtil.h"
#include "RaylibUtil.h"
#include "nlib/util.h"
#include "oead/sarc.h"
#include "oead/yaz0.h"
#include "raylib.h"
#include "settings.h"

namespace game {

RaylibActor::RaylibActor(al::LiveActor* actor) : mActor(actor) {}

void RaylibActor::apply(al::LiveActor* actor, const al::ByamlIter& data) {
    if (!actor->mPoseKeeper)
        actor->mPoseKeeper = new al::ActorPoseKeeperTQGMSV();

    sead::Vector3f trans = {0, 0, 0};
    al::tryGetByamlV3f(&trans, data, "Translate");
    actor->mPoseKeeper->updatePoseTrans(trans);

    sead::Vector3f rotate = {0, 0, 0};
    al::tryGetByamlV3f(&rotate, data, "Rotate");
    actor->mPoseKeeper->updatePoseRotate(rotate);

    sead::Vector3f scale = {1, 1, 1};
    al::tryGetByamlV3f(&scale, data, "Scale");
    *actor->mPoseKeeper->getScalePtr() = scale;

    const char* modelName = nullptr;
    if (!al::tryGetByamlString(&modelName, data, "ModelName"))
        al::tryGetByamlString(&modelName, data, "UnitConfigName");

    actor->mActorName = new char[strlen(modelName) + 1];
    strcpy((char*)actor->mActorName, modelName);

    actor->mFlags->isDead = false;
}

RaylibActor::~RaylibActor() {
    // do not unload model completely if it is the fallback model
    if (raylibModel.meshCount != 1 || raylibModel.meshes[0].vertices != cubeMesh.vertices)
        UnloadModel(raylibModel);
    else {
        // manually clear relevant fields
        for (int i = 0; i < raylibModel.materialCount; i++)
            RL_FREE(raylibModel.materials[i].maps);
        RL_FREE(raylibModel.meshes);
        RL_FREE(raylibModel.materials);
        RL_FREE(raylibModel.meshMaterial);
    }
    delete mActor->mPoseKeeper;
    delete[] mActor->mActorName;
    if (mActor->mCollisionParts)
        delete mActor->mCollisionParts;
    if (kclData)
        delete[] kclData;
    if (collisionByml)
        delete[] collisionByml;
}

void RaylibActor::initCollision(const al::ByamlIter& data, CollisionPartsKeeper* keeper) {
    std::string szsPath = nlib::util::format("res/mod/ObjectData/%s.szs", mActor->mActorName);

    if (!std::filesystem::exists(szsPath)) {
        szsPath = nlib::util::format("%s/ObjectData/%s.szs", settings::sRomfsPath, mActor->mActorName);

        if (!std::filesystem::exists(szsPath)) {
            printf("File does not exist: %s\n", szsPath.c_str());
            return;
        }
    }

    std::vector<u8> szsData = nlib::util::readFile<u8>(szsPath);
    std::vector<u8> sarcData = oead::yaz0::Decompress(szsData);
    oead::Sarc sarc(sarcData);
    int kclIndex = -1;
    for (u16 i = 0; i < sarc.GetNumFiles(); i++) {
        const oead::Sarc::File& file = sarc.GetFile(i);
        if (file.name.ends_with(".kcl")) {
            kclIndex = i;
            break;
        }
    }
    if (kclIndex == -1) {
        dbg_printf("Actor has no collision: %s (%s)\n", mActor->mActorName, szsPath.c_str());
        return;
    }
    const oead::Sarc::File& kclFile = sarc.GetFile(kclIndex);

    int byamlIndex = -1;
    for (u16 i = 0; i < sarc.GetNumFiles(); i++) {
        const oead::Sarc::File& file = sarc.GetFile(i);
        if (file.name.compare(std::string(kclFile.name.substr(0, kclFile.name.size() - 4)) +
                              ("Attribute.byml")) == 0) {
            byamlIndex = i;
            break;
        }
    }
    if(byamlIndex == -1) {
        dbg_printf("Actor has corrupted collision: %s (%s)\n", mActor->mActorName, szsPath.c_str());
        CRASH
    }
    const oead::Sarc::File& bymlFile = sarc.GetFile(byamlIndex);

    try {
        kclData = new u8[kclFile.data.size()];
        memcpy(kclData, kclFile.data.data(), kclFile.data.size());
        collisionByml = new u8[bymlFile.data.size()];
        memcpy(collisionByml, bymlFile.data.data(), bymlFile.data.size());

        mActor->mCollisionParts = new al::CollisionParts(kclData, collisionByml);
        sead::Matrix34f mat;
        // al::makeMtxSRT
        mActor->mPoseKeeper->calcBaseMtx(&mat);
        al::preScaleMtx(&mat, *mActor->mPoseKeeper->getScalePtr());
        // ---
        if (data.getKeyIndex("Sensor") != -1)
            dbg_printf("Sensor-attribute exists, but is not implemented! (%s)\n", mActor->mActorName);
        mActor->mCollisionParts->mConnectedSensor = nullptr;

        mActor->mCollisionParts->initParts(mat);

        if (data.getKeyIndex("Joint") != -1)
            dbg_printf("Joint-attribute exists, but is not implemented! (%s)\n", mActor->mActorName);
        mActor->mCollisionParts->mJointMtx = nullptr;
        keeper->addCollisionParts(mActor->mCollisionParts);
    } catch (const nlib::Exception& ex) {
        dbg_printf("Invalid kcl: %s\n", mActor->mActorName);
    }
}

void RaylibActor::initRaylibModel() {
    if(!IsWindowReady())
        return;
    if (!mActor->mCollisionParts) {
        initFallbackModel();
        return;
    }

    const al::KCollisionServer& coll = mActor->mCollisionParts->getKCollisionServer();
    raylibModel = Model{0};
    raylibModel.materialCount = 1;
    raylibModel.materials = (Material*)RL_CALLOC(raylibModel.materialCount, sizeof(Material));
    raylibModel.materials[0] = LoadMaterialDefault();
    raylibModel.materials[0].shader = checkerShader;
    raylibModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].color =
        Color{(u8)GetRandomValue(150, 255), (u8)GetRandomValue(150, 255),
              (u8)GetRandomValue(150, 255), 255};

    raylibModel.meshCount = coll.getNumInnerKcl();
    raylibModel.meshes = (Mesh*)RL_CALLOC(raylibModel.meshCount, sizeof(Mesh));
    raylibModel.meshMaterial = (int*)RL_CALLOC(raylibModel.meshCount, sizeof(int));

    al::ByamlIter prismAttributes;
    const char* floorCode;
    for (int i = 0; i < coll.getNumInnerKcl(); i++) {
        Mesh& mesh = raylibModel.meshes[i];
        const al::KCPrismHeader* header = coll.getV1Header(i);

        raylibModel.meshMaterial[i] = 0;  // First material index
        mesh.triangleCount = coll.getTriangleNum(header);
        mesh.vertexCount = mesh.triangleCount * 3;
        mesh.vertices = (float*)MemAlloc(mesh.vertexCount * 3 * sizeof(float));
        mesh.normals = (float*)MemAlloc(mesh.vertexCount * 3 * sizeof(float));
        mesh.colors = (unsigned char*)MemAlloc(mesh.vertexCount * 4 * sizeof(unsigned char));

        for (int j = 0; j < mesh.triangleCount; j++) {
            const al::KCPrismData& prism = coll.getPrismData(j, header);
            for (int k = 0; k < 3; k++) {
                sead::Vector3f pos;
                coll.calcPosLocal(&pos, &prism, k, header);
                sead::Vector3f norm = coll.getFaceNormal(&prism, header);
                mesh.vertices[j * 9 + k * 3 + 0] = pos.x;
                mesh.vertices[j * 9 + k * 3 + 1] = pos.y;
                mesh.vertices[j * 9 + k * 3 + 2] = pos.z;
                mesh.normals[j * 9 + k * 3 + 0] = norm.x;
                mesh.normals[j * 9 + k * 3 + 1] = norm.y;
                mesh.normals[j * 9 + k * 3 + 2] = norm.z;
                mesh.colors[j * 12 + k * 4 + 0] = 255;
                mesh.colors[j * 12 + k * 4 + 1] = 255;
                mesh.colors[j * 12 + k * 4 + 2] = 255;
                mesh.colors[j * 12 + k * 4 + 3] = 0;  // alpha = 0 => disabled, use material color

                if (coll.getAttributes(&prismAttributes, &prism) && prismAttributes.tryGetStringByKey(&floorCode, "FloorCode")) {
                    if(strcmp(floorCode, "Poison") == 0) {
                        mesh.colors[j * 12 + k * 4 + 0] = 159;
                        mesh.colors[j * 12 + k * 4 + 1] = 50;
                        mesh.colors[j * 12 + k * 4 + 2] = 168;
                        mesh.colors[j * 12 + k * 4 + 3] = 255;
                    } else if(strcmp(floorCode, "Ground") == 0) {
                        mesh.colors[j * 12 + k * 4 + 0] = 194;
                        mesh.colors[j * 12 + k * 4 + 1] = 167;
                        mesh.colors[j * 12 + k * 4 + 2] = 175;
                        mesh.colors[j * 12 + k * 4 + 3] = 255;
                    } else {
                        printf("Unknown floor code: %s\n", floorCode);
                    }
                }
            }
        }

        UploadMesh(&mesh, false);
    }
}

void RaylibActor::initFallbackModel() {
    raylibModel = LoadModelFromMesh(cubeMesh);
    raylibModel.materials[0].maps->color = BLUE;
}

}  // namespace game
