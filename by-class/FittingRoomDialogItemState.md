*** UID:000051 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomDialogItemState

## Status

- Confidence: strong.
- Historical projection: `class_FittingRoomDialogItemState.cpp` remains useful only as prior naming context; it was not used as evidence for the 2026-06-05 score update.
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Autogen status: reconstructable class attached to [UID:0000JE][FittingRoom](by-file/FittingRoom.md); C++ is intentionally blank because category-entry fields, helper names, and JsonCpp-facing source shape are not final-source quality.
- Evidence basis: existing project documentation, exact by-memory pages, and IDA MCP checks through the A003 live refresh on 2026-06-05.

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
- [UID:0002UB][0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper](by-memory/0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper.md) is the category-storage destructor/free helper called from [UID:0002EB][0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor](by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md) at `0x00422415`; final field/type names for the nested category-storage block remain pending.
- Category lookup and entry-vector lifecycle helpers now attached to this class include [UID:0002U4][0x00423000-0x0042305c.FittingRoomCategoryLookupInsertNode](by-memory/0x00423000-0x0042305c.FittingRoomCategoryLookupInsertNode.md), [UID:0002U8][0x00423470-0x0042365d.FittingRoomCategoryLookupFinalize](by-memory/0x00423470-0x0042365d.FittingRoomCategoryLookupFinalize.md), [UID:0002U9][0x00423660-0x004236d7.FittingRoomCategoryLookupCleanup](by-memory/0x00423660-0x004236d7.FittingRoomCategoryLookupCleanup.md), [UID:0002UE][0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper](by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md), [UID:0002UF][0x004238f0-0x00423952.FittingRoomCategoryEntryVectorDestroy](by-memory/0x004238f0-0x00423952.FittingRoomCategoryEntryVectorDestroy.md), [UID:0002UH][0x00423a60-0x00423a8d.CategoryTreeSentinelAllocator](by-memory/0x00423a60-0x00423a8d.CategoryTreeSentinelAllocator.md), and [UID:0002UI][0x00423a90-0x00423af4.CategoryTreeNodeCleanupFree](by-memory/0x00423a90-0x00423af4.CategoryTreeNodeCleanupFree.md). `0002U4` is the category lookup insertion helper called by `LoadOneCategoryFromDocument`; it allocates/prepares a category tree node through `0002UH`, moves the temporary category transfer record into node fields, and clears source ownership. `0002U9` is the unlink/free helper used by `0002U8` when category lookup insertion/finalization must discard a node. These helpers remain documented inside the [UID:0002EE][0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers](by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md) address aggregate for coverage nesting, but their ordinary source callers and owned storage are item-state category lifecycle paths. The same aggregate also contains shared StringUtil, VectorHelpers, DAT/vector, CRT wrapper, and cleanup-chunk siblings; those siblings prevent `0002EE` itself from being a direct child of this class even though this class owns the exact category-storage children.
- The embedded equipment-entry vector is reset by [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md). IDA shows the vector at item-state offsets `+0x240/+0x244/+0x248` and `0xb4` byte entries with a trailing buffer triple at `+0xa8/+0xac/+0xb0`; see [UID:0001UH][FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md).
- `LoadEncodedStateBuffer` calls JsonCpp document/parse helpers at `0x004298f0` and `0x00429b30`, then uses `version` and the category keys documented in [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md).
- 2026-06-05 A003 live IDA refresh on [UID:0002E4][0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson](by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md) confirms the category-entry parser receives a caller-allocated `0xc0` byte entry, stores the active byte/name/tile/color fields, and appends packed 6-byte part records from JsonCpp `items` elements.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The class role, cache path, encode/decode keys, major methods, category loader, embedded catalog state, linked exact memory pages, category lookup insertion/finalize/cleanup/sentinel helpers, category-entry parser offsets, and `0002EE` mixed-aggregate parent-source boundary are documented. Completion remains capped by unresolved part-record field names, final helper names, and absent final C++ declaration. |
| Confidence `88` | The fitting-room ownership, cache behavior, JsonCpp consumer boundary, category-entry layout evidence, and method inventory are supported by exact memory pages and string/caller evidence. Confidence is not higher because the final source split between `FittingRoom.cpp` and a possible `ItemCatalog` helper remains open. |

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:00006T][ItemCatalog](by-class/ItemCatalog.md)
- [UID:00004Z][FittingEquipmentState](by-class/FittingEquipmentState.md)
- [UID:0001UH][FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md)
- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md)
- [UID:0002EE][0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers](by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:0002UB][0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper](by-memory/0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper.md)
- [UID:0002UE][0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper](by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md)
- [UID:0002UF][0x004238f0-0x00423952.FittingRoomCategoryEntryVectorDestroy](by-memory/0x004238f0-0x00423952.FittingRoomCategoryEntryVectorDestroy.md)
- [UID:0002UH][0x00423a60-0x00423a8d.CategoryTreeSentinelAllocator](by-memory/0x00423a60-0x00423a8d.CategoryTreeSentinelAllocator.md)
- [UID:0002UI][0x00423a90-0x00423af4.CategoryTreeNodeCleanupFree](by-memory/0x00423a90-0x00423af4.CategoryTreeNodeCleanupFree.md)

## Changes

- 2026-06-08 A002 Batch101 parent-source follow-up: Raised completion from `85` to `86` while keeping confidence `88` after adding an explicit parent-candidate boundary for [UID:0002EE][0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers](by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md). This class is the direct parent for exact category lookup/lifecycle children that clear the gate, but not for the full mixed aggregate because the aggregate also contains shared StringUtil/vector/DAT helper and compiler-cleanup siblings.
- 2026-06-07 A010 Batch066: Added [UID:0002U8][0x00423470-0x0042365d.FittingRoomCategoryLookupFinalize](by-memory/0x00423470-0x0042365d.FittingRoomCategoryLookupFinalize.md) and [UID:0002U9][0x00423660-0x004236d7.FittingRoomCategoryLookupCleanup](by-memory/0x00423660-0x004236d7.FittingRoomCategoryLookupCleanup.md) to the category lookup helper list while keeping scores at `85/88`. Evidence is the child pages' documented single category-lookup caller/callee relationship and this class's existing category-storage ownership.
- 2026-06-07 A007 Batch064: Raised completion from `84` to `85` after adding [UID:0002U4][0x00423000-0x0042305c.FittingRoomCategoryLookupInsertNode](by-memory/0x00423000-0x0042305c.FittingRoomCategoryLookupInsertNode.md) to the documented category-loader helper chain. Parent [UID:0000JE][FittingRoom](by-file/FittingRoom.md) is already `85/87`, so this class can now serve as the direct parent for exact FittingRoomDialogItemState category helpers that individually clear the 85/85 gate.
- 2026-06-07 A005 Batch 001 follow-up: Added [UID:0002UB][0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper](by-memory/0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper.md) to the class-level category-storage lifecycle notes after the page became free. Evidence: live IDA xrefs show the ordinary call from [UID:0002EB][0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor](by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md) at `0x00422415`.
- 2026-06-07 A006 Batch 001: Added explicit class-level ownership for four helper pages formerly autogen-unassigned from the category helper island. Evidence: the helpers are direct callees of this class's constructor/destructor/reset/category-lookup paths, the class and file owner both meet the >=80 gate, and the helper pages remain below final C++ threshold.
- 2026-06-05: Raised completion/confidence from `82/86` to `84/88` after A003 live IDA MCP confirmed the category-entry parser's caller allocation/setup, concrete field offsets, nested part-vector records, and JsonCpp field string refs. Replaced generated-source evidence wording with existing-doc/IDA evidence wording; C++ remains blank until final field names and source declarations are ready.
- 2026-06-02: Raised completion from `80` to `82`, marked the class reconstructable, and attached it to [UID:0000JE][FittingRoom](by-file/FittingRoom.md). C++ remains blank because final category-entry fields and JsonCpp-facing source names are not source-quality.
- Completion/confidence score update: existed before as `0/0`; changed to `80/86`. Summary: role, cache file, encode/decode strings, category loading, major methods, and related layout evidence are documented with strong confidence; remaining work is deeper field-by-field naming and final C++ reconstruction. Evidence: method address table from `0x00422020-0x00422e90`, JsonCpp parser notes, `FittingEquipmentStateLayout`, and fitting-room memory cluster references.
