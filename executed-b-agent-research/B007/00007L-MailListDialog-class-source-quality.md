** TARGET-REPORT-UID:00007L **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00007L] MailListDialog Class Source-Quality Report

Status: FINISHED

Agent: B007

Target: `by-class/MailListDialog.md`

Required target: [UID:00007L] `MailListDialog`

Current assignment mode: report-only. I did not edit `by-*` target/support docs, generated files, shared coverage reports, or `by-memory/-coverage-report.md`.

## Recommendation

Recommended target metadata:

```yaml
UID: 00007L
COMPLETION: 88
CONFIDENCE: 88
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000KZ
EMITTER_UIDS:
  - 0000KZ
SOURCE_FILE: NexusTK/ui/dialogs/MailDialogs.cpp
RECONSTRUCTION_CPP: leave blank on the class page
```

Owner/emitter should stay [UID:0000KZ] `MailDialogs`. The class is a received-mail list dialog and belongs with the core mail dialog source cluster, not `BulletinSession`, `ListPane`, `BulletinReplyAlerts`, or a standalone generated helper bucket.

The score should move from `85/86` to `88/88`. The target is materially better than the current page because the class owner, constructor callers, vtable stores, child-list relationship, selected-mail packet flow, incoming packet dispatch, alert dependency, row layout dependency, and previously omitted helper pockets can now be stated with evidence. I am not recommending 90+ because live IDA MCP was unavailable in this session, several source-shaped helper pockets have no direct `call rel32` or dword pointer xrefs in the local PE scan, the exact project-native list wrapper API names remain unproven, and some inherited dialog fields are still only layout/usage inferred.

## Baseline Validation

Scoped validator dry run was run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00007L-MailListDialog-class-source-quality-removed.md](00007L-MailListDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
Exit code: 0
ok: 1
ok           00007L by-class/MailListDialog.md UID header exists
root: C:\FastStorage\NTK_Sources\source-3\project-documentation
mode: file
scanned markdown files: 1
stats_incremental_skip 00007L project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows
autogen_report_noop for generated ag coverage reports
dry run only; pass --apply to write changes
```

Read-only IDA MCP availability check:

> Executable block R002 was removed from this report and preserved verbatim in [00007L-MailListDialog-class-source-quality-removed.md](00007L-MailListDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
IDA_MCP_UNAVAILABLE: Unable to connect to the remote server
```

Because live IDA was unavailable, I used the local PE image and Capstone disassembly as the binary revalidation source. The PE inspected was `E:\NTK\Resources\NexusTK\NexusTK.exe`.

Local PE facts:

```text
image base: 0x00400000
.text:  0x00401000-0x0060c600
.rdata: 0x0060d000-0x0066c200
.data:  0x0066d000-0x0069ce24
.rsrc:  0x0069d000-0x006b2e00
```

## Evidence Re-Read

Re-read target and support docs as leads, then checked the claims against current generated coverage, current markdown, and local PE/Capstone evidence:

- `by-class/MailListDialog.md`
- `by-memory/0x00479110-0x0047a894.MailListDialogCore.md`
- `by-class/MailListPane.md`
- `by-memory/0x0047a8a0-0x0047b110.MailListPaneCore.md`
- `by-class/MailDialog.md`
- `by-memory/0x0047b220-0x0047cc74.MailDialogCore.md`
- `by-class/NewMailDialog.md`
- `by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md`
- `by-file/MailDialogs.md`
- `by-memory/0x00479110-0x0047ec2b.MailDialogs.md`
- `by-type/by-vtable/MailDialogCoreVtables.md`
- `by-class/BulletinSession.md`
- `by-file/BulletinSession.md`
- `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`
- `by-file/BulletinReplyAlerts.md`
- `by-class/MailDeleteReplyAlert.md`
- `by-class/ConfirmDeleteMailAlert.md`
- `by-class/DeleteReplyAlert.md`
- `by-class/ListPane.md`
- `by-file/ListPane.md`
- `by-global/g_packetSender.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `by-class/-coverage-report.md`
- Prior report lead: `tools/leaser/Agents/Agent-B002/research/00007M-MailListPane-class-source-quality.md`
- Prior split-audit lead: `tools/leaser/Agents/Agent-B001/research/executed/older/0001Y2-MailDialogVtableFamily.md`

The prior B002 `MailListPane` row layout report was useful but was treated as a lead, not proof. I revalidated the row offsets, helper pockets, packet subcommands, and shared page-request helper from the local PE disassembly.

## Current Target State

Current `by-class/MailListDialog.md` is `85/86`, reconstructable, owner/emitter [UID:0000KZ] `MailDialogs`, and leaves the reconstruction C++ blank. It documents only six named methods:

- constructor/parser `0x00479110-0x00479d2b`
- `SendMailRequest` `0x00479d30-0x00479e1e`
- `OnAction` `0x0047a060-0x0047a1b9`
- `UpdateButtonStates` `0x0047a320-0x0047a3ac`
- `OnServerPacket` `0x0047a3b0-0x0047a513`
- `UpdateMailList` `0x0047a520-0x0047a754`

That omits several source-shaped helper pockets inside the exact [UID:0003PU] range. Those helpers should not be ignored merely because direct xrefs were not found in a simple `call rel32`/dword scan.

## Revalidated Binary Facts

Direct rel32 callers checked in the local PE:

```text
0x00479110 MailListDialog constructor:
  callers: 0x0047173f, 0x00471e51

0x00479d30 selected-mail read request helper:
  caller: 0x0047a0a3

0x0047a520 list update helper:
  caller: 0x0047a4f0

0x0047a8a0 MailListPane constructor:
  callers: 0x00479273, 0x00479815

0x0047a900 MailListPane add/update row helper:
  callers: 0x00479406, 0x004799a8, 0x0047a70e

0x0047ac30 MailListPane selection-count path:
  callers: 0x0047adc8, 0x0047ae1c

0x0047acd0 MailListPane find/remove helper:
  callers: 0x00479f61, 0x0047a96d, 0x0047ab79, 0x0047c4e2, 0x0047e7f9

0x0047b080 shared mail-list page request helper:
  callers: 0x0047a056, 0x0047ac21, 0x0047ac7a, 0x0047d812, 0x0047e0e1
```

No direct rel32 callers or dword pointer refs were found for these MailListDialog helper starts in the simple PE scan:

```text
0x00479e20
0x00479f40
0x00479f90
0x0047a020
0x0047a1e0
0x0047a200
0x0047a280
0x0047a760
```

This is not evidence that they are dead. They are aligned, source-shaped, and consistent with adjacent virtual dispatch/action-table patterns. The target should document them as no-direct-route helper pockets and cap confidence accordingly.

## Heuristic / Inference Reanalysis And Validation

### Source owner and placement

Best inference: `MailListDialog` remains in `NexusTK/ui/dialogs/MailDialogs.cpp` under [UID:0000KZ] `MailDialogs`.

Evidence:

- `BulletinSessionCore` calls the `MailListDialog` constructor at `0x0047173f` and `0x00471e51`, but only as a session coordinator. It does not own the concrete dialog.
- `by-memory/0x00479110-0x0047ec2b.MailDialogs.md` currently partitions this range into `MailListDialog`, `MailListPane`, `MailDialog`, `NewMailDialog`, and related helper/alert-adjacent children.
- `MailDialogCoreVtables` groups the core mail dialog vtables together under MailDialogs.
- `MailDialogs.md` already treats `MailListDialog`, `MailListPane`, `MailDialog`, and `NewMailDialog` as a source cluster.

Alternatives rejected:

- `BulletinSession`: rejected because it is caller/coordinator only.
- `ListPane`: rejected because `MailListDialog` only uses the reusable list control and owns mail-specific packet/action behavior.
- `BulletinReplyAlerts`: rejected for this class. It remains relevant only for confirmation/reply alert wrappers used by this class.
- Separate `MailListDialog.cpp`: possible source split, but current evidence supports a compact MailDialogs source cluster better than a separate file.

### Class method and helper names

Recommended source-facing method inventory for the target:

| Address | Recommended source-facing name | Evidence and notes |
| --- | --- | --- |
| `0x00479110-0x00479d2b` | `MailListDialog::MailListDialog(...)` | Constructor/parser. Called from `BulletinSession` at `0x0047173f` and `0x00471e51`. Stores MailListDialog vtables and constructs `MailListPane` children. |
| `0x00479d30-0x00479e1e` | `MailListDialog::SendSelectedMailReadRequest()` | Current name `SendMailRequest` is too generic. It fetches selected row data from child id `7`, writes outgoing opcode `0x3b`, subcommand `0x03`, selected mail id, list/page id, trailing zero, and sends length `7` through `g_packetSender`. |
| `0x00479e20-0x00479f3c` | `MailListDialog::SendSelectedMailDeleteRequests()` | No direct xref found, but body loops selected rows from child id `7`, writes opcode `0x3b`, subcommand `0x05`, list id and selected mail ids, sends length `6`, then interacts with the dialog/session state. |
| `0x00479f40-0x00479f82` | `MailListDialog::RemoveMailEntryByIdAndRefresh(unsigned short mailId)` | No direct xref found. Calls `MailListPane::FindMailIdIndex`, removes one row, and refreshes the list. |
| `0x00479f90-0x0047a014` | `MailListDialog::RemoveSelectedMailEntriesAndRefresh()` | No direct xref found. Reads selected indices from child id `7`, removes selected rows with index adjustment, then refreshes. |
| `0x0047a020-0x0047a05c` | `MailListDialog::RequestInitialMailPage()` | No direct xref found. Fetches child id `7`, reads list id from `MailListPane+0x14c`, selects a layout offset from `g_useEpfAssets`/`byte_66DA97`, sends page request with upper bound `0x7fff` through `0x0047b080`. |
| `0x0047a060-0x0047a1b9` | `MailListDialog::OnAction(...)` or `MailListDialog::HandleAction(...)` | Switch/jump-table action dispatcher. Calls read request, compose/reply, session close/back, delete confirm construction, and action-state paths. Existing name is acceptable. |
| `0x0047a1e0-0x0047a1f2` | `MailListDialog::OpenBlankComposeDialog()` | No direct xref found. Thin wrapper around the `BulletinSession`/mail compose helper with null arguments. |
| `0x0047a200-0x0047a278` | `MailListDialog::OpenReplyToSelectedMail()` | No direct xref found. Fetches selected row from child id `7`, copies the wide sender/name field at row `+0x006`, and opens the compose/reply dialog through the same session helper. |
| `0x0047a280-0x0047a316` | `MailListDialog::CreateSelectedMailDeleteConfirmAlert()` | No direct xref found. Allocates and constructs `ConfirmDeleteMailAlert`, stores alert vtables, sets mode byte `1`, and routes it to the UI/session. |
| `0x0047a320-0x0047a3ac` | `MailListDialog::UpdateButtonStates()` | Reads selection state from child id `7` and enables/disables action buttons. Current name is good. |
| `0x0047a3b0-0x0047a513` | `MailListDialog::OnServerPacket(...)` or `MailListDialog::HandleMailListPacket(...)` | Dispatches incoming packet subcommands. `packet[1] == 4` calls list update; `packet[1] == 7` opens/reuses `MailDeleteReplyAlert`. Existing name is acceptable if the class convention uses `OnServerPacket`. |
| `0x0047a520-0x0047a754` | `MailListDialog::UpdateMailList(...)` or `MailListDialog::ApplyMailListUpdate(...)` | Parses incoming list rows and calls `MailListPane::AddOrUpdateMailEntry`. Current name is acceptable; `ApplyMailListUpdate` is slightly more source-facing. |
| `0x0047a760-0x0047a894` | `MailListDialog::ShowMailDeleteReplyAlert(...)` | No direct xref found. Converts packet text, creates/reuses `MailDeleteReplyAlert`, and writes singleton/global alert state. |

The most important name fix is changing `SendMailRequest` to `SendSelectedMailReadRequest`. A generic `SendMailRequest` hides the fact that this specific helper serializes a selected-row read/open request, while delete and list-page requests are separate helpers.

### Generated/raw name mapping

Recommended mapping for raw names encountered in this range:

| Raw/generated evidence | Source-facing inference | Confidence |
| --- | --- | --- |
| `sub_479110` | `MailListDialog::MailListDialog` | High |
| `sub_479d30` | `MailListDialog::SendSelectedMailReadRequest` | High |
| `sub_479e20` | `MailListDialog::SendSelectedMailDeleteRequests` | Medium-high |
| `sub_479f40` | `MailListDialog::RemoveMailEntryByIdAndRefresh` | Medium-high |
| `sub_479f90` | `MailListDialog::RemoveSelectedMailEntriesAndRefresh` | Medium-high |
| `sub_47a020` | `MailListDialog::RequestInitialMailPage` | Medium-high |
| `sub_47a1e0` | `MailListDialog::OpenBlankComposeDialog` | Medium |
| `sub_47a200` | `MailListDialog::OpenReplyToSelectedMail` | Medium-high |
| `sub_47a280` | `MailListDialog::CreateSelectedMailDeleteConfirmAlert` | Medium-high |
| `sub_47a320` | `MailListDialog::UpdateButtonStates` | High |
| `sub_47a3b0` | `MailListDialog::OnServerPacket` / `HandleMailListPacket` | High |
| `sub_47a520` | `MailListDialog::UpdateMailList` / `ApplyMailListUpdate` | High |
| `sub_47a760` | `MailListDialog::ShowMailDeleteReplyAlert` | Medium-high |
| `sub_47a8a0` | `MailListPane::MailListPane` | High |
| `sub_47a900` | `MailListPane::AddOrUpdateMailEntry` | High |
| `sub_47acd0` | `MailListPane::FindMailIdIndex` / selected-row lookup support | High |
| `sub_47b080` | file-local `SendMailListPageRequest(...)` | High |
| `dword_67a7ec` | `g_packetSender` | High; supported by `by-global/g_packetSender.md` and packet send call pattern. |
| `dword_67adbc` | `g_pMailDeleteReplyAlert` | High; supported by alert docs and singleton/reuse pattern. |
| `byte_66da97` | `g_useEpfAssets` or equivalent asset/layout mode flag | Medium; behavior chooses layout offset `-20` vs `-16`. |
| `dword_67a748` | dialog/session/global collection pointer used during request close/back path | Low-medium; usage is visible, but source-facing name is not safe enough to finalize from this target alone. |

### MailListPane relationship and child collection semantics

`MailListDialog` should describe `MailListPane` as a contained child/list control, not as a base class or external owner.

Evidence:

- The constructor calls `MailListPane` constructor at `0x00479273` and `0x00479815`.
- It calls `MailListPane::AddOrUpdateMailEntry` at `0x00479406`, `0x004799a8`, and later from update flow at `0x0047a70e`.
- Action/update helpers repeatedly fetch child/control id `7`, then call list/selection helpers.
- The reusable `ListPane` docs confirm selection-count, selected-indices, item-fetch, insert, remove, and refresh semantics.

Recommended source-facing child id name:

```cpp
static constexpr int kMailListPaneChildId = 7;
```

The target should not claim `this+0x1fc` is a `MailListPane *` member. Current evidence supports that it is an inherited child/control collection or lookup surface. The dialog retrieves child id `7` through that collection. The exact project API name for child lookup is not proven in this session.

### Row and packet field names

The row layout belongs primarily to `MailListPane`, but `MailListDialog` depends on it when sending read/delete/reply requests. The target should include the dependency explicitly and link/update the pane docs.

Recommended row struct for support docs and first-draft code:

```cpp
struct MailListEntryRow {
    unsigned short mailId;       // +0x000
    unsigned char unreadFlag;    // +0x002
    unsigned char month;         // +0x003
    unsigned char day;           // +0x004
    unsigned char pad_005;       // +0x005
    wchar_t sender[256];         // +0x006
    wchar_t subject[256];        // +0x206
}; // sizeof 0x406
```

Evidence:

- `MailListPane` constructor passes row size `0x406`.
- Add/update and draw paths use the `+0x000`, `+0x002`, `+0x003`, `+0x004`, `+0x006`, and `+0x206` offsets.
- Reply flow copies the first wide text field at row `+0x006`, which fits the sender/name field.
- The second wide field at row `+0x206` behaves as a second display string and is best named `subject`.

Rejected alternatives:

- `fromName` instead of `sender`: possible, but `sender` is better for a received-mail list and matches reply-to-selected behavior.
- `title` instead of `subject`: possible, but the mail UI domain makes `subject` the better source-facing name.
- `readFlag` instead of `unreadFlag`: rejected because the UI/update behavior treats it as an unread/new-mail state in row display and action state contexts.

### MailListPane fields at +0x14c and +0x14e

Recommended fields:

```cpp
unsigned short m_mailListId;        // +0x14c, also defensibly "m_mailType"
bool m_pageRequestPending;          // +0x14e
```

`m_mailListId` is my preferred name because the value is serialized with read, delete, and page request packets as the list/mailbox selector. Existing drafts may call it `m_mailType`; that is not wrong, but it is less precise for the packet use. If implementation wants lower churn against current docs, use `mailListId` in packet prose and mention `m_mailType` as the legacy/local alias.

`m_pageRequestPending` remains a good source-facing inference. It is set/cleared around list paging/request flow in `MailListPane`.

### Outgoing packet semantics

Recommended packet names and field order:

| Packet role | Opcode/subcommand evidence | Source-facing helper |
| --- | --- | --- |
| List page request | opcode `0x3b`, subcommand `0x02`, list id, upper-bound mail id, layout offset, length `7` | file-local `SendMailListPageRequest(...)` at `0x0047b080` |
| Selected mail read/open request | opcode `0x3b`, subcommand `0x03`, list id/page selector, selected mail id, trailing zero, length `7` | `MailListDialog::SendSelectedMailReadRequest()` |
| Selected mail delete request | opcode `0x3b`, subcommand `0x05`, list id, selected mail id, length `6` | `MailListDialog::SendSelectedMailDeleteRequests()` and related alert action flow |

The class page should avoid naming opcode `0x3b` as "bulletin" only or "mail" only if that broader protocol is still shared. For this target, source prose can say "mail/bulletin opcode `0x3b`" and name the subcommands by observed behavior.

### Incoming packet semantics

`MailListDialog::OnServerPacket` dispatches on `packet[1]`:

- `packet[1] == 4`: list-update packet, calls `UpdateMailList` / `ApplyMailListUpdate`.
- `packet[1] == 7`: delete-reply/result text packet, opens or reuses `MailDeleteReplyAlert`.

The target should name the second branch as `ShowMailDeleteReplyAlert` or `HandleDeleteReplyPacket`, not a generic "server alert" handler.

### Page request helper and old/new layout offset

`0x0047b080` should remain a file-local helper shared by MailListDialog/MailListPane/MailDialog/NewMailDialog flows, not a MailListDialog method. Direct callers found:

```text
0x0047a056
0x0047ac21
0x0047ac7a
0x0047d812
0x0047e0e1
```

The initial-page wrapper at `0x0047a020` passes upper bound `0x7fff`. The older-page path in `MailListPane` passes the last known mail id minus one. The layout/asset offset comes from `byte_66DA97`:

- current/EPF layout flag: `-20`
- old layout flag: `-16`

Recommended name for the argument is `layoutOffset`, `skinOffset`, or `rowLayoutOffset`. `layoutOffset` is the most neutral.

### Selected-row/request helper naming

`MailListPane` has a helper path that delegates selected-row request behavior back toward the owner/dialog. The `MailListDialog` side should use the more precise packet-sending name:

- pane helper: `RequestSelectedMail()` or `OpenSelectedMail()`
- dialog helper: `SendSelectedMailReadRequest()`

This avoids having two same-named methods with different responsibility.

### Delete confirmation and delete-reply alert placement

`MailListDialog` constructs or routes:

- `ConfirmDeleteMailAlert` from action/delete flow.
- `MailDeleteReplyAlert` from incoming delete-reply/result packet flow.

Ownership should not move to `MailListDialog` in this report. The current [UID:0000HW] `BulletinReplyAlerts` owner bucket remains the best owner for the alert wrapper classes because:

- the alert wrappers form a family in `BulletinReplyAlerts.md`;
- mail and board delete-reply alerts share similar wrapper patterns;
- exact alert child pages already exist under the alert owner;
- the class target depends on the alerts but does not own their vtables/family documentation.

Support docs should add cross-links from `MailListDialog` to the alert pages, and from alert docs back to the MailDialogs callers, without moving the owner unless a later full source-file split proves the private-class placement.

### Old/new mail source split

`MailDialog` and `NewMailDialog` are distinct classes, but current evidence still supports a single `MailDialogs.cpp` source cluster rather than a required `MailDialog.cpp`/`NewMailDialog.cpp` split.

Evidence:

- contiguous exact children under the MailDialogs split range;
- shared helper `0x0047b080` is called by list/read/compose-side flows;
- core vtables are already grouped in `MailDialogCoreVtables`;
- `NewMailDialog.md` already treats a separate `NewMailDialog.cpp` as possible, not proven.

Recommendation: keep source placement as `NexusTK/ui/dialogs/MailDialogs.cpp`; document the separate-file possibility as an open source-tree alternative only.

### Reachability and no-direct helper pockets

The no-direct helper pockets must be documented, not silently omitted. The PE evidence checked:

- direct `call rel32` refs;
- dword pointer refs in `.text`;
- adjacent function boundaries and returns;
- local calls from action/update paths;
- packet/helper behavior.

Impact:

- The helper names are source-quality inferences with medium to high confidence.
- Lack of direct refs caps target confidence at `88`, not 90+.
- The exact [UID:0003PU] child page should carry the detailed no-direct-route table before first-draft method-body C++ is emitted.

### First-draft class C++ readiness

Class-level first-draft C++ is not ready for `by-class/MailListDialog.md` and should remain blank.

This is a target-specific no-code/defer decision, not a generic caution. The class page should carry class responsibility, owner/source placement, method inventory, layout/child relationship, packet semantics, and the no-direct helper inventory. Method bodies belong on exact child pages.

Reasons:

- `MailListDialog` method bodies are exactly owned by [UID:0003PU] `by-memory/0x00479110-0x0047a894.MailListDialogCore.md`.
- Row storage/list behavior belongs to [UID:0003PV] `by-memory/0x0047a8a0-0x0047b110.MailListPaneCore.md`.
- Alert wrapper bodies belong to `BulletinReplyAlerts` child pages, not this class.
- The exact inherited base/member names for child lookup and session/dialog fields are still inferred, so a class-level declaration would either invent source API names or duplicate method bodies that belong to exact memory children.

Exact child pages that should carry code later:

- [UID:0003PU] `by-memory/0x00479110-0x0047a894.MailListDialogCore.md`: `MailListDialog` constructor, selected read/delete request helpers, remove helpers, page request wrapper, action dispatch, button-state update, server packet dispatch, list update, delete-reply alert display.
- [UID:0003PV] `by-memory/0x0047a8a0-0x0047b110.MailListPaneCore.md`: row struct, list insertion/update/removal, selection helpers, paging, and the shared page-request call sites.
- [UID:0003PW] `by-memory/0x0047b220-0x0047cc74.MailDialogCore.md`: read/reply dialog behavior.
- [UID:0003PX] mail save/helper child under `MailDialog`.
- [UID:0003PY] `by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md`: compose/send dialog behavior.
- Alert children [UID:0003MZ], [UID:0002SF], [UID:0002T7], [UID:0002T8], [UID:0002T9], [UID:0002TA] under [UID:0000HW] `BulletinReplyAlerts`: confirmation/delete-reply alert wrappers.

## Exact Recommended Target Changes

Apply these later during implementation:

1. Update `by-class/MailListDialog.md` metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 88
CANONICAL_OWNER: 0000KZ
RECONSTRUCTABLE: TRUE
EMITTER_UIDS:
  - 0000KZ
```

2. Keep the source file as `NexusTK/ui/dialogs/MailDialogs.cpp`.

3. Rename or annotate `SendMailRequest` as `SendSelectedMailReadRequest`; keep the old name only as a previous/local label if needed.

4. Add the no-direct helper pockets to the method inventory:

```text
0x00479e20-0x00479f3c SendSelectedMailDeleteRequests
0x00479f40-0x00479f82 RemoveMailEntryByIdAndRefresh
0x00479f90-0x0047a014 RemoveSelectedMailEntriesAndRefresh
0x0047a020-0x0047a05c RequestInitialMailPage
0x0047a1e0-0x0047a1f2 OpenBlankComposeDialog
0x0047a200-0x0047a278 OpenReplyToSelectedMail
0x0047a280-0x0047a316 CreateSelectedMailDeleteConfirmAlert
0x0047a760-0x0047a894 ShowMailDeleteReplyAlert
```

5. Add a "Row and packet dependencies" section with `MailListEntryRow`, `m_mailListId`, `m_pageRequestPending`, opcode/subcommands `0x3b/0x02`, `0x3b/0x03`, `0x3b/0x05`, incoming packet `4`, and incoming packet `7`.

6. Add a "Child control/list relationship" section documenting child id `7` as the mail list pane lookup id and avoiding a direct `this+0x1fc == MailListPane *` claim.

7. Add a "No-direct-route helper pockets" section explaining the direct-xref scan result and confidence impact.

8. Add a "C++ placement" section stating the class page remains blank and exact method child [UID:0003PU] should carry method-body code.

## Support-Doc Changes To Apply Later

Recommended support updates, still pending supervisor approval/implementation:

- `by-memory/0x00479110-0x0047a894.MailListDialogCore.md`
  - Raise to `88/90`.
  - Add helper-pocket table with the exact ranges above.
  - Add PE/Capstone reachability facts.
  - Add first-draft method-body readiness notes, but only emit code here if the implementation pass is prepared to model the child lookup/session/list wrapper API carefully.

- `by-class/MailListPane.md`
  - Update row layout and helper names from the revalidated evidence.
  - Recommended score after sync: `88/88`.
  - Add explicit relationship back to `MailListDialog`.

- `by-memory/0x0047a8a0-0x0047b110.MailListPaneCore.md`
  - Recommended score after sync: `88/90`.
  - Add the `MailListEntryRow` struct, `m_mailListId`/`m_pageRequestPending`, selected-row helpers, remove helpers, and `SendMailListPageRequest` caller list.

- `by-file/MailDialogs.md`
  - Keep owner/file placement.
  - Add the source split decision: core mail dialogs stay here; alert wrappers remain routed through `BulletinReplyAlerts`; separate `MailListDialog.cpp`/`NewMailDialog.cpp` remains unproven.
  - Parent score can remain `86/86` unless broader file coverage is updated.

- `by-memory/0x00479110-0x0047ec2b.MailDialogs.md`
  - Add note that [UID:0003PU] includes no-direct helper pockets inside `0x00479e20`, `0x00479f40`, `0x00479f90`, `0x0047a020`, `0x0047a1e0`, `0x0047a200`, `0x0047a280`, and `0x0047a760`.

- `by-type/by-vtable/MailDialogCoreVtables.md`
  - No owner change.
  - Optionally update slot/helper prose so pane-selected request naming matches `RequestSelectedMail`/`SendSelectedMailReadRequest`.

- `by-file/BulletinReplyAlerts.md`
  - No owner change.
  - Add cross-reference that `MailListDialog` constructs or reuses `ConfirmDeleteMailAlert` and `MailDeleteReplyAlert`, while alert wrapper ownership remains in [UID:0000HW].

- `by-class/MailDeleteReplyAlert.md`
  - No owner change.
  - Add `MailListDialog::OnServerPacket` / `ShowMailDeleteReplyAlert` as caller/context if implementation touches the alert docs.

- `by-class/ConfirmDeleteMailAlert.md`
  - No owner change.
  - Add `MailListDialog::CreateSelectedMailDeleteConfirmAlert` / delete action context if implementation touches the alert docs.

- `by-class/BulletinSession.md`, `by-file/BulletinSession.md`, and `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`
  - No required score or owner change.
  - Optional note only: constructor call sites `0x0047173f` and `0x00471e51` instantiate `MailListDialog`; concrete dialog ownership remains MailDialogs.

## Implementation Checklist For Later Same-Agent Callback

1. Re-open current docs before editing:

> Executable block R003 was removed from this report and preserved verbatim in [00007L-MailListDialog-class-source-quality-removed.md](00007L-MailListDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

2. Update `by-class/MailListDialog.md` first:

- metadata `88/88`;
- method/helper inventory;
- row/packet dependency section;
- source placement section;
- alert dependency section;
- no-direct helper evidence;
- class-level C++ no-code proof.

3. Update [UID:0003PU] child page:

- add exact helper ranges and recommended names;
- add packet field order;
- add caller/reachability table;
- decide whether the child page receives first-draft C++ in that implementation pass. Do not paste method bodies on the class page.

4. Update `MailListPane` class and child pages:

- add `MailListEntryRow`;
- add `m_mailListId` / `m_pageRequestPending`;
- add shared page request helper evidence;
- add relationship to `MailListDialog` selected row/read/delete flow.

5. Update source/support split docs:

- `MailDialogs.md`;
- `MailDialogs` split memory page;
- `MailDialogCoreVtables.md`;
- alert docs only if adding cross-references without changing owner.

6. Do not edit:

- `by-memory/-coverage-report.md`;
- generated files by hand;
- IDA database;
- unrelated target/support docs.

7. After implementation, run validators with `--apply` for every edited doc.

## Validator Commands For Implementation Pass

Run only for docs actually edited in that pass:

> Executable block R004 was removed from this report and preserved verbatim in [00007L-MailListDialog-class-source-quality-removed.md](00007L-MailListDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation edits multiple docs and the project validator supports a broader mode, run a final bounded validation after the file-level applies:

> Executable block R005 was removed from this report and preserved verbatim in [00007L-MailListDialog-class-source-quality-removed.md](00007L-MailListDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not apply `by-class/-coverage-report.md` manually unless the supervisor explicitly directs it.

## Exact Supervisor-Owned Coverage Row

Recommended replacement row for `by-class/-coverage-report.md`:

```markdown
- [UID:00007L][MailListDialog](by-class/MailListDialog.md) : reconstructable : 88% : strong : MailDialogs-owned received-mail list dialog with PE/Capstone-revalidated constructor callers from BulletinSession, three MailListDialog vtable stores, selected-mail read packet helper, action dispatch, button-state updates, incoming list-update/delete-reply packet handling, MailListPane construction/update relationship, file-local page request helper use, and source-shaped no-direct-route helper pockets for selected delete, remove-by-id, remove-selected, initial page request, compose/reply wrappers, delete-confirm construction, and delete-reply alert display; class-level C++ remains deferred to exact method child [UID:0003PU] while row/layout code belongs to [UID:0003PV] and alert wrappers remain under BulletinReplyAlerts.
```

## Remaining Open Questions And Score Impact

Open questions that still affect score/C++ readiness:

- Live IDA MCP was unavailable, so no IDA type/name database was consulted in this session.
- No direct rel32 or dword pointer xrefs were found for several source-shaped helper pockets; they should be documented but confidence stays below 90.
- Exact project-native names for inherited child lookup/list wrapper APIs are still not proven.
- `byte_66DA97` is strongly a layout/asset mode flag, but exact source name remains inferred.
- `dword_67A748` usage near request/close paths is visible, but its best source-facing name is not safe from this target alone.
- `m_mailListId` versus `m_mailType` remains a naming choice. I recommend `m_mailListId` and documenting `m_mailType` as the previous/local alias if needed.

These are not blockers for an 88/88 documentation update. They are blockers for class-level first-draft C++ and for 90+ confidence.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00007L-MailListDialog-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"00007L"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00007L-MailListDialog-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/00007L-MailListDialog-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00007L"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
