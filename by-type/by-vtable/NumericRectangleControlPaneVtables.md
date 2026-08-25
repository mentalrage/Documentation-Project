*** UID:0001YA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NumericStringControlPane And RectangleControlPane Vtables

## Status

- Confidence: very strong for table bases, constructor/destructor stores, key slots, source-local split children, and adjacent-table boundaries.
- Current classification: reviewed non-emitting mixed-owner index for the contiguous `NumericStringControlPane`/`RectangleControlPane` vtable island.
- Covered classes: [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md) and [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md).
- Likely source files: [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md) and [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md).
- Exact vtable-data children: [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md) and [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md).
- Source-local by-vtable children: [UID:0003IR][NumericStringControlPaneVtables](by-type/by-vtable/NumericStringControlPaneVtables.md) and [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md).
- Evidence basis: IDA MCP `list_globals`, `xrefs_to`, and `py_eval` checks on 2026-05-26 and 2026-06-01, plus A004 live IDA MCP refresh on 2026-06-12.
- Parent status: intentionally blank and `RECONSTRUCTABLE:FALSE` because this is a two-owner aggregate; exact source-local children route to their direct class parents.

## NumericStringControlPane Tables

| View | RTTI pointer | Vtable base | Constructor/destructor stores | Object offset |
| --- | --- | --- | --- | --- |
| Primary | `0x0061838c` | `0x00618390` | `0x00499951`, `0x004999fb`, `0x0049b322` | `+0x00` |
| Secondary | `0x006183f4` | `0x006183f8` | `0x00499957`, `0x00499a01`, `0x0049b328` | `+0xa0` |
| Tertiary | `0x00618424` | `0x00618428` | `0x00499961`, `0x00499a0b`, `0x0049b332` | `+0xa4` |

The primary table begins at `0x00618390` and ends before secondary RTTI at `0x006183f4`. The secondary table ends before tertiary RTTI at `0x00618424`. The tertiary table has two slots and ends before `RectangleControlPane` RTTI at `0x00618430`.

### NumericStringControlPane Key Slots

| Table | Offset | Target | Interpretation |
| --- | --- | --- | --- |
| Primary `0x00618390` | `+0x00` | `0x0049b2f0` | `NumericStringControlPane` scalar deleting destructor. |
| Primary `0x00618390` | `+0x44` | `0x00499a50` | `NumericStringControlPane::RenderNumericString`. |
| Primary `0x00618390` | `+0x48` | `0x00494b80` | Shared local control-family virtual helper. |
| Primary `0x00618390` | `+0x4c` | `0x00494bb0` | Shared local control-family virtual helper. |
| Primary `0x00618390` | `+0x50` | `0x00494bd0` | Shared local control-family virtual helper. |
| Primary `0x00618390` | `+0x54` | `0x00494c00` | Shared local control-family virtual helper. |
| Primary `0x00618390` | `+0x58` | `0x00494c10` | Shared local control-family virtual helper. |
| Primary `0x00618390` | `+0x5c` | `0x00494c30` | Shared local control-family virtual helper. |
| Primary `0x00618390` | `+0x60` | `0x0041d690` | Inherited/control-family terminal virtual slot. |
| Secondary `0x006183f8` | `+0x00` | `0x0049af7f` | Secondary deleting-destructor adjustor thunk. |
| Secondary `0x006183f8` | `+0x1c` | `0x004a89f0` | Shared secondary-view pane/control support slot. |
| Tertiary `0x00618428` | `+0x00` | `0x0049af8a` | Tertiary deleting-destructor adjustor thunk. |
| Tertiary `0x00618428` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

## RectangleControlPane Tables

| View | RTTI pointer | Vtable base | Constructor/destructor stores | Object offset |
| --- | --- | --- | --- | --- |
| Primary | `0x00618430` | `0x00618434` | `0x00499c9f`, `0x00499ce0`, `0x0049b496` | `+0x00` |
| Secondary | `0x00618498` | `0x0061849c` | `0x00499ca5`, `0x00499ce6`, `0x0049b49c` | `+0xa0` |
| Tertiary | `0x006184c8` | `0x006184cc` | `0x00499caf`, `0x00499cf0`, `0x0049b4a6` | `+0xa4` |

The primary table begins at `0x00618434` and ends before secondary RTTI at `0x00618498`. The secondary table ends before tertiary RTTI at `0x006184c8`. The tertiary table has two slots and ends before `CheckBoxControlPane` RTTI at `0x006184d4`.

### RectangleControlPane Key Slots

| Table | Offset | Target | Interpretation |
| --- | --- | --- | --- |
| Primary `0x00618434` | `+0x00` | `0x0049b490` | `RectangleControlPane` scalar deleting destructor. |
| Primary `0x00618434` | `+0x44` | `0x00499d00` | Rectangle paint/invalidating virtual. |
| Primary `0x00618434` | `+0x48` | `0x00494b80` | Shared local control-family virtual helper. |
| Primary `0x00618434` | `+0x4c` | `0x00494bb0` | Shared local control-family virtual helper. |
| Primary `0x00618434` | `+0x50` | `0x00494bd0` | Shared local control-family virtual helper. |
| Primary `0x00618434` | `+0x54` | `0x00494c00` | Shared local control-family virtual helper. |
| Primary `0x00618434` | `+0x58` | `0x00494c10` | Shared local control-family virtual helper. |
| Primary `0x00618434` | `+0x5c` | `0x00494c30` | Shared local control-family virtual helper. |
| Primary `0x00618434` | `+0x60` | `0x0049b8f0` | `RectangleControlPane::HitTestPart(int,int)` returning part code `21`. |
| Secondary `0x0061849c` | `+0x00` | `0x0049afc1` | Secondary deleting-destructor adjustor thunk. |
| Secondary `0x0061849c` | `+0x1c` | `0x004a89f0` | Shared secondary-view pane/control support slot. |
| Tertiary `0x006184cc` | `+0x00` | `0x0049afcc` | Tertiary deleting-destructor adjustor thunk. |
| Tertiary `0x006184cc` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

## Evidence Notes

- IDA `list_globals *NumericStringControlPane*` reports the three table bases at `0x00618390`, `0x006183f8`, and `0x00618428`, plus matching RTTI records.
- IDA `list_globals *RectangleControlPane*` reports the three table bases at `0x00618434`, `0x0061849c`, and `0x006184cc`, plus matching RTTI records.
- IDA `xrefs_to` each table base reports constructor/destructor stores at the addresses listed above.
- IDA `xrefs_to 0x00499a50` reports the NumericString render virtual's table data reference at `0x006183d4`.
- IDA `xrefs_to 0x00499d00` and `xrefs_to 0x0049b8f0` report Rectangle table data references at `0x00618478` and `0x00618494`.
- Historical wave metadata reported `vtable_count: 0`; wave-stage metadata is obsolete and has no current authority. Exact child pages and binary evidence govern the confirmed inventories.

## 2026-06-01 IDA Recheck

- IDA MCP `py_eval` rechecked the `.rdata` island from `0x00618380-0x006184e0`. It reports decorated vtable globals for `NumericStringControlPane` at `0x00618390`, `0x006183f8`, and `0x00618428`, and for `RectangleControlPane` at `0x00618434`, `0x0061849c`, and `0x006184cc`.
- Complete-object-locator dwords were verified at `0x0061838c`, `0x006183f4`, `0x00618424`, `0x00618430`, `0x00618498`, and `0x006184c8`. The scan shows the previous `TargetOptionEditControlPane` tertiary table ending at `0x00618388` and the next `CheckBoxControlPane` primary RTTI pointer at `0x006184d4`.
- IDA xrefs to all six vtable bases confirm the constructor/destructor stores already listed in the tables. Slot xrefs confirm `0x00499a50` at `0x006183d4`, `0x00499d00` at `0x00618478`, and `0x0049b8f0` at `0x00618494`.
- The exact child pages split this formerly aggregate-only evidence into [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md) and [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md).
- 2026-06-11 Agent-A006 live IDA MCP rechecked the Rectangle half while repairing the exact child route: method records remained constructor `0x00499c60-0x00499cd2`, non-deleting destructor helper `0x00499ce0-0x00499cff`, paint virtual `0x00499d00-0x00499d37`, scalar deleting destructor `0x0049b490-0x0049b4e5`, and the then-misidentified tail virtual `0x0049b8f0-0x0049b8f5`. Current evidence corrects that tail slot to `HitTestPart(int,int)`; vtable-base stores and slot refs remain unchanged.

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed the aggregate and the two exact split children:

- `entity_query 0x00618380-0x006184e0` reports `TargetOptionEditControlPane` tertiary table at `0x00618384`, `NumericStringControlPane` vtables at `0x00618390`, `0x006183f8`, and `0x00618428`, `RectangleControlPane` vtables at `0x00618434`, `0x0061849c`, and `0x006184cc`, and successor `CheckBoxControlPane` at `0x006184d8`.
- `lookup_funcs` reconfirmed the relevant owner methods and slots: `NumericStringControlPane` constructor/destructor/render/scalar-destructor at `0x00499910`, `0x004999d0`, `0x00499a50`, and `0x0049b2f0`; `RectangleControlPane` constructor/helper/paint/scalar-destructor/HitTestPart at `0x00499c60`, `0x00499ce0`, `0x00499d00`, `0x0049b490`, and `0x0049b8f0`; and all four adjustor thunks at `0x0049af7f`, `0x0049af8a`, `0x0049afc1`, and `0x0049afcc`.
- `trace_data_flow backward` reconfirmed the `NumericStringControlPane` primary/secondary/tertiary vptr-store triads at `0x00499951`/`0x004999fb`/`0x0049b322`, `0x00499957`/`0x00499a01`/`0x0049b328`, and `0x00499961`/`0x00499a0b`/`0x0049b332`.
- `trace_data_flow backward` reconfirmed the `RectangleControlPane` primary/secondary/tertiary vptr-store triads at `0x00499c9f`/`0x00499ce0`/`0x0049b496`, `0x00499ca5`/`0x00499ce6`/`0x0049b49c`, and `0x00499caf`/`0x00499cf0`/`0x0049b4a6`.
- `make_signature_for_range` produced unique byte signatures for `0x0061838c-0x00618430`, `0x00618430-0x006184d4`, and the combined `0x0061838c-0x006184d4` island. `int_convert.py` verified `0xa0` / decimal 160, `0xa4` / decimal 164, `0x68` / decimal 104, `0x30` / decimal 48, `0x0c` / decimal 12, `0x44` / decimal 68, and `0x60` / decimal 96.

## Source-Layout Implication

Both classes are small reusable `ControlPane` derivatives in the same local control-family cluster as [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md) and [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md). Each object installs primary, secondary, and tertiary views at `+0x00`, `+0xa0`, and `+0xa4`; the secondary/tertiary adjustor thunks are compiler glue and should stay excluded from handwritten source reconstruction.

## Parent Attachment Decision

Keep this aggregate page parent-blank and non-reconstructable as a reviewed ownership split. The source-local by-vtable child [UID:0003IR][NumericStringControlPaneVtables](by-type/by-vtable/NumericStringControlPaneVtables.md) routes to [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md), and [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md) routes to [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md). The backing memory children [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md) and [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) also route to those same direct class owners. No single direct parent owns both source slices under the strict `85/85` gate, so this index must not emit or attach as a separate source-level item.

## Cross-References

- [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md)
- [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- [UID:0003IR][NumericStringControlPaneVtables](by-type/by-vtable/NumericStringControlPaneVtables.md)
- [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md)
- [UID:00011M][0x00499910-0x00499be7.NumericStringControlPaneCore](by-memory/0x00499910-0x00499be7.NumericStringControlPaneCore.md)
- [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md)
- [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md)
- [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md)
- [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md)
- [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md)
- [UID:00011Q][0x00499c60-0x00499d37.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d37.RectangleControlPaneCore.md)
- [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## Changes

- 2026-08-16 B006 RectangleControlPane whole-file support correction:
  - Corrected Rectangle primary slot `+0x60` to `HitTestPart(int,int)` and retained fixed result `21` as a part code rather than a type id.
  - Confirmed exact Rectangle child pages [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) and [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md) are compiler-generated, non-reconstructable, and non-emitting; the class declaration and authored method children produce the binary tables. The mixed aggregate remains a parent-blank, non-emitting ownership index.
  - Marked wave-stage metadata as obsolete historical material per current project guidance; it does not override exact binary-backed children.

- 2026-06-12 A004 Batch 331:
  - Before: `COMPLETION:88`, `CONFIDENCE:91`, `RECONSTRUCTABLE:TRUE`, parent blank.
  - After: `COMPLETION:90`, `CONFIDENCE:93`, `RECONSTRUCTABLE:FALSE`, parent remains blank intentionally.
  - Evidence: live IDA MCP reconfirmed both classes' decorated vtable bases, method/slot sizes, constructor/destructor/scalar-destructor vptr-store triads, unique source-local range signatures, and predecessor/successor boundaries. Created exact source-local by-vtable children [UID:0003IR][NumericStringControlPaneVtables](by-type/by-vtable/NumericStringControlPaneVtables.md) and [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md), which carry the reconstructable class routes.
- 2026-06-11 Agent-A006 Batch 147 split-owner refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:90`, parent blank without an explicit reviewed-split decision.
  - After: `COMPLETION:88`, `CONFIDENCE:91`, parent remains blank intentionally.
  - Evidence: live IDA reconfirmed the Rectangle half while repairing [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) through the corrected class parent. The page now records that [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md) and [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) are the exact child routes and that the aggregate itself has no single direct parent.
