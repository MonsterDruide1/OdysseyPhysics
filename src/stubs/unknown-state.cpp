#include "Library/Nerve/NerveStateBase.h"
#include "PlayerUtil.h"

PlayerStateCapCatchPop::PlayerStateCapCatchPop(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*, PlayerAnimator*, HackCap*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateWallAir::PlayerStateWallAir(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerTrigger const*, IUsePlayerCollision*, IJudge*, PlayerJudgePreInputJump*, PlayerAnimator*, PlayerWallActionHistory*, PlayerActionDiveInWater*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateWallCatch::PlayerStateWallCatch(al::LiveActor*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision*, IUsePlayerCeilingCheck const*, PlayerModelHolder const*, PlayerAreaChecker const*, PlayerAnimator*, PlayerTrigger*, PlayerJudgePreInputJump*, PlayerJointParamGrab*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateGrabCeil::PlayerStateGrabCeil(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerModelHolder const*, PlayerTrigger*, IUsePlayerCollision*, PlayerAnimator*, PlayerJudgePreInputJump*, al::HitSensor*, PlayerJointParamGrab*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStatePoleClimb::PlayerStatePoleClimb(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerTrigger const*, PlayerModelHolder*, IUsePlayerCollision*, PlayerAnimator*, PlayerWallActionHistory*, PlayerJointParamHandLegAngle*, PlayerJudgePreInputJump*, PlayerActionDiveInWater*) : al::NerveStateBase("") { WARN_UNIMPL; }
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
PlayerStateSandSink::PlayerStateSandSink(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerTrigger const*, IUsePlayerCollision*, PlayerAnimator*, IJudge*, PlayerJudgePreInputJump*) : al::NerveStateBase("") { WARN_UNIMPL; }
ActorStateSandGeyser::ActorStateSandGeyser(al::LiveActor* act) : al::ActorStateBase("砂の間欠泉", act) { WARN_UNIMPL; }
PlayerStateSpinCap::PlayerStateSpinCap(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerCounterForceRun const*, al::WaterSurfaceFinder const*, IUsePlayerCollision const*, PlayerTrigger*, PlayerSpinCapAttack*, PlayerAnimator*, PlayerJointParamCapThrow*) : al::NerveStateBase("") { WARN_UNIMPL; }
PlayerStateRolling::PlayerStateRolling(al::LiveActor*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, PlayerTrigger*, PlayerAnimator*, PlayerEffect*, PlayerJudgeStartRolling*, IJudge*, PlayerJudgePreInputJump*, PlayerJudgePreInputCapThrow*, IJudge*, PlayerContinuousLongJump*, PlayerSeCtrl*) : al::NerveStateBase("") { WARN_UNIMPL; }

bool PlayerStateRolling::isRollingJump() { WARN_UNIMPL;return false; }
void PlayerStatePoleClimb::setup(al::CollisionParts const*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float, char const*) { WARN_UNIMPL; }
void PlayerStateGrabCeil::setup(al::CollisionParts const*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&) { WARN_UNIMPL; }
bool PlayerStateGrabCeil::isEnableNextGrabCeil() { WARN_UNIMPL; }

bool PlayerStateHack::isEnableModelSyncShowHide() { WARN_UNIMPL;return false; }
void PlayerStateWallAir::calcSnapMoveCutDir(sead::Vector3<float>*) { WARN_UNIMPL; }
bool PlayerStateWallCatch::isWallCatchForm() { WARN_UNIMPL;return false; }
void PlayerStateWallCatch::setup(al::CollisionParts const*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&) { WARN_UNIMPL; }
const sead::Vector3f& PlayerStateWallCatch::getCeilingCheckPos() { WARN_UNIMPL;return sead::Vector3f::zero; }
