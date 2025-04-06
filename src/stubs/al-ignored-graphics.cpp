#include "Library/Anim/AnimPlayerSkl.h"
#include "Library/Execute/ExecuteTableHolderUpdate.h"
#include "Library/Layout/LayoutInitInfo.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/Model/ModelCtrl.h"
#include "Library/Model/ModelKeeper.h"
#include "Library/Shadow/ShadowMaskCtrl.h"
#include "Project/Action/ActionAnimCtrl.h"
#include "Project/Anim/AnimPlayerSimple.h"
#include "playerUtil.h"

namespace al {

const char* getModelName(al::LiveActor const*) {
    return "";
}

s32 getMaterialCount(al::LiveActor const*) {
    return 0;
}

const char* getMaterialName(al::LiveActor const*, int) {
    return "";
}

void setModelMaterialParameterV4F(al::LiveActor const*, char const*, char const*, sead::Vector4<float> const&) {}

void tryInitFixedModelGpuBuffer(LiveActor*) {}

void showModel(al::LiveActor*) {}

void hideModel(al::LiveActor*) {}

void hideSilhouetteModel(al::LiveActor*) {}

void validateDitherAnim(al::LiveActor*) {}

void setModelAlphaMask(LiveActor*, float) {}

void setModelMaterialParameterF32(al::LiveActor const*, char const*, char const*, float) {}

void stopDitherAnimAutoCtrl(al::LiveActor*) {}

bool tryExpandClippingByDepthShadowLength(al::LiveActor*, sead::Vector3<float>*) {
    return false;
}

void offDrawClipping(al::LiveActor*) {}

void onDrawClipping(al::LiveActor*) {}

void setRailClippingInfo(sead::Vector3<float>*, al::LiveActor*, float, float) {}

void setClippingInfo(al::LiveActor*, float, sead::Vector3<float> const*) {}

void validateClipping(al::LiveActor*) {}

void showShadowMask(al::LiveActor*) {}

void showSilhouetteModelIfHide(al::LiveActor*) {}

void setModelProjMtx0(al::ModelKeeper const*, sead::Matrix44<float> const&) {}

void setModelMaterialParameterF32(al::LiveActor const*, int, char const*, float) {}

void setShadowMaskDropLength(al::LiveActor*, float, char const*) {}

void setShadowMaskIntensity(al::LiveActor const*, char const*, float) {}

void offDepthShadowModel(al::LiveActor*) {}

void onDepthShadowModel(al::LiveActor*) {}

void hideShadowMask(al::LiveActor*) {}

void hideSilhouetteModelIfShow(al::LiveActor*) {}

void invalidateDepthShadowMap(al::LiveActor*) {}

bool isExistDepthShadowMapCtrl(al::LiveActor*) {
    return false;
}

bool isHideModel(LiveActor const*) {
    return false;
}

void hideModelIfShow(LiveActor*) {}

void showModelIfHide(LiveActor*) {}

u8* getModelResourceYaml(al::LiveActor const*, char const*, char const*) {
    return nullptr;
}

void offSyncAppearSubActor(al::LiveActor*, al::LiveActor const*) {}

void offSyncHideSubActor(al::LiveActor*, al::LiveActor const*) {}

void onSyncAppearSubActor(al::LiveActor*, al::LiveActor const*) {}

void invalidateClipping(al::LiveActor*) {}

const al::LayoutInitInfo* getLayoutInitInfo(al::ActorInitInfo const&) {
    return nullptr;
}

void setMaterialProgrammable(al::LiveActor*) {}

void onSyncClippingSubActor(al::LiveActor*, al::LiveActor const*) {}

void onSyncHideSubActor(al::LiveActor*, al::LiveActor const*) {}

void onSyncAlphaMaskSubActor(al::LiveActor*, al::LiveActor const*) {}

s32 getMaterialIndex(al::LiveActor const*, char const*) {
    return 0;
}

f32 getShadowMaskIntensity(al::LiveActor const*, char const*) {
    return 0.0f;
}

bool blinkModel(al::LiveActor*, int, int, int) {
    return false;
}

void updateDepthShadowMapCtrlShapeVisible(al::LiveActor*) {}

void validateDepthShadowMap(al::LiveActor*) {}

FootPrintHolder::FootPrintHolder(al::LiveActor*, char const*, al::HitSensor*,
                                 al::FootPrintServer*) {}

void ModelCtrl::recreateDisplayList() {}

void ModelKeeper::createMatAnimForProgram(int) {}

void ModelKeeper::setDitherAnimator(al::DitherAnimator*) {}

void ModelKeeper::calc(sead::Matrix34<float> const&, sead::Vector3<float> const&) {}

bool AnimPlayerSkl::startSklAnim(char const*, char const*, char const*, char const*, char const*,
                                 char const*, char const*) {}

bool AnimPlayerSkl::isSklAnimExist(char const*) {}

const char* AnimPlayerSkl::getPlayingSklAnimName(int) {}

void AnimPlayerSkl::reset() {}

bool AnimPlayerSkl::isSklAnimEnd(int) {}

bool AnimPlayerSkl::isSklAnimOneTime(char const*) {}

bool AnimPlayerSkl::isSklAnimOneTime(int) {}

bool AnimPlayerSkl::isSklAnimPlaying(int) {}

f32 AnimPlayerSkl::getSklAnimFrame(int) {}

f32 AnimPlayerSkl::getSklAnimFrameRate(int) {}

f32 AnimPlayerSkl::getSklAnimFrameMax(int) {}

f32 AnimPlayerSkl::getSklAnimFrameMax(char const*) {}

void AnimPlayerSkl::setSklAnimFrame(int, float) {}

void AnimPlayerSkl::setSklAnimFrameRate(int, float) {}

s32 AnimPlayerSkl::getSklAnimBlendNum() {}

f32 AnimPlayerSkl::getSklAnimBlendWeight(int) {}

bool AnimPlayerSkl::calcSklAnim() {}

bool ActionAnimCtrl::isExistAction(char const*) {}

void AnimPlayerSimple::startAnim(char const*) {}

void AnimPlayerSimple::setAnimFrame(float) {}

void AnimPlayerSimple::setAnimFrameRate(float) {}

bool AnimPlayerSimple::isAnimExist(char const*) {}

const char* AnimPlayerSimple::getPlayingAnimName() {}

void AnimPlayerSimple::clearAnim() {}

bool AnimPlayerSimple::isAnimEnd() {}

bool AnimPlayerSimple::isAnimOneTime(char const*) {}

bool AnimPlayerSimple::isAnimOneTime() {}

bool AnimPlayerSimple::isAnimPlaying() {}

f32 AnimPlayerSimple::getAnimFrame() {}

f32 AnimPlayerSimple::getAnimFrameRate() {}

f32 AnimPlayerSimple::getAnimFrameMax() {}

f32 AnimPlayerSimple::getAnimFrameMax(char const*) {}

void AnimPlayerSkl::startPartialAnim(char const*, int, int, SklAnimRetargettingInfo const*) {}

void AnimPlayerSkl::prepareAnimInterpDirect(int) {}

void AnimPlayerSkl::clearPartialAnim(int) {}

bool AnimPlayerSkl::isPartialAnimEnd(int) {}

bool AnimPlayerSkl::isPartialAnimOneTime(int) {}

bool AnimPlayerSkl::isPartialAnimAttached(int) {}

const char* AnimPlayerSkl::getPlayingPartialSklAnimName(int) {}

f32 AnimPlayerSkl::getPartialAnimFrame(int) {}

void AnimPlayerSkl::setPartialAnimFrame(int, float) {}

f32 AnimPlayerSkl::getPartialAnimFrameRate(int) {}

void AnimPlayerSkl::setPartialAnimFrameRate(int, float) {}

void AnimPlayerSkl::setSklAnimBlendWeight(int, float) {}

void ShadowMaskCtrl::validate() {}

void ShadowMaskCtrl::invalidate() {}

}  // namespace al
