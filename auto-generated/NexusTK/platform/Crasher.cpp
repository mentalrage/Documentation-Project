// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000II
// Source by-file doc: by-file/Crasher.md
// UID:00003A | by-class/Crasher.md | Completion:93 | Confidence:94
#include "Crasher.h"
#include "ExceptionHandler.h"

// UID:0000QM | by-global/g_pCrasher.md | Completion:93 | Confidence:95
Crasher *g_pCrasher = 0;

template <>
Singleton<Crasher>::Singleton()
{
    g_pCrasher = static_cast<Crasher *>(this);
}

template <>
Singleton<Crasher>::~Singleton()
{
    g_pCrasher = 0;
}

// UID:000298 | by-memory/0x0067ab38-0x0067ab3c.g_pCrasher.md | Completion:93 | Confidence:95
// Emitted code for this range is covered by [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md).

// UID:000129 | by-memory/0x0049bae0-0x0049bbef.Crasher.md | Completion:93 | Confidence:95
Crasher::Crasher()
    : Pane(0)
{
}

Crasher::~Crasher()
{
}

bool Crasher::OnTimer(int timerId, int arg0, int arg1)
{
    g_pCrashTarget->SetSkipCrashReport(true);
    *reinterpret_cast<volatile unsigned long *>(0) = 0x6675636bUL;
    return true;
}
