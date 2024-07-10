#include "Player/PlayerActorBase.h"
#include "Player/PlayerInput.h"
#include "Player/PlayerTrigger.h"
#include "PlayerUtil.h"
#include "Stuff.h"
#include "Util/ObjUtil.h"
#include "Util/PlayerCollisionUtil.h"

bool PlayerActorBase::checkDeathArea() {
    CRASH
}

bool rs::isPlayerOnGround(al::LiveActor const* actor) {
    CRASH
}

void rs::reflectCeilingUpperPunch(al::LiveActor*, IUsePlayerCollision const*, PlayerInput const*,
                                  PlayerConst const*, PlayerTrigger const*, bool) {
    CRASH
}

void rs::sendMsgPlayerStartWallJump(al::HitSensor*, al::HitSensor*) {
    CRASH
}

// 2D-related
void rs::calcLockDirection(sead::Vector3f*, const IUseDimension*) {
    CRASH
}
