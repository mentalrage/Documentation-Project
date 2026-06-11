*** UID:00006M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IntegrateMacroEditControlPane

## Status

- Confidence: strong for behavior and helper/thunk evidence; medium for final source-facing helper representation.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- Current recovered file: `source-3/simroot_v2/class_IntegrateMacroEditControlPane.cpp`
- IDA MCP rechecked: 2026-05-25.
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Functionality

`IntegrateMacroEditControlPane` is a control wrapper for integrated macro edit rows used by [UID:00006L][IntegrateMacroDialog](by-class/IntegrateMacroDialog.md). It owns a saved [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) pointer, an embedded `TextEditPane`, forwarding state for keyboard/mouse/focus input, row painting, attach/hide hooks, and deleting teardown.

## State Fields

| Offset | Meaning |
| --- | --- |
| `+0x108` | current [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) pointer; records with `*(record + 4) == 1` contain editable wide text at `record + 8`. |
| `+0x10d` | forwarding/edit-sync byte cleared before copying embedded editor text back to the macro record. |
| `+0x110` | embedded `TextEditPane` pointer. |

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x0057fd10-0x0057fefb` | Builds a `ControlPane(8)` row and creates/configures the embedded `TextEditPane`. |
| `SetMacroData` | `0x0057ff60-0x0057ff9b` | Stores the macro-record pointer, clears the embedded editor, and seeds it from saved wide text when record type is `1`. |
| `RefreshDisplay` | `0x0057ffa0-0x0057ffa9` | Requests row redraw through the control vtable. |
| `OnPaint` | `0x0057ffb0-0x00580312` | Paints the integrated macro row, type indicator, key label, and content text. |
| `OnKeyEvent` | `0x00580320-0x0058045c` | Handles semicolon/text-entry mode and alphabetic macro assignment. |
| `ForwardMouseEvent` | `0x00580460-0x00580483` | Forwards mouse events to the embedded text editor when forwarding mode is active. |
| `ForwardFocusEvent` | `0x00580490-0x005804b3` | Forwards focus events to the embedded text editor when forwarding mode is active. |
| `OnAttachToParent` | `0x00580550-0x005805b2` | Chains to pane attachment and notifies the embedded editor. |
| `OnHide` | `0x005805c0-0x005805d9` | Hides/removes the embedded editor and chains to base hide. |
| `SyncEditControl` | `0x005805e0-0x0058063d` | Copies embedded editor text back into the bound macro record and deactivates forwarding mode. |
| `Activate` thunk | [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) | Vtable thunk to `RadioGroupControlPane::Activate` (`0x00494c30`), exposed by IDA as a data-referenced slot. |
| adjustor thunks | [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) | Secondary/tertiary vtable thunks to `0x00580690`. |
| scalar deleting destructor | `0x00580690-0x00580700` | Deletes the embedded editor if present, restores vtables, tears down the base control, and conditionally deletes. |

## Evidence Notes

- IDA MCP confirms all listed function starts and vtable-data xrefs for the `0x00580640-0x00580650` thunk run.
- IDA decompiles `SetMacroData` as storing the record at `this[66]`, clearing editor pointer `this[68]`, and loading `record + 8` when `*(record + 4) == 1`.
- IDA decompiles `SyncEditControl` as checking record type `1`, leaving forwarding mode, copying up to 64 units from the embedded editor into `record + 8`, then calling the deactivate path at `0x00494c10`.
- IDA decompiles `OnKeyEvent` as setting `*(record + 4) = 1` for semicolon/text-entry mode, or assigning an alphabetic key at `record + 8` with state `2`/`3` depending on the active tab in `g_pGeneralPurposePanel`. The resolved tab mapping is active child index `3` / spell inventory -> state `2` / `S`, and active child index `2` / inventory -> state `3` / `I`.
- Disabled generated output includes only the `0x00580650` adjustor thunk; the paired `0x00580645` and the `0x00580640` activate thunk are real IDA starts now documented as reviewed vtable support.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:00006L][IntegrateMacroDialog](by-class/IntegrateMacroDialog.md)
- [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `86/84`. Summary: macro edit-row role, state offsets, embedded TextEditPane relationship, method map, macro record semantics, vtable thunks, decompiled Set/Sync/Key behavior, and generated-output omissions are documented in detail; confidence remains limited by final source-facing representation of thunk/helper slots. Evidence: `MacroEditControlPanes`, `MacroEditControlPaneVtableThunks`, `MacroDialogFamilyVtables`, and `MacroHotkeyRecord`.
- 2026-06-05: Marked reconstructable and attached to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) because the class is `86/84` and the parent is `88/82`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x0057fd10`, `0x0057ff60`, `0x0057ffa0`, `0x0057ffb0`, `0x00580320`, `0x00580460`, `0x00580490`, `0x00580550`, `0x005805c0`, `0x005805e0`, `0x00580640`, `0x00580645`, `0x00580650`, and `0x00580690`; current `callers` confirms construction from `IntegrateMacroDialog` at `0x00541cc5`.
