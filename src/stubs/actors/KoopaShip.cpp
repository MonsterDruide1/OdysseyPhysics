#include "MapObj/KoopaShip.h"

KoopaShip::KoopaShip(const char* n) : al::LiveActor(n) {}
void KoopaShip::init(const al::ActorInitInfo&) {}
void KoopaShip::onSwitchGateKeeperOpeningDemoStart() {}
void KoopaShip::onBlurMovie() {}
void KoopaShip::initAfterPlacement() {}
void KoopaShip::offDepthShadow() {}
void KoopaShip::onDepthShadow() {}
void KoopaShip::movement() {}
void KoopaShip::control() {}
void KoopaShip::appear() {}
void KoopaShip::kill() {}
void KoopaShip::calcAnim() {}
void KoopaShip::startClipped() {}
void KoopaShip::endClipped() {}
void KoopaShip::exeWait() {}
void KoopaShip::endWait() {}
void KoopaShip::exeDemo() {}
void KoopaShip::exeDemoAppear() {}
void KoopaShip::exeDemoGateKeeper() {}
void KoopaShip::exeDemoHomeFlyAway() {}
void KoopaShip::exeDemoHomeFlyAwayAfter() {}
void KoopaShip::startDemoWait() {}
void KoopaShip::endDemoWait(Peach*) {}
void KoopaShip::skipGateKeeperOpeningDemo() {}
void KoopaShip::startDemoHomeFlyAway() {}
bool KoopaShip::isEnableStartWipeDemoHomeFlyAway() const {return false;}
s32 KoopaShip::getWipeDemoFlyAwayStep() {return 0;}
bool KoopaShip::isEnableEndDemoHomeFlyAway() const {return false;}
KoopaShip* KoopaShip::createForKoopaLv1(al::LiveActor*, Peach*, const al::ActorInitInfo&) {WARN_UNIMPL;return nullptr;}
void KoopaShip::switchHalfModel() {}
