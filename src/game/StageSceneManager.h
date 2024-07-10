#pragma once

#include "game/StageScene.h"
#include "heap/ClonableExpHeap.h"
#include "heap/seadHeapMgr.h"

namespace game {

class StageSceneManager {
public:
    StageSceneManager();
    ~StageSceneManager();

    void init(const char* stageName, int scenario) {
        sead::ScopedCurrentHeapSetter scopedHeap(mHeap);
        getScene()->init(stageName, scenario);
    }

    StageScene* getScene() { return (StageScene*)(mHeap->mUseList.front()->memory()); }

public:
    sead::ClonableExpHeap* mHeap;
};

}  // namespace game
