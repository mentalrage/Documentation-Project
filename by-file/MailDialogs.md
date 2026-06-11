*** UID:0000KZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MailDialogs

## Status

- Confidence: strong for mail-dialog module ownership and file-root staging, medium-high for exact old/new split.
- Proposed module folder: `ui/dialogs/`
- Projected reconstruction path: `NexusTK/ui/dialogs/MailDialogs.cpp`
- Candidate files: `ui/dialogs/MailDialogs.cpp`, possibly `ui/dialogs/NewMailDialog.cpp`, session coordination in [UID:0000HX][BulletinSession](by-file/BulletinSession.md), and shared alert helpers in [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- Recovered source views: `class_MailDialog.cpp`, `class_MailListDialog.cpp`, `class_MailListPane.cpp`, `class_NewMailDialog.cpp`, `class_MailTransferReplyAlert.cpp`, `class_ConfirmDeleteMailAlert.cpp`, and `class_MailDeleteReplyAlert.cpp`.
- Evidence basis: targeted IDA MCP boundary checks on 2026-05-23, vtable-family verification on 2026-05-26, live anchor lookup on 2026-06-05, Batch 003 live gate audit on 2026-06-07, and B001-009 owner-specific vtable split on 2026-06-10.

## Hypothesis

The mail UI was likely implemented as a small dialog family rather than isolated one-class files. The core source file should own the mail list dialog, list pane, read/reply dialog, compose dialog, and mail transfer/delete reply handling. [UID:0000HX][BulletinSession](by-file/BulletinSession.md) coordinates the shared session stack and packet-dispatch entry points. Alert wrappers may live in the same file or a shared alert-dialog file.

IDA-confirmed vtable grouping supports this family-level source layout. [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) is now the exact owner-specific vtable child for the four core mail dialog classes, while [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md) remains the parent-blank split inventory for core mail dialog tables plus mail alert companions.

Likely structure:

```text
ui/dialogs/MailDialogs.cpp
```

Possible split:

```text
ui/dialogs/MailListDialog.cpp
ui/dialogs/MailDialog.cpp
ui/dialogs/NewMailDialog.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `MailListDialog` | `0x00479110-0x0047a753` | `class_MailListDialog.cpp` | Parses mail-list packets, populates list entries, dispatches read/compose/reply/delete actions, and handles server list/delete replies. |
| `MailListPane` | `0x0047a8a0-0x0047b070` | `class_MailListPane.cpp` | Scrollable mail list row renderer and selected-mail helper. |
| `MailDialog` | `0x0047b220-0x0047ec2a` | `class_MailDialog.cpp` | Reads/parses a mail packet, builds read/reply UI, navigates messages, sends replies, and handles delete replies. |
| `NewMailDialog` | `0x0047d050-0x0047e032` | `class_NewMailDialog.cpp` | Compose-and-send dialog with recipient/subject/body fields, outgoing mail packet serialization, and a reusable [UID:0000JI][FontStyle](by-file/FontStyle.md) for the "Keep a copy" label in the EPF layout path. |
| `MailTransferReplyAlert` | projected constructor `0x0047e040`; action `0x0047e090-0x0047e0fe` | `class_MailTransferReplyAlert.cpp` | Mail transfer-reply acknowledgement alert; sends the mail navigation packet and optionally pops the session. |
| `ConfirmDeleteMailAlert` | projected constructor `0x0047e4b0`; action `0x0047e510-0x0047e694` | `class_ConfirmDeleteMailAlert.cpp` | Mail delete confirmation packet sender. |
| `MailDeleteReplyAlert` | projected constructor `0x0047e6a0`; action/destructor helpers `0x0047e6f0-0x0047ebee` | `class_MailDeleteReplyAlert.cpp` | Local mail reply-list deletion confirmation and singleton cleanup. |

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `0x00479110-0x00479d2b`, `0x00479d30-0x00479e1e`, `0x0047a060-0x0047a1b9`, `0x0047a3b0-0x0047a513`, and `0x0047a520-0x0047a754` for `MailListDialog`.
- `0x0047a8a0-0x0047a8f9` and `0x0047ae50-0x0047b071` for `MailListPane`.
- `0x0047b220-0x0047c405`, `0x0047c500-0x0047c711`, `0x0047c8d0-0x0047c94b`, and `0x0047c9f0-0x0047cb3e` for `MailDialog`.
- `0x0047d050-0x0047d7c1`, `0x0047d820-0x0047d882`, and `0x0047dcb0-0x0047e033` for `NewMailDialog`.
- `0x0047e090`, `0x0047e510`, `0x0047e6f0`, `0x0047e720`, `0x0047e730`, `0x0047e905`, `0x0047e910`, and `0x0047eb90` for mail alert companions.
- IDA `list_globals` on 2026-05-26 confirms vtable bases for `MailListDialog`, `MailListPane`, `MailDialog`, `NewMailDialog`, `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert`. See [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md).

2026-06-07 Batch 003 live IDA gate audit reconfirmed the file-root evidence:

- IDA enumerates 78 function objects from `0x00479110` through `0x0047ec2b`; the first anchors are `0x00479110-0x00479d2b`, `0x0047b220-0x0047c405`, and `0x0047d050-0x0047d7c1`, and the final two family functions are `0x0047eb90-0x0047ebef` and `0x0047ebf0-0x0047ec2b`.
- BulletinSession call-in edges still target the mail-list/view/compose anchors at `0x00479110`, `0x0047b220`, and `0x0047d050`.
- Vtable/data refs still tie the core dialog constructors to bases `0x00614238`, `0x0061439c`, and `0x0061443c`; mail delete-reply vtable ref `0x0061476c` is written from multiple mail/list/read/delete paths plus destructor `0x0047eb90`.
- Singleton refs to `0x0067adb8` and `0x0067adbc` still separate shared board/mail delete-reply state from the mail-delete-reply local singleton usage.
- Boundary bytes remain `0xcc` padding at `0x0047ec2b-0x0047ec30` before the predefined-form article destructor and `0x0047ec6b-0x0047ec70` before `ChangeMan`.

2026-06-10 B001-009 live IDA vtable split reconfirmed the owner-specific core mail vtables now carried by [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md):

- `MailListDialog` bases `0x00614238`, `0x0061429c`, and `0x006142cc` have constructor stores at `0x0047916d`, `0x00479173`, and `0x0047917d`.
- `MailListPane` bases `0x006142d8`, `0x00614360`, and `0x00614390` have constructor stores at `0x0047a8d1`, `0x0047a8d7`, and `0x0047a8e1`.
- `MailDialog` bases `0x0061439c`, `0x00614400`, and `0x00614430` have constructor stores at `0x0047b287`, `0x0047b28d`, and `0x0047b297`.
- `NewMailDialog` bases `0x0061443c`, `0x006144a0`, and `0x006144d0` have constructor stores at `0x0047d0a1`, `0x0047d0a7`, and `0x0047d0b1`.

## Corrected Parent Gate Audit

- Current parent score after this audit: `COMPLETION:86`, `CONFIDENCE:85`.
- Direct file-root decision: this page is eligible as the direct parent for the mail-dialog memory aggregate [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md) because the live IDA range, vtable grouping, BulletinSession call-in surface, singleton refs, projected `NexusTK/ui/dialogs/` path, and explicit alert-split caveats are documented on this page.
- Remaining caveat: shared alert helpers and a possible old/new mail split are still below final-source certainty. That caps confidence at `85` rather than a higher score, but it no longer blocks using `MailDialogs.cpp` as the direct parent for the mail-specific aggregate.
- Non-parent boundaries: [UID:0000HX][BulletinSession](by-file/BulletinSession.md) keeps dialog stack/session coordination, and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) remains the peer candidate for shared board/mail alert wrappers.

## Ownership Notes

- These dialogs send and receive bulletin/mail opcode family packets and should stay with dialog/session UI, not generic networking code.
- Shared stack operations such as close-all/pop/previous-dialog lookup are owned by [UID:0000HX][BulletinSession](by-file/BulletinSession.md), because mail and board flows both call them.
- Several scalar deleting destructors in this family call the shared `ArticleDialog`/`BulletinDialog` base destruction path. That reflects inheritance, not source-file ownership by article dialogs.
- Mail alert classes can remain private to `MailDialogs.cpp` or move into [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). Use `0x0047e090`, `0x0047e510`, and `0x0047e730` caller/data behavior as the strong mail evidence; projected constructors at `0x0047e040`, `0x0047e4b0`, and `0x0047e6a0` are not IDA-defined function starts.
- The keyboard helper at `0x0047cd80` is mentioned in older reports as a mail shortcut helper and should be reviewed separately before creating a by-item page.

## Cross-References

- [UID:00007K][MailDialog](by-class/MailDialog.md)
- [UID:00007L][MailListDialog](by-class/MailListDialog.md)
- [UID:00007M][MailListPane](by-class/MailListPane.md)
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md)
- [UID:0000JI][FontStyle](by-file/FontStyle.md)
- [UID:00001D][BulletinSession](by-class/BulletinSession.md)
- [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md)
- [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md)
- [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)

## Changes

- 2026-06-10 B001-009: Added the exact owner-specific vtable child [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) as a direct `MailDialogs` child after live IDA MCP reconfirmed decorated bases, COL pointers, constructor-store xrefs, and the boundary before `MailTransferReplyAlert`.
- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/dialogs/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree both place `MailDialogs.cpp` under `ui/dialogs/`.
  - After: set the validator path to `NexusTK/ui/dialogs/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `MailDialogs.cpp` under `ui/dialogs`, and live IDA MCP lookup on 2026-06-05 confirms the `MailListDialog` anchor at `0x00479110` as a real function of size `0xc1b`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: mail list/read/compose/delete/transfer dialog family, vtable grouping, IDA boundaries, session/alert ownership split, projected constructor caveats, and cross-references are documented; confidence is capped by exact old/new split and alert-helper placement.
- 2026-06-07: Confidence changed from `82` to `85` after Batch 003 corrected-parent audit.
  - Before: the page recorded the right file-root candidate but kept the parent below the supervisor assignment gate because the alert-helper and old/new-mail split caveats were not balanced against current live IDA evidence.
  - After: the page records a live 78-function IDA audit, call-in edges, vtable/data refs, singleton refs, and boundary padding while preserving the split caveats; this supports `85` confidence for file-root parenting without implying final-source completeness.
