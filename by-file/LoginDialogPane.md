*** UID:0000KX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LoginDialogPane

## Status

- Confidence: strong for `LoginDialogPane` core ownership, `SendLoginRequest` file-local ownership, `NewUserDialogPane`, and `ChangePasswordDialogPane` account-dialog placement; medium-high for whether the smaller account dialogs were separate `.cpp` files or one login-account module.
- Proposed module folder: `login/`
- Proposed source files: `login/LoginDialogPane.cpp`, `login/NewUserDialogPane.cpp`, and `login/ChangePasswordDialogPane.cpp`
- Current generated sources: `class_LoginDialogPane.cpp`, `class_NewUserDialogPane.cpp`, `class_ChangePasswordDialogPane.cpp`, plus recovered login request helpers.
- Evidence basis: Wave3 inspection, generated `simroot_v2` source, IDA MCP function-boundary checks, and Wave2 notes in `by-memory/-report.md`.

## Hypothesis

The login/account dialogs were probably part of a small `login/` source family. `LoginDialogPane` owns username/password entry and login reply handling. `NewUserDialogPane` is the older account-registration dialog. `ChangePasswordDialogPane` owns the password-change form. All three share the same dialog-control idiom, validation rules, alert/dimmer behavior, and main-menu instantiation path.

`SendLoginRequest` and the password/new-user request helpers should remain near this family or in a nearby protocol-send file. `LoginDialogPane` calls [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) after a successful login, but the main UI graph bootstrap is project-level/game-UI setup and should not be owned by the login dialog.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `LoginDialogPane` | [UID:0002Q4][0x004fa7a0-0x004fb2d0.LoginDialogPaneCore](by-memory/0x004fa7a0-0x004fb2d0.LoginDialogPaneCore.md), destructor family `0x005024cc-0x00502840` | `class_LoginDialogPane.cpp` | Login dialog UI, credential entry, login request dispatch, login result handling, switch-table tail, and success handoff. |
| `NewUserDialogPane` | [UID:0002Q3][0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers](by-memory/0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers.md), destructor family `0x0050250e-0x005029e0` | `class_NewUserDialogPane.cpp` | Older account-registration dialog using `DLGNEW01.EPF`; validates digit-containing password/confirmation and includes the new-user packet send/reply helpers. |
| `ChangePasswordDialogPane` | `0x004fdd40-0x004fe781`, helper cluster [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md), destructor family `0x00502474-0x00502694` | `class_ChangePasswordDialogPane.cpp` | Change-password dialog with old/high-res asset branch, form validation, password-change packet send, and reply handling. |
| `EnsureLoginDialogPane_4F8B30` | `0x004f8b30-0x004f8b8d` | `recovered/EnsureLoginDialogPane_004F8B30.cpp` | Opens a login dialog if the singleton is missing. |
| `OpenChangePasswordDialog_4F9060` | `0x004f9060-0x004f90b4` | currently not emitted standalone | Retained helper that allocates and constructs `ChangePasswordDialogPane`; live reachability unresolved. |
| `SendLoginRequest` | [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) | `recovered/SendLoginRequest_004FB2D0.cpp` | Builds and queues the login packet from account and password text. |

## Boundary Notes

- IDA confirms `LoginDialogPane` starts at `0x004fa7a0`, `0x004fab10`, `0x004fad00`, `0x004fae30`, and `0x004fae90`.
- 2026-06-07 live IDA MCP reconfirms the exact LoginDialogPane core functions at `0x004fa7a0-0x004faacd`, `0x004fab10-0x004face9`, `0x004fad00-0x004fae22`, `0x004fae30-0x004fae88`, and `0x004fae90-0x004fb2a6`, with the raw cleanup fragment at `0x004faad0-0x004fab0f`, local switch/table bytes at `0x004face9-0x004fad00` and `0x004fb2a6-0x004fb2d0`, and `0x004fb2d0` as the next function start.
- The same pass reconfirms `SendLoginRequest` at `0x004fb2d0-0x004fb62a`, one direct caller from `LoginDialogPane` command handling at `0x004fadbd`, and six bytes of `0xcc` padding before the next constructor at `0x004fb630`.
- IDA confirms `NewUserDialogPane` starts at `0x004f9d30`, `0x004fa120`, `0x004fa150`, and `0x004fa1d0`.
- 2026-06-01 IDA MCP corrects the active new-user/login core boundaries: `NewUserDialogPane` account-flow code continues through functions at `0x004fa3a0` and `0x004fa5b0` before padding to `0x004fa7a0`; `LoginDialogPane` core continues through switch-table/padding bytes to `0x004fb2d0`; `SendLoginRequest` ends at exclusive `0x004fb62a`.
- IDA confirms `ChangePasswordDialogPane` starts at `0x004fdd40`, `0x004fe460`, `0x004fe490`, and `0x004fe560`.
- 2026-05-28 IDA MCP confirms [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) continues the `ChangePasswordDialogPane` account-flow code with packet send/reply helpers adjacent to the UI methods.
- 2026-05-24 IDA confirms the helper at `0x004f9060` is not runtime/library code; it allocates `620` bytes and calls `ChangePasswordDialogPane::ChangePasswordDialogPane`.
- IDA confirms [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md) is called by [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) destructor paths at `0x005880db` and `0x0058ac52`.
- Generated `NewUserDialogPane` currently contains escaped `\!=` text in emitted C++ and must not be treated as compile-ready source until the materialization bug is fixed.

## Corrected Assignment Gate

This file page now clears the corrected direct-parent gate for the `LoginDialogPane` class and the file-local [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) helper: this page is `88/86`, has validated `NexusTK/login/` placement, and has live IDA evidence tying the constructor, virtual handlers, request helper, resources, singleton slot, and main-menu/ensure callers to the login/account source family. This does not close the broader account-dialog split question; smaller dialogs may still stay in adjacent `login/*.cpp` files, so final C++ remains blank on child pages.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `88` | The page records the proposed login folder, account-dialog family split, exact LoginDialogPane core child, exact `SendLoginRequest` helper, constructor/handler/request boundaries, related new-user and password-change children, generated-source caveat, and assignment-gate scope. |
| Confidence | `86` | Live IDA confirms the LoginDialogPane core, request helper caller, vtable/data/resource/global evidence, and proposed-source-tree placement. Confidence remains below final audit because the original split among small account dialog files is still partly unresolved. |

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

## Changes

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
  - Assignment scope: this page is now a valid direct parent for [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md) and the file-local request helper, but the broader account-dialog source split remains open and no final C++ is emitted.
