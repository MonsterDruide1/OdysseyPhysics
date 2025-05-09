#include "Player/PlayerInputFunction.h"
#include "Util/CameraUtil.h"

bool rs::isEnableStartSubjectiveCamera(al::LiveActor const*) {return false;}
bool PlayerInputFunction::isTriggerCameraReset(al::LiveActor const*, int) {return false;}
