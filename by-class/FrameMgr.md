*** UID:00005H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FrameMgr

## Status

- Confidence: strong.
- Likely source file: [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- Address range: [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- Singleton/global: [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) at `0x0069ae10`
- Current recovered file: `source-3/simroot_v2/class_FrameMgr.cpp`

## Class Purpose

`FrameMgr` owns the global frame-callback queue exposed through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md). It keeps a circular linked list of scheduled `FrameHandler` entries, inserts callbacks sorted by due frame, removes all entries for a handler, dispatches due callbacks, and clears the singleton on destruction.

The circular-list storage uses shared [UID:0000KR][LinkedList](by-file/LinkedList.md) helpers. Keep generic node allocation and list cleanup in `util/LinkedList.cpp`; keep frame scheduling policy here.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `FrameMgr::FrameMgr` | `0x004b6dc0-0x004b6e63` | Initializes `LObject`, installs `g_frameRegistry`, creates the empty linked list, initializes frame counters. |
| `Insert` | `0x004b6ea0-0x004b6f0e` | Inserts a frame handler into due-frame order. |
| `RemoveFrame` | `0x004b6f10-0x004b6f56` | Removes every queued entry owned by a handler. |
| `DispatchDueFrameCallbacks` | `0x004b6f60-0x004b703d` | Advances queue to a target frame and dispatches due handlers. |
| `ScalarDeletingDestructor` | `0x004b70c0-0x004b7112` | Destroys the linked list, clears singleton, destroys base object, optional delete. |

## Cross-References

- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:00005G][FrameHandler](by-class/FrameHandler.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/86`. Summary: global frame queue ownership, circular-list policy, singleton, key methods, and LinkedList boundary are documented with strong confidence; remaining work is deeper structure field naming and final source reconstruction. Evidence: scheduler range `0x004b6cb0-0x004b7112`, `g_frameRegistry`, method table, and LinkedList/FrameHandler references.
