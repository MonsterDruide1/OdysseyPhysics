#include "game/StageScene.h"
#include <filesystem>
#include "Library/Area/AreaObjDirector.h"
#include "Library/Base/StringUtil.h"
#include "Library/Collision/CollisionDirector.h"
#include "Library/Execute/ExecuteDirector.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/LiveActor/LiveActorKit.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Placement/PlacementInfo.h"
#include "Library/Player/PlayerHolder.h"
#include "Library/Scene/ISceneObj.h"
#include "Library/Scene/SceneObjHolder.h"
#include "Library/Scene/SceneUtil.h"
#include "Library/Yaml/ByamlData.h"
#include "Library/Yaml/ByamlIter.h"
#include "Library/Yaml/ByamlUtil.h"
#include "Player/PlayerActorHakoniwa.h"
#include "Player/PlayerColliderHakoniwa.h"
#include "PlayerUtil.h"
#include "Scene/ProjectActorFactory.h"
#include "Scene/SceneObjFactory.h"
#include "game/Input.h"
#include "heap/seadHeapMgr.h"
#include "nlib/util.h"
#include "oead/sarc.h"
#include "oead/yaz0.h"
#include "settings.h"

namespace game {

StageScene::StageScene() : al::Scene("") {
    Input::createInstance();  // create here to allocate on heap of Scene
    mActors = new RaylibActor*[mActorsMax];
    mCamera = new Camera();
    mPartsKeeper = new CollisionPartsKeeper();
    mShinePositions = new sead::Vector3f[mShinesMax];

    //mLiveActorKit = new al::LiveActorKit(5120, 4);
    //mLiveActorKit->init(2);
}

StageScene::~StageScene() {
    for (int i = 0; i < mActorsNum; i++)
        delete mActors[i];
    delete[] mActors;
    delete mPlayer;
    delete mCamera;
    delete mPartsKeeper;
    delete[] mShinePositions;
}

void StageScene::init(const char* stageName, int scenario) {
    mLiveActorKit = new al::LiveActorKit(5120, 4);
    mLiveActorKit->init(4);
    al::SceneObjHolder* sceneObjHolder = SceneObjFactory::createSceneObjHolder();
    initSceneObjHolder(sceneObjHolder);

    std::string szsPath = nlib::util::format("res/mod/StageData/%s.szs", stageName);

    if (!std::filesystem::exists(szsPath)) {
        szsPath = nlib::util::format("%s/StageData/%s.szs", settings::sRomfsPath, stageName);

        if (!std::filesystem::exists(szsPath)) {
            printf("File does not exist: %s\n", szsPath.c_str());
            return;
        }
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

    ProjectActorFactory factory;
    for (int i = 0; i < objectlist.getSize(); i++) {
        al::ByamlIter objiter = objectlist.getIterByIndex(i);
        al::LiveActor* liveactor = nullptr;

        const char* className = nullptr;
        objiter.getIterByKey("UnitConfig").tryGetStringByKey(&className, "ParameterConfigName");
        if(className) {
            for (int i=0; i<factory.mNumFactoryEntries; i++) {
                if(al::isEqualString(factory.mFactoryEntries[i].name, className)) {
                    if(!factory.mFactoryEntries[i].creationFunction) {
                        printf("No creation function for class: %s\n", className);
                        break;
                    }

                    liveactor = factory.mFactoryEntries[i].creationFunction(className);
                    break;
                }
            }
        }

        if(!liveactor) {
            printf("Unknown class: %s\n", className ?: "nullptr");
            liveactor = new al::LiveActor("LiveActor");
        }
        al::PlacementInfo placement;
        placement.set(objiter, nullptr);
        al::ActorInitInfo info;
        al::initActorInitInfo(&info, this, &placement, nullptr, &factory, nullptr, nullptr);
        info.actorSceneInfo.sceneObjHolder = mSceneObjHolder;
        liveactor->init(info);
        RaylibActor::apply(liveactor, objiter);
        RaylibActor* actor = new RaylibActor(liveactor);
        actor->initCollision(objiter, mPartsKeeper);
        actor->initRaylibModel();
        addObject(actor);
        liveactor->initAfterPlacement();
        
        const char* unitConfigName;
        const char* itemType = nullptr;
        objiter.tryGetStringByKey(&unitConfigName, "UnitConfigName");
        objiter.tryGetStringByKey(&itemType, "ItemType");
        bool isShine = false;
        isShine |= strcmp(unitConfigName, "Shine") == 0;
        isShine |= strcmp(unitConfigName, "ShineAddHeight") == 0;
        isShine |= strcmp(unitConfigName, "TreasureBox") == 0 && itemType && strcmp(itemType, "Shine") == 0;
        if(isShine) {
            sead::Vector3f trans = {0, 0, 0};
            al::tryGetByamlV3f(&trans, objiter, "Translate");
            if(mShinesNum == mShinesMax) {
                printf("Too many shines\n");
                continue;
            }
            mShinePositions[mShinesNum++] = trans;
        }
    }

    al::ByamlIter playerStartInfoList = lists.getIterByKey("PlayerStartInfoList");
    for(int i=0; i<playerStartInfoList.getSize(); i++) {
        al::ByamlIter obj = playerStartInfoList.getIterByIndex(i);
        const char* unitConfigName;
        const char* itemType = nullptr;
        obj.tryGetStringByKey(&unitConfigName, "UnitConfigName");
        obj.tryGetStringByKey(&itemType, "ItemType");
        bool isShine = false;
        isShine |= strcmp(unitConfigName, "Shine") == 0;
        isShine |= strcmp(unitConfigName, "ShineAddHeight") == 0;
        isShine |= strcmp(unitConfigName, "TreasureBox") == 0 && itemType && strcmp(itemType, "Shine") == 0;
        if(isShine) {
            sead::Vector3f trans = {0, 0, 0};
            al::tryGetByamlV3f(&trans, obj, "Translate");
            if(mShinesNum == mShinesMax) {
                printf("Too many shines\n");
                continue;
            }
            mShinePositions[mShinesNum++] = trans;
        }
    }

    al::ByamlIter playerlist = lists.getIterByKey("PlayerList");
    if (playerlist.getSize() != 1) {
        printf("PlayerList size is not 1\n");
        return;
    }
    al::ExecuteDirector* executeDirector = new al::ExecuteDirector(512);
    al::CollisionDirector* collDirector = new al::CollisionDirector(executeDirector);
    al::AreaObjDirector* areaObjDirector = new al::AreaObjDirector();
    collDirector->setPartsKeeper(mPartsKeeper);
    PlayerActorHakoniwa* player = new PlayerActorHakoniwa("Player");
    al::PlacementInfo placementInfo = {};
    placementInfo.set(playerlist.getIterByIndex(0), al::ByamlIter());
    al::PlayerHolder* playerHolder = mLiveActorKit->mPlayerHolder;
    playerHolder->registerPlayer(player, new al::PadRumbleKeeper());
    al::ActorInitInfo actorInfo = {};
    actorInfo.initNew(&placementInfo, nullptr, nullptr, nullptr, nullptr, areaObjDirector, nullptr, nullptr,
                      nullptr, collDirector, nullptr, nullptr, executeDirector, nullptr, nullptr, nullptr,
                      nullptr, nullptr, nullptr, nullptr, playerHolder, mSceneObjHolder, nullptr, nullptr,
                      nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    al::ActorSceneInfo* sceneInfo =
        new al::ActorSceneInfo();  // allocate on heap to ensure persistence
    memcpy(sceneInfo, &actorInfo.actorSceneInfo, sizeof(al::ActorSceneInfo));
    player->initSceneInfo(sceneInfo);
    sead::Vector3f playerTrans;
    al::getTrans(&playerTrans, actorInfo);
    sead::Quatf playerQuat;
    al::getQuat(&playerQuat, actorInfo);
    PlayerInitInfo initInfo = {
        nullptr, mCamera->getViewMtxPtr(), 0, "", "", playerTrans, playerQuat, 0};
    RaylibActor::apply(player, playerlist.getIterByIndex(0));
    player->initPlayer(actorInfo, initInfo);
    mPlayer = new RaylibActor(player);
    mPlayer->initRaylibModel();
    mPlayer->initAfterPlacement();
    if(IsWindowReady())
        mPlayer->raylibModel.materials[0].maps->color = RED;
}

}  // namespace game
