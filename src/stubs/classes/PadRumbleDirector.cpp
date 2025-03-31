#include "Library/Controller/PadRumbleDirector.h"

namespace al {

void PadRumbleDirector::changeRumbleLoopVolume(char const*, sead::Vector3<float> const*, float, float, int) {}
void PadRumbleDirector::startRumble(char const*, sead::Vector3<float> const&, al::PadRumbleParam const&, int) {}
void PadRumbleDirector::startRumbleNo3D(char const*, al::PadRumbleParam const&, int) {}
void PadRumbleDirector::stopPadRumbleOneTime(char const*, int) {}
void PadRumbleDirector::startRumbleLoop(char const*, sead::Vector3<float> const*, al::PadRumbleParam const&, int) {}
void PadRumbleDirector::startRumbleLoopNo3D(char const*, sead::Vector3<float> const*, al::PadRumbleParam const&, int) {}
void PadRumbleDirector::stopRumbleLoop(char const*, sead::Vector3<float> const*, int) {}
bool PadRumbleDirector::checkIsAliveRumbleLoop(char const*, sead::Vector3<float> const*, int) {return true;}
void PadRumbleDirector::changeRumbleLoopPitch(char const*, sead::Vector3<float> const*, float, float, int) {}
void PadRumbleDirector::startRumbleDirectValue(float, float, float, float, float, float, int) {}
void PadRumbleDirector::stopRumbleDirectValue(int) {}
void PadRumbleDirector::startRumbleWithVolume(char const*, float, float, int) {}


}
