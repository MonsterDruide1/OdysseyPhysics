

#include "Item/CoinCollectHolder.h"
#include "Item/CoinCollectWatcher.h"
#include "Library/Anim/AnimPlayerSkl.h"
#include "Library/Area/AreaObjDirector.h"
#include "Library/Base/StringUtil.h"
#include "Library/Controller/JoyPadAccelPoseAnalyzer.h"
#include "Library/Execute/ExecuteTableHolderUpdate.h"
#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorClippingFunction.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/ActorResourceFunction.h"
#include "Library/LiveActor/ActorSensorFunction.h"
#include "Library/LiveActor/ActorSensorUtil.h"
#include "Library/LiveActor/ActorInitUtil.h"
#include "Library/LiveActor/ActorInitFunction.h"
#include "Library/LiveActor/LiveActor.h"
#include "Library/LiveActor/LiveActorFunction.h"
#include "Library/Math/MathUtil.h"
#include "Library/Math/MathUtil.h"
#include "Library/Math/MathUtil.h"
#include "Library/Matrix/MatrixUtil.h"
#include "Library/Model/ModelCtrl.h"
#include "Library/Nerve/NerveStateBase.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Placement/PlacementInfo.h"
#include "Library/Player/PlayerHolder.h"
#include "Library/Scene/SceneObjHolder.h"
#include "Library/Scene/SceneUtil.h"
#include "Library/Thread/FunctorV0M.h"
#include "Library/Yaml/ByamlUtil.h"
#include "Library/stuff.h"
#include "Player/CollisionShapeInfo.h"
#include "Player/HackCap.h"
#include "Player/Player.h"
#include "Player/PlayerActionFunction.h"
#include "Player/PlayerActorBase.h"
#include "Player/PlayerCeilingCheck.h"
#include "Player/PlayerColliderHakoniwa.h"
#include "Player/PlayerCostumeInfo.h"
#include "Player/PlayerFunction.h"
#include "Player/PlayerInput.h"
#include "Player/PlayerInputFunction.h"
#include "Player/PlayerStateRunHakoniwa2D3D.h"
#include "Player/PlayerTrigger.h"
#include "PlayerUtil.h"
#include "Project/Action/ActionAnimCtrl.h"
#include "Project/Anim/AnimPlayerSimple.h"
#include "Project/Memory/Util.h"
#include "Stuff.h"
#include "System/GameDataFunction.h"
#include "Util/ActorDimensionKeeper.h"
#include "Util/PlayerCollisionUtil.h"
#include "Util/SensorMsgFunction.h"
#include "basis/seadTypes.h"
#include "game/RaylibActor.h"
#include "playerUtil.h"

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

al::MtxConnector* al::createCollisionPartsConnector(al::LiveActor const*,
                                                    sead::Quat<float> const&) {
    WARN_UNIMPL;
    return nullptr;
}

void al::disconnectMtxConnector(al::MtxConnector*) {
    WARN_UNIMPL;
}

f32 al::getSensorRadius(al::HitSensor const*) {
    WARN_UNIMPL;
    return 0.0f;
}

void al::calcVecBetweenSensors(sead::Vector3f* out, const HitSensor* a, const HitSensor* b) {
    WARN_UNIMPL;
}
