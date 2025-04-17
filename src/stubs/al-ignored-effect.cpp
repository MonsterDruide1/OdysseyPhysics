#include "Library/Effect/EffectKeeper.h"
#include "Library/Effect/EffectSystem.h"
#include "Library/Effect/EffectSystemInfo.h"
#include "Library/Effect/PartsEffectGroup.h"

namespace al {

al::PartsEffectGroup::PartsEffectGroup() {}
void al::PartsEffectGroup::init(int, al::EffectSystemInfo const*, char const*, sead::Vector3<float> const*, sead::Vector3<float> const*, sead::Matrix34<float> const*, al::IUseCamera const*) {}

void EffectKeeper::deleteAndClearEffectAll() {}
void EffectKeeper::offCalcAndDraw() {}
void EffectKeeper::onCalcAndDraw() {}

void EffectSystem::endInit() {}
void EffectSystem::endScene() {}
void EffectSystem::initScene() {}
EffectSystem* EffectSystem::initializeSystem(agl::DrawContext*, sead::Heap*) {WARN_UNIMPL; return nullptr;}
void EffectSystem::setCameraDirector(al::CameraDirector*) {}
void EffectSystem::setGraphicsSystemInfo(al::GraphicsSystemInfo const*) {}
void EffectSystem::startScene(al::ExecuteDirector*) {}

void deleteEffect(al::IUseEffectKeeper*, char const*) {}
void emitEffect(al::IUseEffectKeeper*, char const*, sead::Vector3<float> const*) {}
void setEffectFollowMtxPtr(al::IUseEffectKeeper*,const char*,sead::Matrix34<float> const*) {}
void setEffectNamedMtxPtr(al::IUseEffectKeeper*, char const*, sead::Matrix34<float> const*) {}
bool trySetEffectNamedMtxPtr(al::IUseEffectKeeper*, char const*, sead::Matrix34<float> const*) {return false;}
void tryKillEmitterAndParticleAll(al::IUseEffectKeeper*) {}
void setEffectAllScale(al::IUseEffectKeeper*, char const*, sead::Vector3<float> const&) {}
bool tryDeleteEffect(al::IUseEffectKeeper*,char const*) {return false;}
bool tryUpdateEffectMaterialCode(al::IUseEffectKeeper*, char const*) {return false;}

}

void alEffectKeeperInitFunction::setupCameraToEffectKeeper(al::EffectKeeper*, al::IUseCamera const*) {}
void alEffectKeeperInitFunction::setupModelToEffectKeeper(al::EffectKeeper*, al::ModelKeeper const*) {}
