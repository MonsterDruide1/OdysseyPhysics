#include "Player/CapTargetInfo.h"
#include "Player/PlayerConst.h"
#include "Player/PlayerInput.h"
#include "PlayerUtil.h"
#include "System/GameDataFunction.h"
#include "Util/ScenePlayerCapFunction.h"

namespace rs {


CapTargetInfo* createCapTargetInfo(al::LiveActor*, char const*) {}
void requestLockOnCapHitReaction(al::LiveActor const*, CapTargetInfo const*, char const*) {}
bool tryGetFlyingCapPos(sead::Vector3<float>*, al::LiveActor const*) {return false;}
bool tryReceiveMsgInitCapTargetAndSetCapTargetInfo(al::SensorMsg const*, CapTargetInfo const*) {return false;}
bool tryShowCapMsgCollectCoinGetFirst(al::IUseSceneObjHolder const*) {return false;}

}

bool PlayerCapFunction::isEnableBirdLandPlayerCapOn(al::LiveActor const*) {CRASH}

void CapTargetInfo::setFollowLockOnMtx(char const*, sead::Vector3<float> const&, sead::Vector3<float> const&) {CRASH}

HackCap::HackCap(al::LiveActor const*, char const*, PlayerInput const*, PlayerAreaChecker const*,
                 PlayerWallActionHistory const*, PlayerCapActionHistory const*,
                 PlayerEyeSensorHitHolder const*, PlayerSeparateCapFlag const*,
                 IUsePlayerCollision const*, IUsePlayerHeightCheck const*, PlayerWetControl const*,
                 PlayerJointControlKeeper const*, HackCapJudgePreInputSeparateThrow*,
                 HackCapJudgePreInputSeparateJump*)
    : al::LiveActor("") {}

void HackCap::updateSeparateMode(PlayerSeparateCapFlag const*) {}

bool HackCap::isNoPutOnHide() {
    return false;
}

bool HackCap::isEnableSpinAttack() {
    return true;
}

bool HackCap::requestReturn(bool*) {
    return false;
}

bool HackCap::isRequestableReturn() const {
    return false;
}

bool HackCap::isEnablePreInput() const {
    return false;
}

void HackCap::startCatch(char const*, bool, sead::Vector3<float> const&) {}

void HackCap::prepareCooperateThrow() {}

bool HackCap::isEnableThrowSeparate() const {
    return true;
}

void HackCap::startThrowSeparatePlayJump(sead::Vector3<float> const&, sead::Vector3<float> const&,
                                         float) {}

void HackCap::startThrowSeparatePlay(sead::Vector3<float> const&, sead::Vector3<float> const&,
                                     float, bool) {}

f32 HackCap::calcSeparateHideSpeedH(sead::Vector3<float> const&) {
    return 0.0f;
}

void HackCap::startSpinAttack(const sead::SafeString&) {}

bool HackCap::cancelCapState() {
    return false;
}

bool HackCap::isSpinAttack() {
    return false;
}

void HackCap::startThrow(bool, sead::Vector3<float> const&, sead::Vector3<float> const&, float,
                         sead::Vector2<float> const&, sead::Vector2<float> const&,
                         sead::Vector3<float> const&, bool, sead::Vector3<float> const&,
                         HackCap::SwingHandType, bool, float, int) {}

void HackCap::attackSpin(al::HitSensor*, al::HitSensor*, float) {}

bool PlayerInput::isHoldCapSeparateJump() const {
    return false;
}

PlayerSeparateCapFlag::PlayerSeparateCapFlag() {}

void CapFunction::putOnCapPlayer(HackCap*, PlayerAnimator*) {}

PlayerJudgeCapCatch::PlayerJudgeCapCatch(al::LiveActor const*, PlayerCounterAfterCapCatch const*) {}

void PlayerJudgeCapCatch::reset() {}

void PlayerJudgeCapCatch::update() {}

bool PlayerJudgeCapCatch::judge() const {
    return false;
}

PlayerJudgeCapCatchPop::PlayerJudgeCapCatchPop(al::LiveActor const*, PlayerInput const*,
                                               IUsePlayerCollision const*,
                                               IPlayerModelChanger const*,
                                               PlayerCapActionHistory const*,
                                               PlayerCounterAfterCapCatch const*) {}

void PlayerJudgeCapCatchPop::reset() {}

void PlayerJudgeCapCatchPop::update() {}

bool PlayerJudgeCapCatchPop::judge() const {
    return false;
}

HackCapJudgePreInputHoveringJump::HackCapJudgePreInputHoveringJump(al::LiveActor const*,
                                                                   IUsePlayerCollision const*,
                                                                   HackCap const*,
                                                                   PlayerInput const*) {}

void HackCapJudgePreInputHoveringJump::reset() {}

void HackCapJudgePreInputHoveringJump::update() {}

bool HackCapJudgePreInputHoveringJump::judge() const {
    return false;
}

HackCapJudgeHoldHoveringJump::HackCapJudgeHoldHoveringJump(al::LiveActor const*,
                                                           PlayerColliderHakoniwa const*,
                                                           HackCap const*, PlayerInput const*,
                                                           PlayerConst const*) {}

void HackCapJudgeHoldHoveringJump::reset() {}

void HackCapJudgeHoldHoveringJump::update() {}

bool HackCapJudgeHoldHoveringJump::judge() const {
    return false;
}

HackCapJudgePreInputSeparateThrow::HackCapJudgePreInputSeparateThrow(PlayerInput const*,
                                                                     PlayerSeparateCapFlag const*) {

}

void HackCapJudgePreInputSeparateThrow::reset() {}

void HackCapJudgePreInputSeparateThrow::update() {}

bool HackCapJudgePreInputSeparateThrow::judge() const {
    return false;
}

PlayerStateCapCatchPop::PlayerStateCapCatchPop(al::LiveActor*, PlayerConst const*,
                                               IUsePlayerCollision const*, PlayerInput const*,
                                               PlayerAnimator*, HackCap*)
    : al::NerveStateBase("") {}
