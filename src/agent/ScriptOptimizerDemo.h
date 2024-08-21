#pragma once

#include "container/seadTList.h"
#include "game/InputProviderTAS.h"
#include "heap/ClonableExpHeap.h"
#include "math/seadBoundBox.h"

class ScriptOptimizerDemo {
public:
    ScriptOptimizerDemo(sead::ClonableExpHeap* initialState, const char* scriptPath, const sead::BoundBox3f& destination);

    void optimize(int iterations);
    void optimizeIteration();

public:
    bool mutate(TASFrame* frame);
    f32 evaluate(const sead::TList<TASFrame>& frames);
    void dumpData(int iteration);

public:
    sead::ClonableExpHeap* mInitialState;
    sead::BoundBox3f mDestination;
    sead::TList<TASFrame> mFrames;
    f32 mScore = sead::Mathf::infinity();
};
