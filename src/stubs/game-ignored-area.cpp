#include "Library/Area/AreaObjDirector.h"
#include "Library/Area/AreaObjUtil.h"
#include "MapObj/RouteGuideDirector.h"
#include "Player/PlayerJudgeInvalidateInputFall.h"
#include "PlayerUtil.h"
#include "Stuff.h"
#include "Util/AreaUtil.h"

void rs::onRouteGuideSystem(al::IUseSceneObjHolder const*) {}

bool rs::isInLowGravityArea(al::LiveActor const*) {
    return false;
}

bool rs::tryFindSnapMoveAreaDir(sead::Vector3<float>*, al::LiveActor const*,
                                IUsePlayerCollision const*) {
    return false;
}

void rs::calcSnapVelocitySnapMoveAreaWithCutDir(sead::Vector3<float>* result, al::LiveActor const*,
                                                IUsePlayerCollision const*,
                                                sead::Vector3<float> const& vel, float,
                                                sead::Vector3<float> const&) {
    *result = vel;
}

void rs::calcSnapVelocitySnapMoveArea(sead::Vector3<float>* result, al::LiveActor const*,
                                      IUsePlayerCollision const*, sead::Vector3<float> const& vel,
                                      float) {
    *result = vel;
}

bool rs::tryFindForceRecoveryArea(sead::Vector3<float>*, sead::Vector3<float>*, al::AreaObj const**, al::IUseAreaObj const*, sead::Vector3<float> const&) {
    return false;
}

PlayerJudgePlaySwitchOnAreaWaitAnim::PlayerJudgePlaySwitchOnAreaWaitAnim(PlayerStateWait const*) {}

void PlayerJudgePlaySwitchOnAreaWaitAnim::reset() {}

void PlayerJudgePlaySwitchOnAreaWaitAnim::update() {}

bool PlayerJudgePlaySwitchOnAreaWaitAnim::judge() const {
    return false;
}

PlayerStateRise::PlayerStateRise(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*,
                                 PlayerInput const*, PlayerAnimator*)
    : al::NerveStateBase("") {}
