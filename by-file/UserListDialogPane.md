*** UID:0000OZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# UserListDialogPane

## Status

- Confidence: strong for user-list feature grouping and direct module state; medium-high for exact split from party-search and generic checkbox controls.
- Proposed module: `social/UserListDialogPane.cpp`
- Current recovered sources: `class_UserListDialogPane.cpp`, `class_UserListPane.cpp`, `class_PartySearchEditPane.cpp`, and `recovered/AddUserListSourceMessage_0059DE60.cpp`
- Main address doc: [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- Evidence basis: existing class/file docs plus IDA MCP/raw export function boundary, caller/callee, vtable, and byte-map checks. Generated sources remain useful leads only and are not treated as final source.

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
| `g_pUserListDialogPane`, [UID:0002ZX][g_bShowHiddenUsers](by-global/g_bShowHiddenUsers.md), and layout globals | global-data | Active singleton, show-hidden toggle, and high/low resolution resource layout dependencies. |

## Evidence Notes

- Wave3 reports `UserListDialogPane` as an incomplete class with generated source score `59.1`, while the core method summaries are useful.
- IDA confirms the `UserListDialogPane` constructor callers at `0x005087f4`, `0x00513c6c`, `0x005a7ccb`, and `0x005abc54`.
- `UserListPane` is directly constructed twice from the dialog constructor, once for high-resolution layout and once for low-resolution layout.
- `UserListPane::OnDoubleClick` and `UserListDialogPane::HandleUserListPacket` both call `AddUserListSourceMessage_59DE60`, which supports keeping the helper in this feature source.
- `PartySearchEditPane` is constructed by `UserListDialogPane::OnControlCommand` for command id `20`, which supports grouping it with the user-list source unless later evidence shows it was a separate social dialog file.
- 2026-06-02 IDA MCP/raw export recheck confirms exact modeled sizes for the major range: constructor `0x1508`, no-op `0x3`, sort helpers `0x60` each, refresh `0x34e`, packet handler `0x2d5`, key handler `0x182`, control handler `0x153`, source-message helper `0x70`, party-search constructor `0x2c3`, party-search action `0x337`, list-pane constructor `0x189`, list-pane destructor `0xa3`, draw callback `0x288`, selection callback `0x3e`, whisper opener `0xac`, double-click handler `0x1c0`, and scalar deleting destructors `0x55`/`0x71`/`0xcb`.
- 2026-06-02 IDA byte-map review confirms this is not a simple contiguous function-only island: non-padding tail/table chunks exist between `0x0059d198-0x0059d1e0`, `0x0059d5fe-0x0059d620`, `0x0059dbe3-0x0059de60`, `0x0059e9a6-0x0059e9f0`, and the checkbox/destructor interleave. Those chunks are now called out on the memory page and keep the file below final-source scoring.
- [UID:00026U][0x0062e960-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e960-0x0062eccc.UserListReadOnlyData.md) documents matching `UserListDialogPane`, `CheckBoxTextControlPane`, `PartySearchEditPane`, and `UserListPane` vtable/resource data.
- [UID:0002ZX][g_bShowHiddenUsers](by-global/g_bShowHiddenUsers.md) documents the module-scope show-hidden flag at `0x0069bed0`, with exact user-list constructor, refresh, and control-command xrefs carried by [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag.md).

## Ownership Notes

The address neighborhood is interleaved with [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md), especially `0x0059ded0-0x0059e0ab` and `0x0059efeb-0x0059f0a4`. `PartySearchEditPane::PartySearchEditPane` also inlines one checkbox/text construction at `0x0059e22f-0x0059e265`, but the class layout and vtable still describe a reusable control. Those ranges should stay with [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) or a reusable checkbox-control module, not with user-list source.

The current generated `class_UserListDialogPane.cpp` includes many autograder penalties and unresolved helper names (`UserListPane`, `AddUserListSourceMessage_59DE60`, `OnInputEvent`, synthetic layout overlays). Use IDA function starts and Wave3 summaries as the file-layout anchor; do not treat the active generated body as ready source.

The file-level parent is now above the `80%` confidence attachment threshold. The aggregate executable range can attach here for autogen ownership, but final C++ should remain blank until the non-IDA cleanup/table chunks, checkbox interleaves, field names, packet field names, and helper names are resolved to final-source quality.

## Cross-References

- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md)
- [UID:0000FO][UserListPane](by-class/UserListPane.md)
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:00026U][0x0062e960-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e960-0x0062eccc.UserListReadOnlyData.md)
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)
- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)
- [UID:0000JS][Group](by-file/Group.md)
- [UID:0002ZX][g_bShowHiddenUsers](by-global/g_bShowHiddenUsers.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/78`. Summary/evidence: the page documents the social-list source family, user-list/party-search classes, singleton focus global, IDA evidence, and generated-output ownership caveats; exact split from adjacent controls remains medium-confidence.
- 2026-06-02 source-placement and scoring update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page remained below the file-parent attachment confidence threshold.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/"`, `COMPLETION:86`, and `CONFIDENCE:82`.
  - Summary/evidence: IDA MCP/raw export rechecked exact sizes, constructor/caller relationships, vtable refs, reusable checkbox interleaves, read-only data, and non-padding intra-island chunks; unresolved final field/helper names and non-modeled chunks remain explicit caveats.
- 2026-06-07 A010 Batch057 parent-gate review:
  - What existed before: `CONFIDENCE:82`, which blocked corrected 85/85 routing for directly owned module-scope state.
  - Changed to: `CONFIDENCE:85`; completion remains `86`.
  - Summary/evidence: existing IDA-backed executable, read-only-data, class, singleton, and [UID:0002ZX][g_bShowHiddenUsers](by-global/g_bShowHiddenUsers.md) global documentation now agree on the user-list source family. The remaining checkbox interleave and field-name caveats still cap confidence, but they do not undermine ownership of the show-hidden flag or this source-file parent.
