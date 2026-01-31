#include "gfx/seadCamera.h"
#include "gfx/seadProjection.h"
#include "gfx/seadViewport.h"

sead::Graphics::DevicePosture sead::Graphics::sDefaultDevicePosture;
f32 sead::Graphics::sDefaultDeviceZOffset;
f32 sead::Graphics::sDefaultDeviceZScale;

void sead::Projection::doUpdateDeviceMatrix(sead::Matrix44<float>*, sead::Matrix44<float> const&, sead::Graphics::DevicePosture) const {CRASH}

sead::PerspectiveProjection::PerspectiveProjection() {CRASH}
sead::PerspectiveProjection::~PerspectiveProjection() {CRASH}
void sead::PerspectiveProjection::getOffset(Vector2f* offset) const {CRASH}
void sead::PerspectiveProjection::doScreenPosToCameraPosTo(Vector3f* cameraPos, const Vector3f& screenPos) const {CRASH}
u32 sead::PerspectiveProjection::getProjectionType() const {CRASH}
f32 sead::PerspectiveProjection::getNear() const {CRASH}
f32 sead::PerspectiveProjection::getFar() const {CRASH}
f32 sead::PerspectiveProjection::getAspect() const {CRASH}
f32 sead::PerspectiveProjection::getFovy() const {CRASH}
f32 sead::PerspectiveProjection::getTop() const {CRASH}
f32 sead::PerspectiveProjection::getBottom() const {CRASH}
f32 sead::PerspectiveProjection::getLeft() const {CRASH}
f32 sead::PerspectiveProjection::getRight() const {CRASH}
void sead::PerspectiveProjection::doUpdateMatrix(Matrix44f* mtx) const {CRASH}
void sead::PerspectiveProjection::set(float, float, float, float) {CRASH}

void sead::Camera::cameraPosToWorldPosByMatrix(sead::Vector3<float>*, sead::Vector3<float> const&) const {CRASH}
void sead::Camera::unprojectRayByMatrix(sead::Ray<sead::Vector3<float> >*, sead::Vector3<float> const&) const {CRASH}

void sead::Viewport::project(sead::Vector2<float>*, sead::Vector3<float> const&) const {CRASH}
