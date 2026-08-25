** TARGET-REPORT-UID:0000YG **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-softwareblend16-halfblend-block-source-quality-0000YG-20260616

## Scope

Primary target:

- [UID:0000YG] `by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md`

Context inspected:

- [UID:0000NT] `by-file/SoftwareBlend16.md`
- [UID:0000YE] `by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md`
- [UID:000206] `by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md`
- [UID:000207] `by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md`
- [UID:0000YF] `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`
- [UID:00020B] `by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md`
- [UID:0002OO] `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`
- [UID:0000YD] `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`
- [UID:0000US] `by-item/HalfBlendSpan16Blocks_00460C10.md`
- `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-item-coverage.md`, and current generated source state for `auto-generated/NexusTK/render/SoftwareBlend16.cpp`.

This is report-only B-agent work. I did not edit by-* docs, generated reports, generated source files, `by-memory/-coverage-report.md`, or the IDA database.

## Current State

[UID:0000YG] is currently `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000NT`, with blank final C++.

The by-memory page already records the main facts: exact modeled function range, callers at `0x00460544` and raw `0x0046073e`, no callees, MMX half-blend loop, mask constants, adjacent padding, and SoftwareBlend16 ownership. The main stale/low-score issues are:

- by-memory [UID:0000YG] is still `82/88`, while by-item [UID:0000US] for the same function is already `85/90` with stronger evidence.
- The target page still says parent [UID:0000NT] is `82/86`; current [UID:0000NT] is `86/88`.
- The target page still uses older final-C++ gate wording about `95% confidence`; current guidance uses the confirmed emitter route plus `(COMPLETION + CONFIDENCE) / 2 > 85` as the minimum numerical gate, while still requiring source-quality readiness.
- IDA still names the function `sub_460C10`, so the source-facing name remains descriptive/inferred even though the role is well supported.

Recommendation: raise [UID:0000YG] from `82/88` to `85/90`, keep [UID:0000NT] owner/emitter and blank final C++, and update the target page evidence/score rationale to match current live IDA and by-item evidence.

## Evidence Collected

Live IDA MCP session:

- Session: `b002_ranking_0001ZC_20260616`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Imagebase: `0x00400000`
- `server_health`: `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

Function object and boundary evidence:

| Query | Result |
| --- | --- |
| `lookup_funcs 0x00460c0a` | not a function |
| `lookup_funcs 0x00460c10` | `sub_460C10`, size `0x7c` |
| `lookup_funcs 0x00460c8b` | inside `sub_460C10`, size `0x7c` |
| `lookup_funcs 0x00460c8c` | not a function |
| `lookup_funcs 0x00460c90` | next function `sub_460C90`, size `0xc1` |
| `lookup_funcs 0x00460544` | inside caller `sub_460500`, size `0x209` |
| `lookup_funcs 0x0046073e` | no function object, raw caller site |
| `lookup_funcs 0x00460230` | RGB555 analogue `sub_460230`, size `0x72` |
| `lookup_funcs 0x00460b00` | `AlphaBlendSpan16Blocks`, size `0x10a` |

Disassembly and decompiler evidence:

- `disasm 0x00460c10` returned 49 instructions, total 49, from `push ebp` at `0x00460c10` through `retn` at `0x00460c8b`.
- `analyze_function 0x00460c10` returned prototype `__m64 *__cdecl(__m64 *, int, __m64 *, int, int, int)`, size 124, no strings, no callees, callers `sub_460500`, and direct xrefs from `0x00460544` and `0x0046073e`.
- `callees 0x00460c10` returned an empty list.
- `decompile 0x00460c10` reconstructs a six-argument cdecl helper whose first pointer is the source row, second argument is source pitch, third pointer is destination row, fourth argument is destination pitch, fifth argument is block count, and sixth argument is row count. Hex-Rays represents the first and third pointers as `__m64 *` because the body operates on qwords.

Caller evidence:

- `decompile 0x00460500` shows the alpha==16 branch of [UID:0000YE] calling `sub_460C10(a1, a2, a3, a4, a6 / 4, a7)` at `0x00460544`. [UID:0000YE] itself has the live render callback caller at `0x004c2ad4`, so [UID:0000YG] is statically reachable through a modeled function.
- Scoped `insn_query 0x00460530-0x00460550` shows the modeled caller push window:
  - `0x0046053a push ecx` (row count)
  - `0x0046053b push ebx` (block count = width / 4)
  - `0x0046053c push [ebp+arg_C]` (destination pitch)
  - `0x0046053f push esi` (destination pointer)
  - `0x00460540 push [ebp+arg_4]` (source pitch)
  - `0x00460543 push edx` (source pointer)
  - `0x00460544 call sub_460C10`
- Scoped `insn_query 0x00460720-0x00460750` shows the raw [UID:000206] caller push window:
  - `0x00460736 push ebx` (row count)
  - `0x00460737 push eax` (block count = width / 4)
  - `0x00460738 push ecx` (destination pitch)
  - `0x00460739 push esi` (destination pointer)
  - `0x0046073a push dword ptr [ebp+0Ch]` (source pitch)
  - `0x0046073d push edi` (source pointer)
  - `0x0046073e call sub_460C10`

Xref and raw PE evidence:

- `xrefs_to 0x00460c10`: exactly two code refs, `0x00460544` from `sub_460500` and `0x0046073e` from a raw/unmodeled span.
- `xref_query 0x00460c10 direction=both`: the same two inbound code refs plus an internal line-flow xref from `0x00460c10` to `0x00460c11`; no data xrefs or pointer-table references are reported.
- Raw PE scan of `.text` found rel32 operand starts resolving to `0x00460c10` at `0x00460545` and `0x0046073f`, corresponding to call instructions at `0x00460544` and `0x0046073e`.
- Raw PE scan found no little-endian VA dword or RVA dword hits to `0x00460c10` in `.text`. This argues against a static function-pointer table for this helper; direct calls are the reachability evidence.

Bytes, constants, and signatures:

- `get_bytes 0x00460c0a size 6`: `cc cc cc cc cc cc`.
- `get_bytes 0x00460c8c size 4`: `cc cc cc cc`.
- `get_bytes 0x00610eb8 size 8`: `de f7 de f7 de f7 de f7`, value `0xf7def7def7def7de`.
- `get_bytes 0x00610ec0 size 8`: `21 08 21 08 21 08 21 08`, value `0x0821082108210821`.
- `xrefs_to 0x00610eb8`: one data ref at `0x00460c21` from `sub_460C10`.
- `xrefs_to 0x00610ec0`: one data ref at `0x00460c28` from `sub_460C10`.
- `find_bytes` for the exact [UID:0000YG] prologue/prefix hit only `0x00460c10`.
- `make_signature_for_function 0x00460c10` returned a short unique wildcarded signature beginning `55 8B EC 8B 45 ? 53 56 C1 E0 03 57 89 45 ? 66 60 0F 6F 15 ? ? ? ? 0F 6F 1D`.
- `make_signature_for_range 0x00460c10-0x00460c8c` returned `unique:true`.

RGB555 comparison:

- `lookup_funcs 0x00460230` returns `sub_460230`, size `0x72`.
- `xrefs_to 0x00460230` returns two code refs, `0x0045fbc4` from modeled `sub_45FB80` and raw `0x0045fd9e`.
- `xrefs_to 0x00610e68` and `0x00610e70` each return one data ref from `sub_460230`, matching the RGB555 half-blend constants in [UID:0002OO].
- `find_bytes` for the RGB555 exact prefix hit only `0x00460230`.

Generated-output evidence:

- `auto-generated/-ag-memory-coverage.md` and `auto-generated/-ag-item-coverage.md` route [UID:0000YG] through [UID:0000NT] to `auto-generated/NexusTK/render/SoftwareBlend16.cpp`.
- `auto-generated/NexusTK/render/SoftwareBlend16.cpp` exists but is zero bytes. The blank final C++ block on [UID:0000YG] is not polluting generated source.
- A stale temporary coverage-like file exists under `auto-generated/tmp3us4zach` and mentions [UID:0000YG]. I did not edit generated outputs; this is cleanup/regeneration noise, not C++ pollution from [UID:0000YG].

## Heuristic / Inference Reanalysis And Validation

### Best Role, Name, And Signature

Best defensible role:

- [UID:0000YG] is a source-authored, file-local or free helper in the SoftwareBlend16 family. It performs four-pixel-at-a-time, 50 percent RGB565 span blending using MMX qword operations.

Best source-facing name:

- Preferred documentation/source-facing name: `HalfBlendSpan16Blocks`.
- Optional IDA name if the supervisor applies a rename: `HalfBlendSpan16Blocks_Inferred`.
- A plain `HalfBlendSpan16Blocks` IDA name is defensible because the by-memory/by-item docs and sibling `AlphaBlendSpan16Blocks` naming are consistent, but `_Inferred` better records that no original symbol/source breadcrumb was found.

Best signature:

```cpp
void HalfBlendSpan16Blocks(
    const uint16_t* src,
    int srcPitchBytes,
    uint16_t* dst,
    int dstPitchBytes,
    int blockCount4Pixels,
    int rowCount);
```

Argument-order validation:

- The modeled caller [UID:0000YE] computes `blockCount4Pixels = widthPixels / 4` and calls `sub_460C10(a1, a2, a3, a4, a6 / 4, a7)` at `0x00460544`.
- The raw caller [UID:000206] computes the same `width / 4` split and pushes source pointer, source pitch, destination pointer, destination pitch, block count, and row count before `0x0046073e`.
- Inside [UID:0000YG], `arg_10` is shifted left by 3 (`shl eax, 3`) and used as the byte end offset for qword iteration. Since each block covers 4 RGB565 pixels = 8 bytes, `blockCount4Pixels` is the correct semantic name.
- `arg_14` is loaded into `ecx` and controls the outer row loop.
- `arg_0` and `arg_8` are the two row pointers; `arg_4` and `arg_C` are added after each row. The body reads qwords from both pointers and stores the result to the `arg_8` side, so `arg_0` is source and `arg_8` is destination.

### Source-Authored Versus Compiler/Runtime Helper

Treat [UID:0000YG] as `source-authored`.

Rejected compiler/runtime interpretation:

- The body is not CRT, STL, import thunk, EH, RTTI, security-cookie, or compiler glue. It has no library signature/name and no imported/runtime API behavior.
- It uses SoftwareBlend16-specific RGB565 constants from [UID:0002OO], is called by [UID:0000YE] and [UID:000206], and performs domain-specific pixel math.
- The MMX sequence implements the RGB565 half-blend identity:
  - mask both source and destination with `0xf7def7def7def7de`,
  - shift each masked word right by 1,
  - add the halves,
  - add the shared low-bit carry term using `0x0821082108210821` and `src & dst`.
- A compiler would not synthesize this helper from unrelated runtime support; it is authored render code, even if inline assembly or intrinsics caused the final machine shape.

### Range, Split/Merge, And Padding

Keep [UID:0000YG] as exactly one modeled function page:

- Do not split it. The function starts at `0x00460c10`, returns at `0x00460c8b`, and has no internal padding or separate nested helper.
- Do not merge it with [UID:0000YF]. [UID:0000YF] returns at `0x00460c09`, then `0x00460c0a-0x00460c10` is six bytes of `0xcc` alignment padding.
- Do not merge it with [UID:00020A]. [UID:0000YG] returns at `0x00460c8b`, then `0x00460c8c-0x00460c90` is four bytes of `0xcc` padding before `sub_460C90`.
- Do not convert it to a raw/non-emitting page. IDA has a proper function object at `0x00460c10`, and both IDA and raw PE scan confirm direct callers.

Exact padding spans and ignored-row recommendations:

- Keep `0x00460c0a-0x00460c10` as ignored padding: six `0xcc` bytes.
- Keep `0x00460c8c-0x00460c90` as ignored padding: four `0xcc` bytes.
- No new ignored rows are needed.
- The existing `by-memory/-ignored.md` SoftwareBlend16/render helper alignment entry is sufficient and should not be changed for this target.

### Caller/Reachability And No-Xref Treatment

[UID:0000YG] is reachable. This target does not have a no-xref problem.

Validated facts:

- IDA reports two inbound code xrefs to `0x00460c10`.
- Raw PE rel32 scan independently confirms the same two direct call sites.
- The modeled caller `0x00460544` is inside [UID:0000YE], which is itself reached from a render callback at `0x004c2ad4`.
- The raw caller `0x0046073e` is inside [UID:000206], which currently has no direct static inbound caller, but this does not weaken [UID:0000YG]'s liveness because the modeled [UID:0000YE] caller is enough.
- No VA/RVA dword hit to `0x00460c10` was found in `.text`, so static function-pointer reachability is not the explanation here. Direct calls are the explanation.

Best interpretation:

- The two xrefs are true direct call evidence, not an IDA artifact.
- The absence of a function object at raw caller `0x00460710` is an IDA modeling issue for [UID:000206], not for [UID:0000YG].
- There is no evidence that [UID:0000YG] is dead code. At least one modeled live path calls it.

### Source Placement

Keep [UID:0000YG] owned and emitted by [UID:0000NT] `SoftwareBlend16`.

Reasons:

- [UID:0000NT] is current `86/88`, has `CANONICAL_OWNER:FILE`, and has valid `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
- The helper is stateless 16-bit/RGB565 software-render math.
- It is physically grouped with [UID:0000YE], [UID:000206], [UID:0000YF], [UID:00020A], [UID:00020B], and byte/MMX span helpers that already route to [UID:0000NT].
- [UID:0002OO] owns the SoftwareBlend16 read-only qword masks used by this helper.
- Routing to broader render dispatch or surface/pane ownership is weaker: [UID:0000YG] has no UI state, DirectDraw state, asset ownership, or callback dispatch responsibility. It is an implementation helper called by render blend span code.

### Constants, Siblings, And RGB555/RGB565 Pattern

[UID:0002OO]:

- No metadata change recommended. It already documents `0x00610eb8` and `0x00610ec0` as SoftwareBlend16 constants routed through [UID:0000NT].
- [UID:0000YG] should explicitly reference these constants in its strengthened evidence if updated.

[UID:0000YE]:

- No metadata change recommended. It already documents the alpha==16 branch and direct call to [UID:0000YG] at `0x00460544`.
- It is important support evidence for [UID:0000YG]'s reachability and signature.

[UID:000206]:

- No new change recommended in this assignment. It is now `85/89` after the prior Agent-B001 report and supervisor update.
- Its raw call at `0x0046073e` confirms [UID:0000YG] is shared by both the modeled alpha==16 path and the retained raw half-blend span helper.

[UID:000207]:

- No new change recommended. It is already `85/89`.
- It is context for the raw-helper pattern but does not call [UID:0000YG].

[UID:0000YF]:

- No metadata change recommended. It is the weighted RGB565 block helper sibling and already has a stronger direct sibling name (`AlphaBlendSpan16Blocks`) in IDA.
- Its existence supports the name `HalfBlendSpan16Blocks` by pairing the weighted and 50 percent block helpers in the same source family.

[UID:00020B]:

- No new change recommended. It is already `85/89`.
- It supports the broader SoftwareBlend16 raw-helper retention pattern but not [UID:0000YG]'s signature directly.

RGB555/RGB565 pattern:

- `sub_460230` is the RGB555 half-blend block analogue. It has two callers, uses its own qword masks from [UID:0002OO], and has a unique exact prefix hit.
- The RGB555 analogue strengthens the source-authored block-helper interpretation. It does not justify moving [UID:0000YG] into the broader [UID:0000YD] page because [UID:0000YG] has an exact own page and SoftwareBlend16 ownership.

### Generated Output And Final C++ Impact

Numerical eligibility:

- If raised to `85/90`, [UID:0000YG] clears the current minimum final-C++ numerical gate because `(85 + 90) / 2 = 87.5`, and `EMITTER_UIDS:0000NT` routes to a valid generated source root.

Final C++ recommendation:

- Keep [UID:0000YG] final C++ blank.
- A non-final sketch may remain documentation-only in the page body, but it should not enter `RECONSTRUCTION_CPP CODE` yet.

Why blank final C++ remains correct:

- IDA still names the function `sub_460C10`; `entity_query` found no IDA function names containing `HalfBlend`, and only found neighboring named functions `AlphaBlendSpan16Blocks` and `ByteSpanCopy8Blocks`.
- There is no original source symbol or source file declaration proving the exact helper spelling, linkage, or declaration placement.
- The final source strategy for SoftwareBlend16's MMX helpers is not yet settled: source could have used inline assembly, MSVC MMX intrinsics, or a scalar helper that compiled differently under targeted options. The current machine code includes `pushaw`, `popaw`, and `emms`, which need a deliberate final-source treatment.
- `auto-generated/NexusTK/render/SoftwareBlend16.cpp` is currently zero bytes. Inserting only this helper would create isolated generated output without the surrounding `SoftwareBlend16` helper declarations, constants, and block-family style needed for final project source.

Generated-output pollution:

- [UID:0000YG] is not polluting final generated C++ because its final block is blank.
- Existing autogen coverage rows route it correctly to [UID:0000NT].
- The stale temporary file `auto-generated/tmp3us4zach` is not caused by [UID:0000YG]'s final C++ and should be handled by validator/autogen cleanup policy if the supervisor wants generated-folder cleanup.

### Rejected Alternatives

- Keep `82/88`: rejected. The by-memory page lags behind the already stronger by-item [UID:0000US] evidence, and fresh live IDA/PE checks validate the exact range, callers, constants, unique signature, padding, ownership, and final-C++ blocker status.
- Raise beyond `85` completion: rejected. The function behavior is strong, but original source name, linkage/declaration placement, and final MMX source form are not yet resolved.
- Treat `HalfBlendSpan16Blocks` as confirmed original name: rejected. It is a strong descriptive name, but IDA has no symbol/source-name proof.
- Mark non-emitting/no-route: rejected. The helper is source-authored code with an already valid SoftwareBlend16 emitter route.
- Move to broader render-dispatch ownership: rejected. The helper is stateless blend math, not a dispatcher/callback owner.
- Split or merge: rejected by exact function object, returns, and adjacent `0xcc` padding.
- Add final C++ now: rejected. The score/emitter minimum can be met after the raise, but the source-quality gate for final output is not met.

## Recommendation

Raise [UID:0000YG] from `82/88` to `85/90`.

Keep:

- `CANONICAL_OWNER:0000NT`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000NT`
- blank `RECONSTRUCTION_CPP CODE`
- exact range `0x00460c10-0x00460c8c`
- name `HalfBlendSpan16Blocks` as descriptive/inferred unless original proof is later found

Score rationale:

- Completion `85`: exact function boundary, callers, callee absence, argument order, row/block semantics, constants, byte signature, adjacent padding, ownership, and generated-output impact are now documented well enough to pass the 85 gate. Remaining completion blockers are final original name, exact source declaration/linkage, and final MMX source form.
- Confidence `90`: live IDA, raw bytes, xrefs, raw PE rel32 scan, constants, sibling pages, RGB555 analogue, and by-item [UID:0000US] all agree on behavior and ownership. Confidence remains below final-audit scores because the original source name and source form are still inferred.

## Exact Target Page Edits

Header replacement:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the stale parent/source status wording in `## Status` with:

```text
- Likely source file: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md) `SoftwareBlend16`; parent [UID:0000NT] is currently `86/88`, has `CANONICAL_OWNER:FILE`, and has valid `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
- Confidence: strong for exact modeled range, direct callers at `0x00460544` and raw `0x0046073e`, no callee body, argument order, MMX loop semantics, mask constants, padding, and SoftwareBlend16 ownership; medium for original source spelling/linkage and final MMX source form.
- C++ reconstruction: final C++ remains intentionally blank. The page can clear the numerical/emitter eligibility gate after this score update, but final output should wait for a SoftwareBlend16-wide source-form pass covering helper names, declarations, constants, and MMX/inline-assembly style.
```

Add to `## Evidence`:

```text
- 2026-06-16 Agent-B001 live IDA MCP session `b002_ranking_0001ZC_20260616` reconfirmed `sub_460C10` at `0x00460c10`, size `0x7c`, with `0x00460c8b` inside the function, `0x00460c8c` not a function, and next function `sub_460C90` at `0x00460c90`.
- 2026-06-16 `xrefs_to 0x00460c10` returned exactly two code refs: modeled caller `0x00460544` inside `sub_460500` and raw caller `0x0046073e` inside [UID:000206]. Raw PE rel32 scan independently found the same call sites and found no `.text` VA/RVA dword pointer hits to `0x00460c10`.
- 2026-06-16 scoped instruction queries confirmed both callers pass cdecl arguments as source pointer, source pitch, destination pointer, destination pitch, four-pixel block count, and row count. Inside `sub_460C10`, `arg_10` is shifted left by 3, confirming 8 bytes per block / 4 RGB565 pixels.
- 2026-06-16 `get_bytes` confirmed `0x00460c0a-0x00460c10` is six `0xcc` bytes and `0x00460c8c-0x00460c90` is four `0xcc` bytes. `make_signature_for_range 0x00460c10-0x00460c8c` returned `unique:true`.
- 2026-06-16 constant checks confirmed [UID:0002OO] qwords `0x00610eb8 = 0xf7def7def7def7de` and `0x00610ec0 = 0x0821082108210821`, each with a single data xref from [UID:0000YG] at `0x00460c21` and `0x00460c28`.
- 2026-06-16 IDA entity-name search found no function named `HalfBlend*`; the source-facing name `HalfBlendSpan16Blocks` remains descriptive/inferred despite strong role evidence.
```

Replace or add `## Score Rationale` with:

```text
- Completion `85`: exact modeled boundary, adjacent padding, direct callers, no callees, argument order, block-count semantics, row stepping, destination qword store, SoftwareBlend16 constants, unique signature, source placement, and generated-output impact have been checked. Remaining gaps are original source spelling, helper linkage/declaration placement, and final MMX source form.
- Confidence `90`: live IDA, raw bytes, xrefs, raw PE rel32 scan, constants, sibling block helpers, RGB555 analogue evidence, and by-item [UID:0000US] agree that this is a source-authored SoftwareBlend16 RGB565 half-blend block helper. Confidence stays below final-audit quality because no original symbol/source breadcrumb proves the helper name or exact source representation.
- Reconstructable `TRUE`: unchanged. This is NexusTK source-authored render math, not padding, compiler/runtime glue, third-party code, or a non-emitting audit range.
```

Add to `## Changes`:

```text
- 2026-06-16 Agent-B001 source-quality audit recommendation: raise [UID:0000YG] from `82/88` to `85/90`, keep [UID:0000NT] owner/emitter and blank final C++ unchanged. Evidence: live IDA MCP session `b002_ranking_0001ZC_20260616` reconfirmed exact function object `sub_460C10`, two direct callers at `0x00460544` and raw `0x0046073e`, no callees, MMX half-blend constants, unique range signature, and adjacent padding; raw PE rel32/VA/RVA scan corroborated direct calls and no pointer-table route. Final source name and MMX source form remain inferred, so generated C++ stays blank.
```

## Exact Coverage Row Replacement

Replace the [UID:0000YG] row in `by-memory/-coverage-report.md` with:

```text
    - [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md) 0x00460c10-0x00460c8c | function | HalfBlendSpan16Blocks : reconstructable : 85% : strong : Agent-B001 2026-06-16 reanalysis confirms exact 0x7c-byte modeled SoftwareBlend16 RGB565 50 percent MMX block helper, live IDA function `sub_460C10` at `0x00460c10-0x00460c8c`, two direct code callers at `0x00460544` and raw `0x0046073e`, no callees, unique byte signature, qword masks `0xf7def7def7def7de` and `0x0821082108210821` from [UID:0002OO], source/destination argument order, block-count-by-8-byte qword loop, destination qword store, adjacent `0xcc` padding, and SoftwareBlend16 owner/emitter; name/signature remain descriptive/inferred and final C++ stays blank pending final source style/name audit.
```

No ignored-row replacement is needed. Keep the existing padding rows:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00460c0a-0x00460c10 | padding | AlphaBlendSpan16Blocks/HalfBlendSpan16Blocks alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00460c8c-0x00460c90 | padding | HalfBlendSpan16Blocks/Rgb565AlphaMapMmxBlocks alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
```

## Support Doc Recommendations

`by-file/SoftwareBlend16.md`:

- No metadata change recommended.
- No required body edit. It already lists [UID:0000YG] and current [UID:0000NT] is `86/88` with a valid source route.

`by-item/HalfBlendSpan16Blocks_00460C10.md`:

- No change recommended. It already records [UID:0000YG]'s stronger `85/90` state and detailed live evidence. The by-memory page should be synchronized to this evidence.

`by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`:

- No change recommended. It already covers the RGB565 half-blend qword masks used by [UID:0000YG].

`by-memory/-ignored.md`:

- No change recommended. Existing ignored padding coverage includes both adjacent [UID:0000YG] padding spans.

`auto-generated` reports/source:

- Do not edit manually. After supervisor changes, run validator/autogen so generated reports refresh.
- Keep `auto-generated/NexusTK/render/SoftwareBlend16.cpp` blank unless a separate final-C++ pass writes a coherent SoftwareBlend16 source file.

Associated siblings:

- [UID:000206] is already `85/89`; no new change.
- [UID:000207] is already `85/89`; no new change.
- [UID:00020B] is already `85/89`; no new change.
- [UID:0000YE] and [UID:0000YF] already contain the caller/sibling evidence needed here; no score or metadata change recommended.

## Optional IDA Recommendation

Do not apply this from B-agent work. If the supervisor later chooses to update IDA names/comments:

| Address | Current IDA state | Recommended optional action |
| --- | --- | --- |
| `0x00460c10` | existing function `sub_460C10`, size `0x7c` | Rename to `HalfBlendSpan16Blocks_Inferred`; comment: `Inferred SoftwareBlend16 RGB565 four-pixel 50% MMX block helper. Called by AlphaBlendSpan16 at 0x00460544 and raw HalfBlendSpan16 at 0x0046073e; uses qword masks 0x610eb8/0x610ec0; source name not symbol-proven.` |

No IDA function-start creation is needed for [UID:0000YG] because the function already exists. Raw sibling start recommendations belong to their own pages and were already covered in prior work.

## Validation Commands

After applying the [UID:0000YG] by-memory page update and coverage-row replacement:

> Executable block R001 was removed from this report and preserved verbatim in [0000YG-softwareblend16-halfblend-block-source-quality-removed.md](0000YG-softwareblend16-halfblend-block-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Post-validation checks:

> Executable block R002 was removed from this report and preserved verbatim in [0000YG-softwareblend16-halfblend-block-source-quality-removed.md](0000YG-softwareblend16-halfblend-block-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected outcome:

- [UID:0000YG] no longer appears as `82/88` in Low_Completion/Low_Both; it should report `85/90`.
- [UID:0000YG] remains routed through [UID:0000NT] to `auto-generated/NexusTK/render/SoftwareBlend16.cpp`.
- Adjacent padding rows remain ignored and unchanged.
- `SoftwareBlend16.cpp` remains zero bytes unless a separate final-C++ pass intentionally adds source.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000YG-softwareblend16-halfblend-block-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"0000YG"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000YG-softwareblend16-halfblend-block-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0000YG-softwareblend16-halfblend-block-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000YG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
