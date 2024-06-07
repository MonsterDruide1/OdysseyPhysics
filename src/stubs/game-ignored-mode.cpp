
#include "PlayerUtil.h"
#include "System/GameDataFunction.h"

PlayerConst* PlayerFunction::createMarioConst(char const*) { return new PlayerConst(); }



namespace rs {

bool isClosetScenePlayer(PlayerInitInfo const&) { return false; }
bool isPlayer2D(const al::LiveActor* actor) { return false; }
bool isKidsMode(al::LiveActor const*) { return false; }

}

void GameDataFunction::disableCapByPlacement(al::LiveActor const*) {}

PlayerHackKeeper::PlayerHackKeeper(al::LiveActor*, HackCap*, PlayerRecoverySafetyPoint*, PlayerInput const*, sead::Matrix34<float> const*, PlayerDamageKeeper const*, IPlayerModelChanger const*, IUsePlayerHeightCheck const*) {}
void PlayerHackKeeper::createHackModel(al::ActorInitInfo const&) {}
bool PlayerHackKeeper::executeForceHackStageStart(al::HitSensor*, IUsePlayerHack*) { return false; }

PlayerRecoverySafetyPoint::PlayerRecoverySafetyPoint(al::LiveActor const*, HackCap const*, al::ActorInitInfo const&, IUseDimension const*, al::CollisionPartsFilterBase*, al::HitSensor*) {}
void PlayerRecoverySafetyPoint::updateRecoveryBubble() {}
