*** UID:000094 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Changes

- 2026-05-28: Changed `LoadMacroPage` from `0x0053f210-0x0053f2b5` to `0x0053f210-0x0053f2b6`.
  - Before: the method map ended one byte before the IDA function end.
  - After: the method map includes the full function, with following alignment documented in `by-memory/-ignored.md`.
  - Evidence: IDA MCP reports `sub_53F210` as `0x0053f210-0x0053f2b6`.
- Before: completion/confidence metadata were `0/0` even though the page already contained role, method-map, vtable, and source-file documentation.
- Changed to: `COMPLETION:72` and `CONFIDENCE:84`.
- Evidence: the page documents the newer macro dialog's ownership, active-control/page-load/save behavior, key method ranges, and vtable family; remaining gaps are detailed control layout/state fields and exact body-level reconstruction.
