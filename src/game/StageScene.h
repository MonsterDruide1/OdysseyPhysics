#pragma once

#include <cstdio>
#include "game/Camera.h"
#include "game/RaylibActor.h"

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

    void update() {
        for (int i = 0; i < mActorsNum; i++) {
            auto actor = mActors[i];
            if (!actor)
                continue;
            actor->update();
        }
        mPlayer->update();
    }

public:
    RaylibActor** mActors;
    int mActorsNum = 0;
    int mActorsMax = 5120;
    RaylibActor* mPlayer;
    Camera* mCamera;
    CollisionPartsKeeper* mPartsKeeper;
    sead::Vector3f* mShinePositions;
    int mShinesNum = 0;
    int mShinesMax = 200;
};

}  // namespace game
