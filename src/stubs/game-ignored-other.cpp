
#include "PlayerUtil.h"

namespace rs {

// used too little to be worth implementing here (KinopioTent, Stand, Trampoline, Parasol and a few others)
bool isTouchJumpCode(al::LiveActor const*, IUsePlayerCollision const*) { return false; }

}

PlayerSandSinkAffect::PlayerSandSinkAffect(al::LiveActor const*, PlayerConst const*, PlayerInput const*, IUsePlayerCollision*, PlayerEffect*) {}
bool PlayerSandSinkAffect::isSinkDeathHeight() { return false; }
