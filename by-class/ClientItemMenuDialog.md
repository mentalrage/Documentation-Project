*** UID:00002P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClientItemMenuDialog

## Status

- Confidence: strong for behavior and item-menu placement.
- Likely source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), under the broader [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) family
- Address range: [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ClientItemMenuDialog.cpp`

## Class Purpose

`ClientItemMenuDialog` is the client-side item context menu. It builds local menu actions for an item, dispatches selected commands, and keeps the action state synchronized with selection and mode flags.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClientItemMenuDialog` | `0x0051b880-0x0051c309` | Builds the client-side item action menu from anchor rectangle, packet/item data, and mode flag. |
| `HandleMenuCommand` | `0x0051c310-0x0051c421` | Dispatches selected menu action. |
| `UpdateActionButtonState` | `0x0051c430-0x0051c46c` | Enables/disables local item menu actions. |

## Evidence Notes

- Wave3 summary identifies this as the client-side context menu dialog for item actions.
- IDA MCP confirms all three method starts.
- This should stay near `ServerItemMenuDialog` because both implement item-action menu UI from different authority sources.
- IDA xrefs show this dialog constructs [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md) at `0x0051ba35` and `0x0051bf64`; keep the list class in the same source module.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)

## Changes

- What existed before: the page documented client item-menu behavior, methods, source placement, and list-class construction evidence, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/84`.
- Summary and evidence: constructor, command handling, action-button state, item-menu placement, and related list class are covered; detailed menu action table and final field/layout names remain incomplete.
