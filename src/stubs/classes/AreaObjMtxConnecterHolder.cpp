#include "Library/Area/AreaObjMtxConnecter.h"

al::AreaObjMtxConnecterHolder::AreaObjMtxConnecterHolder(int) {}
bool al::AreaObjMtxConnecterHolder::tryAddArea(al::AreaObj*, al::PlacementInfo const&) {return false;}
void al::AreaObjMtxConnecterHolder::update() {}
void al::AreaObjMtxConnecterHolder::registerSyncParentMtx(sead::Matrix34<float> const*, al::PlacementInfo const&, al::ValidatorBase const*) {}
void al::AreaObjMtxConnecterHolder::registerParentMtx(sead::Matrix34<float> const*, al::PlacementInfo const&, al::ValidatorBase const*) {}
