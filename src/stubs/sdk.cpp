#include <basis/seadTypes.h>
#include <cstring>
#include "nn/account.h"
#include "nn/audio.h"
#include "nn/crypto.h"
#include "nn/diag.h"
#include "nn/err.h"
#include "nn/friends.h"
#include "nn/fs.h"
#include "nn/hid.h"
#include "nn/image.h"
#include "nn/mem.h"
#include "nn/nn.h"
#include "nn/nfp/nfp.h"
#include "nn/nifm.h"
#include "nn/oe.h"
#include "nn/pl.h"
#include "nn/prepo.h"
#include "nn/ssl.h"
#include "nn/socket.h"
#include "nn/vi.h"
#include "nn/util/detail/util_ArithmeticImpl.h"
#include "nn/util/util_BinaryFormat.h"
#include "nv.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

namespace movie {
class Buffer {
public:
    Buffer();
    void Offset() const;
    void SetDataAndCapacity(void*, u64);
    void SetRange(int, int);
    void Size() const;
    ~Buffer();
};

enum class DecoderType : int;
enum class DecoderOutputFormat : int;
class Decoder {
public:
    Decoder(DecoderType, DecoderOutputFormat);
};

enum class ContainerType : int;
enum class CacheSize : int;
class Extractor {
public:
    Extractor(ContainerType, CacheSize);
};

class MediaData {
public:
    MediaData();
    ~MediaData();
    void Clear();
    void FindInt32(char const*, int*) const;
    void FindString(char const*, char const**) const;
};

void SetAllocator(void* (*)(u64, u64, void*), void (*)(void*, void*), void* (*)(void*, u64, void*), void*);
void SetCoreMask(u64);
}

movie::Buffer::Buffer() {CRASH}
void movie::Buffer::Offset() const {CRASH}
void movie::Buffer::SetDataAndCapacity(void*, u64) {CRASH}
void movie::Buffer::SetRange(int, int) {CRASH}
void movie::Buffer::Size() const {CRASH}
movie::Buffer::~Buffer() {CRASH}

movie::Decoder::Decoder(movie::DecoderType, movie::DecoderOutputFormat) {CRASH}

movie::Extractor::Extractor(movie::ContainerType, movie::CacheSize) {CRASH}

void movie::MediaData::Clear() {CRASH}
void movie::MediaData::FindInt32(char const*, int*) const {CRASH}
void movie::MediaData::FindString(char const*, char const**) const {CRASH}
movie::MediaData::MediaData() {CRASH}
movie::MediaData::~MediaData() {CRASH}

void movie::SetAllocator(void* (*)(u64, u64, void*), void (*)(void*, void*), void* (*)(void*, u64, void*), void*) {CRASH}
void movie::SetCoreMask(u64) {CRASH}

extern "C" {
void __nnDetailNintendoSdkNsoFile() {CRASH}
void nnResultGetDescription() {CRASH}
void nnResultGetModule() {CRASH}
void nnResultIsFailure() {CRASH}
void nnResultIsSuccess() {CRASH}
void nndetailDiagAbortFormatImpl() {CRASH}
void nnosConvertTickToNanoSeconds() {CRASH}
void nnosCreateThread() {CRASH}
void nnosDestroyThread() {CRASH}
void nnosFinalizeEvent() {CRASH}
void nnosFinalizeMutex() {CRASH}
void nnosGetCurrentThread() {CRASH}
void nnosGetSystemTick() {CRASH}
void nnosGetSystemTickFrequency() {CRASH}
void nnosGetThreadPriority() {CRASH}
void nnosInitializeEvent() {CRASH}
void nnosInitializeMutex() {CRASH}
void nnosLockMutex() {CRASH}
void nnosSetThreadNamePointer() {CRASH}
void nnosSignalEvent() {CRASH}
void nnosSleepThread() {CRASH}
void nnosStartThread() {CRASH}
void nnosUnlockMutex() {CRASH}
void nnosWaitEvent() {CRASH}
void nnosWaitThread() {CRASH}
int nnsocketBind(int, const sockaddr*, u32) {CRASH}
s32 nnsocketCancel(int) {CRASH}
u32 nnsocketClose() {CRASH}
u32 nnsocketConnect() {CRASH}
void nnsocketFcntl(int, int ...) {CRASH}
hostent* nnsocketGetHostByNameCancel(const char*, int) {CRASH}
s32 nnsocketGetLastErrno() {CRASH}
int nnsocketGetPeerName(int, sockaddr*, u32*) {CRASH}
int nnsocketGetSockName(int, sockaddr*, u32*) {CRASH}
int nnsocketGetSockOpt(int, int, int, void*, u32*) {CRASH}
u16 nnsocketInetHtons(u16 val) {CRASH}
u16 nnsocketInetNtohs(u16) {CRASH}
void nnsocketPoll(pollfd*, ulong, int) {CRASH}
int nnsocketRecv(int, void*, ulong, int) {CRASH}
s32 nnsocketRequestCancelHandle() {CRASH}
int nnsocketSend(int socket, const void* data, ulong dataLen, int flags) {CRASH}
void nnsocketSetLastErrno(int) {CRASH}
int nnsocketSetSockOpt(int, int, int, const void*, u32) {CRASH}
int nnsocketSocket(bool) {CRASH}
void nnsslConnectionCreate() {CRASH}
void nnsslConnectionDestroy() {CRASH}
void nnsslConnectionDoHandshakeWithCertBuffer() {CRASH}
void nnsslConnectionGetConnectionId() {CRASH}
void nnsslConnectionGetVerifyCertError() {CRASH}
void nnsslConnectionPeek() {CRASH}
void nnsslConnectionPending() {CRASH}
void nnsslConnectionRead() {CRASH}
void nnsslConnectionSetHostName() {CRASH}
void nnsslConnectionSetIoMode() {CRASH}
void nnsslConnectionSetOption() {CRASH}
void nnsslConnectionSetSessionCacheMode() {CRASH}
void nnsslConnectionSetSocketDescriptor() {CRASH}
void nnsslConnectionSetVerifyOption() {CRASH}
void nnsslConnectionWrite() {CRASH}
void nnsslContextDestroy() {CRASH}
void nnsslContextGetContextId() {CRASH}
void nnsslFinalize() {CRASH}
void nnsslInitialize() {CRASH}
void nvnBootstrapLoader() {CRASH}
}

namespace nn::util {
// FIXME: put proper constants here
float FloatPi = 3.14159265358979323846f;
namespace MatrixRowMajor4x3f {
float ConstantIdentity[4][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {0, 0, 0},
};
}
}
namespace nn::util::detail {
// FIXME: put proper constants here
AngleIndex AngleIndexHalfRound = {0};
float AtanCoefficients[8] = {0};
float CosCoefficients[5] = {1, 2, 3, 4, 5};
float Float1Divided2Pi = 0.15915494309189533576888376337251f;
float Float2Pi = 6.283185307179586476925286766559f;
float FloatDegree180 = 180.0f;
float FloatPi = 3.14159265358979323846f;
float FloatPiDivided2 = 1.5707963267948966192313216916398f;
float FloatQuaternionEpsilon = 1e-6f;
float FloatUlp = 1.1920928955078125e-7f;
float SinCoefficients[5] = {0};
SinCosSample SinCosSampleTable[4] = {0};
}

namespace nn::audio { nn::Result AddDelay(AudioRendererConfig*, DelayType*, void*, size_t, FinalMixType*, nn::TimeSpan, int); }
namespace nn::audio { nn::Result AddDelay(AudioRendererConfig*, DelayType*, void*, size_t, SubMixType*, nn::TimeSpan, int); }
namespace nn::audio { void ExecuteAudioRendererRendering(AudioRendererHandle); }
namespace nn::audio { void GetActiveAudioDeviceName(AudioDeviceName*); }
namespace nn::audio { void GetAudioRendererRenderingTimeLimit(AudioRendererHandle); }
namespace nn::audio { size_t GetRequiredBufferSizeForDelay(nn::TimeSpan, int, int); }
namespace nn::audio { bool IsAuxRemovable(const AuxType*); }
namespace nn::audio { bool IsDelayRemovable(const DelayType*); }
namespace nn::audio { void OpenAudioRenderer(AudioRendererHandle*, nn::os::SystemEvent*, const AudioRendererParameter&, void*, u64); }
namespace nn::audio { void SetAudioRendererRenderingTimeLimit(AudioRendererHandle, int); }
namespace nn::audio { void SetDelayChannelSpread(DelayType*, float); }
namespace nn::audio { void SetDelayDryGain(DelayType*, float); }
namespace nn::audio { void SetDelayEnabled(DelayType*, bool); }
namespace nn::audio { void SetDelayFeedbackGain(DelayType*, float); }
namespace nn::audio { void SetDelayInGain(DelayType*, float); }
namespace nn::audio { void SetDelayLowPassAmount(DelayType*, float); }
namespace nn::audio { void SetDelayTime(DelayType*, nn::TimeSpan); }
namespace nn::audio { void SetDownMixParameter(DeviceSinkType*, const int*); }
namespace nn::audio { void SetDownMixParameter(DeviceSinkType*, const DeviceSinkType::DownMixParameter*); }
namespace nn::audio { void SetDownMixParameterEnabled(DeviceSinkType*, bool); }
namespace nn::diag { void GetBacktrace(u64*, int); }
namespace nn::diag { void IsDebuggerAttached(); }
namespace nn::diag::detail { void AbortImpl(const char*, const char*, const char*, int, const nn::Result*, const char*, ...); }
namespace nn::diag::detail { void NotNullImpl(u64); }
namespace nn::diag::detail { void PutImpl(const nn::diag::LogMetaData&, const char*, u64); }
namespace nn::friends { void GetProfileList(AsyncContext*, Profile*, const nn::account::NetworkServiceAccountId*, int); }
namespace nn::hid { void GetDebugPadState(DebugPadState*); }
namespace nn::hid { void GetNpadControllerColor(NpadControllerColor*, NpadControllerColor*, const unsigned int&); }
namespace nn::hid { void GetNpadJoyAssignment(const unsigned int&); }
namespace nn::hid { void GetSixAxisSensorHandles(SixAxisSensorHandle*, int, const unsigned int&, nn::util::BitFlagSet<32, NpadStyleTag>); }
namespace nn::hid { void GetSixAxisSensorStates(SixAxisSensorState*, int, const SixAxisSensorHandle&); }
namespace nn::hid { void GetVibrationDeviceHandles(VibrationDeviceHandle*, int, const unsigned int&, nn::util::BitFlagSet<32, NpadStyleTag>); }
namespace nn::hid { void InitializeDebugPad(); }
namespace nn::hid { void InitializeTouchScreen(); }
namespace nn::hid { void InitializeVibrationDevice(const VibrationDeviceHandle&); }
namespace nn::hid { void MergeSingleJoyAsDualJoy(const unsigned int&, const unsigned int&); }
namespace nn::hid { void SendVibrationValue(const VibrationDeviceHandle&, const VibrationValue&); }
namespace nn::hid { void SetNpadJoyAssignmentModeDual(const unsigned int&); }
namespace nn::hid { void SetNpadJoyAssignmentModeSingle(const unsigned int&); }
namespace nn::hid { void SetNpadJoyAssignmentModeSingle(const unsigned int&, NpadJoyDeviceType); }
namespace nn::hid { void SetNpadJoyHoldType(NpadJoyHoldType); }
namespace nn::hid { void StartSixAxisSensor(const SixAxisSensorHandle&); }
namespace nn::hid { void SwapNpadAssignment(const unsigned int&, const unsigned int&); }
namespace nn::nifm { void GetCurrentPrimaryIpAddress(in_addr*); }
namespace nn::oe { void SetScreenShotImageOrientation(nn::album::ImageOrientation); }
namespace nn::os { void DestroySystemEvent(SystemEventType*); }
namespace nn::os { u8 TimedWaitSystemEvent(SystemEventType*, nn::TimeSpan); }
namespace nn::os { void WaitSystemEvent(SystemEventType*); }

nn::account::AsyncContext::AsyncContext() {CRASH}
nn::Result nn::account::AsyncContext::Cancel() {CRASH}
nn::Result nn::account::AsyncContext::GetResult() {CRASH}
nn::Result nn::account::AsyncContext::GetSystemEvent(nn::os::SystemEvent*) {CRASH}
nn::Result nn::account::AsyncContext::HasDone(bool*) {CRASH}
nn::account::AsyncContext::~AsyncContext() {CRASH}

void nn::account::CloseUser(nn::account::UserHandle const&) {CRASH}
nn::Result nn::account::EnsureNetworkServiceAccountAvailable(nn::account::UserHandle const&) {CRASH}
nn::Result nn::account::EnsureNetworkServiceAccountIdTokenCacheAsync(nn::account::AsyncContext*, nn::account::UserHandle const&) {CRASH}
nn::Result nn::account::GetNetworkServiceAccountId(nn::account::NetworkServiceAccountId*, nn::account::UserHandle const&) {CRASH}
nn::Result nn::account::GetNickname(nn::account::Nickname*, nn::account::Uid const&) {CRASH}
nn::Result nn::account::GetUserId(nn::account::Uid*, nn::account::UserHandle const&) {CRASH}
void nn::account::Initialize() {CRASH}
nn::Result nn::account::IsNetworkServiceAccountAvailable(bool*, nn::account::UserHandle const&) {CRASH}
nn::Result nn::account::ListAllUsers(int*, nn::account::Uid*, int) {CRASH}
nn::Result nn::account::LoadNetworkServiceAccountIdTokenCache(u64*, char*, u64, nn::account::UserHandle const&) {CRASH}
nn::Result nn::account::OpenPreselectedUser(nn::account::UserHandle*) {CRASH}
nn::Result nn::account::OpenUser(nn::account::UserHandle*, nn::account::Uid const&) {CRASH}

void nn::audio::AcquireAudioDeviceSwitchNotification(nn::os::SystemEvent*) {CRASH}
bool nn::audio::AcquireFinalMix(nn::audio::AudioRendererConfig*, nn::audio::FinalMixType*, int) {CRASH}
bool nn::audio::AcquireMemoryPool(nn::audio::AudioRendererConfig*, nn::audio::MemoryPoolType*, void*, size_t) {CRASH}
bool nn::audio::AcquireSubMix(nn::audio::AudioRendererConfig*, nn::audio::SubMixType*, int, int) {CRASH}
nn::Result nn::audio::AcquireVoiceSlot(nn::audio::AudioRendererConfig*, nn::audio::VoiceType*, int, int, nn::audio::SampleFormat, int, void const*, size_t) {CRASH}
nn::Result nn::audio::AddAux(nn::audio::AudioRendererConfig*, nn::audio::AuxType*, nn::audio::FinalMixType*, void*, void*, size_t) {CRASH}
nn::Result nn::audio::AddAux(nn::audio::AudioRendererConfig*, nn::audio::AuxType*, nn::audio::SubMixType*, void*, void*, size_t) {CRASH}
nn::Result nn::audio::AddCircularBufferSink(nn::audio::AudioRendererConfig*, nn::audio::CircularBufferSinkType*, nn::audio::FinalMixType*, signed char const*, int, void*, size_t, nn::audio::SampleFormat) {CRASH}
nn::Result nn::audio::AddDelay(nn::audio::AudioRendererConfig*, nn::audio::DelayType*, void*, size_t, nn::audio::FinalMixType*, nn::TimeSpan, int) {CRASH}
nn::Result nn::audio::AddDelay(nn::audio::AudioRendererConfig*, nn::audio::DelayType*, void*, size_t, nn::audio::SubMixType*, nn::TimeSpan, int) {CRASH}
nn::Result nn::audio::AddDeviceSink(nn::audio::AudioRendererConfig*, nn::audio::DeviceSinkType*, nn::audio::FinalMixType*, signed char const*, int, char const*) {CRASH}
bool nn::audio::AppendWaveBuffer(nn::audio::VoiceType*, nn::audio::WaveBuffer const*) {CRASH}
void nn::audio::CloseAudioRenderer(nn::audio::AudioRendererHandle) {CRASH}
void nn::audio::ExecuteAudioRendererRendering(nn::audio::AudioRendererHandle) {CRASH}
void nn::audio::GetActiveAudioDeviceName(nn::audio::AudioDeviceName*) {CRASH}
u32 nn::audio::GetActiveChannelCount() {CRASH}
size_t nn::audio::GetAudioRendererConfigWorkBufferSize(nn::audio::AudioRendererParameter const&) {CRASH}
void nn::audio::GetAudioRendererRenderingTimeLimit(nn::audio::AudioRendererHandle) {CRASH}
size_t nn::audio::GetAudioRendererWorkBufferSize(nn::audio::AudioRendererParameter const&) {CRASH}
s32 nn::audio::GetAuxSampleCount(nn::audio::AuxType const*) {CRASH}
s32 nn::audio::GetAuxSampleRate(nn::audio::AuxType const*) {CRASH}
nn::audio::MemoryPoolState nn::audio::GetMemoryPoolState(nn::audio::MemoryPoolType const*) {CRASH}
nn::audio::WaveBuffer* nn::audio::GetReleasedWaveBuffer(nn::audio::VoiceType*) {CRASH}
size_t nn::audio::GetRequiredBufferSizeForAuxSendReturnBuffer(nn::audio::AudioRendererParameter const*, int, int) {CRASH}
size_t nn::audio::GetRequiredBufferSizeForCircularBufferSink(nn::audio::AudioRendererParameter const*, int, int, nn::audio::SampleFormat) {CRASH}
size_t nn::audio::GetRequiredBufferSizeForDelay(nn::TimeSpan, int, int) {CRASH}
size_t nn::audio::GetRequiredBufferSizeForPerformanceFrames(nn::audio::AudioRendererParameter const&) {CRASH}
u32 nn::audio::GetSinkNodeId(nn::audio::CircularBufferSinkType const*) {CRASH}
u32 nn::audio::GetSinkNodeId(nn::audio::DeviceSinkType const*) {CRASH}
u32 nn::audio::GetSubMixNodeId(nn::audio::SubMixType const*) {CRASH}
u32 nn::audio::GetVoiceNodeId(nn::audio::VoiceType const*) {CRASH}
nn::audio::VoiceType::PlayState nn::audio::GetVoicePlayState(nn::audio::VoiceType const*) {CRASH}
u64 nn::audio::GetVoicePlayedSampleCount(nn::audio::VoiceType const*) {CRASH}
nn::Result nn::audio::InitializeAudioRendererConfig(nn::audio::AudioRendererConfig*, nn::audio::AudioRendererParameter const&, void*, u64) {CRASH}
void nn::audio::InitializeAudioRendererParameter(nn::audio::AudioRendererParameter*) {CRASH}
bool nn::audio::IsAuxRemovable(nn::audio::AuxType const*) {CRASH}
bool nn::audio::IsDelayRemovable(nn::audio::DelayType const*) {CRASH}
bool nn::audio::IsMemoryPoolAttached(nn::audio::MemoryPoolType const*) {CRASH}
bool nn::audio::IsValidAudioRendererParameter(nn::audio::AudioRendererParameter const&) {CRASH}
bool nn::audio::IsVoiceDroppedFlagOn(nn::audio::VoiceType const*) {CRASH}
bool nn::audio::IsVoiceValid(nn::audio::VoiceType const*) {CRASH}
s32 nn::audio::ListAudioDeviceName(nn::audio::AudioDeviceName*, int) {CRASH}
void nn::audio::OpenAudioRenderer(nn::audio::AudioRendererHandle*, nn::os::SystemEvent*, nn::audio::AudioRendererParameter const&, void*, u64) {CRASH}
nn::audio::PerformanceEntry nn::audio::PerformanceInfo::GetEntries(int*) {CRASH}
s32 nn::audio::PerformanceInfo::GetTotalProcessingTime() {CRASH}
bool nn::audio::PerformanceInfo::MoveToNextFrame() {CRASH}
nn::audio::PerformanceInfo::PerformanceInfo() {CRASH}
bool nn::audio::PerformanceInfo::SetBuffer(void const*, u64) {CRASH}
nn::audio::PerformanceInfo::~PerformanceInfo() {CRASH}
s32 nn::audio::ReadAuxSendBuffer(nn::audio::AuxType*, int*, int) {CRASH}
size_t nn::audio::ReadCircularBufferSink(nn::audio::CircularBufferSinkType*, void*, u64) {CRASH}
void nn::audio::ReleaseMemoryPool(nn::audio::AudioRendererConfig*, nn::audio::MemoryPoolType*) {CRASH}
void nn::audio::ReleaseVoiceSlot(nn::audio::AudioRendererConfig*, nn::audio::VoiceType*) {CRASH}
void nn::audio::RemoveAux(nn::audio::AudioRendererConfig*, nn::audio::AuxType*, nn::audio::FinalMixType*) {CRASH}
void nn::audio::RemoveAux(nn::audio::AudioRendererConfig*, nn::audio::AuxType*, nn::audio::SubMixType*) {CRASH}
void nn::audio::RemoveCircularBufferSink(nn::audio::AudioRendererConfig*, nn::audio::CircularBufferSinkType*, nn::audio::FinalMixType*) {CRASH}
void* nn::audio::RemoveDelay(nn::audio::AudioRendererConfig*, nn::audio::DelayType*, nn::audio::FinalMixType*) {CRASH}
void* nn::audio::RemoveDelay(nn::audio::AudioRendererConfig*, nn::audio::DelayType*, nn::audio::SubMixType*) {CRASH}
bool nn::audio::RequestAttachMemoryPool(nn::audio::MemoryPoolType*) {CRASH}
bool nn::audio::RequestDetachMemoryPool(nn::audio::MemoryPoolType*) {CRASH}
nn::Result nn::audio::RequestUpdateAudioRenderer(nn::audio::AudioRendererHandle, nn::audio::AudioRendererConfig const*) {CRASH}
nn::Result nn::audio::SetAudioDeviceOutputVolume(nn::audio::AudioDeviceName const*, float) {CRASH}
void nn::audio::SetAudioRendererRenderingTimeLimit(nn::audio::AudioRendererHandle, int) {CRASH}
void nn::audio::SetAuxEnabled(nn::audio::AuxType*, bool) {CRASH}
void nn::audio::SetAuxInputOutput(nn::audio::AuxType*, signed char const*, signed char const*, int) {CRASH}
void nn::audio::SetDelayChannelSpread(nn::audio::DelayType*, float) {CRASH}
void nn::audio::SetDelayDryGain(nn::audio::DelayType*, float) {CRASH}
void nn::audio::SetDelayEnabled(nn::audio::DelayType*, bool) {CRASH}
void nn::audio::SetDelayFeedbackGain(nn::audio::DelayType*, float) {CRASH}
void nn::audio::SetDelayInGain(nn::audio::DelayType*, float) {CRASH}
void nn::audio::SetDelayInputOutput(nn::audio::DelayType*, signed char const*, signed char const*, int) {CRASH}
void nn::audio::SetDelayLowPassAmount(nn::audio::DelayType*, float) {CRASH}
void nn::audio::SetDelayTime(nn::audio::DelayType*, nn::TimeSpan) {CRASH}
void nn::audio::SetDownMixParameter(nn::audio::DeviceSinkType*, nn::audio::DeviceSinkType::DownMixParameter const*) {CRASH}
void nn::audio::SetDownMixParameterEnabled(nn::audio::DeviceSinkType*, bool) {CRASH}
void* nn::audio::SetPerformanceFrameBuffer(nn::audio::AudioRendererConfig*, void*, u64) {CRASH}
void nn::audio::SetSubMixDestination(nn::audio::AudioRendererConfig*, nn::audio::SubMixType*, nn::audio::FinalMixType*) {CRASH}
void nn::audio::SetSubMixDestination(nn::audio::AudioRendererConfig*, nn::audio::SubMixType*, nn::audio::SubMixType*) {CRASH}
void nn::audio::SetSubMixMixVolume(nn::audio::SubMixType*, nn::audio::FinalMixType*, float, int, int) {CRASH}
void nn::audio::SetSubMixMixVolume(nn::audio::SubMixType*, nn::audio::SubMixType*, float, int, int) {CRASH}
void nn::audio::SetVoiceBiquadFilterParameter(nn::audio::VoiceType*, int, nn::audio::BiquadFilterParameter const&) {CRASH}
void nn::audio::SetVoiceDestination(nn::audio::AudioRendererConfig*, nn::audio::VoiceType*, nn::audio::FinalMixType*) {CRASH}
void nn::audio::SetVoiceDestination(nn::audio::AudioRendererConfig*, nn::audio::VoiceType*, nn::audio::SubMixType*) {CRASH}
void nn::audio::SetVoiceMixVolume(nn::audio::VoiceType*, nn::audio::FinalMixType*, float, int, int) {CRASH}
void nn::audio::SetVoiceMixVolume(nn::audio::VoiceType*, nn::audio::SubMixType*, float, int, int) {CRASH}
void nn::audio::SetVoicePitch(nn::audio::VoiceType*, float) {CRASH}
void nn::audio::SetVoicePlayState(nn::audio::VoiceType*, nn::audio::VoiceType::PlayState) {CRASH}
void nn::audio::SetVoicePriority(nn::audio::VoiceType*, int) {CRASH}
void nn::audio::SetVoiceVolume(nn::audio::VoiceType*, float) {CRASH}
nn::Result nn::audio::StartAudioRenderer(nn::audio::AudioRendererHandle) {CRASH}
nn::Result nn::audio::StopAudioRenderer(nn::audio::AudioRendererHandle) {CRASH}
s32 nn::audio::WriteAuxReturnBuffer(nn::audio::AuxType*, int const*, int) {CRASH}
void nn::crypto::GenerateSha1Hash(void*, u64, void const*, u64) {CRASH}
void nn::crypto::detail::Md5Impl::GetHash(void*, u64) {CRASH}
void nn::crypto::detail::Md5Impl::Initialize() {CRASH}
void nn::crypto::detail::Md5Impl::Update(void const*, u64) {CRASH}
void nn::crypto::detail::Sha1Impl::GetHash(void*, u64) {CRASH}
void nn::crypto::detail::Sha1Impl::Initialize() {CRASH}
void nn::crypto::detail::Sha1Impl::Update(void const*, u64) {CRASH}
void nn::detail::UnexpectedDefaultImpl(char const*, char const*, int) {CRASH}

namespace nn::diag {
class AbortObserverHolder;
class AbortInfo;
void InitializeAbortObserverHolder(nn::diag::AbortObserverHolder*, void (*arg)(nn::diag::AbortInfo const&));
void RegisterAbortObserver(nn::diag::AbortObserverHolder*);
}
s32 nn::diag::GetAllModuleInfo(nn::diag::ModuleInfo**, void*, u64) {CRASH}
void nn::diag::GetBacktrace(u64*, int) {CRASH}
u64 nn::diag::GetRequiredBufferSizeForGetAllModuleInfo() {CRASH}
size_t nn::diag::GetSymbolName(char*, u64, u64) {CRASH}
u64 nn::diag::GetSymbolSize(u64) {CRASH}
void nn::diag::InitializeAbortObserverHolder(nn::diag::AbortObserverHolder*, void (*)(nn::diag::AbortInfo const&)) {CRASH}
void nn::diag::IsDebuggerAttached() {CRASH}
void nn::diag::RegisterAbortObserver(nn::diag::AbortObserverHolder*) {CRASH}
void nn::diag::detail::AbortImpl(char const*, char const*, char const*, int) {CRASH}
void nn::diag::detail::AbortImpl(char const*, char const*, char const*, int, nn::Result const*, char const*, ...) {CRASH}
void nn::diag::detail::LogImpl(nn::diag::LogMetaData const&, char const*, ...) {CRASH}
void nn::diag::detail::NotNullImpl(u64) {CRASH}
void nn::diag::detail::OnAssertionFailure(nn::diag::AssertionType, char const*, char const*, char const*, int) {CRASH}
void nn::diag::detail::PutImpl(nn::diag::LogMetaData const&, char const*, u64) {CRASH}

namespace nn::err {
void ShowError(nn::Result);
}
void nn::err::ShowError(nn::Result) {CRASH}

namespace nn::fontll {
class OtfKerningTable;
class Metrics;
class ScalableFontEngine {
public:
    enum class Flags : int;

    ScalableFontEngine();
    ~ScalableFontEngine();
    void AcquireGlyphmap(unsigned int, unsigned short);
    void AcquireOtfKerning(nn::fontll::OtfKerningTable const*, unsigned int, unsigned int, unsigned int);
    void AcquireOtfKerningFirst(nn::fontll::OtfKerningTable const*, unsigned int, unsigned int);
    void AcquireOtfKerningLast(nn::fontll::OtfKerningTable const*, unsigned int, unsigned int);
    void CheckGlyphExist(unsigned int);
    void Finalize();
    void FinalizeOtfKerningTable(nn::fontll::OtfKerningTable*, void (*)(void*, void*), void*);
    void GetAdvance(short*, short*, int*, int*, unsigned int, unsigned short);
    void GetError();
    void GetFontMetrics(nn::fontll::Metrics*);
    void GetKerning(int*, int*, unsigned int, unsigned int);
    void GetPointerToWorkBuffer();
    void Initialize(void*, unsigned int);
    void InitializeOtfKerningTable(void* (*)(u64, u64, void*), void*, bool);
    void LoadFont(char*, void const*, unsigned int, unsigned int);
    void ReleasesGlyph(void*);
    void SetAutoHint(bool);
    void SetBoldWeight(int);
    void SetFlags(nn::fontll::ScalableFontEngine::Flags);
    void SetFont(char*);
    void SetOutlineWidth(unsigned short);
    void SetScale(int, int, int, int);
};
class ScalableFontEngineHelper {
public:
    void Decode(void const*, unsigned int);
};
}
void nn::fontll::ScalableFontEngine::AcquireGlyphmap(unsigned int, unsigned short) {CRASH}
void nn::fontll::ScalableFontEngine::AcquireOtfKerning(nn::fontll::OtfKerningTable const*, unsigned int, unsigned int, unsigned int) {CRASH}
void nn::fontll::ScalableFontEngine::AcquireOtfKerningFirst(nn::fontll::OtfKerningTable const*, unsigned int, unsigned int) {CRASH}
void nn::fontll::ScalableFontEngine::AcquireOtfKerningLast(nn::fontll::OtfKerningTable const*, unsigned int, unsigned int) {CRASH}
void nn::fontll::ScalableFontEngine::CheckGlyphExist(unsigned int) {CRASH}
void nn::fontll::ScalableFontEngine::Finalize() {CRASH}
void nn::fontll::ScalableFontEngine::FinalizeOtfKerningTable(nn::fontll::OtfKerningTable*, void (*)(void*, void*), void*) {CRASH}
void nn::fontll::ScalableFontEngine::GetAdvance(short*, short*, int*, int*, unsigned int, unsigned short) {CRASH}
void nn::fontll::ScalableFontEngine::GetError() {CRASH}
void nn::fontll::ScalableFontEngine::GetFontMetrics(nn::fontll::Metrics*) {CRASH}
void nn::fontll::ScalableFontEngine::GetKerning(int*, int*, unsigned int, unsigned int) {CRASH}
void nn::fontll::ScalableFontEngine::GetPointerToWorkBuffer() {CRASH}
void nn::fontll::ScalableFontEngine::Initialize(void*, unsigned int) {CRASH}
void nn::fontll::ScalableFontEngine::InitializeOtfKerningTable(void* (*)(u64, u64, void*), void*, bool) {CRASH}
void nn::fontll::ScalableFontEngine::LoadFont(char*, void const*, unsigned int, unsigned int) {CRASH}
void nn::fontll::ScalableFontEngine::ReleasesGlyph(void*) {CRASH}
nn::fontll::ScalableFontEngine::ScalableFontEngine() {CRASH}
void nn::fontll::ScalableFontEngine::SetAutoHint(bool) {CRASH}
void nn::fontll::ScalableFontEngine::SetBoldWeight(int) {CRASH}
void nn::fontll::ScalableFontEngine::SetFlags(nn::fontll::ScalableFontEngine::Flags) {CRASH}
void nn::fontll::ScalableFontEngine::SetFont(char*) {CRASH}
void nn::fontll::ScalableFontEngine::SetOutlineWidth(unsigned short) {CRASH}
void nn::fontll::ScalableFontEngine::SetScale(int, int, int, int) {CRASH}
void nn::fontll::ScalableFontEngineHelper::Decode(void const*, unsigned int) {CRASH}

nn::friends::AsyncContext::AsyncContext() {CRASH}
nn::Result nn::friends::AsyncContext::GetResult() const {CRASH}
nn::Result nn::friends::AsyncContext::GetSystemEvent(nn::os::SystemEvent*) {CRASH}
nn::friends::AsyncContext::~AsyncContext() {CRASH}
void nn::friends::GetProfileList(nn::friends::AsyncContext*, nn::friends::Profile*, nn::account::NetworkServiceAccountId const*, int) {CRASH}
void nn::friends::Initialize() {CRASH}
nn::account::Nickname& nn::friends::Profile::GetNickname() const {CRASH}
nn::Result nn::friends::Profile::GetProfileImageUrl(nn::friends::Url*, nn::friends::ImageSize) const {CRASH}
nn::friends::Profile::Profile() {CRASH}
nn::Result nn::fs::ReadFile(u64*, nn::fs::FileHandle, long, void*, u64) {CRASH}

namespace nn::hid {
void DisconnectNpad(unsigned int const&);

class VibrationModulation;
enum class VibrationMixMode : int;
class VibrationNode {
public:
    void SetModulationTo(nn::hid::VibrationNode const*, nn::hid::VibrationModulation const&);
    void Update();
};
class VibrationNodeConnection {
public:
    VibrationNodeConnection();
    VibrationNodeConnection(nn::hid::VibrationNode*, nn::hid::VibrationNode*);
    void Connect(nn::hid::VibrationNode*, nn::hid::VibrationNode*);
    void Disconnect();
    void GetDestination() const;
    void GetModulation() const;
};
class VibrationPlayer {
public:
    VibrationPlayer();
    void GetFileInfo() const;
    void IsPlaying() const;
    void Load(void const*, u64);
    void Play();
    void SetCurrentPosition(int);
    void SetLoop(bool);
    void Stop();
};
class VibrationMixer {
public:
    VibrationMixer();
    void SetMixMode(nn::hid::VibrationMixMode);
};
class VibrationWriter {
public:
    VibrationWriter();
    void Write(nn::hid::VibrationValue const&);
};
class VibrationTarget {
public:
    VibrationTarget();
    void IsVibrationDeviceHandleSet() const;
    void SetVibrationDeviceHandle(nn::hid::VibrationDeviceHandle const&);
    void UnsetVibrationDeviceHandle();
};

template <u64 N>
void GetTouchScreenState(TouchScreenState<N>* x) {CRASH}
}

void nn::hid::DisconnectNpad(unsigned int const&) {CRASH}
void nn::hid::GetDebugPadState(nn::hid::DebugPadState*) {CRASH}
void nn::hid::GetNpadControllerColor(nn::hid::NpadControllerColor*, nn::hid::NpadControllerColor*, unsigned int const&) {CRASH}
void nn::hid::GetNpadJoyAssignment(unsigned int const&) {CRASH}
void nn::hid::GetNpadStates(nn::hid::NpadFullKeyState*, int, unsigned int const&) {CRASH}
void nn::hid::GetNpadStates(nn::hid::NpadHandheldState*, int, unsigned int const&) {CRASH}
void nn::hid::GetNpadStates(nn::hid::NpadJoyDualState*, int, unsigned int const&) {CRASH}
void nn::hid::GetNpadStates(nn::hid::NpadJoyLeftState*, int, unsigned int const&) {CRASH}
void nn::hid::GetNpadStates(nn::hid::NpadJoyRightState*, int, unsigned int const&) {CRASH}
nn::hid::NpadStyleSet nn::hid::GetNpadStyleSet(unsigned int const&) {CRASH}
void nn::hid::GetSixAxisSensorHandles(nn::hid::SixAxisSensorHandle*, int, unsigned int const&, nn::util::BitFlagSet<32, nn::hid::NpadStyleTag>) {CRASH}
void nn::hid::GetSixAxisSensorStates(nn::hid::SixAxisSensorState*, int, nn::hid::SixAxisSensorHandle const&) {CRASH}
void nn::hid::GetVibrationDeviceHandles(nn::hid::VibrationDeviceHandle*, int, unsigned int const&, nn::util::BitFlagSet<32, nn::hid::NpadStyleTag>) {CRASH}
void nn::hid::InitializeDebugPad() {CRASH}
void nn::hid::InitializeNpad() {CRASH}
void nn::hid::InitializeTouchScreen() {CRASH}
void nn::hid::InitializeVibrationDevice(nn::hid::VibrationDeviceHandle const&) {CRASH}
void nn::hid::MergeSingleJoyAsDualJoy(unsigned int const&, unsigned int const&) {CRASH}
void nn::hid::SendVibrationValue(nn::hid::VibrationDeviceHandle const&, nn::hid::VibrationValue const&) {CRASH}
void nn::hid::SetNpadJoyAssignmentModeDual(unsigned int const&) {CRASH}
void nn::hid::SetNpadJoyAssignmentModeSingle(unsigned int const&) {CRASH}
void nn::hid::SetNpadJoyAssignmentModeSingle(unsigned int const&, nn::hid::NpadJoyDeviceType) {CRASH}
void nn::hid::SetNpadJoyHoldType(nn::hid::NpadJoyHoldType) {CRASH}
void nn::hid::SetSupportedNpadIdType(unsigned int const*, u64) {CRASH}
void nn::hid::SetSupportedNpadStyleSet(nn::util::BitFlagSet<32, nn::hid::NpadStyleTag>) {CRASH}
s32 nn::hid::ShowControllerSupport(nn::hid::ControllerSupportResultInfo*, nn::hid::ControllerSupportArg const&) {CRASH}
void nn::hid::StartSixAxisSensor(nn::hid::SixAxisSensorHandle const&) {CRASH}
void nn::hid::SwapNpadAssignment(unsigned int const&, unsigned int const&) {CRASH}
void nn::hid::VibrationMixer::SetMixMode(nn::hid::VibrationMixMode) {CRASH}
nn::hid::VibrationMixer::VibrationMixer() {CRASH}
void nn::hid::VibrationNode::SetModulationTo(nn::hid::VibrationNode const*, nn::hid::VibrationModulation const&) {CRASH}
void nn::hid::VibrationNode::Update() {CRASH}
void nn::hid::VibrationNodeConnection::Connect(nn::hid::VibrationNode*, nn::hid::VibrationNode*) {CRASH}
void nn::hid::VibrationNodeConnection::Disconnect() {CRASH}
void nn::hid::VibrationNodeConnection::GetDestination() const {CRASH}
void nn::hid::VibrationNodeConnection::GetModulation() const {CRASH}
nn::hid::VibrationNodeConnection::VibrationNodeConnection() {CRASH}
nn::hid::VibrationNodeConnection::VibrationNodeConnection(nn::hid::VibrationNode*, nn::hid::VibrationNode*) {CRASH}
void nn::hid::VibrationPlayer::GetFileInfo() const {CRASH}
void nn::hid::VibrationPlayer::IsPlaying() const {CRASH}
void nn::hid::VibrationPlayer::Load(void const*, u64) {CRASH}
void nn::hid::VibrationPlayer::Play() {CRASH}
void nn::hid::VibrationPlayer::SetCurrentPosition(int) {CRASH}
void nn::hid::VibrationPlayer::SetLoop(bool) {CRASH}
void nn::hid::VibrationPlayer::Stop() {CRASH}
nn::hid::VibrationPlayer::VibrationPlayer() {CRASH}
void nn::hid::VibrationTarget::IsVibrationDeviceHandleSet() const {CRASH}
void nn::hid::VibrationTarget::SetVibrationDeviceHandle(nn::hid::VibrationDeviceHandle const&) {CRASH}
void nn::hid::VibrationTarget::UnsetVibrationDeviceHandle() {CRASH}
nn::hid::VibrationTarget::VibrationTarget() {CRASH}
nn::hid::VibrationWriter::VibrationWriter() {CRASH}
void nn::hid::VibrationWriter::Write(nn::hid::VibrationValue const&) {CRASH}

nn::image::JpegStatus nn::image::JpegDecoder::Analyze() {CRASH}
nn::image::JpegStatus nn::image::JpegDecoder::Decode(void*, u64, int, void*, u64) {CRASH}
nn::image::Dimension nn::image::JpegDecoder::GetAnalyzedDimension() const {CRASH}
s64 nn::image::JpegDecoder::GetAnalyzedWorkBufferSize() const {CRASH}
nn::image::JpegDecoder::JpegDecoder() {CRASH}
void nn::image::JpegDecoder::SetImageData(void const*, u64) {CRASH}
nn::image::JpegDecoder::~JpegDecoder() {CRASH}

namespace nn::lmem {
namespace detail {
class HeapHead;
}
void AllocateFromFrameHeap(detail::HeapHead*, u64, int);
void CreateFrameHeap(void*, u64, int);
void DestroyFrameHeap(detail::HeapHead*);
}
void nn::lmem::AllocateFromFrameHeap(nn::lmem::detail::HeapHead*, u64, int) {CRASH}
void nn::lmem::CreateFrameHeap(void*, u64, int) {CRASH}
void nn::lmem::DestroyFrameHeap(nn::lmem::detail::HeapHead*) {CRASH}
void* nn::mem::StandardAllocator::Allocate(u64 size) { return malloc(size); }
void* nn::mem::StandardAllocator::Allocate(u64 size, u64 align) { return aligned_alloc(align, size); }
void nn::mem::StandardAllocator::Dump() const {CRASH}
void nn::mem::StandardAllocator::Finalize() {CRASH}
void nn::mem::StandardAllocator::Free(void*) {}
size_t nn::mem::StandardAllocator::GetSizeOf(void const*) const {CRASH}
size_t nn::mem::StandardAllocator::GetTotalFreeSize() const {CRASH}
void nn::mem::StandardAllocator::Initialize(void*, u64) {}
void* nn::mem::StandardAllocator::Reallocate(void*, u64) {CRASH}
nn::mem::StandardAllocator::StandardAllocator() {}
nn::mem::StandardAllocator::StandardAllocator(void*, u64) {CRASH}
nn::Result nn::nfp::AttachActivateEvent(nn::os::SystemEventType*, nn::nfp::DeviceHandle const&) {CRASH}
nn::Result nn::nfp::AttachDeactivateEvent(nn::os::SystemEventType*, nn::nfp::DeviceHandle const&) {CRASH}
nn::Result nn::nfp::Finalize() {CRASH}
nn::nfp::DeviceState nn::nfp::GetDeviceState(nn::nfp::DeviceHandle const&) {CRASH}
nn::Result nn::nfp::GetModelInfo(nn::nfp::ModelInfo*, nn::nfp::DeviceHandle const&) {CRASH}
nn::Result nn::nfp::GetNpadId(unsigned int*, nn::nfp::DeviceHandle const&) {CRASH}
nn::Result nn::nfp::GetTagInfo(nn::nfp::TagInfo*, nn::nfp::DeviceHandle const&) {CRASH}
nn::Result nn::nfp::Initialize() {CRASH}
nn::Result nn::nfp::ListDevices(nn::nfp::DeviceHandle*, int*, int) {CRASH}
nn::Result nn::nfp::Mount(nn::nfp::DeviceHandle const&, nn::nfp::ModelType, nn::nfp::MountTarget) {CRASH}
nn::Result nn::nfp::StartDetection(nn::nfp::DeviceHandle const&) {CRASH}
nn::Result nn::nfp::StopDetection(nn::nfp::DeviceHandle const&) {CRASH}
nn::Result nn::nfp::Unmount(nn::nfp::DeviceHandle const&) {CRASH}

namespace nn::nifm {
class ProxySetting;

void GetCurrentProxySetting(nn::nifm::ProxySetting*);
}
void nn::nifm::GetCurrentPrimaryIpAddress(in_addr*) {CRASH}
void nn::nifm::GetCurrentProxySetting(nn::nifm::ProxySetting*) {CRASH}
nn::Result nn::nifm::HandleNetworkRequestResult() {CRASH}
nn::Result nn::nifm::Initialize() {CRASH}
bool nn::nifm::IsNetworkAvailable() {CRASH}
bool nn::nifm::IsNetworkRequestOnHold() {CRASH}
void nn::nifm::SetLocalNetworkMode(bool) {WARN_UNIMPL;}
void nn::nifm::SubmitNetworkRequest() {WARN_UNIMPL;}
void nn::nifm::SubmitNetworkRequestAndWait() {WARN_UNIMPL;}

namespace nn::nsd {
class Fqdn;
void ResolveEx(nn::nsd::Fqdn*, nn::nsd::Fqdn const&);
}
void nn::nsd::ResolveEx(nn::nsd::Fqdn*, nn::nsd::Fqdn const&) {}

namespace nn::oe {
void GetPerformanceConfiguration(nn::oe::PerformanceMode);
}
void nn::oe::EnableGamePlayRecording(void*, u64) {}
void nn::oe::FinishStartupLogo() {CRASH}
nn::oe::FocusState nn::oe::GetCurrentFocusState() {CRASH}
nn::settings::LanguageCode nn::oe::GetDesiredLanguage() {CRASH}
void nn::oe::GetExpectedVolumeBalance(float*, float*) {CRASH}
nn::oe::OperationMode nn::oe::GetOperationMode() {CRASH}
void nn::oe::GetPerformanceConfiguration(nn::oe::PerformanceMode) {CRASH}
nn::oe::PerformanceMode nn::oe::GetPerformanceMode() {CRASH}
void nn::oe::Initialize() {CRASH}
bool nn::oe::IsUserInactivityDetectionTimeExtended() {CRASH}
void nn::oe::SetExpectedVolumeBalance(float, float) {CRASH}
void nn::oe::SetFocusHandlingMode(nn::oe::FocusHandlingMode) {CRASH}
void nn::oe::SetOperationModeChangedNotificationEnabled(bool) {CRASH}
void nn::oe::SetPerformanceConfiguration(nn::oe::PerformanceMode, int) {CRASH}
void nn::oe::SetPerformanceModeChangedNotificationEnabled(bool) {CRASH}
void nn::oe::SetResumeNotificationEnabled(bool) {CRASH}
void nn::oe::SetScreenShotImageOrientation(nn::album::ImageOrientation) {CRASH}
void nn::oe::SetUserInactivityDetectionTimeExtended(bool) {CRASH}
bool nn::oe::TryPopNotificationMessage(unsigned int*) {CRASH}

namespace nn::os {
void ConvertToTick(nn::TimeSpan);
void GetCurrentFiber();
bool TryWaitSystemEvent(nn::os::SystemEventType*);
void WaitConditionVariable(nn::os::ConditionVariableType*, nn::os::MutexType*);
}
void nn::os::BroadcastConditionVariable(nn::os::ConditionVariableType*) {CRASH}
void nn::os::ClearEvent(nn::os::EventType*) {CRASH}
void nn::os::ClearLightEvent(nn::os::LightEventType*) {CRASH}
void nn::os::ConvertToTick(nn::TimeSpan) {CRASH}
void nn::os::DestroySystemEvent(nn::os::SystemEventType*) {CRASH}
void nn::os::FinalizeConditionVariable(nn::os::ConditionVariableType*) {CRASH}
void nn::os::FinalizeEvent(nn::os::EventType*) {CRASH}
void nn::os::FinalizeLightEvent(nn::os::LightEventType*) {CRASH}
void nn::os::GenerateRandomBytes(void*, u64) {CRASH}
void nn::os::GetCurrentFiber() {CRASH}
s32 nn::os::GetHostArgc() {CRASH}
char** nn::os::GetHostArgv() {CRASH}
char* nn::os::GetThreadNamePointer(nn::os::ThreadType const*) {CRASH}
void nn::os::InitializeConditionVariable(nn::os::ConditionVariableType*) {CRASH}
void nn::os::InitializeEvent(nn::os::EventType*, bool, nn::os::EventClearMode) {CRASH}
void nn::os::InitializeLightEvent(nn::os::LightEventType*, bool, nn::os::EventClearMode) {CRASH}
void nn::os::SetMemoryHeapSize(u64) {}
void nn::os::SetThreadNamePointer(nn::os::ThreadType*, char const*) {CRASH}
void nn::os::SetUserExceptionHandler(void (*)(nn::os::UserExceptionInfo*), void*, u64, nn::os::UserExceptionInfo*) {CRASH}
void nn::os::SignalConditionVariable(nn::os::ConditionVariableType*) {CRASH}
void nn::os::SignalEvent(nn::os::EventType*) {CRASH}
void nn::os::SignalLightEvent(nn::os::LightEventType*) {CRASH}
u8 nn::os::TimedWaitConditionVariable(nn::os::ConditionVariableType*, nn::os::MutexType*, nn::TimeSpan) {CRASH}
bool nn::os::TimedWaitLightEvent(nn::os::LightEventType*, nn::TimeSpan) {CRASH}
u8 nn::os::TimedWaitSystemEvent(nn::os::SystemEventType*, nn::TimeSpan) {CRASH}
bool nn::os::TryWaitEvent(nn::os::EventType*) {CRASH}
bool nn::os::TryWaitSystemEvent(nn::os::SystemEventType*) {CRASH}
void nn::os::WaitConditionVariable(nn::os::ConditionVariableType*, nn::os::MutexType*) {CRASH}
void nn::os::WaitEvent(nn::os::EventType*) {CRASH}
void nn::os::WaitLightEvent(nn::os::LightEventType*) {CRASH}
void nn::os::WaitSystemEvent(nn::os::SystemEventType*) {CRASH}
void* nn::pl::GetSharedFontAddress(nn::pl::SharedFontType) {CRASH}
nn::pl::LoadState nn::pl::GetSharedFontLoadState(nn::pl::SharedFontType) {CRASH}
u32 nn::pl::GetSharedFontSize(nn::pl::SharedFontType) {CRASH}
nn::Result nn::prepo::PlayReport::Add(char const*, double) {CRASH}
nn::Result nn::prepo::PlayReport::Add(char const*, long) {CRASH}
nn::prepo::PlayReport::PlayReport(char const*) {CRASH}
nn::Result nn::prepo::PlayReport::Save(nn::account::Uid const&) {CRASH}
void nn::prepo::PlayReport::SetBuffer(void*, u64) {CRASH}
nn::settings::LanguageCode nn::settings::LanguageCode::Make(nn::settings::Language) {CRASH}
bool nn::settings::operator==(nn::settings::LanguageCode const&, nn::settings::LanguageCode const&) {CRASH}
s32 nn::socket::Accept(int, sockaddr*, unsigned int*) {CRASH}
s32 nn::socket::Bind(int, sockaddr const*, unsigned int) {CRASH}
nn::Result nn::socket::Close(int) {CRASH}
nn::Result nn::socket::Connect(int, sockaddr const*, unsigned int) {CRASH}
s32 nn::socket::Fcntl(int, int, ...) {CRASH}
s32 nn::socket::Finalize() {CRASH}
s32 nn::socket::FreeAddrInfo(addrinfo*) {CRASH}
s32 nn::socket::GetAddrInfo(char const*, char const*, addrinfo const*, addrinfo**) {CRASH}
s32 nn::socket::GetLastErrno() {CRASH}
s32 nn::socket::GetPeerName(int, sockaddr*, unsigned int*) {CRASH}
s32 nn::socket::GetSockName(int, sockaddr*, unsigned int*) {CRASH}
u32 nn::socket::InetHtonl(unsigned int) {CRASH}
u16 nn::socket::InetHtons(unsigned short) {CRASH}
char* nn::socket::InetNtoa(in_addr) {CRASH}
u32 nn::socket::InetNtohl(unsigned int) {CRASH}
u16 nn::socket::InetNtohs(unsigned short) {CRASH}
const char* nn::socket::InetNtop(int, void const*, char*, unsigned int) {CRASH}
s32 nn::socket::InetPton(int, char const*, void*) {CRASH}
nn::Result nn::socket::Initialize(void*, u64, u64, int) {CRASH}
s32 nn::socket::Listen(int, int) {CRASH}
s32 nn::socket::Poll(pollfd*, u64, int) {CRASH}
s32 nn::socket::Recv(int, void*, u64, int) {CRASH}
s32 nn::socket::RecvFrom(int, void*, u64, int, sockaddr*, unsigned int*) {CRASH}
s32 nn::socket::Send(int, void const*, u64, int) {CRASH}
s32 nn::socket::SendTo(int, void const*, u64, int, sockaddr const*, unsigned int) {CRASH}
s32 nn::socket::SetSockOpt(int, int, int, void const*, unsigned int) {CRASH}
s32 nn::socket::Shutdown(int, int) {CRASH}
s32 nn::socket::Socket(int, int, int) {CRASH}
nn::Result nn::ssl::Context::Create(nn::ssl::Context::SslVersion) {CRASH}
nn::Result nn::ssl::Context::ImportServerPki(u64*, char const*, unsigned int, nn::ssl::CertificateFormat) {CRASH}
nn::Result nn::ssl::Finalize() {CRASH}
nn::Result nn::ssl::Initialize() {CRASH}
namespace nn::time {
void Finalize() {CRASH}
}
nn::time::CalendarTime nn::time::ToCalendarTimeInUtc(nn::time::PosixTime const&) {CRASH}
nn::Result nn::time::ToPosixTime(int*, nn::time::PosixTime*, int, nn::time::CalendarTime const&) {CRASH}
nn::time::PosixTime nn::time::ToPosixTimeFromUtc(nn::time::CalendarTime const&) {CRASH}
size_t nn::util::BinaryBlockHeader::GetBlockSize() const {CRASH}
size_t nn::util::BinaryFileHeader::GetAlignment() const {CRASH}
nn::util::BinaryBlockHeader* nn::util::BinaryFileHeader::GetFirstBlock() {CRASH}
const nn::util::BinaryBlockHeader* nn::util::BinaryFileHeader::GetFirstBlock() const {CRASH}
nn::util::RelocationTable* nn::util::BinaryFileHeader::GetRelocationTable() {CRASH}
bool nn::util::BinaryFileHeader::IsAlignmentValid() const {CRASH}
bool nn::util::BinaryFileHeader::IsEndianReverse() const {CRASH}
bool nn::util::BinaryFileHeader::IsRelocated() const {CRASH}
bool nn::util::BinaryFileHeader::IsSignatureValid(long) const {CRASH}
bool nn::util::BinaryFileHeader::IsValid(long, int, int, int) const {CRASH}
void nn::util::BinaryFileHeader::SetRelocated(bool) {CRASH}
nn::util::CharacterEncodingResult nn::util::ConvertCharacterUtf8ToUtf32(unsigned int*, char const*) {CRASH}
nn::util::CharacterEncodingResult nn::util::ConvertStringUtf16NativeToUtf8(char*, int, unsigned short const*, int) {CRASH}
nn::util::CharacterEncodingResult nn::util::ConvertStringUtf8ToUtf16Native(unsigned short*, int, char const*, int) {CRASH}
nn::util::CharacterEncodingResult nn::util::PickOutCharacterFromUtf8String(char*, char const**) {CRASH}
void nn::util::RelocationTable::Relocate() {CRASH}
void nn::util::RelocationTable::Unrelocate() {CRASH}
nn::Result nn::vi::CreateLayer(nn::vi::Layer**, nn::vi::Display*) {CRASH}
nn::Result nn::vi::GetDisplayVsyncEvent(nn::os::SystemEventType*, nn::vi::Display*) {CRASH}
nn::Result nn::vi::GetNativeWindow(void**, nn::vi::Layer*) {CRASH}
void nn::vi::Initialize() {CRASH}
nn::Result nn::vi::OpenDefaultDisplay(nn::vi::Display**) {CRASH}
nn::Result nn::vi::SetLayerScalingMode(nn::vi::Layer*, nn::vi::ScalingMode) {CRASH}

namespace nn::web {
enum class OfflineBackgroundKind : int;
enum class OfflineBootDisplayKind : int;
class OfflineHtmlPageReturnValue {
public:
    OfflineHtmlPageReturnValue();
    void GetOfflineExitReason() const;
    void GetLastUrl() const;
};
class ShowOfflineHtmlPageArg {
public:
    void SetBackgroundKind(nn::web::OfflineBackgroundKind const&);
    void SetBootDisplayKind(nn::web::OfflineBootDisplayKind);
    void SetFooterEnabled(bool);
    void SetPointerEnabled(bool);
};
class ShowOfflineHtmlPageArgWithPlayReport {
public:
    ShowOfflineHtmlPageArgWithPlayReport(nn::ApplicationId const&, char const*);
    void SetPlayReportEnabled(bool);
};
void ShowOfflineHtmlPage(nn::web::OfflineHtmlPageReturnValue*, nn::web::ShowOfflineHtmlPageArg const&);
}
void nn::web::OfflineHtmlPageReturnValue::GetLastUrl() const {CRASH}
void nn::web::OfflineHtmlPageReturnValue::GetOfflineExitReason() const {CRASH}
nn::web::OfflineHtmlPageReturnValue::OfflineHtmlPageReturnValue() {CRASH}
void nn::web::ShowOfflineHtmlPage(nn::web::OfflineHtmlPageReturnValue*, nn::web::ShowOfflineHtmlPageArg const&) {CRASH}
void nn::web::ShowOfflineHtmlPageArg::SetBackgroundKind(nn::web::OfflineBackgroundKind const&) {CRASH}
void nn::web::ShowOfflineHtmlPageArg::SetBootDisplayKind(nn::web::OfflineBootDisplayKind) {CRASH}
void nn::web::ShowOfflineHtmlPageArg::SetFooterEnabled(bool) {CRASH}
void nn::web::ShowOfflineHtmlPageArg::SetPointerEnabled(bool) {CRASH}
void nn::web::ShowOfflineHtmlPageArgWithPlayReport::SetPlayReportEnabled(bool) {CRASH}
nn::web::ShowOfflineHtmlPageArgWithPlayReport::ShowOfflineHtmlPageArgWithPlayReport(nn::ApplicationId const&, char const*) {CRASH}
void nv::InitializeGraphics(void*, u64) {CRASH}
void nv::SetGraphicsAllocator(void* (*)(u64, u64, void*), void (*)(void*, void*), void* (*)(void*, u64, void*), void*) {CRASH}
void nv::SetGraphicsDevtoolsAllocator(void* (*)(u64, u64, void*), void (*)(void*, void*), void* (*)(void*, u64, void*), void*) {CRASH}

#pragma GCC diagnostic pop

template <>
void nn::hid::GetTouchScreenState<1ul>(nn::hid::TouchScreenState<1ul>*) {CRASH}


void nn::oe::GetDisplayVersion(nn::oe::DisplayVersion* ver) {
    memcpy(ver->name, "v1.0-PC", 7);
}
void nn::util::ReferSymbol(void const*) {}
