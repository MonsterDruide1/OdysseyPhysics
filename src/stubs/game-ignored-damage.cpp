
#include "Player/PlayerFunction.h"
#include "Player/PlayerTrigger.h"

bool PlayerFunction::isPlayerDeadStatus(al::LiveActor const*) { return false; }

bool PlayerTrigger::isOnAnyDamage() const { return false; }
