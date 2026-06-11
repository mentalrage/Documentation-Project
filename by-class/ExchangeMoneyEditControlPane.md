*** UID:00004T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ExchangeMoneyEditControlPane

## Status

- Likely source file: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Address range: [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md); exact helper children [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md) and [UID:000341][0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler](by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md); false generated method start [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- Current recovered file: `source-3/simroot_v2/class_ExchangeMoneyEditControlPane.cpp`
- Autogen parent: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md); final C++ remains blank because base-class slot names, event field names, and the standalone vtable-data split are not yet final-source quality.
- Confidence: strong for role, method boundaries, and `ExchangeDialog.cpp` ownership; strong that `0x00430058` is not an ExchangeMoney method.

## Class Purpose

`ExchangeMoneyEditControlPane` is the numeric edit control used for the local money amount in `ExchangeDialog`. It accepts only digit key events, forwards accepted input through the text-edit hide/commit path, and reports itself editable.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetClassName` | [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) | False Wave3-modeled method. IDA says this is an internal branch target inside `sub_430040`, not a valid callable method start. |
| `ScalarDeletingDestructor` | [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md) row `0x004b0a60-0x004b0ab5` | Compiler-generated wrapper that restores vtable pointers, chains through text-edit control teardown, and optionally frees storage. |
| `AdjustorThunks` | [UID:00014Y][0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks](by-memory/0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks.md) | Compiler-generated `-0xa0` and `-0xa4` destructor adjustor thunks. |
| activation/state helper | [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md) | Vtable-reached wrapper that calls the embedded text-edit state helper with `1,1` and tail-jumps to the shared control activation/invalidation helper. |
| `OnKeyEvent` | [UID:000341][0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler](by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md) | Returns true for digit key events and forwards accepted input through the text-edit commit/hide behavior. |
| shared return-true slot | [UID:000342][0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper](by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md) | The `ExchangeMoneyEditControlPane` vtable points at this trivial true predicate, but IDA also shows `MapRefreshDimmer`, `ScreenDimmer`, and `InputBlockerPane` vtables using the same body, so it is not assigned to this class. |

## Vtable And Boundary Notes

- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md) records the current IDA-backed class tail boundaries: scalar deleting destructor `0x004b0a60-0x004b0ab5`, adjustor thunk strip `0x004b0ab5-0x004b0acb`, activation helper `0x004b0b40-0x004b0b54`, key handler `0x004b0b60-0x004b0b96`, and shared return-true helper `0x004b0ba0-0x004b0ba5`.
- The same tail pass records the relevant vtable-data cells: destructor slot `0x0061a264`, primary-table activation slot `0x0061a2c0`, adjustor thunk slots `0x0061a2cc` and `0x0061a2fc`, shared return-true slot `0x0061a2d0`, and key-handler slot `0x0061a2d4`.
- The exact `ExchangeMoneyEditControlPane` vtable-data island is still not split into its own by-memory page; it is currently documented through the broader [UID:00025A][0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData](by-memory/0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData.md) aggregate and the adjacent [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md) boundary at `0x0061a260`.
- Parent attachment to `ExchangeDialog` is justified because this class and the file page both clear the corrected `85/85` gate, and the file page groups `ExchangeDialog`, `ExchangeItemListPane`, `ExchangeMoneyEditControlPane`, and `ExchangeAlertPane` as private pieces of the exchange dialog feature.

## Evidence Notes

- `ExchangeDialog` constructs this control at rectangle `73,295,197,307` and assigns it control id `6`.
- `ExchangeDialog::OnKeyEvent` and `ExchangeDialog::OnControlFocusChange` read the control text, parse it with `_wtol`, normalize non-positive values to zero, and submit the amount.
- Current Wave3 emitted score for this class is low because of missing base type names (`TextEditControlPane`, `WideString`) and synthetic layout artifacts; the behavior is still useful.
- IDA MCP recheck on 2026-05-26 shows apparent data xrefs to `0x00430058` are false dword interpretations inside wide resource strings such as `DLGE1.PAL` and `DLGE2.PEF`, not ExchangeMoney vtable entries.
- 2026-06-10 B001-027 IDA MCP recheck confirms `0x004b0b40-0x004b0b54` has only the `0x0061a2c0` vtable/data ref and calls `0x00498c00(this, 1, 1)` before tail-jumping to `0x00494c30`.
- 2026-06-10 B001-027 IDA MCP recheck confirms `0x004b0b60-0x004b0b96` has vtable/data ref `0x0061a2d4`, accepts only event byte `+4 == 10`, byte `+9 == 1`, and UTF-16 digit code `0x30-0x39`, then calls `0x00498d90`.
- 2026-06-10 B001-027 IDA MCP recheck confirms `0x004b0ba0-0x004b0ba5` returns true but has additional non-exchange vtable refs from `MapRefreshDimmer`, `ScreenDimmer`, and `InputBlockerPane`, so this page records it as a consumed shared helper rather than a direct child assignment.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)
- [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md)
- [UID:000341][0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler](by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md)
- [UID:000342][0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper](by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: money edit-control role, destructor/thunks/key/editable methods, control id and ExchangeDialog amount flow, and false `GetClassName`/string-fragment evidence are documented; remaining work is mostly base type/source polish.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving this confirmed exchange money input control unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `76/84`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP confirms real method starts at `0x004b0a60`, `0x004b0b60`, and `0x004b0ba0`, while `0x00430058` remains an interior address of `sub_430040` rather than an ExchangeMoney method start.
- 2026-06-07: Attached to `ExchangeDialog.cpp` and raised class scores to `82/86`.
  - Before: parent was blank and the page did not record the later ExchangeDialog-tail vtable/data slot pass.
  - After: set `AUTOGEN_PARENT_UID:0000J9`, added boundary/vtable notes, and kept final C++ blank.
  - Summary/evidence: [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md) now records IDA-backed method boundaries, money-edit vtable slots, adjustor thunk linkage, padding boundaries, and the next `FieldMapPane` boundary, while [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) is a validated 86/80 source root for the exchange dialog feature.
- 2026-06-10 B001-027 parent gate repair:
  - Before: `82/86`; exact money-edit helper rows inside [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md) could not be assigned under the corrected `85/85` direct-parent gate.
  - After: `85/88`; exact children [UID:000340][0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md) and [UID:000341][0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler](by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md) attach to this class. [UID:000342][0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper](by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md) stays parent-blank because IDA proves multiple non-exchange vtables reuse that tiny helper.
  - Summary/evidence: live IDA confirms activation/key-handler exact ranges, `0x0061a2c0`/`0x0061a2d4` vtable refs, callee behavior through TextEditControlPane/control-family helpers, digit-key filtering behavior, and the shared-helper negative evidence for `0x004b0ba0`.
