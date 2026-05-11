#include "Util/ObjUtil.h"
#include "Util/SensorMsgFunction.h"

namespace al {
class SensorMsg;
}

namespace rs {

al::HitSensor* tryGetCollidedCeilingSensor(IUsePlayerCollision const*) {WARN_UNIMPL;return nullptr;}

void sendPlayerCollisionTouchMsg(al::LiveActor const*, al::HitSensor*, IUsePlayerCollision const*) {}
void sendMsgBreakFloorToPlayer(al::LiveActor const*) {}

}
