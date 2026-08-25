** TARGET-REPORT-UID:00018W **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00018W Layer Ownership / Split Research


## Finalized Report / Current Recommendation

- Current implemented state: UID00018W is a non-emitting exact split index over 25 registered code bodies: 22 IDA-modeled functions plus three retained source-shaped raw bodies at `0x004f0b80`, `0x004f0ca0`, and `0x004f13a0`.
- Final disposition is applied: UID00018W is `92/94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, and relative `Nested:0`. UID0004NR opens the one-level child run with `Nested:4`, UID0004NS through UID0004OF continue it with `Nested:0`, and following UID00018X closes it with `Nested:-4`. Validator-issued children are UID0004NR through UID0004OF. Twenty-four source-authored children emit through UID000073 `Layer`; terminal UID0004OF remains compiler-only, non-reconstructable, and non-emitting.
- Callback completion: B001 applied every accepted target/support/padding/source/history disposition, all 27 exact managed blocks, scoped validation, waited generated verification, and the post-callback balanced-Nested repair. No B001 implementation work remains in this artifact.
- Confidence: very strong for boundaries, body behavior, ABI, layout, owner/emitter route, source order, callers, vtable/compiler distinction, and source placement; strong inference for original human spellings where PDB/UDT names are unavailable.

## Supporting Research

- Mandatory IDA MCP evidence was obtained through a fresh streamable transport to `http://127.0.0.1:13337/mcp`. At evidence time on 2026-07-14, `idb_list` returned one active adopted NexusTK session `1feab207`, worker PID `20008`, `is_analyzing:false`; `server_health` returned `status:ok`, imagebase `0x400000`, and auto-analysis, Hex-Rays, and strings ready; `lookup_funcs(0x004f0480)` returned `sub_4F0480`, size `0x117`; and a valid bounded `get_bytes` call returned target bytes. This is evidence-time health, not an assertion of indefinite future session availability.
- Request-shape history: an initial `get_bytes` call omitted the required `regions` object, and one later decompile batch used `address` instead of the required `addr`; both returned explicit invalid-parameter responses. B001 read `tools/list`, corrected the calls, and the valid retries succeeded. These were malformed-client-call limitations, not worker loss, and no evidence was inferred from either failed request.
- Active roots searched independently with target UID/address/name and source-family terms: `tools/leaser/Agents/Agent-B001/research/**` through `Agent-B005/research/**`. Search terms included `TARGET-REPORT-UID:00018W`, `UID:00018W`, `0x004f0480`, `0x004f1bf6`, `Layer`, `LayerNode`, `sub_4F0FF0`, `0x004f1390`, `HierList`, `ScreenPane`, `MainUiLayerSlots`, and `Layer.cpp`. No pre-existing direct target report or active overlapping report was found.
- Central executed reports opened and classified:
  - `executed-b-agent-research/B001/00018T-LocalizationAdjacentZeroInitializer.md`: boundary/adjacency evidence only; proves Layer begins after the nine-byte LanguageMan tail alignment and is a separate source island.
  - `executed-b-agent-research/B015/00018S-LanguageManCleanupDestructor-source-quality.md`, `B002/00018V-LanguageManScalarDeletingDestructor-source-quality.md`, and `B012/00018R-LanguageManLocalization-source-quality.md`: predecessor and padding evidence only; no Layer body reconstruction.
  - `executed-b-agent-research/B001/00016X-hierlist-source-quality.md`, `B003/0002IA-HierListTailInsertWrapper-source-quality.md`, and `B001/0002IE-HierListRemoveNode-source-quality.md`: direct container/call support. They establish Layer's InsertAfter/InsertBefore/RemoveByPayload calls but are not direct UID00018W reports.
  - `executed-b-agent-research/B002/0001EA-PaneCore-source-quality.md`: direct Pane caller-family support for add/insert/remove/contains/offset routes; not Layer ownership.
  - `executed-b-agent-research/B002/0002I2-mappane-find-active-effect-source-quality.md`: direct render special-branch support; independently reconfirmed here.
  - `executed-b-agent-research/B007/0002H7-ApplicationStartup-source-quality.md`: six constructor clients and MainUiLayerSlots mapping; clients, not source owners.
  - `executed-b-agent-research/B011/00019K-InitializeMainUiGraph-source-quality.md` and `00019K-InitializeMainUiGraph-source-quality-2.md`: historical transition-caller/source-family support; not direct Layer coverage. B002's active repaired UID0002AF report was also opened after a supervisor coordination notice. Its fresh same-session reanalysis identifies UID00019K as `MainMenuPane::InitializeMainUiGraph()` and independently ranks this Layer dependency as `MarkAllPanesForDeletion`; both facts match this report's own receiver/caller and full-loop evidence.
  - `executed-b-agent-research/B012/000058-FlyingParcelPane-class-source-quality.md`: owned animation-layer constructor client; not Layer ownership.
  - `executed-b-agent-research/B012/0003A3-ScreenPanePresentationTraversal-source-quality.md`: direct dirty/render caller support. Its provisional `ScreenLayerEntry` type and omission of `nullsub_11` are superseded by this pass's exact `Layer *` list-element proof and direct `Layer::EndRender()` call.
- `archived/**`, `tools/leaser/Agents/Older-Research/**`, and `tools/leaser/Agents/SpecialReports/**` were separately searched with the same direct and family terms. Older-Research and SpecialReports returned no relevant match; archived search returned no direct target report. No opened artifact has `TARGET-REPORT-UID:00018W`.
- Explicit duplicate conclusion: executed matches are adjacency, dependency, caller, container, or client reports. None reconstructs UID00018W as its direct target. This is the first dedicated UID00018W source-quality report.
- Wave2/Wave3/recovered output was treated only as stale low-rung lead material. Evidence-time MCP bytes/xrefs, evidence-time by-* docs, and source-owner structure control every recommendation.

## Target

- Target UID: `00018W`.
- Target path: `by-memory/0x004f0480-0x004f1bf6.Layer.md`.
- Historical queue/report row: before callback, validator-generated state was not-covered reconstructable at `86/90`, zero direct reports, and generated `Layer.cpp` contained UID000073/UID00018W Empty Emitter Markers.
- Current artifact classification: accepted implementation callback completed by B001; validation/execution/count/path/move/archive state remains external supervisor/validator-owned and is neither asserted nor directed here.
- Current scores and parent state: `92/94`, owner NONE, reconstructable false, blank emitter/position/formal C++, relative `Nested:0`; UID0004NR is `Nested:4`, UID0004NS-UID0004OF are `Nested:0`, and UID00018X is `Nested:-4`.

## Current Target State

- UID00018W now records the entire 6,006-byte range as a non-emitting 25-child index and links all real child UIDs in address order. Its 24 internal alignment spans are registered as proven all-`cc` bytes. Relative nesting is balanced across the address-sorted stream: UID00018W stays at the UID00018V baseline, UID0004NR opens one four-space child level, UID0004NS-UID0004OF retain it, and UID00018X returns to baseline.
- UID000073 now carries the complete 48-byte LayerNode/eight-byte Layer declaration at position 10. UID0004NR through UID0004OE carry the 24 source bodies at positions 20-250; UID0004OF carries exhaustive compiler-only scalar-wrapper proof with blank output.
- At waited command `000000011289` evidence time, generated `auto-generated/NexusTK/ui/core/Layer.cpp` was SHA256 `FDBA16A3273CFB0FC44EA0B2A9E5D154E4C8CBE1B18C0880F6496C0491F2E782`; it contained the class and every source body once, with no UID00018W/UID0004OF marker, Empty Emitter Marker, scalar wrapper, explicit vptr/base teardown, delete flag, or vtable body. A read-only self-review after a later validator-owned refresh reconfirmed every semantic assertion. Generated by-memory leading spaces were also rechecked as UID00018V `211`, UID00018W `211`, every UID0004NR-UID0004OF child `215`, and UID00018X `211`.
- UID0003A3 now uses `Layer *` and calls `Layer::EndRender()`; UID000065 has exact friend access; vtable, Pane, HierList, Region/Motion, startup, MainMenu, MapPane, WorldMapPane, packet, and FlyingParcel support is synchronized without unrelated score or C++ changes.
- B001 used short leases, scoped validators, and waited refreshes. B001 did not manually edit coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, queue/lock, archive, or IDA state and did not run `execute_report` or any report lifecycle/probe/count/move/archive command.

## Executive Recommendation

- Implemented UID00018W as exact leaf pages with the broad parent retained only as a non-emitting address-order index and evidence container.
- Kept source ownership on UID000073 `Layer`, emitted through UID0000KL `NexusTK/ui/core/Layer.cpp`; MapPane, Pane, ScreenPane, MainUiGraph, Application, and FlyingParcelPane remain callers/clients/dependencies.
- Applied `LayerNode` as the exact 48-byte caller payload behind an eight-byte `HierListNode` hierarchy header and three trailing stride bytes, for a 59-byte stored row.
- Applied one Layer declaration at position 10 and 24 source bodies at positions 20 through 250. The scalar deleting destructor remains blank/non-emitting and is regenerated from the virtual ordinary destructor.
- Corrected UID0003A3 to iterate `Layer *`, invoke `Layer::EndRender()` unconditionally after each recursive render, and historicalized the optional/vtable-driven interpretation.
- Applied the balanced relative hierarchy sequence `UID00018W:0`, `UID0004NR:4`, `UID0004NS-UID0004OF:0`, `UID00018X:-4`; generated by-memory coverage now opens exactly one child level and closes it before the following aggregate.

## Supervisor Active Recheck

- The supervisor assigned a dedicated reanalysis of UID00018W and required every modeled/raw child, layout, caller, source, score, C++, generated-output, and coverage blocker to be closed rather than repeated as uncertainty; the accepted callback has now closed those ordinary-documentation and generated-output blockers.
- At Gate 1, split repair was mandatory before the broad aggregate could cease emitting an empty marker; that repair is now implemented and validator-verified.
- Every source-bearing body has an exact child path, role, owner/emitter, score, position, and formal destination below. The sole compiler-only body has an exhaustive no-handwritten-code disposition.

## Inference Research Guidance Check

- `by-structure.md` discipline was applied by separating direct byte/instruction facts, current documentation evidence, and source-facing inference; exact leaves own bodies, while the broad range becomes an index.
- Existing `LayerNode`, raw-helper, nullsub, owner, and render-split text was treated as provisional. `Layer`, `HierList`, Pane, and `ui/core/Layer.cpp` survive reanalysis; 22-body completeness, aggregate emission, raw-gap dismissal, optional nullsub treatment, and unresolved-node wording do not.
- Direct facts: all bytes/hashes/boundaries, instruction flow, return cleanup, xrefs/callers, vtable slots, offsets, allocation sizes, field access, recursion, and branch polarity.
- Documentation facts: established UID routes, current formal HierList/Region methods, MainUiLayerSlots names, Pane caller families, ScreenPane presentation route, and generated/manual coverage state.
- Inference: original human method/field spellings, specifically `paneFlags`, `blocksChildTraversal`, `EndRender`, and several helper names. Each is behavior-specific, ranked against alternatives, and score-capped rather than deferred.
- No Wave2/Wave3 assertion overrides current evidence.

## Heuristic / Inference Reanalysis And Validation

- Aggregate completeness: rejected 22 as the full body count. IDA models 22 functions, but raw bytes at three gaps have ordinary prologues, stack frames, complete CFGs, internal calls to the same recursive lookup, exact `retn` cleanup, and source-semantic field accesses.
- Modeled `0x004f0b40`: accepted as `Layer::MarkAllPanesForDeletion()`. It indexes every row in the owned top-level HierList, skips null/sentinel rows and null pane pointers, then invokes `Pane::MarkForDeletion()` on every surviving pane. `MarkRootPanesForDeletion` remains a precise implementation-description alias, but `MarkAllPanesForDeletion` is the higher-probability human API spelling because callers request deletion of all panes represented by that Layer and Pane owns any descendant deletion semantics.
- Raw `0x004f0b80`: accepted as `Layer::SetPaneFlagsMasked(Pane *, unsigned char value, unsigned char mask)`. It computes `(old & ~mask) | (value & mask)`, handles bit-0 transitions, resets cached state, and invalidates the parent on transition to zero. Generic `raw helper` and `UpdateMetadata` are rejected as less exact.
- Raw `0x004f0ca0`: accepted as `Layer::GetPaneFlags(Pane *) const`. It finds a node and returns payload `+0x04`; it intentionally has no miss guard, proving a caller precondition.
- Raw `0x004f13a0`: accepted as `Layer::GetChildList(Pane *) const`. It shares the lookup skeleton and returns full-node `+0x04`, the child HierList pointer; it also has no miss guard.
- `LayerNode` means the 48-byte caller payload, not the full list row. Calling the full 59-byte row `LayerNode` would conflate HierList's parent/child header and three stride bytes with Layer-owned fields.
- Payload layout is exact: pane `+0x00`, flags `+0x04`, pad `+0x05..+0x07`, current bounds `+0x08`, previous bounds `+0x18`, visible `+0x28`, blocks-child-traversal `+0x29`, dirty `+0x2a`, pad `+0x2b`, Region pointer `+0x2c`.
- Constructor object layout is exact: inherited LObject/vptr at `+0x00`, owned `HierList *m_nodes` at `+0x04`; object size is 8 bytes. Root full row allocation is exactly 59 bytes.
- Insert asymmetry is preserved, not normalized: AddChildAfter initializes only current bounds; AddChildBefore initializes current and previous bounds. Both leave the flags byte and explicit padding indeterminate. This is direct original binary behavior.
- `0x004f1390`: accepted as source member `Layer::EndRender()`, not an omittable callback. ScreenPane loads each Layer pointer into ECX and calls it directly after render. Vtable bytes contain no pointer to `0x004f1390`.
- Rendering names: `RenderRecursive`, `ClearDirtyRegion`, `CopyDirtyRegion`, `UnionDirtyRegion`, `CollectDirtyRegion`, and `PropagateDirtyRegion` are accepted because the Region operations and ScreenPane call order are direct. Old `LayerNode::` ownership labels are rejected because the receiver is an 8-byte Layer object.
- Source placement: one Layer class/source family in `NexusTK/ui/core/Layer.cpp`. A render-side split is rejected because constructor/destructor/add/remove/search/dirty/render bodies are contiguous, share private helpers and one class, and emit through one vtable/source owner.
- Compiler/source split: ordinary destructor is source-authored; explicit vptr restore, LObject teardown, EH cleanup, scalar-delete flags, and operator delete are compiler output. The scalar wrapper must not duplicate the ordinary body.
- Ranked field spelling alternatives: `blocksChildTraversal` is accepted over raw `field_C0`, `skipChildren`, and `opaque`; `paneFlags` is accepted over `metadata` and `stateByte`; `dirtyRegion` is accepted over `motion` because the object is constructed as Region and receives union/intersection operations, while current Region/Motion docs explain the shared implementation.
- Remaining uncertainty is limited to original lexical spelling and physical header factoring. It does not block behavior-identical source, ownership, split, or generated placement.

## Evidence Standards Used

- Evidence types: fresh MCP health/session discovery, lookup/analyze/decompile/disassembly, bounded raw bytes, local SHA256, raw-gap instruction decoding, CFG counts, xrefs, code/data/immediate/pointer searches, callers/callees, vtable/RTTI bytes, global storage, adjacent ranges, current by-* docs, executed reports, generated source, and manual coverage.
- Evidence ladder: bytes/instructions and direct callers dominate; vtable/RTTI and contiguous source order establish class/source ownership; current docs corroborate dependency names; descriptive names are accepted only after alternatives are ranked.
- Evidence is strong enough for target `92/94`: behavior, boundaries, split, layout, routing, and source form are exact. Scores stop below maximum because original PDB/UDT names and the historical header/source split are unavailable.

## Evidence Checked

- MCP calls: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, bounded find/search calls, vtable/global bytes, and relevant caller/callee analysis against database `1feab207`.
- Exact target read: `[0x004f0480,0x004f1bf6)` is 6,006 bytes with SHA256 `1444CFBA7D8179ED1BD2A084485C028364BBAC2DAD841AC0D48D1643352C232B`.
- Boundary reads: predecessor `[0x004f0477,0x004f0480)` is nine `cc` bytes, SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; successor `[0x004f1bf6,0x004f1c00)` is ten `cc` bytes, SHA256 `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`.
- Current docs/output: every path listed in Current Target State, current generated Layer.cpp, current manual class/file/memory rows, and current ignored-range inventory.
- Historical searches: active B001-B005, executed, archived, Older-Research, SpecialReports, target identifiers, generated/source family terms, callers, globals, and dependency names.
- Negative checks: no alternate target entry/chunk; no source owner outside Layer; no vtable route to `0x004f1390`; no source reason to emit scalar-delete glue; no direct reports; no IDA UDT/PDB LayerNode name; no hidden code in any listed `cc` span; no MapPane-only ownership; no separate render object-file evidence.
- Historical report-only boundary: before callback, by-* edits, leases, implementation validators, waited generation, coverage edits, lifecycle commands, report execution, moves/archives, and IDA mutation were intentionally skipped. The accepted callback subsequently applied ordinary documentation and authorized validator work only; manual coverage and all lifecycle/IDA mutations remain excluded.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C18W-001 | UID00018W exact range is `[0x004f0480,0x004f1bf6)`, 6,006 bytes, SHA256 `1444CFBA...C232B`. | 100 | Fresh valid get_bytes plus SHA256. | UID00018W boundary/evidence | incorporate | applied |
| C18W-002 | No direct historical UID00018W report exists; opened matches are support/adjacency only. | 100 | Path-specific active/executed/archive/Older/Special searches. | UID00018W history | incorporate | already-present |
| C18W-003 | Session `1feab207` was healthy at research evidence time; malformed calls were corrected request-shape errors. | 100 | idb_list, health, lookup, valid bounded reads. | UID00018W IDA provenance | incorporate | already-present |
| C18W-004 | Predecessor and successor spans are exact external `cc` alignment, and following UID00018X closes the relative child indentation with `Nested:-4`. | 100 | Bounded bytes/hashes, adjacent lookups, and generated address-sorted leading-space readback. | UID00018W; `-ignored.md`; UID00018X metadata | incorporate | applied |
| C18W-005 | The range contains 25 code bodies, not only 22. | 100 | Complete byte/function/padding map. | UID00018W split index | incorporate | applied |
| C18W-006 | Raw starts `0x004f0b80`, `0x004f0ca0`, `0x004f13a0` are complete source methods. | 99 | Prologues, CFGs, calls, fields, exact returns. | Three new raw child pages | incorporate | applied |
| C18W-007 | Twenty-four internal spans are compiler/linker `cc` alignment, not source/data. | 100 | Exact bytes/hashes and fallthrough boundaries. | `by-memory/-ignored.md` | incorporate | applied |
| C18W-008 | UID00018W is `92/94`, NONE/FALSE/non-emitting, blank position/C++, relative `Nested:0`; the child run opens at UID0004NR and closes at UID00018X. | 99 | Exact split, relative-Nested semantics, scoped validators, and generated leading-space readback. | UID00018W/UID0004NR/UID00018X metadata | incorporate | applied |
| C18W-009 | UID000073 remains semantic owner and emits through UID0000KL at position 10. | 99 | RTTI/vtable, contiguous class bodies, source tree. | Layer class/file | incorporate | applied |
| C18W-010 | UID0000KL remains `NexusTK/ui/core/Layer.cpp`; render-side split is rejected. | 98 | Method cohesion, callers, current tree, vtable. | Layer by-file | reject-stale | applied |
| C18W-011 | Layer object is 8 bytes: LObject plus `HierList *m_nodes`. | 100 | Constructor/destructor offsets and allocation callers. | Layer class/target/children | incorporate | applied |
| C18W-012 | Layer payload is exact 48-byte `LayerNode`; full HierList row stride is 59. | 100 | Constructor size 0x3b, HierList payload 48, all field reads. | Layer class, HierList support | incorporate | applied |
| C18W-013 | Constructor child is exact source body at position 20, `92/94`, and opens the one-level child run with relative `Nested:4`. | 99 | Decompile, nine callers, allocation/layout, and generated indentation. | `LayerConstructor.md` | incorporate | applied |
| C18W-014 | Ordinary destructor child is source body at position 30, `92/94`. | 99 | Decompile, vtable store, ownership cleanup. | `LayerDestructor.md` | incorporate | applied |
| C18W-015 | AddChildAfter child is source body at position 40, `92/94`; previous bounds/flags remain uninitialized. | 99 | Instructions, Pane caller, HierList InsertAfter. | `LayerAddChildAfter.md` | incorporate | applied |
| C18W-016 | AddChildBefore child is source body at position 50, `92/94`; both rects initialize, flags remain uninitialized. | 99 | Instructions, Pane caller, HierList InsertBefore. | `LayerAddChildBefore.md` | incorporate | applied |
| C18W-017 | RemoveChild child is source body at position 60, `92/94`. | 99 | Three Pane callers, Region/child cleanup, RemoveByPayload. | `LayerRemoveChild.md` | incorporate | applied |
| C18W-018 | `MarkAllPanesForDeletion` child is source body at position 70, `91/94`; root-list traversal is exact and `MarkRootPanesForDeletion` is a rejected lower-probability API spelling. | 98 | Fresh decompile/disassembly, two lifecycle callers, indexed full top-level list, Pane effect. | `LayerMarkAllPanesForDeletion.md` | incorporate | applied |
| C18W-019 | Raw masked flag setter is retained source body at position 80, `91/93`. | 97 | Exact raw instructions and state transition behavior. | `LayerSetPaneFlagsMasked.md` | incorporate | applied |
| C18W-020 | Raw flag getter is retained source body at position 90, `90/93`, with attached-pane precondition. | 97 | Exact raw instructions/no guard/no xrefs. | `LayerGetPaneFlags.md` | incorporate | applied |
| C18W-021 | ContainsPane child is source body at position 100, `91/94`. | 99 | Pane caller and recursive search. | `LayerContainsPane.md` | incorporate | applied |
| C18W-022 | InvalidatePaneRegion child is source body at position 110, `92/94`. | 99 | Sole Pane caller, Region operations, ancestor walk. | `LayerInvalidatePaneRegion.md` | incorporate | applied |
| C18W-023 | ClearDirtyRegion child is source body at position 120, `92/94`. | 100 | Root data writes and Region::SetEmpty. | `LayerClearDirtyRegion.md` | incorporate | applied |
| C18W-024 | CopyDirtyRegion child is source body at position 130, `92/94`. | 100 | Root Region copy. | `LayerCopyDirtyRegion.md` | incorporate | applied |
| C18W-025 | UnionDirtyRegion child is source body at position 140, `92/94`. | 100 | Root Region union. | `LayerUnionDirtyRegion.md` | incorporate | applied |
| C18W-026 | CollectDirtyRegion child is source body at position 150, `92/94`. | 99 | Root union, recursive update, output copy. | `LayerCollectDirtyRegion.md` | incorporate | applied |
| C18W-027 | PropagateDirtyRegion child is source body at position 160, `92/94`. | 99 | Wrapper-to-recursive route. | `LayerPropagateDirtyRegion.md` | incorporate | applied |
| C18W-028 | RenderRecursive child is source body at position 170, `92/94`. | 99 | Full CFG, ScreenPane caller, MapPane effect branch. | `LayerRenderRecursive.md` | incorporate | applied |
| C18W-029 | One-byte `0x004f1390` child is source `Layer::EndRender()` at position 180, `91/94`. | 99 | Direct ECX Layer caller; no vtable route. | `LayerEndRender.md`; UID0003A3 | reject-stale | applied |
| C18W-030 | Raw GetChildList child is source body at position 190, `90/93`, with attached-pane precondition. | 97 | Exact raw instructions/no xrefs/no guard. | `LayerGetChildList.md` | incorporate | applied |
| C18W-031 | GetParentPane child is source body at position 200, `92/94`. | 99 | Pane caller, owner-list/root-node semantics. | `LayerGetParentPane.md` | incorporate | applied |
| C18W-032 | GetScreenOffset child is source body at position 210, `92/94`; miss sentinel is `(-1000,-1000)`. | 99 | Three callers and exact ancestor accumulation. | `LayerGetScreenOffset.md` | incorporate | applied |
| C18W-033 | UpdateDirtyRegionsRecursive child is source body at position 220, `92/94`. | 98 | Full recursive CFG and Pane/Region state transitions. | `LayerUpdateDirtyRegionsRecursive.md` | incorporate | applied |
| C18W-034 | PropagateDirtyRegionRecursive child is source body at position 230, `92/94`. | 99 | Static recursion and intersection/offset behavior. | `LayerPropagateDirtyRegionRecursive.md` | incorporate | applied |
| C18W-035 | DestroyNodeRegions child is source body at position 240, `92/94`. | 100 | Destructor/remove/self callers and Region deletion. | `LayerDestroyNodeRegions.md` | incorporate | applied |
| C18W-036 | FindPaneNode child is source body at position 250, `92/94`. | 100 | Thirteen internal calls and exact owner/index outputs. | `LayerFindPaneNode.md` | incorporate | applied |
| C18W-037 | Scalar deleting destructor is compiler-only, NONE/FALSE/non-emitting, blank position/C++, `91/94`. | 100 | Vtable-only xref, duplicate ordinary cleanup, delete flags. | `LayerScalarDeletingDestructor.md` | reject-invalid | applied |
| C18W-038 | HierList class declaration gains `friend class Layer` only; score/route remain `91/92`. | 96 | Protected ownerNode needed by exact source; no emitted body. | UID000065 | incorporate | applied |
| C18W-039 | UID0003A3 uses `Layer *`, calls EndRender after each render, and is `90/92`. | 99 | Root list contents and direct call disassembly. | UID0003A3 formal/prose/score | incorporate | applied |
| C18W-040 | UID0003OK vtable data is exact declaration-generated support, recommend `90/94`, no standalone C++. | 100 | Four dwords, three vtable refs, slot targets. | UID0003OK | incorporate | applied |
| C18W-041 | UID00025N remains mixed non-emitting read-only index; Layer subsection links UID0003OK/class. | 100 | Exact section boundaries and mixed vtables. | UID00025N | already-present | applied |
| C18W-042 | Pane class/file/Core retain ownership/scores; correct parent/offset and Layer API wording only. | 98 | Direct caller and vslot analysis. | UID0000A2/0000MC/0001EA | incorporate | applied |
| C18W-043 | HierList insert/remove pages retain scores/formal bodies and gain exact Layer consumer notes. | 100 | Direct calls at 4f081a/4f0a3b/4f0b25. | UID0002IC/ID/IE | incorporate | applied |
| C18W-044 | Region/Motion page retains score/formal body and gains exact Layer consumer/field note. | 99 | Direct constructor and operation calls. | UID0001FW | incorporate | applied |
| C18W-045 | MapPane effect predicates retain scores/bodies and are exact dependencies of RenderRecursive. | 100 | Calls at 4f1277/4f1286 and returned slot +0x1c. | UID0002I1/2I2 | already-present | already-present |
| C18W-046 | MainUiLayerSlots/Application startup docs remain clients, not Layer owners. | 100 | Six constructor calls/stores and registration order. | UID0000T6/0002H7 | incorporate | applied |
| C18W-047 | `MainMenuPane::InitializeMainUiGraph` and MapPane teardown/reset call `MarkAllPanesForDeletion`; neither caller transfers Layer ownership. | 99 | Calls at 4f7d53 and 504837; B002 UID0002AF receiver repair independently corroborates the first caller. | UID00019K/MapPane support | incorporate | applied |
| C18W-048 | WorldMapPane and FlyingParcelPane construction sites are owned Layer clients. | 99 | Constructor xrefs at 50f326/512722/546b3b. | UID0003TP/000058/0002KJ | incorporate | applied |
| C18W-049 | Generated Layer.cpp contains the class once and 24 source definitions once, with no aggregate/scalar duplicate or empty marker. | 99 | Accepted route/positions/formal blocks and waited readback. | Generated verification | incorporate | applied |
| C18W-050 | Manual coverage rows require exact supervisor-owned synchronization. | 100 | Current stale/missing rows read directly. | Coverage text section | incorporate | excluded-with-reason |
| C18W-051 | No IDA mutation is requested; source-facing names belong in docs/source first. | 100 | Assignment restriction and inferred-name status. | Rename section | not-applicable | excluded-with-reason |
| C18W-052 | No third-party import directive applies. | 100 | NexusTK-owned class and direct binary source. | C++/checklist | not-applicable | excluded-with-reason |

## Callback Claim Proof

| Claim ID | Final proof |
| --- | --- |
| C18W-001 | UID00018W current boundary section retains the full hash/range; original validator 000000011215 and repair validator 000000011281 passed. |
| C18W-002 | Path-specific active/executed/archive/Older/Special classification remains preserved in Supporting Research. |
| C18W-003 | Evidence-time session 1feab207 and malformed-call provenance remain preserved; callback introduced no binary uncertainty or IDA mutation. |
| C18W-004 | Existing predecessor/successor ignored rows were preserved; UID00018X received only relative `Nested:-4` under validator 000000011288, and generated leading spaces return from child `215` to baseline `211`. |
| C18W-005 | UID00018W current child index lists all 25 registered bodies in address order. |
| C18W-006 | Raw source leaves are UID0004NX, UID0004NY, and UID0004O8, each with full body/no-xref evidence and exact formal C++. |
| C18W-007 | Twenty-four all-cc spans were added to by-memory/-ignored.md; validator 000000011223 passed. |
| C18W-008 | UID00018W is 92/94 NONE/FALSE, blank emitter/position/C++, relative Nested 0; UID0004NR is +4, UID0004NS-UID0004OF are 0, and UID00018X is -4. Validators 000000011281/11284/11288 and waited command 000000011289 passed. |
| C18W-009 | UID000073 is 92/94 at position 10 and UID0000KL is 91/93; validators 000000011216/11218 passed. |
| C18W-010 | UID0000KL retains NexusTK/ui/core/Layer.cpp and explicitly closes the rejected render split. |
| C18W-011 | Layer class, target, and every leaf preserve the exact eight-byte object layout. |
| C18W-012 | Layer/HierList/HierListNode pages preserve the 48-byte payload and 59-byte row; validators 11216/11219/11230 passed. |
| C18W-013 | UID0004NR registered at position 20 under validator 000000011157; repair validator 000000011284 applied relative Nested 4 without changing its formal block or source metadata. |
| C18W-014 | UID0004NS registered at position 30; validator 000000011177. |
| C18W-015 | UID0004NT registered at position 40 with uninitialized previousBounds/flags evidence; validator 000000011178. |
| C18W-016 | UID0004NU registered at position 50 with both rectangles and uninitialized flags evidence; validator 000000011179. |
| C18W-017 | UID0004NV registered at position 60 with Pane callers and Region/HierList cleanup; validator 000000011181. |
| C18W-018 | UID0004NW registered at position 70; MainMenu and MapPane caller docs synchronized by validators 11242/11234. |
| C18W-019 | UID0004NX registered at position 80 with retained raw masked transition behavior; validator 000000011183. |
| C18W-020 | UID0004NY registered at position 90 with attached-pane precondition; validator 000000011185. |
| C18W-021 | UID0004NZ registered at position 100 and Pane membership route synchronized; validator 000000011186. |
| C18W-022 | UID0004O0 registered at position 110 and Pane invalidation route synchronized; validator 000000011188. |
| C18W-023 | UID0004O1 registered at position 120; validator 000000011189. |
| C18W-024 | UID0004O2 registered at position 130; validator 000000011190. |
| C18W-025 | UID0004O3 registered at position 140; validator 000000011191. |
| C18W-026 | UID0004O4 registered at position 150; validator 000000011193. |
| C18W-027 | UID0004O5 registered at position 160; validator 000000011194. |
| C18W-028 | UID0004O6 registered at position 170; generated definition count is one; validator 000000011195. |
| C18W-029 | UID0004O7 registered at position 180; UID0003A3 now calls EndRender once; validators 11196/11220. |
| C18W-030 | UID0004O8 registered at position 190 with raw attached-pane precondition; validator 000000011197. |
| C18W-031 | UID0004O9 registered at position 200 and Pane parent route synchronized; validator 000000011199. |
| C18W-032 | UID0004OA registered at position 210 with (-1000,-1000) miss sentinel; validator 000000011200. |
| C18W-033 | UID0004OB registered at position 220 with full recursive motion/dirty evidence; validator 000000011201. |
| C18W-034 | UID0004OC registered at position 230; validator 000000011202. |
| C18W-035 | UID0004OD registered at position 240; validator 000000011203. |
| C18W-036 | UID0004OE registered at position 250; validator 000000011206. |
| C18W-037 | UID0004OF is 91/94 NONE/FALSE, blank emitter/position/C++, and absent from generated Layer.cpp; validator 000000011208. |
| C18W-038 | UID000065 exact Destination 26 block adds only friend class Layer; score/route preserved; validator 000000011219. |
| C18W-039 | UID0003A3 is 90/92 with exact Destination 27 Layer-pointer/EndRender block; validator 000000011220. |
| C18W-040 | UID0003OK is 90/94, declaration-generated, non-emitting, with COL/three slots/xrefs; validator 000000011221. |
| C18W-041 | UID00025N remains 86/92 mixed/non-emitting and has bounded Layer class/vtable synchronization; validator 000000011222. |
| C18W-042 | UID0000A2/0000MC/0001EA retain metadata/formal C++ and contain exact Layer API/offset notes; validators 11224-11226. |
| C18W-043 | UID0002IC/0002ID/0002IE retain metadata/formal bodies and contain exact 48/59-byte Layer consumer notes; validators 11227-11229. |
| C18W-044 | UID0001FW retains metadata/formal C++ and contains exact Layer Region/field consumers; validator 000000011231. |
| C18W-045 | UID0002I1/0002I2 already contained the exact 0x4f1277/0x4f1286 Layer render dependency and were intentionally unchanged. |
| C18W-046 | UID0000T6/UID0002H7 now identify six Layer constructor clients and exact store/register order; validators 11232/11233. |
| C18W-047 | UID00019K dependency is closed and MapPane teardown records 0x504837; validators 11242/11234. |
| C18W-048 | WorldMapPane class/file, packet aggregate/UID0003TP, and FlyingParcel class/UID0002KJ record 0x50f326/0x512722/0x546b3b clients; validators 11235-11240. |
| C18W-049 | Initial waited command 000000011243 and final repair waited command 000000011289 generated one Layer class and 24 definitions with no aggregate/scalar/empty-marker duplicate; command-11289 Layer.cpp SHA was FDBA16A3...F2E782, and a later read-only refresh check preserved the same semantic counts. |
| C18W-050 | B001 did not edit manual coverage. The exact section now carries real UID0004NR-0004OF rows for supervisor-owned synchronization. |
| C18W-051 | No IDA mutation occurred; source-facing names were applied only to ordinary docs/formal source. |
| C18W-052 | Layer is NexusTK-owned; no third-party import directive or source acquisition applies. |

## Positive Evidence Summary

- The entire range is a contiguous Layer source island bracketed by exact `cc` alignment and a distinct successor.
- Constructor, ordinary destructor, and scalar wrapper write the unique Layer vtable; RTTI/vtable data and all public Pane wrappers agree on the class.
- Exact 59-byte row allocation plus HierList's `payloadSize + 11` rule proves a 48-byte Layer payload. Every field is independently read/written by insertion, flags, dirty, render, and cleanup methods.
- ScreenPane's reverse dirty pass and forward render pass call the exact Layer methods in source order, and its root list stores Layer object pointers.
- The three raw methods are structurally and semantically integrated with the same private recursive search; their absence from IDA's function model does not weaken their source-body status.

## IDA MCP Facts

- Function/range facts: 22 IDA-modeled functions plus three complete raw bodies; exact child boundaries/hashes appear below. No alternate chunks or interior entry xrefs were found.
- Data/padding facts: 24 internal all-`cc` alignment spans, exact external padding, and no embedded data tables.
- Xref facts: constructor has nine callers; add/insert/contains/invalidate/parent/offset methods have Pane-facing callers; ScreenPane calls the dirty/render family; internal recursive helpers have only class-internal callers; scalar wrapper has one vtable data xref.
- Vtable/type facts: COL at `0x0061ca44`; vtable slots at `0x0061ca48` scalar destructor `0x004f1b40`, `0x0061ca4c` inherited `0x004f4b10`, and `0x0061ca50` inherited `nullsub_18`; next COL starts at `0x0061ca54`. Vtable-base xrefs are constructor `0x004f04ba`, destructor `0x004f05c9`, scalar wrapper `0x004f1b70`.
- Negative IDA facts: no recovered Layer/LayerNode UDT, no vtable slot for `0x004f1390`, no direct caller to ordinary destructor, no direct xrefs to the three raw methods, and no evidence that MapPane or ScreenPane owns these bodies.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f0480-0x004f1bf6` | UID00018W current path | exact split index | false | none | `92/94` | implemented/validated non-emitting 25-child index; relative `Nested:0`, generated baseline 211 |
| `0x004f0480-0x004f0597` | UID0004NR `0x004f0480-0x004f0597.LayerConstructor.md` | `Layer::Layer` | true | UID000073 | `92/94`, pos 20 | implemented/validated source body; relative `Nested:4` opens child level 215; 279 bytes; SHA `8802890C...319C3` |
| `0x004f05a0-0x004f062a` | UID0004NS `0x004f05a0-0x004f062a.LayerDestructor.md` | ordinary destructor | true | UID000073 | `92/94`, pos 30 | implemented/validated source body; 138 bytes; SHA `4298F5A8...168D1` |
| `0x004f0630-0x004f083c` | UID0004NT `0x004f0630-0x004f083c.LayerAddChildAfter.md` | add after | true | UID000073 | `92/94`, pos 40 | implemented/validated; 524 bytes; SHA `F745CF52...FE8D` |
| `0x004f0840-0x004f0a5d` | UID0004NU `0x004f0840-0x004f0a5d.LayerAddChildBefore.md` | add before | true | UID000073 | `92/94`, pos 50 | implemented/validated; 541 bytes; SHA `1C87575F...DB3C` |
| `0x004f0a60-0x004f0b3d` | UID0004NV `0x004f0a60-0x004f0b3d.LayerRemoveChild.md` | remove child | true | UID000073 | `92/94`, pos 60 | implemented/validated; 221 bytes; SHA `EEB31FA5...79B1` |
| `0x004f0b40-0x004f0b79` | UID0004NW `0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion.md` | mark every pane represented by top-level Layer rows | true | UID000073 | `91/94`, pos 70 | implemented/validated; 57 bytes; SHA `520B780E...5CE9` |
| `0x004f0b80-0x004f0c9f` | UID0004NX `0x004f0b80-0x004f0c9f.LayerSetPaneFlagsMasked.md` | raw masked setter | true | UID000073 | `91/93`, pos 80 | implemented/validated retained raw; 287 bytes; SHA `81129CBB...1F31` |
| `0x004f0ca0-0x004f0d11` | UID0004NY `0x004f0ca0-0x004f0d11.LayerGetPaneFlags.md` | raw flags getter | true | UID000073 | `90/93`, pos 90 | implemented/validated retained raw; 113 bytes; SHA `DEC7C2A0...0CE5` |
| `0x004f0d20-0x004f0d93` | UID0004NZ `0x004f0d20-0x004f0d93.LayerContainsPane.md` | membership | true | UID000073 | `91/94`, pos 100 | implemented/validated; 115 bytes; SHA `2F09F695...5BB7` |
| `0x004f0da0-0x004f0f27` | UID0004O0 `0x004f0da0-0x004f0f27.LayerInvalidatePaneRegion.md` | dirty invalidation | true | UID000073 | `92/94`, pos 110 | implemented/validated; 391 bytes; SHA `C734DCE8...48A4` |
| `0x004f0f30-0x004f0f42` | UID0004O1 `0x004f0f30-0x004f0f42.LayerClearDirtyRegion.md` | clear root dirty | true | UID000073 | `92/94`, pos 120 | implemented/validated; 18 bytes; SHA `33F1B990...3A67` |
| `0x004f0f50-0x004f0f68` | UID0004O2 `0x004f0f50-0x004f0f68.LayerCopyDirtyRegion.md` | copy root dirty | true | UID000073 | `92/94`, pos 130 | implemented/validated; 24 bytes; SHA `C1C7AE2A...99BD` |
| `0x004f0f70-0x004f0f82` | UID0004O3 `0x004f0f70-0x004f0f82.LayerUnionDirtyRegion.md` | union root dirty | true | UID000073 | `92/94`, pos 140 | implemented/validated; 18 bytes; SHA `CA69F026...F8B6` |
| `0x004f0f90-0x004f0fca` | UID0004O4 `0x004f0f90-0x004f0fca.LayerCollectDirtyRegion.md` | collect/update root | true | UID000073 | `92/94`, pos 150 | implemented/validated; 58 bytes; SHA `0858B158...751F` |
| `0x004f0fd0-0x004f0fe1` | UID0004O5 `0x004f0fd0-0x004f0fe1.LayerPropagateDirtyRegion.md` | propagate wrapper | true | UID000073 | `92/94`, pos 160 | implemented/validated; 17 bytes; SHA `566EB137...D203` |
| `0x004f0ff0-0x004f138b` | UID0004O6 `0x004f0ff0-0x004f138b.LayerRenderRecursive.md` | render traversal | true | UID000073 | `92/94`, pos 170 | implemented/validated; 923 bytes; SHA `0B9F9639...F5CF` |
| `0x004f1390-0x004f1391` | UID0004O7 `0x004f1390-0x004f1391.LayerEndRender.md` | source no-op member | true | UID000073 | `91/94`, pos 180 | implemented/validated; one-byte ret; SHA `AE3F4619...359E` |
| `0x004f13a0-0x004f1411` | UID0004O8 `0x004f13a0-0x004f1411.LayerGetChildList.md` | raw child-list getter | true | UID000073 | `90/93`, pos 190 | implemented/validated retained raw; 113 bytes; SHA `13B43841...1622` |
| `0x004f1420-0x004f1499` | UID0004O9 `0x004f1420-0x004f1499.LayerGetParentPane.md` | parent lookup | true | UID000073 | `92/94`, pos 200 | implemented/validated; 121 bytes; SHA `AB98BB39...C32B` |
| `0x004f14a0-0x004f1593` | UID0004OA `0x004f14a0-0x004f1593.LayerGetScreenOffset.md` | ancestor offset | true | UID000073 | `92/94`, pos 210 | implemented/validated; 243 bytes; SHA `F7E2B00A...272B` |
| `0x004f15a0-0x004f1906` | UID0004OB `0x004f15a0-0x004f1906.LayerUpdateDirtyRegionsRecursive.md` | bounds/motion update | true | UID000073 | `92/94`, pos 220 | implemented/validated; 870 bytes; SHA `8290EFF0...E00D` |
| `0x004f1910-0x004f1a42` | UID0004OC `0x004f1910-0x004f1a42.LayerPropagateDirtyRegionRecursive.md` | static dirty recursion | true | UID000073 | `92/94`, pos 230 | implemented/validated; 306 bytes; SHA `99D668F8...BADB` |
| `0x004f1a50-0x004f1aa5` | UID0004OD `0x004f1a50-0x004f1aa5.LayerDestroyNodeRegions.md` | static Region cleanup | true | UID000073 | `92/94`, pos 240 | implemented/validated; 85 bytes; SHA `7531BEA2...8D41` |
| `0x004f1ab0-0x004f1b32` | UID0004OE `0x004f1ab0-0x004f1b32.LayerFindPaneNode.md` | recursive search | true | UID000073 | `92/94`, pos 250 | implemented/validated; 130 bytes; SHA `A5D5FA11...4EE6` |
| `0x004f1b40-0x004f1bf6` | UID0004OF `0x004f1b40-0x004f1bf6.LayerScalarDeletingDestructor.md` | compiler scalar wrapper | false | none | `91/94`, no position | implemented/validated declaration-generated no-code; 182 bytes; SHA `3DC2E187...AE2` |
| `0x004f1c00-0x004f3017` | UID00018X `0x004f1c00-0x004f3017.InputPaneBases.md` | following address-sorted sibling / hierarchy closure | false | none | `90/92` unchanged | relative `Nested:-4` only; generated level returns from 215 to UID00018V/UID00018W baseline 211 |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f0480` | Application::Startup calls at `0x004f6227/6256/6285/62b4/62e3/6312` | Six MainUiLayerSlots client objects. |
| `0x004f0480` | `0x0050f326`, `0x00512722`, `0x00546b3b` | WorldMapPane factory, UID0003TP packet path, FlyingParcelPane animation-layer clients. |
| `0x004f05a0` | no direct code caller; vtable write refs only | Ordinary virtual destructor source, invoked through ABI dispatch/cleanup. |
| `0x004f0630` | Pane::AddToLayer at `0x00544c93` | Public add-after wrapper. |
| `0x004f0840` | Pane::InsertInLayer at `0x00544cc6` | Public add-before wrapper. |
| `0x004f0a60` | Pane destructor/remove/scalar paths `0x0054460a`, `0x00544d19`, `0x00544fe1` | Three detach routes. |
| `0x004f0b40` | `0x004f7d53` in `MainMenuPane::InitializeMainUiGraph`, `0x00504837` in MapPane teardown/reset | Both invoke `MarkAllPanesForDeletion`; the helper indexes all top-level Layer rows and delegates each surviving pane to Pane::MarkForDeletion. |
| raw flags/getters | no recovered direct xrefs | Retained source methods; ordinary precompiled unused members, not compiler glue. |
| `0x004f0d20` | Pane::IsAttachedToLayer at `0x00544c60` | Membership query. |
| `0x004f0da0` | Pane invalidation path at `0x005449c3` | Propagates pane-local invalid region into Layer hierarchy. |
| `0x004f0f30/50/70/90/d0/ff0/1390` | ScreenPane::TraversePresentationList `0x005594a0/51e/529/4af/533/547/554` | Exact reverse dirty and forward render sequence. |
| `0x004f0ff0` | self-recursive call at `0x004f12fe` | Descends child HierLists unless pane blocks traversal. |
| `0x004f1420` | Pane primary parent lookup at `0x005447ae` | Returns containing parent pane. |
| `0x004f14a0` | callers `0x0046c4f1`, `0x005447d3`, `0x00544e46` | Native-window, Pane, and adjusted input coordinate routes. |
| `0x004f15a0` | root call `0x004f0fb4`, self call `0x004f18a5` | Recursive bounds/motion dirty update. |
| `0x004f1910` | root call `0x004f0fdb`, self call `0x004f1a02` | Recursive parent-dirty propagation. |
| `0x004f1a50` | ordinary destructor `0x004f05f9`, RemoveChild `0x004f0afd`, self `0x004f1a7b`, scalar wrapper `0x004f1ba0` | Deletes per-node Regions without duplicating HierList row lifetime. |
| `0x004f1ab0` | thirteen Layer-internal search calls | Shared recursive lookup with optional owner-list/index outputs. |
| `0x004f1b40` | data xref only from vtable slot `0x0061ca48` | Compiler scalar deleting destructor. |

## Documentation Evidence And IDA Status

- Existing docs correctly establish Layer/Pane/HierList/Region/ScreenPane relationships, `ui/core` placement, vtable address, and broad method families.
- Before callback, existing docs were stale where they claimed 22 bodies were complete, dismissed raw gaps, left LayerNode unresolved, described `0x004f1390` as optional, or retained a possible render-source split; the accepted callback historicalized or replaced each of those claims.
- Historical pre-callback generated state: `Layer.cpp` was 506 bytes and contained only UID000073/UID00018W Empty Emitter Markers under command `000000011019`. Current waited output is recorded under Validator Results.
- Evidence-time manual coverage was stale for UID00018W, UID000073, UID0000KL, UID000065, the child rows, UID0003A3, and UID0003OK. B001 did not apply coverage; the exact real-UID synchronization text remains external supervisor-owned below.

## Ranked Ownership Analysis

### 1. UID000073 Layer through UID0000KL Layer.cpp

- Evidence for: unique Layer RTTI/vtable, 8-byte receiver, contiguous complete class body island, direct Pane API callers, private recursive helpers, established source tree, and shared constructor clients.
- Evidence against: original PDB/header spelling is absent.
- Decision: accepted semantic owner/emitter route for class declaration and 24 source children.

### 2. UID0000A2/UID0000MC Pane

- Evidence for: Pane owns public attach/remove/invalidation/offset wrappers and supplies many accessed fields/virtual operations.
- Evidence against: Layer has distinct object state, RTTI, vtable, lifetime, recursive tree, and source island.
- Decision: caller/dependency only.

### 3. ScreenPane, MapPane, or render-side module

- Evidence for: ScreenPane drives presentation; MapPane has a special effect branch; rendering dominates several larger helpers.
- Evidence against: both consume Layer's public/private methods, while construction/tree/search/destruction and rendering are one class/source sequence. No separate RTTI/object/source boundary exists.
- Decision: rejected as owners and rejected as source split.

### New file/grouping analysis

- Applied owner/name/path: no new by-file owner; `NexusTK/ui/core/Layer.cpp` is retained.
- Likely full contents: Layer declaration plus the 24 source children in positions 20-250; compiler emits vtable/scalar glue.
- Candidate related items rejected: Pane wrappers remain Pane.cpp, ScreenPane traversal remains ScreenPane.cpp, HierList implementation remains util/HierList.cpp, Region/Motion implementation remains its current source family.
- Standalone/narrow/broad inference: one narrow class source, with `LayerNode` most plausibly declared in Layer's header or implementation-private declaration consumed by Layer.cpp.

## Source Placement

- Applied placement: UID000073 class declaration and all source-authored exact children emit through UID0000KL at `NexusTK/ui/core/Layer.cpp`.
- This fits current source tree, contiguous link order, class RTTI/vtable, Pane peer relationship, and generic UI clients.
- Rejected placements: MapPane.cpp (special consumer only), ScreenPane.cpp (presentation driver only), HierList.cpp (generic container dependency), render/GrafPort.cpp (drawing dependency only).
- Remaining uncertainty: whether `LayerNode` originally lived in Layer.h or privately in Layer.cpp; generated destination and behavior are unchanged, so this caps confidence only.

## Range / Split / Padding / Reclassification Analysis

- Parent exact range remains unchanged; only its emission/nesting and exact children change.
- The callback created the children serially in the inventory's address order and captured each validator-issued UID before adding it to UID00018W, UID000073, UID0000KL, manual coverage text, or sibling links.
- Internal ignored spans, all exact `cc` bytes: `[4f0597,4f05a0)` 9; `[4f062a,4f0630)` 6; `[4f083c,4f0840)` 4; `[4f0a5d,4f0a60)` 3; `[4f0b3d,4f0b40)` 3; `[4f0b79,4f0b80)` 7; `[4f0c9f,4f0ca0)` 1; `[4f0d11,4f0d20)` 15; `[4f0d93,4f0da0)` 13; `[4f0f27,4f0f30)` 9; `[4f0f42,4f0f50)` 14; `[4f0f68,4f0f70)` 8; `[4f0f82,4f0f90)` 14; `[4f0fca,4f0fd0)` 6; `[4f0fe1,4f0ff0)` 15; `[4f138b,4f1390)` 5; `[4f1391,4f13a0)` 15; `[4f1411,4f1420)` 15; `[4f1499,4f14a0)` 7; `[4f1593,4f15a0)` 13; `[4f1906,4f1910)` 10; `[4f1a42,4f1a50)` 14; `[4f1aa5,4f1ab0)` 11; `[4f1b32,4f1b40)` 14.
- Representative hashes: 9-byte spans `57C1D0AA...51CE`; 6-byte spans `33CC4A00...E722`; 4-byte span `8843B54D...41CA`; 3-byte spans `E668F0A1...ECEE`; 7-byte spans `F145ECA6...368D`; 1-byte span `1DD83126...87D6`; 15-byte spans `54CC9DD9...624C`; 13-byte spans `0D0BB866...F1CE`; 14-byte spans `1E875C76...4356`; 8-byte span `3D2F4247...64C3`; 5-byte span `992CF514...7329`; 10-byte span `22E52BBA...045`; 11-byte span `3682C0A6...0943`.
- Existing external predecessor/successor ignored rows were verified correct and preserved.
- Relative hierarchy impact: UID00018W is `Nested:0` at the UID00018V baseline; first child UID0004NR is `Nested:4`; UID0004NS through UID0004OF are `Nested:0` continuations; following UID00018X is `Nested:-4`. The parent remains non-reconstructable with no owner/emitter/formal C++, all 25 children remain exact leaves, and generated leading levels prove `211 -> 211 -> 215 ... 215 -> 211` with no hierarchy leak.

## Negative Evidence Summary

- No direct target report, PDB UDT, source file artifact, alternate entry, code chunk, embedded table, or non-Layer RTTI route was found.
- Constructor consumers do not establish ownership: six globals, WorldMapPane, and FlyingParcelPane own Layer objects but not Layer source.
- ScreenPane's list and calls do not make helpers ScreenPane methods; each list element is a Layer pointer and ECX confirms Layer receivers.
- MapPane's active effect branch does not make RenderRecursive a MapPane method.
- `0x004f1390` is not a virtual callback slot; direct caller evidence rejects that old wording.
- Raw methods' zero xrefs do not prove dead/invalid code. Their complete ABI, shared private lookup, and exact class fields prove retained source members.
- Scalar wrapper's vtable reachability does not justify handwritten source; virtual destructor declaration is its source cause.

## IDA Rename / Type / Comment Recommendations

- Source-facing names/types: `LayerNode`, `m_nodes`, `pane`, `paneFlags`, `bounds`, `previousBounds`, `visible`, `blocksChildTraversal`, `dirty`, `dirtyRegion`; method names exactly as the inventory paths.
- Evidence: direct offsets/operations, existing Pane/HierList/Region names, caller semantics, and source-order grouping.
- Preserve `sub_...`, `nullsub_11`, raw-offset labels, `ScreenLayerEntry`, and `LayerNode::Render...` only in historical evidence; do not emit them.
- No IDA DB rename/type/comment mutation was requested or performed. The accepted source-facing names were applied only to ordinary by-* documentation and formal C++ during the callback.

## First-Draft C++ Recommendation

- Applied C++ destinations: UID000073 Layer declaration, 24 source-authored exact children, and the corrected complete UID0003A3 ScreenPane caller block.
- Compiler-only/no-code dispositions are applied: UID00018W and UID0004OF remain blank; UID0003OK is declaration-generated and non-emitting, so no standalone vtable body is handwritten.
- Whole-report managed-block count: 27 populated destination blocks: one Layer declaration, 24 Layer source bodies, one full HierList declaration replacement, and one full ScreenPane traversal replacement. Exact normalized callback readback matched all 27; no other C++ or declaration change exists outside these blocks.
- Behavior/source-shape policy: direct bounds, order, asymmetries, null/precondition behavior, recursion, effect routing, and cleanup are preserved; EH state, stack cookies, vptr stores, scalar-delete flags, allocation null scaffolding, and explicit base teardown are omitted as compiler output.
- Third-party import directive: not applicable; this is NexusTK-owned project source.

Destination 1: `by-class/Layer.md`; complete declaration at owner/file position 10.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct LayerNode {
    Pane *pane;
    unsigned char paneFlags;
    unsigned char padding05[3];
    RectBounds bounds;
    RectBounds previousBounds;
    bool visible;
    bool blocksChildTraversal;
    bool dirty;
    unsigned char padding2B;
    Region *dirtyRegion;
};

class Layer : public LObject {
public:
    Layer();
    virtual ~Layer();

    void AddChildAfter(const RectBounds *bounds, Pane *pane,
        Pane *referencePane, Pane *parentPane);
    void AddChildBefore(const RectBounds *bounds, Pane *pane,
        Pane *referencePane, Pane *parentPane);
    void RemoveChild(Pane *pane);
    void MarkAllPanesForDeletion();
    void SetPaneFlagsMasked(Pane *pane, unsigned char value,
        unsigned char mask);
    unsigned char GetPaneFlags(Pane *pane) const;
    bool ContainsPane(Pane *pane) const;
    void InvalidatePaneRegion(Pane *pane, const RectBounds *bounds);

    void ClearDirtyRegion();
    void CopyDirtyRegion(Region *region) const;
    void UnionDirtyRegion(const Region *region);
    void CollectDirtyRegion(Region *region, Region *pendingRegion);
    void PropagateDirtyRegion();
    bool RenderRecursive(GrafPort *grafPort, int xOffset, int yOffset,
        Region *renderedRegion, HierList *list = NULL);
    void EndRender();

    HierList *GetChildList(Pane *pane) const;
    Pane *GetParentPane(Pane *pane) const;
    void GetScreenOffset(Point *offset, Pane *pane) const;

private:
    static LayerNode *NodeData(HierListNode *node)
    {
        return reinterpret_cast<LayerNode *>(node->payload);
    }

    static HierListNode *NodeHeader(LayerNode *node)
    {
        return reinterpret_cast<HierListNode *>(
            reinterpret_cast<unsigned char *>(node) - 8);
    }

    static LayerNode *NodeAt(HierList *list, int index)
    {
        return static_cast<LayerNode *>(list->GetElementAt(index));
    }

    HierListNode *RootNode() const
    {
        return m_nodes->ownerNode;
    }

    HierListNode *FindPaneNode(Pane *pane, HierList **ownerList = NULL,
        int *index = NULL, HierList *list = NULL) const;
    void UpdateDirtyRegionsRecursive(LayerNode *parentNode,
        HierList *list, Region *dirtyRegion);
    static void PropagateDirtyRegionRecursive(LayerNode *parentNode,
        HierList *list);
    static void DestroyNodeRegions(HierList *list);

    HierList *m_nodes;

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 2: `by-memory/0x004f0480-0x004f0597.LayerConstructor.md`; position 20.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Layer::Layer()
    : m_nodes(NULL)
{
    MemoryMan *memoryMan = GetMemoryMan();
    HierListNode *root = static_cast<HierListNode *>(
        memoryMan->AllocateBufferMemory(sizeof(LayerNode) + 11));
    root->parent = NULL;

    LayerNode *rootNode = NodeData(root);
    rootNode->pane = g_pScreenPane;
    InitRectBounds(&rootNode->bounds, 0, 0, g_screenWidth, g_screenHeight);
    InitRectBounds(
        &rootNode->previousBounds, 0, 0, g_screenWidth, g_screenHeight);
    rootNode->visible = false;
    rootNode->blocksChildTraversal = false;
    rootNode->dirty = false;
    rootNode->dirtyRegion = new Region;

    m_nodes = new HierList(sizeof(LayerNode), root);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 3: `by-memory/0x004f05a0-0x004f062a.LayerDestructor.md`; position 30.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Layer::~Layer()
{
    if (m_nodes != NULL) {
        HierListNode *root = RootNode();
        if (root != NULL) {
            delete NodeData(root)->dirtyRegion;
            GetMemoryMan()->FreeBufferMemory(root);
        }

        DestroyNodeRegions(m_nodes);
        delete m_nodes;
        m_nodes = NULL;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 4: `by-memory/0x004f0630-0x004f083c.LayerAddChildAfter.md`; position 40. The intentionally unassigned `paneFlags`, padding, and `previousBounds` fields preserve the observed stack-copy behavior.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::AddChildAfter(const RectBounds *bounds, Pane *pane,
    Pane *referencePane, Pane *parentPane)
{
    pane->SetBounds(bounds, false);

    RectBounds localBounds = *bounds;
    OffsetRect(&localBounds, -localBounds.left, -localBounds.top);
    pane->InvalidateRect(&localBounds);

    LayerNode *parentNode = NULL;
    if (parentPane != NULL) {
        HierListNode *node = FindPaneNode(parentPane);
        parentNode = NodeData(node);
    }

    LayerNode *referenceNode = NULL;
    if (referencePane != NULL) {
        HierListNode *node = FindPaneNode(referencePane);
        referenceNode = NodeData(node);
    }

    LayerNode node;
    node.pane = pane;
    InitRectBounds(&node.bounds, 0, 0, 0, 0);
    node.visible = pane->IsVisible();
    node.blocksChildTraversal = pane->BlocksChildTraversal();
    node.dirty = false;
    node.dirtyRegion = new Region;

    m_nodes->InsertAfter(parentNode, referenceNode, &node);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 5: `by-memory/0x004f0840-0x004f0a5d.LayerAddChildBefore.md`; position 50. The intentionally unassigned `paneFlags` and padding preserve the observed stack-copy behavior.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::AddChildBefore(const RectBounds *bounds, Pane *pane,
    Pane *referencePane, Pane *parentPane)
{
    pane->SetBounds(bounds, false);

    RectBounds localBounds = *bounds;
    OffsetRect(&localBounds, -localBounds.left, -localBounds.top);
    pane->InvalidateRect(&localBounds);

    LayerNode *parentNode = NULL;
    if (parentPane != NULL) {
        HierListNode *node = FindPaneNode(parentPane);
        parentNode = NodeData(node);
    }

    LayerNode *referenceNode = NULL;
    if (referencePane != NULL) {
        HierListNode *node = FindPaneNode(referencePane);
        referenceNode = NodeData(node);
    }

    LayerNode node;
    node.pane = pane;
    InitRectBounds(&node.bounds, 0, 0, 0, 0);
    InitRectBounds(&node.previousBounds, 0, 0, 0, 0);
    node.visible = pane->IsVisible();
    node.blocksChildTraversal = pane->BlocksChildTraversal();
    node.dirty = false;
    node.dirtyRegion = new Region;

    m_nodes->InsertBefore(parentNode, referenceNode, &node);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 6: `by-memory/0x004f0a60-0x004f0b3d.LayerRemoveChild.md`; position 60.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::RemoveChild(Pane *pane)
{
    HierListNode *node = FindPaneNode(pane);
    if (node == NULL) {
        return;
    }

    LayerNode *data = NodeData(node);
    delete data->dirtyRegion;
    data->dirtyRegion = NULL;

    if (node->childList != NULL) {
        DestroyNodeRegions(node->childList);
    }

    Pane *parentPane = NodeData(node->parent)->pane;
    RectBounds bounds;
    pane->GetBounds(&bounds);
    parentPane->InvalidateRect(&bounds);

    m_nodes->RemoveByPayload(data);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 7: `by-memory/0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion.md`; position 70.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::MarkAllPanesForDeletion()
{
    const int count = m_nodes->GetCount();
    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(m_nodes, index);
        if (node != NULL && node->pane != NULL) {
            node->pane->MarkForDeletion();
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 8: `by-memory/0x004f0b80-0x004f0c9f.LayerSetPaneFlagsMasked.md`; position 80.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::SetPaneFlagsMasked(Pane *pane, unsigned char value,
    unsigned char mask)
{
    HierListNode *node = FindPaneNode(pane);
    LayerNode *data = NodeData(node);
    unsigned char oldFlags = data->paneFlags;
    unsigned char newFlags =
        (oldFlags & static_cast<unsigned char>(~mask)) | (value & mask);

    if ((oldFlags & 1) != (newFlags & 1)) {
        InitRectBounds(&data->bounds, 0, 0, 0, 0);
        InitRectBounds(&data->previousBounds, 0, 0, 0, 0);
        data->visible = pane->IsVisible();
        data->blocksChildTraversal = pane->BlocksChildTraversal();
        data->dirty = false;
        data->dirtyRegion->SetEmpty();

        if ((newFlags & 1) == 0) {
            RectBounds bounds;
            pane->GetBounds(&bounds);
            NodeData(node->parent)->pane->InvalidateRect(&bounds);
        }
    }

    data->paneFlags = newFlags;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 9: `by-memory/0x004f0ca0-0x004f0d11.LayerGetPaneFlags.md`; position 90. The missing-node dereference is intentional and preserves the attached-pane precondition.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned char Layer::GetPaneFlags(Pane *pane) const
{
    return NodeData(FindPaneNode(pane))->paneFlags;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 10: `by-memory/0x004f0d20-0x004f0d93.LayerContainsPane.md`; position 100.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool Layer::ContainsPane(Pane *pane) const
{
    return FindPaneNode(pane) != NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 11: `by-memory/0x004f0da0-0x004f0f27.LayerInvalidatePaneRegion.md`; position 110.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::InvalidatePaneRegion(Pane *pane, const RectBounds *bounds)
{
    HierListNode *node = FindPaneNode(pane);
    if (node == NULL) {
        return;
    }

    Region dirtyRegion;
    Region paneRegion;
    dirtyRegion.SetRect(bounds);
    pane->GetRenderRegion(&paneRegion);
    dirtyRegion.IntersectWith(paneRegion);

    RectBounds paneBounds;
    pane->GetBounds(&paneBounds);
    dirtyRegion.IntersectWithRect(&paneBounds);

    LayerNode *data = NodeData(node);
    data->dirty = true;
    data->dirtyRegion->UnionWith(dirtyRegion);

    HierListNode *root = RootNode();
    while (node != root) {
        Point offset;
        data->pane->GetLocalOffset(&offset);
        dirtyRegion.Offset(offset.y, offset.x);

        node = node->parent;
        data = NodeData(node);
        data->dirty = true;
        data->dirtyRegion->UnionWith(dirtyRegion);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 12: `by-memory/0x004f0f30-0x004f0f42.LayerClearDirtyRegion.md`; position 120.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::ClearDirtyRegion()
{
    LayerNode *root = NodeData(RootNode());
    root->dirty = false;
    root->dirtyRegion->SetEmpty();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 13: `by-memory/0x004f0f50-0x004f0f68.LayerCopyDirtyRegion.md`; position 130.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::CopyDirtyRegion(Region *region) const
{
    region->CopyRectFrom(*NodeData(RootNode())->dirtyRegion);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 14: `by-memory/0x004f0f70-0x004f0f82.LayerUnionDirtyRegion.md`; position 140.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::UnionDirtyRegion(const Region *region)
{
    NodeData(RootNode())->dirtyRegion->UnionWith(*region);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 15: `by-memory/0x004f0f90-0x004f0fca.LayerCollectDirtyRegion.md`; position 150.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::CollectDirtyRegion(Region *region, Region *pendingRegion)
{
    LayerNode *root = NodeData(RootNode());
    root->dirtyRegion->UnionWith(*pendingRegion);
    UpdateDirtyRegionsRecursive(root, m_nodes, pendingRegion);
    region->CopyRectFrom(*root->dirtyRegion);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 16: `by-memory/0x004f0fd0-0x004f0fe1.LayerPropagateDirtyRegion.md`; position 160.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::PropagateDirtyRegion()
{
    PropagateDirtyRegionRecursive(NodeData(RootNode()), m_nodes);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 17: `by-memory/0x004f0ff0-0x004f138b.LayerRenderRecursive.md`; position 170. `Pane` accessors used here are source-facing inline/virtual names for the exact direct fields and slots recorded in the destination evidence.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool Layer::RenderRecursive(GrafPort *grafPort, int xOffset, int yOffset,
    Region *renderedRegion, HierList *list)
{
    bool rendered = false;
    if (list == NULL) {
        list = m_nodes;
    }

    LayerNode *owner = NodeData(list->ownerNode);
    Region parentRegion;
    owner->pane->GetRenderRegion(&parentRegion);

    RectBounds ownerBounds;
    owner->pane->GetBounds(&ownerBounds);
    parentRegion.IntersectWithRect(&ownerBounds);
    parentRegion.Offset(yOffset, xOffset);

    RectBounds screenBounds;
    InitRectBounds(&screenBounds, 0, 0, g_screenWidth, g_screenHeight);

    const int count = list->GetCount();
    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(list, index);
        Pane *pane = node->pane;
        if (!pane->IsVisible()) {
            continue;
        }

        Point origin;
        pane->GetLocalOffset(&origin);
        origin.x += xOffset;
        origin.y += yOffset;

        if (node->dirty) {
            rendered = true;

            if (pane->GetMode() != 4) {
                Region drawRegion;
                drawRegion.CopyRectFrom(*node->dirtyRegion);

                RectBounds paneBounds;
                pane->GetBounds(&paneBounds);
                drawRegion.IntersectWithRect(&paneBounds);

                Region paneRegion;
                pane->GetRenderRegion(&paneRegion);
                drawRegion.IntersectWith(paneRegion);
                drawRegion.Offset(origin.y, origin.x);
                drawRegion.IntersectWith(parentRegion);
                drawRegion.IntersectWithRect(&screenBounds);

                Region localRegion;
                localRegion.CopyRectFrom(drawRegion);
                localRegion.Offset(-origin.y, -origin.x);
                grafPort->SetClipRegion(&drawRegion);

                RectBounds clipBounds;
                RectBounds localBounds;
                localRegion.GetRect(&clipBounds);
                drawRegion.GetRect(&localBounds);

                if (!IsRectEmptyOrInvalid(&clipBounds)) {
                    if (pane->UsesCustomPaint()) {
                        grafPort->BeginPaint();
                        pane->OnPaint(grafPort, &clipBounds, &localBounds);
                        grafPort->EndPaint();
                    } else if (g_pActiveMapPane != NULL
                        && pane == g_pActiveMapPane
                        && g_pActiveMapPane->HasScreenEffecters()) {
                        ScreenEffecter *effecter =
                            g_pActiveMapPane->FindActivePixelEffecter();
                        if (effecter != NULL) {
                            effecter->Apply(grafPort, &clipBounds, &localBounds);
                        } else {
                            grafPort->DrawPane(
                                pane, &clipBounds, &localBounds, pane->GetMode());
                        }
                    } else {
                        grafPort->DrawPane(
                            pane, &clipBounds, &localBounds, pane->GetMode());
                    }

                    renderedRegion->UnionWithRect(&localBounds);
                }
            }

            node->dirty = false;
            node->dirtyRegion->SetEmpty();
        }

        HierListNode *header = NodeHeader(node);
        if (header->childList != NULL && !node->blocksChildTraversal) {
            if (RenderRecursive(grafPort, origin.x, origin.y,
                    renderedRegion, header->childList)) {
                rendered = true;
            }
        }
    }

    return rendered;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 18: `by-memory/0x004f1390-0x004f1391.LayerEndRender.md`; position 180. The empty source body is retained because ScreenPane makes a direct non-virtual call after each layer render; it is not compiler padding or a vtable hook.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::EndRender()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 19: `by-memory/0x004f13a0-0x004f1411.LayerGetChildList.md`; position 190. The attached-pane precondition and consequent missing-node dereference are intentional.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
HierList *Layer::GetChildList(Pane *pane) const
{
    return FindPaneNode(pane)->childList;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 20: `by-memory/0x004f1420-0x004f1499.LayerGetParentPane.md`; position 200. This preserves the binary's owner-list lookup and root-parent null return.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Pane *Layer::GetParentPane(Pane *pane) const
{
    HierList *ownerList;
    FindPaneNode(pane, &ownerList);

    HierListNode *parent = ownerList->ownerNode;
    return parent != NULL ? NodeData(parent)->pane : NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 21: `by-memory/0x004f14a0-0x004f1593.LayerGetScreenOffset.md`; position 210.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::GetScreenOffset(Point *offset, Pane *pane) const
{
    InitPointPair(offset, 0, 0);

    HierListNode *node = FindPaneNode(pane);
    if (node == NULL) {
        InitPointPair(offset, -1000, -1000);
        return;
    }

    HierListNode *root = RootNode();
    while (node != root) {
        Point localOffset;
        NodeData(node)->pane->GetLocalOffset(&localOffset);
        offset->x += localOffset.x;
        offset->y += localOffset.y;
        node = node->parent;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 22: `by-memory/0x004f15a0-0x004f1906.LayerUpdateDirtyRegionsRecursive.md`; position 220. The Pane method names express the exact direct/virtual roles at `0x005446e0`, `0x004b8dd0`, `0x00544ae0`, `0x00544b50`, and vtable `+0x28/+0x44`; the destination evidence retains those addresses so naming inference cannot erase behavior.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::UpdateDirtyRegionsRecursive(LayerNode *parentNode,
    HierList *list, Region *dirtyRegion)
{
    HierListNode *root = RootNode();
    const int count = list->GetCount();

    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(list, index);
        HierListNode *header = NodeHeader(node);
        Pane *pane = node->pane;

        if (pane != NULL && pane->HasPendingMotion()) {
            Region motionRegion;
            Region paneRegion;
            pane->GetCurrentMotionRegion(&motionRegion);
            pane->GetRenderRegion(&paneRegion);
            motionRegion.IntersectWith(paneRegion);
            pane->BeginMotionPaint();
            if (!pane->SuppressesMotionRefresh()) {
                pane->RefreshMotionLayout();
            }
            pane->EndMotionPaint();

            HierListNode *ancestor = header;
            Pane *ancestorPane = pane;
            while (ancestor != root) {
                Point ancestorOffset;
                ancestorPane->GetLocalOffset(&ancestorOffset);
                motionRegion.Offset(ancestorOffset.y, ancestorOffset.x);
                ancestor = ancestor->parent;
                ancestorPane = NodeData(ancestor)->pane;
            }

            LayerNode *ancestorNode = NodeData(ancestor);
            ancestorNode->dirty = true;
            ancestorNode->dirtyRegion->UnionWith(motionRegion);
            if (pane->GetMode() != 0) {
                dirtyRegion->UnionWith(motionRegion);
            } else {
                dirtyRegion->Subtract(motionRegion);
            }
        }

        RectBounds currentBounds;
        pane->GetBounds(&currentBounds);
        if (currentBounds != node->bounds) {
            Region currentRegion;
            pane->GetRenderRegion(&currentRegion);
            currentRegion.Offset(currentBounds.top, currentBounds.left);
            currentRegion.IntersectWithRect(&currentBounds);

            RectBounds currentRegionBounds;
            currentRegion.GetRect(&currentRegionBounds);

            Region changedRegion;
            changedRegion.SetRect(&currentRegionBounds);
            changedRegion.UnionWithRect(&node->previousBounds);

            Region previousRegion;
            parentNode->pane->GetRenderRegion(&previousRegion);
            changedRegion.IntersectWith(previousRegion);

            HierListNode *ancestor = header->parent;
            Pane *ancestorPane = NodeData(ancestor)->pane;
            while (ancestor != root) {
                Point ancestorOffset;
                ancestorPane->GetLocalOffset(&ancestorOffset);
                changedRegion.Offset(ancestorOffset.y, ancestorOffset.x);
                ancestor = ancestor->parent;
                ancestorPane = NodeData(ancestor)->pane;
            }

            LayerNode *ancestorNode = NodeData(ancestor);
            ancestorNode->dirty = true;
            ancestorNode->dirtyRegion->UnionWith(changedRegion);
            if (currentRegionBounds != node->previousBounds) {
                dirtyRegion->UnionWith(changedRegion);
            }

            node->bounds = currentBounds;
            node->previousBounds = currentRegionBounds;
        }

        if (header->childList != NULL && !node->blocksChildTraversal) {
            UpdateDirtyRegionsRecursive(node, header->childList, dirtyRegion);
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 23: `by-memory/0x004f1910-0x004f1a42.LayerPropagateDirtyRegionRecursive.md`; position 230.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::PropagateDirtyRegionRecursive(LayerNode *parentNode,
    HierList *list)
{
    const int count = list->GetCount();
    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(list, index);
        HierListNode *header = NodeHeader(node);

        RectBounds bounds;
        node->pane->GetBounds(&bounds);

        Region childDirty;
        childDirty.CopyRectFrom(*parentNode->dirtyRegion);
        if (childDirty.IntersectWithRect(&bounds)) {
            childDirty.Offset(-bounds.top, -bounds.left);

            Region paneRegion;
            node->pane->GetRenderRegion(&paneRegion);
            childDirty.IntersectWith(paneRegion);

            node->dirty = true;
            node->dirtyRegion->UnionWith(childDirty);
        }

        if (header->childList != NULL && !node->blocksChildTraversal) {
            PropagateDirtyRegionRecursive(node, header->childList);
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 24: `by-memory/0x004f1a50-0x004f1aa5.LayerDestroyNodeRegions.md`; position 240.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Layer::DestroyNodeRegions(HierList *list)
{
    const int count = list->GetCount();
    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(list, index);
        HierListNode *header = NodeHeader(node);
        if (header->childList != NULL) {
            DestroyNodeRegions(header->childList);
        }
        delete node->dirtyRegion;
        node->dirtyRegion = NULL;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 25: `by-memory/0x004f1ab0-0x004f1b32.LayerFindPaneNode.md`; position 250.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
HierListNode *Layer::FindPaneNode(Pane *pane, HierList **ownerList,
    int *outIndex, HierList *list) const
{
    if (list == NULL) {
        list = m_nodes;
    }

    const int count = list->GetCount();
    for (int index = 0; index < count; ++index) {
        LayerNode *node = NodeAt(list, index);
        HierListNode *header = NodeHeader(node);
        if (node->pane == pane) {
            if (ownerList != NULL) {
                *ownerList = list;
            }
            if (outIndex != NULL) {
                *outIndex = index;
            }
            return header;
        }

        if (header->childList != NULL) {
            HierListNode *found = FindPaneNode(
                pane, ownerList, outIndex, header->childList);
            if (found != NULL) {
                return found;
            }
        }
    }

    return NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 26: `by-class/HierList.md`; complete replacement of the current declaration with the sole addition needed by exact Layer source access: `friend class Layer;`. All current API, inheritance, fields, and `[[CHILDREN]]` placement are retained.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct HierListNode;

class HierList : public List {
    friend class Layer;

public:
    HierList(int payloadSize, HierListNode *ownerNode);
    virtual ~HierList();

    void InsertLast(const void *parentPayload, const void *payload);
    void InsertFirst(const void *parentPayload, const void *payload);
    void InsertBefore(const void *parentPayload,
        const void *referencePayload, const void *payload);
    void InsertAfter(const void *parentPayload,
        const void *referencePayload, const void *payload);
    void RemoveByPayload(const void *payload);

    virtual void *GetElementAt(int index);
    virtual void InsertAt(int index, int count, void *source);
    virtual void Append(int count, void *source);
    virtual void RemoveAt(int index, int count);
    virtual void SwapElements(int firstIndex, int secondIndex);

protected:
    HierListNode *ownerNode;

private:
    HierListNode *FindNodeByPayload(const void *payload,
        HierList **outOwnerList, int *outIndex);
    void UpdateHierarchy(int firstIndex, int lastIndex, bool clearParent);

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 27: `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md`; complete replacement of the current block. The only Layer element type is `Layer *`, and the direct post-render no-op source method is retained exactly once per entry.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScreenPane::TraversePresentationList(Region *dirtyRegion)
{
    Region layerDirty;
    Region currentMotion;

    GetCurrentMotionRegion(&currentMotion);
    SubtractMotionFromDirtyRegion(&currentMotion);

    const int layerCount = m_rootLayerList->GetCount();
    const int lastLayer = layerCount - 1;

    for (int index = lastLayer; index >= 0; --index) {
        Layer *layer = static_cast<Layer *>(
            m_rootLayerList->GetElementAt(index));
        layer->ClearDirtyRegion();
        layer->CollectDirtyRegion(&layerDirty, &currentMotion);
        dirtyRegion->UnionWith(layerDirty);
    }

    void *savedSurface = m_grafPort.m_surface;
    m_grafPort.m_surface = m_presentationSurface;

    Point origin;
    InitPointPair(&origin, 0, 0);

    for (int index = 0; index < layerCount; ++index) {
        Layer *layer = static_cast<Layer *>(
            m_rootLayerList->GetElementAt(index));

        if (index < lastLayer) {
            Layer *nextLayer = static_cast<Layer *>(
                m_rootLayerList->GetElementAt(index + 1));
            layer->CopyDirtyRegion(&layerDirty);
            nextLayer->UnionDirtyRegion(&layerDirty);
        }

        layer->PropagateDirtyRegion();
        if (layer->RenderRecursive(
                &m_grafPort, origin.x, origin.y, &layerDirty, NULL)) {
            m_presentationDirty = true;
        }
        layer->EndRender();
    }

    m_grafPort.m_surface = savedSurface;

    if (m_hasPendingDirtyRegion) {
        m_presentationDirty = true;
        dirtyRegion->UnionWithRect(&m_pendingDirtyRegion);
        m_hasPendingDirtyRegion = false;
        InitRectBounds(&m_pendingDirtyRegion, 0, 0, 0, 0);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

## Final Recommendation

The 25-child split and source disposition are implemented exactly as specified. UID00018W is an aggregate/index, not a source emitter. Twenty-four children are ordinary Layer source methods emitted through UID000073/UID0000KL; UID0004OF is compiler ABI output and stays blank/non-emitting. The complete class declaration plus exact children remove the generated empty marker without duplicating aggregate, vtable, base-destructor, EH, or scalar-delete code. The relative Nested sequence is balanced rather than a child count: parent `0`, first child `4`, remaining children `0`, following UID00018X `-4`.

The three raw bodies must be retained as real source children even though IDA does not model them and no inbound xref was recovered. Their complete instruction sequences, placement among the modeled methods, receiver/data layout, and shared `FindPaneNode` structure outweigh the absence of callers. The coordinated B002 `0x004f0b40` finding is independently confirmed and incorporated as `Layer::MarkAllPanesForDeletion`; its `MainMenuPane::InitializeMainUiGraph` caller relationship is explicit, while `MarkRootPanesForDeletion` remains a rejected implementation-description alias.

## Recommended Target Doc Changes

- UID00018W is applied as `92/94`, NONE/FALSE, blank emitter/position/formal C++, and relative `Nested:0`, with all 25 real child UIDs, exact range/hash/padding, source/no-code split, and no aggregate emission.
- The 25 exact children were created and registered serially as UID0004NR-UID0004OF before parent/support links were added. Positions 20-250 apply to the 24 source methods; UID0004OF has no position.
- Source children carry owner/emitter UID000073, reconstructable true, exact scores/blocks, full evidence, and preserved raw/no-xref status. UID0004NR alone opens the manual/generated child level with `Nested:4`; UID0004NS-UID0004OF retain that level with `Nested:0`.
- UID0004OF is `91/94`, NONE/FALSE, blank emitter/position/C++, with exhaustive virtual-destructor/vtable/delete-flag/vptr/base-teardown/no-source-caller proof.
- `by-memory/-ignored.md` retains the external predecessor/successor and now records only the 24 proven internal all-`cc` spans; no code span was ignored.

## Recommended Support Doc Changes

- UID000073 is `92/94` at position 10 with Destination 1 and complete layout/method/lifetime/caller/vtable/inference/history; UID0000KL is `91/93` with the retained `NexusTK/ui/core/` route and exact emission policy.
- UID000065 remains `91/92` under UID0000JV and uses exact Destination 26 solely for Layer `ownerNode` access; generic container source remains HierList-owned.
- UID0003OK is `90/94`, declaration-generated/non-emitting with exact COL, three slots, xrefs, and inherited-slot proof; UID00025N remains `86/92` mixed/non-emitting with only bounded Layer synchronization.
- UID0003A3 is `90/92` with Destination 27, `Layer *`, direct EndRender, and historicalized ScreenLayerEntry/optional-nullsub wording.
- UID00018X retains all prior `90/92` non-emitting InputPaneBases content and receives only relative `Nested:-4` so the address-sorted by-memory hierarchy closes after UID0004OF.
- Pane class/file/Core, HierList insertion/removal/node type, Region/Motion, MainUiLayerSlots, Application, WorldMapPane, UID0003TP, FlyingParcel, MainMenuPane initialization, and MapPane teardown received only the accepted bounded relationships.
- UID0002I1/UID0002I2 already contained the exact render dependency and remained unchanged. No unrelated class/file/type/layout page received a score, route, or C++ change.

## Score And Metadata Recommendation

| Destination | Historical pre-callback | Current applied | Metadata disposition | Remaining cap |
| --- | --- | --- | --- | --- |
| UID00018W aggregate | `86/90`, emitting aggregate hypothesis | `92/94` | NONE/FALSE, blank emitter/position/C++, relative Nested 0 | Original private spellings only; callback UIDs/output verified. |
| UID000073 Layer class | `86/88` | `92/94` | UID0000KL/TRUE/UID0000KL, pos 10 | Original private helper spellings remain inferred. |
| UID0000KL Layer file | `86/86` | `91/93` | retain `NexusTK/ui/core/` route | Exact historical header/source split is not recoverable. |
| 24 source children | absent | `90-92/93-94` as inventoried | UID000073/TRUE/UID000073, pos 20-250; UID0004NR Nested 4, later children Nested 0 | Raw-child names and several Pane accessor spellings are inferred. |
| UID0004OF scalar child | absent | `91/94` | NONE/FALSE, blank emitter/position/C++ | Compiler family spelling is descriptive. |
| UID00018X following sibling | `90/92` | `90/92` unchanged | all metadata/formal content preserved except relative Nested -4 closure | InputPaneBases evidence and score are outside this Layer repair. |
| UID0003A3 | `87/89` | `90/92` | preserve owner/emitter UID0000NB | Original traversal method/member spellings remain inferred. |
| UID0003OK | `86/91` | `90/94` | UID0000KL semantic owner, FALSE, blank emitter/position/C++ | Exact historical linker ordering is not independently known. |

These applied scores exceed the evidence-time target because every range/body/route/layout/source disposition and generated blocker has a concrete resolution. None reaches 95 because original symbols are absent and three bodies remain raw/unreferenced; child identities and generated output are now validated.

## Open Questions With Attempted Resolution

- Original `LayerNode` type name: no symbols survive. `LayerNode` is accepted because the payload is Layer-private and every field is resolved; `LayerEntry`, `ScreenLayerEntry`, and `PaneNodeData` are ranked lower because the same payload serves non-ScreenPane clients and is not the hierarchy header itself.
- `0x004f0b40` spelling: `MarkAllPanesForDeletion` is accepted after independent binary validation plus B002's caller/source-family evidence. `MarkRootPanesForDeletion` precisely describes the implementation but is rejected as primary because the method semantically owns all Layer panes at its public boundary; `DeleteAllPanes` is rejected because it only marks panes.
- Raw helper liveness: no inbound xref was found, but each body is complete, positionally source-shaped, shares exact class internals, and is not padding. Retain all three; do not claim dead/covered/compiler output.
- `EndRender`: direct ECX Layer call and a one-byte source body resolve it as an ordinary method. It is neither virtual nor disposable padding despite being a no-op in this build.
- Root ownership: Layer owns HierList, root Region, and child Regions; it borrows Pane pointers including `g_pScreenPane`. Pane deletion is requested separately by `MarkAllPanesForDeletion` and is not destructor ownership.
- `blocksChildTraversal`: accepted over `isHidden`. The byte is loaded only to suppress child recursion while the pane itself can still be processed; visibility has its own `+0x28` byte.
- Source placement: `NexusTK/ui/core/Layer.cpp` is retained. No evidence supports Pane.cpp, ScreenPane.cpp, MapPane.cpp, HierList.cpp, or generated-only placement.
- Remaining limitations are confidence caps, not deferred blockers: exact historical spelling of private accessors/motion flags and the old compiler's header split cannot be recovered from the stripped binary.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B001 must not edit manual coverage. Following callback validation and generated readback, the following rows contain the real validator-issued child UIDs and remain exact pending supervisor-owned coverage synchronization. B001 did not edit any manual coverage file.

File/placement: in `by-memory/-coverage-report.md`, replace the current UID00018W row at the same address-order location and insert the 25 child rows immediately beneath it. Callback registration is complete, and every child row below already uses its real validator-issued UID. The rows below use the exact local indentation: the UID00018W replacement retains the existing four-space baseline, every UID0004NR-UID0004OF child has eight leading spaces, and the existing following UID00018X row remains unchanged at four leading spaces. This is the exact balanced local hierarchy and mirrors metadata deltas `0, +4, 0...0, -4`.

Exact replacement/insert text:

    - [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md) 0x004f0480-0x004f1bf6 | exact split index | Layer : ignored : 92% : very-strong : Exact non-emitting index over 25 code bodies: 24 Layer source methods and one compiler scalar deleting destructor; complete raw-body, layout, caller, vtable, padding, and source/compiler dispositions are documented.
        - [UID:0004NR][0x004f0480-0x004f0597.LayerConstructor](by-memory/0x004f0480-0x004f0597.LayerConstructor.md) 0x004f0480-0x004f0597 | constructor | Layer::Layer : reconstructable : 92% : very-strong : Exact root-row, HierList, screen-pane, bounds, and Region initialization; owner/emitter UID000073, position 20.
        - [UID:0004NS][0x004f05a0-0x004f062a.LayerDestructor](by-memory/0x004f05a0-0x004f062a.LayerDestructor.md) 0x004f05a0-0x004f062a | destructor | Layer::~Layer : reconstructable : 92% : very-strong : Ordinary source destructor; Region/HierList cleanup is retained and compiler teardown is excluded; position 30.
        - [UID:0004NT][0x004f0630-0x004f083c.LayerAddChildAfter](by-memory/0x004f0630-0x004f083c.LayerAddChildAfter.md) 0x004f0630-0x004f083c | method | Layer::AddChildAfter : reconstructable : 92% : very-strong : Exact after-insertion source with intentional previous-bounds/flags initialization asymmetry; position 40.
        - [UID:0004NU][0x004f0840-0x004f0a5d.LayerAddChildBefore](by-memory/0x004f0840-0x004f0a5d.LayerAddChildBefore.md) 0x004f0840-0x004f0a5d | method | Layer::AddChildBefore : reconstructable : 92% : very-strong : Exact before-insertion source with both bounds initialized and flags left indeterminate; position 50.
        - [UID:0004NV][0x004f0a60-0x004f0b3d.LayerRemoveChild](by-memory/0x004f0a60-0x004f0b3d.LayerRemoveChild.md) 0x004f0a60-0x004f0b3d | method | Layer::RemoveChild : reconstructable : 92% : very-strong : Exact recursive Region/child cleanup and HierList payload removal; position 60.
        - [UID:0004NW][0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion](by-memory/0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion.md) 0x004f0b40-0x004f0b79 | method | Layer::MarkAllPanesForDeletion : reconstructable : 91% : very-strong : Full top-level child-list traversal skips null/sentinel rows and null pane pointers, then calls Pane::MarkForDeletion; position 70.
        - [UID:0004NX][0x004f0b80-0x004f0c9f.LayerSetPaneFlagsMasked](by-memory/0x004f0b80-0x004f0c9f.LayerSetPaneFlagsMasked.md) 0x004f0b80-0x004f0c9f | raw source method | Layer::SetPaneFlagsMasked : reconstructable : 91% : strong : Retained complete raw masked-flags state transition and parent invalidation source; position 80.
        - [UID:0004NY][0x004f0ca0-0x004f0d11.LayerGetPaneFlags](by-memory/0x004f0ca0-0x004f0d11.LayerGetPaneFlags.md) 0x004f0ca0-0x004f0d11 | raw source method | Layer::GetPaneFlags : reconstructable : 90% : strong : Retained complete raw getter with attached-pane precondition; position 90.
        - [UID:0004NZ][0x004f0d20-0x004f0d93.LayerContainsPane](by-memory/0x004f0d20-0x004f0d93.LayerContainsPane.md) 0x004f0d20-0x004f0d93 | method | Layer::ContainsPane : reconstructable : 91% : very-strong : Recursive Pane membership query; position 100.
        - [UID:0004O0][0x004f0da0-0x004f0f27.LayerInvalidatePaneRegion](by-memory/0x004f0da0-0x004f0f27.LayerInvalidatePaneRegion.md) 0x004f0da0-0x004f0f27 | method | Layer::InvalidatePaneRegion : reconstructable : 92% : very-strong : Exact pane-local intersection and ancestor dirty-region propagation; position 110.
        - [UID:0004O1][0x004f0f30-0x004f0f42.LayerClearDirtyRegion](by-memory/0x004f0f30-0x004f0f42.LayerClearDirtyRegion.md) 0x004f0f30-0x004f0f42 | method | Layer::ClearDirtyRegion : reconstructable : 92% : very-strong : Root dirty-state reset; position 120.
        - [UID:0004O2][0x004f0f50-0x004f0f68.LayerCopyDirtyRegion](by-memory/0x004f0f50-0x004f0f68.LayerCopyDirtyRegion.md) 0x004f0f50-0x004f0f68 | method | Layer::CopyDirtyRegion : reconstructable : 92% : very-strong : Root dirty-region copy; position 130.
        - [UID:0004O3][0x004f0f70-0x004f0f82.LayerUnionDirtyRegion](by-memory/0x004f0f70-0x004f0f82.LayerUnionDirtyRegion.md) 0x004f0f70-0x004f0f82 | method | Layer::UnionDirtyRegion : reconstructable : 92% : very-strong : Root dirty-region union; position 140.
        - [UID:0004O4][0x004f0f90-0x004f0fca.LayerCollectDirtyRegion](by-memory/0x004f0f90-0x004f0fca.LayerCollectDirtyRegion.md) 0x004f0f90-0x004f0fca | method | Layer::CollectDirtyRegion : reconstructable : 92% : very-strong : Root union, recursive update, and output copy; position 150.
        - [UID:0004O5][0x004f0fd0-0x004f0fe1.LayerPropagateDirtyRegion](by-memory/0x004f0fd0-0x004f0fe1.LayerPropagateDirtyRegion.md) 0x004f0fd0-0x004f0fe1 | method | Layer::PropagateDirtyRegion : reconstructable : 92% : very-strong : Exact recursive-propagation entry; position 160.
        - [UID:0004O6][0x004f0ff0-0x004f138b.LayerRenderRecursive](by-memory/0x004f0ff0-0x004f138b.LayerRenderRecursive.md) 0x004f0ff0-0x004f138b | method | Layer::RenderRecursive : reconstructable : 92% : very-strong : Exact dirty/render recursion, clipping, custom paint, MapPane effect, and child-suppression behavior; position 170.
        - [UID:0004O7][0x004f1390-0x004f1391.LayerEndRender](by-memory/0x004f1390-0x004f1391.LayerEndRender.md) 0x004f1390-0x004f1391 | method | Layer::EndRender : reconstructable : 91% : very-strong : Direct source no-op called once after each ScreenPane layer render; position 180.
        - [UID:0004O8][0x004f13a0-0x004f1411.LayerGetChildList](by-memory/0x004f13a0-0x004f1411.LayerGetChildList.md) 0x004f13a0-0x004f1411 | raw source method | Layer::GetChildList : reconstructable : 90% : strong : Retained complete raw child-list getter with attached-pane precondition; position 190.
        - [UID:0004O9][0x004f1420-0x004f1499.LayerGetParentPane](by-memory/0x004f1420-0x004f1499.LayerGetParentPane.md) 0x004f1420-0x004f1499 | method | Layer::GetParentPane : reconstructable : 92% : very-strong : Exact owner-list/root-parent Pane query; position 200.
        - [UID:0004OA][0x004f14a0-0x004f1593.LayerGetScreenOffset](by-memory/0x004f14a0-0x004f1593.LayerGetScreenOffset.md) 0x004f14a0-0x004f1593 | method | Layer::GetScreenOffset : reconstructable : 92% : very-strong : Exact ancestor offset accumulation and `(-1000,-1000)` miss sentinel; position 210.
        - [UID:0004OB][0x004f15a0-0x004f1906.LayerUpdateDirtyRegionsRecursive](by-memory/0x004f15a0-0x004f1906.LayerUpdateDirtyRegionsRecursive.md) 0x004f15a0-0x004f1906 | private method | Layer::UpdateDirtyRegionsRecursive : reconstructable : 92% : very-strong : Exact pending-motion, bounds-change, ancestor-offset, dirty union/subtract, and child-recursion behavior; position 220.
        - [UID:0004OC][0x004f1910-0x004f1a42.LayerPropagateDirtyRegionRecursive](by-memory/0x004f1910-0x004f1a42.LayerPropagateDirtyRegionRecursive.md) 0x004f1910-0x004f1a42 | private method | Layer::PropagateDirtyRegionRecursive : reconstructable : 92% : very-strong : Exact parent-to-child intersection/offset/union recursion; position 230.
        - [UID:0004OD][0x004f1a50-0x004f1aa5.LayerDestroyNodeRegions](by-memory/0x004f1a50-0x004f1aa5.LayerDestroyNodeRegions.md) 0x004f1a50-0x004f1aa5 | private method | Layer::DestroyNodeRegions : reconstructable : 92% : very-strong : Exact recursive per-node Region deletion and pointer clear; position 240.
        - [UID:0004OE][0x004f1ab0-0x004f1b32.LayerFindPaneNode](by-memory/0x004f1ab0-0x004f1b32.LayerFindPaneNode.md) 0x004f1ab0-0x004f1b32 | private method | Layer::FindPaneNode : reconstructable : 92% : very-strong : Exact recursive node lookup with optional owner-list/index outputs; position 250.
        - [UID:0004OF][0x004f1b40-0x004f1bf6.LayerScalarDeletingDestructor](by-memory/0x004f1b40-0x004f1bf6.LayerScalarDeletingDestructor.md) 0x004f1b40-0x004f1bf6 | scalar deleting destructor | Layer compiler deleting-destructor wrapper : ignored : 91% : very-strong : Vtable-only compiler ABI glue regenerated from the virtual ordinary destructor; no handwritten source body.

File/placement: in `by-class/-coverage-report.md`, replace the existing UID000065 and UID000073 rows in place:

- [UID:000065][HierList](by-class/HierList.md) : reconstructable : 91% : very-strong : Tree-aware List-derived container with complete accepted declaration and methods; exact Layer friend access to ownerNode is documented without changing HierList source ownership.
- [UID:000073][Layer](by-class/Layer.md) : reconstructable : 92% : very-strong : Complete Layer and 48-byte LayerNode declaration with exact 24 source-method children, one compiler scalar-wrapper disposition, Pane/HierList/Region relationships, callers, vtable, and UID0000KL owner/emitter route.

File/placement: in `by-file/-coverage-report.md`, replace UID0000KL in place:

- [UID:0000KL][Layer](by-file/Layer.md) : reconstructable : 91% : very-strong : `NexusTK/ui/core/Layer.cpp` source root with declaration-first emission, exact positions 20-250 for 24 source methods, compiler-only scalar wrapper exclusion, complete layout/caller/source-order evidence, and no aggregate duplicate.

File/placement: in `by-memory/-coverage-report.md`, insert UID0003A3 beneath UID0001G6 in address order after the `0x005583a0-0x0055867a` presentation child, and insert UID0003OK beneath UID00025N's Layer vtable subsection in address order:

    - [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) 0x00559410-0x005595ca | method | ScreenPane::TraversePresentationList : reconstructable : 90% : very-strong : Exact Layer-pointer reverse dirty/forward render traversal with one direct Layer::EndRender call per rendered list entry; stale ScreenLayerEntry/optional-nullsub wording removed.
    - [UID:0003OK][0x0061ca44-0x0061ca54.LayerVtableData](by-memory/0x0061ca44-0x0061ca54.LayerVtableData.md) 0x0061ca44-0x0061ca54 | vtable data | LayerVtableData : ignored : 90% : very-strong : Exact COL and three Layer slots; declaration-generated data with no standalone handwritten source body.

Callback-applied ordinary source text on UID00018W, already present and validated rather than pending supervisor coverage work:

*** Item Summary: Exact non-emitting split index over 25 code bodies: 24 source-authored Layer methods and one compiler scalar deleting destructor, with complete raw-child, LayerNode/HierList layout, caller, vtable, padding, source placement, and generated no-duplicate disposition. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

B001 applied the ordinary UID00018W Item Summary shown above but did not apply any `-coverage-report.md` row because those files are manual supervisor-owned artifacts. Child validators issued the real UIDs shown above; final waited command `000000011289` verified the balanced generated hierarchy and source output. No tracker text is proposed; validator-owned automated tracker state refreshed from ordinary documentation.

## Follow-Up Actions

- B001 implementation callback work is complete. Every accepted ordinary target/support edit, child registration, formal block, padding row, scoped validator, generated readback, report proof, and lease release is recorded here; no B001 implementation work remains.
- Manual `-coverage-report.md` synchronization remains external supervisor-owned. This artifact supplies exact rows with real UID0004NR-UID0004OF identities but does not claim that coverage was applied.
- Report validation/execution/count/path/move/archive state is external supervisor/validator-owned and is neither asserted nor directed by this artifact. B001 ran no `execute_report`, report lifecycle/probe/count/revalidation, move, or archive command.
- A-agent actions: none. C-agent actions: none. No second target was started.

## Confidence

- Range, bytes, child boundaries, padding, direct behavior, owner/no-owner split, caller/callee/xref routes, vtable disposition, Layer/LayerNode/HierList layouts, source/compiler split, formal destination identity, and generated uniqueness/order are very strong (`94`).
- Original private method/field/accessor spellings and raw-helper historical liveness remain strong (`90-93`) confidence caps; they are documented ranked inferences, not deferred implementation blockers.
- Current UID00018W result is `92/94` as a complete non-emitting split/index with all accepted source destinations applied and verified.

## Validator Results

All commands ran from `source-3/project-documentation`. Every command exited `0`. Each ordinary file was leased only for its immediate create/edit/validation scope and released immediately afterward.

### Child Registration Validators

| Issued UID | New path | Command ID | Timestamp | Exit | Result / side effect |
| --- | --- | --- | --- | --- | --- |
| `0004NR` | `by-memory/0x004f0480-0x004f0597.LayerConstructor.md` | `000000011157` | `2026-07-14T09:17:56-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004NS` | `by-memory/0x004f05a0-0x004f062a.LayerDestructor.md` | `000000011177` | `2026-07-14T09:21:00-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004NT` | `by-memory/0x004f0630-0x004f083c.LayerAddChildAfter.md` | `000000011178` | `2026-07-14T09:21:11-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004NU` | `by-memory/0x004f0840-0x004f0a5d.LayerAddChildBefore.md` | `000000011179` | `2026-07-14T09:21:24-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004NV` | `by-memory/0x004f0a60-0x004f0b3d.LayerRemoveChild.md` | `000000011181` | `2026-07-14T09:21:29-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004NW` | `by-memory/0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion.md` | `000000011182` | `2026-07-14T09:21:43-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004NX` | `by-memory/0x004f0b80-0x004f0c9f.LayerSetPaneFlagsMasked.md` | `000000011183` | `2026-07-14T09:21:55-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004NY` | `by-memory/0x004f0ca0-0x004f0d11.LayerGetPaneFlags.md` | `000000011185` | `2026-07-14T09:22:07-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004NZ` | `by-memory/0x004f0d20-0x004f0d93.LayerContainsPane.md` | `000000011186` | `2026-07-14T09:22:11-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004O0` | `by-memory/0x004f0da0-0x004f0f27.LayerInvalidatePaneRegion.md` | `000000011188` | `2026-07-14T09:22:24-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004O1` | `by-memory/0x004f0f30-0x004f0f42.LayerClearDirtyRegion.md` | `000000011189` | `2026-07-14T09:22:28-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004O2` | `by-memory/0x004f0f50-0x004f0f68.LayerCopyDirtyRegion.md` | `000000011190` | `2026-07-14T09:22:40-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004O3` | `by-memory/0x004f0f70-0x004f0f82.LayerUnionDirtyRegion.md` | `000000011191` | `2026-07-14T09:22:53-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004O4` | `by-memory/0x004f0f90-0x004f0fca.LayerCollectDirtyRegion.md` | `000000011193` | `2026-07-14T09:23:05-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004O5` | `by-memory/0x004f0fd0-0x004f0fe1.LayerPropagateDirtyRegion.md` | `000000011194` | `2026-07-14T09:23:19-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004O6` | `by-memory/0x004f0ff0-0x004f138b.LayerRenderRecursive.md` | `000000011195` | `2026-07-14T09:23:31-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004O7` | `by-memory/0x004f1390-0x004f1391.LayerEndRender.md` | `000000011196` | `2026-07-14T09:23:36-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004O8` | `by-memory/0x004f13a0-0x004f1411.LayerGetChildList.md` | `000000011197` | `2026-07-14T09:23:48-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004O9` | `by-memory/0x004f1420-0x004f1499.LayerGetParentPane.md` | `000000011199` | `2026-07-14T09:24:01-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004OA` | `by-memory/0x004f14a0-0x004f1593.LayerGetScreenOffset.md` | `000000011200` | `2026-07-14T09:24:05-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004OB` | `by-memory/0x004f15a0-0x004f1906.LayerUpdateDirtyRegionsRecursive.md` | `000000011201` | `2026-07-14T09:24:17-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004OC` | `by-memory/0x004f1910-0x004f1a42.LayerPropagateDirtyRegionRecursive.md` | `000000011202` | `2026-07-14T09:24:29-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004OD` | `by-memory/0x004f1a50-0x004f1aa5.LayerDestroyNodeRegions.md` | `000000011203` | `2026-07-14T09:24:42-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004OE` | `by-memory/0x004f1ab0-0x004f1b32.LayerFindPaneNode.md` | `000000011206` | `2026-07-14T09:24:54-04:00` | `0` | `insert_uid:1`; generated deferred |
| `0004OF` | `by-memory/0x004f1b40-0x004f1bf6.LayerScalarDeletingDestructor.md` | `000000011208` | `2026-07-14T09:24:59-04:00` | `0` | `insert_uid:1`; generated deferred |

### Existing-Page Scoped Validators

| Changed path | Command ID | Timestamp | Exit | Result / side effect |
| --- | --- | --- | --- | --- |
| `by-memory/0x004f0480-0x004f1bf6.Layer.md` | `000000011215` | `2026-07-14T09:27:57-04:00` | `0` | `ok:1`; generated deferred |
| `by-class/Layer.md` | `000000011216` | `2026-07-14T09:28:44-04:00` | `0` | `ok:1`; generated deferred |
| `by-file/Layer.md` | `000000011218` | `2026-07-14T09:29:12-04:00` | `0` | `ok:1`; generated deferred |
| `by-class/HierList.md` | `000000011219` | `2026-07-14T09:29:49-04:00` | `0` | `ok:1`; generated deferred |
| `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` | `000000011220` | `2026-07-14T09:31:10-04:00` | `0` | `ok:1`; `missing_ref_uid:7` in pre-existing historical content; generated deferred |
| `by-memory/0x0061ca44-0x0061ca54.LayerVtableData.md` | `000000011221` | `2026-07-14T09:31:59-04:00` | `0` | `ok:1`; generated deferred |
| `by-memory/0x0061ca44-0x0061cf68.LayerInputListReadOnlyData.md` | `000000011222` | `2026-07-14T09:32:22-04:00` | `0` | `ok:1`; `missing_ref_uid:15` in pre-existing historical content; generated deferred |
| `by-memory/-ignored.md` | `000000011223` | `2026-07-14T09:33:35-04:00` | `0` | `ok:1`; `missing_ref_uid:314` in pre-existing historical content; generated deferred |
| `by-class/Pane.md` | `000000011224` | `2026-07-14T09:36:20-04:00` | `0` | `ok:1`; generated deferred |
| `by-file/Pane.md` | `000000011225` | `2026-07-14T09:36:23-04:00` | `0` | `ok:1`; `missing_ref_uid:2` in pre-existing historical content; generated deferred |
| `by-memory/0x00544460-0x00545086.PaneCore.md` | `000000011226` | `2026-07-14T09:36:32-04:00` | `0` | `ok:1`; generated deferred |
| `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md` | `000000011227` | `2026-07-14T09:36:41-04:00` | `0` | `ok:1`; generated deferred |
| `by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md` | `000000011228` | `2026-07-14T09:36:53-04:00` | `0` | `ok:1`; generated deferred |
| `by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md` | `000000011229` | `2026-07-14T09:37:04-04:00` | `0` | `ok:1`; generated deferred |
| `by-type/by-struct/HierListNode.md` | `000000011230` | `2026-07-14T09:37:16-04:00` | `0` | `ok:1`; generated deferred |
| `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` | `000000011231` | `2026-07-14T09:37:28-04:00` | `0` | `ok:1`; generated deferred |
| `by-global/MainUiLayerSlots.md` | `000000011232` | `2026-07-14T09:37:36-04:00` | `0` | `ok:1`; generated deferred |
| `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md` | `000000011233` | `2026-07-14T09:37:48-04:00` | `0` | `ok:1`; generated deferred |
| `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` | `000000011234` | `2026-07-14T09:37:57-04:00` | `0` | `ok:1`; `missing_ref_uid:4` in pre-existing historical content; generated deferred |
| `by-class/WorldMapPane.md` | `000000011235` | `2026-07-14T09:38:09-04:00` | `0` | `ok:1`; `missing_ref_uid:10` in pre-existing historical content; generated deferred |
| `by-file/WorldMapPane.md` | `000000011236` | `2026-07-14T09:38:21-04:00` | `0` | `ok:1`; `missing_ref_uid:11` in pre-existing historical content; generated deferred |
| `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` | `000000011237` | `2026-07-14T09:38:30-04:00` | `0` | `ok:1`; `missing_ref_uid:96` in pre-existing historical content; generated deferred |
| `by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md` | `000000011238` | `2026-07-14T09:38:38-04:00` | `0` | `ok:1`; generated deferred |
| `by-class/FlyingParcelPane.md` | `000000011239` | `2026-07-14T09:38:50-04:00` | `0` | `ok:1`; generated deferred |
| `by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md` | `000000011240` | `2026-07-14T09:39:02-04:00` | `0` | `ok:1`; generated deferred |
| `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md` | `000000011242` | `2026-07-14T09:40:13-04:00` | `0` | `ok:1`; `missing_ref_uid:1` in pre-existing historical content; generated deferred |

The reported `missing_ref_uid` counts belong to pre-existing historical references on those large pages; each command still returned `ok:1` and exit `0`. B001 did not rewrite unrelated history to suppress validator diagnostics.

### Initial Callback Waited Generation

- Command: `python .\tools\validator.py --mode file --file by-memory/0x004f0480-0x004f1bf6.Layer.md --apply --queue-timeout 240 --wait-generated`.
- Command ID/timestamp/exit: `000000011243`, `2026-07-14T09:41:09-04:00`, `0`; `ok:1`; `generated_refresh:completed`; generated command ID `000000011243`.
- Authorized validator side effects: `autogen_registry_rebuild:1`, `generated_metadata_refresh:280`, `research_tracker_update:1`, `autogen_children_fallback_insert:14`, `autogen_children_marker_missing:84`, and `autogen_emitter_has_no_code:192`. These are validator-owned generated/registry effects, not manual B001 edits.
- `auto-generated/NexusTK/ui/core/Layer.cpp`: 21,664 bytes; refreshed `2026-07-14T09:41:17.3481844-04:00`; SHA256 `53866137E7864B84DB0B19A58C2D424396D22B1DDED8FF25490C9445764A9534`.
- Layer assertions: one `struct LayerNode`; one `class Layer : public LObject`; one definition each for constructor, ordinary destructor, and all 22 remaining source methods; UID markers exactly once and in order UID000073, UID0004NR-UID0004OE; zero UID00018W, UID0004OF, `Empty Emitter Marker`, scalar-deleting, `deletionFlags`, or `vptr` tokens.
- `auto-generated/NexusTK/ui/core/ScreenPane.cpp`: 9,595 bytes; refreshed `2026-07-14T09:41:20.0490394-04:00`; SHA256 `51F92CD1B2CA5877C807F039D4A26EF7F74BD1C4E7D30FBA05E1713073FF7D01`.
- ScreenPane assertions: UID0003A3 and `TraversePresentationList` each occur once; two `Layer *layer` declarations plus one `Layer *nextLayer`; one `layer->EndRender()`; zero `ScreenLayerEntry`, `nullsub_11`, or stale `MapPane::meth_0x559410`.
- Exact-block readback: all 27 destination managed blocks compare byte-for-byte after CRLF normalization with the Gate-1-passed report blocks; mismatch count `0`.

### Nested-Balance Repair Validators

| Changed path | Command ID | Timestamp | Exit | Result / side effect |
| --- | --- | --- | --- | --- |
| `by-memory/0x004f0480-0x004f1bf6.Layer.md` | `000000011281` | `2026-07-14T09:57:08-04:00` | `0` | `ok:1`; relative `Nested:0`; generated deferred |
| `by-memory/0x004f0480-0x004f0597.LayerConstructor.md` | `000000011284` | `2026-07-14T09:57:29-04:00` | `0` | `ok:1`; relative `Nested:4`; generated deferred |
| `by-memory/0x004f1c00-0x004f3017.InputPaneBases.md` | `000000011288` | `2026-07-14T09:57:59-04:00` | `0` | `ok:1`; relative `Nested:-4`; `missing_ref_uid:27` in preserved pre-existing child references; generated deferred |

Only those three ordinary pages changed during the hierarchy repair. UID0004NS-UID0004OF already had the required relative `Nested:0` continuation and were reread through generated output rather than edited or revalidated. All three repair leases were released immediately after their scoped validator.

### Final Nested-Balance Waited Generation

- Command: `python .\tools\validator.py --mode file --file by-memory/0x004f0480-0x004f1bf6.Layer.md --apply --queue-timeout 240 --wait-generated`.
- Command ID/timestamp/exit: `000000011289`, `2026-07-14T09:58:29-04:00`, `0`; `ok:1`; `generated_refresh:completed`; generated command ID `000000011289`.
- Authorized validator side effects: `autogen_registry_rebuild:1`, `generated_metadata_refresh:281`, `autogen_children_fallback_insert:14`, `autogen_children_marker_missing:84`, and `autogen_emitter_has_no_code:191`. These are validator-owned generated/registry effects, not manual B001 edits.
- `auto-generated/NexusTK/ui/core/Layer.cpp`: 21,664 bytes; refreshed `2026-07-14T09:58:38.9981684-04:00`; SHA256 `FDBA16A3273CFB0FC44EA0B2A9E5D154E4C8CBE1B18C0880F6496C0491F2E782`; one class, one LayerNode, one constructor, one ordinary destructor, and the original no-aggregate/no-scalar/no-empty-marker assertions remain true.
- `auto-generated/NexusTK/ui/core/ScreenPane.cpp`: 9,595 bytes; refreshed `2026-07-14T09:58:41.6619701-04:00`; SHA256 `457EF3B8D4626C16F3BCA00016A4FCDFD926318C79AC5A4F16AC63C4F5D7A1B8`; UID0003A3 and `layer->EndRender()` each occur once, with zero `ScreenLayerEntry` or `nullsub_11` tokens.
- Current generated `auto-generated/-ag-coverage-report-by-memory.md` readback: UID00018V leading spaces `211`; UID00018W `211`; each of all 25 UID0004NR-UID0004OF rows `215` (minimum and maximum both `215`); UID00018X `211`. The sequence therefore opens exactly one Markdown level and returns to the predecessor baseline after UID0004OF.
- Exact-block readback remains 27 matches and zero mismatches; the repair changed only three `Nested` metadata values and one parent prose sentence.
- Read-only final-report self-review after a later validator-owned refresh: at `2026-07-14T10:03:16.0869515-04:00`, Layer.cpp SHA256 was `C6DB6B78B3270EC21F60B75F4ACA3BCADCBF9E1CB1F3AB1015DDDFB1A991485A`; at `2026-07-14T10:03:18.8334707-04:00`, ScreenPane.cpp SHA256 was `3CC4F6D3C9D8EEA0CECBA735A0ED47106A81BA2961B16D0EFD48B510EC7153C7`. The refresh changed volatile hashes/timestamps but retained one Layer class, one LayerNode, zero aggregate/scalar/empty-marker tokens, one UID0003A3, one EndRender call, and zero stale ScreenLayerEntry tokens. These are evidence-time values, not assertions of indefinite hash stability under concurrent validators.

## Changed Files

The callback plus balanced-Nested repair changed 52 ordinary by-* pages and this same report. The repair touched only UID00018W, UID0004NR, and UID00018X. Generated/registry/tracker changes listed above were validator-owned side effects. No manual coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, queue/lock, archive, or IDA file was edited by B001.

| Ordinary path | Callback change |
| --- | --- |
| `by-memory/0x004f0480-0x004f0597.LayerConstructor.md` | created/registered exact child; repair set relative `Nested:4` |
| `by-memory/0x004f05a0-0x004f062a.LayerDestructor.md` | created/registered exact child |
| `by-memory/0x004f0630-0x004f083c.LayerAddChildAfter.md` | created/registered exact child |
| `by-memory/0x004f0840-0x004f0a5d.LayerAddChildBefore.md` | created/registered exact child |
| `by-memory/0x004f0a60-0x004f0b3d.LayerRemoveChild.md` | created/registered exact child |
| `by-memory/0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion.md` | created/registered exact child |
| `by-memory/0x004f0b80-0x004f0c9f.LayerSetPaneFlagsMasked.md` | created/registered exact child |
| `by-memory/0x004f0ca0-0x004f0d11.LayerGetPaneFlags.md` | created/registered exact child |
| `by-memory/0x004f0d20-0x004f0d93.LayerContainsPane.md` | created/registered exact child |
| `by-memory/0x004f0da0-0x004f0f27.LayerInvalidatePaneRegion.md` | created/registered exact child |
| `by-memory/0x004f0f30-0x004f0f42.LayerClearDirtyRegion.md` | created/registered exact child |
| `by-memory/0x004f0f50-0x004f0f68.LayerCopyDirtyRegion.md` | created/registered exact child |
| `by-memory/0x004f0f70-0x004f0f82.LayerUnionDirtyRegion.md` | created/registered exact child |
| `by-memory/0x004f0f90-0x004f0fca.LayerCollectDirtyRegion.md` | created/registered exact child |
| `by-memory/0x004f0fd0-0x004f0fe1.LayerPropagateDirtyRegion.md` | created/registered exact child |
| `by-memory/0x004f0ff0-0x004f138b.LayerRenderRecursive.md` | created/registered exact child |
| `by-memory/0x004f1390-0x004f1391.LayerEndRender.md` | created/registered exact child |
| `by-memory/0x004f13a0-0x004f1411.LayerGetChildList.md` | created/registered exact child |
| `by-memory/0x004f1420-0x004f1499.LayerGetParentPane.md` | created/registered exact child |
| `by-memory/0x004f14a0-0x004f1593.LayerGetScreenOffset.md` | created/registered exact child |
| `by-memory/0x004f15a0-0x004f1906.LayerUpdateDirtyRegionsRecursive.md` | created/registered exact child |
| `by-memory/0x004f1910-0x004f1a42.LayerPropagateDirtyRegionRecursive.md` | created/registered exact child |
| `by-memory/0x004f1a50-0x004f1aa5.LayerDestroyNodeRegions.md` | created/registered exact child |
| `by-memory/0x004f1ab0-0x004f1b32.LayerFindPaneNode.md` | created/registered exact child |
| `by-memory/0x004f1b40-0x004f1bf6.LayerScalarDeletingDestructor.md` | created/registered exact child |
| `by-memory/0x004f1c00-0x004f3017.InputPaneBases.md` | repair set relative `Nested:-4` only; all prior content/metadata preserved |
| `by-memory/0x004f0480-0x004f1bf6.Layer.md` | updated accepted target/support evidence; repair set relative `Nested:0` and corrected nesting prose |
| `by-class/Layer.md` | updated accepted target/support evidence |
| `by-file/Layer.md` | updated accepted target/support evidence |
| `by-class/HierList.md` | updated accepted target/support evidence |
| `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` | updated accepted target/support evidence |
| `by-memory/0x0061ca44-0x0061ca54.LayerVtableData.md` | updated accepted target/support evidence |
| `by-memory/0x0061ca44-0x0061cf68.LayerInputListReadOnlyData.md` | updated accepted target/support evidence |
| `by-memory/-ignored.md` | updated accepted target/support evidence |
| `by-class/Pane.md` | updated accepted target/support evidence |
| `by-file/Pane.md` | updated accepted target/support evidence |
| `by-memory/0x00544460-0x00545086.PaneCore.md` | updated accepted target/support evidence |
| `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md` | updated accepted target/support evidence |
| `by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md` | updated accepted target/support evidence |
| `by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md` | updated accepted target/support evidence |
| `by-type/by-struct/HierListNode.md` | updated accepted target/support evidence |
| `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` | updated accepted target/support evidence |
| `by-global/MainUiLayerSlots.md` | updated accepted target/support evidence |
| `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md` | updated accepted target/support evidence |
| `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` | updated accepted target/support evidence |
| `by-class/WorldMapPane.md` | updated accepted target/support evidence |
| `by-file/WorldMapPane.md` | updated accepted target/support evidence |
| `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` | updated accepted target/support evidence |
| `by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md` | updated accepted target/support evidence |
| `by-class/FlyingParcelPane.md` | updated accepted target/support evidence |
| `by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md` | updated accepted target/support evidence |
| `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md` | updated accepted target/support evidence |

- Report updated: `tools/leaser/Agents/Agent-B001/research/00018W-Layer-source-quality.md`.
- MapPane effect pages UID0002I1/UID0002I2 were reread and already contained the exact Layer render dependency; they were intentionally unchanged and are not in the changed-file table.
- Every child UID was issued by its listed validator before parent/support links were added. No UID was fabricated.
- Lease closure was rechecked after all original ordinary edits, after each of the three repair validators, and after the final waited refresh; no B001 lease remains.

## Implementation Tracking Checklist

Initial/report-to-callback controls:

- [x] Re-read every destination immediately before its callback edit and confirm accepted facts fit current content.
- [x] Create/register all 25 exact child pages serially and record each validator-issued UID before adding links.
- [x] Keep ledger Actions within allowed values and set every final Verification state to `applied`, `already-present`, or `excluded-with-reason`.
- [x] Apply all 27 complete destination-specific managed blocks with no C++ outside formal insertion shape.
- [x] Preserve exact range hash, child hashes, 24 internal and two external padding spans, ABI/CFG/instruction/caller/callee/xref/vtable/RTTI/layout evidence, and ranked negative alternatives.
- [x] Preserve B002 coordination as independently revalidated `MarkAllPanesForDeletion` evidence and close its caller dependency without overwriting unrelated B002 content.
- [x] Preserve exact supervisor-owned coverage text, replace placeholders with real issued UIDs, and make no B001 coverage edit.
- [x] Treat `Nested` as a relative address-sorted indentation delta, not a child count, and preserve the exact balanced sequence parent `0`, first child `4`, later children `0`, following UID00018X `-4`.

Implementation callback:

- [x] Apply C18W-001 through C18W-052 claim by claim with one legal callback state and claim-specific proof per row.
- [x] Convert UID00018W to exact `92/94` NONE/FALSE blank-emitter/position/C++ relative `Nested:0` split index after child registration; open on UID0004NR `Nested:4`, continue UID0004NS-UID0004OF at `0`, and close on UID00018X `-4`.
- [x] Apply exact metadata, source bodies, full behavior/evidence/history, and positions to all 24 source children.
- [x] Apply exact compiler-only/no-code evidence and metadata to UID0004OF.
- [x] Install the complete Layer, HierList, and ScreenPane managed blocks exactly and preserve unrelated stronger content.
- [x] Apply every listed class/file/vtable/read-only/Pane/HierList/Region/MapPane/ScreenPane/client support update without unrelated score inflation.
- [x] Add only verified all-`cc` padding rows to `by-memory/-ignored.md` and preserve adjacent rows.
- [x] Lease one ordinary file only for its immediate edit/validator, reread after lease, scoped-validate, and release immediately; record all IDs/timestamps/exits/results/side effects.
- [x] Run final authorized waited generation and record freshness/SHA/count/order/token assertions for Layer.cpp and ScreenPane.cpp plus exact generated by-memory levels `211/211/215...215/211`.
- [x] Verify no aggregate Empty Emitter Marker/duplicate and no scalar/vptr/base/EH/delete/vtable body is emitted.
- [x] Leave manual coverage and all manually forbidden generated/tracker/audit/supervisor/validator-state/lifecycle/IDA files untouched.
- [x] Confirm no B001 lease remains, update report current state/results/files/checklist, and stop without executing or moving the report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000011355","destination_path":"executed-b-agent-research/B001/00018W-Layer-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00018W-Layer-source-quality.md","timestamp":"2026-07-14T10:24:11-04:00","uid":"00018W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
