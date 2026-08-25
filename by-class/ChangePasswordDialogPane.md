*** UID:00001L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ChangePasswordDialogPane.h"
#include "MainMenuPane.h"
#include "../app/Application.h"
#include "../app/StartupWindow.h"
#include "../localization/LanguageMan.h"
#include "../network/PacketBuffer.h"
#include "../network/Socket.h"
#include "../ui/MainUiGraph.h"
#include "../ui/controls/ButtonControlPane.h"
#include "../ui/controls/EPFImageControlPane.h"
#include "../ui/controls/TextEditControlPane.h"
#include "../ui/core/Event.h"
#include "../ui/core/RectBounds.h"
#include "../ui/core/ScreenDimmer.h"
#include "../ui/core/ScreenPane.h"
#include "../ui/dialogs/AlertPanes.h"

#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>

static void __stdcall SendPasswordChangeRequest(
    const wchar_t *accountName,
    const wchar_t *currentPassword,
    const wchar_t *newPassword);

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../ui/core/DialogPane.h"
#include "../util/Singleton.h"

class Event;
class ChangePasswordDialogPane;
extern ChangePasswordDialogPane *g_pChangePasswordDialogPane;

class ChangePasswordDialogPane : public DialogPane,
                                 public Singleton<ChangePasswordDialogPane>
{
public:
    ChangePasswordDialogPane();

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();
    virtual bool HandlePacketEvent(Event *event);

private:
    void SubmitPasswordChange();
    bool HandlePasswordChangeReply(const unsigned char *packet);
    bool HandlePasswordChangeReplySimple(const unsigned char *packet);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChangePasswordDialogPane

## Status

- Confidence: strong
- Likely source file: [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md), or folded into [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- Address range: [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md) plus the four exact source-bearing packet children indexed by reviewed non-emitting physical container [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md)
- Current recovered file: `source-3/simroot_v2/class_ChangePasswordDialogPane.cpp`

## Class Purpose

`ChangePasswordDialogPane` owns the password-change dialog opened from the main menu. It builds old/new asset variants, validates non-empty fields, checks the new password and confirmation, and sends the active `accountName`/`currentPassword`/`newPassword` password-change request after creating a screen dimmer.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChangePasswordDialogPane` | `0x004fdd40`, size `0x720` | Builds the `DLGPASS.EPF`/`DLGPASS.PAL` centered layout or the `DLGPASS.EPD`/`off_61484C` fixed layout, publishes `0x0069b48c`, and installs the three `ChangePasswordDialogPane` vtable views; the exact UID0002QA core page is now direct-rechecked at `88/90`. |
| `OnDialogAction` | `0x004fe460`, size `0x2e` | Action id `1` submits through `0x004fe560`; action id `2` closes/dismisses through `sub_49EB90` and `sub_49DAD0`. |
| `ValidateInputFields` | `0x004fe490`, size `0x96` | Reads child controls `3` through `6` and toggles the action control through virtual slots `+0x50`/`+0x4c` when required fields are empty/non-empty. |
| `HandlePasswordChangePacket` | `0x004fe530`, size `0x26` | Packet dispatcher slot; packet type `2` routes to `0x004febf0`, otherwise returns `0`. |
| `SubmitPasswordChange` | `0x004fe560`, size `0x222` | Reads controls `3`, `4`, `5`, and `6`; maps controls `3/4/5` to `accountName`, `currentPassword`, and `newPassword`; enforces the digit and confirmation checks on control `5` against confirmation-only control `6`; creates the dimmer/loading object; and calls the active source-ready three-field password-change sender at `0x004fe778`. |
| `SendPasswordChangeRequestWithAccountId` / `RawPasswordChangePacketWithAccount` | `0x004fe790-0x004fe9d1` | Retained raw source-family opcode `0x26` packet sender variant with three text fields plus a parsed wide numeric field; B004's 2026-06-23/2026-06-24 MCP/PE recheck found no function object, caller, xref, table, pointer, immediate, or direct-transfer route to this raw start, so it remains retained/no-route, but B005 supersedes the blank-formal-C++ proof and adds formal first-draft C++ on the child page. |
| `SendPasswordChangeRequest` | `0x004fe9e0`, size `0x202` | Active submit sender with B009 formal C++ on the child page. Builds opcode `0x26`/decimal `38` password-change packet from `accountName`, `currentPassword`, and `newPassword`, writes one-byte length prefixes and length-counted payload bytes, uses local-only terminators outside the sent packet length, and sends through `dword_67A7EC` / `QueueAndSendPacket(g_packetSender, packet, packetLength)`; reached from `SubmitPasswordChange` at `0x004fe778`. |
| `HandlePasswordChangeReply` | `0x004febf0`, size `0x221` | Source-ready B002 formal method `bool ChangePasswordDialogPane::HandlePasswordChangeReply(const unsigned char *packet)`. It handles dispatcher packet type `2`, deletes `g_pScreenDimmer`, reads `packet[1]` result, `packet[2]` message length, and `packet + 3` ANSI message bytes, routes result groups `3,4,14,16,17,18,20,21` to `SetHoverControl(3)` for account-name errors, result `15` to `SetHoverControl(4)` for current-password errors, and results `5..9` to `SetHoverControl(5)` for new-password errors, shows nonempty reply text through `AlertPane` with `kDialogOkButtonText`, and on success calls `SlideCloseVertical()` then `CloseDialog()`. Current active MCP still names the function `sub_4FEBF0`; the source-facing method name is evidence-backed but not a current saved IDB label. |
| `HandlePasswordChangeReplySimple` | `0x004fee40`, size `0x1ff` | Source-ready B006 retained/simple method `bool ChangePasswordDialogPane::HandlePasswordChangeReplySimple(const unsigned char *packet)`. Current MCP still names the function `sub_4FEE40` and finds no direct xref or pointer hit, but behavior/locality tie it to this account dialog family: it deletes `g_pScreenDimmer`, reads `packet[1]` result, `packet[2]` message length, and `packet + 3` ANSI message bytes, maps result codes `3..8` to `SetHoverControl(5)`, shows optional `AlertPane` text with `kDialogOkButtonText`, and on success calls `SlideCloseVertical()` then `CloseDialog()`. The no-route fact remains a confidence/source-placement cap rather than a blank-C++ blocker. |
| Destructor family | `0x00502474`, `0x0050247f`, `0x00502650` | Adjustor and deleting destructor family. |

## State And Layout Anchors

| Anchor | Evidence |
| --- | --- |
| Active singleton | [UID:0002XM][0x0069b48c-0x0069b490.g_pChangePasswordDialogPane](by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md) is now source-ready through [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md) with formal `ChangePasswordDialogPane *g_pChangePasswordDialogPane = (ChangePasswordDialogPane *)-1;`. Current B003 MCP session `e63ee655` reports exact range `0x0069b48c-0x0069b490`, size `0x4`, bytes `FF FF FF FF`, no function at the slot, current operand label `unk_69B48C`, constructor publish/fallback-clear refs, main-menu cleanup consumer, support-helper clear, and destructor-family clear. Exact source symbol spelling and initializer spelling remain confidence caps because B010 session `c9ac3d5b` reported zero bytes for the surrounding aggregate while current B003 `e63ee655` reports `FF` bytes. |
| Vtables/resources | [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) places the three `ChangePasswordDialogPane` vtable views and the `DLGPASS.PAL`/`DLGPASS.EPF`/`DLGPASS.EPD` resource literals in the main-menu/new-user read-only band. |
| Core methods | [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md) now carries the direct constructor/action/validation/dispatcher/submit method evidence and attaches to this class. |
| Packet helpers | [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) carries the adjacent send/reply helpers, exact padding spans, active `0x004fe9e0` submit caller, active `0x004febf0` reply dispatcher route, and raw/sibling caveats. B004's 2026-06-23/2026-06-24 recheck keeps [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md) as a retained no-route numeric-field variant, while [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md) remains the active submit sender. B005 adds formal retained-helper C++ for [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md) without changing the active-vs-retained split; B009 adds formal active-helper C++ for [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md) and resolves the active field names as `accountName`, `currentPassword`, and `newPassword`; B002 adds formal reply-handler C++ for [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md), resolving packet `[1]/[2]/[3]`, `SetHoverControl(3/4/5)`, `g_pScreenDimmer`, `AlertPane`, `kDialogOkButtonText`, `SlideCloseVertical()`, and `CloseDialog()` at class-support level; and B006 adds formal retained/simple reply-handler C++ for [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md), resolving its packet `[1]/[2]/[3]`, result `3..8` -> `SetHoverControl(5)`, optional `AlertPane`, success close path, raw-name caveat, and no-direct-route cap. |
| Packet helpers | [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) is now a reviewed `94/94`, `RECONSTRUCTABLE:FALSE`, non-emitting physical index, not a second class/source object. All source-authored behavior remains on exact children [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md), [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md), [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md), and [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md). UID0002QC is the sole active submit sender at `0x004fe778`; UID0002QD is the packet-type-2 reply target at `0x004fe551`; UID0002QB is a retained opcode-`0x26` sender with three text fields plus an `_wtol`/uint32 field; UID0002QE is a retained/simple reply sibling with no current route. The parent contributes only exact topology, including compiler switch support `[0x004fee14,0x004fee37)` and nine-byte alignment `[0x004fee37,0x004fee40)`. Child formals and UID0000I3 routing remain unchanged; no aggregate class declaration/body, `[[CHILDREN]]`, covered-by prose, or duplicated method body belongs here. |

## 2026-07-24 Packet-Helper Container Reconciliation

- The class remains `85/89`, reconstructable, owned/emitted by UID0000I3, with its existing blank class formal. Reclassifying UID00022W does not remove the four child functions from this class/file family and does not justify duplicating their method/helper bodies in the class page.
- Exact source topology is child-only: UID0002QB retained four-argument packet sender, UID0002QC active three-field sender, UID0002QD active packet-type-2 member reply handler, and UID0002QE retained/simple member reply sibling. Compiler alignment and the UID0002QD jump/class tables are not class declarations.
- The active sender serializes controls `3/4/5` as `accountName`, `currentPassword`, and `newPassword`; control `6` is confirmation-only. The retained sender instead serializes three text fields plus a fourth wide numeric argument through `_wtol` and a big-endian uint32 writer.
- Both reply children consume result `packet[1]`, byte length `packet[2]`, and ANSI bytes at `packet + 3`, clear `g_pScreenDimmer`, show optional converted text through `AlertPane`, and close on success. UID0002QD has the direct dispatcher route and focus groups `3/4/5`; UID0002QE has no current route and only result codes `3..8` focus control `5`.
- Current B002 direct evidence confirms the retained children have no code/data/immediate/pointer route, while the active edges are unique. This preserves retained-source behavior without inventing registration, ranking ownership, or a parent-level source API.
- Historical correction: older class wording treated UID00022W as a reconstructable adjacent helper cluster. It remains a useful physical index, but its true/emitting metadata and blank-parent-C++ blocker are superseded by the false/non-emitting container decision. Exact children remain source-owned and source-ready.

## Evidence Notes

- 2026-06-12 IDA MCP `analyze_component` over the UI/core method island confirms `0x004fdd40` as the interface constructor and `0x004fe460`, `0x004fe490`, `0x004fe530`, and `0x004fe560` as internal-only helpers, with the internal call graph edge `0x004fe460 -> 0x004fe560`.
- 2026-06-12 IDA MCP `decompile 0x004fdd40` confirms the two resource/layout branches, action ids `1`/`2`, focus/control id `4`, vtable stores, singleton publish, and constructor use of `word_66DA94`/`word_66DA98`/`byte_66DA97`.
- 2026-06-12 IDA MCP `analyze_function` confirms `0x004fe460`, `0x004fe490`, `0x004fe530`, and `0x004fe560` behavior: submit/cancel dispatch, required-field gate, packet type `2` dispatch, digit/match validation, dimmer creation, and direct call to `0x004fe9e0`.
- 2026-06-16 C001 live IDA MCP refresh reconfirmed the reply-handler support chain: `0x004fe530` dispatches packet type `2` to `0x004febf0`, the primary reply handler has the direct xref at `0x004fe551`, the simple sibling at `0x004fee40` still has no direct xrefs or little-endian pointer hits, and the local switch support table at `0x004fee14` is referenced only from `0x004fec64`. C001 reported saved `ChangePasswordDialogPane_HandlePasswordChangeReply` and `ChangePasswordDialogPane_HandlePasswordChangeReplySimple` function labels; B002's 2026-06-28 active MCP session `supervisor_20260628_resume` supersedes that as current-IDB evidence because it again reports raw `sub_4FEBF0` and `sub_4FEE40`. The source-facing handler names remain correct for documentation/output, but not as current saved-IDB proof.
- 2026-06-28 B002 accepted source-quality pass for [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md) resolves the class-level reply-handler blockers. Current MCP confirms packet type `2` dispatch at `0x004fe551`, packet `[1]` result, `[2]` message length, `[3]` message payload, switch-table refs at `0x004fec64` and `0x004fec5d`, and the sibling [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md) no-start-xref caveat. The primary handler now emits formal method C++ on the child page with source-facing helper names `g_pScreenDimmer`, `SetHoverControl`, `SimpleUString::FromMbcString`, `AlertPane`, `kDialogOkButtonText`, `SlideCloseVertical()`, and `CloseDialog()`.
- 2026-07-05 B006 accepted source-quality implementation for [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md) resolves that sibling's blank-emitter blocker without inventing a dispatcher edge. Current MCP session `supervisor_recovery_20260705` reports `server_health` OK for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, current raw name `sub_4FEE40`, size `0x1ff` / 511 bytes (Verified with `tools/int_convert.py`), prototype `char __thiscall(int *this, int)`, 20 blocks, complexity `6`, `packet[1]` result, `packet[2]` length, `packet + 3` message payload, `SetHoverControl(5)` only for result codes `3..8`, optional alert text, success `SlideCloseVertical()` / `CloseDialog()`, no function at `0x004ff03f`, successor function at `0x004ff040`, zero xrefs, zero `xref_query`, and zero `find_bytes "40 ee 4f 00"` pointer hits. The source-facing name is accepted for output, while the current IDB-name proof remains raw and the older C001 saved-name claim stays historical.
- 2026-07-06 B013 direct source-quality recheck for [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md) used current MCP session `supervisor_recovery_20260705` and raises the child to `88/90`. The recheck confirmed the five core functions and sizes (`0x004fdd40` `0x720`, `0x004fe460` `0x2e`, `0x004fe490` `0x96`, `0x004fe530` `0x26`, `0x004fe560` `0x222`), constructor callers `0x004f7b49` and `0x004f90a0`, vtable/resource/singleton refs, active sender edge `0x004fe778 -> 0x004fe9e0`, dispatcher edge `0x004fe551 -> 0x004febf0`, and fourteen `0xcc` bytes at `0x004fe782-0x004fe790`. The packet sender/reply children are no longer UID0002QA blockers, but the core aggregate C++ remains blank because constructor/class member layout, control names, resource/message names, method signatures, and source grouping are still unresolved.
- IDA confirms the four local method starts and destructor family.
- `MainMenuPane::ActivateMenuItem` constructs this dialog for menu item `2`.
- IDA MCP `callers 0x004fdd40` also reports a retained launcher call at `0x004f90a0` inside [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md).
- 2026-06-27 B010 source-shape sync keeps the retained launcher with [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), not this class. Accepted report session `875bf182` and current implementation-check session `b001_000241_20260627` still report the launcher as misleading `___std_parallel_algorithms_hw_threads@0_0`, with no direct helper-entry xrefs or accepted VA/RVA pointer route. The active `MainMenuPane::ActivateMenuItem` case `2` duplicates the same allocation/constructor sequence and ignores the constructed pointer, while this constructor publishes the singleton at `0x004fdd96`; that supports first-draft `static void OpenChangePasswordDialog()` on the exact memory child and rejects a `ChangePasswordDialogPane *` returned-pointer API.
- 2026-07-03 B003 source-quality implementation for [UID:0002XM][0x0069b48c-0x0069b490.g_pChangePasswordDialogPane](by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md) updates the class-level singleton anchor to source-ready status. Current MCP session `e63ee655` confirms no function at `0x0069b48c`, bytes `FF FF FF FF`, current operand label `unk_69B48C`, and exactly five refs: cleanup read `0x004f69bf`, constructor publish/fallback `0x004fdd96`/`0x004fdd9d`, helper clear `0x005023a0`, and destructor-family clear `0x00502656`. The child now emits formal singleton declaration C++ through the file owner; the class C++ block remains blank because broader class declaration/member names and folded-vs-standalone source organization are still separate unresolved class-level issues.
- IDA MCP `callers 0x004fe560` reports the submit method is reached from `OnDialogAction` at `0x004fe484`.
- 2026-05-28 IDA MCP decompile shows `SubmitPasswordChange` calls `sub_4FE9E0(v15, v16, v18)` at `0x004fe778`, tying the packet-send helper to this class.
- 2026-06-23/2026-06-24 B004 MCP-backed recheck with session/database `80de0a67` refines the submit/helper relationship: `SubmitPasswordChange` reads controls `3`, `4`, `5`, and `6`; copies all four into 16-wide-character buffers; requires the control `5`/new-password buffer to contain an ASCII digit; compares control `5` against control `6`; creates the dimmer/loading object on success; and sends only controls `3`, `4`, and `5` through [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md). The retained [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md) raw helper has no caller/xref/table/pointer/direct-transfer route in the same MCP/PE pass.
- [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md)'s fourth argument status is now concrete rather than generic: the raw child parses its fourth wide stack argument through CRT `__wtol` and writes it through PacketBuffer `UInt32BE`, so it is a numeric retained field, but there is no caller-side source name proving account id, numeric account name, legacy user id, or removed dialog field. B005 uses `accountIdText` as an inferred source-facing parameter name and adds formal retained-helper C++; the unresolved exact spelling remains a confidence cap, not a blank-C++ blocker. The class/file owner route stays with `ChangePasswordDialogPane`.
- 2026-06-26 B009 accepted source-quality pass for [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md) reconfirmed with MCP session `80de0a67` that `SubmitPasswordChange` is the sole active caller at `0x004fe778`, controls `3/4/5` are the transmitted fields, and control `6` is confirmation-only. The active child now has formal C++ using `accountName`, `currentPassword`, and `newPassword`, with local-only terminators and length-counted packet fields. Socket, PacketBuffer, MemoryMan, and the retained [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md) helper remain support/sibling contexts rather than class ownership replacements.
- 2026-05-28 IDA MCP decompile of `sub_4FE530` dispatches packet type `2` to `sub_4FEBF0`, and `sub_4FEBF0` decodes result/message bytes for a dialog reply.
- IDA's current name for `0x004f9060` is `___std_parallel_algorithms_hw_threads@0_0`, but decompilation shows a password-dialog allocation wrapper, not library code.
- The generated source uses both high-res EPF and old EPD layout branches, supporting a login/account UI source placement.

## Parent And Score Rationale

| Field | Decision |
| --- | --- |
| Direct parent | [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md) remains the owning source-file candidate. [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md) now routes to this class instead of bypassing it. |
| Completion `85` | The class now records the core method island, packet-helper children, singleton storage, read-only vtable/resource anchors, launcher paths, destructor family, and source-file caveat. [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md) is now direct-rechecked at `88/90` with packet sender/reply children no longer blocking the core evidence, [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md) now has formal active packet-sender C++ and resolved source-facing field names, [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md) now has formal active reply-handler C++, and [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md) now has formal retained/simple reply-handler C++. Class completion remains capped because broader member/control declarations and final folded-vs-standalone source organization remain unresolved. |
| Confidence `89` | Current IDA MCP decompile/xref evidence agrees with the memory, file, global, singleton, and read-only-data pages. Confidence remains below final audit because several broader class declaration names and exact source declaration spellings are still inferred, UID0002QE has no direct route, and the current active IDB still reports raw `sub_4FEE40` despite the accepted source-facing name. |

## Cross-References

- [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md)
- [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md)
- [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) Change-password packet helper cluster
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md)
- [UID:0002XM][0x0069b48c-0x0069b490.g_pChangePasswordDialogPane](by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md)
- [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md)

## Changes

- 2026-07-24 B002 [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) direct empty-emitter implementation callback:
  - Score, owner/emitter, reconstructable state, and blank formal for this class remain unchanged at `85/89`, UID0000I3, true, UID0000I3, and blank.
  - Reconciled the packet-helper anchor with UID00022W's reviewed false/non-emitting physical-index disposition while preserving all four exact child formals, class/member behavior, active/retained route evidence, source placement, and rejected owner alternatives.
  - Recorded the corrected switch/padding split `[0x004fee14,0x004fee37)` / `[0x004fee37,0x004fee40)` and prohibited aggregate class code or duplicated child bodies.
- 2026-07-06 B013 [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md) implementation callback:
  - Score unchanged at `85/89`; updated UID0002QA method/support details to reflect the target child score `88/90`.
  - Summary/evidence: recorded current MCP session `supervisor_recovery_20260705`, exact five-function core inventory, constructor callers, singleton/vtable/resource refs, active sender/reply edges, terminal `0x004fe782-0x004fe790` padding, and the remaining blank-C++ rationale for the aggregate. The packet sender/reply children are source-ready and no longer blockers for UID0002QA evidence, while class-level C++ remains blank because broader member/control/resource/source-grouping evidence is not final.
- 2026-07-05 B006 [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md) implementation callback:
  - Score unchanged at `85/89`.
  - Summary/evidence: updated the class method row, packet-helper anchor, evidence notes, and score rationale so [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md) is now source-ready with formal retained/simple C++ on the child page. The method reads packet `[1]/[2]/[3]`, maps result codes `3..8` to `SetHoverControl(5)`, shows optional `AlertPane` text with `kDialogOkButtonText`, closes success replies with `SlideCloseVertical()` / `CloseDialog()`, and returns handled on all paths. Current MCP session `supervisor_recovery_20260705` still reports raw `sub_4FEE40`, zero xrefs, zero pointer-pattern hits, and no current dispatcher route, so route/original declaration evidence remains a confidence cap; RankingDialog remains rejected as generated-source pollution.
- 2026-06-28 B002 [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md) implementation callback:
  - Score unchanged at `85/89`.
  - Summary/evidence: updated the class method row, packet-helper anchor, evidence notes, and score rationale so [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md) became the source-ready active reply handler with formal C++ on the child page. The method handles packet type `2`, packet `[1]/[2]/[3]`, result groups mapped to `SetHoverControl(3/4/5)`, optional `AlertPane` text with `kDialogOkButtonText`, and success `SlideCloseVertical()`/`CloseDialog()`. Current MCP session `supervisor_20260628_resume` reported raw `sub_4FEBF0`/`sub_4FEE40`, so the older saved-IDB-label note is historical only; at that time [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md) kept its no-direct-xref caveat and blank formal C++. The B006 entry above supersedes that blank-C++ state for UID0002QE.
- 2026-06-12 Agent-A001 Goal 2 repair:
  - What existed before: class score was `82/88`, the core memory page bypassed the class and attached directly to the file page, and class-level method notes summarized the UI island without current constructor/validation/submit detail.
  - Changed to: `85/89`, added state/layout anchors, refreshed method roles, and made this class the direct parent for [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md).
  - Summary/evidence: live IDA MCP confirmed the constructor branch resources, singleton/vtable stores, action id handling, required-field gate, packet type dispatch, submit validation, and call to `0x004fe9e0`; related singleton/read-only-data/file pages already support the owner chain.
- 2026-06-16 C001 reply-handler refresh:
  - Score unchanged at `85/89`.
  - Summary/evidence: live IDA reconfirmed the primary reply handler's dispatcher xref, the simple reply sibling's no-direct-xref/no-pointer caveat, local switch-table ownership, RankingDialog pollution exclusion, and saved two evidence-backed handler labels in the IDB. Class-level C++ remains blank pending final field/control names, packet enum names, helper signatures, and standalone-vs-folded source grouping.
- 2026-06-23/2026-06-24 B004 [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md) source-quality implementation:
  - Score unchanged at `85/89`.
  - Summary/evidence: current MCP session `80de0a67` and local PE route scans preserve [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md) as the active submit sender, classify [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md) as a retained raw no-route numeric-field variant, and reject Socket, PacketBuffer, MainMenuPane, and no-owner alternatives for the raw child. B005 later superseded the B004 blank-formal-C++ conclusion.
- 2026-06-25 B005 [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md) implementation callback:
  - Score unchanged at `85/89`.
  - Summary/evidence: updated class-level method/helper notes so [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md) has formal first-draft retained-helper C++ for three converted text fields plus `_wtol`/`PacketBufferWriteUInt32BE` numeric field, while [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md) remains the active submit sender and the fourth-field exact source spelling remains a confidence cap.
- 2026-06-26 B009 [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md) implementation callback:
  - Score unchanged at `85/89`.
  - Summary/evidence: updated class method/helper notes so [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md) is the active source-ready three-field helper, controls `3/4/5` map to `accountName`, `currentPassword`, and `newPassword`, control `6` remains confirmation-only, and the child formal C++ preserves length-counted fields plus local-only terminators. [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md) remains the retained account/id variant, and Socket/PacketBuffer/MemoryMan remain support contexts only.

- 2026-06-27 B010 [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md) implementation callback:
  - Score unchanged at `85/89`.
  - Summary/evidence: synchronized class-level launcher evidence without moving ownership. The retained opener now emits first-draft `static void OpenChangePasswordDialog()` through `MainMenuPane.cpp`; this class owns the constructor and singleton side effect. The no-xref/no-pointer retained route caps confidence, not code eligibility, and the constructor publication through `g_pChangePasswordDialogPane` rejects a pointer-return opener.
- 2026-07-03 B003 [UID:0002XM][0x0069b48c-0x0069b490.g_pChangePasswordDialogPane](by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md) implementation callback:
  - Score unchanged at `85/89`.
  - Summary/evidence: updated the active singleton anchor so UID0002XM is source-ready with formal `ChangePasswordDialogPane *g_pChangePasswordDialogPane = (ChangePasswordDialogPane *)-1;` on the child page. Current MCP session `e63ee655` records exact range `0x0069b48c-0x0069b490`, size `0x4`, bytes `FF FF FF FF`, no function at the slot, current operand label `unk_69B48C`, and refs `0x004f69bf`, `0x004fdd96`, `0x004fdd9d`, `0x005023a0`, and `0x00502656`. The class keeps UID0000I3 as source route; MainMenuPane cleanup is a consumer, the mixed aggregate remains non-emitting, broad LoginDialogPane grouping is not the direct owner, and the B010 `c9ac3d5b` zero-byte aggregate correction remains a byte-confidence cap against current B003 `e63ee655` `FF` evidence.

## 2026-08-14 B003 Whole-File Source-Quality Callback

- Final source route: `NexusTK/login/ChangePasswordDialogPane.cpp` with matching `ChangePasswordDialogPane.h`; UID0000I3 is the sole emitter. The class formal owns the constructor, `OnControlCommand`, `UpdateActionButton`, `HandlePacketEvent`, `SubmitPasswordChange`, both reply methods, and the singleton `extern`.
- Exact source children: UID0002QA emits the five core methods; UID0002QB is the retained no-direct-route account-id sender; UID0002QC is the active three-field sender; UID0002QD is the packet-type-2 reply handler; UID0002QE is the retained no-direct-route simple reply handler; UID0002XM emits the singleton definition. UID00022W remains a non-emitting packet index, and UID0003HG plus the destructor helpers at `0x00502474`, `0x0050247f`, and `0x00502650` remain compiler-generated/non-emitting.
- The five source-facing core names and types are `ChangePasswordDialogPane::ChangePasswordDialogPane()`, `void ChangePasswordDialogPane::OnControlCommand(int controlIndex, int notifyCode)`, `void ChangePasswordDialogPane::UpdateActionButton()`, `bool ChangePasswordDialogPane::HandlePacketEvent(Event *event)`, and `void ChangePasswordDialogPane::SubmitPasswordChange()`. The accepted formal class declaration is authoritative for generated source; supervisor-only IDA rename/type/comment transactions remain separate.
- Constructor source behavior preserves both asset branches, controls `1` through `6`, old/new rectangles, masked password fields, center arithmetic using signed `short` screen globals, overlay-layer attachment, main-menu ordering, and vertical opening. Submit preserves the literal digit error text, localized mismatch text id `90`, dimmer creation, and active UID0002QC call.
- Three vtable views at `0x0061dd18`, `0x0061dd28`, and `0x0061dd3c`, COLs at `0x0060e14c`, `0x0060e168`, and `0x0060e184`, hierarchy/base descriptors, type descriptors, and vtable slots remain documentary compiler data rather than handwritten source children. Their established rows and xrefs are retained on this page and UID0002QA.
- Direct declarations are supplied by `DialogPane.h`, `Singleton.h`, `Event.h`, `RectBounds.h`, `ButtonControlPane.h`, `EPFImageControlPane.h`, `TextEditControlPane.h`, `AlertPanes.h`, `ScreenDimmer.h`, `ScreenPane.h`, `MainUiGraph.h`, `MainMenuPane.h`, `LanguageMan.h`, `Application.h`, `StartupWindow.h`, `PacketBuffer.h`, and `Socket.h`. C-runtime, Win32 conversion, and range-check declarations come from the four system headers in the formal CPP manifest.
- Scores advance from `85/89` to `91/92`: exact class/CPP formals and a closed dependency route materially improve reconstruction completeness, while original symbol spelling, retained-helper liveness, and supervisor-only IDA application remain bounded uncertainties.

- Before: the method inventory ended at `SubmitPasswordChange` and destructor-family entries.
- After: the inventory includes the adjacent password-change packet send/reply helpers in [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md).
- Why: IDA MCP shows `0x004fe9e0` is directly called by `SubmitPasswordChange`, and `0x004febf0` is the dispatcher target for password-change packet replies.
- Evidence: 2026-05-28 IDA MCP xrefs and decompiles for `0x004fe560`, `0x004fe9e0`, `0x004fe530`, and `0x004febf0`.

- What existed before: the page had strong password-dialog and packet-helper evidence, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `82/88`.
- Summary and evidence: constructor variants, validation, submit, send/reply packet helpers, menu launcher, and destructor family are documented; exact original file fold with login/account dialogs remains the main open item.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE` and attached the class to [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md). Current IDA MCP `lookup_funcs` reconfirmed constructor/action/validation/submit/send/reply/destructor starts at `0x004fdd40`, `0x004fe460`, `0x004fe490`, `0x004fe560`, `0x004fe9e0`, `0x004febf0`, and `0x00502650`, and `callers` shows the dialog constructor reached from main-menu/password launcher paths. Both class (`82/88`) and file (`80/84`) clear the 80+ attachment gate; reconstruction C++ remains blank pending final field names and source split.
