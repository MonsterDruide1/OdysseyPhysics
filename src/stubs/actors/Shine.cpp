#include "Item/Shine.h"
#include "System/GameDataHolder.h"

const char* ShineFunction::getMovePointLinkName() {return "ShineMovePoint";}

Shine::Shine(char const*) : al::LiveActor("") {WARN_UNIMPL;}
void Shine::endBossDemoAndStartFall(float) {}
void Shine::endBossDemo() {}
void Shine::appearAndJoinBossDemo(char const*, sead::Quat<float> const&, sead::Vector3<float> const&) {}
void Shine::updateHintTrans(sead::Vector3<float> const&) const {}
void Shine::appearPopup() {}
void Shine::appearPopup(sead::Vector3<float> const&) {}
void Shine::appearPopupGrandByBoss(int) {}
void Shine::appearPopupWithoutDemo() {}
void Shine::appearPopupWithoutWarp() {}
void Shine::appearWait() {}
void Shine::appearWait(sead::Vector3<float> const&) {}
void Shine::createShineEffectInsideObject(al::ActorInitInfo const&, sead::Vector3<float> const&, char const*) {}
void Shine::initAppearDemoFromHost(al::ActorInitInfo const&, sead::Vector3<float> const&) {}
bool Shine::isEndAppear() const {return false;}
bool Shine::isGot() const {return false;}
void Shine::setHintPhotoShine(al::ActorInitInfo const&) {}
void Shine::setShopShine() {}
void Shine::init(const al::ActorInitInfo&) {WARN_UNIMPL;}
void Shine::initAfterPlacement() {}
void Shine::appear() {}
void Shine::makeActorAlive() {}
void Shine::makeActorDead() {}
void Shine::control() {}
void Shine::attackSensor(al::HitSensor* self, al::HitSensor* other) {}
bool Shine::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
void Shine::endClipped() {}
ActorDimensionKeeper* Shine::getActorDimensionKeeper() const {WARN_UNIMPL;return nullptr;}
