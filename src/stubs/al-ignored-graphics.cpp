#include "Library/Anim/AnimPlayerSkl.h"
#include "Library/Clipping/ClippingActorHolder.h"
#include "Library/Draw/GraphicsSystemInfo.h"
#include "Library/Execute/ExecuteTableHolderUpdate.h"
#include "Library/KeyPose/KeyPoseKeeper.h"
#include "Library/Layout/LayoutInitInfo.h"
#include "Library/Light/ModelMaterialCategory.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/LiveActorKit.h"
#include "Library/Model/ModelCtrl.h"
#include "Library/Model/ModelDisplayListController.h"
#include "Library/Model/ModelDrawBufferUpdater.h"
#include "Library/Model/ModelGroup.h"
#include "Library/Model/ModelKeeper.h"
#include "Library/Model/ModelLodCtrl.h"
#include "Library/Model/ModelOcclusionCullingDirector.h"
#include "Library/Model/ModelOcclusionQuery.h"
#include "Library/Model/SkyDirector.h"
#include "Library/Obj/ActorDitherAnimator.h"
#include "Library/Obj/FarDistanceDitherAnimator.h"
#include "Library/Obj/ModelDrawParts.h"
#include "Library/Obj/SimpleCircleShadowXZ.h"
#include "Library/Rail/RailUtil.h"
#include "Library/Scene/SceneUtil.h"
#include "Library/Shader/ActorOcclusionKeeper.h"
#include "Library/Shader/ForwardRendering/ShaderHolder.h"
#include "Library/Shadow/DepthShadowMapCtrl.h"
#include "Library/Shadow/DepthShadowMapDirector.h"
#include "Library/Shadow/ShadowDirector.h"
#include "Library/Shadow/ShadowMaskDirector.h"
#include "Library/Shadow/ShadowMaskBase.h"
#include "Library/Shadow/ShadowMaskCtrl.h"
#include "Library/Shadow/ShadowMaskSphere.h"
#include "Library/Shadow/ShadowMaskCube.h"
#include "Library/Shadow/ShadowMaskCylinder.h"
#include "Library/Shadow/ShadowMaskCastOvalCylinder.h"
#include "Project/Action/ActionAnimCtrl.h"
#include "Project/Anim/AnimPlayerSimple.h"
#include "Project/Clipping/ClippingFunction.h"
#include "Project/Light/ActorPrepassLightKeeper.h"
#include "playerUtil.h"

namespace al {

SEAD_SINGLETON_DISPOSER_IMPL(ShaderHolder);
ShaderHolder::ShaderHolder() {}

void initPartialSklAnim(al::LiveActor*, int, int, int) {}
void invalidateShadowMaskIntensityAll(al::LiveActor*) {}
void setClippingNearDistance(al::LiveActor*, float) {}
void setClippingObb(al::LiveActor*, sead::BoundBox3<float> const&) {}
void setFixedModelFlag(al::LiveActor*) {}
void setIgnoreUpdateDrawClipping(al::LiveActor*, bool) {}
void calcModelBoundingBox(sead::BoundBox3<float>*, al::LiveActor const*) {}
f32 calcModelBoundingSphereRadius(al::LiveActor const*) {return 0.0f;}
void createUniqueShader(al::LiveActor*) {}
bool isExistModel(al::LiveActor const*) {return false;}
s32 getLodModelCount(al::LiveActor const*) {return 1;}
void initActorClipping(al::LiveActor*, al::ActorInitInfo const&) {}
void initGroupClipping(al::LiveActor*, al::ActorInitInfo const&) {}
void invalidateDitherAnim(al::LiveActor*) {}
bool isExistDitherAnimator(al::LiveActor const*) {return false;}
void setKeyMoveClippingInfo(al::LiveActor*,sead::Vector3f*,al::KeyPoseKeeper const*) {}
void calcKeyMoveClippingInfo(sead::Vector3f*,float*,al::KeyPoseKeeper const*,float) {}
bool updateSyncHostVisible(bool*, al::LiveActor*, al::LiveActor const*, bool) {return false;}
f32 getModelAlphaMask(al::LiveActor const*) {return 1.0f;}
void calcViewModel(al::LiveActor*) {}
void forceApplyCubeMap(al::LiveActor*, char const*) {}
f32 getClippingRadius(al::LiveActor const*) {return 1.0f;}
bool isViewDependentModel(al::LiveActor const*) {return false;}
bool isGreaterEqualMaxLodLevelNoClamp(al::ModelKeeper const*) {return false;}
bool isLessMaxLodLevelNoClamp(al::ModelKeeper const*) {return false;}
void expandClippingRadiusByShadowLength(al::LiveActor*, sead::Vector3f*, float) {}
void hideShadow(al::LiveActor*) {}
void setNeedSetBaseMtxAndCalcAnimFlag(al::LiveActor*, bool) {}
const sead::Vector3f& getClippingCenterPos(al::LiveActor const*) {return sead::Vector3f::zero;}
bool isInClippingFrustumAllView(al::LiveActor const*, sead::Vector3<float> const&, float, float) {return true;}
void setDitherAnimMaxAlpha(al::LiveActor*, float) {}
bool isIncludePrepassCullingShape(al::LiveActor*) {return false;}
bool isUsingPrepassTriangleCulling() {return false;}
void forceApplyCubeMap(al::ModelKeeper*, al::GraphicsSystemInfo const*, char const*) {}

DepthShadowMapCtrl::DepthShadowMapCtrl(al::Resource const*) {}
DepthShadowMapCtrl::~DepthShadowMapCtrl() {}
void DepthShadowMapCtrl::appendDepthShadowMapInfo(char const*, int, int, int, float, bool, sead::Vector3<float> const&, bool, sead::Vector3<float> const&, sead::Vector3<float> const&, bool, char const*, int, bool, float, float, float, bool, bool, float, int, bool, bool, float) {}
void DepthShadowMapCtrl::init(al::LiveActor*, al::ByamlIter const&) {}
void DepthShadowMapCtrl::initWithoutIter(al::LiveActor*, int) {}
void DepthShadowMapDirector::createDepthShadowMap(al::DepthShadowMapCtrl const*, al::ModelKeeper const*, char const*, int, int, int) {}

ShadowMaskCtrl::ShadowMaskCtrl(bool) {}
void ShadowMaskCtrl::appendShadowMask(al::ShadowMaskBase*) {}
bool ShadowMaskCtrl::init(al::LiveActor*, al::ActorInitInfo const&, al::ByamlIter const&) {return true;}
bool ShadowMaskCtrl::init(al::LiveActor*, int) {return true;}
void ShadowMaskDirector::registerShadowMask(al::ShadowMaskBase*) {}

ShadowMaskBase::ShadowMaskBase(const char*) {}
void ShadowMaskBase::setDrawCategory(char const*) {}
void ShadowMaskBase::setHost(al::LiveActor const*) {}
ShadowMaskBase::~ShadowMaskBase() {}
void ShadowMaskBase::declare(ShadowMaskDrawCategory) {}
void ShadowMaskBase::update() {}
void ShadowMaskBase::initAfterPlacement() {}
void ShadowMaskBase::calcShadowMatrix(sead::Matrix34f*) {}
void ShadowMaskBase::createMtxConnector() {}
void ShadowMaskBase::readParam(const ByamlIter&) {}
void ShadowMaskBase::updateMulti() {}
void ShadowMaskBase::addMulti() {}

ShadowMaskCastOvalCylinder::ShadowMaskCastOvalCylinder(char const*) : al::ShadowMaskBase("") {}
ShadowMaskCastOvalCylinder::~ShadowMaskCastOvalCylinder() {}
void ShadowMaskCastOvalCylinder::declare(ShadowMaskDrawCategory) {}
void ShadowMaskCastOvalCylinder::update() {}
void ShadowMaskCastOvalCylinder::calcShadowMatrix(sead::Matrix34f*) {}
void ShadowMaskCastOvalCylinder::updateMulti() {}
void ShadowMaskCastOvalCylinder::addMulti() {}
ShadowMaskType ShadowMaskCastOvalCylinder::getShadowMaskType() const {return (ShadowMaskType)0;}

ShadowMaskCube::ShadowMaskCube(char const*) : al::ShadowMaskBase("") {}
ShadowMaskCube::~ShadowMaskCube() {}
void ShadowMaskCube::declare(ShadowMaskDrawCategory) {}
void ShadowMaskCube::update() {}
void ShadowMaskCube::calcShadowMatrix(sead::Matrix34f*) {}
void ShadowMaskCube::updateMulti() {}
void ShadowMaskCube::addMulti() {}
ShadowMaskType ShadowMaskCube::getShadowMaskType() const {return (ShadowMaskType)0;}

ShadowMaskCylinder::ShadowMaskCylinder(char const*) : al::ShadowMaskBase("") {}
ShadowMaskCylinder::~ShadowMaskCylinder() {}
void ShadowMaskCylinder::declare(ShadowMaskDrawCategory) {}
void ShadowMaskCylinder::update() {}
void ShadowMaskCylinder::calcShadowMatrix(sead::Matrix34f*) {}
void ShadowMaskCylinder::updateMulti() {}
void ShadowMaskCylinder::addMulti() {}
ShadowMaskType ShadowMaskCylinder::getShadowMaskType() const {return (ShadowMaskType)0;}

ShadowMaskSphere::ShadowMaskSphere(char const*) : al::ShadowMaskBase("") {}
ShadowMaskSphere::~ShadowMaskSphere() {}
void ShadowMaskSphere::declare(ShadowMaskDrawCategory) {}
void ShadowMaskSphere::update() {}
void ShadowMaskSphere::calcShadowMatrix(sead::Matrix34f*) {}
void ShadowMaskSphere::updateMulti() {}
void ShadowMaskSphere::addMulti() {}
ShadowMaskType ShadowMaskSphere::getShadowMaskType() const {return (ShadowMaskType)0;}

SimpleCircleShadowXZ::SimpleCircleShadowXZ(char const*) : LiveActor("") {}
void SimpleCircleShadowXZ::initSimpleCircleShadow(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*) {}
void SimpleCircleShadowXZ::makeActorAlive() {}
void SimpleCircleShadowXZ::control() {}

ActorOcclusionKeeper::ActorOcclusionKeeper(al::GraphicsSystemInfo const*, al::Resource const*, al::LiveActor const*, char const*) {}
bool ActorOcclusionKeeper::isExistFile(al::Resource const*, char const*) {return false;}
void ActorOcclusionKeeper::appear(bool) {}
void ActorOcclusionKeeper::hideModel() {}
void ActorOcclusionKeeper::requestKill() {}
void ActorOcclusionKeeper::updateAndRequest() {}

ActorPrePassLightKeeper::ActorPrePassLightKeeper(al::LiveActor*) {}
void ActorPrePassLightKeeper::init(al::Resource const*, al::ActorInitInfo const&, char const*) {}
bool ActorPrePassLightKeeper::isExistFile(al::Resource const*, char const*) {return false;}
void ActorPrePassLightKeeper::appear(bool) {}
void ActorPrePassLightKeeper::hideModel() {}
void ActorPrePassLightKeeper::requestKill() {}

al::GraphicsSystemInfo::GraphicsSystemInfo() : mInitArg(nullptr, nullptr) {}
void al::GraphicsSystemInfo::clearGraphicsRequest() {}
void al::GraphicsSystemInfo::endInit() {}
void al::GraphicsSystemInfo::init(al::GraphicsInitArg const&, al::AreaObjDirector*, al::ExecuteDirector*, al::EffectSystem*, al::PlayerHolder*, al::SceneCameraInfo*, al::ShaderHolder*) {}
void al::GraphicsSystemInfo::initAfterPlacement() {}
void al::GraphicsSystemInfo::preDrawGraphics(al::SceneCameraInfo*) {}
void al::GraphicsSystemInfo::updateGraphics() {}
al::GraphicsSystemInfo::~GraphicsSystemInfo() {}

al::GraphicsInitArg::GraphicsInitArg(agl::DrawContext*, sead::FrameBuffer*) {}

al::ModelDisplayListController::ModelDisplayListController(al::ModelGroup*) {}
al::ModelDrawBufferUpdater::ModelDrawBufferUpdater(al::ExecuteDirector const*) {}
al::ModelDrawBufferUpdater::~ModelDrawBufferUpdater() {}
bool al::ModelDrawBufferUpdater::tryUpdateAsync() { return false; }
void al::ModelDrawBufferUpdater::waitAsync() const {}
al::ModelGroup::ModelGroup(int) {}
al::ModelGroup::~ModelGroup() {}
void al::ModelGroup::registerModel(al::ModelKeeper*) {}

al::ModelDrawParts::ModelDrawParts(char const*, al::LiveActor const*, al::ActorInitInfo const&, char const*) : al::LiveActor("") {}
void al::ModelMaterialCategory::tryCreate(al::ModelCtrl*, char const*, al::MaterialCategoryKeeper*) {}

void al::ShadowDirector::endInit() {}
void al::SkyDirector::init(al::ActorInitInfo const&) {}
void al::SkyDirector::update() {}

void al::ModelDisplayListController::update() {}
void al::ModelOcclusionCullingDirector::calc() {}

void al::ModelLodAllCtrl::registerLodCtrl(al::ModelLodCtrl*) {}
al::ModelLodCtrl::ModelLodCtrl(al::IUseCamera*, sead::Vector3<float> const*, sead::Matrix34<float> const*, sead::Vector3<float> const*, sead::BoundBox3<float> const&, int) {}
void al::ModelLodCtrl::init(al::ByamlIter const&) {}
void al::ModelMaterialCategory::tryCreate(al::ModelCtrl*, al::Resource const*, char const*, al::MaterialCategoryKeeper*) {}
al::ModelOcclusionQuery* al::ModelOcclusionQuery::tryCreate(al::LiveActor*, al::Resource*, char const*) {
    WARN_UNIMPL;
    return nullptr;
}
al::ActorDitherAnimator* al::ActorDitherAnimator::tryCreate(al::LiveActor*, al::Resource const*, char const*) {
    WARN_UNIMPL;
    return nullptr;
}
al::FarDistanceDitherAnimator* al::FarDistanceDitherAnimator::tryCreate(al::LiveActor*, al::Resource const*, char const*) {
    WARN_UNIMPL;
    return nullptr;
}
agl::DrawContext* al::GraphicsSystemInfo::getDrawContext() const {
    WARN_UNIMPL;
    return nullptr;
}

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

void invalidateClipping(al::LiveActor*) {}

void setMaterialProgrammable(al::LiveActor*) {}

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

bool AnimPlayerSkl::startSklAnim(char const*, char const*, char const*, char const*, char const*,
                                 char const*, char const*) {return false;}

bool AnimPlayerSkl::isSklAnimExist(char const*) {return false;}

const char* AnimPlayerSkl::getPlayingSklAnimName(int) {return "";}

void AnimPlayerSkl::reset() {}

bool AnimPlayerSkl::isSklAnimEnd(int) {return false;}

bool AnimPlayerSkl::isSklAnimOneTime(char const*) {return false;}

bool AnimPlayerSkl::isSklAnimOneTime(int) {return false;}

bool AnimPlayerSkl::isSklAnimPlaying(int) {return false;}

f32 AnimPlayerSkl::getSklAnimFrame(int) {return 0.0f;}

f32 AnimPlayerSkl::getSklAnimFrameRate(int) {return 0.0f;}

f32 AnimPlayerSkl::getSklAnimFrameMax(int) {return 0.0f;}

f32 AnimPlayerSkl::getSklAnimFrameMax(char const*) {return 0.0f;}

void AnimPlayerSkl::setSklAnimFrame(int, float) {}

void AnimPlayerSkl::setSklAnimFrameRate(int, float) {}

s32 AnimPlayerSkl::getSklAnimBlendNum() {return 0;}

f32 AnimPlayerSkl::getSklAnimBlendWeight(int) {return 0.0f;}

bool AnimPlayerSkl::calcSklAnim() {return false;}

bool ActionAnimCtrl::isExistAction(char const*) {return false;}

void AnimPlayerSimple::startAnim(char const*) {}

void AnimPlayerSimple::setAnimFrame(float) {}

void AnimPlayerSimple::setAnimFrameRate(float) {}

bool AnimPlayerSimple::isAnimExist(char const*) {return false;}

const char* AnimPlayerSimple::getPlayingAnimName() {return "";}

void AnimPlayerSimple::clearAnim() {}

bool AnimPlayerSimple::isAnimEnd() {return false;}

bool AnimPlayerSimple::isAnimOneTime(char const*) {return false;}

bool AnimPlayerSimple::isAnimOneTime() {return false;}

bool AnimPlayerSimple::isAnimPlaying() {return false;}

f32 AnimPlayerSimple::getAnimFrame() {return 0.0f;}

f32 AnimPlayerSimple::getAnimFrameRate() {return 0.0f;}

f32 AnimPlayerSimple::getAnimFrameMax() {return 0.0f;}

f32 AnimPlayerSimple::getAnimFrameMax(char const*) {return 0.0f;}

void AnimPlayerSkl::startPartialAnim(char const*, int, int, SklAnimRetargettingInfo const*) {}

void AnimPlayerSkl::prepareAnimInterpDirect(int) {}

void AnimPlayerSkl::clearPartialAnim(int) {}

bool AnimPlayerSkl::isPartialAnimEnd(int) {return false;}

bool AnimPlayerSkl::isPartialAnimOneTime(int) {return false;}

bool AnimPlayerSkl::isPartialAnimAttached(int) {return false;}

const char* AnimPlayerSkl::getPlayingPartialSklAnimName(int) {return "";}

f32 AnimPlayerSkl::getPartialAnimFrame(int) {return 0.0f;}

void AnimPlayerSkl::setPartialAnimFrame(int, float) {}

f32 AnimPlayerSkl::getPartialAnimFrameRate(int) {return 0.0f;}

void AnimPlayerSkl::setPartialAnimFrameRate(int, float) {}

void AnimPlayerSkl::setSklAnimBlendWeight(int, float) {}

void ShadowMaskCtrl::validate() {}

void ShadowMaskCtrl::invalidate() {}

}  // namespace al

void al::ClippingActorHolder::addToClippingTarget(al::LiveActor*) {}
void al::ClippingActorHolder::removeFromClippingTarget(al::LiveActor*) {}
