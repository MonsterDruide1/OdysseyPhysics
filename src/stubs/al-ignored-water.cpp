#include "Library/Fluid/RippleCtrl.h"
#include "playerUtil.h"

namespace al {

bool calcFindWaterSurfaceFlat(sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {
    return false;
}
bool calcFindWaterSurfaceOverGround(sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {
    return false;
}
bool calcFindWaterSurfaceDisplacement(sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {
    return false;
}

RippleCtrl* al::RippleCtrl::tryCreate(al::LiveActor*) {WARN_UNIMPL;return nullptr;}
void RippleCtrl::init(al::ActorInitInfo const&) {}
void al::RippleCtrl::update() {}

}  // namespace al
