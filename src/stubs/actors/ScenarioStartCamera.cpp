#include "Camera/ScenarioStartCamera.h"

ScenarioStartCamera::ScenarioStartCamera(const char* name) : al::LiveActor(name) {}
void ScenarioStartCamera::init(const al::ActorInitInfo& info) {}
void ScenarioStartCamera::initAfterPlacement() {}
void ScenarioStartCamera::appear() {}
void ScenarioStartCamera::kill() {}
const sead::Matrix34f* ScenarioStartCamera::getBaseMtx() const {WARN_UNIMPL; return nullptr;}
bool ScenarioStartCamera::isEnableStart() const {return false;}
bool ScenarioStartCamera::isFirstDemo() const {return false;}
bool ScenarioStartCamera::isEnableSkipDemo() const {return false;}
void ScenarioStartCamera::skipDemo() {}
void ScenarioStartCamera::end() {}
void ScenarioStartCamera::exePlay() {}
void* ScenarioStartCamera::getPoser(s32 index) const {return nullptr;}
void ScenarioStartCamera::exePlayAnim() {}
void ScenarioStartCamera::exeEnd() {}
s32 ScenarioStartCamera::getMaxPlayStep() {return 0;}
