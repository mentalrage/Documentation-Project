*** UID:0000Q3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static std::uint8_t* g_objectNationMap = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_objectNationMap

## Status

- Confidence: strong for storage address, role, xrefs, lifecycle, source declaration route, and MapPane placement; medium-high for final source spelling because current B005 MCP name/global queries do not expose a named `g_objectNationMap` entity.
- IDA storage: `0x0069b4c0`; current B005 MCP session `80de0a67` renders this as `unk_69B4C0`, while historical generated labels include `unk_69B4C0` / `dword_69B4C0` and C001's 2026-06-16 session saved `g_objectNationMap`.
- Related count storage: [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md), `0x0069b4bc` (`g_objectRecordCount`).
- Proposed owner/source root: [UID:0000L3][MapPane](by-file/MapPane.md). [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) owns the adjacent [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md), not this compact object-map pointer.

## Role

`g_objectNationMap` is a lazily allocated byte array loaded from `SOBJ.TBL` during map-pane initialization. It maps static-object record ids or indices to the second one-byte classification field from each `SOBJ.TBL` record.

Accepted first-draft source declaration:

```cpp
static std::uint8_t* g_objectNationMap = NULL;
```

The `std::uint8_t*` type follows the byte-indexed allocation/fill/consumer behavior and the sibling [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md) declaration style. `NULL` matches the surrounding MapPane constructor/destructor drafts. The original source may have used `unsigned char*`, `BYTE*`, `std::uint8_t*`, `nullptr`, or another local style; that spelling uncertainty caps confidence but no longer blocks this source declaration.

## Loader Behavior

`MapPaneInitialize` at `0x00504110` performs the load when `g_objectNationMap` is null:

1. Open [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md).
2. Read a 4-byte object record count into [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md).
3. Read a 2-byte table header.
4. Allocate `g_objectRecordCount + 1` bytes and set `g_objectNationMap[0] = 0`.
5. Iterate the observed records, reading `4 + 1 + 1 + 1 + count * 2` bytes per record.
6. Store the second one-byte field into `g_objectNationMap[index]`.

IDA shows the loop index starts at `1` and continues while it is less than `g_objectRecordCount`. 2026-06-16 A002 package parsing of the current `tile.dat` `SOBJ.TBL` payload confirms the table starts with a leading reserved/sentinel block: the first `485` records have object id `0xffffffff`, and the first non-sentinel object id is at table index `485`. This supports the slot-zero seed and index-based map convention, but it does not prove final source names for the one-byte fields.

B002's 2026-06-17 MapPane lifecycle pass accepts `g_objectNationMap` and [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md) as the source-facing MapPane-owned compact-cache globals used by the first-draft `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)` and `MapPane::~MapPane()` bodies. The original names of the per-record one-byte fields remain descriptive (`sourceNationOrClass`, `objectNation`, `extraWordCount`), but that local uncertainty no longer blocks the global names or MapPane source placement.

## Consumers

- `0x00505430` reads `g_objectRecordCount` and `g_objectNationMap` during map movement/collision or placement logic, combining map bytes with direction masks at `byte_66DD50` and `byte_66DD58`. C001 checked this body and its nine callers, but skipped a function rename because the final source-facing helper name is still not proven.
- `MapPaneCleanup` at `0x00504530` frees the array during map-pane teardown and clears `g_objectNationMap`.
- `StaticObjImageLib` separately parses the same `SOBJ.TBL` resource for the full static-object image table. That class owns the render/resource object records; this global is a map-gameplay classification cache.
- IDA MCP `py_eval` on 2026-06-07 reconfirmed the exact storage item as `0x0069b4c0-0x0069b4c4` with six xrefs: loader guard/write/read sites at `0x005042de`, `0x00504324`, `0x0050438b`, teardown read/clear sites at `0x0050463d` and `0x00504653`, and consumer read `0x0050557e`. IDA MCP `get_bytes` on 2026-06-12 A003 Batch 342 supersedes the older byte note for the active `b001_nexustk` database: the exact storage slot is `00 00 00 00`. The exact split memory page is [UID:0002XR][0x0069b4c0-0x0069b4c4.g_objectNationMap](by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md).
- Historical 2026-06-16 C001 live IDA MCP recheck reconfirmed the zero bytes, six xrefs, `MapPaneInitialize` loader allocation/fill, `MapPaneCleanup` free/clear, and `0x00505430` consumer. C001 saved the IDA data label `g_objectNationMap`; B004's then-current session `ff68e691` later narrowed that saved-label wording because name/global queries returned no named entity and disassembly still rendered `unk_69B4C0`. B005's current session `80de0a67` supersedes both earlier checks as the active proof for this implementation. The decompiler still leaves the consumer helper and record field variables unnamed, so final helper/field names remain open.

## 2026-06-23 B005 Current MCP Evidence And Source Declaration

B005 rechecked this global with active MCP session `80de0a67` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `server_health` returned `status=ok`, module `NexusTK.exe`, image base `0x400000`, and ready auto-analysis/Hex-Rays/strings. `survey_binary(minimal)` reports PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632` and `.data 0x0066d000-0x0069d000`.

Current storage/name facts:

- [UID:0002XR][0x0069b4c0-0x0069b4c4.g_objectNationMap](by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md) is exact zero-initialized four-byte `.data` storage: `00 00 00 00`.
- `lookup_funcs(0x0069b4c0)` reports not a function.
- `get_global_value(0x0069b4c0)` returns `0x0`, but `get_global_value` by name `g_objectNationMap` returns `Not found`.
- `entity_query` over `0x0069b4b4-0x0069b4c8` returns zero names and zero globals; name/global searches for `g_object`, `objectNation`, `gameServerNation`, and `unk_69B4` do not expose a named target record.
- This means the current IDB display is still `unk_69B4C0`; `g_objectNationMap` is the accepted source-facing project name from lifecycle evidence, not a current recovered symbol.

Current lifecycle/xref facts:

| Site | Function | Role |
| --- | --- | --- |
| `0x005042de` | `sub_504110` / [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) | Guard compares the pointer against zero before loading `SOBJ.TBL`. |
| `0x00504324` | `sub_504110` | Stores the allocation result for `g_objectRecordCount + 1` bytes. |
| `0x0050438b` | `sub_504110` | Reads the pointer to fill per-record compact bytes. |
| `0x0050463d` | `sub_504530` / [UID:0002QF][0x00504530-0x005046c6.MapPaneCleanup](by-memory/0x00504530-0x005046c6.MapPaneCleanup.md) | Reads the pointer before freeing it. |
| `0x00504653` | `sub_504530` | Stores the free-helper result back to the global, clearing it. |
| `0x0050557e` | `sub_505430` | Consumer reads the map pointer for object classification/direction-mask checks. |

`decompile(0x00504110)` shows the lazy load: read [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md), read a two-byte header, allocate `count + 1`, seed slot zero to `0`, and store the second one-byte field from each observed `SOBJ.TBL` record into the compact byte map. `decompile(0x00504530)` shows read/free/clear behavior for this pointer; B005 did not find a current direct `g_objectRecordCount` reset xref in that cleanup function. `decompile(0x00505430)` shows the consumer reads [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md), indexes this byte map, and tests the values with [UID:00027O][0x0066dd50-0x0066dd60.MapObjectDirectionMasks](by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md) table bytes.

Targeted negative checks support the xref set: VA little-endian pattern `c0 b4 69 00` appears only at the six direct target refs; RVA pattern `c0 b4 29 00` has no hits. The adjacent count VA has five matches, and the adjacent [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md) VA has eighteen matches, preserving the sibling split.

Source-placement decision:

- [UID:0000L3][MapPane](by-file/MapPane.md) is the source file/root owner because every direct target xref is in MapPane initialization, cleanup, or object-collision/classification logic.
- [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md) is a support sibling and allocation/bounds input, not this pointer's owner.
- [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md) and [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) are rejected as direct owners because the adjacent table slot has a separate eighteen-xref route and belongs to GameServerConfig nation-entry state.
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) remains a mixed non-emitting physical cluster, not a declaration owner.
- `StaticObjImageLib` is rejected as owner: it parses the full static-object render metadata view of `SOBJ.TBL`, while this global is a compact MapPane gameplay/classification cache.
- No-owner/non-emitting is rejected. Current missing live-symbol proof caps confidence but does not defeat the coherent MapPane lifecycle and declaration route.

## 2026-06-23 B004 Local Sibling Sync

B004's [UID:0002XQ][0x0069b4bc-0x0069b4c0.g_objectRecordCount](by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md) implementation pass rechecked this sibling only to keep the local cluster consistent. That then-current session `ff68e691` reported zero bytes at `0x0069b4c0`, six xrefs (`0x005042de`, `0x00504324`, `0x0050438b`, `0x0050463d`, `0x00504653`, `0x0050557e`), no named global record, and the same MapPane owner route. B005 session `80de0a67` is now the current proof for this page and is recorded above.

## Caveats

Working field names call the first byte `sourceNation`, the second byte `mappedNation`, and the length byte `attributeCount`. `StaticObjImageLib` names the same byte widths as palette/unused/name-length fields. The widths, reads, and index convention are now backed by package parsing, but the semantic names still need validation against map rules and source terminology.

The by-global declaration is source-ready, but the exact original spelling of this global and the source type spelling are inferred. The final source might have used `unsigned char*`, `BYTE*`, `std::uint8_t*`, or a project typedef. Current docs choose `std::uint8_t*` because the map is byte-indexed and because [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md) already uses fixed-width source-facing integer style.

## Cross-References

- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)
- [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)

## Changes

- 2026-06-23 B005 accepted source-quality implementation:
  - Changed from `COMPLETION:88`, `CONFIDENCE:89` to `COMPLETION:89`, `CONFIDENCE:90`.
  - Added first-draft source declaration `static std::uint8_t* g_objectNationMap = NULL;`.
  - Replaced stale current-proof wording with MCP session `80de0a67`, current no-named-global caveat, exact zero bytes, six lifecycle xrefs, MapPane allocation/fill/free/consumer behavior, sibling separation, owner/source-placement rejections, and unresolved source-spelling/SOBJ-field caveats.
- 2026-06-17 B002 MapPane lifecycle source-quality execution: score unchanged at `88/89`; added lifecycle confirmation that `g_objectNationMap` is used by the accepted first-draft `MapPane` constructor/destructor bodies as a MapPane-owned compact `SOBJ.TBL` cache global. Remaining uncertainty is local record-field naming, not the global name or owner route.
- 2026-06-23 B004 local sibling sync: score/C++ unchanged; narrowed stale saved-label wording after current MCP session `ff68e691` showed zero bytes and six xrefs but no named `g_objectNationMap` entity in name/global queries.
- 2026-06-16 C001 global-storage/IDA refresh:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`.
  - Summary/evidence: live IDA MCP reconfirmed exact zeroed storage, six xrefs, loader allocation/fill behavior, teardown free/clear behavior, and the direction-mask consumer path; saved `unk_69B4C0 -> g_objectNationMap`. Owner/emitter remain [UID:0000L3][MapPane](by-file/MapPane.md). Final C++ remains blank because the exact source spelling, consumer helper name, and SOBJ one-byte field semantics remain below final-source confidence.
- 2026-06-16 A002 SOBJ payload sync: score unchanged at `88/89`; updated the loader/caveat wording after parsing the current `tile.dat` `SOBJ.TBL` payload. Evidence: [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md) now records a full `19,551`-record parse, `485` leading `0xffffffff` records, first non-sentinel object id at index `485`, and word-count range `0..12`. This resolves the sample-check blocker for the index convention but not final field/source names.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents storage, related count global, `SOBJ.TBL` loader behavior, consumers, cleanup, source owner, and DAT semantic caveats; final names for record fields remain medium-confidence.
- 2026-06-05: Marked reconstructable under [UID:0000L3][MapPane](by-file/MapPane.md). Evidence: live IDA MCP xrefs to `0x0069b4c0` show allocation and stores in `0x00504110`, cleanup in `0x00504530`, and consumer reads in `0x00505430`; decompilation confirms the loader reads `g_objectRecordCount`, allocates `count + 1`, seeds slot zero, and stores one byte per record.
- 2026-06-07 Batch 043 split-parent refresh:
  - Before: confidence `80`, below the corrected `85/85` gate for assigning an exact memory storage child.
  - After: confidence `86`; completion remains `86`.
  - Evidence: live IDA MCP reconfirmed exact four-byte storage bounds, initial value, loader allocation/write/read xrefs, teardown read/clear xrefs, and consumer read. DAT field semantic names remain caveated but no longer weaken the storage/ownership claim.
- 2026-06-12 A003 Batch 342: Corrected the active-IDB initial storage bytes from the stale `0xffffffff` note to `0x00000000`; xrefs and ownership remain unchanged.
