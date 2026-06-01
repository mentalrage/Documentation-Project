*** UID:00005J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FriendListDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)
- Address range: [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md), with destructor/thunk ranges listed on that page.
- Current recovered file: `source-3/simroot_v2/class_FriendListDialog.cpp`

## Class Purpose

`FriendListDialog` is the friend-list editor dialog. It creates twenty text edit controls in two columns, preloads friend names from config storage, and writes the edited names back when OK is pressed.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `FriendListDialog` | `0x0053f2c0-0x0053f800` | Builds dialog controls, chooses EPF/EPD asset layout, loads saved friend names, and opens the dialog. |
| `OnOkButton` | `0x0053f830-0x0053f920` | Reads all 20 text fields, trims/stores them in config, saves settings, calls the opcode `0x77` name-list upload helper when needed, and closes. |
| `OnSetFocus` | `0x0053f930-0x0053f939` | Updates hover/focus control state. |
| adjustor thunks | `0x005425b5`, `0x005425c0` | Destructor adjustor thunks. |
| scalar deleting destructor | `0x005426e0-0x00542735` | Resets vtables, destroys `DialogPane`, and conditionally frees memory. |

## Evidence Notes

- IDA MCP confirms every listed function start.
- `OnOkButton` stores rows at `g_pConfig + 2691552`, one config string per friend slot.
- IDA MCP callers show [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md) is called from `OnOkButton` after checking [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md); that helper reads the same config slots and serializes opcode `0x77` for [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md). The generated `g_isCashShopEnabled` name for this read is misleading.
- The dialog is feature-specific by assets `FRIEND.EPF`, `FRIEND.EPD`, `FRIEND.PAL`, and fixed 20-slot friend list layout.

## Cross-References

- [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)
- [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md)

## Changes

- 2026-05-28: Changed `OnSetFocus` from `0x0053f930-0x0053f938` to `0x0053f930-0x0053f939`.
  - Before: the method map omitted the final byte of the function.
  - After: the method map matches IDA's full function boundary.
  - Evidence: IDA MCP reports `sub_53F930` as `0x0053f930-0x0053f939`.
- Completion/confidence score update: existed before as `0/0`; changed to `80/88`. Summary: dialog role, 20-slot control layout, OK behavior, config storage, packet upload linkage, assets, method ranges, destructor support, and corrected boundary are documented with strong confidence. Evidence: main range `0x0053f2c0-0x0053f939`, `BuildAndSendInventoryData` cross-reference, `byte_66DEE0`, and friend-name opcode documentation.
