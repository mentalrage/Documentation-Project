*** UID:0000AF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PhoneEntryDialog

## Status

- Confidence: strong
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md)
- Generated recovery hint: `class_PhoneEntryDialog.cpp`; use only as a search/provenance hint, not as authority.
- Parent attachment: attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md), which is `86/80` with `NexusTK/login/` placement; this class is now `80/86` and the linked memory/file docs place it in the terminal phone-book module.
- Reconstruction status: no final C++ emitted. Contact-entry fields, text-control member names, add/edit mode state, and exact list API names are still below the 95+ source gate.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 80 | Class role, owning source file, exact method ranges, terminal-phone ownership, vtable/data island, add/edit behavior, validation rule, and owner-list refresh flow are documented through linked IDA-backed pages. Remaining gaps are member/field names, exact text-control slots, add/edit mode representation, and final C++ shape. |
| Confidence | 86 | Strong for class identity, source placement, exact contiguous method ranges, and terminal phone-book behavior from existing IDA-backed docs; capped below near-final because field layout and list/contact APIs remain source-name candidates. |

## Class Purpose

`PhoneEntryDialog` is the add/edit dialog for a terminal phone-book contact. It presents name and number text fields, validates that both are non-empty, then inserts or updates the selected phone-book list entry.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PhoneEntryDialog` | `0x0058d270-0x0058d536` | Builds `DLGTEL2.EPD` dialog with OK/cancel buttons and name/number text controls. |
| `UpdateButtonState` | `0x0058d540-0x0058d59e` | Enables OK only when both name and number fields contain text. |
| `OnDialogAction` | `0x0058d5a0-0x0058d74c` | Reads text controls, updates or inserts the list entry, refreshes the owner phone book, and closes. |

## Evidence Notes

- The dialog is shown over `g_pTerminalPane`, which ties it to the terminal phone-book feature rather than a generic profile or social dialog.
- [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md) records exact method ranges: constructor `0x0058d270-0x0058d536`, `UpdateButtonState` `0x0058d540-0x0058d59e`, and `OnDialogAction` `0x0058d5a0-0x0058d74c`.
- The same memory page records the end boundary: `PhoneEntryDialog::OnDialogAction` ends at `0x0058d74c`, followed by a four-byte `0xcc` alignment gap before [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md).
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md) places the `PhoneEntryDialog` vtable family at `0x0062dca8-0x0062dd44` in the terminal/phone read-only-data block.
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) places `PhoneEntryDialog` beside `PhoneBookDialog`, `PhoneBookListPane`, and `DialDialog` in `login/PhoneBookDialog.cpp`.

## Touched State And Dependencies

| State or dependency | Use |
| --- | --- |
| [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md) | Modal parent / terminal phone-book ownership signal. |
| `DLGTEL2.EPD` | Dialog resource for the add/edit contact UI. |
| [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md) | Receives inserted or updated contact rows after OK. |
| [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md) | Owner dialog refreshes list/button state after contact changes. |
| Name and number text controls | Both must contain text before OK is enabled. Exact member names and offsets remain open. |

## Open Questions

- Resolve source-quality names and offsets for the name text control, number text control, owner dialog/list pointer, and add-vs-edit state.
- Confirm the contact entry structure used by the list row update/insert path and align names with [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md).
- Keep final C++ blank until the text-control member layout and list API calls are documented at source quality.

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md)
- [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md)
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md)
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: reconstruction autogen classification was blank even though the page documents a NexusTK phone-book edit dialog and its constructor, validation, and action methods.
  - After: classified as reconstructable source but intentionally unassigned.
  - Evidence: live IDA MCP `lookup_funcs` confirms modeled starts at `0x0058d270`, `0x0058d540`, and `0x0058d5a0`; existing [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) evidence places this in the phone-book dialog module. Parent attachment is deferred because the class has `COMPLETION:72`, below the 80/80 attach gate.

- Before: completion/confidence metadata were `0/0` even though the page already documented role, method boundaries, validation behavior, terminal ownership, and contiguous IDA range evidence.
- Changed to: `COMPLETION:72` and `CONFIDENCE:84`.
- Evidence: constructor, OK-enable validation, action handler, `DLGTEL2.EPD` controls, `g_pTerminalPane` ownership, and IDA-confirmed range are documented; remaining gaps are detailed field layout and reconstructed C++.
- 2026-06-07: raised from `72/84` to `80/86` and attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md).
  - Summary/evidence: existing IDA-backed docs now give exact constructor/update/action ranges, the `0x0058d74c` exclusive end plus alignment before `DialDialog`, terminal-phone vtable placement, `g_pTerminalPane` ownership, and source-file placement under `login/PhoneBookDialog.cpp`.
  - Remaining gaps: final C++ stays blank because text-control fields, add/edit state, contact-entry structure, and list API names are not yet final-source quality.
