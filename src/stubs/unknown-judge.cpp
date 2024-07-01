#include "PlayerUtil.h"

// removed soon
PlayerJudgeGrabCeil::PlayerJudgeGrabCeil(al::LiveActor const*, PlayerConst const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerExternalVelocity const*) { WARN_UNIMPL; }
void PlayerJudgeGrabCeil::reset() {}
void PlayerJudgeGrabCeil::update() {}
bool PlayerJudgeGrabCeil::judge() const { return false; }


PlayerJudgeAirForceCount::PlayerJudgeAirForceCount(al::LiveActor const*, PlayerExternalVelocity const*, IUsePlayerCollision const*) { WARN_UNIMPL; }
PlayerJudgeCapCatchPop::PlayerJudgeCapCatchPop(al::LiveActor const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCapActionHistory const*, PlayerCounterAfterCapCatch const*) { WARN_UNIMPL; }
PlayerJudgeDirectRolling::PlayerJudgeDirectRolling(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerCounterForceRun const*) { WARN_UNIMPL; }
PlayerJudgeLongFall::PlayerJudgeLongFall(al::LiveActor const*, PlayerConst const*, IUsePlayerFallDistanceCheck const*, PlayerHackKeeper const*, PlayerBindKeeper const*, IPlayerModelChanger const*) { WARN_UNIMPL; }
PlayerJudgeSlopeSlide::PlayerJudgeSlopeSlide(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*) { WARN_UNIMPL; }
PlayerJudgeWallCatchInputDir::PlayerJudgeWallCatchInputDir(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerExternalVelocity const*, PlayerCounterForceRun const*, IUsePlayerHeightCheck const*) { WARN_UNIMPL; }
PlayerJudgePlaySwitchOnAreaWaitAnim::PlayerJudgePlaySwitchOnAreaWaitAnim(PlayerStateWait const*) { WARN_UNIMPL; }
PlayerJudgeSleep::PlayerJudgeSleep(PlayerStateWait const*) { WARN_UNIMPL; }
PlayerJudgeCapCatch::PlayerJudgeCapCatch(al::LiveActor const*, PlayerCounterAfterCapCatch const*) { WARN_UNIMPL; }
PlayerJudgeWallPush::PlayerJudgeWallPush(al::LiveActor const*, IUsePlayerCollision const*, PlayerInput const*) { WARN_UNIMPL; }

HackCapJudgePreInputHoveringJump::HackCapJudgePreInputHoveringJump(al::LiveActor const*, IUsePlayerCollision const*, HackCap const*, PlayerInput const*) { WARN_UNIMPL; }
HackCapJudgeHoldHoveringJump::HackCapJudgeHoldHoveringJump(al::LiveActor const*, PlayerColliderHakoniwa const*, HackCap const*, PlayerInput const*, PlayerConst const*) { WARN_UNIMPL; }
HackCapJudgePreInputSeparateThrow::HackCapJudgePreInputSeparateThrow(PlayerInput const*, PlayerSeparateCapFlag const*) { WARN_UNIMPL; }

void PlayerJudgeWallCatchInputDir::validateFallJudge() { WARN_UNIMPL; }
void PlayerJudgeWallCatchInputDir::updateWallCatchEnviroment() { WARN_UNIMPL; }
