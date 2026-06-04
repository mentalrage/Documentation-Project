*** UID:0000AD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PhoneBookDialog

## Status

- Confidence: strong for class identity, function boundaries, command dispatch, file persistence, vtable/resource evidence, and parent placement; medium for final field names and list-base helper names.
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md)
- Parent attachment: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) is `86/80` with projected path `NexusTK/login/`; this class is now attached because live IDA confirms it belongs to that phone-book/dial module.

## Class Purpose

`PhoneBookDialog` is the terminal phone-book manager. It loads contact entries from `PHONE.CFG`, manages add/edit/delete/dial actions, saves entries back to disk, and opens the dial dialog for the selected number.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PhoneBookDialog` | `0x0058c350-0x0058c9b5` | Builds the phone-book dialog and embedded list pane, installs PhoneBookDialog/ListPane vtables, loads `PHONE.CFG`, and initializes the terminal-phone UI assets. |
| `DialSelectedEntry` | `0x0058cb60-0x0058cc37` | Copies the selected contact, saves `PHONE.CFG`, closes the phone-book dialog, then creates `DialDialog`. |
| `UpdateButtonStates` | `0x0058cc40-0x0058cccc` | Enables edit/delete/dial based on whether the list has entries; vtable slot is at `0x0062db94`. |
| `OnCommand` | `0x0058ccd0-0x0058ce15` | Six-way command switch for save/close, add, edit, delete, and dial commands. |
| `SavePhoneBook` | `0x0058ce30-0x0058cec7`, [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) | Opens `PHONE.CFG` in write-text mode and writes each entry as formatted name/number lines. |
| selected-entry helper | [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) | Copies selected name/number fields from the list item and returns the entry flag byte; direct caller is `OnCommand` at `0x0058cd8c`. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms the real function starts and exclusive ends for the class core: constructor `0x0058c350-0x0058c9b5`, dial helper `0x0058cb60-0x0058cc37`, button-state slot `0x0058cc40-0x0058cccc`, command switch `0x0058ccd0-0x0058ce15`, and save helper `0x0058ce30-0x0058cec7`.
- The constructor installs PhoneBookDialog vtables `0x0062db48`, `0x0062dba8`, and `0x0062dbd8`; constructs the embedded PhoneBookListPane with vtables `0x0062dbe4`, `0x0062dc6c`, and `0x0062dc9c`; opens `PHONE.CFG` with mode `rt`; and references `NPAL8.PAL` plus `DLGTEL1.EPD`.
- `OnCommand` uses a six-entry jump table at `0x0058cd0b`: save calls `SavePhoneBook` at `0x0058cd12`, add/edit create `PhoneEntryDialog` at `0x0058cd5b` and `0x0058cdc2`, the edit path calls the selected-entry helper at `0x0058cd8c`, delete uses the list removal/refresh path, and dial calls `DialSelectedEntry` at `0x0058cdf4`.
- `DialSelectedEntry` copies the selected name and number with `_wcscpy_s`, calls `SavePhoneBook` at `0x0058cbdd`, closes the phone-book UI, and constructs `DialDialog` at `0x0058cc17`; `DialDialog` starts at `0x0058d750` after the `0x0058d74c-0x0058d750` padding and references the `ATX3DT` modem command string.
- `SavePhoneBook` opens `PHONE.CFG` with mode `wt`, calls the formatted wide-write helper `0x0058dcb0` twice per entry at `0x0058ce94` and `0x0058cea6`, then closes the file.
- The selected-entry helper `0x0058cfa0-0x0058cfdc` copies the selected row's name from offset `+2` and number from offset `+0x82`, returns the row flag byte, and has only one direct code caller, `PhoneBookDialog::OnCommand` at `0x0058cd8c`.
- Remaining uncertainty is limited to source-quality member names, list-base API naming, and exact contact-entry field naming, so final reconstruction C++ stays blank.

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md)
- [UID:0000AF][PhoneEntryDialog](by-class/PhoneEntryDialog.md)
- [UID:00003R][DialDialog](by-class/DialDialog.md)
- [UID:0000V7][PhoneBookListHelpers_58cfa0_58dcb0](by-item/PhoneBookListHelpers_58cfa0_58dcb0.md)
- [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md)
- [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite class purpose, method notes, helper ownership caveats, file persistence behavior, and cross-references.
- Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
- Evidence: constructor, dial/update/command/save methods, `PHONE.CFG` load/save behavior, selected-entry helper, formatted write helper, and generated owner-pollution caveats are documented; confidence stays medium-high because `SavePhoneBook` is not fully emitted and final helper ownership remains open.
- 2026-06-04: raised from `78/76` to `82/84`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md).
  - Summary/evidence: live IDA MCP confirms exact function boundaries, vtable installs, `PHONE.CFG` load/save modes, command-switch callsites, selected-entry helper body/caller, formatted-write helper callsites, PhoneEntryDialog construction, and DialDialog handoff; parent file [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) is already `86/80` with valid `NexusTK/login/` placement.
  - Remaining gaps: final C++ remains blank because contact field names, list-base helper names, and exact source-level member layout are not yet at the 95/95 threshold.
