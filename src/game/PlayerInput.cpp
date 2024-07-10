
#include "Player/PlayerInput.h"
#include "Library/Controller/SpinInputAnalyzer.h"
#include "Library/Math/MathAngleUtil.h"
#include "Player/PlayerActorBase.h"
#include "Player/PlayerFunction.h"
#include "Player/PlayerInputFunction.h"
#include "game/Input.h"
#include "raylib.h"

u32 PlayerFunction::getPlayerInputPort(const al::LiveActor*) {
    return -1;
}
sead::Vector2f PlayerInputFunction::getMoveInputStick(const al::LiveActor*, int, int) {
    return Input::instance()->getStickLeft();
}

const sead::Matrix34f* PlayerFunction::getPlayerViewMtx(const al::LiveActor* actor) {
    return ((PlayerActorBase*)actor)->getViewMtx();
}

bool PlayerInput::isHoldSquat() const {
    if (mIsDisableInput)
        return false;
    // stuff about 2d, ignored here
    return PlayerInputFunction::isHoldSubAction(mLiveActor,
                                                PlayerFunction::getPlayerInputPort(mLiveActor));
}

bool PlayerInput::isThrowTypeLeftRight(const sead::Vector2f& vec) const {
    return !al::isNearZero(vec, 0.001f);
}

bool PlayerInput::isSpinInput() const {
    return mSpinInputAnalyzer->mSpinDirection != 0;
}
