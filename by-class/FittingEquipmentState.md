*** UID:00004Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FittingEquipmentState

## Status

- Confidence: strong for the single known method, layout offsets, and embedded item-state parent; medium for final source-level class identity.
- Working label: embedded fitting-room equipment-entry reset helper.
- Direct assignment parent: [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md), as an embedded support view.
- Source module context: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Evidence basis: live IDA MCP function lookup, callers/xrefs, callees, decompilation, and disassembly checks on 2026-06-03 with Batch088 and 2026-06-11 rechecks, plus B008 current MCP session `c9b60f19` confirming UID0000WS as an item-state-owned source-ready vector clear.
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

2026-06-11 normal-task recheck connected this support view to the refreshed direct parent [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md). IDA still reports the reset helper `0x0041d5e0` as `sub_41D5E0`, size `0x92`, with one caller at `0x0041c404` in `sub_41C310`; the item-state constructor helper `0x00422020` is still called only from `0x0041be6c` in `sub_41BDD0`; and the vector-destroy helper at `0x00423870` confirms the same `0xb4` entry stride and begin/end/capacity triple. Decimal offsets from the decompiler were rechecked with `int_convert.py`: item-state offsets `544/576/580/584/588/592/616` map to `0x220/0x240/0x244/0x248/0x24c/0x250/0x268`, and entry offsets/stride `176/180/45` map to `0xb0/0xb4/0x2d`.

2026-07-03 B008 callback supersedes any direct-emitter reading for UID0000WS. Current MCP session `c9b60f19` confirms the exact `0x0041d5e0-0x0041d671` / `0x92` body, sole OnCommand caller at `0x0041c404`, dialog item-state receiver `this+0x504`, vector fields `+0x240/+0x244/+0x248`, per-entry tail cleanup at `+0xa8/+0xac/+0xb0`, `sub_5C7526`, and large-allocation guard. The source body now emits through [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) as `ResetEquipmentEntries()` with `m_selectedFittingItems.clear();`; this page remains support-view documentation for the equipment-entry layout/tail, not a standalone `FittingEquipmentState.cpp` route.

## Confirmed Method

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md) | support-view label for `FittingRoomDialogItemState::ResetEquipmentEntries` | Source emits through [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) as `m_selectedFittingItems.clear();`. This support view records the raw entry vector at `+0x240/+0x244`, per-entry buffer triplet `+0xa8/+0xac/+0xb0`, and final `end = begin` lowering. |

## Layout Notes

- `+0x240`: `EquipmentEntry* begin`.
- `+0x244`: `EquipmentEntry* end`.
- `+0x248`: likely `EquipmentEntry* capacity`, initialized by `0x00422020` and not changed by `ResetEntries`.
- Entry stride is `0xb4`; the trailing heap-buffer triple is at entry offsets `+0xa8`, `+0xac`, and `+0xb0`.
- Large entry buffers use the same MSVC allocator-header guard pattern seen elsewhere: spans of at least `0x1000` read the allocation base from the dword immediately before the user pointer and validate a `<= 0x1f` header gap before freeing.

## Source Placement Notes

Keep the method in `cashshop/FittingRoom.cpp` with the fitting-room item-state code. The `FittingEquipmentState` name is useful as a documentation label for this embedded vector tail, but current IDA evidence does not justify a separate original `FittingEquipmentState.cpp` or a standalone top-level class declaration.

## Assignment Decision

Assigned under the corrected direct-parent gate to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md). This support-view class page remains `85/89`, the direct parent is `88/90`, and the exact UID0000WS by-memory target is now `88/91`, so the source-ready method routes through the item-state parent rather than through a standalone support-view class.

The assignment is intentionally to the item-state class, not to the broader [UID:0000JE][FittingRoom](by-file/FittingRoom.md) file root. The page documents an embedded item-state/vector-tail support view: `FittingRoomDialog::OnCommand` passes `this + 0x504` into the reset helper, the dialog constructor constructs the same embedded subobject through `0x00422020`, and no standalone constructor, allocator path, vtable, or independent lifetime owner has been found for a top-level `FittingEquipmentState` class.

The class-level C++ block remains blank to avoid creating a fake standalone `FittingEquipmentState` declaration. UID0000WS now carries the emitted method body in the exact by-memory child; this page preserves support-view context for layout and historical naming only.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The class page records current live IDA function bounds, sole caller, constructor/destructor embedding, vector-tail layout, offset conversions, callees, source-placement policy, and the direct item-state assignment decision. Completion clears the assignment gate because the evidence now identifies the direct embedded parent even though the standalone source-level type name remains unresolved. |
| Confidence `89` | Confidence increased because the 2026-06-11 recheck aligns the reset helper, constructor, vector-destroy helper, refreshed struct layout, and item-state parent. Confidence remains capped because IDA proves the layout and call sites, not a standalone original class name. |

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md)
- [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md)
- [UID:0001UH][FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md)
- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)

## Changes

- 2026-07-03 B008 UID0000WS empty-emitter implementation callback: Class metadata unchanged. Historicalized the old direct-emitter implication and clarified that [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md) now emits through [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) as `FittingRoomDialogItemState::ResetEquipmentEntries()` with formal `m_selectedFittingItems.clear();`. Current MCP session `c9b60f19` confirms the exact reset-helper range/size, sole OnCommand caller, item-state receiver `this+0x504`, vector fields `+0x240/+0x244/+0x248`, entry-tail cleanup and large-allocation guard. This page remains support-view documentation, not a standalone `FittingEquipmentState.cpp` source owner.
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
- 2026-06-11 normal task:
  - Before: scores were `82/88`, assignment was blank, and the page treated the class label as below the corrected assignment gate.
  - After: raised to `85/89` and assigned to direct parent [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md).
  - Summary/evidence: live IDA MCP recheck reconfirmed the reset helper, sole OnCommand caller, item-state constructor caller, vector-destroy helper, `0xb4` entry stride, and vector-tail offsets; the refreshed [UID:0001UH][FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md) page then independently cleared `85/88` under the same item-state parent. At that time the support-view class C++ remained blank below the `95/95` gate; B008's 2026-07-03 UID0000WS callback later moved the exact method body to the by-memory child under [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md).

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (00004Z)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- This page remains an embedded-layout/reset support view at 85/89. The former standalone FittingEquipmentState and second-vector interpretation is historical; live storage belongs to UID000051 as m_selectedFittingItems.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-068 | 0000WS | UID0000WS clears the same selected-entry vector; retain `ResetEquipmentEntries()` as the observed command-role method name but change its body/prose from `m_equipmentEntries.clear()` to `m_selectedFittingItems.clear()`. | Certain for storage/body, strong for method/member spelling | Live 0x0041d5e0 decompile, sole OnCommand caller, shared +0x240 vector and 0xb4 stride. | UID0000WS formal/prose; UID000051/UID00004Z/UID0001UH/UID0000JE support. | historicalize | implemented |
| C2E6-072 | 000051 | Constructor/destructor/layout/support pages that call the +0x240 vector `m_equipmentEntries` must preserve their binary facts but historicalize that lifecycle-only name in favor of `m_selectedFittingItems`. | Certain for identity, strong for spelling | Same dialog-relative/item-state-relative storage across 0x0041f100/0x0041f2b0/0x0041fcd0/0x0041d5e0/0x00422020/0x00422330/0x00423870. | UID0002E7, UID0002EB, UID0000WS, UID0002UE, UID000051, UID00004Z, UID0001UH, UID0000JE. | historicalize | implemented |
