
#include "PlayerUtil.h"

PlayerActionDiveInWater::PlayerActionDiveInWater(PlayerAnimator*, IPlayerModelChanger const*, PlayerCarryKeeper const*, PlayerJudgeDiveInWater const*) {}

PlayerCounterIceWater::PlayerCounterIceWater(al::LiveActor*, al::ActorInitInfo const&, PlayerConst const*, IUsePlayerCollision const*, IJudge*) {}
void PlayerCounterIceWater::clearIceWaterCount() {}
void PlayerCounterIceWater::updateCount(bool, bool) {}
