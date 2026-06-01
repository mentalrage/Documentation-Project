*** UID:000021 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CheckBoxControlPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md), or folded into [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Core memory: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- Exact core memory: [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- Adjustor thunks: [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md)
- Exact vtable data: [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md)
- Current recovered file: `source-3/simroot_v2/class_CheckBoxControlPane.cpp`
- Type/layout docs: [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md), [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)

## Class Purpose

`CheckBoxControlPane` is a toggleable checkbox control. It stores checked state, toggles on mouse input when hit-tested, notifies the owner pane after changes, and paints checked/unchecked EPF tile frames using a tile name plus palette name pair.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CheckBoxControlPane` | `0x00499d40-0x00499db8` | Constructs checkbox state from tile/label names and checked/unchecked frame ids. |
| `SetChecked` / `GetChecked` | `0x00499dc0-0x00499dd6` | Sets or reads checked-state byte. |
| `OnMouse` | `0x00499de0-0x00499e2c` | Toggles on button-3 click hit and notifies owner. |
| `OnPaint` | `0x00499e30-0x00499ebf` | Draws checked or unchecked EPF tile frame. |
| [UID:0000U7][CheckBoxControlPaneStateTypeHelper_00499EC0](by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md) | `0x00499ec0-0x00499f0d` | Compares a control-state byte, special-cases type id `20`, and refreshes on change; active generated output currently omits this method. |
| `GetControlTypeId` | `0x0049b8d0-0x0049b8d4` | Returns control type id `20`. |

## Evidence Notes

- IDA MCP reports 3 direct constructor xrefs.
- 2026-05-26 IDA MCP recheck confirms `0x00499ec0` as a real 0x4e-byte function referenced only from primary vtable slot `0x00618520`; active generated output still omits it.
- 2026-05-31 IDA MCP recheck confirms the exact vtable-data range [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md), including constructor/destructor stores for all three table bases and the boundary before `SimpleHelpTextPartPane@StaticTextControlPane2`.
- 2026-05-26 IDA MCP recheck confirms `0x0049af27` and `0x0049af32` as 0xb-byte compiler adjustor thunks into scalar deleting destructor `0x0049b110`; these are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-25 IDA MCP caller checks identify two constructor calls from [UID:0000LE][MiniMap](by-file/MiniMap.md) and one from [UID:000096][NewMailDialog](by-class/NewMailDialog.md). `SetChecked` is MiniMapDialog-only in current evidence, while `GetChecked` is read by `NewMailDialog::SendMail`.
- Confirmed callers pass `L"ONOFFBUT.EPF"` and `L"BUTTON.PAL"`, so the second string field is a palette/resource name, not a visible label.
- Wave3 effective grade is 97.4 and the class has no memory conflicts.

## Cross-References

- [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md)
- [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md)
- [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)
- [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0000U7][CheckBoxControlPaneStateTypeHelper_00499EC0](by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md)
- [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)

## Changes

- What existed before: the page had detailed constructor/state/mouse/paint/helper/destructor evidence, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `84/90`.
- Summary and evidence: layout, vtables, exact memory, omitted helper, caller evidence, resource names, and control type id are documented; remaining work is mainly final source-file split and exact field names.

- 2026-05-31: Grading changed from `84/90` to `86/91`, and `RECONSTRUCTABLE` was set to `TRUE`.
  - Before: the class page referenced vtable evidence but did not link an exact by-memory vtable-data child.
  - After: the class page links [UID:0002M9][0x006184d8-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md) as the exact vtable-data range.
  - Evidence: IDA MCP `list_globals`, `lookup_funcs`, and `py_eval` on 2026-05-31 reconfirmed the three table bases, slot targets, constructor/destructor vptr stores, and next-class boundary.
