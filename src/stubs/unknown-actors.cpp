#include "Enemy/EnemyStateSwoon.h"
#include "Enemy/Gamane.h"
#include "Enemy/GamaneHackState.h"
#include "Enemy/HackerDepthShadowMapCtrl.h"
#include "Enemy/Pecho.h"
#include "Library/Area/AreaObjGroup.h"
#include "Library/Area/AreaObjUtil.h"
#include "Library/Area/AreaShapeCube.h"
#include "Library/Area/AreaShapeCylinder.h"
#include "Library/Area/SwitchKeepOnAreaGroup.h"
#include "Library/Area/SwitchOnAreaGroup.h"
#include "Library/Base/StringUtil.h"
#include "Library/Bgm/BgmLineFunction.h"
#include "Library/Camera/CameraUtil.h"
#include "Library/Collision/CollisionUtil.h"
#include "Library/Collision/KCollisionServer.h"
#include "Library/Collision/PartsConnector.h"
#include "Library/Controller/PadRumbleFunction.h"
#include "Library/Demo/DemoDirector.h"
#include "Library/Demo/DemoFunction.h"
#include "Library/Execute/ExecuteRequestKeeper.h"
#include "Library/Execute/ExecuteTableHolderDraw.h"
#include "Library/Execute/ExecuteTableHolderUpdate.h"
#include "Library/Item/ItemUtil.h"
#include "Library/Joint/JointControllerKeeper.h"
#include "Library/Joint/JointSpringControllerHolder.h"
#include "Library/KeyPose/KeyPoseKeeper.h"
#include "Library/KeyPose/KeyPoseKeeperUtil.h"
#include "Library/Layout/LayoutActor.h"
#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorAnimFunction.h"
#include "Library/LiveActor/ActorAreaFunction.h"
#include "Library/LiveActor/ActorClippingFunction.h"
#include "Library/LiveActor/ActorCollisionFunction.h"
#include "Library/LiveActor/ActorInitFunction.h"
#include "Library/LiveActor/ActorInitUtil.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorMovementFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/ActorSceneInfo.h"
#include "Library/LiveActor/ActorSensorFunction.h"
#include "Library/LiveActor/ActorSensorUtil.h"
#include "Library/LiveActor/HitReactionKeeper.h"
#include "Library/LiveActor/SubActorKeeper.h"
#include "Library/MapObj/ClockMapParts.h"
#include "Library/MapObj/ConveyerMapParts.h"
#include "Library/MapObj/GateMapParts.h"
#include "Library/MapObj/RollingCubeMapParts.h"
#include "Library/MapObj/WheelMapParts.h"
#include "Library/Math/MathUtil.h"
#include "Library/Matrix/MatrixUtil.h"
#include "Library/Model/ModelKeeper.h"
#include "Library/Model/ModelShapeUtil.h"
#include "Library/Movement/AnimScaleController.h"
#include "Library/Movement/WheelMovement.h"
#include "Library/Nature/NatureUtil.h"
#include "Library/Nerve/NerveUtil.h"
#include "Library/Obj/PartsFunction.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Placement/PlacementId.h"
#include "Library/Player/PlayerUtil.h"
#include "Library/Rail/RailUtil.h"
#include "Library/Screen/ScreenFunction.h"
#include "Library/Se/SeFunction.h"
#include "Library/Shadow/ActorShadowUtil.h"
#include "Library/Stage/StageSwitchKeeper.h"
#include "Library/Stage/StageSwitchUtil.h"
#include "MapObj/AnagramAlphabet.h"
#include "MapObj/AppearSwitchSave.h"
#include "MapObj/AppearSwitchTimer.h"
#include "MapObj/CapMessageShowInfo.h"
#include "MapObj/CapSwitch.h"
#include "MapObj/Doshi.h"
#include "MapObj/SubActorLodFixPartsScenarioAction.h"
#include "Util/PlayerCollisionUtil.h"
#include "math/seadMathCalcCommon.h"
#include "Player/CapTargetInfo.h"
#include "Player/HackerJudge.h"
#include "Player/PlayerCollider.h"
#include "Player/PlayerHackStartShaderCtrl.h"
#include "PlayerUtil.h"
#include "Project/Action/ActionAnimCtrl.h"
#include "Project/Action/ActionSeCtrl.h"
#include "Project/Joint/KeyPose.h"
#include "Project/Joint/RollingCubePoseKeeper.h"
#include "Project/LiveActor/ConveyerKeyKeeper.h"
#include "System/GameDataFunction.h"
#include "System/GameDataHolderAccessor.h"
#include "System/GameDataUtil.h"
#include "Util/ActorDimensionKeeper.h"
#include "Util/ActorDimensionUtil.h"
#include "Util/AreaUtil.h"
#include "Util/DemoUtil.h"
#include "Util/Hack.h"
#include "Util/ItemGenerator.h"
#include "Util/ItemUtil.h"
#include "Util/PlayerUtil.h"
#include "Util/SensorMsgFunction.h"
#include "Util/ShadowUtil.h"
#include "Util/WaterSurfaceShadow.h"

AnagramAlphabet::AnagramAlphabet(const char* name) : al::LiveActor(name) {}
void AnagramAlphabet::init(const al::ActorInitInfo&) {}
AppearSwitchSave::AppearSwitchSave(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
bool AppearSwitchSave::isOn() const {CRASH}
void AppearSwitchSave::onSwitch() {CRASH}
void CapTargetInfo::setFollowLockOnMtx(char const*, sead::Vector3<float> const&, sead::Vector3<float> const&) {CRASH}
const char* GameDataFunction::getCurrentStageName(GameDataHolderAccessor) {CRASH}
s32 GameDataFunction::getScenarioNo(al::LiveActor const*) {CRASH}
bool al::CollisionPartsFilterActor::isInvalidParts(CollisionParts*) {CRASH}
al::ConveyerKeyKeeper::ConveyerKeyKeeper() {CRASH}
void al::ConveyerKeyKeeper::calcClippingSphere(sead::Vector3<float>*, float*, float) const {CRASH}
void al::ConveyerKeyKeeper::calcPosAndQuat(sead::Vector3<float>*, sead::Quat<float>*, int*, float) const {CRASH}
const al::ConveyerKey* al::ConveyerKeyKeeper::getConveyerKey(int) const {CRASH}
void al::ConveyerKeyKeeper::init(al::ActorInitInfo const&) {CRASH}
bool al::PlacementId::isEqual(al::PlacementId const&) const {CRASH}
void al::RollingCubePoseKeeper::setStart() {CRASH}
void al::SwitchKeepOnAreaGroup::update(sead::Vector3<float> const&) {CRASH}
void al::SwitchOnAreaGroup::update(sead::Vector3<float> const&) {CRASH}
bool al::appearItemTiming(al::LiveActor const*, char const*) {CRASH}
void al::attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, bool) {CRASH}
void al::calcCameraFront(sead::Vector3<float>*, al::IUseCamera const*, int) {CRASH}
void al::calcCurrentKeyQT(sead::Quat<float>*, sead::Vector3<float>*, al::RollingCubePoseKeeper const*, sead::Quat<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::calcJointPos(sead::Vector3<float>*, al::LiveActor const*, char const*) {CRASH}
void al::calcLayoutPosFromWorldPos(sead::Vector2<float>*, al::IUseCamera const*, sead::Vector3<float> const&) {CRASH}
void al::calcMtxLandEffect(sead::Matrix34<float>*, al::RollingCubePoseKeeper const*, sead::Quat<float> const&, sead::Vector3<float> const&) {CRASH}
al::Axis al::calcNearVecFromAxis3(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Quat<float> const&) {CRASH}
void al::calcQuatLocalAxis(sead::Vector3<float>*, sead::Quat<float> const&, int) {CRASH}
void al::calcQuatSide(sead::Vector3<float>*, sead::Quat<float> const&) {CRASH}
void al::calcRollingCubeClippingInfo(sead::Vector3<float>*, float*, al::RollingCubePoseKeeper const*, float) {CRASH}
void al::calcViewModel(al::LiveActor*) {CRASH}
void al::connectPoseQT(al::LiveActor*, al::MtxConnector const*) {CRASH}
al::CollisionObj* al::createCollisionObj(al::LiveActor const*, al::ActorInitInfo const&, char const*, al::HitSensor*, char const*, char const*) {CRASH}
al::LiveActor* al::createLinksActorFromFactory(al::ActorInitInfo const&, char const*, int) {CRASH}
al::RollingCubePoseKeeper* al::createRollingCubePoseKeeper(al::LiveActor const*, al::ActorInitInfo const&) {CRASH}
al::RollingCubePoseKeeper* al::createRollingCubePoseKeeper(sead::BoundBox3<float> const&, al::ActorInitInfo const&) {CRASH}
void al::fittingToCurrentKeyBoundingBox(sead::Quat<float>*, sead::Vector3<float>*, al::RollingCubePoseKeeper const*) {CRASH}
void al::forceApplyCubeMap(al::LiveActor*, char const*) {CRASH}
f32 al::getClippingRadius(al::LiveActor const*) {CRASH}
const al::PlacementInfo& al::getCurrentKeyPlacementInfo(al::RollingCubePoseKeeper const*) {CRASH}
f32 al::getRailCoord(al::IUseRail const*) {CRASH}
al::LiveActor* al::getSubActor(al::LiveActor const*, int) {CRASH}
void al::initActor(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initActorClipping(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initActorPoseTQSV(al::LiveActor*) {CRASH}
void al::initActorSRT(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initActorSceneInfo(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initCreateActorWithPlacementInfo(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initCreateActorWithPlacementInfo(al::LiveActor*, al::ActorInitInfo const&, al::PlacementInfo const&) {CRASH}
void al::initExecutorMapObjMovement(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initExecutorWatchObj(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initGroupClipping(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initLinksActor(al::LiveActor*, al::ActorInitInfo const&, char const*, int) {CRASH}
void al::initMapPartsActor(al::LiveActor*, al::ActorInitInfo const&, char const*) {CRASH}
void al::initMapPartsActorWithArchiveName(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*) {CRASH}
void al::initMaterialCode(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initNerveAction(al::LiveActor*, char const*, alNerveFunction::NerveActionCollector*, int) {CRASH}
void al::initStageSwitch(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initSubActorKeeperNoFile(al::LiveActor*, al::ActorInitInfo const&, int) {CRASH}
void al::invalidateCollisionParts(al::LiveActor*) {CRASH}
void al::invalidateDitherAnim(al::LiveActor*) {CRASH}
bool al::isExistCollisionParts(al::LiveActor const*) {CRASH}
bool al::isExistModel(al::LiveActor const*) {CRASH}
bool al::isExistRail(al::IUseRail const*) {CRASH}
bool al::isGreaterEqualMaxLodLevelNoClamp(al::ModelKeeper const*) {CRASH}
bool al::isInDeathArea(al::LiveActor const*) {CRASH}
bool al::isLessMaxLodLevelNoClamp(al::ModelKeeper const*) {CRASH}
bool al::isMovementCurrentKeyRotate(al::RollingCubePoseKeeper const*) {CRASH}
bool al::isOnGround(al::LiveActor const*, unsigned int) {CRASH}
bool al::isSameSign(float, float) {CRASH}
bool al::isValidStageSwitch(al::IUseStageSwitch const*, char const*) {CRASH}
bool al::isValidSwitchAppear(al::IUseStageSwitch const*) {CRASH}
bool al::isValidSwitchKill(al::IUseStageSwitch const*) {CRASH}
bool al::isVelocitySlowH(al::LiveActor const*, float) {CRASH}
bool al::isViewDependentModel(al::LiveActor const*) {CRASH}
bool al::listenStageSwitchOn(al::IUseStageSwitch*, char const*, al::FunctorBase const&) {CRASH}
bool al::listenStageSwitchOnOff(al::IUseStageSwitch*, char const*, al::FunctorBase const&, al::FunctorBase const&) {CRASH}
bool al::listenStageSwitchOnOffStart(al::IUseStageSwitch*, al::FunctorBase const&, al::FunctorBase const&) {CRASH}
bool al::listenStageSwitchOnStart(al::IUseStageSwitch*, al::FunctorBase const&) {CRASH}
bool al::listenStageSwitchOnStop(al::IUseStageSwitch*, al::FunctorBase const&) {CRASH}
void al::makeMapPartsModelName(sead::BufferedSafeStringBase<char>*, sead::BufferedSafeStringBase<char>*, al::ActorInitInfo const&) {CRASH}
void al::makeMtxProj(sead::Matrix44<float>*, sead::Vector2<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&) {CRASH}
f32 al::modf(float, float) {CRASH}
bool al::moveSyncRail(al::LiveActor*, float) {CRASH}
bool al::moveSyncRailLoop(al::LiveActor*, float) {CRASH}
bool al::moveSyncRailTurn(al::LiveActor*, float) {CRASH}
void al::multVecInvQuat(sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&) {CRASH}
bool al::nextRollingCubeKey(al::RollingCubePoseKeeper*) {CRASH}
void al::registActorToDemoInfo(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::registSupportFreezeSyncGroup(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::registerAreaHostMtx(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::registerSubActorSyncClipping(al::LiveActor*, al::LiveActor*) {CRASH}
void al::rotateQuatLocalDirDegree(al::LiveActor*, int, float) {CRASH}
void al::rotateQuatLocalDirDegree(al::LiveActor*, sead::Quat<float> const&, int, float) {CRASH}
void al::rotateQuatRadian(sead::Quat<float>*, sead::Quat<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::scaleVelocity(al::LiveActor*, float) {CRASH}
void al::scaleVelocityHV(al::LiveActor*, float, float) {CRASH}
void al::setSyncRailToCoord(al::LiveActor*, float) {CRASH}
void al::setSyncRailToNearestPos(al::LiveActor*) {CRASH}
void al::setTransOffsetLocalDir(al::LiveActor*, sead::Quat<float> const&, sead::Vector3<float> const&, float, int) {CRASH}
bool al::tryAddDisplayOffset(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
al::MtxConnector* al::tryCreateMtxConnector(al::LiveActor const*, al::ActorInitInfo const&) {CRASH}
al::SwitchKeepOnAreaGroup* al::tryCreateSwitchKeepOnAreaGroup(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
al::SwitchOnAreaGroup* al::tryCreateSwitchOnAreaGroup(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
const char* al::tryGetMapPartsSuffix(al::ActorInitInfo const&, char const*) {CRASH}
bool al::tryListenStageSwitchKill(al::LiveActor*) {CRASH}
bool al::tryOffStageSwitch(al::IUseStageSwitch*, char const*) {CRASH}
bool al::tryOnStageSwitch(al::IUseStageSwitch*, char const*) {CRASH}
bool al::tryOnSwitchDeadOn(al::IUseStageSwitch*) {CRASH}
bool al::trySyncStageSwitchAppear(al::LiveActor*) {CRASH}
bool al::trySyncStageSwitchAppearAndKill(al::LiveActor*) {CRASH}
void al::turnQuatYDirRate(sead::Quat<float>*, sead::Quat<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::validateCollisionParts(al::LiveActor*) {CRASH}
bool alCollisionUtil::getFirstPolyOnArrow(al::IUseCollision const*, sead::Vector3<float>*, al::Triangle*, sead::Vector3<float> const&, sead::Vector3<float> const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*) {CRASH}
void alPadRumbleFunction::startPadRumble(al::LiveActor const*, char const*, float, float, int) {CRASH}
SaveObjInfo* rs::createSaveObjInfoWriteSaveData(al::ActorInitInfo const&) {CRASH}
const sead::Vector3f& rs::getPlayerPos(al::LiveActor const*) {CRASH}
bool rs::isOnSaveObjInfo(SaveObjInfo const*) {CRASH}
void rs::onSaveObjInfo(SaveObjInfo*) {CRASH}
void rs::requestHitReactionToAttacker(al::SensorMsg const*, al::HitSensor const*, sead::Vector3<float> const&) {CRASH}
void rs::updateDimensionKeeper(ActorDimensionKeeper*) {CRASH}
template <>
s32 sead::Mathi::lcm(int, int) {CRASH}

bool al::WheelMovement::receiveMsg(al::LiveActor*, al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {CRASH}
void al::WheelMovement::reset(al::LiveActor*) {CRASH}
void al::WheelMovement::update(al::LiveActor*) {CRASH}
void al::attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&) {CRASH}
al::MtxConnector* al::createMtxConnector(al::LiveActor const*) {CRASH}
f32 al::easeByType(float, int) {CRASH}
void al::expandClippingRadiusByShadowLength(al::LiveActor*, sead::Vector3<float>*, float) {CRASH}
f32 al::getRailTotalLength(al::IUseRail const*) {CRASH}
bool al::isExistDitherAnimator(al::LiveActor const*) {CRASH}
bool al::isRailPlusDir(al::IUseRail const*, sead::Vector3<float> const&) {CRASH}
bool al::listenStageSwitchOnAppear(al::IUseStageSwitch*, al::FunctorBase const&) {CRASH}
bool al::listenStageSwitchOnKill(al::IUseStageSwitch*, al::FunctorBase const&) {CRASH}
void al::rotateQuatLocalDirDegree(sead::Quat<float>*, sead::Quat<float> const&, int, float) {CRASH}
void al::rotateQuatYDirDegree(al::LiveActor*, float) {CRASH}
void al::rotateVectorDegree(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
bool rs::isNearPlayerH(al::LiveActor const*, float) {CRASH}
bool rs::isVisibleChameleon(al::SensorMsg const*) {CRASH}
bool rs::tryGetAirExplosionForce(sead::Vector3<float>*, al::SensorMsg const*) {CRASH}
bool rs::tryGetByugoBlowForce(sead::Vector3<float>*, al::SensorMsg const*) {CRASH}
void rs::tryUpdateWaterSurfaceCoinShadow(WaterSurfaceShadow*, al::LiveActor*, float) {CRASH}

f32 al::ActionAnimCtrl::getActionFrameMax(char const*) const {CRASH}
f32 al::ActionAnimCtrl::getFrame() const {CRASH}
f32 al::ActionAnimCtrl::getFrameRate() const {CRASH}
const char* al::ActionAnimCtrl::getPlayingActionName() {CRASH}
bool al::ActionAnimCtrl::isActionEnd() {CRASH}
bool al::ActionAnimCtrl::isActionOneTime(const char*) {CRASH}
void al::HitReactionKeeper::start(char const*, sead::Vector3<float> const*, al::HitSensor const*, al::HitSensor const*) {CRASH}
void al::addVelocityToFront(al::LiveActor*, float) {CRASH}
void al::copySklAnim(al::LiveActor*, al::LiveActor const*) {CRASH}
void al::initJointControllerKeeper(al::LiveActor const*, int) {CRASH}
void al::initJointLocalZRotator(al::LiveActor const*, float const*, char const*) {CRASH}
bool al::isCollidedWall(al::LiveActor const*) {CRASH}
void al::rotateQuatMomentDegree(sead::Quat<float>*, sead::Quat<float> const&, sead::Vector3<float> const&) {CRASH}
void al::setVelocityToFront(al::LiveActor*, float) {CRASH}
void al::turnFront(al::LiveActor*, float) {CRASH}
f32 alAnimFunction::getAllAnimFrame(al::LiveActor const*, int) {CRASH}
f32 alAnimFunction::getAllAnimFrameMax(al::LiveActor const*, char const*, int) {CRASH}
f32 alAnimFunction::getAllAnimFrameRate(al::LiveActor const*, int) {CRASH}
const char* alAnimFunction::getAllAnimName(al::LiveActor const*) {CRASH}
bool alAnimFunction::isAllAnimEnd(al::LiveActor const*, int) {CRASH}

al::JointSpringControllerHolder::JointSpringControllerHolder() {CRASH}
void al::JointSpringControllerHolder::init(al::LiveActor*,char const*) {CRASH}
bool al::calcDirOnPlane(sead::Vector3<float>*,sead::Vector3<float> const&,sead::Vector3<float> const&,sead::Vector3<float> const&) {CRASH}
void al::calcDirToActor(sead::Vector3<float>*,al::LiveActor const*,al::LiveActor const*) {CRASH}
void al::faceToTarget(al::LiveActor*,sead::Vector3<float> const&) {CRASH}
bool al::isInDeathArea(al::IUseAreaObj const*,sead::Vector3<float> const&) {CRASH}
void rs::appearPopupShine(Shine*, al::LiveActor const*) {CRASH}
Shine* rs::tryInitLinkShine(al::ActorInitInfo const&,char const*,int) {CRASH}

al::AreaObj* al::AreaObjGroup::getAreaObj(int) const {CRASH}
bool al::AreaShapeCube::calcLocalBoundingBox(sead::BoundBox3<float>*) const {CRASH}
bool al::AreaShapeCube::calcNearestEdgePoint(sead::Vector3<float>*, sead::Vector3<float> const&) const {CRASH}
bool al::AreaShapeCube::checkArrowCollision(sead::Vector3<float>*, sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&) const {CRASH}
bool al::AreaShapeCube::isInVolumeOffset(sead::Vector3<float> const&, float) const {CRASH}
bool al::AreaShapeCylinder::calcLocalBoundingBox(sead::BoundBox3<float>*) const {CRASH}
bool al::AreaShapeCylinder::calcNearestEdgePoint(sead::Vector3<float>*, sead::Vector3<float> const&) const {CRASH}
bool al::AreaShapeCylinder::checkArrowCollision(sead::Vector3<float>*, sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&) const {CRASH}
bool al::AreaShapeCylinder::isInVolume(sead::Vector3<float> const&) const {CRASH}
bool al::AreaShapeCylinder::isInVolumeOffset(sead::Vector3<float> const&, float) const {CRASH}
al::ActorCameraTarget* al::createActorCameraTarget(al::LiveActor const*, float) {CRASH}
al::AreaObjGroup* al::createLinkAreaGroup(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, char const*) {CRASH}
void al::endCamera(al::IUseCamera const*, al::CameraTicket*, int, bool) {CRASH}
f32 al::getSensorRadius(al::LiveActor const*, char const*) {CRASH}
void al::initJointLocalYRotator(al::LiveActor const*, float const*, char const*) {CRASH}
al::CameraTicket* al::initObjectCamera(al::IUseCamera const*, al::ActorInitInfo const&, char const*, char const*) {CRASH}
void al::invalidateHitSensor(al::LiveActor*, char const*) {CRASH}
bool al::isInAreaObj(al::AreaObjGroup const*, sead::Vector3<float> const&) {CRASH}
void al::resetCameraTarget(al::IUseCamera*, al::CameraTargetBase*) {CRASH}
void al::setCameraTarget(al::IUseCamera*, al::CameraTargetBase*) {CRASH}
void al::startCamera(al::IUseCamera const*, al::CameraTicket*, int) {CRASH}
bool al::tryFindNearestPlayerPos(sead::Vector3<float>*, al::LiveActor const*) {CRASH}
bool al::tryNormalizeOrDirZ(sead::Vector3<float>*) {CRASH}
void rs::appearPopupShineWithoutDemo(Shine*) {CRASH}
bool rs::isEndAppearShine(Shine const*) {CRASH}
void rs::requestEndDemoNormal(al::LiveActor const*) {CRASH}
bool rs::requestStartDemoNormal(al::LiveActor*, bool) {CRASH}

Doshi::Doshi(char const*) : al::LiveActor("") {CRASH}
EnemyStateSwoon::EnemyStateSwoon(al::LiveActor*a, char const*, char const*, char const*, bool, bool) : al::ActorStateBase("", a) {CRASH}
void EnemyStateSwoon::initParams(EnemyStateSwoonInitParam const&) {CRASH}
bool EnemyStateSwoon::requestTrampled() {CRASH}
bool EnemyStateSwoon::tryReceiveMsgEnableLockOn(al::SensorMsg const*) {CRASH}
bool EnemyStateSwoon::tryReceiveMsgEndSwoon(al::SensorMsg const*) {CRASH}
bool EnemyStateSwoon::tryReceiveMsgStartHack(al::SensorMsg const*) {CRASH}
bool EnemyStateSwoon::tryReceiveMsgStartLockOn(al::SensorMsg const*) {CRASH}
GamaneHackState::GamaneHackState(al::LiveActor*a) : al::ActorStateBase("", a) {CRASH}
void GamaneHackState::attackSensor(al::HitSensor*, al::HitSensor*) {CRASH}
void GamaneHackState::initialize(al::ActorInitInfo const&) {CRASH}
bool GamaneHackState::isHackEnd() const {CRASH}
bool GamaneHackState::receiveMsg(al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {CRASH}
bool GameDataFunction::isWorldMoon(GameDataHolderAccessor) {CRASH}
HackerDepthShadowMapCtrl::HackerDepthShadowMapCtrl(al::LiveActor*, char const*, float, float, float) {CRASH}
void HackerDepthShadowMapCtrl::update(PlayerCollider*) {CRASH}
HackerJudgeNormalFall::HackerJudgeNormalFall(al::LiveActor const*, int) : HackerJudge(nullptr) {CRASH}
PlayerHackStartShaderCtrl::PlayerHackStartShaderCtrl(al::LiveActor*, PlayerHackStartShaderParam*) {CRASH}
void PlayerHackStartShaderCtrl::end() {CRASH}
void PlayerHackStartShaderCtrl::start() {CRASH}
void PlayerHackStartShaderCtrl::update() {CRASH}
void al::DemoDirector::addDemoActor(al::LiveActor*) {CRASH}
void al::DemoDirector::requestEndDemo(char const*) {CRASH}
bool al::DemoDirector::requestStartDemo(char const*) {CRASH}
al::ExecuteRequestKeeper::ExecuteRequestKeeper(int) {CRASH}
void al::ExecuteRequestKeeper::executeRequestActorDrawAllOff() {CRASH}
void al::ExecuteRequestKeeper::executeRequestActorDrawAllOn() {CRASH}
void al::ExecuteRequestKeeper::executeRequestActorMovementAllOff() {CRASH}
void al::ExecuteRequestKeeper::executeRequestActorMovementAllOn() {CRASH}
void al::ExecuteRequestKeeper::request(al::LiveActor*, al::ExecuteRequestKeeper::Request) {CRASH}
al::ExecuteTableHolderDraw::ExecuteTableHolderDraw() {CRASH}
void al::ExecuteTableHolderDraw::createExecutorListTable() {CRASH}
void al::ExecuteTableHolderDraw::execute() const {CRASH}
void al::ExecuteTableHolderDraw::executeList(char const*) const {CRASH}
void al::ExecuteTableHolderDraw::init(char const*, al::ExecuteSystemInitInfo const&, al::ExecuteOrder const*, int) {CRASH}
bool al::ExecuteTableHolderDraw::isActive() const {CRASH}
void al::ExecuteTableHolderDraw::tryRegisterActor(al::LiveActor*, char const*) {CRASH}
void al::ExecuteTableHolderDraw::tryRegisterActorModel(al::LiveActor*, char const*) {CRASH}
void al::ExecuteTableHolderDraw::tryRegisterFunctor(al::FunctorBase const&, char const*) {CRASH}
void al::ExecuteTableHolderDraw::tryRegisterLayout(al::LayoutActor*, char const*) {CRASH}
void al::ExecuteTableHolderDraw::tryRegisterUser(al::IUseExecutor*, char const*) {CRASH}
al::ExecuteTableHolderUpdate::ExecuteTableHolderUpdate() {CRASH}
void al::ExecuteTableHolderUpdate::createExecutorListTable() {CRASH}
void al::ExecuteTableHolderUpdate::execute() const {CRASH}
void al::ExecuteTableHolderUpdate::executeList(char const*) const {CRASH}
void al::ExecuteTableHolderUpdate::init(char const*, al::ExecuteSystemInitInfo const&, al::ExecuteOrder const*, int) {CRASH}
void al::ExecuteTableHolderUpdate::tryRegisterActor(al::LiveActor*, char const*) {CRASH}
void al::ExecuteTableHolderUpdate::tryRegisterFunctor(al::FunctorBase const&, char const*) {CRASH}
void al::ExecuteTableHolderUpdate::tryRegisterLayout(al::LayoutActor*, char const*) {CRASH}
void al::ExecuteTableHolderUpdate::tryRegisterUser(al::IUseExecutor*, char const*) {CRASH}
void al::LayoutActor::initExecuteInfo(al::LayoutExecuteInfo*) {CRASH}
void al::addVelocityToGravityFittedGround(al::LiveActor*, float, unsigned int) {CRASH}
void al::addVelocityToGravityNaturalOrFittedGround(al::LiveActor*, float) {CRASH}
bool al::appearItem(al::LiveActor const*) {CRASH}
al::CollisionParts* al::attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, float, float) {CRASH}
bool al::blinkModel(al::LiveActor*, int, int, int) {CRASH}
void al::calcDirToActorH(sead::Vector3<float>*, al::LiveActor const*, al::LiveActor const*) {CRASH}
f32 al::calcDistanceH(al::LiveActor const*, al::LiveActor const*) {CRASH}
bool al::calcFindFireSurface(sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::calcGravityDir(sead::Vector3<float>*, al::LiveActor const*) {CRASH}
void al::calcQuatFront(sead::Vector3<float>*, al::LiveActor const*) {CRASH}
void al::calcQuatGravity(sead::Vector3<float>*, sead::Quat<float> const&) {CRASH}
void al::calcQuatUp(sead::Vector3<float>*, al::LiveActor const*) {CRASH}
bool al::checkIsPlayingSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, char const*) {CRASH}
void al::connectPoseQT(al::LiveActor*, al::MtxConnector const*, sead::Quat<float> const&, sead::Vector3<float> const&) {CRASH}
void al::faceToDirection(al::LiveActor*, sead::Vector3<float> const&) {CRASH}
void al::faceToTarget(al::LiveActor*, al::LiveActor const*) {CRASH}
al::Collider* al::getActorCollider(al::LiveActor const*) {CRASH}
s32 al::getMaterialIndex(al::LiveActor const*, char const*) {CRASH}
const sead::Vector3f& al::getOnGroundNormal(al::LiveActor const*, unsigned int) {CRASH}
al::LiveActor* al::getSensorHost(al::HitSensor const*) {CRASH}
f32 al::getShadowMaskIntensity(al::LiveActor const*, char const*) {CRASH}
s32 al::getSubActorNum(al::LiveActor const*) {CRASH}
bool al::isCollidedFloorCode(al::LiveActor const*, char const*) {CRASH}
bool al::isExistActorCollider(al::LiveActor const*) {CRASH}
bool al::isExistSubActorKeeper(al::LiveActor const*) {CRASH}
bool al::isFaceToTargetDegreeH(al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
bool al::isFallNextMove(al::LiveActor const*, sead::Vector3<float> const&, float, float) {CRASH}
bool al::isFallOrDamageCodeNextMove(al::LiveActor const*, sead::Vector3<float> const&, float, float) {CRASH}
bool al::isHalfProbability() {CRASH}
bool al::isInWaterArea(al::LiveActor const*) {CRASH}
bool al::isMtxConnectorConnecting(al::MtxConnector const*) {CRASH}
bool al::isNearPlayer(al::LiveActor const*, float) {CRASH}
bool al::isOnStageSwitch(al::IUseStageSwitch*, char const*) {CRASH}
bool al::isOnSwitchStart(al::IUseStageSwitch const*) {CRASH}
bool al::isSensorEnemyBody(al::HitSensor const*) {CRASH}
bool al::isValidSwitchStart(al::IUseStageSwitch const*) {CRASH}
void al::onStageSwitch(al::IUseStageSwitch*, char const*) {CRASH}
bool al::reboundVelocityFromCollision(al::LiveActor*, float, float, float) {CRASH}
void al::rotateVectorDegreeY(sead::Vector3<float>*, float) {CRASH}
void al::rotateVectorQuat(sead::Vector3<float>*, sead::Quat<float> const&) {CRASH}
void al::scaleVelocityDirection(al::LiveActor*, sead::Vector3<float> const&, float) {CRASH}
void al::scaleVelocityParallelVertical(al::LiveActor*, sead::Vector3<float> const&, float, float) {CRASH}
void al::setColliderFilterCollisionParts(al::LiveActor*, al::CollisionPartsFilterBase const*) {CRASH}
void al::setCollisionPartsSpecialPurposeName(al::LiveActor*, char const*) {CRASH}
void al::setVelocityBlowAttackAndTurnToTarget(al::LiveActor*, sead::Vector3<float> const&, float, float) {CRASH}
void al::setVelocityToDirection(al::LiveActor*, sead::Vector3<float> const&, float) {CRASH}
void al::setVelocityY(al::LiveActor*, float) {CRASH}
void al::startActionSubActor(al::LiveActor const*, char const*, char const*) {CRASH}
void al::startSeWithParam(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, float, char const*) {CRASH}
al::LiveActor* al::tryFindNearestPlayerActor(al::LiveActor const*) {CRASH}
bool al::tryNormalizeOrDirZ(sead::Vector3<float>*, sead::Vector3<float> const&) {CRASH}
bool al::tryReceiveMsgPushAndAddVelocity(al::LiveActor*, al::SensorMsg const*, al::HitSensor const*, al::HitSensor const*, float) {CRASH}
void al::turnToDirection(al::LiveActor*, sead::Vector3<float> const&, float) {CRASH}
void al::turnToTarget(al::LiveActor*, sead::Vector3<float> const&, float) {CRASH}
void al::updateDepthShadowMapCtrlShapeVisible(al::LiveActor*) {CRASH}
void al::validateDepthShadowMap(al::LiveActor*) {CRASH}
void rs::addDemoActor(al::LiveActor*, bool) {CRASH}
SaveObjInfo* rs::createSaveObjInfoNoWriteSaveDataInSameWorldResetMiniGame(al::ActorInitInfo const&) {CRASH}
bool rs::isInLowGravityArea(al::LiveActor const*) {CRASH}
void rs::requestHitReactionToAttacker(al::SensorMsg const*, al::HitSensor const*, al::HitSensor const*) {CRASH}
void rs::setAppearItemFactorAndOffsetByMsg(al::LiveActor const*, al::SensorMsg const*, al::HitSensor const*) {CRASH}
void rs::setBossBarrierField(BarrierField*) {CRASH}
void rs::setMsgTargetMarkerPosition(al::SensorMsg const*, sead::Vector3<float> const&) {CRASH}
bool rs::tryAppearMultiCoinFromObj(al::LiveActor*, al::HitSensor*, int, float) {CRASH}
bool rs::tryReceiveMsgNpcScareByEnemyIgnoreTargetHack(al::SensorMsg const*, CapTargetInfo const*) {CRASH}

void Doshi::init(const al::ActorInitInfo& initInfo) {CRASH}
void Doshi::attackSensor(al::HitSensor* self, al::HitSensor* other) {CRASH}
bool Doshi::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {CRASH}
void Doshi::control() {CRASH}
void HackerJudge::reset() {CRASH}
void HackerJudge::update() {CRASH}
bool HackerJudge::judge() const {CRASH}
void EnemyStateSwoon::appear() {CRASH}
void EnemyStateSwoon::control() {CRASH}
void GamaneHackState::appear() {CRASH}
void GamaneHackState::kill() {CRASH}
al::ExecuteTableHolderDraw::~ExecuteTableHolderDraw() {CRASH}
al::ExecuteTableHolderUpdate::~ExecuteTableHolderUpdate() {CRASH}
void HackerJudgeNormalFall::reset() {CRASH}
void HackerJudgeNormalFall::update() {CRASH}
bool HackerJudgeNormalFall::judge() const {CRASH}
bool al::CollisionPartsFilterSpecialPurpose::isInvalidParts(CollisionParts* collisionParts) {CRASH}

void AppearSwitchSave::onSwitchDemo() {CRASH}
AppearSwitchTimer::AppearSwitchTimer() : al::NerveExecutor("") {CRASH}
void AppearSwitchTimer::init(al::ActorInitInfo const&,al::IUseAudioKeeper const*,al::IUseStageSwitch*,al::IUseCamera*,al::LiveActor*) {CRASH}
bool AppearSwitchTimer::isSwitchOn() {CRASH}
void AppearSwitchTimer::onSwitch() {CRASH}
ItemGenerator::ItemGenerator(al::LiveActor*,al::ActorInitInfo const&) {CRASH}
void ItemGenerator::generate(sead::Vector3<float> const&,sead::Vector3<float> const&) {CRASH}
bool ItemGenerator::isNone() const {CRASH}
al::AnimScaleController::AnimScaleController(al::AnimScaleParam const*) : al::NerveExecutor("") {CRASH}
void al::AnimScaleController::startAndSetScaleVelocityY(float) {CRASH}
void al::AnimScaleController::startAndSetScaleY(float) {CRASH}
void al::AnimScaleController::stopAndReset() {CRASH}
void al::AnimScaleController::update() {CRASH}
al::KeyPose::KeyPose() {CRASH}
void al::KeyPose::init(al::PlacementInfo const&) {CRASH}
void al::addDemoActorFromAddDemoInfo(al::LiveActor const*,al::AddDemoInfo const*) {CRASH}
bool al::calcDirH(sead::Vector3<float>*,sead::Vector3<float> const&,sead::Vector3<float> const&) {CRASH}
f32 al::calcDistanceV(sead::Vector3<float> const&,al::HitSensor const*,al::HitSensor const*) {CRASH}
void al::calcJointScale(sead::Vector3<float>*,al::LiveActor const*,char const*) {CRASH}
void al::calcKeyMoveClippingInfo(sead::Vector3<float>*,float*,al::KeyPoseKeeper const*,float) {CRASH}
f32 al::calcQuatUpY(sead::Quat<float> const&) {CRASH}
f32 al::calcRailTotalRate(al::IUseRail const*) {CRASH}
void al::createAndSetColliderSpecialPurpose(al::LiveActor*,char const*) {CRASH}
const sead::Vector3f& al::getActorVelocity(al::HitSensor const*) {CRASH}
const al::PlacementInfo* al::getPlacementInfo(al::ActorInitInfo const&) {CRASH}
const sead::Vector3f& al::getPlayerPos(al::LiveActor const*,int) {CRASH}
void al::getRandomDirH(sead::Vector3<float>*,sead::Vector3<float> const&) {CRASH}
void al::initJointGlobalQuatController(al::LiveActor const*,sead::Quat<float> const*,char const*) {CRASH}
bool al::isOnGroundNoVelocity(al::LiveActor const*,unsigned int) {CRASH}
bool al::listenStageSwitchOff(al::IUseStageSwitch*,char const*,al::FunctorBase const&) {CRASH}
void al::offStageSwitch(al::IUseStageSwitch*,char const*) {CRASH}
al::AddDemoInfo* al::registDemoRequesterToAddDemoInfo(al::LiveActor const*,al::ActorInitInfo const&,int) {CRASH}
void al::rotateQuatMoment(sead::Quat<float>*,sead::Quat<float> const&,sead::Vector3<float> const&) {CRASH}
void al::rotateQuatYDirRandomDegree(al::LiveActor*) {CRASH}
void al::setAppearItemOffset(al::LiveActor const*,sead::Vector3<float> const&) {CRASH}
void al::setKeyMoveClippingInfo(al::LiveActor*,sead::Vector3<float>*,al::KeyPoseKeeper const*) {CRASH}

void al::addVelocityDampToTarget(al::LiveActor*, sead::Vector3<float> const&, float, float) {CRASH}
void al::calcMomentRollBall(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::initActorPoseTRSV(LiveActor *actor) {CRASH}
al::CameraTicket* al::initDemoObjectCamera(al::IUseCamera const*, al::ActorInitInfo const&, char const*, char const*) {CRASH}
void al::initExecutorUpdate(LiveActor *actor, const ActorInitInfo &info, const char *) {CRASH}
bool al::isMatchString(const char *, const MatchStr &) {CRASH}
bool al::isNear(sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
f32 al::lerpValue(float, float, float, float, float) {CRASH}
bool al::pushAndAddVelocity(al::LiveActor*, al::HitSensor const*, al::HitSensor const*, float) {CRASH}
void al::rotateQuatYDirDegree(sead::Quat<float>*, sead::Quat<float> const&, float) {CRASH}
bool rs::isOnGroundSlopeSlideStart(al::LiveActor const*, IUsePlayerCollision const*, PlayerConst const*) {CRASH}
