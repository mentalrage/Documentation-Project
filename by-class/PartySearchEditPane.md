*** UID:0000A7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PartySearchEditPane

## Status

- Confidence: strong for behavior, medium for whether final file is separate from `UserListDialogPane.cpp`.
- Likely source file: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- Address range: [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- Current recovered file: `source-3/simroot_v2/class_PartySearchEditPane.cpp`

## Class Purpose

`PartySearchEditPane` is the small dialog opened from the users dialog for party-search/hunters-list settings. It shows a `DLGSETUP.EPF` dialog with a checkbox labeled `Put me on the hunters list`, a text edit control backed by player data, and an OK button that submits opcode `0x84`.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0059e0d0-0x0059e393` | Builds the dialog, checkbox, text edit, OK button, plays sound `0x198`, and centers the dialog. |
| `OnDestroyChildControls` | `0x0059e3c0-0x0059e3c1` | No-op override. |
| `OnAction` | `0x0059e3d0-0x0059e707` | Toggles checkbox on action `2`; on action `1`, stores settings and sends opcode `0x84` with search type/text. |
| adjustor thunks | `0x0059f001-0x0059f017` | Destructor adjustors for subobjects. |
| scalar deleting destructor | `0x0059f0b0-0x0059f105` | Resets vtables, destroys base dialog, and conditionally deletes. |

## Evidence Notes

- Wave3 summary currently names `0x0059e0d0` as `~PartySearchEditPane`, but its signature and behavior are a constructor: it calls `DialogPane::DialogPane`, installs vtables, allocates child controls, and returns `this`.
- IDA MCP confirms `UserListDialogPane::OnControlCommand` calls `0x0059e0d0` at `0x0059db82` when opening the party-search dialog.
- The dialog uses `g_pPlayerData + 0x3cb1` and `+0x3cb2` for search toggle/text state in current decompilation; field names remain provisional.

## Cross-References

- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented class behavior, constructor/action methods, caller evidence, and generated name caveat.
- Changed to: `COMPLETION:74` and `CONFIDENCE:76`.
- Evidence: dialog construction, checkbox/text edit behavior, opcode `0x84` submission, action handling, destructor support, caller path from `UserListDialogPane`, and provisional player-data offsets are documented; confidence remains medium because final file split and field names are still open.
