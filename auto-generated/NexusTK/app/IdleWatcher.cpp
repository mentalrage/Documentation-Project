// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K0
// Source by-file doc: by-file/IdleWatcher.md
// UID:00006C | by-class/IdleWatcher.md | Completion:92 | Confidence:94
class IdleWatcher : public Pane, public Singleton<IdleWatcher>
{
public:
    explicit IdleWatcher(unsigned int idleIntervalMs);
    virtual ~IdleWatcher();

    bool IsIdle() const { return m_isIdle; }
    void ResetIdleTimer();

protected:
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    bool m_isIdle;
    unsigned int m_idleIntervalMs;
};

// UID:0004LE | by-memory/0x004cfe60-0x004cfeba.IdleWatcherConstructor.md | Completion:92 | Confidence:94
IdleWatcher::IdleWatcher(unsigned int idleIntervalMs)
    : Pane(4),
      Singleton<IdleWatcher>(),
      m_isIdle(true),
      m_idleIntervalMs(idleIntervalMs)
{
}

// UID:0004LF | by-memory/0x004cfec0-0x004cfee9.IdleWatcherDestructor.md | Completion:91 | Confidence:94
IdleWatcher::~IdleWatcher()
{
}

// UID:0004LG | by-memory/0x004cfef0-0x004cff20.IdleWatcherResetIdleTimer.md | Completion:92 | Confidence:94
void IdleWatcher::ResetIdleTimer()
{
    m_isIdle = false;
    RemovePendingTimers();
    ScheduleTimer(0, m_idleIntervalMs, 0, 0);
}

// UID:0004LH | by-memory/0x004cff20-0x004cff37.IdleWatcherOnTimer.md | Completion:92 | Confidence:94
bool IdleWatcher::OnTimer(int, int, int)
{
    m_isIdle = true;
    ScheduleTimer(0, m_idleIntervalMs, 0, 0);
    return true;
}


// UID:0002VY | by-memory/0x0069af1c-0x0069af20.g_pIdleWatcher.md | Completion:91 | Confidence:94
IdleWatcher *g_pIdleWatcher = 0;

// UID:0003BP | by-memory\0x0061b568-0x0061b640.IdleWatcherVtableData.md | Completion:91 | Confidence:94 | Empty Emitter Marker
