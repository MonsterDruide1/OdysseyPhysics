#include "Library/LiveActor/ActorSensorFunction.h"
#include "Library/LiveActor/ActorSensorUtil.h"
#include "Library/LiveActor/HitReactionKeeper.h"
#include "Project/HitSensor/HitSensor.h"

namespace al {

al::HitSensor::HitSensor(al::LiveActor*, char const*, unsigned int, float, unsigned short, sead::Vector3<float> const*, sead::Matrix34<float> const*, sead::Vector3<float> const&) {CRASH}
void al::HitSensor::invalidateBySystem() {}
bool al::HitSensor::trySensorSort() {return true;}
void al::HitSensor::update() {}
void al::HitSensor::validateBySystem() {}

al::HitSensor* addHitSensor(al::LiveActor*, al::ActorInitInfo const&, char const*, unsigned int, float, unsigned short, sead::Vector3<float> const&) {
    WARN_UNIMPL;
    return nullptr;
}

void al::HitReactionKeeper::start(char const*, sead::Vector3f const*, al::HitSensor const*, al::HitSensor const*) {}
al::HitReactionKeeper* al::HitReactionKeeper::tryCreate(char const*, sead::Vector3<float> const*, al::IUseEffectKeeper*, al::IUseAudioKeeper const*, al::IUseCamera const*, al::PadRumbleDirector*, al::SceneStopCtrl*, al::RadialBlurDirector*, al::PlayerHolder const*, al::Resource const*, char const*) {WARN_UNIMPL;return nullptr;}

void updateHitSensorsAll(al::LiveActor*) {}
void invalidateHitSensors(LiveActor*) {}
void validateHitSensor(al::LiveActor*, char const*) {}
void validateHitSensors(al::LiveActor*) {}
void invalidateHitSensor(al::LiveActor*, char const*) {}
bool calcDirBetweenSensors(sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*) {return false;}
bool calcDirBetweenSensorsH(sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*) {return false;}
f32 calcDistanceV(sead::Vector3f const&,al::HitSensor const*,al::HitSensor const*) {return 0.0f;}
const sead::Vector3f& getActorTrans(al::HitSensor const*) {return const_cast<sead::Vector3f&>(sead::Vector3f::zero);}
bool isSensorMapObj(al::HitSensor const*) {return false;}
bool isSensorPlayerAll(al::HitSensor const*) {return false;}
bool isSensorPlayerAttack(al::HitSensor const*) {return false;}
bool isSensorEnemyAttack(al::HitSensor const*) {return false;}
bool isSensorEnemyBody(al::HitSensor const*) {return false;}
bool isSensorPlayer(al::HitSensor const*) {return false;}
bool isSensorName(al::HitSensor const*, char const*) {return false;}
bool isSensorEye(al::HitSensor const*) {return false;}
bool isSensorLookAt(al::HitSensor const*) {return false;}
bool isSensorPlayerEye(al::HitSensor const*) {return false;}
bool isSensorRide(al::HitSensor const*) {return false;}
bool isSensorSimple(al::HitSensor const*) {return false;}
bool isSensorCollision(al::HitSensor const*) {return false;}
bool isMySensor(HitSensor const*, LiveActor const*) { return false; }
void setHitSensorPosPtr(al::LiveActor*, char const*, sead::Vector3<float> const*) {}
void setHitSensorJointMtx(al::LiveActor*, char const*, char const*) {}
void setSensorRadius(al::LiveActor*, char const*, float) {}
f32 getSensorRadius(al::LiveActor const*, char const*) {return 1.0f;}
al::LiveActor* getSensorHost(al::HitSensor const*) {WARN_UNIMPL;return nullptr;}
bool tryReceiveMsgPushAndAddVelocity(al::LiveActor*, al::SensorMsg const*, al::HitSensor const*, al::HitSensor const*, float) {return false;}
bool tryReceiveMsgPushAndAddVelocityH(al::LiveActor*, al::SensorMsg const*, al::HitSensor const*, al::HitSensor const*, float) {return false;}
bool tryReceiveMsgCollidePush(sead::Vector3<float>*, al::SensorMsg const*) {return false;}
bool pushAndAddVelocity(al::LiveActor*, al::HitSensor const*, al::HitSensor const*, float) {return false;}
const sead::Vector3f& getActorVelocity(al::HitSensor const*) {return sead::Vector3f::zero;}
const sead::Vector3f& getActorGravity(al::HitSensor const*) {return sead::Vector3f::zero;}
const sead::Vector3f& getSensorPos(al::LiveActor const*, char const*) {return sead::Vector3f::zero;}
void registSupportFreezeSyncGroup(al::LiveActor*, al::ActorInitInfo const&) {}

f32 getChangeAlphaValue(al::SensorMsg const*) { return 0.0f; }

}  // namespace al

namespace alSensorFunction {

al::HitSensorType findSensorTypeByName(char const*) {return al::HitSensorType::CollisionParts;}
void clearHitSensors(al::LiveActor*) {}
void updateHitSensorsAll(al::LiveActor*) {}

}

namespace alActorSensorFunction {

bool sendMsgSensorToSensor(al::SensorMsg const&, al::HitSensor*, al::HitSensor*) { return false; }
bool sendMsgToActorUnusedSensor(al::SensorMsg const&, al::LiveActor*) { return false; }

}
