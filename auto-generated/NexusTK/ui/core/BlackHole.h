// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HR
// Source by-file doc: by-file/BlackHole.md
// UID:00000W | by-class/BlackHole.md | Completion:96 | Confidence:97
#ifndef NEXUSTK_UI_CORE_BLACKHOLE_H
#define NEXUSTK_UI_CORE_BLACKHOLE_H

#include "../../util/List.h"
#include "../../util/Singleton.h"

class Pane;

class BlackHole : public List, public Singleton<BlackHole>
{
public:
    BlackHole();
    virtual ~BlackHole();

    void EnqueueIfMissing(LObject *object);
    void QueuePaneForDeferredDeletion(Pane *pane);
    void ReleaseQueuedOwnedObjects();
};

extern BlackHole *g_pApplicationCleanupQueue;

typedef char BlackHoleSizeMustBe20[
    sizeof(BlackHole) == 0x14 ? 1 : -1];

#endif
