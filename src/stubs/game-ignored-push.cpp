#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/CollisionUtil.h"
#include "PlayerUtil.h"

PlayerPushReceiver::PlayerPushReceiver(al::LiveActor*) {}
PlayerHitPush::PlayerHitPush(al::LiveActor*, PlayerConst*) {}

void PlayerHitPush::clearHitFlag() {}
void PlayerPushReceiver::clear() {}
void PlayerPushReceiver::calcPushedVelocityWithCollide(sead::Vector3<float>*, sead::Vector3<float> const&, IUsePlayerCollision const*, float) {}

bool PlayerActorBase::receivePushMsg(al::SensorMsg const*, al::HitSensor*, al::HitSensor*, float) {}

PlayerExternalVelocity::PlayerExternalVelocity(al::LiveActor const*, IUsePlayerCollision const*, sead::Vector3<float> const*) {}
void PlayerExternalVelocity::requestApplyLastGroundInertia() {}
void PlayerExternalVelocity::cancelAndFeedbackLastGroundInertia(al::LiveActor*, float, bool) {}
void PlayerExternalVelocity::update() {}
bool PlayerExternalVelocity::isExistForce() const { return false; }
bool PlayerExternalVelocity::isExistSnapForce() const { return false; }

PlayerBindKeeper::PlayerBindKeeper(al::HitSensor*, IUsePlayerPuppet*) {}
void PlayerBindKeeper::clearBindableSensor() {}
bool PlayerBindKeeper::sendStartMsg() { return false; }

void al::CollisionParts::calcForceMovePower(sead::Vector3<float> * a1,sead::Vector3<float> const&) const {
    *a1 = {0.0f, 0.0f, 0.0f};
}
bool alCollisionUtil::isCollisionMoving(const al::HitInfo* info) {
  return false;
}
