#include "Boss/BarrierField.h"
#include "Item/CoinCollectHolder.h"
#include "Library/Area/AreaObjDirector.h"
#include "Library/Area/SwitchOnAreaGroup.h"
#include "Library/Area/AreaObjMtxConnecter.h"
#include "Library/Base/StringUtil.h"
#include "Library/Collision/CollisionPartsKeeperUtil.h"
#include "Library/Collision/CollisionUtil.h"
#include "Library/Collision/KCollisionServer.h"
#include "Library/Collision/PartsConnector.h"
#include "Library/Controller/PadRumbleDirector.h"
#include "Library/Event/EventFlowUtil.h"
#include "Library/Joint/JointControllerKeeper.h"
#include "Library/Joint/JointSpringControllerHolder.h"
#include "Library/KeyPose/KeyPoseKeeper.h"
#include "Library/KeyPose/KeyPoseKeeperUtil.h"
#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorAreaFunction.h"
#include "Library/LiveActor/ActorCollisionFunction.h"
#include "Library/LiveActor/ActorInitFunction.h"
#include "Library/LiveActor/ActorInitUtil.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorMovementFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/ActorResourceFunction.h"
#include "Library/LiveActor/ActorSceneInfo.h"
#include "Library/LiveActor/SubActorKeeper.h"
#include "Library/MapObj/ClockMapParts.h"
#include "Library/MapObj/ConveyerMapParts.h"
#include "Library/MapObj/GateMapParts.h"
#include "Library/MapObj/RollingCubeMapParts.h"
#include "Library/MapObj/WheelMapParts.h"
#include "Library/Math/MathUtil.h"
#include "Library/Matrix/MatrixUtil.h"
#include "Library/Movement/WheelMovement.h"
#include "Library/Nature/NatureUtil.h"
#include "Library/Obj/PartsFunction.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Placement/PlacementId.h"
#include "Library/Placement/PlacementInfo.h"
#include "Library/Player/PlayerUtil.h"
#include "Library/Rail/RailUtil.h"
#include "Library/Resource/ActorResourceHolder.h"
#include "Library/Resource/Resource.h"
#include "Library/Resource/ResourceHolder.h"
#include "Library/Screen/ScreenFunction.h"
#include "Library/Screen/ScreenPointDirector.h"
#include "Library/Screen/ScreenPointKeeper.h"
#include "Library/Shadow/ActorShadowUtil.h"
#include "Library/Stage/StageSwitchKeeper.h"
#include "Library/Stage/StageSwitchUtil.h"
#include "Library/Yaml/Writer/ByamlWriterData.h"
#include "MapObj/AnagramAlphabet.h"
#include "MapObj/AppearSwitchSave.h"
#include "MapObj/AppearSwitchTimer.h"
#include "MapObj/Doshi.h"
#include "MapObj/SubActorLodFixPartsScenarioAction.h"
#include "Project/Gravity/GravityHolder.h"
#include "Util/DemoUtil.h"
#include "Util/NpcEventFlowUtil.h"
#include "Util/PlayerCollisionUtil.h"
#include "Player/PlayerCollider.h"
#include "PlayerUtil.h"
#include "Project/Joint/KeyPose.h"
#include "Project/Joint/RollingCubePoseKeeper.h"
#include "Project/LiveActor/ConveyerKeyKeeper.h"
#include "Scene/GuidePosInfoHolder.h"
#include "System/GameDataFunction.h"
#include "System/GameDataHolderAccessor.h"
#include "System/GameDataUtil.h"
#include "Util/ActorDimensionKeeper.h"
#include "Util/ActorDimensionUtil.h"
#include "Util/AreaUtil.h"
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
void al::initExecutorDraw(al::LiveActor*, al::ActorInitInfo const&, char const*) {WARN_UNIMPL;}
void al::initExecutorModelUpdate(al::LiveActor*, al::ActorInitInfo const&) {WARN_UNIMPL;}
void al::initHitReactionKeeper(al::LiveActor*, al::Resource const*, char const*) {WARN_UNIMPL;}
void al::initScreenPointKeeper(al::LiveActor*, al::Resource const*, al::ActorInitInfo const&, char const*) {WARN_UNIMPL;}
void al::initSubActorKeeper(al::LiveActor*, al::ActorInitInfo const&, char const*, int) {WARN_UNIMPL;}
void al::initStageSwitch(al::LiveActor*, al::ActorInitInfo const&) {WARN_UNIMPL;}
bool al::tryGetActorInitFileIter(al::ByamlIter* iter, al::Resource const*, char const* x, char const*) {WARN_UNIMPL;return false;}
void al::initActorParamHolder(al::LiveActor*, al::Resource const*, char const*) {WARN_UNIMPL;}
void al::initActorItemKeeper(al::LiveActor*, al::ActorInitInfo const&, al::ByamlIter const&) {WARN_UNIMPL;}
void al::initActorSceneInfo(al::LiveActor* actor, al::ActorInitInfo const& info) {ActorSceneInfo* sceneInfo = new ActorSceneInfo(); *sceneInfo = info.actorSceneInfo; actor->initSceneInfo(sceneInfo);}
void al::setColliderOffsetY(al::LiveActor*, float) {WARN_UNIMPL;}
void al::setColliderRadius(al::LiveActor*, float) {WARN_UNIMPL;}
const char* al::Resource::getArchiveName() const {WARN_UNIMPL;return "";}
void al::ActorInitInfo::initNoViewId(al::PlacementInfo const* a2, al::ActorInitInfo const& a3) {*this = a3; placementInfo = a2;}
void al::ActorInitInfo::initViewIdHost(al::PlacementInfo const* a2, al::ActorInitInfo const& a3) {*this = a3; placementInfo = a2;}
al::ActorResource* al::findOrCreateActorResource(al::ActorResourceHolder*, char const*, char const*) {WARN_UNIMPL; return new ActorResource("", nullptr, nullptr);}
al::ActorResource::ActorResource(sead::SafeStringBase<char> const&, al::Resource*, al::Resource*) {WARN_UNIMPL;}
CoinCollectHolder::CoinCollectHolder() {WARN_UNIMPL;}
const char* CoinCollectHolder::getSceneObjName() const {WARN_UNIMPL;return "";}
al::MtxConnector* al::tryCreateMtxConnector(al::LiveActor const*, al::ActorInitInfo const&) {WARN_UNIMPL;return nullptr;}
al::MtxConnector* al::createMtxConnector(al::LiveActor const*) {WARN_UNIMPL;return nullptr;}
void al::registerAreaHostMtx(al::LiveActor*, al::ActorInitInfo const&) {WARN_UNIMPL;}
void al::rotateQuatLocalDirDegree(sead::Quatf*, sead::Quatf const&, int, float) {WARN_UNIMPL;}
void al::calcQuatSide(sead::Vector3f*, sead::Quatf const&) {WARN_UNIMPL;}
f32 al::modf(float a, float b) {return fmodf(a, b);}
bool al::isHalfProbability() {return getRandom() < 0.5f;}
void al::rotateQuatYDirDegree(sead::Quatf*, sead::Quatf const&, float) {WARN_UNIMPL;}
bool rs::isNearPlayerH(al::LiveActor const*, float) {WARN_UNIMPL;return false;}

// NORMAL PRIORITY
al::ActorResource::~ActorResource() {CRASH}
AnagramAlphabet::AnagramAlphabet(const char* name) : al::LiveActor(name) {}
void AnagramAlphabet::init(const al::ActorInitInfo&) {}
AppearSwitchSave::AppearSwitchSave(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
bool AppearSwitchSave::isOn() const {CRASH}
void AppearSwitchSave::onSwitch() {CRASH}
const char* GameDataFunction::getCurrentStageName(GameDataHolderAccessor) {CRASH}
s32 GameDataFunction::getScenarioNo(al::LiveActor const*) {CRASH}
bool al::CollisionPartsFilterActor::isInvalidParts(CollisionParts*) {CRASH}
al::ConveyerKeyKeeper::ConveyerKeyKeeper() {CRASH}
void al::ConveyerKeyKeeper::calcClippingSphere(sead::Vector3f*, float*, float) const {CRASH}
void al::ConveyerKeyKeeper::calcPosAndQuat(sead::Vector3f*, sead::Quatf*, int*, float) const {CRASH}
const al::ConveyerKey* al::ConveyerKeyKeeper::getConveyerKey(int) const {CRASH}
void al::ConveyerKeyKeeper::init(al::ActorInitInfo const&) {CRASH}
bool al::PlacementId::isEqual(al::PlacementId const&) const {CRASH}
void al::RollingCubePoseKeeper::setStart() {CRASH}
al::SwitchOnAreaGroup::SwitchOnAreaGroup(al::AreaObjGroup*) {CRASH}
void al::SwitchOnAreaGroup::update(sead::Vector3f const*, int) {CRASH}
void al::SwitchOnAreaGroup::update(sead::Vector3f const&) {CRASH}
bool al::SwitchOnAreaGroup::isExternalCondition() const {CRASH}
void al::attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, bool) {CRASH}
void al::calcCurrentKeyQT(sead::Quatf*, sead::Vector3f*, al::RollingCubePoseKeeper const*, sead::Quatf const&, sead::Vector3f const&, float) {CRASH}
void al::calcJointPos(sead::Vector3f*, al::LiveActor const*, char const*) {CRASH}
void al::calcLayoutPosFromWorldPos(sead::Vector2f*, al::IUseCamera const*, sead::Vector3f const&) {CRASH}
void al::calcMtxLandEffect(sead::Matrix34f*, al::RollingCubePoseKeeper const*, sead::Quatf const&, sead::Vector3f const&) {CRASH}
al::Axis al::calcNearVecFromAxis3(sead::Vector3f*, sead::Vector3f const&, sead::Quatf const&) {CRASH}
void al::calcQuatLocalAxis(sead::Vector3f*, sead::Quatf const&, int) {CRASH}
void al::calcRollingCubeClippingInfo(sead::Vector3f*, float*, al::RollingCubePoseKeeper const*, float) {CRASH}
void al::connectPoseQT(al::LiveActor*, al::MtxConnector const*) {CRASH}
al::CollisionObj* al::createCollisionObj(al::LiveActor const*, al::ActorInitInfo const&, char const*, al::HitSensor*, char const*, char const*) {CRASH}
al::RollingCubePoseKeeper* al::createRollingCubePoseKeeper(al::LiveActor const*, al::ActorInitInfo const&) {CRASH}
al::RollingCubePoseKeeper* al::createRollingCubePoseKeeper(sead::BoundBox3f const&, al::ActorInitInfo const&) {CRASH}
void al::fittingToCurrentKeyBoundingBox(sead::Quatf*, sead::Vector3f*, al::RollingCubePoseKeeper const*) {CRASH}
const al::PlacementInfo& al::getCurrentKeyPlacementInfo(al::RollingCubePoseKeeper const*) {CRASH}
f32 al::getRailCoord(al::IUseRail const*) {CRASH}
al::LiveActor* al::getSubActor(al::LiveActor const*, int) {CRASH}
void al::initActorPoseTQSV(al::LiveActor*) {CRASH}
void al::initExecutorMapObjMovement(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initExecutorWatchObj(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initSubActorKeeperNoFile(al::LiveActor*, al::ActorInitInfo const&, int) {CRASH}
void al::invalidateCollisionParts(al::LiveActor*) {CRASH}
bool al::isExistCollisionParts(al::LiveActor const*) {CRASH}
bool al::isExistRail(al::IUseRail const*) {CRASH}
bool al::isMovementCurrentKeyRotate(al::RollingCubePoseKeeper const*) {CRASH}
bool al::isOnGround(al::LiveActor const*, unsigned int) {CRASH}
bool al::isSameSign(float, float) {CRASH}
void al::makeMtxProj(sead::Matrix44f*, sead::Vector2f const&, sead::Vector3f const&, sead::Vector3f const&) {CRASH}
bool al::moveSyncRail(al::LiveActor*, float) {CRASH}
bool al::moveSyncRailLoop(al::LiveActor*, float) {CRASH}
bool al::moveSyncRailTurn(al::LiveActor*, float) {CRASH}
void al::multVecInvQuat(sead::Vector3f*, al::LiveActor const*, sead::Vector3f const&) {CRASH}
bool al::nextRollingCubeKey(al::RollingCubePoseKeeper*) {CRASH}
void al::rotateQuatRadian(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, float) {CRASH}
void al::setSyncRailToCoord(al::LiveActor*, float) {CRASH}
void al::setSyncRailToNearestPos(al::LiveActor*) {CRASH}
al::SwitchKeepOnAreaGroup* al::tryCreateSwitchKeepOnAreaGroup(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
al::SwitchOnAreaGroup* al::tryCreateSwitchOnAreaGroup(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::turnQuatYDirRate(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, float) {CRASH}
void al::validateCollisionParts(al::LiveActor*) {CRASH}
bool alCollisionUtil::getFirstPolyOnArrow(al::IUseCollision const*, sead::Vector3f*, al::Triangle*, sead::Vector3f const&, sead::Vector3f const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*) {CRASH}
SaveObjInfo* rs::createSaveObjInfoWriteSaveData(al::ActorInitInfo const&) {CRASH}
const sead::Vector3f& rs::getPlayerPos(al::LiveActor const*) {CRASH}
bool rs::isOnSaveObjInfo(SaveObjInfo const*) {CRASH}
void rs::onSaveObjInfo(SaveObjInfo*) {CRASH}
void rs::updateDimensionKeeper(ActorDimensionKeeper*) {CRASH}

bool al::WheelMovement::receiveMsg(al::LiveActor*, al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {CRASH}
void al::WheelMovement::reset(al::LiveActor*) {CRASH}
void al::WheelMovement::update(al::LiveActor*) {CRASH}
void al::attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, sead::Vector3f const&, sead::Vector3f const&) {CRASH}
f32 al::easeByType(float, int) {CRASH}
f32 al::getRailTotalLength(al::IUseRail const*) {CRASH}
bool al::isRailPlusDir(al::IUseRail const*, sead::Vector3f const&) {CRASH}
void al::rotateVectorDegree(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, float) {CRASH}

al::JointSpringControllerHolder::JointSpringControllerHolder() {CRASH}
void al::JointSpringControllerHolder::init(al::LiveActor*,char const*) {CRASH}
bool al::calcDirOnPlane(sead::Vector3f*,sead::Vector3f const&,sead::Vector3f const&,sead::Vector3f const&) {CRASH}
al::AreaObjGroup* al::createLinkAreaGroup(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, char const*) {CRASH}
void al::initJointControllerKeeper(al::LiveActor const*, int) {CRASH}
al::JointLocalAxisRotator* al::initJointLocalAxisRotator(al::LiveActor const*, sead::Vector3<float> const&, float const*, char const*, bool) {CRASH}
void al::initJointLocalXRotator(al::LiveActor const*, float const*, char const*) {CRASH}
void al::initJointLocalYRotator(al::LiveActor const*, float const*, char const*) {CRASH}
void al::initJointLocalZRotator(al::LiveActor const*, float const*, char const*) {CRASH}
bool al::isCollidedWall(al::LiveActor const*) {CRASH}
void al::rotateQuatMomentDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&) {CRASH}
bool al::tryFindNearestPlayerPos(sead::Vector3f*, al::LiveActor const*) {CRASH}

bool GameDataFunction::isWorldMoon(GameDataHolderAccessor) {CRASH}
al::CollisionParts* al::attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, float, float) {CRASH}
bool al::calcFindFireSurface(sead::Vector3f*, sead::Vector3f*, al::LiveActor const*, sead::Vector3f const&, sead::Vector3f const&, float) {CRASH}
void al::calcQuatGravity(sead::Vector3f*, sead::Quatf const&) {CRASH}
void al::connectPoseQT(al::LiveActor*, al::MtxConnector const*, sead::Quatf const&, sead::Vector3f const&) {CRASH}
al::Collider* al::getActorCollider(al::LiveActor const*) {CRASH}
const sead::Vector3f& al::getOnGroundNormal(al::LiveActor const*, unsigned int) {CRASH}
s32 al::getSubActorNum(al::LiveActor const*) {CRASH}
bool al::isCollidedFloorCode(al::LiveActor const*, char const*) {CRASH}
bool al::isExistActorCollider(al::LiveActor const*) {CRASH}
bool al::isExistSubActorKeeper(al::LiveActor const*) {CRASH}
bool al::isMtxConnectorConnecting(al::MtxConnector const*) {CRASH}
bool al::isNearPlayer(al::LiveActor const*, float) {CRASH}
void al::rotateVectorDegreeY(sead::Vector3f*, float) {CRASH}
void al::rotateVectorQuat(sead::Vector3f*, sead::Quatf const&) {CRASH}
void al::setColliderFilterCollisionParts(al::LiveActor*, al::CollisionPartsFilterBase const*) {CRASH}
void al::setCollisionPartsSpecialPurposeName(al::LiveActor*, char const*) {CRASH}
void al::startActionSubActor(al::LiveActor const*, char const*, char const*) {CRASH}
al::LiveActor* al::tryFindNearestPlayerActor(al::LiveActor const*) {CRASH}
SaveObjInfo* rs::createSaveObjInfoNoWriteSaveDataInSameWorldResetMiniGame(al::ActorInitInfo const&) {CRASH}
void rs::setBossBarrierField(BarrierField*) {CRASH}

void AppearSwitchSave::onSwitchDemo() {CRASH}
AppearSwitchTimer::AppearSwitchTimer() : al::NerveExecutor("") {CRASH}
void AppearSwitchTimer::init(al::ActorInitInfo const&,al::IUseAudioKeeper const*,al::IUseStageSwitch*,al::IUseCamera*,al::LiveActor*) {CRASH}
bool AppearSwitchTimer::isSwitchOn() {CRASH}
void AppearSwitchTimer::onSwitch() {CRASH}
bool al::CollisionPartsFilterSpecialPurpose::isInvalidParts(CollisionParts* collisionParts) {CRASH}
al::KeyPose::KeyPose() {CRASH}
void al::KeyPose::init(al::PlacementInfo const&) {CRASH}
bool al::calcDirH(sead::Vector3f*,sead::Vector3f const&,sead::Vector3f const&) {CRASH}
void al::calcJointScale(sead::Vector3f*,al::LiveActor const*,char const*) {CRASH}
f32 al::calcQuatUpY(sead::Quatf const&) {CRASH}
f32 al::calcRailTotalRate(al::IUseRail const*) {CRASH}
void al::createAndSetColliderSpecialPurpose(al::LiveActor*,char const*) {CRASH}
const sead::Vector3f& al::getPlayerPos(al::LiveActor const*,int) {CRASH}
void al::getRandomDirH(sead::Vector3f*,sead::Vector3f const&) {CRASH}
void al::initJointGlobalQuatController(al::LiveActor const*,sead::Quatf const*,char const*) {CRASH}
bool al::isOnGroundNoVelocity(al::LiveActor const*,unsigned int) {CRASH}
void al::rotateQuatMoment(sead::Quatf*,sead::Quatf const&,sead::Vector3f const&) {CRASH}

void al::calcMomentRollBall(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, float) {CRASH}
void al::initActorPoseTRSV(LiveActor *actor) {CRASH}
void al::initExecutorUpdate(LiveActor *actor, const ActorInitInfo &info, const char *) {CRASH}
bool al::isMatchString(const char *, const MatchStr &) {CRASH}
f32 al::lerpValue(float, float, float, float, float) {CRASH}
bool rs::isOnGroundSlopeSlideStart(al::LiveActor const*, IUsePlayerCollision const*, PlayerConst const*) {CRASH}

al::Resource* al::findOrCreateResourceSystemData(char const*, char const*) {CRASH}
u8* al::getByml(al::Resource const*, sead::SafeStringBase<char> const&) {CRASH}
u32 al::getMaxAbsElementIndex(const sead::Vector3f&) {CRASH}
s32 al::getPlayerNumMax(al::LiveActor const*) {CRASH}
s32 al::getPlayerPort(al::LiveActor const*, s32) {CRASH}
bool al::isPercentProbability(float) {CRASH}
bool al::isPlayerDead(al::LiveActor const*, s32) {CRASH}
bool alCollisionUtil::getHitPosOnArrow(al::IUseCollision const*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*) {CRASH}

void al::ActorInitInfo::initViewIdSelf(al::PlacementInfo const*, al::ActorInitInfo const&) {CRASH}
void al::calcCollidedNormalSum(al::LiveActor const*, sead::Vector3<float>*) {CRASH}
void al::calcColliderPos(sead::Vector3<float>*, al::LiveActor const*) {CRASH}
void al::calcJumpInertia(sead::Vector3<float>*, al::LiveActor*, sead::Vector3<float> const&, float) {CRASH}
void al::calcVectorSeparateHV(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float) {CRASH}
al::Triangle* al::Collider::getPlane(int) {CRASH}
const sead::Vector3f& al::getCollidedCeilingNormal(al::LiveActor const*) {CRASH}
const sead::Vector3f& al::getCollidedGroundNormal(al::LiveActor const*) {CRASH}
const sead::Vector3f& al::getCollidedWallNormal(al::LiveActor const*) {CRASH}
bool al::isCollided(al::LiveActor const*) {CRASH}
bool al::isCollidedCeiling(al::LiveActor const*) {CRASH}
bool al::isNearAngleRadianHV(sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float) {CRASH}
bool al::isNearAngleDegree(sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
f32 al::getColliderOffsetY(al::LiveActor const*) {CRASH}
f32 al::getColliderRadius(al::LiveActor const*) {CRASH}
void al::limitVectorParallelVertical(sead::Vector3<float>*, sead::Vector3<float> const&, float, float) {CRASH}
void al::limitVectorSeparateHV(sead::Vector3<float>*, sead::Vector3<float> const&, float, float) {CRASH}
void al::rotateQuatXDirDegree(sead::Quat<float>*, sead::Quat<float> const&, float) {CRASH}
void al::rotateQuatZDirDegree(sead::Quat<float>*, sead::Quat<float> const&, float) {CRASH}
void al::scaleVectorDirection(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::scaleVectorExceptDirection(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
bool al::turnQuatFrontToDirDegreeH(sead::Quat<float>*, sead::Vector3<float> const&, float) {CRASH}
u8* al::tryGetMapPartsResourceYaml(al::ActorInitInfo const&, char const*) {CRASH}

void al::ScreenPointKeeper::invalidateBySystem() {CRASH}
void al::ScreenPointKeeper::validateBySystem() {CRASH}
bool al::isActive(al::EventFlowExecutor const*) {CRASH}
void al::makeQuatRotationRate(sead::Quat<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::invalidateCollisionPartsBySystem(al::LiveActor*) {CRASH}
void al::validateCollisionPartsBySystem(al::LiveActor*) {CRASH}
void alSubActorFunction::trySyncAlive(al::SubActorKeeper*) {CRASH}
void alSubActorFunction::trySyncClippingEnd(al::SubActorKeeper*) {CRASH}
void alSubActorFunction::trySyncClippingStart(al::SubActorKeeper*) {CRASH}
void alSubActorFunction::trySyncDead(al::SubActorKeeper*) {CRASH}
const sead::Vector3f& rs::getPlayerBodyPos(al::LiveActor const*) {CRASH}
al::EventFlowExecutor* rs::initEventFlow(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*) {CRASH}
bool rs::isSequenceTimeBalloonOrRace(al::LiveActor const*) {CRASH}
void rs::resetRouteHeadGuidePosPtr(al::IUseSceneObjHolder const*) {CRASH}
void rs::setNpcMaterialAnimFromPlacementInfo(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void rs::setRouteHeadGuidePosPtr(al::IUseSceneObjHolder const*, sead::Vector3<float> const*) {CRASH}
void rs::startEventFlow(al::EventFlowExecutor*, char const*) {CRASH}
bool rs::updateEventFlow(al::EventFlowExecutor*) {CRASH}

al::ActorResourceHolder::ActorResourceHolder(int) {CRASH}
al::AreaObjMtxConnecterHolder::AreaObjMtxConnecterHolder(int) {CRASH}
bool al::AreaObjMtxConnecterHolder::tryAddArea(al::AreaObj*, al::PlacementInfo const&) {CRASH}
void al::AreaObjMtxConnecterHolder::update() {CRASH}
al::GravityHolder::GravityHolder() {CRASH}
void al::GravityHolder::init() {CRASH}
al::NatureDirector::NatureDirector() {CRASH}
void al::NatureDirector::init() {CRASH}
al::PadRumbleDirector::PadRumbleDirector(al::PlayerHolder const*, al::CameraDirector const*) {CRASH}
void al::PadRumbleDirector::update() {CRASH}
al::ScreenPointDirector::ScreenPointDirector() {CRASH}


// Done, but not merged yet
template <>
s32 sead::Mathi::gcd(s32 x, s32 y)
{
    if (x == 0 || y == 0)
        return 0;

    while (x != y)
    {
        if (x > y)
            x -= y;
        else
            y -= x;
    }

    return x;
}
template <>
s32 sead::Mathi::lcm(int x, int y) {
    if (x == 0 || y == 0)
        return 0;
    return x / gcd(x, y) * y;
}
