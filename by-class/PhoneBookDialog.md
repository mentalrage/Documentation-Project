*** UID:0000AD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PhoneBookDialog

## Status

- Confidence: strong for class identity, function boundaries, command dispatch, file persistence, vtable/resource evidence, and parent placement; medium-high for final class field names and shared list-base helper declarations.
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md)
- Parent attachment: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) is `87/86` with projected path `NexusTK/login/`; this class is attached because live IDA confirms it belongs to that phone-book/dial module.

## Class Purpose

`PhoneBookDialog` is the terminal phone-book manager. It loads contact entries from `PHONE.CFG`, manages add/edit/delete/dial actions, saves entries back to disk, and opens the dial dialog for the selected number.

Its constructor begins at `0x0058c350`, immediately after `TerminalSetupPane::OnCommand` ends. B006 `TerminalPaneAndSetup` recheck confirms this as the exact successor boundary; do not merge the phone-book constructor into the terminal/setup aggregate.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PhoneBookDialog` | `0x0058c350-0x0058c9b5` | Builds the phone-book dialog and embedded list pane, installs PhoneBookDialog/ListPane vtables, loads `PHONE.CFG`, and initializes the terminal-phone UI assets. |
| `AppendPhoneBookEntry` / `AddPhoneBookEntry` | `0x0058c9c0-0x0058ca63` | Retained no-direct-xref wrapper that builds/inserts a `PhoneBookContactEntry` through the embedded list pane and refreshes dialog state. Name is descriptive/high-probability rather than original-proof. |
| `ReplaceSelectedPhoneBookEntry` | `0x0058ca70-0x0058cb2e` | Retained no-direct-xref wrapper that replaces the currently selected contact row with flag/name/number arguments. |
| `RemoveSelectedPhoneBookEntry` / `DeleteSelectedEntry` | `0x0058cb30-0x0058cb5d` | Retained no-direct-xref wrapper that removes the selected row and refreshes button/list state. |
| `DialSelectedEntry` | `0x0058cb60-0x0058cc37` | Copies the selected contact, saves `PHONE.CFG`, closes the phone-book dialog, then creates `DialDialog`. |
| `UpdateButtonStates` | `0x0058cc40-0x0058cccc` | Enables edit/delete/dial based on whether the list has entries; vtable slot is at `0x0062db94`. |
| `OnCommand` | `0x0058ccd0-0x0058ce15` | Six-way command switch for save/close, add, edit, delete, and dial commands. |
| `SavePhoneBook` | `0x0058ce30-0x0058cec7` | Opens `PHONE.CFG` in write-text mode and writes each entry as formatted name/number lines through normal CRT-style wide file output. [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) is now documented as runtime glue rather than a PhoneBook-owned source method. |
| selected-entry helper use | [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) | `OnCommand` edit path calls `PhoneBookListPane::GetSelectedEntryData`; the direct source owner is [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md). |

## Vtable Evidence

| Range | Evidence | Interpretation |
| --- | --- | --- |
| [UID:0003DQ][0x0062db48-0x0062dbe4.PhoneBookDialogVtableData](by-memory/0x0062db48-0x0062dbe4.PhoneBookDialogVtableData.md) | A001 Batch 289 live IDA `trace_data_flow` confirms constructor stores at `0x0058c399`, `0x0058c3a5`, and `0x0058c3b2`, plus primary slots `0x0062db90 -> 0x0058ccd0` and `0x0062db94 -> 0x0058cc40`. | Exact class vtable child; assigned here after this page and the file parent clear the strict gate. |
| `0x0062dbe4` successor | Live IDA traces `0x0062dbe4` as `PhoneBookListPane` vtable data with stores at `0x0058c443` and `0x0058cefe`. | Confirms the upper bound of the PhoneBookDialog vtable child and prevents merging it with the list pane table. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms the real function starts and exclusive ends for the class core: constructor `0x0058c350-0x0058c9b5`, dial helper `0x0058cb60-0x0058cc37`, button-state slot `0x0058cc40-0x0058cccc`, command switch `0x0058ccd0-0x0058ce15`, and save helper `0x0058ce30-0x0058cec7`.
- The constructor installs PhoneBookDialog vtables `0x0062db48`, `0x0062dba8`, and `0x0062dbd8`; constructs the embedded PhoneBookListPane with vtables `0x0062dbe4`, `0x0062dc6c`, and `0x0062dc9c`; opens `PHONE.CFG` with mode `rt`; and references `NPAL8.PAL` plus `DLGTEL1.EPD`.
- `OnCommand` dispatches through a local six-entry switch table at `0x0058ce18-0x0058ce30` after a three-byte `0f 1f 00` alignment nop at `0x0058ce15`. The six case targets are `0x0058cd12`, `0x0058cd19`, `0x0058cd2a`, `0x0058cd65`, `0x0058cdc9`, and `0x0058cdf4`; save calls `SavePhoneBook`, add/edit create `PhoneEntryDialog`, the edit path calls the selected-entry helper at `0x0058cd8c`, delete uses the list removal/refresh path, and dial calls `DialSelectedEntry`.
- `DialSelectedEntry` copies the selected name and number with `_wcscpy_s`, calls `SavePhoneBook` at `0x0058cbdd`, closes the phone-book UI, and constructs `DialDialog` at `0x0058cc17`; `DialDialog` starts at `0x0058d750` after the `0x0058d74c-0x0058d750` padding and references the `ATX3DT` modem command string.
- `SavePhoneBook` opens `PHONE.CFG` with mode `wt`, writes name/number lines twice per entry at `0x0058ce94` and `0x0058cea6`, then closes the file. B001's 2026-06-17 source-quality pass reclassifies callee `0x0058dcb0` as a static MSVC/UCRT `fwprintf`-style wrapper, so handwritten `PhoneBookDialog` source should use normal CRT formatted output rather than owning that helper body.
- The selected-entry helper `0x0058cfa0-0x0058cfdc` copies the selected row's name from offset `+2` and number from offset `+0x82`, returns the row flag byte, and has only one direct code caller, `PhoneBookDialog::OnCommand` at `0x0058cd8c`. B001's 2026-06-17 pass routes it directly to [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md) as `PhoneBookListPane::GetSelectedEntryData`.
- B007's 2026-06-19 source-quality pass confirms retained dialog wrappers at `0x0058c9c0`, `0x0058ca70`, and `0x0058cb30` are source-authored no-direct-xref methods rather than padding or compiler glue. They have normal method bodies and phone-book-specific row construction/update behavior, so the class should document them with descriptive names instead of leaving `sub_`/compiler-generated labels.
- The best source-facing field name for the dialog's embedded list pointer is `m_phoneBookList` at `PhoneBookDialog+0x1fc`. This is inferred from list construction, command dispatch, selected-entry access, and add/replace/remove/save forwarding, but the exact original member spelling remains below final audit.
- 2026-06-12 A001 Batch 289 live IDA MCP revalidated the same class responsibilities: constructor `sub_58C350` installs the three `PhoneBookDialog` vtables, constructs a `PhoneBookListPane`, and opens `PHONE.CFG` in `rt` mode; `OnCommand` dispatches six actions, including save/close, add/edit `PhoneEntryDialog`, delete, and dial; `SavePhoneBook` opens `PHONE.CFG` in `wt` mode and writes name/number records; and `DialSelectedEntry` saves, closes the dialog, and constructs `DialDialog`.
- Remaining uncertainty is limited to exact original member spelling, shared list-base API naming, and inherited dialog/base declarations. The contact-entry type, selected-entry helper ownership, retained wrapper roles, and source direction for `SavePhoneBook`/dialog command flow are no longer open.

## First-Draft Readiness

`SavePhoneBook`, `DialSelectedEntry`, `UpdateButtonStates`, `AppendPhoneBookEntry`, `ReplaceSelectedPhoneBookEntry`, and `RemoveSelectedPhoneBookEntry` are first-draft-ready once exact child pages or accepted method-level emitters exist. Drafts should use `m_phoneBookList`, `PhoneBookContactEntry`, normal CRT `fwprintf(file, L"%s\n", value)` output, and descriptive shared-list names such as `GetEntryCount`, `GetEntryAt`, `AppendEntry`, `ReplaceSelectedEntryData`, and `RemoveSelectedEntry`. These helper names are accepted for documentation/draft code but should keep the page below 95+ until a broader `ListPane` API pass finalizes original spellings.

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md)
- [UID:0000AF][PhoneEntryDialog](by-class/PhoneEntryDialog.md)
- [UID:00003R][DialDialog](by-class/DialDialog.md)
- [UID:0000V7][PhoneBookListHelpers_58cfa0_58dcb0](by-item/PhoneBookListHelpers_58cfa0_58dcb0.md)
- [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md)
- [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md)
- [UID:0003DQ][0x0062db48-0x0062dbe4.PhoneBookDialogVtableData](by-memory/0x0062db48-0x0062dbe4.PhoneBookDialogVtableData.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite class purpose, method notes, helper ownership caveats, file persistence behavior, and cross-references.
- Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
- Evidence: constructor, dial/update/command/save methods, `PHONE.CFG` load/save behavior, selected-entry helper, formatted write helper, and generated owner-pollution caveats are documented; confidence stays medium-high because `SavePhoneBook` is not fully emitted and final helper ownership remains open.
- 2026-06-04: raised from `78/76` to `82/84`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md).
  - Summary/evidence: live IDA MCP confirms exact function boundaries, vtable installs, `PHONE.CFG` load/save modes, command-switch callsites, selected-entry helper body/caller, formatted-write helper callsites, PhoneEntryDialog construction, and DialDialog handoff; parent file [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) is already `86/80` with valid `NexusTK/login/` placement.
  - Remaining gaps: final C++ remains blank because contact field names, list-base helper names, and exact source-level member layout were not yet source-quality.
- 2026-06-12 Agent-A001 Batch 289: Raised `82/84 -> 86/88` using live IDA MCP evidence for the class vtable child [UID:0003DQ][0x0062db48-0x0062dbe4.PhoneBookDialogVtableData](by-memory/0x0062db48-0x0062dbe4.PhoneBookDialogVtableData.md), constructor/list-pane creation and `PHONE.CFG` load, `OnCommand` action dispatch, `SavePhoneBook` write loop, `DialSelectedEntry` handoff, and the `PhoneBookListPane` successor boundary. Class-level C++ remained blank pending source-quality method/field/list helper names.
- 2026-06-17 B001 source-quality execution: moved selected-entry helper source ownership to [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md), resolved `PhoneBookContactEntry` field names for the selected-entry path, and reclassified [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) as CRT/runtime formatted-output glue. `SavePhoneBook` source should emit normal formatted file writes, not a PhoneBook-owned wrapper body.
- 2026-06-21 B006 TerminalPane boundary sync: added the exact `0x0058c350` successor-boundary note from [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md). Score unchanged.
- 2026-06-21 B007 Rule 26 incorporation: raised `86/88 -> 88/89`, added retained wrapper methods at `0x0058c9c0`, `0x0058ca70`, and `0x0058cb30`, recorded the `0x0058ce18-0x0058ce30` switch table, accepted `m_phoneBookList` as the high-probability embedded list pointer name, and documented first-draft method readiness without populating aggregate/class C++.
