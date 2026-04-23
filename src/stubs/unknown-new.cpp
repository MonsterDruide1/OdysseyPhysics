#include "Amiibo/HelpAmiiboDirector.h"
#include "Boss/Loop/LoopAnimState.h"
#include "Enemy/DisregardReceiver.h"
#include "Enemy/GotogotonMark.h"
#include "Item/ShineInfo.h"
#include "Layout/DecideIconLayout.h"
#include "Library/Event/EventFlowExecutor.h"
#include "Library/Joint/JointSpringControllerHolder.h"
#include "Library/Layout/LayoutActionFunction.h"
#include "Library/Layout/LayoutInitInfo.h"
#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorClippingFunction.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorSensorUtil.h"
#include "Library/Message/MessageHolder.h"
#include "Library/Message/MessageTagDataHolder.h"
#include "Library/Movement/AnimScaleController.h"
#include "Library/Nature/NatureUtil.h"
#include "Library/Shadow/ActorShadowUtil.h"
#include "MapObj/CapMessageShowInfo.h"
#include "MapObj/CheckpointFlagWatcher.h"
#include "MapObj/PlayerStartInfoHolder.h"
#include "MapObj/RouteGuideDirector.h"
#include "MapObj/TouchTargetInfo.h"
#include "Npc/BirdMtxGlideCtrl.h"
#include "Player/WhipTargetInfo.h"
#include "Project/Memory/Util.h"
#include "Scene/QuestInfoHolder.h"
#include "Scene/TemporaryScenarioCameraHolder.h"
#include "Sequence/ChangeStageInfo.h"
#include "System/GameDataHolderAccessor.h"
#include "System/MapDataHolder.h"
#include "System/ProjectNfpDirector.h"
#include "Util/AmiiboUtil.h"
#include "Util/CameraUtil.h"
#include "Util/CollisionUtil.h"
#include "Util/Hack.h"
#include "Util/InputInterruptTutorialUtil.h"
#include "Util/ObjUtil.h"
#include "Util/PlayerUtil.h"
#include "Util/ScenePlayerCapFunction.h"
#include "Util/ScenePrepoFunction.h"
#include "Util/SensorMsgFunction.h"
#include "Util/StageLayoutFunction.h"
#include "g3d/aglNW4FToNN.h"
#include "nn/time.h"
#include "prim/seadStringUtil.h"

bool HackFunction::isTriggerCancelBubbleLauncher(IUsePlayerHack const*) {CRASH}

DisregardReceiver::DisregardReceiver(al::LiveActor*, char const*) {CRASH}
bool DisregardReceiver::receiveMsg(al::SensorMsg const*, al::HitSensor*, al::HitSensor*) {CRASH}


void al::AnimScaleController::resetScale() {CRASH}
void al::AnimScaleController::startHitReaction() {CRASH}

al::JointSpringControllerHolder* al::JointSpringControllerHolder::tryCreateAndInitJointControllerKeeper(al::LiveActor*, char const*) {CRASH}
void al::JointSpringControllerHolder::offControlAll() {CRASH}
void al::JointSpringControllerHolder::onControlAll() {CRASH}

const char* al::getFireMaterialCode(al::LiveActor const*) {CRASH}
const sead::Vector3f& al::getShadowMaskOffset(al::LiveActor const*, char const*) {CRASH}
bool al::isInFirePos(al::LiveActor const*, sead::Vector3f const&) {CRASH}
void al::offGroupClipping(al::LiveActor*) {CRASH}
void al::onGroupClipping(al::LiveActor*) {CRASH}
bool al::pushAndAddVelocityH(al::LiveActor*, al::HitSensor const*, al::HitSensor const*, float) {CRASH}
void al::showSilhouetteModel(al::LiveActor*) {CRASH}
bool al::tryAddRippleRandomBlur(al::LiveActor const*, sead::Vector3f const&, float, float, float) {CRASH}
bool al::tryAddRippleSmall(al::LiveActor const*) {CRASH}
void rs::endHackFromTargetPos(IUsePlayerHack**, sead::Vector3f const&, sead::Quatf const&, sead::Vector3f const&) {CRASH}
void rs::endReset(al::LiveActor*) {CRASH}
void rs::hideHackCap(IUsePlayerHack*) {CRASH}
void rs::hideTutorial(al::IUseSceneObjHolder const*) {CRASH}
bool rs::isActiveHackStartDemo(IUsePlayerHack const*) {CRASH}
bool rs::isHoldHackAction(IUsePlayerHack const*) {CRASH}
bool rs::isHoldHackJump(IUsePlayerHack const*) {CRASH}
bool rs::isTriggerHackAction(IUsePlayerHack const*) {CRASH}
bool rs::isTriggerHackPreInputJump(IUsePlayerHack const*) {CRASH}
bool rs::requestDownToDefaultCameraAngleBySpeed(al::LiveActor const*, float, int) {CRASH}
void rs::requestStageStartHack(al::LiveActor const*, al::HitSensor*, CapTargetInfo const*, al::LiveActor*) {CRASH}
void rs::showHackCap(IUsePlayerHack*) {CRASH}
void rs::showTutorial(al::IUseSceneObjHolder const*) {CRASH}
void rs::solveCollisionInHacking(al::LiveActor*, sead::Vector3f const&) {CRASH}
void rs::startReset(al::LiveActor*) {CRASH}

bool EventFlowFunction::isCapTargetHackType(CapTargetInfo const*, int) {CRASH}
bool GotogotonMark::isMatch(GotogotonMark const*) const {CRASH}
void TouchTargetInfo::setInfoByConnector(al::MtxConnector const*, sead::Vector3f const&, sead::Vector3f const&, bool) {CRASH}
void TouchTargetInfo::setInfoBySensor(al::HitSensor const*, sead::Vector3f const&, sead::Vector3f const&) {CRASH}
void WhipTargetInfo::initWhipTarget(al::HitSensor*, sead::Vector3f const*) {CRASH}
void al::EventFlowExecutor::attackSensor(al::HitSensor*, al::HitSensor*) {CRASH}
void al::validateShadowMask(al::LiveActor*, char const*) {CRASH}
const sead::Vector3f& rs::getPlayerHeadPos(al::LiveActor const*) {CRASH}
bool rs::isMsgHackerDamageAndCancel(al::SensorMsg const*) {CRASH}
bool rs::isPlayerOnActor(al::LiveActor const*) {CRASH}
bool rs::isPlayerSquat(al::LiveActor const*) {CRASH}
bool rs::trySendMsgPlayerReflectOrTrample(al::LiveActor const*, al::HitSensor*, al::HitSensor*) {CRASH}
bool rs::tryShowCapMsgCatchBombCatchFirst(al::IUseSceneObjHolder const*) {CRASH}

ChangeStageInfo::ChangeStageInfo(GameDataHolder const*, al::PlacementInfo const&) {CRASH}
ChangeStageInfo::ChangeStageInfo(GameDataHolder const*, char const*, char const*, bool, int, ChangeStageInfo::SubScenarioType) {CRASH}
DecideIconLayout::DecideIconLayout(char const*, al::LayoutInitInfo const&) : al::NerveExecutor("") {CRASH}
const sead::Matrix34f& MapDataHolder::findViewMtx(int) const {CRASH}
al::NfpInfo* ProjectNfpDirector::tryGetTriggerTouchNfpInfo() {CRASH}
ShineInfo::ShineInfo() {CRASH}
void ShineInfo::init(char const*, char const*, char const*, QuestInfo const*, int) {CRASH}
void TemporaryScenarioCameraHolder::registInfo(int, al::CameraTicket*) {CRASH}
s32 agl::g3d::ResFile::GetTextureIndex(nn::g3d::ResFile const*, char const*) {CRASH}
al::MessageTagDataHolder::MessageTagDataHolder(int) {CRASH}
void al::NfpDirector::start() {CRASH}
void al::NfpDirector::stop() {CRASH}
const char16* al::getStageMessageString(al::IUseMessageSystem const*, char const*, char const*) {CRASH}
bool al::isExistLabelInStageMessage(al::IUseMessageSystem const*, char const*, char const*) {CRASH}
void al::registerMessageTagDataAmiiboName(al::MessageTagDataHolder*, char const*, char const**) {CRASH}
void al::registerMessageTagDataString(al::MessageTagDataHolder*, char const*, char16_t const**) {CRASH}
void al::startHitReaction(al::LayoutActor const*, char const*, char const*) {CRASH}
nn::Result nn::time::Initialize() {CRASH}
bool nn::time::IsInitialized() {CRASH}
nn::Result nn::time::StandardUserSystemClock::GetCurrentTime(nn::time::PosixTime*) {CRASH}
nn::Result nn::time::ToCalendarTime(nn::time::CalendarTime*, nn::time::CalendarAdditionalInfo*, nn::time::PosixTime const&) {CRASH}
const QuestInfo* const* rs::getActiveQuestList(al::IUseSceneObjHolder const*) {CRASH}
s32 rs::getActiveQuestNo(al::IUseSceneObjHolder const*) {CRASH}
s32 rs::getActiveQuestNum(al::IUseSceneObjHolder const*) {CRASH}
al::StringTmp<64> rs::getAmiiboMstxtLabel(bool*, al::IUseMessageSystem const*, int, int, int) {CRASH}
SearchAmiiboDataTable* rs::getSearchAmiiboData(al::IUseSceneObjHolder const*) {CRASH}
void rs::makeMessageLabel(sead::BufferedSafeStringBase<char>*, al::PlacementId const*, char const*) {CRASH}
void rs::tryFindAmiiboCostumeItemInfo(ShopItem::ItemInfo**, ShopItem::ItemInfo**, al::NfpCharacterId const&, int, al::IUseSceneObjHolder*) {CRASH}
bool rs::trySavePrepoChangeCapEvent(char const*, long, long, long) {CRASH}
bool rs::trySavePrepoChangeClothEvent(char const*, long, long, long) {CRASH}
bool sead::StringUtil::tryParseU32(unsigned int*, sead::SafeStringBase<char> const&, sead::StringUtil::CardinalNumber) {CRASH}
void al::copyMemory(void*, void const*, unsigned int) {CRASH}
sead::Heap* al::getCurrentHeap() {CRASH}

void BirdMtxGlideCtrl::invalidateGlide() {CRASH}
bool BirdMtxGlideCtrl::isWaitBird() const {CRASH}
void BirdMtxGlideCtrl::makeActorDeadBirdIfAlive() {CRASH}
BirdMtxGlideCtrl* BirdMtxGlideCtrl::tryCreateAliveWaitByLinksBird(sead::Matrix34f const*, sead::Vector3f const&, al::ActorInitInfo const&, char const*) {CRASH}
void BirdMtxGlideCtrl::update() {CRASH}
void BirdMtxGlideCtrl::validateGlide() {CRASH}
al::MessageSystem* al::LayoutInitInfo::getMessageSystem() const {CRASH}
const char* rs::getCheckpointLabelPrefix() {CRASH}
const char* rs::getPlacementStageName(GameDataHolderAccessor, al::ActorInitInfo const&) {CRASH}
bool rs::isPlayerBinding(al::LiveActor const*) {CRASH}
void rs::makeActorMessageLabel(sead::BufferedSafeStringBase<char>*, al::ActorInitInfo const&, char const*) {CRASH}
void rs::registerCheckpointFlagToWatcher(CheckpointFlag*) {CRASH}
void rs::registerLinkedPlayerStartInfoToHolder(al::IUseSceneObjHolder const*, al::ActorInitInfo const&, char const*, sead::Vector3f const*, sead::Quatf const*) {CRASH}
void rs::requestHideCheckpointFlagBalloon(CheckpointFlag const*) {CRASH}
void rs::requestShowCheckpointFlagBalloon(CheckpointFlag const*, sead::Vector3f const&) {CRASH}
void rs::requestShowCheckpointFlagNameLayout(CheckpointFlag const*, char16_t const*) {CRASH}
void rs::setTouchCheckpointFlagToWatcher(CheckpointFlag*) {CRASH}
