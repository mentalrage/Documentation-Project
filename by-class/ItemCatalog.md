*** UID:00006T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ItemCatalog

## Status

- Confidence: very strong for historical embedded fitting-room catalog lookup naming and the exact no-class/no-code disposition.
- Current disposition: non-reconstructable, non-emitting historical facade/name page. `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and both blank formal channels are intentional.
- Active source route: the only source-bearing historical pair, [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md), emits as `FittingRoomDialogItemState` methods through [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) and [UID:0000JE][FittingRoom](by-file/FittingRoom.md) in `NexusTK/cashshop/FittingRoom.cpp`.
- Type identity: current IDA has no `ItemCatalog` UDT, vtable, RTTI, constructor/destructor, singleton, or lifetime object. It does have exact current FittingRoom item-state/catalog UDTs that independently establish the active owner and layouts.
- Header/source disposition: no `ItemCatalog.cpp` or `ItemCatalog.h` is required. The active declarations already live in UID000051's class fragment; this page supplies provenance, not an emitted declaration.
- Evidence basis: retained 2026-06-04 through 2026-07-05 function/caller checks plus the exhaustive 2026-08-15 B006 whole-file review of current hashes, callers, UDTs, compiler lowerings, negative identity evidence, and generated output.

## Role

Historical name for a small catalog lookup facade over fitting-room item-shop category storage. Consumers ask for the number of entries in a category and retrieve a category entry by index, but the live receiver is the dialog's `FittingRoomDialogItemState` subobject at `+0x504`, the storage is `FittingRoomDialogItemState::m_categoryLookup` at `+0x220`, and the source-bearing methods are owned by UID000051. The historical name does not establish a compiled class identity.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `[0x00422690,0x004226cd)` | historical `ItemCatalog::GetItemCount`; active `FittingRoomDialogItemState::GetItemCount` | 61 bytes, SHA256 `FC4EB4E08022A466526BA3C429B1882B83B9BD430A660773875F7BA4B43E4544`; counts entries for a category; active owner/emitter is UID000051. |
| `[0x004226d0,0x0042273f)` | historical `ItemCatalog::GetItemByIndex`; active `FittingRoomDialogItemState::GetItemByIndex` | 111 bytes, SHA256 `309361ABC3C49B47DF73D32EA5386F3D1E5602B6CFCEE9B8A90FF641C754F941`; retrieves one category entry by index; active owner/emitter is UID000051. |

## Evidence

- 2026-06-04 IDA MCP confirms the method ranges as `0x00422690-0x004226cd` and `0x004226d0-0x0042273f`.
- Live call sites pass `this + 0x504` or `g_pFittingRoomDialog + 0x504` as the object, including `0x0041ce50`, `0x0041fc43`, and `0x00420d0b`.
- `GetItemCount` is called from fitting-room category rebuild, list scroll update, paint, key scroll, and selection validation paths.
- `GetItemByIndex` is called from fitting-room list scroll update, paint, input, and selection validation paths.
- Decompilation confirms both methods use category lookup storage at `this + 544` / `+0x220`; the compiler layout state begins at `this + 548` / `+0x224`. The first returns vector count and the second returns a category entry pointer only when the category exists and the signed upper-bound test passes.
- Local padding checks isolate the class methods from neighboring fitting-room item-state functions at `0x0042268f-0x00422690`, `0x004226cd-0x004226d0`, and `0x0042273f-0x00422740`; byte `0x004226cc` is the final immediate byte of the first method's `retn 4`, not padding.
- 2026-07-05 B003 MCP session `supervisor_recovery_20260705` reconfirms exact ranges `0x00422690-0x004226cd` and `0x004226d0-0x0042273f`, sizes `0x3d` / 61 and `0x6f` / 111 (Verified with MCP `int_convert`), the same ten FittingRoom callers, `g_pFittingRoomDialog + 0x504` receiver setup, item-state category lookup at `+0x220/+0x224`, no data xrefs, no VA/RVA pointer hits, no local original UDT records, and formal C++ now emitted by [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md) through [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md).
- 2026-08-15 B006 current evidence distinguishes the missing historical class from the now-present active types: `ItemCatalog` type query returns zero records; `FittingRoomDialogItemState` is ordinal 884, size `0x280`, with `m_categoryLookup` at `+0x220`; `FittingRoomCatalogEntry` is ordinal 875, size `0xc0`, with category `+0x00`, enabled `+0x04`, tile `+0x06`, color `+0x08`, name `+0x0a`, and parts vector `+0xb4`; `FittingRoomCategoryMap` is ordinal 881, size `0x20`.
- The complete reachability set is ten call sites across six unique FittingRoom functions: count calls at `0x0041ce5d`, `0x0041ee41`, `0x0041f4eb`, `0x0041fc49`, `0x00420d1c`; indexed calls at `0x0041ee5e`, `0x0041f51d`, `0x0041f5f0`, `0x0041fe16`, `0x00420d2d`. Both entries have zero data xrefs and zero VA/RVA/raw-offset pointer routes.
- The helper at `[0x00423e40,0x00423ea8)` is 104-byte compiler-generated MSVC byte-key hash-map `find` lowering (SHA256 `C9AA3ACE28EF4DDECC1877FCB696B9213137B40ED1E3F15AFA70BF0E8527B41F`), not a source-authored ItemCatalog API. Shared `0x00421290` and `0x00423810` vector lowerings are represented by ordinary vector copy/destruction.

## Current Active Type And Source Evidence

- The dialog's item-state receiver at `+0x504`, current `0x280` item-state UDT, `m_categoryLookup +0x220`, and every caller converge on UID000051 rather than a separate ItemCatalog object.
- Source-facing `FittingRoomCategoryMap` remains the accepted C++03 alias over a byte key and `std::vector<FittingRoomCatalogEntry*>`; compiler sentinel/bucket implementation details do not create a source class.
- The formal accessor bodies use `m_categoryLookup.find/end`, return zero/`NULL` when absent, copy the found vector for indexed lookup, retain the signed-short upper-bound comparison, and intentionally add no negative-index guard.
- Validator-generated `NexusTK/cashshop/FittingRoom.cpp` contains the UID000051 declarations and UID0000WV definitions. No standalone ItemCatalog generated source or header exists, and that absence is the expected completed state.

## Negative Class Identity Evidence

- No ItemCatalog UDT, vtable, RTTI, constructor, destructor, scalar-deleting destructor, object allocation, singleton, global, static data, or lifetime route was found.
- No ItemCatalog-owned string, constant, table, data island, resource, import, protocol record, or literal was found.
- Neither method entry nor the map-find lowering has a data, vtable, callback, VA, RVA, or raw pointer route; all executable reachability is ordinary FittingRoom code.
- `g_pFittingRoomDialog` is independent [UID:00028I][0x0067a73c-0x0067a740.g_pFittingRoomDialog](by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md) receiver/lifetime support, not ItemCatalog-owned state.
- The broad UID0000WU page remains a non-emitting index/container; emitting from this class would duplicate exact child code or invent a class identity.

## 2026-06-16 A001 Evidence Refresh

Live IDA MCP on database `b001_mappane_0001AW_20260616` reconfirmed the current executable evidence without changing the owner route. `lookup_funcs` reports `sub_422690` at `0x00422690` size `0x3d`, `sub_4226D0` at `0x004226d0` size `0x6f`, parser successor `0x00422740` size `0x1d9`, and category/vector helper `0x00423810` size `0x50`; `0x0042273f` is not a function start. `xrefs_to` still shows five `GetItemCount` callers (`0x0041ce5d`, `0x0041ee41`, `0x0041f4eb`, `0x0041fc49`, `0x00420d1c`) and five `GetItemByIndex` callers (`0x0041ee5e`, `0x0041f51d`, `0x0041f5f0`, `0x0041fe16`, `0x00420d2d`), all inside fitting-room list/render/input/selection paths.

The decompiler still exposes only descriptive layout evidence: category lookup through `sub_423E40`, sentinel comparison against `this[137]`, item-vector count from `(end - begin) >> 2`, and indexed entry return after a temporary vector copy/cleanup through `sub_421290` and `sub_423810`. `search_structs` for `ItemCatalog`, `FittingRoomItem`, and `Category` returned no local IDA UDT records, so the final category-entry type and field names remain unsafe to promote beyond descriptive names.

## Reconstruction Notes

Do not emit a standalone `ItemCatalog` class body, forward declaration, header, or `cashshop/ItemCatalog.cpp` marker from this page. UID0000WV moved to UID000051 because this page contained only the two lookup methods, all callers are FittingRoom paths, the receiver is the item-state subobject, and the backing map belongs to `FittingRoomDialogItemState::m_categoryLookup`. Preserve blank CPP/H and blank emitter metadata as an evidence-backed no-code/no-header disposition, not as unfinished reconstruction. Historical `ItemCatalog::GetItemCount/GetItemByIndex` wording remains dated facade provenance only.

## Historical Assumptions Superseded By Current Evidence

- The 2026-06-04 reconstructable class/emitter state and the early standalone ItemCatalog source possibility predated the owner-route resolution. They remain in `Changes` as historical decisions and no longer describe current emission.
- The 2026-06-16 statement that no relevant local UDT records existed was true of that evidence pass. Current IDA still has no ItemCatalog UDT but now has exact FittingRoom item-state/catalog UDTs; those active types strengthen the non-ItemCatalog ownership conclusion.
- Older custom `FindNode` source vocabulary is superseded. The binary helper is compiler-generated map-find lowering; reconstructed source uses `m_categoryLookup.find(category)`.
- Optional declaration/header context is rejected by current consumer and generated-output evidence. No ItemCatalog declaration consumer exists.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | The class page now records the complete two-method historical inventory, exact hashes/ranges/padding, ten call sites across six unique callers, active receiver and UDT layouts, compiler map/vector lowerings, generated source, no-header proof, negative class/data/resource inventory, and superseded facade assumptions. |
| Confidence | 94 | Current executable, UDT, caller, owner/emitter, and generated-output evidence strongly proves that no standalone ItemCatalog class exists. The remaining ceiling reflects unavailable original lexical/history artifacts rather than an unresolved class or code path. |
| Reconstructable | false | No standalone `ItemCatalog` source class body remains after UID0000WV is routed to `FittingRoomDialogItemState`; this page is retained as historical facade/declaration support context only. |

## Cross-References

- [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md)
- [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md)
- [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md)

## Changes

- 2026-08-15 B006 accepted UID0000KD implementation callback: raised this historical facade from `86/89` to `92/94` while preserving `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter metadata, and blank formal CPP/H. Added exact no-ItemCatalog-UDT/vtable/RTTI/lifetime proof, current `0x280` FittingRoomDialogItemState / `0xc0` entry / `0x20` category-map layouts, function hashes, ten call sites across six unique FittingRoom callers, map/vector compiler-lowering disposition, pointer/data/resource negatives, sole FittingRoom.cpp route, no-header/no-code proof, and dated historical assumption corrections.
- 2026-07-05 B003 UID0000WV implementation callback: Reclassified this class page from reconstructable/emitting through [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md) to non-emitting support context with `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`. This is justified because UID0000WV was the only direct source-bearing method pair on the page, and it now emits formal `FittingRoomDialogItemState::GetItemCount` / `GetItemByIndex` C++ through [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md). Preserved historical `ItemCatalog` facade provenance, exact ranges/sizes/callers, `g_pFittingRoomDialog + 0x504` receiver evidence, no data/pointer route, and rejected standalone `ItemCatalog.cpp` output; no class score change was made.
- 2026-06-27 B008 [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md) implementation callback: Class metadata unchanged. Updated placement guidance so `ItemCatalog` remains a useful two-method embedded facade type but preferred source placement is folded through [UID:0000JE][FittingRoom](by-file/FittingRoom.md) / [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md), not an equally likely standalone `ItemCatalog.cpp`. Owner/emitter metadata was intentionally not moved in this callback because the supervisor assignment limited [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md) route changes to cases with current evidence and by-structure support.
- 2026-06-04: Raised from `72/84` to `82/88`, marked reconstructable, and attached to [UID:0000KD][ItemCatalog](by-file/ItemCatalog.md).
  - Before: the class page identified the two-method facade but still relied on stale non-IDA provenance, lacked reconstructable/autogen metadata, and did not record the current call-site proof for `g_pFittingRoomDialog + 0x504`.
  - After: the page records live method boundaries, fitting-room caller set, embedded-object call sites, decompiled tree/vector behavior, score rationale, and final C++ blockers.
  - Evidence: 2026-06-04 IDA MCP `py_eval` confirmed `0x00422690-0x004226cd`, `0x004226d0-0x0042273f`, callers from `sub_41CDC0`, `sub_41EE10`, `sub_41F2B0`, `sub_41FBA0`, `sub_41FCD0`, and `sub_420D00`, `+0x504` object setup at live call sites, and category-tree decompilation using `this + 544` / `this + 548`.

- Completion/confidence score update: existed before as `0/0`; changed to `72/84`. Summary: fitting-room catalog lookup facade role, two confirmed methods, embedded-object placement, caller evidence, and source-module alternatives are documented with strong confidence; completion is capped because the page is intentionally small and category storage internals live in related fitting-room docs. Evidence: `ItemCatalogLookup`, `FittingRoomUiCore`, `FittingRoomListPane`, and `FittingRoomDialogItemState`.

- 2026-06-16 A001 target refresh: Raised from `82/88` to `86/89`.
  - Evidence: live IDA MCP on `b001_mappane_0001AW_20260616` reconfirmed function sizes, five callers per method, parser/helper successor sizes, and decompiled category-vector behavior; `search_structs` found no source UDTs for the candidate category/item names.
  - Blocker result at the time: standalone `ItemCatalog.cpp` versus private `FittingRoom.cpp` placement and final category-entry type/field names remained unresolved after checking current IDA functions, xrefs, decompilation, type metadata, and related fitting-room item-state docs. B008 2026-06-27 supersedes the source-placement portion with folded `FittingRoom.cpp` guidance while leaving final type/field names and route metadata normalization open.
