** TARGET-REPORT-UID:0004IS **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004IS PopupMenuControlPane Select Item And Notify Parent Raw Source Quality


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0004IS] as a reconstructable, class-owned, independently emitting private `PopupMenuControlPane` method at the exact range `0x004981b0-0x0049821f`. Keep the source-facing name `SelectItemAndNotifyParent(long)` as the narrowest realistic inferred name.
- Final disposition: keep `CANONICAL_OWNER:0000AN`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000AN`; the accepted implementation callback raised the target documentation from `88/89` to `94/93` and incorporated the dedicated current evidence without changing its source route.
- Ordinary callback state: the target CPP body remains exact, target H remains blank, the complete class declaration now resides in the class H channel, class CPP contains only `[[CHILDREN]]`, and stale raw/unmodeled prose is reconciled across the target/class/file/core/setter pages. The supervisor-owned IDA function-comment refinement and manual coverage insertion are completed and recorded below; report execution/archive remains supervisor-owned and is not asserted by ordinary report prose.
- Confidence: very high for range, boundaries, behavior, ABI, class ownership, emitter route, and executable parity; high for the inferred private name and source placement. No surviving route or original symbol proves the historical lexical spelling or a UI-specific meaning for notification `12`.

## Supporting Research

- This dedicated report was independently researched from the documentation and live IDA MCP evidence available during its dated report-only pass. The older B005 UID00011F report remains historical lead material only.
- Historical MCP evidence snapshot: session `supervisor-gate2b-batch2-20260810`, canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, returned `server_health status:ok`, image base `0x400000`, Hex-Rays ready, and string cache ready. `auto_analysis_ready:false` was recorded as context while bounded IDB-backed calls succeeded. The session identifier is a dated evidence receipt, not current session authority.
- During that dated pass, the first available session identity had expired. B002 used the supervisor-provided replacement and re-ran every relied-on query there; no result from the expired identity supports a final conclusion. Any later live IDA authority must be established dynamically from the canonical loaded IDB and fresh bounded readback rather than inferred from either historical session name.
- This report is lifecycle-neutral. Its execution/archive state is authoritative only from its physical current path plus validator-owned lifecycle status/history metadata read at the time of use; the report body does not bind authority to a `research` or archive location.
- Historical gate/callback receipt: Supervisor Gate 1 passed report-only artifact SHA256 `32CC6BC36C4BD6EC6A970C57109814719930060AB3EF4E3935A9C9DE80DBAE92` at `33/33`, after which B002 received and completed the accepted ordinary implementation callback recorded below.

## Target

- Target UID: `[UID:0004IS]`.
- Additional target UIDs: none.
- Declared-target inventory: one exact by-memory method, `by-memory/0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md`.
- Source queue at assignment time: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; the historical pre-callback row was `88/89`, effective score `88.5`, with no direct/additional report coverage before this report. The current implemented target score is `94/93`.
- Current supervisor classification: reconstructable source-authored private class method requiring a dedicated source-quality report.
- Current scores and parent state: target `94/93`, owner/emitter [UID:0000AN] `PopupMenuControlPane`; exact split parent [UID:00011F] `PopupMenuControlPaneCore`; source root [UID:0000MN] `PopupMenuControls`.

## Current Target State

- Current metadata after callback: `COMPLETION:94`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000AN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AN`, blank optional position.
- Current CPP remains exact: `void PopupMenuControlPane::SelectItemAndNotifyParent(long index)` caches `GetParent()`, calls `SetSelectedIndex(index)`, finds the control in the cached parent, and sends literal notification `12` when the index is not `-1`.
- Current target H remains blank. The private declaration now appears in [UID:0000AN]'s formal H channel; that class page's CPP channel contains only `[[CHILDREN]]`.
- Resolved documentation defects: the target/class/file/core pages now make the current modeled `0x6f` function authoritative while retaining historical raw/unmodeled discovery state, and the setter records the exact source-call/optimized-inline relationship. Original lexical spelling, code-12 enum meaning, live route, and historical physical file split remain explicit confidence caps rather than uninvestigated blockers.
- Historical callback-generated receipt: command `000000021722` at `2026-08-10T12:41:03-04:00` produced `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` with the target definition exactly once at line 216 and no PopupMenuControlPane class declaration, and `PopupMenuControls.h` with the class exactly once at line 90 and its private declaration exactly once. Later validator activity advanced the generated headers beyond that command identity. Current generated authority is the command/timestamp physically present in the generated headers at read time; the later supervisor closure verified the same one-definition/one-declaration route without treating `000000021722` as current authority.
- Related docs checked: UID0000AN class, UID0000MN file, UID00011F split parent, UID0004IT setter, UID000459 FolderSelect handler, UID0003MD MusicControl handler, UID0001JB TerminalPane/Setup aggregate, UID0001KG UserInfoDialogPane aggregate, DialogPane class/helper docs, current generated CPP/H, generated tracker/coverage, and manual by-memory/class/file coverage rows.

## Executive Recommendation

- Direct owner: [UID:0000AN] `PopupMenuControlPane`. The receiver fields `+0x10c`, inherited bounds `+0x44`, parent lookup, and neighboring class-method run are conclusive.
- Source root: [UID:0000MN] `NexusTK/ui/menu/PopupMenuControls.cpp` with declaration in `PopupMenuControls.h`. No evidence supports a feature-dialog owner or a separate raw-helper file.
- Source representation: one ordinary private class method definition in the target CPP block, one private declaration owned by the class H block, and no standalone target H fragment.
- Reachability disposition: retain the method as source-authored but currently unreferenced. Zero incoming route is a liveness/name confidence cap, not a reason to classify 111 coherent class-method bytes as padding, compiler glue, or no-code evidence.
- Code `10` is the ordinary selection-change notification. Code `12` is only proven as a separate parent notification after control-index lookup. The report deliberately does not rename it to close, commit, accept, or dismiss semantics.

## Supervisor Active Recheck

- Historical initial assignment: UID0004IS required a new report-only investigation with mandatory live MCP evidence, no by-* edits before Gate 1, no executable report content, and no report lifecycle commands. That report-only phase and the accepted ordinary implementation callback are complete.
- No split repair is required. The exact `0x6f` body is already isolated from nine predecessor `0xcc` bytes and one successor `0xcc` byte.
- The only source-routing defect exposed by that recheck was the support-class channel placement: the accepted callback moved the class declaration into [UID:0000AN]'s H channel and retained only `[[CHILDREN]]` in its CPP channel.
- Every source-bearing item in the target range has a disposition: the entire 111-byte interval is one method; there is no internal padding, data, child, EH subrange, or compiler-only island.
- Current closure phase: ordinary documentation, manual coverage, supervisor IDA comment application/protected-state readback, one-save persistence, and fresh post-save-copy verification are complete. The report is ready for supervisor execution review, while execution/archive authority remains dynamic and supervisor-owned.

## Inference Research Guidance Check

- Direct IDA facts are addresses, bytes, function model/size, CFG, stack frame, calls, constants, xrefs, current types/comments, and consumer parameter use.
- Documentation evidence supplies the UID graph, class/file route, accepted field names, callback type, formal source, and historical pre-curation state.
- Inference supplies the realistic source name, private access, retained-unused explanation, and consolidated physical source-file choice. These are labeled inferred rather than original-symbol facts.
- The current evidence supports human-written mid-2000s C++ using a source-level setter call. It does not support copying the decompiler's expanded virtual calls, `v3` temporaries, or IDA `int` spelling into final source.
- No Wave2/Wave3 source or workflow was used. Any stale references encountered in historical material were ignored.

## Heuristic / Inference Reanalysis And Validation

1. **Raw versus modeled state.** Historical B005 evidence correctly recorded a raw, unmodeled body. Current MCP now returns a function object named `PopupMenuControlPane_SelectItemAndNotifyParent`, exact size `0x6f`. The page must preserve the historical state while making the current curated state authoritative.
2. **Liveness.** Current `xrefs_to`, separate code/data `xref_query`, and whole-image little-endian VA/RVA byte searches all return zero routes to `0x4981b0`. Constructor callback evidence targets `0x498220`, not this body. The method is source-shaped, exactly fenced, unique-signatured, and class-local, so the best explanation is an authored unused member retained with the linked translation unit. Exact linker/compiler retention settings are not recoverable and are not required for source representation.
3. **Name.** `SelectItemAndNotifyParent` describes only proved behavior. `SetSelectedIndexAndNotifyParent` is plausible but overstates that a state change always occurs; `ClosePopup`, `CommitSelection`, `AcceptSelection`, and `DismissMenu` assign unsupported meaning to code `12`. Keep the existing descriptive name.
4. **Signature.** `retn 4`, ECX receiver use, one four-byte argument, and void return prove `__thiscall` with one 32-bit index. The constructor's decorated callback type proves the sibling selection API uses `long`; 32-bit MSVC `long` and IDA's current `int` are ABI-equivalent. Source remains `void SelectItemAndNotifyParent(long index)`.
5. **Code 10.** The first branch exactly duplicates the active setter's no-change/`-1` rejection, store, invalidation, second parent lookup, control-index lookup, and `OnControlCommand(..., 10)`. FolderSelectDialog directly consumes `(controlIndex == 0 && notifyCode == 10)` as drive-selection change.
6. **Code 12.** The second notification is unconditional with respect to selection change but conditional on the cached original parent's control lookup returning non-`-1`. FolderSelect has no code-12 branch; MusicControl uses only `controlIndex`; TerminalSetup and UserInfo handlers also ignore their notification argument. Literal `12` is exact; stronger UI semantics are not.
7. **Parent behavior.** The body intentionally caches the original parent before the setter flow and uses that object for code `12`, even though the inlined setter obtains the parent again for code `10`. The source-level call preserves this distinction.
8. **Null behavior.** The final cached-parent lookup has no null guard. Adding one would change failure behavior. Existing source preserves the parent invariant and exact null-crash possibility.
9. **Source channels.** The method definition is target-owned CPP. The declaration is class-owned H. Keeping the declaration in generated CPP contradicts current channel rules and the file page's own header contract, so the class formal channels require a support repair.

## Evidence Standards Used

- Primary evidence: live IDA MCP `server_health`, `lookup_funcs`, `disasm`, `decompile`, `basic_blocks`, `stack_frame`, `callees`, `xrefs_to`, `xref_query`, `find_bytes`, `get_bytes`, `get_comments`, `type_inspect`, and signature generation.
- Corroboration: current by-* metadata/prose/formal source, generated CPP/H physical readback, current tracker/generated coverage, manual coverage reports, and one matching historical executed B report.
- Negative evidence was treated narrowly. The timed-out earlier broad instruction scan is excluded; only successful bounded xref/pointer/callback/vtable-equivalent checks support the no-route conclusion.
- Evidence ladder: exact bytes and control flow establish behavior; callback and consumer facts establish source types/notification roles; class layout and source graph establish ownership; naming/access/file placement remain explicit inference.

## Evidence Checked

- Historical MCP health receipt: replacement session `supervisor-gate2b-batch2-20260810` returned `status:ok` during the report-only pass and bounded calls continued successfully. This dated identity is evidence provenance, not a claim about the current live session.
- Function/body: lookup, 49-instruction disassembly, 7-block CFG, decompilation, stack frame, callees, exact 111-byte read, SHA256, and unique entry signature.
- Reachability: incoming xrefs, separate code/data xref queries, VA bytes `B0 81 49 00`, RVA bytes `B0 81 09 00`, constructor callback target, setter xrefs, and current vtable/data-route absence.
- Dependencies/consumers: constructor `0x498040`, setter `0x498220`, `DialogPane_FindControlIndex` `0x49dd20`, FolderSelect handler `0x4b1920`, MusicControl handler `0x529790`, TerminalSetup handler `0x58c240`, and UserInfo handler `0x59b000`.
- Type/comment evidence checked during research: `PopupMenuControlPane` and `DialogPane` UDTs, target/setter frames, all four target comment channels, and target/setter function names/sizes. Supervisor Gate 2B later persisted the accepted replacement function-regular comment and verified the other three comment channels plus name/range/frame unchanged.
- Documentation: target, class, file, split parent, setter, four consumer families, DialogPane support, `by-structure.md`, generated source/header, tracker/generated coverage, manual coverage rows, and IDA recommendation implementation catalog.
- Historical-report search terms: `0004IS`, `0x004981b0`, `SelectItemAndNotifyParent`, `PopupMenuControlPane`, `code 12`, and `PopupMenuControls`. The only matching report was executed B005 UID00011F.
- Historical report-only phase intentionally skipped IDA mutation/save, validators, by-* edits, generated refresh, manual coverage edits, report execution, and lifecycle commands. The accepted callback subsequently completed the B002-owned ordinary edits, scoped validators, and generated readback. Supervisor closure then completed the manual coverage insertion and the bounded IDA comment/save/reopen work recorded below. Report execution/archive remains supervisor-owned and is not claimed here.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination | Action | Actor | State |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| C0004IS-001 | 0004IS | Record exact `0x4981b0-0x49821f` identity, 111 bytes, SHA256 `6DC833EECFD6DDF74E589850D46D0ADA9D992DAD5588742A3C67CC219C3255C7`, 49 instructions, 7 blocks, and `0xcc` fences. | Very high | live bytes/disasm/CFG | target `Exact Binary Contract` | incorporate | B002 | [x] |
| C0004IS-002 | 0004IS | Replace stale current raw/unmodeled state with current modeled function `PopupMenuControlPane_SelectItemAndNotifyParent`, size `0x6f`, while preserving historical pre-curation state. | Very high | lookup/catalog/history | target `Current IDA State` | incorporate | B002 | [x] |
| C0004IS-003 | 0004IS | Preserve zero incoming code/data xrefs, zero VA/RVA pointer hits, no vtable/data slot, and setter-only constructor callback evidence. | Very high | xrefs/find_bytes/constructor | target `Retained Liveness And Reachability` | incorporate | B002 | [x] |
| C0004IS-004 | 0004IS | Classify the exact fenced coherent body as source-authored retained unused code, not padding, compiler glue, or no-code coverage. | High | body/fields/calls/fences | target `Retained Liveness And Reachability` | incorporate | B002 | [x] |
| C0004IS-005 | 0004IS | Preserve inferred private source signature `void SelectItemAndNotifyParent(long index)` and reject stronger unsupported names. | High | ABI/callback/name analysis | target `Name And Signature` | incorporate | B002 | [x] |
| C0004IS-006 | 0004IS | Document cached-original-parent flow, conditional selection update, second parent lookup inside setter flow, and independent code-12 lookup. | Very high | disasm/decompile | target `Exact State And Call Flow` | incorporate | B002 | [x] |
| C0004IS-007 | 0004IS | Document code 10 as the ordinary selection-change notification and exact inlined `SetSelectedIndex` path. | Very high | target/setter/Folder handler | target `Notification Semantics` | incorporate | B002 | [x] |
| C0004IS-008 | 0004IS | Preserve code 12 literally as a separate parent notification; record that known parents do not prove close/commit/dismiss meaning. | High | four parent handlers | target `Notification Semantics` | incorporate | B002 | [x] |
| C0004IS-009 | 0004IS | Preserve the existing target CPP body as execution-equivalent, human source-shaped formal code. | Very high | line-by-line parity audit | target CPP block | preserve | B002 | [x] |
| C0004IS-010 | 0004IS | Keep the target H block blank because the declaration belongs to class UID0000AN. | Very high | channel ownership rules | target H block | preserve | B002 | [x] |
| C0004IS-011 | 0004IS | Raise target `88/89` to `94/93` and replace the Item Summary with the dedicated current finding. | High | complete dedicated audit | target metadata/header | replace | B002 | [x] |
| C0004IS-012 | 0004IS | Add exact binary, state-flow, consumer-matrix, source-parity, and no-null-guard evidence at report-level detail. | Very high | complete evidence pass | target body sections | incorporate | B002 | [x] |
| C0004IS-013 | 0004IS | Preserve historical raw state and rejected alternatives as explicitly superseded/rejected evidence. | High | historical report/current MCP | target history/rejections | incorporate | B002 | [x] |
| C0004IS-014 | 0004IS | Replace class prose claiming UID0004IS remains raw with current modeled/no-route evidence and refined notification semantics. | Very high | current MCP | class UID0000AN evidence notes | replace | B002 | [x] |
| C0004IS-015 | 0004IS | Move the complete PopupMenuControlPane declaration from class CPP to class H, add `../core/ControlPane.h`, and leave only `[[CHILDREN]]` in class CPP. | High | channel rules/generated readback | class UID0000AN formal CPP/H | move declaration channel | B002 | [x] |
| C0004IS-016 | 0004IS | Replace file prose claiming no function at UID0004IS and reconcile the physical header/source contract after class-channel repair. | Very high | current MCP/generated readback | file UID0000MN UID00011F section | replace | B002 | [x] |
| C0004IS-017 | 0004IS | Replace split-parent stale unmodeled/no-route prose with current modeled/no-route and exact body evidence. | Very high | current MCP | core UID00011F evidence notes | replace | B002 | [x] |
| C0004IS-018 | 0004IS | Add the exact source-level call-through relationship to the setter without changing setter metadata or CPP. | Very high | target/setter parity | setter UID0004IT behavior notes | incorporate | B002 | [x] |
| C0004IS-019 | 0004IS | Verify Folder/Music/Terminal/UserInfo consumer docs remain support evidence and require no metadata/formal-source change. | High | live handler decomp/docs | four consumer support pages | verify already present | B002 | [x] |
| C0004IS-020 | 0004IS | Insert the missing exact UID0004IS manual by-memory coverage row after UID0004IN. | High | manual report comparison | by-memory manual coverage | insert | Supervisor | [x] |
| C0004IS-021 | 0004IS | Replace only the target regular function comment with the exact refined behavior/no-route wording. | High | current pre-state/current evidence | IDA `0x4981b0` function comment | apply | Supervisor | [x] |
| C0004IS-022 | 0004IS | Protect current function boundary, name, ABI-equivalent IDA `int` type, complete frame, and three non-function comment channels from change. | Very high | lookup/frame/comments | IDA `0x4981b0` protected state | protect | Supervisor | [x] |
| C0004IS-023 | 0004IS | Run scoped target validation with generated refresh disabled after callback edits. | High | validator plan | target validator receipt | validate | B002 | [x] |
| C0004IS-024 | 0004IS | Run scoped class validation with generated refresh disabled after callback edits. | High | validator plan | class validator receipt | validate | B002 | [x] |
| C0004IS-025 | 0004IS | Run scoped file validation with generated refresh disabled after callback edits. | High | validator plan | file validator receipt | validate | B002 | [x] |
| C0004IS-026 | 0004IS | Run scoped split-parent and setter validation with generated refresh disabled after callback edits. | High | validator plan | core/setter validator receipts | validate | B002 | [x] |
| C0004IS-027 | 0004IS | After accepted implementation and coherent refresh, verify one target definition in CPP and the class declaration in H rather than CPP. | High | generated-source contract | generated PopupMenuControls CPP/H | read back | B002 | [x] |
| C0004IS-028 | 0004IS | Preserve the lifecycle guard requiring Gate 2A documentation verification and Gate 2B IDA closure before execution/archive; both gates pass, but execution is not claimed. | Very high | lifecycle rules | validator-owned report lifecycle | lifecycle guard verified; execution remains supervisor-owned | Supervisor | [x] |

## Positive Evidence Summary

- The current function model exactly spans the documented range and contains one coherent `__thiscall` method with a one-argument `retn 4` epilogue.
- The body uses only PopupMenuControlPane state/API, inherited bounds, and DialogPane parent notification APIs. Its placement is inside the contiguous popup class run.
- Exact bytes are fenced by alignment and hash to `6DC833EECFD6DDF74E589850D46D0ADA9D992DAD5588742A3C67CC219C3255C7`.
- The first branch is instruction-for-instruction equivalent to optimized/inlined `SetSelectedIndex(long)` behavior.
- The constructor independently proves the sibling selection API's member-function argument is `long` and targets `0x498220`, cleanly separating this retained method from the active callback.
- The existing human-shaped CPP preserves every observable branch/order/null behavior without importing decompiler artifacts.

## IDA MCP Facts

- `lookup_funcs(0x4981b0)`: `PopupMenuControlPane_SelectItemAndNotifyParent`, size `0x6f`.
- Adjacent modeled entries: getter `0x4981a0-0x4981a7`, target `0x4981b0-0x49821f`, setter `0x498220-0x49826d`.
- Exact target: 49 instructions, 7 basic blocks, void return, arguments `this: PopupMenuControlPane *`, `index: int`, `retn 4`.
- Frame rows: saved registers `+0x8`, return address `+0xc`, `index` `+0x10`, each four bytes; no stable local stack row.
- Callee inventory records `DialogPane_FindControlIndex` twice; virtual calls resolve parent lookup, invalidation, and `OnControlCommand` slots.
- Current UDT: `PopupMenuControlPane` size `0x114`, base bytes `0x108`, `m_menuPane +0x108`, `m_selectedIndex +0x10c`, `m_parentDialog +0x110`.
- Current persisted/reopened comment post-state after Supervisor Gate 2B: address regular absent; address repeatable absent; function regular is `Retained private PopupMenuControlPane method: caches the original parent, conditionally performs the normal SetSelectedIndex(long) path and code-10 selection notification, then independently sends literal notification 12 when the original parent's control index is valid; no surviving inbound route proves a stronger semantic name.`; function repeatable absent. The earlier function-regular text `Retained source-shaped helper that applies selection and notifies the original parent with command 12. SelectItemAndNotifyParent is descriptive because no direct declaration or live route survives.` is historical prestate only.
- Unique relocatable entry signature: `55 8B EC 53 57 8B F9 8B 07`.
- Incoming route facts: zero xrefs, zero separate code/data xrefs, zero VA/RVA pointer-pattern hits.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004981a7-0x004981b0` | alignment in UID00011F | nine `0xcc` predecessor bytes | false as source | UID00011F | n/a | excluded boundary evidence |
| `0x004981b0-0x0049821f` | UID0004IS target | private retained selection plus parent-notify method | true | UID0000AN | `88/89 -> 94/93` | standalone CPP method |
| `0x0049821f-0x00498220` | alignment in UID00011F | one `0xcc` successor byte | false as source | UID00011F | n/a | excluded boundary evidence |
| `0x00498220-0x0049826d` | UID0004IT support | active selection setter and constructor callback target | true | UID0000AN | `91/92`, unchanged | separate sibling method |

The target has no internal child, padding, data, EH range, thunk, or split. Its declaration is class-owned H source; its definition is target-owned CPP source.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004981b0` | zero incoming code/data xrefs | no surviving direct caller |
| `0x004981b0` | zero `B0 81 49 00` VA and `B0 81 09 00` RVA hits | no surviving raw pointer/vtable/callback route |
| `0x004981b9`, `0x004981e3` | virtual `GetParent()` | caches original parent, then repeats parent lookup inside selection update |
| `0x004981dc` | virtual invalidation through slot `+0x20` | invalidates inherited bounds after changing selection |
| `0x004981f5`, `0x00498205` | `DialogPane_FindControlIndex` | first lookup supports code 10; second uses original cached parent for code 12 |
| `0x004981fe` | virtual command with literal `10` | ordinary selection-change notification |
| `0x00498216` | virtual command with literal `12` | separate parent notification, stronger meaning unproved |
| `0x004980c2` | constructor data xref to `0x00498220` | active callback is setter, not target |
| `0x00498220` | 16 code xrefs plus constructor data xref | sibling setter is live and reused by source-level target representation |

## Documentation Evidence And IDA Status

- Target behavior, owner/emitter, score `94/93`, exact CPP, and blank target H are current. Former raw/unmodeled statements are retained only as historical discovery evidence; current prose records the modeled/no-route state.
- The class method map uses the best inferred name/signature, its complete declaration now resides in the formal H channel, and its CPP channel retains only `[[CHILDREN]]`; the former raw/no-route claim is reconciled to modeled/no-route.
- The source-file and split-parent pages preserve ownership/boundaries and now record the current modeled function/body/no-route evidence rather than stale unmodeled wording.
- The setter page proves callback type `void (PopupMenuControlPane::*)(long)`, active xrefs, and code-10 behavior, and now records UID0004IS's source-level call-through versus optimized inline bytes.
- Historical callback generation first proved one correct target body in CPP and exposed the missing class declaration in H. The accepted class-channel repair and later supervisor closure verified the corrected route: target definition in CPP, complete class declaration in H, and no duplicate class declaration in CPP.
- Historical assignment-time tracker state listed UID0004IS as uncovered while generated memory coverage already routed code through UID0000AN. Current manual coverage now includes the exact UID0004IS row recorded below; generated/tracker current authority remains tool-owned and is read from physical current artifacts rather than this dated snapshot.

## Ranked Ownership Analysis

### 1. PopupMenuControlPane class UID0000AN

- Evidence for: exact receiver fields, inherited bounds use, surrounding class-method run, class UDT, parent API, sibling setter parity, existing declaration, and valid emitter chain.
- Evidence against: no surviving caller and no original lexical symbol.
- Decision: direct semantic owner and emitter; confidence very high.

### 2. PopupMenuControls file UID0000MN

- Evidence for: accepted consolidated popup/menu source family, generated route, class/file docs, and neighboring methods.
- Evidence against: an original narrower `PopupMenuControlPane.cpp` physical split cannot be excluded.
- Decision: retain as current source root. Physical split uncertainty has no current behavior or emitter impact.

### 3. Feature-dialog consumers

- Evidence for: FolderSelect, MusicControl, TerminalSetup, and UserInfo instantiate/use popup controls.
- Evidence against: none calls the target; all are consumers of generic popup methods. Code 12 has no feature-specific consumer.
- Decision: reject caller-feature ownership.

### Proposed new file/grouping, if applicable

- Not applicable. A raw-island file would be a reverse-engineering artifact and would duplicate a class-owned method.

## Source Placement

- Recommended placement: declaration in `NexusTK/ui/menu/PopupMenuControls.h` through class UID0000AN; definition in `NexusTK/ui/menu/PopupMenuControls.cpp` through target UID0004IS -> class UID0000AN -> file UID0000MN.
- This placement preserves the existing reusable popup class family and source-level setter relationship.
- Rejected: FolderSelectDialog.cpp, MusicControlDialog.cpp, TerminalPane.cpp, UserInfoDialogPane.cpp, FunctionObjects.cpp, direct free-function ownership, and a generated-name/raw-helper source file.
- Remaining uncertainty: the historical project may have used a narrower `PopupMenuControlPane.cpp`; no current source artifact justifies changing the established consolidated root.

## Range / Split / Padding / Reclassification Analysis

- Exact body range: `[0x004981b0,0x0049821f)`, 111 bytes.
- Predecessor fence: nine `0xcc` bytes `[0x004981a7,0x004981b0)` after `GetSelectedIndex`.
- Successor fence: one `0xcc` byte `[0x0049821f,0x00498220)` before `SetSelectedIndex`.
- The body has one entry, one `retn 4`, seven coherent CFG blocks, no embedded data, and no child boundary.
- No split, merge, range change, title/path rename, or reconstructable reclassification is warranted. `Raw` in the page filename is historical discovery provenance, not current IDA-state truth.

## Negative Evidence Summary

- No incoming code xref, data xref, VA pointer, RVA pointer, constructor binding, vtable slot, or callback route targets `0x4981b0`.
- The active member callback and all ordinary selection callers target `0x498220`.
- FolderSelect handles code 10 but not 12. MusicControl ignores `notifyCode` and switches on control index. TerminalSetup and UserInfo also leave their second notification argument unused.
- No evidence proves code 12 means close, accept, commit, dismiss, or menu hide.
- No evidence supports changing owner to a consumer, merging with the setter, emitting a free function, or omitting the source body.
- The excluded broad instruction scan timed out and is not used as evidence.

## IDA Rename / Type / Comment Recommendations

| Action ID | Address/entity | Historical pre-state | Accepted action / disposition | Evidence/safety constraints | Applied/saved/reopened post-state | Classification |
| --- | --- | --- | --- | --- | --- | --- |
| I0004IS-01 | `0x004981b0`, modeled function | Name `PopupMenuControlPane_SelectItemAndNotifyParent`; type `void __thiscall PopupMenuControlPane_SelectItemAndNotifyParent(PopupMenuControlPane *this, int index)`; range `0x004981b0-0x0049821f` (`0x6f`); frame: saved registers `+0x8/_DWORD`, return address `+0xc/_UNKNOWN *`, `index +0x10/int`, all width 4; address regular absent; address repeatable absent; function regular `Retained source-shaped helper that applies selection and notifies the original parent with command 12. SelectItemAndNotifyParent is descriptive because no direct declaration or live route survives.`; function repeatable absent. | The accepted historical action used the dedicated function-regular-comment operation available at application time for `addr=0x4981b0` and exact comment `Retained private PopupMenuControlPane method: caches the original parent, conditionally performs the normal SetSelectedIndex(long) path and code-10 selection notification, then independently sends literal notification 12 when the original parent's control index is valid; no surviving inbound route proves a stronger semantic name.` | Change only the regular function-comment channel. Do not rename, retype, redefine, resize, refresh decompiler state as a mutation, or alter address regular/repeatable or function repeatable comments. | Applied, saved once, and verified from a fresh post-save copy: same name, exact type, `0x6f` range, complete three-row frame, address regular absent, address repeatable absent, function repeatable absent, and function regular equal to the accepted text exactly. Post-save IDB SHA256 `4094292D7768A5DDF1BBDE721E5436D4FC4AE9F8B7EF7AE580A44FF48E6173A8`; catalog entry `0415`. | `APPLIED_VERIFIED_AND_SAVED`. |
| I0004IS-02 | `0x004981b0`, name/type/frame/protected comments | Historical prestate was the same name, exact `0x6f` range, type and complete three-row frame recorded in I0004IS-01; address regular, address repeatable, and function repeatable were absent. | No rename, type, boundary, frame, or protected-comment mutation. Keep IDA `int index`; source `long` is separately justified by callback type and 32-bit ABI equivalence. | The descriptive IDA name remains the best supported label. A type edit provides no ABI gain and may canonicalize back to `int`; all frame rows and the three protected comment channels must remain unchanged. | Fresh post-save-copy readback preserved name `PopupMenuControlPane_SelectItemAndNotifyParent`, exact range `0x004981b0-0x0049821f`, type `void __thiscall PopupMenuControlPane_SelectItemAndNotifyParent(PopupMenuControlPane *this, int index)`, saved registers `+0x8/_DWORD`, return address `+0xc/_UNKNOWN *`, `index +0x10/int`, and all three protected comment channels absent. | `NO_CHANGE_VERIFIED`. |

No other dependency needs an IDA action for this target. The setter, constructor, DialogPane helper, UDT members, and parent handlers are evidence dependencies only.

### Supervisor Gate 2B Receipt

- C0004IS-021 is `APPLIED_VERIFIED_AND_SAVED`: the exact accepted function-regular comment now persists at modeled function `0x004981b0`.
- C0004IS-022 is `NO_CHANGE_VERIFIED`: function name `PopupMenuControlPane_SelectItemAndNotifyParent`, exact `0x6f` range, the complete three-row frame, address regular/repeatable comment channels, and function-repeatable comment channel remained exact.
- Persistence/readback: prehash `E42D7752...45F1E`; backup `NexusTK.exe.uid0004IS-prechange-20260810-132813.i64`; exactly one save; posthash `4094292D7768A5DDF1BBDE721E5436D4FC4AE9F8B7EF7AE580A44FF48E6173A8`; fresh post-save-copy readback passed. The supervisor recorded catalog entry `0415`.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Owner/emitter route is valid and existing combined score already clears the source gate.
- CPP block disposition: preserve this exact formal target insertion text:

```text
void PopupMenuControlPane::SelectItemAndNotifyParent(long index)
{
    DialogPane *parentDialog = static_cast<DialogPane *>(GetParent());

    SetSelectedIndex(index);

    const int controlIndex = parentDialog->FindControlIndex(this);
    if (controlIndex != -1)
        parentDialog->OnControlCommand(controlIndex, 12);
}
```

- H block disposition: keep UID0004IS H blank. The declaration belongs in the class UID0000AN H block, not this method-range page.
- Exact behavior: the cached parent precedes the setter call; optimized setter inlining yields the observed conditional code-10 path; the final lookup uses the original parent; no null guard is introduced; notification 12 is conditional only on control index.
- Source shape: ordinary private member call-through is more plausible developer source than manually expanded vtable calls and compiler temporaries.
- Naming style: existing `PopupMenuControlPane`, `SetSelectedIndex`, `parentDialog`, and `controlIndex` conventions are retained.
- Third-party import: not applicable.

## Final Recommendation

- Target: the implemented current state keeps owner/emitter/reconstructable metadata, retains the exact CPP and blank target H, records score `94/93`, and contains the expanded current evidence.
- Class support: stale model prose is reconciled, the complete declaration is in H, and CPP retains the child route only.
- File/core support: stale raw/unmodeled wording is reconciled and the physical header/source contract is documented.
- Setter support: the exact source-level call-through parity note is present; score and formal code remain unchanged.
- Consumer support: read-only verification found no required edits; their current source remains separate.
- IDA: I0004IS-01 is applied, verified, saved, and reopened with the exact replacement function-regular comment; I0004IS-02 is no-change verified with name/range/type/frame and three protected comment channels unchanged.
- No-owner/non-emitting items: none. No split/new child/rename is recommended.
- Future work outside scope: an original source archive or symbol-bearing build could refine lexical name/access/file split, but current final source must use the best inferred human name rather than an IDA label.

## Recommended Target Doc Changes

- The following exact change specification is retained as historical accepted callback text; it is implemented in the current target and is not a future instruction.
- Path: `by-memory/0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md`.
- Metadata: `COMPLETION:94`, `CONFIDENCE:93`; all ownership/emitter/reconstructable fields unchanged.
- Item Summary replacement: `Exact 111-byte source-authored PopupMenuControlPane private selection helper: caches the original parent, source-level calls SetSelectedIndex(long) matching the inlined code-10 path, then independently sends literal notification 12 when the original parent's control index is valid; current IDA models the function, while zero surviving direct or pointer routes cap lexical-name and liveness confidence.`
- Preserve formal CPP exactly; preserve blank formal H.
- Add sections/facts for exact hash/signature/instruction/CFG/frame/UDT/fences, current IDA function/comment state, exhaustive reachability, exact state/call flow, parent consumer matrix, source parity, null behavior, retained-source inference, and rejected names.
- Replace `IDA did not model` as current truth with current modeled state and label session `bf5519ae` as historical pre-curation evidence.
- Preserve the current filename/title and explain `Raw` as historical discovery provenance.

## Recommended Support Doc Changes

- The following exact support specification is retained as historical accepted callback text; its B002-owned changes are implemented and physically recorded below.
- `by-class/PopupMenuControlPane.md` [UID0000AN]: replace line 103's current claim that UID0004IS remains raw with the current modeled name/size/no-route state; refine method-map/evidence prose to record code-10 source-level setter call-through, independent literal code 12, and no semantic consumer.
- UID0000AN formal channels after callback:

```text
RECONSTRUCTION_CPP CODE:
[[CHILDREN]]

RECONSTRUCTION_H CODE:
#include "../core/ControlPane.h"

struct PaneMouseEvent;
struct PaneKeyEvent;
struct RectBounds;
class DialogPane;
class MenuItem;
class MenuPane;

class PopupMenuControlPane : public ControlPane
{
public:
    PopupMenuControlPane(DialogPane *parentDialog, const RectBounds *bounds);
    virtual ~PopupMenuControlPane();

    void AppendItem(MenuItem *item);
    MenuItem *GetItem(int index) const;
    int GetItemCount() const;
    long GetSelectedIndex() const;
    void SetSelectedIndex(long index);

protected:
    virtual void OnDraw();
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool OnKeyDown(const PaneKeyEvent *event);
    virtual int GetControlType();

private:
    void SelectItemAndNotifyParent(long index);

    MenuPane *m_menuPane;
    long m_selectedIndex;
    DialogPane *m_parentDialog;
};
```

- `by-file/PopupMenuControls.md` [UID0000MN]: replace UID0004IS raw/no-function wording with current modeled/no-route wording; record that UID0000AN now physically fulfills the stated H/CPP contract. Scores stay unchanged because this is not a whole-file final audit.
- `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md` [UID00011F]: update child row/evidence notes from raw/unmodeled to retained/private and current modeled/no-route; preserve exact range/index disposition.
- `by-memory/0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex.md` [UID0004IT]: add that UID0004IS source-level calls this setter and current optimized bytes inline its complete update/code-10 path; no metadata or CPP change.
- UID000459, UID0003MD, UID0001JB, and UID0001KG: no edits. Their current bodies/notes already preserve the consumer facts needed by this target; no target-specific metadata/formal source belongs there.

## Score And Metadata Recommendation

- Current implemented target: `94/93`, owner `0000AN`, reconstructable true, emitter `0000AN`, CPP present, H blank.
- Implemented score transition: historical pre-callback `88/89` to current `94/93`; ownership/emitter/reconstructable/position/CPP/H dispositions remained unchanged.
- Reason higher: dedicated current function model, exact full-body hash, unique signature, complete CFG/frame/type/current comments, exhaustive route negatives, live constructor/setter separation, four-parent consumer audit, line-by-line source parity, and current generated-route review are now documented.
- Reason not `95+`: no original symbol/declaration proves lexical spelling or access; no surviving caller proves live use; no consumer proves a source enum/name or UI-specific meaning for code 12; exact original physical file split remains inferred. These do not block behaviorally exact source but remain real final-audit confidence limits.
- Reason not lower: every instruction, boundary, state transition, call ordering, source owner, emitter route, source signature, and no-route fact is independently current and reproducible.
- Support scores: keep UID0000AN `90/92`, UID0000MN `88/88`, UID00011F current values, and UID0004IT `91/92`; this report does not final-audit those broader items.

## Open Questions With Attempted Resolution

1. **Original method spelling/access.** Checked current name/type/frame/comments, all routes, class maps, historical report, and sibling naming. No symbol survives. Best resolution is inferred private `SelectItemAndNotifyParent(long)`: realistic, behavior-bounded, and better than raw/IDA names. This is the confidence cap, not deferred investigation.
2. **Meaning of code 12.** Checked all four known parent handler families. FolderSelect handles only code 10; the other three do not use the notification parameter. Best resolution is a literal separate parent notification with no stronger UI label. Source preserves `12`.
3. **Why unused code remains.** Checked exact fences/signature/body, incoming routes, callback/vtable state, surrounding linked methods, and source family. Best resolution is retained source-authored unused member code from the linked translation unit. Exact build-option mechanics are unavailable and do not affect emitted source.
4. **`int` versus `long`.** Checked target frame and constructor callback decorated type. Both are four-byte ABI values; source-family evidence selects `long`, while IDA may retain canonical `int`. No behavior uncertainty remains.
5. **Physical source file.** Checked file/class graph and generated route. Current consolidated PopupMenuControls root is best supported; a narrower historical file remains possible but has no present routing or code impact.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical pre-callback inspection of `by-memory/-coverage-report.md`: parent UID00011F and sibling UID0004IN existed, but UID0004IS had no row.
- The accepted insertion text immediately after the UID0004IN row was:

```text
    - [UID:0004IS][0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw](by-memory/0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md) 0x004981b0-0x0049821f | retained private class method | PopupMenuControlPaneSelectItemAndNotifyParentRaw : reconstructable : 94% : very-strong : Exact 111-byte PopupMenuControlPane helper caches the original parent, performs the normal SetSelectedIndex(long) code-10 path, then independently sends literal notification 12 when the original parent's control index is valid; current IDA models the function, while zero surviving direct/pointer routes cap lexical-name and liveness confidence.
```

- Inspected `by-class/-coverage-report.md` UID0000AN row and `by-file/-coverage-report.md` UID0000MN row. Their text remains suitable after the recommended class channel repair; no score or row-text change is requested.
- C0004IS-020 is applied and verified: the supervisor inserted the exact row at current line 1183. Scoped validation command `000000021739`, timestamp `2026-08-10T13:17:47-04:00`, exited `0`, reported `ok: 1`, and reported generated refresh skipped. B002 did not edit the manual coverage file.

## Follow-Up Actions

- Historical gate receipt: supervisor mechanically passed the exact report-only artifact SHA256 `32CC6BC36C4BD6EC6A970C57109814719930060AB3EF4E3935A9C9DE80DBAE92` at Gate 1 `33/33`.
- B002 callback: claims C0004IS-001 through C0004IS-019 and C0004IS-023 through C0004IS-027 are implemented and physically verified under JIT leases with the receipts below.
- Supervisor Gate 2B is complete: I0004IS-01 is applied/verified/saved, I0004IS-02 is no-change verified, and persistence/readback is recorded under catalog entry `0415`.
- Supervisor manual state is complete: C0004IS-020's exact coverage row is present at line 1183 and scoped command `000000021739` passed.
- Lifecycle guard C0004IS-028 is verified because Gate 2A and Gate 2B now pass. Report execution/archive remains supervisor-owned and authoritative only from the report's current path plus validator-owned lifecycle metadata; this report does not state that execution has occurred.
- No A-agent or unrelated B-agent work is required for this target.

## Confidence

- Recommendation confidence: `93/100`.
- Score confidence: high; `94/93` matches dedicated evidence depth without claiming original symbols or final-audit certainty.
- Behavior/range/ownership confidence: very high.
- Remaining uncertainty: original lexical spelling/access, exact code-12 enum/name/intent, whether any stripped source path once called the method, and original physical file split.

## Validator Results

- Report-only phase validator commands: none, as required. The accepted callback ran these scoped commands from `source-3/project-documentation`; each exited `0`, reported `ok: 1`, and reported `generated_refresh: skipped` because `--no-generated-refresh` was set:
  - Target: `python .\tools\validator.py --mode file --file by-memory\0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md --apply --no-generated-refresh --queue-timeout 240`; command `000000021710`, timestamp `2026-08-10T12:37:49-04:00`. It confirmed completion `94`, confidence `93`, and normalized/inserted current UID links.
  - Class: `python .\tools\validator.py --mode file --file by-class\PopupMenuControlPane.md --apply --no-generated-refresh --queue-timeout 240`; command `000000021712`, timestamp `2026-08-10T12:38:47-04:00`. It registered the migrated formal H block and CPP child route.
  - File: `python .\tools\validator.py --mode file --file by-file\PopupMenuControls.md --apply --no-generated-refresh --queue-timeout 240`; command `000000021714`, timestamp `2026-08-10T12:39:35-04:00`. Four pre-existing missing-reference diagnostics for historical UIDs `000376`-`000379` remained unrelated; target validation still reported `ok: 1`.
  - Split parent: `python .\tools\validator.py --mode file --file by-memory\0x00498040-0x00498599.PopupMenuControlPaneCore.md --apply --no-generated-refresh --queue-timeout 240`; command `000000021717`, timestamp `2026-08-10T12:40:20-04:00`.
  - Setter: `python .\tools\validator.py --mode file --file by-memory\0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex.md --apply --no-generated-refresh --queue-timeout 240`; command `000000021719`, timestamp `2026-08-10T12:40:45-04:00`.
- Historical callback coherent rebuild/readback: `python .\tools\validator.py --mode autogen --apply --queue-timeout 240`; command `000000021722`, timestamp `2026-08-10T12:41:03-04:00`, exit `0`, `generated_refresh: completed`. Autogen mode did not emit a separate `ok` count; it rebuilt one registry and refreshed generated metadata.
- Historical callback-generated CPP receipt: `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`, SHA256 `7A6A4EF14B0B697220BF8DFBB534DF5BA5F3DBBB71CA22BCC8AE76C8B55F8D2D`, 342 lines / 12,803 bytes. At that snapshot its header matched command `000000021722`; the header include occurred once, PopupMenuControlPane class declarations occurred zero times, UID0004IS's exact definition occurred once at line 216, and no UID0004IS empty-emitter marker existed.
- Historical callback-generated H receipt: `auto-generated/NexusTK/ui/menu/PopupMenuControls.h`, SHA256 `35C0602E5725C61B892CAC2970078E1FF3D41F30E4BDB111BB406A77514FC830`, 114 lines / 2,996 bytes. At that snapshot its header matched command `000000021722`; `../core/ControlPane.h` occurred once at line 81, the class declaration occurred once at line 90, and `SelectItemAndNotifyParent(long index);` occurred once.
- These command/hash/line receipts are historical callback evidence. Later validator activity advanced the physical generated headers, so current generated command identity is read dynamically from those headers; the later supervisor closure reverified the same target-definition/class-declaration route.
- Supervisor C0004IS-020 coverage validation receipt: command `000000021739`, timestamp `2026-08-10T13:17:47-04:00`, exit `0`, `ok: 1`, generated refresh skipped; exact row physically verified at line 1183.

## Changed Files

- Target: `by-memory/0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md`, SHA256 `B9548386283492AF8B93EF4FB381C57EA31782E4413C98A6810B3BB91889B02C`, 105 lines / 11,460 bytes. Exact binary contract begins at line 37 and notification semantics at line 61; formal CPP remains lines 10-19 and target H is blank.
- Class: `by-class/PopupMenuControlPane.md`, SHA256 `14939F20B85CB2B9CA58D7EE7AA469F77307B04CE1B48B4DBBC415DB55F21F31`, 167 lines / 19,031 bytes. Formal CPP is only `[[CHILDREN]]` at line 10; formal H spans lines 12-47, and the UID0004IS dedicated recheck begins at line 106.
- File: `by-file/PopupMenuControls.md`, SHA256 `568154F70F1090B37D519225892C48DC1DD52D3C295E2B57F0FB0D6119E60E79`, 259 lines / 44,462 bytes. Current UID0004IS model/no-route evidence is at line 100 and the repaired physical header/source receipt is at line 106.
- Split parent: `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md`, SHA256 `120C12A089E9F25AD2E13B88CDEF6355DC8D777EFDF035F4BE811ACE14AC753F`, 108 lines / 16,131 bytes. The exact current model/body/no-route reconciliation is at line 71.
- Setter: `by-memory/0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex.md`, SHA256 `C7A2FFF217757828E92B01F705A4E603D8A68F0A9E7A2C0A963EAE1095752D1C`, 63 lines / 4,711 bytes. The exact source-call/optimized-inline relationship is at line 47; metadata and formal CPP remain unchanged.
- Read-only consumers were not edited: UID000459 SHA256 `54DA7197798A97F1624E4A5D240096340C680A513BC31FCA724C401E1375E9BB`; UID0003MD `8CC4CA8C4054D0C8504F356614653C3914B982E0B0BDC7E3E4AD5785C324DFDC`; UID0001JB `65ABF6AEA747A572FB0C4F84C1A3F40C127E62FB2743CA3358530C2033ED8A3E`; UID0001KG `4EC3F28D0FEF72374DFB42D70FC03549FA554D82B6091BB21A196B8830B3F260`.
- During B002's accepted callback, generated files changed only through validator command `000000021722`; later tool-owned validator activity advanced their headers. B002 never edited generated content directly. Scoped validators also reported tool-owned projected-stat/reference/autogen-registry maintenance. B002 made no manual generated, coverage, validator.ini, IDA, or lifecycle edit; the completed supervisor-owned coverage and IDA changes are recorded in the current receipts above.
- JIT leases: target, class, file, split parent, and setter were each leased only for their edit/scoped-validator batch and immediately released. The report was leased only for this receipt/check-state edit. No lease conflict occurred, and final shared-lease readback must contain no B002/UID0004IS row.
- Renamed/moved files: none. IDA/MCP mutations: none. Manual coverage edits: none. Report lifecycle commands: none.
- Report lifecycle boundary: execution/archive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata. B002 will not run `execute_report`, lifecycle commands, or manual moves.

## Implementation Tracking Checklist

| State | Claim ID | Target UID | Claim | Destination | Action | Actor |
| --- | --- | --- | --- | --- | --- | --- |
| [x] | C0004IS-001 | 0004IS | Record exact `0x4981b0-0x49821f` identity, 111 bytes, SHA256 `6DC833EECFD6DDF74E589850D46D0ADA9D992DAD5588742A3C67CC219C3255C7`, 49 instructions, 7 blocks, and `0xcc` fences. | target `Exact Binary Contract` | incorporate | B002 |
| [x] | C0004IS-002 | 0004IS | Replace stale current raw/unmodeled state with current modeled function `PopupMenuControlPane_SelectItemAndNotifyParent`, size `0x6f`, while preserving historical pre-curation state. | target `Current IDA State` | incorporate | B002 |
| [x] | C0004IS-003 | 0004IS | Preserve zero incoming code/data xrefs, zero VA/RVA pointer hits, no vtable/data slot, and setter-only constructor callback evidence. | target `Retained Liveness And Reachability` | incorporate | B002 |
| [x] | C0004IS-004 | 0004IS | Classify the exact fenced coherent body as source-authored retained unused code, not padding, compiler glue, or no-code coverage. | target `Retained Liveness And Reachability` | incorporate | B002 |
| [x] | C0004IS-005 | 0004IS | Preserve inferred private source signature `void SelectItemAndNotifyParent(long index)` and reject stronger unsupported names. | target `Name And Signature` | incorporate | B002 |
| [x] | C0004IS-006 | 0004IS | Document cached-original-parent flow, conditional selection update, second parent lookup inside setter flow, and independent code-12 lookup. | target `Exact State And Call Flow` | incorporate | B002 |
| [x] | C0004IS-007 | 0004IS | Document code 10 as the ordinary selection-change notification and exact inlined `SetSelectedIndex` path. | target `Notification Semantics` | incorporate | B002 |
| [x] | C0004IS-008 | 0004IS | Preserve code 12 literally as a separate parent notification; record that known parents do not prove close/commit/dismiss meaning. | target `Notification Semantics` | incorporate | B002 |
| [x] | C0004IS-009 | 0004IS | Preserve the existing target CPP body as execution-equivalent, human source-shaped formal code. | target CPP block | preserve | B002 |
| [x] | C0004IS-010 | 0004IS | Keep the target H block blank because the declaration belongs to class UID0000AN. | target H block | preserve | B002 |
| [x] | C0004IS-011 | 0004IS | Raise target `88/89` to `94/93` and replace the Item Summary with the dedicated current finding. | target metadata/header | replace | B002 |
| [x] | C0004IS-012 | 0004IS | Add exact binary, state-flow, consumer-matrix, source-parity, and no-null-guard evidence at report-level detail. | target body sections | incorporate | B002 |
| [x] | C0004IS-013 | 0004IS | Preserve historical raw state and rejected alternatives as explicitly superseded/rejected evidence. | target history/rejections | incorporate | B002 |
| [x] | C0004IS-014 | 0004IS | Replace class prose claiming UID0004IS remains raw with current modeled/no-route evidence and refined notification semantics. | class UID0000AN evidence notes | replace | B002 |
| [x] | C0004IS-015 | 0004IS | Move the complete PopupMenuControlPane declaration from class CPP to class H, add `../core/ControlPane.h`, and leave only `[[CHILDREN]]` in class CPP. | class UID0000AN formal CPP/H | move declaration channel | B002 |
| [x] | C0004IS-016 | 0004IS | Replace file prose claiming no function at UID0004IS and reconcile the physical header/source contract after class-channel repair. | file UID0000MN UID00011F section | replace | B002 |
| [x] | C0004IS-017 | 0004IS | Replace split-parent stale unmodeled/no-route prose with current modeled/no-route and exact body evidence. | core UID00011F evidence notes | replace | B002 |
| [x] | C0004IS-018 | 0004IS | Add the exact source-level call-through relationship to the setter without changing setter metadata or CPP. | setter UID0004IT behavior notes | incorporate | B002 |
| [x] | C0004IS-019 | 0004IS | Verify Folder/Music/Terminal/UserInfo consumer docs remain support evidence and require no metadata/formal-source change. | four consumer support pages | verify already present | B002 |
| [x] | C0004IS-020 | 0004IS | Insert the missing exact UID0004IS manual by-memory coverage row after UID0004IN. | by-memory manual coverage | insert | Supervisor |
| [x] | C0004IS-021 | 0004IS | Replace only the target regular function comment with the exact refined behavior/no-route wording. | IDA `0x4981b0` function comment | apply | Supervisor |
| [x] | C0004IS-022 | 0004IS | Protect current function boundary, name, ABI-equivalent IDA `int` type, complete frame, and three non-function comment channels from change. | IDA `0x4981b0` protected state | protect | Supervisor |
| [x] | C0004IS-023 | 0004IS | Run scoped target validation with generated refresh disabled after callback edits. | target validator receipt | validate | B002 |
| [x] | C0004IS-024 | 0004IS | Run scoped class validation with generated refresh disabled after callback edits. | class validator receipt | validate | B002 |
| [x] | C0004IS-025 | 0004IS | Run scoped file validation with generated refresh disabled after callback edits. | file validator receipt | validate | B002 |
| [x] | C0004IS-026 | 0004IS | Run scoped split-parent and setter validation with generated refresh disabled after callback edits. | core/setter validator receipts | validate | B002 |
| [x] | C0004IS-027 | 0004IS | After accepted implementation and coherent refresh, verify one target definition in CPP and the class declaration in H rather than CPP. | generated PopupMenuControls CPP/H | read back | B002 |
| [x] | C0004IS-028 | 0004IS | Preserve the lifecycle guard requiring Gate 2A documentation verification and Gate 2B IDA closure before execution/archive; both gates pass, but execution is not claimed. | validator-owned report lifecycle | lifecycle guard verified; execution remains supervisor-owned | Supervisor |

All 28 claim IDs, actors, actions, destinations, and states retain ledger/checklist identity, and all 28 claims are checked. C0004IS-020 is applied/verified, C0004IS-021 is applied/verified/saved, C0004IS-022 is no-change verified, and C0004IS-028 is checked only as the satisfied lifecycle guard; execution/archive remains supervisor-owned and is not claimed to have occurred.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000021783","destination_path":"executed-b-agent-research/B002/0004IS-PopupMenuControlPaneSelectItemAndNotifyParentRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0004IS-PopupMenuControlPaneSelectItemAndNotifyParentRaw-source-quality.md","timestamp":"2026-08-10T14:41:59-04:00","uid":"0004IS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
