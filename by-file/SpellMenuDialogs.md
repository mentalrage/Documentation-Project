*** UID:0000O2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SpellMenuDialogs

## Status

- Proposed module: `NexusTK/ui/dialogs/SpellMenuDialogs.cpp`.
- Source owner for: `ServerSpellMenuDialog`, `ServerSpellMenuItemList`, `ClientSpellMenuDialog`, `ClientSpellMenuItemList`, and owner-specific [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md).
- Exact source-bearing memory children: [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md), [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md), [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md), and [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md).
- Broad range map: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md), now a non-emitting split index.
- Direct vtable/layout anchor: [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md). [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) is mixed-family context only.

## File Role

`SpellMenuDialogs.cpp` is the spell-action sibling to [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). It owns server-supplied and client-local spell action menus, parses packet/object-image payloads, builds the `DLGMERC1` dialog layout, and sends opcode `0x39` spell-action replies.

The server and client variants share the same visual shell and inherited [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) behavior:

- `DLGMERC1.EPD` classic layout or `DLGMERC1.EPF` high-resolution layout;
- three image buttons for action, request/previous, and cancel;
- an `ObjectImageControlPane` portrait/object preview;
- static description text;
- scrollable spell-list child slot `6`;
- action button child slot `1`, updated from list selection state.

`DLGMERC1`, palettes, object-image controls, static text controls, scroll/list controls, and shared packet sender/global dependencies are dependencies of this file, not reasons to move ownership out of [UID:0000O2].

[UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) creates the spell dialogs as subtype `6` / `kServerSpellMenu` and subtype `8` / `kClientSpellMenu` targets. That dispatcher now emits through [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), initializes `RectBounds` through `InitDlgMerc1Bounds`, and calls the spell constructors with `(const RectBounds& bounds, const unsigned char *payload, unsigned char menuMode)`. Keep the shared factory owned by the text/menu factory page; this file owns only the concrete spell dialog/list classes and spell-specific row payloads.

## Proposed Contents

| Entity | Range | Role |
| --- | --- | --- |
| [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md) | `0x0051ca40-0x0051d6fd` | Server spell dialog constructor, command handler, and action-button updater. |
| [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md) | `0x0051d700-0x0051db38` | Server list constructor, retained raw append/send helpers, activation thunk, and draw method. |
| [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md) | `0x0051db40-0x0051e63d` | Client spell dialog constructor, command handler, and action-button updater. |
| [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md) | `0x0051e640-0x0051e998` | Client list constructor, retained raw append/send helpers, activation thunk, and draw method. |
| [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md) | `0x0061f168-0x0061f41c` | Owner-specific spell dialog/list vtable group. |
| [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md) | support index | Non-emitting evidence index for server/client update helpers; exact method children own emitted source. |

## Packet And Row Models

- Server spell rows are server-provided text rows. The list row size is `0x202`: reserved word at `+0`, display name at `+2`. Server selected send serializes opcode `0x39`, packet subtype, object/menu id, option id, row-name byte length, multibyte row name, and a trailing zero.
- Client spell rows are local-player spell records. The list row size is `0x204`: selected spell slot/action byte at `+0`, reserved word at `+2`, display name at `+4`. Client selected/explicit send serializes fixed length `9`: opcode `0x39`, packet subtype, object/menu id, option id, selected spell slot/action byte, and a trailing zero.
- Both list classes store packet/list context at `+0x14c` subtype, `+0x150` object/menu id, `+0x154` option id, and `+0x158` owner dialog pointer.
- Client construction consumes the [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) spell-slot typed view: one-based slots `1..52`, stride `0x148`, active byte `+0x13a834`, display-name text `+0x13a83c`.

## Command And State Behavior

- Dialog command id `1` sends the selected row/action when possible and closes afterward.
- Dialog command id `2` calls the shared request route at `0x00517ec0`; it is not the inherited `0x00517d80` action-string virtual.
- Dialog command id `3` closes without sending opcode `0x39`.
- Other command ids return.
- Both update helpers fetch child slot `1` for the action button, child slot `6` for the spell list, read list storage `+0x108`, call shared `ListPane::GetSelectionCount` at `0x004f3e20`, and dispatch action-button virtual slots `+0x4c/+0x50`.

## Ownership And Exclusions

- Keep this source adjacent to [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), and [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), but do not merge them. Spell menus have distinct row payloads and local-player spell-slot population.
- Do not move client spell code to [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md) or [UID:0000I5][Chatting](by-file/Chatting.md). MCP session `80de0a67` found the real `ChattingColorListPane` constructor `0x00482fb0` only has chat callers `0x00482837` and `0x0048295d`.
- Do not introduce a standalone `SpellManager` / `g_pSpellMan` owner for the local spell rows. Current support docs identify the storage as a `g_pUserPane` typed view.
- Do not duplicate shared list-pane destructor glue in this file's handwritten source. `ServerSpellMenuItemList` and `ClientSpellMenuItemList` destructor slots route through [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md) and [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md). Reconstruct ordinary class declarations/destructors and let the compiler regenerate ABI glue.

## Cross-References

- [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md)
- [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md)
- [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md)
- [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md)
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md)

## Changes

- 2026-06-23 B001 accepted implementation:
  - Raised score from `88/86` to `90/91`.
  - Replaced the broad proposed contents table with exact child pages [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md), [UID:0004Y5][0x0051d700-0x0051db38.ServerSpellMenuItemList](by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md), [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md), and [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md).
  - Updated the primary vtable anchor from mixed [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) to direct [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md).
  - Incorporated raw helper inventory, row models, command ids, action-button state route, `g_pUserPane` spell-slot typed view, generated `ChattingColorListPane` pollution rejection, and shared destructor-glue exclusion.
- 2026-06-28 B010 [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) support sync:
  - Score unchanged at `90/91`.
  - Recorded subtype `6/8` factory creation through the `TextMenuDialogs.cpp` dispatcher and normalized spell-dialog constructor bounds wording to `RectBounds` without transferring factory ownership to this file.
