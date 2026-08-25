*** UID:0001UC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004E | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004E | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001UC] EmployeeQuantityInputDialogPane layout evidence marker.
// Owner/index tail fields support exact quantity-dialog method children; no standalone layout/body C++ is emitted here.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EmployeeQuantityInputDialogPane Layout

## Status

- Entity kind: derived dialog layout.
- Covered class: [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md).
- Likely owner source: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md).
- Rebuild handling: `source-declared/generated-binary`; recreate the class declaration/tail fields, not raw addresses.
- Direct owner/emitter: [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md).
- Confidence: strong for vtable views, `0x274` live allocation size, `m_owner`, and signed `m_selectedIndex`; medium-high for inherited `DialogPane` tail naming and final control/member names.
- Vtable-data support: [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md) now carries the class-owned formal no-raw-vtable marker for the `+0x00`, `+0xa0`, and `+0xa4` compiler-generated vtable views.

## Assignment Gate

`CANONICAL_OWNER` and `EMITTER_UIDS` are set to [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md). This layout page now clears the child-side gate at `86/91`, and the direct class parent clears the parent-side gate at `88/91`.

The direct semantic parent is the class page rather than [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), because this page documents the `EmployeeQuantityInputDialogPane` object layout only. The class page already routes to the employee-dialog source file, so attaching this layout to the class preserves the required child/direct-parent chain.

## Layout Hypothesis

`EmployeeQuantityInputDialogPane` is a small `DialogPane`-derived modal prompt. It stores the owning employee dialog pointer and the selected employee/item index after the inherited dialog state.

All three live constructor paths allocate `0x274` bytes immediately before calling `0x004a4770`, so the derived tail is now bounded as `[+0x26c,+0x274)`: owner pointer, selected index byte, and three bytes of tail padding/alignment.

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Constructor stores `0x00619038` at `0x004a47cc`; primary slot `+0x48` points to `0x004a4a30`. |
| `+0xa0` | 4 | secondary dialog/input vtable view | Constructor stores `0x00619098` at `0x004a47d2`; slot `+0x00` uses adjustor thunk `0x0047e8d9`. |
| `+0xa4` | 4 | tertiary event/update vtable view | Constructor stores `0x006190c8` at `0x004a47dc`; slot `+0x00` uses adjustor thunk `0x0047e8e4`. |
| `+0x26c` | 4 | `EmployeeDialogPane* m_owner` | Constructor [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) stores the caller parent pointer at `0x004a49b7`; [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) reads it before scheduling employee command/event `5` through `m_owner->m_timerHandler`. |
| `+0x270` | 1 | `char m_selectedIndex` | Constructor [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) stores the byte argument at `0x004a49c7`; [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) sign-extends it before forwarding it to event id `5`, so the source-facing field is signed. |
| `+0x271-+0x273` | 3 | tail padding / alignment | No field reads observed; all live callers allocate `0x274` bytes for the object before `0x004a4770`. |

The three vtable-view fields are represented by [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md). That page emits only the accepted no-raw-vtable marker because the RTTI/vtable bytes are compiler-generated from the class declaration, inherited virtual layout, shared destructor/adjustor thunks, [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md), and [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md).

The class-specific tail begins at `+0x26c`, immediately after the documented [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) custom-background state through `+0x268`. Do not promote the tail padding bytes to source fields unless later IDA evidence finds reads or writes.

## IDA MCP Evidence

- 2026-06-11 A002 live IDA MCP `py_eval` reconfirmed constructor `0x004a4770-0x004a4a25` (`0x2b5`) and action handler `0x004a4a30-0x004a4adb` (`0xab`).
- The same pass confirmed all three live callers allocate `0x274` bytes before construction: `0x004a2450` pushes `0x274` at `0x004a24c6` before calling `0x004a4770` at `0x004a24f2`, `0x004a3240` pushes `0x274` at `0x004a326f` before `0x004a32b6`, and `0x004a4b20` pushes `0x274` at `0x004a4c32` before `0x004a4c5e`.
- 2026-06-11 decompilation shows the constructor signature shape `sub_4A4770(this, promptText, owner, selectedIndex)` and writes `owner` at `this+0x26c` and `selectedIndex` at `this+0x270`.
- 2026-06-11 decompilation of `0x004a4a30` reads the inherited control manager at `this+0x1fc`, fetches control id `4`, copies `128` wide characters, parses `L"%d"`, reads owner at `this+0x26c` and signed selected byte at `this+0x270`, then queues event/command id `5` through `owner+0xa4` with selected-index and quantity payloads.
- 2026-06-11 direct dword reads confirmed `0x00619038 -> 0x0047eaf0`, `0x00619080 -> 0x004a4a30`, `0x00619098 -> 0x0047e8d9`, and `0x006190c8 -> 0x0047e8e4`.
- `lookup_funcs` confirms constructor `0x004a4770` size `0x2b5` and `OnAction` `0x004a4a30` size `0xab`.
- `xrefs_to 0x00619038`, `0x00619098`, and `0x006190c8` reports constructor stores at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`.
- `xrefs_to 0x004a4770` reports construction from the employee inventory helper `0x004a2450`, main employee dialog action handler `0x004a3240`, and `AddEmployeeItemDialog::OnButtonClick` `0x004a4b20`.
- `xrefs_to 0x004a4a30` reports the primary vtable data reference at `0x00619080`, which is primary slot `+0x48`.
- Constructor decompilation stores the owner pointer at `+0x26c` and the index byte at `+0x270`.
- `OnAction` reads text-edit control id `4`, parses the text as an integer quantity, queues the employee command/event path through the owner dialog's `+0xa4` subobject with event id `5`, and closes the dialog for button ids `1` and `2`.
- 2026-06-25 B004 source-quality implementation confirms the preferred field names and signedness: constructor [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) writes `m_owner` at `+0x26c` and `m_selectedIndex` at `+0x270`, while sibling [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) sign-extends `+0x270` before scheduling event id `5`.
- 2026-06-28 B006 source-quality implementation confirms [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) now emits formal first-draft C++ using these fields. Current MCP/accepted report evidence keeps `m_owner` at `+0x26c`, signed `m_selectedIndex` at `+0x270`, inherited `m_controlManager` at `+0x1fc`, text edit control id `4`, action ids `1/2`, UTF-16LE `L"%d"` parsing, and `m_owner->m_timerHandler.ScheduleTimer(kEmployeeCommandSubmitQuantity, 0, m_selectedIndex, quantity)` as the source-facing route.
- 2026-06-29 B004 source-quality implementation confirms [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md) now emits a formal no-raw-vtable marker for the vtable/RTTI storage instead of raw `.rdata` arrays. Current MCP session `967f0703` reconfirmed the vtable bases at `0x00619038`, `0x00619098`, and `0x006190c8`, constructor stores at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`, action slot `0x00619080 -> 0x004a4a30`, and the `0x006190d0` successor boundary.

## Score Rationale

- Completion is `86` because the page now records the direct class parent, exact `0x274` allocation size from all live callers, inherited/control offsets used by `OnAction`, `m_owner`, signed `m_selectedIndex`, vtable slots, method boundaries, formalized action-method consumption of the layout, and cross-links to exact constructor/action/vtable data pages.
- Confidence is `91` because current IDA/MCP-backed evidence agrees across constructor stores, action reads and sign-extension, caller allocation sites, exact vtable dwords, event id `5` scheduling, and the already-gated class/file ownership chain.
- The page remains below final-source range because inherited `DialogPane` field names, local/control names, and source-facing declarations still need a broader final declaration audit.

## Generated-Data Caveat

Current `source-3/simroot_v2/class_EmployeeQuantityInputDialogPane.meta_wave3` reports `vtable_count: 0` even though IDA confirms all three vtable bases. It also records a constructor method name with a trailing carriage-return/control character in the generated metadata. Treat those as Wave3 data issues, not source facts.

## Cross-References

- [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md)
- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md)
- [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md)
- [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)
- [UID:0000UL][EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md)

## Changes

- 2026-06-29 B004 vtable-view marker sync:
  - Score unchanged at `86/91`.
  - Summary/evidence: added [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md) as the formal no-raw-vtable marker page for the `+0x00`, `+0xa0`, and `+0xa4` compiler-generated vtable views. Current MCP session `967f0703` reconfirmed the exact vtable bases, constructor stores, action slot, and successor boundary; the layout page remains declaration/layout support with blank formal C++.
- 2026-06-28 B006 action field/route sync:
  - Score unchanged at `86/91`.
  - Summary/evidence: recorded that [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) now emits first-draft C++ through [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md), consuming `m_owner`, signed `m_selectedIndex`, inherited `m_controlManager`, text edit control id `4`, and event id `5`. The layout page remains a declaration/layout support page with blank formal C++.
- 2026-06-25 B004 constructor field sync:
  - Before: score `85/90`; the tail fields were documented as generic `owner` and employee/item index byte.
  - After: score `86/91`; the preferred source-facing tail names are `m_owner` at `+0x26c` and signed `m_selectedIndex` at `+0x270`.
  - Summary/evidence: B004 MCP session `91ce6b78-ad2a-43bf-890f-1e976af9bdb1` / database `80de0a67` verified constructor writes at `0x004a49b7` and `0x004a49c7`, all three `0x274` allocation sites, and sibling action sign-extension of `+0x270` before command/event id `5` scheduling.
- 2026-06-11 A002 assignment and allocation-size pass:
  - Before: the page was `76/88`, reconstructable, and unassigned; the `0x274` object size was described as plausible but not directly confirmed on this page.
  - Changed to: raised to `85/90`, set `AUTOGEN_PARENT_UID:00004E`, documented the strict child/class-parent gate, and converted the object-size note into live IDA evidence.
  - Summary/evidence: live IDA MCP confirmed the `0x004a4770` constructor and `0x004a4a30` action-handler bounds, all three `0x274` allocation sites, owner/index writes at `+0x26c/+0x270`, action reads of `+0x1fc/+0x26c/+0x270`, event id `5` scheduling through owner `+0xa4`, and the quantity-dialog vtable dwords.
- 2026-05-31 completion/reconstruction metadata:
  - What existed before: metadata remained unevaluated at `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank despite detailed layout notes.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`; exact constructor/action memory pages were added to cross-references.
  - Summary/evidence: live IDA MCP recheck confirms constructor size/callers, vtable stores, owner pointer at `+0x26c`, selected index byte at `+0x270`, action handler use of control id `4`, and employee command `5` dispatch.
