#include "Library/Camera/CameraDirector.h"
#include "Library/Camera/CameraUtil.h"

namespace al {

CameraTicket* initDemoObjectCamera(al::IUseCamera const*, al::ActorInitInfo const&, char const*, char const*) {WARN_UNIMPL; return nullptr;}
void calcCameraLookDir(sead::Vector3<float>*, al::IUseCamera const*, int) {}
ActorMatrixCameraTarget* createActorMatrixCameraTarget(al::LiveActor const*, sead::Matrix34<float> const*) {WARN_UNIMPL; return nullptr;}
bool isActiveCamera(al::CameraTicket const*) {return false;}
bool isActiveCameraTarget(al::CameraTargetBase const*) {return false;}
void requestStopCameraVerticalAbsorb(al::IUseCamera*) {}
al::CameraTicket* initObjectCamera(al::IUseCamera const*, al::ActorInitInfo const&, char const*, char const*) {WARN_UNIMPL; return nullptr;}
void resetCameraTarget(al::IUseCamera*, al::CameraTargetBase*) {}
void setCameraTarget(al::IUseCamera*, al::CameraTargetBase*) {}
void startCamera(al::IUseCamera const*, al::CameraTicket*, int) {}
al::ActorCameraTarget* createActorCameraTarget(al::LiveActor const*, float) {WARN_UNIMPL; return nullptr;}
void endCamera(al::IUseCamera const*, al::CameraTicket*, int, bool) {}
void calcCameraFront(sead::Vector3f*, al::IUseCamera const*, int) {}

f32 CameraDirector::getSceneFovyDegree() {return 45.0f;}


}
