*** UID:00000W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "BlackHole.h"
#include "Pane.h"
#include "../../util/TimerMgr.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BlackHole

## Status

- Confidence: strong.
- Likely source file: [UID:0000HR][BlackHole](by-file/BlackHole.md)
- Primary range: [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)
- Exact pane queue helper: [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md)
- Layout: [UID:0001TT][BlackHoleLayout](by-type/by-struct/BlackHoleLayout.md)
- Vtable: [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)

## Class Purpose

`BlackHole` is a singleton deferred deletion queue. It uses a `List` primary-base layout for owned polymorphic object pointers, prevents duplicate entries, and releases queued objects through source-equivalent virtual deletion.

For panes, `BlackHole` has a specialized queueing helper that first removes the pane from its layer, unregisters it from event dispatch, cancels pending timer events, and only then appends the pointer to the queue.

## Class Shape

- Base family: `List` primary base plus RTTI-supported `Singleton<BlackHole>` relationship.
- Global state: owns [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md).
- Queue policy: deduplicates owned polymorphic object pointers, then source-deletes queued objects; `LObject*` is the current high-probability entry type.
- Pane specialization: `QueuePaneForDeferredDeletion` performs layer/event/timer detach before queueing pane objects.
- Source placement: [UID:0000HR][BlackHole](by-file/BlackHole.md).

The formal H channel above is the owning declaration. The equivalent public shape is:

```cpp
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
```

The guarded header includes the existing `List` and `Singleton` declarations, so neither `Singleton<T>` nor `LObject` requires a placeholder fallback. Do not replace the source model with decompiler-style `void*` ownership or explicit scalar-deleting-destructor calls.

## Evidence Notes

- IDA `list_globals BlackHole` reports MSVC RTTI and vtable symbols for `BlackHole` and `Singleton<BlackHole>`.
- IDA `lookup_funcs` confirms exact functions at `0x004690b0`, `0x00469100`, `0x00469120`, `0x00469180`, `0x00469200`, and `0x00469240`.
- IDA `.rdata` inspection confirms the primary vtable at `0x00613118` has ten slots: `BlackHole::ScalarDeletingDestructor` followed by the inherited `List` virtual surface.
- `Application::Initialize` calls the constructor at `0x00464549`.
- `Application::CleanupResources` and `ApplicationHelper_4A6C40::ProcessIdleWork` drain the queue through `0x00469200`.
- `0x00469180` reads [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) and calls the timer-manager remove-all-pending-events helper for the pane timer-handler subobject.
- 2026-06-15 C001 Wave2 method-analysis refresh reports a 20-byte `BlackHole` class with an embedded/inherited `List` surface and confirms all six class methods: constructor `0x004690b0`, destructor `0x00469100`, generic enqueue `0x00469120`, pane queue helper `0x00469180`, queued-object release `0x00469200`, and scalar deleting destructor `0x00469240`.
- 2026-06-15 live IDA MCP recheck reconfirmed `0x00469120-0x00469171` as the generic deduplicating enqueue method with caller `sub_539FE0+0xdc`, no direct static callees because it uses inherited `List` vtable slots, and `0xcc` padding before the pane-specific queue helper.
- 2026-06-17 B002 source-quality reanalysis confirms `BlackHole` as a `List` primary-base deferred cleanup singleton with RTTI evidence for `Singleton<BlackHole>`, [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) as backing storage, and `LObject*` / owned-polymorphic pointer entries as the best current source type.
- Complete identity inventory includes the BlackHole vtable plus 12 named RTTI/string entities and 13 BlackHole/global entity-query results. Only the pane queue method was source-named in the pre-handoff IDB; stripped names do not weaken class ownership.
- The CPP channel intentionally contains only the self header, `Pane.h`, `TimerMgr.h`, and top-level `[[CHILDREN]]`. This prevents out-of-class child definitions from being inserted inside class braces.

## Method Summary

| Address | Working name | Role |
| --- | --- | --- |
| [UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md) | `BlackHole::BlackHole` | Build `List(4, 1024)`, install vtable, store singleton pointer. |
| [UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md) | `BlackHole::~BlackHole` | Clear singleton pointer and destroy the embedded list. |
| [UID:0002M3][0x00469120-0x00469171.BlackHoleEnqueueIfMissing](by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md) | `EnqueueIfMissing` | Deduplicate and append an owned polymorphic object pointer. |
| [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) | `QueuePaneForDeferredDeletion` | Pane-specific detach/unregister/cancel-timer path before queueing. |
| [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md) | `ReleaseQueuedOwnedObjects` | Source-delete every queued owned object and clear the inherited list. |
| [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md) | `ScalarDeletingDestructor` | Compiler-generated MSVC deleting destructor wrapper for `virtual ~BlackHole()`. |

## Remaining Caveats

- Older recovery notes that said the non-deleting destructor wrapper was omitted are stale; live IDA has a real `0x00469100-0x00469115` body.
- Older owner-context notes routed `0x00469180` through `PaneChildRegistry`, but live IDA shows this is a `BlackHole` pane-deletion queue helper.
- The shared body at `0x004f30e0` is a [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md), not a unique BlackHole destructor candidate.
- Live IDA confirms [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md) at `0x00613118`.
- Cleanup writes clear [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md), the singleton pointer, not an unrelated global manager pointer.
- `BlackHole` should be modeled as a `List` subclass, not a class containing a separate `List` member. The constructor calls the `List` constructor with `ecx=this`, method bodies use inherited count/data fields, and vtable slots after the deleting destructor match the inherited `List` virtual surface.
- Queue entries are not arbitrary POD pointers. The drain method calls virtual delete semantics on each stored pointer; `LObject*` is the best current source-level type, with `void*` retained only as a conservative final-header fallback.

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

- 2026-08-16 B009 UID0000MD accepted ordinary implementation:
  - What changed: raised `90/93` to `96/97`, moved the class declaration from CPP into one guarded C++03 H channel, added exact dependencies/global extern/size assertion, and reduced CPP to includes plus top-level child insertion.
  - Source effect: all six child dispositions remain intact; source bodies assemble at namespace scope, while scalar destructor/vtable/RTTI remain compiler-generated from declarations.

- 2026-07-01 B011 implementation callback for [UID:0000HR][BlackHole](by-file/BlackHole.md):
  - What changed: raised completion from `88` to `90` and inserted the accepted formal class shell into the multiline `RECONSTRUCTION_CPP CODE` block with `List` primary base, `Singleton<BlackHole>` relationship, three source-facing queue methods, virtual destructor, and `[[CHILDREN]]` placement.
  - Summary/evidence: accepted B011 report preserves the `List` primary-base model, `Singleton<BlackHole>` RTTI caveat, `LObject *` queue-entry type, and source-level destructor policy while allowing child method/global output to assemble under `BlackHole.cpp`.

- 2026-06-15 C001 Wave2/live-IDA owner-gate refresh:
  - What existed before: the class was already strongly routed through [UID:0000HR][BlackHole](by-file/BlackHole.md) but remained scored `84/92`, which blocked strict child routes through [UID:00000W].
  - What changed: raised completion to `85`, kept confidence `92`, and added Wave2/live-IDA evidence tying the six-method class inventory and generic enqueue helper to the existing BlackHole source route.
  - Summary/evidence: Wave2 reports `BlackHole` size `20` with the `List` component and method set; live IDA reconfirms `0x00469120-0x00469171`, caller `0x0053a0bc`, inherited virtual-list dispatch, and successor padding. Final C++ remains blank under the source-quality gate.

- 2026-06-17 B002 Rule 26 source-quality sync:
  - What changed: raised completion/confidence from `85/92` to `88/93`, added the `List` primary-base plus `Singleton<BlackHole>` declaration direction, documented `LObject*` / owned-polymorphic queue entries, and clarified the scalar deleting destructor as compiler-generated from `virtual ~BlackHole()`.
  - Summary/evidence: B002 reviewed the exact child functions, vtable, RTTI, global storage, and queue producer/drain behavior. Remaining class-level uncertainty is header spelling, not ownership or behavior.

- 2026-06-05 live IDA refresh:
  - What existed before: the page carried stale recovered-source and owner-metadata caveats, a blank parent, and direct raw global/function labels in the caveats.
  - What changed: raised completion to `84`, attached the class to [UID:0000HR][BlackHole](by-file/BlackHole.md), and rewrote caveats around live IDA evidence.
  - Summary/evidence: live IDA reconfirmed the six function ranges, vtable and singleton pointer references, queue-drain callers, and pane-deletion queue behavior; at that time, formal C++ had not yet been emitted under the `95/95` gate.

- What existed before: the page had strong method, vtable, and caveat evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `82/92`, and class-shape notes were added for singleton state, queue policy, pane-specialized cleanup, and source placement.
- Summary and evidence: IDA confirms function boundaries, RTTI/vtable symbols, singleton construction/cleanup callers, and queue-drain usage; completion remains below full until final class layout and rewritten source are complete.
- What existed before: the class page summarized methods by raw addresses and did not mark the class as reconstructable in validator metadata.
- What it was changed to: method rows now link to exact child `by-memory` pages and `RECONSTRUCTABLE` is set to `TRUE`.
- Summary and evidence: 2026-05-31 IDA MCP reconfirmed the six child function ranges and vtable stores; no C++ autogen parent/code was added because the final-source threshold is not met.
