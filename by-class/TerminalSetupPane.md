*** UID:0000EH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TerminalSetupPane

## Status

- Confidence: strong
- Likely source file: [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- Address range: [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md)
- Current recovered file: `source-3/simroot_v2/class_TerminalSetupPane.cpp`

## Class Purpose

`TerminalSetupPane` is the terminal serial settings dialog. It lets the user choose whether to use a COM port, select `COM1` through `COM4`, choose a baud rate, persist the resulting terminal settings, and send a setup packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `TerminalSetupPane` | `0x0058b650` | Builds `Terminal Setup` using `DLGSETUP.EPF` or `DLGSETUP.EPD`, creates mode/COM/baud controls, initializes them from config, and opens the modal dialog. |
| `UpdateControlState` | `0x0058c1a0` | Enables/disables COM and baud controls based on the selected mode and enables accept only when a required COM selection exists. |
| `OnCommand` | `0x0058c240` | Applies or cancels; on apply writes COM/baud settings, sends terminal setup packet, persists pane state, and closes. |

## Evidence Notes

- IDA MCP confirms all three method starts and the contiguous class block.
- The setup dialog belongs with `TerminalPane` because it edits the same terminal/modem config consumed by terminal connect and dial paths.

## Cross-References

- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- [UID:0000EG][TerminalPane](by-class/TerminalPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `86`.
- Evidence: the page documents terminal setup purpose, source ownership, contiguous range, constructor/update/apply-cancel methods, config persistence, setup packet behavior, and relationship to `TerminalPane`; remaining completion gap is source-ready C++ detail.
