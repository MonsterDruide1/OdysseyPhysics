#include "Library/Demo/DemoFunction.h"
#include "playerUtil.h"

namespace al {

bool isPlayingEntranceCamera(al::IUseCamera const*, int) {
    return false;
}

bool isActiveCameraInterpole(al::IUseCamera const*, int) {
    return false;
}

void addDemoActorFromAddDemoInfo(al::LiveActor const*,al::AddDemoInfo const*) {}
AddDemoInfo* registDemoRequesterToAddDemoInfo(al::LiveActor const*,al::ActorInitInfo const&,int) {WARN_UNIMPL;return nullptr;}
void registActorToDemoInfo(al::LiveActor*, al::ActorInitInfo const&) {}

}  // namespace al
