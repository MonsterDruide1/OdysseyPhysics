

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
#include "Util/Sensor.h"
#include "CUSTOM/PlayerColliderHakoniwa.h"
#include "Stuff.h"
#include "playerUtil.h"

// definitely fine to ignore (logic-wise, not sure if nullptr-wise)
bool rs::isClosetScenePlayer(PlayerInitInfo const&) { return false; }
PlayerCostumeInfo* PlayerFunction::initMarioModelActor(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, al::AudioKeeper*, bool) {
    PlayerCostumeInfo* info = new PlayerCostumeInfo();
    info->init(new PlayerBodyCostumeInfo("stub"), new PlayerHeadCostumeInfo("stub"));
    return info;
}
bool PlayerFunction::isInvisibleCap(PlayerCostumeInfo const*) { return false; }
void PlayerFunction::initMarioModelActor2D(al::LiveActor*, al::ActorInitInfo const&, char const*, bool) {}
bool rs::isNeedCreateNoseNeedle(PlayerInitInfo const&) { return false; }
PlayerConst* PlayerFunction::createMarioConst(char const*) { return new PlayerConst(); }
al::LiveActor* PlayerModelHolder::findModelActor(char const*) { return nullptr; }
PlayerJointControlKeeper::PlayerJointControlKeeper(al::LiveActor*, PlayerConst const*, bool, bool, bool) {}
PlayerModelChangerHakoniwa::PlayerModelChangerHakoniwa(al::LiveActor const*, PlayerModelHolder*, PlayerPainPartsKeeper*, PlayerCostumeInfo*, IUseDimension const*) {}
al::ActorDitherAnimator* PlayerFunction::createPlayerDitherAnimator(al::LiveActor*, float) { return nullptr; }
PlayerAnimator::PlayerAnimator(PlayerModelHolder const*, al::ActorDitherAnimator*) {}
PlayerEffect::PlayerEffect(al::LiveActor*, PlayerModelHolder const*, sead::Matrix34<float> const*) {}
bool rs::isGuardNosePainCap(al::LiveActor const*) { return false; }
void al::setModelAlphaMask(al::LiveActor*, float) {}
bool al::isHideModel(al::LiveActor const*) { return false; }
void al::hideModelIfShow(al::LiveActor*) {}
void al::showModelIfHide(al::LiveActor*) {}

bool al::AnimPlayerSkl::startSklAnim(char const*, char const*, char const*, char const*, char const*, char const*, char const*) {}
bool al::AnimPlayerSkl::isSklAnimExist(char const*) {}
const char* al::AnimPlayerSkl::getPlayingSklAnimName(int) {}
void al::AnimPlayerSkl::reset() {}
bool al::AnimPlayerSkl::isSklAnimEnd(int) {}
bool al::AnimPlayerSkl::isSklAnimOneTime(char const*) {}
bool al::AnimPlayerSkl::isSklAnimOneTime(int) {}
bool al::AnimPlayerSkl::isSklAnimPlaying(int) {}
f32 al::AnimPlayerSkl::getSklAnimFrame(int) {}
f32 al::AnimPlayerSkl::getSklAnimFrameRate(int) {}
f32 al::AnimPlayerSkl::getSklAnimFrameMax(int) {}
f32 al::AnimPlayerSkl::getSklAnimFrameMax(char const*) {}
void al::AnimPlayerSkl::setSklAnimFrame(int, float) {}
void al::AnimPlayerSkl::setSklAnimFrameRate(int, float) {}
s32 al::AnimPlayerSkl::getSklAnimBlendNum() {}
f32 al::AnimPlayerSkl::getSklAnimBlendWeight(int) {}
bool al::AnimPlayerSkl::calcSklAnim() {}
bool al::ActionAnimCtrl::isExistAction(char const*) {}
void al::AnimPlayerSimple::startAnim(char const*) {}
void al::AnimPlayerSimple::setAnimFrame(float) {}
void al::AnimPlayerSimple::setAnimFrameRate(float) {}
bool al::AnimPlayerSimple::isAnimExist(char const*) {}
const char* al::AnimPlayerSimple::getPlayingAnimName() {}
void al::AnimPlayerSimple::clearAnim() {}
bool al::AnimPlayerSimple::isAnimEnd() {}
bool al::AnimPlayerSimple::isAnimOneTime(char const*) {}
bool al::AnimPlayerSimple::isAnimOneTime() {}
bool al::AnimPlayerSimple::isAnimPlaying() {}
f32 al::AnimPlayerSimple::getAnimFrame() {}
f32 al::AnimPlayerSimple::getAnimFrameRate() {}
f32 al::AnimPlayerSimple::getAnimFrameMax() {}
f32 al::AnimPlayerSimple::getAnimFrameMax(char const*) {}
void al::AnimPlayerSkl::startPartialAnim(char const*, int, int, al::SklAnimRetargettingInfo const*) {}
void al::AnimPlayerSkl::prepareAnimInterpDirect(int) {}
void al::AnimPlayerSkl::clearPartialAnim(int) {}
bool al::AnimPlayerSkl::isPartialAnimEnd(int) {}
bool al::AnimPlayerSkl::isPartialAnimOneTime(int) {}
bool al::AnimPlayerSkl::isPartialAnimAttached(int) {}
const char* al::AnimPlayerSkl::getPlayingPartialSklAnimName(int) {}
f32 al::AnimPlayerSkl::getPartialAnimFrame(int) {}
void al::AnimPlayerSkl::setPartialAnimFrame(int, float) {}
f32 al::AnimPlayerSkl::getPartialAnimFrameRate(int) {}
void al::AnimPlayerSkl::setPartialAnimFrameRate(int, float) {}
void al::ModelKeeper::calc(sead::Matrix34<float> const&, sead::Vector3<float> const&) {}
void al::AnimPlayerSkl::setSklAnimBlendWeight(int, float) {}


// unknown
CollisionShapeInfoDisk::CollisionShapeInfoDisk(char const*, float, sead::Vector3<float> const&, sead::Vector3<float> const&, float) : CollisionShapeInfoBase(CollisionShapeId::Disk, nullptr) {CRASH}
al::LiveActor* al::getSubActor(al::LiveActor const*, char const*) { WARN_UNIMPL;return nullptr; }
sead::Matrix34f* al::getJointMtxPtr(al::LiveActor const*, char const*) { WARN_UNIMPL;return nullptr; }
void al::onSyncClippingSubActor(al::LiveActor*, al::LiveActor const*) { WARN_UNIMPL; }
void al::onSyncHideSubActor(al::LiveActor*, al::LiveActor const*) { WARN_UNIMPL; }
void al::onSyncAlphaMaskSubActor(al::LiveActor*, al::LiveActor const*) { WARN_UNIMPL; }
void al::setMaterialProgrammable(al::LiveActor*) { WARN_UNIMPL; }
void GameDataFunction::disableCapByPlacement(al::LiveActor const*) { WARN_UNIMPL; }
PlayerContinuousJump::PlayerContinuousJump(PlayerConst const*) { WARN_UNIMPL; }
PlayerContinuousLongJump::PlayerContinuousLongJump(PlayerConst const*) { WARN_UNIMPL; }
PlayerDamageKeeper::PlayerDamageKeeper(al::LiveActor*, PlayerEffect*) { WARN_UNIMPL; }
PlayerDemoActionFlag::PlayerDemoActionFlag() { WARN_UNIMPL; }
PlayerCapActionHistory::PlayerCapActionHistory(al::LiveActor const*, PlayerConst const*, PlayerTrigger const*, IUsePlayerCollision const*) { WARN_UNIMPL; }
PlayerAreaChecker::PlayerAreaChecker(al::LiveActor const*, PlayerModelHolder const*) { WARN_UNIMPL; }
al::WaterSurfaceFinder::WaterSurfaceFinder(al::LiveActor const*) { WARN_UNIMPL; }
WorldEndBorderKeeper::WorldEndBorderKeeper(al::LiveActor const*) : al::NerveExecutor("stub") { WARN_UNIMPL; }
PlayerWallActionHistory::PlayerWallActionHistory() { WARN_UNIMPL; }
PlayerCounterAfterUpperPunch::PlayerCounterAfterUpperPunch() { WARN_UNIMPL; }
PlayerCounterQuickTurnJump::PlayerCounterQuickTurnJump(PlayerConst const*, PlayerTrigger const*) { WARN_UNIMPL; }
PlayerJumpMessageRequest::PlayerJumpMessageRequest() { WARN_UNIMPL; }
PlayerSandSinkAffect::PlayerSandSinkAffect(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision*, PlayerEffect*) { WARN_UNIMPL; }
PlayerEyeSensorHitHolder::PlayerEyeSensorHitHolder(int) { WARN_UNIMPL; }
void PlayerEyeSensorHitHolder::createTargetMarkerBuffer(int) { WARN_UNIMPL; }
PlayerPushReceiver::PlayerPushReceiver(al::LiveActor*) { WARN_UNIMPL; }
PlayerHitPush::PlayerHitPush(al::LiveActor*, PlayerConst*) { WARN_UNIMPL; }
PlayerExternalVelocity::PlayerExternalVelocity(al::LiveActor const*, IUsePlayerCollision const*, sead::Vector3<float> const*) { WARN_UNIMPL; }
al::ISceneObj* al::getSceneObj(al::IUseSceneObjHolder const*, int) { WARN_UNIMPL;return nullptr; }
al::FootPrintHolder::FootPrintHolder(al::LiveActor*, char const*, al::HitSensor*, al::FootPrintServer*) { WARN_UNIMPL; }
PlayerSeparateCapFlag::PlayerSeparateCapFlag() { WARN_UNIMPL; }
PlayerWetControl::PlayerWetControl(al::LiveActor const*, al::LiveActor*, PlayerAreaChecker const*) { WARN_UNIMPL; }
HackCapJudgePreInputSeparateThrow::HackCapJudgePreInputSeparateThrow(PlayerInput const*, PlayerSeparateCapFlag const*) { WARN_UNIMPL; }
HackCapJudgePreInputSeparateJump::HackCapJudgePreInputSeparateJump(PlayerInput const*, PlayerSeparateCapFlag const*) { WARN_UNIMPL; }
HackCap::HackCap(al::LiveActor const*, char const*, PlayerInput const*, PlayerAreaChecker const*, PlayerWallActionHistory const*, PlayerCapActionHistory const*, PlayerEyeSensorHitHolder const*, PlayerSeparateCapFlag const*, IUsePlayerCollision const*, IUsePlayerHeightCheck const*, PlayerWetControl const*, PlayerJointControlKeeper const*, HackCapJudgePreInputSeparateThrow*, HackCapJudgePreInputSeparateJump*) : al::LiveActor("") { WARN_UNIMPL; }
PlayerRippleGenerator::PlayerRippleGenerator(al::LiveActor const*, al::LiveActor const*, PlayerModelHolder const*) { WARN_UNIMPL; }
PlayerRecoverySafetyPoint::PlayerRecoverySafetyPoint(al::LiveActor const*, HackCap const*, al::ActorInitInfo const&, IUseDimension const*, al::CollisionPartsFilterBase*, al::HitSensor*) { WARN_UNIMPL; }
PlayerPuppet::PlayerPuppet(al::LiveActor*, HackCap*, PlayerAnimator*, IUsePlayerCollision*, ActorDimensionKeeper*, IPlayerModelChanger*, WorldEndBorderKeeper*, PlayerCounterForceRun*, PlayerDamageKeeper*, PlayerEffect*, PlayerInput const*, PlayerConst const*) { WARN_UNIMPL; }
PlayerBindKeeper::PlayerBindKeeper(al::HitSensor*, IUsePlayerPuppet*) { WARN_UNIMPL; }
PlayerCarryKeeper::PlayerCarryKeeper(al::LiveActor const*, al::HitSensor*, PlayerAnimator*, IPlayerModelChanger const*, IUsePlayerCeilingCheck const*, PlayerJointParamHandLegAngle*) { WARN_UNIMPL; }
PlayerSeCtrl::PlayerSeCtrl(al::LiveActor const*, PlayerAnimator const*, HackCap const*, PlayerModelChangerHakoniwa const*, al::LiveActor const*, PlayerExternalVelocity const*) { WARN_UNIMPL; }
PlayerHackKeeper::PlayerHackKeeper(al::LiveActor*, HackCap*, PlayerRecoverySafetyPoint*, PlayerInput const*, sead::Matrix34<float> const*, PlayerDamageKeeper const*, IPlayerModelChanger const*, IUsePlayerHeightCheck const*) { WARN_UNIMPL; }
void PlayerHackKeeper::createHackModel(al::ActorInitInfo const&) { WARN_UNIMPL; }
PlayerFormSensorCollisionArranger::PlayerFormSensorCollisionArranger(al::LiveActor*, PlayerColliderHakoniwa*, IPlayerModelChanger const*, PlayerHackKeeper const*) { WARN_UNIMPL; }
al::LiveActor* al::tryGetSubActor(al::LiveActor const*, char const*) { WARN_UNIMPL;return nullptr; }
PlayerCapManHeroEyesControl::PlayerCapManHeroEyesControl(char const*, al::LiveActor*, al::LiveActor*) { WARN_UNIMPL; }
PlayerJudgeAirForceCount::PlayerJudgeAirForceCount(al::LiveActor const*, PlayerExternalVelocity const*, IUsePlayerCollision const*) { WARN_UNIMPL; }
PlayerJudgeCapCatchPop::PlayerJudgeCapCatchPop(al::LiveActor const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCapActionHistory const*, PlayerCounterAfterCapCatch const*) { WARN_UNIMPL; }
PlayerJudgeDeadWipeStart::PlayerJudgeDeadWipeStart(al::LiveActor const*, PlayerConst const*) { WARN_UNIMPL; }
PlayerJudgeDirectRolling::PlayerJudgeDirectRolling(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerCounterForceRun const*) { WARN_UNIMPL; }
PlayerJudgeEnableStandUp::PlayerJudgeEnableStandUp(IUsePlayerCollision const*, IUsePlayerCeilingCheck const*) { WARN_UNIMPL; }
PlayerJudgeForceSlopeSlide::PlayerJudgeForceSlopeSlide(al::LiveActor const*, PlayerConst const*, IUsePlayerCollision const*) { WARN_UNIMPL; }
PlayerJudgeForceRolling::PlayerJudgeForceRolling(al::LiveActor const*, IUsePlayerCollision const*) { WARN_UNIMPL; }
PlayerJudgeGrabCeil::PlayerJudgeGrabCeil(al::LiveActor const*, PlayerConst const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerExternalVelocity const*) { WARN_UNIMPL; }
PlayerJudgeInWater::PlayerJudgeInWater(al::LiveActor const*, PlayerConst const*, IUsePlayerCollision const*, PlayerAreaChecker const*, al::WaterSurfaceFinder const*, IUsePlayerHeightCheck const*, PlayerCounterForceRun const*, bool, bool, bool) { WARN_UNIMPL; }
PlayerJudgeLongFall::PlayerJudgeLongFall(al::LiveActor const*, PlayerConst const*, IUsePlayerFallDistanceCheck const*, PlayerHackKeeper const*, PlayerBindKeeper const*, IPlayerModelChanger const*) { WARN_UNIMPL; }
PlayerJudgePoleClimb::PlayerJudgePoleClimb(al::LiveActor const*, PlayerConst const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerExternalVelocity const*, PlayerInput const*, PlayerTrigger const*) { WARN_UNIMPL; }
PlayerJudgePreInputCapThrow::PlayerJudgePreInputCapThrow(PlayerConst const*, PlayerInput const*, PlayerCarryKeeper const*, HackCap const*) { WARN_UNIMPL; }
PlayerJudgePreInputHackAction::PlayerJudgePreInputHackAction(PlayerConst const*, PlayerInput const*) { WARN_UNIMPL; }
HackCapJudgePreInputHoveringJump::HackCapJudgePreInputHoveringJump(al::LiveActor const*, IUsePlayerCollision const*, HackCap const*, PlayerInput const*) { WARN_UNIMPL; }
PlayerJudgeSandSink::PlayerJudgeSandSink(IUsePlayerCollision const*, PlayerSandSinkAffect const*) { WARN_UNIMPL; }
PlayerJudgeSlopeSlide::PlayerJudgeSlopeSlide(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*) { WARN_UNIMPL; }
PlayerJudgeStartHipDrop::PlayerJudgeStartHipDrop(PlayerConst const*, PlayerInput const*, IUsePlayerHeightCheck const*, IPlayerModelChanger const*) { WARN_UNIMPL; }
PlayerJudgeStartRise::PlayerJudgeStartRise(al::LiveActor const*, PlayerAreaChecker const*, IPlayerModelChanger const*) { WARN_UNIMPL; }
PlayerJudgeStartRolling::PlayerJudgeStartRolling(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*) { WARN_UNIMPL; }
PlayerJudgeStartSquat::PlayerJudgeStartSquat(PlayerInput const*, PlayerCounterForceRun const*, PlayerCarryKeeper const*) { WARN_UNIMPL; }
PlayerJudgeWallCatch::PlayerJudgeWallCatch(al::LiveActor const*, PlayerConst const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerExternalVelocity const*, PlayerInput const*, PlayerTrigger const*, PlayerCounterForceRun const*) { WARN_UNIMPL; }
PlayerJudgeWallCatchInputDir::PlayerJudgeWallCatchInputDir(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerExternalVelocity const*, PlayerCounterForceRun const*, IUsePlayerHeightCheck const*) { WARN_UNIMPL; }
PlayerJudgeWallHitDown::PlayerJudgeWallHitDown(al::LiveActor const*, IUsePlayerCollision const*, PlayerConst const*, PlayerTrigger const*) { WARN_UNIMPL; }
PlayerJudgeWallHitDownForceRun::PlayerJudgeWallHitDownForceRun(al::LiveActor const*, IUsePlayerCollision const*, PlayerConst const*, PlayerCounterForceRun const*, PlayerTrigger const*) { WARN_UNIMPL; }
PlayerJudgeWallHitDownRolling::PlayerJudgeWallHitDownRolling(al::LiveActor const*, IUsePlayerCollision const*, PlayerConst const*, PlayerTrigger const*) { WARN_UNIMPL; }
PlayerJudgeWallKeep::PlayerJudgeWallKeep(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, IUsePlayerHeightCheck const*, PlayerCounterAfterUpperPunch const*, PlayerWallActionHistory const*, PlayerCarryKeeper const*, PlayerTrigger const*, PlayerCounterForceRun const*) { WARN_UNIMPL; }
PlayerJudgeCameraSubjective::PlayerJudgeCameraSubjective(al::LiveActor const*, IUsePlayerCollision const*, PlayerInput const*) { WARN_UNIMPL; }
PlayerSpinCapAttack::PlayerSpinCapAttack(HackCap*, PlayerConst const*, PlayerTrigger const*, PlayerInput const*, PlayerCounterAfterCapCatch const*, PlayerJudgePreInputCapThrow const*) { WARN_UNIMPL; }
PlayerJudgeDiveInWater::PlayerJudgeDiveInWater(al::LiveActor const*, PlayerConst const*, IUsePlayerHeightCheck const*, IUsePlayerFallDistanceCheck const*) { WARN_UNIMPL; }
PlayerActionDiveInWater::PlayerActionDiveInWater(PlayerAnimator*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerJudgeDiveInWater const*) { WARN_UNIMPL; }
PlayerJudgeForceLand::PlayerJudgeForceLand(IJudge const*, PlayerTrigger const*) { WARN_UNIMPL; }
PlayerJudgeOutInWater::PlayerJudgeOutInWater(al::LiveActor const*, IJudge const*, IJudge const*) { WARN_UNIMPL; }
PlayerJudgeStartWaterSurfaceRun::PlayerJudgeStartWaterSurfaceRun(al::LiveActor const*, al::WaterSurfaceFinder const*, PlayerCounterForceRun const*) { WARN_UNIMPL; }
PlayerJudgeSpeedCheckFall::PlayerJudgeSpeedCheckFall(al::LiveActor const*, IUsePlayerCollision const*, PlayerConst const*, IJudge const*) { WARN_UNIMPL; }
PlayerJudgeStartRun::PlayerJudgeStartRun(al::LiveActor const*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*, PlayerCounterForceRun const*, IJudge const*) { WARN_UNIMPL; }
PlayerStateWait::PlayerStateWait(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*, PlayerModelChangerHakoniwa const*, PlayerJointControlKeeper const*, al::WaterSurfaceFinder const*, IUsePlayerHeightCheck const*, IJudge const*, PlayerAnimator*, PlayerTrigger*, PlayerCapManHeroEyesControl*, PlayerJointParamCenterDynamics*, PlayerJointParamGroundPose*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateSandSink::PlayerStateSandSink(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerTrigger const*, IUsePlayerCollision*, PlayerAnimator*, IJudge*, PlayerJudgePreInputJump*) : al::NerveStateBase("") { WARN_UNIMPL; }
ActorStateSandGeyser::ActorStateSandGeyser(al::LiveActor* act) : al::ActorStateBase("砂の間欠泉", act) { WARN_UNIMPL; }
PlayerStateSpinCap::PlayerStateSpinCap(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerCounterForceRun const*, al::WaterSurfaceFinder const*, IUsePlayerCollision const*, PlayerTrigger*, PlayerSpinCapAttack*, PlayerAnimator*, PlayerJointParamCapThrow*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateSquat::PlayerStateSquat(al::LiveActor*, PlayerConst const*, PlayerAnimator*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerTrigger const*, IJudge*, IJudge*, IJudge*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateRunHakoniwa2D3D::PlayerStateRunHakoniwa2D3D(al::LiveActor*, PlayerConst const*, IUseDimension const*, PlayerInput const*, IUsePlayerCollision const*, al::WaterSurfaceFinder const*, PlayerCounterForceRun const*, PlayerCounterQuickTurnJump const*, PlayerTrigger*, PlayerAnimator*, PlayerEffect*, PlayerJointParamCenterDynamics*, bool) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateSlope::PlayerStateSlope(al::LiveActor*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, PlayerAnimator*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateRolling::PlayerStateRolling(al::LiveActor*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, PlayerTrigger*, PlayerAnimator*, PlayerEffect*, PlayerJudgeStartRolling*, IJudge*, PlayerJudgePreInputJump*, PlayerJudgePreInputCapThrow*, IJudge*, PlayerContinuousLongJump*, PlayerSeCtrl*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerJudgeCapCatch::PlayerJudgeCapCatch(al::LiveActor const*, PlayerCounterAfterCapCatch const*) { WARN_UNIMPL; }
HackCapJudgeHoldHoveringJump::HackCapJudgeHoldHoveringJump(al::LiveActor const*, PlayerColliderHakoniwa const*, HackCap const*, PlayerInput const*, PlayerConst const*) { WARN_UNIMPL; }
PlayerStateCapCatchPop::PlayerStateCapCatchPop(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*, PlayerAnimator*, HackCap*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateWallAir::PlayerStateWallAir(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerTrigger const*, IUsePlayerCollision*, IJudge*, PlayerJudgePreInputJump*, PlayerAnimator*, PlayerWallActionHistory*, PlayerActionDiveInWater*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateWallCatch::PlayerStateWallCatch(al::LiveActor*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision*, IUsePlayerCeilingCheck const*, PlayerModelHolder const*, PlayerAreaChecker const*, PlayerAnimator*, PlayerTrigger*, PlayerJudgePreInputJump*, PlayerJointParamGrab*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateGrabCeil::PlayerStateGrabCeil(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerModelHolder const*, PlayerTrigger*, IUsePlayerCollision*, PlayerAnimator*, PlayerJudgePreInputJump*, al::HitSensor*, PlayerJointParamGrab*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStatePoleClimb::PlayerStatePoleClimb(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerTrigger const*, PlayerModelHolder*, IUsePlayerCollision*, PlayerAnimator*, PlayerWallActionHistory*, PlayerJointParamHandLegAngle*, PlayerJudgePreInputJump*, PlayerActionDiveInWater*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateHipDrop::PlayerStateHipDrop(al::LiveActor*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, PlayerAnimator*, PlayerTrigger*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateHeadSliding::PlayerStateHeadSliding(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*, PlayerActionDiveInWater const*, PlayerAnimator*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateLongJump::PlayerStateLongJump(al::LiveActor*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, PlayerTrigger*, PlayerAnimator*, PlayerContinuousLongJump*, PlayerActionDiveInWater*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateRise::PlayerStateRise(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*, PlayerAnimator*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateSwim::PlayerStateSwim(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*, PlayerTrigger const*, PlayerCarryKeeper const*, PlayerModelHolder const*, PlayerExternalVelocity const*, PlayerAnimator*, PlayerSpinCapAttack*, al::WaterSurfaceFinder const*, PlayerEffect*, PlayerJointParamSwim*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateDamageLife::PlayerStateDamageLife(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*, IUsePlayerCeilingCheck const*, PlayerAnimator*, PlayerTrigger*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateDamageSwim::PlayerStateDamageSwim(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*, PlayerTrigger const*, PlayerAnimator*, al::WaterSurfaceFinder const*, PlayerEffect*, IJudge*, IJudge*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateDamageFire::PlayerStateDamageFire(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*, PlayerAnimator*, IJudge*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStatePress::PlayerStatePress(al::LiveActor*, IUsePlayerCollision const*, PlayerAnimator*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateBind::PlayerStateBind(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerPuppet const*, IUsePlayerCollision const*, PlayerTrigger*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateHack::PlayerStateHack(al::LiveActor*, PlayerHackKeeper*, IPlayerModelChanger*, PlayerAnimator*, HackCap*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateEndHack::PlayerStateEndHack(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*, PlayerTrigger*, PlayerAnimator*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateCameraSubjective::PlayerStateCameraSubjective(al::LiveActor*, al::CameraTicket*, IPlayerModelChanger*, PlayerCarryKeeper*, PlayerAnimator*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateAbyss::PlayerStateAbyss(al::LiveActor*, PlayerConst const*, PlayerRecoverySafetyPoint*, PlayerColliderHakoniwa*, PlayerAnimator*, al::LiveActor*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerCounterIceWater::PlayerCounterIceWater(al::LiveActor*, al::ActorInitInfo const&, PlayerConst const*, IUsePlayerCollision const*, IJudge*) { WARN_UNIMPL; }
PlayerStainControl::PlayerStainControl(al::LiveActor const*, al::LiveActor*, PlayerModelChangerHakoniwa const*, HackCap const*, PlayerEffect*) { WARN_UNIMPL; }
PlayerJudgeRecoveryLifeFast::PlayerJudgeRecoveryLifeFast(al::LiveActor const*, PlayerDamageKeeper const*, PlayerBindKeeper const*, IUsePlayerCollision const*, PlayerInput const*, PlayerHackKeeper const*, PlayerStateWait const*, PlayerStateSwim const*, IJudge const*) { WARN_UNIMPL; }
PlayerJudgeCameraInWater::PlayerJudgeCameraInWater(al::LiveActor const*, IJudge const*, al::WaterSurfaceFinder const*) { WARN_UNIMPL; }
PlayerJudgeActiveCameraSubjective::PlayerJudgeActiveCameraSubjective(PlayerStateCameraSubjective const*) { WARN_UNIMPL; }
PlayerJudgeTalkGround::PlayerJudgeTalkGround(al::LiveActor const*, IPlayerModelChanger const*, PlayerHackKeeper const*, PlayerCarryKeeper const*, IUsePlayerCollision const*, PlayerInput const*, PlayerConst const*, PlayerStateWait const*) { WARN_UNIMPL; }
PlayerJudgeTalkSwim::PlayerJudgeTalkSwim(PlayerHackKeeper const*, PlayerCarryKeeper const*, PlayerStateSwim const*) { WARN_UNIMPL; }
PlayerJudgeDead::PlayerJudgeDead(al::LiveActor const*) { WARN_UNIMPL; }
PlayerJudgeDrawForward::PlayerJudgeDrawForward(al::LiveActor const*, PlayerJudgeDeadWipeStart const*) { WARN_UNIMPL; }
PlayerJudgeSameNerve::PlayerJudgeSameNerve(al::IUseNerve const*, al::Nerve const*) { WARN_UNIMPL; }
PlayerJudgeFailureCameraSubjective::PlayerJudgeFailureCameraSubjective(PlayerInput const*, IJudge const*) { WARN_UNIMPL; }
PlayerJudgeSafetyPointRecovery::PlayerJudgeSafetyPointRecovery(IJudge*, PlayerStateAbyss const*) { WARN_UNIMPL; }
PlayerJudgeStatusPoleClimb::PlayerJudgeStatusPoleClimb(IJudge const*, PlayerStatePoleClimb const*) { WARN_UNIMPL; }
PlayerJudgePlaySwitchOnAreaWaitAnim::PlayerJudgePlaySwitchOnAreaWaitAnim(PlayerStateWait const*) { WARN_UNIMPL; }
PlayerJudgeSleep::PlayerJudgeSleep(PlayerStateWait const*) { WARN_UNIMPL; }
PlayerJudgeEnableGuideArrow::PlayerJudgeEnableGuideArrow(PlayerPuppet const*) { WARN_UNIMPL; }
PlayerJudgeEnablePeachAmiibo::PlayerJudgeEnablePeachAmiibo(PlayerStateDamageFire const*) { WARN_UNIMPL; }
void CapFunction::putOnCapPlayer(HackCap*, PlayerAnimator*) { WARN_UNIMPL; }
void rs::resetCollision(IUsePlayerCollision*) { WARN_UNIMPL; }
const al::LayoutInitInfo* al::getLayoutInitInfo(al::ActorInitInfo const&) { WARN_UNIMPL;return nullptr; }
GaugeAir::GaugeAir(char const*, al::LayoutInitInfo const&) { WARN_UNIMPL; }
WaterSurfaceShadow::WaterSurfaceShadow(al::ActorInitInfo const&, char const*) { WARN_UNIMPL; }
void WaterSurfaceShadow::setScale(float) { WARN_UNIMPL; }
bool rs::calcSlideDir(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&) { WARN_UNIMPL;return false; }
bool PlayerCarryKeeper::isCarry() { WARN_UNIMPL;return false; }
void PlayerCarryKeeper::startCancelAndRelease() { WARN_UNIMPL; }
void PlayerStatePoleClimb::setup(al::CollisionParts const*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float, char const*) { WARN_UNIMPL; }
void PlayerStateGrabCeil::setup(al::CollisionParts const*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&) { WARN_UNIMPL; }
bool PlayerStateGrabCeil::isEnableNextGrabCeil() { WARN_UNIMPL; }
void PlayerStateWallCatch::setup(al::CollisionParts const*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&) { WARN_UNIMPL; }
bool PlayerActionDiveInWater::isDiveInWaterAnim() { WARN_UNIMPL; }
bool al::sendMsgPlayerReleaseEquipment(al::HitSensor*, al::HitSensor*) { WARN_UNIMPL; }
bool rs::sendMsgNoticePlayerDamage(al::HitSensor*, al::HitSensor*) { WARN_UNIMPL; }

void al::ModelCtrl::recreateDisplayList() { WARN_UNIMPL; }
void al::ModelKeeper::createMatAnimForProgram(int) { WARN_UNIMPL; }
void alActorSystemFunction::updateExecutorDraw(al::LiveActor*) { WARN_UNIMPL; }
void al::setScale(al::LiveActor*, sead::Vector3<float> const&) { WARN_UNIMPL; }
void al::normalize(sead::Matrix34<float>*) { WARN_UNIMPL; }
void al::invalidateClipping(al::LiveActor*) { WARN_UNIMPL; }
void al::registerSubActor(al::LiveActor*, al::LiveActor*) { WARN_UNIMPL; }
u8* al::getModelResourceYaml(al::LiveActor const*, char const*, char const*) { WARN_UNIMPL; }
void al::offSyncAppearSubActor(al::LiveActor*, al::LiveActor const*) { WARN_UNIMPL; }
void al::offSyncHideSubActor(al::LiveActor*, al::LiveActor const*) { WARN_UNIMPL; }
void al::onSyncAppearSubActor(al::LiveActor*, al::LiveActor const*) { WARN_UNIMPL; }
bool PlayerActorBase::checkDeathArea() { WARN_UNIMPL; }
void PlayerActorBase::sendCollisionMsg() { WARN_UNIMPL; }
bool PlayerActorBase::receivePushMsg(al::SensorMsg const*, al::HitSensor*, al::HitSensor*, float) { WARN_UNIMPL; }
void PlayerJointControlKeeper::resetPartsDynamics() { WARN_UNIMPL; }
void PlayerModelChangerHakoniwa::initStartModel() { WARN_UNIMPL; }
bool PlayerHackKeeper::executeForceHackStageStart(al::HitSensor*, IUsePlayerHack*) { WARN_UNIMPL;return false; }
void al::getLinksInfoByIndex(al::PlacementInfo*, al::PlacementInfo const&, char const*, int) { WARN_UNIMPL; }
void PlayerModelChangerHakoniwa::resetPosition() { WARN_UNIMPL; }
void PlayerStateWait::initSceneStartAnim() { WARN_UNIMPL; }
bool PlayerAnimator::isAnim(sead::SafeStringBase<char> const&) const { WARN_UNIMPL;return false; }
void rs::startHitReactionLandJumpIfLanding(al::LiveActor const*, IUsePlayerCollision const*, bool) { WARN_UNIMPL; }
void PlayerContinuousJump::clear() { WARN_UNIMPL; }

void PlayerCapActionHistory::clearLandLimitStandAngle() { WARN_UNIMPL; }
void PlayerExternalVelocity::requestApplyLastGroundInertia() { WARN_UNIMPL; }
bool PlayerStateWait::isLandStain() { WARN_UNIMPL;return false; }
void PlayerExternalVelocity::cancelAndFeedbackLastGroundInertia(al::LiveActor*, float, bool) { WARN_UNIMPL; }
void PlayerJudgeWallCatchInputDir::validateFallJudge() { WARN_UNIMPL; }
bool PlayerStateWait::isEnableCancelAction() { WARN_UNIMPL;return true; }
bool PlayerStateWait::isEnableCancelHipDropJump() { WARN_UNIMPL;return false; }
bool PlayerJudgeStartRolling::judgeCancelHipDrop() { WARN_UNIMPL;return false; }
bool HackCap::isEnableSpinAttack() { WARN_UNIMPL;return false; }
bool PlayerStateWait::tryConnectWait() { WARN_UNIMPL;return false; }
bool HackCap::requestReturn(bool*) { WARN_UNIMPL;return false;}
bool HackCap::isRequestableReturn() { WARN_UNIMPL;return false;}
void al::startHitReaction(al::LiveActor const*, char const*) { WARN_UNIMPL; }
bool GameDataFunction::isEnableCap(GameDataHolderAccessor) { WARN_UNIMPL;return true;}
void PlayerDamageKeeper::update(IPlayerModelChanger*, bool, bool) { WARN_UNIMPL; }
al::AreaObj* al::tryFindAreaObj(al::IUseAreaObj const*, char const*, sead::Vector3<float> const&) { WARN_UNIMPL;return nullptr;}
al::AreaObjGroup* al::tryFindAreaObjGroup(al::IUseAreaObj const*, char const*) { WARN_UNIMPL;return nullptr;}
bool PlayerCarryKeeper::isThrowRelease() { WARN_UNIMPL;return false;}
void PlayerJointControlKeeper::calcGroundPoseUp(sead::Vector3<float>*) const { WARN_UNIMPL; }
void rs::noticePlayerJumpStart(PlayerTrigger*, al::LiveActor const*) { WARN_UNIMPL; }
bool HackCap::isNoPutOnHide() { WARN_UNIMPL;return false; }
bool rs::isPlayerDamageStopDemo(al::LiveActor const*) { WARN_UNIMPL;return false; }
void PlayerExternalVelocity::update() { WARN_UNIMPL; }
bool PlayerEquipmentFunction::tryGetEquipmentForceDashInfo(int*, float*, PlayerEquipmentUser const*) { WARN_UNIMPL;return false; }
void PlayerAnimator::updateAnimFrame() { WARN_UNIMPL; }
void PlayerEyeSensorHitHolder::clear() { WARN_UNIMPL; }
void PlayerHitPush::clearHitFlag() { WARN_UNIMPL; }
bool PlayerStateHack::isEnableModelSyncShowHide() { WARN_UNIMPL;return false; }
void PlayerModelChangerHakoniwa::syncHost(bool) { WARN_UNIMPL; }
f32 PlayerAnimator::getModelAlpha() { WARN_UNIMPL;return 1.0f; }
void PlayerRecoverySafetyPoint::updateRecoveryBubble() { WARN_UNIMPL; }
void PlayerPushReceiver::clear() { WARN_UNIMPL; }
void PlayerCapActionHistory::update() { WARN_UNIMPL; }
void PlayerCounterAfterUpperPunch::update(PlayerTrigger const*) { WARN_UNIMPL; }
void PlayerCounterIceWater::clearIceWaterCount() { WARN_UNIMPL; }
void PlayerCounterIceWater::updateCount(bool, bool) { WARN_UNIMPL; }
void PlayerCounterQuickTurnJump::update() { WARN_UNIMPL; }
void PlayerRippleGenerator::reset() { WARN_UNIMPL; }
void PlayerWallActionHistory::update(IUsePlayerCollision const*) { WARN_UNIMPL; }
void PlayerContinuousJump::update(bool) { WARN_UNIMPL; }
bool PlayerStateRolling::isRollingJump() { WARN_UNIMPL;return false; }
void PlayerContinuousLongJump::update() { WARN_UNIMPL; }
bool PlayerStateWait::tryClearIgnoreSwitchOnAreaAnim() { WARN_UNIMPL;return false; }
bool PlayerFunction::isPlayerDeadStatus(al::LiveActor const*) { WARN_UNIMPL;return false; }
bool rs::isKidsMode(al::LiveActor const*) { WARN_UNIMPL;return false; }
bool al::isPlayingEntranceCamera(al::IUseCamera const*, int) { WARN_UNIMPL;return false; }
void PlayerJudgeWallCatchInputDir::updateWallCatchEnviroment() { WARN_UNIMPL; }
void PlayerSeCtrl::update() { WARN_UNIMPL; }
void HackCap::updateSeparateMode(PlayerSeparateCapFlag const*) { WARN_UNIMPL; }
void game::PlayerColliderHakoniwa::calcSeparateCapLocalOffset(sead::Vector3<float>*) { WARN_UNIMPL; }
void PlayerBindKeeper::clearBindableSensor() { WARN_UNIMPL; }
bool PlayerBindKeeper::sendStartMsg() { WARN_UNIMPL;return false; }
bool rs::isPressedCollision(IUsePlayerCollision const*) { WARN_UNIMPL;return false; }
bool PlayerSandSinkAffect::isSinkDeathHeight() { WARN_UNIMPL;return false; }
bool rs::isActiveDemo(al::LiveActor const*) { WARN_UNIMPL;return false; }
bool HackCap::sendMsgStartHack(al::HitSensor*) { WARN_UNIMPL;return false; }
bool PlayerTrigger::isOnAnyDamage() const { WARN_UNIMPL;return false; }
bool rs::isTouchJumpCode(al::LiveActor const*, IUsePlayerCollision const*) { WARN_UNIMPL;return false; }
void PlayerInput::updateWallAlong() { WARN_UNIMPL; }
bool rs::tryFindSnapMoveAreaDir(sead::Vector3<float>*, al::LiveActor const*, IUsePlayerCollision const*) { WARN_UNIMPL;return false; }
void PlayerInput::updateInput3D() { WARN_UNIMPL; }
void PlayerInput::updateInput2D() { WARN_UNIMPL; }
void al::normalize(sead::Vector2<float>*, sead::Vector2<float> const&) { WARN_UNIMPL; }
f32 al::calcAngleDegree(sead::Vector2<float> const&, sead::Vector2<float> const&) { WARN_UNIMPL;return 0.0f; }
al::PadRumbleKeeper* al::getPlayerPadRumbleKeeper(al::LiveActor const*, int) { WARN_UNIMPL;int val; return (al::PadRumbleKeeper*)&val; }
void al::JoyPadAccelPoseAnalyzer::update() { WARN_UNIMPL; }
bool al::isInAreaObj(al::IUseAreaObj const*, char const*) { WARN_UNIMPL;return false; }
bool PlayerInputFunction::isTriggerCameraReset(al::LiveActor const*, int) { WARN_UNIMPL;return false; }
bool PlayerStateRunHakoniwa2D3D::isSpinClockwise() { WARN_UNIMPL;return false; }
bool PlayerStateRunHakoniwa2D3D::isRunWaterSurface() { WARN_UNIMPL;return false; }
bool PlayerStateRunHakoniwa2D3D::isGroundSpin() { WARN_UNIMPL;return false; }
bool PlayerStateRunHakoniwa2D3D::isRunDashFast() { WARN_UNIMPL;return false; }
bool PlayerStateRunHakoniwa2D3D::isBrake2D() { WARN_UNIMPL;return false; }
bool PlayerStateRunHakoniwa2D3D::tryTurnJump(IJudge*, sead::Vector3<float>*) { WARN_UNIMPL;return false; }
void rs::resetCollisionPose(const IUsePlayerCollision *, const sead::Quat<float> &) { WARN_UNIMPL; }
bool PlayerStateHipDrop::isLandTrigger() const { WARN_UNIMPL;return false; }

void PlayerStateWallAir::calcSnapMoveCutDir(sead::Vector3<float>*) { WARN_UNIMPL; }
void rs::calcSnapVelocitySnapMoveAreaWithCutDir(sead::Vector3<float>* result, al::LiveActor const*, IUsePlayerCollision const*, sead::Vector3<float> const& vel, float, sead::Vector3<float> const&) { WARN_UNIMPL;*result=vel; }
void rs::calcSnapVelocitySnapMoveArea(sead::Vector3<float>* result, al::LiveActor const*, IUsePlayerCollision const*, sead::Vector3<float> const& vel, float) { WARN_UNIMPL;*result=vel; }
void PlayerPushReceiver::calcPushedVelocityWithCollide(sead::Vector3<float>*, sead::Vector3<float> const&, IUsePlayerCollision const*, float) { WARN_UNIMPL; }
void WorldEndBorderKeeper::update(sead::Vector3<float> const&, sead::Vector3<float> const&, bool) { WARN_UNIMPL; }
bool PlayerPuppet::isNoCollide() { WARN_UNIMPL;return false; }
void al::WaterSurfaceFinder::update(sead::Vector3<float> const&, sead::Vector3<float> const&, float) { WARN_UNIMPL; }
void PlayerEffect::updateWaterSurfaceMtx(al::WaterSurfaceFinder const*) { WARN_UNIMPL; }
bool PlayerStateWallCatch::isWallCatchForm() { WARN_UNIMPL;return false; }
const sead::Vector3f& PlayerStateWallCatch::getCeilingCheckPos() { WARN_UNIMPL;return sead::Vector3f::zero; }
bool PlayerCarryKeeper::isCarryUp() { WARN_UNIMPL;return false; }
void game::PlayerColliderHakoniwa::updateFallDistanceCheck(sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float) { WARN_UNIMPL; }
bool PlayerCarryKeeper::updateCollideLockUp(IUsePlayerCollision const*, PlayerPushReceiver const*) { WARN_UNIMPL;return false; }

// might be fine to ignore, better replace with proper implementation though
void al::tryReplaceString(sead::BufferedSafeStringBase<char>* result, char const* in, char const* search, char const* replace) {
    result->setReplaceString(in, search, replace);
}
al::HitSensor* al::HitSensorKeeper::getSensor(char const*) const { WARN_UNIMPL; return nullptr; }
void al::registerExecutorFunctor(char const*, al::ExecuteDirector*, al::FunctorBase const&) { WARN_UNIMPL; }
s32 al::calcLinkChildNum(al::PlacementInfo const&, char const*) { WARN_UNIMPL; return 0; }
const char* rs::getInitPlayerModelName(PlayerInitInfo const&) { WARN_UNIMPL; return "Mario"; }
const char* rs::getInitCapTypeName(PlayerInitInfo const&) { WARN_UNIMPL; return "Mario"; }
bool ActorDimensionKeeper::update() { WARN_UNIMPL; return false; }
void al::initActorWithArchiveName(al::LiveActor* actor, al::ActorInitInfo const&, sead::SafeStringBase<char> const&, char const*) {
    actor->mPoseKeeper = new al::ActorPoseKeeperTQGMSV();
    WARN_UNIMPL;
}
void al::initChildActorWithArchiveNameNoPlacementInfo(al::LiveActor*, al::ActorInitInfo const&, sead::SafeStringBase<char> const&, char const*) { WARN_UNIMPL; }
