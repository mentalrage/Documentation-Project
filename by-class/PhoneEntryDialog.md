*** UID:0000AF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PhoneEntryDialog

## Status

- Confidence: strong
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_PhoneEntryDialog.cpp`

## Class Purpose

`PhoneEntryDialog` is the add/edit dialog for a terminal phone-book contact. It presents name and number text fields, validates that both are non-empty, then inserts or updates the selected phone-book list entry.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PhoneEntryDialog` | `0x0058d270` | Builds `DLGTEL2.EPD` dialog with OK/cancel buttons and name/number text controls. |
| `UpdateButtonState` | `0x0058d540` | Enables OK only when both name and number fields contain text. |
| `OnDialogAction` | `0x0058d5a0` | Reads text controls, updates or inserts the list entry, refreshes the owner phone book, and closes. |

## Evidence Notes

- The dialog is shown over `g_pTerminalPane`, which ties it to the terminal phone-book feature rather than a generic profile or social dialog.
- IDA MCP confirms the contiguous constructor/action block at `0x0058d270-0x0058d74b`.

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented role, method boundaries, validation behavior, terminal ownership, and contiguous IDA range evidence.
- Changed to: `COMPLETION:72` and `CONFIDENCE:84`.
- Evidence: constructor, OK-enable validation, action handler, `DLGTEL2.EPD` controls, `g_pTerminalPane` ownership, and IDA-confirmed range are documented; remaining gaps are detailed field layout and reconstructed C++.
