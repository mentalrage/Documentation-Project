*** UID:0000Q8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pApplicationCleanupQueue

## Status

- Symbol kind: singleton pointer/global data.
- Address: `0x0067a74c` in IDA as `dword_67A74C`.
- Current generated names: `g_pApplicationCleanupQueue`, `dword_67A74C`.
- Likely owner: [UID:0000HR][BlackHole](by-file/BlackHole.md).
- Owning vtable: [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md).
- Confidence: strong for role, medium for final source-level global spelling.

## Role

`g_pApplicationCleanupQueue` points to the process-wide [UID:00000W][BlackHole](by-class/BlackHole.md) deferred deletion queue. The queue is constructed during application initialization, drained during idle work, and drained/destroyed during final cleanup.

The name may be a generated descriptive name rather than the original source spelling. IDA RTTI proves the owning class name is `BlackHole` and also exposes `Singleton<BlackHole>`, so the final source could use a singleton accessor instead of a public `g_pApplicationCleanupQueue` variable.

## Evidence

- `BlackHole::BlackHole` at `0x004690b0` writes `dword_67A74C = this`.
- `BlackHole` destructors at `0x00469100` and `0x00469240` write `dword_67A74C = 0`.
- `Application::CleanupResources` at `0x00464a60` tests `dword_67A74C`, drains it through `0x00469200`, and then calls its scalar deleting destructor.
- `ApplicationHelper_4A6C40::ProcessIdleWork` at `0x004a6c40` calls `BlackHole::ReleaseQueuedOwnedObjects(dword_67A74C)` before timer dispatch.
- IDA xrefs to `0x0067a74c` are broad across pane/dialog close paths and map/object cleanup paths.

## Cross-References

- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)
- [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)
- [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:00000E][ApplicationHelper_4A6C40](by-class/ApplicationHelper_4A6C40.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents address, generated names, BlackHole singleton role, constructor/destructor writes, application cleanup/idle users, RTTI-backed owner, and refs; final source spelling/accessor style remains open.
