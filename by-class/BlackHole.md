*** UID:00000W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BlackHole

## Status

- Confidence: strong.
- Likely source file: [UID:0000HR][BlackHole](by-file/BlackHole.md)
- Primary range: [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)
- Exact pane queue helper: [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md)
- Layout: [UID:0001TT][BlackHoleLayout](by-type/by-struct/BlackHoleLayout.md)
- Vtable: [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)

## Class Purpose

`BlackHole` is a singleton deferred deletion queue. It owns a `List` of object pointers, prevents duplicate entries, and releases queued objects by invoking each object's scalar deleting destructor with delete flag `1`.

For panes, `BlackHole` has a specialized queueing helper that first removes the pane from its layer, unregisters it from event dispatch, cancels pending timer events, and only then appends the pointer to the queue.

## Class Shape

- Base family: singleton deferred-deletion queue with an embedded/inherited `List` virtual surface.
- Global state: owns [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md).
- Queue policy: deduplicates object pointers, then scalar-deletes queued objects with delete flag `1`.
- Pane specialization: `QueuePaneForDeferredDeletion` performs layer/event/timer detach before queueing pane objects.
- Source placement: [UID:0000HR][BlackHole](by-file/BlackHole.md).

## Evidence Notes

- IDA `list_globals BlackHole` reports MSVC RTTI and vtable symbols for `BlackHole` and `Singleton<BlackHole>`.
- IDA `lookup_funcs` confirms exact functions at `0x004690b0`, `0x00469100`, `0x00469120`, `0x00469180`, `0x00469200`, and `0x00469240`.
- IDA `.rdata` inspection confirms the primary vtable at `0x00613118` has ten slots: `BlackHole::ScalarDeletingDestructor` followed by the inherited `List` virtual surface.
- `Application::Initialize` calls the constructor at `0x00464549`.
- `Application::CleanupResources` and `ApplicationHelper_4A6C40::ProcessIdleWork` drain the queue through `0x00469200`.
- `0x00469180` reads [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) and calls the timer-manager remove-all-pending-events helper for the pane timer-handler subobject.

## Method Summary

| Address | Working name | Role |
| --- | --- | --- |
| [UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md) | `BlackHole::BlackHole` | Build `List(4, 1024)`, install vtable, store singleton pointer. |
| [UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md) | `BlackHole::~BlackHole` | Clear singleton pointer and destroy the embedded list. |
| [UID:0002M3][0x00469120-0x00469171.BlackHoleEnqueueIfMissing](by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md) | `EnqueueIfMissing` | Deduplicate and append a generic object pointer. |
| [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) | `QueuePaneForDeferredDeletion` | Pane-specific detach/unregister/cancel-timer path before queueing. |
| [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md) | `ReleaseQueuedOwnedObjects` | Scalar-delete every queued object and clear the list. |
| [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md) | `ScalarDeletingDestructor` | Deleting destructor wrapper. |

## Remaining Caveats

- Older recovery notes that said the non-deleting destructor wrapper was omitted are stale; live IDA has a real `0x00469100-0x00469115` body.
- Older owner-context notes routed `0x00469180` through `PaneChildRegistry`, but live IDA shows this is a `BlackHole` pane-deletion queue helper.
- The shared body at `0x004f30e0` is a [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md), not a unique BlackHole destructor candidate.
- Live IDA confirms [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md) at `0x00613118`.
- Cleanup writes clear [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md), the singleton pointer, not an unrelated global manager pointer.

## Cross-References

- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)
- [UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md)
- [UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md)
- [UID:0002M3][0x00469120-0x00469171.BlackHoleEnqueueIfMissing](by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md)
- [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md)
- [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md)
- [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md)
- [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)
- [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
- [UID:0000A3][PaneChildRegistry](by-class/PaneChildRegistry.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:000079][List](by-class/List.md)
- [UID:00000E][ApplicationHelper_4A6C40](by-class/ApplicationHelper_4A6C40.md)

## Changes

- 2026-06-05 live IDA refresh:
  - What existed before: the page carried stale recovered-source and owner-metadata caveats, a blank parent, and direct raw global/function labels in the caveats.
  - What changed: raised completion to `84`, attached the class to [UID:0000HR][BlackHole](by-file/BlackHole.md), and rewrote caveats around live IDA evidence.
  - Summary/evidence: live IDA reconfirms the six function ranges, vtable and singleton pointer references, queue-drain callers, and pane-deletion queue behavior; final C++ remains blank under the `95/95` gate.

- What existed before: the page had strong method, vtable, and caveat evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `82/92`, and class-shape notes were added for singleton state, queue policy, pane-specialized cleanup, and source placement.
- Summary and evidence: IDA confirms function boundaries, RTTI/vtable symbols, singleton construction/cleanup callers, and queue-drain usage; completion remains below full until final class layout and rewritten source are complete.
- What existed before: the class page summarized methods by raw addresses and did not mark the class as reconstructable in validator metadata.
- What it was changed to: method rows now link to exact child `by-memory` pages and `RECONSTRUCTABLE` is set to `TRUE`.
- Summary and evidence: 2026-05-31 IDA MCP reconfirmed the six child function ranges and vtable stores; no C++ autogen parent/code was added because the final-source threshold is not met.
