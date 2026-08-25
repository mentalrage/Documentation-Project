** TARGET-REPORT-UID:0000NT **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B013 Research Report: [UID:0000NT] SoftwareBlend16 Empty-Emitter Family

Report status: `FINISHED_IMPLEMENTATION`

Target: [UID:0000NT] `by-file/SoftwareBlend16.md`

Report path: `tools/leaser/Agents/Agent-B013/research/0000NT-SoftwareBlend16-empty-emitter-family-source-quality.md`

Mode: implementation callback complete. The accepted by-* docs were edited under B013 leases, scoped validators were run, generated `SoftwareBlend16.cpp` was inspected after validator refresh, and this report checklist/ledger was updated. No generated files, coverage reports, validator state, lock files, IDA DB, executed archives, or supervisor ledgers were manually edited. No subagents were used.

## Required Workflow Inputs

- Read `tools/leaser/Agents/Agent-B013/goal.md` for assignment `B013-report-0000NT-SoftwareBlend16-empty-emitter-family-20260630`.
- Used project-level `ntk-b-agent-workflow` skill as the B-agent operating manual.
- Read `by-structure.md`, `by-file/-guidance.md`, `by-memory/-guidance.md`, and `by-item/-guidance.md`.
- Inspected target/support docs for the 22 current SoftwareBlend16 empty markers plus the parent `by-file/SoftwareBlend16.md`.
- Inspected current generated file `auto-generated/NexusTK/render/SoftwareBlend16.cpp`.
- Searched/opened matching executed reports as leads and reconciled them against the current generated state.
- Used IDA MCP database `supervisor_resume_20260629` for current evidence.

## MCP Availability And Generated State

MCP was available during the report. Current checks:

- `idb_list`: HTTP 200 / JSON-RPC ok. One active session, `session_id:"supervisor_resume_20260629"`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, `pid:17592`, `worker_pid:17592`, `is_analyzing:false`.
- `server_health(database="supervisor_resume_20260629")`: HTTP 200 / JSON-RPC ok. `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size 2067.
- Latest generated output header observed for `SoftwareBlend16.cpp`: `validator-command-id: 000000001629`, `validator-refreshed-at: 2026-06-29T23:45:30-04:00`.
- Current tracker row: `[UID:0000NT] SoftwareBlend16` has 38 total entries, 16 emitted entries, 22 empty entries, 42.1% filled, generated path `auto-generated/NexusTK/render/SoftwareBlend16.cpp`.

## Current Empty Marker List

The current generated file contains these 22 empty markers under `SoftwareBlend16.cpp`:

| UID | Path | Current score | Current emitted state |
|---|---|---:|---|
| 0000TW | `by-item/AlphaBlendSpan16Blocks_00460B00.md` | 86/91 | Empty marker |
| 0000TV | `by-item/AlphaBlendSpan16_00460500.md` | 88/92 | Empty marker |
| 0000TZ | `by-item/BlendRgb555_004C0710.md` | 86/91 | Empty marker |
| 0000U0 | `by-item/BlendRgb565Pair_004C60D0.md` | 88/90 | Empty marker |
| 0000U1 | `by-item/BlendRgb565Pixel_004C6050.md` | 86/90 | Empty marker |
| 0000US | `by-item/HalfBlendSpan16Blocks_00460C10.md` | 85/90 | Empty marker |
| 000206 | `by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md` | 85/89 | Empty marker |
| 000207 | `by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md` | 85/89 | Empty marker |
| 000209 | `by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md` | 86/91 | Empty marker |
| 0000YG | `by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md` | 85/90 | Empty marker |
| 00020A | `by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md` | 86/91 | Empty marker |
| 00020B | `by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md` | 85/89 | Empty marker |
| 00020C | `by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md` | 86/91 | Empty marker |
| 00020D | `by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md` | 86/91 | Empty marker |
| 00020E | `by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md` | 86/91 | Empty marker |
| 00020F | `by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md` | 85/90 | Empty marker |
| 00020G | `by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md` | 85/90 | Empty marker |
| 00020H | `by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md` | 85/90 | Empty marker |
| 00020I | `by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md` | 85/90 | Empty marker |
| 00016M | `by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md` | 90/92 | Empty marker |
| 00016N | `by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md` | 88/91 | Empty marker |
| 0002OO | `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md` | 86/90 | Empty marker |

All 22 marker docs currently have `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`. That metadata route is valid; the unresolved defect is the blank emitted body/comment, stale source-form language, and a few outdated score rationales.

## Matching Executed Reports Reconciled

These executed reports were useful leads, but several are stale under the current score-blocker audit standard because they ended in broad "leave blank until a family-wide source-form pass" language:

- `executed-b-agent-research/B001/000206-softwareblend16-raw-span-source-quality.md`: useful raw-range evidence for UID000206, UID000207, and UID00020B, including raw-start no-xref facts and body uniqueness. Stale disposition: kept C++ blank.
- `executed-b-agent-research/B001/000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality.md`: useful source-authored helper evidence and behavior summaries. Stale disposition: kept C++ blank pending a broad pass.
- `executed-b-agent-research/B001/0000YG-softwareblend16-halfblend-block-source-quality.md`: useful half-blend block evidence. Stale disposition: kept C++ blank pending a broad pass.
- `executed-b-agent-research/B001/0000YD-Rgb555565BlitHelpers-empty-emitter-source-quality.md`: important accepted precedent. It split and emitted UID0004BB-UID0004BL, including several MMX-range block helpers as behavior-preserving C++ loops.
- `executed-b-agent-research/B002/0000YE-AlphaBlendSpan16-empty-emitter-source-quality.md`: accepted precedent for formal `AlphaBlendSpan16` wrapper C++ with prototypes for block helpers.
- `executed-b-agent-research/B003/0000YF-AlphaBlendSpan16Blocks-empty-emitter-source-quality.md`: accepted precedent for the RGB565 block family and local mask/weight constants.
- `executed-b-agent-research/B006/000208-BlitTransparentShadow565MmxBlocks-empty-emitter-source-quality.md`: accepted precedent for target-local MMX block helper reconstruction.
- `executed-b-agent-research/B012/00028W-MmxBlendWeightScratchData-empty-emitter-source-quality.md`: accepted precedent for a formal no-standalone-source comment marker for a SoftwareBlend16 data range covered by helper-local source.
- `executed-b-agent-research/B002/00016K-BlendRgb555-empty-emitter-source-quality.md`: accepted scalar RGB555 blend precedent for UID00016M/UID00016N.

Conclusion: the older no-code blockers are not valid final dispositions now. The current generated file and accepted SoftwareBlend16 precedents provide enough source-form policy to resolve every current marker with either formal C++ or exact no-code/covered-by marker text.

## Current MCP Evidence Summary

### Function boundaries and names

`lookup_funcs(database="supervisor_resume_20260629")` confirms the modeled and raw split:

- `0x00460500`: `sub_460500`, size `0x209`; current emitted canonical UID0000YE.
- `0x00460710`: not a modeled IDA function; raw retained body for UID000206.
- `0x004607e0`: not a modeled IDA function; raw retained body for UID000207.
- `0x00460940`: `sub_460940`, size `0x93`; current emitted UID000208.
- `0x004609e0`: `sub_4609E0`, size `0x119`; UID000209.
- `0x00460b00`: `sub_460B00`, size `0x10a`; current emitted UID0000YF.
- `0x00460c10`: `sub_460C10`, size `0x7c`; UID0000YG.
- `0x00460c90`: `sub_460C90`, size `0xc1`; UID00020A.
- `0x00460d60`: not a modeled IDA function; raw retained body for UID00020B.
- `0x00460df0`: `sub_460DF0`, size `0x89`; UID00020C.
- `0x00460e80`: `sub_460E80`, size `0x89`; UID00020D.
- `0x00460f10`: `sub_460F10`, size `0x89`; UID00020E.
- `0x00460fa0`: `sub_460FA0`, size `0x5e`; UID00020F.
- `0x00461000`: `sub_461000`, size `0x4b`; UID00020G.
- `0x00461050`: `sub_461050`, size `0x4e`; UID00020H.
- `0x004610a0`: `sub_4610A0`, size `0x4e`; UID00020I.
- `0x004c0710`: `sub_4C0710`, size `0x5d`; current emitted UID00016K.
- `0x004c6050`: `sub_4C6050`, size `0x77`; UID00016M.
- `0x004c60d0`: `sub_4C60D0`, size `0x81`; UID00016N.
- `0x00610e38` through `0x00610ed8`: data, not functions; UID0002OO.

Name lookup did not find source names such as `AlphaBlendSpan16Blocks`, `HalfBlendSpan16Blocks`, `BlendRgb565Pixel`, `BlendRgb565Pair`, `ByteSpanFillRows`, `ByteSpanCopyRows`, `ByteSpanAddRows`, or `ByteSpanSubtractRows`. Therefore names remain source-quality reconstructions, not debug-symbol proof.

### Cross-references and calls

`xrefs_to` and `callees` show the helper family is internally coherent:

- `0x00460500` has one external code xref at `0x004c2ad4`; it calls `0x00460c10` and `0x00460b00`.
- `0x00460710`, `0x004607e0`, and `0x00460d60` have no xrefs to their raw starts. They still have fresh prologue/return bodies with exact padding after their ranges.
- Raw UID000206 calls `0x00460c10` at `0x0046073e`.
- Raw UID000207 calls `0x004609e0` at `0x00460818`.
- Raw UID00020B calls `0x00460fa0` at `0x00460d8e`.
- `0x004609e0`, `0x00460c10`, `0x00460c90`, `0x00460fa0`, `0x00461000`, `0x00461050`, and `0x004610a0` have no callees.
- `0x00460df0` calls `0x00461000`.
- `0x00460e80` calls `0x00461050`.
- `0x00460f10` calls `0x004610a0`.
- `0x004c6050` has 17 code xrefs from RGB565 callback family functions and no callees.
- `0x004c60d0` has 4 code xrefs from RGB565 callback family functions and no callees.
- UID0002OO qwords each have one data xref from SoftwareBlend16 helper code at addresses in `0x0045ff68`, `0x0045ff72`, `0x00460038`, `0x0046003f`, `0x00460168`, `0x0046016f`, `0x00460238`, `0x0046023f`, `0x004602bb`, `0x004602c2`, `0x00460951`, `0x0046095b`, `0x00460a28`, `0x00460a2f`, `0x00460b51`, `0x00460b58`, `0x00460c21`, `0x00460c28`, `0x00460ca4`, and `0x00460cab`.

### Bytes, padding, and data

`get_bytes` confirms exact function/range endings:

- `0x00460709` has seven `0xcc` bytes after UID0000YE before raw UID000206.
- `0x0046093c` has four `0xcc` bytes after raw UID000207.
- `0x00460af9` has seven `0xcc` bytes after UID000209.
- `0x00460c0a` has six `0xcc` bytes after UID0000YF.
- `0x00460c8c` has four `0xcc` bytes after UID0000YG.
- `0x00460d51` has fifteen `0xcc` bytes after UID00020A.
- `0x00460dee` has two `0xcc` bytes after raw UID00020B.
- `0x00460e79`, `0x00460f09`, and `0x00460f99` each have seven `0xcc` bytes after UID00020C/00020D/00020E.
- `0x00460ffe`, `0x0046109e`, and `0x004610ee` each have two `0xcc` bytes after UID00020F/00020H/00020I; `0x0046104b` has five `0xcc` bytes after UID00020G.
- `0x004c60c7` has nine `0xcc` bytes after UID00016M; `0x004c6151` has fifteen `0xcc` bytes after UID00016N.
- `0x00610e38` size 160 returns the qword mask/constant table already inventoried in UID0002OO.

### Decompile/disassembly behavior

Current MCP decompilation/disassembly supports these behavior assignments:

- UID000206 raw body: six-argument span wrapper; computes `widthPixels / 4`, calls `HalfBlendSpan16Blocks` at `0x0046073e`, then handles tail pixels with RGB565 half-blend formula `((source >> 1) & 0x7bef) + ((destination >> 1) & 0x7bef) + (source & destination & 0x0821)`, stepping rows by byte pitches.
- UID000207 raw body: seven-argument transparent alpha span wrapper; computes source weight `32 - alpha`, calls UID000209 at `0x00460818`, then tail-skips `source == 0` and blends RGB565 red/blue mask `0xf81f` and green mask `0x07e0`.
- UID000209: transparent RGB565 block helper over qword/four-pixel groups. It preserves destination pixels for zero source words and otherwise blends with source/destination 5-bit weights.
- UID0000YG: RGB565 half-blend block helper over four-pixel groups, masks `0xf7def7def7def7de` and `0x0821082108210821`, equivalent to per-pixel `0x7bef/0x0821` half blend.
- UID00020A: RGB565 alpha-map block helper; reads alpha bytes, scales RGB565 channels in-place with 5-bit weight semantics.
- UID00020B raw body: fill-row wrapper; computes `widthBytes / 8`, calls UID00020F at `0x00460d8e`, then fills tail bytes with the byte value using repeated stores and advances by destination pitch.
- UID00020C/00020D/00020E: copy/add/subtract row wrappers; split width into eight-byte blocks and byte tails; call UID00020G/00020H/00020I respectively; tail add/subtract are wrapping byte operations.
- UID00020F: fill eight-byte block helper; broadcasts the fill byte into qword stores.
- UID00020G: copy eight-byte block helper; copies qwords row by row.
- UID00020H: add eight-byte block helper; uses `paddb`, so source-level semantics are modulo-256 byte addition.
- UID00020I: subtract eight-byte block helper; uses `psubb`, so source-level semantics are modulo-256 byte subtraction.
- UID00016M: scalar RGB565 blend helper; weights first pixel by `firstWeight32`, second by `32 - firstWeight32`, masks `0xf81f` and `0x07e0`, shifts by 5.
- UID00016N: packed two-RGB565-pixel blend helper; same weights as UID00016M, applied to low and high 16-bit lanes.
- UID0002OO: read-only MMX mask constants used only by SoftwareBlend16 helper bodies; no independent behavior beyond helper-local masks.

## Heuristic Reanalysis

The old blank C++ disposition for the remaining SoftwareBlend16 rows is no longer justified:

- The generated file already accepts behavior-preserving C++ loop source for several MMX-range child helpers from UID0000YD, so "MMX helper" is not by itself a no-code blocker.
- UID0000YE, UID0000YF, UID000208, UID00016K, and UID00028W establish current SoftwareBlend16 source-form policy: wrappers can emit with helper prototypes, block helpers can emit source-level C++ or target-local inline assembly where appropriate, scalar blend helpers can emit exact C++, and helper-owned data/scratch ranges can use formal covered-by comments.
- By-item rows are duplicate index/alias pages for canonical by-memory bodies. Duplicating code into those rows would create duplicate emitted bodies; blank markers should be replaced by target-specific covered-by comments.
- Raw start no-xrefs for UID000206/UID000207/UID00020B remain important confidence caps, but not no-code blockers. Their bodies have exact prologue/return/padding, internal calls into sibling helpers, and source-authored retained behavior. Formal C++ can be emitted as static retained helpers with the raw-start caveat documented.
- UID0002OO should not emit a standalone file-scope constant table. Current accepted helper bodies either already carry local constants or can carry equivalent scalar immediates. A standalone declaration would introduce a source artifact not proven by the current reconstruction policy.

No current row needs a lease-time split before implementation. No owner route, emitter route, or index metadata repair is required; the repair is formal C++ or exact formal no-code comment text plus by-file support text and score rationale.

## Row-By-Row Disposition

| UID | Disposition | Required implementation detail |
|---|---|---|
| 0000TW | Covered-by/no-code marker | Add formal comment covered by canonical UID0000YF. Keep metadata/score unless supervisor wants alias-score normalization. |
| 0000TV | Covered-by/no-code marker | Add formal comment covered by canonical UID0000YE. Keep metadata/score. |
| 0000TZ | Covered-by/no-code marker | Add formal comment covered by canonical UID00016K. Keep metadata/score. |
| 0000U0 | Covered-by/no-code marker | Add formal comment covered by canonical UID00016N. Keep metadata/score. |
| 0000U1 | Covered-by/no-code marker | Add formal comment covered by canonical UID00016M. Keep metadata/score. |
| 0000US | Covered-by/no-code marker | Add formal comment covered by canonical UID0000YG. Keep metadata/score. |
| 000206 | Formal C++ | Add static `HalfBlendSpan16` wrapper code. Recommend score 85/89 -> 88/90. |
| 000207 | Formal C++ | Add static `Rgb565TransparentAlphaBlendSpan` wrapper code. Recommend score 85/89 -> 88/90. |
| 000209 | Formal C++ | Add static `Rgb565TransparentAlphaBlendMmxBlocks` behavior-preserving block code. Recommend score 86/91 -> 88/91. |
| 0000YG | Formal C++ | Add static `HalfBlendSpan16Blocks` behavior-preserving block code. Recommend score 85/90 -> 88/91. |
| 00020A | Formal C++ | Add static `Rgb565AlphaMapMmxBlocks` behavior-preserving block code. Recommend score 86/91 -> 88/91. |
| 00020B | Formal C++ | Add static `ByteSpanFillRows` wrapper code. Recommend score 85/89 -> 88/90. |
| 00020C | Formal C++ | Add `ByteSpanCopyRows` wrapper code. Recommend score 86/91 -> 88/91. |
| 00020D | Formal C++ | Add `ByteSpanAddRows` wrapper code. Recommend score 86/91 -> 88/91. |
| 00020E | Formal C++ | Add `ByteSpanSubtractRows` wrapper code. Recommend score 86/91 -> 88/91. |
| 00020F | Formal C++ | Add static `ByteSpanFill8Blocks` block code. Recommend score 85/90 -> 88/91. |
| 00020G | Formal C++ | Add static `ByteSpanCopy8Blocks` block code. Recommend score 85/90 -> 88/91. |
| 00020H | Formal C++ | Add static `ByteSpanAdd8Blocks` block code. Recommend score 85/90 -> 88/91. |
| 00020I | Formal C++ | Add static `ByteSpanSubtract8Blocks` block code. Recommend score 85/90 -> 88/91. |
| 00016M | Formal C++ | Add `BlendRgb565Pixel` scalar helper code. Current 90/92 can remain. |
| 00016N | Formal C++ | Add `BlendRgb565Pair` packed helper code. Recommend score 88/91 -> 90/92. |
| 0002OO | Covered-by/no-code marker | Add formal comment covered by SoftwareBlend16 helper-local constants/immediates. Recommend score 86/90 -> 88/91. |

Parent target `by-file/SoftwareBlend16.md`: recommend score 86/88 -> 88/90 after implementation, because this report resolves all current empty markers but still leaves original source names/static declarations partly inferred.

## Exact Formal RECONSTRUCTION_CPP CODE Insertion Text

### [UID:0000TW] `by-item/AlphaBlendSpan16Blocks_00460B00.md`

```cpp
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:0000YF]. Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000TW].
```

Target-specific proof: the by-item address `0x00460b00` is the same body as canonical UID0000YF `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`, which already emits formal C++ in the current generated file. A duplicate body under the alias would double-emit the same helper.

### [UID:0000TV] `by-item/AlphaBlendSpan16_00460500.md`

```cpp
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:0000YE]. Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000TV].
```

Target-specific proof: the by-item address `0x00460500` is the same body as canonical UID0000YE `by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md`, which already emits formal C++ in the current generated file.

### [UID:0000TZ] `by-item/BlendRgb555_004C0710.md`

```cpp
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:00016K]. Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000TZ].
```

Target-specific proof: the by-item address `0x004c0710` is the same scalar RGB555 helper as canonical UID00016K, which already emits formal C++ in the current generated file.

### [UID:0000U0] `by-item/BlendRgb565Pair_004C60D0.md`

```cpp
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:00016N]. Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000U0].
```

Target-specific proof: the by-item address `0x004c60d0` is the same body as canonical UID00016N. UID00016N should carry the formal `BlendRgb565Pair` implementation below; the alias should not emit a second function.

### [UID:0000U1] `by-item/BlendRgb565Pixel_004C6050.md`

```cpp
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:00016M]. Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000U1].
```

Target-specific proof: the by-item address `0x004c6050` is the same body as canonical UID00016M. UID00016M should carry the formal `BlendRgb565Pixel` implementation below; the alias should not emit a second function.

### [UID:0000US] `by-item/HalfBlendSpan16Blocks_00460C10.md`

```cpp
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:0000YG]. Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000US].
```

Target-specific proof: the by-item address `0x00460c10` is the same body as canonical UID0000YG. UID0000YG should carry the formal `HalfBlendSpan16Blocks` implementation below; the alias should not emit a second function.

### [UID:000206] `by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md`

```cpp
static void __cdecl HalfBlendSpan16Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount);

static void __cdecl HalfBlendSpan16(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int widthPixels,
    int rowCount)
{
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (blockCount4Pixels > 0) {
        HalfBlendSpan16Blocks(
            sourcePixels,
            sourcePitchBytes,
            destinationPixels,
            destinationPitchBytes,
            blockCount4Pixels,
            rowCount);

        sourcePixels += blockCount4Pixels * 4;
        destinationPixels += blockCount4Pixels * 4;
    }

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            const unsigned int destination = destinationPixels[pixelIndex];

            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                ((source >> 1) & 0x7bef) +
                ((destination >> 1) & 0x7bef) +
                (source & destination & 0x0821));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
```

Target-specific proof: MCP disassembly at `0x00460710` shows a fresh prologue, `width / 4` block split, call to UID0000YG at `0x0046073e`, tail masks `0x7bef` and `0x0821`, byte-pitch row stepping, `retn` at `0x004607df`, and `0xcc` padding at `0x004607e0`.

### [UID:000207] `by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md`

```cpp
static void __cdecl Rgb565TransparentAlphaBlendMmxBlocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount);

static void __cdecl Rgb565TransparentAlphaBlendSpan(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned int alpha32,
    int widthPixels,
    int rowCount)
{
    const unsigned char alpha = static_cast<unsigned char>(alpha32);
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (blockCount4Pixels > 0) {
        Rgb565TransparentAlphaBlendMmxBlocks(
            sourcePixels,
            sourcePitchBytes,
            destinationPixels,
            destinationPitchBytes,
            static_cast<unsigned char>(32 - alpha),
            blockCount4Pixels,
            rowCount);

        sourcePixels += blockCount4Pixels * 4;
        destinationPixels += blockCount4Pixels * 4;
    }

    const unsigned int sourceWeight32 = static_cast<unsigned char>(32 - alpha);
    const unsigned int destinationWeight32 = alpha;

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            const unsigned int destination = destinationPixels[pixelIndex];
            const unsigned int redBlue =
                (sourceWeight32 * (source & 0xf81f) +
                 destinationWeight32 * (destination & 0xf81f)) >> 5;
            const unsigned int green =
                (sourceWeight32 * (source & 0x07e0) +
                 destinationWeight32 * (destination & 0x07e0)) >> 5;

            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (redBlue & 0xf81f) | (green & 0x07e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
```

Target-specific proof: MCP disassembly at `0x004607e0` shows a fresh raw body, block call to UID000209 at `0x00460818`, source-zero skip in the tail, RGB565 masks `0xf81f` and `0x07e0`, and row pitch stepping. No xrefs to the raw start remain a confidence cap, not a no-code blocker.

### [UID:000209] `by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md`

```cpp
static void __cdecl Rgb565TransparentAlphaBlendMmxBlocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount)
{
    const unsigned int sourceWeight = sourceWeight32;
    const unsigned int destinationWeight = static_cast<unsigned char>(32 - sourceWeight32);

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            const unsigned int destination = destinationPixels[pixelIndex];
            const unsigned int redBlue =
                (sourceWeight * (source & 0xf81f) +
                 destinationWeight * (destination & 0xf81f)) >> 5;
            const unsigned int green =
                (sourceWeight * (source & 0x07e0) +
                 destinationWeight * (destination & 0x07e0)) >> 5;

            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (redBlue & 0xf81f) | (green & 0x07e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
```

Target-specific proof: MCP decompile of `sub_4609E0` shows seven cdecl arguments, source/inverse weight setup, zero-source preservation, RGB565 red/blue and green masks, qword/four-pixel block iteration, no callees, and `0xcc` padding at `0x00460af9`.

### [UID:0000YG] `by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md`

```cpp
static void __cdecl HalfBlendSpan16Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount)
{
    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            const unsigned int destination = destinationPixels[pixelIndex];

            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                ((source >> 1) & 0x7bef) +
                ((destination >> 1) & 0x7bef) +
                (source & destination & 0x0821));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
```

Target-specific proof: MCP decompile of `sub_460C10` shows RGB565 half-blend qword masks equivalent to `0x7bef` and carry mask `0x0821`, four-pixel block traversal, no callees, xrefs from UID0000YE and raw UID000206, and padding at `0x00460c8c`.

### [UID:00020A] `by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md`

```cpp
static void __cdecl Rgb565AlphaMapMmxBlocks(
    unsigned short* pixels,
    int pixelPitchBytes,
    const unsigned char* alphaBytes,
    int alphaPitchBytes,
    int blockCount4Pixels,
    int rowCount)
{
    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            const unsigned int pixel = pixels[pixelIndex];
            const unsigned int alpha = alphaBytes[pixelIndex];

            const unsigned int redBlue =
                (alpha * (pixel & 0xf81f)) >> 5;
            const unsigned int green =
                (alpha * (pixel & 0x07e0)) >> 5;

            pixels[pixelIndex] = static_cast<unsigned short>(
                (redBlue & 0xf81f) | (green & 0x07e0));
        }

        pixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(pixels) + pixelPitchBytes);
        alphaBytes += alphaPitchBytes;
    }
}
```

Target-specific proof: MCP decompile of `sub_460C90` shows alpha-byte unpacking/scaling of RGB565 pixels in place, xref from `sub_460410`, no callees, and function padding at `0x00460d51`.

### [UID:00020B] `by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md`

```cpp
static void __cdecl ByteSpanFill8Blocks(
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    unsigned char value,
    int blockCount8Bytes,
    int rowCount);

static void __cdecl ByteSpanFillRows(
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    unsigned char value,
    int widthBytes,
    int rowCount)
{
    const int blockCount8Bytes = widthBytes / 8;
    const int tailBytes = widthBytes - blockCount8Bytes * 8;

    if (blockCount8Bytes > 0) {
        ByteSpanFill8Blocks(
            destinationBytes,
            destinationPitchBytes,
            value,
            blockCount8Bytes,
            rowCount);

        destinationBytes += blockCount8Bytes * 8;
    }

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < tailBytes; ++byteIndex) {
            destinationBytes[byteIndex] = value;
        }

        destinationBytes += destinationPitchBytes;
    }
}
```

Target-specific proof: MCP disassembly at raw `0x00460d60` shows a fresh body, `width / 8` split, call to UID00020F at `0x00460d8e`, tail fill via byte-repeated stores, destination pitch stepping, return at `0x00460ded`, and two `0xcc` bytes at `0x00460dee`.

### [UID:00020C] `by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md`

```cpp
static void __cdecl ByteSpanCopy8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount);

void __cdecl ByteSpanCopyRows(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int widthBytes,
    int rowCount)
{
    const int blockCount8Bytes = widthBytes / 8;
    const int tailBytes = widthBytes - blockCount8Bytes * 8;

    if (blockCount8Bytes > 0) {
        ByteSpanCopy8Blocks(
            sourceBytes,
            sourcePitchBytes,
            destinationBytes,
            destinationPitchBytes,
            blockCount8Bytes,
            rowCount);

        sourceBytes += blockCount8Bytes * 8;
        destinationBytes += blockCount8Bytes * 8;
    }

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < tailBytes; ++byteIndex) {
            destinationBytes[byteIndex] = sourceBytes[byteIndex];
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}
```

Target-specific proof: MCP decompile of `sub_460DF0` shows the row wrapper calls UID00020G at `0x00460e1f`, then handles tail bytes with direct copy and advances source/destination by byte pitches.

### [UID:00020D] `by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md`

```cpp
static void __cdecl ByteSpanAdd8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount);

void __cdecl ByteSpanAddRows(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int widthBytes,
    int rowCount)
{
    const int blockCount8Bytes = widthBytes / 8;
    const int tailBytes = widthBytes - blockCount8Bytes * 8;

    if (blockCount8Bytes > 0) {
        ByteSpanAdd8Blocks(
            sourceBytes,
            sourcePitchBytes,
            destinationBytes,
            destinationPitchBytes,
            blockCount8Bytes,
            rowCount);

        sourceBytes += blockCount8Bytes * 8;
        destinationBytes += blockCount8Bytes * 8;
    }

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < tailBytes; ++byteIndex) {
            destinationBytes[byteIndex] = static_cast<unsigned char>(
                destinationBytes[byteIndex] + sourceBytes[byteIndex]);
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}
```

Target-specific proof: MCP decompile of `sub_460E80` shows the row wrapper calls UID00020H at `0x00460eaf`, then tail-adds bytes with wrapping unsigned-byte semantics and advances by byte pitches.

### [UID:00020E] `by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md`

```cpp
static void __cdecl ByteSpanSubtract8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount);

void __cdecl ByteSpanSubtractRows(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int widthBytes,
    int rowCount)
{
    const int blockCount8Bytes = widthBytes / 8;
    const int tailBytes = widthBytes - blockCount8Bytes * 8;

    if (blockCount8Bytes > 0) {
        ByteSpanSubtract8Blocks(
            sourceBytes,
            sourcePitchBytes,
            destinationBytes,
            destinationPitchBytes,
            blockCount8Bytes,
            rowCount);

        sourceBytes += blockCount8Bytes * 8;
        destinationBytes += blockCount8Bytes * 8;
    }

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < tailBytes; ++byteIndex) {
            destinationBytes[byteIndex] = static_cast<unsigned char>(
                destinationBytes[byteIndex] - sourceBytes[byteIndex]);
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}
```

Target-specific proof: MCP decompile of `sub_460F10` shows the row wrapper calls UID00020I at `0x00460f3f`, then tail-subtracts bytes with wrapping unsigned-byte semantics and advances by byte pitches.

### [UID:00020F] `by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md`

```cpp
static void __cdecl ByteSpanFill8Blocks(
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    unsigned char value,
    int blockCount8Bytes,
    int rowCount)
{
    const int blockBytes = blockCount8Bytes * 8;

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < blockBytes; ++byteIndex) {
            destinationBytes[byteIndex] = value;
        }

        destinationBytes += destinationPitchBytes;
    }
}
```

Target-specific proof: MCP decompile of `sub_460FA0` shows fill-byte broadcast and qword stores over row/block loops, no callees, xref from raw UID00020B, and `0xcc` padding at `0x00460ffe`.

### [UID:00020G] `by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md`

```cpp
static void __cdecl ByteSpanCopy8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount)
{
    const int blockBytes = blockCount8Bytes * 8;

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < blockBytes; ++byteIndex) {
            destinationBytes[byteIndex] = sourceBytes[byteIndex];
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}
```

Target-specific proof: MCP decompile/disassembly of `sub_461000` shows qword copy blocks row by row with `pushaw`/`emms`, no callees, xref from UID00020C, and padding at `0x0046104b`.

### [UID:00020H] `by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md`

```cpp
static void __cdecl ByteSpanAdd8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount)
{
    const int blockBytes = blockCount8Bytes * 8;

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < blockBytes; ++byteIndex) {
            destinationBytes[byteIndex] = static_cast<unsigned char>(
                destinationBytes[byteIndex] + sourceBytes[byteIndex]);
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}
```

Target-specific proof: MCP decompile/disassembly of `sub_461050` shows qword block loops with `paddb`, so source-level behavior is modulo-256 byte addition. It has one xref from UID00020D and padding at `0x0046109e`.

### [UID:00020I] `by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md`

```cpp
static void __cdecl ByteSpanSubtract8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount)
{
    const int blockBytes = blockCount8Bytes * 8;

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < blockBytes; ++byteIndex) {
            destinationBytes[byteIndex] = static_cast<unsigned char>(
                destinationBytes[byteIndex] - sourceBytes[byteIndex]);
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}
```

Target-specific proof: MCP decompile/disassembly of `sub_4610A0` shows qword block loops with `psubb`, so source-level behavior is modulo-256 byte subtraction. It has one xref from UID00020E and padding at `0x004610ee`.

### [UID:00016M] `by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md`

```cpp
unsigned short __cdecl BlendRgb565Pixel(
    unsigned short firstPixel,
    unsigned short secondPixel,
    unsigned char firstWeight32)
{
    const unsigned int firstWeight = firstWeight32;
    const unsigned int secondWeight = static_cast<unsigned char>(32 - firstWeight32);

    const unsigned int redBlue =
        (firstWeight * (firstPixel & 0xf81f) +
         secondWeight * (secondPixel & 0xf81f)) >> 5;
    const unsigned int green =
        (firstWeight * (firstPixel & 0x07e0) +
         secondWeight * (secondPixel & 0x07e0)) >> 5;

    return static_cast<unsigned short>((redBlue & 0xf81f) | (green & 0x07e0));
}
```

Target-specific proof: MCP decompile of `sub_4C6050` shows first argument weighted by `a3`, second by `32 - a3`, RGB565 red/blue mask `0xf81f`, green mask `0x07e0`, shift by 5, 17 code xrefs, no callees, and padding at `0x004c60c7`.

### [UID:00016N] `by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md`

```cpp
unsigned int __cdecl BlendRgb565Pair(
    unsigned int firstPixels,
    unsigned int secondPixels,
    unsigned char firstWeight32)
{
    const unsigned int firstWeight = firstWeight32;
    const unsigned int secondWeight = static_cast<unsigned char>(32 - firstWeight32);

    const unsigned int firstLow = firstPixels & 0xffff;
    const unsigned int secondLow = secondPixels & 0xffff;
    const unsigned int lowRedBlue =
        (firstWeight * (firstLow & 0xf81f) +
         secondWeight * (secondLow & 0xf81f)) >> 5;
    const unsigned int lowGreen =
        (firstWeight * (firstLow & 0x07e0) +
         secondWeight * (secondLow & 0x07e0)) >> 5;
    const unsigned int lowPixel = (lowRedBlue & 0xf81f) | (lowGreen & 0x07e0);

    const unsigned int firstHigh = (firstPixels >> 16) & 0xffff;
    const unsigned int secondHigh = (secondPixels >> 16) & 0xffff;
    const unsigned int highRedBlue =
        (firstWeight * (firstHigh & 0xf81f) +
         secondWeight * (secondHigh & 0xf81f)) >> 5;
    const unsigned int highGreen =
        (firstWeight * (firstHigh & 0x07e0) +
         secondWeight * (secondHigh & 0x07e0)) >> 5;
    const unsigned int highPixel = (highRedBlue & 0xf81f) | (highGreen & 0x07e0);

    return lowPixel | (highPixel << 16);
}
```

Target-specific proof: MCP decompile of `sub_4C60D0` shows packed two-lane RGB565 blending with the same first/second weight convention as UID00016M, four code xrefs, no callees, and padding at `0x004c6151`. The formal source computes lanes separately to avoid cross-lane carry ambiguity in source-level packed arithmetic while preserving target behavior.

### [UID:0002OO] `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`

```cpp
// Emitted source for this read-only MMX mask table is covered by the
// SoftwareBlend16 helper bodies that carry the masks as local constants or
// equivalent scalar immediates: [UID:0004BF], [UID:0004BG],
// [UID:0004BH], [UID:0004BI], [UID:0004BJ], [UID:000208],
// [UID:000209], [UID:0000YF], [UID:0000YG], and [UID:00020A].
// No standalone file-scope data declaration is emitted for [UID:0002OO].
```

Target-specific proof: current MCP xrefs for the qwords in `0x00610e38-0x00610ed8` all originate from SoftwareBlend16 helper bodies and no external route uses the table independently. The current generated file already embeds helper-local constants for accepted rows, and the proposed remaining helper code carries equivalent local constants/immediates. A standalone file-scope declaration would add an unproven source artifact.

## Rejected Alternatives

- Keep current blank markers: rejected. Current source-form evidence and accepted SoftwareBlend16 precedents resolve every row.
- Duplicate by-item bodies: rejected. Each by-item row is a legacy alias for a canonical by-memory body and would double-emit code.
- Force inline assembly for every remaining MMX range: rejected. Current generated SoftwareBlend16 already accepts source-level loop reconstructions for several MMX-range block helpers, and the exact behavior is simple channel/byte arithmetic for these rows.
- Emit UID0002OO as a standalone file-scope qword table: rejected. Current evidence proves helper use, not independent source ownership of a global table.
- Treat raw no-start-xref helpers as no-code: rejected for UID000206, UID000207, and UID00020B. The raw helpers have exact bodies, internal calls, return/padding boundaries, and source-authored retained behavior; no-start-xref is a confidence cap only.

## Implementation Tracking Checklist

Callback status: all accepted rows are applied or explicitly excluded. No accepted item remains unapplied.

- [x] Lease only the accepted by-* docs immediately before editing, then release after validators.
  - Proof: B013 leased the 23 accepted by-* docs before patching. The cleanup unlease attempt after validator/generation checks returned `Rejected[No active lease]` for each file because the short leases had already expired; the current lease report shows no active B013 lease remains.
- [x] Update `by-file/SoftwareBlend16.md`: add current empty-marker resolution, MCP evidence summary, executed-report reconciliation, stale-blocker correction, parent score recommendation `86/88 -> 88/90`, and generated-output expectation that all 22 current markers should be eliminated after refresh.
  - Proof: applied in `by-file/SoftwareBlend16.md` metadata and sections `MMX Source-Form Policy` and `2026-06-30 Empty-Emitter Family Resolution`; validator `000000001776`, `2026-06-30T00:10:15-04:00`, exit 0, `ok: 1`.
- [x] Update by-item aliases with covered-by marker text and duplicate-alias proof.
  - Proof: `by-item/AlphaBlendSpan16Blocks_00460B00.md` -> UID0000YF marker, validator `000000001777`, `2026-06-30T00:10:34-04:00`, exit 0, `ok: 1`.
  - Proof: `by-item/AlphaBlendSpan16_00460500.md` -> UID0000YE marker, validator `000000001778`, `2026-06-30T00:10:36-04:00`, exit 0, `ok: 1`.
  - Proof: `by-item/BlendRgb555_004C0710.md` -> UID00016K marker, validator `000000001779`, `2026-06-30T00:10:38-04:00`, exit 0, `ok: 1`.
  - Proof: `by-item/BlendRgb565Pair_004C60D0.md` -> UID00016N marker, validator `000000001780`, `2026-06-30T00:10:40-04:00`, exit 0, `ok: 1`.
  - Proof: `by-item/BlendRgb565Pixel_004C6050.md` -> UID00016M marker, validator `000000001781`, `2026-06-30T00:10:42-04:00`, exit 0, `ok: 1`.
  - Proof: `by-item/HalfBlendSpan16Blocks_00460C10.md` -> UID0000YG marker, validator `000000001782`, `2026-06-30T00:10:44-04:00`, exit 0, `ok: 1`.
- [x] Update by-memory formal C++ rows with accepted scores and evidence notes.
  - Proof: `by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md` added formal `HalfBlendSpan16` C++, score `88/90`; validator `000000001783`, `2026-06-30T00:10:45-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md` added formal `Rgb565TransparentAlphaBlendSpan` C++, score `88/90`; validator `000000001784`, `2026-06-30T00:10:47-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md` added formal helper C++, score `88/91`; validator `000000001785`, `2026-06-30T00:10:49-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md` added formal helper C++, score `88/91`; validator `000000001786`, `2026-06-30T00:10:51-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md` added formal helper C++, score `88/91`; validator `000000001787`, `2026-06-30T00:10:53-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md` added formal `ByteSpanFillRows` C++, score `88/90`; validator `000000001788`, `2026-06-30T00:10:54-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md` added formal `ByteSpanCopyRows` C++, score `88/91`; validator `000000001789`, `2026-06-30T00:10:56-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md` added formal `ByteSpanAddRows` C++, score `88/91`; validator `000000001790`, `2026-06-30T00:10:58-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md` added formal `ByteSpanSubtractRows` C++, score `88/91`; validator `000000001791`, `2026-06-30T00:11:00-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md` added formal `ByteSpanFill8Blocks` C++, score `88/91`; validator `000000001792`, `2026-06-30T00:11:02-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md` added formal `ByteSpanCopy8Blocks` C++, score `88/91`; validator `000000001793`, `2026-06-30T00:11:03-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md` added formal `ByteSpanAdd8Blocks` C++, score `88/91`; validator `000000001794`, `2026-06-30T00:11:05-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md` added formal `ByteSpanSubtract8Blocks` C++, score `88/91`; validator `000000001795`, `2026-06-30T00:11:07-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md` added formal scalar helper C++; score remains `90/92`; validator `000000001796`, `2026-06-30T00:11:09-04:00`, exit 0, `ok: 1`.
  - Proof: `by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md` added formal scalar pair helper C++, score `90/92`; validator `000000001797`, `2026-06-30T00:11:11-04:00`, exit 0, `ok: 1`.
- [x] Update `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`: add covered-by marker text, current xref proof, and score `86/90 -> 88/91`.
  - Proof: formal no-standalone-source comment added; validator `000000001798`, `2026-06-30T00:11:13-04:00`, exit 0, `ok: 1`.
- [x] Do not edit `by-memory/-ignored.md`; no concrete wording mismatch was found.
  - Proof: excluded-with-reason; report accepted no edit required, and no wording mismatch was found during implementation.
- [x] Do not edit manual `-coverage-report.md` files, generated C++ files, generated reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files.
  - Proof: no manual edits were made to those forbidden files. Validators updated validator-owned generated/projected outputs as normal side effects.
- [x] Run scoped validators from `source-3/project-documentation` for every changed by-* doc.
  - Proof: all 23 scoped commands listed above returned exit code 0 and `ok: 1`. Each validator reported `generated_refresh: deferred`.
- [x] After validators, inspect generated `auto-generated/NexusTK/render/SoftwareBlend16.cpp` freshness header and confirm current 22 UID0000NT empty markers are gone or report any remaining marker by UID/path.
  - Proof: polled validator queue until generated header reached `validator-command-id: 000000001798`, `validator-refreshed-at: 2026-06-30T00:11:13-04:00`, `validator-refresh-source: deferred-generated-refresh`. `Select-String 'Empty Emitter Marker'` returned count `0`. No remaining empty marker UID/path.
- [x] Release leases immediately after the edit/validator batch and report leases used/released, validator command ids/timestamps/exit codes/ok counts, changed files, generated refresh state, and unapplied/excluded items.
  - Proof: active release was no longer possible because all 23 B013 leases had already expired; the unlease command reported `Rejected[No active lease]` for each leased path and the current lease report contains no B013 rows. No accepted item remains unapplied.

## Claim And Incorporation Ledger

| Claim / accepted row | Evidence route | Implementation target | Verification state |
|---|---|---|---|
| Current generated SoftwareBlend16 state has 22 empty markers | `SoftwareBlend16.cpp` header `000000001629`, marker scan, tracker row | `by-file/SoftwareBlend16.md` | callback `applied`: by-file records prior marker list and generated refresh now has zero empty markers |
| MCP is available/current | `idb_list` and `server_health` for `supervisor_resume_20260629` | Report evidence section | callback `already-present`: evidence remains in report and by-file implementation section |
| By-item UID0000TW is duplicate alias of UID0000YF | Same address `0x00460b00`, current generated canonical body exists | `by-item/AlphaBlendSpan16Blocks_00460B00.md` | callback `applied`: covered-by marker inserted; validator `000000001777` ok |
| By-item UID0000TV is duplicate alias of UID0000YE | Same address `0x00460500`, current generated canonical body exists | `by-item/AlphaBlendSpan16_00460500.md` | callback `applied`: covered-by marker inserted; validator `000000001778` ok |
| By-item UID0000TZ is duplicate alias of UID00016K | Same address `0x004c0710`, current generated canonical body exists | `by-item/BlendRgb555_004C0710.md` | callback `applied`: covered-by marker inserted; validator `000000001779` ok |
| By-item UID0000U0 is duplicate alias of UID00016N | Same address `0x004c60d0`; UID00016N formal body provided | `by-item/BlendRgb565Pair_004C60D0.md` | callback `applied`: covered-by marker inserted; validator `000000001780` ok |
| By-item UID0000U1 is duplicate alias of UID00016M | Same address `0x004c6050`; UID00016M formal body provided | `by-item/BlendRgb565Pixel_004C6050.md` | callback `applied`: covered-by marker inserted; validator `000000001781` ok |
| By-item UID0000US is duplicate alias of UID0000YG | Same address `0x00460c10`; UID0000YG formal body provided | `by-item/HalfBlendSpan16Blocks_00460C10.md` | callback `applied`: covered-by marker inserted; validator `000000001782` ok |
| UID000206 is reconstructable raw half-blend span wrapper | MCP raw disasm, call `0x0046073e`, masks `0x7bef/0x0821`, padding | `by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md` | callback `applied`: formal C++ and score `88/90`; validator `000000001783` ok |
| UID000207 is reconstructable raw transparent RGB565 alpha span wrapper | MCP raw disasm/decompile, call `0x00460818`, zero-source skip, RGB565 masks | `by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md` | callback `applied`: formal C++ and score `88/90`; validator `000000001784` ok |
| UID000209 is reconstructable transparent RGB565 block helper | MCP decompile, xref from raw UID000207, no callees, helper masks/weights | `by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md` | callback `applied`: formal C++ and score `88/91`; validator `000000001785` ok |
| UID0000YG is reconstructable RGB565 half-blend block helper | MCP decompile, xrefs from UID0000YE and UID000206, masks | `by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md` | callback `applied`: formal C++ and score `88/91`; validator `000000001786` ok |
| UID00020A is reconstructable RGB565 alpha-map block helper | MCP decompile, xref from `sub_460410`, no callees | `by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md` | callback `applied`: formal C++ and score `88/91`; validator `000000001787` ok |
| UID00020B is reconstructable raw byte-fill row wrapper | MCP raw disasm, call `0x00460d8e`, tail fill, padding | `by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md` | callback `applied`: formal C++ and score `88/90`; validator `000000001788` ok |
| UID00020C is reconstructable byte-copy row wrapper | MCP decompile, call `0x00460e1f`, tail copy | `by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md` | callback `applied`: formal C++ and score `88/91`; validator `000000001789` ok |
| UID00020D is reconstructable byte-add row wrapper | MCP decompile, call `0x00460eaf`, wrapping add tail | `by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md` | callback `applied`: formal C++ and score `88/91`; validator `000000001790` ok |
| UID00020E is reconstructable byte-subtract row wrapper | MCP decompile, call `0x00460f3f`, wrapping subtract tail | `by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md` | callback `applied`: formal C++ and score `88/91`; validator `000000001791` ok |
| UID00020F is reconstructable byte-fill block helper | MCP decompile/disasm, qword fill, xref from UID00020B | `by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md` | callback `applied`: formal C++ and score `88/91`; validator `000000001792` ok |
| UID00020G is reconstructable byte-copy block helper | MCP decompile/disasm, qword copy, xref from UID00020C | `by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md` | callback `applied`: formal C++ and score `88/91`; validator `000000001793` ok |
| UID00020H is reconstructable byte-add block helper | MCP decompile/disasm, `paddb`, xref from UID00020D | `by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md` | callback `applied`: formal C++ and score `88/91`; validator `000000001794` ok |
| UID00020I is reconstructable byte-subtract block helper | MCP decompile/disasm, `psubb`, xref from UID00020E | `by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md` | callback `applied`: formal C++ and score `88/91`; validator `000000001795` ok |
| UID00016M is reconstructable scalar RGB565 pixel blend | MCP decompile, 17 xrefs, masks `0xf81f/0x07e0` | `by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md` | callback `applied`: formal C++; score remains `90/92`; validator `000000001796` ok |
| UID00016N is reconstructable packed RGB565 pair blend | MCP decompile, 4 xrefs, packed two-lane behavior | `by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md` | callback `applied`: formal C++ and score `90/92`; validator `000000001797` ok |
| UID0002OO should be covered by helper-local constants/immediates, not standalone data | MCP xrefs all from SoftwareBlend16 helpers; UID00028W precedent | `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md` | callback `applied`: covered-by marker and score `88/91`; validator `000000001798` ok |
| Parent by-file source-quality blocker can be closed for current marker family | Current marker list plus all row dispositions above | `by-file/SoftwareBlend16.md` | callback `applied`: score `88/90` and family evidence section added |
| Validators and generated freshness must be run after edits | Project workflow and assignment | All changed by-* docs; generated `SoftwareBlend16.cpp` inspection | callback `applied`: 23 validators ok; generated header `000000001798`; empty marker count `0` |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0000NT-SoftwareBlend16-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0000NT-SoftwareBlend16-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T00:23:15","uid":"0000NT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
