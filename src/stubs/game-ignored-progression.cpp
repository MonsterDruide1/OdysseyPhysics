#include "MapObj/CapMessageShowInfo.h"
#include "Scene/QuestInfoHolder.h"
#include "System/CapMessageBossData.h"
#include "System/GameConfigData.h"
#include "System/GameDataFile.h"
#include "System/GameDataHolder.h"
#include "System/HintPhotoData.h"
#include "System/MapDataHolder.h"
#include "System/MoonRockData.h"
#include "System/NetworkUploadFlag.h"
#include "System/SaveDataAccessFunction.h"
#include "System/SaveDataAccessSequence.h"
#include "System/ShopTalkData.h"
#include "System/TempSaveData.h"
#include "System/VisitStageData.h"
#include "System/WorldList.h"
#include "System/WorldWarpTalkData.h"
#include "Util/AchievementUtil.h"

namespace rs {
    
bool isShowCapMsgPlayerLife1(al::IUseSceneObjHolder const*) {return true;}
void showCapMsgPlayerLife1(al::IUseSceneObjHolder const*, int) {}
s32 calcBuyItemNumForCoinCollectByWorld(GameDataHolder const*) {return 0;}
s32 calcClearWorldNum(GameDataHolder const*) {return 0;}
s32 calcGetCheckpointNum(GameDataHolder const*) {return 0;}
s32 calcGetShineNumBird(GameDataHolder const*) {return 0;}
s32 calcGetShineNumCapHanger(GameDataHolder const*) {return 0;}
s32 calcGetShineNumCollectAnimal(GameDataHolder const*) {return 0;}
s32 calcGetShineNumCostumeRoom(GameDataHolder const*) {return 0;}
s32 calcGetShineNumDigPoint(GameDataHolder const*) {return 0;}
s32 calcGetShineNumDot(GameDataHolder const*) {return 0;}
s32 calcGetShineNumFigureWalking(GameDataHolder const*) {return 0;}
s32 calcGetShineNumGrowPlant(GameDataHolder const*) {return 0;}
s32 calcGetShineNumHideAndSeekCapMan(GameDataHolder const*) {return 0;}
s32 calcGetShineNumHintPhoto(GameDataHolder const*) {return 0;}
s32 calcGetShineNumJugemFish(GameDataHolder const*) {return 0;}
s32 calcGetShineNumKinopioBrigade(GameDataHolder const*) {return 0;}
s32 calcGetShineNumKuriboGirl(GameDataHolder const*) {return 0;}
s32 calcGetShineNumNoteObj(GameDataHolder const*) {return 0;}
s32 calcGetShineNumRabbit(GameDataHolder const*) {return 0;}
s32 calcGetShineNumRace(GameDataHolder const*) {return 0;}
s32 calcGetShineNumSlot(GameDataHolder const*) {return 0;}
s32 calcGetShineNumTimerAthletic(GameDataHolder const*) {return 0;}
s32 calcGetShineNumTreasureBox(GameDataHolder const*) {return 0;}
s32 calcGetShineNumWorldTravelingPeach(GameDataHolder const*) {return 0;}
s32 calcHackObjNum(GameDataHolderAccessor) {return 0;}
s32 calcSphinxQuizCompleteNum(GameDataHolderAccessor) {return 0;}
s32 calcUnlockMoonRockNum(GameDataHolderAccessor) {return 0;}
s32 calcWorldWarpHoleThroughNum(GameDataHolder const*) {return 0;}
bool checkGetAchievement(GameDataHolderAccessor, char const*) {return false;}
s32 getPlayerJumpCount(GameDataHolder const*) {return 0;}
s32 getPlayerThrowCapCount(GameDataHolder const*) {return 0;}
s32 getTotalCoinNum(GameDataHolder const*) {return 0;}
bool trySavePrepoSeparatePlayMode(bool, s64, s64, s64) {return false;}

}

void SaveDataAccessFunction::startSaveDataWriteSync(GameDataHolder*) {}
SaveDataAccessSequence::SaveDataAccessSequence(GameDataHolder*, al::LayoutInitInfo const&) : al::NerveExecutor("") {}

GameConfigData::GameConfigData() {}

MapDataHolder::MapDataHolder(GameDataHolder const*) {}

CapMessageBossData::CapMessageBossData() {}
void CapMessageBossData::init() {}

bool HintPhotoData::checkSavedHintPhoto(char const*) const {return false;}
void HintPhotoData::saveHintPhoto(char const*) {}

void NetworkUploadFlag::updateScore(RankingCategory const&) {}

bool ShopTalkData::checkExistNewItem(GameDataHolderAccessor const&, int, int, bool) const {return false;}
bool ShopTalkData::checkShowNewItemAndPrepareSave(GameDataHolderAccessor const&, bool, int) {return false;}
bool ShopTalkData::isEnableExplainShopCoin(int) const {return false;}

bool VisitStageData::checkAlreadyVisit(char const*) const {return false;}
void VisitStageData::visit(char const*) {}

WorldList::WorldList() {}
bool WorldList::checkNeedTreasureMessageStage(char const*) const {return false;}
s32 WorldList::findUseScenarioNo(char const*) const {return 0;}
const char* WorldList::getWorldDevelopName(int) const {return "";}
bool WorldList::isEqualAfterEndingScenarioNo(int, int) const {return false;}
bool WorldList::isEqualClearMainScenarioNo(int, int) const {return false;}
bool WorldList::isEqualMoonRockScenarioNo(int, int) const {return false;}
s32 WorldList::tryFindWorldIndexByMainStageName(const char*) const {return 0;}
s32 WorldList::getWorldNum() const {return 0;}
s32 WorldList::tryFindWorldIndexByDevelopName(char const*) const {return 0;}
s32 WorldList::tryFindWorldIndexByStageName(char const*) const {return 0;}
s32 WorldList::getMainQuestMin(int, int) const {return 0;}
const char* WorldList::getMainStageName(int) const {return "";}
s32 WorldList::getWorldScenarioNum(int) const {return 0;}
bool WorldList::tryFindTransOnMainStageByStageName(sead::Vector3<float>*, char const*, int) const {return false;}

void WorldWarpTalkData::addTipsId() {}
s32 WorldWarpTalkData::getTipsId() const {return 0;}
bool WorldWarpTalkData::isAlreadyTalkNextWorld(int) const {return true;}
bool WorldWarpTalkData::isAlreadyTalkPrevWorld(int) const {return true;}
bool WorldWarpTalkData::isTalkBossRaid() const {return true;}
bool WorldWarpTalkData::isTalkFindKoopa() const {return true;}
void WorldWarpTalkData::setAlreadyTalkNextWorld(int) {}
void WorldWarpTalkData::setAlreadyTalkPrevWorld(int) {}
void WorldWarpTalkData::setTalkSpecial(bool, bool) {}

void MoonRockData::addMoonRockTalkMessageIndex(int) {}
s32 MoonRockData::calcMoonRockTalkMessageIndex() const {return 0;}
bool MoonRockData::isAppearedMoonRockTalkMessage(int) const {return false;}
bool MoonRockData::isEnableShowDemoOpenMoonRockFirst() const {return false;}
bool MoonRockData::isEnableShowDemoOpenMoonRockWorld(int) const {return false;}
void MoonRockData::showDemoOpenMoonRockFirst() {}
void MoonRockData::showDemoOpenMoonRockWorld(int) {}

TempSaveData::TempSaveData() {}
void TempSaveData::deleteInWorld(al::PlacementId const*, char const*) {}
void TempSaveData::deleteInWorldResetMiniGame(al::PlacementId const*, char const*) {}
bool TempSaveData::findHashValueInWorld(char const*) const {return false;}
void TempSaveData::init() {}
void TempSaveData::initForScenario() {}
bool TempSaveData::isOnInScenario(al::PlacementId const*, char const*) const {return false;}
bool TempSaveData::isOnInWorld(al::PlacementId const*, char const*) const {return false;}
bool TempSaveData::isOnInWorldResetMiniGame(al::PlacementId const*, char const*) const {return false;}
void TempSaveData::resetMiniGame() {}
void TempSaveData::setInfo(int, int) {}
void TempSaveData::writeHashInWorld(char const*, bool) {}
void TempSaveData::writeInScenario(al::PlacementId const*, char const*) {}
void TempSaveData::writeInWorld(al::PlacementId const*, char const*) {}
void TempSaveData::writeInWorldResetMiniGame(al::PlacementId const*, char const*) {}

void GameDataFile::addGrowFlowerGrowLevel(al::PlacementId const*, unsigned int) {}
s32 GameDataFile::calcAllShineNumByObjectNameOrOptionalId(char const*) const {return 0;}
s32 GameDataFile::calcGetShineNumByObjectNameOrOptionalId(char const*, GameDataFile::CountType) const {return 0;}
s32 GameDataFile::calcGetShineNumByObjectNameWithWorldId(char const*, int) const {return 0;}
void GameDataFile::calcShineIndexTableNameAvailable(int*, int*, int) {}
void GameDataFile::calcShineIndexTableNameUnlockable(int*, int*, int) {}
const char* GameDataFile::findGrowFlowerPotIdFromSeedId(al::PlacementId const*) {return "";}
RaceRecord* GameDataFile::findRaceRecord(char const*) const {WARN_UNIMPL; return nullptr;}
u32 GameDataFile::getGrowFlowerGrowLevel(al::PlacementId const*) const {return 0;}
u64 GameDataFile::getGrowFlowerTime(al::PlacementId const*) const {return 0;}
s32 GameDataFile::getScenarioNo() const {return 0;}
s32 GameDataFile::getShineNum(int) const {return 0;}
s32 GameDataFile::getTokimekiMayorNpcFavorabilityRating() const {return 0;}
bool GameDataFile::isClearWorldMainScenario(int) const {return false;}
bool GameDataFile::isEnableOpenMoonRock(int) const {return false;}
bool GameDataFile::isFirstNetwork() const {return false;}
bool GameDataFile::isStartWorldTravelingPeach() const {return false;}
bool GameDataFile::isTalkCollectBgmNpc() const {return false;}
bool GameDataFile::isTalkKakku() const {return false;}
bool GameDataFile::isTalkWorldTravelingPeach() const {return false;}
bool GameDataFile::isUsedGrowFlowerSeed(al::PlacementId const*) const {return false;}
void GameDataFile::noFirstNetwork() {}
void GameDataFile::setGrowFlowerTime(al::PlacementId const*, al::PlacementId const*, u64) {}
void GameDataFile::setGrowFlowerTime(al::PlacementId const*, u64) {}
void GameDataFile::setJumpingRopeBestCount(int) {}
void GameDataFile::setTokimekiMayorNpcFavorabilityRating(int) {}
void GameDataFile::setUpdateJumpingRopeScoreFlag() {}
void GameDataFile::setUpdateVolleyballScoreFlag() {}
void GameDataFile::setVolleyballBestCount(int) {}
void GameDataFile::startWorldTravelingPeach() {}
void GameDataFile::talkCollectBgmNpc() {}
void GameDataFile::talkKakku() {}
void GameDataFile::talkLocalLanguage() {}
void GameDataFile::talkWorldTravelingPeach() {}
bool GameDataFile::tryGetNextMainScenarioLabel(sead::BufferedSafeStringBase<char>*, sead::BufferedSafeStringBase<char>*) const {return false;}
bool GameDataFile::tryUnlockShineName(int, int) {return false;}
void GameDataFile::addCoin(int) {}
void GameDataFile::addCoinCollect(al::PlacementId const*) {}
void GameDataFile::addHackDictionary(char const*) {}
void GameDataFile::addKey(int) {}
void GameDataFile::addOpenDoorLockNum(int) {}
void GameDataFile::addPayShine(int) {}
void GameDataFile::addPayShineCurrentAll() {}
void GameDataFile::buyItem(ShopItem::ItemInfo const*, bool) {}
void GameDataFile::buyItemAll() {}
s32 GameDataFile::calcHaveCapNum() const {return 0;}
s32 GameDataFile::calcHaveClothNum() const {return 0;}
s32 GameDataFile::calcHaveGiftNum() const {return 0;}
s32 GameDataFile::calcHaveStickerNum() const {return 0;}
s32 GameDataFile::calcHintMoonRockNum() const {return 0;}
const sead::Vector3f& GameDataFile::calcHintMoonRockTrans(int) const {return sead::Vector3f::zero;}
s32 GameDataFile::calcHintNum() const {return 0;}
const sead::Vector3f& GameDataFile::calcHintTrans(int) const {return sead::Vector3f::zero;}
const sead::Vector3f& GameDataFile::calcHintTransMostEasy() const {return sead::Vector3f::zero;}
bool GameDataFile::calcIsGetMainShineAll(al::IUseSceneObjHolder const*) const {return false;}
bool GameDataFile::calcIsGetShineAllInWorld(int) const {return false;}
s32 GameDataFile::calcLinkedShineNum(al::ActorInitInfo const&) const {return 0;}
s32 GameDataFile::calcMiniGameNum() const {return 0;}
s32 GameDataFile::calcNextScenarioNo() const {return 0;}
s32 GameDataFile::calcRestHintNum() const {return 0;}
s32 GameDataFile::calcShineNumInOneShine(int, int) const {return 0;}
s32 GameDataFile::calcShopNum() const {return 0;}
void GameDataFile::changeNextSceneByGotCheckpoint(int) {}
void GameDataFile::changeNextSceneByHome() {}
bool GameDataFile::checkAchievementShine(int, int) const {return false;}
void GameDataFile::clearStartId() {}
void GameDataFile::disableHintById(int) {}
void GameDataFile::enteredStage() {}
const GameDataFile::HintInfo& GameDataFile::findHint(int) const {CRASH;}
const GameDataFile::HintInfo& GameDataFile::findHintMoonRock(int) const {CRASH;}
const GameDataFile::HintInfo* GameDataFile::findShine(int, int) const {WARN_UNIMPL;return nullptr;}
s32 GameDataFile::findUnlockShineNumCurrentWorld(bool*) const {return 0;}
s32 GameDataFile::getCheckpointNumMaxInWorld() const {return 0;}
const char* GameDataFile::getCheckpointObjIdInWorld(int) const {return "";}
const sead::Vector3f& GameDataFile::getCheckpointTransInWorld(char const*) const {return sead::Vector3f::zero;}
s32 GameDataFile::getCoinCollectGotNum() const {return 0;}
s32 GameDataFile::getCoinCollectGotNum(int) const {return 0;}
s32 GameDataFile::getCoinCollectNum() const {return 0;}
const CollectBgm& GameDataFile::getCollectBgmByIndex(int) const {CRASH;}
s32 GameDataFile::getCollectedBgmMaxNum() const {return 0;}
s32 GameDataFile::getCollectedBgmNum() const {return 0;}
s32 GameDataFile::getKeyNum() const {return 0;}
const char* GameDataFile::getMiniGameName(int) const {return "";}
s32 GameDataFile::getMiniGameNumMax() const {return 0;}
const sead::Vector3f& GameDataFile::getMiniGameTrans(int) const {return sead::Vector3f::zero;}
s64 GameDataFile::getPlayTimeTotal() const {return 0;}
PlayerHitPointData* GameDataFile::getPlayerHitPointData() const {WARN_UNIMPL; return nullptr;}
const sead::Vector3f& GameDataFile::getPoetterTrans() const {return sead::Vector3f::zero;}
s32 GameDataFile::getRaceLoseCount(int) const {return 0;}
s32 GameDataFile::getScenarioNoPlacement() const {return 0;}
s32 GameDataFile::getShineNum() const {return 0;}
s32 GameDataFile::getShopNpcIconNumMax() const {return 0;}
const sead::Vector3f& GameDataFile::getShopNpcTrans(int) const {return sead::Vector3f::zero;}
s32 GameDataFile::getStartShineNextIndex() const {return 0;}
const sead::Vector3f& GameDataFile::getTimeBalloonNpcTrans() const {return sead::Vector3f::zero;}
s32 GameDataFile::getTotalPayShineNum() const {return 0;}
s32 GameDataFile::getTotalShineNum() const {return 0;}
s32 GameDataFile::getWorldTotalShineNum(int) const {return 0;}
s32 GameDataFile::getWorldTotalShineNumMax(int) const {return 0;}
const char* GameDataFile::getWorldTravelingStatus() const {return "";}
void GameDataFile::incrementRaceLoseCount(int) {}
void GameDataFile::initializeHintList() {}
bool GameDataFile::isAlreadyShowExplainCheckpointFlag() const {return false;}
bool GameDataFile::isBuyItem(ShopItem::ItemInfo const*) const {return false;}
bool GameDataFile::isBuyItem(char const*, sead::FixedSafeString<64> const*) const {return false;}
bool GameDataFile::isCollectedBgm(char const*, char const*) const {return false;}
bool GameDataFile::isEnableUnlockHint() const {return false;}
bool GameDataFile::isExistInHackDictionary(char const*) const {return false;}
bool GameDataFile::isExistJango() const {return false;}
bool GameDataFile::isExistPoetter() const {return false;}
bool GameDataFile::isExistTimeBalloonNpc() const {return false;}
bool GameDataFile::isFirstTimeNextWorld() const {return false;}
bool GameDataFile::isFirstWorldTravelingStatus() const {return false;}
bool GameDataFile::isFlagOnTalkMessageInfo(int) const {return false;}
bool GameDataFile::isGoToCeremonyFromInsideHomeShip() const {return false;}
bool GameDataFile::isGotCheckpoint(al::PlacementId*) const {return false;}
bool GameDataFile::isGotCheckpointInWorld(int) const {return false;}
bool GameDataFile::isGotCoinCollect(al::PlacementId const*) const {return false;}
bool GameDataFile::isGotShine(ShineInfo const*) const {return false;}
bool GameDataFile::isGotShine(int) const {return false;}
bool GameDataFile::isGotShine(int, int) const {return false;}
bool GameDataFile::isLatestGetMainShine(ShineInfo const*) const {return false;}
bool GameDataFile::isMainShine(int) const {return false;}
bool GameDataFile::isNextMainShine(int) const {return false;}
bool GameDataFile::isOpenMoonRock(int) const {return false;}
bool GameDataFile::isOpenShineName(int, int) const {return false;}
bool GameDataFile::isPayCoinToSphinx() const {return false;}
bool GameDataFile::isPayShineAllInAllWorld() const {return false;}
bool GameDataFile::isPlayDemoPlayerDownForBattleKoopaAfter() const {return false;}
bool GameDataFile::isPlayScenarioCamera(QuestInfo const*) const {return false;}
bool GameDataFile::isRaceStart() const {return false;}
bool GameDataFile::isShopSellout(int) const {return false;}
bool GameDataFile::isStartedObj(al::PlacementId const*, char const*) const {return false;}
void GameDataFile::missAndRestartStage() {}
void GameDataFile::noPlayDemoWorldWarp() {}
void GameDataFile::payCoinToSphinx() {}
void GameDataFile::registerCheckpointTrans(al::PlacementId const*, sead::Vector3<float> const&) {}
void GameDataFile::registerShineInfo(ShineInfo const*, sead::Vector3<float> const&) {}
void GameDataFile::resetHintTrans(int) {}
void GameDataFile::restartStage() {}
void GameDataFile::saveWorldTravelingStatus(char const*) {}
void GameDataFile::setActivateHome() {}
void GameDataFile::setAmiiboNpcTrans(sead::Vector3<float> const&) {}
void GameDataFile::setFlagOnTalkMessageInfo(int) {}
void GameDataFile::setGotShine(ShineInfo const*) {}
void GameDataFile::setHintTrans(int, sead::Vector3<float> const&) {}
void GameDataFile::setJangoTrans(sead::Vector3<float> const&) {}
void GameDataFile::setKidsMode(bool) {}
void GameDataFile::setMainScenarioNo(int) {}
void GameDataFile::setMiniGameInfo(sead::Vector3<float> const&, char const*) {}
void GameDataFile::setMoonRockTrans(sead::Vector3<float> const&) {}
void GameDataFile::setPoetterTrans(sead::Vector3<float> const&) {}
void GameDataFile::setRestartPointId(al::PlacementId const*) {}
void GameDataFile::setSaveObjS32(al::PlacementId const*, int) {}
void GameDataFile::setShopNpcTrans(sead::Vector3<float> const&, char const*, int) {}
void GameDataFile::setStartShine(ShineInfo const*) {}
void GameDataFile::setStartedObj(al::PlacementId const*) {}
void GameDataFile::setTimeBalloonNpcTrans(sead::Vector3<float> const&) {}
void GameDataFile::showExplainCheckpointFlag() {}
void GameDataFile::startDemoStage(char const*) {}
bool GameDataFile::tryFindAndInitShineInfoByOptionalId(ShineInfo*, char const*) {return false;}
const char* GameDataFile::tryFindExistCoinCollectStageName(int) const {return "";}
s32 GameDataFile::tryFindLinkedShineIndex(al::ActorInitInfo const&, al::IUseSceneObjHolder const*) const {return -1;}
s32 GameDataFile::tryFindLinkedShineIndex(al::ActorInitInfo const&, int, al::IUseSceneObjHolder const*) const {return -1;}
s32 GameDataFile::tryFindLinkedShineIndexByLinkName(al::IUseSceneObjHolder const*, al::ActorInitInfo const&, char const*) const {return -1;}
s32 GameDataFile::tryFindShineIndex(al::ActorInitInfo const&) const {return -1;}
s32 GameDataFile::tryFindShineIndex(char const*, char const*) const {return -1;}
s32 GameDataFile::tryFindUniqueId(ShineInfo const*) const {return -1;}
bool GameDataFile::tryGetNextMainScenarioPos(sead::Vector3<float>*) const {return false;}
const char* GameDataFile::tryGetRestartPointIdString() const {return "";}
bool GameDataFile::trySetCollectedBgm(char const*, char const*) {return false;}
void GameDataFile::unlockHint() {}
void GameDataFile::unlockHintAddByMoonRock() {}
void GameDataFile::unlockHintAmiibo() {}
void GameDataFile::unlockWorld(int) {}
void GameDataFile::winRace() {}
GameDataFile::GameDataFile(GameDataHolder*) {}
void GameDataFile::changeNextStage(ChangeStageInfo const*, int) {}
void GameDataFile::changeNextStageWithDemoWorldWarp(char const*) {}
void GameDataFile::changeNextStageWithWorldWarpHole(char const*) {}
void GameDataFile::endStage() {}
const char* GameDataFile::getPlayerStartId() const {}
void GameDataFile::initializeData() {}
bool GameDataFile::readFromStream(sead::ReadStream*, unsigned char*) {}
void GameDataFile::resetTempData() {}
void GameDataFile::returnPrevStage() {}
void GameDataFile::setCheckpointId(al::PlacementId const*) {}
void GameDataFile::startStage(char const*, int) {}
bool GameDataFile::tryReadByamlData(unsigned char const*) {}
void GameDataFile::updateSaveInfoForDisp() {}
void GameDataFile::updateSaveTime() {}
void GameDataFile::writeToStream(sead::WriteStream*, sead::Heap*) const {}
