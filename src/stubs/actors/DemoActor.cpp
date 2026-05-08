#include "Library/Demo/DemoActor.h"

namespace al {

DemoActor::DemoActor(const char* name) : al::LiveActor(name) {WARN_UNIMPL;}
void DemoActor::init(const ActorInitInfo& info) {}
void DemoActor::control() {}
void DemoActor::initDemoActor(const ActorInitInfo&, const ActorInitInfo&, const sead::Matrix34f*, bool) {}
void DemoActor::initDemoActorSerial(const ActorInitInfo&, const ActorInitInfo&, const sead::Matrix34f*) {}
void DemoActor::initAfterCreateFromFactory(const ActorInitInfo&, const ActorInitInfo&, const sead::Matrix34f*, bool) {}
void DemoActor::startAction(s32) {}
void DemoActor::resetDynamics() {}
void DemoActor::initCommon(const ActorInitInfo&, const ActorInitInfo&, const sead::Matrix34f*, bool) {}
void DemoActor::startDemo(const sead::Matrix34f&) {}
bool DemoActor::isExistAction(s32) const {return false;}
const char* DemoActor::getDemoActionName(s32) const {return "";}
void DemoActor::startActionByName(const char* actionName) {}
void DemoActor::hideModelBySwitch() {}
void DemoActor::showModelBySwitch() {}
void DemoActor::endDemo() {}
void DemoActor::exeDelay() {}
void DemoActor::exeAction() {}

}
