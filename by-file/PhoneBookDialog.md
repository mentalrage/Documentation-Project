*** UID:0000MJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PhoneBookDialog

## Status

- Confidence: strong for phone-book/dial feature ownership, medium for final split from `TerminalPane.cpp`.
- Proposed module: `login/PhoneBookDialog.cpp`
- Current recovered sources: `class_PhoneBookDialog.cpp`, `class_PhoneBookListPane.cpp`, `class_PhoneEntryDialog.cpp`, `class_DialDialog.cpp`
- Evidence basis: IDA MCP boundary checks, current documentation cross-references, and generated-source caveats. Generated source is used only as a hint where IDA-backed docs corroborate behavior.

## File Role

`PhoneBookDialog.cpp` owns the terminal phone book UI: persistent `PHONE.CFG` loading/saving, phone-book list rendering, add/edit entry dialog, and modem dialing dialog. The code is tightly tied to `TerminalPane` because `PhoneEntryDialog` and `DialDialog` are shown over `g_pTerminalPane`, and `DialDialog` sends modem command strings through the same packet sender path.

The most likely original placement is a sibling file near `TerminalPane.cpp`:

```text
login/PhoneBookDialog.cpp
login/PhoneBookDialog.h
```

An alternate original layout is one larger terminal source file containing both terminal setup and phone-book support.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `PhoneBookDialog` | `0x0058c350-0x0058cec6` plus [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) | Main phone-book dialog, `PHONE.CFG` load/save, add/edit/delete/dial/close command handling, and button state updates. |
| `PhoneBookListPane` | `0x0058d110-0x0058d263`, [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) | Contact list pane activation, selected-entry extraction, and contact row rendering. |
| `PhoneEntryDialog` | `0x0058d270-0x0058d74c` | Modal add/edit dialog with name and number text fields. |
| `DialDialog` | `0x0058d750-0x0058dc5b`, [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md), [UID:0001JJ][0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks](by-memory/0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks.md) | Dial-in-progress dialog that sends cleanup/connect and `ATX3DT` modem command sequence. |
| Terminal singleton clear helper | [UID:0001JI][0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md) | Constructor EH cleanup that clears `g_pTerminalPane`; recorded in the dial/terminal thunk island but ignored for source reconstruction. |

## Key Behavior

- `PhoneBookDialog` loads alternating name/number lines from `PHONE.CFG` into the list pane and writes the same format back through `SavePhoneBook`.
- `OnCommand` handles save/close, add, edit, delete, and dial actions. Add/edit constructs `PhoneEntryDialog`; dial saves and closes the phone book before constructing `DialDialog`.
- `PhoneEntryDialog` updates or inserts a list entry, then refreshes the owner phone-book dialog.
- `DialDialog` converts the selected wide phone number to multibyte text and sends modem dialing commands through the packet sender.

## Evidence Notes

- IDA MCP confirms the phone-book block at `0x0058c350-0x0058d74c` and the dial block at `0x0058d750-0x0058dc5b`.
- 2026-05-26 IDA recheck: [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) has only one direct caller, `PhoneBookDialog::OnCommand` at `0x0058cd8c`; [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) is called from `SavePhoneBook` and the nearby phone-list rendering area.
- Current emitted source is incomplete for `PhoneBookDialog::SavePhoneBook` and `PhoneBookListPane::RenderEntry`; use method summaries and IDA boundaries rather than the emitted bodies for those rows.
- Current `simroot_v2/class_PhoneBookListPane.cpp` now emits `0x0058cfa0` as `PhoneBookListPane::GetSelectedEntryData`, but `PhoneBookDialog::OnCommand` still calls it through a `ChattingColorListPane` cast and delete/list helpers through `ArticleListPane`. Treat those local types as owner pollution until list-base relationships are reviewed.

## Cross-References

- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md)
- [UID:0000AF][PhoneEntryDialog](by-class/PhoneEntryDialog.md)
- [UID:00003R][DialDialog](by-class/DialDialog.md)
- [UID:0000V7][PhoneBookListHelpers_58cfa0_58dcb0](by-item/PhoneBookListHelpers_58cfa0_58dcb0.md)
- [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md)
- [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md)
- [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md)
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md)
- [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md)
- [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md)
- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents phone-book/dial feature ownership, class grouping, behavior, IDA boundary evidence, current generated-source caveats, TerminalPane relationship, and cross-references; confidence remains capped by final split from `TerminalPane.cpp`.
- 2026-06-01: `PROPOSED_RECONSTRUCTION_PATH` changed from blank to `NexusTK/login/`.
  - Summary/evidence: the page already proposed `login/PhoneBookDialog.cpp`; [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `PhoneBookDialog.cpp` in the login family; sibling pre-login dialog files use the same projected path.
