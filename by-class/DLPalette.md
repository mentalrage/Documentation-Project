*** UID:00003Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Palette.h"
#include "../archive/DATFile.h"
#include "Surface.h"
#include "../third_party/zlib/zlib.h"

#include <string.h>
#include <windows.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_PALETTE_H
#define NEXUSTK_RENDER_PALETTE_H

#include "../util/LObject.h"

class File;
struct EPFTileContext;

struct DLPaletteRange
{
    unsigned char firstIndex;
    unsigned char lastIndex;
};

class DLPalette : public LObject
{
    friend struct EPFTileContext;

public:
    [[CHILDREN]]

private:
    DLPaletteRange *m_paletteRanges;
    int m_paletteRangeCount;
    unsigned char m_paletteHeader[32];
    unsigned short m_mappedColors[256];
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DLPalette

## Status

- Confidence: very strong for the exact `0x22c` layout, typed two-byte palette-range storage, copy/load/application behavior, Palette.cpp/Palette.h source route, emitted child aggregation, and bitmap-palette behavior; original lexical field/method spellings remain inferred.
- Likely source file: [UID:0000MA][Palette](by-file/Palette.md), with detail notes in [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- Address ranges: non-emitting inventory parent [UID:0001E4][0x00542ac0-0x00543149.DLPaletteMethodCluster](by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md), exact child methods/raw helpers beneath it, and [UID:0003MU][0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor](by-memory/0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_DLPalette.cpp`

## Class Purpose

`DLPalette` is the 16-bit color palette object used by sprite, tile, text, and UI rendering. It owns an optional array of inclusive two-byte palette-range records, a fixed header, and a 256-entry native mapped-color table. It can be constructed empty, deep-copied from another `DLPalette`, loaded from a DAT-backed stream/file, loaded from raw RGBA, or loaded from a bitmap palette.

`PaletteLib` owns most long-lived instances, while rendering helpers consume `DLPalette` through lookup and color-mapping calls.

## Observed Layout

```text
DLPalette
  +0x00  LObject/vtable
  +0x04  DLPaletteRange* m_paletteRanges / typed inclusive two-byte records
  +0x08  int m_paletteRangeCount / range-record count
  +0x0c  unsigned char m_paletteHeader[0x20] / palette header block
  +0x2c  uint16 m_mappedColors[256]
```

Generated overlays name `mappedColors` at offset `0x2c`, which matches the first 44 bytes of object/header state followed by a 512-byte 16-bit lookup table. Loader, application, copy, and EPF-consumer evidence resolves `+0x04/+0x08` to `DLPaletteRange *m_paletteRanges` and `int m_paletteRangeCount`. Each record is exactly two bytes with inclusive `firstIndex`/`lastIndex` endpoints; `ApplyPaletteEntryMoves` may use local destination/source aliases for the same bytes. The older `m_entryMoves`/`m_entryMoveCount` vocabulary is retained only as a superseded historical model. All field and record spellings remain high-probability source-facing inference rather than original-symbol proof.

The layout totals exactly `0x22c`: 4-byte `LObject`/vtable state, one 4-byte range pointer, one 4-byte count, a 32-byte header, and 512 mapped-color bytes. No padding or invented accessor object is needed.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `unsigned short MapColor(unsigned int colorIndex) const` | [UID:0004HQ][0x00542ac0-0x00542adc.DLPaletteMapColor](by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md) | Source-ready bounded getter emitted through the child CPP/H channels. It returns zero above index 255 and otherwise returns `m_mappedColors[colorIndex]`; 23 render consumers prove liveness. |
| `void SetColor(unsigned int colorIndex, unsigned char red, unsigned char green, unsigned char blue)` | [UID:0004HR][0x00542ae0-0x00542b4a.DLPaletteSetColor](by-memory/0x00542ae0-0x00542b4a.DLPaletteSetColor.md) | Source-ready setter emitted through the child CPP/H channels. It rejects indexes above 255, independently normalizes each component in `1..7` to `8`, calls Surface-owned `g_pfnPackPixel(red, green, blue)`, and stores the returned native word. Its source contract is void. |
| `void SetPackedColor(unsigned int colorIndex, unsigned short packedColor)` | [UID:0004HS][0x00542b50-0x00542b63.DLPaletteSetPackedColor](by-memory/0x00542b50-0x00542b63.DLPaletteSetPackedColor.md) | Source-ready out-of-line setter emitted through the child CPP/H channels. It performs exactly one unchecked `m_mappedColors[colorIndex] = packedColor` word store, has no branch/callee/explicit return, and is used at four ignored-result restoration sites in `BalloonObjectPane::PaintBubble` and `ColorStringChattingMessage::Draw`. The residual EAX index is compiler/decompiler residue, not a source return value. |
| `ExpandMappedColor` (descriptive) | [UID:0004HT][0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw](by-memory/0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw.md) | Source-ready retained raw receiver method that reads `m_mappedColors[index]` and expands the native color through Surface slot 8 `g_pfnExpandPixel` / `SurfaceExpandPixelProc`; no direct caller or original symbol was recovered, so the method name remains descriptive. |
| `DLPalette::DLPalette` | [UID:0004HU][0x00542bb0-0x00542bda.DLPaletteDefaultConstructor](by-memory/0x00542bb0-0x00542bda.DLPaletteDefaultConstructor.md) | Constructs an empty palette object. |
| `DLPalette::DLPalette(const DLPalette &source)` | [UID:0004HV][0x00542be0-0x00542c95.DLPaletteCopyConstructor](by-memory/0x00542be0-0x00542c95.DLPaletteCopyConstructor.md) | Source-ready retained deep-copy constructor. Constructs the base, installs the vtable, copies the fixed header/table, and conditionally allocates and copies typed `DLPaletteRange` records. Exact body and fence hashes, base-only EH cleanup, and zero-static-route interpretation live on the child. |
| `DLPalette::~DLPalette` | [UID:0004HW][0x00542ca0-0x00542ccf.DLPaletteDestructor](by-memory/0x00542ca0-0x00542ccf.DLPaletteDestructor.md) | Frees optional entry/remap data and chains to `LObject`. |
| `FreePaletteData` | [UID:0004HX][0x00542cd0-0x00542cf3.DLPaletteFreePaletteData](by-memory/0x00542cd0-0x00542cf3.DLPaletteFreePaletteData.md) | Clears entry count and frees optional entry/remap data without destroying the object. |
| `CopyPaletteState` (descriptive; raw label `DLPaletteRawCopyHelper`) | [UID:0004HY][0x00542d00-0x00542d81.DLPaletteRawCopyHelper](by-memory/0x00542d00-0x00542d81.DLPaletteRawCopyHelper.md) | Source-ready retained raw receiver helper that copies `m_paletteHeader`, typed `m_paletteRanges`/`m_paletteRangeCount`, and `m_mappedColors` into an already prepared destination. It deliberately omits base/vtable/full-constructor behavior; no direct live route or original symbol was recovered. |
| `DLPaletteColorTransformRaw` | [UID:0004HZ][0x00542d90-0x00542de3.DLPaletteColorTransformRaw](by-memory/0x00542d90-0x00542de3.DLPaletteColorTransformRaw.md) | Raw single-palette transform helper kept under the Palette source umbrella unless a future caller proves it is a declared DLPalette method. |
| `void LoadFromFile(const wchar_t *path)` | [UID:0004I0][0x00542df0-0x00542e5f.DLPaletteLoadFromFile](by-memory/0x00542df0-0x00542e5f.DLPaletteLoadFromFile.md) | Source-ready out-of-line wrapper: constructs one 20-byte `DATFile`, calls throwing `Open`, delegates through `File *` to `LoadFromStream`, explicitly closes on the normal path while ignoring Close's Boolean result, and relies on automatic destruction for normal and escaping-exception cleanup. The retained method has no current incoming xref/pointer/rel32 route, which is liveness evidence rather than a no-code reason. |
| `void LoadFromStream(File *stream)` | [UID:0004I1][0x00542e60-0x00542f91.DLPaletteLoadFromStream](by-memory/0x00542e60-0x00542f91.DLPaletteLoadFromStream.md) | Resolved base-stream declaration; reads the header, allocates and reads typed `DLPaletteRange` records, and reads 256 RGBX colors through virtual `File` calls before conversion to native 16-bit colors. All seven direct callers ignore EAX; its separate CPP body remains a child-specific implementation responsibility. |
| `ApplyPaletteEntryMoves` | [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md) | Rotates `m_mappedColors` across each typed two-byte palette-range record; called by the PaletteLib screen-palette reset path. |
| `LoadFromRawRGBA` | [UID:0004I2][0x00543020-0x00543091.DLPaletteLoadFromRawRGBA](by-memory/0x00543020-0x00543091.DLPaletteLoadFromRawRGBA.md) | Stamps a `DLPalette` header and builds a lookup table from 256 raw RGBA/BGRA-style entries. |
| `LoadFromBitmapPalette` | [UID:0004I4][0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette](by-memory/0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette.md) | Source-ready `void` member called by two LogoPane `.LGO` paths. It invokes stock zlib 1.1.4 `uncompress` into `RGBTRIPLE[256]`, deliberately preserves the original uninitialized `uLongf` destination-length local, passes BGR memory as red/green/blue to `g_pfnPackPixel`, and writes all 256 `m_mappedColors` only on `Z_OK`. |
| `ScalarDeletingDestructor` | [UID:0003MU][0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor](by-memory/0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor.md) | Destructor glue placed near the `PaletteLib` scalar-deleting destructor, split out as an exact page. |

## Stream Format Notes

`LoadFromStream` has the resolved source contract `void LoadFromStream(File *stream)`. It reads a 0x20-byte header through the virtual base-stream interface, uses a header dword as `m_paletteRangeCount`, allocates `DLPaletteRange[m_paletteRangeCount]`, reads two bytes per typed record, then reads 0x400 bytes of RGBX palette data. It converts 256 entries into native 16-bit colors, forces palette index 0 to transparent, and replaces other zero-valued colors with a default color that depends on `g_isHighColor`. The seven observed callers all ignore EAX and the inspected PaletteLib routes pass stack `DATFile` objects, supporting a `File *` declaration rather than a DATFile-coupled decoder.

`LoadFromBitmapPalette` is a distinct compressed payload route rather than another form of the DAT stream layout. Its two LogoPane callers read a size-prefixed `.LGO` palette blob, and the method inflates exactly 768 bytes interpreted as 256 Windows `RGBTRIPLE` values. The local bytes are B/G/R, but Surface slot 9 is called as red/high, green/middle, blue/low. This is also distinct from `LoadFromRawRGBA`, whose BMP caller provides four-byte RGBQUAD-style entries.

## Source And Dependency Model

- The class emits a conventional `Palette.cpp` / `Palette.h` shell with `[[CHILDREN]]`; exact method bodies and declarations remain on their child pages.
- `Palette.cpp` includes `Palette.h`, `../archive/DATFile.h`, `Surface.h`, `../third_party/zlib/zlib.h`, `<string.h>`, and `<windows.h>`. `DATFile.h` is a complete-type dependency because `LoadFromFile` instantiates a 20-byte automatic `DATFile`; `<string.h>` supplies the observed `memcpy`/`memmove` source operations; Surface, zlib, and Windows provide the established callback, API/type, and `RGBTRIPLE` dependencies.
- `Palette.h` forward-declares `File` because the `LoadFromStream(File *stream)` declaration needs only the abstract stream name. It also forward-declares `EPFTileContext` and grants `friend struct EPFTileContext` so [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md) can read the private range array/count without inventing an unobserved accessor. The header does not include or expose DATFile solely for the stream pointer contract.
- `LoadFromFile` remains a DLPalette/Palette source method even though DATFile performs archive lookup. `DATFile::Open` is `void` and throws `FileError` on failure; the wrapper has no Boolean Open test or local catch, and its explicit normal-path Close result is ignored.
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) owns the sole `SurfacePackPixelProc g_pfnPackPixel` declaration/definition. DLPalette is a consumer and must not duplicate callback storage.
- [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md) owns stock zlib `uncompress`; Palette calls it and does not import or paste `uncompr.c`.
- Header declarations for existing emitted children `ExpandMappedColor`, `DLPalette(const DLPalette &source)`, `CopyPaletteState`, and `ApplyPaletteEntryMoves` are supplied by UID0004HT, UID0004HV, UID0004HY, and UID0001E5 so the class shell remains coherent.
- [UID:0004HS][0x00542b50-0x00542b63.DLPaletteSetPackedColor](by-memory/0x00542b50-0x00542b63.DLPaletteSetPackedColor.md) now supplies the public `SetPackedColor(unsigned int, unsigned short)` declaration and exact out-of-line definition through the same child aggregation route. The method belongs in `Palette.h` / `Palette.cpp` with the other mapped-color methods; this class page intentionally does not duplicate its body.
- [UID:0004HQ][0x00542ac0-0x00542adc.DLPaletteMapColor](by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md) and [UID:0004HR][0x00542ae0-0x00542b4a.DLPaletteSetColor](by-memory/0x00542ae0-0x00542b4a.DLPaletteSetColor.md) now supply their exact public declarations and out-of-line definitions through the same `[[CHILDREN]]` route. Together with SetPackedColor they form one coherent mapped-color API in `Palette.h` / `Palette.cpp`; the owner shell carries no duplicate body or declaration.
- `SetPackedColor` has a distinct source contract from `SetColor`: callers pass a value already encoded in the active native 16-bit format, and the method neither validates the index nor invokes `g_pfnPackPixel`. Surface is therefore a sibling-method dependency/provider, not this setter's owner or callee.
- The source-facing method and parameter names are inferred from established class vocabulary, adjacent mapped-color operations, and caller roles. The class layout and behavior are exact even though original PDB lexical spellings and the final declaration order among still-blank siblings are unavailable.

## Render Consumers

[UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) is a direct render consumer of `DLPalette::MapColor` (`0x00542ac0`). `GrafPort::CompositePixels` calls `PaletteLib::GetCurrentPalette`, passes the GrafPort background-color field at `this+0x7c` to `MapColor`, and uses the returned native 16-bit color to fill zero pixels inside a clipped destination rectangle while inverting nonzero pixels.

[UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) is a direct image-loader producer/consumer for caller-supplied palette storage. It calls `DLPalette::FreePaletteData` before validation and `DLPalette::LoadFromRawRGBA` with the embedded BMP RGBQUAD table at `bmpData + sizeof(BITMAPFILEHEADER) + biSize`; in this context the four-byte entries are BMP BGRA/RGBQUAD-style entries, not a DAT stream palette.

[UID:0004HS][0x00542b50-0x00542b63.DLPaletteSetPackedColor](by-memory/0x00542b50-0x00542b63.DLPaletteSetPackedColor.md) closes the packed-color restoration side of two draw protocols. `BalloonObjectPane::PaintBubble` calls it at `0x0046820c` and `0x0046821f` to restore indexes 253 and 254 after temporary color changes. `ColorStringChattingMessage::Draw` calls it at `0x004837e5` and `0x004837f3` to restore saved foreground/background values. Both callers first read through `MapColor`, temporarily write through `SetColor`, draw, and then restore through `SetPackedColor`; all four calls ignore EAX, proving the source-facing `void` contract.

## B010 2026-08-14 Mapped-Color API Closure

- The class remains `92/94` with exact `0x22c` layout, UID0000MA owner/emitter, and Palette.cpp/Palette.h aggregation. No field, range, file, inheritance, split, or ownership change is introduced.
- UID0004HQ now emits `unsigned short DLPalette::MapColor(unsigned int colorIndex) const` and its public declaration. The method returns zero for `colorIndex > 0xff` and otherwise reads the 256-entry `m_mappedColors` table at `+0x2c`; 23 consumers include GrafPort and ColorStringChattingMessage rendering.
- UID0004HR now emits `void DLPalette::SetColor(unsigned int colorIndex, unsigned char red, unsigned char green, unsigned char blue)` and its public declaration. It performs the exact upper-bound return, each `1..7 -> 8` normalization, Surface-owned `g_pfnPackPixel` conversion in red/green/blue order, and one mapped-color store. Four callers prove live mutation; residual EAX is not a source return value.
- UID0004HS remains the exact unchecked packed-word setter. ColorStringChattingMessage::Draw uses the three-method transaction as `MapColor` save, `SetColor` temporary RGB conversion, outlined draw under the borrowed palette, and `SetPackedColor` restoration. Palette pointer ownership remains with PaletteLib/GrafPort; DLPalette owns entry behavior but does not release the borrowed palette.
- Source-facing method/parameter/member names are high-probability inferred lexical forms consistent with the adjacent API and established class layout. Exact original spellings remain the confidence cap, while raw IDA names and decompiler expressions remain excluded from emitted source.

## IDA MCP Boundary Notes

2026-06-13 C001 live IDA MCP recheck records the primary DLPalette method cluster as `0x00542ac0-0x00543149` and the scalar deleting destructor island as [UID:0003MU][0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor](by-memory/0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor.md). B008's 2026-07-06 implementation callback reclassifies [UID:0001E4][0x00542ac0-0x00543149.DLPaletteMethodCluster](by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md) as evidence/inventory only, not a handwritten source method, and moves exact method/raw-helper details to child pages [UID:0004HQ][0x00542ac0-0x00542adc.DLPaletteMapColor](by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md) through [UID:0004I4][0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette](by-memory/0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette.md) plus existing [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md). The physically adjacent [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md) method sits between `LoadFromStream` and `LoadFromRawRGBA`; B014's 2026-06-25 implementation pass replaces the older "palette-family support rather than DLPalette method" statement because the callee uses the same `+0x04` entry-move pointer, `+0x08` count, and `+0x2c` mapped-color table created and copied by adjacent DLPalette methods. It is called by the PaletteLib screen-palette reset path, but that caller context is usage evidence, not ownership evidence against DLPalette. The bytes after `DLPalette::LoadFromBitmapPalette` are now split precisely: `0x00543149-0x00543150` padding, [UID:0003MT][0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw](by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md), and `0x005431b9-0x005431c0` padding before the `PaletteLib` method cluster.

B003's 2026-07-06 UID0004HY implementation makes the raw `0x00542d00-0x00542d81` copy helper first-draft source-ready as inferred `DLPalette::CopyPaletteState`. The helper still has no direct caller, pointer route, rel32 route, IDA function object, or original symbol, but the copied offsets match the `DLPalette` layout and adjacent copy constructor state-copy body. This pass names the existing 0x20-byte header block at `+0x0c` as inferred `m_paletteHeader` for source reconstruction.

B002's 2026-08-04 UID0004HV callback resolves the adjacent copy constructor to exact formal `DLPalette::DLPalette(const DLPalette &source)` source and synchronizes the shared dynamic storage to typed two-byte `DLPaletteRange` records. The loader writes the records, `ApplyPaletteEntryMoves` consumes their bytes as rotation endpoints, and EPFTileContext compares them inclusively. The narrow `friend struct EPFTileContext` relationship explains the direct private-field access while leaving ownership, allocation, copy, and destruction with `DLPalette`.

## Historical Source-Shape Assumptions

- `DLPaletteData` as a separate constructor parameter type is rejected: the body reads the complete same-class layout and performs a true `DLPalette` deep copy.
- `unsigned char *m_entryMoves` / `m_entryMoveCount` remains a historical behavior-oriented alias, not the current emitted layout. The typed `DLPaletteRange` model preserves the same two-byte allocation and byte order while better matching loader and inclusive-range consumers.
- Public palette-range fields or invented getter APIs are not supported. Friendship is the smallest source mechanism consistent with the EPFTileContext direct reads.

## Cross-References

- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0001E4][0x00542ac0-0x00543149.DLPaletteMethodCluster](by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md)
- [UID:0004HQ][0x00542ac0-0x00542adc.DLPaletteMapColor](by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md)
- [UID:0004HT][0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw](by-memory/0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw.md)
- [UID:0004HY][0x00542d00-0x00542d81.DLPaletteRawCopyHelper](by-memory/0x00542d00-0x00542d81.DLPaletteRawCopyHelper.md)
- [UID:0004HZ][0x00542d90-0x00542de3.DLPaletteColorTransformRaw](by-memory/0x00542d90-0x00542de3.DLPaletteColorTransformRaw.md)
- [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md)
- [UID:0003MU][0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor](by-memory/0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-08-14 B010 UID0002GH mapped-color support callback:
  - Preserved `92/94`, UID0000MA owner/emitter, exact `0x22c` layout, formal owner shell, all existing methods, and child aggregation.
  - Synchronized exact source-ready MapColor/SetColor declarations and definitions, SetPackedColor transaction use, render-consumer liveness, Surface callback boundary, and inferred-name rationale without duplicating child code.

- 2026-08-04 B002 UID0004HV ordinary implementation callback:
  - Raised `90/93 -> 92/94`; preserved the exact `0x22c` layout, owner/emitter UID0000MA, reconstructable state, and Palette.cpp/Palette.h aggregation.
  - Added source-ready copy construction, typed `DLPaletteRange` storage, `m_paletteRanges`/`m_paletteRangeCount`, EPFTileContext friendship, and `<string.h>` support while preserving exact binary field offsets and prior history.
  - Synchronized constructor/helper/loader/application method notes and historicalized `DLPaletteData` plus untyped entry-move vocabulary instead of deleting those earlier interpretations.
- 2026-08-04 B002 UID0004HS ordinary implementation callback:
  - Raised `89/92 -> 90/93` while preserving the exact `0x22c` layout, owner/emitter UID0000MA, reconstructable state, and `Palette.cpp` / `Palette.h` child aggregation.
  - Expanded `SetPackedColor` to the source-ready public declaration/out-of-line definition route with exact unchecked word-store behavior, four ignored-result restoration calls, residual-EAX explanation, inferred lexical-name caveat, and Surface/provider boundary.
  - Kept the exact method body on UID0004HS rather than duplicating it in the class shell, and preserved all existing child/dependency/history evidence.
- 2026-07-29 B001 UID0004I0 source-quality implementation callback:
  - Raised completion `88 -> 89` with confidence `92` unchanged; preserved the exact `0x22c` layout, owner UID0000MA, emitter UID0000MA, and child aggregation.
  - Added the required `../archive/DATFile.h` complete-type include and `File` forward declaration to the formal CPP/H shells.
  - Replaced the LoadFromFile/LoadFromStream method notes with the resolved void/wide-path and void/File-pointer contracts, throwing Open, ignored Close result, automatic EH destruction, seven ignored-EAX stream callers, retained-unreferenced liveness, and separate-body boundary.
  - Expanded the source/dependency model without moving DATFile behavior into Palette or removing earlier zlib/Surface/Windows evidence.
- 2026-07-28 B001 UID0004I4 source-quality implementation callback:
  - Raised `85/88 -> 88/92` and added the exact `Palette.cpp`/`Palette.h` CPP/H child scaffold for the proven `0x22c` class layout.
  - Expanded `LoadFromBitmapPalette` with exact zlib 1.1.4, `RGBTRIPLE[256]`, BGR-to-RGB callback order, two LogoPane callers, source-void semantics, and the deliberately uninitialized `uLongf` behavior.
  - Added bounded include/dependency and child-header routing while preserving remaining blank sibling caps, inferred lexical names, raw-helper liveness caveats, and all prior layout/consumer history.
- 2026-07-06 B003 UID0004HY source-ready callback:
  - Score unchanged.
  - Updated the layout note to name the `+0x0c` 0x20-byte header block as inferred `m_paletteHeader`, and revised [UID:0004HY][0x00542d00-0x00542d81.DLPaletteRawCopyHelper](by-memory/0x00542d00-0x00542d81.DLPaletteRawCopyHelper.md) as first-draft source-ready inferred `DLPalette::CopyPaletteState`.
  - Evidence: accepted B003 report and target implementation preserve the no-direct-caller/no-original-symbol caveat while using live MCP and adjacent copy-constructor evidence to support class ownership and source-ready copy-state semantics.
- 2026-07-06 B001 UID0004HT source-ready callback:
  - Score unchanged.
  - Updated [UID:0004HT][0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw](by-memory/0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw.md) from blank/no-live-route wording to source-ready retained raw `DLPalette` method status.
  - Evidence: accepted B001 report and target implementation use `m_mappedColors[index]`, Surface slot-8 `g_pfnExpandPixel` / `SurfaceExpandPixelProc`, and preserve the descriptive-name/no-direct-caller caveat.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `80/84`.
  - Summary/evidence: palette purpose, observed layout, constructors/loaders/accessors/destructor methods, stream format, PaletteLib relationship, and DAT format links are documented; remaining uncertainty is mostly exact original field names.

- 2026-06-01:
  - Before: reconstructable/autogen parent metadata was blank and scalar deleting destructor endpoint was still documented as the stale `0x00544410` end through the memory-page link.
  - After: marked reconstructable under [UID:0000MA][Palette](by-file/Palette.md), raised to `82/86`, and recorded the exact `0x005443b0-0x00544411` scalar deleting destructor end.
  - Summary/evidence: IDA MCP `idautils.Functions`, `lookup_funcs`, decompilation, and byte checks confirmed the DLPalette method cluster, scalar deleting destructor island, contained entry-move method boundary, and alignment padding.

- 2026-06-13 C001 Goal 2 barrier repair:
  - Before: completion/confidence were `82/86`, and the address-range reference still pointed at the overbroad [UID:0001E4][0x00542ac0-0x00543149.DLPaletteMethodCluster](by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md) `0x00542ac0-0x00544411` page.
  - After: raised to `85/88`, updated the range inventory to the narrowed [UID:0001E4][0x00542ac0-0x00543149.DLPaletteMethodCluster](by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md) method cluster plus exact scalar deleting destructor [UID:0003MU][0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor](by-memory/0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor.md), and recorded the raw PaletteLib finder that replaces the stale `0x00543149-0x005431c0` padding claim.
  - Summary/evidence: live IDA confirmed the narrowed DLPalette boundary, exact destructor wrapper body and vtable xref, and the intervening raw `PaletteLib` helper.
- 2026-06-18 B003 CompositePixels consumer note:
  - Score unchanged at `85/88`.
  - Added [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) as a direct `DLPalette::MapColor` render consumer.
  - Evidence: B003 raw PE/Capstone recheck shows `GrafPort::CompositePixels` obtains the current palette, maps `this+0x7c`, and uses the native 16-bit color for zero-pixel fill inside its clipped pixel-effect loop.
- 2026-06-21 B007 BMP decoder support sync:
  - Score unchanged.
  - Added [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) as a consumer of `FreePaletteData` and `LoadFromRawRGBA`, with the embedded BMP RGBQUAD table source and non-DAT palette caveat.
- 2026-06-25 B014 DLPalette entry-move support sync:
  - Score unchanged.
  - Added [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md) as a direct `DLPalette` method/facet and recorded inferred field names `m_entryMoves`, `m_entryMoveCount`, and `m_mappedColors`.
  - Evidence: accepted B014 report used live IDA MCP session `80de0a67`, adjacent DLPalette load/copy/raw-RGBA functions, and the `ResetSlots` caller data flow to reject the old provisional `PaletteEntryMoveSlotState` interpretation.
- 2026-07-06 B008 UID0001E4 split-inventory callback:
  - Score unchanged.
  - Replaced raw address-only method rows with exact child UID links for the DLPalette method cluster, added the previously omitted raw [UID:0004HT][0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw](by-memory/0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw.md), and linked the B001-046 raw gap children [UID:0004HY][0x00542d00-0x00542d81.DLPaletteRawCopyHelper](by-memory/0x00542d00-0x00542d81.DLPaletteRawCopyHelper.md) and [UID:0004HZ][0x00542d90-0x00542de3.DLPaletteColorTransformRaw](by-memory/0x00542d90-0x00542de3.DLPaletteColorTransformRaw.md).
  - Evidence: accepted B008 report and callback set [UID:0001E4][0x00542ac0-0x00543149.DLPaletteMethodCluster](by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md) to non-emitting inventory, created exact child pages [UID:0004HQ][0x00542ac0-0x00542adc.DLPaletteMapColor](by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md) through [UID:0004I4][0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette](by-memory/0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette.md), preserved no-live-route/no-original-name caveats for raw helpers, and kept `0x00542d90` under the Palette source umbrella unless future caller evidence proves a declared DLPalette method.
