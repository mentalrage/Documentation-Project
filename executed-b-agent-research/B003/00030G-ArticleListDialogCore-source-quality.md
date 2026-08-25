** TARGET-REPORT-UID:00030G **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 00030G ArticleListDialogCore Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00030G] `0x00472c00-0x004748ea.ArticleListDialogCore` assigned to direct owner/emitter [UID:00000K] `ArticleListDialog`, with source routing through [UID:0000HT] `BoardDialogs`.
- Final disposition: report-only source-quality pass. Do not split, reroute, or enter aggregate C++ in this phase. The report should be incorporated into the target and support docs because live MCP now recovers the local raw helper bodies and narrows the remaining blockers.
- Required action if accepted: update `00030G`, `ArticleListDialog`, and `BoardDialogs` with the raw helper roles, parser/dispatcher names, score rationale, rejected alternatives, and no-partial-C++ proof below. Support `ArticleListPane`/`00030I` only needs a cross-reference if the supervisor wants the producer/consumer row-layout notes synchronized again.
- Confidence: high for ownership, source route, function/raw boundaries, row producer order, and no-direct-xref evidence; medium-high for helper source-facing names; medium for opcode `0x3b` subcommand `7` semantics and final original `BoardDialogs.cpp` versus `ArticleDialogs.cpp` partition.

## Target

- Target UID: `00030G`
- Target path: `by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md`
- Assignment: `B003-report-00030G-ArticleListDialogCore-20260702`
- Queue source: `auto-generated/-ag-research-tracker.md`, by-memory not-covered reconstructable row, assigned as `85/88`, reports `0`.
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00000K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000K`.
- Current formal C++: marker-only comment saying the range is covered through `ArticleListDialog`/`BoardDialogs` and should not emit a partial aggregate body yet.

## Current Target State

- Existing owner/emitter state is correct. `ArticleListDialog` owns the method/helper cluster, and the class emits through the `BoardDialogs` file bucket.
- Existing body notes already identify constructor/setup, read request, command dispatch, list update parser, server alert refresh, and the adjacent shared article-navigation helper.
- Existing blockers are partly stale. Raw helper body recovery is no longer a broad blocker after current-session MCP disassembly. The remaining blockers are exact original source spellings, subcommand `7` meaning, synchronized packet/control/ListPane declarations, and final board/article source split.
- Current generated output at `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp` was read as validator-generated only. Header: `validator-command-id: 000000004499`, `validator-refreshed-at: 2026-07-02T13:36:38-04:00`. UID00030G currently emits only the accepted marker comment.

## Supervisor Active Recheck

- The user assigned B003 to produce a report only for UID00030G.
- No by-* docs, generated files, coverage reports, validator state, queues, archives, supervisor ledgers, or target/support docs were edited.
- No leases were needed or taken.
- MCP was available. Current endpoint `http://127.0.0.1:13337/mcp` initialized successfully, `tools/list` was checked, and active session `supervisor_resume_20260629` was used.
- MCP health: `status: ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

## Inference Research Guidance Check

- `by-structure.md` requires the direct semantic owner, not just a broad file root. The constructor vtable stores and method cluster prove class ownership, while `BoardDialogs` remains the source-file route.
- Direct IDA/MCP facts, current documentation facts, and inference are separated below.
- Generated output and historical recovered-source names were treated as leads only. The local `source-3/simroot_v2` folder was absent in this workspace, so no generated source file was used as proof.
- No Wave2/Wave3 artifact was used as authority.

## Evidence Checked

MCP calls against session `supervisor_resume_20260629`:

- `initialize`, `tools/list`, `idb_list`, `server_health`
- `lookup_funcs` for raw/model starts `0x00472c00`, `0x00472ca0`, `0x00473990`, `0x004739b0`, `0x00473aa0`, `0x00473bc0`, `0x00473ce0`, `0x00473d30`, `0x00473dc0`, `0x00473e00`, `0x00474020`, `0x004740d0`, `0x00474170`, `0x00474230`, `0x00474470`, `0x004746b0`, `0x004747d0`, and successor `0x004748f0`.
- `entity_query kind=functions` bounded to `0x00472c00-0x004748f0`.
- `xrefs_to` for the six raw starts, `0x00472ca0`, `0x00613dac`, `0x004748f0`, and `0x004751c0`.
- `xref_query direction=both` for the six raw starts.
- `disasm` for raw starts `0x00472c00`, `0x00473990`, `0x00473aa0`, `0x00473bc0`, `0x00473ce0`, and `0x00473d30`.
- `analyze_function` for `0x00472ca0`, `0x004739b0`, `0x00473dc0`, `0x00473e00`, `0x00474230`, `0x00474470`, and `0x004747d0`.

Docs and reports checked:

- `goal.md` and `notes.md` for Agent-B003.
- Project skill references: `b-agent-research-and-implementation-workflow.md`, `b-agent-report-template.md`, and `score-blocker-audit-standard.md`.
- `by-structure.md`.
- Target `00030G`, support docs `ArticleListDialog`, `ArticleListPane`, `BoardDialogs`, `00030I`, `00030H`, `0000ZK`, and `BoardArticleDialogVtableFamily`.
- Generated tracker/coverage rows: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and generated `BoardDialogs.cpp`.
- Prior report searches used terms `00030G`, `0x00472c00-0x004748ea`, `ArticleListDialogCore`, `ArticleListDialog`, `BoardDialogs`, `sub_472CA0`, `sub_473E00`, and `sub_474470`. Relevant leads opened: B001 `0000ZK-BoardArticleDialogs`, B009 `0000HT-BoardDialogs-empty-emitter-family-source-quality`, B001/B014 `00030I-ArticleListPaneCore-source-quality`, and B002 `000133-screen-dimmer-factory-source-quality` hit for `sub_473E00`.

## IDA MCP Facts

- `lookup_funcs` confirms modeled functions at `0x00472ca0`, `0x004739b0`, `0x00473dc0`, `0x00473e00`, `0x00474020`, `0x004740d0`, `0x00474170`, `0x00474230`, `0x00474470`, `0x004746b0`, and `0x004747d0`.
- `lookup_funcs` reports `0x00472c00`, `0x00473990`, `0x00473aa0`, `0x00473bc0`, `0x00473ce0`, and `0x00473d30` as not function starts.
- Bounded `entity_query` over `0x00472c00-0x004748f0` returns only those modeled function starts plus successor `0x004748f0`.
- `xrefs_to` raw starts `0x00472c00`, `0x00473990`, `0x00473aa0`, `0x00473bc0`, `0x00473ce0`, and `0x00473d30` returns zero inbound xrefs. `xref_query direction=both` returns only each raw instruction head's fall-through, not external callers.
- `xrefs_to 0x00472ca0` returns constructor callers `0x00471695` and `0x004719e1` from `BulletinSession` code.
- `xrefs_to 0x00613dac` returns the primary `ArticleListDialog` vtable store at `0x00472cfd` inside `sub_472CA0`.
- `xrefs_to 0x004748f0` returns pane construction calls at `0x00472e04` and `0x00473410` inside the constructor/setup.
- `xrefs_to 0x004751c0` returns seven callers/refs: `0x00473df6`, `0x00474d91`, `0x00474dea`, `0x004771a2`, `0x00478232`, `0x00479031`, and `0x004790f1`. This preserves `00030H` as shared file-level support, not an ArticleListDialog child.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00472c00-0x004748ea` | [UID:00030G] target | ArticleListDialog method/raw-helper cluster | true | [UID:00000K] `ArticleListDialog` | `85/88` current, recommend `88/89` after incorporation | Keep exact range and route. |
| `0x00472c00-0x00472c9f` | in target | raw initial/newest page request helper | true | [UID:00000K] | included | Sends opcode `0x3b`, subcmd `2`, board id, `0x7fff`, and EPF/legacy page offset. |
| `0x00472ca0-0x0047398d` | in target | constructor/setup and initial list parser | true | [UID:00000K] | included | Constructor callers/vtable stores/pane construction prove ownership. |
| `0x00473990-0x004739ac` | in target | title/text forwarding helper | true | [UID:00000K] | included | `_wcscpy_s` into `this + 0x276`; no inbound xrefs. |
| `0x004739b0-0x00473a96` | in target | selected article read request | true | [UID:00000K] | included | Sends opcode `0x3b`, subcmd `3`, board id, selected article id, trailing `0`, length `7`. |
| `0x00473aa0-0x00473bbc` | in target | selected article subcommand-7 requests | true | [UID:00000K] | included | Iterates selected pane rows and sends opcode `0x3b`, subcmd `7`, board id, article id, length `6`; semantic name remains unresolved. |
| `0x00473bc0-0x00473cdc` | in target | selected article delete requests | true | [UID:00000K] | included | Same selected-row loop but subcmd `5`, length `6`; delete semantics supported by command/alert flow. |
| `0x00473ce0-0x00473d22` | in target | remove article entry by id and refresh | true | [UID:00000K] | included | Finds row through `ArticleListPane::FindArticleById`, removes one item, then calls virtual refresh at `+0x4c`. |
| `0x00473d30-0x00473db4` | in target | remove selected article entries and refresh | true | [UID:00000K] | included | Gets up to `0x100` selected row indices and removes each adjusted by prior removals. |
| `0x00473dc0-0x00473dfc` | in target | newest/refresh page navigation caller | true | [UID:00000K] | included | Calls shared `0x004751c0(boardId, 0x7fff, offset)`. |
| `0x00473e00-0x00473ff3` plus `0x00473ff3-0x00474014` | in target | command dispatcher plus owned jump table | true | [UID:00000K] | included | Vtable slot/data xref at `0x00613df4`; cases invoke read, new article, close, confirm delete, delete/session actions, and subcmd `7` selected requests. |
| `0x00474020-0x004740c1` | in target | write/new article action | true | [UID:00000K] | included | Existing docs sufficient; not re-decompiled in detail. |
| `0x004740d0-0x00474166` | in target | article-list command helper | true | [UID:00000K] | included | Existing role remains source-facing unresolved. |
| `0x00474170-0x0047422d` | in target | button-state updater | true | [UID:00000K] | included | Existing role remains valid. |
| `0x00474230-0x00474461` | in target | server-message dispatcher | true | [UID:00000K] | included | Routes subcmd `2` to list update, subcmd `7/8` to alert/new page paths, otherwise returns false. |
| `0x00474470-0x004746ac` | in target | article-list update parser | true | [UID:00000K] | included | Parses status byte, article id, title, month, day, author, clears pane `m_pageRequestPending`, then calls `AddArticleEntry`. |
| `0x004746b0-0x004747cb` | in target | alert/refresh helper | true | [UID:00000K] | included | Calls `0x00473dc0` as refresh/navigation after server alert flow. |
| `0x004747d0-0x004748ea` | in target | delete/reply alert construction helper | true | [UID:00000K] | included | Decodes alert text and constructs `DeleteReplyAlert` when singleton is absent; no inbound xrefs. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00471695`, `0x004719e1` | refs to `0x00472ca0` | `BulletinSession` constructs ArticleListDialog. |
| `0x00472cfd` | data ref to vtable `0x00613dac` | Primary ArticleListDialog vtable store. |
| `0x00472e04`, `0x00473410` | refs to `0x004748f0` | ArticleListDialog creates ArticleListPane. |
| `0x00473e4a` and `0x00474f7e` | refs to `0x004739b0` | Dispatcher and ArticleListPane activation route call selected-read request. |
| `0x00474358`, `0x004747a6` | refs to `0x00473dc0` | Server message and alert/refresh helper request newest/refresh page. |
| `0x00613df4` | data ref to `0x00473e00` | Command dispatcher vtable slot. |
| `0x0047443e` | ref to `0x00474470` | Server message dispatcher routes list update to parser. |
| `0x00473df6` | ref to `0x004751c0` | ArticleListDialog uses shared page helper. |
| raw helper starts | zero inbound xrefs | Bodies are source-shaped but not directly address-taken/called in IDA metadata. |

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Decision / best inference | Rejected alternatives / remaining cap |
| --- | --- | --- | --- |
| Direct owner | Constructor callers, vtable store, pane construction, support class docs | Keep `CANONICAL_OWNER:00000K`, `EMITTER_UIDS:00000K`. | Reject `BoardDialogs` as direct owner because class page is narrower and clears gate. Reject `ArticleListPane` because pane is constructed/controlled, not owner of dialog methods. |
| Source route | `ArticleListDialog -> BoardDialogs`, vtable family, `0000ZK`, generated `BoardDialogs.cpp` | Keep route through `BoardDialogs`; note possible future `ArticleDialogs.cpp` split only as source-tree refinement. | Do not create or recommend a new file solely for this target during this pass. |
| Raw helper reachability | `lookup_funcs`, `xrefs_to`, `xref_query`, `disasm` for raw starts | Raw helpers are source-bearing ArticleListDialog local methods/helpers with no direct inbound route; recover body roles in the docs. | Do not claim dead code. No inbound xref does not override vtable/dispatcher/control-flow locality. |
| `0x00472c00` | Raw disassembly | Best name: `RequestNewestArticlePage` / `SendInitialArticlePageRequest`; sends opcode `0x3b`, subcmd `2`, board id argument, `0x7fff`, EPF/legacy offset, length `7`. | Not padding; not a constructor prelude. Exact original name unproven. |
| `0x00473990` | Raw disassembly | Best name: `CopyArticleDialogText` or `SetArticleListDialogText`; `_wcscpy_s` to `this + 0x276`. | Avoid overclaiming field name until class layout is synchronized. |
| `0x00473aa0` | Raw disassembly and dispatcher case 8 | Best name: `SendSelectedArticleSubcommand7Requests`; selected rows, board id from pane `+0x14c`, article id from row, opcode `0x3b`, subcmd `7`, length `6`, then session/UI update. | Do not invent final semantic name. Subcmd `7` remains protocol-meaning unresolved. |
| `0x00473bc0` | Raw disassembly | Best name: `SendSelectedArticleDeleteRequests`; selected rows, opcode `0x3b`, subcmd `5`, board id/article id, length `6`. | Delete semantics are strong, but exact original name still inferred. |
| `0x00473ce0` | Raw disassembly | Best name: `RemoveArticleEntryById`; it resolves control `7`, finds article id, removes one row, and refreshes. | Reject generic "selected-control action helper"; body is concrete row removal. |
| `0x00473d30` | Raw disassembly | Best name: `RemoveSelectedArticleEntries`; selected-index buffer, remove with index-minus-removed-count, refresh. | Reject text/packet helper; no packet writes in sampled body. |
| Command dispatcher | `analyze_function 0x00473e00` | `OnControlCommand` dispatches command ids: read, write, close/session, confirm-delete alert allocation, delete/session action, and subcmd `7` selected requests. Switch table bytes belong to this dispatcher. | Do not split jump table as standalone source item. |
| List-update parser | `analyze_function 0x00474470`, `00030I` support docs | Parser row order is status byte, article id, title, month, day, author; it clears pane `+0x14e` before adding rows. | Reject generated date-byte names `readStatus`/`replyFlag`; keep first byte neutral. |
| Final C++ | Current marker, raw helper recovery, declaration gaps | Keep marker-only C++. Future C++ is viable as full aggregate or exact helper split after declaration synchronization. | Reject modeled-method-only partial aggregate C++; it would hide raw helper obligations and unresolved protocol names. |

## Positive Evidence Summary

- Direct IDA facts prove the class: `0x00472ca0` has BulletinSession callers, writes `ArticleListDialog` vtables, and constructs ArticleListPane twice.
- Direct IDA facts prove exact raw/model split: six local raw starts are executable source-shaped bodies with no function objects, while the known modeled functions cover the rest of the range.
- Direct disassembly now recovers the raw helper roles enough to update source-quality docs: page request, text copy, selected subcmd `7`, selected delete, remove-by-id, and remove-selected.
- Documentation facts from `00030I` and `ArticleListPane` support the parser field order and `m_boardId` / `m_pageRequestPending` naming.

## Negative Evidence Summary

- No raw helper start has inbound xrefs in `xrefs_to`; `xref_query` only shows fall-through heads. That caps reachability confidence and argues against formal C++ until helper policy is synchronized.
- `0x004751c0` has seven cross-class callers, so shared navigation helpers must remain [UID:00030H] / `BoardDialogs`, not folded into ArticleListDialog.
- The first status byte's exact read/unread or type/color polarity remains unproven. Keep `statusByte` / `articleStatusByte`.
- Subcmd `7` has packet behavior but no proven source/user semantic. Keep conservative naming.
- No PDB/source names, local variable names, custom type definitions, or comments were exposed by MCP.

## Ranked Ownership Analysis

### 1. [UID:00000K] ArticleListDialog

- Evidence for: constructor callers from BulletinSession, vtable stores at `0x00472cfd/0x00472d03/0x00472d0d`, ArticleListPane construction at `0x00472e04/0x00473410`, dispatcher/list parser/server-message methods, class docs, and vtable-family docs.
- Evidence against: final class declaration and helper names are not source-final.
- Decision: keep as direct owner/emitter.

### 2. [UID:0000HT] BoardDialogs

- Evidence for: correct file bucket for board/article dialog family and current generated file route.
- Evidence against: too broad for direct semantic ownership of class methods.
- Decision: keep as source file route only.

### 3. [UID:00000L] ArticleListPane

- Evidence for: dialog accesses pane control `7`, constructs it, and parses rows for it.
- Evidence against: pane is a controlled child/consumer; the target writes dialog state and dispatches dialog actions.
- Decision: reject as owner; use as support/consumer evidence.

### 4. [UID:00030H] ArticleNavigationHelpers

- Evidence for: dialog calls shared helper at `0x00473df6`.
- Evidence against: helper has cross-class fanout and a separate exact page.
- Decision: reject merge or ownership transfer.

## Source Placement

- Recommended source placement: keep `ArticleListDialog` under `BoardDialogs` for now, likely in a future `BoardDialogs.cpp` / `ArticleDialogs.cpp` partition.
- Why it fits: the range sits inside the board/article dialog address cluster and depends on BulletinSession, ArticleListPane, shared article navigation, and board/article alerts.
- Rejected placements: `ListPane.cpp` because only shared pane infrastructure belongs there; `BulletinSession.cpp` because the session constructs/routs dialogs but does not own their bodies; `ArticleListPane` because pane methods are separate.
- Remaining uncertainty: final original source file split among `BoardDialogs.cpp`, `ArticleDialogs.cpp`, and related alert files remains inferred.

## Range / Split / Padding / Reclassification Analysis

- Keep the current target range `0x00472c00-0x004748ea`.
- Keep `0x00473ff3-0x00474014` documented as switch table data owned by `0x00473e00`.
- No mandatory child split is required for ownership. Optional helper children could improve review granularity for `0x00472c00`, `0x00473990`, `0x00473aa0`, `0x00473bc0`, `0x00473ce0`, and `0x00473d30`, but this report recommends documentation updates first because every raw helper is class-local and no alternate owner is proven.
- Keep successor `0x004748f0` on [UID:00030I] and shared helper `0x004751c0` on [UID:00030H].

## First-Draft C++ Recommendation

- Eligible for draft C++ by minimum score/emitter gate: yes, current `(85 + 88) / 2 > 85` and emitter route is valid.
- Recommended code: keep the existing formal marker-only block. Do not add body C++ in this pass.
- Reason code should remain blank: although raw helper bodies are now recovered at source-quality summary level, a correct aggregate draft needs synchronized class fields (`+0x1fc`, `+0x270`, `+0x276`, `+0x624`), control id `7` typing, packet helper declarations, `ArticleListPane` API names, `ConfirmDeleteAlert` / `DeleteReplyAlert` constructors, shared navigation helper declaration, and a decision for subcmd `7` naming. A partial body for only modeled functions would misrepresent the whole by-memory range.
- Exact no-code proof: UID00030G should continue emitting only the marker comment already present in the formal block until either a full coherent `ArticleListDialogCore` draft is prepared or exact helper children are split and individually source-shaped.

## Score And Metadata Recommendation

- Current score/metadata: `85/88`, owner/emitter `00000K`, reconstructable `TRUE`.
- Recommended metadata after accepted incorporation: keep owner/emitter/reconstructable unchanged; raise to `COMPLETION:88`, `CONFIDENCE:89`.
- Rationale for `88` completion: current MCP resolves the main named blocker "raw helper body roles" and documents parser/dispatcher/helper roles at implementation-ready detail. Completion should not exceed `88` because formal C++ remains marker-only, class field declarations are not synchronized, and subcmd `7` semantics remain unresolved.
- Rationale for `89` confidence: direct IDA facts now support the raw helper roles, xref negatives, vtable ownership, pane construction, shared helper separation, and row producer order. Confidence should stay below `90+` because exact source names and original source split remain inferred.
- If the supervisor decides score movement should wait for by-* incorporation, apply the details first and then raise in the same callback.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md`
- Incorporate current MCP session state and bounded call list.
- Update `Covered Range` roles for raw helpers:
  - `0x00472c00`: `SendInitialArticlePageRequest` / `RequestNewestArticlePage` packet helper.
  - `0x00473990`: `_wcscpy_s` text copy into `this + 0x276`.
  - `0x00473aa0`: selected article subcmd `7` request loop.
  - `0x00473bc0`: selected article delete request loop.
  - `0x00473ce0`: remove article entry by id and refresh.
  - `0x00473d30`: remove selected article entries and refresh.
- Add dispatcher and parser detail from `analyze_function 0x00473e00`, `0x00474230`, and `0x00474470`.
- Preserve negative evidence: zero inbound xrefs for raw starts, no PDB/source names, and shared `0x004751c0` fanout.
- Update score rationale and no-partial-C++ proof if accepted.

## Recommended Support Doc Changes

- `by-class/ArticleListDialog.md`: add the same raw helper role names, update the class C++ caveat so "raw-helper reachability" becomes "no-direct-route plus exact helper names/subcmd 7/declaration synchronization", and update score if accepted.
- `by-file/BoardDialogs.md`: update the ArticleListDialog proposed-content row / empty-emitter disposition to say UID00030G raw bodies are now role-recovered by B003 MCP, but marker-only C++ remains correct pending full aggregate or splits.
- `by-class/ArticleListPane.md` and `by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md`: optional support sync only. If edited, add that ArticleListDialogCore raw helpers `0x00473aa0/0x00473bc0/0x00473ce0/0x00473d30` operate through ArticleListPane control `7`, board id `+0x14c`, selected rows, `FindArticleById`, and remove-item APIs; no metadata change required.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00030G-001 | UID00030G owner/emitter remains `ArticleListDialog` / `ArticleListDialog`, routed through `BoardDialogs`. | High | Constructor callers, vtable store, pane construction, support docs. | `00030G` metadata/status, `ArticleListDialog`, `BoardDialogs` | already-present | already-present: `00030G` retained `CANONICAL_OWNER:00000K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000K`; class/file support pages retain [UID:0000HT] route. |
| C-00030G-002 | `0x00472c00` sends opcode `0x3b`, subcmd `2`, board id, `0x7fff`, EPF/legacy offset, length `7`. | High | MCP `disasm 0x00472c00`. | `00030G` Covered Range/Evidence | incorporate | applied: target Covered Range and Evidence now document `SendInitialArticlePageRequest` / `RequestNewestArticlePage`, opcode/subcmd/length, no inbound xrefs, and session proof. |
| C-00030G-003 | `0x00473990` is a tiny text-copy helper into `this + 0x276`, not padding. | High | MCP `disasm 0x00473990`. | `00030G` Covered Range/Evidence | incorporate | applied: target Covered Range and class Method Notes document `CopyArticleDialogText` / `SetArticleListDialogText`, `_wcscpy_s`, `this+0x276`, and no-direct-route evidence. |
| C-00030G-004 | `0x00473aa0` sends selected article subcmd `7` requests; final semantic name remains unresolved. | High for packet shape, medium for name | MCP `disasm 0x00473aa0`; dispatcher case 8. | `00030G`, `ArticleListDialog` | incorporate | applied: target and class support docs document selected-row subcommand-`7` packet shape, dispatcher/control route, and evidence-backed unresolved semantics with score/C++ impact. |
| C-00030G-005 | `0x00473bc0` sends selected article delete subcmd `5` requests. | High | MCP `disasm 0x00473bc0`; delete command/alert context. | `00030G`, `ArticleListDialog` | incorporate | applied: target Covered Range and class Method Notes document `SendSelectedArticleDeleteRequests`, opcode `0x3b`, subcmd `5`, board id/article id, length `6`. |
| C-00030G-006 | `0x00473ce0` removes one article entry by id; `0x00473d30` removes selected entries. | High | MCP raw disassembly. | `00030G`, optional `ArticleListPane` support | incorporate | applied: target and class support docs document `RemoveArticleEntryById` and `RemoveSelectedArticleEntries`; optional pane docs were not edited because class/target/file destinations now carry the producer-side detail without needing consumer-page consistency changes. |
| C-00030G-007 | Raw starts have no inbound xrefs; this is a confidence/source-shape cap, not dead-code proof. | High | MCP `xrefs_to` and `xref_query`. | `00030G` Negative Evidence/Score | incorporate | applied: target Evidence/Source-Quality Reanalysis and class Source-Quality Notes document zero inbound xrefs/no-direct-route as a source-shape cap, not dead-code proof. |
| C-00030G-008 | Parser row order remains status byte, article id, title, month, day, author; first status byte stays neutral. | High for order, medium for status meaning | MCP `analyze_function 0x00474470`; `00030I` docs. | `00030G`, `ArticleListDialog` | incorporate | applied: target Covered Range/Evidence and class Article Row Producer Notes preserve parser order, pending-byte clear, and neutral status-byte language. |
| C-00030G-009 | Keep marker-only C++; do not add a partial aggregate body yet. | High | Current generated output, B009, current declaration gaps. | `00030G` C++ guidance/formal block | already-present/incorporate rationale | already-present and applied rationale: target formal block remains marker-only; target Reconstruction Guidance, class Source-Quality Notes, and BoardDialogs disposition explain the no-partial-C++ proof. |
| C-00030G-010 | Recommended score after incorporation is `88/89`, owner/emitter unchanged. | Medium-high | Resolved raw body blocker plus remaining source-name/C++ caps. | `00030G` metadata and score rationale | incorporate | applied: target header raised from `85/88` to `88/89`; owner/emitter/reconstructable unchanged; Score Rationale updated. |

## Open Questions With Attempted Resolution

- Subcmd `7` meaning: MCP proves packet shape and selected-row loop, but no user-visible/server semantic or source enum name was recovered. Keep descriptive `SendSelectedArticleSubcommand7Requests`.
- Field `this + 0x276`: MCP proves text copy destination, but not final class field name. Document as a title/text buffer pending class layout sync.
- Class fields/control names: `+0x1fc`, `+0x270`, and `+0x624` are used by the dialog helpers but need a broader `DialogInSession`/control declaration pass before C++.
- Original file split: current route through `BoardDialogs` is correct; final `ArticleDialogs.cpp` split remains a project source-tree question.

## Validator Results

- `python .\tools\validator.py --mode file --file by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md --apply --queue-timeout 240`
  - `command_id: 000000004529`
  - `command_timestamp: 2026-07-02T14:09:15-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Validator-applied effects: `completion_update 00030G 88`, `confidence_update 00030G 89`, projected stats update, and stats-row removal/rescore recommendation for `project-level/-auto-completion-stats.md`.
- `python .\tools\validator.py --mode file --file by-class/ArticleListDialog.md --apply --queue-timeout 240`
  - `command_id: 000000004531`
  - `command_timestamp: 2026-07-02T14:09:20-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Validator-applied effects: projected stats update, reference index add for `00030H`, three stats row updates for `00000K`, and two UID link label normalizations for [UID:00030H].
- `python .\tools\validator.py --mode file --file by-file/BoardDialogs.md --apply --queue-timeout 240`
  - `command_id: 000000004532`
  - `command_timestamp: 2026-07-02T14:09:31-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Validator-applied effects: projected stats update, `stats_incremental_noop 0000HT`, and one UID link label normalization for [UID:00030H].
- Generated refresh state:
  - All three validators reported `generated_refresh: deferred`.
  - Queue status check `command_id: 000000004533`, `command_timestamp: 2026-07-02T14:09:44-04:00`, reported worker running, `0` queued jobs, `0` processing jobs, `0` queued generated refresh jobs, and `0` processing generated refresh jobs.
  - `auto-generated/-ag-memory-coverage.md` header is refreshed at `validator-command-id: 000000004529`, `validator-refreshed-at: 2026-07-02T14:09:15-04:00`.
  - `auto-generated/-ag-research-tracker.md` header is refreshed at `validator-command-id: 000000004532`, `validator-refreshed-at: 2026-07-02T14:09:31-04:00`.
  - `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp` header is refreshed at `validator-command-id: 000000004532`, `validator-refreshed-at: 2026-07-02T14:09:31-04:00`; generated UID00030G output is still marker-only and now reports `Completion:88 | Confidence:89`.
- No report execution/archive command was run.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/00030G-ArticleListDialogCore-source-quality.md`
- Modified by callback:
  - `by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md`
  - `by-class/ArticleListDialog.md`
  - `by-file/BoardDialogs.md`
  - `tools/leaser/Agents/Agent-B003/research/00030G-ArticleListDialogCore-source-quality.md`
- Validator-owned generated/projected updates observed and not manually edited: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-research-tracker.md`, `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp`, and `project-level/-auto-completion-stats.md`.
- Leases: B003 leased `by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md`, `by-class/ArticleListDialog.md`, and `by-file/BoardDialogs.md` for the immediate edit/validator batch. Release attempt after validators returned `Rejected[No active lease]` for the target and class files and `Rejected[Lease owned by B004]` for `BoardDialogs.md`; the shared lease report then showed no active B003 leases, with `BoardDialogs.md` newly leased by B004 from `2026-07-02T18:10:31Z` to `2026-07-02T18:15:31Z`.
- Report execution: not run. Supervisor-only after validation, callback implementation, and independent verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor returned `ACCEPTED FOR IMPLEMENTATION CALLBACK` for Agent-B003 / UID00030G.
- [x] Target doc `by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md`: incorporate MCP session state, raw helper roles, parser/dispatcher facts, negative xref evidence, score rationale, and no-partial-C++ proof. Proof: target Item Summary, Covered Range, Evidence, Source-Quality Reanalysis, Reconstruction Guidance, Score Rationale, and Changes now carry those details.
- [x] Support doc `by-class/ArticleListDialog.md`: incorporate source-facing helper names/roles, packet/list-entry field updates, score/C++ caveat, and rejected alternatives. Proof: Method Notes, Evidence Notes, Source-Quality Notes, Score Rationale, and Changes updated; validator normalized two UID link labels only.
- [x] Support doc `by-file/BoardDialogs.md`: update ArticleListDialogCore row/source-disposition note with B003 raw helper recovery and unchanged marker-only C++. Proof: Empty Emitter Family Source Disposition, Proposed Contents `ArticleListDialog` row, and Changes updated; validator normalized one UID link label only.
- [x] Optional support sync for `by-class/ArticleListPane.md` and `by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md`: add producer/dialog-side raw helper cross-reference if supervisor wants consumer docs refreshed. Proof: excluded-with-reason; accepted scope marked these optional only if needed, and target/class/file docs now preserve the producer-side helper facts without changing pane consumer semantics.
- [x] Claim And Incorporation Ledger updated with destination and report-only `proposed` state for every accepted claim. Proof: report-only states are superseded above by callback `applied` / `already-present` verification states for C-00030G-001 through C-00030G-010.
- [x] Metadata/score change to apply if accepted: `00030G` from `85/88` to `88/89`; owner/emitter/reconstructable unchanged. Proof: target header changed and validator `000000004529` applied `completion_update 88` and `confidence_update 89`.
- [x] Score-limiting blockers researched: raw helper body roles resolved; no-direct-route evidence preserved; subcmd `7`, final field declarations, original source split, and aggregate C++ remain evidence-backed unresolved. Proof: target Source-Quality Reanalysis and class Source-Quality Notes.
- [x] Owner/emitter changes: none. Proof: target retained `CANONICAL_OWNER:00000K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000K`; class/file support route unchanged.
- [x] Split/rename/new-child changes: none required; optional raw-helper child splits are a future review-granularity choice, not an ownership blocker. Proof: no new files created, target range unchanged, shared `00030H` separation preserved.
- [x] Source-placement/range changes: keep current range and shared `00030H` separation. Proof: target range/header unchanged and support docs state `00030H` remains shared file-level support.
- [x] First-draft C++ disposition: keep existing marker-only formal block; no body C++. Proof: target formal C++ remains marker-only; generated `BoardDialogs.cpp` retains marker-only UID00030G output.
- [x] Third-party import directive: not applicable. Proof: no third-party source or import directive used.
- [x] Historical/stale assumptions to preserve/reject: generated date-byte labels `readStatus`/`replyFlag` remain rejected; raw helper "unknown body" blocker should be superseded by B003 MCP role recovery; subcmd `7` semantics remain unresolved. Proof: target/class docs preserve all three dispositions.
- [x] Validators to run during callback: scoped file validators for every edited by-* doc, normally `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240`. Proof: validators `000000004529`, `000000004531`, and `000000004532` all exited `0` with `ok: 1`.
- [x] Generated refresh expectation: validators should refresh `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp`; generated `BoardDialogs.cpp` should retain marker-only UID00030G output unless formal C++ changes are explicitly approved. Proof: generated headers and queue status recorded in Validator Results; generated UID00030G remains marker-only at `88/89`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: supervisor callback accepted UID00030G for implementation and listed target/support scope.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target, class, and file support docs updated; optional pane docs excluded with reason above.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C-00030G-001 through C-00030G-010 updated above.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: UID00030G raised to `88/89`; owner/emitter/reconstructable unchanged; no split/rename/new child; marker-only C++ retained.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/class/file docs preserve raw no-direct-route, source-placement rejection, shared UID00030H separation, stale date-byte label rejection, and subcommand `7` unresolved state.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: subcommand `7`, field declarations, and source split are documented as current-pass evidence-backed caps, not generic future work.
- [x] Validators run and results recorded. Proof: Validator Results section records commands, IDs, timestamps, exit codes, and `ok` counts.
- [x] Generated report refresh completed by validator or freshness checked/reported. Proof: generated headers and queue status recorded above.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none remain; optional pane sync excluded because not needed for consistency.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004545","destination_path":"executed-b-agent-research/B003/00030G-ArticleListDialogCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00030G-ArticleListDialogCore-source-quality.md","timestamp":"2026-07-02T14:16:17-04:00","uid":"00030G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
