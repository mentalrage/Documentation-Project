*** UID:00007K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once
#include "BoardDialogs.h"

class BulletinSession;
struct RectBounds;

class MailDialog : public BoardDialog {
public:
    MailDialog(BulletinSession *session, const RectBounds &bounds,
               const unsigned char *packet);
    virtual void OnCommand(int commandId, int controlId);
    virtual bool OnKeyInput(const unsigned char *keyState);
    virtual bool OnMailDeleteReply(const unsigned char *packet);
    void SendDeleteCurrentMailRequest();
    void RefreshSelectedMailInList();
    void NavigateToAdjacentMail(bool forward);
    void OpenBlankComposeDialog();
    void SendReply();
    void CreateConfirmDeleteAlert();
    bool ShowMailDeleteReplyAlert(const unsigned char *packet);
    void SaveCurrentMailToFile();

private:
    BulletinSession *m_session;
    unsigned short m_mailListId;
    unsigned short m_currentMailId;
    wchar_t m_sender[256];
    wchar_t m_date[64];
    wchar_t m_subject[256];
    wchar_t m_body[16384];
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MailDialog

## Status

- Confidence: very strong for all thirteen core bodies, the separately bounded save/export body, mail-dialog placement, split routing, vtable/compiler disposition, and the complete formal declaration. Exact historical member/helper spellings remain the sub-95 cap.
- Likely source file: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- Address range: [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MailDialog.cpp`
- Parent routing: assigned to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md); formal CPP contains `[[CHILDREN]]`, formal H contains the complete class declaration, and method bodies route through [UID:0003PW][0x0047b220-0x0047cd79.MailDialogCore](by-memory/0x0047b220-0x0047cd79.MailDialogCore.md) plus [UID:0003PX][0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper](by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md).
- Code state: declaration and all fourteen source-shaped bodies are implementation-ready. High-probability human names are used for unavailable lexical details instead of leaving raw reverse-engineering labels.

## Class Purpose

`MailDialog` is the mail read/reply dialog. It parses a mail packet into sender/date/subject/body fields, builds read and reply UI layouts, handles navigation and delete/forward/reply commands, sends replies, coordinates single-mail delete alerts, and exposes a Ctrl+S save/export path for the current mail content.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MailDialog` | `0x0047b220-0x0047c404` | Parses mail packet and builds read/reply layouts. |
| `SendDeleteCurrentMailRequest` | `0x0047c410-0x0047c4ab` | Retained complete subcommand-`0x05` request body with zero direct xrefs. |
| `RefreshSelectedMailInList` | `0x0047c4b0-0x0047c4ff` | Finds this dialog's mail id in the list pane and reselects it before returning to the list view. |
| `OnCommand` | `0x0047c500-0x0047c710` | Handles close, send reply, confirm delete, list return, page navigation packets, and forward/base commands. |
| `OnKeyInput` / `HandleKeyInput` | `0x0047c730-0x0047c77f` | Handles Ctrl+S and calls the save/export helper at `0x0047cd80`; it is not a send/reply shortcut. |
| `NavigateToAdjacentMail` | `0x0047c780-0x0047c890` | Retained complete adjacent-row lookup/navigation request body with zero direct xrefs. |
| `OpenBlankComposeDialog` | `0x0047c8a0-0x0047c8c2` | Retained thin BulletinSession compose wrapper with null reply text. |
| `SendReply` | `0x0047c8d0-0x0047c94f` | Extracts reply text, pops dialog, and sends reply. |
| `CreateConfirmDeleteAlert` / `ShowConfirmDeleteAlert` | `0x0047c950-0x0047c9ef` | Allocates and initializes a `ConfirmDeleteMailAlert` for this read dialog. |
| `OnMailDeleteReply` / `HandleMailDeleteReply` | `0x0047c9f0-0x0047cb3f` | Handles the mail-delete reply callback, inline-constructs/uses [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md) with `m_deleteAllReplies = false`, publishes `g_pMailDeleteReplyAlert`, and relies on the alert's single-reply branch to update the previous dialog and pop the current session view. |
| `ShowMailDeleteReplyAlert` | `0x0047cb40-0x0047cc73` | Converts a packet payload to wide text, inline-constructs/uses [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md) with `m_deleteAllReplies = false`, and publishes/uses the singleton. |
| file-local `SendMailNavigationRequest` | `0x0047cc80-0x0047cd0d` | Retained complete navigation packet body; zero direct xrefs, not padding. |
| file-local `SendMailDeleteRequest` | `0x0047cd10-0x0047cd77` | Retained complete delete packet body; zero direct xrefs, not padding. |
| `SaveCurrentMailToFile` | [UID:0003PX][0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper](by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md) `0x0047cd80-0x0047d049` | Sole Ctrl+S save/export body with exact path, headings, file write, close, and success behavior. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks; ignore for handwritten source. |
| scalar deleting destructor wrapper | [UID:0003Q7][0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor](by-memory/0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor.md) | Compiler-generated ABI glue; do not hand-port as source C++. |

## Evidence Notes

- IDA MCP on 2026-06-08 historically confirmed the compact eight-modeled-function set. Current UID0000KZ live-MCP/physical audit expands the source-shaped core to thirteen through `0x0047cd77`, plus separately owned `SaveCurrentMailToFile` at `0x0047cd80-0x0047d049`.
- Constructor callers are still the BulletinSession mail-open paths at `0x004717f6` and `0x00471f71`, tying the class to the mail-dialog flow rather than a generic alert or session helper.
- The constructor writes all three `MailDialog` vtable views: primary `0x0061439c` at `0x0047b287`, secondary `0x00614400` at `0x0047b28d`, and tertiary `0x00614430` at `0x0047b297`.
- B006's 2026-06-27 source-quality implementation records that this class consumes [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) through the secondary view at `0x00614400 + 0x10`: slot `0x00614410` stores `0x00472040`. This is one mail-side consumer slot of the shared command-`'1'` secondary bridge, not a MailDialog-owned method body and not a reason to move ownership away from [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- B006 2026-06-20 source-quality reanalysis rechecked the current docs plus a direct read-only PE scan of `NexusTK.exe` (`MD5 4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`). IDA MCP was not reachable in that session, so the B006 additions are grounded in current docs plus direct binary call/ref/string checks rather than fresh Hex-Rays output.
- Direct PE facts confirmed constructor calls at `0x004717f6` and `0x00471f71`, `SendReply` call at `0x0047c67e`, the sole save-helper call at `0x0047c765`, `OnCommand` vtable/data ref `0x006143e4`, `OnKeyInput` vtable/data ref `0x00614408`, `OnMailDeleteReply` vtable/data ref `0x006143f8`, and scalar-wrapper calls at `0x0047e921`/`0x0047e92c` plus vtable/data ref `0x0061439c`.
- `OnCommand` switch case evidence ties command `2` to `SendReply` at `0x0047c67e`, command `3` to `ConfirmDeleteMailAlert` vtable stores at `0x0047c6c5/0x0047c6cb/0x0047c6d5`, and commands `5`/`7` to opcode `0x3b` page-navigation packet construction. Source-facing packet names remain descriptive: `kBulletinMailOpcode` / `kMailDialogOpcode` for opcode `0x3b`, `SendMailListPageRequest` for page-navigation sends, and `RequestSelectedMail` / `OpenSelectedMail` for the mail-list selected-content request behavior.
- `OnKeyInput` handles Ctrl+S by calling `0x0047cd80-0x0047d04a`; B006 resolves the stale wording by naming that child [UID:0003PX][0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper](by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md) as the source-facing `SaveCurrentMailToFile` save/export helper. It is not a send/reply shortcut, not a `NewMailDialog` compose helper, and not a generic file utility owner.
- `OnMailDeleteReply` and `ShowDeleteReplyAlert` both convert packet payloads into wide text, install `MailDeleteReplyAlert` vtables at `0x0061476c/0x006147d4/0x00614804`, set the alert's `m_deleteAllReplies` byte at `+0x270` to false, and publish singleton slot `0x0067adbc`.
- B009 2026-06-19 MailDeleteReplyAlert reanalysis pins the false-mode inline construction sites at `0x0047caf7/0x0047cafd/0x0047cb07` and `0x0047cc2d/0x0047cc33/0x0047cc3d`. The resulting alert action uses this dialog's `m_dialogSession` at `+0x270` to call `DialogSession::FindPreviousDialog`, reads this dialog's `m_currentReplyId` at `+0x274`, removes the matching row from the previous dialog's reply list through `MailListPane::FindMailIdIndex` and `ListPane::RemoveItems`, refreshes the previous dialog through vtable slot `+0x4c`, then calls `DialogSession::PopCurrentDialog(false)`.
- Direct string facts from the B006 PE scan include `From :` at `0x00610d88`, `Delete` at `0x00612588`, `Cancel` at `0x00614cbc`, `%5d` at `0x006148d0`, and `%2d/%2d` at `0x006148d8`. Earlier docs cite `Date :` and `Subject :` for the save/export path, but B006 did not use those two strings as fresh proof because its direct UTF-16 scan did not find exact matches.
- Boundary samples show `0xcc` padding at `0x0047c405-0x0047c4b0`, `0x0047c94b-0x0047c950`, `0x0047c9e6-0x0047c9f0`, `0x0047cb3e-0x0047cb40`, and `0x0047cc74` before the following `0x0047cd80` helper.

## Class State / Layout Inferences

| Storage | Current source-facing name | Evidence and caveat |
| --- | --- | --- |
| inherited/dialog control infrastructure around `+0x1fc` | child/control collection; reply-list id `kReplyListControlId = 7` | Mail delete-reply handling and ListPane support show child id `7` is the reply-list interaction target. Treat this as inherited/control infrastructure, not a new MailDialog-owned field. |
| `MailDialog+0x270` | `m_session` | Mail delete-reply handling treats this as the owning/current BulletinSession/dialog-session context. Historical `m_dialogSession` remains a superseded descriptive alias. |
| `MailDialog+0x274` | `m_currentMailId` | Used as the 16-bit current mail id in the single-reply delete/update path. Historical `m_currentReplyId`/`m_selectedReplyId` spellings remain earlier descriptive aliases. |
| `0x0067adbc` | `g_pMailDeleteReplyAlert` | Existing global/class docs establish this as the mail delete-reply alert singleton. |

Constructor-local sender/date/subject/body fields are represented in formal H with project-consistent source names. Exact original lexical spellings remain inferred, but current formal CPP/H preserves the observed field roles and behavior without IDA artifacts.

## Source Placement And Rejected Alternatives

The owner/emitter stays [UID:0000KZ][MailDialogs](by-file/MailDialogs.md). Constructor callers, the three MailDialog vtable stores, command/key/reply/delete behavior, and the `SaveCurrentMailToFile` helper all fit the mail read/reply dialog class.

Rejected alternatives:

- [UID:0000HX][BulletinSession](by-file/BulletinSession.md): caller/session coordinator only. It constructs and stacks mail dialogs but does not own the class methods.
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md): current owner bucket for the mail alert wrappers, not the main read/reply dialog class.
- [UID:00007L][MailListDialog](by-class/MailListDialog.md) / [UID:00007M][MailListPane](by-class/MailListPane.md): adjacent list UI and selected-mail request helpers, not owners of read/reply dialog internals.
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md): compose-dialog sibling; no evidence that it owns the read/reply dialog or Ctrl+S save/export helper.
- Generic file/export utility owner for `0x0047cd80`: rejected because the helper has a sole MailDialog key-handler caller and formats current mail fields.
- Moving mail-only alert classes into `MailDialogs` in this pass: plausible as a future physical-source hypothesis, but current alert class/global/vtable routing is stronger through [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). Document MailDialog as an inline construction/use site, not as the current owner of alert class implementations.

## Child Page And C++ Policy

- [UID:0003PW][0x0047b220-0x0047cd79.MailDialogCore](by-memory/0x0047b220-0x0047cd79.MailDialogCore.md) carries the accepted thirteen-body core formal CPP.
- [UID:0003PX][0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper](by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md) carries the accepted exact `SaveCurrentMailToFile` formal CPP.
- [UID:0003Q7][0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor](by-memory/0x0047ebf0-0x0047ec2b.MailDialogScalarDeletingDestructor.md) remains non-emitting compiler ABI glue.
- The class formal H channel carries the complete declaration; its CPP channel contains only `[[CHILDREN]]`. Compiler vtable writes, thunks, and the scalar deleting wrapper remain no-code consequences.

## Assignment Gate

Direct parent assignment is closed at `94/93`. Current whole-file evidence resolves the complete core/save inventory, owner/emitter route, formal H/CPP split, packet/alert behavior, and compiler-only exclusions. Remaining uncertainty is lexical only.

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md)
- [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md)
- [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)

## Changes

- 2026-08-11 Agent-B002 UID0000KZ whole-file implementation callback:
  - Raised `87/88` to `94/93`, installed the complete formal H declaration, and routed formal CPP through `[[CHILDREN]]` to the thirteen-body core and one-body save/export children.
  - Corrected the core endpoint to `0x0047cd79`, added retained delete/navigation/compose/request bodies, normalized active member names, and historicalized the compact eight-function/blank-C++ assumptions.
  - Preserved BulletinSession/DialogSession coordination, BulletinReplyAlerts implementation ownership, and compiler-only scalar/thunk disposition.

- 2026-06-27 B006 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync:
  - Score and owner/emitter unchanged at `87/88`, [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), and `EMITTER_UIDS:0000KZ`.
  - Added the secondary `0x00614400 + 0x10 -> 0x00614410 -> 0x00472040` consumer-slot note, preserving class-level C++ blankness and MailDialogs ownership for mail-specific behavior only.
- 2026-06-21 supervisor-worker Rule 26 incorporation of B009 `00007J-MailDeleteReplyAlert-class-source-quality.md`: no score change. Added exact false-mode inline construction sites for `MailDeleteReplyAlert`, clarified `m_deleteAllReplies = false` in `OnMailDeleteReply` / `ShowDeleteReplyAlert`, and documented the alert-side previous-dialog update plus session pop behavior using `m_dialogSession` and `m_currentReplyId`.
- 2026-06-20 supervisor Rule 26 incorporation of B006 MailDialog source-quality report:
  - Changed score from `85/86` to `87/88`, owner/emitter unchanged through [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
  - Corrected the stale Ctrl+S wording: `OnKeyInput` calls [UID:0003PX][0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper](by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md) as a `SaveCurrentMailToFile` save/export helper, not a send/reply shortcut.
  - Added direct PE caller/ref/string evidence, high-probability `m_dialogSession`, `m_currentReplyId`, reply-list child id `7`, packet/helper naming notes, rejected owner/name alternatives, current mail-alert ownership policy, and child-page C++ routing.
  - Replaced the stale numeric "95/95 emission bar" rationale with an explicit no-code proof: class-level C++ remains blank until constructor control fields, text-control offsets, inherited subobject declarations, and packet/session helper prototypes are source-quality.
- 2026-06-08 A009 Batch 136:
  - Changed score from `78/82` to `85/86`.
  - Set `AUTOGEN_PARENT_UID:0000KZ` because this page and the direct [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) parent now both satisfy the corrected `85/85` gate.
  - Added live IDA MCP evidence for all eight `MailDialog` core functions in `0x0047b220-0x0047cc74`, constructor callers, three vtable stores, command-handler packet/delete/reply cases, `ConfirmDeleteMailAlert` and `MailDeleteReplyAlert` vtable stores, singleton publication, padding boundaries, and the `0x0047cd80` Ctrl+S helper split caveat.
  - Final C++ remains blank because source-quality field names, complete control/member declarations, and the helper split around `0x0047cd80` are still unresolved.
- 2026-06-05: Marked reconstructable because live IDA MCP confirms the mail read/reply dialog constructor, command, shortcut, reply-send, delete-reply, and destructor functions are NexusTK-owned UI/mail behavior. Kept `AUTOGEN_PARENT_UID` blank because this class is `78/82`, below the 80/80 parent-attachment gate, even though [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) is the likely owner. Live IDA MCP evidence: `lookup_funcs` confirms starts at `0x0047b220`, `0x0047c500`, `0x0047c730`, `0x0047c8d0`, `0x0047c9f0`, and `0x0047ebf0`; `callers` confirms constructor calls from `0x004717f6` and `0x00471f71`, and `SendReply` called from `0x0047c67e` inside `sub_47C500`.
- Completion/confidence score update: existed before as `0/0`; changed to `78/82`. Summary: the mail read/reply dialog has core parse/build, command, shortcut, reply send, delete-reply, destructor, and module-placement documentation, but unresolved helper cleanup keeps it below high completion. Evidence: linked mail dialog memory range, method address table, IDA-confirmed boundaries, and Ctrl+S helper caveat.
