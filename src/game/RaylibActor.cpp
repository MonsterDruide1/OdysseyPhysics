#include "game/RaylibActor.h"
#include <cstdio>
#include <cstring>
#include <filesystem>
#include "Library/Base/StringUtil.h"
#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/KCollisionServer.h"
#include "Library/LiveActor/LiveActorFlag.h"
#include "Library/Matrix/MatrixUtil.h"
#include "Library/Model/ModelKeeper.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Yaml/ByamlUtil.h"
#include "RaylibUtil.h"
#include "filedevice/seadFileDevice.h"
#include "raylib.h"
#include "resource/seadArchiveRes.h"
#include "resource/seadResourceMgr.h"
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

    actor->mName = new char[strlen(modelName) + 1];
    strcpy((char*)actor->mName, modelName);

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
    delete[] mActor->mName;
    if (mActor->mCollisionParts)
        delete mActor->mCollisionParts;
    if (kclData)
        delete[] kclData;
    if (collisionByml)
        delete[] collisionByml;
}

static sead::ArchiveRes* loadSarc(const sead::SafeString& path, sead::FileDevice* device) {
    sead::ResourceMgr::LoadArg loadArg;
    loadArg.device = device;
    loadArg.path = path;
    loadArg.load_data_alignment = 0;
    loadArg.load_data_buffer_alignment = 0;

    sead::Resource* resource =
        sead::ResourceMgr::instance()->tryLoad(loadArg, "sarc", nullptr);
    return sead::DynamicCast<sead::ArchiveRes>(resource);
}

void RaylibActor::initCollision(const al::ByamlIter& data, CollisionPartsKeeper* keeper) {
    sead::ArchiveRes* sarc = loadSarc(((std::string) "ObjectData/"+mActor->mName+".szs").c_str(), nullptr);

    constexpr u32 ENTRIES_NUM = 512;
    sead::HandleBuffer handle{};
    sead::DirectoryEntry entries[ENTRIES_NUM];
    u32 files_num = sarc->readDirectory(&handle, entries, ENTRIES_NUM);

    int kclIndex = -1;
    for (u16 i = 0; i < files_num; i++) {
        if (al::isEndWithString(entries[i].name.cstr(), ".kcl")) {
            kclIndex = i;
            break;
        }
    }
    if (kclIndex == -1) {
        dbg_printf("Actor has no collision: %s\n", mActor->mName);
        return;
    }
    sead::ArchiveRes::FileInfo kclFileInfo;
    const auto* kclFile = sarc->getFile(entries[kclIndex].name.cstr(), &kclFileInfo);

    int byamlIndex = -1;
    for (u16 i = 0; i < files_num; i++) {
        if (al::isEqualString(entries[i].name.cstr(), (std::string(entries[kclIndex].name.cstr()).substr(0, entries[kclIndex].name.calcLength() - 4) + ("Attribute.byml")).c_str())) {
            byamlIndex = i;
            break;
        }
    }
    if(byamlIndex == -1) {
        dbg_printf("Actor has corrupted collision: %s\n", mActor->mName);
        CRASH
    }
    sead::ArchiveRes::FileInfo bymlFileInfo;
    const auto* bymlFile = sarc->getFile(entries[byamlIndex].name.cstr(), &bymlFileInfo);

    kclData = new u8[kclFileInfo.mLength];
    memcpy(kclData, kclFile, kclFileInfo.mLength);
    collisionByml = new u8[bymlFileInfo.mLength];
    memcpy(collisionByml, bymlFile, bymlFileInfo.mLength);

    mActor->mCollisionParts = new al::CollisionParts(kclData, collisionByml);
    sead::Matrix34f mat;
    // al::makeMtxSRT
    mActor->mPoseKeeper->calcBaseMtx(&mat);
    al::preScaleMtx(&mat, *mActor->mPoseKeeper->getScalePtr());
    // ---
    if (data.getKeyIndex("Sensor") != -1)
        dbg_printf("Sensor-attribute exists, but is not implemented! (%s)\n", mActor->mName);
    mActor->mCollisionParts->mConnectedSensor = nullptr;

    mActor->mCollisionParts->initParts(mat);

    if (data.getKeyIndex("Joint") != -1)
        dbg_printf("Joint-attribute exists, but is not implemented! (%s)\n", mActor->mName);
    mActor->mCollisionParts->mJointMtx = nullptr;
    keeper->addCollisionParts(mActor->mCollisionParts);
}

void RaylibActor::initRaylibModel() {
    if(!IsWindowReady())
        return;
    if (!mActor->mCollisionParts) {
        initFallbackModel();
        return;
    }

    const al::KCollisionServer& coll = *mActor->mCollisionParts->getKCollisionServer();
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
