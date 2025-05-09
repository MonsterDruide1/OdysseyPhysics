#include "Library/Joint/JointControllerKeeper.h"
#include "Library/Joint/JointSpringControllerHolder.h"
#include "Library/Joint/JointSpringController.h"

al::JointSpringControllerHolder::JointSpringControllerHolder() {}
void al::JointSpringControllerHolder::init(al::LiveActor*,char const*) {}

void al::JointSpringController::setChildLocalPos(sead::Vector3<float> const&) {}
void al::JointSpringController::setFriction(float) {}
void al::JointSpringController::setLimitDegree(float) {}
void al::JointSpringController::setStability(float) {}

al::JointSpringController* al::initJointSpringController(al::LiveActor const*, char const*) {WARN_UNIMPL; return nullptr;}
void al::initJointControllerKeeper(al::LiveActor const*, int) {}
al::JointLocalAxisRotator* al::initJointLocalAxisRotator(al::LiveActor const*, sead::Vector3<float> const&, float const*, char const*, bool) {WARN_UNIMPL; return nullptr;}
void al::initJointLocalXRotator(al::LiveActor const*, float const*, char const*) {}
void al::initJointLocalYRotator(al::LiveActor const*, float const*, char const*) {}
void al::initJointLocalZRotator(al::LiveActor const*, float const*, char const*) {}
