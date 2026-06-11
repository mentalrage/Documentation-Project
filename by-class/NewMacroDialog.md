*** UID:000094 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewMacroDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_NewMacroDialog.cpp`
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Functionality

`NewMacroDialog` is the newer paged macro setup dialog. It owns page switching, active-control selection, macro entry load/save, and construction of `NewMacroEditControlPane` rows.

It is part of the [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) source family rather than an option-pane or spell-inventory source. The dialog edits macro-page records through [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md) rows, while integrated-profile macro row storage is documented separately as [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md).

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x0053ed90-0x0053f07e` | Builds the newer macro dialog and page controls. |
| non-deleting destructor helper | `0x0053f080-0x0053f09e` | IDA-confirmed helper. |
| `OnCommand` | `0x0053f0a0-0x0053f165` | Handles OK/page commands. |
| `SetActiveControl` | `0x0053f170-0x0053f178` | Tiny active-control helper. |
| `SaveMacroEntries` | `0x0053f180-0x0053f202` | Writes current page entries. |
| `LoadMacroPage` | `0x0053f210-0x0053f2b6` | Loads page entries into row controls. |
| scalar deleting destructor | `0x00542800-0x00542854` | Deleting destructor wrapper. |

## Evidence Notes

- [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md) records the exact constructor, non-deleting destructor helper, command handler, active-control helper, save, and load-page ranges for the dialog.
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) verifies the `NewMacroDialog` primary/secondary/tertiary vtable views at `0x00620e48-0x00620ee0`, with primary slots for the scalar deleting destructor, `OnCommand`, and `SetActiveControl`.
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) classifies the `0x005425f7` and `0x00542602` adjustor thunks as compiler/vtable support for `NewMacroDialog::ScalarDeletingDestructor`.
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md) documents the `0x00542800-0x00542855` scalar deleting destructor wrapper and explains why the wrapper is ABI output tied to source destructor declarations, not handwritten dialog behavior.
- [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md) now records the row-control getter/setter, page load/save accessors, and vtable/thunk evidence used by this dialog.

## Autogen Handling

Attach this class to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md). The class and parent both satisfy the 80/80 attachment gate, and the MacroDialogs source page already owns the newer macro dialog and row-control family. Keep reconstructed C++ blank until constructor layout, command ids, page-control fields, and final destructor/source declarations reach the 95/95 final-source gate.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Changes

- 2026-05-28: Changed `LoadMacroPage` from `0x0053f210-0x0053f2b5` to `0x0053f210-0x0053f2b6`.
  - Before: the method map ended one byte before the IDA function end.
  - After: the method map includes the full function, with following alignment documented in `by-memory/-ignored.md`.
  - Evidence: IDA MCP reports `sub_53F210` as `0x0053f210-0x0053f2b6`.
- Before: completion/confidence metadata were `0/0` even though the page already contained role, method-map, vtable, and source-file documentation.
- Changed to: `COMPLETION:72` and `CONFIDENCE:84`.
- Evidence: the page documents the newer macro dialog's ownership, active-control/page-load/save behavior, key method ranges, and vtable family; remaining gaps are detailed control layout/state fields and exact body-level reconstruction.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `72/84`, below the 80/80 parent-attachment gate, even though [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts at `0x0053ed90`, `0x0053f080`, `0x0053f0a0`, `0x0053f170`, `0x0053f180`, `0x0053f210`, and `0x00542800`.
- 2026-06-06: Raised completion to `82` and attached `AUTOGEN_PARENT_UID:0000KY`. Evidence: the MacroDialogs parent is `88/82`; the executable range page records exact NewMacroDialog method ranges and boundary padding; the vtable page verifies NewMacroDialog vtable views and override slots; the adjustor/scalar-deleting destructor islands classify the destructor support; and NewMacroEditControlPane now documents the row-control accessor/vtable evidence used by page load/save. Confidence remains `84` because final control-field layout, command ids, and source-facing destructor declarations are still below the final-source gate.
