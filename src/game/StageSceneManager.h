#pragma once

#include "Library/Layout/LayoutSystem.h"
#include "Library/Memory/HeapUtil.h"
#include "Library/System/GameSystemInfo.h"
#include "Library/System/SystemKit.h"
#include "Project/Memory/MemorySystem.h"
#include "Audio/CollectBgmPlayer.h"
#include "Scene/StageScene.h"
#include "System/GameDataHolder.h"
#include "System/Application.h"
#include "System/ProjectInterface.h"
#include "heap/ClonableExpHeap.h"
#include "heap/seadHeapMgr.h"

namespace game {

class StageSceneManager {
public:
    StageSceneManager();
    ~StageSceneManager();

    void init(const char* stageName, int scenario) {
        sead::ScopedCurrentHeapSetter scopedHeap(alProjectInterface::getSystemKit()->getMemorySystem()->getSceneHeap());

        al::GameSystemInfo* gameSystemInfo = new al::GameSystemInfo();
        
        al::LayoutSystem* layout = new al::LayoutSystem();
        //layout->init();
        gameSystemInfo->layoutSystem = layout;
        
        GameDataHolder* gameDataHolder = new GameDataHolder(nullptr);

        getScene()->mCollectBgmPlayer = new CollectBgmPlayer();
        getScene()->init({
            gameSystemInfo, gameDataHolder, nullptr,
            stageName, scenario,
            stageName, nullptr,
        });
    }

    // TODO: work around this to get savestates to work again.
    // formerly: return (::StageScene*)(mHeap->mUseList.front()->memory());
    ::StageScene* getScene() { return mScene; }

public:
    sead::ClonableExpHeap* mHeap;
    ::StageScene* mScene;
};

}  // namespace game
