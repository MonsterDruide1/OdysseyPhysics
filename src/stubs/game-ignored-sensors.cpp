#include "Util/SensorMsgFunction.h"

namespace al {
class SensorMsg;
}

namespace rs {

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

bool sendMsgEnemyAttack2D(al::HitSensor*, al::HitSensor*) {return false;}
bool sendMsgTouchFireDrum2D(al::HitSensor*, al::HitSensor*) {return false;}

}
