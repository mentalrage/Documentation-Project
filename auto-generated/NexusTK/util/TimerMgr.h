// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OT
// Source by-file doc: by-file/TimerMgr.md
// UID:0000F1 | by-class/TimerMgr.md | Completion:93 | Confidence:95
#ifndef NEXUSTK_UTIL_TIMERMGR_H
#define NEXUSTK_UTIL_TIMERMGR_H

#include <windows.h>
#include <deque>
#include "LObject.h"
#include "TimerHandler.h"

struct ScheduledTimerEvent
{
    TimerHandler *owner;
    int timerId;
    DWORD dueTick;
    int arg0;
    int arg1;
};

class TimerMgr : public LObject
{
public:
    TimerMgr();
    virtual ~TimerMgr();

    void DispatchDueTimers();
    void ScheduleTimer(TimerHandler *owner, int timerId,
                       unsigned int delayMs, int arg0, int arg1);
    void RemovePendingTimersForOwner(TimerHandler *owner);
    void CancelTimer(TimerHandler *owner, int timerId);
    void CancelPendingTimersExceptEvent(TimerHandler *owner, int timerId);
    DWORD FindQueuedTimerDueTick(TimerHandler *owner, int timerId) const;
    void BeginTimerPeriod();
    void RefreshCurrentTick();

private:
    std::deque<ScheduledTimerEvent> m_timerQueue;

public:
    DWORD m_currentTick;

private:
    UINT m_timerPeriod;
    DWORD m_nextDueTick;
};

extern TimerMgr *g_pTimerMgr;

#endif
