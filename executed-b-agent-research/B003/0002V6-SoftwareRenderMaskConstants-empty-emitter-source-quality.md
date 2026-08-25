** TARGET-REPORT-UID:0002V6 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# SoftwareRenderMaskConstants Empty-Emitter Source-Quality Report

## Finalized Report / Current Recommendation

The accepted ordinary-document callback is complete. B003 incorporated claims C2V6-01 through C2V6-26 into the target and eight support documents, preserved the two already-sufficient boundary documents unchanged, and ran scoped validator commands `17369` through `17377`. B003 did not manually edit coverage, generated/tracker, audit, goal, validator-owned lifecycle state, or IDA, and did not run any report lifecycle command.

[UID:0002V6] is a single 416-byte compiler-generated aligned literal pool used by five `Surface.cpp` software-render callbacks. It contains fourteen RGB555/compat blocks at `[0x0061a920,0x0061aa00)` and twelve RGB565 blocks at `[0x0061aa00,0x0061aac0)`. The source reconstruction should retain one physical by-memory page, document the two internal families, and emit no standalone array. Its source is covered by the scalar callback expressions that caused the compiler to materialize these masks, fixed-point blend weights, and fade deltas.

Current target metadata is `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OC`. The exact covered-by managed CPP block and deliberate empty H block are installed. Current support-document hashes and no-change boundary hashes are recorded under `Supporting Research` and `Changed Files`. Current generated `Surface.cpp` contains exactly one UID0002V6 provenance block and no target empty marker, standalone raw table, duplicate emission, raw IDA symbol, sibling declaration, or header output.

Current support result: UID0000OC Surface, UID00025F physical aggregate, UID0002TB/UID0002TF RLE consumers, UID0002YF fill consumer, UID0002YJ/UID0002YO transfer consumers, and UID0000NT SoftwareBlend16 contain the accepted additive evidence with their independent metadata/formals preserved. UID0002V5 and UID0002M7 were reread and verified no-change because their exact predecessor/successor boundaries were already sufficient.

Pending work is supervisor-owned: a fresh exact-artifact Gate 1 continuity audit of this Gate 2B-reconciled report, supervisor-only execution/archive, and the post-execution manual coverage update/validation. Gate 2A and Gate 2B are complete and recorded below.

## Supporting Research

- Target after callback/validator command `17369`: `by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md`, SHA256 `7846D541331BC3C97CD27A8D4A0A29902A97CD8C48B478C67F52D22FA159FA2A`, 25,865 bytes / 218 lines.
- Containing physical-data aggregate after command `17371`: [UID:00025F] `FrameGrafPortReadOnlyData`, SHA256 `47107273FEB2DC050DB2B3BA13A894118944486548B18B89CBFC78B2B4944E13`, 18,140 bytes / 128 lines.
- Predecessor [UID:0002V5] was reread and intentionally not edited: SHA256 `9C49137F932AB92F6EABE4CD7DAD6650AEC90B87E3646485802950AF7645DCF5`, 6,241 bytes / 77 lines; its exact `[0x0061a8b8,0x0061a920)` boundary was already sufficient.
- Successor [UID:0002M7] was reread and intentionally not edited: SHA256 `51D6DD3D09456CF23FB22FF16B1F1438233839DC42624CB4D0900A5B02DD2F61`, 9,891 bytes / 101 lines; its exact `0x0061aac0` start and protected RTTI/vtable state were already sufficient.
- Source owner after command `17370`: [UID:0000OC] `Surface`, SHA256 `209C976D044CCB0A15EF54A3ED0B8AF0B989A7989AD50047119EB70C0EF9AA73`, 125,552 bytes / 527 lines.
- Semantic support after command `17377`: [UID:0000NT] `by-file/SoftwareBlend16.md`, SHA256 `CF8E195C7B7C6204A47484AD5B930336D2674B251248B660CCE0785BE75FB499`, 46,215 bytes / 236 lines.
- Callback consumers independently rechecked: [UID:0002TB], [UID:0002YF], [UID:0002YJ], [UID:0002TF], and [UID:0002YO].
- Prior B-agent reports were used as leads only and independently validated against current bytes, docs, and live IDA. Wave2/Wave3 material was ignored.
- Original PE: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, 2,679,296 bytes, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, image base `0x00400000`.
- The target is `.rdata` raw offset `0x00219320`; original-PE and live-MCP target bytes both hash to `756BB7CB40D6CCEBA12FCCB7366DCCEB00E35240F720341858D31661A7FF7F2A`.

## Target

- UID: `0002V6`
- Path: `by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md`
- Half-open range: `[0x0061a920,0x0061aac0)`
- Size: `0x1a0` / 416 bytes
- Current metadata after callback: `92/94`, owner/emitter [UID:0000OC], reconstructable true, covered-by CPP formal, and deliberately empty H formal.
- Current generated result: `NexusTK/render/Surface.cpp` contains one UID0002V6 covered-by provenance block and no UID0002V6 empty-emitter marker, standalone raw table, duplicate emission, or target header declaration.
- Requested result: exhaustive source-quality closure of bytes, consumers, semantics, ownership, source placement, emission policy, IDA data items, score, and support-document implications.

## Current Target State

The ordinary-document callback is complete. The target now records the aligned `0x0061aa00` family boundary, all 26 blocks, 142 block-head refs and 390 zero-ref interiors, five consumers, scalar source shape, exact boundaries, and the full IDA handoff. The stale `0x0061a9f8` and handwritten-table interpretations remain only as disproved historical assumptions.

The pre-callback command `17322` Surface.cpp empty marker and post-callback command-17377 hash were historical checkpoints. After supervisor Gate 2A command `17410`, current `auto-generated/NexusTK/render/Surface.cpp` is SHA256 `16A7E43CD43F9A50494E2EF069408129BD4A105D15E7282D2838BA1B96811714`, 46,532 bytes / 1,397 lines, last write `2026-07-24T21:22:01.9423763-04:00`. UID0002V6 appears exactly once at lines 1366-1371 as the accepted covered-by comments. Searches found no UID0002V6 empty marker, `SoftwareRenderMaskConstants` raw object, `kRgb555*`/`kRgb565*` declaration, `xmmword_61A*`/`qword_61A*`/`dword_61A970` symbol, duplicate table, or UID0002V6 occurrence in any generated sibling/header file. Gate 2A verified these content invariants after the fresh supervisor validation pass.

The manual by-memory coverage row remains stale and supervisor-owned; B003 did not edit it. Validator-owned generated/tracker state changed only as a side effect of the nine approved scoped validators, never by manual edit.

The accepted live prestate used 21 complete 16-byte items and five partially modeled blocks whose first 4 or 8 bytes were named while their remaining bytes were undefined one-byte items. Gate 2B has now normalized all 26 heads to exact 16-byte const arrays, absorbed the 44 former tail items, and installed only the accepted repeatable comments; exact prestate and poststate remain documented below.

## Executive Recommendation

1. **APPLIED:** retained one by-memory target spanning all 416 bytes; no physical split was introduced.
2. **APPLIED:** corrected the semantic family boundary to `0x0061aa00` and historicalized the disproved `0x0061a9f8` interpretation.
3. **APPLIED:** documented fourteen RGB555/compat blocks, twelve RGB565 blocks, exact lane values, and all 142 direct code xrefs plus 390 zero-ref interiors.
4. **APPLIED:** documented compiler-materialized constants covered by five scalar callback sources and rejected a handwritten indexed global table.
5. **APPLIED:** installed the covered-by CPP block and empty H block; generated readback proves no empty marker or duplicate data emission.
6. **APPLIED / VERIFIED NO CHANGE:** raised the target to `92/94` while preserving owner/emitter [UID:0000OC] and reconstructable true.
7. **APPLIED:** added report-level detail to the Surface owner, containing aggregate, five callback consumers, and SoftwareBlend16 support while preserving independent metadata and formals.
8. **APPLIED / VERIFIED SUPERVISOR GATE2B:** refreshed the stable IDB prestate, normalized/named/typed/commented all 26 aligned data items, preserved both neighbors/COL and dependency functions, saved, and recorded exact readback.

## Supervisor Active Recheck

Current post-callback supervisor controls:

- Perform a fresh exact-artifact Gate 1 continuity audit of this Gate 2B-reconciled report: verify all 33 literal H2 headings, the complete eight-column C2V6-01..34 ledger, separate CPP/H dispositions, current lifecycle language, the checked/pending checklist split, and exactly one final-Gate1-reaudit marker.
- Gate 2A completed: every implemented ledger claim was verified against current target/support hashes, fresh supervisor validator commands `17404` through `17414`, unchanged UID0002V5/UID0002M7 boundaries, and generated `Surface.cpp` content invariants.
- Gate 2B completed against stable session `supervisor_current_20260724_9f6e`: CB62 was freshly verified as the saved prestate before mutation, and all action/protected rows were read back after application.
- Gate 2B verified the 416-byte hash, 26 aligned heads, 142 head refs, 390 zero-ref interiors, absent address-taking/indexed routes, collision state, both comment channels, and exact predecessor/successor/COL protections.
- Gate 2B applied only the accepted 26 data-item normalization/name/type/repeatable-comment actions, preserved bytes/xrefs/boundaries, saved the IDB, and recorded backup plus pre/post hash/size/time and deterministic readback in this same report.
- Gate 2A and Gate 2B have passed. Only after the final exact-artifact Gate 1 continuity re-audit may the supervisor execute/archive the report. The supervisor applies and validates the manual coverage row only after execution.

## Inference Research Guidance Check

The inference standard was applied to behavior, ownership, source shape, names, types, and emission policy, not only to labels. The report distinguishes direct binary facts from source-shape inference and selects the most realistic mid-2000s C++ representation compatible with exact runtime behavior.

The binary cannot preserve original local spellings or the compiler's internal literal-pool labels. Leaving `xmmword_61A920`, `qword_61A940`, and similar names in final documentation would not reconstruct human source. The recommended names are consistent descriptive names derived from exact bit masks, channel layout, direct consumers, and arithmetic roles. They are not claimed as recovered lexical symbols.

Runtime behavior remains primary: no byte, lane, xref, callback mode, fixed-point scale, or fade delta is abstracted away. Human-looking source shape is recovered by placing the scalar expressions in their owning callbacks and treating this page as compiler output covered by those expressions.

## Heuristic / Inference Reanalysis And Validation

### Candidate source shapes

1. **Handwritten global constant table**: rejected. No consumer indexes a base, takes the pool address, or walks entries. Every reference targets a specific aligned block through direct compiler-generated loads.
2. **Twenty-six explicit file-scope SIMD declarations**: rejected as final source. This would reproduce decompiler artifacts and duplicate constants whose scalar callback expressions already explain generation.
3. **One hidden compiler literal pool covered by scalar callback source**: accepted. It explains alignment, direct loads, duplicated lane values, absence of address-taking, shared constants between callback variants, and exact arithmetic semantics.
4. **Split RGB555 and RGB565 by-memory pages**: rejected. The range is one contiguous compiler pool with one source owner, while the internal `0x0061aa00` split remains useful semantic documentation.

### Naming validation

- `GreenMask` and `RedBlueMask` follow exact RGB555/RGB565 channel masks.
- `FadeDeltaN` records the scalar channel step represented by each splat; for RGB565 the green component has six bits and therefore yields values such as `0x0841`, `0x18c3`, and `0x39c7`.
- `HalfBlendWeightBytes` is supported by byte value 16, `pmovzxbd`, and multiply use in both compat and RGB565 RLE blend paths.
- `BlendWeightScaleBytes` is supported by byte value 32 and the compat fill sequence that subtracts the requested alpha/strength before widening.
- Names do not encode IDA widths such as `xmmword` or `qword`; types preserve exact lane width and count.

## Evidence Standards Used

- Exact bytes and hashes outrank decompiler typography.
- Direct xrefs and instruction use outrank adjacent naming.
- Repeated arithmetic identities across independent consumers support semantic naming.
- Negative evidence is explicit: every interior address was queried, not sampled.
- Source ownership requires behavior/source-route evidence, not physical adjacency alone.
- A recommended IDA mutation requires current literal prestate, collision check, boundary constraints, exact action, and exact readback expectation.
- Unresolved original lexical spelling does not justify retaining compiler-generated labels; the best supported human source name is required.
- Scores above 85 require source-ready behavior and routing; scores remain below 95 because compile-identical source details and three callback bodies still require their own focused reconstruction passes.

## Evidence Checked

- Current target/support documentation and metadata headers.
- Current generated `Surface.cpp`, research tracker, memory coverage, and manual coverage rows read-only.
- Original PE section mapping and exact target bytes.
- Live MCP session `supervisor_current_20260724_9f6e`, `server_health`, item inspection, byte reads, comment reads, complete xref queries, entity/name collision queries, and consumer function profile/prototype/comment reads.
- Stable authoritative saved-IDB before/after checkpoint: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, 143,186,380 bytes, last write `2026-07-24T20:36:29.1906020-04:00`, SHA256 `CB62D69DD6833431565994032CA0F8229ED7762773A223E2F1CDA93AC9047C2E` before, during, and after the complete current-prestate pass.
- Historical-only shared-IDB checkpoints superseded before this return: `48EBC47071A99F8E90D2B639724A67CCB2ABA32FD34A776CA894471AE3CD8BED` (143,185,660 bytes, `2026-07-24T13:21:32.8746112-04:00`), supervisor-provided `B6A2BD3E2D92B9E77CFB82660F87E71D3709BC2D80C777140D9762234684A138` (143,186,131 bytes, `2026-07-24T14:11:31.3531890-04:00`), and `9F6E2C7AA9CFB718AB146AC8F8363CC1401F8474AA63803D7FAED35FA8ADE7CF` (143,186,002 bytes, `2026-07-24T18:12:13.9828605-04:00`). None is used as current Gate 2B prestate.
- Exact name-collision query across all 26 proposed names returned zero results.
- Complete byte-by-byte target xref audit: all 26 aligned block heads are referenced; all other 390 addresses have zero inbound xrefs; total direct refs are 142.
- Prior reports concerning [UID:00025F], [UID:0000OC], [UID:00039V], [UID:0000NT], [UID:0002TB], and [UID:0002TF], followed by independent current verification.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|---|
| C2V6-01 | 0002V6 | Exact range is `[0x0061a920,0x0061aac0)`, 416 bytes in `.rdata`. | Very strong | PE section mapping, exact endpoint bytes, predecessor/successor item reads. | `by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md` `## Range`; `by-memory/0x0061a7dc-0x0061aad0.FrameGrafPortReadOnlyData.md` `## Range`/`## Observed Contents`. | Record exact half-open range, size, section, and physical containment without expanding either endpoint. | `IMPLEMENTED_17369_17371; B003_READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-02 | 0002V6 | Original PE and MCP target bytes hash identically to `756BB7CB40D6CCEBA12FCCB7366DCCEB00E35240F720341858D31661A7FF7F2A`. | Very strong | Original-PE raw offset `0x00219320` and live MCP 416-byte read produce the same SHA256. | Target `## IDA Evidence` and `## Changes`. | Add both provenance sources and the full hash; verify target byte count remains 416. | `IMPLEMENTED_17369; B003_READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-03 | 0002V6 | Pool contains exactly 26 aligned 16-byte blocks. | Very strong | Exact byte partition and live item/xref audit at every `0x10`-aligned head. | Target `## Detailed Constant Inventory`; UID00025F `## Observed Contents`. | Add a complete 26-block inventory and aggregate count. | `IMPLEMENTED_17369_17371; READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-04 | 0002V6 | RGB555/compat family is `[0x0061a920,0x0061aa00)`, fourteen blocks. | Very strong | Values `0x03e0/0x7c1f`, RGB555 deltas, and refs only from compat consumers before `0x61aa00`. | Target `## Constant Groups`; UID00025F `## Observed Contents`. | Record exact family interval, block count, masks, blend vectors, and delta roles. | `IMPLEMENTED_17369_17371; READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-05 | 0002V6 | RGB565 family is `[0x0061aa00,0x0061aac0)`, twelve blocks. | Very strong | Values `0x07e0/0xf81f`, RGB565 deltas, and refs from RGB565 consumers beginning at `0x61aa00`. | Target `## Constant Groups`; UID00025F `## Observed Contents`. | Record exact family interval, block count, masks, and delta roles. | `IMPLEMENTED_17369_17371; READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-06 | 0002V6 | Existing `0x0061a9f8` semantic split is disproved; correct split is `0x0061aa00`. | Very strong | `[0x61a9f0,0x61aa00)` is one eight-lane RGB555 `0x7c1f` block; RGB565 `0x07e0` starts at `0x61aa00`. | Target `## Constant Groups`/`## Changes`; UID00025F `## Observed Contents`/`## Changes`. | Replace current split, preserve the old value only in historical-assumption prose with exact disproof. | `IMPLEMENTED_17369_17371; HISTORY_PRESERVED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-07 | 0002V6 | RGB555 mask blocks are `0x03e0`, `0x7c1f`, and their word-width splats. | Very strong | Exact bytes plus refs from UID0002TB/UID0002YF/UID0002YJ. | Target `## Detailed Constant Inventory`; UID0002TB `## Callback, Peer, And Compiler-Lowering Evidence`; UID0002YF `## Behavior Evidence`; UID0002YJ `## Evidence`. | Add exact block addresses, lane widths, values, and each consumer relationship. | `IMPLEMENTED_17369_17372_17374_17375; READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-08 | 0002V6 | RGB565 mask blocks are `0x07e0`, `0xf81f`, and their word-width splats. | Very strong | Exact bytes plus refs from UID0002TF and UID0002YO. | Target `## Detailed Constant Inventory`; UID0002TF `## Callback, Peer, And Compiler-Lowering Evidence`; UID0002YO `## Evidence`. | Add exact block addresses, lane widths, values, and consumer relationships. | `IMPLEMENTED_17369_17373_17376; READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-09 | 0002V6 | RGB555 deltas encode channel levels 1, 3, 7, 15, 16, 24, 28, and 30. | Very strong | Eight repeated word values `0421,0c63,1ce7,3def,4210,6318,739c,7bde` and transfer-mode refs. | Target `## Detailed Constant Inventory`; UID0002YJ `## Evidence`. | Record every value/address/level mapping and its block-transfer use. | `IMPLEMENTED_17369_17375; READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-10 | 0002V6 | RGB565 deltas encode the same channel levels under 5:6:5 packing. | Very strong | Eight repeated words `0841,18c3,39c7,7bcf,8410,c618,e71c,f79e` and UID0002YO refs. | Target `## Detailed Constant Inventory`; UID0002YO `## Evidence`. | Record every value/address/level mapping and its transfer-mode use. | `IMPLEMENTED_17369_17376; READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-11 | 0002V6 | `0x0061a970` is a sixteen-byte half-blend weight vector of 16. | Very strong | Sixteen `0x10` bytes; four direct refs; `pmovzxbd`/multiply use in compat and RGB565 RLE paths. | Target `## Detailed Constant Inventory`/`## IDA Evidence`; UID0002TB and UID0002TF `## Callback, Peer, And Compiler-Lowering Evidence`. | Add exact vector width/value and parallel callback arithmetic role. | `IMPLEMENTED_17369_17372_17373; READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-12 | 0002V6 | `0x0061a990` is a sixteen-byte fixed-point blend scale vector of 32. | Very strong | Sixteen `0x20` bytes; refs at `0x4be8e8/0x4beb66`; subtract-before-widen sequence. | Target `## Detailed Constant Inventory`/`## IDA Evidence`; UID0002YF `## Behavior Evidence`. | Add fixed-point scale semantics and exact consumer sites. | `IMPLEMENTED_17369_17374; READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-13 | 0002V6 | All 142 refs land on the 26 aligned block heads; all 390 interior addresses have zero refs. | Very strong | Complete `xrefs_to` pass across all 416 addresses on stable CB62. | Target `## IDA Evidence`/`## Cross-References`. | Add the 26-head/390-interior/142-total result and retain exact per-head site inventory. | `IMPLEMENTED_17369; COMPLETE_SITE_TABLE_READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-14 | 0002V6 | No base-indexed lookup, address-taking, VA/RVA pointer route, or sequential walker exists. | Strong to very strong | Complete interior-xref audit plus bounded consumer disassembly/decompilation and pointer searches. | Target `## Reconstruction Notes`/`## IDA Evidence`. | Record rejected handwritten-table evidence and compiler-literal-pool conclusion. | `IMPLEMENTED_17369; NEGATIVE_EVIDENCE_PRESERVED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-15 | 0002V6 | Direct consumers are UID0002TB, UID0002YF, UID0002YJ, UID0002TF, and UID0002YO. | Very strong | Every one of 142 xrefs resolves inside exactly those five current function ranges. | Target `## Cross-References`; `by-file/Surface.md` `## Proposed Contents`/`## Evidence Notes`. | Add all five UIDs, paths, ranges, roles, and exact ownership relationship. | `IMPLEMENTED_17369_17370; FIVE_CONSUMERS_READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-16 | 0002V6 | UID0002YJ and UID0002YO implement transfer modes `0..24`; case 24 clears. | Very strong | Current profiles show 1,819/1,816 instructions; bounded switch disassembly has 25 cases and case-24 memset tail. | UID0002YJ `## Evidence`/`## Score Rationale`; UID0002YO `## Evidence`/`## Score Rationale`; target `## Reconstruction Notes`. | Add exact mode domain, clear case, and connection to fade constants. | `IMPLEMENTED_17369_17375_17376; READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-17 | 0002V6 | Transfer callback slot 11 receives mutable pixel buffer, pixel count, mode, and fade step. | Very strong | Surface callback initializer evidence and current presentation/helper callsites, including `m_fadeStep`. | Target `## Reconstruction Notes`; `by-file/Surface.md` `## Proposed Contents`/`## Evidence Notes`. | Add callback-slot contract and caller data flow without changing broader ABI metadata. | `IMPLEMENTED_17369_17370; READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-18 | 0002V6 | Pool is compiler materialization of scalar callback expressions, not a handwritten table. | Strong to very strong | Direct block loads, no address identity/indexing, aligned splats, scalar mode arithmetic, and accepted compiler-lowering precedent. | Target `## Reconstruction Notes`; `by-file/Surface.md` `## Proposed Contents`; five consumer evidence/reconstruction sections. | Replace standalone-table source policy with covered-by compiler-output policy and preserve rejected alternative historically. | `IMPLEMENTED_17369_17370_17372_17376; INFERENCE_AND_HISTORY_READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-19 | 0002V6 | Source owner and emitter remain UID0000OC `Surface`. | Very strong | All refs are Surface callbacks; target header already routes owner/emitter UID0000OC; generated destination is `render/Surface.cpp`. | Target metadata header/`## Assignment Gate`; `by-file/Surface.md` `## Ownership Decision`. | Preserve owner/emitter metadata and add evidence-backed source route. | `IMPLEMENTED_17369_17370; ROUTE_PRESERVED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-20 | 0002V6 | Retain one physical by-memory page; no split is justified. | Very strong | Contiguous 416-byte pool, one owner/emitter, exact neighbors, and shared compiler-literal role. | Target `## Range`/`## Reconstruction Notes`; UID00025F `## Source-Routing Recheck`. | Preserve one page and document internal groups without creating child emitters. | `IMPLEMENTED_17369_17371; NO_SPLIT_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-21 | 0002V6 | Predecessor string ends exactly at `0x0061a920` and must not be absorbed. | Very strong | CB62 item `[0x61a8b8,0x61a920)`, 104-byte `const wchar_t`, one xref, exact comments absent. | Target `## Range`/`## IDA Evidence`; UID0002V5 `## Range` only if boundary detail is below report specificity. | Add target-side no-absorption proof; modify UID0002V5 only after reread proves missing detail. | `TARGET_IMPLEMENTED_17369; UID0002V5_READBACK_NO_CHANGE_SHA_9C49137F; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-22 | 0002V6 | Successor data begins exactly at `0x0061aac0` and must not be absorbed. | Very strong | CB62 one-byte pointer fragments at `61aac0..c3`, `off_61AAC4`, two following dwords, and external COL readback. | Target `## Range`/`## IDA Evidence`; UID0002M7 `## Range` only if boundary detail is below report specificity. | Add target-side no-absorption proof; preserve every protected successor entity. | `TARGET_IMPLEMENTED_17369; UID0002M7_READBACK_NO_CHANGE_SHA_51D6DD3D; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-23 | 0002V6 | CPP must use covered-by provenance rather than raw arrays/intrinsics/symbols; H must remain an exact managed empty block because no source declaration exists. | Very strong | Compiler-literal-pool source disposition, no address identity, no source-level object/type/header consumer. | Target metadata `RECONSTRUCTION_CPP` and `RECONSTRUCTION_H` formals; target `## Reconstruction Notes`. | Install exact CPP covered-by block and exact empty H block separately; do not invent a declaration. | `CPP_AND_H_IMPLEMENTED_17369; EXACT_BLOCKS_READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-24 | 0002V6 | Managed CPP formal removes the empty marker without duplicate raw emission; empty H correctly emits no sibling declaration/header. | Very strong | Current command-17322 generated marker; validator channel semantics; covered-by formal contains no declaration/definition. | Target CPP/H metadata formals; validator-owned `auto-generated/NexusTK/render/Surface.cpp` content invariant after callback. | Validate that CPP marker disappears, no raw table is emitted, and no target-generated H declaration appears. | `GENERATED_READBACK_A2FE484B; ONE_PROVENANCE_BLOCK; NO_EMPTY_MARKER_RAW_TABLE_DUPLICATE_OR_HEADER; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-25 | 0002V6 | Target should become `92/94`; owner/emitter/reconstructable remain UID0000OC/UID0000OC/true. | Strong to very strong | Closed bytes, refs, semantics, bounds, source route, CPP/H dispositions, and exact IDA plan. | Target metadata header, `## Assignment Gate`, `## Changes`, and Item Summary. | Set exact scores, preserve route flags, and replace summary with source-quality description. | `IMPLEMENTED_17369; 92_94_AND_ROUTE_READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-26 | 0002V6 | Support metadata and formals remain unchanged during this target pass. | Strong | Support pages have independent scope/scores; this report adds target-specific evidence without completing their body passes. | UID0000OC/UID00025F/UID0002TB/UID0002YF/UID0002YJ/UID0002TF/UID0002YO support sections named above; `by-file/SoftwareBlend16.md` [UID:0000NT] `## Evidence Notes`. | Add report-level evidence only; verify no unintended support score/route/formal changes. | `IMPLEMENTED_17370_17377; SUPPORT_METADATA_AND_FORMALS_READBACK_UNCHANGED; SUPERVISOR_GATE2A_VERIFIED_17404_17414` |
| C2V6-27 | 0002V6 | Twenty-one current IDA blocks are complete 16-byte items. | Very strong | CB62 `inspect_items` readback for all 26 heads identifies 21 size-16 items. | Report `## IDA Rename / Type / Comment Recommendations`; after Gate2B target `## IDA Evidence`. | Supervisor rechecks each head and records exact normalization/readback result. | `PRESTATE_AND_TARGET_HANDOFF_DOCUMENTED_CB62; SUPERVISOR_GATE2B_APPLIED_VERIFIED_E2128EF4` |
| C2V6-28 | 0002V6 | Five current blocks are fragmented into 4/8-byte heads plus 44 undefined one-byte tails. | Very strong | CB62 item-by-item readback for five heads and every tail, all names/types/comments absent on tails. | Report IDA section; after Gate2B target `## IDA Evidence`. | Supervisor normalizes only the five exact parent ranges and verifies all 44 tail values are preserved. | `PRESTATE_AND_TARGET_HANDOFF_DOCUMENTED_CB62; SUPERVISOR_GATE2B_APPLIED_VERIFIED_E2128EF4` |
| C2V6-29 | 0002V6 | All 26 recommended IDA names are collision-free at CB62. | Very strong | Exact anchored `entity_query` across all proposed names returned zero entities. | Report IDA section; after Gate2B target `## IDA Evidence`. | Supervisor repeats collision query immediately before rename and records results/readback. | `COLLISION_CHECK_AND_TARGET_HANDOFF_DOCUMENTED_CB62; SUPERVISOR_GATE2B_APPLIED_VERIFIED_E2128EF4` |
| C2V6-30 | 0002V6 | Every target regular and repeatable comment channel is absent at CB62. | Very strong | `get_comments` for all 26 heads and all 44 tails returned empty channels. | Report IDA action/tail tables; after Gate2B target `## IDA Evidence`. | Supervisor applies only the exact proposed repeatable comments and verifies regular comments remain absent. | `COMMENT_PRESTATE_AND_TARGET_HANDOFF_DOCUMENTED_CB62; SUPERVISOR_GATE2B_APPLIED_VERIFIED_E2128EF4` |
| C2V6-31 | 0002V6 | IDA should normalize each block to one exact typed 16-byte lane array while retaining bytes/xrefs. | Strong to very strong | Exact lane widths/values, 16-byte alignment, 142 head refs, and five partial-item defects. | Report IDA action table; after Gate2B target `## IDA Evidence`/`## Changes`. | Supervisor applies 26 names/types/comments, reads back item sizes/bytes/xrefs/comments, saves IDB, and records poststate. | `EXACT_ACTION_TABLE_MIRRORED_TO_TARGET; SUPERVISOR_GATE2B_APPLIED_VERIFIED_E2128EF4` |
| C2V6-32 | 0002V6 | Predecessor, successor, and external CachedHashTable COL require explicit no-change protection. | Very strong | CB62 exact item/name/type/width/value/comment/xref reads for all nine protected rows. | Report IDA protected table; target `## IDA Evidence` after Gate2B. | Supervisor verifies all protected entities byte-for-byte/name/type/comment/xref unchanged after target actions. | `NO_CHANGE_PRESTATE_AND_BOUNDARIES_DOCUMENTED_CB62; SUPERVISOR_GATE2B_APPLIED_VERIFIED_E2128EF4` |
| C2V6-33 | 0002V6 | Manual by-memory coverage requires the exact replacement row supplied below after execution. | Very strong | Current manual row read-only comparison reports stale 80% and older description. | `by-memory/-coverage-report.md`, existing UID0002V6 row; report `## Exact Manual Supervisor-Owned Coverage Or Tracker Text`. | Supervisor replaces exactly that row only after execute/archive, then validates coverage. | `MANUAL_ROW_READ; SUPERVISOR_POST_EXECUTION_PENDING` |
| C2V6-34 | 0002V6 | Research tracker and generated output may change only through validators/lifecycle, never manual edits. | Very strong | Historical command 17322 marker; commands 17369-17377; workflow ownership rules. | Validator-owned `auto-generated/-ag-research-tracker.md` and `auto-generated/NexusTK/render/Surface.cpp`; report `## Validator Results`. | B003 runs only scoped ordinary-file validators after callback; supervisor verifies generated headers/content and performs lifecycle. | `SCOPED_VALIDATORS_COMPLETE_17369_17377; GENERATED_CONTENT_READBACK_VERIFIED; SUPERVISOR_GATE2A_VERIFIED_17404_17414; SUPERVISOR_LIFECYCLE_PENDING` |

## Positive Evidence Summary

- Byte identity is exact across original PE and MCP.
- The target is completely partitioned into 26 aligned splat blocks with no unexplained byte.
- Every block has direct executable consumers; no padding or dead island remains inside the page.
- All 142 refs are inventoried and map only to five Surface callback functions.
- Bitwise values match RGB555/RGB565 channel masks, equal-channel fade deltas, and fixed-point blend weights.
- Compat and RGB565 peer callbacks use parallel constants and instruction shapes.
- Transfer callbacks expose the scalar mode/fade source behavior that explains compiler literal generation.
- Both neighboring boundaries are exact and independently modeled.
- Ownership, source placement, and non-standalone emission agree across physical, semantic, callback, and generated evidence.

## IDA MCP Facts

- Active database/session: `supervisor_current_20260724_9f6e`; the session name is historical infrastructure naming, while its loaded and saved authoritative revision is the `CB62D69D...47C2E` checkpoint below.
- `server_health`: status `ok`, module `NexusTK.exe`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, strings cache ready with 2,068 entries.
- Current saved IDB stable before, during, and after the itemized pass: SHA256 `CB62D69DD6833431565994032CA0F8229ED7762773A223E2F1CDA93AC9047C2E`, 143,186,380 bytes, last write `2026-07-24T20:36:29.1906020-04:00`.
- Prior `48EBC470...D8BED`, `B6A2BD3E...84A138`, and `9F6E2C7A...ADE7CF` saved revisions are historical only and do not supply any current prestate row.
- Current item model has complete 16-byte heads except at `0x0061a940`, `0x0061a970`, `0x0061a9f0`, `0x0061aa20`, and `0x0061aab0`.
- Fragment tails are 44 separate one-byte undefined items with absent name, type, regular comment, and repeatable comment.
- Exact name collision query for all 26 proposed names returned zero entities.
- Target comment query returned empty regular and repeatable channels at every aligned head and every fragmented tail.
- Protected predecessor and successor comment channels are itemized in the Gate 2B table.
- No IDA mutation, save, type declaration, rename, comment, or item normalization was performed by B003.

## Function / Child Inventory

| UID | Address / current name | Size | Role in this pool | Current source-quality state |
|---|---:|---:|---|---|
| 0002TB | `0x004bd420` `SoftwareRenderCompatRleFillCallback` | `0x889` | Compat/RGB555 RLE fill; masks plus half-weight vector | `92/94`, source-ready peer |
| 0002YF | `0x004be680` `sub_4BE680` | `0x6e7` | Compat fill/blend; mask and 32-scale vector | `87/90`, needs independent body pass |
| 0002YJ | `0x004bee40` `sub_4BEE40` | `0x185e` | Compat/RGB555 transfer modes and fade deltas | `87/90`, needs independent body pass |
| 0002TF | `0x004c3190` `SoftwareRenderRgb565RleFillCallback` | `0x8b0` | RGB565 RLE fill; masks plus half-weight vector | `92/94`, source-ready peer |
| 0002YO | `0x004c4790` `sub_4C4790` | `0x184e` | RGB565 transfer modes and fade deltas | `87/90`, needs independent body pass |

The pool has no callable children and no source-level standalone object children. Its source children are the five expressions embedded in these callbacks.

## Direct Xref / Caller Inventory

| Block | Refs | Exact code sites |
|---:|---:|---|
| `61a920` | 6 | `4bd833,4bdac4,4bdb8a,4bdbf6,4be8ef,4beb6d` |
| `61a930` | 10 | `4bd83e,4bd90a,4bd976,4bdabd,4be8f6,4be963,4be9d4,4beb74,4bec44,4beca8` |
| `61a940` | 8 | `4bd8ec,4bd95e,4bdb3e,4bdbb0,4be9af,4bea20,4bec1f,4bec90` |
| `61a950` | 15 | `4bee87,4bef5d,4bf16d,4bf295,4bf4ad,4bf723,4bf825,4bf96b,4bfaa5,4bfc6e,4bfd7e,4bfe98,4c012f,4c0304,4c040f` |
| `61a960` | 8 | `4bef69,4bf097,4bf179,4bf5e7,4bf72f,4bfea4,4c0019,4c041b` |
| `61a970` | 4 | `4bd848,4bdacb,4c35ba,4c3852` |
| `61a980` | 14 | `4bf2a1,4bf3d7,4bf4b9,4bf5f3,4bf778,4bf819,4bfd72,4bfee6,4bff17,4bff49,4bff7b,4c0025,4c013b,4c02f8` |
| `61a990` | 2 | `4be8e8,4beb66` |
| `61a9a0` | 3 | `4bf977,4bfab1,4bfc62` |
| `61a9b0` | 1 | `4c05d8` |
| `61a9c0` | 1 | `4c0521` |
| `61a9d0` | 1 | `4c0241` |
| `61a9e0` | 1 | `4bfbb9` |
| `61a9f0` | 8 | `4bd8be,4bd930,4bdb6c,4bdbde,4be990,4bea01,4bec00,4bec71` |
| `61aa00` | 4 | `4c35a5,4c384b,4c390a,4c3976` |
| `61aa10` | 4 | `4c35b0,4c367a,4c36e6,4c3844` |
| `61aa20` | 4 | `4c365c,4c36ce,4c38be,4c3930` |
| `61aa30` | 15 | `4c47d7,4c48ad,4c4abd,4c4bf7,4c4e0d,4c5068,4c516d,4c52ab,4c53e5,4c55ae,4c56be,4c57d8,4c5a6f,4c5c44,4c5d4f` |
| `61aa40` | 8 | `4c48b9,4c49e7,4c4ac9,4c4f47,4c5074,4c57e4,4c5959,4c5d5b` |
| `61aa50` | 14 | `4c4c03,4c4d37,4c4e19,4c4f53,4c50bd,4c5161,4c56b2,4c5826,4c5857,4c5889,4c58bb,4c5965,4c5a7b,4c5c38` |
| `61aa60` | 3 | `4c52b7,4c53f1,4c55a2` |
| `61aa70` | 1 | `4c5f18` |
| `61aa80` | 1 | `4c5e61` |
| `61aa90` | 1 | `4c5b81` |
| `61aaa0` | 1 | `4c54f9` |
| `61aab0` | 4 | `4c362e,4c36a0,4c38ec,4c395e` |

The sum is 142. Byte-by-byte queries over the other 390 addresses returned zero inbound xrefs.

## Documentation Evidence And IDA Status

The target's useful prior byte descriptions remain valid and must be preserved. The principal corrections are source shape and the RGB family boundary. Prior statements treating the range as broad static table source should move to a historical-assumption section explaining why direct-load evidence disproved handwritten-table emission.

IDA's partial `__m128i` typing at five heads is useful historical analysis but incomplete: the encoded constants are lane arrays and the actual blocks are all 16 bytes. Normalizing them does not alter bytes or executable behavior. Source-facing IDA types should describe exact element width/count, while the by-memory source formal remains covered-by rather than exposing these compiler literals.

## Ranked Ownership Analysis

1. **[UID:0000OC] Surface - accepted.** All 142 refs occur in Surface software-render callbacks, the initializer routes the transfer callback through Surface state, and generated placement is `NexusTK/render/Surface.cpp`.
2. **[UID:0000NT] SoftwareBlend16 semantic file - support only.** It explains blend arithmetic but is not the physical/source owner of this distinct pool.
3. **[UID:00025F] FrameGrafPortReadOnlyData - physical container only.** It groups the `.rdata` region but does not own source emission.
4. **Five callback by-memory pages - covered-by providers, not competing file owners.** Their scalar expressions jointly explain compiler output and all refs.
5. **Standalone `SoftwareRenderMaskConstants` object - rejected.** No pointer identity, indexed access, constructor, exported symbol, or table walker supports such an object.

## Source Placement

- File owner/emitter: [UID:0000OC] `by-file/Surface.md` -> `NexusTK/render/Surface.cpp`.
- Physical evidence page: [UID:0002V6] remains one by-memory document.
- Source representation: scalar masks, blend constants, and fade arithmetic remain inside their five callback bodies.
- The by-memory formal records covered-by provenance and emits no standalone declaration.
- No header declaration, exported symbol, global array, SIMD intrinsic constant, or separate translation unit is justified.

## Range / Split / Padding / Reclassification Analysis

- Start `0x0061a920` is exact: predecessor [UID:0002V5] is a 104-byte UTF-16 format string ending at the target start.
- End `0x0061aac0` is exact: successor begins with a pointer to CachedHashTable RTTI followed by table entries.
- No target byte is padding: every aligned 16-byte block head has direct code refs.
- No interior address has an inbound ref; this supports aligned literal blocks rather than arbitrary subranges.
- Internal semantic split is `0x0061aa00`, not `0x0061a9f8`.
- Do not create child by-memory pages for each literal; that would fragment one compiler pool and create 26 non-source emitters.
- Do not merge predecessor or successor data into this target.
- Classification remains reconstructable compiler-output evidence, with source covered by callback providers.

## Negative Evidence Summary

- No absolute-VA/RVA pointer to the pool base or block interiors was found.
- No consumer indexes from `0x0061a920` or `0x0061aa00`.
- No loop walks the 26 blocks.
- No constructor, initializer, destructor, writable alias, or relocation identifies a source object.
- No original symbols recover lexical constant names.
- No IDA name collision exists for the 26 proposed names.
- No target comment currently preserves a conflicting interpretation.
- No target byte is unreferenced padding.
- No neighbor item can be absorbed safely.
- No evidence supports emitting raw `__m128i`, intrinsics, `xmmword_*`, or a handcrafted table in final C++.

## IDA Rename / Type / Comment Recommendations

### Gate 2B checkpoint and common constraints

- Stable live prestate: session `supervisor_current_20260724_9f6e`, saved IDB SHA256 `CB62D69DD6833431565994032CA0F8229ED7762773A223E2F1CDA93AC9047C2E`, 143,186,380 bytes, last write `2026-07-24T20:36:29.1906020-04:00`, identical before, during, and after this complete read-only pass.
- Historical checkpoints `48EBC470...D8BED`, `B6A2BD3E...84A138`, and `9F6E2C7A...ADE7CF` were superseded before this return. They are retained only as rebase history and authorize no action.
- Every proposed name has zero current collision results.
- For each action, preserve exact bytes, address, 16-byte alignment, and all current xrefs. Normalize only the stated half-open range. Do not absorb predecessor/successor data.
- `regular=absent` and `repeatable=absent` are literal current comment states.
- Expected readback for each action is one 16-byte data item at the stated head, exact proposed name/type/repeatable comment, regular comment absent, identical bytes, and unchanged xrefs.

### Complete and fragmented block-head actions

| Entity/range | Literal current prestate | Exact bytes/value and xrefs | Proposed action and exact expected comment |
|---|---|---|---|
| `[61a920,61a930)` | head `61a920`; name `xmmword_61A920`; type absent; width 16; regular absent; repeatable absent | `E0 03 00 00` x4; 6 refs | Rename `kRgb555GreenMaskDwords`; type `const unsigned int[4]`; repeatable `RGB555 green mask 0x03E0 splatted for compat software-render channel isolation.` |
| `[61a930,61a940)` | head `61a930`; name `xmmword_61A930`; type absent; width 16; regular absent; repeatable absent | `1F 7C 00 00` x4; 10 refs | Rename `kRgb555RedBlueMaskDwords`; type `const unsigned int[4]`; repeatable `RGB555 red/blue mask 0x7C1F splatted for compat software-render channel isolation.` |
| `[61a940,61a948)` | head `61a940`; name `qword_61A940`; type `__m128i`; width 8; regular absent; repeatable absent | first half `E0 03` x4; 8 refs to block head | Normalize parent `[61a940,61a950)`; rename `kRgb555GreenMaskWords`; type `const unsigned short[8]`; repeatable `RGB555 green mask 0x03E0 splatted across eight 16-bit lanes.` |
| `[61a950,61a960)` | head `61a950`; name `xmmword_61A950`; type absent; width 16; regular absent; repeatable absent | `21 04` x8; 15 refs | Rename `kRgb555FadeDelta1Words`; type `const unsigned short[8]`; repeatable `RGB555 packed equal-channel fade delta for one channel level, 0x0421.` |
| `[61a960,61a970)` | head `61a960`; name `xmmword_61A960`; type absent; width 16; regular absent; repeatable absent | `63 0C` x8; 8 refs | Rename `kRgb555FadeDelta3Words`; type `const unsigned short[8]`; repeatable `RGB555 packed equal-channel fade delta for three channel levels, 0x0C63.` |
| `[61a970,61a974)` | head `61a970`; name `dword_61A970`; type absent; width 4; regular absent; repeatable absent | first four bytes `10` x4; 4 refs to block head | Normalize parent `[61a970,61a980)`; rename `kHalfBlendWeightBytes`; type `const unsigned char[16]`; repeatable `Fixed-point half-blend weight 16 splatted across sixteen byte lanes.` |
| `[61a980,61a990)` | head `61a980`; name `xmmword_61A980`; type absent; width 16; regular absent; repeatable absent | `E7 1C` x8; 14 refs | Rename `kRgb555FadeDelta7Words`; type `const unsigned short[8]`; repeatable `RGB555 packed equal-channel fade delta for seven channel levels, 0x1CE7.` |
| `[61a990,61a9a0)` | head `61a990`; name `xmmword_61A990`; type absent; width 16; regular absent; repeatable absent | byte `20` x16; 2 refs | Rename `kBlendWeightScaleBytes`; type `const unsigned char[16]`; repeatable `Fixed-point blend-weight scale 32 splatted across sixteen byte lanes.` |
| `[61a9a0,61a9b0)` | head `61a9a0`; name `xmmword_61A9A0`; type absent; width 16; regular absent; repeatable absent | `EF 3D` x8; 3 refs | Rename `kRgb555FadeDelta15Words`; type `const unsigned short[8]`; repeatable `RGB555 packed equal-channel fade delta for fifteen channel levels, 0x3DEF.` |
| `[61a9b0,61a9c0)` | head `61a9b0`; name `xmmword_61A9B0`; type absent; width 16; regular absent; repeatable absent | `10 42` x8; 1 ref | Rename `kRgb555FadeDelta16Words`; type `const unsigned short[8]`; repeatable `RGB555 packed equal-channel fade delta for sixteen channel levels, 0x4210.` |
| `[61a9c0,61a9d0)` | head `61a9c0`; name `xmmword_61A9C0`; type absent; width 16; regular absent; repeatable absent | `18 63` x8; 1 ref | Rename `kRgb555FadeDelta24Words`; type `const unsigned short[8]`; repeatable `RGB555 packed equal-channel fade delta for twenty-four channel levels, 0x6318.` |
| `[61a9d0,61a9e0)` | head `61a9d0`; name `xmmword_61A9D0`; type absent; width 16; regular absent; repeatable absent | `9C 73` x8; 1 ref | Rename `kRgb555FadeDelta28Words`; type `const unsigned short[8]`; repeatable `RGB555 packed equal-channel fade delta for twenty-eight channel levels, 0x739C.` |
| `[61a9e0,61a9f0)` | head `61a9e0`; name `xmmword_61A9E0`; type absent; width 16; regular absent; repeatable absent | `DE 7B` x8; 1 ref | Rename `kRgb555FadeDelta30Words`; type `const unsigned short[8]`; repeatable `RGB555 packed equal-channel fade delta for thirty channel levels, 0x7BDE.` |
| `[61a9f0,61a9f8)` | head `61a9f0`; name `qword_61A9F0`; type `__m128i`; width 8; regular absent; repeatable absent | first half `1F 7C` x4; 8 refs to block head | Normalize parent `[61a9f0,61aa00)`; rename `kRgb555RedBlueMaskWords`; type `const unsigned short[8]`; repeatable `RGB555 red/blue mask 0x7C1F splatted across eight 16-bit lanes.` |
| `[61aa00,61aa10)` | head `61aa00`; name `xmmword_61AA00`; type absent; width 16; regular absent; repeatable absent | `E0 07 00 00` x4; 4 refs | Rename `kRgb565GreenMaskDwords`; type `const unsigned int[4]`; repeatable `RGB565 green mask 0x07E0 splatted for software-render channel isolation.` |
| `[61aa10,61aa20)` | head `61aa10`; name `xmmword_61AA10`; type absent; width 16; regular absent; repeatable absent | `1F F8 00 00` x4; 4 refs | Rename `kRgb565RedBlueMaskDwords`; type `const unsigned int[4]`; repeatable `RGB565 red/blue mask 0xF81F splatted for software-render channel isolation.` |
| `[61aa20,61aa28)` | head `61aa20`; name `qword_61AA20`; type `__m128i`; width 8; regular absent; repeatable absent | first half `E0 07` x4; 4 refs to block head | Normalize parent `[61aa20,61aa30)`; rename `kRgb565GreenMaskWords`; type `const unsigned short[8]`; repeatable `RGB565 green mask 0x07E0 splatted across eight 16-bit lanes.` |
| `[61aa30,61aa40)` | head `61aa30`; name `xmmword_61AA30`; type absent; width 16; regular absent; repeatable absent | `41 08` x8; 15 refs | Rename `kRgb565FadeDelta1Words`; type `const unsigned short[8]`; repeatable `RGB565 packed equal-channel fade delta for one channel level, 0x0841.` |
| `[61aa40,61aa50)` | head `61aa40`; name `xmmword_61AA40`; type absent; width 16; regular absent; repeatable absent | `C3 18` x8; 8 refs | Rename `kRgb565FadeDelta3Words`; type `const unsigned short[8]`; repeatable `RGB565 packed equal-channel fade delta for three channel levels, 0x18C3.` |
| `[61aa50,61aa60)` | head `61aa50`; name `xmmword_61AA50`; type absent; width 16; regular absent; repeatable absent | `C7 39` x8; 14 refs | Rename `kRgb565FadeDelta7Words`; type `const unsigned short[8]`; repeatable `RGB565 packed equal-channel fade delta for seven channel levels, 0x39C7.` |
| `[61aa60,61aa70)` | head `61aa60`; name `xmmword_61AA60`; type absent; width 16; regular absent; repeatable absent | `CF 7B` x8; 3 refs | Rename `kRgb565FadeDelta15Words`; type `const unsigned short[8]`; repeatable `RGB565 packed equal-channel fade delta for fifteen channel levels, 0x7BCF.` |
| `[61aa70,61aa80)` | head `61aa70`; name `xmmword_61AA70`; type absent; width 16; regular absent; repeatable absent | `10 84` x8; 1 ref | Rename `kRgb565FadeDelta16Words`; type `const unsigned short[8]`; repeatable `RGB565 packed equal-channel fade delta for sixteen channel levels, 0x8410.` |
| `[61aa80,61aa90)` | head `61aa80`; name `xmmword_61AA80`; type absent; width 16; regular absent; repeatable absent | `18 C6` x8; 1 ref | Rename `kRgb565FadeDelta24Words`; type `const unsigned short[8]`; repeatable `RGB565 packed equal-channel fade delta for twenty-four channel levels, 0xC618.` |
| `[61aa90,61aaa0)` | head `61aa90`; name `xmmword_61AA90`; type absent; width 16; regular absent; repeatable absent | `1C E7` x8; 1 ref | Rename `kRgb565FadeDelta28Words`; type `const unsigned short[8]`; repeatable `RGB565 packed equal-channel fade delta for twenty-eight channel levels, 0xE71C.` |
| `[61aaa0,61aab0)` | head `61aaa0`; name `xmmword_61AAA0`; type absent; width 16; regular absent; repeatable absent | `9E F7` x8; 1 ref | Rename `kRgb565FadeDelta30Words`; type `const unsigned short[8]`; repeatable `RGB565 packed equal-channel fade delta for thirty channel levels, 0xF79E.` |
| `[61aab0,61aab8)` | head `61aab0`; name `qword_61AAB0`; type `__m128i`; width 8; regular absent; repeatable absent | first half `1F F8` x4; 4 refs to block head | Normalize parent `[61aab0,61aac0)`; rename `kRgb565RedBlueMaskWords`; type `const unsigned short[8]`; repeatable `RGB565 red/blue mask 0xF81F splatted across eight 16-bit lanes.` |

### Fragment-tail entities consumed by the five normalization actions

Every row below is a distinct current IDA entity. Each is one byte wide, unnamed, untyped, undefined, with regular and repeatable comments absent and zero direct xrefs. The action is to consume it only into the named parent 16-byte array; expected readback is a tail byte of that parent item with unchanged value and no standalone name/comment.

| Current entity | Literal prestate | Parent action and exact expected readback |
|---|---|---|
| `[61a948,61a949)` | head `61a948`; value `E0`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555GreenMaskWords`; tail byte `E0`, no standalone name/comment. |
| `[61a949,61a94a)` | head `61a949`; value `03`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555GreenMaskWords`; tail byte `03`, no standalone name/comment. |
| `[61a94a,61a94b)` | head `61a94a`; value `E0`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555GreenMaskWords`; tail byte `E0`, no standalone name/comment. |
| `[61a94b,61a94c)` | head `61a94b`; value `03`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555GreenMaskWords`; tail byte `03`, no standalone name/comment. |
| `[61a94c,61a94d)` | head `61a94c`; value `E0`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555GreenMaskWords`; tail byte `E0`, no standalone name/comment. |
| `[61a94d,61a94e)` | head `61a94d`; value `03`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555GreenMaskWords`; tail byte `03`, no standalone name/comment. |
| `[61a94e,61a94f)` | head `61a94e`; value `E0`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555GreenMaskWords`; tail byte `E0`, no standalone name/comment. |
| `[61a94f,61a950)` | head `61a94f`; value `03`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555GreenMaskWords`; tail byte `03`, no standalone name/comment. |
| `[61a974,61a975)` | head `61a974`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a975,61a976)` | head `61a975`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a976,61a977)` | head `61a976`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a977,61a978)` | head `61a977`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a978,61a979)` | head `61a978`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a979,61a97a)` | head `61a979`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a97a,61a97b)` | head `61a97a`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a97b,61a97c)` | head `61a97b`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a97c,61a97d)` | head `61a97c`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a97d,61a97e)` | head `61a97d`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a97e,61a97f)` | head `61a97e`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a97f,61a980)` | head `61a97f`; value `10`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kHalfBlendWeightBytes`; tail byte `10`, no standalone name/comment. |
| `[61a9f8,61a9f9)` | head `61a9f8`; value `1F`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555RedBlueMaskWords`; tail byte `1F`, no standalone name/comment. |
| `[61a9f9,61a9fa)` | head `61a9f9`; value `7C`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555RedBlueMaskWords`; tail byte `7C`, no standalone name/comment. |
| `[61a9fa,61a9fb)` | head `61a9fa`; value `1F`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555RedBlueMaskWords`; tail byte `1F`, no standalone name/comment. |
| `[61a9fb,61a9fc)` | head `61a9fb`; value `7C`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555RedBlueMaskWords`; tail byte `7C`, no standalone name/comment. |
| `[61a9fc,61a9fd)` | head `61a9fc`; value `1F`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555RedBlueMaskWords`; tail byte `1F`, no standalone name/comment. |
| `[61a9fd,61a9fe)` | head `61a9fd`; value `7C`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555RedBlueMaskWords`; tail byte `7C`, no standalone name/comment. |
| `[61a9fe,61a9ff)` | head `61a9fe`; value `1F`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555RedBlueMaskWords`; tail byte `1F`, no standalone name/comment. |
| `[61a9ff,61aa00)` | head `61a9ff`; value `7C`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb555RedBlueMaskWords`; tail byte `7C`, no standalone name/comment. |
| `[61aa28,61aa29)` | head `61aa28`; value `E0`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565GreenMaskWords`; tail byte `E0`, no standalone name/comment. |
| `[61aa29,61aa2a)` | head `61aa29`; value `07`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565GreenMaskWords`; tail byte `07`, no standalone name/comment. |
| `[61aa2a,61aa2b)` | head `61aa2a`; value `E0`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565GreenMaskWords`; tail byte `E0`, no standalone name/comment. |
| `[61aa2b,61aa2c)` | head `61aa2b`; value `07`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565GreenMaskWords`; tail byte `07`, no standalone name/comment. |
| `[61aa2c,61aa2d)` | head `61aa2c`; value `E0`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565GreenMaskWords`; tail byte `E0`, no standalone name/comment. |
| `[61aa2d,61aa2e)` | head `61aa2d`; value `07`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565GreenMaskWords`; tail byte `07`, no standalone name/comment. |
| `[61aa2e,61aa2f)` | head `61aa2e`; value `E0`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565GreenMaskWords`; tail byte `E0`, no standalone name/comment. |
| `[61aa2f,61aa30)` | head `61aa2f`; value `07`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565GreenMaskWords`; tail byte `07`, no standalone name/comment. |
| `[61aab8,61aab9)` | head `61aab8`; value `1F`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565RedBlueMaskWords`; tail byte `1F`, no standalone name/comment. |
| `[61aab9,61aaba)` | head `61aab9`; value `F8`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565RedBlueMaskWords`; tail byte `F8`, no standalone name/comment. |
| `[61aaba,61aabb)` | head `61aaba`; value `1F`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565RedBlueMaskWords`; tail byte `1F`, no standalone name/comment. |
| `[61aabb,61aabc)` | head `61aabb`; value `F8`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565RedBlueMaskWords`; tail byte `F8`, no standalone name/comment. |
| `[61aabc,61aabd)` | head `61aabc`; value `1F`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565RedBlueMaskWords`; tail byte `1F`, no standalone name/comment. |
| `[61aabd,61aabe)` | head `61aabd`; value `F8`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565RedBlueMaskWords`; tail byte `F8`, no standalone name/comment. |
| `[61aabe,61aabf)` | head `61aabe`; value `1F`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565RedBlueMaskWords`; tail byte `1F`, no standalone name/comment. |
| `[61aabf,61aac0)` | head `61aabf`; value `F8`; one-byte undefined; name/type/regular/repeatable absent; 0 refs | Consume into `kRgb565RedBlueMaskWords`; tail byte `F8`, no standalone name/comment. |

### Protected no-change entities

| Entity/range | Literal current prestate | Collision/boundary constraint and exact expected readback |
|---|---|---|
| `[61a8b8,61a920)` | head `61a8b8`; name `aSurfacedescDww`; type `const wchar_t`; width 104; bytes begin UTF-16 `surfaceDesc.`; value is `surfaceDesc.dwWidth : %d, surfaceDesc.dwHeight : %d`; regular absent; repeatable absent; 1 xref at `4b9464` | `NO_CHANGE_VERIFIED` required. Target normalization begins at `61a920`; expected identical head/name/type/width/value/comments/xref. |
| `[61aac0,61aac1)` | head `61aac0`; unnamed/untyped undefined byte; width 1; value `E8`; regular absent; repeatable absent; 0 xrefs | Preserve as first byte of pointer value `0x00647de8`; do not let target action cross `61aac0`; exact unchanged readback. |
| `[61aac1,61aac2)` | head `61aac1`; unnamed/untyped undefined byte; width 1; value `7D`; regular absent; repeatable absent; 0 xrefs | Preserve as second pointer byte; exact unchanged readback. |
| `[61aac2,61aac3)` | head `61aac2`; unnamed/untyped undefined byte; width 1; value `64`; regular absent; repeatable absent; 0 xrefs | Preserve as third pointer byte; exact unchanged readback. |
| `[61aac3,61aac4)` | head `61aac3`; unnamed/untyped undefined byte; width 1; value `00`; regular absent; repeatable absent; 0 xrefs | Preserve as fourth pointer byte; exact unchanged readback. |
| `[61aac4,61aac8)` | head `61aac4`; name `off_61AAC4`; type absent; width 4; value `0x004c64f0`; bytes `F0 64 4C 00`; regular absent; repeatable absent; 3 xrefs at `4c61a1,4c6288,4c651f` | Preserve successor item and refs; exact unchanged readback. |
| `[61aac8,61aacc)` | head `61aac8`; name absent; type absent; width 4; value `0x004f4b10`; bytes `10 4B 4F 00`; regular absent; repeatable absent; 0 head xrefs | Preserve successor item; exact unchanged readback. |
| `[61aacc,61aad0)` | head `61aacc`; name absent; type absent; width 4; value `0x0041b6c0`; bytes `C0 B6 41 00`; regular absent; repeatable absent; 0 head xrefs | Preserve successor item; exact unchanged readback. |
| `[647de8,647dec)` | head `647de8`; name `??_R4CachedHashTable@@6B@`; type absent; width 4; value/bytes `00 00 00 00`; regular comment exact `signature`; repeatable absent; 0 direct xrefs to COL head | Preserve decorated CachedHashTable COL and exact comments. The raw pointer at `61aac0` targets it but is not currently modeled as an xref. |

### Dependency-only consumer current state

These entities justify xrefs and source ownership but require no UID0002V6 Gate 2B action. They were re-read on the same stable `CB62D69D...47C2E` revision:

| Function | Exact current prototype | Current comment channels | Disposition |
|---|---|---|---|
| `0x004bd420` `SoftwareRenderCompatRleFillCallback`, size `0x889` | `void __thiscall(GrafPort *port, const EPFTileContext *sourceContext, const RectBounds *sourceBounds, const RectBounds *destinationBounds, unsigned __int8 mode, DLPalette *palette)` | regular exact `Compat/RGB555 Surface slot-3 RLE fill callback. ECX is GrafPort; stack args are source context, source bounds, destination bounds, mode, and palette. Signed tokens use low 7 bits as length; zero ends a row.`; repeatable absent; function-regular absent; function-repeatable exact `Surface-owned compat RLE fill/blend callback; source return type is void.` | `NO_ACTION`; owned by its consumer report |
| `0x004be680` `sub_4BE680`, size `0x6e7` | `char __userpurge@<al>(int@<ecx>, int@<ebp>, struct RectBounds *)` | regular, repeatable, function-regular, and function-repeatable all absent | `NO_ACTION`; independent callback-body pass required |
| `0x004bee40` `sub_4BEE40`, size `0x185e` | `__m128i *__cdecl(__m128i *, unsigned int, int)` | regular, repeatable, function-regular, and function-repeatable all absent | `NO_ACTION`; independent transfer-body pass required |
| `0x004c3190` `SoftwareRenderRgb565RleFillCallback`, size `0x8b0` | `void __thiscall(GrafPort *port, const EPFTileContext *sourceContext, const RectBounds *sourceBounds, const RectBounds *destinationBounds, unsigned __int8 mode, DLPalette *palette)` | regular exact `RGB565 Surface slot-3 RLE fill callback. ECX is GrafPort; stack args are source context, source bounds, destination bounds, mode, and palette. Signed tokens use low 7 bits as length; zero ends a row.`; repeatable absent; function-regular absent; function-repeatable exact `Surface-owned RGB565 RLE fill/blend callback; source return type is void.` | `NO_ACTION`; owned by its consumer report |
| `0x004c4790` `sub_4C4790`, size `0x184e` | `__m128i *__cdecl(__m128i *, unsigned int, int)` | regular, repeatable, function-regular, and function-repeatable all absent | `NO_ACTION`; independent transfer-body pass required |

No target-specific local, global, UDT, or function mutation is proposed outside the 26 data-item actions. Function renames/types/comments belong to consumer-specific reports, not this data-page action table.

### Supervisor Gate 2B implementation record

- Stable session: `supervisor_current_20260724_9f6e`; pre-mutation server health was `ok`, auto-analysis and Hex-Rays were ready, and all 26 proposed names were freshly collision-free.
- Saved prestate: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `CB62D69DD6833431565994032CA0F8229ED7762773A223E2F1CDA93AC9047C2E`, 143,186,380 bytes.
- Verified backup: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0002V6-20260724_213735.bak`, identical SHA256 `CB62D69DD6833431565994032CA0F8229ED7762773A223E2F1CDA93AC9047C2E` and size 143,186,380 bytes.
- Mutation: supervisor `make_data` installed the 26 exact final names and 16-byte const arrays, normalizing only `[61a940,61a950)`, `[61a970,61a980)`, `[61a9f0,61aa00)`, `[61aa20,61aa30)`, and `[61aab0,61aac0)`; supervisor `set_repeatable_comments` installed the exact 26 comments from the action table. No regular comments were added.
- IDA canonical type spelling: `const unsigned short[8]` reads back as equivalent `const unsigned __int16[8]`, and `const unsigned char[16]` reads back as equivalent `const unsigned __int8[16]`; the dword arrays retain `const unsigned int[4]`. Interior `get_comments` queries resolve to the containing parent array's repeatable comment, while `inspect_items` proves there is no standalone tail entity/name/comment after normalization.
- Initial post-action verifier intentionally withheld `idb_save` when it treated those canonical spellings and containing-item comment reads as mismatches. A corrected exact readback then passed every item, extent, comment, byte, xref, protected-boundary, dependency, and collision check before the only save.
- Byte/xref readback: target SHA256 remains `756BB7CB40D6CCEBA12FCCB7366DCCEB00E35240F720341858D31661A7FF7F2A`; all 26 heads are 16-byte items; all 44 former one-byte tails resolve to the expected parent; all 142 target-head xrefs and zero tail xrefs are unchanged.
- Protected/dependency readback: predecessor `[61a8b8,61a920)`, successor bytes/items `[61aac0,61aad0)`, CachedHashTable COL `0x00647de8`, and functions `0x004bd420`, `0x004be680`, `0x004bee40`, `0x004c3190`, and `0x004c4790` retain their exact prestate names/types/comments/bytes/xrefs. No dependency function was changed.
- Save result: `idb_save` returned `ok:true`; saved IDB SHA256 is `E2128EF4804CEB23ED4619C27A7C1B7808D050E08571B25BB3C8E40646448931`, 143,186,421 bytes, last write `2026-07-24T21:40:00.1407193-04:00`. Post-save server health remained `ok` with auto-analysis, Hex-Rays, and the 2,068-entry strings cache ready.

| Address | Exact saved name | Canonical IDA type | Size | Xrefs | Gate 2B disposition |
|---|---|---|---:|---:|---|
| `0x0061a920` | `kRgb555GreenMaskDwords` | `const unsigned int[4]` | 16 | 6 | `APPLIED_VERIFIED` |
| `0x0061a930` | `kRgb555RedBlueMaskDwords` | `const unsigned int[4]` | 16 | 10 | `APPLIED_VERIFIED` |
| `0x0061a940` | `kRgb555GreenMaskWords` | `const unsigned __int16[8]` | 16 | 8 | `APPLIED_VERIFIED` |
| `0x0061a950` | `kRgb555FadeDelta1Words` | `const unsigned __int16[8]` | 16 | 15 | `APPLIED_VERIFIED` |
| `0x0061a960` | `kRgb555FadeDelta3Words` | `const unsigned __int16[8]` | 16 | 8 | `APPLIED_VERIFIED` |
| `0x0061a970` | `kHalfBlendWeightBytes` | `const unsigned __int8[16]` | 16 | 4 | `APPLIED_VERIFIED` |
| `0x0061a980` | `kRgb555FadeDelta7Words` | `const unsigned __int16[8]` | 16 | 14 | `APPLIED_VERIFIED` |
| `0x0061a990` | `kBlendWeightScaleBytes` | `const unsigned __int8[16]` | 16 | 2 | `APPLIED_VERIFIED` |
| `0x0061a9a0` | `kRgb555FadeDelta15Words` | `const unsigned __int16[8]` | 16 | 3 | `APPLIED_VERIFIED` |
| `0x0061a9b0` | `kRgb555FadeDelta16Words` | `const unsigned __int16[8]` | 16 | 1 | `APPLIED_VERIFIED` |
| `0x0061a9c0` | `kRgb555FadeDelta24Words` | `const unsigned __int16[8]` | 16 | 1 | `APPLIED_VERIFIED` |
| `0x0061a9d0` | `kRgb555FadeDelta28Words` | `const unsigned __int16[8]` | 16 | 1 | `APPLIED_VERIFIED` |
| `0x0061a9e0` | `kRgb555FadeDelta30Words` | `const unsigned __int16[8]` | 16 | 1 | `APPLIED_VERIFIED` |
| `0x0061a9f0` | `kRgb555RedBlueMaskWords` | `const unsigned __int16[8]` | 16 | 8 | `APPLIED_VERIFIED` |
| `0x0061aa00` | `kRgb565GreenMaskDwords` | `const unsigned int[4]` | 16 | 4 | `APPLIED_VERIFIED` |
| `0x0061aa10` | `kRgb565RedBlueMaskDwords` | `const unsigned int[4]` | 16 | 4 | `APPLIED_VERIFIED` |
| `0x0061aa20` | `kRgb565GreenMaskWords` | `const unsigned __int16[8]` | 16 | 4 | `APPLIED_VERIFIED` |
| `0x0061aa30` | `kRgb565FadeDelta1Words` | `const unsigned __int16[8]` | 16 | 15 | `APPLIED_VERIFIED` |
| `0x0061aa40` | `kRgb565FadeDelta3Words` | `const unsigned __int16[8]` | 16 | 8 | `APPLIED_VERIFIED` |
| `0x0061aa50` | `kRgb565FadeDelta7Words` | `const unsigned __int16[8]` | 16 | 14 | `APPLIED_VERIFIED` |
| `0x0061aa60` | `kRgb565FadeDelta15Words` | `const unsigned __int16[8]` | 16 | 3 | `APPLIED_VERIFIED` |
| `0x0061aa70` | `kRgb565FadeDelta16Words` | `const unsigned __int16[8]` | 16 | 1 | `APPLIED_VERIFIED` |
| `0x0061aa80` | `kRgb565FadeDelta24Words` | `const unsigned __int16[8]` | 16 | 1 | `APPLIED_VERIFIED` |
| `0x0061aa90` | `kRgb565FadeDelta28Words` | `const unsigned __int16[8]` | 16 | 1 | `APPLIED_VERIFIED` |
| `0x0061aaa0` | `kRgb565FadeDelta30Words` | `const unsigned __int16[8]` | 16 | 1 | `APPLIED_VERIFIED` |
| `0x0061aab0` | `kRgb565RedBlueMaskWords` | `const unsigned __int16[8]` | 16 | 4 | `APPLIED_VERIFIED` |

## First-Draft C++ Recommendation

Destination: [UID:0002V6]. This is the complete source-ready formal. It intentionally emits only covered-by provenance because the original developer source would have contained scalar callback expressions rather than the compiler's pooled SIMD literals.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted source for this compiler-generated constant pool is covered by
// [UID:0002TB], [UID:0002YF], [UID:0002YJ], [UID:0002TF], and [UID:0002YO].
// Their scalar Surface callback expressions produce the RGB555/RGB565 masks,
// fixed-point blend weights, and fade deltas; no standalone data declaration
// is emitted for [UID:0002V6].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

This formal is human-source shaped, remains behaviorally exact, stays within the target's source authority, and avoids reverse-engineering labels or intrinsics. It was installed exactly in UID0002V6 during the accepted callback and validated by command `17369`.

Header disposition: [UID:0002V6] has no source-level object, symbol, type, declaration, or header consumer. Its compiler-generated literal bytes are covered by callback implementation expressions, so the H channel must remain explicitly empty rather than inventing a declaration. Destination-exact managed H formal:

*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

The empty H formal is a deliberate source-quality result. It was preserved/installed exactly and verified separately from the nonempty covered-by CPP formal: generated search finds no UID0002V6 sibling declaration or header output.

## Final Recommendation

The accepted ordinary-document callback is complete. Claims C2V6-01 through C2V6-26 are incorporated at report-level detail, the exact CPP/H blocks are installed, prior valid material is preserved, disproved assumptions are historicalized, all nine changed ordinary docs passed serial scoped validation, and generated content invariants pass the bounded readback.

The current report has passed supervisor Gate 2A and Gate 2B and is ready for the mandatory final exact-artifact Gate 1 continuity re-audit created by this reconciliation. Only the supervisor may execute/archive the report and later apply the manual coverage row. B003 did not invoke a lifecycle command or mutate IDA.

## Recommended Target Doc Changes

- **APPLIED / SUPERVISOR VERIFIED:** replaced assignment-baseline `86/91` with current `92/94`; supervisor Gate 2A verification passed.
- **VERIFIED NO CHANGE:** preserved `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank position metadata.
- **APPLIED:** installed the exact covered-by CPP and empty H managed formals.
- **APPLIED:** added the exact PE/MCP hash, 416-byte size, and `.rdata` mapping.
- **APPLIED:** added the complete 26-block lane/value inventory and corrected `0x0061aa00` family boundary.
- **APPLIED:** added all five consumers and the 142-head/390-interior xref proof.
- **APPLIED:** documented half-weight 16 and blend-scale 32 arithmetic.
- **APPLIED:** documented 25 transfer modes, case-24 clear behavior, and fade-delta roles.
- **APPLIED:** added ranked ownership, source placement, and source-shape analysis.
- **APPLIED:** preserved prior valid facts and historicalized the disproved `0x0061a9f8` and handwritten-table assumptions with exact negative evidence.
- **APPLIED:** added exact predecessor/successor boundary proof.
- **APPLIED / VERIFIED SUPERVISOR GATE2B:** the supervisor freshly rebased the exact CB62 recommendation/prestate table, backed up the authoritative IDB, applied all 26 accepted data-item actions, verified all 44 absorbed tails plus protected/dependency entities, saved, and recorded exact readback below.
- **APPLIED:** updated the item summary to describe the compiler literal pool and covered-by source route.

## Recommended Support Doc Changes

- Applied to [UID:0000OC] `by-file/Surface.md`: complete compiler-literal-pool source route, five consumers, and covered-by/no-standalone-emission policy; score/formal retained.
- Applied to [UID:00025F]: corrected internal family boundary and exact 26-block/142-xref evidence; metadata/formal retained.
- Applied to [UID:0002TB] and [UID:0002TF]: exact pool blocks and covered-by relationship; accepted scores/formals retained.
- Applied to [UID:0002YF]: compat masks, blend-scale 32 semantics/sites, and provider relationship; score/formal retained pending its independent body pass.
- Applied to [UID:0002YJ]: exact RGB555 fade-delta set, 25-mode/case-24-clear semantics, and provider relationship; score/formal retained.
- Applied to [UID:0002YO]: exact RGB565 fade-delta set, 25-mode/case-24-clear semantics, and provider relationship; score/formal retained.
- Applied to [UID:0000NT] `by-file/SoftwareBlend16.md`: negative-owner/source-shape contrast; metadata/formal retained.
- Verified no-change for [UID:0002V5] and [UID:0002M7]: current pages already contain exact boundary prose and were not edited.

## Score And Metadata Recommendation

| Document | Assignment baseline | Current post-callback | Disposition / route |
|---|---:|---:|---|
| UID0002V6 | `86/91` | `92/94` | **APPLIED**: exact bytes, refs, semantics, owner, source shape, CPP/H, range, and IDA plan are documented; owner/emitter/reconstructable route is unchanged |
| UID0000OC | `89/87` | `89/87` | **VERIFIED NO CHANGE**: broader Surface file received support detail only |
| UID00025F | `88/94` | `88/94` | **VERIFIED NO CHANGE**: physical aggregate received detail only |
| UID0002TB | `92/94` | `92/94` | **VERIFIED NO CHANGE**: accepted source-ready consumer received pool evidence only |
| UID0002TF | `92/94` | `92/94` | **VERIFIED NO CHANGE**: accepted source-ready consumer received pool evidence only |
| UID0002YF | `87/90` | `87/90` | **VERIFIED NO CHANGE**: independent callback-body pass remains necessary |
| UID0002YJ | `87/90` | `87/90` | **VERIFIED NO CHANGE**: independent transfer-body pass remains necessary |
| UID0002YO | `87/90` | `87/90` | **VERIFIED NO CHANGE**: independent transfer-body pass remains necessary |
| UID0000NT | `90/92` | `90/92` | **VERIFIED NO CHANGE**: semantic support file received negative-owner evidence only |

Reason not higher than `92/94`: original lexical spellings and compiler-version-specific pool ordering are unrecoverable, and UID0002YF/UID0002YJ/UID0002YO need independent full source-body reconstruction before the whole callback family can approach final-source scores. These are final-audit caps, not unresolved target blockers.

Reason not lower: every target byte, block, xref, arithmetic role, boundary, owner, emitter, source representation, managed formal, and IDA action is closed with exact current evidence.

## Open Questions With Attempted Resolution

- **Was this a handwritten global table?** Resolved negatively by 142 direct block loads, zero interior refs, zero address-taking, and zero indexed-base accesses. Best source reconstruction is compiler-generated covered-by output.
- **Where does RGB565 begin?** Resolved at `0x0061aa00`; exact masks and consumers disprove the stale `0x0061a9f8` split.
- **Are any bytes padding?** Resolved negatively. Every 16-byte block head has executable refs and the byte-by-byte audit found no alternate interior heads.
- **Should the range split?** Resolved negatively. One contiguous compiler pool, one owner, one source route, and exact neighbors support one physical page.
- **What do 16 and 32 mean?** Resolved as half-weight and fixed-point blend scale through `pmovzxbd`, multiply, and subtract-before-widen instruction use.
- **Are fade words arbitrary colors?** Resolved negatively. They are exact equal-channel deltas for levels 1/3/7/15/16/24/28/30 under RGB555 and RGB565 packing.
- **Can original names be proven?** Original spellings cannot be recovered, but source-facing names are resolved heuristically with high probability from exact roles. Compiler labels are not retained as an excuse.
- **Can exact standalone C++ be emitted?** Resolved: standalone arrays would be less source-authentic. Exact covered-by formal is the correct destination C++.
- **Does IDA require current mutations?** Resolved and applied by the supervisor at Gate 2B: all 26 exact item normalizations/names/types/repeatable comments passed fresh prestate, collision, readback, protected-state, save, and post-save health checks.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

After supervisor execution/archive, replace the stale [UID:0002V6] row in `by-memory/-coverage-report.md` with exactly:

```text
        - [UID:0002V6][0x0061a920-0x0061aac0.SoftwareRenderMaskConstants](by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md) 0x0061a920-0x0061aac0 | read-only-render-constant-data | SoftwareRenderMaskConstants : reconstructable : 92% : very-strong : Exact 416-byte, 26-block aligned compiler literal pool for Surface compat/RGB555 and RGB565 callbacks: all bytes/hash, 142 direct xrefs, 0x0061aa00 family split, masks, fixed-point blend weights, fade deltas, and neighboring boundaries are closed; callback source covers emission without a standalone table.
```

No direct tracker edit is authorized. Validator-owned research/generated trackers must refresh through the normal supervisor validator/lifecycle flow.

## Follow-Up Actions

1. Supervisor completed the fresh exact-artifact post-callback Gate 1 audit; because this Gate 2B record changes the artifact hash, one final exact-artifact Gate 1 continuity audit is required before execution.
2. Supervisor completed Gate 2A claim-by-claim verification against the current destination hashes, fresh commands `17404` through `17414`, and generated content invariants.
3. Supervisor completed Gate 2B on stable session `supervisor_current_20260724_9f6e`, applied all 26 accepted data-item actions, verified every protected entity, saved, and recorded exact readback above.
4. Supervisor alone executes/archives the report after Gate 2A and Gate 2B pass.
5. Supervisor applies and validates the manual coverage replacement only after execution.
6. Separate future focused passes reconstruct UID0002YF, UID0002YJ, and UID0002YO bodies; they do not block this target's implemented `92/94` result.

## Confidence

- Range/bytes/hash: very strong.
- Consumer/xref inventory: very strong.
- RGB555/RGB565 semantics and `0x0061aa00` split: very strong.
- Ownership/emitter/source placement: very strong.
- Compiler-literal-pool source shape: strong to very strong.
- Proposed human source-facing IDA names: strong; lexical originality is not claimed.
- Covered-by C++ disposition: very strong.
- Recommended target score `92/94`: justified.

## Validator Results

All changed ordinary documents passed the required serial scoped validator with exit `0` and `ok: 1`:

| Command | Ordinary document | Result |
|---:|---|---|
| `000000017369` | `by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md` | `ok: 1`; target metadata refreshed to `92/94`; managed registry changed blank -> block |
| `000000017370` | `by-file/Surface.md` | `ok: 1`; UID0002V6 and consumer references indexed; unrelated pre-existing missing-UID diagnostics remained nonfatal |
| `000000017371` | `by-memory/0x0061a7dc-0x0061aad0.FrameGrafPortReadOnlyData.md` | `ok: 1`; unrelated pre-existing UID00040U diagnostics remained nonfatal |
| `000000017372` | `by-memory/0x004bd420-0x004bdca9.SoftwareRenderCompatRleFillCallback.md` | `ok: 1` |
| `000000017373` | `by-memory/0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback.md` | `ok: 1` |
| `000000017374` | `by-memory/0x004be680-0x004bed67.SoftwareRenderCompatFillCallback.md` | `ok: 1` |
| `000000017375` | `by-memory/0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback.md` | `ok: 1` |
| `000000017376` | `by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md` | `ok: 1` |
| `000000017377` | `by-file/SoftwareBlend16.md` | `ok: 1`; UID0002V6 support reference indexed |

Each lease was acquired only immediately before its edit, held through that file's scoped validator, and released immediately afterward. `current_leases.md` readback shows no active B003 lease. No `execute_report`, probe, dry-run, lifecycle, registry command, report archive, or IDA mutation was invoked by B003.

Supervisor Gate 2A reran scoped commands `17404` UID00025F, `17406` UID0002TB, `17407` UID0002TF, `17408` UID0002YF, `17409` UID0002YJ, `17410` UID0002YO, `17412` UID0000NT, `17413` UID0000OC, and `17414` UID0002V6 with `--wait-generated`; every command exited `0` with `ok: 1`. Known nonfatal UID00040U and pre-existing Surface missing-reference diagnostics were unrelated to UID0002V6.

Current post-Gate2A generated readback: `auto-generated/NexusTK/render/Surface.cpp` SHA256 `16A7E43CD43F9A50494E2EF069408129BD4A105D15E7282D2838BA1B96811714`, 46,532 bytes / 1,397 lines, last write `2026-07-24T21:22:01.9423763-04:00`, header command `17410`. UID0002V6 occurs once as the accepted lines 1366-1371 provenance block. There is no UID0002V6 empty marker, standalone/raw constant table, duplicate emission, raw IDA label, target-generated declaration, or sibling/header occurrence.

## Changed Files

- `by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md`: SHA256 `7846D541331BC3C97CD27A8D4A0A29902A97CD8C48B478C67F52D22FA159FA2A`, 25,865 bytes / 218 lines.
- `by-file/Surface.md`: SHA256 `209C976D044CCB0A15EF54A3ED0B8AF0B989A7989AD50047119EB70C0EF9AA73`, 125,552 bytes / 527 lines.
- `by-memory/0x0061a7dc-0x0061aad0.FrameGrafPortReadOnlyData.md`: SHA256 `47107273FEB2DC050DB2B3BA13A894118944486548B18B89CBFC78B2B4944E13`, 18,140 bytes / 128 lines.
- `by-memory/0x004bd420-0x004bdca9.SoftwareRenderCompatRleFillCallback.md`: SHA256 `FB07BB3FBCBBA5CB8E4690FD979FAA32EE73783DB03F1B94DDA156E58E15E672`, 32,638 bytes / 409 lines.
- `by-memory/0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback.md`: SHA256 `BA636C35C5099763A548FA13AB9EC2085D45BE252CB3F041A3AA78EB3A94C4E2`, 28,278 bytes / 399 lines.
- `by-memory/0x004be680-0x004bed67.SoftwareRenderCompatFillCallback.md`: SHA256 `53FF6F9418DA42A9025A23B7C7C988CD79569082B61F44D1DD09D4EAD3C6CCE0`, 9,444 bytes / 86 lines.
- `by-memory/0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback.md`: SHA256 `BA7D5C96068117B52D723E21B475087B8639E8780C58D2A3D7204886DB338C16`, 9,694 bytes / 82 lines.
- `by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md`: SHA256 `29D5F7FFF30899ED3BE8AFD8ED3FAAC5590BB5514EF13B5608EF3B1190DECFE6`, 8,793 bytes / 79 lines.
- `by-file/SoftwareBlend16.md`: SHA256 `CF8E195C7B7C6204A47484AD5B930336D2674B251248B660CCE0785BE75FB499`, 46,215 bytes / 236 lines.
- Verified no-change: UID0002V5 SHA256 `9C49137F932AB92F6EABE4CD7DAD6650AEC90B87E3646485802950AF7645DCF5`; UID0002M7 SHA256 `51D6DD3D09456CF23FB22FF16B1F1438233839DC42624CB4D0900A5B02DD2F61`.
- This same report was reconciled after callback. Coverage/audit/goal/lifecycle files were not manually edited; generated/tracker/validator state changed only through the approved scoped validators.
- IDA changed/saved by B003: no. IDA changed/saved by supervisor Gate 2B: yes, exact record above.
- Report executed/archived: no.

## Implementation Tracking Checklist

- [x] Supervisor Gate 1 validated the accepted pre-callback exact report SHA `6D5FD9F778938CB690D4F44C8DA9672A60C61526124E39768C84D80108A0DD3A`, all headings, ledger, CPP/H dispositions, and score justification.
- [x] Supervisor accepted the CB62 saved-IDB prestate for callback and later refreshed that exact stable revision immediately before Gate 2B mutation.
- [x] Supervisor accepted the complete eight-column C2V6-01..34 ledger and implementation destination list.
- [x] B003 received the explicit ordinary-document implementation callback.
- [x] B003 updated UID0002V6 at full report detail without pruning valid history.
- [x] B003 installed the exact UID0002V6 covered-by `RECONSTRUCTION_CPP` managed formal.
- [x] B003 preserved/installed the exact empty UID0002V6 `RECONSTRUCTION_H` managed formal without inventing a declaration.
- [x] B003 updated UID0000OC Surface support detail without changing unrelated metadata/formal.
- [x] B003 updated UID00025F physical aggregate detail and corrected the internal split.
- [x] B003 updated UID0002TB and UID0002TF consumer detail without regressing accepted source.
- [x] B003 updated UID0002YF, UID0002YJ, and UID0002YO evidence/provider detail without claiming their independent passes complete.
- [x] B003 updated UID0000NT `by-file/SoftwareBlend16.md` negative-owner/source-route detail.
- [x] B003 reread UID0002V5 and UID0002M7 and verified their exact boundary detail already met the report standard, so both remained unchanged.
- [x] B003 ran serial scoped validators `17369` through `17377` for every changed ordinary document and recorded exact results.
- [x] B003 reread generated `NexusTK/render/Surface.cpp`: no UID0002V6 empty marker, raw table, duplicate emission, raw IDA label, target sibling declaration, or header output exists.
- [x] B003 reconciled all ledger rows, destination hashes, validator results, changed files, and checklist in this same report.
- [x] Supervisor Gate 2A verified every implemented claim and generated content invariant with fresh commands `17404` through `17414`.
- [x] Supervisor Gate 2B refreshed all 26 action rows and protected rows against stable session `supervisor_current_20260724_9f6e`.
- [x] Supervisor Gate 2B applied/verified the 26 data-item names/types/repeatable comments without changing bytes/xrefs/boundaries.
- [x] Supervisor Gate 2B verified all predecessor/successor/COL protected entities and five dependency functions unchanged.
- [x] Supervisor recorded the verified backup, pre/post IDB hash/size/time, save result, exact item readback, canonical IDA type spelling, and post-save health in this report.
- [ ] Supervisor alone executes/archives the validated report.
- [ ] Supervisor applies the exact manual by-memory coverage replacement after execution.
- [ ] Supervisor validates the changed coverage report and confirms validator-owned trackers/generated state.

READY_FOR_SUPERVISOR_FINAL_GATE1_REAUDIT

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000017428","destination_path":"executed-b-agent-research/B003/0002V6-SoftwareRenderMaskConstants-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002V6-SoftwareRenderMaskConstants-empty-emitter-source-quality.md","timestamp":"2026-07-24T21:48:02-04:00","uid":"0002V6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
