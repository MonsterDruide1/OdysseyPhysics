
#include "PlayerUtil.h"
#include "Util/PlayerUtil.h"
#include "Util/ShadowUtil.h"

PlayerCounterIceWater::PlayerCounterIceWater(al::LiveActor*, al::ActorInitInfo const&,
                                             PlayerConst const*, IUsePlayerCollision const*,
                                             IJudge*) {}

void PlayerCounterIceWater::clearIceWaterCount() {}

void PlayerCounterIceWater::updateCount(bool, bool) {}

PlayerJudgeOutInWater::PlayerJudgeOutInWater(al::LiveActor const*, IJudge const*, IJudge const*) {}

void PlayerJudgeOutInWater::update() {}

void PlayerJudgeOutInWater::reset() {}

bool PlayerJudgeOutInWater::judge() const {
    return false;
}

PlayerJudgeInWater::PlayerJudgeInWater(al::LiveActor const*, PlayerConst const*,
                                       IUsePlayerCollision const*, PlayerAreaChecker const*,
                                       al::WaterSurfaceFinder const*, IUsePlayerHeightCheck const*,
                                       PlayerCounterForceRun const*, bool, bool, bool) {}

void PlayerJudgeInWater::update() {}

void PlayerJudgeInWater::reset() {}

bool PlayerJudgeInWater::judge() const {
    return false;
}

PlayerRippleGenerator::PlayerRippleGenerator(al::LiveActor const*, al::LiveActor const*,
                                             PlayerModelHolder const*) {}

PlayerJudgeTalkSwim::PlayerJudgeTalkSwim(PlayerHackKeeper const*, PlayerCarryKeeper const*,
                                         PlayerStateSwim const*) {}

void PlayerJudgeTalkSwim::update() {}

void PlayerJudgeTalkSwim::reset() {}

bool PlayerJudgeTalkSwim::judge() const {
    return false;
}

PlayerStateSwim::PlayerStateSwim(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*,
                                 PlayerInput const*, PlayerTrigger const*, PlayerCarryKeeper const*,
                                 PlayerModelHolder const*, PlayerExternalVelocity const*,
                                 PlayerAnimator*, PlayerSpinCapAttack*,
                                 al::WaterSurfaceFinder const*, PlayerEffect*,
                                 PlayerJointParamSwim*)
    : al::NerveStateBase("") {}

PlayerStateDamageSwim::PlayerStateDamageSwim(al::LiveActor*, PlayerConst const*,
                                             IUsePlayerCollision const*, PlayerInput const*,
                                             PlayerTrigger const*, PlayerAnimator*,
                                             al::WaterSurfaceFinder const*, PlayerEffect*, IJudge*,
                                             IJudge*)
    : al::NerveStateBase("") {}

bool rs::isPlayerInWater(al::LiveActor const*) {return false;}
