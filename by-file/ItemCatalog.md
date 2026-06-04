*** UID:0000KD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/cashshop/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ItemCatalog

## Status

- Confidence: strong for embedded catalog behavior, medium for standalone file placement.
- Proposed module: `cashshop/ItemCatalog.cpp`, or embedded inside `cashshop/FittingRoom.cpp`.
- Main class: [UID:00006T][ItemCatalog](by-class/ItemCatalog.md)
- Main memory range: [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md); surrounding cache/catalog state is [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md)
- Evidence basis: live IDA MCP function, caller, call-site, padding, and decompilation checks on 2026-06-04.

## Hypothesis

`ItemCatalog` is an embedded fitting-room catalog helper stored at `g_pFittingRoomDialog + 0x504`. It is probably not a project-wide item database; current evidence ties it to item-shop/fitting-room category enumeration and preview item entries.

## Contents

Likely source-level contents:

- `ItemCatalog::GetItemCount(unsigned char categoryId)` at [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md), IDA range `0x00422690-0x004226cd`.
- `ItemCatalog::GetItemByIndex(unsigned char categoryId, short itemIndex)` at [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md), IDA range `0x004226d0-0x0042273f`.
- Category lookup helper structures initialized, reset, and populated by [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md), which parses item-shop JSON through JsonCpp and then stores fitting-room-owned entry vectors.

## Evidence

- 2026-06-04 IDA MCP confirms `0x00422690-0x004226cd` and `0x004226d0-0x0042273f` as the only functions in the lookup child span.
- Live call sites show fitting-room ownership: `0x0041ce50`, `0x0041fc43`, and `0x00420d0b` pass `this + 0x504` or `g_pFittingRoomDialog + 0x504` as the catalog object.
- `GetItemCount` callers are fitting-room category/list/paint/key/selection paths at `0x0041ce5d`, `0x0041ee41`, `0x0041f4eb`, `0x0041fc49`, and `0x00420d1c`.
- `GetItemByIndex` callers are fitting-room list/paint/input/selection paths at `0x0041ee5e`, `0x0041f51d`, `0x0041f5f0`, `0x0041fe16`, and `0x00420d2d`.
- Decompilation confirms the catalog tree at `this + 544` with sentinel at `this + 548`; `GetItemCount` returns the pointer-vector length, while `GetItemByIndex` returns an entry pointer only when the category exists and the index is in range.
- Live byte checks confirm local padding at `0x0042268f-0x00422690`, `0x004226cc-0x004226d0`, and `0x0042273f-0x00422740`, keeping the lookup range cleanly split from neighboring fitting-room item-state methods.

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

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 84 | The page now records a valid cash-shop path, source-placement options, exact live IDA method ranges, fitting-room-only caller set, `g_pFittingRoomDialog + 0x504` call-site evidence, backing category-tree behavior, padding boundaries, and reconstruction gates. |
| Confidence | 86 | Live IDA strongly supports embedded fitting-room catalog ownership and `NexusTK/cashshop/` placement. Confidence remains capped below high because the final source split between standalone `ItemCatalog.cpp` and private `FittingRoom.cpp` helper code is still unresolved. |

## Changes

- 2026-06-04: Raised from `76/78` to `84/86`, set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/cashshop/"`, and replaced stale provenance notes with live IDA evidence.
  - Before: the page had a blank projected path, an autogen error row, and relied on older non-IDA source leads for embedded-object placement.
  - After: the page has a valid cash-shop path, exact method ranges, caller/call-site evidence tying the object to `g_pFittingRoomDialog + 0x504`, padding checks, score rationale, and the standalone-vs-embedded source split caveat.
  - Evidence: 2026-06-04 IDA MCP `py_eval` confirmed functions `0x00422690-0x004226cd` and `0x004226d0-0x0042273f`, fitting-room callers at `0x0041ce5d`, `0x0041ee41`, `0x0041f4eb`, `0x0041fc49`, `0x00420d1c`, `0x0041ee5e`, `0x0041f51d`, `0x0041f5f0`, `0x0041fe16`, and `0x00420d2d`, `+0x504` object call sites, local padding bytes, and decompiled category-tree/vector behavior.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:78`.
  - Summary/evidence: embedded fitting-room catalog behavior, lookup ranges, callers, JSON/catalog state relationship, and source placement options are documented; completion is lower because the document is concise and does not deeply map the backing category structures or parser population path.
