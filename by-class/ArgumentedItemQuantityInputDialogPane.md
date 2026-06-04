*** UID:00000G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArgumentedItemQuantityInputDialogPane

## Status

- Confidence: strong for behavior, boundaries, constructor callers, vtable anchors, validation constants, and packet dispatch.
- Likely source file: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), or folded into [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- Address range: [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)
- Parent attachment: attached to [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), now `82/88`, because the class and parent both have live IDA-backed high confidence.

## Class Purpose

`ArgumentedItemQuantityInputDialogPane` asks for the quantity to buy after the user has confirmed an argumented item price. It validates the typed quantity, rejects zero and values above 100, and sends the final opcode `0x39` item quantity packet.

## Class Shape

- Base family: command/input dialog pane for argumented item purchase flow.
- Context ownership: copies argumented menu/list context so the final quantity packet can be serialized without depending on transient UI selection state.
- Validation: accepts only quantity values in the documented `1..100` range.
- Dispatch dependency: successful confirm calls `SendArgumentedItemQuantityPacket` at `0x0051f640`.
- Source placement: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), with the same folded-into-argumented-menu caveat as the confirm pane.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0051fc90-0x0051ff6c` | `ArgumentedItemQuantityInputDialogPane` | Builds `ArgumentQuantity` dialog controls and copies the argumented menu item-list context. |
| `0x0051ff70-0x005200c4` | `OnDialogAction` | Parses quantity text, shows validation alerts, sends `SendArgumentedItemQuantityPacket`, and closes/destroys the dialog. |

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- Constructor boundary `0x0051fc90-0x0051ff6c`, size `0x2dc`, final `retn 0Ch` at `0x0051ff69`.
- Constructor callers at `0x0051f570` and `0x005204ec`.
- Constructor vtable stores at `0x0051fcec`, `0x0051fcf2`, and `0x0051fcfc` to `??_7ArgumentedItemQuantityInputDialogPane@@6B@` and the secondary quantity-pane vtables.
- Action handler boundary `0x0051ff70-0x005200c4`, size `0x154`, final `retn 8` at `0x005200c1`.
- The action handler is referenced by vtable data at `0x0061f5d0`.
- The action handler parses decimal text, compares the parsed quantity with `0x64` (`100`), uses the `You can't buy more than 100.` and `How much?` alert strings for invalid values, and calls `0x0051f640` at `0x0052008e` for valid nonzero quantities.
- `0x00520046` resolves inside `0x0051ff70-0x005200c4`, so it is not a separate method/function start.

## Cross-References

- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)

## Changes

- 2026-06-04: Raised grading from `70/86` to `82/88`, marked `RECONSTRUCTABLE:TRUE`, and attached `AUTOGEN_PARENT_UID:0000HH`.
  - Before: the page relied partly on stale non-live provenance and had no parent attachment.
  - After: live IDA MCP evidence documents exact half-open boundaries, constructor callers, vtable stores, action-handler vtable data ref, validation constants/alerts, the packet-send call, and the false-start status for `0x00520046`.
  - Score rationale: completion and confidence increased because the class can now be reconstructed as part of the argumented item input-dialog module. C++ remains blank because final names/signatures and the file split are still below the 95/95 bar.
