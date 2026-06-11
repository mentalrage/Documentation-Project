*** UID:0000OI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TerminalPane

## Status

- Confidence: strong for `TerminalPane` and `TerminalSetupPane` ownership, medium for the exact original split from phone-book support.
- Proposed module: `login/TerminalPane.cpp`
- Helper caveat: the stream parser and reconnect/leave callback are exact by-memory children, but their final source-facing helper names are still provisional.
- Evidence basis: live IDA MCP boundary/caller checks and linked by-* memory/class docs.

## File Role

`TerminalPane.cpp` owns the pre-login terminal connection pane and its serial/modem setup dialog. It is launched from `MainMenuPane::ActivateMenuItem`, sends initial connection/setup packets, handles disconnect and reconnect/leave decisions, and parses terminal-style byte streams from the connection layer.

This belongs under `login/` rather than generic UI because the pane is entered from the main menu before the normal game session and uses the same pre-login root pane/singleton lifecycle. It also has strong network coupling, but its ownership evidence is closer to login/startup UI than to the reusable packet or socket modules.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TerminalPane` | `0x0058af50-0x0058b5fb`, [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md), [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md), [UID:0001JK][0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks.md), [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md) | Full-screen terminal/reconnect pane, initial packet send, terminal stream parsing, disconnect alert, and close/destructor behavior. |
| `TerminalSetupPane` | `0x0058b650-0x0058c350` | `Terminal Setup` dialog for COM port and baud-rate settings, using `DLGSETUP.EPF` or `DLGSETUP.EPD`. |
| [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md) | `0x0069bdf8` | Active terminal pane singleton, also used as parent by phone-entry/dial dialogs. |
| [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md) | `0x004f91c0-0x004f927d` | Retained main-menu terminal launcher; keep in `MainMenuPane.cpp`, not this terminal implementation file. |
| Terminal packet helpers | callers only in this pass | Uses `SendCancelReconnect`, `SendCashShopRequest`, `SendConnectPacket`, modem command senders, disconnect senders, and terminal setup packet senders. |

## Evidence Notes

- IDA MCP confirms the TerminalPane constructor at `0x0058af50-0x0058b0ed`, [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md), disconnect handler at `0x0058b470-0x0058b5df`, close handler at `0x0058b5e0-0x0058b5fb`, [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md), TerminalSetupPane constructor/update/command block at `0x0058b650-0x0058c350`, and TerminalPane destructor/thunks in the later thunk island.
- IDA MCP callers on 2026-05-25 show the stream parser at `0x0058b130` calls [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md), tying terminal byte-stream handling to the same queued position/status upload used by reconnect flow.
- 2026-05-26 IDA MCP recheck: `0x0058b130` has only the `0x0062da80` data/vtable reference, and `0x0058b620` is stored from `TerminalPane::OnDisconnect` at `0x0058b56d`. Keep both helpers as exact by-memory children until their final source-facing names are settled.
- [UID:0001JI][0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md) is constructor unwind glue that clears [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md), not normal source logic.
- IDA MCP confirms [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md) contains a `TerminalPane::TerminalPane` call at `0x004f924f`, but direct xrefs to the launcher itself are currently unresolved.
- Earlier summaries framed this as terminal-style text output; current IDA evidence shows a broader pre-login network terminal/reconnect role.

## Split Notes

The adjacent phone-book and dial code is likely part of the same feature family. Current best migration split is:

```text
login/TerminalPane.cpp
login/PhoneBookDialog.cpp
```

If later symbol or linker-order evidence shows the original source was flatter, both files could collapse into a single `login/Terminal.cpp` or `login/TerminalPane.cpp`. Keep the split provisional until the phone-book helper ownership is cleaned up.

## Cross-References

- [UID:0000EG][TerminalPane](by-class/TerminalPane.md)
- [UID:0000EH][TerminalSetupPane](by-class/TerminalSetupPane.md)
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md)
- [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md)
- [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md)
- [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md)
- [UID:0001JK][0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks.md)
- [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md)
- [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md)
- [UID:00019S][0x004f91c0-0x004f927d.OpenTerminalPane](by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md)
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)

## Changes

- 2026-06-06: Synced reconnect/leave callback range and removed stale generated-source wording.
  - Before: the page linked [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) with the short `0x0058b620-0x0058b64e` filename and described generated-source omissions as current state.
  - After: updated links to [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md), described the stream parser/callback as exact by-memory children with provisional final names, and kept the score unchanged.
  - Evidence: live IDA MCP on 2026-06-06 confirms the callback's half-open `0x0058b620-0x0058b64f` range and callback-pointer store from `TerminalPane::OnDisconnect` at `0x0058b56d`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document captures pre-login terminal/setup role, proposed contents, singleton/global launcher notes, IDA boundary/caller evidence, stream parser/reconnect callback caveats, split notes, and cross-references; confidence remains capped by exact split from phone-book support.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `TerminalPane.cpp` under `login`; IDA MCP confirms the pre-login terminal/setup block and `g_pTerminalPane` lifecycle.
