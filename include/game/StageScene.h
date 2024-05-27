#pragma once

#include "game/RaylibActor.h"
#include "game/Player.h"
#include "game/Camera.h"
#include <cstdio>

namespace game {

class StageScene {
public:
    StageScene();
    ~StageScene();

    void init(const char* stageName, int scenario);

    void addObject(RaylibActor* actor) {
        if (mActorsNum >= mActorsMax) {
            printf("Too many actors\n");
            return;
        }
        mActors[mActorsNum++] = actor;
    }

public:
    RaylibActor** mActors;
    int mActorsNum = 0;
    int mActorsMax = 5120;
    RaylibActor* mPlayer;
    Camera* mCamera;
    CollisionPartsKeeper* mPartsKeeper;
};

}
