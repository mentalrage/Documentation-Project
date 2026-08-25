** TARGET-REPORT-UID:0004DN **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0004DN] NewHumanImageLibGrowCommandSideVector Source-Quality Report

Report timestamp: `2026-07-06T00:42:58-04:00`

## Finalized Report / Current Recommendation

Supervisor Gate 1 passed this report at SHA256 `B80C4DCCC04A33C04BEE67DF5483C8CEDD10318FB84E237290D3BEBE7FA1384B`, and the implementation callback has now applied the accepted narrow source-quality repair for [UID:0004DN][0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector](../../../../../by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md). The target is now `COMPLETION:88`, `CONFIDENCE:91`; `CANONICAL_OWNER:0000LR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LR`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0` are preserved; and the formal marker now identifies command-side pointer-ring/vector support with no standalone helper body.

The refreshed MCP evidence proves the function is a real `0x192` / 402-byte body at `0x004e6e50-0x004e6fe2`, called only from `BuildPartDrawCommand` at `0x004e2f7a`. The caller passes `this + 13`, i.e. the object state beginning at byte offset `+0x34`, and the target grows/rebalances a 4-byte pointer-slot command-side storage state. The caller then lazily allocates 9-byte side records for slots and writes the 8-byte plus 1-byte command-side payload. This evidence is incorporated into the target and narrow support docs; it remains insufficient for a source-authored helper body because exact command-record names, field names, and a standalone exact `BuildPartDrawCommand` source page are still missing.

Implementation should not move the target to direct `VectorHelpers` ownership and should not create a decompiler-shaped allocator/memmove/memset helper body. The direct route remains [UID:0000LR][NewHumanImageLib](../../../../../by-file/NewHumanImageLib.md), with [UID:000092][NewHumanImageLib](../../../../../by-class/NewHumanImageLib.md) as semantic class context and [UID:0000P3][VectorHelpers](../../../../../by-file/VectorHelpers.md) only as a compatibility-template fallback.

## Supporting Research

Lifecycle/status:

- Current artifact state: this report remains in B004's assigned research path, `tools/leaser/Agents/Agent-B004/research/0004DN-NewHumanImageLibGrowCommandSideVector-source-quality.md`, after the supervisor-accepted implementation callback. It is post-implementation and ready for supervisor Gate 2 / `execute_report` review; the supervisor has not yet run report execution/archive for this artifact.
- Current implementation state: accepted target/support by-* edits have been applied, the report checklist and claim ledger are checked to applied states, scoped validators `000000007509` through `000000007513` passed, and generated refresh completed through validator command `000000007513`.
- Historical report-only state: the initial pre-callback B004 pass for UID0004DN performed no by-* implementation, required supervisor Gate 1 before edits/validators/leases, and requested no generated refresh during that report-only phase.
- B004 lifecycle boundary still current: B004 did not run `execute_report`, a dry-run/probing execute variant, registry lifecycle command, manual report move, archive move, manual validator-state edit, manual generated-file edit, coverage-report edit, or supervisor ledger edit.

Docs/reports/generated checked:

- Target: `by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md`.
- Direct support docs: `by-file/NewHumanImageLib.md`, `by-class/NewHumanImageLib.md`, `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`, `by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md`, `by-file/VectorHelpers.md`, and `by-type/by-struct/NewHumanImageLibLayout.md`.
- Related sibling pages: UID0004DQ `NewHumanImageLibAppendCommandRecord80`, UID00041F `VectorGrowLayer`, UID00041G `VectorGrowPart`, and UID00017T `VectorGrowMotion`.
- Generated/tracker files read-only: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/render/NewHumanImageLib.cpp`.
- Executed reports checked as leads: B011 `00022R-ImageLibVectorSupportHelpers-source-quality.md`, B011 `0000LR-NewHumanImageLib-empty-emitter-family-source-quality.md`, B007 `00041G-VectorGrowPart-by-memory-source-quality.md`, B011 `00041F-VectorGrowLayer-source-quality.md`, and B005 `00017T-VectorGrowMotion-source-quality.md`.

MCP/session summary:

- Active IDA MCP database/session: `supervisor_recovery_20260705`.
- MCP health: `server_health` returned `status=ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`.
- MCP calls used were narrow and paged/schema-current: `idb_list`, `server_health`, `lookup_funcs`, `entity_query` with bounded `functions`/`names`, `get_bytes`, `xrefs_to`, `xref_query`, `callees`, `decompile`, `disasm` with caps, `analyze_function`, `find_bytes`, `make_signature_for_range`, `int_convert`, and scoped `search_text`.
- One obsolete `entity_query kind=function` attempt returned `Unsupported kind: function`; this was corrected to `kind=functions` and was not an MCP availability failure.
- One obsolete `type_query` shape attempt returned `missing required parameters: ['queries']`; equivalent narrow `entity_query kind=names`, `func_query`, and scoped text searches were used for name/type evidence.

## Target

- Target UID: `0004DN`.
- Target path: `by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md`.
- Queue source: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Historical queue row at assignment/pre-callback read: `86/89`, combined `87.5`, reconstructable `true`, reports `0`.
- Classification: exact function body / compiler-lowered NewHuman command-side pointer-ring/vector grow/rebalance support, routed through the NewHuman source file as marker-only emitted source-disposition support.
- Current parent/source state: owner/emitter [UID:0000LR][NewHumanImageLib](../../../../../by-file/NewHumanImageLib.md), class context [UID:000092][NewHumanImageLib](../../../../../by-class/NewHumanImageLib.md), split-parent context [UID:00022R][ImageLibVectorSupportHelpers](../../../../../by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md), and fallback-only utility context [UID:0000P3][VectorHelpers](../../../../../by-file/VectorHelpers.md).

## Current Target State

Post-callback, the target currently has:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000LR`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LR`
- blank `EMITTER_POSITION_OPTIONAL`
- `Nested:0`
- formal marker only, with the accepted text:

```cpp
// NewHumanImageLibGrowCommandSideVector is compiler-lowered command-side
// pointer-ring/vector growth support for NewHumanImageLib::BuildPartDrawCommand.
// Source behavior should live in typed BuildPartDrawCommand command-append
// logic, or in a local vector compatibility template if needed.
// Do not emit a standalone allocator/memmove/memset helper body here.
```

The target page now records the exact range, `0x004e6e50-0x004e6fe2`, the `sub_4E6E50` size `0x192` / 402 bytes, seven `0xcc` prepad bytes, fourteen `0xcc` postpad bytes before successor `0x004e6ff0`, unique signature, one `BuildPartDrawCommand` caller at `0x004e2f7a`, `this + 13` / byte-offset `+0x34` command-side receiver proof, 4-byte pointer-slot growth/rebalance behavior, caller-side 9-byte side-record allocation/copy, allocation/memmove/memset/free callees, NewHuman file route, VectorHelpers fallback-only route, rejected direct class-method/no-owner/standalone-body alternatives, and confidence caps for exact command-side field names and typed `BuildPartDrawCommand` source.

Generated state is current through validator command `000000007513`: `auto-generated/NexusTK/render/NewHumanImageLib.cpp` header shows `validator-command-id: 000000007513`, `validator-refreshed-at: 2026-07-06T01:05:40-04:00`, and UID0004DN appears at `Completion:88 | Confidence:91` with the accepted marker. This was read-only inspection; generated files were not edited manually. Historical pre-callback state was `86/89` with the older generic marker and validator command `000000007480`.

## Heuristic / Inference Reanalysis And Validation

Owner/emitter:

- Keep direct owner/emitter [UID:0000LR][NewHumanImageLib](../../../../../by-file/NewHumanImageLib.md). The sole code caller is inside `sub_4E2EB0`, documented by class/file/cluster pages as `BuildPartDrawCommand`, and that method is part of the NewHuman command-building family.
- Do not move direct target ownership to [UID:000092][NewHumanImageLib](../../../../../by-class/NewHumanImageLib.md). MCP shows the target's `ecx` receiver is `this + 13` from the caller, a command-side storage subobject at byte offset `+0x34`, not the enclosing class object as an ordinary method receiver.
- Do not move direct target ownership to [UID:0000P3][VectorHelpers](../../../../../by-file/VectorHelpers.md). The body has one NewHuman caller and no cross-module helper reuse; VectorHelpers remains only a compatibility-template fallback if typed NewHuman source cannot regenerate the out-of-line helper.

Reconstructable:

- Keep `RECONSTRUCTABLE:TRUE`. The function body is real, exact, and emitted through the NewHuman file route as a non-empty source-disposition marker. The marker prevents an empty generated slot while avoiding a false handwritten helper body.

Generated route:

- Current generated `auto-generated/NexusTK/render/NewHumanImageLib.cpp` already includes UID0004DN through [UID:0000LR]. A callback should refresh it only through scoped validators, not by manual generated edits.
- Expected generated result after implementation: UID0004DN remains a comment-only marker, but with the updated `88/91` metadata and the more exact command-side pointer-ring/vector marker text.

Source placement:

- Final authored behavior should live in typed `NewHumanImageLib::BuildPartDrawCommand` command-append logic if that method receives an exact source page later.
- If recovered typed source cannot regenerate the out-of-line helper, the only acceptable fallback is a local/vector compatibility template, not a standalone product helper named literally `NewHumanImageLibGrowCommandSideVector`.

C++ marker:

- The existing marker is directionally correct, but it should be refined to identify the pointer-ring/vector storage, `BuildPartDrawCommand` append context, and no standalone allocator/memmove/memset body.
- A real C++ helper body is not recommended because it would encode compiler/vector allocation and rebalance lowering using invented storage names.

Route repair:

- Target doc should be updated with the current MCP evidence, caller decompile, pointer-slot/9-byte side-record behavior, and negative evidence.
- Support docs should receive narrow synchronization only where same-or-greater detail is missing. No support score movement is recommended.

Score blockers:

- Resolved: exact function range, boundaries, padding, unique signature, sole caller, callee set, caller storage offset, 4-byte pointer-slot behavior, and route rejection for direct VectorHelpers.
- Still confidence caps: exact original helper spelling, command-side storage/member names, 9-byte side-record type name, typed `BuildPartDrawCommand` source signature/body, and the broader project decision on compatibility vector templates.

Rejected alternatives:

- Reject aggregate [UID:00022R][ImageLibVectorSupportHelpers](../../../../../by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md) as direct source owner. It is now a non-emitting mixed split/index.
- Reject IME/successor merge. Target ends at `0x004e6fe2`, followed by fourteen `0xcc` bytes and successor `sub_4E6FF0` at `0x004e6ff0`.
- Reject no-owner/non-emitting status. Current file route already emits a marker and current evidence is stronger than a blank/non-emitting state.

Remaining caps:

- The exact source names for the command-side storage state at `+0x34..+0x44` remain inferred.
- There is no exact by-memory page for `BuildPartDrawCommand`; current evidence comes from the local method cluster, class/file pages, and MCP decompile.
- No local IDA UDT or named source symbol proves a command-side type.

## Evidence Standards Used

- Current MCP evidence is mandatory and primary for function identity, boundaries, caller/callee proof, byte/signature proof, and decompile behavior.
- Current by-* docs are used for accepted ownership/source-route context, not as substitutes for live MCP evidence.
- Executed reports are used as historical/support precedent only; UID0004DN claims are rechecked against current docs and current MCP.
- Generated output/tracker files are read-only evidence of current validator projection, not editable sources.
- Negative evidence is treated as source-quality evidence when the query is narrow and bounded: no raw VA/RVA pointer hits, no source names, no local command UDT names, no extra callers, and no cross-module helper reuse.

## Evidence Checked

Current by-* docs:

- `by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md`
- `by-file/NewHumanImageLib.md`
- `by-class/NewHumanImageLib.md`
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`
- `by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md`
- `by-file/VectorHelpers.md`
- `by-type/by-struct/NewHumanImageLibLayout.md`
- sibling target/support docs for UID0004DQ, UID00041F, UID00041G, and UID00017T

Generated/tracker evidence:

- Historical report-only read of `auto-generated/-ag-research-tracker.md`: UID0004DN row `86/89`, combined `87.5`, reconstructable `true`, reports `0`.
- Historical report-only read of `auto-generated/-ag-memory-coverage.md`: UID0004DN coded, owner/emitter `0000LR`, generated path `auto-generated/NexusTK/render/NewHumanImageLib.cpp`.
- Historical report-only read of `auto-generated/-ag-coverage-report-by-memory.md`: UID0004DN `emits_code:true`, reconstructable, `86%`, strong, updated `2026-07-02 16:56:48`.
- Post-callback read-only generated freshness check of `auto-generated/NexusTK/render/NewHumanImageLib.cpp`: header `validator-command-id: 000000007513`, refreshed `2026-07-06T01:05:40-04:00`, UID0004DN marker present at lines 227-232, `Completion:88 | Confidence:91`.

Executed report evidence checked:

- B011 UID00022R split report created UID0004DN from the mixed helper island and already rejected whole-range VectorHelpers ownership.
- B011 UID0000LR empty-emitter-family report established NewHuman file-route marker/no-standalone-body precedent for vector/STL glue.
- B007 UID00041G, B011 UID00041F, and B005 UID00017T reports establish the NewHuman local vector slow-path pattern: file-local marker support, class-method rejection when the receiver is a vector header, and VectorHelpers fallback-only route.

MCP evidence checked:

- `lookup_funcs`: target `0x004e6e50` is `sub_4E6E50`, size `0x192`; `0x004e6fe2` is not a function; successor `0x004e6ff0` is `sub_4E6FF0`; caller `0x004e2eb0` is `sub_4E2EB0`, size `0x125`; callsite `0x004e2f7a` resolves inside `sub_4E2EB0`; sibling UID0004DQ start `0x004e70a0` is `sub_4E70A0`.
- `entity_query kind=functions`: in `0x004e6de0-0x004e7030`, functions are `sub_4E6DF0`, `sub_4E6E50`, `sub_4E6FF0`, and `sub_4E7030`.
- `get_bytes`: seven `0xcc` bytes before `0x004e6e50`, target body bytes over 402 bytes, fourteen `0xcc` bytes after `0x004e6fe2`, and caller bytes around `0x004e2f60`.
- `xrefs_to`/`xref_query`: exactly one incoming code xref to target, from `0x004e2f7a` in `sub_4E2EB0`.
- `callees`: target calls `operator new`, `_memmove_0`, `_memset`, `sub_5C7526`, `sub_43F190`, and `__invalid_parameter_noinfo_noreturn`; caller calls `sub_4D1600`, `sub_4B78F0`, `sub_543E40`, target `sub_4E6E50`, and `operator new`.
- `decompile`/`analyze_function` target: vector-header style `void __thiscall sub_4E6E50(_DWORD *this, void *a2)` with 24 basic blocks, complexity 10, growth loop, 4-byte slot allocation, memmove/memset rebalance, checked free, and final storage/capacity updates.
- `decompile`/`analyze_function` caller: `char __thiscall sub_4E2EB0(...)`, size 293 bytes, source-family `BuildPartDrawCommand`, capacity check at `0x004e2f73`, target call `sub_4E6E50(this + 13, (void *)1)` at `0x004e2f7a`, slot calculation through fields at object dword indexes 14-17, lazy `operator new(9)` for a side record, 8-byte plus 1-byte side-record copy, and `++this[17]`.
- `find_bytes`: no raw VA pattern `50 6E 4E 00` or RVA pattern `50 6E 0E 00`; rel32 call pattern `E8 D1 3E 00 00` and the longer `E8 D1 3E 00 00 8B 4E 3C` pattern occur only at `0x004e2f7a`.
- `make_signature_for_range`: target range signature is unique with wildcarded operands.
- `entity_query kind=names`: `*NewHuman*` finds only RTTI/vtable names; `*Command*` finds CRT command-line names, not local NewHuman command types or source symbols.
- `search_text` scoped to `0x004dfd10-0x004e7100`: no `Command` listing hits; `NewHuman` hits are vtable/RTTI comments only.

## Positive Evidence Summary

- The function range is exact: `sub_4E6E50` starts at `0x004e6e50`, size `0x192` / 402 bytes, exclusive end `0x004e6fe2`.
- Boundary bytes are exact: `0x004e6e49-0x004e6e50` is seven `0xcc` bytes; `0x004e6fe2-0x004e6ff0` is fourteen `0xcc` bytes before `sub_4E6FF0`.
- There is exactly one code caller: `0x004e2f7a` inside `sub_4E2EB0`, the `BuildPartDrawCommand` method-family function.
- The caller passes `this + 13` and `1`, so the helper operates on a subobject beginning at object dword index 13 / byte offset `+0x34`, not on the `NewHumanImageLib *` object as a class method.
- The helper grows a 4-byte slot container. Target decompile uses `4 * newCapacity`, shifts by 2, moves/copies spans with `_memmove_0`, clears gaps with `_memset`, stores the new pointer to receiver `[1]`, and increases receiver `[2]` by the new free slot count.
- The caller's post-grow path proves command-side use: it masks `this[16]` by `capacity - 1`, computes a 4-byte slot index from `(capacity - 1) & (this[16] + this[17])`, reads the slot pointer from `this[14]`, lazily allocates `9` bytes if the slot is null, copies eight bytes plus one byte into that record, and increments `this[17]`.
- The target's callee set is vector/runtime support only: `operator new`, `_memmove_0`, `_memset`, checked free, a max-size helper, and invalid-parameter failure.
- No raw VA/RVA pointer bytes for `0x004e6e50` were found, and the only rel32 call pattern hit is the known callsite. This supports a single inlined/source-owned caller route rather than a shared exported helper API.
- Current generated output already routes UID0004DN through `NexusTK/render/NewHumanImageLib.cpp` as a marker, avoiding a blank emitter while preserving no-standalone-body policy.

## Negative Evidence Summary

- No current evidence supports a standalone source-authored `NewHumanImageLibGrowCommandSideVector` helper body. The available names are descriptive documentation names; IDA still names the function `sub_4E6E50`.
- No current evidence supports a `NewHumanImageLib` class-method signature for this target. The receiver is the command-side storage subobject at `this + 13`, not the enclosing object.
- No current evidence supports direct generic `VectorHelpers` ownership. The helper has one NewHuman command-builder caller and no cross-module caller spread.
- No current evidence supports treating UID0004DN as padding, data, dead code, or a sibling/aggregate tail. The target is a valid function and its padding boundaries are exact.
- No local IDA names or types prove the command-side storage, side-record, or helper spelling. `entity_query kind=names` and scoped text searches found no NewHuman command type names.
- No exact by-memory child currently owns `BuildPartDrawCommand` as a first-draft C++ method page. The caller source route is accepted at class/file/cluster level but not final enough to absorb UID0004DN into a typed method body now.

## Ranked Ownership Analysis

1. Accepted: [UID:0000LR][NewHumanImageLib](../../../../../by-file/NewHumanImageLib.md) as direct canonical owner/emitter.
   Evidence: target has exactly one caller inside `BuildPartDrawCommand`, a NewHuman command-building method-family function; generated routing already projects UID0004DN to `NexusTK/render/NewHumanImageLib.cpp`.

2. Support context only: [UID:000092][NewHumanImageLib](../../../../../by-class/NewHumanImageLib.md).
   Evidence: the class owns the semantic method family, but target `ecx` is the command-side vector/ring subobject, so this page should support the route without becoming direct target metadata.

3. Fallback only: [UID:0000P3][VectorHelpers](../../../../../by-file/VectorHelpers.md).
   Evidence: project precedent uses VectorHelpers only as a compatibility-template fallback for NewHuman-local vector slow paths. UID0004DN's one-caller and storage-specific behavior are narrower than a shared utility source owner.

4. Rejected as direct target owner: [UID:00022R][ImageLibVectorSupportHelpers](../../../../../by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md).
   Evidence: the old mixed island is now a non-emitting split/index; UID0004DN is already its exact child.

5. Rejected: raw `NONE`/no-owner/no-emitter state.
   Evidence: current target already has a correct file-local marker route. Dropping owner/emitter would reintroduce a generated omission without improving source fidelity.

## Source Placement

Recommended source placement remains `NexusTK/render/NewHumanImageLib.cpp` through [UID:0000LR][NewHumanImageLib](../../../../../by-file/NewHumanImageLib.md). The emitted source for this exact UID should be a formal comment marker, not a real helper body.

The source-level behavior should eventually appear as typed command append logic in `NewHumanImageLib::BuildPartDrawCommand` when that method has source-quality command-side field names and an exact child page. Until then, UID0004DN should document the compiler-lowered capacity/rebalance support and route through the NewHuman file. A local/vector compatibility template remains a fallback only if the project later decides typed command-builder source cannot reproduce this out-of-line helper.

## First-Draft C++ Recommendation

Do not emit a standalone helper function body. If this report is accepted, replace the formal `RECONSTRUCTION_CPP CODE` block in the target with exactly this marker:

```cpp
// NewHumanImageLibGrowCommandSideVector is compiler-lowered command-side
// pointer-ring/vector growth support for NewHumanImageLib::BuildPartDrawCommand.
// Source behavior should live in typed BuildPartDrawCommand command-append
// logic, or in a local vector compatibility template if needed.
// Do not emit a standalone allocator/memmove/memset helper body here.
```

This block is intended for the formal target C++ block. It is not illustrative prose. It is the source-disposition marker that preserves generated output while rejecting a decompiler-shaped body.

## Final Recommendation

Implementation callback is complete and ready for supervisor execute review. The target is updated to `88/91`, owner/emitter/reconstructable/nested metadata is preserved, the refined marker is inserted, current MCP/caller/storage evidence is incorporated at report-level detail, and narrow support syncs were applied to NewHuman file/class/local-cluster/layout docs. Generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, and IDA DB were not manually edited; generated refresh was validator-owned through command `000000007513`.

## Recommended Target Doc Changes

For `by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md`:

- Change `COMPLETION:86` to `COMPLETION:88`.
- Change `CONFIDENCE:89` to `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000LR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LR`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- Replace the current formal marker with the exact marker in `First-Draft C++ Recommendation`.
- Update Item Summary to preserve the exact range, `sub_4E6E50` size `0x192` / 402 bytes, one `BuildPartDrawCommand` caller, command-side pointer-ring/vector growth/rebalance role, `this+13` / byte-offset `+0x34` receiver proof, 4-byte pointer-slot behavior, 9-byte side-record caller allocation, callee set, exact padding, NewHuman file route, VectorHelpers fallback-only route, and no-standalone-body proof.
- Add current MCP session evidence: `supervisor_recovery_20260705`, `server_health ok`, exact bytes/padding, unique signature, sole xref, target and caller decompile summaries, no VA/RVA pointer hits, no local command source names/types, and generated marker state.
- Historicalize old weaker wording that only said command-record names were "not final"; keep it as a confidence cap, not a reason to leave the target at `86/89`.

## Recommended Support Doc Changes

- `by-file/NewHumanImageLib.md`: add a narrow B004 UID0004DN source-quality sync if current content is not already considered same-or-greater detail. It should record the refreshed current MCP session, sole `BuildPartDrawCommand` callsite `0x004e2f7a`, `this+13` command-side state receiver, 4-byte pointer-slot grow/rebalance behavior, caller-side 9-byte side-record allocation, marker-only/no-standalone-body disposition, and unchanged file route. No score change recommended.
- `by-class/NewHumanImageLib.md`: add or refine a narrow support sentence if needed: UID0004DN supports the `BuildPartDrawCommand` method family but is not itself a class method because the receiver is the command-side storage subobject. No score change recommended.
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`: update the source-adjacent helper row if needed to include current UID0004DN evidence and the formal marker/no-standalone-body disposition. Keep the cluster non-emitting and do not change scores.
- `by-type/by-struct/NewHumanImageLibLayout.md`: optional narrow sync if accepted and if no stronger wording already exists. Current layout has `+0x34..+0x44` as generic list/sentinel state; add evidence that UID0004DN proves `BuildPartDrawCommand` uses this region as command-side pointer-ring/vector state with data pointer/capacity/mask-or-head/count fields. Do not over-rename the whole state unless reconciled with destructor/list evidence. No score change recommended.
- `by-file/VectorHelpers.md`: no edit expected. Current text already treats UID0004DN/UID0004DQ as NewHuman children that name VectorHelpers only as a compatibility-template fallback.
- `by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md`: no edit expected unless callback review finds stale split-parent wording. It already lists UID0004DN as a child and rejects whole-range direct VectorHelpers ownership.
- `by-memory/0x004e70a0-0x004e70e9.NewHumanImageLibAppendCommandRecord80.md`: no edit expected. UID0004DQ is sibling context only.

## Score And Metadata Recommendation

Target metadata recommendation and applied callback state:

| Field | Pre-callback | Applied | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `86` | `88` | Current MCP resolves caller context, receiver offset, pointer-slot behavior, generated marker state, no-pointer-route negative evidence, and implementation-ready target/support prose. |
| `CONFIDENCE` | `89` | `91` | Exact function/caller/boundary evidence and route rejection are strong. Confidence remains below final because exact command-side names, helper spelling, typed `BuildPartDrawCommand` source body, and vector-template policy remain inferred. |
| `CANONICAL_OWNER` | `0000LR` | `0000LR` | Sole caller and generated route remain NewHuman file-local. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Exact body is reconstructable as compiler-lowered marker support. |
| `EMITTER_UIDS` | `0000LR` | `0000LR` | Generated marker belongs in `NewHumanImageLib.cpp`. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No ordering repair discovered. |
| `Nested` | `0` | `0` | Exact child page, no nested child split. |

Support scores:

- [UID:0000LR][NewHumanImageLib](../../../../../by-file/NewHumanImageLib.md) remains `90/89`.
- [UID:000092][NewHumanImageLib](../../../../../by-class/NewHumanImageLib.md) remains `86/88`.
- [UID:00017R][NewHumanImageLibLocalMethodCluster](../../../../../by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md) score is unchanged.
- [UID:0001VF][NewHumanImageLibLayout](../../../../../by-type/by-struct/NewHumanImageLibLayout.md) score is unchanged after the narrow command-side state evidence sync.
- [UID:0000P3][VectorHelpers](../../../../../by-file/VectorHelpers.md) was not edited and remains unchanged.

## Open Questions With Attempted Resolution

1. Exact command-side storage field names.
   Attempted resolution: MCP caller decompile proves fields at object dword indexes 13-17 / byte offsets `+0x34..+0x44`, and the layout page currently names the region generically as list/sentinel state. No local IDA type/name and no exact `BuildPartDrawCommand` source page prove original field names. Resolution: document the pointer-ring/vector role and keep exact names as a confidence cap.

2. Exact side-record type and field names.
   Attempted resolution: caller decompile proves `operator new(9)`, an 8-byte copy, and a final byte copy into the slot record after `sub_4E6E50` grows storage. No `*Command*` names were found in scoped IDA name/text searches. Resolution: describe the 9-byte side-record behavior, but do not invent a source type.

3. Can typed `BuildPartDrawCommand` source replace the marker now?
   Attempted resolution: `BuildPartDrawCommand` is documented as a method-family row in file/class/cluster docs and MCP decompiles it clearly, but there is no exact child page or source-quality parameter/field naming for the method. Resolution: not yet. Keep UID0004DN marker-only and recommend a future exact `BuildPartDrawCommand` report if supervisor selects that method.

4. Should VectorHelpers own the target directly?
   Attempted resolution: checked current `VectorHelpers.md`, sibling vector slow-path reports, caller set, pointer-hit negatives, and generated route. Resolution: no direct VectorHelpers ownership. Keep fallback-only compatibility-template language.

5. Is a split/range repair needed?
   Attempted resolution: MCP confirms target start, exact size, no function at exclusive end, `0xcc` padding before successor, and successor `sub_4E6FF0` at `0x004e6ff0`. Resolution: no split/range/rename is recommended.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004DN-01 | Target exact function range is `0x004e6e50-0x004e6fe2`, size `0x192` / 402 bytes, with padding separated from the body. | Very high | MCP `lookup_funcs`, `get_bytes`, `int_convert`; current target docs. | Target `Range And Boundary` / `Evidence Notes`. | incorporate | applied |
| C-0004DN-02 | Current MCP session `supervisor_recovery_20260705` is healthy and should be cited as current evidence. | Very high | MCP `server_health` returned `status=ok`, Hex-Rays ready, auto-analysis ready. | Target `Evidence Notes`; report `Supporting Research`. | incorporate | applied |
| C-0004DN-03 | UID0004DN has exactly one code caller, `0x004e2f7a` in `sub_4E2EB0` / `BuildPartDrawCommand`. | Very high | MCP `xrefs_to`, `xref_query`, `callees`, caller `decompile`. | Target `Behavior`; file/class/cluster support prose. | incorporate | applied |
| C-0004DN-04 | Caller passes `this + 13` and `1`, proving the helper receiver is command-side storage at object byte offset `+0x34`, not an ordinary class-method receiver. | High | Caller decompile at `0x004e2f7a`: `sub_4E6E50(this + 13, (void *)1)`. | Target `Behavior` / `Source Placement`; class support note; layout optional note. | incorporate | applied |
| C-0004DN-05 | Target body grows/rebalances 4-byte pointer slots with allocation, `_memmove_0`, `_memset`, checked free, and begin/capacity updates. | Very high | Target decompile, disasm, and `callees`; bytes use `4 * capacity` and shifts by 2. | Target `Behavior` / `Evidence Notes`; Item Summary. | incorporate | applied |
| C-0004DN-06 | Caller-side command records are 9-byte side records allocated lazily after the grow path. | High | Caller decompile allocates `operator new(9u)`, copies 8 bytes plus one byte, and increments `this[17]`. | Target `Behavior`; support docs if edited. | incorporate | applied |
| C-0004DN-07 | No VA/RVA pointer hits and unique rel32 call pattern support the single caller route. | High | MCP `find_bytes` found zero `50 6E 4E 00` / `50 6E 0E 00` hits and one rel32 call pattern hit at `0x004e2f7a`; signature unique. | Target `Evidence Notes` / `Negative Evidence`. | incorporate | applied |
| C-0004DN-08 | No local IDA source names or command UDT names were found for the helper, storage, or records. | Medium-high | `entity_query kind=names`, `func_query`, and scoped `search_text` found only NewHuman RTTI/vtable and CRT command-line names, not command helper/source types. | Target `Reconstruction Notes`; `Open Questions With Attempted Resolution`. | incorporate | applied |
| C-0004DN-09 | Direct owner/emitter should remain `0000LR`, with class `000092` as semantic support only. | High | One NewHuman caller, current generated route, by-file/by-class docs, receiver subobject evidence. | Target metadata and `Source Placement`; support docs. | incorporate | applied |
| C-0004DN-10 | Direct generic VectorHelpers ownership is invalid for UID0004DN; VectorHelpers is fallback-only. | High | One NewHuman caller, current `VectorHelpers.md`, B011/B007/B005 sibling precedents. | Target `Source Placement`; `by-file/VectorHelpers.md` already-present/fallback note. | reject-invalid | applied |
| C-0004DN-11 | Standalone decompiler-shaped helper C++ is invalid; formal marker-only output is the source-quality route. | High | Target/caller decompile is compiler/vector allocation lowering; no source names; source behavior belongs in typed `BuildPartDrawCommand` when available. | Target formal `RECONSTRUCTION_CPP CODE` and `Reconstruction Notes`. | reject-invalid | applied |
| C-0004DN-12 | B011 UID00022R split/index state remains valid support context and does not replace UID0004DN target-specific review. | High | Executed B011 split report and current split-parent doc; current MCP rechecked UID0004DN. | Target `Cross-References`; split-parent support no-change note. | incorporate | applied |
| C-0004DN-13 | Target score can move to `88/91` while original helper spelling/type names remain confidence caps. | High | Current MCP evidence resolves objective blockers but not original names/typed `BuildPartDrawCommand` body. | Target metadata; `Score And Metadata Recommendation`. | incorporate | applied |
| C-0004DN-14 | Layout support may need a narrow `+0x34..+0x44` command-side pointer-ring note, but not a broad rename. | Medium-high | Caller passes `this + 13`; layout currently labels `+0x34..+0x44` as generic list/sentinel state; destructor/list evidence still exists. | Optional `by-type/by-struct/NewHumanImageLibLayout.md` support section. | incorporate | applied |
| C-0004DN-15 | Generated output should refresh only through validators after callback and should remain marker-only, not a helper body. | High | Current `NewHumanImageLib.cpp` UID0004DN marker; workflow/generated-file rules. | Callback checklist; generated freshness expectation. | not-applicable | applied |

## Validator Results

Historical report-only Gate 1 pass before implementation callback:

- No scoped validators were run during the report-only pass.
- No `execute_report`, dry-run/probing execute variant, registry lifecycle command, report move, archive move, or lifecycle command was run during report-only work.
- No generated refresh was requested or manually performed during report-only work.

Implementation callback scoped validators, all run from `source-3/project-documentation`:

| Command ID | Timestamp | Command | Exit | ok | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `000000007509` | `2026-07-06T01:05:02-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md --apply --queue-timeout 240` | `0` | `1` | Updated UID0004DN completion/confidence to `88/91`; `generated_refresh: deferred`. |
| `000000007510` | `2026-07-06T01:05:11-04:00` | `python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240` | `0` | `1` | Support validator passed; `generated_refresh: deferred`. |
| `000000007511` | `2026-07-06T01:05:21-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 240` | `0` | `1` | Support validator passed; warning `missing_ref_uid 0003UD` appeared twice as pre-existing/unrelated referenced UID state; `generated_refresh: deferred`. |
| `000000007512` | `2026-07-06T01:05:29-04:00` | `python .\tools\validator.py --mode file --file by-type/by-struct/NewHumanImageLibLayout.md --apply --queue-timeout 240` | `0` | `1` | Support validator passed; projected stats rows updated by validator; `generated_refresh: deferred`. |
| `000000007513` | `2026-07-06T01:05:40-04:00` | `python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated` | `0` | `1` | File-route validator passed; `generated_refresh: completed`; generated refresh command/timestamp match this command. Validator emitted broad generated metadata warnings/notes such as `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code`; no manual generated edit was made. |

Generated freshness:

- Read-only inspection of `auto-generated/NexusTK/render/NewHumanImageLib.cpp` shows header `validator-command-id: 000000007513`, `validator-refreshed-at: 2026-07-06T01:05:40-04:00`, and `validator-refresh-source: foreground-generated-refresh`.
- UID0004DN appears at lines 227-232 as `Completion:88 | Confidence:91` with the accepted command-side marker and no standalone helper body.
- Generated refresh also performed validator-owned generated report/metadata side effects, including `auto-generated/-ag-file-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, generated metadata reports, `validator.ini` registry rebuild, `project-level/-auto-completion-stats.md` projected stats updates, and validator autogen backups. B004 did not edit those files manually.

Lifecycle command restriction confirmation:

- B004 did not run `execute_report`, any execute dry-run/probe/status variant, registry lifecycle command, manual report move, archive move, or manual generated/coverage/validator-state edit.

## Changed Files

Manually edited by B004 during the implementation callback:

- `by-memory/0x004e6e50-0x004e6fe2.NewHumanImageLibGrowCommandSideVector.md`
- `by-file/NewHumanImageLib.md`
- `by-class/NewHumanImageLib.md`
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`
- `by-type/by-struct/NewHumanImageLibLayout.md`
- `tools/leaser/Agents/Agent-B004/research/0004DN-NewHumanImageLibGrowCommandSideVector-source-quality.md`

Read-only inspected, not manually edited:

- `auto-generated/NexusTK/render/NewHumanImageLib.cpp` after validator refresh.
- Generated/tracker/coverage files listed in `Evidence Checked`.
- Executed reports listed in `Evidence Checked`.

Validator-owned side effects from scoped validators:

- `auto-generated/NexusTK/render/NewHumanImageLib.cpp` refreshed by command `000000007513`.
- Generated reports/metadata were refreshed by command `000000007513`, including generated coverage/report metadata and memory coverage output noted in validator output.
- `tools/validator.ini`, `project-level/-auto-completion-stats.md`, and `tools/validator_autogen_backup/...` were touched only by validator-owned scoped validation/generation, not by manual B004 edits.

Explicitly not manually edited or run by B004:

- No generated files edited.
- No coverage reports or `-coverage-report.md` files edited.
- No validator state, queue state, supervisor ledgers, lifecycle headers/footers, archives, or IDA DB edited.
- No `execute_report`, dry-run/probing variants, registry lifecycle commands, manual moves, or archive commands run.
- No `by-file/VectorHelpers.md`, `by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md`, or `by-memory/0x004e70a0-0x004e70e9.NewHumanImageLibAppendCommandRecord80.md` edit was made; no direct contradiction was found.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Historical status: the initial report-only artifact stopped at Gate 1 review and performed no by-* edits; supervisor later passed Gate 1 and authorized this callback.
- [x] Target/support docs to update identified. Target required; support candidates are NewHuman file, NewHuman class, local cluster, optional layout, and no-change/fallback VectorHelpers/split-parent context.
- [x] Current target state and actual evidence checked recorded. Historical report-only pre-callback target was `86/89`, owner/emitter `0000LR`, marker-only, generated marker present; post-callback current target is `88/91`.
- [x] Claim And Incorporation Ledger updated with destination and report-only verification state for every accepted claim during Gate 1; callback pass now updates those rows to applied verification states.
- [x] Metadata/score changes to apply recorded: target `88/91`, keep owner/emitter/reconstructable/optional/nested unchanged.
- [x] Score-limiting blockers researched to attempted resolution: exact helper/source names, command-side storage fields, 9-byte side-record type, exact `BuildPartDrawCommand` body, and vector-template policy remain evidence-backed caps, not uninvestigated blockers.
- [x] Owner/emitter/reconstructable changes resolved: keep `0000LR`/`0000LR`, keep `TRUE`, reject class-method/direct-VectorHelpers/no-owner alternatives.
- [x] Split/rename/new-child changes resolved: no split, rename, or new child recommended; range boundaries are exact.
- [x] Source-placement, range/split/padding/reclassification, and IDA rename/type/comment changes resolved: no IDA DB edits; no reclassification; target remains exact function body with marker route.
- [x] First-draft C++ or no-code proof recorded: formal marker-only block recommended; standalone helper body rejected with MCP proof.
- [x] Third-party import directive not applicable. The target is project compiler/vector lowering around NewHuman command building, not imported third-party source.
- [x] Exact target/support doc facts to incorporate at report-level detail recorded: current MCP session, exact bytes/range/padding, caller/callee sets, target/caller decompile, pointer hits, generated marker, support route.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: B011 split context, stale weaker marker-only explanation, direct VectorHelpers rejection, class-method rejection, no local names/types, no pointer hits.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale/non-authoritative. `rg` saw project-level/Wave artifacts during broad text searches, but current report uses current by-* docs, executed B reports, generated current rows, and live MCP evidence only.
- [x] Open questions closed or documented as evidence-backed unresolved caps.
- [x] Validators to run during callback listed with scoped commands.
- [x] Generated refresh expected after callback documented: `auto-generated/NexusTK/render/NewHumanImageLib.cpp` should remain marker-only for UID0004DN, with refreshed target score/marker if validators refresh generated output.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: supervisor callback cited Gate 1 SHA256 `B80C4DCCC04A33C04BEE67DF5483C8CEDD10318FB84E237290D3BEBE7FA1384B`.
- [x] Lease only the exact by-* files to edit immediately before editing, and release after the edit/validator batch. Proof: B004 leased target, NewHuman file, NewHuman class, local cluster, and layout pages before editing. After that lease expired during review, B015 briefly leased cluster/layout; B004 waited until B015 cleared, reacquired B004 leases for the same five edited docs before validators, and released all five with `leaser.py ... unlease` success. Post-release `current_leases.md` showed no active B004 leases, only unrelated B011 `JpegScreenshotWriter`.
- [x] Apply target metadata `COMPLETION:88`, `CONFIDENCE:91`, preserving `CANONICAL_OWNER:0000LR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LR`, blank optional position, and `Nested:0`. Proof: target validator `000000007509`, exit `0`, `ok: 1`, recorded `completion_update 0004DN ... 88` and `confidence_update 0004DN ... 91`.
- [x] Insert the exact formal marker from `First-Draft C++ Recommendation`. Proof: target and generated `NewHumanImageLib.cpp` UID0004DN marker contain the accepted command-side pointer-ring/vector marker and no helper body.
- [x] Incorporate target facts at report-level detail: current MCP session, exact range/padding/body, unique signature, caller decompile, target decompile, pointer-hit negatives, no name/type proof, source placement, rejected alternatives, score rationale, and generated marker state. Proof: target `Status`, `Range And Boundary`, `Behavior`, `Evidence Notes`, `Source Placement`, `Reconstruction Notes`, and `Score Rationale` were updated and validated by `000000007509`.
- [x] Apply narrow support prose if same-or-greater detail is missing: NewHuman file, NewHuman class, local cluster, optional layout. Do not edit VectorHelpers, split-parent, or UID0004DQ unless direct contradiction is found. Proof: edited `by-file/NewHumanImageLib.md`, `by-class/NewHumanImageLib.md`, `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`, and `by-type/by-struct/NewHumanImageLibLayout.md`; did not edit VectorHelpers, split-parent, or UID0004DQ because no direct contradiction was found.
- [x] Claim And Incorporation Ledger updated with `applied`, `already-present`, `excluded-with-reason`, or `blocked` verification states for every accepted claim. Proof: C-0004DN-01 through C-0004DN-15 now use callback verification states; no row is blocked.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: target metadata and formal marker applied; owner/emitter/reconstructable/nested unchanged; no split/rename/new-child; support scores unchanged; direct VectorHelpers/class-method/no-owner/standalone body rejected in prose.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs retain B011 split context, VectorHelpers fallback-only status, direct class-method/no-owner rejection, no VA/RVA pointer hits, no local names/types, and source-body confidence caps.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale after implementation. Proof: command-side field names, 9-byte side-record type/name, exact typed `BuildPartDrawCommand` body, and vector-template policy remain evidence-backed caps in target and report.
- [x] Scoped validators run for every edited by-* file, with command id, timestamp, exit code, ok count, warnings/errors, and generated refresh state recorded. Proof: validators `000000007509` through `000000007513`, all exit `0`, all `ok: 1`; cluster validator warning `missing_ref_uid 0003UD` recorded; file route generated refresh completed at `000000007513`.
- [x] Generated `auto-generated/NexusTK/render/NewHumanImageLib.cpp` freshness checked read-only after validation if generated refresh occurs; no manual generated edit. Proof: read-only inspection shows header `validator-command-id: 000000007513`, `validator-refreshed-at: 2026-07-06T01:05:40-04:00`, and UID0004DN `Completion:88 | Confidence:91` marker lines 227-232.
- [x] Remaining unapplied accepted items listed with exact blocker, or explicitly state none remain. Proof: none remain; no blocked ledger rows.
- [x] Confirm no generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, or IDA DB were manually edited, and no `execute_report`/lifecycle/archive/manual move command was run. Proof: only scoped validators produced validator-owned generated/registry/report side effects; B004 made no manual generated/coverage/validator-state/lifecycle edits and ran no lifecycle/report execution command.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000007527","destination_path":"executed-b-agent-research/B004/0004DN-NewHumanImageLibGrowCommandSideVector-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0004DN-NewHumanImageLibGrowCommandSideVector-source-quality.md","timestamp":"2026-07-06T04:18:32-04:00","uid":"0004DN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
