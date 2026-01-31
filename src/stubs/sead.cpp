#include "controller/nin/seadNinJoyNpadDevice.h"
#include "framework/seadCalculateTask.h"
#include "framework/seadTaskMgr.h"
#include "gfx/seadProjection.h"
#include "heap/seadExpHeap.h"
#include "heap/seadFrameHeap.h"
#include "prim/seadStringUtil.h"
#include "resource/seadParallelSZSDecompressor.h"
#include "stream/seadStream.h"

s32 sead::StringUtil::vsnprintf(char* s, size_t n, const char* format, va_list arg) {
    return std::vsnprintf(s, n, format, arg);
}

s32 sead::StringUtil::snprintf(char* s, size_t n, const char* format, ...) {
    va_list arg;
    va_start(arg, format);
    s32 ret = sead::StringUtil::vsnprintf(s, n, format, arg);
    va_end(arg);
    return ret;
}

s32 sead::StringUtil::vsw16printf(char16_t*, unsigned long, char16_t const*, va_list) {
    CRASH
}

char16* sead::StringUtil::wcs16cpy(char16_t*, unsigned long, char16_t const*) {
    CRASH
}

s32 sead::StringUtil::vsnw16printf(char16* s, size_t n, const char16* format, va_list arg) {
    CRASH
}

bool sead::MemUtil::isStack(void const*) {
    return true;
}
sead::FrameHeap* sead::FrameHeap::create(unsigned long, sead::SafeStringBase<char> const&, sead::Heap*, int, sead::Heap::HeapDirection, bool) {CRASH}

sead::FrameHeap* sead::FrameHeap::tryCreate(unsigned long, sead::SafeStringBase<char> const&, sead::Heap*, int, sead::Heap::HeapDirection, bool) {CRASH}

void sead::Heap::makeMetaString_(BufferedSafeString* str) {
    CRASH
}

void sead::Heap::genInformation_(sead::hostio::Context* ctx) {
    CRASH
}

void sead::Heap::dumpYAML(WriteStream& stream, int) const {
    CRASH
}

void sead::Heap::dumpTreeYAML(WriteStream& stream, int) const {
    CRASH
}

void sead::ExpHeap::setFindFreeBlockMode(sead::ExpHeap::FindFreeBlockMode) {
    CRASH
}

void sead::ExpHeap::genInformation_(hostio::Context* context){
    CRASH
}

s32 sead::ExpHeap::destroyAndGetAllocatableSize(int){CRASH}

void sead::CalculateTask::pauseCalc(bool) {
    CRASH
}

void sead::CalculateTask::pauseDraw(bool) {
    CRASH
}

void sead::CalculateTask::pauseCalcRec(bool) {
    CRASH
}

void sead::CalculateTask::pauseDrawRec(bool) {
    CRASH
}

void sead::CalculateTask::pauseCalcChild(bool) {
    CRASH
}

void sead::CalculateTask::pauseDrawChild(bool) {
    CRASH
}

void sead::CalculateTask::attachCalcImpl() {
    CRASH
}

void sead::CalculateTask::attachDrawImpl() {
    CRASH
}

void sead::CalculateTask::detachCalcImpl() {
    CRASH
}

void sead::CalculateTask::detachDrawImpl() {
    CRASH
}

const sead::RuntimeTypeInfo::Interface*
sead::CalculateTask::getCorrespondingMethodTreeMgrTypeInfo() const {
    CRASH} sead::MethodTreeNode* sead::CalculateTask::getMethodTreeNode(int){CRASH}

sead::TaskBase::TaskBase(sead::TaskConstructArg const&, char const*){
    CRASH} sead::TaskBase::TaskBase(sead::TaskConstructArg const&){
    CRASH} sead::TaskBase::~TaskBase() {
    CRASH
}

void sead::TaskBase::prepare() {
    CRASH
}

void sead::TaskBase::enterCommon() {
    CRASH
}

void sead::TaskBase::enter() {
    CRASH
}

void sead::TaskBase::exit() {
    CRASH
}

void sead::TaskBase::onEvent(sead::TaskEvent const&) {
    CRASH
}

void sead::TaskBase::onDestroy() {
    CRASH
}

void sead::TaskBase::pauseCalcChild(bool) {
    CRASH
}

void sead::TaskBase::pauseDrawChild(bool) {
    CRASH
}

void sead::TaskMgr::destroyTaskSync(sead::TaskBase*){CRASH}

sead::NinJoyNpadDevice::NinJoyNpadDevice(sead::ControllerMgr* mgr, sead::Heap*)
    : sead::ControlDevice(mgr), mVibrationThread(nullptr) {
    CRASH
}

void sead::NinJoyNpadDevice::calc() {
    CRASH
}

sead::NinJoyNpadDevice::VibrationThread::VibrationThread(sead::Heap*) : sead::Thread(nullptr, nullptr, 0) {
    CRASH
}

sead::NinJoyNpadDevice::VibrationThread::~VibrationThread() {
    CRASH
}

void sead::NinJoyNpadDevice::VibrationThread::calc_(long) {
    CRASH
}

sead::NinJoyNpadDevice::~NinJoyNpadDevice() {
    CRASH
}

void sead::WriteStream::writeF32(float) {CRASH}
void sead::WriteStream::writeMemBlock(void const*, unsigned int) {CRASH}
void sead::WriteStream::writeS32(int) {CRASH}
void sead::WriteStream::writeS64(long) {CRASH}
void sead::WriteStream::writeU16(unsigned short) {CRASH}
void sead::WriteStream::writeU32(unsigned int) {CRASH}
void sead::WriteStream::writeU64(unsigned long) {CRASH}
void sead::WriteStream::writeU8(unsigned char) {CRASH}

sead::ParallelSZSDecompressor::ParallelSZSDecompressor(unsigned int, int, sead::Heap*, unsigned char*, sead::CoreIdMask const&) : sead::Decompressor("") {CRASH}
sead::ParallelSZSDecompressor::~ParallelSZSDecompressor() {CRASH}
u8* sead::ParallelSZSDecompressor::tryDecompFromDevice(const ResourceMgr::LoadArg& loadArg, Resource* resource, u32* outSize,
                            u32* outAllocSize, bool* outAllocated) {CRASH}
