*** UID:00000I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArgumentedMenuMenuItemList

## Status

- Confidence: strong for included methods and list role; one Wave3 listed method is not an IDA function.
- Likely source file: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), or folded into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- Main address range: [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- Destructor/thunk range: [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_ArgumentedMenuMenuItemList.cpp`

## Class Purpose

`ArgumentedMenuMenuItemList` is the specialized `ListPane` for argumented item menu rows. It tracks the dialog command type, owner dialog id, list parameter, and owner dialog pointer. It updates the description text for the selected item, handles item-help hover behavior, and draws icon/name/count/price or percent metadata for each row.

## Class Shape

- Base family: specialized `ListPane` used by argumented menu dialogs.
- Owned context: command type at `+0x14c`, owner id at `+0x150`, list parameter at `+0x154`, and owner dialog pointer at `+0x158` are documented by the related packet helper.
- UI role: selection updates description text and item-help state; draw path renders icon/name/count/price/percent row metadata.
- Source placement: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), or folded into [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md).

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0051f290-0x0051f30a` | `ArgumentedMenuMenuItemList` | Constructs/copies list-pane state from an existing source list state. |
| `0x0051f310` | Wave3 listed non-function | Wave3 has an excluded method entry here, but IDA MCP reports no function at this address. |
| `0x0051f5b0-0x0051f63c` | `SelectItemAndUpdateText` | Selects a row and updates the dialog description/static text area. |
| `0x0051f710-0x0051f71a` | `ForwardUpdatePendingItemState` | Tiny owner/list state forwarder. |
| `0x0051f720-0x0051f83f` | `HandleMouseEvent` | Handles hover/select behavior and opens contextual `ItemHelpPane` when enabled. |
| `0x0051f840-0x0051fc8c` | `DrawMenuItem` | Draws item icon, name, quantity, price, and percent metadata. |
| `0x00520abb-0x00520ad0` | vtable adjustor thunks | Compiler-generated this-adjustors forwarding to the destructor. |
| `0x00520bb0-0x00520c16` | scalar deleting destructor | Resets vtables, notifies the global argumented-menu pane if present, tears down base list state, and deletes according to flags. |

## Evidence Notes

- Wave3 summary: specialized list-pane implementation for argumented item dialogs, including selection text updates and contextual help-pane behavior.
- IDA MCP confirms all included method starts and reports no function at `0x0051f310`.
- Constructor callers are in the argumented confirm/input flow at `0x0051feec` and `0x00520347`, while the owning dialog builds an equivalent list object inline during packet construction.
- `SendArgumentedItemQuantityPacket` at `0x0051f640` consumes this list's command type, owner id, selected item argument, and owner dialog pointer fields.
- Current generated source omits some excluded helper/thunk bodies even though IDA confirms the thunk functions; this is tracked in [wave3_data_issues](../wave3_data_issues.md).

## Cross-References

- [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:0000TY][ArgumentedItemPurchaseHelpers_51f450_51f640](by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md)
- [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md)
- [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)

## Changes

- What existed before: the page had method and caveat evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `70/84`, and a class-shape section was added for base family, owned context offsets, UI role, and source placement.
- Summary and evidence: IDA-confirmed method starts and packet-helper field consumption support strong confidence; the non-function Wave3 method at `0x0051f310` and generated thunk omissions keep completion below high.
