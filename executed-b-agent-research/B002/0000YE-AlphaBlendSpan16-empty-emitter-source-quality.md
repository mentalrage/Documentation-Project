** TARGET-REPORT-UID:0000YE **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000YE AlphaBlendSpan16 Empty-Emitter Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0000YE] `by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md` owned/emitted by [UID:0000NT] `SoftwareBlend16`, keep `COMPLETION:90` / `CONFIDENCE:92`, and populate formal `RECONSTRUCTION_CPP CODE` for this target with the exact first-draft C++ block in this report.
- Final disposition: source-authored, reconstructable, emitting SoftwareBlend16 row/span dispatcher. No split, rename, owner change, emitter change, or score raise is required.
- Required action: implementation callback should replace the target's stale final-C++ blocker wording, insert the formal C++ block below into the target `RECONSTRUCTION_CPP CODE`, add the source-form rationale and caller/no-return evidence, then validate the target and check that `auto-generated/NexusTK/render/SoftwareBlend16.cpp` refreshes from an empty emitter marker to actual source for [UID:0000YE].
- Confidence: high for behavior, range, source placement, argument order, row stepping, scalar formulas, and C++ readiness; medium-high for exact original helper spelling because the names remain descriptive/inferred.

## Supporting Research

## Target
- Target UID: `0000YE`
- Target path: `by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> Files With Empty Emitters, [UID:0000NT] `SoftwareBlend16` has 28 emitters / 0 filled, `0.0%`.
- Current supervisor classification: accepted implementation callback `B002-implement-0000YE-AlphaBlendSpan16-empty-emitter-20260629`.
- Current scores and parent state: target `90/92`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`; parent [UID:0000NT] `SoftwareBlend16` is `86/88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.

## Current Target State
- Existing metadata: `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter [UID:0000NT], reconstructable true, blank formal C++.
- Existing owner/emitter/reconstructable state: correct. The target is a stateless RGB565 blend helper under `SoftwareBlend16`, not a Surface callback body.
- Existing C++/emitter state before callback: empty emitter marker in `auto-generated/NexusTK/render/SoftwareBlend16.cpp` despite the target clearing the current numerical/emitter gate: `(90 + 92) / 2 = 91`. Callback state after `command_id:000000000956`: generated `SoftwareBlend16.cpp` contains [UID:0000YE] source at lines 7-110 and no [UID:0000YE] empty marker.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: target and by-item text still cite the old `95/95` final-code bar and list "final source spelling", "neighboring helper declarations", and "family-wide source form" as blockers. Current `by-structure.md` uses the combined-score/emitter gate as the minimum, and this target's own body can be represented as ordinary C++ while MMX block helper bodies remain separate.
- Related target/support docs checked: [UID:0000NT], [UID:0000YF], [UID:0000YG], [UID:00016L], [UID:0002OO], [UID:00028W], by-item [UID:0000TV]/[UID:0000TW]/[UID:0000US], generated memory coverage, generated research tracker, and executed B001 reports for [UID:0000YG], [UID:000206], and [UID:000209]/[UID:00020A]/[UID:00020C]/[UID:00020D]/[UID:00020E].

## Executive Recommendation
- Best direct owner/source placement: [UID:0000NT] `SoftwareBlend16`.
- Keep target metadata unchanged except formal C++: `90/92`, owner/emitter [UID:0000NT], reconstructable true.
- Populate [UID:0000YE] formal C++ now. The target is not one of the MMX block bodies whose final source form must wait for a family-wide inline-assembly/intrinsic decision. It is a scalar dispatcher/tail function that calls those separate block helpers and inlines two scalar RGB565 tails.
- Support pages [UID:0000YF] and [UID:0000YG] should not be forced to emit their MMX bodies by this callback. They only need synchronized signature/declaration notes showing that [UID:0000YE]'s first-draft code calls them through file-local prototypes.

## Supervisor Active Recheck
- The supervisor instruction asked why this high-score reconstructable SoftwareBlend16 function still emits no formal C++ and specifically prohibited shallow acceptance of source spelling, MMX/intrinsic form, neighbor declaration, or family-wide-pass blockers.
- No split repair is required. IDA MCP confirms one modeled function `sub_460500` at `0x00460500-0x00460709`, with `0xcc` padding before and after.
- Every source-bearing child in scope already exists. The unresolved MMX helper bodies are support dependencies, not a blocker to representing this dispatcher's own range.

## Inference Research Guidance Check
- IDA fact: function boundary, caller, callees, scalar formulas, row stepping, padding, and return-value non-use were checked in live MCP session `dad3692b`.
- Documentation evidence: current by-* docs already support SoftwareBlend16 ownership and helper roles but contain stale final-C++ gate wording.
- Inference: `AlphaBlendSpan16`, `AlphaBlendSpan16Blocks`, and `HalfBlendSpan16Blocks` are descriptive source-facing names, not original-symbol proof. They are still the best consistent names because current docs, one saved IDA label for [UID:0000YF], by-item pages, and SoftwareBlend16 inventory all use the same pair of weighted/half block-helper names.
- No Wave2/Wave3 instruction was used as authority. Current generated output was used only to identify the empty-emitter state.

## Heuristic / Inference Reanalysis And Validation
- Empty-emitter blocker: resolved. The blank formal C++ comes from stale caution, not missing behavior evidence. Current target scores and emitter route already satisfy the project minimum gate.
- Source form: this target should use ordinary C++ loops and helper calls. The two callee bodies [UID:0000YF]/[UID:0000YG] may still need a coherent MMX inline-assembly/intrinsic family pass, but [UID:0000YE] does not need to encode their MMX internals.
- Return type: use `void`. Hex-Rays reports `int __cdecl` because `eax` remains live, but the sole direct caller at `0x004c2ad4` immediately performs `add esp, 1Ch`, restores registers, checks the security cookie, and returns without reading `eax`.
- Argument names/types: use `const unsigned short* sourcePixels`, `int sourcePitchBytes`, `unsigned short* destinationPixels`, `int destinationPitchBytes`, `unsigned int alpha32`, `int widthPixels`, `int rowCount`. The binary reads only the low byte of the alpha argument, so the code casts `alpha32` to `unsigned char`.
- Scalar half path: use `((source >> 1) & 0x7bef) + ((destination >> 1) & 0x7bef) + (source & destination & 0x0821)`.
- Scalar weighted path: source-side weight is `(unsigned char)(32 - alpha)`, destination-side weight is `alpha`, with RGB565 masks `0xf81f` and `0x07e0`, shift by 5, then combine red/blue and green lanes.
- Rejected stale blocker, "neighbor declarations": first-draft formal code can include file-local prototypes for the two called helper functions. Those prototypes are dependency declarations, not implementations of outside ranges.
- Rejected stale blocker, "family-wide pass": valid for MMX helper bodies, not for this dispatcher. The report preserves that distinction so it does not force [UID:0000YF]/[UID:0000YG] to emit unsafe MMX source prematurely.

## Evidence Standards Used
- Live IDA MCP session `dad3692b`, `NexusTK.exe.i64`, `server_health status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- MCP checks: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `func_profile`, `decompile`, `disasm`, `insn_query`, and `get_bytes`.
- Documentation checks: target/support by-* docs, by-item mirrors, generated memory coverage, generated SoftwareBlend16 output, generated research tracker, and matching executed B reports.
- Negative evidence: no `AlphaBlendSpan16` IDA function symbol in `lookup_funcs`; only one direct caller; no return-value read after the call; no owner evidence for Surface/RGB565 callback aggregate beyond consumer context.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list`: active session `dad3692b`, `NexusTK.exe.i64`, active/adopted worker.
  - `server_health dad3692b`: status ok, imagebase `0x400000`, auto-analysis and Hex-Rays ready.
  - `lookup_funcs`: `0x00460500 -> sub_460500 size 0x209`; `AlphaBlendSpan16` not found; `0x00460b00 -> sub_460B00 size 0x10a`; `0x00460c10 -> sub_460C10 size 0x7c`; `0x004c2ad4` is inside `sub_4C0F80`.
  - `xrefs_to`: `0x00460500` has one code ref at `0x004c2ad4`; `0x00460b00` has one code ref at `0x004605fd`; `0x00460c10` has code refs at `0x00460544` and raw `0x0046073e`.
  - `func_profile 0x00460500`: 185 instructions, 20 basic blocks, prototype `int __cdecl(__m64 *, int, __m64 *, int, char, int, int)`, one caller, no strings, constants including `0x10`, `0x20`, `0x7bef`, `0x0821`, `0xf81f`, and `0x07e0`.
  - `decompile 0x00460500`: confirms alpha==16 half path, weighted path, block helper calls, pointer advancement, scalar formulas, and low-byte alpha handling.
  - `disasm 0x00460500`: confirms push windows to `sub_460C10` at `0x00460544` and `sub_460B00` at `0x004605fd`, scalar tail instruction sequences, and `retn` at `0x00460708`.
  - `insn_query` in `sub_4C0F80`: exactly one call to `sub_460500`, at `0x004c2ad4`.
  - `disasm 0x004c2ab0`: call-site window shows seven pushes before `0x004c2ad4`, then `add esp, 1Ch`, register restores, security-cookie check, and `retn 18h` with no `eax` read.
  - `get_bytes`: `0x004604f4` size 12 is all `0xcc`; `0x00460709` size 7 is all `0xcc`.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - `by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md`
  - `by-file/SoftwareBlend16.md`
  - `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`
  - `by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md`
  - `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`
  - `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`
  - `by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md`
  - `by-item/AlphaBlendSpan16_00460500.md`
  - `by-item/AlphaBlendSpan16Blocks_00460B00.md`
  - `by-item/HalfBlendSpan16Blocks_00460C10.md`
  - `auto-generated/-ag-research-tracker.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/NexusTK/render/SoftwareBlend16.cpp`
  - executed reports `executed-b-agent-research/B001/0000YG-softwareblend16-halfblend-block-source-quality.md`, `executed-b-agent-research/B001/000206-softwareblend16-raw-span-source-quality.md`, and `executed-b-agent-research/B001/000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality.md`.
- Existing report search terms used: `TARGET-REPORT-UID:0000YE`, `0000YE`, `0x00460500`, `AlphaBlendSpan16`, `SoftwareBlend16`, `AlphaBlendSpan16Blocks`, `HalfBlendSpan16Blocks`, and `Rgb565`.
- Negative checks performed:
  - No exact `TARGET-REPORT-UID:0000YE` executed report was found.
  - `lookup_funcs AlphaBlendSpan16` returned not found, so the source-facing name remains inferred/descriptive.
  - The only direct caller discards `eax`, so no meaningful return contract is proven.
  - [UID:00016L] is a Surface callback aggregate/consumer context and is explicitly non-emitting; it does not own this helper.
- Failed, unavailable, or intentionally skipped checks and why:
  - MCP `callees` call with stale `max_depth`/`max_nodes` params failed due schema mismatch; `func_profile`, `decompile`, `disasm`, and `xrefs_to` supplied the required callee evidence.
  - No validators were run because this is report-only and no by-* docs were edited.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | [UID:0000YE] remains owned/emitted by [UID:0000NT] SoftwareBlend16. | High | target metadata, SoftwareBlend16 inventory, live caller/callee context | target Status / Source Placement | already-present | applied: target metadata still `CANONICAL_OWNER:0000NT`, `EMITTER_UIDS:0000NT`; validator `000000000956` ok |
| C2 | Current `90/92` score should remain unchanged; no score raise is justified by this pass alone. | High | target already documents range/caller/formulas; remaining exact-name uncertainty remains | target Score Rationale | incorporate | applied: target metadata and score rationale keep `90/92`; validator `000000000956` ok |
| C3 | The old `95/95` final-code blocker is stale under current `by-structure.md`; [UID:0000YE] clears the current minimum numerical/emitter gate. | High | `by-structure.md` current gate; target `90/92`; emitter [UID:0000NT] | target Status / Score Rationale; by-item Changes; SoftwareBlend16 policy | incorporate | applied: stale blocker replaced with dispatcher/MMX-helper distinction; validators `000000000954`-`000000000956` ok |
| C4 | [UID:0000YE] can safely emit first-draft formal C++ now. | High | live decompile/disasm, caller return discard, scalar formula evidence, support helper pages | target `RECONSTRUCTION_CPP CODE` | incorporate | applied: exact formal code inserted; generated `SoftwareBlend16.cpp` lines 7-110 contain UID0000YE source after validator `000000000956` |
| C5 | The emitted source should be `void __cdecl AlphaBlendSpan16(...)` and cast `alpha32` to an unsigned byte before branching/weighting. | High | Hex-Rays prototype uses `char`; disassembly reads `byte ptr [arg_10]`; caller discards return | target C++ block and Inferred Signature | incorporate | applied: target formal block and signature section use `void __cdecl AlphaBlendSpan16(...)` with local `unsigned char alpha`; validator `000000000956` ok |
| C6 | `AlphaBlendSpan16Blocks` and `HalfBlendSpan16Blocks` should remain support callees with declarations only in this target's first-draft block; their MMX bodies stay blank until their own source-form pass. | Medium-high | B001 executed reports, support pages, current SoftwareBlend16 MMX policy | target C++ block; support pages [UID:0000YF]/[UID:0000YG]; SoftwareBlend16 policy | incorporate | applied: prototypes inserted/recorded; [UID:0000YF]/[UID:0000YG] generated markers remain empty after validator `000000000956`; support validators `000000000952` and `000000000953` ok |
| C7 | [UID:00016L] is consumer context only and should not become target owner/emitter. | High | [UID:00016L] non-emitting aggregate docs, Surface callback ownership | target Evidence Notes / Changes; by-item Changes | incorporate | applied: docs preserve [UID:00016L] as caller/consumer context; target metadata remains [UID:0000NT]; validators `000000000955` and `000000000956` ok |
| C8 | Generated output should refresh from an empty marker for [UID:0000YE] to first-draft source in `auto-generated/NexusTK/render/SoftwareBlend16.cpp`. | High | generated file currently lists [UID:0000YE] empty marker; target has route to [UID:0000NT] | generated refresh expectation | incorporate | applied: validator `000000000956` reported `generated_refresh: completed`; generated file contains UID0000YE source and no UID0000YE empty marker |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation:
  - Exact modeled function `sub_460500` spans `0x00460500-0x00460709`.
  - One direct caller at `0x004c2ad4`; caller discards return value.
  - Two direct block-helper calls: half path to `sub_460C10` and weighted path to `sub_460B00`.
  - Scalar tails are fully understood and use standard RGB565 formulas.
  - Adjacent ranges are `0xcc` padding, not mixed code/data.
- Corroborating documentation/generated-report evidence:
  - Target and by-item mirror already describe behavior, ownership, and signature shape.
  - SoftwareBlend16 lists [UID:0000YE] as a proposed contents item and current generated output routes it to `render/SoftwareBlend16.cpp`.
  - Generated reports mark [UID:0000YE] as `emits` but `no` code.
- Strongest inference chain and why it is sufficient:
  - The function is a stateless SoftwareBlend16 helper, has exact binary behavior, calls documented support helpers, and has no unresolved object state or protocol layout. The only real uncertainty is exact original spelling/linkage, which can be documented as inferred without blocking a first-draft formal C++ representation.

## IDA MCP Facts
- Function/range facts:
  - `sub_460500`, size `0x209`, 185 instructions, 20 basic blocks.
  - `0x004604f4-0x00460500` and `0x00460709-0x00460710` are `0xcc` padding.
- Data/table/padding facts:
  - No table or global data is owned by this target. It uses scalar immediates `0x7bef`, `0x0821`, `0xf81f`, `0x07e0`, `0x10`, and `0x20`.
- Xref facts:
  - `xrefs_to 0x00460500`: one code ref at `0x004c2ad4` inside `sub_4C0F80`.
  - `xrefs_to 0x00460b00`: one code ref at `0x004605fd`.
  - `xrefs_to 0x00460c10`: code refs at `0x00460544` and raw `0x0046073e`.
- Vtable/global/type facts:
  - None for this target. This is a free helper, not a vtable method or global data range.
- Negative IDA facts:
  - No IDA function named `AlphaBlendSpan16`.
  - No return value consumed by the only direct caller.
  - No evidence that [UID:00016L] owns this helper rather than consuming it through callback code.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00460500-0x00460709` | [UID:0000YE] `AlphaBlendSpan16` | RGB565 row/span alpha-blend dispatcher with scalar tails | `TRUE` | [UID:0000NT] | `90/92` | should emit first-draft C++ |
| `0x00460b00-0x00460c0a` | [UID:0000YF] `AlphaBlendSpan16Blocks` | weighted MMX four-pixel block helper callee | `TRUE` | [UID:0000NT] | `86/91` | keep blank body for now; declaration dependency |
| `0x00460c10-0x00460c8c` | [UID:0000YG] `HalfBlendSpan16Blocks` | 50 percent MMX four-pixel block helper callee | `TRUE` | [UID:0000NT] | `85/90` | keep blank body for now; declaration dependency |
| `0x004c0770-0x004c5fde` | [UID:00016L] `SoftwareRenderRgb565Callbacks` | RGB565 callback aggregate and consumer context | `FALSE` | `NONE` | `90/92` | not direct owner |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004c2ad4` | `sub_4C0F80 -> sub_460500` | Sole modeled caller; caller discards `eax`. |
| `0x00460544` | `sub_460500 -> sub_460C10` | 50 percent block path to [UID:0000YG]. |
| `0x004605fd` | `sub_460500 -> sub_460B00` | non-50-percent weighted block path to [UID:0000YF]. |
| `0x0046073e` | raw [UID:000206] caller -> `sub_460C10` | support evidence that [UID:0000YG] is shared by modeled and raw half-span paths. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - [UID:0000YE] target page already records exact range, sole caller, block/tail split, scalar formulas, and SoftwareBlend16 ownership.
  - [UID:0000NT] lists this helper as part of the low-level 16-bit blending file.
  - [UID:0000YF]/[UID:0000YG] document the callee semantics and valid [UID:0000NT] routing.
- Existing docs that are stale, incomplete, or contradicted:
  - [UID:0000YE] and by-item [UID:0000TV] cite the older `95/95` final-code bar and describe final C++ as intentionally blank until source spelling/declarations/family pass. That is now too broad for this dispatcher.
  - [UID:0000YE] should explicitly distinguish "block helper bodies remain blank" from "dispatcher can emit now".
- Generated/coverage report state:
  - `auto-generated/NexusTK/render/SoftwareBlend16.cpp` refreshed at validator command id `000000000948` and currently lists [UID:0000YE] as an empty emitter marker.
  - `auto-generated/-ag-memory-coverage.md` row for [UID:0000YE] is `emits` through `0000NT`, output `auto-generated/NexusTK/render/SoftwareBlend16.cpp`, but `no` code.
  - `auto-generated/-ag-research-tracker.md` row for [UID:0000NT] reports 28 emitters, 0 filled, `0.0%`; [UID:0000YE] row is `90/92`, true, no executed report.

## Ranked Ownership Analysis

### 1. [UID:0000NT] SoftwareBlend16
- Evidence for: current owner/emitter metadata; SoftwareBlend16 proposed contents include [UID:0000YE]; helper is stateless RGB565 blend math; callees and constants/scratch support pages are already in SoftwareBlend16; generated output route is valid.
- Evidence against: direct caller is inside an RGB565 callback body, but that is consumer evidence, not direct source ownership.
- Decision: accepted. Keep owner/emitter unchanged.

### 2. [UID:00016L] SoftwareRenderRgb565Callbacks / Surface callback family
- Evidence for: sole direct caller is inside `sub_4C0F80`, the RGB565 sprite/block callback family.
- Evidence against: [UID:00016L] is explicitly a non-emitting aggregate; callback pages own dispatch/control bodies, while SoftwareBlend16 owns stateless blend helpers. [UID:0000YE] has no callback-table slot, receiver, Surface field access, or UI state.
- Decision: rejected as direct owner. Preserve as caller/context reference only.

### 3. New standalone helper file or no-owner/non-emitting
- Evidence for: none beyond descriptive name uncertainty.
- Evidence against: parent [UID:0000NT] already clears the gate and inventories the whole helper family; target has valid emitter route and exact behavior.
- Decision: rejected. No new owner and no no-owner/non-emitting classification.

## Source Placement
- Recommended source file/class/global/module placement: `NexusTK/render/SoftwareBlend16.cpp` under [UID:0000NT].
- Why this placement fits source-tree and subsystem context: the target is an ordinary free/static render helper used by RGB565 callback code; it manipulates only source/destination row pointers, pitches, alpha, width, and row count.
- Rejected placements and why: Surface/callback ownership is consumer-side; UI/pane ownership is unsupported; constants/scratch pages are support data, not the function owner.
- Remaining placement uncertainty: exact original filename could have been `Blend16.cpp`, `SoftwareBlend16.cpp`, or part of a broader blitter source file. Current project owner [UID:0000NT] is still the correct reconstruction route.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: modeled function `0x00460500-0x00460709`; preceding twelve bytes from `0x004604f4` are `0xcc`; following seven bytes at `0x00460709` are `0xcc`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none.
- Padding/table/data/code distinctions: adjacent padding is outside the target; no jump table or embedded data belongs inside [UID:0000YE].
- Parent/container impact: no parent/container change.

## Negative Evidence Summary
- No original source symbol was found for `AlphaBlendSpan16`; preserve inferred/descriptive naming language.
- The direct caller does not prove Surface ownership because it calls this helper as a stateless primitive and discards its return value.
- The MMX source-form blocker for [UID:0000YF]/[UID:0000YG] does not block [UID:0000YE]'s dispatcher source. This report does not claim the MMX block helper bodies are ready.
- No score raise is recommended because exact original names/linkage and final family declarations are still inferred.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments:
  - Source-facing function: `AlphaBlendSpan16`.
  - Signature: `void __cdecl AlphaBlendSpan16(const unsigned short* sourcePixels, int sourcePitchBytes, unsigned short* destinationPixels, int destinationPitchBytes, unsigned int alpha32, int widthPixels, int rowCount)`.
  - Dependency prototypes: `AlphaBlendSpan16Blocks` and `HalfBlendSpan16Blocks` as file-local `__cdecl` helpers using `unsigned short*` rows and byte pitches.
- Evidence for each proposed name/type/comment:
  - Names match existing by-memory/by-item pages and SoftwareBlend16 inventory; [UID:0000YF] has a saved IDA label `AlphaBlendSpan16Blocks`.
  - `void` is supported by caller non-use of `eax`.
  - `unsigned short*` rows are supported by word loads/stores and RGB565 masks; pitches are byte additions.
- Items intentionally left unchanged and why:
  - IDA database should not be renamed from this report-only pass.
  - [UID:0000YF]/[UID:0000YG] formal bodies stay blank pending their own MMX source-form pass.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text for [UID:0000YE]:

```cpp
static void __cdecl AlphaBlendSpan16Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount);

static void __cdecl HalfBlendSpan16Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl AlphaBlendSpan16(
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
    int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (alpha == 16) {
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

        return;
    }

    if (blockCount4Pixels > 0) {
        AlphaBlendSpan16Blocks(
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

    const unsigned int destinationWeight32 = alpha;
    const unsigned int sourceWeight32 = static_cast<unsigned char>(32 - alpha);

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
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

- Third-party import directive: not applicable.
- Reason it preserves exact original behavior:
  - Uses signed `widthPixels / 4` and `widthPixels - blockCount4Pixels * 4` like the binary's block/tail split for ordinary nonnegative render widths.
  - Branches on the low byte of alpha and uses `alpha == 16` for the half path.
  - Calls half and weighted block helpers with the same source/destination pointer, pitch, block count, and row count order observed in disassembly.
  - Advances row pointers by caller-supplied byte pitches.
  - Keeps destination-side alpha weighting and source-side `32 - alpha` weighting for the scalar weighted tail.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape:
  - Plain file-local helper prototypes plus a C-style `__cdecl` free function fit MSVC-era render helper code better than decompiler temporaries.
  - Uses `unsigned short`/byte pitch arithmetic instead of `__m64*` decompiler artifacts for scalar span code.
  - Leaves MMX block implementation choices to the helper pages rather than forcing portable replacements into this target.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `sourcePixels`, `destinationPixels`, `sourcePitchBytes`, `destinationPitchBytes`, `alpha32`, `widthPixels`, `rowCount`, `blockCount4Pixels`, and `tailPixels`.
- Naming/coding style convention used and evidence for consistency: descriptive SoftwareBlend16 helper names already present in target/support docs, by-item mirrors, and [UID:0000NT] inventory.
- Reason code should remain blank, if applicable: not applicable for [UID:0000YE]. It should not remain blank.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes recommended:
  - Populate [UID:0000YE] formal C++ with the block above.
  - Replace stale old-gate wording in [UID:0000YE] and by-item [UID:0000TV].
  - Add a note in [UID:0000YE] that the target can emit now while [UID:0000YF]/[UID:0000YG] MMX helper bodies remain separate blank emitters pending their own source-form pass.
- Exact parent assignments recommended: keep [UID:0000NT] owner/emitter.
- Exact items left no-owner/non-emitting and why: none for this target.
- Exact future work outside this assignment scope: coherent final C++ for MMX block helpers and SoftwareBlend16 constants/scratch support remains a separate family-level task.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md`
- Exact report facts to incorporate:
  - Live MCP session `dad3692b` reconfirmed exact function, caller, callees, scalar formulas, caller return discard, and padding.
  - The target is eligible for formal first-draft C++ now despite support helper bodies remaining blank.
  - Source-facing names/signature remain inferred/descriptive but are strong enough for first-draft insertion.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Keep `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`.
  - Replace blank `RECONSTRUCTION_CPP CODE` with the exact formal code block above.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Historical old `95/95` gate wording should be replaced, not preserved as current policy.
  - Preserve that exact original spelling is not proven.
  - Preserve rejected Surface/[UID:00016L] ownership and caller return-value non-use.

## Recommended Support Doc Changes
- Support path: `by-item/AlphaBlendSpan16_00460500.md`
  - Exact facts to incorporate: by-item mirror should stop saying final C++ is blank because of old `95/95`/family-wide blockers; it should mirror [UID:0000YE]'s first-draft readiness and formal target C++ decision.
  - Metadata/link/score/coverage/source-placement changes: no score/owner/emitter change required unless supervisor chooses to also emit by-item code. Preferred implementation is target by-memory formal C++ only to avoid duplicate generated function bodies.
- Support path: `by-file/SoftwareBlend16.md`
  - Exact facts to incorporate: add a short note that [UID:0000YE] is the first safe dispatcher/tail helper to emit as ordinary C++ while MMX block helper bodies remain blank pending family source-form work.
  - Metadata/link/score/coverage/source-placement changes: no metadata or score change.
- Support path: `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`
  - Exact facts to incorporate: add or confirm the source-facing declaration used by [UID:0000YE]:
    `static void __cdecl AlphaBlendSpan16Blocks(const unsigned short*, int, unsigned short*, int, unsigned char, int, int);`
  - Metadata/link/score/coverage/source-placement changes: no score/owner/emitter change; formal body remains blank.
- Support path: `by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md`
  - Exact facts to incorporate: add or confirm the source-facing declaration used by [UID:0000YE]:
    `static void __cdecl HalfBlendSpan16Blocks(const unsigned short*, int, unsigned short*, int, int, int);`
  - Metadata/link/score/coverage/source-placement changes: no score/owner/emitter change; formal body remains blank.
- Support path: `auto-generated/NexusTK/render/SoftwareBlend16.cpp`
  - Do not edit manually. Validator/autogen should refresh it after target validation.

## Score And Metadata Recommendation
- Current score/metadata after callback: `90/92`, owner/emitter [UID:0000NT], reconstructable true, populated [UID:0000YE] formal C++.
- Recommended score/metadata: keep `90/92`, owner/emitter [UID:0000NT], reconstructable true; populate formal C++.
- Score rationale and reason not higher/lower:
  - Not higher: exact original source spelling/linkage remains inferred, and support helper MMX bodies still need a family-level source-form decision.
  - Not lower: behavior, range, caller, callees, scalar formulas, and source placement are live-MCP-confirmed and sufficient for first-draft code.
- Score-improvement attempt:
  - Final source spelling blocker: resolved enough for inferred first-draft names; no original symbol found, so no score raise.
  - MMX/intrinsic source-form blocker: narrowed to support helper bodies only; not a blocker for [UID:0000YE].
  - Neighbor declaration blocker: resolved by including file-local dependency prototypes and recommending support signature notes.
  - Family-wide pass blocker: rejected for this dispatcher; retained only for separate MMX block helper bodies.
- Metadata fields to change or leave unchanged: leave all metadata unchanged except formal C++ content.

## Open Questions With Attempted Resolution
- Open question: exact original function spelling.
  - Evidence checked: IDA `lookup_funcs AlphaBlendSpan16`, by-* docs, generated output, executed reports.
  - Best supported resolution: `AlphaBlendSpan16` is descriptive/inferred but project-consistent and strong enough for first-draft formal code.
- Open question: exact helper linkage and prototype placement.
  - Evidence checked: current SoftwareBlend16 policy, support pages, caller push windows.
  - Best supported resolution: file-local/static cdecl prototypes in the target code are the practical first-draft representation; support docs should record the same signatures.
- Open question: can support MMX helper bodies remain blank?
  - Evidence checked: executed B001 reports, target decompile/disasm, generated output.
  - Best supported resolution: yes. [UID:0000YE] can emit calls to those helpers while their exact bodies remain separate unresolved emitters.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. Do not manually edit `auto-generated/-ag-*` reports. No manual `-coverage-report.md` row is required by this report. Validator/autogen refresh should update generated empty-emitter state after target formal C++ insertion.

## Follow-Up Actions
- Supervisor actions: validate this report; if accepted, send B002 an implementation callback to edit [UID:0000YE], by-item [UID:0000TV], [UID:0000NT], and support signature notes in [UID:0000YF]/[UID:0000YG].
- A-agent actions: none required.
- B002 future research actions: after callback, run scoped validators for edited files and verify generated `SoftwareBlend16.cpp` contains [UID:0000YE] code while support helper bodies remain empty markers.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for keeping `90/92`.
- Remaining uncertainty: exact original symbol spelling and file-local declaration style remain inferred; support MMX helper bodies still require family-level source-form work.

## Validator Results
- Commands run:
  - `python .\tools\validator.py --mode file --file by-memory\0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md --apply --queue-timeout 240`
    - `command_id:000000000952`, `command_timestamp:2026-06-29T17:19:10-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md --apply --queue-timeout 240`
    - `command_id:000000000953`, `command_timestamp:2026-06-29T17:19:17-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`.
  - `python .\tools\validator.py --mode file --file by-file\SoftwareBlend16.md --apply --queue-timeout 240`
    - `command_id:000000000954`, `command_timestamp:2026-06-29T17:19:28-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`.
  - `python .\tools\validator.py --mode file --file by-item\AlphaBlendSpan16_00460500.md --apply --queue-timeout 240`
    - `command_id:000000000955`, `command_timestamp:2026-06-29T17:19:41-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00460500-0x00460709.AlphaBlendSpan16.md --apply --wait-generated --queue-timeout 240`
    - `command_id:000000000956`, `command_timestamp:2026-06-29T17:19:48-04:00`, exit `0`, `ok:1`, `generated_refresh:completed`.
- Generated verification: `auto-generated/NexusTK/render/SoftwareBlend16.cpp` contains [UID:0000YE] source beginning at line 7, including `void __cdecl AlphaBlendSpan16(...)`, and no [UID:0000YE] empty marker. [UID:0000YF] and [UID:0000YG] remain empty markers as intended.
- Any unresolved validator warnings/errors: `SoftwareBlend16.md` validator run `000000000954` reported pre-existing `missing_ref_uid 0003ZP` warnings; not introduced or resolved by this scoped callback. The final target run reported many project-wide `autogen_emitter_has_no_code`/children marker notices during generated refresh, with scoped result `ok:1`.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B002/research/0000YE-AlphaBlendSpan16-empty-emitter-source-quality.md`.
- Modified in implementation callback:
  - `by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md`
  - `by-item/AlphaBlendSpan16_00460500.md`
  - `by-file/SoftwareBlend16.md`
  - `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`
  - `by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md`
  - `tools/leaser/Agents/Agent-B002/research/0000YE-AlphaBlendSpan16-empty-emitter-source-quality.md`
- Validator-generated refresh touched generated/project files, including `auto-generated/NexusTK/render/SoftwareBlend16.cpp`, generated tracker/coverage outputs, project stats, validator state, and validator backups. These were not manually edited.
- Renamed: none.
- Report execution: leave blank during the B-agent pass. The supervisor runs `tools/validator.py execute_report ... --apply` after verification.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report for implementation in the 2026-06-29 callback.
- [x] Target/support docs to update:
  - `by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md`: insert formal C++ block; replace stale old-gate C++ blocker; add `dad3692b` evidence and first-draft readiness rationale.
  - `by-item/AlphaBlendSpan16_00460500.md`: synchronize final-C++ readiness wording without duplicating generated function code unless supervisor explicitly wants by-item code.
  - `by-file/SoftwareBlend16.md`: add a short note distinguishing [UID:0000YE] dispatcher readiness from the still-blank MMX block helper bodies.
  - `by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md`: record/confirm dependency prototype used by [UID:0000YE]; keep body blank.
  - `by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md`: record/confirm dependency prototype used by [UID:0000YE]; keep body blank.
- [x] Current target state and actual evidence checked recorded: [UID:0000YE] `90/92`, owner/emitter [UID:0000NT], live MCP session `dad3692b`, generated empty marker state, support docs and executed reports.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger C1-C8 above.
- [x] Metadata/score changes to apply: no score, owner, emitter, reconstructable, split, or rename metadata change; formal C++ changes only.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: old final-code blockers resolved for [UID:0000YE]; MMX helper body blocker scoped to support pages only.
- [x] Owner/emitter/reconstructable changes to apply: none; kept [UID:0000NT] / [UID:0000NT] / `TRUE` through target validator `000000000956`.
- [x] Split/rename/new-child changes to apply: none.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: kept source placement; no IDA edits requested.
- [x] First-draft C++ or no-code proof to apply: exact formal `AlphaBlendSpan16` C++ block from this report is in [UID:0000YE] and generated output.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: caller/callee facts, scalar formulas, void-return decision, inferred name/prototype caveat, support helper body caveat, generated refresh expectation.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: replaced old `95/95` blocker as stale; preserved exact-name uncertainty and rejected Surface/[UID:00016L] ownership.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: no Wave2/Wave3 evidence used as authority.
- [x] Open questions to close or document as evidence-backed unresolved: exact original spelling and final MMX helper source form remain evidence-backed unresolved but do not block this target's first-draft C++.
- [x] Validators to run:
  - `python .\tools\validator.py --mode file --file by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-item/AlphaBlendSpan16_00460500.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file/SoftwareBlend16.md --apply --queue-timeout 240`
  - If support docs are edited: scoped file validators for [UID:0000YF] and [UID:0000YG].
  - Confirm generated refresh state for `auto-generated/NexusTK/render/SoftwareBlend16.cpp`; use `--wait-generated` if generated headers lag the returned command metadata.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated reports/source refreshed through validator/autogen; no manual coverage/tracker text applied.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator; no manual supervisor-owned coverage/tracker text supplied.
- [x] Remaining unapplied accepted items listed with exact blocker: none for [UID:0000YE]; [UID:0000YF]/[UID:0000YG] MMX bodies remain intentionally blank as separate future work, not unapplied accepted items.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0000YE-AlphaBlendSpan16-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0000YE-AlphaBlendSpan16-empty-emitter-source-quality.md","timestamp":"2026-06-29T17:23:43","uid":"0000YE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
