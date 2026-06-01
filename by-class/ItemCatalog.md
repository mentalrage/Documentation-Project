*** UID:00006T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemCatalog

## Status

- Confidence: strong for embedded fitting-room catalog lookup behavior.
- Current Wave3 file: `class_ItemCatalog.cpp`
- Proposed source module: [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md), or folded into [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Memory range: [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md)
- Evidence basis: Wave3 inspection and IDA MCP xref checks on 2026-05-23.

## Role

Small catalog lookup facade over fitting-room item-shop category storage. Consumers ask for the number of entries in a category and retrieve a category entry by index.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00422690-0x004226cc` | `GetItemCount` | Counts entries for a category. |
| `0x004226d0-0x0042273e` | `GetItemByIndex` | Retrieves one category entry by index. |

## Evidence

- Wave3 class summary places this object at `g_pFittingRoomDialog + 0x504`.
- IDA MCP caller evidence ties both methods to fitting-room list/render helpers, including `0x0041ee10`, `0x0041f2b0`, and `0x0041fba0`.

## Cross-References

- [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md)
- [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md)
- [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/84`. Summary: fitting-room catalog lookup facade role, two confirmed methods, embedded-object placement, caller evidence, and source-module alternatives are documented with strong confidence; completion is capped because the page is intentionally small and category storage internals live in related fitting-room docs. Evidence: `ItemCatalogLookup`, `FittingRoomUiCore`, `FittingRoomListPane`, and `FittingRoomDialogItemState`.
