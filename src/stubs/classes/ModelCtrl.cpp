
#include "Library/Model/ModelCtrl.h"
#include "nn/g3d/ModelObj.h"

namespace al {

ModelCtrl::ModelCtrl() {
    // wrong:
    mModelObj = new nn::g3d::ModelObj();
}
ModelCtrl::~ModelCtrl() {CRASH}
void ModelCtrl::initResource(Resource* modelRes, Resource* animRes) {
    mModelRes = modelRes;
    mAnimRes = animRes;
}
void ModelCtrl::show() {CRASH}
void ModelCtrl::hide() {CRASH}
void ModelCtrl::recreateDisplayList() {}
void ModelCtrl::setCameraInfo(const sead::Matrix34f*, const sead::Matrix34f*, const sead::Matrix44f*, const sead::Matrix44f*) {CRASH}

}
