
#include "Player/PlayerFunction.h"
#include "Player/PlayerInputFunction.h"
#include "raylib.h"

u32 PlayerFunction::getPlayerInputPort(const al::LiveActor*) {
    return -1;
}
sead::Vector2f PlayerInputFunction::getMoveInputStick(const al::LiveActor*, int, int) {
    sead::Vector2f input = {0, 0};
    if(IsKeyDown(KEY_W))
        input.y = 1;
    if(IsKeyDown(KEY_S))
        input.y = -1;
    if(IsKeyDown(KEY_A))
        input.x = -1;
    if(IsKeyDown(KEY_D))
        input.x = 1;
    return input;
}

sead::Matrix34f* PlayerFunction::getPlayerViewMtx(const al::LiveActor* actor) {
    //TODO
    return const_cast<sead::Matrix34f*>(&sead::Matrix34f::ident);
}
