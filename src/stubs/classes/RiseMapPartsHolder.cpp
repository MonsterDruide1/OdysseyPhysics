#include "MapObj/RiseMapPartsHolder.h"

RiseMapPartsHolder::RiseMapPartsHolder(char const*) : al::LiveActor("") {}
void RiseMapPartsHolder::startDemo(bool) {}
void RiseMapPartsHolder::init(const al::ActorInitInfo&) {}
bool RiseMapPartsHolder::receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                al::HitSensor* self) { return false; }
