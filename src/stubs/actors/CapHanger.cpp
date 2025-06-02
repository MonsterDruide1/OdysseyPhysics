#include "MapObj/CapHanger.h"
#include "Library/LiveActor/ActorInitUtil.h"
#include "Library/LiveActor/ActorPoseKeeper.h"

CapHanger::CapHanger(const char*, bool) : al::LiveActor("") {}
void CapHanger::init(const al::ActorInitInfo& info) {al::initActorWithArchiveName(this, info, "CapHanger", nullptr);}
void CapHanger::initItem(s32, s32, const al::ActorInitInfo&) {}
void CapHanger::switchOn() {}
void CapHanger::switchOff() {}
void CapHanger::switchKill() {}
void CapHanger::initAfterPlacement() {}
void CapHanger::kill() {}
void CapHanger::control() {}
void CapHanger::attackSensor(al::HitSensor* other, al::HitSensor* self) {}
bool CapHanger::receiveMsg(const al::SensorMsg* msg, al::HitSensor* other, al::HitSensor* self) {return false;}
void CapHanger::exeWait() {}
void CapHanger::exeKeep() {}
void CapHanger::exeRelease() {}
bool CapHanger::isKeep(s32) const {return false;}
void CapHanger::setPeachCastleCap(const sead::Vector3f&) {}
