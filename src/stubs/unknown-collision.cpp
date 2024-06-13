#include "Player/CollisionShapeInfo.h"
#include "PlayerUtil.h"
#include "Stuff.h"
#include "Util/PlayerCollisionUtil.h"

void PlayerActorBase::sendCollisionMsg() { WARN_UNIMPL; }

void game::PlayerColliderHakoniwa::updateFallDistanceCheck(sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float) { WARN_UNIMPL; }

PlayerFormSensorCollisionArranger::PlayerFormSensorCollisionArranger(al::LiveActor*, PlayerColliderHakoniwa*, IPlayerModelChanger const*, PlayerHackKeeper const*) { WARN_UNIMPL; }

CollisionShapeInfoDisk::CollisionShapeInfoDisk(char const*, float, sead::Vector3<float> const&, sead::Vector3<float> const&, float) : CollisionShapeInfoBase(CollisionShapeId::Disk, nullptr) {CRASH}
