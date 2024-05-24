#pragma once

#include "Player/PlayerConst.h"
#include "game/LiveActor.h"
#include "game/PlayerCollider.h"


namespace game {

class PlayerColliderHakoniwa {
public:
    PlayerColliderHakoniwa(LiveActor* actor, const PlayerConst* c, al::CollisionDirector* collisionDirector);
    ~PlayerColliderHakoniwa();

    sead::Vector3f updateCollider(const sead::Vector3f&);

public:
    LiveActor* mPlayer;
    const PlayerConst* mPlayerConst;
    PlayerCollider* mPlayerCollider;
    CollisionShapeKeeper* mShapeKeeperNormal;
};

}
