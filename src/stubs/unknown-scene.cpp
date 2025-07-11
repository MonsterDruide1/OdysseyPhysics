#include "Library/Audio/AudioDirector.h"
#include "Library/Audio/System/AudioKeeperFunction.h"
#include "Library/Camera/CameraDirector.h"
#include "Library/Camera/CameraUtil.h"
#include "Library/Clipping/ClippingActorHolder.h"
#include "Library/Clipping/ClippingActorInfo.h"
#include "Library/Clipping/ClippingGroupHolder.h"
#include "Library/Clipping/ClippingJudge.h"
#include "Library/Controller/PadRumbleDirector.h"
#include "Library/Draw/GraphicsSystemInfo.h"
#include "Library/Draw/ViewRenderer.h"
#include "Library/Effect/EffectKeeper.h"
#include "Library/Layout/LayoutInitInfo.h"
#include "Library/Layout/LayoutUtil.h"
#include "Library/Matrix/MatrixUtil.h"
#include "Library/Message/MessageHolder.h"
#include "Library/Play/Camera/SimpleCameraPoserFactory.h"
#include "Library/PostProcessing/PostProcessingFilter.h"
#include "Library/Resource/ResourceFunction.h"
#include "Library/Scene/DemoDirector.h"
#include "Library/Se/Function/SeDbFunction.h"
#include "Library/Se/SeFunction.h"
#include "Project/Clipping/ViewInfoCtrl.h"
#include "Project/File/FileLoader.h"
#include "Project/Gravity/GravityHolder.h"
#include "Project/LiveActor/ActorExecuteFunction.h"
#include "Project/SaveData/SaveDataDirector.h"
#include "System/Application.h"

al::ClippingJudge::ClippingJudge(al::ClippingFarAreaObserver const*, al::SceneCameraInfo const*) {WARN_UNIMPL;}
al::ClippingActorHolder::ClippingActorHolder(int) {WARN_UNIMPL;}
al::ClippingGroupHolder::ClippingGroupHolder() {WARN_UNIMPL;}

al::AudioDirector::AudioDirector() {CRASH}
void al::AudioDirector::init(al::AudioDirectorInitInfo const&) {CRASH}
void al::AudioDirector::init3D(al::AudioDirectorInitInfo const&) {CRASH}
void al::AudioDirector::setDependentModule(al::AudioDirector*) {CRASH}
void al::AudioDirector::pauseSystem(bool, const char*, bool, f32, bool, bool, bool) {CRASH}
al::AreaObjDirector* al::AudioDirector::getAreaObjDirector() const {CRASH}

void al::CameraDirector::endInvalidStopJudgeByDemo() {CRASH}
void al::CameraDirector::endSnapShotMode() {CRASH}
al::CameraPoseUpdater* al::CameraDirector::getPoseUpdater(int) {CRASH}
void al::CameraDirector::init(al::CameraPoserSceneInfo*, al::CameraPoserFactory const*) {CRASH}
al::PauseCameraCtrl* al::CameraDirector::initAndCreatePauseCameraCtrl(float) {CRASH}
void al::CameraDirector::initAreaCameraSwitcherMultiForPrototype(al::AreaObjDirector*) {CRASH}
void al::CameraDirector::initAreaCameraSwitcherSingle() {CRASH}
void al::CameraDirector::initResourceHolder(al::CameraResourceHolder const*) {CRASH}
void al::CameraDirector::initSceneFovyDegree(float) {CRASH}
void al::CameraDirector::initSnapShotCameraAudioKeeper(al::IUseAudioKeeper*) {CRASH}
void al::CameraDirector::restartByDeathPlayer() {CRASH}
void al::CameraDirector::startInvalidStopJudgeByDemo() {CRASH}
void al::CameraDirector::startSnapShotMode(bool) {CRASH}
void al::CameraDirector::stopByDeathPlayer() {CRASH}

void al::ClippingActorHolder::endInit(al::ClippingGroupHolder*) {CRASH}
al::ClippingActorInfo* al::ClippingActorHolder::find(al::LiveActor const*) const {CRASH}
al::ClippingActorInfo* al::ClippingActorHolder::initGroupClipping(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::ClippingActorHolder::offGroupClipping(al::LiveActor*) {CRASH}
void al::ClippingActorHolder::onGroupClipping(al::LiveActor*) {CRASH}
al::ClippingActorInfo* al::ClippingActorHolder::registerActor(al::LiveActor*) {CRASH}
void al::ClippingActorHolder::update(al::ClippingJudge const*) {CRASH}
void al::ClippingActorHolder::updateFarClipLevel() {CRASH}
al::ClippingActorHolder::~ClippingActorHolder() {CRASH}
void al::ClippingActorInfo::initViewGroup(al::ViewIdHolder const*) {CRASH}
bool al::ClippingActorInfo::isGroupClippingInit() const {CRASH}
void al::ClippingActorInfo::registerViewGroupFarClipFlag(bool const*) {CRASH}
void al::ClippingGroupHolder::leave(al::ClippingActorInfo*) {CRASH}
void al::ClippingGroupHolder::reentry(al::ClippingActorInfo*) {CRASH}
void al::ClippingGroupHolder::update(al::ClippingJudge const*) {CRASH}
void al::ClippingJudge::update() {CRASH}

const char* al::DemoDirector::getActiveDemoName() const {CRASH}
al::LiveActor** al::DemoDirector::getDemoActorList() const {CRASH}
s32 al::DemoDirector::getDemoActorNum() const {CRASH}
bool al::DemoDirector::isActiveDemo() const {CRASH}

void al::GraphicsSystemInfo::initStageResource(al::Resource const*, char const*, char const*) {CRASH}

void al::GravityHolder::createGravity(al::PlacementInfo const&) {CRASH}

void al::LayoutInitInfo::init(al::ExecuteDirector*, al::EffectSystemInfo const*, al::SceneObjHolder*, al::AudioDirector const*, al::CameraDirector*, al::LayoutSystem const*, al::MessageSystem const*, al::GamePadSystem const*, al::PadRumbleDirector*) {CRASH}

void al::PadRumbleDirector::endPause() {CRASH}
void al::PadRumbleDirector::pause() {CRASH}
void al::PadRumbleDirector::setWaveVibrationHolder(al::WaveVibrationHolder*) {CRASH}
void al::PadRumbleDirector::stopAllRumble() {CRASH}

void al::PostProcessingFilter::decrementPreset() {CRASH}
void al::PostProcessingFilter::incrementPreset() {CRASH}

al::SimpleCameraPoserFactory::SimpleCameraPoserFactory(char const*) : al::CameraPoserFactory("") {CRASH}
al::CameraPoserFactory::CameraPoserFactory(char const*) : al::Factory<CameraPoserCreatorFunction>("") {CRASH}
al::CameraPoserEntrance* al::CameraPoserFactory::createEntranceCameraPoser() const {CRASH}

void al::ViewRenderer::endForwardPlayerScreenFader(int) {CRASH}
void al::ViewRenderer::startForwardPlayerScreenFader(int, int, float) {CRASH}

void al::executeDraw(al::LayoutKit const*, char const*) {CRASH}
void al::executeDraw(al::LiveActorKit const*, char const*) {CRASH}
void al::executeDrawList(al::LiveActorKit const*, char const*, char const*) {CRASH}
void al::executeUpdate(al::LayoutKit*) {CRASH}
void al::executeUpdate(al::LiveActorKit*, char const*) {CRASH}
void al::executeUpdateList(al::LiveActorKit*, char const*, char const*) {CRASH}
void al::executeUpdateTable(al::LiveActorKit*, char const*) {CRASH}
const char* al::getLanguage() {CRASH}
al::CameraTicket* al::initFixCamera(al::IUseCamera const*, char const*, sead::Vector3<float> const&, sead::Vector3<float> const&) {CRASH}
void al::makeMtxSideNoSupport(sead::Matrix34<float>*, sead::Vector3<float> const&) {CRASH}

void alAudioSystemFunction::setPadRumbleDirectorForSe(al::AudioDirector*, al::PadRumbleDirector*) {CRASH}
void alEffectSystemFunction::drawEffectDeferred(al::EffectSystem const*, sead::Matrix44<float> const&, sead::Matrix34<float> const&, float, float, float) {CRASH}
const char* alSeDbFunction::tryFindSceneSeUserName(al::AudioSystemInfo const*, char const*, int) {CRASH}
void alSeFunction::stopAllSe(al::AudioDirector const*, unsigned int) {CRASH}

al::SaveDataDirector::SaveDataDirector(unsigned int, int) {CRASH}
