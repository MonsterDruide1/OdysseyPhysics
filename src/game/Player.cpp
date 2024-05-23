#include "game/Player.h"
#include <cstdio>

#include "game/PlayerColliderHakoniwa.h"

namespace game {

Player::Player(const al::ByamlIter& data, const SceneInfo& info) : LiveActor(data, info) {
    //*mPoseKeeper->getTransPtr() += {0, 1000.0f, 0};
    *mPoseKeeper->getVelocityPtr() = {0, -0.01f, 0};
    mPlayerConst = new PlayerConst();
    mColliderHakoniwa = new PlayerColliderHakoniwa(this, mPlayerConst, info.mPartsKeeper);
}

Player::~Player() {
    delete mColliderHakoniwa;
    delete mPlayerConst;
}

void Player::update() {
    LiveActor::update();
    mPoseKeeper->updatePoseTrans(mPoseKeeper->getTrans());

    sead::Vector3f collisionResult = mColliderHakoniwa->updateCollider(mPoseKeeper->getVelocity());

    const sead::Vector3f& a2 = mPoseKeeper->getVelocity();
    const sead::Vector3f& result = collisionResult;
    const PlayerCollider* a1 = mColliderHakoniwa->mPlayerCollider;
    printf("Collide: (%.02f, %.02f, %.02f) => (%.02f, %.02f, %.02f) ; isRecovery=%s\n", a2.x, a2.y, a2.z, result.x, result.y, result.z, "false");
    //printf("mCollisionShapeScale: %.02f\n", a1->mCollisionShapeScale);
    
    *mPoseKeeper->getTransPtr() += collisionResult;
    mPoseKeeper->updatePoseTrans(mPoseKeeper->getTrans());


    
    *mPoseKeeper->getVelocityPtr() -= {0, 1.5f, 0};
}

}  // namespace game
