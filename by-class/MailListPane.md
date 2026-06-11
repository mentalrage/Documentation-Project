*** UID:00007M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Parent routing: assigned to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) under the corrected gate after Batch 125; this class is `85/86` and the direct file parent is `86/85`.

## Class Purpose

`MailListPane` is the list component used by `MailListDialog`. It displays mail entries with sender, date, subject, selection highlighting, and scroll-triggered lazy-load behavior.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MailListPane` | `0x0047a8a0-0x0047a8f9` | Initializes the `ListPane` base with item height and mail type, then writes all three `MailListPane` vtable views. |
| `AddOrUpdateMailEntry` | `0x0047a900-0x0047a9de` | Builds a local row record, updates an existing mail-id row when present, or inserts the row in sorted position. |
| `RequestOlderMailIfNeeded` | `0x0047ac30-0x0047ac88` | Checks the current first row and sends a lazy-load request when the list can page backward. |
| `FindMailIdIndex` | `0x0047acd0-0x0047ad13` | Linear search over list rows for a mail id, returning `-1` when absent. |
| `OnScrollChanged` | `0x0047ad80-0x0047add5` | Delegates to the base scroll handler and triggers lazy-load when the top/bottom condition is reached. |
| `OnItemSelected` | `0x0047ade0-0x0047ae29` | Delegates to the base selection handler and triggers lazy-load when the final row is selected. |
| `GetSelectedMailId` | `0x0047ae30-0x0047ae43` | Retrieves the selected row object through virtual dispatch and extracts the mail id through the mail-list dialog helper. |
| `DrawEntry` | `0x0047ae50-0x0047b071` | Draws one mail list row with selection coloring, id, sender/subject truncation, and unread/count text. |
| local page-request helper | `0x0047b080-0x0047b110` | `__stdcall` helper shared by this pane and a mail-dialog path; builds and queues the request packet used for lazy mail paging. |

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-06-08 confirms the compact MailListPane island: `0x0047a8a0` size `0x59`, `0x0047a900` size `0xde`, `0x0047ac30` size `0x58`, `0x0047acd0` size `0x43`, `0x0047ad80` size `0x55`, `0x0047ade0` size `0x49`, `0x0047ae30` size `0x13`, `0x0047ae50` size `0x221`, and local packet helper `0x0047b080` size `0x90`; `0x0047b110` is not a function start.
- IDA MCP `callers` on 2026-06-08 confirms the constructor is called only from the mail-list dialog initializer `sub_479110` at `0x00479273` and `0x00479815`, while the add/update helper is called from `sub_479110` and the mail-list update path `sub_47A520`.
- The constructor writes the three `MailListPane` vtable views: primary `0x006142d8` at `0x0047a8d1`, secondary `0x00614360` at `0x0047a8d7`, and tertiary `0x00614390` at `0x0047a8e1`.
- IDA data refs tie virtual slots back to this class: `0x00614364 -> 0x0047ad80`, `0x00614368 -> 0x0047ade0`, `0x00614354 -> 0x0047ae30`, and `0x00614358 -> 0x0047ae50`.
- Decompilation on 2026-06-08 shows `AddOrUpdateMailEntry` copies two 256-wide-character fields into a row record and inserts by mail id, `RequestOlderMailIfNeeded` calls the local packet helper with the pane mail-type field and previous id, `DrawEntry` formats the id (`"%5d"`), count (`"%2d/%2d"`), and truncated sender/subject strings, and the scroll/selection handlers trigger lazy paging only when their base handler succeeds.
- This pane is tightly coupled to mail list records, constructor call sites, vtable data, and the mail-list dialog helper surface, so it should migrate with [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), not as a standalone source file.

## Assignment Gate

Direct parent assignment is now justified. The child page reaches `85/86` after live IDA method, caller, vtable, and decompilation evidence was added. The direct file parent [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) is already `86/85` and documents this same mail-dialog family, vtable group, and `0x00479110-0x0047ec2b` memory aggregate. `AUTOGEN_PARENT_UID` is therefore set to `0000KZ`.

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:00007L][MailListDialog](by-class/MailListDialog.md)

## Changes

- 2026-06-05: Marked reconstructable because live IDA MCP confirms the mail list pane constructor, scroll/selection helpers, selected-mail lookup, and row draw function are NexusTK-owned UI/mail behavior. Kept `AUTOGEN_PARENT_UID` blank because this class is `78/82`, below the 80/80 parent-attachment gate, even though [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) is the likely owner. Live IDA MCP evidence: `lookup_funcs` confirms starts at `0x0047a8a0`, `0x0047ad80`, `0x0047ade0`, `0x0047ae30`, and `0x0047ae50`; `callers` confirms the constructor is called from `0x00479273` and `0x00479815` inside `sub_479110`.
- Completion/confidence score update: existed before as `0/0`; changed to `78/82`. Summary: the mail list component has purpose, constructor, scroll/load, selection, selected-id, draw-entry, and module-placement documentation, but row data layout and final C++ detail are not exhaustive. Evidence: linked mail-dialog range, IDA-confirmed constructor/draw boundaries, `MailListDialog` relationship, and lazy-load behavior.
- 2026-06-08 A009 Batch 125:
  - Changed score from `78/82` to `85/86`.
  - Set `AUTOGEN_PARENT_UID:0000KZ` because this page and the direct [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) parent both satisfy the corrected `85/85` gate.
  - Added live IDA MCP evidence for all nine local functions/helpers, constructor/list-update callers, three vtable stores, key virtual-slot data refs, sorted row insertion, lazy-page request behavior, and row drawing.
  - Final C++ remains blank because field names, complete row struct declaration, and source-quality method signatures are still below the `95/95` emission gate.
