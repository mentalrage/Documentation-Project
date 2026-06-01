*** UID:0001UC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EmployeeQuantityInputDialogPane Layout

## Status

- Entity kind: derived dialog layout.
- Covered class: [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md).
- Likely owner source: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md).
- Confidence: strong for vtable views, parent pointer, and employee index byte; medium for final padding and base `DialogPane` tail size.

## Layout Hypothesis

`EmployeeQuantityInputDialogPane` is a small `DialogPane`-derived modal prompt. It stores the owning employee dialog pointer and the selected employee/item index after the inherited dialog state.

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Constructor stores `0x00619038` at `0x004a47cc`; primary slot `+0x48` points to `0x004a4a30`. |
| `+0xa0` | 4 | secondary dialog/input vtable view | Constructor stores `0x00619098` at `0x004a47d2`; slot `+0x00` uses adjustor thunk `0x0047e8d9`. |
| `+0xa4` | 4 | tertiary event/update vtable view | Constructor stores `0x006190c8` at `0x004a47dc`; slot `+0x00` uses adjustor thunk `0x0047e8e4`. |
| `+0x26c` | 4 | `EmployeeDialogPane* owner` | Constructor stores the caller parent pointer at `0x004a49b7`; `OnAction` reads it before sending employee command `5`. |
| `+0x270` | 1 | employee/item index byte | Constructor stores the byte argument at `0x004a49c7`; `OnAction` forwards it to the employee command helper. |

The live allocation size is not confirmed directly on this page. The generated Ghidra struct reports padding through `+0x273`, which is plausible for a `0x274`-byte allocation-aligned dialog object, but reconstruction should use the field evidence above rather than every generated undefined byte.

## IDA MCP Evidence

- `lookup_funcs` confirms constructor `0x004a4770` size `0x2b5` and `OnAction` `0x004a4a30` size `0xab`.
- `xrefs_to 0x00619038`, `0x00619098`, and `0x006190c8` reports constructor stores at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`.
- `xrefs_to 0x004a4770` reports construction from the employee inventory helper `0x004a2450`, main employee dialog action handler `0x004a3240`, and `AddEmployeeItemDialog::OnButtonClick` `0x004a4b20`.
- `xrefs_to 0x004a4a30` reports the primary vtable data reference at `0x00619080`, which is primary slot `+0x48`.
- Constructor decompilation stores the owner pointer at `+0x26c` and the index byte at `+0x270`.
- `OnAction` reads text-edit control id `4`, parses the text as an integer quantity, calls the employee command helper on `owner + 0xa4`, passes command id `5`, and closes the dialog for button ids `1` and `2`.

## Generated-Data Caveat

Current `source-3/simroot_v2/class_EmployeeQuantityInputDialogPane.meta_wave3` reports `vtable_count: 0` even though IDA confirms all three vtable bases. It also records a constructor method name with a trailing carriage-return/control character in the generated metadata. Treat those as Wave3 data issues, not source facts.

## Cross-References

- [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md)
- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md)
- [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)
- [UID:0000UL][EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md)

## Changes

- 2026-05-31 completion/reconstruction metadata:
  - What existed before: metadata remained unevaluated at `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank despite detailed layout notes.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`; exact constructor/action memory pages were added to cross-references.
  - Summary/evidence: live IDA MCP recheck confirms constructor size/callers, vtable stores, owner pointer at `+0x26c`, selected index byte at `+0x270`, action handler use of control id `4`, and employee command `5` dispatch.
