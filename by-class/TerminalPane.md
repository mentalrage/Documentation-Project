*** UID:0000EG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TerminalPane

## Status

- Confidence: strong for class role, medium for unmodeled helper ownership.
- Likely source file: [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- Primary address range: [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md)
- Current recovered file: `source-3/simroot_v2/class_TerminalPane.cpp`

## Class Purpose

`TerminalPane` is the pre-login terminal connection pane. It installs a full-screen hidden dialog over the root pane, cancels stale reconnect state, sends cash-shop/session connection packets, initializes modem/serial state, handles disconnect alerts, and owns the reconnect/leave callback flow.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `TerminalPane` | `0x0058af50` | Constructs the full-screen terminal dialog, sets [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md), sends initial reconnect/cashshop/connect/modem reset packets, and starts the terminal timer. |
| Terminal stream parser | [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) | IDA-confirmed helper parsing incoming terminal bytes/escape states; not currently emitted in `class_TerminalPane.cpp`. Calls [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md) on the current IDA path. |
| `OnDisconnect` | `0x0058b470` | Sends disconnect/cashshop cleanup, closes transient alert, and optionally shows reconnect/leave prompt. |
| `OnClose` | `0x0058b5e0` | Hides the pane and invalidates its region. |
| Reconnect/leave callback | [UID:0001JD][0x0058b620-0x0058b64e.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64e.TerminalPaneReconnectLeaveCallback.md) | Callback used by the reconnect/leave alert; reconnect branch restarts terminal timer, leave branch exits through the application path. |
| Thunks/destructor | [UID:0001JK][0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks.md), `0x0058dc60` | Compiler adjustor thunks and scalar deleting destructor; destructor clears [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md). |

## Evidence Notes

- Wave3 class summary is too narrow: this class is not just text output, it is the terminal connection/reconnect owner.
- `0x0058b130` and `0x0058b620` are IDA-confirmed real functions but are still absent from current `simroot_v2/class_TerminalPane.cpp`.
- IDA MCP callers on 2026-05-25 show the parser at `0x0058b130` calls [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md).
- 2026-05-26 IDA MCP recheck confirms the stream parser has only the `0x0062da80` data/vtable reference and the reconnect/leave callback is referenced from `TerminalPane::OnDisconnect` callback construction at `0x0058b56d`.
- The destructor/thunk methods live in the later DialDialog thunk island; keep them associated with this class even though they are not contiguous with the constructor block.

## Cross-References

- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- [UID:0000EH][TerminalSetupPane](by-class/TerminalSetupPane.md)
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md)
- [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md)
- [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md)
- [UID:0001JD][0x0058b620-0x0058b64e.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64e.TerminalPaneReconnectLeaveCallback.md)
- [UID:0001JK][0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks.md)
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `76`.
- Evidence: the page documents terminal connection responsibility, constructor/disconnect/close/parser/callback/destructor ranges, singleton, missing generated helpers, parser call evidence, and reconnect/leave flow; confidence remains capped by unmodeled helper ownership and broad terminal/dial thunk island interactions.
