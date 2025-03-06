#include "Library/LiveActor/ActorSensorFunction.h"
#include "Library/LiveActor/ActorSensorUtil.h"

namespace al {

void invalidateHitSensors(LiveActor*) {}
void validateHitSensor(al::LiveActor*, char const*) {}
void validateHitSensors(al::LiveActor*) {}
bool calcDirBetweenSensorsH(sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*) {}
const sead::Vector3f& getActorTrans(al::HitSensor const*) {return const_cast<sead::Vector3f&>(sead::Vector3f::zero);}
const sead::Vector3f& getSensorPos(al::HitSensor const*) {return const_cast<sead::Vector3f&>(sead::Vector3f::zero);}
bool isSensorMapObj(al::HitSensor const*) {return false;}
bool isSensorName(al::HitSensor const*, char const*) {return false;}
bool isMySensor(HitSensor const*, LiveActor const*) { return false; }

bool isMsgAskSafetyPoint(SensorMsg const*) { return false; }
bool isMsgEnemyFloorTouch(SensorMsg const*) { return false; }
bool isMsgExplosion(SensorMsg const*) { return false; }
bool isMsgFloorTouch(SensorMsg const*) { return false; }
bool isMsgHideModel(SensorMsg const*) { return false; }
bool isMsgIsNerveSupportFreeze(SensorMsg const*) { return false; }
bool isMsgOffSyncSupportFreeze(SensorMsg const*) { return false; }
bool isMsgOnSyncSupportFreeze(SensorMsg const*) { return false; }
bool isMsgPlayerDisregard(SensorMsg const*) { return false; }
bool isMsgPlayerFloorTouch(SensorMsg const*) { return false; }
bool isMsgPlayerHipDropAll(SensorMsg const*) { return false; }
bool isMsgPlayerObjTouch(SensorMsg const*) { return false; }
bool isMsgRestart(SensorMsg const*) { return false; }
bool isMsgShowModel(SensorMsg const*) { return false; }
bool isMsgTouchAssist(SensorMsg const*) { return false; }
bool isMsgScreenPointInvalidCollisionParts(al::SensorMsg const*) { return false; }
bool isMsgPush(al::SensorMsg const*) { return false; }
bool isMsgEnemyAttackNeedle(al::SensorMsg const*) { return false; }
bool isMsgEnemyTouch(al::SensorMsg const*) { return false; }
bool isMsgEnemyAttackFire(al::SensorMsg const*) { return false; }
bool isMsgPlayerFireBallAttack(al::SensorMsg const*) { return false; }
bool isMsgPlayerTouch(al::SensorMsg const*) { return false; }
bool isMsgPlayerTrample(al::SensorMsg const*) { return false; }
bool isMsgPlayerTrampleReflect(al::SensorMsg const*) { return false; }

bool sendMsgExplosion(al::HitSensor*, al::HitSensor*, al::ComboCounter*) { return false; }
bool sendMsgPlayerHipDropKnockDown(al::HitSensor*, al::HitSensor*) { return false; }
bool sendMsgEnemyAttackFire(al::HitSensor*,al::HitSensor*,char const*) { return false; }
bool sendMsgRestart(al::LiveActor*) { return false; }
bool sendMsgEnemyAttack(al::HitSensor*, al::HitSensor*) { return false; }
bool sendMsgEnemyAttackNeedle(al::HitSensor*, al::HitSensor*) { return false; }
bool sendMsgPush(al::HitSensor*, al::HitSensor*) { return false; }
bool sendMsgPushAndKillVelocityToTarget(al::LiveActor*, al::HitSensor*, al::HitSensor*) { return false; }

}  // namespace al
