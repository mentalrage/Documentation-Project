*** UID:0000AE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PhoneBookListPane

## Status

- Confidence: strong for ownership, medium for emitted source completeness.
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_PhoneBookListPane.cpp`

## Class Purpose

`PhoneBookListPane` displays terminal phone-book contacts and forwards selected-entry activation back to the owning `PhoneBookDialog`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetSelectedEntryData` | [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) | Copies selected contact name/number from the list entry and returns the entry flag byte. |
| `DialSelectedEntry` | `0x0058d110` | Forwards activation/dial request to the owned phone-book dialog. |
| `RenderEntry` | `0x0058d120` | Draws the selected highlight and two contact columns from the entry name/number fields. |

## Evidence Notes

- Current `simroot_v2/class_PhoneBookListPane.cpp` emits [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) at `0x0058cfa0`, but `PhoneBookDialog::OnCommand` still calls the same helper through a polluted `ChattingColorListPane` cast.
- `RenderEntry` is still only a packed struct declaration in the emitted file.
- IDA decompilation of `RenderEntry` confirms the row payload fields at `+0x02` and `+0x82`, ellipsis truncation, palette setup, selected-row highlight, and two-column text drawing.
- The list pane should migrate with `PhoneBookDialog`, not with generic chat or article list code.
- [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md) now records the complete phone-book block as reconstructable `84/84`, attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md), with rows for `PhoneBookListPane::DialSelectedEntry` at `0x0058d110-0x0058d11a` and `PhoneBookListPane::RenderEntry` at `0x0058d120-0x0058d262`.
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) has a valid `NexusTK/login/` projected path and treats `PhoneBookListPane` as part of `login/PhoneBookDialog.cpp`, alongside `PhoneBookDialog`, `PhoneEntryDialog`, and `DialDialog`.
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md) places the `PhoneBookListPane` vtable family in the terminal/phone read-only-data block, between `PhoneBookDialog` and `PhoneEntryDialog`.

## Autogen Status

Attach this class to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) as reconstructable terminal phone-book metadata. Leave C++ blank because `RenderEntry`, list-base APIs, selected-entry field names, and stale generated casts are not final-source quality.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `76` | The page records class role, exact selected-entry/dial/render methods, parent source module, row-field/render behavior, generated owner pollution, vtable-block evidence, and no-code autogen handling. Completion remains capped by incomplete emitted render/save bodies and unresolved list-entry field names. |
| Confidence `84` | Phone-book ownership is strongly supported by the high-confidence PhoneBookDialog file page, the exact phone-book aggregate, selected-entry helper caller evidence, and terminal/phone read-only vtable placement. Confidence is not higher because the emitted list-pane source still has incomplete/polluted bodies. |

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000V7][PhoneBookListHelpers_58cfa0_58dcb0](by-item/PhoneBookListHelpers_58cfa0_58dcb0.md)
- [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md)
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md)

## Changes

- 2026-06-02:
  - Before: scored `68/72`, reconstructability and parent blank.
  - After: scored `76/84`, marked reconstructable, and attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) with C++ blank.
  - Why: exact phone-book aggregate, selected-entry helper, terminal/phone vtable data, and the high-confidence parent file now prove login phone-book ownership while incomplete generated bodies still block source emission.
- Before: completion/confidence metadata were `0/0` despite selected-entry helper, activation, render behavior, and generated owner-pollution notes.
- Changed to: `COMPLETION:68` and `CONFIDENCE:72`.
- Evidence: selected contact copying, dial forwarding, render-entry behavior, row payload fields, and placement with `PhoneBookDialog` are documented; completion/confidence remain moderate because emitted `RenderEntry` is incomplete and helper owner pollution still needs cleanup.
