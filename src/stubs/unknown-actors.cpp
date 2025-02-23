#include "Item/Coin.h"
#include "Item/CoinRotateCalculator.h"
#include "Library/Audio/System/AudioKeeper.h"
#include "Library/Bgm/BgmLineFunction.h"
#include "Library/Collision/CollisionUtil.h"
#include "Library/Collision/KCollisionServer.h"
#include "Library/Controller/PadRumbleFunction.h"
#include "Library/Effect/EffectSystemInfo.h"
#include "Library/Joint/JointControllerKeeper.h"
#include "Library/Layout/LayoutActionFunction.h"
#include "Library/Layout/LayoutActor.h"
#include "Library/Item/ItemUtil.h"
#include "Library/Camera/CameraUtil.h"
#include "Library/Area/SwitchKeepOnAreaGroup.h"
#include "Library/Area/SwitchOnAreaGroup.h"
#include "Library/Audio/System/SimpleAudioUser.h"
#include "Library/Collision/PartsConnector.h"
#include "Library/Layout/LayoutActorUtil.h"
#include "Library/LiveActor/ActorAnimFunction.h"
#include "Library/LiveActor/ActorAreaFunction.h"
#include "Library/LiveActor/ActorInitFunction.h"
#include "Library/Fluid/RippleCtrl.h"
#include "Library/KeyPose/KeyPoseKeeper.h"
#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorClippingFunction.h"
#include "Library/LiveActor/ActorCollisionFunction.h"
#include "Library/LiveActor/ActorInitFunction.h"
#include "Library/LiveActor/ActorInitUtil.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorMovementFunction.h"
#include "Library/LiveActor/ActorSensorMsgFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/HitReactionKeeper.h"
#include "Library/Demo/DemoFunction.h"
#include "Library/Layout/LayoutInitInfo.h"
#include "Library/LiveActor/ActorSensorMsgFunction.h"
#include "Library/LiveActor/SubActorKeeper.h"
#include "Library/MapObj/ClockMapParts.h"
#include "Library/MapObj/ConveyerMapParts.h"
#include "Library/MapObj/GateMapParts.h"
#include "Library/MapObj/KeyMoveMapParts.h"
#include "Library/MapObj/RollingCubeMapParts.h"
#include "Library/LiveActor/ActorSensorFunction.h"
#include "Library/Math/MathUtil.h"
#include "Library/MapObj/WheelMapParts.h"
#include "Library/Math/MathUtil.h"
#include "Library/Math/MathUtil.h"
#include "Library/Matrix/MatrixUtil.h"
#include "Library/Model/ModelKeeper.h"
#include "Library/Model/ModelShapeUtil.h"
#include "Library/Movement/WheelMovement.h"
#include "Library/Nature/NatureUtil.h"
#include "Library/Nerve/NerveUtil.h"
#include "Library/Obj/PartsFunction.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Placement/PlacementId.h"
#include "Library/Rail/RailUtil.h"
#include "Library/Screen/ScreenFunction.h"
#include "Library/Se/SeFunction.h"
#include "Library/Stage/StageSwitchKeeper.h"
#include "Library/Stage/StageSwitchUtil.h"
#include "PlayerUtil.h"
#include "Project/Action/ActionAnimCtrl.h"
#include "Project/Action/ActionSeCtrl.h"
#include "Project/LiveActor/ConveyerKeyKeeper.h"
#include "Project/Joint/RollingCubePoseKeeper.h"
#include "MapObj/AnagramAlphabet.h"
#include "MapObj/AppearSwitchSave.h"
#include "MapObj/CapSwitch.h"
#include "MapObj/CapMessageShowInfo.h"
#include "Player/CapTargetInfo.h"
#include "Item/Coin.h"
#include "Item/CoinCollectHolder.h"
#include "Item/LifeMaxUpItem.h"
#include "Item/LifeMaxUpItem2D.h"
#include "System/GameDataFunction.h"
#include "MapObj/SubActorLodFixPartsScenarioAction.h"
#include "System/GameDataUtil.h"
#include "Util/ActorDimensionKeeper.h"
#include "Util/ActorDimensionUtil.h"
#include "Util/ItemUtil.h"
#include "Util/Hack.h"
#include "Util/PlayerUtil.h"
#include "Util/SensorMsgFunction.h"
#include "Util/ShadowUtil.h"
#include "Util/WaterSurfaceShadow.h"
#include "math/seadMathCalcCommon.h"

AnagramAlphabet::AnagramAlphabet(const char* name) : al::LiveActor(name) {}
void AnagramAlphabet::init(const al::ActorInitInfo&) {}
AppearSwitchSave::AppearSwitchSave(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
bool AppearSwitchSave::isOn() const {CRASH}
void AppearSwitchSave::onSwitch() {CRASH}
void CapTargetInfo::setFollowLockOnMtx(char const*, sead::Vector3<float> const&, sead::Vector3<float> const&) {CRASH}
void CoinCollectHolder::registerCoinCollect2D(CoinCollect2D*) {CRASH}
void CoinCollectHolder::registerHintObj(CoinCollectHintObj*) {CRASH}
void GameDataFunction::addCoin(GameDataHolderWriter, int) {CRASH}
void GameDataFunction::addCoinCollect(GameDataHolderWriter, al::PlacementId const*) {CRASH}
s32 GameDataFunction::getCoinCollectGotNum(GameDataHolderAccessor) {CRASH}
s32 GameDataFunction::getCoinCollectNumMax(GameDataHolderAccessor) {CRASH}
const char* GameDataFunction::getCurrentStageName(GameDataHolderAccessor) {CRASH}
s32 GameDataFunction::getScenarioNo(al::LiveActor const*) {CRASH}
bool GameDataFunction::isGotCoinCollect(GameDataHolderAccessor, al::ActorInitInfo const&) {CRASH}
void al::AudioKeeper::appear() {CRASH}
bool al::CollisionPartsFilterActor::isInvalidParts(CollisionParts*) {CRASH}
al::ConveyerKeyKeeper::ConveyerKeyKeeper() {CRASH}
void al::ConveyerKeyKeeper::calcClippingSphere(sead::Vector3<float>*, float*, float) const {CRASH}
void al::ConveyerKeyKeeper::calcPosAndQuat(sead::Vector3<float>*, sead::Quat<float>*, int*, float) const {CRASH}
const al::ConveyerKey* al::ConveyerKeyKeeper::getConveyerKey(int) const {CRASH}
void al::ConveyerKeyKeeper::init(al::ActorInitInfo const&) {CRASH}
al::LayoutActor::LayoutActor(char const*) {CRASH}
void al::LayoutActor::calcAnim(bool) {CRASH}
void al::LayoutActor::initNerve(al::Nerve const*, int) {CRASH}
void al::LayoutActor::kill() {CRASH}
void al::LayoutActor::movement() {CRASH}
void al::ModelKeeper::setDitherAnimator(al::DitherAnimator*) {CRASH}
bool al::PlacementId::isEqual(al::PlacementId const&) const {CRASH}
void al::RippleCtrl::init(al::ActorInitInfo const&) {CRASH}
al::RippleCtrl* al::RippleCtrl::tryCreate(al::LiveActor*) {CRASH}
void al::RippleCtrl::update() {CRASH}
void al::RollingCubePoseKeeper::setStart() {CRASH}
al::SimpleAudioUser::SimpleAudioUser(char const*, al::ActorInitInfo const&) {CRASH}
al::AudioKeeper* al::SimpleAudioUser::getAudioKeeper() const {CRASH}
void al::SwitchKeepOnAreaGroup::update(sead::Vector3<float> const&) {CRASH}
void al::SwitchOnAreaGroup::update(sead::Vector3<float> const&) {CRASH}
bool al::appearItemTiming(al::LiveActor const*, char const*) {CRASH}
void al::attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, bool) {CRASH}
void al::calcCameraFront(sead::Vector3<float>*, al::IUseCamera const*, int) {CRASH}
void al::calcCurrentKeyQT(sead::Quat<float>*, sead::Vector3<float>*, al::RollingCubePoseKeeper const*, sead::Quat<float> const&, sead::Vector3<float> const&, float) {CRASH}
f32 al::calcDistanceNextKeyTrans(al::KeyPoseKeeper const*) {CRASH}
void al::calcJointPos(sead::Vector3<float>*, al::LiveActor const*, char const*) {CRASH}
void al::calcKeyMoveClippingInfo(sead::Vector3<float>*, float*, al::KeyPoseKeeper const*, float) {CRASH}
s32 al::calcKeyMoveMoveTime(al::KeyPoseKeeper const*) {CRASH}
s32 al::calcKeyMoveWaitTime(al::KeyPoseKeeper const*) {CRASH}
void al::calcLayoutPosFromWorldPos(sead::Vector2<float>*, al::IUseCamera const*, sead::Vector3<float> const&) {CRASH}
void al::calcLerpKeyTrans(sead::Vector3<float>*, al::KeyPoseKeeper const*, float) {CRASH}
s32 al::calcLinkChildNum(al::ActorInitInfo const&, char const*) {CRASH}
void al::calcMtxLandEffect(sead::Matrix34<float>*, al::RollingCubePoseKeeper const*, sead::Quat<float> const&, sead::Vector3<float> const&) {CRASH}
al::Axis al::calcNearVecFromAxis3(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Quat<float> const&) {CRASH}
void al::calcQuatLocalAxis(sead::Vector3<float>*, sead::Quat<float> const&, int) {CRASH}
void al::calcQuatSide(sead::Vector3<float>*, sead::Quat<float> const&) {CRASH}
void al::calcRollingCubeClippingInfo(sead::Vector3<float>*, float*, al::RollingCubePoseKeeper const*, float) {CRASH}
void al::calcSlerpKeyQuat(sead::Quat<float>*, al::KeyPoseKeeper const*, float) {CRASH}
void al::calcViewModel(al::LiveActor*) {CRASH}
void al::connectPoseQT(al::LiveActor*, al::MtxConnector const*) {CRASH}
al::CollisionObj* al::createCollisionObj(al::LiveActor const*, al::ActorInitInfo const&, char const*, al::HitSensor*, char const*, char const*) {CRASH}
al::KeyPoseKeeper* al::createKeyPoseKeeper(al::ActorInitInfo const&) {CRASH}
al::LiveActor* al::createLinksActorFromFactory(al::ActorInitInfo const&, char const*, int) {CRASH}
al::RollingCubePoseKeeper* al::createRollingCubePoseKeeper(al::LiveActor const*, al::ActorInitInfo const&) {CRASH}
al::RollingCubePoseKeeper* al::createRollingCubePoseKeeper(sead::BoundBox3<float> const&, al::ActorInitInfo const&) {CRASH}
void al::deleteEffect(al::IUseEffectKeeper*, char const*) {CRASH}
void al::emitEffect(al::IUseEffectKeeper*, char const*, sead::Vector3<float> const*) {CRASH}
void al::fittingToCurrentKeyBoundingBox(sead::Quat<float>*, sead::Vector3<float>*, al::RollingCubePoseKeeper const*) {CRASH}
void al::forceApplyCubeMap(al::LiveActor*, char const*) {CRASH}
f32 al::getClippingRadius(al::LiveActor const*) {CRASH}
const al::PlacementInfo& al::getCurrentKeyPlacementInfo(al::RollingCubePoseKeeper const*) {CRASH}
const sead::Quatf& al::getCurrentKeyQuat(al::KeyPoseKeeper const*) {CRASH}
const sead::Vector3f& al::getCurrentKeyTrans(al::KeyPoseKeeper const*) {CRASH}
s32 al::getKeyPoseCount(al::KeyPoseKeeper const*) {CRASH}
void al::getLinksInfo(al::PlacementInfo*, al::ActorInitInfo const&, char const*) {CRASH}
sead::Quatf* al::getQuatPtr(al::LiveActor*) {CRASH}
f32 al::getRailCoord(al::IUseRail const*) {CRASH}
const sead::Vector3f& al::getRotate(al::LiveActor const*) {CRASH}
void al::getStringArg(char const**, al::ActorInitInfo const&, char const*) {CRASH}
al::LiveActor* al::getSubActor(al::LiveActor const*, int) {CRASH}
void al::getTrans(sead::Vector3<float>*, al::PlacementInfo const&) {CRASH}
void al::hideModel(al::LiveActor*) {CRASH}
void al::hideSilhouetteModel(al::LiveActor*) {CRASH}
void al::initActor(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initActorClipping(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initActorPoseTQSV(al::LiveActor*) {CRASH}
void al::initActorSRT(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initActorSceneInfo(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initCreateActorWithPlacementInfo(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initExecutorMapObjMovement(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initExecutorWatchObj(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initGroupClipping(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initLayoutActor(al::LayoutActor*, al::LayoutInitInfo const&, char const*, char const*) {CRASH}
void al::initLayoutPartsActor(al::LayoutActor*, al::LayoutActor*, al::LayoutInitInfo const&, char const*, char const*) {CRASH}
void al::initLinksActor(al::LiveActor*, al::ActorInitInfo const&, char const*, int) {CRASH}
void al::initMapPartsActor(al::LiveActor*, al::ActorInitInfo const&, char const*) {CRASH}
void al::initMapPartsActorWithArchiveName(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*) {CRASH}
void al::initMaterialCode(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initNerveAction(al::LiveActor*, char const*, alNerveFunction::NerveActionCollector*, int) {CRASH}
void al::initStageSwitch(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::initSubActorKeeperNoFile(al::LiveActor*, al::ActorInitInfo const&, int) {CRASH}
void al::invalidateCollisionParts(al::LiveActor*) {CRASH}
void al::invalidateDitherAnim(al::LiveActor*) {CRASH}
bool al::isActionEnd(al::IUseLayoutAction const*, char const*) {CRASH}
bool al::isExistCollisionParts(al::LiveActor const*) {CRASH}
bool al::isExistModel(al::LiveActor const*) {CRASH}
bool al::isExistRail(al::IUseRail const*) {CRASH}
bool al::isGreaterEqualMaxLodLevelNoClamp(al::ModelKeeper const*) {CRASH}
bool al::isInDeathArea(al::LiveActor const*) {CRASH}
bool al::isLastKey(al::KeyPoseKeeper const*) {CRASH}
bool al::isLeftTarget(al::LiveActor const*, sead::Vector3<float> const&) {CRASH}
bool al::isLessMaxLodLevelNoClamp(al::ModelKeeper const*) {CRASH}
bool al::isMoveSignKey(al::KeyPoseKeeper const*) {CRASH}
bool al::isMovementCurrentKeyRotate(al::RollingCubePoseKeeper const*) {CRASH}
bool al::isObjectName(al::ActorInitInfo const&, char const*) {CRASH}
bool al::isOnGround(al::LiveActor const*, unsigned int) {CRASH}
bool al::isRestart(al::KeyPoseKeeper const*) {CRASH}
bool al::isSameSign(float, float) {CRASH}
bool al::isStop(al::KeyPoseKeeper const*) {CRASH}
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
void al::moveSyncRail(al::LiveActor*, float) {CRASH}
void al::moveSyncRailLoop(al::LiveActor*, float) {CRASH}
void al::moveSyncRailTurn(al::LiveActor*, float) {CRASH}
void al::multVecInvQuat(sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&) {CRASH}
void al::multVecPose(sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&) {CRASH}
void al::nextKeyPose(al::KeyPoseKeeper*) {CRASH}
bool al::nextRollingCubeKey(al::RollingCubePoseKeeper*) {CRASH}
void al::offDrawClipping(al::LiveActor*) {CRASH}
void al::onDrawClipping(al::LiveActor*) {CRASH}
void al::registActorToDemoInfo(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::registSupportFreezeSyncGroup(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::registerAreaHostMtx(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
void al::registerSubActorSyncClipping(al::LiveActor*, al::LiveActor*) {CRASH}
void al::resetKeyPose(al::KeyPoseKeeper*) {CRASH}
void al::restartKeyPose(al::KeyPoseKeeper*, sead::Vector3<float>*, sead::Quat<float>*) {CRASH}
void al::rotateQuatLocalDirDegree(al::LiveActor*, int, float) {CRASH}
void al::rotateQuatLocalDirDegree(al::LiveActor*, sead::Quat<float> const&, int, float) {CRASH}
void al::rotateQuatRadian(sead::Quat<float>*, sead::Quat<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::scaleVelocity(al::LiveActor*, float) {CRASH}
void al::scaleVelocityHV(al::LiveActor*, float, float) {CRASH}
void al::setClippingInfo(al::LiveActor*, float, sead::Vector3<float> const*) {CRASH}
void al::setEffectAllScale(al::IUseEffectKeeper*, char const*, sead::Vector3<float> const&) {CRASH}
void al::setKeyMoveClippingInfo(al::LiveActor*, sead::Vector3<float>*, al::KeyPoseKeeper const*) {CRASH}
void al::setLocalTrans(al::IUseLayout*, sead::Vector2<float> const&) {CRASH}
void al::setModelProjMtx0(al::ModelKeeper const*, sead::Matrix44<float> const&) {CRASH}
void al::setPaneStringFormat(al::IUseLayout*, char const*, char const*, ...) {CRASH}
void al::setQuat(al::LiveActor*, sead::Quat<float> const&) {CRASH}
void al::setRailClippingInfo(sead::Vector3<float>*, al::LiveActor*, float, float) {CRASH}
void al::setRotateY(al::LiveActor*, float) {CRASH}
void al::setSyncRailToCoord(al::LiveActor*, float) {CRASH}
void al::setSyncRailToNearestPos(al::LiveActor*) {CRASH}
void al::setTransOffsetLocalDir(al::LiveActor*, sead::Quat<float> const&, sead::Vector3<float> const&, float, int) {CRASH}
void al::showModel(al::LiveActor*) {CRASH}
bool al::startAction(al::IUseLayoutAction*, char const*, char const*) {CRASH}
void al::startBgmSituation(al::IUseAudioKeeper const*, char const*, bool, bool) {CRASH}
void al::startSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&) {CRASH}
bool al::tryAddDisplayOffset(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
al::MtxConnector* al::tryCreateMtxConnector(al::LiveActor const*, al::ActorInitInfo const&) {CRASH}
al::SwitchKeepOnAreaGroup* al::tryCreateSwitchKeepOnAreaGroup(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
al::SwitchOnAreaGroup* al::tryCreateSwitchOnAreaGroup(al::LiveActor*, al::ActorInitInfo const&) {CRASH}
bool al::tryGetArg(bool*, al::PlacementInfo const&, char const*) {CRASH}
bool al::tryGetArg(float*, al::ActorInitInfo const&, char const*) {CRASH}
bool al::tryGetArg(int*, al::ActorInitInfo const&, char const*) {CRASH}
bool al::tryGetArg(int*, al::PlacementInfo const&, char const*) {CRASH}
bool al::tryGetBoolArgOrFalse(al::ActorInitInfo const&, char const*) {CRASH}
bool al::tryGetLinksMatrixTR(sead::Matrix34<float>*, al::ActorInitInfo const&, char const*) {CRASH}
bool al::tryGetLinksQuat(sead::Quat<float>*, al::ActorInitInfo const&, char const*) {CRASH}
bool al::tryGetLinksTrans(sead::Vector3<float>*, al::ActorInitInfo const&, char const*) {CRASH}
const char* al::tryGetMapPartsSuffix(al::ActorInitInfo const&, char const*) {CRASH}
bool al::tryGetQuatPtr(al::LiveActor*) {CRASH}
bool al::tryGetStringArg(char const**, al::ActorInitInfo const&, char const*) {CRASH}
bool al::tryGetStringArg(char const**, al::PlacementInfo const&, char const*) {CRASH}
bool al::tryHoldSeWithParam(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, float, char const*) {CRASH}
void al::tryKillEmitterAndParticleAll(al::IUseEffectKeeper*) {CRASH}
bool al::tryListenStageSwitchKill(al::LiveActor*) {CRASH}
bool al::tryOffStageSwitch(al::IUseStageSwitch*, char const*) {CRASH}
bool al::tryOnStageSwitch(al::IUseStageSwitch*, char const*) {CRASH}
bool al::tryOnSwitchDeadOn(al::IUseStageSwitch*) {CRASH}
bool al::trySetEffectNamedMtxPtr(al::IUseEffectKeeper*, char const*, sead::Matrix34<float> const*) {CRASH}
bool al::tryStartSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&) {CRASH}
bool al::tryStartSeWithParam(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, float, char const*) {CRASH}
bool al::tryStopSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, int, char const*) {CRASH}
bool al::trySyncStageSwitchAppear(al::LiveActor*) {CRASH}
bool al::trySyncStageSwitchAppearAndKill(al::LiveActor*) {CRASH}
void al::turnQuatYDirRate(sead::Quat<float>*, sead::Quat<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::updateLayoutPaneRecursive(al::LayoutActor*) {CRASH}
void al::validateClipping(al::LiveActor*) {CRASH}
void al::validateCollisionParts(al::LiveActor*) {CRASH}
void al::validateDitherAnim(al::LiveActor*) {CRASH}
bool alCollisionUtil::getFirstPolyOnArrow(al::IUseCollision const*, sead::Vector3<float>*, al::Triangle*, sead::Vector3<float> const&, sead::Vector3<float> const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*) {CRASH}
void alPadRumbleFunction::startPadRumble(al::LiveActor const*, char const*, float, float, int) {CRASH}
CapTargetInfo* rs::createCapTargetInfo(al::LiveActor*, char const*) {CRASH}
CoinCollectHolder* rs::createCoinCollectHolder(al::IUseSceneObjHolder const*) {CRASH}
SaveObjInfo* rs::createSaveObjInfoWriteSaveData(al::ActorInitInfo const&) {CRASH}
const sead::Vector3f& rs::getPlayerPos(al::LiveActor const*) {CRASH}
const char* rs::getStageCoinCollect2DArchiveName(al::LiveActor const*) {CRASH}
const char* rs::getStageCoinCollect2DEmptyArchiveName(al::LiveActor const*) {CRASH}
bool rs::isOnSaveObjInfo(SaveObjInfo const*) {CRASH}
void rs::onSaveObjInfo(SaveObjInfo*) {CRASH}
void rs::requestHitReactionToAttacker(al::SensorMsg const*, al::HitSensor const*, sead::Vector3<float> const&) {CRASH}
void rs::requestLockOnCapHitReaction(al::LiveActor const*, CapTargetInfo const*, char const*) {CRASH}
void rs::snap2D(al::LiveActor*, IUseDimension const*, float) {CRASH}
void rs::snap2DParallelizeFront(al::LiveActor*, IUseDimension const*, float) {CRASH}
void rs::syncCoin2DAnimFrame(al::LiveActor*, char const*) {CRASH}
bool rs::tryGetFlyingCapPos(sead::Vector3<float>*, al::LiveActor const*) {CRASH}
bool rs::tryReceiveMsgInitCapTargetAndSetCapTargetInfo(al::SensorMsg const*, CapTargetInfo const*) {CRASH}
bool rs::tryShowCapMsgCollectCoinGetFirst(al::IUseSceneObjHolder const*) {CRASH}
void rs::updateDimensionKeeper(ActorDimensionKeeper*) {CRASH}
template <>
s32 sead::Mathi::lcm(int, int) {CRASH}

void CoinCollectHolder::registerCoinCollect(CoinCollect*) {CRASH}
CoinRotateCalculator::CoinRotateCalculator(al::LiveActor*) {CRASH}
void CoinRotateCalculator::addFishingLineTouch() {CRASH}
f32 CoinRotateCalculator::getRotate() const {CRASH}
void CoinRotateCalculator::reset() {CRASH}
void CoinRotateCalculator::update(sead::Vector3<float> const&, bool) {CRASH}
void WaterSurfaceShadow::disappearShadow() {CRASH}
bool al::WheelMovement::receiveMsg(al::LiveActor*, al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {CRASH}
void al::WheelMovement::reset(al::LiveActor*) {CRASH}
void al::WheelMovement::update(al::LiveActor*) {CRASH}
void al::attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&) {CRASH}
bool al::calcFindWaterSurface(sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
al::MtxConnector* al::createMtxConnector(al::LiveActor const*) {CRASH}
f32 al::easeByType(float, int) {CRASH}
void al::expandClippingRadiusByShadowLength(al::LiveActor*, sead::Vector3<float>*, float) {CRASH}
f32 al::getRailTotalLength(al::IUseRail const*) {CRASH}
void al::holdSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&) {CRASH}
bool al::isExistDitherAnimator(al::LiveActor const*) {CRASH}
bool al::isInWater(al::LiveActor const*) {CRASH}
bool al::isMsgScreenPointInvalidCollisionParts(al::SensorMsg const*) {CRASH}
bool al::isPlaced(al::ActorInitInfo const&) {CRASH}
bool al::isRailPlusDir(al::IUseRail const*, sead::Vector3<float> const&) {CRASH}
bool al::listenStageSwitchOnAppear(al::IUseStageSwitch*, al::FunctorBase const&) {CRASH}
bool al::listenStageSwitchOnKill(al::IUseStageSwitch*, al::FunctorBase const&) {CRASH}
void al::rotateQuatLocalDirDegree(sead::Quat<float>*, sead::Quat<float> const&, int, float) {CRASH}
void al::rotateQuatYDirDegree(al::LiveActor*, float) {CRASH}
void al::rotateVectorDegree(sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
void al::setEffectNamedMtxPtr(al::IUseEffectKeeper*, char const*, sead::Matrix34<float> const*) {CRASH}
void al::setModelMaterialParameterF32(al::LiveActor const*, char const*, char const*, float) {CRASH}
void al::stopDitherAnimAutoCtrl(al::LiveActor*) {CRASH}
bool al::tryExpandClippingByDepthShadowLength(al::LiveActor*, sead::Vector3<float>*) {CRASH}
bool al::tryGetDisplayOffset(sead::Vector3<float>*, al::ActorInitInfo const&) {CRASH}
const char* rs::getStageCoinCollectArchiveName(al::LiveActor const*) {CRASH}
const char* rs::getStageCoinCollectEmptyArchiveName(al::LiveActor const*) {CRASH}
bool rs::isNearPlayerH(al::LiveActor const*, float) {CRASH}
bool rs::isPlayerEnableToSeeOddSpace(al::LiveActor const*) {CRASH}
bool rs::isVisibleChameleon(al::SensorMsg const*) {CRASH}
f32 rs::setShadowDropLength(al::LiveActor*, al::ActorInitInfo const&, char const*) {CRASH}
WaterSurfaceShadow* rs::tryCreateWaterSurfaceCoinShadow(al::ActorInitInfo const&) {CRASH}
bool rs::tryGetAirExplosionForce(sead::Vector3<float>*, al::SensorMsg const*) {CRASH}
bool rs::tryGetByugoBlowForce(sead::Vector3<float>*, al::SensorMsg const*) {CRASH}
void rs::tryUpdateWaterSurfaceCoinShadow(WaterSurfaceShadow*, al::LiveActor*, float) {CRASH}

LifeMaxUpItem2D::LifeMaxUpItem2D(char const*) : al::LiveActor("") {CRASH}
void LifeMaxUpItem2D::init(const al::ActorInitInfo& initInfo) {CRASH}
bool LifeMaxUpItem2D::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {CRASH}
ActorDimensionKeeper* LifeMaxUpItem2D::getActorDimensionKeeper() const {CRASH}
void LifeMaxUpItem2D::appear() {CRASH}

LifeMaxUpItem::LifeMaxUpItem(char const*) : al::LiveActor("") {CRASH}
void LifeMaxUpItem::init(const al::ActorInitInfo& initInfo) {CRASH}
void LifeMaxUpItem::initAfterPlacement() {CRASH}
bool LifeMaxUpItem::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {CRASH}
void LifeMaxUpItem::appear() {CRASH}
void LifeMaxUpItem::control() {CRASH}

f32 al::ActionAnimCtrl::getActionFrameMax(char const*) const {CRASH}
f32 al::ActionAnimCtrl::getFrame() const {CRASH}
f32 al::ActionAnimCtrl::getFrameRate() const {CRASH}
const char* al::ActionAnimCtrl::getPlayingActionName() {CRASH}
bool al::ActionAnimCtrl::isActionEnd() {CRASH}
bool al::ActionAnimCtrl::isActionOneTime(const char*) {CRASH}
void al::ActionSeCtrl::resetAction(bool) {CRASH}
void al::ActionSeCtrl::restartAction() {CRASH}
void al::HitReactionKeeper::start(char const*, sead::Vector3<float> const*, al::HitSensor const*, al::HitSensor const*) {CRASH}
void al::addVelocityToFront(al::LiveActor*, float) {CRASH}
void al::copySklAnim(al::LiveActor*, al::LiveActor const*) {CRASH}
const sead::Vector3f& al::getFront(al::LiveActor const*) {CRASH}
void al::initJointControllerKeeper(al::LiveActor const*, int) {CRASH}
void al::initJointLocalZRotator(al::LiveActor const*, float const*, char const*) {CRASH}
bool al::isCollidedWall(al::LiveActor const*) {CRASH}
bool al::isSensorEnemyAttack(al::HitSensor const*) {CRASH}
bool al::isSensorPlayer(al::HitSensor const*) {CRASH}
void al::rotateQuatMomentDegree(sead::Quat<float>*, sead::Quat<float> const&, sead::Vector3<float> const&) {CRASH}
void al::setVelocityToFront(al::LiveActor*, float) {CRASH}
void al::turnFront(al::LiveActor*, float) {CRASH}
f32 alAnimFunction::getAllAnimFrame(al::LiveActor const*, int) {CRASH}
f32 alAnimFunction::getAllAnimFrameMax(al::LiveActor const*, char const*, int) {CRASH}
f32 alAnimFunction::getAllAnimFrameRate(al::LiveActor const*, int) {CRASH}
const char* alAnimFunction::getAllAnimName(al::LiveActor const*) {CRASH}
bool alAnimFunction::isAllAnimEnd(al::LiveActor const*, int) {CRASH}
void rs::createAndSetFilter2DOnly(al::LiveActor*) {CRASH}
bool rs::isMsgBlockUpperPunch2D(al::SensorMsg const*) {CRASH}
bool rs::isMsgKouraAttack2D(al::SensorMsg const*) {CRASH}
bool rs::isMsgPush2D(al::SensorMsg const*) {CRASH}
bool rs::sendMsgPush2D(al::HitSensor*, al::HitSensor*) {CRASH}
void rs::snap2DGravity(al::LiveActor*, IUseDimension const*, float) {CRASH}
