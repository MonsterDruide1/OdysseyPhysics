#include "game/CollisionPartsKeeper.h"
#include "../stubs/missing.h"
#include "Library/Collision/CollisionUtil.h"

namespace game {

CollisionPartsKeeper::CollisionPartsKeeper() {
    mPartsList.allocBuffer(256, nullptr);
}
CollisionPartsKeeper::~CollisionPartsKeeper() {
    mPartsList.freeBuffer();
}

void CollisionPartsKeeper::endInit() {
    CRASH
}
void CollisionPartsKeeper::addCollisionParts(al::CollisionParts* parts) {
    mPartsList.pushBack(parts);
    printf("Adding parts %p at %p, now %d entries\n", parts, this, mPartsList.size());
}
void CollisionPartsKeeper::connectToCollisionPartsList(al::CollisionParts*) {
    CRASH
}
void CollisionPartsKeeper::disconnectToCollisionPartsList(al::CollisionParts*) {
    CRASH
}
void CollisionPartsKeeper::resetToCollisionPartsList(al::CollisionParts*) {
    CRASH
}
bool CollisionPartsKeeper::checkStrikePoint(al::HitInfo*, const al::CollisionCheckInfoBase*) const {
    CRASH
}
bool CollisionPartsKeeper::checkStrikeSphere(al::SphereHitResultBuffer*, const al::SphereCheckInfo*, bool, const sead::Vector3f*) const {
    CRASH
}
bool CollisionPartsKeeper::checkStrikeArrow(al::ArrowHitResultBuffer*, const al::ArrowCheckInfo*) const {
    CRASH
}
bool CollisionPartsKeeper::checkStrikeSphereForPlayer(al::SphereHitResultBuffer*, const al::SphereCheckInfo*) const {
    CRASH
}
bool CollisionPartsKeeper::checkStrikeDisk(al::DiskHitResultBuffer*, const al::DiskCheckInfo*) const {
    CRASH
}
void CollisionPartsKeeper::searchWithSphere(const al::SphereCheckInfo* info, sead::IDelegate1<al::CollisionParts*>& delegate) const {
    for(int i=0; i<mPartsList.size(); i++) {
        if(!alCollisionUtil::isFarAway(*mPartsList[i], *info->mPos, info->mRadius))
            delegate(mPartsList[i]);
    }
}

}
