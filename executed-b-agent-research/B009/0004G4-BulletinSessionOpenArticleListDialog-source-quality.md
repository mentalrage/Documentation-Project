** TARGET-REPORT-UID:0004G4 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0004G4 BulletinSessionOpenArticleListDialog Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0004G4] `by-memory/0x00471960-0x00471a26.BulletinSessionOpenArticleListDialog.md` as a reconstructable `BulletinSession` method/documentation child owned by [UID:00001D] with blank `EMITTER_UIDS` and blank formal C++ for now.
- Current implemented score: `86/91`, raised from the assignment-time `84/90` during the accepted implementation callback. MCP session `d3e83820` resolves the exact body, range, boundary padding, callee list, allocation size, active-id store, and no-entry-xref/duplicate-dispatcher caveat. Do not raise higher or emit C++ yet because the target has zero xrefs to its function entry and duplicates dispatcher case `2` rather than being the observed live route.
- Source placement: future route remains [UID:0000HX] `BulletinSession.cpp`. [UID:0000HT] `BoardDialogs` / [UID:00000K] `ArticleListDialog` are callee/support owners, not the direct owner of this session helper.
- C++ disposition: formal `RECONSTRUCTION_CPP CODE` should remain blank. The no-code proof is target-specific: even with plausible `ArticleListDialog` and `DialogSession::PushDialog` declarations, emitting this body now would create an uncalled private helper and duplicate the live inline dispatcher case-2 path at `0x00471550`.

## Supporting Research
- Assignment history: B009 completed the report-only source-quality pass for UID0004G4, then applied the accepted implementation callback after Gate 1 approval. During the callback B009 edited only the target/support by-* docs listed in `Changed Files` plus this report; no generated source/report files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, or IDA DB state were manually edited.
- MCP: after the stale `b010_00032w_20260703` session disappeared, supervisor restored MCP with fresh IDB-backed session `d3e83820`; this report uses `d3e83820` only.
- MCP health: `idb_list` showed session `d3e83820`, input IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker, not analyzing. `server_health(database=d3e83820)` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Skill/read gates used: `ntk-b-agent-workflow`, `b-agent-research-and-implementation-workflow.md`, `by-structure.md` IDA MCP Output Discipline, target page, parent/class/file support pages, generated tracker/coverage rows, and matching executed B012 parent report.

## Target
- Target UID: `0004G4`.
- Target path: `by-memory/0x00471960-0x00471a26.BulletinSessionOpenArticleListDialog.md`.
- Historical assignment-time generated tracker row before callback: `84/90`, combined `87.0`, reconstructable `true`, reports `0`, blank emitter.
- Current target metadata after B009 implementation callback and validator command `000000005683`: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:00001D`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank optional emitter position, blank formal C++.
- Current generated/tracker caveat: generated refresh was deferred by the scoped validators, so any generated coverage/tracker row still showing `84/90`, `reports 0`, `non-emits`, or `emits_code:false` is generated-stale context only. It is not the current target by-* metadata. The current by-* target remains `86/91` and blank-emitter/no-code.

## Current Target State
- Post-callback target page now identifies the range as `0x00471960-0x00471a26`, owner [UID:00001D] `BulletinSession`, future source route [UID:0000HX] `BulletinSession.cpp`, parent split/index [UID:0000ZH], reconstructable `TRUE`, score `86/91`, blank `EMITTER_UIDS`, blank optional emitter position, and blank formal C++.
- Post-callback behavior/evidence text records the current MCP-backed detail: the function builds the same article-list rectangle as dispatcher case `2`, allocates `0x478` bytes / `1144` decimal (Verified with int_convert.py), constructs `ArticleListDialog` at `0x00472ca0`, pushes it through `DialogSession` helper `0x004a0fc0`, reads the dialog id at returned dialog `+0x274` / `628` decimal (Verified with int_convert.py), stores it into `BulletinSession +0x102` / `258` decimal (Verified with int_convert.py), and returns that id.
- Post-callback no-code proof has replaced the old shallow blocker. The current blocker is not merely that "active-list id field and ArticleListDialog declaration need synchronization." MCP session `d3e83820` adds the stronger target-specific proof: `xrefs_to 0x00471960` returns zero xrefs, while dispatcher case `2` at `0x00471550` already contains an inline equivalent article-list construction path and calls `0x00472ca0` from `0x00471695`. Emitting this target would invent an unobserved helper callsite or duplicate dispatcher source.
- Active lifecycle state: implementation callback is applied; scoped validators have run and passed; generated refresh remains deferred; B009 has not run `execute_report`, dry-run/probe variants, lifecycle/archive commands, registry commands, manual report moves, generated-file edits, coverage-report edits, or subagents. The artifact is awaiting supervisor Gate 1 re-review and Gate 2/execution handling.

## Heuristic / Inference Reanalysis And Validation
- Range/boundary validation: `lookup_funcs` reports `sub_471960` at `0x00471960` size `0xc6` / `198` decimal (Verified with int_convert.py). `lookup_funcs` says `0x0047195f` and `0x00471a26` are not function starts, while sibling `0x00471a30` is the next modeled function. `get_bytes` at `0x00471956` and `0x00471a26` returns ten `0xcc` bytes before/after the function followed by the adjacent prologue bytes, so the child bounds are clean.
- Body validation: decompile shows `byte_66DA97 == 1` selects rectangle `(10,10,461,430)`; otherwise `(10,10,456,376)`. The converted constants are `0x1cd` = `461`, `0x1ae` = `430`, `0x1c8` = `456`, and `0x178` = `376` (Verified with int_convert.py).
- Construction path: callee list is `0x004b7c50` rectangle helper, `0x004f4aa0` allocator, `0x00472ca0` `ArticleListDialog` constructor, `0x004a0fc0` DialogSession push/add helper, and MSVC security-cookie support. The allocation size is `0x478` / `1144` decimal (Verified with int_convert.py), matching [UID:00000K] `ArticleListDialog` support.
- Reachability/source-shape blocker: `xrefs_to 0x00471960` returns zero. This does not prove the bytes are padding or third-party code because IDA models a real `0xc6` function with constructor behavior, but it blocks a confident source route for an emitting method.
- Duplicate live route: `decompile 0x00471550` shows dispatcher case `2` checks `*(this+0x100)==1`, builds the same rectangle, allocates `0x478`, calls `0x00472ca0`, pushes the dialog through `0x004a0fc0`, stores `*(dialog+0x274)` into `this+0x102`, and clears `this+0x100` to `0`. UID0004G4 contains the construction/store subset but does not clear `+0x100` and has no entry xref.
- Inference validated: source-facing role remains "open article-list dialog and remember active list id", but final method name, visibility, and whether it was an unreferenced helper, duplicate retained method, or decompiler-split artifact remain unresolved. This is a stronger cap than the current page records.

## Evidence Standards Used
- Direct MCP fact: session health, modeled function starts/sizes, zero xrefs, decompile/disasm, callee lists, and boundary bytes from session `d3e83820`.
- Documentation evidence: current target, UID0000ZH parent split/index, UID00001D class page, UID0000HX file page, UID00000K `ArticleListDialog`, UID00030G `ArticleListDialogCore`, UID0000HT `BoardDialogs`, generated coverage/tracker rows, and executed B012 parent report.
- Inference: source-facing helper names, active-state/dialog-id field names, and support declaration shape.
- Limits: no broad MCP listing/callgraph/type batch was used. Hex-Rays names and prototypes are synthetic. No original source symbol proves this helper name or route.

## Evidence Checked
- MCP calls on `d3e83820`: `idb_list`, `server_health`, `lookup_funcs` for `0x00471960`, siblings `0x004718a0/0x00471a30`, callee/support addresses `0x00472ca0/0x004a0f40/0x004a1020`, boundary starts `0x0047195f/0x00471a26`; `xrefs_to 0x00471960`; `callees 0x00471960`; `decompile 0x00471960`; `disasm 0x00471960`; `get_bytes 0x00471956/0x00471a26`; `analyze_function 0x00471960`; `decompile 0x00471550`; `xrefs_to 0x00472ca0`; `xrefs_to 0x004a0fc0`.
- MCP results: no xrefs to UID0004G4 entry; `xrefs_to 0x00472ca0` returns constructor calls at `0x00471695` in dispatcher and `0x004719e1` in UID0004G4; `xrefs_to 0x004a0fc0` shows the helper is used by related BulletinSession open/action paths.
- Docs searched/opened: target page, UID0000ZH parent, UID00001D class, UID0000HX file, UID00000K class, UID00030G core, UID0000HT file, sibling UID0004G3/UID0004G7 pages, B012 executed parent report, generated memory coverage and research tracker.
- Search terms used: `0004G4`, `00471960`, `00471a26`, `BulletinSessionOpenArticleListDialog`, `OpenArticleListDialog`, `sub_471960`.
- Numeric conversions checked with `tools/int_convert.py`: `0x478`, `0x274`, `0x102`, `0x100`, `0xc6`, `0x1ae`, `0x1cd`, `0x178`, `0x1c8`.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0004G4 remains a `BulletinSession` documentation child, owned by [UID:00001D], reconstructable true, blank emitter. | Strong | Target/class/file docs; MCP modeled function belongs in BulletinSession island. | Target metadata/status; BulletinSession method table | applied | Target metadata now preserves owner/reconstructable/blank emitter/formal C++; `by-class/BulletinSession.md` row records the same blank-emitter/no-code status. |
| C2 | Function is exactly `0x00471960-0x00471a26`, size `0xc6` / `198`, with `0xcc` padding before/after. | Strong | `lookup_funcs`, `get_bytes`; int_convert. | Target MCP Evidence / Range notes | applied | Target MCP Evidence now records `d3e83820` modeled size, boundary non-functions, and clean pre/post `0xcc` padding. |
| C3 | Body allocates `0x478` / `1144` bytes and constructs `ArticleListDialog` via `0x00472ca0`. | Strong | Decompile/disasm/callees; ArticleListDialog docs. | Target Behavior; support docs | applied / already-present | Target Behavior, `by-class/BulletinSession.md`, `by-file/BulletinSession.md`, and UID0000ZH child row now carry allocation/constructor facts; `by-class/ArticleListDialog.md` and ArticleListDialogCore already recorded callers `0x00471695` and `0x004719e1`, so no duplicate edit was made there. |
| C4 | Body pushes the dialog through `DialogSession` helper `0x004a0fc0`, reads dialog `+0x274`, stores into session `+0x102`, and returns it. | Strong | Decompile/disasm; int_convert. | Target Behavior; BulletinSession support | applied | Target Behavior and BulletinSession class/file/parent support now record `0x004a0fc0`, dialog `+0x274`, session `+0x102`, and returned id behavior. |
| C5 | `xrefs_to 0x00471960` is empty; this is a target-specific no-code blocker. | Strong | MCP xrefs_to. | Target No-Code Proof; class/file caveat | applied | Target No-Code Proof and BulletinSession class/file/parent support now state zero entry xrefs and route-unproven helper status. |
| C6 | Dispatcher case `2` duplicates the live article-list open path and additionally clears `+0x100`. | Strong | `decompile 0x00471550`. | Target No-Code Proof; parent/class support | applied | Target and support docs now record duplicate live dispatcher case-2 path at `0x00471550`; support wording avoids inventing a helper callsite. |
| C7 | Formal C++ should remain blank until helper route/name/visibility and support declarations are synchronized; a draft body would invent an uncalled method. | Medium-strong | Zero entry xrefs, duplicate dispatcher path, marker-only ArticleListDialog support. | First-Draft C++ Recommendation; target formal C++ | applied | Target formal `RECONSTRUCTION_CPP CODE` remains blank with stronger proof that code would invent an unobserved callsite or duplicate dispatcher source. |
| C8 | Score should rise to `86/91`, not code-entry. | Medium-strong | New MCP detail resolves body/range but strengthens route/no-code blocker. | Target metadata recommendation | applied | Target metadata is now `COMPLETION:86`, `CONFIDENCE:91`; validator command `000000005683` confirmed both updates. |

## Positive Evidence Summary
- The target is a real modeled function, not padding: `lookup_funcs` reports `sub_471960`, size `0xc6`.
- The body is source-shaped game UI code: it uses board/article rectangle selection, allocates a concrete dialog object, calls `ArticleListDialog` constructor, pushes it into the dialog session, and stores an active dialog/list id.
- The owner route is stable: target sits inside the UID0000ZH BulletinSession island, uses `this+0x102`, and mirrors dispatcher case `2` article-list handling.
- The support route is identifiable: concrete dialog construction belongs to [UID:00000K]/[UID:00030G]/[UID:0000HT], while session orchestration belongs to [UID:00001D]/[UID:0000HX].

## Negative Evidence Summary
- There are zero direct xrefs to `0x00471960`.
- The live dispatcher case `2` at `0x00471550` already emits an inline equivalent call to `0x00472ca0` and `0x004a0fc0`; UID0004G4 is not required to explain the observed dispatcher route.
- ArticleListDialog class/core support remains marker-only; exact class fields, constructor declaration, packet/list-entry declarations, and source split are still not formal.
- Field names `+0x100`, `+0x102`, and dialog `+0x274` remain inferred. The best current names are active/list pending flag, active list/dialog id, and dialog id field/accessor, but exact source declarations are not ready.

## Ranked Ownership Analysis
### 1. [UID:00001D] BulletinSession
- Evidence for: target receives `this` as BulletinSession, stores `+0x102`, sits in UID0000ZH, and duplicates dispatcher article-list case behavior.
- Evidence against: no entry xrefs and concrete dialog body belongs to ArticleListDialog/BoardDialogs.
- Decision: keep as canonical owner, but blank emitter.

### 2. [UID:0000HX] BulletinSession file root
- Evidence for: file page owns BulletinSession coordinator, singleton, dispatcher, and method children.
- Evidence against: by-file is the source root, not the narrower direct by-memory owner.
- Decision: future source placement remains `BulletinSession.cpp`.

### 3. [UID:00000K] ArticleListDialog / [UID:0000HT] BoardDialogs
- Evidence for: constructor callee `0x00472ca0`, allocation size `0x478`, and dialog id read at `+0x274` are ArticleListDialog facts.
- Evidence against: target itself is session orchestration; it does not implement ArticleListDialog behavior.
- Decision: support docs only. Do not reowner UID0004G4 to BoardDialogs.

## Source Placement
- Recommended placement stays `ui/dialogs/BulletinSession.cpp/.h` through [UID:0000HX].
- The target should be documented as an uncalled/route-unproven private session helper or retained duplicate of dispatcher case `2`, not as a concrete `ArticleListDialog` method and not as a raw no-route non-reconstructable helper.
- Rejected placements: `BoardDialogs.cpp` owns the constructed dialog; `DialogSession.cpp` owns stack helpers; neither owns the session-level helper.

## Range / Split / Padding / Reclassification Analysis
- No split is needed. Exact range is clean and already a single modeled function.
- No merge into UID0004G1 was performed during the implementation callback. UID0004G1 dispatcher contains a duplicated live path, but UID0004G4 is a separate modeled body with its own SEH/security-cookie frame and exact padding.
- No reclassification to `RECONSTRUCTABLE:FALSE` is recommended now. Unlike raw helper children, this is a modeled function with ordinary code shape and ArticleListDialog construction semantics. The issue is route/source readiness, not non-source data or compiler-only table bytes.

## First-Draft C++ Recommendation
- Formal C++ insertion text: leave blank.
- No-code proof: `xrefs_to 0x00471960` returns no xrefs in current MCP session `d3e83820`. The dispatcher `0x00471550` case `2` contains an inline live article-list construction path and calls `0x00472ca0` at `0x00471695`; UID0004G4 separately calls the same constructor at `0x004719e1` but has no observed route. Even with support declarations such as `ArticleListDialog(BulletinSession *, const RectBounds &, const PacketView *)`, `DialogSession::PushDialog`, and `ArticleListDialog::GetDialogId`, emitting a method now would require inventing a private helper name/visibility and an unobserved callsite, or duplicating dispatcher case `2` source. That is not source-quality.
- What would make C++ safe later: a route to `0x00471960` or authoritative class/source evidence showing this was an intentional retained private method; synchronized support declarations for `ArticleListDialog` constructor, dialog id accessor/member, `DialogSession::PushDialog`, `RectBounds`, packet view type, and BulletinSession `m_activeListDialogId` / active flag names.

## Final Recommendation
- Implementation callback applied target documentation rather than source emission: current MCP session `d3e83820` facts, exact body details, zero-xref proof, dispatcher duplicate comparison, and support-declaration blockers are now incorporated.
- Target is now `COMPLETION:86`, `CONFIDENCE:91`; owner `00001D`, reconstructable `TRUE`, blank `EMITTER_UIDS`, blank optional position, and blank formal C++ are preserved.
- B009 did not run `execute_report`, dry-run/probe variants, lifecycle/archive commands, registry commands, or manual report moves.

## Recommended Target Doc Changes
- Set UID0004G4 `COMPLETION:86`, `CONFIDENCE:91`; keep `CANONICAL_OWNER:00001D`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Fill `Item Summary` with: "MCP session d3e83820 confirms modeled `0xc6` BulletinSession article-list opener at `0x00471960`, clean padding, zero entry xrefs, rectangle selection via `byte_66DA97`, `0x478` ArticleListDialog allocation, constructor call `0x00472ca0`, DialogSession push `0x004a0fc0`, returned dialog `+0x274` id copied to session `+0x102`, and duplicate live dispatcher case-2 path at `0x00471550`; formal C++ remains blank pending route/declaration proof."
- Replace shallow MCP Evidence with exact `d3e83820` facts: health/session, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, boundary bytes, and int_convert-verified constants.
- Replace No-Code Proof with the stronger target-specific proof from `First-Draft C++ Recommendation`.
- Add rejected alternatives: ArticleListDialog ownership, BoardDialogs source ownership, DialogSession ownership, reclassifying as raw non-reconstructable helper, and emitting decompiler-shaped SEH/security-cookie/raw-offset code.

## Recommended Support Doc Changes
- `by-class/BulletinSession.md`: applied UID0004G4 row/support note recording zero entry xrefs, duplicate dispatcher case-2 path, `+0x102` active list/dialog id store, and continued blank-emitter/no-code status. Class score was unchanged.
- `by-file/BulletinSession.md`: applied UID0004G4 proposed-content row update with current `d3e83820` evidence and noted that future source route remains `BulletinSession.cpp`, but this exact helper is route-unproven. File metadata was unchanged.
- `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`: applied child-row/support sync showing UID0004G4 has a separate modeled duplicate of dispatcher case `2` with zero entry xrefs. Parent metadata was unchanged.
- `by-class/ArticleListDialog.md` / `by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md`: audited and left unchanged because construction callers `0x00471695` and `0x004719e1` were already present at sufficient detail; B009 did not invent class fields or unlock ArticleListDialog aggregate C++.
- `by-file/BoardDialogs.md`: left unchanged because the accepted implementation did not require a new BoardDialogs fact and existing ArticleListDialog marker-only/source context was sufficient.

## Score And Metadata Recommendation
- Historical before-callback score/metadata: `84/90`, owner `00001D`, reconstructable true, blank emitter/C++.
- Current implemented score/metadata: `86/91`, owner `00001D`, reconstructable true, blank emitter/C++.
- Rationale: completion improved because the target now has exact current-session MCP body/range/callee/no-xref/duplicate-dispatcher evidence and implementation-ready documentation text. Confidence improved slightly because the body role is clear and owner/source route remains stable. Score remains below code-entry because no entry route exists, support declarations are marker-only, and emitting the body would duplicate the observed dispatcher case-2 implementation.

## Open Questions With Attempted Resolution
- Is UID0004G4 reachable? Current resolution: no direct xrefs in MCP `d3e83820`; leave as route-unproven retained helper/duplicate, not a live dispatcher path.
- Can the active-list id field be named? Current resolution: source-facing role is active list/dialog id at `BulletinSession +0x102`; exact member name remains unresolved.
- Can `ArticleListDialog` support declarations be introduced now? Current resolution: enough to document constructor/id dependencies, not enough to emit this target, because the route/name/visibility problem remains even if support declarations are inferred.
- Should this be `RECONSTRUCTABLE:FALSE` like raw helper children? Current resolution: no. IDA models a function object with ordinary source-shaped UI/session code; the safer fix is blank emitter/no-code proof, not non-reconstructable reclassification.

## Validator Results
- `python .\tools\validator.py --mode file --file by-memory/0x00471960-0x00471a26.BulletinSessionOpenArticleListDialog.md --apply --queue-timeout 240`: command_id `000000005683`, command_timestamp `2026-07-03T17:29:19-04:00`, exit `0`, `ok: 1`. Updates reported: `completion_update 0004G4 86`, `confidence_update 0004G4 91`, `uid_link_insert 00001D`, `reference_index_add 0004G1`, projected stats update; warnings none reported; generated refresh deferred with command_id `000000005683`.
- `python .\tools\validator.py --mode file --file by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md --apply --queue-timeout 240`: command_id `000000005682`, command_timestamp `2026-07-03T17:29:19-04:00`, exit `0`, `ok: 1`. Updates reported: projected stats update and `stats_incremental_noop 0000ZH`; warnings none reported; generated refresh deferred with command_id `000000005682`.
- `python .\tools\validator.py --mode file --file by-file/BulletinSession.md --apply --queue-timeout 240`: command_id `000000005684`, command_timestamp `2026-07-03T17:29:19-04:00`, exit `0`, `ok: 1`. Updates reported: three `stats_row_update` entries for UID0000HX and projected stats update; warnings none reported; generated refresh deferred with command_id `000000005684`.
- `python .\tools\validator.py --mode file --file by-class/BulletinSession.md --apply --queue-timeout 240`: command_id `000000005685`, command_timestamp `2026-07-03T17:29:20-04:00`, exit `0`, `ok: 1`. Updates reported: four `stats_row_update` entries for UID00001D and projected stats update; warnings none reported; generated refresh deferred with command_id `000000005685`.
- Generated-refresh state: deferred for all four scoped validators. No generated files were manually edited by B009, and no `--wait-generated` proof was required because UID0004G4 keeps blank formal C++.

## Changed Files
- Edited target doc: `by-memory/0x00471960-0x00471a26.BulletinSessionOpenArticleListDialog.md`.
- Edited support docs: `by-class/BulletinSession.md`, `by-file/BulletinSession.md`, and `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`.
- Report updated: `tools/leaser/Agents/Agent-B009/research/0004G4-BulletinSessionOpenArticleListDialog-source-quality.md`.
- Validator-applied side effect: projected stats rows in `project-level/-auto-completion-stats.md`; no generated source/report file or coverage report was edited manually by B009.
- Already-present support detail, not edited: `by-class/ArticleListDialog.md` and `by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md` already recorded `ArticleListDialog` constructor callers `0x00471695` and `0x004719e1` at sufficient construction-detail level; B009 did not invent fields, declarations, or unlock aggregate C++ there.
- Forbidden commands not run: no `execute_report`, dry-run/probe execute variants, lifecycle/archive commands, registry commands, manual report moves, generated-file edits, coverage-report edits, or subagents.
- Leases used and released: B009 leased the four edited by-* docs for the edit/validator batch, then released all four; `current_leases.md` showed no active leases after release.

## Implementation Tracking Checklist
- [x] Target doc updated: `by-memory/0x00471960-0x00471a26.BulletinSessionOpenArticleListDialog.md`.
- [x] Metadata applied: set `COMPLETION:86`, `CONFIDENCE:91`; preserved owner `00001D`, reconstructable true, blank emitter and blank formal C++; validator command `000000005683` confirmed completion/confidence.
- [x] Target behavior/evidence applied: added `d3e83820` range, clean padding, zero-xref, rectangle, allocation, constructor, push, dialog-id, active-id store, and duplicate dispatcher case-2 facts.
- [x] Target no-code proof applied: formal C++ remains blank because no entry route exists and dispatcher case `2` already has the live equivalent path.
- [x] Support docs synced: `by-class/BulletinSession.md`, `by-file/BulletinSession.md`, and UID0000ZH parent now carry route-unproven duplicate-helper evidence and active id facts.
- [x] ArticleListDialog support audited: construction callers were already present in `by-class/ArticleListDialog.md` and ArticleListDialogCore at sufficient detail; no fields/declarations/aggregate C++ were invented.
- [x] Rejected alternatives preserved: target No-Code Proof rejects BoardDialogs/ArticleListDialog/DialogSession ownership, raw non-reconstructable reclassification, decompiler-shaped SEH/security-cookie/raw-offset code, and invented live helper callsite.
- [x] Validators run: scoped validators executed from `source-3/project-documentation` for all four edited by-* files with `--apply --queue-timeout 240`; all exited `0` with `ok: 1`.
- [x] Supervisor-only lifecycle respected: B009 did not run `execute_report`, dry-run/probe lifecycle variants, archive commands, registry commands, generated/coverage edits, manual report moves, or subagents.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000005704","destination_path":"executed-b-agent-research/B009/0004G4-BulletinSessionOpenArticleListDialog-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0004G4-BulletinSessionOpenArticleListDialog-source-quality.md","timestamp":"2026-07-03T18:01:06-04:00","uid":"0004G4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
