*** UID:0000KX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# LoginDialogPane

## Status

- Confidence: very strong for complete `LoginDialogPane.cpp` contents/order, singleton/class/method/helper ownership, and compiler exclusions. Neighboring NewUserDialogPane and ChangePasswordDialogPane remain separate family pages/files and do not limit this file's route.
- Proposed module folder: `login/`
- Proposed source files: `login/LoginDialogPane.cpp`, `login/NewUserDialogPane.cpp`, and `login/ChangePasswordDialogPane.cpp`
- Current source route: position-0 global UID0000RE inserts exact storage definition UID0002XI, class UID00007F inserts seven source/coverage children at positions 10-60, and file-local UID00019L/UID0002Q5 retain their direct file routes. The former UID0002Q4 aggregate is a non-emitting index.
- Evidence basis: current by-* documentation, generated source readback, resumed bounded IDA MCP bytes/functions/xrefs/vtables, and executed direct-helper reports. Wave2/Wave3/simroot material is retained only as historical lead context where current evidence independently confirms it.

## Hypothesis

The login/account dialogs were probably part of a small `login/` source family. `LoginDialogPane` owns username/password entry and login reply handling. `NewUserDialogPane` is the older account-registration dialog. `ChangePasswordDialogPane` owns the password-change form. All three share the same dialog-control idiom, validation rules, alert/dimmer behavior, and main-menu instantiation path.

`SendLoginRequest` is now resolved as a private source-ready helper in `login/LoginDialogPane.cpp`; the password/new-user request helpers should remain near this family or in nearby account-dialog protocol-send files. `LoginDialogPane` calls [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) after a successful login, but the main UI graph bootstrap is project-level/game-UI setup and should not be owned by the login dialog.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `g_pLoginDialogPane` | [UID:0000RE][g_pLoginDialogPane](by-global/g_pLoginDialogPane.md) with exact storage [UID:0002XI][0x0069b484-0x0069b488.g_pLoginDialogPane](by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md) | `login/LoginDialogPane.cpp`, position 0 | One source-authored null-initialized external singleton definition; twelve refs cover cleanup/activation/ensure/constructor/unwind/clear/destructor lifetime. |
| `LoginDialogPane` | class [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md); reviewed index [UID:0002Q4][0x004fa7a0-0x004fb2d0.LoginDialogPaneCore](by-memory/0x004fa7a0-0x004fb2d0.LoginDialogPaneCore.md) | `login/LoginDialogPane.cpp`, positions 10-60 | Complete no-derived-field class declaration plus exact constructor UID0004PJ, unwind coverage UID0004PN, packet UID0004PQ, command UID0004PR, action updater UID0004PS, pointer/mouse UID0004PT, and destructor UID0004PU. Internal tables, padding, adjustor thunks, scalar flags, vptr/base/free mechanics do not emit source. |
| `NewUserDialogPane` | [UID:0002Q3][0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers](by-memory/0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers.md) non-emitting split index with exact source/compiler children, including routed destructor [UID:0004PO][0x00502970-0x005029e1.NewUserDialogPaneDestructor](by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md) | standalone `login/NewUserDialogPane.cpp` through [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) | Older account-registration dialog using `DLGNEW01.EPF`; exact constructor/destructor/event/command/button-state/submit/reply class children plus file-local [UID:0004PH][0x004fa3a0-0x004fa5a5.SendCreateAccountRequest](by-memory/0x004fa3a0-0x004fa5a5.SendCreateAccountRequest.md). It remains family-adjacent but is not owned by LoginDialogPane.cpp. |
| `ChangePasswordDialogPane` | `0x004fdd40-0x004fe781`, helper cluster [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md), destructor family `0x00502474-0x00502694` | `class_ChangePasswordDialogPane.cpp` | Change-password dialog with old/high-res asset branch, form validation, password-change packet send, and reply handling. |
| `EnsureLoginDialogPane` | [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) | private helper in `login/LoginDialogPane.cpp` | Ensures the login dialog singleton exists by checking `g_pLoginDialogPane` and constructing `LoginDialogPane` through source-level `new LoginDialogPane;`; recovered alias [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md). |
| `OpenChangePasswordDialog_4F9060` | `0x004f9060-0x004f90b4` | currently not emitted standalone | Retained helper that allocates and constructs `ChangePasswordDialogPane`; live reachability unresolved. |
| `SendLoginRequest` | [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) | private helper in `login/LoginDialogPane.cpp` | Source-ready login packet sender: serializes account/password text, config login challenge key/mask bytes, OS/window metadata, randomized challenge bytes, queues through `g_packetSender`, and updates the protected password token. Exact helper/config field names remain inferred. |

## Boundary Notes

- IDA confirms `LoginDialogPane` starts at `0x004fa7a0`, `0x004fab10`, `0x004fad00`, `0x004fae30`, and `0x004fae90`.
- Registered exact Login children are [UID:0004PJ][0x004fa7a0-0x004faacd.LoginDialogPaneConstructor](by-memory/0x004fa7a0-0x004faacd.LoginDialogPaneConstructor.md), [UID:0004PN][0x004faad0-0x004fab0f.LoginDialogPaneConstructorUnwindCleanup](by-memory/0x004faad0-0x004fab0f.LoginDialogPaneConstructorUnwindCleanup.md), [UID:0004PQ][0x004fab10-0x004face9.LoginDialogPaneHandlePacketEvent](by-memory/0x004fab10-0x004face9.LoginDialogPaneHandlePacketEvent.md), [UID:0004PR][0x004fad00-0x004fae22.LoginDialogPaneOnControlCommand](by-memory/0x004fad00-0x004fae22.LoginDialogPaneOnControlCommand.md), [UID:0004PS][0x004fae30-0x004fae88.LoginDialogPaneUpdateActionButton](by-memory/0x004fae30-0x004fae88.LoginDialogPaneUpdateActionButton.md), [UID:0004PT][0x004fae90-0x004fb2a6.LoginDialogPaneHandlePointerOrMouseEvent](by-memory/0x004fae90-0x004fb2a6.LoginDialogPaneHandlePointerOrMouseEvent.md), and [UID:0004PU][0x005027d0-0x00502841.LoginDialogPaneDestructor](by-memory/0x005027d0-0x00502841.LoginDialogPaneDestructor.md).
- 2026-06-07 live IDA MCP reconfirms the exact LoginDialogPane core functions at `0x004fa7a0-0x004faacd`, `0x004fab10-0x004face9`, `0x004fad00-0x004fae22`, `0x004fae30-0x004fae88`, and `0x004fae90-0x004fb2a6`, with the raw cleanup fragment at `0x004faad0-0x004fab0f`, local switch/table bytes at `0x004face9-0x004fad00` and `0x004fb2a6-0x004fb2d0`, and `0x004fb2d0` as the next function start.
- The same pass reconfirms `SendLoginRequest` at `0x004fb2d0-0x004fb62a`, one direct caller from `LoginDialogPane` command handling at `0x004fadbd`, and six bytes of `0xcc` padding before the next constructor at `0x004fb630`. B005's accepted UID0002Q5 pass refreshed this with MCP session `6eab6bcb`, rejected endpoint/raw-pointer routes and class/dependency ownership, and made the helper source-ready through [UID:0000KX].
- Login source order and behavior are resolved: null singleton definition; complete class shell; constructor resources/controls/centering; packet failure focus/conversion and ordered success transition; command account/password reads, independent config-gated pointer shifts, request/copy/ScreenDimmer order; action-button gate; pointer/drag/release/relay path; ordinary destructor; existing Ensure and Send helpers. Exact switch tables at `0x004face9` and `0x004fb2a6`, raw unwind mechanics, alignment, destructor adjustors, scalar delete flag, vptr/base teardown, and free/return mechanics are compiler output.
- IDA confirms `NewUserDialogPane` starts at `0x004f9d30`, `0x004fa120`, `0x004fa150`, and `0x004fa1d0`.
- 2026-06-01 IDA MCP corrects the active new-user/login core boundaries: `NewUserDialogPane` account-flow code continues through functions at `0x004fa3a0` and `0x004fa5b0` before padding to `0x004fa7a0`; `LoginDialogPane` core continues through switch-table/padding bytes to `0x004fb2d0`; `SendLoginRequest` ends at exclusive `0x004fb62a`.
- IDA confirms `ChangePasswordDialogPane` starts at `0x004fdd40`, `0x004fe460`, `0x004fe490`, and `0x004fe560`.
- 2026-05-28 IDA MCP confirms [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) continues the `ChangePasswordDialogPane` account-flow code with packet send/reply helpers adjacent to the UI methods.
- 2026-05-24 IDA confirms the helper at `0x004f9060` is not runtime/library code; it allocates `620` bytes and calls `ChangePasswordDialogPane::ChangePasswordDialogPane`.
- IDA confirms [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md) is called by [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) destructor paths at `0x005880db` and `0x0058ac52`.
- 2026-06-20 B001 source-quality recheck confirms [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) is ready for first-draft helper C++ under the current combined-score/emitter gate. The old blocker was the address-suffixed recovered name and broader account-dialog source split; current evidence supports `static void EnsureLoginDialogPane()` as a file-local login helper, while the account-dialog split remains a broader file-planning issue. [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md) now stays a non-emitting recovered-symbol alias so the helper body emits once.
- Generated `NewUserDialogPane` currently contains escaped `\!=` text in emitted C++ and must not be treated as compile-ready source until the materialization bug is fixed.

## Corrected Assignment Gate

This file page is `92/93` with validated `NexusTK/login/` placement and complete `LoginDialogPane.cpp` inventory. It directly owns class UID00007F, global UID0000RE, and file-local Ensure/Send helpers; exact storage and method children route through those owners. Receiver/vtables/resources/singleton/callers and source ordering exclude MainMenuPane, DialogPane, a combined account-dialog file, or a new helper file. Separate neighboring account dialogs retain their own accepted source routes.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `92` | Exact folder/file, singleton/class/children/helpers, positions/order, behaviors, boundaries, neighboring file separation, compiler exclusions, rejected alternatives, and generated policy are resolved. |
| Confidence | `93` | Bounded IDA, exact source children, current class/global/file docs, callers/vtables/resources, and existing helper routes are very strong; stripped original file-manifest and lexical spellings remain bounded uncertainty. |

## Cross-References

- [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md)
- [UID:0000RE][g_pLoginDialogPane](by-global/g_pLoginDialogPane.md)
- [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md)
- [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md)
- [UID:00009D][NewUserDialogPane](by-class/NewUserDialogPane.md)
- [UID:00001L][ChangePasswordDialogPane](by-class/ChangePasswordDialogPane.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) Change-password packet helper cluster
- [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md)
- [UID:0004PJ][0x004fa7a0-0x004faacd.LoginDialogPaneConstructor](by-memory/0x004fa7a0-0x004faacd.LoginDialogPaneConstructor.md)
- [UID:0004PN][0x004faad0-0x004fab0f.LoginDialogPaneConstructorUnwindCleanup](by-memory/0x004faad0-0x004fab0f.LoginDialogPaneConstructorUnwindCleanup.md)
- [UID:0004PQ][0x004fab10-0x004face9.LoginDialogPaneHandlePacketEvent](by-memory/0x004fab10-0x004face9.LoginDialogPaneHandlePacketEvent.md)
- [UID:0004PR][0x004fad00-0x004fae22.LoginDialogPaneOnControlCommand](by-memory/0x004fad00-0x004fae22.LoginDialogPaneOnControlCommand.md)
- [UID:0004PS][0x004fae30-0x004fae88.LoginDialogPaneUpdateActionButton](by-memory/0x004fae30-0x004fae88.LoginDialogPaneUpdateActionButton.md)
- [UID:0004PT][0x004fae90-0x004fb2a6.LoginDialogPaneHandlePointerOrMouseEvent](by-memory/0x004fae90-0x004fb2a6.LoginDialogPaneHandlePointerOrMouseEvent.md)
- [UID:0004PU][0x005027d0-0x00502841.LoginDialogPaneDestructor](by-memory/0x005027d0-0x00502841.LoginDialogPaneDestructor.md)

## Changes

- 2026-07-14 B005 UID0002Q4 callback: rebased after B004's UID0002Q3 changes and preserved the complete standalone NewUserDialogPane row, exact B004 child/helper/destructor links, neighboring ChangePassword content, folder path, and all unrelated history. Raised this Login file page from `88/86` to `92/93`; added the exact position-0 null singleton route, complete no-field class and seven positions 10-60 source/coverage children, current method names/behaviors, three-view vtable ownership, two constructor callers, existing Ensure/Send helper placement, compiler table/padding/unwind/thunk/scalar exclusions, and rejected aggregate/MainMenu/base/new-file alternatives. Historical Wave/simroot and stale method/mode/wait/global claims remain labeled lead/superseded rather than current authority.
- 2026-07-14 B004 UID0002Q3 implementation callback: Replaced only the stale `class_NewUserDialogPane.cpp` family row with the resolved standalone `login/NewUserDialogPane.cpp` route, exact split/destructor/helper links, and retained family boundary; all Login/B005 content, scores, and formal state remain unchanged.
- 2026-06-05: Filled `PROPOSED_RECONSTRUCTION_PATH` with `NexusTK/login/`.
  - Reason: `by-project-structure/proposed-source-tree.md` already places `LoginDialogPane.cpp` under login, and the linked IDA-backed login/account dialog boundaries plus `EnsureLoginDialogPane_4F8B30` constructor evidence support this source owner. This also makes the file root valid for child autogen attachment; completion/confidence scores were not changed.
- Before: the proposed contents represented `ChangePasswordDialogPane` with only `0x004fdd40-0x004fe781`.
- After: the proposed contents include [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) as the adjacent packet send/reply helper cluster for the same dialog family.
- Why: IDA MCP ties `0x004fe9e0` to `SubmitPasswordChange` and `0x004febf0` to the local password-change reply dispatcher.
- Evidence: 2026-05-28 IDA MCP xrefs and decompiles for `0x004fe560`, `0x004fe9e0`, `0x004fe530`, and `0x004febf0`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: login/new-user/change-password ownership, helper functions, packet helpers, boundary notes, generated source caveat, and account-flow cross-references are documented; confidence is capped by exact split among smaller account dialog `.cpp` files.
- 2026-06-07 A006 Batch006 parent-gate pass:
  - Changed completion/confidence from `86/82` to `88/86`.
  - Evidence: live IDA MCP reconfirmed the exact LoginDialogPane core functions and raw cleanup/table islands, `SendLoginRequest`'s single caller from the login command handler, request-helper bounds/padding, constructor resource/global/vtable refs, and proposed-source-tree `login/LoginDialogPane.cpp` placement.
  - Assignment scope: this page is a valid direct parent for [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md) and the file-local request helper; the broader account-dialog source split remains open, but UID0002Q5 is no longer blocked by that caveat.
- 2026-06-20 B001 EnsureLoginDialogPane source-quality execution:
  - Score unchanged at `88/86`.
  - Summary/evidence: [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) now emits first-draft `static void EnsureLoginDialogPane()` through this file. B001 resolved the helper as a login-file singleton ensure routine, documented `0x004f4aa0(620)` as compiler output for `new LoginDialogPane`, preserved forced-inform destructor calls as caller context only, and reframed [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md) as a non-emitting recovered-symbol alias to avoid duplicate helper definitions.
- 2026-07-04 B005 UID0002Q5 implementation callback:
  - Score unchanged at `88/86`.
  - Summary/evidence: [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) now emits first-draft `static void __stdcall SendLoginRequest(const wchar_t* accountName, const wchar_t* password)` through this file. The support sync preserves the account-dialog split caveat while recording that it does not block this exact helper; the old recovered `SendLoginRequest_004FB2D0` route is historical only.
