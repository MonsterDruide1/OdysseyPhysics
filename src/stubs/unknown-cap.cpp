#include "Player/PlayerConst.h"
#include "Player/PlayerInput.h"
#include "PlayerUtil.h"
#include "System/GameDataFunction.h"

PlayerCapActionHistory::PlayerCapActionHistory(al::LiveActor const*, PlayerConst const*, PlayerTrigger const*, IUsePlayerCollision const*) { WARN_UNIMPL; }
void PlayerCapActionHistory::clearLandLimitStandAngle() { WARN_UNIMPL; }
void PlayerCapActionHistory::update() { WARN_UNIMPL; }

HackCap::HackCap(al::LiveActor const*, char const*, PlayerInput const*, PlayerAreaChecker const*, PlayerWallActionHistory const*, PlayerCapActionHistory const*, PlayerEyeSensorHitHolder const*, PlayerSeparateCapFlag const*, IUsePlayerCollision const*, IUsePlayerHeightCheck const*, PlayerWetControl const*, PlayerJointControlKeeper const*, HackCapJudgePreInputSeparateThrow*, HackCapJudgePreInputSeparateJump*) : al::LiveActor("") { WARN_UNIMPL; }
void HackCap::updateSeparateMode(PlayerSeparateCapFlag const*) { WARN_UNIMPL; }
bool HackCap::sendMsgStartHack(al::HitSensor*) { WARN_UNIMPL;return false; }
bool HackCap::isNoPutOnHide() { WARN_UNIMPL;return false; }
bool HackCap::isEnableSpinAttack() { WARN_UNIMPL;return false; }
bool HackCap::requestReturn(bool*) { WARN_UNIMPL;return false; }
bool HackCap::isRequestableReturn() { WARN_UNIMPL;return false; }
void HackCap::startCatch(char const*, bool, sead::Vector3<float> const&) { WARN_UNIMPL; }

bool PlayerInput::isHoldCapSeparateJump() const { WARN_UNIMPL;return false; }

PlayerSeparateCapFlag::PlayerSeparateCapFlag() { WARN_UNIMPL; }

void CapFunction::putOnCapPlayer(HackCap*, PlayerAnimator*) { WARN_UNIMPL; }

bool GameDataFunction::isEnableCap(GameDataHolderAccessor) { WARN_UNIMPL;return true; }

PlayerJudgePreInputCapThrow::PlayerJudgePreInputCapThrow(PlayerConst const*,PlayerInput const*,PlayerCarryKeeper const*,HackCap const*) {WARN_UNIMPL;}
void PlayerJudgePreInputCapThrow::reset() {WARN_UNIMPL;}
void PlayerJudgePreInputCapThrow::update() {WARN_UNIMPL;}
bool PlayerJudgePreInputCapThrow::judge() const {WARN_UNIMPL;return false;}

bool PlayerActorHakoniwa::tryActionSeparateCapThrow() { WARN_UNIMPL;return false; }
