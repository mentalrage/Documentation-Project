*** UID:00004E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EmployeeQuantityInputDialogPane

## Status

- Confidence: strong for behavior and boundaries.
- Likely source file: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- Address range: [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- Current recovered file: `source-3/simroot_v2/class_EmployeeQuantityInputDialogPane.cpp`
- Type docs: [UID:0001UC][EmployeeQuantityInputDialogPaneLayout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md), [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- Exact vtable data: [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md)

## Class Purpose

`EmployeeQuantityInputDialogPane` prompts for a numeric quantity used by employee item commands. It is opened either from the main employee dialog or from the employee add-item flow when the selected item supports a quantity.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) | `EmployeeQuantityInputDialogPane` | Builds the `Quantity` dialog using `DLGEXC3.EPF`, OK/cancel buttons, prompt text, and a focused text-edit control. |
| [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) | `OnAction` | Reads text edit control id `4`, parses an integer quantity, forwards employee command `5` through the parent dialog, then closes. |

## Evidence Notes

- IDA MCP confirms both method starts.
- `xrefs_to 0x004a4770` reports callers at `0x004a24f2`, `0x004a32b6`, and `0x004a4c5e`, covering the inventory helper, main employee button action, and `AddEmployeeItemDialog` action path.
- 2026-05-31 IDA MCP confirms the exact vtable data span at [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md), ending before `AddEmployeeItemDialog` RTTI at `0x006190d0`.
- Decompilation of `0x004a4a30` shows the parent pointer at `+0x26c` and selected item/index byte at `+0x270`; action `1` submits quantity, while action `2` just closes.
- 2026-05-26 IDA MCP confirms vtables at `0x00619038`, `0x00619098`, and `0x006190c8`, with constructor stores at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`; current Wave3 metadata still reports `vtable_count: 0`.
- The primary vtable uses shared dialog/alert scalar deleting destructor `0x0047eaf0`, while secondary/tertiary views use adjustor thunks `0x0047e8d9` and `0x0047e8e4`; these are compiler-generated and should not be emitted as handwritten employee-dialog methods.
- 2026-06-07 A010 live IDA refresh reconfirmed constructor `0x004a4770` with callers at `0x004a24f2`, `0x004a32b6`, and `0x004a4c5e`, covering the inventory helper, main dialog action path, and add-employee item action path. `xrefs_to 0x004a4a30` still routes through the primary vtable at `0x00619080`, and constructor vtable stores remain at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`.
- The 2026-06-07 callee refresh for `0x004a4a30` keeps this class in the employee command path: action `1` reads/parses the text control, calls the employee command sender path, then closes; action `2` only closes. The parent pointer at `+0x26c` and selected item/index byte at `+0x270` match [UID:0001UC][EmployeeQuantityInputDialogPaneLayout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md).

## Ownership Synthesis

`EmployeeQuantityInputDialogPane` is a feature-private child of the employee-shop dialog module. Its constructor is reached only from employee item-command flows, its action method forwards through the owning employee dialog, and its exact vtable data is nested inside the employee dialog vtable family. It should route to the source file parent rather than to a generic dialog/input module.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md). The child is now `85/88`, the direct source-file parent is `88/85`, and the by-structure relationship is direct because this quantity prompt is implemented in the employee-shop source module.

## Score Rationale

- Completion is `85` because the class purpose, exact constructor/action child pages, caller triad, owner/index layout, vtable data, destructor-thunk exclusions, and direct parent routing are documented.
- Confidence is `88` because live IDA, exact by-memory pages, and layout/vtable docs agree on the two-method class boundary and its employee-only call graph.
- The score stays below final-code range because final member names and exact local/control names still need a full source-emission pass.

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0000UL][EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md)
- [UID:0001UC][EmployeeQuantityInputDialogPaneLayout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md)
- [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md)
- [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md)
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md)

## Changes

- 2026-06-07 A010 Batch086 class coverage toss-up:
  - Before: score `78/86`, `AUTOGEN_PARENT_UID` blank, with enough confidence but incomplete ownership/parent-gate documentation.
  - After: score `85/88`, `AUTOGEN_PARENT_UID:0000J0`.
  - Evidence: live IDA reconfirmed the constructor caller triad, vtable stores, action vtable slot, parent/item layout, and command-forwarding behavior; [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) was raised to `88/85`, so both child and direct parent meet the corrected 85/85 gate.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/86`.
  - Summary/evidence: quantity prompt role, constructor/action boundaries, callers, parent/item layout, vtables, and shared destructor-thunk ownership are documented; remaining work is mostly final field/local naming.
- 2026-05-31 reconstructable flag and exact method links:
  - Before: `RECONSTRUCTABLE:` was blank and method rows used raw address spans.
  - After: `RECONSTRUCTABLE:TRUE` and constructor/action rows link to exact by-memory pages.
  - Summary/evidence: live IDA MCP recheck confirms method sizes, constructor callers, vtable references, owner/index fields, and command `5` dispatch behavior.
