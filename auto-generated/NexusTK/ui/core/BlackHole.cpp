// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HR
// Source by-file doc: by-file/BlackHole.md
// UID:00000W | by-class/BlackHole.md | Completion:96 | Confidence:97
#include "BlackHole.h"
#include "Pane.h"
#include "../../util/TimerMgr.h"

// UID:0002M0 | by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md | Completion:94 | Confidence:96
BlackHole::BlackHole()
    : List(sizeof(LObject *), 1024)
{
    g_pApplicationCleanupQueue = this;
}

// UID:0002M1 | by-memory/0x00469100-0x00469115.BlackHoleDestructor.md | Completion:94 | Confidence:96
BlackHole::~BlackHole()
{
    g_pApplicationCleanupQueue = NULL;
}

// UID:0002M3 | by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md | Completion:95 | Confidence:96
void BlackHole::EnqueueIfMissing(LObject *object)
{
    if (object == NULL)
        return;

    for (int i = 0; i < m_count; ++i)
    {
        LObject *queuedObject = *reinterpret_cast<LObject **>(GetElementAt(i));
        if (queuedObject == object)
            return;
    }

    Append(1, &object);
}

// UID:0000Z1 | by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md | Completion:96 | Confidence:97
void BlackHole::QueuePaneForDeferredDeletion(Pane *pane)
{
    if (pane == NULL)
        return;

    pane->RemoveFromLayer();
    pane->UnregisterEventHandler();
    g_pTimerMgr->RemovePendingTimersForOwner(
        static_cast<TimerHandler *>(pane));
    EnqueueIfMissing(pane);
}

// UID:0002M4 | by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md | Completion:95 | Confidence:96
void BlackHole::ReleaseQueuedOwnedObjects()
{
    for (int i = 0; i < m_count; ++i)
    {
        LObject* object = *reinterpret_cast<LObject**>(GetElementAt(i));
        if (object != NULL)
            delete object;
    }

    RemoveAll();
}

// UID:0002M2 | by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md | Completion:94 | Confidence:96
// MSVC emits BlackHole's scalar deleting destructor from virtual ~BlackHole();
// do not hand-author a separate source body for 0x00469240.

// UID:0001TT | by-type/by-struct/BlackHoleLayout.md | Completion:94 | Confidence:97
// BlackHole's 0x14-byte object layout is represented by the source declaration
// `class BlackHole : public List`; no standalone layout struct is emitted here.

// UID:0001X2 | by-type/by-vtable/BlackHoleVtable.md | Completion:94 | Confidence:97
// BlackHole's vtable at 0x00613118 is compiler-emitted from the virtual
// destructor declaration and inherited List virtual surface; no raw vtable
// array is hand-authored here.

// UID:0000Q8 | by-global/g_pApplicationCleanupQueue.md | Completion:94 | Confidence:96
BlackHole *g_pApplicationCleanupQueue = 0;
// UID:00028K | by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md | Completion:93 | Confidence:96
// Backing storage for g_pApplicationCleanupQueue is emitted by [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md);
// the binary slot at 0x0067a74c is zero-initialized .data and is not duplicated.
