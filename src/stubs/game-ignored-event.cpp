#include "MapObj/CapMessageShowInfo.h"
#include "Npc/NpcEventStateScare.h"
#include "Npc/TalkNpcCap.h"
#include "Util/InputInterruptTutorialUtil.h"
#include "Util/NpcEventFlowUtil.h"

al::EventFlowExecutor* rs::initEventFlow(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*) {WARN_UNIMPL;return nullptr;}
void rs::startEventFlow(al::EventFlowExecutor*, char const*) {}
bool rs::updateEventFlow(al::EventFlowExecutor*) {return false;}
al::EventFlowExecutor* rs::initEventFlowSuffix(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, char const*) {WARN_UNIMPL;return nullptr;}
void rs::initEventMessageTagDataHolder(al::EventFlowExecutor*, al::MessageTagDataHolder const*) {}

void rs::showCapMessage(al::IUseSceneObjHolder const*, char const*, int, int) {}
bool rs::isActiveCapMessage(al::IUseSceneObjHolder const*) {return false;}
void rs::requestSwitchTalkNpcEventVolleyBall(al::LiveActor*, int) {}
bool rs::tryAppearObjectTutorial(al::IUseSceneObjHolder const*, char const*) {return false;}
bool rs::tryCloseObjectTutorial(al::IUseSceneObjHolder const*, char const*) {return false;}
void rs::setEventBalloonFilterOnlyMiniGame(al::LiveActor const*) {}
void rs::resetEventBalloonFilter(al::LiveActor const*) {}
bool rs::tryShowCapMessageFromCurrentStageMsg(al::IUseSceneObjHolder const*, char const*, int, int) {return false;}
bool rs::isDefinedEventCamera(al::EventFlowExecutor const*, char const*) {return false;}

NpcEventStateScare::NpcEventStateScare(al::LiveActor* x, NpcEventStateScareActionParam const*) : al::ActorStateBase("", x) {WARN_UNIMPL;}
void NpcEventStateScare::kill() {}
bool NpcEventStateScare::tryStart(al::EventFlowExecutor const*) {return false;}

NpcEventStateScareActionParam::NpcEventStateScareActionParam(const char*) {}
NpcEventStateScareActionParam::NpcEventStateScareActionParam(const char*, const char*, const char*) {}

TalkNpcCap* TalkNpcCap::createForVolleyballNpc(al::LiveActor const*, al::ActorInitInfo const&) {WARN_UNIMPL;return nullptr;}
