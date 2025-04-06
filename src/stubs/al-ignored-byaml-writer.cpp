#include "Library/Yaml/Writer/ByamlWriterData.h"

void al::ByamlWriterData::write(sead::WriteStream*) const {}

void al::ByamlWriterHash::addData(char const*, al::ByamlWriterData*) {}
void al::ByamlWriterHash::deleteData() {}
void al::ByamlWriterHash::print(int) const {}
void al::ByamlWriterHash::writeContainer(sead::WriteStream*) const {}
