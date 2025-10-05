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
#include "Library/LiveActor/ActorInitFunction.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/LiveActor/ActorInitUtil.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/ActorResourceFunction.h"
#include "Library/LiveActor/ActorSensorUtil.h"
#include "Library/Math/MathUtil.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Scene/ISceneObj.h"
#include "Library/Scene/SceneUtil.h"
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
#include "Area/In2DAreaMoveControl.h"
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

void al::ActorActionKeeper::updatePost() {
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

void al::SeKeeper::resetPosition() {
    CRASH
}

void al::updateMaterialCodePuddle(al::LiveActor*) {
    CRASH
}

const char* al::getCollidedFloorMaterialCodeName(al::LiveActor const*) {
    CRASH
}

void al::calcTouchScreenPos(sead::Vector2f*) {
    CRASH
}

sead::Vector3f al::Collider::collide(sead::Vector3<float> const&) {
    CRASH
}
