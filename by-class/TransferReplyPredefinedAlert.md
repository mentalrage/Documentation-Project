*** UID:0000F6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TransferReplyPredefinedAlert

## Status

- Confidence: strong for the IDA-backed raw constructor, action body, vtable-family anchors, and alert-family ownership; medium-high overall because the active generated body conflicts with IDA and final source placement remains provisional.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md).
- Current recovered file: `source-3/simroot_v2/class_TransferReplyPredefinedAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- Exact raw constructor memory: [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md)
- Exact action memory: [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md)

## Role

`TransferReplyPredefinedAlert` is the predefined-form article variant of the transfer-reply acknowledgement alert. It stores the same one-byte optional pop/confirm flag as `TransferReplyAlert` and sits immediately before the mail-dialog cluster.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md) | raw constructor bytes | Initializes `AlertPane`, stores the flag at `this + 0x270`, installs three predefined-alert vtables, and returns `this`. IDA still does not define this start as a function object. |
| [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) | `OnAlertAction` / confirm action | IDA confirms a function here and decompiles it as the same article navigation-packet pattern as `TransferReplyAlert::OnConfirm`. |

## Data Caveat

The active `class_TransferReplyPredefinedAlert.cpp` body describes a text-edit/predefined-reply submission path. IDA decompilation of [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) instead calls the article navigation helper at `0x004751c0` and optionally pops the bulletin session. The generated source should not be used for migration until this mismatch is resolved; see [wave3_data_issues](../wave3_data_issues.md).

2026-05-26 IDA recheck confirms the callee set is identical to `TransferReplyAlert::OnConfirm`: `0x004a1250`, `0x004751c0`, and `0x004a10e0`. `xrefs_to 0x004790a0` reports a vtable/data reference at `0x006141f0`, while `0x00479050` remains non-function/projected constructor data. A later same-day live recheck reconfirmed exact range `0x004790a0-0x0047910f` and the callsites `0x004790b6`, `0x004790f1`, and `0x00479107`.

## Evidence Notes

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) has the valid proposed path `NexusTK/ui/dialogs/` and is scored `85/86`, so it passes the corrected parent side of the `85/85` attachment gate for this small alert wrapper.
- [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md) is scored `85/90` and documents exact raw constructor bytes, the shared `0x0049feb0` alert constructor call, the shared `0x00613a18` alert text/table pointer, the `this + 0x270` flag store, corrected primary vtable target `0x00614194`, secondary/tertiary vtable stores `0x006141fc` and `0x0061422c`, exact `0xcc` padding on both sides, and raw/non-function start caveats.
- [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) is scored `85/90` and records exact range, modeled function size, vtable xref `0x006141f0`, no direct callers, raw instruction flow, equivalent `TransferReplyAlert` callee set, and the article-navigation packet helper path.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records `TransferReplyPredefinedAlert` primary/secondary/tertiary table bases at `0x00614194`, `0x006141fc`, and `0x0061422c`, with stores including `0x00479077`.
- The generated `class_TransferReplyPredefinedAlert.cpp` body remains a known data issue; use the IDA-backed constructor/action pages for migration decisions.

## Autogen Status

- Reconstructable: true for the alert wrapper and IDA-backed constructor/action behavior.
- Parent: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), position `20`. The file parent is `85/86`, this class is `85/88`, and the relationship is direct enough for the corrected `85/85` gate because the exact constructor/action pages both install or dispatch through `TransferReplyPredefinedAlert` vtables while sharing the bulletin reply alert helper/table pattern.
- Code: intentionally blank. The action page has a source-shaped candidate, but this class page should not emit final C++ while the active generated body conflicts with IDA and final names/types remain provisional.

## Score Rationale

- Completion is raised to `85` because both constructor and virtual action are exact `85/90` child pages, the constructor/action pair is tied to the named `TransferReplyPredefinedAlert` vtables, the corrected `BulletinReplyAlerts` file parent now clears `85/85`, and the generated-body conflict plus source-split caveats are explicitly documented.
- Confidence remains `88` because IDA-backed raw bytes, corrected vtable stores, callback xrefs, and alert-family ownership agree; the score is still below final-source quality due to the generated-source conflict, unresolved final names/types, and provisional source-file split.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md)
- [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md)
- [UID:0000F5][TransferReplyAlert](by-class/TransferReplyAlert.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the IDA-confirmed action body, vtable/data reference, same callee pattern as `TransferReplyAlert`, and explicit data caveat that the active generated body conflicts with IDA while the constructor remains projected.
- 2026-06-02: Raised to `80/86`, marked reconstructable, attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), and added raw constructor, action, vtable-family, owner-bucket, and score-rationale evidence. C++ remains blank because active generated output conflicts with IDA.
- 2026-06-06 A007: Raised to `82/88` after live IDA rechecked [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md), corrected the primary vtable target to `0x00614194`, and updated [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) to `78/86`. Cleared `AUTOGEN_PARENT_UID` because the likely file parent no longer passes the 80/80 attachment gate.
- 2026-06-07 A004: Attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) with parent position `20`; score remains `82/88`.
  - Summary/evidence: the file parent was refreshed to `82/86`, so the parent gate now passes. The exact raw constructor, exact action callback, corrected vtable targets, and generated-body conflict remain documented; final C++ stays blank because final names/types and the possible [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) private-source split are not near-final.
- 2026-06-08 A010 Batch109: Raised completion from `82` to `85` while keeping confidence at `88`.
  - Summary/evidence: refreshed stale child-score and gate wording after both exact memory children reached `85/90` and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) reached `85/86`. This class now clears the corrected `85/85` gate as the direct parent for the exact constructor/action child pages, while final C++ remains blank because active generated output still conflicts with IDA.
