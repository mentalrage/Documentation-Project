*** UID:00007M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MailListPane

## Status

- Confidence: strong for behavior and mail-dialog module placement.
- Likely source file: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- Address range: [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MailListPane.cpp`

## Class Purpose

`MailListPane` is the list component used by `MailListDialog`. It displays mail entries with sender, date, subject, selection highlighting, and scroll-triggered lazy-load behavior.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MailListPane` | `0x0047a8a0-0x0047a8f8` | Initializes the `ListPane` base with item height and mail type. |
| `OnScrollChanged` | `0x0047ad80-0x0047add4` | Requests more mail when scrolled to the bottom. |
| `OnItemSelected` | `0x0047ade0-0x0047ae28` | Handles selection and bottom-of-list load. |
| `GetSelectedMailId` | `0x0047ae30-0x0047ae42` | Retrieves selected mail ID through parent context. |
| `DrawEntry` | `0x0047ae50-0x0047b070` | Draws one mail list row with truncation and highlighting. |

## Evidence Notes

- IDA MCP confirms constructor and row draw boundaries.
- This pane is tightly coupled to mail list records and should migrate with mail dialogs.

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:00007L][MailListDialog](by-class/MailListDialog.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/82`. Summary: the mail list component has purpose, constructor, scroll/load, selection, selected-id, draw-entry, and module-placement documentation, but row data layout and final C++ detail are not exhaustive. Evidence: linked mail-dialog range, IDA-confirmed constructor/draw boundaries, `MailListDialog` relationship, and lazy-load behavior.
