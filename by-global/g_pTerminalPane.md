*** UID:0000SF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pTerminalPane

## Status

- Confidence: strong for terminal/phone parent singleton role.
- Address: `0x0069bdf8`
- Symbol kind: global-data pointer
- Likely owner file: [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- Current generated owner evidence: `class_TerminalPane.cpp`, with users in `PhoneBookDialog`, `PhoneEntryDialog`, and `DialDialog`.

## Role

`g_pTerminalPane` points to the active pre-login terminal pane. `TerminalPane` construction stores the active pane, the destructor and local cleanup helper clear it, and the phone-book entry/dial dialogs use it as the parent pane when they are opened over the terminal UI.

## Xref Notes

IDA MCP checked on 2026-05-24:

- `0x0058af50` stores the constructed `TerminalPane` and initializes the terminal singleton lifecycle.
- `0x0058b650`, `0x0058c240`, `0x0058c350`, `0x0058d270`, and `0x0058d750` use the terminal pane as the dialog parent or terminal-family context.
- [UID:0001JI][0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md) is a tiny constructor EH/unwind helper that clears `0x0069bdf8`.
- `0x0058dc60` clears the singleton in the `TerminalPane` scalar deleting destructor.
- 2026-05-26 recheck confirms `0x0058dbe0` is reached from the `TerminalPane` constructor unwind metadata path, while `0x0058dc60` is the normal destructor clear path.
- IDA MCP `py_eval` rechecked `0x0069bdf8` on 2026-05-31 and confirmed IDA name `dword_69BDF8`, initial dword `0xffffffff`, and 9 data xrefs: constructor writes at `0x0058afa8` and `0x0058afaf`, terminal/setup/dialog-parent reads at `0x0058c15d`, `0x0058c316`, `0x0058c97d`, `0x0058d4ef`, and `0x0058d907`, constructor-unwind clear at `0x0058dbe0`, and destructor clear at `0x0058dc66`.

## Ownership Notes

Keep this global with `login/TerminalPane.cpp`. `PhoneBookDialog.cpp` and `DialDialog` consume the pointer because their dialogs are terminal children, but the singleton lifetime is owned by `TerminalPane`.

## Cross-References

- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- [UID:0000EG][TerminalPane](by-class/TerminalPane.md)
- [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md)
- [UID:0001JI][0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md)
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:00003R][DialDialog](by-class/DialDialog.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:74`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OI` for [UID:0000OI][TerminalPane](by-file/TerminalPane.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069bdf8` as a 4-byte singleton pointer with 9 data xrefs spanning TerminalPane construction, setup/phone/dial parent usage, constructor-unwind cleanup, and the scalar deleting destructor clear.
