*** UID:0000J3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# EPF Image Resources

## Status

- Confidence: very strong for exhaustive source-family ownership, explicit non-emitting index status, the one-object ImageLib/ResourceLayout/g_pEPFLib boundary, generic-List source shape, GetItemGlyphBounds placement, DATArchive dependency boundary, concrete render splits, and blank CPP/H disposition; exact historical directory and private lexical spellings remain inferred.
- Proposed modules: `render/EPFTileContext.cpp`, `render/ImageLib.cpp`, `render/ResourceLayoutTable.cpp`, `render/ImageFrameTable.cpp`, render support files, and per-asset image-library files.
- Evidence basis: existing EPF/render documentation plus current IDA 9.1 MCP checks of the shared EPF table-loader/helper addresses, singleton lifetime, and ResourceLayout API edges.

## Historical Source-Family Hypothesis (Refined)

EPF/EPD support is a rendering/resource layer above the DAT archive API. The original project likely did not put all of this code in `DATFile.cpp`; DAT supplies entry lookup and mapped payload access, while EPF/EPD code owns frame bounds, payload-offset tables, image-library selection, and decoded tile/pixel contexts.

Likely original split:

```text
render/EPFTileContext.cpp
render/DIBitmap.cpp
render/ImageLoaders.cpp
render/ImageLib.cpp
render/ResourceLayoutTable.cpp
render/ImageFrameTable.cpp
render/Palette.cpp
render/FontImageLib.cpp
render/AlphaMaskSurface.cpp
render/Surface.cpp
render/MapTileImageLib.cpp
render/StaticObjImageLib.cpp
render/EffectObjImageLib.cpp
render/ItemObjImageLib.cpp
render/HumanImageLib.cpp
render/NewHumanImageLib.cpp
render/MonsterImageLib.cpp
render/MonsterImageLibTables.cpp
render/RidingImageLib.cpp
render/LightObjImageLib.cpp
ui/controls/EPFImageControlPane.cpp
```

This should be treated as a working source-tree hypothesis. The key rule is that DAT parsing stays in [UID:0000IM][DATArchive](by-file/DATArchive.md), while image-frame metadata and image-library code stay under render/UI ownership.

The concrete file-level pages now split the shared support layer into:

- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md) for the decoded frame context, buffer lifecycle, and RLE transparency-mask cache.
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) for `LoadImageFrameTable_4D0F50`, `LoadFrameDrawRecord_4D1600`, and the shared frame-table record model.
- [UID:0000K2][ImageLib](by-file/ImageLib.md) and [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) for the process-wide EPF/EPD layout registry and list-backed resource-name store, while asset-specific image libraries keep their own one-caller table builders.

## Shared Table Format

Several helpers use the same packed EPF/EPD metadata shape:

```text
ArchiveMetadataTable / FrameRecordTable
  +0x00  uint16 entryCount
  +0x02  uint16 maxMetric0
  +0x04  uint16 maxMetric1
  +0x06  uint16 reserved
  +0x08  PackedArchiveRecord* records

PackedArchiveRecord
  +0x00  int left
  +0x04  int top
  +0x08  int right
  +0x0c  int bottom
  +0x10  int payloadStart
  +0x14  int payloadEnd
```

The loader reads an 8-byte table header, then a 4-byte record-table offset, then seeks to the record table. Each record stores four signed 16-bit bounds values followed by start/end payload offsets. The loader normalizes bounds with `InitRectBounds` and adds `DATFile::GetDataPointer()` to the payload offsets so records point into the mapped DAT-backed EPF payload.

The loaders allocate `entryCount + 1` records and append a zero-bounds terminal sentinel. For single archives the sentinel offset is `payloadBaseOffset + recordTableOffset`; merged archives use the last shard's same base-plus-table offset.

## Resource Layout Registry

2026-05-22 follow-up resolves the earlier registry question but refines the class boundary: [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / historical IDA alias `DAT_0067a744` is initialized by `ImageLib::ImageLib`, while the EPF/EPD layout lookup methods are currently recovered as `ResourceLayoutTable`. This belongs with render/resource code, while UI controls and per-asset image-library classes consume it. 2026-05-24 IDA MCP xrefs confirmed the global owner writes are in the `ImageLib` constructor/destructor family, and the broad `g_pEPFLib` xref set is mostly consumer reads.

`ResourceLayoutTable::LoadResourceIndex` opens a named EPF/EPD entry through `DATFile`, reads the frame table, normalizes offsets with `DATFile::GetDataBase() + 0xc`, appends a sentinel, and appends the result to a [UID:0000KS][List](by-file/List.md)-backed resource-name record table. `ResourceLayoutTable::LookupLayoutEntry` then fills an `EPFTileContext` for callers. Existing cross-reference docs show broad use across UI panes, image libraries, item/effect helpers, and `EPFImageControlPane`.

2026-06-14 C001 live IDA MCP recheck used the active `NexusTK.exe.i64` session with auto-analysis and Hex-Rays ready. `0x0067a744` is still global storage rather than a function, and bytes around `0x0067a738-0x0067a758` are zero-initialized storage. Paged xrefs to `0x0067a744` still include the `ImageLib` constructor writes at `0x004cffef` / `0x004cfff6`, destructor cleanup at `0x004d00fa`, and many UI/render consumer reads; the result set reported more pages. The ImageLib lifecycle functions at `0x004cffb0`, `0x004d0070`, and `0x004e64a0` share `off_61B654` and `dword_67A744`, while vtable pointer `0x0061b654` has only the constructor/destructor-family refs at `0x004d0009`, `0x004d009a`, and `0x004e64d1`.

The same recheck confirmed the ResourceLayout public API starts and lazy-load edges: `0x004d0120` loads a named resource index; `0x004d02f0`, `0x004d0530`, `0x004d1730`, and `0x004d1780` all call through the lookup/load pair as needed; and `0x004d04d0` is a small `__stdcall` wrapper over `0x004d02f0`. The frame-table neighborhood still has modeled functions at `0x004d0f50` and `0x004d1600`; raw helper starts at `0x004d1660` and `0x004d1710` remain non-functions in IDA; and `0x004d182f` is padding immediately before the successor body. This supports the current split between concrete render source pages and this non-emitting umbrella page.

The generated `EPFLibrary::LoadFrame` references in some files should be treated as naming artifacts until proven otherwise; their call target is `ResourceLayoutTable::LookupLayoutEntry`. The original class may have exposed these methods directly from `ImageLib`, or through a base/helper slice now recovered as `ResourceLayoutTable`. The supporting store model is a [UID:0000KS][List](by-file/List.md) of 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) rows; [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md) and [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) are retained as provisional aliases for older generated overlays.

Integer constants used in this family were rechecked with the required conversion wording: `0x2c` = decimal 44 (Verified with int_convert.py), `0xa` = decimal 10 (Verified with int_convert.py), `0xf4240` = decimal 1000000 (Verified with int_convert.py), `0x4e20` = decimal 20000 (Verified with int_convert.py), and `0x14` = decimal 20 (Verified with int_convert.py).

Palette ownership is a parallel render-resource layer. [UID:0000MA][Palette](by-file/Palette.md) groups `PaletteLib` / `g_pPaletteLib`, `DLPalette`, slot constants, and adjacent palette-state helpers. It loads `baram.pal`, 25 category palette sets, and optional `SUPER0.PAL` through `SUPER6.PAL`; `DLPalette` stores the native 16-bit lookup tables consumed by EPF/tile blitters. This supports a `render/Palette.cpp` owner beside, not inside, DAT parsing.

## Shared Helpers

| Function | Current owner file | Role |
| --- | --- | --- |
| `LoadImageFrameTable_4D0F50` | [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) | Loads one EPF/EPD frame table or merges numbered human/equipment archive shards. |
| `LoadFrameDrawRecord_4D1600` | [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) | Extracts one draw/metrics record from a loaded frame metadata table. |
| `LoadTileEpfMetadata` | [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) | Scans `TILE%d.EPF` and builds the map-tile [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) consumed by [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md). See [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md). |
| `BuildTilecArchiveTable` | [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) | Scans `TILEC%d.EPF` and builds static-object metadata for [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md). See [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md). |
| `BuildEffectArchiveTable` | [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) | Scans `EFFECT%d.EPF` and builds effect metadata for [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md). See [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md). |
| `ResolveSpritePartPath` | `ResolveSpritePartPath_004E19D0.cpp` | Resolves either numbered `<base>%d.EPF` shards or a single `<base>.EPF` for `NewHumanImageLib`. See [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md). |
| `GetItemGlyphBounds` | [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) or a neighboring item-image helper | Resolves and recenters item icon bounds from `ITEM.EPF` or `ITEM.EPD`. See [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md). |
| `DrawFrameWithBlendMode` | `DrawFrameWithBlendMode_00462E10.cpp` | Copies/adds/subtracts byte frame masks into `AlphaMaskSurface`; used by light draw modes. See [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md). |
| `DrawEncodedAlphaFrame` provisional | currently not emitted as a recovered source | Draws signed-run encoded frame rows into an alpha mask with a vertical alpha ramp; used by several image-library callers. See [UID:0000UH][DrawEncodedAlphaFrame_00462F20](by-item/DrawEncodedAlphaFrame_00462F20.md). |

IDA MCP checks and existing item docs show the EPF/EPD table-loading helpers call [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), `DATFile`, `DATFile::GetDataPointer`, and allocation/rect helpers. They should depend on the DAT archive API but should not be owned by the DAT module. The alpha-mask blitters in the same table are lower-level render helpers rather than DAT consumers.

## Consumer Classes

| Class | Current summary | Ownership implication |
| --- | --- | --- |
| `ImageLib` | EPF image library manager singleton behind `g_pEPFLib`. | Strong candidate owner for the central layout/cache manager and related source file; IDA confirms [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md), [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md), and the ordinary destructor at [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md). |
| `MapTileImageLib` | Image library for map tile sprites behind [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md). | Owns `TILE.TBL`, `TILE.TBD`, `TILE%d.EPF`, [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md), [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md), and calls `LoadTileEpfMetadata`. |
| `StaticObjImageLib` | Image library for static map object sprites behind [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md). | Owns `SOBJ.TBL`, `TILEC` resources, [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md), [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md), [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md), and calls `BuildTilecArchiveTable`. |
| `EffectObjImageLib` | Image library for effect object sprites behind [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md). | Owns `EFFECT.TBL`, `EFFECT.FRM`, `EFFECT%d.EPF` / `EFFECT.EPD`, [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md), [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md), [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md), [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md), and calls `BuildEffectArchiveTable`. |
| `ItemObjImageLib` | Image library for item object sprites behind [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md). | Owns `ITEM.TBL` / `ITEM.TBD`, `ITEM.EPF` / `ITEM.EPD`, [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md), [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md), item sprite drawing, and likely `GetItemGlyphBounds`. |
| `HumanImageLib` | Legacy human character body/equipment image library behind [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md). | Calls `LoadImageFrameTable_4D0F50` for many old human/equipment archives, owns [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md), and has IDA-confirmed vtable `0x0061b6d4`. |
| `NewHumanImageLib` | Updated human sprite image library behind [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md). | Owns `Motion.tbl`, `Layer.tbl`, `Part.tbl`, per-part descriptor tables, `acc2drw.tbl`, `HAIRCOL.TBL`, [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md), and composed-part rendering. |
| `MonsterImageLib` | Monster character sprite image library behind [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md). | Owns `MONSTER.DNA`/`MONSTER.DND`, `DATA/MON%d.DAT` archive indexing, [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md), [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md), [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md), render/projection paths, and lazy bounds buckets. |
| `MonsterImageLibTable_5289D0` / `MonsterImageLibTable_528BE0` | Shared monster/riding animation table helpers. | Used by both `MonsterImageLib` and `RidingImageLib`; current names are not final. |
| `RidingImageLib` | Riding/mount sprite image library behind [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md). | Owns `RIDINGS.DNA`, `RIDINGS.EPF`, [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md), [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md), and [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md), and calls `LoadImageFrameTable_4D0F50`. |
| `LightObjImageLib` | Light source image library behind [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md). | Reads `LIGHT.TBL`, owns [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md) and [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md), and builds procedural radial light frames; not an EPF frame-table owner. |
| `FontImageLib` | Font glyph image library behind [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md). | Owns `BA0`/`BA1` font archives, [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md), [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md), [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md), glyph metrics, and glyph-to-`EPFTileContext` decode. |
| `DIBitmap` / PCX helpers | Startup PCX image loader and Win32 DIB wrapper. | DAT-aware image loading support, but not an archive parser. |
| `AlphaMaskSurface` | Temporary byte alpha-mask surface. | Shared render/blit primitive used by light/shading and encoded sprite-mask paths. |
| `EPFImageControlPane` | UI control widget for EPF images. | UI-side consumer of `g_pEPFLib`, not core EPF parser owner. |

## Current Ownership Decision And Exhaustive Closure

The complete 2026-08-17 B008 whole-family pass resolves this page as an explicit non-reconstructable documentation index. UID0000J3 has no unique function, helper, raw body, thunk, EH object, FuncInfo object, global, static, constant, string, table, data object, type, enum, vtable, RTTI object, resource, import, address range, or generated translation unit. It therefore remains `PROPOSED_RECONSTRUCTION_PATH:"NONE"`, `CANONICAL_OWNER:NONE`, has no emitter, and is now explicitly `RECONSTRUCTABLE:FALSE`. The `96/94` score reflects complete ownership/source-placement/behavior/generated closure with a bounded confidence reserve for exact historical directory and private lexical spellings.

### ImageLib And ResourceLayout Boundary

There is one concrete 20-byte ImageLib object behind [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), not separate ImageLib and ResourceLayoutTable instances. Current IDA storage at `0x0067a744` is four zero-initialized bytes named `g_pEPFLib`, currently typed `ResourceLayoutTable *`, with 231 xrefs. Vtable cell `0x0061b654` contains `0x004e64a0` and has exactly three lifecycle references from the constructor, ordinary destructor, and scalar deleting wrapper. No second ResourceLayout storage, constructor, destructor, vtable, RTTI object, or independent UDT exists.

[UID:0000K2][ImageLib](by-file/ImageLib.md) is the source owner for the lifecycle plus nine class/facet operations: `LoadResourceIndex`, `LookupLayoutEntry`, `CopyEntryTileContext`, `GetEntryRect`, `LoadFrameDrawRecord`, `GetFrameSize`, `GetEntryCount`, `FindResourceIndex`, and the `GetEntry` accessor. [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) owns only the two external no-this helpers `ResourceLayoutRawBufferLookupEntry` and `ResourceLayoutRawRecordGetEntryRect`. This split preserves the one-object binary model while retaining the source-useful helper unit already projected by the validator.

The constructor uses `List(44, 10)`: decimal 44 is the exact [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) row size, and decimal 10 is its initial capacity. The most plausible original declaration remains a generic `List *m_pEntryList`. [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md) and [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) are non-emitting historical/provisional analysis aliases, not evidence for a typed source wrapper or separate runtime class.

### Exact Core Function Inventory

| Range / UID | Source role | Liveness and evidence | Final owner / source disposition |
| --- | --- | --- | --- |
| `0x004cffb0-0x004d006f` | `ImageLib::ImageLib` | Startup caller; initializes vtable, `List(44,10)`, and singleton. | UID0000K2 CPP/H. |
| [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) | `ImageLib::~ImageLib` | Frees rows/list and clears singleton. | UID0000K2 CPP/H. |
| [UID:0002KO][0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex](by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md) | `LoadResourceIndex` | 13 code refs; DAT-backed layout registration. | UID0000K2 class/facet CPP/H. |
| [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md) | `LookupLayoutEntry` | 440 code refs; lazy load and context fill. | UID0000K2 class/facet CPP/H. |
| [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) | Raw buffer lookup | No-this helper; one caller. | UID0000N5 external CPP/H. |
| [UID:0002KR][0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext](by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md) | `CopyEntryTileContext` | 25 code refs; temporary load/copy. | UID0000K2 class/facet CPP/H. |
| [UID:0002KS][0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect](by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md) | `GetEntryRect` | 11 code refs; lazy bounds lookup. | UID0000K2 class/facet CPP/H. |
| [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) | Raw record bounds helper | No-this helper; 28 code refs. | UID0000N5 external CPP/H. |
| [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) | `LoadFrameDrawRecord` | 81 total xrefs; pure table projection through singleton receiver. | UID0000K2 body; ImageFrameTable H declarations. |
| [UID:0002KU][0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize](by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md) | `GetFrameSize` | One code ref. | UID0000K2 class/facet CPP/H. |
| [UID:0002KV][0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount](by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md) | `GetEntryCount` | Six code refs. | UID0000K2 class/facet CPP/H. |
| [UID:0002KW][0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex](by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md) | `FindResourceIndex` | 13 code refs. | UID0000K2 class/facet CPP/H. |
| `0x004d1830-0x004d1860` | `GetEntry` | Source accessor recovered out of line. | UID0000K2 H/source route. |
| `0x004e64a0-0x004e6572` | ImageLib scalar deleting destructor | Vtable-targeted compiler wrapper. | Compiler evidence only; no authored duplicate body. |

[UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) separately owns [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md), [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md), raw [UID:00031T][0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper](by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md), raw [UID:00031U][0x004d1710-0x004d172d.FrameRecordRectCopyHelper](by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md), and the shared H declarations on [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md). The raw starts remain source-bearing despite absent modeled functions/xrefs/pointer hits; their exact surrounding padding remains non-source.

[UID:0000J4][EPFTileContext](by-file/EPFTileContext.md) owns the complete 40-byte context and all thirteen bodies in `0x00457a60-0x00458610`: initialization; byte/word mask builders; copy/convert; retained raw `0x00457f30-0x00457fe9`; byte/word half-scale transforms; indexed, RGB16, and RGB16-alpha allocators; `ReleaseBuffers`; post-decode normalization; and the final bounds/range test. The raw and zero-direct-ref bodies remain source, not padding. UID0000J3 owns none of them.

### Asset, Render, Archive, And UI Owner Map

| Concrete owner | Preserved responsibility |
| --- | --- |
| [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) | Decoder wrappers and private codec glue. |
| [UID:0000MA][Palette](by-file/Palette.md) / [UID:0000MB][PaletteLib](by-file/PaletteLib.md) | Palette resources, slots, and native lookup tables. |
| [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) / [UID:0000OC][Surface](by-file/Surface.md) | Byte-mask and DirectDraw render primitives. |
| [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) | TILE metadata and map-tile frames. |
| [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) | TILEC/static-object metadata and drawing. |
| [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) | EFFECT metadata, frames, and rendering. |
| [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) | ITEM tables/drawing and `GetItemGlyphBounds`. |
| [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) / [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) | Legacy archive tables and composed-part human rendering. |
| [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) / [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) | Monster archives/rendering and shared monster/riding animation tables. |
| [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) / [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) | Mount and procedural-light assets. |
| [UID:0000JH][FontImageLib](by-file/FontImageLib.md) | BA0/BA1 glyph metrics and EPFTileContext decode. |
| [UID:0000IV][DIBitmap](by-file/DIBitmap.md) | PCX and Win32 DIB support, not EPF layout ownership. |
| [UID:0000IM][DATArchive](by-file/DATArchive.md) | DAT entry lookup and mapped-payload transport only. |
| [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md) | UI consumer of g_pEPFLib, not render/parser owner. |

`GetItemGlyphBounds` is conclusively a public nonvirtual `ItemObjImageLib` member. Current IDA at `0x004df460-0x004df4fa` has exact type `void __thiscall(ItemObjImageLib *this, __int16 itemId, RectBounds *outBounds)`. All 48 direct code callers provide the item singleton receiver and no caller consumes EAX. Free-helper, UI, DATArchive, and umbrella placement are rejected even though the body does not dereference `this`.

### Generated CPP/H Closure

The dated physical audit used validator command `000000025458`, refreshed `2026-08-17T11:48:37-04:00`. It found no `EPFImageResources.cpp` or `.h`, which is the correct result. Core hashes were: `EPFTileContext.cpp` `77F86EDEA55F48B7AD5D853AEF4DAF313E6840CA9E9D1E748EDD82653473625A`; `EPFTileContext.h` `687B6A04F5D84D028DEE54B044A1D5E16BD82E1321ADC7B856850F9C150121E0`; `ImageLib.cpp` `0BA87CB8B4CF2C80AC59ACFB708E11051007498C10CA5ECE280CBC5170F1F65E`; `ImageLib.h` `15CBD9DF7523A8E8A47F0DB32A85333C5366E09541000094490288FFF721EA67`; `ResourceLayoutTable.cpp` `41E2D58465C801BAF0B5BDD37399DC6617678C43476B562A205D9ED4FB0F7857`; `ResourceLayoutTable.h` `A5F5A3B9E3C1173B5FB8A90391D345711DF74A53446D4AC820DF9BCB3BAEFEA2`; `ImageFrameTable.cpp` `8C34EA51E7B92C7A5B6679E90B4D6A7ADFD4C310293E4E794460CFAE63474FD3`; `ImageFrameTable.h` `2876631F0547C96442406B3EDB0B1A54CFA68586BFDD264D7A2EF99E1B8F3D4E`; and `ImageLoaders.cpp` `1F120F409828EEB1032F99332D3668CEEB83545724AB55C98A4B6C355C1A840A`.

The remaining audited roots were DIBitmap, Palette/PaletteLib, FontImageLib, AlphaMaskSurface, Surface, MapTileImageLib, StaticObjImageLib, EffectObjImageLib, ItemObjImageLib, HumanImageLib, NewHumanImageLib, MonsterImageLib, MonsterImageLibTables, RidingImageLib, LightObjImageLib, EPFImageControlPane, DATFile, and DATFileMgr. Existing empty markers in EPFTileContext and ImageFrameTable are aggregate/type markers; Palette, Surface, StaticObjImageLib, ItemObjImageLib, NewHumanImageLib, and DATFile markers remain owner-local source/evidence backlog. None belongs in a new umbrella source file.

### Formal CPP/H Disposition

UID0000J3 must not emit formal CPP. It has no source-bearing definition, initializer, static import, or covered-by body. A comment-only `EPFImageResources.cpp` would be a reverse-engineering artifact and would duplicate concrete translation units.

UID0000J3 must not emit formal H. All required declarations are owned by ImageLib, ResourceLayoutTable, ImageFrameTable, EPFTileContext, and asset-specific headers. There is no caller/include evidence for an umbrella include header. Because by-file index pages do not carry child emitter payloads, the absent formal CPP/H metadata is the correct explicit blank-channel implementation.

### Historical Assumptions And Rejected Alternatives

- The earlier standalone ResourceLayout class/object possibility is retained as historical reasoning and rejected by the one lifecycle/global/vtable model.
- `ResourceLayoutStore` and `ResourceLayoutBucket` remain historical analysis aliases; a typed wrapper would replace evidence-backed generic List source with invented modern structure.
- Generated `EPFLibrary::LoadFrame` naming is a historical naming artifact for the ResourceLayout/ImageLib facet.
- DATArchive ownership is rejected because dependencies flow from render loaders to DAT entry/payload APIs, not the reverse.
- A monolithic `EPFImageResources.cpp`, owner-by-physical-neighborhood, and per-caller helper duplication are rejected because they conflict with exact callers and concrete source routes.
- Exact original `render/`, `image/`, or flat-root spelling cannot be proven. The established `NexusTK/render/` routes are the highest-probability current reconstruction and the residual lexical uncertainty is the confidence cap, not an ownership blocker.

## Historical Ownership Decision (Superseded)

The current one-function generated files are staging containers. `ImageLib` should be treated as the broader shared EPF image/cache manager behind `g_pEPFLib`; the `ResourceLayoutTable` method family should be reviewed as either part of `ImageLib` or a close helper/base class before final migration. The other shared table loaders should be grouped into a render/resource metadata module, while asset-specific classes should remain separate enough to preserve feature ownership. A compact original project might have used a broader `ImageLib.cpp`, but the number of asset families argues for multiple source files or a small `render/image/` subfolder.

[UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) now reinforces this as an umbrella/source-family page rather than a source-emitting file: it lists concrete render files such as `EPFTileContext.cpp`, `ImageFrameTable.cpp`, `ImageLib.cpp`, and `ResourceLayoutTable.cpp`, plus asset-specific image-library files, and it explicitly notes that EPF/image-frame helpers are render-resource code rather than archive parsing. Keep `PROPOSED_RECONSTRUCTION_PATH:"NONE"` unless the umbrella is later split into a real source page.

## Historical Open Questions (Resolved)

- Confirm whether the original filenames used `render/`, `image/`, or a flatter Visual C++ source layout.
- Confirm final class boundary between `ImageLib`, `ResourceLayoutTable`, the [UID:0000KS][List](by-file/List.md)-backed layout record registry, and the process-wide `g_pEPFLib` type model.
- Decide whether reconstructed source should expose a typed layout-list wrapper for readability or keep the original-looking generic `List*` field.
- Decide whether `GetItemGlyphBounds` should be placed directly in `ItemObjImageLib.cpp` or in a small item-image helper file. Current evidence says item-render helper, not UI pane and not DAT archive code.

Current resolutions supersede those assignment-time questions:

| Historical question | Resolved current model |
| --- | --- |
| `render/`, `image/`, or flatter layout | Use established flat `NexusTK/render/`; preserve exact historical spelling as a confidence-only caveat. |
| ImageLib / ResourceLayout / List boundary | One ImageLib object and nine class/facet operations; two no-this ResourceLayoutTable file helpers; generic `List *` with 44-byte rows. |
| Typed wrapper readability | Reject a synthetic wrapper; source fidelity favors the evidence-backed generic List API. |
| GetItemGlyphBounds placement | Public nonvirtual `ItemObjImageLib` member in ItemObjImageLib.cpp. |
| Umbrella route | Explicit non-reconstructable, non-emitting UID0000J3 index with path/owner `NONE` and no CPP/H. |

## Cross-References

- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:000176][0x004d0f50-0x004d165d.ImageFrameTable](by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000KS][List](by-file/List.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:00003Z][DLPalette](by-class/DLPalette.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)
- [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md)
- [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md)
- [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md)
- [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md)
- [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md)
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md)
- [UID:0001XQ][HumanImageLibVtable](by-type/by-vtable/HumanImageLibVtable.md)
- [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
- [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md)
- [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md)
- [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000S4][g_pRidingImageLib](by-global/g_pRidingImageLib.md)
- [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md)
- [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md)
- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md)
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000UH][DrawEncodedAlphaFrame_00462F20](by-item/DrawEncodedAlphaFrame_00462F20.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md)
- [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md)
- [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md)
- [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md)
- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md)
- [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-17 B008 UID0000J3 whole-family implementation callback:
  - Changed metadata from `89/86` with blank reconstructability to `96/94`, `RECONSTRUCTABLE:FALSE`, path `NONE`, owner `NONE`, and no emitter/formal source route.
  - Resolved the ImageLib/ResourceLayout object and source split, generic List source shape, GetItemGlyphBounds member placement, DATArchive dependency boundary, source-tree placement, and umbrella no-code/no-header disposition.
  - Added exhaustive core function, raw-helper, lifecycle/compiler, asset/render/archive/UI owner, generated CPP/H, historical assumption, negative-evidence, and resolved-question inventories without pruning the earlier source-family research.
  - Preserved the exact supervisor-owned manual coverage replacement and IDA no-change verification outside this ordinary document callback.

- 2026-06-14 C001 live IDA/source-family confidence refresh:
  - What existed before: `COMPLETION:88`, `CONFIDENCE:82`; the page correctly described a non-emitting EPF/render umbrella but lacked a current session-backed tie between the singleton lifetime, ResourceLayout API edges, and frame-table boundaries.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:86`; `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE` remain unchanged because this is still an umbrella/source-family page, not a generated source root.
  - Summary/evidence: live IDA MCP reconfirmed `g_pEPFLib` storage at `0x0067a744`, ImageLib lifecycle refs and vtable refs, ResourceLayout public API starts/internal lazy-load edges, frame-table/raw-helper boundaries, and converted key constants with `int_convert.py`. Exact original filenames and the final ImageLib-vs-ResourceLayout class/facet boundary remain open, so no C++ was added.
- 2026-06-07 A008 alias cleanup:
  - Before: the resource-layout registry note used bare `DAT_0067a744` wording for the `g_pEPFLib` singleton.
  - Changed to: canonical [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) wording with `DAT_0067a744` retained as the historical IDA alias.
  - Evidence: the section already records `ImageLib::ImageLib` ownership and `ResourceLayoutTable` consumer/facet behavior.
- 2026-06-07 A003 umbrella/source-tree confidence refresh:
  - What existed before: confidence was `78`, with the page correctly marked as a non-emitting render-resource umbrella but still described as only medium-to-strong for source-family ownership.
  - Changed to: confidence `82`, with explicit source-tree cross-check showing that concrete render files now own the child implementations while this page stays `PROPOSED_RECONSTRUCTION_PATH:"NONE"`.
  - Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) lists the concrete render owners for `EPFTileContext`, `ImageFrameTable`, `ImageLib`, `ResourceLayoutTable`, and asset image libraries; the page already documents shared table format, registry/palette relationship, consumer classes, and archive-boundary separation. Completion stays `88` because exact original filenames and some class/helper boundaries remain open.

- 2026-06-05: Marked the projected reconstruction path as `NONE`.
  - Before: the blank path made this umbrella/source-family page look like a missing generated source root.
  - After: the page remains a render-resource ownership map; concrete source roots stay with pages such as [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md), [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), [UID:0000K2][ImageLib](by-file/ImageLib.md), and asset-specific image-library files.
  - Evidence: live IDA MCP `lookup_funcs` confirms representative shared loaders/helpers at `0x004d0f50`, `0x004d1b80`, and `0x004de420`; these are already assigned to concrete render/image docs, so `EPFImageResources.md` should not emit `EPFImageResources.cpp`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:78`.
  - Summary/evidence: EPF/EPD source-family split, shared table format, resource layout registry, palette relationship, shared helpers, consumer classes, ownership decision, open questions, and extensive cross-references are documented; confidence is capped because it remains an umbrella/source-family hypothesis with several exact original filenames unresolved.
