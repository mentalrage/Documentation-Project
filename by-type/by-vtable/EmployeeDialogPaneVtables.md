*** UID:0001XH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EmployeeDialogPane Vtables

## Status

- Confidence: strong for vtable addresses and class-specific slots, medium for inherited slot names.
- Likely owner source: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- Memory evidence: [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md), [UID:000256][0x00618efc-0x0061929c.EmployeeDialogReadOnlyData](by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md), [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md), [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)
- Layout docs: [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md), [UID:0001TN][AddEmployeeItemDialogLayout](by-type/by-struct/AddEmployeeItemDialogLayout.md), [UID:0001UC][EmployeeQuantityInputDialogPaneLayout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md)

## EmployeeDialogPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x00618f00` | `+0x00 -> 0x004a4d40` scalar deleting destructor. |
| secondary | `0x00618f60` | `+0x00 -> 0x004a4cc7` this-adjustor thunk; `+0x04 -> 0x004a2a60` mouse/tooltip handler; `+0x10 -> 0x004a2f60` employee packet dispatcher. |
| tertiary | `0x00618f90` | `+0x00 -> 0x004a4cd2` this-adjustor thunk; `+0x04 -> 0x004a2c80` employee command sender. |

Exact data range: [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md).

## EmployeeItemPropertyDialogPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x00618f9c` | `+0x00 -> 0x004a4e30` scalar deleting destructor; `+0x44 -> 0x004a4570` paint handler; `+0x48 -> 0x004a4660` command/action handler. |
| secondary | `0x00618ffc` | `+0x00 -> 0x004a4cdd` this-adjustor thunk. |
| tertiary | `0x0061902c` | `+0x00 -> 0x004a4ce8` this-adjustor thunk; `+0x0c -> 0x0047eaf0` inherited or base-dialog slot. |

Exact data range: [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md).

## EmployeeQuantityInputDialogPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x00619038` | `+0x00 -> 0x0047eaf0` shared dialog/alert scalar deleting destructor; `+0x48 -> 0x004a4a30` quantity confirm/cancel action handler. |
| secondary | `0x00619098` | `+0x00 -> 0x0047e8d9` this-adjustor thunk into `0x0047eaf0`. |
| tertiary | `0x006190c8` | `+0x00 -> 0x0047e8e4` this-adjustor thunk into `0x0047eaf0`; `+0x04 -> 0x00544e90` base/default event-update slot. |

Exact data range: [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md).

The quantity dialog uses the older shared [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md), not the employee-specific `0x004a4cb1-0x004a4cf3` thunk island. Keep this distinction when reconstructing destructors.

## AddEmployeeItemDialog

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x006190d4` | `+0x00 -> 0x004a4d00` scalar deleting destructor; `+0x48 -> 0x004a4b20` employee item action handler; `+0x4c -> 0x004aea40` inherited item-dialog action slot. |
| secondary | `0x00619134` | `+0x00 -> 0x004a4cb1` this-adjustor thunk. |
| tertiary | `0x00619164` | `+0x00 -> 0x004a4cbc` this-adjustor thunk. |

Do not read primary `+0x5c` or secondary `+0x2c` as normal virtual slots. They are RTTI metadata for the next table. The secondary table happens to begin at absolute address `0x00619134`, which is primary base `+0x60`.

Exact data range: [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md).

## Evidence

- 2026-05-26 IDA MCP `py_eval` read the listed vtable dwords directly from the IDB.
- 2026-05-31 IDA MCP `list_globals`, `lookup_funcs`, and dword scan confirmed exact `.rdata` child ranges: `0x00618efc-0x00618f98`, `0x00618f98-0x00619034`, `0x00619034-0x006190d0`, and `0x006190d0-0x0061916c`.
- `xrefs_to` ties `EmployeeDialogPane` vtables to constructor/destructor writes at `0x004a1d70`, `0x004a22f0`, and `0x004a4d40`.
- `xrefs_to` ties `EmployeeItemPropertyDialogPane` vtables to constructor writes at `0x004a41c0`.
- `xrefs_to` ties `EmployeeItemPropertyDialogPane::OnPaint` to primary slot `0x00618fe0` and `OnCommand` to primary slot `0x00618fe4`.
- `xrefs_to` ties `EmployeeQuantityInputDialogPane` vtables to constructor writes at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`; `OnAction` is vtable-referenced at `0x00619080`.
- `xrefs_to` ties `AddEmployeeItemDialog` vtables to inline writes in `EmployeeDialogPane::OnButtonAction` at `0x004a3240` and to raw constructor-shaped bytes at `0x004a4ae0`.
- The live inline write sequence is documented as [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md): `0x004a33a4`, `0x004a33aa`, and `0x004a33b4` store the primary/secondary/tertiary vtable bases after the generic `AddItemDialog` constructor call.
- `xrefs_to` confirms `AddEmployeeItemDialog::OnButtonClick` at `0x004a4b20` is vtable-referenced at `0x0061911c` and has no direct code callers, matching virtual dispatch from the item picker.
- Current `class_AddEmployeeItemDialog.meta_wave3` reports `vtable_count: 0`, so generated vtable inventory is incomplete despite these IDA-confirmed vtable bases.

## Reconstruction Notes

The adjustor thunk slots are compiler-generated and are recorded in [UID:0000VN][-ignored](by-memory/-ignored.md). Reconstruct normal class inheritance and destructors in `EmployeeDialogPane.cpp`; do not emit these thunks as handwritten methods.

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md)
- [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md)
- [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)
- [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md)
- [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md)
- [UID:0001TN][AddEmployeeItemDialogLayout](by-type/by-struct/AddEmployeeItemDialogLayout.md)
- [UID:0001UC][EmployeeQuantityInputDialogPaneLayout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md)
- [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)
- [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md)
- [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md)
- [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md)
- [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-05-31 exact `.rdata` child split:
  - What existed before: metadata was unevaluated `0/0`, `RECONSTRUCTABLE` was blank, and the page listed vtable bases without exact by-memory child pages for the read-only data bytes.
  - Changed to: scored `86/88`, marked `RECONSTRUCTABLE:TRUE`, and linked four exact vtable-data child pages.
  - Summary/evidence: IDA MCP `list_globals`, `lookup_funcs`, and dword scan confirmed RTTI words, vtable bases, slot values, adjustor-thunk functions, and next-range boundaries for the employee dialog vtable family.
