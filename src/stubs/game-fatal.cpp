#include "Player/PlayerActorBase.h"
#include "Player/PlayerInput.h"
#include "Player/PlayerTrigger.h"
#include "PlayerUtil.h"
#include "Util/ObjUtil.h"
#include "Util/PlayerCollisionUtil.h"

bool PlayerActorBase::checkDeathArea() {CRASH}

bool rs::isPlayerOnGround(al::LiveActor const* actor) {CRASH}
void rs::reflectCeilingUpperPunch(al::LiveActor *,IUsePlayerCollision const*,PlayerInput const*,PlayerConst const*,PlayerTrigger const*,bool) {CRASH}

bool rs::findWallCatchPos(al::CollisionParts const**, sead::Vector3<float>*, sead::Vector3<float>*, al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float, float, float, float, float, float) {CRASH}
