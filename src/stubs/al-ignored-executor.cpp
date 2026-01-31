#include "Library/Execute/ExecutorActorExecuteBase.h"
#include "Library/Execute/ExecuteRequestKeeper.h"
#include "Library/Execute/ExecuteTableHolderUpdate.h"
#include "Library/Execute/ExecutorActorCalcAnim.h"
#include "Library/Execute/ExecutorActorCalcView.h"
#include "Library/Execute/ExecutorActorDraw.h"
#include "Library/Execute/ExecutorActorMovement.h"
#include "Library/Execute/ExecutorActorMovementCalcAnim.h"
#include "Library/Execute/ExecutorListActorDraw.h"
#include "Library/Execute/ExecutorListActorModelDraw.h"
#include "Library/Execute/ExecutorListFunctor.h"
#include "Library/Execute/ExecutorListLayoutDraw.h"
#include "Library/Execute/ExecutorListUser.h"
#include "Project/Execute/ExecuteAsyncExecutor.h"
#include "Project/Execute/ExecuteSystemInitInfo.h"

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
void al::ExecuteAsyncExecutor::waitAsync() {}

al::ExecuteAsyncExecutorUpdate::~ExecuteAsyncExecutorUpdate() {}
void al::ExecuteAsyncExecutorUpdate::execute() {}

al::ExecutorActorExecuteBase::ExecutorActorExecuteBase(const char* name) {}
void al::ExecutorActorExecuteBase::addActor(al::LiveActor*) {}
void al::ExecutorActorExecuteBase::removeActor(al::LiveActor*) {}
void al::ExecutorActorExecuteBase::registerActor(al::LiveActor*) {}
void al::ExecutorActorExecuteBase::createExecutorTable() {}


al::ExecutorListLayoutDrawNormal::ExecutorListLayoutDrawNormal(const char* name, int size, const al::ExecuteSystemInitInfo& info) : al::ExecutorListLayoutDrawBase(name, size, info) {}
void al::ExecutorListLayoutDrawNormal::startDraw() const {}

al::ExecutorActorDraw::ExecutorActorDraw(char const* name) : ExecutorActorExecuteBase(name) {}
void al::ExecutorActorDraw::execute() const {}

al::ExecutorActorMovement::ExecutorActorMovement(char const* name) : ExecutorActorExecuteBase(name) {}
void al::ExecutorActorMovement::execute() const {}

al::ExecutorActorCalcAnim::ExecutorActorCalcAnim(char const* name) : ExecutorActorExecuteBase(name) {}
void al::ExecutorActorCalcAnim::execute() const {}

al::ExecutorActorMovementCalcAnim::ExecutorActorMovementCalcAnim(char const* name) : ExecutorActorExecuteBase(name) {}
void al::ExecutorActorMovementCalcAnim::execute() const {}

al::ExecutorActorCalcView::ExecutorActorCalcView(char const* name) : ExecutorActorExecuteBase(name) {}
void al::ExecutorActorCalcView::execute() const {}
