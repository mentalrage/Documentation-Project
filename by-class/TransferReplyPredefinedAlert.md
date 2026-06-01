*** UID:0000F6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Exact action memory: [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md)

## Role

`TransferReplyPredefinedAlert` is the predefined-form article variant of the transfer-reply acknowledgement alert. It stores the same one-byte optional pop/confirm flag as `TransferReplyAlert` and sits immediately before the mail-dialog cluster.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| `0x00479050` | constructor, Wave3-projected | Initializes `AlertPane`, stores the flag at the tail of the alert object, and installs predefined-alert vtables. IDA does not currently define this start as a function. |
| [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) | `OnAlertAction` / confirm action | IDA confirms a function here and decompiles it as the same article navigation-packet pattern as `TransferReplyAlert::OnConfirm`. |

## Data Caveat

The active `class_TransferReplyPredefinedAlert.cpp` body describes a text-edit/predefined-reply submission path. IDA decompilation of [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) instead calls the article navigation helper at `0x004751c0` and optionally pops the bulletin session. The generated source should not be used for migration until this mismatch is resolved; see [wave3_data_issues](../wave3_data_issues.md).

2026-05-26 IDA recheck confirms the callee set is identical to `TransferReplyAlert::OnConfirm`: `0x004a1250`, `0x004751c0`, and `0x004a10e0`. `xrefs_to 0x004790a0` reports a vtable/data reference at `0x006141f0`, while `0x00479050` remains non-function/projected constructor data. A later same-day live recheck reconfirmed exact range `0x004790a0-0x0047910f` and the callsites `0x004790b6`, `0x004790f1`, and `0x00479107`.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md)
- [UID:0000F5][TransferReplyAlert](by-class/TransferReplyAlert.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the IDA-confirmed action body, vtable/data reference, same callee pattern as `TransferReplyAlert`, and explicit data caveat that the active generated body conflicts with IDA while the constructor remains projected.
