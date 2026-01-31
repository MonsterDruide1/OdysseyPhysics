#include "MapObj/CapMessageShowInfo.h"
#include "System/GameDataFile.h"
#include "System/GameDataFunction.h"
#include "System/HintPhotoData.h"
#include "System/NetworkUploadFlag.h"
#include "System/ShopTalkData.h"
#include "System/VisitStageData.h"
#include "System/WorldList.h"
#include "System/WorldWarpTalkData.h"

namespace rs {
    
bool isShowCapMsgPlayerLife1(al::IUseSceneObjHolder const*) {return true;}
void showCapMsgPlayerLife1(al::IUseSceneObjHolder const*, int) {}

}

bool HintPhotoData::checkSavedHintPhoto(char const*) const {return false;}
void HintPhotoData::saveHintPhoto(char const*) {}

void NetworkUploadFlag::updateScore(RankingCategory const&) {}

bool ShopTalkData::checkExistNewItem(GameDataHolderAccessor const&, int, int, bool) const {return false;}
bool ShopTalkData::checkShowNewItemAndPrepareSave(GameDataHolderAccessor const&, bool, int) {return false;}
bool ShopTalkData::isEnableExplainShopCoin(int) const {return false;}

bool VisitStageData::checkAlreadyVisit(char const*) const {return false;}
void VisitStageData::visit(char const*) {}

const char* WorldList::getWorldDevelopName(int) const {return "";}
bool WorldList::isEqualAfterEndingScenarioNo(int, int) const {return false;}
bool WorldList::isEqualClearMainScenarioNo(int, int) const {return false;}
bool WorldList::isEqualMoonRockScenarioNo(int, int) const {return false;}
s32 WorldList::tryFindWorldIndexByMainStageName(const char*) const {return 0;}
s32 WorldList::getWorldNum() const {return 0;}
s32 WorldList::tryFindWorldIndexByDevelopName(char const*) const {return 0;}
s32 WorldList::tryFindWorldIndexByStageName(char const*) const {return 0;}

void WorldWarpTalkData::addTipsId() {CRASH}
s32 WorldWarpTalkData::getTipsId() const {CRASH}
bool WorldWarpTalkData::isAlreadyTalkNextWorld(int) const {CRASH}
bool WorldWarpTalkData::isAlreadyTalkPrevWorld(int) const {CRASH}
bool WorldWarpTalkData::isTalkBossRaid() const {CRASH}
bool WorldWarpTalkData::isTalkFindKoopa() const {CRASH}
void WorldWarpTalkData::setAlreadyTalkNextWorld(int) {CRASH}
void WorldWarpTalkData::setAlreadyTalkPrevWorld(int) {CRASH}
void WorldWarpTalkData::setTalkSpecial(bool, bool) {CRASH}

const char* GameDataFunction::getCurrentCapTypeName(GameDataHolderAccessor) {return "";}
const char* GameDataFunction::getCurrentCostumeTypeName(GameDataHolderAccessor) {return "";}
s32 GameDataFunction::getCurrentWorldId(GameDataHolderAccessor) {return 0;}
s32 GameDataFunction::getWorldIndexBoss() {return 0;}
s32 GameDataFunction::getWorldIndexCity() {return 0;}
s32 GameDataFunction::getWorldIndexCloud() {return 0;}
s32 GameDataFunction::getWorldIndexForest() {return 0;}
s32 GameDataFunction::getWorldIndexHat() {return 0;}
s32 GameDataFunction::getWorldIndexLake() {return 0;}
s32 GameDataFunction::getWorldIndexPeach() {return 0;}
s32 GameDataFunction::getWorldIndexSea() {return 0;}
s32 GameDataFunction::getWorldIndexSky() {return 0;}
s32 GameDataFunction::getWorldIndexSnow() {return 0;}
s32 GameDataFunction::getWorldIndexSpecial2() {return 0;}
s32 GameDataFunction::getWorldIndexWaterfall() {return 0;}
bool GameDataFunction::isCityWorldCeremonyAll(int, int) {return false;}
bool GameDataFunction::isObjStarted(GameDataHolderAccessor, char const*, char const*) {return false;}
bool GameDataFunction::isRaceStartFlag(GameDataHolderAccessor) {return false;}
s32 GameDataFunction::findWorldIdByDevelopName(GameDataHolderAccessor, char const*) {return 0;}
s32 GameDataFunction::getCurrentWorldIdNoDevelop(GameDataHolderAccessor) {return 0;}
s32 GameDataFunction::getGotShineNum(GameDataHolderAccessor, int) {return 0;}
s32 GameDataFunction::getPrevWorldId(GameDataHolderAccessor) {return 0;}
s32 GameDataFunction::getTotalPayShineNum(GameDataHolderAccessor) {return 0;}
s32 GameDataFunction::getWorldIndexClash() {return 0;}
bool GameDataFunction::isCollectedBgm(GameDataHolderAccessor, char const*, char const*) {return false;}
bool GameDataFunction::isExistJango(GameDataHolderAccessor) {return false;}
bool GameDataFunction::isRaceStart(GameDataHolderAccessor) {return false;}
bool GameDataFunction::isTimeBalloonSequence(GameDataHolderAccessor) {return false;}
bool GameDataFunction::isWorldClash(GameDataHolderAccessor) {return false;}
void GameDataFunction::saveObjS32(GameDataHolderWriter, al::PlacementId const*, int) {}
bool GameDataFunction::tryFindSaveObjS32Value(int*, GameDataHolderAccessor, al::PlacementId const*) {return false;}
bool GameDataFunction::isWorldMoon(GameDataHolderAccessor) {return false;}
bool GameDataFunction::isOnObjNoWriteSaveData(GameDataHolderAccessor, al::PlacementId const*) {return false;}
bool GameDataFunction::isOnObjNoWriteSaveDataInSameScenario(GameDataHolder const*, al::PlacementId const*) {return false;}
bool GameDataFunction::isObjStarted(GameDataHolder const*, al::PlacementId const*) {return false;}
void GameDataFunction::setObjStarted(GameDataHolder*, al::PlacementId const*) {}
void GameDataFunction::onObjNoWriteSaveData(GameDataHolderWriter, al::PlacementId const*) {}
void GameDataFunction::onObjNoWriteSaveDataResetMiniGame(GameDataHolderWriter, al::PlacementId const*) {}
void GameDataFunction::onObjNoWriteSaveDataInSameScenario(GameDataHolder*, al::PlacementId const*) {}
void GameDataFunction::offObjNoWriteSaveData(GameDataHolderWriter, al::PlacementId const*) {}
void GameDataFunction::offObjNoWriteSaveDataResetMiniGame(GameDataHolderWriter, al::PlacementId const*) {}
void GameDataFunction::damagePlayer(GameDataHolderWriter) {}
s32 GameDataFunction::getPlayerHitPoint(GameDataHolderAccessor) {return 3;}
bool GameDataFunction::isPlayerHitPointMax(GameDataHolderAccessor) {return true;}
void GameDataFunction::killPlayer(GameDataHolderWriter) {}
void GameDataFunction::recoveryPlayer(al::LiveActor const*) {}

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
void GameDataFile::setGrowFlowerTime(al::PlacementId const*, al::PlacementId const*, unsigned long) {}
void GameDataFile::setGrowFlowerTime(al::PlacementId const*, unsigned long) {}
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

GameDataHolder::GameDataHolder() {}
GameDataHolder::~GameDataHolder() {}
const char* GameDataHolder::getSceneObjName() const {return "";}
al::MessageSystem* GameDataHolder::getMessageSystem() const {WARN_UNIMPL;return nullptr;}
void GameDataHolder::calcWorldWarpHoleLabelAndStageName(sead::BufferedSafeStringBase<char>*, sead::BufferedSafeStringBase<char>*, char const*, int) const {}
bool GameDataHolder::checkIsOpenWorldWarpHoleInScenario(int, int) const {return false;}
s32 GameDataHolder::findUnlockShineNum(bool*, int) const {return 0;}
bool GameDataHolder::findValueFromTempSaveDataHash(char const*) {return false;}
CapMessageBossData* GameDataHolder::getCapMessageBossData() const {WARN_UNIMPL; return nullptr;}
void GameDataHolder::playScenarioStartCamera(int) {}
void GameDataHolder::writeTempSaveDataToHash(char const*, bool) {}
void GameDataHolder::setRequireSave() {}
