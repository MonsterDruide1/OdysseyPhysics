#include "Library/Nerve/NerveKeeper.h"
#include "Library/Nerve/NerveStateCtrl.h"
#include "Player/CollisionShapeInfo.h"
#include "Player/CollisionShapeKeeper.h"
#include "Player/PlayerActorHakoniwa.h"
#include "Player/PlayerCollider.h"
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
#include "rlgl.h"
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
                    CollisionShapeKeeper* collisionShapeKeeper = ((PlayerActorHakoniwa*)scene->mPlayer->mActor)->getPlayerCollision()->getPlayerCollider()->mCollisionShapeKeeper;
                    for(int i=0; i<collisionShapeKeeper->mCollisionShape.size(); i++) {
                        auto shape = collisionShapeKeeper->mCollisionShape[i];
                        if(shape->getId() == CollisionShapeId::Arrow) {
                            auto arrow = (CollisionShapeInfoArrow*)shape;
                            sead::Vector3f startOrig = arrow->a3;
                            sead::Vector3f endOrig = arrow->a4;
                            sead::Vector3f start,end;
                            start.setMul(mtx, startOrig);
                            end.setMul(mtx, endOrig);
                            start *= SCALE;
                            end *= SCALE;
                            rlPushMatrix();
                                DrawLine3D(raylibVec(start), raylibVec(end), RED);
                            rlPopMatrix();
                        }
                        else if(shape->getId() == CollisionShapeId::Sphere) {
                            auto sphere = (CollisionShapeInfoSphere*)shape;
                            sead::Vector3f center = sphere->mBoundingCenter * SCALE;
                            sphereModel.transform = raylibMtx(mtx);
                            DrawModel(sphereModel, raylibVec(center), SCALE, RED);
                        }
                        else {
                            printf("Unknown shape type: %d\n", (int)shape->getId());
                            CRASH
                        }
                    }
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
