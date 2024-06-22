
#include "Library/Controller/JoyPadAccelPoseAnalyzer.h"

namespace al {

bool JoyPadAccelPoseAnalyzer::isSwingAnyHand() const {return false;}
bool JoyPadAccelPoseAnalyzer::isSwingLeftHand() const {return false;}
bool JoyPadAccelPoseAnalyzer::isSwingRightHand() const {return false;}
bool JoyPadAccelPoseAnalyzer::isSwingDoubleHandSameDir() const {return false;}
void JoyPadAccelPoseAnalyzer::setSwingBorder(f32 val1, f32 val2) {
    mSwingBorder = {val1, val2};
}
const sead::Vector2f& al::JoyPadAccelPoseAnalyzer::getSwingDirDoubleHandSameDir() const {return sead::Vector2f::zero;}

}
