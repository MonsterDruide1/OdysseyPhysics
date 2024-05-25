#pragma once

#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/LiveActor.h"
#include "Library/Yaml/ByamlIter.h"
#include "game/SceneInfo.h"
#include "raylib.h"

namespace game {

extern Shader checkerShader;
extern Mesh cubeMesh;

class LiveActor : public al::LiveActor {
public:
    LiveActor(const al::ByamlIter& data, const SceneInfo& info);
    virtual ~LiveActor();

    void initRaylibModel(const char* modelName, const al::ByamlIter& data);
    void initFallbackModel();

    virtual void initAfterPlacement() {}
    virtual void update() {}

    static LiveActor* create(const al::ByamlIter& data, const SceneInfo& info);

public:
    const SceneInfo& mInfo;
    al::CollisionParts* mCollisionParts = nullptr;

    u8* kclData = nullptr;
    u8* collisionByml = nullptr;

    ::Model raylibModel;
};

}
