** TARGET-REPORT-UID:000206 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-softwareblend16-raw-span-source-quality-000206-20260616

## Scope

Primary target:

- [UID:000206] `by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md`

Associated context inspected:

- [UID:000207] `by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md`
- [UID:0000YG] `by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md`
- [UID:00020B] `by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md`
- [UID:0000NT] `by-file/SoftwareBlend16.md`
- Directly relevant nearby SoftwareBlend16 helpers/constants and the RGB555 analogue at `0x0045fd70` only as source-quality comparison evidence.

This is report-only B-agent work. I did not edit by-* docs, generated reports, `by-memory/-coverage-report.md`, the IDA database, or generated source files.

## Inputs Read

- B001 `goal.md` and `notes.md`.
- `project-documentation/by-structure.md` and B001 `inference_research.md`.
- Current target/context docs for [UID:000206], [UID:000207], [UID:0000YG], [UID:00020B], [UID:0000NT], [UID:0000YE], [UID:0000YD], [UID:000209], and [UID:00020F].
- `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `by-project-structure/proposed-source-tree.md` for current routing/report state.
- Live IDA MCP session `b002_ranking_0001ZC_20260616`, target `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x00400000`; server health reported `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Raw PE byte scan of `NexusTK.exe` for `.text` rel32 `E8`/`E9` targets and whole-file little-endian VA/RVA dword hits to relevant helper starts.

## Current Documentation State

- [UID:000206] is currently `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, with blank final C++.
- [UID:000207] is currently `82/88`, owner/emitter [UID:0000NT], reconstructable, with blank final C++.
- [UID:0000YG] is currently `82/88`, owner/emitter [UID:0000NT], reconstructable, with blank final C++.
- [UID:00020B] is currently `82/88`, owner/emitter [UID:0000NT], reconstructable, with blank final C++.
- [UID:0000NT] is currently `86/88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`; `by-project-structure/proposed-source-tree.md` already lists `render/SoftwareBlend16.cpp`.
- `auto-generated/-ag-memory-coverage.md` routes [UID:000206], [UID:000207], [UID:0000YG], and [UID:00020B] to `auto-generated/NexusTK/render/SoftwareBlend16.cpp`, and marks them `emits`, but the generated file is currently zero bytes because the final C++ blocks are blank.

## Live IDA Evidence

Function object state and boundaries:

| Address/range | IDA state | Evidence impact |
| --- | --- | --- |
| `0x00460500-0x00460709` | modeled function `sub_460500`, size `0x209` | The live RGB565 `AlphaBlendSpan16` dispatcher is modeled and has the one direct external caller at `0x004c2ad4`. |
| `0x00460709-0x00460710` | no function, `align 10h`, bytes `cc cc cc cc cc cc cc` | Confirmed padding before [UID:000206]. |
| `0x00460710-0x004607e0` | no IDA function object; 87 decoded instructions; terminal `retn` at `0x004607df` | [UID:000206] is a real unmodeled prologue/epilogue code body, not padding. |
| `0x004607e0-0x0046093c` | no IDA function object; 118 body instructions plus following `align`; terminal `retn` at `0x0046093b` | [UID:000207] is a sibling unmodeled code body. |
| `0x0046093c-0x00460940` | no function, bytes `cc cc cc cc` | Confirmed padding after [UID:000207]. |
| `0x00460940-0x004609d3` | modeled function `sub_460940`, size `0x93` | Neighbor after [UID:000207]. |
| `0x004609e0-0x00460af9` | modeled function `sub_4609E0`, size `0x119` | Block helper called by [UID:000207] at `0x00460818`. |
| `0x00460b00-0x00460c0a` | modeled function `AlphaBlendSpan16Blocks`, size `0x10a` | Weighted RGB565 block helper. |
| `0x00460c0a-0x00460c10` | no function, bytes `cc` x6 | Confirmed padding before [UID:0000YG]. |
| `0x00460c10-0x00460c8c` | modeled function `sub_460C10`, size `0x7c` | Four-pixel RGB565 half-blend block helper. |
| `0x00460c8c-0x00460c90` | no function, bytes `cc` x4 | Confirmed padding after [UID:0000YG]. |
| `0x00460d51-0x00460d60` | no function, bytes `cc` x15 | Confirmed padding before [UID:00020B]. |
| `0x00460d60-0x00460dee` | no IDA function object; 64 decoded body instructions; terminal `retn` at `0x00460ded` | [UID:00020B] is a real unmodeled code body. |
| `0x00460dee-0x00460df0` | no function, bytes `cc cc` | Confirmed padding after [UID:00020B]. |

IDA xrefs:

- `xrefs_to 0x00460710`: none.
- `xrefs_to 0x004607e0`: none.
- `xrefs_to 0x00460d60`: none.
- `xrefs_to 0x00460c10`: two code refs, `0x00460544` from modeled `sub_460500` and raw `0x0046073e` from [UID:000206].
- `xrefs_to 0x004609e0`: one raw code ref, `0x00460818` from [UID:000207].
- `xrefs_to 0x00460fa0`: one raw code ref, `0x00460d8e` from [UID:00020B].
- `xrefs_to 0x00460500`: one direct code ref, `0x004c2ad4` inside `sub_4C0F80`.
- `callees 0x00460500`: `sub_460C10` and `AlphaBlendSpan16Blocks`.
- `callees 0x00460c10`, `0x004609e0`, `0x00460fa0`: empty.

Important detail: `xref_query direction=both` on raw starts reports only line-flow xrefs from `0x00460710` to `0x00460711`, from `0x004607e0` to `0x004607e1`, and from `0x00460d60` to `0x00460d61`. Those are not inbound reachability evidence.

IDA and byte-signature evidence:

- `make_signature 0x00460710` returned a unique wildcarded signature beginning `55 8B EC 51 8B 45 ? 8B 4D ? 99 83 E2 03 53 ...`.
- `make_signature_for_range 0x00460710-0x004607e0` returned a unique full-range signature.
- `make_signature 0x004607e0`, `0x00460d60`, and `0x00460c10` also returned unique signatures.
- `find_bytes` for the [UID:000206] prologue prefix hit `0x0045fd70` and `0x00460710`; the prologue alone is not unique.
- `find_bytes` for the [UID:000206] RGB565 half-blend mask sequence `81 E6 EF 7B 00 00 81 E1 EF 7B 00 00 23 FA 03 F1 81 E7 21 08 00 00` hit only `0x00460793`.
- `find_bytes` for the [UID:000207] prologue prefix hit only `0x004607e0`.
- `find_bytes` for the [UID:00020B] prologue prefix hit only `0x00460d60`.
- IDA name/string search found no source strings for `SoftwareBlend16`, `HalfBlend`, `AlphaBlendSpan`, `ByteSpan`, or `Rgb565`; IDA names matching these terms in this neighborhood are only `AlphaBlendSpan16Blocks` at `0x00460b00` and `ByteSpanCopy8Blocks` at `0x00461000`. Therefore final original names remain inferred/descriptive.

Raw PE scan:

`.text` is `VA=0x00401000`, `RVA=0x00001000`, `RawPtr=0x400`, `RawSize=0x20b600`.

Direct `E8`/`E9` rel32 hits to target starts in `.text`:

| Site | Op | Target |
| --- | --- | --- |
| `0x00460399` | `e8` | `0x00460940` |
| `0x00460544` | `e8` | `0x00460c10` |
| `0x004605fd` | `e8` | `0x00460b00` |
| `0x0046073e` | `e8` | `0x00460c10` |
| `0x00460818` | `e8` | `0x004609e0` |
| `0x00460d8e` | `e8` | `0x00460fa0` |
| `0x004c2ad4` | `e8` | `0x00460500` |

No direct `E8`/`E9` rel32 hit targets `0x00460710`, `0x004607e0`, or `0x00460d60`.

Whole-file little-endian dword scan for VA and RVA forms of `0x00460500`, `0x00460710`, `0x004607e0`, `0x00460940`, `0x004609e0`, `0x00460b00`, `0x00460c10`, `0x00460d60`, and `0x00460fa0` found no VA/RVA dword hits. This argues against static function-pointer table reachability for the raw starts.

## Heuristic / Inference Reanalysis And Validation

### Primary [UID:000206] Role

Best defensible source role: source-authored 16-bit/RGB565 half-blend row-span helper retained in the SoftwareBlend16 helper family.

Best defensible name:

- Preferred source-facing descriptive name: `HalfBlendSpan16`.
- Existing report filename/name `Rgb565HalfBlendSpanRaw` remains acceptable as a documentation label because it makes pixel format and IDA raw/unmodeled status explicit.
- IDA name recommendation if the supervisor elects to model this function: `HalfBlendSpan16_Inferred` or `Rgb565HalfBlendSpan_Inferred`. The `_Inferred` suffix should stay until original source spelling is proven.

Best defensible signature:

```cpp
void HalfBlendSpan16(
    const uint16_t* src,
    int srcPitchBytes,
    uint16_t* dst,
    int dstPitchBytes,
    int widthPixels,
    int rowCount);
```

Validation:

- Argument order is confirmed by the `0x0046073e -> 0x00460c10` cdecl push window and by the `HalfBlendSpan16Blocks` destination store.
- `[ebp+8]` and `[ebp+0c]` are source pointer/pitch; `[ebp+10]` and `[ebp+14]` are destination pointer/pitch; `[ebp+18]` is width in pixels; `[ebp+1c]` is row count.
- Scalar tail writes to destination and advances source/destination by byte pitches.
- Half-blend math is the RGB565 identity using `0x7bef` and `0x0821`.

### Sibling Roles And Names

`0x004607e0` [UID:000207]:

- Best role: source-authored RGB565 transparent weighted alpha row-span helper.
- Best descriptive name: `Rgb565TransparentAlphaBlendSpan` or `TransparentAlphaBlendSpan16`; keep `_Inferred` if applied in IDA.
- Signature remains:

```cpp
void Rgb565TransparentAlphaBlendSpan(
    const uint16_t* src,
    int srcPitchBytes,
    uint16_t* dst,
    int dstPitchBytes,
    unsigned int alpha32,
    int widthPixels,
    int rowCount);
```

`0x00460c10` [UID:0000YG]:

- Best role: source-authored four-pixel MMX/block helper for 50 percent 16-bit/RGB565 row blending.
- Best descriptive name: `HalfBlendSpan16Blocks`; this is stronger than `Rgb565HalfBlendSpan16Blocks` because IDA already has the sibling name `AlphaBlendSpan16Blocks`, and the current docs consistently use `HalfBlendSpan16Blocks`.
- Signature remains:

```cpp
void HalfBlendSpan16Blocks(
    const uint16_t* src,
    int srcPitchBytes,
    uint16_t* dst,
    int dstPitchBytes,
    int blockCount4Pixels,
    int rowCount);
```

`0x00460d60` [UID:00020B]:

- Best role: source-authored byte-span row fill helper that delegates eight-byte blocks to `ByteSpanFill8Blocks`.
- Best descriptive name: `ByteSpanFillRows`.
- Signature remains:

```cpp
void ByteSpanFillRows(
    unsigned char* dst,
    int dstPitchBytes,
    unsigned char value,
    int widthBytes,
    int rowCount);
```

### Split, Merge, And Padding Decision

[UID:000206] should remain one exact source-bearing raw helper page:

- Do not split it. It has one prologue at `0x00460710`, one terminal `retn` at `0x004607df`, one block-helper call, one scalar tail, and no internal padding island.
- Do not merge it with [UID:0000YE] `AlphaBlendSpan16`. `AlphaBlendSpan16` ends with `retn` at `0x00460708`; `0x00460709-0x00460710` is seven bytes of `0xcc` padding; [UID:000206] starts with a fresh prologue.
- Do not merge it with [UID:000207]. [UID:000206] returns at `0x004607df`; [UID:000207] starts at `0x004607e0` with a fresh prologue and different alpha/transparent semantics.
- Do not convert it to padding/non-emitting. Its code body has normal frame setup, loop structure, an internal call, scalar pixel math, and a return.

Padding spans and ignored-row recommendations:

- Keep existing ignored padding row coverage for:
  - `0x00460709-0x00460710`
  - `0x0046093c-0x00460940`
  - `0x00460c0a-0x00460c10`
  - `0x00460c8c-0x00460c90`
  - `0x00460d51-0x00460d60`
  - `0x00460dee-0x00460df0`
- No new ignored rows are needed for [UID:000206].
- No padding bytes belong inside [UID:000206].

### Reachability And Liveness Decision

The raw-start no-xref condition is now resolved:

- IDA has no function object at `0x00460710`; that is an IDA modeling issue.
- IDA has no inbound xrefs to `0x00460710`; the raw PE rel32 and VA/RVA scans support that this is a true direct static-reference absence, not merely an IDA function-modeling artifact.
- The raw body itself has a direct call to `HalfBlendSpan16Blocks` at `0x0046073e`. That proves the body decodes as intended but does not prove an external caller.
- Preceding code cannot fall through into it because [UID:0000YE] returns at `0x00460708` and the intervening bytes are `0xcc` padding.
- No static function-pointer table to `0x00460710`, `0x004607e0`, or `0x00460d60` was found by VA/RVA dword scan.

Best interpretation: [UID:000206] is retained unreferenced source-authored helper code, likely preserved by object-level linking or a build without function-level dead stripping. It is not proven live in the shipped executable's direct static call graph. It is still source-authored and reconstructable because rebuilding this binary/source family must account for retained helper functions even when the current executable has no direct static caller.

Disconfirming evidence checked:

- Compiler/runtime helper interpretation: rejected because the body is domain-specific RGB565 span math and calls a sibling render helper.
- Padding/data interpretation: rejected by prologue, decoded control flow, call, scalar loop, and terminal `retn`.
- IDA-only xref miss interpretation: rejected for direct references because the raw PE rel32 and VA/RVA scans also found no raw-start hit.
- True unreachable source helper interpretation: accepted for direct static reachability, with the caveat that an indirect computed call without a static pointer cannot be fully disproven from static bytes alone.

### RGB555 Analogue Validation

The prologue prefix shared by [UID:000206] also appears at `0x0045fd70`, directly after `sub_45FB80` returns and before `sub_45FE40`. IDA shows:

- `0x0045fd70` has no function object and no xrefs.
- It calls `sub_460230` at `0x0045fd9e`.
- `xrefs_to 0x00460230` includes modeled `0x0045fbc4` from `sub_45FB80` and raw `0x0045fd9e`.
- Its scalar tail uses RGB555 masks `0x3def` and `0x0421`.

This out-of-scope analogue supports the inference that [UID:000206] is part of a repeated retained raw half-blend helper pattern, not an accidental decoder artifact. It also shows that the broader [UID:0000YD] RGB555/RGB565 helper island may contain another raw no-xref source helper needing future exact-page cleanup, but I do not recommend editing that page under this assignment.

### Source Placement Decision

Keep [UID:000206] under [UID:0000NT] `SoftwareBlend16`.

Reasons:

- The body is stateless RGB565/16-bit software-render math.
- It is physically adjacent to [UID:0000YE] `AlphaBlendSpan16`, [UID:000207], and the modeled block helpers.
- It calls [UID:0000YG] `HalfBlendSpan16Blocks`.
- [UID:0000NT] already documents the span/block helper family and has a valid `NexusTK/render/` proposed path.
- Routing to broader Surface/software-render callback pages is weaker: the callbacks consume live helpers such as `AlphaBlendSpan16`, but [UID:000206] itself has no direct callback xref and has no Surface state.

Do not change `CANONICAL_OWNER` or `EMITTER_UIDS` for [UID:000206], [UID:000207], [UID:0000YG], or [UID:00020B].

### Generated Output And Final C++ Decision

There is no generated-output pollution from [UID:000206] today:

- It is marked `emits` through [UID:0000NT], but its final C++ block is blank.
- `auto-generated/NexusTK/render/SoftwareBlend16.cpp` is zero bytes.
- The non-final C++ sketch in the body does not enter generated output.

If [UID:000206] is raised to `85/89`, it clears the numerical/emitter minimum for final C++ consideration: `(85 + 89) / 2 = 87`, and `EMITTER_UIDS:0000NT` surfaces to a valid by-file source root.

However, blank final C++ remains the correct recommendation for now. The active gate is a minimum, not an instruction to emit code. Final insertion should wait because:

- Original source name is not proven.
- IDA/source names only prove nearby `AlphaBlendSpan16Blocks` and `ByteSpanCopy8Blocks`; no string/name evidence proves `HalfBlendSpan16` or `Rgb565HalfBlendSpan`.
- The final source style for this file is still unsettled: scalar C++ versus inline assembly/intrinsics for the MMX block family, helper visibility, and exact declaration grouping have not been final-audited.
- A nearby RGB555 raw analogue at `0x0045fd70` suggests source-family cleanup is incomplete and should be handled before writing final `SoftwareBlend16.cpp` code.

Therefore: keep `RECONSTRUCTION_CPP CODE` blank for [UID:000206], [UID:000207], [UID:0000YG], and [UID:00020B]. Keep the sketches documentation-only.

## Recommendations

### Primary [UID:000206]

Disposition:

- Keep as reconstructable source-authored SoftwareBlend16 helper.
- Keep `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`.
- Do not split, merge, ignore, or mark non-emitting.
- Raise `COMPLETION` from `82` to `85`.
- Raise `CONFIDENCE` from `88` to `89`.
- Keep final C++ blank.

Reason for score:

- Completion can reach `85` because the remaining source-quality gap is now narrowed to original spelling/final source form; raw start, body, padding, block relationship, direct static non-reachability, pointer absence, and source placement have all been checked.
- Confidence can reach `89` because behavior/source family are strong, but original source name and any indirect runtime reachability remain unproven.

Suggested by-memory page edits:

1. Header:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Add to `## Evidence`:

```text
- 2026-06-16 Agent-B001 live IDA MCP session `b002_ranking_0001ZC_20260616` reconfirmed no IDA function object at `0x00460710`, no inbound `xrefs_to 0x00460710`, exact decoded body `0x00460710-0x004607e0`, terminal `retn` at `0x004607df`, and seven `0xcc` bytes at `0x00460709-0x00460710`.
- 2026-06-16 raw PE scan of `NexusTK.exe` found direct rel32 hits only to `0x00460c10` from `0x00460544` and raw `0x0046073e`; it found no `E8`/`E9` rel32 hit, VA dword hit, or RVA dword hit to `0x00460710`. This resolves the raw-start xref caveat as true absence of direct static reachability, not just an IDA function-modeling issue.
- 2026-06-16 IDA `make_signature_for_range 0x00460710-0x004607e0` returned a unique wildcarded signature. A short prologue prefix also appears at RGB555 analogue `0x0045fd70`, but the RGB565 half-blend mask sequence at `0x00460793` is unique.
- 2026-06-16 IDA string/name search found no surviving source-name breadcrumb for `HalfBlendSpan`, `Rgb565HalfBlendSpan`, or `SoftwareBlend16`; final source-facing names remain descriptive/inferred.
```

3. Replace `## Score Rationale` bullets with:

```text
- Completion `85`: exact raw extent, padding, decoded instruction count, block-helper call, source/destination argument order, row stepping, scalar RGB565 formula, source route, unique body signature, and direct static non-reachability have now been checked. Remaining gaps are original source spelling, final declaration grouping, and final C++ source form.
- Confidence `89`: IDA disassembly, xrefs, raw bytes, PE rel32/VA/RVA scan, sibling block-helper evidence, and the RGB555 raw analogue agree that this is retained source-authored SoftwareBlend16 code. Confidence stays below final-audit quality because no original name/debug/source breadcrumb or live external caller was found.
- Reconstructable `TRUE`: unchanged. This is source-authored render support code retained in the binary, not padding, data, compiler glue, or third-party/runtime code.
```

4. Add to `## Changes`:

```text
- 2026-06-16 Agent-B001 source-quality audit recommendation: raise from `82/88` to `85/89`, keep [UID:0000NT] owner/emitter and blank final C++ unchanged. Evidence: live IDA MCP session `b002_ranking_0001ZC_20260616` reconfirmed the raw body, padding, empty raw-start xrefs, and `0x0046073e -> sub_460C10` block call; raw PE rel32 and VA/RVA scans found no direct static reference to `0x00460710`; unique body signature and the `0x0045fd70` RGB555 analogue support retained source-authored helper treatment.
```

### [UID:000207]

Recommended sibling change:

- Raise from `82/88` to `85/89`.
- Keep [UID:0000NT] owner/emitter, reconstructable state, and blank final C++ unchanged.

Reason: the same direct-reference audit applies. IDA has no function object or raw-start xrefs at `0x004607e0`; raw PE scan found no rel32/VA/RVA hit to `0x004607e0`; body and block-helper call at `0x00460818 -> 0x004609e0` are still source-authored SoftwareBlend16 code.

Suggested header edits:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Suggested evidence addition:

```text
- 2026-06-16 Agent-B001 source-quality audit reconfirmed no IDA function object and no inbound raw-start xrefs at `0x004607e0`; raw PE rel32/VA/RVA scans found no direct static reference to `0x004607e0`, while preserving the expected raw block call `0x00460818 -> 0x004609e0`. `make_signature 0x004607e0` returned a unique signature. Keep this as retained source-authored SoftwareBlend16 helper code with descriptive/inferred name and blank final C++.
```

### [UID:0000YG]

Recommended metadata change: none.

Reason:

- The current page already records the modeled function object, exact range, two code refs (`0x00460544` and raw `0x0046073e`), no callee set, mask constants, and padding.
- This investigation corroborates the caller relationship but does not resolve the remaining final source spelling/intrinsic style gap.
- Optional IDA DB recommendation only: if the supervisor is applying IDA names, rename `sub_460C10` to `HalfBlendSpan16Blocks_Inferred` or `HalfBlendSpan16Blocks` with a repeatable comment that the name is descriptive unless original source proof is later found.

### [UID:00020B]

Recommended sibling change:

- Raise from `82/88` to `85/89`.
- Keep [UID:0000NT] owner/emitter, reconstructable state, and blank final C++ unchanged.

Reason: direct-reference audit matches the primary raw-helper pattern. IDA has no function object or raw-start xrefs at `0x00460d60`; raw PE scan found no rel32/VA/RVA hit to `0x00460d60`; the body has an expected raw block-helper call at `0x00460d8e -> 0x00460fa0`, exact padding, and source-authored byte-span semantics.

Suggested header edits:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Suggested evidence addition:

```text
- 2026-06-16 Agent-B001 source-quality audit reconfirmed no IDA function object and no inbound raw-start xrefs at `0x00460d60`; raw PE rel32/VA/RVA scans found no direct static reference to `0x00460d60`, while preserving the expected raw block call `0x00460d8e -> 0x00460fa0`. `make_signature 0x00460d60` returned a unique signature. Keep this as retained source-authored SoftwareBlend16 byte-span helper code with descriptive/inferred name and blank final C++.
```

### Support Docs

`by-memory/-ignored.md`:

- No edit recommended. The existing SoftwareBlend16/render helper alignment entry already covers all relevant padding spans.

`by-project-structure/proposed-source-tree.md`:

- No edit recommended. `render/SoftwareBlend16.cpp` is already listed.

`by-file/SoftwareBlend16.md`:

- No metadata edit recommended.
- Optional body-only evidence update if the supervisor wants to record the raw no-xref conclusion at file level:

```text
- 2026-06-16 Agent-B001 raw-helper audit: `0x00460710`, `0x004607e0`, and `0x00460d60` remain reconstructable SoftwareBlend16 helpers even though raw PE rel32/VA/RVA scans found no direct static references to their starts. The helpers are retained source-authored span/block support code; final C++ remains blank until source naming and MMX/intrinsic source form are final-audited.
```

## Coverage Row Recommendations

Replace the [UID:000206] row in `by-memory/-coverage-report.md` with:

```text
    - [UID:000206][0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw](by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md) 0x00460710-0x004607e0 | raw function | Rgb565HalfBlendSpanRaw : reconstructable : 85% : strong : Agent-B001 2026-06-16 reanalysis confirms exact 0xd0-byte retained SoftwareBlend16 RGB565 half-blend span helper, no IDA function object, no inbound raw-start xrefs, no raw PE rel32/VA/RVA direct reference to 0x00460710, unique body signature, HalfBlendSpan16Blocks call at 0x0046073e, source/destination argument order, width/4 block split, scalar RGB565 half-blend masks 0x7bef and 0x0821, destination store, source/destination row-pitch stepping, and boundary padding; final source name remains descriptive/inferred and final C++ stays blank.
```

Replace the [UID:000207] row only if the supervisor accepts the sibling score bump:

```text
    - [UID:000207][0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw](by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md) 0x004607e0-0x0046093c | raw function | Rgb565TransparentAlphaBlendSpanRaw : reconstructable : 85% : strong : Agent-B001 2026-06-16 reanalysis confirms exact retained SoftwareBlend16 RGB565 transparent weighted span helper, no IDA function object, no inbound raw-start xrefs, no raw PE rel32/VA/RVA direct reference to 0x004607e0, unique body signature, Rgb565TransparentAlphaBlendMmxBlocks call at 0x00460818 with source/destination argument order and source-side weight 32-alpha, width/4 block split, source-zero scalar skip, RGB565 weighted masks 0xf81f and 0x07e0, destination store, source/destination row-pitch stepping, and boundary padding; final source name remains descriptive/inferred and final C++ stays blank.
```

Replace the [UID:00020B] row only if the supervisor accepts the sibling score bump:

```text
    - [UID:00020B][0x00460d60-0x00460dee.ByteSpanFillRows](by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md) 0x00460d60-0x00460dee | raw function | ByteSpanFillRows : reconstructable : 85% : strong : Agent-B001 2026-06-16 reanalysis confirms exact 0x8e-byte retained SoftwareBlend16 byte-span fill row helper, no IDA function object, no inbound raw-start xrefs, no raw PE rel32/VA/RVA direct reference to 0x00460d60, unique body signature, ByteSpanFill8Blocks call at 0x00460d8e with argument order, width/8 block split, scalar byte expansion, rep stosd/rep stosb tail fill, row-pitch stepping, and boundary padding; final source name remains descriptive/inferred and final C++ stays blank.
```

No [UID:0000YG] coverage row change is recommended.

## Optional IDA Recommendations

Do not apply these from B-agent work. If the supervisor chooses to update IDA later:

| Start | End | Action |
| --- | --- | --- |
| `0x00460710` | `0x004607e0` | Define function; name `HalfBlendSpan16_Inferred`; comment: `Inferred SoftwareBlend16 retained RGB565 half-blend span helper. No direct static caller/pointer found in 2026-06-16 rel32/VA/RVA scan; calls HalfBlendSpan16Blocks and handles scalar tail.` |
| `0x004607e0` | `0x0046093c` | Define function; name `Rgb565TransparentAlphaBlendSpan_Inferred`; comment: `Inferred SoftwareBlend16 retained transparent weighted RGB565 span helper. No direct static caller/pointer found in 2026-06-16 scan; calls sub_4609E0 and handles scalar transparent tail.` |
| `0x00460c10` | `0x00460c8c` | Rename existing `sub_460C10` to `HalfBlendSpan16Blocks_Inferred` or `HalfBlendSpan16Blocks`; comment: `Four-pixel MMX RGB565 half-blend block helper called by AlphaBlendSpan16 and raw HalfBlendSpan16.` |
| `0x00460d60` | `0x00460dee` | Define function; name `ByteSpanFillRows_Inferred`; comment: `Inferred SoftwareBlend16 byte-span row fill helper. No direct static caller/pointer found in 2026-06-16 scan; calls ByteSpanFill8Blocks and handles scalar tail.` |

Use `_Inferred` unless the supervisor accepts descriptive names as IDA names without original source proof.

## Rejected Alternatives

- `RECONSTRUCTABLE:FALSE` or ignored padding for [UID:000206]: rejected. The range is executable source-domain code with prologue, loops, block-helper call, pixel math, and return.
- Merge [UID:000206] into [UID:0000YE]: rejected. There is a return and `0xcc` padding before [UID:000206].
- Merge [UID:000206] into [UID:000207]: rejected. [UID:000206] returns before [UID:000207]'s fresh prologue.
- Route [UID:000206] to Surface/software-render callback ownership: rejected. No direct callback xref targets [UID:000206], and behavior is stateless color math already grouped under [UID:0000NT].
- Treat no xrefs as purely IDA modeling failure: rejected. IDA missing the function object is a modeling issue; absence of direct static inbound references is corroborated by raw PE rel32 and VA/RVA scans.
- Insert final C++ now: rejected. The numerical gate can be met after score update, but final source name, source style, and surrounding SoftwareBlend16 declaration strategy remain below final-output quality.

## Validation Commands

If the supervisor applies only the primary [UID:000206] page and coverage-row recommendation:

> Executable block R001 was removed from this report and preserved verbatim in [000206-softwareblend16-raw-span-source-quality-removed.md](000206-softwareblend16-raw-span-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor also applies sibling score/evidence updates:

> Executable block R002 was removed from this report and preserved verbatim in [000206-softwareblend16-raw-span-source-quality-removed.md](000206-softwareblend16-raw-span-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional [UID:0000NT] body evidence note is added:

> Executable block R003 was removed from this report and preserved verbatim in [000206-softwareblend16-raw-span-source-quality-removed.md](000206-softwareblend16-raw-span-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Post-validation checks:

> Executable block R004 was removed from this report and preserved verbatim in [000206-softwareblend16-raw-span-source-quality-removed.md](000206-softwareblend16-raw-span-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected outcome:

- [UID:000206] no longer appears in Low_Completion/Low_Both at `82/88`; it should show `85/89` if the score update is accepted.
- [UID:000207] and [UID:00020B] similarly leave `82/88` if sibling updates are accepted.
- Autogen routing should remain `auto-generated/NexusTK/render/SoftwareBlend16.cpp`.
- Generated C++ file content should remain blank unless a separate final-C++ pass explicitly adds code.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000206-softwareblend16-raw-span-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"000206"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000206-softwareblend16-raw-span-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000206-softwareblend16-raw-span-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000206"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
