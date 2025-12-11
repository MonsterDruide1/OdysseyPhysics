#include "Player/PlayerInput.h"
#include "Player/PlayerInputFunction.h"
#include "Util/CameraUtil.h"
#include "Util/InputInterruptTutorialUtil.h"

bool rs::isEnableStartSubjectiveCamera(al::LiveActor const*) {return false;}
bool rs::tryAppearPlayerCameraSubjectiveTutorial(al::IUseSceneObjHolder const*) {return false;}
void rs::tryClosePlayerCameraSubjectiveTutorial(al::IUseSceneObjHolder const*) {}
bool PlayerInputFunction::isTriggerCameraReset(al::LiveActor const*, int) {return false;}
bool PlayerInput::isTriggerCameraSubjective() const {return false;}
