*** UID:00006L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IntegrateMacroDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001E1][0x00541b30-0x00542265.IntegrateMacroDialog](by-memory/0x00541b30-0x00542265.IntegrateMacroDialog.md)
- Current recovered file: `source-3/simroot_v2/class_IntegrateMacroDialog.cpp`
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Functionality

`IntegrateMacroDialog` is the integrated macro sequence editor. It builds ten macro edit fields, draws the macro dialog frame, handles OK/prev/next/page actions, clears fields, refreshes field contents, and responds to key input.

It edits the 30-row [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) table inside `RegistryConfig`: three pages of ten rows, with row base `g_pConfig + 0x28f2ec + index * 0x108`.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x00541b30-0x00541e28` | Builds the integrated macro dialog and creates edit controls. |
| non-deleting destructor helper | `0x00541e30-0x00541e4e` | IDA-confirmed helper. |
| `OnDraw` | `0x00541e50-0x00541f95` | Paints frame/background. |
| `OnButtonClick` | `0x00541fa0-0x005420b0` | Handles dialog buttons and save actions. |
| `HandleKeyInput` | `0x005420c0-0x005420c8` | Tiny key-input hook. |
| `ClearMacroEditFields` | `0x005420d0-0x005420fc` | Clears macro edit rows. |
| `RefreshMacroEditFields` | `0x005421f0-0x00542265` | Loads saved macro records into row controls. |
| scalar deleting destructor | `0x00542740-0x00542795` | Deleting destructor wrapper in [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md). |

## Evidence

IDA confirms constructor callers from `UserPane::OnKeyEvent` and `MenuVarietySelectPane::HandleMenuMouseEvent`, and confirms construction of `IntegrateMacroEditControlPane` from this dialog. A 2026-05-25 recheck confirms `RefreshMacroEditFields` computes `264 * (controlIndex + 10 * currentPage - 2) + g_pConfig + 0x28f2ec` before binding each edit control.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:00006M][IntegrateMacroEditControlPane](by-class/IntegrateMacroEditControlPane.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)
- [UID:0000EE][TargetOptionDialog](by-class/TargetOptionDialog.md)
- [UID:0001E1][0x00541b30-0x00542265.IntegrateMacroDialog](by-memory/0x00541b30-0x00542265.IntegrateMacroDialog.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)

## Changes

- What existed before: the page referenced `RefreshMacroEditFields` and the main memory page as ending at `0x00542264`, and the scalar deleting destructor as ending at `0x00542794`.
- What it was changed to: the main range now ends at `0x00542265`, and the scalar deleting destructor wrapper is documented as `0x00542740-0x00542795` in the shared destructor island.
- Summary and evidence: IDA MCP review on 2026-05-28 showed `sub_5421F0` ends at `0x00542265` and the generated destructor wrapper ends at `0x00542795`.
- Completion/confidence score update: existed before as `0/0`; changed to `82/88`. Summary: integrated macro dialog behavior, ten-row edit controls, RegistryConfig macro table mapping, method inventory, caller evidence, child control relationship, vtable family, and corrected ranges are documented with strong confidence. Evidence: `IntegrateMacroDialog`, `MacroDialogFamilyVtables`, `MacroHotkeyRecord`, `DialogPaneScalarDeletingDestructorIsland`, and IDA caller/recheck notes.
