*** UID:00004Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingEquipmentState

## Status

- Confidence: strong for the single known method and layout offsets, medium for final source-level class identity.
- Working label: embedded fitting-room equipment-entry reset helper.
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Evidence basis: live IDA MCP function lookup, callers/xrefs, callees, decompilation, and disassembly checks on 2026-06-03 with a Batch088 recheck on 2026-06-07.
- Exact memory page: [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- Layout page: [UID:0001UH][FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md)

## Role

Embedded state helper for resetting the fitting-room equipment/appearance entries after the user resets or restores preview appearance.

IDA caller and constructor evidence indicate this is probably a support view into [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md), not an independently allocated source-level class. `FittingRoomDialog::OnCommand` passes `this + 0x504` to `ResetEntries`, and the constructor at `0x0041bdd0` initializes the same subobject through `0x00422020`.

## IDA Evidence Snapshot

Live IDA MCP checks on 2026-06-03 confirm the current ownership boundary:

| Address | IDA result | Evidence |
| --- | --- | --- |
| `0x0041d5e0` | `sub_41D5E0`, size `0x92` | Reset helper body; decompilation reads `this[144]`/`this[145]`, steps entries by `0xb4`, frees entry buffers, and writes `this[145] = this[144]`. |
| `0x0041c310` | `sub_41C310`, size `0x286` | Sole caller at `0x0041c404`; `OnCommand` sets `ecx = this + 0x504` before calling `sub_41D5E0`. |
| `0x0041bdd0` | `sub_41BDD0`, size `0x480` | Dialog constructor computes `ecx = this + 0x504` and calls `sub_422020` at `0x0041be6c`. |
| `0x00422020` | `sub_422020`, size `0x30a` | Item-state constructor zeroes the equipment-entry vector tail at relative offsets `+0x240/+0x244/+0x248`. |

IDA `callers`/`xrefs_to` found exactly one code caller for `0x0041d5e0` (`0x0041c404`) and exactly one code caller for `0x00422020` (`0x0041be6c`). IDA `callees` for `0x0041d5e0` are `sub_5C7526` and `__invalid_parameter_noinfo_noreturn`.

2026-06-07 Batch088 recheck preserved the same ownership picture: `0x0041d5e0-0x0041d672` is a 146-byte reset helper, its only caller is still `FittingRoomDialog::OnCommand` at `0x0041c404`, and `0x00422020-0x0042232a` is constructed only from the dialog constructor at `0x0041be6c`. No standalone constructor, allocator path, vtable, or independent lifetime owner was found for a top-level `FittingEquipmentState` class.

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

Keep the method in `cashshop/FittingRoom.cpp` with the fitting-room item-state code. The `FittingEquipmentState` name is useful as a documentation label for this embedded vector tail, but current IDA evidence does not justify a separate original `FittingEquipmentState.cpp` or a standalone top-level class declaration.

## Assignment Decision

No assignment was made under the corrected Batch088 gate. The plausible direct source module [UID:0000JE][FittingRoom](by-file/FittingRoom.md) already satisfies the parent side of the gate at `85/87`, but this child remains `82/88`: completion is below `85` because the page documents an embedded item-state/vector-tail view rather than a proven standalone original class. Assigning this class page to the file root would overstate the recovered source-level class model.

Final C++ remains blank. If later evidence proves an original nested declaration inside `FittingRoomDialogItemState`, this page should either be renamed/reframed as that nested type or kept as a support view with references to the exact by-memory reset helper.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `82` | The class page records current live IDA function bounds, sole caller, constructor embedding, vector-tail layout, callees, source-placement policy, and the explicit no-assignment decision. Completion remains below `85` because the original source-level type name and full enclosing item-state declaration are still unresolved. |
| Confidence `88` | Confidence increased because the Batch088 recheck confirms the embedded-owner claim and lack of independent lifetime evidence. Confidence remains capped because IDA proves the layout and call sites, not a standalone original class name. |

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md)
- [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md)
- [UID:0001UH][FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md)
- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)

## Changes

- 2026-05-30: Scored the class page from 0/0 to 70/82 and changed the confirmed method row to a UID link after expanding the exact by-memory method page. Evidence: IDA MCP confirms the `0x0041d5e0` function, sole caller at `0x0041c404`, entry-vector offsets, and large-allocation guarded buffer release behavior.
- 2026-06-03: Raised completion/confidence to `76/86` after current live IDA MCP checks reconfirmed `sub_41D5E0` bounds (`0x92` bytes), its only caller at `0x0041c404`, the constructor call to `sub_422020` at `0x0041be6c`, the `this + 0x504` embedded object pointer, the item-state vector initialization at `+0x240/+0x244/+0x248`, and the reset helper callees `sub_5C7526` plus `__invalid_parameter_noinfo_noreturn`. The update also removes generated-source evidence from the status section and keeps final C++/parent attachment blank because IDA does not prove a standalone original class.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the embedded fitting-room equipment reset helper unclassified.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `76/86` and the page still documents this as an embedded support view rather than a proven standalone source-level class.
  - Summary/evidence: live IDA MCP reconfirms `0x0041d5e0-0x0041d672` with sole caller `0x0041c404`, plus the constructor path `0x0041bdd0 -> 0x00422020` that initializes the same embedded item-state subobject.
- 2026-06-07 Batch088 class coverage audit:
  - Before: scores were `76/86`, assignment was blank, and the page already warned that this was likely an embedded support view.
  - After: raised to `82/88`; assignment remains blank.
  - Summary/evidence: IDA/MCP recheck reconfirmed the reset helper bounds, sole OnCommand caller, sole item-state constructor caller from the dialog constructor, and reset callees. The parent [UID:0000JE][FittingRoom](by-file/FittingRoom.md) clears `85/85`, but this child does not because standalone class identity is not proven.
