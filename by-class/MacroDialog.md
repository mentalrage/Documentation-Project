*** UID:00007I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MacroDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MacroDialog.cpp`
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Functionality

`MacroDialog` is the older keyboard macro setup dialog. It constructs macro edit controls, saves macro strings/settings, and is opened from `OptionPane::OnOptionCommand`.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x0053e520-0x0053e8ce` | Builds the older macro dialog and edit controls. |
| non-deleting destructor helper | `0x0053e8d0-0x0053e8ee` | IDA-confirmed helper adjacent to the save method. |
| `SaveMacros` | `0x0053e8f0-0x0053e958` | Saves macro entries. |
| scalar deleting destructor | `0x005427a0-0x005427f4` | Deleting destructor wrapper in the shared island. |

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:00009V][OptionPane](by-class/OptionPane.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/82`. Summary: the older macro setup dialog has purpose, source owner, vtable family, opening path, and main methods documented, but method-level behavior remains comparatively brief. Evidence: linked macro-dialog memory range, constructor/save/destructor method map, and `OptionPane::OnOptionCommand` ownership evidence.
