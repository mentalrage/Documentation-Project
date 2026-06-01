*** UID:0000AD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PhoneBookDialog

## Status

- Confidence: strong for behavior, medium for final helper ownership.
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_PhoneBookDialog.cpp`

## Class Purpose

`PhoneBookDialog` is the terminal phone-book manager. It loads contact entries from `PHONE.CFG`, manages add/edit/delete/dial actions, saves entries back to disk, and opens the dial dialog for the selected number.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PhoneBookDialog` | `0x0058c350` | Builds the phone-book dialog, list pane, name/number controls, action buttons, and loads `PHONE.CFG`. |
| `DialSelectedEntry` | `0x0058cb60` | Copies the selected contact, saves and closes the dialog, then creates `DialDialog`. |
| `UpdateButtonStates` | `0x0058cc40` | Enables edit/delete/dial only when the list has entries. |
| `OnCommand` | `0x0058ccd0` | Handles save/close, add, edit, delete, and dial commands. |
| `SavePhoneBook` | `0x0058ce30`, [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) | Writes entries to `PHONE.CFG` as alternating name and number lines. |
| selected-entry helper | [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) | Copies selected name/number from the phone-book list; current direct caller is `OnCommand`. |

## Evidence Notes

- Wave3 has high-grade summaries for all five methods, but the emitted `SavePhoneBook` body is currently only a struct declaration. Treat this as source materialization debt.
- IDA decompilation of `SavePhoneBook` confirms it opens `PHONE.CFG` in wide text write mode, iterates the phone list, and writes name/number pairs through helper `0x0058dcb0`.
- Current `simroot_v2/class_PhoneBookListPane.cpp` now owns `0x0058cfa0` as `PhoneBookListPane::GetSelectedEntryData`, but `OnCommand` still uses a `ChattingColorListPane` cast and `ArticleListPane` delete/list helpers. Treat those local types as owner pollution.

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
