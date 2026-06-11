*** UID:0000A7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PartySearchEditPane

## Status

- Confidence: strong for behavior, IDA boundaries, user-list caller ownership, vtable evidence, and opcode `0x84` submit path; medium only for final field/control names.
- Likely source file: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- Address range: [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)

## Class Purpose

`PartySearchEditPane` is the small dialog opened from the users dialog for party-search/hunters-list settings. It shows a `DLGSETUP.EPF` dialog with a checkbox labeled `Put me on the hunters list`, a text edit control backed by player data, and an OK button that submits opcode `0x84`.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0059e0d0-0x0059e393` | Builds the dialog, checkbox, text edit, OK button, plays sound `0x198`, and centers the dialog. |
| vtable reset helper | `0x0059e3a0-0x0059e3bf` | Restores the three `PartySearchEditPane` vtables before forwarding to the base cleanup path. |
| `OnDestroyChildControls` | `0x0059e3c0-0x0059e3c1` | No-op override. |
| `OnAction` | `0x0059e3d0-0x0059e707` | Toggles checkbox on action `2`; on action `1`, stores settings and sends opcode `0x84` with search type/text. |
| adjustor thunks | `0x0059f001-0x0059f017` | Destructor adjustors for subobjects. |
| scalar deleting destructor | `0x0059f0b0-0x0059f105` | Resets vtables, destroys base dialog, and conditionally deletes. |

## Evidence Notes

- Live IDA MCP on 2026-06-04 confirms the current executable as `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` / SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- IDA function boundaries are exact for the constructor `0x0059e0d0-0x0059e393`, vtable reset helper `0x0059e3a0-0x0059e3bf`, no-op override `0x0059e3c0-0x0059e3c1`, action handler `0x0059e3d0-0x0059e707`, adjustor thunks `0x0059f001-0x0059f00c` and `0x0059f00c-0x0059f017`, and scalar deleting destructor `0x0059f0b0-0x0059f105`.
- `CodeRefsTo(0x0059e0d0)` reports only `0x0059db82`, inside `sub_59DA90` (`UserListDialogPane::OnControlCommand`), matching the user-list command `20` ownership path.
- The constructor installs the three `PartySearchEditPane` vtables at `0x0062ea40`, `0x0062eaa0`, and `0x0062ead0`, plays sound id `0x198`, loads `DLGSETUP.PAL` / `DLGSETUP.EPF`, inlines checkbox/text setup with label `Put me on the hunters list`, and stores the initial checked byte into the child control at `+0x108`.
- The action handler is vtable-referenced at `0x0062ea88`. Action `2` reads and toggles the checkbox byte at child `+0x108` and invalidates through the child vtable; action `1` stores the checked state to `g_pPlayerData + 0x3cb1`, sanitizes/copies the text state, pushes opcode `0x84` at `0x0059e607`, appends the payload through packet helpers, and sends through `dword_67A7EC`.
- The destructor path resets the same three vtables before base cleanup, and the two adjustor thunks at `0x0059f001` and `0x0059f00c` forward into the scalar deleting destructor.

## Cross-References

- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and assigned parent `0000OZ`.
  - Before: reconstruction autogen classification and parent were blank despite IDA-backed documentation for a user-list dialog child class.
  - After: classified as reconstructable source attached to [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md).
  - Evidence: live IDA MCP `lookup_funcs` confirms the constructor/helper/no-op/action/destructor-thunk/deleting-destructor starts at `0x0059e0d0`, `0x0059e3a0`, `0x0059e3c0`, `0x0059e3d0`, `0x0059f001`, `0x0059f00c`, and `0x0059f0b0`; the class page documents the single constructor caller from the user-list command path and opcode `0x84` submission. The class score is `84/88` and parent file score is `86/82`, satisfying the 80/80 attach gate.

- Before: completion/confidence metadata were `0/0` even though the page already documented class behavior, constructor/action methods, caller evidence, and file-name uncertainty.
- Changed to: `COMPLETION:74` and `CONFIDENCE:76`.
- Evidence: dialog construction, checkbox/text edit behavior, opcode `0x84` submission, action handling, destructor support, caller path from `UserListDialogPane`, and provisional player-data offsets are documented; confidence remains medium because final file split and field names are still open.
- 2026-06-04: Raised completion from `74` to `84` and confidence from `76` to `88` after live IDA MCP verification of the party-search dialog class.
  - Before: the page had a stale naming caveat and treated the final user-list source placement as medium confidence.
  - After: the page records exact constructor/helper/action/destructor boundaries, the single constructor caller from `UserListDialogPane::OnControlCommand`, vtable addresses/refs, resource strings, checked-state storage, opcode `0x84` submit path, and destructor/adjustor relationship.
  - Evidence: live disassembly confirms `sub_59E0D0`, `sub_59E3A0`, `nullsub_62`, `sub_59E3D0`, `sub_59F001`, `sub_59F00C`, and `sub_59F0B0`; `CodeRefsTo(0x0059e0d0)` contains only `0x0059db82`; the constructor writes vtables `0x0062ea40/0x0062eaa0/0x0062ead0`; and `OnAction` uses child `+0x108`, player-data `+0x3cb1`, opcode `0x84`, and `dword_67A7EC`.
