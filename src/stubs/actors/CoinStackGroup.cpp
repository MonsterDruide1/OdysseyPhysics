#include "Item/CoinStackGroup.h"

CoinStackGroup::CoinStackGroup(const char* name) : al::LiveActor(name) {WARN_UNIMPL;}
void CoinStackGroup::init(const al::ActorInitInfo& info) {}
void CoinStackGroup::control() {}
bool CoinStackGroup::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
void CoinStackGroup::makeActorDead() {}
void CoinStackGroup::makeActorAlive() {}
void CoinStackGroup::generateCoinStackGroup(const al::ActorInitInfo&, s32) {}
void CoinStackGroup::makeStackAppear() {}
void CoinStackGroup::makeStackDisappear() {}
f32 CoinStackGroup::setStackAsCollected(CoinStack* stack) {return 0.0f;}
f32 CoinStackGroup::updateClippingInfo(u32 stackAmount) {return 0.0f;}
void CoinStackGroup::validateClipping() {}
