*** UID:00005B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FontImageLib

## Status

- Confidence: strong for class role, medium for exact private field names.
- Likely source file: [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- Address range: [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md)
- Current recovered file: `source-3/simroot_v2/class_FontImageLib.cpp`
- Singleton global: [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) at `0x0067ab24`
- Vtable: [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md) at `0x0061a5f4`

## Class Purpose

`FontImageLib` is the singleton-backed font bitmap/glyph library behind `g_pFontImageLib`. It lazily loads two DAT-backed font archives, exposes text metrics, measures individual glyphs, and decodes compact glyph runs into tile contexts used by UI text drawing.

## Observed State

```text
0x00000  LObject/vtable base
0x00004  FontSlotStorage fontSlots[2]
         each slot: DATFile*, max cell width/height, glyphTable[0x10000]
0x80014  void* scratchBuffer
0x80018  int scratchBufferBytes
0x8001c  end / allocated size
```

The application allocates `524316` bytes for the object, matching the two `262152`-byte font slots plus base/scratch fields. See [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md), [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md), and [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `FontImageLib::FontImageLib` | [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md) | Initializes `LObject`, sets `g_pFontImageLib`, clears both font slots and scratch fields. |
| `~FontImageLib` | [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md) | Ordinary non-deleting destructor; releases loaded font archives, frees scratch storage, and clears the singleton. |
| `GetFontMetrics` | [UID:0002HQ][0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics](by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md) | Ensures the selected font slot is loaded and returns fixed 12x12 cell metrics. |
| `MeasureGlyphWidth` | [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md) | Resolves glyph bounds/advance, with optional decode into an `EPFTileContext`. |
| `EnsureFontSlotLoaded` | [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md) | Opens `BA%d`, reads slot metrics and the 65536-entry glyph offset table. |
| `DecodeGlyphBitmap` | [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md) | Expands encoded glyph rows into the scratch buffer using the caller's palette map. |
| `ScalarDeletingDestructor` | [UID:0002HU][0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor](by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md) | Destroys loaded font slots, frees scratch memory, clears singleton, and optionally deletes `this`. |

## Evidence Notes

- IDA MCP on 2026-05-22 reports one constructor caller from application startup at `0x00464520`.
- IDA MCP on 2026-05-26 confirms `g_pFontImageLib` storage at `0x0067ab24`, vtable `0x0061a5f4`, and ordinary destructor `0x004b5f60-0x004b5fe6`.
- `GetFontMetrics` has seven direct callers in UI text paths.
- `MeasureGlyphWidth` has nine direct callers across fitting-room, clan item list, text edit, and related UI text routines.
- Current `simroot_v2/class_FontImageLib.cpp` emits the live metrics/loading/decode methods in the active file; older disabled-companion notes are stale for the present generated tree.
- Active `class_FontImageLib.meta_wave3` still reports `vtable_count: 0` and active generated source omits the ordinary destructor at `0x004b5f60`.
- Shared GrafPort text helpers at `0x004ba9a0+` and `0x004bb5e0` use this class through `g_pFontImageLib`, but they are not `FontImageLib` methods.

## Cross-References

- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md)
- [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md)
- [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md)
- [UID:0002HQ][0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics](by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md)
- [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md)
- [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md)
- [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md)
- [UID:0002HU][0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor](by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md)
- [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md)
- [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md)
- [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:00016I][0x004bb5e0-0x004bb7df.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `86/88`. Summary: singleton role, object size, layout, font slot structures, method responsibilities, destructor gap, global/vtable addresses, caller evidence, and non-owned GrafPort helper boundary are documented in detail; remaining work is mostly exact private field names and final C++ reconstruction. Evidence: `0x004b5f00-0x004b6409` memory page, destructor page, `FontImageLibLayout`, `FontSlotStorage`, `FontGlyphRecord`, `FontImageLibVtable`, and `g_pFontImageLib`.
- 2026-05-31: Method inventory now points to exact child memory pages.
  - Before: constructor, metrics, measure, loader, decode, and scalar-deleting destructor rows were address-only.
  - After: rows link to dedicated by-memory pages with exact IDA MCP boundaries.
  - Summary/evidence: IDA MCP `lookup_funcs`, decompilation, and xrefs split the aggregate function range into exact child pages without writing provisional C++.
