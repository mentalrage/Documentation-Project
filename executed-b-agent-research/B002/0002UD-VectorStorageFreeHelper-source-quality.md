** TARGET-REPORT-UID:0002UD **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0002UD VectorStorageFreeHelper Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002UD] `by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md` assigned to [UID:0000P3] `VectorHelpers`, keep it reconstructable and emitted through `0000P3`, raise the target from `85/88` to `87/90`, and replace the empty formal C++ block with a source-disposition marker.
- Final disposition: this is an exact shared vector-storage cleanup helper, not fitting-room-private code, not an `ItemCatalog` method, not a runtime-only ignore, and not a standalone source-quality helper body.
- Required action: after supervisor acceptance, update only the target page and [UID:0000P3] `VectorHelpers.md`; generated `auto-generated/NexusTK/util/VectorHelpers.cpp` must refresh through the validator, not manual edits.
- Confidence: strong for behavior, boundary, owner/emitter route, and marker/no-standalone-body disposition; medium-high for exact original helper/type spelling because no UDT or source symbol exists.

## Supporting Research

## Target

- Target UID: `0002UD`
- Target path: `by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> Not-Covered Files - Reconstructable, row `85/88`, combined `86.5`, reconstructable `true`, reports `0`.
- Current supervisor classification: report-only source-quality research for shared vector-storage cleanup helper, VectorHelpers owner, ItemCatalog caller, handler/unwind fan-in, allocation-header validation, type/signature, and first-draft C++ readiness.
- Current scores and parent state: target `85/88`; direct owner [UID:0000P3] `VectorHelpers` is `86/86`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, `CANONICAL_OWNER:FILE`.

## Current Target State

- Existing metadata: `CANONICAL_OWNER:0000P3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P3`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP CODE`.
- Existing owner/emitter/reconstructable state: already correctly routes through [UID:0000P3] `VectorHelpers`; generated output currently shows [UID:0002UD] as an `Empty Emitter Marker` in `auto-generated/NexusTK/util/VectorHelpers.cpp`.
- Existing C++/emitter state: the target still says "leave blank until the exact helper type/signature reaches 95/95." That is stale against current `by-structure.md`, which uses `(COMPLETION + CONFIDENCE) / 2 > 85` plus confirmed emitter route as the minimum C++ eligibility gate. The target already clears that minimum at `86.5`.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: final source signature and helper type names remain descriptive rather than original-proof; however, current evidence is sufficient for a formal source-disposition marker. A standalone helper body remains blocked because it would turn compiler/template vector cleanup into handwritten `VectorHelpers.cpp` scaffolding.
- Related target/support docs checked: [UID:0000P3] `VectorHelpers`, [UID:0000WV] `ItemCatalogLookup`, [UID:0002EE] mixed fitting-room helper island, [UID:0002UE] sibling vector destroy/free marker precedent, `client_containers`, `proposed-source-tree`, [UID:0002E1] MSVC vector throw helpers, and prior executed B reports for [UID:0001B2], [UID:00017U], [UID:00030Q], and [UID:00030Z].

## Executive Recommendation

Keep the route:

```text
[UID:0002UD] -> [UID:0000P3] VectorHelpers -> NexusTK/util/
```

Recommended metadata:

| Field | Current | Recommended |
| --- | ---: | ---: |
| `COMPLETION` | `85` | `87` |
| `CONFIDENCE` | `88` | `90` |
| `CANONICAL_OWNER` | `0000P3` | `0000P3` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000P3` | `0000P3` |
| `RECONSTRUCTION_CPP CODE` | blank | formal marker below |

Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
// Emitted code for this vector-storage cleanup helper is covered by typed
// caller-owned vector declarations, or by a [UID:0000P3] VectorHelpers
// compatibility template if the recovered typed source cannot regenerate this
// out-of-line MSVC-style vector storage free helper.
// Do not emit a standalone decompiler-shaped VectorStorageFreeHelper body here.
```

This resolves the empty-emitter/source-quality blocker without inventing a concrete `VectorStorageFreeHelper(_DWORD *this)` source function as original project code.

## Supervisor Active Recheck

- Active instruction: `B002-report-0002UD-VectorStorageFreeHelper-20260702`, report-only research, write `tools/leaser/Agents/Agent-B002/research/0002UD-VectorStorageFreeHelper-source-quality.md`, do not edit target/support docs or run execute-report lifecycle commands.
- Split repair: not required. `0x00423810-0x00423860` is already an exact function split from [UID:0002EE] mixed helper island.
- Source-bearing children in scope: only this exact helper. Related sibling/helper pages were checked as support and precedent; no new child page is needed.

## Inference Research Guidance Check

- `by-structure.md` requires direct semantic owner and emitter separation. [UID:0000P3] remains the direct utility/template owner; `ItemCatalog` is a consumer; [UID:0002EE] is only the mixed physical island.
- Existing documentation was treated as a lead and rechecked through current IDA MCP session `supervisor_resume_20260629`.
- Direct IDA facts: function boundary, decompile/disassembly behavior, xrefs, callees, lack of data xrefs/pointer encodings, and lack of UDT type matches.
- Documentation evidence: current target/support pages and executed vector-helper B reports.
- Inference: final source likely came from typed vector declarations or template support rather than a handwritten helper body. The marker is a documentation/emitter disposition, not proof of original source comments.
- No Wave2/Wave3 source instructions were used as authority. Historical generated names such as `sub_423810` are retained only as raw search labels.

## Heuristic / Inference Reanalysis And Validation

Source-quality issue resolution:

| Issue | Best current resolution | Evidence and validation |
| --- | --- | --- |
| Helper role | `VectorStorageFreeHelper`: MSVC-style vector storage free/clear for a three-pointer header. | MCP decompile/disassembly shows `ECX` vector header, null-begin fast exit, `begin/endOfStorage` span, large-allocation metadata validation, free wrapper call, and triple clear. |
| Signature | `void __thiscall(VectorStorageHeader *storage)` as descriptive source contract. | IDA renders `void __thiscall(_DWORD *this)`; disassembly saves `ECX` in `ESI`, uses `[esi]`, `[esi+4]`, `[esi+8]`, and returns with plain `retn`. |
| Field names | `begin`, `end/current`, `capacityEnd/endOfStorage`. | This is the same three-pointer vector triplet pattern used by sibling VectorHelpers and ItemCatalog temporary vectors. This target only reads `begin` and `capacityEnd` before clearing all three slots; the middle slot is still part of the contract. |
| Allocation policy | MSVC aligned large-block storage: direct free below `0x1000`; for large storage load raw base at `begin - 4`, validate front padding <= `0x1f`, add `0x23` to free size, free raw base. | MCP disassembly at `0x00423821-0x0042383d`; `int_convert` verified `0x1000` = 4096, `0x1f` = 31, `0x23` = 35. |
| Owner route | Keep [UID:0000P3] `VectorHelpers`. | Ordinary calls are two cleanup calls inside [UID:0000WV] `ItemCatalog::GetItemByIndex`, while 24 additional xrefs are cleanup/unwind metadata spread across unrelated functions. Utility ownership is more faithful than consumer ownership. |
| C++ readiness | Eligible for a formal marker, not a standalone body. | Current score/emitter gate is cleared; prior VectorHelpers reports use marker disposition for compiler/template helper bodies; exact original helper name/type/header policy is not recovered. |
| Generated empty marker | Should be replaced by the formal source-disposition marker after accepted implementation and validation. | Current generated `VectorHelpers.cpp` header is validator command `000000004305`, refreshed `2026-07-02T05:58:28-04:00`, and contains [UID:0002UD] as `Empty Emitter Marker`. |

Rejected alternatives:

- Assign to `ItemCatalog`: rejected. The two ordinary call sites clean a local copied pointer-vector in `ItemCatalog::GetItemByIndex`, but the function body has no item-catalog fields, strings, category logic, or object-specific state.
- Assign to [UID:0002EE] mixed aggregate: rejected. [UID:0002EE] is intentionally `RECONSTRUCTABLE:FALSE` and crosses fitting-room category helpers, StringUtil/SSO helpers, vector helpers, CRT/UCRT support, EH chunks, and padding.
- Assign to [UID:000051] `FittingRoomDialogItemState`: rejected. Unlike sibling [UID:0002UE], this target has cross-subsystem cleanup/unwind fan-in and ordinary use through `ItemCatalog` temporary storage, not one item-state field.
- Reclassify `RECONSTRUCTABLE:FALSE`: rejected. The helper is a concrete emitted vector storage cleanup body needed either through typed source regeneration or compatibility-template support.
- Emit a standalone helper body: rejected. It would preserve decompiler-shaped `_DWORD *` mechanics and invented helper naming as product source, while the more plausible original source is typed vector declarations or template support.
- Leave the C++ block blank under the old `95/95` sentence: rejected as stale. The active project gate permits formal C++ once average score exceeds `85` and the emitter route is confirmed; a marker is the appropriate non-body C++.

## Evidence Standards Used

- IDA MCP current session evidence: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, `analyze_function`, `xref_query`, `find_bytes`, `type_query`, and `int_convert`.
- Current by-* documentation: target, direct owner, caller, mixed aggregate, sibling cleanup helper, runtime vector throw helper, container/source-tree support docs.
- Generated/read-only evidence: research tracker row and generated `auto-generated/NexusTK/util/VectorHelpers.cpp` marker/header.
- Prior executed B reports: marker/no-standalone-body precedents for `0001B2`, `00017U`, `00030Q`, and `00030Z`.
- Evidence strength: strong for binary behavior and owner route; the only cap is exact original source spelling/header/template policy.

## Evidence Checked

IDA MCP/manual checks performed on database `supervisor_resume_20260629`:

- `server_health`: `status:"ok"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- `lookup_funcs`: `0x00423810` -> `sub_423810`, size `0x50`; `0x0042385f` still inside; `0x00423860` not a function; caller sites `0x00422720` and `0x00422731` both inside `sub_4226D0`; `0x005c7526` -> `sub_5C7526`, size `0xe`; `0x005cd607` -> `__invalid_parameter_noinfo_noreturn`, size `0x1d`.
- `decompile` / `disasm` for `0x00423810`: full 27-instruction body, no strings, two callees, basic block complexity 3.
- `xrefs_to(0x00423810)`: 26 code xrefs. Ordinary calls at `0x00422720` and `0x00422731` in `sub_4226D0`; remaining xrefs are cleanup/unwind-style entries at `0x005f6bc1`, `0x005f6d32`, `0x005f77fe`, `0x005f9b7b` through `0x005f9bc1`, `0x005f9fbc`, `0x005fd25b`, `0x005fdb73`, `0x005ffd9a`, `0x005ffdb0`, `0x005ffdd1`, `0x00600292`, `0x00602cbb`, `0x00602cc6`, `0x0060a9fc`, `0x0060bf29`, `0x0060bf37`, `0x0060bf45`, `0x0060bfd7`, and `0x0060bfdf`.
- `callees(0x00423810)`: only `sub_5C7526` and `__invalid_parameter_noinfo_noreturn`.
- `decompile` / `disasm` for `0x004226d0`: confirms `ItemCatalog::GetItemByIndex` copies a category-node pointer vector into a stack/local triple through `sub_421290`, indexes it when in range, and calls `sub_423810` on both success and failure cleanup paths.
- `xref_query` data refs to `0x00423810`: total `0`, no data xrefs.
- `find_bytes` for VA/RVA encodings `10 38 42 00` and `10 38 02 00`: no matches.
- `type_query` for UDT filters `*Vector*`, `*ItemCatalog*`, and `*Category*`: no matching local UDTs returned.
- `int_convert`: verified `0x50` = 80, `0x1000` = 4096, `0x1f` = 31, `0x23` = 35, `0x220` = 544, and `0x224` = 548.

Docs/generated reports checked:

- `by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md`
- `by-file/VectorHelpers.md`
- `by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md`
- `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md`
- `by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md`
- `by-memory/0x00421500-0x0042151a.MsvcVectorThrowHelpers.md`
- `by-project-structure/proposed-source-tree.md`
- `by-meta/client_containers.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/NexusTK/util/VectorHelpers.cpp`

Existing report search terms:

- `0002UD`, `0x00423810`, `00423810`, `VectorStorageFreeHelper`, `sub_423810`, `VectorStorageFree`, `VectorHelpers`.
- Relevant matches opened: executed [UID:0001B2] B006 empty-emitter marker report, [UID:00017U] B008 RecordVector marker report, [UID:00030Q] B010 grow-insert source-quality report, [UID:00030Z] B001 copy-construct source-quality report. No prior B report for this exact UID was found.

Negative checks:

- No data refs or VA/RVA pointer byte hits for the helper start.
- No UDT names recovered for `Vector`, `ItemCatalog`, or `Category`.
- No feature-specific strings, globals, vtables, resources, or protocol logic inside the target body.
- No split/merge need: function end is confirmed at `0x00423860`, and [UID:0002EE] records `0x00423805-0x00423810` and `0x00423860-0x00423870` as `0xcc` alignment.

Failed/unavailable/skipped checks:

- MCP incident during evidence collection: after a successful `server_health` response, an overpacked local PowerShell wrapper that queued several exact-address MCP calls timed out after 60 seconds, and an immediate `lookup_funcs` retry reported `Unable to connect to the remote server`. Read-only incident checks showed `Test-NetConnection 127.0.0.1:13337` failed while `idalib-mcp` and Python worker processes still existed. After a 10-second wait, the listener recovered and `Test-NetConnection` succeeded. The final evidence above was then rerun with single narrow MCP calls against session `supervisor_resume_20260629`.
- No validator was run because this was report-only and no by-* files were edited.
- No local PE broad scan was needed after current MCP supplied exact xref/data/byte evidence.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | [UID:0002UD] remains directly owned/emitted by [UID:0000P3] `VectorHelpers`. | Strong | MCP xrefs, target page, `VectorHelpers.md`, container/source-tree docs. | `by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md` metadata/status/ownership sections and `by-file/VectorHelpers.md` Covered Helpers / `VectorStorageFreeHelper Source-Disposition Notes`. | incorporate | already-present |
| C2 | Raise target to `87/90`. | Strong | Current MCP closes body/xref/type/C++ gate blockers; remaining uncertainty is only exact original spelling/header policy. | Target metadata headers and `Score And Assignment Audit`. Reconciliation found the target already at `COMPLETION:87` and `CONFIDENCE:90`. | incorporate | already-present |
| C3 | Replace empty formal C++ with the exact source-disposition marker, not a body. | Strong | Current C++ gate, generated empty marker, prior `0001B2`/`00017U` marker precedents. | Target formal `RECONSTRUCTION_CPP CODE` block. Reconciliation found the accepted exact marker already present in the target; generated output also now shows marker text rather than an empty marker. | incorporate | already-present |
| C4 | Best signature is descriptive `void __thiscall(VectorStorageHeader *storage)` over `begin/end/capacityEnd`. | Strong descriptive, not original-proof | MCP decompile/disasm and ItemCatalog local triple use. | Target `Signature And State Contract`, `Raw Code Evidence`, and `Open Questions`. | incorporate | already-present |
| C5 | `ItemCatalog` is a consumer, not the owner. | Strong | Only ordinary calls are stack/local cleanup in `sub_4226D0`; no item-catalog state inside helper. | Target `Raw Code Evidence` and `Ownership And Rejected Alternatives`; support `VectorStorageFreeHelper Source-Disposition Notes`. | incorporate | already-present |
| C6 | [UID:0002EE] stays adjacent mixed aggregate context only. | Strong | Aggregate metadata is `RECONSTRUCTABLE:FALSE`, mixed exact-child inventory. | Target status, open questions, ownership rejection; support note rejects aggregate ownership. No [UID:0002EE] metadata change was needed. | incorporate | already-present |
| C7 | No data/pointer route exists for callback/vtable/table ownership. | Strong | `xref_query` data total 0; `find_bytes` VA/RVA patterns no matches. | Target `Raw Code Evidence`, `Ownership And Rejected Alternatives`, and `Score And Assignment Audit`; support source-disposition note. | incorporate | already-present |
| C8 | Exact original helper/type/source spelling remains unresolved but no longer blocks marker emission. | Medium-high | Type query returned no UDTs; no symbols; source-tree supports `VectorHelpers.h`/template support. | Target `Signature And State Contract`, `Open Questions`, `Source-Disposition Marker`, and score rationale; support note records inferred header/template policy. | incorporate | already-present |

## Positive Evidence Summary

- Direct facts supporting recommendation: exact `0x00423810-0x00423860` function, 80 bytes (Verified with `int_convert`), thiscall-style vector-header receiver, free-wrapper/invalid-parameter callees only, no data refs, no pointer-table route, and no UDT symbols.
- Corroborating documentation: [UID:0000P3] already groups shared vector/template helpers under `NexusTK/util/`; `client_containers` says feature modules should not absorb generic vector machinery; proposed tree lists `util/VectorHelpers.h`.
- Strongest inference chain: a helper that only frees/clears a three-pointer vector header, is used by a local ItemCatalog temporary vector and many cleanup/unwind records across unrelated source families, and has no feature-specific state is best represented as shared vector/template support. Because exact original source would likely be typed vector declarations/template emission, generated output should carry a marker rather than a handwritten helper body.

## IDA MCP Facts

- Function/range facts: `sub_423810`, start `0x00423810`, size `0x50`, exclusive end `0x00423860`; `0x0042385f` is inside, `0x00423860` is not a function.
- Data/table/padding facts: no data xrefs to `0x00423810`; no `10 38 42 00` or `10 38 02 00` pointer byte hits. Target docs and aggregate docs record `0xcc` padding before and after.
- Xref facts: 26 code xrefs; only two ordinary source calls in `sub_4226D0`; 24 additional cleanup/unwind metadata xrefs across unrelated functions.
- Vtable/global/type facts: no vtable/data route found; no `*Vector*`, `*ItemCatalog*`, or `*Category*` UDT names in current type query.
- Negative IDA facts: no strings, no globals, no feature fields except caller-local vector headers, no callback-table evidence.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00423810-0x00423860` | [UID:0002UD] `by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md` | Shared vector storage free/clear helper | TRUE | [UID:0000P3] `VectorHelpers` | current `85/88`, recommended `87/90` | exact target; marker recommended |
| `0x004226d0-0x0042273f` | [UID:0000WV] `ItemCatalogLookup` second method | Ordinary caller using local copied pointer vector | TRUE | [UID:0000KD] `ItemCatalog` | `86/89` | consumer only |
| `0x00423000-0x00423af4` | [UID:0002EE] mixed helper island | Physical aggregate/context | FALSE | NONE | `85/87` | adjacent mixed container, not owner |
| `0x00423870-0x004238e3` | [UID:0002UE] sibling vector destroy helper | Item-state equipment-entry vector destroy/free marker precedent | TRUE | [UID:000051] `FittingRoomDialogItemState` | `88/90` | sibling; not owner for this target |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00422720` | `sub_4226D0` -> `sub_423810` | Successful `ItemCatalog::GetItemByIndex` cleanup of local copied vector before returning selected item pointer. |
| `0x00422731` | `sub_4226D0` -> `sub_423810` | Out-of-range cleanup of the same local copied vector before returning null. |
| `0x005f6bc1`, `0x005f6d32` | code xrefs associated with `sub_422020` / `sub_422BA0` contexts | Cleanup/unwind metadata fan-in from fitting-room constructor/loader contexts. |
| `0x005f77fe` through `0x0060bfdf` | code xrefs in unrelated function records including `0x428d70`, `0x450ca0`, `0x4563c0`, `0x49bd30`, `0x4a7e70`, `0x4daec0`, `0x4dfd10`, `0x511db0`, `0x5a8cf0`, `0x5c2ac0`, `0x5c4bd0` | Broad handler/unwind cleanup fan-in; supports reusable vector-template cleanup rather than a single feature owner. |
| `0x005c7526` | callee `sub_5C7526` | Shared free/delete wrapper. |
| `0x005cd607` | callee `__invalid_parameter_noinfo_noreturn` | Large-allocation metadata corruption guard. |

## Documentation Evidence And IDA Status

- Existing docs supporting conclusion: target page already records exact behavior, ordinary ItemCatalog callers, broad handler/unwind fan-in, allocation-header validation, and `VectorHelpers` owner. [UID:0000P3] already lists this target as shared vector-storage cleanup support. `client_containers` and `proposed-source-tree` support generic container placement under `util/VectorHelpers.h`.
- Existing docs stale/incomplete: target's "leave blank until 95/95" sentence is stale; blank C++ is now an empty-emitter problem rather than a correct final state. Target lacks the current negative data/pointer/type checks and lacks an implementation-ready formal marker.
- Generated/coverage state: research tracker row has reports `0`; generated `VectorHelpers.cpp` currently contains [UID:0002UD] as `Empty Emitter Marker` at `85/88`. Generated files are read-only and should refresh after validator runs in a callback.

## Ranked Ownership Analysis

### 1. [UID:0000P3] `VectorHelpers`

- Evidence for: generic vector-header cleanup body; cross-context handler/unwind fan-in; existing utility/container docs; `NexusTK/util/VectorHelpers.h` source-tree placement; sibling vector helper reports reject feature-local ownership and standalone helper bodies.
- Evidence against: exact original header/source split is not recovered; generated output is a `.cpp` staging file even though final source may be header/template-driven.
- Decision: keep as direct owner and emitter. The caveat limits standalone C++ body quality, not ownership.

### 2. [UID:0000WV] / `ItemCatalog`

- Evidence for: the only two ordinary source calls are in `ItemCatalog::GetItemByIndex`.
- Evidence against: both calls clean a stack/local copied vector triple; the helper body has no `ItemCatalog` fields, category-node logic, strings, globals, resources, or object-specific behavior; 24 additional code xrefs are broad cleanup/unwind fan-in.
- Decision: consumer only; do not assign owner/emitter to `ItemCatalog`.

### 3. [UID:0002EE] mixed fitting-room helper island

- Evidence for: physical containment in `0x00423000-0x00423af4`.
- Evidence against: the aggregate is explicitly reviewed as `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`; it mixes fitting-room category helpers, string/vector/DAT support, CRT/UCRT support, EH chunks, and padding. Exact children carry ownership.
- Decision: adjacent context only.

### 4. [UID:000051] `FittingRoomDialogItemState` / [UID:0000JE] `FittingRoom`

- Evidence for: several metadata xrefs are from fitting-room contexts and the helper sits in the fitting-room-adjacent island.
- Evidence against: ordinary caller is ItemCatalog local cleanup, not a specific item-state member; broad fan-in crosses non-fitting-room source families; sibling [UID:0002UE] is the item-state-specific vector destroy helper and already covers that pattern.
- Decision: reject as direct owner.

### 5. Runtime/STL ignored helper ownership

- Evidence for: machine code is MSVC vector-template cleanup shaped and calls runtime/free/invalid-parameter support.
- Evidence against: this is a concrete emitted helper for source-level vector storage used by game source. The project models these as source-declared/generated-binary vector support under `VectorHelpers`, while runtime throw/free wrappers remain dependencies.
- Decision: keep `RECONSTRUCTABLE:TRUE`; do not reclassify to ignored/non-reconstructable.

## Source Placement

- Recommended source file/class/global/module placement: `NexusTK/util/VectorHelpers.h` or a closely related compatibility-template route under [UID:0000P3]. Generated `VectorHelpers.cpp` remains a validator staging route, not proof of a standalone original `.cpp`.
- Why this fits: project container docs keep generic containers under `util/`, and prior VectorHelpers reports preserve typed caller-owned source plus compatibility-template fallback.
- Rejected placements: `cashshop/FittingRoom.cpp`, `cashshop/ItemCatalog.cpp`, [UID:0002EE] aggregate, runtime/CRT ignored, or a new `VectorStorageFreeHelper.cpp`.
- Remaining uncertainty: exact original helper spelling and whether normal typed vector source will regenerate the body without a compatibility shim.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: `lookup_funcs` confirms start `0x00423810`, size `0x50`, exclusive end `0x00423860`; `0x00423860` is not a function. Existing aggregate docs record `0x00423805-0x00423810` and `0x00423860-0x00423870` as `0xcc` padding.
- Children/subranges: no split, merge, or new child page recommended.
- Padding/table/data/code distinctions: no data/table route for the helper start; function is executable `.text` code with adjacent alignment padding.
- Parent/container impact: [UID:0002EE] remains a non-emitting mixed address container; [UID:0000P3] remains owner/emitter.

## Negative Evidence Summary

- Consumer xrefs alone do not prove ownership: the two ordinary ItemCatalog calls only clean a caller-local vector copy.
- Physical address locality does not prove fitting-room ownership: [UID:0002EE] already documents the island as mixed owner/context.
- Runtime shape does not prove `RECONSTRUCTABLE:FALSE`: the helper is concrete vector-template support needed by source reconstruction if typed source cannot regenerate it.
- Lack of original type names does not block a marker: current C++ policy permits formal non-body markers for source-disposition when a standalone body is misleading.
- No data refs, pointer encodings, vtable refs, strings, globals, or UDT names were found to support callback/table/feature ownership.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments:
  - Helper role: `VectorStorageFreeHelper` remains the best stable descriptive title.
  - Receiver type: `VectorStorageHeader *`, `VectorHeader *`, or `VectorStorageTriple *` are descriptive only; do not claim original-proof.
  - Fields: `begin`, `end/current`, `capacityEnd/endOfStorage`.
  - Behavior phrase: "MSVC-style vector storage free/clear with large-allocation saved-base validation."
- Evidence: MCP instruction-level use of `[esi]`, `[esi+4]`, `[esi+8]`; ItemCatalog copied-vector triple; sibling VectorHelpers patterns.
- Items intentionally left unchanged: no IDA DB rename requested; no by-* filename rename recommended because current title is stable and clear.
- IDA DB edits: not requested and not allowed in this report-only pass.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes for a formal marker, because `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P3`, and average score exceeds `85`.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` block insertion text only:

```cpp
// Emitted code for this vector-storage cleanup helper is covered by typed
// caller-owned vector declarations, or by a [UID:0000P3] VectorHelpers
// compatibility template if the recovered typed source cannot regenerate this
// out-of-line MSVC-style vector storage free helper.
// Do not emit a standalone decompiler-shaped VectorStorageFreeHelper body here.
```

- Reason it preserves exact original behavior: it keeps traceability for the emitted range while deferring machine-code regeneration to typed vector declarations or an explicitly documented compatibility template, which is the route most likely to reproduce MSVC vector helper output.
- Reason it matches plausible original source shape: a mid-2000s C++ project would more likely contain typed vectors or template/header support than a hand-authored `_DWORD *` cleanup function in `VectorHelpers.cpp`.
- Inferred source-facing names/types/fields used instead of decompiler labels: `VectorStorageHeader`, `begin`, `end/current`, `capacityEnd/endOfStorage`, `VectorHelpers compatibility template`.
- Naming/coding style convention: follows existing accepted markers for [UID:0001B2] and [UID:00017U].
- Reason code should remain blank, if applicable: not applicable after acceptance; it should no longer be blank. It should contain the marker only, not a body.
- Exact no-code proof against a body: no original helper symbol/type; no UDT; helper is pure vector cleanup mechanics; owner docs say final source may be header/template-driven; a concrete function body would invent a product source API around compiler/STL-like storage mechanics.

## Final Recommendation

- Exact changes recommended: target metadata `85/88 -> 87/90`, keep owner/emitter/reconstructable fields, insert formal marker, update target summary/status/behavior/source-disposition/negative evidence/open-question prose, and add/update a `VectorStorageFreeHelper Source-Disposition Notes` paragraph in [UID:0000P3] `VectorHelpers`.
- Exact parent assignments recommended: keep [UID:0000P3] as canonical owner and emitter.
- Exact items left no-owner/non-emitting: none in this target. [UID:0002EE] remains no-owner/non-emitting as existing aggregate context.
- Future work outside this assignment: final project-wide vector header/template policy may later decide whether typed caller source alone regenerates the body or a compatibility template is required.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md`
- Exact report facts to incorporate:
  - Current MCP session `supervisor_resume_20260629` health and exact `lookup_funcs`/decompile/disasm/xrefs/callees facts.
  - Current data/pointer/type negative checks.
  - `ItemCatalog::GetItemByIndex` local vector-copy cleanup call-site meaning at `0x00422720` and `0x00422731`.
  - Best descriptive signature/type/fields and unresolved original-proof caveat.
  - Rejected owner alternatives and no-standalone-body proof.
  - Replacement of stale `95/95` blank-C++ wording with the active marker disposition.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:87`
  - `CONFIDENCE:90`
  - Keep `CANONICAL_OWNER:0000P3`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:0000P3`
  - Insert exact marker in formal C++ block.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Historical blank-until-95/95 wording should be marked superseded, not deleted without explanation.
  - Preserve [UID:0002EE] as adjacent mixed aggregate only.
  - Preserve why `ItemCatalog`, fitting-room class/file routes, runtime/ignored classification, and standalone helper-body C++ are rejected.

## Recommended Support Doc Changes

- Support path: `by-file/VectorHelpers.md`
- Exact report facts to incorporate:
  - Add/update a concise `VectorStorageFreeHelper Source-Disposition Notes` paragraph saying [UID:0002UD] remains utility/template storage cleanup support, current MCP confirms the vector-header/free/invalid-parameter behavior and broad cleanup/unwind fan-in, and final behavior should come from typed caller-owned vector declarations or a `VectorHelpers` compatibility template.
  - State that the child now emits a formal marker and should not become a standalone decompiler-shaped helper body.
- Metadata/link/score/coverage/source-placement changes: no metadata score/path change required for [UID:0000P3]. Its `86/86` score remains adequate for this callback unless the supervisor chooses a broader VectorHelpers source-quality pass.

## Score And Metadata Recommendation

- Current score/metadata: target `85/88`, owner/emitter [UID:0000P3], reconstructable true, blank C++.
- Recommended score/metadata: `87/90`, same owner/emitter/reconstructable, formal marker.
- Score rationale and reason not higher/lower:
  - Completion `87`: current pass closes the stale C++ gate, marker disposition, signature/type contract, data/pointer/type negative checks, and owner/emitter revalidation. It remains below `90` because exact original source spelling/header/template policy remains inferred and no final compatibility-template implementation is chosen.
  - Confidence `90`: current MCP confirms exact behavior, range, xrefs, callees, no data refs, and no pointer encodings. It remains below final audit because no original UDT/source symbol exists.
- Score-improvement attempt:
  - Type/signature blocker: checked decompile/disassembly, ItemCatalog caller local stack triple, and `type_query`; resolved to descriptive `VectorStorageHeader *`, original-proof unavailable.
  - Owner/emitter blocker: checked xrefs, support docs, prior vector helper reports; resolved to keep `VectorHelpers`.
  - C++ blocker: checked active `by-structure.md` gate and prior marker precedents; resolved to formal marker.
  - Runtime/free wrapper relationship: checked callees and MSVC vector throw support; resolved as runtime dependencies, not target owner.
  - Generated empty marker: checked generated file header/current marker; implementation-ready validator refresh expected.
- Metadata fields to change or leave unchanged: only completion/confidence and formal C++ block should change; owner/reconstructable/emitter remain unchanged.

## Open Questions With Attempted Resolution

- Exact original helper name: not recoverable from current binary evidence. Best descriptive name remains `VectorStorageFreeHelper`; raw `sub_423810` should stay evidence-only. Score impact: caps confidence below final, does not block marker.
- Exact storage type spelling: no UDT names for Vector/ItemCatalog/Category; source-facing contract is a three-pointer vector header. Score impact: caps completion below high-final, does not block marker.
- Original header/source split: `VectorHelpers.h` is the best current placement, but final source might rely on typed caller containers or a compatibility template. Score/C++ impact: blocks standalone body, supports marker.
- Whether the body should be ignored as runtime/STL: rejected. It is a concrete emitted helper for game-source vector storage; runtime/free/invalid-parameter callees are dependencies.
- Whether further current-pass evidence could improve metadata beyond `87/90`: no defensible higher score is safe without original source symbols/UDTs or a settled project-wide vector template implementation. Current evidence routes were attempted: MCP body/xrefs/callees/type/data/pointer checks, target/support docs, generated output, and prior B-report precedent.

## Follow-Up Actions

- Supervisor actions: verify the implementation against this report, changed docs, scoped validator output, and generated freshness; then execute/archive the report if verification passes.
- B002 future callback actions: none remaining for the accepted scope.
- A-agent actions: none required.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `87/90`, not strong enough for `95+`.
- Remaining uncertainty: exact original symbol/type/source-header policy; whether final rebuild will use ordinary typed vectors or an explicit compatibility helper to regenerate this exact body.

## Validator Results

- B002 did not run scoped validators during this reconciliation callback and does not claim supervisor-observed validator commands as B002-run commands.
- Supervisor validation was reported as already observed for the target/support files before this reconciliation request.
- Read-only generated freshness inspection during reconciliation:
  - `auto-generated/NexusTK/util/VectorHelpers.cpp` has `validator-command-id: 000000004321`, `validator-refreshed-at: 2026-07-02T06:21:36-04:00`, `validator-refresh-source: deferred-generated-refresh`.
  - The generated [UID:0002UD] section now shows `Completion:87 | Confidence:90` and marker text, not `Empty Emitter Marker`.
  - Generated output auto-expands `[UID:0000P3] VectorHelpers` into a linked UID phrase; the target by-memory formal block itself still contains the accepted exact marker text.
- Unresolved validator warnings/errors from B002-run commands: none, because no validator commands were run by B002 in this reconciliation.

## Changed Files

- Created: none in callback.
- Modified:
  - `tools/leaser/Agents/Agent-B002/research/0002UD-VectorStorageFreeHelper-source-quality.md`
- Reconciled as already-present, not modified by B002 in this callback:
  - `by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md`
  - `by-file/VectorHelpers.md`
- Renamed: none.
- Report execution: not run. B agents must not run `tools/validator.py execute_report ... --apply` or equivalent report execution/archive lifecycle commands.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted the report and sent the 2026-07-02 implementation callback.
- [x] Target/support docs to update: `by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md`; `by-file/VectorHelpers.md`. Reconciliation proof: both files already contained the accepted target/support facts at report-level detail before B002 made any by-* edits in this callback.
- [x] Current target state and actual evidence checked recorded: incorporated MCP session `supervisor_resume_20260629`, function boundary/body/xrefs/callees, data/pointer/type negative checks, generated marker state, and report search terms into target `Raw Code Evidence`, `Signature And State Contract`, and `Score And Assignment Audit`, plus support source-disposition note.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C1-C8 now have `already-present` verification states with target/support proof.
- [x] Metadata/score changes to apply: target `COMPLETION:87`, `CONFIDENCE:90`; no support metadata change required. Reconciliation proof: target headers already show `COMPLETION:87` and `CONFIDENCE:90`.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: stale 95/95 C++ blocker resolved by marker; exact original type/name/header remains evidence-backed unresolved and score-capping in target `Open Questions`.
- [x] Owner/emitter/reconstructable changes to apply: kept `CANONICAL_OWNER:0000P3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P3`, blank `EMITTER_POSITION_OPTIONAL`. Proof: target headers unchanged except score/C++ block.
- [x] Split/rename/new-child changes to apply: none; exact `0x00423810-0x00423860` range and current filename/title preserved. Proof: target path unchanged and `Score And Assignment Audit` records no split/merge need.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: added source-placement/no-body reasoning; no IDA DB edits. Proof: target `Ownership And Rejected Alternatives`, `Source-Disposition Marker`, and support source-disposition note.
- [x] First-draft C++ or no-code proof to apply: reconciliation found the exact formal marker already present in the target `RECONSTRUCTION_CPP CODE` block:

```cpp
// Emitted code for this vector-storage cleanup helper is covered by typed
// caller-owned vector declarations, or by a [UID:0000P3] VectorHelpers
// compatibility template if the recovered typed source cannot regenerate this
// out-of-line MSVC-style vector storage free helper.
// Do not emit a standalone decompiler-shaped VectorStorageFreeHelper body here.
```

- [x] Third-party import directive to apply or confirm not applicable: not applicable; this is not a static third-party source import.
- [x] Exact target/support doc facts to incorporate at report-level detail: behavior, xrefs, owner ranking, rejected alternatives, source-disposition marker, score rationale, stale-95/95 correction, and generated refresh expectation are in target/support docs.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old blank-C++/95/95 text is superseded; ItemCatalog/fitting-room/[UID:0002EE]/runtime/no-owner/body rejections are preserved in target and support docs.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: none used as authority; raw/generated labels remain search aliases only.
- [x] Open questions to close or document as evidence-backed unresolved: original helper spelling, exact storage type, and header/template policy remain unresolved with score/C++ impact documented in target `Open Questions`.
- [x] Validators to run after accepted implementation: B002 did not run validators during this reconciliation; supervisor-observed scoped validator passes are not claimed here as B002-run commands. No additional validator was required because B002 made no by-* edits.
  - Read-only generated freshness inspected: `auto-generated/NexusTK/util/VectorHelpers.cpp` header shows `validator-command-id: 000000004321`, `validator-refreshed-at: 2026-07-02T06:21:36-04:00`, and [UID:0002UD] is no longer an empty marker.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated output is current by read-only inspection; no manual coverage/tracker text recommended.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail. Reconciliation proof: target and VectorHelpers support doc already contain the accepted evidence and source-disposition facts.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Reconciliation proof: target score/C++ already present; owner/emitter/reconstructable fields preserved; no split/rename/new child.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded: no B002-run validators in this reconciliation callback; supervisor-observed validator passes are not claimed as B002-run. No additional validator was required because B002 made no by-* edits.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged. Proof: generated `VectorHelpers.cpp` header is `validator-command-id: 000000004321` and [UID:0002UD] is no longer an empty marker; no manual coverage/tracker text needed.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004325","destination_path":"executed-b-agent-research/B002/0002UD-VectorStorageFreeHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002UD-VectorStorageFreeHelper-source-quality.md","timestamp":"2026-07-02T06:25:20-04:00","uid":"0002UD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
