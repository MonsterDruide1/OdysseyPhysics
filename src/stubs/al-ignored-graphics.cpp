#include "Library/Clipping/ClippingActorHolder.h"
#include "Library/Draw/GraphicsSystemInfo.h"
#include "Library/Execute/ExecuteTableHolderUpdate.h"
#include "Library/Joint/JointControllerBase.h"
#include "Library/KeyPose/KeyPoseKeeper.h"
#include "Library/Layout/LayoutActorUtil.h"
#include "Library/Layout/LayoutInitInfo.h"
#include "Library/Layout/LayoutKeeper.h"
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
#include "Library/Model/ModelDrawerBase.h"
#include "Library/Model/ModelDrawerForward.h"
#include "Library/Model/ModelDrawerDeferred.h"
#include "Library/Model/ModelDrawerDeferredSilhouette.h"
#include "Library/Model/ModelDrawerDeferred.h"
#include "Library/Model/ModelDrawerDepthShadow.h"
#include "Library/Model/ModelDrawerStaticDepthShadow.h"
#include "Library/Model/ModelDrawerDepthOnly.h"
#include "Library/Model/ModelDrawerPrepassCulling.h"
#include "Library/Model/ModelDrawerDeferredSky.h"
#include "Library/Model/ModelDrawerDeferredFootPrint.h"
#include "Library/Model/ModelDrawerWorldAo.h"
#include "Library/Model/ModelDrawerBufferUpdate.h"
#include "Library/Model/ModelDrawerChromakey.h"
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
#include "Library/Texture/TextureUtil.h"
#include "Project/Action/ActionEffectCtrl.h"
#include "Project/Action/ActionScreenEffectCtrl.h"
#include "Project/Clipping/ClippingFunction.h"
#include "Project/Light/ActorPrepassLightKeeper.h"
#include "FootPrintHolder.h"

namespace al {

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
const char* getModelName(al::LiveActor const*) {return "";}
s32 getMaterialCount(al::LiveActor const*) {return 0;}
const char* getMaterialName(al::LiveActor const*, int) {return "";}
void setModelMaterialParameterV4F(al::LiveActor const*, char const*, char const*, sead::Vector4<float> const&) {}
void tryInitFixedModelGpuBuffer(LiveActor*) {}
void showModel(al::LiveActor*) {}
void hideModel(al::LiveActor*) {}
void hideSilhouetteModel(al::LiveActor*) {}
void validateDitherAnim(al::LiveActor*) {}
void setModelAlphaMask(LiveActor*, float) {}
void setModelMaterialParameterF32(al::LiveActor const*, char const*, char const*, float) {}
void stopDitherAnimAutoCtrl(al::LiveActor*) {}
bool tryExpandClippingByDepthShadowLength(al::LiveActor*, sead::Vector3<float>*) {return false;}
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
bool isExistDepthShadowMapCtrl(al::LiveActor*) {return false;}
bool isHideModel(LiveActor const*) {return false;}
void hideModelIfShow(LiveActor*) {}
void showModelIfHide(LiveActor*) {}
void invalidateClipping(al::LiveActor*) {}
void setMaterialProgrammable(al::LiveActor*) {}
s32 getMaterialIndex(al::LiveActor const*, char const*) {return 0;}
f32 getShadowMaskIntensity(al::LiveActor const*, char const*) {return 0.0f;}
bool blinkModel(al::LiveActor*, int, int, int) {return false;}
void updateDepthShadowMapCtrlShapeVisible(al::LiveActor*) {}
void validateDepthShadowMap(al::LiveActor*) {}
f32 getShadowMaskDropLength(al::LiveActor const*, char const*) {return 0.0f;}
void setShadowMaskDropLength(al::LiveActor*, float) {}
void invalidateShadowMask(al::LiveActor*) {}
void invalidateShadowMask(al::LiveActor*, char const*) {}
bool isExistShadow(al::LiveActor*) {return false;}
void setShadowMaskOffset(al::LiveActor const*, sead::Vector3<float> const&, char const*) {}
void showShadow(al::LiveActor*) {}
void validateShadowMask(al::LiveActor*) {}
bool isJudgedToClipFrustum(al::LiveActor const*, sead::Vector3<float> const&, float, float) {return false;}
void calcJointPos(sead::Vector3f* a, al::LiveActor const*, char const*) {a->set(sead::Vector3f::zero);}
void calcJointScale(sead::Vector3f* a,al::LiveActor const*,char const*) {a->set(sead::Vector3f::ones);}
void initJointGlobalQuatController(al::LiveActor const*,sead::Quatf const*,char const*) {}
bool isExistJoint(al::LiveActor const*, char const*) {return true;}
void registerJointController(const al::LiveActor*, al::JointControllerBase*) {}
void registerJointController(const al::LiveActor*, al::JointControllerBase*, const char*) {}
void calcLayoutPosFromWorldPos(sead::Vector2f* a, al::IUseCamera const*, sead::Vector3f const&) {a->set(sead::Vector2f::zero);}
void updateMaterialCodePuddle(al::LiveActor*) {}
const agl::TextureData* getWhite2DTexture() {WARN_UNIMPL; return nullptr;}
void recreateModelDisplayList(al::LiveActor const*) {}
void invalidateOcclusionQuery(al::LiveActor*) {}
bool isValidOcclusionQuery(al::LiveActor const*) {return false;}
void setDepthShadowMapLength(al::LiveActor const*, float, char const*) {}
nn::ui2d::TextureInfo* createTextureInfo(char const*, char const*, char const*) {WARN_UNIMPL; return nullptr;}

SEAD_SINGLETON_DISPOSER_IMPL(ShaderHolder);
ShaderHolder::ShaderHolder() {}

DepthShadowMapCtrl::DepthShadowMapCtrl(al::Resource const*) {}
DepthShadowMapCtrl::~DepthShadowMapCtrl() {}
void DepthShadowMapCtrl::show() {}
void DepthShadowMapCtrl::hide() {}
void DepthShadowMapCtrl::update() {}
void DepthShadowMapCtrl::initAfterPlacement(al::GraphicsSystemInfo*) {}
void DepthShadowMapCtrl::appendDepthShadowMapInfo(char const*, int, int, int, float, bool, sead::Vector3<float> const&, bool, sead::Vector3<float> const&, sead::Vector3<float> const&, bool, char const*, int, bool, float, float, float, bool, bool, float, int, bool, bool, float) {}
void DepthShadowMapCtrl::init(al::LiveActor*, al::ByamlIter const&) {}
void DepthShadowMapCtrl::initWithoutIter(al::LiveActor*, int) {}

void DepthShadowMapDirector::createDepthShadowMap(al::DepthShadowMapCtrl const*, al::ModelKeeper const*, char const*, int, int, int) {}

ShadowMaskCtrl::ShadowMaskCtrl(bool) {}
void ShadowMaskCtrl::show() {}
void ShadowMaskCtrl::hide() {}
void ShadowMaskCtrl::initAfterPlacement() {}
void ShadowMaskCtrl::appendShadowMask(al::ShadowMaskBase*) {}
bool ShadowMaskCtrl::init(al::LiveActor*, al::ActorInitInfo const&, al::ByamlIter const&) {return true;}
bool ShadowMaskCtrl::init(al::LiveActor*, int) {return true;}
void ShadowMaskCtrl::validate() {}
void ShadowMaskCtrl::invalidate() {}

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
void ActorPrePassLightKeeper::initAfterPlacement() {}
bool ActorPrePassLightKeeper::isExistFile(al::Resource const*, char const*) {return false;}
void ActorPrePassLightKeeper::appear(bool) {}
void ActorPrePassLightKeeper::hideModel() {}
void ActorPrePassLightKeeper::requestKill() {}

al::GraphicsSystemInfo::GraphicsSystemInfo() : mInitArg(nullptr, nullptr) {}
void al::GraphicsSystemInfo::clearGraphicsRequest() {}
void al::GraphicsSystemInfo::endInit() {}
void al::GraphicsSystemInfo::init(al::GraphicsInitArg const&, al::AreaObjDirector*, al::ExecuteDirector*, al::EffectSystem*, al::PlayerHolder*, al::SceneCameraInfo*, al::ShaderHolder*) {}
void al::GraphicsSystemInfo::initAfterPlacement() {}
void al::GraphicsSystemInfo::preDrawGraphics(const al::SceneCameraInfo*) {}
void al::GraphicsSystemInfo::updateGraphics() {}
al::GraphicsSystemInfo::~GraphicsSystemInfo() {}
void al::GraphicsSystemInfo::initStageResource(al::Resource const*, char const*, char const*) {}

al::GraphicsInitArg::GraphicsInitArg(agl::DrawContext*, sead::FrameBuffer*) {}

al::ModelDisplayListController::ModelDisplayListController(al::ModelGroup*) {}
void al::ModelDisplayListController::update() {}

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

void al::ModelOcclusionCullingDirector::calc() {}

void al::ModelLodAllCtrl::registerLodCtrl(al::ModelLodCtrl*) {}
al::ModelLodCtrl::ModelLodCtrl(al::IUseCamera*, sead::Vector3<float> const*, sead::Matrix34<float> const*, sead::Vector3<float> const*, sead::BoundBox3<float> const&, int) {}
void al::ModelLodCtrl::init(al::ByamlIter const&) {}

void al::ModelMaterialCategory::tryCreate(al::ModelCtrl*, al::Resource const*, char const*, al::MaterialCategoryKeeper*) {}
al::ModelOcclusionQuery* al::ModelOcclusionQuery::tryCreate(al::LiveActor*, al::Resource*, char const*) {WARN_UNIMPL;return nullptr;}
al::ActorDitherAnimator* al::ActorDitherAnimator::tryCreate(al::LiveActor*, al::Resource const*, char const*) {WARN_UNIMPL;return nullptr;}
al::FarDistanceDitherAnimator* al::FarDistanceDitherAnimator::tryCreate(al::LiveActor*, al::Resource const*, char const*) {WARN_UNIMPL;return nullptr;}
agl::DrawContext* al::GraphicsSystemInfo::getDrawContext() const {WARN_UNIMPL;return nullptr;}

FootPrintHolder::FootPrintHolder(al::LiveActor*, char const*, al::HitSensor*,
                                 al::FootPrintServer*) {}

void ClippingActorHolder::addToClippingTarget(al::LiveActor*) {}
void ClippingActorHolder::removeFromClippingTarget(al::LiveActor*) {}

void LayoutKeeper::draw() {}

ModelDrawerBase::ModelDrawerBase(const char* name) : mName(name) {}
ModelDrawerBase::~ModelDrawerBase() {}
void ModelDrawerBase::registerModel(ModelCtrl* model) {}
void ModelDrawerBase::addModel(ModelCtrl* model) {}
void ModelDrawerBase::removeModel(ModelCtrl* model) {}
void ModelDrawerBase::updateModel(ModelCtrl* model) {}
void ModelDrawerBase::setDrawInfo(agl::DrawContext*, al::GraphicsSystemInfo const*, al::ModelDrawBufferCounter const*, al::ModelKeeper const*) {}

ModelDrawerForward::ModelDrawerForward(char const* name, bool, bool, bool, bool, bool, bool) : ModelDrawerBase(name) {}
void ModelDrawerForward::createTable() {}
void ModelDrawerForward::draw() const {}
void ModelDrawerForward::addModel(ModelCtrl*) {}
void ModelDrawerForward::removeModel(ModelCtrl*) {}

ModelDrawerDeferred::ModelDrawerDeferred(char const* name, bool, bool, bool, bool) : ModelDrawerBase(name) {}
void ModelDrawerDeferred::createTable() {}
void ModelDrawerDeferred::draw() const {}
void ModelDrawerDeferred::addModel(ModelCtrl*) {}
void ModelDrawerDeferred::removeModel(ModelCtrl*) {}

ModelDrawerDeferredSilhouette::ModelDrawerDeferredSilhouette(char const* name, al::SilhouetteDrawCategory) : ModelDrawerBase(name) {}
void ModelDrawerDeferredSilhouette::createTable() {}
void ModelDrawerDeferredSilhouette::draw() const {}

ModelDrawerDepthShadow::ModelDrawerDepthShadow(char const* name, bool, bool) : ModelDrawerBase(name) {}
void ModelDrawerDepthShadow::createTable() {}
void ModelDrawerDepthShadow::registerModel(ModelCtrl*) {}
void ModelDrawerDepthShadow::addModel(ModelCtrl*) {}
void ModelDrawerDepthShadow::updateModel(ModelCtrl*) {}
void ModelDrawerDepthShadow::draw() const {}

ModelDrawerStaticDepthShadow::ModelDrawerStaticDepthShadow(char const* name) : ModelDrawerBase(name) {}
void ModelDrawerStaticDepthShadow::createTable() {}
void ModelDrawerStaticDepthShadow::addModel(ModelCtrl*) {}
void ModelDrawerStaticDepthShadow::removeModel(ModelCtrl*) {}
void ModelDrawerStaticDepthShadow::draw() const {}

ModelDrawerDepthOnly::ModelDrawerDepthOnly(char const* name, bool, bool, bool, bool, bool) : ModelDrawerBase(name) {}
void ModelDrawerDepthOnly::createTable() {}
void ModelDrawerDepthOnly::draw() const {}
void ModelDrawerDepthOnly::registerModel(ModelCtrl*) {}
void ModelDrawerDepthOnly::addModel(ModelCtrl*) {}
void ModelDrawerDepthOnly::removeModel(ModelCtrl*) {}
void ModelDrawerDepthOnly::updateModel(ModelCtrl*) {}
void ModelDrawerDepthOnly::createTableCulling() {}

ModelDrawerPrepassCulling::ModelDrawerPrepassCulling(char const* name) : ModelDrawerBase(name) {}
void ModelDrawerPrepassCulling::createTable() {}
void ModelDrawerPrepassCulling::draw() const {}
void ModelDrawerPrepassCulling::registerModel(ModelCtrl*) {}
void ModelDrawerPrepassCulling::addModel(ModelCtrl*) {}
void ModelDrawerPrepassCulling::updateModel(ModelCtrl*) {}

ModelDrawerDeferredSky::ModelDrawerDeferredSky(char const* name) : ModelDrawerBase(name) {}
void ModelDrawerDeferredSky::createTable() {}
void ModelDrawerDeferredSky::draw() const {}

ModelDrawerDeferredFootPrint::ModelDrawerDeferredFootPrint(char const* name) : ModelDrawerBase(name) {}
void ModelDrawerDeferredFootPrint::createTable() {}
void ModelDrawerDeferredFootPrint::draw() const {}

ModelDrawerWorldAo::ModelDrawerWorldAo(char const* name) : ModelDrawerBase(name) {}
void ModelDrawerWorldAo::createTable() {}
void ModelDrawerWorldAo::draw() const {}
void ModelDrawerWorldAo::addModel(ModelCtrl*) {}
void ModelDrawerWorldAo::removeModel(ModelCtrl*) {}

ModelDrawerBufferUpdate::ModelDrawerBufferUpdate(char const* name) : ModelDrawerBase(name) {}
void ModelDrawerBufferUpdate::draw() const {}
void ModelDrawerBufferUpdate::createTable() {}

ModelDrawerChromakey::ModelDrawerChromakey(char const* name, bool, bool, bool, bool) : ModelDrawerBase(name) {}
void ModelDrawerChromakey::createTable() {}
void ModelDrawerChromakey::registerModel(ModelCtrl*) {}
void ModelDrawerChromakey::draw() const {}

void ActionEffectCtrl::update(float, float, float, bool) {}
void ActionScreenEffectCtrl::update(float, float, float, bool) {}

TextureReplacer::TextureReplacer(agl::TextureData const*) {}
void TextureReplacer::replace(al::LiveActor*, char const*, char const*) {}
void TextureReplacer::update() {}

}  // namespace al
