#include "Item/CoinCollectHolder.h"
#include "Item/CoinRotateCalculator.h"
#include "Item/LifeMaxUpItem.h"
#include "Item/LifeMaxUpItem2D.h"
#include "Item/LifeUpItem.h"
#include "Item/LifeUpItem2D.h"
#include "System/GameDataFunction.h"
#include "Util/ItemUtil.h"

CoinCollectHolder* rs::createCoinCollectHolder(al::IUseSceneObjHolder const*) {WARN_UNIMPL;return nullptr;}
const char* rs::getStageCoinCollectArchiveName(al::LiveActor const*) {return "";}
const char* rs::getStageCoinCollectEmptyArchiveName(al::LiveActor const*) {return "";}
const char* rs::getStageCoinCollect2DArchiveName(al::LiveActor const*) {return "";}
const char* rs::getStageCoinCollect2DEmptyArchiveName(al::LiveActor const*) {return "";}

void CoinCollectHolder::registerCoinCollect2D(CoinCollect2D*) {}
void CoinCollectHolder::registerHintObj(CoinCollectHintObj*) {}
void CoinCollectHolder::registerCoinCollect(CoinCollect*) {}

CoinRotateCalculator::CoinRotateCalculator(al::LiveActor*) {}
void CoinRotateCalculator::addFishingLineTouch() {}
f32 CoinRotateCalculator::getRotate() const {return 0.0f;}
void CoinRotateCalculator::reset() {}
void CoinRotateCalculator::update(sead::Vector3<float> const&, bool) {}

void GameDataFunction::addCoin(GameDataHolderWriter, int) {}
void GameDataFunction::addCoinCollect(GameDataHolderWriter, al::PlacementId const*) {}
s32 GameDataFunction::getCoinCollectGotNum(GameDataHolderAccessor) {return 0;}
s32 GameDataFunction::getCoinCollectNumMax(GameDataHolderAccessor) {return 0;}
bool GameDataFunction::isGotCoinCollect(GameDataHolderAccessor, al::ActorInitInfo const&) {return false;}

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
