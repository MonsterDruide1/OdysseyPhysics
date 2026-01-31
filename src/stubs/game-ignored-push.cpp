#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/CollisionUtil.h"
#include "PlayerUtil.h"

PlayerExternalVelocity::PlayerExternalVelocity(al::LiveActor const*, IUsePlayerCollision const*,
                                               sead::Vector3<float> const*) {}
void PlayerExternalVelocity::requestApplyLastGroundInertia() {}
void PlayerExternalVelocity::cancelAndFeedbackLastGroundInertia(al::LiveActor*, float, bool) {}
void PlayerExternalVelocity::update() {}
bool PlayerExternalVelocity::isExistForce() const {return false;}
bool PlayerExternalVelocity::isExistSnapForce() const {return false;}

PlayerBindKeeper::PlayerBindKeeper(al::HitSensor*, IUsePlayerPuppet*) {}
void PlayerBindKeeper::clearBindableSensor() {}
bool PlayerBindKeeper::sendStartMsg() {return false;}

void al::CollisionParts::calcForceMovePower(sead::Vector3f* a1, const sead::Vector3f&) const {*a1 = {0.0f, 0.0f, 0.0f};}

bool alCollisionUtil::isCollisionMoving(const al::HitInfo*) {return false;}
