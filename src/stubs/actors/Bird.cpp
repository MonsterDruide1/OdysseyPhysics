#include "Npc/Bird.h"

Bird::Bird(char const*) : al::LiveActor("") {WARN_UNIMPL;}

Bird* Bird::createBirdGlideDownUfo(char const*, al::ActorInitInfo const&) {return new Bird("");}

void Bird::initGlideOff(sead::Matrix34<float> const*, sead::Vector3<float> const&, bool) {}

void Bird::tryStartFlyAway() {}

void Bird::tryStartGlideDown() {}
