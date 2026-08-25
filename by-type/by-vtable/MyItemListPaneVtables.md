*** UID:0001Y8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MyItemListPane Vtables

## UID0000LO Accepted Compiler-Only Disposition - 2026-08-14

This page remains attached to UID00008W as evidence but is now explicitly
non-reconstructable and non-emitting. Primary `0x00619f28` (33 slots),
secondary `0x00619fb0` (11 slots), and tertiary `0x00619fe0` (2 slots) begin
after RTTI locators at `0x00619f24`, `0x00619fac`, and `0x00619fdc`; constructor
stores occur at `0x004aeb9a`, `0x004aeba5`, and `0x004aebb1`. The primary
`+0x80` slot is the source-authored renderer `0x004aec90` and routes through
its method page, not this table page.

The shared scalar deleting destructor `0x0047ea50`, secondary/tertiary
adjustors `0x0047e8ad` and `0x0047e8b8`, all inherited slots, RTTI objects, and
neighbor table boundaries are compiler products. No CPP/H text is emitted from
UID0001Y8, and no table object is modeled as handwritten source. Historical
owner/emitter wording below is superseded while its measured inventory remains
valid evidence.

Exact compiler-data ranges are primary table
`0x00619f28-0x00619fac`, secondary `0x00619fb0-0x00619fdc`, and tertiary
`0x00619fe0-0x00619fe8`. RTTI objects are primary COL
`0x00647354-0x00647368`, CHD `0x00647368-0x00647378`, base array
`0x00647378-0x0064739c`, self BCD `0x0064739c-0x006473b8`, secondary COL
`0x006473b8-0x006473cc`, tertiary COL `0x006473cc-0x006473e0`, and type
descriptor `0x00675ff0-0x00676010`. Binding cells at
`0x00619f24/0x00619fac/0x00619fdc` select the three COLs; descriptor references
occur at `0x00647360`, `0x0064739c`, `0x006473c4`, and `0x006473d8`.

## Status

- Confidence: strong for table bases, slot boundaries, and constructor stores.
- Covered class: [UID:00008W][MyItemListPane](by-class/MyItemListPane.md).
- Likely source file: [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md), or folded into [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- Evidence basis: IDA MCP `list_globals`, `xrefs_to`, `disasm`, and `py_eval` checks on 2026-05-26.
- Parent gate: assigned to [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) after this vtable page reached `87/91` and the direct class parent reached `85/86`; source file [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md) is already `86/85`.

## Current IDA Recheck

IDA MCP `py_eval` on 2026-06-01 rechecked the current IDB table bases, locator pointers, slot counts, constructor stores, and the row-renderer virtual slot. The primary table at `0x00619f28` is `??_7MyItemListPane@@6B@`, has locator `??_R4MyItemListPane@@6B@` at `0x00619f24`, contains 33 slots, and is stored by the constructor at `0x004aeb9a`. The secondary table at `0x00619fb0` has locator `??_R4MyItemListPane@@6B@_0`, contains 11 slots, and is stored at `0x004aeba5`. The tertiary table at `0x00619fe0` has locator `??_R4MyItemListPane@@6B@_1`, contains 2 slots, and is stored at `0x004aebb1`.

The same recheck confirmed the local boundaries: `AddItemDialog` tertiary vtable data precedes this group at `0x00619f1c`, and `AddItemWithCountDialog` begins at `0x00619fec` after the tertiary locator at `0x00619fe8`. The `MyItemListPane` tertiary table therefore ends at `0x00619fe8`; do not merge it into the following add-item dialog vtable family.

IDA also still reports the primary `+0x80` slot value as `0x004aec90`, with the only data reference to that function pointer at `0x00619fa8`. That matches the documented `MyItemListPane::DrawListEntry` virtual entry and the exact child page for the draw body. B004 UID0002JQ incorporation now records that child as `88/90`, class-owned/class-emitted through [UID:00008W][MyItemListPane](by-class/MyItemListPane.md), and first-draft C++ ready.

2026-06-11 live IDA MCP rechecked the same facts against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`: the constructor stores are still `0x004aeb9a`, `0x004aeba5`, and `0x004aebb1`; primary/secondary/tertiary table bases still have one direct constructor xref each; primary slot `+0x80` still targets `0x004aec90`; and `0x004aec90` still has the single data xref at `0x00619fa8`. `int_convert.py` verified `0x80 == 128`, `0xa0 == 160`, and `0xa4 == 164` for the slot/object-offset conversions.

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
| Primary `0x00619f28` | `+0x80` | `0x004aec90` | `MyItemListPane::DrawListEntry`; exact child UID0002JQ now carries first-draft source C++. |
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

Model `MyItemListPane` as a `ListPane`-derived item-picker list with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. The only class-specific primary-table override confirmed in this pass is the row renderer at slot `+0x80`; most other slots are inherited list/pane behavior. UID0002JQ now owns the source body for that override, so this vtable page remains layout evidence rather than an emitter of method code.

Keep the shared scalar deleting destructor and adjustor thunks as compiler/vtable support evidence. The reconstructable handwritten behavior for this class remains the constructor and `DrawListEntry`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | The page now records current RTTI locator placement, exact table boundaries, constructor stores, key inherited slots, class-specific draw override, adjustor thunks, neighboring `AddItemDialog`/`AddItemWithCountDialog` boundaries, and direct class attachment. Completion remains below final audit because inherited slot declarations still need full source-facing names and there is no exact by-memory vtable-data child split yet. |
| Confidence | 91 | Current IDA evidence is very strong for table identity, class ownership, object offsets, boundaries, and the `DrawListEntry` virtual slot. Confidence remains below 95 because final header declarations and inherited virtual names are not exhaustively audited. |

## Cross-References

- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md)
- [UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md)
- [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md)
- [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md)
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md)
- [UID:0001VE][MyItemListPaneEntryLayouts](by-type/by-struct/MyItemListPaneEntryLayouts.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)

## Changes

- 2026-06-01: The page previously had unevaluated validator scores (`COMPLETION:0`, `CONFIDENCE:0`) and a blank reconstructability flag despite already containing a detailed vtable inventory. It is now marked `RECONSTRUCTABLE:TRUE` with `COMPLETION:86` and `CONFIDENCE:90` after IDA MCP rechecked the decorated vtable globals, RTTI locator placement, exact slot counts, constructor stores, neighboring vtable boundaries, and the `DrawListEntry` virtual slot data reference. The score remains below the 95+ final-audit gate because final source declarations and the exact source-file placement are not fully closed.
- 2026-06-11 Agent-A005 Batch 152:
  - Before: `86/90`, `AUTOGEN_PARENT_UID` blank because the direct class parent was below the strict `85/85` gate.
  - After: `87/91`, `AUTOGEN_PARENT_UID:00008W`.
  - Evidence: live IDA MCP rechecked the constructor stores, one direct base xref for each table, RTTI locator values, exact primary/secondary/tertiary slot counts, the sole `0x004aec90` draw-method data xref at `0x00619fa8`, and neighboring boundaries. [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) is now `85/86`, so the direct class parent clears the gate. Final C++ remains blank below the 95/95 gate.
- 2026-07-02 B004 UID0002JQ implementation callback:
  - Score unchanged at `87/91`; this page remains vtable/type evidence.
  - Updated the primary `+0x80` slot notes to record that [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md) is now `88/90`, class-owned/class-emitted, and carries first-draft `MyItemListPane::DrawListEntry` C++.
  - Evidence: B004 live MCP reconfirmed the vtable-only data xref at `0x00619fa8`, constructor vtable stores, zero direct callers, and inherited ListPane row-draw dispatch shape.
