*** UID:00000Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID00000Z BoardListDialog class-level source is covered by UID0000HT BoardDialogs and the exact emitting child UID0002EJ BoardListDialogCore. This page emits no standalone partial class declaration until the board dialog hierarchy and header/source split are finalized.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BoardListDialog

## Status

- Disposition: reconstructable NexusTK project dialog class.
- Confidence: strong for behavior, vtable identity, board-dialog module placement, command callback ABI, selected-board packet layout, current source-facing helper/global names, and first-draft method C++ on the exact core child; capped below final because exact original field/helper spellings remain inferred.
- Parent source bucket: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Core memory: [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md)
- Destructor companion: [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md) is shared compiler-emitted destructor glue, not handwritten class logic.
- Address range parent: [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- Vtable family: [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- Autogen status: attached to the `BoardDialogs` file bucket. This class page remains a class/owner summary, while first-draft source-shaped method C++ now lives on [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md). The old blocker that field names were too unresolved for the child C++ is superseded.

## Class Purpose

`BoardListDialog` presents selectable bulletin-board categories parsed from server packet data. It creates the board-list controls, tracks the selected board, sends the board-selection request, and updates button state when selection changes.

## Class Shape

- Base family: board/article `BulletinDialog` descendant in the `DialogInSession` stack.
- Vtable identity: constructor stores the three `BoardListDialog` table views at object offsets `0x0`, `0xa0`, and `0xa4`.
- Owned controls: builds the board-list pane and command controls; the sibling [UID:000010][BoardListPane](by-class/BoardListPane.md) double-click/activation path calls back into `BoardListDialog::OpenSelectedBoard`.
- Control/session fields: the exact source spelling is inferred, but the roles are now bounded. `this + 0x1fc` is the inherited dialog control host used to resolve control ids `1`, `2`, and `3`; `this + 0x270` is the inherited `DialogInSession` session pointer, locally best modeled as a `BulletinSession`/`DialogSession` pointer.
- Network role: serializes the selected board request through `Socket *g_packetSender`, using `g_useEpfAssets` for the mode byte and `g_pUserPane + 0x214` for the active dialog host-pane route after send.
- Source placement: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), with the exact core method band split into [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `BoardListDialog` | `0x00472070-0x00472869` | Parses board-list packet data, installs three class vtables, creates the board-list pane, and builds command controls. |
| `OnCommand(int commandId, int unusedNotifyCode)` | `0x00472870-0x00472898` | Vtable slot `0x00613c90`; raw callback returns with `retn 8`, uses command `1` to call `OpenSelectedBoard`, and uses command `2` to call `DialogSession::CloseAllDialogs` through `this + 0x270`. |
| `OpenSelectedBoard` | `0x004728a0-0x00472999` | Reads selected row state from control id `3`, serializes opcode `0x3b` / subcommand `0x02` selected-board packet length `7`, updates `g_pUserPane + 0x214` and session `+0x100` dialog-transition state, and is also reached from the pane double-click callback. |
| `UpdateButtonState` | `0x004729a0-0x004729dd` | Vtable slot `0x00613c94`; resolves open button id `1` and list id `3`, calls `ListPane::GetSelectionCount`, and enables/disables the open button from current selection state. |
| title-copy helper | `0x0049db30-0x0049db5d` | Small helper called from the constructor at `0x0047217b` and `0x0047250d`; keep outside the exact core child range until final file layout is settled. |
| shared scalar deleting destructor | [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md) | Non-emitting MSVC wrapper shared through bulletin/board/article dialog vtables; source reconstruction should express the class hierarchy and let the compiler regenerate it. |

## Evidence Notes

- 2026-06-03 restarted IDA MCP confirms function boundaries `0x00472070-0x00472869`, `0x00472870-0x00472898`, `0x004728a0-0x00472999`, `0x004729a0-0x004729dd`, and title helper `0x0049db30-0x0049db5d`.
- The same IDA pass confirms `0xcc` alignment gaps at `0x00472869-0x00472870`, `0x00472898-0x004728a0`, `0x00472999-0x004729a0`, and `0x004729dd-0x004729e0`; IDA has no function at `0x004729dd` or `0x004729e0`.
- Vtable evidence is direct: constructor xrefs store `0x00613c48`, `0x00613cac`, and `0x00613cdc` at `0x004720cd`, `0x004720d3`, and `0x004720dd`; vtable dwords `0x00613c90` and `0x00613c94` target `0x00472870` and `0x004729a0`.
- Live xrefs show the constructor reached from bulletin-session code at `0x00471604` and `0x00471921`, and `OpenSelectedBoard` reached both from `OnCommand` at `0x0047288f` and from the board-list pane callback at `0x00472b5e`.
- Callee evidence anchors behavior: the constructor calls `0x004a1400`, `0x0049db30`, list/control helpers, and board-list pane/control constructors; `OpenSelectedBoard` calls selected-row extraction `0x004f3dc0`, packet writers `0x00575380`/`0x005753a0`/`0x00574bb0`, and session/dialog update helper `0x004a12b0`.
- 2026-06-10 B001-025 recheck confirms [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md) is now `85/88`, this class is the direct owner, and [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md) covers the shared non-emitting scalar deleting destructor companion.
- The class should stay in the board/article dialog family rather than generic list-pane or packet code because vtables, constructor callers, owned pane activation, and source bucket all point to `BoardDialogs`.
- 2026-06-23 B004 MCP-backed source-quality recheck in session `80de0a67` raises the core child to `88/90` and resolves the old code-entry blockers. Current evidence names the old raw/global/helper dependencies as `g_useEpfAssets`, `g_packetSender`, `g_pUserPane`, `DialogSession::CloseAllDialogs`, `CreateScreenDimmer`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `ListPane::GetItem`, and `ListPane::GetSelectionCount`. The raw/generated names `byte_66DA97`, `dword_67A7EC`, `dword_67A748`, `g_useHighResLayout`, `g_pNetworkManager`, `g_pPlayerData`, `CloseSession`, and `DialogInSession::TransitionState` remain useful search aliases only.
- Packet facts are now class-level source evidence: opcode `0x3b`, subcommand `0x02`, selected board id big-endian u16, sentinel `0x7fff`, mode byte `0xec` when `g_useEpfAssets == 1` else `0xf0`, eight-byte local scratch buffer, and explicit send length `7`.

## Score Rationale

Completion is raised to `88` because the page now records the exact core child, direct file parent, constructor callers, vtable stores, virtual slots, packet/open behavior, sibling pane callback, title helper, shared destructor companion, source-facing helper/global names, and first-draft method C++ readiness on the child. Confidence rises to `90` because current MCP session `80de0a67` confirms the function boundaries, padding, vtable slots, constructor callers, BoardListPane activation xref, helper routes, and packet constants. Confidence remains below final because exact original field spellings for the control host, session transition flag, and active-dialog host field remain inferred.

## Remaining Confidence Caps

- Exact original spellings for `m_controls`/`GetControl`, `m_session`, `m_dialogTransitionPending`, `m_activeDialogHostPane`, and `BoardListEntry` remain inferred. These are documented caps, not blockers for the accepted child first-draft C++.
- The original source split between a compact `BoardDialogs.cpp`, a separate `ArticleDialogs.cpp`, and shared alert files is still a file-parent-level caveat; it does not move this class away from the current [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) source-family route.
- The class page does not emit a standalone declaration yet. Method-body emission for this accepted pass belongs to [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md).

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:000010][BoardListPane](by-class/BoardListPane.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)
- [UID:00001C][BulletinDialog](by-class/BulletinDialog.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md)

## Changes

- 2026-06-23 B004 accepted source-quality implementation:
  - Before: the class remained `85/88` and described final field names/source-quality C++ as unresolved blockers.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`; owner/emitter remain [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md). The exact method-body C++ is emitted from [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md), while this class page carries the class-level route and field/global/helper interpretation.
  - Summary/evidence: B004 MCP session `80de0a67` confirms the command callback `retn 8` two-argument shape, command ids `1`/`2`, constructor callers, vtable slots, BoardListPane activation callback, selected-board packet `0x3b`/`0x02` length `7`, `g_useEpfAssets`/`g_packetSender`/`g_pUserPane` dependencies, `DialogSession::CloseAllDialogs`, and `CreateScreenDimmer`. Generated aliases are retained only as superseded search leads.
- What existed before: the page documented purpose, methods, placement, and references, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `70/84`.
- Summary and evidence: the page has strong BoardDialogs placement, method boundaries, and by-memory references, but it is not 100% complete because class layout, final C++ declaration, and exact field names are not fully recovered here.
- 2026-06-03:
  - Before: class remained at `70/84`, had no autogen parent/reconstructable marker, and lacked a fresh IDA evidence map.
  - After: scored as `78/88`, marked reconstructable, and attached to [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
  - Summary/evidence: restarted IDA MCP confirms exact function boundaries, padding, three class vtable stores, virtual slots `0x00613c90`/`0x00613c94`, title-helper xrefs, constructor callers, and the board-list pane activation call into `OpenSelectedBoard`; class-level output is marker-only pending final field names and class-layout recovery.
- 2026-06-10 B001-025:
  - Before: the class remained `78/88`, blocking strict assignment of its `85`-ready child.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`; parent remains [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
  - Summary/evidence: B001 re-audit connected the exact core child, vtable/caller evidence, pane activation callback, and shared scalar deleting destructor companion. Remaining source C++ and field-name uncertainty no longer blocks the class from serving as a direct parent.
