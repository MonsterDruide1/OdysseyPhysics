#include <prim/seadSafeString.h>
#include "Library/Audio/System/AudioKeeper.h"
#include "Library/Audio/System/SimpleAudioUser.h"

namespace al {

void AudioKeeper::appear() {}
SimpleAudioUser::SimpleAudioUser(char const*, ActorInitInfo const&) {}
AudioKeeper* SimpleAudioUser::getAudioKeeper() const {}
void startBgmSituation(al::IUseAudioKeeper const*, char const*, bool, bool) {}
void startSe(al::IUseAudioKeeper const*, sead::SafeString const&) {}
bool tryStartSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&) {}
bool tryStartSeWithParam(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, float, char const*) {}
bool tryStopSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, int, char const*) {}
bool tryHoldSeWithParam(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, float, char const*) {}
void holdSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&) {}
    
}
