#include "System/Application.h"
#include "Library/System/SystemKit.h"

SEAD_SINGLETON_DISPOSER_IMPL(Application)

Application::Application() = default;
void Application::init(s32, char*[]) {
    mSystemKit = new al::SystemKit();
    mSystemKit->createFileLoader(-1);
    mSystemKit->createResourceSystem(nullptr, -1, 0x400000, true);
    WARN_UNIMPL;
}
