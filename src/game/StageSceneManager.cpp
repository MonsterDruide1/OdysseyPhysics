#include "game/StageSceneManager.h"
#include "game/StageScene.h"
#include "heap/seadHeapMgr.h"

namespace game {

StageSceneManager::StageSceneManager() {
    // should've been a FrameHeap, but that one is not implemented
    // original size: 0x1EA00000, optimized to be sufficient for the current use case
    mHeap = sead::ClonableExpHeap::create(0x3000000, "SceneHeap", nullptr, 16,
                                          sead::Heap::cHeapDirection_Forward, false);
    sead::ScopedCurrentHeapSetter scopedHeap(mHeap);

    StageScene* scene = new StageScene();
}

StageSceneManager::~StageSceneManager() {
    // delete mHeap;
}

}  // namespace game
