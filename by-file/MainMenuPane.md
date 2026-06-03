*** UID:0000L0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MainMenuPane

## Status

- Confidence: strong for `MainMenuPane` behavior; medium for final folder name.
- Proposed module folder: `login/`
- Proposed source file: `login/MainMenuPane.cpp`
- Current generated source: `source-3/simroot_v2/class_MainMenuPane.cpp`
- Evidence basis: Wave3 class inspection, generated `simroot_v2` source, existing Wave2 notes in `by-memory/-report.md`, and IDA MCP boundary checks on 2026-05-23.

## Hypothesis

`MainMenuPane` is the login-screen menu controller. It paints the initial menu, handles mouse/key navigation, processes pre-login server messages, and dispatches selected menu items into login, account creation, password change, story/history viewing, terminal, or shutdown flows.

The constructor also optionally loads `LEVEL.BMP` through a file-buffer path and decodes it with the shared [UID:000175][0x004d05f0-0x004d0c58.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0c58.ImageDecodeWrappers.md) at `0x004d09b0`; the decoded tile context is login-screen presentation state, while the decode wrapper stays with [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md).

The likely original source was a small standalone login UI file rather than part of generic UI core:

```text
login/MainMenuPane.cpp
login/MainMenuPane.h
```

It should include declarations for the account/login dialog classes it instantiates, but those dialog implementations should stay in their own nearby files.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `MainMenuPane` | `0x004f6700-0x004f7ce8`, destructor family `0x005024e2-0x00502918` | `class_MainMenuPane.cpp` | Login-screen menu pane, input handling, server-message handling, paint, timer, and menu activation. |
| `BackStoryDialogPane` | `0x00500090-0x0050040d`, destructor support at `0x00502390`, `0x0050245e`, `0x00502469`, `0x00502600` | `class_BackStoryDialogPane.cpp` | Older/main-menu story text dialog using `STORY.EPF`/`STORY.EPD` and `BACKTALE`; likely sibling file in the login menu family. |
| `HistoryViewingPane` | `0x004ffd80-0x0050008b`, destructor support at `0x005023b0`, `0x005024b6`, `0x005024c1`, `0x00502760` | `class_HistoryViewingPane.cpp` | Full-screen story/history frame viewer constructed directly by main-menu story/history actions. |
| `NewHistoryDialogPane` | `0x00500410-0x00500632`, destructor support at `0x005023e0`, `0x005024f8`, `0x00502503`, `0x00502920` | `class_NewHistoryDialogPane.cpp` | Full-screen `HISTORYN.EPF` / `MADEBY` history-credits dialog; exact live entry path remains open. |
| `StaffsDialogPane` | `0x004ffaa0-0x004ffd3d`, destructor support at `0x00502410`, `0x00502592`, `0x0050259d`, `0x00502cc0` | `class_StaffsDialogPane.cpp` | Main-menu staff/credits dialog using `STAFF.EPF` and `STAFFS`/`STAFFS2`; likely sibling file in the login menu family. |
| `ForcedInformMessageDialog` | `0x00587bb0-0x005881ed`, destructor support at `0x0058aa90`, `0x0058aadb`, `0x0058aae6`, `0x0058abf0` | `class_ForcedInformMessageDialog.cpp` | Mandatory accept/decline information dialog that is cleaned by main-menu singleton cleanup and can reopen the login dialog on accepted teardown. |
| `CloseMainMenuDialogSingletons_4F69A0` | `0x004f69a0-0x004f6a31` | `recovered/CloseMainMenuDialogSingletons_004F69A0.cpp` | File-local/main-menu cleanup helper for open pre-login dialogs and the history viewer. |
| `ComputeMenuItemRect_4F8B90` | `0x004f8b90-0x004f8c07` | `recovered/ComputeMenuItemRect_004F8B90.cpp` | Main-menu item rectangle helper used by input and paint. |
| `HitTestMenuItem_4F8C10` | `0x004f8c10-0x004f8cfa` | generated prototype only | Main-menu mouse hit-test helper used by `OnMouseEvent`. |
| `HandleLegacyMainMenuPacket_4F8D00` | `0x004f8d00-0x004f8f02` | generated prototype only | Pre-login server-message opcode `3` helper; queues follow-up packet and requests `Meta.dat` sync. |
| `OpenTransferServerDialog_4F8F10` | `0x004f8f10-0x004f8f95` | currently not emitted standalone | Retained transfer-server overlay launcher; cancels a timer/player-state hook and constructs `TransferServerDialogPane` if the singleton is absent. |
| `OpenCreateUserDialog_4F8FA0` | `0x004f8fa0-0x004f9055` | currently not emitted standalone | Retained create-user dialog launcher selecting old/new create-user UI by layout flag; live reachability unresolved. |
| `OpenChangePasswordDialog_4F9060` | `0x004f9060-0x004f90b4` | currently not emitted standalone | Retained password-change dialog launcher; current IDA runtime-style name is misleading. |
| `OpenStoryViewingPane_4F90C0` | `0x004f90c0-0x004f913f` | currently not emitted standalone | Retained helper that allocates `HistoryViewingPane` for `STORY.EPF`/`STORY.EPD`; live reachability unresolved. |
| `OpenHistoryViewingPane_4F9140` | `0x004f9140-0x004f91bf` | currently not emitted standalone | Retained helper that allocates `HistoryViewingPane` for `HISTORY.EPF`/`HISTORY.EPD`; live reachability unresolved. |
| `OpenTerminalPane_4F91C0` | `0x004f91c0-0x004f927d` | currently not emitted standalone | Retained terminal launcher that performs pre-terminal packet cleanup and constructs `TerminalPane`; live reachability unresolved. |
| `PreparePatchLaunch_502E10` | `0x00502e10-0x00502e21` | `class_MainMenuPane.cpp` prototype only | Out-of-range main-menu server-message helper that tears down the active [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md) before pre-login patch/info handling. |
| `HandleAnsiTextDialogPacket_502E30` | `0x00502e30-0x0050305c` | `class_MainMenuPane.cpp` prototype only | Opcode `0x66` main-menu packet helper; parses counted ANSI fields and creates [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md) prompts or stores decoded text. |

## Key Behavior

- `ActivateMenuItem` at `0x004f7a10` constructs `CreateUserDialogPane`, `LoginDialogPane`, `ChangePasswordDialogPane`, `HistoryViewingPane`, `TerminalPane`, or requests application exit depending on the selected menu index.
- IDA confirms `ActivateMenuItem` calls the login/account constructors at `0x004fa7a0`, `0x004fdd40`, `0x0052a540`, and `0x0052dd30`.
- IDA confirms `ActivateMenuItem` calls `HistoryViewingPane::HistoryViewingPane` four times, selecting `STORY.EPF`/`STORY.EPD` for the story menu item and `HISTORY.EPF`/`HISTORY.EPD` for the history menu item.
- IDA confirms `ComputeMenuItemRect_4F8B90` is called from `OnMouseEvent`, `OnKeyEvent`, and `OnPaint`.
- IDA confirms `HitTestMenuItem_4F8C10` is called only from `OnMouseEvent` and uses the same menu rectangle constants as `ComputeMenuItemRect_4F8B90`.
- IDA confirms `HandleLegacyMainMenuPacket_4F8D00` is called only from `OnServerMessage` when pre-login opcode `3` is received.
- IDA confirms `OpenCreateUserDialog_4F8FA0` and `OpenTerminalPane_4F91C0` are real retained launch helpers, but direct caller/xref lookup currently returns none.
- 2026-06-01 IDA MCP confirms `OpenTransferServerDialog_4F8F10` is a real retained helper between `HandleLegacyMainMenuPacket_4F8D00` and `OpenCreateUserDialog_4F8FA0`; it calls timer helper `0x00597a10`, allocates `0x100`, and constructs `TransferServerDialogPane` at `0x00598ed0`, with no direct caller/xref found.
- 2026-05-24 IDA confirms `OpenChangePasswordDialog_4F9060` is a real retained launch helper that allocates `620` bytes and calls `ChangePasswordDialogPane::ChangePasswordDialogPane`; direct caller/xref lookup currently returns none.
- IDA confirms `OpenStoryViewingPane_4F90C0` and `OpenHistoryViewingPane_4F9140` are real functions that allocate `HistoryViewingPane`, but direct caller/xref lookup currently returns none.
- 2026-05-27 IDA raw-pointer scan across loaded segments found no dwords equal to `0x004f9060`, `0x004f90c0`, or `0x004f9140`; keep these as retained helpers with weak live reachability until a stronger indirect-call source is found.
- 2026-05-28 IDA MCP confirms `MainMenuPane::OnServerMessage` calls [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md) at `0x004f733a` and `0x004f74c2`; local `simroot_v2` routes opcode `0x66` to `HandleAnsiTextDialogPacket_502E30`.
- The main menu destructor calls the dialog-singleton cleanup helper and stops menu music.
- `OnServerMessage` is a pre-login message handler, not an in-game session dispatcher; it belongs with the main menu/login UI.

## Migration Notes

Keep this file separate from [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md). `MainMenuPane` owns dispatch and presentation of the top-level menu, while the login/create/password dialogs own their own controls and packet senders.

Keep [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) as a nearby login/main-menu dialog module. It is cleaned by the main-menu singleton cleanup helper, but its direct constructor reachability still needs review.

Keep [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) as a nearby login/main-menu pane module. Unlike `BackStoryDialogPane`, it has direct `MainMenuPane::ActivateMenuItem` constructor call sites and owns the frame-sequence story/history viewer.

Keep [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md) in the same login/main-menu family. IDA does not currently show a direct constructor caller, but the `HISTORYN.EPF`/`MADEBY` resources and `g_pMainMenuPane` parent path are pre-login/menu evidence.

Keep [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md) in the same login/main-menu family. IDA does not currently show a direct constructor caller, but the resource names and `g_pMainMenuPane` parent path are pre-login/menu evidence.

Keep [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) in the login/main-menu family. It is address-adjacent to system-message panes, but its singleton is read by main-menu cleanup and its destructor uses `EnsureLoginDialogPane_4F8B30`.

Keep [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md), [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md), [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md), and [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md) as retained `MainMenuPane.cpp` launch helpers unless a later xref pass proves they are callback targets owned elsewhere. Their constructor targets remain in [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md), [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md), [UID:0000OI][TerminalPane](by-file/TerminalPane.md), and [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md).

Possible Wave3 migration sequence after caveats are reviewed:

```powershell
python source-3\wave3.py create file MainMenuPane.cpp --kind source --simpath login/MainMenuPane.cpp --dry-run
python source-3\wave3.py attach class MainMenuPane --to-file MainMenuPane.cpp
```

Do not attach `LoginDialogPane` or create-user classes to this file except as forward declarations.

## Cross-References

- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:000175][0x004d05f0-0x004d0c58.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0c58.ImageDecodeWrappers.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md)
- [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md)
- [UID:0000T1][HitTestMenuItem_4F8C10](by-global/HitTestMenuItem_4F8C10.md)
- [UID:0000SZ][HandleLegacyMainMenuPacket_4F8D00](by-global/HandleLegacyMainMenuPacket_4F8D00.md)
- [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md)
- [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md)
- [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md)
- [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md)
- [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md)
- [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md)
- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: login-screen menu role, proposed contents, menu activation behavior, retained launch helpers, packet helpers, sibling dialog placement, migration notes, and broad cross-references are documented; confidence is capped by final folder naming and retained-helper reachability questions.
