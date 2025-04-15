#include "Library/Item/ItemUtil.h"

namespace al {

bool appearItem(al::LiveActor const*) {return false;}

bool appearItem(al::LiveActor const*, sead::Vector3<float> const&, sead::Quat<float> const&,
                al::HitSensor const*) {
    return false;
}

bool appearItem(al::LiveActor const*, sead::Vector3<float> const&, sead::Vector3<float> const&,
                al::HitSensor const*) {
    return false;
}

bool appearItemTiming(al::LiveActor const*, char const*) {return false;}

void setAppearItemAttackerSensor(al::LiveActor const*, al::HitSensor const*) {}
void setAppearItemFactor(al::LiveActor const*, char const*, al::HitSensor const*) {}
void setAppearItemOffset(al::LiveActor const*,sead::Vector3f const&) {}

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
