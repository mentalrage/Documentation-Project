*** UID:0000TY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArgumentedItemPurchaseHelpers_51f450_51f640

## Status

- Confidence: strong for helper behavior and function boundaries; medium for final helper names and whether `0x0051f450`/`0x0051f510` are retained live paths.
- Current Wave3 caveats: `0x0051f450` is emitted as `ChattingColorListPane::ShowBuyConfirmDialog`; `0x0051f510` is not modeled as a Wave3 method in current data; `0x00520046` is a false method start inside the quantity dialog action handler.
- Proposed owner file: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), possibly folded into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) or `ArgumentedMenuDialogs.cpp`
- Exact memory ranges: [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md) and [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)

## Helper Summary

| Address range | Proposed name | Behavior |
| --- | --- | --- |
| `0x0051f450-0x0051f4fd` | `ShowBuyConfirmDialog` / `OpenArgumentedItemConfirmDialog` | Reads the selected argumented menu entry, formats `Do you want to buy this?\n\nConfirm the price.`, allocates `ArgumentedItemConfirmInputDialogPane`, and passes item id, argument id, and expected price. |
| `0x0051f510-0x0051f5a4` | `OpenQuantityDialogOrSendSingle` | If available quantity is `0` or `1`, sends quantity `1` through `SendArgumentedItemQuantityPacket`; otherwise allocates `ArgumentedItemQuantityInputDialogPane` using prompt resource id `246`. |
| `0x0051f640-0x0051f705` | `SendArgumentedItemQuantityPacket` | Serializes the final 14-byte opcode `0x39` argumented item purchase packet from the selected `ArgumentedMenuMenuItemList` context and sends it through the client packet sender. |

## IDA MCP Evidence

Checked on 2026-05-24:

- `lookup_funcs` confirms `0x0051f450`, `0x0051f510`, and `0x0051f640` as real functions with sizes `0xae`, `0x95`, and `0xc6`.
- `xrefs_to 0x0051f450` and `xrefs_to 0x0051f510` report no direct xrefs in the current IDB, so treat these as retained or indirectly reached helper paths until a raw caller/vtable pass proves otherwise.
- Decompilation of `0x0051f450` does not use chat-color data. It reads a selected menu-entry index, fetches an entry through a list vtable, and creates `ArgumentedItemConfirmInputDialogPane` with selected item context fields.
- Decompilation of `0x0051f510` matches the confirm-dialog handler's final branch: quantity `<= 1` calls `0x0051f640`, while larger quantities open `ArgumentedItemQuantityInputDialogPane`.
- `xrefs_to 0x0051f640` reports calls at `0x0051f504`, `0x0051f58d`, `0x0052008e`, and `0x00520501`, covering direct helper dispatch plus both quantity and confirm input-dialog action paths.
- `lookup_funcs 0x00520046` resolves to enclosing function `0x0051ff70-0x005200c3`, and decompilation places it inside `ArgumentedItemQuantityInputDialogPane::OnDialogAction` after the nonzero quantity check. It is not a function start.
- `lookup_funcs 0x0051f310` reports `Not a function`; keep that separate from this purchase-helper issue as an `ArgumentedMenuMenuItemList` metadata caveat.

## Ownership Decision

These helpers are argumented merchant/menu purchase helpers, not chat-color or frame-chrome code. The strongest source placement is `ui/dialogs/ArgumentedItemInputDialogs.cpp` because the helpers construct or call the two argumented input panes and share their packet sender. If final migration folds input panes into `ArgumentedMenuDialogs.cpp`, these helpers should move with that argumented-menu source family.

Do not migrate `0x0051f450` as `ChattingColorListPane` code. Do not model `0x00520046` as an `AboveFrame`, alert, ranking, or chat method.

## Cross-References

- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)
- [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `76/82`.
  - Before: page documented helper behavior, IDA starts, ownership decision, and Wave3 caveats but remained unevaluated.
  - After: score reflects documented purchase-confirm/quantity-send helper behavior and source placement, with completion/confidence limited by retained/indirect reachability questions for `0x0051f450` and `0x0051f510`.
  - Evidence: IDA notes confirm real starts/sizes, decompilation of the purchase helpers, xrefs to `0x0051f640`, and false-start status for `0x00520046`.
