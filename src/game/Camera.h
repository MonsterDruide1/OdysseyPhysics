#pragma once

#include <math/seadVector.h>
#include "Library/Math/MathUtil.h"
#include "gfx/seadCamera.h"
#include "math/seadMatrix.h"
#include "math/seadVectorFwd.h"

namespace game {

class Camera {
public:
    f32 calcZoneRotAngleH(f32 val) {
        f32 v2 = sead::Mathf::deg2rad(val);
        f32 v4 = sead::Mathf::sin(v2);
        f32 v5 = sead::Mathf::cos(v2);
        return sead::Mathf::rad2deg(sead::Mathf::atan2(v4, v5));
    }
    void setup(float angleH, float angleV, float distance, sead::Vector3f lookAtPos) {
        f32 v20 = sead::Mathf::deg2rad(calcZoneRotAngleH(angleH));
        sead::Vector3f v37 = {
            sead::Mathf::sin(v20) * sead::Mathf::cos(sead::Mathf::deg2rad(angleV)),
            sead::Mathf::sin(sead::Mathf::deg2rad(angleV)),
            sead::Mathf::cos(v20) * sead::Mathf::cos(sead::Mathf::deg2rad(angleV))
        };
        al::normalize(&v37);
        sead::Vector3f pos = v37 * distance + lookAtPos;
        mCamera = sead::LookAtCamera(pos, lookAtPos, {0, 1, 0});
        mCamera.doUpdateMatrix(&mCamera.getMatrix());
    }

    sead::Vector3f position() { return mCamera.getPos(); }

    sead::Vector3f up() { return mCamera.getUp(); }

    sead::Vector3f at() { return mCamera.getAt(); }

    const sead::Matrix34f* getViewMtxPtr() { return &mCamera.getMatrix(); }

public:
    sead::LookAtCamera mCamera;
};

}  // namespace game
