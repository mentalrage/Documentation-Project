*** UID:0000Q8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pApplicationCleanupQueue

## Status

- Symbol kind: singleton pointer/global data.
- Address: `0x0067a74c` in IDA as `dword_67A74C`.
- Observed names: `g_pApplicationCleanupQueue`, `dword_67A74C`.
- Exact storage child: [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md).
- Likely owner: [UID:0000HR][BlackHole](by-file/BlackHole.md).
- Owning vtable: [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md).
- Confidence: strong for role and owner, medium-high for final source-level global spelling/accessor style.

## Role

`g_pApplicationCleanupQueue` points to the process-wide [UID:00000W][BlackHole](by-class/BlackHole.md) deferred deletion queue. The queue is constructed during application initialization, drained during idle work, and drained/destroyed during final cleanup.

The name may be a working descriptive name rather than the original source spelling. IDA RTTI proves the owning class name is `BlackHole` and also exposes `Singleton<BlackHole>`, so the final source could use a singleton accessor instead of a public `g_pApplicationCleanupQueue` variable.

## Evidence

- The exact storage child [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md) records a zero-initialized four-byte `.data` slot, `72` IDA xrefs, and four writer sites confined to the BlackHole constructor/destructor family.
- `BlackHole::BlackHole` at `0x004690b0` writes `dword_67A74C = this`.
- `BlackHole` destructors at `0x00469100` and `0x00469240` write `dword_67A74C = 0`.
- `Application::CleanupResources` at `0x00464a60` tests `dword_67A74C`, drains it through `0x00469200`, and then calls its scalar deleting destructor.
- `ApplicationHelper_4A6C40::ProcessIdleWork` at `0x004a6c40` calls `BlackHole::ReleaseQueuedOwnedObjects(dword_67A74C)` before timer dispatch.
- `BlackHole::BlackHole` builds the underlying list with pointer-sized entries and `0x400` / decimal `1024` initial capacity (Verified with `int_convert.py`), matching the deferred-object queue model.
- The [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) helper detaches panes from layer/event/timer systems before deduplicating and appending them; broad pane/dialog close paths are consumers, not owners.
- Current-session MCP status: `tools/list` responded, but a combined `xrefs_to 0x0067a74c` plus `lookup_funcs` exact-check timed out after `30` seconds, and a lighter `lookup_funcs` retry timed out after `15` seconds. No new IDA facts are claimed from those timed-out calls; this update relies on the existing written live-IDA evidence in the linked memory/class/file pages.

## Lifecycle And Consumers

| Area | Evidence | Interpretation |
| --- | --- | --- |
| Storage | [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md) records initial `0x00000000`, neighboring `g_pCollectionData` / `g_pLanguageMan` boundaries, and 72 xrefs. | Source-declared process global or singleton backing slot for `BlackHole`. |
| Construction | [UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md) stores `this` into the slot after list/vtable setup. | `Application::Initialize` creates the singleton queue before clients enqueue deferred objects. |
| Teardown | [UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md) and [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md) clear the slot. | The global is lifecycle-owned by BlackHole, not by a pane or application helper. |
| Idle/final drain | [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md), [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md), and [UID:0000HG][Application](by-file/Application.md). | Queued objects are scalar-deleted during idle work and final cleanup. |
| Pane/dialog consumers | [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) plus pane/dialog close paths. | Consumers enqueue objects through BlackHole after detaching UI/event/timer state. |

## Assignment Decision

Keep `AUTOGEN_PARENT_UID:0000HR` on [UID:0000HR][BlackHole](by-file/BlackHole.md). The child page is now `88/86`, and the direct parent file is now `85/90`, so the strict child/direct-parent `85/85` assignment gate clears. [UID:0000HG][Application](by-file/Application.md), [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), `Pane` consumers, and map/dialog teardown pages are users of the queue, but they do not own the singleton storage or the queue methods.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 88 | The page now records exact storage, owner file/class, vtable/layout context, constructor/destructor lifetime, idle/final drain users, pane-specific enqueue behavior, current MCP timeout status, and the strict direct-parent gate. Remaining work is the final source spelling/accessor choice and final C++ declaration style. |
| Confidence | 86 | Existing linked pages contain live-IDA evidence for the storage slot, xref count, writer set, method boundaries, RTTI/vtable identity, and consumer split. Confidence is not higher because current-session xref/function MCP retries timed out and the final public symbol name remains descriptive. |

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

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents address, observed names, BlackHole singleton role, constructor/destructor writes, application cleanup/idle users, RTTI-backed owner, and refs; final source spelling/accessor style remains open.
- 2026-06-05: Marked reconstructable under [UID:0000HR][BlackHole](by-file/BlackHole.md). Evidence: live IDA MCP reports broad xrefs to `0x0067a74c`; decompilation confirms `0x004690b0` writes the singleton pointer, `0x00469100` and `0x00469240` clear it, and `0x004a6c40` drains the queue during idle work.
- 2026-06-10 A001: Raised `86/80` to `88/86` and kept the BlackHole file parent after direct-parent gate repair. Evidence: exact storage child [UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md), BlackHole aggregate/method pages, and [UID:0000HR][BlackHole](by-file/BlackHole.md) now record enough written evidence for the strict `85/85` child/direct-parent gate; current-session MCP exact-check attempts timed out after `30` and `15` seconds, so no new live IDA facts were added from those calls.
