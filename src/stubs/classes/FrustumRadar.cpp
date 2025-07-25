#include "Library/Clipping/FrustumRadar.h"

namespace al {

FrustumRadar::FrustumRadar() {}
void FrustumRadar::calcFrustumArea(const sead::Matrix34f&, f32, f32, f32, f32) {}
void FrustumRadar::setLocalAxis(const sead::Matrix34f&) {}
void FrustumRadar::setFactor(f32, f32) {}
void FrustumRadar::calcFrustumArea(const sead::Matrix34f&, const sead::Matrix44f&, f32, f32) {}
void FrustumRadar::setFactor(sead::Matrix44f) {}
void FrustumRadar::calcFrustumAreaStereo(const sead::Matrix34f&, const sead::Matrix34f&, const sead::Matrix44f&, f32, f32) {}
void FrustumRadar::setLocalAxisStereo(const sead::Matrix34f&, const sead::Matrix34f&) {}
void FrustumRadar::setFactorStereo(const sead::Matrix44f&) {}
bool FrustumRadar::judgeInLeft(const sead::Vector3f&, f32) const {return true;}
bool FrustumRadar::judgeInRight(const sead::Vector3f&, f32) const {return true;}
bool FrustumRadar::judgeInTop(const sead::Vector3f&, f32) const {return true;}
bool FrustumRadar::judgeInBottom(const sead::Vector3f&, f32) const {return true;}
bool FrustumRadar::judgeInArea(const sead::Vector3f&, f32, f32, f32) const {return true;}
bool FrustumRadar::judgeInArea(const sead::Vector3f&, f32, f32) const {return true;}
bool FrustumRadar::judgeInAreaNoFar(const sead::Vector3f&, f32) const {return true;}
bool FrustumRadar::judgePointFlag(const sead::Vector3f&, f32, f32) const {return true;}
bool FrustumRadar::judgeInAreaObb(const sead::Matrix34f*, const sead::BoundBox3f&, f32, f32) const {return true;}
bool FrustumRadar::judgeInAreaObb(const sead::Matrix34f*, const sead::BoundBox3f&, f32) const {return true;}
bool FrustumRadar::judgeInAreaObbNoFar(const sead::Matrix34f*, const sead::BoundBox3f&) const {return true;}

}  // namespace al
