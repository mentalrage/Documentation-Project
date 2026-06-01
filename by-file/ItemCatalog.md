*** UID:0000KD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ItemCatalog

## Status

- Confidence: strong for embedded catalog behavior, medium for standalone file placement.
- Proposed module: `cashshop/ItemCatalog.cpp`, or embedded inside `cashshop/FittingRoom.cpp`.
- Current Wave3 file: `class_ItemCatalog.cpp`
- Main class: [UID:00006T][ItemCatalog](by-class/ItemCatalog.md)
- Main memory range: [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md); surrounding cache/catalog state is [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md)
- Evidence basis: Wave3 class inspection, generated fitting-room list source, and IDA MCP xref checks on 2026-05-23.

## Hypothesis

`ItemCatalog` is an embedded fitting-room catalog helper stored at `g_pFittingRoomDialog + 0x504`. It is probably not a project-wide item database; current evidence ties it to item-shop/fitting-room category enumeration and preview item entries.

## Contents

Likely source-level contents:

- `ItemCatalog::GetItemCount(unsigned char categoryId)` at [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md).
- `ItemCatalog::GetItemByIndex(unsigned char categoryId, short itemIndex)` at [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md).
- Category lookup helper structures initialized, reset, and populated by [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md), which parses item-shop JSON through JsonCpp and then stores fitting-room-owned entry vectors.

## Evidence

- Wave3 describes `ItemCatalog` as embedded fitting-room state at `g_pFittingRoomDialog + 0x504`.
- IDA MCP confirms `0x00422690-0x004226cc` and `0x004226d0-0x0042273e` as real functions.
- IDA MCP reports callers from fitting-room list/display functions, including `0x0041ee10`, `0x0041f2b0`, and `0x0041fba0`.
- Generated `FittingRoomListPane::UpdateScrollBar` gets the catalog from `g_pFittingRoomDialog + 0x504` and calls both methods to count visible items.

## Proposed Placement

```text
cashshop/
  ItemCatalog.h
  ItemCatalog.cpp
```

If the original code kept only feature-private helpers in one source file, fold this into:

```text
cashshop/
  FittingRoom.cpp
```

## Cross-References

- [UID:00006T][ItemCatalog](by-class/ItemCatalog.md)
- [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md)
- [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:78`.
  - Summary/evidence: embedded fitting-room catalog behavior, lookup ranges, callers, JSON/catalog state relationship, and source placement options are documented; completion is lower because the document is concise and does not deeply map the backing category structures or parser population path.
