*** UID:000006 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AddEmployeeItemDialog

## Status

- Confidence: medium overall: strong for action behavior, vtable/layout evidence, and employee-dialog placement; projected constructor `0x004a4ae0` remains non-IDA/raw with no proven reachability.
- Likely source file: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), with base class in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md), plus disputed constructor at `0x004a4ae0`
- Current recovered file: `source-3/simroot_v2/class_AddEmployeeItemDialog.cpp`
- Type docs: [UID:0001TN][AddEmployeeItemDialogLayout](by-type/by-struct/AddEmployeeItemDialogLayout.md), [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- Exact vtable data: [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md)
- Autogen parent: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), matching the employee-specific owner and keeping the generic item picker base in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).

## Class Purpose

`AddEmployeeItemDialog` is an employee-specific `AddItemDialog` variant used by `EmployeeDialogPane` when adding an inventory item to an employee shop flow. It reuses the generic item picker but routes confirmation through employee command/quantity logic.

## Class Shape

- Base behavior: reuses `AddItemDialog` construction and item-list selection behavior.
- Derived state: stores the owning `EmployeeDialogPane*` at object offset `+0x270`.
- Object size: confirmed live allocation size is `0x274`.
- Vtable family: primary `0x006190d4`, secondary `0x00619134`, tertiary `0x00619164`.
- Source placement: final implementation should migrate with [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), while the reused base picker remains in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AddEmployeeItemDialog` | [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md) | Wave3-projected constructor range. Raw constructor-shaped bytes call `AddItemDialog`, store owner pointer at `+0x270`, and install vtables, but IDA MCP reports no function or xrefs at this address. |
| `OnButtonClick` | `0x004a4b20-0x004a4cb0` | Handles employee item selection/confirmation behavior. |
| Adjustor thunks | [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md) | Secondary/tertiary destructor adjustor thunks into `0x004a4d00`; compiler-generated. |
| `ScalarDeletingDestructor` | `0x004a4d00-0x004a4d3a` | Runs destructor path and optional free. |

## Evidence Notes

- Wave3 summary identifies this as an employee-specific `AddItemDialog` extension.
- IDA MCP confirms `0x004a4b20`, thunks around `0x004a4cc7-0x004a4cd2`, and `0x004a4d00`; it reports no function at `0x004a4ae0`.
- The previous IDA function before the projected constructor is `0x004a4a30-0x004a4adb`; the next is `0x004a4b20-0x004a4cb1`.
- `EmployeeDialogPane::OnButtonAction` constructs the add-item picker inline at [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md): it allocates `0x274` bytes, calls `AddItemDialog` at `0x004ae4c0`, patches its vtables to `AddEmployeeItemDialog`, and stores the employee-dialog owner pointer at `+0x270`.
- 2026-05-25 raw disassembly shows constructor-shaped bytes at `0x004a4ae0`, but `xrefs_to` still reports no direct xrefs. Treat it as a raw/projection caveat, not a stable IDA-modeled function.
- 2026-05-27 IDA recheck still reports no function/xrefs at `0x004a4ae0`, and a raw-pointer scan across loaded segments found no dword equal to `0x004a4ae0`.
- `AddEmployeeItemDialog::OnButtonClick` calls [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) for stack-like items or dispatches employee command `5` directly.
- 2026-05-26 action-method recheck: `OnButtonClick` forwards non-confirm button ids to `AddItemDialog::OnButtonClick`, rejects multi-select with [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md) and the shared [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md), resets owner pending quantity at `+0x420`, and then either opens [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) for item records with byte flag `+0x1ec` or dispatches employee command `5` with count/value at item record `+0x1e8`.
- 2026-05-26 IDA MCP confirms `AddEmployeeItemDialog` primary vtable `0x006190d4`, secondary vtable `0x00619134`, and tertiary vtable `0x00619164`. `OnButtonClick` is vtable-referenced at `0x0061911c`; the two destructor adjustor thunks are vtable-referenced at `0x00619134` and `0x00619164`.
- 2026-05-31 IDA MCP confirms the exact vtable data span at [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md), ending before the `aEmployee` string at `0x0061916c`.
- 2026-05-26 layout recheck confirms the derived object is allocated as `0x274` bytes on the live path, with the owning `EmployeeDialogPane*` stored at `+0x270`. `OnButtonClick` reads that pointer from `this + 0x270`.

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md)
- [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md)
- [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md)
- [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md)
- [UID:0001TN][AddEmployeeItemDialogLayout](by-type/by-struct/AddEmployeeItemDialogLayout.md)
- [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md)
- [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md)
- [wave3_data_issues](../wave3_data_issues.md)
- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)

## Changes

- What existed before: the page had detailed evidence but metadata was still `COMPLETION:0` and `CONFIDENCE:0`, so it appeared as unevaluated in the stats queue.
- What it was changed to: scores were set to `76/82`, and a concise class-shape section was added for layout, vtable, object-size, and final source-placement visibility.
- Summary and evidence: existing IDA MCP notes, inline construction evidence at `0x004a339f`, vtable anchors, and layout docs support a high-confidence class identity while the raw `0x004a4ae0` constructor remains a completion/confidence limiter.
- 2026-05-31 exact vtable child:
  - What existed before: `RECONSTRUCTABLE` was blank and vtable evidence was only summarized through the combined employee vtable type page.
  - What it was changed to: `RECONSTRUCTABLE:TRUE` with a direct exact vtable-data child link.
  - Summary/evidence: IDA MCP `list_globals` and dword scan confirm `0x006190d0-0x0061916c` as the complete `AddEmployeeItemDialog` RTTI/vtable range, ending at the `aEmployee` string.
