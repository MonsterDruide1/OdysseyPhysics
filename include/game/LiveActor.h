#pragma once

#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/Yaml/ByamlIter.h"
#include "game/SceneInfo.h"
#include "raylib.h"

namespace game {

extern Shader checkerShader;
extern Mesh cubeMesh;

class LiveActor {
public:
    LiveActor(const al::ByamlIter& data, const SceneInfo& info);
    virtual ~LiveActor();

    void initRaylibModel(const char* modelName, const al::ByamlIter& data);
    void initFallbackModel();

    virtual void initAfterPlacement() {}
    virtual void update() {}

public:
    al::ActorPoseKeeperBase* mPoseKeeper;
    const char* mName;
    const SceneInfo& mInfo;
    al::CollisionParts* mCollisionParts = nullptr;

    void* kclData = nullptr;
    void* collisionByml = nullptr;

    ::Model raylibModel;
};

}
