#include "MapObj/ShineTowerRocket.h"

ShineTowerRocket::ShineTowerRocket(const char* n) : al::LiveActor(n) {}
void ShineTowerRocket::init(const al::ActorInitInfo&) {}
void ShineTowerRocket::onSwitchDither() {}
void ShineTowerRocket::offSwitchDither() {}
void ShineTowerRocket::makeActorDead() {}
void ShineTowerRocket::makeActorAlive() {}
void ShineTowerRocket::initAfterPlacement() {}
void ShineTowerRocket::startClipped() {}
void ShineTowerRocket::control() {}
bool ShineTowerRocket::isActiveDirtyModel() const {return false;}
void ShineTowerRocket::calcAnim() {}
bool ShineTowerRocket::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
void ShineTowerRocket::attackSensor(al::HitSensor* self, al::HitSensor* other) {}
bool ShineTowerRocket::receiveEvent(const al::EventFlowEventData*) {return false;}
void ShineTowerRocket::tryStartEntranceCamera(s32) {}
bool ShineTowerRocket::isFirstDemo() const {return false;}
bool ShineTowerRocket::isEnableSkipDemo() const {return false;}
void ShineTowerRocket::skipDemo() {}
void ShineTowerRocket::exeWait() {}
void ShineTowerRocket::updateParts() {}
bool ShineTowerRocket::isNearPlayerEntrance() const {return false;}
void ShineTowerRocket::exeReaction() {}
void ShineTowerRocket::exeDemoPrepare() {}
bool ShineTowerRocket::tryStartDemo() {return false;}
void ShineTowerRocket::tryEndEntranceCamera() {}
void ShineTowerRocket::exeDemoWalkPlayerToPoint() {}
void ShineTowerRocket::calcPlayerPoseForPayDemo() {}
void ShineTowerRocket::tryStartHitReactionDemoStart() {}
void ShineTowerRocket::exeDemoAppearShine() {}
void ShineTowerRocket::exeDemoWaitAfterAppearShine() {}
bool ShineTowerRocket::tryLevelUp() {return false;}
void ShineTowerRocket::exeDemoWaitBeforeScaleUpDirect() {}
void ShineTowerRocket::calcCameraMtxMeterUpPrev() {}
void ShineTowerRocket::exeDemoScaleUp() {}
void ShineTowerRocket::exeDemoMeterRotate() {}
void ShineTowerRocket::calcCameraMtx() {}
void ShineTowerRocket::setupRotateMeter() {}
void ShineTowerRocket::exeDemoMeterUpPrev() {}
void ShineTowerRocket::exeDemoMeterUp() {}
void ShineTowerRocket::exeDemoMeterUpPost() {}
void ShineTowerRocket::exeDemoTutorialShine() {}
void ShineTowerRocket::exeDemoSelectGoOtherWorld() {}
void ShineTowerRocket::exeDemoAwardMoon() {}
void ShineTowerRocket::exeDemoUpLevelCamera() {}
void ShineTowerRocket::calcCameraMtxLevelUp() {}
void ShineTowerRocket::exeDemoUpLevel() {}
void ShineTowerRocket::exeDemoInformPowerUp() {}
void ShineTowerRocket::exeDemoInformPowerUpMessage() {}
void ShineTowerRocket::exeDemoKoopaShip() {}
void ShineTowerRocket::exeDemoKoopaShipFade() {}
void ShineTowerRocket::exeDemoUpLevelCloseFade() {}
void ShineTowerRocket::exeDemoUpLevelWaitFade() {}
void ShineTowerRocket::exeDemoUpLevelOpenFade() {}
void ShineTowerRocket::exeDemoInformNewHome() {}
void ShineTowerRocket::exeDemoInformNewHomeMessage() {}
void ShineTowerRocket::exeDemoInformPeachCastleCap() {}
void ShineTowerRocket::exeDemoInformRepairHome() {}
void ShineTowerRocket::exeDemoInformNewItem() {}
void ShineTowerRocket::exeDemoInformCompleteShineFadeIn() {}
void ShineTowerRocket::exeDemoInformCompleteShineFadeWait() {}
void ShineTowerRocket::exeDemoInformCompleteShineFadeOut() {}
void ShineTowerRocket::exeDemoInformCompleteShine() {}
void ShineTowerRocket::exeDemoWarpWorld() {}
void ShineTowerRocket::exeWaitDemo() {}
void ShineTowerRocket::exeDemoAppearPlayerFromHome() {}
bool ShineTowerRocket::isActiveDamageModel() const {return false;}
void ShineTowerRocket::exeDemoAppearPlayerFromHomeAfter() {}
void ShineTowerRocket::exeDemoReturnToHome() {}
bool ShineTowerRocket::isActiveDirtyOrClashModel() const {return false;}
void ShineTowerRocket::exeDemoWorldTakeoff() {}
void ShineTowerRocket::exeDemoWorldTakeoffNext() {}
void ShineTowerRocket::setupWorldTakeoffPose(bool) {}
void ShineTowerRocket::exeDemoAppearFromEntrance() {}
void ShineTowerRocket::exeDemoWorldTakeoffForDebug() {}
void ShineTowerRocket::exeNoStart() {}
void ShineTowerRocket::exeNoStartEarth() {}
void ShineTowerRocket::exeNoStartEnter() {}
void ShineTowerRocket::exeBackDoor() {}
void ShineTowerRocket::exeNoStartAndCoin() {}
void ShineTowerRocket::exeGoToWorldMapWithCamera() {}
void ShineTowerRocket::setupWorldMapCameraParam() {}
void ShineTowerRocket::exeGoToWorldMapWithFade() {}
void ShineTowerRocket::exeWorldMap() {}
void ShineTowerRocket::cancelWorldMap() {}
void ShineTowerRocket::decideWorldMap(s32) {}
bool ShineTowerRocket::isWorldMap() const {return false;}
void ShineTowerRocket::startDemoAppearPlayerFromHome() {}
void ShineTowerRocket::startDemoReturnToHome() {}
void ShineTowerRocket::updatePartsByDamage() {}
bool ShineTowerRocket::isActiveClashModel() const {return false;}
