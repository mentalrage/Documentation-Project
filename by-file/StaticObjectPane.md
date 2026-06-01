*** UID:0000O6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StaticObjectPane

## Status

- Confidence: strong for class role and core range.
- Proposed module: `map/StaticObjectPane.cpp`
- Current generated source: `source-3/simroot_v2/class_StaticObjectPane.cpp`
- Primary class doc: [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md)
- Main address docs: [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md), [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md), and [UID:0001DN][0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md)

## File Role

`StaticObjectPane.cpp` likely owns the `ObjectPane` subclass used for map static objects. It stores the static object id, delegates bounds/render/hit-test work to the static-object image library, and sends a small object-interaction packet when the user clicks inside the static object's active bounds.

Keep this separate from [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md). The image library owns static-object asset tables and drawing primitives; `StaticObjectPane` owns the live map-object wrapper, object identity, map click handling, and `ObjectPane` lifecycle.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `StaticObjectPane` | `0x00537900-0x00537abf`, [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md), scalar destructor at `0x0053d740` | Map object wrapper for static map props. |
| static object bounds/render hooks | `0x00537950`, `0x00537970`, `0x005379a0` | Hit-test, copy-bounds, and render forwarding through `g_pStaticObjectManager`. |
| static object interaction sender | `0x005379d0-0x00537abf`, `0x00537ac0-0x00537b39` | Handles click/mouse event data and sends opcode `0x43` subcommand `0x03` style interaction payload; the later helper is a direct packet sender with no current static callers. |

## Boundary Notes

- IDA confirms a real helper at `0x00537950-0x00537970` that active `class_StaticObjectPane.cpp` omits. It calls the static-object manager with `m_staticObjectId` and two caller-supplied coordinates/arguments.
- Active generated source lists `HandleStaticObjectEvent` at `0x005379d0`, but the emitted body is missing after the local event struct. IDA decompilation confirms a real packet-sending body through `0x00537abf`.
- 2026-05-28 IDA byte/disassembly review confirms [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) as a second StaticObjectPane packet helper after a one-byte alignment gap; IDA has no static callers, so final method name stays provisional.
- Destructor adjustor thunks at `0x0053cf88` and `0x0053cf93` forward to the scalar deleting destructor at `0x0053d740`; `0x0053cf93` is currently listed as missing code in disabled output.
- The global pointer `g_pStaticObjectManager` is a dependency on [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), not proof that static-object image library code belongs in this file.
- 2026-05-26 IDA static-pool review identifies the [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md) [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) at `0x0069b8bc`, constructed by `0x0041a160` with block size `300` and `16` blocks per chunk.

## Cross-References

- [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md)
- [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md)
- [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md)
- [UID:0001DN][0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `86`.
  - Evidence: document captures map-object wrapper role, proposed contents, static-image-library dependency boundary, packet helper split, omitted helper, destructor thunks, pool allocator evidence, and cross-references; confidence is high because role and core range are strongly anchored.
