#include "seadInterface.h"

#include "heap/seadExpHeap.h"
#include "heap/seadHeapMgr.h"
#include "thread/seadThread.h"

void initializeSead() {
    sead::HeapMgr::initialize(0xBFC00000);
    sead::Heap* threadMgrHeap = sead::ExpHeap::create(0, "sead::ThreadMgr", sead::HeapMgr::getRootHeap(0), 16, sead::Heap::cHeapDirection_Forward, 0);
    sead::ThreadMgr::createInstance(threadMgrHeap);
    sead::HeapMgr::instance()->setCurrentHeap_(threadMgrHeap);
    //sead::ThreadMgr::instance()->initialize(threadMgrHeap);
}

void unloadSead() {
    sead::ThreadMgr::deleteInstance();
    sead::HeapMgr::sInstancePtr = nullptr;
}
