#include "MapObj/Car.h"

Car::Car(const char* name) : al::LiveActor(name) {WARN_UNIMPL;}

void Car::init(const al::ActorInitInfo& info) {}

void Car::kill() {}

void Car::calcAnim() {}

void Car::movement() {}

void Car::control() {}

void Car::attackSensor(al::HitSensor* self, al::HitSensor* other) {}

bool Car::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}

void Car::exeWait() {}

void Car::exeRun() {}

bool Car::tryBrake() {return false;}

void Car::exeBrake() {}

void Car::exeStop() {}
