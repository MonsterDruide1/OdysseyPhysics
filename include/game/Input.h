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


class InputProvider {
public:
    virtual sead::BitFlag32 getButtons() = 0;
    virtual sead::Vector3f getStickLeft() = 0;
    virtual sead::Vector3f getStickRight() = 0;
};

class Input {
public:
    static Input* instance() {
        static Input sInstance;
        return &sInstance;
    }

    void setInputProvider(InputProvider* provider) { mProvider = provider; }

    void update() {
        mPrevButtons = mButtons;
        if (!mProvider) {
            ((sead::BitFlag32*)&mButtons)->makeAllZero();
            mStickLeft = sead::Vector3f::zero;
            mStickRight = sead::Vector3f::zero;
            return;
        }
        mButtons = mProvider->getButtons();
        mStickLeft = mProvider->getStickLeft();
        mStickRight = mProvider->getStickRight();
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
        return ((sead::BitFlag32*)&mButtons)->isOn(button) &&
               ((sead::BitFlag32*)&mPrevButtons)->isOn(button);
    }

    bool isRepeat(int button) {
        return isHold(button);  // what's the difference?
    }

private:
    sead::BitFlag32 mButtons = {};
    sead::Vector3f mStickLeft = sead::Vector3f::zero;
    sead::Vector3f mStickRight = sead::Vector3f::zero;

    sead::BitFlag32 mPrevButtons = {};
    InputProvider* mProvider = nullptr;
};
