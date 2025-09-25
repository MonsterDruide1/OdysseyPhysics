#include "Item/CoinCollectHolder.h"
#include "Library/Collision/Collider.h"
#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/CollisionPartsKeeperUtil.h"
#include "Library/Collision/KCollisionServer.h"
#include "Library/Collision/PartsConnector.h"
#include "Library/Collision/PartsConnectorUtil.h"
#include "Library/Collision/SensorConnector.h"
#include "Library/Event/EventFlowUtil.h"
#include "Library/Joint/JointControllerKeeper.h"
#include "Library/LiveActor/ActorCollisionFunction.h"
#include "Library/LiveActor/ActorInitFunction.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/ActorResourceFunction.h"
#include "Library/LiveActor/ActorSceneInfo.h"
#include "Library/Math/MathUtil.h"
#include "Library/Matrix/MatrixUtil.h"
#include "Library/Movement/WheelMovement.h"
#include "Library/Nature/NatureUtil.h"
#include "Library/Obj/PartsFunction.h"
#include "Library/Player/PlayerUtil.h"
#include "Library/Rail/RailUtil.h"
#include "Library/Resource/ActorResource.h"
#include "Library/Resource/Resource.h"
#include "Library/Resource/ResourceFunction.h"
#include "Library/Scene/SceneMsgCtrl.h"
#include "Library/Screen/ScreenFunction.h"
#include "Library/Screen/ScreenPointDirector.h"
#include "Library/Screen/ScreenPointKeeper.h"
#include "Library/Yaml/ParameterBase.h"
#include "MapObj/AnagramAlphabet.h"
#include "MapObj/RouteGuideDirector.h"
#include "Project/Action/InitResourceDataAction.h"
#include "Project/Anim/InitResourceDataAnim.h"
#include "Project/Gravity/GravityHolder.h"
#include "Util/DemoUtil.h"
#include "Util/NpcEventFlowUtil.h"
#include "Util/ObjUtil.h"
#include "Project/Joint/RollingCubePoseKeeperUtil.h"
#include "Project/LiveActor/ConveyerKeyKeeper.h"
#include "Scene/GuidePosInfoHolder.h"
#include "Scene/ProjectAppearSwitchFactory.h"
#include "System/GameDataFunction.h"
#include "System/GameDataUtil.h"
#include "Util/NpcAnimUtil.h"
#include "Util/PlayerUtil.h"

// HIGH PRIORITY
void al::initActorActionKeeper(al::LiveActor*, al::ActorResource const*, char const*, char const*) {WARN_UNIMPL;}
void al::initActorCollisionWithResource(al::LiveActor*, al::Resource const*, sead::SafeStringBase<char> const&, al::HitSensor*, sead::Matrix34<float> const*, char const*) {WARN_UNIMPL;}
void al::initActorEffectKeeper(al::LiveActor*, al::ActorInitInfo const&, char const*) {WARN_UNIMPL;}
void al::initActorSRT(al::LiveActor* actor, al::ActorInitInfo const& info) {WARN_UNIMPL;}
void al::initActorPoseTFGSV(al::LiveActor* actor) {actor->mPoseKeeper = new ActorPoseKeeperTFGSV();}
void al::initActorPoseTFSV(al::LiveActor* actor) {actor->mPoseKeeper = new ActorPoseKeeperTFSV();}
void al::initActorPoseTFUSV(al::LiveActor* actor) {actor->mPoseKeeper = new ActorPoseKeeperTFUSV();}
void al::initActorPoseTQGMSV(al::LiveActor* actor) {actor->mPoseKeeper = new ActorPoseKeeperTQGMSV();}
void al::initActorPoseTQGSV(al::LiveActor* actor) {actor->mPoseKeeper = new ActorPoseKeeperTRGMSV();}
void al::initActorPoseTRGMSV(al::LiveActor* actor) {actor->mPoseKeeper = new ActorPoseKeeperTRGMSV();}
void al::initActorPoseTRMSV(al::LiveActor* actor) {actor->mPoseKeeper = new ActorPoseKeeperTRMSV();}
void al::initActorPoseTRSV(al::LiveActor* actor) {actor->mPoseKeeper = new ActorPoseKeeperTRSV();}
void al::initExecutorDraw(al::LiveActor*, al::ActorInitInfo const&, char const*) {WARN_UNIMPL;}
void al::initExecutorModelUpdate(al::LiveActor*, al::ActorInitInfo const&) {WARN_UNIMPL;}
void al::initHitReactionKeeper(al::LiveActor*, al::Resource const*, char const*) {WARN_UNIMPL;}
void al::initScreenPointKeeper(al::LiveActor*, al::Resource const*, al::ActorInitInfo const&, char const*) {WARN_UNIMPL;}
void al::initSubActorKeeper(al::LiveActor*, al::ActorInitInfo const&, char const*, int) {WARN_UNIMPL;}
void al::initStageSwitch(al::LiveActor*, al::ActorInitInfo const&) {WARN_UNIMPL;}
void al::initActorParamHolder(al::LiveActor*, al::Resource const*, char const*) {WARN_UNIMPL;}
void al::initActorItemKeeper(al::LiveActor*, al::ActorInitInfo const&, al::ByamlIter const&) {WARN_UNIMPL;}
void al::initActorSceneInfo(al::LiveActor* actor, al::ActorInitInfo const& info) {ActorSceneInfo* sceneInfo = new ActorSceneInfo(); *sceneInfo = info.actorSceneInfo; actor->initSceneInfo(sceneInfo);}
void al::setColliderOffsetY(al::LiveActor*, float) {WARN_UNIMPL;}
void al::setColliderRadius(al::LiveActor*, float) {WARN_UNIMPL;}
CoinCollectHolder::CoinCollectHolder() {WARN_UNIMPL;}
const char* CoinCollectHolder::getSceneObjName() const {WARN_UNIMPL;return "";}
bool rs::isNearPlayerH(al::LiveActor const*, float) {WARN_UNIMPL;return false;}
bool GameDataFunction::isOnObjNoWriteSaveDataResetMiniGame(GameDataHolderAccessor, al::PlacementId const*) {WARN_UNIMPL;return false;}
bool rs::isOnSaveObjInfo(SaveObjInfo const*) {WARN_UNIMPL;return false;}
void al::initExecutorMapObjMovement(al::LiveActor*, al::ActorInitInfo const&) {WARN_UNIMPL;}
bool al::isOnGround(al::LiveActor const*, unsigned int) {WARN_UNIMPL;return false;}
bool al::isCollidedFloorCode(al::LiveActor const*, char const*) {WARN_UNIMPL;return false;}
bool alCollisionUtil::getFirstPolyOnArrow(al::IUseCollision const*, sead::Vector3f*, al::Triangle*, sead::Vector3f const&, sead::Vector3f const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*) {WARN_UNIMPL;return false;}
bool al::isNearPlayer(al::LiveActor const*, float) {WARN_UNIMPL;return false;}
al::Collider* al::getActorCollider(al::LiveActor const*) {WARN_UNIMPL;return nullptr;}
void al::Collider::onInvalidate() {WARN_UNIMPL;}
void al::setColliderFilterCollisionParts(al::LiveActor*, al::CollisionPartsFilterBase const*) {WARN_UNIMPL;}
const sead::Vector3f& al::getPlayerPos(al::LiveActor const*,int) {WARN_UNIMPL;return sead::Vector3f::zero;}
bool al::isCollidedGround(al::LiveActor const*) {WARN_UNIMPL;return false;}
bool al::isCollidedWall(al::LiveActor const*) {WARN_UNIMPL;return false;}
bool al::isCollidedCeiling(al::LiveActor const*) {WARN_UNIMPL;return false;}
s32 al::getPlayerNumMax(al::LiveActor const*) {WARN_UNIMPL; return 1;}
s32 al::getPlayerPort(al::LiveActor const*, s32) {WARN_UNIMPL; return 0;}
bool al::isPlayerDead(al::LiveActor const*, s32) {WARN_UNIMPL; return false;}
void al::initExecutorUpdate(LiveActor *actor, const ActorInitInfo &info, const char *) {WARN_UNIMPL;}
bool rs::findWallCatchPosWallHit(al::CollisionParts const**, sead::Vector3<float>*, sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float, float, float, float, float, float, float) {WARN_UNIMPL;return false;}

// MathUtil.o
void al::calcQuatSide(sead::Vector3f*, sead::Quatf const&) {WARN_UNIMPL;}
bool al::isHalfProbability() {return getRandom() < 0.5f;}
al::Axis al::calcNearVecFromAxis3(sead::Vector3f*, sead::Vector3f const&, sead::Quatf const&) {CRASH}
void al::calcQuatLocalAxis(sead::Vector3f*, sead::Quatf const&, int) {CRASH}
bool al::isSameSign(float, float) {CRASH}
void al::lerpVec(sead::Vector2<float>*, sead::Vector2<float> const&, sead::Vector2<float> const&, float) {CRASH}
void al::turnQuatYDirRate(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, float) {CRASH}
void al::rotateVectorDegree(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, float) {CRASH}
void al::calcQuatGravity(sead::Vector3f*, sead::Quatf const&) {CRASH}
void al::limitVectorParallelVertical(sead::Vector3<float>*, sead::Vector3<float> const&, float, float) {CRASH}
void al::limitVectorSeparateHV(sead::Vector3<float>*, sead::Vector3<float> const&, float, float) {CRASH}
bool al::turnQuatFrontToDirDegreeH(sead::Quat<float>*, sead::Vector3<float> const&, float) {CRASH}
void al::calcVectorSeparateHV(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float) {CRASH}
bool al::isPercentProbability(float) {CRASH}
f32 al::lerpValue(float, float, float, float, float) {CRASH}
void al::rotateVectorDegreeY(sead::Vector3f*, float) {CRASH}
void al::rotateVectorQuat(sead::Vector3f*, sead::Quatf const&) {CRASH}
f32 al::calcQuatUpY(sead::Quatf const&) {CRASH}
void al::getRandomDirH(sead::Vector3f*,sead::Vector3f const&) {CRASH}
void al::makeQuatRotationRate(sead::Quat<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::calcFittingBoxPose(sead::Quat<float>*, sead::BoundBox3<float> const&, sead::Quat<float> const&, sead::Quat<float> const&) {CRASH}
void al::calcQuatRotateAxisAndDegree(sead::Vector3<float>*, float*, sead::Quat<float> const&, sead::Quat<float> const&) {CRASH}
void al::calcBoxFacePoint(sead::Vector3<float>*, sead::BoundBox3<float> const&, al::Axis, sead::Quat<float> const&, sead::Vector3<float> const&) {CRASH}
void al::calcQuatLocalAxisAll(sead::Quat<float> const&, sead::Vector3<float>*, sead::Vector3<float>*, sead::Vector3<float>*) {CRASH}
void al::rotateQuatAndTransDegree(sead::Quat<float>*, sead::Vector3<float>*, sead::Quat<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::calcSphereMargeSpheres(sead::Vector3<float>*, float*, sead::Vector3<float> const&, float, sead::Vector3<float> const&, float) {CRASH}
// MtxUtil.o
void al::makeMtxProj(sead::Matrix44f*, sead::Vector2f const&, sead::Vector3f const&, sead::Vector3f const&) {CRASH}

// NORMAL PRIORITY
AnagramAlphabet::AnagramAlphabet(const char* name) : al::LiveActor(name) {}
void AnagramAlphabet::init(const al::ActorInitInfo&) {}
const char* GameDataFunction::getCurrentStageName(GameDataHolderAccessor) {CRASH}
s32 GameDataFunction::getScenarioNo(al::LiveActor const*) {CRASH}
bool al::CollisionPartsFilterActor::isInvalidParts(CollisionParts*) {CRASH}
void al::calcJointPos(sead::Vector3f*, al::LiveActor const*, char const*) {CRASH}
void al::calcLayoutPosFromWorldPos(sead::Vector2f*, al::IUseCamera const*, sead::Vector3f const&) {CRASH}
void al::calcMtxLandEffect(sead::Matrix34f*, al::RollingCubePoseKeeper const*, sead::Quatf const&, sead::Vector3f const&) {CRASH}
void al::calcRollingCubeClippingInfo(sead::Vector3f*, float*, al::RollingCubePoseKeeper const*, float) {CRASH}
al::CollisionObj* al::createCollisionObj(al::LiveActor const*, al::ActorInitInfo const&, char const*, al::HitSensor*, char const*, char const*) {CRASH}
void al::initActorPoseTQSV(al::LiveActor*) {CRASH}
void al::initExecutorWatchObj(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initSubActorKeeperNoFile(al::LiveActor*, al::ActorInitInfo const&, int) {CRASH}
void al::invalidateCollisionParts(al::LiveActor*) {CRASH}
bool al::isExistCollisionParts(al::LiveActor const*) {CRASH}
void al::multVecInvQuat(sead::Vector3f*, al::LiveActor const*, sead::Vector3f const&) {CRASH}
void al::validateCollisionParts(al::LiveActor*) {CRASH}
SaveObjInfo* rs::createSaveObjInfoWriteSaveData(al::ActorInitInfo const&) {CRASH}
const sead::Vector3f& rs::getPlayerPos(al::LiveActor const*) {CRASH}
void rs::onSaveObjInfo(SaveObjInfo*) {CRASH}

bool al::WheelMovement::receiveMsg(al::LiveActor*, al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {CRASH}
void al::WheelMovement::reset(al::LiveActor*) {CRASH}
void al::WheelMovement::update(al::LiveActor*) {CRASH}
bool al::tryFindNearestPlayerPos(sead::Vector3f*, al::LiveActor const*) {CRASH}

bool GameDataFunction::isWorldMoon(GameDataHolderAccessor) {CRASH}
bool al::calcFindFireSurface(sead::Vector3f*, sead::Vector3f*, al::LiveActor const*, sead::Vector3f const&, sead::Vector3f const&, float) {CRASH}
const sead::Vector3f& al::getOnGroundNormal(al::LiveActor const*, unsigned int) {CRASH}
bool al::isExistActorCollider(al::LiveActor const*) {CRASH}
void al::setCollisionPartsSpecialPurposeName(al::LiveActor*, char const*) {CRASH}
al::LiveActor* al::tryFindNearestPlayerActor(al::LiveActor const*) {CRASH}
void rs::setBossBarrierField(BarrierField*) {CRASH}

bool al::CollisionPartsFilterSpecialPurpose::isInvalidParts(CollisionParts* collisionParts) {CRASH}
void al::calcJointScale(sead::Vector3f*,al::LiveActor const*,char const*) {CRASH}
void al::createAndSetColliderSpecialPurpose(al::LiveActor*,char const*) {CRASH}
void al::initJointGlobalQuatController(al::LiveActor const*,sead::Quatf const*,char const*) {CRASH}
bool al::isOnGroundNoVelocity(al::LiveActor const*,unsigned int) {CRASH}

bool al::isMatchString(const char *, const MatchStr &) {CRASH}

void al::faceToPlayer(al::LiveActor*) {CRASH}
bool alCollisionUtil::getHitPosOnArrow(al::IUseCollision const*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*) {CRASH}

void al::calcCollidedNormalSum(al::LiveActor const*, sead::Vector3<float>*) {CRASH}
void al::calcColliderPos(sead::Vector3<float>*, al::LiveActor const*) {CRASH}
void al::calcJumpInertia(sead::Vector3<float>*, al::LiveActor*, sead::Vector3<float> const&, float) {CRASH}
al::Triangle* al::Collider::getPlane(int) {CRASH}
const sead::Vector3f& al::getCollidedCeilingNormal(al::LiveActor const*) {CRASH}
const sead::Vector3f& al::getCollidedGroundNormal(al::LiveActor const*) {CRASH}
const sead::Vector3f& al::getCollidedWallNormal(al::LiveActor const*) {CRASH}
bool al::isCollided(al::LiveActor const*) {CRASH}
bool al::isNearAngleRadianHV(sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float) {CRASH}
f32 al::getColliderOffsetY(al::LiveActor const*) {CRASH}
f32 al::getColliderRadius(al::LiveActor const*) {CRASH}

bool al::isActive(al::EventFlowExecutor const*) {CRASH}
void al::invalidateCollisionPartsBySystem(al::LiveActor*) {CRASH}
void al::validateCollisionPartsBySystem(al::LiveActor*) {CRASH}
const sead::Vector3f& rs::getPlayerBodyPos(al::LiveActor const*) {CRASH}
al::EventFlowExecutor* rs::initEventFlow(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*) {CRASH}
bool rs::isSequenceTimeBalloonOrRace(al::LiveActor const*) {CRASH}
void rs::resetRouteHeadGuidePosPtr(al::IUseSceneObjHolder const*) {CRASH}
void rs::setNpcMaterialAnimFromPlacementInfo(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void rs::setRouteHeadGuidePosPtr(al::IUseSceneObjHolder const*, sead::Vector3<float> const*) {CRASH}
void rs::startEventFlow(al::EventFlowExecutor*, char const*) {CRASH}
bool rs::updateEventFlow(al::EventFlowExecutor*) {CRASH}

al::GravityHolder::GravityHolder() {CRASH}
void al::GravityHolder::init() {CRASH}
al::NatureDirector::NatureDirector() {CRASH}
void al::NatureDirector::init() {CRASH}
al::SceneMsgCtrl::SceneMsgCtrl() {CRASH}
al::SceneMsg::SceneMsg() {CRASH}

bool GameDataFunction::isOnObjNoWriteSaveData(GameDataHolderAccessor, al::PlacementId const*) {CRASH}
bool GameDataFunction::isOnObjNoWriteSaveDataInSameScenario(GameDataHolder const*, al::PlacementId const*) {CRASH}
bool GameDataFunction::isObjStarted(GameDataHolder const*, al::PlacementId const*) {CRASH}
void GameDataFunction::setObjStarted(GameDataHolder*, al::PlacementId const*) {CRASH}
void GameDataFunction::onObjNoWriteSaveData(GameDataHolderWriter, al::PlacementId const*) {CRASH}
void GameDataFunction::onObjNoWriteSaveDataResetMiniGame(GameDataHolderWriter, al::PlacementId const*) {CRASH}
void GameDataFunction::onObjNoWriteSaveDataInSameScenario(GameDataHolder*, al::PlacementId const*) {CRASH}
void GameDataFunction::offObjNoWriteSaveData(GameDataHolderWriter, al::PlacementId const*) {CRASH}
void GameDataFunction::offObjNoWriteSaveDataResetMiniGame(GameDataHolderWriter, al::PlacementId const*) {CRASH}

void sead::DirectCamera::doUpdateMatrix(sead::Matrix34<float>*) const {CRASH}

bool al::isCollidedGroundFloorCode(al::LiveActor const*, char const*) {CRASH}
al::HitSensor* al::getCollidedWallSensor(al::LiveActor const*) {CRASH}
const sead::Vector3f& al::getCollidedWallPos(al::LiveActor const*) {CRASH}
void rs::offRouteGuideByActor(al::LiveActor*) {CRASH}
void rs::onRouteGuideByActor(al::LiveActor*) {CRASH}
const char* ProjectAppearSwitchFactory::convertName(const char*) const {CRASH}

void al::ParameterBase::tryGetParam(al::ByamlIter const&) {CRASH}
bool al::ParameterBase::copyLerp(al::ParameterBase const&, al::ParameterBase const&, float) {CRASH}
bool al::ParameterBase::copy(al::ParameterBase const&) {CRASH}
bool al::ParameterBase::isEqual(al::ParameterBase const&) const {CRASH}
void al::ParameterBase::afterGetParam() {CRASH}
void al::ParameterBase::initialize(const sead::SafeString& name, const sead::SafeString& label,
                                   const sead::SafeString& meta, bool e) {CRASH}
void al::ParameterBase::initializeListNode(const sead::SafeString& name,
                                           const sead::SafeString& label,
                                           const sead::SafeString& meta, al::ParameterObj* obj,
                                           bool e) {CRASH}
al::InitResourceDataAction* al::InitResourceDataAction::tryCreate(al::Resource*, al::InitResourceDataAnim const*, char const*) {CRASH}
al::InitResourceDataAnim* al::InitResourceDataAnim::tryCreate(al::Resource*, al::Resource*) {CRASH}

void al::ScreenPointDirector::setCheckGroup(al::ScreenPointTarget*) {CRASH}
void al::ScreenPointDirector::registerTarget(al::ScreenPointTarget*) {CRASH}
void rs::moveInertiaSlideOnSkate(sead::Vector3<float>*, al::LiveActor*, IUsePlayerCollision const*, sead::Vector3<float> const&, float, float, float, float, float, float, float) {CRASH}

void al::SensorConnector::init(sead::Matrix34<float> const*, sead::Matrix34<float> const&, al::HitSensor*) {CRASH}

al::CollisionParts* alCollisionUtil::getStrikeArrowCollisionParts(al::IUseCollision const*, sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*) {CRASH}
