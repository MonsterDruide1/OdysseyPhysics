#include "game/StageScene.h"
#include "Library/Yaml/ByamlData.h"
#include "Library/Yaml/ByamlIter.h"
#include "nlib/util.h"
#include "oead/sarc.h"
#include "oead/yaz0.h"
#include <filesystem>

namespace game {

StageScene::StageScene() {
    mActors = new LiveActor*[mActorsMax];
    mCamera = new Camera();
    mPartsKeeper = new CollisionPartsKeeper();
    mInfo = {mPartsKeeper};
}

StageScene::~StageScene()
{
    for(int i=0; i<mActorsNum; i++)
        delete mActors[i];
    delete[] mActors;
    delete mPlayer;
    delete mCamera;
    delete mPartsKeeper;
}

void StageScene::init(const char* stageName, int scenario) {
    std::string szsPath = nlib::util::format("res/romfs/StageData/%s.szs", stageName);

    if (!std::filesystem::exists(szsPath)) {
        printf("File does not exist: %s\n", szsPath.c_str());
        return;
    }

    std::vector<u8> szsData = nlib::util::readFile<u8>(szsPath);
    std::vector<u8> sarcData = oead::yaz0::Decompress(szsData);
    oead::Sarc sarc(sarcData);
    const auto& file = sarc.GetFile(nlib::util::format("%s.byml", stageName));
    if (!file.has_value()) {
        printf("File has no value: %s (%s)\n", stageName, szsPath.c_str());
        return;
    }

    al::ByamlIter iter = al::ByamlIter(file->data.data());
    al::ByamlIter lists = iter.getIterByIndex(scenario);
    al::ByamlIter objectlist = lists.getIterByKey("ObjectList");

    for(int i=0; i<objectlist.getSize(); i++) {
        al::ByamlIter objiter = objectlist.getIterByIndex(i);
        addObject(new LiveActor(objiter, mInfo));
    }

    al::ByamlIter playerlist = lists.getIterByKey("PlayerList");
    if(playerlist.getSize() != 1) {
        printf("PlayerList size is not 1\n");
        return;
    }
    mPlayer = new Player(playerlist.getIterByIndex(0), mInfo);
    mPlayer->raylibModel.materials[0].maps->color = RED;
}

}
