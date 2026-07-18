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
#include "Library/Event/EventFlowUtil.h"
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
#include "Scene/StageSceneStateOption.h"

al::ClippingActorHolder::ClippingActorHolder(int) {WARN_UNIMPL;}
al::AreaObjDirector* al::AudioDirector::getAreaObjDirector() const {CRASH}

/*
void al::CameraDirector::registerCameraRailHolder(al::CameraRailHolder*) {}
void al::CameraDirector::endInvalidStopJudgeByDemo() {CRASH}
void al::CameraDirector::endSnapShotMode() {CRASH}
al::CameraPoseUpdater* al::CameraDirector::getPoseUpdater(int) const {CRASH}
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
*/

void al::ClippingActorHolder::endInit(al::ClippingGroupHolder*) {CRASH}
al::ClippingActorInfo* al::ClippingActorHolder::find(al::LiveActor const*) const {CRASH}
al::ClippingActorInfo* al::ClippingActorHolder::initGroupClipping(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::ClippingActorHolder::offGroupClipping(al::LiveActor*) {CRASH}
void al::ClippingActorHolder::onGroupClipping(al::LiveActor*) {CRASH}
al::ClippingActorInfo* al::ClippingActorHolder::registerActor(al::LiveActor*) {CRASH}
void al::ClippingActorHolder::update(al::ClippingJudge const*) {CRASH}
void al::ClippingActorHolder::updateFarClipLevel() {CRASH}
al::ClippingActorHolder::~ClippingActorHolder() {CRASH}

const char* al::DemoDirector::getActiveDemoName() const {CRASH}
al::LiveActor** al::DemoDirector::getDemoActorList() const {CRASH}
s32 al::DemoDirector::getDemoActorNum() const {CRASH}
bool al::DemoDirector::isActiveDemo() const {CRASH}

void al::PostProcessingFilter::decrementPreset() {CRASH}
void al::PostProcessingFilter::incrementPreset() {CRASH}

al::SimpleCameraPoserFactory::SimpleCameraPoserFactory(char const*) : al::CameraPoserFactory("") {CRASH}

void al::ViewRenderer::endForwardPlayerScreenFader(int) {CRASH}
void al::ViewRenderer::startForwardPlayerScreenFader(int, int, float) {CRASH}

void al::executeUpdate(al::LayoutKit*) {CRASH}
al::CameraTicket* al::initFixCamera(al::IUseCamera const*, char const*, sead::Vector3<float> const&, sead::Vector3<float> const&) {CRASH}
void al::makeMtxSideNoSupport(sead::Matrix34<float>*, sead::Vector3<float> const&) {CRASH}
bool al::isEventName(al::EventFlowEventData const*, char const*, ...) {return false;}

void alEffectSystemFunction::drawEffectDeferred(al::EffectSystem const*, sead::Matrix44<float> const&, sead::Matrix34<float> const&, float, float, float) {CRASH}

StageSceneStateOption::StageSceneStateOption(char const*,al::Scene *x,al::LayoutInitInfo const&,FooterParts *,GameDataHolder *,bool) : al::HostStateBase<al::Scene>("", x) {}
