

#include "Library/Anim/AnimPlayerSkl.h"
#include "Library/Area/AreaObjDirector.h"
#include "Library/Base/StringUtil.h"
#include "Library/Controller/JoyPadAccelPoseAnalyzer.h"
#include "Library/Execute/ExecuteTableHolderUpdate.h"
#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorClippingFunction.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/ActorResourceFunction.h"
#include "Library/LiveActor/ActorSensorFunction.h"
#include "Library/LiveActor/ActorSensorMsgFunction.h"
#include "Library/LiveActor/LiveActor.h"
#include "Library/LiveActor/LiveActorUtil.h"
#include "Library/LiveActor/SubActorKeeper.h"
#include "Library/Math/MathAngleUtil.h"
#include "Library/Math/MathLengthUtil.h"
#include "Library/Math/MathUtil.h"
#include "Library/Matrix/MatrixUtil.h"
#include "Library/Model/ModelCtrl.h"
#include "Library/Model/ModelKeeper.h"
#include "Library/Nerve/NerveStateBase.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Player/PlayerHolder.h"
#include "Library/Scene/SceneUtil.h"
#include "Library/Thread/FunctorV0M.h"
#include "Library/stuff.h"
#include "Player/CollisionShapeInfo.h"
#include "Player/HackCap.h"
#include "Player/Player.h"
#include "Player/PlayerActionFunction.h"
#include "Player/PlayerActorBase.h"
#include "Player/PlayerCostumeInfo.h"
#include "Player/PlayerFunction.h"
#include "Player/PlayerInput.h"
#include "Player/PlayerInputFunction.h"
#include "Player/PlayerTrigger.h"
#include "PlayerUtil.h"
#include "Project/Action/ActionAnimCtrl.h"
#include "Project/Anim/AnimPlayerSimple.h"
#include "System/GameDataFunction.h"
#include "Util/ActorDimensionKeeper.h"
#include "Util/PlayerCollisionUtil.h"
#include "Util/Sensor.h"
#include "CUSTOM/PlayerColliderHakoniwa.h"
#include "Stuff.h"
#include "playerUtil.h"

CollisionShapeInfoDisk::CollisionShapeInfoDisk(char const*, float, sead::Vector3<float> const&, sead::Vector3<float> const&, float) : CollisionShapeInfoBase(CollisionShapeId::Disk, nullptr) {CRASH}
al::LiveActor* al::getSubActor(al::LiveActor const*, char const*) { WARN_UNIMPL;return nullptr; }
al::LiveActor* al::tryGetSubActor(al::LiveActor const*, char const*) { WARN_UNIMPL;return nullptr; }
sead::Matrix34f* al::getJointMtxPtr(al::LiveActor const*, char const*) { CRASH;return nullptr; }

void al::onSyncClippingSubActor(al::LiveActor*, al::LiveActor const*) { WARN_UNIMPL; }
void al::onSyncHideSubActor(al::LiveActor*, al::LiveActor const*) { WARN_UNIMPL; }
void al::onSyncAlphaMaskSubActor(al::LiveActor*, al::LiveActor const*) { WARN_UNIMPL; }
PlayerDemoActionFlag::PlayerDemoActionFlag() { WARN_UNIMPL; }
PlayerCapActionHistory::PlayerCapActionHistory(al::LiveActor const*, PlayerConst const*, PlayerTrigger const*, IUsePlayerCollision const*) { WARN_UNIMPL; }
PlayerAreaChecker::PlayerAreaChecker(al::LiveActor const*, PlayerModelHolder const*) { WARN_UNIMPL; }
PlayerWallActionHistory::PlayerWallActionHistory() { WARN_UNIMPL; }
PlayerCounterAfterUpperPunch::PlayerCounterAfterUpperPunch() { WARN_UNIMPL; }
PlayerSandSinkAffect::PlayerSandSinkAffect(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision*, PlayerEffect*) { WARN_UNIMPL; }
PlayerPushReceiver::PlayerPushReceiver(al::LiveActor*) { WARN_UNIMPL; }
PlayerHitPush::PlayerHitPush(al::LiveActor*, PlayerConst*) { WARN_UNIMPL; }
PlayerExternalVelocity::PlayerExternalVelocity(al::LiveActor const*, IUsePlayerCollision const*, sead::Vector3<float> const*) { WARN_UNIMPL; }
al::ISceneObj* al::getSceneObj(al::IUseSceneObjHolder const*, int) { WARN_UNIMPL;return nullptr; }
PlayerSeparateCapFlag::PlayerSeparateCapFlag() { WARN_UNIMPL; }
HackCap::HackCap(al::LiveActor const*, char const*, PlayerInput const*, PlayerAreaChecker const*, PlayerWallActionHistory const*, PlayerCapActionHistory const*, PlayerEyeSensorHitHolder const*, PlayerSeparateCapFlag const*, IUsePlayerCollision const*, IUsePlayerHeightCheck const*, PlayerWetControl const*, PlayerJointControlKeeper const*, HackCapJudgePreInputSeparateThrow*, HackCapJudgePreInputSeparateJump*) : al::LiveActor("") { WARN_UNIMPL; }
PlayerRippleGenerator::PlayerRippleGenerator(al::LiveActor const*, al::LiveActor const*, PlayerModelHolder const*) { WARN_UNIMPL; }
PlayerPuppet::PlayerPuppet(al::LiveActor*, HackCap*, PlayerAnimator*, IUsePlayerCollision*, ActorDimensionKeeper*, IPlayerModelChanger*, WorldEndBorderKeeper*, PlayerCounterForceRun*, PlayerDamageKeeper*, PlayerEffect*, PlayerInput const*, PlayerConst const*) { WARN_UNIMPL; }
PlayerBindKeeper::PlayerBindKeeper(al::HitSensor*, IUsePlayerPuppet*) { WARN_UNIMPL; }

bool PlayerActionDiveInWater::isDiveInWaterAnim() { WARN_UNIMPL; }
PlayerFormSensorCollisionArranger::PlayerFormSensorCollisionArranger(al::LiveActor*, PlayerColliderHakoniwa*, IPlayerModelChanger const*, PlayerHackKeeper const*) { WARN_UNIMPL; }
PlayerCapManHeroEyesControl::PlayerCapManHeroEyesControl(char const*, al::LiveActor*, al::LiveActor*) { WARN_UNIMPL; }
void CapFunction::putOnCapPlayer(HackCap*, PlayerAnimator*) { WARN_UNIMPL; }
bool rs::calcSlideDir(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&) { WARN_UNIMPL;return false; }
bool al::sendMsgPlayerReleaseEquipment(al::HitSensor*, al::HitSensor*) { WARN_UNIMPL; }
bool rs::sendMsgNoticePlayerDamage(al::HitSensor*, al::HitSensor*) { WARN_UNIMPL; }
f32 rs::getGroundHeight(const IUsePlayerHeightCheck*) { WARN_UNIMPL;return 0; }

void al::setScale(al::LiveActor*, sead::Vector3<float> const&) { WARN_UNIMPL; }
void al::normalize(sead::Matrix34<float>*) { WARN_UNIMPL; }
void al::registerSubActor(al::LiveActor*, al::LiveActor*) { WARN_UNIMPL; }
bool PlayerActorBase::checkDeathArea() { WARN_UNIMPL; }
void PlayerActorBase::sendCollisionMsg() { WARN_UNIMPL; }
bool PlayerActorBase::receivePushMsg(al::SensorMsg const*, al::HitSensor*, al::HitSensor*, float) { WARN_UNIMPL; }
void al::getLinksInfoByIndex(al::PlacementInfo*, al::PlacementInfo const&, char const*, int) { WARN_UNIMPL; }
void rs::startHitReactionLandJumpIfLanding(al::LiveActor const*, IUsePlayerCollision const*, bool) { WARN_UNIMPL; }

void PlayerCapActionHistory::clearLandLimitStandAngle() { WARN_UNIMPL; }
void PlayerExternalVelocity::requestApplyLastGroundInertia() { WARN_UNIMPL; }
void PlayerExternalVelocity::cancelAndFeedbackLastGroundInertia(al::LiveActor*, float, bool) { WARN_UNIMPL; }
void PlayerExternalVelocity::update() { WARN_UNIMPL; }

void al::startHitReaction(al::LiveActor const*, char const*) { WARN_UNIMPL; }
bool GameDataFunction::isEnableCap(GameDataHolderAccessor) { WARN_UNIMPL;return true; }
al::AreaObj* al::tryFindAreaObj(al::IUseAreaObj const*, char const*, sead::Vector3<float> const&) { WARN_UNIMPL;return nullptr; }
al::AreaObjGroup* al::tryFindAreaObjGroup(al::IUseAreaObj const*, char const*) { WARN_UNIMPL;return nullptr; }
void rs::noticePlayerJumpStart(PlayerTrigger*, al::LiveActor const*) { WARN_UNIMPL; }
bool rs::isPlayerDamageStopDemo(al::LiveActor const*) { WARN_UNIMPL;return false; }
bool PlayerEquipmentFunction::tryGetEquipmentForceDashInfo(int*, float*, PlayerEquipmentUser const*) { WARN_UNIMPL;return false; }
void PlayerHitPush::clearHitFlag() { WARN_UNIMPL; }
void PlayerPushReceiver::clear() { WARN_UNIMPL; }
void PlayerCapActionHistory::update() { WARN_UNIMPL; }
void PlayerCounterAfterUpperPunch::update(PlayerTrigger const*) { WARN_UNIMPL; }

void PlayerWallActionHistory::update(IUsePlayerCollision const*) { WARN_UNIMPL; }
void game::PlayerColliderHakoniwa::calcSeparateCapLocalOffset(sead::Vector3<float>*) { WARN_UNIMPL; }
void PlayerBindKeeper::clearBindableSensor() { WARN_UNIMPL; }
bool PlayerBindKeeper::sendStartMsg() { WARN_UNIMPL;return false; }
bool PlayerSandSinkAffect::isSinkDeathHeight() { WARN_UNIMPL;return false; }
bool rs::isActiveDemo(al::LiveActor const*) { WARN_UNIMPL;return false; }

void HackCap::updateSeparateMode(PlayerSeparateCapFlag const*) { WARN_UNIMPL; }
bool HackCap::sendMsgStartHack(al::HitSensor*) { WARN_UNIMPL;return false; }
bool HackCap::isNoPutOnHide() { WARN_UNIMPL;return false; }
bool HackCap::isEnableSpinAttack() { WARN_UNIMPL;return false; }
bool HackCap::requestReturn(bool*) { WARN_UNIMPL;return false; }
bool HackCap::isRequestableReturn() { WARN_UNIMPL;return false; }

void al::normalize(sead::Vector2<float>*, sead::Vector2<float> const&) { WARN_UNIMPL; }
f32 al::calcAngleDegree(sead::Vector2<float> const&, sead::Vector2<float> const&) { WARN_UNIMPL;return 0.0f; }
bool al::isInAreaObj(al::IUseAreaObj const*, char const*) { WARN_UNIMPL;return false; }

al::PadRumbleKeeper* al::getPlayerPadRumbleKeeper(al::LiveActor const*, int) { WARN_UNIMPL;int val; return (al::PadRumbleKeeper*)&val; }
void al::JoyPadAccelPoseAnalyzer::update() { WARN_UNIMPL; }
bool PlayerInputFunction::isTriggerCameraReset(al::LiveActor const*, int) { WARN_UNIMPL;return false; }
void PlayerInput::updateInput3D() { WARN_UNIMPL; }
void PlayerInput::updateInput2D() { WARN_UNIMPL; }
void PlayerInput::updateWallAlong() { WARN_UNIMPL; }



bool rs::tryFindSnapMoveAreaDir(sead::Vector3<float>*, al::LiveActor const*, IUsePlayerCollision const*) { WARN_UNIMPL;return false; }
bool rs::isTouchJumpCode(al::LiveActor const*, IUsePlayerCollision const*) { WARN_UNIMPL;return false; }
void rs::resetCollisionPose(const IUsePlayerCollision *, const sead::Quat<float> &) { WARN_UNIMPL; }
void rs::calcSnapVelocitySnapMoveAreaWithCutDir(sead::Vector3<float>* result, al::LiveActor const*, IUsePlayerCollision const*, sead::Vector3<float> const& vel, float, sead::Vector3<float> const&) { WARN_UNIMPL;*result=vel; }
void rs::calcSnapVelocitySnapMoveArea(sead::Vector3<float>* result, al::LiveActor const*, IUsePlayerCollision const*, sead::Vector3<float> const& vel, float) { WARN_UNIMPL;*result=vel; }
void PlayerPushReceiver::calcPushedVelocityWithCollide(sead::Vector3<float>*, sead::Vector3<float> const&, IUsePlayerCollision const*, float) { WARN_UNIMPL; }
bool PlayerPuppet::isNoCollide() { WARN_UNIMPL;return false; }
void game::PlayerColliderHakoniwa::updateFallDistanceCheck(sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float) { WARN_UNIMPL; }

// might be fine to ignore, better replace with proper implementation though
void al::tryReplaceString(sead::BufferedSafeStringBase<char>* result, char const* in, char const* search, char const* replace) {
    result->setReplaceString(in, search, replace);
}
al::HitSensor* al::HitSensorKeeper::getSensor(char const*) const { WARN_UNIMPL; return nullptr; }
void al::registerExecutorFunctor(char const*, al::ExecuteDirector*, al::FunctorBase const&) { WARN_UNIMPL; }
s32 al::calcLinkChildNum(al::PlacementInfo const&, char const*) { WARN_UNIMPL; return 0; }
const char* rs::getInitPlayerModelName(PlayerInitInfo const&) { WARN_UNIMPL; return "Mario"; }
const char* rs::getInitCapTypeName(PlayerInitInfo const&) { WARN_UNIMPL; return "Mario"; }
void al::initActorWithArchiveName(al::LiveActor* actor, al::ActorInitInfo const&, sead::SafeStringBase<char> const&, char const*) {
    actor->mPoseKeeper = new al::ActorPoseKeeperTQGMSV();
    WARN_UNIMPL;
}
void al::initChildActorWithArchiveNameNoPlacementInfo(al::LiveActor*, al::ActorInitInfo const&, sead::SafeStringBase<char> const&, char const*) { WARN_UNIMPL; }
