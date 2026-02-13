#include "Player/Yoshi.h"

Yoshi::Yoshi(const char* actorName) : al::LiveActor(actorName) {}
void Yoshi::init(const al::ActorInitInfo& info) {}
void Yoshi::initAfterPlacement() {}
void Yoshi::movement() {}
void Yoshi::attackSensor(al::HitSensor* self, al::HitSensor* other) {}
bool Yoshi::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
void Yoshi::control() {}
void Yoshi::updateCollider() {}
void Yoshi::updateCollisionShape() {}
void Yoshi::sendCollisionMsg() {}
void Yoshi::appearEgg() {}
void Yoshi::startFruitShineGetDemo() {}
void Yoshi::exeEgg() {}
void Yoshi::exeNpc() {}
void Yoshi::exeHack() {}
