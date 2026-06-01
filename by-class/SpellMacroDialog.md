*** UID:0000DP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellMacroDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_SpellMacroDialog.cpp`
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Functionality

`SpellMacroDialog` is the spell-specific macro setup dialog. It constructs spell macro edit controls, confirms/saves selected spell macro entries, and supports a visibility hook.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x0053e960-0x0053eccf` | Builds spell macro dialog controls. |
| non-deleting destructor helper | `0x0053ecd0-0x0053ecee` | IDA-confirmed helper. |
| `OnConfirm` | `0x0053ecf0-0x0053ed79` | Saves/accepts spell macro values. |
| `SetVisible` | `0x0053ed80-0x0053ed88` | Tiny visibility hook. |
| scalar deleting destructor | `0x00542a00-0x00542a54` | Deleting destructor wrapper. |

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:0000DQ][SpellMacroEditControlPane](by-class/SpellMacroEditControlPane.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `80`, confidence `86`.
- Evidence: the page documents ownership, main range, vtable family, role, constructor/destructor/confirm/visibility/scalar-destructor map, and edit-control relationship; completion remains below high-exhaustive because detailed evidence notes and source-ready C++ are still sparse.
