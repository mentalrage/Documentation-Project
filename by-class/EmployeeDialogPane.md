*** UID:00004C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EmployeeDialogPane

## Status

- Confidence: strong for class role and IDA-confirmed method anchors; medium for omitted/raw helper modeling.
- Likely source file: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- Address range: [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- Current recovered file: `source-3/simroot_v2/class_EmployeeDialogPane.cpp`
- Type docs: [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md), [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- Exact vtable data: [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md)

## Class Purpose

`EmployeeDialogPane` is the main employee shop/management dialog. It owns the employee record array, selected visible item slots, item tooltip/status drawing, employee command packets, and response packet handling for adding/removing/updating employee shop entries.

## Method Map

| Address | Method or helper | Role |
| --- | --- | --- |
| `0x004a1d70-0x004a22ee` | `EmployeeDialogPane` | Builds the `Employee` dialog, initializes up to 10 visible employee slots, parses optional initial packet data, and sends the initial opcode `0x54` request. |
| `0x004a22f0-0x004a23a7` | non-deleting destructor | Frees the employee record buffer, sends close notification, and tears down `DialogPane`. |
| `0x004a2450-0x004a2530` | inventory item helper | Opens quantity input for stack-like items or sends command `5` directly. Omitted from active Wave3 output. |
| `0x004a2560-0x004a2a50` | `OnPaint` | Draws the seller background, employee name, gold/count/status text, item icons, and tooltip text. |
| `0x004a2a60-0x004a2c77` | `OnMouseInput` | Hit-tests the 10 item icon rects and builds tooltip strings. |
| `0x004a2c80-0x004a2f5c` | `SendCommand` | Sends opcode `0x54` employee subcommands for hire, quantity, transfer, remove, close, and fitting-room actions. |
| `0x004a2f60-0x004a322b` | packet dispatcher | Handles employee response packets. Omitted from active Wave3 output but IDA-confirmed. |
| `0x004a3240-0x004a33d7` | `OnButtonAction` | Opens quantity/property/add-item dialogs, fitting room, or closes the dialog. |
| `0x004a33e0-0x004a34ca` | `RebuildSelectionList` | Recomputes the 10 visible employee slots and scroll-button state. |
| [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) | `DeserializeEmployeeRecord` | File-local or recovered helper that parses one `EmployeeRecord`. |
| `0x004a3a90-0x004a3bde` | `LoadEmployeeData` | Parses the full employee list packet and allocates the record array. |
| `0x004a3be0-0x004a3c9f` | `UpdateEmployeeRecord` | Wave3/raw helper that updates or inserts one record; IDA currently does not define this as a function. |
| `0x004a3e10-0x004a4056` | `UpdateEmployeeFields` | Applies renamed/status/field updates to one existing record. |
| `0x004a4cc7-0x004a4cdc` | destructor adjustor thunks | Thin this-adjustor thunks into `0x004a4d40`. |
| `0x004a4d40-0x004a4e26` | scalar deleting destructor | Full deleting destructor wrapper. |

## Evidence Notes

- Wave3 class notes identify a 2804-byte dialog with a 1052-byte `EmployeeRecord` stride and opcode `0x54` command family.
- IDA MCP confirms all method starts above except raw/projected `0x004a3be0`; disassembly still shows a complete prologue/body there.
- IDA confirms omitted helpers `0x004a2450` and `0x004a2f60`; both are employee-dialog-specific and should be restored or explicitly excluded before migration.
- `OnButtonAction` constructs [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md), [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md), and an `AddItemDialog` patched to [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) vtables.
- 2026-05-25 IDA MCP recheck confirms `0x004a3be0` is still not an IDA function but contains raw update-record code, and confirms `0x004a4ae0` is also raw constructor-shaped code with no IDA function object or xrefs.
- 2026-05-26 IDA MCP vtable pass confirms `EmployeeDialogPane` vtables at `0x00618f00`, `0x00618f60`, and `0x00618f90`; the secondary/tertiary destructor adjustor thunks at `0x004a4cc7` and `0x004a4cd2` are compiler-generated and now tracked as ignored memory.
- 2026-05-31 IDA MCP confirms the exact vtable data span at [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md), ending before `EmployeeItemPropertyDialogPane` RTTI at `0x00618f98`.

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)
- [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md)
- [UID:0000UL][EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md)
- [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md)
- [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md)
- [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/80`.
  - Summary/evidence: shop dialog role, method map, employee record stride, opcode family, omitted helper caveats, child dialogs, vtable evidence, and adjustor-thunk handling are documented; confidence remains limited by raw/projected helper modeling and final field names.
- 2026-05-31 reconstructable flag and exact helper link:
  - Before: `RECONSTRUCTABLE:` was blank and `DeserializeEmployeeRecord` was only listed as an address span in the method map.
  - After: `RECONSTRUCTABLE:TRUE` and `DeserializeEmployeeRecord` links to its exact by-memory page.
  - Summary/evidence: live IDA MCP recheck confirms the parser at `0x004a34d0` is a real function, is called by employee-dialog packet/list paths, and writes the documented `EmployeeRecord` layout.
