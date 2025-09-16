

#include "Item/CoinCollectHolder.h"
#include "Item/CoinCollectWatcher.h"
#include "Library/Base/StringUtil.h"
#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorSensorFunction.h"
#include "Library/LiveActor/ActorSensorUtil.h"
#include "Library/LiveActor/ActorInitFunction.h"
#include "Library/LiveActor/LiveActor.h"
#include "Library/Scene/SceneObjHolder.h"
#include "Player/PlayerActorBase.h"
#include "Player/PlayerColliderHakoniwa.h"
#include "Player/PlayerInputFunction.h"
#include "PlayerUtil.h"
#include "Project/Memory/Util.h"
#include "Util/PlayerCollisionUtil.h"
#include "Util/SensorMsgFunction.h"
#include "basis/seadTypes.h"

namespace al {

sead::Heap* getCurrentHeap() {CRASH}

al::ISceneObj* getSceneObj(al::IUseSceneObjHolder const* holder, int index) {
    return holder->getSceneObjHolder()->getObj(index);
    if (index == 15) {
        return nullptr;
    }  // al::FootPrintHolder => graphics
    if (index == 18) {
        dbg_printf("Returning nullptr for GameDataHolderAccessor from getSceneObj!\n");
        return nullptr;
    }  // GameDataHolderAccessor => ?
    if (index == 7) {
        return new CoinCollectHolder();
    }
    if (index == 8) {
        return new CoinCollectWatcher();
    }
    CRASH
}

}  // namespace al

// might be fine to ignore, better replace with proper implementation though
void al::tryReplaceString(sead::BufferedSafeStringBase<char>* result, char const* in,
                          char const* search, char const* replace) {
    result->setReplaceString(in, search, replace);
}

const char* rs::getInitPlayerModelName(PlayerInitInfo const&) {
    WARN_UNIMPL;
    return "Mario";
}

const char* rs::getInitCapTypeName(PlayerInitInfo const&) {
    WARN_UNIMPL;
    return "Mario";
}

f32 al::getSensorRadius(al::HitSensor const*) {
    WARN_UNIMPL;
    return 0.0f;
}

void al::calcVecBetweenSensors(sead::Vector3f* out, const HitSensor* a, const HitSensor* b) {
    WARN_UNIMPL;
}
