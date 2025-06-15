#include "MapObj/TreasureBoxKeyOpener.h"

TreasureBoxKeyOpener::TreasureBoxKeyOpener(const char*) : al::LiveActor("") { WARN_UNIMPL; }
void TreasureBoxKeyOpener::init(const al::ActorInitInfo&) { WARN_UNIMPL; }
void TreasureBoxKeyOpener::initAfterPlacement() {}
void TreasureBoxKeyOpener::appear() {}
void TreasureBoxKeyOpener::makeActorAlive() {}
bool TreasureBoxKeyOpener::receiveMsg(const al::SensorMsg* msg, al::HitSensor* other, al::HitSensor* self) {return false;}
void TreasureBoxKeyOpener::control() {}
bool TreasureBoxKeyOpener::isGot() {return false;}
void TreasureBoxKeyOpener::exeAppear() {}
void TreasureBoxKeyOpener::exeWait() {}
void TreasureBoxKeyOpener::exeGot() {}
void TreasureBoxKeyOpener::setHostForClipping(al::LiveActor*) {}
