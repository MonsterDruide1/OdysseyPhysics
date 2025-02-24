#include "Enemy/Gamane.h"
#include "Enemy/EnemyStateSwoon.h"
#include "Enemy/GamaneHackState.h"
#include "Enemy/HackerDepthShadowMapCtrl.h"
#include "Item/Coin2D.h"
#include "Item/LifeUpItem.h"
#include "Item/LifeUpItem2D.h"
#include "Library/Collision/PartsConnector.h"
#include "Library/Demo/DemoDirector.h"
#include "Library/Execute/ExecuteRequestKeeper.h"
#include "Library/Execute/ExecuteTableHolderDraw.h"
#include "Library/Execute/ExecuteTableHolderUpdate.h"
#include "Library/Item/ItemUtil.h"
#include "Library/KeyPose/KeyPoseKeeper.h"
#include "Library/Layout/LayoutActor.h"
#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorAreaFunction.h"
#include "Library/LiveActor/ActorCollisionFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/ActorSceneInfo.h"
#include "Library/LiveActor/ActorMovementFunction.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorSensorMsgFunction.h"
#include "Library/LiveActor/ActorSensorFunction.h"
#include "Library/LiveActor/SubActorKeeper.h"
#include "Library/Math/MathUtil.h"
#include "Library/Nature/NatureUtil.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Player/PlayerUtil.h"
#include "Library/Se/SeFunction.h"
#include "Library/Shadow/ActorShadowUtil.h"
#include "Library/Stage/StageSwitchUtil.h"
#include "MapObj/Doshi.h"
#include "Player/HackerJudge.h"
#include "Player/PlayerCollider.h"
#include "Player/PlayerHackStartShaderCtrl.h"
#include "System/GameDataFunction.h"
#include "System/GameDataHolderAccessor.h"
#include "System/GameDataUtil.h"
#include "Util/ActorDimensionKeeper.h"
#include "Util/AreaUtil.h"
#include "Util/DemoUtil.h"
#include "Util/Hack.h"
#include "Util/ItemUtil.h"
#include "Util/SensorMsgFunction.h"
#include "Util/ShadowUtil.h"

Coin2D::Coin2D(char const*) : al::LiveActor("") {CRASH}
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
LifeUpItem2D::LifeUpItem2D(char const*) : al::LiveActor("") {CRASH}
LifeUpItem::LifeUpItem(char const*) : al::LiveActor("") {CRASH}
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
void al::KeyPoseKeeper::setMoveTypeStop() {CRASH}
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
void al::getObjectName(char const**, al::ActorInitInfo const&) {CRASH}
const sead::Vector3f& al::getOnGroundNormal(al::LiveActor const*, unsigned int) {CRASH}
al::LiveActor* al::getSensorHost(al::HitSensor const*) {CRASH}
f32 al::getShadowMaskIntensity(al::LiveActor const*, char const*) {CRASH}
s32 al::getSubActorNum(al::LiveActor const*) {CRASH}
void al::hideShadowMask(al::LiveActor*) {CRASH}
void al::hideSilhouetteModelIfShow(al::LiveActor*) {CRASH}
void al::invalidateDepthShadowMap(al::LiveActor*) {CRASH}
bool al::isCollidedFloorCode(al::LiveActor const*, char const*) {CRASH}
bool al::isExistActorCollider(al::LiveActor const*) {CRASH}
bool al::isExistDepthShadowMapCtrl(al::LiveActor*) {CRASH}
bool al::isExistSubActorKeeper(al::LiveActor const*) {CRASH}
bool al::isFaceToTargetDegreeH(al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float) {CRASH}
bool al::isFallNextMove(al::LiveActor const*, sead::Vector3<float> const&, float, float) {CRASH}
bool al::isFallOrDamageCodeNextMove(al::LiveActor const*, sead::Vector3<float> const&, float, float) {CRASH}
bool al::isHalfProbability() {CRASH}
bool al::isInWaterArea(al::LiveActor const*) {CRASH}
bool al::isMsgEnemyAttackFire(al::SensorMsg const*) {CRASH}
bool al::isMsgPlayerFireBallAttack(al::SensorMsg const*) {CRASH}
bool al::isMsgPlayerTouch(al::SensorMsg const*) {CRASH}
bool al::isMsgPlayerTrample(al::SensorMsg const*) {CRASH}
bool al::isMsgPlayerTrampleReflect(al::SensorMsg const*) {CRASH}
bool al::isMtxConnectorConnecting(al::MtxConnector const*) {CRASH}
bool al::isNearPlayer(al::LiveActor const*, float) {CRASH}
bool al::isOnStageSwitch(al::IUseStageSwitch*, char const*) {CRASH}
bool al::isOnSwitchStart(al::IUseStageSwitch const*) {CRASH}
bool al::isSensorEnemyBody(al::HitSensor const*) {CRASH}
bool al::isValidSwitchStart(al::IUseStageSwitch const*) {CRASH}
void al::offDepthShadowModel(al::LiveActor*) {CRASH}
void al::onDepthShadowModel(al::LiveActor*) {CRASH}
void al::onStageSwitch(al::IUseStageSwitch*, char const*) {CRASH}
void al::reboundVelocityFromCollision(al::LiveActor*, float, float, float) {CRASH}
void al::rotateVectorDegreeY(sead::Vector3<float>*, float) {CRASH}
void al::rotateVectorQuat(sead::Vector3<float>*, sead::Quat<float> const&) {CRASH}
void al::scaleVelocityDirection(al::LiveActor*, sead::Vector3<float> const&, float) {CRASH}
void al::scaleVelocityParallelVertical(al::LiveActor*, sead::Vector3<float> const&, float, float) {CRASH}
bool al::sendMsgEnemyAttack(al::HitSensor*, al::HitSensor*) {CRASH}
bool al::sendMsgEnemyAttackNeedle(al::HitSensor*, al::HitSensor*) {CRASH}
bool al::sendMsgPush(al::HitSensor*, al::HitSensor*) {CRASH}
bool al::sendMsgPushAndKillVelocityToTarget(al::LiveActor*, al::HitSensor*, al::HitSensor*) {CRASH}
void al::setColliderFilterCollisionParts(al::LiveActor*, al::CollisionPartsFilterBase const*) {CRASH}
void al::setCollisionPartsSpecialPurposeName(al::LiveActor*, char const*) {CRASH}
void al::setModelMaterialParameterF32(al::LiveActor const*, int, char const*, float) {CRASH}
void al::setShadowMaskDropLength(al::LiveActor*, float, char const*) {CRASH}
void al::setShadowMaskIntensity(al::LiveActor const*, char const*, float) {CRASH}
void al::setVelocityBlowAttackAndTurnToTarget(al::LiveActor*, sead::Vector3<float> const&, float, float) {CRASH}
void al::setVelocityToDirection(al::LiveActor*, sead::Vector3<float> const&, float) {CRASH}
void al::setVelocityY(al::LiveActor*, float) {CRASH}
void al::showShadowMask(al::LiveActor*) {CRASH}
void al::showSilhouetteModelIfHide(al::LiveActor*) {CRASH}
void al::startActionSubActor(al::LiveActor const*, char const*, char const*) {CRASH}
void al::startSeWithParam(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, float, char const*) {CRASH}
bool al::tryAddRippleMiddle(al::LiveActor const*) {CRASH}
al::LiveActor* al::tryFindNearestPlayerActor(al::LiveActor const*) {CRASH}
bool al::tryNormalizeOrDirZ(sead::Vector3<float>*, sead::Vector3<float> const&) {CRASH}
bool al::tryReceiveMsgPushAndAddVelocity(al::LiveActor*, al::SensorMsg const*, al::HitSensor const*, al::HitSensor const*, float) {CRASH}
void al::turnToDirection(al::LiveActor*, sead::Vector3<float> const&, float) {CRASH}
void al::turnToTarget(al::LiveActor*, sead::Vector3<float> const&, float) {CRASH}
void al::updateDepthShadowMapCtrlShapeVisible(al::LiveActor*) {CRASH}
void al::validateDepthShadowMap(al::LiveActor*) {CRASH}
bool alPlacementFunction::tryGetModelName(char const**, al::ActorInitInfo const&) {CRASH}
void rs::addDemoActor(al::LiveActor*, bool) {CRASH}
SaveObjInfo* rs::createSaveObjInfoNoWriteSaveDataInSameWorldResetMiniGame(al::ActorInitInfo const&) {CRASH}
void rs::endHack(IUsePlayerHack**) {CRASH}
void rs::endHackShadow(al::LiveActor*) {CRASH}
void rs::endHackStartDemo(IUsePlayerHack*, al::LiveActor*) {CRASH}
const char* rs::getSpecialPurposeName2DOnly() {CRASH}
void rs::hideShadowHackCap(IUsePlayerHack*) {CRASH}
void rs::initHackShadow(al::LiveActor*) {CRASH}
bool rs::isHackStartDemoEnterMario(IUsePlayerHack const*) {CRASH}
bool rs::isInLowGravityArea(al::LiveActor const*) {CRASH}
bool rs::isMsgBlowDown(al::SensorMsg const*) {CRASH}
bool rs::isMsgCapAttackCollide(al::SensorMsg const*) {CRASH}
bool rs::isMsgCapEnableLockOn(al::SensorMsg const*) {CRASH}
bool rs::isMsgCapReflect(al::SensorMsg const*) {CRASH}
bool rs::isMsgConductLightning(al::SensorMsg const*) {CRASH}
bool rs::isMsgDamageBallAttack(al::SensorMsg const*) {CRASH}
bool rs::isMsgDonsukeAttack(al::SensorMsg const*) {CRASH}
bool rs::isMsgGamaneBullet(al::SensorMsg const*) {CRASH}
bool rs::isMsgHackMarioCheckpointFlagWarp(al::SensorMsg const*) {CRASH}
bool rs::isMsgKillByHomeDemo(al::SensorMsg const*) {CRASH}
bool rs::isMsgKillByShineGet(al::SensorMsg const*) {CRASH}
bool rs::isMsgNpcScareByEnemy(al::SensorMsg const*) {CRASH}
bool rs::isMsgPechoSpot(al::SensorMsg const*) {CRASH}
bool rs::isMsgPressDown(al::SensorMsg const*) {CRASH}
bool rs::isMsgSeedTouch(al::SensorMsg const*) {CRASH}
bool rs::isMsgSenobiTrample(al::SensorMsg const*) {CRASH}
bool rs::isMsgStartHack(al::SensorMsg const*) {CRASH}
bool rs::isMsgTargetMarkerPosition(al::SensorMsg const*) {CRASH}
bool rs::isMsgTimerAthleticDemoStart(al::SensorMsg const*) {CRASH}
void rs::requestHitReactionToAttacker(al::SensorMsg const*, al::HitSensor const*, al::HitSensor const*) {CRASH}
bool rs::sendMsgPushToPlayer(al::HitSensor*, al::HitSensor*) {CRASH}
void rs::setAppearItemFactorAndOffsetByMsg(al::LiveActor const*, al::SensorMsg const*, al::HitSensor const*) {CRASH}
void rs::setBossBarrierField(BarrierField*) {CRASH}
void rs::setMsgTargetMarkerPosition(al::SensorMsg const*, sead::Vector3<float> const&) {CRASH}
void rs::setupHackShadow(al::LiveActor*) {CRASH}
IUsePlayerHack* rs::startHack(al::HitSensor*, al::HitSensor*, al::LiveActor*) {CRASH}
IUsePlayerHack* rs::startHackStartDemo(IUsePlayerHack*, al::LiveActor*) {CRASH}
bool rs::tryAppearMultiCoinFromObj(al::LiveActor*, al::HitSensor*, int, float) {CRASH}
bool rs::tryReceiveMsgNpcScareByEnemyIgnoreTargetHack(al::SensorMsg const*, CapTargetInfo const*) {CRASH}

void LifeUpItem::init(const al::ActorInitInfo& initInfo) {CRASH}
void LifeUpItem::initAfterPlacement() {CRASH}
bool LifeUpItem::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {CRASH}
void LifeUpItem::control() {CRASH}
void LifeUpItem2D::init(const al::ActorInitInfo& initInfo) {CRASH}
bool LifeUpItem2D::receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                al::HitSensor* self) {CRASH}
ActorDimensionKeeper* LifeUpItem2D::getActorDimensionKeeper() const {CRASH}
void Doshi::init(const al::ActorInitInfo& initInfo) {CRASH}
void Doshi::attackSensor(al::HitSensor* self, al::HitSensor* other) {CRASH}
bool Doshi::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {CRASH}
void Doshi::control() {CRASH}
void HackerJudge::reset() {CRASH}
void HackerJudge::update() {CRASH}
bool HackerJudge::judge() const {CRASH}
void Coin2D::init(const al::ActorInitInfo& initInfo) {CRASH}
void Coin2D::initAfterPlacement() {CRASH}
void Coin2D::appear() {CRASH}
void Coin2D::control() {CRASH}
void Coin2D::endClipped() {CRASH}
bool Coin2D::receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                al::HitSensor* self) {CRASH}
ActorDimensionKeeper* Coin2D::getActorDimensionKeeper() const {CRASH}
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
