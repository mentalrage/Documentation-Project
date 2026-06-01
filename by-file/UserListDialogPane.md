*** UID:0000OZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# UserListDialogPane

## Status

- Confidence: strong for user-list feature grouping, medium for exact split from party-search and generic checkbox controls.
- Proposed module: `social/UserListDialogPane.cpp`
- Current recovered sources: `class_UserListDialogPane.cpp`, `class_UserListPane.cpp`, `class_PartySearchEditPane.cpp`, and `recovered/AddUserListSourceMessage_0059DE60.cpp`
- Main address doc: [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- Evidence basis: Wave3 class/method summaries, generated `simroot_v2` sources, and IDA MCP function boundary checks on 2026-05-23.

## File Role

`UserListDialogPane.cpp` owns the social user-list dialog, its five column/list panes, list sorting/filtering, user-list packet updates, selected-user interactions, and the party-search edit dialog opened from the user-list command surface.

This should be treated as a social UI feature source rather than generic dialog or list-control infrastructure. It uses reusable controls such as `CheckBoxTextControlPane`, `RadioGroupControlPane`, `ScrollableControlPane`, `TextEditControlPane`, and `DialogPane`, but those controls should keep their own modules.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `UserListDialogPane` | `0x0059bc90-0x0059dbe3`, `0x0059f017-0x0059f181` | Constructs the dialog, parses initial packet rows, refreshes category buckets, handles keyboard/control commands, and destroys the singleton. |
| `AddUserListSourceMessage_59DE60` | `0x0059de60-0x0059decf` | Formats a user-list source line and forwards it to chat/system output. |
| `PartySearchEditPane` | `0x0059e0d0-0x0059e707`, `0x0059f001-0x0059f0b0` | Dialog opened from user-list command `20`; edits hunters-list/party-search settings and sends opcode `0x84`. |
| `UserListPane` | `0x0059e710-0x0059efcf`, `0x0059f02d-0x0059f25b` | Five repeated list panes used by the dialog for category/user rows, drawing, selection, double-click, and whisper/source actions. |
| `g_pUserListDialogPane` and layout globals | global-data | Active singleton and high/low resolution resource layout dependencies. |

## Evidence Notes

- Wave3 reports `UserListDialogPane` as an incomplete class with generated source score `59.1`, while the core method summaries are useful.
- IDA confirms the `UserListDialogPane` constructor callers at `0x005087f4`, `0x00513c6c`, `0x005a7ccb`, and `0x005abc54`.
- `UserListPane` is directly constructed twice from the dialog constructor, once for high-resolution layout and once for low-resolution layout.
- `UserListPane::OnDoubleClick` and `UserListDialogPane::HandleUserListPacket` both call `AddUserListSourceMessage_59DE60`, which supports keeping the helper in this feature source.
- `PartySearchEditPane` is constructed by `UserListDialogPane::OnControlCommand` for command id `20`, which supports grouping it with the user-list source unless later evidence shows it was a separate social dialog file.

## Ownership Notes

The address neighborhood is interleaved with [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md), especially `0x0059ded0-0x0059e0ab` and `0x0059efeb-0x0059f0a4`. `PartySearchEditPane::PartySearchEditPane` also inlines one checkbox/text construction at `0x0059e22f-0x0059e265`, but the class layout and vtable still describe a reusable control. Those ranges should stay with [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) or a reusable checkbox-control module, not with user-list source.

The current generated `class_UserListDialogPane.cpp` includes many autograder penalties and unresolved helper names (`UserListPane`, `AddUserListSourceMessage_59DE60`, `OnInputEvent`, synthetic layout overlays). Use IDA function starts and Wave3 summaries as the file-layout anchor; do not treat the active generated body as ready source.

## Cross-References

- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md)
- [UID:0000FO][UserListPane](by-class/UserListPane.md)
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)
- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)
- [UID:0000JS][Group](by-file/Group.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/78`. Summary/evidence: the page documents the social-list source family, user-list/party-search classes, singleton focus global, IDA evidence, and generated-output ownership caveats; exact split from adjacent controls remains medium-confidence.
