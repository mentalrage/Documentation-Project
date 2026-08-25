// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 00051U
// Source by-file doc: by-file/CriticalSection.md
// UID:00051V | by-class/CriticalSection.md | Completion:94 | Confidence:95
#include "CriticalSection.h"

// UID:000520 | by-memory/0x0049bcb0-0x0049bcbe.CriticalSectionConstructor.md | Completion:94 | Confidence:96
CriticalSection::CriticalSection()
{
    InitializeCriticalSection(&m_section);
}

// UID:00051W | by-memory/0x0049bcc0-0x0049bcc8.CriticalSectionDestructorSharedTail.md | Completion:92 | Confidence:94
CriticalSection::~CriticalSection()
{
    DeleteCriticalSection(&m_section);
}

// UID:000524 | by-memory/0x0049bcd0-0x0049bcd8.CriticalSectionEnterRaw.md | Completion:93 | Confidence:95
void CriticalSection::Enter()
{
    EnterCriticalSection(&m_section);
}

// UID:000521 | by-memory/0x0049bce0-0x0049bce8.CriticalSectionLeaveRaw.md | Completion:93 | Confidence:95
void CriticalSection::Leave()
{
    LeaveCriticalSection(&m_section);
}

// UID:00003C | by-class/CriticalSectionLock.md | Completion:94 | Confidence:95
// UID:00051X | by-memory/0x0049bcf0-0x0049bd09.CriticalSectionLockConstructor.md | Completion:94 | Confidence:96
CriticalSectionLock::CriticalSectionLock(CriticalSection *criticalSection)
    : m_criticalSection(criticalSection)
{
    m_criticalSection->Enter();
}

// UID:000522 | by-memory/0x0049bd10-0x0049bd19.CriticalSectionLockDestructor.md | Completion:94 | Confidence:96
CriticalSectionLock::~CriticalSectionLock()
{
    m_criticalSection->Leave();
}
