#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/CollisionUtil.h"
#include "Library/LiveActor/LiveActorUtil.h"
#include "Library/Shadow/ShadowMaskCtrl.h"
#include "Player/CollisionShapeInfo.h"
#include "Project/Light/ActorPrepassLightKeeper.h"
#include "math/seadQuat.h"
#include "Library/Math/MathUtil.h"
#include "Library/Shadow/DepthShadowMapCtrl.h"

#include "missing.h"

void al::CollisionParts::calcForceRotatePower(sead::Quatf*) const {CRASH}
void al::CollisionParts::calcForceMovePower(sead::Vector3<float> *,sead::Vector3<float> const&)	const {CRASH}
const al::LiveActor* al::CollisionParts::getConnectedHost() const {CRASH}

CollisionShapeInfoDisk::CollisionShapeInfoDisk(char const*, float, sead::Vector3<float> const&, sead::Vector3<float> const&, float) : CollisionShapeInfoBase(CollisionShapeId::Disk, nullptr) {CRASH}

void al::DepthShadowMapCtrl::show() {CRASH}
void al::DepthShadowMapCtrl::hide() {CRASH}
void al::DepthShadowMapCtrl::update() {CRASH}
void al::DepthShadowMapCtrl::initAfterPlacement(al::GraphicsSystemInfo*) {CRASH}

void al::ShadowMaskCtrl::show() {CRASH}
void al::ShadowMaskCtrl::hide() {CRASH}
void al::ShadowMaskCtrl::initAfterPlacement() {CRASH}

void al::ActorPrePassLightKeeper::initAfterPlacement() {CRASH}

void al::tryInitFixedModelGpuBuffer(const LiveActor *) {CRASH}
