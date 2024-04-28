#include "basis/seadRawPrint.h"
#include "heap/seadArena.h"
#include "heap/seadExpHeap.h"
#include "heap/seadHeap.h"
#include "heap/seadHeapMgr.h"
#include "nn/os.h"
#include "nn/os/os_Mutex.h"
#include "nn/os/os_ThreadTypes.h"
#include "nn/time.h"
#include "prim/seadStringUtil.h"
#include "vapours/results/results_common.hpp"

#define DEREF_NULL *(volatile int*)0;
#define WARN_UNIMPL printf("Function not implemented: %s\n", __func__)
#define CRASH WARN_UNIMPL;DEREF_NULL

u64 nn::os::GetSystemTick() {CRASH}
u64 nn::os::GetSystemTickFrequency() {WARN_UNIMPL; return 1;}
void nn::os::FreeMemoryBlock(u64, u64) {CRASH}
void nn::os::AllocateMemoryBlock(u64 *, u64) {CRASH}
nn::TimeSpan nn::os::ConvertToTimeSpan(Tick ticks) {CRASH}
nn::os::ThreadType* nn::os::GetCurrentThread() {CRASH}
u64 nn::os::GetThreadId(const nn::os::ThreadType *thread) {CRASH}
u32 nn::os::GetCurrentCoreNumber() {CRASH}
s32 nn::os::GetThreadPriority(const nn::os::ThreadType *thread) {CRASH}
u64 nn::os::GetThreadAvailableCoreMask() {CRASH}
void nn::os::GetCurrentStackInfo(uintptr_t *stack_addr, size_t *stack_size) {CRASH}
void nn::os::SetTlsValue(TlsSlot slot, u64 value) {CRASH}
u64 nn::os::GetTlsValue(TlsSlot slot) {CRASH}
nn::Result nn::os::AllocateTlsSlot(TlsSlot *slot_out, void (*)(u64)) {WARN_UNIMPL;return nn::ResultSuccess();}
void nn::os::FreeTlsSlot(TlsSlot slot) {CRASH}
s32 nn::os::ChangeThreadPriority(nn::os::ThreadType *thread, s32 priority) {CRASH}
nn::Result nn::os::CreateThread(nn::os::ThreadType*, void (*)(void*), void* arg, void* srcStack, u64 stackSize, s32 priority, s32 coreNum) {CRASH}
nn::Result nn::os::CreateThread(nn::os::ThreadType*, void (*)(void*), void* arg, void* srcStack, u64 stackSize, s32 priority) {CRASH}
void nn::os::DestroyThread(nn::os::ThreadType *) {CRASH}
void nn::os::StartThread(nn::os::ThreadType *) {CRASH}
void nn::os::SetThreadName(nn::os::ThreadType *, char const *threadName) {CRASH}
void nn::os::WaitThread(nn::os::ThreadType *) {CRASH}
void nn::os::SleepThread(nn::TimeSpan) {CRASH}
void nn::os::ResumeThread(nn::os::ThreadType *) {CRASH}
void nn::os::SuspendThread(nn::os::ThreadType *) {CRASH}
void nn::os::YieldThread() {CRASH}
void nn::os::SetThreadCoreMask(nn::os::ThreadType *, int, u64 mask) {CRASH}
void nn::os::InitializeMutex(MutexType *, bool, s32) {WARN_UNIMPL;}
void nn::os::FinalizeMutex(MutexType *) {WARN_UNIMPL;}
void nn::os::LockMutex(MutexType *) {CRASH}
bool nn::os::TryLockMutex(MutexType *) {CRASH}
void nn::os::UnlockMutex(MutexType *) {CRASH}
void nn::os::InitializeMessageQueue(nn::os::MessageQueueType *, u64 *buf, u64 queueCount) {CRASH}
void nn::os::FinalizeMessageQueue(nn::os::MessageQueueType *) {CRASH}
void nn::os::ReceiveMessageQueue(u64 *out, MessageQueueType *) {CRASH}
void nn::os::SendMessageQueue(MessageQueueType *, u64) {CRASH}
bool nn::os::TrySendMessageQueue(MessageQueueType *, u64) {CRASH}
void nn::os::PeekMessageQueue(u64 *, const MessageQueueType *) {CRASH}
bool nn::os::TryReceiveMessageQueue(u64 *, MessageQueueType *) {CRASH}
bool nn::os::TryPeekMessageQueue(u64 *, const MessageQueueType *) {CRASH}
void nn::os::JamMessageQueue(nn::os::MessageQueueType *, u64) {CRASH}
bool nn::os::TryJamMessageQueue(nn::os::MessageQueueType *, u64) {CRASH}

void sead::Heap::pushBackChild_(sead::Heap* child) {CRASH}
void sead::Heap::makeMetaString_(BufferedSafeString *str) {CRASH}
void sead::Heap::genInformation_(sead::hostio::Context *ctx) {CRASH}
void sead::Heap::dumpYAML(WriteStream &stream, int) const {CRASH}
void sead::Heap::dumpTreeYAML(WriteStream &stream, int) const {CRASH}

sead::Heap* sead::HeapMgr::findContainHeap(const void *ptr) const {CRASH}

void sead::system::Print(const char *format, ...) {CRASH}

sead::ExpHeap* sead::ExpHeap::tryCreate(void* address, size_t size, const sead::SafeString& name, bool) {CRASH}

s32 sead::StringUtil::vsnprintf(char *s, size_t n, const char *format, va_list arg) {CRASH}
s32 sead::StringUtil::vsnw16printf(char16 *s, size_t n, const char16 *format, va_list arg) {CRASH}
