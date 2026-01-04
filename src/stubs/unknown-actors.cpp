#include "Item/CoinCollectHolder.h"
#include "Library/Action/ActorActionKeeper.h"
#include "Library/Base/StringUtil.h"
#include "Library/Camera/CameraUtil.h"
#include "Library/Collision/Collider.h"
#include "Library/Collision/CollisionDirector.h"
#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/CollisionPartsKeeperUtil.h"
#include "Library/Collision/KCollisionServer.h"
#include "Library/Collision/PartsConnector.h"
#include "Library/Collision/PartsConnectorUtil.h"
#include "Library/Controller/InputFunction.h"
#include "Library/Event/EventFlowUtil.h"
#include "Library/Joint/JointControllerKeeper.h"
#include "Library/LiveActor/ActorCollisionFunction.h"
#include "Library/LiveActor/ActorInitFunction.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/ActorResourceFunction.h"
#include "Library/LiveActor/ActorSceneInfo.h"
#include "Library/LiveActor/ActorSensorUtil.h"
#include "Library/Math/MathUtil.h"
#include "Library/Matrix/MatrixUtil.h"
#include "Library/Nature/NatureUtil.h"
#include "Library/Obj/PartsFunction.h"
#include "Library/Player/PlayerUtil.h"
#include "Library/PostProcessing/CameraBlurController.h"
#include "Library/Rail/RailUtil.h"
#include "Library/Resource/ActorResource.h"
#include "Library/Resource/Resource.h"
#include "Library/Resource/ResourceFunction.h"
#include "Library/Scene/SceneMsgCtrl.h"
#include "Library/Screen/ScreenFunction.h"
#include "Library/Screen/ScreenPointDirector.h"
#include "Library/Screen/ScreenPointKeeper.h"
#include "Library/Se/SeFunction.h"
#include "Library/Shadow/ActorShadowUtil.h"
#include "Library/Yaml/ParameterBase.h"
#include "MapObj/AnagramAlphabet.h"
#include "MapObj/RouteGuideDirector.h"
#include "Player/HackerJudge.h"
#include "Player/PlayerCarryKeeper.h"
#include "Player/PlayerInput.h"
#include "Project/Action/ActionBgmCtrl.h"
#include "Project/Action/ActionEffectCtrl.h"
#include "Project/Action/ActionFlagCtrl.h"
#include "Project/Action/ActionPadAndCameraCtrl.h"
#include "Project/Action/ActionScreenEffectCtrl.h"
#include "Project/Action/ActionSeCtrl.h"
#include "Project/Action/InitResourceDataAction.h"
#include "Project/Action/InitResourceDataActionAnim.h"
#include "Project/Anim/InitResourceDataAnim.h"
#include "Project/Resource/ResourceSystem.h"
#include "System/GameDataFile.h"
#include "System/HintPhotoData.h"
#include "System/NetworkUploadFlag.h"
#include "System/ShopTalkData.h"
#include "System/VisitStageData.h"
#include "System/WorldWarpTalkData.h"
#include "Util/DemoUtil.h"
#include "Util/Hack.h"
#include "Util/InputInterruptTutorialUtil.h"
#include "Util/NpcEventFlowUtil.h"
#include "Util/ObjUtil.h"
#include "Util/PlayerCollisionUtil.h"
#include "Project/Joint/RollingCubePoseKeeperUtil.h"
#include "Project/LiveActor/ConveyerKeyKeeper.h"
#include "Scene/GuidePosInfoHolder.h"
#include "Scene/ProjectAppearSwitchFactory.h"
#include "System/GameDataFunction.h"
#include "System/GameDataUtil.h"
#include "Util/NpcAnimUtil.h"
#include "Util/PlayerUtil.h"
#include "Util/ScenePrepoFunction.h"
#include "Util/SensorMsgFunction.h"

// HIGH PRIORITY
CoinCollectHolder::CoinCollectHolder() {WARN_UNIMPL;}
const char* CoinCollectHolder::getSceneObjName() const {WARN_UNIMPL;return "";}
bool GameDataFunction::isOnObjNoWriteSaveDataResetMiniGame(GameDataHolderAccessor, al::PlacementId const*) {WARN_UNIMPL;return false;}
bool rs::isNearPlayerH(al::LiveActor const*, float) {WARN_UNIMPL;return false;}
bool rs::findWallCatchPosWallHit(al::CollisionParts const**, sead::Vector3<float>*, sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float, float, float, float, float, float, float) {WARN_UNIMPL;return false;}
sead::Matrix34f* al::getJointMtxPtr(al::LiveActor const* a, char const*) {WARN_UNIMPL; return a->getPoseKeeper()->getMtxPtr();}
bool alCollisionUtil::getFirstPolyOnArrow(al::IUseCollision const*, sead::Vector3f*, al::Triangle*, sead::Vector3f const&, sead::Vector3f const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*) {WARN_UNIMPL;return false;}
al::ICollisionPartsKeeper* alCollisionUtil::getCollisionPartsKeeper(al::IUseCollision const* c) {return c->getCollisionDirector()->getActivePartsKeeper();}
void al::CollisionParts::validateBySystem() {WARN_UNIMPL;}
void al::CollisionParts::invalidateBySystem() {WARN_UNIMPL;}
al::Collider::Collider(CollisionDirector*, const sead::Matrix34f*, const sead::Vector3f*, const sead::Vector3f*, f32, f32, u32) {WARN_UNIMPL;}
void al::Collider::onInvalidate() {WARN_UNIMPL;}
void al::Collider::setCollisionPartsFilter(al::CollisionPartsFilterBase const*) {WARN_UNIMPL;}
const sead::Vector3f& al::Collider::getRecentOnGroundNormal(u32) const {WARN_UNIMPL; return sead::Vector3f::ey;}
sead::Vector3f al::Collider::collide(sead::Vector3<float> const&) {WARN_UNIMPL; return sead::Vector3f::zero;}
al::InitResourceDataAction* al::InitResourceDataAction::tryCreate(al::Resource*, al::InitResourceDataAnim const*, char const*) {WARN_UNIMPL;return nullptr;}
al::InitResourceDataAnim* al::InitResourceDataAnim::tryCreate(al::Resource*, al::Resource*) {WARN_UNIMPL;return nullptr;}

// MathUtil.o
al::Axis al::calcNearVecFromAxis3(sead::Vector3f*, sead::Vector3f const&, sead::Quatf const&) {CRASH}
void al::calcQuatLocalAxis(sead::Vector3f*, sead::Quatf const&, int) {CRASH}
void al::turnQuatYDirRate(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, float) {CRASH}
void al::rotateVectorDegree(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, float) {CRASH}
void al::limitVectorParallelVertical(sead::Vector3<float>*, sead::Vector3<float> const&, float, float) {CRASH}
void al::limitVectorSeparateHV(sead::Vector3<float>*, sead::Vector3<float> const&, float, float) {CRASH}
bool al::turnQuatFrontToDirDegreeH(sead::Quat<float>*, sead::Vector3<float> const&, float) {CRASH}
void al::calcVectorSeparateHV(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float) {CRASH}
void al::rotateVectorDegreeY(sead::Vector3f*, float) {CRASH}
void al::rotateVectorQuat(sead::Vector3f*, sead::Quatf const&) {CRASH}
void al::getRandomDirH(sead::Vector3f*,sead::Vector3f const&) {CRASH}
void al::calcFittingBoxPose(sead::Quat<float>*, sead::BoundBox3<float> const&, sead::Quat<float> const&, sead::Quat<float> const&) {CRASH}
void al::calcQuatLocalAxisAll(sead::Quat<float> const&, sead::Vector3<float>*, sead::Vector3<float>*, sead::Vector3<float>*) {CRASH}
void al::rotateQuatAndTransDegree(sead::Quat<float>*, sead::Vector3<float>*, sead::Quat<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::calcSphereMargeSpheres(sead::Vector3<float>*, float*, sead::Vector3<float> const&, float, sead::Vector3<float> const&, float) {CRASH}
void al::calcBoxFacePoint(sead::Vector3<float>*, sead::BoundBox3<float> const&, int, sead::Quat<float> const&, sead::Vector3<float> const&) {CRASH}
bool al::turnQuatWithAxisDegree(sead::Quat<float>*, sead::Quat<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
// MtxUtil.o
void al::makeMtxProj(sead::Matrix44f*, sead::Vector2f const&, sead::Vector3f const&, sead::Vector3f const&) {CRASH}

// NORMAL PRIORITY
AnagramAlphabet::AnagramAlphabet(const char* name) : al::LiveActor(name) {}
void AnagramAlphabet::init(const al::ActorInitInfo&) {}
const char* GameDataFunction::getCurrentStageName(GameDataHolderAccessor) {CRASH}
s32 GameDataFunction::getScenarioNo(al::LiveActor const*) {CRASH}
void al::calcLayoutPosFromWorldPos(sead::Vector2f*, al::IUseCamera const*, sead::Vector3f const&) {CRASH}
void al::calcMtxLandEffect(sead::Matrix34f*, al::RollingCubePoseKeeper const*, sead::Quatf const&, sead::Vector3f const&) {CRASH}
void al::calcRollingCubeClippingInfo(sead::Vector3f*, float*, al::RollingCubePoseKeeper const*, float) {CRASH}
al::CollisionObj* al::createCollisionObj(al::LiveActor const*, al::ActorInitInfo const&, char const*, al::HitSensor*, char const*, char const*) {CRASH}
void al::multVecInvQuat(sead::Vector3f*, al::LiveActor const*, sead::Vector3f const&) {CRASH}

const sead::Vector3f& rs::getPlayerPos(al::LiveActor const*) {CRASH}
const sead::Vector3f& rs::getPlayerBodyPos(al::LiveActor const*) {CRASH}

bool al::calcFindFireSurface(sead::Vector3f*, sead::Vector3f*, al::LiveActor const*, sead::Vector3f const&, sead::Vector3f const&, float) {CRASH}
void rs::setBossBarrierField(BarrierField*) {CRASH}

void al::calcJointPos(sead::Vector3f*, al::LiveActor const*, char const*) {CRASH}
void al::calcJointScale(sead::Vector3f*,al::LiveActor const*,char const*) {CRASH}
void al::initJointGlobalQuatController(al::LiveActor const*,sead::Quatf const*,char const*) {CRASH}
bool al::isExistJoint(al::LiveActor const*, char const*) {CRASH}

al::Triangle* al::Collider::getPlane(int) const {CRASH}
bool al::isNearAngleRadianHV(sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float) {CRASH}

bool al::isActive(al::EventFlowExecutor const*) {CRASH}
al::EventFlowExecutor* rs::initEventFlow(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*) {CRASH}
void rs::resetRouteHeadGuidePosPtr(al::IUseSceneObjHolder const*) {CRASH}
void rs::setNpcMaterialAnimFromPlacementInfo(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void rs::setRouteHeadGuidePosPtr(al::IUseSceneObjHolder const*, sead::Vector3<float> const*) {CRASH}
void rs::startEventFlow(al::EventFlowExecutor*, char const*) {CRASH}
bool rs::updateEventFlow(al::EventFlowExecutor*) {CRASH}

al::NatureDirector::NatureDirector() {CRASH}
void al::NatureDirector::init() {CRASH}
al::SceneMsgCtrl::SceneMsgCtrl() {CRASH}
al::SceneMsg::SceneMsg() {CRASH}

void sead::DirectCamera::doUpdateMatrix(sead::Matrix34<float>*) const {CRASH}

void rs::offRouteGuideByActor(al::LiveActor*) {CRASH}
void rs::onRouteGuideByActor(al::LiveActor*) {CRASH}
const char* ProjectAppearSwitchFactory::convertName(const char*) const {CRASH}

void al::ParameterBase::tryGetParam(al::ByamlIter const&) {CRASH}
bool al::ParameterBase::copyLerp(al::ParameterBase const&, al::ParameterBase const&, float) {CRASH}
bool al::ParameterBase::copy(al::ParameterBase const&) {CRASH}
bool al::ParameterBase::isEqual(al::ParameterBase const&) {CRASH}
void al::ParameterBase::afterGetParam() {CRASH}
void al::ParameterBase::initialize(const sead::SafeString& name, const sead::SafeString& label,
                                   const sead::SafeString& meta, bool e) {CRASH}
void al::ParameterBase::initializeListNode(const sead::SafeString& name,
                                           const sead::SafeString& label,
                                           const sead::SafeString& meta, al::ParameterObj* obj,
                                           bool e) {CRASH}

void al::ScreenPointDirector::setCheckGroup(al::ScreenPointTarget*) {CRASH}
void al::ScreenPointDirector::registerTarget(al::ScreenPointTarget*) {CRASH}
void rs::moveInertiaSlideOnSkate(sead::Vector3<float>*, al::LiveActor*, IUsePlayerCollision const*, sead::Vector3<float> const&, float, float, float, float, float, float, float) {CRASH}

bool al::isSensorValid(al::HitSensor const*) {CRASH}
s64 rs::prepo::generateSaveDataId() {CRASH}

void al::calcTouchScreenPos(sead::Vector2f*) {CRASH}
void al::updateMaterialCodePuddle(al::LiveActor*) {CRASH}

bool alCollisionUtil::getHitPosOnArrow(al::IUseCollision const*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*) {CRASH}
al::CollisionParts* alCollisionUtil::getStrikeArrowCollisionParts(al::IUseCollision const*, sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*) {CRASH}

void al::CollisionParts::calcForceRotatePower(sead::Quatf*) const {CRASH}
const al::LiveActor* al::CollisionParts::getConnectedHost() const {CRASH}
void al::CollisionParts::resetAllMtx() {CRASH}
void al::CollisionParts::invalidateByUser() {CRASH}
void al::CollisionParts::validateByUser() {CRASH}

al::CollisionDirector* al::Collider::getCollisionDirector() const {CRASH}
void al::Collider::calcCheckPos(sead::Vector3<float>*) const {CRASH}
void al::Collider::setTriangleFilter(al::TriangleFilterBase const*) {CRASH}

bool al::CollisionPartsFilterActor::isInvalidParts(CollisionParts*) {CRASH}
bool al::CollisionPartsFilterSpecialPurpose::isInvalidParts(CollisionParts* collisionParts) {CRASH}
bool al::CollisionPartsFilterMergePair::isInvalidParts(CollisionParts* collisionParts) {CRASH}
bool al::CollisionPartsFilterIgnoreOptionalPurpose::isInvalidParts(CollisionParts* collisionParts) {CRASH}
bool al::CollisionPartsFilterSubActor::isInvalidParts(CollisionParts* collisionParts) {CRASH}

bool al::isJudgedToClipFrustum(al::LiveActor const*, sead::Vector3<float> const&, float, float) {CRASH}

void al::ActionEffectCtrl::update(float, float, float, bool) {CRASH}
void al::ActionSeCtrl::update(float, float, float, bool) {CRASH}
void al::ActionBgmCtrl::update(float, float, float, bool) {CRASH}
void al::ActionPadAndCameraCtrl::update(float, float, float, bool) {CRASH}
void al::ActionScreenEffectCtrl::update(float, float, float, bool) {CRASH}

void al::ResourceSystem::removeCategory(sead::SafeStringBase<char> const&) {CRASH}
const char* al::getSubStringUnmatched(char const*, al::MatchStr const&) {CRASH}
u32 rs::reboundVelocityPart(al::LiveActor*, IUsePlayerCollision const*, float, float, float, float) {CRASH}

bool rs::isCollisionCodeSandSink(IUsePlayerCollision const*) {CRASH}
