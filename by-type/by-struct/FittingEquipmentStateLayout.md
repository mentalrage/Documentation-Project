*** UID:0001UH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingEquipmentStateLayout

## Status

- Entity kind: embedded fitting-room state layout
- Working owner label: [UID:00004Z][FittingEquipmentState](by-class/FittingEquipmentState.md)
- Likely source owner: [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) in [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Main evidence: IDA decompilation of `0x0041d5e0` and constructor initialization at `0x00422020`.
- Confidence: strong for documented offsets, medium for final type/name.

## Layout

`ResetEntries` only needs the equipment-entry vector tail of the larger fitting-room item-state object:

| Offset | Type hypothesis | Evidence |
| --- | --- | --- |
| `+0x240` | `EquipmentEntry* begin` | Read as `this[144]`; constructor zeroes it at `0x004220d1`. |
| `+0x244` | `EquipmentEntry* end` | Read as `this[145]`; reset writes `end = begin`; constructor zeroes it at `0x004220db`. |
| `+0x248` | `EquipmentEntry* capacity` | Constructor zeroes `this[146]`; not used by `ResetEntries`. |

`EquipmentEntry` stride is `0xb4` bytes. The reset loop starts the buffer pointer triple at entry offset `+0xa8` and then advances the entry pointer by `0xb4`.

| Entry offset | Type hypothesis | Reset behavior |
| --- | --- | --- |
| `+0x000-+0x0a7` | item/equipment metadata | Not touched by `ResetEntries`. |
| `+0x0a8` | `uint8_t* bufferBegin` | Freed if non-null, then zeroed. |
| `+0x0ac` | `uint8_t* bufferCurrent` | Zeroed after buffer release. |
| `+0x0b0` | `uint8_t* bufferEnd` | Used for span/large-allocation check, then zeroed. |

## Ownership Notes

The `FittingEquipmentState` label is useful for the reset method, but IDA caller and constructor evidence tie the object to the larger fitting-room item-state record:

- `FittingRoomDialog::OnCommand` at `0x0041c404` calls `ResetEntries` with `this + 0x504`.
- `FittingRoomDialog` constructor calls the item-state constructor at `0x0041be6c` with the same `this + 0x504` pointer.
- The `0x00422020` constructor initializes strings, cache path, category storage, and the `+0x240/+0x244/+0x248` equipment-entry vector in one object.

Until the full item-state declaration is recovered, keep this as a layout page rather than a final standalone class declaration.

## Cross-References

- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- [UID:00004Z][FittingEquipmentState](by-class/FittingEquipmentState.md)
- [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)

## Changes

- 2026-05-30: Scored the layout page from 0/0 to 74/84 after the method page was expanded with exact offset and raw-code evidence. Evidence: IDA MCP decompilation for `0x0041d5e0` confirms the `+0x240/+0x244/+0x248` vector fields, `0xb4` entry stride, and `+0xa8/+0xac/+0xb0` buffer triplet.
- 2026-06-03: Replaced generated-owner wording with a working-label statement. Live IDA MCP reconfirmed the same layout evidence: `sub_41D5E0` reads/writes the vector tail, `sub_41C310` calls it with dialog `this + 0x504`, and `sub_422020` initializes the vector fields at relative offsets `+0x240/+0x244/+0x248`.
