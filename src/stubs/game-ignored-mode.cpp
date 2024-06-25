
#include "Library/Collision/CollisionDirector.h"
#include "PlayerUtil.h"
#include "System/GameDataFunction.h"
#include "Util/ActorDimensionKeeper.h"
#include "Util/Hack.h"

PlayerConst* PlayerFunction::createMarioConst(char const*) { return new PlayerConst(); }



namespace rs {

bool isClosetScenePlayer(PlayerInitInfo const&) { return false; }
bool isPlayer2D(const al::LiveActor* actor) { return false; }
bool isKidsMode(al::LiveActor const*) { return false; }
bool isActiveDemo(al::LiveActor const*) { return false; }
bool calcHackerMoveDir(sead::Vector3f *, const IUsePlayerHack *, const sead::Vector3f &) { return false; }
bool isPlayerHack(al::LiveActor const*) { return false; }
al::CollisionPartsFilterBase* createCollisionPartsFilter2DOnly() { return nullptr; }
bool isModeE3Rom() { return false; }
bool isModeE3MovieRom() { return false; }
void addPlayerThrowCapCount(const al::LiveActor*) {}

}

PlayerDemoActionFlag::PlayerDemoActionFlag() {}

bool ActorDimensionKeeper::update() { return false; }

void GameDataFunction::disableCapByPlacement(al::LiveActor const*) {}
bool GameDataFunction::isMeetCap(GameDataHolderAccessor) { return true; }
bool GameDataFunction::isEnableCap(GameDataHolderAccessor) { return true; }
bool GameDataFunction::isPlayerLifeZero(GameDataHolderAccessor) { return false; }

PlayerHackKeeper::PlayerHackKeeper(al::LiveActor*, HackCap*, PlayerRecoverySafetyPoint*, PlayerInput const*, sead::Matrix34<float> const*, PlayerDamageKeeper const*, IPlayerModelChanger const*, IUsePlayerHeightCheck const*) {}
void PlayerHackKeeper::createHackModel(al::ActorInitInfo const&) {}
bool PlayerHackKeeper::executeForceHackStageStart(al::HitSensor*, IUsePlayerHack*) { return false; }

PlayerRecoverySafetyPoint::PlayerRecoverySafetyPoint(al::LiveActor const*, HackCap const*, al::ActorInitInfo const&, IUseDimension const*, al::CollisionPartsFilterBase*, al::HitSensor*) {}
void PlayerRecoverySafetyPoint::updateRecoveryBubble() {}

bool PlayerEquipmentFunction::tryGetEquipmentForceDashInfo(int*, float*, PlayerEquipmentUser const*) { return false; }
bool PlayerEquipmentFunction::isEquipmentNoCapThrow(PlayerEquipmentUser const*) { return false; }

PlayerPuppet::PlayerPuppet(al::LiveActor*, HackCap*, PlayerAnimator*, IUsePlayerCollision*, ActorDimensionKeeper*, IPlayerModelChanger*, WorldEndBorderKeeper*, PlayerCounterForceRun*, PlayerDamageKeeper*, PlayerEffect*, PlayerInput const*, PlayerConst const*) {}
bool PlayerPuppet::isNoCollide() { return false; }

PlayerStateRun2D::PlayerStateRun2D(al::LiveActor*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision const*, PlayerAnimator*) : al::NerveStateBase("") {}

PlayerJudgeSafetyPointRecovery::PlayerJudgeSafetyPointRecovery(IJudge *,PlayerStateAbyss const*) {}
void PlayerJudgeSafetyPointRecovery::reset() {}
void PlayerJudgeSafetyPointRecovery::update() {}
bool PlayerJudgeSafetyPointRecovery::judge() const {return false;}

PlayerJudgePreInputHackAction::PlayerJudgePreInputHackAction(PlayerConst const*,PlayerInput const*) {}
void PlayerJudgePreInputHackAction::reset() {}
void PlayerJudgePreInputHackAction::update() {}
bool PlayerJudgePreInputHackAction::judge() const {return false;}

bool HackCap::sendMsgStartHack(al::HitSensor*) { return false; }
