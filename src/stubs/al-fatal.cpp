#include "Library/Action/ActorActionKeeper.h"
#include "Library/Base/StringUtil.h"
#include "Library/Camera/CameraUtil.h"
#include "Library/Collision/Collider.h"
#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/CollisionUtil.h"
#include "Library/Controller/InputFunction.h"
#include "Library/Effect/EffectKeeper.h"
#include "Library/HitSensor/HitSensorKeeper.h"
#include "Library/HitSensor/SensorFunction.h"
#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorCollisionFunction.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/ActorResourceFunction.h"
#include "Library/LiveActor/ActorSensorMsgFunction.h"
#include "Library/LiveActor/LiveActorUtil.h"
#include "Library/Math/MathUtil.h"
#include "Library/Model/ModelKeeper.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Scene/ISceneObj.h"
#include "Library/Scene/SceneUtil.h"
#include "Library/Screen/ScreenPointKeeper.h"
#include "Library/Se/SeKeeper.h"
#include "Library/Shadow/DepthShadowMapCtrl.h"
#include "Library/Shadow/ShadowMaskCtrl.h"
#include "Player/CollisionShapeInfo.h"
#include "Project/Action/ActionAnimCtrl.h"
#include "Project/Action/ActionBgmCtrl.h"
#include "Project/Action/ActionEffectCtrl.h"
#include "Project/Action/ActionFlagCtrl.h"
#include "Project/Action/ActionPadAndCameraCtrl.h"
#include "Project/Action/ActionScreenEffectCtrl.h"
#include "Project/Action/ActionSeCtrl.h"
#include "Project/Light/ActorPrepassLightKeeper.h"
#include "Util/In2DAreaMoveControl.h"
#include "math/seadQuat.h"

void al::CollisionParts::calcForceRotatePower(sead::Quatf*) const {
    CRASH
}

const al::LiveActor* al::CollisionParts::getConnectedHost() const {
    CRASH
}

void al::DepthShadowMapCtrl::show() {
    CRASH
}

void al::DepthShadowMapCtrl::hide() {
    CRASH
}

void al::DepthShadowMapCtrl::update() {
    CRASH
}

void al::DepthShadowMapCtrl::initAfterPlacement(al::GraphicsSystemInfo*) {
    CRASH
}

void al::ShadowMaskCtrl::show() {
    CRASH
}

void al::ShadowMaskCtrl::hide() {
    CRASH
}

void al::ShadowMaskCtrl::initAfterPlacement() {
    CRASH
}

void al::ActorPrePassLightKeeper::initAfterPlacement() {
    CRASH
}

void al::tryInitFixedModelGpuBuffer(const LiveActor*) {
    CRASH
}

void al::ModelKeeper::update() {
    CRASH
}

void al::ModelKeeper::updateLast() {
    CRASH
}

void al::EffectKeeper::update() {
    CRASH
}

void al::HitSensorKeeper::update() {
    CRASH
}

void al::ActorActionKeeper::updatePost() {
    CRASH
}

void al::ScreenPointKeeper::update() {
    CRASH
}

void alScreenPointFunction::updateScreenPointAll(al::LiveActor*) {
    CRASH
}

void alSensorFunction::updateHitSensorsAll(al::LiveActor*) {
    CRASH
}

void alSensorFunction::clearHitSensors(al::LiveActor*) {
    CRASH
}

void al::ActionFlagCtrl::initPost() {
    CRASH
}

void al::ActionFlagCtrl::startCtrlSensor() {
    CRASH
}

void al::ActionFlagCtrl::startCtrlFlag() {
    CRASH
}

void al::ActionFlagCtrl::updateCtrlSensor(float, float, float, bool) {
    CRASH
}

void al::ActionSeCtrl::startAction(char const*) {
    CRASH
}

void al::ActionBgmCtrl::startAction(char const*) {
    CRASH
}

void al::ActionPadAndCameraCtrl::startAction(char const*) {
    CRASH
}

void al::ActionScreenEffectCtrl::startAction(char const*) {
    CRASH
}

bool al::ActionAnimCtrl::start(char const*) {
    CRASH
}

void al::ActionEffectCtrl::startAction(char const*){CRASH}

al::ActionEffectCtrl* al::ActionEffectCtrl::tryCreate(al::IUseEffectKeeper*){
    CRASH} al::ActionBgmCtrl* al::ActionBgmCtrl::tryCreate(al::AudioKeeper*){
    CRASH} al::ActionScreenEffectCtrl* al::ActionScreenEffectCtrl::tryCreate(al::LiveActor const*,
                                                                             char const*){
    CRASH} al::ActionAnimCtrl* al::ActionAnimCtrl::tryCreate(al::LiveActor*,
                                                             al::ActorResource const*, char const*,
                                                             char const*){
    CRASH} al::ActionPadAndCameraCtrl* al::ActionPadAndCameraCtrl::
    tryCreate(al::LiveActor const*, al::ActorResource const*, sead::Vector3<float> const*,
              char const*){CRASH} al::ActionSeCtrl* al::ActionSeCtrl::tryCreate(al::AudioKeeper*) {
    CRASH
}

void al::SeKeeper::resetPosition() {
    CRASH
}

void al::HitSensorKeeper::attackSensor() {
    CRASH
}

void al::updateMaterialCodePuddle(al::LiveActor*) {
    CRASH
}

void al::setMaterialCode(al::LiveActor*, char const*) {
    CRASH
}

const char* al::getCollidedFloorMaterialCodeName(al::LiveActor const*) {
    CRASH
}

bool al::isExistModelResourceYaml(al::LiveActor const*, char const*, char const*) {
    CRASH
}

void al::createFileNameBySuffix(sead::BufferedSafeStringBase<char>*, char const*, char const*) {
    CRASH
}

bool al::isExistModelResource(al::LiveActor const*) {
    CRASH
}

const char* al::createStringIfInStack(char const*) {
    CRASH
}

bool al::tryGetActorInitFileName(sead::BufferedSafeStringBase<char>*, al::LiveActor const*,
                                 char const*, char const*) {
    CRASH
}

void al::tryInitFixedModelGpuBuffer(al::LiveActor*) {
    CRASH
}

bool al::isCollidedGround(al::LiveActor const*) {
    CRASH
}

void al::resetAllCollisionMtx(al::LiveActor*) {
    CRASH
}

void al::setScale(al::LiveActor*, sead::Vector3<float> const&){
    CRASH} sead::Matrix34f* al::getJointMtxPtr(al::LiveActor const*, char const*) {
    CRASH
}

void al::Collider::onInvalidate() {
    CRASH
}

void al::calcTouchScreenPos(sead::Vector2f*) {
    CRASH
}

bool al::sendMsgPlayerReleaseEquipment(al::HitSensor*, al::HitSensor*) {
    CRASH
}

void al::registerSubActor(al::LiveActor*, al::LiveActor*) {
    CRASH
}

void al::getLinksInfoByIndex(al::PlacementInfo*, al::PlacementInfo const&, char const*, int){CRASH}

sead::Matrix34f* al::ModelKeeper::getBaseMtx(){CRASH}

sead::Vector3f al::Collider::collide(sead::Vector3<float> const&) {
    CRASH
}

const sead::Vector3f& al::getCameraPos(const IUseCamera*, s32) {
    CRASH
}
