#include "Enemy/KaronWingStateHack.h"

KaronWingStateHack::KaronWingStateHack(al::LiveActor*, al::ActorInitInfo const&, IUsePlayerHack**) : al::ActorStateBase("", nullptr) {CRASH}
void KaronWingStateHack::attackSensor(al::HitSensor*, al::HitSensor*) {CRASH}
bool KaronWingStateHack::isEndCancel() const {CRASH}
bool KaronWingStateHack::isEndDamage() const {CRASH}
bool KaronWingStateHack::isEndReset() const {CRASH}
bool KaronWingStateHack::receiveMsg(al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {CRASH}
void KaronWingStateHack::resetFlyLimit(sead::Vector3<float> const&) {CRASH}
void KaronWingStateHack::updateCollider() {CRASH}
PlayerCollider* KaronWingStateHack::getPlayerCollider() const {CRASH}
