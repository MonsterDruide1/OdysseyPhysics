#include "MapObj/Barrel2D.h"

Barrel2D::Barrel2D(char const*) : al::LiveActor("") {WARN_UNIMPL;}
void Barrel2D::appearByGenerator(sead::Vector3<float> const&, sead::Quat<float> const&, float) {}
void Barrel2D::startMove() {}
void Barrel2D::init(const al::ActorInitInfo& info) {}
void Barrel2D::attackSensor(al::HitSensor* self, al::HitSensor* other) {}
bool Barrel2D::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
