** TARGET-REPORT-UID:0004FW **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0004FW BulletinSessionOpenNewArticleDialog Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation/status: implementation callback is complete for UID0004FW; target/support by-* docs now apply the accepted source-ready `BulletinSession::OpenNewArticleDialog(const wchar_t *title)` disposition.
- Final disposition: target remains a source-bearing `BulletinSession` method child, direct owner [UID:00001D][BulletinSession](by-class/BulletinSession.md), `EMITTER_UIDS:00001D`, with the accepted formal C++ block in `RECONSTRUCTION_CPP CODE`.
- Gate state: target page and stale support rows in `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`, `by-class/BulletinSession.md`, and `by-file/BulletinSession.md` were edited and scoped-validated; `NewArticleDialogCore` and the raw rectangle helper were inspected as already-present support and left unchanged. No `execute_report`, dry-run/probing variant, lifecycle/archive command, generated edit, coverage edit, or supervisor-ledger edit was run by B006.
- Confidence: strong for behavior, boundaries, callers, owner, emitter route, and first-draft C++; capped below final audit by exact original member/helper spelling and broader `BulletinSession` declaration polish.

## Supporting Research

- Lifecycle/status notes: this artifact began as report-only research for UID0004FW, then passed Gate 1 and received this implementation callback. B006 edited only accepted target/support by-* docs plus this report during callback; no generated files, coverage reports, validator state, archives, supervisor ledgers, or lifecycle state were manually edited.
- Skill and workflow: used the project-level `ntk-b-agent-workflow` skill, read the assigned `goal.md`, the B-agent workflow reference, report template, score-blocker standard, and relevant `by-structure.md` sections for MCP discipline, metadata, emitter routing, and formal C++ requirements.
- MCP state: direct MCP work used live IDB session `d3e83820` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status:"ok"`, `module:"NexusTK.exe"`, `imagebase:"0x400000"`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Historical lead: executed B012 report `0000ZH-BulletinSessionCore-source-quality.md` created UID0004FW as a blank-emitter split child. That was valid at the split time, but later support docs now provide enough declarations for this exact child.

## Target

- Target UID: `0004FW`.
- Target path: `by-memory/0x004712f0-0x004713a6.BulletinSessionOpenNewArticleDialog.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` listed the target at `84/90`, combined `87.0`, reconstructable `true`, reports `0`.
- Current supervisor classification: implementation callback complete; awaiting supervisor Gate 2 review/execute decision.
- Current scores and parent state: target is now `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00001D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001D`, with formal C++; parent split/index [UID:0000ZH] remains `88/91`, non-emitting.

## Current Target State

- Implemented metadata: owner [UID:00001D][BulletinSession](by-class/BulletinSession.md), reconstructable true, `EMITTER_UIDS:00001D`, and formal `BulletinSession::OpenNewArticleDialog(const wchar_t *title)` C++ in `RECONSTRUCTION_CPP CODE`.
- Existing source route: [UID:00001D] emits to [UID:0000HX][BulletinSession](by-file/BulletinSession.md), which stages `NexusTK/ui/dialogs/BulletinSession.cpp`.
- Historical blocker text: the target previously said formal C++ was blank because `NewArticleDialog` constructor type, rectangle helper abstraction, and `PushDialog` declaration were not formal; that wording has been replaced as stale for UID0004FW.
- Current recheck/result: those blocker facts are resolved enough for this specific child. `NewArticleDialogCore` contains formal constructor C++ using `NewArticleDialog::NewArticleDialog(BulletinSession *session, const wchar_t *title, const Rect &bounds)` and `MakeRect`; `DialogSession` docs support `PushDialog`; current MCP proves UID0004FW only builds the bounds, allocates/constructs `NewArticleDialog`, and pushes it.
- Related target/support docs checked: UID0004FW target, UID0000ZH parent, `by-class/BulletinSession.md`, `by-file/BulletinSession.md`, `by-memory/0x004712b0-0x004712e5.BulletinSessionDialogRectRawNoRoute.md`, `by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md`, `by-class/NewArticleDialog.md`, `by-file/BoardDialogs.md`, `by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md`, `by-class/ArticleListDialog.md`, `by-class/ArticleDialog.md`, `by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md`, and `by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md`.
- Current artifact/lifecycle status: Gate 1 passed, implementation callback applied, scoped validators run for all edited by-* docs, no `execute_report` run by B006, awaiting supervisor Gate 2 review.

## Executive Recommendation

- Best direct owner: [UID:00001D][BulletinSession](by-class/BulletinSession.md). The method receives `BulletinSession *this`, is called by article-list/article-viewer user actions, constructs a `NewArticleDialog`, and pushes that dialog onto the inherited session stack.
- Source placement: emit through [UID:00001D] to [UID:0000HX] `BulletinSession.cpp`.
- Metadata recommendation: set target `COMPLETION:88`, `CONFIDENCE:91`, keep owner `00001D`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00001D`, keep blank optional position.
- C++ recommendation: insert the formal method body supplied below. The old blank/no-code treatment is stale for this exact child.
- Support condition: [UID:00001D] class-level output should receive or retain a marker with `[[CHILDREN]]` so the child method can surface through the class route without requiring a partial class declaration.

## Supervisor Active Recheck

- The original active assignment was the UID0004FW report-only target named in `Agent-B006/goal.md`; the current artifact now records the accepted implementation callback.
- The assigned item does not require a new split: UID0004FW is already the exact child range `0x004712f0-0x004713a6`, bracketed by padding and followed by sibling UID0004FX.
- No source-bearing child creation was needed. The applied repair converted the existing child from blank-emitter to source-ready after supervisor Gate 1 acceptance.

## Inference Research Guidance Check

- IDA/MCP facts are separated from documentation evidence and inference. Direct facts include function size, bytes, calls, xrefs, padding, data-xref absence, and caller decompilations from session `d3e83820`.
- Documentation evidence includes accepted `NewArticleDialog`, `DialogSession`, `BulletinSession`, `ArticleListDialog`, and `ArticleDialog` pages.
- Inference is limited to source-facing names: `OpenNewArticleDialog`, `title`, `Rect`, `MakeRect`, `g_useEpfAssets`, and `PushDialog`. These names are not PDB-proven, but they are already used or implied by current accepted support docs and match the exact body.
- Stale Wave2/Wave3/generated labels were treated only as leads. The final recommendation rejects decompiler-shaped `sub_4712F0`, raw `operator new`/SEH scaffolding, and caller-owner contamination.

## Heuristic / Inference Reanalysis And Validation

- Former blocker: "`NewArticleDialog` constructor type, rectangle helper abstraction, and `PushDialog` declaration are not formal." Rechecked against current docs. [UID:00030K] now contains formal `NewArticleDialog::NewArticleDialog(BulletinSession *session, const wchar_t *title, const Rect &bounds)` C++; [UID:000132] documents `DialogSession::PushDialog`; existing `NewArticleDialog` C++ already uses `MakeRect`. This resolves the blocker for UID0004FW.
- Method name: `BulletinSession::OpenNewArticleDialog` is the best source-facing name. It is already used in the target filename and B012 split report, and the body opens the normal compose dialog, not a reply/predefined/mail dialog.
- Parameter name/type: `const wchar_t *title` is supported by the `NewArticleDialog` constructor signature and caller evidence. ArticleListDialog passes its stored dialog text/title field at `this+0x276`; ArticleDialog passes a wide buffer read from control index `7`.
- Bounds helper: `MakeRect(0x0a, 0x0a, 0x1cd, 0x1ae)` for EPF and `MakeRect(0x0a, 0x0a, 0x1c8, 0x178)` for legacy mode is source-shaped. Decimal equivalents are `10`, `461`, `430`, `456`, and `376` (Verified with int_convert.py).
- Allocation and cleanup: `sub_4F4AA0(0x274)` and the SEH cleanup/delete path are compiler output for `new NewArticleDialog(...)`. Do not hand-author `operator new`, null checks, SEH, stack-cookie, or delete-cleanup wrapper code.
- Rejected raw-helper merge: adjacent [UID:0004FV] at `0x004712b0` has the same rectangle-selection logic but current MCP reports no function object and zero xrefs to its start. UID0004FW is a separate modeled, directly called source method; do not merge it into UID0004FV or reclassify it as raw no-route.
- Rejected dependency owners: NewArticleDialog owns the constructed dialog body; DialogSession owns `PushDialog`; BoardDialogs owns caller-side article UI classes; ArticleDialog and ArticleListDialog are consumers. None owns this `BulletinSession` session helper.

## Evidence Standards Used

- IDA MCP exact-address checks: `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `xref_query`, `find_bytes`, `callees`, `disasm`, `decompile`, and `analyze_function`.
- Local documentation checks: target/support by-* pages, executed B-agent reports for UID0000ZH and UID00030K, generated tracker rows, and generated `BulletinSession.cpp` header state as read-only leads.
- Negative evidence: data xref absence, no absolute VA/RVA pointer pattern for `0x004712f0`, no data/vtable route, no xrefs to the adjacent raw rectangle helper start, no function object at the raw helper, and no need for split/merge.
- Strength: strong enough for first-draft C++ because the exact body is small, single-purpose, has two direct callers, has formal callee support, and has clean bounds. Confidence is capped because exact original names and the full `BulletinSession` declaration remain inferred.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `server_health(database=d3e83820)`.
  - `lookup_funcs` for `0x004712b0`, `0x004712e5`, `0x004712f0`, `0x004713a6`, `0x004713b0`, `0x00474020`, `0x004740ad`, `0x00476740`, `0x00476800`, `0x00476c10`, and `0x004a0fc0`.
  - `get_bytes` for pre-target padding `0x004712e5` size `11`, full target `0x004712f0` size `182`, and post-target padding `0x004713a6` size `10`.
  - `xrefs_to` for `0x004712b0`, `0x004712f0`, `0x004713a6`, `0x00476c10`, and `0x004a0fc0`.
  - `xref_query` for code/data refs to `0x004712f0`, refs to raw helper start `0x004712b0`, and instruction/callee context around `0x00471371`.
  - `find_bytes` for absolute VA pattern `f0 12 47 00` and RVA pattern `f0 12 07 00`; both returned zero matches.
  - `callees`, `disasm`, `decompile`, and `analyze_function` for `0x004712f0`; `decompile`/`disasm`/`callees` for direct callers `0x00474020` and `0x00476740`.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target/support docs listed in `Current Target State`.
  - `executed-b-agent-research/B012/0000ZH-BulletinSessionCore-source-quality.md`.
  - `executed-b-agent-research/B005/00030K-NewArticleDialogCore-source-quality.md`.
  - Focused `rg` searches under `executed-b-agent-research` and active Agent folders for `0004FW`, `004712f0`, `4712f0`, `BulletinSessionOpenNewArticleDialog`, and `OpenNewArticleDialog`.
  - `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and read-only generated `auto-generated/NexusTK/ui/dialogs/BulletinSession.cpp`.
- Negative checks performed: no data xrefs to target start, no VA/RVA pointer patterns, no xrefs to raw helper start `0x004712b0`, no function at raw helper or target end, no split requirement, no parent aggregate C++ route.
- Failed, unavailable, or intentionally skipped checks and why: no broad list/search/disassembly/callgraph/type/batch-analysis calls and no IDA DB edits. Validators were intentionally skipped during the report-only evidence pass, then run during the accepted implementation callback as recorded under `Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0004FW is a modeled function `sub_4712F0` at `0x004712f0`, size `0xb6` / 182 bytes (Verified with int_convert.py), ending at `0x004713a6`. | Strong | `lookup_funcs`, `analyze_function`, `get_bytes`. | Target Status/Evidence; UID0000ZH child row | incorporate | applied: target Item Summary/MCP Evidence and UID0000ZH child row now state size `0xb6` / 182 bytes and exact range. |
| C2 | Bounds are clean: `0x004712e5-0x004712f0` and `0x004713a6-0x004713b0` are `0xcc` padding; `0x004713b0` is the next modeled sibling. | Strong | `get_bytes`; `lookup_funcs 0x004713b0`. | Target Evidence; parent split row | incorporate | applied: target MCP Evidence records clean padding before/after; parent row records clean padding through B006 support note. |
| C3 | The body selects EPF bounds `(10,10,461,430)` or legacy bounds `(10,10,456,376)` using `byte_66DA97`, then constructs and pushes a `NewArticleDialog`. | Strong | `decompile`, `disasm`, `analyze_function`; int_convert results. | Target Behavior/Evidence; formal C++ | incorporate | applied: target formal C++ uses `MakeRect(0x0a, 0x0a, 0x1cd, 0x1ae)` / `MakeRect(0x0a, 0x0a, 0x1c8, 0x178)`, constructs `NewArticleDialog`, and calls `PushDialog`. |
| C4 | Direct callers are `0x004740ad` in `ArticleListDialog::WriteNewArticle` and `0x00476800` in `ArticleDialog::SubmitAction/SendReplyOrReportAction`. | Strong | `xrefs_to 0x004712f0`; caller decompilations. | Target Cross-References; support docs if stale | incorporate | applied: target Item Summary/MCP Evidence and parent/class/file support notes record callers `0x004740ad` and `0x00476800` as consumer paths, not ownership proof. |
| C5 | There is no data/vtable/absolute pointer route to `0x004712f0`; direct code callers are the only current route. | Strong | `xref_query xref_type=data`; `find_bytes` VA/RVA patterns. | Target negative evidence | incorporate | applied: target Item Summary/MCP Evidence and support rows record no data xrefs or pointer route. |
| C6 | Adjacent raw rectangle helper [UID:0004FV] remains no-function/no-xref and must not absorb UID0004FW. | Strong | `lookup_funcs 0x004712b0`; `xrefs_to 0x004712b0`; existing UID0004FV page. | Target rejected alternatives; parent row | incorporate | applied/already-present: target and parent/class/file support record UID0004FV raw-helper non-merge; UID0004FV page was inspected and left unchanged because its no-function/no-xref proof was already present. |
| C7 | The old target no-code proof is stale because `NewArticleDialog` constructor and `MakeRect` support are now formal in [UID:00030K], and `PushDialog` is documented by DialogSession stack support. | Strong | NewArticleDialogCore formal C++; DialogSession stack docs. | Target C++ section; class/file support rows | incorporate | applied: target stale no-code proof replaced by Source-Quality Notes and formal C++; class/file support rows mark UID0004FW source-ready. |
| C8 | Target should become `88/91`, keep owner `00001D`, keep reconstructable true, and set `EMITTER_UIDS:00001D`. | Strong | by-structure code-entry gate; parent route `00001D -> 0000HX`; current body evidence. | Target metadata | incorporate | applied: target metadata now `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00001D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001D`, blank optional position. |
| C9 | [UID:00001D] class page needs child-emission support, preferably a marker-only class block with `[[CHILDREN]]`, before child output should be considered generated-route complete. | Medium-strong | Current `BulletinSession.cpp` generated output shows UID00001D as an empty emitter marker; analogous class pages use `[[CHILDREN]]`. | `by-class/BulletinSession.md` formal block/status | incorporate | applied: `by-class/BulletinSession.md` now contains the accepted marker-only `[[CHILDREN]]` block and status notes; validator `000000005693` accepted it. |
| C10 | `by-file/BulletinSession.md` and UID0000ZH parent rows are stale where they say UID0004FW remains blank/C++ blocked. | Strong | Current file/parent rows read during report. | `by-file/BulletinSession.md`; `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md` | incorporate | applied: parent child row and file proposed-contents row now identify UID0004FW as source-ready/emitting through [UID:00001D]. |
| C11 | `NewArticleDialogCore` already contains constructor/signature support at same-or-greater detail and need not be edited unless the supervisor wants an explicit caller note. | Strong | Read current [UID:00030K] page. | `by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md` | already-present | already-present: inspected during callback; constructor/signature/MakeRect support remains present, no contradiction found, file left untouched. |

## Positive Evidence Summary

- Direct facts supporting the recommendation: current MCP reports exact function size, clean padding, two direct code callers, no data route, exact callee list, and decompiled behavior that maps one-to-one to a compact source method.
- Corroborating documentation/generated-report evidence: UID0004FW already has the correct class owner; [UID:00030K] now has formal `NewArticleDialog` constructor C++; [UID:000132] documents stack push semantics; generated reports identify UID0004FW as a reconstructable non-emitter needing source-quality work.
- Strongest inference chain: callers pass a `BulletinSession` receiver and wide title/text pointer; target builds the correct compose-dialog bounds, constructs `NewArticleDialog(this,title,bounds)`, and pushes it through the session. That is a normal source method, not an unresolved raw helper.

## IDA MCP Facts

- Function/range facts: `lookup_funcs 0x004712f0` returns `sub_4712F0`, size `0xb6`; `analyze_function` reports size `182`, prototype `void __thiscall(void *this, const unsigned __int16 *)`, 10 basic blocks, and cyclomatic complexity `1`.
- Raw bytes: target bytes begin `55 8b ec 6a ff 68 a6 b0 5f 00 ...` and end `... 8b e5 5d c2 04 00`; pre/post bytes read as `0xcc` padding.
- Body facts: `byte_66DA97 == 1` selects `sub_4B7C50(v5, 10, 10, 461, 430)`; otherwise selects `sub_4B7C50(v5, 10, 10, 456, 376)`; allocates `0x274` / 628 bytes (Verified with int_convert.py); calls `sub_476C10` at `0x00471371`; pushes through `sub_4A0FC0` at `0x00471384`.
- Xref facts: `xrefs_to 0x004712f0` returns exactly `0x004740ad` from `sub_474020` and `0x00476800` from `sub_476740`; `xrefs_to 0x00476c10` returns `0x00471371` from this target; `xrefs_to 0x004a0fc0` includes this target at `0x00471384` among other session-dialog push sites.
- Negative IDA facts: `xref_query` finds no data xrefs to `0x004712f0`; `find_bytes` finds no absolute VA/RVA pointer patterns for the target start; `lookup_funcs 0x004712b0` reports not a function; `xrefs_to 0x004712b0` is empty.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004712b0-0x004712e5` | [UID:0004FV] `by-memory/0x004712b0-0x004712e5.BulletinSessionDialogRectRawNoRoute.md` | raw no-route rectangle helper pocket | false | NONE | `86/91` | Keep no-code; same coordinate logic but no function/xrefs |
| `0x004712f0-0x004713a6` | [UID:0004FW] `by-memory/0x004712f0-0x004713a6.BulletinSessionOpenNewArticleDialog.md` | `BulletinSession::OpenNewArticleDialog` | true | [UID:00001D] | recommend `88/91` | Make source-ready with formal C++ |
| `0x004713b0-0x00471476` | [UID:0004FX] `by-memory/0x004713b0-0x00471476.BulletinSessionOpenReplyDialog.md` | sibling reply dialog opener | true | [UID:00001D] | `84/90` current | Out of scope except boundary proof |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004740ad` | code xref from `sub_474020` / `ArticleListDialog::WriteNewArticle` | If the dialog's `+0x476` flag is clear, caller passes session pointer at `this+0x270` and wide text at `this+0x276` to open normal new-article composition. |
| `0x00476800` | code xref from `sub_476740` / `ArticleDialog::SubmitAction` | After reading control index `7` and popping current dialog, caller delegates to UID0004FW when its action-mode byte is clear; otherwise it sends opcode `0x3b` subcommand `8`. |
| `0x00471371` | call from UID0004FW to `sub_476C10` | Constructs `NewArticleDialog` with receiver/session, title pointer, and local bounds. |
| `0x00471384` | call from UID0004FW to `sub_4A0FC0` | Pushes the new dialog through the inherited `DialogSession` stack. |
| `0x004712b0` | zero xrefs and no function object | Adjacent raw helper remains no-code and is not the source route for this method. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target already assigns owner [UID:00001D] and describes `NewArticleDialog` construction plus `DialogSession` push.
  - [UID:00030K] now contains source-ready `NewArticleDialog` constructor and `MakeRect` conventions.
  - [UID:000132] documents `DialogSession::PushDialog` behavior and shared ownership.
  - ArticleListDialog and ArticleDialog docs name the two consumer flows and their caller roles.
- Historical docs that were stale, incomplete, or contradicted before callback:
  - Target no-code proof was stale because its named blockers were resolved for this exact method; callback replaced it with source-ready evidence and formal C++.
  - UID0000ZH, `by-class/BulletinSession.md`, and `by-file/BulletinSession.md` described UID0004FW as blank-emitter/C++ blocked; callback updated those rows/notes to source-ready.
  - Generated `auto-generated/NexusTK/ui/dialogs/BulletinSession.cpp` showed only empty markers before callback because the target had no emitter; scoped validators now report deferred generated refresh effects.
- Generated/coverage report state: generated reports remain read-only leads. B006 did not hand-edit them; scoped validators were run and reported validator-owned deferred generated refresh/projected stats/reference effects.

## Ranked Ownership Analysis

### 1. [UID:00001D] BulletinSession

- Evidence for: target `this` is a `BulletinSession`/`DialogSession` receiver; callers pass `BulletinSession` session pointers; target constructs a dialog owned elsewhere but controls session stack insertion; surrounding split parent and class/file docs already prove BulletinSession island ownership.
- Evidence against: exact original method name and class field names are inferred, not PDB-proven.
- Decision: direct owner and emitter parent for UID0004FW.

### 2. [UID:00008Y] NewArticleDialog / [UID:0000HT] BoardDialogs

- Evidence for: target constructs `NewArticleDialog`; callers are article-list/article-viewer classes under BoardDialogs.
- Evidence against: callee and caller modules do not own the session method. The target does not create NewArticleDialog controls itself; it only selects bounds, constructs, and pushes the dialog.
- Decision: support dependencies only. Do not move UID0004FW to BoardDialogs or NewArticleDialog.

### 3. [UID:00003U] DialogSession / [UID:0000IU] DialogSession

- Evidence for: target calls `PushDialog`.
- Evidence against: `PushDialog` is a shared callee. UID0004FW's source semantics are BulletinSession-specific article-compose routing.
- Decision: keep DialogSession as callee/support owner only.

### 4. NONE / raw helper / no-code

- Evidence for: previous split child stayed blank because formal declarations were not yet synchronized.
- Evidence against: current target is a modeled function with two direct callers, no route ambiguity, source-ready callees, and formal C++ can be represented without raw/decompiler scaffolding.
- Decision: reject no-owner/no-emitter/blank treatment for UID0004FW after this pass.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file. Use existing [UID:0000HX] `BulletinSession.cpp`.
- Likely full contents: `BulletinSession` class methods, singleton, packet forwarder/dispatcher, dialog-open helpers, and exact source-ready children as they become formal.
- Candidate related items that belong: UID0004FW now belongs as an emitted child; sibling open/dialog methods can be handled in later focused passes.
- Candidate related items rejected: NewArticleDialog body remains with BoardDialogs/NewArticleDialog; DialogSession stack helpers remain with DialogSession; raw rectangle helper remains no-code.
- Standalone, narrow, or broad source-file inference: narrow class method in the existing `BulletinSession.cpp` route.

## Source Placement

- Recommended source file/class/global/module placement: `BulletinSession::OpenNewArticleDialog` in `NexusTK/ui/dialogs/BulletinSession.cpp`, emitted through class [UID:00001D] to file [UID:0000HX].
- Why this placement fits source-tree and subsystem context: BulletinSession coordinates bulletin board/mail dialog stack flow and delegates concrete dialog bodies to BoardDialogs/MailDialogs. This target is a coordinator/open helper.
- Rejected placements and why: BoardDialogs/NewArticleDialog are callee/caller UI modules; DialogSession is a shared stack helper; a new file is unnecessary because BulletinSession already owns the class/source root.
- Remaining placement uncertainty: exact original header layout and whether the broader legacy source file was `BulletinSession.cpp` or a larger bulletin-dialog source remain unproven, but current by-file route is strong enough for emitted method C++.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: `0x004712f0-0x004713a6` is the exact modeled function; size `0xb6` / 182 bytes (Verified with int_convert.py). Padding `0xcc` appears before at `0x004712e5-0x004712f0` and after at `0x004713a6-0x004713b0`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new child pages. Leave [UID:0004FV] as no-code raw helper and [UID:0004FX] as separate sibling. Repair only UID0004FW and stale support rows after supervisor callback.
- Padding/table/data/code distinctions: UID0004FW is code; surrounding `0xcc` is alignment; no table/data lives in the target range.
- Parent/container impact: [UID:0000ZH] stays non-emitting split/index parent, but its UID0004FW row should change from blank/C++ blocked to source-ready child.

## Negative Evidence Summary

- No data xrefs to target start and no absolute VA/RVA byte-pattern route were found. This rejects vtable/function-pointer ownership and confirms the two direct code calls as the current route.
- No IDA function object or inbound xrefs exist at adjacent raw helper `0x004712b0`; this rejects merging UID0004FW into the raw helper or treating the raw helper as the actual callable source route.
- NewArticleDialog constructor ownership is not transferred to BulletinSession. The target owns only the open/push helper; the dialog body remains [UID:00008Y]/[UID:00030K].
- ArticleListDialog and ArticleDialog are consumers, not owners. Their direct calls prove reachability and title/text source, not canonical ownership.
- Raw/decompiler-shaped source is rejected: do not write `sub_4F4AA0`, `sub_476C10`, `sub_4A0FC0`, stack-cookie, SEH, or manual null-check/delete cleanup into formal source.
- Blank/no-code treatment is rejected for this exact child because formal target-specific source can now be supplied.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing name: `BulletinSession::OpenNewArticleDialog`.
- Proposed parameter: `const wchar_t *title`; `const unsigned __int16 *` is the decompiler view of the same wide text pointer.
- Proposed helper names used in formal source: `g_useEpfAssets`, `MakeRect`, `Rect`, `NewArticleDialog`, and `PushDialog`, following current accepted support docs.
- Items intentionally left unchanged: no IDA DB renames, type applications, comments, or process-management actions are requested.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested; this is documentation-only report work.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. After recommended metadata, UID0004FW will be reconstructable, have a nonblank emitter route through [UID:00001D], exceed the combined score gate, and have target-specific formal source supported by current docs and MCP.
- Recommended code: exact formal insertion text for the target page:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void BulletinSession::OpenNewArticleDialog(const wchar_t *title)
{
    Rect bounds;

    if (g_useEpfAssets == 1) {
        bounds = MakeRect(0x0a, 0x0a, 0x1cd, 0x1ae);
    } else {
        bounds = MakeRect(0x0a, 0x0a, 0x1c8, 0x178);
    }

    PushDialog(new NewArticleDialog(this, title, bounds));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: the source maps exactly to the current decompilation: asset-mode rectangle choice, allocation/construction of `NewArticleDialog`, and `DialogSession` push. Compiler-generated allocation null checks, SEH cleanup, and security cookie code should be regenerated by the compiler/toolchain.
- Reason it matches plausible mid-2000s developer source shape: it is a small class method that delegates to existing helper abstractions and constructor declarations rather than hand-authoring ABI scaffolding.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `g_useEpfAssets`, `Rect`, `MakeRect`, `NewArticleDialog`, and `PushDialog`.
- Naming/coding style convention used and evidence for consistency: CamelCase class/method names and `g_` global style match current `NewArticleDialogCore`, `BoardDialogs`, and `BulletinSession` docs.
- Reason code should remain blank, if applicable: not applicable for UID0004FW after this report. Blank treatment should be rejected.
- Exact no-code proof, if not eligible: not applicable. No-code proof remains valid for adjacent UID0004FV only.

## Final Recommendation

- Exact changes recommended:
  - Target: `COMPLETION:88`, `CONFIDENCE:91`, owner unchanged `00001D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001D`, blank optional position, formal C++ inserted.
  - Parent/class/file support: replace stale blank-blocker wording for UID0004FW with current source-ready evidence and route.
  - Class output support: add/repair a marker-only `[[CHILDREN]]` block for [UID:00001D] if absent, so child methods can emit through the class without pretending the full class declaration is final.
- Exact parent assignments recommended: direct owner [UID:00001D], source-file route [UID:0000HX].
- Exact items left no-owner/non-emitting and why: [UID:0004FV] remains no-owner/non-reconstructable raw helper because current MCP confirms no function and zero xrefs to start.
- Exact future work outside this assignment: sibling BulletinSession methods can be rechecked one at a time for source-ready C++, but this report only recommends UID0004FW.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004712f0-0x004713a6.BulletinSessionOpenNewArticleDialog.md`.
- Exact report facts to incorporate:
  - Current MCP session `d3e83820` health/session facts.
  - Modeled function at `0x004712f0`, size `0xb6` / 182 bytes (Verified with int_convert.py), clean `0xcc` padding before/after, direct callers `0x004740ad` and `0x00476800`, direct callee facts, no data xrefs, no VA/RVA pointer route.
  - Body behavior: EPF/legacy bounds via `g_useEpfAssets`, allocate/construct `NewArticleDialog`, push with `DialogSession::PushDialog`.
  - Caller behavior: ArticleListDialog write-new-article branch and ArticleDialog submit/reply branch pass a wide title/text pointer.
  - Rejected alternatives: raw no-route helper merge, NewArticleDialog/BoardDialogs/ArticleDialog/ArticleListDialog/DialogSession ownership, raw/decompiler C++, and blank/no-code treatment.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Set `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:00001D`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00001D`, keep `EMITTER_POSITION_OPTIONAL` blank, insert formal C++ from this report.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - The former B012 blank no-code proof was historically correct before declarations were synchronized; now it is stale for UID0004FW and should be replaced, not silently deleted.

## Recommended Support Doc Changes

- Support path: `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`.
  - Exact report facts to incorporate: update UID0004FW child row from blank/C++ blocked to source-ready `BulletinSession::OpenNewArticleDialog`, source-bearing, owner [UID:00001D], emitter [UID:00001D], formal C++ supplied, with current MCP body/caller evidence.
  - Metadata/link/score/coverage/source-placement changes: parent metadata should remain non-emitting `88/91`; only child-row/support text changes.
- Support path: `by-class/BulletinSession.md`.
  - Exact report facts to incorporate: update UID0004FW method note to source-ready; add current caller/body evidence at a concise support level; preserve that other sibling methods remain blank until separately accepted.
  - Formal class support if absent: add a marker-only child insertion block, not a partial class declaration:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID00001D BulletinSession class-level source is covered by UID0000HX BulletinSession and exact method/global children. This page emits no standalone partial class declaration until constructor, packet, field, and header declarations are source-quality.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

  - Metadata/link/score/coverage/source-placement changes: keep class owner/emitter route; score increase is optional and not required by this report.
- Support path: `by-file/BulletinSession.md`.
  - Exact report facts to incorporate: update the UID0004FW proposed-contents row from blank-emitter pending declarations to source-ready child emitted through [UID:00001D]; include the short body summary and note current route to `BulletinSession.cpp`.
  - Metadata/link/score/coverage/source-placement changes: keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and `CANONICAL_OWNER:FILE`.
- Support path: `by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md`.
  - Exact report facts to incorporate: already present at same-or-greater detail for constructor signature and `MakeRect`/bounds conventions. Inspect during callback and leave untouched unless a contradiction is found.
- Support path: `by-memory/0x004712b0-0x004712e5.BulletinSessionDialogRectRawNoRoute.md`.
  - Exact report facts to incorporate: already present for no-function/no-xref raw rectangle helper proof. Leave unchanged unless support wording implies it owns UID0004FW's route.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00001D`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
- Recommended score/metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00001D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001D`, blank optional position, formal C++ inserted.
- Score rationale and reason not higher/lower:
  - Raise completion because the report resolves the named C++ blockers, supplies formal source, records exact current MCP evidence, and defines support sync.
  - Raise confidence modestly because direct callers/body/callees are current-session verified and support declarations now exist.
  - Do not exceed `91` because exact original method/parameter/helper spelling and the broader `BulletinSession` header/class declaration are still inferred.
- Score-improvement attempt:
  - Checked target body and bytes: resolved.
  - Checked direct callers: resolved.
  - Checked constructor and push support: resolved.
  - Checked raw helper/split issue: resolved as no merge.
  - Checked emitter route: resolved with required class `[[CHILDREN]]` support sync.
- Metadata fields to change or leave unchanged: change only target scores/emitter/C++; keep owner/reconstructable/optional position.

## Open Questions With Attempted Resolution

- Exact original method name: no PDB/source symbol found. `OpenNewArticleDialog` is supported by behavior, filename, split report, and source family. It is safe for source-facing documentation.
- Exact parameter name: caller and constructor evidence support `title`; ArticleDialog sometimes passes user-entered text, but the `NewArticleDialog` constructor uses it as the title/static text argument. Keep `title`.
- Exact helper names: `MakeRect`, `PushDialog`, and `g_useEpfAssets` are accepted support names, not symbol-proof. Their use is safe in first-draft C++ and caps confidence rather than blocking.
- `BulletinSession` class/header declaration: not fully source-final. This blocks broad class C++, not this child method. Use class marker `[[CHILDREN]]`.
- Adjacent raw helper relationship: current MCP proves UID0004FV has no route to its start. It remains support/no-code, not a blocker for UID0004FW.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. Do not hand-edit auto-generated tracker or coverage reports. The implementation callback updated source by-* docs and ran scoped validators so validator-owned generated reports can refresh.

## Follow-Up Actions

- Supervisor action: Gate 2 review this implemented artifact; supervisor owns any later `execute_report` decision.
- A-agent action: none required from this B006 callback.
- B006 callback action: complete. Target metadata/C++, support sync rows/class marker, validators, and checklist/ledger updates are applied; B006 stopped before `execute_report`.

## Confidence

- Overall recommendation confidence: strong.
- Strongest facts: exact current MCP function body, direct callers, clean bounds, formal constructor support, and existing owner chain.
- Main caps: exact original source spellings and full `BulletinSession` declaration/source split remain inferred.

## Validator Results

- Target validator: `python .\tools\validator.py --mode file --file by-memory/0x004712f0-0x004713a6.BulletinSessionOpenNewArticleDialog.md --apply --queue-timeout 240`
  - First run `command_id: 000000005686`, `command_timestamp: 2026-07-03T17:34:23-04:00`, exit code `0`, `ok: 1`; produced completion/confidence/emitter/formal-block registry updates and a stale UID link correction side effect.
  - Corrective rerun after fixing NewArticleDialog support UID to [UID:00030K]: `command_id: 000000005687`, `command_timestamp: 2026-07-03T17:34:43-04:00`, exit code `0`, `ok: 1`; warnings/errors: none; `reference_index_remove 00041G`, `reference_index_add 00030K`; `generated_refresh: deferred`.
- Parent validator: `python .\tools\validator.py --mode file --file by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md --apply --queue-timeout 240`
  - `command_id: 000000005692`, `command_timestamp: 2026-07-03T17:38:00-04:00`, exit code `0`, `ok: 1`; warnings/errors: none; `generated_refresh: deferred`.
- Class validator: `python .\tools\validator.py --mode file --file by-class/BulletinSession.md --apply --queue-timeout 240`
  - `command_id: 000000005693`, `command_timestamp: 2026-07-03T17:38:06-04:00`, exit code `0`, `ok: 1`; warnings/errors: none; registry updated UID00001D from blank to block for the marker-only `[[CHILDREN]]`; `generated_refresh: deferred`.
- File validator: `python .\tools\validator.py --mode file --file by-file/BulletinSession.md --apply --queue-timeout 240`
  - `command_id: 000000005694`, `command_timestamp: 2026-07-03T17:38:17-04:00`, exit code `0`, `ok: 1`; warnings/errors: none; `generated_refresh: deferred`.
- Generated freshness observation: scoped validators reported projected stats/reference/registry updates and `generated_refresh: deferred`; B006 did not manually edit generated files, coverage reports, validator state, lifecycle/archive state, or supervisor ledgers.

## Changed Files

- Report changed file: `tools/leaser/Agents/Agent-B006/research/0004FW-BulletinSessionOpenNewArticleDialog-source-quality.md`.
- by-* docs changed:
  - `by-memory/0x004712f0-0x004713a6.BulletinSessionOpenNewArticleDialog.md`
  - `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`
  - `by-class/BulletinSession.md`
  - `by-file/BulletinSession.md`
- Inspected and left unchanged as already-present support: `by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md`; `by-memory/0x004712b0-0x004712e5.BulletinSessionDialogRectRawNoRoute.md`.
- Generated/coverage/validator/lifecycle/archive files manually changed by B006: none. Scoped validators reported deferred generated refresh/projected stats/reference/registry effects only.
- Leases used/released:
  - Target lease acquired for `by-memory/0x004712f0-0x004713a6.BulletinSessionOpenNewArticleDialog.md`, validated, and released before waiting on support files.
  - Initial support lease request for parent/class/file was rejected because B005 held short leases until `2026-07-03T21:36:31Z`; B006 waited until no active leases remained, then acquired and released leases for `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`, `by-class/BulletinSession.md`, and `by-file/BulletinSession.md`.
  - Post-release check: `current_leases.md` showed no active leases.

## Implementation Tracking Checklist

- [x] Target `by-memory/0x004712f0-0x004713a6.BulletinSessionOpenNewArticleDialog.md`: applied `COMPLETION:88`, `CONFIDENCE:91`, kept `CANONICAL_OWNER:00001D`, kept `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00001D`, kept optional position blank; validator `000000005687` ok.
- [x] Target C++: applied exact `BulletinSession::OpenNewArticleDialog(const wchar_t *title)` formal `RECONSTRUCTION_CPP CODE` block from this report; validator `000000005687` ok.
- [x] Target evidence: applied MCP session `d3e83820`, exact range/size/padding, behavior, direct callers, callee list, data/pointer negative evidence, UID0004FV rejection, and support-declaration resolution to target Item Summary/Evidence/Source-Quality Notes.
- [x] Target rejected alternatives: applied rejection of NewArticleDialog/BoardDialogs/ArticleDialog/ArticleListDialog/DialogSession ownership, raw helper merge, decompiler-shaped source, and blank/no-code treatment in target Source-Quality Notes.
- [x] Support `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`: applied only UID0004FW row/support text and source-ready exception notes; parent metadata stayed non-emitting/unchanged; validator `000000005692` ok.
- [x] Support `by-class/BulletinSession.md`: applied UID0004FW method note and concise evidence; added marker-only `[[CHILDREN]]` block; sibling blank dispositions preserved; validator `000000005693` ok.
- [x] Support `by-file/BulletinSession.md`: applied UID0004FW proposed-contents/source-route note as source-ready emitted child through [UID:00001D]; validator `000000005694` ok.
- [x] Inspected/marked already-present `by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md`: constructor/signature/MakeRect support already present at same-or-greater detail; no contradiction found; not edited.
- [x] Inspected/marked already-present `by-memory/0x004712b0-0x004712e5.BulletinSessionDialogRectRawNoRoute.md`: no-function/no-xref raw helper proof already present and no ownership/emission contradiction found; not edited.
- [x] Ran scoped validators for every edited by-* file from `source-3/project-documentation`; command IDs `000000005687`, `000000005692`, `000000005693`, and `000000005694` are the final clean validation set.
- [x] Did not manually edit generated reports, project-level generated files, manual `-coverage-report.md` files, validator state, lifecycle/archive state, supervisor ledgers, or report registry files; no execute/lifecycle/archive command was run.
- [x] Used leases only immediately before by-* edits and released immediately after the edit/validator batch; post-release `current_leases.md` showed no active leases.
- [x] Updated this report's Claim And Incorporation Ledger and Implementation Tracking Checklist with `applied` / `already-present` proof for every accepted claim; no accepted item remains blocked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000005697","destination_path":"executed-b-agent-research/B006/0004FW-BulletinSessionOpenNewArticleDialog-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0004FW-BulletinSessionOpenNewArticleDialog-source-quality.md","timestamp":"2026-07-03T17:51:16-04:00","uid":"0004FW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
