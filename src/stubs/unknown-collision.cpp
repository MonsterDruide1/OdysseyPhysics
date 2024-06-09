#include "Player/CollisionShapeInfo.h"
#include "PlayerUtil.h"
#include "Stuff.h"
#include "Util/PlayerCollisionUtil.h"

void rs::startHitReactionLandJumpIfLanding(al::LiveActor const*, IUsePlayerCollision const*, bool) { CRASH; }

bool rs::tryFindSnapMoveAreaDir(sead::Vector3<float>*, al::LiveActor const*, IUsePlayerCollision const*) { WARN_UNIMPL;return false; }
void rs::calcSnapVelocitySnapMoveAreaWithCutDir(sead::Vector3<float>* result, al::LiveActor const*, IUsePlayerCollision const*, sead::Vector3<float> const& vel, float, sead::Vector3<float> const&) { WARN_UNIMPL;*result=vel; }
void rs::calcSnapVelocitySnapMoveArea(sead::Vector3<float>* result, al::LiveActor const*, IUsePlayerCollision const*, sead::Vector3<float> const& vel, float) { WARN_UNIMPL;*result=vel; }

void PlayerActorBase::sendCollisionMsg() { WARN_UNIMPL; }

void game::PlayerColliderHakoniwa::updateFallDistanceCheck(sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float) { WARN_UNIMPL; }

PlayerFormSensorCollisionArranger::PlayerFormSensorCollisionArranger(al::LiveActor*, PlayerColliderHakoniwa*, IPlayerModelChanger const*, PlayerHackKeeper const*) { WARN_UNIMPL; }

CollisionShapeInfoDisk::CollisionShapeInfoDisk(char const*, float, sead::Vector3<float> const&, sead::Vector3<float> const&, float) : CollisionShapeInfoBase(CollisionShapeId::Disk, nullptr) {CRASH}
