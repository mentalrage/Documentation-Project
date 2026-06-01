*** UID:0001TN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AddEmployeeItemDialog Layout

## Status

- Entity kind: derived dialog layout.
- Covered class: [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md).
- Likely owner source: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), with base picker layout inherited from [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- Confidence: strong for derived vtable views and employee-owner pointer; low for treating `0x004a4ae0` as a callable constructor boundary.
- Reconstructable: yes, as source-level class/layout information. Do not emit C++ from this type page until the real constructor boundary and `AddItemDialog` base declaration are fully resolved.

## Layout Hypothesis

`AddEmployeeItemDialog` is an employee-specific `AddItemDialog` variant. The base item-picker object occupies the first `0x270` bytes; the derived class adds one owner pointer at `+0x270`. Live [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md) allocates `0x274` bytes.

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Raw constructor-shaped bytes store `0x006190d4`; live `EmployeeDialogPane::OnButtonAction` stores the same table at `0x004a33a4`. |
| `+0xa0` | 4 | secondary dialog/input vtable view | Raw bytes store `0x00619134`; live construction stores it at `0x004a33aa`. |
| `+0xa4` | 4 | tertiary event/update vtable view | Raw bytes store `0x00619164`; live construction stores it at `0x004a33b4`. |
| `+0x270` | 4 | `EmployeeDialogPane* owner` | Raw bytes store the constructor argument at `0x004a4af6`; live construction stores the current `EmployeeDialogPane` pointer at `0x004a33be`; `OnButtonClick` reads it at `0x004a4be6`. |

## IDA MCP Evidence

- `lookup_funcs` confirms `0x004a4b20` as a real `0x191`-byte method and `0x004a3240` as the live employee dialog button/action handler. It reports `0x004a4ae0` as `Not a function`.
- `xrefs_to` the three vtable bases reports live stores in `EmployeeDialogPane::OnButtonAction` at `0x004a33a4`, `0x004a33aa`, and `0x004a33b4`, plus raw non-function stores at `0x004a4afe`, `0x004a4b04`, and `0x004a4b0e`.
- Raw disassembly from `0x004a4ae0-0x004a4b1f` calls `AddItemDialog` at `0x004ae4c0`, stores `[esi+0x270] = [ebp+8]`, installs the three `AddEmployeeItemDialog` vtables, and returns with `retn 4`.
- IDA decompilation of `0x004a3240` shows the live path allocating `0x274` bytes, calling `AddItemDialog(0,0)`, patching the same three vtables, and storing the current `EmployeeDialogPane` pointer at dword index `156` (`+0x270`).
- IDA decompilation of `0x004a4b20` reads `*(this + 0x270)` before clearing owner field `+0x420`, opening `EmployeeQuantityInputDialogPane`, or sending employee command `5`.
- 2026-05-31 IDA MCP recheck confirms `0x004a4ae0` is still not an IDA function, but raw disassembly from `0x004a4ae0-0x004a4b1f` performs the constructor-shaped sequence: calls `0x004ae4c0`, writes `[esi+0x270] = [ebp+8]`, installs vtables at `+0x00`, `+0xa0`, and `+0xa4`, then returns with `retn 4`.
- 2026-05-31 IDA MCP recheck of `0x004a3240` confirms live allocation size `0x274`, base `AddItemDialog` construction through `0x004ae4c0`, and `0x274`-byte derived object setup in the employee dialog action path.
- 2026-05-31 IDA MCP recheck of `0x004a4b20` confirms constants `0x270`, `0x1ec`, and `0x1e8` are used in the selected-item/owner-driven button path.
- The same method uses the selected item record's byte flag at `+0x1ec` to choose the quantity dialog path and the dword at `+0x1e8` as the direct-dispatch count/value when no quantity prompt is required. These item-record offsets are owned by the inventory/item metadata, not by `AddEmployeeItemDialog`.
- Current Wave3 metadata reports `vtable_count: 0` for `AddEmployeeItemDialog`, so the generated class inventory omits the real table bases even though active source names placeholder vtables.

## Reconstruction Notes

In source, model this as a small derived class over `AddItemDialog` with one extra `EmployeeDialogPane*` member. The live construction evidence favors expressing creation inside `EmployeeDialogPane::OnButtonAction` as a normal derived allocation/constructor, while preserving the raw `0x004a4ae0` bytes as a projected constructor island until function-boundary metadata is reconciled.

The three destructor adjustor thunks at `0x004a4cb1` and `0x004a4cbc` are compiler glue. They should remain documented as ABI evidence, not handwritten source methods.

## Open Questions

- Whether the original source had an out-of-line constructor corresponding to the raw `0x004a4ae0` bytes, or whether the only source-level construction was inlined into `EmployeeDialogPane::OnButtonAction`.
- Final owner split between `EmployeeDialogPane` and the base item-dialog source remains open until the neighboring item-dialog layouts are audited.

## Cross-References

- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)
- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md)
- [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md)
- [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)
- [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md)
