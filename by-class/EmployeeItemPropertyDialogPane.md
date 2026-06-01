*** UID:00004D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EmployeeItemPropertyDialogPane

## Status

- Confidence: strong for constructor/action behavior and source placement; medium for destructor base label.
- Likely source file: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- Address range: [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- Current recovered file: `source-3/simroot_v2/class_EmployeeItemPropertyDialogPane.cpp`
- Type docs: [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md), [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- Exact vtable data: [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md)

## Class Purpose

`EmployeeItemPropertyDialogPane` is the employee item property/price dialog opened from an item slot in `EmployeeDialogPane`. It displays the selected item sprite/name/price, lets the user edit the price, and sends employee commands back through the owning employee dialog.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0002HE][0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor](by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md) | `EmployeeItemPropertyDialogPane` | Builds the `Property` dialog, stores parent/item pointers, creates OK/cancel/close buttons, price edit, labels, and item icon rect. |
| [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md) | `OnPaint` | Draws `SELLITEM.EPF`/`SELLITEM.PAL` and renders the selected item sprite. |
| [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md) | `OnCommand` | On OK, reads edited price and sends employee command `2`; on alternate action, sends command `3`; closes on cancel/close. |
| `0x004a4cdd-0x004a4cf2` | adjustor thunks | Disabled/currently uneven Wave3 thunk coverage into the scalar deleting destructor. |
| `0x004a4e30-0x004a4e6a` | scalar deleting destructor | Deleting destructor wrapper; current generated base label is polluted. |

## Evidence Notes

- IDA MCP confirms the constructor, paint, command, thunk, and destructor starts.
- `xrefs_to 0x004a41c0` reports construction from `EmployeeDialogPane::OnButtonAction` at `0x004a3319`.
- 2026-05-31 IDA MCP confirms the exact vtable data span at [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md), ending before `EmployeeQuantityInputDialogPane` RTTI at `0x00619034`.
- `EmployeeDialogPane::OnButtonAction` allocates `0x284` bytes for this dialog before calling `0x004a41c0`.
- IDA layout evidence places the parent `EmployeeDialogPane*` at `+0x26c`, the item icon rectangle at `+0x270-+0x27f`, and the selected `EmployeeRecord*` at `+0x280`; see [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md).
- Decompilation of `0x004a4660` reads text edit control id `3`, parses the price with `g_szPriceFormat`, stores pending edit state in the parent, then dispatches employee command `2`.
- Current generated destructor calls `TransferReplyAlert::~DialogPane`; treat this as base-owner pollution until the real `DialogPane` teardown helper is named.
- 2026-05-25 IDA decompilation of `0x004a4e30` is also type-polluted, currently rendering the base teardown as `boost::exception::~exception`. Use the class/memory ownership docs rather than either polluted base label.
- 2026-05-26 IDA MCP vtable pass confirms primary vtable `0x00618f9c`, secondary vtable `0x00618ffc`, and tertiary vtable `0x0061902c`; the adjustor thunks at `0x004a4cdd` and `0x004a4ce8` are compiler-generated and now tracked as ignored memory.

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md)
- [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md)
- [UID:0002HE][0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor](by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md)
- [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md)
- [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md)
- [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/80`.
  - Summary/evidence: property dialog role, constructor/paint/action/destructor ranges, parent/item layout, command dispatch, vtables, and polluted destructor label caveats are documented; remaining uncertainty is final destructor-base naming and source-facing fields.
- 2026-05-31 reconstructable flag and exact method links:
  - Before: `RECONSTRUCTABLE:` was blank and method rows used raw address spans.
  - After: `RECONSTRUCTABLE:TRUE` and constructor/paint/command rows link to exact by-memory pages.
  - Summary/evidence: live IDA MCP recheck confirms method sizes, vtable references, parent/record fields, and command dispatch behavior for the three exact methods.
