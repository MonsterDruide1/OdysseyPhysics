#include "Library/Fluid/RippleCtrl.h"

namespace al {

bool calcFindWaterSurface(sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {
    return false;
}
bool calcFindWaterSurfaceFlat(sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {
    return false;
}
bool calcFindWaterSurfaceOverGround(sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {
    return false;
}
bool calcFindWaterSurfaceDisplacement(sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {
    return false;
}

bool isInWater(al::LiveActor const*) {
    return false;
}
bool isInWaterPos(al::LiveActor const*, sead::Vector3<float> const&) {
    return false;
}
bool isInIceWaterPos(al::LiveActor const*, sead::Vector3<float> const&) {
    return false;
}

RippleCtrl* RippleCtrl::tryCreate(LiveActor*) {WARN_UNIMPL;return nullptr;}
void RippleCtrl::init(ActorInitInfo const&) {}
void RippleCtrl::update() {}
bool tryAddRippleLarge(LiveActor const*) {return false;}
bool tryAddRippleMiddle(al::LiveActor const*) {return false;}

}  // namespace al
