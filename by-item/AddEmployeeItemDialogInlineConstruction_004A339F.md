*** UID:0000TT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AddEmployeeItemDialogInlineConstruction_004A339F

## Status

- Entity kind: item-level inline construction sequence inside a larger method.
- Owning method: `EmployeeDialogPane::OnButtonAction` at `0x004a3240-0x004a33d7`.
- Instruction span: `0x004a3381-0x004a33be`, with the base constructor call at `0x004a339f`.
- Likely source module: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md).
- Related class: [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md).
- Confidence: strong for live allocation/layout behavior.

## Behavior

When the employee dialog action argument is zero, `EmployeeDialogPane::OnButtonAction` opens the add-item picker. IDA decompilation shows this construction path inline instead of calling the raw projected `0x004a4ae0` constructor.

| Address | Operation |
| --- | --- |
| `0x004a3381` | Allocates `0x274` bytes through `sub_4F4AA0(628)`. |
| `0x004a339f` | Calls generic [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) constructor `0x004ae4c0` with two zero arguments. |
| `0x004a33a4` | Stores primary `AddEmployeeItemDialog` vtable `0x006190d4` at object offset `+0x00`. |
| `0x004a33aa` | Stores secondary vtable `0x00619134` at object offset `+0xa0`. |
| `0x004a33b4` | Stores tertiary vtable `0x00619164` at object offset `+0xa4`. |
| `0x004a33be` | Stores the current `EmployeeDialogPane*` owner at object offset `+0x270`. |

## IDA MCP Evidence

- `decompile 0x004a3240` shows the allocation, base `AddItemDialog` constructor call, three vtable stores, and owner-pointer store in one branch of `EmployeeDialogPane::OnButtonAction`.
- `xrefs_to 0x004ae4c0` reports a code reference at `0x004a339f` from the live construction path.
- `xrefs_to 0x006190d4`, `0x00619134`, and `0x00619164` reports data refs at `0x004a33a4`, `0x004a33aa`, and `0x004a33b4`.
- The raw constructor-shaped bytes at `0x004a4ae0-0x004a4b1f` perform the same base-constructor call, vtable writes, and `+0x270` owner store, but `lookup_funcs 0x004a4ae0` and `xrefs_to 0x004a4ae0` still do not prove a callable function boundary.

## Reconstruction Notes

Model the source-level action as `EmployeeDialogPane` creating an `AddEmployeeItemDialog` for `this`. Do not use this item as a separate handwritten helper. It is a source-map anchor showing that the add-item subclass belongs with the employee dialog module while generic item-picker construction remains in `ItemDialogs`.

The matching raw constructor island remains documented separately because it may represent orphaned, retained, or metadata-disputed code. The live path at `0x004a3381-0x004a33be` is the stronger evidence for runtime construction.

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)
- [UID:0001TN][AddEmployeeItemDialogLayout](by-type/by-struct/AddEmployeeItemDialogLayout.md)
- [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md)
- [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented the live inline construction sequence, vtable stores, raw-constructor caveat, and reconstruction notes but remained unevaluated.
  - After: score reflects documented allocation, base constructor call, three vtable writes, owner-pointer store, stronger live-path evidence, and source-map role.
  - Evidence: IDA notes confirm `EmployeeDialogPane::OnButtonAction` decompile, xrefs to base constructor and vtables, and lack of proven callable boundary for the raw constructor-shaped bytes.
