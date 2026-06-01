*** UID:0000LT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewPredefinedFormArticleDialog

## Status

- Confidence: strong for behavior and ownership; medium for final original filename.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/NewPredefinedFormArticleDialog.cpp`
- Alternate placement: private section of `ui/dialogs/ArticleDialogs.cpp`
- Current generated sources: `class_NewPredefinedFormArticleDialog.cpp` and `recovered/DeserializePredefinedFormArticleEntries_00478650.cpp`
- Evidence basis: `simroot_v2` generated source, `.meta_wave3`, recovered helper source, older Wave2 report evidence, and IDA MCP checks on 2026-05-24 and 2026-05-25.

## Hypothesis

`NewPredefinedFormArticleDialog` is a specialized bulletin-board compose dialog for template/form articles. It is much larger than `NewArticleDialog`: the constructor parses a serialized form definition, builds dynamic label/body controls, supports an alternate free-text predefined mode, paints a variable-height `DLGBBS08` dialog, and submits opcode `0x3b` article data.

Likely structure:

```text
ui/dialogs/NewPredefinedFormArticleDialog.cpp
```

Possible compact legacy structure:

```text
ui/dialogs/ArticleDialogs.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md) | `0x004777a0-0x00478f8d`, plus [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) and [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) | `class_NewPredefinedFormArticleDialog.cpp` | Template/form article compose dialog, command handling, paint, post-reply alert handling, and submit serialization. |
| [UID:0000UE][DeserializePredefinedFormArticleEntries_478650](by-item/DeserializePredefinedFormArticleEntries_478650.md) | `0x00478650-0x00478932` | `recovered/DeserializePredefinedFormArticleEntries_00478650.cpp` | File-local parser for serialized predefined article entry definitions. |
| [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md) setup | `0x004782b0`, `0x00478940`, companion action [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) | current class source plus alert wrapper | Error/transfer-reply alert handling for predefined article posts. |

## Packet And Layout Model

- Submit path sends opcode `0x3b`, subcommand `4`, board id, one-byte subject length, ANSI subject bytes, two-byte body length, and ANSI body bytes.
- Transfer/post reply handling accepts packet subcommand `0x06`, converts an ANSI message to wide text, and opens an alert pane with a reply mode byte saved at alert offset `0x270`.
- Dynamic form definitions are parsed into `PredefinedFormArticleEntry` records with a `0x40c` stride.
- The dialog stores entry counts around `this + 0x274` and parsed form entries beginning around `this + 0x278`.
- The non-free-text mode builds label/value control pairs from parsed form rows. The free-text predefined mode uses one large editable body field.
- Main resources are `DLGBBS08.EPF`, `DLGBBS08.PAL`, `DLGBBS08.EPD`, and `NPAL8.PAL`.

## Boundary Notes

- IDA confirms the core contiguous code cluster at `0x004777a0-0x00478f8d`.
- IDA confirms the parser helper `0x00478650-0x00478932`; xrefs are only the two constructor call sites at `0x00477848` and `0x00477d0c`.
- IDA confirms destructor/thunk companions at [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) and [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md); they are distant from the main constructor/submit cluster and should remain companion ranges.
- IDA decompilation of [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) action `0x004790a0` currently disagrees with the active generated alert source. Treat the generated alert body as suspect until Wave3 data is reconciled.
- Constructor xref evidence shows a caller at `0x00471c00` validates incoming form data and constructs this dialog when the predefined-form article path is active.
- Current emitted active constructor text contains placeholder comments for parts of the dynamic form-field construction and the EPD layout. Use `.meta_wave3`, recovered helper source, and IDA decompilation as the evidence source until emission is fixed.
- Current scalar deleting destructor source calls `ArticleDialog::~ArticleDialog()`. Treat that as base-owner label pollution: the 2026-05-25 IDA recheck shows the real call target is [UID:00003S][DialogInSession](by-class/DialogInSession.md)'s non-deleting destructor at `0x004a1450`.
- The two disabled destructor adjustor thunks are now IDA-confirmed compiler thunks: `0x0047e931` subtracts `0xa0` from `ecx` and jumps to `0x0047ec30`; `0x0047e93c` subtracts `0xa4` and jumps to the same deleting destructor. They are documented in [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) and listed in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Migration Notes

Use dry-run only until the source materialization caveats are fixed:

```powershell
python source-3\wave3.py create file NewPredefinedFormArticleDialog.cpp --kind source --simpath ui/dialogs/NewPredefinedFormArticleDialog.cpp --dry-run
python source-3\wave3.py attach class NewPredefinedFormArticleDialog --to-file NewPredefinedFormArticleDialog.cpp --dry-run
python source-3\wave3.py attach global DeserializePredefinedFormArticleEntries_478650 --to-file NewPredefinedFormArticleDialog.cpp --dry-run
```

Before real migration, verify the exact Wave3 command name for attaching recovered global functions, reconcile the emitted constructor placeholders, and make sure the deleting destructor uses neutral `DialogInSession` base cleanup rather than an `ArticleDialog` owner label.

## Cross-References

- [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md)
- [UID:0000UE][DeserializePredefinedFormArticleEntries_478650](by-item/DeserializePredefinedFormArticleEntries_478650.md)
- [UID:0000ZL][0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog.md)
- [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md)
- [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `80`.
- Summary/evidence: the page documents dialog role, parser/helper ownership, packet/layout model, IDA boundaries, destructor/thunk companions, migration notes, generated-output caveats, and cross-references; confidence remains capped by constructor placeholder emission and alert-body disagreement.
