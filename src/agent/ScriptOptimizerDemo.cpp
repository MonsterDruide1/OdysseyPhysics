#include "agent/ScriptOptimizerDemo.h"
#include <cstdlib>
#include "Player/PlayerActorHakoniwa.h"
#include "game/Input.h"
#include "game/InputProviderTAS.h"
#include "game/RaylibActor.h"
#include "game/StageScene.h"
#include "game/StageSceneManager.h"
#include "heap/ClonableExpHeap.h"
#include "math/seadMathCalcCommon.h"
#include "math/seadVectorFwd.h"
#include "raylib.h"
#include "Util/PlayerCollisionUtil.h"

ScriptOptimizerDemo::ScriptOptimizerDemo(sead::ClonableExpHeap* initialState, const char* scriptPath, const sead::BoundBox3f& destination) {
    mInitialState = initialState;
    mDestination = destination;

    InputProviderTAS inputProvider = InputProviderTAS(scriptPath);
    while (!inputProvider.mFrames.isEmpty()) {
        sead::TListNode<TASFrame>* node = inputProvider.mFrames.popBack();
        node->mList = nullptr;
        mFrames.pushFront(node);
    }
    mScore = evaluate(mFrames);
}

void ScriptOptimizerDemo::optimize(int iterations) {
    srand(time(nullptr));
    for (int i = 0; i < iterations; ++i) {
        if(i % 100 == 0)
            printf("Done iteration %d, current best: %f\n", i, mScore);
        optimizeIteration();
    }
}

void ScriptOptimizerDemo::optimizeIteration() {
    static int iteration = 0;
    static double timeStart = GetTime();
    
    sead::TList<TASFrame> newFrames;

    for (auto it = mFrames.begin(); it != mFrames.end(); ++it) {
        TASFrame frame = *it;
        if(!mutate(&frame)) continue;
        newFrames.pushBack(new sead::TListNode<TASFrame>(frame));
    }

    /*
    TASFrame* frame = new TASFrame[newFrames.size()];
    int i = 0;
    for (auto it = newFrames.begin(); it != newFrames.end(); ++it) {
        frame[i++] = *it;
    }
    Input::dumpToTASFile("tmp.tas", frame, newFrames.size());
    delete[] frame;
    */

    f32 newScore = evaluate(newFrames);
    if (newScore < mScore) {
        printf("%d / %f: %f -> %f\n", iteration++, GetTime() - timeStart, mScore, newScore);
        while (!mFrames.isEmpty()) {
            delete mFrames.popBack();
        }

        while (!newFrames.isEmpty()) {
            sead::TListNode<TASFrame>* node = newFrames.popBack();
            node->mList = nullptr;
            mFrames.pushFront(node);
        }

        mScore = newScore;

        dumpData(iteration);
    } else {
        while (!newFrames.isEmpty()) {
            delete newFrames.popBack();
        }
    }
    iteration++;
}

bool ScriptOptimizerDemo::mutate(TASFrame* frame) {
    const int FACTOR = 100;
    if(rand() % (300*FACTOR) == 0) {
        return false;
    }

    if (frame->buttons.isOn(ControllerButton_A) && rand() % (FACTOR) == 0) {
        frame->buttons.toggleBit(ControllerButton_A);
    }
    if (frame->buttons.isOff(ControllerButton_A) && rand() % (100*FACTOR) == 0) {
        frame->buttons.toggleBit(ControllerButton_A);
    }

    if (frame->buttons.isOn(ControllerButton_Y) && rand() % (FACTOR) == 0) {
        frame->buttons.toggleBit(ControllerButton_Y);
    }
    if (frame->buttons.isOff(ControllerButton_Y) && rand() % (100*FACTOR) == 0) {
        frame->buttons.toggleBit(ControllerButton_Y);
    }

    if (frame->buttons.isOn(ControllerButton_C) && rand() % (FACTOR) == 0) {
        frame->buttons.toggleBit(ControllerButton_C);
    }
    if (frame->buttons.isOff(ControllerButton_C) && rand() % (400*FACTOR) == 0) {
        frame->buttons.toggleBit(ControllerButton_C);
    }

    if (rand() % (50*FACTOR) == 0) {
        // adjust angle of left stick
        f32 currentAngle = frame->stickLeft.isZero() ? sead::Mathf::pi() : atan2(frame->stickLeft.y, frame->stickLeft.x);
        f32 newAngle = currentAngle + ((rand() % 100) / 6.0f - 3.0f);
        frame->stickLeft = sead::Vector2f(cos(newAngle), sin(newAngle));
    }
    return true;
}

f32 ScriptOptimizerDemo::evaluate(const sead::TList<TASFrame>& frames) {
    double timeStart = GetTime();
    sead::ClonableExpHeap* heap = mInitialState->clone();
    game::StageScene* scene = (game::StageScene*)(heap->mUseList.front()->memory());
    InputProviderTAS inputProvider = InputProviderTAS(frames);
    Input::instance()->setInputProvider(&inputProvider);

    game::RaylibActor* player = scene->mPlayer;
    sead::Vector3f* playerPos = player->mActor->mPoseKeeper->getTransPtr();

    int i = 0;
    for (i = 0; i < sead::Mathf::min(frames.size(), mScore + 4); ++i) {
        Input::instance()->update();
        scene->update();

        if(rs::isCollisionCodePoisonTouch(((PlayerActorHakoniwa*)scene->mPlayer->mActor)->mPlayerColliderHakoniwa)) {
            delete heap;
            return sead::Mathf::infinity();
        }
        if(mDestination.isInside(*playerPos)) {
            break;
        }
    }

    if (!mDestination.isInside(*playerPos)) {
        delete heap;
        return sead::Mathf::infinity();
    }
    
    int numButtonPresses = 0;
    for (auto it = frames.begin(); it != frames.end(); ++it) {
        numButtonPresses += it->buttons.countOnBit();
    }

    sead::Vector3f diff = *playerPos - mDestination.getCenter();
    f32 distance = diff.length();
    f32 maxDistance = sead::Vector3f{mDestination.getHalfSizeX(), mDestination.getHalfSizeY(), mDestination.getHalfSizeZ()}.length();
    f32 score = i + distance / maxDistance + numButtonPresses;

    delete heap;
    return score;
}

void ScriptOptimizerDemo::dumpData(int iteration) {
    TASFrame* frame = new TASFrame[mFrames.size()];
    int i = 0;
    for (auto it = mFrames.begin(); it != mFrames.end(); ++it) {
        frame[i++] = *it;
    }
    char filename[100];
    sprintf(filename, "out/%d.tas", iteration);
    Input::dumpToTASFile(filename, frame, mFrames.size());
    delete[] frame;

    // write all player positions to out/{iteration}.pos
    sead::ClonableExpHeap* heap = mInitialState->clone();
    game::StageScene* scene = (game::StageScene*)(heap->mUseList.front()->memory());
    InputProviderTAS inputProvider = InputProviderTAS(mFrames);
    Input::instance()->setInputProvider(&inputProvider);

    game::RaylibActor* player = scene->mPlayer;
    sead::Vector3f* playerPos = player->mActor->mPoseKeeper->getTransPtr();

    sprintf(filename, "out/%d.pos", iteration);
    FILE* posFile = fopen(filename, "w");

    for (i = 0; i < sead::Mathf::min(mFrames.size(), mScore + 4); ++i) {
        Input::instance()->update();
        scene->update();

        fprintf(posFile, "%f %f %f\n", playerPos->x, playerPos->y, playerPos->z);

        if(rs::isCollisionCodePoisonTouch(((PlayerActorHakoniwa*)scene->mPlayer->mActor)->mPlayerColliderHakoniwa)) {
            break;
        }
        if(mDestination.isInside(*playerPos)) {
            break;
        }
    }

    fclose(posFile);
    delete heap;
}
