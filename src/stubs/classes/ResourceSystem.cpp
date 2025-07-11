#include "Project/Resource/ResourceSystem.h"
#include "Library/Resource/Resource.h"

namespace al {


ResourceSystem::ResourceSystem(const char*) {WARN_UNIMPL;}
const sead::SafeString& ResourceSystem::addCategory(const sead::SafeString&, s32, sead::Heap*) {CRASH}
Resource* ResourceSystem::findOrCreateResourceCategory(const sead::SafeString&, const sead::SafeString&, const char*) {CRASH}
s64 ResourceSystem::findResourceCategoryIter(const sead::SafeString&) {CRASH}
bool ResourceSystem::isEmptyCategoryResource(const sead::SafeString&) {CRASH}
void ResourceSystem::createCategoryResourceAll(const sead::SafeString&) {CRASH}
Resource* ResourceSystem::createResource(const sead::SafeString&, ResourceCategory*, const char*) {CRASH}
void ResourceSystem::removeCategory(const sead::SafeString&) {CRASH}
Resource* ResourceSystem::findResource(const sead::SafeString&) {CRASH}
Resource* ResourceSystem::findResourceCore(const sead::SafeString&, sead::RingBuffer<ResourceCategory*>::iterator*) {CRASH}
Resource* ResourceSystem::findOrCreateResource(const sead::SafeString& x, const char*) {WARN_UNIMPL;return new Resource(x);}
ResourceSystem::ResourceCategory* ResourceSystem::findResourceCategory(const sead::SafeString&) {CRASH}
void ResourceSystem::loadCategoryArchiveAll(const sead::SafeString&) {CRASH}
void ResourceSystem::setCurrentCategory(const char*) {CRASH}
const char* ResourceSystem::findCategoryNameFromTable(const sead::SafeString&) const {CRASH}
bool ResourceSystem::tryGetTableCategoryIter(ByamlIter*, const sead::SafeString&) const {CRASH}
bool ResourceSystem::tryGetGraphicsInfoIter(ByamlIter*, const sead::SafeString&) const {CRASH}


}
