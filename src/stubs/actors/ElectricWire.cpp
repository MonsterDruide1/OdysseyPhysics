#include "MapObj/ElectricWire/ElectricWire.h"

ElectricWire::ElectricWire(const char* name) : al::LiveActor(name) {}
void ElectricWire::init(const al::ActorInitInfo& info) {}
bool ElectricWire::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
void ElectricWire::attackSensor(al::HitSensor* self, al::HitSensor* other) {}
void ElectricWire::initAfterPlacement() {}
void ElectricWire::control() {}
bool ElectricWire::tryCreateElectricWireLinks(al::LiveActor**, al::LiveActor*, const al::ActorInitInfo&, const char*, s32) {return false;}
void ElectricWire::createGraph(const al::ActorInitInfo&) {}
void ElectricWire::switchStartOn() {}
void ElectricWire::tryUpdateDisplayModel() {}
ElectricWireVertex* ElectricWire::searchAliveKeeperGraphVertexBySensor(const al::HitSensor*) {return nullptr;}
void ElectricWire::endCapture(const sead::Vector3f*, const sead::Vector3f*, bool, bool) {}
void ElectricWire::afterSpringMovement() {}
void ElectricWire::springMovement() {}
void ElectricWire::exeHackEnd() {}
void ElectricWire::exeStandby() {}
void ElectricWire::exeCaptureWait() {}
void ElectricWire::exeCaptureStart() {}
void ElectricWire::exeCaptureHackStart() {}
bool ElectricWire::trySwitchMoveEndCamera(const ElectricWireVertex*) {return false;}
void ElectricWire::exeSwitchRail() {}
void ElectricWire::trySetPoseGraphMoveDir(f32) {}
const char* ElectricWire::getMoveActionName() const {return "";}
const char* ElectricWire::getMoveAttackableActionName() const {return "";}
const char* ElectricWire::getSparkActionName() const {return "";}
void ElectricWire::exeTurnFrontStartDemo() {}
void ElectricWire::exeMove() {}
bool ElectricWire::checkMovableInputAndNextNerve() {return false;}
f32 ElectricWire::checkEnableMoveByGraph(const al::Graph::PosVertex**, const sead::Vector2f&, const al::LiveActor*, const al::Graph::PosVertex*) {return 0.0f;}
ElectricWireVertex* ElectricWire::checkMovableInputNextByGraph(bool*, const al::Graph::PosVertex*, const sead::Vector2f&) {return nullptr;}
void ElectricWire::exeMoveEnd() {}
void ElectricWire::onMoveEndEnd() {}
void ElectricWire::exeLightning() {}
void ElectricWire::exeLightningEnd() {}
void ElectricWire::exeLightningEndToMove() {}
void ElectricWire::addDemoActorElectricWirePartsAll() {}
