#include "Library/Nerve/NerveKeeper.h"
#include "Library/Nerve/NerveStateCtrl.h"
#include "game/RaylibActor.h"
#include "Player/PlayerColliderHakoniwa.h"
#include "game/StageScene.h"
#include "game/StageSceneManager.h"
#include "heap/ClonableExpHeap.h"
#include "math/seadMatrix.h"
#include "nlib/types.h"
#include "nlib/util.h"
#include "oead/sarc.h"
#include "oead/yaz0.h"
#include "raylib.h"
#include "raymath.h"
#include "rcamera.h"
#include "seadInterface.h"
#include "types.h"
#include "ui/RaylibUtil.h"
#include <filesystem>
#include <vector>

#include "Library/Base/StringUtil.h"
#include "Library/Camera/CameraPoserFunction.h"

#define SCALE 0.005f

int main() {
    SetTraceLogLevel(LOG_NONE);
    InitWindow(1920, 1080, "TAS Client");
    SetTargetFPS(60);
    //DisableCursor();

    setupRaylibUtil();
    initializeSead();
    {
        // context of sead

        
        game::StageSceneManager sceneManager{};
        game::StageScene* scene = sceneManager.getScene();
        //scene.init("SandWorldSlotStageMap", 0);
        sceneManager.init("SandWorldMeganeExStageMap", 0);

        Camera3D cam = {0};
        cam.position = raylibVec(scene->mCamera->position() * SCALE);
        cam.target = raylibVec(scene->mCamera->lookAtPos * SCALE);
        cam.up = raylibVec(scene->mCamera->up());
        cam.fovy = 45;
        cam.projection = CAMERA_PERSPECTIVE;

        sead::ClonableExpHeap* prevHeap = sceneManager.mHeap->clone();

        int cameraDirLoc = GetShaderLocation(checkerShader, "cameraDirection");
        while (!WindowShouldClose()) {

            printf("----------------------------\n");

            if(IsKeyPressed(KEY_P)) {
                sead::ClonableExpHeap* currentHeap = sceneManager.mHeap;
                sceneManager.mHeap = prevHeap;
                prevHeap = currentHeap;
            }
            scene = sceneManager.getScene();

            scene->update();

            //UpdateCamera(&cam, CAMERA_FREE);

            sead::Vector3f cameraDir = (seadVec(cam.target) - seadVec(cam.position));
            cameraDir.normalize();

            BeginDrawing();
            {
                ClearBackground(BLACK);
                BeginMode3D(cam);

                SetShaderValue(checkerShader, cameraDirLoc, &cameraDir, SHADER_UNIFORM_VEC3);

                for (int i=0; i<scene->mActorsNum; i++) {
                    auto actor = scene->mActors[i];
                    if (!actor)
                        continue;

                    sead::Matrix34f mtx;
                    actor->mActor->mPoseKeeper->calcBaseMtx(&mtx);
                    actor->raylibModel.transform = raylibMtx(mtx);
                    DrawModel(actor->raylibModel, {0,0,0}, SCALE, WHITE);
                }

                {
                    sead::Matrix34f mtx;
                    scene->mPlayer->mActor->mPoseKeeper->calcBaseMtx(&mtx);
                    scene->mPlayer->raylibModel.transform = raylibMtx(mtx);
                    DrawModel(scene->mPlayer->raylibModel, {0,0,0}, SCALE, WHITE);
                }

                EndMode3D();

                DrawText(scene->mPlayer->mActor->mNerveKeeper->getStateCtrl()->findStateInfo(scene->mPlayer->mActor->mNerveKeeper->getCurrentNerve())->name,
                    0, 0, 40,  {255, 0, 0, 255});
            }
            EndDrawing();
        }

    }
    unloadSead();
    unloadRaylibUtil();

    CloseWindow();
    

    printf("Exiting...\n");
    return 0;
}
