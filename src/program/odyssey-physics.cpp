// ----------------------------------
// Easy configuration stuff
#define Stage "SandWorldMeganeExStageMap"
#define TASFile "res/beginner_recording.txt"
#define TASPlayback false
#define WSL_COMPATIBILITY false

// Testing modes
#define TEST_FPS_HEADLESS false
#define TEST_FPS_RAYLIB false
#define TEST_FRAMES 600000
#define TEST_AGENT false
#define TEST_AGENT_ITERATIONS 110000
// ----------------------------------


#include <filesystem>
#include <vector>
#include "CUSTOM/PlayerAnimator.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/Nerve/NerveKeeper.h"
#include "Library/Nerve/NerveStateCtrl.h"
#include "Player/CollisionShapeInfo.h"
#include "Player/CollisionShapeKeeper.h"
#include "Player/PlayerActorHakoniwa.h"
#include "Player/PlayerCollider.h"
#include "Player/PlayerColliderHakoniwa.h"
#include "RaylibUtil.h"
#include "game/Input.h"
#include "game/InputProviderRaylib.h"
#include "game/InputProviderTAS.h"
#include "game/RaylibActor.h"
#include "game/StageSceneManager.h"
#include "heap/ClonableExpHeap.h"
#include "math/seadMatrix.h"
#include "raylib.h"
#include "raymath.h"
#include "rcamera.h"
#include "rlgl.h"
#include "seadInterface.h"
#include "PlayerStateGym.h"

#include "Library/Base/StringUtil.h"
#include "Library/Camera/CameraPoserFunction.h"

#include "Util/PlayerCollisionUtil.h"
#include "Library/Collision/Collider.h"
#include "Library/Collision/CollisionUtil.h"
#include "agent/ScriptOptimizerDemo.h"

#include <fcntl.h>
#include <sys/stat.h>

enum class MyCameraMode { Free, Follow, Fixed };

int supress_stdout() {
    fflush(stdout);

    int ret = dup(1);
    int nullfd = open("/dev/null", O_WRONLY);
    // check nullfd for error omitted
    dup2(nullfd, 1);
    close(nullfd);

    return ret;
}

void resume_stdout(int fd) {
    fflush(stdout);
    dup2(fd, 1);
    close(fd);
}

bool shouldUpdate() {
    static bool paused = false;
    if (IsKeyPressed(KEY_HOME))
        paused = !paused;
    return !paused || IsKeyPressed(KEY_SPACE) || IsKeyPressedRepeat(KEY_SPACE);
}

#define SCALE 0.005f

Model ShineCubeModel;

int odyssey_physics_main(int argc, char *argv[]) {
    const char* stage;
    if(argc > 0) {
        stage = argv[0];
    } else {
        stage = Stage;
    }

    if(!TEST_FPS_HEADLESS) {
        SetTraceLogLevel(LOG_NONE);
        InitWindow(1920, 1080, "OdysseyPhysics");
        SetTargetFPS(TEST_FPS_RAYLIB ? 0 : 60);
        if (!WSL_COMPATIBILITY) DisableCursor();

        setupRaylibUtil();
        
        ShineCubeModel = LoadModelFromMesh(cubeMesh);
        ShineCubeModel.materials[0].maps->color = GOLD;
    }

    initializeSead();
    {
        // context of sead
        MyCameraMode camMode = MyCameraMode::Fixed;

        game::StageSceneManager sceneManager{};
        game::StageScene* scene = sceneManager.getScene();
        sceneManager.init(stage, 0);

        if (TASPlayback)
            Input::instance()->setInputProvider(new InputProviderTAS(TASFile));
        else
            Input::instance()->setInputProvider(new InputProviderRaylib());

        float angleH = 0;
        float angleV = 60;
        float distance = 3000.000244140625;
        sead::Vector3f lookAtPos1 = {-250, 300, 1500};   // room 1
        sead::Vector3f lookAtPos2 = {-3050, 300, 1500};  // room 2
        sead::Vector3f lookAtPos3 = {-5850, 300, 1500};  // room 3
        scene->mCamera->setup(angleH, angleV, distance, lookAtPos1);

        Camera3D cam = {0};
        cam.position = raylibVec(scene->mCamera->position() * SCALE);
        cam.target = raylibVec(scene->mCamera->at() * SCALE);
        cam.up = raylibVec(scene->mCamera->up());
        cam.fovy = 45;
        cam.projection = CAMERA_PERSPECTIVE;

        if(TEST_FPS_HEADLESS) {
            int fd = 0;//supress_stdout();
            double time_start = GetTime();
            for(int i=0; i<TEST_FRAMES; i++) {
                Input::instance()->update();
                scene->update();
            }
            double time_end = GetTime();
            resume_stdout(fd);
            fprintf(stdout, "Time taken for %d frames: %f => %f FPS\n", TEST_FRAMES, time_end - time_start, TEST_FRAMES / (time_end - time_start));
            return 1;
        }

        if(TEST_AGENT) {
            sead::BoundBox3f destination{{-850, 50, 700}, {-450, 1000, 1100}};
            //sead::BoundBox3f destination{{-6780, 150, 350}, {-6450, 1000, 710}};

            ScriptOptimizerDemo optimizer(sceneManager.mHeap, TASFile, destination);
            printf("initial score: %f\n", optimizer.mScore);
            optimizer.optimize(TEST_AGENT_ITERATIONS);
            printf("final score: %f\n", optimizer.mScore);
            TASFrame* frame = new TASFrame[optimizer.mFrames.size()];
            int i = 0;
            for (auto it = optimizer.mFrames.begin(); it != optimizer.mFrames.end(); ++it) {
                frame[i++] = *it;
            }
            Input::dumpToTASFile("tmp.tas", frame, optimizer.mFrames.size());
            delete[] frame;

            Input::instance()->setInputProvider(new InputProviderTAS(optimizer.mFrames));
        }

        sead::ClonableExpHeap* prevHeap = sceneManager.mHeap->clone();

        
        int fd = TEST_FPS_RAYLIB ? supress_stdout() : -1;
        double time_start = GetTime();
        int frames = 0;

        int cameraDirLoc = GetShaderLocation(checkerShader, "cameraDirection");
        while (!WindowShouldClose()) {
            if(TEST_FPS_RAYLIB && frames >= TEST_FRAMES) {
                double time_end = GetTime();
                resume_stdout(fd);
                printf("Time taken for %d frames: %f => %f FPS\n", frames, time_end - time_start, frames / (time_end - time_start));
                return 1;
            }

            if (IsKeyPressed(KEY_P)) {
                sead::ClonableExpHeap* currentHeap = sceneManager.mHeap;
                sceneManager.mHeap = prevHeap;
                prevHeap = currentHeap;
            }
            if (IsKeyPressed(KEY_ZERO))
                Input::instance()->dumpToTASFile("res/out.txt");
            if (IsKeyPressed(KEY_O))
                camMode = (MyCameraMode)(((int)camMode + 1) % 3);
            if (IsKeyPressed(KEY_L))
                TakeScreenshot("screenshot.png");
            scene = sceneManager.getScene();

            if (IsKeyPressed(KEY_KP_8) || IsKeyPressedRepeat(KEY_KP_8))
                scene->mPlayer->mActor->mPoseKeeper->updatePoseTrans(scene->mPlayer->mActor->mPoseKeeper->getTrans() - sead::Vector3f::ez*100);
            if (IsKeyPressed(KEY_KP_2) || IsKeyPressedRepeat(KEY_KP_2))
                scene->mPlayer->mActor->mPoseKeeper->updatePoseTrans(scene->mPlayer->mActor->mPoseKeeper->getTrans() + sead::Vector3f::ez*100);
            if (IsKeyPressed(KEY_KP_4) || IsKeyPressedRepeat(KEY_KP_4))
                scene->mPlayer->mActor->mPoseKeeper->updatePoseTrans(scene->mPlayer->mActor->mPoseKeeper->getTrans() - sead::Vector3f::ex*100);
            if (IsKeyPressed(KEY_KP_6) || IsKeyPressedRepeat(KEY_KP_6))
                scene->mPlayer->mActor->mPoseKeeper->updatePoseTrans(scene->mPlayer->mActor->mPoseKeeper->getTrans() + sead::Vector3f::ex*100);
            if (IsKeyPressed(KEY_KP_0) || IsKeyPressedRepeat(KEY_KP_0))
                scene->mPlayer->mActor->mPoseKeeper->updatePoseTrans(scene->mPlayer->mActor->mPoseKeeper->getTrans() + sead::Vector3f::ey*100);
            if (IsKeyPressed(KEY_KP_5) || IsKeyPressedRepeat(KEY_KP_5))
                scene->mPlayer->mActor->mPoseKeeper->updatePoseTrans(scene->mPlayer->mActor->mPoseKeeper->getTrans() - sead::Vector3f::ey*100);

            //if(!TEST_UPWARPS || IsKeyPressedRepeat(KEY_U) || IsKeyPressed(KEY_U)) {
            if(shouldUpdate()) {
                printf("--------------------------- %d ---------------------------------\n", Input::instance()->getInputCount());
                al::NerveKeeper* playerNerveKeeper = scene->mPlayer->mActor->mNerveKeeper;
                sead::Vector3f playerPos = scene->mPlayer->mActor->mPoseKeeper->getTrans();
                sead::Vector3f playerVel = scene->mPlayer->mActor->mPoseKeeper->getVelocity();
                sead::Vector3f playerFront;
                al::calcFrontDir(&playerFront, scene->mPlayer->mActor);
                printf("Currently in %s\n",
                    playerNerveKeeper->getStateCtrl()->findStateInfo(playerNerveKeeper->getCurrentNerve())->name);
                printf("Position: (%.17f, %.17f, %.17f)\n", playerPos.x, playerPos.y, playerPos.z);
                printf("Velocity: (%.17f, %.17f, %.17f)\n", playerVel.x, playerVel.y, playerVel.z);
                printf("Front: (%.17f, %.17f, %.17f)\n", playerFront.x, playerFront.y, playerFront.z);
                if(Input::instance()->getInputCount() == 111) {
                    printf("Dbg\n");
                }

                Input::instance()->update();
                scene->update();
            }

            if (camMode == MyCameraMode::Free) {
                UpdateCamera(&cam, CAMERA_FREE);
            } else if (camMode == MyCameraMode::Fixed) {
                sead::Vector3f playerPos = scene->mPlayer->mActor->mPoseKeeper->getTrans();
                float dist1 = sead::Vector3f(playerPos - lookAtPos1).squaredLength();
                float dist2 = sead::Vector3f(playerPos - lookAtPos2).squaredLength();
                float dist3 = sead::Vector3f(playerPos - lookAtPos3).squaredLength();
                if (dist1 < dist2 && dist1 < dist3)
                    scene->mCamera->setup(angleH, angleV, distance, lookAtPos1);
                else if (dist2 < dist1 && dist2 < dist3)
                    scene->mCamera->setup(angleH, angleV, distance, lookAtPos2);
                else
                    scene->mCamera->setup(angleH, angleV, distance, lookAtPos3);
                cam.position = raylibVec(scene->mCamera->position() * SCALE);
                cam.target = raylibVec(scene->mCamera->at() * SCALE);
                cam.up = raylibVec(scene->mCamera->up());
            } else if (camMode == MyCameraMode::Follow) {
                sead::Vector3f playerPos = scene->mPlayer->mActor->mPoseKeeper->getTrans();
                scene->mCamera->setup(angleH, angleV, distance, playerPos);
                cam.position = raylibVec(scene->mCamera->position() * SCALE);
                cam.target = raylibVec(scene->mCamera->at() * SCALE);
                cam.up = raylibVec(scene->mCamera->up());
            }

            sead::Vector3f cameraDir = (seadVec(cam.target) - seadVec(cam.position));
            cameraDir.normalize();

            BeginDrawing();
            {
                ClearBackground(BLACK);
                BeginMode3D(cam);

                SetShaderValue(checkerShader, cameraDirLoc, &cameraDir, SHADER_UNIFORM_VEC3);

                for (int i = 0; i < scene->mActorsNum; i++) {
                    auto actor = scene->mActors[i];
                    if (!actor)
                        continue;

                    sead::Matrix34f mtx;
                    actor->mActor->mPoseKeeper->updatePoseQuat(al::getQuat(actor->mActor));
                    actor->mActor->mPoseKeeper->calcBaseMtx(&mtx);
                    actor->raylibModel.transform = raylibMtx(mtx);
                    DrawModel(actor->raylibModel, {0, 0, 0}, SCALE, WHITE);
                }

                for (int i = 0; i < scene->mShinesNum; i++) {
                    sead::Vector3f pos = scene->mShinePositions[i];
                    ShineCubeModel.transform = {
                        1, 0, 0, pos.x,
                        0, 1, 0, pos.y,
                        0, 0, 1, pos.z,
                        0, 0, 0, 1
                    };
                    DrawModel(ShineCubeModel, {0, 0, 0}, SCALE, WHITE);
                }

                {
                    sead::Matrix34f mtx;
                    scene->mPlayer->mActor->mPoseKeeper->calcBaseMtx(&mtx);
                    CollisionShapeKeeper* collisionShapeKeeper =
                        ((PlayerActorHakoniwa*)scene->mPlayer->mActor)
                            ->getPlayerCollision()
                            ->getPlayerCollider()
                            ->mCollisionShapeKeeper;
                    for (int i = 0; i < collisionShapeKeeper->mCollisionShape.size(); i++) {
                        auto shape = collisionShapeKeeper->mCollisionShape[i];
                        if (shape->getId() == CollisionShapeId::Arrow) {
                            auto arrow = (CollisionShapeInfoArrow*)shape;
                            sead::Vector3f startOrig = arrow->a3;
                            sead::Vector3f endOrig = arrow->a4;
                            sead::Vector3f start, end;
                            start.setMul(mtx, startOrig);
                            end.setMul(mtx, endOrig);
                            start *= SCALE;
                            end *= SCALE;
                            rlPushMatrix();
                            DrawLine3D(raylibVec(start), raylibVec(end), RED);
                            rlPopMatrix();
                        } else if (shape->getId() == CollisionShapeId::Sphere) {
                            auto sphere = (CollisionShapeInfoSphere*)shape;
                            sead::Vector3f center = sphere->mBoundingCenter * SCALE;
                            sphereModel.transform = raylibMtx(mtx);
                            DrawModel(sphereModel, raylibVec(center), SCALE, RED);
                        } else {
                            printf("Unknown shape type: %d\n", (int)shape->getId());
                            CRASH
                        }
                    }
                }

                EndMode3D();

                DrawText(
                    scene->mPlayer->mActor->mNerveKeeper->getStateCtrl()
                        ->findStateInfo(scene->mPlayer->mActor->mNerveKeeper->getCurrentNerve())
                        ->name,
                    0, 0, 40, {255, 0, 0, 255});
                
                bool isDead = false;
                isDead |= rs::isCollisionCodePoisonTouch(((PlayerActorHakoniwa*)scene->mPlayer->mActor)->mPlayerColliderHakoniwa);
                isDead |= rs::isCollisionCodeDamageFireGround(((PlayerActorHakoniwa*)scene->mPlayer->mActor)->mPlayerColliderHakoniwa);
                if(isDead) {
                    DrawText("Dead", 0, 50, 40, {255, 0, 0, 255});
                }

                sead::Vector3f playerTrans = al::getTrans(scene->mPlayer->mActor);
                for(int i=0; i<scene->mShinesNum; i++) {
                    sead::Vector3f shinePos = scene->mShinePositions[i];
                    DrawText(TextFormat("Shine %d: %.2f", i, (shinePos - playerTrans).length()), 0, 90+40*i, 40, {255, 0, 0, 255});
                }
            }
            EndDrawing();

            frames++;
        }
    }
    unloadSead();
    unloadRaylibUtil();

    CloseWindow();

    printf("Exiting...\n");
    return 0;
}
