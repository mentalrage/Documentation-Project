// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P7
// Source by-file doc: by-file/WaitableTimer.md
// UID:0002L8 | by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md | Completion:94 | Confidence:94
void WaitableTimer::StartMultimediaTimer(UINT delayMilliseconds)
{
    m_isRunning = true;
    m_callbackGateEvent = g_pfnCreateEventW(NULL, FALSE, FALSE, NULL);

    UINT timerId = 0;
    do
    {
        timerId = timeSetEvent(delayMilliseconds, 5, WaitableTimerCallback,
                               reinterpret_cast<DWORD_PTR>(this), 0);
    }
    while (timerId == 0);

    m_timerId = timerId;
    SetEvent(m_callbackGateEvent);
}

// UID:0002L9 | by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md | Completion:94 | Confidence:94
void WaitableTimer::CancelMultimediaTimer()
{
    EnterCriticalSection(&m_criticalSection);

    m_isRunning = false;
    timeKillEvent(m_timerId);
    CloseHandle(m_callbackGateEvent);
    ResetEvent(m_completionEvent);
    m_timerId = 0;
    m_callbackGateEvent = NULL;

    LeaveCriticalSection(&m_criticalSection);
}

// UID:0000FY | by-class\WaitableTimer.md | Completion:92 | Confidence:92 | Empty Emitter Marker

// UID:0001NX | by-memory\0x005c0ff0-0x005c129a.WaitableTimer.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:0002P2 | by-memory\0x00631184-0x0063118c.WaitableTimerVtableData.md | Completion:92 | Confidence:95 | Empty Emitter Marker

// UID:0001WI | by-type\by-struct\WaitableTimerLayout.md | Completion:92 | Confidence:94 | Empty Emitter Marker

// UID:0001Z2 | by-type\by-vtable\WaitableTimerVtable.md | Completion:92 | Confidence:95 | Empty Emitter Marker
