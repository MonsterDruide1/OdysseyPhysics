#include "Library/Area/AreaObjGroup.h"
#include "Library/Area/AreaObjUtil.h"
#include "Library/Area/AreaShapeCube.h"
#include "Library/Area/AreaShapeCylinder.h"
#include "Library/LiveActor/ActorAreaFunction.h"

namespace al {

bool isInAreaObj(al::IUseAreaObj const*, char const*) {return false;}
bool isInAreaObjPlayerOneIgnoreAreaTarget(al::PlayerHolder const*, char const*) {return false;}
bool isInAreaObjPlayerAnyOne(al::LiveActor const*, al::AreaObj const*) {return false;}

bool al::AreaShapeCube::calcLocalBoundingBox(sead::BoundBox3<float>*) const {return false;}
bool al::AreaShapeCube::calcNearestEdgePoint(sead::Vector3<float>*, sead::Vector3<float> const&) const {return false;}
bool al::AreaShapeCube::checkArrowCollision(sead::Vector3<float>*, sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&) const {return false;}
bool al::AreaShapeCube::isInVolumeOffset(sead::Vector3<float> const&, float) const {return false;}
bool al::AreaShapeCylinder::calcLocalBoundingBox(sead::BoundBox3<float>*) const {return false;}
bool al::AreaShapeCylinder::calcNearestEdgePoint(sead::Vector3<float>*, sead::Vector3<float> const&) const {return false;}
bool al::AreaShapeCylinder::checkArrowCollision(sead::Vector3<float>*, sead::Vector3<float>*, sead::Vector3<float> const&, sead::Vector3<float> const&) const {return false;}
bool al::AreaShapeCylinder::isInVolume(sead::Vector3<float> const&) const {return false;}
bool al::AreaShapeCylinder::isInVolumeOffset(sead::Vector3<float> const&, float) const {return false;}
    
}
