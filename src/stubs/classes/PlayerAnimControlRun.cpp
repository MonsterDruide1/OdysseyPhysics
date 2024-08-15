#include "Player/PlayerAnimControlRun.h"
#include "CUSTOM/PlayerAnimator.h"
#include "Library/Math/MathLengthUtil.h"
#include "Library/Math/MathUtil.h"
#include "Library/stuff.h"
#include "Player/PlayerConst.h"
#include "Util/StageSceneFunction.h"
#include "math/seadMathCalcCommon.h"
#include "PlayerUtil.h"

PlayerAnimControlRun::PlayerAnimControlRun(PlayerAnimator* animator, PlayerConst const* pConst,
                                           IJudge const* judge, PlayerEffect* effect, bool isMoon)
    : mAnimator(animator), mConst(pConst), mJudgeWaterSurfaceRun(judge), mEffect(effect),
      _30(isMoon), mMoveAnimName(isMoon ? "MoveMoon" : "Move") {}

void PlayerAnimControlRun::reset(float a2, bool a3) {
    _20 = !a3 && (mConst->getNormalMaxSpeed() * 0.9f) > a2;
    _24 = 0;
    _28 = 0;
    _2c = 0.0;
}

bool PlayerAnimControlRun::isAnimDashFast() const {
    return mAnimator->isAnim(mMoveAnimName) && customDashBlendWeight > 0.5f;
}

void PlayerAnimControlRun::update(float a2, sead::Vector3f const& a3) {
    f32 v8 = mAnimator->getRunStartAnimFrameMax() * mConst->getRunStartPlayFrameScale();
    s32 v9 = (s32) v8;
    if(a3.length() >= 0.95 && _20 && mConst->getDashJudgeSpeed() > a2 && _24 < (s32)v8) {
        _28 = al::converge(_28, mConst->getRunStartBlendFrame(), 1);
    } else {
        _28 = al::converge(_28, 0, 1);
    }

    _24 = sead::Mathi::clampMax(_24+1, v9);

    if (!mAnimator->isAnim(mMoveAnimName))
        mAnimator->startAnim(mMoveAnimName);
    if (!mAnimator->isAnim(mMoveAnimName))
        return;

    f32 v22 = al::calcRate01(mConst->getAnimFrameRateRunStart(), 0.0f, mConst->getRunStartBlendFrame());
    
    bool v24;
    if(v22 <= 0.5f) {
        if(!mJudgeWaterSurfaceRun || !rs::isJudge(mJudgeWaterSurfaceRun)) {
            v24 = true;
        } else {
            mEffect->tryStartRunEffectDashWaterSurface();
            v24 = false;
        }
    } else {
        mEffect->tryStartRunEffectRunStart();
        v24 = false;
    }

    f32 v25 = 1.0f - v22;
    f32 v27 = mConst->getDashFastBorderSpeed() - mConst->getDashFastBlendRange();
    if(v27 < a2) {
        f32 v36 = mConst->getDashFastBorderSpeed();
        f32 v38 = mConst->getDashFastBlendRange();
        f32 v40 = 0.0f;
        if(!al::isNearZero(v38, 0.001f)) {
            v40 = sead::Mathf::clamp((v38 + a2 - v36) / (v38 + v38), 0.0f, 1.0f);
        }

        f32 weight3 = v25 * v40;
        customDashBlendWeight = weight3;
    } else {
        customDashBlendWeight = 0.0f;
    }
}
