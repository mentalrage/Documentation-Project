*** UID:0000HW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BulletinReplyAlerts

## Status

- Confidence: strong that these are shared bulletin/mail alert wrappers; medium for whether the original project used a separate source file.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/BulletinReplyAlerts.cpp`
- Alternate placement: private classes in [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), and [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md).
- Current generated sources: `class_TransferReplyAlert.cpp`, `class_TransferReplyPredefinedAlert.cpp`, `class_MailTransferReplyAlert.cpp`, `class_ConfirmDeleteAlert.cpp`, `class_DeleteReplyAlert.cpp`, `class_ConfirmDeleteMailAlert.cpp`, and `class_MailDeleteReplyAlert.cpp`.
- Evidence basis: `simroot_v2`, `.meta_wave3`, older Wave2 report notes, and IDA MCP checks on 2026-05-24 through 2026-05-26.

## Hypothesis

The reply/delete alert classes are small `AlertPane` subclasses compiled in the same board/mail neighborhood as the bulletin dialogs. They bridge server reply packets, local list mutation, and dialog-session navigation. In a reconstructed source tree they can either be a small shared alert source file or private helper classes split between the board/article and mail dialog files.

Likely structure:

```text
ui/dialogs/BulletinReplyAlerts.cpp
```

Possible compact legacy structure:

```text
ui/dialogs/BulletinDialogs.cpp
```

## Reconstruction Handling

- The assigned reconstruction path is `NexusTK/ui/dialogs/BulletinReplyAlerts.cpp`.
- Treat this file page as the source-owner bucket for confirmed small reply/delete alert wrappers until individual original file names are proven.
- Do not emit final reconstructed C++ from this file yet. The wrapper grouping is useful for autogen ownership, but several constructors remain projected or raw-disassembly-only and the original source split is still not final-source quality.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:0000F5][TransferReplyAlert](by-class/TransferReplyAlert.md) | constructor [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md); action `0x00478fe0-0x0047904e`; destructor companions `0x0047e8d9-0x0047eb2a` | `class_TransferReplyAlert.cpp` | Article/bulletin transfer reply acknowledgement; sends article navigation packet and optionally pops the session dialog. |
| [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md) | projected constructor `0x00479050`; action [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) | `class_TransferReplyPredefinedAlert.cpp` | Predefined-form article transfer reply acknowledgement. Active Wave3 body is suspect; IDA shows the same navigation-packet pattern as `TransferReplyAlert`. |
| [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md) | projected constructor `0x0047e040`; action `0x0047e090-0x0047e0fe` | `class_MailTransferReplyAlert.cpp` | Mail transfer reply acknowledgement; sends mail navigation packet and optionally pops the session dialog. |
| [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md) | projected constructor `0x0047e100`; action `0x0047e160-0x0047e2e3` | `class_ConfirmDeleteAlert.cpp` | Board/article delete confirmation that sends one or more opcode `0x3b`, subcommand `0x05` delete packets. |
| [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md) | `0x0047e2f0-0x0047e4a5`; destructor companions `0x0047e8ef-0x0047eb8e` | `class_DeleteReplyAlert.cpp` | Local reply-list deletion confirmation for bulletin/article replies. |
| [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md) | projected constructor `0x0047e4b0`; action `0x0047e510-0x0047e693` | `class_ConfirmDeleteMailAlert.cpp` | Mail delete confirmation that sends one or more opcode `0x3b`, subcommand `0x05` mail delete packets. |
| [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md) | projected constructor `0x0047e6a0`; action helpers `0x0047e6f0-0x0047e835`; destructor companions `0x0047e905-0x0047ebee` | `class_MailDeleteReplyAlert.cpp` | Local reply-list deletion confirmation for mail replies. |

## Boundary Notes

- IDA confirms `0x00478fe0`, `0x004790a0`, `0x0047e090`, `0x0047e160`, `0x0047e2f0`, `0x0047e390`, `0x0047e510`, `0x0047e730`, `0x0047eb30`, and `0x0047eb90` as function starts.
- IDA does not currently define Wave3-projected constructors at `0x00478f90`, `0x00479050`, `0x0047e040`, `0x0047e100`, `0x0047e4b0`, or `0x0047e6a0` as functions. Raw disassembly now confirms `0x00478f90-0x00478fd8` as [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md); treat the other starts as Wave3-projected boundaries until raw disassembly or function creation confirms them.
- IDA decompilation of `0x004790a0` sends the same article navigation packet shape as `TransferReplyAlert::OnConfirm`. The active `class_TransferReplyPredefinedAlert.cpp` body instead describes text-editor/predefined-reply submission behavior, so that active body is logged as a Wave3 data issue.
- 2026-05-26 recheck: `callees 0x004790a0` and `callees 0x00478fe0` match exactly (`0x004a1250`, `0x004751c0`, `0x004a10e0`), and `xrefs_to 0x004790a0` reports a vtable/data reference at `0x006141f0`. See [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md).
- The `0x0047e8d9-0x0047e91a` strip is mostly compiler-generated this-adjustor thunks for secondary/tertiary `AlertPane` vtables.
- `0x0047e950-0x0047ec6a` is a dense scalar-deleting-destructor strip shared by article, bulletin, mail, predefined article, and related dialog classes. Do not use destructor locality alone as file-ownership proof.

## Cross-References

- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md)
- [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)

## Changes

- What existed before: the page documented shared board/mail alert wrappers and constructor/action caveats but remained scored as unevaluated.
- What it was changed to: scores were set to `74/82`.
- Summary and evidence: alert behavior and shared wrapper role are well supported, while separate source-file existence and several projected constructors remain medium-confidence.
- 2026-05-27: `TransferReplyAlert` constructor ownership previously remained a projected `0x00478f90` start. Updated it to raw constructor range [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md). Evidence: IDA raw disassembly confirms constructor-shaped code and vtable stores; IDA still does not promote the start to a function object.
- 2026-06-02: Assigned projected reconstruction path `NexusTK/ui/dialogs/` so confirmed child items can attach to a stable file-owner bucket. This is a path/ownership aid only; source-file split remains medium-confidence and no final C++ should be generated from this page yet.
