#include "Player/HackCap.h"

HackCap::HackCap(const al::LiveActor*, const char*, const PlayerInput*, const PlayerAreaChecker*,
        const PlayerWallActionHistory*, const PlayerCapActionHistory*,
        const PlayerEyeSensorHitHolder*, const PlayerSeparateCapFlag*, const IUsePlayerCollision*,
        const IUsePlayerHeightCheck*, const PlayerWetControl*, const PlayerJointControlKeeper*,
        HackCapJudgePreInputSeparateThrow*, HackCapJudgePreInputSeparateJump*) : al::LiveActor("") { WARN_UNIMPL; }

void HackCap::init(const al::ActorInitInfo&) { WARN_UNIMPL; }
void HackCap::hide(bool) { CRASH }
void HackCap::movement() { CRASH }
void HackCap::updateShadowMaskOffset() { CRASH }
void HackCap::control() { CRASH }
bool HackCap::isFlying() const { CRASH }
void HackCap::updateTargetLayout() { CRASH }
void HackCap::updateCollider() { CRASH }
void HackCap::updateFrameOutLayout() { CRASH }
void HackCap::attackSpin(al::HitSensor*, al::HitSensor*, f32) { CRASH }
void HackCap::prepareLockOn(al::HitSensor*) { CRASH }
bool HackCap::sendMsgStartHack(al::HitSensor*) { WARN_UNIMPL;return false; }
bool HackCap::receiveRequestTransferHack(al::HitSensor*, al::HitSensor*) { CRASH }
void HackCap::startThrowSeparatePlayHack(al::HitSensor*, const sead::Vector3f&, const sead::Vector3f&, f32) { CRASH }
void HackCap::startHack() { CRASH }
void HackCap::emitHackStartEffect() { CRASH }
void HackCap::noticeHackMarioEnter() { CRASH }
void HackCap::noticeHackDemoPuppetableEnd() { CRASH }
void HackCap::recordHack() { CRASH }
void HackCap::addHackStartDemo() { CRASH }
void HackCap::addLockOnKeepDemo() { CRASH }
void HackCap::syncHackDamageVisibility(bool) { CRASH }
void HackCap::endHack() { CRASH }
void HackCap::startSpinAttack(const char*) { CRASH }
void HackCap::startThrow(bool, const sead::Vector3f&, const sead::Vector3f&, f32, const sead::Vector2f&,
                const sead::Vector2f&, const sead::Vector3f&, bool, const sead::Vector3f&,
                SwingHandType, bool, f32, s32) { CRASH }
void HackCap::startThrowSeparatePlay(const sead::Vector3f&, const sead::Vector3f&, f32, bool) { CRASH }
void HackCap::startThrowSeparatePlayJump(const sead::Vector3f&, const sead::Vector3f&, f32) { CRASH }
void HackCap::startCatch(const char*, bool, const sead::Vector3f&) { CRASH }
bool HackCap::isNoPutOnHide() const { WARN_UNIMPL;return false; }
void HackCap::forcePutOn() { CRASH }
void HackCap::forceHack(al::HitSensor*, const CapTargetInfo*) { CRASH }
void HackCap::resetLockOnParam() { CRASH }
void HackCap::setupStartLockOn() { CRASH }
bool HackCap::cancelCapState() { CRASH }
bool HackCap::isEnableThrow() const { CRASH }
bool HackCap::isEnableSpinAttack() const { WARN_UNIMPL;return false; }
bool HackCap::isSpinAttack() const { CRASH }
bool HackCap::requestReturn(bool*) { CRASH }
bool HackCap::tryReturn(bool, bool*) { CRASH }
void HackCap::updateCapPose() { CRASH }
void HackCap::followTarget() { CRASH }
void HackCap::syncPuppetSilhouette() { CRASH }
void HackCap::recordCapJump(PlayerWallActionHistory*) { CRASH }
f32 HackCap::getFlyingSpeedMax() const { CRASH }
f32 HackCap::getThrowSpeed() const { CRASH }
bool HackCap::requestLockOnHitReaction(const CapTargetInfo*, const char*) { CRASH }
void HackCap::startPuppet() { CRASH }
void HackCap::endPuppet() { CRASH }
void HackCap::hidePuppetCap() { CRASH }
void HackCap::showPuppetCap() { CRASH }
void HackCap::hidePuppetCapSilhouette() { CRASH }
void HackCap::showPuppetCapSilhouette() { CRASH }
void HackCap::startPuppetCheckpointWarp() { CRASH }
void HackCap::startHackShineGetDemo() { CRASH }
void HackCap::endHackThrowAndReturnHack() { CRASH }
void HackCap::endHackShineGetDemo() { CRASH }
void HackCap::calcHackFollowTrans(sead::Vector3f*, bool) const { CRASH }
void HackCap::makeFollowMtx(sead::Matrix34f*) const { CRASH }
void HackCap::updateCapEyeShowHide(bool, s32) { CRASH }
void HackCap::activateInvincibleEffect() { CRASH }
void HackCap::syncInvincibleEffect(bool) { CRASH }
void HackCap::updateSeparateMode(const PlayerSeparateCapFlag*) { WARN_UNIMPL; }
bool HackCap::isEnableRescuePlayer() const { CRASH }
bool HackCap::isRescuePlayer() const { CRASH }
bool HackCap::isEnableHackThrow(bool*) const { CRASH }
bool HackCap::isSeparateHipDropLand() const { CRASH }
bool HackCap::isSeparateHide() const { CRASH }
bool HackCap::isSeparateThrowFlying() const { CRASH }
void HackCap::startRescuePlayer() { CRASH }
void HackCap::prepareCooperateThrow() { CRASH }
void HackCap::requestForceFollowSeparateHide() { CRASH }
f32 HackCap::calcSeparateHideSpeedH(const sead::Vector3f&) const { CRASH }
void HackCap::updateModelAlphaForSnapShot() { CRASH }
s32 HackCap::getPadRumblePort() const { CRASH }
bool HackCap::isEnableThrowSeparate() const { CRASH }
bool HackCap::isHoldInputKeepLockOn() const { CRASH }
bool HackCap::isRequestableReturn() const { WARN_UNIMPL;return false; }
bool HackCap::isLockOnEnableHackTarget() const { CRASH }
bool HackCap::isWaitHackLockOn() const { CRASH }
bool HackCap::isCatched() const { CRASH }
bool HackCap::isHide() const { CRASH }
bool HackCap::isPutOn() const { CRASH }
bool HackCap::isLockOnInterpolate() const { CRASH }
bool HackCap::isEnablePreInput() const { WARN_UNIMPL;return false; }
bool HackCap::isForceCapTouchJump() const { CRASH }
bool HackCap::isHackInvalidSeparatePlay() const { CRASH }
void HackCap::exeLockOn() { CRASH }
void HackCap::updateThrowJoint() { CRASH }
void HackCap::exeHack() { CRASH }
void HackCap::exeSpinAttack() { CRASH }
void HackCap::exeCatch() { CRASH }
void HackCap::exeTrample() { CRASH }
bool HackCap::isHoldSpinCapStay() const { CRASH }
void HackCap::exeTrampleLockOn() { CRASH }
void HackCap::exeRescue() { CRASH }
void HackCap::exeHide() { CRASH }
void HackCap::exeThrowStart() { CRASH }
bool HackCap::isThrowTypeSpiral() const { CRASH }
bool HackCap::isThrowTypeRolling() const { CRASH }
void HackCap::setupThrowStart() { CRASH }
f32 HackCap::getThrowHeight() const { CRASH }
bool HackCap::checkEnableThrowStartSpace(sead::Vector3f*, sead::Vector3f*, sead::Vector3f*,
                                const sead::Vector3f&, f32, f32, bool, const sead::Vector3f&) { CRASH }
void HackCap::updateWaterArea() { CRASH }
f32 HackCap::getThrowRange() const { CRASH }
s32 HackCap::getThrowBrakeTime() const { CRASH }
void HackCap::startThrowCapEyeThrowAction() { CRASH }
void HackCap::exeThrow() { CRASH }
bool HackCap::tryCollideReflectReaction() { CRASH }
bool HackCap::tryCollideWallReaction() { CRASH }
bool HackCap::changeThrowParamInWater(s32, bool) { CRASH }
void HackCap::addCurveOffset() { CRASH }
void HackCap::exeThrowBrake() { CRASH }
bool HackCap::tryAppendAttack() { CRASH }
void HackCap::exeThrowSpiral() { CRASH }
bool HackCap::tryCollideWallReactionSpiral() { CRASH }
void HackCap::endThrowSpiral() { CRASH }
void HackCap::exeThrowTornado() { CRASH }
bool HackCap::tryCollideWallReactionReflect() { CRASH }
void HackCap::exeThrowRolling() { CRASH }
bool HackCap::tryCollideWallReactionRollingGround() { CRASH }
void HackCap::rollingGround() { CRASH }
void HackCap::exeThrowRollingBrake() { CRASH }
void HackCap::exeThrowStay() { CRASH }
bool HackCap::tryChangeSeparateThrow() { CRASH }
f32 HackCap::getThrowBackSpeed() const { CRASH }
void HackCap::updateLavaSurfaceMove() { CRASH }
bool HackCap::tryCollideWallReactionStay() { CRASH }
bool HackCap::isEnableHackThrowAutoCatch() const { CRASH }
s32 HackCap::getThrowStayTime() const { CRASH }
s32 HackCap::getThrowStayTimeMax() const { CRASH }
void HackCap::exeThrowAppend() { CRASH }
f32 HackCap::getThrowSpeedAppend() const { CRASH }
f32 HackCap::getThrowRangeAppend() const { CRASH }
void HackCap::exeBlow() { CRASH }
bool HackCap::tryCollideWallLockOn() { CRASH }
void HackCap::endHackThrowAndReturnHackOrHide() { CRASH }
void HackCap::clearThrowType() { CRASH }
void HackCap::exeRebound() { CRASH }
void HackCap::exeReturn() { CRASH }
void HackCap::calcReturnTargetPos(sead::Vector3f*) const { CRASH }
void HackCap::attackSensor(al::HitSensor* self, al::HitSensor* other) { CRASH }
bool HackCap::stayRollingOrReflect() { CRASH }
bool HackCap::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) { CRASH }
void HackCap::endMove() { CRASH }
bool HackCap::isEnableCapTouchJumpInput() const { CRASH }
void HackCap::prepareTransferLockOn(al::HitSensor*) { CRASH }
void HackCap::collideThrowStartArrow(al::HitSensor*, const sead::Vector3f&, const sead::Vector3f&,
                            const sead::Vector3f&) { CRASH }
bool HackCap::trySendAttackCollideAndReaction(bool*) { CRASH }
bool HackCap::stayWallHit() { CRASH }
void HackCap::endHackThrow() { CRASH }
