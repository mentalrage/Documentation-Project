*** UID:00000F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArgumentedItemConfirmInputDialogPane

## Status

- Confidence: strong for behavior, boundaries, constructor callers, vtable anchors, and the action-handler dispatch.
- Likely source file: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), or folded into [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- Address range: [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)
- Parent attachment: attached to [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), now `82/88`, because the class and parent both have live IDA-backed high confidence.

## Class Purpose

`ArgumentedItemConfirmInputDialogPane` is the price-confirm dialog opened from an argumented item menu row. It displays a confirmation prompt, reads the typed price, compares it against the expected price from the selected row, and either shows a mismatch alert, sends a quantity-one purchase packet, or opens `ArgumentedItemQuantityInputDialogPane`.

## Class Shape

- Base family: command/input dialog pane for argumented item purchase flow.
- Context ownership: copies an `ArgumentedMenuMenuItemList` context so the final packet can reuse command type, owner id, list parameter, selected argument id, and owner dialog pointer.
- Dispatch dependency: calls `SendArgumentedItemQuantityPacket` directly for quantity `1`, otherwise opens [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md).
- Source placement: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), with an open option to fold into [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md).

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005200d0-0x005203be` | `ArgumentedItemConfirmInputDialogPane` | Builds the confirm dialog UI, stores expected price/available quantity/item argument id, and constructs a copied `ArgumentedMenuMenuItemList` context. |
| `0x005203c0-0x00520539` | `OnDialogAction` | Handles confirm/cancel; validates entered price, alerts on mismatch, sends quantity `1`, or opens the quantity input dialog. |

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- Constructor boundary `0x005200d0-0x005203be`, size `0x2ee`, final `retn 14h` at `0x005203bb`.
- Constructor callers at `0x0051f22a` and `0x0051f4de`.
- Constructor vtable stores at `0x00520147`, `0x0052014d`, and `0x00520157` to `??_7ArgumentedItemConfirmInputDialogPane@@6B@` and the secondary confirm-pane vtables.
- Action handler boundary `0x005203c0-0x00520539`, size `0x179`, final `retn 8` at `0x00520536`.
- The action handler is referenced by vtable data at `0x0061f66c`.
- The action handler parses decimal text, compares it with the expected price field, uses the `Price is different.` alert string on mismatch, reads prompt resource id `246` through `dword_67A750` for the quantity dialog, calls `0x0051fc90` for multi-quantity purchases, and calls `0x0051f640` at `0x00520501` for quantity-one purchases.
- The next function starts at `0x00520540` and belongs to `ObjectImageControlPane`, confirming the handler endpoint.

## Cross-References

- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)

## Changes

- 2026-06-04: Raised grading from `70/86` to `82/88`, marked `RECONSTRUCTABLE:TRUE`, and attached `AUTOGEN_PARENT_UID:0000HH`.
  - Before: the page relied partly on stale non-live provenance and had no parent attachment.
  - After: live IDA MCP evidence documents exact half-open boundaries, constructor callers, vtable stores, action-handler vtable data ref, price-validation behavior, quantity-dialog dispatch, and the `0x0051f640` packet-send call.
  - Score rationale: completion and confidence increased because the class can now be reconstructed as part of the argumented item input-dialog module. C++ remains blank because final names/signatures and the file split are still below the 95/95 bar.
