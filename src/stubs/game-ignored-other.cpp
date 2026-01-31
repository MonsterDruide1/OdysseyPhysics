
#include "Library/stuff.h"
#include "PlayerUtil.h"
#include "Player/PlayerSandSinkAffect.h"
#include "Util/PlayerCollisionUtil.h"

namespace rs {

// used too little to be worth implementing here (KinopioTent, Stand, Trampoline, Parasol and a few
// others)
bool isTouchJumpCode(al::LiveActor const*, IUsePlayerCollision const*) {
    return false;
}

void addPlayerJumpCount(const al::LiveActor*) {}

bool isAutoRunOnGroundSkateCode(const al::LiveActor*, const IUsePlayerCollision*, float) {
    return false;
}

bool isOnGroundSkateCode(al::LiveActor const*, IUsePlayerCollision const*) {
    return false;
}

bool isOnGroundForceSlideCode(al::LiveActor const*, IUsePlayerCollision const*,
                              PlayerConst const*) {
    return false;
}

bool isOnGroundForceRollingCode(al::LiveActor const*, IUsePlayerCollision const*) {
    return false;
}

bool isCollisionCodeSandSink(IUsePlayerCollision const*) {
    return false;
}

}  // namespace rs

PlayerSandSinkAffect::PlayerSandSinkAffect(al::LiveActor const*, PlayerConst const*,
                                           PlayerInput const*, IUsePlayerCollision*,
                                           PlayerEffect*) {}

bool PlayerSandSinkAffect::isSinkDeathHeight() const {
    return false;
}

bool PlayerSandSinkAffect::isSink() const {
    return false;
}

bool PlayerSandSinkAffect::isEnableCapThrow() const {
    return false;
}

PlayerJudgePoleClimb::PlayerJudgePoleClimb(al::LiveActor const*, PlayerConst const*,
                                           IUsePlayerCollision const*, IPlayerModelChanger const*,
                                           PlayerCarryKeeper const*, PlayerExternalVelocity const*,
                                           PlayerInput const*, PlayerTrigger const*) {}

void PlayerJudgePoleClimb::update() {}

void PlayerJudgePoleClimb::reset() {}

bool PlayerJudgePoleClimb::judge() const {
    return false;
}

PlayerJudgeStatusPoleClimb::PlayerJudgeStatusPoleClimb(IJudge const*, PlayerStatePoleClimb const*) {
}

void PlayerJudgeStatusPoleClimb::update() {}

void PlayerJudgeStatusPoleClimb::reset() {}

bool PlayerJudgeStatusPoleClimb::judge() const {
    return false;
}

PlayerStateGrabCeil::PlayerStateGrabCeil(al::LiveActor*, PlayerConst const*, PlayerInput const*,
                                         PlayerModelHolder const*, PlayerTrigger*,
                                         IUsePlayerCollision*, PlayerAnimator*,
                                         PlayerJudgePreInputJump*, al::HitSensor*,
                                         PlayerJointParamGrab*)
    : al::NerveStateBase("") {}

PlayerStatePoleClimb::PlayerStatePoleClimb(al::LiveActor*, PlayerConst const*, PlayerInput const*,
                                           PlayerTrigger const*, PlayerModelHolder*,
                                           IUsePlayerCollision*, PlayerAnimator*,
                                           PlayerWallActionHistory*, PlayerJointParamHandLegAngle*,
                                           PlayerJudgePreInputJump*, PlayerActionDiveInWater*)
    : al::NerveStateBase("") {}

PlayerStateSandSink::PlayerStateSandSink(al::LiveActor*, PlayerConst const*, PlayerInput const*,
                                         PlayerTrigger const*, IUsePlayerCollision*,
                                         PlayerAnimator*, IJudge*, PlayerJudgePreInputJump*)
    : al::NerveStateBase("") {}

ActorStateSandGeyser::ActorStateSandGeyser(al::LiveActor* act)
    : al::ActorStateBase("砂の間欠泉", act) {}

void PlayerStatePoleClimb::setup(al::CollisionParts const*, sead::Vector3<float> const&,
                                 sead::Vector3<float> const&, sead::Vector3<float> const&, float,
                                 float, char const*) {}

void PlayerStateGrabCeil::setup(al::CollisionParts const*, sead::Vector3<float> const&,
                                sead::Vector3<float> const&, sead::Vector3<float> const&) {}

bool PlayerStateGrabCeil::isEnableNextGrabCeil() {
    return false;
}
