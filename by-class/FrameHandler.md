*** UID:00005G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FrameHandler

## Status

- Confidence: strong for behavior and class name because IDA has decorated `FrameHandler` RTTI/vtable data and multiple constructor/destructor vtable stores.
- Likely source file: [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- Address range: [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- Scheduler singleton: [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) at `0x0069ae10`
- Vtable data: [UID:0002V3][0x0061a7e0-0x0061a7f8.FrameHandlerFrameMgrVtableData](by-memory/0x0061a7e0-0x0061a7f8.FrameHandlerFrameMgrVtableData.md)
- Evidence basis: live IDA MCP `py_eval` on 2026-06-04 against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`).

## Class Purpose

`FrameHandler` is the small base object used by frame-driven classes. Its destructor unregisters the handler from [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md), preventing stale scheduled callbacks after the owner is destroyed.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~FrameHandler` | `0x004b6cb0-0x004b6cf3` | Resets vtable and unregisters from `g_frameRegistry`. |
| `ScheduleNextFrame` | `0x004b6d00-0x004b6d14` | Inserts this handler into `g_frameRegistry` for `currentFrame + 1`; callers span living-object, screen, look, world-map, and weather-style frame users. |
| `RemoveFrame` wrapper | `0x004b6d20-0x004b6d2d` | Removes this handler from `g_frameRegistry`; callers span the same broad frame-driven owner set. |
| `ScalarDeletingDestructor` | `0x004b6d50-0x004b6db3` | Restores `FrameHandler` vtable, unregisters, and optionally frees the handler. |

## Evidence Notes

- IDA labels the destructor address as a Boost exception symbol, but the body calls `g_frameRegistry->RemoveFrame(this)`.
- `ScreenPane` and `WorldMapPane` both embed/use frame-handler state.
- `0x004b6d00` has callers from living-object, screen, look, world-map, and weather-style paths; `0x004b6d20` has frame-handler, world-map, and other frame-driven callers. The wrapper behavior is generic rather than feature-owned.
- 2026-06-04 live IDA confirms `FrameHandler` RTTI at `0x0061a7dc` and vtable base at `0x0061a7e0`, with slots `0x004b6d50` and `__purecall`.
- Vtable stores to `0x0061a7e0` occur in the handler destructor (`0x004b6cd2`), scalar deleting destructor (`0x004b6d75`), `ScreenPane` construction (`0x00556949`), `GroupListPane` construction (`0x0056bb86`/`0x0056bc1a`), and `WorldMapPane` construction (`0x005c2b05`).
- Live decompilation confirms `0x004b6d00` calls `FrameMgr::Insert(g_frameRegistry, this, g_frameRegistry->currentDispatchFrame + 1)`, `0x004b6d20` calls `FrameMgr::RemoveFrame(g_frameRegistry, this)`, and both destructors unregister before returning or freeing.

## Cross-References

- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- [UID:00005H][FrameMgr](by-class/FrameMgr.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
- [UID:0002V3][0x0061a7e0-0x0061a7f8.FrameHandlerFrameMgrVtableData](by-memory/0x0061a7e0-0x0061a7f8.FrameHandlerFrameMgrVtableData.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/78`. Summary: base handler role, unregister behavior, schedule/remove wrappers, destructor methods, and generated-name caveats are documented, but the final class name and all owner embeddings are still medium-confidence. Evidence: scheduler range `0x004b6cb0-0x004b7112`, `g_frameRegistry`, caller notes for `0x004b6d00`/`0x004b6d20`, and FrameMgr/ScreenPane cross-references.
- 2026-06-04: Raised from `72/78` to `84/90`.
  - What existed before: the page described the frame-handler behavior but treated the class name as medium-confidence and used stale generated-name caveats.
  - Changed to: documented the current IDA binary identity, decorated `FrameHandler` RTTI/vtable data, exact method endpoints, broad wrapper caller sets, vtable store sites in owner constructors/destructors, and live decompilation of schedule/remove/destructor behavior.
  - Reason for score increase: class identity is now backed by live decorated RTTI/vtable evidence and generic caller behavior rather than caller-biased names; completion remains below final reconstruction because field names and all embedding-owner layouts are not yet source-quality.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JM][FrameMgr](by-file/FrameMgr.md) because the class is `84/90` and the parent is `82/84`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x004b6cb0`, `0x004b6d00`, `0x004b6d20`, and `0x004b6d50`; current `callers` confirms broad frame-driven constructor/destructor and scheduling use.
