*** UID:0000E1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticObjectPane

## Status

- Confidence: strong for role and anchors.
- Likely source file: [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_StaticObjectPane.cpp`

## Class Purpose

`StaticObjectPane` is the map-object wrapper for static map props. It derives through [UID:00009R][ObjectPane](by-class/ObjectPane.md), stores `m_staticObjectId` at the first subclass field area, asks [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) for bounds/render/hit-test behavior, and emits a static-object interaction packet when a click lands in the active static-object rectangle.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00537900-0x00537947` | Builds an `ObjectPane` with object type `5`, stores the static object id, and installs all three vtable views. |
| probable hit-test helper | `0x00537950-0x00537970` | Calls the static-object manager with `m_staticObjectId` and two arguments; omitted from active generated output. |
| `CopyStaticObjectBounds` | `0x00537970-0x00537999` | Gets static-object bounds from `g_pStaticObjectManager` and copies the four-word rectangle out. |
| `RenderStaticObjectForTarget` | `0x005379a0-0x005379cc` | Forwards rendering to the static-object image library. |
| `HandleStaticObjectEvent` | `0x005379d0-0x00537abf` | Checks click/event type, verifies bounds, and sends a static-object interaction packet. |
| [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) | `0x00537ac0-0x00537b39` | IDA-missed direct packet-send helper with no current static callers; keep with this class pending final name review. |
| scalar deleting destructor | `0x0053d740-0x0053d7bd` | Destroys `ObjectPane` and optionally releases the object through the object free list. |

## Evidence Notes

- IDA caller xrefs show construction from the map object creation path at `0x0050f030`.
- Vtable/data xrefs reference the virtual methods at `0x00537970`, `0x005379a0`, `0x005379d0`, and the scalar deleting destructor at `0x0053d740`.
- 2026-05-28 IDA byte review confirms a separate helper at [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) that sends the same opcode `0x43` / subcommand `0x03` packet shape without the checked event wrapper.
- The active source currently omits `0x00537950` and emits no body for `0x005379d0`; use the memory doc before migration.

## Cross-References

- [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md)
- [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md)
- [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `86`.
- Evidence: the page documents map-object role, constructor/helper/render/event/packet/destructor ranges, caller and vtable evidence, generated omissions, and packet helper ownership; remaining completion gap is source-ready field naming and C++ detail.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, hit-test helper, bounds copy, render, event handler, and scalar deleting destructor at `0x00537900`, `0x00537950`, `0x00537970`, `0x005379a0`, `0x005379d0`, and `0x0053d740`; `0x00537ac0` remains a raw/not-modeled helper as documented. Both class (`84/86`) and parent file (`82/86`) meet the 80/80 gate.
