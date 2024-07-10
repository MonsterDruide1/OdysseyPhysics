#pragma once

#include <raylib.h>
#include "math/seadQuat.h"

extern Mesh cubeMesh;
extern Model cubeModel;
extern Mesh sphereMesh;
extern Model sphereModel;
extern Shader checkerShader;

void setupRaylibUtil();
void unloadRaylibUtil();

inline Quaternion raylibQuat(sead::Quatf quat) {
    return {quat.x, quat.y, quat.z, quat.w};
}
inline Vector3 raylibVec(sead::Vector3f vec) {
    return {vec.x, vec.y, vec.z};
}
inline Matrix raylibMtx(sead::Matrix34f mtx) {
    return {mtx.m[0][0], mtx.m[0][1], mtx.m[0][2], mtx.m[0][3],
            mtx.m[1][0], mtx.m[1][1], mtx.m[1][2], mtx.m[1][3],
            mtx.m[2][0], mtx.m[2][1], mtx.m[2][2], mtx.m[2][3],
            0,           0,           0,           1};
}

inline sead::Vector3f seadVec(Vector3 raylib) {
    return {raylib.x, raylib.y, raylib.z};
}
