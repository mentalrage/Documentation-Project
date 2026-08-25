** TARGET-REPORT-UID:0000YD **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000YD Rgb555565BlitHelpers Empty-Emitter Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: split [UID:0000YD] `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md` into exact child by-memory pages and populate each child with formal reconstruction C++ now.
- Final disposition: the current broad page is a source-family inventory/container over eleven modeled functions, not the right formal C++ emission unit.
- Required action: after supervisor acceptance, create exact child pages for the eleven functions as emitting SoftwareBlend16 helpers: wrapper/span children at `90/92`, MMX block children at `88/91`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, and the formal C++ blocks supplied in this report. Change the parent aggregate to a non-emitting container (`CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++).
- Confidence: high for split requirement, SoftwareBlend16 ownership/emitter route, function inventory, caller families, child formal C++ disposition, and parent no-code proof; medium-high for final original helper spellings because active IDA still uses `sub_` labels.

## Supporting Research

## Target

- Target UID: `0000YD`
- Target path: `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`
- Assignment: `B001-report-0000YD-Rgb555565BlitHelpers-empty-emitter-20260629`
- Queue/report row: `auto-generated/-ag-research-tracker.md` -> `Files With Empty Emitters`; `SoftwareBlend16` currently routes to `auto-generated/NexusTK/render/SoftwareBlend16.cpp`.
- Current scores and parent state: target `86/90`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, empty formal C++; parent [UID:0000NT] `SoftwareBlend16` is `86/88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
- Current generated state: `auto-generated/NexusTK/render/SoftwareBlend16.cpp` refreshed by validator command `000000000956` at `2026-06-29T17:19:48-04:00`; UID0000YD is still an `Empty Emitter Marker`. B002 has since filled UID0000YE, so the file is no longer zero-filled, but UID0000YD remains blank.

## Current Target State

- Existing metadata is internally consistent for broad ownership but not for emission shape. The page proves the helper island is SoftwareBlend16 render math, but it treats eleven separate functions as one code-emitting by-memory page.
- Existing behavior evidence is strong: current docs and live MCP agree on RGB555/RGB565 transparent-shadow, alpha-map, weighted-blend, transparent weighted-blend, and block-helper behavior.
- Existing open blocker: the page's empty formal C++ is not caused by weak ownership; it is caused by the page being too broad for the current by-memory C++ rule. `by-structure.md` says aggregate/container pages must not paste child function C++ into the parent when the child ranges are understood.
- Related docs checked: [UID:0000NT] `SoftwareBlend16`, [UID:00016J] compat callbacks, [UID:00016L] RGB565 callbacks, [UID:0002OO] `SoftwareBlend16ReadOnlyConstants`, [UID:00028W] `MmxBlendWeightScratchData`, generated memory/file coverage, generated `SoftwareBlend16.cpp`, and matching B-agent reports.

## Executive Recommendation

The target should not emit one large C++ block. It should be repaired like the already split callback aggregates: preserve UID0000YD as a non-emitting inventory/container and create exact child pages for each modeled function. Each child is reconstructable SoftwareBlend16 code, should carry `CANONICAL_OWNER:0000NT`, should emit through `EMITTER_UIDS:0000NT`, and should receive the formal child C++ supplied below. This avoids both aggregate duplication and new empty emitters.

The split plus child code is the score/C++ repair. It removes the empty-emitter marker from the broad parent while preserving exact function-level source ownership. The latest `691d4db6` MCP pass, current target docs, generated SoftwareBlend16 output, accepted UID000208/B006 and UID0000YF/B003 inline-assembly precedents, and UID00028W/B012 scratch policy are sufficient to choose source-facing names, signatures, parameter roles, local mask/weight variables, and formal first-draft C++ for all eleven children.

## Supervisor Active Recheck

- Triggering instruction: Agent-B001 current assignment asks for a report-only source-quality pass on UID0000YD and specifically asks whether the broad helper island should emit directly, split first, use covered-by/no-code markers, or stay blank.
- Split repair required before final source: yes. Current MCP shows eleven separate IDA functions in the range, including six externally consumed interface helpers and five internal block helpers.
- Exact children in scope: no children currently exist for the exact functions inside UID0000YD. The report now provides an exact child inventory, per-child score/emitter/formal-C++ disposition, and implementation checklist for the split.

## Inference Research Guidance Check

- IDA fact: current MCP session `691d4db6` is live and reports the target range as eleven modeled functions plus successor padding before `0x00460500`.
- Documentation evidence: current by-memory and by-file docs already identify SoftwareBlend16 ownership and callback consumers.
- Inference: the source-facing helper names remain descriptive rather than original-symbol proof, but they match behavior, caller family, pixel format, and existing SoftwareBlend16 naming.
- Existing uncertain assumptions rechecked: old wording that the island can be one code-emitting page is now rejected under current by-structure C++ rules. Older B/C reports were used only as leads.
- Wave2/Wave3 stale material: generated/simroot names and old missing-ref names were treated as leads only; no Wave2/Wave3 workflow was used as authority.

## Heuristic / Inference Reanalysis And Validation

- Empty-emitter cause: not weak parentage. The target clears the numerical/emitter gate, but the page overlaps eleven distinct functions. Direct parent C++ would duplicate child bodies once the required child pages exist.
- Source placement: SoftwareBlend16 remains the best owner. The helpers are stateless pixel/span/block math, use SoftwareBlend16 constants/scratch, and are called by software render callback bodies.
- Active names: current MCP `entity_query` over `0x0045f900-0x00460510` finds only active `sub_` function names and no scoped `Rgb`, `Blend`, `Alpha`, or `SoftwareBlend` names. Proposed names are descriptive/inferred, not original-proof.
- Source form: the block helpers compile to MSVC-era MMX shape (`pushaw`/`popaw`, `emms`, `movq`, `pmullw`, `pcmpeqw`, qword constants/scratch). The current accepted SoftwareBlend16 generated output proves that target-local masks and local weight vectors are acceptable for this family. For UID0000YD, the safest formal first-draft C++ is source-level four-pixel loop code that preserves the exact row stepping, weights, masks, transparent skips, sentinel handling, and in-place writes without re-emitting binary scratch globals or Hex-Rays temporaries. This resolves the source-form blocker directly.
- Pixel behavior: scalar wrappers and block helpers agree with existing docs: RGB555 masks `0x7c1f`/`0x03e0`, RGB555 half-mask `0x3def`/block qword `0x7bde...`, RGB555 carry `0x0421`, RGB565 shadow mask `0x7bef`, RGB565 alpha-map masks `0xf81f`/`0x07e0`, alpha weights in `0..32`, and special source sentinel `1` for transparent-shadow half-bright writes.
- Rejected alternative: direct parent emission. Rejected because by-memory C++ for a broad aggregate would contain multiple child function bodies and would become overlapping output once child pages are created.
- Rejected alternative: no-owner as unresolved. Rejected because current owner evidence is strong; the exact children should be SoftwareBlend16-owned emitting pages with `EMITTER_UIDS:0000NT` and the formal C++ supplied by this report.
- Rejected alternative: static third-party import. Rejected because these functions are NexusTK software-render helper code with no vetted staged third-party source under `source-3/third_party_embeds/...`.

## Evidence Standards Used

Evidence types used: current IDA MCP `idb_list`, `server_health`, `tools/list`, `lookup_funcs`, `callees`, `xref_query`, `decompile`, `disasm`, `get_bytes`, `entity_query`, and `make_signature_for_range`; current by-* docs; generated coverage and generated C++; executed and active B reports; callback/support docs. The evidence is strong enough for split/owner/child-code/no-parent-code because function boundaries, internal calls, external callers, scalar formulas, MMX constants/scratch, and current generated source-form precedents all agree.

## Evidence Checked

- MCP session status: `691d4db6` is present, active, worker-owned, not analyzing, backend `worker`, `server_health` status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready.
- MCP checks:
  - `lookup_funcs` for `0x0045fa00`, `0x0045faa0`, `0x0045fb80`, `0x0045fe40`, `0x0045ff60`, `0x0045fff0`, `0x00460120`, `0x00460230`, `0x004602b0`, `0x00460370`, `0x00460410`, `0x004604f4`, and `0x00460500`.
  - `callees` and `xref_query` for the eleven target starts.
  - `decompile` for all eleven target starts.
  - `disasm` for the five internal block helpers at `0x0045ff60`, `0x0045fff0`, `0x00460120`, `0x00460230`, and `0x004602b0`.
  - `get_bytes` for the qword constants at `0x00610e38`, `0x00610e40`, `0x00610e48`, `0x00610e50`, `0x00610e58`, `0x00610e60`, `0x00610e68`, `0x00610e70`, `0x00610e78`, `0x00610e80`, `0x00610e88`, and `0x00610e90`.
  - `entity_query` for functions/names from `0x0045f9e0` to `0x00460510`.
  - `make_signature_for_range` for `0x0045fa00-0x004604f4` returned a unique range signature; the full signature is not reproduced because it is long and not needed for incorporation.
- Docs/reports searched with required terms: `TARGET-REPORT-UID:0000YD`, `0000YD`, `0x0045fa00`, `Rgb555565BlitHelpers`, `SoftwareBlend16`, `Rgb555`, `Rgb565`, `BlendRgb555`, `AlphaBlendSpan16`, `BlitTransparentShadow555`, `ApplyAlphaMap555`, `BlendRgb555Span`, `SoftwareRenderCompat`, `SoftwareRenderRgb565`, `BlitTransparentShadow`, and `ApplyAlphaMap`.
- Docs read: target by-memory page, [UID:0000NT] `SoftwareBlend16`, [UID:00016J] `SoftwareRenderCompatCallbacks`, [UID:00016L] `SoftwareRenderRgb565Callbacks`, [UID:0002OO], [UID:00028W], generated `-ag-research-tracker.md`, generated memory coverage rows, generated `auto-generated/NexusTK/render/SoftwareBlend16.cpp`, B002 UID0000YE report as sibling context, B003 UID0000YF report as sibling context, and executed B001 SoftwareBlend16 reports for UID000206/0000YG/000209+00020A+00020C+00020D+00020E where matching.
- Negative checks: active MCP name search found no current source-facing labels in the scoped target range; no IDA function starts exist at `0x004604f4`; `0x00460500` is the next function after target; no third-party staged source applies; callback aggregate pages are consumers/context, not direct owners.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0000YD should become a non-emitting aggregate/container after child split, not a direct C++ emitter. | high | by-structure C++ rule, MCP eleven-function inventory, current empty marker | Target metadata/status/reconstruction notes | incorporate | applied 2026-06-29: parent now `90/92`, owner none, non-reconstructable, blank emitter/C++, `Nested:11` |
| C2 | Eleven exact child pages should be created for the modeled functions in `0x0045fa00-0x004604f4`. | high | `lookup_funcs`, `callees`, `xref_query`, `entity_query` | Target split status and new child docs | incorporate | applied 2026-06-29: validator assigned UIDs `0004BB`-`0004BL` |
| C3 | Every child belongs to and should emit through [UID:0000NT] `SoftwareBlend16` as stateless RGB555/RGB565 render math. | high | parent docs, callback callers, constants/scratch docs, MCP callees/callers, generated SoftwareBlend16 precedent, supervisor revision | Child metadata, SoftwareBlend16 proposed contents | incorporate | applied 2026-06-29: all child metadata uses owner/emitter `0000NT`; SoftwareBlend16 lists exact children |
| C4 | `sub_45FA00`, `sub_45FB80`, and `sub_45FE40` are called by compat sprite blit `sub_4BC090`; `sub_45FAA0` by compat alpha lookup `sub_4BDF40`; `sub_460370` by RGB565 sprite blit `sub_4C0F80`; `sub_460410` by RGB565 alpha lookup `sub_4C3CF0`. | high | MCP `xref_query` callers | Target evidence, child evidence | incorporate | applied 2026-06-29: preserved on parent and child evidence sections |
| C5 | Internal helper calls inside the page are `0x45fa00 -> 0x45ff60`, `0x45faa0 -> 0x4602b0`, `0x45fb80 -> 0x460230/0x460120`, and `0x45fe40 -> 0x45fff0`; RGB565 wrappers call siblings `0x460940` and `0x460c90` outside this page. | high | MCP `callees`, `decompile`, and `xref_query` | Target function inventory, child docs | incorporate | applied 2026-06-29: parent range table and child formal C++ preserve calls/prototypes |
| C6 | Current active IDA names remain `sub_` labels; source-facing names are descriptive/inferred. | high | MCP `lookup_funcs`, `entity_query` names query | Target/source-quality notes, child docs | incorporate | applied 2026-06-29: caveat retained in parent and child evidence |
| C7 | Binary block helpers use MSVC x86 MMX form with `pushaw`/`popaw`, `emms`, qword masks, and weight scratch; formal source should preserve behavior with target-local masks/weights and no standalone scratch globals. | high | MCP `disasm`/`get_bytes`, [UID:0002OO], [UID:00028W], generated UID000208/UID0000YF precedents | Child docs, SoftwareBlend16 source-form policy | incorporate | applied 2026-06-29: child C++ uses local masks/weights; support docs updated to exact child UIDs |
| C8 | Static third-party import is not applicable. | high | no staged source/provenance; behavior is local render math | Target first-draft C++/import section | not-applicable | applied 2026-06-29: no import directive used |
| C9 | All eleven new child pages should be emitting SoftwareBlend16 children with formal C++: wrapper/span children `90/92`, MMX block children `88/91`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000NT`, `EMITTER_UIDS:0000NT`. | high | supervisor revision, by-structure code gate, active MCP source-shape evidence, accepted B003/B006 inline-asm generated output | Child metadata, child C++ blocks, checklist | incorporate | applied 2026-06-29: UIDs `0004BB`-`0004BL` validated `ok:1` |
| C10 | `BlitTransparentShadow555` can emit formal wrapper C++ with source/destination row pointers, byte pitches, width, row count, a `BlitTransparentShadow555Blocks` prototype, block dispatch, and scalar sentinel/shadow tail. | high | MCP `decompile/disasm 0x0045fa00`, callee `0x0045ff60`, caller `0x004bc090`, RGB555 mask `0x3def` | New child doc C++ | incorporate | applied 2026-06-29: [UID:0004BB] formal C++ inserted and generated |
| C11 | `ApplyAlphaMap555` can emit formal in-place alpha-map wrapper C++ using `unsigned short* pixels`, `const unsigned char* alphaBytes`, byte pitches, width, row count, and `ApplyAlphaMap555Blocks`; the widened `unsigned int*` decompiler type is rejected because scalar code increments alpha by one byte. | high | MCP `decompile/disasm 0x0045faa0`, callee `0x004602b0`, scalar `*(unsigned __int8 *)` alpha reads | New child doc C++ | incorporate | applied 2026-06-29: [UID:0004BC] formal C++ inserted and generated |
| C12 | `BlendRgb555Span` can emit formal wrapper C++ with 50 percent and weighted paths, prototypes for `HalfBlendRgb555Blocks` and `BlendRgb555Blocks`, and scalar RGB555 tail math. | high | MCP `decompile 0x0045fb80`, callees `0x00460230`/`0x00460120`, generated UID0000YE source pattern | New child doc C++ | incorporate | applied 2026-06-29: [UID:0004BD] formal C++ inserted and generated |
| C13 | `BlendTransparentRgb555Span` can emit formal wrapper C++ with source-zero skip, prototype for `BlendTransparentRgb555Blocks`, and scalar weighted RGB555 transparent tail. | high | MCP `decompile 0x0045fe40`, callee `0x0045fff0`, caller `0x004bc090` | New child doc C++ | incorporate | applied 2026-06-29: [UID:0004BE] formal C++ inserted and generated |
| C14 | `BlitTransparentShadow555Blocks` can emit formal source-level four-pixel C++ using the same RGB555 transparent/sentinel/shadow semantics proven by MMX disassembly and the wrapper scalar tail. | high | MCP `disasm/decompile 0x0045ff60`, bytes at `0x00610e38/0x00610e40`, generated UID000208 pattern | New child doc C++ | incorporate | applied 2026-06-29: [UID:0004BF] formal C++ inserted and generated |
| C15 | `BlendTransparentRgb555Blocks` can emit formal source-level four-pixel C++ using local source/inverse weights, RGB555 masks, and source-zero preservation, matching UID00028W scratch policy without standalone scratch globals. | high | MCP `disasm/decompile 0x0045fff0`, bytes at `0x00610e48/0x00610e50`, [UID:00028W] B012 policy | New child doc C++ | incorporate | applied 2026-06-29: [UID:0004BG] formal C++ inserted and generated |
| C16 | `BlendRgb555Blocks` can emit formal source-level four-pixel C++ using local source/inverse weights and RGB555 masks, matching the wrapper tail and UID0000YF local-weight policy. | high | MCP `disasm/decompile 0x00460120`, bytes at `0x00610e58/0x00610e60`, generated UID0000YF | New child doc C++ | incorporate | applied 2026-06-29: [UID:0004BH] formal C++ inserted and generated |
| C17 | `HalfBlendRgb555Blocks` can emit formal source-level four-pixel C++ with average mask `0x3def` and carry mask `0x0421`, matching the MMX `0x7bde...` and `0x0421...` constants. | high | MCP `disasm/decompile 0x00460230`, bytes at `0x00610e68/0x00610e70` | New child doc C++ | incorporate | applied 2026-06-29: [UID:0004BI] formal C++ inserted and generated |
| C18 | `ApplyAlphaMap555Blocks` can emit formal source-level four-pixel C++ using byte alpha input and in-place RGB555 alpha-map writes, matching the wrapper scalar tail and MMX alpha-unpack path. | high | MCP `disasm/decompile 0x004602b0`, bytes at `0x00610e78/0x00610e80` | New child doc C++ | incorporate | applied 2026-06-29: [UID:0004BJ] formal C++ inserted and generated |
| C19 | `BlitTransparentShadow565` can emit formal wrapper C++ using a prototype for already-emitting [UID:000208] `BlitTransparentShadow565MmxBlocks`; this does not duplicate UID000208's body. | high | MCP `decompile 0x00460370`, callee `0x00460940`, generated UID000208 formal body | New child doc C++ | incorporate | applied 2026-06-29: [UID:0004BK] formal C++ inserted and generated |
| C20 | `ApplyAlphaMap565` can emit formal wrapper C++ using a prototype for [UID:00020A] `Rgb565AlphaMapMmxBlocks`; the wrapper code is independent of UID00020A body population. | high | MCP `decompile 0x00460410`, callee `0x00460c90`, scalar RGB565 alpha formula | New child doc C++ | incorporate | applied 2026-06-29: [UID:0004BL] formal C++ inserted and generated |

## Positive Evidence Summary

- Direct facts supporting split: current MCP reports eleven function starts in the target and `0x00460500` as the next function; the target is not one function.
- Direct facts supporting owner: callers are software render callback bodies; block helpers use SoftwareBlend16 constants/scratch; docs already scope SoftwareBlend16 to this low-level blend/math family.
- Strongest inference chain: exact helper behavior plus callback consumers plus constants/scratch ownership make the child-level SoftwareBlend16 route high-confidence, while current by-memory C++ policy makes aggregate-level output unsafe.

## IDA MCP Facts

- Session `691d4db6` function inventory:
  - `sub_45FA00` `0x0045fa00-0x0045faa0`, size `0xa0`.
  - `sub_45FAA0` `0x0045faa0-0x0045fb74`, size `0xd4`.
  - `sub_45FB80` `0x0045fb80-0x0045fd65`, size `0x1e5`.
  - `sub_45FE40` `0x0045fe40-0x0045ff5c`, size `0x11c`.
  - `sub_45FF60` `0x0045ff60-0x0045ffe9`, size `0x89`.
  - `sub_45FFF0` `0x0045fff0-0x00460111`, size `0x121`.
  - `sub_460120` `0x00460120-0x0046022f`, size `0x10f`.
  - `sub_460230` `0x00460230-0x004602a2`, size `0x72`.
  - `sub_4602B0` `0x004602b0-0x0046036b`, size `0xbb`.
  - `sub_460370` `0x00460370-0x00460410`, size `0xa0`.
  - `sub_460410` `0x00460410-0x004604f4`, size `0xe4`.
- Boundary facts: `0x004604f4` is not a function; `0x00460500` starts `sub_460500`/UID0000YE.
- Xref/caller facts:
  - `sub_45FA00`, `sub_45FB80`, `sub_45FE40` have caller `sub_4BC090`.
  - `sub_45FAA0` has caller `sub_4BDF40`.
  - `sub_460370` has caller `sub_4C0F80`.
  - `sub_460410` has caller `sub_4C3CF0`.
- Internal/sibling callee facts:
  - `sub_45FA00` calls `sub_45FF60`.
  - `sub_45FAA0` calls `sub_4602B0`.
  - `sub_45FB80` calls `sub_460230` and `sub_460120`.
  - `sub_45FE40` calls `sub_45FFF0`.
  - `sub_460370` calls sibling [UID:000208] `sub_460940`.
  - `sub_460410` calls sibling [UID:00020A] `sub_460C90`.
- MMX facts: internal block helpers contain `pushaw`/`popaw`, `emms`, and qword mask/scratch reads/writes. Examples: `sub_45FF60` reads `qword_610E38`/`qword_610E40`; `sub_45FFF0` writes/reads `qword_67A7F0`/`qword_67A7F8` and reads `qword_610E48`/`qword_610E50`; `sub_460120` uses `0x0067a800/0x0067a808` and `0x00610e58/0x00610e60`; `sub_460230` reads `0x00610e68/0x00610e70`; `sub_4602B0` reads `0x00610e78/0x00610e80`.

## Function / Child Inventory

| Range / proposed child | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0045fa00-0x0045faa0` `BlitTransparentShadow555` | [UID:0004BB] `by-memory/0x0045fa00-0x0045faa0.BlitTransparentShadow555.md` | RGB555 transparent copy/shadow wrapper and scalar tail | true | [UID:0000NT] owner/emitter | `90/92` | emitting child created; formal wrapper C++ inserted |
| `0x0045faa0-0x0045fb74` `ApplyAlphaMap555` | [UID:0004BC] `by-memory/0x0045faa0-0x0045fb74.ApplyAlphaMap555.md` | RGB555 alpha-byte map wrapper and scalar tail | true | [UID:0000NT] owner/emitter | `90/92` | emitting child created; formal wrapper C++ inserted |
| `0x0045fb80-0x0045fd65` `BlendRgb555Span` | [UID:0004BD] `by-memory/0x0045fb80-0x0045fd65.BlendRgb555Span.md` | RGB555 weighted blend wrapper, half path, scalar tails | true | [UID:0000NT] owner/emitter | `90/92` | emitting child created; formal wrapper C++ inserted |
| `0x0045fe40-0x0045ff5c` `BlendTransparentRgb555Span` | [UID:0004BE] `by-memory/0x0045fe40-0x0045ff5c.BlendTransparentRgb555Span.md` | RGB555 transparent weighted blend wrapper and scalar tail | true | [UID:0000NT] owner/emitter | `90/92` | emitting child created; formal wrapper C++ inserted |
| `0x0045ff60-0x0045ffe9` `BlitTransparentShadow555Blocks` | [UID:0004BF] `by-memory/0x0045ff60-0x0045ffe9.BlitTransparentShadow555Blocks.md` | MMX four-pixel RGB555 transparent-shadow block helper | true | [UID:0000NT] owner/emitter | `88/91` | emitting child created; formal source-level four-pixel C++ inserted |
| `0x0045fff0-0x00460111` `BlendTransparentRgb555Blocks` | [UID:0004BG] `by-memory/0x0045fff0-0x00460111.BlendTransparentRgb555Blocks.md` | MMX four-pixel transparent weighted RGB555 block helper | true | [UID:0000NT] owner/emitter | `88/91` | emitting child created; formal source-level four-pixel C++ inserted |
| `0x00460120-0x0046022f` `BlendRgb555Blocks` | [UID:0004BH] `by-memory/0x00460120-0x0046022f.BlendRgb555Blocks.md` | MMX four-pixel weighted RGB555 block helper | true | [UID:0000NT] owner/emitter | `88/91` | emitting child created; formal source-level four-pixel C++ inserted |
| `0x00460230-0x004602a2` `HalfBlendRgb555Blocks` | [UID:0004BI] `by-memory/0x00460230-0x004602a2.HalfBlendRgb555Blocks.md` | MMX four-pixel 50 percent RGB555 block helper | true | [UID:0000NT] owner/emitter | `88/91` | emitting child created; formal source-level four-pixel C++ inserted |
| `0x004602b0-0x0046036b` `ApplyAlphaMap555Blocks` | [UID:0004BJ] `by-memory/0x004602b0-0x0046036b.ApplyAlphaMap555Blocks.md` | MMX four-pixel RGB555 alpha-byte map helper | true | [UID:0000NT] owner/emitter | `88/91` | emitting child created; formal source-level four-pixel C++ inserted |
| `0x00460370-0x00460410` `BlitTransparentShadow565` | [UID:0004BK] `by-memory/0x00460370-0x00460410.BlitTransparentShadow565.md` | RGB565 transparent copy/shadow wrapper and scalar tail | true | [UID:0000NT] owner/emitter | `90/92` | emitting child created; formal wrapper C++ inserted |
| `0x00460410-0x004604f4` `ApplyAlphaMap565` | [UID:0004BL] `by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md` | RGB565 alpha-byte map wrapper and scalar tail | true | [UID:0000NT] owner/emitter | `90/92` | emitting child created; formal wrapper C++ inserted |
| `0x0045fa00-0x004604f4` UID0000YD parent | [UID:0000YD] existing target | split inventory/container after children exist | false | none | applied `90/92` | converted parent |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0045fa00` | caller `sub_4BC090` at `0x004bcf48`; callee `sub_45FF60` | compat sprite blit uses RGB555 transparent-shadow helper. |
| `0x0045faa0` | caller `sub_4BDF40` at `0x004be004`; callee `sub_4602B0` | compat alpha/color-LUT callback uses RGB555 alpha-map helper. |
| `0x0045fb80` | caller `sub_4BC090` at `0x004bcfad`; callees `sub_460230`, `sub_460120` | compat sprite blit uses RGB555 weighted blend span. |
| `0x0045fe40` | caller `sub_4BC090` at `0x004bd359`; callee `sub_45FFF0` | compat sprite blit uses transparent weighted RGB555 span. |
| `0x00460370` | caller `sub_4C0F80` at `0x004c2a54`; callee `sub_460940` | RGB565 sprite callback uses RGB565 transparent-shadow helper and sibling MMX block helper. |
| `0x00460410` | caller `sub_4C3CF0` at `0x004c3db4`; callee `sub_460C90` | RGB565 alpha lookup callback uses RGB565 alpha-map helper and sibling MMX block helper. |

## Documentation Evidence And IDA Status

- Existing target doc already records correct broad behavior and ownership, but should be updated from a direct reconstruction page to a split aggregate.
- [UID:0000NT] `SoftwareBlend16` already owns this family in its proposed contents and source-form policy. It should be updated after split to list/link the exact child pages instead of one broad UID0000YD row.
- [UID:00016J] and [UID:00016L] show the same aggregate pattern in the render callback families: broad pages are non-emitting inventories once exact child pages exist.
- Generated memory coverage currently shows UID0000YD `emits_code:false` with the broad item summary. After split, generated coverage should show the parent as not reconstructable/non-emitting and the child pages as reconstructable SoftwareBlend16 emitters with the formal C++ supplied in this report.

## Ranked Ownership Analysis

### 1. [UID:0000NT] SoftwareBlend16

- Evidence for: contiguous low-level 16-bit blend helper cluster; callbacks consume these helpers as leaf math; constants [UID:0002OO] and scratch [UID:00028W] are already attached to SoftwareBlend16; no class/object state is accessed; parent has a valid generated file route.
- Evidence against: final original filename is inferred, not proven. Some callers are Surface callback bodies, but they are consumers, not source owners for stateless helper math.
- Decision: use [UID:0000NT] as `CANONICAL_OWNER` and `EMITTER_UIDS:0000NT` for every exact child page.

### 2. [UID:0000OC] Surface / callback family docs

- Evidence for: direct external callers are software render callbacks and Surface owns callback-table dispatch.
- Evidence against: the target helpers are ordinary callees, not callback-table targets; they do not read Surface/GrafPort fields; callback aggregate docs explicitly keep helper math in SoftwareBlend16.
- Decision: support context only, rejected as direct owner for child functions.

### 3. RankingDialog / RankingEventListPane generated owner

- Evidence for: older generated output polluted render callback bodies into RankingEventListPane.
- Evidence against: no target helper uses Ranking UI state; callback docs explicitly reject Ranking owner for render infrastructure; current target calls are render callback paths.
- Decision: rejected.

### 4. No owner / non-emitting

- Evidence for: active helper names remain synthetic and the broad parent is an empty emitter.
- Evidence against: ownership and behavior evidence are strong; only the overlapping aggregate should become non-emitting.
- Decision: rejected for children; accepted only for the parent aggregate after split.

## Source Placement

- Recommended placement: exact children are documented as SoftwareBlend16-owned render helpers under the `NexusTK/render/SoftwareBlend16.cpp` source family and should route to generated output through `EMITTER_UIDS:0000NT`.
- Source-shape rationale: plausible mid-2000s source would keep static/free low-level pixel helpers in one render/blend source, with scalar span wrappers calling local block helpers. Current B002/B003/B006/B012 sibling work supports ordinary C++ wrappers, target-local constants, local weight vectors, and behavior-preserving first-draft source for this helper family.
- Rejected placements: Surface callback docs own callback bodies, not stateless helper callees; Ranking UI is generated pollution; third-party import has no source provenance.
- Remaining uncertainty: exact original file name and exact original helper spellings remain unresolved. They lower confidence from perfect scores but do not block formal child C++ because current function behavior, signatures, row stepping, masks, and helper relationships are directly evidenced.

## Range / Split / Padding / Reclassification Analysis

- Exact range facts: target half-open range is `0x0045fa00-0x004604f4`. MCP function sizes prove eleven child function ranges listed above.
- Parent/container impact: set UID0000YD to non-emitting container after child creation. Suggested metadata after split:
  - `COMPLETION:90`
  - `CONFIDENCE:92`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:FALSE`
  - `EMITTER_UIDS:`
  - blank formal C++ block
  - `Nested:11`
- Padding/gaps: do not create child pages for alignment gaps between modeled functions. Preserve gaps as padding/alignment in the parent and/or `by-memory/-ignored.md` if supervisor wants explicit ledger cleanup.
- Split child pages should use validator-assigned UIDs; do not invent UIDs in documentation. Use temporary path references until validator assigns real IDs.
- Child metadata for this split: wrapper/span children should be `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, blank `EMITTER_POSITION_OPTIONAL`, and the formal wrapper C++ blocks supplied in this report. Internal block-helper children should be `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, blank `EMITTER_POSITION_OPTIONAL`, and the formal four-pixel block-helper C++ blocks supplied in this report.

## Negative Evidence Summary

- No current MCP source-facing labels prove original helper names.
- No direct evidence supports Ranking ownership.
- No evidence supports a static third-party import.
- No evidence supports direct parent C++ after split: the parent would overlap child code.
- No evidence supports leaving all code blank because of unresolved names. The unresolved names affect exact spelling only; behavior, ownership, and source form are good enough for child-level reconstruction planning.

## IDA Rename / Type / Comment Recommendations

- Do not edit the IDA DB in this report-only pass.
- Source-facing names to use in docs are descriptive/inferred:
  - `BlitTransparentShadow555`, `ApplyAlphaMap555`, `BlendRgb555Span`, `BlendTransparentRgb555Span`
  - `BlitTransparentShadow555Blocks`, `BlendTransparentRgb555Blocks`, `BlendRgb555Blocks`, `HalfBlendRgb555Blocks`, `ApplyAlphaMap555Blocks`
  - `BlitTransparentShadow565`, `ApplyAlphaMap565`
- Suggested shared argument vocabulary for child docs: `sourcePixels`, `sourcePitchBytes`, `destinationPixels`, `destinationPitchBytes`, `alphaBytes`, `alphaPitchBytes`, `alpha32`/`sourceWeight32`, `widthPixels`, `blockCount4Pixels`, and `rowCount`.
- Active IDA label caveat: document that active MCP still reports `sub_` labels.

## First-Draft C++ Recommendation

- Eligible for draft C++: not on UID0000YD parent. The exact child pages are the eligible units after split.
- Recommended parent code: none.
- Exact no-code proof for parent: UID0000YD is an overlapping aggregate over eleven exact function bodies. Current by-structure policy says child functions must be documented on their own exact pages; parent aggregate code must not duplicate child bodies. Therefore the formal parent `RECONSTRUCTION_CPP CODE` block should remain blank and the parent should become `RECONSTRUCTABLE:FALSE` after child creation.
- Child C++ disposition for this split: every proposed child should emit now through [UID:0000NT] `SoftwareBlend16`. Wrapper/span children use ordinary source-level C++ with local prototypes for their block helpers, matching the accepted UID0000YE source style. Block-helper children use four-pixel source-level C++ loops with the exact masks, alpha weights, row stepping, transparent-source handling, and in-place writes proven by `691d4db6` MCP decompilation/disassembly. This is implementation-ready formal C++, not a placeholder.
- Third-party import directive: not applicable.

### Child Formal C++ Insertion Text

#### `BlitTransparentShadow555` `0x0045fa00-0x0045faa0`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __cdecl BlitTransparentShadow555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl BlitTransparentShadow555(
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
        BlitTransparentShadow555Blocks(
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
            unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            if (source == 1) {
                source = (destinationPixels[pixelIndex] >> 1) & 0x3def;
            }

            destinationPixels[pixelIndex] = static_cast<unsigned short>(source);
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

#### `ApplyAlphaMap555` `0x0045faa0-0x0045fb74`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __cdecl ApplyAlphaMap555Blocks(
    unsigned short* pixels,
    int pixelPitchBytes,
    const unsigned char* alphaBytes,
    int alphaPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl ApplyAlphaMap555(
    unsigned short* pixels,
    int pixelPitchBytes,
    const unsigned char* alphaBytes,
    int alphaPitchBytes,
    int widthPixels,
    int rowCount)
{
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (blockCount4Pixels > 0) {
        ApplyAlphaMap555Blocks(
            pixels,
            pixelPitchBytes,
            alphaBytes,
            alphaPitchBytes,
            blockCount4Pixels,
            rowCount);

        pixels += blockCount4Pixels * 4;
        alphaBytes += blockCount4Pixels * 4;
    }

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int pixel = pixels[pixelIndex];
            const unsigned int alpha = alphaBytes[pixelIndex];

            pixels[pixelIndex] = static_cast<unsigned short>(
                (((alpha * (pixel & 0x7c1f)) >> 5) & 0x7c1f) |
                (((alpha * (pixel & 0x03e0)) >> 5) & 0x03e0));
        }

        pixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(pixels) + pixelPitchBytes);
        alphaBytes += alphaPitchBytes;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

#### `BlendRgb555Span` `0x0045fb80-0x0045fd65`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __cdecl BlendRgb555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount);

static void __cdecl HalfBlendRgb555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl BlendRgb555Span(
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

    if (alpha == 16) {
        if (blockCount4Pixels > 0) {
            HalfBlendRgb555Blocks(
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
                    ((source >> 1) & 0x3def) +
                    ((destination >> 1) & 0x3def) +
                    (source & destination & 0x0421));
            }

            sourcePixels = reinterpret_cast<const unsigned short*>(
                reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
            destinationPixels = reinterpret_cast<unsigned short*>(
                reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
        }

        return;
    }

    if (blockCount4Pixels > 0) {
        BlendRgb555Blocks(
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
            const unsigned int destination = destinationPixels[pixelIndex];
            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (((sourceWeight32 * (source & 0x7c1f) +
                   destinationWeight32 * (destination & 0x7c1f)) >> 5) & 0x7c1f) |
                (((sourceWeight32 * (source & 0x03e0) +
                   destinationWeight32 * (destination & 0x03e0)) >> 5) & 0x03e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

#### `BlendTransparentRgb555Span` `0x0045fe40-0x0045ff5c`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __cdecl BlendTransparentRgb555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount);

void __cdecl BlendTransparentRgb555Span(
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
        BlendTransparentRgb555Blocks(
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
            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (((sourceWeight32 * (source & 0x7c1f) +
                   destinationWeight32 * (destination & 0x7c1f)) >> 5) & 0x7c1f) |
                (((sourceWeight32 * (source & 0x03e0) +
                   destinationWeight32 * (destination & 0x03e0)) >> 5) & 0x03e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

#### `BlitTransparentShadow555Blocks` `0x0045ff60-0x0045ffe9`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __cdecl BlitTransparentShadow555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount)
{
    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            if (source == 1) {
                source = (destinationPixels[pixelIndex] >> 1) & 0x3def;
            }

            destinationPixels[pixelIndex] = static_cast<unsigned short>(source);
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

#### `BlendTransparentRgb555Blocks` `0x0045fff0-0x00460111`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __cdecl BlendTransparentRgb555Blocks(
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
            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (((sourceWeight * (source & 0x7c1f) +
                   destinationWeight * (destination & 0x7c1f)) >> 5) & 0x7c1f) |
                (((sourceWeight * (source & 0x03e0) +
                   destinationWeight * (destination & 0x03e0)) >> 5) & 0x03e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

#### `BlendRgb555Blocks` `0x00460120-0x0046022f`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __cdecl BlendRgb555Blocks(
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
            const unsigned int destination = destinationPixels[pixelIndex];
            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (((sourceWeight * (source & 0x7c1f) +
                   destinationWeight * (destination & 0x7c1f)) >> 5) & 0x7c1f) |
                (((sourceWeight * (source & 0x03e0) +
                   destinationWeight * (destination & 0x03e0)) >> 5) & 0x03e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

#### `HalfBlendRgb555Blocks` `0x00460230-0x004602a2`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __cdecl HalfBlendRgb555Blocks(
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
                ((source >> 1) & 0x3def) +
                ((destination >> 1) & 0x3def) +
                (source & destination & 0x0421));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

#### `ApplyAlphaMap555Blocks` `0x004602b0-0x0046036b`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __cdecl ApplyAlphaMap555Blocks(
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
            pixels[pixelIndex] = static_cast<unsigned short>(
                (((alpha * (pixel & 0x7c1f)) >> 5) & 0x7c1f) |
                (((alpha * (pixel & 0x03e0)) >> 5) & 0x03e0));
        }

        pixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(pixels) + pixelPitchBytes);
        alphaBytes += alphaPitchBytes;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

#### `BlitTransparentShadow565` `0x00460370-0x00460410`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __cdecl BlitTransparentShadow565MmxBlocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl BlitTransparentShadow565(
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
        BlitTransparentShadow565MmxBlocks(
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
            unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            if (source == 1) {
                source = (destinationPixels[pixelIndex] >> 1) & 0x7bef;
            }

            destinationPixels[pixelIndex] = static_cast<unsigned short>(source);
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

#### `ApplyAlphaMap565` `0x00460410-0x004604f4`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __cdecl Rgb565AlphaMapMmxBlocks(
    unsigned short* pixels,
    int pixelPitchBytes,
    const unsigned char* alphaBytes,
    int alphaPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl ApplyAlphaMap565(
    unsigned short* pixels,
    int pixelPitchBytes,
    const unsigned char* alphaBytes,
    int alphaPitchBytes,
    int widthPixels,
    int rowCount)
{
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (blockCount4Pixels > 0) {
        Rgb565AlphaMapMmxBlocks(
            pixels,
            pixelPitchBytes,
            alphaBytes,
            alphaPitchBytes,
            blockCount4Pixels,
            rowCount);

        pixels += blockCount4Pixels * 4;
        alphaBytes += blockCount4Pixels * 4;
    }

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int pixel = pixels[pixelIndex];
            const unsigned int alpha = alphaBytes[pixelIndex];
            const unsigned int redBlue = (alpha * (pixel & 0xf81f)) >> 5;
            const unsigned int green = (alpha * (pixel & 0x07e0)) >> 5;

            pixels[pixelIndex] = static_cast<unsigned short>(
                (redBlue & 0xf81f) | (green & 0x07e0));
        }

        pixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(pixels) + pixelPitchBytes);
        alphaBytes += alphaPitchBytes;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

- Convert UID0000YD from a reconstructable empty emitter to a non-emitting split inventory/container.
- Create eleven exact reconstructable SoftwareBlend16 child pages with owner/emitter [UID:0000NT], wrapper/span child metadata `90/92`, block-helper child metadata `88/91`, and the exact formal C++ blocks supplied in this report.
- Update `SoftwareBlend16.md` to replace the single broad UID0000YD inventory line with child links and to state that the former broad page is now a container while the new child pages emit through SoftwareBlend16.
- Keep constants/scratch support docs as support context; no metadata change is required there unless the supervisor wants source-form notes for the new child pages.
- Do not edit generated files or coverage reports manually. Let scoped validators and generated refresh update generated reports/output.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`
- Incorporate:
  - current `691d4db6` MCP session evidence;
  - exact eleven-function inventory with half-open ranges and active `sub_` names;
  - split-first recommendation and parent no-code proof;
  - external caller and internal/sibling callee graph;
  - parent metadata change to non-emitting aggregate after children exist;
  - warning that final helper names are descriptive/inferred, not current IDA symbols.
- Parent metadata changes after child creation:
  - `COMPLETION:90`, `CONFIDENCE:92`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:FALSE`
  - `EMITTER_UIDS:` blank
  - blank C++ block
  - `Nested:11`
- Child metadata to apply to all eleven new pages:
  - wrappers/spans: `COMPLETION:90`, `CONFIDENCE:92`
  - internal block helpers: `COMPLETION:88`, `CONFIDENCE:91`
  - `CANONICAL_OWNER:0000NT`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000NT`
  - formal C++ block from this report

## Recommended Support Doc Changes

- Support path: `by-file/SoftwareBlend16.md`
  - Replace broad UID0000YD proposed-contents wording with the eleven exact child functions once created.
  - Add note that former UID0000YD is now a non-emitting container and the child pages are SoftwareBlend16-owned emitters with formal first-draft C++ supplied by this report.
  - Route the new children into generated output with `EMITTER_UIDS:0000NT`.
- Support path: `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`
  - No metadata change required. Optional support note after split: first ten qword constants feed UID0000YD child block helpers at `0x0045ff60`, `0x0045fff0`, `0x00460120`, `0x00460230`, and `0x004602b0`.
- Support path: `by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md`
  - No metadata change required. Optional support note after split: scratch pairs `0x0067a7f0/0x0067a7f8` and `0x0067a800/0x0067a808` feed new RGB555 weighted block-helper children.
- Support paths: [UID:00016J] and [UID:00016L]
  - No required edit. They already support the consumer relationship.

## Score And Metadata Recommendation

- Current score/metadata before this recommendation: `86/90`, `CANONICAL_OWNER:0000NT`, `EMITTER_UIDS:0000NT`, reconstructable true, empty C++.
- Recommended parent score/metadata after split: `90/92`, owner none, reconstructable false, no emitters, blank C++.
- Recommended child score/metadata during split: wrapper/span children `90/92`, owner/emitter [UID:0000NT], reconstructable true, formal C++; internal block-helper children `88/91`, owner/emitter [UID:0000NT], reconstructable true, formal C++. These scores reflect evidence quality: wrappers have direct scalar decompilation and accepted dispatcher style, while block helpers have exact behavior but lower source-form confidence because their binary implementation is MMX and the formal source is a behavior-preserving four-pixel C++ reconstruction.
- Score rationale: the parent becomes a well-documented inventory/container like [UID:00016J]/[UID:00016L]. It should score higher for exact split evidence and non-emitting disposition, but not 95+ because exact original source filename/helper spellings remain inferred. Children score above the code-entry gate because each has exact range, caller/callee evidence, parameter-role inference, behavior proof, and formal C++.
- Score-improvement attempt: the named blockers were checked directly:
  - Empty emitter: resolved as structural overlap requiring split.
  - Original helper names: current IDA name query proves no active original labels; descriptive names are still strong enough for child docs.
  - Inline assembly/MMX style: resolved by choosing behavior-preserving source-level four-pixel C++ for UID0000YD block helpers, with masks/weights verified against MCP and accepted SoftwareBlend16 local-constant/scratch policy.
  - Ownership and emitter fields: owner/emitter remains [UID:0000NT] for children; parent route intentionally stays blank after split.
  - Static import: rejected.

## Open Questions With Attempted Resolution

- Exact original helper spellings: unresolved. Checked active IDA function/name entries and current docs. Best supported result is descriptive SoftwareBlend16 names; confidence impact only, not split/owner blocker.
- Direct parent C++: resolved. Parent must not emit because it is an aggregate over child functions.
- Child formal code disposition: resolved for this split as emitting child pages with exact formal C++ insertion text supplied above. The eleven scalar/MMX helpers are reconstructable and SoftwareBlend16-owned; wrappers/spans receive `90/92`, block helpers receive `88/91`, and every child receives `EMITTER_UIDS:0000NT`.
- Padding/gap details: current docs and MCP prove no additional modeled function starts in the gaps. If supervisor wants padding rows, confirm exact gap bytes during split validation and record in target or ignored ledger as appropriate.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual supervisor-owned tracker text is required for validator-owned generated reports. If the supervisor keeps a manual by-memory coverage row, the intended replacement for UID0000YD after split is:

`0x0045fa00-0x004604f4.Rgb555565BlitHelpers : not_reconstructable/container : 90 : 92 : SoftwareBlend16 RGB555/RGB565 helper island container; exact child pages carry and emit the eleven reconstructable helper functions through SoftwareBlend16 with formal C++ supplied by the B001 report.`

## Follow-Up Actions

- Supervisor action: validate this report and send an implementation callback for split creation if accepted.
- B001 callback action: create/update only the target/support docs listed in this checklist under normal leases; run scoped validators; verify generated `SoftwareBlend16.cpp` no longer has UID0000YD as an empty emitter and now contains generated code for the eleven child helpers.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for parent `90/92` after split.
- Remaining uncertainty: exact original helper spellings and exact original source filename remain inferred. This lowers confidence from perfect scores but does not block the formal C++ supplied here.

## Validator Results

- Implementation callback validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`; all listed commands exited `0` with `ok: 1`.
- `python .\tools\validator.py --mode file --file by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md --apply --queue-timeout 240`
  - `command_id: 000000001008`, `command_timestamp: 2026-06-29T18:17:18-04:00`, generated refresh deferred.
- New child validators:
  - [UID:0004BB] `by-memory/0x0045fa00-0x0045faa0.BlitTransparentShadow555.md`: `000000001009`, `2026-06-29T18:17:20-04:00`.
  - [UID:0004BC] `by-memory/0x0045faa0-0x0045fb74.ApplyAlphaMap555.md`: `000000001010`, `2026-06-29T18:17:22-04:00`.
  - [UID:0004BD] `by-memory/0x0045fb80-0x0045fd65.BlendRgb555Span.md`: `000000001011`, `2026-06-29T18:17:32-04:00`.
  - [UID:0004BE] `by-memory/0x0045fe40-0x0045ff5c.BlendTransparentRgb555Span.md`: `000000001012`, `2026-06-29T18:17:42-04:00`.
  - [UID:0004BF] `by-memory/0x0045ff60-0x0045ffe9.BlitTransparentShadow555Blocks.md`: `000000001013`, `2026-06-29T18:17:52-04:00`.
  - [UID:0004BG] `by-memory/0x0045fff0-0x00460111.BlendTransparentRgb555Blocks.md`: `000000001014`, `2026-06-29T18:18:02-04:00`.
  - [UID:0004BH] `by-memory/0x00460120-0x0046022f.BlendRgb555Blocks.md`: `000000001015`, `2026-06-29T18:18:12-04:00`.
  - [UID:0004BI] `by-memory/0x00460230-0x004602a2.HalfBlendRgb555Blocks.md`: `000000001016`, `2026-06-29T18:18:22-04:00`.
  - [UID:0004BJ] `by-memory/0x004602b0-0x0046036b.ApplyAlphaMap555Blocks.md`: `000000001017`, `2026-06-29T18:18:32-04:00`.
  - [UID:0004BK] `by-memory/0x00460370-0x00460410.BlitTransparentShadow565.md`: `000000001018`, `2026-06-29T18:18:42-04:00`.
  - [UID:0004BL] `by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md`: `000000001019`, `2026-06-29T18:18:52-04:00`.
- `python .\tools\validator.py --mode file --file by-file/SoftwareBlend16.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000001020`, `command_timestamp: 2026-06-29T18:19:02-04:00`, `generated_refresh: completed`.
- Optional support validators run because the current support docs still used broad UID0000YD for the exact child consumers:
  - `by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md`: `000000001021`, `2026-06-29T18:21:49-04:00`, `ok:1`.
  - `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`: `000000001022`, `2026-06-29T18:21:51-04:00`, `ok:1`.
  - Final wait-generated check on `by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md`: `000000001027`, `2026-06-29T18:22:30-04:00`, `generated_refresh: completed`.
  - Final stale-wording cleanup validator on `by-file/SoftwareBlend16.md`: `000000001035`, `2026-06-29T18:26:46-04:00`, `generated_refresh: completed`.
- Generated-output check:
  - `auto-generated/NexusTK/render/SoftwareBlend16.cpp` header after refresh: `validator-command-id: 000000001035`, `validator-refreshed-at: 2026-06-29T18:26:46-04:00`, `validator-refresh-source: foreground-generated-refresh`.
  - Search confirmed no `UID:0000YD ... Empty Emitter Marker`.
  - Search confirmed generated code entries for all child UIDs `0004BB` through `0004BL`.
  - Search confirmed the generated scratch comment now references [UID:0004BG] and [UID:0004BH] instead of broad UID0000YD.
- Validator side effects were validator-owned generated refreshes only: `auto-generated/-ag-*` coverage/tracker metadata, `auto-generated/NexusTK/render/SoftwareBlend16.cpp`, generated backup directories, and known unrelated `autogen_emitter_has_no_code` diagnostics for other emitting-children-only docs. No generated file was manually edited.

## Changed Files

- Created:
  - `by-memory/0x0045fa00-0x0045faa0.BlitTransparentShadow555.md` [UID:0004BB]
  - `by-memory/0x0045faa0-0x0045fb74.ApplyAlphaMap555.md` [UID:0004BC]
  - `by-memory/0x0045fb80-0x0045fd65.BlendRgb555Span.md` [UID:0004BD]
  - `by-memory/0x0045fe40-0x0045ff5c.BlendTransparentRgb555Span.md` [UID:0004BE]
  - `by-memory/0x0045ff60-0x0045ffe9.BlitTransparentShadow555Blocks.md` [UID:0004BF]
  - `by-memory/0x0045fff0-0x00460111.BlendTransparentRgb555Blocks.md` [UID:0004BG]
  - `by-memory/0x00460120-0x0046022f.BlendRgb555Blocks.md` [UID:0004BH]
  - `by-memory/0x00460230-0x004602a2.HalfBlendRgb555Blocks.md` [UID:0004BI]
  - `by-memory/0x004602b0-0x0046036b.ApplyAlphaMap555Blocks.md` [UID:0004BJ]
  - `by-memory/0x00460370-0x00460410.BlitTransparentShadow565.md` [UID:0004BK]
  - `by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md` [UID:0004BL]
- Modified:
  - `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`
  - `by-file/SoftwareBlend16.md`
  - `by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md`
  - `by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md`
  - `tools/leaser/Agents/Agent-B001/research/0000YD-Rgb555565BlitHelpers-empty-emitter-source-quality.md`
- Modified by validator only: generated coverage/tracker metadata and `auto-generated/NexusTK/render/SoftwareBlend16.cpp`.
- Renamed: none.
- Report execution: leave blank during the B-agent pass. The supervisor runs `tools/validator.py execute_report ... --apply` only after verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Accepted by supervisor and converted to implementation callback on 2026-06-29.
- [x] Target/support docs to update:
  - `by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md`
  - create `by-memory/0x0045fa00-0x0045faa0.BlitTransparentShadow555.md`
  - create `by-memory/0x0045faa0-0x0045fb74.ApplyAlphaMap555.md`
  - create `by-memory/0x0045fb80-0x0045fd65.BlendRgb555Span.md`
  - create `by-memory/0x0045fe40-0x0045ff5c.BlendTransparentRgb555Span.md`
  - create `by-memory/0x0045ff60-0x0045ffe9.BlitTransparentShadow555Blocks.md`
  - create `by-memory/0x0045fff0-0x00460111.BlendTransparentRgb555Blocks.md`
  - create `by-memory/0x00460120-0x0046022f.BlendRgb555Blocks.md`
  - create `by-memory/0x00460230-0x004602a2.HalfBlendRgb555Blocks.md`
  - create `by-memory/0x004602b0-0x0046036b.ApplyAlphaMap555Blocks.md`
  - create `by-memory/0x00460370-0x00460410.BlitTransparentShadow565.md`
  - create `by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md`
  - `by-file/SoftwareBlend16.md`
  - optional support notes only if accepted: [UID:0002OO] constants and [UID:00028W] scratch docs
- [x] Current target state and actual evidence checked recorded: incorporated `691d4db6` session status, function inventory, callers/callees, source-form facts, generated output state, and search terms in this report and by-* docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes applied: parent UID0000YD is `90/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++, `Nested:11`; child UIDs `0004BB`-`0004BL` use accepted scores, owner/emitter [UID:0000NT], and formal C++.
- [x] Score-limiting blockers researched to resolution: split/overlap, original-name caveat, MMX source form, child code disposition, and static-import rejection are recorded in target/support docs.
- [x] Ownership/emitter/reconstructable changes applied: parent non-emitting container; all exact children SoftwareBlend16-owned, reconstructable, and emitting through [UID:0000NT].
- [x] Split/rename/new-child changes applied: created eleven exact child pages with half-open ranges listed in this report; UID0000YD preserved as broad container.
- [x] Source-placement/range/padding/reclassification changes applied: parent body and SoftwareBlend16 inventory updated; gaps remain non-source alignment/padding, not child code.
- [x] First-draft C++ or no-code proof applied: parent no-code/container proof inserted; every child has formal `RECONSTRUCTION_CPP CODE`; child bodies were not pasted into the parent aggregate.
- [x] Third-party import directive applied or confirmed not applicable: no `third_party_embeds/...` path is used.
- [x] Exact target/support doc facts incorporated at report-level detail: MCP function inventory, caller/callee graph, active-name caveat, MMX constants/scratch use, generated empty-emitter state, split recommendation, and rejected alternatives are represented in target/support docs.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: old single-page emitter assumption rejected; Ranking/generator ownership rejected; no-owner/non-emitting rejected for children; direct aggregate C++ rejected; source names not original-proof.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated/simroot names treated as leads only.
- [x] Open questions closed or documented as evidence-backed unresolved: original helper spellings and exact original source filename remain confidence limitations only; they do not block the child formal C++ supplied here.
- [x] Validators run after accepted implementation:
  - `python .\tools\validator.py --mode file --file by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md --apply --queue-timeout 240`
  - one scoped validator for each newly created child page
  - `python .\tools\validator.py --mode file --file by-file/SoftwareBlend16.md --apply --queue-timeout 240`
  - scoped validators for [UID:0002OO] and [UID:00028W] only if support notes are edited
  - run or request generated refresh/autogen check so `auto-generated/NexusTK/render/SoftwareBlend16.cpp` no longer contains UID0000YD as an empty-emitter marker and contains emitted code for the eleven child helpers
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: validator-owned generated tracker/coverage refreshed through validators; no manual generated edit.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/ownership/emitter/split/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator; `SoftwareBlend16.cpp` header is `validator-command-id: 000000001035` / `2026-06-29T18:26:46-04:00`.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000YD-Rgb555565BlitHelpers-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0000YD-Rgb555565BlitHelpers-empty-emitter-source-quality.md","timestamp":"2026-06-29T18:31:17","uid":"0000YD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
