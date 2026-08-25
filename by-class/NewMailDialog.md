*** UID:000096 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "BoardDialogs.h"

class BulletinSession;
struct RectBounds;

class NewMailDialog : public BoardDialog {
public:
    NewMailDialog(BulletinSession *session, const RectBounds &bounds,
                  const wchar_t *recipient, const wchar_t *quotedText,
                  short quotedLength);
    virtual void OnCommand(int commandId, int controlId);
    virtual bool ShowSendFailureAlert(const unsigned char *packet);
    virtual void SetHoverControl(int controlId);
    virtual bool OnMailTransferReplyPacket(const unsigned char *packet);
    void RequestInitialMailPage();
    bool AppendQuotedMessage(const wchar_t *text, short length);
    bool ShowMailTransferReplyAlert(const unsigned char *packet);
    int SendMail(short commandId);

private:
    BulletinSession *m_session;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewMailDialog

## Status

- Confidence: very strong for all nine bodies, behavior, vtable routes, transfer-alert dependency, and complete formal source placement; exact historical lexical spellings remain the sub-95 cap.
- Likely source file: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md). A separate `NewMailDialog.cpp` is retained only as a historical unproven alternative.
- Address range: [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- Parent attachment: attached to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) because the mail file page, mail aggregate memory page, and this class page now meet the 80/80 attachment gate.
- Current evidence basis: UID0000KZ whole-file live-MCP and physical-body audit, with the dated 2026-06-14 session retained as historical corroboration.

## Class Purpose

`NewMailDialog` is the compose-and-send mail dialog. It lays out recipient, subject, body, and copy option controls, preloads quoted content when replying, serializes outgoing mail fields, and handles transfer-reply alerts. In the EPF mail-skin path, IDA shows it builds a local [UID:00005C][FontStyle](by-class/FontStyle.md) for the "Keep a copy" static label.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewMailDialog` | `0x0047d050-0x0047d7c1` | Builds compose dialog layout and quoted content; constructor stores vtables at `0x0047d0a1/0x0047d0a7/0x0047d0b1`. |
| `RequestInitialMailPage` | `0x0047d7d0-0x0047d817` | Retained source body; fetches child id `7`, list selector, upper id `0x7fff`, layout offset, and calls the shared page helper. |
| `OnCommand` | `0x0047d820-0x0047d881` | Handles send and cancel commands; send calls `SendMail` and closes through the session helper. |
| `ShowSendFailureAlert` | `0x0047d890-0x0047d942` | Displays transfer failure alert using the `MailTransferReplyAlert` family. |
| `SetHoverControl` | `0x0047d950-0x0047d958` | Nine-byte tail call to inherited hover-control behavior. Historical `SetDialogMode` is rejected. |
| `AppendQuotedMessage` | `0x0047d960-0x0047da11` | Prefixes quoted body lines and appends them to the editor. |
| `OnMailTransferReplyPacket` | `0x0047da20-0x0047db6a` | Parses transfer reply text and displays [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md). |
| `ShowMailTransferReplyAlert` | `0x0047db70-0x0047dca0` | Distinct modeled zero-xref helper that converts bounded text, constructs the alert, stores its mode, and returns true. |
| `SendMail` | `0x0047dcb0-0x0047e032` | Converts recipient/subject/body/copy-option fields and serializes the outgoing mail packet. |

## Class State And Layout Anchors

| Evidence | Class-level meaning |
| --- | --- |
| [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md) records `NewMailDialog` primary/secondary/tertiary vtables at `0x0061443c`, `0x006144a0`, and `0x006144d0`, with constructor stores at `0x0047d0a1`, `0x0047d0a7`, and `0x0047d0b1`. | Confirms `NewMailDialog` is a real multi-view dialog class in the mail family, not just a generated helper bucket. |
| [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md) groups `0x0047cd80-0x0047e033` as `NewMailDialog` plus send/shortcut helpers. | Places the compose dialog inside the mail-dialog aggregate and records the constructor caller from the BulletinSession reply-opening path at `0x00471440`. |
| [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) lists `NewMailDialog` as the compose-and-send dialog with recipient, subject, body, outgoing serialization, and `FontStyle` label setup. | Supports `MailDialogs.cpp` as the parent source file while leaving a later split to `NewMailDialog.cpp` possible if stronger source-layout evidence appears. |
| The constructor writes the mail-family vtables and uses [UID:00005C][FontStyle](by-class/FontStyle.md) for the EPF "Keep a copy" label path. | Identifies owned UI controls and transient style construction without naming unresolved field offsets as final source fields. |
| [UID:0003O8][0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor](by-memory/0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor.md) is now the exact raw constructor child for the transfer-reply alert displayed from `HandleMailTransferReply` and send-failure paths. | Removes the previous projected-constructor blocker from this dialog's transfer-alert dependency without moving ownership away from the compose dialog. |
| B006 2026-06-27 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync | This class consumes the shared command-`'1'` secondary bridge through the secondary view at `0x006144a0 + 0x10`: slot `0x006144b0` stores `0x00472040`. This is a consumer slot, not a NewMailDialog-owned body and not a reason to move ownership away from [UID:0000KZ][MailDialogs](by-file/MailDialogs.md). |

## Reconstruction State

- Reconstructable: true, because this is NexusTK-owned compose-dialog source behavior that must be rebuilt.
- Parent: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), not [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). The transfer alert dependency is a child/helper interaction, while the compose constructor, send flow, vtables, and BulletinSession opening path are part of the mail-dialog family.
- Formal H now contains the complete class declaration, formal CPP contains `[[CHILDREN]]`, and [UID:0003PY][0x0047d050-0x0047e033.NewMailDialogCore](by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md) carries all nine accepted method bodies. Exact original member/helper spellings remain inferred but no behavior/body/source-placement blocker is deferred.

## Evidence Notes

- 2026-06-14 live IDA MCP confirms constructor, command, transfer-reply, quote-append, and send boundaries at `0x0047d050`, `0x0047d820`, `0x0047d890`, `0x0047d950`, `0x0047d960`, `0x0047da20`, and `0x0047dcb0`.
- 2026-06-14 live IDA MCP confirms constructor stores to `0x0061443c`, `0x006144a0`, and `0x006144d0`, and the constructor caller from `sub_4713B0` at `0x00471440`.
- IDA MCP confirms raw constructor calls to `FontStyle::FontStyle` at `0x0047d0d2` and `FontStyle::Configure(128, 128, 3, 0)` at `0x0047d3fa`.
- Outgoing mail conversion helpers are shared with other text-submit flows and should not be treated as mail-owned.
- Existing mail aggregate docs record the exact compose cluster as `0x0047cd80-0x0047e033`, with `NewMailDialog` constructor at `0x0047d050-0x0047d7c1`, command handler at `0x0047d820-0x0047d882`, and send routine at `0x0047dcb0-0x0047e033`.
- The mail vtable-family page records the `NewMailDialog` vtable bases and constructor store sites, while the broader mail aggregate page records the matching vtable bases and the BulletinSession caller.
- 2026-06-14 live IDA MCP decompiles `HandleCommand` as send/cancel dispatch, `HandleMailTransferReply` as packet subcommand `6` parsing and transfer-alert construction, and `SendMail` as field extraction/sanitization plus opcode `0x3b` mail-send serialization.

## Score Rationale

Completion is `94` because the page records the complete nine-body inventory, constructor/vtable/caller anchors, exact source-owner and alert boundary, corrected hover and transfer-alert helpers, complete formal H, and child formal CPP route. Confidence is `93`: behavior, body identity, owner, and source placement are closed; exact original lexical spellings remain inferred.

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)
- [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)

## Changes

- 2026-08-11 Agent-B002 UID0000KZ whole-file implementation callback:
  - Raised `86/87` to `94/93`, installed the complete formal H declaration, and routed formal CPP through `[[CHILDREN]]` to [UID:0003PY][0x0047d050-0x0047e033.NewMailDialogCore](by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md).
  - Corrected the inventory from seven to nine bodies by adding `0x0047d7d0` and `0x0047db70`, replaced stale `SetDialogMode` with `SetHoverControl`, and historicalized the blank-C++/separate-file assumptions.
  - Preserved BulletinReplyAlerts ownership for transfer-alert implementations and compiler-only vtable/thunk consequences.

- 2026-06-27 B006 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync:
  - Score and owner/emitter unchanged at `86/87`, [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), and `EMITTER_UIDS:0000KZ`.
  - Added the secondary `0x006144a0 + 0x10 -> 0x006144b0 -> 0x00472040` consumer-slot note, preserving class-level C++ blankness and MailDialogs ownership for mail-specific compose behavior only.
- 2026-06-07 (A010): Raised completion from `74` to `80` and attached the class to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
  - Evidence added: mail-family vtable bases/store refs from [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md), compose-cluster/caller support from [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md), parent-file rationale, reconstruction-state notes, and final-C++ blockers.
  - Limitation: IDA MCP was unavailable in this session, so the update consolidates existing by-* evidence rather than adding new live disassembly.
- Before: completion/confidence metadata were `0/0` even though the page already covered dialog role, send flow, command handling, transfer replies, and module placement.
- Changed to: `COMPLETION:74` and `CONFIDENCE:84`.
- Evidence: constructor, command, failure, quoted-message, transfer-reply, and send methods are documented with IDA-backed notes; remaining gaps are exact field layout and complete body-level converted C++.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `74/84`, below the 80/80 parent-attachment gate, even though [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts at `0x0047d050`, `0x0047d820`, `0x0047d890`, `0x0047d950`, `0x0047d960`, `0x0047da20`, and `0x0047dcb0`; current `callers` confirms the constructor is referenced from `0x00471440`.
- 2026-06-14 Agent-A001 Goal 2 low-score repair:
  - Changed scores from `80/84` to `86/87`.
  - Added live IDA MCP method-boundary, vtable-store, constructor-caller, command/send, and transfer-reply evidence; linked the exact `MailTransferReplyAlert` raw constructor child [UID:0003O8][0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor](by-memory/0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor.md).
  - C++ remains blank below the active `90/90+` final-source gate.
