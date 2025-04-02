#include "Library/Item/ItemUtil.h"

namespace al {

void setAppearItemAttackerSensor(al::LiveActor const*, al::HitSensor const*) {}

bool appearItem(al::LiveActor const*, sead::Vector3<float> const&, sead::Quat<float> const&,
                al::HitSensor const*) {
    return false;
}

bool appearItem(al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&,
                al::HitSensor const*) {
    return false;
}

void setAppearItemFactor(al::LiveActor const*, char const*, al::HitSensor const*) {}

al::ActorItemInfo* addItem(al::LiveActor*, al::ActorInitInfo const&, char const*, bool) {
    WARN_UNIMPL;
    return nullptr;
}

al::ActorItemInfo* addItem(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*,
                           char const*, int, bool) {
    WARN_UNIMPL;
    return nullptr;
}

}  // namespace al
