*** UID:0000JN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FriendListDialog

## Status

- Confidence: strong for class behavior and IDA boundaries.
- Proposed module folder: `social/`
- Proposed source file: `social/FriendListDialog.cpp`
- Possible split files: `ui/dialogs/FriendListDialog.cpp`
- Evidence basis: Wave3 class inspection, generated `simroot_v2` source, and IDA MCP function-boundary/xref checks on 2026-05-23.

## Hypothesis

`FriendListDialog` is a self-contained social dialog source file. It builds a 20-entry friend-name editor from saved config strings, supports old/new asset layouts (`FRIEND.EPF`/`FRIEND.EPD`), writes edited names back into config on OK, optionally sends the updated friend/name-list state through opcode `0x77`, saves user settings, and closes the dialog.

The implementation uses generic dialog/control primitives, but the asset names, config table, and fixed two-column friend-name layout make this feature-specific rather than a generic `DialogPane` source.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `FriendListDialog` | `0x0053f2c0-0x0053f939`, destructor/thunks at `0x005425b5-0x00542735` | `class_FriendListDialog.cpp` | Friend-list editor dialog with two columns of text controls, OK save behavior, focus handling, and destructor. |

## Boundary And Data Notes

- IDA MCP confirms `0x0053f2c0`, `0x0053f830`, `0x0053f930`, `0x005425b5`, `0x005425c0`, and `0x005426e0`.
- Constructor callers include `0x0053ddb0`, `0x005a5bd0`, and `0x005bd000`, suggesting the dialog can be opened from multiple UI/menu paths.
- `OnOkButton` is vtable-referenced at `0x00620f2c` and writes 20 friend-name strings back to `g_pConfig + 2691552`.
- IDA MCP caller evidence shows `OnOkButton` calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md) only when [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) / candidate `g_friendNameListSyncEnabled` is nonzero. That helper serializes the same 20 config slots into opcode `0x77`; treat its generated `InventoryData` name and the local `g_isCashShopEnabled` alias as suspect, and prefer [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md) semantics in social feature docs.
- The constructor has an asset-mode branch: EPF layout uses `FRIEND.EPF`/`FRIEND.PAL`; fallback layout uses `FRIEND.EPD`/`NPAL8.PAL`.

## Migration Notes

This class is safe to use as a source-layout anchor after ordinary review. A dry-run migration should be a simple one-class file move:

```powershell
python source-3\wave3.py create file FriendListDialog.cpp --kind source --simpath social/FriendListDialog.cpp --dry-run
python source-3\wave3.py attach class FriendListDialog --to-file FriendListDialog.cpp
```

## Cross-References

- [UID:00005J][FriendListDialog](by-class/FriendListDialog.md)
- [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md)
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0000JS][Group](by-file/Group.md)

## Changes

- 2026-05-28: Changed the core `FriendListDialog` range from `0x0053f2c0-0x0053f938` to `0x0053f2c0-0x0053f939`.
  - Before: the file-level range ended before the final byte of `OnSetFocus`.
  - After: the range includes full `OnSetFocus`, with padding before `ProfileDialog`.
  - Evidence: IDA MCP reports `sub_53F930` as `0x0053f930-0x0053f939`; bytes after that end are `0xcc` until `0x0053f940`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: class behavior, boundaries, save/sync opcode behavior, asset-mode branch, constructor/callback evidence, and range correction are well documented; confidence is capped by exact final folder placement and the suspect generated `BuildAndSendInventoryData` alias.
