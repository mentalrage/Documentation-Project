*** UID:0001QC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client DAT And Resource Specifications

## Status

- Confidence: medium for archive ownership, public APIs, mapped entry-table layout, and consumer/source split; weak for exact original on-disk field names and sentinel-row semantics.
- Scope: DAT archives, DAT-backed resource lookup, PCX/DIB loading, EPF/EPD image metadata, palette/image-library ownership, DAT-backed audio resource use, and adjacent loose resource/cache formats that must not be confused with packed DAT archives.
- Primary source modules: [UID:0000IN][DATFile](by-file/DATFile.md), [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), and [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md), with [UID:0000IM][DATArchive](by-file/DATArchive.md) as the umbrella resource note
- Core class docs: [UID:00003G][DATFile](by-class/DATFile.md), [UID:00003I][DATFileMgr](by-class/DATFileMgr.md), [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- Core address docs: [UID:00012D][0x0049c130-0x0049d2cb.DATFile](by-memory/0x0049c130-0x0049d2cb.DATFile.md), [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md), [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md), [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md), exact [UID:00003K][DATIndexVector](by-class/DATIndexVector.md), and the DATIndexVector [UID:0000XT][0x00457310-0x004573b2.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b2.DATIndexVectorRemoveNodeHelper.md)

## Observed Archive Model

The client has a compact DAT resource layer rather than direct filesystem loading everywhere. `DATFile` is the per-entry reader. `DATFileMgr` is the public singleton-style wrapper, while `_DATFileMgr` is the internal manager that builds and queries the archive name index. `DATFileContainer` owns the mapped archive backing store.

Observed layout and behavior:

- `DATFile` is a 20-byte object: embedded `File` object at `0x0`, entry pointer at `0x8`, read position at `0xc`, and entry size at `0x10`.
- DAT entry records are 0x11-byte records: 4-byte payload start offset followed by a 13-byte ANSI name. The end offset is read from the next record's 4-byte payload start offset, not from a second field inside the same record.
- `DATFileContainer::DATFileContainer` caches the first dword of the final 17-byte row at container offset `0x10`. Because `_DATFileMgr::LoadDATFileIndex` skips empty names, the current best interpretation is that the final row is a sentinel/final-payload-offset row.
- `DATFile::Open` resolves an entry name through `_DATFileMgr::FindEntryByName`; `DATFile::OpenByIndex` opens by archive/index location.
- [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) is the public wrapper that forwards archive-file loading/indexing to `_DATFileMgr::LoadDATFileIndex`.
- `DATFile::Read`, `Seek`, `Tell`, `GetSize`, `ReadLine`, `ReadAllEntries`, and `ReadAllLines` expose normal file-like reads over the entry payload.
- [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md) decodes an eight-byte DAT entry header using a shared 27-step seed table and is called only by `DATFile::ReadAllEntries` and `DATFile::ReadAllEntriesAlt`; the 2026-05-25 IDA MCP recheck resolves it as `archive/DATFile.cpp` private/static-style support.
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) constructs a `DATFile`, opens a DAT-backed path, gets its size, allocates a buffer with optional zeroed prefix bytes, reads the entry, and closes the file.

IDA MCP caller/callee checks support this model: [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) calls `DATFile` constructor, `Open`, `GetSize`, `Read`, `Close`, and destructor; `_DATFileMgr::LoadDATFileIndex` calls `DATFileContainer`, index insertion helpers, and name lookup helpers; [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) is a tiny public wrapper over that internal loader; [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) has callers across PCX/image frame/tile/effect/sprite/audio loaders. Follow-up checks on 2026-05-24 show `DATIndexVector` is a standalone helper used by DAT-manager, minimap, fitting-room, and monster-image state. A 2026-05-25 check shows [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md) is application startup policy over numbered DAT archive families, not DAT parser ownership.

2026-05-27 documentation audit: the core DAT archive surface now has exact file, class, memory, item, global, resource, and startup-archive cross-references. The remaining weak portion is not the archive ownership model; it is the exact original naming/semantics of the physical header, final sentinel row, and table-field declarations.

## Core Classes And Helpers

| Entity | Address/range | Role |
| --- | --- | --- |
| `DATFile` | `0x0049c130-0x0049d2cb` | Per-entry reader with file-like read/seek/line helpers. |
| `DATFileMgr` | `0x0049bd30-0x0049d38b` | Thin public wrapper; singleton [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) at `0x0067ab40`; fatal-load cleanup helper [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md) at `0x00467380`. |
| [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) | `0x0049be70-0x0049be7c` | Public wrapper forwarding to `_DATFileMgr::LoadDATFileIndex`. |
| `_DATFileMgr` | `0x0049c800-0x0049d6ed` | Internal archive index builder and name lookup engine. |
| `DATFileContainer` | `0x0049be80-0x0049d349` | Mapped archive container and Win32 file mapping lifecycle owner. |
| `DATFileResolver` | `0x0049d190-0x0049d26c` | Small resolver/destruction helper; exact relationship still open. |
| [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) | discontiguous; see class page | FNV-1a keyed index/list and value-table helper used by archive, minimap, fitting-room, and monster-image state. |
| [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md) | `0x0049c700-0x0049c71d` | Boolean entry-existence probe through global DAT manager. |
| [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md) | `0x00467410-0x004674ed` | `Application::Initialize` helper for numbered DAT archive families. |
| [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md) | `0x004a5e60-0x004a609f` | Decodes/validates DAT entry headers for bulk entry readers. |
| [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) | `0x004bb120-0x004bb1d2` | Loads a DAT-backed file into memory, optionally with a zeroed prefix. |

## Resource Format Areas

### DAT Archives

Current evidence supports a mapped archive with an internal entry table and a separate name index. `DATFileContainer` maps the backing archive, and `_DATFileMgr::LoadDATFileIndex` creates name-index nodes for entries exposed by that archive. The exact physical file header is not fully documented yet.

Observed mapped layout:

```text
DAT mapped view
  +0x00  uint32 entryCount
  +0x04  DATEntryRecord records[entryCount]

DATEntryRecord
  +0x00  uint32 startOffset
  +0x04  char name[13]
```

Observed `DATFileContainer` layout:

```text
DATFileContainer
  +0x00  vftable
  +0x04  file handle
  +0x08  file mapping handle
  +0x0c  mapped view base / archive data base
  +0x10  last entry offset
  +0x14  entry count
  +0x18  entry table pointer
```

`_DATFileMgr::LoadDATFileIndex` reads names from `entryTable + entryIndex * 17 + 4`, converts each ANSI name to uppercase wide text, skips empty names, and inserts unique names into an internal hash/list index.

`DATFileContainer::DATFileContainer` computes `last entry offset` from `*(uint32*)(entryTable + (entryCount - 1) * 17)`. This is strong evidence that the final row supplies the archive's last payload boundary, probably as an empty-name sentinel row.

`Application::Initialize` loads fixed DAT archives directly through [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md), and loads numbered DAT archive families through [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md). That startup helper probes loose `*.DAT` files to decide where each numbered family ends, then uses the same manager wrapper to index existing archives. The full fixed and looped startup inventory is tracked in [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md).

### Localized String Resource

[UID:0000KK][LanguageMan](by-file/LanguageMan.md) uses `DATFile` to open `str.res`, then treats it as a line-oriented byte stream of localized strings.

Observed `str.res` behavior:

- maximum of 1024 string records;
- maximum of 1024 bytes per input line;
- CR/LF line handling, with CR causing an extra one-byte seek;
- byte `0x11` rewritten to CR before conversion;
- conversion through `MultiByteToWideChar(0, 0, ...)`;
- string ids are zero-based indexes into the loaded table.

See [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md), [UID:000071][LanguageMan](by-class/LanguageMan.md), and [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md).

### Meta.dat Metadata Cache

[UID:0000LC][MetaMan](by-file/MetaMan.md) owns a separate loose metadata cache file named `Meta.dat`. This is not a packed DAT archive and should not be merged into [UID:0000IN][DATFile](by-file/DATFile.md) ownership.

Observed behavior:

- `MetaMan::LoadMetaDatAndRequestSync` loads local `Meta.dat`, then sends opcode `123`, subtype `1` to synchronize with the server.
- `MetaMan::LoadMetaDat` opens loose `Meta.dat`, reads a table-count/header area, constructs [UID:000089][MetaTable](by-class/MetaTable.md) objects, and stores compressed table payloads.
- `MetaMan::HandleMetaPacket` receives server table/checksum lists and individual table payloads, validating each payload through `MetaTable::DecompressAndValidateData`.
- `MetaTable::DecompressAndValidateData` consumes bundled [UID:0000PC][Zlib](by-file/Zlib.md) support: `Uncompress` inflates the payload and `Crc32` validates the decoded bytes.
- [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) parses the post-zlib [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md): a 16-bit row count, one-byte row-key lengths, 16-bit value counts, and 16-bit length-prefixed multibyte values converted with `MultiByteToWideChar(0, 0, ...)`.
- A private helper at `0x005237d0` writes dirty metadata state back to `Meta.dat` after synchronization completes.
- Public lookup APIs such as `MetaMan::FindEntry` and `MetaMan::LoadStatValues` are consumed by [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md), [UID:00002X][CollectionPane](by-class/CollectionPane.md), and resource helper code.

See [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md), [UID:000088][MetaMan](by-class/MetaMan.md), [UID:000089][MetaTable](by-class/MetaTable.md), [UID:0000PC][Zlib](by-file/Zlib.md), [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md), and [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md).

### PCX And DIB

PCX loading is DAT-aware. `LoadPcxImage` calls [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) and uses the shared file-buffer path before building a `DIBitmap`. `DIBitmap` is a 96-byte device-independent bitmap wrapper around a `BITMAPINFOHEADER`, an `HBITMAP`, a pixel pointer, dimensions, and scanline-alignment state. The concrete file docs now split this as [UID:0000IV][DIBitmap](by-file/DIBitmap.md) for the wrapper and [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) for the PCX free-helper pipeline.

The tight `0x004a1600-0x004a1b5d` memory cluster places `LoadPcxImage` and `CreateDIBitmapFromPcxBuffer` between the `DIBitmap` constructor and destructor. `DecodePcxToRgb565Buffer` links farther away at `0x00549410`, so the current source-tree hypothesis keeps the DIB wrapper and startup PCX helper together while leaving the final codec-file split open.

Important helpers:

- `DIBitmap` / local PCX cluster `0x004a1600-0x004a1b5e`; see [UID:0000IV][DIBitmap](by-file/DIBitmap.md) and [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- `LoadPcxImage` `0x004a17b0-0x004a18a8`; see [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md)
- `CreateDIBitmapFromPcxBuffer` `0x004a18b0-0x004a1b0c`; see [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)
- `DecodePcxToRgb565Buffer` `0x00549410-0x00549616`; see [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md)

### EPF, EPD, Sprites, Tiles, And Effects

EPF/EPD image work appears to sit between archive and rendering. `EPFTileContext` owns decoded EPF/EPD pixel buffers, bounds metadata, and optional cached run-length masks. Archive-entry probes are used by tile, effect, item, and sprite-part loaders.

2026-05-22 follow-up confirms a shared EPF/EPD metadata-table pattern above the DAT layer:

- Table helpers call [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), `DATFile`, and `DATFile::GetDataPointer`, but they own EPF/EPD bounds and payload-offset records rather than raw DAT parsing.
- `ImageLib` is the singleton constructed into [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `DAT_0067a744`; the EPF/EPD layout lookup methods are currently recovered as `ResourceLayoutTable`. Together they lazy-load named EPF/EPD resources, store registered layout buckets, and return `EPFTileContext` or bounds data to UI/render callers. 2026-05-24 IDA xrefs confirmed the global owner writes are in `ImageLib` construction/destruction, while `ResourceLayoutTable` callers consume the same object. 2026-05-26 follow-up pins the central [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md), [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md), and omitted ordinary destructor at [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md).
- `LoadImageFrameTable_4D0F50` loads a single EPF/EPD frame table or merges numbered human/equipment shards such as `HEAD%d.EPF`, `BODY%d.EPF`, `SWORD%d.EPF`, `FACE%d.EPF`, and `HAIR%d.EPF`.
- `LoadTileEpfMetadata`, `BuildTilecArchiveTable`, `BuildEffectArchiveTable`, and `ResolveSpritePartPath` all build `ArchiveMetadataTable`-style records with bounds and absolute payload offsets plus a terminal sentinel.
- `MapTileImageLib`, `StaticObjImageLib`, and `EffectObjImageLib` are now documented as distinct render image-library owners. Their owned one-caller helpers scan `TILE%d.EPF`, `TILEC%d.EPF`, and `EFFECT%d.EPF` respectively.
- `ItemObjImageLib` owns item table metadata and shared item draw paths over `ITEM.EPF`/`ITEM.EPD`; `GetItemGlyphBounds` is a shared item-icon bounds helper with broad item UI fan-in.
- `HumanImageLib` owns the old human/equipment frame-table family and repeatedly calls `LoadImageFrameTable_4D0F50` for prefixes such as `HEAD`, `HEADSP`, `BODY`, `SWORD`, `SPEAR`, `BOW`, `FAN`, `SHIELD`, `ARROW`, `FACE`, `HAIR`, `ACE1`, `ACE2`, `HELMET`, `MANTLE`, `NECLACE`, `SHOES`, and `COAT`. IDA confirms [UID:0000R5][g_pHumanImageLib](by-global/g_pHumanImageLib.md) at `0x0069b43c`, [UID:0001UR][HumanImageLibLayout](by-type/by-struct/HumanImageLibLayout.md), vtable `0x0061b6d4`, and ordinary destructor `0x004d4ad0`.
- `NewHumanImageLib` owns the newer table-driven human composition model around `Motion.tbl`, `Layer.tbl`, `Part.tbl`, per-part descriptor tables, `acc2drw.tbl`, `HAIRCOL.TBL`, and `ResolveSpritePartPath`. IDA confirms [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) at `0x0067a760`, [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md), vtable `0x0061b76c`, ordinary destructor `0x004e0250`, and singleton clear helper `0x004e5be0`.
- `Motion.tbl` vector helpers [UID:0000TO][VectorGrowMotion](by-global/VectorGrowMotion.md) and [UID:0000PK][DestroyMotionVector](by-global/DestroyMotionVector.md) belong to `NewHumanImageLib`; they should not be confused with the runtime/dirty-rectangle [UID:00008R][Motion](by-class/Motion.md) helper family.
- `MonsterImageLib` owns `MONSTER.DNA`/`MONSTER.DND` parsing, `DATA/MON%d.DAT` archive indexing, render/projection paths, and lazy monster archive bounds buckets. IDA confirms [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md) at `0x0069b440`, [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md), vtable `0x0061b6e4`, ordinary destructor `0x004db010`, and disabled-but-real `GetArchiveBoundsBucket` at `0x004dbe60`.
- `RidingImageLib` owns `RIDINGS.DNA` parsing and loads `RIDINGS.EPF` through the shared frame-table loader. The DNA parser fills `0x0c`-byte [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md) rows plus nested 8-byte bucket rows and 10-byte bucket-entry rows, and seeds [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md) with 21 default groups spanning `0..30000`.
- `LightObjImageLib` reads `LIGHT.TBL` through the DAT path and builds procedural radial light frames; it belongs with render/image ownership, but is not itself an EPF frame-table loader.
- `FontImageLib` reads `BA0`/`BA1` font archives through `DATFile`, owns the glyph table and scratch decode buffer, and returns glyph metrics or `EPFTileContext` output for text rendering.
- `AlphaMaskSurface` and the mask blitters are shared render primitives. They consume image-library frame/mask data but own byte alpha-mask buffers, gradients, and replace/add/subtract transfer modes.
- `IntAlphaSurface` is a provisional neighboring render-surface type. Only its destructor and vtable are recovered, so it should remain near `AlphaMaskSurface` or `Surface` until the constructor/source boundary is proved.
- `Surface` is the provisional bucket for generic paint lifecycle, surface metadata, scroll-buffer, presentation, and DirectDraw blit helpers that currently have caller-biased owners.
- The helper classes `MonsterImageLibTable_5289D0` and `MonsterImageLibTable_528BE0` are shared by monster and riding table parsers, so their current monster-biased names should be treated as provisional.
- Consumer ownership points toward render/image modules: `MapTileImageLib`, `StaticObjImageLib`, `EffectObjImageLib`, `ItemObjImageLib`, `HumanImageLib`, `NewHumanImageLib`, `MonsterImageLib`, `RidingImageLib`, `LightObjImageLib`, and UI/effect panes.

Important helpers and classes:

- `EPFTileContext` `0x00457a60-0x00458557`
- `ImageLib` `0x004cffb0-0x004e6571`
- `ResourceLayoutTable` `0x004d0120-0x004d182e`
- `LoadImageFrameTable` `0x004d0f50-0x004d15c5`
- `LoadFrameDrawRecord` `0x004d1600-0x004d165d`
- `LoadTileEpfMetadata` `0x004d1b80-0x004d1f21`
- `BuildTilecArchiveTable` `0x004dda60-0x004dde01`
- `BuildEffectArchiveTable` `0x004de420-0x004de7c1`
- `ItemObjImageLib` `0x004dec30-0x004e65db`
- `GetItemGlyphBounds` `0x004df460-0x004df4f8`
- `HumanImageLib` `0x004d2720-0x004e649a`
- `NewHumanImageLib` `0x004dfd10-0x004e68a7`
- `RidingImageLib` `0x004dc420-0x004e6980`
- `MonsterImageLib` `0x004dac40-0x004e685f`
- `Monster/riding table helpers` `0x00528930-0x00528d51`
- `LightObjImageLib` `0x004df7e0-0x004e669c`
- `FontImageLib` `0x004b5f00-0x004b6409`
- `AlphaMaskSurface` `0x00462170-0x00462e02`
- `DrawFrameWithBlendMode` `0x00462e10-0x00462f1d`
- `DrawEncodedAlphaFrame` provisional `0x00462f20-0x00463251`
- `IntAlphaSurface` provisional `0x00463270-0x004632b1`
- `Surface paint helpers` provisional `0x004b9820-0x004ba24a`
- `Surface presentation helpers` provisional `0x00557140-0x00559aef`
- `ResolveSpritePartPath` `0x004e19d0-0x004e1f26`
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)

See [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md), [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md), [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md), [UID:0000OC][Surface](by-file/Surface.md), [UID:00006E][ImageLib](by-class/ImageLib.md), [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md), [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md), [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md), and [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md).

### Palettes

`PaletteLib` / `g_pPaletteLib` is the render-side palette manager, while `DLPalette` is the palette data object used for native 16-bit color lookup tables. Palette files are commonly DAT-backed and loaded through `DATFile`, but palette policy belongs with render/image code rather than raw archive parsing.

Observed palette bootstrap:

- `Application::Startup` constructs `PaletteLib` once through the call at `0x004f61bb`.
- `PaletteLib::PaletteLib` loads `baram.pal`, all 25 category palette files, and optional `SUPER0.PAL` through `SUPER6.PAL`.
- `PaletteLib::LoadPaletteSet` parses a category palette file into source `DLPalette` objects and clones them into runtime palettes.
- `PaletteLib::GetSlotPalette` selects source/runtime slot palettes by asset-family slot and palette index, or selects a super palette when `superPaletteIndex` is nonzero.
- `DLPalette::LoadFromStream` reads a 0x20-byte header, optional two-byte entries, and 0x400 bytes of RGBX color data, then builds a 256-entry 16-bit lookup table.
- `ScreenPanePaletteState_543D30` is an adjacent screen-level helper with two 25-entry palette banks; it should be reviewed with palette/render code even if final ownership lands in `ScreenPane.cpp`.

See [UID:0000MA][Palette](by-file/Palette.md), [UID:0000MB][PaletteLib](by-file/PaletteLib.md), [UID:0000A1][PaletteLib](by-class/PaletteLib.md), [UID:00003Z][DLPalette](by-class/DLPalette.md), [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md), and [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md).

### Audio And WAV

Audio resource selection is DAT-backed in the core game path and belongs to `SoundManager`, not to the archive module.

Confirmed behaviors:

- `SoundManager::SoundManager` at `0x00579a30` scans `%03d.wav` for IDs `0..999`, checks each name through [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), opens matching entries with `DATFile`, and caches `DATFile::GetDataPointer()` for sound-effect playback.
- `SoundManager::PlayMusicByZone` at `0x0057a0b0` checks `%08d.LST`, `%08d.LSR`, and `%08d.MP3` through [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md).
- `SoundManager::LoadTrackListFromFile` at `0x005797b0` opens `.LST`/`.LSR` entries through `DATFile`, reads a line-based track list, and formats each track ID as `%08d.MP3`.
- A separate local music-directory mode exists through `FindFirstFileA` and `g_strMusicExtension`, so DAT-backed zone music and loose user music are separate paths in the same audio manager.
- MIDI playback is a separate WinMM path owned by [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md); it uses [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md) and stream/buffer globals rather than DAT resource lookup.

See [UID:0000UB][DATAudioResources](by-item/DATAudioResources.md), [UID:0000DG][SoundManager](by-class/SoundManager.md), [UID:0000NV][SoundManager](by-file/SoundManager.md), and [UID:0001Q8][client_audio](by-meta/client_audio.md).

## Source-Structure Implications

The likely original source split is:

```text
archive/DATFile.h
archive/DATFile.cpp
archive/DATFileMgr.h
archive/DATFileMgr.cpp
archive/DATIndexVector.cpp
app/Application.cpp        # LoadIndexedDATSeries startup helper only
localization/LanguageMan.cpp
metadata/MetaMan.cpp
audio/SoundManager.cpp
audio/MidiPlayer.cpp
render/ImageLoaders.cpp
render/DIBitmap.cpp
render/EPF.cpp
render/ImageLib.cpp
render/ResourceLayoutTable.cpp
render/ImageFrameTable.cpp
render/EPFTileContext.cpp
render/Palette.cpp
render/FontImageLib.cpp
render/AlphaMaskSurface.cpp
render/IntAlphaSurface.cpp
render/Surface.cpp
ui/controls/EPFImageControlPane.cpp
```

The DAT classes should be grouped before the EPF/image helpers are migrated. `DATIndexVector` should remain standalone rather than being merged into `DATFileMgr.cpp`; its final folder may be `archive/` or a common helper folder, but its imported source name and DAT-manager callers currently justify `archive/DATIndexVector.cpp` as the working source-tree node. The archive layer is a dependency of rendering/resource loaders, but `ImageLib`, `ResourceLayoutTable`, `EPFTileContext`, `DIBitmap`, `FontImageLib`, `AlphaMaskSurface`, provisional `IntAlphaSurface`, `Surface`, `PaletteLib`, `DLPalette`, and EPF/EPD frame-table helpers should not be merged into the same source file as DAT parsing.

The DATIndexVector helper at `0x00457310` is real code, but the only IDA-observed call is from `InsertNode`'s EH/unwind cleanup block. Treat it as `DATIndexVector.cpp` internal cleanup support until a reviewed generated-ownership pass decides whether to expose it as `RemoveNode` or keep it file-local.

The same applies to audio: `SoundManager` should keep sound/music policy in `audio/SoundManager.cpp` while depending on `DATFile` and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) for archive-backed resources.

Localization is another DAT consumer. `LanguageMan.cpp` should depend on `archive/DATFile.cpp` for `str.res` access, but own string-id lookup policy and the `g_pLanguageMan` singleton.

Application startup is a DAT consumer too. [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md) belongs with `app/Application.cpp`, while [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) remains `archive/DATFileMgr.cpp`.

`metadata/MetaMan.cpp` is adjacent resource/cache ownership, but it is not a DAT archive consumer in the same sense. It owns loose `Meta.dat` cache load/save, metadata packet sync, [UID:000088][MetaMan](by-class/MetaMan.md), [UID:000089][MetaTable](by-class/MetaTable.md), [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md), and [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md).

## Open Questions

- Exact DAT physical header layout beyond the observed mapped `entryCount` and 17-byte record table, and whether entry names are ever encoded/compressed.
- Whether the final entry-table row is always an empty-name sentinel or can sometimes be a named entry.
- Exact `Meta.dat` header record layout and per-table decoded value semantics. The structural decoded payload format now has [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md), but table-specific columns remain unnamed.
- Final names and field types for `DATFileContainer` offsets `0x4` through `0x18`.
- Final names and field types for `_DATFileMgr` index/tree/list fields.
- Whether `DATIndexVector`'s final folder is `archive/` or a common/helper folder; current evidence rules out making it private to `DATFileMgr.cpp`.
- Final class boundary and field names for `ImageLib`, `ResourceLayoutTable`, the [UID:000079][List](by-class/List.md)-backed [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) registry, and the [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) type model.
- Exact WAV payload handoff into Miles AIL and whether DAT-backed MP3 streaming maps directly from the DAT payload or copies into another buffer/file abstraction.
- Whether `str.res` is language-specific per distribution and whether byte `0x11` is consistently an authoring-time line-break escape.

## Next Research Targets

1. Deep-review `SoundManager::LoadTrackListFromFile`, the WAV sample creation path, and the MP3 stream open path to document exact audio payload ownership.
2. Confirm whether the final DAT table row is always an empty-name sentinel across multiple archives.
3. Continue per-asset image-library refinement now that the `ResourceLayoutStore` constructor/vtable question resolves to generic `List::List(44, 10)`.
4. Decide final Wave3 dry-run ownership moves for [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md), [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md), and standalone `DATIndexVector.cpp` source placement. [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md) is already resolved as `archive/DATFile.cpp` private/static-style support.

## Cross-References

- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)
- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)
- [UID:0000UB][DATAudioResources](by-item/DATAudioResources.md)
- [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md)
- [UID:0001I8][0x005797b0-0x0057bc58.SoundManager](by-memory/0x005797b0-0x0057bc58.SoundManager.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md)
- [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:00003Z][DLPalette](by-class/DLPalette.md)
- [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:000079][List](by-class/List.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)
- [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md)
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000UH][DrawEncodedAlphaFrame_00462F20](by-item/DrawEncodedAlphaFrame_00462F20.md)
- [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md)
- [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- [UID:0000V5][ParseEntries_004A5E60](by-item/ParseEntries_004A5E60.md)
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md)
- [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- [UID:0000UW][LoadDatFileBuffer_004BB120](by-item/LoadDatFileBuffer_004BB120.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)
- [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md)
- [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md)
- [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md)
- [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md)
- [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md)
- [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md)
- [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md)
- [UID:0000XS][0x00457100-0x0045730e.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730e.DATIndexVectorInsertNode.md)
- [UID:0000XT][0x00457310-0x004573b2.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b2.DATIndexVectorRemoveNodeHelper.md)
- [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md)
- [UID:0001QJ][client_old_redering_mode](by-meta/client_old_redering_mode.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
