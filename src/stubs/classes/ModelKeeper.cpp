#include "Library/Model/ModelKeeper.h"
#include "Library/Model/ModelCtrl.h"
#include "Library/Resource/ActorResource.h"
#include "Library/Resource/ResourceFunction.h"

al::ModelKeeper::ModelKeeper() {}
al::ModelKeeper::~ModelKeeper() {}
void al::ModelKeeper::hide() {}
void al::ModelKeeper::show() {}
void al::ModelKeeper::setDisplayRootJointMtxPtr(sead::Matrix34<float> const*) {}
void al::ModelKeeper::setModelLodCtrl(al::ModelLodCtrl*) {}
void al::ModelKeeper::createMatAnimForProgram(int) {}
void al::ModelKeeper::setDitherAnimator(al::DitherAnimator*) {}
void al::ModelKeeper::calc(sead::Matrix34<float> const&, sead::Vector3<float> const&) {}
sead::Matrix34f* al::ModelKeeper::getBaseMtx(){CRASH}
void al::ModelKeeper::update() {}
void al::ModelKeeper::updateLast() {}
void al::ModelKeeper::initModel(int, al::GpuMemAllocator*, al::ModelShaderHolder*, al::ModelOcclusionCullingDirector*, al::ShadowDirector*, al::PrepassTriangleCulling*) {}
void al::ModelKeeper::initResource(al::ActorResource const* a) {
    mActorRes = a;
    mName = al::getResourceName(a->getModelRes());
    mModelCtrl = new ModelCtrl();
    mModelCtrl->initResource(a->getModelRes(), a->getAnimRes());
}
al::Resource* al::ModelKeeper::getAnimResource() const {
    return mActorRes->getAnimRes() ?: mActorRes->getModelRes();
}
al::Resource* al::ModelKeeper::getModelResource() const {
    return mActorRes->getModelRes();
}
