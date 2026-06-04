*** UID:0000EG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TerminalPane

## Status

- Confidence: strong for class role, login source placement, vtable/singleton anchors, parser/callback ownership, and live IDA function boundaries; medium-high for final helper names and phone/dial split.
- Likely source file: [UID:0000OI][TerminalPane](by-file/TerminalPane.md) / `NexusTK/login/TerminalPane.cpp`
- Primary address range: [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md)
- Rebuild handling: reconstructable class documentation attached to the TerminalPane file parent; final C++ remains blank because helper names, field names, and the phone/dial boundary are not final-source quality.

## Class Purpose

`TerminalPane` is the pre-login terminal connection pane. It installs a full-screen hidden dialog over the root pane, cancels stale reconnect state, sends cash-shop/session connection packets, initializes modem/serial state, handles disconnect alerts, and owns the reconnect/leave callback flow.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `TerminalPane` | `0x0058af50-0x0058b0ee` | Constructs the full-screen terminal dialog, sets [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md), sends initial reconnect/cashshop/connect/modem reset packets, and starts the terminal timer. |
| Terminal stream parser | `0x0058b130-0x0058b44c`, [UID:0001JC][0x0058b130-0x0058b44b.TerminalPaneStreamParser](by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md) | IDA-confirmed helper parsing incoming terminal bytes/escape states. Calls [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md) on the current IDA path. |
| `OnDisconnect` | `0x0058b470-0x0058b5e0` | Sends disconnect/cashshop cleanup, closes transient alert, and optionally shows reconnect/leave prompt. |
| `OnClose` | `0x0058b5e0-0x0058b5fc` | Hides the pane and invalidates its region. |
| Reconnect/leave callback | `0x0058b620-0x0058b64f`, [UID:0001JD][0x0058b620-0x0058b64e.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64e.TerminalPaneReconnectLeaveCallback.md) | Callback used by the reconnect/leave alert; reconnect branch restarts terminal timer, leave branch exits through the application path. |
| Thunks/destructor | [UID:0001JK][0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks.md), `0x0058dc60-0x0058dca5` | Adjustor thunks and scalar deleting destructor; destructor clears [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md). |

## Live IDA Evidence

- IDA MCP on 2026-06-04 used IDB `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Exact IDA function records for the TerminalPane half are constructor `0x0058af50-0x0058b0ee`, stream parser `0x0058b130-0x0058b44c`, disconnect handler `0x0058b470-0x0058b5e0`, close handler `0x0058b5e0-0x0058b5fc`, reconnect/leave callback `0x0058b620-0x0058b64f`, adjustor thunks `0x0058dc01-0x0058dc0c` and `0x0058dc0c-0x0058dc17`, and scalar deleting destructor `0x0058dc60-0x0058dca5`.
- TerminalSetupPane companion functions are `0x0058b650-0x0058c192`, `0x0058c1a0-0x0058c23f`, and `0x0058c240-0x0058c350`; the next major function starts at `0x0058c350`, matching the phone-book boundary.
- Constructor code callers are `0x004f5f9b`, `0x004f647a`, `0x004f7cbb`, and `0x004f924f`; the last call is inside [UID:0000TF][OpenTerminalPane_4F91C0](by-global/OpenTerminalPane_4F91C0.md) / `0x004f91c0-0x004f927d`, which itself has no direct callers.
- Vtable/data refs keep the virtual handlers with TerminalPane: `0x0062da10 -> 0x0058dc60`, `0x0062da54 -> 0x0058b5e0`, `0x0062da80 -> 0x0058b130`, and `0x0062daa4 -> 0x0058b470`; the constructor writes the vtable at `0x0058afb9`.
- The reconnect/leave callback has a single data xref from `0x0058b56d` inside the disconnect handler, matching callback-object construction for the reconnect/leave alert.
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md) at `0x0069bdf8` has nine live refs in this family: constructor writes at `0x0058afa8`/`0x0058afaf`, TerminalSetupPane and phone/dial reads, singleton-clear helper `0x0058dbe0`, and destructor clear at `0x0058dc66`.
- `SendPositionUpdate` at `0x00574d40` has a live call from the stream parser at `0x0058b42f`, confirming the parser is connection/reconnect logic rather than plain text output.
- Destructor xrefs include both adjustor thunks (`0x0058dc07`, `0x0058dc12`) and the TerminalPane vtable slot `0x0062da10`.

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

- 2026-06-04:
  - Before: scored `84/76`, reconstructability and parent attachment were blank, and the page still had stale source-reference wording.
  - After: scored `86/84`, marked reconstructable, attached to [UID:0000OI][TerminalPane](by-file/TerminalPane.md), and replaced the evidence with live IDA boundary, vtable, caller, callback, singleton, and parser-call checks.
  - Why: current IDA evidence proves TerminalPane class ownership, login source placement, virtual handler anchors, singleton lifecycle, reconnect callback ownership, and parser behavior. Confidence remains below 90 because final helper names and the phone/dial split still need source-quality cleanup.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `76`.
- Evidence: the page documents terminal connection responsibility, constructor/disconnect/close/parser/callback/destructor ranges, singleton, helper coverage gaps, parser call evidence, and reconnect/leave flow; confidence remains capped by unmodeled helper ownership and broad terminal/dial thunk island interactions.
