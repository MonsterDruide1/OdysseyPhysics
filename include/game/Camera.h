#pragma once

#include <math/seadVector.h>
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
        sead::Vector3f rot = {
            sead::Mathf::deg2rad(0.0f+angleV),
            sead::Mathf::deg2rad(-90.0f - angleH),
            0
        };
        mMtx.makeRT(rot, pos);
        mDistance = distance;
    }

    sead::Vector3f position() {
        sead::Vector3f pos;
        mMtx.getTranslation(pos);
        return pos;
    }

    sead::Vector3f up() {
        sead::Vector3f up = {0, 1, 0};
        up.rotate(mMtx);
        up.normalize();
        return up;
    }

    sead::Vector3f front() {
        sead::Vector3f front = {0, 0, 1};
        front.rotate(mMtx);
        front.normalize();
        return front;
    }

    const sead::Matrix34f* getViewMtxPtr() {
        return &mMtx;
    }

public:
    sead::Matrix34f mMtx;
    f32 mDistance;
};

}
