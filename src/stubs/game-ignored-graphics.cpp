#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/Math/MathUtil.h"
#include "Library/Math/MathUtil.h"
#include "Library/Math/MathUtil.h"
#include "Player/Player.h"
#include "PlayerUtil.h"

PlayerCostumeInfo* PlayerFunction::initMarioModelActor(al::LiveActor*, al::ActorInitInfo const&,
                                                       char const*, char const*, al::AudioKeeper*,
                                                       bool) {
    PlayerCostumeInfo* info = new PlayerCostumeInfo();
    info->init(new PlayerBodyCostumeInfo("stub"), new PlayerHeadCostumeInfo("stub"));
    return info;
}

namespace rs {

bool isGuardNosePainCap(al::LiveActor const*) {
    return false;
}

bool isNeedCreateNoseNeedle(PlayerInitInfo const&) {
    return false;
}

void startHitReactionLandJumpIfLanding(al::LiveActor const*, IUsePlayerCollision const*, bool) {}

void startHitReactionLandIfLanding(al::LiveActor const*, IUsePlayerCollision const*, bool) {}

void startHitReactionHipDropLand(al::LiveActor*, bool) {}

}  // namespace rs

bool PlayerFunction::isInvisibleCap(PlayerCostumeInfo const*) {
    return false;
}

void PlayerFunction::initMarioModelActor2D(al::LiveActor*, al::ActorInitInfo const&, char const*,
                                           bool) {}

PlayerJointControlKeeper::PlayerJointControlKeeper(al::LiveActor* player, PlayerConst const*, bool, bool,
                                                   bool) : mPlayer(player) {}

void PlayerJointControlKeeper::resetPartsDynamics() {}

void PlayerJointControlKeeper::calcGroundPoseUp(sead::Vector3<float>* up) const {
    WARN_UNIMPL;
    al::calcUpDir(up, mPlayer);
    al::normalize(up);
}

al::ActorDitherAnimator* PlayerFunction::createPlayerDitherAnimator(al::LiveActor*, float) {
    return nullptr;
}

PlayerEffect::PlayerEffect(al::LiveActor*, PlayerModelHolder const*, sead::Matrix34<float> const*) {
}

void PlayerEffect::updateWaterSurfaceMtx(al::WaterSurfaceFinder const*) {}

void PlayerEffect::tryEmitRollingEffect() {}

void PlayerEffect::tryDeleteRollingEffect() {}

void PlayerEffect::tryStartRunEffectDashWaterSurface() {}

void PlayerEffect::tryStartRunEffectRunStart() {}

void PlayerEffect::clearRunEffect() {}

PlayerModelChangerHakoniwa::PlayerModelChangerHakoniwa(al::LiveActor const*, PlayerModelHolder*,
                                                       PlayerPainPartsKeeper*, PlayerCostumeInfo*,
                                                       IUseDimension const*) {}

void PlayerModelChangerHakoniwa::syncHost(bool) {}

void PlayerModelChangerHakoniwa::initStartModel() {}

bool PlayerModelChangerHakoniwa::isFireFlower() const {
    return false;
}

bool PlayerModelChangerHakoniwa::isMini() const {
    return false;
}

bool PlayerModelChangerHakoniwa::isChange() const {
    return false;
}

bool PlayerModelChangerHakoniwa::is2DModel() const {
    return false;
}

bool PlayerModelChangerHakoniwa::isHiddenModel() const {
    return false;
}

bool PlayerModelChangerHakoniwa::isHiddenShadowMask() const {
    return false;
}

void PlayerModelChangerHakoniwa::hideModel() {}

void PlayerModelChangerHakoniwa::hideSilhouette() {}

void PlayerModelChangerHakoniwa::hideShadowMask() {}

void PlayerModelChangerHakoniwa::showModel() {}

void PlayerModelChangerHakoniwa::showSilhouette() {}

void PlayerModelChangerHakoniwa::showShadowMask() {}

void PlayerModelChangerHakoniwa::resetPosition() {}

PlayerEyeSensorHitHolder::PlayerEyeSensorHitHolder(int) {}

void PlayerEyeSensorHitHolder::createTargetMarkerBuffer(int) {}

void PlayerEyeSensorHitHolder::clear() {}

void PlayerRippleGenerator::reset() {}

PlayerWetControl::PlayerWetControl(al::LiveActor const*, al::LiveActor*, PlayerAreaChecker const*) {
}

void PlayerWetControl::recordPuddleRolling() {}

PlayerStainControl::PlayerStainControl(al::LiveActor const*, al::LiveActor*,
                                       PlayerModelChangerHakoniwa const*, HackCap const*,
                                       PlayerEffect*) {}

GaugeAir::GaugeAir(char const*, al::LayoutInitInfo const&) {}

WaterSurfaceShadow::WaterSurfaceShadow(al::ActorInitInfo const&, char const*) {}

void WaterSurfaceShadow::setScale(float) {}

PlayerCapManHeroEyesControl::PlayerCapManHeroEyesControl(char const*, al::LiveActor*,
                                                         al::LiveActor*) {}

bool PlayerStateWait::tryUpdateAreaAnim() {
    return false;
}

bool PlayerStateWait::tryChangeRequestAnim() {
    return false;
}

bool PlayerStateWait::tryChangeAreaAnim() {
    return false;
}
