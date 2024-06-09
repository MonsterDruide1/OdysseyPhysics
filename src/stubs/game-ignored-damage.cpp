
#include "Player/PlayerFunction.h"
#include "Player/PlayerTrigger.h"
#include "PlayerUtil.h"

namespace rs {

// if mario gets squished under specific objects (only twice in the whole game) => instant death
bool isPressedCollision(IUsePlayerCollision const*) { return false; }

bool sendMsgNoticePlayerDamage(al::HitSensor*, al::HitSensor*) {}

bool isPlayerDamageStopDemo(al::LiveActor const*) { return false; }

}

bool PlayerFunction::isPlayerDeadStatus(al::LiveActor const*) { return false; }

bool PlayerTrigger::isOnAnyDamage() const { return false; }

PlayerDamageKeeper::PlayerDamageKeeper(al::LiveActor*, PlayerEffect*) {}
void PlayerDamageKeeper::update(IPlayerModelChanger*, bool, bool) {}

void PlayerActorHakoniwa::checkDamageFromCollision() {}
