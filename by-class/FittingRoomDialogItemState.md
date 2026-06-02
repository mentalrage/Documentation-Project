*** UID:000051 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomDialogItemState

## Status

- Confidence: strong.
- Current Wave3 file: `class_FittingRoomDialogItemState.cpp`
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Autogen status: reconstructable class attached to [UID:0000JE][FittingRoom](by-file/FittingRoom.md); C++ is intentionally blank because category-entry fields, helper names, and JsonCpp-facing source shape are not final-source quality.
- Evidence basis: Wave3 inspection, generated source, and IDA MCP checks on 2026-05-23.

## Role

Embedded fitting-room state object for cached item-shop catalog data. It owns `ItemShop.jbn` persistence, category entry lists, encode/decode keys, and per-category loading from the downloaded catalog document. It consumes [UID:0000KI][JsonCpp](by-file/JsonCpp.md) document/value helpers for parsing but does not own the JsonCpp parser implementation.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00422020-0x00422329` | constructor | Builds `Documents\NexusTK\ItemShop\ItemShop.jbn`, initializes category storage, and loads cached data if present. |
| `0x00422330-0x0042246d` | destructor | Clears category entries and string buffers. |
| `0x00422470-0x00422599` | `ResetCategoryEntryLists` | Frees category vectors and resets lookup storage. |
| `0x004225a0-0x0042268e` | `SaveEncodedStateBuffer` | Persists encoded cache bytes. |
| `0x00422740-0x00422918` | `LoadEncodedStateBuffer` | Decodes and loads persisted cache bytes. |
| `0x00422b30-0x00422b92` | `TransformPersistedBuffer` | Applies the reversible encode/decode transform. |
| `0x00422ba0-0x00422e90` | `LoadOneCategoryFromDocument` | Loads one item category from the parsed document. |

## Notable Data

- Cache path: `NexusTK\ItemShop\ItemShop.jbn` under the user's documents folder.
- Encode/decode strings: `CASHEncodeDecodeByChris` and `sirhCyBedoceDedocnEHSAC`.
- Category storage is shared with [UID:00006T][ItemCatalog](by-class/ItemCatalog.md).
- The embedded equipment-entry vector is reset by [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md). IDA shows the vector at item-state offsets `+0x240/+0x244/+0x248` and `0xb4` byte entries with a trailing buffer triple at `+0xa8/+0xac/+0xb0`; see [UID:0001UH][FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md).
- `LoadEncodedStateBuffer` calls JsonCpp document/parse helpers at `0x004298f0` and `0x00429b30`, then uses `version` and the category keys documented in [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md).

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `82` | The class role, cache path, encode/decode keys, major methods, category loader, embedded catalog state, and linked exact memory pages are documented. Completion remains capped by unresolved category-entry field names, final helper names, and absent final C++ declaration. |
| Confidence `86` | The fitting-room ownership, cache behavior, JsonCpp consumer boundary, and method inventory are supported by exact memory pages and string/caller evidence. Confidence is not higher because the final source split between `FittingRoom.cpp` and a possible `ItemCatalog` helper remains open. |

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:00006T][ItemCatalog](by-class/ItemCatalog.md)
- [UID:00004Z][FittingEquipmentState](by-class/FittingEquipmentState.md)
- [UID:0001UH][FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md)
- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)

## Changes

- 2026-06-02: Raised completion from `80` to `82`, marked the class reconstructable, and attached it to [UID:0000JE][FittingRoom](by-file/FittingRoom.md). C++ remains blank because final category-entry fields and JsonCpp-facing source names are not source-quality.
- Completion/confidence score update: existed before as `0/0`; changed to `80/86`. Summary: role, cache file, encode/decode strings, category loading, major methods, and related layout evidence are documented with strong confidence; remaining work is deeper field-by-field naming and final C++ reconstruction. Evidence: method address table from `0x00422020-0x00422e90`, JsonCpp parser notes, `FittingEquipmentStateLayout`, and fitting-room memory cluster references.
