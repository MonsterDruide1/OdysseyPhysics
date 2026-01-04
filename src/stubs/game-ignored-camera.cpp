#include "Player/PlayerInput.h"
#include "Player/PlayerInputFunction.h"
#include "PlayerUtil.h"
#include "Util/CameraUtil.h"
#include "Util/InputInterruptTutorialUtil.h"
#include "Util/ScenePlayerCameraFunction.h"

bool rs::isEnableStartSubjectiveCamera(al::LiveActor const*) {return false;}
bool rs::tryAppearPlayerCameraSubjectiveTutorial(al::IUseSceneObjHolder const*) {return false;}
void rs::tryClosePlayerCameraSubjectiveTutorial(al::IUseSceneObjHolder const*) {}
bool PlayerInputFunction::isTriggerCameraReset(al::LiveActor const*, int) {return false;}
bool PlayerInput::isTriggerCameraSubjective() const {return false;}
bool PlayerCameraFunction::checkNoCollisionForPlayerSubjectiveCamera(al::LiveActor const*, al::CameraTicket const*, bool) {CRASH}

PlayerJudgeActiveCameraSubjective::PlayerJudgeActiveCameraSubjective(PlayerStateCameraSubjective const*) {}
void PlayerJudgeActiveCameraSubjective::reset() {}
void PlayerJudgeActiveCameraSubjective::update() {}
bool PlayerJudgeActiveCameraSubjective::judge() const {return false;}
