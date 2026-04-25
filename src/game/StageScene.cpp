#include "game/StageScene.h"
#include <filesystem>
#include "Library/Area/AreaObjDirector.h"
#include "Library/Base/StringUtil.h"
#include "Library/Collision/CollisionDirector.h"
#include "Library/Execute/ExecuteDirector.h"
#include "Library/LiveActor/ActorInitFunction.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/LiveActor/ActorInitUtil.h"
#include "Library/LiveActor/LiveActorGroup.h"
#include "Library/LiveActor/LiveActorKit.h"
#include "Library/Memory/HeapUtil.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Placement/PlacementInfo.h"
#include "Library/Player/PlayerHolder.h"
#include "Library/Resource/ActorResourceHolder.h"
#include "Library/Resource/ResourceFunction.h"
#include "Library/Scene/ISceneObj.h"
#include "Library/Scene/SceneObjHolder.h"
#include "Library/Scene/SceneObjUtil.h"
#include "Library/Scene/SceneUtil.h"
#include "Library/System/GameSystemInfo.h"
#include "Library/Yaml/ByamlData.h"
#include "Library/Yaml/ByamlIter.h"
#include "Library/Yaml/ByamlUtil.h"
#include "Project/Controller/PadRumbleKeeper.h"
#include "Player/PlayerActorHakoniwa.h"
#include "Player/PlayerColliderHakoniwa.h"
#include "PlayerUtil.h"
#include "Project/Execute/ExecuteSystemInitInfo.h"
#include "Project/Memory/Util.h"
#include "Project/Scene/SceneInitInfo.h"
#include "Scene/ProjectActorFactory.h"
#include "Scene/ProjectAreaFactory.h"
#include "Scene/SceneObjFactory.h"
#include "System/GameDataHolder.h"
#include "game/Input.h"
#include "heap/seadHeapMgr.h"
#include "resource/seadArchiveRes.h"
#include "resource/seadResourceMgr.h"
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

void StageScene::init(const char* stageName, int scenario) {
    al::addResourceCategory("シーン", 0x200, sead::HeapMgr::instance()->getCurrentHeap());
    al::addResourceCategory("シーン", 0x200, sead::HeapMgr::instance()->getCurrentHeap());
    al::setCurrentCategoryName("シーン");

    al::DrawSystemInfo drawSystemInfo;
    mDrawSystemInfo = &drawSystemInfo;
    al::GameSystemInfo gameSystemInfo = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                                         nullptr, &drawSystemInfo, nullptr, nullptr, nullptr, nullptr};
    GameDataHolder* holder = new GameDataHolder(nullptr);
    
    al::SceneInitInfo sceneInitInfo = {&gameSystemInfo, holder, nullptr, stageName, scenario, "", nullptr};
    al::Scene::initLiveActorKit(sceneInitInfo, 5120, 4, 2);
    al::SceneObjHolder* sceneObjHolder = SceneObjFactory::createSceneObjHolder();
    initSceneObjHolder(sceneObjHolder);
    al::setSceneObj(this, holder);
    
    al::AreaObjDirector* areaObjDirector = mLiveActorKit->getAreaObjDirector();
    areaObjDirector->init(new ProjectAreaFactory());

    sead::ArchiveRes* sarc = loadSarc(((std::string) "StageData/"+stageName+".szs").c_str(), nullptr);
    const auto* file = sarc->getFile(((std::string) stageName + ".byml").c_str());

    al::ByamlIter iter = al::ByamlIter((const u8*)file);
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

        bool unknown = false;
        if(!liveactor) {
            printf("Unknown class: %s\n", className ?: "nullptr");
            liveactor = new al::LiveActor("LiveActor");
            unknown = true;
        }
        al::PlacementInfo placement;
        placement.set(objiter, nullptr);
        al::ActorInitInfo info;
        al::initActorInitInfo(&info, this, &placement, nullptr, &factory, nullptr, holder);
        info.actorSceneInfo.sceneObjHolder = mSceneObjHolder;
        liveactor->init(info);
        if (unknown) {
            const char* suffix = nullptr;
            al::tryGetStringArg(&suffix, info, "Suffix");
            al::initMapPartsActor(liveactor, info, suffix);
        }
        RaylibActor::apply(liveactor, objiter);
        RaylibActor* actor = new RaylibActor(liveactor);
        if (actor->mActor->getCollisionParts())
            mPartsKeeper->addCollisionParts(actor->mActor->getCollisionParts());/**/
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
    executeDirector->init({});
    al::CollisionDirector* collDirector = mLiveActorKit->getCollisionDirector();
    al::LiveActorGroup* allActorsGroup = mLiveActorKit->getLiveActorGroupAllActors();
    collDirector->setPartsKeeper(mPartsKeeper);
    PlayerActorHakoniwa* player = new PlayerActorHakoniwa("Player");
    al::PlacementInfo placementInfo = {};
    placementInfo.set(playerlist.getIterByIndex(0), al::ByamlIter());
    al::PlayerHolder* playerHolder = mLiveActorKit->mPlayerHolder;
    al::ActorResourceHolder* actorResourceHolder = mLiveActorKit->mActorResourceHolder;
    playerHolder->registerPlayer(player, new al::PadRumbleKeeper(0));
    al::ActorInitInfo actorInfo = {};
    actorInfo.initNew(&placementInfo, nullptr, allActorsGroup, nullptr, actorResourceHolder, areaObjDirector, nullptr, nullptr,
                      mLiveActorKit->mClippingDirector, collDirector, nullptr, nullptr, executeDirector, holder, nullptr, nullptr,
                      nullptr, nullptr, nullptr, nullptr, playerHolder, mSceneObjHolder, nullptr, nullptr,
                      nullptr, nullptr, nullptr, nullptr, nullptr, mLiveActorKit->getGraphicsSystemInfo(), nullptr, nullptr);

    sead::Vector3f playerTrans;
    al::getTrans(&playerTrans, actorInfo);
    sead::Quatf playerQuat;
    al::getQuat(&playerQuat, actorInfo);
    PlayerInitInfo initInfo = {
        nullptr, mCamera->getViewMtxPtr(), 0, "", "", playerTrans, playerQuat, 0};

    // 0x7100444028;
    al::initActorSceneInfo(player, actorInfo);
    al::initActorPoseTQGSV(player);
    al::initActorSRT(player, actorInfo);
    const char* modelName = al::StringTmp<256> {"ObjectData/%s", rs::getInitPlayerModelName(initInfo)}.cstr();
    al::initActorModelKeeper(player, actorInfo, modelName, 6, "ObjectData/PlayerAnimation");

    RaylibActor::apply(player, playerlist.getIterByIndex(0));
    player->initPlayer(actorInfo, initInfo);
    mPlayer = new RaylibActor(player);
    mPlayer->initRaylibModel();
    mPlayer->initAfterPlacement();
    if(IsWindowReady())
        mPlayer->raylibModel.materials[0].maps->color = RED;
}

}  // namespace game
