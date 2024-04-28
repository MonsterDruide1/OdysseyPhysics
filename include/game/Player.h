#pragma once

#include "game/LiveActor.h"

namespace game {

class Player : public LiveActor {
public:
    Player(const al::ByamlIter& data) : LiveActor(data) {}
};

}
