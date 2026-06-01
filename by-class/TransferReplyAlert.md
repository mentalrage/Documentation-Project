*** UID:0000F5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TransferReplyAlert

## Status

- Confidence: strong for confirm behavior; medium for constructor boundary.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_TransferReplyAlert.cpp`
- Constructor memory range: [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md)
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)

## Role

`TransferReplyAlert` is an `AlertPane` subclass used by article/bulletin transfer-reply acknowledgements. Confirming the alert hides/closes it, finds the previous bulletin dialog entry, sends an article navigation packet for the selected reply context, and optionally pops the current `BulletinSession` dialog.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) | constructor, raw IDA bytes | Initializes `AlertPane`, stores the optional pop flag, and installs three alert vtables. IDA does not currently define this start as a function, but raw disassembly confirms constructor-shaped code. |
| `0x00478fe0-0x0047904e` | `OnConfirm` | IDA confirms this function; it calls the article navigation helper at `0x004751c0` and optionally pops the bulletin session. |
| [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | adjustor thunks | Secondary/tertiary vtable thunks to scalar deleting destructor `0x0047eaf0`. |
| `0x0047eaf0-0x0047eb2a` | scalar deleting destructor | Runs base alert/dialog destruction and optional delete. |

## Notes

- Current Wave3 metadata warns that destructor `0x0049d9f0` is a shared `DialogPane` destructor, not a `TransferReplyAlert`-specific body. Treat any generated `TransferReplyAlert::~DialogPane` labels in other classes as base-owner pollution.
- The closely related [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md) action body is now documented at [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md). IDA shows the same callee set and article-navigation behavior as this method; the active generated predefined-alert body remains a data issue.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md)
- [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md)

## Changes

- 2026-05-27: The constructor was previously recorded only as Wave3-projected `0x00478f90`. Updated it to raw IDA-confirmed range [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md). Evidence: IDA raw disassembly shows constructor-shaped code, `0x0049feb0` helper call, optional-pop flag store at `this+0x270`, and `TransferReplyAlert` vtable stores at `0x00478fb7`, `0x00478fbd`, and `0x00478fc7`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the raw constructor evidence, IDA-confirmed confirm action, alert-family ownership notes, destructor-thunk mapping, and documented constructor-boundary/base-owner caveats.
