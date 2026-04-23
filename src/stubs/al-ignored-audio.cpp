#include <prim/seadSafeString.h>
#include "Library/Audio/System/AudioKeeper.h"
#include "Library/Audio/AudioDirector.h"
#include "Library/Audio/System/AudioKeeperFunction.h"
#include "Library/Audio/System/SimpleAudioUser.h"
#include "Library/Bgm/BgmLineFunction.h"
#include "Library/LiveActor/LiveActor.h"
#include "Library/Se/SeFunction.h"
#include "Library/Se/SeKeeper.h"
#include "Project/Action/ActionSeCtrl.h"
#include "Project/Action/ActionBgmCtrl.h"

namespace al {

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
void startBgmSituation(al::IUseAudioKeeper const*, char const*, bool) {}
void endBgmSituation(al::IUseAudioKeeper const*, char const*, bool) {}
bool isEnableRhythmAnim(al::IUseAudioKeeper const*, char const*) {return false;}
f32 getCurBeat(al::IUseAudioKeeper const*) {return 0.0f;}
f32 getCurBeatOnMeasure(al::IUseAudioKeeper const*) {return 0.0f;}
void tryUpdateSeMaterialCode(al::IUseAudioKeeper*, char const*) {}
void resetSeKeeperPlayNamePrefix(al::IUseAudioKeeper const*) {}
void setSeKeeperPlayNamePrefix(al::IUseAudioKeeper const*, char const*) {}
void startAndStopBgmInCurPosition(al::IUseAudioKeeper const*, bool) {}
void startBgm(al::IUseAudioKeeper const*, al::BgmPlayingRequest const&, bool, bool) {}
void stopBgm(al::IUseAudioKeeper const*, char const*, int) {}
bool isRunningBgm(al::IUseAudioKeeper const*, char const*) {return true;}

SimpleAudioUser::SimpleAudioUser(char const*, ActorInitInfo const&) {}
AudioKeeper* SimpleAudioUser::getAudioKeeper() const {WARN_UNIMPL;return nullptr;}

void AudioKeeper::appear() {}
void AudioKeeper::endClipped() {}
void AudioKeeper::kill() {}
void AudioKeeper::startClipped() {}
void AudioKeeper::initBgmKeeper(al::AudioDirector const*, char const*) {}
void AudioKeeper::initSeKeeper(al::AudioDirector const*, char const*, sead::Vector3<float> const*, sead::Matrix34<float> const*, al::ModelKeeper const*, al::CameraDirector*) {}

ActionBgmCtrl* ActionBgmCtrl::tryCreate(al::AudioKeeper*){WARN_UNIMPL; return nullptr;}
void ActionBgmCtrl::startAction(char const*) {}
void ActionBgmCtrl::update(float, float, float, bool) {}

void AudioDirector::finalize() {}
void AudioDirector::initAfterInitPlacement() {}
void AudioDirector::updatePost() {}
void AudioDirector::updatePre() {}

ActionSeCtrl* ActionSeCtrl::tryCreate(al::AudioKeeper*) {WARN_UNIMPL; return nullptr;}
void ActionSeCtrl::startAction(char const*) {}
void ActionSeCtrl::resetAction(bool) {}
void ActionSeCtrl::restartAction() {}
void ActionSeCtrl::update(float, float, float, bool) {}

void SeKeeper::resetPosition() {}

}

al::AudioKeeper* alAudioKeeperFunction::createAudioKeeper(al::AudioDirector const*, char const*, char const*) {WARN_UNIMPL; return nullptr;}
al::AudioKeeper* alAudioKeeperFunction::createAudioKeeper(al::AudioDirector const*) {WARN_UNIMPL; return nullptr;}

void alSeFunction::endListenerPoser(al::IUseAudioKeeper const*, char const*, int) {}
void alSeFunction::startListenerPoser(al::IUseAudioKeeper const*, char const*, int) {}

bool alAudioSystemFunction::tryDisableSoundMemoryPoolHandlerByFilePath(char const*, al::SeadAudioPlayer*) {return false;}
al::SeadAudioPlayer* alAudioSystemFunction::tryFindAudioPlayerRegistedSoundMemoryPoolHandler(char const*, al::SeadAudioPlayer*, al::SeadAudioPlayer*) {WARN_UNIMPL; return nullptr;}
