#include "game/Player.h"
#include <cstdio>

#include "Library/Nerve/NerveSetupUtil.h"
#include "Library/Nerve/NerveUtil.h"
#include "Player/PlayerStateFallHakoniwa.h"
#include "game/PlayerColliderHakoniwa.h"

#include "Stuff.h"


namespace game {

namespace {

NERVE_IMPL(Player, Wait);
NERVE_IMPL(Player, Jump);
NERVE_IMPL(Player, Fall);

NERVE_MAKE(Player, Wait);
NERVE_MAKE(Player, Jump);
NERVE_MAKE(Player, Fall);

}  // namespace

Player::Player(const al::ByamlIter& data, const SceneInfo& info) : RaylibActor(data, info) {
    *mPoseKeeper->getTransPtr() += {0, 100.0f, 0};
    *mPoseKeeper->getVelocityPtr() = {0, -0.01f, 0};
    mActorDimensionKeeper = new ActorDimensionKeeper(this);
    mPlayerConst = new PlayerConst();
    mCollisionDirector = new al::CollisionDirector(nullptr);
    mCollisionDirector->setPartsKeeper(info.mPartsKeeper);
    mColliderHakoniwa = new PlayerColliderHakoniwa(this, mPlayerConst, mCollisionDirector);

    mPlayerInput = new PlayerInput(this, mColliderHakoniwa, this);
    // FIXME replace nullptrs with actual objects
    mStateFall = new PlayerStateFallHakoniwa(this, mPlayerConst, mColliderHakoniwa, mPlayerInput, nullptr, nullptr, this, nullptr);
    /*
    PlayerStateFallHakoniwa(al::LiveActor*, const PlayerConst*, const IUsePlayerCollision*,
                            const PlayerInput*, const PlayerTrigger*, const PlayerAreaChecker*,
                            const IUseDimension*, PlayerAnimator*);
    */

    al::initNerve(this, &Fall, 29);
    //al::initNerveState(this, mStateWait, &Wait, "待機");
    //al::initNerveState(this, mStateJump, &Jump, "ジャンプ");
    al::initNerveState(this, mStateFall, &Fall, "落下");
}

Player::~Player() {
    delete mColliderHakoniwa;
    delete mPlayerConst;
    delete mCollisionDirector;

    delete mNerveKeeper;
}

void Player::initAfterPlacement() {
    mPoseKeeper->getVelocityPtr()->y = -0.01f;
    updateCollider();
    *mPoseKeeper->getVelocityPtr() = {0, 0.0f, 0};
    if(mColliderHakoniwa->mPlayerCollider->val1 >= 0.0f) {  // rs::isCollidedGround
        al::setNerve(this, &Wait);
    } else {
        al::setNerve(this, &Fall);
    }


    // FIXME remove this
    al::setNerve(this, &Fall);
}

void Player::update() {
    RaylibActor::update();
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

void Player::exeFall() {
    al::updateNerveState(this);
    // TODO try cap return/spin attack
    // TODO try wall catch
    // TODO all sorts of judges

    /*
    if(rs::isLandGroundRunAngle(this, getCollider(), mPlayerConst)) {
        if(mStateFall->flag2 && al::isFirstStep(this))
            mTrigger->set(24);

        setNerveOnGround();

        if(al::isNerve(this, &Run) && !rs::isJustLand(mColliderHakoniwa)) {
            // more logic to preserve velocity
            CRASH
        }
    }
    */

    // TODO more random judges
    if(mStateFall->flag1 || mStateFall->mInvalidateInputFallArea)
        CRASH  // should disable input

    // TODO stuff about HackCap (probably 2P?)
    printf("During fall\n");
}
void Player::exeWait() {
    printf("During wait\n");
}
void Player::exeJump() {
    printf("During jump\n");
}

}  // namespace game
