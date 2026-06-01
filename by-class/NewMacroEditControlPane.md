*** UID:000095 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewMacroEditControlPane

## Status

- Confidence: strong for behavior; medium for helper/thunk completeness.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- Current recovered file: `source-3/simroot_v2/class_NewMacroEditControlPane.cpp`
- IDA MCP rechecked: 2026-05-25.
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Functionality

`NewMacroEditControlPane` is the row control used by [UID:000094][NewMacroDialog](by-class/NewMacroDialog.md) for macro key/modifier bindings. It stores the macro slot index, binding code, and modifier byte, exposes getter/setter helpers for page load/save, redraws itself after state changes, and handles letter-key assignment.

## State Fields

| Offset | Meaning |
| --- | --- |
| `+0x108` | macro slot/index value loaded by `SetIndex`. |
| `+0x10c` | key binding code read by `GetKeyBinding`. |
| `+0x10e` | modifier byte read by `GetModifier`. |

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| `GetKeyBinding` | `0x0057f9b0-0x0057f9b7` | Returns the `+0x10c` binding code; called by `NewMacroDialog::SaveMacroEntries`. |
| `GetModifier` | `0x0057f9c0-0x0057f9c6` | Returns the `+0x10e` modifier byte; called by `NewMacroDialog::SaveMacroEntries`. |
| constructor | `0x0057f9d0-0x0057fa2a` | Builds a `ControlPane(8)`-derived row and initializes slot/key/modifier state. |
| `SetIndex` | `0x0057fa30-0x0057fa3f` | Stores the macro slot/index field. |
| `SetKeyBinding` | `0x0057fa40-0x0057fa51` | Stores the key binding code. |
| `SetModifier` | `0x0057fa60-0x0057fa6f` | Stores the modifier byte. |
| `Refresh` | `0x0057fa70-0x0057fa79` | Requests row redraw through the control vtable. |
| vtable/base teardown helper | [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) | Reinstalls the three `NewMacroEditControlPane` vtable pointers and tail-calls `0x00544580`; IDA reports no direct xrefs. |
| `OnPaint` | `0x0057faa0-0x0057fc75` | Paints shortcut label, macro type, display name, and selection frame. |
| `OnKeyEvent` | `0x0057fc80-0x0057fcfe` | Accepts letter bindings in input modes 2/3 and notifies the owner pane. |
| `IsSelectable` | `0x0057fd00-0x0057fd04` | Returns true. |
| adjustor thunks | [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) | Secondary/tertiary vtable thunks to `0x00580710`. |
| scalar deleting destructor | `0x00580710-0x00580764` | Restores vtables, tears down the base control, and conditionally deletes. |

## Evidence Notes

- IDA MCP confirms all listed function starts.
- IDA decompiles `0x0057f9b0` as `return this[134]` and `0x0057f9c0` as `return this[270]`, matching offsets `+0x10c` and `+0x10e`.
- `0x0057fa80` is a helper for vtable reset/base teardown, not a row behavior method.
- Disabled generated output includes the `0x00580666` adjustor thunk; the paired `0x0058065b` is missing body text in `simroot_v2` but IDA confirms it forwards to `0x00580710`.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:000094][NewMacroDialog](by-class/NewMacroDialog.md)
- [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md)
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite detailed behavior, field-offset, method, thunk, and IDA evidence notes.
- Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
- Evidence: the page documents row-control purpose, known state offsets, getter/setter/paint/input methods, teardown helper, adjustor thunks, and vtable family; confidence remains medium because helper/thunk completeness and final handwritten-source boundaries are not fully resolved.
