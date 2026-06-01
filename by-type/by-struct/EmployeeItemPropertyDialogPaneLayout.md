*** UID:0001UB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EmployeeItemPropertyDialogPane Layout

## Status

- Entity kind: derived dialog layout.
- Covered class: [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md).
- Likely owner source: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md).
- Size: `0x284` bytes on the live allocation path.
- Confidence: strong for feature-specific tail fields and vtable offsets; medium for inherited `DialogPane` member names.

## Layout Hypothesis

`EmployeeItemPropertyDialogPane` is a `DialogPane`-derived item price/property editor. The inherited dialog base occupies the first `0x26c` bytes. The derived tail stores the owning employee dialog, the icon rectangle used by `OnPaint`, and the selected employee record pointer.

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Constructor stores `0x00618f9c` at `0x004a4230`. |
| `+0xa0` | 4 | secondary dialog/input vtable view | Constructor stores `0x00618ffc` at `0x004a4236`. |
| `+0xa4` | 4 | tertiary event/update vtable view | Constructor stores `0x0061902c` at `0x004a4240`. |
| `+0x1fc` | 4 | inherited control collection pointer | `OnCommand` reads this field, dispatches vtable slot `+0x10` with control id `3`, and reads price text from the returned text-edit pane. |
| `+0x26c` | 4 | `EmployeeDialogPane* parentDialog` | Constructor stores argument `a3` at `0x004a420f`; `OnCommand` reads it before sending employee commands or recording pending price edits. |
| `+0x270` | 16 | icon rectangle | Constructor writes `20, 21, 68, 69` through `SetRect`; `OnPaint` reads the left/top pair and draws a 44-by-44 item icon. |
| `+0x280` | 4 | `EmployeeRecord* itemRecord` | Constructor stores argument `a2` at `0x004a421a`; `OnPaint` and `OnCommand` read item id, sprite/palette fields, price, and editable price from this record. |
| `+0x284` | - | object end | `EmployeeDialogPane::OnButtonAction` allocates `644` bytes before calling the constructor. |

## Method Offset Evidence

- `EmployeeDialogPane::OnButtonAction` at `0x004a32ff` allocates `644` bytes (`0x284`) and calls the constructor at `0x004a3319`.
- Constructor `0x004a41c0` calls `DialogPane::DialogPane("Property", 20, 1)`, then stores the parent pointer at dword index `155` (`+0x26c`) and the item pointer at dword index `160` (`+0x280`).
- Constructor `0x004a43d7` writes the item icon rectangle at dword index `156` (`+0x270`) using `SetRect(20, 21, 68, 69)`.
- `OnPaint` at `0x004a4570` reads `this + 0x270` and `this + 0x280`, loads `SELLITEM.EPF`/`SELLITEM.PAL`, and calls the item-object image renderer using the selected record's sprite and palette fields.
- `OnCommand` at `0x004a4660` reads `this + 0x26c`, `this + 0x1fc`, and `this + 0x280`. Confirm writes the edited price to `parent + 0x26c`, sets `parent + 0x270`, and sends employee command `2`; alternate action sends command `3`.

## Vtable Notes

Primary vtable `0x00618f9c` includes:

- `+0x00 -> 0x004a4e30` scalar deleting destructor.
- `+0x44 -> 0x004a4570` paint handler.
- `+0x48 -> 0x004a4660` command/action handler.

Secondary vtable `0x00618ffc` and tertiary vtable `0x0061902c` are installed at `+0xa0` and `+0xa4`. Their destructor slots point to compiler-generated adjustor thunks `0x004a4cdd` and `0x004a4ce8`; keep those as ABI glue, not source methods.

## Reconstruction Notes

Model the source type as a feature-private property dialog with a typed `EmployeeDialogPane*` owner and `EmployeeRecord*` item pointer. Do not copy the generated local `DialogLayout` and `PaneState` overlay structs into final source; they are decompiler scaffolding for the derived tail fields.

The scalar deleting destructor decompiles with polluted base labels in both current simroot and IDA. Treat it as `EmployeeItemPropertyDialogPane` deleting destructor plus inherited dialog teardown until the shared base destructor name is settled.

## Cross-References

- [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md)
- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0002HE][0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor](by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md)
- [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md)
- [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md)
- [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)

## Changes

- 2026-05-31 completion/reconstruction metadata:
  - What existed before: metadata remained unevaluated at `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank despite detailed layout notes.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`; exact constructor/paint/command memory pages were added to cross-references.
  - Summary/evidence: live IDA MCP recheck confirms the constructor size/caller, vtable stores, parent pointer at `+0x26c`, icon rectangle at `+0x270`, item record pointer at `+0x280`, paint use of those fields, and command use of parent/record/control state.
