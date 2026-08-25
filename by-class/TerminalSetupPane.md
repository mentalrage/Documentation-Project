*** UID:0000EH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TerminalSetupPane

## Status

- Confidence: strong
- Likely source file: [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- Address range: [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md)
- Exact vtable data: [UID:0003DP][0x0062daac-0x0062db48.TerminalSetupPaneVtableData](by-memory/0x0062daac-0x0062db48.TerminalSetupPaneVtableData.md)
- Autogen parent: [UID:0000OI][TerminalPane](by-file/TerminalPane.md). This class now clears the strict `85/85` gate and remains part of the pre-login terminal source module.

## Class Purpose

`TerminalSetupPane` is the terminal serial settings dialog. It lets the user choose whether to use a COM port, select `COM1` through `COM4`, choose a baud rate, persist the resulting terminal settings, refresh the active terminal pane, and reset/close Socket connection state through the shared Socket helper.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `TerminalSetupPane` | `0x0058b650-0x0058c192` | Builds `Terminal Setup` using `DLGSETUP.EPF`/`DLGSETUP.PAL` or `DLGSETUP.EPD`/`NPAL8.PAL`, creates mode/COM/baud controls, initializes them from config, and opens the modal dialog. No direct caller/data route is currently recovered; raw epilogue is `ret 4`, so keep an unused/legacy argument ABI caveat. |
| `UpdateControlState` | `0x0058c1a0` | Enables/disables COM and baud controls based on the selected mode and enables accept only when a required COM selection exists. |
| `OnCommand` | `0x0058c240-0x0058c350` | Applies or cancels; on apply writes COM/baud settings, refreshes [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md), calls Socket-owned `Socket::PostResetConnectionCommand` at `0x00574b20`, persists pane state, and closes. Raw epilogue is `ret 8`; the second stack argument is currently unused. |

## Evidence Notes

- IDA MCP confirms all three method starts and the contiguous class block.
- The setup dialog belongs with `TerminalPane` because it edits the same terminal/modem config consumed by terminal connect and dial paths.
- 2026-06-12 A002 Batch 288 live IDA MCP `lookup_funcs` confirms the constructor at `0x0058b650-0x0058c192`, control-state updater at `0x0058c1a0-0x0058c23f`, and command handler at `0x0058c240-0x0058c350`, with [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md) beginning at `0x0058c350`.
- Live IDA `entity_query`/`xrefs_to` confirms [UID:0003DP][0x0062daac-0x0062db48.TerminalSetupPaneVtableData](by-memory/0x0062daac-0x0062db48.TerminalSetupPaneVtableData.md) is an exact class-owned vtable child: stores at `0x0058b690`, `0x0058b699`, and `0x0058b6a3` target the three `TerminalSetupPane` vtable views, and the successor vtable at `0x0062db48` is `PhoneBookDialog`.
- Live IDA disassembly confirms the constructor creates setup graphics from `DLGSETUP.PAL`/`DLGSETUP.EPF`, builds COM and baud selectors, maps persisted config values to selections, loads `DLGSETUP.EPD`, and parents the modal under [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md).
- Live IDA disassembly confirms `OnCommand` treats command `1` as accept/apply and command `2` as cancel/close; the apply path writes the COM slot byte at `dword_67A7C8 + 0x28de28`, formats the selected baud text into `dword_67A7C8 + 0x28de2c`, refreshes the active terminal pane through its virtual slot, calls the Socket reset/close helper at `0x00574b20`, and closes the dialog.
- B006 source-quality recheck found no exported xref or local PE direct reference to constructor entry `0x0058b650`; current best interpretation is retained/source-authored setup dialog code linked with vtables/resources, not dead padding or PhoneBook ownership. Source-facing prose can use `TerminalSetupPane::TerminalSetupPane()`, but binary-aware docs should preserve the `ret 4` unused-argument caveat until caller recovery.

## Controls And Resources

| Item | Source-facing meaning |
| --- | --- |
| command/control id `1` | OK/apply command. Writes terminal config, refreshes the active terminal pane, posts Socket reset command, saves placement, and closes. |
| command/control id `2` | Cancel/close command. Saves placement and closes without applying serial settings. |
| control id `3` | Use-COM / connection-mode toggle. |
| control id `4` | COM-port popup for `COM1` through `COM4`. Stored as `g_pConfig+0x28de28` / `terminalComPort`, with `1..4` matching `COM1..COM4` and `5` representing no-COM/direct mode. |
| control id `5` | Baud popup for `9600`, `14400`, `19200`, `28800`, `38400`, and `57600`; selected text is parsed into `g_pConfig+0x28de2c` / `terminalBaudRate`. |
| image button ids `14` and `22` | Setup dialog image/control buttons created by the constructor. |
| EPF branch | Uses `DLGSETUP.EPF` and `DLGSETUP.PAL`; observed dialog size is approximately `338x190`. |
| EPD branch | Uses `DLGSETUP.EPD` and `NPAL8.PAL`; observed dialog size is approximately `407x210`. |

Reject the old local name `SendTerminalSetupPacket` for `0x00574b20`; [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md) identifies the helper as Socket command id `5` / reset-close state posting.

## Score Rationale

Completion is raised to `85` because the class page now documents role, source owner, method inventory with exact ranges, exact vtable child ownership, setup resources, COM/baud control behavior, config write offsets, terminal-pane refresh, and boundary against phone-book code. Confidence is raised to `88` because current IDA function-boundary, vptr-store, successor-boundary, and disassembly evidence agree with the linked executable/read-only-data pages. Final C++ remains blank because field names and exact class declaration/layout are still below the `95/95` reconstruction-code gate.

## Cross-References

- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- [UID:0000EG][TerminalPane](by-class/TerminalPane.md)
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md)
- [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md)
- [UID:0003DP][0x0062daac-0x0062db48.TerminalSetupPaneVtableData](by-memory/0x0062daac-0x0062db48.TerminalSetupPaneVtableData.md)
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md)

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OI][TerminalPane](by-file/TerminalPane.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented setup constructor, control-state updater, and command handler function starts at `0x0058b650`, `0x0058c1a0`, and `0x0058c240`; this page and parent [UID:0000OI][TerminalPane](by-file/TerminalPane.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `86`.
- Evidence: the page documents terminal setup purpose, source ownership, contiguous range, constructor/update/apply-cancel methods, config persistence, setup packet behavior, and relationship to `TerminalPane`; remaining completion gap is source-ready C++ detail.
- 2026-06-12 A002 Batch 288:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`.
  - Evidence: live IDA MCP reconfirmed method bounds, exact class vtable child [UID:0003DP][0x0062daac-0x0062db48.TerminalSetupPaneVtableData](by-memory/0x0062daac-0x0062db48.TerminalSetupPaneVtableData.md), constructor vptr stores, `DLGSETUP` resource use, COM/baud selector setup, persisted config writes, and terminal-pane refresh. This clears the strict direct-parent gate for the vtable child; final C++ remains blank.
- 2026-06-21 B006 Rule 26 support sync:
  - Added no-direct-route/`ret 4` constructor caveat, resource branch details, control id map, COM/baud field names, `OnCommand` `ret 8` caveat, and corrected `0x00574b20` from a Terminal setup packet name to Socket-owned `Socket::PostResetConnectionCommand`.
  - Score unchanged; this pass refined source-quality naming and reconstruction readiness without changing the class owner.
