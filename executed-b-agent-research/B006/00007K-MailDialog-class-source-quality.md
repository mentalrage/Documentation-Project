** TARGET-REPORT-UID:00007K **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00007K MailDialog Class Source-Quality Report

Status: FINISHED

Agent: Agent-B006  
Assignment: B006 MailDialog class source-quality refresh under the B001-B007 cap  
Target UID: [UID:00007K]  
Target path: `by-class/MailDialog.md`  
Required output path: `tools/leaser/Agents/Agent-B006/research/00007K-MailDialog-class-source-quality.md`  
Scope honored: report-only. No target/support `by-*` docs, generated files, IDA database state, shared coverage reports, or `by-memory/-coverage-report.md` were edited.

## Bottom Line

[UID:00007K] `MailDialog` should remain reconstructable and should remain owned/emitted through [UID:0000KZ] `MailDialogs`. The current `85/86` row is not wrong, but it is now stale: the class page can be raised after implementation to `87/88` because the main source-placement, split, Ctrl+S helper, alert interaction, and high-probability field/control-name questions are more resolved than the current page records.

Recommended target metadata after implementation:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended C++ state for the class page: keep the formal `RECONSTRUCTION_CPP` block blank for now. This is a class declaration/source-quality target, and the current declaration is not first-draft ready because constructor control fields, text-control member offsets, and packet/session helper prototypes are not final enough. Method bodies should be carried later by the exact child pages, primarily [UID:0003PW] `MailDialogCore` and [UID:0003PX] `MailDialogSaveMailToFileShortcutHelper`; [UID:0003Q7] `MailDialogScalarDeletingDestructor` should remain non-emitting compiler glue.

Important correction: `0x0047c730` / `OnKeyInput` is not a Ctrl+S send/reply shortcut. It gates into [UID:0003PX] `0x0047cd80-0x0047d04a`, a save/export helper for the current mail content.

## Evidence Checked

Target and direct owner docs:

- `by-class/MailDialog.md`
- `by-file/MailDialogs.md`
- `by-memory/0x00479110-0x0047ec2b.MailDialogs.md`
- `by-memory/0x0047b220-0x0047cc74.MailDialogCore.md`
- `by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md`
- `by-memory/0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor.md`

Related class/source docs revalidated as leads, not proof:

- `by-class/MailListDialog.md`
- `by-class/MailListPane.md`
- `by-class/NewMailDialog.md`
- `by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md`
- `by-class/BulletinSession.md`
- `by-file/BulletinSession.md`
- `by-file/BulletinReplyAlerts.md`
- `by-class/ConfirmDeleteMailAlert.md`
- `by-class/MailDeleteReplyAlert.md`
- `by-global/g_pMailDeleteReplyAlert.md`
- `by-class/ListPane.md`

Vtable and split docs:

- `by-type/by-vtable/MailDialogVtableFamily.md`
- `by-type/by-vtable/MailDialogCoreVtables.md`
- `by-type/by-vtable/MailAlertCompanionVtables.md`
- `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`
- `by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md`

Prior B-agent reports used as leads:

- `tools/leaser/Agents/Agent-B001/research/executed/older/0000ZO-maildialogs-source-split-audit.md`
- `tools/leaser/Agents/Agent-B001/research/executed/older/0001Y2-MailDialogVtableFamily.md`
- `tools/leaser/Agents/Agent-B002/research/00007M-MailListPane-class-source-quality.md`
- `tools/leaser/Agents/Agent-B009/research/00007J-MailDeleteReplyAlert-class-source-quality.md`
- `tools/leaser/Agents/Agent-B006/research/0000ZP-DialogAndAlertDestructorAdjustorThunks-source-routing.md`

Coverage/generated state checked:

- `by-class/-coverage-report.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`
- `auto-generated/NexusTK/ui/dialogs/MailDialogs.cpp`

IDA MCP was not reachable from this tool session. A PowerShell probe to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`. To close the most important current-evidence gaps, this pass used current docs plus a direct read-only PE scan of `E:\NTK\Resources\NexusTK\NexusTK.exe`.

## Current Metadata Recommendation And Score Justification

Recommended state: `87/88`, reconstructable, owner/emitter [UID:0000KZ] `MailDialogs`, no class-level C++ yet.

Why this can go above `85/86`:

- The current owner/emitter route is stable. The class constructor has direct callers from BulletinSession paths at `0x004717f6` and `0x00471f71`, the vtable stores belong to the MailDialog vtable family, and the source-family route stays `NexusTK/ui/dialogs/MailDialogs.cpp`.
- The stale Ctrl+S wording is resolved. The sole direct call to `0x0047cd80` is from `0x0047c765` in the key handler, and the helper has save/export evidence such as the `From :` string and file-open/write setup. It is not send/reply composition.
- The mail-delete alert interaction is sufficiently resolved for class prose: `MailDialog` inline-constructs/uses `MailDeleteReplyAlert`, but current source ownership for the alert classes remains [UID:0000HW] `BulletinReplyAlerts`.
- The exact split remains valid: [UID:0003PW] core class method island, [UID:0003PX] Ctrl+S save helper, and [UID:0003Q7] non-emitting scalar deleting destructor wrapper.
- High-probability class/control names can now be recorded without pretending they are exact historical spelling: `m_dialogSession` at `MailDialog+0x270`, `m_currentReplyId` at `MailDialog+0x274`, reply-list child id `7`, and source-facing `SaveCurrentMailToFile` for `0x0047cd80`.

Why this should not go to `90+` or emit class C++ yet:

- The constructor builds many UI controls and parses packet/string state, but the current class page does not have a complete offset-to-member layout for sender/date/subject/body/reply controls.
- Packet helper names and exact enum names for the mail opcode family are still descriptive rather than source-proven.
- `0x0047cd80` is source-owned by MailDialog, but its file/path dialog helper names and exact output-format helper prototypes are not first-draft C++ ready.
- No current report proves an exact historical class declaration shape, base-class list, or all inherited subobject names for a safe `class MailDialog` shell.

## Direct Binary / PE Facts Rechecked

Direct read-only scan target:

```text
PE: E:\NTK\Resources\NexusTK\NexusTK.exe
MD5: 4247e04e20b65d6414c7238aa8ff5515
ImageBase: 0x00400000
.text: 0x00401000-0x0060c4ac
.rdata: 0x0060d000-0x0066c0be
.data: 0x0066d000-0x0069ce24
```

Direct `call rel32` / dword-reference facts:

| Target | Direct calls / data refs observed in this pass |
| --- | --- |
| `0x0047b220` `MailDialog` constructor | direct calls at `0x004717f6`, `0x00471f71` |
| `0x0047c500` command handler | dword ref at `0x006143e4` |
| `0x0047c730` key handler | dword ref at `0x00614408` |
| `0x0047c8d0` `SendReply` | direct call at `0x0047c67e` |
| `0x0047c9f0` delete-reply handler | dword ref at `0x006143f8` |
| `0x0047cd80` Ctrl+S save/export helper | direct call at `0x0047c765` |
| `0x0047ebf0` scalar deleting destructor | direct calls at `0x0047e921`, `0x0047e92c`; vtable/data ref at `0x0061439c` |

String facts rechecked:

- `From :` at `0x00610d88`
- `Delete` at `0x00612588`
- `Cancel` at `0x00614cbc`
- `%5d` at `0x006148d0`
- `%2d/%2d` at `0x006148d8`

The direct scan did not find exact UTF-16 `Date :` or `Subject :` strings in this binary search pass. Existing docs still cite them from earlier live IDA-backed work, but this report does not use those two strings as fresh proof.

## Heuristic / Inference Reanalysis And Validation

### Owner and source placement

Accepted: [UID:00007K] belongs to [UID:0000KZ] `MailDialogs`, generated under `NexusTK/ui/dialogs/MailDialogs.cpp`.

Evidence:

- Constructor callers are from the BulletinSession mail-dialog creation path.
- Primary/secondary/tertiary vtable stores and vtable-slot data route through the MailDialog vtable family.
- The command, key, reply, delete-confirmation, and delete-reply handlers operate on the same read/reply mail dialog state.
- `MailDialogs.md` already groups MailDialog, MailListDialog/MailListPane, and NewMailDialog as the mail UI source family.

Rejected alternatives:

- `BulletinSession`: caller/session owner only. It constructs and stacks mail dialogs but does not own the MailDialog methods.
- `BulletinReplyAlerts`: owns current mail-delete alert support, not the main MailDialog read/reply class.
- `MailListDialog` / `MailListPane`: adjacent mail-list source support and selected-mail request helpers, not owner of read/reply dialog internals.
- `NewMailDialog`: mail-composition sibling; no evidence that it owns the read/reply dialog or Ctrl+S save helper.
- Generic file/export utility owner for `0x0047cd80`: rejected because the helper has a sole MailDialog key-handler caller and formats current mail fields.

### Range and split policy

Accepted current split:

- [UID:0003PW] `0x0047b220-0x0047cc74.MailDialogCore`: source-authored MailDialog method island.
- [UID:0003PX] `0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper`: exact Ctrl+S save/export helper, still source-owned by MailDialog.
- [UID:0003Q7] `0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor`: compiler-generated scalar deleting destructor wrapper, non-emitting.
- [UID:0000ZO] `0x00479110-0x0047ec2b.MailDialogs`: non-emitting mixed source-family index, not a single source method.

No additional split is recommended for the class page. Future method-body work may split [UID:0003PW] into individual method children if the project standard moves to one method per page, but that is not necessary for ownership or class metadata now.

### Method and helper names

Accepted source-facing names:

| Range | Recommended name | Evidence / caveat |
| --- | --- | --- |
| `0x0047b220-0x0047c404` | `MailDialog::MailDialog` | Constructor callers and vtable stores are already strong. |
| `0x0047c4b0-0x0047c4ff` | `RefreshSelectedMailInList` or `ReselectCurrentMailInList` | Current name is acceptable. It reselects/refreshes the selected mail in the list path before returning. Exact historical spelling is not proven. |
| `0x0047c500-0x0047c710` | `OnCommand` / `HandleCommand` | Virtual command slot; command ids route reply, delete confirmation, and page navigation. |
| `0x0047c730-0x0047c77f` | `OnKeyInput` / `HandleKeyInput` | Virtual key slot; Ctrl+S path calls `0x0047cd80`. Correct description is save/export, not send/reply. |
| `0x0047c8d0-0x0047c94f` | `SendReply` | Direct call from command case at `0x0047c67e`; sends reply payload. |
| `0x0047c950-0x0047c9ef` | `CreateConfirmDeleteAlert` / `ShowConfirmDeleteAlert` | Allocates/initializes the mail single-delete confirmation alert. Current name can stay. |
| `0x0047c9f0-0x0047cb3f` | `OnMailDeleteReply` / `HandleMailDeleteReply` | Vtable/data ref plus mail-delete alert handling and current-dialog update/pop behavior. |
| `0x0047cb40-0x0047cc74` | `ShowDeleteReplyAlert` / `ShowMailDeleteReplyAlert` | Inline constructs `MailDeleteReplyAlert` for the single-reply branch. |
| `0x0047cd80-0x0047d04a` | `SaveCurrentMailToFile` | Best source-facing name for class prose. Page filename can remain `MailDialogSaveMailToFileShortcutHelper` until helper C++ proves exact dialog/path helper spelling. |

Rejected names:

- `SendReplyShortcut` or any Ctrl+S send/reply wording for `0x0047c730` / `0x0047cd80`: rejected by sole-caller and save/export evidence.
- `NewMailDialog` save/compose helper for `0x0047cd80`: rejected because the only direct caller is MailDialog key handling.
- Raw/generated `sub_47CD80`: acceptable as an IDA label only, not a source-facing report name.

### Packet, command, and cursor/list helper names

High-probability names to record in target/support prose:

- `kBulletinMailOpcode` or `kMailDialogOpcode` for opcode `0x3b`. Existing mail-list/delete docs consistently use the same packet family.
- `SendMailListPageRequest` for the page-navigation helper behavior shared with MailListPane; command ids `5` and `7` send previous/next page requests.
- `RequestSelectedMail` / `OpenSelectedMail` for MailListPane selection behavior. The B002 MailListPane report rejects a pure `GetSelectedMailId` name because the helper sends/requests selected-mail content.
- `kReplyListControlId` for child/control id `7`, based on MailDeleteReplyAlert single-reply handling and ListPane support evidence.

Names not safe yet:

- Exact packet enum type names, cursor iterator class names, and stream/buffer helper names are still descriptive. Current docs prove behavior and packet constants but do not prove original source spelling.
- Constructor-local control-member names for sender/date/subject/body/reply widgets should be role-based until [UID:0003PW] receives a method-level decompilation pass.

### Field, control, and global names

Accepted high-probability class state:

| Storage | Recommended name | Evidence / caveat |
| --- | --- | --- |
| inherited/dialog control slot around `+0x1fc` | child/control collection pointer; use local id `kReplyListControlId = 7` for the reply list | B009 MailDeleteReplyAlert and ListPane support show child id `7` is used for reply-list interaction. Treat as inherited/control infrastructure, not a newly invented MailDialog field. |
| `MailDialog+0x270` | `m_dialogSession` or `m_session` | MailDeleteReplyAlert single-reply branch treats it as the owning/current dialog session context. Exact historical name is not proven. |
| `MailDialog+0x274` | `m_currentReplyId` or `m_selectedReplyId` | Read as the 16-bit reply/mail id used by the single-reply delete/update path. Prefer `m_currentReplyId` in prose because it reflects current dialog context. |
| global `0x0067adbc` | `g_pMailDeleteReplyAlert` | Existing global/class docs already establish singleton publication and scalar-destructor clearing. |

Rejected generated/raw interpretations:

- Do not add a second derived field for AlertPane `+0x26c` when documenting MailDeleteReplyAlert; B009 resolves that as inherited layout/current mail context.
- Do not name `MailDialog+0x270` as an alert mode flag. Alert mode byte lives in ConfirmDeleteMailAlert/MailDeleteReplyAlert objects, not the MailDialog object.
- Do not promote temporary decompiler names or generated UI labels as final fields without offset/control evidence.

### Alert placement

Accepted current route:

- `ConfirmDeleteMailAlert` and `MailDeleteReplyAlert` stay with [UID:0000HW] `BulletinReplyAlerts` for now.
- `MailDialog` class docs should describe them as inline construction/use sites and consumer interactions, not as source owners for the alert class implementations.

Evidence:

- Confirm-delete alert constructors and delete request behavior are shared in the alert support docs.
- `MailDeleteReplyAlert` has its own vtable/singleton/destructor evidence and B009 source-quality work.
- The mail dialog command path installs/uses the alert, but that does not prove physical source ownership moved from `BulletinReplyAlerts`.

Rejected alternative:

- Moving mail-only alert classes into `MailDialogs` is plausible as a future physical-source hypothesis, but current vtable/class/global docs and existing owner route are stronger. Do not make that ownership move in this class update.

### First-draft C++ readiness

Decision: [UID:00007K] class-level first-draft C++ is not ready.

No-code/defer proof for the class page:

1. The class page is an emitter target, but no safe declaration shell exists yet. The constructor's control/member layout is still incomplete.
2. The exact inherited/base layout for the primary/secondary/tertiary subobjects is vtable-proven but not source-declaration ready.
3. The most source-relevant bodies belong to exact child pages and need method-level field/prototype resolution before code emission.
4. Writing a partial class shell now would likely freeze guessed control names and packet helper types into generated output.
5. The scalar deleting destructor child is compiler ABI glue and should not be represented as handwritten C++.

Exact child pages that should carry code later:

- [UID:0003PW] `MailDialogCore`: constructor, selected-mail refresh, command handler, key handler, reply send, confirm-delete alert creation, mail-delete reply handling, and delete-reply alert creation after method-level field/control names are settled.
- [UID:0003PX] `MailDialogSaveMailToFileShortcutHelper`: `SaveCurrentMailToFile` helper after file-dialog/path helper names and output formatting helpers are resolved.
- [UID:0003Q7] `MailDialogScalarDeletingDestructor`: keep blank/no-emitter. Source destructor shape, if eventually declared, belongs on the class/method source target rather than this wrapper.

## Recommended Target And Support Doc Changes

### `by-class/MailDialog.md`

Recommended metadata: `87/88`, owner/emitter unchanged.

Body edits:

- Correct `OnKeyInput` from Ctrl+S send/reply wording to Ctrl+S save/export wording.
- Add a "Class State / Layout Inferences" section with `m_dialogSession`, `m_currentReplyId`, reply-list child id `7`, and caveats for constructor control members.
- Add a source-placement note: owner/emitter stays [UID:0000KZ] `MailDialogs`; mail-only alert ownership stays [UID:0000HW] pending separate alert-source work.
- Add child-page policy: `MailDialogCore` and `MailDialogSaveMailToFileShortcutHelper` should carry later method C++; scalar deleting destructor remains non-emitting.
- Remove or replace stale "95/95 emission bar" language. Current readiness is not blocked by an old numeric bar; it is blocked by unresolved class declaration/member names.
- Keep formal class C++ blank for now.

### `by-file/MailDialogs.md`

Recommended metadata: no score change required.

Body edits:

- Update the MailDialog row to say Ctrl+S save/export through [UID:0003PX], not generic send/reply.
- Add a short B006 reanalysis note that `SaveCurrentMailToFile` is the preferred source-facing helper name while exact historical spelling remains inferred.
- Preserve [UID:0000HW] `BulletinReplyAlerts` as current alert owner; mention `MailDialogs` private placement only as a rejected/future hypothesis.

### `by-memory/0x0047b220-0x0047cc74.MailDialogCore.md`

Recommended metadata: keep `86/90` unless a method-body implementation pass adds more decompilation detail; raising to `87/91` is reasonable only after constructor/control details are added.

Body edits:

- Correct key-handler wording to Ctrl+S save/export.
- Add direct-reference evidence for `SendReply` caller `0x0047c67e` and save helper caller `0x0047c765`.
- Add high-probability names for session/reply fields and reply-list id.
- Add first-draft C++ defer note: exact child method page is the right destination, but not ready until control and helper prototypes are resolved.

### `by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md`

Recommended metadata: keep `85/90` unless helper prototype/path evidence is expanded.

Body edits:

- Use `SaveCurrentMailToFile` as the preferred source-facing method/helper name.
- Keep page title/filename for continuity.
- State that direct PE scan confirmed sole direct caller `0x0047c765` and `From :` at `0x00610d88`.
- Rejected alternatives: NewMail compose helper, generic file utility, send/reply shortcut.
- C++ remains deferred pending file-dialog/path helper prototypes and exact formatting helpers.

### `by-memory/0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor.md`

Recommended metadata: no change.

Body edits:

- Optional: add a cross-link to this report's class-level no-code policy.
- Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++.

### Alert and vtable support docs

Recommended no ownership change now.

Support cleanup to apply when touching these pages:

- `by-class/MailDeleteReplyAlert.md`: fix stale parent-confidence prose if still saying [UID:0000HW] is `82`; the current `BulletinReplyAlerts.md` page is `86/87`.
- `by-file/BulletinReplyAlerts.md`: optional consumer note that MailDialog inline-constructs mail delete reply alerts but does not currently own their source route.
- `by-type/by-vtable/MailDialogCoreVtables.md`: ensure slots for `OnCommand`, `OnKeyInput`, and `OnMailDeleteReply` use source-facing names and mention secondary/tertiary scalar destructor thunks as compiler support only.
- `by-type/by-vtable/MailDialogVtableFamily.md`: no score change required; keep vtable stores and destructor adjustor routing.
- `by-class/MailListPane.md` / `MailListPaneCore`: if updated later, align names with B002: `RequestSelectedMail`, `SendDeleteRequestsForSelectedMail`, `SendMailListPageRequest`, and the `MailListEntryRow` layout.

## Exact Supervisor-Owned Coverage Row

Do not edit `by-class/-coverage-report.md` during this report-only assignment. If the supervisor accepts this report, replace the current [UID:00007K] row with:

```text
- [UID:00007K][MailDialog](by-class/MailDialog.md) : reconstructable : 87% : strong : B006 2026-06-20 source-quality reanalysis keeps owner/emitter [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), corrects the stale Ctrl+S note to save/export through [UID:0003PX] `0x0047cd80-0x0047d04a`, reconfirms PE/direct-reference evidence for constructor callers `0x004717f6`/`0x00471f71`, `SendReply` caller `0x0047c67e`, and save helper caller `0x0047c765`, preserves the split between [UID:0003PW] MailDialogCore, [UID:0003PX] save-mail helper, and non-emitting [UID:0003Q7] scalar deleting destructor, resolves mail-delete alert interactions as inline construction/use while current alert ownership stays with [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), records high-probability names for `m_dialogSession` at `+0x270`, `m_currentReplyId` at `+0x274`, reply-list child id `7`, and Ctrl+S `SaveCurrentMailToFile`, and leaves class-level C++ blank pending constructor/control field layout and child method-body readiness.
```

No `by-memory/-coverage-report.md` row is required for this report unless the later implementation also changes [UID:0003PW], [UID:0003PX], or [UID:0003Q7] metadata. If [UID:0003PX] is later raised after helper implementation, add a separate supervisor-owned row then.

## Validator Dry Run Performed

Scoped dry-run command executed from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00007K-MailDialog-class-source-quality-removed.md](00007K-MailDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
exit code: 0
mode: file
apply: False
scanned markdown files: 1
ok: 1
ok           00007K by-class/MailDialog.md UID header exists
dry run only; pass --apply to write changes
```

The validator also reported dry-run generated-output updates elsewhere, including `auto-generated/-ag-class-coverage.md`, but no files were written because `--apply` was not used.

## Validator Commands For Later Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the supervisor authorizes implementation:

> Executable block R002 was removed from this report and preserved verbatim in [00007K-MailDialog-class-source-quality-removed.md](00007K-MailDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support alert/vtable docs are touched in the same implementation, also run:

> Executable block R003 was removed from this report and preserved verbatim in [00007K-MailDialog-class-source-quality-removed.md](00007K-MailDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Coverage report validation is supervisor-owned if the row above is applied:

> Executable block R004 was removed from this report and preserved verbatim in [00007K-MailDialog-class-source-quality-removed.md](00007K-MailDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation Checklist For Later Same-Agent Callback

1. Lease the implementation docs before editing: `by-class/MailDialog.md`, `by-file/MailDialogs.md`, `by-memory/0x0047b220-0x0047cc74.MailDialogCore.md`, and `by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md`. Lease alert/vtable docs only if the implementation touches them.
2. Do not edit `by-memory/-coverage-report.md`. Do not edit `by-class/-coverage-report.md` unless the supervisor explicitly delegates coverage-row application.
3. Update [UID:00007K] metadata to `87/88`, owner/emitter unchanged.
4. Correct all Ctrl+S wording in `MailDialog.md` and `MailDialogCore.md` from send/reply to save/export.
5. Add source-facing helper name `SaveCurrentMailToFile` for `0x0047cd80` while preserving the existing helper page filename.
6. Add class state notes for `m_dialogSession`, `m_currentReplyId`, reply-list child id `7`, and unresolved constructor control members.
7. Add rejected alternatives: NewMail ownership, BulletinSession ownership, MailListPane ownership, generic export utility ownership, Ctrl+S send/reply, and moving mail-only alerts under MailDialogs in this pass.
8. Keep [UID:00007K] formal class C++ blank. Add an explicit first-draft C++ defer note with child-page destinations.
9. Update [UID:0003PW] prose only unless a method-level implementation pass is also in scope. Do not add speculative method bodies.
10. Update [UID:0003PX] prose with `SaveCurrentMailToFile`, direct caller `0x0047c765`, and helper-prototype blockers. Do not add C++ until file/path helper prototypes are resolved.
11. Keep [UID:0003Q7] non-emitting compiler glue; do not add handwritten scalar destructor wrapper code.
12. Apply validators listed above, inspect regenerated `auto-generated/NexusTK/ui/dialogs/MailDialogs.cpp` if any C++ is eventually added, and record whether the class block remains intentionally blank.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B006/research/00007K-MailDialog-class-source-quality.md`
- Modified: none
- Target/support by-* docs edited: none
- Generated/shared coverage edited: none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00007K-MailDialog-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00007K"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00007K-MailDialog-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/00007K-MailDialog-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00007K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
