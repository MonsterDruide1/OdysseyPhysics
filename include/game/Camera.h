#pragma once

#include <math/seadVector.h>
#include "math/seadMatrix.h"

namespace game {

class Camera {
public:
    sead::Vector3f position() {
        sead::Vector3f pos;
        pos.x = lookAtPos.x + distance * cosf(angleH * M_PI / 180) * cosf(angleV * M_PI / 180);
        pos.y = lookAtPos.y + distance * sinf(angleV * M_PI / 180);
        pos.z = lookAtPos.z + distance * sinf(angleH * M_PI / 180) * cosf(angleV * M_PI / 180);
        return pos;
    }

    sead::Vector3f up() {
        return {0, 1, 0};
    }

    const sead::Matrix34f* getViewMtxPtr() {
        WARN_UNIMPL;
        return &sead::Matrix34f::ident;
    }

public:
    float angleH = 90;
    float angleV = 60;
    float distance = 3000;
    sead::Vector3f lookAtPos = {-250, 300, 1500};  // room 1
    //sead::Vector3f lookAtPos = {-3050, 300, 1500};  // room 2
    //sead::Vector3f lookAtPos = {-5850, 300, 1500};  // room 3

    /*float angleH = 90;
    float angleV = 30;
    float distance = 1800;
    sead::Vector3f lookAtPos = {0, 250, -150};*/

};

}
