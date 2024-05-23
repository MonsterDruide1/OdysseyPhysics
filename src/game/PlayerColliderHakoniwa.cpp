#include "game/PlayerColliderHakoniwa.h"
#include "Library/Collision/CollisionDirector.h"
#include "../stubs/missing.h"

namespace game {
void helperFunc(CollisionShapeKeeper* keeper, const sead::Vector3f& pos);

PlayerColliderHakoniwa::PlayerColliderHakoniwa(LiveActor* actor, const PlayerConst* c, CollisionPartsKeeper* partsKeeper) : mPlayer(actor), mPlayerConst(c) {
    //FIXME proper instance
    al::CollisionDirector* director = (al::CollisionDirector*)(&partsKeeper - 1);
    mPlayerCollider = new PlayerCollider(director, actor->mPoseKeeper->getMtxPtr(), actor->mPoseKeeper->getTransPtr(), actor->mPoseKeeper->getGravityPtr(), false);
    mShapeKeeperNormal = new CollisionShapeKeeper(5, 64, 32);

    mShapeKeeperNormal->unk3 = 25.0f;
    mShapeKeeperNormal->unk4 = 25.0f;
    helperFunc(mShapeKeeperNormal, sead::Vector3f::zero);
    mShapeKeeperNormal->createShapeSphereSupportGround("Body", 55.0f, sead::Vector3f::ey*65.0f, sead::Vector3f::ey, 14.5f);
    mShapeKeeperNormal->createShapeSphere("Head", 55.0f, sead::Vector3f::ey*105.0f);
    mShapeKeeperNormal->updateShape();

    mPlayerCollider->setCollisionShapeKeeper(mShapeKeeperNormal);
}

PlayerColliderHakoniwa::~PlayerColliderHakoniwa() {
    delete mPlayerCollider;
    delete mShapeKeeperNormal;
}

sead::Vector3f PlayerColliderHakoniwa::updateCollider(const sead::Vector3f& pos) {
    return mPlayerCollider->collide(pos);
}

const char* legNames[3] = {"LegFront", "LegLeft", "LegRight"};

void helperFunc(CollisionShapeKeeper* keeper, const sead::Vector3f& pos) {
    float v2; // s14
  float v3; // s15
  float v4; // s8
  float v8; // s10
  float v9; // s0
  const char *v10; // x1
  float v11; // s2
  float v12; // s0
  float v13; // s5
  float v14; // s3
  float v15; // s6
  float v16; // s4
  float v17; // s7
  float v18; // s20
  float v19; // s3
  float y; // s16
  float v21; // s1
  float v22; // s2
  sead::Vector3f a4; // [xsp+10h] [xbp-90h] BYREF
  sead::Vector3f a3; // [xsp+20h] [xbp-80h] BYREF
  float v26; // [xsp+78h] [xbp-28h]
  float v27; // [xsp+7Ch] [xbp-24h]

  v2 = 0.0 * 30.0;
  v3 = 0.0 * 30.0;
  v4 = 1.0 * 30.0;
  v27 = 0.0 * -40.0;
  v26 = 1.0 * -40.0;
  for(int v7=0; v7!=3; v7++)
  {
    v8 = sead::Mathf::cos((float)((float)((float)(int)v7 * 120.0) * 0.017453) * 0.5);
    v9 = sead::Mathf::sin((float)((float)((float)(int)v7 * 120.0) * 0.017453) * 0.5);
    v10 = legNames[v7];
    v11 = v9 * 1.0;
    v12 = v9 * 0.0;
    v13 = (float)(v3 * v8) + (float)((float)(v2 * v12) - (float)(v4 * v12));
    v14 = (float)(v2 * v8) + (float)((float)(v4 * v11) - (float)(v3 * v12));
    v15 = (float)(v4 * v8) + (float)((float)(v3 * v12) - (float)(v2 * v11));
    v16 = (float)((float)-(float)(v2 * v12) - (float)(v3 * v11)) - (float)(v4 * v12);
    v17 = v8 * v14;
    v18 = v12 * v14;
    v19 = (float)(v12 * v13) - (float)(v11 * v14);
    y = pos.y;
    v21 = (float)((float)(v18 + (float)(v8 * v13)) - (float)(v12 * v15)) - (float)(v11 * v16);
    v22 = (float)((float)((float)((float)(v11 * v15) + (float)(v17 - (float)(v12 * v13))) - (float)(v12 * v16)) + pos.x)
        - v27;
    a3.z = (float)((float)((float)((float)(v8 * v15) + v19) - (float)(v12 * v16)) + pos.z) - (float)(0.0 * -40.0);
    a4.x = (float)(0.0 * -40.0) - (float)(0.0 * 20.0);
    a4.y = (float)(1.0 * -40.0) - (float)(1.0 * 20.0);
    a3.x = v22;
    a3.y = (float)(v21 + y) - v26;
    a4.z = a4.x;
    //TODO add these back
    keeper->createShapeArrow(v10, a3, a4, 20.0, v7);
  }
}

}
