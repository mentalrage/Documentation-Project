*** UID:00000G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArgumentedItemQuantityInputDialogPane

## Status

- Confidence: strong for behavior and boundaries.
- Likely source file: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), or folded into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- Address range: [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ArgumentedItemQuantityInputDialogPane.cpp`

## Class Purpose

`ArgumentedItemQuantityInputDialogPane` asks for the quantity to buy after the user has confirmed an argumented item price. It validates the typed quantity, rejects zero and values above 100, and sends the final opcode `0x39` item quantity packet.

## Class Shape

- Base family: command/input dialog pane for argumented item purchase flow.
- Context ownership: copies argumented menu/list context so the final quantity packet can be serialized without depending on transient UI selection state.
- Validation: accepts only quantity values in the documented `1..100` range.
- Dispatch dependency: successful confirm calls `SendArgumentedItemQuantityPacket` at `0x0051f640`.
- Source placement: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md), with the same folded-into-text-menu caveat as the confirm pane.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0051fc90-0x0051ff6b` | `ArgumentedItemQuantityInputDialogPane` | Builds `ArgumentQuantity` dialog controls and copies the argumented menu item-list context. |
| `0x0051ff70-0x005200c3` | `OnDialogAction` | Parses quantity text, shows validation alerts, sends `SendArgumentedItemQuantityPacket`, and closes/destroys the dialog. |

## Evidence Notes

- Wave3 summary: dialog for entering item quantity with arguments; effective grade `98.0`.
- IDA MCP confirms both method starts and shows constructor callers at `0x0051f570` and `0x005204ec`.
- IDA reports `0x00520046` as an address inside `OnDialogAction`, not a function start. Any metadata treating `0x00520046` as a separate method should be ignored for migration.
- The successful confirm path calls `SendArgumentedItemQuantityPacket` at `0x0051f640`, documented with the surrounding [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md).

## Cross-References

- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)

## Changes

- What existed before: the page had constructor/action evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `70/86`, and a class-shape section was added for copied context, validation, packet dispatch, and source placement.
- Summary and evidence: Wave3 grade and IDA-confirmed method starts/callers support strong confidence; completion remains below high because exact layout fields and final source-file split still need a deeper rewrite pass.
