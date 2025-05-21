#include "seadInterface.h"

#include "heap/seadExpHeap.h"
#include "heap/seadHeapMgr.h"
#include "random/seadGlobalRandom.h"
#include "resource/seadResourceMgr.h"
#include "resource/seadSZSDecompressor.h"
#include "resource/seadSharcArchiveRes.h"
#include "thread/seadThread.h"
#include "yaz0.h"

void sead::system::HaltWithDetail(const char* file, int line, const char* message, ...) {
    printf("HaltWithDetail: %s:%d: ", file, line);
    va_list args;
    va_start(args, message);
    vprintf(message, args);
    va_end(args);
    printf("\n");
    DEREF_NULL;
}

void sead::system::HaltWithDetailNoFormat(const char* file, int line, const char* message) {
    printf("HaltWithDetailNoFormat: %s:%d: %s\n", file, line, message);
    DEREF_NULL;
}

void sead::system::Warning(const char* file, int line, const char* message, ...) {
    printf("Warning: %s:%d: ", file, line);
    va_list args;
    va_start(args, message);
    vprintf(message, args);
    va_end(args);
    printf("\n");
}

void sead::system::Print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void initializeSead() {
    sead::HeapMgr::initialize(0xBFC00000);
    sead::Heap* threadMgrHeap =
        sead::ExpHeap::create(0, "sead::ThreadMgr", sead::HeapMgr::getRootHeap(0), 16,
                              sead::Heap::cHeapDirection_Forward, 0);
    sead::ThreadMgr::createInstance(threadMgrHeap);
    sead::HeapMgr::instance()->setCurrentHeap_(threadMgrHeap);
    // sead::ThreadMgr::instance()->initialize(threadMgrHeap);
    sead::GlobalRandom::createInstance(threadMgrHeap);

    sead::ResourceMgr::createInstance(threadMgrHeap);
    sead::ResourceMgr::instance()->registerFactory(
        new sead::DirectResourceFactory<sead::SharcArchiveRes>(), "sarc");
    sead::ResourceMgr::instance()->registerFactory(
        new sead::DirectResourceFactory<sead::SharcArchiveRes>(), "aras");

    s32 decompressDestinationSize = 0x400000;
    u8* decompressDestination = new (0x20) u8[decompressDestinationSize];
    sead::ResourceMgr::instance()->registerDecompressor(new sead::SZSDecompressor(decompressDestinationSize / 2, decompressDestination), "szs");
}

s32 decodeSZSNxAsm64_(void* dst, const void* src) {
    Yaz0::Decompress((const char*)src, (char*)dst);
    return 0;
}

void unloadSead() {
    sead::ThreadMgr::deleteInstance();
    sead::HeapMgr::sInstancePtr = nullptr;
}
