#include "Library/Screen/ScreenPointTarget.h"

namespace al {

ScreenPointTarget::ScreenPointTarget(LiveActor*, const char*, f32, const sead::Vector3f*, const char*, const sead::Vector3f&) {}
void ScreenPointTarget::setFollowMtxPtrByJointName(const LiveActor*) {}
const char* ScreenPointTarget::getJointName() const {return "";}
void ScreenPointTarget::update() {}
void ScreenPointTarget::validate() {}
void ScreenPointTarget::invalidate() {}
void ScreenPointTarget::validateBySystem() {}
void ScreenPointTarget::invalidateBySystem() {}
f32 ScreenPointTarget::getTargetRadius() const {return 0.0f;}
const char* ScreenPointTarget::getTargetName() const {return "";}
void ScreenPointTarget::setTargetName(const char*) {}
void ScreenPointTarget::setTargetRadius(f32) {}
void ScreenPointTarget::setTargetFollowPosOffset(const sead::Vector3f&) {}
void ScreenPointTarget::setJointName(const char*) {}

}  // namespace al
