*** UID:0000IM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:98 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# DATArchive

## Current Disposition

`DATArchive` is a non-emitting documentation index, not an original compilation unit. Exhaustive binary, RTTI, type, xref, generated-output, and source-route review found no `DATArchive` function, class, global, vtable, RTTI record, import, export, resource, source symbol, or generated artifact. The concrete archive implementation is exactly two authored units: [UID:0000IN][DATFile](by-file/DATFile.md) for the per-entry reader and [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) for the public/private manager, mapped containers, singleton, and typed standard-container state.

[UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) and its exact bodies are old-MSVC/Dinkumware `stdext::hash_map`/list/vector lowering shared by multiple typed consumers, not a third authored archive source file. [UID:00003J][DATFileResolver](by-class/DATFileResolver.md) and the manager-local node/hash helpers are likewise semantic/compiler overlays generated from `_DATFileMgr`'s typed map member. No `DATArchive.cpp`, `DATArchive.h`, `DATIndexVector.cpp`, or `DATIndexVector.h` should be generated.

The mapped directory record is exactly 17 bytes: a four-byte payload start offset at `+0x00` and a 13-byte ANSI name at `+0x04`. Payload length is the next row's start offset minus the current row's start offset. A read-only 250-file package audit found monotonic in-bounds offsets and no zero-length intervals; three final boundary rows contain nonzero unused name bytes, so the final row is a boundary row rather than an always-empty sentinel.

Render, image, palette, audio, and application code are consumers. In particular [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), its storage [UID:0001OQ][0x0067a744-0x0067a748.g_pEPFLib](by-memory/0x0067a744-0x0067a748.g_pEPFLib.md), [UID:0000K2][ImageLib](by-file/ImageLib.md), and [UID:00006E][ImageLib](by-class/ImageLib.md) remain the ImageLib-owned declaration/storage/lifecycle chain. Their DATFile calls do not transfer archive ownership.

## Historical Status Superseded By Current Disposition

- Confidence: strong for archive-folder split and DAT API boundaries; medium-high for umbrella granularity.
- Document kind: archive/resource umbrella over [UID:0000IN][DATFile](by-file/DATFile.md), [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), and neighboring image/archive helpers
- Proposed folder context: `NexusTK/archive/`; concrete classes should still attach to [UID:0000IN][DATFile](by-file/DATFile.md), [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), or [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md), not to this umbrella page.
- Evidence basis: live IDA MCP caller/callee/decompile checks through 2026-06-16, read-only current-package DAT table audit, and cross-linked concrete owner pages.

## Historical Umbrella Hypothesis Superseded

NexusTK resource loading likely had a compact archive subsystem centered on DAT files, EPF/EPD image assets, frame metadata, palettes, and PCX/DIB conversion. Current recovery inventory models many of these as isolated class/global pages, but the behavior and names point to a small set of archive/render-support modules.

## Historical Three-Way Split Superseded

The core DAT archive layer is now split into two concrete file hypotheses:

- [UID:0000IN][DATFile](by-file/DATFile.md) owns the per-entry `DATFile` reader, [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md), and the [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md) helper used by bulk DAT entry reads.
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) owns the public/private manager pair, mapped archive containers, resolver/hash-table state, [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md), the [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md), [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md) object ownership, and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md).
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) should own the reusable `DATIndexVector` helper. The folder remains medium-confidence, but IDA caller fanout now rules out treating it as private `DATFileMgr.cpp` code.

This page remains the umbrella for adjacent archive/resource research. Do not use it as the final owner for a class when a concrete `by-file` page exists.

## Core DAT Classes

| Class | Range | Current file | Notes |
| --- | --- | --- | --- |
| [UID:00003G][DATFile](by-class/DATFile.md) | `0x0049c130-0x0049d2cc` | [UID:0000IN][DATFile](by-file/DATFile.md) | Reader for NexusTK `.DAT` resources, line reads, bulk entry parsing, 0x11-byte entry records. |
| [UID:00003H][DATFileContainer](by-class/DATFileContainer.md) | `0x0049be80-0x0049d349` | [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | One mapped archive container and Win32 file mapping lifecycle owner. |
| [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) | `0x0049bd30-0x0049d38b` | [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | Singleton-facing archive access wrapper with [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) at `0x0067ab40` and an inner manager object. |
| [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) | `0x0049c800-0x0049d6ed` | [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | Internal index builder, archive vector, and name lookup engine used by `DATFileMgr` and `DATFile::Open`. |
| [UID:00003J][DATFileResolver](by-class/DATFileResolver.md) | `0x0049d190-0x0049d26c` | [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | Embedded resolver/hash-table cleanup helper; likely not a separate final source file. |
| [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) | discontiguous; see exact method pages | [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) | Reusable FNV-1a keyed index/list and value-table helper used by DAT, minimap, fitting-room, and monster-image state. |

## Closely Coupled Resource/Image Classes

| Class | Range | Current file | Reason to review with archive module |
| --- | --- | --- | --- |
| [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md) | `0x00457a60-0x00458610` | `render/EPFTileContext.cpp` | Shared decoded EPF/EPD tile context used by frame, minimap, dialog, and image controls. |
| `ImageLib` | `0x004cffb0-0x004e6571` | `class_ImageLib.cpp` | EPF image/cache manager singleton behind `g_pEPFLib`; render/resource owner, not raw DAT parsing. |
| `ResourceLayoutTable` | `0x004d0120-0x004d182f` | `class_ResourceLayoutTable.cpp` | Shared EPF/EPD layout lookup method family used by `g_pEPFLib`; likely part of or adjacent to `ImageLib`. |
| `DIBitmap` | `0x004a1600-0x004a1b5d` | `class_DIBitmap.cpp` | DIB wrapper used by PCX/image loading. |
| `PaletteLib` | `0x00543150-0x005431b9`, `0x005431c0-0x005443ab`, plus `0x00544420-0x0054445b` | `class_PaletteLib.cpp` | Global palette manager; render/resource owner, not raw DAT parsing. |
| `DLPalette` | `0x00542ac0-0x00543149` plus `0x005443b0-0x00544411` | `class_DLPalette.cpp` | 16-bit palette data object used by `PaletteLib`. |
| `FontImageLib` | `0x004b5f00-0x004b6409` | `class_FontImageLib.cpp` | Font glyph image library. |
| `MapTileImageLib` | `0x004d1860-0x004e6748` | `class_MapTileImageLib.cpp` | Terrain tile image library; render owner. |
| `StaticObjImageLib` | `0x004dcf60-0x004e6aa5` | `class_StaticObjImageLib.cpp` | Static map object image library; render owner. |
| `EffectObjImageLib` | `0x004ddf60-0x004e6455` | `class_EffectObjImageLib.cpp` | Effect sprite image library; uses EPF/EPD archive metadata. |
| `ItemObjImageLib` | `0x004dec30-0x004e65db` | `class_ItemObjImageLib.cpp` | Item sprite image library; render owner for `ITEM.TBL`/`ITEM.TBD` and item draw paths. |
| `HumanImageLib` | `0x004d2720-0x004e649a` | `class_HumanImageLib.cpp` | Old human body/equipment image library; render owner for human/equipment frame-table families. |
| `NewHumanImageLib` | `0x004dfd10-0x004e68a7` | `class_NewHumanImageLib.cpp` | Updated human composition image library; render owner for motion/layer/part tables. |
| `MonsterImageLib` | `0x004dac40-0x004e685f` | `class_MonsterImageLib.cpp` | Monster sprite image library; render owner for monster tables and `DATA/MON%d.DAT` indexing. |
| `RidingImageLib` | `0x004dc420-0x004dca14`; `0x004e68b0-0x004e6981` | `class_RidingImageLib.cpp` | Riding/mount image library; parses `RIDINGS.DNA`, loads `RIDINGS.EPF`, and has a separate scalar deleting destructor tail at `0x004e68b0-0x004e6981`. |
| `LightObjImageLib` | `0x004df7e0-0x004e669c` | `class_LightObjImageLib.cpp` | Light source image library; reads `LIGHT.TBL` and builds procedural radial frames. |
| `AlphaMaskSurface` | `0x00462170-0x00462e02` | `class_AlphaMaskSurface.cpp` | Temporary byte alpha-mask surface used by rendering and overlay shading. |
| `IntAlphaSurface` | `0x00463270-0x004632b1` | `class_IntAlphaSurface.cpp` | Related alpha surface destructor and vtable evidence; final source split still open. |

## Free Helpers To Review For This Area

| Function | Range | Current role |
| --- | --- | --- |
| [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md) | `0x00467380-0x00467391` | Fatal-load cleanup helper that deletes [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md); object ownership remains DAT manager even if helper source stays near app cleanup glue. |
| [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md) | `0x00467410-0x004674ed` | Startup helper in `Application.cpp` that loads numbered DAT-file series through the DAT manager. |
| [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md) | `0x0049c700-0x0049c71d` | Checks if global DAT manager can resolve a named entry. |
| [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md) | `0x004a5e60-0x004a609f` | Decodes DAT entry headers with seed table and validates parsed values. |
| [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) | `0x004bb120-0x004bb1d2` | Loads a DAT-backed file into memory with optional zero prefix. |
| `Uncompress` | `0x00414390-0x0041442c` | Bundled zlib decompression wrapper used by resource and metadata consumers. |
| `Crc32` | `0x00414430-0x00414565` | Bundled zlib CRC-32 helper used by metadata payload validation. |
| `Adler32` | `0x00415ee0-0x0041600e` | Bundled zlib Adler-32 helper used by inflate internals. |
| `LoadPcxImage` | `0x004a17b0-0x004a18a8` | Loads PCX through shared file-buffer path and returns `DIBitmap`. |
| `CreateDIBitmapFromPcxBuffer` | `0x004a18b0-0x004a1b0c` | Builds a `DIBitmap` from decoded PCX bytes. |
| `DecodePcxToRgb565Buffer` | `0x00549410-0x00549616` | Decodes PCX image data into RGB565 pixels. |
| `DrawFrameWithBlendMode` | `0x00462e10-0x00462f1d` | Copies/adds/subtracts byte frame masks into an alpha surface. |
| [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md) | `0x00462f20-0x00463252` | `AlphaMaskSurface::DrawEncodedAlphaFrame` member helper. It consumes EPFTileContext encoded rows and is owned/routed through AlphaMaskSurface; this umbrella records it only as adjacent render support, not DATArchive-owned code. |
| `LoadImageFrameTable` | `0x004d0f50-0x004d15c5` | Loads or merges frame metadata from DAT/EPF archives; see [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md). |
| `LoadFrameDrawRecord` | `0x004d1600-0x004d165d` | Frame draw record helper; see [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md). |
| `LoadTileEpfMetadata` | `0x004d1b80-0x004d1f22` | Scans `TILE<n>.EPF` archives for map tile metadata. |
| `BuildTilecArchiveTable` | `0x004dda60-0x004dde01` | Builds `TILEC%d.EPF` metadata table. |
| `BuildEffectArchiveTable` | `0x004de420-0x004de7c1` | Builds `EFFECT%d.EPF` metadata table. |
| `GetSpriteBounds` | `0x004de2a0-0x004de3d1` | Resolves effect atlas frame bounds. |
| `GetItemGlyphBounds` | `0x004df460-0x004df4f8` | Resolves item sprite rectangles from `ITEM.EPF`/`ITEM.EPD`. |
| `ResolveSpritePartPath` | `0x004e19d0-0x004e1f26` | Resolves numbered/single sprite-part EPF archives. |
| `MonsterImageLibTable_5289D0` / `MonsterImageLibTable_528BE0` | `0x00528930-0x00528d51` | Small nested table owners shared by monster and riding parsers, including initializer/destructor callback helpers. |
| [UID:0000VK][VectorGrowArchiveIndex_004E5990](by-item/VectorGrowArchiveIndex_004E5990.md) | `0x004e5990-0x004e5a62` | Grows monster archive-index buffer; IDA currently shows only `MonsterImageLib::LoadMonsterArchives` caller. |

## 2026-05-22 Evidence Update

- `DATFile` inspection reports a 20-byte object with embedded `File` storage at `0x0`, entry pointer at `0x8`, read position at `0xc`, and entry size at `0x10`.
- `DATFileContainer` source shows a mapped view with `entryCount` at mapped dword `0`, `entryTable` at mapped dword `1`, mapped data base at container offset `0x0c`, `entryCount` at container offset `0x14`, and `entryTable` at container offset `0x18`.
- Entry records are observed as 17 bytes: 4-byte payload start offset plus 13-byte ANSI name. `DATFile` computes payload size from the next record start offset at `record + 0x11`.
- IDA MCP decompilation of `DATFileContainer::DATFileContainer` confirms container offset `0x10` is set from the first dword of the final 17-byte table row: `entryTable + (entryCount - 1) * 17`. This likely represents an empty-name sentinel/final payload offset row.
- `_DATFileMgr::LoadDATFileIndex` (`0x0049c800`) is summarized as loading one DAT archive and populating the internal name index for each exposed entry.
- `_DATFileMgr::LoadDATFileIndex` reads the entry name from `entryTable + entryIndex * 17 + 4`, converts it to uppercase wide text, skips empty names, and inserts only names not already present in the manager index.
- IDA MCP `callees` confirmed `DATFile::Open` (`0x0049c180`) calls `_DATFileMgr::FindEntryByName` (`0x0049cad0`).
- IDA MCP `callees` confirmed `DATFile::ReadAllEntries` (`0x0049c4a0`) calls `ParseEntries` (`0x004a5e60`); `callers` confirmed `ParseEntries` is only called by the two bulk entry readers at `0x0049c4a0` and `0x0049c4f0`.
- 2026-05-25 IDA MCP caller/callee/decompile recheck keeps `ParseEntries` in `archive/DATFile.cpp`: the only call sites are `0x0049c4d4` and `0x0049c524`, and both wrappers only compute `GetSize() >> 1`, read eight bytes, and dispatch to the helper.
- IDA MCP `callees` confirmed [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) (`0x004bb120`) constructs `DATFile`, opens the DAT-backed path, gets size, reads payload bytes, closes, and destructs the `DATFile`.
- IDA MCP `callers` found [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) used by PCX loading, image-frame loading, tile metadata, tilec/effect table building, sprite-part resolution, audio paths, and other resource paths.
- IDA MCP decompilation of `SoundManager` confirmed DAT-backed audio resource use: `%03d.wav` sound effects are probed/opened through [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) and `DATFile`, and zone `%08d.LST`/`%08d.LSR`/`%08d.MP3` entries are selected through the same helper. See [UID:0000UB][DATAudioResources](by-item/DATAudioResources.md).
- Live IDA caller/callee checks confirm EPF/EPD table helpers call the DAT API but belong above it: `LoadImageFrameTable`, `LoadTileEpfMetadata`, `BuildTilecArchiveTable`, `BuildEffectArchiveTable`, and `ResolveSpritePartPath` all use [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), `DATFile`, and `DATFile::GetDataPointer` while building render metadata tables. See [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md).
- Live IDA inspection confirms `ImageLib` initializes [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / historical IDA alias `DAT_0067a744`, while the methods recovered as `ResourceLayoutTable` provide the shared EPF/EPD layout lookup API. They open EPF/EPD resources through `DATFile`, but own named frame-layout buckets and should live in render/resource code rather than in `archive/DATFile.cpp`.
- Palette inspection confirms `PaletteLib` and `DLPalette` follow the same dependency pattern: they read DAT-backed `.PAL` streams through `DATFile`, but own render palette selection, color conversion, and slot tables. See [UID:0000MA][Palette](by-file/Palette.md).
- Map/static/effect image-library inspection confirms `MapTileImageLib`, `StaticObjImageLib`, and `EffectObjImageLib` depend on DAT-backed resources but own render/image metadata: `TILE%d.EPF`, `TILEC%d.EPF`, and `EFFECT%d.EPF` table builders each have a single owning image-library constructor caller.
- Item/riding/light image-library inspection extends that ownership rule: `ItemObjImageLib` owns item table metadata and draw variants over `ITEM.EPF`/`ITEM.EPD`, `RidingImageLib` owns `RIDINGS.DNA` plus `RIDINGS.EPF` loading, and `LightObjImageLib` owns `LIGHT.TBL` procedural light-frame generation. These are DAT consumers, not DAT archive parser classes.
- Human/new-human/monster image-library inspection completes the main sprite-family map: `HumanImageLib` owns old human/equipment frame-table resources, `NewHumanImageLib` owns new table-driven human composition data, and `MonsterImageLib` owns monster animation tables plus numbered `DATA/MON%d.DAT` archive indexing. These remain render/image modules even when they instantiate `DATFile` or `DATFileContainer`.
- Font/DIB/alpha-surface inspection fills in the render support layer: `FontImageLib` owns `BA0`/`BA1` glyph archives and UI text decode, `DIBitmap` plus PCX helpers own startup PCX-to-DIB conversion, and `AlphaMaskSurface` plus mask blitters own byte alpha surfaces consumed by light/effect/item/human render paths.
- 2026-05-24 IDA MCP caller checks confirm `DATIndexVector` is shared infrastructure rather than manager-private DAT code. `ResizeAndFill` is called from fitting-room item state, minimap version manager, `DATFileMgr`/`_DATFileMgr`, and `MonsterImageLib`; `InsertNode` and `FindNodeByKey` are used by minimap hash-list and monster archive-bounds cache paths. See [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md).
- 2026-05-25 IDA MCP checks confirm [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md) is called only by `Application::Initialize`, formats `L"%s%d.DAT"` for numbered resource families, and delegates each existing file to the [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md). Treat it as application startup code, not archive-manager ownership.
- 2026-05-25 IDA MCP disassembly/string reads resolve the full [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md) inventory around the numbered-family helper, including fixed required archives, `DATA/MUH###.DAT`/`DATA/MUS###.DAT` music loops, BINT `0..2`, and `DATA/WM.DAT`.
- 2026-05-24 IDA MCP checks resolve `WriteRGBA8PNGFile` as a small [UID:0000K4][ImageWriters](by-file/ImageWriters.md) wrapper over bundled [UID:0000KW][LodePNG](by-file/LodePNG.md) code. It should not be grouped into DAT/archive resource code.
- 2026-05-24 IDA MCP checks resolve `Crc32`, `Adler32`, `Uncompress`, and the inflate/deflate helpers as bundled [UID:0000PC][Zlib](by-file/Zlib.md) 1.1.4 support code, not DAT parser code.

## 2026-06-04 Live IDA Recheck

- IDB identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Live `lookup_funcs` confirms the core archive ranges still split cleanly: `0x0049bd30-0x0049be41` public manager wrapper, `0x0049be70-0x0049be7c` forwarder, `0x0049be80-0x0049c0c9` mapped archive container, `0x0049c130-0x0049d2cb` `DATFile`/entry reader cluster, `0x0049c800-0x0049d6ed` internal manager/resolver cluster, `0x004a5e60-0x004a609f` parse helper, and `0x004bb120-0x004bb1d2` load-buffer wrapper.
- `ParseEntries` at `0x004a5e60` still has exactly two live callers, `0x0049c4d4` in `0x0049c4a0` and `0x0049c524` in `0x0049c4f0`, matching private/static-style support for [UID:0000IN][DATFile](by-file/DATFile.md).
- `DATFile::Open` at `0x0049c180` calls the manager lookup helper `0x0049cad0`; `HasDATEntry` at `0x0049c700` also only calls `0x0049cad0`, proving it is a thin archive API boundary.
- `LoadDatFileBuffer` at `0x004bb120` calls `DATFile` constructor/open/get-size/read/close/destructor helpers (`0x0049c130`, `0x0049c180`, `0x0049c240`, `0x0049c2f0`, `0x0049c310`, `0x0049c160`) and has broad resource/UI callers, so it remains a [UID:0000IN][DATFile](by-file/DATFile.md) wrapper rather than a consumer-owned helper.
- `HasDATEntry` has live caller fanout from PCX/image loading, image-frame table loading, tile metadata, tilec/effect table builders, sprite-part resolution, palette/audio paths, and UI/resource consumers; those callers confirm DAT dependency, not DAT parser ownership.
- `LoadIndexedDATSeries` at `0x00467410-0x004674ed` is called from `Application::Initialize` (`0x004639d0`) for numbered archive families and calls the `0x0049be70` archive-manager forwarder after file-existence probing, so it remains startup policy in [UID:0000HG][Application](by-file/Application.md).
- `DATIndexVector` fanout remains broad: `0x00423b00` has callers in fitting-room/minimap/DAT manager/monster-image paths, while `0x00457100` and `0x00457580` are used by minimap and monster-image helper paths. This supports a standalone [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) file under `NexusTK/archive/`, not private ownership by `DATFileMgr.cpp`.
- The umbrella path assignment to `NexusTK/archive/` is folder context only. Concrete code ownership remains on [UID:0000IN][DATFile](by-file/DATFile.md), [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md), and the render/audio/application consumer files named above.

## 2026-06-16 IDA And Package Recheck

- Live IDA MCP session `b001_mappane_0001AW_20260616` (`NexusTK.exe`, image base `0x00400000`, Hex-Rays ready) reconfirmed the same core archive boundaries: `DATFileContainer::DATFileContainer` at `0x0049be80` size `0x249`, `DATFile::Open` at `0x0049c180` size `0xbb`, `HasDATEntry` at `0x0049c700` size `0x1d`, `_DATFileMgr::LoadDATFileIndex` at `0x0049c800` size `0x2c4`, `_DATFileMgr::FindEntryByName` at `0x0049cad0` size `0xd5`, `ParseEntries` at `0x004a5e60` size `0x23f`, and `LoadDatFileBuffer` at `0x004bb120` size `0xb2`.
- Function profiling reconfirmed `LoadDatFileBuffer` as a DATFile lifecycle wrapper with nine caller functions across UI/resource constructors and `DATIndexVector` as shared infrastructure: `ResizeAndFill` has callers from minimap, fitting-room, DAT manager, and monster-image code; `InsertNode`/`FindNodeByKey` are also used outside the manager. This keeps the concrete owner split on [UID:0000IN][DATFile](by-file/DATFile.md), [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), and [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md).
- Decompilation rechecked the 17-byte table stride: `DATFileContainer` stores `entryCount`, stores `mappedView + 4` as the entry-table pointer, and caches the first dword of `entryTable + (entryCount - 1) * 17`; `DATFile::Open` and `OpenByIndex` compute payload size as the next row's start offset minus the current row's start offset.
- A read-only audit of 250 current DAT files under `E:\2026\Resources\Read_Only\NexusTK\Data` parsed every archive with no bad headers, monotonic offsets in all 250, offsets within file bounds in all 250, and zero zero-length intervals. Counts ranged from 2 to 260 table rows, and 1,038 non-empty row names were null-terminated within the 13-byte field.
- The same audit resolves the previous final-row blocker: 247 of 250 final boundary rows have an empty name field, but `baramst.dat`, `head0.dat`, and `mus004.dat` contain nonzero bytes in the final row's 13-byte name area. Therefore the source-quality invariant is that the final row's first dword supplies the last payload boundary; the final row's name bytes are padding/unused and cannot be documented as always an empty-name sentinel.

## Historical Proposed Split Superseded

The archive/resource area may need several original files rather than one:

```text
archive/DATFile.cpp
archive/DATFileMgr.cpp
archive/DATIndexVector.cpp
app/Application.cpp
audio/SoundManager.cpp
render/ImageFrameTable.cpp
render/ImageLib.cpp
render/ResourceLayoutTable.cpp
render/ImageLoaders.cpp
render/EPFTileContext.cpp
render/Palette.cpp
render/FontImageLib.cpp
render/DIBitmap.cpp
render/AlphaMaskSurface.cpp
render/Surface.cpp
render/ImageWriters.cpp
third_party/lodepng.cpp
third_party/zlib/
```

`DATFile`, [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md), and [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md) should migrate first into [UID:0000IN][DATFile](by-file/DATFile.md). `DATFileContainer`, `DATFileMgr`, `_DATFileMgr`, `DATFileResolver`, [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md), the [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md), [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md) object ownership, and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) should migrate with [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md). [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md) should stay near `Application::Initialize` in [UID:0000HG][Application](by-file/Application.md), because it owns startup scan policy over numbered archives while merely calling into the DAT manager API. `DATIndexVector` should stay standalone in [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) or a later common-helper folder; do not fold it into the manager file. `ImageLib`, `ResourceLayoutTable`, and image-frame/EPF helpers now lean toward `render/ImageLib.cpp`, `render/ResourceLayoutTable.cpp`, `render/ImageFrameTable.cpp`, or nearby image-resource files rather than `archive/`. `ImageWriters.cpp`, `third_party/lodepng.cpp`, and `third_party/zlib/` are render/codec/support-library dependencies, not DAT resource modules. `SoundManager` remains an audio module caller of the DAT API, not part of DAT parsing.

## Historical Open Questions Resolved

- Whether `DATIndexVector`'s final folder is `archive/` because of the imported source name, or a common/helper folder because of broad non-DAT caller fanout.
- Exact render/resource filename split for EPF frame-table helpers versus per-asset image libraries.
- Which image-library classes should be grouped by asset type (`EffectObjImageLib`, `FontImageLib`, map/tile image libs) versus common base support.
- Whether older or alternate DAT distributions follow the same mostly-empty final boundary-row convention as the audited 2026 read-only package.

## Cross-References

- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:00003H][DATFileContainer](by-class/DATFileContainer.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:00003J][DATFileResolver](by-class/DATFileResolver.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)
- [UID:0000UB][DATAudioResources](by-item/DATAudioResources.md)
- [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
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
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0000KW][LodePNG](by-file/LodePNG.md)
- [UID:0000PC][Zlib](by-file/Zlib.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md)
- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- [UID:0000VK][VectorGrowArchiveIndex_004E5990](by-item/VectorGrowArchiveIndex_004E5990.md)
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
- [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md)
- [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md)
- [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)

## Changes

- 2026-07-09 B001 UID0000YO stale support correction:
  - Replaced the provisional `0x00462f20-0x00463251` helper row with canonical UID0000YO and the correct half-open `0x00462f20-0x00463252` range.
  - Recorded that this is an AlphaMaskSurface member/render dependency, not DATArchive ownership; DATArchive scores and source placement are unchanged.
- 2026-06-07 A008 alias cleanup:
  - Before: the render/archive boundary evidence used bare `g_pEPFLib` / `DAT_0067a744` wording.
  - Changed to: canonical [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) wording with `DAT_0067a744` retained as the historical IDA alias.
  - Evidence: this umbrella page already distinguishes `ImageLib`/`ResourceLayoutTable` render ownership from DAT archive parsing.
- 2026-06-06: Corrected the RidingImageLib umbrella range endpoint from `0x004e6980` to `0x004e6981`.
  - Summary/evidence: A002 IDA MCP `lookup_funcs` reports `sub_4E68B0` size `0xd1`, so `0x004e6980` is still inside the scalar deleting destructor and `0x004e6981` is the exclusive end.

- 2026-05-28: Corrected the `PaletteLib` endpoint from `0x005431c0-0x0054445a` to `0x005431c0-0x0054445b`. Evidence: IDA MCP byte/function review shows the final byte is the `retn 4` operand in `PaletteLib::ScalarDeletingDestructor`; `0x0054445b-0x00544460` is alignment padding before `Pane`.
- Before: the monster/riding table helper summary used range `0x00528950-0x00528d28`.
- Changed to: the range is `0x00528930-0x00528d51`.
- Summary/evidence: 2026-05-28 IDA MCP adds the zero initializer, frame-record initializer, and no-op destructor callback around the existing monster/riding table helper island.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:76`.
  - Summary/evidence: this umbrella page gives a broad archive/resource split map, DAT core classes, adjacent render/resource consumers, helper ownership decisions, proposed split, open questions, and extensive cross-references; confidence is capped because it is intentionally an umbrella and should not be treated as a final owner for concrete classes when specific by-file pages exist.
- 2026-05-31 MapTile range endpoint correction:
  - What existed before: `MapTileImageLib` and `LoadTileEpfMetadata` used stale endpoints `0x004e6747` and `0x004d1f21`.
  - Changed to: half-open endpoints `0x004e6748` and `0x004d1f22`.
  - Summary/evidence: IDA `lookup_funcs` reports `MapTileImageLib` scalar deleting destructor `0x004e66a0` size `0xa8` and `LoadTileEpfMetadata` `0x004d1b80` size `0x3a2`; these functions now have exact by-memory pages and coverage rows.
- 2026-06-04 reconstruction path and confidence update:
  - Before: `CONFIDENCE:76` and blank `PROPOSED_RECONSTRUCTION_PATH`.
  - After: `CONFIDENCE:84` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/"`.
  - Summary/evidence: live IDA rechecked the DAT manager/file/helper boundaries, the two-callsite `ParseEntries` ownership, `LoadDatFileBuffer` as a DATFile wrapper, `HasDATEntry` as a broad DAT API boundary, `LoadIndexedDATSeries` as application startup policy, and `DATIndexVector` as shared archive helper infrastructure. Completion stays at `88` because this page remains an umbrella and should not become the final owner for concrete classes.
- 2026-06-16 A002 file-boundary/package refresh:
  - Before: `88/84`.
  - After: `89/87`.
  - Summary/evidence: live IDA MCP reconfirmed the core DATFile/DATFileMgr/helper boundaries, DATIndexVector shared fanout, and load-buffer ownership, while a read-only audit of 250 current-package DAT archives resolved the final-row blocker: offsets are monotonic and bounded, all exposed non-empty names are null-terminated, and the final row is a payload-boundary row whose name bytes are often empty but not reliably zero. Concrete source ownership remains on DATFile, DATFileMgr, and DATIndexVector; this page remains an umbrella.
