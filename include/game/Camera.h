#pragma once

#include <math/seadVector.h>
#include "gfx/seadCamera.h"
#include "math/seadMatrix.h"
#include "math/seadVectorFwd.h"

namespace game {

class Camera {
public:
    void setup(float angleH, float angleV, float distance, sead::Vector3f lookAtPos) {
        sead::Vector3f pos = {
            lookAtPos.x + distance * cosf(angleH * M_PI / 180) * cosf(angleV * M_PI / 180),
            lookAtPos.y + distance * sinf(angleV * M_PI / 180),
            lookAtPos.z + distance * sinf(angleH * M_PI / 180) * cosf(angleV * M_PI / 180)
        };
        mCamera = sead::LookAtCamera(pos, lookAtPos, {0, 1, 0});
        mCamera.doUpdateMatrix(&mCamera.getMatrix());
    }

    sead::Vector3f position() {
        return mCamera.getPos();
    }

    sead::Vector3f up() {
        return mCamera.getUp();
    }

    sead::Vector3f at() {
        return mCamera.getAt();
    }

    const sead::Matrix34f* getViewMtxPtr() {
        return &mCamera.getMatrix();
    }

public:
    sead::LookAtCamera mCamera;
};

}
