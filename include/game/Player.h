#pragma once

#include "game/LiveActor.h"

class PlayerConst;

namespace game {
class PlayerColliderHakoniwa;

class Player : public LiveActor {
public:
    Player(const al::ByamlIter& data, const SceneInfo& info);
    ~Player() override;

    void update() override;
private:
    PlayerColliderHakoniwa* mColliderHakoniwa;
    PlayerConst* mPlayerConst;
};

}
