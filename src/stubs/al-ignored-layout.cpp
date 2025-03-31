#include "Library/Layout/LayoutActionFunction.h"
#include "Library/Layout/LayoutActorUtil.h"
#include "Library/Layout/LayoutInitInfo.h"

namespace al {

void setLocalTrans(al::IUseLayout*, sead::Vector2<float> const&) {}
bool isActionEnd(al::IUseLayoutAction const*, char const*) {return false;}
void initLayoutActor(al::LayoutActor*, al::LayoutInitInfo const&, char const*, char const*) {}
void initLayoutPartsActor(al::LayoutActor*, al::LayoutActor*, al::LayoutInitInfo const&, char const*, char const*) {}
void updateLayoutPaneRecursive(al::LayoutActor*) {}
void startAction(al::IUseLayoutAction*, char const*, char const*) {}
void setPaneStringFormat(al::IUseLayout*, char const*, char const*, ...) {}
    
}
