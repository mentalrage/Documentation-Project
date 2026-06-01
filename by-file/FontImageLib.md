*** UID:0000JH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FontImageLib

## Status

- Confidence: strong for class purpose and resource ownership, medium for final helper names.
- Proposed module: `render/FontImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_FontImageLib.cpp`
- Main address range: `0x004b5f00-0x004b6409`
- Primary global instance: [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) at `0x0067ab24`
- Primary vtable: [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md)

## File Role

`FontImageLib` is the client font glyph image library. It owns two large font slots, opens the `BA%d` DAT-backed font archives, builds a 65536-entry glyph pointer table per loaded slot, reports fixed 12x12 font cell metrics, measures glyph advance/bounds, and decodes glyph run data into an `EPFTileContext` for text rendering.

This belongs in render/UI text support, not in raw DAT archive parsing. It depends on `DATFile` for archive reads and on `EPFTileContext`/rect helpers for decoded glyph output.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `BA0` / `BA1` | Font archive slots loaded lazily by `EnsureFontSlotLoaded`. The loader formats the path as `BA%d`. |

## Behavior Summary

The constructor initializes the singleton and clears `0x80010` bytes of two-slot font storage plus a scratch buffer pointer/size. Each [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md) stores a `DATFile*`, max cell dimensions, and a `0x10000` [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md) pointer table. The loader reads max width/height, subtracts four from the cell height, then reads 65536 relative offsets and resolves nonzero offsets against the archive payload base.

`MeasureGlyphWidth` resolves a glyph record, falls back to codepoint `63` when the requested glyph has no visible bounds, optionally fills bounds and advance, and optionally asks `DecodeGlyphBitmap` to materialize pixels into an `EPFTileContext`. `DecodeGlyphBitmap` allocates or grows the shared scratch buffer, initializes tile bounds/stride, then expands compact per-row run tokens into palette-index bytes.

## Ownership Decision

Keep `FontImageLib` as a separate render/text source module. The class is small in method count but owns a large private data layout and a distinct DAT-backed resource family. It should not be folded into `ImageLib` or `DATArchive`.

Current `simroot_v2/class_FontImageLib.cpp` now emits the constructor, metrics, glyph measurement, lazy slot load, glyph decode, and scalar deleting destructor in the active file. IDA additionally confirms an ordinary non-deleting destructor at [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md), and active Wave3 metadata currently omits the [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md).

Do not fold higher-level string iteration, line-height, cursor, invalidation, or run drawing helpers into `FontImageLib`. Those helpers consume `FontImageLib` through `g_pFontImageLib` and belong under [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) / [UID:00016I][0x004bb5e0-0x004bb7df.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md) review.

## Cross-References

- [UID:00005B][FontImageLib](by-class/FontImageLib.md)
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
- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: font resource ownership, singleton/vtable/layout anchors, BA0/BA1 input resources, glyph table/decode behavior, ownership decision, excluded higher-level text helpers, and render/archive dependencies are documented; confidence remains below maximum because final helper names need review.
- 2026-05-31 exact child function references:
  - What existed before: the file page referenced only the broad aggregate and ordinary destructor memory pages.
  - Changed to: cross-references now include the constructor, metrics, glyph measurement, lazy loader, decode helper, and scalar deleting destructor child pages.
  - Summary/evidence: IDA MCP `lookup_funcs` and decompilation split the aggregate into exact child function pages while keeping reconstructed C++ blank until source quality is much higher.
