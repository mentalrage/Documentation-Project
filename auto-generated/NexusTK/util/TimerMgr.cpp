// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OT
// Source by-file doc: by-file/TimerMgr.md
// UID:0000F1 | by-class/TimerMgr.md | Completion:93 | Confidence:95
#include "TimerMgr.h"

// UID:0002KX | by-memory/0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md | Completion:94 | Confidence:96
DWORD TimerMgr::FindQueuedTimerDueTick(TimerHandler* owner, int timerId) const
{
    for (int index = static_cast<int>(m_timerQueue.size()) - 1;
         index >= 0;
         --index) {
        const ScheduledTimerEvent& event = m_timerQueue[index];
        if (event.owner == owner && event.timerId == timerId) {
            return event.dueTick;
        }
    }

    return 0;
}

// UID:0002KY | by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md | Completion:87 | Confidence:92
void TimerMgr::BeginTimerPeriod()
{
    TIMECAPS caps;
    timeGetDevCaps(&caps, sizeof(caps));

    UINT period = caps.wPeriodMin;
    if (period < 1) {
        period = 1;
    }
    if (period > caps.wPeriodMax) {
        period = caps.wPeriodMax;
    }

    m_timerPeriod = period;
    timeBeginPeriod(period);

    const DWORD now = timeGetTime();
    m_currentTick = now;
    g_timerCurrentTickMirror = now;
    g_timerTickBaselineMirror = now;
}

// UID:0002KZ | by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md | Completion:89 | Confidence:93
void TimerMgr::RefreshCurrentTick()
{
    const DWORD now = timeGetTime();
    m_currentTick = now;
    g_timerCurrentTickMirror = now;
}

// UID:0002L4 | by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md | Completion:88 | Confidence:93
// Compiler-generated scalar deleting destructor wrapper for TimerMgr; source destructor semantics are represented by the TimerMgr destructor and queue/global cleanup docs, not by a standalone handwritten helper body.


// UID:0001VX | by-type/by-struct/ScheduledTimerEvent.md | Completion:92 | Confidence:96
// ScheduledTimerEvent is declared once by UID0000F1's complete TimerMgr header block.

// UID:0001WD | by-type/by-struct/TimerMgrLayout.md | Completion:92 | Confidence:95
// TimerMgr layout is emitted by UID0000F1; this page documents the compiler layout of its std::deque member without declaring a duplicate struct.

// UID:0000SI | by-global/g_pTimerMgr.md | Completion:88 | Confidence:92
TimerMgr* g_pTimerMgr = 0;

// UID:00029S | by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md | Completion:89 | Confidence:92
// Process-lifetime TimerMgr static object storage is generated from the TimerMgr.cpp static instance declaration; this storage page emits no standalone duplicate definition.

// UID:000306 | by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md | Completion:88 | Confidence:91
DWORD g_timerTickBaselineMirror = 0;

// UID:000307 | by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md | Completion:88 | Confidence:91
DWORD g_timerCurrentTickMirror = 0;

// UID:0003E1 | by-memory\0x0062e344-0x0062e354.TimerMgrVtableData.md | Completion:86 | Confidence:92 | Empty Emitter Marker
