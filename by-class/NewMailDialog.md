*** UID:000096 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewMailDialog

## Status

- Confidence: strong for behavior and mail-dialog module placement.
- Likely source file: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) or `ui/dialogs/NewMailDialog.cpp`
- Address range: [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_NewMailDialog.cpp`
- Parent attachment: attached to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) because the mail file page, mail aggregate memory page, and this class page now meet the 80/80 attachment gate.
- 2026-06-07 note: local IDA MCP was unavailable during this follow-up, so the new details below are consolidated from existing by-file/by-memory/by-vtable evidence.

## Class Purpose

`NewMailDialog` is the compose-and-send mail dialog. It lays out recipient, subject, body, and copy option controls, preloads quoted content when replying, serializes outgoing mail fields, and handles transfer-reply alerts. In the EPF mail-skin path, IDA shows it builds a local [UID:00005C][FontStyle](by-class/FontStyle.md) for the "Keep a copy" static label.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewMailDialog` | `0x0047d050-0x0047d7c0` | Builds compose dialog layout and quoted content. |
| `HandleCommand` | `0x0047d820-0x0047d881` | Handles send and cancel commands. |
| `HandleSendFailure` | `0x0047d890-0x0047d942` | Displays transfer failure alert. |
| `SetDialogMode` | `0x0047d950-0x0047d958` | Forwards dialog mode changes to base implementation. |
| `AppendQuotedMessage` | `0x0047d960-0x0047da10` | Prefixes quoted body lines and appends them to the editor. |
| `HandleMailTransferReply` | `0x0047da20-0x0047db6a` | Parses transfer reply text and displays [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md). |
| `SendMail` | `0x0047dcb0-0x0047e032` | Converts fields and sends outgoing mail packet. |

## Class State And Layout Anchors

| Evidence | Class-level meaning |
| --- | --- |
| [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md) records `NewMailDialog` primary/secondary/tertiary vtables at `0x0061443c`, `0x006144a0`, and `0x006144d0`, with constructor stores at `0x0047d0a1`, `0x0047d0a7`, and `0x0047d0b1`. | Confirms `NewMailDialog` is a real multi-view dialog class in the mail family, not just a generated helper bucket. |
| [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md) groups `0x0047cd80-0x0047e033` as `NewMailDialog` plus send/shortcut helpers. | Places the compose dialog inside the mail-dialog aggregate and records the constructor caller from the BulletinSession reply-opening path at `0x00471440`. |
| [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) lists `NewMailDialog` as the compose-and-send dialog with recipient, subject, body, outgoing serialization, and `FontStyle` label setup. | Supports `MailDialogs.cpp` as the parent source file while leaving a later split to `NewMailDialog.cpp` possible if stronger source-layout evidence appears. |
| The constructor writes the mail-family vtables and uses [UID:00005C][FontStyle](by-class/FontStyle.md) for the EPF "Keep a copy" label path. | Identifies owned UI controls and transient style construction without naming unresolved field offsets as final source fields. |

## Reconstruction State

- Reconstructable: true, because this is NexusTK-owned compose-dialog source behavior that must be rebuilt.
- Parent: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), not [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). The transfer alert dependency is a child/helper interaction, while the compose constructor, send flow, vtables, and BulletinSession opening path are part of the mail-dialog family.
- Final C++ remains blank. The class role, method ranges, parent file, and vtable identity are strong enough for parent attachment, but exact member names for recipient/subject/body/copy controls and source-quality helper declarations are still below the 95/95 final-code gate.

## Evidence Notes

- IDA MCP confirms constructor, command, and send boundaries.
- IDA MCP confirms raw constructor calls to `FontStyle::FontStyle` at `0x0047d0d2` and `FontStyle::Configure(128, 128, 3, 0)` at `0x0047d3fa`, even though active generated source abstracts this as `BuildDialogTextStyle`.
- Outgoing mail conversion helpers are shared with other text-submit flows and should not be treated as mail-owned.
- Existing mail aggregate docs record the exact compose cluster as `0x0047cd80-0x0047e033`, with `NewMailDialog` constructor at `0x0047d050-0x0047d7c1`, command handler at `0x0047d820-0x0047d882`, and send routine at `0x0047dcb0-0x0047e033`.
- The mail vtable-family page records the `NewMailDialog` vtable bases and constructor store sites, while the broader mail aggregate page records the matching vtable bases and the BulletinSession caller.

## Score Rationale

Completion is raised to `80` because the page now records parent attachment, class-layout/vtable anchors, source-owner decision, reconstruction state, and explicit final-C++ blockers in addition to the earlier method inventory. Confidence remains `84`: existing IDA-backed documentation supports the behavior and owner, but this session could not query IDA MCP directly and final field names/source declarations remain unresolved.

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)
- [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)

## Changes

- 2026-06-07 (A010): Raised completion from `74` to `80` and attached the class to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
  - Evidence added: mail-family vtable bases/store refs from [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md), compose-cluster/caller support from [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md), parent-file rationale, reconstruction-state notes, and final-C++ blockers.
  - Limitation: IDA MCP was unavailable in this session, so the update consolidates existing by-* evidence rather than adding new live disassembly.
- Before: completion/confidence metadata were `0/0` even though the page already covered dialog role, send flow, command handling, transfer replies, and module placement.
- Changed to: `COMPLETION:74` and `CONFIDENCE:84`.
- Evidence: constructor, command, failure, quoted-message, transfer-reply, and send methods are documented with IDA-backed notes; remaining gaps are exact field layout and complete body-level converted C++.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `74/84`, below the 80/80 parent-attachment gate, even though [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts at `0x0047d050`, `0x0047d820`, `0x0047d890`, `0x0047d950`, `0x0047d960`, `0x0047da20`, and `0x0047dcb0`; current `callers` confirms the constructor is referenced from `0x00471440`.
