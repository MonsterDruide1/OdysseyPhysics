#pragma once

#include "Library/LiveActor/LiveActor.h"
#include "Library/Yaml/ByamlIter.h"
#include "raylib.h"

namespace game {

class RaylibActor {
public:
    RaylibActor(al::LiveActor*);
    virtual ~RaylibActor();

    void initRaylibModel();
    void initFallbackModel();

    virtual void initAfterPlacement() { mActor->initAfterPlacement(); }

    virtual void update() { mActor->movement(); }

    static void apply(al::LiveActor*, const al::ByamlIter& data);

public:
    al::LiveActor* mActor;

    u8* kclData = nullptr;
    u8* collisionByml = nullptr;

    ::Model raylibModel;
};

}  // namespace game
