// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LI
// Source by-file doc: by-file/Monitor.md
// UID:00008L | by-class/Monitor.md | Completion:94 | Confidence:95
#pragma once

#include <windows.h>

class MonitorCondition;

class Monitor
{
    friend class MonitorCondition;

public:
    Monitor();
    virtual ~Monitor();

    void Lock();
    void Unlock();

private:
    HANDLE m_mutex;
    int m_waiterCount;
    HANDLE m_semaphore;
};

// UID:00008M | by-class/MonitorCondition.md | Completion:94 | Confidence:95
class MonitorCondition
{
public:
    explicit MonitorCondition(Monitor *monitor);
    virtual ~MonitorCondition();

    void Wait();
    void Signal();

private:
    Monitor *m_monitor;
    int m_waiterCount;
    HANDLE m_semaphore;
};
