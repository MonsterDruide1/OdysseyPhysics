#include "Library/Model/ModelKeeper.h"

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
