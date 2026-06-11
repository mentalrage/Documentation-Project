*** UID:0000FO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserListPane

## Status

- Confidence: strong for class purpose and local ownership.
- Likely source file: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- Address range: [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- Current recovered file: `source-3/simroot_v2/class_UserListPane.cpp`

## Class Purpose

`UserListPane` is the repeated list widget used by `UserListDialogPane` for user rows. It derives from/list-wraps `ListPane`, draws user entries, tracks selection, opens whisper input for selected users, and dispatches double-click source/message actions.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0059e710-0x0059e899` | Constructs the list pane around fixed `1044`-byte entries and owner/bucket pointers. |
| destructor | `0x0059e8a0-0x0059e943` | Resets vtables and tears down list-pane state. |
| `DrawUserEntry` | `0x0059ea90-0x0059ed18` | Draws a row, highlight state, user name/status/source flags, and category coloring. |
| `OnItemSelected` | `0x0059ed20-0x0059ed5e` | Selection callback, then forwards to base list selection. |
| `OpenSayToUserMessageInputPane` | `0x0059ed60-0x0059ee0c` | Closes the user list and opens direct-message input for the selected name. |
| `OnDoubleClick` | `0x0059ee10-0x0059efd0` | Handles double-click row actions and calls `AddUserListSourceMessage_59DE60` when a source line is available. |
| adjustor thunks | `0x0059f02d-0x0059f043` | Destructor adjustors for list-pane subobjects. |
| scalar deleting destructor | `0x0059f190-0x0059f25b` | Deleting destructor wrapper around list-pane teardown. |

## Evidence Notes

- Wave3 reports class grade `96.1`, with current source emitted separately as `class_UserListPane.cpp`.
- IDA MCP confirms `UserListDialogPane` constructor calls `UserListPane` at `0x0059c00a` and `0x0059cb6b`.
- The class should migrate with `UserListDialogPane.cpp` rather than a generic list-control file because its draw and double-click behavior are specific to social user records.

## Cross-References

- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, destructor, row draw, selection callback, message-input opener, double-click handler, adjustor thunks, and scalar deleting destructor at `0x0059e710`, `0x0059e8a0`, `0x0059ea90`, `0x0059ed20`, `0x0059ed60`, `0x0059ee10`, `0x0059f02d`, `0x0059f038`, and `0x0059f190`; this page and parent [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:86`.
  - Summary/evidence: scored from the repeated-list purpose, constructor/destructor/draw/selection/message/double-click method map, constructor call evidence, and local ownership with `UserListDialogPane`.
