*** UID:0000HI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ArgumentedMenuDialogs

## Status

- Confidence: strong for argumented menu behavior, vtables, and `ui/dialogs/` placement; medium for final split from [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md).
- Proposed module: `NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp`, or folded into `TextMenuDialogs.cpp`.
- Current recovered sources: `class_ArgumentedMenuMenuDialog.cpp` and `class_ArgumentedMenuMenuItemList.cpp`
- Vtable/layout anchor: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- Exact dialog memory slice: [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md)

## File Role

`ArgumentedMenuDialogs.cpp` should own the item-argument variant of server-driven menu dialogs. These classes parse argumented entries with item data, quantity/price fields, description text, help display, and buy-confirm dispatch.

IDA confirms `ArgumentedMenuMenuDialog` vtables at `0x0061f428`, `0x0061f488`, and `0x0061f4b8`, plus `ArgumentedMenuMenuItemList` vtables at `0x0061f4c4`, `0x0061f54c`, and `0x0061f57c`. Current generated metadata omits these vtables.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md) | [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) | Packet-driven argumented item/menu dialog; exact child slice now includes the raw `0x0051f140` caveat. |
| [UID:00000I][ArgumentedMenuMenuItemList](by-class/ArgumentedMenuMenuItemList.md) | `0x0051f290-0x0051fc8c`, destructor island `0x00520abb-0x00520c16` | Specialized argumented item row list and rendering/selection behavior. |

[UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) is the shared creator/dispatcher that allocates `ArgumentedMenuMenuDialog` for packet subtype `10`. Keep the helper adjacent to the broader merchant/menu dialog family.

## 2026-06-03 IDA Refresh

- Restarted IDA MCP confirms `ArgumentedMenuMenuDialog` functions at `0x0051e9a0-0x0051f136`, `0x0051f160-0x0051f24c`, and `0x0051f250-0x0051f28d`.
- The constructor is reached from packet-dispatch sites `0x00517750` and `0x00517c97`, matching the subtype `10` factory route.
- The dialog primary vtable at `0x0061f428` points command/update slots to `0x0051f160` and `0x0051f250`; secondary/tertiary bases `0x0061f488` and `0x0061f4b8` are written by the constructor.
- The contiguous slice contains a raw, unreferenced code-shaped island at `0x0051f140-0x0051f158`; it is documented in [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md) but is not promoted to source-level method identity.

## Boundary Notes

Keep [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md) adjacent. The confirm/quantity input panes may fold into this file if final migration favors one argumented-menu source.

## Cross-References

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md)
- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)

## Changes

- What existed before: the page identified argumented menu classes, vtables, and factory relationship but had unevaluated scores.
- What it was changed to: scores were set to `70/82`.
- Summary and evidence: menu behavior and vtables are strongly supported; completion/confidence stay moderate because final split from `TextMenuDialogs.cpp` and input-dialog folding remain open.
- 2026-06-03 path/child split update:
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the dialog span was only represented by the broad `ArgumentedMenuDialogs` aggregate.
  - Changed to: `76/84`, path `NexusTK/ui/dialogs/`, and an exact [UID:0002TW][0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog](by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md).
  - Evidence: restarted IDA MCP function, constructor-caller, vtable-slot, command-handler, and raw `0x0051f140` disassembly checks.
