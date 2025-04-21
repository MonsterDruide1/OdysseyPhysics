#include <prim/seadSafeString.h>
#include "Library/Audio/System/AudioKeeper.h"
#include "Library/Audio/AudioDirector.h"
#include "Library/Audio/System/SimpleAudioUser.h"
#include "Library/LiveActor/LiveActor.h"
#include "Project/Action/ActionSeCtrl.h"

namespace al {

AudioKeeper* SimpleAudioUser::getAudioKeeper() const {WARN_UNIMPL;return nullptr;}

void AudioKeeper::appear() {}
void AudioKeeper::endClipped() {}
void AudioKeeper::kill() {}
void AudioKeeper::startClipped() {}

void AudioDirector::finalize() {CRASH}
void AudioDirector::initAfterInitPlacement() {CRASH}
void AudioDirector::updatePost() {CRASH}
void AudioDirector::updatePre() {CRASH}

SimpleAudioUser::SimpleAudioUser(char const*, ActorInitInfo const&) {}
void startBgmSituation(al::IUseAudioKeeper const*, char const*, bool, bool) {}
void startSe(al::IUseAudioKeeper const*, sead::SafeString const&) {}
bool tryStartSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&) {return false;}
bool tryStartSeWithParam(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, float, char const*) {return false;}
bool tryStopSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, int, char const*) {return false;}
bool tryHoldSeWithParam(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, float, char const*) {return false;}
void holdSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&) {}
bool checkIsPlayingSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, char const*) {return true;}
void startSeWithParam(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, float, char const*) {}
bool isExistSeKeeper(al::IUseAudioKeeper const*) {return false;}
void stopSe(al::IUseAudioKeeper const*, sead::SafeStringBase<char> const&, int, char const*) {}

void ActionSeCtrl::resetAction(bool) {}
void ActionSeCtrl::restartAction() {}

bool isEnableRhythmAnim(al::IUseAudioKeeper const*, char const*) {return false;}
f32 getCurBeat(al::IUseAudioKeeper const*) {return 0.0f;}
f32 getCurBeatOnMeasure(al::IUseAudioKeeper const*) {return 0.0f;}

void tryUpdateSeMaterialCode(al::IUseAudioKeeper*, char const*) {}

void initActorBgmKeeper(al::LiveActor*, al::ActorInitInfo const&, char const*) {}
void initActorSeKeeper(al::LiveActor*, al::ActorInitInfo const&, char const*) {}
    
}
