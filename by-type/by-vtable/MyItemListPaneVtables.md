*** UID:0001Y8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MyItemListPane Vtables

## Status

- Confidence: strong for table bases, slot boundaries, and constructor stores.
- Covered class: [UID:00008W][MyItemListPane](by-class/MyItemListPane.md).
- Likely source file: [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md), or folded into [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- Evidence basis: IDA MCP `list_globals`, `xrefs_to`, `disasm`, and `py_eval` checks on 2026-05-26.

## Current IDA Recheck

IDA MCP `py_eval` on 2026-06-01 rechecked the current IDB table bases, locator pointers, slot counts, constructor stores, and the row-renderer virtual slot. The primary table at `0x00619f28` is `??_7MyItemListPane@@6B@`, has locator `??_R4MyItemListPane@@6B@` at `0x00619f24`, contains 33 slots, and is stored by the constructor at `0x004aeb9a`. The secondary table at `0x00619fb0` has locator `??_R4MyItemListPane@@6B@_0`, contains 11 slots, and is stored at `0x004aeba5`. The tertiary table at `0x00619fe0` has locator `??_R4MyItemListPane@@6B@_1`, contains 2 slots, and is stored at `0x004aebb1`.

The same recheck confirmed the local boundaries: `AddItemDialog` tertiary vtable data precedes this group at `0x00619f1c`, and `AddItemWithCountDialog` begins at `0x00619fec` after the tertiary locator at `0x00619fe8`. The `MyItemListPane` tertiary table therefore ends at `0x00619fe8`; do not merge it into the following add-item dialog vtable family.

IDA also still reports the primary `+0x80` slot value as `0x004aec90`, with the only data reference to that function pointer at `0x00619fa8`. That matches the documented `MyItemListPane::DrawListEntry` virtual entry and the exact child page for the draw body.

## Table Inventory

| View | RTTI pointer | Vtable base | Constructor store | Object offset |
| --- | --- | --- | --- | --- |
| Primary | `0x00619f24` | `0x00619f28` | `0x004aeb9a` | `+0x00` |
| Secondary | `0x00619fac` | `0x00619fb0` | `0x004aeba5` | `+0xa0` |
| Tertiary | `0x00619fdc` | `0x00619fe0` | `0x004aebb1` | `+0xa4` |

The primary table ends before secondary RTTI at `0x00619fac`. The secondary table ends before tertiary RTTI at `0x00619fdc`. The tertiary table has two slots and ends before `AddItemWithCountDialog` RTTI at `0x00619fe8`.

## Key Slots

| Table | Offset | Target | Interpretation |
| --- | --- | --- | --- |
| Primary `0x00619f28` | `+0x00` | `0x0047ea50` | Shared list-pane scalar deleting destructor target; see [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md). |
| Primary `0x00619f28` | `+0x48` through `+0x7c` | `0x004f3f20` through `0x004f45b0` plus no-op guard slots | Inherited `ListPane` row, selection, and list-management virtuals. |
| Primary `0x00619f28` | `+0x80` | `0x004aec90` | `MyItemListPane::DrawListEntry`. |
| Secondary `0x00619fb0` | `+0x00` | `0x0047e8ad` | Compiler adjustor thunk subtracting `0xa0` and jumping to `0x0047ea50`. |
| Secondary `0x00619fb0` | `+0x1c` | `0x004a89f0` | Shared secondary-view list/dialog support slot. |
| Tertiary `0x00619fe0` | `+0x00` | `0x0047e8b8` | Compiler adjustor thunk subtracting `0xa4` and jumping to `0x0047ea50`. |
| Tertiary `0x00619fe0` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

The adjustor thunks are already covered by [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) and should not be reconstructed as handwritten `MyItemListPane` methods.

## Evidence Notes

- IDA `list_globals *MyItemListPane*` reports primary, secondary, and tertiary vtable bases at `0x00619f28`, `0x00619fb0`, and `0x00619fe0`, plus matching RTTI records.
- IDA `xrefs_to` the table bases reports constructor stores at `0x004aeb9a`, `0x004aeba5`, and `0x004aebb1` inside `MyItemListPane::MyItemListPane` at `0x004aeb30`.
- IDA `xrefs_to 0x004aec90` reports only the primary-table data reference at `0x00619fa8`, confirming `DrawListEntry` is reached virtually.
- Current `class_MyItemListPane.meta_wave3` reports `vtable_count: 0`, so the generated vtable inventory is incomplete even though the active source names placeholder vtable fields.

## Source-Layout Implication

Model `MyItemListPane` as a `ListPane`-derived item-picker list with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. The only class-specific primary-table override confirmed in this pass is the row renderer at slot `+0x80`; most other slots are inherited list/pane behavior.

Keep the shared scalar deleting destructor and adjustor thunks as compiler/vtable support evidence. The reconstructable handwritten behavior for this class remains the constructor and `DrawListEntry`.

## Cross-References

- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md)
- [UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md)
- [UID:00025A][0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData](by-memory/0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData.md)
- [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md)
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md)
- [UID:0001VE][MyItemListPaneEntryLayouts](by-type/by-struct/MyItemListPaneEntryLayouts.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)

## Changes

- 2026-06-01: The page previously had unevaluated validator scores (`COMPLETION:0`, `CONFIDENCE:0`) and a blank reconstructability flag despite already containing a detailed vtable inventory. It is now marked `RECONSTRUCTABLE:TRUE` with `COMPLETION:86` and `CONFIDENCE:90` after IDA MCP rechecked the decorated vtable globals, RTTI locator placement, exact slot counts, constructor stores, neighboring vtable boundaries, and the `DrawListEntry` virtual slot data reference. The score remains below the 95+ final-audit gate because final source declarations and the exact source-file placement are not fully closed.
