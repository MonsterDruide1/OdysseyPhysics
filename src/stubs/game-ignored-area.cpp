#include "Library/Area/AreaObjDirector.h"
#include "Library/stuff.h"
#include "PlayerUtil.h"
#include "playerUtil.h"

PlayerAreaChecker::PlayerAreaChecker(al::LiveActor const*, PlayerModelHolder const*) {}

al::AreaObj* al::tryFindAreaObj(al::IUseAreaObj const*, char const*, sead::Vector3<float> const&) { return nullptr; }
al::AreaObjGroup* al::tryFindAreaObjGroup(al::IUseAreaObj const*, char const*) { return nullptr; }
bool al::isInAreaObj(al::IUseAreaObj const*, char const*) { return false; }
