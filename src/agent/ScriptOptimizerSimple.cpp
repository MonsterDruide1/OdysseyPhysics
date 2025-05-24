#include "agent/ScriptOptimizerSimple.h"

#include "Player/PlayerActorHakoniwa.h"
#include "Util/PlayerCollisionUtil.h"
#include "game/InputProviderTAS.h"
#include "game/RaylibActor.h"
#include "game/StageScene.h"
#include "heap/ClonableExpHeap.h"
#include "math/seadVector.h"

ScriptOptimizerSimple::ScriptOptimizerSimple(sead::ClonableExpHeap* initialState,
                                             const char* scriptPath,
                                             const sead::BoundBox3f& destination)
    : mInitialState(initialState), mDestination(destination), mFrames(scriptPath) {
    mScore = evaluate(mFrames);
}

void ScriptOptimizerSimple::optimize(int iterations) {
    // ensure randomness
    srand(time(nullptr));
    for (int i = 0; i < iterations; ++i) {
        optimizeIteration();
    }
}

void ScriptOptimizerSimple::optimizeIteration() {
    InputList newFrames = InputList(mFrames, &ScriptOptimizerSimple::mutate);
    f32 newScore = evaluate(newFrames);

    // if new best (= lower score), update
    if (newScore < mScore) {
        mFrames = newFrames;
        mScore = newScore;
    }
}

bool ScriptOptimizerSimple::mutate(TASFrame* frame) {
    // drop frame with 1/30000 chance
    if (rand() % 30000 == 0)
        return false;

    // toggle button off with 1/100 chance, on with 1/10000 chance
    // ZL less likely, because most of the time, it slows the player down

    if (frame->buttons.isOn(ControllerButton_A) && rand() % 100 == 0)
        frame->buttons.toggleBit(ControllerButton_A);
    if (frame->buttons.isOff(ControllerButton_A) && rand() % 10000 == 0)
        frame->buttons.toggleBit(ControllerButton_A);

    if (frame->buttons.isOn(ControllerButton_Y) && rand() % 100 == 0)
        frame->buttons.toggleBit(ControllerButton_Y);
    if (frame->buttons.isOff(ControllerButton_Y) && rand() % 10000 == 0)
        frame->buttons.toggleBit(ControllerButton_Y);

    if (frame->buttons.isOn(ControllerButton_C) && rand() % 100 == 0)
        frame->buttons.toggleBit(ControllerButton_C);
    if (frame->buttons.isOff(ControllerButton_C) && rand() % 40000 == 0)
        frame->buttons.toggleBit(ControllerButton_C);

    // adjust angle of left stick with 1/5000 chance
    if (rand() % 5000 == 0) {
        // adjust angle of left stick (if no input, default to pi)
        f32 currentAngle = frame->stickLeft.isZero() ?
                               sead::Mathf::pi() :
                               atan2(frame->stickLeft.y, frame->stickLeft.x);
        // adjust by up to 15 degree in either direction (in radians)
        f32 angleAdjustment = sead::Mathf::deg2rad(rand() % 30 - 15);
        f32 newAngle = currentAngle + angleAdjustment;
        // apply new angle
        frame->stickLeft = sead::Vector2f(cos(newAngle), sin(newAngle));
    }
    return true;
}

f32 ScriptOptimizerSimple::evaluate(const InputList& frames) {
    // setup new game instance
    sead::ClonableExpHeap* heap = mInitialState->clone();
    game::StageScene* scene = (game::StageScene*)(heap->mUseList.front()->memory());

    // setup input provider
    InputProviderTAS inputProvider = InputProviderTAS(frames);
    Input::instance()->setInputProvider(&inputProvider);

    PlayerActorHakoniwa* player = (PlayerActorHakoniwa*)scene->mPlayer->mActor;
    sead::Vector3f* playerPos = player->mPoseKeeper->getTransPtr();

    // run simulation for length of the script or best score + 4 (allow extra frames that might
    // still increase score)
    for (int i = 0; i < sead::Mathf::min(frames.size(), mScore + 4); ++i) {
        // update input and scene => updates the entire game simulation
        Input::instance()->update();
        scene->update();

        // stop simulation if player is dead
        if (rs::isCollisionCodePoisonTouch(player->mColliderHakoniwa))
            break;
        // stop simulation if player has reached the goal
        if (mDestination.isInside(*playerPos))
            break;
    }

    // destroy the game instance
    delete heap;

    // invalid run if the player didn't reach the goal or died in poison
    if (!mDestination.isInside(*playerPos))
        return sead::Mathf::infinity();
    if (rs::isCollisionCodePoisonTouch(player->mColliderHakoniwa))
        return sead::Mathf::infinity();

    // final score: number of frames + number of button presses
    return inputProvider.mCurrentFrame + frames.countButtonPresses();
}
