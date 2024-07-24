#include "Player/PlayerCollider.h"
#include <typeinfo>
#include "CUSTOM/CollisionMultiShape.h"
#include "Library/Collision/CollisionUtil.h"
#include "Library/Collision/KTriangle.h"
#include "Library/Math/MathAngleUtil.h"
#include "Library/Math/MathLengthUtil.h"
#include "Library/Math/MathUtil.h"
#include "Player/CollisionShapeKeeper.h"
#include "Player/PlayerCollider.h"
#include "Stuff.h"
#include "math/seadMathCalcCommon.h"
#include "math/seadMatrix.h"
#include "math/seadVectorFwd.h"

PlayerCollider::~PlayerCollider() {
    delete info1;
    delete info2;
    delete info3;

    delete mCollisionMultiShape;
    delete[] someHitInfos;

    // assume only three elements from ctor in array
    if (anotherPtrArray.size() != 3)
        CRASH
    for (int i = 0; i < anotherPtrArray.size(); i++)
        delete anotherPtrArray[i];

    ptrArraysChangeMe[0].freeBuffer();
    ptrArraysChangeMe[1].freeBuffer();
    ptrArraysChangeMe[2].freeBuffer();
    anotherPtrArray.freeBuffer();

    delete[] someThreeFloats;
    delete[] anotherThreeFloats;
}

PlayerCollider::PlayerCollider(al::CollisionDirector* a2, sead::Matrix34f const* a3,
                               sead::Vector3f const* a4, sead::Vector3f const* a5, bool a6) {
    PlayerCollider* a1 = this;
    al::HitInfo* v8;                              // x23
    al::HitInfo* v9;                              // x23
    al::HitInfo* v10;                             // x23
    int v13;                                      // w2
    al::HitInfo* v14;                             // x21
    float* v15;                                   // x0
    float* v16;                                   // x0
    al::HitInfo* v17;                             // x20
    al::HitInfo* v19;                             // x20
    float* someThreeFloats;                       // x8
    float* anotherThreeFloats;                    // x8
    al::HitInfo* v23;                             // x20
    float* v25;                                   // x8
    float* v26;                                   // x8
    float* v27;                                   // x8
    float* v28;                                   // x8
    float* v29;                                   // x8
    CollisionShapeKeeper* mCollisionShapeKeeper;  // x8
    float v31;                                    // s0
    const sead::Matrix34f* mMtxPtr;               // x8
    long double result;                           // q0

    a1->mMtxPtr = a3;
    a1->mTransPtr = a4;
    a1->mGravityPtr = a5;
    a1->mCollisionDirector = a2;
    a1->mTrans = *a4;
    a1->mSize = 0.0;
    mMtx = sead::Matrix34f::ident;
    a1->info1 = new al::HitInfo{};
    a1->val1 = 0.0;
    a1->info2 = new al::HitInfo{};
    a1->val2 = 0.0;
    a1->flag1 = 0;
    a1->flag2 = 0;
    a1->val3 = 0.0;
    a1->unk3.x = 0.0;
    a1->unk3.y = 0.0;
    a1->unk3.z = 0.0;
    a1->info3 = new al::HitInfo{};
    a1->mCollisionHitNormal.z = 0.0;
    a1->mCollisionHitNormal.x = 0.0;
    a1->mCollisionHitNormal.y = 0.0;
    a1->mCollisionHitPos.z = 0.0;
    a1->mTimeInAir = 0;
    a1->mCollisionHitPos.x = 0.0;
    a1->mCollisionHitPos.y = 0.0;
    mCollidePosMtx = sead::Matrix34f::ident;
    a1->mCollisionShapeScale = 1.0;
    a1->mCollisionShapeKeeper = 0LL;
    a1->mCollisionMultiShape = 0LL;
    a1->someBitField = 0;
    a1->mIsInFastMoveCollisionArea = 0;
    a1->mIsValidGroundSupport = 1;
    a1->mIsDuringRecovery = 0;
    a1->mCutCollideAffectDir.x = 0.0;
    a1->mCutCollideAffectDir.y = 0.0;
    a1->mCutCollideAffectDir.z = 0.0;
    a1->mWallBorderCheckType = 1;
    a1->someThreeFloats = 0LL;
    a1->sizeOfArrayBelowIs3_2 = 0;
    a1->anotherThreeFloats = 0LL;
    memset(&a1->mCollisionPartsFilter, 0, 0x44uLL);
    a1->sizeOfArrayBelowIs3 = 0;
    a1->mCollidedGroundPos.z = 0.0;
    a1->mCollidedGroundPos.x = 0.0;
    a1->mCollidedGroundPos.y = 0.0;
    a1->mCollidedGroundNormal.z = 0.0;
    a1->mCollidedGroundNormal.x = 0.0;
    a1->mCollidedGroundNormal.y = 1.0;
    a1->unk11 = 70.0;

    a1->mCollisionMultiShape = new CollisionMultiShape(this, a6 ? 256 : 128);
    a1->someHitInfos = new al::HitInfo[64];
    a1->ptrArraysChangeMe[0].allocBuffer(64, nullptr);
    a1->ptrArraysChangeMe[1].allocBuffer(64, nullptr);
    a1->ptrArraysChangeMe[2].allocBuffer(64, nullptr);
    a1->anotherPtrArray.allocBuffer(3, nullptr);

    a1->sizeOfArrayBelowIs3 = 3;
    a1->someThreeFloats = new float[3];

    a1->sizeOfArrayBelowIs3_2 = 3;
    a1->anotherThreeFloats = new float[3];

    anotherPtrArray.pushBack(new al::HitInfo());

    *a1->someThreeFloats = -99999.0;
    *a1->anotherThreeFloats = 0.0;

    anotherPtrArray.pushBack(new al::HitInfo());

    if (a1->sizeOfArrayBelowIs3 <= 1u)
        someThreeFloats = a1->someThreeFloats;
    else
        someThreeFloats = a1->someThreeFloats + 1;

    *someThreeFloats = -99999.0;
    if (a1->sizeOfArrayBelowIs3_2 <= 1u)
        anotherThreeFloats = a1->anotherThreeFloats;
    else
        anotherThreeFloats = a1->anotherThreeFloats + 1;

    *anotherThreeFloats = 0.0;

    anotherPtrArray.pushBack(new al::HitInfo());

    if (a1->sizeOfArrayBelowIs3 <= 2u)
        v25 = a1->someThreeFloats;
    else
        v25 = a1->someThreeFloats + 2;

    *v25 = -99999.0;
    if (a1->sizeOfArrayBelowIs3_2 <= 2u)
        v26 = a1->anotherThreeFloats;
    else
        v26 = a1->anotherThreeFloats + 2;

    *v26 = 0.0;
    v27 = a1->someThreeFloats;
    a1->val3 = -99999.0;
    a1->unk3.x = 0.0;
    a1->unk3.y = 0.0;
    a1->unk3.z = 0.0;
    a1->val1 = -99999.0;
    a1->val2 = -99999.0;
    if (a1->sizeOfArrayBelowIs3 <= 1u)
        v28 = a1->someThreeFloats;
    else
        v28 = a1->someThreeFloats + 1;

    *v28 = -99999.0;
    if (a1->sizeOfArrayBelowIs3 <= 2u)
        v29 = a1->someThreeFloats;
    else
        v29 = a1->someThreeFloats + 2;

    *v29 = -99999.0;
    a1->mTrans = *a1->mTransPtr;
    mCollisionShapeKeeper = a1->mCollisionShapeKeeper;
    if (mCollisionShapeKeeper)
        v31 = mCollisionShapeKeeper->mBoundingRadius * a1->mCollisionShapeScale;
    else
        v31 = 0.0;

    mMtxPtr = a1->mMtxPtr;
    a1->mSize = v31;
    mMtx = *mMtxPtr;
    a1->mTimeInAir = 2;
}

void PlayerCollider::onInvalidate() {
    float* someThreeFloats;                       // x9
    float* v2;                                    // x9
    float* v3;                                    // x9
    CollisionShapeKeeper* mCollisionShapeKeeper;  // x8
    float v5;                                     // s0
    const sead::Matrix34f* mMtxPtr;               // x8
    long double result;                           // q0

    someThreeFloats = this->someThreeFloats;
    this->val3 = -99999.0;
    this->unk3.x = 0.0;
    this->unk3.y = 0.0;
    this->unk3.z = 0.0;
    this->val1 = -99999.0;
    this->val2 = -99999.0;
    *someThreeFloats = -99999.0;
    if (this->sizeOfArrayBelowIs3 <= 1u)
        v2 = this->someThreeFloats;
    else
        v2 = this->someThreeFloats + 1;

    *v2 = -99999.0;
    if (this->sizeOfArrayBelowIs3 <= 2u)
        v3 = this->someThreeFloats;
    else
        v3 = this->someThreeFloats + 2;

    *v3 = -99999.0;
    this->mTrans = *this->mTransPtr;
    mCollisionShapeKeeper = this->mCollisionShapeKeeper;
    if (mCollisionShapeKeeper)
        v5 = mCollisionShapeKeeper->mBoundingRadius * this->mCollisionShapeScale;
    else
        v5 = 0.0;

    mMtxPtr = this->mMtxPtr;
    this->mSize = v5;
    this->mMtx = *mMtxPtr;
    this->mTimeInAir = 2;
}

void PlayerCollider::setCollisionShapeKeeper(CollisionShapeKeeper* a2) {
    CollisionShapeKeeper* mCollisionShapeKeeper;  // x8

    mCollisionShapeKeeper = this->mCollisionShapeKeeper;
    if (mCollisionShapeKeeper) {
        if (mCollisionShapeKeeper != a2)
            this->mSize = mCollisionShapeKeeper->mBoundingRadius * this->mCollisionShapeScale;

        this->mCollisionShapeKeeper = a2;
    } else {
        this->mSize = a2->mBoundingRadius;
        this->mCollisionShapeKeeper = a2;
    }
}

void PlayerCollider::calcBoundingRadius(float* radius) const {
    *radius = mCollisionShapeKeeper->mBoundingRadius * mCollisionShapeScale;
}

void PlayerCollider::setCollisionShapeScale(float scale) {
    if (mCollisionShapeKeeper) {
        f32 unk = mCollisionShapeKeeper->mBoundingRadius * mCollisionShapeScale;
        if (mSize < unk)
            unk = mSize;
        mSize = unk;
        mCollisionShapeScale = scale;
    } else {
        mCollisionShapeScale = scale;
    }
}

void PlayerCollider::onCutCollideAffectDir(sead::Vector3f const& dir) {
    mCutCollideAffectDir = dir;
}

void PlayerCollider::offCutCollideAffectDir() {
    mCutCollideAffectDir = {0.0f, 0.0f, 0.0f};
}

void PlayerCollider::clear() {
    CRASH
}

void PlayerCollider::calcCheckPos(sead::Vector3f*) const {
    CRASH
}

void PlayerCollider::resetPose(sead::Quatf const&){
    CRASH} sead::Vector3f PlayerCollider::collide(sead::Vector3f const& velocity) {
    PlayerCollider* a1 = this;
    float mBoundingRadius;                    // s8
    float mCollisionShapeScale;               // s9
    sead::Vector3f* FaceNormal;               // x8
    float* someThreeFloats;                   // x8
    float* v8;                                // x8
    float* v9;                                // x8
    float mCheckStepRange;                    // s11
    float newSize;                            // s8
    bool skipFirstStep;                       // w7
    float checkStepRange;                     // s1
    sead::Matrix34f* mMtxPtr;                 // x8
    float val1;                               // s0
    int mTimeInAir;                           // w8
    sead::Vector3f* CollisionMovingReaction;  // x21
    sead::Vector3f* CollisionHitNormal;       // x0
    float v26;                                // w9
    float v27;                                // w10
    float v28;                                // w11
    float v29;                                // w12
    float v30;                                // w8
    sead::Vector3f* v31;                      // x21
    sead::Vector3f* v32;                      // x0
    al::HitInfo* info3;                       // x0
    sead::Vector3f* v34;                      // x0
    float v35;                                // w8
    al::HitInfo* v36;                         // x0
    const sead::Vector3f* v37;                // x21
    const sead::Vector3f* v38;                // x0
    al::HitInfo* info2;                       // x0
    const sead::Vector3f* v40;                // x0
    float v41;                                // w8
    al::HitInfo* v42;                         // x0
    sead::Matrix34f* v43;                     // x8
    const sead::Vector3f* mTransPtr;          // x9
    float v48;                                // s2
    float v49;                                // s0
    float v50;                                // s1
    float v51;                                // s3
    float v52;                                // s4
    float v53;                                // s5
    float v54;                                // s0
    float v55;                                // s3
    float v56;                                // s2
    float v57;                                // s4
    float v58;                                // s4
    float v59;                                // s3
    sead::Vector3f v60;                       // [xsp+0h] [xbp-140h] BYREF
    sead::Vector3f transPlusVelocity;         // [xsp+10h] [xbp-130h] BYREF
    sead::Vector3f finalDiff;                 // [xsp+20h] [xbp-120h] BYREF
    sead::Vector3f movePower;                 // [xsp+30h] [xbp-110h] BYREF
    sead::Quatf destQuat;                     // [xsp+40h] [xbp-100h] BYREF
    sead::Quatf curQuat;                      // [xsp+50h] [xbp-F0h] BYREF
    sead::Vector3f curTrans;                  // [xsp+60h] [xbp-E0h] BYREF
    sead::Vector3f destTrans;                 // [xsp+70h] [xbp-D0h] BYREF
    al::Triangle dest;                        // [xsp+80h] [xbp-C0h] OVERLAPPED BYREF
    sead::Vector3f finalTrans;                // [xsp+80h] [xbp-C0h] FORCED BYREF
    float mSize;                              // [xsp+FCh] [xbp-44h] BYREF
    sead::Vector3f result;                    // 0:s0.4,4:s1.4,8:s2.4

    a1->ptrArraysChangeMe[0].clear();
    a1->ptrArraysChangeMe[1].clear();
    a1->ptrArraysChangeMe[2].clear();
    a1->numHitInfosAbove = 0;
    a1->someBitField = 0;
    a1->flag1 = 0;
    a1->flag2 = 0;
    a1->mCollisionHitPos.y = 0.0;
    a1->mCollisionHitPos.z = 0.0;
    a1->mCollisionHitNormal.z = 0.0;
    a1->mCollisionHitPos.x = 0.0;
    a1->mCollisionHitNormal.x = 0.0;
    a1->mCollisionHitNormal.y = 0.0;
    destTrans.x = 0.0;
    destTrans.y = 0.0;
    destTrans.z = 0.0;
    destTrans = *a1->mTransPtr;
    curTrans = a1->mTrans;
    mSize = a1->mSize;
    curQuat.x = 0.0;
    curQuat.y = 0.0;
    curQuat.z = 0.0;
    curQuat.w = 1.0;
    sead::Matrix34CalcCommon<float>::toQuat(curQuat, a1->mMtx);
    destQuat.x = 0.0;
    destQuat.y = 0.0;
    destQuat.z = 0.0;
    destQuat.w = 1.0;
    sead::Matrix34CalcCommon<float>::toQuat(destQuat, *a1->mMtxPtr);
    mBoundingRadius = a1->mCollisionShapeKeeper->mBoundingRadius;
    mCollisionShapeScale = a1->mCollisionShapeScale;
    movePower.x = 0.0;
    movePower.y = 0.0;
    movePower.z = 0.0;
    if (a1->val1 >= 0.0 && alCollisionUtil::isCollisionMoving(a1->info1)) {
        CRASH
        /*memcpy(&dest, a1->info1, sizeof(dest));
        al::Triangle::calcForceMovePower(&dest, &movePower, &destTrans);
        FaceNormal = al::Triangle::getFaceNormal(&dest);
        if ( (float)((float)((float)(FaceNormal->x * movePower.x) + (float)(FaceNormal->y *
        movePower.y))
                   + (float)(FaceNormal->z * movePower.z)) > 0.0 )
          al::verticalizeVec(&movePower, FaceNormal, &movePower);*/
    }

    someThreeFloats = a1->someThreeFloats;
    a1->unk3.y = 0.0;
    a1->unk3.z = 0.0;
    a1->val3 = -99999.0;
    a1->unk3.x = 0.0;
    a1->val1 = -99999.0;
    a1->val2 = -99999.0;
    *someThreeFloats = -99999.0;
    if (a1->sizeOfArrayBelowIs3 <= 1u)
        v8 = a1->someThreeFloats;
    else
        v8 = a1->someThreeFloats + 1;

    *v8 = -99999.0;
    if (a1->sizeOfArrayBelowIs3 <= 2u)
        v9 = a1->someThreeFloats;
    else
        v9 = a1->someThreeFloats + 2;

    *v9 = -99999.0;
    mCheckStepRange = a1->mCollisionShapeKeeper->mCheckStepRange;
    finalTrans = destTrans + movePower;
    newSize = mBoundingRadius * mCollisionShapeScale;
    finalDiff = (destTrans + movePower) - curTrans;
    if (al::isNearZero(finalDiff, 0.001) && al::isNearZero(a1->mSize - newSize, 0.001)) {
        skipFirstStep = 0;
    } else {
        PlayerCollider::moveCollide(&curTrans, &mSize, &curQuat, finalTrans, newSize, destQuat,
                                    finalDiff, fminf(mCheckStepRange * 0.99, 35.0), 0);
        skipFirstStep = 1;
    }

    checkStepRange = fminf(a1->mCollisionShapeKeeper->mCheckStepRange, 35.0);
    transPlusVelocity = curTrans + velocity;
    PlayerCollider::moveCollide(&curTrans, &mSize, &curQuat, transPlusVelocity, newSize, destQuat,
                                velocity, checkStepRange, skipFirstStep);
    v60 = curTrans - destTrans;
    mMtxPtr = (sead::Matrix34f*)a1->mMtxPtr;
    sead::Vector3f a1trans = a1->mTrans;
    a1->mTrans = destTrans + (curTrans - destTrans);
    a1->mSize = newSize;
    a1->mMtx = *mMtxPtr;
    val1 = a1->val1;
    if (val1 >= 0.0) {
        mTimeInAir = a1->mTimeInAir;
        if (mTimeInAir <= 99999)
            a1->mTimeInAir = mTimeInAir + 1;
    } else {
        a1->mTimeInAir = 0;
    }

    if (a1->flag1) {
        if (val1 >= 0.0 && rs::isCollisionCodePress(a1->info1)) {
            CRASH
            /*CollisionMovingReaction = alCollisionUtil::getCollisionMovingReaction(a1->info1);
            CollisionHitNormal = alCollisionUtil::getCollisionHitNormal(a1->info1);
            if ( al::isNearZeroOrGreater(
                   (float)((float)(CollisionMovingReaction->x * CollisionHitNormal->x)
                         + (float)(CollisionMovingReaction->y * CollisionHitNormal->y))
                 + (float)(CollisionMovingReaction->z * CollisionHitNormal->z),
                   0.001) )
            {
              v26 = a1->unk10.y;
              a1->mCollisionHitNormal.x = a1->unk10.x;
              a1->mCollisionHitNormal.y = v26;
              v27 = a1->unk10.z;
              v28 = a1->unk9.x;
              v29 = a1->unk9.y;
              v30 = a1->unk9.z;
              a1->flag2 = 0;
              a1->mCollisionHitNormal.z = v27;
              a1->mCollisionHitPos.x = v28;
              a1->mCollisionHitPos.y = v29;
              a1->mCollisionHitPos.z = v30;
              goto LABEL_29;
            }
            */
        }

        else if (a1->val3 >= 0.0 && rs::isCollisionCodePress(a1->info3)) {
            CRASH
            /*
            v31 = alCollisionUtil::getCollisionMovingReaction(a1->info3);
            v32 = alCollisionUtil::getCollisionHitNormal(a1->info3);
            if ( al::isNearZeroOrGreater(
                   (float)((float)(v31->x * v32->x) + (float)(v31->y * v32->y)) + (float)(v31->z *
            v32->z), 0.001) )
            {
              info3 = a1->info3;
              a1->flag2 = 0;
              v34 = alCollisionUtil::getCollisionHitNormal(info3);
              a1->mCollisionHitNormal.x = v34->x;
              a1->mCollisionHitNormal.y = v34->y;
              v35 = v34->z;
              v36 = a1->info3;
              a1->mCollisionHitNormal.z = v35;
              a1->mCollisionHitPos = *alCollisionUtil::getCollisionHitPos(v36);
              goto LABEL_29;
            }
            */
        }

        a1->flag1 = 0;
    }

LABEL_29:
    if (a1->flag2) {
        if (a1->val2 >= 0.0 && rs::isCollisionCodePress(a1->info2) &&
            (v37 = &alCollisionUtil::getCollisionMovingReaction(a1->info2),
             v38 = &alCollisionUtil::getCollisionHitNormal(a1->info2),
             (float)((float)((float)(v37->x * v38->x) + (float)(v37->y * v38->y)) +
                     (float)(v37->z * v38->z)) > 0.0)) {
            info2 = a1->info2;
            a1->flag1 = 0;
            v40 = &alCollisionUtil::getCollisionHitNormal(info2);
            a1->mCollisionHitNormal.x = v40->x;
            a1->mCollisionHitNormal.y = v40->y;
            v41 = v40->z;
            v42 = a1->info2;
            a1->mCollisionHitNormal.z = v41;
            a1->mCollisionHitPos = alCollisionUtil::getCollisionHitPos(v42);
        } else {
            a1->flag2 = 0;
        }
    }

    if (a1->mIsDuringRecovery) {
        v43 = (sead::Matrix34f*)a1->mMtxPtr;
        mTransPtr = a1->mTransPtr;
        a1->mTrans.x = mTransPtr->x;
        a1->mTrans.y = mTransPtr->y;
        a1->mTrans.z = mTransPtr->z;
        a1->mTrans.x = mTransPtr->x + velocity.x;
        a1->mTrans.y = mTransPtr->y + velocity.y;
        a1->mTrans.z = mTransPtr->z + velocity.z;
        a1->mSize = newSize;
        a1->mMtx = *v43;
        v60 = velocity;
    } else {
        if (al::isNearZero(a1->mCutCollideAffectDir, 0.001)) {
            v51 = destTrans.x;
            v52 = destTrans.y;
            v53 = destTrans.z;
        } else {
            al::verticalizeVec(&v60, a1->mCutCollideAffectDir, v60);
            v57 = mCutCollideAffectDir.dot(velocity);
            v60.x += (float)(v57 * a1->mCutCollideAffectDir.x);
            v60.y += (float)(v57 * a1->mCutCollideAffectDir.y);
            v60.z += (float)(v57 * a1->mCutCollideAffectDir.z);
            v51 = destTrans.x;
            a1->mTrans.x = destTrans.x + v49;
            v52 = destTrans.y;
            a1->mTrans.y = destTrans.y + v50;
            v53 = destTrans.z;
            a1->mTrans.z = destTrans.z + v48;
        }

        a1->unk3.x = (float)(curTrans.x - a1trans.x) -
                     (float)((float)((float)(v51 - a1trans.x) + movePower.x) + velocity.x);
        a1->unk3.y = (float)(curTrans.y - a1trans.y) -
                     (float)((float)((float)(v52 - a1trans.y) + movePower.y) + velocity.y);
        a1->unk3.z = (float)(curTrans.z - a1trans.z) -
                     (float)((float)((float)(v53 - a1trans.z) + movePower.z) + velocity.z);
    }

    result = v60;
    printf("Collide: (%f, %f, %f) => (%f, %f, %f)\n", velocity.x, velocity.y, velocity.z, result.x,
           result.y, result.z);
    return result;
}

bool PlayerCollider::calcMovePowerByContact(sead::Vector3f*, sead::Vector3f const&) {
    CRASH return false;
}

void PlayerCollider::moveCollide(sead::Vector3f* trans, float* size, sead::Quatf* quat,
                                 sead::Vector3f const& newTrans, float newSize,
                                 sead::Quatf const& newQuat, sead::Vector3f const& velocity,
                                 float checkStepRange, bool skipFirstStep) {
    al::SpherePoseInterpolator interp = {};
    interp.startInterp(*trans, newTrans, *size, newSize, *quat, newQuat, checkStepRange);
    if (skipFirstStep)
        interp.nextStep();

    sead::Vector3f a4a = {0.0f, 0.0f, 0.0f};
    if ((PlayerCollider::findCollidePos(&interp) & 1) != 0) {
        int v41 = 0;
        int v27;
        sead::Vector3f v17v = {0.0f, 0.0f, 0.0f};
        do {
            sead::Vector3f remainMoveVec = {0.0f, 0.0f, 0.0f};
            interp.calcInterp(trans, size, quat, &remainMoveVec);
            sead::Vector3f a1a = {0.0f, 0.0f, 0.0f};
            sead::Vector3f x2_0 = {0.0f, 0.0f, 0.0f};
            printf("before calcResultVec: progress=%f\n", interp.mCurrentStep);
            PlayerCollider::calcResultVec(&a1a, &x2_0, a4a);
            *trans += a1a;

            sead::Vector3f v33v;

            if (interp.mCurrentStep >= 1.0)
                goto LABEL_47;

            f32 v29;
            if (al::isNearZero(a1a, 0.0000001f) || (v29 = a1a.length(), v29 <= 0.0)) {
                v33v = {0.0f, 0.0f, 0.0f};
            } else {
                v33v = (1.0f / v29) * a1a;
                f32 v36 = v33v.dot(remainMoveVec);
                if (v36 >= 0.0) {
                    if (v36 < v29)
                        v29 = v33v.dot(remainMoveVec);

                    remainMoveVec -= v33v * v29;
                } else {
                    remainMoveVec -= v33v * v36;
                }
            }

            f32 v40;
            if (((v40 = velocity.dot(remainMoveVec), v40 >= 0.0) || al::isNearZero(v40, 0.001f)) &&
                (!al::isNearZero(remainMoveVec, 0.001f) || v17v.dot(v33v) >= 0.0)) {
                sead::Vector3f a2a = *trans - a1a;
                sead::Vector3f a3a = *trans + remainMoveVec;
                interp.startInterp(a2a, a3a, *size, newSize, *quat, newQuat, checkStepRange);
                interp.nextStep();
                a2a = {0.0f, 0.0f, 0.0f};
                interp.calcInterpPos(&a2a);
                a4a = *trans - a1a - a2a + x2_0;
                if (mIsInFastMoveCollisionArea) {
                    if ((someBitField & 0x100) != 0 && a4a.x < 0.0 && x2_0.x < 0.0 ||
                        (someBitField & 0x80) != 0 && a4a.x > 0.0 && x2_0.x > 0.0)
                        a4a.x = 0.0;

                    if ((someBitField & 0x400) != 0 && a4a.y < 0.0 && x2_0.y < 0.0 ||
                        (someBitField & 0x200) != 0 && a4a.y > 0.0 && x2_0.y > 0.0)
                        a4a.y = 0.0;

                    if ((someBitField & 0x1000) != 0 && a4a.z < 0.0 && x2_0.z < 0.0 ||
                        (someBitField & 0x800) != 0 && a4a.z > 0.0 && x2_0.z > 0.0)
                        a4a.z = 0.0;
                }

                if ((PlayerCollider::findCollidePos(&interp) & 1) != 0) {
                    if (v41 <= 99)
                        v27 = 0;
                    else
                        v27 = 3;

                    ++v41;
                } else {
                    interp.calcInterp(trans, size, quat, 0LL);
                    v27 = 3;
                }
            } else {
            LABEL_47:
                v27 = 3;
                v33v = v17v;
            }

            v17v = v33v;
        } while (!v27);
    } else {
        interp.calcInterp(trans, size, quat, 0LL);
    }

    printf("PostMoveCollide: (%.020f, %.020f, %.020f), %.02f, (%.02f, %.02f, %.02f, %.02f), (%.020f, "
           "%.020f, %.020f), %.02f, (%.02f, %.02f, %.02f, %.02f), (%.02f, %.02f, %.02f), %.02f, %s\n",
           trans->x, trans->y, trans->z, *size, quat->x, quat->y, quat->z, quat->w, newTrans.x,
           newTrans.y, newTrans.z, newSize, newQuat.x, newQuat.y, newQuat.z, newQuat.w, velocity.x,
           velocity.y, velocity.z, checkStepRange, skipFirstStep ? "true" : "false");
}

bool PlayerCollider::findCollidePos(al::SpherePoseInterpolator* interp) {
    while (interp->mPrevStep != 1.0 || interp->mCurrentStep != 1.0) {
        sead::Vector3f trans = {0.0f, 0.0f, 0.0f};
        f32 size = 0.0;
        sead::Quatf quat = {1.0f, 0.0f, 0.0f, 0.0f};
        sead::Vector3f remainMoveVec = {0.0f, 0.0f, 0.0f};
        interp->calcInterp(&trans, &size, &quat, &remainMoveVec);
        f32 scale = interp->calcRadiusBaseScale(size) * this->mCollisionShapeScale;
        mCollidePosMtx.makeQT(quat, trans);
        if (mCollisionMultiShape->check(mCollisionShapeKeeper, &mCollidePosMtx, scale,
                                        remainMoveVec, nullptr))
            return true;

        interp->nextStep();
    }

    return false;
}

void PlayerCollider::calcResultVec(sead::Vector3f* a2, sead::Vector3f* a3,
                                   sead::Vector3f const& a4) {
    int mNumCollideResult;                           // w19
    sead::BitFlag<u32>* p_someBitField;              // x22
    unsigned int v11;                                // w24
    const CollidedShapeResult* collidedShapeResult;  // x25
    const al::HitInfo* ArrowHitInfo;                 // x0
    float v14;                                       // s10
    const sead::Vector3f* v15;                       // x25
    float v16;                                       // s11
    float v17;                                       // s0
    float v18;                                       // s1
    const al::SphereHitInfo* SphereHitInfo;          // x0
    float v22;                                       // s10
    const al::Triangle* v23;                         // x25
    const sead::Vector3f* v24;                       // x25
    float v25;                                       // s11
    float v29;                                       // s0
    const al::DiskHitInfo* DiskHitInfo;              // x0
    float unk11;                                     // s10
    const al::Triangle* p_mTriangle;                 // x25
    const sead::Vector3f* FaceNormal;                // x25
    float v35;                                       // s11
    float v36;                                       // s0
    float v37;                                       // s1
    bool v38;                                        // nf
    float v39;                                       // s0
    float v40;                                       // s11
    unsigned int i;                                  // w26
    const CollidedShapeResult* v42;                  // x27
    float x;                                         // s2
    float y;                                         // s4
    float z;                                         // s0
    float v46;                                       // s3
    float v47;                                       // s5
    float v48;                                       // s18
    float v49;                                       // w8
    float v50;                                       // s1
    float v51;                                       // s17
    float v52;                                       // s6
    float v53;                                       // s9
    float v54;                                       // s11
    float v55;                                       // s14
    float v56;                                       // s10
    float v57;                                       // s12
    float v58;                                       // s3
    float v59;                                       // s2
    float v60;                                       // s15
    float v62;                                       // s1
    float v63;                                       // s0
    float v67;                                       // s0
    float v68;                                       // s1
    bool v69;                                        // zf
    float v70;                                       // s0
    float v72;                                       // s0
    float v73;                                       // s1
    bool v74;                                        // zf
    float v75;                                       // s0
    float v77;                                       // s0
    float v78;                                       // s1
    bool v79;                                        // zf
    float v80;                                       // s0
    float v81;                                       // s10
    float v82;                                       // s9
    float v84;                                       // s0
    float v85;                                       // s10
    float v88;                                       // s1
    float v89;                                       // s0
    float v90;                                       // s1
    float v91;                                       // s0
    bool v92;                                        // w27
    bool v93;                                        // w23
    bool v94;                                        // w22
    int v98;                                         // w19
    int v99;                                         // w28
    const sead::Vector3f* CollisionHitPos;           // x0
    const sead::Vector3f* CollisionHitNormal;        // x0
    const sead::Vector3f* v107;                      // x0
    const CollisionShapeKeeper* v110;                // x8
    float v117;                                      // s0
    s16 v121;                                        // w8

    float v86;   // s12
    float v87;   // s13
    float v126;  // [xsp+14h] [xbp-16Ch]

    float v128;           // [xsp+20h] [xbp-160h]
    float v129;           // [xsp+24h] [xbp-15Ch]
    sead::Vector3f v130;  // [xsp+28h] [xbp-158h] BYREF
    sead::Vector3f v131;  // [xsp+38h] [xbp-148h] BYREF
    sead::Vector3f a1;    // [xsp+48h] [xbp-138h] BYREF
    sead::Vector3f vert;  // [xsp+58h] [xbp-128h] BYREF
    sead::Vector3f v134;  // [xsp+68h] [xbp-118h] BYREF
    sead::Vector3f v135;  // [xsp+78h] [xbp-108h] BYREF
    sead::Vector3f v136;  // [xsp+88h] [xbp-F8h] BYREF
    sead::Vector3f v137;  // [xsp+98h] [xbp-E8h] BYREF
    sead::Vector3f v138;  // [xsp+A8h] [xbp-D8h] BYREF
    sead::Vector3f v139;  // [xsp+B8h] [xbp-C8h] BYREF
    bool v140;            // [xsp+C8h] [xbp-B8h] BYREF
    bool v141;            // [xsp+CCh] [xbp-B4h] BYREF
    sead::Vector3f v142;  // [xsp+D0h] [xbp-B0h] BYREF
    sead::Vector3f a2a;   // [xsp+E0h] [xbp-A0h] BYREF
    sead::Vector3f v111v;
    sead::Vector3f v114v;
    sead::Vector3f v118v;
    sead::Vector3f v61v;
    sead::Vector3f v95v;

    v142 = *this->mGravityPtr;
    this->someBitField = 0;
    mNumCollideResult = mCollisionShapeKeeper->mNumCollideResult;
    p_someBitField = &this->someBitField;
    for (v11 = 0; v11 < mNumCollideResult; v11++) {
        collidedShapeResult = mCollisionShapeKeeper->getCollidedShapeResult(v11);
        if (collidedShapeResult->isArrow()) {
            ArrowHitInfo = &collidedShapeResult->getArrowHitInfo();
            v14 = this->unk11;
            v15 = &ArrowHitInfo->mTriangle.getFaceNormal();
            if (al::isNearZero(*v15, 0.001))
                continue;

            v16 = v15->dot(v142);
            v17 = cosf(sead::Mathf::deg2rad(v14));
            v18 = sead::Mathf::abs(v16);
            if (v16 >= 0.0 || v18 < v17)
                continue;

            *p_someBitField = *p_someBitField | 0x40;
        } else if (collidedShapeResult->isSphere()) {
            SphereHitInfo = &collidedShapeResult->getSphereHitInfo();
            v22 = this->unk11;
            v23 = &SphereHitInfo->mTriangle;
            if (!SphereHitInfo->isCollisionAtFace())
                continue;

            v24 = &v23->getFaceNormal();
            if (al::isNearZero(*v24, 0.001) ||
                (v25 = v24->dot(v142),
                 v25 < 0.0 && (sead::Mathf::abs(v25) < cosf(sead::Mathf::deg2rad(v22)))))
                if (al::isNearZero(*v24, 0.001) ||
                    (sead::Mathf::abs(v24->dot(v142)) >= cosf(sead::Mathf::deg2rad(v22))))
                    *p_someBitField = *p_someBitField | 4;
                else
                    *p_someBitField = *p_someBitField | 2;
            else
                *p_someBitField = *p_someBitField | 1;
        } else if (collidedShapeResult->isDisk()) {
            DiskHitInfo = &collidedShapeResult->getDiskHitInfo();
            unk11 = this->unk11;
            p_mTriangle = &DiskHitInfo->mTriangle;
            if (!DiskHitInfo->isCollisionAtFace())
                continue;

            FaceNormal = &p_mTriangle->getFaceNormal();
            if (al::isNearZero(*FaceNormal, 0.001) ||
                (v35 = FaceNormal->dot(v142),
                 v35 < 0.0 ? (v38 = sead::Mathf::abs(FaceNormal->dot(v142)) <
                                    cosf(sead::Mathf::deg2rad(unk11))) :
                             (v38 = 1),
                 v38))
                if (al::isNearZero(*FaceNormal, 0.001) ||
                    (sead::Mathf::abs(FaceNormal->dot(v142)) >= cosf(sead::Mathf::deg2rad(unk11))))
                    *p_someBitField = *p_someBitField | 0x20;
                else
                    *p_someBitField = *p_someBitField | 0x10;
            else
                *p_someBitField = *p_someBitField | 8;
        }
    }

LABEL_51:
    v141 = 0;
    v140 = 0;
    PlayerCollider::calcGroundArrowAverage(&v141, &this->mCollidedGroundPos, &v140,
                                           &this->mCollidedGroundNormal, mCollisionShapeKeeper);

    v139 = {0.0f, 0.0f, 0.0f};
    v138 = {0.0f, 0.0f, 0.0f};
    v137 = {0.0f, 0.0f, 0.0f};
    v136 = {0.0f, 0.0f, 0.0f};
    for (i = 0; i != mNumCollideResult; ++i) {
        v42 = mCollisionShapeKeeper->getCollidedShapeResult(i);

        if (v42->isArrow())
            PlayerCollider::calcResultVecArrow(p_someBitField, &v136, &v137, &v138, &v139, v42);
        else if (v42->isSphere())
            PlayerCollider::calcResultVecSphere(p_someBitField, &v136, &v137, &v138, &v139, v42);
        else if (v42->isDisk())
            PlayerCollider::calcResultVecDisk(p_someBitField, &v136, &v137, &v138, &v139, v42);

        printf("after %d/%d (%s): v136=(%.02f, %.02f, %.02f), v137=(%.02f, %.02f, %.02f), "
               "v138=(%.02f, %.02f, %.02f), v139=(%.02f, %.02f, %.02f)\n",
               i + 1, mNumCollideResult,
               v42->isArrow()  ? "arrow" :
               v42->isSphere() ? "sphere" :
                                 "disk",
               v136.x, v136.y, v136.z, v137.x, v137.y, v137.z, v138.x, v138.y, v138.z, v139.x,
               v139.y, v139.z);
    }

    if (this->val1 >= 0.0) {
        if (!v141)
            this->mCollidedGroundPos = this->info1->mCollisionHitPos;

        if (!v140)
            this->mCollidedGroundNormal = this->info1->mTriangle.getFaceNormal();
    }

    z = v136.z;
    v48 = v136.y + v137.y;
    v126 = v136.x + v137.x;
    v49 = v136.x + v137.x;
    v50 = v137.z;

    x = sead::Mathf::min(v136.x, v138.x);
    y = sead::Mathf::min(v136.y, v138.y);
    v51 = sead::Mathf::min(v136.z, v138.z);

    v46 = sead::Mathf::max(v137.x, v138.x);
    v47 = sead::Mathf::max(v137.y, v138.y);
    v52 = sead::Mathf::max(v137.z, v138.z);

    v53 = sead::Mathf::min(x, v139.x);
    v54 = sead::Mathf::min(y, v139.y);
    v55 = sead::Mathf::min(v51, v139.z);

    v136.x = v53;
    v136.y = v54;
    v136.z = v55;

    v56 = sead::Mathf::max(v46, v139.x);
    v57 = sead::Mathf::max(v47, v139.y);
    v60 = sead::Mathf::max(v52, v139.z);

    v58 = v53 + v56;
    v59 = v54 + v57;
    v137.x = v56;
    v137.y = v57;
    v137.z = v60;
    if (v58 <= 0.0 || (v61v.x = v49, (*((u8*)p_someBitField + 1) & 1) == 0)) {
        v61v.x = v53 + v56;
        if (v58 < 0.0 && (*(u8*)p_someBitField & 0x80) != 0)
            v61v.x = v49;
    }

    v62 = z + v50;
    v63 = v60 + v55;
    if (v59 <= 0.0 || (v61v.y = v48, (*((u8*)p_someBitField + 1) & 4) == 0)) {
        v61v.y = v54 + v57;
        if (v59 < 0.0 && (*((u8*)p_someBitField + 1) & 2) != 0)
            v61v.y = v48;
    }

    v128 = v62;
    v129 = v48;
    if (v63 <= 0.0 || (v61v.z = v62, (*((u8*)p_someBitField + 1) & 0x10) == 0)) {
        v61v.z = v60 + v55;
        if (v63 < 0.0 && (*((u8*)p_someBitField + 1) & 8) != 0)
            v61v.z = v62;
    }

    if ((someBitField & 0x100) != 0) {
        if (v61v.x <= 0.0 || v61v.x <= a4.x || a4.x < 0.0 && !al::isNearZero(a4.x, 0.001))
            goto LABEL_128;

        v67 = v61v.x + a4.x;
        v68 = 0.5;
        v69 = (*(u8*)p_someBitField & 0x80) == 0;
    } else {
        if ((someBitField & 0x80) == 0 || v61v.x >= 0.0 || v61v.x >= a4.x ||
            a4.x > 0.0 && !al::isNearZero(a4.x, 0.001))
            goto LABEL_128;

        v67 = v61v.x + a4.x;
        v68 = 0.5;
        v69 = (*((u8*)p_someBitField + 1) & 1) == 0;
    }

    v70 = v67 * v68;
    if (v69)
        v70 = a4.x;

    v61v.x = v70;

LABEL_128:
    if ((someBitField & 0x400) != 0) {
        if (v61v.y <= 0.0 || v61v.y <= a4.y || a4.y < 0.0 && !al::isNearZero(a4.y, 0.001))
            goto LABEL_144;

        v72 = v61v.y + a4.y;
        v73 = 0.5;
        v74 = (*((u8*)p_someBitField + 1) & 2) == 0;
    } else {
        if ((someBitField & 0x200) == 0 || v61v.y >= 0.0 || v61v.y >= a4.y ||
            a4.y > 0.0 && !al::isNearZero(a4.y, 0.001))
            goto LABEL_144;

        v72 = v61v.y + a4.y;
        v73 = 0.5;
        v74 = (*((u8*)p_someBitField + 1) & 4) == 0;
    }

    v75 = v72 * v73;
    if (v74)
        v75 = a4.y;

    v61v.y = v75;

LABEL_144:
    if ((someBitField & 0x1000) != 0) {
        if (v61v.z <= 0.0 || v61v.z <= a4.z || a4.z < 0.0 && !al::isNearZero(a4.z, 0.001))
            goto LABEL_160;

        v77 = v61v.z + a4.z;
        v78 = 0.5;
        v79 = (*((u8*)p_someBitField + 1) & 8) == 0;
    } else {
        if ((someBitField & 0x800) == 0 || v61v.z >= 0.0 || v61v.z >= a4.z ||
            a4.z > 0.0 && !al::isNearZero(a4.z, 0.001))
            goto LABEL_160;

        v77 = v61v.z + a4.z;
        v78 = 0.5;
        v79 = (*((u8*)p_someBitField + 1) & 0x10) == 0;
    }

    v80 = v77 * v78;
    if (v79)
        v80 = a4.z;

    v61v.z = v80;

LABEL_160:
    v81 = v56 - v53;
    v82 = v57 - v54;
    v135 = {0.0f, 0.0f, 0.0f};
    v134 = {0.0f, 0.0f, 0.0f};
    a2a = {0.0f, 0.0f, 0.0f};
    if (!al::isNearZero(v81, 0.001)) {
        if (sead::Mathf::abs(v61v.x) < v81) {
            if (v61v.x <= 0.0)
                v84 = -(float)(v61v.x + v81);
            else
                v84 = v81 - v61v.x;

            a2a.x = v84;
        }
    }

    v85 = v60 - v55;
    v87 = v128;
    v86 = v129;
    if (!al::isNearZero(v82, 0.001)) {
        v88 = sead::Mathf::abs(v61v.y);

        if (v88 < v82) {
            if (v61v.y <= 0.0)
                v89 = -(float)(v61v.y + v82);
            else
                v89 = v82 - v61v.y;

            a2a.y = v89;
        }
    }

    if (!al::isNearZero(v85, 0.001)) {
        v90 = sead::Mathf::abs(v61v.z);

        if (v90 < v85) {
            if (v61v.z <= 0.0)
                v91 = -(float)(v61v.z + v85);
            else
                v91 = v85 - v61v.z;

            a2a.z = v91;
        }
    }

    if (al::isNearZero(a2a, 0.001)) {
        v92 = 0;
        v93 = 0;
        goto LABEL_214;
    }

    al::separateVectorParallelVertical(&v134, &v135, v142, a2a);
    v93 = !al::isNearZero(v134, 0.001);
    v94 = al::isNearZero(v135, 0.001);
    v92 = !v94;
    if (v94 && !v93) {
        v92 = 0;
        goto LABEL_214;
    }

    a2a = {0.0f, 0.0f, 0.0f};
    if (!v93 && !v94) {
        v95v = {0.0f, 0.0f, 0.0f};
        v98 = 0;
        v99 = 1;
        goto LABEL_200;
    }

    if (this->val1 >= 0.0 && rs::isCollisionCodePress(this->info1)) {
        v95v = this->mCollidedGroundPos;
        a2a = this->mCollidedGroundNormal;
        v99 = 1;
        v98 = 1;
        goto LABEL_200;
    }

    if (this->val3 >= 0.0 && rs::isCollisionCodePress(this->info3)) {
        CollisionHitPos = &alCollisionUtil::getCollisionHitPos(this->info3);
        CollisionHitNormal = &alCollisionUtil::getCollisionHitNormal(this->info3);
        a2a = *CollisionHitNormal;
        v95v = *CollisionHitPos;
        v99 = 1;
        v98 = 1;
        goto LABEL_200;
    }

    v95v = {0.0f, 0.0f, 0.0f};
    v98 = 0;
    v99 = !v94;

LABEL_200:
    if (!v94) {
        if (this->val2 < 0.0 || !rs::isCollisionCodePress(this->info2)) {
            if ((v99 & v98 & 1) == 0)
                goto LABEL_214;

            goto LABEL_210;
        }

        if (!v98 || v135.length() > v134.length()) {
            v107 = &alCollisionUtil::getCollisionHitPos(this->info2);
            a2a = alCollisionUtil::getCollisionHitNormal(this->info2);
            if ((v99 & 1) == 0)
                goto LABEL_214;

            v95v = *v107;
            goto LABEL_210;
        }
    }

    if ((v99 & 1) == 0)
        goto LABEL_214;

LABEL_210:
    v110 = this->mCollisionShapeKeeper;
    v111v = v110->mBoundingCenter + sead::Vector3f{0.0f, 35.0f, 0.0f};
    v114v.setMul(mCollidePosMtx, v111v);
    vert = v114v - v95v;
    al::verticalizeVec(&vert, a2a, vert);
    a1 = {0.0f, 0.0f, 0.0f};
    if (al::tryNormalizeOrZero(&a1, vert)) {
        v117 = fmaxf(50.0 - vert.length(), 0.0);
        v118v = a1 * v117;
        v131 = (v114v + (a1 * v117)) + a2a;
        v130 = a2a * -200.0f;

        CRASH
        /*if ( !(unsigned int)alCollisionUtil::checkStrikeArrow(this, v131, v130, 0LL, 0LL) )
        {
          v61v += (v118v * 0.05f);
          v92 = 0;
          v93 = 0;
        }*/

        v87 = v128;
        v86 = v129;
    }

LABEL_214:
    this->flag1 |= v93;
    this->flag2 |= v92;
    *a2 = v61v;
    a3->z = v87;
    a3->x = v126;
    a3->y = v86;

    printf("calcResultVec result: (%f, %f, %f), (%f, %f, %f)\n", a2->x, a2->y, a2->z, a3->x, a3->y,
           a3->z);
}

void sub_7100433D98(sead::PtrArray<al::HitInfo>* a1, int* a2, int* a3,
                    const CollidedShapeResult* a4, const sead::Vector3f* a5, float a6) {
    float v14;         // s9
    float v15;         // s0
    float v16;         // s1
    u64 v18;           // x24
    float* v19;        // x8
    al::HitInfo* v20;  // x8
    u32* v21;          // x9
    float v22;         // w8
    float* v23;        // x9

    if (!a4->isArrow())
        return;

    const al::HitInfo& ArrowHitInfo = a4->getArrowHitInfo();
    const sead::Vector3f& FaceNormal = ArrowHitInfo.mTriangle.getFaceNormal();
    if (al::isNearZero(FaceNormal, 0.001))
        return;

    v14 = FaceNormal.dot(*a5);
    v15 = cosf(sead::Mathf::deg2rad(a6));
    v16 = sead::Mathf::abs(v14);
    if (v14 < 0.0 && v16 >= v15) {
        v18 = a4->getShapeInfoArrow()->mArrowIndex;
        v19 = (float*)(*a2 <= (unsigned int)v18 ? *((u64*)a2 + 1) : *((u64*)a2 + 1) + 4 * v18);
        if (*v19 < ArrowHitInfo.unk) {
            v20 = (al::HitInfo*)(a1->at(v18));

            v20->mTriangle.mKCPrismHeader = ArrowHitInfo.mTriangle.mKCPrismHeader;
            v20->mTriangle.mKCPrismData = ArrowHitInfo.mTriangle.mKCPrismData;
            v20->mTriangle.mCollisionParts = ArrowHitInfo.mTriangle.mCollisionParts;
            v20->mTriangle.mFaceNormal.x = ArrowHitInfo.mTriangle.mFaceNormal.x;
            v20->mTriangle.mFaceNormal.y = ArrowHitInfo.mTriangle.mFaceNormal.y;
            v20->mTriangle.mFaceNormal.z = ArrowHitInfo.mTriangle.mFaceNormal.z;
            v20->mTriangle.mEdgeNormals[0].x = ArrowHitInfo.mTriangle.mEdgeNormals[0].x;
            v20->mTriangle.mEdgeNormals[0].y = ArrowHitInfo.mTriangle.mEdgeNormals[0].y;
            v20->mTriangle.mEdgeNormals[0].z = ArrowHitInfo.mTriangle.mEdgeNormals[0].z;
            v20->mTriangle.mEdgeNormals[1].x = ArrowHitInfo.mTriangle.mEdgeNormals[1].x;
            v20->mTriangle.mEdgeNormals[1].y = ArrowHitInfo.mTriangle.mEdgeNormals[1].y;
            v20->mTriangle.mEdgeNormals[1].z = ArrowHitInfo.mTriangle.mEdgeNormals[1].z;
            v20->mTriangle.mEdgeNormals[2].x = ArrowHitInfo.mTriangle.mEdgeNormals[2].x;
            v20->mTriangle.mEdgeNormals[2].y = ArrowHitInfo.mTriangle.mEdgeNormals[2].y;
            v20->mTriangle.mEdgeNormals[2].z = ArrowHitInfo.mTriangle.mEdgeNormals[2].z;
            v20->mTriangle.mVerts[0].x = ArrowHitInfo.mTriangle.mVerts[0].x;
            v20->mTriangle.mVerts[0].y = ArrowHitInfo.mTriangle.mVerts[0].y;
            v20->mTriangle.mVerts[0].z = ArrowHitInfo.mTriangle.mVerts[0].z;
            v20->mTriangle.mVerts[1].x = ArrowHitInfo.mTriangle.mVerts[1].x;
            v20->mTriangle.mVerts[1].y = ArrowHitInfo.mTriangle.mVerts[1].y;
            v20->mTriangle.mVerts[1].z = ArrowHitInfo.mTriangle.mVerts[1].z;
            v20->mTriangle.mVerts[2].x = ArrowHitInfo.mTriangle.mVerts[2].x;
            v20->mTriangle.mVerts[2].y = ArrowHitInfo.mTriangle.mVerts[2].y;
            v20->mTriangle.mVerts[2].z = ArrowHitInfo.mTriangle.mVerts[2].z;
            v20->unk = ArrowHitInfo.unk;
            v20->mCollisionHitPos.x = ArrowHitInfo.mCollisionHitPos.x;
            v20->mCollisionHitPos.y = ArrowHitInfo.mCollisionHitPos.y;
            v20->mCollisionHitPos.z = ArrowHitInfo.mCollisionHitPos.z;
            v20->unk3.x = ArrowHitInfo.unk3.x;
            v20->unk3.y = ArrowHitInfo.unk3.y;
            v20->unk3.z = ArrowHitInfo.unk3.z;
            v20->mCollisionMovingReaction.x = ArrowHitInfo.mCollisionMovingReaction.x;
            v20->mCollisionMovingReaction.y = ArrowHitInfo.mCollisionMovingReaction.y;
            v20->mCollisionMovingReaction.z = ArrowHitInfo.mCollisionMovingReaction.z;
            v20->mCollisionLocation = ArrowHitInfo.mCollisionLocation;

            if (*a2 <= (unsigned int)v18)
                v21 = (u32*)*((u64*)a2 + 1);
            else
                v21 = (u32*)(*((u64*)a2 + 1) + 4 * v18);

            *v21 = ArrowHitInfo.unk;
            v22 = a4->getShapeInfoArrow()->a5;
            if (*a3 <= (unsigned int)v18)
                v23 = (float*)*((u64*)a3 + 1);
            else
                v23 = (float*)(*((u64*)a3 + 1) + 4 * v18);

            *v23 = v22;
        }
    }
}

void sub_71004338F0(u32* a1, sead::Vector3f* x1_0, sead::Vector3f* a3) {
    sead::Vector3f a2 = *x1_0;
    if (al::isNearZero(a2, 0.001)) {
        a2 = *a3;
        if (al::isNearZero(a2.x, 0.05))
            a2.x = 0.0;

        if (al::isNearZero(a2.y, 0.05))
            a2.y = 0.0;

        if (al::isNearZero(a2.z, 0.05))
            a2.z = 0.0;

        al::normalize(&a2);
    } else {
        f32 a2length = a2.length();
        if (al::isNearZero(a2.x / a2length, 0.05))
            a2.x = 0.0;

        if (al::isNearZero(a2.y / a2length, 0.05))
            a2.y = 0.0;

        if (al::isNearZero(a2.z / a2length, 0.05))
            a2.z = 0.0;
    }

    if (!al::isNearZero(a2.x, 0.001)) {
        if (a2.x > 0.0)
            *a1 |= 0x80u;

        if (a2.x < 0.0)
            *a1 |= 0x100u;
    }

    if (!al::isNearZero(a2.y, 0.001)) {
        if (a2.y > 0.0)
            *a1 |= 0x200u;

        if (a2.y < 0.0)
            *a1 |= 0x400u;
    }

    if (!al::isNearZero(a2.z, 0.001)) {
        if (a2.z > 0.0)
            *a1 |= 0x800u;

        if (a2.z < 0.0)
            *a1 |= 0x1000u;
    }
}

void PlayerCollider::calcGroundArrowAverage(bool* a2, sead::Vector3f* a3, bool* a4,
                                            sead::Vector3f* a5, CollisionShapeKeeper const* a6) {
    int mNumCollideResult;                                  // w19
    unsigned int i;                                         // w25
    const CollidedShapeResult* collidedShapeResult;         // x0
    int mNumCollideSupportResult;                           // w19
    unsigned int j;                                         // w25
    const CollidedShapeResult* CollidedShapeSupportResult;  // x0
    u64 v22;                                                // x27
    int v23;                                                // w26
    int v24;                                                // w25
    float* someThreeFloats;                                 // x8
    float v26;                                              // s0
    float* anotherThreeFloats;                              // x8
    const al::HitInfo* v28;                                 // x0
    const sead::Vector3f* CollisionHitNormal;               // x24
    bool isNearExistingNormal;                              // w19
    float* v35;                                             // x8

    *a2 = 0;
    *a4 = 0;
    *a3 = {0.0f, 0.0f, 0.0f};
    *a5 = {0.0f, 0.0f, 0.0f};
    mNumCollideResult = a6->mNumCollideResult;
    for (i = 0; i != mNumCollideResult; ++i) {
        collidedShapeResult = a6->getCollidedShapeResult(i);
        sub_7100433D98(&this->anotherPtrArray, &this->sizeOfArrayBelowIs3,
                       &this->sizeOfArrayBelowIs3_2, collidedShapeResult, this->mGravityPtr,
                       this->unk11);
    }

    mNumCollideSupportResult = a6->mNumCollideSupportResult;
    for (j = 0; j != mNumCollideSupportResult; ++j) {
        CollidedShapeSupportResult = a6->getCollidedShapeSupportResult(j);
        sub_7100433D98(&this->anotherPtrArray, &this->sizeOfArrayBelowIs3,
                       &this->sizeOfArrayBelowIs3_2, CollidedShapeSupportResult, this->mGravityPtr,
                       this->unk11);
    }

    sead::Vector3f v16v = {0.0f, 0.0f, 0.0f};
    sead::Vector3f v19v = {0.0f, 0.0f, 0.0f};
    v22 = 0LL;
    v23 = 0;
    v24 = 0;
    for (v22 = 0; v22 != 3; v22++) {
        if ((unsigned int)this->sizeOfArrayBelowIs3 <= v22)
            someThreeFloats = this->someThreeFloats;
        else
            someThreeFloats = &this->someThreeFloats[v22];

        v26 = *someThreeFloats;
        if (*someThreeFloats >= 0.0) {
            if ((unsigned int)this->sizeOfArrayBelowIs3_2 <= v22)
                anotherThreeFloats = this->anotherThreeFloats;
            else
                anotherThreeFloats = &this->anotherThreeFloats[v22];

            if (v26 >= *anotherThreeFloats) {
                ++v23;
                v28 = (const al::HitInfo*)this->anotherPtrArray[v22];

                v16v += alCollisionUtil::getCollisionHitPos(v28);
            }

            CollisionHitNormal =
                &alCollisionUtil::getCollisionHitNormal(this->anotherPtrArray[v22]);

            isNearExistingNormal = false;
            for (int v33 = 0; v33 != v22; v33++) {
                if ((unsigned int)this->sizeOfArrayBelowIs3 <= v33)
                    v35 = this->someThreeFloats;
                else
                    v35 = &this->someThreeFloats[v33];

                if (*v35 >= 0.0) {
                    isNearExistingNormal |= al::isNearDirection(
                        *CollisionHitNormal,
                        alCollisionUtil::getCollisionHitNormal(this->anotherPtrArray[v33]), 0.01);
                }
            }

            if (!isNearExistingNormal) {
                v19v += *CollisionHitNormal;
                ++v24;
            }
        }
    }

    if (v23 > 0) {
        *a3 = v16v * (1.0f / v23);
        *a2 = 1;
    }

    if (v24 >= 1) {
        *a5 = v19v * (1.0f / v24);
        al::normalize(a5);
        *a4 = 1;
    }

    printf("Result of GroundArrowAverage: %s=(%f, %f, %f), %s=(%f, %f, %f)\n",
           *a2 ? "true" : "false", a3->x, a3->y, a3->z, *a4 ? "true" : "false", a5->x, a5->y,
           a5->z);
}

void PlayerCollider::calcResultVecArrow(sead::BitFlag<uint>* a2, sead::Vector3f* a3,
                                        sead::Vector3f* a4, sead::Vector3f* a5, sead::Vector3f* a6,
                                        CollidedShapeResult const* result) {
    const al::HitInfo* ArrowHitInfo;                // x0
    const sead::Vector3f* mGravityPtr;              // x8
    const al::HitInfo* v19;                         // x20
    const sead::Vector3f* FaceNormal;               // x0
    float unk11;                                    // s9
    const sead::Vector3f* p_x;                      // x27
    float v23;                                      // s8
    float v24;                                      // s0
    float v25;                                      // s1
    const CollisionShapeInfoArrow* ShapeInfoArrow;  // x26
    float v28;                                      // s0
    float v32;                                      // s0
    float v36;                                      // s3
    float v37;                                      // s3
    float v38;                                      // s4
    float v39;                                      // s5
    float v40;                                      // s0
    float v41;                                      // s1
    float v42;                                      // s2
    float v43;                                      // s3
    float v44;                                      // s4
    float v45;                                      // s5
    float v46;                                      // s3
    float v47;                                      // s4
    float v48;                                      // s3
    float v49;                                      // s3
    float v58;                                      // s0
    float v59;                                      // s1
    float v60;                                      // s2
    float v61;                                      // s1
    float v62;                                      // s2
    float v63;                                      // s3
    float v64;                                      // s4
    float v65;                                      // s0
    float v66;                                      // s0
    float v67;                                      // s0
    float v68;                                      // s2
    float v69;                                      // s0
    float v70;                                      // s0
    float v71;                                      // s0
    float v72;                                      // s2
    float v73;                                      // s0
    float v74;                                      // s0
    al::HitInfo* info1;                             // x8
    sead::Vector3f v76;                             // [xsp+0h] [xbp-A0h] BYREF
    sead::Vector3f v77;                             // [xsp+10h] [xbp-90h] BYREF
    sead::Vector3f v78;                             // [xsp+20h] [xbp-80h] BYREF
    float v79;                                      // [xsp+5Ch] [xbp-44h] BYREF
    sead::Vector3f v33v;
    sead::Vector3f v29v;

    if ((this->someBitField & 0x40) != 0) {
        ArrowHitInfo = &result->getArrowHitInfo();
        mGravityPtr = this->mGravityPtr;
        v19 = ArrowHitInfo;
        FaceNormal = &ArrowHitInfo->mTriangle.getFaceNormal();
        unk11 = this->unk11;
        p_x = FaceNormal;
        if (!al::isNearZero(*FaceNormal, 0.001)) {
            v23 = mGravityPtr->dot(*p_x);
            v24 = cosf(sead::Mathf::deg2rad(unk11));
            v25 = sead::Mathf::abs(v23);
            if (v23 < 0.0 && v25 >= v24) {
                ShapeInfoArrow = result->getShapeInfoArrow();
                v77 = ShapeInfoArrow->vec4;
                al::tryNormalizeOrZero(&v77);
                v28 = fmaxf(v19->unk - ShapeInfoArrow->a5, 0.0);
                v29v = this->mCollidedGroundNormal;
                v32 = -(v77 * v28).dot(mCollidedGroundNormal);
                v33v = v29v * v32;
                v76 = v29v * v32;
                if (alCollisionUtil::isCollisionMoving(v19)) {
                    v79 = 0.0;
                    v78 = {0.0f, 0.0f, 0.0f};
                    if (al::separateScalarAndDirection(&v79, &v78, v76) ||
                        (v36 = (float)((float)(v78.x * v19->mCollisionMovingReaction.x) +
                                       (float)(v78.y * v19->mCollisionMovingReaction.y)) +
                               (float)(v78.z * v19->mCollisionMovingReaction.z),
                         v36 >= 0.0)) {
                        v58 = v76.x;
                        v59 = a5->x;
                        v60 = a5->y;
                        if (a5->x >= v76.x)
                            v59 = v76.x;

                        a5->x = v59;
                        v61 = v76.y;
                        if (v60 >= v76.y)
                            v60 = v76.y;

                        a5->y = v60;
                        v62 = a5->z;
                        v63 = v76.z;
                        if (v62 >= v76.z)
                            v62 = v76.z;

                        a5->z = v62;
                        v64 = a6->y;
                        if (a6->x > v58)
                            v58 = a6->x;

                        a6->x = v58;
                        if (v64 <= v61)
                            v65 = v61;
                        else
                            v65 = v64;

                        a6->y = v65;
                        v66 = a6->z;
                        if (v66 <= v63)
                            v66 = v63;

                        a6->z = v66;
                        v67 = v19->mCollisionMovingReaction.x;
                        v68 = a5->y;
                        if (a5->x < v67)
                            v67 = a5->x;

                        a5->x = v67;
                        v69 = v19->mCollisionMovingReaction.y;
                        if (v68 < v69)
                            v69 = v68;

                        a5->y = v69;
                        v70 = a5->z;
                        if (v70 >= v19->mCollisionMovingReaction.z)
                            v70 = v19->mCollisionMovingReaction.z;

                        a5->z = v70;
                        v71 = v19->mCollisionMovingReaction.x;
                        v72 = a6->y;
                        if (a6->x > v71)
                            v71 = a6->x;

                        a6->x = v71;
                        v73 = v19->mCollisionMovingReaction.y;
                        if (v72 > v73)
                            v73 = v72;

                        a6->y = v73;
                        v74 = a6->z;
                        if (v74 <= v19->mCollisionMovingReaction.z)
                            v74 = v19->mCollisionMovingReaction.z;

                        a6->z = v74;
                    } else {
                        v37 = fmaxf(v36 + v79, 0.0);
                        v38 = a5->x;
                        v39 = a5->y;
                        v40 = v78.x * v37;
                        v41 = v78.y * v37;
                        v42 = v78.z * v37;
                        v43 = a5->z;
                        if (a5->x >= v40)
                            v38 = v40;

                        a5->x = v38;
                        if (v39 >= v41)
                            v44 = v41;
                        else
                            v44 = v39;

                        if (v43 >= v42)
                            v43 = v42;

                        a5->y = v44;
                        a5->z = v43;
                        v45 = a6->z;
                        v46 = a6->x;
                        v47 = a6->y;
                        if (a6->x <= v40)
                            v46 = v40;

                        a6->x = v46;
                        if (v47 <= v41)
                            v48 = v41;
                        else
                            v48 = v47;

                        a6->y = v48;
                        if (v45 <= v42)
                            v49 = v42;
                        else
                            v49 = v45;

                        a6->z = v49;
                        v76.x = v40;
                        v76.y = v41;
                        v76.z = v42;
                    }
                } else {
                    a3->x = sead::Mathf::min(a3->x, v33v.x);
                    a3->y = sead::Mathf::min(a3->y, v33v.y);
                    a3->z = sead::Mathf::min(a3->z, v33v.z);

                    a4->x = sead::Mathf::max(a4->x, v33v.x);
                    a4->y = sead::Mathf::max(a4->y, v33v.y);
                    a4->z = sead::Mathf::max(a4->z, v33v.z);

                    sub_71004338F0((u32*)a2, &v76, &this->mCollidedGroundNormal);
                }

                if (this->val1 < v19->unk) {
                    info1 = this->info1;
                    info1->mTriangle.mKCPrismHeader = v19->mTriangle.mKCPrismHeader;
                    info1->mTriangle.mKCPrismData = v19->mTriangle.mKCPrismData;
                    info1->mTriangle.mCollisionParts = v19->mTriangle.mCollisionParts;
                    info1->mTriangle.mFaceNormal = v19->mTriangle.mFaceNormal;
                    info1->mTriangle.mEdgeNormals[0].x = v19->mTriangle.mEdgeNormals[0].x;
                    info1->mTriangle.mEdgeNormals[0].y = v19->mTriangle.mEdgeNormals[0].y;
                    info1->mTriangle.mEdgeNormals[0].z = v19->mTriangle.mEdgeNormals[0].z;
                    info1->mTriangle.mEdgeNormals[1] = v19->mTriangle.mEdgeNormals[1];
                    info1->mTriangle.mEdgeNormals[2] = v19->mTriangle.mEdgeNormals[2];
                    info1->mTriangle.mVerts[0].x = v19->mTriangle.mVerts[0].x;
                    info1->mTriangle.mVerts[0].y = v19->mTriangle.mVerts[0].y;
                    info1->mTriangle.mVerts[0].z = v19->mTriangle.mVerts[0].z;
                    info1->mTriangle.mVerts[1] = v19->mTriangle.mVerts[1];
                    info1->mTriangle.mVerts[2] = v19->mTriangle.mVerts[2];
                    info1->unk = v19->unk;
                    info1->mCollisionHitPos = v19->mCollisionHitPos;
                    info1->unk3 = v19->unk3;
                    info1->mCollisionMovingReaction = v19->mCollisionMovingReaction;
                    info1->mCollisionLocation = v19->mCollisionLocation;
                    this->val1 = v19->unk;
                }

                PlayerCollider::collectHitInfoArray(*v19, 0);
            }
        }
    }
}

void PlayerCollider::calcResultVecSphere(sead::BitFlag<uint>* a2, sead::Vector3f* a3,
                                         sead::Vector3f* a4, sead::Vector3f* a5, sead::Vector3f* a6,
                                         CollidedShapeResult const* a7) {
    const al::SphereHitInfo* sphereHitInfo;    // x0
    const al::SphereHitInfo* v15;              // x20
    const sead::Vector3f* p_mCollisionHitPos;  // x26
    float unk11;                               // s9
    float v18;                                 // s10
    float v19;                                 // s0
    float v20;                                 // s1
    bool v21;                                  // nf
    float v22;                                 // s9
    int mWallBorderCheckType;                  // w8
    const sead::Vector3f* p_mWorldShapeInfo;   // x28
    float unk2;                                // s9
    int* p_someBitField;                       // x28
    char v37;                                  // w26
    float v38;                                 // s3
    float v39;                                 // s3
    float v40;                                 // s0
    float v41;                                 // s1
    float v42;                                 // s2
    float v43;                                 // s3
    float v44;                                 // s4
    float v45;                                 // s3
    float v46;                                 // s3
    float v47;                                 // s4
    float v48;                                 // s3
    float v56;                                 // s0
    float v58;                                 // s0
    float v59;                                 // s1
    float y;                                   // s2
    float v61;                                 // s1
    float v62;                                 // s2
    float v63;                                 // s3
    float v64;                                 // s4
    float v65;                                 // s0
    float v66;                                 // s0
    float v67;                                 // s0
    float v68;                                 // s2
    float v69;                                 // s0
    float v70;                                 // s0
    float v71;                                 // s0
    float v72;                                 // s2
    float v73;                                 // s0
    float v74;                                 // s0
    float v77;                                 // s0
    al::HitInfo* info1;                        // x8
    PlayerCollider* v80;                       // x0
    const al::HitInfo* v81;                    // x1
    int v82;                                   // w2
    float v84;                                 // s0
    al::HitInfo* info2;                        // x8
    al::HitInfo* info3;                        // x8
    float v93;                                 // s0
    bool v94;                                  // [xsp+Ch] [xbp-E4h]
    sead::Vector3f v95;                        // [xsp+30h] [xbp-C0h] BYREF
    sead::Vector3f v96;                        // [xsp+40h] [xbp-B0h] BYREF
    sead::Vector3f v97;                        // [xsp+50h] [xbp-A0h] BYREF
    sead::Vector3f gravity;                    // [xsp+60h] [xbp-90h] BYREF
    float v99;                                 // [xsp+6Ch] [xbp-84h] BYREF
    sead::Vector3f v100;                       // [xsp+70h] [xbp-80h] BYREF

    sphereHitInfo = &a7->getSphereHitInfo();
    gravity = *this->mGravityPtr;
    v15 = sphereHitInfo;
    p_mCollisionHitPos = &sphereHitInfo->mCollisionHitPos;
    v97 = sphereHitInfo->mTriangle.getNormal(0);
    v96 = {0.0f, 0.0f, 0.0f};
    v95 = {0.0f, 0.0f, 0.0f};
    unk11 = this->unk11;
    if (al::isNearZero(v97, 0.001) ||
        ((v18 = v97.dot(gravity), v19 = cosf(sead::Mathf::deg2rad(unk11)), v18 <= 0.0) ?
             (v20 = -v18) :
             (v20 = v18),
         v18 < 0.0 ? (v21 = v20 < v19) : (v21 = 1), v21)) {
        v22 = this->unk11;
        if (!al::isNearZero(v97, 0.001)) {
            if (sead::Mathf::abs(v97.dot(gravity)) < sead::Mathf::cos(sead::Mathf::deg2rad(v22))) {
                mWallBorderCheckType = this->mWallBorderCheckType;
                if ((mWallBorderCheckType == 2 ||
                     mWallBorderCheckType == 1 && !v15->isCollisionAtFace()) &&
                    rs::calcExistCollisionBorder(this, *p_mCollisionHitPos, v97))
                    return;

                if ((this->someBitField & 2) == 0) {
                    v15->calcFixVector(&v96, &v95);
                    if (!v15->isCollisionAtFace()) {
                        al::verticalizeVec(&v96, gravity, v96);
                        al::tryNormalizeOrZero(&v95, v96);
                    }

                    goto LABEL_35;
                }

                goto LABEL_34;
            }
        }

        if (a7->getShapeInfoSphere()->unkFlag)
            return;

        if ((this->someBitField & 4) == 0) {
        LABEL_33:
            v15->calcFixVector(&v96, &v95);
            goto LABEL_35;
        }

    LABEL_34:
        v15->calcFixVectorNormal(&v96, &v95);
        goto LABEL_35;
    }

    if (!this->mIsValidGroundSupport || a7->getShapeInfoSphere()->isIgnoreGround)
        return;

    if (!this->mCollisionShapeKeeper->someFlag) {
        if ((this->someBitField & 1) == 0)
            goto LABEL_33;

        goto LABEL_34;
    }

    if (!a7->getShapeInfoSphere()->isSupportGround) {
        v15->calcFixVectorNormal(&v96, &v95);
        p_someBitField = (int*)&this->someBitField;
        goto LABEL_117;
    }

    p_mWorldShapeInfo = &a7->getShapeInfoSphere()->mWorldShapeInfo;
    unk2 = a7->getShapeInfoSphere()->unk2;
    v100 = v15->mCollisionHitPos - v15->unk3;
    al::verticalizeVec(&v100, *p_mWorldShapeInfo, v100);
    if (v100.length() < unk2)
        goto LABEL_34;

    p_someBitField = (int*)&this->someBitField;
    if ((this->someBitField & 0x40) == 0) {
        v15->calcFixVectorNormal(&v96, &v95);

    LABEL_117:
        if ((*(u8*)p_someBitField & 0x40) != 0 &&
            (v15->mCollisionHitPos - this->mCollidedGroundPos).dot(mCollidedGroundNormal) < 2.5)
            return;

        v100 = v15->unk3 - *p_mCollisionHitPos;
        if (!al::tryNormalizeOrZero(&v100))
            return;

        v93 = v96.dot(v100);
        v96 = v100 * v93;
        al::verticalizeVec(&v96, gravity, v96);
        if (!al::tryNormalizeOrZero(&v95, v96))
            return;

        v97 = v95;
        v37 = 1;
        goto LABEL_36;
    }

    v94 = al::isNearZeroOrGreater(this->mCollisionShapeKeeper->unk4 +
                                      gravity.dot(v15->mCollisionHitPos - this->mCollidedGroundPos),
                                  0.001);
    v15->calcFixVectorNormal(&v96, &v95);
    if (!v94)
        goto LABEL_117;

LABEL_35:
    v37 = 0;

LABEL_36:
    if (alCollisionUtil::isCollisionMoving(v15)) {
        v99 = 0.0;
        v100.x = 0.0;
        v100.y = 0.0;
        v100.z = 0.0;
        if (al::separateScalarAndDirection(&v99, &v100, v96) ||
            (v38 = (float)((float)(v100.x * v15->mCollisionMovingReaction.x) +
                           (float)(v100.y * v15->mCollisionMovingReaction.y)) +
                   (float)(v100.z * v15->mCollisionMovingReaction.z),
             v38 >= 0.0)) {
            v58 = v96.x;
            v59 = a5->x;
            y = a5->y;
            if (a5->x >= v96.x)
                v59 = v96.x;

            a5->x = v59;
            v61 = v96.y;
            if (y >= v96.y)
                y = v96.y;

            a5->y = y;
            v62 = a5->z;
            v63 = v96.z;
            if (v62 >= v96.z)
                v62 = v96.z;

            a5->z = v62;
            v64 = a6->y;
            if (a6->x > v58)
                v58 = a6->x;

            a6->x = v58;
            if (v64 <= v61)
                v65 = v61;
            else
                v65 = v64;

            a6->y = v65;
            v66 = a6->z;
            if (v66 <= v63)
                v66 = v63;

            a6->z = v66;
            v67 = v15->mCollisionMovingReaction.x;
            v68 = a5->y;
            if (a5->x < v67)
                v67 = a5->x;

            a5->x = v67;
            v69 = v15->mCollisionMovingReaction.y;
            if (v68 < v69)
                v69 = v68;

            a5->y = v69;
            v70 = a5->z;
            if (v70 >= v15->mCollisionMovingReaction.z)
                v70 = v15->mCollisionMovingReaction.z;

            a5->z = v70;
            v71 = v15->mCollisionMovingReaction.x;
            v72 = a6->y;
            if (a6->x > v71)
                v71 = a6->x;

            a6->x = v71;
            v73 = v15->mCollisionMovingReaction.y;
            if (v72 > v73)
                v73 = v72;

            a6->y = v73;
            v74 = a6->z;
            if (v74 <= v15->mCollisionMovingReaction.z)
                v74 = v15->mCollisionMovingReaction.z;

            a6->z = v74;
        } else {
            v39 = fmaxf(v38 + v99, 0.0);
            v40 = v100.x * v39;
            v41 = v100.y * v39;
            v42 = v100.z * v39;
            v43 = a5->x;
            v44 = a5->y;
            if (a5->x >= v40)
                v43 = v40;

            a5->x = v43;
            v45 = a5->z;
            if (v44 >= v41)
                v44 = v41;

            if (v45 >= v42)
                v45 = v42;

            a5->y = v44;
            a5->z = v45;
            v46 = a6->x;
            v47 = a6->y;
            if (a6->x <= v40)
                v46 = v40;

            a6->x = v46;
            v48 = a6->z;
            if (v47 <= v41)
                v47 = v41;

            if (v48 <= v42)
                v48 = v42;

            a6->y = v47;
            a6->z = v48;
            v96.x = v40;
            v96.y = v41;
            v96.z = v42;
        }
    } else {
        a3->x = sead::Mathf::min(a3->x, v96.x);
        a3->y = sead::Mathf::min(a3->y, v96.y);
        a3->z = sead::Mathf::min(a3->z, v96.z);

        a4->x = sead::Mathf::max(a4->x, v96.x);
        a4->y = sead::Mathf::max(a4->y, v96.y);
        a4->z = sead::Mathf::max(a4->z, v96.z);

        sub_71004338F0((u32*)a2, &v96, &v97);
    }

    if ((v37 & 1) == 0) {
        if (al::isNearZero(v97, 0.001) || v97.dot(gravity) >= 0.0 ||
            sead::Mathf::abs(v97.dot(gravity)) <
                sead::Mathf::cos(sead::Mathf::deg2rad(this->unk11))) {
            if (al::isNearZero(v97, 0.001) ||
                (sead::Mathf::abs(v97.dot(gravity)) >=
                 sead::Mathf::cos(sead::Mathf::deg2rad(this->unk11)))) {
                if (this->val3 < v15->unk) {
                    info3 = this->info3;
                    info3->mTriangle.mKCPrismHeader = v15->mTriangle.mKCPrismHeader;
                    info3->mTriangle.mKCPrismData = v15->mTriangle.mKCPrismData;
                    info3->mTriangle.mCollisionParts = v15->mTriangle.mCollisionParts;
                    info3->mTriangle.mFaceNormal = v15->mTriangle.mFaceNormal;
                    info3->mTriangle.mEdgeNormals[0].x = v15->mTriangle.mEdgeNormals[0].x;
                    info3->mTriangle.mEdgeNormals[0].y = v15->mTriangle.mEdgeNormals[0].y;
                    info3->mTriangle.mEdgeNormals[0].z = v15->mTriangle.mEdgeNormals[0].z;
                    info3->mTriangle.mEdgeNormals[1] = v15->mTriangle.mEdgeNormals[1];
                    info3->mTriangle.mEdgeNormals[2] = v15->mTriangle.mEdgeNormals[2];
                    info3->mTriangle.mVerts[0].x = v15->mTriangle.mVerts[0].x;
                    info3->mTriangle.mVerts[0].y = v15->mTriangle.mVerts[0].y;
                    info3->mTriangle.mVerts[0].z = v15->mTriangle.mVerts[0].z;
                    info3->mTriangle.mVerts[1] = v15->mTriangle.mVerts[1];
                    info3->mTriangle.mVerts[2] = v15->mTriangle.mVerts[2];
                    info3->unk = v15->unk;
                    info3->mCollisionHitPos = v15->mCollisionHitPos;
                    info3->unk3 = v15->unk3;
                    info3->mCollisionMovingReaction = v15->mCollisionMovingReaction;
                    info3->mCollisionLocation = v15->mCollisionLocation;
                    this->val3 = v15->unk;
                }

                v82 = 2;
            } else {
                if (this->val2 < v15->unk) {
                    info2 = this->info2;
                    info2->mTriangle.mKCPrismHeader = v15->mTriangle.mKCPrismHeader;
                    info2->mTriangle.mKCPrismData = v15->mTriangle.mKCPrismData;
                    info2->mTriangle.mCollisionParts = v15->mTriangle.mCollisionParts;
                    info2->mTriangle.mFaceNormal = v15->mTriangle.mFaceNormal;
                    info2->mTriangle.mEdgeNormals[0].x = v15->mTriangle.mEdgeNormals[0].x;
                    info2->mTriangle.mEdgeNormals[0].y = v15->mTriangle.mEdgeNormals[0].y;
                    info2->mTriangle.mEdgeNormals[0].z = v15->mTriangle.mEdgeNormals[0].z;
                    info2->mTriangle.mEdgeNormals[1] = v15->mTriangle.mEdgeNormals[1];
                    info2->mTriangle.mEdgeNormals[2] = v15->mTriangle.mEdgeNormals[2];
                    info2->mTriangle.mVerts[0].x = v15->mTriangle.mVerts[0].x;
                    info2->mTriangle.mVerts[0].y = v15->mTriangle.mVerts[0].y;
                    info2->mTriangle.mVerts[0].z = v15->mTriangle.mVerts[0].z;
                    info2->mTriangle.mVerts[1] = v15->mTriangle.mVerts[1];
                    info2->mTriangle.mVerts[2] = v15->mTriangle.mVerts[2];
                    info2->unk = v15->unk;
                    info2->mCollisionHitPos = v15->mCollisionHitPos;
                    info2->unk3 = v15->unk3;
                    info2->mCollisionMovingReaction = v15->mCollisionMovingReaction;
                    info2->mCollisionLocation = v15->mCollisionLocation;
                    this->val2 = v15->unk;
                }

                v82 = 1;
            }

            v80 = this;
            v81 = v15;
        } else {
            if (this->val1 < v15->unk) {
                info1 = this->info1;
                info1->mTriangle.mKCPrismHeader = v15->mTriangle.mKCPrismHeader;
                info1->mTriangle.mKCPrismData = v15->mTriangle.mKCPrismData;
                info1->mTriangle.mCollisionParts = v15->mTriangle.mCollisionParts;
                info1->mTriangle.mFaceNormal = v15->mTriangle.mFaceNormal;
                info1->mTriangle.mEdgeNormals[0].x = v15->mTriangle.mEdgeNormals[0].x;
                info1->mTriangle.mEdgeNormals[0].y = v15->mTriangle.mEdgeNormals[0].y;
                info1->mTriangle.mEdgeNormals[0].z = v15->mTriangle.mEdgeNormals[0].z;
                info1->mTriangle.mEdgeNormals[1] = v15->mTriangle.mEdgeNormals[1];
                info1->mTriangle.mEdgeNormals[2] = v15->mTriangle.mEdgeNormals[2];
                info1->mTriangle.mVerts[0].x = v15->mTriangle.mVerts[0].x;
                info1->mTriangle.mVerts[0].y = v15->mTriangle.mVerts[0].y;
                info1->mTriangle.mVerts[0].z = v15->mTriangle.mVerts[0].z;
                info1->mTriangle.mVerts[1] = v15->mTriangle.mVerts[1];
                info1->mTriangle.mVerts[2] = v15->mTriangle.mVerts[2];
                info1->unk = v15->unk;
                info1->mCollisionHitPos = v15->mCollisionHitPos;
                info1->unk3 = v15->unk3;
                info1->mCollisionMovingReaction = v15->mCollisionMovingReaction;
                info1->mCollisionLocation = v15->mCollisionLocation;
                this->val1 = v15->unk;
            }

            v80 = this;
            v81 = v15;
            v82 = 0;
        }

        PlayerCollider::collectHitInfoArray(*v81, v82);
    }
}

void PlayerCollider::calcResultVecDisk(sead::BitFlag<uint>*, sead::Vector3f*, sead::Vector3f*,
                                       sead::Vector3f*, sead::Vector3f*,
                                       CollidedShapeResult const*) {
    CRASH
}

void PlayerCollider::collectHitInfoArray(al::HitInfo const& a2, int a3) {
    sead::PtrArray<const al::HitInfo>* ptrArraysChangeMe;  // x21
    u64 v6;                                                // x10
    u64 v8;                                                // x22
    int v9;                                                // w8
    int v10;                                               // w9
    u64 numHitInfosAbove;                                  // x11
    al::HitInfo* v12;                                      // x11
    al::HitInfo* v13;                                      // x10

    if (a3 == 2) {
        ptrArraysChangeMe = &this->ptrArraysChangeMe[2];
    }

    else if (a3 == 1) {
        ptrArraysChangeMe = &this->ptrArraysChangeMe[1];
    } else {
        if (a3)
            return;

        ptrArraysChangeMe = this->ptrArraysChangeMe;
    }

    v6 = ptrArraysChangeMe->capacity();
    if (ptrArraysChangeMe->size() < 1) {
        v10 = 0;
        v9 = -1;
    } else {
        v8 = 0LL;
        v9 = -1;
        while ((*ptrArraysChangeMe)[v8]->mTriangle.mCollisionParts !=
               a2.mTriangle.mCollisionParts) {
            if (++v8 >= ptrArraysChangeMe->size()) {
                v10 = 0;
                goto LABEL_18;
            }
        }

        if ((v8 & 0x80000000) != 0) {
            v10 = 0;
        } else {
            if (al::isNearZeroOrGreater(*((float*)(*ptrArraysChangeMe)[v8] + 28) - a2.unk, 0.001))
                return;

            v6 = ptrArraysChangeMe->capacity();
            v10 = 1;
        }

        v9 = v8;
    }

LABEL_18:
    numHitInfosAbove = this->numHitInfosAbove;
    if ((unsigned int)numHitInfosAbove < (unsigned int)v6) {
        v12 = &this->someHitInfos[numHitInfosAbove];
        v12->mTriangle.mKCPrismHeader = a2.mTriangle.mKCPrismHeader;
        v12->mTriangle.mKCPrismData = a2.mTriangle.mKCPrismData;
        v12->mTriangle.mCollisionParts = a2.mTriangle.mCollisionParts;
        v12->mTriangle.mFaceNormal = a2.mTriangle.mFaceNormal;
        v12->mTriangle.mEdgeNormals[0].x = a2.mTriangle.mEdgeNormals[0].x;
        v12->mTriangle.mEdgeNormals[0].y = a2.mTriangle.mEdgeNormals[0].y;
        v12->mTriangle.mEdgeNormals[0].z = a2.mTriangle.mEdgeNormals[0].z;
        v12->mTriangle.mEdgeNormals[1] = a2.mTriangle.mEdgeNormals[1];
        v12->mTriangle.mEdgeNormals[2] = a2.mTriangle.mEdgeNormals[2];
        v12->mTriangle.mVerts[0].x = a2.mTriangle.mVerts[0].x;
        v12->mTriangle.mVerts[0].y = a2.mTriangle.mVerts[0].y;
        v12->mTriangle.mVerts[0].z = a2.mTriangle.mVerts[0].z;
        v12->mTriangle.mVerts[1] = a2.mTriangle.mVerts[1];
        v12->mTriangle.mVerts[2] = a2.mTriangle.mVerts[2];
        v12->unk = a2.unk;
        v12->mCollisionHitPos = a2.mCollisionHitPos;
        v12->unk3 = a2.unk3;
        v12->mCollisionMovingReaction = a2.mCollisionMovingReaction;
        v12->mCollisionLocation = a2.mCollisionLocation;
        v13 = &this->someHitInfos[this->numHitInfosAbove];
        if (v10) {
            if (ptrArraysChangeMe->size() > (unsigned int)v9)
                (*ptrArraysChangeMe).replace(v9, v13);
        }

        else if (ptrArraysChangeMe->size() < ptrArraysChangeMe->capacity()) {
            ptrArraysChangeMe->pushBack(v13);
        }

        ++this->numHitInfosAbove;
    }
}

bool PlayerCollider::isNeedWallBorderCheck(al::HitInfo const&) const {
    CRASH return false;
}

void PlayerCollider::setWallBorderCheckTypeNone() {
    CRASH
}

void PlayerCollider::setWallBorderCheckTypeNoFace() {
    mWallBorderCheckType = 1;
}

void PlayerCollider::setWallBorderCheckTypeAll() {
    mWallBorderCheckType = 2;
}

void PlayerCollider::setCollisionPartsFilter(al::CollisionPartsFilterBase const* partsFilter) {
    mCollisionPartsFilter = partsFilter;
}

void PlayerCollider::calcBoundingCenter(sead::Vector3f*) const {
    CRASH
}

void PlayerCollider::validateCorrectMovePartsCheck() const {
    mCollisionMultiShape->validateCorrectMovePartsCheck();
}

al::CollisionDirector* PlayerCollider::getCollisionDirector() const {
    return mCollisionDirector;
}
