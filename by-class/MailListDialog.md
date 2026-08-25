*** UID:00007L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "BoardDialogs.h"

class BulletinSession;
class MailListPane;
struct RectBounds;

class MailListDialog : public BoardDialog {
public:
    MailListDialog(BulletinSession *session, const RectBounds &bounds,
                   const unsigned char *packet);
    virtual void OnCommand(int commandId, int controlId);
    virtual bool OnServerPacket(const unsigned char *packet);
    void SendSelectedMailReadRequest();
    void SendSelectedMailDeleteRequests();
    void RemoveMailEntryByIdAndRefresh(unsigned short mailId);
    void RemoveSelectedMailEntriesAndRefresh();
    void RequestInitialMailPage();
    void OpenBlankComposeDialog();
    void OpenReplyToSelectedMail();
    void CreateSelectedMailDeleteConfirmAlert();
    void UpdateButtonStates();
    bool ApplyMailListUpdate(const unsigned char *packet);
    bool ShowMailDeleteReplyAlert(const unsigned char *packet);

private:
    BulletinSession *m_session;
    unsigned short m_mailListId;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MailListDialog

## Status

- Confidence: very strong for behavior, mail-dialog module placement, constructor callers, vtable stores, selected-mail packet flow, incoming packet dispatch, row-layout dependencies, retained helper bodies, and the complete declaration route. Exact historical lexical spellings remain the sub-95 confidence cap.
- Likely source file: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- Address range: [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- Evidence basis: prior live IDA MCP checks, B007 2026-06-20 local PE/Capstone revalidation against `NexusTK.exe`, existing mail-dialog by-* support docs, and current generated coverage. Historical recovered-output labels are treated only as naming leads.

## Class Purpose

`MailListDialog` is the received-mail listing dialog. It parses server packet data into mail list entries, owns the mail action buttons, sends read-mail and delete requests, opens compose/reply flows, coordinates with the contained [UID:00007M][MailListPane](by-class/MailListPane.md), and handles list update and delete/reply confirmation packets.

The class belongs to the core [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) source cluster. [UID:0000HX][BulletinSession](by-file/BulletinSession.md) constructs it from session/coordinator call sites, [UID:00007M][MailListPane](by-class/MailListPane.md) supplies the contained row/list control, and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) currently owns the alert wrapper implementations consumed by this class.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MailListDialog` | `0x00479110-0x00479d2b` | 3099-byte constructor/parser. Source-facing constructor direction is `MailListDialog(BulletinSession *, const Rect &, const unsigned char *mailListPayload)`: parses mail-list packet data from BulletinSession call sites, creates controls/list layout, constructs `MailListPane`, and installs all three dialog vtable views. |
| `SendSelectedMailReadRequest` | `0x00479d30-0x00479e1e` | 238-byte helper previously labeled `SendMailRequest`. Fetches selected row data from child/control id `7`, writes outgoing mail/bulletin opcode `0x3b`, subcommand `0x03`, list/page selector, selected mail id, and a local trailing zero, then sends length `7` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). |
| `SendSelectedMailDeleteRequests` | `0x00479e20-0x00479f3c` | No-direct-route helper pocket. Iterates selected rows from child/control id `7`, writes opcode `0x3b`, subcommand `0x05`, list id and selected mail id, sends length `6`, then interacts with dialog/session state. |
| `RemoveMailEntryByIdAndRefresh` | `0x00479f40-0x00479f82` | No-direct-route helper pocket. Finds one row by mail id through `MailListPane::FindMailIdIndex`, removes it when found, and refreshes the visible list. |
| `RemoveSelectedMailEntriesAndRefresh` | `0x00479f90-0x0047a014` | No-direct-route helper pocket. Reads selected row indices from child/control id `7`, removes selected rows with index adjustment, then refreshes the visible list. |
| `RequestInitialMailPage` | `0x0047a020-0x0047a05c` | No-direct-route wrapper. Fetches child/control id `7`, reads the pane list selector from `MailListPane + 0x14c`, chooses old/new layout offset from `byte_66DA97`/`g_useEpfAssets`, and calls the file-local page request helper with upper bound `0x7fff`. |
| `OnAction` / `HandleAction` | `0x0047a060-0x0047a1b9` | 345-byte handler. Switch/jump-table dispatcher for read, compose, reply, delete, close/back, and scroll/action-state paths; the selected-read case calls `SendSelectedMailReadRequest`, and delete setup constructs `ConfirmDeleteMailAlert`. |
| `OpenBlankComposeDialog` | `0x0047a1e0-0x0047a1f2` | No-direct-route thin wrapper around the BulletinSession/mail compose helper with null reply arguments. |
| `OpenReplyToSelectedMail` | `0x0047a200-0x0047a278` | No-direct-route helper. Fetches selected row data from child/control id `7`, copies the wide sender/name field at row `+0x006`, and opens the compose/reply dialog through the same session helper. |
| `CreateSelectedMailDeleteConfirmAlert` | `0x0047a280-0x0047a316` | No-direct-route helper. Allocates and constructs [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md), installs alert vtables through the constructor-shaped sequence, sets mode byte `1`, and routes it to the UI/session. |
| `UpdateButtonStates` | `0x0047a320-0x0047a3ac` | 140-byte helper. Enables/disables mail action buttons based on list selection. |
| `OnServerPacket` / `HandleMailListPacket` | `0x0047a3b0-0x0047a513` | 355-byte packet handler. Dispatches incoming `packet[1] == 4` to `UpdateMailList`, handles `packet[1] == 7` by opening/reusing `MailDeleteReplyAlert`, and rejects unrelated packet types. |
| `UpdateMailList` / `ApplyMailListUpdate` | `0x0047a520-0x0047a754` | 564-byte list refresh. Parses incoming list update rows, converts text, and repopulates/updates entries through `MailListPane::AddOrUpdateMailEntry`. |
| `ShowMailDeleteReplyAlert` | `0x0047a760-0x0047a894` | No-direct-route helper pocket. Converts packet text, creates or reuses [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md), and writes the mail delete-reply singleton/global alert state. |

Raw/generated-name mapping retained for source-quality migration:

| Raw/generated evidence | Preferred source-facing role | Confidence |
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

## Evidence Notes

- B007 2026-06-20 local PE/Capstone pass reconfirmed the PE image base and relevant `.text`, `.rdata`, `.data`, and `.rsrc` spans from `E:\NTK\Resources\NexusTK\NexusTK.exe`, then rechecked direct rel32 callers, dword pointer refs, adjacent boundaries, local calls, packet behavior, and current by-* docs.
- Live IDA MCP `lookup_funcs` on 2026-06-14 confirms exact function sizes for constructor `0xc1b`, request `0xee`, action `0x159`, button-state update `0x8c`, packet handler `0x163`, and list update `0x234`.
- `analyze_function 0x00479110` confirms constructor callers at `0x0047173f` and `0x00471e51` from the bulletin/mail session flow, and shows the initial base-call plus vtable stores.
- B012 2026-07-03 UID0004G7 support sync with MCP session `supervisor_20260703_reopen`: constructor caller `0x00471e51` is [UID:0004G7][0x00471dd0-0x00471e96.BulletinSessionOpenMailListDialog](by-memory/0x00471dd0-0x00471e96.BulletinSessionOpenMailListDialog.md); it allocates `0x278` bytes, passes `BulletinSession *`, `Rect` bounds, and mail-list payload into this constructor, pushes the constructed dialog through `DialogSession::PushDialog`, then consumes the 16-bit returned dialog/list id at `MailListDialog +0x274` by storing it into `BulletinSession +0x102`. This records BulletinSession as coordinator/caller only and does not move concrete dialog ownership away from [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- `trace_data_flow backward` from vtable heads `0x00614238`, `0x0061429c`, and `0x006142cc` confirms constructor stores at `0x0047916d`, `0x00479173`, and `0x0047917d`; these match [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md).
- B006's 2026-06-27 source-quality implementation records that this class consumes [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) through the secondary view at `0x0061429c + 0x10`: slot `0x006142ac` stores `0x00472040`. This is one mail-side consumer slot of the shared command-`'1'` secondary bridge, not a MailListDialog-owned method body and not a reason to move ownership away from [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- `analyze_component` confirms the local call graph edges `OnAction -> SendSelectedMailReadRequest` and `OnServerPacket -> UpdateMailList`, which keeps packet dispatch and list refresh behavior inside the `MailListDialog` class rather than generic networking.
- `analyze_function 0x00479d30` confirms the read-mail request helper pulls the selected row through the list child, serializes the selected mail/list ids, sends through `sub_574BB0(dword_67A7EC, ..., 7)`, and may return to the bulletin session stack when the modal flag at `this + 0x270` is set.
- `analyze_function 0x0047a3b0` confirms the server-packet handler branches on packet byte `a2 + 1`: value `4` updates the mail list, value `7` builds or reuses a `MailDeleteReplyAlert`, and other values return false.
- Direct local PE callers were found for the constructor (`0x0047173f`, `0x00471e51`), selected-read helper (`0x0047a0a3`), list update helper (`0x0047a4f0`), MailListPane constructor (`0x00479273`, `0x00479815`), MailListPane add/update helper (`0x00479406`, `0x004799a8`, `0x0047a70e`), MailListPane selection-count path (`0x0047adc8`, `0x0047ae1c`), MailListPane find/remove helper (`0x00479f61`, `0x0047a96d`, `0x0047ab79`, `0x0047c4e2`, `0x0047e7f9`), and shared page request helper (`0x0047a056`, `0x0047ac21`, `0x0047ac7a`, `0x0047d812`, `0x0047e0e1`).
- No direct `call rel32` callers or dword pointer refs were found in the local scan for helper starts `0x00479e20`, `0x00479f40`, `0x00479f90`, `0x0047a020`, `0x0047a1e0`, `0x0047a200`, `0x0047a280`, and `0x0047a760`. These are aligned, source-shaped helper pockets with coherent adjacent behavior, so the negative route scan caps confidence instead of deleting them from the source model.
- B002 2026-06-19 MailListPane reanalysis confirms this dialog's parser/setup paths feed [UID:00007M][MailListPane](by-class/MailListPane.md) through `MailListPane::AddOrUpdateMailEntry`, whose row layout is `0x406` bytes with `mailId`, `unreadFlag`, `month`, `day`, `sender[256]`, and `subject[256]`.
- The same pass confirms MailListPane's `0x0047ae30` vtable helper should be named as selected-mail request/open behavior rather than pure `GetSelectedMailId`: it performs virtual owner lookups and tail-calls this class's selected-read request helper at `0x00479d30`.
- The shared page-request helper `0x0047b080` is file-local to `MailDialogs.cpp`. It is used by MailListDialog/MailListPane/MailDialog/NewMailDialog family paths, including initial/older page requests and transfer-reply contexts, so this class may call or neighbor it without owning the helper exclusively.
- This dialog owns mail UI flow and packet dispatch decisions, not the generic packet serializer.

## Child Control And Row Dependencies

`MailListDialog` owns/uses a contained `MailListPane` as child/control id `7`. Do not model this as direct inheritance or as a proven `this + 0x1fc == MailListPane *` field. Current evidence supports an inherited child/control collection or lookup surface, with exact project API names still pending.

The dependent row record belongs primarily to [UID:00007M][MailListPane](by-class/MailListPane.md), but this class depends on its fields when opening, deleting, replying to, and updating selected mail:

```cpp
struct MailListEntryRow {
    unsigned short mailId;       // +0x000
    unsigned char unreadFlag;    // +0x002
    unsigned char month;         // +0x003
    unsigned char day;           // +0x004
    unsigned char pad_005;       // +0x005
    wchar_t sender[256];         // +0x006
    wchar_t subject[256];        // +0x206
};                               // sizeof == 0x406
```

`sender` is preferred over `fromName` because reply-to-selected behavior copies the first wide text field at row `+0x006`. `subject` is preferred over `title` for the second wide text field at row `+0x206` because the received-mail UI domain and draw column behavior fit mail subjects. `unreadFlag` is preferred over `readFlag` because display/action behavior treats nonzero as unread/new-mail state.

MailListPane fields used by this dialog:

| Offset | Preferred name | Notes |
| --- | --- | --- |
| `+0x14c` | `m_mailListId` / local legacy alias `m_mailType` | Serialized into read, delete, and page-request packets as the mailbox/list selector. `m_mailListId` is the preferred prose name for this dialog; existing pane draft C++ still uses `m_mailType` to avoid churn. |
| `+0x14e` | `m_pageRequestPending` | Guard for lazy page requests in the pane. |

## Packet Semantics

`MailListDialog` and the neighboring pane/helper code use the shared mail/bulletin opcode family `0x3b`. For this target, name subcommands by observed behavior rather than forcing a broader protocol owner:

| Packet role | Opcode/subcommand | Source-facing helper |
| --- | --- | --- |
| List page request | `0x3b`, `0x02`, list id, upper-bound mail id, layout offset, length `7` | File-local `SendMailListPageRequest(...)` at `0x0047b080`; not a `MailListDialog` member. |
| Selected mail read/open request | `0x3b`, `0x03`, list id/page selector, selected mail id, local trailing zero, send length `7` | `MailListDialog::SendSelectedMailReadRequest()` at `0x00479d30`. |
| Selected mail delete request | `0x3b`, `0x05`, list id, selected mail id, send length `6` | `MailListDialog::SendSelectedMailDeleteRequests()` and delete-confirm flow. |

Incoming `OnServerPacket` dispatches on `packet[1]`:

- `4`: list-update packet, calls `UpdateMailList` / `ApplyMailListUpdate`.
- `7`: delete-reply/result text packet, opens or reuses `MailDeleteReplyAlert`; source-facing name for the no-direct helper is `ShowMailDeleteReplyAlert` or `HandleDeleteReplyPacket`, not a generic server-alert handler.

`byte_66DA97` is strongly a layout/asset mode flag equivalent to current prose name `g_useEpfAssets`; it chooses layout offset `-20` for current/EPF layout and `-16` for the older layout. The exact source symbol remains inferred.

## Source Placement And Rejected Alternatives

- Keep owner/emitter [UID:0000KZ][MailDialogs](by-file/MailDialogs.md). The contiguous MailDialogs child split, shared file-local helper `0x0047b080`, and core mail vtable grouping make `NexusTK/ui/dialogs/MailDialogs.cpp` the best current source route.
- Reject [UID:0000HX][BulletinSession](by-file/BulletinSession.md) as owner: it constructs this dialog at `0x0047173f` and `0x00471e51` as a coordinator but does not own the concrete dialog implementation.
- Reject [UID:00007M][MailListPane](by-class/MailListPane.md) and generic [UID:0000KT][ListPane](by-file/ListPane.md) ownership: those pages own list control behavior, while this class owns mail-specific packet/action behavior.
- Reject [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) for this class: alert wrappers are dependencies/consumers, not the list dialog owner.
- A separate `MailListDialog.cpp` remains possible, but current evidence favors a compact `MailDialogs.cpp` cluster with `MailListDialog`, `MailListPane`, `MailDialog`, and `NewMailDialog`.

## Alert Dependencies

`MailListDialog` constructs or routes mail-specific alerts but does not currently own their implementation pages:

- [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md): created from delete-action paths, including the no-direct `CreateSelectedMailDeleteConfirmAlert` helper; list-dialog mode byte is `1`.
- [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md): created or reused from incoming delete-reply/result packet handling; singleton storage remains `g_pMailDeleteReplyAlert`.

Current owner bucket [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) remains valid because the alert wrappers form a board/mail alert family with exact child pages and vtable/global evidence. If later source-file evidence proves the mail-only alert wrappers were private to `MailDialogs.cpp`, move the alert pages in a focused source-split pass rather than by locality alone.

## No-Direct-Route Helper Pockets

The following helper starts were checked for direct rel32 callers and dword pointer refs in the local PE pass and found no simple route to their starts:

```text
0x00479e20 SendSelectedMailDeleteRequests
0x00479f40 RemoveMailEntryByIdAndRefresh
0x00479f90 RemoveSelectedMailEntriesAndRefresh
0x0047a020 RequestInitialMailPage
0x0047a1e0 OpenBlankComposeDialog
0x0047a200 OpenReplyToSelectedMail
0x0047a280 CreateSelectedMailDeleteConfirmAlert
0x0047a760 ShowMailDeleteReplyAlert
```

Each pocket is aligned and source-shaped, sits inside the exact [UID:0003PU][0x00479110-0x0047a894.MailListDialogCore](by-memory/0x00479110-0x0047a894.MailListDialogCore.md) range, and operates on the same mail-list, action, packet, or alert state. Keep them documented as retained helper pockets. Do not discard them as padding, compiler residue, or unreachable code unless a later IDA/source pass proves the route impossible.

## Reconstruction Notes

- This class is reconstructable because all fourteen source-shaped bodies, constructor callers, three vtable stores, packet roles, list-row dependencies, alert consumers, and the direct MailDialogs owner route are closed by current whole-file evidence.
- Formal H now carries the complete class declaration. Formal CPP contains `[[CHILDREN]]` only; exact method bodies belong to [UID:0003PU][0x00479110-0x0047a894.MailListDialogCore](by-memory/0x00479110-0x0047a894.MailListDialogCore.md), while row/list behavior belongs to [UID:0003PV][0x0047a8a0-0x0047b21f.MailListPaneCore](by-memory/0x0047a8a0-0x0047b21f.MailListPaneCore.md). Alert wrapper implementations remain under [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- Historical deferral based on no-direct-route helpers and unresolved inherited API spellings is superseded. Complete aligned bodies remain source-bearing even when direct xrefs are absent; high-probability human source names are used instead of IDA artifacts, with lexical uncertainty retained in the score rationale.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `94` | The page records the complete fourteen-body inventory, exact constructor callers, three-view vtable stores, selected-read/delete packet semantics, incoming list-update/delete-reply dispatch, child-control id `7`, MailListPane row/layout dependency, retained helper bodies, alert dependencies, complete formal H, and direct [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) owner route. |
| Confidence `93` | Current whole-file evidence agrees on every body, range, packet/list role, vtable route, dependency boundary, and source placement. The remaining cap is exact historical lexical spelling for inferred helper/member APIs, not behavior or ownership. |

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:00007M][MailListPane](by-class/MailListPane.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)
- [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md)
- [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)

## Changes

- 2026-08-11 Agent-B002 UID0000KZ whole-file implementation callback:
  - Raised `88/88` to `94/93`, added the complete formal H declaration, and routed formal CPP through `[[CHILDREN]]` to the fourteen-body [UID:0003PU][0x00479110-0x0047a894.MailListDialogCore](by-memory/0x00479110-0x0047a894.MailListDialogCore.md) child.
  - Reconciled the corrected [UID:0003PV][0x0047a8a0-0x0047b21f.MailListPaneCore](by-memory/0x0047a8a0-0x0047b21f.MailListPaneCore.md) end address `0x0047b21f`, retained all zero-direct-xref bodies as source-bearing evidence, and historicalized the prior blank-C++/investigate-later disposition.
  - Preserved MailDialogs ownership, BulletinSession/DialogSession coordination boundaries, and BulletinReplyAlerts implementation ownership.

- 2026-06-27 B006 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync:
  - Score and owner/emitter unchanged at `88/88`, [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), and `EMITTER_UIDS:0000KZ`.
  - Added the secondary `0x0061429c + 0x10 -> 0x006142ac -> 0x00472040` consumer-slot note, preserving class-level C++ blankness and MailDialogs ownership for mail-specific behavior only.
- 2026-07-03 B012 UID0004G7 support sync:
  - Score and owner/emitter unchanged.
  - Added source-facing constructor direction from the BulletinSession mail-list opener and documented that `MailListDialog +0x274` is the returned dialog/list id consumed by `BulletinSession +0x102`.
- 2026-06-20 supervisor-worker Rule 26 incorporation of B007 `00007L-MailListDialog-class-source-quality.md`:
  - Changed score from `85/86` to `88/88`.
  - Renamed/annotated `SendMailRequest` as `SendSelectedMailReadRequest`, added retained no-direct-route helper pockets for selected delete, remove-by-id, remove-selected, initial page request, compose/reply wrappers, delete-confirm construction, and delete-reply alert display.
  - Added child/control id `7`, `MailListEntryRow`, `m_mailListId`/`m_mailType`, `m_pageRequestPending`, outgoing opcode `0x3b` subcommands `0x02`/`0x03`/`0x05`, incoming packet `4` and `7`, file-local `SendMailListPageRequest`, alert dependency placement, source-owner rejections, raw-name mapping, and class-level C++ deferral rationale.
  - Evidence: B007 local PE/Capstone direct-caller and negative-route scans plus existing live IDA/by-* evidence for constructor callers, vtable stores, list-pane construction/update, selected read packet send, list update, and delete-reply alert handling.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: scored `80/84`.
  - After: scored `85/86`; owner/emitter remains [UID:0000KZ][MailDialogs](by-file/MailDialogs.md); final C++ remains blank below the active `90/90+` code-entry gate.
  - Evidence: live IDA MCP `lookup_funcs`, `analyze_component`, `analyze_function`, and vtable `trace_data_flow` confirmed exact method sizes, constructor callers from `0x0047173f`/`0x00471e51`, constructor vtable stores, `OnAction -> SendMailRequest`, `OnServerPacket -> UpdateMailList`, read-request serialization behavior, and delete-reply alert packet handling.
- 2026-06-20 supervisor Rule 26 incorporation of B002 MailListPane report:
  - Added cross-class support notes for MailListPane row insertion/update semantics, selected-mail request delegation to `0x00479d30`, and shared file-local page request helper placement.
- 2026-06-05: Marked reconstructable and attached to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) because the class is `80/84` and the parent is `86/82`, satisfying the 80/80 parent gate. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x00479110`, `0x00479d30`, `0x0047a060`, `0x0047a320`, `0x0047a3b0`, and `0x0047a520`; `callers` confirms the constructor is reached from `0x0047173f` and `0x00471e51` in the mail/bulletin dialog flow.
- Completion/confidence score update: existed before as `0/0`; changed to `80/84`. Summary: the received-mail listing dialog has constructor, packet parsing, read request, actions, button state, server packet, update flow, and module ownership documented. Evidence: linked mail-dialog range, IDA-confirmed method boundaries, mail-list pane relationship, and packet dispatch notes.
