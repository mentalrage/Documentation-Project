*** UID:0000LK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MonsterImageLib Table Helpers

## Status

- Confidence: very strong for shared helper behavior, accepted neutral type roles, complete UID0001CM formal CPP/H, the fallback definition, and the non-emitting alias route; the exact original lexical filename and type/global spellings remain inferred.
- Reconstruction module: `NexusTK/render/MonsterImageLibTables.cpp` with sibling `MonsterImageLibTables.h`. Historical uncertainty about a private helper section is retained as an unrecoverable lexical/source-tree caveat, not an implementation blocker.
- 2026-06-29 B007 implementation: the helper declaration pass is no longer pending. [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) now emits the shared `ImageAnimationTable`, `ImageAnimationGroup`, and `ImageAnimationFrame` declarations and method bodies through this file route.
- Current recovered sources:
  - Historical stale lead only: `source-3/simroot_v2/class_MonsterImageLibTable_5289D0.cpp`
  - Historical stale lead only: `source-3/simroot_v2/class_MonsterImageLibTable_528BE0.cpp`
- Main address range: `0x00528930-0x00528d51`

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 94 | The page records the complete thirteen-function island, authored/no-code split, exact 12/8/10-byte layouts, shared monster/riding callers, callback wiring, fallback object and alignment boundary, complete CPP/H route, consumer includes, and non-emitting alias dispositions. |
| Confidence | 94 | Parent, class, memory, global, data, parser, generated-source, and IDA-backed evidence agree on one shared source unit. The remaining six points reflect unrecovered lexical filename/type/global spellings and do not limit runtime behavior or source completeness. |

## File Role

These two small helper classes own heap arrays used by nested monster/riding animation table records. The current class names are address-derived and monster-biased, but IDA MCP shows the allocation helpers are called by both [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) and [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md):

- `0x005289d0` has callers from `MonsterImageLib::LoadMonsterTables` and `RidingImageLib::LoadRidingDefinitions`.
- `0x00528be0` has the same monster/riding parser caller family.

This argues for a shared sprite animation table helper source file or local helper structs included in both original modules. The accepted B001 source-facing names are `ImageAnimationGroup` for the 8-byte child record and `ImageAnimationFrame` for the 10-byte frame entry. The 2026-06-29 B007 implementation adds `ImageAnimationTable` as the inferred source-facing name for the 12-byte outer helper because the helper is shared by monster and riding table code and no recovered IDA name contains `MonsterImageLibTable`. These names replace the old "monster-only" source-facing direction, while raw helper/class labels remain evidence aliases.

IDA MCP on 2026-05-26 also ties the global default riding table at [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) to the 12-byte `0x005289d0` helper shape. `RidingImageLib::LoadRidingDefinitions` seeds that global table with `21` / `0x15` default riding groups (verified with `tools/int_convert.py`) before loading per-riding definitions from `RIDINGS.DNA`.

The adjacent monster default table storage at [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md) uses the same 12-byte outer helper shape. It is initialized by the shared helper constructor, cleaned up by the shared helper destructor, allocated with `21` / `0x15` default groups (verified with `tools/int_convert.py`) by `MonsterImageLib::LoadMonsterTables`, and returned by the monster table lookup when an index is out of range. That storage is concrete monster image state, while this page owns the shared helper behavior and type-shape evidence.

The shared fallback frame record at [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) belongs with this helper file as well. Both lookup helpers return that record when a requested group or frame is out of range, and the record bytes match the normal 10-byte `ImageAnimationFrame` initializer shape. The B002 advanced-scan pass on 2026-06-14 verified that this was a scanner-visible body-label gap only: `MonsterImageLibDefaultFrameRecord` is the correct retained label, the range remains `0x0066deb0-0x0066debc`, and the current owner/emitter route remains this shared helper file.

UID0001CM now declares that fallback dependency as `extern ImageAnimationFrame g_defaultImageAnimationFrame`; the fallback storage itself remains [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md). Adjacent concrete default outer tables [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md) and [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) remain separate data pages and are not absorbed into the helper declaration/body target.

For that default frame record, B002 session `b001_0003gy` reconfirmed raw bytes `00 00 00 00 ff 00 ff ff 00 00 00 00`, uniqueness of the 12-byte pattern in the raw PE, and exactly two base-address refs from `0x00528b2f` and `0x00528d11`. It also confirmed no xrefs to the predecessor padding start `0x0066de6c`, no xrefs to interior offsets `0x0066deb4`/`0x0066deb6`/`0x0066deb8`/`0x0066deba`, and successor refs beginning at `0x0066debc` for the next drive-root buffer. This keeps adjacency with NCA padding and MusicControl data as boundary evidence only; ownership is based on shared helper data flow through the monster/riding table lookup and initializer family. Monster-only ownership is rejected because [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md) is the separate monster outer-table default storage, while this page owns the shared inner-frame fallback used by both monster and riding table helpers.

## Helper Classes

| Class | Address ranges | Role |
| --- | --- | --- |
| `MonsterImageLibTable_5289D0` | `0x00528930-0x00528b43` | Address-derived page alias for the 12-byte outer animation table shape. It owns a heap array of 8-byte `ImageAnimationGroup` records plus a low-byte group count, including initializer, allocation, cleanup, group lookup, and frame lookup helpers. |
| `MonsterImageLibTable_528BE0` | `0x00528b60-0x00528d51` | Address-derived page alias for the 8-byte `ImageAnimationGroup` helper shape. It owns a heap array of 10-byte `ImageAnimationFrame` records plus a count word, including allocation, cleanup, frame-record initializer, no-op element destructor callback, and default-frame fallback. |

## Accepted Shared Layout Names

The 2026-06-25 B001 accepted implementation chooses neutral source-facing names for the shared helper records while preserving the existing address-derived class pages as evidence aliases:

```text
ImageAnimationGroup
  +0x00  ImageAnimationFrame* frames
  +0x04  uint16 frameCount
  +0x06  uint16 reserved
  sizeof = 0x08

ImageAnimationFrame
  +0x00  int16 frameOffset
  +0x02  int16 frameDuration
  +0x04  uint8 blendAlpha
  +0x05  uint8 reserved
  +0x06  int16 auxFrameId
  +0x08  uint8 paletteIndex
  +0x09  uint8 effectIndex
  sizeof = 0x0a
```

The strong fields are group `frames`/`frameCount`, frame `frameOffset`, frame `frameDuration`, and frame `blendAlpha`. The `reserved`, `auxFrameId`, `paletteIndex`, and `effectIndex` names remain inferred and should be carried with confidence caveats until a broader render/riding consumer pass strengthens or replaces them. This accepted naming supersedes older shared wording that described frame entry `+0x02` as `endFrame` or `+0x04` as `direction`.

## Helper Island Details

[UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) currently records thirteen helper bodies before the next function at `0x00528d60`. The outer helper includes the zero initializer at `0x00528930`, cleanup/allocation helpers, group and frame lookup helpers, and the `0x00528b50` nested group-record initializer. The inner helper includes the `0x00528b60` cleanup helper, `0x00528be0` allocator, `0x00528c80` cleanup/unwind duplicate, `0x00528d00` lookup helper, `0x00528d30` frame-record initializer, and the `0x00528d50` no-op element destructor callback.

The `0x00528b50` initializer is part of the outer helper family, not a standalone class. It zeroes each 8-byte nested group record and is passed as the constructor callback from `0x005289d0`. The `0x00528d30` initializer and `0x00528d50` no-op callback serve the inner 10-byte frame-record vector. Padding between these helpers is `0xcc` alignment and should not be promoted into source methods.

UID0001CM is now the source declaration/body home for the helper island. The address-derived class pages [UID:00008O][MonsterImageLibTable_5289D0](by-class/MonsterImageLibTable_5289D0.md) and [UID:00008P][MonsterImageLibTable_528BE0](by-class/MonsterImageLibTable_528BE0.md) remain support aliases and should not duplicate the helper C++.

Current half-open endpoints from session `b2ae72ec` normalize several older last-byte-style rows: `0x005289d0-0x00528a6e`, `0x00528af0-0x00528b08`, `0x00528b10-0x00528b44`, `0x00528be0-0x00528c7c`, and `0x00528d00-0x00528d28`.

## 2026-08-11 B006 Cleanup-Helper Source-Quality Synchronization

- `0x00528950-0x005289c6` is the high-confidence `ImageAnimationTable` destructor helper: 118 bytes, body SHA256 `16699FE91B4F170A208359C4DA2FE9976DF505F7DEBCA73F5BEF90432B99D42F`, and eight refs. The dated pre-mutation B006 observation was name `sub_528950`, prototype `void __thiscall(_DWORD *this)`, and blank comments. The accepted current A02 state is name `ImageAnimationTable__destructor`, type `void __thiscall(ImageAnimationTable *this)`, and function regular comment `Destroys one 12-byte ImageAnimationTable: destroys/frees its ImageAnimationGroup array, clears groupCount, and nulls groups. Shared by MonsterImageLib and RidingImageLib table cleanup.`
- The helper destroys/frees the nested `ImageAnimationGroup` array, clears `groupCount`, and nulls `groups`. Both RidingImageLib ordinary/scalar cleanup paths use it as the element-destructor callback for their `ImageAnimationTable` arrays; that dependency does not transfer helper ownership into `RidingImageLib.cpp`.
- Shared dependency `0x005c7910-0x005c791e` is a 14-byte one-argument cdecl wrapper around the single runtime free-base callee, body SHA256 `F1379B8CF21C269DF67C6849951BCCA560B07D2C92441ED30FD291070BF6A0EF`, with 17 callers. Its dated pre-mutation B006 name was `sub_5C7910`. The accepted current A14 state is name `NexusTK_array_allocation_free_wrapper`, type `void __cdecl(void *Block)`, and function regular comment `Shared array-allocation release wrapper around the runtime free path; source reconstruction should use the owning container/allocation syntax rather than call this compiler-facing wrapper directly.` It remains a compiler/runtime dependency with no direct authored-source body or call; reconstructed C++ uses `delete[]`/owning allocation syntax.
- The source-facing `ImageAnimationTable` destructor already belongs to this shared helper family and is represented by UID0001CM formal C++. No formal source, class ownership, score, range, or emitter route changes are required. The supervisor-owned IDA rename/type/comment handoff may improve analysis names without changing source ownership.
- UID0002Y4 independently duplicates RidingImageLib ordinary cleanup and depends on both helpers before its compiler-only deletion tail. Its use is corroborating shared-consumer evidence, not a reason to move these helpers under RidingImageLib.

## 2026-06-14 C001 IDA MCP Refresh

Live IDA 9.1 on session `a001_goal2_class_batch` reconfirmed the shared helper island and the file-root route:

- `lookup_funcs` reports the helper island as `0x00528930` size `0x17`, `0x00528950` size `0x76`, `0x005289d0` size `0x9e`, `0x00528a70` size `0x76`, `0x00528b10` size `0x34`, `0x00528b50` size `0x0f`, `0x00528b60` size `0x79`, `0x00528be0` size `0x9c`, `0x00528c80` size `0x79`, `0x00528d00` size `0x28`, `0x00528d30` size `0x16`, and `0x00528d50` as `nullsub_13` size `0x01`, with successor function `0x00528d60`.
- `xrefs_to 0x005289d0` reports four parser/allocation call sites: two in `0x004dac40` and two in `0x004dc420`. `xrefs_to 0x00528be0` reports the same two-function monster/riding parser family.
- `xrefs_to 0x0066deb0` reports exactly the two fallback-frame references from `0x00528b10` and `0x00528d00`, matching [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md).
- `xrefs_to 0x0069b424` reports the monster fallback/default table references from static setup/shutdown and the monster parser/lookup family, while `xrefs_to 0x0069b430` reports the riding default table static setup/shutdown, parser, fallback, and render lookup references. This keeps concrete table storage with [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) and [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md), while this page owns the shared helper implementation.

## Ownership Decision

Do not hard-attach these helpers only to `MonsterImageLib` just because of the current page names. They should be kept near the monster/riding animation parser family. The source-facing neutral names above are accepted for method-level C++ use, but the page names remain unchanged in this callback to avoid a broad rename/reference pass.

2026-05-26 IDA `py_eval` recheck expands the reviewed range to `0x00528950-0x00528d28`, adding modeled cleanup/unwind helpers at `0x00528950`, `0x00528a70`, `0x00528b60`, and `0x00528c80`. No IDA names contain `MonsterImageLibTable`, so the current class names are placeholders until neutral helper names are selected.

2026-05-28 IDA MCP recheck expands the active range to `0x00528930-0x00528d51`, adding the outer-table zero initializer at `0x00528930`, the inner frame-record initializer at `0x00528d30`, and the no-op element destructor callback at `0x00528d50`.

## UID0003U8 Signed Timing Contract - 2026-07-15

- This file remains the shared source root for UID0001CM's complete 13-helper `ImageAnimationTable`/`ImageAnimationGroup`/`ImageAnimationFrame` implementation. File score, path, owner, inferred filename caveat, helper ordering, fallback ownership, and compiler cleanup-clone treatment remain unchanged.
- `ImageAnimationFrame::frameDuration` at `+0x02` is canonical signed `int16`/C++ `short`, not `uint16`. Five timing consumers at `0x0053a30b`, `0x0053aaae`, `0x0053b780`, `0x0053ba59`, and `0x005a37d6` sign-extend this word.
- [UID:0003U8][0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation](by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md) is a live UserPane.cpp consumer: its MonsterObject branch follows `g_pMonsterImageLib -> MonsterImageEntry -> ImageAnimationGroup -> ImageAnimationFrame` and uses the signed duration for event `20` scheduling.
- Loader and fallback behavior is unchanged: serialized width is two bytes, normal constructors clear the field, and monster/riding defaults write `30000`. Historical unsigned-duration wording is superseded without changing record size, field offset, parser order, default bytes, or source ownership.

## 2026-08-17 B008 Whole-File Source Closure

The complete compilation unit is the half-open code island `0x00528930-0x00528d51`, followed by internal `0xcc` alignment through the next function at `0x00528d60`, plus the source-bearing fallback object at `0x0066deb0-0x0066deba`. The two bytes at `0x0066deba-0x0066debc` are linker/alignment padding with no names, types, comments, or xrefs; `RootPathName` begins at the protected successor head `0x0066debc`.

The authored source inventory contains ten definitions: constructors for `ImageAnimationTable`, `ImageAnimationGroup`, and `ImageAnimationFrame`; destructors for the table and group; `AllocateGroups`, `AllocateFrames`, the table-level `GetGroup` and `GetFrame`, and the group-level `GetFrame`. The cleanup bodies at `0x00528a70-0x00528ae6` and `0x00528c80-0x00528cf9` are zero-xref EH cleanup clones of the authored destructors. The one-byte `retn` callback at `0x00528d50-0x00528d51` is compiler lowering for a trivial frame destructor. These three compiler products are documented but emit no duplicate C++.

UID0001CM is the sole declaration/method carrier. Its H channel owns the guarded declarations of the exact 12-byte `ImageAnimationTable`, 8-byte `ImageAnimationGroup`, and 10-byte `ImageAnimationFrame`, plus `extern ImageAnimationFrame g_defaultImageAnimationFrame`. Its CPP channel includes its own header and contains definitions only. UID00027U follows at emitter position 10 and defines exactly `ImageAnimationFrame g_defaultImageAnimationFrame;`; it emits no H fragment. UID00008O and UID00008P are address-derived search/evidence aliases, are non-reconstructable/non-emitting, and retain owner UID0000LK without duplicating either formal source channel.

The formal source preserves binary behavior while using human-authored C++ shape: table/group allocations use `new[]`; destructors use `delete[]`; table count truncates to the low byte; frame count follows the observed `(unsigned short)(unsigned char)count` truncation; in-range lookups use 8-byte and 10-byte strides; out-of-range frame lookups return the shared fallback. `ImageAnimationFrame::frameDuration` is signed `short`. The frame constructor writes `frameOffset = 0`, `frameDuration = 0`, `blendAlpha = 0xff`, `auxFrameId = -1`, `paletteIndex = 0`, and `effectIndex = 0`; it deliberately does not write the reserved byte. Static zero-initialization supplies that byte in the fallback object. The group declaration keeps only the pointer and 16-bit count, leaving the observed `+0x06` tail as implicit 32-bit alignment rather than inventing a source field.

Concrete `MonsterImageEntry`, `RidingDefinition`, and their default outer tables remain owned by MonsterImageLib/RidingImageLib. Their loaders consume this shared ABI and directly include `MonsterImageLibTables.h`; they do not acquire this helper implementation. The IDA-facing `NexusTK_array_allocation_free_wrapper` explains lowered vector cleanup at seventeen call sites but is not a source-level call in this module.

Historical conclusions that source C++ or a sibling header had to remain blank are superseded. The remaining uncertainty is lexical only: no recovered symbol proves the exact original filename, neutral type spellings, or fallback global spelling. The selected names are the strongest subsystem-consistent human source reconstruction and do not alter execution.

## Cross-References

- [UID:00008O][MonsterImageLibTable_5289D0](by-class/MonsterImageLibTable_5289D0.md)
- [UID:00008P][MonsterImageLibTable_528BE0](by-class/MonsterImageLibTable_528BE0.md)
- [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md)
- [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md)

## Changes

- 2026-08-11 B006 UID0002Y4 support synchronization:
  - Added exact `ImageAnimationTable__destructor` and `NexusTK_array_allocation_free_wrapper` IDA-facing roles, ranges, hashes, types, and reference/caller counts.
  - Preserved shared MonsterImageLibTables/runtime ownership and existing formal source while recording RidingImageLib ordinary/scalar cleanup as consumers only.

- 2026-06-29 B007 UID0001CM implementation callback:
  - Score unchanged at `87/88`.
  - Evidence: [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) now emits the formal shared helper C++ for `ImageAnimationTable`, `ImageAnimationGroup`, and `ImageAnimationFrame`. This supersedes the prior "standalone helper C++ remains blank pending declaration pass" caveat for UID0001CM.
  - Current session `b2ae72ec` reconfirmed source ownership through this file, parser callers in both `MonsterImageLib` and `RidingImageLib`, render/lookup use, fallback-frame refs to `0x0066deb0`, callback wiring, cleanup/unwind clones, and internal padding. Address-derived class pages remain aliases covered by UID0001CM source.
- 2026-06-25 B001 implementation callback:
  - Score unchanged at `87/88`.
  - Evidence: synchronized the helper source page with accepted [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) C++ and support evidence. Added `ImageAnimationGroup` and `ImageAnimationFrame` as inferred source-facing shared names, preserved `MonsterImageLibTable_5289D0` / `MonsterImageLibTable_528BE0` as address-derived evidence aliases, and superseded stale `endFrame` / `direction` frame-field wording.
- 2026-06-14 C001 Goal 2 by-file score refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:87`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed the full helper island, successor boundary, parser/allocation xrefs for both outer and inner allocation helpers, fallback-frame record refs, concrete monster/riding default-table refs, and the `21` / `0x15` default-group count (verified with `tools/int_convert.py`). Owner/emitter routing stays as the shared helper source root [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md); the previous standalone helper C++ blocker was later resolved by the 2026-06-29 B007 UID0001CM implementation.
- Before: the file-level helper range was `0x00528950-0x00528d28`.
- Changed to: range is `0x00528930-0x00528d51`, including initializer/callback helpers that were previously hidden in UNKNOWN gaps.
- Summary/evidence: 2026-05-28 IDA MCP xrefs tie `0x00528930`, `0x00528d30`, and `0x00528d50` to the same monster/riding table allocation and cleanup helper family.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `80`.
- Summary/evidence: the page documents both helper classes, shared monster/riding caller evidence, global table tie-in, active range corrections, and cross-references; confidence remains below high because neutral final helper names and original filename are still provisional.

- 2026-06-03 path consistency pass:
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
  - Summary/evidence: this page already proposes `render/MonsterImageLibTables.cpp`, [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) ties the helper bodies to monster/riding render table parsing, and `by-project-structure/proposed-source-tree.md` already lists `MonsterImageLibTables.cpp` under `NexusTK/render/`. The final helper type names remain provisional, so no reconstructed C++ was added.

- 2026-06-07 A001 helper-island reconciliation:
  - Changed to: completion `84`, confidence `84`; added score rationale, the shared fallback frame-record owner, the `0x00528b50` nested group initializer, and the thirteen-helper island breakdown.
  - Summary/evidence: [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md), [UID:00008O][MonsterImageLibTable_5289D0](by-class/MonsterImageLibTable_5289D0.md), [UID:00008P][MonsterImageLibTable_528BE0](by-class/MonsterImageLibTable_528BE0.md), [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md), and [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) now agree on shared monster/riding helper ownership, callback wiring, fallback-record behavior, and the remaining neutral-name/source-split caveat.
- 2026-06-07 A002 Batch 042 fallback-table refresh:
  - Before: `COMPLETION:84` and `CONFIDENCE:84`.
  - After: `COMPLETION:85` and `CONFIDENCE:85`.
  - Summary/evidence: added the exact monster default-table storage [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md) to the helper-family evidence, tying it to shared constructor/destructor helpers, `MonsterImageLib::LoadMonsterTables` allocation/seeding, and out-of-range fallback behavior. At that time scores remained capped because neutral helper names and standalone-vs-private source placement were still unresolved; UID0001CM later resolved the helper declaration/body blocker while exact original placement remains inferred.
