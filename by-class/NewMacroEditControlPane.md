*** UID:000095 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewMacroEditControlPane

## Status

- Confidence: strong for behavior, vtable identity, and source-module ownership; medium-high for final source-facing destructor/helper representation.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- Current recovered file: `source-3/simroot_v2/class_NewMacroEditControlPane.cpp`
- IDA MCP rechecked: 2026-05-25.
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md), rechecked on 2026-06-01.

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
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) verifies the `NewMacroEditControlPane` primary/secondary/tertiary vtable views at `0x0062d288-0x0062d328`, including `OnPaint`, `OnKeyEvent`, `IsSelectable`, the scalar deleting destructor, and the two adjustor-thunk slots.
- [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) records raw-byte and vtable-store evidence for the non-deleting/base-teardown helper, resolving the prior open question about whether the helper belonged to row behavior.
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) records the secondary/tertiary adjustor thunk pair for this class as compiler/vtable support, not independent source behavior.

## Autogen Handling

Attach this class to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md). Both the class and parent now satisfy the 80/80 attachment gate, and the MacroDialogs source page already owns the macro-dialog edit-row family. Keep reconstructed C++ blank until the final source declaration, class layout, and destructor/helper representation reach the 95/95 final-source gate.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:000094][NewMacroDialog](by-class/NewMacroDialog.md)
- [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md)
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed getter/setter/constructor/paint/input/thunk/deleting-destructor starts at `0x0057f9b0`, `0x0057f9c0`, `0x0057f9d0`, `0x0057fa30`, `0x0057fa40`, `0x0057fa60`, `0x0057fa70`, `0x0057fa80`, `0x0057faa0`, `0x0057fc80`, `0x0057fd00`, `0x00580640`, `0x0058065b`, `0x00580666`, and `0x00580710`. Left `AUTOGEN_PARENT_UID` blank because this class confidence is below the 80 attachment gate even though [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) is the likely source-module parent.
- Before: completion/confidence metadata were `0/0` despite detailed behavior, field-offset, method, thunk, and IDA evidence notes.
- Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
- Evidence: the page documents row-control purpose, known state offsets, getter/setter/paint/input methods, teardown helper, adjustor thunks, and vtable family; confidence remains medium because helper/thunk completeness and final handwritten-source boundaries are not fully resolved.
- 2026-06-06: Raised to `82/84` and attached `AUTOGEN_PARENT_UID:0000KY`. Evidence: the MacroDialogs parent is `88/82`, the 2026-06-01 vtable-family page verifies the `NewMacroEditControlPane` vtable views and destructor/adjustor slots, the teardown helper page records raw-byte/vtable-store evidence, and the thunk page classifies the `0x0058065b`/`0x00580666` pair as compiler/vtable support. Final C++ stays blank because the exact source-facing destructor/helper shape remains below the final-source gate.
