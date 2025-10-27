#include "Project/Resource/ResourceSystem.h"
#include "Library/Resource/Resource.h"

namespace al {

static ResourceSystem::ResourceCategory sResource {"", nullptr};

ResourceSystem::ResourceCategory* ResourceSystem::addCategory(const sead::SafeString& name, s32 id, sead::Heap* heap) {WARN_UNIMPL;sResource = {name, heap}; return &sResource;}
Resource* ResourceSystem::findOrCreateResourceCategory(const sead::SafeString&, const sead::SafeString&, const char*) {CRASH}
sead::RingBuffer<ResourceSystem::ResourceCategory*>::iterator ResourceSystem::findResourceCategoryIter(const sead::SafeString&) {CRASH}
bool ResourceSystem::isEmptyCategoryResource(const sead::SafeString&) {CRASH}
void ResourceSystem::createCategoryResourceAll(const sead::SafeString&) {CRASH}
void ResourceSystem::removeCategory(const sead::SafeString&) {CRASH}
ResourceSystem::ResourceCategory* ResourceSystem::findResourceCategory(const sead::SafeString&) {WARN_UNIMPL;return &sResource;}
void ResourceSystem::loadCategoryArchiveAll(const sead::SafeString&) {CRASH}

}
