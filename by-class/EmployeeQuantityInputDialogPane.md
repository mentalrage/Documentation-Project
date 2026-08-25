*** UID:00004E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:00004E] EmployeeQuantityInputDialogPane class route marker.
// Exact constructor, action, layout, and vtable-data children carry source or marker output; do not duplicate method bodies here.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EmployeeQuantityInputDialogPane

## Status

- Confidence: strong for behavior, boundaries, direct method emitters, and the quantity submit timer-event route.
- Likely source file: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- Address range: [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- Current recovered file: `source-3/simroot_v2/class_EmployeeQuantityInputDialogPane.cpp`
- Type docs: [UID:0001UC][EmployeeQuantityInputDialogPaneLayout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md), [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- Exact vtable data: [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md), now class-owned source-declared/generated-binary ABI storage with a formal no-raw-vtable marker rather than raw `.rdata` array C++.

## Class Purpose

`EmployeeQuantityInputDialogPane` prompts for a numeric quantity used by employee item commands. It is opened either from the main employee dialog or from the employee add-item flow when the selected item supports a quantity.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) | `EmployeeQuantityInputDialogPane` | Builds the `Quantity` dialog using `DLGEXC3.EPF`, OK/cancel buttons, prompt text, and a focused text-edit control; now carries first-draft constructor C++ through this class emitter. |
| [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) | `OnAction` | Carries first-draft formal C++ through this class emitter; action `1` reads text edit control id `4`, parses `L"%d"` into an intentionally uninitialized `int quantity`, schedules employee event id `5` through `m_owner->m_timerHandler` with signed `m_selectedIndex` and quantity payloads, then closes. Action `2` closes without scheduling. |

## Recovered Fields

| Field | Offset | Type | Evidence |
| --- | --- | --- | --- |
| `m_owner` | `+0x26c` | pointer to [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md) | [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) stores the constructor owner parameter at `0x004a49b7`; [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) reads it before scheduling employee command/event id `5`. |
| `m_selectedIndex` | `+0x270` | `char` | [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) stores the selected index byte at `0x004a49c7`; [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) sign-extends it, so the source-facing field is a signed `char`, not `unsigned char`. |

## Evidence Notes

- IDA MCP confirms both method starts.
- `xrefs_to 0x004a4770` reports callers at `0x004a24f2`, `0x004a32b6`, and `0x004a4c5e`, covering the inventory helper, main employee button action, and `AddEmployeeItemDialog` action path.
- 2026-05-31 IDA MCP confirms the exact vtable data span at [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md), ending before `AddEmployeeItemDialog` RTTI at `0x006190d0`.
- Decompilation of `0x004a4a30` shows the parent pointer at `+0x26c` and selected item/index byte at `+0x270`; action `1` submits quantity, while action `2` just closes.
- 2026-05-26 IDA MCP confirms vtables at `0x00619038`, `0x00619098`, and `0x006190c8`, with constructor stores at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`; current Wave3 metadata still reports `vtable_count: 0`.
- The primary vtable uses shared dialog/alert scalar deleting destructor `0x0047eaf0`, while secondary/tertiary views use adjustor thunks `0x0047e8d9` and `0x0047e8e4`; these are compiler-generated and should not be emitted as handwritten employee-dialog methods.
- 2026-06-07 A010 live IDA refresh reconfirmed constructor `0x004a4770` with callers at `0x004a24f2`, `0x004a32b6`, and `0x004a4c5e`, covering the inventory helper, main dialog action path, and add-employee item action path. `xrefs_to 0x004a4a30` still routes through the primary vtable at `0x00619080`, and constructor vtable stores remain at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`.
- The 2026-06-07 callee refresh for `0x004a4a30` keeps this class in the employee command path: action `1` reads/parses the text control, calls the employee command sender path, then closes; action `2` only closes. The parent pointer at `+0x26c` and selected item/index byte at `+0x270` match [UID:0001UC][EmployeeQuantityInputDialogPaneLayout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md).
- 2026-06-25 B004 source-quality implementation confirms the constructor [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) now has formal first-draft C++ under this class. The accepted source-facing members are `m_owner` at `+0x26c` and signed `m_selectedIndex` at `+0x270`; the signedness is proven by the sibling action handler's sign-extension before scheduling employee command/event id `5`.
- 2026-06-28 B006 source-quality implementation confirms [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) now has formal first-draft C++ under this class. Current MCP session `supervisor_20260628_resume` was healthy before implementation and the accepted report rechecked exact `0xab` bounds, the sole vtable xref at `0x00619080`, no direct callers, control id `4`, UTF-16LE `L"%d"` bytes at `0x00610660`, branch action ids `1/2`, `m_owner`, signed `m_selectedIndex`, and `TimerHandler::ScheduleTimer(owner+0xa4, 5, 0, selectedIndex, quantity)`.
- The accepted action C++ uses inferred source-facing constants `kEmployeeQuantityConfirmAction`, `kEmployeeQuantityCloseAction`, `kEmployeeQuantityEditControlId`, and `kEmployeeCommandSubmitQuantity`. Exact original spellings remain a final-audit cap, but raw action/control numbers, `sub_5975E0`, and decompiler temporaries are no longer appropriate on this class method path.
- The helper-route distinction is resolved for this class: [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) schedules event id `5` through the owner dialog's TimerHandler subobject; [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) is the later event consumer/packet writer that stages the selected-index and quantity payloads.
- 2026-06-29 B004 vtable-data marker implementation confirms [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md) now carries the formal no-raw-vtable marker through this class. MCP session `967f0703` reconfirmed the three vtable bases `0x00619038`/`0x00619098`/`0x006190c8`, COL/RTTI records, key dwords including `0x00619080 -> 0x004a4a30`, constructor-store xrefs at `0x004a47cc`/`0x004a47d2`/`0x004a47dc`, and the `0x006190d0` successor boundary. The constructor/action children remain the source-authored emitters; vtable/RTTI bytes are regenerated from the class declaration and method/destructor shape.

## Ownership Synthesis

`EmployeeQuantityInputDialogPane` is a feature-private child of the employee-shop dialog module. Its constructor is reached only from employee item-command flows, its action method forwards through the owning employee dialog, and its exact vtable data is nested inside the employee dialog vtable family. It should route to the source file parent rather than to a generic dialog/input module.

## Assignment Gate

`CANONICAL_OWNER` and `EMITTER_UIDS` are set to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md). The class is now `88/91`, the direct source-file parent is `90/88`, and the by-structure relationship is direct because this quantity prompt is implemented in the employee-shop source module. Exact method bodies emit on their by-memory method pages through this class; the class page remains the declaration/ownership bridge.

## Score Rationale

- Completion is `88` because the class purpose, exact constructor/action child pages, caller triad, owner/index layout, action ids, control id, timer-event route, vtable data marker status, destructor-thunk exclusions, direct parent routing, and constructor plus action first-draft C++ statuses are documented.
- Confidence is `91` because current B004/B006 MCP evidence, exact by-memory pages, and layout/vtable/send-command docs agree on the two-method class boundary, employee-only call graph, `m_owner`, signed `m_selectedIndex`, action slot reachability, event id `5` scheduling semantics, and class-owned no-raw-vtable handling for [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md).
- The class-level C++ block remains blank because the class declaration as a whole still needs a broader declaration/member audit; the accepted source-bearing constructor/action C++ lives on [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) and [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md).

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

- 2026-06-29 B004 quantity vtable-data marker sync:
  - Score unchanged at `88/91`.
  - Summary/evidence: recorded that [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md) now emits only the accepted formal no-raw-vtable marker through this class. Current MCP session `967f0703` reconfirmed exact vtable bases, COL/RTTI dwords, constructor-store xrefs, primary slot `0x00619080 -> 0x004a4a30`, function sizes, and the successor `0x006190d0` boundary. [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) and [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) remain the source-authored behavior emitters; no raw `.rdata` vtable arrays are added to this class.
- 2026-06-28 B006 action source-quality sync:
  - Before: score `86/90`; the action method row described a high-level forward to parent dialog command `5`, while [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) still had broad aggregate owner/emitter and blank formal C++.
  - After: score `88/91`; [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) now records first-draft action C++ through this class, with `m_owner`, signed `m_selectedIndex`, action/control constants, `TextEditControlPane::ReadText`, `swscanf(L"%d")`, and `m_owner->m_timerHandler.ScheduleTimer(kEmployeeCommandSubmitQuantity, 0, m_selectedIndex, quantity)`.
  - Evidence: B006 current MCP/accepted report verified exact action bounds, sole vtable reachability at `0x00619080`, no direct callers, control id `4`, `L"%d"` bytes, uninitialized parsed local, owner/index field usage, and the later [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) case-5 staged route. Class-level C++ remains blank because declaration/member audit is broader than this method-body callback.
- 2026-06-25 B004 constructor source-quality sync:
  - Before: score `85/88`, constructor row did not record first-draft C++ status, and member names/signedness were still described generically as owner/index layout.
  - After: score `86/90`; [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) now records first-draft constructor C++ through this class, and this page records `m_owner` plus signed `m_selectedIndex`.
  - Evidence: B004 MCP session `91ce6b78-ad2a-43bf-890f-1e976af9bdb1` / database `80de0a67` verified the constructor caller triad, `0x274` allocation size, vtable stores, owner/index stores at `+0x26c/+0x270`, and sibling [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) sign-extension of the selected index byte.
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
