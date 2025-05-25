#include "Boss/BarrierField.h"
#include "Item/CoinCollectHolder.h"
#include "Library/Area/AreaObjDirector.h"
#include "Library/Area/SwitchKeepOnAreaGroup.h"
#include "Library/Area/SwitchOnAreaGroup.h"
#include "Library/Area/AreaObjMtxConnecter.h"
#include "Library/Base/StringUtil.h"
#include "Library/Collision/CollisionPartsKeeperUtil.h"
#include "Library/Collision/CollisionUtil.h"
#include "Library/Collision/KCollisionServer.h"
#include "Library/Collision/PartsConnector.h"
#include "Library/Controller/PadRumbleDirector.h"
#include "Library/Event/EventFlowUtil.h"
#include "Library/File/FileUtil.h"
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
#include "Library/LiveActor/LiveActorFunction.h"
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
#include "Library/Scene/SceneMsg.h"
#include "Library/Scene/SceneMsgCtrl.h"
#include "Library/Scene/SceneUtil.h"
#include "Library/Screen/ScreenFunction.h"
#include "Library/Screen/ScreenPointDirector.h"
#include "Library/Screen/ScreenPointKeeper.h"
#include "Library/Shadow/ActorShadowUtil.h"
#include "Library/Stage/StageSwitchKeeper.h"
#include "Library/Stage/StageSwitchUtil.h"
#include "Library/Yaml/Writer/ByamlWriterData.h"
#include "MapObj/AnagramAlphabet.h"
#include "MapObj/AppearSwitchTimer.h"
#include "MapObj/Doshi.h"
#include "MapObj/SubActorLodFixPartsScenarioAction.h"
#include "Project/Gravity/GravityHolder.h"
#include "System/SaveObjInfo.h"
#include "Util/DemoUtil.h"
#include "Util/NpcEventFlowUtil.h"
#include "Util/PlayerCollisionUtil.h"
#include "Player/PlayerCollider.h"
#include "PlayerUtil.h"
#include "Project/Joint/KeyPose.h"
#include "Project/Joint/RollingCubePoseKeeper.h"
#include "Project/Joint/RollingCubePoseKeeperUtil.h"
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
#include "basis/seadTypes.h"
#include "resource/seadArchiveRes.h"

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
void al::ActorInitInfo::initNoViewId(al::PlacementInfo const* a2, al::ActorInitInfo const& a3) {*this = a3; placementInfo = a2;}
void al::ActorInitInfo::initViewIdHost(al::PlacementInfo const* a2, al::ActorInitInfo const& a3) {*this = a3; placementInfo = a2;}
void al::ActorInitInfo::initViewIdSelf(al::PlacementInfo const* a2, al::ActorInitInfo const& a3) {*this = a3; placementInfo = a2;}
al::ActorResource* al::findOrCreateActorResource(al::ActorResourceHolder*, char const*, char const*) {WARN_UNIMPL; return new ActorResource("", nullptr, nullptr);}
al::ActorResource::ActorResource(sead::SafeStringBase<char> const&, al::Resource*, al::Resource*) {WARN_UNIMPL;}
CoinCollectHolder::CoinCollectHolder() {WARN_UNIMPL;}
const char* CoinCollectHolder::getSceneObjName() const {WARN_UNIMPL;return "";}
al::MtxConnector* al::tryCreateMtxConnector(al::LiveActor const*, al::ActorInitInfo const&) {WARN_UNIMPL;return nullptr;}
al::MtxConnector* al::createMtxConnector(al::LiveActor const*) {WARN_UNIMPL;return nullptr;}
void al::calcQuatSide(sead::Vector3f*, sead::Quatf const&) {WARN_UNIMPL;}
bool al::isHalfProbability() {return getRandom() < 0.5f;}
bool rs::isNearPlayerH(al::LiveActor const*, float) {WARN_UNIMPL;return false;}
bool GameDataFunction::isOnObjNoWriteSaveDataResetMiniGame(GameDataHolderAccessor, al::PlacementId const*) {WARN_UNIMPL;return false;}
bool rs::isOnSaveObjInfo(SaveObjInfo const*) {WARN_UNIMPL;return false;}
void al::initExecutorMapObjMovement(al::LiveActor*, al::ActorInitInfo const&) {WARN_UNIMPL;}
al::Resource* al::findOrCreateResourceSystemData(char const*, char const*) {WARN_UNIMPL;return nullptr;}
u8* al::getByml(al::Resource const*, sead::SafeStringBase<char> const&) {WARN_UNIMPL;return nullptr;}
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
bool al::tryGetActorInitFileIter(al::ByamlIter*, al::Resource const*, char const*, char const*) {WARN_UNIMPL; return false;}
s32 al::getPlayerNumMax(al::LiveActor const*) {WARN_UNIMPL; return 1;}
s32 al::getPlayerPort(al::LiveActor const*, s32) {WARN_UNIMPL; return 0;}
bool al::isPlayerDead(al::LiveActor const*, s32) {WARN_UNIMPL; return false;}

// NORMAL PRIORITY
al::ActorResource::~ActorResource() {CRASH}
AnagramAlphabet::AnagramAlphabet(const char* name) : al::LiveActor(name) {}
void AnagramAlphabet::init(const al::ActorInitInfo&) {}
const char* GameDataFunction::getCurrentStageName(GameDataHolderAccessor) {CRASH}
s32 GameDataFunction::getScenarioNo(al::LiveActor const*) {CRASH}
bool al::CollisionPartsFilterActor::isInvalidParts(CollisionParts*) {CRASH}
al::ConveyerKeyKeeper::ConveyerKeyKeeper() {CRASH}
void al::ConveyerKeyKeeper::calcClippingSphere(sead::Vector3f*, float*, float) const {CRASH}
void al::ConveyerKeyKeeper::calcPosAndQuat(sead::Vector3f*, sead::Quatf*, int*, float) const {CRASH}
const al::ConveyerKey* al::ConveyerKeyKeeper::getConveyerKey(int) const {CRASH}
void al::ConveyerKeyKeeper::init(al::ActorInitInfo const&) {CRASH}
al::SwitchOnAreaGroup::SwitchOnAreaGroup(al::AreaObjGroup*) {CRASH}
void al::SwitchOnAreaGroup::update(sead::Vector3f const*, int) {CRASH}
void al::SwitchOnAreaGroup::update(sead::Vector3f const&) {CRASH}
bool al::SwitchOnAreaGroup::isExternalCondition() const {CRASH}
void al::attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, bool) {CRASH}
void al::calcJointPos(sead::Vector3f*, al::LiveActor const*, char const*) {CRASH}
void al::calcLayoutPosFromWorldPos(sead::Vector2f*, al::IUseCamera const*, sead::Vector3f const&) {CRASH}
void al::calcMtxLandEffect(sead::Matrix34f*, al::RollingCubePoseKeeper const*, sead::Quatf const&, sead::Vector3f const&) {CRASH}
al::Axis al::calcNearVecFromAxis3(sead::Vector3f*, sead::Vector3f const&, sead::Quatf const&) {CRASH}
void al::calcQuatLocalAxis(sead::Vector3f*, sead::Quatf const&, int) {CRASH}
void al::calcRollingCubeClippingInfo(sead::Vector3f*, float*, al::RollingCubePoseKeeper const*, float) {CRASH}
void al::connectPoseQT(al::LiveActor*, al::MtxConnector const*) {CRASH}
al::CollisionObj* al::createCollisionObj(al::LiveActor const*, al::ActorInitInfo const&, char const*, al::HitSensor*, char const*, char const*) {CRASH}
f32 al::getRailCoord(al::IUseRail const*) {CRASH}
void al::initActorPoseTQSV(al::LiveActor*) {CRASH}
void al::initExecutorWatchObj(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initSubActorKeeperNoFile(al::LiveActor*, al::ActorInitInfo const&, int) {CRASH}
void al::invalidateCollisionParts(al::LiveActor*) {CRASH}
bool al::isExistCollisionParts(al::LiveActor const*) {CRASH}
bool al::isExistRail(al::IUseRail const*) {CRASH}
bool al::isSameSign(float, float) {CRASH}
void al::lerpVec(sead::Vector2<float>*, sead::Vector2<float> const&, sead::Vector2<float> const&, float) {CRASH}
void al::makeMtxProj(sead::Matrix44f*, sead::Vector2f const&, sead::Vector3f const&, sead::Vector3f const&) {CRASH}
bool al::moveSyncRail(al::LiveActor*, float) {CRASH}
bool al::moveSyncRailLoop(al::LiveActor*, float) {CRASH}
bool al::moveSyncRailTurn(al::LiveActor*, float) {CRASH}
void al::multVecInvQuat(sead::Vector3f*, al::LiveActor const*, sead::Vector3f const&) {CRASH}
void al::setSyncRailToCoord(al::LiveActor*, float) {CRASH}
void al::setSyncRailToNearestPos(al::LiveActor*) {CRASH}
void al::turnQuatYDirRate(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, float) {CRASH}
void al::validateCollisionParts(al::LiveActor*) {CRASH}
SaveObjInfo* rs::createSaveObjInfoWriteSaveData(al::ActorInitInfo const&) {CRASH}
const sead::Vector3f& rs::getPlayerPos(al::LiveActor const*) {CRASH}
void rs::onSaveObjInfo(SaveObjInfo*) {CRASH}

bool al::WheelMovement::receiveMsg(al::LiveActor*, al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {CRASH}
void al::WheelMovement::reset(al::LiveActor*) {CRASH}
void al::WheelMovement::update(al::LiveActor*) {CRASH}
void al::attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, sead::Vector3f const&, sead::Vector3f const&) {CRASH}
f32 al::getRailTotalLength(al::IUseRail const*) {CRASH}
bool al::isRailPlusDir(al::IUseRail const*, sead::Vector3f const&) {CRASH}
void al::rotateVectorDegree(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, float) {CRASH}
bool al::tryFindNearestPlayerPos(sead::Vector3f*, al::LiveActor const*) {CRASH}

bool GameDataFunction::isWorldMoon(GameDataHolderAccessor) {CRASH}
al::CollisionParts* al::attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, float, float) {CRASH}
bool al::calcFindFireSurface(sead::Vector3f*, sead::Vector3f*, al::LiveActor const*, sead::Vector3f const&, sead::Vector3f const&, float) {CRASH}
void al::calcQuatGravity(sead::Vector3f*, sead::Quatf const&) {CRASH}
void al::connectPoseQT(al::LiveActor*, al::MtxConnector const*, sead::Quatf const&, sead::Vector3f const&) {CRASH}
const sead::Vector3f& al::getOnGroundNormal(al::LiveActor const*, unsigned int) {CRASH}
bool al::isExistActorCollider(al::LiveActor const*) {CRASH}
bool al::isMtxConnectorConnecting(al::MtxConnector const*) {CRASH}
void al::rotateVectorDegreeY(sead::Vector3f*, float) {CRASH}
void al::rotateVectorQuat(sead::Vector3f*, sead::Quatf const&) {CRASH}
void al::setCollisionPartsSpecialPurposeName(al::LiveActor*, char const*) {CRASH}
al::LiveActor* al::tryFindNearestPlayerActor(al::LiveActor const*) {CRASH}
void rs::setBossBarrierField(BarrierField*) {CRASH}

AppearSwitchTimer::AppearSwitchTimer() : al::NerveExecutor("") {CRASH}
void AppearSwitchTimer::init(al::ActorInitInfo const&,al::IUseAudioKeeper const*,al::IUseStageSwitch*,al::IUseCamera*,al::LiveActor*) {CRASH}
bool AppearSwitchTimer::isSwitchOn() {CRASH}
void AppearSwitchTimer::onSwitch() {CRASH}
bool al::CollisionPartsFilterSpecialPurpose::isInvalidParts(CollisionParts* collisionParts) {CRASH}
void al::calcJointScale(sead::Vector3f*,al::LiveActor const*,char const*) {CRASH}
f32 al::calcQuatUpY(sead::Quatf const&) {CRASH}
f32 al::calcRailTotalRate(al::IUseRail const*) {CRASH}
void al::createAndSetColliderSpecialPurpose(al::LiveActor*,char const*) {CRASH}
void al::getRandomDirH(sead::Vector3f*,sead::Vector3f const&) {CRASH}
void al::initJointGlobalQuatController(al::LiveActor const*,sead::Quatf const*,char const*) {CRASH}
bool al::isOnGroundNoVelocity(al::LiveActor const*,unsigned int) {CRASH}

void al::initExecutorUpdate(LiveActor *actor, const ActorInitInfo &info, const char *) {CRASH}
bool al::isMatchString(const char *, const MatchStr &) {CRASH}
f32 al::lerpValue(float, float, float, float, float) {CRASH}

void al::faceToPlayer(al::LiveActor*) {CRASH}
bool al::isPercentProbability(float) {CRASH}
bool alCollisionUtil::getHitPosOnArrow(al::IUseCollision const*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*) {CRASH}

void al::calcCollidedNormalSum(al::LiveActor const*, sead::Vector3<float>*) {CRASH}
void al::calcColliderPos(sead::Vector3<float>*, al::LiveActor const*) {CRASH}
void al::calcJumpInertia(sead::Vector3<float>*, al::LiveActor*, sead::Vector3<float> const&, float) {CRASH}
void al::calcVectorSeparateHV(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float) {CRASH}
al::Triangle* al::Collider::getPlane(int) {CRASH}
const sead::Vector3f& al::getCollidedCeilingNormal(al::LiveActor const*) {CRASH}
const sead::Vector3f& al::getCollidedGroundNormal(al::LiveActor const*) {CRASH}
const sead::Vector3f& al::getCollidedWallNormal(al::LiveActor const*) {CRASH}
bool al::isCollided(al::LiveActor const*) {CRASH}
bool al::isNearAngleRadianHV(sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float) {CRASH}
f32 al::getColliderOffsetY(al::LiveActor const*) {CRASH}
f32 al::getColliderRadius(al::LiveActor const*) {CRASH}
void al::limitVectorParallelVertical(sead::Vector3<float>*, sead::Vector3<float> const&, float, float) {CRASH}
void al::limitVectorSeparateHV(sead::Vector3<float>*, sead::Vector3<float> const&, float, float) {CRASH}
bool al::turnQuatFrontToDirDegreeH(sead::Quat<float>*, sead::Vector3<float> const&, float) {CRASH}
u8* al::tryGetMapPartsResourceYaml(al::ActorInitInfo const&, char const*) {CRASH}

void al::ScreenPointKeeper::invalidateBySystem() {CRASH}
void al::ScreenPointKeeper::validateBySystem() {CRASH}
bool al::isActive(al::EventFlowExecutor const*) {CRASH}
void al::makeQuatRotationRate(sead::Quat<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
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

void al::calcRailPosAtCoord(sead::Vector3<float>*, al::IUseRail const*, float) {CRASH}
al::Resource* al::findOrCreateResource(sead::SafeStringBase<char> const&, char const*) {CRASH}
s32 al::getRailPointNum(al::IUseRail const*) {CRASH}
bool al::isLoopRail(al::IUseRail const*) {CRASH}

void al::calcFittingBoxPose(sead::Quat<float>*, sead::BoundBox3<float> const&, sead::Quat<float> const&, sead::Quat<float> const&) {CRASH}
void al::calcQuatRotateAxisAndDegree(sead::Vector3<float>*, float*, sead::Quat<float> const&, sead::Quat<float> const&) {CRASH}
void al::calcBoxFacePoint(sead::Vector3<float>*, sead::BoundBox3<float> const&, al::Axis, sead::Quat<float> const&, sead::Vector3<float> const&) {CRASH}
void al::calcQuatLocalAxisAll(sead::Quat<float> const&, sead::Vector3<float>*, sead::Vector3<float>*, sead::Vector3<float>*) {CRASH}
void al::rotateQuatAndTransDegree(sead::Quat<float>*, sead::Vector3<float>*, sead::Quat<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}

bool GameDataFunction::isOnObjNoWriteSaveData(GameDataHolderAccessor, al::PlacementId const*) {CRASH}
bool GameDataFunction::isOnObjNoWriteSaveDataInSameScenario(GameDataHolder const*, al::PlacementId const*) {CRASH}
bool GameDataFunction::isObjStarted(GameDataHolder const*, al::PlacementId const*) {CRASH}
void GameDataFunction::setObjStarted(GameDataHolder*, al::PlacementId const*) {CRASH}
void GameDataFunction::onObjNoWriteSaveData(GameDataHolderWriter, al::PlacementId const*) {CRASH}
void GameDataFunction::onObjNoWriteSaveDataResetMiniGame(GameDataHolderWriter, al::PlacementId const*) {CRASH}
void GameDataFunction::onObjNoWriteSaveDataInSameScenario(GameDataHolder*, al::PlacementId const*) {CRASH}
void GameDataFunction::offObjNoWriteSaveData(GameDataHolderWriter, al::PlacementId const*) {CRASH}
void GameDataFunction::offObjNoWriteSaveDataResetMiniGame(GameDataHolderWriter, al::PlacementId const*) {CRASH}

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
