#include "Library/Scene/Scene.h"

al::Scene::Scene(const char* name) : al::NerveExecutor(name) {}
al::Scene::~Scene() {}
void al::Scene::init(al::SceneInitInfo const&) {}
void al::Scene::appear() {}
void al::Scene::kill() {}
void al::Scene::movement() {}
void al::Scene::control() {}
void al::Scene::drawMain() {}
void al::Scene::drawSub() {}
al::AudioKeeper* al::Scene::getAudioKeeper() const {WARN_UNIMPL; return nullptr;}
al::SceneObjHolder* al::Scene::getSceneObjHolder() const {WARN_UNIMPL; return nullptr;}
al::CameraDirector* al::Scene::getCameraDirector() const {WARN_UNIMPL; return nullptr;}
