#include "game/Input.h"
#include <fstream>
#include <sstream>

Input* Input::sInstance;

void Input::dumpToTASFile(const char* filename) {
    std::ofstream file(filename);

    // format: `FRAME_ID BUTTONS STICK_LEFT STICK_RIGHT`
    // example: `30 KEY_A;KEY_B 18000;-3000 1234;8753`
    // if no button is set, use `NONE` instead
    // do not use trailing semicolon for buttons
    for (int i = 0; i < mInputCount; i++) {
        auto& input = mInputs[i];
        file << i << ' ';

        if (input.buttons == 0) {
            file << "NONE";
        } else {
            std::stringstream buttons;
            if (input.buttons.isOnBit(ControllerButton_A))
                buttons << "KEY_A;";
            if (input.buttons.isOnBit(ControllerButton_B))
                buttons << "KEY_B;";
            if (input.buttons.isOnBit(ControllerButton_X))
                buttons << "KEY_X;";
            if (input.buttons.isOnBit(ControllerButton_Y))
                buttons << "KEY_Y;";
            if (input.buttons.isOnBit(ControllerButton_C))
                buttons << "KEY_ZL;";
            if (input.buttons.isOnBit(ControllerButton_Z))
                buttons << "KEY_ZR;";
            if (input.buttons.isOnBit(ControllerButton_L))
                buttons << "KEY_L;";
            if (input.buttons.isOnBit(ControllerButton_R))
                buttons << "KEY_R;";
            if (input.buttons.isOnBit(ControllerButton_Up))
                buttons << "KEY_UP;";
            if (input.buttons.isOnBit(ControllerButton_Down))
                buttons << "KEY_DOWN;";
            if (input.buttons.isOnBit(ControllerButton_Left))
                buttons << "KEY_LEFT;";
            if (input.buttons.isOnBit(ControllerButton_Right))
                buttons << "KEY_RIGHT;";
            if (input.buttons.isOnBit(ControllerButton_Plus))
                buttons << "KEY_PLUS;";
            if (input.buttons.isOnBit(ControllerButton_Minus))
                buttons << "KEY_MINUS;";

            std::string buttonsStr = buttons.str();
            buttonsStr.pop_back();
            file << buttonsStr;
        }

        file << ' ' << (int)(input.stickLeft.x * 32767) << ';' << (int)(input.stickLeft.y * 32767);
        file << ' ' << (int)(input.stickRight.x * 32767) << ';' << (int)(input.stickRight.y * 32767)
             << '\n';
    }
}
