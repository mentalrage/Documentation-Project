*** UID:00004Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingEquipmentState

## Status

- Confidence: strong for the single known method and layout offsets, medium for final source-level class identity.
- Current Wave3 file: `class_FittingEquipmentState.cpp`
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Evidence basis: Wave3 inspection, generated source, and IDA MCP checks on 2026-05-23 and 2026-05-26.
- Exact memory page: [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- Layout page: [UID:0001UH][FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md)

## Role

Embedded state helper for resetting the fitting-room equipment/appearance entries after the user resets or restores preview appearance.

IDA caller and constructor evidence indicate this is probably a support view into [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md), not an independently allocated source-level class. `FittingRoomDialog::OnCommand` passes `this + 0x504` to `ResetEntries`, and the constructor at `0x0041bdd0` initializes the same subobject through `0x00422020`.

## Confirmed Method

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md) | `ResetEntries` | Called by `FittingRoomDialog::OnCommand` at `0x0041c404`; walks entry vector `+0x240/+0x244`, releases each entry buffer at `+0xa8/+0xac/+0xb0`, and collapses `end` back to `begin`. |

## Layout Notes

- `+0x240`: `EquipmentEntry* begin`.
- `+0x244`: `EquipmentEntry* end`.
- `+0x248`: likely `EquipmentEntry* capacity`, initialized by `0x00422020` and not changed by `ResetEntries`.
- Entry stride is `0xb4`; the trailing heap-buffer triple is at entry offsets `+0xa8`, `+0xac`, and `+0xb0`.
- Large entry buffers use the same MSVC allocator-header guard pattern seen elsewhere: spans of at least `0x1000` read the allocation base from the dword immediately before the user pointer and validate a `<= 0x1f` header gap before freeing.

## Source Placement Notes

Keep the method in `cashshop/FittingRoom.cpp` with the fitting-room item-state code. The current generated one-class file is a reconstruction convenience; it should not drive a separate original `FittingEquipmentState.cpp` unless future evidence finds independent construction or broader callers.

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md)
- [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md)
- [UID:0001UH][FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md)
- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)

## Changes

- 2026-05-30: Scored the class page from 0/0 to 70/82 and changed the confirmed method row to a UID link after expanding the exact by-memory method page. Evidence: IDA MCP confirms the `0x0041d5e0` function, sole caller at `0x0041c404`, entry-vector offsets, and large-allocation guarded buffer release behavior.
