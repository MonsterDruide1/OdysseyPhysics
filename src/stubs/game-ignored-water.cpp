
#include "PlayerUtil.h"

PlayerActionDiveInWater::PlayerActionDiveInWater(PlayerAnimator*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerJudgeDiveInWater const*) {}

PlayerCounterIceWater::PlayerCounterIceWater(al::LiveActor*, al::ActorInitInfo const&, PlayerConst const*, IUsePlayerCollision const*, IJudge*) {}
void PlayerCounterIceWater::clearIceWaterCount() {}
void PlayerCounterIceWater::updateCount(bool, bool) {}

PlayerJudgeOutInWater::PlayerJudgeOutInWater(al::LiveActor const*, IJudge const*, IJudge const*) {}
void PlayerJudgeOutInWater::update() {}
void PlayerJudgeOutInWater::reset() {}
bool PlayerJudgeOutInWater::judge() const { return false; }

PlayerJudgeStartWaterSurfaceRun::PlayerJudgeStartWaterSurfaceRun(al::LiveActor const*, al::WaterSurfaceFinder const*, PlayerCounterForceRun const*) {}
void PlayerJudgeStartWaterSurfaceRun::update() {}
void PlayerJudgeStartWaterSurfaceRun::reset() {}
bool PlayerJudgeStartWaterSurfaceRun::judge() const { return false; }

PlayerJudgeInWater::PlayerJudgeInWater(al::LiveActor const*, PlayerConst const*, IUsePlayerCollision const*, PlayerAreaChecker const*, al::WaterSurfaceFinder const*, IUsePlayerHeightCheck const*, PlayerCounterForceRun const*, bool, bool, bool) { WARN_UNIMPL; }
void PlayerJudgeInWater::update() {}
void PlayerJudgeInWater::reset() {}
bool PlayerJudgeInWater::judge() const { return false; }
