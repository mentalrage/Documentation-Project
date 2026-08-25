** TARGET-REPORT-UID:0000ZO **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000ZO MailDialogs Source Split Research

## Finalized Report / Current Recommendation

- Current recommendation: split [UID:0000ZO] into exact executable children, then reclassify the broad page as a non-emitting mixed source-family inventory.
- Final disposition: do not keep `0x00479110-0x0047ec2b.MailDialogs` as one reconstructable/emitting MailDialogs source item after split repair.
- Required action: create the missing exact children listed below, refresh existing low-score exact mail-delete children where the current evidence supports `85+`, update support docs, then set [UID:0000ZO] to `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank final C++.
- Confidence: high for the split/reclassification decision; medium-high for a few helper names where the behavior is clear but final source names are not.

## Supporting Research

## Target

- Target UID: [UID:0000ZO]
- Target path: `by-memory/0x00479110-0x0047ec2b.MailDialogs.md`
- Source queue/report row: memory-tool largest reconstructable leaf, `auto-generated/by-memory-tool-report.md` row 11: `0x00479110-0x0047e040` from this page, 20272 bytes, reconstructable.
- Current state checked: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000KZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KZ`, blank final C++.
- Current direct file route: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), `NexusTK/ui/dialogs/MailDialogs.cpp`.

## Executive Recommendation

[UID:0000ZO] is not a safe final source-emitting unit. It begins with core mail dialog code, but its later address span includes current [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) alert-wrapper classes, board/article-only `ConfirmDeleteAlert` and `DeleteReplyAlert` bodies, [UID:00001D][BulletinSession](by-class/BulletinSession.md) cleanup glue, shared compiler-generated destructor wrappers, and existing exact child pages with non-MailDialogs owners.

The current page should become the same kind of split inventory as [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md), but with a MailDialogs core prefix. The source-bearing code should move to exact child pages routed to `MailListDialog`, `MailListPane`, `MailDialog`, `NewMailDialog`, `BulletinReplyAlerts` alert classes, `DeleteReplyAlert`, and `BulletinSession` as appropriate. Compiler-generated thunks/destructor wrappers should be ignored or non-emitting.

Do not write final C++ for [UID:0000ZO]. The parent is a migration/split index, not an original source body.

## Supervisor Active Recheck

- Supervisor asked for a memory-tool largest-range/source-split audit, not routine score polishing.
- Direct edits to by-* docs, generated reports, IDA DB, and `by-memory/-coverage-report.md` are prohibited for this assignment. This report is the only file changed by B001.
- B001 split-first policy would normally support direct child creation, but the assignment explicitly makes this report-only. All changes below are supervisor actions.

## Inference Research Guidance Check

- `by-structure.md` requires `CANONICAL_OWNER` to be the narrowest true semantic owner and requires non-emitting containers when exact children carry the real source ownership.
- `inference_research.md` warns that address adjacency alone is weak source-file evidence. Here, adjacency conflicts with direct caller/vtable/global evidence, so the source split should follow the stronger evidence.
- Existing docs were treated as hypotheses. IDA MCP and raw-byte checks confirm some current docs, but contradict the current parent/emitter route for the full [UID:0000ZO] range.

## Evidence Standards Used

Evidence checked:

- Live IDA MCP session `b001_maildialogs_0000ZO_20260616` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA `entity_query`, `lookup_funcs`, `analyze_component`, `analyze_function`, `disasm`, `find_regex`, and `trace_data_flow`.
- Raw PE section/byte scan over `NexusTK.exe`.
- Existing target/support docs: [UID:0000ZO], [UID:0000ZM], [UID:0000KZ], [UID:0000HW], [UID:0000HX], mail/alert/BulletinSession class pages, vtable pages [UID:000321]/[UID:000322], singleton docs, generated memory report, and `by-memory/-coverage-report.md`.
- Negative evidence: no `.pdb`, no `.cpp` source-path strings, no raw pointer/call hits to unmodeled constructor starts, and no safe IDA DB repair requirement.

## IDA MCP And Raw Facts

### Function / Range Facts

`entity_query` over `0x00478f80-0x0047ec80` found the expected predecessor/successor functions and 78 modeled function objects inside [UID:0000ZO]. The important current boundaries are:

| Range | IDA facts | Source meaning |
| --- | --- | --- |
| `0x00479110-0x0047a894` | eight modeled functions from `sub_479110` through `sub_47A760` | `MailListDialog` method island. |
| `0x0047a8a0-0x0047b110` | nine modeled functions from `sub_47A8A0` through `sub_47B080` | `MailListPane` plus local page-request helper. |
| `0x0047b220-0x0047cc74` | eight modeled functions from `sub_47B220` through `sub_47CB40` | `MailDialog` read/reply island. |
| `0x0047cd80-0x0047d04a` | `sub_47CD80`, only caller `sub_47C730` | MailDialog Ctrl+S/save-mail helper, not NewMailDialog. |
| `0x0047d050-0x0047e033` | seven modeled functions from `sub_47D050` through `sub_47DCB0` | `NewMailDialog` compose/send island. |
| `0x0047e040-0x0047e088` | no IDA function object | exact existing raw `MailTransferReplyAlert` constructor child. |
| `0x0047e090-0x0047e0ff` | modeled function, vtable-only xref `0x00614538` | missing exact `MailTransferReplyAlert::OnConfirm` child. |
| `0x0047e100-0x0047e2e4` | existing raw/action children | board/article `ConfirmDeleteAlert`, not MailDialogs-owned. |
| `0x0047e2f0-0x0047e4a6` | modeled constructor/destructor/getter/action island | board/article `DeleteReplyAlert`, not MailDialogs-owned. |
| `0x0047e4b0-0x0047e694` | existing raw/action children | `ConfirmDeleteMailAlert`, currently routed to `BulletinReplyAlerts`. |
| `0x0047e6a0-0x0047e836` | existing exact `MailDeleteReplyAlert` children | currently routed to `BulletinReplyAlerts`. |
| `0x0047e840-0x0047e84b` | `sub_47E840`: `g_pBulletinSession = 0` | BulletinSession constructor-unwind cleanup, not MailDialogs. |
| `0x0047e850-0x0047e855` | thunk: `jmp sub_4A1450` | compiler-generated base destructor jump thunk. |
| `0x0047e855-0x0047e947` | existing adjustor-thunk page | compiler-generated, ignored. |
| `0x0047e950-0x0047ec2b` | dense scalar-deleting-destructor strip | mixed compiler glue and source-destructor semantics; some exact pages exist, several are missing. |

### Xref / Caller Facts

- `0x00479110` callers: `sub_471550` and `sub_471DD0`, code xrefs at `0x0047173f` and `0x00471e51`.
- `0x0047b220` callers: `sub_471550` and `sub_471EA0`, code xrefs at `0x004717f6` and `0x00471f71`.
- `0x0047d050` caller: `sub_4713B0`, code xref at `0x00471440`.
- `0x0047cd80` caller: only `sub_47C730`; decompilation/callee/string evidence shows file-save behavior with `From :`, `Date :`, and `Subject :` text, so direct owner should be `MailDialog`, not `NewMailDialog`.
- `0x0047e2f0` callers: `sub_474230`, `sub_4747D0`, `sub_4768C0`, and `sub_4769F0`; these are board/article paths, not mail-list/read/compose paths.
- `0x0047e090`, `0x0047e160`, `0x0047e390`, `0x0047e510`, and `0x0047e730` have vtable data xrefs and no ordinary direct callers; this matches virtual alert action methods.
- `0x0047e840` has code xref from `0x005fb071` and data write to `0x0067adc0`.
- `trace_data_flow backward 0x0067adc0` confirms `0x0047e840` and `0x0047eab0` as BulletinSession singleton clears alongside constructor/core writes at `0x004711a2`, `0x004711a9`, and `0x0047128a`.

### Vtable / Type Facts

IDA named data over `0x00614180-0x00614820` confirms the owner sequence:

- `MailListDialog`, `MailListPane`, `MailDialog`, and `NewMailDialog` vtables at `0x00614238-0x006144d0`, already split as [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) and owned by [UID:0000KZ].
- `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert` vtables interleaved with `ConfirmDeleteAlert` and `DeleteReplyAlert` at `0x006144dc-0x0061480c`, already split as [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) and owned by [UID:0000HW].
- The shared board/article `ConfirmDeleteAlert` and `DeleteReplyAlert` vtables in the middle of the mail-alert strip are direct evidence that [UID:0000ZO] is mixed-owner beyond the core mail range.

### Raw PE Facts

Raw PE section scan:

- `.text`: RVA `0x1000-0x20c600`, raw `0x400-0x20ba00`.
- `.rdata`: RVA `0x20d000-0x26c200`.
- `.data`: RVA `0x26d000-0x29ce24`.
- No `.pdb` or `.cpp` source-path strings were found.
- String/type-info hits include RTTI names for `MailListDialog`, `MailListPane`, `MailDialog`, `NewMailDialog`, `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert`, but no source-file path.
- Raw constructor-shaped starts `0x00478f90`, `0x00479050`, `0x0047e040`, `0x0047e100`, `0x0047e4b0`, and `0x0047e6a0` have no absolute VA hits, no RVA hits, and no direct `call`/`jmp rel32` hits in the scanned PE.
- Padding bytes are confirmed as `0xcc` at the important splits, including `0x0047e088-0x0047e090`, `0x0047e0ff-0x0047e100`, `0x0047e158-0x0047e160`, `0x0047e2e4-0x0047e2f0`, `0x0047e4a6-0x0047e4b0`, `0x0047e508-0x0047e510`, `0x0047e694-0x0047e6a0`, `0x0047e836-0x0047e840`, `0x0047ec2b-0x0047ec30`, and `0x0047ec6b-0x0047ec70`.

## Documentation Evidence And IDA Status

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) correctly owns the core mail dialog classes and vtable child [UID:000321], but still lists mail alert companions as possible/proposed contents. IDA supports mail construction/use there, but current direct ownership for alert wrappers is [UID:0000HW].
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) currently owns the alert-wrapper class pages and vtable child [UID:000322]. IDA supports this as the current best bucket because the alert strip is shared/interleaved with board/article wrappers.
- [UID:0000ZM][BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md) is already a non-emitting mixed overlap/index map. [UID:0000ZO] should follow that model after its own core prefix is split.
- [UID:00001D][BulletinSession](by-class/BulletinSession.md) and [UID:0000HX][BulletinSession](by-file/BulletinSession.md) already document `0x0047ea90` and the `0x0067adc0` lifecycle. `0x0047e840` is mentioned in singleton docs but still lacks exact executable handling.
- `by-memory/-coverage-report.md` has [UID:0000ZO] as a reconstructable MailDialogs aggregate even though child rows around it already prove mixed ownership. This row should be replaced after split repair.

## Recommended Child / Split Inventory

Supervisor should create or hand off these missing exact child pages. Existing exact children listed as "keep" do not need recreation.

| Range / Item | Proposed page name | Reconstructable | Owner / emitter | Rationale |
| --- | --- | --- | --- | --- |
| `0x00479110-0x0047a894` | `MailListDialogCore` | `TRUE` | [UID:00007L] / [UID:00007L] | Eight-function `MailListDialog` island; constructor callers from BulletinSession, local packet/list methods, mail vtable stores. |
| `0x0047a8a0-0x0047b110` | `MailListPaneCore` | `TRUE` | [UID:00007M] / [UID:00007M] | Nine-function list-pane island; constructor only from `MailListDialog`, vtable stores, row/list/page request behavior. |
| `0x0047b220-0x0047cc74` | `MailDialogCore` | `TRUE` | [UID:00007K] / [UID:00007K] | Eight-function read/reply dialog island; BulletinSession open callers, command/reply/delete-reply paths, mail vtable stores. |
| `0x0047cd80-0x0047d04a` | `MailDialogSaveMailToFileShortcutHelper` | `TRUE` | [UID:00007K] / [UID:00007K] | Only caller is `MailDialog::OnKeyInput` at `0x0047c765`; strings and file APIs match Ctrl+S mail export/save behavior. |
| `0x0047d050-0x0047e033` | `NewMailDialogCore` | `TRUE` | [UID:000096] / [UID:000096] | Seven-function compose/send island; constructor caller at `0x00471440`, compose vtable stores, send/transfer-reply flow. |
| `0x0047e040-0x0047e088` | existing [UID:0003O8] | keep | [UID:00007N] / [UID:00007N] | Exact raw constructor already exists. |
| `0x0047e090-0x0047e0ff` | `MailTransferReplyAlertOnConfirm` | `TRUE` | [UID:00007N] / [UID:00007N] | Missing exact virtual action child; vtable xref `0x00614538`, callees `0x004a1250`, `0x0047b080`, `0x004a10e0`. |
| `0x0047e100-0x0047e2e4` | existing [UID:0002US], [UID:0002SE] | keep | [UID:000033] | Board/article confirm-delete alert, not MailDialogs-owned. |
| `0x0047e2f0-0x0047e4a6` | `DeleteReplyAlertMethods` | `TRUE` | [UID:00003O] / [UID:00003O] | Missing exact board/article reply-delete constructor/destructor/getter/action island; callers are board/article only. |
| `0x0047e4b0-0x0047e694` | existing [UID:0003MZ], [UID:0002SF] | keep | [UID:000034] | Exact mail delete-confirm constructor/action children already exist. |
| `0x0047e6a0-0x0047e836` | existing [UID:0002T7], [UID:0002T8], [UID:0002T9] | keep, refresh scores if supervisor agrees | [UID:00007J] | Exact mail delete-reply children exist but completion values remain `82/82/84`; current class/live evidence supports bringing them to `85+` in the same split repair. |
| `0x0047e840-0x0047e84b` | `BulletinSessionConstructorUnwindSingletonClear` | `FALSE` | `NONE` | EH/unwind-style helper that only clears `g_pBulletinSession`; semantic owner is [UID:00001D]/[UID:0000QG], but no source body should emit. |
| `0x0047e850-0x0047e855` | `DialogSessionDestructorJumpThunk` or `-ignored.md` entry | `FALSE` | `NONE` | Pure `jmp sub_4A1450` compiler thunk with funclet xrefs; do not emit source. |
| `0x0047e855-0x0047e947` | existing [UID:0000ZP] / [UID:0000ZQ] | keep | `NONE` | Existing ignored adjustor-thunk coverage. |
| `0x0047e950-0x0047e98b` | existing [UID:00033N] | keep | `NONE` | Existing ignored `ArticleDialog` scalar deleting destructor wrapper. |
| `0x0047e990-0x0047e9cb` | existing `ArticleListDialogScalarDeletingDestructor` | keep | `NONE` | Existing ignored scalar deleting destructor wrapper. |
| `0x0047e9d0-0x0047ea0b` | `SharedListPaneScalarDeletingDestructor2` | `FALSE` | `NONE` | Missing shared `ListPane`-derived scalar deleting destructor wrapper; vtable refs include `MailListPane` and unrelated list panes, so no single source owner. |
| `0x0047ea10-0x0047ea4b` | existing `BulletinDialogSharedScalarDeletingDestructor` | keep | `NONE` | Existing ignored scalar deleting destructor wrapper. |
| `0x0047ea50-0x0047ea8b` | existing [UID:0000ZR] | keep | `NONE` | Existing ignored shared list-pane scalar deleting destructor. |
| `0x0047ea90-0x0047eaef` | `BulletinSessionScalarDeletingDestructor` | `TRUE` | [UID:00001D] / [UID:00001D] | Missing exact source-destructor wrapper with BulletinSession vtable restores and `g_pBulletinSession` clear; already documented by class/file docs. |
| `0x0047eaf0-0x0047eb2b` | `SharedAlertPaneScalarDeletingDestructor` | `FALSE` | `NONE` | Missing shared alert scalar deleting wrapper; vtable refs span predefined/mail/confirm alert classes and unrelated users. |
| `0x0047eb30-0x0047eb8f` | `DeleteReplyAlertScalarDeletingDestructor` | `TRUE` | [UID:00003O] / [UID:00003O] | Missing exact `DeleteReplyAlert` scalar deleting destructor; restores vtables and clears `g_pDeleteReplyAlert`. |
| `0x0047eb90-0x0047ebef` | existing [UID:0002TA] | keep, refresh completion if supervisor agrees | [UID:00007J] | Exact `MailDeleteReplyAlert` scalar deleting destructor exists at `84/90`; current evidence supports at least `85/90`. |
| `0x0047ebf0-0x0047ec2b` | `MailDialogScalarDeletingDestructor` | `FALSE` | `NONE` | Missing exact scalar deleting destructor wrapper for `MailDialog`; analogous to existing non-emitting `ArticleDialogScalarDeletingDestructor`. |

Internal padding rows should be added or refreshed where validator/coverage expects them, using the raw-byte padding facts above. The current parent page can also carry padding as a non-emitting inventory, but exact padding rows are preferable for memory-tool cleanliness if the supervisor is doing a full split pass.

## Ranked Ownership Analysis

### 1. Split exact children; make [UID:0000ZO] non-emitting

Evidence for:

- The full range is proven mixed by IDA vtables and callers.
- Current exact children already route many later subranges to `BulletinReplyAlerts`, `DeleteReplyAlert`, `ConfirmDeleteAlert`, and `MailDeleteReplyAlert`.
- The memory-tool leaf `0x00479110-0x0047e040` shows the unsplit problem is now mostly the core mail prefix plus missing small exact children.
- Existing precedent: [UID:0000ZM] is already a non-emitting alert overlap/index map for much of the same physical neighborhood.

Evidence against:

- Exact by-memory pages do not yet exist for the large core mail method islands and several small destructor/session fragments.

Decision:

- Selected. Create children first, then reclassify the parent. Do not demote the parent before the exact child pages and coverage rows are ready unless the supervisor accepts a temporary broad-index state.

### 2. Keep [UID:0000ZO] as one reconstructable `MailDialogs.cpp` family page

Evidence for:

- The core prefix `0x00479110-0x0047e033` is strongly mail-dialog code.
- `MailDialogs.md` is a valid file root for `MailListDialog`, `MailListPane`, `MailDialog`, and `NewMailDialog`.

Evidence against:

- The later range includes board/article `ConfirmDeleteAlert`/`DeleteReplyAlert`, BulletinSession cleanup, shared destructor thunks, and multiple exact children already owned outside MailDialogs.
- Keeping one MailDialogs emitter would duplicate or misroute code that class/file pages already route to [UID:0000HW] and [UID:0000HX].
- `0x0047e2f0` has board/article-only callers, which directly contradicts MailDialogs ownership.

Decision:

- Rejected for final source structure.

### 3. Move all mail alert companions from `BulletinReplyAlerts` into `MailDialogs`

Evidence for:

- Mail alert vtable stores occur in mail-list/read/compose code.
- `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert` are mail-specific classes.

Evidence against:

- The alert strip is interleaved with shared board/article alert classes.
- Current class/global/vtable pages consistently route the alert wrapper bucket through [UID:0000HW].
- Construction/use sites do not prove declaration/source ownership; they can be inline construction of helper classes declared in a shared alert module.

Decision:

- Rejected as current action. Keep [UID:0000HW] routing, with the documented caveat that a later final-source pass may fold mail-only private alert classes into `MailDialogs.cpp` if stronger source evidence appears.

### 4. Treat [UID:0000ZO] as dead/duplicate or non-source

Evidence for:

- Some raw constructor starts have no direct xrefs and no IDA function objects.
- Many destructor thunks/scalar deleting destructors are compiler glue.

Evidence against:

- The core mail functions have live BulletinSession callers.
- Alert actions are vtable callbacks.
- Raw constructors have vtable stores and modeled inline construction mirrors.
- This is not dead code; it is a mixed source/codegen neighborhood.

Decision:

- Rejected. Only specific thunks/wrappers should be non-emitting; the core children remain reconstructable.

## Negative Evidence Summary

- No embedded `.pdb` or `.cpp` source-path metadata was found, so original file names cannot be proven directly.
- No raw VA/RVA/relative call hits were found for unmodeled constructor starts, so no IDA function creation is justified from reachability.
- Consumer/construction xrefs inside mail functions are not enough to move alert class ownership from `BulletinReplyAlerts` to `MailDialogs`; this is construction/use evidence, not declaration/source-file proof.
- Address adjacency is not enough to keep board/article `DeleteReplyAlert`, BulletinSession singleton cleanup, and shared destructor wrappers under MailDialogs.
- IDA function boundaries for modeled functions are stable; the safe action is documentation split, not IDA DB repair.

## Exact Supervisor Actions

### Target Metadata After Split

Apply only after child pages are created/validated:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep `EMITTER_POSITION_OPTIONAL` blank and keep final C++ blank.

Update [UID:0000ZO] body to describe it as a mixed source-family split inventory over:

- `MailDialogs` core children,
- `BulletinReplyAlerts` alert children,
- `BulletinSession` cleanup/destructor children,
- compiler-generated thunk/destructor-wrapper children,
- exact padding rows.

### Support Docs

1. [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
   - Keep `MailListDialog`, `MailListPane`, `MailDialog`, `NewMailDialog`, and the `0x0047cd80` save-mail helper as MailDialogs contents.
   - Move `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert` from "proposed contents" into a dependency/alternate-private-placement note unless the supervisor deliberately changes alert ownership.
   - Add links to the new exact core child pages.

2. [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
   - Add links for the new `MailTransferReplyAlertOnConfirm`, `DeleteReplyAlertMethods`, `DeleteReplyAlertScalarDeletingDestructor`, and shared alert destructor child if created.
   - Keep the current caveat that mail-only alert wrappers might later fold into `MailDialogs.cpp`.

3. [UID:0000HX][BulletinSession](by-file/BulletinSession.md), [UID:00001D][BulletinSession](by-class/BulletinSession.md), [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md), and [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md)
   - Add links to exact `0x0047e840-0x0047e84b` cleanup and `0x0047ea90-0x0047eaef` scalar-deleting-destructor pages after creation.

4. [UID:0000ZM][BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
   - Refresh the covered-range table to replace broad references for the now-exact children.
   - Keep `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitter.

5. Existing exact mail-delete child pages [UID:0002T7], [UID:0002T8], [UID:0002T9], and [UID:0002TA]
   - Supervisor should consider a focused score/evidence refresh in the same split batch. Current live evidence supports `85+` completion for at least [UID:0002T7]/[UID:0002T8]/[UID:0002T9] and `85/90` for [UID:0002TA], but B001 did not edit them directly.

### Coverage Report Replacement

Do not edit directly as B001. After split repair, replace the existing [UID:0000ZO] row in `by-memory/-coverage-report.md` where it currently appears after [UID:0002TA] and before [UID:0000ZP] with:

```text
    - [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md) 0x00479110-0x0047ec2b | mixed source-family split index | MailDialogs : not_reconstructable : 88% : strong : B001 2026-06-16 source-split audit reclassifies this range as a non-emitting mixed MailDialogs/BulletinReplyAlerts/BulletinSession inventory; exact mail-list, mail-list-pane, mail-read, save-mail shortcut, compose, mail-alert, board/delete-alert, BulletinSession cleanup, thunk, scalar-destructor, and padding child pages carry source ownership or compiler-glue exclusion, so no aggregate final C++ should emit from this range.
```

If supervisor creates the recommended child pages in one pass, insert their rows as children of [UID:0000ZO] in address order. Use the UIDs assigned by validator. Suggested row text can follow this shape:

```text
      - [UID:<new>][0x00479110-0x0047a894.MailListDialogCore](by-memory/0x00479110-0x0047a894.MailListDialogCore.md) 0x00479110-0x0047a894 | class method island | MailListDialogCore : reconstructable : 86% : strong : Exact MailListDialog constructor/list/action/packet-update island assigned to [UID:00007L][MailListDialog](by-class/MailListDialog.md); live IDA confirms eight modeled functions, BulletinSession constructor callers, local call graph, vtable stores, and MailDialogs file route; final C++ remains blank pending source-quality field/helper names.
      - [UID:<new>][0x0047a8a0-0x0047b110.MailListPaneCore](by-memory/0x0047a8a0-0x0047b110.MailListPaneCore.md) 0x0047a8a0-0x0047b110 | class method island | MailListPaneCore : reconstructable : 86% : strong : Exact MailListPane list row/render/page-request island assigned to [UID:00007M][MailListPane](by-class/MailListPane.md); live IDA confirms nine modeled functions, constructor calls only from MailListDialog, vtable stores, row operations, and local mail request helper.
      - [UID:<new>][0x0047b220-0x0047cc74.MailDialogCore](by-memory/0x0047b220-0x0047cc74.MailDialogCore.md) 0x0047b220-0x0047cc74 | class method island | MailDialogCore : reconstructable : 86% : strong : Exact MailDialog read/reply island assigned to [UID:00007K][MailDialog](by-class/MailDialog.md); live IDA confirms eight modeled functions, BulletinSession open callers, command/reply/delete cases, vtable stores, and MailDialogs route.
      - [UID:<new>][0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper](by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md) 0x0047cd80-0x0047d04a | mail helper | MailDialogSaveMailToFileShortcutHelper : reconstructable : 85% : strong : Exact Ctrl+S mail save/export helper assigned to [UID:00007K][MailDialog](by-class/MailDialog.md); live IDA confirms sole caller `0x0047c765`, file/path APIs, and `From :`/`Date :`/`Subject :` text.
      - [UID:<new>][0x0047d050-0x0047e033.NewMailDialogCore](by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md) 0x0047d050-0x0047e033 | class method island | NewMailDialogCore : reconstructable : 86% : strong : Exact NewMailDialog compose/send island assigned to [UID:000096][NewMailDialog](by-class/NewMailDialog.md); live IDA confirms seven modeled functions, BulletinSession reply-open caller, vtable stores, send/transfer-reply behavior, and MailDialogs route.
      - [UID:<new>][0x0047e090-0x0047e0ff.MailTransferReplyAlertOnConfirm](by-memory/0x0047e090-0x0047e0ff.MailTransferReplyAlertOnConfirm.md) 0x0047e090-0x0047e0ff | virtual alert action | MailTransferReplyAlertOnConfirm : reconstructable : 86% : strong : Exact MailTransferReplyAlert confirm action assigned to [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md); live IDA confirms modeled boundary, vtable data xref `0x00614538`, mail navigation helper call `0x0047b080`, and optional session pop.
      - [UID:<new>][0x0047e2f0-0x0047e4a6.DeleteReplyAlertMethods](by-memory/0x0047e2f0-0x0047e4a6.DeleteReplyAlertMethods.md) 0x0047e2f0-0x0047e4a6 | class method island | DeleteReplyAlertMethods : reconstructable : 86% : strong : Exact board/article DeleteReplyAlert constructor/destructor/getter/action island assigned to [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md); live IDA confirms board/article-only constructor callers, singleton writes, vtable stores, and confirm-action vtable slot.
      - [UID:<new>][0x0047e840-0x0047e84b.BulletinSessionConstructorUnwindSingletonClear](by-memory/0x0047e840-0x0047e84b.BulletinSessionConstructorUnwindSingletonClear.md) 0x0047e840-0x0047e84b | compiler cleanup | BulletinSessionConstructorUnwindSingletonClear : ignored : 85% : strong : Exact EH/unwind cleanup helper that only clears `g_pBulletinSession`; semantic evidence belongs to [UID:00001D][BulletinSession](by-class/BulletinSession.md) and [UID:0000QG][g_pBulletinSession](by-global/g_pBulletinSession.md), but no handwritten source should emit.
      - [UID:<new>][0x0047e850-0x0047e855.DialogSessionDestructorJumpThunk](by-memory/0x0047e850-0x0047e855.DialogSessionDestructorJumpThunk.md) 0x0047e850-0x0047e855 | compiler thunk | DialogSessionDestructorJumpThunk : ignored : 85% : strong : Exact five-byte jump thunk to `sub_4A1450` with funclet xrefs; compiler-generated destructor glue, no source emission.
      - [UID:<new>][0x0047e9d0-0x0047ea0b.SharedListPaneScalarDeletingDestructor2](by-memory/0x0047e9d0-0x0047ea0b.SharedListPaneScalarDeletingDestructor2.md) 0x0047e9d0-0x0047ea0b | shared scalar deleting destructor | SharedListPaneScalarDeletingDestructor2 : ignored : 85% : strong : Exact compiler-generated scalar deleting destructor shared by MailListPane and unrelated list-pane vtables; no single source owner and no handwritten source emission.
      - [UID:<new>][0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor](by-memory/0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor.md) 0x0047ea90-0x0047eaef | scalar deleting destructor | BulletinSessionScalarDeletingDestructor : reconstructable : 85% : strong : Exact BulletinSession scalar deleting destructor assigned to [UID:00001D][BulletinSession](by-class/BulletinSession.md); live IDA confirms vtable restores, `g_pBulletinSession` clear, base cleanup, vtable data ref, and adjustor-thunk refs.
      - [UID:<new>][0x0047eaf0-0x0047eb2b.SharedAlertPaneScalarDeletingDestructor](by-memory/0x0047eaf0-0x0047eb2b.SharedAlertPaneScalarDeletingDestructor.md) 0x0047eaf0-0x0047eb2b | shared scalar deleting destructor | SharedAlertPaneScalarDeletingDestructor : ignored : 85% : strong : Exact compiler-generated shared alert destructor wrapper with vtable refs from predefined, mail-transfer, confirm-delete, confirm-delete-mail, and other alert classes; no single source owner and no handwritten source emission.
      - [UID:<new>][0x0047eb30-0x0047eb8f.DeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb30-0x0047eb8f.DeleteReplyAlertScalarDeletingDestructor.md) 0x0047eb30-0x0047eb8f | scalar deleting destructor | DeleteReplyAlertScalarDeletingDestructor : reconstructable : 85% : strong : Exact DeleteReplyAlert scalar deleting destructor assigned to [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md); live IDA confirms vtable restores, `g_pDeleteReplyAlert` clear, base cleanup, vtable data ref, and adjustor-thunk refs.
      - [UID:<new>][0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor](by-memory/0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor.md) 0x0047ebf0-0x0047ec2b | scalar deleting destructor | MailDialogScalarDeletingDestructor : ignored : 85% : strong : Exact compiler-generated scalar deleting destructor wrapper for MailDialog, analogous to the non-emitting ArticleDialog wrapper; semantic class owner is [UID:00007K][MailDialog](by-class/MailDialog.md), but no standalone source should emit.
```

### IDA DB

No IDA DB edit is recommended.

- Do not force raw constructor starts into IDA functions for this task; the no-function/no-direct-xref state is documented and current exact raw pages handle them.
- Do not rename modeled functions in IDA during this report-only split audit; documentation can carry the source names after validator-created pages exist.

## Validation Order For Supervisor

1. Create the new by-memory child pages and update the existing [UID:0000ZO] parent.
2. Validate each new child page first:

> Executable block R001 was removed from this report and preserved verbatim in [0000ZO-maildialogs-source-split-audit-removed.md](0000ZO-maildialogs-source-split-audit-removed.md). The archived block is non-authoritative and must not be executed.

3. Validate changed support docs: `MailDialogs.md`, `BulletinReplyAlerts.md`, `BulletinSession.md`, `BulletinSession` class/global/singleton docs, [UID:0000ZM], and [UID:0000ZO].
4. Apply `by-memory/-coverage-report.md` replacement/insertion rows, then validate the shared report:

> Executable block R002 was removed from this report and preserved verbatim in [0000ZO-maildialogs-source-split-audit-removed.md](0000ZO-maildialogs-source-split-audit-removed.md). The archived block is non-authoritative and must not be executed.

5. Regenerate the memory tool report:

> Executable block R003 was removed from this report and preserved verbatim in [0000ZO-maildialogs-source-split-audit-removed.md](0000ZO-maildialogs-source-split-audit-removed.md). The archived block is non-authoritative and must not be executed.

6. Confirm `auto-generated/by-memory-tool-report.md` no longer lists `0x00479110-0x0047e040` as a large reconstructable leaf from [UID:0000ZO].

## Remaining Blockers

- Exact final C++ remains blocked for core mail classes by field names, packet-buffer helper names, row-record layout, and final source declarations. This does not block split/reclassification because the class pages already document behavior and owner routes.
- Original source file proof for `BulletinReplyAlerts.cpp` versus private mail/board alert classes remains unavailable. Checked evidence: no source-path strings, no PDB, vtable/type-info names only, constructor/use sites in both mail and board paths. Current best route remains [UID:0000HW] because the alert wrappers are shared/interleaved.
- `0x0047cd80` final helper name remains provisional. Checked evidence: only caller is `MailDialog::OnKeyInput`, strings and file APIs indicate mail export/save behavior. This is enough to split under `MailDialog`, not enough for final C++ naming.
- Several scalar deleting destructor wrappers are compiler-generated and should not emit. Checked evidence: vtable refs and adjustor thunk refs prove their class relationships, but wrapper bodies are ABI glue. The exact classification is recorded per child recommendation above.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0000ZO-maildialogs-source-split-audit.md`
- Modified: none outside this report.
- Direct by-* edits: none.
- Generated report edits: none.
- IDA DB edits: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000ZO-maildialogs-source-split-audit.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"0000ZO"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000ZO-maildialogs-source-split-audit-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0000ZO-maildialogs-source-split-audit.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000ZO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
