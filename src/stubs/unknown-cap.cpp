#include "Player/PlayerConst.h"
#include "Player/PlayerInput.h"
#include "PlayerUtil.h"
#include "System/GameDataFunction.h"

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

PlayerJudgeCapCatch::PlayerJudgeCapCatch(al::LiveActor const*, PlayerCounterAfterCapCatch const*) {WARN_UNIMPL; }
void PlayerJudgeCapCatch::reset() {WARN_UNIMPL;}
void PlayerJudgeCapCatch::update() {WARN_UNIMPL;}
bool PlayerJudgeCapCatch::judge() const {WARN_UNIMPL;return false;}

PlayerJudgeCapCatchPop::PlayerJudgeCapCatchPop(al::LiveActor const*, PlayerInput const*, IUsePlayerCollision const*, IPlayerModelChanger const*, PlayerCapActionHistory const*, PlayerCounterAfterCapCatch const*) {WARN_UNIMPL; }
void PlayerJudgeCapCatchPop::reset() {WARN_UNIMPL;}
void PlayerJudgeCapCatchPop::update() {WARN_UNIMPL;}
bool PlayerJudgeCapCatchPop::judge() const {WARN_UNIMPL;return false;}

HackCapJudgePreInputHoveringJump::HackCapJudgePreInputHoveringJump(al::LiveActor const*, IUsePlayerCollision const*, HackCap const*, PlayerInput const*) {WARN_UNIMPL; }
void HackCapJudgePreInputHoveringJump::reset() {WARN_UNIMPL;}
void HackCapJudgePreInputHoveringJump::update() {WARN_UNIMPL;}
bool HackCapJudgePreInputHoveringJump::judge() const {WARN_UNIMPL;return false;}

HackCapJudgeHoldHoveringJump::HackCapJudgeHoldHoveringJump(al::LiveActor const*, PlayerColliderHakoniwa const*, HackCap const*, PlayerInput const*, PlayerConst const*) {WARN_UNIMPL; }
void HackCapJudgeHoldHoveringJump::reset() {WARN_UNIMPL;}
void HackCapJudgeHoldHoveringJump::update() {WARN_UNIMPL;}
bool HackCapJudgeHoldHoveringJump::judge() const {WARN_UNIMPL;return false;}

HackCapJudgePreInputSeparateThrow::HackCapJudgePreInputSeparateThrow(PlayerInput const*, PlayerSeparateCapFlag const*) {WARN_UNIMPL; }
void HackCapJudgePreInputSeparateThrow::reset() {WARN_UNIMPL;}
void HackCapJudgePreInputSeparateThrow::update() {WARN_UNIMPL;}
bool HackCapJudgePreInputSeparateThrow::judge() const {WARN_UNIMPL;return false;}

PlayerStateCapCatchPop::PlayerStateCapCatchPop(al::LiveActor*, PlayerConst const*, IUsePlayerCollision const*, PlayerInput const*, PlayerAnimator*, HackCap*) : al::NerveStateBase("") { WARN_UNIMPL; }
