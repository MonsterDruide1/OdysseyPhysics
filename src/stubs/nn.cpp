#include <cstdlib>

#include <basis/seadTypes.h>

#include "nn/account.h"
#include "nn/os.h"

nn::os::Tick nn::os::GetSystemTickFrequency() {
    WARN_UNIMPL;
    return {1};
}

void nn::os::AllocateMemoryBlock(u64* dst_ptr, u64 size) {
    *dst_ptr = (u64)malloc(size);
}

u32 nn::os::GetCurrentCoreNumber() {
    WARN_UNIMPL;
    return 0;
}

nn::Result nn::os::AllocateTlsSlot(TlsSlot* slot_out, void (*)(u64)) {
    WARN_UNIMPL;
    return nn::ResultSuccess();
}

void nn::os::FreeTlsSlot(TlsSlot slot) {
    WARN_UNIMPL;
}

void nn::os::YieldThread() {
    WARN_UNIMPL;
}

void nn::os::InitializeMutex(MutexType*, bool, s32) {
    WARN_UNIMPL;
}

void nn::os::FinalizeMutex(MutexType*) {
    WARN_UNIMPL;
}

void nn::os::LockMutex(MutexType*) {}  // TODO not even warn here due to heavy spam

bool nn::os::TryLockMutex(MutexType*) {
    WARN_UNIMPL;
    return true;
}

void nn::os::UnlockMutex(MutexType*) {}  // TODO not even warn here due to heavy spam

nn::os::Tick nn::os::GetSystemTick() {
    WARN_UNIMPL;
    return {0};
}

void nn::os::FreeMemoryBlock(u64, u64){CRASH} nn::TimeSpan nn::os::ConvertToTimeSpan(Tick ticks){
    CRASH} nn::os::ThreadType* nn::os::GetCurrentThread(){
    CRASH} u64 nn::os::GetThreadId(const nn::os::ThreadType* thread){
    CRASH} s32 nn::os::GetThreadPriority(const nn::os::ThreadType* thread){
    CRASH} u64 nn::os::GetThreadAvailableCoreMask() {
    CRASH
}

void nn::os::GetCurrentStackInfo(uintptr_t* stack_addr, size_t* stack_size) {
    CRASH
}

void nn::os::SetTlsValue(TlsSlot slot, u64 value){CRASH} u64 nn::os::GetTlsValue(TlsSlot slot){
    CRASH} s32 nn::os::ChangeThreadPriority(nn::os::ThreadType* thread, s32 priority){
    CRASH} nn::Result nn::os::CreateThread(nn::os::ThreadType*, void (*)(void*), void* arg,
                                           void* srcStack, u64 stackSize, s32 priority,
                                           s32 coreNum){
    CRASH} nn::Result nn::os::CreateThread(nn::os::ThreadType*, void (*)(void*), void* arg,
                                           void* srcStack, u64 stackSize, s32 priority) {
    CRASH
}

void nn::os::DestroyThread(nn::os::ThreadType*) {
    CRASH
}

void nn::os::StartThread(nn::os::ThreadType*) {
    CRASH
}

void nn::os::SetThreadName(nn::os::ThreadType*, char const* threadName) {
    CRASH
}

void nn::os::WaitThread(nn::os::ThreadType*) {
    CRASH
}

void nn::os::SleepThread(nn::TimeSpan) {
    CRASH
}

void nn::os::ResumeThread(nn::os::ThreadType*) {
    CRASH
}

void nn::os::SuspendThread(nn::os::ThreadType*) {
    CRASH
}

void nn::os::SetThreadCoreMask(nn::os::ThreadType*, int, u64 mask) {
    CRASH
}

void nn::os::InitializeMessageQueue(nn::os::MessageQueueType*, u64* buf, u64 queueCount) {
    WARN_UNIMPL;
}

void nn::os::FinalizeMessageQueue(nn::os::MessageQueueType*) {
    CRASH
}

void nn::os::ReceiveMessageQueue(u64* out, MessageQueueType*) {
    CRASH
}

void nn::os::SendMessageQueue(MessageQueueType*, u64) {
    CRASH
}

bool nn::os::TrySendMessageQueue(MessageQueueType*, u64) {
    CRASH
}

void nn::os::PeekMessageQueue(u64*, const MessageQueueType*) {
    CRASH
}

bool nn::os::TryReceiveMessageQueue(u64*, MessageQueueType*) {
    CRASH
}

bool nn::os::TryPeekMessageQueue(u64*, const MessageQueueType*) {
    CRASH
}

void nn::os::JamMessageQueue(nn::os::MessageQueueType*, u64) {
    CRASH
}

bool nn::os::TryJamMessageQueue(nn::os::MessageQueueType*, u64) {
    CRASH
}

nn::Result nn::account::GetLastOpenedUser(nn::account::Uid*) {CRASH}
