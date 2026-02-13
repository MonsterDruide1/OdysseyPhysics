#include "MapObj/WorldWarpHole.h"

WorldWarpHole::WorldWarpHole(const char* n) : al::LiveActor(n) {}
void WorldWarpHole::init(const al::ActorInitInfo&) {}
void WorldWarpHole::initAfterPlacement() {}
bool WorldWarpHole::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {return false;}
void WorldWarpHole::control() {}
void WorldWarpHole::exeCloseWait() {}
void WorldWarpHole::exeOpenWait() {}
void WorldWarpHole::exeInvalidStart() {}
void WorldWarpHole::exeInvalid() {}
void WorldWarpHole::exeInvalidEnd() {}
void WorldWarpHole::exeBindStart() {}
void WorldWarpHole::exeBind() {}
void WorldWarpHole::exeIn() {}
void WorldWarpHole::exeInAfter() {}
void WorldWarpHole::exeOutBefore() {}
void WorldWarpHole::exeOut() {}
void WorldWarpHole::exeOutBindRequest() {}
