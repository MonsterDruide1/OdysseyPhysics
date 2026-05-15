#include "Item/CoinRotateCalculator.h"
#include "Item/LifeMaxUpItem.h"
#include "Item/LifeMaxUpItem2D.h"
#include "Item/LifeUpItem.h"
#include "Item/LifeUpItem2D.h"
#include "MapObj/BlockStateSingleItem.h"
#include "MapObj/BlockStateTenCoin.h"
#include "Util/ItemUtil.h"

CoinRotateCalculator::CoinRotateCalculator(al::LiveActor*) {}
void CoinRotateCalculator::addFishingLineTouch() {}
f32 CoinRotateCalculator::getRotate() const {return 0.0f;}
void CoinRotateCalculator::reset() {}
void CoinRotateCalculator::update(sead::Vector3<float> const&, bool) {}

LifeMaxUpItem2D::LifeMaxUpItem2D(char const*) : al::LiveActor("") {}
void LifeMaxUpItem2D::init(const al::ActorInitInfo& initInfo) {}
bool LifeMaxUpItem2D::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
ActorDimensionKeeper* LifeMaxUpItem2D::getActorDimensionKeeper() const {WARN_UNIMPL;return nullptr;}
void LifeMaxUpItem2D::appear() {}

LifeMaxUpItem::LifeMaxUpItem(char const*) : al::LiveActor("") {}
void LifeMaxUpItem::init(const al::ActorInitInfo& initInfo) {}
void LifeMaxUpItem::initAfterPlacement() {}
bool LifeMaxUpItem::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
void LifeMaxUpItem::appear() {}
void LifeMaxUpItem::control() {}

LifeUpItem::LifeUpItem(char const*) : al::LiveActor("") {}
void LifeUpItem::init(const al::ActorInitInfo& initInfo) {}
void LifeUpItem::initAfterPlacement() {}
bool LifeUpItem::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
void LifeUpItem::control() {}

LifeUpItem2D::LifeUpItem2D(char const*) : al::LiveActor("") {}
void LifeUpItem2D::init(const al::ActorInitInfo& initInfo) {}
bool LifeUpItem2D::receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                al::HitSensor* self) {return false;}
ActorDimensionKeeper* LifeUpItem2D::getActorDimensionKeeper() const {WARN_UNIMPL;return nullptr;}

BlockStateSingleItem::BlockStateSingleItem(al::LiveActor* a, int, bool) : al::ActorStateBase("", a) {WARN_UNIMPL;}
void BlockStateSingleItem::init() {}
bool BlockStateSingleItem::isReaction() const {return false;}
bool BlockStateSingleItem::receiveMsg(al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {return false;}
void BlockStateSingleItem::setItemOffsetY(float) {}
BlockStateTenCoin::BlockStateTenCoin(al::LiveActor* a, bool) : al::ActorStateBase("", a) {WARN_UNIMPL;}
void BlockStateTenCoin::init() {}
void BlockStateTenCoin::control() {}
bool BlockStateTenCoin::isReaction() const {return false;}
bool BlockStateTenCoin::receiveMsg(al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {return false;}
