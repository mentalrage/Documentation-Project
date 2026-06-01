*** UID:000098 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewPredefinedFormArticleDialog

## Status

- Confidence: strong for behavior; medium for final source split.
- Likely source file: [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) or [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: [UID:0000ZL][0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog.md), with destructor companions at [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) and [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_NewPredefinedFormArticleDialog.cpp`

## Class Purpose

`NewPredefinedFormArticleDialog` composes bulletin-board articles from server-provided predefined form rows. It parses a serialized form definition, creates a variable-height dialog with subject and row-specific edit controls, supports a free-text predefined mode, posts article data, and handles transfer-reply alert packets.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewPredefinedFormArticleDialog` | `0x004777a0-0x004781e4` | Builds the form article compose dialog, parses form data when needed, creates controls, loads `DLGBBS08`, and opens the dialog. |
| `HandleButtonClick` | `0x00478240-0x004782a1` | OK submits article data for the current board; Cancel closes the bulletin session. |
| `HandleEvent` | `0x004782b0-0x00478362` | Handles transfer error/retry flow and creates the predefined transfer-reply alert wrapper. |
| `SetHoverControl` | `0x00478370-0x00478378` | Thin hover-control forwarder. |
| `OnPaint` | `0x00478380-0x0047864b` | Paints the variable-height `DLGBBS08` header, row, and footer sections. |
| `HandleTransferReplyPredefinedAlert` | `0x00478940-0x00478a92` | Parses packet subcommand `0x06`, converts the server message to wide text, and creates an alert pane. |
| `SubmitArticle` | `0x00478be0-0x00478f8d` | Collects subject/body controls, serializes opcode `0x3b` subcommand `4`, and queues the packet. |
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
- The generated active constructor source is currently summarized with placeholder comments in several branches. The older `.meta_wave3` history and IDA decompilation contain more complete dynamic-control evidence.
- Current scalar deleting destructor text calls `ArticleDialog::~ArticleDialog()`; treat that as base-owner pollution. IDA decompilation on 2026-05-25 and 2026-05-26 shows [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) calls `0x004a1450`, the [UID:00003S][DialogInSession](by-class/DialogInSession.md) non-deleting destructor also used by neighboring article/bulletin deleting destructors.
- IDA disassembly/decompilation on 2026-05-25 and 2026-05-26 shows [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) are compiler adjustor thunks, not missing handwritten behavior.
- [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md) action `0x004790a0` currently disagrees with active generated source and should be verified from IDA before migration.

## Cross-References

- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZL][0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog.md)
- [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md)
- [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md)
- [UID:0000UE][DeserializePredefinedFormArticleEntries_478650](by-item/DeserializePredefinedFormArticleEntries_478650.md)
- [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite detailed constructor, submit, paint, transfer-reply, layout, destructor, and parser-helper notes.
- Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
- Evidence: the page documents form-entry parsing, dynamic controls, packet serialization, destructor companion ranges, and multiple IDA-backed caveats; confidence remains medium because final source split, generated constructor placeholders, and `TransferReplyPredefinedAlert` behavior still need verification.
