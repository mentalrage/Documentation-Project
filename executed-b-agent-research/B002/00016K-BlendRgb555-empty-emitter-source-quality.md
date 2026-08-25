** TARGET-REPORT-UID:00016K **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00016K BlendRgb555 Empty-Emitter Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00016K] `by-memory/0x004c0710-0x004c076d.BlendRgb555.md` owned/emitted by [UID:0000NT] `SoftwareBlend16`, keep `COMPLETION:90` / `CONFIDENCE:92`, keep `Nested:-4`, and populate formal `RECONSTRUCTION_CPP CODE` with the exact first-draft `BlendRgb555(...)` C++ block in this report.
- Final disposition: source-authored, reconstructable, emitting SoftwareBlend16 RGB555 single-pixel weighted blend helper. No split, rename, owner change, emitter change, reconstructable change, or score raise is required.
- Required action: implementation callback should replace stale `95/95`/final-name/signature blocker wording in the target and by-item mirror, insert the formal C++ block below into [UID:00016K], synchronize [UID:0000NT] `SoftwareBlend16` source-readiness wording, then validate the edited docs and verify `auto-generated/NexusTK/render/SoftwareBlend16.cpp` changes from [UID:00016K] empty marker to source.
- Confidence: high for exact range, callers, no callees, no strings/globals, return contract, RGB555 masks, 0..32 fixed-point behavior, owner/emitter route, and C++ readiness; medium-high for exact original helper spelling because the name remains source-facing/descriptive rather than symbol-proven.

## Supporting Research

## Target
- Target UID: `00016K`
- Target path: `by-memory/0x004c0710-0x004c076d.BlendRgb555.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `Files With Empty Emitters`; [UID:0000NT] `SoftwareBlend16` currently shows `28` emitters, `1` filled, `27` marked empty, `3.6%`, output `auto-generated/NexusTK/render/SoftwareBlend16.cpp`.
- Current supervisor classification: report-only assignment `B002-report-00016K-BlendRgb555-empty-emitter-20260629`.
- Current scores and parent state: target `90/92`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`; parent [UID:0000NT] `SoftwareBlend16` is `86/88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.

## Current Target State
- Existing metadata: `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter [UID:0000NT], reconstructable true, `Nested:-4`, blank formal C++.
- Existing owner/emitter/reconstructable state: correct. The target is a state-free RGB555 scalar blend primitive under `SoftwareBlend16`, not a callback-table implementation.
- Existing C++/emitter state: `auto-generated/NexusTK/render/SoftwareBlend16.cpp` refreshed at validator command `000000000963` / `2026-06-29T17:28:03-04:00` and still contains `// UID:00016K ... Empty Emitter Marker`.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: target and by-item text cite the older `95/95` final-code bar and final helper name/signature uncertainty as a reason for blank C++. Current `by-structure.md` uses the combined-score/emitter gate and requires exact evidence-backed source-shape reasoning, not final original symbol proof.
- Related target/support docs checked: [UID:0000TZ] by-item mirror, [UID:0000NT] `SoftwareBlend16`, [UID:00016J] `SoftwareRenderCompatCallbacks`, [UID:0000YD] `Rgb555565BlitHelpers`, [UID:00016M] `BlendRgb565Pixel`, generated memory coverage, generated SoftwareBlend16 output, generated research tracker, and relevant executed/active B reports and A/C notes.

## Executive Recommendation
- Best direct owner/source placement: [UID:0000NT] `SoftwareBlend16`.
- Keep target metadata unchanged except formal C++ content: `90/92`, owner/emitter [UID:0000NT], reconstructable true, `Nested:-4`.
- Populate [UID:00016K] formal C++ now. It is a one-block scalar return-value helper with exact arithmetic, no callees, no state, no outside declarations, no MMX source-form problem, and callers that consume the returned pixel.
- Support pages should be synchronized, not structurally changed. [UID:0000TZ] should stop saying C++ remains blank for old final-code-bar reasons, and [UID:0000NT] should record that this scalar RGB555 helper can emit ordinary C++ independent of the unresolved MMX block-helper bodies.

## Supervisor Active Recheck
- The supervisor asked why this high-score reconstructable SoftwareBlend16 RGB555 scalar helper still emits no formal C++ and explicitly prohibited shallow acceptance of final original name/signature blockers.
- No split repair is required. Current MCP confirms one modeled function `sub_4C0710` at `0x004c0710-0x004c076d`, with padding before and after.
- Every source-bearing child in scope already exists. The target is not an aggregate and does not require support declarations or sibling body implementations before its own source can emit.

## Inference Research Guidance Check
- IDA fact: function boundary, caller set, callee absence, one-block arithmetic body, constants, return-in-EAX behavior, and padding were checked in live MCP session `dad3692b`.
- Documentation evidence: target/support docs already support SoftwareBlend16 ownership and RGB555 helper role, but contain stale final-C++ blocker wording.
- Inference: `BlendRgb555` is source-facing/descriptive, not original-symbol proof. It is still the best project-consistent name because the target page, by-item page, SoftwareBlend16 inventory, and current IDA label history use the same RGB555/RGB565 naming pattern.
- No Wave2/Wave3 instruction was used as authority. Generated output was used only to identify the empty-emitter state and route.

## Heuristic / Inference Reanalysis And Validation
- Empty-emitter blocker: resolved. The blank C++ is stale caution, not missing behavior evidence. [UID:00016K] satisfies the current gate: reconstructable true, nonblank emitter route through [UID:0000NT], and `(90 + 92) / 2 = 91`.
- Source form: ordinary C++ is appropriate. Unlike MMX block helpers, this target uses scalar integer arithmetic only; no inline assembly, intrinsics, scratch qwords, constants declarations, or sibling prototypes are needed.
- Return type: use a 16-bit source-facing return. Hex-Rays reports `unsigned int __cdecl(__int16, __int16, unsigned __int8)` because the value is carried in `eax`, but every observed caller stores the low 16 bits back into a destination pixel. `unsigned short` communicates the RGB555 pixel contract while preserving the masked 16-bit result.
- Argument roles: first pixel is weighted by the supplied 0..32 byte weight; second pixel is weighted by `32 - weight`. Current callers often pass the destination pixel first and a palette/source color second, but the helper itself is generic, so the recommended formal names are `firstPixel`, `secondPixel`, and `firstWeight32`.
- Type choice: use `unsigned short` and `unsigned char`, not `uint16_t`, because neighboring accepted SoftwareBlend16 first-draft C++ uses VC6-era built-in unsigned types and the current docs do not prove a project typedef for RGB555 pixels. The report rejects IDA/Ghidra labels like `sub_4C0710`, `a1`, `a2`, and `param_3` as final source names.
- `Nested:-4`: keep unchanged. Generated memory coverage currently renders [UID:00016K] after the nested [UID:00016J] compat-callback child list and before [UID:00016L]; the negative nesting value is the display correction that returns this SoftwareBlend16 leaf helper to the outer level instead of making it a child of the non-emitting compat aggregate.
- Rejected stale blocker, final original name/signature: lack of original symbol proof caps score below final audit but does not block first-draft C++. The name/signature are sufficiently documented and the formal block can record inferred source-facing names.
- Rejected ownership alternative, [UID:00016J]/Surface callback family: callers consume this helper, but the target has no callback-table slot, receiver state, Surface fields, or dispatch role. Callback ownership belongs to the callback bodies; the stateless pixel math belongs to SoftwareBlend16.

## Evidence Standards Used
- IDA MCP evidence: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `func_profile`, `callees`, `get_bytes`, `decompile`, `disasm`, `analyze_function`, and `insn_query`.
- Documentation evidence: current target by-memory, by-item mirror, SoftwareBlend16, compat callback aggregate, RGB555/RGB565 helper island, RGB565 sibling helper, generated research tracker, generated memory coverage, and generated SoftwareBlend16 C++.
- Old-report evidence: searched executed, active, archived, and notes paths for the required terms. No direct B report for `TARGET-REPORT-UID:00016K` was found; A/C notes and sibling B reports were treated as leads only.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list`: active session `dad3692b`, `NexusTK.exe.i64`, worker pid `13916`, not analyzing.
  - `server_health database=dad3692b`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
  - `lookup_funcs`: `0x004c0710 -> sub_4C0710 size 0x5d`; `0x004c076d` not a function; `0x004c0770 -> sub_4C0770 size 0xd5`; `BlendRgb555` and `BlendRgb555_4C0710` not found in current MCP symbols.
  - `xrefs_to 0x004c0710`: 13 code refs: `0x004bb987`, `0x004bbb0c`, `0x004bbbec`, `0x004bbc3c`, `0x004bc563`, `0x004bc6e4`, `0x004bc858`, `0x004bc864`, `0x004bca47`, `0x004bca70`, `0x004bcc44`, `0x004bd001`, and `0x004bd3a7`.
  - `func_profile 0x004c0710`: 33 instructions, one basic block, prototype `unsigned int __cdecl(__int16, __int16, unsigned __int8)`, three caller functions, no callees, no strings, constants `0x20`, `0x03e0`, `0x7c1f`, and shifts by `5`.
  - `callees 0x004c0710`: none.
  - `get_bytes`: `0x004c0704-0x004c0710` is twelve `0xcc` bytes; `0x004c076d-0x004c0770` is three `0xcc` bytes.
  - `decompile 0x004c0710`: returns RGB555 lane blend with `(32 - weight)` inverse, masks `0x03e0` and `0x7c1f`, and right shift by five.
  - `disasm 0x004c0710`: confirms byte weight load/subtract, `imul` per lane group, `shr 5`, final `or eax, edi`, and `retn` at `0x004c076c`.
  - `decompile 0x004bb8d0` and `decompile 0x004bb9b0`: representative callers assign the returned value back to `*destination`, proving non-void return use.
  - `insn_query` over `0x004bb8d0-0x004bd3e8`: finds exactly the 13 `call sub_4C0710` sites listed above.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - `by-memory/0x004c0710-0x004c076d.BlendRgb555.md`
  - `by-item/BlendRgb555_004C0710.md`
  - `by-file/SoftwareBlend16.md`
  - `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`
  - `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`
  - `by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md`
  - `by-item/BlendRgb565Pixel_004C6050.md`
  - `by-structure.md`
  - `by-memory/-guidance.md`
  - `auto-generated/-ag-research-tracker.md`
  - `auto-generated/-ag-coverage-report-by-memory.md`
  - `auto-generated/NexusTK/render/SoftwareBlend16.cpp`
  - Relevant old leads: Agent-A001 notes, Agent-C001 notes, Agent-A005 notes, `executed-b-agent-research/B002/0000YE-AlphaBlendSpan16-empty-emitter-source-quality.md`, `tools/leaser/Agents/Agent-B003/research/0000YF-AlphaBlendSpan16Blocks-empty-emitter-source-quality.md`, and SoftwareBlend16 sibling reports found by search.
- Existing report search terms used: `TARGET-REPORT-UID:00016K`, `00016K`, `0x004c0710`, `BlendRgb555`, `BlendRgb555_004C0710`, `SoftwareBlend16`, `RGB555`, `0x7c1f`, `0x03e0`, `SoftwareRenderCompat`, `compatibility-render`, and caller/source-family terms.
- Negative checks performed:
  - No exact `TARGET-REPORT-UID:00016K` executed report was found.
  - Current MCP has no active function symbol named `BlendRgb555` or `BlendRgb555_4C0710`, so the name remains inferred/descriptive.
  - No callees, strings, global reads/writes, or data refs are required by the target body.
  - Caller evidence points to consumer callbacks, not direct callback ownership.
- Failed, unavailable, or intentionally skipped checks and why:
  - Initial MCP calls with older parameter names (`address`, `session`, `size`) returned schema errors; the schemas were refreshed via `tools/list`, then the calls succeeded with `database`, `addrs`, `queries`, and `regions`.
  - No validators were run because this is report-only and no by-* docs were edited.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | [UID:00016K] remains owned/emitted by [UID:0000NT] SoftwareBlend16. | High | target metadata, SoftwareBlend16 inventory, caller/consumer distinction, generated route | target Status / Source Placement; SoftwareBlend16 ownership notes | already-present | already-present: target metadata was kept unchanged; `by-memory/0x004c0710-0x004c076d.BlendRgb555.md` Source Placement and `by-file/SoftwareBlend16.md` ownership notes now explicitly preserve SoftwareBlend16 as direct owner/emitter. |
| C2 | Current `90/92` score should remain unchanged. | High | exact behavior/range supports high score; original name still unproven caps final audit | target Score Rationale | incorporate | applied: `by-memory/0x004c0710-0x004c076d.BlendRgb555.md` Score And C++ Readiness states keep `90/92`; validator `000000000990` passed. |
| C3 | `Nested:-4` remains correct. | High | generated memory coverage nesting around [UID:00016J] children and [UID:00016L] sibling | target metadata / coverage rationale | already-present | already-present: target metadata kept `Nested:-4`; target Source Placement section now records the nesting rationale. |
| C4 | The stale `95/95` final-code blocker is invalid under current `by-structure.md`; [UID:00016K] clears the current C++ eligibility gate. | High | `by-structure.md`; target `90/92`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000NT` | target Status / Changes; by-item Changes | incorporate | applied: target Behavior/Changes and by-item Behavior/Changes replace the old blocker with score-cap-only wording; validators `000000000990` and `000000000991` passed. |
| C5 | [UID:00016K] can safely emit first-draft formal C++ now. | High | one-block scalar decompile/disasm, no callees/globals, caller return use | target `RECONSTRUCTION_CPP CODE` | incorporate | applied: formal C++ block inserted in `by-memory/0x004c0710-0x004c076d.BlendRgb555.md`; generated `SoftwareBlend16.cpp` contains UID00016K source at command `000000000992`. |
| C6 | Formal source should use `unsigned short __cdecl BlendRgb555(unsigned short firstPixel, unsigned short secondPixel, unsigned char firstWeight32)`. | High | MCP prototype, caller return stores, RGB555 pixel semantics, SoftwareBlend16 style | target C++ block and signature prose | incorporate | applied: exact signature inserted in target formal C++ and described in target/by-item prose. |
| C7 | The first argument is weighted by `firstWeight32`; the second is weighted by `static_cast<unsigned char>(32 - firstWeight32)`. | High | decompile and disassembly at `0x004c0713-0x004c0766` | target Behavior / C++ block | incorporate | applied: target formal C++ and Behavior prose include the accepted first/inverse weight behavior. |
| C8 | [UID:00016J]/compat callbacks are consumer context, not direct owner. | High | 13 call sites inside callbacks; callback aggregate docs; no callback-table slot for target | target ownership notes; by-item evidence | incorporate | applied/already-present: target Source Placement and by-item evidence preserve consumer-context wording; `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md` already had sufficient lower-level-helper consumer wording and was not edited. |
| C9 | Generated output should refresh from [UID:00016K] empty marker to source in `auto-generated/NexusTK/render/SoftwareBlend16.cpp` after accepted implementation. | High | generated file currently contains UID00016K empty marker and valid SoftwareBlend16 route | implementation checklist / generated verification | incorporate | applied: generated header is `validator-command-id: 000000000992`, `validator-refreshed-at: 2026-06-29T17:55:43-04:00`; UID00016K now contains `BlendRgb555` source and no UID00016K empty marker. |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation:
  - Exact modeled function `sub_4C0710` spans `0x004c0710-0x004c076d`.
  - The function is one basic block, 33 instructions, with no callees and no strings.
  - It computes a pure RGB555 weighted blend using masks `0x03e0` and `0x7c1f`, 0..32 weights, and shift by five.
  - The return value is consumed by callers and stored back to 16-bit destination pixels.
  - Boundary bytes before and after the function are `0xcc` padding.
- Corroborating documentation/generated-report evidence:
  - Target, by-item, SoftwareBlend16, and Rgb555565BlitHelpers docs already classify this as a stateless RGB555 render helper under SoftwareBlend16.
  - Generated research tracker and generated C++ route [UID:00016K] through [UID:0000NT] to `NexusTK/render/SoftwareBlend16.cpp`.
  - Compatibility callback docs explicitly say lower-level color/blit math such as [UID:00016K] should stay in SoftwareBlend16 or a sibling render blitter source, not Ranking or callback aggregate ownership.
- Strongest inference chain and why it is sufficient:
  - The target has exact binary behavior, no hidden dependencies, valid SoftwareBlend16 routing, and a project-consistent source-facing name. Exact original symbol proof is absent, but that only caps score; it does not block a formal first-draft helper whose source semantics are fully local.

## IDA MCP Facts
- Function/range facts: `sub_4C0710`, size `0x5d` / 93 bytes, one basic block, 33 instructions, `0x004c076d` not a function, next function `sub_4C0770` at `0x004c0770`.
- Data/table/padding facts: no owned data/table; twelve `0xcc` bytes at `0x004c0704-0x004c0710`; three `0xcc` bytes at `0x004c076d-0x004c0770`.
- Xref facts: 13 direct code refs from `sub_4BB8D0`, `sub_4BB9B0`, and `sub_4BC090`.
- Vtable/global/type facts: no vtable refs, no global state, no strings, no data refs needed for this target.
- Negative IDA facts: no current function named `BlendRgb555`; no callees; no evidence of Surface callback-table target status for this helper.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004c0710-0x004c076d` | [UID:00016K] `BlendRgb555` | RGB555 single-pixel 0..32 weighted blend helper | `TRUE` | [UID:0000NT] | `90/92` | should emit first-draft C++ |
| `0x004bb8d0-0x004c069e` | [UID:00016J] `SoftwareRenderCompatCallbacks` | non-emitting compatibility callback aggregate and consumer context | `FALSE` | `NONE` | `89/91` | not direct owner |
| `0x0045fa00-0x004604f4` | [UID:0000YD] `Rgb555565BlitHelpers` | RGB555/RGB565 span/blit helper island | `TRUE` | [UID:0000NT] | `86/90` | source-family support |
| `0x004c6050-0x004c60c7` | [UID:00016M] `BlendRgb565Pixel` | RGB565 sibling scalar blend helper | `TRUE` | [UID:0000NT] | `90/92` | sibling empty-emitter follow-up candidate |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004bb987` | `sub_4BB8D0 -> sub_4C0710` | Compat pixel callback blend path stores return to destination pixel. |
| `0x004bbb0c`, `0x004bbbec`, `0x004bbc3c` | `sub_4BB9B0 -> sub_4C0710` | Compat line callback blend paths. |
| `0x004bc563`, `0x004bc6e4`, `0x004bc858`, `0x004bc864`, `0x004bca47`, `0x004bca70`, `0x004bcc44`, `0x004bd001`, `0x004bd3a7` | `sub_4BC090 -> sub_4C0710` | Compat sprite/blit callback blend paths. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - [UID:00016K] target page already records exact range, RGB555 masks, 0..32 behavior, no callees/global state, thirteen callers, and SoftwareBlend16 ownership.
  - [UID:0000TZ] by-item mirror records the same behavior and the saved-label history.
  - [UID:0000NT] inventories this helper as a single-pixel RGB555 weighted blend helper and separates stateless helper ownership from callback-family ownership.
  - [UID:00016J] explicitly says the callback family calls lower-level color/blit math such as [UID:00016K] and that this math should remain in SoftwareBlend16 or a sibling render blitter source.
- Existing docs that are stale, incomplete, or contradicted:
  - [UID:00016K], [UID:0000TZ], and [UID:00016M] still mention `95/95` or final-name/signature blockers as blank-C++ reasons. That rationale is stale for scalar one-block helpers under the current C++ gate.
  - [UID:0000TZ] says runtime activation remains unresolved; that remains a score cap for the broader compatibility renderer but not a blocker to this helper's standalone formal C++.
- Generated/coverage report state:
  - `auto-generated/NexusTK/render/SoftwareBlend16.cpp` currently contains [UID:00016K] as an empty-emitter marker at lines 255-256.
  - `auto-generated/-ag-coverage-report-by-memory.md` row for [UID:00016K] says `emits_code:false`, reconstructable, `90%`, very-strong, updated `2026-06-29 15:40:04`.
  - `auto-generated/-ag-research-tracker.md` row for [UID:00016K] shows `90/92`, true, report count `0`, matching this direct report-only assignment.

## Ranked Ownership Analysis

### 1. [UID:0000NT] SoftwareBlend16
- Evidence for: current owner/emitter metadata; SoftwareBlend16 inventory includes `BlendRgb555_4C0710`; helper is stateless pixel math; no receiver/state/global use; support docs place RGB555/RGB565 blend primitives in the same render source family; generated route is valid.
- Evidence against: all direct callers are compatibility callback bodies, and exact original filename may have been `Blend16.cpp`, `SoftwareBlend16.cpp`, or part of a broader blitter source.
- Decision: accepted. Keep [UID:0000NT] as direct owner/emitter; filename uncertainty is already represented by parent `86/88` and target score cap.

### 2. [UID:00016J] SoftwareRenderCompatCallbacks / Surface callback family
- Evidence for: all 13 direct code xrefs originate inside three compatibility callback functions.
- Evidence against: [UID:00016J] is a non-emitting aggregate; exact callback children own dispatch/control bodies, while [UID:00016K] has no callback-table slot, no receiver fields, and no Surface/GrafPort state access. It is a called math primitive.
- Decision: rejected as direct owner. Preserve as caller/consumer context.

### 3. New standalone RGB555 helper file or no-owner/non-emitting
- Evidence for: exact original file name is unknown and current MCP lacks an original symbol.
- Evidence against: SoftwareBlend16 already serves as the coherent source root for RGB555/RGB565 stateless helper math and clears the parent gate; generated route is valid.
- Decision: rejected. No new source file and no no-owner/non-emitting classification are needed.

## Source Placement
- Recommended source file/class/global/module placement: `NexusTK/render/SoftwareBlend16.cpp` under [UID:0000NT].
- Why this placement fits source-tree and subsystem context: the function is a pure RGB555 color arithmetic helper used by software render callbacks and grouped with RGB555/RGB565 span, block, pixel, and pair helpers.
- Rejected placements and why: Surface/callback ownership is consumer-side; Ranking ownership is a generated callsite artifact; a standalone file would duplicate the existing SoftwareBlend16 grouping.
- Remaining placement uncertainty: exact original file basename remains unknown, but current project owner [UID:0000NT] is the correct reconstruction route.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: modeled function `0x004c0710-0x004c076d`; preceding `0x004c0704-0x004c0710` and following `0x004c076d-0x004c0770` are `0xcc` padding; next function starts at `0x004c0770`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none.
- Padding/table/data/code distinctions: preceding padding follows the final compat callback jump-table/padding region; following padding separates this helper from RGB565 callback family. Neither belongs to [UID:00016K].
- Parent/container impact: keep [UID:00016K] as an exact leaf helper with `Nested:-4`; no aggregate or container reclassification.

## Negative Evidence Summary
- No original symbol proof for `BlendRgb555`; use the name as inferred/descriptive.
- Direct calls from compat callback functions prove consumer use but not callback ownership.
- No MMX/intrinsic, constants-table, scratch-global, child-helper, or neighboring-declaration dependency exists for this scalar helper.
- No score raise is recommended because original source spelling and exact project typedef/header placement remain inferred.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments:
  - Function name: `BlendRgb555`.
  - Signature: `unsigned short __cdecl BlendRgb555(unsigned short firstPixel, unsigned short secondPixel, unsigned char firstWeight32)`.
  - Comment, if an implementation callback chooses to document it: "Returns the RGB555 blend of firstPixel weighted by firstWeight32/32 and secondPixel weighted by the inverse."
- Evidence for each proposed name/type/comment: names match current docs and SoftwareBlend16 inventory; `unsigned short` matches RGB555 pixel storage and caller stores; `unsigned char` matches the byte weight load and inverse-byte calculation; `__cdecl` matches the prototype and stack arguments.
- Items intentionally left unchanged and why: no IDA DB rename/type/comment is requested in report-only mode; current MCP does not show an active `BlendRgb555` symbol.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` block insertion text for [UID:00016K]:

```cpp
unsigned short __cdecl BlendRgb555(
    unsigned short firstPixel,
    unsigned short secondPixel,
    unsigned char firstWeight32)
{
    const unsigned int firstWeight = firstWeight32;
    const unsigned int secondWeight = static_cast<unsigned char>(32 - firstWeight32);

    const unsigned int green =
        (firstWeight * (firstPixel & 0x03e0) +
         secondWeight * (secondPixel & 0x03e0)) >> 5;
    const unsigned int redBlue =
        (firstWeight * (firstPixel & 0x7c1f) +
         secondWeight * (secondPixel & 0x7c1f)) >> 5;

    return static_cast<unsigned short>((redBlue & 0x7c1f) | (green & 0x03e0));
}
```

- Reason it preserves exact original behavior: the code uses the same 0..32 byte weight, byte-wrapped inverse weight, RGB555 green and red/blue lane masks, shift-by-five normalization, and final lane recombination confirmed by decompile/disassembly.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: it is a small free helper in a render math module, using built-in VC-era scalar types and direct arithmetic instead of decompiler temporaries or modern abstractions.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `BlendRgb555`, `firstPixel`, `secondPixel`, `firstWeight32`, `firstWeight`, `secondWeight`, `green`, and `redBlue` replace `sub_4C0710`, `a1`, `a2`, `a3`, and register-derived names.
- Naming/coding style convention used and evidence for consistency: SoftwareBlend16 docs use descriptive `BlendRgb555`, `BlendRgb565Pixel`, `AlphaBlendSpan16`, and RGB lane terminology; accepted UID0000YE C++ uses `unsigned short` rather than `uint16_t`.
- Reason code should remain blank, if applicable: not applicable. The code should not remain blank.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes recommended:
  - Populate [UID:00016K] formal C++ with the block above.
  - Replace stale old-gate/final-name blocker wording in [UID:00016K] and [UID:0000TZ].
  - Add a SoftwareBlend16 note that scalar single-pixel helpers such as [UID:00016K] can emit ordinary C++ now, independent of the MMX block-helper source-form policy.
  - Preserve compatibility callback pages as consumer context only.
- Exact parent assignments recommended: keep [UID:0000NT] owner/emitter.
- Exact items left no-owner/non-emitting and why: none for this target.
- Exact future work outside this assignment scope: sibling empty emitters [UID:00016M] `BlendRgb565Pixel` and [UID:00016N] `BlendRgb565Pair` likely need similar scalar/pair source-quality passes; they are not prerequisites for [UID:00016K].

## Recommended Target Doc Changes
- Target path: `by-memory/0x004c0710-0x004c076d.BlendRgb555.md`
- Exact report facts to incorporate:
  - Live MCP session `dad3692b` reconfirmed exact function, 13 call sites, no callees, no strings/global state, scalar formula, return-value use, and boundary padding.
  - The target is eligible for formal first-draft C++ now.
  - Source-facing name/signature remain inferred/descriptive but are strong enough for first-draft insertion.
  - `Nested:-4` remains correct as a coverage-display outdent from the compat callback aggregate.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Keep `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, and `Nested:-4`.
  - Replace blank `RECONSTRUCTION_CPP CODE` with the exact formal code block above.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Historical old `95/95` final-code wording should be replaced as stale.
  - Preserve that exact original spelling is not proven.
  - Preserve rejected callback/Surface/Ranking ownership and caller return-value use.

## Recommended Support Doc Changes
- Support path: `by-item/BlendRgb555_004C0710.md`
  - Exact facts to incorporate: by-item mirror should stop saying final C++ remains blank because final name/signature/source context are not source-quality. It should mirror [UID:00016K]'s first-draft readiness and the fact that the by-memory page carries the formal C++ body.
  - Metadata/link/score/coverage/source-placement changes: no score/owner/emitter change required unless the supervisor also chooses to score by-item C++ readiness. Preferred implementation is target by-memory formal C++ only to avoid duplicate generated function bodies.
- Support path: `by-file/SoftwareBlend16.md`
  - Exact facts to incorporate: add a short note that [UID:00016K] is a scalar RGB555 helper ready for ordinary C++ emission; this does not affect MMX source-form policy for block helpers.
  - Metadata/link/score/coverage/source-placement changes: no metadata or score change required.
- Support path: `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`
  - Exact facts to incorporate: no edit required if supervisor agrees current text already says [UID:00016K] is lower-level color/blit math in SoftwareBlend16, not callback ownership. Optional sync only if supervisor wants an explicit [UID:00016K] C++ readiness note.
  - Metadata/link/score/coverage/source-placement changes: none.
- Support path: `auto-generated/NexusTK/render/SoftwareBlend16.cpp`
  - Do not edit manually. Validator/autogen should refresh it after target validation.

## Score And Metadata Recommendation
- Current score/metadata: `90/92`, owner/emitter [UID:0000NT], reconstructable true, `Nested:-4`, blank C++.
- Recommended score/metadata: keep `90/92`, owner/emitter [UID:0000NT], reconstructable true, `Nested:-4`; populate formal C++.
- Score rationale and reason not higher/lower:
  - Not higher: exact original symbol spelling, exact public/static linkage, and final source header/typedef placement remain inferred.
  - Not lower: current MCP proves exact range, callers, no callees, no globals, scalar formula, padding, and return use; current docs prove source ownership and emitter route.
- Score-improvement attempt:
  - Final source spelling blocker: resolved enough for inferred first-draft name; no original symbol found, so no score raise.
  - Signature/type blocker: resolved with `unsigned short`, `unsigned char`, and `__cdecl`; no project typedef is proven, so built-in VC-era types are preferred.
  - Return contract blocker: resolved as returning RGB555 pixel; caller decompilation stores result back to destination.
  - Source-form blocker: resolved as ordinary scalar C++; MMX family policy is not applicable.
  - Nested blocker: resolved by generated coverage display; keep `Nested:-4`.
- Metadata fields to change or leave unchanged: leave all metadata unchanged except formal C++ content.

## Open Questions With Attempted Resolution
- Open question: exact original function spelling.
  - Evidence checked: current MCP `lookup_funcs` for `BlendRgb555` and `BlendRgb555_4C0710`, current docs, by-item mirror, SoftwareBlend16 inventory, old A/C notes.
  - Best supported resolution: `BlendRgb555` is inferred/descriptive but project-consistent and strong enough for first-draft formal code.
- Open question: exact helper linkage/header placement.
  - Evidence checked: caller set spans callback functions, helper is emitted under SoftwareBlend16, no current symbol found.
  - Best supported resolution: use a non-static `__cdecl` free helper body in `SoftwareBlend16.cpp`; header/declaration placement remains a broader source-tree integration detail and does not block by-memory formal code.
- Open question: whether to use `unsigned short`, `uint16_t`, or project typedef.
  - Evidence checked: sibling accepted C++ and current docs; no project typedef proof for RGB555 pixels was found in scope.
  - Best supported resolution: use `unsigned short` for source-facing first draft.
- Questions remaining unresolved: exact original basename/header and symbol spelling remain unresolved; impact is a score cap only, not an owner/emitter/C++ blocker.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. Do not manually edit `auto-generated/-ag-*` reports. No manual `-coverage-report.md` row is required by this report. Validator/autogen refresh should update generated empty-emitter state after target formal C++ insertion.

## Follow-Up Actions
- Supervisor actions: validate this report and checklist; if accepted, send B002 an implementation callback for [UID:00016K], [UID:0000TZ], and [UID:0000NT] with optional check-only handling for [UID:00016J].
- A-agent actions: none required.
- B002 future research actions: after callback, run scoped validators and verify generated `SoftwareBlend16.cpp` contains [UID:00016K] source while no duplicate by-item body is emitted.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for keeping `90/92`.
- Remaining uncertainty: exact original symbol spelling and public/static/header placement remain inferred.

## Validator Results
- Commands run during implementation callback:
  - `python .\tools\validator.py --mode file --file by-memory\0x004c0710-0x004c076d.BlendRgb555.md --apply --queue-timeout 240`
    - Exit code: `0`
    - `command_id: 000000000990`
    - `command_timestamp: 2026-06-29T17:55:24-04:00`
    - `ok: 1`
    - Notes: validator inserted missing UID link labels for [UID:0000NT] and [UID:00016J]; generated refresh was deferred with the same command metadata.
  - `python .\tools\validator.py --mode file --file by-item\BlendRgb555_004C0710.md --apply --queue-timeout 240`
    - Exit code: `0`
    - `command_id: 000000000991`
    - `command_timestamp: 2026-06-29T17:55:30-04:00`
    - `ok: 1`
    - Notes: validator inserted missing UID link labels for [UID:00016K]; generated refresh was deferred with the same command metadata.
  - `python .\tools\validator.py --mode file --file by-file\SoftwareBlend16.md --apply --queue-timeout 240`
    - Exit code: `0`
    - `command_id: 000000000992`
    - `command_timestamp: 2026-06-29T17:55:43-04:00`
    - `ok: 1`
    - Notes: known unrelated `missing_ref_uid 0003ZP` warning remains; validator inserted a missing UID link label for [UID:00016K].
- Generated freshness:
  - `auto-generated/NexusTK/render/SoftwareBlend16.cpp` header is `validator-command-id: 000000000992` and `validator-refreshed-at: 2026-06-29T17:55:43-04:00`, equal to the final by-file validator command.
  - UID00016K now appears with `unsigned short __cdecl BlendRgb555(...)`; no UID00016K empty emitter marker remains. The by-item mirror [UID:0000TZ] still has an empty marker by design because the formal body lives in the canonical by-memory target.
  - No `--wait-generated` rerun was required because generated output caught up to command `000000000992`.
  - [UID:00016J] compat callback support page was checked and not edited; its existing consumer/lower-level-helper wording is sufficient, so its validator was not run.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B002/research/00016K-BlendRgb555-empty-emitter-source-quality.md`.
- Modified during implementation callback:
  - `by-memory/0x004c0710-0x004c076d.BlendRgb555.md`
  - `by-item/BlendRgb555_004C0710.md`
  - `by-file/SoftwareBlend16.md`
  - `tools/leaser/Agents/Agent-B002/research/00016K-BlendRgb555-empty-emitter-source-quality.md`
- Validator-refreshed/generated side effects observed:
  - `auto-generated/NexusTK/render/SoftwareBlend16.cpp` refreshed by validator command `000000000992`.
  - `project-level/-auto-completion-stats.md` projected path completion section was updated by validator.
  - Validator state files reported by validator were updated by the tool; no manual tool-state edits were made.
- Renamed: none.
- Leases: took short B002 leases for `by-memory/0x004c0710-0x004c076d.BlendRgb555.md`, `by-item/BlendRgb555_004C0710.md`, and `by-file/SoftwareBlend16.md`; released all three immediately after the edit/validator/generated-check batch. `current_leases.md` then reported no active leases.
- Report execution: leave blank during the B-agent pass. The supervisor runs `tools/validator.py execute_report ... --apply` after verification.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: current `goal.md` converted this to accepted implementation callback.
- [x] Target/support docs to update:
  - `by-memory/0x004c0710-0x004c076d.BlendRgb555.md`: insert formal C++ block; replace stale old-gate C++ blocker; add `dad3692b` evidence, return-contract proof, first-draft readiness rationale, and `Nested:-4` rationale.
  - `by-item/BlendRgb555_004C0710.md`: synchronize final-C++ readiness wording without duplicating generated function code unless supervisor explicitly wants by-item code.
  - `by-file/SoftwareBlend16.md`: add a short scalar-helper note distinguishing [UID:00016K] ordinary C++ readiness from the still-separate MMX source-form policy.
  - `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`: check whether existing lower-level-helper consumer wording is already sufficient; edit only if supervisor wants explicit UID00016K readiness sync.
- [x] Current target state and actual evidence checked recorded: target/support docs now record [UID:00016K] `90/92`, owner/emitter [UID:0000NT], `Nested:-4`, accepted MCP session `dad3692b` evidence, generated freshness, support-doc state, and stale blocker replacement.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger C1-C9 above now has callback verification proof.
- [x] Metadata/score changes to apply: no score, owner, emitter, reconstructable, split, rename, or nesting metadata change; formal C++ changes only. Confirmed by target validator `000000000990`.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: old final-code/name/signature blockers replaced in target and by-item; exact original symbol remains score cap only.
- [x] Owner/emitter/reconstructable changes to apply: none; kept [UID:0000NT] / [UID:0000NT] / `TRUE`.
- [x] Split/rename/new-child changes to apply: none; no split, rename, or new child files created.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: source placement retained; no IDA edits made; boundary/padding facts preserved in target.
- [x] First-draft C++ or no-code proof to apply: exact formal `BlendRgb555` C++ block applied to [UID:00016K].
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable; inline C++ body is used.
- [x] Exact target/support doc facts to incorporate at report-level detail: caller set, scalar RGB555 formula, return-use decision, inferred name/prototype caveat, `Nested:-4` rationale, generated refresh expectation, and rejected ownership alternatives were incorporated.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old `95/95` blocker historicalized as stale; exact-name uncertainty and rejected callback/Surface/Ranking ownership preserved.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: no Wave2/Wave3 evidence used as authority; no doc change needed.
- [x] Open questions to close or document as evidence-backed unresolved: exact original spelling and header/static linkage are documented as score caps only in target and by-item.
- [x] Validators to run after accepted implementation:
  - `python .\tools\validator.py --mode file --file by-memory\0x004c0710-0x004c076d.BlendRgb555.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-item\BlendRgb555_004C0710.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file\SoftwareBlend16.md --apply --queue-timeout 240`
  - If [UID:00016J] is edited: `python .\tools\validator.py --mode file --file by-memory\0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md --apply --queue-timeout 240`
  - Run the final target validation with `--wait-generated` if generated `SoftwareBlend16.cpp` lags; confirm [UID:00016K] has source and no UID00016K empty marker.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated source refreshed through validator command `000000000992`; no manual coverage/tracker text needed.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: `goal.md` assignment `B002-implement-00016K-BlendRgb555-empty-emitter-20260629`.
- [x] All accepted target/support doc details incorporated at report-level detail: target, by-item, and by-file edited; compat callback support page checked and left unchanged because existing consumer wording is sufficient.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C1-C9 updated above.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: metadata unchanged; no split/rename/new children; formal target C++ inserted.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: stale old-gate blocker replaced/historicalized; rejected callback/Surface/Ranking/no-owner alternatives documented.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: exact original spelling/header linkage remain unresolved score caps only.
- [x] Validators run and results recorded: commands `000000000990`, `000000000991`, and `000000000992`, all exit `0`, all `ok: 1`.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: generated `SoftwareBlend16.cpp` header equals final validator command `000000000992`; no manual tracker/coverage edit required.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00016K-BlendRgb555-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00016K-BlendRgb555-empty-emitter-source-quality.md","timestamp":"2026-06-29T17:59:09","uid":"00016K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
