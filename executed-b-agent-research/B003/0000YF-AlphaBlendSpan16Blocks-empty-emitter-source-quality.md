** TARGET-REPORT-UID:0000YF **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000YF AlphaBlendSpan16Blocks Empty-Emitter Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000YF] `AlphaBlendSpan16Blocks` as reconstructable, SoftwareBlend16-owned, and routed through [UID:0000NT] `SoftwareBlend16`, and replace its blank formal `RECONSTRUCTION_CPP CODE` with the implementation-ready MSVC x86 inline-assembly block in this report.
- Final disposition: no split, no owner/emitter change, no non-emitting reclassification, no rare no-code exception.
- Required action: update the target/support docs to record the current MCP facts, historicalize the stale "saved IDA label" claim, insert the formal C++ block, document the local constants/scratch source policy, and refresh the stale manual by-memory coverage row from `84%` to the recommended `88/91` state.
- Confidence: high for behavior/range/ownership; medium-high for exact original spelling because current IDA still exposes `sub_460B00`, but sufficient for first-draft source because constants/scratch can be target-local and the sibling helper style supports MSVC-era MMX inline assembly.

## Supervisor Rejection Update - 2026-06-29

I re-checked the rejected blockers under the score-blocker/no-code burden:

- SoftwareBlend16-wide source form: siblings at `0x004609e0`, `0x00460b00`, `0x00460c10`, and `0x00460c90` are no-callee, small MMX block helpers with similar caller-driven span arguments. That supports a shared MSVC-era inline-assembly source style; it does not prove target-local emission is impossible.
- Constants/scratch declarations: `SoftwareBlend16ReadOnlyConstants.md` records source-level static masks, and `MmxBlendWeightScratchData.md` explicitly allows clean source to compute equivalent local `__m64`/qword temporaries when behavior is preserved. UID0000YF can therefore use local qword masks and local qword blend weights without external support declarations.
- Sibling helper style: sibling pages are still marker-only, but UID0000YF has no callees and its required constants/scratch can be local. The sibling gap is an ecosystem consistency task, not a target-local score blocker.
- Marker-only generated output: the marker is caused by the target's blank C++ block. A formal insertion for this UID directly improves the generated output and is therefore required.

Conclusion: UID0000YF is implementation-ready as a first-draft source insertion. No rare no-improvement exception applies.

## Target

- Target UID: `0000YF`
- Target path: `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`
- Assignment: `B003-report-0000YF-AlphaBlendSpan16Blocks-empty-emitter-20260629`
- Queue/report row: `auto-generated/-ag-research-tracker.md` -> `Files With Empty Emitters`; [UID:0000NT] `SoftwareBlend16` shows `28` routed items, `0` filled, `28` empty, `0.0%`, output `auto-generated/NexusTK/render/SoftwareBlend16.cpp`.
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, blank formal C++.
- Current parent state: [UID:0000NT] `SoftwareBlend16` is `86/88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.

## Current Target State

- Existing owner/emitter state is correct: [UID:0000YF] is a source-authored free/static render helper under [UID:0000NT].
- Existing behavior summary is mostly correct: it is the weighted RGB565 four-pixel MMX block path called by [UID:0000YE] `AlphaBlendSpan16` at `0x004605fd`.
- Current generated output is marker-only, not source code. `auto-generated/NexusTK/render/SoftwareBlend16.cpp` was refreshed by validator command `000000000948` at `2026-06-29T17:06:04-04:00`, has length `3820`, and contains `Empty Emitter Marker` comments including [UID:0000YF], but no helper body or declarations.
- Current generated memory coverage routes [UID:0000YF] through [UID:0000NT] to `SoftwareBlend16.cpp` and marks code as `no`.
- Manual `by-memory/-coverage-report.md` is stale for this row: it still records [UID:0000YF] as `84% : strong`, while the target page and generated marker report `86/91`.
- Current MCP contradicts the target/by-item claim that the active IDA function label is saved as `AlphaBlendSpan16Blocks`: `lookup_funcs AlphaBlendSpan16Blocks` returns not found, and `lookup_funcs 0x00460b00` returns `sub_460B00`, size `0x10a`.

## Evidence Checked

- Required MCP session: `dad3692b`, active and healthy. `idb_list` reported one active adopted worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` reported `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- IDA MCP tools used: `server_health`, `idb_list`, `lookup_funcs`, `analyze_function`, `xrefs_to`, `callees`, `get_bytes`, `get_int`, `insn_query`, `entity_query`, `make_signature_for_range`, and `int_convert`.
- Docs read: target [UID:0000YF], [UID:0000NT] `SoftwareBlend16`, [UID:0000YE] `AlphaBlendSpan16`, [UID:0000YG] `HalfBlendSpan16Blocks`, [UID:0002OO] `SoftwareBlend16ReadOnlyConstants`, [UID:00028W] `MmxBlendWeightScratchData`, by-item [UID:0000TW] and [UID:0000US], `by-memory/-ignored.md`, `by-memory/-coverage-report.md`, generated memory/file coverage, generated research tracker, and generated `SoftwareBlend16.cpp`.
- Existing reports searched with: `TARGET-REPORT-UID:0000YF`, `0000YF`, `0x00460b00`, `AlphaBlendSpan16Blocks`, `SoftwareBlend16`, `AlphaBlendSpan16`, `HalfBlendSpan16Blocks`, `MmxBlendWeightScratchData`, and `SoftwareBlend16ReadOnlyConstants`.
- Relevant reports opened as leads: executed B001 reports for [UID:000206], [UID:0000YG], and [UID:000209]/[UID:00020A]/[UID:00020C]/[UID:00020D]/[UID:00020E].
- Negative checks: current MCP name search found no function/name entries matching `AlphaBlend`, `HalfBlend`, `ByteSpan`, `Rgb565`, or `SoftwareBlend16` in the scoped neighborhood; target has no callees; target has only one inbound code xref; no formal generated source body exists for [UID:0000YF].

## IDA MCP Facts

- `lookup_funcs`:
  - `0x00460af9`: not a function.
  - `0x00460b00`: `sub_460B00`, size `0x10a`.
  - `0x00460c09`: inside `sub_460B00`.
  - `0x00460c0a`: not a function.
  - `0x00460c10`: `sub_460C10`, size `0x7c`.
  - `AlphaBlendSpan16Blocks`: not found.
- `analyze_function 0x00460b00`: prototype-like Hex-Rays shape is seven-argument cdecl over two row pointers/pitches, one 8-bit weight, block count, and row count; size `266` / `0x10a` (Verified with MCP `int_convert`); no strings; no callees; caller `sub_460500`; basic blocks `7`; cyclomatic complexity `3`.
- `xrefs_to 0x00460b00`: exactly one code xref, `0x004605fd`, inside `sub_460500`.
- `callees 0x00460b00`: empty.
- Caller push window at `0x004605e9-0x004605fd`:
  - pushes row count, block count, computed source-side weight `32 - alpha`, destination pitch, destination pointer, source pitch, and source pointer, then calls `sub_460B00`.
- Target body:
  - `0x00460b03-0x00460b1c` replicates the source weight into `0x0067a820`.
  - `0x00460b0e-0x00460b38` computes and replicates inverse weight `32 - sourceWeight32` into `0x0067a828`.
  - `0x00460b41` uses `pushaw`; `0x00460c01` uses `popaw`; `0x00460c03` uses `emms`.
  - `0x00460b43` and `0x00460b4a` load the writable scratch qwords into `mm2` and `mm3`.
  - `0x00460b51` and `0x00460b58` load read-only RGB565 masks from `0x00610ea8` and `0x00610eb0`.
  - `arg_14` is shifted left by three to convert four-pixel block count into qword byte span.
  - The loop reads one source qword and one destination qword, applies red/blue and green channel masks, multiplies by source/inverse weights, shifts by five, recombines packed channels, writes a destination qword, advances both row pointers by eight bytes, and steps rows by the supplied pitches.
- Constants and scratch:
  - `xrefs_to 0x00610ea8`: one data xref at `0x00460b51`.
  - `xrefs_to 0x00610eb0`: one data xref at `0x00460b58`.
  - `xrefs_to 0x0067a820`: data xrefs at `0x00460b16` and `0x00460b43`.
  - `xrefs_to 0x0067a828`: data xrefs at `0x00460b32` and `0x00460b4a`.
  - `get_int` values: `0x00610ea8` = `0x1f001f001f001f`; `0x00610eb0` = `0x7e007e007e007e0` (Verified with MCP `int_convert`).
  - `get_bytes` shows current scratch qwords at `0x0067a820` and `0x0067a828` are zero in this IDB snapshot; this does not change the runtime role because the function writes both before reading them.
- Padding:
  - `get_bytes 0x00460af9 size 7`: seven `0xcc` bytes.
  - `get_bytes 0x00460c0a size 6`: six `0xcc` bytes.
- `make_signature_for_range 0x00460b00-0x00460c0a`: unique `true`.

## Positive Evidence Summary

- The target is an exact modeled function, not a raw span or mixed range.
- It is source-authored render math: no imports, no CRT/runtime pattern, no class/object state, and no non-render side effects.
- Its only caller is the weighted path in [UID:0000YE] `AlphaBlendSpan16`; that caller computes source-side `32 - alpha` before the call.
- Its data dependencies are exactly the SoftwareBlend16 scratch and read-only mask docs [UID:00028W] and [UID:0002OO].
- Its adjacent bytes are covered by the existing SoftwareBlend16/render helper alignment padding entry in `by-memory/-ignored.md`.
- [UID:0000NT] already inventories [UID:0000YF], the sibling [UID:0000YG], [UID:000209], [UID:00020A], byte helpers, mask constants, and scratch data as a single low-level 16-bit blend-helper family.

## Negative Evidence Summary

- No current IDA name or string proves `AlphaBlendSpan16Blocks` as an original symbol. Current MCP reports `sub_460B00` and no name match for `AlphaBlendSpan16Blocks`.
- No source file breadcrumb proves exact original file name, helper declaration visibility, or whether the original source used MSVC inline assembly, external assembly, macros, or intrinsics.
- A portable scalar C++ body would be behavior-descriptive but is weaker than the MSVC-era MMX source form for this optimized block path.
- Current generated `SoftwareBlend16.cpp` contains marker comments only, so the target needs a formal block insertion before the generator can produce a real body for UID0000YF.

## Heuristic / Inference Reanalysis And Validation

### Role And Source-Facing Name

Best role: weighted RGB565 four-pixel MMX block helper for the non-50-percent branch of `AlphaBlendSpan16`.

Best source-facing name remains `AlphaBlendSpan16Blocks` as a descriptive/inferred documentation name. It pairs naturally with `HalfBlendSpan16Blocks`, and the caller is `AlphaBlendSpan16`; however, current MCP proves the IDA function is not currently named this in the active IDB. Any doc wording saying the saved active IDA label is currently present should be historicalized or corrected.

### Source-Facing Signature

Best source-facing signature in prose:

- return: void-style side-effect helper, not a meaningful return contract;
- calling convention: cdecl/static helper;
- arguments in order: source pixel row pointer, source pitch in bytes, destination pixel row pointer, destination pitch in bytes, source weight on a 0..32 scale, four-pixel block count, row count.

This is validated by the [UID:0000YE] push window, the target's destination stores, the row-pitch additions, and `arg_14 << 3`.

### Source Form

Best-supported source-form direction: target-local MSVC x86 inline assembly using local qword masks and local qword weight vectors. This is stronger than isolated intrinsics because the binary uses `pushaw`/`popaw`, explicit `emms`, qword memory operands for scratch weights, and a family of similarly shaped MMX block helpers. The support-doc evidence is enough to avoid external declarations: the binary's writable scratch locations are behaviorally equivalent to local qword temporaries because UID0000YF writes both weights before reading them, and the read-only masks can be expressed as local qword constants in the formal block.

Rejected source forms:

- Portable scalar C++: rejected because it would be behavior-equivalent but not the best source representation of the optimized MMX binary.
- Hex-Rays `_m_*` intrinsic body: rejected because it preserves decompiler artifacts and is less plausible for the observed MSVC-era assembly shape.
- External assembly-only helper: rejected for this pass because the generator expects formal C++ insertion text, and target-local MSVC inline assembly preserves behavior without requiring a separate build artifact.

### Range / Split / Padding / Reclassification

Keep exact range `0x00460b00-0x00460c0a`.

- Do not split: the function has one prologue, one MMX loop body, one epilogue, and no internal padding/data island.
- Do not merge with [UID:000209]: `0x00460af9-0x00460b00` is seven bytes of `0xcc` padding after [UID:000209].
- Do not merge with [UID:0000YG]: `0x00460c0a-0x00460c10` is six bytes of `0xcc` padding before [UID:0000YG].
- Do not reclassify as no-owner or non-emitting. It is source-authored and already has a valid owner/emitter route.

## Ranked Ownership Analysis

### 1. [UID:0000NT] SoftwareBlend16

- Evidence for: contiguous SoftwareBlend16 helper cluster; direct caller [UID:0000YE]; source-authored RGB565 MMX math; direct references to [UID:0002OO] masks and [UID:00028W] scratch; no object or UI state; parent clears file-owner/emitter gate.
- Evidence against: final original filename remains inferred and `SoftwareBlend16.cpp` is a reconstruction grouping, not proven source filename.
- Decision: accept as current best owner and emitter.

### 2. [UID:00016L] SoftwareRenderRgb565Callbacks / Surface dispatch

- Evidence for: [UID:0000YE] is reached by RGB565 render callback code.
- Evidence against: [UID:0000YF] has no dispatch, Surface, DirectDraw, pane, or asset-library state; it is a primitive helper consumed by callback code.
- Decision: reject as direct owner; keep as consumer/caller context.

### 3. No owner / no emitter

- Evidence for: no original source file or symbol proof survives.
- Evidence against: current docs and MCP prove a precise modeled function, valid parent route, source-authored behavior, and direct dependencies already owned by SoftwareBlend16.
- Decision: reject. Lack of original symbol proof is not enough to remove owner/emitter.

## Source Placement

Recommended placement remains `NexusTK/render/SoftwareBlend16.cpp` under [UID:0000NT].

Implementation-ready source-form plan:

1. Insert UID0000YF as a static/cdecl MSVC x86 inline-assembly helper in `NexusTK/render/SoftwareBlend16.cpp`.
2. Use local qword masks for the two RGB565 constants and local qword weight vectors for the binary scratch qwords; record in [UID:0002OO] and [UID:00028W] that UID0000YF's first-draft source folds those support artifacts locally.
3. Keep [UID:0000YG], [UID:000209], [UID:00020A], and [UID:00020F]-[UID:00020I] on the same source-form trajectory when their empty emitters are implemented.
4. Preserve [UID:0000YF]'s descriptive source name while documenting that current MCP still reports `sub_460B00`.

## First-Draft C++ Recommendation

Eligible for isolated first-draft formal C++ now: yes.

The target's formal `RECONSTRUCTION_CPP` multiline block should contain exactly this insertion text:

```cpp
static void __cdecl AlphaBlendSpan16Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount)
{
    unsigned int sourceWeightWord = sourceWeight32;
    sourceWeightWord |= sourceWeightWord << 16;

    unsigned int inverseWeightWord = (unsigned char)(32 - sourceWeight32);
    inverseWeightWord |= inverseWeightWord << 16;

    unsigned __int64 sourceWeightVector =
        ((unsigned __int64)sourceWeightWord << 32) | sourceWeightWord;
    unsigned __int64 inverseWeightVector =
        ((unsigned __int64)inverseWeightWord << 32) | inverseWeightWord;
    unsigned __int64 rgb565RedBlueMask = 0x001f001f001f001fui64;
    unsigned __int64 rgb565GreenMask = 0x07e007e007e007e0ui64;
    const unsigned char* sourceRow = (const unsigned char*)sourcePixels;
    unsigned char* destinationRow = (unsigned char*)destinationPixels;
    int blockBytes = blockCount4Pixels << 3;

    __asm {
        pushad
        movq mm2, qword ptr [sourceWeightVector]
        movq mm3, qword ptr [inverseWeightVector]
        movq mm4, qword ptr [rgb565RedBlueMask]
        movq mm5, qword ptr [rgb565GreenMask]
        mov eax, sourceRow
        mov ebx, destinationRow
        mov ecx, rowCount

    rowLoop:
        test ecx, ecx
        jz blendDone
        mov esi, eax
        mov edi, ebx
        mov edx, blockBytes
        add edx, edi

    blockLoop:
        cmp edx, edi
        jbe nextRow
        movq mm0, qword ptr [esi]
        movq mm1, qword ptr [edi]
        movq mm7, mm0
        psrlw mm7, 11
        pmullw mm7, mm2
        psrlw mm7, 5
        psllw mm7, 11
        movq mm6, mm0
        pand mm6, mm5
        psrlw mm6, 5
        pmullw mm6, mm2
        pand mm6, mm5
        por mm7, mm6
        pand mm0, mm4
        pmullw mm0, mm2
        psrlw mm0, 5
        por mm0, mm7
        movq mm7, mm1
        psrlw mm7, 11
        pmullw mm7, mm3
        psrlw mm7, 5
        psllw mm7, 11
        movq mm6, mm1
        pand mm6, mm5
        psrlw mm6, 5
        pmullw mm6, mm3
        pand mm6, mm5
        por mm7, mm6
        pand mm1, mm4
        pmullw mm1, mm3
        psrlw mm1, 5
        por mm1, mm7
        paddw mm1, mm0
        movq qword ptr [edi], mm1
        add esi, 8
        add edi, 8
        jmp blockLoop

    nextRow:
        add eax, sourcePitchBytes
        add ebx, destinationPitchBytes
        dec ecx
        jmp rowLoop

    blendDone:
        popad
        emms
    }
}
```

Notes for implementation:

- The formal block intentionally uses local qword variables for [UID:0002OO] mask values and [UID:00028W] weight scratch. This is source-safe because the target writes both scratch qwords before reading them and there are no external xrefs that require preserving the global scratch side effect in clean C++.
- The inline assembly uses `pushad`/`popad` as a conservative MSVC x86 register-preservation spelling. The binary shows operand-size-prefixed `pushaw`/`popaw`; the behavior-visible outputs are unchanged because this helper communicates through the destination buffer and MMX state is cleared with `emms`.
- The function is `void` because the binary return register is not a meaningful caller contract; the caller consumes only destination memory side effects.

## Score And Metadata Recommendation

- Current metadata: `86/91`, owner [UID:0000NT], reconstructable `TRUE`, emitter [UID:0000NT], blank C++.
- Recommended metadata after implementation: `88/91`, owner [UID:0000NT], reconstructable `TRUE`, emitter [UID:0000NT], formal C++ populated with the block above.
- Reason not higher: exact original source spelling/declaration visibility and current IDA active label remain unresolved, and sibling helper emitters still need the same source-form treatment.
- Reason not lower: current MCP directly validates exact range, caller, no callees, constants, scratch, loop shape, padding, and owner/emitter route.
- Manual coverage correction: after the target C++ insertion, `by-memory/-coverage-report.md` row should be updated from `84%` to `88%` by the supervisor or under explicit coverage-report permission.

## Recommended Target Doc Changes

Target path: `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`

- Update `COMPLETION` from `86` to `88`; keep `CONFIDENCE:91`, owner, reconstructable, emitter, range, and source placement unchanged.
- Add a current 2026-06-29 MCP evidence note: session `dad3692b`, `lookup_funcs 0x00460b00 -> sub_460B00 size 0x10a`, `AlphaBlendSpan16Blocks` name not found, one caller at `0x004605fd`, no callees, data xrefs to `0x0067a820/0x0067a828/0x00610ea8/0x00610eb0`, unique range signature, and adjacent padding.
- Historicalize/correct the earlier "saved label `AlphaBlendSpan16Blocks`" wording: it may be a prior saved-IDB observation, but it is not true in the current MCP session.
- Replace the blank formal C++ block with the exact insertion text in this report.
- Add the prose source-facing signature/argument order and void-style return decision.

## Recommended Support Doc Changes

`by-item/AlphaBlendSpan16Blocks_00460B00.md`:

- Keep metadata unchanged.
- Add the current MCP contradiction for the active IDA label and historicalize the previous saved-label statement.
- Add the same source-form decision at shorter detail: UID0000YF should use a target-local MSVC x86 inline-assembly block with local qword masks and local qword weight vectors.

`by-file/SoftwareBlend16.md`:

- Increase completion only if the supervisor wants parent score to reflect the filled UID0000YF emitter; otherwise keep metadata unchanged until more empty helpers are populated.
- Add [UID:0000YF] to the MMX source-form policy note explicitly: current MCP still exposes `sub_460B00`, but the helper is ready for MSVC x86 inline-assembly C++ insertion using local qword masks/scratch.
- Update generated-output wording after refresh: `SoftwareBlend16.cpp` should no longer be marker-only for [UID:0000YF], though sibling helper markers remain.
- Add the implementation-ready source-form plan from this report, or reference it at report-level detail after acceptance.

`by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md`:

- No metadata change required.
- Optional body sync only: confirm its weighted path calls [UID:0000YF] with source-side `32 - alpha` and that [UID:0000YF] now has an implementation-ready formal C++ callback.

`by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md`:

- No metadata change required.
- No target-specific edit required unless the supervisor wants both weighted and half-blend sibling pages to share the same current generated-output wording.

`by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`:

- No metadata change required.
- Implementation-callback sync: note that [UID:0000YF] uses `0x00610ea8` and `0x00610eb0` in the binary, but its first-draft formal C++ folds those masks into local qword constants to avoid support-declaration coupling.

`by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md`:

- No metadata change required.
- Implementation-callback sync: note that [UID:0000YF] writes/loads `0x0067a820` and `0x0067a828` in the binary, but its first-draft formal C++ uses local qword weight vectors because the writes are immediately consumed and have no external code xref dependency.

`by-memory/-coverage-report.md`:

- B-agent report-only mode must not edit this manual report. Supervisor-owned replacement row should update [UID:0000YF] from `84%` to `88%` and record the formal C++ recommendation.

Suggested replacement row:

```text
    - [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md) 0x00460b00-0x00460c0a | function | AlphaBlendSpan16Blocks : reconstructable : 88% : very strong : Agent-B003 2026-06-29 reanalysis confirms exact 0x10a-byte SoftwareBlend16 weighted RGB565 four-pixel MMX block helper, current MCP function `sub_460B00`, sole caller at 0x004605fd from AlphaBlendSpan16 with source-side 32-alpha weight, no callees, source/destination pointer and pitch order, sourceWeight32/blockCount4Pixels/rowCount semantics, scratch refs at 0x0067a820/0x0067a828, RGB565 mask refs at 0x00610ea8/0x00610eb0, unique range signature, adjacent padding, valid SoftwareBlend16 owner/emitter, and implementation-ready MSVC x86 inline-assembly formal C++ using local qword masks and local qword weight vectors.
```

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | [UID:0000YF] remains SoftwareBlend16-owned and emitted by [UID:0000NT]. | high | Target metadata, [UID:0000NT], generated memory coverage, MCP caller/data refs | Target status, SoftwareBlend16 ownership/source-form section | already-present | applied |
| C2 | Current MCP session `dad3692b` exposes `sub_460B00`, not `AlphaBlendSpan16Blocks`, for `0x00460b00`. | high | `lookup_funcs` and `entity_query` | Target evidence, by-item evidence | historicalize | applied |
| C3 | Exact range is `0x00460b00-0x00460c0a`; adjacent padding is `0x00460af9-0x00460b00` and `0x00460c0a-0x00460c10`. | high | `lookup_funcs`, `get_bytes`, ignored ledger | Target range/evidence | incorporate | applied |
| C4 | The sole caller is [UID:0000YE] at `0x004605fd`, passing source pointer/pitch, destination pointer/pitch, source-side `32-alpha`, block count, and row count. | high | `xrefs_to`, `insn_query` caller window | Target evidence and signature/source-dependency prose | incorporate | applied |
| C5 | The target writes and loads scratch qwords `0x0067a820/0x0067a828` and reads masks `0x00610ea8/0x00610eb0`. | high | `xrefs_to`, `get_int`, `get_bytes`, target disassembly | Target evidence; support docs [UID:0002OO]/[UID:00028W] | incorporate | applied |
| C6 | Formal C++ should be populated with the MSVC x86 inline-assembly insertion in this report. | high | MCP body shape, caller window, constants/scratch xrefs, support-doc local-temporary policy, sibling MMX helper style | Target C++ block, SoftwareBlend16 source-form policy | incorporate | applied |
| C7 | Manual `by-memory/-coverage-report.md` row is stale at `84%` and should be supervisor-updated to `88%` after implementation. | high | Target header `86/91`, generated marker `86/91`, manual row grep, new formal C++ recommendation | Manual coverage row | not-applicable | excluded-with-reason: current implementation callback forbids editing any `-coverage-report.md`; supervisor-owned row remains intentionally untouched. |
| C8 | UID0000YF can fold [UID:0002OO] masks and [UID:00028W] scratch into local qword variables without external declarations. | high | Support docs, target writes scratch before reads, no target callees, no external code xrefs to scratch side effect | Target source notes; [UID:0002OO]; [UID:00028W] | incorporate | applied |

## Open Questions With Attempted Resolution

- Original helper spelling: unresolved. Checked current MCP function/name search; no matching active symbol/name survives. Impact: keep descriptive `AlphaBlendSpan16Blocks`, do not treat as original-proof, and keep confidence at 91 rather than raising it.
- Exact source form: resolved for UID0000YF as MSVC x86 inline assembly in formal C++.
- Scratch/global policy: resolved for UID0000YF as local qword weight vectors; support docs should record this as a first-draft source policy because the binary writes both scratch values before loading them.
- Generated output state: resolved as an implementation task. `SoftwareBlend16.cpp` is not zero bytes now, but it contains an empty-emitter marker for UID0000YF until the formal block above is inserted and generated output is refreshed.

## Validator Results

- Implementation validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md --apply --queue-timeout 240` -> command_id `000000000959`, command_timestamp `2026-06-29T17:27:26-04:00`, exit code `0`, `ok: 1`; updated [UID:0000YF] completion to `88` and registry state from `blank` to `block`; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-item\AlphaBlendSpan16Blocks_00460B00.md --apply --queue-timeout 240` -> command_id `000000000960`, command_timestamp `2026-06-29T17:27:33-04:00`, exit code `0`, `ok: 1`; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-file\SoftwareBlend16.md --apply --queue-timeout 240` -> command_id `000000000961`, command_timestamp `2026-06-29T17:27:47-04:00`, exit code `0`, `ok: 1`; generated refresh deferred; validator reported four pre-existing `missing_ref_uid 0003ZP` diagnostics.
  - `python .\tools\validator.py --mode file --file by-memory\0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md --apply --queue-timeout 240` -> command_id `000000000962`, command_timestamp `2026-06-29T17:27:54-04:00`, exit code `0`, `ok: 1`; added [UID:0000YF] to the reference index; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory\0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md --apply --queue-timeout 240` -> command_id `000000000963`, command_timestamp `2026-06-29T17:28:03-04:00`, exit code `0`, `ok: 1`; generated refresh deferred.
- Follow-up parent wording validators:
  - `python .\tools\validator.py --mode file --file by-file\SoftwareBlend16.md --apply --queue-timeout 240` -> command_id `000000000965`, command_timestamp `2026-06-29T17:31:27-04:00`, exit code `0`, `ok: 1`; validator inserted UID links for UID0000YF/UID0000YG in the historical B002 note and repeated the known `missing_ref_uid 0003ZP` diagnostics.
  - `python .\tools\validator.py --mode file --file by-file\SoftwareBlend16.md --apply --queue-timeout 240` -> command_id `000000000967`, command_timestamp `2026-06-29T17:32:16-04:00`, exit code `0`, `ok: 1`; final parent wording validation, known `missing_ref_uid 0003ZP` diagnostics remain.
- Verification correction:
  - `python .\tools\validator.py --mode file --file by-memory\0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md --apply --queue-timeout 240` -> command_id `000000000969`, command_timestamp `2026-06-29T17:36:23-04:00`, exit code `0`, `ok: 1`; corrected the target change-log heading from `B002 implementation callback` to `B003 implementation callback`.
- Verification correction follow-up:
  - `python .\tools\validator.py --mode file --file by-memory\0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md --apply --queue-timeout 240` -> command_id `000000000978`, command_timestamp `2026-06-29T17:40:11-04:00`, exit code `0`, `ok: 1`; restored the first 2026-06-29 change-log heading to `B002 implementation callback` because its bullets document the earlier UID0000YE/B002 synchronization, while the second 2026-06-29 heading remains `B003 implementation callback` for this UID0000YF implementation.
- Generated freshness: after the verification correction follow-up, `auto-generated/NexusTK/render/SoftwareBlend16.cpp` refreshed at least to `validator-command-id: 000000000978` / `2026-06-29T17:40:11-04:00`, equal to the final target validator command and newer than the UID0000YF initial implementation validator `000000000959`. The generated file contains [UID:0000YF] at `Completion:88 Confidence:91` with the `AlphaBlendSpan16Blocks` body and `pushad`; UID0000YF no longer has an empty-emitter marker. Sibling and by-item empty markers remain outside this callback.
- Queue check after validation: latest command_id `000000000976`, command_timestamp `2026-06-29T17:39:00-04:00`, worker running, no queued/processing jobs and no queued/processing generated refresh jobs.
- Leases: B003 leased the five approved by-* docs at `2026-06-29T21:23:31Z`, expiration `2026-06-29T21:28:31Z`; required edit/validator batch completed before expiration and B003 released all five leases successfully. B003 then used two fresh narrow leases for `by-file/SoftwareBlend16.md` wording cleanup, validated with commands `000000000965` and `000000000967`, and released each lease. Final lease report showed no active leases.

## Changed Files

- Updated: `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`
- Updated: `by-item/AlphaBlendSpan16Blocks_00460B00.md`
- Updated: `by-file/SoftwareBlend16.md`
- Updated: `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`
- Updated: `by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md`
- Updated: `tools/leaser/Agents/Agent-B003/research/0000YF-AlphaBlendSpan16Blocks-empty-emitter-source-quality.md`
- Validator side effects: scoped validators refreshed validator/project-generated state and `auto-generated/NexusTK/render/SoftwareBlend16.cpp`; these were tool-generated, not manually edited.
- Report execution: not run. The supervisor runs `tools/validator.py execute_report ... --apply` only after review and accepted implementation.

## Implementation Tracking Checklist

Initial report-only pass and callback proof:

- [x] Supervisor validation required before implementation. Proof: supervisor callback accepted this corrected report for implementation in assignment `B003-implement-0000YF-AlphaBlendSpan16Blocks-empty-emitter-20260629`.
- [x] Update target doc `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md` with current `dad3692b` MCP facts, active-name correction, source-facing signature prose, `COMPLETION:88`, and the exact formal C++ insertion text from this report. Proof: target metadata is now `88/91`; formal C++ block is populated; `Source Declaration Dependency And Source Form`, `Evidence Notes`, `Score Rationale`, and `2026-06-29 - B003 implementation callback` sections record the accepted details.
- [x] Update support doc `by-item/AlphaBlendSpan16Blocks_00460B00.md` with current active-name correction and shorter source-form/C++ insertion recommendation. Proof: added `Source Form Decision`, current `dad3692b` evidence, and B003 change-log entry.
- [x] Update support doc `by-file/SoftwareBlend16.md` with [UID:0000YF]-specific source-form policy, generated-output wording after refresh, and implementation-ready SoftwareBlend16 MMX helper plan. Proof: MMX Source-Form Policy now records UID0000YF as populated with MSVC x86 inline assembly and local qword masks/scratch; Proposed Contents and Changes sections updated.
- [x] Confirm `by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md` needs no metadata change; optionally sync weighted-path/formal-C++ wording if supervisor accepts support edit. Proof: intentionally excluded by current callback, which explicitly said not to edit [UID:0000YE] unless a validator/by-structure issue required it. No such issue occurred.
- [x] Confirm `by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md` needs no metadata change; optionally sync generated-output wording only if supervisor wants sibling consistency. Proof: intentionally excluded by current callback, which explicitly said not to edit [UID:0000YG] unless a validator/by-structure issue required it. No such issue occurred.
- [x] Confirm `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md` needs no metadata change; add source policy note for [UID:0000YF]'s local qword `0x00610ea8/0x00610eb0` mask equivalents. Proof: Rebuild Notes and Changes sections updated; metadata remains `86/90`.
- [x] Confirm `by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md` needs no metadata change; add source policy note for [UID:0000YF]'s local qword equivalents of `0x0067a820/0x0067a828`. Proof: Reconstruction Notes and Changes sections updated; metadata remains `85/88`.
- [x] Supervisor-owned manual coverage update: replace the stale [UID:0000YF] row in `by-memory/-coverage-report.md` from `84%` to `88%` using the replacement row in this report, unless a current callback explicitly authorizes B-agent coverage-report editing. Proof: intentionally excluded; current callback says do not edit any `-coverage-report.md` file, so no manual coverage report was touched.
- [x] Target metadata after implementation: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, formal C++ populated. Proof: target header and validator command `000000000959` confirm completion update and `blank -> block`.
- [x] Preserve rejected alternatives: no no-owner/non-emitting reclassification, no split/merge, no target-only portable C++/Hex-Rays intrinsic body, no claim that `AlphaBlendSpan16Blocks` is current active IDA symbol proof. Proof: target, by-item, and SoftwareBlend16 pages document these dispositions and historicalize the saved-label claim.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: ledger rows C1-C8 now show `applied` or `excluded-with-reason`.
- [x] Validators to run after accepted implementation: scoped file validator for target by-memory doc, by-item doc, `by-file/SoftwareBlend16.md`, [UID:0002OO], and [UID:00028W]; if supervisor updates manual coverage, validate `by-memory/-coverage-report.md`; run or request generated refresh/autogen check so `auto-generated/NexusTK/render/SoftwareBlend16.cpp` contains UID0000YF code instead of its empty-emitter marker. Proof: required validators `000000000959` through `000000000963` ran with exit code `0` and `ok: 1`; parent cleanup validators `000000000965` and `000000000967` also ran with exit code `0` and `ok: 1`; verification heading correction validators `000000000969` and `000000000978` ran with exit code `0` and `ok: 1`; manual coverage validation not run because manual coverage edit was forbidden.
- [x] Generated report refresh expected: validator/autogen should keep [UID:0000YF] routed through [UID:0000NT] with code `yes` and no UID0000YF empty-emitter marker after accepted implementation. Proof: generated `auto-generated/NexusTK/render/SoftwareBlend16.cpp` refreshed to final B003 correction command `000000000978`; file contains UID0000YF body at `Completion:88 Confidence:91` and no UID0000YF empty-emitter marker.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` names accepted implementation callback.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: five listed by-* docs updated; optional [UID:0000YE]/[UID:0000YG] and manual coverage row excluded with callback reasons.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: rows C1-C8 updated.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: UID0000YF score `86 -> 88`, owner/emitter unchanged, no split/rename, formal C++ populated; parent/support metadata unchanged with reasons.
- [x] Historical/stale saved-label assumption preserved as historical or corrected against current MCP. Proof: target and by-item now state current MCP session `dad3692b` exposes `sub_460B00`, while the 2026-06-16 saved-label claim is historical.
- [x] Source-form and scratch/constant local-equivalent policy documented with evidence. Proof: target source-form section, SoftwareBlend16 MMX policy, [UID:0002OO] Rebuild Notes, and [UID:00028W] Reconstruction Notes all document local qword masks/scratch for UID0000YF.
- [x] Validators run and results recorded with command, command id, timestamp, exit code, and ok count. Proof: Validator Results section records required commands `000000000959`-`000000000963`, parent cleanup commands `000000000965`/`000000000967`, verification correction commands `000000000969`/`000000000978`, and queue/freshness checks through `000000000976`.
- [x] Generated refresh completed or freshness checked against validator command metadata. Proof: generated `SoftwareBlend16.cpp` refreshed to final B003 correction command `000000000978`, `validator-refreshed-at: 2026-06-29T17:40:11-04:00`; no queued generated jobs were present in the B003 queue check after correction.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted by-* implementation item remains unapplied; only intentionally excluded items are manual coverage and optional [UID:0000YE]/[UID:0000YG] edits blocked by explicit callback scope.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0000YF-AlphaBlendSpan16Blocks-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0000YF-AlphaBlendSpan16Blocks-empty-emitter-source-quality.md","timestamp":"2026-06-29T17:43:11","uid":"0000YF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
