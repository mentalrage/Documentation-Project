** TARGET-REPORT-UID:00030I **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00030I ArticleListPaneCore Source-Quality / Heuristic Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00030I] `0x004748f0-0x004751b1.ArticleListPaneCore` assigned to direct class owner/emitter [UID:00000L] `ArticleListPane`; do not split or reroute the target in this pass.
- Final disposition: source-quality report-only pass. The current owner/source placement is valid, the current score `85/87` is defensible, and implementation should improve the target/support docs with the field, helper, source-name, negative-evidence, and C++-readiness details below.
- Required action: supervisor should send an implementation checklist to B014 or another documentation agent if accepted. The checklist should update the target and direct support docs, but `by-memory/-coverage-report.md` remains supervisor-owned.
- Confidence: high for `ArticleListPane` ownership and `BoardDialogs` source route; medium-high for the article-row layout and method-name inferences; medium for the raw helper names because live IDA MCP was unavailable in this session and the raw helper bodies still need direct disassembly/decompilation confirmation.

## Supporting Research

## Target

- Target UID: `00030I`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004748f0-0x004751b1.ArticleListPaneCore.md`
- Assignment: `B014-goal2-article-list-pane-core-source-quality-00030I-20260619`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:00000L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000L`, blank C++.
- Current direct class parent: [UID:00000L] `ArticleListPane`, currently `85/87`, owner/emitter [UID:0000HT] `BoardDialogs`.
- Current file/source parent: [UID:0000HT] `BoardDialogs`, currently `86/87`, projected under `NexusTK/ui/dialogs/`.
- Current parent aggregate: [UID:0000ZK] `BoardArticleDialogs`, now a `90/91`, `RECONSTRUCTABLE:FALSE` split inventory.
- Exact current supervisor-owned coverage row is recorded in the dedicated section below.

## Executive Recommendation

The target is already correctly modeled as the `ArticleListPane` method/raw-helper cluster. The direct owner should remain [UID:00000L] `ArticleListPane`, and the emitter should remain [UID:00000L] so generated output flows through [UID:0000HT] `BoardDialogs`.

No new source split is justified from the evidence available here. The internal raw helper spans are source-bearing and belong to this pane, but they do not show different owners. Splitting them into separate `by-memory` pages could be useful later if live disassembly recovers precise function bodies and final source names, but a split is not currently required to fix ownership or range quality.

The main implementation work is source-quality documentation:

- Rename the constructor argument and field from `categoryId` to inferred `boardId`; `ArticleListDialog` passes the parsed board id, and article read/navigation packet helpers read `ArticleListPane + 0x14c`.
- Document the row record as a `0x406`-byte `ArticleListEntry` layout: `articleId`, a status/type byte, month, day, one pad byte, `title[256]`, and `author[256]`. Decimal `1030` was verified as `0x406` with `int_convert.py`.
- Correct the producer-side generated labels `readStatus`/`replyFlag` for the two post-title bytes: the pane's paint method renders them as the date columns, so the best source-facing names are `month` and `day`. The first per-row byte should stay neutral as `statusByte`/`articleStatus` until color semantics are proven.
- Treat `0x00474f70` as an activation/read dispatch virtual, not a pure session getter. Existing metadata says it follows two owner hops into `ArticleListDialog::SendReadArticlePacket()`, which is behaviorally `OnArticleActivated()` or `OnItemActivated()`.
- Keep formal C++ blank for this target until raw helpers `0x00474a70`, `0x00474b20`, `0x00474c00`, `0x00474ce0`, `0x00474d10`, `0x00474d70`, `0x00474e00`, and `0x00474e60` have direct live disassembly/decompilation or exact child splits. A partial C++ block for only the modeled functions would falsely imply the whole range is source-ready.

## Supervisor Active Recheck

- The user explicitly assigned B014 to produce a report only for [UID:00030I], not to edit `by-*` docs.
- `Supervisor.md` and B014 `goal.md` require source-quality/heuristic reanalysis, exact ownership/source-placement decisions, open-question treatment, C++ readiness, support checklist, and exact supervisor-owned coverage row text.
- The current B014 `notes.md` still mentions an older `00010D` handoff, but the direct user assignment supersedes it for this turn.
- Live IDA MCP at `http://127.0.0.1:13337/mcp` was checked and was unavailable: `Unable to connect to the remote server`. This report therefore distinguishes current-session facts from existing documented IDA facts and non-authoritative generated-source leads.
- No `by-*` docs and no coverage reports were edited. Only this research report was created.

## Inference Research Guidance Check

- `by-structure.md` requires direct semantic ownership, separate emitter routing, conservative scoring, no C++ unless the item is source-ready, and explicit treatment of raw helpers and unresolved names.
- `inference_research.md` supports using caller/callee clusters, vtable stores, source locality, negative evidence, and producer/consumer data flow as probabilistic evidence when stripped binaries lack original source names.
- Existing by-doc claims were treated as leads. Strong claims already backed by documented IDA checks were retained; generated names such as `categoryId`, `GetBulletinSession`, `readStatus`, and `replyFlag` were re-evaluated against documented data flow and source shape.
- Local generated output from `simroot_v2` was used only as a weak source-shape lead, not as authority. The report relies primarily on existing by-doc IDA notes, target/class/file documentation, parent aggregate research, and cross-document consistency.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Candidates considered | Decision / best inference | Rejected alternatives / blocker |
| --- | --- | --- | --- | --- |
| Direct owner for `00030I` | Target doc, [UID:00000L] class doc, [UID:0001X4] vtable family, [UID:0000ZK] split inventory, prior B001 aggregate report | `ArticleListPane`, `ArticleListDialog`, `BoardDialogs`, `ListPane` | Keep `CANONICAL_OWNER:00000L`; constructor callers from `ArticleListDialog`, vtable store `0x00474942`, and class docs prove pane ownership. | Reject `ArticleListDialog` because it owns/constructs the pane but not the pane methods; reject `BoardDialogs` as too broad for class methods; reject `ListPane` because only shared `0x004f3c00+` infrastructure belongs there. |
| Source file route | [UID:00000L] -> [UID:0000HT], [UID:0000HT] source bucket, proposed tree | `BoardDialogs.cpp`, split `ArticleDialogs.cpp`, `ListPane.cpp` | Keep current route through `BoardDialogs`; note that final original split may become `ArticleDialogs.cpp`, but current file parent is the valid reconstruction root. | Reject `ListPane.cpp` for this target; only inherited/shared helpers such as `0x004f3c00+` move there. |
| Range/split decision | Target boundaries, `0000ZK` child inventory, padding `0x004748ea-0x004748f0` and `0x004751b1-0x004751c0`, successor [UID:00030H] | Keep one cluster; split raw helpers; merge with navigation helpers | Keep `0x004748f0-0x004751b1` intact. It is an exact pane cluster with internal raw helpers; no different direct owner is proven. | Reject merge with [UID:00030H] because `0x004751c0` has cross-class callers and file-level ownership. Optional future raw-helper splits should wait for live disassembly. |
| Constructor field at `+0x14c` | ArticleListDialog constructor/list-update flow passes parsed board id to `ArticleListPane`; read/navigation packet paths read the field; target notes selected navigation uses `+0x14c` | `categoryId`, `boardId`, `boardNumber` | Best source-facing name: `m_boardId` / constructor parameter `boardId`. | Reject `categoryId` as stale/generated; board/article packet context uses board id. |
| Byte at `+0x14e` | Target raw setter `0x00474e00`; generated/metadata input handlers check adjusted byte before requesting next page; no stronger body evidence | `m_sortEnabled`, `m_pageRequestBlocked`, `m_noMorePages`, `m_isLoadingNextPage` | Best descriptive name: `m_pageRequestBlocked` or `m_nextPageRequestSuppressed`; document as a guard byte tested before automatic next-page requests. | Reject `sortEnabled`; shared `0x004f3dd0` is a `ListPane` selection/multi-select toggle and not this byte. Do not choose `m_noMorePages` without producer write evidence. |
| Article row layout | Constructor item-size lead `1030`, verified as `0x406`; add-entry and paint behavior; producer flow in `ArticleListDialog` | `{id,status,month,day,title,author}`, generated `{id,isRead,month,day,title,author[257]}` | Best layout: `int16 articleId; uint8 statusByte; uint8 month; uint8 day; uint8 pad; wchar_t title[256]; wchar_t author[256];` total `0x406`. | Reject `author[257]`; `0x406` total only fits two 256-wide-character buffers after six header bytes. Reject naming the date bytes `readStatus`/`replyFlag`; paint renders them as month/day. |
| First row byte semantics | Producer reads it before id/title; AddArticleEntry stores it at row `+2`; paint changes color when nonzero | `isRead`, `isUnread`, `articleType`, `statusByte` | Use neutral `statusByte` / `articleStatusByte`; mention likely read/unread or type/color flag. | Do not claim exact read/unread polarity because color id meaning and server enum are not proven in current evidence. |
| `0x00474990` name/signature | Target role, generated active source, producer calls from constructor/update parser | `AddArticleEntry`, `InsertArticleEntry`, `UpsertArticleEntry` | Best source name: `AddArticleEntry(uint8 statusByte, int16 articleId, const wchar_t *title, uint8 month, uint8 day, const wchar_t *author)`. It removes/replaces duplicates and inserts sorted by article id. | Avoid `isRead`/`readStatus` parameter names for the date bytes. |
| `0x00474e10` name | Existing docs and metadata agree | `FindArticleById`, `FindRowByArticleId` | Keep `FindArticleById(short articleId)`. | None; exact original spelling unknown, but descriptive name is strong. |
| `0x00474ec0` and `0x00474f20` names | Existing metadata says input/key handlers call next-page request when scrolled/selected at end and guard byte is clear | `HandleInputEvent`, `OnInputEvent`, `HandleKeyDown`, `OnKeyDown` | Use virtual-style names `OnInputEvent`/`OnKeyDown` or keep documented `HandleInputEvent`/`HandleKeyDown`; both are descriptive. | Do not model them as generic ListPane code; they use ArticleListPane page-request policy. |
| `0x00474f70` current name | Metadata note: two vtable-slot `+0x1C` owner hops into `ArticleListDialog::SendReadArticlePacket()` | `GetBulletinSession`, `OnItemActivated`, `OpenSelectedArticle`, `ReadSelectedArticle` | Best source-facing name: `OnArticleActivated()` / `OnItemActivated()`, a virtual activation callback that asks the owning dialog to read/open the selected article. | Reject `GetBulletinSession`; behavior is dispatch into the owner dialog, not a pure getter. Exact original name remains unproven. |
| `0x00474f90` name/layout | Paint method formats id, title, date, author columns and selection/read-status colors | `OnPaintItem`, `DrawArticleRow` | Keep `OnPaintItem(int itemIndex, const ArticleListEntry *entry, RECT *itemRect)` or document as `DrawArticleRow`. | C++ should not be emitted until text clipping helper and color enum names are documented. |
| Raw helper `0x00474a70` | Target says raw body with `0x104` stack buffer and no xrefs; generated disabled owner pollution attached it to `ChattingColorListPane` | packet helper, text helper, stale generated method | Keep as `ArticleListPane` raw helper with unresolved source name; likely article-row packet/text support, but needs live disassembly. | Reject `ChattingColorListPane` owner as generated pollution. Do not use final C++ name yet. |
| Raw helpers `0x00474b20` and `0x00474c00` | Target says paired raw no-function helpers with `0x50c` stack buffers; generated disabled `ArticleListPane` methods with no code | text formatting helpers, selected-row helpers, dead/redundant helpers | Keep in target as unresolved `ArticleListPane` raw row/text helper pair. | Do not emit source; no direct xrefs or body details are documented enough for final names. |
| Raw helper `0x00474ce0` | Target says wrapper calls `FindArticleById`; generated signature includes `short param_1` | row lookup/update wrapper, select row by id, remove by id | Best descriptive placeholder: `UpdateArticleRowByIdRaw` or `FindArticleRowWrapperRaw`; exact behavior requires disassembly. | Do not call it delete/select until side effects are proven. |
| Raw helper `0x00474d10` | Target says `0x404` stack buffer, no direct xrefs | row text/update helper | Keep descriptive unresolved raw helper. | Not source-ready. |
| Raw helper `0x00474d70` and modeled `0x00474da0` | [UID:00030H] records raw xref `0x00474d91` and modeled caller `0x00474dea` into shared helper `0x004751c0` | previous/next page request, selected-article navigation | Treat as ArticleListPane selected-article/page-navigation wrappers that call shared file-level navigation helper. `0x00474da0` is likely the `RequestNextArticlePage` helper used by input/key end-of-list policy. | Do not assign the shared helper itself to this class; it is correctly [UID:00030H] under `BoardDialogs`. |
| Raw helper `0x00474e60` | Target says adjacent raw scan helper; generated disabled `ChattingColorListPane` method with short param | find/select article by id, stale chat method | Keep as ArticleListPane raw row-selection scan helper with unresolved exact name. | Reject `ChattingColorListPane` ownership as generated pollution; no final C++ until body is recovered. |
| First-draft C++ readiness | Target qualifies by minimum metadata gate, but C++ block is blank and raw bodies/field names remain unresolved | Populate modeled methods only; leave blank; split raw helpers first | Leave formal C++ blank for `00030I` now. Add a `First-Draft C++ Recommendation` explaining the no-code proof and the conditions to clear it. | Reject partial C++ because this by-memory page covers the whole cluster, not only modeled functions; partial emission would hide missing raw source. |

## Evidence Standards Used

- Existing documented IDA evidence: function boundaries, caller/callee notes, vtable-store xrefs, raw helper spans, padding boundaries, and shared-helper fanout recorded in the target, class, file, vtable, and aggregate pages.
- Documentation evidence: [UID:00000L] `ArticleListPane`, [UID:00000K] `ArticleListDialog`, [UID:0000HT] `BoardDialogs`, [UID:00007A] / [UID:0000KT] `ListPane`, [UID:00030G], [UID:00030H], [UID:0000ZK], and B001's executed `0000ZK` aggregate report.
- Generated-source evidence: `simroot_v2` ArticleListPane/ArticleListDialog output and metadata were used only as non-authoritative leads, mainly to cross-check field and row-shape consistency.
- Negative evidence: live IDA MCP unavailable; raw helper starts have documented empty direct-xref checks; generated `ChattingColorListPane` ownership for `0x00474a70`/`0x00474e60` is contradicted by range locality and target documentation; shared `0x004f3c00+` helpers belong to ListPane, not this target.
- Integer conversion: `1030` decimal was verified as `0x406` with `int_convert.py`; `0x14c` was verified as decimal `332`, and `0x14e` as decimal `334`, with `int_convert.py`.

## IDA MCP Facts

Current-session live IDA MCP facts are unavailable because the local MCP endpoint did not respond. The following are existing documented IDA facts from the by-* corpus and prior B-agent reports:

- `lookup_funcs`/function inventory previously confirmed modeled functions in this target at `0x004748f0`, `0x00474990`, `0x00474da0`, `0x00474e10`, `0x00474ec0`, `0x00474f20`, `0x00474f70`, and `0x00474f90`.
- Raw function-shaped chunks are documented at `0x00474a70`, `0x00474b20`, `0x00474c00`, `0x00474ce0`, `0x00474d10`, `0x00474d70`, `0x00474e00`, and `0x00474e60`; prior `xrefs_to` checks for those raw starts were empty.
- Constructor callers for `0x004748f0` are documented at `0x00472e04` and `0x00473410` inside `ArticleListDialog` constructor/setup.
- Vtable ownership is documented by `xrefs_to 0x00613e4c` returning the primary `ArticleListPane` vtable store at `0x00474942` inside `sub_4748F0`; vtable-family docs also list secondary/tertiary stores at `0x00474948` and `0x00474952`.
- `callees 0x004748f0` is documented as limited to shared list-pane setup helpers `0x004f3a50` and `0x004f3dd0`.
- [UID:00030H] documents `xrefs_to 0x004751c0` including `0x00474d91` and `0x00474dea` from this target, proving the pane reaches the shared article-navigation helper while the helper itself is not pane-private.
- Boundary padding is documented: six `0xcc` bytes at `0x004748ea-0x004748f0` before this page and fifteen `0xcc` bytes at `0x004751b1-0x004751c0` before the shared navigation helper island.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004748f0-0x004751b1` | [UID:00030I] `by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md` | ArticleListPane constructor/method/raw-helper cluster | true | [UID:00000L] `ArticleListPane` | `85/87` | Keep assigned; improve source-quality details. |
| `0x004748f0-0x00474983` | in target | `ArticleListPane::ArticleListPane(short itemHeight, uint16 boardId)` | true | [UID:00000L] | included in target | Constructor, vtable stores, ListPane base setup, board id field. |
| `0x00474990-0x00474a6e` | in target | `AddArticleEntry` / sorted insert-or-replace | true | [UID:00000L] | included in target | Row layout and parameter names should be corrected. |
| `0x00474a70-0x00474b19` | in target | raw article-row helper | true | [UID:00000L] | included in target | Keep unresolved; generated `ChattingColorListPane` disabled owner is pollution. |
| `0x00474b20-0x00474bf6` | in target | raw row/text helper | true | [UID:00000L] | included in target | Keep unresolved until disassembly. |
| `0x00474c00-0x00474cd6` | in target | paired raw row/text helper | true | [UID:00000L] | included in target | Keep unresolved until disassembly. |
| `0x00474ce0-0x00474d02` | in target | raw row lookup/update wrapper | true | [UID:00000L] | included in target | Calls/uses `FindArticleById`; exact side effect unresolved. |
| `0x00474d10-0x00474d6a` | in target | raw row text/update helper | true | [UID:00000L] | included in target | Keep unresolved until disassembly. |
| `0x00474d70-0x00474d97` | in target | raw selected-article navigation wrapper | true | [UID:00000L] | included in target | Reads pane/selected entry state and calls [UID:00030H] helper. |
| `0x00474da0-0x00474df8` | in target | selected-page/article navigation caller | true | [UID:00000L] | included in target | Likely `RequestNextArticlePage`/page navigation helper. |
| `0x00474e00-0x00474e10` | in target | page-request guard setter | true | [UID:00000L] | included in target | Best field name `m_nextPageRequestSuppressed` / `m_pageRequestBlocked`. |
| `0x00474e10-0x00474e53` | in target | `FindArticleById` | true | [UID:00000L] | included in target | Strong descriptive name. |
| `0x00474e60-0x00474eb6` | in target | raw row-selection scan helper | true | [UID:00000L] | included in target | Keep unresolved; generated `ChattingColorListPane` disabled owner is pollution. |
| `0x00474ec0-0x00474f15` | in target | input-event virtual | true | [UID:00000L] | included in target | ArticleListPane page-request policy on end-of-list/scroll condition. |
| `0x00474f20-0x00474f69` | in target | key-down virtual | true | [UID:00000L] | included in target | ArticleListPane page-request policy on keyboard selection reaching last row. |
| `0x00474f70-0x00474f83` | in target | activation/read-selected virtual | true | [UID:00000L] | included in target | Rename away from pure getter; likely `OnArticleActivated()`. |
| `0x00474f90-0x004751b1` | in target | row paint virtual | true | [UID:00000L] | included in target | Uses row layout and date/title/author columns. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00472e04`, `0x00473410` | documented callers to `0x004748f0` | `ArticleListDialog` constructs the embedded/owned article-list pane. |
| `0x00474942`, `0x00474948`, `0x00474952` | documented vtable stores | `ArticleListPane` primary/secondary/tertiary vtable identity. |
| `0x004751c0` | callees from `0x00474d91` and `0x00474dea` | This pane requests shared article navigation/read-page behavior, but [UID:00030H] is file-level because callers span multiple article/alert classes. |
| `0x004f3a50` | constructor callee | `ListPane` base/control setup; shared infrastructure remains [UID:00007A]/[UID:0000KT]. |
| `0x004f3dd0` | constructor callee | Shared ListPane selection/multi-select toggle; generated name `SetSortEnabled` is not ArticleListPane-private evidence. |
| `0x004f3dc0` | selected-entry helper used by dialog/pane flow | Shared ListPane selected-entry retrieval; consumers read the leading article id from the row record. |
| `0x00474470` | ArticleListDialog list-update parser | Producer of rows consumed by `AddArticleEntry`; supports month/day naming for two post-title bytes. |

## Documentation Evidence And IDA Status

- Target doc already records the correct direct class owner, file parent, parent aggregate, exact boundaries, modeled/raw helper inventory, and current assignment decision.
- [UID:00000L] `ArticleListPane` correctly excludes `0x004f3c00+` shared ListPane helpers, records the vtable family, and documents stale-owner correction for `0x00488680`.
- [UID:00000K] `ArticleListDialog` documents the pane as an owned control and records that final C++ is blocked by packet/list-entry field names and raw-helper reachability.
- [UID:0000HT] `BoardDialogs` treats `ArticleListPane` as a board article-list row renderer and keeps the current source route under `NexusTK/ui/dialogs/`.
- [UID:0000ZK] confirms this target is an exact child of a non-emitting split inventory and no longer a mixed aggregate problem.
- [UID:00030H] confirms the successor navigation helper island is shared and should stay file-level, not absorbed into this target.
- Existing docs are stale/incomplete in several source-quality details: `categoryId` should be `boardId`; the row layout is not explicitly modeled; `0x00474f70` is mislabeled as a session getter in places; raw helper names and reachability remain unresolved; and final C++ readiness is not explained with enough precision.

## Ranked Ownership Analysis

### 1. [UID:00000L] ArticleListPane

- Evidence for: constructor callers from `ArticleListDialog`, `ArticleListPane` vtable stores at constructor offsets, target/class doc agreement, exact child inventory in `0000ZK`, row insertion/find/paint behavior, and field use tied to article-list pane state.
- Evidence against: inherited/shared ListPane helpers are nearby in generated output and some raw helpers have generated owner pollution.
- Decision: accepted. Shared helper pollution is explicitly excluded; this target covers pane-local behavior only.

### 2. [UID:0000HT] BoardDialogs

- Evidence for: file-level board/article source bucket owns the surrounding dialog family and shared navigation helper island.
- Evidence against: this target is direct class method code, not a file-level free helper island. Assigning direct ownership to the file would bypass the true class owner.
- Decision: rejected as canonical owner for `00030I`, retained as source-file route through the class.

### 3. [UID:00007A] / [UID:0000KT] ListPane

- Evidence for: constructor calls shared ListPane setup; several generated methods under `ArticleListPane` are now documented as shared ListPane infrastructure.
- Evidence against: target's core range has ArticleListPane vtable stores, board id field, article row layout, article row painting, and article navigation calls; the actual shared ListPane implementation lives at `0x004f3a50-0x004f4a77`.
- Decision: rejected for this range. Keep only inherited helper references to ListPane.

### 4. [UID:00000K] ArticleListDialog

- Evidence for: constructs and owns the pane as a control; row producer lives in the dialog constructor/update parser.
- Evidence against: the pane methods are class-local virtuals/helpers with their own vtables and row renderer. Dialog ownership of the child control is not source ownership of the child class methods.
- Decision: rejected as direct owner, retained as caller/producer context.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new source file owner is required.
- Possible future type support: create or update a row-layout support page such as `by-type/by-struct/ArticleListPaneEntryLayout.md` only if the project wants a shared canonical struct page. Otherwise document the `ArticleListEntry` layout directly in [UID:00030I] and [UID:00000L].
- Likely full contents of current source grouping: `ArticleListPane` class methods in `BoardDialogs.cpp` or future `ArticleDialogs.cpp`, with inherited `ListPane` helpers remaining in `ui/controls/ListPane.cpp`.
- Candidate related items that belong: [UID:00030I] only for this pane cluster; [UID:00030G] as producer/caller context; [UID:00030H] as shared navigation helper dependency.
- Candidate related items rejected: `0x004f3c00+` ListPane helpers, `0x00488680` Clan list helper, and generated `ChattingColorListPane` disabled attachments for `0x00474a70`/`0x00474e60`.
- Standalone, narrow, or broad source-file inference: narrow class-in-source-bucket inference, not a new standalone module.

## Negative Evidence Summary

- Live IDA MCP was unavailable; no current-session decompile/disasm facts should be claimed.
- Empty direct xrefs for raw starts prevent final source names for the raw helper bodies.
- Generated ownership for `0x00474a70` and `0x00474e60` under `ChattingColorListPane` is rejected as owner pollution because the addresses sit inside the `ArticleListPane` exact child range and the target/aggregate docs already classify them as article-list pane raw helpers.
- Consumer/caller context from `ArticleListDialog` does not override class ownership. It proves construction and producer data flow, not direct ownership of the pane methods.
- Shared ListPane helper calls do not prove this target owns `0x004f3c00+` methods. ListPane docs record broad caller fanout and correct `ui/controls/ListPane.cpp` placement.
- The formal C++ block should not be partially populated from generated code because raw bodies and final helper names remain undocumented at source quality.

## First-Draft C++ Recommendation

Do not populate `RECONSTRUCTION_CPP CODE` for [UID:00030I] in the implementation callback.

Reason: the target qualifies by the minimum metadata gate (`RECONSTRUCTABLE:TRUE`, nonblank emitter route, average score above 85), but the item is not source-ready. The page covers the full `0x004748f0-0x004751b1` cluster, including multiple raw helper bodies with unresolved signatures, no direct xrefs, and no current live disassembly in this report. Emitting only the modeled constructor/add/find/input/key/paint methods would be a partial reconstruction that omits source-bearing bytes inside the same page and would make the generated output look more complete than the evidence supports.

Implementation should instead add a source-readiness note with the conditions that would clear the C++ blocker:

- live disassembly/decompilation for each raw helper body;
- final source-facing names or deliberate descriptive names for each raw helper;
- documented `ArticleListEntry` layout and `ArticleListPane` member offsets;
- final treatment of text clipping/color helpers in `OnPaintItem`;
- explicit decision whether the raw helpers remain in this cluster or are split to exact child pages;
- if split, each child must carry its own owner/emitter/C++ readiness state.

When those conditions are met, a plausible mid-2000s source shape would include `ArticleListPane::ArticleListPane`, `AddArticleEntry`, `FindArticleById`, `OnInputEvent`, `OnKeyDown`, `OnArticleActivated`, `OnPaintItem`, and private helper methods for page navigation and row lookup/update, with shared `ListPane` calls expressed through the base class API rather than copied as ArticleListPane-owned source.

## Final Recommendation

- Exact changes recommended for target doc:
  - Add a source-quality section documenting `ArticleListEntry` layout, `m_boardId`, `m_nextPageRequestSuppressed`/guard-byte uncertainty, corrected producer field names, and raw helper status.
  - Change prose that calls constructor argument `categoryId` to `boardId` or explicitly mark `categoryId` as stale/generated.
  - Change `0x00474f70` role from `owning session getter` to `article activation/read-selected callback` or document both the stale label and the corrected inference.
  - Keep `COMPLETION:85` and `CONFIDENCE:87` unless the implementation also adds the full row-layout/source-quality evidence and supervisor chooses to raise modestly. I do not recommend `90+` while raw helper bodies remain unresolved.
  - Keep `CANONICAL_OWNER:00000L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000L`, and blank C++.
- Exact support-doc changes recommended:
  - [UID:00000L] `ArticleListPane`: add the `ArticleListEntry` layout, `m_boardId` at `+0x14c`, guard byte at `+0x14e`, `OnArticleActivated` correction for `0x00474f70`, and retained raw-helper C++ blocker.
  - [UID:00000K] `ArticleListDialog`: correct or caveat generated names `readStatus`/`replyFlag` for article rows; the two bytes passed after title are rendered as month/day by the pane.
  - [UID:0000HT] `BoardDialogs`: no required ownership/path change; optional note that `ArticleListPane` source-quality blocker is internal raw helper recovery, not owner routing.
  - Optional by-type support: create a focused `ArticleListPaneEntryLayout` struct page only if a future implementation wants layout reuse across dialog producer, pane row insertion, and row paint docs.
- Exact items left no-owner/non-emitting: none in this target. The parent aggregate [UID:0000ZK] remains non-emitting by design; [UID:00030H] remains file-level, not pane-owned.
- Exact future work outside this assignment: live IDA MCP disassembly/decompile pass for raw helpers; possible raw-helper child splits if bodies are independently source-ready.

## Target / Support Implementation Checklist

For an implementation callback, apply the following claim-by-claim and do not compress the report into a short summary:

1. Target [UID:00030I] `by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md`
   - Add a `Source-Quality Reanalysis` or equivalent section covering owner/source route, row layout, field names, helper names, rejected generated names, C++ readiness, and live-IDA-unavailable caveat.
   - Update `Covered Range` role text:
     - `0x004748f0`: constructor parameter/field should be `boardId`, not `categoryId`.
     - `0x00474990`: `AddArticleEntry(statusByte, articleId, title, month, day, author)`, duplicate replace plus sorted insert.
     - `0x00474e00`: `SetNextPageRequestSuppressed` / guard-byte setter as inferred descriptive name, not final original name.
     - `0x00474f70`: activation/read-selected callback, not pure session getter.
   - Add row layout:
     - total row size `0x406` / 1030 bytes, verified with `int_convert.py`;
     - `+0x000 int16 articleId`;
     - `+0x002 uint8 statusByte`;
     - `+0x003 uint8 month`;
     - `+0x004 uint8 day`;
     - `+0x005 uint8 pad/reserved`;
     - `+0x006 wchar_t title[256]`;
     - `+0x206 wchar_t author[256]`.
   - Add pane member notes:
     - `+0x14c` is inferred `m_boardId`;
     - `+0x14e` is a next-page request guard/suppression byte, exact polarity/name unresolved.
   - Keep metadata unchanged unless the implementer adds enough written evidence to justify a modest score change. Do not raise either score to `90+`.
   - Keep formal C++ blank and add the no-code proof from this report.

2. Support [UID:00000L] `by-class/ArticleListPane.md`
   - Add the same row layout in class-level form or link to a new by-type struct if created.
   - Replace/caveat `categoryId` and `GetBulletinSession` wording.
   - Preserve the `ListPane` shared-helper exclusion.
   - Mention generated disabled `ChattingColorListPane` attachments for `0x00474a70`/`0x00474e60` as rejected owner pollution only if useful; do not make them evidence of chat ownership.

3. Support [UID:00000K] `by-class/ArticleListDialog.md` and/or [UID:00030G] `ArticleListDialogCore`
   - Clarify producer packet row order: status/type byte, article id, title bytes, month byte, day byte, author bytes.
   - Preserve uncertainty for the first status byte polarity.
   - Do not move ownership from `ArticleListPane`.

4. Support [UID:0000HT] `by-file/BoardDialogs.md`
   - No required source path or owner change.
   - Optional one-line source-quality note: `ArticleListPaneCore` ownership is settled, but its formal C++ remains blank pending raw helper recovery and row-helper naming.

5. Optional new support doc
   - If creating `by-type/by-struct/ArticleListPaneEntryLayout.md`, lease normally, validate it, then update target/class/dialog docs to UID-link it.
   - Do not create the struct page unless the implementation will fill it with evidence at report-level detail.

6. Validation expected after implementation
   - Run scoped validator file scans for every touched by-* doc.
   - Do not edit `by-memory/-coverage-report.md`; leave exact current or replacement row text for supervisor application.

## Supervisor-Owned Coverage Row Text

Exact current row from `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md`:

```text
      - [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) 0x004748f0-0x004751b1 | class method cluster | ArticleListPaneCore : reconstructable : 85% : strong : Assigned to [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) after child `85/87`, direct class parent `85/87`, and file parent `85/86`; evidence is constructor callers from `ArticleListDialog`, primary vtable store `0x00474942`, shared-list setup callees, exact pane child split, row/navigation raw helper bodies, and `0x004751c0` shared-helper caller evidence.
```

Recommended coverage action for this report-only pass: no immediate supervisor-owned coverage replacement is required because no by-* implementation changes were made. If the implementation checklist is accepted and target/support docs are updated without score changes, the row above can remain valid. If the supervisor chooses to reflect the added source-quality detail while keeping the score, use this replacement:

```text
      - [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) 0x004748f0-0x004751b1 | class method cluster | ArticleListPaneCore : reconstructable : 85% : strong : Assigned to [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) after child `85/87`, direct class parent `85/87`, and file parent `86/87`; B014 source-quality reanalysis keeps owner/emitter unchanged, infers `ArticleListPane +0x14c` as `m_boardId`, models the `0x406`-byte article row as id/status/month/day/title/author, rejects stale `categoryId`, `GetBulletinSession`, and generated `ChattingColorListPane` raw-helper ownership, and keeps formal C++ blank pending raw helper disassembly/naming.
```

If the implementation raises the target score after adding detailed evidence, the row must be adjusted to match the final validated header values instead of using the replacement above blindly.

## Follow-Up Actions

- Supervisor actions:
  - Review this report for acceptance.
  - If accepted, send B014 a detailed implementation callback using the checklist above.
  - Apply or retain the supervisor-owned coverage row text after implementation and validation; B014 must not edit the shared report directly.
- A-agent actions:
  - None required before B014 implementation. If assigned later, focus on raw helper live disassembly and optional row-layout type page.
- B014 future research actions:
  - With live IDA MCP available, decompile/disassemble raw helpers `0x00474a70`, `0x00474b20`, `0x00474c00`, `0x00474ce0`, `0x00474d10`, `0x00474d70`, `0x00474e00`, and `0x00474e60`.
  - Determine whether raw helpers should remain in the cluster or become exact child pages.
  - Revisit first-draft C++ only after the raw helper issue is closed.

## Confidence

- Recommendation confidence: high for owner/emitter/source route and no split; medium-high for row layout and field names; medium for raw helper names.
- Score confidence: current `85/87` remains appropriate. A modest completion/confidence increase may be defensible after implementation, but this report does not require one because live raw-helper evidence is still missing.
- Remaining uncertainty: exact original names for raw helpers; exact polarity/enum name of the first row status byte; exact source name for the `+0x14e` guard; final original file split between `BoardDialogs.cpp` and possible `ArticleDialogs.cpp`; final text clipping/color helper names needed for `OnPaintItem` C++.

## Validator Results

- Commands run for documentation validation: none.
- Reason: report-only assignment; no by-* docs or coverage reports were edited.
- Other tool checks:
  - IDA MCP status check attempted; endpoint was unavailable.
  - `int_convert.py` was run for `1030`, `0x406`, `0x14c`, and `0x14e`.

## Changed Files

- Created:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B014\research\00030I-ArticleListPaneCore-source-quality.md`
- Modified:
  - None.
- Renamed:
  - None.
- Moved to executed:
  - None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/00030I-ArticleListPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00030I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
