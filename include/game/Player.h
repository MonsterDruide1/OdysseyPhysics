#pragma once

#include "Library/Collision/CollisionDirector.h"
#include "Player/PlayerInput.h"
#include "Player/PlayerTrigger.h"
#include "Util/ActorDimensionKeeper.h"
#include "Util/IUseDimension.h"
#include "game/RaylibActor.h"

class PlayerConst;
class PlayerStateJump;
class PlayerStateWait;
class PlayerStateFallHakoniwa;
class PlayerColliderHakoniwa;

namespace game {

class Player : public al::LiveActor, public IUseDimension {
public:
    Player(const al::ByamlIter& data, CollisionPartsKeeper* keeper);
    ~Player();

    ActorDimensionKeeper* getActorDimensionKeeper() const override {return mActorDimensionKeeper;}

    void initAfterPlacement() override;
    void updateCollider() override;

    void setNerveOnGround();


    void exeWait();
    void exeFall();
    void exeJump();
    void exeRun();
public:
    ActorDimensionKeeper* mActorDimensionKeeper;
    PlayerColliderHakoniwa* mColliderHakoniwa;
    PlayerConst* mPlayerConst;
    PlayerInput* mPlayerInput;
    PlayerTrigger* mTrigger;

    al::CollisionDirector* mCollisionDirector;

    PlayerStateJump* mStateJump;
    PlayerStateWait* mStateWait;
    PlayerStateFallHakoniwa* mStateFall;
};

}
