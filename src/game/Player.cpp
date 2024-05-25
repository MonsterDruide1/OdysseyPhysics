#include "game/Player.h"
#include <cstdio>

#include "game/PlayerColliderHakoniwa.h"

namespace game {

Player::Player(const al::ByamlIter& data, const SceneInfo& info) : LiveActor(data, info) {
    //*mPoseKeeper->getTransPtr() += {0, 1000.0f, 0};
    *mPoseKeeper->getVelocityPtr() = {0, -0.01f, 0};
    mPlayerConst = new PlayerConst();
    mCollisionDirector = new al::CollisionDirector(nullptr);
    mCollisionDirector->setPartsKeeper(info.mPartsKeeper);
    mColliderHakoniwa = new PlayerColliderHakoniwa(this, mPlayerConst, mCollisionDirector);
}

Player::~Player() {
    delete mColliderHakoniwa;
    delete mPlayerConst;
    delete mCollisionDirector;
}

void Player::initAfterPlacement() {
    mPoseKeeper->getVelocityPtr()->y = -0.01f;
    updateCollider();
    *mPoseKeeper->getVelocityPtr() = {0, 0.0f, 0};
}

void Player::update() {
    LiveActor::update();
    updateCollider();

    if(mColliderHakoniwa->mPlayerCollider->val1 >= 0.0f) {
        mPoseKeeper->getVelocityPtr()->y = std::max(0.0f, mPoseKeeper->getVelocity().y);
    }
    *mPoseKeeper->getVelocityPtr() -= {0, 1.5f, 0};
    mPoseKeeper->getVelocityPtr()->y = std::max(-30.0f, mPoseKeeper->getVelocity().y);
}

void Player::updateCollider() {
    mPoseKeeper->updatePoseTrans(mPoseKeeper->getTrans());

    sead::Vector3f collisionResult = mColliderHakoniwa->updateCollider(mPoseKeeper->getVelocity());

    const sead::Vector3f& a2 = mPoseKeeper->getVelocity();
    const sead::Vector3f& result = collisionResult;
    const PlayerCollider* a1 = mColliderHakoniwa->mPlayerCollider;
    printf("Collide: (%.02f, %.02f, %.02f)+(%.02f, %.02f, %.02f) => (%.02f, %.02f, %.02f) ; isRecovery=%s\n", a1->mTrans.x, a1->mTrans.y, a1->mTrans.z, a2.x, a2.y, a2.z, result.x, result.y, result.z, "false");
    
    *mPoseKeeper->getTransPtr() += collisionResult;
    mPoseKeeper->updatePoseTrans(mPoseKeeper->getTrans());
}

}  // namespace game
