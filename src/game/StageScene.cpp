#include "game/StageScene.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Placement/PlacementInfo.h"
#include "Library/Yaml/ByamlData.h"
#include "Library/Yaml/ByamlIter.h"
#include "Player/PlayerActorHakoniwa.h"
#include "Player/PlayerColliderHakoniwa.h"
#include "heap/seadExpHeap.h"
#include "heap/seadHeapMgr.h"
#include "nlib/util.h"
#include "oead/sarc.h"
#include "oead/yaz0.h"
#include <filesystem>
#include "PlayerUtil.h"

namespace game {

StageScene::StageScene() {
    // should've been a FrameHeap, but that one is not implemented
    mHeap = sead::ExpHeap::create(0x1EA00000, "SceneHeap", nullptr, 16, sead::Heap::cHeapDirection_Forward, false);
    sead::ScopedCurrentHeapSetter scopedHeap(mHeap);

    mActors = new RaylibActor*[mActorsMax];
    mCamera = new Camera();
    mPartsKeeper = new CollisionPartsKeeper();
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
    sead::ScopedCurrentHeapSetter scopedHeap(mHeap);

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
        al::LiveActor* liveactor = new al::LiveActor("LiveActor");
        RaylibActor::apply(liveactor, objiter);
        RaylibActor* actor = new RaylibActor(liveactor);
        actor->initCollision(objiter, mPartsKeeper);
        actor->initRaylibModel();
        addObject(actor);
        //actor->initAfterPlacement();
    }

    al::ByamlIter playerlist = lists.getIterByKey("PlayerList");
    if(playerlist.getSize() != 1) {
        printf("PlayerList size is not 1\n");
        return;
    }
    al::CollisionDirector* collDirector = new al::CollisionDirector(nullptr);
    collDirector->setPartsKeeper(mPartsKeeper);
    PlayerActorHakoniwa* player = new PlayerActorHakoniwa("Player");
    al::PlacementInfo* placementInfo = new al::PlacementInfo();
    placementInfo->set(playerlist.getIterByIndex(0), al::ByamlIter());
    al::ActorInitInfo actorInfo = {};
    actorInfo.initNew(placementInfo, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, collDirector, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    al::ActorSceneInfo* sceneInfo = new al::ActorSceneInfo(); // allocate on heap to ensure persistence
    memcpy(sceneInfo, &actorInfo.mActorSceneInfo, sizeof(al::ActorSceneInfo));
    player->initSceneInfo(sceneInfo);
    sead::Vector3f playerTrans;
    al::getTrans(&playerTrans, actorInfo);
    sead::Quatf playerQuat;
    al::getQuat(&playerQuat, actorInfo);
    PlayerInitInfo initInfo = {nullptr, mCamera->getViewMtxPtr(), 0, "", "", playerTrans, playerQuat, 0};
    player->initPlayer(actorInfo, initInfo);
    //RaylibActor::apply(player, playerlist.getIterByIndex(0));
    mPlayer = new RaylibActor(player);
    mPlayer->initRaylibModel();
    mPlayer->initAfterPlacement();
    mPlayer->raylibModel.materials[0].maps->color = RED;
}

}
