*** UID:00002Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClientItemMenuItemList

## Status

- Confidence: strong for item-menu list behavior; medium for shared destructor ownership.
- Likely source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- Main address range: [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md)
- Current recovered file: `source-3/simroot_v2/class_ClientItemMenuItemList.cpp`

## Class Purpose

`ClientItemMenuItemList` is the row-list widget for client-side item action menus. It stores packet/item context from the owning dialog, appends locally available inventory item rows, forwards activation into the shared item-action context, and draws icon/name rows.

## Method Notes

| Method or range | Address | Role |
| --- | --- | --- |
| `ClientItemMenuItemList` | `0x0051c470-0x0051c4dc` | Constructs the `ListPane` with client item-menu row geometry, stores packet/item context fields, and installs three vtables. |
| append row helper | `0x0051c4e0-0x0051c548` | Builds/appends a client item row from item code, item id/style, and display label. |
| selected-action packet helper | `0x0051c550-0x0051c603` | Builds opcode `0x39` payload for the current selected row. |
| explicit-action packet helper | `0x0051c610-0x0051c6ac` | Builds opcode `0x39` payload for a caller-supplied item action byte. |
| `OnItemActivated` thunk | `0x0051c6b0-0x0051c6bb` | Loads owner/context from `this + 0x158` and jumps to shared activation logic at `0x0049de70`. |
| `DrawMenuItemEntry` | `0x0051c6c0-0x0051ca3c` | Draws selected/unselected item rows with icon and ellipsis-truncated item name in high-resolution and legacy layouts. |
| shared destructor glue | `0x00520ad1`, `0x00520adc`, `0x00520c20` | Secondary/tertiary adjustor thunks and shared scalar deleting destructor also referenced by spell menu item list vtables. |

## Evidence Notes

- IDA MCP confirms `0x0051c470`, `0x0051c6b0`, and `0x0051c6c0` as functions.
- IDA disassembly confirms raw helper-shaped code at `0x0051c4e0`, `0x0051c550`, and `0x0051c610`, though those addresses are not currently function starts.
- IDA xrefs show `ClientItemMenuDialog` constructs this list from `0x0051ba35` and `0x0051bf64`.
- IDA xrefs show destructor thunks `0x00520ad1` and `0x00520adc`, and scalar deleting destructor `0x00520c20`, are shared by `ClientItemMenuItemList`, `ServerSpellMenuItemList`, and `ClientSpellMenuItemList` vtables.
- Active generated output treats `0x004f3b60` as `ClientItemMenuItemList::~ClientItemMenuItemList`, but IDA caller fanout shows it is broad `ListPane` cleanup, not a private client item-menu method.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:00007A][ListPane](by-class/ListPane.md)

## Changes

- What existed before: the page documented item-menu row-list behavior, raw helper-shaped packet functions, draw path, and shared destructor caveat, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: constructor, append/helper ranges, selected/explicit packet helpers, activation, draw, constructor xrefs, and shared destructor ownership are covered; complete row struct names and final helper ownership remain open.
