// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000I6
// Source by-file doc: by-file/CheatDetector.md
// UID:0000QJ | by-global/g_pCheatDetector.md | Completion:92 | Confidence:94
class CheatDetector;

CheatDetector *g_pCheatDetector = 0;

// UID:000020 | by-class/CheatDetector.md | Completion:92 | Confidence:94
class CheatDetector : public Singleton<CheatDetector>, public TimerHandler
{
public:
    CheatDetector();
    virtual ~CheatDetector() {}

    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void CaptureTimeSnapshot(unsigned int *timerTick, unsigned __int64 *systemFileTime);

    unsigned __int64 m_lastSystemFileTime;
    unsigned int m_lastTimerTick;
    unsigned int m_baselineTimerTick;
    unsigned __int64 m_baselineSystemFileTime;
};

extern CheatDetector *g_pCheatDetector;

// UID:0004UO | by-memory/0x00483f00-0x00483f86.CheatDetectorConstructor.md | Completion:92 | Confidence:94
CheatDetector::CheatDetector()
    : m_lastTimerTick(0),
      m_baselineTimerTick(0),
      m_baselineSystemFileTime(0)
{
}

// UID:0002EN | by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md | Completion:90 | Confidence:92
void CheatDetector::CaptureTimeSnapshot(unsigned int *timerTick, unsigned __int64 *systemFileTime)
{
    FILETIME fileTime;
    GetSystemTimeAsFileTime(&fileTime);

    const unsigned __int64 capturedFileTime =
        (static_cast<unsigned __int64>(fileTime.dwHighDateTime) << 32) |
        fileTime.dwLowDateTime;

    m_lastSystemFileTime = capturedFileTime;

    const unsigned int currentTick = g_pTimerMgr->m_currentTick;
    m_lastTimerTick = currentTick;

    *timerTick = currentTick;
    *systemFileTime = capturedFileTime;
}

// UID:0004UP | by-memory/0x00483fe0-0x00483fe5.CheatDetectorOnTimer.md | Completion:92 | Confidence:96
bool CheatDetector::OnTimer(int timerId, int arg0, int arg1)
{
    return true;
}
