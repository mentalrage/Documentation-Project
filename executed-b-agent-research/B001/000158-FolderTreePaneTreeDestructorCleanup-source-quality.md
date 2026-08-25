** TARGET-REPORT-UID:000158 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID000158 FolderTreePane Tree Destructor Ownership / Split Research


## Finalized Report / Current Recommendation
- Current implementation state: UID000158 is corrected from historical `[0x004b5650,0x004b5668)` to exact `[0x004b5650,0x004b5669)`, renamed `FolderTreePaneTreeDestructor`, and documented as the retained complete-object destructor body for `Tree<FolderTreePane::TreeElem>` rather than merely an anonymous constructor-cleanup fragment.
- Applied disposition: the page remains reconstructable and source-routed, attached directly to class UID0000F9 with `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000F9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000F9`, blank optional position, and `Nested:8`.
- Applied source shape: the target uses the accepted covered-by marker, UID0000F9's complete formal class block defines its virtual destructor inline with an empty source body, ordinary support links/evidence use the corrected path, and successor alignment `[0x004b5669,0x004b5670)` is registered in `by-memory/-ignored.md`.
- Confidence: very strong for the binary range, object identity, destructor role, unwind liveness, member/base teardown, owner, and compiler-regenerated behavior. The remaining uncertainty is limited to whether the original header spelled the empty virtual destructor explicitly or defaulted it through an equivalent inline definition; that distinction does not change the accepted reconstruction shape.

## Supporting Research
- Research date: 2026-07-14 EDT.
- Mandatory IDA MCP evidence came from the evidence-time NexusTK IDB session `5288313d`, discovered by a fresh `idb_list`. The session reported PID `20244`, `is_analyzing:false`; `server_health` reported `ok`, with auto-analysis, Hex-Rays, and strings ready. All valid bounded target calls used database `5288313d`.
- Active/current assignment search roots checked: `tools/leaser/Agents/Agent-B001` through `Agent-B005`. The only direct UID000158 assignment match was the current B001 `goal.md`; no active direct-target report or competing assignment was found.
- Central executed root checked: `executed-b-agent-research/**`. The following matching historical reports were opened and classified:
  - `executed-b-agent-research/B008/00005A-FolderTreePane-class-source-quality.md`: class/layout support. It supplies the embedded `Tree` member and prior no-hand-port direction, but it does not independently resolve UID000158's exact end or retained destructor identity.
  - `executed-b-agent-research/B010/0000JG-FolderTreePane-empty-emitter-family-source-quality.md`: source-family support. It implemented the current file route and old EH-only marker, but its `[...5668)` boundary and owner UID0000JG are superseded by the fresh function-chunk and direct-class evidence.
  - `executed-b-agent-research/B013/0002MX-FolderTreeStorageDestructor-empty-emitter-source-quality.md`: direct callee/dependency support for element destruction and storage release.
  - `executed-b-agent-research/B001/000157-FolderTreePaneTreeAndSortHelpers.md`: aggregate/adjacency inventory only; not a direct UID000158 source-quality report.
  - `executed-b-agent-research/B001/00036K-FolderTreeVtableData-empty-emitter-source-quality.md`: tree-vtable identity and xref support.
  - `executed-b-agent-research/B010/0002MW-FolderTreeElemCopyConstruct-empty-emitter-source-quality.md`: predecessor and padding adjacency support.
  - `executed-b-agent-research/B014/0000FB-FolderTreePaneTreeIterator-class-source-quality.md`: successor/iterator support. It correctly observed that the target jump consumes `0x004b5668` and padding starts at `0x004b5669`.
  - `executed-b-agent-research/B010/000155-FolderTreePaneCore-empty-emitter-source-quality.md`: constructor and cleanup-island support.
  - `executed-b-agent-research/B007/00034F-FolderTreeIteratorVtableResetDestructor-empty-emitter-source-quality.md`: direct project precedent for a retained ordinary destructor body routed through a class-level virtual destructor with a covered-by marker.
  - `executed-b-agent-research/B001/00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality.md`: outer scalar-destructor and member/base teardown support.
- Archive root `archived/**`, `tools/leaser/Agents/Older-Research/**`, and `tools/leaser/Agents/SpecialReports/**` were searched with target UID, range, address, name, constructor, tree/template, storage, and `+0x130` terms. They contained no direct UID000158 research artifact. This is an explicit no-direct-report conclusion; the executed matches above are support or family leads, not substitutes.
- Historical B008/B010 statements remain useful evidence that the block must not be hand-ported as vptr/call glue. Their narrower claim that it is only a constructor-EH fragment is historicalized because fresh unwind, scalar-destructor, and vtable evidence identify a complete-object tree destructor body retained as a constructor unwind action.

## Target
- Target UID: UID000158.
- Target path: current `by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md`; historical pre-callback path `by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md`.
- Source queue/report row: the evidence-time refreshed `auto-generated/-ag-research-tracker.md` placed the old target in the `by-memory` reconstructable/not-covered queue at `86/90` with zero direct reports. Any later queue state is validator/supervisor-owned and is not asserted here.
- Supervisor classification: the exact report SHA `E0DBD728C0544D55975A057FE8AD9431A219D5CFACD72759EB8F0E70C3142DFB` passed Gate 1, and B001 completed only the authorized implementation callback and validation work recorded below.
- Current scores and parent state: target `92/94`, owner/emitter UID0000F9, reconstructable true, blank position, `Nested:8`. Direct semantic class UID0000F9 is `90/93`, owner/emitter UID0000JG, reconstructable true.

## Current Target State
- Current metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000F9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000F9`, blank optional position, and `Nested:8`.
- Current owner/emitter/reconstructable state: UID0000F9 is the direct semantic class owner and UID0000JG remains the translation-unit route through that class. The target is reconstructable because the inline virtual destructor source construct is required, not because its compiler-expanded instructions should be copied.
- Current C++/emitter state: the target formal block is the exact class-covered marker, and UID0000F9's complete managed class declaration contains one inline empty virtual destructor definition. Generated `FolderTreePane.cpp` places UID000158 directly after the Tree class and before UID00034I, with no independent compiler-glue body.
- Closed historical blockers: the old path excluded the final byte of a five-byte tail jump; the old title understated the retained destructor role; direct class ownership and nesting were absent; the exact unwind state and complete-object semantics were undocumented; successor padding was omitted; and the class declaration left the source cause unresolved. The callback closed each item without creating a child or shared Tree file.
- Related target/support docs checked: UID0000F9 Tree class, UID0000FC TreeStorage class, UID00005A FolderTreePane class, UID0000JG FolderTreePane file, UID000155 core, UID000157 aggregate, UID0002MX storage destructor, UID00034I tree scalar deleting destructor, UID00034K pane scalar deleting destructor, UID0001WP template context, UID0001UJ TreeElem, UID00036J/UID00036K vtable docs, `by-memory/-ignored.md`, current manual coverage rows, and generated `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`.
- Current artifact/lifecycle status: implementation and authorized validation are complete, and no B001 implementation work remains. B001 ran no `execute_report`, report probe/count/revalidation command, lifecycle command, move, or archive. Current report path/count/execution/archive state outside this artifact is supervisor/validator-owned and is neither asserted nor directed here.

## Executive Recommendation
- UID000158 is renamed and boundary-corrected in place with its UID and history preserved. The exact body is 25 bytes at `[0x004b5650,0x004b5669)`.
- Direct owner/emitter UID0000F9 and `Nested:8` are applied, with reconstruction retained through the existing UID0000JG `FolderTreePane.cpp` source family by way of the class owner.
- The owning Tree class's virtual destructor is defined inline with an empty body. This is the smallest human-source construct that regenerates the retained complete-object destructor, storage member destruction, LObject base teardown, vtable state transitions, scalar deleting wrapper, and constructor-unwind invocation without hand-porting compiler glue.
- UID000158 remains a distinct exact by-memory evidence page because the linker retained a concrete body and the EH map directly targets it. It was not split, merged into UID0002MX, or made non-reconstructable.
- No source-quality blocker remains. Original header factoring and explicit-versus-equivalent inline spelling remain bounded confidence caveats, not blockers to owner, emitter, range, score, or formal C++.

## Supervisor Active Recheck
- The initial assignment explicitly requested a fresh report-only re-audit of UID000158 rather than a restatement of older aggregate work.
- The item did not require a new child split. The callback applied the in-place one-byte range correction, semantic rename, class-parent correction, and ignored-padding registration.
- Every source-bearing item in scope has a disposition: UID000158 is retained ordinary destructor support; UID0000F9 receives the human-source destructor definition; UID0002MX remains storage-member destructor support; UID00034I remains scalar deleting wrapper support; and the constructor/EH actions remain compiler-generated invocation sites.

## Inference Research Guidance Check
- `by-structure.md` requires exact half-open ranges, preservation of UID/history during validator-aware renames, direct semantic ownership before file ownership, formal managed C++ only, compiler-glue exclusion, and explicit manual coverage text. Those rules drive the boundary, parent, marker, and class-block recommendations.
- Existing cleanup-fragment naming, direct UID0000JG ownership, `Nested:0`, old `[...5668)` end, and declaration-only virtual destructor were treated as hypotheses, not inherited truth.
- IDA fact: bytes, chunks, instructions, xrefs, unwind entries, vtable targets, callees, object offsets, and padding. Documentation evidence: current by-* metadata, historical reports, generated output, and manual coverage. Inference: the exact human source spelling is an inline empty virtual destructor and concrete specializations remain emitted through FolderTreePane.cpp.
- No current Wave2/Wave3 override was found. Historical Wave-style assumptions that the range was merely no-code constructor cleanup were not used as authority; only independently reproduced facts were retained.

## Heuristic / Inference Reanalysis And Validation
- Boundary heuristic: current path end `0x004b5668` was rejected because the `jmp rel32` begins at `0x004b5664` and occupies bytes through `0x004b5668`. The first padding byte is `0x004b5669`; exact end is therefore `0x004b5669`.
- Function-identity heuristic: IDA associates this body with constructor `sub_4B1B90`, but chunk ownership alone does not erase source semantics. The same exact body is an unwind action for a fully constructed Tree member, mirrors the Tree portion of scalar deletion, writes the Tree vtable, destroys its member, and tail-calls its base destructor. Best role: retained complete-object Tree destructor.
- Liveness heuristic: one direct xref is sufficient because it is an EH unwind-map action at state 3, reached after the embedded Tree completed construction. Lack of ordinary callers does not make the body dead.
- Object/type heuristic: receiver `ECX` is the Tree object, storage is exactly `this+4`, and the constructor supplies `FolderTreePane+0x130`. Vtable `0x0061a500` has the decorated concrete Tree specialization identity. These facts outweigh the generic current file owner.
- Source-shape alternatives ranked:
  1. Inline empty virtual Tree destructor: selected. It accounts for all compiler-expanded member/base behavior and matches the adjacent TreeItor precedent.
  2. Out-of-line empty Tree destructor: behaviorally plausible, but weaker because no independent normal function model or source-call route survives and the body is folded into a constructor-owned chunk model.
  3. Handwritten destructor that explicitly resets vptr/calls storage/LObject: rejected as compiler-shaped, unsafe, and unlike plausible source.
  4. Constructor-only cleanup with no destructor source construct: rejected because complete-object semantics, scalar-wrapper reuse pattern, and virtual class declaration require a destructor cause.
  5. Merge into storage destructor UID0002MX: rejected because UID000158 owns a different receiver, vtable transition, and base teardown.
- Name heuristic: `Tree<FolderTreePane::TreeElem>` and `TreeItor` are RTTI/vtable-backed. `TreeStorage` and member names remain project-facing inferred names corroborated by layout and accepted source-family conventions; they should not be replaced by `std::vector` solely from vector-like compiler lowering.
- Source placement heuristic: concrete specialization stays in UID0000JG FolderTreePane source family because no scored shared Tree source owner exists. UID0000F9 is the direct class owner, not a new by-file.
- Generated-output heuristic: the old distant UID000158 comment is pollution caused by file-level attachment. Nesting the target under UID0000F9 should place the covered-by marker with Tree children while the inline destructor appears once in the Tree declaration.
- No unresolved issue affects implementation. Exact original header filename and whether the empty destructor was explicitly written inline cannot be recovered from stripped binary evidence; the accepted block is the least speculative source that preserves all behavior.

## Evidence Standards Used
- Evidence types: fresh IDA MCP session discovery/health, function lookup, chunks, raw bytes and SHA256, instruction disassembly, xrefs, outgoing refs, constructor and cleanup-island disassembly, EH FuncInfo/unwind-map data, vtable refs, scalar destructor siblings, storage destructor behavior, LObject constructor/destructor stubs, adjacent functions/padding, current by-* docs, historical executed reports, generated source, and manual coverage.
- The evidence is strong enough because independent byte, control-flow, EH-state, vtable, object-offset, and sibling-destructor routes converge on the same complete-object role.
- Evidence ladder: direct binary facts govern boundaries and semantics; decorated vtable/type evidence governs class identity; constructor layout and EH state govern member lifetime; current docs and historical reports provide leads; source spelling is inferred only after those facts. Confidence stops at 94 because stripped binaries do not preserve exact header factoring or source token spelling.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed: fresh `idb_list`; `server_health`; bounded `lookup_funcs` at target, end, successor, constructor, storage destructor, scalar destructors, LObject helpers, and adjacent iterator destructor; target/predecessor/successor `get_bytes`; disassembly; decompilation where applicable; function chunks; xrefs; outgoing refs; vtable refs; constructor EH chunk; FuncInfo and unwind map reads; and cleanup-island review.
- by-* docs, support docs, old reports, generated reports, and trackers checked: all paths listed in Supporting Research and Current Target State, current manual by-memory/by-class/by-file/by-template/by-struct coverage reports, refreshed generated FolderTreePane.cpp, active Agent-B001-B005 roots, central executed root, archive root, Older-Research, and SpecialReports.
- Historical search terms included `UID000158`, `004b5650`, `004b5668`, `FolderTreePaneTreeDestructorCleanup`, `sub_4B1B90`, `FolderTreePane`, `Tree`, `TreeStorage`, `TreeItor`, `0x130`, constructor, destructor, EH, vtable, and generated source-family terms.
- Negative checks performed: no independent function at target/end/successor; no ordinary callers; no data/pointer/immediate inbound route; no strings/constants; no source body requiring explicit vptr/base/storage calls; no padding inside corrected range; no direct historical UID000158 report; no scored shared Tree by-file; no evidence for a `std::vector` source replacement; and no source reason to emit scalar-delete or EH glue.
- Failed, unavailable, or intentionally skipped checks: early PowerShell transport attempts omitted `-UseBasicParsing`, shadowed PowerShell `$args`, parsed `session_id` under the wrong property, or used `address` instead of the `get_bytes` schema's `addr`. Those were client/request-shape failures or schema errors, not valid IDB-backed failures. After correcting the transport and schema, all valid bounded calls succeeded. IDA mutation and implementation validators were intentionally skipped during the initial report-only research phase; the later authorized callback validators are recorded under Validator Results.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C158-001 | Preserve UID000158 while correcting its path, range, title, and report history. | 100 | Current UID header and validator-aware rename convention. | UID000158 target path/header/history | incorporate | applied |
| C158-002 | No direct historical UID000158 report exists; all matching executed reports are support/family leads. | 99 | Active, executed, archived, Older-Research, and SpecialReports path-specific search. | UID000158 Supporting Research/history | incorporate | applied |
| C158-003 | Evidence-time MCP session `5288313d` was healthy and analysis-ready. | 100 | Fresh `idb_list`, `server_health`, bounded lookup/bytes calls. | UID000158 IDA evidence | incorporate | applied |
| C158-004 | Exact bytes are 25 bytes with SHA256 `40EBF7F09188473DFC51737FB1CDBF066874424B9472997BC5AB3820E28BDF99`. | 100 | `get_bytes [0x4b5650,0x4b5669)`. | UID000158 exact range evidence | incorporate | applied |
| C158-005 | Exact half-open range is `[0x004b5650,0x004b5669)`, not `[...5668)`. | 100 | Five-byte tail jump consumes `0x004b5668`; first padding at `0x004b5669`. | UID000158 path/title/range | incorporate | applied |
| C158-006 | Predecessor `[0x004b564d,0x004b5650)` is three `0xcc` bytes. | 100 | Raw bytes and SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`. | UID000158 and ignored evidence | already-present | already-present |
| C158-007 | Successor `[0x004b5669,0x004b5670)` is seven `0xcc` bytes. | 100 | Raw bytes and SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`. | `by-memory/-ignored.md`; UID000158 | incorporate | applied |
| C158-008 | IDA models target as constructor `sub_4B1B90` chunk `[0x4b5650,0x4b5669)`, not an independent function. | 100 | `lookup_funcs` and function chunks. | UID000158 function identity | incorporate | applied |
| C158-009 | ABI receiver is a complete Tree object in ECX; ESI preserves it, storage receiver is `this+4`, and LObject receives restored ECX. | 99 | Exact disassembly and calling convention. | UID000158 ABI/behavior | incorporate | applied |
| C158-010 | Every target instruction and side effect is resolved. | 100 | Disassembly at `0x4b5650-0x4b5668`. | UID000158 instruction inventory | incorporate | applied |
| C158-011 | Outgoing refs are exactly tree vtable `0x61a500`, storage destructor `0x4b56e0`, and LObject teardown `0x4f4a90`. | 100 | Xrefs/outgoing refs/disassembly. | UID000158 callee/vtable inventory | incorporate | applied |
| C158-012 | Sole inbound code xref is EH action `0x5fe944`; no ordinary/data/pointer/immediate routes exist. | 100 | `xrefs_to`, caller, and negative-reference checks. | UID000158 liveness/negative evidence | incorporate | applied |
| C158-013 | EH action converts FolderTreePane receiver to embedded Tree at `+0x130`. | 100 | `0x5fe93b-0x5fe944` disassembly and constructor layout. | UID000158, UID00005A | incorporate | applied |
| C158-014 | Constructor has main, target, and EH chunks and constructs Tree at `+0x130` with storage at `+0x134/+0x138/+0x13c`. | 100 | `sub_4B1B90` chunks/disassembly. | UID000158, UID000155, UID00005A | incorporate | applied |
| C158-015 | FuncInfo `0x65ce40` and six unwind entries establish exact construction states. | 99 | Raw data and EH action disassembly. | UID000158 EH inventory | incorporate | applied |
| C158-016 | State 3 invokes UID000158 only after Tree construction completed; target is live complete-object cleanup. | 99 | Unwind predecessor/action chain. | UID000158 role/liveness | incorporate | applied |
| C158-017 | Best semantic identity is retained `Tree<FolderTreePane::TreeElem>` complete-object destructor. | 98 | Vtable, member/base teardown, EH state, scalar sibling. | UID000158 title/status | incorporate | applied |
| C158-018 | Historical constructor-EH-only/no-source-body interpretation is incomplete. | 98 | Fresh complete-object and sibling evidence. | UID000158, UID0000F9, UID0000JG history | historicalize | applied |
| C158-019 | Human source cause is an inline empty virtual Tree destructor. | 94 | Class declaration, compiler-expanded body, TreeItor precedent, no source-authored side effect. | UID0000F9 formal block | incorporate | applied |
| C158-020 | Explicit vptr store, storage call, LObject call, EH call site, and scalar-delete logic must not be hand-ported. | 100 | Compiler ABI/destructor patterns. | UID000158 and support negative evidence | reject-invalid | excluded-with-reason |
| C158-021 | Direct owner is UID0000F9 Tree class. | 99 | Receiver/vtable/decorated specialization and direct-class precedent. | UID000158 metadata | incorporate | applied |
| C158-022 | Final source-family route remains UID0000JG FolderTreePane.cpp through UID0000F9. | 94 | Existing concrete specialization route; no scored shared Tree file. | UID0000F9, UID0000JG, UID0001WP | already-present | applied |
| C158-023 | Target remains `RECONSTRUCTABLE:TRUE`. | 99 | Required source destructor construct and retained concrete body. | UID000158 metadata | already-present | already-present |
| C158-024 | Target nesting becomes `Nested:8`. | 99 | Direct class child convention and UID00034F/UID00034I precedent. | UID000158 metadata | incorporate | applied |
| C158-025 | Target emitter becomes UID0000F9 with blank optional position. | 99 | Class-owned covered-by marker; no ordering need. | UID000158 metadata | incorporate | applied |
| C158-026 | Target formal block becomes the exact class-covered marker below. | 99 | Compiler-regenerated body and managed child convention. | UID000158 formal block | incorporate | applied |
| C158-027 | Target score becomes `92/94`. | 96 | All binary/source blockers closed; token/header caveat retained. | UID000158 metadata/score | incorporate | applied |
| C158-028 | UID0000F9 score becomes `90/93`. | 95 | Destructor definition closes declaration/body gap; class role and vtable are direct. | UID0000F9 metadata/score | incorporate | applied |
| C158-029 | UID0000F9 formal class block is replaced completely, changing only destructor declaration to inline empty definition. | 99 | Current block plus accepted source cause. | UID0000F9 formal block | incorporate | applied |
| C158-030 | UID000157 records corrected range, semantic role, and successor padding; metadata remains `88/90`. | 98 | Aggregate inventory and fresh boundary facts. | UID000157 support/history | incorporate | applied |
| C158-031 | UID0000JG records class-routed ordinary destructor and historicalizes old file-direct/EH-only wording; score stays `91/90`. | 96 | Existing source placement plus fresh class owner. | UID0000JG support/history | incorporate | applied |
| C158-032 | UID0001WP records ordinary destructor source cause and current concrete source route; score stays `88/91`. | 95 | Template context and sibling specialization. | UID0001WP support/history | incorporate | applied |
| C158-033 | UID0001UJ records that element cleanup is owned by TreeStorage and invoked by the Tree destructor; score stays `88/91`. | 96 | 36-byte element/storage destructor evidence. | UID0001UJ support | incorporate | applied |
| C158-034 | UID0002MX adds target as complete-object caller category and corrected path; score stays `88/91`. | 100 | Call at `0x4b565c` and current storage evidence. | UID0002MX support | incorporate | applied |
| C158-035 | UID00034I distinguishes its scalar wrapper from UID000158 ordinary body and updates path; score stays `87/91`. | 100 | Scalar wrapper disassembly/vtable slot. | UID00034I support/history | incorporate | applied |
| C158-036 | UID00005A records constructor state, `m_tree+0x130`, and compiler-driven ordinary destruction; score stays `88/89`. | 97 | Constructor/EH/layout evidence. | UID00005A support | incorporate | applied |
| C158-037 | `by-memory/-ignored.md` adds `[0x004b5669,0x004b5670)` without disturbing predecessor or adjacent UID00034F. | 100 | Seven `0xcc` bytes and exact next start. | ignored padding inventory | incorporate | applied |
| C158-038 | Existing Tree/TreeItor/TreeStorage project-facing names are retained; `std::vector` substitution is rejected. | 92 | RTTI, accepted family conventions, layout, missing original UDTs. | target/support naming notes | reject-stale | excluded-with-reason |
| C158-039 | No new shared Tree source file or child is created. | 94 | No scored shared owner; concrete specialization route is established. | source placement/final recommendation | not-applicable | excluded-with-reason |
| C158-040 | Exact stale manual coverage rows and insertion text are supplied for supervisor ownership. | 100 | Current manual reports read without editing. | coverage section | incorporate | already-present |
| C158-041 | Generated verification must prove one inline destructor, one UID000158 marker, preserved children, and no explicit compiler glue. | 99 | Current FolderTreePane.cpp readback and applied emitter route. | Validator Results/checklist | incorporate | applied |
| C158-042 | Each changed ordinary by-* page requires one scoped validator and a final target `--wait-generated` refresh during callback. | 100 | Workflow requirement; report-only restriction observed. | implementation checklist | incorporate | applied |
| C158-043 | Old `[...5668)` links must be synchronized across all six ordinary support pages that currently contain them. | 100 | Exact repository search result. | named support docs | incorporate | applied |
| C158-044 | All remaining uncertainty is bounded and does not defer any current score/C++/ownership blocker. | 95 | Exhaustive evidence and ranked alternatives. | open questions/confidence | incorporate | applied |

### Callback Verification Notes
| Claim ID | Final destination proof |
| --- | --- |
| C158-001 | Validator command `000000010816` preserved UID000158 while changing the live path to `by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md`; the page retains the prior path and B008/B010 provenance as historical facts. |
| C158-002 | The path-specific active/executed/archive/Older-Research/SpecialReports classifications and explicit no-direct-report conclusion remain in Supporting Research and are retained in the target history without treating a support report as a substitute. |
| C158-003 | The report and target evidence retain evidence-time session `5288313d`, PID `20244`, healthy analysis state, and bounded-call status; callback work introduced no binary uncertainty and did not mutate IDA. |
| C158-004 | The renamed target records the complete 25-byte sequence and SHA256 `40EBF7F09188473DFC51737FB1CDBF066874424B9472997BC5AB3820E28BDF99`. |
| C158-005 | The target header, title, Item Summary, instruction inventory, and all live ordinary links use exact half-open end `0x004b5669`; the old end survives only in explicitly historical text. |
| C158-006 | The target and existing ignored-range inventory retain predecessor `[0x004b564d,0x004b5650)`, three `0xcc`, and SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`. |
| C158-007 | The target and `by-memory/-ignored.md` now record successor `[0x004b5669,0x004b5670)`, seven `0xcc`, and SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`, preserving adjacent ranges. |
| C158-008 | UID000158 documents IDA's `sub_4B1B90` chunk association and the evidence-backed distinction between chunk ownership and independent function/source identity. |
| C158-009 | UID000158 records ECX/ESI complete-object ABI, `this+4` TreeStorage receiver, restored Tree receiver, and LObject tail teardown. |
| C158-010 | UID000158 retains the address-by-address instruction table through the five-byte jump ending at `0x004b5668`, with every side effect dispositioned. |
| C158-011 | UID000158 retains exact outgoing references to vtable `0x0061a500`, UID0002MX at `0x004b56e0`, and LObject teardown at `0x004f4a90`; support pages link the same relationships. |
| C158-012 | UID000158 preserves sole inbound EH action `0x005fe944` and explicit negative ordinary/data/pointer/immediate route results. |
| C158-013 | UID000158 and UID00005A record `FolderTreePane+0x130` receiver adjustment and the embedded Tree lifetime relationship. |
| C158-014 | UID000158 and UID00005A record constructor main/target/EH chunks and Tree/TreeStorage offsets `+0x130/+0x134/+0x138/+0x13c`; UID000155 remains unchanged support. |
| C158-015 | UID000158 retains FuncInfo `0x0065ce40` and the complete six-state unwind map without collapsing actions or states. |
| C158-016 | UID000158 identifies state 3 as the live post-Tree-construction cleanup route and preserves the action predecessor chain. |
| C158-017 | The corrected target title, summary, status, and class relationship identify the retained complete-object `Tree<FolderTreePane::TreeElem>` destructor. |
| C158-018 | UID000158, UID0000F9, and UID0000JG retain B008/B010 EH-only/file-direct claims as superseded historical leads while preserving their no-hand-port value. |
| C158-019 | UID0000F9's complete managed class block defines exactly one inline empty `virtual ~Tree()` body; validator `000000010817` accepted the page. |
| C158-020 | UID000158 and support negative evidence explicitly exclude handwritten vptr, TreeStorage, LObject, EH-invocation, and scalar-delete logic; generated readback confirms none is emitted as a target body. |
| C158-021 | UID000158 metadata now has `CANONICAL_OWNER:0000F9`; target, class, and file prose consistently describe UID0000F9 as direct semantic owner. |
| C158-022 | UID0000F9, UID0000JG, and UID0001WP retain the concrete FolderTreePane.cpp route without creating file-root reconstruction metadata or a shared Tree file. |
| C158-023 | UID000158 remains `RECONSTRUCTABLE:TRUE`; the callback changed no accepted reconstructability disposition. |
| C158-024 | UID000158 metadata now has `Nested:8`, placing its generated marker with the Tree class children. |
| C158-025 | UID000158 metadata now has `EMITTER_UIDS:0000F9` and a blank optional position; generated order is class-owned rather than manually forced. |
| C158-026 | UID000158 contains the exact accepted formal covered-by marker and no source-authored compiler body. |
| C158-027 | UID000158 metadata and visible score are `92/94`; validator `000000010816` and final validator `000000010832` both returned exit 0 and `ok: 1`. |
| C158-028 | UID0000F9 metadata and visible score are `90/93`; unrelated class metadata and children remain intact. |
| C158-029 | UID0000F9 retains the complete accepted class block and `[[CHILDREN]]`; only the destructor declaration became the accepted inline empty definition. |
| C158-030 | UID000157 remains `88/90`, non-emitting, and records the corrected target range/identity, successor padding, aggregate inventory, and superseded EH-only interpretation. |
| C158-031 | UID0000JG remains `91/90`, records UID0000F9 direct ownership and the retained source-family route, and historicalizes file-direct/EH-only wording without file-root reconstruction metadata. |
| C158-032 | UID0001WP remains `88/91`, records the ordinary destructor source cause and concrete source route, and preserves shared-header caveats plus prior UID000346/UID000347/UID00034H references after corrective validator `000000010821`. |
| C158-033 | UID0001UJ remains `88/91`, distinguishes containing Tree destruction from per-record name destruction, and retains the non-`std::vector` layout/source wording. |
| C158-034 | UID0002MX remains `88/91`, records UID000158 as a complete-object caller at `0x004b565c`, and preserves the raw storage destructor body and element cleanup details. |
| C158-035 | UID00034I remains `87/91`, retains its compiler-covered marker, and distinguishes scalar deletion from the UID000158 ordinary body using the corrected link. |
| C158-036 | UID00005A remains `88/89`, records `m_tree` at `+0x130`, constructor/EH state, storage offsets, and compiler-driven member destruction without changing its formal class block. |
| C158-037 | `by-memory/-ignored.md` adds only the accepted seven-byte successor alignment evidence in the existing FolderTreePane helper row; predecessor and UID00034F adjacency remain present. |
| C158-038 | Existing Tree, TreeItor, and TreeStorage names remain in all bounded docs and generated source; `std::vector` substitution is excluded because lowering/layout evidence does not establish that source type. |
| C158-039 | No new child or shared Tree file was created; UID000158 was renamed in place and remains routed through UID0000F9 to UID0000JG. |
| C158-040 | The exact manual supervisor-owned coverage replacement/insertion text below remains unchanged. B001 did not apply it; validator `000000010816` automatically synchronized the target link in by-memory coverage as a recorded validator side effect only. |
| C158-041 | Generated FolderTreePane.cpp readback after `000000010832` proves one Tree class, one inline destructor, one UID000158, one UID00034I, each existing Tree method once, no UID000157, no old path, and no explicit target compiler-glue body. |
| C158-042 | Every changed ordinary page received a scoped validator; corrective UID0001WP validation is recorded separately, and final target `--wait-generated` command `000000010832` completed. |
| C158-043 | Repository readback finds no stale live ordinary support link to the old filename/range; remaining old-range text is explicit history, and `.bak` manual-coverage files were not edited. |
| C158-044 | Applied metadata, formal source, support evidence, validators, and generated readback close every current owner/range/C++/score blocker; original header/token spelling remains bounded only. |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation: exact 25-byte body; Tree vtable write; storage destruction on `this+4`; LObject tail teardown; complete-member EH state; Tree object at FolderTreePane `+0x130`; scalar-wrapper sibling; and decorated concrete Tree vtable identity.
- Corroborating documentation/generated-report evidence: UID0000F9 already declares the virtual destructor and owns scalar-wrapper child UID00034I; UID00034F demonstrates the same class-covered ordinary-destructor pattern for TreeItor; generated FolderTreePane.cpp exposes the missing definition and misplaced old marker.
- Strongest inference chain: state 3 cleans a fully constructed Tree object, the body performs the canonical derived-member-base destructor sequence, and the class already requires a virtual destructor. An empty source destructor is therefore sufficient and safer than any explicit ABI glue.

## IDA MCP Facts
- Function/range facts: `lookup_funcs(0x004b5650)` and boundary lookups map the target to constructor `sub_4B1B90`; constructor chunks are `[0x4b1b90,0x4b1ce5)`, `[0x4b5650,0x4b5669)`, and `[0x5fe920,0x5fe97a)`. There is no independent function at `0x4b5650`, `0x4b5668`, or `0x4b5669`.
- Target bytes: `56 8b f1 8d 4e 04 c7 06 00 a5 61 00 e8 7f 00 00 00 8b ce 5e e9 27 f4 03 00`; SHA256 `40EBF7F09188473DFC51737FB1CDBF066874424B9472997BC5AB3820E28BDF99`.
- Instruction facts:
  - `0x4b5650 push esi`; `0x4b5651 mov esi,ecx`.
  - `0x4b5653 lea ecx,[esi+4]` selects embedded TreeStorage.
  - `0x4b5656` stores Tree vtable `0x61a500` at `[esi]`.
  - `0x4b565c` calls UID0002MX at `0x4b56e0`.
  - `0x4b5661 mov ecx,esi`; `0x4b5663 pop esi`.
  - `0x4b5664 jmp 0x4f4a90`; the rel32 tail jump occupies bytes through `0x4b5668`.
- Data/table/padding facts: predecessor three-byte padding and successor seven-byte padding are all `0xcc`. FuncInfo at `0x65ce40` has magic `0x19930522`, six states, unwind map `0x65cebc`, no try/IP map, and trailing flags value 1.
- Unwind map inventory:
  - State 0, previous -1, action `0x5fe920`: outer base cleanup through `sub_55E780`.
  - State 1, previous 0, action `0x5fe928`: LObject teardown for partially built Tree.
  - State 2, previous 1, action `0x5fe930`: TreeStorage destruction at Tree `+4`.
  - State 3, previous 0, action `0x5fe93b`: completed Tree cleanup through UID000158 after adding `0x130`.
  - State 4, previous 3, action `0x5fe949`: embedded TreeItor at `+0x170`.
  - State 5, previous 4, action `0x5fe957`: temporary iterator cleanup.
- Xref facts: target has exactly one inbound code xref from `0x5fe944`; no ordinary caller or data/pointer/immediate xref. Outgoing refs are exactly vtable `0x61a500`, call `0x4b56e0`, and tail jump `0x4f4a90`.
- Vtable/global/type facts: xrefs to Tree vtable `0x61a500` are constructor `0x4b1bf7`, outer cleanup island `0x4b1d1e`, UID000158 `0x4b5656`, Tree scalar wrapper `0x4b59f9`, and FolderTreePane scalar wrapper `0x4b5aa1`.
- Storage facts: UID0002MX destroys each 36-byte element's SimpleUString at `+0x14`, frees validated vector-like storage, and zeros begin/end/capacity. Its refs include constructor cleanup, UID000158, both scalar destructor paths, and partial Tree construction cleanup.
- Base facts: LObject constructor `0x4f4a80` and destructor `0x4f4a90` are tiny vtable-setting stubs. UID000158 tail-calls the destructor stub with the complete Tree receiver restored.
- Negative IDA facts: no strings/constants, no separate direct-called ordinary destructor function model, no source-only side effect, no additional target xref, and no padding inside the corrected body.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004b5650,0x004b5669)` | UID000158, renamed `FolderTreePaneTreeDestructor` | Retained complete-object Tree destructor body | true | UID0000F9 | current `92/94` | implemented/validated corrected boundary, owner, and C++ disposition |
| `[0x004b56e0,0x004b575f)` | UID0002MX FolderTreeStorageDestructor | TreeStorage member destructor | true | UID0000FC | current `88/91` | already source-routed |
| `[0x004b59f0,0x004b5a38)` | UID00034I FolderTreeScalarDeletingDestructor | Compiler scalar deleting wrapper | true | UID0000F9 | current `87/91` | covered-by marker |
| `[0x004b5a70,0x004b5af4)` | UID00034K FolderTreePaneScalarDeletingDestructor | Compiler outer scalar deleting wrapper | true | UID00005A | current `88/92` | no target change required |
| `[0x004f4a90,0x004f4a97)` | shared LObject teardown | Base destructor stub | compiler/source support | LObject family | existing | callee evidence only |
| `[0x004b5669,0x004b5670)` | ignored range | alignment padding | false | none | n/a | registered in ignored inventory |
| `[0x004b5670,0x004b5677)` | UID00034F | TreeItor ordinary destructor/vtable reset | true | UID0000FB | current `87/91` | adjacent precedent |
| `[0x004b1cf0,0x004b1d41)` | no standalone UID change | compiler cleanup island | false as standalone source | constructor/core evidence | n/a | historical/support only |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005fe944 -> 0x004b5650` | sole inbound code xref | Constructor unwind state 3 invokes completed embedded Tree cleanup. |
| `0x004b5656 -> 0x0061a500` | vtable data ref | Receiver is concrete `Tree<FolderTreePane::TreeElem>`. |
| `0x004b565c -> 0x004b56e0` | direct call to UID0002MX | Destroys TreeStorage member at Tree `+4`. |
| `0x004b5664 -> 0x004f4a90` | tail jump | Performs LObject base teardown with Tree receiver restored. |
| `0x004b1bf7 -> 0x0061a500` | constructor vtable store | Constructs the same embedded Tree at FolderTreePane `+0x130`. |
| `0x004b59f9 -> 0x0061a500` | scalar-wrapper vtable store | Scalar deleting path includes same complete Tree destruction semantics. |
| `0x004b5aa1 -> 0x0061a500` | outer scalar-wrapper vtable store | FolderTreePane destruction reaches embedded Tree semantics. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: UID0000F9 inline virtual destructor definition and Tree vtable; UID00005A `m_tree` placement; UID0002MX storage behavior; UID00034I scalar wrapper; UID00034F ordinary-destructor precedent; UID00036J/UID00036K vtable identity; UID0001WP concrete template route; and UID000155 constructor/EH chunks.
- Historical pre-callback stale state: old `[0x004b5650,0x004b5668)` links; target title/owner/nesting; statements that the body was only an anonymous EH fragment; UID0000F9's declaration-only destructor; UID000157's omitted successor padding; and manual coverage scores/descriptions that lagged ordinary pages.
- Current generated state after validator command `000000010832`: FolderTreePane.cpp contains one Tree class, one inline empty virtual destructor, UID000158 once directly under that class, UID00034I once after it, and each existing Tree method once. It has no old path/comment, target Empty Emitter Marker, aggregate duplicate, explicit target vptr/storage/LObject/EH implementation, or explicit target scalar-wrapper implementation. Manual coverage remains supervisor-owned; B001 did not apply the supplied rows.

## Ranked Ownership Analysis

### 1. UID0000F9 Tree_struct_FolderTreePane__TreeElem_
- Evidence for: exact Tree receiver, decorated vtable identity, storage at `this+4`, LObject base, applied inline virtual destructor definition, UID00034I sibling ownership, and UID00034F class-destructor precedent.
- Evidence against: class filename is a generated alias and original shared-header factoring is unknown.
- Decision: selected direct semantic owner and emitter. Alias/header uncertainty does not weaken concrete class ownership.

### 2. UID0000JG FolderTreePane file
- Evidence for: all concrete FolderTreePane Tree specialization source currently emits through this file; no scored shared Tree file exists.
- Evidence against: a file is broader than the exact receiver class and should not be the direct parent of a class method/destructor support page.
- Decision: UID0000JG is retained as the ultimate source-family route through UID0000F9, while current direct target ownership is UID0000F9.

### 3. UID000155 constructor/core or UID0002MX TreeStorage
- Evidence for: IDA attaches the chunk to constructor `sub_4B1B90`; the body directly calls UID0002MX.
- Evidence against: constructor chunk ownership is compiler EH organization, not human source ownership; TreeStorage is only one member and does not own the Tree vtable or LObject base teardown.
- Decision: rejected as direct owner. Preserve both as evidence/support.

### Proposed new file/grouping, if applicable
- Applied disposition: no new by-file or grouping. The existing target was renamed in place under UID0000F9.
- Likely full contents: not applicable; existing UID0000F9 formal class block is sufficient.
- Candidate related items that belong: UID000158 and existing UID00034I remain Tree class children.
- Candidate related items rejected: constructor EH action, outer cleanup island, scalar wrapper, raw vtable data, and storage member destructor remain their existing evidence/support items.
- Standalone, narrow, or broad source-file inference: concrete template support remains in FolderTreePane.cpp; likely reusable header factoring is recorded but not fabricated.

## Source Placement
- Applied source file/class/global/module placement: human source destructor definition in UID0000F9 Tree class; exact memory marker as nested UID000158 child; final translation-unit route UID0000JG FolderTreePane.cpp.
- Why this placement fits source-tree and subsystem context: all concrete Tree/TreeStorage/TreeItor declarations and methods already generate in that file, and no generic Tree owner currently clears source-quality gates.
- Rejected placements and why: separate generated `class_Tree...cpp` is an artifact; constructor/core ownership confuses EH organization with source; TreeStorage ownership misses vtable/base semantics; new shared Tree file would exceed evidence.
- Remaining placement uncertainty: original declarations may have lived in a shared header used by EventDispatcher and FolderTreePane. This does not change the current concrete emitter route.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: the historical pre-callback end was one byte short. The current corrected target is `[0x004b5650,0x004b5669)`, size `0x19`, because the final rel32 jump occupies five bytes starting at `0x004b5664`.
- Applied child/subrange disposition: no child creation or split. UID000158 was renamed/corrected in place, and only successor padding `[0x004b5669,0x004b5670)` was added to the ignored alignment row.
- Padding/table/data/code distinctions: predecessor `[0x004b564d,0x004b5650)` and successor `[0x004b5669,0x004b5670)` are `0xcc`; target is executable destructor code; next exact function starts at `0x004b5670`.
- Parent/container impact: UID000157 inventory and every live ordinary target link now use the corrected path. UID0000F9 is the direct parent. No aggregate nesting count changed because UID000158 remains an existing leaf.

## Negative Evidence Summary
- No normal source caller, independent IDA function, string, constant, data pointer, or immediate reference was found.
- Those negatives reject a separately invoked application method, but they do not reject liveness because the EH unwind map directly invokes the body.
- No instruction performs application-specific work beyond compiler destructor sequencing. Explicit vptr stores, member/base calls, EH state transitions, and scalar delete behavior are therefore excluded from handwritten C++.
- Nearby UID0002MX and UID00034F do not own this target: one is a member destructor and the other is a different class's destructor.
- Existing direct file ownership proves translation-unit placement only, not semantic parentage.
- No direct historical report or original UDT/source symbol resolves exact header factoring. No such evidence is needed to fabricate a shared file or inflate confidence above 94.

## IDA Rename / Type / Comment Recommendations
- Applied documentation-facing names/types/comments: target page `FolderTreePaneTreeDestructor`; role `Tree<FolderTreePane::TreeElem>` complete-object destructor; member `m_storage`; enclosing embedded member `m_tree` at `FolderTreePane+0x130`.
- Evidence for each applied name/type/comment: decorated vtable and existing class/template conventions prove Tree; object offsets prove storage/member relation; constructor class layout proves `+0x130`; current accepted docs establish project-facing `m_tree`/`m_storage` names.
- Items intentionally left unchanged and why: `TreeItor`, `TreeStorage`, and concrete specialization spellings remain; no `std::vector` replacement; no original IDA DB function rename/type mutation requested; no new shared source owner.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. The assignment forbids IDA mutation, and the report needs only documentation/source reconstruction changes.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes, but only through the two exact destination-specific managed blocks below. No body-only examples or samples exist elsewhere in this report.
- Target UID000158 destination block:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- UID0000F9 destination block, complete replacement preserving all accepted declarations and `[[CHILDREN]]`:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T> class TreeItor;

struct FolderTreeContentDimensionsContext;
struct FolderTreePaintTraversalContext;
struct FolderTreeHitTestContext;
struct FolderTreeNavigationContext;

template <class T>
class Tree : public LObject
{
public:
    Tree();
    virtual ~Tree()
    {
    }

    void ResetToSingleRoot();
    void TraverseContentDimensions(TreeItor<T> *start,
                                   FolderTreeContentDimensionsContext *context);
    void TraversePaintNodes(TreeItor<T> *start,
                            FolderTreePaintTraversalContext *context);
    void HitTestVisibleNodes(TreeItor<T> *start,
                             FolderTreeHitTestContext *context);
    void FindVisibleNavigationNode(TreeItor<T> *start,
                                   FolderTreeNavigationContext *context);

    TreeStorage<T> m_storage;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Reason it preserves exact original behavior: language-driven destruction invokes the TreeStorage member and LObject base in reverse construction order; virtual destructor semantics regenerate the concrete vtable/scalar wrappers; constructor unwinding invokes the ordinary destructor automatically.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: an empty inline virtual destructor in a small template wrapper is a conventional source cause for a retained concrete destructor body with no application-specific side effect.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `Tree`, `TreeItor`, `TreeStorage`, `FolderTreePane::TreeElem`, and `m_storage` use current accepted project-facing names backed by RTTI/layout/source-family evidence.
- Naming/coding style convention used and evidence for consistency: existing formal FolderTreePane template declarations use `template <class T>`, brace-on-next-line class/method style, pointer stars adjacent to names, and explicit virtual destructors. The replacement preserves that block exactly except for the destructor definition.
- Reason code should remain blank, if applicable: not applicable to UID0000F9. UID000158 itself emits only the formal covered-by marker because its source behavior is fully represented by the owning class definition and compiler-generated cleanup.
- Exact no-code proof for UID000158: every instruction is ABI/compiler destructor machinery; no application-specific source side effect exists; the single inbound route is compiler EH; member/base destructor sequencing is automatic; scalar deletion is separately compiler generated. Emitting a second body would duplicate or conflict with the class destructor.

## Final Recommendation
- Exact changes applied: validator-aware rename/range correction of UID000158; metadata `92/94`, owner/emitter UID0000F9, true, blank position, `Nested:8`; exact target marker; complete UID0000F9 block with inline empty virtual destructor; UID0000F9 score `90/93`; and the accepted support/history/link/padding updates.
- Exact parent assignments applied: UID000158 direct parent UID0000F9; UID0000F9 continues through UID0000JG.
- Exact items left no-owner/non-emitting and why: no new item. Compiler cleanup island, EH actions, scalar-delete mechanics, raw vtable data, and alignment remain represented through existing non-source/covered support and must not become handwritten bodies.
- Exact future work outside this assignment: none required for UID000158. A future independently assigned shared Tree header consolidation may revisit source factoring across FolderTreePane and EventDispatcher, but it is not a blocker or action in this report.

## Recommended Target Doc Changes
- Applied target path: `by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md`, renamed from `by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md` while preserving UID000158 and history.
- Exact report facts incorporated: bytes/hash, exact instruction/ABI table, chunk identity, sole EH xref, outgoing refs, constructor `+0x130` relation, six-state unwind map, vtable xrefs, storage/base/scalar siblings, padding hashes, source-shape alternatives, liveness, negative evidence, and historicalized B008/B010 assumptions.
- Applied metadata/score/owner/emitter/reconstructable/C++ changes: `92/94`, owner/emitter UID0000F9, reconstructable true, blank position, `Nested:8`, exact first managed block, updated Item Summary without metadata duplication.
- Historical/stale assumptions, rejected alternatives, and negative evidence preserved: prior research provenance remains, with old end, direct-file ownership, and EH-only interpretation labeled superseded. No-hand-port proof, no ordinary caller, no independent function, and no explicit compiler-glue source remain documented.

## Recommended Support Doc Changes
- `by-class/Tree_struct_FolderTreePane__TreeElem_.md` (UID0000F9): is `90/93`; the complete second managed block is applied; UID000158 is classified as retained ordinary complete-object destructor; the corrected path is current; all unrelated children and method content are preserved.
- `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md` (UID000157): remains `88/90` with non-emitting aggregate metadata; UID000158 end/title/role and successor padding are current, and EH-only wording is historicalized.
- `by-file/FolderTreePane.md` (UID0000JG): remains `91/90` with its translation-unit route; UID0000F9 is recorded as direct owner, the inline destructor is the source cause, and target path/old-owner wording are synchronized.
- `by-type/by-template/FolderTreePaneTreeTemplates.md` (UID0001WP): remains `88/91`; target path and ordinary-destructor role are current, with likely shared-header caveat and concrete FolderTreePane route preserved.
- `by-type/by-struct/FolderTreePane__TreeElem.md` (UID0001UJ): remains `88/91`; the corrected target path and containing-Tree versus stored-TreeElem-name destruction distinction are applied.
- `by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md` (UID0002MX): remains `88/91`; the corrected target path and complete-object caller classification at `0x4b565c` are applied, with raw destructor details preserved.
- `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md` (UID00034I): remains `87/91`; the corrected target path and scalar-wrapper versus ordinary-body distinction are applied, with marker and compiler-glue evidence preserved.
- `by-class/FolderTreePane.md` (UID00005A): remains `88/89`; constructor/EH proof for `m_tree` at `+0x130`, ordinary destructor source cause, and rejection of manual member teardown are applied, with formal C++ and unrelated content preserved.
- `by-memory/-ignored.md`: contains `[0x004b5669,0x004b5670)` in the existing FolderTreePane helper alignment row with byte evidence; predecessor `[0x004b564d,0x004b5650)` and all existing ranges are preserved.
- Old-path link synchronization: the validator-aware rename and scoped edits left no stale live ordinary link in UID0000JG, UID0000F9, UID0001WP, UID0001UJ, UID000157, UID0002MX, or UID00034I.

## Score And Metadata Recommendation
- Historical pre-callback score/metadata: target `86/90`, direct file owner/emitter UID0000JG, reconstructable true, blank position, `Nested:0`, old end/title, and verbose EH-only marker.
- Applied score/metadata: target `92/94`, owner/emitter UID0000F9, reconstructable true, blank position, `Nested:8`, corrected end/title and marker. UID0000F9 is `90/93`; all other named support scores remain unchanged.
- Score rationale and reason not higher/lower: completion rises because exact range/hash/instructions, EH map, liveness, role, class owner, source shape, formal code, padding, link set, generated expectations, and coverage text are all closed. Confidence rises because independent binary routes converge. It remains below 95 due exact original header factoring and explicit source token spelling.
- Score-improvement attempt:
  - Range blocker: raw bytes/disassembly resolved end to `0x4b5669`.
  - Liveness blocker: unwind map and sole xref prove state-3 use.
  - Function/source-role blocker: vtable/member/base/scalar sibling evidence resolves complete-object destructor.
  - Owner blocker: concrete receiver/vtable and class precedent resolve UID0000F9.
  - C++ blocker: full class block resolves the declaration-only gap while excluding ABI glue.
  - Padding blocker: exact predecessor/successor hashes resolve both gaps.
  - Source placement blocker: current concrete route and negative shared-owner search retain UID0000JG without fabricating a file.
  - Naming blocker: decorated Tree/TreeItor names plus accepted conventions retain project-facing names; no unsafe `std::vector` substitution.
- Applied metadata disposition: target completion/confidence/owner/emitter/nesting/path/title/formal block/summary changed; target UID, reconstructable true, and blank optional position were retained. Only UID0000F9 score/formal block changed among support metadata.

## Open Questions With Attempted Resolution
- Open question: is target merely constructor EH glue? Evidence checked: chunks, xref, six-state map, scalar siblings, vtable, member/base behavior. Resolution: it is a retained complete-object destructor body used by constructor unwind; invocation is EH-generated, body semantics are ordinary destruction.
- Open question: should target be non-reconstructable/no-emitter? Evidence checked: existing class declaration, generated source gap, UID00034F/UID00034I conventions. Resolution: reconstructable true with class emitter and covered marker because a human source destructor is required.
- Open question: explicit inline versus out-of-line/defaulted source spelling. Evidence checked: no independent function, no ordinary caller, template class context, retained body, compiler era/style. Resolution: inline empty virtual destructor is the least speculative complete source shape; confidence capped at 94.
- Open question: direct file or class owner? Evidence checked: concrete receiver/vtable and source-tree route. Resolution: class UID0000F9 direct; file UID0000JG ultimate route.
- Open question: `TreeStorage` versus `std::vector`. Evidence checked: layout/destructor lowering, accepted declarations, RTTI gaps, sibling specializations. Resolution: preserve project-facing TreeStorage; vector-like lowering alone cannot prove source type replacement.
- Questions remaining unresolved: only original header filename/factoring and token-level spelling. Exhaustive active/executed/archive/SpecialReports search and IDA type/symbol evidence do not recover them. They do not affect current score/C++/owner/range decisions and require original source/debug symbols to close.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Current manual rows inspected without editing: by-memory UID000157/UID000158/UID0002MX and absence of UID00034I; by-class UID0000F9/UID00005A; by-file UID0000JG; by-template UID0001WP; by-struct UID0001UJ. Validator-owned auto-generated tracker text is not supplied here.
- `by-memory/-coverage-report.md`, replace the current UID000158 row in the UID000157 child group with:

`        - [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md) : reconstructable : 92% : very strong : Retained complete-object destructor for \`Tree<FolderTreePane::TreeElem>\`; exact 25-byte range/hash, constructor-unwind state-3 liveness, vtable/storage/LObject teardown, class ownership, inline empty-destructor source cause, and compiler-glue exclusions are resolved.`

- `by-memory/-coverage-report.md`, replace the UID000157 row with:

`    - [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md) 0x004b3350-0x004b5c3f | aggregate | FolderTreePaneTreeAndSortHelpers : not reconstructable : 88% : strong : Non-emitting split index for FolderTreePane tree/sort helpers; exact children include corrected UID000158 \`[0x004b5650,0x004b5669)\` retained Tree destructor support, and alignment padding includes successor \`[0x004b5669,0x004b5670)\`.`

- `by-memory/-coverage-report.md`, replace the UID0002MX row with:

`        - [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) 0x004b56e0-0x004b575f | template destructor | FolderTreeStorageDestructor : reconstructable : 88% : very strong : TreeStorage member destructor with exact 36-byte element-name cleanup, validated free, pointer zeroing, and caller categories including UID000158 complete-object Tree destruction, constructor cleanup, and scalar wrappers.`

- `by-memory/-coverage-report.md`, insert near UID000158/UID0002MX if the supervisor maintains explicit exact-child rows:

`        - [UID:00034I][0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor](by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md) : reconstructable : 87% : very strong : Compiler-emitted scalar deleting wrapper for \`Tree<FolderTreePane::TreeElem>\`, distinct from ordinary destructor UID000158 and covered by UID0000F9 virtual destructor source semantics.`

- `by-class/-coverage-report.md`, replace UID0000F9 row with:

`- [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md) : reconstructable : 90% : very strong : Concrete \`Tree<FolderTreePane::TreeElem>\` wrapper with exact vtable/layout/method children and inline empty virtual destructor source cause for ordinary UID000158 cleanup, storage/base destruction, EH cleanup, and scalar wrapper regeneration.`

- `by-class/-coverage-report.md`, replace UID00005A row with:

`- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) : reconstructable : 88% : strong : Filesystem tree control with embedded \`Tree<FolderTreePane::TreeElem> m_tree\` at \`+0x130\`; constructor EH states and UID000158 ordinary Tree destruction confirm automatic member cleanup without handwritten ABI teardown.`

- `by-file/-coverage-report.md`, replace UID0000JG row with:

`- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) : reconstructable : 91% : strong : FolderTreePane source family with concrete Tree/TreeStorage/TreeItor support; UID000158 is class-owned by UID0000F9 and regenerated from its inline virtual destructor while compiler EH/scalar/vtable glue remains non-handwritten.`

- `by-type/by-template/-coverage-report.md`, replace UID0001WP row with:

`- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md) : reconstructable : 88% : very strong : Concrete FolderTreePane TreeStorage/Tree/TreeItor template support, including UID000158 ordinary Tree destructor semantics through UID0000F9; shared-header factoring remains likely but concrete emission stays in FolderTreePane.cpp.`

- `by-type/by-struct/-coverage-report.md`, replace UID0001UJ row with:

`- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) : reconstructable : 88% : very strong : 36-byte nested FolderTreePane TreeElem record used by TreeStorage; UID0002MX destroys each stored name while UID000158 destroys the containing Tree wrapper and automatically reaches storage cleanup.`

- Reason B agent must not apply it directly: these are manual supervisor-owned coverage reports expressly forbidden to B001. The supervisor decides exact row placement/synchronization after accepted implementation.

## Follow-Up Actions
- Supervisor actions: manual `-coverage-report.md` application and any validation/execution/count/path/move/archive decisions remain external supervisor/validator-owned state. This artifact neither asserts nor directs those outcomes.
- A-agent actions: none.
- B001 future research or implementation actions: none for UID000158. C158-001 through C158-044 are dispositioned below, scoped validation and waited generation are complete, and no accepted item is blocked.

## Confidence
- Recommendation confidence: 94/100.
- Score confidence: 96/100 for `92/94` target and 94/100 for `90/93` UID0000F9.
- Remaining uncertainty: exact original shared header and token-level explicit/defaulted destructor spelling. Binary behavior, owner, source route, range, and no-hand-port disposition are closed.

## Validator Results
- All validator commands ran from `source-3/project-documentation` with `--apply --queue-timeout 240`; final command `000000010832` additionally used `--wait-generated`. Every command exited 0 and reported `ok: 1`.

| Command ID | Timestamp (EDT) | Scoped file / purpose | Exit / ok | Recorded side effects or warnings |
| --- | --- | --- | --- | --- |
| `000000010816` | `2026-07-14T05:49:00-04:00` | renamed UID000158 target to `by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md` | `0 / 1` | Applied one path update plus target metadata/owner/reference updates; synchronized six source-path references and 15 UID links. Validator automatically updated the target link in `by-memory/-coverage-report.md`; unrelated coverage UID0003MT remained a reported missing reference. Generated refresh deferred. |
| `000000010817` | `2026-07-14T05:50:19-04:00` | `by-class/Tree_struct_FolderTreePane__TreeElem_.md` | `0 / 1` | Applied score/formal/autogen updates; generated refresh deferred. |
| `000000010818` | `2026-07-14T05:51:17-04:00` | `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md` | `0 / 1` | Accepted aggregate/history/range edits; generated refresh deferred. |
| `000000010819` | `2026-07-14T05:52:07-04:00` | `by-file/FolderTreePane.md` | `0 / 1` | Accepted class ownership/source route/history edits; generated refresh deferred. |
| `000000010820` | `2026-07-14T05:52:57-04:00` | first pass, `by-type/by-template/FolderTreePaneTreeTemplates.md` | `0 / 1` | Initial edit had compressed prior UID000346/UID000347 references; validator removed those two reference-index entries. The page remained leased and was corrected before release. |
| `000000010821` | `2026-07-14T05:53:20-04:00` | corrective final pass, `by-type/by-template/FolderTreePaneTreeTemplates.md` | `0 / 1` | Restored the prior UID000346/UID000347/UID00034H detail and added two reference-index entries; generated refresh deferred. This is the accepted final page state. |
| `000000010822` | `2026-07-14T05:54:04-04:00` | `by-type/by-struct/FolderTreePane__TreeElem.md` | `0 / 1` | Accepted containing-Tree versus per-record cleanup evidence; generated refresh deferred. |
| `000000010823` | `2026-07-14T05:54:52-04:00` | `by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md` | `0 / 1` | Accepted complete-object caller classification while preserving raw body; generated refresh deferred. |
| `000000010824` | `2026-07-14T05:55:47-04:00` | `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md` | `0 / 1` | Accepted ordinary/scalar distinction and corrected link; generated refresh deferred. |
| `000000010825` | `2026-07-14T05:56:53-04:00` | `by-class/FolderTreePane.md` | `0 / 1` | Added UID000158 reference-index entry and accepted bounded layout/lifetime evidence; generated refresh deferred. |
| `000000010826` | `2026-07-14T05:58:06-04:00` | `by-memory/-ignored.md` | `0 / 1` | Accepted successor alignment row. The scope-wide ignored page reported 314 pre-existing missing references, with ten printed and 304 suppressed; none was introduced as a UID000158 blocker. Generated refresh deferred. |
| `000000010832` | `2026-07-14T06:00:01-04:00` | final UID000158 target validation and `--wait-generated` refresh | `0 / 1` | `generated_refresh: completed` with matching command ID/timestamp. Validator-owned side effects included registry rebuild, projected stats update, seven generated coverage metadata reports, and 281 generated metadata refreshes; reported global fallback/missing-children/no-code warnings are outside this target. |

- Generated freshness: `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` has filesystem write time `2026-07-14T06:00:12.6863770-04:00`, later than command `000000010832` at `06:00:01-04:00`.
- Generated exact counts: Tree class `1`; inline `virtual ~Tree()` `1`; UID000158 `1`; UID00034I `1`; UID000157 `0`; `ResetToSingleRoot`, `TraverseContentDimensions`, `TraversePaintNodes`, `HitTestVisibleNodes`, and `FindVisibleNavigationNode` each `1`.
- Generated placement/readback: the inline destructor is inside the sole Tree class; UID000158's exact covered-by marker is immediately after the class and UID00034I follows it. Existing Tree methods remain in their established source order.
- Generated negative assertions: old `0x004b5650-0x004b5668` path/title `0`; target Empty Emitter Marker `0`; vptr/vftable assignments `0`; explicit `LObject::~LObject` call `0`; EH-cleanup wording/body `0`; UID000157 aggregate output `0`. UID00034I's one scalar-deleting-destructor comment remains as the accepted covered compiler marker, with no explicit wrapper body.
- Unresolved validator warnings/errors: none for UID000158 or any accepted ordinary destination. The unrelated UID0003MT manual-coverage reference, ignored-page scope-wide missing references, and global autogen advisory counts are recorded rather than treated as target failures.
- Lease proof: each ordinary page was leased immediately before editing, reread under lease, scoped-validated, and released before proceeding. `tools/leaser/Agents/Agent-B001/current_leases.md` reported no active B001 leases after the ordinary edits; the final waited validator and report update required no lease.
- Forbidden-command proof: B001 ran no `execute_report`, lifecycle, report probe/count/revalidation, move, or archive command and did not mutate IDA.

## Changed Files
- Renamed in place, preserving UID: `by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md` -> `by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md`.
- Modified ordinary by-* files:
  - `by-class/Tree_struct_FolderTreePane__TreeElem_.md`
  - `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`
  - `by-file/FolderTreePane.md`
  - `by-type/by-template/FolderTreePaneTreeTemplates.md`
  - `by-type/by-struct/FolderTreePane__TreeElem.md`
  - `by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md`
  - `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md`
  - `by-class/FolderTreePane.md`
  - `by-memory/-ignored.md`
- Modified report: `tools/leaser/Agents/Agent-B001/research/000158-FolderTreePaneTreeDestructorCleanup-source-quality.md`.
- Validator-owned, not manually edited by B001: `by-memory/-coverage-report.md` received the automatic renamed-link synchronization from `000000010816`; final command `000000010832` refreshed generated metadata/output, including `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`, the seven `auto-generated/-ag-*-coverage.md` metadata reports, projected `project-level/-auto-completion-stats.md`, and validator registry state. The validator reported 281 generated metadata refreshes; B001 made no manual generated/coverage/tracker/validator-state edit.
- Unchanged by decision: UID000155, UID0000FC, UID00034K, UID00036J/UID00036K, UID00034F, UID0002MW, shared Tree-file structure, IDA, supervisor/audit/lifecycle files, and all unrelated children/content.
- Report execution/move/archive: not run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: exact SHA `E0DBD728C0544D55975A057FE8AD9431A219D5CFACD72759EB8F0E70C3142DFB` passed Gate 1.
- [x] Target/support docs to update: UID000158, UID0000F9, UID000157, UID0000JG, UID0001WP, UID0001UJ, UID0002MX, UID00034I, UID00005A, and `by-memory/-ignored.md`; all ten final ordinary destinations are recorded above.
- [x] Current target state and actual evidence checked recorded: healthy evidence-time MCP session, exact bytes/hash/range, chunks, instructions, refs, EH states, sibling destructors, current docs, generated output, coverage, and path-specific historical searches.
- [x] Claim And Incorporation Ledger updated with destination and legal final verification state for every accepted claim: C158-001 through C158-044 use `applied`, `already-present`, or `excluded-with-reason`; none is blocked.
- [x] Metadata/score changes applied: UID000158 `92/94`; UID0000F9 `90/93`; other named support scores unchanged.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: all current target blockers resolved; no rare exception used.
- [x] Owner/emitter/reconstructable changes applied: UID000158 owner/emitter UID0000F9, reconstructable true, blank position, `Nested:8`; UID0000F9 continues through UID0000JG.
- [x] Split/rename/new-child changes applied: no split/new child; validator-aware in-place target rename and one-byte range correction preserved UID000158.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes applied or confirmed not applicable: class/file route, corrected range, successor ignored padding, and documentation rename are exact; no IDA mutation.
- [x] First-draft C++ or no-code proof applied: exactly two destination-specific managed blocks, with UID000158 covered-by marker and complete UID0000F9 class block.
- [x] Third-party import directive applied or confirmed not applicable: not applicable; source is project-local reconstructed C++ and no third-party path was introduced.
- [x] Exact target/support doc facts incorporated at report-level detail: the ledger, destination proof, target, support, validator, and generated sections preserve all accepted facts without deferral.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: B008/B010 EH-only lead, old range/file owner, explicit ABI glue, dead-code, storage-owner, and shared-file alternatives are all dispositioned.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: no current override; stale family assumptions independently revalidated and historicalized.
- [x] Open questions closed or documented as evidence-backed unresolved: all current blockers closed; only original header/token spelling remains bounded.
- [x] Validators run: one accepted final scoped validation per changed ordinary page, plus the recorded corrective UID0001WP pass and final UID000158 `--wait-generated` refresh.
- [x] Generated report refresh completed and explicit manual supervisor-owned coverage text retained: exact generated assertions and supervisor-owned manual coverage text are recorded without claiming manual application.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at exact Gate-1 SHA recorded above.
- [x] All accepted target/support doc details incorporated at report-level detail across the ten ordinary destinations.
- [x] Claim And Incorporation Ledger updated with a legal final verification state and separate destination proof for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly excluded with evidence-backed reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and exact IDs/timestamps/results/side effects recorded; every ordinary destination's accepted final validation is exit 0, `ok: 1`.
- [x] Generated refresh completed by validator `000000010832`; exact generated readback and unchanged supervisor-owned coverage text are recorded.
- [x] Remaining unapplied accepted items listed with exact blocker: none; no C158 claim is blocked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000010863","destination_path":"executed-b-agent-research/B001/000158-FolderTreePaneTreeDestructorCleanup-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/000158-FolderTreePaneTreeDestructorCleanup-source-quality.md","timestamp":"2026-07-14T06:19:42-04:00","uid":"000158"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
