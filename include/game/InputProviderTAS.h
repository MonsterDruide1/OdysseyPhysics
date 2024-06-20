#pragma once

#include <fstream>
#include "container/seadTList.h"
#include "game/Input.h"
#include "prim/seadBitFlag.h"

using TASFrame = FrameInput;

class InputProviderTAS : public InputProvider {
public:
    InputProviderTAS(const char* path) {
        std::ifstream file(path);

        // lines formatted like this: "30 KEY_A;KEY_B;KEY_Y 18000;-3000 1234;8753"
        // purpose: "FRAME_ID BUTTONS STICK_LEFT STICK_RIGHT"
        while (!file.eof()) {
            TASFrame frame;
            int frameId;
            char buttons[64];
            int stickLeftX, stickLeftY;
            int stickRightX, stickRightY;

            file >> frameId;
            file.ignore(1);
            file.getline(buttons, 64, ' ');
            file >> stickLeftX;
            file.ignore(1);
            file >> stickLeftY;
            file.ignore(1);
            file >> stickRightX;
            file.ignore(1);
            file >> stickRightY;

            frame.buttons = 0;
            char* button = strtok(buttons, ";");
            while (button) {
                if (strcmp(button, "KEY_A") == 0) frame.buttons.setBit(ControllerButton_A);
                if (strcmp(button, "KEY_B") == 0) frame.buttons.setBit(ControllerButton_B);
                if (strcmp(button, "KEY_X") == 0) frame.buttons.setBit(ControllerButton_X);
                if (strcmp(button, "KEY_Y") == 0) frame.buttons.setBit(ControllerButton_Y);
                if (strcmp(button, "KEY_ZL") == 0) frame.buttons.setBit(ControllerButton_C);
                if (strcmp(button, "KEY_ZR") == 0) frame.buttons.setBit(ControllerButton_Z);
                if (strcmp(button, "KEY_L") == 0) frame.buttons.setBit(ControllerButton_L);
                if (strcmp(button, "KEY_R") == 0) frame.buttons.setBit(ControllerButton_R);
                if (strcmp(button, "KEY_UP") == 0) frame.buttons.setBit(ControllerButton_Up);
                if (strcmp(button, "KEY_DOWN") == 0) frame.buttons.setBit(ControllerButton_Down);
                if (strcmp(button, "KEY_LEFT") == 0) frame.buttons.setBit(ControllerButton_Left);
                if (strcmp(button, "KEY_RIGHT") == 0) frame.buttons.setBit(ControllerButton_Right);
                if (strcmp(button, "KEY_PLUS") == 0) frame.buttons.setBit(ControllerButton_Plus);
                if (strcmp(button, "KEY_MINUS") == 0) frame.buttons.setBit(ControllerButton_Minus);
                button = strtok(nullptr, ";");
            }

            frame.stickLeft = sead::Vector2f(stickLeftX / 32767.0f, stickLeftY / 32767.0f);
            frame.stickRight = sead::Vector2f(stickRightX / 32767.0f, stickRightY / 32767.0f);

            auto node = new sead::TListNode<TASFrame>(frame);
            mFrames.pushBack(node);
        }
    }

    void update() override {
        if (!mPlaying) return;

        ++mCurrentFrame;

        if (mCurrentFrame >= mFrames.size())
            mPlaying = false;
    }

    sead::BitFlag32 getButtons() override {
        if(!mPlaying) return sead::BitFlag32();
        return mFrames.nth(mCurrentFrame)->mData.buttons;
    }

    sead::Vector2f getStickLeft() override {
        if(!mPlaying) return sead::Vector2f(0, 0);
        return mFrames.nth(mCurrentFrame)->mData.stickLeft;
    }

    sead::Vector2f getStickRight() override {
        if(!mPlaying) return sead::Vector2f(0, 0);
        return mFrames.nth(mCurrentFrame)->mData.stickRight;
    }

private:
    sead::TList<TASFrame> mFrames = {};
    int mCurrentFrame = 0;
    bool mPlaying = true;
};
