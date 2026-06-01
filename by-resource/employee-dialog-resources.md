*** UID:0001R9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Employee Dialog Resources

## Status

- Scope: strings and resource/data constants currently tied to the employee shop dialog family.
- Confidence: confirmed for the two string addresses below; medium for final source/resource names.
- Evidence basis: IDA MCP direct UTF-16 decoding and xref checks.

## Resource Strings

| Address | Value | Observed use | Notes |
| --- | --- | --- | --- |
| `0x0061929c-0x006192c6` | `한번에 여러개를 추가할 수 없습니다.` | [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) multi-selection warning. | Only observed xref is `0x004a4bc1` inside `0x004a4b20-0x004a4cb1`. Meaning: cannot add multiple items at once. |
| `0x00613a18-0x00613a1e` | `OK` | Primary button label for the warning alert and many other dialogs. | Shared dialog string with many IDA xrefs; current generated alias `g_addEmployeeAlertCallbacks` is incorrect. |
| localized string id `247` | unresolved here | Quantity prompt text passed to `EmployeeQuantityInputDialogPane`. | Loaded through `GetLocalizedString`/string table at `0x004f0350` before constructing the quantity prompt. Final text should be resolved from the client string table or DAT resource. |

## Ownership Notes

- The Korean warning string belongs with the employee dialog feature or a shared UI string table, not with generic [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- The `OK` string belongs to shared alert/dialog resources and should not be emitted as an employee callback table.
- The quantity prompt text is not an inline literal in the checked method; keep it as a localized string id until the string table lookup is decoded.

## IDA MCP Evidence

- `0x0061929c` decodes as UTF-16 `한번에 여러개를 추가할 수 없습니다.`; IDA xref `0x004a4bc1` lands in `0x004a4b20-0x004a4cb1`.
- `0x00613a18` decodes as UTF-16 `OK` and has many dialog xrefs, confirming it is shared UI string data rather than employee-only state.
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
