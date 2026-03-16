#include "controller/nin/seadNinJoyNpadDevice.h"
#include "framework/seadCalculateTask.h"
#include "framework/seadTaskMgr.h"
#include "gfx/seadProjection.h"
#include "heap/seadExpHeap.h"
#include "heap/seadFrameHeap.h"
#include "prim/seadStringUtil.h"
#include "resource/seadParallelSZSDecompressor.h"
#include "stream/seadStream.h"
#include "stream/seadStreamFormat.h"

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

sead::ParallelSZSDecompressor::ParallelSZSDecompressor(unsigned int, int, sead::Heap*, unsigned char*, sead::CoreIdMask const&) : sead::Decompressor("") {CRASH}
sead::ParallelSZSDecompressor::~ParallelSZSDecompressor() {CRASH}
u8* sead::ParallelSZSDecompressor::tryDecompFromDevice(const ResourceMgr::LoadArg& loadArg, Resource* resource, u32* outSize,
                            u32* outAllocSize, bool* outAllocated) {CRASH}

                            
u8 sead::TextStreamFormat::readU8(StreamSrc* src, Endian::Types endian) {return 0;}
u16 sead::TextStreamFormat::readU16(StreamSrc* src, Endian::Types endian) {return 0;}
u32 sead::TextStreamFormat::readU32(StreamSrc* src, Endian::Types endian) {return 0;}
u64 sead::TextStreamFormat::readU64(StreamSrc* src, Endian::Types endian) {return 0;}
s8 sead::TextStreamFormat::readS8(StreamSrc* src, Endian::Types endian) {return 0;}
s16 sead::TextStreamFormat::readS16(StreamSrc* src, Endian::Types endian) {return 0;}
s32 sead::TextStreamFormat::readS32(StreamSrc* src, Endian::Types endian) {return 0;}
s64 sead::TextStreamFormat::readS64(StreamSrc* src, Endian::Types endian) {return 0;}
f32 sead::TextStreamFormat::readF32(StreamSrc* src, Endian::Types endian) {return 0;}
void sead::TextStreamFormat::readBit(StreamSrc* src, void* data, u32 bits) {}
void sead::TextStreamFormat::readString(StreamSrc* src, BufferedSafeString* str, u32 size) {}
u32 sead::TextStreamFormat::readMemBlock(StreamSrc* src, void* buffer, u32 size) {return 0;}
void sead::TextStreamFormat::writeU8(StreamSrc* src, Endian::Types endian, u8 value) {}
void sead::TextStreamFormat::writeU16(StreamSrc* src, Endian::Types endian, u16 value) {}
void sead::TextStreamFormat::writeU32(StreamSrc* src, Endian::Types endian, u32 value) {}
void sead::TextStreamFormat::writeU64(StreamSrc* src, Endian::Types endian, u64 value) {}
void sead::TextStreamFormat::writeS8(StreamSrc* src, Endian::Types endian, s8 value) {}
void sead::TextStreamFormat::writeS16(StreamSrc* src, Endian::Types endian, s16 value) {}
void sead::TextStreamFormat::writeS32(StreamSrc* src, Endian::Types endian, s32 value) {}
void sead::TextStreamFormat::writeS64(StreamSrc* src, Endian::Types endian, s64 value) {}
void sead::TextStreamFormat::writeF32(StreamSrc* src, Endian::Types endian, f32 value) {}
void sead::TextStreamFormat::writeBit(StreamSrc* src, const void* data, u32 bits) {}
void sead::TextStreamFormat::writeString(StreamSrc* src, const SafeString& str, u32 size) {}
void sead::TextStreamFormat::writeMemBlock(StreamSrc* src, const void* buffer, u32 size) {}
void sead::TextStreamFormat::writeDecorationText(StreamSrc* src, const SafeString& text) {}
void sead::TextStreamFormat::writeNullChar(StreamSrc* src) {}
void sead::TextStreamFormat::skip(StreamSrc* src, u32 offset) {}
void sead::TextStreamFormat::flush(StreamSrc* src) {}
void sead::TextStreamFormat::rewind(StreamSrc* src) {}
