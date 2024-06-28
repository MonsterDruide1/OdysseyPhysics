#include "Library/Controller/JoyPadAccelPoseAnalyzer.h"
#include "Library/stuff.h"
#include "Player/PlayerInput.h"
#include "Player/PlayerInputFunction.h"

al::PadRumbleKeeper* al::getPlayerPadRumbleKeeper(al::LiveActor const*, int) { WARN_UNIMPL;int val; return (al::PadRumbleKeeper*)&val; }
bool PlayerInputFunction::isTriggerCameraReset(al::LiveActor const*, int) { WARN_UNIMPL;return false; }
