#include "Layout/BalloonIcon.h"
#include "Layout/CommonHorizontalList.h"
#include "Layout/CommonVerticalList.h"
#include "Layout/ControllerGuideSnapShotCtrl.h"
#include "Layout/HackListLayout.h"
#include "Layout/MapLayout.h"
#include "Layout/ShineListLayout.h"
#include "Layout/SouvenirListLayout.h"
#include "Layout/StageSceneLayout.h"
#include "Scene/StageScene.h"
#include "Util/StageInputFunction.h"

void BalloonIcon::hideAndStopUpdate() {}
void BalloonIcon::startUpdateDraw() {}

BalloonIcon* rs::createShopBalloon(al::LayoutInitInfo const&, sead::Matrix34<float> const*, sead::Vector3<float> const&) {WARN_UNIMPL; return nullptr;}

void rs::recordGamePadPlayStyleInfo(GamePadPlayStyleInfo*, al::LayoutActor const*) {}

StageSceneLayout::StageSceneLayout(char const*, al::LayoutInitInfo const&, al::PlayerHolder const*, al::SubCameraRenderer const*) : al::NerveStateBase("") {}
ControllerGuideSnapShotCtrl::ControllerGuideSnapShotCtrl(char const*, al::LayoutInitInfo const&, al::PostProcessingFilter*) : al::NerveStateBase("") {}
MapLayout::MapLayout(al::LayoutInitInfo const&,al::PlayerHolder const*,int) : al::LayoutActor("") {}
ShineListLayout::ShineListLayout(al::LayoutInitInfo const&) : al::LayoutActor("") {}
HackListLayout::HackListLayout(al::LayoutInitInfo const&) : al::LayoutActor("") {}
SouvenirListLayout::SouvenirListLayout(al::LayoutInitInfo const&) : al::LayoutActor("") {}

CommonVerticalList::CommonVerticalList(al::LayoutActor*, al::LayoutInitInfo const&, bool) : al::NerveExecutor("") {}
void CommonVerticalList::addStringData(sead::WFixedSafeString<512> const*,char const*) {}
void CommonVerticalList::addGroupAnimData(sead::FixedSafeString<64> const*,char const*) {}

CommonHorizontalList::CommonHorizontalList(al::LayoutActor*, al::LayoutInitInfo const&, bool) : al::NerveExecutor("") {}
void CommonHorizontalList::addStringData(sead::WFixedSafeString<512> const*,char const*) {}
void CommonHorizontalList::setGroupAnimData(sead::FixedSafeString<64> const*,char const*) {}
