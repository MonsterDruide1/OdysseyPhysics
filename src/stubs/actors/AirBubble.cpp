#include "MapObj/AirBubble.h"

AirBubble::AirBubble(const char*, bool) : al::LiveActor("") {WARN_UNIMPL;}
void AirBubble::init(const al::ActorInitInfo& info) {}
void AirBubble::endClipped() {}
void AirBubble::startClipped() {}
void AirBubble::appear() {}
void AirBubble::appearPopup() {}
void AirBubble::control() {}
bool AirBubble::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
void AirBubble::exeCreate() {}
void AirBubble::exeWait() {}
void AirBubble::exeReaction() {}
void AirBubble::exeMove() {}
void AirBubble::exeGot() {}
void AirBubble::getItem() {}
void AirBubble::exeCapGet() {}
void AirBubble::exeBreak() {}
