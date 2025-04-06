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
