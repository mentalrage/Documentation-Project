*** UID:000098 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewPredefinedFormArticleDialog

## Status

- Confidence: strong for behavior, exact child split, and dedicated file-parent attachment; medium for final field/helper names and final C++.
- Likely source file: [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md). [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) remains the broader board/article grouping anchor.
- Address range: [UID:0000ZL][0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md), with destructor companions at [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) and [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_NewPredefinedFormArticleDialog.cpp`

## Class Purpose

`NewPredefinedFormArticleDialog` composes bulletin-board articles from server-provided predefined form rows. It parses a serialized form definition, creates a variable-height dialog with subject and row-specific edit controls, supports a free-text predefined mode, posts article data, and handles transfer-reply alert packets.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewPredefinedFormArticleDialog` | [UID:0002UJ][0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor](by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md) | Builds the form article compose dialog, parses form data when needed, creates controls, loads `DLGBBS08`, and opens the dialog. |
| raw navigation helper | [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md) | Function-shaped helper between constructor and button handler; uses previous-dialog control id `7` and article navigation helper `0x004751c0`, with reachability still unresolved. |
| `HandleButtonClick` | [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md) | OK submits article data for the current board; Cancel closes the bulletin session. |
| `HandleEvent` | [UID:0002UM][0x004782b0-0x00478363.NewPredefinedFormArticleDialogHandleEvent](by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogHandleEvent.md) | Handles transfer error/retry flow and creates the predefined transfer-reply alert wrapper. |
| `SetHoverControl` | [UID:0002UN][0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl](by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md) | Thin hover-control forwarder. |
| `OnPaint` | [UID:0002UO][0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint](by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md) | Paints the variable-height `DLGBBS08` header, row, and footer sections. |
| `DeserializePredefinedFormArticleEntries` | [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md) | File-local parser helper used only by constructor call sites; expands serialized row definitions into `0x40c`-byte records. |
| `HandleTransferReplyPredefinedAlert` | [UID:0002UQ][0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert](by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md) | Parses packet subcommand `0x06`, converts the server message to wide text, and creates an alert pane. |
| unreferenced transfer-reply helper | [UID:0002UR][0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper](by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md) | Retained alternate packet-layout helper with no IDA code/data xrefs, raw VA/RVA pointer references, or vtable slot after B001-030; kept out of autogen parent assignment because direct parent/source-emission treatment remains blocked. |
| `SubmitArticle` | [UID:0002UL][0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle](by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md) | Collects subject/body controls, serializes opcode `0x3b` subcommand `4`, and queues the packet. |
| adjustor thunks | [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) | Compiler-generated vtable thunks forwarding to the scalar deleting destructor; ignore for handwritten source. |
| scalar deleting destructor | [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) | Deletes the dialog after `DialogInSession` base teardown; generated `ArticleDialog` base-owner label is pollution. |

## Layout Notes

- Entry counts are stored around `this + 0x274`.
- Parsed `PredefinedFormArticleEntry` records begin around `this + 0x278`.
- Each parsed entry has a `0x40c` byte stride:
  - title length and wide title text
  - `usesUserImagePane` flag
  - text-line count
  - body length and wide body text
  - extra row-advance flag
- Non-free-text mode creates two controls per row after the subject controls. Free-text predefined mode uses one large body edit control.

## Evidence Notes

- IDA MCP confirms all active method starts and the two excluded destructor thunks.
- `DeserializePredefinedFormArticleEntries_478650` is only called from the constructor and should migrate with this class.
- The dedicated file parent [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) is scored `88/80`, and the aggregate/child memory pages now attach to the same file parent with exact boundaries, padding, parser call edges, vtable xrefs, and submit-call evidence. This satisfies the parent-chain attachment gate for this class while leaving final C++ blank.
- The main aggregate [UID:0000ZL][0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md) is scored `82/86` and records the raw navigate helper plus unreferenced `0x00478aa0` helper. B001-030 resolved `0x00478aa0` reachability negatively, but retained-helper source-emission policy and the current parent gate still keep the class below higher-confidence/final-source status.
- The generated active constructor source is currently summarized with placeholder comments in several branches. Use direct IDA decompilation/disassembly and the checked child pages as the evidence base for completing those dynamic-control branches.
- Current scalar deleting destructor text calls `ArticleDialog::~ArticleDialog()`; treat that as base-owner pollution. IDA decompilation on 2026-05-25 and 2026-05-26 shows [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) calls `0x004a1450`, the [UID:00003S][DialogInSession](by-class/DialogInSession.md) non-deleting destructor also used by neighboring article/bulletin deleting destructors.
- IDA disassembly/decompilation on 2026-05-25 and 2026-05-26 shows [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) are compiler adjustor thunks, not missing handwritten behavior.
- [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md) action `0x004790a0` currently disagrees with active generated source and should be verified from IDA before migration.

## Cross-References

- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZL][0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md)
- [UID:0002UJ][0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor](by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md)
- [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md)
- [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md)
- [UID:0002UM][0x004782b0-0x00478363.NewPredefinedFormArticleDialogHandleEvent](by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogHandleEvent.md)
- [UID:0002UN][0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl](by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md)
- [UID:0002UO][0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint](by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md)
- [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md)
- [UID:0002UQ][0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert](by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md)
- [UID:0002UR][0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper](by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md)
- [UID:0002UL][0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle](by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md)
- [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md)
- [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md)
- [UID:0000UE][DeserializePredefinedFormArticleEntries_478650](by-item/DeserializePredefinedFormArticleEntries_478650.md)
- [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)

## Changes

- 2026-06-10 B001-030 consistency update: revised the [UID:0002UR][0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper](by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md) method row and evidence note after IDA MCP/IDAPython found no callers, xrefs, raw VA/RVA pointer hits, immediate/code-ref/data-ref owner, or vtable slot for `0x00478aa0`. Scores and parent remain unchanged because the class still has final field/source-name and retained-helper emission caveats.
- 2026-06-07 A007 parent-chain sync: raised confidence from `78` to `80` and attached `AUTOGEN_PARENT_UID:0000LT` after verifying [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) is `88/80` and the aggregate/child memory pages document exact constructor/helper/handler/parser/submit boundaries, padding, vtable references, parser and submit call edges, and file-level ownership. Updated method rows to exact half-open child ranges and added the raw navigation helper, parser helper, and unreferenced transfer-reply helper caveats. Completion remains `84` and final C++ remains blank because dynamic-control field names, packet/helper types, retained-helper source-emission treatment, and alert source placement are not source-final.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor/command/event/paint/submit/thunk/deleting-destructor starts at `0x004777a0`, `0x00478240`, `0x004782b0`, `0x00478370`, `0x00478380`, `0x00478940`, `0x00478be0`, `0x0047e931`, `0x0047e93c`, and `0x0047ec30`. Left `AUTOGEN_PARENT_UID` blank because this class confidence is below the 80 attachment gate even though [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) is the likely source-module parent.
- Before: completion/confidence metadata were `0/0` despite detailed constructor, submit, paint, transfer-reply, layout, destructor, and parser-helper notes.
- Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
- Evidence: the page documents form-entry parsing, dynamic controls, packet serialization, destructor companion ranges, and multiple IDA-backed caveats; confidence remains medium because final source split, generated constructor placeholders, and `TransferReplyPredefinedAlert` behavior still need verification.
