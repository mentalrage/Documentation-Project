*** UID:0000HR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# BlackHole

## Status

- Confidence: very strong for class name, behavior, complete source family, source placement, and accepted public header.
- Proposed source path: `NexusTK/ui/core/BlackHole.cpp`
- Primary class doc: [UID:00000W][BlackHole](by-class/BlackHole.md)
- Singleton/global doc: [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
- Vtable: [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)

## File Role

`BlackHole` is the process-wide deferred deletion queue. It derives from [UID:0000KS][List](by-file/List.md), has RTTI evidence for a `Singleton<BlackHole>` relationship, stores owned polymorphic pointer entries, deduplicates queued objects, and source-deletes queued entries during idle processing or final application cleanup.

The name is not just a guessed label. IDA exposes MSVC RTTI for `BlackHole`, `Singleton<BlackHole>`, and the [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md) at `0x00613118`.

Older recovery notes said the deleting destructor clears a global manager pointer. Live IDA shows the cleanup clears [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md), the singleton pointer.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `BlackHole` | exact children inside `0x004690b0-0x00469288` plus shared list destructor call | Singleton cleanup queue object built on a `List` primary base. |
| `g_pApplicationCleanupQueue` | [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md) / [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) | Zero-initialized four-byte global/backing pointer to the singleton queue; existing IDA-backed docs record 72 refs, constructor/destructor writes, and application/idle drain reads. |
| [UID:0001TT][BlackHoleLayout](by-type/by-struct/BlackHoleLayout.md) | size `0x14` / decimal `20` bytes (Verified with `int_convert.py`) | `List` primary-base layout with 4-byte owned-polymorphic pointer entries and `0x400` / decimal `1024` initial capacity (Verified with `int_convert.py`). |
| [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md) | `0x00613118` | Primary vtable: `BlackHole` scalar deleting destructor plus inherited `List` virtual surface. |

## Method Roles

| Function | Range | Notes |
| --- | --- | --- |
| `BlackHole::BlackHole` | [UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md) | Calls `List::List(4, 0x400 / decimal 1024)` (Verified with `int_convert.py`), installs the `BlackHole` vtable, and stores the singleton pointer. |
| `BlackHole::~BlackHole` non-deleting body | [UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md) | Clears the singleton pointer, then calls the shared [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md). |
| `BlackHole::EnqueueIfMissing` | [UID:0002M3][0x00469120-0x00469171.BlackHoleEnqueueIfMissing](by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md) | Queues an owned polymorphic object pointer only if not already present. |
| `BlackHole::QueuePaneForDeferredDeletion` | [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) | Detaches a pane from its layer, unregisters its event and timer handlers, then deduplicates and queues it. Older owner-context notes exposed this as the stale disabled [UID:0000MD][PaneChildRegistry](by-file/PaneChildRegistry.md) helper. |
| `BlackHole::ReleaseQueuedOwnedObjects` | [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md) | Source-deletes every queued owned object, then clears the inherited list. |
| `BlackHole::ScalarDeletingDestructor` | [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md) | Compiler-generated deleting destructor wrapper for the virtual destructor declaration. |

## Ownership Decision

Use `ui/core/BlackHole.cpp` as the working module. The class is constructed and destroyed by [UID:0000HG][Application](by-file/Application.md), but most specialized queue entries are panes or pane-adjacent timer owners. Keeping it beside [UID:0000MC][Pane](by-file/Pane.md), [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and [UID:0000OT][TimerMgr](by-file/TimerMgr.md) is more useful than hiding it inside `Application.cpp`.

Do not migrate `0x00469180` as a child-registration helper. Its IDA body calls pane vtable slots `+0x38` and `+0x40`, which resolve to `Pane::RemoveFromLayer` and `Pane::UnregisterEventHandler`, and then calls `TimerMgr` removal through `g_pTimerMgr` before queuing the pane for later deletion. Older owner-context notes routed the method through `PaneChildRegistry`, but live behavior supports the BlackHole module.

Historical empty or invalid generated `auto-generated/NexusTK/ui/core/BlackHole.cpp` states reflected formal assembly defects, not a dead or unsupported source file. The accepted formal route is a guarded `BlackHole.h`, a CPP preamble that places `[[CHILDREN]]` at top level, one global definition, five source method bodies, and a compiler-role-only scalar-deleting-destructor child. Generated files remain validator-owned readback artifacts.

## Source And Dependency Closure

- The source family is bounded by `[0x004690b0,0x00469290)`: six exact function objects, six exact `0xcc` pads, and successor `sub_469290` outside the family.
- [UID:00000W][BlackHole](by-class/BlackHole.md) owns the complete C++03 header. It includes guarded `List.h` and `Singleton.h`, forward-declares `Pane`, declares all source methods and `extern BlackHole *g_pApplicationCleanupQueue`, and enforces `sizeof(BlackHole) == 0x14`.
- The CPP includes `BlackHole.h`, `Pane.h`, and `TimerMgr.h` before top-level child output. The pane helper uses `static_cast<TimerHandler *>(pane)`, matching public Pane inheritance and the observed `Pane+0xa4` adjusted-base argument without inventing a member.
- The global parent emits the sole `g_pApplicationCleanupQueue` definition; the exact memory child documents the zero-initialized storage without duplicating it.
- Sixteen non-BlackHole generated TUs consume the class/global. Their owning formal routes provide `BlackHole.h` at the earliest source position: Application, FittingRoom, MainMenuPane, MapPane, Motion, SayInputPanes, UserListDialogPane, EventDispatcher, FrameChrome, InputPanes, RankingDialog, TargetOptionDialog, TargetSelectionInputPanes, WebBoardDialog, ParcelPane, and UserPane.
- `FrameChrome.cpp` alone carried the stale spelling `g_pBlackHole`; its accepted source expression is `g_pApplicationCleanupQueue`. No consumer gains source ownership from including the service header.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 95 | The page closes the exact function/padding inventory, vtable/layout/global/RTTI family, caller topology, `NexusTK/ui/core/` placement, guarded header, top-level CPP assembly, corrected timer cast, and all consumer dependencies. |
| Confidence | 97 | Live IDA-backed pages prove identity, behavior, ranges, callers, storage, and inherited layout; generated validation remains a readback step rather than a source-quality blocker. |

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

- 2026-08-16 B009 UID0000MD accepted ordinary implementation:
  - What changed: raised `89/93` to `95/97`, finalized the guarded CPP/H assembly and dependency graph, bounded all six functions and six pads, and historicalized prior generated-output expectations.
  - Ownership: `NexusTK/ui/core/BlackHole.cpp` remains the single canonical source file. PaneChildRegistry is only a non-emitting compatibility warning.

- 2026-07-01 B011 implementation callback for [UID:0000HR]:
  - What changed: raised completion/confidence from `87/92` to `89/93`, updated generated-output status from "currently empty" to an expected refreshed source file, and aligned the module summary with formal child C++/comment insertion.
  - Summary/evidence: accepted B011 report `tools/leaser/Agents/Agent-B011/research/0000HR-BlackHole-empty-emitter-family-source-quality.md` incorporated formal bodies/comments into the class, global, method, layout, vtable, and storage pages; scoped validators were run with `--wait-generated`.

- 2026-06-05 live IDA refresh:
  - What existed before: the file page had correct module ownership but still included stale recovered-source and metadata caveats plus raw singleton labels.
  - What changed: raised completion/confidence to `84/90`, removed stale recovery-output wording, and documented the singleton clear, vtable, queue, and pane cleanup evidence in source-facing terms.
  - Summary/evidence: live IDA confirms the BlackHole RTTI/vtable, six method ranges, singleton pointer xrefs, queue-drain callers, pane-specific timer/event/layer cleanup, and exact scalar-destructor endpoint.

- 2026-06-10 A001 gate repair:
  - What existed before: the page was still scored `84/90`, leaving child pages that named BlackHole as their direct file parent below the strict `85/85` assignment gate even though the evidence was already present.
  - What changed: completion is now `85`, the singleton global row links the exact storage child and global page, and a score rationale records the remaining gaps.
  - Summary/evidence: [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md), [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md), [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md), and [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md) already record the exact storage, lifetime, xref count, queue behavior, and drain callers needed for the file-parent gate.

- 2026-06-17 B002 Rule 26 source-quality sync:
  - What changed: raised completion/confidence from `85/90` to `87/92`, clarified that `BlackHole.cpp` is a real source file even if generated output was empty, and added the `List` primary-base, `Singleton<BlackHole>`, `LObject*` queue-entry, and generated scalar-deleting-destructor conclusions.
  - Summary/evidence: B002 reviewed exact method children, RTTI/vtable data, [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md), [UID:0001TT][BlackHoleLayout](by-type/by-struct/BlackHoleLayout.md), and [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md).

- What existed before: the page had strong class, vtable, queue, and ownership evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `82/88`.
- Summary and evidence: IDA RTTI/vtable/function evidence makes the source module highly actionable; exact final folder placement remains the main open question.
- Before: the `BlackHole` file summary and scalar deleting destructor row used `0x00469287` as the end address.
- Changed to: both now use `0x00469288`.
- Summary/evidence: IDA MCP byte/function audit on 2026-05-27 reports the scalar deleting destructor as `0x00469240-0x00469288`; `0x00469287` is the final immediate byte of `retn 4`, and `0x00469288-0x00469290` is alignment padding.
- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the proposed tree placed `BlackHole.cpp` under UI core, and method rows used raw ranges.
- Changed to: `PROPOSED_RECONSTRUCTION_PATH` is now `NexusTK/ui/core/`, and method rows link to exact split `by-memory` children.
- Summary/evidence: `by-project-structure/proposed-source-tree.md` lists `BlackHole.cpp` under `NexusTK/ui/core/`; 2026-05-31 IDA MCP reconfirmed all child function ranges and padding splits.
