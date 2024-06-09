#include "Library/Controller/JoyPadAccelPoseAnalyzer.h"
#include "Library/stuff.h"
#include "Player/PlayerInput.h"
#include "Player/PlayerInputFunction.h"

al::PadRumbleKeeper* al::getPlayerPadRumbleKeeper(al::LiveActor const*, int) { WARN_UNIMPL;int val; return (al::PadRumbleKeeper*)&val; }
void al::JoyPadAccelPoseAnalyzer::update() { WARN_UNIMPL; }
bool PlayerInputFunction::isTriggerCameraReset(al::LiveActor const*, int) { WARN_UNIMPL;return false; }
void PlayerInput::updateInput3D() { WARN_UNIMPL; }
void PlayerInput::updateInput2D() { WARN_UNIMPL; }
void PlayerInput::updateWallAlong() { WARN_UNIMPL; }
