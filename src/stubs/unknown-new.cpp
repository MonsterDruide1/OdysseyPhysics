#include "Boss/Loop/LoopAnimState.h"
#include "Enemy/BubbleStateInLauncher.h"
#include "Enemy/DisregardReceiver.h"
#include "Enemy/GotogotonMark.h"
#include "Library/Event/EventFlowExecutor.h"
#include "Library/Joint/JointSpringControllerHolder.h"
#include "Library/LiveActor/ActorClippingFunction.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorSensorUtil.h"
#include "Library/Math/MathUtil.h"
#include "Library/Movement/AnimScaleController.h"
#include "Library/Nature/NatureUtil.h"
#include "Library/Shadow/ActorShadowUtil.h"
#include "MapObj/CapMessageShowInfo.h"
#include "MapObj/TouchTargetInfo.h"
#include "Player/WhipTargetInfo.h"
#include "Util/CameraUtil.h"
#include "Util/CollisionUtil.h"
#include "Util/Hack.h"
#include "Util/InputInterruptTutorialUtil.h"
#include "Util/ObjUtil.h"
#include "Util/PlayerUtil.h"
#include "Util/ScenePlayerCapFunction.h"
#include "Util/SensorMsgFunction.h"

bool HackFunction::isTriggerCancelBubbleLauncher(IUsePlayerHack const*) {CRASH}

DisregardReceiver::DisregardReceiver(al::LiveActor*, char const*) {CRASH}
bool DisregardReceiver::receiveMsg(al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {CRASH}


void al::AnimScaleController::resetScale() {CRASH}
void al::AnimScaleController::startHitReaction() {CRASH}

al::JointSpringControllerHolder* al::JointSpringControllerHolder::tryCreateAndInitJointControllerKeeper(al::LiveActor*, char const*) {CRASH}
void al::JointSpringControllerHolder::offControlAll() {CRASH}
void al::JointSpringControllerHolder::onControlAll() {CRASH}

const char* al::getFireMaterialCode(al::LiveActor const*) {CRASH}
const sead::Vector3f& al::getShadowMaskOffset(al::LiveActor const*, char const*) {CRASH}
bool al::isInFirePos(al::LiveActor const*, sead::Vector3<float> const&) {CRASH}
void al::offGroupClipping(al::LiveActor*) {CRASH}
void al::onGroupClipping(al::LiveActor*) {CRASH}
bool al::pushAndAddVelocityH(al::LiveActor*, al::HitSensor const*, al::HitSensor const*, float) {CRASH}
void al::showSilhouetteModel(al::LiveActor*) {CRASH}
bool al::tryAddRippleRandomBlur(al::LiveActor const*, sead::Vector3<float> const&, float, float, float) {CRASH}
bool al::tryAddRippleSmall(al::LiveActor const*) {CRASH}
void al::updateBoundingBox(sead::Vector3<float>, sead::Vector3<float>*, sead::Vector3<float>*) {CRASH}
void rs::endHackFromTargetPos(IUsePlayerHack**, sead::Vector3<float> const&, sead::Quat<float> const&, sead::Vector3<float> const&) {CRASH}
void rs::endReset(al::LiveActor*) {CRASH}
void rs::hideHackCap(IUsePlayerHack*) {CRASH}
void rs::hideTutorial(al::IUseSceneObjHolder const*) {CRASH}
bool rs::isActiveHackStartDemo(IUsePlayerHack const*) {CRASH}
bool rs::isHoldHackAction(IUsePlayerHack const*) {CRASH}
bool rs::isHoldHackJump(IUsePlayerHack const*) {CRASH}
bool rs::isTriggerHackAction(IUsePlayerHack const*) {CRASH}
bool rs::isTriggerHackPreInputJump(IUsePlayerHack const*) {CRASH}
bool rs::requestDownToDefaultCameraAngleBySpeed(al::LiveActor const*, float, int) {CRASH}
void rs::requestStageStartHack(al::LiveActor const*, al::HitSensor*, CapTargetInfo const*, al::LiveActor*) {CRASH}
void rs::showHackCap(IUsePlayerHack*) {CRASH}
void rs::showTutorial(al::IUseSceneObjHolder const*) {CRASH}
void rs::solveCollisionInHacking(al::LiveActor*, sead::Vector3<float> const&) {CRASH}
void rs::startReset(al::LiveActor*) {CRASH}

bool EventFlowFunction::isCapTargetHackType(CapTargetInfo const*, int) {CRASH}
bool GotogotonMark::isMatch(GotogotonMark const*) const {CRASH}
void TouchTargetInfo::setInfoByConnector(al::MtxConnector const*, sead::Vector3<float> const&, sead::Vector3<float> const&, bool) {CRASH}
void TouchTargetInfo::setInfoBySensor(al::HitSensor const*, sead::Vector3<float> const&, sead::Vector3<float> const&) {CRASH}
void WhipTargetInfo::initWhipTarget(al::HitSensor*, sead::Vector3<float> const*) {CRASH}
void al::EventFlowExecutor::attackSensor(al::HitSensor*, al::HitSensor*) {CRASH}
void al::validateShadowMask(al::LiveActor*, char const*) {CRASH}
const sead::Vector3f& rs::getPlayerHeadPos(al::LiveActor const*) {CRASH}
bool rs::isMsgHackerDamageAndCancel(al::SensorMsg const*) {CRASH}
bool rs::isPlayerOnActor(al::LiveActor const*) {CRASH}
bool rs::isPlayerSquat(al::LiveActor const*) {CRASH}
bool rs::trySendMsgPlayerReflectOrTrample(al::LiveActor const*, al::HitSensor*, al::HitSensor*) {CRASH}
bool rs::tryShowCapMsgCatchBombCatchFirst(al::IUseSceneObjHolder const*) {CRASH}
