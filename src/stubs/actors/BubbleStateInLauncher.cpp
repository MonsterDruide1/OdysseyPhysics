#include "Enemy/BubbleStateInLauncher.h"

BubbleStateInLauncher::BubbleStateInLauncher(Bubble* b) : al::HostStateBase<Bubble>("", b) {WARN_UNIMPL;}
void BubbleStateInLauncher::appear() {}
void BubbleStateInLauncher::kill() {}
bool BubbleStateInLauncher::isWaiting() const {return true;}
bool BubbleStateInLauncher::isFlying() const {return false;}
void BubbleStateInLauncher::shoot(const sead::Vector3f&, f32) {}
void BubbleStateInLauncher::calcLaunchPos(sead::Vector3f*, const sead::Vector3f&, f32, s32) const {}
void BubbleStateInLauncher::exeEnter() {}
void BubbleStateInLauncher::exeWait() {}
void BubbleStateInLauncher::exeShoot() {}
