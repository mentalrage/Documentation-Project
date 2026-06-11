*** UID:0000HR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BlackHole

## Status

- Confidence: strong for class name and behavior; medium-high for final folder placement.
- Proposed source path: `NexusTK/ui/core/BlackHole.cpp`
- Primary class doc: [UID:00000W][BlackHole](by-class/BlackHole.md)
- Singleton/global doc: [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
- Vtable: [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)

## File Role

`BlackHole` is the process-wide deferred deletion queue. It derives from [UID:0000KS][List](by-file/List.md), stores pointer-sized entries, deduplicates queued objects, and scalar-deletes queued entries during idle processing or final application cleanup.

The name is not just a guessed label. IDA exposes MSVC RTTI for `BlackHole`, `Singleton<BlackHole>`, and the [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md) at `0x00613118`.

Older recovery notes said the deleting destructor clears a global manager pointer. Live IDA shows the cleanup clears [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md), the singleton pointer.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `BlackHole` | `0x004690b0-0x00469288` plus shared list destructor call | Singleton queue object built on `List`. |
| `g_pApplicationCleanupQueue` | [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md) / [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) | Zero-initialized four-byte global pointer to the singleton queue; existing IDA-backed docs record 72 refs, constructor/destructor writes, and application/idle drain reads. |
| [UID:0001TT][BlackHoleLayout](by-type/by-struct/BlackHoleLayout.md) | size `0x14` / decimal `20` bytes (Verified with `int_convert.py`) | `List` layout with 4-byte entries and `0x400` / decimal `1024` initial capacity (Verified with `int_convert.py`). |
| [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md) | `0x00613118` | Primary vtable: `BlackHole` scalar deleting destructor plus inherited `List` virtual surface. |

## Method Roles

| Function | Range | Notes |
| --- | --- | --- |
| `BlackHole::BlackHole` | [UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md) | Calls `List::List(4, 0x400 / decimal 1024)` (Verified with `int_convert.py`), installs the `BlackHole` vtable, and stores the singleton pointer. |
| `BlackHole::~BlackHole` non-deleting body | [UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md) | Clears the singleton pointer, then calls the shared [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md). |
| `BlackHole::EnqueueIfMissing` | [UID:0002M3][0x00469120-0x00469171.BlackHoleEnqueueIfMissing](by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md) | Queues a raw object pointer only if not already present. |
| `BlackHole::QueuePaneForDeferredDeletion` | [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) | Detaches a pane from its layer, unregisters its event and timer handlers, then deduplicates and queues it. Older owner-context notes exposed this as the stale disabled [UID:0000MD][PaneChildRegistry](by-file/PaneChildRegistry.md) helper. |
| `BlackHole::ReleaseQueuedOwnedObjects` | [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md) | Calls the scalar deleting destructor on every queued pointer, then clears the list. |
| `BlackHole::ScalarDeletingDestructor` | [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md) | Clears the singleton pointer, calls the non-deleting destructor body, and optionally frees the object. |

## Ownership Decision

Use `ui/core/BlackHole.cpp` as the working module. The class is constructed and destroyed by [UID:0000HG][Application](by-file/Application.md), but most specialized queue entries are panes or pane-adjacent timer owners. Keeping it beside [UID:0000MC][Pane](by-file/Pane.md), [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and [UID:0000OT][TimerMgr](by-file/TimerMgr.md) is more useful than hiding it inside `Application.cpp`.

Do not migrate `0x00469180` as a child-registration helper. Its IDA body calls pane vtable slots `+0x38` and `+0x40`, which resolve to `Pane::RemoveFromLayer` and `Pane::UnregisterEventHandler`, and then calls `TimerMgr` removal through `g_pTimerMgr` before queuing the pane for later deletion. Older owner-context notes routed the method through `PaneChildRegistry`, but live behavior supports the BlackHole module.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 85 | The page now ties the class, exact method aggregate, split child methods, concrete vtable/layout pages, projected `NexusTK/ui/core/` placement, and exact singleton storage child together as one source module. Remaining work is final polished C++ and the last source-level names for inherited `List` helpers and pane timer-handler members. |
| Confidence | 90 | IDA-backed supporting pages prove the BlackHole RTTI/vtable, constructor/destructor family, queue-drain callers, pane detach/timer cleanup behavior, and `g_pApplicationCleanupQueue` storage/lifetime. Confidence stays below final-audit levels because the public singleton spelling/accessor style and final source declarations are still open. |

## Cross-References

- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)
- [UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md)
- [UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md)
- [UID:0002M3][0x00469120-0x00469171.BlackHoleEnqueueIfMissing](by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md)
- [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md)
- [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md)
- [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md)
- [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
- [UID:0001TT][BlackHoleLayout](by-type/by-struct/BlackHoleLayout.md)
- [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000KS][List](by-file/List.md)

## Changes

- 2026-06-05 live IDA refresh:
  - What existed before: the file page had correct module ownership but still included stale recovered-source and metadata caveats plus raw singleton labels.
  - What changed: raised completion/confidence to `84/90`, removed stale recovery-output wording, and documented the singleton clear, vtable, queue, and pane cleanup evidence in source-facing terms.
  - Summary/evidence: live IDA confirms the BlackHole RTTI/vtable, six method ranges, singleton pointer xrefs, queue-drain callers, pane-specific timer/event/layer cleanup, and exact scalar-destructor endpoint.

- 2026-06-10 A001 gate repair:
  - What existed before: the page was still scored `84/90`, leaving child pages that named BlackHole as their direct file parent below the strict `85/85` assignment gate even though the evidence was already present.
  - What changed: completion is now `85`, the singleton global row links the exact storage child and global page, and a score rationale records the remaining gaps.
  - Summary/evidence: [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md), [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md), [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md), and [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md) already record the exact storage, lifetime, xref count, queue behavior, and drain callers needed for the file-parent gate.

- What existed before: the page had strong class, vtable, queue, and ownership evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `82/88`.
- Summary and evidence: IDA RTTI/vtable/function evidence makes the source module highly actionable; exact final folder placement remains the main open question.
- Before: the `BlackHole` file summary and scalar deleting destructor row used `0x00469287` as the end address.
- Changed to: both now use `0x00469288`.
- Summary/evidence: IDA MCP byte/function audit on 2026-05-27 reports the scalar deleting destructor as `0x00469240-0x00469288`; `0x00469287` is the final immediate byte of `retn 4`, and `0x00469288-0x00469290` is alignment padding.
- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the proposed tree placed `BlackHole.cpp` under UI core, and method rows used raw ranges.
- Changed to: `PROPOSED_RECONSTRUCTION_PATH` is now `NexusTK/ui/core/`, and method rows link to exact split `by-memory` children.
- Summary/evidence: `by-project-structure/proposed-source-tree.md` lists `BlackHole.cpp` under `NexusTK/ui/core/`; 2026-05-31 IDA MCP reconfirmed all child function ranges and padding splits.
