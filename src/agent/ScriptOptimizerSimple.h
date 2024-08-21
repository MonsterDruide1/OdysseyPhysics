#pragma once

#include "agent/InputList.h"
#include "container/seadTList.h"
#include "game/InputProviderTAS.h"
#include "heap/ClonableExpHeap.h"
#include "math/seadBoundBox.h"

class ScriptOptimizerSimple {
public:
    ScriptOptimizerSimple(sead::ClonableExpHeap* initialState, const char* scriptPath, const sead::BoundBox3f& destination);

    void optimize(int iterations);
    void optimizeIteration();
    
    static bool mutate(TASFrame* frame);

public:
    f32 evaluate(const InputList& frames);

public:
    sead::ClonableExpHeap* mInitialState;
    sead::BoundBox3f mDestination;
    InputList mFrames;
    f32 mScore = sead::Mathf::infinity();
};
