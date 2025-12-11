
#include "Library/Nerve/NerveExecutor.h"
#include "PlayerUtil.h"

PlayerCarryKeeper::PlayerCarryKeeper(al::LiveActor const*, al::HitSensor*, PlayerAnimator*,
                                     IPlayerModelChanger const*, IUsePlayerCeilingCheck const*,
                                     PlayerJointParamHandLegAngle*) : al::NerveExecutor("") {}

bool PlayerCarryKeeper::isThrowRelease() const {
    return false;
}

bool PlayerCarryKeeper::isCarryUp() const {
    return false;
}

bool PlayerCarryKeeper::updateCollideLockUp(IUsePlayerCollision const*, PlayerPushReceiver*) {
    return false;
}

bool PlayerCarryKeeper::isCarry() const {
    return false;
}

bool PlayerCarryKeeper::isCarryWallKeep() const {
    return true;
}

void PlayerCarryKeeper::startCancelAndRelease() {}

bool PlayerCarryKeeper::isThrowHold() const {
    return false;
}

bool PlayerCarryKeeper::isThrow() const {
    return false;
}

void PlayerActorHakoniwa::updateCarry() {}

bool rs::isPlayerCarrySomething(al::LiveActor const*) {
    return false;
}
