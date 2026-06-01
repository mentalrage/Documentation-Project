*** UID:0001YA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NumericStringControlPane And RectangleControlPane Vtables

## Status

- Confidence: strong for table bases, constructor/destructor stores, key slots, and adjacent-table boundaries.
- Covered classes: [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md) and [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md).
- Likely source files: [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md) and [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md).
- Exact vtable-data children: [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md) and [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md).
- Evidence basis: IDA MCP `list_globals`, `xrefs_to`, and `py_eval` checks on 2026-05-26 and 2026-06-01.

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
| Primary `0x00618434` | `+0x60` | `0x0049b8f0` | Returns fixed control type id `21`. |
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
- Current `class_NumericStringControlPane.meta_wave3` and `class_RectangleControlPane.meta_wave3` both report `vtable_count: 0`, so generated metadata currently omits these confirmed vtable inventories.

## 2026-06-01 IDA Recheck

- IDA MCP `py_eval` rechecked the `.rdata` island from `0x00618380-0x006184e0`. It reports decorated vtable globals for `NumericStringControlPane` at `0x00618390`, `0x006183f8`, and `0x00618428`, and for `RectangleControlPane` at `0x00618434`, `0x0061849c`, and `0x006184cc`.
- Complete-object-locator dwords were verified at `0x0061838c`, `0x006183f4`, `0x00618424`, `0x00618430`, `0x00618498`, and `0x006184c8`. The scan shows the previous `TargetOptionEditControlPane` tertiary table ending at `0x00618388` and the next `CheckBoxControlPane` primary RTTI pointer at `0x006184d4`.
- IDA xrefs to all six vtable bases confirm the constructor/destructor stores already listed in the tables. Slot xrefs confirm `0x00499a50` at `0x006183d4`, `0x00499d00` at `0x00618478`, and `0x0049b8f0` at `0x00618494`.
- The exact child pages split this formerly aggregate-only evidence into [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md) and [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md).

## Source-Layout Implication

Both classes are small reusable `ControlPane` derivatives in the same local control-family cluster as [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md) and [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md). Each object installs primary, secondary, and tertiary views at `+0x00`, `+0xa0`, and `+0xa4`; the secondary/tertiary adjustor thunks are compiler glue and should stay excluded from handwritten source reconstruction.

## Cross-References

- [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md)
- [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- [UID:0002OD][0x0061838c-0x00618430.NumericStringControlPaneVtableData](by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md)
- [UID:00011M][0x00499910-0x00499be6.NumericStringControlPaneCore](by-memory/0x00499910-0x00499be6.NumericStringControlPaneCore.md)
- [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md)
- [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md)
- [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md)
- [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md)
- [UID:00011Q][0x00499c60-0x00499d36.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d36.RectangleControlPaneCore.md)
- [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
