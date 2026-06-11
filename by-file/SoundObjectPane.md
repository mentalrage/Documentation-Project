*** UID:0000NW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SoundObjectPane

## Status

- Confidence: strong for class role and core range.
- Proposed module: `map/SoundObjectPane.cpp`
- Current generated source: `source-3/simroot_v2/class_SoundObjectPane.cpp`
- Primary class doc: [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md)
- Main address docs: [UID:0001DJ][0x0053ca20-0x0053ce3c.SoundObjectPaneCore](by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md) and [UID:0001DN][0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md)

## File Role

`SoundObjectPane.cpp` likely owns positional or map-attached sound objects. It derives through [UID:0000M5][ObjectPane](by-file/ObjectPane.md), stores sound position/target position and playback parameters, starts immediate or delayed playback, and schedules repeat/random trigger behavior through the map object/timer infrastructure.

This file is a map-object consumer of [UID:0000NV][SoundManager](by-file/SoundManager.md), not the sound system itself. The sound manager owns sample playback and audio backends; `SoundObjectPane` owns map object lifetime, linkage to an owning object, and trigger/removal rules.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SoundObjectPane` | `0x0053ca20-0x0053ce3c`, scalar destructor at `0x0053d660` | Positional sound object pane with trigger/repeat behavior. |
| non-deleting destructor | `0x0053cac0-0x0053cb48` | Clears a linked object's sound reference, unregisters from map object manager, and tears down `ObjectPane`. |
| playback starter | `0x0053cb50-0x0053cc5c` | Consumes playback mode fields and either plays immediately, destroys itself, or arms a timer token at `this+0xa4`. |
| trigger handler | `0x0053cc70-0x0053ce3c` | Handles mode `2`, counted-play mode `3`, and probability mode `4`, scheduling follow-up triggers as needed. |

## Boundary Notes

- Active generated output omits the real non-deleting destructor at `0x0053cac0-0x0053cb48`. The scalar deleting destructor duplicates the same cleanup plus optional `operator delete`.
- Constructor callers at `0x0050ec30` and `0x00512f20` build sound objects from map/object packet flows and call `StartPlayback` immediately in two paths.
- Adjustor thunk `0x0053cf72` is emitted; thunk `0x0053cf7d` is real in IDA but currently listed as missing code in disabled output.
- `0x0053ce40` and `0x0053ce50` are not part of this class. `0x0053ce50` is the [UID:0001DK][0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper](by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md), sitting between the sound trigger body and later object-pane destructor/allocator thunks.
- 2026-05-26 IDA static-pool review identifies the [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md) [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) at `0x0069b8e4`, constructed by `0x0041a140` with block size `344` and `32` blocks per chunk.

## Cross-References

- [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md)
- [UID:0001DJ][0x0053ca20-0x0053ce3c.SoundObjectPaneCore](by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md)
- [UID:0001DN][0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- [UID:0001DK][0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper](by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md)

## Changes

- 2026-06-05: Assigned projected reconstruction folder.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - After: set the folder to `NexusTK/map/`.
  - Evidence: live IDA MCP lookup confirms the documented `SoundObjectPane` constructor anchor at `0x0053ca20`; proposed-source-tree keeps positional sound objects with the map object companion files, while `SoundManager.cpp` remains the audio-backend owner.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `86`.
  - Evidence: document covers map-object role, proposed contents, destructor/playback/trigger behavior, constructor callers, boundary exclusions, pool allocator evidence, and cross-references; confidence is high because class role and core range are strongly anchored.
