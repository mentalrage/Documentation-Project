*** UID:000006 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AddEmployeeItemDialog

## Status

- Confidence: strong overall for runtime behavior, vtable/layout evidence, and employee-dialog placement; raw constructor-shaped bytes at `0x004a4ae0` remain a non-runtime/no-xref caveat.
- Likely source file: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), with base class in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md), plus disputed constructor at `0x004a4ae0`
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
| Raw constructor-shaped bytes | [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md) | Unreferenced byte island that calls `AddItemDialog`, stores the owner pointer at `+0x270`, and installs vtables; IDA reports no function object or direct xrefs, so runtime construction is the inline `EmployeeDialogPane::OnButtonAction` branch. |
| `OnButtonClick` | `0x004a4b20-0x004a4cb1` | Handles employee item selection/confirmation behavior. |
| AddEmployee adjustor thunks | [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md) | The `0x004a4cb1-0x004a4cc7` subrange contains the two AddEmployee secondary/tertiary destructor adjustor thunks into `0x004a4d00`; later thunks in the aggregate belong to sibling employee dialog classes. |
| `ScalarDeletingDestructor` | `0x004a4d00-0x004a4d3b` | Runs the base picker destructor path and optional free, followed by `CC` padding before the next employee-dialog destructor. |

## Evidence Notes

- Existing employee-dialog and item-dialog documentation identify this as an employee-specific `AddItemDialog` extension.
- 2026-06-06 live IDA MCP `lookup_funcs` confirms `0x004a4b20-0x004a4cb1` for `OnButtonClick`, AddEmployee adjustor thunks at `0x004a4cb1-0x004a4cbc` and `0x004a4cbc-0x004a4cc7`, and scalar deleting destructor `0x004a4d00-0x004a4d3b`; it still reports no function at `0x004a4ae0`.
- The previous IDA function before the projected constructor is `0x004a4a30-0x004a4adb`; the next is `0x004a4b20-0x004a4cb1`.
- `EmployeeDialogPane::OnButtonAction` constructs the add-item picker inline at [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md): it allocates `0x274` bytes, calls `AddItemDialog` at `0x004ae4c0`, patches its vtables to `AddEmployeeItemDialog`, and stores the employee-dialog owner pointer at `+0x270`.
- Live owner-action decompilation shows the runtime branch at `0x004a3381-0x004a33be`: allocate `628` bytes, call `AddItemDialog` with `(0, 0)`, write vtables at `0x004a33a4`, `0x004a33aa`, and `0x004a33b4`, then store `EmployeeDialogPane*` at object slot `+0x270`.
- Live `xrefs_to` for the three AddEmployee vtables reports refs from both the inline runtime branch and the raw constructor-shaped byte island: primary `0x006190d4` from `0x004a33a4` and `0x004a4afe`, secondary `0x00619134` from `0x004a33aa` and `0x004a4b04`, and tertiary `0x00619164` from `0x004a33b4` and `0x004a4b0e`.
- Live `xrefs_to 0x004a4b20` reports the primary vtable action slot at `0x0061911c`, with no static callers, matching virtual dialog dispatch. Live `xrefs_to 0x004a4d00` reports refs from the primary vtable and the two AddEmployee adjustor thunks.
- Live thunk xrefs separate sibling ownership: `0x004a4cb1` is referenced by `0x00619134` and `0x004a4cbc` by `0x00619164` for AddEmployee, while `0x004a4cc7`, `0x004a4cd2`, `0x004a4cdd`, and `0x004a4ce8` are referenced by EmployeeDialogPane and EmployeeItemPropertyDialogPane vtable slots.
- 2026-05-25 raw disassembly shows constructor-shaped bytes at `0x004a4ae0`, but `xrefs_to` still reports no direct xrefs. Treat it as a raw/projection caveat, not a stable IDA-modeled function.
- 2026-05-27 IDA recheck still reports no function/xrefs at `0x004a4ae0`, and a raw-pointer scan across loaded segments found no dword equal to `0x004a4ae0`.
- `AddEmployeeItemDialog::OnButtonClick` calls [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) for stack-like items or dispatches employee command `5` directly.
- Live `OnButtonClick` decompilation shows non-confirm actions forwarding to `AddItemDialog::OnButtonClick` at `0x004ae930`; confirm action fetches picker child selector `3`, rejects multi-select with the employee alert text, clears the owner pending-quantity field at `EmployeeDialogPane+0x420`, tests item metadata byte `+0x1ec`, and either sends employee command `5` through `0x005975e0` with metadata dword `+0x1e8` or opens [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) using localized string id `247`.
- 2026-05-26 action-method recheck: `OnButtonClick` forwards non-confirm button ids to `AddItemDialog::OnButtonClick`, rejects multi-select with [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md) and the shared [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md), resets owner pending quantity at `+0x420`, and then either opens [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) for item records with byte flag `+0x1ec` or dispatches employee command `5` with count/value at item record `+0x1e8`.
- 2026-05-26 IDA MCP confirms `AddEmployeeItemDialog` primary vtable `0x006190d4`, secondary vtable `0x00619134`, and tertiary vtable `0x00619164`. `OnButtonClick` is vtable-referenced at `0x0061911c`; the two destructor adjustor thunks are vtable-referenced at `0x00619134` and `0x00619164`.
- 2026-05-31 IDA MCP confirms the exact vtable data span at [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md), ending before the `EMPLOYEE` UTF-16 string at `0x0061916c` (historical IDA label `aEmployee`).
- 2026-05-26 layout recheck confirms the derived object is allocated as `0x274` bytes on the live path, with the owning `EmployeeDialogPane*` stored at `+0x270`. `OnButtonClick` reads that pointer from `this + 0x270`.

## Score Rationale

The class is scored `82/88` because live IDA evidence now confirms the runtime construction path, exact action/destructor/thunk boundaries, vtable refs, virtual-only dispatch shape, owner offset, selected-row behavior, employee command path, and quantity-dialog dependency. It stays below the final C++ gate because the raw `0x004a4ae0` constructor-shaped bytes remain unreferenced, source-facing row/item metadata field names are not final, and the broader employee item dialog source split still needs final audit.

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
- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)

## Changes

- What existed before: the page had detailed evidence but metadata was still `COMPLETION:0` and `CONFIDENCE:0`, so it appeared as unevaluated in the stats queue.
- What it was changed to: scores were set to `76/82`, and a concise class-shape section was added for layout, vtable, object-size, and final source-placement visibility.
- Summary and evidence: existing IDA MCP notes, inline construction evidence at `0x004a339f`, vtable anchors, and layout docs support a high-confidence class identity while the raw `0x004a4ae0` constructor remains a completion/confidence limiter.
- 2026-05-31 exact vtable child:
  - What existed before: `RECONSTRUCTABLE` was blank and vtable evidence was only summarized through the combined employee vtable type page.
  - What it was changed to: `RECONSTRUCTABLE:TRUE` with a direct exact vtable-data child link.
  - Summary/evidence: IDA MCP `list_globals` and dword scan confirm `0x006190d0-0x0061916c` as the complete `AddEmployeeItemDialog` RTTI/vtable range, ending at the `EMPLOYEE` string (historical IDA label `aEmployee`).
- 2026-06-06 live IDA recheck:
  - What existed before: the page was scored `76/82`, still carried stale provenance wording, and grouped all nearby employee adjustor thunks as if they belonged equally to AddEmployee.
  - What it was changed to: scores were raised to `82/88`, stale provenance wording was removed, the AddEmployee-only thunk subrange was corrected to `0x004a4cb1-0x004a4cc7`, and the page now records the live inline construction path, raw no-xref constructor caveat, action/destructor boundaries, vtable refs, owner offset, selection handling, and quantity/direct-command behavior.
  - Summary/evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, `decompile`, `disasm`, and raw-byte probes confirm the documented class behavior while leaving final C++ blank below the `95/95` gate.
- 2026-06-07 A005 resolved-name cleanup:
  - What existed before: the page preserved only the IDA auto string label `aEmployee` at the vtable/string boundary.
  - What it was changed to: the same boundary now records the resolved source string meaning as `EMPLOYEE` while keeping `aEmployee` as a historical search label.
  - Summary/evidence: the generated resolved-name report maps `aEmployee` to `EMPLOYEE`, and the existing 2026-05-31 vtable evidence already proves the `0x006190d0-0x0061916c` end boundary before that string.
