*** UID:0001R9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Employee Dialog Resources

## Status

- Scope: strings and resource/data constants currently tied to the employee shop dialog family.
- Confidence: strong for the inline strings, vtable/data island ownership, and consuming dialog methods; medium for final source/resource names.
- Evidence basis: IDA MCP direct UTF-16 decoding and xref checks already recorded in the linked by-memory, by-file, and issue-tracker pages.

## Resource Family

| Resource/data item | Evidence owner | Observed role | Notes |
| --- | --- | --- | --- |
| `EMPLOYEE` | [UID:000256][0x00618efc-0x0061929c.EmployeeDialogReadOnlyData](by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md) | Employee dialog resource/name literal. | Stored in the employee dialog `.rdata` island with the family vtables and UI resource names. |
| `LLER.EPF`, `LLER.PAL` | [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) | Main employee/seller dialog art resources. | The read-only-data page records these as employee dialog resource strings; exact DAT payload is not decoded here. |
| `PROPERTY` | [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) | Property editor label/resource marker. | Owned by the employee item property dialog path, not by generic item exchange dialogs. |
| `LLITEM.EPF`, `LLITEM.PAL` | [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) | Employee item-list/art resources. | Kept with the employee dialog family pending a DAT asset audit. |
| `Quantity` | [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) | Quantity prompt/control label family. | Distinct from unresolved localized string id `247`, which is looked up dynamically. |
| `3.EPF` | [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) | Quantity/input dialog art resource. | The read-only-data page lists this as the trailing employee dialog resource literal before the warning string range. |

## Resource Strings

| Address | Value | Observed use | Notes |
| --- | --- | --- | --- |
| `0x0061929c-0x006192c6` | `한번에 여러개를 추가할 수 없습니다.` | [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) multi-selection warning. | Only observed xref is `0x004a4bc1` inside `0x004a4b20-0x004a4cb1`. Meaning: cannot add multiple items at once. |
| `0x00613a18-0x00613a1e` | `OK` | Primary button label for the warning alert and many other dialogs. | Shared dialog string with many IDA xrefs; current generated alias `g_addEmployeeAlertCallbacks` is incorrect. |
| localized string id `247` | unresolved here | Quantity prompt text passed to `EmployeeQuantityInputDialogPane`. | Loaded through `GetLocalizedString`/string table at `0x004f0350` before constructing the quantity prompt. Final text should be resolved from the client string table or DAT resource. |

## Consumer Map

| Consumer | Resource use | Evidence |
| --- | --- | --- |
| [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) | Owns the employee shop dialog family, employee records, item-slot rendering, quantity/property child panes, and opcode `0x54` employee command paths. | File page records the `0x004a1d70-0x004a4e6a` boundary and the exact employee dialog vtable-data children. |
| [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) | Uses the static Korean warning and shared `OK` label when confirm is pressed with multiple selected items. | [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md) records the `OnButtonClick` behavior. |
| [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) | Consumes localized string id `247` for the stack/count prompt after a single selected stack-like item. | The AddEmployee method page records the item flag `+0x1ec` branch and dynamic string lookup. |
| [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) | Consumes the employee property dialog/resource literals in the same `.rdata` family. | The employee file page and read-only-data page keep it as a feature-private employee dialog, not a generic exchange dialog. |

## Ownership Notes

- The Korean warning string belongs with the employee dialog feature or a shared UI string table, not with generic [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- The `OK` string belongs to shared alert/dialog resources and should not be emitted as an employee callback table.
- The quantity prompt text is not an inline literal in the checked method; keep it as a localized string id until the string table lookup is decoded.
- Treat this page as the resource index for the employee dialog feature. Reconstructed source declarations belong on the consuming file/class/memory pages, because `by-resource` pages are not emitted as standalone C++.
- Keep `AddEmployeeItemDialog` feature ownership with [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), even though it reuses generic item dialog behavior; the employee-specific alert, quantity, and command-dispatch paths all depend on the employee owner object.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 72 | The page now indexes the known employee dialog resource literals, exact inline strings, consuming classes, memory evidence, and source-boundary rules. It remains below high completion because the DAT payloads, localized string id `247`, and original resource macro/literal strategy are still unresolved. |
| Confidence | 88 | The string addresses, warning xref, shared `OK` caveat, employee `.rdata` family, and consuming dialog methods are backed by existing IDA MCP evidence in linked pages. Confidence is capped by missing client string-table/DAT-resource decoding. |

## IDA MCP Evidence

- `0x0061929c` decodes as UTF-16 `한번에 여러개를 추가할 수 없습니다.`; IDA xref `0x004a4bc1` lands in `0x004a4b20-0x004a4cb1`.
- `0x00613a18` decodes as UTF-16 `OK` and has many dialog xrefs, confirming it is shared UI string data rather than employee-only state.
- [UID:000256][0x00618efc-0x0061929c.EmployeeDialogReadOnlyData](by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md) records the surrounding employee dialog RTTI/vtable and resource literal island: `EMPLOYEE`, `LLER.EPF`, `LLER.PAL`, `PROPERTY`, `LLITEM.EPF`, `LLITEM.PAL`, `Quantity`, and `3.EPF`.
- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) records the 2026-05-26 action-method recheck tying `AddEmployeeItemDialog::OnButtonClick` to the warning string, shared `OK`, and localized string id `247`.
- Localized string id `247` is still unresolved in this page; do not raise completion further until that string-table path is decoded.

## Cross-References

- File: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- Classes: [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md), [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md), [UID:00000B][AlertPane](by-class/AlertPane.md)
- Memory: [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md), [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md), [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md)
- Related resources: [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md)

## Changes

- Before: the Korean warning string was mojibake in the page and the page was scored `0/0`.
- Changed to: decoded UTF-16 Korean text, `COMPLETION:60`, and `CONFIDENCE:85`.
- Evidence: IDA MCP direct UTF-16 decode of `0x0061929c` and xref from `0x004a4bc1`.
- 2026-06-02 resource-family pass:
  - What existed before: the page listed only the two inline strings plus unresolved localized id `247`.
  - Changed to: `COMPLETION:72`, `CONFIDENCE:88`, with employee resource-family literals, consumer map, ownership boundaries, and score rationale.
  - Summary/evidence: linked employee `.rdata`, EmployeeDialogPane, AddEmployee method, AddEmployee alert text, and shared OK pages already establish the resource island and caller behavior; DAT payload and string-table text remain open.
