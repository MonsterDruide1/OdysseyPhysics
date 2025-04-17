#include "Library/Execute/ExecuteRequestKeeper.h"
#include "Library/Execute/ExecuteSystemInitInfo.h"
#include "Library/Execute/ExecuteTableHolderDraw.h"
#include "Library/Execute/ExecuteTableHolderUpdate.h"
#include "Project/Execute/ExecuteAsyncExecutor.h"

al::ExecuteRequestKeeper::ExecuteRequestKeeper(int) {}
void al::ExecuteRequestKeeper::executeRequestActorDrawAllOff() {}
void al::ExecuteRequestKeeper::executeRequestActorDrawAllOn() {}
void al::ExecuteRequestKeeper::executeRequestActorMovementAllOff() {}
void al::ExecuteRequestKeeper::executeRequestActorMovementAllOn() {}
void al::ExecuteRequestKeeper::request(al::LiveActor*, al::ExecuteRequestKeeper::Request) {}
al::ExecuteTableHolderDraw::ExecuteTableHolderDraw() {}
void al::ExecuteTableHolderDraw::createExecutorListTable() {}
void al::ExecuteTableHolderDraw::execute() const {}
void al::ExecuteTableHolderDraw::executeList(char const*) const {}
void al::ExecuteTableHolderDraw::init(char const*, al::ExecuteSystemInitInfo const&, al::ExecuteOrder const*, int) {}
bool al::ExecuteTableHolderDraw::isActive() const {return false;}
void al::ExecuteTableHolderDraw::tryRegisterActor(al::LiveActor*, char const*) {}
void al::ExecuteTableHolderDraw::tryRegisterActorModel(al::LiveActor*, char const*) {}
void al::ExecuteTableHolderDraw::tryRegisterFunctor(al::FunctorBase const&, char const*) {}
void al::ExecuteTableHolderDraw::tryRegisterLayout(al::LayoutActor*, char const*) {}
void al::ExecuteTableHolderDraw::tryRegisterUser(al::IUseExecutor*, char const*) {}
al::ExecuteTableHolderDraw::~ExecuteTableHolderDraw() {}
al::ExecuteTableHolderUpdate::ExecuteTableHolderUpdate() {}
void al::ExecuteTableHolderUpdate::createExecutorListTable() {}
void al::ExecuteTableHolderUpdate::execute() const {}
void al::ExecuteTableHolderUpdate::executeList(char const*) const {}
void al::ExecuteTableHolderUpdate::init(char const*, al::ExecuteSystemInitInfo const&, al::ExecuteOrder const*, int) {}
void al::ExecuteTableHolderUpdate::tryRegisterActor(al::LiveActor*, char const*) {}
void al::ExecuteTableHolderUpdate::tryRegisterFunctor(al::FunctorBase const&, char const*) {}
void al::ExecuteTableHolderUpdate::tryRegisterLayout(al::LayoutActor*, char const*) {}
void al::ExecuteTableHolderUpdate::tryRegisterUser(al::IUseExecutor*, char const*) {}
al::ExecuteTableHolderUpdate::~ExecuteTableHolderUpdate() {}

al::ExecuteAsyncExecutor::ExecuteAsyncExecutor(al::ExecuteDirector const*, char const*, sead::CoreId) {}
al::ExecuteAsyncExecutor::~ExecuteAsyncExecutor() {}
void al::ExecuteAsyncExecutor::executeAsync() {}

al::ExecuteAsyncExecutorUpdate::~ExecuteAsyncExecutorUpdate() {}
void al::ExecuteAsyncExecutorUpdate::execute() {}

al::ExecuteSystemInitInfo::ExecuteSystemInitInfo() {}
