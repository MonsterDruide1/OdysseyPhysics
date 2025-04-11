#include "MapObj/HipDropSwitch.h"

HipDropSwitch::HipDropSwitch(const char*) : al::LiveActor("") {WARN_UNIMPL;}
bool HipDropSwitch::isOnWait() const {return false;}
void HipDropSwitch::init(const al::ActorInitInfo& initInfo) {WARN_UNIMPL;}
void HipDropSwitch::reset() {}
void HipDropSwitch::startClipped() {}
bool HipDropSwitch::receiveMsg(const al::SensorMsg *, al::HitSensor *self, al::HitSensor *other) {return false;}
void HipDropSwitch::control() {}
