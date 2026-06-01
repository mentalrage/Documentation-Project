*** UID:0000FN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserListDialogPane

## Status

- Confidence: strong for class purpose, medium for generated source quality.
- Likely source file: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- Address range: [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- Current recovered file: `source-3/simroot_v2/class_UserListDialogPane.cpp`

## Class Purpose

`UserListDialogPane` is the main users dialog. It builds high-resolution or low-resolution dialog layouts, parses the initial user-list packet into fixed-size user records, distributes users into five visible list panes, sorts by name or status, filters by category/career, handles selected-user packet updates, and dispatches UI commands.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0059bc90-0x0059d198` | Constructs high/low-res dialog controls, creates five `UserListPane` children, parses user rows, populates buckets, and initializes labels/counts. |
| `SortListsByName` | `0x0059d1f0-0x0059d24f` | Sorts all five category list panes by user name. |
| `SortListsByStatus` | `0x0059d250-0x0059d2af` | Sorts all five category list panes by status. |
| `RefreshCategoryView` | `0x0059d2b0-0x0059d5fe` | Steps the category filter, redistributes users into buckets, sorts current lists, updates counts and labels. |
| `HandleUserListPacket` | `0x0059d620-0x0059d8f5` | Handles selected-flag sync and source-text updates from network packets. |
| `OnKeyEvent` | `0x0059d900-0x0059da82` | Handles Page Up/Page Down category changes and Ctrl+C copy of selected names. |
| `OnControlCommand` | `0x0059da90-0x0059dbe3` | Handles close, sort-mode change, category step, party-search dialog open, and show-hidden toggle. |
| adjustor thunks | `0x0059f017-0x0059f02d` | User-list dialog destructor adjustors. |
| scalar deleting destructor | `0x0059f110-0x0059f181` | Destroys owned scroll/list state, tears down base dialog, clears singleton, and optionally deletes. |

## Related Local Classes

- [UID:0000FO][UserListPane](by-class/UserListPane.md) implements the repeated list control used by this dialog.
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md) is opened by `OnControlCommand(20)`.
- `AddUserListSourceMessage_59DE60` is a local helper called by packet and double-click/source display paths.

## Data Notes

- `g_pUserListDialogPane` is the active dialog singleton.
- `g_bShowHiddenUsers` controls whether hidden users remain visible in category refresh.
- `g_userListDialogHighResLayout` and `g_userListDialogLowResLayout` are resource-layout dependencies.
- User rows are staged as fixed `1044`-byte records in current generated source; field names remain provisional.

## Evidence Notes

- Wave3 class summary describes user buckets, high/low layouts, input commands, and sorted categorized network updates.
- IDA MCP confirms the constructor and virtuals as real functions, with the constructor called from packet/UI paths at `0x005087f4`, `0x00513c6c`, `0x005a7ccb`, and `0x005abc54`.
- Current generated source has many synthetic layout and missing-helper artifacts; use this class doc for ownership and structure, not final source quality.

## Cross-References

- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0000FO][UserListPane](by-class/UserListPane.md)
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the users-dialog responsibility, constructor, sort/filter/packet/key/control method map, related local classes, data notes, constructor callers, and explicit generated-source quality caveat.
