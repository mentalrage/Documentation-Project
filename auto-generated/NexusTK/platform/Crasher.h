// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000II
// Source by-file doc: by-file/Crasher.md
// UID:00003A | by-class/Crasher.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_PLATFORM_CRASHER_H
#define NEXUSTK_PLATFORM_CRASHER_H

#include "../ui/core/Pane.h"
#include "../util/Singleton.h"

class Crasher : public Pane, public Singleton<Crasher>
{
public:
    Crasher();
    virtual ~Crasher();
    virtual bool OnTimer(int timerId, int arg0, int arg1);
};

extern Crasher *g_pCrasher;

typedef char CrasherSizeMustBe0xF8[
    sizeof(Crasher) == 0xf8 ? 1 : -1];

#endif
