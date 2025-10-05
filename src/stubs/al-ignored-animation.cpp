#include "Library/Movement/AnimScaleController.h"
#include "Project/Action/ActionAnimCtrl.h"

namespace al {

void copySklAnim(al::LiveActor*, al::LiveActor const*) {}

al::ActionAnimCtrl* al::ActionAnimCtrl::tryCreate(al::LiveActor*, al::ActorResource const*, char const*, char const*) {WARN_UNIMPL; return nullptr;}
f32 ActionAnimCtrl::getActionFrameMax(char const*) const {return 1.0f;}
f32 ActionAnimCtrl::getFrame() const {return 0.0f;}
f32 ActionAnimCtrl::getFrameRate() const {return 1.0f;}
const char* ActionAnimCtrl::getPlayingActionName() {return "";}
bool ActionAnimCtrl::isActionEnd() {return false;}
bool ActionAnimCtrl::isActionOneTime(const char*) {return true;}

AnimScaleController::AnimScaleController(al::AnimScaleParam const*) : al::NerveExecutor("") {}
void AnimScaleController::startAndSetScaleVelocityY(float) {}
void AnimScaleController::startAndSetScaleY(float) {}
void AnimScaleController::stopAndReset() {}
void AnimScaleController::update() {}

}

namespace alAnimFunction {
    
f32 getAllAnimFrame(al::LiveActor const*, int) {return 0.0f;}
f32 getAllAnimFrameMax(al::LiveActor const*, char const*, int) {return 1.0f;}
f32 getAllAnimFrameRate(al::LiveActor const*, int) {return 1.0f;}
const char* getAllAnimName(al::LiveActor const*) {return "";}
bool isAllAnimEnd(al::LiveActor const*, int) {return false;}

}
