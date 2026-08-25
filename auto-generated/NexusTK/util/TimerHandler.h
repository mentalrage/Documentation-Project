// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0004ZO
// Source by-file doc: by-file/TimerHandler.md
// UID:0000F0 | by-class/TimerHandler.md | Completion:89 | Confidence:91
#ifndef NEXUSTK_UTIL_TIMERHANDLER_H
#define NEXUSTK_UTIL_TIMERHANDLER_H

class TimerHandler
{
public:
    TimerHandler();
    virtual ~TimerHandler();
    virtual bool OnTimer(int timerId, int arg0, int arg1) = 0;

    void ScheduleTimer(int timerId, unsigned int delayMs, int arg0, int arg1);
    void RemovePendingTimers();
    void CancelTimer(int timerId);
    void CancelPendingTimersExceptEvent(int timerId);
};

typedef char TimerHandlerSizeMustBe4[sizeof(TimerHandler) == 4 ? 1 : -1];

#endif
