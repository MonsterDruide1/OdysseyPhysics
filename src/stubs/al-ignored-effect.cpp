#include "Library/Effect/EffectSystemInfo.h"

namespace al {


void deleteEffect(al::IUseEffectKeeper*, char const*) {}
void emitEffect(al::IUseEffectKeeper*, char const*, sead::Vector3<float> const*) {}
void setEffectFollowMtxPtr(al::IUseEffectKeeper*,const char*,sead::Matrix34<float> const*) {}
void setEffectNamedMtxPtr(al::IUseEffectKeeper*, char const*, sead::Matrix34<float> const*) {}
bool trySetEffectNamedMtxPtr(al::IUseEffectKeeper*, char const*, sead::Matrix34<float> const*) {return false;}
void tryKillEmitterAndParticleAll(al::IUseEffectKeeper*) {}
void setEffectAllScale(al::IUseEffectKeeper*, char const*, sead::Vector3<float> const&) {}
bool tryDeleteEffect(al::IUseEffectKeeper*,char const*) {return false;}

}
