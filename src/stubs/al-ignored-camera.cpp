#include "Library/Camera/CameraArrowCollider.h"
#include "Library/Camera/CameraDirector.h"
#include "Library/Camera/CameraPoserFunction.h"
#include "Library/Camera/CameraTargetAreaLimitter.h"
#include "Library/Camera/CameraUtil.h"
#include "Library/Camera/SceneCameraInfo.h"
#include "Library/Camera/SnapShotCameraCtrl.h"
#include "Library/Play/Camera/CameraPoserSubjective.h"
#include "Library/Play/Camera/CameraVerticalAbsorber.h"
#include "Project/Action/ActionPadAndCameraCtrl.h"
#include "Project/Camera/CameraAngleCtrlInfo.h"

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

CameraPoserSubjective::CameraPoserSubjective(char const*) : al::CameraPoser("") {}
void CameraPoserSubjective::init() {}
void CameraPoserSubjective::loadParam(const ByamlIter&) {}
void CameraPoserSubjective::start(const CameraStartInfo&) {}
void CameraPoserSubjective::movement() {}
void CameraPoserSubjective::update() {}
void CameraPoserSubjective::startSnapShotMode() {}
void CameraPoserSubjective::endSnapShotMode() {}
bool CameraPoserSubjective::isZooming() const {return false;}
bool CameraPoserSubjective::isEnableRotateByPad() const {return false;}

al::CameraDirector::CameraDirector(int) { mSceneCameraInfo = new SceneCameraInfo(1); }
al::CameraDirector::~CameraDirector() {}
f32 CameraDirector::getSceneFovyDegree() {return 45.0f;}
void al::CameraDirector::endInit(al::PlayerHolder const*) {}
void al::CameraDirector::execute() {}
ActionPadAndCameraCtrl* ActionPadAndCameraCtrl::tryCreate(al::LiveActor const*, al::ActorResource const*, sead::Vector3<float> const*,
              char const*) {WARN_UNIMPL; return nullptr;}
void ActionPadAndCameraCtrl::notifyActorDead() {}
void ActionPadAndCameraCtrl::notifyActorEndClipped() {}
void ActionPadAndCameraCtrl::notifyActorStartClipped() {}

bool CameraAngleCtrlInfo::isFixByRangeHV() const {return false;}
void CameraAngleCtrlInfo::load(al::ByamlIter const&) {}
bool CameraAngleCtrlInfo::receiveRequestFromObject(al::CameraObjectRequestInfo const&) {return false;}
void CameraAngleCtrlInfo::start(float) {}

void CameraArrowCollider::makeLookAtCamera(sead::LookAtCamera*) const {}
void CameraArrowCollider::start() {}

void CameraPoser::movement() {}

bool CameraTargetAreaLimitter::applyAreaLimit(sead::Vector3<float>*, sead::Vector3<float> const&) {return false;}
CameraTargetAreaLimitter* CameraTargetAreaLimitter::tryCreate(al::PlacementInfo const&) {WARN_UNIMPL; return nullptr;}

void CameraVerticalAbsorber::exeAbsorb() {}
void CameraVerticalAbsorber::exeFollow() {}
void CameraVerticalAbsorber::exeFollowClimbPole() {}
void CameraVerticalAbsorber::exeFollowGround() {}
void CameraVerticalAbsorber::liberateAbsorb() {}
void CameraVerticalAbsorber::makeLookAtCamera(sead::LookAtCamera*) const {}

void SnapShotCameraCtrl::makeLookAtCameraLast(sead::LookAtCamera*) const {}
void SnapShotCameraCtrl::makeLookAtCameraPost(sead::LookAtCamera*) const {}
void SnapShotCameraCtrl::start(float) {}

}

namespace alCameraPoserFunction {

void calcOffsetCameraKeepInFrameV(sead::Vector3<float>*, sead::LookAtCamera*, sead::Vector3<float> const&, al::CameraPoser const*, float, float) {}
void calcPreCameraDir(sead::Vector3<float>*, al::CameraPoser const*) {}
void calcTargetFront(sead::Vector3<float>*, al::CameraPoser const*) {}
void calcTargetGravity(sead::Vector3<float>*, al::CameraPoser const*) {}
void calcTargetTransWithOffset(sead::Vector3<float>*, al::CameraPoser const*) {}
f32 getAspect(al::CameraPoser const*) {return 1.0f;}
f32 getFar(al::CameraPoser const*) {return 1.0f;}
f32 getNear(al::CameraPoser const*) {return 1.0f;}
const sead::Vector3f& getPreLookAtPos(al::CameraPoser const*) {return sead::Vector3f::zero;}
bool isPlayerTypeHighJump(al::CameraPoser const*) {return false;}
bool isPlayerTypeNotTouchGround(al::CameraPoser const*) {return false;}
bool isSnapShotMode(al::CameraPoser const*) {return false;}
bool isTargetClimbPole(al::CameraPoser const*) {return false;}
bool isTargetCollideGround(al::CameraPoser const*) {return false;}
bool isTargetGrabCeil(al::CameraPoser const*) {return false;}

}

al::CameraTicket* alCameraFunction::initCamera(al::CameraPoser*, al::IUseCamera const*, al::ActorInitInfo const&, char const*, int) {WARN_UNIMPL; return nullptr;}
