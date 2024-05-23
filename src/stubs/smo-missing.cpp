#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/CollisionUtil.h"
#include "Player/CollisionShapeInfo.h"
#include "math/seadQuat.h"
#include "Library/Math/MathUtil.h"

#include "missing.h"

void al::CollisionParts::calcForceRotatePower(sead::Quatf*) const {CRASH}
void al::CollisionParts::calcForceMovePower(sead::Vector3<float> *,sead::Vector3<float> const&)	const {CRASH}
const al::LiveActor* al::CollisionParts::getConnectedHost() const {CRASH}

CollisionShapeInfoDisk::CollisionShapeInfoDisk(char const*, float, sead::Vector3<float> const&, sead::Vector3<float> const&, float) : CollisionShapeInfoBase(CollisionShapeId::Disk, nullptr) {CRASH}
