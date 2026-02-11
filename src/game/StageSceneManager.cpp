#include "game/StageSceneManager.h"
#include "game/StageScene.h"
#include "heap/seadHeapMgr.h"

namespace game {

StageSceneManager::StageSceneManager() {
    // should've been a FrameHeap, but that one is not implemented
    mHeap = sead::ClonableExpHeap::create(0x1EA00000, "SceneHeap", nullptr, 16,
                                          sead::Heap::cHeapDirection_Forward, false);
    sead::ScopedCurrentHeapSetter scopedHeap(mHeap);

    StageScene* scene = new StageScene();
}

StageSceneManager::~StageSceneManager() {
    // delete mHeap;
}

}  // namespace game
