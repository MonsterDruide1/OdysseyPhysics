#pragma once

#include <math/seadVector.h>
#include "prim/seadBitFlag.h"

enum ControllerButton : u32 {
    ControllerButton_A,
    ControllerButton_B,
    ControllerButton_C,
    ControllerButton_X,
    ControllerButton_Y,
    ControllerButton_Z,
    ControllerButton_2,
    ControllerButton_1,
    ControllerButton_Home,
    ControllerButton_Minus,
    ControllerButton_Plus,
    ControllerButton_Start,
    ControllerButton_Select,
    ControllerButton_L,
    ControllerButton_R,
    ControllerButton_Touch,
    ControllerButton_Up,
    ControllerButton_Down,
    ControllerButton_Left,
    ControllerButton_Right,
    ControllerButton_LeftStickUp,
    ControllerButton_LeftStickDown,
    ControllerButton_LeftStickLeft,
    ControllerButton_LeftStickRight,
    ControllerButton_RightStickUp,
    ControllerButton_RightStickDown,
    ControllerButton_RightStickLeft,
    ControllerButton_RightStickRight
};

struct FrameInput {
    sead::BitFlag32 buttons;
    sead::Vector2f stickLeft;
    sead::Vector2f stickRight;
};

class InputProvider {
public:
    virtual void update() {}

    virtual sead::BitFlag32 getButtons() = 0;
    virtual sead::Vector2f getStickLeft() = 0;
    virtual sead::Vector2f getStickRight() = 0;
};

// 10 minutes of 60fps
#define MAX_RECORDED_INPUTS 60 * 60 * 10

class Input {
public:
    void update() {
        mPrevButtons = mButtons;
        if (!mProvider) {
            ((sead::BitFlag32*)&mButtons)->makeAllZero();
            mStickLeft = sead::Vector2f::zero;
            mStickRight = sead::Vector2f::zero;
            return;
        }
        mProvider->update();
        mButtons = mProvider->getButtons();
        mStickLeft = mProvider->getStickLeft();
        mStickRight = mProvider->getStickRight();

        if (mInputCount >= MAX_RECORDED_INPUTS)
            return;
        mInputs[mInputCount].buttons = mButtons;
        mInputs[mInputCount].stickLeft = mStickLeft;
        mInputs[mInputCount].stickRight = mStickRight;
        mInputCount++;
    }

    bool isPress(int button) { return ((sead::BitFlag32*)&mButtons)->isOn(button); }

    bool isTrigger(int button) {
        return ((sead::BitFlag32*)&mButtons)->isOn(button) &&
               !((sead::BitFlag32*)&mPrevButtons)->isOn(button);
    }

    bool isRelease(int button) {
        return !((sead::BitFlag32*)&mButtons)->isOn(button) &&
               ((sead::BitFlag32*)&mPrevButtons)->isOn(button);
    }

    bool isHold(int button) {
        return ((sead::BitFlag32*)&mButtons)->isOn(button);
    }

    bool isRepeat(int button) {
        return isHold(button);  // what's the difference?
    }

    sead::Vector2f getStickLeft() { return mStickLeft; }

    sead::Vector2f getStickRight() { return mStickRight; }

    void setInputProvider(InputProvider* provider) { mProvider = provider; }

    void dumpToTASFile(const char* filename);

    static Input* instance() { return sInstance; }

    static void createInstance() { sInstance = new Input(); }

private:
    Input() { mInputs = new FrameInput[MAX_RECORDED_INPUTS]; }

    static Input* sInstance;

    sead::BitFlag32 mButtons = {};
    sead::Vector2f mStickLeft = sead::Vector2f::zero;
    sead::Vector2f mStickRight = sead::Vector2f::zero;

    sead::BitFlag32 mPrevButtons = {};
    InputProvider* mProvider = nullptr;

    FrameInput* mInputs = nullptr;
    int mInputCount = 0;
};
