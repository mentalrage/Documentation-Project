// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LI
// Source by-file doc: by-file/Monitor.md
// UID:00008L | by-class/Monitor.md | Completion:94 | Confidence:95
#include "Monitor.h"
#include "Error.h"

// UID:00051Y | by-memory/0x005285e0-0x005286c8.MonitorConstructor.md | Completion:94 | Confidence:96
Monitor::Monitor()
    : m_mutex(0),
      m_waiterCount(0),
      m_semaphore(0)
{
    m_mutex = CreateMutexW(0, FALSE, 0);
    if (m_mutex == 0)
        throw new Win32Error;

    m_semaphore = CreateSemaphoreW(0, 0, 0x7fffffff, 0);
    if (m_semaphore == 0)
        throw new Win32Error;
}

// UID:000523 | by-memory/0x005286d0-0x00528705.MonitorDestructorRaw.md | Completion:93 | Confidence:95
Monitor::~Monitor()
{
    if (m_semaphore != 0) {
        CloseHandle(m_semaphore);
        m_semaphore = 0;
    }

    if (m_mutex != 0) {
        CloseHandle(m_mutex);
        m_mutex = 0;
    }
}

// UID:00051Z | by-memory/0x00528710-0x0052871c.MonitorLock.md | Completion:95 | Confidence:97
void Monitor::Lock()
{
    WaitForSingleObject(m_mutex, INFINITE);
}

// UID:000525 | by-memory/0x00528720-0x0052873e.MonitorUnlock.md | Completion:95 | Confidence:97
void Monitor::Unlock()
{
    if (m_waiterCount > 0)
        ReleaseSemaphore(m_semaphore, 1, 0);
    else
        ReleaseMutex(m_mutex);
}

// UID:00008M | by-class/MonitorCondition.md | Completion:94 | Confidence:95
// UID:00052A | by-memory/0x00528740-0x005287e0.MonitorConditionConstructor.md | Completion:94 | Confidence:96
MonitorCondition::MonitorCondition(Monitor *monitor)
    : m_monitor(monitor),
      m_waiterCount(0),
      m_semaphore(0)
{
    m_semaphore = CreateSemaphoreW(0, 0, 0x7fffffff, 0);
    if (m_semaphore == 0)
        throw new Win32Error;
}

// UID:00052E | by-memory/0x005287f0-0x00528810.MonitorConditionDestructorRaw.md | Completion:93 | Confidence:95
MonitorCondition::~MonitorCondition()
{
    if (m_semaphore != 0) {
        CloseHandle(m_semaphore);
        m_semaphore = 0;
    }
}

// UID:000526 | by-memory/0x00528810-0x00528855.MonitorConditionWait.md | Completion:95 | Confidence:97
void MonitorCondition::Wait()
{
    ++m_waiterCount;

    if (m_monitor->m_waiterCount > 0)
        ReleaseSemaphore(m_monitor->m_semaphore, 1, 0);
    else
        ReleaseMutex(m_monitor->m_mutex);

    WaitForSingleObject(m_semaphore, INFINITE);
    --m_waiterCount;
}

// UID:00052B | by-memory/0x00528860-0x00528892.MonitorConditionSignal.md | Completion:95 | Confidence:97
void MonitorCondition::Signal()
{
    if (m_waiterCount <= 0)
        return;

    ++m_monitor->m_waiterCount;
    ReleaseSemaphore(m_semaphore, 1, 0);
    WaitForSingleObject(m_monitor->m_semaphore, INFINITE);
    --m_monitor->m_waiterCount;
}
