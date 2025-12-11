#include "System/GameDataFile.h"
#include "System/GameDataFunction.h"
#include "System/WorldList.h"

s32 WorldList::tryFindWorldIndexByMainStageName(const char*) const {return 0;}
s32 WorldList::getWorldNum() const {return 0;}
s32 WorldList::tryFindWorldIndexByDevelopName(char const*) const {return 0;}

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
