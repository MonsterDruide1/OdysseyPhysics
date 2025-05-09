#include "Util/ObjUtil.h"
#include "Util/SensorMsgFunction.h"

namespace al {
class SensorMsg;
}

namespace rs {

void requestHitReactionToAttacker(al::SensorMsg const*, al::HitSensor const*, sead::Vector3f const&) {}
void requestHitReactionToAttacker(al::SensorMsg const*, al::HitSensor const*, al::HitSensor const*) {}

bool isMsgCapCancelLockOn(al::SensorMsg const*) {return false;}
bool isMsgCapIgnoreCancelLockOn(al::SensorMsg const*) {return false;}
bool isMsgCapKeepLockOn(al::SensorMsg const*) {return false;}
bool isMsgCapStartLockOn(al::SensorMsg const*) {return false;}
bool isMsgCapTouchWall(al::SensorMsg const*) {return false;}
bool isMsgItemGet2D(al::SensorMsg const*) {return false;}
bool isMsgItemGetByWeapon(al::SensorMsg const*) {return false;}
bool isMsgKoopaHackPunchCollide(al::SensorMsg const*) {return false;}
bool isMsgNpcCapReactionAll(al::SensorMsg const*) {return false;}
bool isMsgPlayerAndCapHipDropAll(al::SensorMsg const*) {return false;}
bool isMsgPlayerDisregardHomingAttack(al::SensorMsg const*) {return false;}
bool isMsgPlayerDisregardTargetMarker(al::SensorMsg const*) {return false;}
bool isMsgPlayerRollingWallHitDown(al::SensorMsg const*) {return false;}
bool isMsgAirExplosion(al::SensorMsg const*) {return false;}
bool isMsgByugoBlow(al::SensorMsg const*) {return false;}
bool isMsgCapAttack(al::SensorMsg const*) {return false;}
bool isMsgFishingItemGet(al::SensorMsg const*) {return false;}
bool isMsgFishingLineTouch(al::SensorMsg const*) {return false;}
bool isMsgItemAmiiboKoopa(al::SensorMsg const*) {return false;}
bool isMsgItemGetAll(al::SensorMsg const*) {return false;}
bool isMsgBlowDown(al::SensorMsg const*) {return false;}
bool isMsgCapAttackCollide(al::SensorMsg const*) {return false;}
bool isMsgCapEnableLockOn(al::SensorMsg const*) {return false;}
bool isMsgCapReflect(al::SensorMsg const*) {return false;}
bool isMsgConductLightning(al::SensorMsg const*) {return false;}
bool isMsgDamageBallAttack(al::SensorMsg const*) {return false;}
bool isMsgDonsukeAttack(al::SensorMsg const*) {return false;}
bool isMsgGamaneBullet(al::SensorMsg const*) {return false;}
bool isMsgHackMarioCheckpointFlagWarp(al::SensorMsg const*) {return false;}
bool isMsgKillByHomeDemo(al::SensorMsg const*) {return false;}
bool isMsgKillByShineGet(al::SensorMsg const*) {return false;}
bool isMsgNpcScareByEnemy(al::SensorMsg const*) {return false;}
bool isMsgPechoSpot(al::SensorMsg const*) {return false;}
bool isMsgPressDown(al::SensorMsg const*) {return false;}
bool isMsgSeedTouch(al::SensorMsg const*) {return false;}
bool isMsgSenobiTrample(al::SensorMsg const*) {return false;}
bool isMsgStartHack(al::SensorMsg const*) {return false;}
bool isMsgTargetMarkerPosition(al::SensorMsg const*) {return false;}
bool isMsgTimerAthleticDemoStart(al::SensorMsg const*) {return false;}
bool isMsgBubbleAttackToPecho(al::SensorMsg const*) {return false;}
bool isMsgBubbleGroundTouchTrigger(al::SensorMsg const*) {return false;}
bool isMsgCapHipDrop(al::SensorMsg const*) {return false;}
bool isMsgFrogHackTrample(al::SensorMsg const*) {return false;}
bool isMsgPlayerAndCapObjHipDropReflectAll(al::SensorMsg const*) {return false;}
bool isMsgHosuiAttack(al::SensorMsg const*) {return false;}
bool isMsgBossKnuckleFallAttack(al::SensorMsg const*) {return false;}
bool isMsgBossKnuckleIceFallToMummy(al::SensorMsg const*) {return false;}
bool isMsgBullAttack(al::SensorMsg const*) {return false;}
bool isMsgCactusNeedleAttack(al::SensorMsg const*) {return false;}
bool isMsgGamaneBulletThrough(al::SensorMsg const*) {return false;}
bool isMsgSeedAttack(al::SensorMsg const*) {return false;}
bool isMsgSphinxRideAttack(al::SensorMsg const*) {return false;}
bool isMsgBlockUpperPunch2D(al::SensorMsg const*) {return false;}
bool isMsgKouraAttack2D(al::SensorMsg const*) {return false;}
bool isMsgPush2D(al::SensorMsg const*) {return false;}
bool isMsgPlayerAndCapObjHipDropAll(al::SensorMsg const*) {return false;}
bool isMsgAttackDirect(al::SensorMsg const*) {return false;}
bool isMsgPlayerObjLeapFrog(al::SensorMsg const*) {return false;}
bool isMsgCancelHack(al::SensorMsg const*) {return false;}
bool isMsgEnableMapCheckPointWarp(al::SensorMsg const*) {return false;}
bool isMsgHackMarioDead(al::SensorMsg const*) {return false;}
bool isMsgHackMarioDemo(al::SensorMsg const*) {return false;}
bool isMsgHackSyncDamageVisibility(al::SensorMsg const*) {return false;}
bool isMsgHackerDamageAndCancel(al::SensorMsg const*) {return false;}
bool isMsgHammerBrosHammerHackAttack(al::SensorMsg const*) {return false;}
bool isMsgMotorcycleDashAttack(al::SensorMsg const*) {return false;}
bool isMsgRadishReflect(al::SensorMsg const*) {return false;}
bool isMsgSeedReflect(al::SensorMsg const*) {return false;}
bool isMsgTankExplosion(al::SensorMsg const*) {return false;}
bool isMsgPushToPlayer(al::SensorMsg const*) {return false;}
bool isMsgCancelHackByDokan(al::SensorMsg const*) {return false;}
bool isMsgEnableMapCheckPointWarpCollidedGround(al::SensorMsg const*, al::LiveActor const*) {return false;}
bool isMsgSphinxRideAttackReflect(al::SensorMsg const*) {return false;}
bool isMsgThrowObjHitReflect(al::SensorMsg const*) {return false;}

bool isVisibleChameleon(al::SensorMsg const*) {return false;}
void setMsgTargetMarkerPosition(al::SensorMsg const*, sead::Vector3f const&) {}
bool tryGetAirExplosionForce(sead::Vector3f*, al::SensorMsg const*) {return false;}
bool tryGetByugoBlowForce(sead::Vector3f*, al::SensorMsg const*) {return false;}
bool tryReceiveMsgNpcScareByEnemyIgnoreTargetHack(al::SensorMsg const*, CapTargetInfo const*) {return false;}
bool tryGetSandGeyserRaise(al::SensorMsg const*, float*, float*) {return false;}

bool sendMsgEnemyAttack2D(al::HitSensor*, al::HitSensor*) {return false;}
bool sendMsgTouchFireDrum2D(al::HitSensor*, al::HitSensor*) {return false;}
bool sendMsgPushToPlayer(al::HitSensor*, al::HitSensor*) {return false;}
bool sendMsgPush2D(al::HitSensor*, al::HitSensor*) {return false;}
bool sendMsgKuriboGirlAttack(al::HitSensor*, al::HitSensor*) {return false;}
bool sendMsgKuriboGirlLove(al::HitSensor*, al::HitSensor*) {return false;}
bool sendMsgHackAttackKick(al::HitSensor*, al::HitSensor*) {return false;}
bool sendMsgHackAttackMapObj(al::HitSensor*, al::HitSensor*) {return false;}
bool sendMsgMeganeAttack(al::HitSensor*, al::HitSensor*) {return false;}
bool sendMsgMeganeHackTrample(al::HitSensor*, al::HitSensor*) {return false;}

void sendPlayerCollisionTouchMsg(al::LiveActor const*, al::HitSensor*, IUsePlayerCollision const*) {}

}
