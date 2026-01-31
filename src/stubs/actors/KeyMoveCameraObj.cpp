#include "Library/Obj/KeyMoveCameraObj.h"

namespace al {

KeyMoveCameraObj::KeyMoveCameraObj(const char* name) : al::LiveActor(name) {}
void KeyMoveCameraObj::init(const ActorInitInfo&) {}
void KeyMoveCameraObj::initAfterPlacement() {}
void KeyMoveCameraObj::switchCamera(s32) {}
void KeyMoveCameraObj::appear() {}
void KeyMoveCameraObj::control() {}
CameraPoser* KeyMoveCameraObj::getCurrentCamera() const {WARN_UNIMPL;return nullptr;}
CameraTicket* KeyMoveCameraObj::getCurrentCameraTicket() const {WARN_UNIMPL;return nullptr;}
void KeyMoveCameraObj::kill() {}
void KeyMoveCameraObj::setFirstCameraStartInterpoleStepDefault() {}
void KeyMoveCameraObj::validateStartAtNearestPosition() {}
void KeyMoveCameraObj::setPlaySumStep(s32) {}
void KeyMoveCameraObj::setEndWaitStep(s32) {}

}
