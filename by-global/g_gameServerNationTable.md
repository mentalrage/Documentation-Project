*** UID:0000Q1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static GameServerConfig *g_gameServerNationTable = nullptr;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_gameServerNationTable

## Status

- Confidence: strong for storage address, zero-initialized bytes, lifecycle, `GameServerConfig.cpp` owner route, and the accepted split from `MapPane` active-pane/cache state; medium-high for current-session original-name proof because B003 MCP session `80de0a67` name/global queries do not expose a named `g_gameServerNationTable` entity.
- IDA storage: `0x0069b4c4`; current B003 MCP session `80de0a67` renders this through `unk_69B4C4` / `dword_69B4C4` aliases and returns no named `g_gameServerNationTable` data record. C001's 2026-06-16 saved-label note remains historical support for the source-facing name.
- Proposed owner: [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) under `map/`. [UID:0000L3][MapPane](by-file/MapPane.md) allocates/tears down the table as a dependency, but does not own this singleton/table pointer.
- Formal C++ disposition: this by-global page emits the single source declaration. Exact memory child [UID:0002XS][0x0069b4c4-0x0069b4c8.g_gameServerNationTable](by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md) stays blank to avoid duplicate output.

## Role

`g_gameServerNationTable` is the process-wide pointer to the map/game-server nation-entry table. It backs 68-byte [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md) records used by user/status/map presentation code.

Accepted first-draft declaration during reconstruction:

```cpp
static GameServerConfig *g_gameServerNationTable = nullptr;
```

The `GameServerConfig *` type is inferred from allocation, vtable installation, protected-array setup/cleanup, modeled methods, and current support docs. A future cleanup could introduce a narrower table wrapper name, but current MCP evidence does not justify replacing `GameServerConfig *` or moving this declaration to MapPane.

## 2026-06-23 B003 Current MCP Evidence

B003 rechecked this global with live IDA MCP database/session `80de0a67` at `http://127.0.0.1:13337/mcp`. `initialize`, `tools/list`, and `server_health(database='80de0a67')` succeeded. Health reported IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.

Storage/name checks:

- `lookup_funcs` at `0x0069b4c4`, `0x0069b4b4`, `0x0069b4bc`, `0x0069b4c0`, and `0x0069b4c8` returned no functions, confirming exact writable data storage rather than executable code.
- `get_bytes(0x0069b4c4, 4)` returned `00 00 00 00`; SHA-256 is `df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119`, SHA16 `df3f619804a92fdb`.
- `get_int(0x0069b4c4, u32le)` and `get_global_value` by address returned zero.
- The full [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) window is twenty zero bytes, SHA16 `de47c9b27eb8d30`.
- Current `entity_query` and `get_global_value('g_gameServerNationTable')` did not find a named `g_gameServerNationTable` data entity; `unk_69B4C4` and `dword_69B4C4` aliases returned zero. The source-facing name is therefore accepted from lifecycle/type/source-family evidence rather than current IDB symbol proof.

`xrefs_to(0x0069b4c4)` returned eighteen direct data xrefs:

- Raw constructor writer: `0x00503a0d`.
- Raw destructor clear: `0x00503a6b`.
- MapPane allocation/constructor dependency: `0x00504467`, `0x0050446e`.
- MapPane cleanup dependency: `0x00504668`.
- Packet/parser route: `0x00507cf6`.
- Scalar deleting destructor clear: `0x00514d9e`.
- Status/user/map consumers: `0x0059be2e`, `0x0059c0d2`, `0x0059c9a2`, `0x0059cc30`, `0x0059d2ca`.
- Nation-entry request paths: `0x005a5023`, `0x005a5dc6`.
- Lookup/fallback consumers: `0x005b92f8`, `0x005b930a`, `0x005be726`, `0x005be738`.

Pointer-route scans reject hidden table ownership. `find_bytes` for absolute-VA bytes `c4 b4 69 00` returned the eighteen matching direct references; RVA-style bytes `c4 b4 29 00` and raw-offset-style bytes `c4 a8 29 00` returned zero matches.

## Lifecycle

- `0x005039f0-0x00503a41` initializes the table object, installs the `GameServerConfig` and `ProtectedArray<GameServerConfig::NationEntry>` vtables, seeds capacity/count fields, and stores this global.
- `0x00504110-0x00504521` (`MapPaneInitialize`) allocates an 88-byte table object during map-pane initialization and stores it in this global.
- `0x00503a50-0x00503a7d` is destructor-like code in the local constructor block that frees table data, clears the global, and tail-jumps to base `LObject` cleanup, but IDA does not currently model it as a separate function.
- `0x00514d80-0x00514ddc` (`GameServerConfigScalarDeletingDestructor`) frees the table data and writes zero to `g_gameServerNationTable`.
- `0x00504530-0x005046c6` (`MapPaneCleanup`) tears down `MapPane` state and calls the table object's virtual destructor when this global is non-null.

B003 session `80de0a67` refined the lifecycle evidence. `lookup_funcs(0x005039f0)` and `lookup_funcs(0x00503a50)` returned no modeled functions; bounded `insn_query` still showed valid raw constructor/destructor islands. The constructor writes the `GameServerConfig` and `ProtectedArray<GameServerConfig::NationEntry>` vtables, initializes protected-array capacity/count/data fields, and writes `ecx` to `unk_69B4C4` at `0x00503a0d`. The raw destructor restores vtables, frees table storage, and clears `unk_69B4C4` at `0x00503a6b`. `lookup_funcs(0x00504110)` returned `sub_504110` size `0x411`; decompilation shows MapPane allocating `0x58` bytes, calling the base/setup helper, storing the constructed pointer or zero to `unk_69B4C4`, then writing GameServerConfig/protected-array vtables. `lookup_funcs(0x00504530)` returned `sub_504530` size `0x196`; decompilation shows MapPane cleanup clearing adjacent object-map storage and invoking this object's virtual destructor when the global is non-null. `lookup_funcs(0x00514d80)` returned `sub_514D80` size `0x5c`; decompilation and disassembly show vtable restoration, protected-array free, `unk_69B4C4 = 0`, base cleanup, and conditional delete.

## Access Patterns

- `0x00503a80` (`GameServerConfigCopyNationEntryOrFallback`) copies a matching nation entry or returns the fallback `L"????"` record.
- `0x00503c70` (`GameServerConfigRequestNationEntries`) sends the fixed opcode `0x66` / subcode `0x4000` request packet when the table is empty.
- IDA xrefs also show readers in the `MapPane` packet path and in the user-list/status UI neighborhood, including `0x00507c90` and `0x0059bc90` range functions.
- 2026-05-25 IDA recheck reports concrete xrefs at `0x00503a0d`, `0x00503a6b`, `0x00504467`, `0x0050446e`, `0x00504668`, `0x00507cf6`, `0x00514d9e`, multiple `0x0059bc90` sites, `0x005a5010`, `0x005a5bd0`, `0x005b8c70`, and `0x005be520`.
- IDA MCP `py_eval` on 2026-06-07 reconfirmed the exact storage item as `0x0069b4c4-0x0069b4c8` with 18 xrefs spanning raw constructor/destructor writes, map initializer writes, map teardown read, scalar destructor clear, user/status readers, request paths, and copy/fallback consumers. IDA MCP `get_bytes` on 2026-06-12 A003 Batch 342 supersedes the older byte note for the active `b001_nexustk` database: the exact storage slot is `00 00 00 00`. The exact split memory page is [UID:0002XS][0x0069b4c4-0x0069b4c8.g_gameServerNationTable](by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md).
- 2026-06-16 C001 live IDA MCP recheck on session `b001_selflookpane_0001H7_20260616` reconfirmed zero bytes at `0x0069b4c4`, the same 18 direct xrefs, raw no-function status for `0x005039f0` and `0x00503a50`, and modeled function bodies for the lookup/request/map-init/map-cleanup/scalar-destructor paths. The IDB was safely updated from `unk_69B4C4` to `g_gameServerNationTable`, and verified helpers were labeled `GameServerConfigCopyNationEntryOrFallback`, `GameServerConfigRequestNationEntries`, `MapPaneInitialize`, `MapPaneCleanup`, and `GameServerConfigScalarDeletingDestructor`.

B003 session `80de0a67` also rechecked the modeled method family. `lookup_funcs(0x00503a80)` returned `sub_503A80` size `0xd8`, with `func_profile` callers from `0x005b8c70` and `0x005be520`; decompilation shows 68-byte entry scanning, copy/fallback behavior, and `_wcscpy_s` fallback text. `lookup_funcs(0x00503c70)` returned `sub_503C70` size `0x93`, with four caller functions from `0x005a5010`, `0x005a5bd0`, `0x005b8c70`, and `0x005be520`; decompilation shows opcode `0x66`, subcode `0x4000`, and send length `9`. `lookup_funcs(0x00503d10)` returned `sub_503D10` size `0x167`, with caller `0x00507c90`; decompilation shows packet parsing, `sub_514EE0` resizing, 68-byte entry writes, `MultiByteToWideChar`, and `_wcscpy_s` fallback/sentinel handling. These paths support a `GameServerConfig *` global declaration rather than a generic MapPane storage declaration.

## 2026-06-23 B004 Local Sibling Sync

B004's [UID:0002XQ][0x0069b4bc-0x0069b4c0.g_objectRecordCount](by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md) implementation pass rechecked this adjacent slot to keep the local cluster consistent. Current MCP session `ff68e691` reports zero bytes at `0x0069b4c4`, eighteen direct xrefs (`0x00503a0d`, `0x00503a6b`, `0x00504467`, `0x0050446e`, `0x00504668`, `0x00507cf6`, `0x00514d9e`, `0x0059be2e`, `0x0059c0d2`, `0x0059c9a2`, `0x0059cc30`, `0x0059d2ca`, `0x005a5023`, `0x005a5dc6`, `0x005b92f8`, `0x005b930a`, `0x005be726`, `0x005be738`), no current named global record, and the same GameServerConfig owner route. No score or C++ change is made here because [UID:0000Q1] was not the accepted target for this callback.

This B004 sibling sync is retained as historical lead material. B003 session `80de0a67` supersedes it for current evidence and formal C++ disposition.

## Caveats

The `GameServerConfig` module name is misleading if read as general configuration. The global is map/gameplay nation state. Keep it out of `config/` unless later evidence proves a broader server-config module existed.

The remaining confidence caveat is original name/type finality. Current MCP does not expose a named `g_gameServerNationTable` record, and a future final source cleanup could introduce a narrower table wrapper type. Current evidence still supports `GameServerConfig *g_gameServerNationTable` as the best first-draft declaration.

## Rejected Alternatives

- Exact memory child C++ is rejected: [UID:0002XS][0x0069b4c4-0x0069b4c8.g_gameServerNationTable](by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md) documents address storage and stays blank so this by-global page is the single declaration emitter.
- No-owner/non-emitting-only is rejected because the storage has a clear by-global route and GameServerConfig method family.
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) aggregate ownership is rejected because the parent is a mixed physical split index.
- MapPane declaration ownership is rejected because MapPane owns allocation/cleanup call sites only; GameServerConfig owns the table type and helper family.
- Adjacent [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md) / [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md) ownership is rejected because those slots are MapPane-owned object-cache state with different xref counts.
- Raw constructor/destructor/source-island ownership is rejected for the declaration because those ranges are lifetime code with no modeled function starts, not file-scope storage declarations.
- Status/user/request/lookup/parser consumer ownership is rejected because consumers read or update the table but do not define the storage.
- Hidden RVA/raw-offset table ownership is rejected by the negative `find_bytes` scans.

## Cross-References

- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:00005O][GameServerConfig](by-class/GameServerConfig.md)
- [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)
- [UID:0001B4][0x00514d50-0x00514ddc.GameServerNationTableDelete](by-memory/0x00514d50-0x00514ddc.GameServerNationTableDelete.md)

## Changes

- 2026-06-23 B003 accepted implementation:
  - Score raised from `88/89` to `89/89` because this page now carries the single formal source declaration.
  - Added formal C++: `static GameServerConfig *g_gameServerNationTable = nullptr;`.
  - Incorporated current MCP session `80de0a67` storage bytes/SHA, no-function data status, alias/name caveat, 18 grouped xrefs, raw constructor/destructor, MapPane allocation/cleanup dependency, scalar-destructor clear, GameServerConfig method-family evidence, pointer-scan negatives, source placement, rejected alternatives, and duplicate-output policy.
- 2026-06-19 B004 GameServerConfig accepted source-quality sync: score unchanged at `88/89`; updated owner wording after the class-level route scan kept [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) as the canonical owner and separated this singleton from MapPane-owned `g_activeMapPane`, `g_objectRecordCount`, and `g_objectNationMap`.
- 2026-06-23 B004 local sibling sync: score/C++ unchanged; narrowed stale current-label wording after current MCP session `ff68e691` showed zero bytes and eighteen xrefs but no named `g_gameServerNationTable` entity in name/global queries.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents storage, role, lifecycle, allocation/destruction, access patterns, IDA xrefs, caveats, and owner/type refs, with final type name still medium-confidence.
- 2026-06-03: Updated the raw destructor lifecycle range to `0x00503a50-0x00503a7d`. Evidence: IDA MCP disassembly shows the tail jump starts at `0x00503a78`, runs through `0x00503a7c`, and is followed by `0xcc` padding.
- 2026-06-05: Marked reconstructable under [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md). Evidence: live IDA MCP xrefs to `0x0069b4c4` include the initialization corridor at `0x00504110`, the cleanup body at `0x00514d80`, and nation-table readers in map/status/user code; decompilation confirms `0x00504110` stores the table object and `0x00514d80` clears the global.
- 2026-06-07 Batch 043 split-parent refresh:
  - Before: confidence `80`, below the corrected `85/85` gate for assigning an exact memory storage child.
  - After: confidence `86`; completion remains `86`.
  - Evidence: live IDA MCP reconfirmed exact four-byte storage bounds, initial value, and 18 xrefs across constructor/destructor, map initialization/teardown, user/status presentation, request, and nation-entry copy paths. The final class/type name remains caveated, but the storage and direct global ownership are now strong.
- 2026-06-12 A003 Batch 342: Corrected the active-IDB initial storage bytes from the stale `0xffffffff` note to `0x00000000`; xrefs and ownership remain unchanged.
- 2026-06-16 C001 global/IDA refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`.
  - Evidence: live IDA MCP reconfirmed zero-initialized storage bytes, 18 direct xrefs, modeled lookup/request/map lifecycle/destructor helpers, and raw no-function status for the constructor/destructor islands. Applied and saved the safe data label plus five verified helper names. Final C++/type edits remain blocked by raw starts and the exact `GameServerConfig.cpp` versus private `MapPane.cpp` source split.
