#include "CUSTOM/CollisionMultiShape.h"
#include <typeinfo>
#include "CUSTOM/CollisionPartsKeeper.h"
#include "Library/Collision/CollisionCheckInfo.h"
#include "Library/Collision/CollisionParts.h"
#include "Library/Collision/CollisionUtil.h"
#include "Library/Collision/KCollisionServer.h"
#include "Library/Collision/KTriangle.h"
#include "Library/Math/MathUtil.h"
#include "Player/CollisionShapeInfo.h"
#include "Player/CollisionShapeKeeper.h"
#include "Util/CollisionShapeFunction.h"

namespace game {

bool CollisionMultiShape::check(CollisionShapeKeeper* keeper, const sead::Matrix34f* mtx, float val,
                                const sead::Vector3f& vec, const al::CollisionPartsFilterBase*) {
    mCollisionShapeKeeper = keeper;
    keeper->clearResult();
    keeper->calcWorldShapeInfo(*mtx, val);

    al::SphereCheckInfo info = {mCheckPos, keeper->mBoundingRadius};
    mCheckPos.setMul(*mtx, keeper->mBoundingCenter);

    sead::Delegate1<CollisionMultiShape, al::CollisionParts*> delegate(
        this, &CollisionMultiShape::callbackFromParts);
    mPartsKeeper->searchWithSphere(info, delegate);
    dbg_printf("CollisionMultiShapeSimple::check((%.02f,%.02f,%.02f,%.02f,%.02f,%.02f,%.02f,%.02f,%."
           "02f,%.02f,%.02f,%.02f), %.02f, (%.02f,%.02f,%.02f)) => %d\n",
           mtx->m[0][0], mtx->m[0][1], mtx->m[0][2], mtx->m[0][3], mtx->m[1][0], mtx->m[1][1],
           mtx->m[1][2], mtx->m[1][3], mtx->m[2][0], mtx->m[2][1], mtx->m[2][2], mtx->m[2][3], val,
           vec.x, vec.y, vec.z, mCollisionShapeKeeper->mNumCollideResult);
    return mCollisionShapeKeeper->mNumCollideResult > 0;
}

void sub_71003F78A8(al::KCollisionServer* server, const CollisionShapeInfoBase* shape,
                    al::CollisionParts* parts, const sead::Vector3f& vec,
                    sead::Delegate2<CollisionMultiShape, const al::KCPrismData*,
                                    const al::KCPrismHeader*>& delegate,
                    sead::PtrArray<const al::KCPrismData>& checkedTriangles) {
    checkedTriangles.clear();
    if (CollisionShapeFunction::isShapeArrow(shape)) {
        const CollisionShapeInfoArrow* arrow = CollisionShapeFunction::getShapeInfoArrow(shape);
        sead::Vector3f v28 = arrow->vec5 + vec;
        server->searchPrismArrow(v28, arrow->vec6, delegate);
    } else if (CollisionShapeFunction::isShapeDisk(shape)) {
        CRASH
        return;
    } else if (CollisionShapeFunction::isShapeSphere(shape)) {
        sead::Vector3f v23;
        v23.setMul(parts->mBaseInvMtx, shape->getBoundingCenterWorld());
        sead::Vector3f v28 = v23 + vec;
        server->searchPrism(&v28, parts->mMtxScale * shape->getBoundingRadiusWorld(), delegate);
    }
}

void CollisionMultiShape::callbackFromParts(al::CollisionParts* parts) {
    CollisionShapeKeeper* mCollisionShapeKeeper;    // x0
    CollisionShapeKeeper* v5;                       // x0
    int mPtrNum;                                    // w27
    unsigned int v7;                                // w21
    const CollisionShapeInfoBase* ShapeInfoBase;    // x0
    const CollisionShapeInfoBase* v9;               // x25
    bool v10;                                       // w24
    float v11;                                      // s8
    const CollisionShapeInfoArrow* ShapeInfoArrow;  // x26
    bool v13;                                       // w0
    float v14;                                      // s9
    float v15;                                      // s13
    float v16;                                      // s14
    float mBoundingSphereRange;                     // s8
    float* ShapeInfoDisk;                           // x26
    float v19;                                      // s0
    float v20;                                      // s2
    float v21;                                      // s1
    float v22;                                      // s3
    float v23;                                      // s4
    float v24;                                      // s5
    float v25;                                      // s16
    float v26;                                      // s6
    sead::Vector3f* v27;                            // x26
    float v28;                                      // s0
    float* v29;                                     // x0
    float v30;                                      // s0
    float v31;                                      // s1
    float v32;                                      // s2
    float v33;                                      // s0
    float v34;                                      // s1
    float* v35;                                     // x0
    float v36;                                      // s0
    float v37;                                      // s1
    float v38;                                      // s2
    float v39;                                      // s0
    float v40;                                      // s2
    float v41;                                      // s1
    float v42;                                      // s0
    float v43;                                      // s3
    float v44;                                      // s4
    float v45;                                      // s0
    float y;                                        // s2
    float v47;                                      // s0
    float v48;                                      // s8
    float v49;                                      // s9
    float v50;                                      // s0
    int mNumCollideResult;                          // w24
    al::KCollisionServer* mKCServer;                // x0
    sead::Vector3f v53;                             // [xsp+10h] [xbp-130h] BYREF
    sead::Vector3f a4;                              // [xsp+20h] [xbp-120h] BYREF
    sead::Vector3f v55;                             // [xsp+30h] [xbp-110h] BYREF
    sead::Vector3f a1;                              // [xsp+40h] [xbp-100h] FORCED BYREF
    float v61;                                      // [xsp+68h] [xbp-D8h]
    sead::Vector3f a3;                              // [xsp+90h] [xbp-B0h] BYREF
    sead::Vector3f partsa;                          // [xsp+A0h] [xbp-A0h] BYREF
    char v65[4];                                    // [xsp+BCh] [xbp-84h] BYREF

    mParts = parts;
    unk6 = parts->mMtxScale;
    mCollisionShapeKeeper = this->mCollisionShapeKeeper;
    mCollisionShapeKeeper->calcRelativeShapeInfo(parts->mBaseInvMtx);
    v5 = this->mCollisionShapeKeeper;
    mPtrNum = v5->mCollisionShape.size();
    if (mPtrNum >= 1) {
        v7 = 0;
        while (1) {
            this->mCurrentShapeIndex = v7;
            ShapeInfoBase = v5->getShapeInfoBase(v7);
            v9 = ShapeInfoBase;
            v10 = false;
            if (CollisionShapeFunction::isShapeArrow(ShapeInfoBase))
                break;

            if (CollisionShapeFunction::isShapeDisk(v9)) {
                CRASH
                /*
                v14 = a2->mBaseMtx.m[0][3];
                v15 = a2->mBaseMtx.m[1][3];
                v16 = a2->mBaseMtx.m[2][3];
                mBoundingSphereRange = a2->mBoundingSphereRange;
                ShapeInfoDisk = (float *)CollisionShapeFunction::getShapeInfoDisk(v9);
                v19 = ShapeInfoDisk[20] - v14;
                v20 = ShapeInfoDisk[21] - v15;
                v21 = ShapeInfoDisk[22] - v16;
                v23 = ShapeInfoDisk[23];
                v22 = ShapeInfoDisk[24];
                v24 = ShapeInfoDisk[25];
                v25 = (float)((float)(v19 * v23) + (float)(v20 * v22)) + (float)(v21 * v24);
                v26 = -v25;
                if ( v25 <= 0.0 )
                  v25 = -v25;

                if ( v25 > (float)(mBoundingSphereRange + ShapeInfoDisk[19]) )
                  goto LABEL_14;

                LOBYTE(v13) = sqrtf(
                                (float)((float)(v21 + (float)(v24 * v26)) * (float)(v21 +
                (float)(v24 * v26)))
                              + (float)((float)((float)(v19 + (float)(v23 * v26)) * (float)(v19 +
                (float)(v23 * v26)))
                                      + (float)((float)(v20 + (float)(v22 * v26)) * (float)(v20 +
                (float)(v22 * v26))))) > (float)(mBoundingSphereRange + ShapeInfoDisk[11]);
                */
            } else {
                v13 = alCollisionUtil::isFarAway(*parts, v9->getBoundingCenterWorld(),
                                                 v9->getBoundingRadiusWorld());
            }

        LABEL_17:
            if ((v13 & 1) == 0) {
                sead::Delegate2<CollisionMultiShape, const al::KCPrismData*,
                                const al::KCPrismHeader*>
                    delegate(this, &CollisionMultiShape::callbackFromServer);
                sub_71003F78A8(parts->mKCollisionServer, v9, parts, sead::Vector3f::zero, delegate,
                               mCheckedTriangles);
            }

            if (++v7 == mPtrNum)
                return;

            v5 = this->mCollisionShapeKeeper;
        }

        a1.x = parts->mBaseMtx.m[0][3];
        a1.y = parts->mBaseMtx.m[1][3];
        a1.z = parts->mBaseMtx.m[2][3];
        v11 = parts->mBoundingSphereRange;
        ShapeInfoArrow = CollisionShapeFunction::getShapeInfoArrow(v9);
        if (al::isNearCollideSphereAabb(a1, v11, ShapeInfoArrow->mAabb)) {
            v13 = al::checkHitSegmentSphere(a1, ShapeInfoArrow->vec2, ShapeInfoArrow->vec3, v11,
                                            0LL, 0LL) ^
                  1;
            goto LABEL_17;
        }

    LABEL_14:
        v13 = 1;
        goto LABEL_17;
    }
}

void CollisionMultiShape::callbackFromServer(al::KCPrismData const* data,
                                             al::KCPrismHeader const* header) {
    if (mHeader == header) {
        if (mCheckedTriangles.search(data) != -1)
            return;
    } else {
        mHeader = header;
        mCheckedTriangles.clear();
    }
    mCheckedTriangles.pushBack(data);

    if (mCollisionShapeKeeper->isShapeArrow(mCurrentShapeIndex)) {
        const CollisionShapeInfoArrow* arrow =
            mCollisionShapeKeeper->getShapeInfoArrow(mCurrentShapeIndex);
        al::ArrowHitInfo info = {};
        info.hitInfo->triangle.fillData(*mParts, data, header);

        /*if ( v12->someCounter && !v12->mIsMoving
            || al::isNearZero(&this->unk3, 0.001)
            || (v13 = al::Triangle::getFaceNormal(&info.triangle),
                (float)((float)((float)(v13->x * this->unk3.x) + (float)(v13->y * this->unk3.y)) +
           (float)(v13->z * this->unk3.z)) <= 0.0) )
        */
        if (false)
            return;

        f32 a3a = 0.0f;
        sead::Vector3f v80 = arrow->vec5;  // - unk4; -- only some value if moving
        u8 v87 = 0;
        bool hitarrow =
            mParts->mKCollisionServer->KCHitArrow(data, header, v80, arrow->vec6, &a3a, &v87);
        if (!hitarrow)
            return;

        sead::Vector3f v17 = (arrow->vec5 /*+ unk4*/) + (a3a * arrow->vec6);
        f32 v20 = (1.0f - a3a) * arrow->vec4.length();
        info.hitInfo->collisionLocation = (al::CollisionLocation)v87;
        info.hitInfo->_70 = v20;
        info.hitInfo->collisionHitPos.setMul(mParts->mBaseMtx, v17);

        // something if moving

        CollidedShapeResult result = {arrow};
        result.setArrowHitInfo(info);

        if (v20 < arrow->a5) {
            if (mCollisionShapeKeeper->isCollidedSupportResultFull())
                mCollisionShapeKeeper->registerCollideSupportResult(result);
            return;
        }

        if (!mCollisionShapeKeeper->isCollidedResultFull())
            mCollisionShapeKeeper->registerCollideResult(result);
    } else if (mCollisionShapeKeeper->isShapeSphere(mCurrentShapeIndex)) {
        al::SphereHitInfo info = {};
        info.hitInfo->triangle.fillData(*mParts, data, header);

        const CollisionShapeInfoSphere* sphere =
            mCollisionShapeKeeper->getShapeInfoSphere(mCurrentShapeIndex);
        sead::Vector3f a3a = sphere->mRelativeShapeInfo;  // + unk4; -- only some value if moving
        sead::Vector3f v75 = a3a;
        f32 v74 = 0.0f;
        u8 v73 = 0;
        dbg_printf("KCHitSphereForPlayer(%p(%d), %p, (%.02f, %.02f, %.02f), %f, %f)\n", data,
               data->triIndex, header, v75.x, v75.y, v75.z, sphere->mBoundingRadiusWorld * unk6,
               unk6);
        bool hitsphere = mParts->mKCollisionServer->KCHitSphereForPlayer(
            data, header, &v75, sphere->mBoundingRadiusWorld * unk6, unk6, &v74, &v73);
        dbg_printf("hitSphereResult = %s\n", hitsphere ? "true" : "false");
        if (!hitsphere)
            return;

        f32 v35 = al::isNearZero(unk6, 0.001f) ? 0.0f : 1.0f / unk6;

        sead::Vector3f v72;
        alKCollisionFunc::calcSphereHitPos(&v72, mParts->mKCollisionServer, a3a, *data, header,
                                           v73);
        info.hitInfo->_80.setMul(mParts->mBaseMtx, a3a);
        info.hitInfo->collisionLocation = (al::CollisionLocation) v73;
        info.hitInfo->_70 = v35 * v74;
        info.hitInfo->collisionHitPos.setMul(mParts->mBaseMtx, v72);

        CollidedShapeResult result = {sphere};
        result.setSphereHitInfo(info);

        if (!mCollisionShapeKeeper->isCollidedResultFull())
            mCollisionShapeKeeper->registerCollideResult(result);
    } else if (mCollisionShapeKeeper->isShapeDisk(mCurrentShapeIndex)) {
        CRASH
    } else {
        CRASH
    }
}

}  // namespace game
