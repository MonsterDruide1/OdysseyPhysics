#include "Library/Area/AreaObjGroup.h"
#include "Library/Area/AreaObjUtil.h"
#include "Library/Area/AreaShapeCube.h"
#include "Library/Area/AreaShapeCylinder.h"
#include "Library/LiveActor/ActorAreaFunction.h"
#include "Library/Play/Area/CameraStartParamArea.h"
#include "Library/Play/Area/SeBarrierArea.h"
#include "Library/Play/Area/SePlayArea.h"
#include "Library/Play/Area/ViewCtrlArea.h"

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

al::CameraStartParamArea::CameraStartParamArea(char const* n) : al::AreaObj(n) {}
void al::CameraStartParamArea::init(const AreaInitInfo& info) {}

al::SeBarrierArea::SeBarrierArea(char const* n) : al::AreaObj(n) {}
void al::SeBarrierArea::init(const AreaInitInfo& info) {}

al::SePlayArea::SePlayArea(char const* n) : al::AreaObj(n) {}
void al::SePlayArea::init(const AreaInitInfo& info) {}

al::ViewCtrlArea::ViewCtrlArea(char const* n) : al::AreaObj(n) {}
void al::ViewCtrlArea::init(const AreaInitInfo& info) {}

}
