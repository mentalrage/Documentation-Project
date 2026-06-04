*** UID:0000O2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SpellMenuDialogs

## Status

- Confidence: strong for class boundaries and shared source family.
- Proposed module: `ui/dialogs/SpellMenuDialogs.cpp`
- Current IDA owner cluster: `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, `ServerSpellMenuItemList`, and `ClientSpellMenuItemList`.
- Vtable/layout anchor: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## File Role

`SpellMenuDialogs.cpp` is the spell-action sibling to `ItemMenuDialogs.cpp`. It owns server-supplied and client-local spell action menus, parses packet/object-image payloads, builds `DLGMERC1` dialog layouts, and sends opcode `0x39` spell-action replies.

IDA confirms spell menu dialog/list vtables at `0x0061f168-0x0061f41c`, with the spell-specific dialog and list methods grouped inside the compact `0x0051ca40-0x0051e998` range.

The server and client variants share the same visual shell and inherit the same [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) base virtual used by text/item menu dialogs:

- `DLGMERC1.EPD` classic layout or `DLGMERC1.EPF` high-resolution layout.
- three image buttons for action, request/previous, and cancel.
- an `ObjectImageControlPane` portrait/object preview.
- a static description pane.
- a scrollable spell list pane.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `ServerSpellMenuDialog` | `0x0051ca40-0x0051d6fc` | `class_ServerSpellMenuDialog.cpp` | Server-provided spell action menu; parses list text from packet rows and sends selected row text back. |
| `ServerSpellMenuItemList` | `0x0051d700-0x0051db37` | `class_ServerSpellMenuItemList.cpp` | Server spell row list with selection highlight and text truncation. |
| `ClientSpellMenuDialog` | `0x0051db40-0x0051e63c` | `class_ClientSpellMenuDialog.cpp` | Client-side spell action menu; populates rows from local player spell data and sends selected spell code. |
| `ClientSpellMenuItemList` | `0x0051e640-0x0051e998` | `class_ClientSpellMenuItemList.cpp` | Client spell row list with slot-code payload and text rendering. |
| Action-button-state helpers | `0x0051d6c0`, `0x0051e600` | server/client dialog methods | [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md); confirms child slot `6` is the spell list, not chat-color UI. |

## Evidence Notes

- IDA MCP confirms the full spell-menu block from `0x0051ca40` through `0x0051e998`; `0x0051e998-0x0051e9a0` is alignment padding before the separate argumented-menu dialog cluster.
- IDA MCP confirms constructor refs into the two dialogs from the dialog-packet dispatcher area around `0x005176c3`, `0x00517b77`, `0x0051770b`, and `0x00517c07`.
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) now documents that dispatcher/wrapper area as the shared menu-dialog creator for packet subtypes `6` and `8`.
- IDA MCP confirms both spell-menu vtable groups reference [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)'s [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md).
- `ServerSpellMenuItemList` and `ClientSpellMenuItemList` share row rendering structure, but their row payload offsets differ: server rows draw text from `entry + 2`, while client rows draw text from `entry + 4` after the spell slot/code field.
- 2026-05-24 MCP recheck: server/client `UpdateActionButtonState` methods both fetch child slot `1` for the action button and child slot `6` for the spell list, count enabled entries, and dispatch to the button enable/disable virtual. The real `ChattingColorListPane` constructor has only chat-color callers, so the stale client local type is not ownership evidence.
- 2026-05-24 item-menu-list pass: IDA xrefs show the secondary/tertiary destructor thunks at `0x00520ad1` and `0x00520adc`, plus scalar deleting destructor `0x00520c20`, are shared by `ClientItemMenuItemList`, `ServerSpellMenuItemList`, and `ClientSpellMenuItemList`.

## Ownership Notes

- Keep this adjacent to [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) and [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), but not merged into either. The spell menu has a distinct spell-list payload model and local-player spell-table population path.
- Keep the shared [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) base adjacent to the menu-dialog family; it is not spell-specific despite spell-menu vtable references.
- The `ObjectImageControlPane` dependency is a reusable control dependency, not a reason to move spell menu dialogs into the object-image control module.
- The current `ClientSpellMenuDialog::UpdateActionButtonState` local label still types the spell list through `ChattingColorListPane`; treat that as owner-name pollution, not chat ownership. Rename that local type to a neutral spell-list wrapper before source migration.
- Do not duplicate the shared list-pane destructor glue in each spell list source body. Keep `0x00520ad1`, `0x00520adc`, and `0x00520c20` as compiler/list-pane destructor support shared with item menu list classes.

## Cross-References

- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md)
- [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `86`.
  - Evidence: document covers class boundaries, shared dialog/list source family, proposed contents, IDA/vtable evidence, ownership notes, local-name pollution, shared destructor glue, and cross-references; confidence is high because class boundaries and grouping are strongly verified.
- 2026-06-04: Assigned reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank, leaving the file in projected-path completion.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) lists `ui/dialogs/SpellMenuDialogs.cpp`, and live IDA confirms the server/client spell menu dialog and list range remains a compact dialog-source owner cluster.
