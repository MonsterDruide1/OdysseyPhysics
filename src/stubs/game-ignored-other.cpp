
#include "Library/stuff.h"
#include "PlayerUtil.h"
#include "Util/PlayerCollisionUtil.h"

namespace rs {

// used too little to be worth implementing here (KinopioTent, Stand, Trampoline, Parasol and a few others)
bool isTouchJumpCode(al::LiveActor const*, IUsePlayerCollision const*) { return false; }

void addPlayerJumpCount(const al::LiveActor*) {}

bool isAutoRunOnGroundSkateCode(const al::LiveActor *, const IUsePlayerCollision *, float) { return false; }
bool isOnGroundSkateCode(al::LiveActor const*, IUsePlayerCollision const*) { return false; }
bool isOnGroundForceSlideCode(al::LiveActor const*, IUsePlayerCollision const*, PlayerConst const*) { return false; }
bool isOnGroundForceRollingCode(al::LiveActor const*, IUsePlayerCollision const*) { return false; }

}

PlayerSandSinkAffect::PlayerSandSinkAffect(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision*, PlayerEffect*) {}
bool PlayerSandSinkAffect::isSinkDeathHeight() { return false; }

PlayerJudgeSandSink::PlayerJudgeSandSink(IUsePlayerCollision const*, PlayerSandSinkAffect const*) {}
void PlayerJudgeSandSink::update() {}
void PlayerJudgeSandSink::reset() {}
bool PlayerJudgeSandSink::judge() const { return false; }

void alPadRumbleFunction::startPadRumbleLoopNo3D(al::LiveActor const*, char const*, sead::Vector3<float> const*, int) {}
void alPadRumbleFunction::stopPadRumbleLoop(al::LiveActor const*, char const*, sead::Vector3<float> const*, int) {}

PlayerJudgePoleClimb::PlayerJudgePoleClimb(al::LiveActor const*,PlayerConst const*,IUsePlayerCollision const*,IPlayerModelChanger const*,PlayerCarryKeeper const*,PlayerExternalVelocity const*,PlayerInput const*,PlayerTrigger const*) {}
void PlayerJudgePoleClimb::update() {}
void PlayerJudgePoleClimb::reset() {}
bool PlayerJudgePoleClimb::judge() const { return false; }

PlayerJudgeStatusPoleClimb::PlayerJudgeStatusPoleClimb(IJudge const*, PlayerStatePoleClimb const*) {}
void PlayerJudgeStatusPoleClimb::update() {}
void PlayerJudgeStatusPoleClimb::reset() {}
bool PlayerJudgeStatusPoleClimb::judge() const { return false; }

PlayerStateGrabCeil::PlayerStateGrabCeil(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerModelHolder const*, PlayerTrigger*, IUsePlayerCollision*, PlayerAnimator*, PlayerJudgePreInputJump*, al::HitSensor*, PlayerJointParamGrab*) : al::NerveStateBase("") {}
PlayerStatePoleClimb::PlayerStatePoleClimb(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerTrigger const*, PlayerModelHolder*, IUsePlayerCollision*, PlayerAnimator*, PlayerWallActionHistory*, PlayerJointParamHandLegAngle*, PlayerJudgePreInputJump*, PlayerActionDiveInWater*) : al::NerveStateBase("") {}
PlayerStateSandSink::PlayerStateSandSink(al::LiveActor*, PlayerConst const*, PlayerInput const*, PlayerTrigger const*, IUsePlayerCollision*, PlayerAnimator*, IJudge*, PlayerJudgePreInputJump*) : al::NerveStateBase("") {}
ActorStateSandGeyser::ActorStateSandGeyser(al::LiveActor* act) : al::ActorStateBase("砂の間欠泉", act) {}

void PlayerStatePoleClimb::setup(al::CollisionParts const*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float, char const*) {}
void PlayerStateGrabCeil::setup(al::CollisionParts const*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&) {}
bool PlayerStateGrabCeil::isEnableNextGrabCeil() { return false; }
