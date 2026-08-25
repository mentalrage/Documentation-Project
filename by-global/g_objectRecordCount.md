*** UID:0000Q4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static std::uint32_t g_objectRecordCount = 0;

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_objectRecordCount

## Status

- Confidence: strong for storage address, zero initializer, relationship to `g_objectNationMap`, xrefs, unsigned count role, and owner/emitter route; the exact original symbol spelling remains inferred because current MCP name/global queries do not expose a named `g_objectRecordCount` entity.
- IDA storage: `0x0069b4bc`; current B004 MCP session `ff68e691` renders this as `unk_69B4BC`, while historical generated labels include `unk_69B4BC` / `dword_69B4BC` and C001's 2026-06-16 session saved `g_objectRecordCount`.
- Proposed owner: [UID:0000L3][MapPane](by-file/MapPane.md), with loader notes in [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md).

## Role

`g_objectRecordCount` is the process-wide count read from [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md) immediately before allocating [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md). It bounds map classification checks that index into the compact object-to-nation/classification byte array.

First-draft declaration emitted by this by-global page:

```cpp
static std::uint32_t g_objectRecordCount = 0;
```

## Evidence

- `MapPaneInitialize` at `0x00504110` reads four bytes from `SOBJ.TBL` into `g_objectRecordCount`, then allocates `g_objectRecordCount + 1` bytes for [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md).
- `MapPaneInitialize` uses the same count as the upper bound for reading static-object classification records into [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md).
- `0x00505430` reads the count before checking object ids/indexes against `g_objectNationMap` and direction masks.
- IDA MCP `py_eval` on 2026-06-07 reconfirmed the exact storage item as `0x0069b4bc-0x0069b4c0` with five xrefs: loader write/read sites at `0x005042fa`, `0x00504315`, `0x00504331`, `0x00504397`, plus consumer bounds check read `0x00505561`. IDA MCP `get_bytes` on 2026-06-12 A003 Batch 342 supersedes the older byte note for the active `b001_nexustk` database: the exact storage slot is `00 00 00 00`. The exact split memory page is [UID:0002XQ][0x0069b4bc-0x0069b4c0.g_objectRecordCount](by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md).
- Historical 2026-06-16 C001 live IDA MCP recheck reconfirmed the zero bytes, five xrefs, `MapPaneInitialize` load/allocation/count loop behavior, and the `0x00505430` bounds-check consumer. C001 saved the IDA data label `g_objectRecordCount`; the current B004 session below preserves the source-facing name but supersedes that saved label as current-session proof. The consumer helper at `0x00505430` remains unnamed because its final source-facing purpose is broader than this count slot alone.

## 2026-06-23 B004 MCP-Backed Source-Quality Recheck

Current evidence uses IDA MCP endpoint `http://127.0.0.1:13337/mcp`, session `ff68e691`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, worker PID `14256`, and input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`. `server_health` was `ok` with auto-analysis, Hex-Rays, and strings cache ready. `survey_binary minimal` reported SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, `.text` `0x00401000-0x0060d000`, `.idata` `0x0060d000-0x0060d670`, `.rdata` `0x0060d670-0x0066d000`, and writable `.data` `0x0066d000-0x0069d000`. A supplemental local PE mirror at `E:\NTK\Resources\NexusTK\NexusTK.exe` is size `2679296` and has the same SHA-256.

MCP `get_bytes` on the exact storage child [UID:0002XQ][0x0069b4bc-0x0069b4c0.g_objectRecordCount](by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md) returned `00 00 00 00`; the full parent window `0x0069b4b4-0x0069b4c8` is twenty zero bytes. `get_global_value` by address returns `0x0` for `0x0069b4bc`, `0x0069b4c0`, and `0x0069b4c4`. Current name/global checks return no named `g_objectRecordCount`, `g_objectNationMap`, or `g_gameServerNationTable`, and `entity_query` over the local window returns no named global records, so this page treats `g_objectRecordCount` as the accepted source-facing name rather than current original-symbol proof.

Five direct xrefs classify the role. In `sub_504110` (`0x00504110`, size `0x411`), `0x005042fa` passes `&unk_69B4BC` with size `4` to the DAT read helper for the first four bytes of `SOBJ.TBL`, `0x00504315` reads the count for `g_objectNationMap` allocation sizing, and `0x00504331` / `0x00504397` use it as the parse-loop bound. In `sub_505430` (`0x00505430`, size `0x19a`), `0x00505561` reads it before object-id bounds checks and direction-mask tests using [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md).

The direct sibling relationship remains: [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md) at `0x0069b4c0` has six xrefs and is the byte-map pointer paired with this count; [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md) at `0x0069b4c4` has eighteen xrefs and belongs to the [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) nation-table family. Supplemental PE scan found five absolute-VA hits for `0x0069b4bc` and zero RVA/raw-offset pattern hits, rejecting a hidden pointer/RVA/raw-offset table owner.

The emitted type is `static std::uint32_t g_objectRecordCount = 0;` because the slot is a four-byte binary table count, the constructor draft uses unsigned indexes/object ids, and the consumer compares unsigned-ish object ids before indexing the byte map. `static unsigned int` would be an acceptable final-source spelling if the project avoids `<cstdint>`, but signed `int` is not the preferred primary type because no negative-count semantics appear.

## Caveats

`StaticObjImageLib` also reads the first four bytes of `SOBJ.TBL`, but stores that count in its instance field rather than in this global. Keep this global scoped to the map/gameplay cache, not the full static-object render table.

The `MapPane` loader uses slot zero as a sentinel and starts its read/store loop at index `1`. 2026-06-16 A002 parsing of the current `tile.dat` `SOBJ.TBL` payload confirms this is consistent with resource contents: the table has `19,551` records, starts with `485` records whose object id is `0xffffffff`, and first reaches a non-sentinel object id at table index `485`. The record-to-index convention is now package-backed, but the exact source meaning of the sentinel block and one-byte fields remains open.

B002's 2026-06-17 MapPane lifecycle pass accepts `g_objectRecordCount` and [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md) as the source-facing MapPane-owned compact-cache globals used by the first-draft `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)` and `MapPane::~MapPane()` bodies. The first draft resets this count during destructor cleanup after freeing `g_objectNationMap`; if later allocator evidence changes the free helper spelling, the owner/name route remains unchanged.

Rejected alternatives preserved by the B004 recheck: [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) is a mixed physical aggregate, not a declaration owner; [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) owns adjacent `g_gameServerNationTable` state but not the compact object-count/map pair; [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) owns render-object table parsing but not this global; adjacent singleton storage has no xref route to this slot; no-owner/non-emitting is rejected because the MapPane by-global route is clear; duplicate declaration on this by-global page and the exact memory child [UID:0002XQ][0x0069b4bc-0x0069b4c0.g_objectRecordCount](by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md) is rejected.

## Cross-References

- [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)

## Changes

- 2026-06-17 B002 MapPane lifecycle source-quality execution: score unchanged at `88/89`; added lifecycle confirmation that `g_objectRecordCount` is used by the accepted first-draft `MapPane` constructor/destructor bodies with `g_objectNationMap` as MapPane-owned compact `SOBJ.TBL` cache state. Remaining uncertainty is local record-field/sentinel interpretation, not the global name or owner route.
- 2026-06-23 B004 MCP-backed implementation: raised completion to `89` with confidence `89`; added first-draft declaration `static std::uint32_t g_objectRecordCount = 0;`; replaced overstrong current saved-label wording with the session `ff68e691` label caveat; incorporated current zero bytes, five xrefs, loader/consumer route, sibling split, PE route scan, unsigned-count rationale, MapPane owner/emitter route, and rejected alternatives.
- 2026-06-16 C001 global-storage/IDA refresh:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`.
  - Summary/evidence: live IDA MCP reconfirmed exact zeroed storage, five xrefs, loader/count behavior, and the consumer bounds-check path; saved `unk_69B4BC -> g_objectRecordCount`. Owner/emitter remain [UID:0000L3][MapPane](by-file/MapPane.md). Final C++ remains blank because the exact source spelling and SOBJ record-to-index convention remain open.
- 2026-06-16 A002 SOBJ payload sync: score unchanged at `88/89`; updated the DAT caveat after parsing the current `tile.dat` `SOBJ.TBL` payload. Evidence: [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md) now records a full `19,551`-record parse, `485` leading `0xffffffff` records, first non-sentinel object id at index `485`, and word-count range `0..12`. This resolves the sample-check blocker for the index convention but not final source naming or sentinel-block semantics.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/82`. Summary/evidence: the page documents address, relationship to `g_objectNationMap`, loader/count use, consumer bounds checks, and caveats about the map-gameplay cache versus `StaticObjImageLib`; scope is narrow but well-supported.
- 2026-06-05: Marked reconstructable under [UID:0000L3][MapPane](by-file/MapPane.md). Evidence: live IDA MCP xrefs to `0x0069b4bc` are confined to the map loader at `0x00504110` and consumer bounds checks at `0x00505430`; decompilation confirms the count is read before allocating and filling [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md).
- 2026-06-07 Batch 043 split-parent refresh:
  - Before: `84/82`, below the corrected `85/85` gate for assigning an exact memory storage child.
  - After: `86/86`.
  - Evidence: live IDA MCP reconfirmed exact four-byte storage bounds, initial value, loader write/read xrefs, and consumer bounds-check read. The remaining DAT record-to-index caveat affects final field naming, not ownership of this global count slot.
- 2026-06-12 A003 Batch 342: Corrected the active-IDB initial storage bytes from the stale `0xffffffff` note to `0x00000000`; xrefs and ownership remain unchanged.
