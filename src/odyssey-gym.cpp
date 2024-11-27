#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "Library/Nerve/NerveKeeper.h"
#include "Library/Nerve/NerveStateCtrl.h"
#include "Player/CollisionShapeInfo.h"
#include "Player/CollisionShapeKeeper.h"
#include "Player/PlayerActorHakoniwa.h"
#include "Player/PlayerCollider.h"
#include "Player/PlayerColliderHakoniwa.h"
#include "Util/PlayerCollisionUtil.h"
#include "RaylibUtil.h"
#include "game/Input.h"
#include "game/StageSceneManager.h"
#include "raylib.h"
#include "rlgl.h"
#include "seadInterface.h"

#define SCALE 0.005f

#define COMMAND_IN_FRAME 1
#define COMMAND_IN_RESET 2
#define COMMAND_OUT_ACK 1  // currently unused
#define COMMAND_OUT_DATA 2

#pragma pack(1)
struct __attribute__((packed)) DataPacket {
    char type = COMMAND_OUT_DATA;
    sead::Vector3f playerPos;
    bool isTouchingPoison;
};
#pragma pack()

struct InputProviderGym : public InputProvider {
    FrameInput frame;

    sead::BitFlag32 getButtons() override {
        return frame.buttons;
    }
    sead::Vector2f getStickLeft() override {
        return frame.stickLeft;
    }
    sead::Vector2f getStickRight() override {
        return frame.stickRight;
    }
};

void setupCameraSandMegane(game::StageScene* scene, Camera3D cam) {
    float angleH = 0;
    float angleV = 60;
    float distance = 3000.000244140625;
    sead::Vector3f lookAtPos1 = {-250, 300, 1500};   // room 1
    sead::Vector3f lookAtPos2 = {-3050, 300, 1500};  // room 2
    sead::Vector3f lookAtPos3 = {-5850, 300, 1500};  // room 3

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
}

void drawRaylib(game::StageScene* scene, Camera3D cam) {
    BeginDrawing();
    {
        ClearBackground(BLACK);
        BeginMode3D(cam);

        int cameraDirLoc = GetShaderLocation(checkerShader, "cameraDirection");
        sead::Vector3f cameraDir = (seadVec(cam.target) - seadVec(cam.position));
        cameraDir.normalize();
        SetShaderValue(checkerShader, cameraDirLoc, &cameraDir, SHADER_UNIFORM_VEC3);

        for (int i = 0; i < scene->mActorsNum; i++) {
            auto actor = scene->mActors[i];
            if (!actor)
                continue;

            sead::Matrix34f mtx;
            actor->mActor->mPoseKeeper->calcBaseMtx(&mtx);
            actor->raylibModel.transform = raylibMtx(mtx);
            DrawModel(actor->raylibModel, {0, 0, 0}, SCALE, WHITE);
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
        
        if(rs::isCollisionCodePoisonTouch(((PlayerActorHakoniwa*)scene->mPlayer->mActor)->mPlayerColliderHakoniwa)) {
            DrawText("Poison Touch", 0, 50, 40, {255, 0, 0, 255});
        }
    }
    EndDrawing();
}

void sendState(game::StageScene* scene, int sock) {
    PlayerActorHakoniwa* player = (PlayerActorHakoniwa*)scene->mPlayer->mActor;
    DataPacket p = {
        COMMAND_OUT_DATA,
        al::getTrans(player),
        rs::isCollisionCodePoisonTouch(player->mPlayerColliderHakoniwa),
    };
    write(sock, &p, sizeof(DataPacket));
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <stage> <scenario> <socket-file> [display?]\n", argv[0]);
        return 1;
    }

    const char* stage = argv[1];
    int scenario = atoi(argv[2]);
    const char* socketFile = argv[3];
    bool display = argc >= 4 && strcmp(argv[4], "true") == 0;

    int serverSocket = socket(AF_UNIX, SOCK_STREAM, 0);
    //fcntl(serverSocket, F_SETFL, fcntl(serverSocket, F_GETFL, 0) | O_NONBLOCK);
    //timeval timeout;
    //timeout.tv_sec = 0;
    //timeout.tv_usec = 1;
    //setsockopt(serverSocket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    if (serverSocket == -1) {
        printf("Failed to create socket\n");
        return 1;
    }
    sockaddr_un sockaddr_un = {0};
    sockaddr_un.sun_family = AF_UNIX;
    strcpy(sockaddr_un.sun_path, socketFile);
    if(connect(serverSocket, (sockaddr*)&sockaddr_un, sizeof(sockaddr_un)) == -1) {
        printf("Failed to connect to socket\n");
        return -1;
    }

    if(display) {
        SetTraceLogLevel(LOG_NONE);
        InitWindow(1920, 1080, "OdysseyPhysics");
        SetTargetFPS(0);  // no artificial limit, just go as fast as possible

        setupRaylibUtil();
    }

    initializeSead();
    {
        // context of sead
        game::StageSceneManager sceneManager{};
        game::StageScene* scene = sceneManager.getScene();
        sceneManager.init(stage, scenario);

        InputProviderGym* input = new InputProviderGym();
        Input::instance()->setInputProvider(input);
        
        Camera3D cam = {0};
        cam.fovy = 45;
        cam.projection = CAMERA_PERSPECTIVE;
        if(strcmp("SandWorldMeganeExStageMap", stage) == 0)
            setupCameraSandMegane(scene, cam);

        sead::ClonableExpHeap* prevHeap = sceneManager.mHeap->clone();

        while (true) {
            if(display && WindowShouldClose())
                break;

            char command;
            int read_bytes = read(serverSocket, &command, 1);
            if(read_bytes <= 0) {
                if(display)
                    PollInputEvents();
                if(read_bytes == 0)
                    continue;
                if(read_bytes == -1 && errno == EAGAIN)
                    continue;
                else {
                    printf("Unhandled error with socket: %d (%s)\n", errno, strerror(errno));
                    break;
                }
            }

            switch(command) {
                case COMMAND_IN_FRAME:
                    read_bytes = read(serverSocket, &input->frame, sizeof(FrameInput));
                    if(read_bytes != sizeof(FrameInput)) {
                        printf("Failed to read FrameInput!\n");
                        break;
                    }

                    scene = sceneManager.getScene();

                    Input::instance()->update();
                    scene->update();

                    if(strcmp("SandWorldMeganeExStageMap", stage) == 0)
                        setupCameraSandMegane(scene, cam);

                    sendState(scene, serverSocket);
                    
                    if(display)
                        drawRaylib(scene, cam);
                    break;
                case COMMAND_IN_RESET:
                    delete sceneManager.mHeap;
                    sceneManager.mHeap = prevHeap->clone();

                    sendState(scene, serverSocket);
                    break;
                default:
                    printf("Error: no command with ID %d found!", command);
                    break;
            }
        }

    }
    unloadSead();
    unloadRaylibUtil();

    if(display)
        CloseWindow();

    close(serverSocket);
    return 0;
}
