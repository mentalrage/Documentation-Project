*** UID:00000F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArgumentedItemConfirmInputDialogPane

## Status

- Confidence: strong for behavior and boundaries.
- Likely source file: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), or folded into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- Address range: [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ArgumentedItemConfirmInputDialogPane.cpp`

## Class Purpose

`ArgumentedItemConfirmInputDialogPane` is the price-confirm dialog opened from an argumented item menu row. It displays a prompt, reads the typed price, compares it against the expected price from the selected row, and either shows a mismatch alert, sends a quantity-one purchase packet, or opens `ArgumentedItemQuantityInputDialogPane`.

## Class Shape

- Base family: command/input dialog pane for argumented item purchase flow.
- Context ownership: copies an `ArgumentedMenuMenuItemList` context so the final packet can reuse command type, owner id, list parameter, selected argument id, and owner dialog pointer.
- Dispatch dependency: calls `SendArgumentedItemQuantityPacket` directly for quantity `1`, otherwise opens [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md).
- Source placement: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), with an open option to fold into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md).

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005200d0-0x005203bd` | `ArgumentedItemConfirmInputDialogPane` | Builds the confirm dialog UI, stores expected price/available quantity/item argument id, and constructs a copied `ArgumentedMenuMenuItemList` context. |
| `0x005203c0-0x00520538` | `OnDialogAction` | Handles confirm/cancel; validates entered price, alerts on mismatch, sends quantity `1`, or opens the quantity input dialog. |

## Evidence Notes

- Wave3 summary: dialog for confirming an item action with arguments; effective grade `97.5`.
- IDA MCP confirms the constructor and virtual action handler starts and shows constructor callers at `0x0051f22a` and `0x0051f4de`.
- The confirm handler calls `SendArgumentedItemQuantityPacket` at `0x0051f640` for single-quantity purchases and creates `ArgumentedItemQuantityInputDialogPane` at `0x0051fc90` otherwise. This mirrors the separate [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md) at `0x0051f510`.

## Cross-References

- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)

## Changes

- What existed before: the page had method and caller evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `70/86`, and a class-shape section was added for copied context ownership, dispatch dependencies, and source placement.
- Summary and evidence: Wave3 grade, IDA-confirmed method starts/callers, and existing argumented-item helper docs support strong confidence; completion stays moderate until layout fields and final source split are fully resolved.
