*** UID:0000F6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TransferReplyPredefinedAlert

## Status

- Confidence: strong for the IDA-backed action body and alert-family ownership; medium overall because the active generated body conflicts with IDA.
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

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) now has the valid proposed path `NexusTK/ui/dialogs/` and is scored `74/82`, so it is eligible as the source-owner bucket for this small alert wrapper.
- [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md) documents the raw constructor-shaped bytes, the shared `0x0049feb0` alert constructor call, the `this + 0x270` flag store, three vtable stores, and exact `0xcc` padding on both sides.
- [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) is scored `82/90` and records exact range, vtable xref `0x006141f0`, raw instruction flow, equivalent `TransferReplyAlert` callee set, and the article-navigation packet helper path.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records `TransferReplyPredefinedAlert` primary/secondary/tertiary table bases at `0x00614194`, `0x006141fc`, and `0x0061422c`, with stores including `0x00479077`.
- The generated `class_TransferReplyPredefinedAlert.cpp` body remains a known data issue; use the IDA-backed constructor/action pages for migration decisions.

## Autogen Status

- Reconstructable: true for the alert wrapper and IDA-backed constructor/action behavior.
- Parent: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). The parent is a stable path/ownership bucket for small board/mail reply alert wrappers, even though exact original source-file split remains provisional.
- Code: intentionally blank. The action page has a source-shaped candidate, but this class page should not emit final C++ while the active generated body conflicts with IDA and final names/types remain provisional.

## Score Rationale

- Completion is raised to 80 because both constructor and virtual action are now exact child pages, with vtable-family and owner-bucket evidence.
- Confidence is raised to 86 because IDA-backed raw bytes, vtable stores, callback xrefs, and parent-file ownership now agree; the score is still below final-source quality due to generated-source conflict and unresolved final names/types.

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
