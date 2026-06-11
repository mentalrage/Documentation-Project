*** UID:0001UH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Confidence: strong for documented offsets and lifecycle evidence, medium for final type/name.
- Reconstructable: true as a source-level embedded layout declaration; C++ body remains blank because the full item-state declaration is still unresolved.

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

## Lifecycle Evidence

- [UID:0002E7][0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor](by-memory/0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor.md) clears the equipment-entry vector triple at item-state offsets `+0x240/+0x244/+0x248` during construction, after category lookup setup and before the encode/decode key strings.
- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md) is a non-destructive reset: it frees each active entry's trailing buffer triple at entry `+0xa8/+0xac/+0xb0`, zeroes that triple, and writes `end = begin` while preserving the vector allocation/capacity.
- [UID:0002EB][0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor](by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md) releases the vector storage at item-state `+0x240` through [UID:0002UE][0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper](by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md), which walks the `0xb4` stride entries, calls the entry-range release helper, frees the backing allocation, and clears the vector triple.
- The reset helper and destructor helper therefore document two different lifecycle phases: command-time clearing of active entry contents versus object-destruction release of the vector allocation.

## Boundary And Cleanup Caveats

- Do not merge this equipment-entry vector with category-entry cleanup. [UID:0002EC][0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries](by-memory/0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries.md) walks category lookup storage at item-state `+0x220` and frees `0xc0` byte category entries; this layout describes the separate equipment-entry vector at `+0x240`.
- The entry stride `0xb4` is shared between the reset helper and the destructor vector helper, but the final source-facing entry name remains open. The current `EquipmentEntry` label should be treated as a role name until item/category entry fields are reconciled.
- The entry-local trailing buffer looks vector/string-like because both reset and destruction validate MSVC large-allocation headers before freeing. The current page should not name the buffer as item text, encoded bytes, or category parts until parser/render consumers are audited.

## Score Rationale

- Completion is `80` because the page now records constructor initialization, command-time reset, destructor-time vector release, the category-entry cleanup boundary, object embedding under `FittingRoomDialogItemState`, and the remaining source-name caveats.
- Confidence is `86` because the `+0x240/+0x244/+0x248` vector triple, `0xb4` stride, and `+0xa8/+0xac/+0xb0` entry buffer triple are corroborated by constructor, reset, destructor, class, and file docs. Confidence remains capped because the final entry type/name and full item-state declaration are not source-quality yet.

## Cross-References

- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- [UID:00004Z][FittingEquipmentState](by-class/FittingEquipmentState.md)
- [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)

## Changes

- 2026-05-30: Scored the layout page from 0/0 to 74/84 after the method page was expanded with exact offset and raw-code evidence. Evidence: IDA MCP decompilation for `0x0041d5e0` confirms the `+0x240/+0x244/+0x248` vector fields, `0xb4` entry stride, and `+0xa8/+0xac/+0xb0` buffer triplet.
- 2026-06-03: Replaced older owner wording with a working-label statement. Live IDA MCP reconfirmed the same layout evidence: `sub_41D5E0` reads/writes the vector tail, `sub_41C310` calls it with dialog `this + 0x504`, and `sub_422020` initializes the vector fields at relative offsets `+0x240/+0x244/+0x248`.
- 2026-06-04: Marked `RECONSTRUCTABLE:TRUE` without changing scores.
  - Reasoning: existing live IDA evidence proves the embedded vector-tail and entry-buffer layout as real source-level data structure information; parent attachment remains blank because the complete fitting-room item-state declaration and final type name are still unresolved.
- 2026-06-07 A006 documentation pass:
  - Before: the page was `74/84` and focused on reset-method offsets.
  - After: raised to `80/86`.
  - Summary/evidence: added constructor initialization evidence, destructor vector-release evidence, the reset-versus-destruction lifecycle distinction, the boundary against category-entry cleanup at `+0x220`, and explicit naming caveats for the `0xb4` entry and trailing buffer.
