*** UID:0000KY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MacroDialogs

## Status

- Confidence: strong for class behavior; medium for whether all generations shared one original file.
- Proposed module: `ui/dialogs/MacroDialogs.cpp`
- Current recovered sources: `class_MacroDialog.cpp`, `class_SpellMacroDialog.cpp`, `class_NewMacroDialog.cpp`, `class_IntegrateMacroDialog.cpp`, `class_NewMacroEditControlPane.cpp`, `class_SpellMacroEditControlPane.cpp`, and `class_IntegrateMacroEditControlPane.cpp`
- Main address docs: [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md), [UID:0001E1][0x00541b30-0x00542265.IntegrateMacroDialog](by-memory/0x00541b30-0x00542265.IntegrateMacroDialog.md), and [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- Vtable/type evidence: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Role

`MacroDialogs.cpp` owns the keyboard macro setup UI family: older item/spell macro dialogs, the newer paged macro dialog, the integrated macro sequence dialog, and the custom controls that display/edit macro rows.

## Proposed Contents

| Structure | Address evidence | Role |
| --- | --- | --- |
| `MacroDialog` | `0x0053e520-0x0053e958`, destructor `0x005427a0` | Older macro setup dialog with ten text/edit controls and save handling. |
| `SpellMacroDialog` | `0x0053e960-0x0053ed88`, destructor `0x00542a00` | Spell macro setup dialog and confirm handler. |
| `NewMacroDialog` | `0x0053ed90-0x0053f2b6`, destructor `0x00542800` | Newer paged macro dialog with macro edit-control rows and page load/save logic. |
| `IntegrateMacroDialog` | `0x00541b30-0x00542265`, destructor `0x00542740-0x00542795` | Integrated macro sequence dialog opened from user/menu paths. |
| `SpellMacroEditControlPane` | `0x0057f750-0x0057f9a4`, destructor `0x00580770` | Spell macro row control. |
| `NewMacroEditControlPane` | `0x0057f9b0-0x0057fd04`, destructor `0x00580710` | New macro row control for item/spell bindings and key modifiers. |
| `IntegrateMacroEditControlPane` | `0x0057fd10-0x00580700` | Integrated macro text/edit wrapper with focus, paint, sync, and parent attach forwarding. |

## Boundaries

- [UID:0000M7][OptionPane](by-file/OptionPane.md) opens older macro dialogs, but the macro dialog implementations should stay in a macro-focused source candidate rather than being absorbed into `OptionPane.cpp`.
- [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md) begins after `IntegrateMacroDialog` at `0x00542270`; keep target-option settings separate.
- `SpellMacroDialog` is spell-related by content, but its construction, resource layout, and row-control behavior are closer to the macro-dialog family than to spell inventory rendering.
- The saved row data belongs to [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) as [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) storage. `MacroDialogs.cpp` edits those rows but does not own the profile serializer.

## Evidence

- Wave3 reports high effective grades for the dialog classes: `MacroDialog` `98.2`, `SpellMacroDialog` `96.4`, `NewMacroDialog` `96.7`, and `IntegrateMacroDialog` `98.1`.
- IDA confirms `MacroDialog` and `SpellMacroDialog` are opened from `OptionPane::OnOptionCommand`.
- IDA confirms `IntegrateMacroDialog` is opened from `UserPane::OnKeyEvent` and `MenuVarietySelectPane::HandleMenuMouseEvent`.
- IDA confirms `IntegrateMacroDialog` constructs `IntegrateMacroEditControlPane` at `0x00541cc5`.
- IDA MCP recheck on 2026-05-25 confirms `IntegrateMacroDialog` binds ten [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) rows per page from `g_pConfig + 0x28f2ec + index * 0x108`, and the edit control reads/writes state at row `+4` with text/key payload at row `+8`.
- The integrated edit control's alphabetic assignment uses the active [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) child: child index `3` / spell inventory writes state `2` / `.usr` `S`, while child index `2` / inventory writes state `3` / `.usr` `I`.
- IDA symbol enumeration on 2026-05-26 confirms decorated vtable/RTTI families for all seven classes. The dialog classes each have primary, secondary, and tertiary vtable views; the edit controls use the larger `ControlPane`-derived primary view plus secondary/tertiary adjustor views. Current `simroot_v2` metadata still reports `vtable_count: 0` for all seven classes, so source migration should use [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) for ABI layout evidence.

## Caveats

The edit-control island contains several IDA-confirmed helper/thunk starts that are not modeled consistently by Wave3. The 2026-05-25 recheck identifies [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md) and [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) as vtable-reset/base-teardown helpers for `SpellMacroEditControlPane` and `NewMacroEditControlPane`; [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) is vtable thunk/adjustor support for activate and the three scalar deleting destructors. Treat the generated control files as behavior evidence, not a complete final source emission.

## Cross References

- [UID:00007I][MacroDialog](by-class/MacroDialog.md)
- [UID:0000DP][SpellMacroDialog](by-class/SpellMacroDialog.md)
- [UID:000094][NewMacroDialog](by-class/NewMacroDialog.md)
- [UID:00006L][IntegrateMacroDialog](by-class/IntegrateMacroDialog.md)
- [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)

## Changes

- 2026-05-28: Changed the `NewMacroDialog` end from `0x0053f2b5` to `0x0053f2b6`.
  - Before: the file candidate ended `NewMacroDialog::LoadMacroPage` one byte early.
  - After: `NewMacroDialog` includes the full `0x0053f210-0x0053f2b6` helper, with only padding before `FriendListDialog`.
  - Evidence: IDA MCP reports `sub_53F210` as `0x0053f210-0x0053f2b6`; bytes after the corrected end are `0xcc` padding until `0x0053f2c0`.
- 2026-05-28: Changed `IntegrateMacroDialog` from `0x00541b30-0x00542264` to `0x00541b30-0x00542265`.
  - Before: the file candidate ended `RefreshMacroEditFields` one byte early and left the following bytes as UNKNOWN.
  - After: `IntegrateMacroDialog` includes the full refresh method, with only padding before `TargetOptionDialog`; its generated scalar deleting destructor is tracked in the shared destructor island.
  - Evidence: IDA MCP reports `sub_5421F0` ending at `0x00542265`, padding through `0x00542270`, and the wrapper at `0x00542740-0x00542795` in [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md).
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: macro dialog generations, edit-control panes, boundaries, registry macro record interaction, vtable family, helper/thunk caveats, and range corrections are documented; confidence is capped by whether all generations shared one original file.
