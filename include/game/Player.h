#pragma once

#include "Library/Collision/CollisionDirector.h"
#include "game/LiveActor.h"

class PlayerConst;

namespace game {
class PlayerColliderHakoniwa;

class Player : public LiveActor {
public:
    Player(const al::ByamlIter& data, const SceneInfo& info);
    ~Player() override;

    void update() override;
public:
    PlayerColliderHakoniwa* mColliderHakoniwa;
    PlayerConst* mPlayerConst;

    al::CollisionDirector* mCollisionDirector;
};

}
