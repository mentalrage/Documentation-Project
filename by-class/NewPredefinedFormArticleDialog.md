*** UID:000098 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "NewPredefinedFormArticleDialog.h"

#include <windows.h>
#include <cstring>
#include <cwchar>

#include "BulletinSession.h"
#include "DialogControls.h"
#include "PacketBuffer.h"
#include "ScreenDimmer.h"
#include "TransferReplyPredefinedAlert.h"

static int __stdcall DeserializePredefinedFormArticleEntries(
    const unsigned char *serializedForm,
    PredefinedFormArticleEntry *entries,
    unsigned short *outVisibleRowCount,
    unsigned short *outEntryCount);

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "BulletinDialog.h"

class DialogSession;
struct RectBounds;

struct PredefinedFormArticleEntry
{
    unsigned char titleLength;
    wchar_t title[256];
    bool usesUserImagePane;
    unsigned char textLineCount;
    unsigned char bodyLength;
    wchar_t body[256];
    int rowAdvanceMode;
};

class NewPredefinedFormArticleDialog : public BulletinDialog
{
public:
    NewPredefinedFormArticleDialog(DialogSession *session,
        const wchar_t *previousSubject,
        RectBounds *bounds,
        const unsigned char *formPacket);

    virtual void OnPaint();
    virtual void OnCommand(int commandId, int commandParam);
    virtual void SetHoverControl(int controlId);
    virtual bool HandleTransferReplyPredefinedAlert(
        const unsigned char *packet);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void NavigateToPreviousArticleSelection();
    bool HandleTransferReplyPredefinedAlertPayload(
        const unsigned char *payload);
    void SubmitArticle(unsigned short boardId);

    unsigned short m_predefinedFormEntryCount;
    unsigned short m_visibleFormRowCount;
    PredefinedFormArticleEntry m_predefinedFormEntries[20];
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewPredefinedFormArticleDialog

## Status

- Confidence: strong for behavior, exact child split, vtable/negative-reachability audits, dedicated file-parent attachment, [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md)'s source-ready retained navigation method, [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md)'s source-ready `OnCommand` / `HandleButtonClick` command handler, [UID:0002UL][0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle](by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md)'s source-ready submit method, [UID:0002UM][0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer](by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md)'s source-ready event handler, [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md)'s source-ready parser helper, and [UID:0002UQ][0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert](by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md)'s source-ready transfer-reply alert packet handler; medium for broader constructor/control/helper names and class-level final C++.
- Likely source file: [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md). [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) remains the broader board/article grouping anchor.
- Address range: [UID:0000ZL][0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md), with destructor companions at [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) and [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_NewPredefinedFormArticleDialog.cpp`

## Class Purpose

`NewPredefinedFormArticleDialog` composes bulletin-board articles from server-provided predefined form rows. It parses a serialized form definition, creates a variable-height dialog with subject and row-specific edit controls, supports a free-text predefined mode, posts article data, and handles transfer-reply alert packets.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewPredefinedFormArticleDialog` | [UID:0002UJ][0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor](by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md) | Reconstructable but intentionally non-emitting constructor at `88/91`. B005's 2026-07-04 MCP-backed callback clears the old blank class emitter, keeps formal C++ blank, and records session `73c77998` evidence for exact size `0xa45` / 2629, sole caller/allocation/argument roles, vtable writes, parser calls, dynamic-control/helper flow, type/struct negative checks, boundary padding, and the generated empty-emitter defect. |
| `NavigateToPreviousArticleSelection` | [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md) | Function-shaped retained class helper between constructor and button handler. B002's 2026-06-25 MCP-backed recheck resolves the source-facing name and first-draft child C++: `m_session->FindPreviousDialog(this)`, previous-dialog control id `7`, selected article/list value, `g_useEpfAssets` layout offset, and shared `SendArticleNavigationRequest(..., 0x7fff, ...)`. No caller/vtable/VA/RVA pointer route remains, but that is a route caveat rather than a child C++ blocker. |
| `OnCommand` / `HandleButtonClick` | [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md) | Source-ready command handler. B002's 2026-06-26 MCP-backed implementation raises the child to `90/91` and emits formal `void NewPredefinedFormArticleDialog::OnCommand(int commandId, int)` C++: command `0` reads the inherited session at `this+0x270`, submits the selected/current board id from `session+0x102` through `SubmitArticle`, restores `g_pUserPane->m_activeDialogHostPane`, and calls `CreateScreenDimmer()`; command `1` calls `DialogSession::PopCurrentDialog(false)` when a session exists. |
| `HandleEvent` | [UID:0002UM][0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer](by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md) | Source-ready virtual event handler. B005's 2026-06-25 MCP-backed implementation raises the child to `90/92` and emits formal `bool NewPredefinedFormArticleDialog::HandleEvent(void *eventBlock, int, int)` C++: it always returns handled, releases active ScreenDimmer state on the null-event path, and creates `TransferReplyPredefinedAlert` with the fixed post-error message. |
| `SetHoverControl` | [UID:0002UN][0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl](by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md) | Source-ready hover-control forwarder. B012's 2026-07-05 MCP-backed implementation raises the child to `90/92` and emits formal `void NewPredefinedFormArticleDialog::SetHoverControl(int controlId)` C++ that forwards to inherited `DialogPane::SetHoverControl(controlId)`. |
| `OnPaint` | [UID:0002UO][0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint](by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md) | Source-ready virtual paint method. B005's 2026-06-25 MCP-backed pass raises the child to `90/92` and emits formal first-draft `NewPredefinedFormArticleDialog::OnPaint()` C++ for the current/legacy `DLGBBS08` header, repeated-row, and footer chrome selected by `g_useEpfAssets`; the vtable-only route is a confidence cap, not a child blank-C++ blocker. |
| `DeserializePredefinedFormArticleEntries` | [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md) | Source-ready file-local parser helper used only by constructor call sites; B014's 2026-07-03 MCP-backed callback raises the child to `90/92` and emits formal first-draft C++ with inferred `PredefinedFormArticleEntry` records, `0x40c` stride, explicit reserved fields, `empty` handling through `g_emptyWideString` / raw `word_60DB20`, skipped title delimiter preservation, and dword `rowAdvanceMode`. |
| `HandleTransferReplyPredefinedAlert` | [UID:0002UQ][0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert](by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md) | Source-ready virtual packet handler emitted through this class. B006's 2026-07-04 callback raises the child to `90/91` and emits formal `bool NewPredefinedFormArticleDialog::HandleTransferReplyPredefinedAlert(const unsigned char *packet)` C++: live vtable slot `0x006140ac -> 0x00478940`, subcommand `0x06`, `packet[2]` reply byte, `packet[3]` message length, `packet+4` text, 256-byte narrow/wide conversion through `MultiByteToWideChar(CP_ACP, 0, ...)`, ScreenDimmer release, `TransferReplyPredefinedAlert` allocation/vtable stores, and `+0x270` reply-byte storage. |
| unreferenced transfer-reply helper | [UID:0002UR][0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload](by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload.md) | Retained alternate packet-layout helper with no IDA code/data xrefs, raw VA/RVA pointer references, or vtable slot after B001-030 and C001-008; assigned to this class for ownership now that the direct class/file chain clears the strict gate, but still needs a separate source-emission decision. |
| `SubmitArticle` | [UID:0002UL][0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle](by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md) | Source-ready submit method. B014's 2026-06-26 MCP-backed implementation raises the child to `90/91` and emits formal `void NewPredefinedFormArticleDialog::SubmitArticle(short boardId)` C++: reads subject control `3`, reads free-text body control `4` or parsed-row label/value control pairs, serializes opcode `0x3b` / subcommand `4`, board id, subject/body ANSI payloads, queues through `g_packetSender`, and starts the 15000 ms post-send wait. |
| adjustor thunks | [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) | Compiler-generated vtable thunks forwarding to the scalar deleting destructor; ignore for handwritten source. |
| scalar deleting destructor | [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) | Compiler-generated deleting wrapper over ordinary/default class destruction. It calls `DialogInSession` cleanup at `0x004a1450`, conditionally calls `OperatorDeleteWrapper`, and has a `flags & 4` guard/no-op path through `0x0041b6a0`; source should model the class destructor normally and let MSVC regenerate this wrapper. |

## Layout Notes

- Entry counts are stored around `this + 0x274`.
- Parsed `PredefinedFormArticleEntry` records begin around `this + 0x278`.
- Each parsed entry has a `0x40c` byte stride:
  - title length and wide title text
  - `usesUserImagePane` flag
  - text-line count
  - body length and wide body text
  - extra row-advance flag
- Non-free-text mode creates two controls per row after the subject controls. Free-text predefined mode uses one large body edit control.

## Evidence Notes

- IDA MCP confirms all active method starts and the two excluded destructor thunks.
- `DeserializePredefinedFormArticleEntries_478650` is only called from the constructor and should migrate with this class/file route as a source-ready file-local helper.
- The dedicated file parent [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) is scored `88/85`, and the aggregate/child memory pages attach to the same file parent with exact boundaries, padding, parser call edges, vtable xrefs, and submit-call evidence. This satisfies the strict `85/85` parent-chain gate for this class while leaving final C++ blank.
- B006's 2026-06-27 source-quality implementation records that this class consumes [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) through the secondary view at `0x006140b4 + 0x10`: slot `0x006140c4` stores `0x00472040`. This is one consumer slot of the shared command-`'1'` secondary bridge, not a NewPredefinedFormArticleDialog-owned method body and not a reason to move this class away from [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md); class-level C++ remains blank for broader constructor dynamic-control names and retained-helper policy, not because UID0002UQ is still unresolved.
- B006's 2026-07-04 UID0002UQ implementation sync resolves the live transfer-reply alert packet handler as source-ready at `90/91`. Fresh MCP session `73c77998` confirms `sub_478940` size `0x153` / 339 bytes, exact range `0x00478940-0x00478a93`, thirteen-byte `0xcc` padding before and after, terminal `retn 4`, vtable/data route `0x006140ac -> 0x00478940`, zero code xrefs, unique VA pointer-pattern hit only at `0x006140ac`, no RVA hit, packet layout `packet[1] == 0x06` / `packet[2]` reply byte / `packet[3]` length / `packet+4` text, 256-byte narrow and wide buffers, ScreenDimmer helper pair, shared OK label `0x00613a18`, operator-new wrapper `0x004f4aa0`, `AlertPane::AlertPane` `0x0049feb0`, `TransferReplyPredefinedAlert` vtable stores `0x00614194`/`0x006141fc`/`0x0061422c`, and reply-byte store at `+0x270`. UID0002UR remains a separate no-route retained helper and is not a UID0002UQ source blocker.
- B012's 2026-07-05 UID0002UN implementation sync resolves the hover-control vtable forwarder as source-ready at `90/92`. Current MCP session `supervisor_recovery_20260705` confirms `sub_478370` size `0x9`, exact range `0x00478370-0x00478379`, no function at `0x00478379`, `0xcc` padding before/after, the sole vtable data xref `0x006140a8 -> 0x00478370`, vtable slot bytes `70 83 47 00`, wrapper body `push ebp; mov ebp, esp; pop ebp; jmp sub_49FC00`, and decompile `sub_49FC00(this, a2);`. The shared helper is source-modeled as `DialogPane::SetHoverControl(int controlId)` because it uses `m_controlManager` at `+0x1fc`, toggles prior/new child state through virtual slots `+0x58`/`+0x5c`, and stores `m_activeControlId` at `+0x214`. This child no longer blocks class-level C++; remaining blockers are constructor/control field names, broader class-layout declarations, alert-source handling, and retained-helper policy.
- B005's 2026-07-04 UID0002UJ implementation sync resolves the constructor's old generated empty-emitter defect without forcing decompiler-shaped constructor C++. Current MCP session `73c77998` confirms healthy IDB state, `sub_4777A0` size `0xa45`, the sole constructor caller `0x00471d4a`, allocation size `0x5368` / 21352, previous-subject buffer and packet argument roles, vtable writes at `0x004777ee`/`0x004777f4`/`0x004777fe`, parser edges `0x00477848` and `0x00477d0c`, dynamic control/helper calls, no recovered local `Predefined`/`NewPredefined`/`FormArticle` type, no raw pointer-pattern route for the constructor, and clean padding at `0x00477790-0x004777a0` and `0x004781e5-0x004781f0`. The constructor remains source-owned by this class, reconstructable, and blank-formal because source-quality dynamic-control member/helper declarations are not recovered.
- B014's 2026-07-03 UID0002UP implementation sync resolves the parser child as source-ready at `90/92`. Current MCP session `b010_00032w_20260703` confirms `sub_478650` size `0x2e3`, exact range `0x00478650-0x00478933`, two constructor-only call sites `0x00477848` and `0x00477d0c`, no extra callers, `0x40c` entry stride, field offsets `+0x00/+0x02/+0x202/+0x203/+0x204/+0x206/+0x408`, `empty` handling through `word_60DB20`, visible-row logic, clean boundary padding, and no named IDA `Predefined*` type. The missing exact original parser type spelling is now a child confidence cap rather than a class blank-C++ blocker.
- The main aggregate [UID:0000ZL][0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md) is scored `85/90` and records the retained navigation helper plus unreferenced `0x00478aa0` helper. B002's 2026-06-25 MCP-backed recheck raises [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md) to `88/91`, names it `NavigateToPreviousArticleSelection`, and inserts exact child formal C++; the no-function/no-xref/no-VA/RVA-pointer/no-vtable-slot proof is preserved with sibling vtable positives at `0x00614098`, `0x006140ac`, and `0x006140e8`.
- B002's 2026-06-26 [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md) implementation sync resolves the command handler as source-ready child C++. Active MCP session `80de0a67` confirms `sub_478240` size `0x62`, half-open range `0x00478240-0x004782a2`, vtable/data route `0x00614098 -> 0x00478240`, no ordinary callers, one exact VA pointer-pattern hit and no RVA/end-address pointer hit, eight leading and fourteen trailing `0xcc` bytes, unique signature, submit edge `0x0047827e -> 0x00478be0`, and callee set `0x00478be0`, `0x004a10e0`, and `0x004a12b0`. The stale close/pop reading of `0x004a12b0` is superseded: it is `CreateScreenDimmer()`, while cancel uses `0x004a10e0` / `DialogSession::PopCurrentDialog(false)`. This child no longer blocks class-level C++; remaining blockers are constructor/control field names, broader class-layout declarations, alert source split, and retained-helper policy.
- B014's 2026-06-26 [UID:0002UL][0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle](by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md) implementation sync resolves the submit child as source-ready first-draft C++. Active MCP session `80de0a67` confirms `sub_478BE0` size `0x3ae`, exact half-open range `0x00478be0-0x00478f8e`, predecessor and successor `0xcc` padding, sole caller `0x0047827e` from [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md), subject control `3`, free-text control `4`, parsed-row label/value controls `4 + row*2` and `5 + row*2`, `0x40c` entry stride, row fields `+0x202` / `+0x408`, opcode `0x3b` / subcommand `4` packet layout, `g_packetSender` queue/send path, and 15000 ms post-send wait. Current callee evidence rejects adding normal article validation/sanitizer calls here. Submit/packet helper naming is no longer a child C++ blocker; inferred private field/helper spellings remain confidence caps.
- B005's 2026-06-25 [UID:0002UM][0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer](by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md) implementation sync resolves the event handler as a source-ready child. Active MCP session `80de0a67` confirms the tertiary vtable/data route `0x006140e8 -> 0x004782b0`, no ordinary callers, handled/true return in `AL`, the null-event plus active-ScreenDimmer construction path, ScreenDimmer helpers `0x004a1380`/`0x004a1360`, fixed post-error string `0x00614990`, shared OK label `0x00613a18`, operator-new allocation at `0x004f4aa0`, and `TransferReplyPredefinedAlert` construction/vtable stores through `AlertPane::AlertPane`. This handler no longer blocks class-level C++; remaining blockers are constructor/control field names, broader class-layout declarations, alert-source handling, and retained-helper policy.
- B005's 2026-06-25 source-quality callback resolves [UID:0002UO][0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint](by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md) as a source-ready child. Active MCP session `80de0a67` confirms `sub_478380` size `0x2cc`, vtable/data route `0x00614094 -> 0x00478380`, no ordinary callers, one exact VA pointer hit, no RVA pointer hit, `0xcc` padding before/after, current branch `DLGBBS08.EPF`/`DLGBBS08.PAL`, legacy branch `DLGBBS08.EPD`/`NPAL8.PAL`, and visible row count `this+0x276`. The child now uses source-facing `g_useEpfAssets`, `g_pEPFLib`, `SurfaceRenderCallbackTable` slot wrapper, `EPFFrame`, `SetPaneDrawMode`, `Rect::Set`, `Rect::Offset`, `DrawEPFFrame`, `m_paintRegion`, `m_redrawPending`, and `m_visibleFormRowCount` names. These inferred spellings cap child confidence below final audit but no longer block the child C++ block.
- B001-030 resolved `0x00478aa0` reachability negatively. C001-008 rerouted the separate helper to this class after a fresh IDA MCP pass reconfirmed no inbound edge for `0x00478aa0`, live sibling slots for `0x00478940`, `0x004782b0`, and `0x004790a0`, the analogous `NewArticleDialog` retained-helper split, and that this class/file parent chain now clears the strict `85/85` gate.
- Historical generated constructor output contained placeholder/empty-emitter text for dynamic-control and EPD-layout branches. After the UID0002UJ callback, the constructor page is intentionally non-emitting with blank formal C++; use direct IDA decompilation/disassembly and the checked child pages as the evidence base before any future constructor source body is attempted.
- Current scalar deleting destructor text calls `ArticleDialog::~ArticleDialog()`; treat that as base-owner pollution. IDA decompilation on 2026-05-25 and 2026-05-26 shows [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) calls `0x004a1450`, the [UID:00003S][DialogInSession](by-class/DialogInSession.md) non-deleting destructor also used by neighboring article/bulletin deleting destructors.
- IDA disassembly/decompilation on 2026-05-25 and 2026-05-26 shows [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) are compiler adjustor thunks, not missing handwritten behavior.
- 2026-06-21 B011 raw PE recheck resolves the adjustor pair to source-routing quality: `0x0047e931-0x0047e93c` subtracts `0xa0` and jumps to [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md), `0x0047e93c-0x0047e947` subtracts `0xa4` and jumps to the same wrapper, the only start refs are vtable slots `0x006140b4` and `0x006140e4`, and constructor stores at `0x004777f4`/`0x004777fe` place those tables at `this+0xa0`/`this+0xa4`. The class source should declare ordinary inheritance/destructor behavior; do not add source methods for these thunk labels.
- 2026-06-19 B012 rechecked the deleting destructor companion. The ordinary/source-level `NewPredefinedFormArticleDialog` destructor has no derived cleanup body proven by the binary; the exact wrapper at `0x0047ec30` calls [UID:00003S][DialogInSession](by-class/DialogInSession.md) cleanup directly, then runs compiler deleting-destructor flag handling. It frees storage only on the ordinary `(flags & 1) != 0 && (flags & 4) == 0` path through `OperatorDeleteWrapper`; the `flags & 4` path calls the one-byte MSVC guard-check no-op at `0x0041b6a0` with object size `0x5368` / 21352 (Verified with `int_convert.py`). Treat `ArticleDialog::~ArticleDialog` and `boost::exception` spellings from decompilers/generated output as type/name pollution.
- [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md) action `0x004790a0` currently disagrees with active generated source and should be verified from IDA before migration.

## Cross-References

- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:0000ZL][0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md)
- [UID:0002UJ][0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor](by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md)
- [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md)
- [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md)
- [UID:0002UM][0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer](by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md)
- [UID:0002UN][0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl](by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md)
- [UID:0002UO][0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint](by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md)
- [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md)
- [UID:0002UQ][0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert](by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md)
- [UID:0002UR][0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload](by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload.md)
- [UID:0002UL][0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle](by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md)
- [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md)
- [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md)
- [UID:0000UE][DeserializePredefinedFormArticleEntries_478650](by-item/DeserializePredefinedFormArticleEntries_478650.md)
- [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)

## Score Rationale

- Completion is `86` because the page now has exact class inventory, direct file-parent attachment, constructor/parser/submit/paint/handler/destructor companion coverage, vtable-slot evidence, B005 current-session no-code proof for [UID:0002UJ][0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor](by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md), B002 source-quality evidence for [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md)'s retained `NavigateToPreviousArticleSelection` method, B002 source-ready evidence plus formal child C++ for [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md), B014 source-ready evidence plus formal child C++ for [UID:0002UL][0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle](by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md), B005 source-ready evidence plus formal child C++ for [UID:0002UM][0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer](by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md), B012 source-ready evidence plus formal forwarding C++ for [UID:0002UN][0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl](by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md), B005 source-ready evidence plus formal child C++ for [UID:0002UO][0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint](by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md), B014 source-ready evidence plus formal parser C++ for [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md), and B006 source-ready evidence plus formal child C++ for [UID:0002UQ][0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert](by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md). It remains below higher scores because constructor field/control names, dynamic UI helper declarations, broader alert source split, and the separate retained `0x00478aa0` emission policy are not source-final.
- Confidence is `87` because the direct parent file now clears `88/85`, live IDA evidence covers the active vtable slots and raw helper absence from those slots, B002 current MCP evidence resolves the raw navigation helper's source name/C++ disposition and the command handler's `0x00614098 -> 0x00478240` source route, B014 current MCP evidence resolves the submit child's range/caller/packet/body/C++ disposition, B005 current MCP evidence resolves the event child and paint child C++ dispositions, B014 current MCP evidence resolves the parser child's source-ready C++ disposition, and the class cluster has consistent exact child coverage. Confidence remains below source-final level because exact original filename, class-level final C++ spelling, and some constructor/control field names remain provisional.

## 2026-08-14 Whole-Class Source-Quality Resolution

The complete class is now source-ready rather than a partial class shell. `NewPredefinedFormArticleDialog` directly derives from `BulletinDialog`; the inherited `DialogInSession`, `DialogPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler` views are proven by the nine-entry RTTI hierarchy. The `EventHandler` and `TimerHandler` subobjects begin at `+0xa0` and `+0xa4`, matching the two secondary vtable stores and compiler adjustor thunks.

### Exact Source Layout

| Offset | Source member | Type / size | Evidence |
| --- | --- | --- | --- |
| `+0x274` | `m_predefinedFormEntryCount` | `unsigned short` / 2 | Parser output and constructor/free-text initialization. |
| `+0x276` | `m_visibleFormRowCount` | `unsigned short` / 2 | Parser output and paint/geometry loops. |
| `+0x278` | `m_predefinedFormEntries` | `PredefinedFormArticleEntry[20]` / `20 * 0x40c` | Constructor parser destination, dynamic-control loop, and submit serialization. |
| `+0x5368` | object end | total size `0x5368` | Sole caller allocates exactly 21352 bytes; last row ends at this boundary. |

`PredefinedFormArticleEntry` is naturally padded by the compiler rather than carrying invented reserved fields:

| Offset | Field | Type |
| --- | --- | --- |
| `0x000` | `titleLength` | `unsigned char` |
| `0x002` | `title` | `wchar_t[256]` |
| `0x202` | `usesUserImagePane` | `bool` |
| `0x203` | `textLineCount` | `unsigned char` |
| `0x204` | `bodyLength` | `unsigned char` |
| `0x206` | `body` | `wchar_t[256]` |
| `0x408` | `rowAdvanceMode` | `int` |

The title's two-byte alignment gap and the body field's alignment arise naturally under the accepted MSVC-era layout. Total row size is `0x40c`; no explicit reserved members belong in the human-source declaration.

### Complete Method And Helper Inventory

| UID / range | Source identity | Class/source disposition |
| --- | --- | --- |
| [UID:0002UJ][0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor](by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md) `[0x004777a0,0x004781e5)` | constructor | Source definition; parses form data, builds controls, and establishes final bounds. |
| [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md) `[0x004781f0,0x00478238)` | `NavigateToPreviousArticleSelection` | Retained private method despite zero inbound xrefs in the dated snapshot. |
| [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md) `[0x00478240,0x004782a2)` | `OnCommand` | Primary-view virtual command handler. |
| [UID:0002UM][0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer](by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md) `[0x004782b0,0x00478363)` | `OnTimer` | TimerHandler-view virtual, not generic `HandleEvent`. |
| [UID:0002UN][0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl](by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md) `[0x00478370,0x00478379)` | `SetHoverControl` | Primary-view forwarding virtual. |
| [UID:0002UO][0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint](by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md) `[0x00478380,0x0047864c)` | `void OnPaint` | Primary-view paint virtual; no integer result. |
| [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md) `[0x00478650,0x00478933)` | `DeserializePredefinedFormArticleEntries` | File-local `__stdcall` helper; declared before constructor use. |
| [UID:0002UQ][0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert](by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md) `[0x00478940,0x00478a93)` | `HandleTransferReplyPredefinedAlert` | Primary-view full-packet transfer-reply virtual. |
| [UID:0002UR][0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload](by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload.md) `[0x00478aa0,0x00478bd9)` | `HandleTransferReplyPredefinedAlertPayload` | Retained private payload-layout twin; source-authored despite zero inbound xrefs. |
| [UID:0002UL][0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle](by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md) `[0x00478be0,0x00478f8e)` | `SubmitArticle` | Private opcode `0x3b` / subcommand `4` serializer using unsigned board id. |
| [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) `[0x0047e931,0x0047e947)` | two destructor adjustors | Compiler-only consequences of the `+0xa0`/`+0xa4` subobjects. |
| [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) `[0x0047ec30,0x0047ec6b)` | scalar deleting destructor | Compiler-only; regenerated from normal class destruction semantics. |

### Vtable And RTTI Contract

Exact non-emitting data child [UID:00050Q][0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData](by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md) covers `[0x0061404c,0x006140ec)`: primary COL plus 24 slots, EventHandler COL plus 11 slots, and TimerHandler COL plus 2 slots. Constructor stores install bases `0x00614050`, `0x006140b4`, and `0x006140e4` at object offsets `0`, `+0xa0`, and `+0xa4`. File-owned virtual slots are:

- `0x00614094 -> 0x00478380`: `OnPaint`;
- `0x00614098 -> 0x00478240`: `OnCommand`;
- `0x006140a8 -> 0x00478370`: `SetHoverControl`;
- `0x006140ac -> 0x00478940`: full-packet transfer-reply handler;
- `0x006140e8 -> 0x004782b0`: `TimerHandler::OnTimer`.

The private navigation and payload helpers do not occupy virtual slots. The vtable child, deleting destructor, adjustors, COLs, and RTTI arrays remain non-emitting because the accepted header declaration must cause the compiler to regenerate them.

### CPP/H Source Contract

The formal H channel owns `PredefinedFormArticleEntry`, the complete class declaration, inheritance, virtual declarations, private helpers, and the three data members. The formal CPP channel owns the module includes, a parser forward declaration before constructor use, and `[[CHILDREN]]` for the ten exact source definitions in address/source order. Definitions do not belong directly on this class page; each exact by-memory child remains canonical for its body.

Required runtime/source dependencies are `BulletinDialog`, `BulletinSession`, dialog controls, packet buffer helpers, the screen dimmer, `TransferReplyPredefinedAlert`, `MultiByteToWideChar`, `WideCharToMultiByte`, `memmove`, and wide-string helpers. Resource branches use `DLGBBS08.EPF` / `DLGBBS08.PAL` and legacy `DLGBBS08.EPD` / `NPAL8.PAL`.

### Superseded Historical Assumptions

- Historical constructor no-code conclusions are retained in the change history but superseded by the complete caller, allocation, argument, parser, control, geometry, and class-layout evidence.
- Historical `HandleEvent` naming for `0x004782b0` is superseded by the tertiary TimerHandler slot and exact timer-id-zero behavior; the source method is `OnTimer`.
- Historical `int OnPaint` is superseded by the inherited void contract and exact body; the source method returns `void`.
- Historical omission of `0x00478aa0` is superseded by its complete source-shaped structural twin and retained private-method disposition. Its zero-xref evidence remains documented as liveness history, not a source-exclusion rule.
- Historical duplicate row declarations in the parser CPP are superseded by the H-owned naturally padded struct.

## 2026-08-14 Score Rationale

- Completion `94`: the page now contains the full class/header contract, exact object and row layouts, every source/ABI child, vtable/RTTI routes, dependencies/resources, source order, formal CPP/H, and closed historical blockers.
- Confidence `94`: direct callers, ranges, field offsets, vtable slots, constructor stores, RTTI hierarchy, packet/resource behavior, and sibling analogs agree. Remaining uncertainty is lexical spelling of a few private helpers/members and include names, below the `95+` final-audit threshold.

## Changes

- 2026-08-14 B004 UID0000LT implementation callback: raised `86/87` to `94/94`, populated the accepted CPP/H channels, completed the object/row layout and ten-body inventory, linked exact vtable child [UID:00050Q][0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData](by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md), corrected `HandleEvent` to `OnTimer` and `int OnPaint` to `void OnPaint`, promoted both retained private helpers to source emission, and retained all prior contrary assumptions as superseded history.

- 2026-07-05 B012 [UID:0002UN][0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl](by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md) implementation sync: kept class score/metadata unchanged, updated the method row, evidence notes, and score rationale so the hover-control vtable forwarder is source-ready at `90/92` with formal `NewPredefinedFormArticleDialog::SetHoverControl(int controlId)` C++. The child records fresh MCP session `supervisor_recovery_20260705`, exact `0x9` range, padding, vtable-only route `0x006140a8 -> 0x00478370`, helper `DialogPane::SetHoverControl(int controlId)` over `+0x1fc` control manager and `+0x214` active-control id state, sibling `NewArticleDialog::SetHoverControl` precedent, and rejection of focus/select-control/rect-writer names. Class-level C++ remains blank only for broader constructor/control declarations and retained-helper policy.
- 2026-07-04 B005 [UID:0002UJ][0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor](by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md) implementation sync: kept class score/metadata unchanged, updated the method row, evidence notes, and score rationale so the constructor is `88/91`, reconstructable, class-owned, and intentionally non-emitting with blank formal C++. The child records current MCP session `73c77998`, exact size `0xa45` / 2629, caller/allocation/argument roles, vtable writes, parser call sites, dynamic-control/helper flow, type/struct negative checks, boundary padding, raw pointer-pattern negatives, and the old generated empty-emitter defect; class-level C++ remains blank because constructor control fields/helpers and retained-helper policy are still not source-final.
- 2026-07-04 B006 [UID:0002UQ][0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert](by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md) implementation sync: kept class score/metadata unchanged, updated the method row, evidence notes, and score rationale so the live predefined transfer-reply packet handler is source-ready at `90/91` with formal `NewPredefinedFormArticleDialog::HandleTransferReplyPredefinedAlert(const unsigned char *packet)` C++. The child records fresh MCP session `73c77998`, exact range/size/padding, vtable route `0x006140ac`, zero code xrefs, pointer-pattern negatives, packet subcommand `0x06`, message conversion, ScreenDimmer release, `TransferReplyPredefinedAlert` allocation/vtable stores/`+0x270` reply-byte storage, and UID0002UR no-route sibling distinction; class-level C++ remains blank only for broader constructor/control declarations and retained-helper policy.
- 2026-06-27 B006 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync:
  - Score and owner/emitter unchanged at `86/87`, [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md), and `EMITTER_UIDS:0000LT`.
  - Added the secondary `0x006140b4 + 0x10 -> 0x006140c4 -> 0x00472040` consumer-slot note, preserving the dedicated file route and class-level C++ blankness.
- 2026-07-03 B014 [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md) implementation sync: kept class score/metadata unchanged, updated the method row, evidence notes, and score rationale so the parser helper is source-ready at `90/92` with formal file-local `DeserializePredefinedFormArticleEntries` C++ and inferred `PredefinedFormArticleEntry` declaration. The parser child records current MCP session `b010_00032w_20260703`, exact range/size, two constructor-only call sites, no extra callers, `0x40c` stride, field offsets, `empty` handling through `word_60DB20`, row-count logic, boundary padding, and no named IDA `Predefined*` type; parser declaration uncertainty is no longer a class-level blank-C++ blocker.
- 2026-06-26 B002 [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md) implementation sync: raised class score/metadata from `85/86` to `86/87`, updated the method row and evidence notes so the command handler is source-ready at `90/91` with formal `NewPredefinedFormArticleDialog::OnCommand(int commandId, int)` C++. The primary vtable route `0x00614098 -> 0x00478240`, command `0` submit path, command `1` cancel path, submit edge `0x0047827e`, active dialog host restore, `CreateScreenDimmer()` call, and `DialogSession::PopCurrentDialog(false)` helper identity are recorded; class-level C++ remains blank only for broader constructor, parser/layout, alert-source, and retained `0x00478aa0` issues after B014 resolved the submit child separately.
- 2026-06-26 B014 [UID:0002UL][0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle](by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md) implementation sync: kept class score/metadata unchanged after B002's same-day `86/87` support raise, updated the method row, evidence notes, and score rationale so the submit method is source-ready at `90/91` with formal `NewPredefinedFormArticleDialog::SubmitArticle(short boardId)` C++. The submit child records active MCP session `80de0a67`, command ids `10`, `11`, `14`, `15`, `17`, `18`, `19`, `20`, and `21`, exact range/padding, sole caller through [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md), subject/body control flow, parsed-row field mapping, opcode `0x3b` / subcommand `4` packet layout, `g_packetSender` send path, no validation/sanitizer calls, and void-return rationale. Class-level C++ remains blank for broader constructor, parser/layout, alert-source, and retained `0x00478aa0` issues, not because submit/packet naming is still a child C++ blocker.
- 2026-06-25 B005 [UID:0002UM][0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer](by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md) implementation sync: kept class score/metadata unchanged at `85/86`, updated the method row and evidence notes so the event handler is source-ready at `90/92` with formal `NewPredefinedFormArticleDialog::HandleEvent()` C++. The tertiary vtable route `0x006140e8 -> 0x004782b0`, handled/true return, null-event plus active-ScreenDimmer path, fixed error string, OK label, and `TransferReplyPredefinedAlert` construction facts are recorded; class-level C++ remains blank only for broader constructor, parser/layout, alert-source, and retained `0x00478aa0` issues after B014 resolved the submit child separately.
- 2026-06-25 B005 [UID:0002UO][0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint](by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md) source-quality sync: updated the method row, evidence notes, and score rationale so the paint method is source-ready at `90/92` with formal first-draft `NewPredefinedFormArticleDialog::OnPaint()` C++. The target's no-direct-caller/vtable-only route, helper-name uncertainty, field-name uncertainty, and old `95/95` gate language are preserved as confidence caps or historical blockers, not as child blank-C++ blockers. Class-level C++ remains blank for unrelated constructor, parser, packet, alert, and retained `0x00478aa0` issues.
- 2026-06-25 B002 [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md) source-quality sync: updated the method row and evidence notes for [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md). The child is now `88/91`, emits exact `NewPredefinedFormArticleDialog::NavigateToPreviousArticleSelection()` C++ through this class route, and preserves the no-function/no-caller/no-pointer/no-vtable evidence as a route caveat rather than a retained-helper C++ blocker. Class-level C++ remains blank because broader constructor, parser, packet, alert, and `0x00478aa0` issues are separate.
- 2026-06-19 B012 scalar-wrapper sync: updated the method row and evidence notes for [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md). The class remains source-owned by [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md), while the wrapper remains ownerless/non-emitting ABI glue regenerated from ordinary/default destructor semantics.
- 2026-06-12 C001 Batch C001-008: updated [UID:0002UR][0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload](by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload.md) from parent blank to this class after a fresh IDA MCP pass reconfirmed the negative reachability result, live sibling vtable slots, identical alert-construction pattern, and analogous `NewArticleDialog` retained-helper split. Scores stay `85/86`; final C++ remains blank pending retained-helper source-emission policy and final field/helper names.
- 2026-06-21 B011 support sync: incorporated the final [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) source-routing decision into the class evidence: the secondary/tertiary destructor slots are compiler-generated from the `+0xa0`/`+0xa4` class layout and must not be hand-authored as class methods.
- 2026-06-12 A001 Batch 240 follow-up parent-gate repair: raised `84/80` to `85/86` after repairing file parent [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) to `88/85` and adding live IDA evidence that [UID:0002EK][0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper](by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md) is a bounded class-cluster helper with no function object, xrefs, pointer hits, or NewPredefined vtable slot while sibling routed methods do have vtable slots.
- 2026-06-10 B001-030 consistency update: revised the [UID:0002UR][0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload](by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlertPayload.md) method row and evidence note after IDA MCP/IDAPython found no callers, xrefs, raw VA/RVA pointer hits, immediate/code-ref/data-ref owner, or vtable slot for `0x00478aa0`. Scores and parent remain unchanged because the class still has final field/source-name and retained-helper emission caveats.
- 2026-06-07 A007 parent-chain sync: raised confidence from `78` to `80` and attached `AUTOGEN_PARENT_UID:0000LT` after verifying [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) is `88/80` and the aggregate/child memory pages document exact constructor/helper/handler/parser/submit boundaries, padding, vtable references, parser and submit call edges, and file-level ownership. Updated method rows to exact half-open child ranges and added the raw navigation helper, parser helper, and unreferenced transfer-reply helper caveats. Completion remains `84` and final C++ remains blank because dynamic-control field names, packet/helper types, retained-helper source-emission treatment, and alert source placement are not source-final.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor/command/event/paint/submit/thunk/deleting-destructor starts at `0x004777a0`, `0x00478240`, `0x004782b0`, `0x00478370`, `0x00478380`, `0x00478940`, `0x00478be0`, `0x0047e931`, `0x0047e93c`, and `0x0047ec30`. Left `AUTOGEN_PARENT_UID` blank because this class confidence is below the 80 attachment gate even though [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) is the likely source-module parent.
- Before: completion/confidence metadata were `0/0` despite detailed constructor, submit, paint, transfer-reply, layout, destructor, and parser-helper notes.
- Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
- Evidence: the page documents form-entry parsing, dynamic controls, packet serialization, destructor companion ranges, and multiple IDA-backed caveats; confidence remains medium because final source split, constructor control/helper naming, and `TransferReplyPredefinedAlert` behavior still need verification.
