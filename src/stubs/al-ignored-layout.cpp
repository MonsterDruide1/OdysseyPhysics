#include "Library/Layout/LayoutActionFunction.h"
#include "Library/Layout/LayoutActionKeeper.h"
#include "Library/Layout/LayoutActorUtil.h"
#include "Library/Layout/LayoutInitInfo.h"
#include "Library/Layout/LayoutPaneGroup.h"
#include "Library/Layout/LayoutSystem.h"
#include "Library/Message/IUseMessageSystem.h"

namespace al {

void setLocalTrans(al::IUseLayout*, sead::Vector2<float> const&) {}
void initLayoutActor(al::LayoutActor*, al::LayoutInitInfo const&, char const*, char const*) {}
void initLayoutPartsActor(al::LayoutActor*, al::LayoutActor*, al::LayoutInitInfo const&, char const*, char const*) {}
void updateLayoutPaneRecursive(al::LayoutActor*) {}
void setPaneStringFormat(al::IUseLayout*, char const*, char const*, ...) {}
bool isDead(al::LayoutActor const*) {return false;}
void setPaneString(al::IUseLayout*, char const*, char16_t const*, unsigned short) { CRASH }
void setPaneNumberDigit1(al::IUseLayout*, char const*, int, unsigned short) {}

void initMessageTagDataHolder(int) {}
void registerMessageTagDataScore(al::MessageTagDataHolder*, char const*, int const*) {}
void replaceMessageTagScore(sead::BufferedSafeStringBase<char16_t>*, al::IUseMessageSystem const*, char16_t const*, int, char const*) {}
void getSystemMessageString(al::IUseMessageSystem const*, char const*, char const*) {}

LayoutKit::LayoutKit(al::FontHolder*) {}
LayoutKit::~LayoutKit() {}
void LayoutKit::endInit() {}
void LayoutKit::setDrawContext(agl::DrawContext*) {}
void LayoutKit::setLayoutSystem(al::LayoutSystem*) {}

bool LayoutPaneGroup::isAnimEnd() const {return false;}
bool LayoutPaneGroup::isAnimOneTime() const {return true;}
void LayoutPaneGroup::setAnimFrame(float) {}
void LayoutPaneGroup::setAnimFrameRate(float) {}
f32 LayoutPaneGroup::getAnimFrame() const {return 0.0f;}
f32 LayoutPaneGroup::getAnimFrameMax(char const*) const {return 1.0f;}
f32 LayoutPaneGroup::getAnimFrameRate() const {return 1.0f;}
const char* LayoutPaneGroup::getPlayingAnimName() const {return "";}
bool LayoutPaneGroup::isAnimExist(char const*) const {return false;}
bool LayoutPaneGroup::isAnimOneTime(char const*) const {return true;}
bool LayoutPaneGroup::isAnimPlaying() const {return false;}

LayoutPaneGroup* LayoutActionKeeper::getLayoutPaneGroup(char const*) const {WARN_UNIMPL;return nullptr;}
void LayoutActionKeeper::startAction(char const*, char const*) {}

}
