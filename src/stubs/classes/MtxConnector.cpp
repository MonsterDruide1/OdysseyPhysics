#include "Library/Collision/PartsMtxConnector.h"

namespace al {

al::MtxConnector::MtxConnector() {WARN_UNIMPL;}
MtxConnector::MtxConnector(const sead::Quatf&, const sead::Vector3f&) {CRASH}
bool MtxConnector::isConnecting() const {CRASH}
void MtxConnector::clear() {WARN_UNIMPL;}
void MtxConnector::init(const sead::Matrix34f*, const sead::Matrix34f&) const {WARN_UNIMPL;}
void MtxConnector::init(const sead::Matrix34f*) const {CRASH}
void MtxConnector::multVec(sead::Vector3f*, const sead::Vector3f&) const {CRASH}
void MtxConnector::multTrans(sead::Vector3f*, const sead::Vector3f&) const {CRASH}
void MtxConnector::multMtx(sead::Matrix34f*, const sead::Matrix34f&) const {CRASH}
void MtxConnector::multQT(sead::Quatf*, sead::Vector3f*, sead::Vector3f*) const {CRASH}
void MtxConnector::multQT(sead::Quatf*, sead::Vector3f*, sead::Vector3f*, const sead::Quatf&, const sead::Vector3f&) const {CRASH}
void MtxConnector::multQT(sead::Quatf*, sead::Vector3f*, const sead::Quatf&, const sead::Vector3f&) const {CRASH}
const sead::Quatf& MtxConnector::getBaseQuat() const {CRASH}
const sead::Vector3f& MtxConnector::getBaseTrans() const {CRASH}
void MtxConnector::setBaseQuatTrans(const sead::Quatf&, const sead::Vector3f&) {WARN_UNIMPL;}
void MtxConnector::calcConnectInfo(sead::Vector3f*, sead::Quatf*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&) const {CRASH}
void MtxConnector::calcMtxWithOffset(sead::Matrix34f*, const sead::Vector3f&, const sead::Vector3f&) const {CRASH}
bool MtxConnector::tryGetParentTrans(sead::Vector3f*) const {CRASH}

}  // namespace al
