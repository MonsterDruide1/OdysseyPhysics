#include "CUSTOM/CollisionPartsKeeper.h"
#include "Library/Collision/CollisionCheckInfo.h"
#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/CollisionUtil.h"

namespace game {

CollisionPartsKeeper::CollisionPartsKeeper() {
    mPartsList.allocBuffer(1024, nullptr);
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

bool CollisionPartsKeeper::checkStrikePoint(al::HitInfo*, const al::CollisionCheckInfoBase&) const {
    CRASH
}

bool CollisionPartsKeeper::checkStrikeSphere(al::SphereHitResultBuffer* results, const al::SphereCheckInfo& info,
                                             bool a4, const sead::Vector3f& a5) const {
    CRASH
}

bool CollisionPartsKeeper::checkStrikeArrow(al::ArrowHitResultBuffer* results,
                                            const al::ArrowCheckInfo& info) const {
    int numCollisions = 0;
    for (int i = 0; i < mPartsList.size(); i++) {
        numCollisions +=
            mPartsList[i]->checkStrikeArrow(results, info.mPos, info.unk1, info.mTriFilterBase);
        if (results->isFull())
            break;
    }
    return numCollisions;
}

bool CollisionPartsKeeper::checkStrikeSphereForPlayer(al::SphereHitResultBuffer*,
                                                      const al::SphereCheckInfo&) const {
    CRASH
}

bool CollisionPartsKeeper::checkStrikeDisk(al::DiskHitResultBuffer*,
                                           const al::DiskCheckInfo&) const {
    CRASH
}

void CollisionPartsKeeper::searchWithSphere(const al::SphereCheckInfo& info,
                                            sead::IDelegate1<al::CollisionParts*>& delegate) const {
    for (int i = 0; i < mPartsList.size(); i++)
        if (!alCollisionUtil::isFarAway(*mPartsList[i], info.mPos, info.mRadius))
            delegate(mPartsList[i]);
}

void CollisionPartsKeeper::movement() {
    CRASH
}

}  // namespace game
