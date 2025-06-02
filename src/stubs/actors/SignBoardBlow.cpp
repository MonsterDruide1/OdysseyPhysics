#include "MapObj/SignBoardBlow.h"

SignBoardBlow::SignBoardBlow(const char* actorName, const char* signBoardBlowName) : al::LiveActor("") {}
void SignBoardBlow::init(const al::ActorInitInfo& info) {}
bool SignBoardBlow::receiveMsg(const al::SensorMsg* msg, al::HitSensor* other, al::HitSensor* self) {return false;}
void SignBoardBlow::startBlow(const sead::Vector3f&) {}
void SignBoardBlow::exeWait() {}
void SignBoardBlow::exeBlow() {}
