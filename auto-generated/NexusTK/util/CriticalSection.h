// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 00051U
// Source by-file doc: by-file/CriticalSection.md
// UID:00051V | by-class/CriticalSection.md | Completion:94 | Confidence:95
#pragma once

#include <windows.h>

class CriticalSection
{
public:
    CriticalSection();
    ~CriticalSection();

    void Enter();
    void Leave();

private:
    CRITICAL_SECTION m_section;
};

// UID:00003C | by-class/CriticalSectionLock.md | Completion:94 | Confidence:95
class CriticalSectionLock
{
public:
    explicit CriticalSectionLock(CriticalSection *criticalSection);
    ~CriticalSectionLock();

private:
    CriticalSection *m_criticalSection;
};
