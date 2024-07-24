#include "Library/Nerve/NerveStateBase.h"
#include "PlayerUtil.h"

PlayerStateWallCatch::PlayerStateWallCatch(al::LiveActor*, PlayerConst const*, PlayerInput const*,
                                           IUsePlayerCollision*, IUsePlayerCeilingCheck const*,
                                           PlayerModelHolder const*, PlayerAreaChecker const*,
                                           PlayerAnimator*, PlayerTrigger*,
                                           PlayerJudgePreInputJump*, PlayerJointParamGrab*)
    : al::NerveStateBase("") {
    WARN_UNIMPL;
}

bool PlayerStateWallCatch::isWallCatchForm() {
    WARN_UNIMPL;
    return false;
}

void PlayerStateWallCatch::setup(al::CollisionParts const*, sead::Vector3<float> const&,
                                 sead::Vector3<float> const&, sead::Vector3<float> const&) {
    WARN_UNIMPL;
}

const sead::Vector3f& PlayerStateWallCatch::getCeilingCheckPos() {
    WARN_UNIMPL;
    return sead::Vector3f::zero;
}

const sead::Vector3f& PlayerStateWallCatch::getWallCatchFront() const {
    WARN_UNIMPL;
    return sead::Vector3f::zero;
}
