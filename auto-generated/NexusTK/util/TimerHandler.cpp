// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0004ZO
// Source by-file doc: by-file/TimerHandler.md
// UID:0000F0 | by-class/TimerHandler.md | Completion:89 | Confidence:91
#include "TimerHandler.h"
#include "TimerMgr.h"

// UID:0001K7 | by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md | Completion:89 | Confidence:91
TimerHandler::~TimerHandler()
{
    g_pTimerMgr->RemovePendingTimersForOwner(this);
}

// UID:0001K8 | by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md | Completion:87 | Confidence:89
void TimerHandler::ScheduleTimer(int timerId, unsigned int delayMs, int arg0, int arg1)
{
    g_pTimerMgr->ScheduleTimer(this, timerId, delayMs, arg0, arg1);
}

void TimerHandler::RemovePendingTimers()
{
    g_pTimerMgr->RemovePendingTimersForOwner(this);
}

// UID:0001K9 | by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md | Completion:89 | Confidence:91
void TimerHandler::CancelTimer(int timerId)
{
    g_pTimerMgr->CancelTimer(this, timerId);
}

void TimerHandler::CancelPendingTimersExceptEvent(int timerId)
{
    g_pTimerMgr->CancelPendingTimersExceptEvent(this, timerId);
}

// UID:0003E0 | by-memory\0x0062e334-0x0062e340.TimerHandlerVtableData.md | Completion:86 | Confidence:92 | Empty Emitter Marker
