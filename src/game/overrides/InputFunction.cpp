#include "Library/Controller/InputFunction.h"
#include "raylib.h"

namespace al {

#define CONTROLLER_A KEY_C
#define CONTROLLER_B KEY_X
#define CONTROLLER_X KEY_V
#define CONTROLLER_Y KEY_Y
#define CONTROLLER_ZL KEY_R
#define CONTROLLER_ZR KEY_T
#define CONTROLLER_L KEY_Q
#define CONTROLLER_R KEY_E
#define CONTROLLER_UP KEY_UP
#define CONTROLLER_DOWN KEY_DOWN
#define CONTROLLER_LEFT KEY_LEFT
#define CONTROLLER_RIGHT KEY_RIGHT
#define CONTROLLER_1 KEY_F
#define CONTROLLER_2 KEY_G
#define CONTROLLER_HOME -1
#define CONTROLLER_START -1
#define CONTROLLER_SELECT -1
#define CONTROLLER_PLUS KEY_M
#define CONTROLLER_MINUS KEY_N
#define CONTROLLER_LSTICK_UP KEY_W
#define CONTROLLER_LSTICK_DOWN KEY_S
#define CONTROLLER_LSTICK_LEFT KEY_A
#define CONTROLLER_LSTICK_RIGHT KEY_D
#define CONTROLLER_RSTICK_UP KEY_I
#define CONTROLLER_RSTICK_DOWN KEY_K
#define CONTROLLER_RSTICK_LEFT KEY_J
#define CONTROLLER_RSTICK_RIGHT KEY_L


sead::ControllerBase* getController_(s32 port) {
    CRASH
    return isValidReplayController(port) ? getReplayController(port) :
                                           sead::ControllerMgr::instance()->getController(port);
}

sead::ControllerBase* getController(s32 port) {
    CRASH
    if (port == -1) {
        port = getMainControllerPort();
    }

    return getController_(port);
}

bool isPadTrigger(s32 port, s32 button) {
    return getController(port)->isTrig(button);
}

bool isPadTriggerA(s32 port) {
    return IsKeyDown(CONTROLLER_A);
}
bool isPadTriggerB(s32 port) {
    return IsKeyDown(CONTROLLER_B);
}
bool isPadTriggerX(s32 port) {
    return IsKeyDown(CONTROLLER_X);
}
bool isPadTriggerY(s32 port) {
    return IsKeyDown(CONTROLLER_Y);
}
bool isPadTriggerZL(s32 port) {
    return IsKeyDown(CONTROLLER_ZL);
}
bool isPadTriggerZR(s32 port) {
    return IsKeyDown(CONTROLLER_ZR);
}
bool isPadTriggerL(s32 port) {
    return IsKeyDown(CONTROLLER_L);
}
bool isPadTriggerR(s32 port) {
    return IsKeyDown(CONTROLLER_R);
}
bool isPadTrigger1(s32 port) {
    return IsKeyDown(CONTROLLER_1);
}
bool isPadTrigger2(s32 port) {
    return IsKeyDown(CONTROLLER_2);
}
bool isPadTriggerUp(s32 port) {
    return IsKeyDown(CONTROLLER_UP);
}
bool isPadTriggerDown(s32 port) {
    return IsKeyDown(CONTROLLER_DOWN);
}
bool isPadTriggerLeft(s32 port) {
    return IsKeyDown(CONTROLLER_LEFT);
}
bool isPadTriggerRight(s32 port) {
    return IsKeyDown(CONTROLLER_RIGHT);
}
bool isPadTriggerLeftUp(s32 port) {
    return IsKeyDown(CONTROLLER_LEFT) && IsKeyDown(CONTROLLER_UP);
}
bool isPadTriggerLeftDown(s32 port) {
    return IsKeyDown(CONTROLLER_LEFT) && IsKeyDown(CONTROLLER_DOWN);
}
bool isPadTriggerRightUp(s32 port) {
    return IsKeyDown(CONTROLLER_RIGHT) && IsKeyDown(CONTROLLER_UP);
}
bool isPadTriggerRightDown(s32 port) {
    return IsKeyDown(CONTROLLER_RIGHT) && IsKeyDown(CONTROLLER_DOWN);
}
bool isPadTriggerHome(s32 port) {
    return IsKeyDown(CONTROLLER_HOME);
}
bool isPadTriggerStart(s32 port) {
    return IsKeyDown(CONTROLLER_START);
}
bool isPadTriggerSelect(s32 port) {
    return IsKeyDown(CONTROLLER_SELECT);
}
bool isPadTriggerPlus(s32 port) {
    return IsKeyDown(CONTROLLER_PLUS);
}
bool isPadTriggerMinus(s32 port) {
    return IsKeyDown(CONTROLLER_MINUS);
}
bool isPadTriggerTouch() {
    CRASH
}
bool isPadTriggerUpLeftStick(s32 port) {
    return IsKeyDown(CONTROLLER_LSTICK_UP) && IsKeyDown(CONTROLLER_LSTICK_LEFT);
}
bool isPadTriggerDownLeftStick(s32 port) {
    return IsKeyDown(CONTROLLER_LSTICK_DOWN) && IsKeyDown(CONTROLLER_LSTICK_LEFT);
}
bool isPadTriggerLeftLeftStick(s32 port) {
    return IsKeyDown(CONTROLLER_LSTICK_LEFT);
}
bool isPadTriggerRightLeftStick(s32 port) {
    return IsKeyDown(CONTROLLER_LSTICK_RIGHT);
}
bool isPadTriggerUpRightStick(s32 port) {
    return IsKeyDown(CONTROLLER_RSTICK_UP);
}
bool isPadTriggerDownRightStick(s32 port) {
    return IsKeyDown(CONTROLLER_RSTICK_DOWN);
}
bool isPadTriggerLeftRightStick(s32 port) {
    return IsKeyDown(CONTROLLER_RSTICK_LEFT);
}
bool isPadTriggerRightRightStick(s32 port) {
    return IsKeyDown(CONTROLLER_RSTICK_RIGHT);
}
bool isPadTriggerAnyABXY(s32 port) {
    return isPadTriggerA(port) || isPadTriggerB(port) || isPadTriggerX(port) || isPadTriggerY(port);
}
bool isPadTriggerAny(s32 port) {
    CRASH
}
bool isPadTriggerLeftStick(s32 port) {
    CRASH
}
bool isPadTriggerRightStick(s32 port) {
    CRASH
}
bool isPadTriggerPressLeftStick(s32 port) {
    return isPadTrigger1(port);
}
bool isPadTriggerPressRightStick(s32 port) {
    return isPadTrigger2(port);
}

bool isPadRepeat(s32 port, s32 button) {
    return getController(port)->isTrigWithRepeat(button);
}
bool isPadRepeatA(s32 port) {
    return isPadRepeat(port, 1);
}
bool isPadRepeatB(s32 port) {
    return isPadRepeat(port, 1 << 1);
}
bool isPadRepeatX(s32 port) {
    return isPadRepeat(port, 1 << 3);
}
bool isPadRepeatY(s32 port) {
    return isPadRepeat(port, 1 << 4);
}
bool isPadRepeatZL(s32 port) {
    return isPadRepeat(port, 1 << 2);
}
bool isPadRepeatZR(s32 port) {
    return isPadRepeat(port, 1 << 5);
}
bool isPadRepeatL(s32 port) {
    return isPadRepeat(port, 1 << 13);
}
bool isPadRepeatR(s32 port) {
    return isPadRepeat(port, 1 << 14);
}
bool isPadRepeat1(s32 port) {
    return isPadRepeat(port, 1 << 7);
}
bool isPadRepeat2(s32 port) {
    return isPadRepeat(port, 1 << 6);
}
bool isPadRepeatUp(s32 port) {
    return isPadRepeat(port, 1 << 16);
}
bool isPadRepeatDown(s32 port) {
    return isPadRepeat(port, 1 << 17);
}
bool isPadRepeatLeft(s32 port) {
    return isPadRepeat(port, 1 << 18);
}
bool isPadRepeatRight(s32 port) {
    return isPadRepeat(port, 1 << 19);
}
bool isPadRepeatHome(s32 port) {
    return isPadRepeat(port, 1 << 8);
}
bool isPadRepeatStart(s32 port) {
    return isPadRepeat(port, 1 << 11);
}
bool isPadRepeatSelect(s32 port) {
    return isPadRepeat(port, 1 << 12);
}
bool isPadRepeatPlus(s32 port) {
    return isPadRepeat(port, 1 << 10);
}
bool isPadRepeatMinus(s32 port) {
    return isPadRepeat(port, 1 << 9);
}
bool isPadRepeatTouch() {
    return isPadRepeat(getTouchPanelPort(), 1 << 15);
}
bool isPadRepeatUpLeftStick(s32 port) {
    return isPadRepeat(port, 1 << 20);
}
bool isPadRepeatDownLeftStick(s32 port) {
    return isPadRepeat(port, 1 << 21);
}
bool isPadRepeatLeftLeftStick(s32 port) {
    return isPadRepeat(port, 1 << 22);
}
bool isPadRepeatRightLeftStick(s32 port) {
    return isPadRepeat(port, 1 << 23);
}
bool isPadRepeatUpRightStick(s32 port) {
    return isPadRepeat(port, 1 << 24);
}
bool isPadRepeatDownRightStick(s32 port) {
    return isPadRepeat(port, 1 << 25);
}
bool isPadRepeatLeftRightStick(s32 port) {
    return isPadRepeat(port, 1 << 26);
}
bool isPadRepeatRightRightStick(s32 port) {
    return isPadRepeat(port, 1 << 27);
}

bool isPadHoldPressLeftStick(s32 port) {
    return isPadHold1(port);
}
bool isPadHoldPressRightStick(s32 port) {
    return isPadHold2(port);
}
bool isPadHold(s32 port, s32 button) {
    return getController(port)->isHold(button);
}
bool isPadHoldA(s32 port) {
    return isPadHold(port, 1);
}
bool isPadHoldB(s32 port) {
    return isPadHold(port, 1 << 1);
}
bool isPadHoldX(s32 port) {
    return isPadHold(port, 1 << 3);
}
bool isPadHoldY(s32 port) {
    return isPadHold(port, 1 << 4);
}
bool isPadHoldZL(s32 port) {
    return isPadHold(port, 1 << 2);
}
bool isPadHoldZR(s32 port) {
    return isPadHold(port, 1 << 5);
}
bool isPadHoldL(s32 port) {
    return isPadHold(port, 1 << 13);
}
bool isPadHoldR(s32 port) {
    return isPadHold(port, 1 << 14);
}
bool isPadHold1(s32 port) {
    return isPadHold(port, 1 << 7);
}
bool isPadHold2(s32 port) {
    return isPadHold(port, 1 << 6);
}
bool isPadHoldUp(s32 port) {
    return isPadHold(port, 1 << 16);
}
bool isPadHoldDown(s32 port) {
    return isPadHold(port, 1 << 17);
}
bool isPadHoldLeft(s32 port) {
    return isPadHold(port, 1 << 18);
}
bool isPadHoldRight(s32 port) {
    return isPadHold(port, 1 << 19);
}
bool isPadHoldLeftUp(s32 port) {
    return getController(port)->isHoldAll(0x50000);
}
bool isPadHoldLeftDown(s32 port) {
    return getController(port)->isHoldAll(0x60000);
}
bool isPadHoldRightUp(s32 port) {
    return getController(port)->isHoldAll(0x90000);
}
bool isPadHoldRightDown(s32 port) {
    return getController(port)->isHoldAll(0xA0000);
}
bool isPadHoldHome(s32 port) {
    return isPadHold(port, 1 << 8);
}
bool isPadHoldStart(s32 port) {
    return isPadHold(port, 1 << 11);
}
bool isPadHoldSelect(s32 port) {
    return isPadHold(port, 1 << 12);
}
bool isPadHoldPlus(s32 port) {
    return isPadHold(port, 1 << 10);
}
bool isPadHoldMinus(s32 port) {
    return isPadHold(port, 1 << 9);
}
bool isPadHoldAny(s32 port) {
    return isPadHold(port, 0xFFF7FFF);
}
bool isPadHoldAnyWithoutStick(s32 port) {
    return isPadHold(port, 0xF7FFF);
}
bool isPadHoldTouch() {
    return isPadHold(getTouchPanelPort(), 1 << 15);
}
bool isPadHoldUpLeftStick(s32 port) {
    return isPadHold(port, 1 << 20);
}
bool isPadHoldDownLeftStick(s32 port) {
    return isPadHold(port, 1 << 21);
}
bool isPadHoldLeftLeftStick(s32 port) {
    return isPadHold(port, 1 << 22);
}
bool isPadHoldRightLeftStick(s32 port) {
    return isPadHold(port, 1 << 23);
}
bool isPadHoldUpRightStick(s32 port) {
    return isPadHold(port, 1 << 24);
}
bool isPadHoldDownRightStick(s32 port) {
    return isPadHold(port, 1 << 25);
}
bool isPadHoldLeftRightStick(s32 port) {
    return isPadHold(port, 1 << 26);
}
bool isPadHoldRightRightStick(s32 port) {
    return isPadHold(port, 1 << 27);
}
bool isPadHoldLeftStick(s32 port) {
    return isPadHold(port, 0xF00000);
}
bool isPadHoldRightStick(s32 port) {
    return isPadHold(port, 0xF000000);
}

bool isPadRelease(s32 port, s32 button) {
    return getController(port)->isRelease(button);
}
bool isPadReleaseA(s32 port) {
    return isPadRelease(port, 1);
}
bool isPadReleaseB(s32 port) {
    return isPadRelease(port, 1 << 1);
}
bool isPadReleaseX(s32 port) {
    return isPadRelease(port, 1 << 3);
}
bool isPadReleaseY(s32 port) {
    return isPadRelease(port, 1 << 4);
}
bool isPadReleaseZL(s32 port) {
    return isPadRelease(port, 1 << 2);
}
bool isPadReleaseZR(s32 port) {
    return isPadRelease(port, 1 << 5);
}
bool isPadReleaseL(s32 port) {
    return isPadRelease(port, 1 << 13);
}
bool isPadReleaseR(s32 port) {
    return isPadRelease(port, 1 << 14);
}
bool isPadRelease1(s32 port) {
    return isPadRelease(port, 1 << 7);
}
bool isPadRelease2(s32 port) {
    return isPadRelease(port, 1 << 6);
}
bool isPadReleaseUp(s32 port) {
    return isPadRelease(port, 1 << 16);
}
bool isPadReleaseDown(s32 port) {
    return isPadRelease(port, 1 << 17);
}
bool isPadReleaseLeft(s32 port) {
    return isPadRelease(port, 1 << 18);
}
bool isPadReleaseRight(s32 port) {
    return isPadRelease(port, 1 << 19);
}
bool isPadReleaseHome(s32 port) {
    return isPadRelease(port, 1 << 8);
}
bool isPadReleaseStart(s32 port) {
    return isPadRelease(port, 1 << 11);
}
bool isPadReleaseSelect(s32 port) {
    return isPadRelease(port, 1 << 12);
}
bool isPadReleasePlus(s32 port) {
    return isPadRelease(port, 1 << 10);
}
bool isPadReleaseMinus(s32 port) {
    return isPadRelease(port, 1 << 9);
}
bool isPadReleaseTouch() {
    return isPadRelease(getTouchPanelPort(), 1 << 15);
}
bool isPadReleaseUpLeftStick(s32 port) {
    return isPadRelease(port, 1 << 20);
}
bool isPadReleaseDownLeftStick(s32 port) {
    return isPadRelease(port, 1 << 21);
}
bool isPadReleaseLeftLeftStick(s32 port) {
    return isPadRelease(port, 1 << 22);
}
bool isPadReleaseRightLeftStick(s32 port) {
    return isPadRelease(port, 1 << 23);
}
bool isPadReleaseUpRightStick(s32 port) {
    return isPadRelease(port, 1 << 24);
}
bool isPadReleaseDownRightStick(s32 port) {
    return isPadRelease(port, 1 << 25);
}
bool isPadReleaseLeftRightStick(s32 port) {
    return isPadRelease(port, 1 << 26);
}
bool isPadReleaseRightRightStick(s32 port) {
    return isPadRelease(port, 1 << 27);
}

const sead::Vector2f& getLeftStick(s32 port) {
    return getController(port)->getLeftStick();
}
const sead::Vector2f& getRightStick(s32 port) {
    return getController(port)->getRightStick();
}

void getPadCrossDir(sead::Vector2f* vec, s32 port) {
    vec->x = 0;
    vec->y = 0;
    if (isPadHoldUp(port))
        vec->y = 1;
    if (isPadHoldDown(port))
        vec->y = -1;
    if (isPadHoldLeft(port))
        vec->x = -1;
    if (isPadHoldRight(port))
        vec->x = 1;
}
void getPadCrossDirSideways(sead::Vector2f* vec, s32 port) {
    vec->x = 0;
    vec->y = 0;
    if (isPadHoldUp(port))
        vec->x = -1;
    if (isPadHoldDown(port))
        vec->x = 1;
    if (isPadHoldLeft(port))
        vec->y = -1;
    if (isPadHoldRight(port))
        vec->y = 1;
}

#ifdef NON_MATCHING
void calcTouchScreenPos(sead::Vector2f* vec) {
    *vec = getController(getTouchPanelPort())->getPointer();  // uses w8 for storage instead and
                                                              // inserts another write at +4 bytes
}
#endif

void calcTouchLayoutPos(sead::Vector2f*) {}

bool isTouchPosInRect(const sead::Vector2f& rect_pos, const sead::Vector2f& size) {
    sead::Vector2f pos;
    calcTouchScreenPos(&pos);

    if (rect_pos.x > pos.x)
        return false;
    if (pos.x >= (rect_pos.x + size.x))
        return false;
    if (rect_pos.y > pos.y)
        return false;
    if (pos.y > rect_pos.y + size.y)
        return false;

    return true;
}

void setPadRepeat(s32 a1, s32 a2, s32 a3, s32 port) {
    getController(port)->setPadRepeat(a1, a2, a3);
}

s32 getPlayerControllerPort(s32 playerNo) {
    auto* manager = sead::ControllerMgr::instance();
    sead::Controller* controller =
        manager->getControllerByOrder(sead::ControllerDefine::ControllerId::_15, playerNo);
    return manager->findControllerPort(controller);
}
s32 getTouchPanelPort() {
    auto* manager = sead::ControllerMgr::instance();
    sead::Controller* controller =
        manager->getControllerByOrder(sead::ControllerDefine::ControllerId::_16, 0);
    return manager->findControllerPort(controller);
}
s32 getMainControllerPort() {
    return getPlayerControllerPort(0);
}
s32 getMainJoyPadDoublePort() {
    return getMainControllerPort();
}
s32 getMainJoyPadSingleRightPort() {
    return 1;
}
s32 getMainJoyPadSingleLeftPort() {
    return 2;
}

}  // namespace al
