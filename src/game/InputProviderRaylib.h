#pragma once

#include "game/Input.h"
#include "prim/seadBitFlag.h"
#include "raylib.h"

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

class InputProviderRaylib : public InputProvider {
public:
    sead::BitFlag32 getButtons() override {
        sead::BitFlag32 buttons = 0;
        if (IsKeyDown(CONTROLLER_A))
            buttons.setBit(ControllerButton_A);
        if (IsKeyDown(CONTROLLER_B))
            buttons.setBit(ControllerButton_B);
        if (IsKeyDown(CONTROLLER_X))
            buttons.setBit(ControllerButton_X);
        if (IsKeyDown(CONTROLLER_Y))
            buttons.setBit(ControllerButton_Y);
        if (IsKeyDown(CONTROLLER_ZL))
            buttons.setBit(ControllerButton_C);
        if (IsKeyDown(CONTROLLER_ZR))
            buttons.setBit(ControllerButton_Z);
        if (IsKeyDown(CONTROLLER_L))
            buttons.setBit(ControllerButton_L);
        if (IsKeyDown(CONTROLLER_R))
            buttons.setBit(ControllerButton_R);
        if (IsKeyDown(CONTROLLER_UP))
            buttons.setBit(ControllerButton_Up);
        if (IsKeyDown(CONTROLLER_DOWN))
            buttons.setBit(ControllerButton_Down);
        if (IsKeyDown(CONTROLLER_LEFT))
            buttons.setBit(ControllerButton_Left);
        if (IsKeyDown(CONTROLLER_RIGHT))
            buttons.setBit(ControllerButton_Right);
        if (IsKeyDown(CONTROLLER_PLUS))
            buttons.setBit(ControllerButton_Plus);
        if (IsKeyDown(CONTROLLER_MINUS))
            buttons.setBit(ControllerButton_Minus);
        return buttons;
    }

    sead::Vector2f getStickLeft() override {
        sead::Vector2f stick = sead::Vector2f::zero;
        if (IsKeyDown(KEY_W))
            stick.y = 1;
        if (IsKeyDown(KEY_S))
            stick.y = -1;
        if (IsKeyDown(KEY_A))
            stick.x = -1;
        if (IsKeyDown(KEY_D))
            stick.x = 1;
        if (stick.squaredLength() > 1)
            stick.normalize();
        return stick;
    }

    sead::Vector2f getStickRight() override {
        sead::Vector2f stick = sead::Vector2f::zero;
        if (IsKeyDown(KEY_I))
            stick.y = 1;
        if (IsKeyDown(KEY_K))
            stick.y = -1;
        if (IsKeyDown(KEY_J))
            stick.x = -1;
        if (IsKeyDown(KEY_L))
            stick.x = 1;
        if (stick.squaredLength() > 1)
            stick.normalize();
        return stick;
    }
};
