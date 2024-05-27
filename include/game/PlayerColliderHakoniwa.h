#pragma once

#include "Player/IUsePlayerCollision.h"
#include "Player/PlayerConst.h"
#include "game/RaylibActor.h"
#include "game/PlayerCollider.h"


namespace game {

class PlayerColliderHakoniwa : public IUsePlayerCollision {
public:
    PlayerColliderHakoniwa(al::LiveActor* actor, const PlayerConst* c, al::CollisionDirector* collisionDirector);
    ~PlayerColliderHakoniwa();

    sead::Vector3f updateCollider(const sead::Vector3f&);
    
    virtual ::PlayerCollider* getPlayerCollider() const { return (::PlayerCollider*)mPlayerCollider; }

public:
    al::LiveActor* mPlayer;
    const PlayerConst* mPlayerConst;
    PlayerCollider* mPlayerCollider;
    CollisionShapeKeeper* mShapeKeeperNormal;
};

}
