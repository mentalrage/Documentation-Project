*** UID:0000JH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FontImageLib

## Status

- Confidence: strong for class purpose, direct LObject/Singleton inheritance, resource ownership, exact layout/vtable/RTTI, source/header order, global one-definition route, authored lifecycle bodies, compiler-only scalar/data artifacts, and emitted method family; method/member spellings remain source-facing inferred names rather than recovered PDB symbols.
- Proposed module: `render/FontImageLib.cpp`
- Main address range: `0x004b5f00-0x004b6409`
- Primary global instance: [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) at `0x0067ab24`
- Primary vtable: [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md)
- Exact vtable data: [UID:00031Q][0x0061a5f0-0x0061a600.FontImageLibVtableData](by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md)
- Current emitted-source status: [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md), [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md), [UID:0002HQ][0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics](by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md), [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md), [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md), and [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md) now contribute formal C++ through [UID:00005B][FontImageLib](by-class/FontImageLib.md), with supporting class, struct, singleton, layout, vtable, and exact vtable-data declarations/no-code proof in this source route.

## File Role

`FontImageLib` is the client font glyph image library. It owns two large font slots, opens the `BARAM%02d.EFT` DAT-backed font archives, builds a 65536-entry glyph pointer table per loaded slot, reports fixed 12x12 font cell metrics, measures glyph advance/bounds, and decodes glyph run data into an `EPFTileContext` for text rendering.

This belongs in render/UI text support, not in raw DAT archive parsing. It depends on `DATFile` for archive reads and on `EPFTileContext`/rect helpers for decoded glyph output.

## Header And Translation-Unit Route

[UID:00005B][FontImageLib](by-class/FontImageLib.md) is the single formal declaration owner for `NexusTK/render/FontImageLib.h`. Its H channel emits the include guard, `LObject` and `Singleton` dependencies, the complete `FontGlyphRecord` and `FontSlotStorage` support records, the complete `FontImageLib` public/private declaration and exact storage order, and `extern FontImageLib *g_pFontImageLib`. This ordering is required because the two `FontSlotStorage` values are by-value members and must be complete before the class definition.

The matching CPP channel includes `FontImageLib.h` and then expands `[[CHILDREN]]`; exact method bodies remain owned by their by-memory children. The class page therefore supplies one coherent human-written header and translation-unit frame without duplicating child implementations or leaving declaration source in the CPP channel.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `BARAM00.EFT` / `BARAM01.EFT` | Font archive slots loaded lazily by `EnsureFontSlotLoaded`. The loader formats the UTF-16 path as `BARAM%02d.EFT`. |

## Behavior Summary

The constructor initializes direct `LObject` and empty `Singleton<FontImageLib>` bases, clears `0x80010` bytes of two-slot font storage, and clears the scratch pointer/size. Source now has no explicit `g_pFontImageLib = this`: RTTI PMD `+4/-1/0`, constructor adjustment, and lifecycle xrefs prove that store is compiler lowering of direct Singleton-base construction. Each [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md) stores a `DATFile*`, max cell dimensions, and a `0x10000` [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md) pointer table. The loader reads max width/height from `BARAM00.EFT` or `BARAM01.EFT`, subtracts four from the cell height, then reads 65536 relative offsets and resolves nonzero offsets against the archive payload base.

The ordinary source destructor owns only the two DAT-backed slot deletes and scratch-buffer release. Its observed global clear is compiler lowering of reverse direct Singleton-base destruction before `LObject` teardown. The vtable scalar deleting wrapper, RTTI/vtable arrays, base teardown, delete flags, cookie/EH mechanics, and physical storage are compiler/generated-binary evidence, not handwritten source.

`MeasureGlyphWidth` resolves a glyph record, falls back to codepoint `63` when the requested glyph has no visible bounds, optionally fills bounds and advance, and optionally asks `DecodeGlyphBitmap` to materialize pixels into an `EPFTileContext`. `DecodeGlyphBitmap` allocates or grows the shared scratch buffer, writes the tile-context bounds/stride/pixel pointer/mask fields, then expands compact per-row run tokens into palette-index bytes with mode-dependent transparent indexes.

The physical `0x004b5f00-0x004b6409` interval also contains [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md). That helper only tests [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) and is routed through the global's owner, not through this file's FontImageLib class reconstruction.

The complete generated contract is one position-0 `g_pFontImageLib` definition preceded by a local forward declaration; one compatible class-header extern; one `FontGlyphRecord` and one `FontSlotStorage` declaration before class/method use; a complete class with direct `LObject, Singleton<FontImageLib>` bases closed before `[[CHILDREN]]`; one authored constructor and ordinary destructor with zero explicit singleton writes; all existing source methods once; covered-by/compiler comments for support/layout/vtable data; zero physical UID0001P2 or scalar UID0002HU body/empty marker; and no handwritten vtable, RTTI, scalar flags/free, EH/cookie, or base teardown.

## Ownership Decision

Keep `FontImageLib` as a separate render/text source module. The class is small in method count but owns a large private data layout and a distinct DAT-backed resource family. It should not be folded into `ImageLib` or `DATArchive`.

IDA confirms the constructor, metrics, glyph measurement, lazy slot load, glyph decode, scalar deleting destructor, and ordinary non-deleting destructor at [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md). The constructor installs [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md) and writes [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md).

The direct constructor owner remains [UID:00005B][FontImageLib](by-class/FontImageLib.md), not this file page, because the constructor has a `this` receiver, class vtable, class layout, and class-owned singleton lifecycle. This file remains the source route. The accepted constructor implementation rejects no-code/covered-by treatment for [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md), rejects duplicate aggregate emission from [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md), and rejects `ImageLib`, `GrafPort`, `DATArchive`, and `DATFile` ownership as dependency/consumer-only alternatives.

Batch 139 split the exact [UID:00031Q][0x0061a5f0-0x0061a600.FontImageLibVtableData](by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md) child out of the mixed read-only aggregate. That child confirms the class RTTI/vtable dwords and the following `BARAM%02d.EFT` boundary, so the file page now clears the supporting source-evidence gate for [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md).

Do not fold higher-level string iteration, line-height, cursor, invalidation, or run drawing helpers into `FontImageLib`. Those helpers consume `FontImageLib` through `g_pFontImageLib` and belong under [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) / [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md) review.

Likewise, do not force the `IsLegacyAssetMode` helper into `FontImageLib.cpp` merely because it is physically embedded in the same executable island. B001's 2026-06-17 source-quality pass proved it is a broad display/asset-mode query over `byte_66DA97`, not font-library state.

## Cross-References

- [UID:00005B][FontImageLib](by-class/FontImageLib.md)
- [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md)
- [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md)
- [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md)
- [UID:0002HQ][0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics](by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md)
- [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md)
- [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md)
- [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md)
- [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md)
- [UID:0002HU][0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor](by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md)
- [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md)
- [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md)
- [UID:00031Q][0x0061a5f0-0x0061a600.FontImageLibVtableData](by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md)
- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-07-20 B003 UID0001P2 source-closure callback:
  - Raised `92/92` to `94/94` while preserving `NexusTK/render/` and all resource/method/helper history.
  - Added the complete source/header/declaration order, sole semantic global definition, direct Singleton PMD/EBO lifecycle cause, exact `0x8001c` layout, authored constructor/destructor split, compiler scalar/vtable/RTTI/physical-storage exclusions, and generated uniqueness/order contract.
  - Historicalized the prior explicit constructor assignment/destructor-clear interpretation; retained every BARAM, glyph, slot, scratch, consumer, separate `IsLegacyAssetMode`, and ownership exclusion fact.

- 2026-06-08 A007 Batch 139 source-parent refresh:
  - What existed before: file scores were `84/82`, below the strict supporting source gate used by the vtable assignment audit.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, exact vtable-data child link, and source-ownership text connecting the vtable child to the font resource boundary.
  - Summary/evidence: [UID:00031Q][0x0061a5f0-0x0061a600.FontImageLibVtableData](by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md) records the RTTI/vtable dwords, target sizes, lifecycle xrefs, and `BARAM%02d.EFT` boundary. Scores remain below final-source level because final helper names and C++ reconstruction are not complete.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: font resource ownership, singleton/vtable/layout anchors, font input resources, glyph table/decode behavior, ownership decision, excluded higher-level text helpers, and render/archive dependencies are documented; confidence remains below maximum because final helper names need review.
- 2026-05-31 exact child function references:
  - What existed before: the file page referenced only the broad aggregate and ordinary destructor memory pages.
  - Changed to: cross-references now include the constructor, metrics, glyph measurement, lazy loader, decode helper, and scalar deleting destructor child pages.
  - Summary/evidence: IDA MCP `lookup_funcs` and decompilation split the aggregate into exact child function pages. The historical blank-C++ policy from that pass is superseded for [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md) by the 2026-06-29 implementation callback below.
- 2026-06-05 reconstruction path classification:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, leaving the file row in error.
  - Changed to: `NexusTK/render/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `FontImageLib.cpp` under `NexusTK/render/`, and live IDA MCP decompilation confirms `0x004b5f00`, `0x004b5f60`, and `0x004b6350` write/clear `dword_67AB24` from `FontImageLib` lifecycle code.
- 2026-06-06 resource-name correction:
  - What existed before: resource inputs were described as `BA0` / `BA1` and `BA%d`.
  - Changed to: `BARAM00.EFT` / `BARAM01.EFT` and UTF-16 format `BARAM%02d.EFT`.
  - Summary/evidence: [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md) records the live IDA data xref at `0x004b6113` and byte-level string read at `0x0061a600`.
- 2026-06-06 decode-helper detail update:
  - What existed before: the decode summary only said compact row tokens became palette-index bytes.
  - Changed to: documented that [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md) writes the EPFTileContext pixel pointer, stride, bounds, and mask fields and uses mode-dependent transparent indexes.
  - Summary/evidence: live IDA disassembly at `0x004b6290`, `0x004b6299`, and `0x004b62a0` writes context fields, and the token branch at `0x004b62cd-0x004b62e1` distinguishes non-clear transparent index `5` from clear-mode nonzero writes.
- 2026-06-17 B001 source-quality execution:
  - Kept file score `86/86` and recorded that [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md) is now a non-emitting mixed physical index rather than an emitting file/class aggregate.
  - Summary/evidence: B001's fresh IDA pass found [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md), a `g_useEpfAssets != 1` helper, inside the physical interval. FontImageLib methods still route through this file; the mode helper routes through [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md).
- 2026-06-29 B001 UID0002HP implementation callback:
  - Before: `86/86`, with `FontImageLib.cpp` still fully empty in generated output and the constructor blocked by stale future class-wide-pass language.
  - Changed to: `88/88`; [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md) now emits formal constructor C++ through [UID:00005B][FontImageLib](by-class/FontImageLib.md), and this source route has accepted support declarations for `FontImageLib`, `FontSlotStorage`, `FontGlyphRecord`, and `g_pFontImageLib`.
  - Summary/evidence: MCP session `3fa0535f` confirmed constructor range/size, startup allocation/call, singleton write, vtable store, slot clear, scratch clears, vtable/global xrefs, and no VA/RVA constructor-pointer table. The path remains `NexusTK/render/`; sibling method bodies remain separate future work and do not block the constructor.
- 2026-07-01 B010 FontImageLib empty-emitter family implementation:
  - Before: `88/88`, with nine visible empty markers remaining in generated `FontImageLib.cpp`.
  - Changed to: `92/92`; formal C++ is now present for the ordinary destructor, fixed metrics getter, glyph measurement front door, lazy font-slot loader, and glyph bitmap decoder. Formal no-code proof comments are now present for the scalar deleting destructor, class layout evidence, compiler vtable page, and exact vtable-data page.
  - Summary/evidence: accepted B010 report `0000JH-FontImageLib-empty-emitter-family-source-quality.md` used live MCP session `supervisor_resume_20260629` command ids `6-29` to confirm function boundaries, current decompilation/disassembly, caller/callee/xref sets, vtable/string/global data, and padding. The file source route remains `NexusTK/render/`; [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md) remains a non-emitting mixed physical index, and [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) remains outside the FontImageLib class route.
