*** UID:0000SF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pTerminalPane

## Status

- Confidence: strong for terminal/phone parent singleton role and physical storage slot.
- Address: `0x0069bdf8`
- Symbol kind: global-data pointer
- Likely owner file: [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- Current generated owner evidence: `class_TerminalPane.cpp`, with users in `PhoneBookDialog`, `PhoneEntryDialog`, and `DialDialog`.
- Exact storage evidence: [UID:000300][0x0069bdf8-0x0069bdfc.g_pTerminalPane](by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md) records `0x0069bdf8-0x0069bdfc` / `dword_69BDF8` as the active `TerminalPane` singleton slot split from the mixed [UID:0002AQ][0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals](by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md) cluster.

## Role

`g_pTerminalPane` points to the active pre-login terminal pane. `TerminalPane` construction stores the active pane, the destructor and local cleanup helper clear it, and the phone-book entry/dial dialogs use it as the parent pane when they are opened over the terminal UI.

The global should be source-declared with the terminal pane implementation, while the exact `.data` slot remains documented in the adjacent mixed global cluster. The cluster should not imply a source-level aggregate; it only records physical adjacency between terminal and text-edit globals.

## Xref Notes

IDA MCP checked on 2026-05-24:

- `0x0058af50` stores the constructed `TerminalPane` and initializes the terminal singleton lifecycle.
- `0x0058b650`, `0x0058c240`, `0x0058c350`, `0x0058d270`, and `0x0058d750` use the terminal pane as the dialog parent or terminal-family context.
- [UID:0001JI][0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md) is a tiny constructor EH/unwind helper that clears `0x0069bdf8`.
- `0x0058dc60` clears the singleton in the `TerminalPane` scalar deleting destructor.
- 2026-05-26 recheck confirms `0x0058dbe0` is reached from the `TerminalPane` constructor unwind metadata path, while `0x0058dc60` is the normal destructor clear path.
- IDA MCP `py_eval` rechecked `0x0069bdf8` on 2026-05-31 and confirmed IDA name `dword_69BDF8`, initial dword `0xffffffff`, and 9 data xrefs: constructor writes at `0x0058afa8` and `0x0058afaf`, terminal/setup/dialog-parent reads at `0x0058c15d`, `0x0058c316`, `0x0058c97d`, `0x0058d4ef`, and `0x0058d907`, constructor-unwind clear at `0x0058dbe0`, and destructor clear at `0x0058dc66`.
- 2026-06-06 documentation refresh links this global to the current [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) range map, including `TerminalPane::TerminalPane`, `TerminalSetupPane` construction/update/command handlers, stream parser and reconnect/leave callback children, terminal vtable data, and the singleton storage cluster.

## Ownership Notes

Keep this global with `login/TerminalPane.cpp`. `PhoneBookDialog.cpp` and `DialDialog` consume the pointer because their dialogs are terminal children, but the singleton lifetime is owned by `TerminalPane`.

This page now clears the corrected `85/85` direct-parent gate for the exact storage child. The score is still below final-source levels because the exact original declaration spelling/static linkage remains open and this Batch 056 pass could not refresh live IDA xrefs due MCP timeout.

## Cross-References

- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- [UID:0000EG][TerminalPane](by-class/TerminalPane.md)
- [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md)
- [UID:0001JI][0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md)
- [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md)
- [UID:0002AQ][0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals](by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md)
- [UID:000300][0x0069bdf8-0x0069bdfc.g_pTerminalPane](by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md)
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:00003R][DialDialog](by-class/DialDialog.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:74`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OI` for [UID:0000OI][TerminalPane](by-file/TerminalPane.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069bdf8` as a 4-byte singleton pointer with 9 data xrefs spanning TerminalPane construction, setup/phone/dial parent usage, constructor-unwind cleanup, and the scalar deleting destructor clear.
- 2026-06-06: Raised `COMPLETION` from `74` to `80` and `CONFIDENCE` from `84` to `86`.
  - Added exact storage-cluster evidence, refreshed current TerminalPane range/child links, and clarified source-declared/generated-binary handling for the physical `.data` slot.
  - Evidence: existing IDA-backed docs tie `dword_69BDF8` to [UID:0002AQ][0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals](by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md), constructor writes, setup/dialog-parent reads, constructor EH clear, normal scalar deleting destructor clear, terminal vtables, and the [UID:0000OI][TerminalPane](by-file/TerminalPane.md) owner. Final C++ remains blank because the exact source declaration spelling is still below the 95/95 threshold.
- 2026-06-07 A004 Batch 056 parent-gate refresh:
  - Before: `80/86`, with exact storage still documented only through the mixed terminal/text-edit cluster.
  - Changed to: `86/88`, linking exact child [UID:000300][0x0069bdf8-0x0069bdfc.g_pTerminalPane](by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md).
  - Summary/evidence: existing IDA-backed constructor, terminal/setup/dialog-parent, EH clear, and destructor-clear evidence is now tied to the exact four-byte storage page. Live MCP refresh timed out during this pass, so no final C++ declaration was emitted.
