*** UID:0000Q8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
BlackHole *g_pApplicationCleanupQueue = 0;
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pApplicationCleanupQueue

## Status

- Symbol kind: singleton pointer/global data.
- Address: `0x0067a74c`; fresh 2026-08-16 report evidence reads physical name `g_pApplicationCleanupQueue`, type `BlackHole *`, and regular address comment `BlackHole deferred-deletion queue singleton pointer (source-facing g_pApplicationCleanupQueue).`.
- Observed historical/raw alias: `dword_67A74C`.
- Exact storage child: [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md).
- Likely owner: [UID:0000HR][BlackHole](by-file/BlackHole.md).
- Owning vtable: [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md).
- Confidence: strong for role and owner, medium-high for final source-level global spelling/accessor style.

## Role

`g_pApplicationCleanupQueue` points to the process-wide [UID:00000W][BlackHole](by-class/BlackHole.md) deferred deletion queue. The queue is constructed during application initialization, drained during idle work, and drained/destroyed during final cleanup.

The name remains the best documentation/emission name for the backing storage at `0x0067a74c`. IDA RTTI proves the owning class name is `BlackHole` and also exposes `Singleton<BlackHole>`, so a later header pass may describe this slot as instantiated singleton backing storage or use a singleton accessor instead of exposing a public global.

## Evidence

- The exact storage child [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md) records a zero-initialized four-byte `.data` slot, `72` IDA xrefs, and four writer sites confined to the BlackHole constructor/destructor family.
- `BlackHole::BlackHole` at `0x004690b0` writes `dword_67A74C = this`.
- `BlackHole` destructors at `0x00469100` and `0x00469240` write `dword_67A74C = 0`.
- `Application::CleanupResources` at `0x00464a60` tests `dword_67A74C`, drains it through `0x00469200`, and then calls its scalar deleting destructor.
- `ApplicationHelper_4A6C40::ProcessIdleWork` at `0x004a6c40` calls `BlackHole::ReleaseQueuedOwnedObjects(dword_67A74C)` before timer dispatch.
- `BlackHole::BlackHole` builds the underlying list with pointer-sized entries and `0x400` / decimal `1024` initial capacity (Verified with `int_convert.py`), matching the deferred-object queue model.
- The [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) helper detaches panes from layer/event/timer systems before deduplicating and appending them; broad pane/dialog close paths are consumers, not owners.
- Dated earlier MCP attempt: `tools/list` responded, but one combined exact-check timed out after `30` seconds and a lighter retry after `15` seconds. Later bounded read-only evidence, including the 2026-08-16 UID0000MD recheck, independently completed the physical item and exact xref audit.
- 2026-06-17 B002 source-quality reanalysis keeps this as BlackHole-owned cleanup-queue backing storage and confirms the `Singleton<BlackHole>` relationship is a source-shape caveat, not a reason to rename the slot to a vague `g_pBlackHole`.

## Exact Xref Inventory

The complete 72-address incoming set is:

`0x0041c585`, `0x00452151`, `0x00458a53`, `0x0045ddb1`, `0x00464c0f`, `0x00464c1e`, `0x004690d0`, `0x004690e4`, `0x00469106`, `0x0046924c`, `0x0046ad6a`, `0x0046d394`, `0x0046e286`, `0x0046e91a`, `0x0049dad1`, `0x004a0669`, `0x004a0eb8`, `0x004a0fdb`, `0x004a1548`, `0x004a6c43`, `0x004b73c0`, `0x004f1c7a`, `0x004f2059`, `0x004f206f`, `0x004f260d`, `0x004f264a`, `0x004f26da`, `0x004f2714`, `0x004f273a`, `0x004f297b`, `0x004f2d24`, `0x004f2e20`, `0x004f2e36`, `0x004f2ef0`, `0x004f2f06`, `0x004f7c77`, `0x004f8a93`, `0x004f920b`, `0x00504824`, `0x00504b80`, `0x0053a0b2`, `0x0053dd98`, `0x0053dfc4`, `0x0053e946`, `0x0053ed56`, `0x0053f146`, `0x0053f904`, `0x0053fe6a`, `0x00542091`, `0x00542512`, `0x005446a1`, `0x0054523a`, `0x00545dd1`, `0x005460b5`, `0x00546f85`, `0x0059dad5`, `0x0059e6e6`, `0x005aad10`, `0x005aae83`, `0x005ae833`, `0x005ae94f`, `0x005ae9d8`, `0x005af136`, `0x005af232`, `0x005af798`, `0x005af7e4`, `0x005afc36`, `0x005afec5`, `0x005b0087`, `0x005b04b6`, `0x005b0751`, `0x005b1cab`.

Only constructor/destructor-family addresses write the slot. All other routes consume or drain the service and do not transfer ownership.

## Lifecycle And Consumers

| Area | Evidence | Interpretation |
| --- | --- | --- |
| Storage | [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md) records initial `0x00000000`, neighboring `g_pCollectionData` / `g_pLanguageMan` boundaries, and 72 xrefs. | Source-declared process global or singleton backing slot for `BlackHole`. |
| Construction | [UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md) stores `this` into the slot after list/vtable setup. | `Application::Initialize` creates the singleton queue before clients enqueue deferred objects. |
| Teardown | [UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md) and [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md) clear the slot. | The global is lifecycle-owned by BlackHole, not by a pane or application helper. |
| Idle/final drain | [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md), [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md), and [UID:0000HG][Application](by-file/Application.md). | Queued objects are scalar-deleted during idle work and final cleanup. |
| Pane/dialog consumers | [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) plus pane/dialog close paths. | Consumers enqueue objects through BlackHole after detaching UI/event/timer state. |

## Assignment Decision

Keep `CANONICAL_OWNER:0000HR` and `EMITTER_UIDS:0000HR` on [UID:0000HR][BlackHole](by-file/BlackHole.md). This page emits the source-facing global definition once, while the exact storage child [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md) remains owner/emitter `0000Q8` and documents the backing bytes without duplicating the definition. [UID:0000HG][Application](by-file/Application.md), [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), `Pane` consumers, and map/dialog teardown pages are users of the queue, but they do not own the singleton storage or the queue methods.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 94 | The page records exact physical state, all 72 xrefs, writer set, owner file/class, vtable/layout context, constructor/destructor lifetime, drains/consumers, and the sole formal global definition. |
| Confidence | 96 | Live-IDA-backed evidence closes the storage slot, exact xrefs, writer set, RTTI/vtable identity, source spelling, and consumer/owner split. |

## Cross-References

- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)
- [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md)
- [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)
- [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md)
- [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:00000E][ApplicationHelper_4A6C40](by-class/ApplicationHelper_4A6C40.md)

## Changes

- 2026-08-16 B009 UID0000MD accepted ordinary implementation: raised `90/92` to `94/96`, historicalized the old MCP timeout, recorded the fresh physical name/type/comment, and added the complete 72-address xref inventory while preserving the one-definition BlackHole ownership route.

- 2026-07-01 B011 implementation callback for [UID:0000HR][BlackHole](by-file/BlackHole.md):
  - What changed: raised completion/confidence from `89/90` to `90/92`, inserted the formal global definition plus `[[CHILDREN]]`, and replaced stale parent-gate wording with current owner/emitter routing.
  - Summary/evidence: this global page emits `BlackHole *g_pApplicationCleanupQueue = 0;`; the exact storage child remains owner/emitter `0000Q8` and emits only a backing-storage comment so the definition is not duplicated.

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents address, observed names, BlackHole singleton role, constructor/destructor writes, application cleanup/idle users, RTTI-backed owner, and refs; final source spelling/accessor style remains open.
- 2026-06-05: Marked reconstructable under [UID:0000HR][BlackHole](by-file/BlackHole.md). Evidence: live IDA MCP reports broad xrefs to `0x0067a74c`; decompilation confirms `0x004690b0` writes the singleton pointer, `0x00469100` and `0x00469240` clear it, and `0x004a6c40` drains the queue during idle work.
- 2026-06-10 A001: Raised `86/80` to `88/86` and kept the BlackHole file parent after direct-parent gate repair. Evidence: exact storage child [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md), BlackHole aggregate/method pages, and [UID:0000HR][BlackHole](by-file/BlackHole.md) now record enough written evidence for the strict `85/85` child/direct-parent gate; current-session MCP exact-check attempts timed out after `30` and `15` seconds, so no new live IDA facts were added from those calls.
- 2026-06-17 B002 Rule 26 source-quality sync: raised `88/86` to `89/90`, kept the `g_pApplicationCleanupQueue` name, and added the `Singleton<BlackHole>` backing-storage caveat. Evidence: B002 correlated the global with BlackHole constructor/destructor writers, idle/final drain readers, RTTI, and class/layout/vtable docs.
