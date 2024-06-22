
#include "PlayerUtil.h"

PlayerCarryKeeper::PlayerCarryKeeper(al::LiveActor const*, al::HitSensor*, PlayerAnimator*, IPlayerModelChanger const*, IUsePlayerCeilingCheck const*, PlayerJointParamHandLegAngle*) {}
bool PlayerCarryKeeper::isThrowRelease() { return false;}
bool PlayerCarryKeeper::isCarryUp() { return false; }
bool PlayerCarryKeeper::updateCollideLockUp(IUsePlayerCollision const*, PlayerPushReceiver const*) { return false; }
bool PlayerCarryKeeper::isCarry() { return false; }
bool PlayerCarryKeeper::isCarry() const { return false; }
void PlayerCarryKeeper::startCancelAndRelease() {}
bool PlayerCarryKeeper::isThrowHold() const { return false; }
bool PlayerCarryKeeper::isThrow() const { return false; }

void PlayerActorHakoniwa::updateCarry() {}
