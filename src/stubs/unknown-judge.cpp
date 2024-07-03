#include "PlayerUtil.h"

PlayerJudgeAirForceCount::PlayerJudgeAirForceCount(al::LiveActor const*, PlayerExternalVelocity const*, IUsePlayerCollision const*) { WARN_UNIMPL; }
PlayerJudgeLongFall::PlayerJudgeLongFall(al::LiveActor const*, PlayerConst const*, IUsePlayerFallDistanceCheck const*, PlayerHackKeeper const*, PlayerBindKeeper const*, IPlayerModelChanger const*) { WARN_UNIMPL; }
PlayerJudgeSlopeSlide::PlayerJudgeSlopeSlide(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*) { WARN_UNIMPL; }
PlayerJudgeWallCatchInputDir::PlayerJudgeWallCatchInputDir(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerExternalVelocity const*, PlayerCounterForceRun const*, IUsePlayerHeightCheck const*) { WARN_UNIMPL; }

void PlayerJudgeWallCatchInputDir::validateFallJudge() { WARN_UNIMPL; }
void PlayerJudgeWallCatchInputDir::updateWallCatchEnviroment() { WARN_UNIMPL; }
