#include "game/LiveActor.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Yaml/ByamlUtil.h"
#include "file/KCollision.h"
#include "nlib/util.h"
#include "oead/sarc.h"
#include "oead/yaz0.h"
#include "raylib.h"
#include <cstdio>
#include <filesystem>

namespace game {

Shader checkerShader;
Mesh cubeMesh;

LiveActor::LiveActor(const al::ByamlIter& data) {
    mPoseKeeper = new al::ActorPoseKeeperTQSV();

    sead::Vector3f trans = {0,0,0};
    al::tryGetByamlV3f(&trans, data, "Translate");
    mPoseKeeper->updatePoseTrans(trans);

    sead::Vector3f rotate = {0,0,0};
    al::tryGetByamlV3f(&rotate, data, "Rotate");
    mPoseKeeper->updatePoseRotate(rotate);

    sead::Vector3f scale = {1,1,1};
    al::tryGetByamlV3f(&scale, data, "Scale");
    *mPoseKeeper->getScalePtr() = scale;

    const char* modelName = nullptr;
    if(!al::tryGetByamlString(&modelName, data, "ModelName"))
        al::tryGetByamlString(&modelName, data, "UnitConfigName");
    initRaylibModel(modelName);

    mName = new char[strlen(modelName)+1];
    strcpy((char*)mName, modelName);
}

LiveActor::~LiveActor() {
    UnloadModel(raylibModel);
    delete mPoseKeeper;
    delete[] mName;
}

void LiveActor::initRaylibModel(const char* modelName) {
    std::string szsPath = nlib::util::format("res/romfs/ObjectData/%s.szs", modelName);

    if (!std::filesystem::exists(szsPath)) {
        printf("File does not exist: %s\n", szsPath.c_str());
        initFallbackModel();
        return;
    }

    std::vector<u8> szsData = nlib::util::readFile<u8>(szsPath);
    std::vector<u8> sarcData = oead::yaz0::Decompress(szsData);
    oead::Sarc sarc(sarcData);
    const oead::Sarc::File* kclFile = nullptr;
    for(u16 i=0; i<sarc.GetNumFiles(); i++) {
        const oead::Sarc::File& file = sarc.GetFile(i);
        if(file.name.ends_with(".kcl")) {
            kclFile = &file;
            break;
        }
    }
    if (!kclFile) {
        printf("Actor has no collision: %s (%s)\n", modelName, szsPath.c_str());
        initFallbackModel();
        return;
    }

    try {
        fl::KCL kcl(kclFile->data);
        std::string objName = nlib::util::format("%s.obj", kclFile->name.data());
        std::string mtlName = nlib::util::format("%s.mtl", kclFile->name.data());
        std::string objStr = nlib::util::format("mtllib %s\n", mtlName.c_str());
        objStr.append(kcl.toObj());
        std::string mtlStr = kcl.toMtl();
        std::vector<u8> obj(objStr.begin(), objStr.end());
        std::vector<u8> mtl(mtlStr.begin(), mtlStr.end());

        nlib::util::writeFile(objName, std::span<const u8>(obj));
        nlib::util::writeFile(mtlName, std::span<const u8>(mtl));
        raylibModel = LoadModel(objName.c_str());

        Color colors[] = {WHITE, RED,     BLUE,   GREEN,      YELLOW, ORANGE, PINK,
                          LIME,  SKYBLUE, PURPLE, DARKPURPLE, BROWN,  BLACK};

        for (int i = 0; i < raylibModel.materialCount; i++) {
            raylibModel.materials[i].maps->color = colors[i % 11];
            raylibModel.materials[i].shader = checkerShader;
        }

        std::filesystem::remove(objName);
        std::filesystem::remove(mtlName);

        printf("Loaded model: %s\n", modelName);
    } catch (const nlib::Exception& ex) {
        printf("Invalid kcl: %s\n", modelName);
        initFallbackModel();
    }
}

void LiveActor::initFallbackModel() {
    raylibModel = LoadModelFromMesh(cubeMesh);
    raylibModel.materials[0].maps->color = BLUE;
}

}
