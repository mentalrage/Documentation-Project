*** UID:00005H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FrameMgr

## Status

- Confidence: strong for scheduler class identity, singleton ownership, method boundaries, vtable refs, and direct file parent; medium-high for final member names and callback-record layout names.
- Source file parent: [UID:0000JM][FrameMgr](by-file/FrameMgr.md), now assigned after both class and file clear the corrected `85/85` gate.
- Address range: [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- Singleton/global: [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) at `0x0069ae10`
- Vtable data: [UID:0002V3][0x0061a7e0-0x0061a7f8.FrameHandlerFrameMgrVtableData](by-memory/0x0061a7e0-0x0061a7f8.FrameHandlerFrameMgrVtableData.md)

## Class Purpose

`FrameMgr` owns the global frame-callback queue exposed through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md). It keeps a circular linked list of scheduled `FrameHandler` entries, inserts callbacks sorted by due frame, removes all entries for a handler, dispatches due callbacks, and clears the singleton on destruction.

The circular-list storage uses shared [UID:0000KR][LinkedList](by-file/LinkedList.md) helpers. Keep generic node allocation and list cleanup in `util/LinkedList.cpp`; keep frame scheduling policy here.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `FrameMgr::FrameMgr` | `0x004b6dc0-0x004b6e63` | Initializes `LObject`, installs `g_frameRegistry`, creates the empty linked list, initializes frame counters, and stores the `FrameMgr` vtable. |
| `Insert` | `0x004b6ea0-0x004b6f0e` | Inserts a `FrameHandler` into due-frame order using shared `LinkedList` node allocation. |
| `RemoveFrame` | `0x004b6f10-0x004b6f56` | Removes every queued entry owned by a handler. |
| `DispatchDueFrameCallbacks` | `0x004b6f60-0x004b703d` | Called from application idle work; advances queue state and dispatches due handler callbacks. |
| `ScalarDeletingDestructor` | `0x004b70c0-0x004b7112` | Destroys the linked list, clears `g_frameRegistry`, restores base state, and optionally deletes. |

## Cross-References

- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:0002V3][0x0061a7e0-0x0061a7f8.FrameHandlerFrameMgrVtableData](by-memory/0x0061a7e0-0x0061a7f8.FrameHandlerFrameMgrVtableData.md)
- [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:00005G][FrameHandler](by-class/FrameHandler.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)

## Evidence And Assignment Gate

- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md) records the current scheduler aggregate as `85/90` and assigned to [UID:0000JM][FrameMgr](by-file/FrameMgr.md), with live IDA confirmation of all `FrameHandler` and `FrameMgr` function endpoints.
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md) is the direct source root at `85/86`, covering both `FrameHandler` wrappers and `FrameMgr` queue policy under `NexusTK/ui/core/FrameMgr.cpp`.
- IDA-backed evidence ties this class to `g_frameRegistry` construction/clear xrefs, application idle dispatch, broad wrapper callers, `LinkedList` helper use, and the `FrameMgr` vtable base at `0x0061a7ec`.
- Assignment decision: `AUTOGEN_PARENT_UID:0000JM` is justified because this class is the manager half of the scheduler source module and both child and direct parent meet the corrected `85/85` gate.
- Final C++ remains blank because exact member names, callback record field names, and all embedding-owner layouts are still below final-source quality.

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the scheduler methods at `0x004b6dc0`, `0x004b6ea0`, `0x004b6f10`, `0x004b6f60`, and `0x004b70c0`. Left `AUTOGEN_PARENT_UID` blank because this class is still below the 80 completion gate even though the likely file parent [UID:0000JM][FrameMgr](by-file/FrameMgr.md) is plausible.
- Completion/confidence score update: existed before as `0/0`; changed to `78/86`. Summary: global frame queue ownership, circular-list policy, singleton, key methods, and LinkedList boundary are documented with strong confidence; remaining work is deeper structure field naming and final source reconstruction. Evidence: scheduler range `0x004b6cb0-0x004b7112`, `g_frameRegistry`, method table, and LinkedList/FrameHandler references.
- 2026-06-07 Batch 089 class-gate refresh:
  - Before: `COMPLETION:78`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000JM`.
  - Summary/evidence: linked the reviewed scheduler aggregate, vtable-data page, singleton/global refs, application idle dispatch evidence, and direct file parent [UID:0000JM][FrameMgr](by-file/FrameMgr.md), which already clears `85/86`. C++ remains blank under the final-source gate.
