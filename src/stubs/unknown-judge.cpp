#include "PlayerUtil.h"

PlayerJudgeAirForceCount::PlayerJudgeAirForceCount(al::LiveActor const*, PlayerExternalVelocity const*, IUsePlayerCollision const*) { WARN_UNIMPL; }
PlayerJudgeCapCatchPop::PlayerJudgeCapCatchPop(al::LiveActor const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCapActionHistory const*, PlayerCounterAfterCapCatch const*) { WARN_UNIMPL; }
PlayerJudgeDirectRolling::PlayerJudgeDirectRolling(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerCounterForceRun const*) { WARN_UNIMPL; }
PlayerJudgeGrabCeil::PlayerJudgeGrabCeil(al::LiveActor const*, PlayerConst const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerExternalVelocity const*) { WARN_UNIMPL; }
PlayerJudgeLongFall::PlayerJudgeLongFall(al::LiveActor const*, PlayerConst const*, IUsePlayerFallDistanceCheck const*, PlayerHackKeeper const*, PlayerBindKeeper const*, IPlayerModelChanger const*) { WARN_UNIMPL; }
PlayerJudgePoleClimb::PlayerJudgePoleClimb(al::LiveActor const*, PlayerConst const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerExternalVelocity const*, PlayerInput const*, PlayerTrigger const*) { WARN_UNIMPL; }
PlayerJudgeSandSink::PlayerJudgeSandSink(IUsePlayerCollision const*, PlayerSandSinkAffect const*) { WARN_UNIMPL; }
PlayerJudgeSlopeSlide::PlayerJudgeSlopeSlide(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*) { WARN_UNIMPL; }
PlayerJudgeStartRolling::PlayerJudgeStartRolling(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*) { WARN_UNIMPL; }
PlayerJudgeWallCatch::PlayerJudgeWallCatch(al::LiveActor const*, PlayerConst const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerExternalVelocity const*, PlayerInput const*, PlayerTrigger const*, PlayerCounterForceRun const*) { WARN_UNIMPL; }
PlayerJudgeWallCatchInputDir::PlayerJudgeWallCatchInputDir(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerExternalVelocity const*, PlayerCounterForceRun const*, IUsePlayerHeightCheck const*) { WARN_UNIMPL; }
PlayerJudgeWallHitDown::PlayerJudgeWallHitDown(al::LiveActor const*, IUsePlayerCollision const*, PlayerConst const*, PlayerTrigger const*) { WARN_UNIMPL; }
PlayerJudgeWallHitDownForceRun::PlayerJudgeWallHitDownForceRun(al::LiveActor const*, IUsePlayerCollision const*, PlayerConst const*, PlayerCounterForceRun const*, PlayerTrigger const*) { WARN_UNIMPL; }
PlayerJudgeWallHitDownRolling::PlayerJudgeWallHitDownRolling(al::LiveActor const*, IUsePlayerCollision const*, PlayerConst const*, PlayerTrigger const*) { WARN_UNIMPL; }
PlayerJudgeWallKeep::PlayerJudgeWallKeep(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, IUsePlayerHeightCheck const*, PlayerCounterAfterUpperPunch const*, PlayerWallActionHistory const*, PlayerCarryKeeper const*, PlayerTrigger const*, PlayerCounterForceRun const*) { WARN_UNIMPL; }
PlayerJudgeCameraSubjective::PlayerJudgeCameraSubjective(al::LiveActor const*, IUsePlayerCollision const*, PlayerInput const*) { WARN_UNIMPL; }
PlayerSpinCapAttack::PlayerSpinCapAttack(HackCap*, PlayerConst const*, PlayerTrigger const*, PlayerInput const*, PlayerCounterAfterCapCatch const*, PlayerJudgePreInputCapThrow const*) { WARN_UNIMPL; }
PlayerJudgeDiveInWater::PlayerJudgeDiveInWater(al::LiveActor const*, PlayerConst const*, IUsePlayerHeightCheck const*, IUsePlayerFallDistanceCheck const*) { WARN_UNIMPL; }
PlayerJudgeCameraInWater::PlayerJudgeCameraInWater(al::LiveActor const*, IJudge const*, al::WaterSurfaceFinder const*) { WARN_UNIMPL; }
PlayerJudgeActiveCameraSubjective::PlayerJudgeActiveCameraSubjective(PlayerStateCameraSubjective const*) { WARN_UNIMPL; }
PlayerJudgeTalkSwim::PlayerJudgeTalkSwim(PlayerHackKeeper const*, PlayerCarryKeeper const*, PlayerStateSwim const*) { WARN_UNIMPL; }
PlayerJudgeDead::PlayerJudgeDead(al::LiveActor const*) { WARN_UNIMPL; }
PlayerJudgeDrawForward::PlayerJudgeDrawForward(al::LiveActor const*, PlayerJudgeDeadWipeStart const*) { WARN_UNIMPL; }
PlayerJudgeSameNerve::PlayerJudgeSameNerve(al::IUseNerve const*, al::Nerve const*) { WARN_UNIMPL; }
PlayerJudgeFailureCameraSubjective::PlayerJudgeFailureCameraSubjective(PlayerInput const*, IJudge const*) { WARN_UNIMPL; }
PlayerJudgeStatusPoleClimb::PlayerJudgeStatusPoleClimb(IJudge const*, PlayerStatePoleClimb const*) { WARN_UNIMPL; }
PlayerJudgePlaySwitchOnAreaWaitAnim::PlayerJudgePlaySwitchOnAreaWaitAnim(PlayerStateWait const*) { WARN_UNIMPL; }
PlayerJudgeSleep::PlayerJudgeSleep(PlayerStateWait const*) { WARN_UNIMPL; }
PlayerJudgeEnableGuideArrow::PlayerJudgeEnableGuideArrow(PlayerPuppet const*) { WARN_UNIMPL; }
PlayerJudgeEnablePeachAmiibo::PlayerJudgeEnablePeachAmiibo(PlayerStateDamageFire const*) { WARN_UNIMPL; }
PlayerJudgeForceLand::PlayerJudgeForceLand(IJudge const*, PlayerTrigger const*) { WARN_UNIMPL; }
PlayerJudgeCapCatch::PlayerJudgeCapCatch(al::LiveActor const*, PlayerCounterAfterCapCatch const*) { WARN_UNIMPL; }
PlayerJudgeStartGroundSpin::PlayerJudgeStartGroundSpin(al::LiveActor const*, IUsePlayerCollision const*, PlayerInput const*) { WARN_UNIMPL; }
PlayerJudgeWaterSurfaceRun::PlayerJudgeWaterSurfaceRun(al::LiveActor const*, PlayerConst const*, al::WaterSurfaceFinder const*, PlayerCounterForceRun const*) { WARN_UNIMPL; }
PlayerJudgeWallPush::PlayerJudgeWallPush(al::LiveActor const*, IUsePlayerCollision const*, PlayerInput const*) { WARN_UNIMPL; }

HackCapJudgePreInputHoveringJump::HackCapJudgePreInputHoveringJump(al::LiveActor const*, IUsePlayerCollision const*, HackCap const*, PlayerInput const*) { WARN_UNIMPL; }
HackCapJudgeHoldHoveringJump::HackCapJudgeHoldHoveringJump(al::LiveActor const*, PlayerColliderHakoniwa const*, HackCap const*, PlayerInput const*, PlayerConst const*) { WARN_UNIMPL; }
HackCapJudgePreInputSeparateThrow::HackCapJudgePreInputSeparateThrow(PlayerInput const*, PlayerSeparateCapFlag const*) { WARN_UNIMPL; }
HackCapJudgePreInputSeparateJump::HackCapJudgePreInputSeparateJump(PlayerInput const*, PlayerSeparateCapFlag const*) { WARN_UNIMPL; }

void PlayerJudgeWallCatchInputDir::validateFallJudge() { WARN_UNIMPL; }
void PlayerJudgeWallCatchInputDir::updateWallCatchEnviroment() { WARN_UNIMPL; }
bool PlayerJudgeStartRolling::judgeCancelHipDrop() { WARN_UNIMPL;return false; }
