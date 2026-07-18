#include "game/StageSceneManager.h"
#include "heap/seadHeapMgr.h"

namespace game {

StageSceneManager::StageSceneManager() {
    // should've been a FrameHeap, but that one is not implemented
    /*mHeap = sead::ClonableExpHeap::create(0x1EA00000, "SceneHeap", nullptr, 16,
                                          sead::Heap::cHeapDirection_Forward, false);*/
    mHeap = sead::ClonableExpHeap::create(0x3EA00000, "CustomSceneHeap", nullptr, 16,
                                          sead::Heap::cHeapDirection_Forward, false);
    {
        sead::ScopedCurrentHeapSetter scopedHeap(mHeap);

        Application::instance()->mSystemKit = new al::SystemKit();
        Application::instance()->mSystemKit->createMemorySystem(mHeap);
        Application::instance()->mSystemKit->createFileLoader(-1);
        Application::instance()->mSystemKit->createResourceSystem(0, -1, 0x400000, true);

    }
    {
        sead::ScopedCurrentHeapSetter scopedHeap(alProjectInterface::getSystemKit()->getMemorySystem()->getStationedHeap());
        al::createSequenceHeap();
        al::createSceneHeap("StageSceneHeap", false);
    }

    sead::ScopedCurrentHeapSetter scopedHeap(alProjectInterface::getSystemKit()->getMemorySystem()->getSceneHeap());
    mScene = new StageScene();
}

StageSceneManager::~StageSceneManager() {
    // delete mHeap;
}

}  // namespace game
