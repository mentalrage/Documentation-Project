*** UID:00000J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID00000J ArticleDialog class-level source is covered by UID0000HT BoardDialogs and exact ArticleDialog method/support pages. This page emits no standalone partial class declaration until the board/article dialog source split, packet/action field names, and raw helper policy are source-quality.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ArticleDialog

## Status

- Confidence: strong for behavior and board-dialog module placement.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: exact core child [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md), with non-emitting deleting-destructor companion [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md)

## Autogen Status

- Parent file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Reconstructable: true.
- Formal output is marker-only. B004 2026-07-02 resolves UID00030J's action IDs, packet fields, and retained raw helper roles at documentation level, but class-level output still waits on synchronized ArticleDialog declarations, raw helper visibility/source-split policy, and the final `BoardDialogs.cpp` versus `ArticleDialogs.cpp` source split.
- Recovered class-file names are retained only as historical search leads on the file parent; this class page now uses by-file/by-memory/by-vtable evidence for ownership.

## Class Purpose

`ArticleDialog` displays a single bulletin-board article. It supports article navigation, reply/new-article flows, delete confirmation, report or submit actions, and server response handling for article operations.

## Class Shape

- Base family: `BulletinDialog` / `DialogInSession` article-viewer dialog.
- Session dependency: operates inside the bulletin session stack and shares base cleanup through [UID:00003S][DialogInSession](by-class/DialogInSession.md).
- Network role: handles board opcode `0x3b` article-view commands, submit/report/delete-style actions, and server reply text.
- Source placement: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), likely in an article-specific board dialog source beside [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) and [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ArticleDialog` | `0x004753e0-0x00476314` | Parses article data and builds the viewer/action UI. |
| `OnDialogAction` | `0x00476410-0x004765fd` | Handles action IDs `1` next, `2` reply/report submit, `3` close/pop, `4` delete confirmation, `5` previous, and `6` session-stack action. Next/previous send opcode `0x3b` subcommand `3` with board/context id, article id, and direction byte. |
| retained packet helpers | `0x00476320`, `0x00476620`, `0x00476b10`, `0x00476ba0` | No-direct-xref raw helper bodies retained in [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md): current-article subcommand `5` senders and relative-article subcommand `3` senders. |
| `SubmitAction` / `SendReplyOrReportAction` | `0x00476740-0x00476813` | Reads control index `7`, closes/pops through the session, then either sends opcode `0x3b` subcommand `8` when the action-mode byte is set or delegates text to the BulletinSession compose/reply helper. |
| duplicate `ConfirmDeleteAlert` helper | `0x00476820-0x004768b5` | Retained duplicate of action case `4`'s `ConfirmDeleteAlert` construction path; no direct xrefs in current IDA. |
| `HandleDeleteReplyPacket` | `0x004768c0-0x004769eb` | Checks packet subcommand `7`, decodes mode/length/text, releases modal/dimmer state, and constructs `DeleteReplyAlert`. |
| `HandleDeleteReplyPayload` | `0x004769f0-0x00476b01` | Shifted payload helper starting at mode/length/text with no subcommand check; constructs `DeleteReplyAlert`; no direct xrefs in current IDA. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks; ignore for handwritten source. |
| `ScalarDeletingDestructor` | [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md) | Non-emitting MSVC wrapper that runs [UID:00003S][DialogInSession](by-class/DialogInSession.md) base cleanup at `0x004a1450` and optionally frees storage. |

## Evidence Notes

- IDA MCP confirms constructor, action dispatch, submit, server-response, and destructor boundaries.
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is scored `85/86`, stages the board/article dialog bucket under `NexusTK/ui/dialogs/`, and lists `ArticleDialog` as the article viewer with navigation, reply/submit/delete/report actions, and transfer/delete reply handling.
- [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md) now records the exact article-viewer method/helper cluster, including raw helper chunks, the direct `BulletinSession` constructor caller, article-list helper references, delete/reply alert construction pattern, and final padding before `NewArticleDialog`.
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) keeps the aggregate board/article range as a non-emitting split inventory, while [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md) owns the exact scalar deleting destructor companion documentation.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records `ArticleDialog` primary/secondary/tertiary vtable bases `0x00613f10`, `0x00613f74`, and `0x00613fa4`, with constructor stores at `0x0047544a`, `0x00475450`, and `0x0047545a`.
- B006's 2026-06-27 source-quality implementation records that this class consumes [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) through the secondary view at `0x00613f74 + 0x10`: slot `0x00613f84` stores `0x00472040`. This is one consumer slot of the shared command-`'1'` secondary bridge, not an ArticleDialog-owned method body; class-level output is marker-only until the common secondary interface, event/action type, and primary `+0x5c` dispatch declaration are source-quality.
- Batch 107 continuation rechecked live IDA ownership evidence: `callers 0x004753e0` returns the `BulletinSession` call at `0x00471b7a`; `xrefs_to 0x00613f10` returns the primary vtable store at `0x0047544a` inside `sub_4753E0`; `callees 0x004769f0` matches the article-list delete/reply alert construction helper shape.
- B004 2026-07-02 current MCP session `supervisor_resume_20260629` rechecked [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md) and raised that child to `88/90` without changing owner/emitter routing. The pass confirms modeled/raw boundaries, action switch cases, opcode `0x3b` subcommands `3`/`5`/`7`/`8`, retained raw helper roles, zero direct xrefs to raw starts `0x00476320`, `0x00476620`, and `0x00476b10`, duplicate `ConfirmDeleteAlert` helper `0x00476820`, delete/reply `DeleteReplyAlert` route through `0x0047e2f0`, generated marker state, and rejected alternatives of moving the child to BoardDialogs or DeleteReplyAlert.
- 2026-06-10 B001-025 created exact non-emitting destructor companion [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md); IDA reports code refs from adjustor thunks, vtable/data refs at `0x00613f10` and `0x00614238`, the `DialogInSession` cleanup call, and the scalar-delete conditional free.
- `0x004a1450` is [UID:00003S][DialogInSession](by-class/DialogInSession.md)'s non-deleting destructor, not an ArticleDialog-owned helper. Several board/dialog deleting destructors call it.
- The class inherits through `BulletinDialog` and should stay in the board/article dialog family rather than generic networking.

## DeleteReplyAlert Consumer Contract

[UID:0004WF][0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton](by-memory/0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton.md) provides an exact current consumer for two previously descriptive ArticleDialog helpers:

- `GetDialogSession()` returns the owning [UID:00003U][DialogSession](by-class/DialogSession.md) used to find the preceding article-list dialog and later pop the current dialog.
- `GetCurrentArticleId()` returns the current unsigned 16-bit article/reply identifier used by `ArticleListPane::FindArticleById`.

In DeleteReplyAlert single mode, inherited `AlertPane::m_layoutReference` is constructor-proven to hold the current `ArticleDialog *`. The action obtains the session first, resolves the previous `ArticleListDialog`, reads the ID, removes the matching row if present, refreshes the prior list, and calls `PopCurrentDialog(false)`. This confirms accessor roles while preserving the existing field offsets, BoardDialogs ownership, exact core child, and class-level formal-output caveats.

## Score Rationale

Completion remains `85` and confidence `87` for the class page because the class has a stable parent file bucket, exact core child coverage, confirmed method inventory, destructor companion ownership, board/article aggregate context, vtable-family evidence, and now a source-quality child pass for UID00030J's action/packet/raw-helper semantics. The class-level score is not raised in this callback because standalone class output still needs synchronized declarations, inherited/secondary-interface policy, final helper visibility, and the final article-dialog source split.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00001C][BulletinDialog](by-class/BulletinDialog.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)
- [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md)

## Changes

- 2026-07-22 B005 UID0003Q0 callback: retained `85/87`; documented DeleteReplyAlert's exact single-reply consumption of source-facing `GetDialogSession()` and `GetCurrentArticleId()` without changing ArticleDialog ownership, offsets, or formal-output caveats.
- 2026-07-02 B004 [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md) source-quality sync:
  - Score and owner/emitter unchanged at `85/87`, [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), and `EMITTER_UIDS:0000HT`.
  - Updated Autogen Status, Method Notes, Evidence Notes, and Score Rationale with current MCP session `supervisor_resume_20260629`, resolved action IDs, opcode `0x3b` subcommands `3`/`5`/`7`/`8`, retained raw helper no-direct-xref evidence, duplicate `ConfirmDeleteAlert` helper, delete/reply packet and shifted-payload handlers, and continued marker-only class-level C++ rationale.
- 2026-06-27 B006 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync:
  - Score and owner/emitter unchanged at `85/87`, [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), and `EMITTER_UIDS:0000HT`.
  - Added the secondary `0x00613f74 + 0x10 -> 0x00613f84 -> 0x00472040` consumer-slot note, preserving class-level C++ blankness and the shared-interface/source-split caveat.
- What existed before: the page described the main methods and evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `74/86`, and class-shape notes were added for inheritance/session ownership, network role, and source placement.
- Summary and evidence: the address range, by-memory board article cluster, BoardDialogs file page, and IDA-confirmed constructor/action/server-response boundaries support strong confidence; completion remains below 100 until field layout and converted C++ bodies are fully documented.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` re-confirmed the article viewer constructor/action/submit/response method starts at `0x004753e0`, `0x00476410`, `0x00476740`, and `0x004768c0`, and `callers` shows the constructor remains live from the surrounding board-dialog flow. `AUTOGEN_PARENT_UID` remains blank despite the likely [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) owner because the class completion score is still below the 80+ attachment gate.
- 2026-06-07:
  - Before: score stayed at `74/86`, `AUTOGEN_PARENT_UID` was blank, and status still named the recovered class file as current context.
  - After: raised completion to `80`, attached parent [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), removed generated-source dependency, and added autogen-status/evidence/score-rationale sections.
  - Summary/evidence: the file parent, board/article aggregate, and board/article vtable-family page now provide durable ownership evidence while the article-viewer core still needs exact child splits and packet/action field naming.
- 2026-06-08 A008 Batch 107 continuation:
  - Before: `COMPLETION:80`, `CONFIDENCE:86`, and the page still treated the exact viewer child split as pending.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`.
  - Summary/evidence: exact child [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md) now covers the article-viewer method/helper cluster; live IDA rechecked the `BulletinSession` constructor caller, primary vtable-store xref, and delete/reply alert helper callees. This clears the direct class-parent gate for the child while preserving packet/action and raw-helper caveats.
- 2026-06-10 B001-025:
  - Changed: replaced the raw destructor range note with exact non-emitting companion [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md).
  - Summary/evidence: IDA MCP confirms the wrapper's bounds, `DialogInSession` destructor call, scalar-delete free logic, adjustor-thunk refs, and `ArticleDialog` vtable refs.
