*** UID:00005B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FontImageLib.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_FONTIMAGELIB_H
#define NEXUSTK_RENDER_FONTIMAGELIB_H

#include "../util/LObject.h"
#include "../util/Singleton.h"

class DATFile;
class EPFTileContext;
struct RectBounds;

struct FontGlyphRecord
{
    short advance;
    short top;
    short left;
    short bottom;
    short right;
    short reserved0;
    short reserved1;
    unsigned char encodedRows[1];
};

struct FontSlotStorage
{
    DATFile *archiveFile;
    unsigned short maxCellWidth;
    unsigned short maxCellHeightMinus4;
    FontGlyphRecord *glyphTable[0x10000];
};

class FontImageLib :
    public LObject,
    public Singleton<FontImageLib>
{
public:
    FontImageLib();
    virtual ~FontImageLib();

    void GetFontMetrics(int fontId, short *outWidth, short *outHeight);
    void MeasureGlyphWidth(int fontId,
                           unsigned short ch,
                           unsigned short nextCh,
                           bool decodeBitmap,
                           const unsigned char *colors,
                           RectBounds *outBounds,
                           short *outAdvance,
                           EPFTileContext *outContext);

private:
    FontSlotStorage *EnsureFontSlotLoaded(int fontId);
    int DecodeGlyphBitmap(const FontGlyphRecord *glyph,
                          unsigned short glyphId,
                          bool clearBeforeDecode,
                          const unsigned char *paletteMap,
                          EPFTileContext *tileContext);

    FontSlotStorage m_fontSlots[2];
    unsigned char *m_scratchBuffer;
    int m_scratchBufferBytes;
};

extern FontImageLib *g_pFontImageLib;

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Complete FontImageLib declaration with direct LObject and empty Singleton<FontImageLib> bases, FontGlyphRecord/FontSlotStorage declarations before first use, PMD +0x04 EBO and exact 0x8001c layout, one typed global extern, source method inventory, inherited three-slot vtable, two DAT-backed font slots, scratch state, and compiler scalar/vtable/RTTI exclusions. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FontImageLib

## Status

- Confidence: strong for complete class/header shape, direct bases, constructor/destructor/source method shape, accepted private fields, declaration order, global extern, Singleton/vtable ownership, source placement, and public/private routing; unrecoverable private spellings remain the lexical cap.
- Likely source file: [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- Address range: [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md)
- Singleton global: [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) at `0x0067ab24`
- Vtable: [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md) at `0x0061a5f4`
- Exact vtable data: [UID:00031Q][0x0061a5f0-0x0061a600.FontImageLibVtableData](by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md)

## Class Purpose

`FontImageLib` is the singleton-backed font bitmap/glyph library behind `g_pFontImageLib`. It lazily loads two DAT-backed font archives named `BARAM00.EFT` and `BARAM01.EFT`, exposes text metrics, measures individual glyphs, and decodes compact glyph runs into tile contexts used by UI text drawing.

## Observed State

```text
0x00000  LObject/vtable base
0x00004  empty Singleton<FontImageLib> base and FontSlotStorage m_fontSlots[0]
0x4000c  FontSlotStorage m_fontSlots[1]
         each slot: DATFile*, max cell width/height, glyphTable[0x10000]
0x80014  unsigned char* m_scratchBuffer
0x80018  int m_scratchBufferBytes
0x8001c  end / allocated size
```

The application allocates `524316` (`0x8001c`) bytes for the object. RTTI records exactly `FontImageLib`, `LObject`, and direct `Singleton<FontImageLib>`; the Singleton PMD `+4/-1/0` proves empty-base optimization at `+0x04`, overlapping the first `FontSlotStorage` without adding storage. Each slot is `0x40008`, so the second begins at `+0x4000c`; scratch fields remain `+0x80014/+0x80018`. `FontGlyphRecord` and `FontSlotStorage` must be complete before the by-value class member and are therefore declared once before `FontImageLib`; their dedicated pages emit covered-by comments only. The accepted source-facing member names are inferred rather than recovered, but constructor, layout, slot/glyph records, destructor cleanup, loader, and decoder consumers converge on their types and order.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `FontImageLib::FontImageLib` | [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md) | Initializes direct `LObject` and `Singleton<FontImageLib>` bases, clears both slots with `memset`, and clears scratch state; compiler base construction supplies the global publication, so source has no explicit singleton assignment. |
| `~FontImageLib` | [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md) | Ordinary authored destructor; releases loaded font archives and scratch storage. Reverse direct Singleton-base destruction supplies the clear before `LObject` teardown, so source has no explicit global clear. |
| `GetFontMetrics` | [UID:0002HQ][0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics](by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md) | Public consumer-facing service; ensures the selected font slot is loaded and writes fixed 12x12 cell metrics through optional output pointers; formal void C++ is now emitted. |
| `MeasureGlyphWidth` | [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md) | Public consumer-facing service; resolves glyph bounds/advance, preserves the unused next-glyph argument, falls back to glyph `63`, and optionally decodes into an `EPFTileContext`; formal void C++ is now emitted. |
| `EnsureFontSlotLoaded` | [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md) | Private class helper; opens `BARAM%02d.EFT`, reads slot metrics, subtracts four from the second metric, and builds the 65536-entry glyph pointer table; formal C++ is now emitted. |
| `DecodeGlyphBitmap` | [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md) | Private class helper; expands encoded glyph rows into the scratch buffer, writes the EPFTileContext fields, applies caller palette/transparent-index rules, and returns decoded height; formal C++ is now emitted. |
| `ScalarDeletingDestructor` | [UID:0002HU][0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor](by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md) | Vtable-only compiler deleting wrapper with flags `1/4` and optional `0x8001c` object free; source cleanup is emitted solely through `~FontImageLib`, and the wrapper is false/non-emitting. |

## Embedded Non-Class Helper

The physical aggregate [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md) also contains [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md), a separate `g_useEpfAssets != 1` query helper. It is not a FontImageLib method: it has no `this`, touches no font-slot or glyph state, and is owned through [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md). Keep it out of FontImageLib class reconstruction.

## Evidence Notes

- IDA MCP on 2026-05-22 reports one constructor caller from application startup at `0x00464520`.
- IDA MCP on 2026-05-26 confirms `g_pFontImageLib` storage at `0x0067ab24`, vtable `0x0061a5f4`, and ordinary destructor `0x004b5f60-0x004b5fe6`.
- Batch 139 split the exact compiler-emitted vtable data into [UID:00031Q][0x0061a5f0-0x0061a600.FontImageLibVtableData](by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md), confirming the RTTI pointer, three slot dwords, lifecycle xrefs, and `BARAM%02d.EFT` boundary.
- `GetFontMetrics` has seven direct callers in UI text paths.
- `MeasureGlyphWidth` has nine direct callers across fitting-room, clan item list, text edit, and related UI text routines.
- The dedicated ordinary destructor page at [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md) should remain part of the class inventory even though it is separate from the scalar deleting destructor.
- Shared GrafPort text helpers at `0x004ba9a0+` and `0x004bb5e0` use this class through `g_pFontImageLib`, but they are not `FontImageLib` methods.
- B001's 2026-06-17 source-quality research rechecked the executable island and changed [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md) into a non-emitting mixed index because [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) is embedded between the glyph measurement method and lazy slot loader.
- B001's accepted 2026-06-29 UID0002HP implementation report resolves the constructor source blocker: `FontImageLib::FontImageLib()` now emits formal C++ through this class page. MCP session `3fa0535f` confirmed the constructor range/size, startup allocation `0x8001c`, singleton write, vtable store, `memset(this+4,0,0x80010)`, scratch clears, direct startup caller, vtable/global xrefs, and absence of a VA/RVA data-pointer-table route.
- The class declaration intentionally contains `[[CHILDREN]]` after the class body so emitted method bodies and support declarations remain routed through the same FontImageLib source file without pasting method bodies into this class page.
- B010's 2026-07-01 implementation pass added the public method prototypes and private helper prototypes needed by the emitted child method bodies. `GetFontMetrics` and `MeasureGlyphWidth` remain consumer-facing public services used by GrafPort/text callers; `EnsureFontSlotLoaded` and `DecodeGlyphBitmap` remain private helpers because only sibling FontImageLib methods call them. Live MCP session `supervisor_resume_20260629` command ids `6-29` confirmed exact boundaries, caller/callee/xref sets, vtable/string/global data, and the source-vs-compiler-wrapper split.
- B003's 2026-07-20 target-specific MCP pass on healthy session `9b0396a3` resolved the remaining class blockers. RTTI has exactly three hierarchy entries and direct Singleton PMD `+4/-1/0`; constructor adjustment/publication and reverse destructor ordering are compiler-lowered base lifecycle, not authored assignments. The exact `0x8001c` allocation, `0x80010` clear, two `0x40008` slots, scratch offsets, inherited vtable slots, and resource consumers close declaration order and layout. `ImageLib`, GrafPort ownership, an Application-owned singleton, a class-static definition, duplicate support structs, and handwritten vtable/scalar/RTTI/base teardown are rejected.

## Cross-References

- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
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
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-07-20 B003 UID0001P2 source-closure callback:
  - Raised `92/92` to `94/94`, retained UID0000JH owner/emitter, and installed the complete declaration with `FontGlyphRecord` and `FontSlotStorage` once before use, direct `LObject` plus `Singleton<FontImageLib>` bases, one compatible extern, exact fields/methods, and class closure before `[[CHILDREN]]`.
  - Added exact three-entry RTTI/PMD/EBO evidence, source/header/definition order, authored lifecycle versus compiler scalar/vtable/RTTI split, and no-duplicate generated contract while preserving all existing methods, resources, consumers, and historical evidence.

- 2026-06-08 A007 Batch 139 vtable evidence update:
  - What existed before: the class already met the strict parent gate at `86/88`, but it only linked the by-vtable page rather than the exact concrete vtable-data child.
  - Changed to: added [UID:00031Q][0x0061a5f0-0x0061a600.FontImageLibVtableData](by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md) to status, evidence notes, and cross-references. Scores remain `86/88`.
  - Summary/evidence: the child records the RTTI/vtable dwords, slot target sizes, constructor/destructor/scalar-deleting-destructor xrefs, and `BARAM%02d.EFT` boundary used to justify [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md) attaching here.
- Completion/confidence score update: existed before as `0/0`; changed to `86/88`. Summary: singleton role, object size, layout, font slot structures, method responsibilities, destructor gap, global/vtable addresses, caller evidence, and non-owned GrafPort helper boundary are documented in detail; remaining work is mostly exact private field names and final C++ reconstruction. Evidence: `0x004b5f00-0x004b6409` memory page, destructor page, `FontImageLibLayout`, `FontSlotStorage`, `FontGlyphRecord`, `FontImageLibVtable`, and `g_pFontImageLib`.
- 2026-05-31: Method inventory now points to exact child memory pages.
- 2026-06-06: Attached the class autogen parent to [UID:0000JH][FontImageLib](by-file/FontImageLib.md) so class-owned generated children resolve through the FontImageLib file page.
  - Before: constructor, metrics, measure, loader, decode, and scalar-deleting destructor rows were address-only.
  - After: rows link to dedicated by-memory pages with exact IDA MCP boundaries.
  - Summary/evidence: IDA MCP `lookup_funcs`, decompilation, and xrefs split the aggregate function range into exact child pages without writing provisional C++.
- 2026-06-06: Corrected lazy font archive resource names.
  - Before: the loader row used stale `BA%d` shorthand.
  - After: the class purpose and loader row name the live UTF-16 `BARAM%02d.EFT` format and the two resulting resources `BARAM00.EFT` / `BARAM01.EFT`.
  - Summary/evidence: [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded](by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md) records the IDA data xref and byte-level literal decode.
- 2026-06-06: Refined decode-helper method role.
  - Before: `DecodeGlyphBitmap` was summarized as scratch-buffer expansion using a palette map.
  - After: the method row also records EPFTileContext field writes and transparent-index rules.
  - Summary/evidence: [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md) now records live IDA disassembly/decompilation for `this+0x80014/+0x80018`, `tileContext+0x04/+0x0c/+0x10/+0x20/+0x24`, and the palette-index branch.
- 2026-06-17 B001 source-quality execution:
  - Kept class score `86/88` but recorded that the physical aggregate is now a non-emitting mixed index.
  - Summary/evidence: B001's fresh IDA pass proved the helper at `0x004b60b0-0x004b60bd` is a `g_useEpfAssets != 1` query, not a FontImageLib method. FontImageLib child methods remain class-owned, while the helper is routed through [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md).
- 2026-06-29 B001 UID0002HP implementation callback:
  - Before: `86/88`, with no class formal C++ and remaining text treating final private field names as a code blocker.
  - Changed to: `90/90` with formal `FontImageLib` class declaration, accepted member names `m_fontSlots`, `m_scratchBuffer`, and `m_scratchBufferBytes`, and a `[[CHILDREN]]` insertion point for emitted children.
  - Summary/evidence: accepted report `0002HP-FontImageLibConstructor-empty-emitter-source-quality.md` ties the declaration to constructor MCP evidence from session `3fa0535f`, layout/slot/glyph struct pages, singleton/vtable lifecycle evidence, and sibling destructor/decode scratch use. Exact original private member spelling remains inferred, but source-facing names are now accepted for emitted constructor source.
- 2026-07-01 B010 FontImageLib empty-emitter family implementation:
  - Before: `90/90`, with class fields accepted but the sibling method prototypes/helpers still missing from the formal class block.
  - Changed to: `92/92`; the formal declaration now includes `GetFontMetrics`, `MeasureGlyphWidth`, private `EnsureFontSlotLoaded`, private `DecodeGlyphBitmap`, and the existing fields/`[[CHILDREN]]` route.
  - Summary/evidence: accepted B010 report used live MCP command ids `6-29` plus current class/slot/glyph/EPFTileContext docs to prove the method source signatures, public/private split, no direct FontImageLib ownership for [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md), and compiler-generated treatment for scalar deleting destructor/vtable/layout pages.
