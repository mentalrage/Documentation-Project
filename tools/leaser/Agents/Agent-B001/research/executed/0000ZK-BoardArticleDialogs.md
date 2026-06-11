# 0000ZK BoardArticleDialogs Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](../../../by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) parent-blank and non-reconstructable as a split inventory, not as a direct source-bearing item.
- Final disposition: converted the aggregate from stale `82/87` reconstructable source bucket to `90/91`, `RECONSTRUCTABLE:FALSE`, with all source-bearing in-range work represented by exact child pages.
- Required action: supervisor review/execute/archive the report; no remaining in-range source-bearing child is left as a vague follow-up.
- Confidence: high for the split/container disposition and parent routing; medium-high for final original source-file partition because `BoardDialogs.cpp` versus `ArticleDialogs.cpp` remains inferred.

## Supporting Research

## Target

- Target UID: `0000ZK`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00472070-0x00477790.BoardArticleDialogs.md`
- Source queue/report row: supervisor status `reviewed-no-85-under-review`
- Current supervisor classification: aggregate below 85 and unassigned; determine whether direct source-bearing completion or parent-blank split inventory is correct.
- Starting scores and parent state: `82/87`, `RECONSTRUCTABLE:TRUE`, blank parent.
- Ending scores and parent state: `90/91`, `RECONSTRUCTABLE:FALSE`, blank parent.

## Executive Recommendation

The aggregate should not be assigned to a source parent or reconstructed directly. IDA shows this is a compact address cluster containing several real owners: `BoardListDialog`, `BoardListPane`, `ArticleListDialog`, `ArticleListPane`, shared article-navigation helpers, `ArticleDialog`, and `NewArticleDialog`, plus nearby compiler destructor companions outside the range. Treating `0000ZK` as one reconstructable source item would duplicate exact children and hide mixed ownership.

Exact source-bearing children are now the reconstruction surface. Class-owned children attach to their direct classes after both sides clear `85/85`. The shared article-navigation island attaches to [UID:0000HT][BoardDialogs](../../../by-file/BoardDialogs.md) because no class page can honestly own callers from article-list, normal new-article, predefined-form article, and transfer-reply alert paths.

The only remaining external note is `0x0047e9d0`, a shared list-like pane destructor target referenced by `ArticleListPane`/shared adjustor docs. It is outside `0000ZK`, spans non-board pane families, and is non-source ABI wrapper territory; it is not an in-range source-bearing blocker.

## Supervisor Active Recheck

- The supervisor asked B001 to audit `0x00472070-0x00477790`, repair exact child pages first, raise reconstructable children only with evidence, repair parent gates, investigate raw helper islands, article-navigation helper ownership, destructor companions, and run targeted validator file scans.
- The assigned item required split repair before this master report. I repaired BoardList child/parent gates, repaired the shared navigation child, created exact destructor companion pages for the missing dialog wrappers, and converted the master aggregate into a non-emitting split inventory.
- Every source-bearing in-range function/helper is either represented by an exact child page at `85/85+` or is documented inside the exact child that owns the raw bytes. No source-bearing in-range helper remains only on the aggregate.

## Inference Research Guidance Check

- `by-structure.md` drove the direct-parent rule: exact reconstructable children must attach to direct class parents when the child/class both clear `85/85`; mixed containers remain parent-blank/non-emitting.
- `inference_research.md` drove the evidence ranking: caller fanout, vtable refs, constructor stores, boundary padding, raw helper behavior, and negative class-owner evidence were weighed instead of inheriting stale docs.
- Existing docs were treated as hypotheses. The stale aggregate said reconstructable source; IDA evidence contradicted that at aggregate level because exact children own the source-bearing subranges.

## Evidence Standards Used

- IDA MCP facts: function starts/ends, raw helper disassembly, decompilation observations, callers/xrefs, callees, destructor wrapper behavior, vtable/data refs, and padding checks.
- Documentation evidence: existing by-memory child pages, by-class pages, [UID:0000HT][BoardDialogs](../../../by-file/BoardDialogs.md), destructor thunk pages, generated memory coverage rows after validation.
- Negative evidence: no single class owns `0x004751c0`; aggregate has multiple source owners; destructor wrappers are compiler ABI glue; boundary gaps are padding.

## IDA MCP Facts

- Function/range facts: IDA inventory found 40 modeled function starts inside `0x00472070-0x00477790`, starting with `sub_472070` and ending with `sub_477590` ending at `0x00477790`.
- Raw helper facts: IDA/raw scans show raw source-shaped helper bodies in the BoardListPane, ArticleListDialog, ArticleListPane, ArticleNavigation, ArticleDialog, and NewArticleDialog child ranges; these are now documented in exact children.
- Data/table/padding facts: `0x00473ff3-0x00474014` and `0x004765fe-0x00476618` are switch-table bytes owned by their dispatchers; prefix `0x00472069-0x00472070` and successor `0x00477790-0x004777a0` are only `0xcc` padding.
- Xref facts: `xrefs_to 0x004751c0` returns `0x00473df6`, `0x00474d91`, `0x00474dea`, `0x004771a2`, `0x00478232`, `0x00479031`, and `0x004790f1`, crossing article-list, article-pane, new-article, predefined-form, and transfer-reply alert paths.
- Destructor facts: `0x0047e950`, `0x0047e990`, and `0x0047ea10` are `0x3b`-byte scalar deleting destructor wrappers calling `DialogInSession` cleanup `0x004a1450` and conditionally freeing with `0x004f4ac0`.
- Negative IDA facts: no IDA evidence supports one source-bearing function/class for the full aggregate; no class-only owner fits the navigation helper island; destructor wrappers should not be handwritten reconstruction targets.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00472070-0x004729dd` | [UID:0002EJ][BoardListDialogCore](../../../by-memory/0x00472070-0x004729dd.BoardListDialogCore.md) | `BoardListDialog` constructor/virtual/helper core | true | [UID:00000Z][BoardListDialog](../../../by-class/BoardListDialog.md) | `85/88` | Repaired by B001-025; exact child and parent clear `85/85`. |
| `0x004729e0-0x00472bf5` | [UID:0002V9][BoardListPaneCore](../../../by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md) | `BoardListPane` raw helper and virtual core | true | [UID:000010][BoardListPane](../../../by-class/BoardListPane.md) | `85/88` | Repaired by B001-025; raw helpers documented, parent clears `85/85`. |
| `0x00472c00-0x004748ea` | [UID:00030G][ArticleListDialogCore](../../../by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md) | article-list dialog method/raw island | true | [UID:00000K][ArticleListDialog](../../../by-class/ArticleListDialog.md) | `85/88` | Existing exact child already assigned. |
| `0x004748f0-0x004751b1` | [UID:00030I][ArticleListPaneCore](../../../by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) | article-list pane method/raw island | true | [UID:00000L][ArticleListPane](../../../by-class/ArticleListPane.md) | `85/87` | Existing exact child already assigned. |
| `0x004751c0-0x004753df` | [UID:00030H][ArticleNavigationHelpers](../../../by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md) | shared article navigation packet helpers | true | [UID:0000HT][BoardDialogs](../../../by-file/BoardDialogs.md) | `85/89` | Repaired by B001-025; file-level owner assigned. |
| `0x004753e0-0x00476c0a` | [UID:00030J][ArticleDialogCore](../../../by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md) | article-view dialog method/raw island | true | [UID:00000J][ArticleDialog](../../../by-class/ArticleDialog.md) | `85/88` | Existing exact child already assigned. |
| `0x00476c10-0x00477790` | [UID:00030K][NewArticleDialogCore](../../../by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md) | normal article composer core | true | [UID:00008Y][NewArticleDialog](../../../by-class/NewArticleDialog.md) | `85/87` | Existing exact child already assigned. |
| `0x00472070-0x00477790` | [UID:0000ZK][BoardArticleDialogs](../../../by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) | mixed aggregate/container | false | blank | `90/91` | Converted by B001-025 to parent-blank non-emitting split inventory. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00472070` | callers `0x00471604`, `0x00471921` | `BoardListDialog` construction from bulletin-session flow. |
| `0x00472b5e -> 0x004728a0` | BoardListPane activation tail jump | Confirms pane child calls back into direct `BoardListDialog` owner. |
| `0x00472ca0` | callers `0x00471695`, `0x004719e1` | `ArticleListDialog` construction from bulletin-session flow. |
| `0x004748f0` | callers `0x00472e04`, `0x00473410` | `ArticleListPane` constructed by `ArticleListDialog`. |
| `0x004751c0` | xrefs `0x00473df6`, `0x00474d91`, `0x00474dea`, `0x004771a2`, `0x00478232`, `0x00479031`, `0x004790f1` | Shared helper across article-list, new-article, predefined-form, and transfer-reply paths; rejects any single class parent. |
| `0x004753e0` | caller `0x00471b7a` | `ArticleDialog` construction from bulletin-session flow. |
| `0x00476c10` | caller `0x00471371` | `NewArticleDialog` construction from bulletin-session flow. |
| `0x00477590` | caller `0x004771ee` | NewArticle command handler reaches post-packet sender. |
| `0x0047e950` | refs from adjustor thunks and vtables `0x00613f10`, `0x00614238` | `ArticleDialog` scalar deleting destructor wrapper is class evidence but non-emitting. |
| `0x0047e990` | refs from adjustor thunks and vtable `0x00613dac` | `ArticleListDialog` scalar deleting destructor wrapper is class evidence but non-emitting. |
| `0x0047ea10` | refs from adjustors and vtables `0x00613ba8`, `0x00613c48`, `0x00613fb0`, `0x0061443c` | Shared bulletin/board/article scalar deleting destructor wrapper is non-emitting ABI glue. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: the seven exact child pages already held the right high-level split; `BoardDialogs.md` already cleared `85/86`; article-list/article-dialog/new-article class pages already cleared `85/85`; vtable-family docs and destructor thunk docs support class identities.
- Existing docs that were stale or incomplete: the aggregate still claimed `RECONSTRUCTABLE:TRUE` at `82/87`; `BoardListDialog`, `BoardListPane`, and their exact children were stuck at `78/88`; `ArticleNavigationHelpers` was `80/88` and unassigned despite cross-class evidence; destructor companions were loose address notes without exact pages.
- Generated/coverage report state after validation: `0000ZK` now appears as `not_reconstructable`; `0002EJ`, `0002V9`, and `00030H` appear assigned to `00000Z`, `000010`, and `0000HT`; `00033N`, `00033O`, and `00033P` appear as non-reconstructable.

## Ranked Ownership Analysis

### 1. Exact child split plus parent-blank aggregate

- Evidence for: IDA function inventory proves multiple class/function owners; exact child pages cover all source-bearing subranges; raw helpers are documented in child pages; boundary padding is known; by-structure supports containers when a range is mixed.
- Evidence against: final original source file partition is still inferred, so `BoardDialogs.cpp` versus `ArticleDialogs.cpp` is not final.
- Decision: accepted. This is the only disposition that preserves direct ownership and avoids duplicate reconstruction.

### 2. Assign the full aggregate to BoardDialogs

- Evidence for: all source-bearing children belong under the board/article dialog source family; [UID:0000HT][BoardDialogs](../../../by-file/BoardDialogs.md) is `85/86`.
- Evidence against: the aggregate is not one source-bearing unit; exact children already route to classes or the file-level shared helper; assigning the aggregate would duplicate children and overstate direct source ownership.
- Decision: rejected for `0000ZK`. `BoardDialogs` is the correct file parent for shared helpers and class parents, not for this aggregate.

### 3. Assign the shared navigation helper to one class

- Evidence for: `ArticleListDialog` and `ArticleListPane` have nearby callers; `NewArticleDialog` also reaches the helper.
- Evidence against: `xrefs_to 0x004751c0` crosses article-list, new-article, predefined-form, `TransferReplyAlert`, and `TransferReplyPredefinedAlert` paths. No single class owns all uses.
- Decision: rejected. [UID:00030H][ArticleNavigationHelpers](../../../by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md) is assigned directly to [UID:0000HT][BoardDialogs](../../../by-file/BoardDialogs.md).

### 4. Treat destructor wrappers as reconstructable class methods

- Evidence for: vtable refs tie wrappers to semantic classes.
- Evidence against: wrappers are standard scalar deleting destructor ABI glue calling shared `DialogInSession` cleanup and conditional free; source should express the class hierarchy and let the compiler regenerate them.
- Decision: rejected. Exact non-emitting companion pages now document the wrappers with blank parents.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file owner is recommended.
- Likely full contents: current [UID:0000HT][BoardDialogs](../../../by-file/BoardDialogs.md) remains the practical `NexusTK/ui/dialogs/` board/article bucket, with possible future split into `BoardDialogs.cpp`, `ArticleDialogs.cpp`, `BulletinDialogs.cpp`, and alert/predefined-form companions.
- Candidate related items that belong: the seven exact children listed above, plus existing prefix/successor/alert companion pages as cross-references.
- Candidate related items rejected: `0x0047e9d0` shared list-like destructor target, because it spans non-board pane families and is outside this aggregate.
- Standalone, narrow, or broad source-file inference: broad source-bucket inference, not a new standalone owner.

## Negative Evidence Summary

- Consumer/read xrefs alone were not treated as ownership proof. For `0x004751c0`, the full caller fanout is negative evidence against a class owner and positive evidence for a file-level helper bucket.
- Nearby address adjacency was not enough to fold raw helpers into the aggregate; each raw island stayed with the exact child range whose behavior and boundaries it belongs to.
- Destructor vtable refs prove semantic class relationships but not handwritten source ownership; scalar deleting destructor wrappers remain non-emitting.
- The aggregate's high address contiguity does not imply one C++ source item. IDA function starts, vtables, constructors, raw helpers, jump tables, and padding split it cleanly into children.

## Final Recommendation

- Exact changes applied: converted `0000ZK` to a `90/91` non-reconstructable split inventory; repaired BoardListDialog/BoardListPane child and parent gates to `85/88`; repaired ArticleNavigationHelpers to `85/89` and assigned it to `0000HT`; created three exact non-emitting destructor companion pages.
- Exact parent assignments applied: `0002EJ -> 00000Z`, `0002V9 -> 000010`, `00030H -> 0000HT`; existing assignments for `00030G`, `00030I`, `00030J`, and `00030K` remain correct.
- Exact items left unassigned and why: `0000ZK` remains parent-blank because it is a non-emitting aggregate; `00033N`, `00033O`, and `00033P` remain parent-blank because they are compiler-generated ABI wrappers; external `0x0047e9d0` remains outside this assignment and is not source-bearing in-range work.
- Exact future work outside this assignment scope: optional separate audit for shared destructor `0x0047e9d0` if the supervisor wants exact ABI-wrapper coverage across non-board pane families.

## Follow-Up Actions

- Supervisor actions: review this report and, if accepted, execute/archive it. No `Supervisor_notes.md` edit was made by B001.
- A-agent actions: none required for in-range source-bearing children after this pass.
- B001 future research actions: only if assigned, audit `0x0047e9d0` as a shared non-emitting pane destructor outside the `0000ZK` target.

## Confidence

- Recommendation confidence: high. IDA and by-structure evidence both support parent-blank aggregate plus exact child ownership.
- Score confidence: high for `0000ZK 90/91`, repaired children/parents, and destructor companion non-emitting status.
- Remaining uncertainty: final original source-file partition and final names for several raw helpers/fields.

## Validator Results

- Commands run: one targeted `python source-3\project-documentation\tools\validator.py --mode file --file <path> --apply` scan for each changed/created by-* file listed below.
- Syntax note: an initial shorthand `validator.py file <path>` attempt failed with command-usage output before scanning; the actual targeted scans used the documented `--mode file --file` syntax.

| File | Validator result |
| --- | --- |
| `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md` | OK; validator updated completion/confidence to `90/91`, registry reconstructable state `true -> false`, and memory coverage to `not_reconstructable`. |
| `by-memory/0x00472070-0x004729dd.BoardListDialogCore.md` | OK; targeted file scan completed. |
| `by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md` | OK; targeted file scan completed. |
| `by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md` | OK; targeted file scan completed with parent `0000HT` retained. |
| `by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md` | OK; targeted file scan completed. |
| `by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md` | OK; targeted file scan completed. |
| `by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md` | OK; targeted file scan completed. |
| `by-class/BoardListDialog.md` | OK; targeted file scan completed. |
| `by-class/BoardListPane.md` | OK; targeted file scan completed. |
| `by-class/ArticleDialog.md` | OK; targeted file scan completed. |
| `by-class/ArticleListDialog.md` | OK; targeted file scan completed. |
| `by-class/BulletinDialog.md` | OK; targeted file scan completed. |
| `by-class/NewArticleDialog.md` | OK; targeted file scan completed. |
| `by-file/BoardDialogs.md` | OK; targeted file scan completed. |

- Aggregate result: the final validator batch ended with `ALL_TARGETED_FILE_SCANS_OK`.
- Pending scans: none for changed by-* files.
- Validator side effects: validator reported autogen backup creation, registry rebuild/update, `auto-generated/-ag-memory-coverage.md` update, and projected stats update as part of `--apply`.

## Changed Files

- Created:
  - `by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md`
  - `by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md`
  - `by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md`
  - `tools/leaser/Agents/Agent-B001/research/0000ZK-BoardArticleDialogs.md`
- Modified:
  - `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`
  - `by-memory/0x00472070-0x004729dd.BoardListDialogCore.md`
  - `by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md`
  - `by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md`
  - `by-class/BoardListDialog.md`
  - `by-class/BoardListPane.md`
  - `by-class/ArticleDialog.md`
  - `by-class/ArticleListDialog.md`
  - `by-class/BulletinDialog.md`
  - `by-class/NewArticleDialog.md`
  - `by-file/BoardDialogs.md`
  - `auto-generated/-ag-memory-coverage.md` by validator
  - `project-level/-auto-completion-stats.md` reported by validator
- Renamed:
  - None.
- Moved to executed:
  - None.
