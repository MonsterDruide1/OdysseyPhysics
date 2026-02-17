#include "Boss/Loop/LoopAnimState.h"

LoopAnimState::LoopAnimState(al::LiveActor* actor, const char* name, bool isLoop) : al::ActorStateBase(name, actor) {WARN_UNIMPL;}
void LoopAnimState::appear() {}
void LoopAnimState::end() {}
void LoopAnimState::exeStart() {}
void LoopAnimState::startAction(const char*) {}
void LoopAnimState::exeLoop() {}
void LoopAnimState::exeEnd() {}
