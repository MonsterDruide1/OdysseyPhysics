#include "Library/Execute/ExecutorActorExecuteBase.h"
#include "Library/Execute/ExecuteRequestKeeper.h"
#include "Project/Execute/ExecuteSystemInitInfo.h"
#include "Library/Execute/ExecuteTableHolderDraw.h"
#include "Library/Execute/ExecuteTableHolderUpdate.h"
#include "Project/Execute/ExecuteAsyncExecutor.h"

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

void al::ExecutorActorExecuteBase::addActor(al::LiveActor*) {}
void al::ExecutorActorExecuteBase::removeActor(al::LiveActor*) {}
