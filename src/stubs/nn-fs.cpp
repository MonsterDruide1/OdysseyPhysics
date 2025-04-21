#include "nn/fs.h"
#include "basis/seadTypes.h"

void nn::fs::CloseDirectory(nn::fs::DirectoryHandle) {CRASH}
void nn::fs::CloseFile(nn::fs::FileHandle) {CRASH}
nn::Result nn::fs::CreateDirectory(char const*) {CRASH}
nn::Result nn::fs::CreateFile(char const*, long) {CRASH}
nn::Result nn::fs::DeleteFile(char const*) {CRASH}
nn::Result nn::fs::FlushFile(nn::fs::FileHandle) {CRASH}
nn::Result nn::fs::GetEntryType(nn::fs::DirectoryEntryType*, char const*) {CRASH}
nn::Result nn::fs::GetFileSize(long*, nn::fs::FileHandle) {CRASH}
nn::Result nn::fs::MountRom(char const*, void*, unsigned long) {CRASH}
nn::Result nn::fs::MountSaveDataForDebug(char const*) {CRASH}
nn::Result nn::fs::OpenDirectory(nn::fs::DirectoryHandle*, char const*, int) {CRASH}
nn::Result nn::fs::OpenFile(nn::fs::FileHandle*, char const*, int) {CRASH}
nn::Result nn::fs::QueryMountRomCacheSize(unsigned long*) {CRASH}
nn::Result nn::fs::ReadDirectory(long*, nn::fs::DirectoryEntry*, nn::fs::DirectoryHandle, long) {CRASH}
nn::Result nn::fs::ReadFile(unsigned long*, nn::fs::FileHandle, long, void*, unsigned long, nn::fs::ReadOption const&) {CRASH}
nn::Result nn::fs::SetFileSize(nn::fs::FileHandle, long) {CRASH}
nn::Result nn::fs::Unmount(char const*) {CRASH}
nn::Result nn::fs::WriteFile(nn::fs::FileHandle, long, void const*, unsigned long, nn::fs::WriteOption const&) {CRASH}
