*** UID:00000H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArgumentedMenuMenuDialog

## Status

- Confidence: strong for behavior, vtable slots, constructor callers, and the exact dialog memory child; medium for exact source split from `TextMenuDialogs.cpp`.
- Likely source file: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), or folded into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- Address range: [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md), nested under [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ArgumentedMenuMenuDialog.cpp`

## Class Purpose

`ArgumentedMenuMenuDialog` is the parameterized item/menu variant of the NPC merchant dialog. It parses packet data for command type, NPC/dialog id, portrait/object asset data, dialog text, list parameter, and item entries. It builds a `DLGMERC3.EPF` dialog with object image, static text, scrollable item list, and action buttons.

## Class Shape

- Base family: merchant/text-menu dialog family.
- Child list: owns or constructs [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md).
- Resource anchor: `DLGMERC3.EPF`.
- Command behavior: command `1` opens item price confirm, command `2` sends a menu request/cancel packet, and command `3` closes.
- Source placement: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), with an open folded source option under [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md).

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0051e9a0-0x0051f136` | `ArgumentedMenuMenuDialog` | Constructor and packet parser; builds `ArgumentedMenuMenuItemList`, parses item entry blocks, and creates dialog controls. |
| `0x0051f140-0x0051f158` | raw action/list forwarding island | Code-shaped non-function island with no IDA xrefs; loads child pointer `this+0x1fc`, calls child virtual slot `+0x10` with argument `7`, then tail-jumps to `0x00498ca0`. |
| `0x0051f160-0x0051f24c` | `HandleMenuCommand` | Opens buy-confirm input dialog for command `1`, sends cancel/request packet for command `2`, or closes on command `3`. |
| `0x0051f250-0x0051f28d` | `UpdateActionButtonState` | Enables/disables the action button depending on selected list state. |

## Evidence Notes

- Wave3 summary identifies this as a menu dialog with parameterized menu entries.
- IDA MCP confirms all three method starts and vtable refs for `0x0051f160` and `0x0051f250`.
- 2026-06-03 restarted IDA MCP recheck corrects the exact half-open function ranges to `0x0051e9a0-0x0051f136`, `0x0051f160-0x0051f24c`, and `0x0051f250-0x0051f28d`.
- Focused disassembly confirms a raw code-shaped island at `0x0051f140-0x0051f158`, but IDA has no function object, no xrefs to `0x0051f140`, and no dialog vtable slot targeting that address.
- The constructor is called from packet-dispatch sites `0x00517750` and `0x00517c97`.
- The primary dialog vtable at `0x0061f428` points command/update slots to `0x0051f160` and `0x0051f250`; secondary/tertiary bases `0x0061f488` and `0x0061f4b8` are installed by the constructor.
- The command `1` path opens [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md) at `0x005200d0` with the prompt text `Do you want to buy this?\n\nConfirm the price.`
- A separate generated helper at `0x0051f450` builds the same confirm pane but is currently emitted under `ChattingColorListPane`; treat it as an argumented item purchase helper, not chat-color code.
- Command `2` reuses `TextMenuDialog::SendMenuRequestPacket`, which ties this class to the text-menu dialog family.

## Cross-References

- [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md)
- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md)

## Changes

- What existed before: the page had behavior and boundary evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `68/82`, and a class-shape section was added for base family, child list, resource anchor, command behavior, and source placement.
- Summary and evidence: IDA-confirmed method starts and vtable references support strong behavior confidence, but final split from `TextMenuDialogs.cpp` and packet/layout fields remain unresolved.
- 2026-06-03 exact-slice update:
  - Before: the class still pointed only at the broad aggregate and omitted the raw `0x0051f140` island.
  - Changed to: `74/84`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md) at position `10`, exact memory child [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md), and corrected half-open method endpoints.
  - Evidence: restarted IDA MCP function boundary checks, vtable-slot dump, constructor caller xrefs, command callee/string refs, and focused raw-island disassembly.
