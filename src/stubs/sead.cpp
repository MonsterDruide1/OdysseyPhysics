#include "controller/nin/seadNinJoyNpadDevice.h"
#include "framework/seadCalculateTask.h"
#include "framework/seadTaskMgr.h"
#include "heap/seadExpHeap.h"
#include "prim/seadStringUtil.h"

s32 sead::StringUtil::vsnprintf(char* s, size_t n, const char* format, va_list arg) {
    return std::vsnprintf(s, n, format, arg);
}

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

void sead::Heap::destruct_() {
    CRASH
}

void sead::Heap::dispose_(void const*, void const*) {
    CRASH
}

void sead::ExpHeap::setFindFreeBlockMode(sead::ExpHeap::FindFreeBlockMode) {
    CRASH
}

void sead::ExpHeap::genInformation_(hostio::Context* context){
    CRASH} s32 sead::ExpHeap::destroyAndGetAllocatableSize(int){CRASH}

s32 sead::StringUtil::vsnw16printf(char16* s, size_t n, const char16* format, va_list arg) {
    CRASH
}

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
    : sead::ControlDevice(mgr) {
    CRASH
}

void sead::NinJoyNpadDevice::calc() {
    CRASH
}
