*** UID:00005G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FrameHandler

## Status

- Confidence: strong for behavior, medium for final class name.
- Likely source file: [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- Address range: [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- Scheduler singleton: [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) at `0x0069ae10`
- Current recovered file: `source-3/simroot_v2/class_FrameHandler.cpp`

## Class Purpose

`FrameHandler` is the small base object used by frame-driven classes. Its destructor unregisters the handler from [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md), preventing stale scheduled callbacks after the owner is destroyed.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~FrameHandler` | `0x004b6cb0-0x004b6cf3` | Resets vtable and unregisters from `g_frameRegistry`. |
| `ScheduleNextFrame` candidate | `0x004b6d00-0x004b6d13` | Inserts this handler into `g_frameRegistry` for `currentFrame + 1`. Generated WorldMap names this `RegisterFrameCallback`, but caller evidence is broad. |
| `RemoveFrame` wrapper candidate | `0x004b6d20-0x004b6d2c` | Removes this handler from `g_frameRegistry`. Generated WorldMap names this `StopAnimation`, but it is a generic wrapper. |
| `ScalarDeletingDestructor` | `0x004b6d50-0x004b6db2` | Unregisters and optionally deletes the handler. |

## Evidence Notes

- IDA labels the destructor address as a Boost exception symbol, but the body calls `g_frameRegistry->RemoveFrame(this)`.
- `ScreenPane` and `WorldMapPane` both embed/use frame-handler state.
- `0x004b6d00` has callers from living-object/effect/world-map paths; `0x004b6d20` has frame-handler, world-map, and other frame-driven callers. The wrapper behavior is generic even though some generated files attach feature-specific names.

## Cross-References

- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- [UID:00005H][FrameMgr](by-class/FrameMgr.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/78`. Summary: base handler role, unregister behavior, schedule/remove wrappers, destructor methods, and generated-name caveats are documented, but the final class name and all owner embeddings are still medium-confidence. Evidence: scheduler range `0x004b6cb0-0x004b7112`, `g_frameRegistry`, caller notes for `0x004b6d00`/`0x004b6d20`, and FrameMgr/ScreenPane cross-references.
