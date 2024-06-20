
#include "Player/PlayerFunction.h"
#include "Player/PlayerInput.h"
#include "Player/PlayerInputFunction.h"
#include "game/Input.h"
#include "raylib.h"

u32 PlayerFunction::getPlayerInputPort(const al::LiveActor*) {
    return -1;
}
sead::Vector2f PlayerInputFunction::getMoveInputStick(const al::LiveActor*, int, int) {
    return Input::instance()->getStickLeft();
}

sead::Matrix34f* PlayerFunction::getPlayerViewMtx(const al::LiveActor* actor) {
    //TODO
    WARN_UNIMPL;
    return const_cast<sead::Matrix34f*>(&sead::Matrix34f::ident);
}

bool PlayerInput::isHoldSquat() const {
    if(mIsDisableInput) return false;
    // stuff about 2d, ignored here
    return PlayerInputFunction::isHoldSubAction(mLiveActor, PlayerFunction::getPlayerInputPort(mLiveActor));
}
