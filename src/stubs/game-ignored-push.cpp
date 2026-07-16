#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/CollisionUtil.h"
#include "PlayerUtil.h"
#include "Util/AreaUtil.h"

PlayerBindKeeper::PlayerBindKeeper(al::HitSensor*, IUsePlayerPuppet*) {}
void PlayerBindKeeper::clearBindableSensor() {}
bool PlayerBindKeeper::sendStartMsg() {return false;}

void al::CollisionParts::calcForceMovePower(sead::Vector3f* a1, const sead::Vector3f&) const {*a1 = {0.0f, 0.0f, 0.0f};}

bool alCollisionUtil::isCollisionMoving(const al::HitInfo*) {return false;}

bool rs::calcExtForceAreaVelocity(sead::Vector3<float>*, al::IUseAreaObj const*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&) {return false;}
bool al::calcForceMovePowerExceptNormal(sead::Vector3<float>*, al::CollisionParts const*, sead::Vector3<float> const&, sead::Vector3<float> const&) {return false;}
