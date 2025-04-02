#include "Enemy/KuriboMini.h"

KuriboMini::KuriboMini(char const*) : al::LiveActor("") {WARN_UNIMPL;}
void KuriboMini::init(const al::ActorInitInfo& info) {WARN_UNIMPL;}
void KuriboMini::makeActorAlive() {}
void KuriboMini::makeActorDead() {}
void KuriboMini::appear() {}
void KuriboMini::kill() {}
void KuriboMini::appearPop() {}
void KuriboMini::appearPopBack() {}
void KuriboMini::control() {}
void KuriboMini::updateCollider() {}
void KuriboMini::startClipped() {}
void KuriboMini::endClipped() {}
void KuriboMini::attackSensor(al::HitSensor* self, al::HitSensor* other) {}
bool KuriboMini::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
