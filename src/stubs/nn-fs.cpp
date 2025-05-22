#include <cstdio>
#include <string>
#include "Library/Base/StringUtil.h"
#include "nn/fs.h"
#include "basis/seadTypes.h"
#include "settings.h"
#include "vapours/results/results_common.hpp"

const static int SUCCESS = 0;
const static int FAILURE = 1;
#define NN_SUCCESS (*(nn::Result*) &SUCCESS)
#define NN_FAILURE (*(nn::Result*) &FAILURE)

// ----------------
// Used functions, replaced with host-specific handling
nn::Result nn::fs::OpenFile(nn::fs::FileHandle* handle, char const* name, int mode) {
    if (mode != 1) {
        printf("Trying to open file %s for non-read-only - unsupported mode %d!\n", name, mode);
        CRASH
    }

    if (!al::isStartWithString(name, "content:/")) {
        printf("Trying to open unsupported file: %s\n", name);
        CRASH
    }
    std::string full_name = (std::string)settings::sRomfsPath + "/" + (name + 9);

    FILE* file = fopen(full_name.c_str(), "rb");
    if (!file) {
        printf("Error opening file %s (=> %s):\n", name, full_name.c_str());
        perror("Error");
        CRASH
    }
    handle->_internal = (u64) file;
    return NN_SUCCESS;
}
nn::Result nn::fs::GetFileSize(long* size, nn::fs::FileHandle handle) {
    FILE* file = (FILE*) handle._internal;

    s32 prev = ftell(file);
    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    fseek(file, prev, SEEK_SET);

    return NN_SUCCESS;
}
/*
    Read file at a location, with an output amount of bytes read, and additional options.
    bytesRead:  How many bytes were actually read.
    handle:     Handle representing file to be read.
    position:   Position within the file to be read.
    size:       How many bytes to read from file.
    option:     Additional options for reading, see ReadOption.
*/
nn::Result nn::fs::ReadFile(u64* outSize, FileHandle handle, s64 offset, void* buffer, u64 bufferSize, const ReadOption& option) {
    if (option.value != 0) {
        printf("Unknown ReadOption: %d\n", option.value);
        CRASH
    }

    FILE* file = (FILE*) handle._internal;

    s32 prev = ftell(file);
    fseek(file, offset, SEEK_SET);

    *outSize = fread(buffer, 1, bufferSize, file);

    fseek(file, prev, SEEK_SET);

    return NN_SUCCESS;
}
void nn::fs::CloseFile(nn::fs::FileHandle handle) {
    FILE* file = (FILE*) handle._internal;
    fclose(file);
}
// ----------------

// ----------------
// Useless functions
nn::Result nn::fs::QueryMountRomCacheSize(unsigned long* cache_size) {
    *cache_size = 0;
    return NN_SUCCESS;
}
nn::Result nn::fs::MountRom(char const* name, void* cache, unsigned long cache_size) {
    if (cache_size == 0 && al::isEqualString(name, "content"))
        return NN_SUCCESS;  // from seadFileDeviceMgr.cpp
    CRASH
}
// ----------------

void nn::fs::CloseDirectory(nn::fs::DirectoryHandle) {CRASH}
nn::Result nn::fs::CreateDirectory(char const*) {CRASH}
nn::Result nn::fs::CreateFile(char const*, long) {CRASH}
nn::Result nn::fs::DeleteFile(char const*) {CRASH}
nn::Result nn::fs::FlushFile(nn::fs::FileHandle) {CRASH}
nn::Result nn::fs::GetEntryType(nn::fs::DirectoryEntryType*, char const*) {CRASH}
nn::Result nn::fs::MountSaveDataForDebug(char const*) {CRASH}
nn::Result nn::fs::OpenDirectory(nn::fs::DirectoryHandle*, char const*, int) {CRASH}
nn::Result nn::fs::ReadDirectory(long*, nn::fs::DirectoryEntry*, nn::fs::DirectoryHandle, long) {CRASH}
nn::Result nn::fs::SetFileSize(nn::fs::FileHandle, long) {CRASH}
nn::Result nn::fs::Unmount(char const*) {CRASH}
nn::Result nn::fs::WriteFile(nn::fs::FileHandle, long, void const*, unsigned long, nn::fs::WriteOption const&) {CRASH}
