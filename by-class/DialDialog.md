*** UID:00003R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DialDialog

## Status

- Confidence: strong for core dialog behavior, medium for nearby unowned modem parser.
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md)
- Current recovered file: `source-3/simroot_v2/class_DialDialog.cpp`

## Class Purpose

`DialDialog` is the terminal dialing dialog. It displays the dial-in-progress UI over `g_pTerminalPane`, converts the selected phone-book number to multibyte text, sends modem cleanup/connect commands, and starts dialing with `ATX3DT`.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `DialDialog` | `0x0058d750` | Builds `DLGDIAL.EPD`, opens over `TerminalPane`, stores the target number, and sends cleanup/connect/dial strings. |
| `OnDialogAction` | `0x0058d9f0` | OK action sends carriage return, slide-closes, and closes the dialog. |
| Modem response parser | [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) | IDA-confirmed helper parsing `CONNECT` and `BUSY` response tokens; not currently emitted in `class_DialDialog.cpp`. |
| terminal singleton clear helper | [UID:0001JI][0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md) | Clears [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md); constructor unwind/cleanup glue, not a normal `DialDialog` method. |
| Thunks/destructor | [UID:0001JJ][0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks](by-memory/0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks.md), `0x0058dc20` | Compiler adjustor thunks and scalar deleting destructor. |

## Evidence Notes

- `PhoneBookDialog::DialSelectedEntry` constructs `DialDialog` after copying the selected number.
- `0x0058da20` sits immediately after `OnDialogAction` and uses `DialDialog`-sized offsets, but current `simroot_v2/class_DialDialog.cpp` still omits it.
- IDA decompilation shows `0x0058da20` walks byte buffers up to length 100, tracks parser state at `this + 0x24c`, recognizes `CONNECT` and `BUSY`, then closes the dialog through the same slide/close helpers used by `OnDialogAction`.
- The local thunk island also contains `TerminalPane` thunks at `0x0058dc01` and `0x0058dc0c`; do not claim those as `DialDialog` methods.

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000EG][TerminalPane](by-class/TerminalPane.md)
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md)
- [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md)
- [UID:0001JJ][0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks](by-memory/0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: dialing dialog role, constructor/action behavior, modem response parser, terminal cleanup caveat, thunk/destructor boundaries, and PhoneBook/Terminal links are documented; remaining work is final ownership for the nearby parser and generated body completeness.
