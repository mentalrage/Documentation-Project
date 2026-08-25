*** UID:0000KZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MailDialogs

## Status

- Confidence: very strong for the complete 53-body core inventory, corrected ranges, one-file owner route, formal CPP/H source placement, compiler/no-code dispositions, and neighboring alert/session boundaries. Exact original lexical spellings remain the sub-95 cap.
- Proposed module folder: `ui/dialogs/`
- Projected reconstruction path: `NexusTK/ui/dialogs/MailDialogs.cpp`
- Current source files: `NexusTK/ui/dialogs/MailDialogs.cpp` plus required sibling `NexusTK/ui/dialogs/MailDialogs.h`. Separate per-class files remain historical unproven alternatives; session coordination stays in [UID:0000HX][BulletinSession](by-file/BulletinSession.md), shared stack ownership in [UID:0000IU][DialogSession](by-file/DialogSession.md), and alert implementations in [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- Recovered source views: `class_MailDialog.cpp`, `class_MailListDialog.cpp`, `class_MailListPane.cpp`, `class_NewMailDialog.cpp`, `class_MailTransferReplyAlert.cpp`, `class_ConfirmDeleteMailAlert.cpp`, and `class_MailDeleteReplyAlert.cpp`.
- Evidence basis: targeted IDA MCP boundary checks on 2026-05-23, vtable-family verification on 2026-05-26, live anchor lookup on 2026-06-05, Batch 003 live gate audit on 2026-06-07, and B001-009 owner-specific vtable split on 2026-06-10.

## Hypothesis

The mail UI was likely implemented as a small dialog family rather than isolated one-class files. The core source file should own the mail list dialog, list pane, read/reply dialog, compose dialog, and mail transfer/delete reply handling. [UID:0000HX][BulletinSession](by-file/BulletinSession.md) coordinates packet-dispatch entry points, while [UID:0000IU][DialogSession](by-file/DialogSession.md) owns the shared session stack/list helpers. Alert wrappers may live in the same file or a shared alert-dialog file.

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
| `MailListDialog` | [UID:0003PU][0x00479110-0x0047a894.MailListDialogCore](by-memory/0x00479110-0x0047a894.MailListDialogCore.md) | `class_MailListDialog.cpp` | Parses mail-list packets, populates list entries, dispatches read/compose/reply/delete actions, owns selected-mail read/delete request flow, retains no-direct-route helper pockets, handles server list/delete replies, and exposes constructor direction `MailListDialog(BulletinSession *, const Rect &, const unsigned char *mailListPayload)` to BulletinSession callers. |
| `MailListPane` | [UID:0003PV][0x0047a8a0-0x0047b21f.MailListPaneCore](by-memory/0x0047a8a0-0x0047b21f.MailListPaneCore.md) | `class_MailListPane.cpp` | Scrollable mail list row renderer, selected-mail request/delete/remove helpers, retained no-direct-route helper pockets, row layout, and lazy page request behavior. |
| `MailDialog` | [UID:0003PW][0x0047b220-0x0047cd79.MailDialogCore](by-memory/0x0047b220-0x0047cd79.MailDialogCore.md) plus [UID:0003PX][0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper](by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md) | `class_MailDialog.cpp` | Reads/parses a mail packet, builds read/reply UI, navigates messages, sends replies, handles delete replies, and supports Ctrl+S mail save/export. |
| `NewMailDialog` | [UID:0003PY][0x0047d050-0x0047e033.NewMailDialogCore](by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md) | `class_NewMailDialog.cpp` | Compose-and-send dialog with recipient/subject/body fields, outgoing mail packet serialization, and a reusable [UID:0000JI][FontStyle](by-file/FontStyle.md) for the "Keep a copy" label in the EPF layout path. |

## Alert Dependencies And Alternate Placement

The 2026-06-16 B001 source-split audit kept mail alert wrappers under [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) for current ownership because the alert strip is interleaved with board/article wrappers and compiler glue. They remain dependencies and possible private-placement candidates for `MailDialogs.cpp`, not core `MailDialogs` contents until stronger source-file evidence appears.

| Dependency | Exact children | Current route |
| --- | --- | --- |
| [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md) | [UID:0003O8][0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor](by-memory/0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor.md), [UID:0003PZ][0x0047e090-0x0047e0ff.MailTransferReplyAlertOnConfirm](by-memory/0x0047e090-0x0047e0ff.MailTransferReplyAlertOnConfirm.md) | [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) |
| [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md) | [UID:0003MZ][0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor](by-memory/0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor.md), [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) | [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) |
| [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md) | source-emitting retained constructor [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md), destructor/getter [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md), primary-button action [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md), and scalar destructor [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md) | [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) |

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `0x00479110-0x00479d2b`, `0x00479d30-0x00479e1e`, `0x0047a060-0x0047a1b9`, `0x0047a3b0-0x0047a513`, and `0x0047a520-0x0047a754` for `MailListDialog`.
- `0x0047a8a0-0x0047a8f9` and `0x0047ae50-0x0047b071` for `MailListPane`.
- `0x0047b220-0x0047c405`, `0x0047c500-0x0047c711`, `0x0047c8d0-0x0047c94b`, and `0x0047c9f0-0x0047cb3e` for `MailDialog`.
- `0x0047d050-0x0047d7c1`, `0x0047d820-0x0047d882`, and `0x0047dcb0-0x0047e033` for `NewMailDialog`.
- `0x0047e090`, `0x0047e510`, `0x0047e6f0`, `0x0047e720`, `0x0047e730`, `0x0047e905`, `0x0047e910`, and `0x0047eb90` for mail alert companions.
- IDA `list_globals` on 2026-05-26 confirms vtable bases for `MailListDialog`, `MailListPane`, `MailDialog`, `NewMailDialog`, `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert`. See [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md).

2026-06-07 Batch 003 live IDA gate audit reconfirmed the file-root evidence:

- Historical IDA enumeration recorded 78 function objects. Current live enumeration returns 79 modeled functions from `0x00479110` through `0x0047ec2b`, including modeled `0x0047db70`; the core handwritten/source-shaped file interval is `0x00479110-0x0047e033`.
- BulletinSession call-in edges still target the mail-list/view/compose anchors at `0x00479110`, `0x0047b220`, and `0x0047d050`.
- Vtable/data refs still tie the core dialog constructors to bases `0x00614238`, `0x0061439c`, and `0x0061443c`; mail delete-reply vtable ref `0x0061476c` is written from multiple mail/list/read/delete paths plus destructor `0x0047eb90`.
- Singleton refs to `0x0067adb8` and `0x0067adbc` still separate shared board/mail delete-reply state from the mail-delete-reply local singleton usage.
- Boundary bytes remain `0xcc` padding at `0x0047ec2b-0x0047ec30` before the predefined-form article destructor and `0x0047ec6b-0x0047ec70` before `ChangeMan`.

2026-06-10 B001-009 live IDA vtable split reconfirmed the owner-specific core mail vtables now carried by [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md):

- `MailListDialog` bases `0x00614238`, `0x0061429c`, and `0x006142cc` have constructor stores at `0x0047916d`, `0x00479173`, and `0x0047917d`.
- `MailListPane` bases `0x006142d8`, `0x00614360`, and `0x00614390` have constructor stores at `0x0047a8d1`, `0x0047a8d7`, and `0x0047a8e1`.
- B002's 2026-06-19 PE/Capstone reanalysis of [UID:0003PV][0x0047a8a0-0x0047b21f.MailListPaneCore](by-memory/0x0047a8a0-0x0047b21f.MailListPaneCore.md) expands the old nine-function model: the pane child also owns source-shaped no-direct-route helper pockets at `0x0047a9e0`, `0x0047aa90`, `0x0047ab70`, `0x0047aba0`, and `0x0047ac00`. These helpers operate on `MailListEntryRow` list state and should remain in the MailListPane source model even though the local direct-call and dword-pointer scans found no route to their starts.
- `0x0047b080-0x0047b110` is a `MailDialogs.cpp` file-local helper best named `SendMailListPageRequest`, not a class-exclusive `MailListPane` method. It builds the 7-byte opcode `0x3b` subopcode `0x02` page request. Its proven direct callsite/containing-entry pairs are `0x0047a056`<-`0x0047a020`, `0x0047ac21`<-`0x0047ac00`, `0x0047ac7a`<-`0x0047ac30`, `0x0047d812`<-`0x0047d7d0`, and `0x0047e0e1`<-`0x0047e090`. The older `0x0047a50c` is an interior operand byte of the unrelated `call __security_check_cookie` instruction headed at `0x0047a508`; `0x0047a539` is an interior byte of the unrelated `mov edi, ecx` instruction headed at `0x0047a538`; `0x0047c3cc` is an interior operand byte of the unrelated `call DialogPane__SetFocusedControl` instruction headed at `0x0047c3c8`; and `0x0047e0f2` is an interior byte of the unrelated `mov ecx, [edi+270h]` instruction headed at `0x0047e0ef`. None of those four superseded addresses is a helper callsite or containing-entry identity.
- B007's 2026-06-20 MailListDialog source-quality pass expands [UID:0003PU][0x00479110-0x0047a894.MailListDialogCore](by-memory/0x00479110-0x0047a894.MailListDialogCore.md) beyond the older six/eight-function summaries: no-direct-route helper pockets at `0x00479e20`, `0x00479f40`, `0x00479f90`, `0x0047a020`, `0x0047a1e0`, `0x0047a200`, `0x0047a280`, and `0x0047a760` are retained as source-shaped selected-delete, remove, initial-page, compose/reply, delete-confirm, and delete-reply-alert helpers. The same pass renames the generic `SendMailRequest` role at `0x00479d30` to `SendSelectedMailReadRequest`, keeps child/control id `7` as the MailListPane lookup route, and records `MailListEntryRow`, `m_mailListId`/`m_mailType`, and `g_useEpfAssets` layout-offset dependencies.
- B012's 2026-07-03 UID0004G7 support sync with MCP session `supervisor_20260703_reopen` refines the BulletinSession constructor-call surface: [UID:0004G7][0x00471dd0-0x00471e96.BulletinSessionOpenMailListDialog](by-memory/0x00471dd0-0x00471e96.BulletinSessionOpenMailListDialog.md) calls constructor `0x00479110` at `0x00471e51` after a `0x278` allocation, passing `BulletinSession *`, `Rect` bounds, and a mail-list payload pointer. The constructed dialog is pushed through `DialogSession::PushDialog`, and the 16-bit returned dialog/list id at `MailListDialog +0x274` is consumed by `BulletinSession +0x102`. This keeps MailDialogs as concrete dialog owner and BulletinSession as coordinator/caller.
- `MailDialog` bases `0x0061439c`, `0x00614400`, and `0x00614430` have constructor stores at `0x0047b287`, `0x0047b28d`, and `0x0047b297`.
- `NewMailDialog` bases `0x0061443c`, `0x006144a0`, and `0x006144d0` have constructor stores at `0x0047d0a1`, `0x0047d0a7`, and `0x0047d0b1`.

## Corrected Parent Gate Audit

- Current parent score after whole-file closure: `COMPLETION:94`, `CONFIDENCE:94`.
- Direct file-root decision: this page is eligible as the direct parent for the mail-dialog memory aggregate [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md) because the live IDA range, vtable grouping, BulletinSession call-in surface, singleton refs, projected `NexusTK/ui/dialogs/` path, and explicit alert-split caveats are documented on this page.
- Remaining caveat: shared alert helpers and a possible historical old/new mail split remain below final-source certainty. The former `86` confidence cap is historical and superseded by the exhaustive 53-body/range/formal-channel closure; the current evidence supports `CONFIDENCE:94` while retaining this caveat as sub-95 lexical and original-source-placement uncertainty. It does not block using `MailDialogs.cpp` as the direct parent for the mail-specific aggregate.
- Non-parent boundaries: [UID:0000HX][BulletinSession](by-file/BulletinSession.md) keeps packet/session dispatch coordination, [UID:0000IU][DialogSession](by-file/DialogSession.md) keeps shared stack/list ownership, and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) remains the peer candidate for shared board/mail alert wrappers.

## Ownership Notes

- These dialogs send and receive bulletin/mail opcode family packets and should stay with dialog/session UI, not generic networking code.
- Shared stack operations such as close-all/pop/previous-dialog lookup are owned by [UID:0000IU][DialogSession](by-file/DialogSession.md); mail and board flows call them through shared session infrastructure. The historical [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md) page is now a non-emitting split/index rather than a mail, board, or BulletinSession emitter.
- Several scalar deleting destructors in this family call the shared `ArticleDialog`/`BulletinDialog` base destruction path. That reflects inheritance, not source-file ownership by article dialogs.
- Mail alert implementations remain under [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). Core MailDialogs constructs/consumes them through exact raw constructor and action children, but the source boundary begins the alert strip at `0x0047e040`; private placement inside MailDialogs is retained only as a rejected historical possibility.
- [UID:0003PX][0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper](by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md) records the exact `SaveCurrentMailToFile` body: sole caller `MailDialog::OnKeyInput` at `0x0047c765`, exact mail paths/headings/success text, and complete formal CPP. Historical Ctrl+S send/reply and generic-file interpretations are rejected.
- MailDialog inline-constructs/uses [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md) and [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md), but B006 did not find enough evidence to move those class implementations out of [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). Keep `MailDialogs` as the consumer/source context and preserve the shared-alert owner bucket until stronger physical source evidence appears.
- MailListDialog also constructs or reuses [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md) and [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md): delete action and helper `0x0047a280` create the mail delete confirmation in list mode, while incoming packet subcommand `7` and helper `0x0047a760` create/reuse the mail delete-reply alert. This reinforces `MailDialogs` as the consumer/context for mail alerts without moving the alert implementation owner out of [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- B009 2026-06-19 MailDeleteReplyAlert source-quality reanalysis refined the exact consumer relationship. Mail-list paths at `0x0047a4bf/0x0047a4c5/0x0047a4cf` and `0x0047a84d/0x0047a853/0x0047a85d` inline the alert construction with `m_deleteAllReplies = true`; MailDialog paths at `0x0047caf7/0x0047cafd/0x0047cb07` and `0x0047cc2d/0x0047cc33/0x0047cc3d` inline it with `m_deleteAllReplies = false`. All four paths install the `MailDeleteReplyAlert` vtables and publish `g_pMailDeleteReplyAlert`. Its no-direct-entry observation remains valid binary evidence but is no longer a no-code disposition.
- B005 2026-07-22 live sibling/caller reconciliation identifies the four optimized result evaluations that precede those mirrors: `0x0047a42b` and `0x0047a7b9` precede the two mail-list mode-`1` constructions, while `0x0047ca63` and `0x0047cb99` precede the two MailDialog mode-`0` constructions. Together with the modeled `DeleteReplyAlert` sibling, these discarded evaluations resolve the retained constructor's first source parameter as `bool deleteSucceeded`; the fourth parameter is `bool deleteAllReplies`. This strengthens the consumer contract without moving implementation ownership from [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- Current source-split decision after B007: keep `MailListDialog`, `MailListPane`, `MailDialog`, `NewMailDialog`, and the file-local `SendMailListPageRequest` helper in `NexusTK/ui/dialogs/MailDialogs.cpp`; keep alert wrappers routed through [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md); treat separate `MailListDialog.cpp` or `NewMailDialog.cpp` as unproven source-tree alternatives rather than current owners.
- B006 2026-06-27 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync: the mail dialog secondary command/action views consume the shared command-`'1'` bridge through MailListDialog secondary `0x0061429c + 0x10 -> 0x006142ac`, MailDialog secondary `0x00614400 + 0x10 -> 0x00614410`, and NewMailDialog secondary `0x006144a0 + 0x10 -> 0x006144b0`; all three slots store `0x00472040`. These slots are mail-side consumers only. They do not move [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) ownership to MailDialogs, and they preserve MailDialogs ownership for mail-specific list/read/compose methods rather than the shared BoardDialogs-routed bridge.

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
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)

## 2026-08-11 Whole-File Closure

The core file owns exactly 53 handwritten/source-shaped bodies: 14 `MailListDialog`, 16 `MailListPane`/request, 14 `MailDialog` including save/export, and 9 `NewMailDialog`. Current live IDA enumerates 79 modeled functions in the broader mixed family; the core itself contains 34 modeled plus 19 retained raw bodies.

### Complete Function And Child Inventory


Every source-bearing row below has a role, owner, body identity, formal CPP/H destination, and implementation claim. Hashes are SHA256 of current executable bytes.

| Range | UID / source role | Size / SHA256 | Xref status | CPP/H disposition |
| --- | --- | --- | --- | --- |
| `0x479110-0x479d2a` | 0003PU `MailListDialog::MailListDialog` | 3099 / `2882F5693ECF56C10F7C5544E001DD15049083EC0FB4D751FA9145918E4A550E` | callers `0x47173f`, `0x471e51` | UID3PU CPP; UID07L H |
| `0x479d30-0x479e1d` | 0003PU `SendSelectedMailReadRequest` | 238 / `9329E6301732B90AF836D78E21043CFA9CA197B0B578EABBEDF71779E11FFE83` | caller `0x47a0a3` | UID3PU CPP/H declaration |
| `0x479e20-0x479f3b` | 0003PU `SendSelectedMailDeleteRequests` | 284 / `C838A88A38608831AC4AE9A895406BF6D8DC4B9E2DA5AC747B60B817C7370BDB` | zero direct xrefs | retained CPP/H |
| `0x479f40-0x479f7f` | 0003PU `RemoveMailEntryByIdAndRefresh` | 64 / `737604DFE3FF9B7ADC516B11F0E4AF111086D1AC099F5D93F3F550C8560A54AC` | zero direct xrefs | retained CPP/H |
| `0x479f90-0x47a013` | 0003PU `RemoveSelectedMailEntriesAndRefresh` | 132 / `83ED2F0F26A506B208A54D5CD0B957F8A6A510B417406762D7033C862A33CEA7` | zero direct xrefs | retained CPP/H |
| `0x47a020-0x47a05b` | 0003PU `RequestInitialMailPage` | 60 / `E5E7E0404F76EBBB54E324387C69590AE9A7A8F938BE9FC62955A313969A5D97` | zero direct xrefs | retained CPP/H |
| `0x47a060-0x47a1b8` | 0003PU `OnCommand` | 345 / `5DF0A682AE1449F8B608FE7B0D4A66872239E965DA84CE3929F776389394C07A` | vtable/jump table | CPP/H override |
| `0x47a1e0-0x47a1f1` | 0003PU `OpenBlankComposeDialog` | 18 / `1132F6B8A3195FEE4B455192D1E1C4A8AFCCAA113E4F150F75EE757C681AF2AA` | zero direct xrefs | retained CPP/H |
| `0x47a200-0x47a277` | 0003PU `OpenReplyToSelectedMail` | 120 / `E4E91789E39E0EC9CA1F60E9CCAEB1A89011B8B1C7B38244AA387783A24AD201` | zero direct xrefs | retained CPP/H |
| `0x47a280-0x47a315` | 0003PU `CreateSelectedMailDeleteConfirmAlert` | 150 / `FE818495E3399A51FFD557E6B89787820E11DDFB2D8DCD9B503412DA8530CAB5` | zero direct xrefs | CPP/H |
| `0x47a320-0x47a3ab` | 0003PU `UpdateButtonStates` | 140 / `B3868EDB3F6ED48C7510DC315A54AB241A7C1ADCFE67C51CE4769C9BFEB321F8` | vtable ref `0x614284` | CPP/H |
| `0x47a3b0-0x47a512` | 0003PU `OnServerPacket` | 355 / `7BA24D9BE9EF915AF56B97500AB7E7C4254B6D92459ABCDF41863DE5814F282D` | vtable ref `0x614294` | CPP/H override |
| `0x47a520-0x47a753` | 0003PU `ApplyMailListUpdate` | 564 / `EE68C3427E80B0741FB479A6155425A85734DBC07F8D24D7718CA239B24555E3` | caller `0x47a4f0` | CPP/H |
| `0x47a760-0x47a893` | 0003PU `ShowMailDeleteReplyAlert` | 308 / `33BA9845E99A448CE5C96B7F435C26D51B1D6461F053AF443770049D111F39C5` | zero direct xrefs | CPP/H |
| `0x47a8a0-0x47a8f8` | 0003PV `MailListPane::MailListPane` | 89 / `1A7F298B541CDD4C2788D75BE9821763378E3A3887523BAF4261042C22242CCE` | callers `0x479273`, `0x479815` | UID3PV CPP; UID07M H |
| `0x47a900-0x47a9dd` | 0003PV `AddOrUpdateMailEntry` | 222 / `B91DB4ACAF677629F3A681E8B61D2D908C1E5E032BAF819157A8F27D9B46B090` | three callers | CPP/H |
| `0x47a9e0-0x47aa8c` | 0003PV `RequestSelectedMailAndMarkRead` | 173 / `0D49F928E07EF522BD3B2A5F184A882F7D437BB1621E48E5A514240EDD509A85` | zero direct xrefs | retained CPP/H |
| `0x47aa90-0x47ab65` | 0003PV `SendDeleteRequestsForSelectedMail` | 214 / `5EDBF28F6CA7A1F6FB9849EFA79ECD4C98BDCC888D74A19C5476EE7E778CD2FC` | zero direct xrefs | retained CPP/H |
| `0x47ab70-0x47ab8f` | 0003PV `RemoveMailEntryById` | 32 / `3E62C6493AD92FDAC57349B8578561D991425BB3C01B14E2094AEF17279772F4` | zero direct xrefs | retained CPP/H |
| `0x47aba0-0x47abf9` | 0003PV `RemoveSelectedMailEntries` | 90 / `5BAA1B14D68A428641A9C312C00C555E226379D9C10598F6B9C31A7827DA3167` | zero direct xrefs | retained CPP/H |
| `0x47ac00-0x47ac26` | 0003PV `RequestInitialMailPage` | 39 / `7D32C6671DCD092F6CB583725FEE9997A4F880A1A0244A004EDABA9111F06036` | zero direct xrefs | retained CPP/H |
| `0x47ac30-0x47ac87` | 0003PV `RequestOlderMailIfNeeded` | 88 / `1F41D0667CDC0018824C687C421DC19E4368D38F3876A8F6F888E64A10754743` | callers `0x47adc8`, `0x47ae1c` | CPP/H |
| `0x47acd0-0x47ad12` | 0003PV `FindMailIdIndex` | 67 / `9DC0E7CEDFDDD85F141CD27CC366B51F35E98292B1FFB52C7CB7A147BF89823F` | five family callers | CPP/H |
| `0x47ad80-0x47add4` | 0003PV `OnScrollChanged` | 85 / `59B5B6516F7137912C8563D2B426C4D8D06C40FB42E504C46E111615DA9A1CBB` | vtable `0x614364` | CPP/H override |
| `0x47ade0-0x47ae28` | 0003PV `OnItemSelected` | 73 / `41E9D107016B02D302057E0B297D4B87084D39785713884C20B89EAD090E25AC` | vtable `0x614368` | CPP/H override |
| `0x47ae30-0x47ae42` | 0003PV `RequestSelectedMail` | 19 / `CB2D94E315B4FC30229054E0DF73DF4CC35069F6F781D55672719F6E40CD674C` | vtable `0x614354` | CPP/H override |
| `0x47ae50-0x47b070` | 0003PV `DrawEntry` | 545 / `DEBAED5BE567AD572EAA0834C56CA22C825E4CA5784EC998A427CC840DCC189D` | vtable `0x614358` | CPP/H override |
| `0x47b080-0x47b10f` | 0003PV file-local `SendMailListPageRequest` | 144 / `0303C325C998113D0E754F0E414EA219A705319F26126F036B02701D9794D8CE` | five family callers | static CPP declaration |
| `0x47b110-0x47b19a` | 0003PV static `SendMailReadRequest` | 139 / `6AFD8376A9C9D794E5D0421729220F5271ECEAADEB0825F8C5AFC0BCC93497F1` | zero direct xrefs | retained static CPP |
| `0x47b1a0-0x47b21c` | 0003PV static `SendMailDeleteRequest` | 125 / `D5ED1D52C140003FF8CB072143CA254C65BD00C9F26EC665F32C7867492B7EDD` | zero direct xrefs | retained static CPP |
| `0x47b220-0x47c404` | 0003PW `MailDialog::MailDialog` | 4581 / `4D5A391AD70DDF5043EFF4EF36FE5126DD342C3ECBC1F5B4DDDA61E5CA1BA142` | callers `0x4717f6`, `0x471f71` | UID3PW CPP; UID07K H |
| `0x47c410-0x47c4ab` | 0003PW `SendDeleteCurrentMailRequest` | 156 / `E8AC4E9DA3548641C92E9AFFDB6D6B64AD627CA318459D1DB76602E2F5AA9183` | zero direct xrefs | retained CPP/H |
| `0x47c4b0-0x47c4ff` | 0003PW `RefreshSelectedMailInList` | 80 / `72102D32A0CB6ECBD16AF7FD145B53CA259C8CCC01B88444F0213A4BC82A422B` | zero direct xrefs | CPP/H |
| `0x47c500-0x47c710` | 0003PW `OnCommand` | 529 / `70B826A0AAC18D278240C55F4F55B8B943C65B9A9CD6AC816F81376E42D4EBB5` | vtable `0x6143e4` | CPP/H override |
| `0x47c730-0x47c77f` | 0003PW `OnKeyInput` | 80 / `026D535F8303798C39412FCA62A25B1E703CC196D8BD6CE02618245B1102AA17` | vtable `0x614408` | CPP/H override |
| `0x47c780-0x47c890` | 0003PW `NavigateToAdjacentMail` | 273 / `44210F1CE066725C6724C8099E3D7D25EFFC6CCFF8CFBDFE244749617BD84907` | zero direct xrefs | retained CPP/H |
| `0x47c8a0-0x47c8c2` | 0003PW `OpenBlankComposeDialog` | 35 / `8826A392E87778687FA61CC2DEEB65E29511A3AF687FB1CBA3F03F7BE4F5043F` | zero direct xrefs | retained CPP/H |
| `0x47c8d0-0x47c94a` | 0003PW `SendReply` | 123 / `BE19D10F44317BC1CA4567B961429301157FB97BC5256EFBD9430B7B63815E15` | caller `0x47c67e` | CPP/H |
| `0x47c950-0x47c9e5` | 0003PW `CreateConfirmDeleteAlert` | 150 / `C2C0B7E8729EE2BA8809233DEA869AC843AD247F4BB0987FDFB6ABD88E849632` | zero direct xrefs | CPP/H |
| `0x47c9f0-0x47cb3d` | 0003PW `OnMailDeleteReply` | 334 / `79E3F05FAB1368ECC56BB84A78FC9DC3AECE56973462A7B043D64CFA24B496F3` | vtable `0x6143f8` | CPP/H override |
| `0x47cb40-0x47cc73` | 0003PW `ShowMailDeleteReplyAlert` | 308 / `E957ED01209F5850908F2BE526EC93321BCC3F177E6AB1788E7C71FC1865AE18` | zero direct xrefs | CPP/H |
| `0x47cc80-0x47cd0d` | 0003PW static `SendMailNavigationRequest` | 142 / `CED9872F56F5C3AB0421626835A53C2ABCC6DAA4FF85243C441F5F8A4CE9BAB5` | zero direct xrefs | retained static CPP |
| `0x47cd10-0x47cd77` | 0003PW static `SendMailDeleteRequest` | 104 / `F5E68FB522788595AFCD958BB95C84B7C5F517CE98EBA5B77A83719FD87A9E92` | zero direct xrefs | retained static CPP |
| `0x47cd80-0x47d049` | 0003PX `MailDialog::SaveCurrentMailToFile` | 714 / `72A30E400CF824E002C2DE6604F70F29F5C198996B27ACD7684220108AE92FA2` | sole caller `0x47c765` | UID3PX CPP; UID07K H |
| `0x47d050-0x47d7c0` | 0003PY `NewMailDialog::NewMailDialog` | 1905 / `587923F1BB1E47B58F8590BCF20B866E06DA6AF7EAB8693672AC6E1046213F0C` | caller `0x471440` | UID3PY CPP; UID096 H |
| `0x47d7d0-0x47d817` | 0003PY `RequestInitialMailPage` | 72 / `B506177CE930A1F3F06D570C3809F824BE4F42ADCB28BBEAB97EF99DF390F16F` | zero direct xrefs | retained CPP/H |
| `0x47d820-0x47d881` | 0003PY `OnCommand` | 98 / `C41DCC71D86BFC51AA68368526F5EAF152D634F95C44F03A80A16C35006E0D7A` | vtable `0x614484` | CPP/H override |
| `0x47d890-0x47d942` | 0003PY `ShowSendFailureAlert` | 179 / `0BE8212B86E1D197E21B69D7F84714015EE027964FE55DEB1F3BB8C1D0DAD9A0` | vtable `0x6144d4` | CPP/H override |
| `0x47d950-0x47d958` | 0003PY `SetHoverControl` | 9 / `4858E80E3D933C1F5A31B419AA737FF4B43FFE649895A16216F9151C03591B6D` | vtable `0x614494` | CPP/H override |
| `0x47d960-0x47da10` | 0003PY `AppendQuotedMessage` | 177 / `CFDDC6D34B5A26F227F10D1F5CFB670D506B934445A50A02E982056A1B2AAB3C` | two constructor callers | CPP/H |
| `0x47da20-0x47db6a` | 0003PY `OnMailTransferReplyPacket` | 331 / `E2FEC6CA5E797F9560143A6E9C7B99C0FAFC1DB3F105209DF93C990E9648B485` | vtable `0x614498` | CPP/H override |
| `0x47db70-0x47dca0` | 0003PY `ShowMailTransferReplyAlert` | 305 / `5EDC38B6326CA311864A73C1830F67B99B4AA28CF601C80F42FC73A0EACA1E2A` | zero direct xrefs | CPP/H |
| `0x47dcb0-0x47e032` | 0003PY `SendMail` | 899 / `48901659BBC9C5E35C975D8206E2AFB8D3CBFD9E6945659D22EDC5A62E5C3039` | caller `0x47d85e` | CPP/H |
| core vtables `0x614238-0x6144db` | 000321 compiler data | four decorated families | constructor stores/data xrefs | UID000321 formal CPP compiler-covered comment; class H declarations generate the tables |
| `0x47ebf0-0x47ec2b` | 0003Q7 scalar deleting destructor | 60-byte compiler wrapper | vtable route | no handwritten CPP |
| internal gaps | compiler alignment/jump tables | exact `align 10h`; jump tables at `0x47a1bc`, `0x47c714` | no source xrefs | no code; preserve boundaries |
| alert strip `0x47e040...` | 0000HW dependencies | separate children | alert/session xrefs | excluded from core CPP |

Counts reconcile: 34 modeled + 19 raw = 53 separately emitted source-shaped bodies; 4 core class-vtable families are compiler-covered; one scalar wrapper and secondary/tertiary thunks are compiler-covered. Two additional physically retained raw helpers at `0x0047ac90-0x0047acc8` and `0x0047ad20-0x0047ad75` are source-covered by the accepted `MailListPane` setter/list-insertion logic and therefore do not add duplicate formal CPP bodies. Every remaining inter-body byte is classified below as a return-immediate tail, alignment, or jump-table span.

### Exact Alignment, Resource, And Boundary Maps

The following SHA256 values identify the complete non-body spans between the 53 emitted bodies. `retn` operands remain attached to their preceding instruction but outside the accepted body-hash interval; alignment and jump-table bytes produce no handwritten source.

| Group | Exact span | Bytes / role | SHA256 |
| --- | --- | --- | --- |
| MailListDialog | `0x00479d2b-0x00479d2f` | 5 bytes, `CC` alignment | `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329` |
| MailListDialog | `0x00479e1e-0x00479e1f` | 2 bytes, `CC` alignment | `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2` |
| MailListDialog | `0x00479f3c-0x00479f3f` | 4 bytes, `CC` alignment | `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA` |
| MailListDialog | `0x00479f80-0x00479f8f` | `04 00` trailing `retn 4` operand plus 14 `CC` bytes | `7B00D0E1F49F88AD01A90295E041D63568A0F2D4D05DD3671213ACA0B5D4DAF4` |
| MailListDialog | `0x0047a014-0x0047a01f` | 12 bytes, `CC` alignment | `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902` |
| MailListDialog | `0x0047a05c-0x0047a05f` | 4 bytes, `CC` alignment | `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA` |
| MailListDialog | `0x0047a1b9-0x0047a1df` | 39-byte switch tail: `0F 1F 00`, six-entry jump table at `0x0047a1bc`, then fill | `6ACEF00961B7A464699476470612872C4F7FE75EFE6EDFAC4CEF68DF50701E14` |
| MailListDialog | `0x0047a1f2-0x0047a1ff` | 14 bytes, `CC` alignment | `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356` |
| MailListDialog | `0x0047a278-0x0047a27f` | 8 bytes, `CC` alignment | `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3` |
| MailListDialog | `0x0047a316-0x0047a31f` | 10 bytes, `CC` alignment | `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045` |
| MailListDialog | `0x0047a3ac-0x0047a3af` | 4 bytes, `CC` alignment | `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA` |
| MailListDialog | `0x0047a513-0x0047a51f` | 13 bytes, `CC` alignment | `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE` |
| MailListDialog | `0x0047a754-0x0047a75f` | 12 bytes, `CC` alignment | `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902` |
| MailListDialog | `0x0047a894-0x0047a89f` | 12-byte child tail, all `CC`; successor begins `0x0047a8a0` | `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902` |
| MailListPane | `0x0047a8f9-0x0047a8ff` | 7 bytes, `CC` alignment | `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D` |
| MailListPane | `0x0047a9de-0x0047a9df` | 2 bytes, `CC` alignment | `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2` |
| MailListPane | `0x0047aa8d-0x0047aa8f` | 3 bytes, `CC` alignment | `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE` |
| MailListPane | `0x0047ab66-0x0047ab6f` | 10 bytes, `CC` alignment | `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045` |
| MailListPane | `0x0047ab90-0x0047ab9f` | `04 00` trailing `retn 4` operand plus 14 `CC` bytes | `7B00D0E1F49F88AD01A90295E041D63568A0F2D4D05DD3671213ACA0B5D4DAF4` |
| MailListPane | `0x0047abfa-0x0047abff` | 6 bytes, `CC` alignment | `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722` |
| MailListPane | `0x0047ac27-0x0047ac2f` | 9 bytes, `CC` alignment | `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE` |
| MailListPane | `0x0047ac88-0x0047ac8f` | 8 bytes, `CC` alignment | `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3` |
| MailListPane | `0x0047ac90-0x0047ac9f` | 16-byte retained `m_pageRequestPending` setter, source-covered by the inline class setter | `A3D2A16A9F2360F3EEE207B6B893E4BE7DC46F4EAA1FC93BF5989BA4A8BE503A` |
| MailListPane | `0x0047aca0-0x0047acc8` | 41-byte retained selected-sender copy helper, source-covered by reply/open logic | `D7699D91D6CB6047D2F9396DA2013F25235F412E39DB8951E6A79C58DC32A293` |
| MailListPane | `0x0047acc9-0x0047accf` | 7 bytes, `CC` alignment | `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D` |
| MailListPane | `0x0047ad13-0x0047ad1f` | 13 bytes, `CC` alignment | `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE` |
| MailListPane | `0x0047ad20-0x0047ad75` | 86-byte retained insertion-position helper, source-covered by `AddOrUpdateMailEntry` | `5570204CC99778D3E9724BE1397112F9E39AB0862326724E996AD0F34C6A2137` |
| MailListPane | `0x0047ad76-0x0047ad7f` | 10 bytes, `CC` alignment | `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045` |
| MailDialog | `0x0047c405-0x0047c40f` | 11 bytes, `CC` alignment | `3682D6B3FA9DB15202DA99B219973806EFB3A3A2B1E4BFA08BDE8118E68AF49F` |
| MailDialog | `0x0047c4ac-0x0047c4af` | 4 bytes, `CC` alignment | `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA` |
| MailDialog | `0x0047c711-0x0047c72f` | 31-byte switch tail: `0F 1F 00`, seven-entry jump table at `0x0047c714` | `5F1C904838C12E24D2F45384A6A0004C6CE64D7CD1E7EFC2025B1CAAB4E7AA13` |
| MailDialog | `0x0047c891-0x0047c89f` | `04 00` trailing `retn 4` operand plus 13 `CC` bytes | `E91E5EA98FAA3572FBC8AE32F0099245176F2725CCD9D214B180F15834041AFB` |
| MailDialog | `0x0047c8c3-0x0047c8cf` | 13 bytes, `CC` alignment | `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE` |
| MailDialog | `0x0047c94b-0x0047c94f` | 5 bytes, `CC` alignment | `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329` |
| MailDialog | `0x0047c9e6-0x0047c9ef` | 10 bytes, `CC` alignment | `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045` |
| MailDialog | `0x0047cb3e-0x0047cb3f` | 2 bytes, `CC` alignment | `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2` |
| MailDialog | `0x0047cc74-0x0047cc7f` | 12 bytes, `CC` alignment | `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902` |
| MailDialog | `0x0047cd0e-0x0047cd0f` | `0C 00`, trailing `retn 12` operand | `BF60E4349CACE6BCE0D552E8D783428DB66D0D649BD9E430A3627E2EE14AC839` |
| MailDialog | `0x0047cd78-0x0047cd7f` | `08 00` trailing `retn 8` operand plus six `CC` bytes | `7B58DB6B3C996F9588D2B5EB022EEE134FC2639CF8A58EF6A2136E104B6658CE` |
| MailDialog save helper | `0x0047d04a-0x0047d04f` | 6-byte child tail, all `CC`; successor begins `0x0047d050` | `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722` |
| NewMailDialog | `0x0047d7c1-0x0047d7cf` | 15 bytes, `CC` alignment | `54CC44B4F04FD53183FD49F6BAB21E0B667C6C63F62AF0A4338E4C47C86E64AB` |
| NewMailDialog | `0x0047d818-0x0047d81f` | 8 bytes, `CC` alignment | `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3` |
| NewMailDialog | `0x0047d882-0x0047d88f` | 14 bytes, `CC` alignment | `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356` |
| NewMailDialog | `0x0047d943-0x0047d94f` | 13 bytes, `CC` alignment | `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE` |
| NewMailDialog | `0x0047d959-0x0047d95f` | 7 bytes, `CC` alignment | `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D` |
| NewMailDialog | `0x0047da11-0x0047da1f` | 15 bytes, `CC` alignment | `54CC44B4F04FD53183FD49F6BAB21E0B667C6C63F62AF0A4338E4C47C86E64AB` |
| NewMailDialog | `0x0047db6b-0x0047db6f` | 5 bytes, `CC` alignment | `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329` |
| NewMailDialog | `0x0047dca1-0x0047dcaf` | 15 bytes, `CC` alignment | `54CC44B4F04FD53183FD49F6BAB21E0B667C6C63F62AF0A4338E4C47C86E64AB` |
| Core tail | `0x0047e033-0x0047e03f` | 13-byte tail, all `CC`; raw file offset `0x0007d433`; successor `MailTransferReplyAlert` begins `0x0047e040` | `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE` |

The complete file-owned resource/import manifest is finite:

| Kind | Exact literals or symbols | Ownership/source disposition |
| --- | --- | --- |
| Dialog assets | `DLGBBS05.EPF`, `DLGBBS05.EPD`, `DLGBBS05.PAL`; `DLGBBS06.EPF`, `DLGBBS06.EPD`, `DLGBBS06.PAL`; `DLGBBS07.EPF`, `DLGBBS07.EPD`, `DLGBBS07.PAL`; `NPAL8.PAL` | Constructor-loaded MailDialogs resources; referenced from formal CPP, not separately emitted. |
| Controls and labels | `Read`, `Write`, `Reply`, `Delete`, `Close`, `New`, `Previous`, `Next`, `Save`, `Send`, `Cancel`, `OK`, `Keep a copy` | UI text/resources consumed by the four constructors. |
| Formatting and mail text | `%5d`, `%2d/%2d`, `%s\\NexusTK`, `%s\\NexusTK\\Mail`, `%s\\%s`, `%s\\%d_%s_%s.txt`, `From : `, `\r\nDate : `, `\r\nSubject : `, `\r\n\r\n`, `\n`, `> `, empty wide string, `Successfully saved mail`, `Your mail didn't go through due to an error.` | Exact formatter/export/quote/alert literals; owned by or consumed in the formal MailDialogs bodies. |
| External imports | `SHGetFolderPathW`, `CreateDirectoryW`, `_wfopen`, `fclose`, `swprintf`, `_wcscpy_s` | Win32/CRT dependencies only; no separate MailDialogs emitter. |
| Project helpers | `SetDialogImage`, `AddDialogButton`, `AddDialogLabel`, `WriteWideText`, `ShowSystemMessage`, packet serialization/send helpers | Project-local dependencies called by formal bodies; ownership remains in their documented modules. |


### Generated CPP/H Defect Contract

- Historical coherent validator command `000000021890` ran at `2026-08-11T10:31:16-04:00` as `python .\tools\validator.py --mode file --file by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md --apply --wait-generated --queue-timeout 240`; it exited `0`, returned `ok:1`, and refreshed generated output globally. At that dated baseline, `MailDialogs.cpp` contained one class declaration and eleven definitions: ten mapped physical bodies plus one synthesized helper, with four empty markers and no sibling H.
- Historical read-only snapshot command `000000022403` at `2026-08-11T20:10:00-04:00` superseded the command-21890 artifact after the ordinary callback but remained partial: generated CPP SHA256 `4CF33A1F8CDBA81DA4DF05AEB3123D16AE2DC33920732CAB8D6BA2032DE5FE1C` had ten UID markers and one empty marker; generated H SHA256 `0D28ADCA132DB46BC61BDDA86D018FEA3BF45F5332AAA8F2EDC77D54CA49412C` had four UID markers. Neither dated command is current generated authority after this ordinary metadata repair.
- The accepted current source route requires four complete class declarations in formal H and all 53 bodies exactly once in physical source order: I01-I14 under UID00007L/UID0003PU, I15-I30 under UID00007M/UID0003PV, I31-I43 under UID00007K/UID0003PW, I44 under UID00007K/UID0003PX, and I45-I53 under UID000096/UID0003PY. Class/root emitter positions are `0,1,2,3`; child positions are `0`, `0`, `0/1`, and `0` respectively.
- UID000321 occupies final root position `4` and emits only the formal compiler-covered explanatory comment. That nonblank formal disposition removes the empty-emitter marker without emitting literal vtable arrays, COLs, constructor vptr stores, secondary/tertiary adjustment thunks, or scalar deleting wrappers; those remain compiler consequences of the four class declarations.
- Coherent generated refresh and physical CPP/H readback remain supervisor-owned; this by-file page defines the exact expected result without editing generated output directly.

### Historical Assumptions And Resolution

- `78` modeled functions: superseded by current live enumeration of `79`; the missing modeled body was `0x0047db70`.
- Per-class `MailListDialog.cpp` / `MailDialog.cpp` / `NewMailDialog.cpp`: preserved as an unproven historical alternative; one contiguous `MailDialogs.cpp` plus `MailDialogs.h` is the active route.
- Seven-method `NewMailDialog`: superseded by the nine-body inventory including `0x0047d7d0` and `0x0047db70`.
- `SetDialogMode` at `0x0047d950`: rejected; the nine-byte tail call is `SetHoverControl`.
- Zero-direct-xref retained bodies as blockers/padding: rejected after exact byte/boundary/behavior review; negative routes cap lexical confidence but do not erase complete source bodies.
- Blank or prose-only C++: superseded. All nine formal payloads now have exact owning channels; all draft/formal source appears there, not only in prose.

### Source Placement And Boundaries

- Core emitted source begins at `0x00479110`; I53 ends at `0x0047e032` inclusive. The complete child tail is `0x0047e033-0x0047e03f`, thirteen `CC` bytes at raw file offset `0x0007d433`, SHA256 `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`, before BulletinReplyAlerts begins at raw constructor `0x0047e040`.
- Corrected pane/request child: `0x0047a8a0-0x0047b21f`. Corrected MailDialog core child: `0x0047b220-0x0047cd79`. Save/export remains `0x0047cd80-0x0047d04a`; compose remains `0x0047d050-0x0047e033`.
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md) remains a non-emitting mixed index spanning core, alert, and later compiler slices. [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) is compiler-covered through class H declarations, and [UID:0003Q7][0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor](by-memory/0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor.md) is non-emitting scalar deleting ABI glue.
- No MailDialogs-owned standalone writable global/table/resource definition was found; packet sender, asset mode, dialog state, and alert singleton are dependencies.

## Changes

- 2026-08-11 Agent-B002 UID0000KZ whole-file implementation callback:
  - Raised `86/86` to `94/94` and replaced the sampled/stale model with the complete 53-body core inventory, current 79-modeled-function broad-family count, exact core/alert boundary, and corrected child ranges.
  - Established one `MailDialogs.cpp` plus required `MailDialogs.h`, documented all nine formal payload routes, and preserved compiler-generated vtables/thunks/scalar wrapper as no-literal-code consequences.
  - Added the exact generated-defect contract, no-global negative evidence, ownership/session/alert exclusions, and explicit historical resolution for the 78-count, per-class split, seven-method compose inventory, `SetDialogMode`, no-xref blockers, and blank-C++ assumptions.
- 2026-07-22 B005 accepted UID0002T7 support sync: scores and projected path unchanged at `86/86`. Added the four caller-side packet-result evaluations, resolved the first/fourth retained constructor parameters, recorded UID0002T7 as source-emitting, and preserved `MailDialogs` as consumer/source context rather than alert implementation owner.
- 2026-06-27 B006 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync:
  - Added mail-side consumer-slot evidence for MailListDialog, MailDialog, and NewMailDialog secondary `+0x10` entries, all storing `0x00472040`.
  - Scores and projected path unchanged; [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) remains routed through [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), while this page remains the owner for mail-specific dialog methods.
- 2026-07-03 B012 UID0004G7 support sync:
  - Scores and projected path unchanged.
  - Added the BulletinSession mail-list opener constructor-call direction and `MailListDialog +0x274` returned-id consumption by `BulletinSession +0x102`.
- 2026-06-21 supervisor-worker Rule 26 incorporation of B009 `00007J-MailDeleteReplyAlert-class-source-quality.md`: no score change. Added exact inline construction sites and mode-byte values for `MailDeleteReplyAlert` while preserving `MailDialogs` as consumer/source context and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) as current alert owner.
- 2026-06-20 supervisor Rule 26 incorporation of B006 MailDialog source-quality report:
  - Recorded `SaveCurrentMailToFile` as the preferred source-facing name for [UID:0003PX][0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper](by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md), corrected the rejected Ctrl+S send/reply interpretation, and retained C++ deferral until file-dialog/path helper prototypes are source-quality.
  - Clarified that `MailDialog` consumes and inline-constructs the mail delete alert helpers while current alert implementation ownership remains with [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), not this file page.
- 2026-06-20 supervisor-worker Rule 26 incorporation of B007 `00007L-MailListDialog-class-source-quality.md`:
  - Synced the file-level source split with retained MailListDialog no-direct-route helper pockets, `SendSelectedMailReadRequest`, child/control id `7`, `MailListEntryRow` row dependencies, shared page-request helper context, and MailListDialog's consumer relationship to `ConfirmDeleteMailAlert`/`MailDeleteReplyAlert` while preserving current alert ownership through [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- 2026-06-16 supervisor execution of B001 MailDialogs split report:
  - Added exact core child links [UID:0003PU][0x00479110-0x0047a894.MailListDialogCore](by-memory/0x00479110-0x0047a894.MailListDialogCore.md)-[UID:0003PY][0x0047d050-0x0047e033.NewMailDialogCore](by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md) and the [UID:0003PX][0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper](by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md) save-mail helper.
  - Moved mail alert wrappers from core proposed contents into dependency/alternate-placement notes while keeping current routing through [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
  - [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md) is now a non-emitting split inventory, not this file's aggregate emitted range.
- 2026-06-20 supervisor Rule 26 incorporation of B002 MailListPane source-quality report:
  - Updated MailListPane file-scope notes to record the five retained no-direct-route helper pockets, the `MailListEntryRow`-backed selected read/delete/remove helpers, and the shared file-local `SendMailListPageRequest` helper.
  - Kept source placement in `MailDialogs.cpp`; the helper's shared call sites are MailDialogs-family callers and do not justify PacketBuffer/socket ownership or a standalone source file.
- 2026-06-10 B001-009: Added the exact owner-specific vtable child [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) as a direct `MailDialogs` child after live IDA MCP reconfirmed decorated bases, COL pointers, constructor-store xrefs, and the boundary before `MailTransferReplyAlert`.
- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/dialogs/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree both place `MailDialogs.cpp` under `ui/dialogs/`.
  - After: set the validator path to `NexusTK/ui/dialogs/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `MailDialogs.cpp` under `ui/dialogs`, and live IDA MCP lookup on 2026-06-05 confirms the `MailListDialog` anchor at `0x00479110` as a real function of size `0xc1b`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: mail list/read/compose/delete/transfer dialog family, vtable grouping, IDA boundaries, session/alert ownership split, raw constructor caveats, and cross-references are documented; confidence is capped by exact old/new split and alert-helper placement.
- 2026-06-07: Confidence changed from `82` to `85` after Batch 003 corrected-parent audit.
  - Before: the page recorded the right file-root candidate but kept the parent below the supervisor assignment gate because the alert-helper and old/new-mail split caveats were not balanced against current live IDA evidence.
  - After: the page records a live 78-function IDA audit, call-in edges, vtable/data refs, singleton refs, and boundary padding while preserving the split caveats; this supports `85` confidence for file-root parenting without implying final-source completeness.
- 2026-06-14 Agent-A001 Goal 2 low-score repair:
  - Confidence changed from `85` to `86`.
  - Replaced projected mail-alert constructor wording with exact raw constructor child links for `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert`; the new [UID:0003O8][0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor](by-memory/0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor.md) removes the last mail-transfer projected-constructor blocker while preserving the shared-alert versus mail-private source split caveat.
