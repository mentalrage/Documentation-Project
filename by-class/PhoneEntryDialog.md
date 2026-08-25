*** UID:0000AF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

# PhoneEntryDialog

## Status

- Confidence: strong for class identity, source placement, exact method ranges, vtable/resource evidence, text-control validation, owner/add-edit fields, and add/update flow; medium-high for final inherited dialog/text-control API names.
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md)
- Generated recovery hint: `class_PhoneEntryDialog.cpp`; use only as a search/provenance hint, not as authority.
- Parent attachment: attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md), which is `87/86` with `NexusTK/login/` placement; this class is now `85/88` and the linked memory/file docs place it in the terminal phone-book module.
- Reconstruction status: no final C++ emitted. `m_ownerDialog` at `+0x26c`, `m_addMode` / `m_isNewEntry` at `+0x270`, and the name/number text-control roles are high-probability and accepted for documentation/first-draft child C++; exact inherited dialog/text-control API names and final member spellings remain below the 95+ source gate.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | Class role, owning source file, exact method ranges, terminal-phone ownership, repaired vtable/data child [UID:0003DS][0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData](by-memory/0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData.md), dialog resource construction, text-control validation, add/update dispatch, owner refresh/close flow, owner pointer/add-mode offsets, high-probability member names, and first-draft child-method direction are documented through linked IDA-backed pages. Remaining gaps are exact inherited base names, final text-control API names, and final C++ shape. |
| Confidence | 89 | Strong for class identity, source placement, exact contiguous method ranges, vptr stores, text-control/action behavior, owner/add-edit field roles, and terminal phone-book ownership from live IDA and linked docs; capped below near-final because exact member spellings and list/dialog APIs remain source-name candidates. |

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
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md) places the `PhoneEntryDialog` vtable family at `0x0062dca4-0x0062dd44` in the terminal/phone read-only-data block.
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) places `PhoneEntryDialog` beside `PhoneBookDialog`, `PhoneBookListPane`, and `DialDialog` in `login/PhoneBookDialog.cpp`.
- 2026-06-12 A004 live IDA MCP `trace_data_flow` ties [UID:0003DS][0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData](by-memory/0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData.md) to constructor stores at `0x0058d2d0` (`this+0`), `0x0058d2d6` (`this+0xa0`), and `0x0058d2e0` (`this+0xa4`).
- 2026-06-12 A004 live IDA MCP `analyze_function` on `0x0058d270` shows the constructor creates `DLGTEL2.EPD`, adds OK/cancel controls, creates name and number text controls with 128-character limits, sets default focus/OK/cancel control ids, and stores the owner dialog pointer at `this+0x26c` plus the add/edit mode byte at `this+0x270`. Offsets `0xa0`, `0xa4`, `0x26c`, and `0x270` are 160, 164, 620, and 624 bytes. Verified with `int_convert.py`.
- 2026-06-12 A004 live IDA MCP `analyze_function` on `0x0058d540` reads controls 3 and 4 and toggles control 1, matching the "OK enabled only when both text fields are non-empty" behavior.
- 2026-06-12 A004 live IDA MCP `analyze_function` on `0x0058d5a0` handles action id 1 by reading controls 3 and 4 into 63-wide-character buffers, then either appending a contact through the owner dialog when the `this+0x270` mode byte is set or updating the selected entry path when it is clear; action id 2 closes/cancels without contact mutation.
- 2026-06-12 A002 Batch 333 live IDA MCP `get_bytes` and `xrefs_to` reconfirm [UID:0003GW][0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings](by-memory/0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings.md) as the exact UTF-16 `DLGTEL2.EPD` child for this class, with only two direct xrefs at `0x0058d314` and `0x0058d499` inside the constructor/setup function `0x0058d270`.
- B007's 2026-06-19 source-quality pass resolves the field-role open questions to high-probability names: `m_ownerDialog` at `+0x26c`, `m_addMode` / `m_isNewEntry` at `+0x270`, and name/number edit-control members for controls 3 and 4. These names are strong enough for documentation and first-draft child C++ but should keep the class below 95+ until inherited dialog/control APIs are finalized.

## Touched State And Dependencies

| State or dependency | Use |
| --- | --- |
| [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md) | Modal parent / terminal phone-book ownership signal. |
| `DLGTEL2.EPD` | Dialog resource for the add/edit contact UI. |
| [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md) | Receives inserted or updated contact rows after OK. |
| [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md) | Owner dialog refreshes list/button state after contact changes. |
| `m_nameEdit` and `m_numberEdit` text-control members | Constructor creates the two editable fields as controls 3 and 4 with 128-character limits; update/action slots read them, and both must contain text before OK/control 1 is enabled. Names are high-probability/descriptive. |
| `m_ownerDialog` at `this+0x26c` | Stored by the constructor and consumed by the OK action path to mutate/refresh the owning phone-book dialog. Offset is 620 bytes. Verified with `int_convert.py`. |
| `m_addMode` / `m_isNewEntry` byte at `this+0x270` | Stored by the constructor and branches the OK action between append and selected-entry update paths. Offset is 624 bytes. Verified with `int_convert.py`. |
| [UID:0003DS][0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData](by-memory/0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData.md) | Direct generated vtable/RTTI child for this class. |
| [UID:0003GW][0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings](by-memory/0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings.md) | Direct source-authored resource-string child for this class's `DLGTEL2.EPD` dialog layout. |

## First-Draft Readiness

`UpdateButtonState` and `OnDialogAction` are first-draft-ready for exact child pages using `m_nameEdit`, `m_numberEdit`, `m_ownerDialog`, `m_addMode`/`m_isNewEntry`, and `PhoneBookContactEntry`. `UpdateButtonState` enables OK only when both edit controls are non-empty. `OnDialogAction` action id 1 reads controls 3 and 4 into 63-wide-character buffers, appends a zero-flag contact in add mode or replaces the selected entry in edit mode, refreshes the owner phone-book dialog, and closes; action id 2 cancels/closes. Keep class-level C++ blank until inherited dialog/text-control method names and base declarations are coordinated.

## Remaining Follow-Up

- Finalize exact original member spelling for `m_nameEdit`, `m_numberEdit`, `m_ownerDialog`, and `m_addMode` / `m_isNewEntry`.
- Coordinate inherited dialog/text-control API declarations before raising this class toward final C++ audit.

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md)
- [UID:0003DS][0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData](by-memory/0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData.md)
- [UID:0003GW][0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings](by-memory/0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings.md)
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
- 2026-06-12 A004 Batch 291: raised from `80/86` to `85/88`.
  - Summary/evidence: live IDA MCP tied the repaired direct vtable child [UID:0003DS][0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData](by-memory/0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData.md) to constructor vptr stores, verified the `DLGTEL2.EPD` construction and text-control layout, documented owner pointer/add-edit mode offsets, and connected the update/action virtual slots to OK validation and add/update behavior.
  - Routing impact: this class now clears the strict `85/85` direct-parent gate for [UID:0003DS][0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData](by-memory/0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData.md). Final C++ remains blank because source-quality member/list API names are still unresolved.
- 2026-06-12 Agent-A002 Batch 333:
  - Added [UID:0003GW][0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings](by-memory/0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings.md) as the direct resource-string child after live IDA reconfirmed exact bytes, constructor-only xrefs, and the `DialDialog` successor boundary.
  - Routing impact: [UID:0003GW][0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings](by-memory/0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings.md) is now assigned to this class because child `88/93` and parent `85/88` clear the strict gate.
- 2026-06-21 B007 Rule 26 incorporation:
  - Raised `85/88 -> 86/89`, accepted high-probability names for owner dialog, add/edit mode, and name/number edit controls, added first-draft child-method readiness for `UpdateButtonState` and `OnDialogAction`, and narrowed remaining blockers to final inherited API/member spelling rather than unresolved behavior.
