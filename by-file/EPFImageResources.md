*** UID:0000J3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# EPF Image Resources

## Status

- Confidence: medium to strong for source-family ownership, medium for exact original filenames.
- Proposed modules: `render/EPFTileContext.cpp`, `render/ImageLib.cpp`, `render/ResourceLayoutTable.cpp`, `render/ImageFrameTable.cpp`, render support files, and per-asset image-library files.
- Evidence basis: `simroot_v2` generated source, Wave3 class/global summaries, Wave3 xrefs, and IDA MCP callee checks on 2026-05-22.

## Hypothesis

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

2026-05-22 follow-up resolves the earlier registry question but refines the class boundary: [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `DAT_0067a744` is initialized by `ImageLib::ImageLib`, while the EPF/EPD layout lookup methods are currently recovered as `ResourceLayoutTable`. This belongs with render/resource code, while UI controls and per-asset image-library classes consume it. 2026-05-24 IDA MCP xrefs confirmed the global owner writes are in the `ImageLib` constructor/destructor family, and the broad `g_pEPFLib` xref set is mostly consumer reads.

`ResourceLayoutTable::LoadResourceIndex` opens a named EPF/EPD entry through `DATFile`, reads the frame table, normalizes offsets with `DATFile::GetDataBase() + 0xc`, appends a sentinel, and appends the result to a [UID:0000KS][List](by-file/List.md)-backed resource-name record table. `ResourceLayoutTable::LookupLayoutEntry` then fills an `EPFTileContext` for callers. Wave3 xrefs show broad use across UI panes, image libraries, item/effect helpers, and `EPFImageControlPane`.

The generated `EPFLibrary::LoadFrame` references in some files should be treated as naming artifacts until proven otherwise; their call target is `ResourceLayoutTable::LookupLayoutEntry`. The original class may have exposed these methods directly from `ImageLib`, or through a base/helper slice now recovered as `ResourceLayoutTable`. The supporting store model is a [UID:0000KS][List](by-file/List.md) of 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) rows; [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md) and [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) are retained as provisional aliases for older generated overlays.

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
| `GetItemGlyphBounds` | [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) or a neighboring item-image helper | Resolves and recenters item icon bounds from `ITEM.EPF` or `ITEM.EPD`. See [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md). |
| `DrawFrameWithBlendMode` | `DrawFrameWithBlendMode_00462E10.cpp` | Copies/adds/subtracts byte frame masks into `AlphaMaskSurface`; used by light draw modes. See [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md). |
| `DrawEncodedAlphaFrame` provisional | currently not emitted as a recovered source | Draws signed-run encoded frame rows into an alpha mask with a vertical alpha ramp; used by several image-library callers. See [UID:0000UH][DrawEncodedAlphaFrame_00462F20](by-item/DrawEncodedAlphaFrame_00462F20.md). |

IDA/Wave3 xrefs show the EPF/EPD table-loading helpers call [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), `DATFile`, `DATFile::GetDataPointer`, and allocation/rect helpers. They should depend on the DAT archive API but should not be owned by the DAT module. The alpha-mask blitters in the same table are lower-level render helpers rather than DAT consumers.

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

## Ownership Decision

The current one-function Wave3 files are staging containers. `ImageLib` should be treated as the broader shared EPF image/cache manager behind `g_pEPFLib`; the `ResourceLayoutTable` method family should be reviewed as either part of `ImageLib` or a close helper/base class before final migration. The other shared table loaders should be grouped into a render/resource metadata module, while asset-specific classes should remain separate enough to preserve feature ownership. A compact original project might have used a broader `ImageLib.cpp`, but the number of asset families argues for multiple source files or a small `render/image/` subfolder.

## Open Questions

- Confirm whether the original filenames used `render/`, `image/`, or a flatter Visual C++ source layout.
- Confirm final class boundary between `ImageLib`, `ResourceLayoutTable`, the [UID:0000KS][List](by-file/List.md)-backed layout record registry, and the process-wide `g_pEPFLib` type model.
- Decide whether reconstructed source should expose a typed layout-list wrapper for readability or keep the original-looking generic `List*` field.
- Decide whether `GetItemGlyphBounds` should be placed directly in `ItemObjImageLib.cpp` or in a small item-image helper file. Current evidence says item-render helper, not UI pane and not DAT archive code.

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
- [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md)
- [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:78`.
  - Summary/evidence: EPF/EPD source-family split, shared table format, resource layout registry, palette relationship, shared helpers, consumer classes, ownership decision, open questions, and extensive cross-references are documented; confidence is capped because it remains an umbrella/source-family hypothesis with several exact original filenames unresolved.
