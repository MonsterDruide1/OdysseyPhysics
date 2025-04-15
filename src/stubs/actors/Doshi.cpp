#include "MapObj/Doshi.h"

Doshi::Doshi(char const*) : al::LiveActor("") {WARN_UNIMPL;}
void Doshi::init(const al::ActorInitInfo& initInfo) {WARN_UNIMPL;}
void Doshi::attackSensor(al::HitSensor* self, al::HitSensor* other) {}
bool Doshi::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
void Doshi::control() {}
