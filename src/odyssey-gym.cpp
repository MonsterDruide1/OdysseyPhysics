#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "Library/Collision/CollisionUtil.h"
#include "Library/LiveActor/ActorMovementFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/Nerve/NerveKeeper.h"
#include "Library/Nerve/NerveStateCtrl.h"
#include "Player/CollisionShapeInfo.h"
#include "Player/CollisionShapeKeeper.h"
#include "Player/PlayerActorHakoniwa.h"
#include "Player/PlayerCollider.h"
#include "Player/PlayerColliderHakoniwa.h"
#include "Player/PlayerContinuousJump.h"
#include "Player/PlayerCounterQuickTurnJump.h"
#include "PlayerStateGym.h"
#include "PlayerUtil.h"
#include "Util/PlayerCollisionUtil.h"
#include "RaylibUtil.h"
#include "game/Input.h"
#include "game/StageSceneManager.h"
#include "raylib.h"
#include "rlgl.h"
#include "seadInterface.h"
#include "settings.h"

#define SCALE 0.005f

#define COMMAND_IN_FRAME 1
#define COMMAND_IN_RESET 2
#define COMMAND_IN_RENDER 3
#define COMMAND_OUT_ACK 1  // currently unused
#define COMMAND_OUT_DATA 2
#define COMMAND_OUT_RENDER 3

#pragma pack(1)
struct __attribute__((packed)) DataPacket {
    char type = COMMAND_OUT_DATA;  // +1
    sead::Vector3f playerPos;  // 0x000
    sead::Vector3f playerVel;  // 0x00c
    sead::Quatf playerQuat;    // 0x018
    u128 stateBitMap;          // 0x028
    f32 raycastResults[250];   // 0x038
    u32 counterContinuousJump; // 0x420
    s32 counterQuickTurnJump;  // 0x424
    bool isTouchingMoon;       // 0x428
    bool isTouchingPoison;     // 0x429
};
#pragma pack()
static_assert(sizeof(DataPacket) == 0x42a+1);

#pragma pack(1)
struct __attribute__((packed)) ResetPacket {
    bool isOverridePosition;   // 0x000
    sead::Vector3f playerPos;  // 0x001
};
#pragma pack()
static_assert(sizeof(ResetPacket) == 0xd);

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

void setupCameraSandMegane(game::StageScene* scene, Camera3D& cam) {
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

void drawRaylib(game::StageScene* scene, Camera3D& cam) {
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

void fillRaycastResults(PlayerActorHakoniwa* player, f32* results, int numSamples) {
    sead::Matrix34f playerMtx = sead::Matrix34f::ident;
    playerMtx.fromQuat(al::getQuat(player));
    sead::Vector3f playerPos = al::getTrans(player);

    // fibonacci sphere: https://stackoverflow.com/a/26127012/9275661
    f32 phi = sead::Mathf::pi() * (sead::Mathf::sqrt(5.0f) - 1.0f);
    for(int i=0; i<numSamples; i++) {
        f32 y = 1 - (i / (f32)(numSamples - 1)) * 2;
        f32 radius = sead::Mathf::sqrt(1 - y * y);
        f32 theta = phi * i;
        f32 x = sead::Mathf::cos(theta) * radius;
        f32 z = sead::Mathf::sin(theta) * radius;

        sead::Vector3f dir = {x, y, z};
        dir.normalize();
        sead::Vector3f hitPos = {0, 0, 0};
        sead::Vector3f hitNormal = {0, 0, 0};
        bool hit = alCollisionUtil::getHitPosAndNormalOnArrow(player, &hitPos, &hitNormal, al::getTrans(player), playerMtx * dir * 500'00, nullptr, nullptr);
        results[i] = hit ? (hitPos - playerPos).length() : 500'00.0f;
    }
}

void sendState(game::StageScene* scene, int sock) {
    PlayerActorHakoniwa* player = (PlayerActorHakoniwa*)scene->mPlayer->mActor;

    bool isTouchingMoon = false;
    for(int i=0; i<scene->mShinesNum; i++) {
        sead::Vector3f shinePos = scene->mShinePositions[i];
        if((shinePos - al::getTrans(player)).length() < 200) {
            isTouchingMoon = true;
            break;
        }
    }

    bool isDead = false;
    isDead |= rs::isCollisionCodePoisonTouch(player->mPlayerColliderHakoniwa);
    isDead |= rs::isCollisionCodeDamageFireGround(((PlayerActorHakoniwa*)scene->mPlayer->mActor)->mPlayerColliderHakoniwa);
    isDead |= scene->mPlayer->mActor->mPoseKeeper->getTrans().y < -2000;

    DataPacket p = {
        COMMAND_OUT_DATA,
        al::getTrans(player),
        al::getVelocity(player),
        al::getQuat(player),
        getPlayerStateBitMap(player),
        {},  // placeholder
        player->mPlayerContinuousJump->mCount,
        player->mPlayerCounterQuickTurnJump->mCounter,
        isTouchingMoon,
        isDead,
    };
    fillRaycastResults(player, p.raycastResults, 250);

    write(sock, &p, sizeof(DataPacket));
}

void sendRender(RenderTexture2D tex, int sock) {
    Image img = LoadImageFromTexture(tex.texture);
    Color* pixels = LoadImageColors(img);

    char data[1920*1080*3 + 1];
    data[0] = COMMAND_OUT_RENDER;
    for(int i=0; i<img.width*img.height; i++) {
        data[i*3+1] = pixels[i].r;
        data[i*3+2] = pixels[i].g;
        data[i*3+3] = pixels[i].b;
    }
    write(sock, data, sizeof(data));

    UnloadImageColors(pixels);
    UnloadImage(img);
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Usage: %s <stage> <scenario> <path to romfs> <socket-file> [display?]\n", argv[0]);
        return 1;
    }

    const char* stage = argv[1];
    int scenario = atoi(argv[2]);
    settings::sRomfsPath = argv[3];
    const char* socketFile = argv[4];
    int display_mode = argc >= 6 ? atoi(argv[5]) : 0;

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

    RenderTexture2D renderTarget;

    if(display_mode >= 1) {
        SetTraceLogLevel(LOG_NONE);
        InitWindow(1920, 1080, "OdysseyPhysics");
        SetTargetFPS(0);  // no artificial limit, just go as fast as possible
        setupRaylibUtil();
        
        // setup render texture for render command
        renderTarget = LoadRenderTexture(1920, 1080);
        BeginTextureMode(renderTarget);
        ClearBackground(BLACK);
        EndTextureMode();
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
            if(display_mode >= 2 && WindowShouldClose())
                break;

            char command;
            int read_bytes = read(serverSocket, &command, 1);
            if(read_bytes <= 0) {
                if(display_mode >= 2)
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

            ResetPacket reset_packet;
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
                    
                    if(display_mode >= 2) {
                        BeginDrawing();
                        drawRaylib(scene, cam);
                        EndDrawing();
                    }
                    break;
                case COMMAND_IN_RESET:
                    delete sceneManager.mHeap;
                    sceneManager.mHeap = prevHeap->clone();
                    if(read(serverSocket, &reset_packet, sizeof(ResetPacket)) != sizeof(ResetPacket)) {
                        printf("Failed to read ResetPacket!\n");
                        break;
                    }
                    if(reset_packet.isOverridePosition) {
                        scene->mPlayer->mActor->mPoseKeeper->updatePoseTrans(reset_packet.playerPos);
                        rs::resetCollision(((PlayerActorHakoniwa*)scene->mPlayer->mActor)->mPlayerColliderHakoniwa);
                    }

                    sendState(scene, serverSocket);
                    break;
                case COMMAND_IN_RENDER:
                    if (display_mode < 1) {
                        printf("Error: received render command but display is disabled!\n");
                        break;
                    }
                    BeginTextureMode(renderTarget);
                    drawRaylib(scene, cam);
                    EndTextureMode();

                    sendRender(renderTarget, serverSocket);
                    break;
                default:
                    printf("Error: no command with ID %d found!", command);
                    break;
            }
        }

    }
    unloadSead();

    if(display_mode >= 1) {
        unloadRaylibUtil();
        CloseWindow();
        UnloadRenderTexture(renderTarget);
    }

    close(serverSocket);
    return 0;
}
