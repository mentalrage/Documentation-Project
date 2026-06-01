*** UID:0001YH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProgressBarControlPane Vtables

## Status

- Confidence: strong for table bases, boundaries, and constructor stores.
- Covered class: [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md).
- Likely source file: [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md).
- Exact vtable-data range: [UID:0002OL][0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData](by-memory/0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md).
- Evidence basis: IDA MCP `list_globals`, `xrefs_to`, and `py_eval` checks on 2026-05-26.

## Table Inventory

| View | RTTI pointer | Vtable base | Constructor store | Object offset |
| --- | --- | --- | --- | --- |
| Primary | `0x00617b30` | `0x00617b34` | `0x00494cc5` | `+0x00` |
| Secondary | `0x00617b98` | `0x00617b9c` | `0x00494ccb` | `+0xa0` |
| Tertiary | `0x00617bc8` | `0x00617bcc` | `0x00494cd5` | `+0xa4` |

The `ControlPane` tertiary table ends before `0x00617b30`. The `ProgressBarControlPane` primary table ends before secondary RTTI at `0x00617b98`; the secondary table ends before tertiary RTTI at `0x00617bc8`; the tertiary table has two slots and ends before `ButtonControlPane` RTTI at `0x00617bd4`.

## Key Slots

| Table | Offset | Target | Interpretation |
| --- | --- | --- | --- |
| Primary `0x00617b34` | `+0x00` | `0x0049b170` | Inherited `ControlPane` scalar deleting destructor. |
| Primary `0x00617b34` | `+0x44` | `0x00494de0` | `ProgressBarControlPane::DrawProgressBar`. |
| Primary `0x00617b34` | `+0x48` | `0x00494b80` | Progress-bar/control-family virtual helper in the local control neighborhood. |
| Primary `0x00617b34` | `+0x4c` | `0x00494bb0` | Progress-bar/control-family virtual helper in the local control neighborhood. |
| Primary `0x00617b34` | `+0x50` | `0x00494bd0` | Progress-bar/control-family virtual helper in the local control neighborhood. |
| Primary `0x00617b34` | `+0x54` | `0x00494c00` | Progress-bar/control-family virtual helper in the local control neighborhood. |
| Primary `0x00617b34` | `+0x58` | `0x00494c10` | Progress-bar/control-family virtual helper in the local control neighborhood. |
| Primary `0x00617b34` | `+0x5c` | `0x00494c30` | Progress-bar/control-family virtual helper in the local control neighborhood. |
| Secondary `0x00617b9c` | `+0x00` | `0x0049af3d` | `ControlPane` secondary destructor adjustor thunk. |
| Secondary `0x00617b9c` | `+0x1c` | `0x004a89f0` | Shared secondary-view pane/control support slot. |
| Tertiary `0x00617bcc` | `+0x00` | `0x0049af48` | `ControlPane` tertiary destructor adjustor thunk. |
| Tertiary `0x00617bcc` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

The destructor adjustor thunks are covered by [UID:000120][0x0049af3d-0x0049af52.ControlPaneAdjustorThunks](by-memory/0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md) and should not be reconstructed as handwritten progress-bar methods.

## Evidence Notes

- IDA `list_globals *ProgressBarControlPane*` reports vtable bases at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`, plus matching RTTI records.
- IDA `xrefs_to` the table bases reports constructor stores at `0x00494cc5`, `0x00494ccb`, and `0x00494cd5` inside `ProgressBarControlPane::ProgressBarControlPane` at `0x00494c80`.
- IDA `xrefs_to 0x00494de0` reports only the primary-table data reference at `0x00617b78`, confirming the draw routine is reached virtually.
- IDA MCP `py_eval` on 2026-06-01 confirms the exact [UID:0002OL][0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData](by-memory/0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md) child range: previous `ControlPane` tertiary data ends at `0x00617b30`, primary/secondary/tertiary `ProgressBarControlPane` RTTI and vtable views occupy `0x00617b30-0x00617bd4`, and `0x00617bd4` starts `ButtonControlPane` RTTI.
- Current `class_ProgressBarControlPane.meta_wave3` reports `vtable_count: 0`, so the generated vtable inventory is incomplete.

## Source-Layout Implication

Model `ProgressBarControlPane` as a `ControlPane`-derived reusable UI control with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. The primary table owns the confirmed paint virtual at `+0x44`; adjacent local helpers in the `0x00494b80-0x00494c30` range should stay with the control-family cluster until their exact source names are recovered.

## Cross-References

- [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md)
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:0002OL][0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData](by-memory/0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md)
- [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md)
- [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md)
- [UID:000116][0x00494a90-0x00494b4b.ProgressBarRangeSetters](by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md)
- [UID:000120][0x0049af3d-0x0049af52.ControlPaneAdjustorThunks](by-memory/0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## Changes

- 2026-06-01: Grading changed from validator-header `0/0` to `84/90`, and `RECONSTRUCTABLE` was set to `TRUE`.
  - Before: the page had useful table notes and a stale coverage-row grade, but no exact by-memory child page for the vtable data and no validator-visible score.
  - After: [UID:0002OL][0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData](by-memory/0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md) records the exact primary/secondary/tertiary RTTI/vtable-data range while this page remains the type-level inventory.
  - Evidence: IDA MCP `py_eval` on 2026-06-01 verified the dword layout, neighboring `ControlPane`/`ButtonControlPane` boundaries, constructor vptr-store xrefs, and key slot function boundaries. Completion/confidence remain below `95` because inherited virtual names and final source declarations are not audited to final-source confidence.
