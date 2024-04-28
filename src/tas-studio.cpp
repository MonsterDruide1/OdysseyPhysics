#include "file/KCollision.h"
#include "game/StageScene.h"
#include "math/seadMatrix.h"
#include "nlib/types.h"
#include "nlib/util.h"
#include "oead/sarc.h"
#include "oead/yaz0.h"
#include "raylib.h"
#include "raymath.h"
#include "rcamera.h"
#include "types.h"
#include "ui/RaylibUtil.h"
#include <filesystem>
#include <vector>

#include "Library/Base/String.h"
#include "Library/Camera/CameraPoserFunction.h"

#define SCALE 0.005f

int main() {
    SetTraceLogLevel(LOG_NONE);
    InitWindow(1920, 1080, "TAS Client");
    SetTargetFPS(60);
    //DisableCursor();

    game::checkerShader = LoadShader("res/shaders/normal.vs", "res/shaders/normal.fs");
    game::cubeMesh = GenMeshCube(50, 50, 50);
    game::StageScene scene{};
    scene.init("SandWorldMeganeExStageMap", 0);

    Camera3D cam = {0};
    cam.position = {0, 0, 0};
    cam.target = {0, 0, 1};
    cam.up = {0, 1, 0};
    cam.fovy = 45;
    cam.projection = CAMERA_PERSPECTIVE;

    int cameraDirLoc = GetShaderLocation(game::checkerShader, "cameraDirection");
    while (!WindowShouldClose()) {

        UpdateCamera(&cam, CAMERA_FREE);

        sead::Vector3f cameraDir = (seadVec(cam.target) - seadVec(cam.position));
        cameraDir.normalize();

        BeginDrawing();
        {
            ClearBackground(BLACK);
            BeginMode3D(cam);

            SetShaderValue(game::checkerShader, cameraDirLoc, &cameraDir, SHADER_UNIFORM_VEC3);

            for (int i=0; i<scene.mActorsNum; i++) {
                auto actor = scene.mActors[i];
                if (!actor)
                    continue;

                sead::Matrix34f mtx;
                actor->mPoseKeeper->calcBaseMtx(&mtx);
                actor->raylibModel.transform = raylibMtx(mtx);
                DrawModel(actor->raylibModel, {0,0,0}, SCALE, WHITE);
            }

            {
                sead::Matrix34f mtx;
                scene.mPlayer->mPoseKeeper->calcBaseMtx(&mtx);
                scene.mPlayer->raylibModel.transform = raylibMtx(mtx);
                DrawModel(scene.mPlayer->raylibModel, {0,0,0}, SCALE, WHITE);
            }

            EndMode3D();
        }
        EndDrawing();
    }

    return 0;
}
