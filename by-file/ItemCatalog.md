*** UID:0000KD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ItemCatalog

## Status

- Disposition: reviewed historical facade/source-name record with no standalone source root. `PROPOSED_RECONSTRUCTION_PATH:"NONE"` is intentional; this page retains provenance and does not stage an `ItemCatalog.cpp` or `ItemCatalog.h`.
- Active source route: [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md) -> [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) -> [UID:0000JE][FittingRoom](by-file/FittingRoom.md) -> `NexusTK/cashshop/FittingRoom.cpp`.
- Historical class context: [UID:00006T][ItemCatalog](by-class/ItemCatalog.md) remains non-reconstructable, non-emitting facade/name evidence with no formal CPP or H.
- Complete source-bearing inventory: exactly two accessors, `GetItemCount` and `GetItemByIndex`, in [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md). No ItemCatalog-owned code, data, type, resource, import, or declaration remains outside that pair.
- Confidence: very strong for behavior, boundaries, callers, active owner/emitter route, no-source-root disposition, and generated output. The remaining uncertainty is limited to unrecoverable original lexical spellings and historical physical file organization.
- Evidence basis: the prior 2026-06-04 through 2026-07-05 checks are retained below; the exhaustive B006 review on 2026-08-15 added current function hashes/signatures, all ten call sites across six unique callers, active UDT layouts, helper-lowering classification, pointer-route negatives, and generated-output/no-header proof.

## Hypothesis

`ItemCatalog` is a historical source-name facade for two accessors over the fitting-room dialog's embedded item state at `g_pFittingRoomDialog + 0x504`. It is not a project-wide item database, independent object, or translation unit. Current receiver, UDT, caller, emitter, and generated-source evidence places both accessor definitions on [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md), where `m_categoryLookup` occupies item-state offset `+0x220` and its compiler-layout sentinel/storage begins at `+0x224`.

## Contents

Historical facade contents, now emitted through [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) instead of this file:

- Historical `ItemCatalog::GetItemCount(unsigned char categoryId)` / active `FittingRoomDialogItemState::GetItemCount(unsigned char category)` at [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md), exact half-open range `[0x00422690,0x004226cd)`, 61 bytes, body SHA256 `FC4EB4E08022A466526BA3C429B1882B83B9BD430A660773875F7BA4B43E4544`.
- Historical `ItemCatalog::GetItemByIndex(unsigned char categoryId, short itemIndex)` / active `FittingRoomDialogItemState::GetItemByIndex(unsigned char category, short itemIndex)` at [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md), exact half-open range `[0x004226d0,0x0042273f)`, 111 bytes, body SHA256 `309361ABC3C49B47DF73D32EA5386F3D1E5602B6CFCEE9B8A90FF641C754F941`.
- Local alignment is `[0x0042268f,0x00422690)=CC`, `[0x004226cd,0x004226d0)=CC CC CC`, and `[0x0042273f,0x00422740)=CC`. Byte `0x004226cc` belongs to the first method's `retn 4` and is not padding.
- Compiler-generated MSVC byte-key `stdext::hash_map::find` lowering occupies `[0x00423e40,0x00423ea8)`, 104 bytes, SHA256 `C9AA3ACE28EF4DDECC1877FCB696B9213137B40ED1E3F15AFA70BF0E8527B41F`. Source expresses it as `m_categoryLookup.find(category)`, not a handwritten helper.
- Shared compiler/vector lowerings at `0x00421290` and `0x00423810` materialize the copied `std::vector<FittingRoomCatalogEntry*>` and release its storage. They are represented by ordinary vector copy/destruction in source and are not ItemCatalog functions.
- The preceding [UID:0002EF][0x004225a0-0x0042268f.FittingRoomDialogItemStateSaveEncodedStateBuffer](by-memory/0x004225a0-0x0042268f.FittingRoomDialogItemStateSaveEncodedStateBuffer.md) and successor item-state `LoadEncodedStateBuffer` beginning at `0x00422740` are excluded FittingRoom methods, not historical ItemCatalog contents.
- Category storage is initialized, reset, and populated by [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md), which parses item-shop JSON through JsonCpp and stores fitting-room-owned entry vectors.

## Complete Inventory

| Item | Disposition |
| --- | --- |
| `[0x00422690,0x004226cd)` | Source-authored `FittingRoomDialogItemState::GetItemCount`; formal CPP already lives in UID0000WV. |
| `[0x004226cd,0x004226d0)` | Three-byte alignment, no source. |
| `[0x004226d0,0x0042273f)` | Source-authored `FittingRoomDialogItemState::GetItemByIndex`; formal CPP already lives in UID0000WV. |
| `[0x0042273f,0x00422740)` | One-byte trailing alignment, no source. |
| `[0x00423e40,0x00423ea8)` | Compiler-generated map-find lowering covered by `m_categoryLookup.find`. |
| `0x00421290` / `0x00423810` | Shared compiler/vector copy and cleanup lowerings covered by the temporary `std::vector`. |
| `0x0067a73c` | Independent [UID:00028I][0x0067a73c-0x0067a740.g_pFittingRoomDialog](by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md) support receiver/lifetime global; not ItemCatalog-owned. |
| ItemCatalog globals/statics/constants/strings/tables/data | None found. |
| ItemCatalog UDT/vtable/RTTI/lifetime object | None found. |
| ItemCatalog resources/imports/protocol records/literals | None found. |
| Standalone CPP/H | None required; both paths are intentionally absent. |

## Active Type And Layout Evidence

- `FittingRoomDialogItemState` is a current `0x280`-byte UDT (IDA ordinal 884); `m_categoryLookup` is `+0x220`, size `0x20`, and the accessor receiver is the dialog's item-state subobject at `+0x504`.
- `FittingRoomCatalogEntry` is a current `0xc0`-byte UDT (ordinal 875): category `+0x00`, enabled `+0x04`, tile `+0x06`, color `+0x08`, `wchar_t name[0x55]` at `+0x0a`, and parts vector at `+0xb4`.
- `FittingRoomCategoryMap` is a current `0x20`-byte compiler-layout UDT (ordinal 881). Source uses the accepted C++03 alias `stdext::hash_map<unsigned char, FittingRoomCatalogEntryList>` rather than reproducing its sentinel/bucket implementation.
- Supporting category, part-record/vector, entry-list, selection-entry, and vector types are declared by UID000051. No separate `ItemCatalog` type was found.

## Evidence

- 2026-06-04 IDA MCP confirms `0x00422690-0x004226cd` and `0x004226d0-0x0042273f` as the only functions in the lookup child span.
- Live call sites show fitting-room ownership: `0x0041ce50`, `0x0041fc43`, and `0x00420d0b` pass `this + 0x504` or `g_pFittingRoomDialog + 0x504` as the catalog object.
- `GetItemCount` callers are fitting-room category/list/paint/key/selection paths at `0x0041ce5d`, `0x0041ee41`, `0x0041f4eb`, `0x0041fc49`, and `0x00420d1c`.
- `GetItemByIndex` callers are fitting-room list/paint/input/selection paths at `0x0041ee5e`, `0x0041f51d`, `0x0041f5f0`, `0x0041fe16`, and `0x00420d2d`.
- Decompilation confirms the catalog tree at `this + 544` with sentinel at `this + 548`; `GetItemCount` returns the pointer-vector length, while `GetItemByIndex` returns an entry pointer only when the category exists and the index is in range.
- Live byte checks confirm local padding at `[0x0042268f,0x00422690)`, `[0x004226cd,0x004226d0)`, and `[0x0042273f,0x00422740)`, keeping the lookup range cleanly split from neighboring fitting-room item-state methods.
- 2026-07-05 B003 MCP session `supervisor_recovery_20260705` reconfirms the two ranges/sizes, ten fitting-room caller refs, receiver setup through `g_pFittingRoomDialog + 0x504`, item-state `m_categoryLookup` at `+0x220/+0x224`, zero data xrefs, zero VA/RVA pointer hits, no original UDT/type records, and active formal C++ emission through [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md).
- 2026-08-15 B006 exhaustive review records unique signatures for both functions, exact body hashes above, zero data xrefs, and zero VA/RVA/raw-offset pointer-pattern routes. The ten call sites are distributed across six unique fitting-room functions: category-control rebuild (`0x0041ce5d`), scrollbar update (`0x0041ee41`, `0x0041ee5e`), paint (`0x0041f4eb`, `0x0041f51d`, `0x0041f5f0`), key scroll (`0x0041fc49`), input (`0x0041fe16`), and selection validation (`0x00420d1c`, `0x00420d2d`).
- The count accessor returns zero when `find` reaches `end`, otherwise the pointer-vector size narrowed to `short`. The indexed accessor copies the found pointer vector, uses the binary's signed upper-bound comparison, returns an entry pointer or `NULL`, frees temporary storage on both completed paths, and intentionally adds no negative-index guard.

## Negative Evidence

- Neither accessor has a data xref, function-pointer cell, vtable route, VA/RVA/raw pointer hit, string, or imported-call signature that suggests another owner.
- No call escapes the FittingRoom subsystem and no ItemCatalog-specific constructor, destructor, singleton, global, static storage, constant, table, string, resource, import, or protocol record exists.
- Current IDA contains exact FittingRoom item-state/catalog UDTs but no `ItemCatalog` UDT, vtable, RTTI record, or standalone lifetime identity.
- General item database, DAT, inventory, JsonCpp, `FittingRoomListPane`, broad UID0000WU aggregate emission, and no-owner routes are dependencies, consumers, or rejected duplicates rather than source owners.

## 2026-06-14 C001 IDA MCP Refresh

Current IDA MCP health reports `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. The refreshed checks keep this as an embedded fitting-room catalog helper. Later B008 source-quality incorporation supersedes the standalone-file option with folded `FittingRoom.cpp` placement, without changing this page's metadata route in the `0000WU` callback.

- `lookup_funcs` reconfirms `0x00422690` size `0x3d`, `0x004226d0` size `0x6f`, parser `0x00422740` size `0x1d9`, category loader `0x00422ba0` size `0x2f1`, and category/vector helper `0x00423810` size `0x50`.
- `xrefs_to` reconfirms five `GetItemCount` refs at `0x0041ce5d`, `0x0041ee41`, `0x0041f4eb`, `0x0041fc49`, and `0x00420d1c`, and five `GetItemByIndex` refs at `0x0041ee5e`, `0x0041f51d`, `0x0041f5f0`, `0x0041fe16`, and `0x00420d2d`; all sit in the fitting-room list/render/input/selection neighborhood.
- `analyze_component` keeps the ItemCatalog lookup pair as interface functions and shows the broader fitting-room parser chain `0x00422740 -> 0x00422ba0`, while keeping JsonCpp callees outside this file.
- `analyze_function 0x00422690` decompiles the count helper as category lookup plus sentinel comparison at `this[137]`, returning `0` when absent or `(end - begin) >> 2` when present.
- `analyze_function 0x004226d0` decompiles the indexed lookup as category lookup, vector-triplet copy, bounds check, pointer return, and vector cleanup helper call.

## Proposed Placement

- Active definitions remain in `NexusTK/cashshop/FittingRoom.cpp` through UID0000WV -> UID000051 -> UID0000JE.
- This page's exact reconstruction path is `NONE`; it is a reviewed historical facade record rather than a generated source root.
- `ItemCatalog.cpp` is absent by design because emitting it would duplicate the two already-owned FittingRoom methods.
- `ItemCatalog.h` is absent by design. The declarations already live in UID000051's private class fragment, and no external ItemCatalog type or declaration consumer exists.
- No new source/header, UID, child, split, merge, wrapper, owner, emitter, or range extension is required.

## Generated Output Audit

- The validator-generated `NexusTK/cashshop/FittingRoom.cpp` is the sole active translation unit for this pair. It contains one declaration and one complete definition for each accessor through the UID000051/UID0000WV route.
- The generated bodies preserve `m_categoryLookup.find/end`, zero/`NULL` failure returns, the copied entry-vector lifetime, the signed-short upper-bound comparison, and the absence of a new negative-index guard.
- No target-specific stub, TODO, or empty-emitter marker is required. Current artifact identities are recorded by the implementation report/validator receipt rather than frozen here as continuing authority.
- `NexusTK/cashshop/ItemCatalog.cpp` and `NexusTK/cashshop/ItemCatalog.h` are intentionally absent.

## Historical Assumptions Superseded By Current Evidence

- The 2026-06-04 reconstruction path and optional standalone `ItemCatalog.cpp`/`ItemCatalog.h` discussion were reasonable early organizational hypotheses. Receiver, current UDT, caller, owner/emitter, and generated-output evidence now supersedes them with path `NONE` and folded FittingRoom source.
- The 2026-06-14 standalone-versus-embedded split question is closed; it is retained below as dated research history, not a current blocker.
- Older statements that no relevant local UDT records existed describe the earlier IDA state. Current IDA has exact FittingRoomDialogItemState and catalog UDTs while still having no ItemCatalog UDT.
- Historical `ItemCatalog::GetItemCount` / `ItemCatalog::GetItemByIndex` spellings remain useful provenance, but do not establish an active class, file, header, or owner route.

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
| Completion | 94 | The page now reconciles the exhaustive two-accessor inventory, exact ranges/hashes/padding, all ten call sites across six unique callers, map/vector compiler lowerings, current types/layouts, support receiver, complete negative inventory, active owner/emitter route, no-source-root/no-header decision, generated output, rejected alternatives, and historical assumptions. |
| Confidence | 95 | Behavior, ownership, source placement, output, and absence of a standalone unit are independently supported. The remaining ceiling reflects unavailable original symbols and exact historical physical filename/private spellings, not an unresolved implementation or routing blocker. |

## Changes

- 2026-08-15 B006 accepted UID0000KD implementation callback: raised `86/88` to `94/95`, changed `PROPOSED_RECONSTRUCTION_PATH` from `NexusTK/cashshop/` to exact `NONE`, and completed the historical no-source-root inventory. Added exact function/body hashes, padding, ten call sites across six unique FittingRoom callers, current `0x280` item-state / `0xc0` entry / `0x20` map layouts, compiler-covered map-find/vector-copy cleanup, complete data/type/resource negatives, sole UID0000WV -> UID000051 -> UID0000JE -> `FittingRoom.cpp` route, generated-output proof, and the intentional absence of `ItemCatalog.cpp`/`.h`. Preserved earlier standalone/facade hypotheses as dated superseded history; owner `FILE` remains the singular documentation-record owner and no formal code or new source artifact was added.
- 2026-07-05 B003 UID0000WV implementation callback: File metadata unchanged. Historicalized this page as support/facade context only after UID0000WV moved to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) and [UID:0000JE][FittingRoom](by-file/FittingRoom.md). Preserved exact ranges/sizes/callers, `g_pFittingRoomDialog + 0x504` receiver proof, no data/pointer route, and the old `ItemCatalog::GetItemCount/GetItemByIndex` provenance, while rejecting standalone `cashshop/ItemCatalog.cpp` output and direct file/class emission for the current generated route.
- 2026-06-27 B008 [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md) implementation callback: File metadata unchanged. Updated source-placement guidance to prefer folded `cashshop/FittingRoom.cpp` placement for the two-method embedded `ItemCatalog` facade and to stop presenting standalone `cashshop/ItemCatalog.cpp` as an equally likely split. [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md) owner/emitter metadata was intentionally not forced in this callback because the supervisor assignment limited that route move to cases where current evidence and by-structure require it.
- 2026-06-04: Raised from `76/78` to `84/86`, set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/cashshop/"`, and replaced stale provenance notes with live IDA evidence.
  - Before: the page had a blank projected path, an autogen error row, and relied on older non-IDA source leads for embedded-object placement.
  - After: the page had a valid cash-shop path, exact method ranges, caller/call-site evidence tying the object to `g_pFittingRoomDialog + 0x504`, padding checks, score rationale, and a then-open standalone-vs-embedded source split caveat. B008 2026-06-27 supersedes the source-split caveat with folded `FittingRoom.cpp` guidance.
  - Evidence: 2026-06-04 IDA MCP `py_eval` confirmed functions `0x00422690-0x004226cd` and `0x004226d0-0x0042273f`, fitting-room callers at `0x0041ce5d`, `0x0041ee41`, `0x0041f4eb`, `0x0041fc49`, `0x00420d1c`, `0x0041ee5e`, `0x0041f51d`, `0x0041f5f0`, `0x0041fe16`, and `0x00420d2d`, `+0x504` object call sites, local padding bytes, and decompiled category-tree/vector behavior.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:78`.
  - Summary/evidence: embedded fitting-room catalog behavior, lookup ranges, callers, JSON/catalog state relationship, and source placement options are documented; completion is lower because the document is concise and does not deeply map the backing category structures or parser population path.

- 2026-06-14 C001: Raised from `84/86` to `86/88`.
  - Before: the page had strong fitting-room-only caller evidence but only a concise link to the parser/category-loader relationship.
  - After: added current IDA MCP health, refreshed method/parser/helper sizes, caller refs, interface-function classification, decompiled count/index behavior, and the then-open standalone-vs-embedded source split blocker. B008 2026-06-27 supersedes the source-split blocker with folded `FittingRoom.cpp` guidance.
  - Evidence: `lookup_funcs`, `xrefs_to`, `analyze_component`, and `analyze_function` reconfirm the lookup pair, the parser/category loader chain, and the sentinel/vector behavior.
