*** UID:0000J0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# EmployeeDialogPane

## Status

- Confidence: strong for the employee-shop dialog family and `0x004a1d70-0x004a4e6a` boundaries; medium-high for final split from generic [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- Proposed module folder: `ui/dialogs/`
- Candidate file: `ui/dialogs/EmployeeDialogPane.cpp`
- Related class pages: [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md), [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md), [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md), and [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md).
- Evidence basis: existing by-* documentation and targeted IDA MCP checks, including 2026-06-06 add-item and 2026-06-07 class-parent gate rechecks.
- Type docs: [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md), [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md), [UID:0001TN][AddEmployeeItemDialogLayout](by-type/by-struct/AddEmployeeItemDialogLayout.md), [UID:0001UC][EmployeeQuantityInputDialogPaneLayout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md), [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- Exact vtable data: [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md), [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md), [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md), and [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md).

## Hypothesis

The employee shop/management UI was likely one feature source module rather than four independent one-class files. `EmployeeDialogPane` owns the main `SELLER.EPF` dialog, employee record storage, opcode `0x54` employee command packets, packet response handling, item-slot rendering, quantity input, property editing, and the `AddEmployeeItemDialog` subclass used to add inventory items to the employee flow.

Likely source layout:

```text
ui/dialogs/EmployeeDialogPane.cpp
```

Possible split if the original project kept small input dialogs separate:

```text
ui/dialogs/EmployeeDialogPane.cpp
ui/dialogs/EmployeeItemDialogs.cpp
```

## Proposed Contents

| Entity | Current range | Documentation status | Role |
| --- | --- | --- | --- |
| `EmployeeDialogPane` | `0x004a1d70-0x004a4056`, destructor/thunks `0x004a4cc7-0x004a4e26` | Class page plus aggregate memory range. | Main employee-shop dialog, packet sender, item-slot renderer, record storage, and packet update handlers. |
| `HandleEmployeeInventoryItem` | `0x004a2450-0x004a2530` | IDA-modeled file-local helper still needing exact by-memory split. | Inventory item helper; sends immediate employee item command or opens quantity input when the item stack requires a count. |
| `HandleEmployeeDialogPacket` | `0x004a2f60-0x004a322b` | IDA-modeled file-local packet helper still needing exact by-memory split. | Opcode `0x4f`/subcommand `1` dispatcher that applies employee records, removals, field updates, and status text. |
| `DeserializeEmployeeRecord` | [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) | Exact parser helper page. | Parses variable-length employee records into the 1052-byte `EmployeeRecord` layout. |
| `EmployeeItemPropertyDialogPane` | [UID:0002HE][0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor](by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md), [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md), [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md), destructor/thunks `0x004a4cdd-0x004a4e6a`, layout [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md) | Class page plus exact method/layout pages. | Item property/price editor for an employee-owned item. |
| `EmployeeQuantityInputDialogPane` | [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md), [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) | Class page plus exact method/layout pages. | Quantity prompt used by employee item commands. |
| `AddEmployeeItemDialog` inline construction | `0x004a3381-0x004a33be` inside `0x004a3240` | [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md) | Live add-item picker creation path; allocates `0x274`, calls generic `AddItemDialog`, patches add-employee vtables, and stores the owner pointer. |
| `AddEmployeeItemDialog` | `0x004a4b20-0x004a4d3b`, raw constructor-shaped bytes at `0x004a4ae0` | Class page plus exact vtable-data child; runtime construction is inline in `OnButtonAction`. | Employee-specific `AddItemDialog` subclass/variant used by the main employee dialog. |
| `EmployeeRecord` | size `0x41c` | Layout type page. | Per-employee item/shop record parsed from packets and displayed in the main dialog. |

## IDA MCP Evidence

Checked on 2026-05-24:

- `lookup_funcs` confirms `EmployeeDialogPane` anchors at `0x004a1d70`, `0x004a22f0`, `0x004a2560`, `0x004a2a60`, `0x004a2c80`, `0x004a3240`, `0x004a33e0`, `0x004a34d0`, `0x004a3a90`, and `0x004a3e10`.
- IDA confirms file-local helpers at `0x004a2450` and `0x004a2f60`; keep them in this module even though they are not currently represented as class method pages.
- IDA reports no function at raw `0x004a3be0` `UpdateEmployeeRecord` candidate start, although raw disassembly shows a valid prologue/body with no direct xrefs. Treat it as a raw/projected helper until function-boundary cleanup.
- IDA confirms `EmployeeItemPropertyDialogPane` starts at `0x004a41c0`, `0x004a4570`, `0x004a4660`, and `0x004a4e30`, plus disabled adjustor thunks at `0x004a4cdd` and `0x004a4ce8`.
- IDA confirms `EmployeeQuantityInputDialogPane` at `0x004a4770` and `0x004a4a30`.
- IDA reports no function at the projected `AddEmployeeItemDialog` constructor-shaped bytes at `0x004a4ae0`; raw disassembly is constructor-shaped but has no xrefs, while the real method island starts at `0x004a4b20`.
- 2026-05-25 recheck confirms this page still needs to account for the file-local helpers at `0x004a2450` and `0x004a2f60`, raw `0x004a3be0`, and the unreferenced raw `0x004a4ae0` constructor-shaped bytes.
- `xrefs_to 0x004a1d70` reports callers at `0x00508d53` and `0x005103d2`, consistent with packet/session creation paths.
- `xrefs_to 0x004a34d0` reports callers from `0x004a2f60`, `0x004a3a90`, and raw `0x004a3be0` code.
- 2026-05-26 IDA MCP vtable pass confirms `AddEmployeeItemDialog` vtables at `0x006190d4`, `0x00619134`, and `0x00619164`, with `OnButtonClick` at primary slot `+0x48`. The raw constructor bytes at `0x004a4ae0` install those vtables but still have no function object or xrefs.
- 2026-05-31 IDA MCP split exact `.rdata` child pages for all four employee dialog vtable groups: [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md), [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md), [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md), and [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md).
- 2026-05-27 IDA recheck still finds no function/xrefs or raw pointer-table references to `0x004a4ae0`; prefer the live inline construction sequence at `0x004a3381-0x004a33be` as the runtime source-map anchor.
- 2026-05-26 IDA MCP vtable pass confirms `EmployeeQuantityInputDialogPane` vtables at `0x00619038`, `0x00619098`, and `0x006190c8`, installed by constructor stores at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`.
- 2026-05-26 IDA MCP layout pass confirms `EmployeeItemPropertyDialogPane` is allocated as `0x284` bytes in `EmployeeDialogPane::OnButtonAction`, stores the parent pointer at `+0x26c`, stores the icon rectangle at `+0x270`, and stores the selected `EmployeeRecord*` at `+0x280`.
- 2026-05-26 IDA MCP layout pass confirms `EmployeeDialogPane::OnButtonAction` allocates `0x274` bytes for the add-item variant, calls generic `AddItemDialog`, patches the three `AddEmployeeItemDialog` vtables, and stores the employee-dialog owner at object offset `+0x270`.
- 2026-05-26 IDA MCP recheck records this live construction sequence as [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md), so the source map should prefer the `EmployeeDialogPane::OnButtonAction` branch over the unreferenced raw constructor start as runtime evidence.
- 2026-05-26 IDA MCP confirms `0x004a4cb1-0x004a4cf3` is a compiler-generated adjustor-thunk island for `AddEmployeeItemDialog`, `EmployeeDialogPane`, and `EmployeeItemPropertyDialogPane`; keep it out of handwritten source.
- 2026-05-26 action-method recheck confirms `AddEmployeeItemDialog::OnButtonClick` uses [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md): inline warning text at `0x0061929c` for multi-select rejection, shared `OK` label at `0x00613a18`, and localized string id `247` for the quantity prompt.
- 2026-05-31 IDA MCP recheck confirms exact child pages for `DeserializeEmployeeRecord`, the property dialog constructor/paint/command methods, and the quantity dialog constructor/action methods. These pages are marked reconstructable but intentionally left unattached and without C++ because they are not at the `95+` final-code threshold.
- 2026-06-06 live AddEmployee recheck confirms `OnButtonClick` at `0x004a4b20-0x004a4cb1`, AddEmployee-only adjustor thunks at `0x004a4cb1-0x004a4cc7`, scalar deleting destructor `0x004a4d00-0x004a4d3b`, no function/xrefs for raw `0x004a4ae0`, inline vtable stores at `0x004a33a4`/`0x004a33aa`/`0x004a33b4`, raw vtable stores at `0x004a4afe`/`0x004a4b04`/`0x004a4b0e`, primary action slot ref at `0x0061911c`, and AddEmployee thunk refs from `0x00619134`/`0x00619164`.
- 2026-06-07 class-parent gate recheck confirms the main dialog constructor at `0x004a1d70` is called from packet/session creation paths `0x00508d53` and `0x005103d2`; `EmployeeDialogPane::OnButtonAction` at `0x004a3240`, `DeserializeEmployeeRecord` at `0x004a34d0`, quantity dialog construction/action at `0x004a4770`/`0x004a4a30`, and `AddEmployeeItemDialog::OnButtonClick` at `0x004a4b20` still sit in the same contiguous employee-shop island. IDA still reports no function at raw `0x004a3be0`, so confidence rises only to the parent-assignment threshold rather than final-audit range.

## Ownership Notes

- Keep generic `AddItemDialog` and `AddItemWithCountDialog` in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), but move or cross-own `AddEmployeeItemDialog` with this employee module because its owner pointer is an `EmployeeDialogPane` and its button path dispatches employee quantity/property commands. `EmployeeDialogPane::OnButtonAction` constructs the base item dialog and patches the `AddEmployeeItemDialog` vtables inline, so the raw `0x004a4ae0` constructor-shaped bytes should not be the only source-map anchor.
- `EmployeeQuantityInputDialogPane` and `EmployeeItemPropertyDialogPane` are feature-private dialogs; they should not migrate as generic exchange dialogs even though they reuse `DLGEXC3.EPF`, `SELLITEM.EPF`, and base dialog controls.
- `EmployeeRecord` should be documented as a recovered type/layout before header generation because several methods assume the fixed `0x41c` stride.
- `EmployeeItemPropertyDialogPane::ScalarDeletingDestructor` currently emits a base call labeled `TransferReplyAlert::~DialogPane`; treat that as base-owner pollution until the shared dialog teardown is named.

## Follow-Up Notes

- Reconcile `0x004a2450`, `0x004a2f60`, and raw/projected `0x004a3be0` with exact by-memory pages before final source migration.
- Keep `AddEmployeeItemDialog` in this employee module unless later evidence proves the original project placed employee item selection in the generic [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) source file.
- Keep final C++ children blank until the employee dialog family reaches the `95/95` final-code gate.

## Cross-References

- [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md)
- [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md)
- [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0000UL][EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md)
- [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md)
- [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md)
- [UID:0002HE][0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor](by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md)
- [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md)
- [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md)
- [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md)
- [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md)
- [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md)
- [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md)
- [UID:0001TN][AddEmployeeItemDialogLayout](by-type/by-struct/AddEmployeeItemDialogLayout.md)
- [UID:0001UC][EmployeeQuantityInputDialogPaneLayout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md)
- [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md)
- [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md)
- [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md)
- [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)

## Changes

- 2026-06-07 A010 Batch086 class-parent gate:
  - What existed before: `CONFIDENCE:84`, leaving the direct file parent just below the corrected 85/85 assignment gate for employee class toss-up rows.
  - Changed to: `CONFIDENCE:85`; completion remains `88`.
  - Summary/evidence: live IDA reconfirmed the employee-shop constructor callers, main dialog action/parser anchors, quantity-dialog caller triad, AddEmployee action island, and exact vtable-data boundaries while preserving the raw `0x004a3be0` caveat and final split uncertainty from generic item dialogs.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: employee shop grouping, proposed contents, packet/record helpers, IDA boundary and vtable evidence, inline add-item construction, ownership notes, migration cautions, type/resource links, and omitted helper coverage are documented; confidence is strong with remaining uncertainty around final split from generic item dialogs and a few raw/projected helpers.
- 2026-05-31 projected path and exact child range links:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and several proposed contents rows still named raw address spans rather than exact child by-memory pages.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and cross-references to the exact IDA-verified employee record/property/quantity pages.
  - Summary/evidence: proposed-source-tree already places `EmployeeDialogPane.cpp` under `ui/dialogs`; live IDA MCP recheck confirmed the exact child function sizes and xrefs.
- 2026-06-06 provenance cleanup and AddEmployee refresh:
  - What existed before: the page still described source grouping in terms of stale generated-provenance labels and kept old migration-command scaffolding.
  - Changed to: confidence was raised to `84`, the proposed contents table now describes documentation/runtime status instead of generated container names, stale provenance wording was removed, and the AddEmployee evidence now reflects the 2026-06-06 live IDA recheck.
  - Summary/evidence: live IDA confirms the employee add-item inline construction path, raw no-xref constructor caveat, exact action/destructor/thunk ranges, and vtable refs; remaining raw helper and final source-split caveats keep completion/confidence below final-audit levels.
