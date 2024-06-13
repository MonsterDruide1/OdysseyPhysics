#include "Library/Area/AreaObjDirector.h"
#include "Library/stuff.h"
#include "PlayerUtil.h"
#include "playerUtil.h"
#include "Stuff.h"

PlayerAreaChecker::PlayerAreaChecker(al::LiveActor const*, PlayerModelHolder const*) {}

al::AreaObj* al::tryFindAreaObj(al::IUseAreaObj const*, char const*, sead::Vector3<float> const&) { return nullptr; }
al::AreaObjGroup* al::tryFindAreaObjGroup(al::IUseAreaObj const*, char const*) { return nullptr; }
bool al::isInAreaObj(al::IUseAreaObj const*, char const*) { return false; }

bool rs::tryFindSnapMoveAreaDir(sead::Vector3<float>*, al::LiveActor const*, IUsePlayerCollision const*) { return false; }
void rs::calcSnapVelocitySnapMoveAreaWithCutDir(sead::Vector3<float>* result, al::LiveActor const*, IUsePlayerCollision const*, sead::Vector3<float> const& vel, float, sead::Vector3<float> const&) { *result=vel; }
void rs::calcSnapVelocitySnapMoveArea(sead::Vector3<float>* result, al::LiveActor const*, IUsePlayerCollision const*, sead::Vector3<float> const& vel, float) { *result=vel; }

PlayerJudgeStartRise::PlayerJudgeStartRise(al::LiveActor const*,PlayerAreaChecker const*,IPlayerModelChanger const*) {}
void PlayerJudgeStartRise::reset() {}
void PlayerJudgeStartRise::update() {}
bool PlayerJudgeStartRise::judge() const {return false;}
