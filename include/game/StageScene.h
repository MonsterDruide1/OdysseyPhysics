#pragma once

#include "game/LiveActor.h"
#include "game/Player.h"
#include "game/Camera.h"
#include <cstdio>

namespace game {

class StageScene {
public:
    StageScene();
    ~StageScene();

    void init(const char* stageName, int scenario);

    void addObject(LiveActor* actor) {
        if (mActorsNum >= mActorsMax) {
            printf("Too many actors\n");
            return;
        }
        mActors[mActorsNum++] = actor;
    }

public:
    LiveActor** mActors;
    int mActorsNum = 0;
    int mActorsMax = 5120;
    Player* mPlayer;
    Camera* mCamera;
};

}
