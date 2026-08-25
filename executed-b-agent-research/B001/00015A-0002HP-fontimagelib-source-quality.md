** TARGET-REPORT-UID:00015A **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015A / 0002HP FontImageLib Source-Quality Research

Agent: B001  
Assignment: B001-goal2-fontimagelib-source-quality-00015A-0002HP-20260617  
Date: 2026-06-17  
Primary target: [UID:00015A] `by-memory/0x004b5f00-0x004b6409.FontImageLib.md`  
Required entry child: [UID:0002HP] `by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md`

## Executive Recommendation

[UID:00015A] should not remain a reconstructable/emitting aggregate. Fresh IDA evidence proves the physical range is a mixed executable island: it contains the FontImageLib method cluster plus a real non-padding helper at `0x004b60b0-0x004b60bd` that only tests `g_useEpfAssets != 1`. The exact FontImageLib child pages should carry reconstruction and emit through [UID:00005B] `FontImageLib`; the aggregate should become a reviewed non-emitting index with blank formal C++.

[UID:0002HP] should stay class-owned and reconstructable under [UID:00005B], with the stale MCP-timeout caveat removed. The constructor is now directly validated: it calls `LObject::LObject`, stores the singleton-adjusted `g_pFontImageLib`, installs the FontImageLib vtable, zeroes exactly `0x80010` bytes for two `0x40008` font slots, clears scratch pointer/capacity fields, and returns `this`.

Recommended high-level metadata after supervisor execution:

| UID | Target | Recommended owner | Recommended emitter | Reconstructable | Score | Formal C++ |
|---|---|---:|---:|---:|---:|---|
| 00015A | aggregate `0x004b5f00-0x004b6409` | `NONE` | blank | false | 88/92 | blank |
| 0002HP | constructor `0x004b5f00-0x004b5f54` | 00005B | 00005B | true | 88/92 | blank, do not populate yet |
| 00015B | destructor `0x004b5f60-0x004b5fe6` | 00005B | 00005B | true | 86/91 | blank |
| 0002HQ | metrics `0x004b5ff0-0x004b6018` | 00005B | 00005B | true | 86/90 | blank |
| 0002HR | measure `0x004b6020-0x004b60ae` | 00005B | 00005B | true | 86/90 | blank |
| NEW | mode helper `0x004b60b0-0x004b60bd` | 0000SW | 0000SW | true | 86/90 | blank until child created/named |
| 0002HS | lazy slot load `0x004b60c0-0x004b61d9` | 00005B | 00005B | true | 88/92 | blank |
| 0002HT | glyph decode `0x004b61e0-0x004b6341` | 00005B | 00005B | true | 88/92 | blank |
| 0002HU | scalar deleting destructor `0x004b6350-0x004b6409` | 00005B | 00005B | true | 86/92 | blank |

## Inputs Checked

Read and applied:

- `tools/leaser/Agents/Agent-B001/goal.md`
- `project-documentation/by-structure.md`
- `tools/leaser/Agents/Agent-B001/inference_research.md`
- `project-documentation/source-tree/proposed/NexusTK-full-proposed-tree.md`
- Current target/support docs for [UID:00015A], [UID:0002HP], [UID:00015B], [UID:0002HQ], [UID:0002HR], [UID:0002HS], [UID:0002HT], [UID:0002HU], [UID:00005B], [UID:0000JH], [UID:0000QX], [UID:0001P2], [UID:0001UL], [UID:0001UM], [UID:0001UK], [UID:0001XM], [UID:00031Q], [UID:0003BI], [UID:0000SW], [UID:0001OH], and relevant LObject pages.
- `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, and generated `NexusTK/render/FontImageLib.cpp`.
- Existing B001/B002/B003 executed reports searched for this UID and siblings. No prior exact B report for `00015A`, `0002HP`, `0002HQ`, `0002HR`, `0002HS`, `0002HT`, or `0002HU` was found. Older executed B001 work only referenced FontImageLib as a text/glyph dependency from UI consumers; it was used as a lead, not authority.

Fresh IDA worker used: `b002_00014p_exchange_ready_20260617`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, auto-analysis ready and Hex-Rays ready.

## Fresh IDA Evidence

Function boundaries:

| Range | IDA function | Size | Result |
|---|---:|---:|---|
| `0x004b5f00-0x004b5f54` | `sub_4B5F00` | `0x54` | FontImageLib constructor |
| `0x004b5f54-0x004b5f60` | none | `0x0c` | `0xcc` padding |
| `0x004b5f60-0x004b5fe6` | `sub_4B5F60` | `0x86` | ordinary destructor |
| `0x004b5fe6-0x004b5ff0` | none | `0x0a` | `0xcc` padding |
| `0x004b5ff0-0x004b6018` | `sub_4B5FF0` | `0x28` | font metrics accessor |
| `0x004b6018-0x004b6020` | none | `0x08` | `0xcc` padding |
| `0x004b6020-0x004b60ae` | `sub_4B6020` | `0x8e` | glyph measure/draw setup |
| `0x004b60ae-0x004b60b0` | none | `0x02` | `0xcc` padding |
| `0x004b60b0-0x004b60bd` | `sub_4B60B0` | `0x0d` | real global mode helper |
| `0x004b60bd-0x004b60c0` | none | `0x03` | `0xcc` padding |
| `0x004b60c0-0x004b61d9` | `sub_4B60C0` | `0x119` | lazy font-slot loader |
| `0x004b61d9-0x004b61e0` | none | `0x07` | `0xcc` padding |
| `0x004b61e0-0x004b6341` | `sub_4B61E0` | `0x161` | glyph decoder/EPF tile context |
| `0x004b6341-0x004b6350` | none | `0x0f` | `0xcc` padding |
| `0x004b6350-0x004b6409` | `sub_4B6350` | `0xb9` | scalar deleting destructor |
| `0x004b6409-0x004b6410` | none | `0x07` | `0xcc` padding after aggregate |

Constructor facts at `0x004b5f00`:

- Calls `sub_4F4A80` (`LObject::LObject`) at `0x004b5f0a`.
- Computes the singleton payload pointer as `esi + 4`, then stores `ecx = (esi + 4) - 4` when non-null, so the stored value is the object base pointer. This is compiler null-adjust guard shape, not a separate subobject allocation.
- Writes `g_pFontImageLib` at `0x0067ab24` from `0x004b5f24`.
- Installs vtable `??_7FontImageLib@@6B@` at `0x0061a5f4` into `[esi]` from `0x004b5f2b`.
- Calls `_memset` with destination `esi + 4`, value `0`, size `0x80010`.
- Clears `[esi+0x80014]` and `[esi+0x80018]`.
- Returns `esi`.

Startup allocation evidence:

- `Application::Initialize`-region caller at `0x00464520` calls `sub_4B5F00`.
- The allocation sequence pushes `0x8001c`, calls the allocator at `sub_4F4AA0`, tests the returned pointer, moves it to `ecx`, then calls the FontImageLib constructor.
- The previous nearby startup allocation is ImageLib-sized and calls `ImageLib_Constructor`; the FontImageLib allocation is separate and has the exact class size implied by the two font slots plus scratch fields.

Vtable and read-only evidence:

- `0x0061a5f0` is the RTTI locator pointer.
- `0x0061a5f4` points to `0x004b6350`, the scalar deleting destructor.
- `0x0061a5f8` points to `0x004f4b10`, inherited `LObject::GetRuntimeClass`.
- `0x0061a5fc` points to `0x0041b6c0`, inherited/shared no-op virtual.
- `0x0061a600` begins the UTF-16 string `BARAM%02d.EFT`.
- Xrefs to `0x0061a5f4`: constructor vtable store, ordinary destructor vtable restore, scalar deleting destructor vtable restore.

Global pointer evidence:

- Current IDA value at `0x0067ab24` is `0x0`.
- Current bytes at `0x0067ab20-0x0067ab30` are zero-filled. This contradicts current `g_pFontImageLib` support text that says the slot is initially `0xffffffff`.
- `g_pFontImageLib` has 52 xrefs. The FontImageLib constructor writes it, the ordinary destructor and scalar deleting destructor clear it, application cleanup reads it, and GrafPort/UI consumers read it for text/glyph operations.

New embedded helper evidence:

```asm
0x004b60b0 xor     eax, eax
0x004b60b2 cmp     byte_66DA97, 1
0x004b60b9 setnz   al
0x004b60bc retn
```

This is not padding and is not a FontImageLib method. It reads [UID:0000SW] `g_useEpfAssets` / `byte_66DA97` and returns true when that byte is not `1`. It has 33 code xrefs across UI/rendering code. The best source-facing name is `IsLegacyAssetMode` or `IsLegacyUiMode`; existing stale names such as `IsCompactDisplayMode_4B60B0` should be retained only as aliases until the broader display-mode naming pass resolves them.

## Heuristic / Inference Reanalysis And Validation

Best defensible class/source shape:

- `FontImageLib` is a source-authored class in `NexusTK/render/FontImageLib.cpp`, owned by [UID:00005B] and routed through [UID:0000JH]. The constructor, destructor, metrics accessor, glyph measure path, lazy loader, glyph decoder, and scalar deleting destructor all use the same vtable/class object state and should not be routed directly to the by-file page.
- The file page [UID:0000JH] remains the correct source file route. The class page should be the direct semantic owner for class methods. The resource string [UID:0003BI] can remain file-owned because it is static file/method literal data, not a class method.
- The physical aggregate [UID:00015A] is only an executable index. It has no independent source unit once exact children exist, and it is now known to contain a non-FontImageLib mode helper. Emitting the aggregate would either duplicate child method source or accidentally place the mode helper under FontImageLib.

Best defensible member layout and names:

- Object size is `0x8001c`.
- The vptr is at `+0x0`.
- `m_slots[2]` occupies `+0x4` through `+0x80013`; each slot is `0x40008`.
- Each slot has a DAT/resource file pointer at `+0x0`, two 16-bit metrics/config fields at `+0x4` and `+0x6`, and a `0x10000` pointer table at `+0x8`.
- The scratch/tile output fields are `+0x80014` and `+0x80018`; source-facing names should be conservative, such as `m_scratchPixels` and `m_scratchCapacityBytes`, until every grow/free path is fully typed.
- Glyph records are variable payload records. The documented fields `advance`, `top`, `left`, `bottom`, `right`, two reserved/unknown 16-bit values, and encoded row bytes are defensible. The final header should avoid overnaming the `+0xa` and `+0xc` fields until the decoder/EPF-tile consumer evidence resolves them.

Evidence checked:

- IDA function boundaries and raw byte padding across the entire `0x004b5f00-0x004b6409` interval.
- Constructor instruction sequence, startup allocation size, singleton write, vtable install, and `_memset` length.
- Vtable dwords, read-only string placement, vtable xrefs, and inherited LObject virtual slot pages.
- Call graph edges: metrics and measure call the lazy loader; measure calls the glyph decoder; loader and decoder have the expected allocator/DAT/EPFTileContext support calls.
- `g_pFontImageLib` xrefs and current initial bytes.
- Existing generated output is still only a placeholder for `NexusTK/render/FontImageLib.cpp`; no emitted C++ depends on the aggregate today.
- Existing B reports do not provide a competing exact reconstruction for this island.

Rejected alternatives:

- GrafPort ownership is rejected. GrafPort and UI text code consume the singleton but do not allocate the object, install the vtable, own the slots, or clear the singleton.
- ImageLib ownership is rejected. The startup allocator calls ImageLib immediately nearby, but that is a separate object with a different size and constructor. The `0x8001c` allocation and FontImageLib vtable isolate this class.
- DATArchive/DATFile ownership is rejected. The lazy loader uses DAT-style file APIs and the `BARAM%02d.EFT` resource naming convention, but the font slot state, glyph record table, and decode semantics are FontImageLib-owned.
- Compiler/runtime-only treatment is rejected for the ordinary methods. Constructor/destructor/scalar deleting destructor have compiler ABI shape, but the class object, vtable, singleton, and source destructor obligation are real. Only alignment bytes should be ignored.
- Aggregate duplicate emission is rejected. Exact child pages already cover the source-level methods, and the aggregate includes a separate `g_useEpfAssets` helper. The aggregate should document coverage, not emit source.

Score, placement, and final-C++ impact:

- The fresh evidence is strong enough to raise [UID:0002HP] above the `85/85` gate as a reconstructable class child, but the final formal C++ should remain blank until the class-wide header and support-type naming pass lands.
- The aggregate can be scored higher as documentation after the split because all bytes are accounted for; however, it must become non-reconstructable/non-emitting because it is not a source unit.
- [UID:0002HQ], [UID:0002HR], [UID:0002HS], and [UID:0002HT] should move from direct file owner/emitter [UID:0000JH] to class owner/emitter [UID:00005B]. The route still ends in `NexusTK/render/FontImageLib.cpp`.
- [UID:0002HU] can be lifted from low score because vtable and boundary evidence are now direct, but its formal source block should stay blank because scalar deleting destructors should be regenerated from the class destructor/ABI model, not hand-authored as ordinary application C++.

## Child Recheck Notes

[UID:0002HP] constructor:

- Fresh IDA validates every main field claim and removes stale MCP-timeout language.
- Constructor identity is `FontImageLib::FontImageLib`, not a base constructor and not ImageLib.
- Recommended score: 88/92.

[UID:00015B] ordinary destructor:

- Class ownership and vtable reset are supported by direct xrefs to the FontImageLib vtable.
- It calls the free/cleanup routines for slot and scratch state, clears `g_pFontImageLib`, restores the LObject vtable, and calls `LObject::~LObject`.
- Recommended score: 86/91.

[UID:0002HQ] metrics accessor:

- This is a FontImageLib class method, not a free file helper. It calls the lazy slot loader and reads the selected slot metric fields.
- Recommended owner/emitter: [UID:00005B], not [UID:0000JH].
- Recommended score remains 86/90; the coverage report is stale at 76%.

[UID:0002HR] glyph measure/draw setup:

- This is a FontImageLib class method. It calls the lazy loader, uses glyph lookup/measure support, and reaches the decoder path.
- Recommended owner/emitter: [UID:00005B], not [UID:0000JH].
- Recommended score remains 86/90.

[UID:0002HS] lazy slot loader:

- This is the class loader for the two font slots. `BARAM%02d.EFT` is the validated resource string at `0x0061a600`.
- The source-facing slot names should avoid `BA0`/`BA1`; the evidence supports two indexed font resource slots selected through the format string.
- Recommended owner/emitter: [UID:00005B], not [UID:0000JH].
- Recommended score remains 88/92.

[UID:0002HT] glyph decoder:

- This is a FontImageLib class method that expands glyph payload into EPF/tile/scratch output. The EPFTileContext output relationship is supported by callees and field use, but final type names should stay conservative.
- Recommended owner/emitter: [UID:00005B], not [UID:0000JH].
- Recommended score remains 88/92.

[UID:0002HU] scalar deleting destructor:

- Vtable slot `0x0061a5f4` points here, and the body has the expected ABI wrapper shape around destructor cleanup and conditional delete.
- Recommended score: 86/92.
- Formal C++ should remain blank or be represented only through ABI-wrapper metadata, not hand-authored application source.

New child needed for `0x004b60b0-0x004b60bd`:

- Recommended page: `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`
- Recommended owner/emitter: [UID:0000SW] `g_useEpfAssets`, because the helper is a pure query over that global and current project ownership places the mode byte with StartupWindow support.
- Recommended score: 86/90 after creating the exact child and documenting its 33 broad callers.
- Formal C++ should remain blank until the source-facing helper name is accepted.

## Support Docs Needing Updates

- [UID:00015A] should become a non-emitting index and list every exact child plus internal padding, including the newly discovered `0x004b60b0` helper.
- [UID:0002HP] should remove the stale MCP-timeout caveat and record fresh constructor/startup/vtable/global evidence.
- [UID:0002HQ], [UID:0002HR], [UID:0002HS], and [UID:0002HT] should change direct owner/emitter from [UID:0000JH] to [UID:00005B].
- [UID:00015B] and [UID:0002HU] should record fresh boundary/vtable/global-clear evidence and score lift.
- [UID:0000QX] and [UID:0001P2] should replace `0xffffffff` initial-value language with the current IDA zero-filled static image / value `0x0`.
- Generated `NexusTK/render/FontImageLib.cpp` can remain a placeholder until the class-wide final-C++ pass; it should not receive aggregate-emitted code from [UID:00015A].

## Exact Coverage Rows For Supervisor

Placement context: replace the current [UID:00015A] block in `by-memory/-coverage-report.md`, between the existing `0x004b5efc-0x004b5f00` padding row and the existing `0x004b6409-0x004b6410` padding row. Use the assigned UID in place of `UID:NEWID` after the new `0x004b60b0-0x004b60bd` child page is created.

```markdown
    - [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md) 0x004b5f00-0x004b6409 | mixed executable index | FontImageLib method island plus asset-mode helper : not_reconstructable : 88% : very-strong : Reviewed non-emitting physical index; exact FontImageLib method children carry class-owned reconstruction, while fresh IDA proves a real `g_useEpfAssets != 1` helper at `0x004b60b0-0x004b60bd`, so the aggregate must not emit duplicate FontImageLib source.
        - [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md) 0x004b5f00-0x004b5f54 | function | FontImageLib::FontImageLib : reconstructable : 88% : very-strong : Fresh IDA confirms `LObject::LObject` base call, singleton write to `g_pFontImageLib`, FontImageLib vtable install, `_memset(this+4,0,0x80010)`, scratch pointer/capacity clears at `+0x80014/+0x80018`, return `this`, and startup allocation size `0x8001c`.
        - [UID:0000VN][-ignored-](by-memory/-ignored-.md) 0x004b5f54-0x004b5f60 | padding | FontImageLib constructor-to-destructor alignment : ignored : 100% : strong : Fresh IDA/raw bytes show only `0xcc` alignment padding between exact function ends.
        - [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md) 0x004b5f60-0x004b5fe6 | function | FontImageLib::~FontImageLib : reconstructable : 86% : very-strong : Fresh IDA confirms ordinary destructor boundary, FontImageLib vtable restore, slot/scratch cleanup calls, `g_pFontImageLib` clear, and `LObject::~LObject` tail cleanup; formal C++ remains blank pending class-wide destructor/source-shape pass.
        - [UID:0000VN][-ignored-](by-memory/-ignored-.md) 0x004b5fe6-0x004b5ff0 | padding | FontImageLib destructor-to-metrics alignment : ignored : 100% : strong : Fresh IDA/raw bytes show only `0xcc` alignment padding.
        - [UID:0002HQ][0x004b5ff0-0x004b6018.FontImageLibMetrics](by-memory/0x004b5ff0-0x004b6018.FontImageLibMetrics.md) 0x004b5ff0-0x004b6018 | function | FontImageLib metrics accessor : reconstructable : 86% : strong : Class-owned FontImageLib method; calls lazy slot loader and reads selected slot metric fields. Owner/emitter should be [UID:00005B], with final route through `NexusTK/render/FontImageLib.cpp`.
        - [UID:0000VN][-ignored-](by-memory/-ignored-.md) 0x004b6018-0x004b6020 | padding | FontImageLib metrics-to-measure alignment : ignored : 100% : strong : Fresh IDA/raw bytes show only `0xcc` alignment padding.
        - [UID:0002HR][0x004b6020-0x004b60ae.FontImageLibMeasure](by-memory/0x004b6020-0x004b60ae.FontImageLibMeasure.md) 0x004b6020-0x004b60ae | function | FontImageLib glyph measure/draw setup : reconstructable : 86% : strong : Class-owned FontImageLib method; calls lazy slot loader and glyph decode/support path. Owner/emitter should be [UID:00005B], with final route through `NexusTK/render/FontImageLib.cpp`.
        - [UID:0000VN][-ignored-](by-memory/-ignored-.md) 0x004b60ae-0x004b60b0 | padding | FontImageLib measure-to-mode-helper alignment : ignored : 100% : strong : Fresh IDA/raw bytes show two `0xcc` bytes before the next real helper.
        - [UID:NEWID][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) 0x004b60b0-0x004b60bd | function | IsLegacyAssetMode / g_useEpfAssets query helper : reconstructable : 86% : strong : Fresh IDA proves `xor eax,eax; cmp byte_66DA97,1; setnz al; retn`, with 33 broad code callers. Recommended owner/emitter is [UID:0000SW] `g_useEpfAssets`; not FontImageLib, GrafPort, ImageLib, or DATArchive.
        - [UID:0000VN][-ignored-](by-memory/-ignored-.md) 0x004b60bd-0x004b60c0 | padding | mode-helper-to-FontImageLib-loader alignment : ignored : 100% : strong : Fresh IDA/raw bytes show three `0xcc` bytes after the helper return.
        - [UID:0002HS][0x004b60c0-0x004b61d9.FontImageLibSlotLoad](by-memory/0x004b60c0-0x004b61d9.FontImageLibSlotLoad.md) 0x004b60c0-0x004b61d9 | function | FontImageLib lazy font-slot loader : reconstructable : 88% : very-strong : Class-owned FontImageLib loader; validates two indexed font slots, `BARAM%02d.EFT` resource format, DAT-style file operations, and slot table population. Owner/emitter should be [UID:00005B].
        - [UID:0000VN][-ignored-](by-memory/-ignored-.md) 0x004b61d9-0x004b61e0 | padding | FontImageLib loader-to-decoder alignment : ignored : 100% : strong : Fresh IDA/raw bytes show only `0xcc` alignment padding.
        - [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibGlyphDecode](by-memory/0x004b61e0-0x004b6341.FontImageLibGlyphDecode.md) 0x004b61e0-0x004b6341 | function | FontImageLib glyph decoder : reconstructable : 88% : very-strong : Class-owned FontImageLib decoder; validates glyph record read/decode path, scratch/tile output handling, and EPFTileContext-adjacent support calls. Owner/emitter should be [UID:00005B].
        - [UID:0000VN][-ignored-](by-memory/-ignored-.md) 0x004b6341-0x004b6350 | padding | FontImageLib decoder-to-scalar-destructor alignment : ignored : 100% : strong : Fresh IDA/raw bytes show only `0xcc` alignment padding.
        - [UID:0002HU][0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor](by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md) 0x004b6350-0x004b6409 | function | FontImageLib scalar deleting destructor : reconstructable : 86% : very-strong : Fresh IDA confirms vtable slot target at `0x0061a5f4`, ABI wrapper shape, destructor cleanup path, conditional delete, and `g_pFontImageLib` clear; formal C++ should be ABI metadata/blank rather than hand-authored application source.
```

Placement context for `g_pFontImageLib`: replace only the [UID:0001P2] row text, keeping its existing position under the globals block.

```markdown
    - [UID:0001P2][0x0067ab24-0x0067ab28.g_pFontImageLib](by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md) 0x0067ab24-0x0067ab28 | global pointer | g_pFontImageLib : reconstructable : 86% : strong : Exact four-byte FontImageLib singleton slot; current IDA reads zero-filled bytes around `0x0067ab24` and value `0x0`, with 52 xrefs including constructor write at `0x004b5f24`, ordinary/scalar destructor clears, application startup/cleanup refs, GrafPort glyph/text clusters, later UI text consumers, and parent `g_pFontImageLib`.
```

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:00015A]. It should become a non-reconstructable, non-emitting index, and it contains a real non-FontImageLib helper at `0x004b60b0`.

Do not populate formal C++ for [UID:0002HP] or the sibling methods in this pass even where the recommended score clears the `85/85` gate. The evidence is strong enough for metadata and source placement, but the accepted source needs a single class-wide header/source pass that settles field names, DATFile-facing type names, EPFTileContext output names, glyph record reserved fields, and scalar deleting destructor policy. Entering only the constructor now would create a misleading partial formal implementation.

Review-only source shape for the future class-wide pass:

```cpp
// Review-only sketch. Do not paste into formal reconstruction blocks in this pass.
struct FontGlyphRecord {
    int16_t advance;
    int16_t top;
    int16_t left;
    int16_t bottom;
    int16_t right;
    int16_t reserved0;
    int16_t reserved1;
    uint8_t encodedRows[1];
};

struct FontSlotStorage {
    DATFile* file;
    uint16_t metric0;
    uint16_t metric1;
    FontGlyphRecord* glyphs[0x10000];
};

class FontImageLib : public LObject {
public:
    FontImageLib();
    ~FontImageLib() override;

private:
    FontSlotStorage m_slots[2];
    uint8_t* m_scratchPixels;
    uint32_t m_scratchCapacityBytes;
};

FontImageLib::FontImageLib()
    : LObject(),
      m_scratchPixels(nullptr),
      m_scratchCapacityBytes(0)
{
    g_pFontImageLib = this;
    memset(m_slots, 0, sizeof(m_slots));
}

// Separate helper, not a FontImageLib member. Final name/file still needs acceptance.
bool IsLegacyAssetMode()
{
    return g_useEpfAssets != 1;
}
```

The constructor sketch reflects source intent, not instruction order. The compiler installs the vtable and emits the null-adjust guarded singleton store shape seen in IDA.

## Validation Commands

Recommended after supervisor-owned doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [00015A-0002HP-fontimagelib-source-quality-removed.md](00015A-0002HP-fontimagelib-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Also rerun the memory range refresh/rescore workflow used by the supervisor after adding the new helper/padding rows, because the old coverage block omits internal padding and treats [UID:00015A] as a pure FontImageLib aggregate.

## Final Decision

- [UID:00015A] should be a non-emitting split/index, not an emitting aggregate.
- [UID:0002HP] should be upgraded with fresh IDA evidence and kept class-owned under [UID:00005B].
- Exact child method ownership should be normalized to [UID:00005B] for all FontImageLib class methods.
- A new child page is needed for `0x004b60b0-0x004b60bd`; it is a `g_useEpfAssets` query helper, not FontImageLib.
- `g_pFontImageLib` support docs should correct the initial/static value from `0xffffffff` to zero-filled/current `0x0`.
- Formal C++ should remain blank in this pass for the aggregate and all children until the class-wide source/header reconstruction is applied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00015A-0002HP-fontimagelib-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"00015A"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015A-0002HP-fontimagelib-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00015A-0002HP-fontimagelib-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
