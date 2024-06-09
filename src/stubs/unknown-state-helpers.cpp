#include "Library/Math/MathLengthUtil.h"
#include "Player/HackCap.h"
#include "Player/PlayerInput.h"
#include "Player/PlayerTrigger.h"
#include "Stuff.h"

void HackCap::startCatch(char const*, bool, sead::Vector3<float> const&) { WARN_UNIMPL; }
void rs::slerpUp(al::LiveActor*, sead::Vector3<float> const&, float, float) { WARN_UNIMPL; }
bool PlayerTrigger::isOnUpperPunchHit() const { WARN_UNIMPL;return false; }
bool rs::isOnGroundAndGravity(al::LiveActor const*, IUsePlayerCollision const*) { WARN_UNIMPL;return false; }
bool rs::isCollidedCeiling(IUsePlayerCollision const*) { WARN_UNIMPL;return false; }
void rs::reflectCeiling(al::LiveActor*, float) { WARN_UNIMPL; }
void PlayerActionDiveInWater::tryChangeDiveInWaterAnim() { WARN_UNIMPL; }
bool al::limitLength(sead::Vector3<float>*, sead::Vector3<float> const&, float) { WARN_UNIMPL;return false; }
bool PlayerInput::isHoldCapSeparateJump() const { WARN_UNIMPL;return false; }
