
#include "Enemy/GamaneHackState.h"
#include "Enemy/HackerDepthShadowMapCtrl.h"
#include "Library/Collision/CollisionDirector.h"
#include "Library/Scene/DemoDirector.h"
#include "Player/HackerJudge.h"
#include "Player/PlayerHackStartShaderCtrl.h"
#include "PlayerUtil.h"
#include "System/GameDataFunction.h"
#include "Util/ActorDimensionKeeper.h"
#include "Util/Hack.h"

PlayerConst* PlayerFunction::createMarioConst(char const*) {
    return new PlayerConst();
}

namespace rs {

bool isClosetScenePlayer(PlayerInitInfo const&) {
    return false;
}

bool isPlayer2D(const al::LiveActor* actor) {
    return false;
}

bool isPlayer3D(const al::LiveActor* actor) {
    return true;
}

bool isKidsMode(al::LiveActor const*) {
    return false;
}

bool isActiveDemo(al::LiveActor const*) {
    return false;
}

bool calcHackerMoveDir(sead::Vector3f*, const IUsePlayerHack*, const sead::Vector3f&) {
    return false;
}

bool isPlayerHack(al::LiveActor const*) {
    return false;
}

bool isPlayerEnableToSeeOddSpace(al::LiveActor const*) {
    return false;
}

al::CollisionPartsFilterOnlySpecialPurpose* createCollisionPartsFilter2DOnly() {
    return nullptr;
}

bool isModeE3Rom() {
    return false;
}

bool isModeE3MovieRom() {
    return false;
}

void addPlayerThrowCapCount(const al::LiveActor*) {}

void snap2D(al::LiveActor*, IUseDimension const*, float) {}

void snap2DParallelizeFront(al::LiveActor*, IUseDimension const*, float) {}

void createAndSetFilter2DOnly(al::LiveActor*) {}

void snap2DGravity(al::LiveActor*, IUseDimension const*, float) {}

al::AreaObj* tryFind2DAreaObj(al::LiveActor const*, sead::Vector3<float>*, sead::Vector3<float>*) {WARN_UNIMPL;return nullptr;}

void calc2DAreaLockDir(sead::Vector3<float>*, al::AreaObj const*, sead::Vector3<float> const&) {}

bool isMsgPlayerItemGet2D(al::SensorMsg const*) {return false;}

void endHack(IUsePlayerHack**) {}
void endHackShadow(al::LiveActor*) {}
void endHackStartDemo(IUsePlayerHack*, al::LiveActor*) {}
const char* getSpecialPurposeName2DOnly() {return "";}
void hideShadowHackCap(IUsePlayerHack*) {}
void initHackShadow(al::LiveActor*) {}
bool isHackStartDemoEnterMario(IUsePlayerHack const*) {return false;}
void setupHackShadow(al::LiveActor*) {}
IUsePlayerHack* startHack(al::HitSensor*, al::HitSensor*, al::LiveActor*) {WARN_UNIMPL;return nullptr;}
IUsePlayerHack* startHackStartDemo(IUsePlayerHack*, al::LiveActor*) {WARN_UNIMPL;return nullptr;}
bool isPlayerHackKuriboAny(al::LiveActor const*) {return false;}
bool isPlayerHackTank(al::LiveActor const*) {return false;}
void requestEndDemoNormal(al::LiveActor const*) {}
bool requestStartDemoNormal(al::LiveActor*, bool) {return false;}

}  // namespace rs

GamaneHackState::GamaneHackState(al::LiveActor*a) : al::ActorStateBase("", a) {}
void GamaneHackState::attackSensor(al::HitSensor*, al::HitSensor*) {}
void GamaneHackState::initialize(al::ActorInitInfo const&) {}
bool GamaneHackState::isHackEnd() const {return false;}
bool GamaneHackState::receiveMsg(al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {return false;}
void GamaneHackState::appear() {}
void GamaneHackState::kill() {}

void HackerJudge::reset() {}
void HackerJudge::update() {}
bool HackerJudge::judge() const {return false;}

HackerDepthShadowMapCtrl::HackerDepthShadowMapCtrl(al::LiveActor*, char const*, float, float, float) {}
void HackerDepthShadowMapCtrl::update(PlayerCollider*) {}
HackerJudgeNormalFall::HackerJudgeNormalFall(al::LiveActor const*, int) : HackerJudge(nullptr) {}
void HackerJudgeNormalFall::reset() {}
void HackerJudgeNormalFall::update() {}
bool HackerJudgeNormalFall::judge() const {return false;}
PlayerHackStartShaderCtrl::PlayerHackStartShaderCtrl(al::LiveActor*, PlayerHackStartShaderParam*) {}
void PlayerHackStartShaderCtrl::end() {}
void PlayerHackStartShaderCtrl::start() {}
void PlayerHackStartShaderCtrl::update() {}
void al::DemoDirector::addDemoActor(al::LiveActor*) {}
void al::DemoDirector::requestEndDemo(char const*) {}
bool al::DemoDirector::requestStartDemo(char const*) {return false;}

PlayerDemoActionFlag::PlayerDemoActionFlag() {}

bool ActorDimensionKeeper::update() {
    return false;
}

void GameDataFunction::disableCapByPlacement(al::LiveActor const*) {}

bool GameDataFunction::isMeetCap(GameDataHolderAccessor) {
    return true;
}

bool GameDataFunction::isEnableCap(GameDataHolderAccessor) {
    return true;
}

bool GameDataFunction::isPlayerLifeZero(GameDataHolderAccessor) {
    return false;
}

PlayerHackKeeper::PlayerHackKeeper(al::LiveActor*, HackCap*, PlayerRecoverySafetyPoint*,
                                   PlayerInput const*, sead::Matrix34<float> const*,
                                   PlayerDamageKeeper const*, IPlayerModelChanger const*,
                                   IUsePlayerHeightCheck const*) {}

void PlayerHackKeeper::createHackModel(al::ActorInitInfo const&) {}

bool PlayerHackKeeper::executeForceHackStageStart(al::HitSensor*, IUsePlayerHack*) {
    return false;
}

const char* PlayerHackKeeper::getCurrentHackName() const {
    return nullptr;
}
al::CollisionPartsFilterBase* PlayerHackKeeper::getCollisionPartsFilter() const {
    return nullptr;
}

PlayerRecoverySafetyPoint::PlayerRecoverySafetyPoint(al::LiveActor const*, HackCap const*,
                                                     al::ActorInitInfo const&, IUseDimension const*,
                                                     al::CollisionPartsFilterBase*,
                                                     al::HitSensor*) {}

void PlayerRecoverySafetyPoint::updateRecoveryBubble() {}

bool PlayerEquipmentFunction::tryGetEquipmentForceDashInfo(int*, float*,
                                                           PlayerEquipmentUser const*) {
    return false;
}

bool PlayerEquipmentFunction::isEquipmentNoCapThrow(PlayerEquipmentUser const*) {
    return false;
}

PlayerPuppet::PlayerPuppet(al::LiveActor*, HackCap*, PlayerAnimator*, IUsePlayerCollision*,
                           ActorDimensionKeeper*, IPlayerModelChanger*, WorldEndBorderKeeper*,
                           PlayerCounterForceRun*, PlayerDamageKeeper*, PlayerEffect*,
                           PlayerInput const*, PlayerConst const*) {}

bool PlayerPuppet::isNoCollide() {
    return false;
}

PlayerStateRun2D::PlayerStateRun2D(al::LiveActor*, PlayerConst const*, PlayerInput const*,
                                   IUsePlayerCollision const*, PlayerAnimator*)
    : al::NerveStateBase("") {}

PlayerJudgeSafetyPointRecovery::PlayerJudgeSafetyPointRecovery(IJudge*, PlayerStateAbyss const*) {}

void PlayerJudgeSafetyPointRecovery::reset() {}

void PlayerJudgeSafetyPointRecovery::update() {}

bool PlayerJudgeSafetyPointRecovery::judge() const {
    return false;
}

PlayerJudgePreInputHackAction::PlayerJudgePreInputHackAction(PlayerConst const*,
                                                             PlayerInput const*) {}

void PlayerJudgePreInputHackAction::reset() {}

void PlayerJudgePreInputHackAction::update() {}

bool PlayerJudgePreInputHackAction::judge() const {
    return false;
}

bool HackCap::sendMsgStartHack(al::HitSensor*) {
    return false;
}

PlayerJudgeEnableGuideArrow::PlayerJudgeEnableGuideArrow(PlayerPuppet const*) {}

void PlayerJudgeEnableGuideArrow::reset() {}

void PlayerJudgeEnableGuideArrow::update() {}

bool PlayerJudgeEnableGuideArrow::judge() const {
    return false;
}

PlayerJudgeEnablePeachAmiibo::PlayerJudgeEnablePeachAmiibo(PlayerStateDamageFire const*) {}

void PlayerJudgeEnablePeachAmiibo::reset() {}

void PlayerJudgeEnablePeachAmiibo::update() {}

bool PlayerJudgeEnablePeachAmiibo::judge() const {
    return false;
}

PlayerJudgeCameraSubjective::PlayerJudgeCameraSubjective(al::LiveActor const*,
                                                         IUsePlayerCollision const*,
                                                         PlayerInput const*) {}

void PlayerJudgeCameraSubjective::reset() {}

void PlayerJudgeCameraSubjective::update() {}

bool PlayerJudgeCameraSubjective::judge() const {
    return false;
}

PlayerJudgeActiveCameraSubjective::PlayerJudgeActiveCameraSubjective(
    PlayerStateCameraSubjective const*) {}

void PlayerJudgeActiveCameraSubjective::reset() {}

void PlayerJudgeActiveCameraSubjective::update() {}

bool PlayerJudgeActiveCameraSubjective::judge() const {
    return false;
}

PlayerJudgeFailureCameraSubjective::PlayerJudgeFailureCameraSubjective(PlayerInput const*,
                                                                       IJudge const*) {}

void PlayerJudgeFailureCameraSubjective::reset() {}

void PlayerJudgeFailureCameraSubjective::update() {}

bool PlayerJudgeFailureCameraSubjective::judge() const {
    return false;
}

PlayerStateBind::PlayerStateBind(al::LiveActor*, PlayerConst const*, PlayerInput const*,
                                 PlayerPuppet const*, IUsePlayerCollision const*, PlayerTrigger*)
    : al::NerveStateBase("") {}

PlayerStateHack::PlayerStateHack(al::LiveActor*, PlayerHackKeeper*, IPlayerModelChanger*,
                                 PlayerAnimator*, HackCap*)
    : al::NerveStateBase("") {}

PlayerStateEndHack::PlayerStateEndHack(al::LiveActor*, PlayerConst const*,
                                       IUsePlayerCollision const*, PlayerInput const*,
                                       PlayerTrigger*, PlayerAnimator*)
    : al::NerveStateBase("") {}

PlayerStateCameraSubjective::PlayerStateCameraSubjective(al::LiveActor*, al::CameraTicket*,
                                                         IPlayerModelChanger*, PlayerCarryKeeper*,
                                                         PlayerAnimator*, PlayerConst const*,
                                                         IUsePlayerCollision const*,
                                                         PlayerInput const*)
    : al::NerveStateBase("") {}

bool PlayerStateHack::isEnableModelSyncShowHide() {
    return false;
}

PlayerJudgeSleep::PlayerJudgeSleep(PlayerStateWait const*) {}

void PlayerJudgeSleep::reset() {}

void PlayerJudgeSleep::update() {}

bool PlayerJudgeSleep::judge() const {
    return false;
}
