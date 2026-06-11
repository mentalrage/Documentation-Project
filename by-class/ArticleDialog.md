*** UID:00000J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArticleDialog

## Status

- Confidence: strong for behavior and board-dialog module placement.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: exact core child [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md), with non-emitting deleting-destructor companion [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md)

## Autogen Status

- Parent file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Reconstructable: true.
- Final C++ remains blank because packet/action field names, raw-helper reachability, and final `BoardDialogs.cpp` versus `ArticleDialogs.cpp` source split are not source-quality yet.
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
| `OnDialogAction` | `0x00476410-0x004765fd` | Handles next/previous, reply, delete, close, and related action commands. |
| `SubmitAction` | `0x00476740-0x00476813` | Sends an article action packet. |
| `HandleServerResponse` | `0x004768c0-0x004769eb` | Handles server operation replies and alert text. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks; ignore for handwritten source. |
| `ScalarDeletingDestructor` | [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md) | Non-emitting MSVC wrapper that runs [UID:00003S][DialogInSession](by-class/DialogInSession.md) base cleanup at `0x004a1450` and optionally frees storage. |

## Evidence Notes

- IDA MCP confirms constructor, action dispatch, submit, server-response, and destructor boundaries.
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is scored `85/86`, stages the board/article dialog bucket under `NexusTK/ui/dialogs/`, and lists `ArticleDialog` as the article viewer with navigation, reply/submit/delete/report actions, and transfer/delete reply handling.
- [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md) now records the exact article-viewer method/helper cluster, including raw helper chunks, the direct `BulletinSession` constructor caller, article-list helper references, delete/reply alert construction pattern, and final padding before `NewArticleDialog`.
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) keeps the aggregate board/article range as a non-emitting split inventory, while [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md) owns the exact scalar deleting destructor companion documentation.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records `ArticleDialog` primary/secondary/tertiary vtable bases `0x00613f10`, `0x00613f74`, and `0x00613fa4`, with constructor stores at `0x0047544a`, `0x00475450`, and `0x0047545a`.
- Batch 107 continuation rechecked live IDA ownership evidence: `callers 0x004753e0` returns the `BulletinSession` call at `0x00471b7a`; `xrefs_to 0x00613f10` returns the primary vtable store at `0x0047544a` inside `sub_4753E0`; `callees 0x004769f0` matches the article-list delete/reply alert construction helper shape.
- 2026-06-10 B001-025 created exact non-emitting destructor companion [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md); IDA reports code refs from adjustor thunks, vtable/data refs at `0x00613f10` and `0x00614238`, the `DialogInSession` cleanup call, and the scalar-delete conditional free.
- `0x004a1450` is [UID:00003S][DialogInSession](by-class/DialogInSession.md)'s non-deleting destructor, not an ArticleDialog-owned helper. Several board/dialog deleting destructors call it.
- The class inherits through `BulletinDialog` and should stay in the board/article dialog family rather than generic networking.

## Score Rationale

Completion is raised to `85` because the class now has a stable parent file bucket, exact core child coverage, confirmed method inventory, destructor companion ownership, board/article aggregate context, and vtable-family evidence. Confidence rises to `87` because live IDA caller/xref/callee checks agree with the direct class owner, but final C++ remains gated on raw helper reachability and packet/action field names.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00001C][BulletinDialog](by-class/BulletinDialog.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)
- [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md)

## Changes

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
