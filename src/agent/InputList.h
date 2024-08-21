#pragma once

#include "game/InputProviderTAS.h"

class InputList : public sead::TList<TASFrame> {
public:
    // empty constructor
    InputList() {}

    // construct from TAS script at scriptPath
    InputList(const char* scriptPath) {
        InputProviderTAS inputProvider = InputProviderTAS(scriptPath);
        while (!inputProvider.mFrames.isEmpty()) {
            sead::TListNode<TASFrame>* node = inputProvider.mFrames.popBack();
            node->mList = nullptr;
            pushFront(node);
        }
    }

    // copy from other InputList
    InputList(const InputList& other) {
        for (auto it = other.begin(); it != other.end(); ++it) {
            TASFrame frame = *it;
            pushBack(new sead::TListNode<TASFrame>(frame));
        }
    }

    // copy and mutate from other InputList, where mutate takes a pointer and returns whether the frame should be dropped
    InputList(const InputList& other, bool (*mutate)(TASFrame*)) {
        for (auto it = other.begin(); it != other.end(); ++it) {
            TASFrame frame = *it;
            if (!mutate(&frame))
                continue;
            pushBack(new sead::TListNode<TASFrame>(frame));
        }
    }

    ~InputList() {
        while (!isEmpty()) {
            delete popBack();
        }
    }

    s32 countButtonPresses() const {
        s32 count = 0;
        for (auto it = begin(); it != end(); ++it)
            count += it->buttons.countOnBit();
        return count;
    }
};
