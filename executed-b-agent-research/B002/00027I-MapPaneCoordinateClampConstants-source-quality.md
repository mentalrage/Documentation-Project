** TARGET-REPORT-UID:00027I **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: [UID:00027I] MapPaneCoordinateClampConstants

Assignment id: `B002-goal2-mappane-coordinate-clamp-constants-source-quality-00027I-20260618`

Primary target: [UID:00027I] `by-memory/0x0066daa2-0x0066daec.MapPaneCoordinateClampConstants.md`

Report author: Agent-B002

Report-only status: no by-* documentation, generated reports/source, IDA database, or `by-memory/-coverage-report.md` files were edited. This report is the only file created for supervisor review/application.

## Finalized Report / Current Recommendation

Recommended disposition: split [UID:00027I] into exact children and make the current page a non-emitting mixed data-island index. Do not populate formal C++ on the combined [UID:00027I] range.

Recommended parent metadata after split:

```text
COMPLETION: 88
CONFIDENCE: 90
CANONICAL_OWNER: NONE
RECONSTRUCTABLE: FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE: blank
```

Recommended title/filename if the supervisor applies a rename:

```text
0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland.md
```

Why: the current target is not purely MapPane coordinate data. It is a mixed initialized `.data` island containing alignment padding, source-shaped but unreferenced legacy/current asset-remap triplets, live MapPane map-tile remap constants, live ItemObjImageLib item-entry remap constants, and then a hard boundary at [UID:00027J] `g_emptySimpleUString`. Keeping the whole page owned/emitted by [UID:0000L3] `MapPane` would incorrectly route ItemObjImageLib source data into `MapPane.cpp`. Multi-emitting the combined page would duplicate unrelated constants into both `MapPane.cpp` and `ItemObjImageLib.cpp`. The source-quality answer is exact splitting.

Recommended exact children:

| Range | Recommended child name | Rebuild status | Owner/emitter recommendation |
| --- | --- | --- | --- |
| `0x0066daa2-0x0066daa4` | `MapTileHeightTrailingPadding` | ignored padding | no owner/emitter |
| `0x0066daa4-0x0066dabc` | `UnreferencedLegacyAssetRemapTriplets` | reconstructable source-shaped data but no confirmed route | `CANONICAL_OWNER:NONE`, blank emitter until a real owner is proven |
| `0x0066dabc-0x0066dad4` | `MapPaneLegacyMapTileRemapConstants` | reconstructable source data | [UID:0000L3] `MapPane` file owner/emitter |
| `0x0066dad4-0x0066dae0` | `ItemObjImageLibLegacyItemRemapConstants` | reconstructable source data | [UID:0000KH] `ItemObjImageLib` file owner/emitter |
| `0x0066dae0-0x0066daec` | `UnreferencedLegacyAssetRemapTailTriplet` | reconstructable source-shaped data but no confirmed route | `CANONICAL_OWNER:NONE`, blank emitter until a real owner is proven |

## Target And Evidence Inputs

Primary target read:

- [UID:00027I] `by-memory/0x0066daa2-0x0066daec.MapPaneCoordinateClampConstants.md`

Required/support context read:

- [UID:0000L3] `by-file/MapPane.md`
- [UID:00007Q] `by-class/MapPane.md`
- [UID:0000KH] `by-file/ItemObjImageLib.md`
- [UID:0000UQ] `by-item/GetItemGlyphBounds_004DF460.md`
- [UID:0000T7] `by-global/MapTilePixelDimensions.md`
- [UID:00027F] `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md`
- [UID:0001AP] `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
- [UID:00027J] `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md`
- [UID:0000SW] `by-global/g_useEpfAssets.md`
- [UID:0001OH] `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`
- [UID:0000L5] `by-file/MapTileImageLib.md`
- [UID:0000K2] `by-file/ImageLib.md`
- [UID:00017N] `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`
- [UID:0001V3] `by-type/by-struct/MapTileRecord.md`
- [UID:0001QI] `by-meta/client_new_rendering_mode.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/NexusTK/map/MapPane.cpp`
- `auto-generated/NexusTK/render/ItemObjImageLib.cpp`
- B001 executed reports for [UID:0002CF] `g_movementSubstepScale` and [UID:0000ST]/[UID:0000SU] display dimensions

Read-only binary evidence:

- PE inspected: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base `0x00400000`.
- Sections observed: `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, `.data 0x0066d000-0x0069ce24`, `.rsrc 0x0069d000-0x006b2e00`.
- Capstone 5.0.7 was used for local read-only disassembly.
- IDA MCP was unavailable during this pass; `127.0.0.1:13337` had no listener. The report uses the current docs' prior live IDA facts plus fresh local PE disassembly/xref scans.
- Base conversions quoted as decimal were verified with `tools/int_convert.py`.

## Exact Byte Layout And Xref Recheck

Bytes for `0x0066daa2-0x0066daec`:

```text
00 00
68 02 00 00  a6 02 00 00  de 02 00 00
c3 00 00 00  ca 00 00 00  dc 00 00 00
e2 74 00 00  92 79 00 00  c1 79 00 00
8e 36 00 00  0a 38 00 00  22 38 00 00
72 09 00 00  20 0a 00 00  56 0a 00 00
93 00 00 00  a9 00 00 00  aa 00 00 00
```

Layout:

| Range | Values | Reanalysis |
| --- | --- | --- |
| `0x0066daa2-0x0066daa4` | `00 00` | two-byte padding after the two-byte `g_mapTilePixelHeight` child; aligns the following four-byte-spaced values at `0x0066daa4`. |
| `0x0066daa4-0x0066dabc` | `0x0268`, `0x02a6`, `0x02de`, `0x00c3`, `0x00ca`, `0x00dc` | two unreferenced legacy/current remap triplets; direct address scan and immediate scan found no real consumer. Decimal values are 616, 678, 734, 195, 202, and 220, verified with `int_convert.py`. |
| `0x0066dabc-0x0066dad4` | `0x74e2`, `0x7992`, `0x79c1`, `0x368e`, `0x380a`, `0x3822` | live MapPane map-tile record remap/clamp constants used only by `sub_50C120`. Decimal values 29922, 31122, 31169, 13966, 14346, and 14370 were verified with `int_convert.py`. |
| `0x0066dad4-0x0066dae0` | `0x0972`, `0x0a20`, `0x0a56` | live ItemObjImageLib item-entry remap constants used by `0x004defc0`, `0x004df2c0`, and `0x004df460`. Decimal values 2418, 2592, and 2646 were verified with `int_convert.py`. |
| `0x0066dae0-0x0066daec` | `0x0093`, `0x00a9`, `0x00aa` | one unreferenced legacy/current remap triplet; direct address scan and immediate scan found no real consumer. Decimal values 147, 169, and 170 were verified with `int_convert.py`. |
| `0x0066daec` | next object begins | [UID:00027J] `g_emptySimpleUString` starts here; all raw pointer hits to `0x0066daec` are for that next object, not for [UID:00027I]. |

All-section raw address scan found exact address operands only for:

- `0x0066dabc`, `0x0066dac0`, `0x0066dac4`, `0x0066dac8`, `0x0066dacc`, and `0x0066dad0`, all inside `0x0050c120`.
- `0x0066dad4`, `0x0066dad8`, and `0x0066dadc`, each inside `0x004defc0`, `0x004df2c0`, and `0x004df460`.
- `0x0066daec`, which belongs to the next `g_emptySimpleUString` range.

No raw VA/RVA pointer/table hits were found in `.text`, `.rdata`, `.data`, or `.rsrc` for `0x0066daa2`, `0x0066daa4`, `0x0066daa8`, `0x0066daac`, `0x0066dab0`, `0x0066dab4`, `0x0066dab8`, `0x0066dae0`, `0x0066dae4`, or `0x0066dae8`. A literal-immediate scan also found no meaningful uses of those values; the only incidental hits for `0x00ca` and `0x00dc` were unrelated early instructions/stack adjustment, not this data island.

## Consumer Reanalysis

### `sub_50C120`: MapPane Legacy-Aware Tile Record Helper

Best source-facing helper name:

```text
MapPane::GetLegacyAwareMapTileLayerIds(int tileX, int tileY, MapTileLayerIds *out)
```

Acceptable shorter aliases:

- `MapPane::GetMapTileLayerIds`
- `MapPane::GetTileRenderIds`
- `MapPane::GetTileRecordForDraw`

Evidence and behavior:

- Receiver `ecx` is `MapPane *`.
- Stack arguments are output pointer, tile X/column, and tile Y/row; the function returns the output pointer and cleans `0x0c` stack bytes.
- It bounds-checks the coordinates against `MapPane +0x3f4`/`+0x3f6` map width/height.
- It reads `MapPane +0x3f8` as the tile buffer, indexes a six-byte record, copies a dword from record `+0x00`, and copies a word from record `+0x04`.
- If `g_useEpfAssets` (`byte_66DA97`) equals `1`, it returns the record unchanged.
- In legacy/non-EPF mode, it remaps the first tile-id word and the third tile-id word:
  - First tile word: if the id is in `0x7992..0x79c1`, add signed 16-bit immediate `0xfb51`, mapping the band down to the legacy-adjacent range after `0x74e2`; otherwise values above `0x74e2` are clamped to `0`.
  - Third tile word: if the id is in `0x380a..0x3822`, add signed 16-bit immediate `0xfe85`, mapping the band down to the legacy-adjacent range after `0x368e`; otherwise values above `0x368e` are clamped to `0`.
- Out-of-bounds coordinates produce a zero/blank output record.

The current target title says “coordinate clamp constants,” but the live code proves the referenced constants are tile/resource-id remap and clamp thresholds inside a coordinate-indexed tile-record lookup. Keep “coordinate” in historical notes only; source-facing names should describe map tile layer id remapping.

Direct caller recheck:

| Caller site | Function start | Meaning |
| --- | --- | --- |
| `0x00505544`, `0x0050555c` | `0x00505430` | movement collision/nation-mask helper compares nearby tile-layer ids while deciding movement/object transition behavior. |
| `0x0050c07c` | `0x0050c040` | tile-span/visible-region helper loop. |
| `0x0050c3b4` | `0x0050c370` | tile draw helper; calls `MapTileImageLib::DrawTile` at `0x004d1a20` after retrieving a remapped tile id. This call is missing from the current target's four-caller list and should be added. |
| `0x0050d95f` | `0x0050d8e0` | map/tile render path; draws visible map cells and calls nearby tile-rect helper `0x0050c240`. |
| `0x0050f178` | `0x0050f130` | static-object tile-region refresh path; uses the map-tile layer id while reconciling static object panes. |

The existing target's caller inventory is mostly right but incomplete. It names `0x00505430`, `0x0050c040`, `0x0050d8e0`, and `0x0050f130`, but raw direct-call scanning also finds `0x0050c370`.

### ItemObjImageLib Remap Consumers

The item remap triplet at `0x0066dad4-0x0066dae0` is not MapPane data. It is read by three ItemObjImageLib/item helper functions:

- `0x004defc0` `ItemObjImageLib::DrawItemImageIn43x43Slot`
- `0x004df2c0` `ItemObjImageLib::DrawItemImageScaled`
- `0x004df460` [UID:0000UQ] `GetItemGlyphBounds`

All three perform the same legacy/non-EPF item-entry remap:

- Start with `itemId + 0x4000`.
- If `g_useEpfAssets == 1`, use the computed entry unchanged and select the EPF resource path.
- If not in EPF/current mode and the computed entry is in `0x0a20..0x0a56`, add signed 16-bit immediate `0xff53`, mapping the current band down to the range after `0x0972`.
- If not in the remap band and the computed entry is above `0x0972`, clamp to `0x0972`.
- `GetItemGlyphBounds` then uses `ITEM.EPF` versus `ITEM.EPD` layout tables and centers the returned rectangle by half of [UID:0000T7] `g_mapTilePixelWidth`/`g_mapTilePixelHeight`.

Recommended source-facing names:

```text
g_legacyItemImageMaxEntry
g_currentItemImageRemapFirstEntry
g_currentItemImageRemapLastEntry
```

These are file-level ItemObjImageLib constants, not MapPane constants. The current target should not continue claiming a single MapPane source owner for them.

## Heuristic / Inference Reanalysis And Validation

### Six MapPane Remap Constants

Best source-facing names for `0x0066dabc-0x0066dad4`:

| Address | Current raw label | Recommended descriptive name | Evidence |
| --- | --- | --- | --- |
| `0x0066dabc` | `word_66DABC` | `g_legacyMapTilePrimaryMaxId` | if first tile word is above this and not in the current remap band, `sub_50C120` writes zero. |
| `0x0066dac0` | `word_66DAC0` | `g_currentMapTilePrimaryRemapFirstId` | lower bound of first-word current/remap band. |
| `0x0066dac4` | `word_66DAC4` | `g_currentMapTilePrimaryRemapLastId` | upper bound of first-word current/remap band. |
| `0x0066dac8` | `word_66DAC8` | `g_legacyMapTileOverlayMaxId` | if third tile word is above this and not in the current remap band, `sub_50C120` writes zero. |
| `0x0066dacc` | `word_66DACC` | `g_currentMapTileOverlayRemapFirstId` | lower bound of third-word current/remap band. |
| `0x0066dad0` | `word_66DAD0` | `g_currentMapTileOverlayRemapLastId` | upper bound of third-word current/remap band. |

`Primary` and `Overlay` are high-probability descriptive names for the first and third 16-bit words in the map file tile-layer record. If the map-file tile record support docs later recover original field names, replace these with those canonical names. Do not use `word_66DABC`-style labels in final source.

Rejected alternatives:

- Coordinate clamp min/max names: rejected because the constants compare against tile/resource ids read from `m_tileBuffer`, not the input coordinates.
- MapTileImageLib ownership: rejected for this exact group because only MapPane helper `0x0050c120` directly reads these addresses. MapTileImageLib consumes the already-remapped id through `DrawTile`.
- `g_useEpfAssets` ownership: rejected as direct owner. The flag gates the branch, but the constants belong to the source that performs the remap.

### Three Item Remap Constants

Best source-facing names for `0x0066dad4-0x0066dae0`:

| Address | Current raw label | Recommended descriptive name | Evidence |
| --- | --- | --- | --- |
| `0x0066dad4` | `word_66DAD4` | `g_legacyItemImageMaxEntry` | clamp target/fallback entry for non-EPF item image lookup. |
| `0x0066dad8` | `word_66DAD8` | `g_currentItemImageRemapFirstEntry` | lower bound of current item-entry remap band. |
| `0x0066dadc` | `word_66DADC` | `g_currentItemImageRemapLastEntry` | upper bound of current item-entry remap band. |

Rejected alternatives:

- MapPane ownership: rejected because no MapPane code reads these addresses and all direct readers are ItemObjImageLib/item-glyph helpers.
- Generic `ITEM.TBL` count constants: too vague. The live code uses them specifically as current-to-legacy image-entry remap thresholds.
- ResourceLayoutTable ownership: rejected because ResourceLayoutTable performs the lookup after ItemObjImageLib computes the entry id; the thresholds are not read inside the layout helper.

### Six Leading No-Xref Constants

Best descriptive treatment for `0x0066daa4-0x0066dabc`:

```text
Legacy/current asset-remap triplet 0:
  g_legacyAssetRemapUnknown0MaxId          = 0x0268
  g_currentAssetRemapUnknown0FirstId       = 0x02a6
  g_currentAssetRemapUnknown0LastId        = 0x02de

Legacy/current asset-remap triplet 1:
  g_legacyAssetRemapUnknown1MaxId          = 0x00c3
  g_currentAssetRemapUnknown1FirstId       = 0x00ca
  g_currentAssetRemapUnknown1LastId        = 0x00dc
```

Inference basis:

- The two triplets have the same source shape as the live MapPane and item groups: a legacy max/fallback value followed by a current-mode remap band first/last pair.
- The values are four-byte-spaced low-word constants like the live referenced groups.
- They sit immediately before the live MapPane tile-remap groups.
- No direct address xrefs, raw pointer/table xrefs, or meaningful immediate uses were found.

Do not call these padding. They are nonzero source-shaped values with the same triplet pattern as the live remap thresholds. Also do not assign them to MapPane, ItemObjImageLib, MapTileImageLib, or `g_useEpfAssets` yet. The strongest safe recommendation is a no-owner/non-emitting exact child until a future resource-family pass finds a consumer or declaration owner.

Rejected alternatives:

- Alignment padding: rejected because the values are nonzero structured triplets, not fill bytes.
- MapPane constants: weak. Address adjacency to the live MapPane group is real, but no MapPane xref reads them.
- ItemObjImageLib constants: weak. They do not sit in the item group and no item helper reads them.
- MapTileImageLib constants: plausible as a resource-family hypothesis, but current `MapTileImageLib::DrawTile` does not read these addresses and `sub_50C120` handles the live map-tile remap.

### Three Trailing No-Xref Constants

Best descriptive treatment for `0x0066dae0-0x0066daec`:

```text
Legacy/current asset-remap tail triplet:
  g_legacyAssetRemapUnknownTailMaxId       = 0x0093
  g_currentAssetRemapUnknownTailFirstId    = 0x00a9
  g_currentAssetRemapUnknownTailLastId     = 0x00aa
```

Inference basis:

- Same triplet pattern as the live remap groups.
- Four-byte-spaced low-word values.
- Immediately follows the live ItemObjImageLib remap group.
- No direct address xrefs, raw pointer/table xrefs, or meaningful immediate uses were found.

Rejected alternatives:

- `g_emptySimpleUString` prefix: rejected because [UID:00027J] starts exactly at `0x0066daec`; the `0x0066dae0-0x0066daec` values precede it and are not string object fields.
- Padding: rejected because the values are nonzero and structured.
- ItemObjImageLib ownership: plausible from adjacency after the item triplet, but not strong enough without a consumer.

### Type Recommendation

Use 16-bit signed or unsigned storage names in documentation, with `short` first-draft C++ declarations for emitted children.

Rationale:

- All live consumers load these as `movsx word ptr [...]`.
- The initialized layout stores each low word in a four-byte slot. That could represent individually aligned `short` globals or 32-bit source variables whose low word is used through casts, but the direct machine code only proves signed 16-bit reads.
- Because the storage is in writable `.data` and code loads from memory, do not use `static const` as the first formal C++ shape unless a later compiler-output audit proves the build will still keep addressable storage. Prefer file-static `short` declarations for first draft.

### Existing Documentation Validation / Contradiction

Validated current docs:

- Exact bytes and the `0x0066daec` `g_emptySimpleUString` boundary are correct.
- `0x0066dabc-0x0066dad0` are read by `sub_50C120`.
- `0x0066dad4-0x0066dadc` are read by the three item-image/glyph helpers.
- `byte_66DA97` is the current/EPF mode selector that gates both MapPane and item legacy remap behavior.
- `0x0066daa2-0x0066daa4` is not a live two-byte global; it is best treated as alignment padding.

Contradicted or superseded current docs:

- Current owner/emitter [UID:0000L3] for the whole target is too broad and incorrect for the item-remap subgroup.
- The row name `MapPaneCoordinateClampConstants` is too narrow and partially misleading. The live constants are asset/tile/item id remap thresholds, not coordinate thresholds.
- The current four-caller list for `sub_50C120` is incomplete; add caller `0x0050c370` / call site `0x0050c3b4`.
- The current blank-C++ reason should not be “final names unresolved” only. The hard blocker is now source-shape/range mixing; exact child C++ is ready for the two referenced subgroups after split.
- The `by-memory/-coverage-report.md` row is stale at `82%`; the target page header is `85/85`, and this pass supports an index-level `88/90` plus child rows.

## Ranked Ownership And Split Analysis

### 1. Split Into Exact Children And Make [UID:00027I] A Non-Emitting Index

Decision: accepted.

Evidence for:

- Exact byte/layout boundaries are clear.
- Referenced MapPane group and referenced ItemObjImageLib group have disjoint direct consumers.
- The leading and trailing no-xref triplets are source-shaped but not safely assignable to either consumer.
- `0x0066daa2-0x0066daa4` is padding, and `0x0066daec` is a separate string object boundary.
- Exact child C++ can be source-facing and file-local without polluting the other source file.

Evidence against:

- The original source could have had a shared legacy asset remap constants header/source file. No current by-file owner models that, and the no-xref groups do not prove it.

Decision: best current source-quality answer.

### 2. Keep One Mixed Page, MapPane Owner/Emitter, With Support Notes

Decision: rejected.

Evidence for:

- MapPane has a valid generated route and one live subgroup is MapPane-only.
- Current docs already route the page to [UID:0000L3].

Evidence against:

- ItemObjImageLib-only constants would be emitted/documented under `MapPane.cpp`.
- The no-xref triplets would be incorrectly treated as MapPane data based only on adjacency.
- Formal C++ for the combined page would be misleading or would need comments and unused constants unrelated to MapPane.

### 3. One Page With Multiple Emitters

Decision: rejected.

Evidence for:

- The island contains constants used by more than one source file.

Evidence against:

- The constants are not shared constants used by both sources. Different subranges belong to different consumers.
- Multiple emitters would duplicate the entire combined declaration block into both `MapPane.cpp` and `ItemObjImageLib.cpp`.
- The no-xref groups still have no safe declaration owner.

### 4. New Shared `LegacyAssetRemapConstants.cpp`

Decision: rejected for now.

Evidence for:

- All non-padding values share a current-to-legacy resource remap triplet pattern.
- The branch depends on the process-wide [UID:0000SW] `g_useEpfAssets` current/legacy asset selector.

Evidence against:

- No source-tree entry, writer, startup initializer, function cluster, pointer table, or xref cluster proves such a file.
- Live xrefs are concentrated in MapPane and ItemObjImageLib consumers rather than through a shared helper/table.
- Creating a new file would overstate source evidence and would not solve no-xref ownership.

### 5. Reclassify No-Xref Groups As Padding/Sentinel Constants

Decision: partially rejected.

Accepted only for `0x0066daa2-0x0066daa4` padding.

Rejected for `0x0066daa4-0x0066dabc` and `0x0066dae0-0x0066daec` because their nonzero triplet structure matches the live remap groups. They should be documented as unreferenced legacy asset remap triplets, not padding. “Sentinel/reserved source constants” is plausible, but no emitted owner should be assigned yet.

## First-Draft C++ Recommendation

### Parent [UID:00027I] No-Code Proof

Do not populate formal C++ on the combined [UID:00027I] page.

Target-specific proof:

- The combined range crosses at least two source-file owners: MapPane for `0x0066dabc-0x0066dad4` and ItemObjImageLib for `0x0066dad4-0x0066dae0`.
- The range includes ignored padding at `0x0066daa2-0x0066daa4`.
- The range includes unreferenced source-shaped triplets whose declaration owner is not defensibly proven.
- A single C++ block emitted through [UID:0000L3] would incorrectly place item-image constants in `MapPane.cpp`.
- A single C++ block emitted through multiple UIDs would duplicate unrelated constants into multiple source files.

After splitting, populate formal C++ on the two referenced source-bearing children.

### Proposed Child C++: MapPane Legacy Map Tile Remap Constants

For new child `0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md`, owner/emitter [UID:0000L3]:

```cpp
namespace
{
    static short g_legacyMapTilePrimaryMaxId = 0x74e2;
    static short g_currentMapTilePrimaryRemapFirstId = 0x7992;
    static short g_currentMapTilePrimaryRemapLastId = 0x79c1;

    static short g_legacyMapTileOverlayMaxId = 0x368e;
    static short g_currentMapTileOverlayRemapFirstId = 0x380a;
    static short g_currentMapTileOverlayRemapLastId = 0x3822;
}
```

Notes for supervisor application:

- Use `short` rather than `const short` in first draft because the original storage is writable `.data` and live consumers load through memory.
- If the map-file tile record fields are later named, replace `Primary`/`Overlay` with those canonical names.
- These constants should sit near the `MapPane::GetLegacyAwareMapTileLayerIds` / tile-record lookup helper, not near the MapTileImageLib draw routine.

### Proposed Child C++: ItemObjImageLib Legacy Item Remap Constants

For new child `0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md`, owner/emitter [UID:0000KH]:

```cpp
namespace
{
    static short g_legacyItemImageMaxEntry = 0x0972;
    static short g_currentItemImageRemapFirstEntry = 0x0a20;
    static short g_currentItemImageRemapLastEntry = 0x0a56;
}
```

Notes for supervisor application:

- These declarations belong in `render/ItemObjImageLib.cpp` near the draw/glyph helper family.
- They should be referenced by `ItemObjImageLib::DrawItemImageIn43x43Slot`, `ItemObjImageLib::DrawItemImageScaled`, and `GetItemGlyphBounds`.
- [UID:0000UQ] can continue using the descriptive helper name `GetItemGlyphBounds`; the raw `0x004DF460` suffix is no longer needed in source-facing code.

### No C++ Yet For No-Xref Triplets

Do not populate C++ for the unreferenced leading/tail triplet children unless the supervisor decides they should be emitted as reviewed orphan source data. The current safer recommendation is:

- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:NONE`
- blank `EMITTER_UIDS`
- blank C++
- document the best descriptive names listed above and the zero-route evidence.

## Exact Supervisor Edits

### [UID:00027I] Target Page

Recommended header after split:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended summary replacement:

```text
This range is a reviewed non-emitting split/index over a small initialized `.data` island after `g_mapTilePixelHeight` and before [UID:00027J] `g_emptySimpleUString`. It contains two bytes of alignment padding, source-shaped no-xref legacy/current asset-remap triplets, a live MapPane map-tile remap group used by `MapPane::GetLegacyAwareMapTileLayerIds`, a live ItemObjImageLib item-entry remap group used by item draw/glyph helpers, and one no-xref tail remap triplet. The combined page must not emit C++ because the live subgroups have different source owners.
```

Recommended split note:

```text
Split recommendation: create exact children for `0x0066daa2-0x0066daa4` padding, `0x0066daa4-0x0066dabc` unreferenced legacy remap triplets, `0x0066dabc-0x0066dad4` MapPane legacy map-tile remap constants, `0x0066dad4-0x0066dae0` ItemObjImageLib legacy item remap constants, and `0x0066dae0-0x0066daec` unreferenced tail remap triplet. Keep this page as the parent index with `RECONSTRUCTABLE:FALSE`, blank owner/emitter, and blank formal C++.
```

### [UID:0000L3] MapPane Support

Recommended insert under Coordinate And Movement Globals or Coordinate Conversion notes:

```text
[UID:00027I] source-quality reanalysis resolves the live `0x0066dabc-0x0066dad4` subgroup as MapPane legacy map-tile remap constants, not generic coordinate constants. The helper at `0x0050c120` should be documented as `MapPane::GetLegacyAwareMapTileLayerIds` / `GetTileRenderIds`: it bounds-checks tile coordinates against `+0x3f4/+0x3f6`, reads the six-byte map tile-layer record from `+0x3f8`, and in legacy/non-EPF mode remaps the first and third tile-id words through the current-to-legacy bands `0x7992..0x79c1` and `0x380a..0x3822`, clamping out-of-range ids above `0x74e2` and `0x368e` to zero. Direct call sites are `0x00505544`, `0x0050555c`, `0x0050c07c`, `0x0050c3b4`, `0x0050d95f`, and `0x0050f178`; the `0x0050c370` tile-draw helper call is missing from older caller inventories.
```

### [UID:00007Q] MapPane Class Support

Recommended insert near coordinate/helper glossary:

```text
The `0x0050c120` tile-record helper is a `MapPane` instance method because it reads `this+0x3f4/+0x3f6/+0x3f8` map dimensions/tile-buffer fields and is called from MapPane movement, visible-tile, tile-draw, render, and static-object refresh helpers. The static constants it reads should be file-level `MapPane.cpp` constants, not class fields.
```

### [UID:0001AP] MapPaneWeatherCoordinateObjectCore

Recommended updates:

```text
Add exact caller/callee note: `0x0050c120` is better described as `MapPane::GetLegacyAwareMapTileLayerIds` / `GetTileRenderIds`, and the direct caller set includes the previously omitted `0x0050c370` tile-draw helper at call site `0x0050c3b4`. Its constants are tile-layer id remap thresholds, not coordinate min/max thresholds.
```

### [UID:0000KH] ItemObjImageLib Support

Recommended insert under Resource Inputs or legacy remap policy:

```text
[UID:00027I] reanalysis resolves the `0x0066dad4-0x0066dae0` subgroup as ItemObjImageLib legacy item-entry remap constants: `g_legacyItemImageMaxEntry = 0x0972`, `g_currentItemImageRemapFirstEntry = 0x0a20`, and `g_currentItemImageRemapLastEntry = 0x0a56`. They are read by `ItemObjImageLib::DrawItemImageIn43x43Slot` (`0x004defc0`), `ItemObjImageLib::DrawItemImageScaled` (`0x004df2c0`), and `GetItemGlyphBounds` (`0x004df460`) when `g_useEpfAssets != 1`; the code remaps entries in `0x0a20..0x0a56` by adding `0xff53` and clamps other entries above `0x0972` back to `0x0972`.
```

### [UID:0000UQ] GetItemGlyphBounds

Recommended replacement for remap-policy wording:

```text
The legacy/non-EPF remap thresholds are source data at [UID:00027I] subrange `0x0066dad4-0x0066dae0`, not literals unique to this helper. Use source-facing names `g_legacyItemImageMaxEntry`, `g_currentItemImageRemapFirstEntry`, and `g_currentItemImageRemapLastEntry` for the `0x0972`, `0x0a20`, and `0x0a56` values. The signed add immediate remains `0xff53`, mapping the current item-entry band down to the legacy-adjacent item-image entry range.
```

### [UID:0000T7] MapTilePixelDimensions

Recommended boundary note:

```text
The two bytes at `0x0066daa2-0x0066daa4` after `g_mapTilePixelHeight` are alignment padding before the legacy asset remap constants island. They are not part of `g_mapTilePixelHeight`, and the following constants should not be folded into the tile-dimension global pair.
```

### [UID:00027F] g_movementSubstepScale

No metadata change required. Optional support note:

```text
The adjacent [UID:00027I] constants remain excluded from the `g_movementSubstepScale` movement-helper grouping. Fresh B002 reanalysis found no function overlap with the scale reader set; the live referenced constants are legacy/current asset id remap thresholds for MapPane tile records and ItemObjImageLib entries.
```

## Coverage Row Recommendation

Current stale row to replace:

```text
    - [UID:00027I][0x0066daa2-0x0066daec.MapPaneCoordinateClampConstants](by-memory/0x0066daa2-0x0066daec.MapPaneCoordinateClampConstants.md) 0x0066daa2-0x0066daec | initialized coordinate/constants data | MapPaneCoordinateClampConstants : reconstructable : 82% : strong : Live IDA documents exact bytes, aligned values, MapPane coordinate xrefs, item-image remap xrefs, and split boundaries; nine no-xref constants and final static names remain open.
```

If supervisor applies the recommended rename/split, replace that row with this parent row and insert the child rows immediately below it. Replace `UID:NEW_*` placeholders with validator-assigned UIDs after child creation:

```text
    - [UID:00027I][0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland](by-memory/0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland.md) 0x0066daa2-0x0066daec | mixed legacy/current asset-remap constants index | LegacyAssetRemapConstantsDataIsland : ignored : 88% : very strong : B002 2026-06-18 source-quality reanalysis reclassifies the former MapPane-only constants page as a non-emitting split/index over padding, no-xref source-shaped legacy/current remap triplets, live MapPane map-tile remap constants, live ItemObjImageLib item-entry remap constants, and the `g_emptySimpleUString` boundary; combined formal C++ is blocked because one range would otherwise pollute MapPane.cpp with ItemObjImageLib constants or duplicate unrelated data through multiple emitters.
        - [UID:NEW_PAD][0x0066daa2-0x0066daa4.MapTileHeightTrailingPadding](by-memory/0x0066daa2-0x0066daa4.MapTileHeightTrailingPadding.md) 0x0066daa2-0x0066daa4 | padding | MapTileHeightTrailingPadding : ignored : 100% : strong : Two zero bytes after [UID:0001OK] `g_mapTilePixelHeight` and before the four-byte-spaced legacy asset remap constants; no direct address, pointer-table, or immediate-use route found.
        - [UID:NEW_LEAD][0x0066daa4-0x0066dabc.UnreferencedLegacyAssetRemapTriplets](by-memory/0x0066daa4-0x0066dabc.UnreferencedLegacyAssetRemapTriplets.md) 0x0066daa4-0x0066dabc | unreferenced legacy/current remap triplets | UnreferencedLegacyAssetRemapTriplets : reconstructable : 84% : strong : Six source-shaped four-byte-spaced low-word constants `0x0268/0x02a6/0x02de` and `0x00c3/0x00ca/0x00dc`; B002 PE scan found no direct address, pointer-table, or meaningful immediate consumer, but the values match the live legacy-current remap triplet pattern, so keep no-owner/non-emitting rather than padding or MapPane assignment.
        - [UID:NEW_MAP][0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants](by-memory/0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md) 0x0066dabc-0x0066dad4 | MapPane legacy map-tile remap constants | MapPaneLegacyMapTileRemapConstants : reconstructable : 88% : very strong : Six MapPane.cpp file-level remap thresholds read only by `0x0050c120` / inferred `MapPane::GetLegacyAwareMapTileLayerIds`; remaps first tile word band `0x7992..0x79c1` against legacy max `0x74e2` and third tile word band `0x380a..0x3822` against legacy max `0x368e`, with direct callers at `0x00505544`, `0x0050555c`, `0x0050c07c`, `0x0050c3b4`, `0x0050d95f`, and `0x0050f178`; first-draft file-static C++ ready under [UID:0000L3].
        - [UID:NEW_ITEM][0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants](by-memory/0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md) 0x0066dad4-0x0066dae0 | ItemObjImageLib legacy item remap constants | ItemObjImageLibLegacyItemRemapConstants : reconstructable : 89% : very strong : Three ItemObjImageLib.cpp file-level thresholds `0x0972`, `0x0a20`, and `0x0a56` read by `ItemObjImageLib::DrawItemImageIn43x43Slot`, `ItemObjImageLib::DrawItemImageScaled`, and `GetItemGlyphBounds`; in legacy/non-EPF mode the current item-entry band `0x0a20..0x0a56` is rebased by add-immediate `0xff53`, while other entries above `0x0972` clamp to `0x0972`; first-draft file-static C++ ready under [UID:0000KH].
        - [UID:NEW_TAIL][0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet](by-memory/0x0066dae0-0x0066daec.UnreferencedLegacyAssetRemapTailTriplet.md) 0x0066dae0-0x0066daec | unreferenced legacy/current remap triplet | UnreferencedLegacyAssetRemapTailTriplet : reconstructable : 83% : strong : Three source-shaped four-byte-spaced low-word constants `0x0093/0x00a9/0x00aa` before [UID:00027J] `g_emptySimpleUString`; B002 PE scan found no direct address, pointer-table, or meaningful immediate consumer, but the values match the live legacy-current remap triplet pattern, so keep no-owner/non-emitting rather than padding, string-prefix, or ItemObjImageLib assignment.
```

If supervisor does not split immediately, at minimum replace the current row with:

```text
    - [UID:00027I][0x0066daa2-0x0066daec.MapPaneCoordinateClampConstants](by-memory/0x0066daa2-0x0066daec.MapPaneCoordinateClampConstants.md) 0x0066daa2-0x0066daec | mixed legacy/current asset-remap constants data | MapPaneCoordinateClampConstants : reconstructable : 88% : very strong : B002 2026-06-18 source-quality reanalysis proves the combined range is mixed: padding at `0x0066daa2-0x0066daa4`, no-xref remap triplets at `0x0066daa4-0x0066dabc` and `0x0066dae0-0x0066daec`, MapPane-only map-tile remap constants at `0x0066dabc-0x0066dad4`, ItemObjImageLib-only item remap constants at `0x0066dad4-0x0066dae0`, and [UID:00027J] boundary at `0x0066daec`; current MapPane-only owner/emitter and blank-C++ wording are stale, and exact split is required before formal C++ is safe.
```

No direct edit was made to `by-memory/-coverage-report.md`.

## Validator Commands After Supervisor Application

Suggested split/application validation:

> Executable block R001 was removed from this report and preserved verbatim in [00027I-MapPaneCoordinateClampConstants-source-quality-removed.md](00027I-MapPaneCoordinateClampConstants-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor does not rename/split in the same pass, validate only the current [UID:00027I] file and support docs after applying non-split notes.

## Remaining Uncertainties And Impact

- Original source symbol spelling is not recovered for any of these constants. Impact: confidence stays below 95; use descriptive names.
- The exact source owner of the unreferenced leading/tail triplets is not defensible from current evidence. Evidence checked: direct xrefs, raw address/pointer scan across all PE sections, literal-immediate scan, support docs for MapPane/ItemObjImageLib/MapTileImageLib/ImageLib/current-rendering mode. Impact: these children should remain no-owner/non-emitting with blank C++.
- The map tile-layer record field names are still not final. Impact: `Primary` and `Overlay` in the MapPane constants are descriptive placeholders; if future map-file docs name the first and third 16-bit tile words, update the constant names.
- A future shared legacy asset-remap constants source/header remains possible. Impact: do not create a new shared file now; revisit only if xrefs, writer/initializer evidence, source metadata, or a broader resource-family pass proves that grouping.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B002/research/00027I-MapPaneCoordinateClampConstants-source-quality.md`

Modified:

- None outside the B002 research folder.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00027I-MapPaneCoordinateClampConstants-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00027I"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00027I-MapPaneCoordinateClampConstants-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00027I-MapPaneCoordinateClampConstants-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00027I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
