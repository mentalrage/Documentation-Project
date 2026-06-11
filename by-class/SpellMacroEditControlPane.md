*** UID:0000DQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellMacroEditControlPane

## Status

- Confidence: strong for behavior, vtable identity, and source-module ownership; medium-high for final source-facing destructor/helper representation.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SpellMacroEditControlPane.cpp`
- IDA MCP rechecked: 2026-05-25.
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md), rechecked on 2026-06-01.

## Functionality

`SpellMacroEditControlPane` is the spell macro row control used by [UID:0000DP][SpellMacroDialog](by-class/SpellMacroDialog.md). It stores the selected spell key at offset `+0x108`, paints the spell icon/name row, accepts alphabetic key input, and reports itself as selectable to the parent dialog.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| `GetSpellKey` | `0x0057f750-0x0057f757` | Returns the `+0x108` spell-key field; called by `SpellMacroDialog::OnConfirm`. |
| constructor | `0x0057f760-0x0057f7a8` | Builds a `ControlPane(8)`-derived row and stores the spell key. |
| vtable/base teardown helper | [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md) | Reinstalls the three `SpellMacroEditControlPane` vtable pointers and tail-calls the shared base teardown at `0x00544580`; IDA reports no direct xrefs. |
| `OnPaint` | `0x0057f7d0-0x0057f926` | Draws the spell macro row using player spell data and selection state. |
| `OnKeyEvent` | `0x0057f930-0x0057f997` | Accepts alphabetic macro-key input and triggers the owner callback. |
| `IsSelectable` | `0x0057f9a0-0x0057f9a4` | Returns true. |
| adjustor thunks | [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) | Secondary/tertiary vtable thunks to `0x00580770`. |
| scalar deleting destructor | `0x00580770-0x005807c4` | Restores vtables, tears down the base control, and conditionally deletes. |

## Evidence Notes

- IDA MCP confirms all listed function starts.
- IDA decompiles `0x0057f750` as `return this[132]`, matching the generated spell-key field.
- `0x0057f7b0` is a destructor-shaped helper rather than behavior unique to spell macro painting or input.
- Disabled generated output includes the adjustor thunk at `0x0058067c`; the paired `0x00580671` is missing body text in `simroot_v2` but IDA confirms it forwards to `0x00580770`.
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) verifies the `SpellMacroEditControlPane` primary/secondary/tertiary vtable views at `0x0062d1e4-0x0062d284`, including `OnPaint`, `OnKeyEvent`, `IsSelectable`, the scalar deleting destructor, and the two adjustor-thunk slots.
- [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md) records raw-byte and vtable-store evidence for the non-deleting/base-teardown helper, resolving the prior open question about whether the helper belonged to row behavior.
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) records the secondary/tertiary adjustor thunk pair for this class as compiler/vtable support, not independent source behavior.

## Autogen Handling

Attach this class to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md). Both the class and parent now satisfy the 80/80 attachment gate, and the MacroDialogs source page already owns the macro-dialog edit-row family. Keep reconstructed C++ blank until the final source declaration, class layout, and destructor/helper representation reach the 95/95 final-source gate.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:0000DP][SpellMacroDialog](by-class/SpellMacroDialog.md)
- [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md)
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents row-control behavior, field offset, constructor, paint/key/selectable methods, teardown helper, thunk/scalar-destructor ranges, vtable family, and IDA-confirmed thunk caveats; confidence remains capped by helper/thunk completeness and final teardown ownership.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the spell-key getter, constructor, teardown helper, paint, key, selectable, thunk, and scalar deleting destructor anchors from `0x0057f750` through `0x00580770`. The likely parent [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) meets 80/80, but this class confidence is `78`, so the parent UID stays blank.
- 2026-06-06: Raised confidence to `84` and attached `AUTOGEN_PARENT_UID:0000KY`. Evidence: the MacroDialogs parent is `88/82`, the 2026-06-01 vtable-family page verifies the `SpellMacroEditControlPane` vtable views and destructor/adjustor slots, the teardown helper page records raw-byte/vtable-store evidence, and the thunk page classifies the `0x00580671`/`0x0058067c` pair as compiler/vtable support. Final C++ stays blank because the exact source-facing destructor/helper shape remains below the final-source gate.
