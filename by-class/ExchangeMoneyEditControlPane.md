*** UID:00004T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ExchangeMoneyEditControlPane

## Status

- Likely source file: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Address range: [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md); false generated method start [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- Current recovered file: `source-3/simroot_v2/class_ExchangeMoneyEditControlPane.cpp`
- Confidence: strong for role; strong that `0x00430058` is not an ExchangeMoney method.

## Class Purpose

`ExchangeMoneyEditControlPane` is the numeric edit control used for the local money amount in `ExchangeDialog`. It accepts only digit key events, forwards accepted input through the text-edit hide/commit path, and reports itself editable.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetClassName` | [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) | False Wave3-modeled method. IDA says this is an internal branch target inside `sub_430040`, not a valid callable method start. |
| `ScalarDeletingDestructor` | `0x004b0a60-0x004b0ab4` | Restores vtable pointers, chains through text-edit control teardown, and optionally frees storage. |
| `AdjustorThunks` | [UID:00014Y][0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks](by-memory/0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks.md) | Compiler-generated `-0xa0` and `-0xa4` destructor adjustor thunks. |
| `OnKeyEvent` | `0x004b0b60-0x004b0b95` | Returns true for digit key events and forwards the accepted event through the text-edit commit/hide behavior. |
| `IsEditable` | `0x004b0ba0-0x004b0ba4` | Returns true. |

## Evidence Notes

- `ExchangeDialog` constructs this control at rectangle `73,295,197,307` and assigns it control id `6`.
- `ExchangeDialog::OnKeyEvent` and `ExchangeDialog::OnControlFocusChange` read the control text, parse it with `_wtol`, normalize non-positive values to zero, and submit the amount.
- Current Wave3 emitted score for this class is low because of missing base type names (`TextEditControlPane`, `WideString`) and synthetic layout artifacts; the behavior is still useful.
- IDA MCP recheck on 2026-05-26 shows apparent data xrefs to `0x00430058` are false dword interpretations inside wide resource strings such as `DLGE1.PAL` and `DLGE2.PEF`, not ExchangeMoney vtable entries.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: money edit-control role, destructor/thunks/key/editable methods, control id and ExchangeDialog amount flow, and false `GetClassName`/string-fragment evidence are documented; remaining work is mostly base type/source polish.
