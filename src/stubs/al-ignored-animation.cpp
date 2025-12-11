#include "Library/Anim/AnimPlayerSkl.h"
#include "Library/Movement/AnimScaleController.h"
#include "Project/Action/ActionAnimCtrl.h"
#include "Project/Anim/AnimPlayerSimple.h"

namespace al {

void copySklAnim(al::LiveActor*, al::LiveActor const*) {}

al::ActionAnimCtrl* al::ActionAnimCtrl::tryCreate(al::LiveActor*, al::ActorResource const*, char const*, char const*) {WARN_UNIMPL; return nullptr;}
f32 ActionAnimCtrl::getActionFrameMax(char const*) const {return 1.0f;}
f32 ActionAnimCtrl::getFrame() const {return 0.0f;}
f32 ActionAnimCtrl::getFrameRate() const {return 1.0f;}
const char* ActionAnimCtrl::getPlayingActionName() const {return "";}
bool ActionAnimCtrl::isActionEnd() const {return false;}
bool ActionAnimCtrl::isActionOneTime(const char*) const {return true;}
bool ActionAnimCtrl::start(char const*) {return false;}
bool ActionAnimCtrl::isExistAction(char const*) const {return false;}

AnimScaleController::AnimScaleController(al::AnimScaleParam const*) : al::NerveExecutor("") {}
void AnimScaleController::startAndSetScaleVelocityY(float) {}
void AnimScaleController::startAndSetScaleY(float) {}
void AnimScaleController::stopAndReset() {}
void AnimScaleController::update() {}

void AnimPlayerSimple::startAnim(char const*) {}
void AnimPlayerSimple::setAnimFrame(float) {}
void AnimPlayerSimple::setAnimFrameRate(float) {}
bool AnimPlayerSimple::isAnimExist(char const*) const {return false;}
const char* AnimPlayerSimple::getPlayingAnimName() const {return "";}
void AnimPlayerSimple::clearAnim() {}
bool AnimPlayerSimple::isAnimEnd() const {return false;}
bool AnimPlayerSimple::isAnimOneTime(char const*) const {return false;}
bool AnimPlayerSimple::isAnimOneTime() const {return false;}
bool AnimPlayerSimple::isAnimPlaying() const {return false;}
f32 AnimPlayerSimple::getAnimFrame() const {return 0.0f;}
f32 AnimPlayerSimple::getAnimFrameRate() const {return 0.0f;}
f32 AnimPlayerSimple::getAnimFrameMax() const {return 0.0f;}
f32 AnimPlayerSimple::getAnimFrameMax(char const*) const {return 0.0f;}

bool AnimPlayerSkl::startSklAnim(char const*, char const*, char const*, char const*, char const*, char const*, char const*) {return false;}
bool AnimPlayerSkl::isSklAnimExist(char const*) const {return false;}
const char* AnimPlayerSkl::getPlayingSklAnimName(int) const {return "";}
void AnimPlayerSkl::reset() {}
bool AnimPlayerSkl::isSklAnimEnd(int) const {return false;}
bool AnimPlayerSkl::isSklAnimOneTime(char const*) const {return false;}
bool AnimPlayerSkl::isSklAnimOneTime(int) const {return false;}
bool AnimPlayerSkl::isSklAnimPlaying(int) const {return false;}
f32 AnimPlayerSkl::getSklAnimFrame(int) const {return 0.0f;}
f32 AnimPlayerSkl::getSklAnimFrameRate(int) const {return 0.0f;}
f32 AnimPlayerSkl::getSklAnimFrameMax(int) const {return 0.0f;}
f32 AnimPlayerSkl::getSklAnimFrameMax(char const*) const {return 0.0f;}
void AnimPlayerSkl::setSklAnimFrame(int, float) {}
void AnimPlayerSkl::setSklAnimFrameRate(int, float) {}
s32 AnimPlayerSkl::getSklAnimBlendNum() const {return 0;}
f32 AnimPlayerSkl::getSklAnimBlendWeight(int) const {return 0.0f;}
bool AnimPlayerSkl::calcSklAnim() {return false;}
void AnimPlayerSkl::startPartialAnim(char const*, int, int, SklAnimRetargettingInfo const*) {}
void AnimPlayerSkl::prepareAnimInterpDirect(int) {}
void AnimPlayerSkl::clearPartialAnim(int) {}
bool AnimPlayerSkl::isPartialAnimEnd(int) const {return false;}
bool AnimPlayerSkl::isPartialAnimOneTime(int) const {return false;}
bool AnimPlayerSkl::isPartialAnimAttached(int) const {return false;}
const char* AnimPlayerSkl::getPlayingPartialSklAnimName(int) const {return "";}
f32 AnimPlayerSkl::getPartialAnimFrame(int) const {return 0.0f;}
void AnimPlayerSkl::setPartialAnimFrame(int, float) {}
f32 AnimPlayerSkl::getPartialAnimFrameRate(int) const {return 0.0f;}
void AnimPlayerSkl::setPartialAnimFrameRate(int, float) {}
void AnimPlayerSkl::setSklAnimBlendWeight(int, float) {}

}

namespace alAnimFunction {
    
f32 getAllAnimFrame(al::LiveActor const*, int) {return 0.0f;}
f32 getAllAnimFrameMax(al::LiveActor const*, char const*, int) {return 1.0f;}
f32 getAllAnimFrameRate(al::LiveActor const*, int) {return 1.0f;}
const char* getAllAnimName(al::LiveActor const*) {return "";}
bool isAllAnimEnd(al::LiveActor const*, int) {return false;}
bool checkPass(float, float, float, bool, float) {return false;}

}
