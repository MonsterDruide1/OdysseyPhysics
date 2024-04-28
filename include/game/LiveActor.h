#pragma once

#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/Yaml/ByamlIter.h"
#include "raylib.h"

namespace game {

extern Shader checkerShader;
extern Mesh cubeMesh;

class LiveActor {
public:
    LiveActor(const al::ByamlIter& data);
    ~LiveActor();

    void initRaylibModel(const char* modelName);
    void initFallbackModel();

public:
    al::ActorPoseKeeperBase* mPoseKeeper;
    const char* mName;

    ::Model raylibModel;
};

}
