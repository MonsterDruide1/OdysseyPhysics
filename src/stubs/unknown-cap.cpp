#include "Player/PlayerConst.h"
#include "Player/PlayerInput.h"
#include "PlayerUtil.h"
#include "System/GameDataFunction.h"

PlayerCapActionHistory::PlayerCapActionHistory(al::LiveActor const*, PlayerConst const*, PlayerTrigger const*, IUsePlayerCollision const*) { WARN_UNIMPL; }
void PlayerCapActionHistory::clearLandLimitStandAngle() { WARN_UNIMPL; }
void PlayerCapActionHistory::update() { WARN_UNIMPL; }

HackCap::HackCap(al::LiveActor const*, char const*, PlayerInput const*, PlayerAreaChecker const*, PlayerWallActionHistory const*, PlayerCapActionHistory const*, PlayerEyeSensorHitHolder const*, PlayerSeparateCapFlag const*, IUsePlayerCollision const*, IUsePlayerHeightCheck const*, PlayerWetControl const*, PlayerJointControlKeeper const*, HackCapJudgePreInputSeparateThrow*, HackCapJudgePreInputSeparateJump*) : al::LiveActor("") { WARN_UNIMPL; }
void HackCap::updateSeparateMode(PlayerSeparateCapFlag const*) { WARN_UNIMPL; }
bool HackCap::isNoPutOnHide() { WARN_UNIMPL;return false; }
bool HackCap::isEnableSpinAttack() { WARN_UNIMPL;return true; }
bool HackCap::requestReturn(bool*) { WARN_UNIMPL;return false; }
bool HackCap::isRequestableReturn() const { WARN_UNIMPL;return false; }
bool HackCap::isEnablePreInput() const { WARN_UNIMPL;return false; }
void HackCap::startCatch(char const*, bool, sead::Vector3<float> const&) { WARN_UNIMPL; }
void HackCap::prepareCooperateThrow() { WARN_UNIMPL; }
bool HackCap::isEnableThrowSeparate() const { WARN_UNIMPL; return true; }
void HackCap::startThrowSeparatePlayJump(sead::Vector3<float> const&, sead::Vector3<float> const&, float) { WARN_UNIMPL; }
void HackCap::startThrowSeparatePlay(sead::Vector3<float> const&, sead::Vector3<float> const&, float, bool) { WARN_UNIMPL; }
f32 HackCap::calcSeparateHideSpeedH(sead::Vector3<float> const&) { WARN_UNIMPL;return 0.0f; }
void HackCap::startSpinAttack(const sead::SafeString&) { WARN_UNIMPL; }
bool HackCap::cancelCapState() { WARN_UNIMPL; return false; }
bool HackCap::isSpinAttack() { WARN_UNIMPL; return false; }
void HackCap::startThrow(bool,sead::Vector3<float> const&,sead::Vector3<float> const&,float,sead::Vector2<float> const&,sead::Vector2<float> const&,sead::Vector3<float> const&,bool,sead::Vector3<float> const&,HackCap::SwingHandType,bool,float,int) { WARN_UNIMPL; }
void HackCap::attackSpin(al::HitSensor *,al::HitSensor *,float) { WARN_UNIMPL; }

bool PlayerInput::isHoldCapSeparateJump() const { WARN_UNIMPL;return false; }

PlayerSeparateCapFlag::PlayerSeparateCapFlag() { WARN_UNIMPL; }

void CapFunction::putOnCapPlayer(HackCap*, PlayerAnimator*) { WARN_UNIMPL; }
