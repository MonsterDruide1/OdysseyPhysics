#include "Player/PlayerPuppet.h"

PlayerPuppet::PlayerPuppet(al::LiveActor*, HackCap*, PlayerAnimator*, IUsePlayerCollision*,
                ActorDimensionKeeper*, IPlayerModelChanger*, WorldEndBorderKeeper*,
                PlayerCounterForceRun*, PlayerDamageKeeper*, PlayerEffect*, const PlayerInput*,
                const PlayerConst*) {}
void PlayerPuppet::start(al::HitSensor*, al::HitSensor*) {}
void PlayerPuppet::end() {}
void PlayerPuppet::cancel() {}
void PlayerPuppet::setTrans(const sead::Vector3f&) {}
void PlayerPuppet::setPose(const sead::Quatf&) {}
void PlayerPuppet::setVelocity(const sead::Vector3f&) {}
void PlayerPuppet::resetPosition(const sead::Vector3f&) {}
const sead::Vector3f& PlayerPuppet::getTrans() const {return sead::Vector3f::zero;}
const sead::Vector3f& PlayerPuppet::getVelocity() const {return sead::Vector3f::zero;}
const sead::Vector3f& PlayerPuppet::getGravity() const {return sead::Vector3f::zero;}
void PlayerPuppet::calcFront(sead::Vector3f*) const {}
void PlayerPuppet::calcUp(sead::Vector3f*) const {}
void PlayerPuppet::startAction(const sead::SafeString&) const {}
bool PlayerPuppet::isActionEnd() const {return false;}
bool PlayerPuppet::isActionPlaying(const char*) const {return false;}
void PlayerPuppet::setAnimRate(f32) const {}
f32 PlayerPuppet::getAnimFrameMax() const {return 0.0f;}
void PlayerPuppet::hide() {}
void PlayerPuppet::show() {}
bool PlayerPuppet::isHidden() const {return true;}
void PlayerPuppet::hideSilhouette() {}
void PlayerPuppet::showSilhouette() {}
void PlayerPuppet::hideShadow() {}
void PlayerPuppet::showShadow() {}
void PlayerPuppet::requestDamage() {}
void PlayerPuppet::clearRequestDamage() {}
bool PlayerPuppet::isRequestDamage() const {return false;}
void PlayerPuppet::setBindEndOnGround() {}
bool PlayerPuppet::isBindEndOnGround() const {return false;}
void PlayerPuppet::setBindEndJump(const sead::Vector3f&, s32) {}
bool PlayerPuppet::isBindEndJump() const {return false;}
void PlayerPuppet::validateCollisionCheck() {}
void PlayerPuppet::invalidateCollisionCheck() {}
bool PlayerPuppet::isValidCollisionCheck() {return false;}
bool PlayerPuppet::isCollidedGround() {return false;}
const sead::Vector3f& PlayerPuppet::getCollidedGroundNormal() {return sead::Vector3f::zero;}
void PlayerPuppet::validateSensor() {}
void PlayerPuppet::invalidateSensor() {}
void PlayerPuppet::startPlayerHitReaction(const char*) {}
void PlayerPuppet::setBindEndWallJump(const sead::Vector3f&, s32) {}
void PlayerPuppet::validate2D() {}
void PlayerPuppet::keepOn2D() {}
void PlayerPuppet::endKeepOn2D() {}
void PlayerPuppet::requestUpdateRecoveryInfo(bool, bool, const sead::Vector3f&, const sead::Vector3f&, const al::AreaObj*) {}
bool PlayerPuppet::tryUpdateRecoveryInfo(bool*, bool*, sead::Vector3f*, sead::Vector3f*, const al::AreaObj**) {return false;}
bool PlayerPuppet::isBinding() const {return false;}
bool PlayerPuppet::isNoCollide() const {return false;}
