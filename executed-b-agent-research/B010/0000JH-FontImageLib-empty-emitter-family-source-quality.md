** TARGET-REPORT-UID:0000JH **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000JH FontImageLib Empty-Emitter Family Source-Quality Report

Agent: B010  
Assignment: `B010-report-0000JH-FontImageLib-empty-emitter-family-20260701`  
Date: 2026-07-01  
Mode: accepted implementation callback applied on 2026-07-01. Target/support by-* docs listed in `Changed Files` were edited; generated files/reports, coverage reports, validator state, supervisor ledgers, archives, by-project-structure docs, and IDA DB files were not manually edited.

## Finalized Report / Current Recommendation

- Current recommendation: accept the current `FontImageLib` file root as the source route for the whole visible empty-emitter family, convert the five source-authored method pages from empty markers to formal C++, and convert the four compiler/generated/layout evidence pages to exact formal no-code proof comments rather than leaving them looking like unresolved emitters.
- Final disposition: keep [UID:0000JH] `by-file/FontImageLib.md` as `NexusTK/render/FontImageLib.cpp`; keep direct method/type ownership routed through [UID:00005B] `FontImageLib`; preserve [UID:00015A] as a non-emitting mixed physical index and [UID:0003XA] `IsLegacyAssetMode` outside FontImageLib.
- Required action after supervisor acceptance: update the target file/class/support pages listed in the checklist, insert the formal C++/no-code text below, update scores and stale "future class-wide pass" language, run scoped validators with `--wait-generated`, and verify `auto-generated/NexusTK/render/FontImageLib.cpp` has no remaining visible empty markers from this nine-marker family.
- Confidence: high for behavior, range, ownership, and C++ readiness; medium-high for exact original method/member spelling because names remain source-facing inferred names, not recovered PDB symbols.

## Target

- Target UID: `0000JH`
- Target path: `by-file/FontImageLib.md`
- Generated output lead: `auto-generated/NexusTK/render/FontImageLib.cpp`
- Queue row: `auto-generated/-ag-research-tracker.md` -> Files With Empty Emitters; current row is `15` total emitters, `6` filled, `9` empty, `40.0%`.
- Current visible empty markers audited: [UID:00015B], [UID:0002HQ], [UID:0002HR], [UID:0002HS], [UID:0002HT], [UID:0002HU], [UID:0001UL], [UID:0001XM], and [UID:00031Q].

## Current Target State

- [UID:0000JH] is `COMPLETION:88`, `CONFIDENCE:88`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, `CANONICAL_OWNER:FILE`.
- Generated `FontImageLib.cpp` currently emits the class declaration [UID:00005B], constructor [UID:0002HP], `FontGlyphRecord` [UID:0001UK], `FontSlotStorage` [UID:0001UM], and `g_pFontImageLib` [UID:0000QX].
- The class declaration currently has only constructor/destructor public declarations and private fields. It needs method prototypes for the now-source-ready sibling methods.
- Several method pages still say final C++ is blank pending a class-wide source/header pass. That blocker is now superseded: the accepted constructor callback already established `m_fontSlots`, `m_scratchBuffer`, `m_scratchBufferBytes`, `FontGlyphRecord`, `FontSlotStorage`, and `g_pFontImageLib`, and this pass rechecked the sibling bodies with live MCP.

## Evidence Checked

IDA MCP status and schema:

- MCP `initialize` succeeded against `http://127.0.0.1:13337/mcp`.
- `tools/list` was rechecked before tool use. Relevant active schemas used: `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_global_value`, `get_bytes`, and `list_globals`.
- `idb_list` command id `6` returned one active session, `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, PID/worker PID `14860`, `is_active:true`, `is_analyzing:false`.
- `server_health` command id `7` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

MCP facts used:

- `lookup_funcs` command id `9` confirmed exact functions and exclusive ends: `0x004b5f60` size `0x86`; `0x004b5ff0` size `0x28`; `0x004b6020` size `0x8e`; `0x004b60b0` size `0x0d`; `0x004b60c0` size `0x119`; `0x004b61e0` size `0x161`; `0x004b6350` size `0xb9`; exclusive ends `0x004b5fe6`, `0x004b6018`, `0x004b60ae`, `0x004b61d9`, `0x004b6341`, and `0x004b6409` are not functions.
- `decompile` command ids `10-15` returned current pseudocode for the ordinary destructor, metrics getter, glyph measurement, slot loader, glyph decoder, and scalar deleting destructor.
- `disasm` command ids `21-24` confirmed key instruction details: metrics writes fixed `0x0c`; loader signed/upper-bound clamp (`test edx, edx; js`; `cmp edx,2`), `0x40008` slot stride, `BARAM%02d.EFT` format call, two 16-bit reads, second metric minus-four, and the `0x10000` glyph offset loop; decoder `record+0x0e` row stream and token rules; padding after method boundaries.
- `xrefs_to` command id `25` confirmed: no direct xrefs to the ordinary destructor; 7 xrefs to `GetFontMetrics`; 9 xrefs to `MeasureGlyphWidth`; 2 xrefs to `EnsureFontSlotLoaded`; 1 xref to `DecodeGlyphBitmap`; scalar deleting destructor reached from vtable data; vtable base `0x0061a5f4` referenced by constructor, ordinary destructor, and scalar deleting destructor; `0x0061a600` referenced only by the loader; `0x0067ab24` global refs include constructor/destructor and GrafPort/UI text consumers.
- `get_global_value` command id `26` read `0x0061a5f0 -> 0x6479b0`, `0x0061a5f4 -> 0x4b6350`, `0x0061a5f8 -> 0x4f4b10`, `0x0061a5fc -> 0x41b6c0`, `0x0067ab24 -> 0x0`.
- `get_bytes` command id `27` confirmed vtable dwords followed by UTF-16 bytes for `BARAM%02d.EFT`, plus `0xcc` padding at key exclusive ends.
- `callees` command id `28` confirmed narrow callee sets for each source method and compiler wrapper.
- `list_globals` command id `29` confirmed `??_7FontImageLib@@6B@` at `0x0061a5f4` and RTTI globals for `FontImageLib`.

Documentation and generated leads checked:

- `by-file/FontImageLib.md`, `by-class/FontImageLib.md`, generated `auto-generated/NexusTK/render/FontImageLib.cpp`, and `auto-generated/-ag-research-tracker.md`.
- Current exact method/type/data pages: [UID:00015B], [UID:0002HQ], [UID:0002HR], [UID:0002HS], [UID:0002HT], [UID:0002HU], [UID:0001UL], [UID:0001XM], [UID:00031Q], [UID:0002HP], [UID:00015A], [UID:0001UK], [UID:0001UM], [UID:0000QX], [UID:00025D], and [UID:0003BI].
- Support type/helper docs: `EPFTileContext.md`, `RectBoundsLayout.md`, MemoryMan helper pages [UID:0001BC], [UID:0001BD], [UID:0001BF], [UID:0001BG].
- Historical reports searched with `rg` terms: `0000JH`, `00015B`, `0002HQ`, `0002HR`, `0002HS`, `0002HT`, `0002HU`, `0001UL`, `0001XM`, `00031Q`, `FontImageLib`, and exact addresses. Matching reports opened as leads: B001 `00015A-0002HP-fontimagelib-source-quality.md`, B001 `0002HP-FontImageLibConstructor-empty-emitter-source-quality.md`, B002 `00016I-GrafPortDrawGlyph-source-quality.md`, and B004 `00004I-EPFTileContext-class-source-quality.md`.

Negative checks:

- The ordinary destructor has no direct xrefs; this matches vtable/compiler destructor usage and does not make it dead.
- Scalar deleting destructor has only the vtable data xref; this identifies compiler wrapper handling, not a missing source method.
- `0x004b60b0-0x004b60bd` remains the separate [UID:0003XA] `IsLegacyAssetMode` helper. It is excluded from this FontImageLib empty-emitter family because it is not one of the current visible empty markers and is already owned outside FontImageLib.
- No evidence supports routing the methods directly through the file page, aggregate page, GrafPort, ImageLib, DATArchive, DATFile, or EPFTileContext as direct owners.

## Positive Evidence Summary

- The five method bodies are source-authored `FontImageLib` class behavior with stable exact ranges, current class owner/emitter, and a generated route through `NexusTK/render/FontImageLib.cpp`.
- Accepted support declarations already supply the class fields and payload structs required to write source-level code without raw offsets.
- Current generated GrafPort code calls `GetFontMetrics` and `MeasureGlyphWidth` as void-style services; the decompiler return values are return-register artifacts from the last expression, not caller-consumed API results.
- The loader and decoder are now detailed enough to emit readable source with accepted names: `EnsureFontSlotLoaded`, `DecodeGlyphBitmap`, `FontSlotStorage`, `FontGlyphRecord`, `EPFTileContext`, `RectBounds`, `GetMemoryMan()->AllocateBufferMemory`, `ReallocateBufferMemory`, and `FreeBufferMemory`.
- The layout/vtable/vtable-data pages represent source-declared/generated-binary evidence; they should receive target-specific no-code proof comments, not duplicate class/vtable declarations.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Current score | Recommended disposition |
| --- | --- | --- | --- | --- |
| `0x004b5f60-0x004b5fe6` | [UID:00015B] `by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md` | ordinary destructor | `86/91` | `90/92`, formal destructor C++ |
| `0x004b5ff0-0x004b6018` | [UID:0002HQ] `by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md` | fixed metrics service | `86/90` | `90/93`, formal void C++ |
| `0x004b6020-0x004b60ae` | [UID:0002HR] `by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md` | glyph measure/decode front door | `86/90` | `90/92`, formal void C++ |
| `0x004b60c0-0x004b61d9` | [UID:0002HS] `by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md` | lazy slot loader | `88/92` | `91/93`, formal C++ |
| `0x004b61e0-0x004b6341` | [UID:0002HT] `by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md` | glyph row decoder | `88/92` | `91/93`, formal C++ |
| `0x004b6350-0x004b6409` | [UID:0002HU] `by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md` | MSVC scalar deleting wrapper | `86/92` | `88/93`, exact no-code proof comment |
| class layout page | [UID:0001UL] `by-type/by-struct/FontImageLibLayout.md` | class layout evidence | `85/90` | `88/92`, exact covered-by no-code proof |
| vtable type page | [UID:0001XM] `by-type/by-vtable/FontImageLibVtable.md` | compiler vtable semantics | `87/92` | `89/93`, exact generated-by-class no-code proof |
| exact vtable data | [UID:00031Q] `by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md` | RTTI/vtable dwords | `88/92` | `90/94`, exact generated-by-class no-code proof |

## Ranked Ownership Analysis

### 1. [UID:00005B] FontImageLib class - accepted direct owner for methods/layout/vtable semantics

- Evidence for: all method bodies use `ecx` as class receiver, share `FontImageLib` vtable/global lifecycle, touch `m_fontSlots`, `m_scratchBuffer`, `m_scratchBufferBytes`, or class payload structs, and are already routed through the class/file chain.
- Evidence against: physical aggregate includes [UID:0003XA] at `0x004b60b0`, but that function is outside the visible empty-marker list and is already split/routed through `g_useEpfAssets`.
- Decision: keep method/type owner and emitter [UID:00005B].

### 2. [UID:0000JH] FontImageLib file - accepted source route, not direct method owner

- Evidence for: file root owns `NexusTK/render/FontImageLib.cpp`, resource family `BARAM%02d.EFT`, singleton declaration, generated output route, and source-module narrative.
- Evidence against: method pages have class receivers and class state; direct semantic owner is narrower than the file page.
- Decision: update file page as the source route and family status, not as direct owner for method bodies.

### 3. [UID:00015A] aggregate - rejected as emitter

- Evidence for: physically contains the method cluster.
- Evidence against: reviewed non-reconstructable mixed executable index, includes non-FontImageLib helper [UID:0003XA], and exact child pages already own the source-bearing code.
- Decision: leave non-emitting; do not place C++ on the aggregate.

### 4. GrafPort, EPFTileContext, DATFile/DATArchive, ImageLib - rejected direct owners

- GrafPort and UI callers consume the singleton for text layout/drawing.
- EPFTileContext is an output context used by the decoder, not the glyph library owner.
- DATFile/DATArchive provide archive I/O used by the loader but do not own font slot state.
- ImageLib is a nearby startup/render subsystem but has separate object size, vtable, and resource responsibilities.

## Heuristic / Inference Reanalysis And Validation

The named score blockers in current docs are now resolved:

- "Class-wide header/source pass" blocker: resolved by combining the accepted UID0002HP callback with current MCP checks. The class has accepted fields and support structs; this report adds the missing method prototypes and bodies.
- Method names: `GetFontMetrics`, `MeasureGlyphWidth`, `EnsureFontSlotLoaded`, and `DecodeGlyphBitmap` remain inferred source-facing names, but they are consistent with current docs, generated callers, and behavior. Lack of recovered PDB spelling is not a reason to leave empty markers.
- Return types: use `void` for `GetFontMetrics` and `MeasureGlyphWidth` because current generated callers ignore the decompiler return values and consume output pointers. Preserve the decompiler return-register artifacts in evidence prose rather than in source API.
- Slot metrics: `maxCellWidth` and `maxCellHeightMinus4` are already accepted support names. The loader's minus-four adjustment must be preserved.
- Scratch allocation: use accepted `MemoryMan` helpers. Do not introduce `new[]` / `delete[]` where the binary calls `GetMemoryMan` allocation/free wrappers.
- Scalar deleting destructor: source cleanup belongs in `FontImageLib::~FontImageLib`; the deleting wrapper is compiler-generated from the virtual destructor and should be represented with a no-code proof.
- Layout/vtable/vtable-data pages: these are source-declared/generated-binary evidence. They should not duplicate class declarations or hand-authored vtable arrays.

Rejected alternatives:

- Leave methods blank because exact original names are unknown: rejected by score-blocker standard and current source-facing name evidence.
- Emit raw decompiler signatures: rejected; they expose `char *this`, `_DWORD *`, `_WORD *` and return artifacts instead of source-quality class APIs.
- Use direct file helper functions: rejected because receivers and current class owner are proven.
- Include `IsLegacyAssetMode` in this callback family: rejected because it is not a current visible empty marker for `FontImageLib.cpp` and already routes outside the class.

## First-Draft C++ Recommendation

All code below is intended as exact formal `RECONSTRUCTION_CPP CODE` insertion text after supervisor acceptance.

### [UID:00005B] Class Declaration Support

```cpp
class FontImageLib : public LObject
{
public:
    FontImageLib();
    virtual ~FontImageLib();

    void GetFontMetrics(int fontId, short *outWidth, short *outHeight);
    void MeasureGlyphWidth(int fontId,
                           unsigned short glyphId,
                           unsigned short nextGlyphId,
                           bool clearBeforeDecode,
                           const unsigned char *paletteMap,
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

[[CHILDREN]]
```

### [UID:00015B] FontImageLib Destructor

```cpp
FontImageLib::~FontImageLib()
{
    for (int i = 0; i < 2; ++i) {
        if (m_fontSlots[i].archiveFile != NULL) {
            delete m_fontSlots[i].archiveFile;
        }
    }

    if (m_scratchBuffer != NULL) {
        GetMemoryMan()->FreeBufferMemory(m_scratchBuffer);
    }

    g_pFontImageLib = 0;
}
```

Rationale: this omits compiler vtable restore, SEH/security-cookie machinery, and implicit base destructor chaining while preserving the two-slot DATFile cleanup, scratch free, and singleton clear. It intentionally does not clear fields on a dying object because the binary does not store field zeroes.

### [UID:0002HQ] FontImageLib GetFontMetrics

```cpp
void FontImageLib::GetFontMetrics(int fontId, short *outWidth, short *outHeight)
{
    EnsureFontSlotLoaded(fontId);

    if (outWidth != NULL) {
        *outWidth = 12;
    }
    if (outHeight != NULL) {
        *outHeight = 12;
    }
}
```

Rationale: live callers use output pointers; the decompiler return value is the final output-pointer expression in `eax`, not a source API value.

### [UID:0002HR] FontImageLib MeasureGlyphWidth

```cpp
void FontImageLib::MeasureGlyphWidth(int fontId,
                                     unsigned short glyphId,
                                     unsigned short nextGlyphId,
                                     bool clearBeforeDecode,
                                     const unsigned char *paletteMap,
                                     RectBounds *outBounds,
                                     short *outAdvance,
                                     EPFTileContext *outContext)
{
    (void)nextGlyphId;

    FontGlyphRecord *glyph = NULL;
    for (;;) {
        FontSlotStorage *slot = EnsureFontSlotLoaded(fontId);
        glyph = slot->glyphTable[glyphId];
        if (glyph != NULL && glyph->right - glyph->left != 0) {
            break;
        }
        glyphId = 63;
    }

    if (outBounds != NULL) {
        InitRectBounds(outBounds, glyph->left, glyph->top, glyph->right, glyph->bottom);
    }
    if (outAdvance != NULL) {
        *outAdvance = glyph->advance;
    }
    if (outContext != NULL) {
        outContext->ReleaseBuffers();
        DecodeGlyphBitmap(glyph, glyphId, clearBeforeDecode, paletteMap, outContext);
    }
}
```

Rationale: preserves fallback-to-63 for missing or zero-width glyphs, optional bounds/advance/tile-context outputs, and the intentionally unused next-glyph-looking parameter.

### [UID:0002HS] FontImageLib EnsureFontSlotLoaded

```cpp
FontSlotStorage *FontImageLib::EnsureFontSlotLoaded(int fontId)
{
    int slotIndex = fontId;
    if (slotIndex < 0 || slotIndex >= 2) {
        slotIndex = 0;
    }

    FontSlotStorage *slot = &m_fontSlots[slotIndex];
    if (slot->archiveFile != NULL) {
        return slot;
    }

    wchar_t fileName[32];
    swprintf_s(fileName, 32, L"BARAM%02d.EFT", slotIndex);

    slot->archiveFile = new DATFile;
    slot->archiveFile->Open(fileName);

    unsigned char *payloadBase = static_cast<unsigned char *>(slot->archiveFile->GetDataPointer());
    slot->archiveFile->Read(&slot->maxCellWidth, sizeof(slot->maxCellWidth));
    slot->archiveFile->Read(&slot->maxCellHeightMinus4, sizeof(slot->maxCellHeightMinus4));
    slot->maxCellHeightMinus4 = static_cast<unsigned short>(slot->maxCellHeightMinus4 - 4);

    for (int glyphIndex = 0; glyphIndex < 0x10000; ++glyphIndex) {
        int offset = 0;
        slot->archiveFile->Read(&offset, sizeof(offset));
        slot->glyphTable[glyphIndex] = offset != 0
            ? reinterpret_cast<FontGlyphRecord *>(payloadBase + offset)
            : NULL;
    }

    return slot;
}
```

Rationale: preserves signed/out-of-range clamp, archive pointer as loaded flag, `BARAM%02d.EFT`, DATFile open/data/read calls, second metric minus-four, and relative glyph-offset resolution.

### [UID:0002HT] FontImageLib DecodeGlyphBitmap

```cpp
int FontImageLib::DecodeGlyphBitmap(const FontGlyphRecord *glyph,
                                    unsigned short glyphId,
                                    bool clearBeforeDecode,
                                    const unsigned char *paletteMap,
                                    EPFTileContext *tileContext)
{
    (void)glyphId;

    InitRectBounds(&tileContext->bounds, glyph->left, glyph->top, glyph->right, glyph->bottom);
    tileContext->rowStridePixels = tileContext->bounds.right - tileContext->bounds.left;

    const int requiredBytes = RectArea(&tileContext->bounds);
    if (requiredBytes > m_scratchBufferBytes) {
        if (m_scratchBuffer != NULL) {
            m_scratchBuffer = static_cast<unsigned char *>(
                GetMemoryMan()->ReallocateBufferMemory(m_scratchBuffer, requiredBytes));
        } else {
            m_scratchBuffer = static_cast<unsigned char *>(
                GetMemoryMan()->AllocateBufferMemory(requiredBytes));
        }
        m_scratchBufferBytes = requiredBytes;
    }

    if (clearBeforeDecode) {
        memset(m_scratchBuffer, 0, m_scratchBufferBytes);
    }

    tileContext->pixelData = m_scratchBuffer;
    tileContext->encodedMaskByteCount = 0;
    tileContext->encodedMaskBytes = 0;

    const unsigned char *encoded = glyph->encodedRows;
    unsigned char *row = m_scratchBuffer;
    const int width = tileContext->bounds.right - tileContext->bounds.left;
    const int height = tileContext->bounds.bottom - tileContext->bounds.top;

    for (int y = 0; y < height; ++y) {
        int x = 0;
        for (;;) {
            const unsigned char token = *encoded++;
            if (token == 0) {
                break;
            }

            const int runStart = x;
            const int runLength = token & 0x1f;
            const int paletteIndex = token >> 5;
            x += runLength;

            if ((!clearBeforeDecode && paletteIndex != 5) ||
                (clearBeforeDecode && paletteIndex != 0)) {
                if (x > 0 && runStart < width) {
                    const int left = runStart > 0 ? runStart : 0;
                    const int right = x < width ? x : width;
                    if (right > left) {
                        memset(row + left, paletteMap[paletteIndex], right - left);
                    }
                }
            }
        }

        row += tileContext->rowStridePixels;
    }

    return height;
}
```

Rationale: preserves `record+0x0e` row streams, low-five-bit run length, high-three-bit palette index, mode-dependent transparent indices (`5` in non-clear mode, `0` in clear mode), row clipping, scratch growth, and tile-context field writes.

### [UID:0002HU] Scalar Deleting Destructor No-Code Proof

```cpp
// Compiler-generated scalar deleting destructor for FontImageLib; source cleanup is emitted by [UID:00015B] FontImageLib::~FontImageLib(), and the compiler regenerates this wrapper from the virtual destructor.
```

### [UID:0001UL] Layout No-Code Proof

```cpp
// FontImageLib object layout is emitted by [UID:00005B] FontImageLib and [UID:0001UM] FontSlotStorage; this page remains complete-object layout evidence only.
```

### [UID:0001XM] Vtable No-Code Proof

```cpp
// FontImageLib vtable data is compiler-generated from [UID:00005B] FontImageLib and its virtual destructor; this page remains vtable evidence only.
```

### [UID:00031Q] Exact Vtable Data No-Code Proof

```cpp
// Exact FontImageLib RTTI/vtable storage is compiler-generated from [UID:00005B] FontImageLib and [UID:0001XM] FontImageLibVtable; do not hand-port the 0x0061a5f0 dwords.
```

## Recommended Target Doc Changes

`by-file/FontImageLib.md`:

- Raise from `88/88` to `92/92` if the accepted callback applies all nine visible empty-marker dispositions.
- Update status/current emitted-source text to say the constructor plus sibling destructor/metrics/measure/loader/decoder bodies are source-ready and that layout/vtable/vtable-data pages use exact no-code proof comments.
- Preserve `NexusTK/render/` path and file owner.
- Preserve rejected routing for [UID:00015A] mixed aggregate and [UID:0003XA] `IsLegacyAssetMode`.
- Record MCP session `supervisor_resume_20260629`, command ids `6-29`, exact function sizes, xrefs, vtable/string/global facts, and score rationale.

## Recommended Support Doc Changes

- `by-class/FontImageLib.md`: raise to `92/92`; replace the class formal block with the expanded declaration above; document that `GetFontMetrics` and `MeasureGlyphWidth` are public consumer-facing services while `EnsureFontSlotLoaded` and `DecodeGlyphBitmap` are private class helpers; keep accepted field names.
- `by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md`: raise to `90/92`; insert destructor C++; remove/historicalize "blank until class-wide pass"; preserve vtable restore/base cleanup as compiler/source-destructor evidence, not hand-authored statements.
- `by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md`: raise to `90/93`; insert void metrics C++; preserve fixed 12/12 behavior and return-register artifact as non-API.
- `by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md`: raise to `90/92`; insert void measurement C++; preserve fallback glyph `63`, unused next-glyph parameter, optional output behavior, and GrafPort consumer evidence.
- `by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md`: raise to `91/93`; insert loader C++; correct Item Summary stale `BA0`/`BA1` wording to `BARAM00.EFT` / `BARAM01.EFT` and `BARAM%02d.EFT`.
- `by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md`: raise to `91/93`; insert decoder C++; document MemoryMan allocation names and exact transparent-index rule.
- `by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md`: raise to `88/93`; insert no-code proof; state source cleanup is [UID:00015B].
- `by-type/by-struct/FontImageLibLayout.md`: raise to `88/92`; insert no-code proof; optionally update status that final member names are accepted enough for emitted class/method source.
- `by-type/by-vtable/FontImageLibVtable.md`: raise to `89/93`; insert no-code proof; keep inherited/shared slot `0x004f4b10` as a confidence cap.
- `by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md`: raise to `90/94`; insert no-code proof; preserve exact dword/string boundary evidence.
- Optional support sync only if supervisor wants broader generated-output consistency: `by-memory/0x0061a600-0x0061a61c.FontImageLibResourcePatternString.md` already documents the string but is not one of the current visible empty markers and should not be added to this implementation scope unless validator output exposes it as a remaining FontImageLib empty marker.

## Score And Metadata Recommendation

| UID | Current | Recommended | Metadata changes |
| --- | --- | --- | --- |
| `0000JH` | `88/88` | `92/92` | path/owner unchanged |
| `00005B` | `90/90` | `92/92` | owner/emitter unchanged; expanded class C++ |
| `00015B` | `86/91` | `90/92` | owner/emitter unchanged; formal C++ |
| `0002HQ` | `86/90` | `90/93` | owner/emitter unchanged; formal C++ |
| `0002HR` | `86/90` | `90/92` | owner/emitter unchanged; formal C++ |
| `0002HS` | `88/92` | `91/93` | owner/emitter unchanged; formal C++ |
| `0002HT` | `88/92` | `91/93` | owner/emitter unchanged; formal C++ |
| `0002HU` | `86/92` | `88/93` | owner/emitter unchanged; formal no-code proof |
| `0001UL` | `85/90` | `88/92` | owner/emitter unchanged; formal no-code proof |
| `0001XM` | `87/92` | `89/93` | owner/emitter unchanged; formal no-code proof |
| `00031Q` | `88/92` | `90/94` | owner/emitter unchanged; formal no-code proof |

Reason not higher: original private/member/method spellings are inferred, `FontSlotStorage` metric meanings remain partly descriptive, and the inherited/shared virtual slot at `0x004f4b10` is still not source-named here.

## Open Questions With Attempted Resolution

- Exact original method names: unresolved as original symbols, resolved operationally with source-facing names already used in docs and generated callers.
- `nextGlyphId` role in `MeasureGlyphWidth`: binary does not read it. Keep parameter for caller signature compatibility and mark `(void)nextGlyphId`.
- `FontGlyphRecord` reserved fields: still unknown, but not read by this family; keep `reserved0/reserved1`.
- Exact header split: unresolved but nonblocking; by-* generated route currently emits the class and children in `FontImageLib.cpp`.
- MemoryMan helper spelling: use accepted current pages, including `ReallocateBufferMemory`; preserve `ReallocateOrThrow` only as historical alias in prose if needed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Current MCP is healthy and session-backed, not fallback-only. | High | MCP ids `6-7` | `by-file/FontImageLib.md` Status/Behavior Summary and `by-class/FontImageLib.md` Evidence Notes | incorporate | applied - both docs record live MCP session `supervisor_resume_20260629` command ids `6-29` as the accepted evidence basis. |
| C02 | Five source-authored class methods are ready for formal C++ under [UID:00005B]. | High | MCP ids `9-28`, current class/struct docs | Method pages and class page | incorporate | applied - formal C++ blocks are present in [UID:00015B], [UID:0002HQ], [UID:0002HR], [UID:0002HS], [UID:0002HT]; class [UID:00005B] now declares public methods/private helpers. |
| C03 | `GetFontMetrics` and `MeasureGlyphWidth` should use void source signatures despite decompiler return artifacts. | Medium-high | xrefs/callers, generated GrafPort callers, decompile ids `11-12` | [UID:0002HQ], [UID:0002HR], class page | incorporate | applied - [UID:0002HQ] and [UID:0002HR] formal blocks use `void`; both pages preserve return-register artifact rationale, and [UID:00005B] declares matching void methods. |
| C04 | Loader source must preserve signed clamp, `BARAM%02d.EFT`, DATFile load, minus-four metric, and 65536 offset loop. | High | disasm ids `22,24`, decompile id `13`, string bytes id `27` | [UID:0002HS], file/class docs | incorporate | applied - [UID:0002HS] formal C++ includes signed clamp, `swprintf_s(... L"BARAM%02d.EFT" ...)`, DATFile allocation/open/read/data-pointer, minus-four metric adjustment, and 0x10000 glyph-offset loop; stale `BA0`/`BA1` summary corrected. |
| C05 | Decoder source must preserve scratch allocation, tile-context fields, row-token decoding, and mode-dependent transparent indices. | High | decompile id `14`, disasm id `23`, EPFTileContext docs | [UID:0002HT], class docs | incorporate | applied - [UID:0002HT] formal C++ includes scratch growth via MemoryMan, EPFTileContext bounds/stride/pixel/mask writes, token low-five/high-three decoding, clipping, and transparent-index split (`5` non-clear, `0` clear). |
| C06 | Ordinary destructor owns source cleanup; scalar deleting destructor is compiler wrapper. | High | decompile ids `10,15`, xrefs id `25`, vtable data | [UID:00015B], [UID:0002HU], vtable docs | incorporate | applied - [UID:00015B] emits `FontImageLib::~FontImageLib()` cleanup; [UID:0002HU] emits formal no-code proof and records compiler wrapper/delete-flag evidence. |
| C07 | Layout/vtable/vtable-data pages should receive formal no-code comments, not duplicate emitted class/vtable source. | High | by-structure generated-binary rules, vtable bytes/global values | [UID:0001UL], [UID:0001XM], [UID:00031Q] | incorporate | applied - [UID:0001UL], [UID:0001XM], and [UID:00031Q] contain formal no-code proof comments; generated output includes [UID:0001UL]/[UID:0001XM] no-code comments and omits the old [UID:00031Q] empty marker after source-page disposition. |
| C08 | [UID:00015A] remains non-emitting mixed index and [UID:0003XA] remains outside FontImageLib. | High | current aggregate docs, B001 report, lookup id `9` | file/class notes | incorporate | applied - `by-file/FontImageLib.md` and `by-class/FontImageLib.md` preserve the non-emitting mixed-index and non-FontImageLib `IsLegacyAssetMode` route; no split/child edits made. |
| C09 | Target file score can rise to `92/92` after all nine marker dispositions are applied. | Medium-high | all above evidence plus generated route | [UID:0000JH] metadata/score rationale | incorporate | applied - `by-file/FontImageLib.md` metadata is `COMPLETION:92`, `CONFIDENCE:92`; all accepted support score updates were applied and validated. |

Allowed action value used: `incorporate`. Callback verification states are `applied` for every accepted claim; no ledger item is blocked or excluded.

## Validator Results

Validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--wait-generated`. The final compact metadata run used these command ids:

| File | Command | command_id | command_timestamp | Exit | ok | generated_refresh |
| --- | --- | --- | --- | --- | --- | --- |
| `by-file/FontImageLib.md` | `python .\tools\validator.py --mode file --file by-file/FontImageLib.md --apply --queue-timeout 240 --wait-generated` | `000000004060` | `2026-07-01T17:14:54-04:00` | `0` | `1` | completed, command `000000004060`, timestamp `2026-07-01T17:14:54-04:00` |
| `by-class/FontImageLib.md` | `python .\tools\validator.py --mode file --file by-class/FontImageLib.md --apply --queue-timeout 240 --wait-generated` | `000000004061` | `2026-07-01T17:15:07-04:00` | `0` | `1` | completed, command `000000004061`, timestamp `2026-07-01T17:15:07-04:00` |
| `by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md --apply --queue-timeout 240 --wait-generated` | `000000004062` | `2026-07-01T17:15:19-04:00` | `0` | `1` | completed, command `000000004062`, timestamp `2026-07-01T17:15:19-04:00` |
| `by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md --apply --queue-timeout 240 --wait-generated` | `000000004063` | `2026-07-01T17:15:31-04:00` | `0` | `1` | completed, command `000000004063`, timestamp `2026-07-01T17:15:31-04:00` |
| `by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md --apply --queue-timeout 240 --wait-generated` | `000000004064` | `2026-07-01T17:15:43-04:00` | `0` | `1` | completed, command `000000004064`, timestamp `2026-07-01T17:15:43-04:00` |
| `by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md --apply --queue-timeout 240 --wait-generated` | `000000004071` | `2026-07-01T17:17:15-04:00` | `0` | `1` | completed, command `000000004071`, timestamp `2026-07-01T17:17:15-04:00` |
| `by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md --apply --queue-timeout 240 --wait-generated` | `000000004072` | `2026-07-01T17:17:26-04:00` | `0` | `1` | completed, command `000000004072`, timestamp `2026-07-01T17:17:26-04:00` |
| `by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md --apply --queue-timeout 240 --wait-generated` | `000000004067` | `2026-07-01T17:16:17-04:00` | `0` | `1` | completed, command `000000004067`, timestamp `2026-07-01T17:16:17-04:00` |
| `by-type/by-struct/FontImageLibLayout.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/FontImageLibLayout.md --apply --queue-timeout 240 --wait-generated` | `000000004068` | `2026-07-01T17:16:29-04:00` | `0` | `1` | completed, command `000000004068`, timestamp `2026-07-01T17:16:29-04:00` |
| `by-type/by-vtable/FontImageLibVtable.md` | `python .\tools\validator.py --mode file --file by-type/by-vtable/FontImageLibVtable.md --apply --queue-timeout 240 --wait-generated` | `000000004069` | `2026-07-01T17:16:39-04:00` | `0` | `1` | completed, command `000000004069`, timestamp `2026-07-01T17:16:39-04:00` |
| `by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md` | `python .\tools\validator.py --mode file --file by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md --apply --queue-timeout 240 --wait-generated` | `000000004070` | `2026-07-01T17:16:51-04:00` | `0` | `1` | completed, command `000000004070`, timestamp `2026-07-01T17:16:51-04:00` |

Warnings/side effects observed:

- Common warning counts on scoped validator runs: `autogen_children_fallback_insert:16`, `autogen_children_marker_missing:81`, `autogen_emitter_has_no_code:233`; these are broad generated-output warnings unrelated to the edited FontImageLib pages.
- `missing_ref_uid:4` appeared on the file/class validators for [UID:0003XA] references; the callback preserves [UID:0003XA] as an outside route and does not attempt validator registry repair.
- `stats_incremental_noop:1` appeared for each scoped target because the UID file is not present in generated stats lists; `projected_stats_update:1` refreshed projected stats through the validator.
- Validator-owned generated files refreshed through the validator, including generated C++ metadata, research tracker, memory auto coverage, projected stats, and autogen backups. No generated file was manually edited.

Generated freshness proof:

- `auto-generated/NexusTK/render/FontImageLib.cpp` header after the final validator reads `validator-command-id: 000000004072` and `validator-refreshed-at: 2026-07-01T17:17:26-04:00`, equal to the latest returned generated-refresh metadata.
- Generated output contains formal code for [UID:00015B], [UID:0002HQ], [UID:0002HR], [UID:0002HS], and [UID:0002HT].
- Generated output contains formal no-code comments for [UID:0002HU], [UID:0001UL], and [UID:0001XM]. [UID:00031Q] is no longer emitted as a visible generated marker after its source page no-code disposition; its by-memory page contains the formal no-code proof and the old [UID:00031Q] empty marker is absent from generated `FontImageLib.cpp`.
- Search of generated `FontImageLib.cpp` found no `EMPTY`, `No reconstruction`, `No C++`, `TODO`, `formal C++ remains blank`, `blank final C++`, or `C++ remains blank` marker for the audited family.

## Changed Files

- Modified: `by-file/FontImageLib.md`
- Modified: `by-class/FontImageLib.md`
- Modified: `by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md`
- Modified: `by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md`
- Modified: `by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md`
- Modified: `by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md`
- Modified: `by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md`
- Modified: `by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md`
- Modified: `by-type/by-struct/FontImageLibLayout.md`
- Modified: `by-type/by-vtable/FontImageLibVtable.md`
- Modified: `by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md`
- Modified: `tools/leaser/Agents/Agent-B010/research/0000JH-FontImageLib-empty-emitter-family-source-quality.md`
- Leases: initial B010 batch lease succeeded for all eleven by-* docs before edits; it expired during the edit/validator batch before explicit unlease, and `python leaser.py B010 unlease` reported `B010: No active leases`. A follow-up one-file lease for `by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md` succeeded before the wording correction and validator `000000004059`; `python leaser.py B010 unlease` released it successfully. Final `current_leases.md` reports no active leases.
- Report execution: not performed. Supervisor owns `tools/validator.py execute_report ... --apply` after verification.

## Implementation Tracking Checklist

Implementation callback status:

- [x] Supervisor validation required before implementation. Proof: supervisor callback accepted report and assigned `B010-implement-0000JH-FontImageLib-empty-emitter-family-20260701`.
- [x] Update `by-file/FontImageLib.md`: set recommended `92/92`, preserve `NexusTK/render/`, record nine-marker family resolution, MCP ids `6-29`, source route, rejected aggregate/helper ownership, and generated freshness expectation. Proof: metadata is `92/92`; Status/Behavior/Changes sections record the nine-marker family, MCP ids, source route, and preserved [UID:00015A]/[UID:0003XA] decisions; validator `000000004060`.
- [x] Update `by-class/FontImageLib.md`: set recommended `92/92`, replace formal class declaration with expanded method prototypes/private helpers from this report, preserve fields and `[[CHILDREN]]`. Proof: formal block includes `GetFontMetrics`, `MeasureGlyphWidth`, private `EnsureFontSlotLoaded`, private `DecodeGlyphBitmap`, existing fields, and `[[CHILDREN]]`; validator `000000004061`.
- [x] Update [UID:00015B] `by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md`: set `90/92`, insert destructor C++, historicalize blank-C++ blocker, preserve cleanup/vtable/base evidence. Proof: metadata `90/92`, formal destructor block inserted, status/change notes historicalize B001 blank blocker and preserve compiler evidence; validator `000000004062`.
- [x] Update [UID:0002HQ] `by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md`: set `90/93`, insert void C++, preserve fixed 12/12 metrics and return-artifact rationale. Proof: metadata `90/93`, formal void block inserted, behavior/reconstruction notes preserve return-register artifact; validator `000000004063`.
- [x] Update [UID:0002HR] `by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md`: set `90/92`, insert void C++, preserve fallback glyph, unused next-glyph parameter, optional outputs, and caller evidence. Proof: metadata `90/92`, formal void block includes `(void)nextGlyphId`, fallback glyph `63`, optional outputs, and decode; validator `000000004064`.
- [x] Update [UID:0002HS] `by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md`: set `91/93`, insert loader C++, correct Item Summary stale `BA0`/`BA1`, preserve clamp/resource/DAT/glyph-table evidence. Proof: metadata `91/93`, item summary now names `BARAM00.EFT`/`BARAM01.EFT`, formal block preserves clamp/resource/DAT/glyph table; validator `000000004071`.
- [x] Update [UID:0002HT] `by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md`: set `91/93`, insert decoder C++, preserve MemoryMan helper names, EPFTileContext field writes, token format, clipping, and transparency rule. Proof: metadata `91/93`, formal block includes scratch growth, EPFTileContext writes, row token decoding, clipping, and transparency branches; validator `000000004072`.
- [x] Update [UID:0002HU] `by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md`: set `88/93`, insert exact scalar-deleting no-code proof, preserve wrapper/delete-flag evidence. Proof: metadata `88/93`, formal no-code comment present, classification/changes preserve wrapper evidence; validator `000000004067`.
- [x] Update [UID:0001UL] `by-type/by-struct/FontImageLibLayout.md`: set `88/92`, insert exact covered-by no-code proof, update accepted field-name status if needed. Proof: metadata `88/92`, formal no-code comment present, notes accept `m_fontSlots`, `m_scratchBuffer`, `m_scratchBufferBytes`; validator `000000004068`.
- [x] Update [UID:0001XM] `by-type/by-vtable/FontImageLibVtable.md`: set `89/93`, insert exact compiler-generated-vtable no-code proof, preserve slot table and `0x004f4b10` confidence cap. Proof: metadata `89/93`, formal no-code comment present, slot table and inherited/shared slot caveat preserved; validator `000000004069`.
- [x] Update [UID:00031Q] `by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md`: set `90/94`, insert exact vtable-data no-code proof, preserve RTTI/vtable/string boundary evidence. Proof: metadata `90/94`, formal no-code comment present, range/reconstruction/changes preserve exact dwords and string boundary; validator `000000004070`.
- [x] Preserve [UID:00015A] non-emitting mixed-index decision and [UID:0003XA] non-FontImageLib route; do not create split children or edit them unless supervisor callback explicitly adds that scope. Proof: no edits made to [UID:00015A] or [UID:0003XA]; file/class docs preserve these decisions.
- [x] Do not edit `auto-generated/`, generated reports, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, supervisor ledgers, archives, by-project-structure docs, or IDA DB. Proof: only listed by-* docs and this report were manually edited; generated/project/tool state changes were validator-owned side effects only.
- [x] Run all scoped validators listed in `Validator Results` with `--wait-generated`. Proof: validator table above, exit `0`, `ok:1`, generated refresh completed for all scoped files.
- [x] Verify `auto-generated/NexusTK/render/FontImageLib.cpp` generated header freshness and absence/replacement of the nine audited visible empty markers. Proof: header is `validator-command-id: 000000004072`, `validator-refreshed-at: 2026-07-01T17:17:26-04:00`; generated marker scan found accepted code/no-code comments for emitted UIDs and no old empty-marker text. [UID:00031Q] is absent as a generated marker after source no-code disposition.
- [x] Update this report's Claim And Incorporation Ledger during callback with `applied`, `already-present`, `excluded-with-reason`, or `blocked` proof for every accepted claim. Proof: all ledger rows C01-C09 are marked `applied` with destination proof.
- [x] Release any implementation leases immediately after the edit/validator batch and prove no active B010 leases remain. Proof: initial batch lease expired during validation and explicit `python leaser.py B010 unlease` reported `B010: No active leases`; follow-up scalar wrapper lease was explicitly released; final `tools/leaser/Agents/current_leases.md` reports no active leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000JH-FontImageLib-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000JH-FontImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T17:24:20","uid":"0000JH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
