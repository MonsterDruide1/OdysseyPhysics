

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
#include "System/GameDataHolderAccessor.h"
#include "Util/PlayerCollisionUtil.h"
#include "Util/SensorMsgFunction.h"
#include "basis/seadTypes.h"

namespace al {

sead::Heap* getCurrentHeap() {CRASH}

al::ISceneObj* getSceneObj(al::IUseSceneObjHolder const* holder, int index) {
    return holder->getSceneObjHolder()->getObj(index);
}

}  // namespace al

// might be fine to ignore, better replace with proper implementation though
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
