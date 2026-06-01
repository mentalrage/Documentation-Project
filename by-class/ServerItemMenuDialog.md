*** UID:0000CZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ServerItemMenuDialog

## Status

- Confidence: strong for behavior and item-menu placement, medium for generated method name quality.
- Likely source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), under the broader [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) family
- Address range: [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ServerItemMenuDialog.cpp`

## Class Purpose

`ServerItemMenuDialog` displays item actions supplied by server packet data. It initializes a context menu from packet/action data, dispatches the selected menu action, and updates action availability.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InitializeFromPacket` | `0x0051a520-0x0051ac8d` | Builds the server-provided item action menu from packet data. Wave3 currently names this like `~ServerItemMenuDialog`, but its signature and summary are constructor/init-like. |
| `OnDialogAction` | `0x0051acb0-0x0051ae41` | Dispatches selected menu action. |
| `UpdateActionAvailability` | `0x0051ae50-0x0051ae8c` | Enables/disables available item actions. |

## Evidence Notes

- Wave3 summary identifies this as a server-side item context menu dialog.
- IDA MCP confirms all three method starts.
- The first method's generated name is suspect and is tracked in [wave3_data_issues](../wave3_data_issues.md).
- The dialog builds or inline-initializes the private [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md) row-list widget; keep the list class in the same source module.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents behavior, likely file ownership, by-memory grouping, three confirmed method starts, and generated-name caveat; confidence remains capped by suspect generated method naming.
