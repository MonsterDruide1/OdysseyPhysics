#include "playerUtil.h"

namespace al {

bool isPlayingEntranceCamera(al::IUseCamera const*, int) {
    return false;
}

bool isActiveCameraInterpole(al::IUseCamera const*, int) {
    return false;
}

}  // namespace al
