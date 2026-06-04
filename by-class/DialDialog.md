*** UID:00003R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DialDialog

## Status

- Confidence: strong for local class behavior, constructor caller, vtables, modem parser ownership, and thunk exclusions; medium-high for final callback and field names.
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md)
- Parent attachment: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) has a valid `NexusTK/login/` path and already groups the phone-book/dial terminal flow; current class evidence is strong enough to attach.

## Score Rationale

- Completion `84`: raised from `72` after the 2026-06-04 live IDA pass confirmed exact function bounds, constructor caller, vtable stores and slots, modem parser dispatch, dial command strings, and adjacent TerminalPane thunk exclusions.
- Confidence `86`: strong for `DialDialog` ownership and behavior. It remains below final-code confidence because the parser callback name/prototype, source-facing field names, and exact source split from terminal support are still provisional.

## Class Purpose

`DialDialog` is the terminal dialing dialog. It displays the dial-in-progress UI over `g_pTerminalPane`, converts the selected phone-book number to multibyte text, sends modem cleanup/connect commands, and starts dialing with `ATX3DT`.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `DialDialog` | `0x0058d750-0x0058d9e3` | Builds `DLGDIAL.EPD`, opens over `TerminalPane`, stores the target number, converts it to multibyte text, and sends cleanup/connect/dial strings. |
| `OnDialogAction` | `0x0058d9f0-0x0058da1f` | OK action sends carriage return, slide-closes, and closes the dialog. |
| Modem response parser | [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) | Callback/vtable helper parsing `CONNECT` and `BUSY` response tokens. |
| terminal singleton clear helper | [UID:0001JI][0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md) | Clears [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md); constructor unwind/cleanup glue, not a normal `DialDialog` method. |
| `DialDialog` destructor family | [UID:0001JJ][0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks](by-memory/0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks.md), `0x0058dc20-0x0058dc5b` | Compiler adjustor thunks plus scalar deleting destructor. |

## Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA reports exact local function bounds for `0x0058d750-0x0058d9e3`, `0x0058d9f0-0x0058da1f`, `0x0058da20-0x0058db95`, `0x0058dbe0-0x0058dbeb`, `0x0058dbeb-0x0058dc01`, and `0x0058dc20-0x0058dc5b`.
- The constructor has one direct code caller: `0x0058cc17` inside `PhoneBookDialog::DialSelectedEntry` (`0x0058cb60`).
- Constructor stores the primary, secondary, and tertiary `DialDialog` vtables at `0x0062dd44`, `0x0062dda4`, and `0x0062ddd4`.
- Vtable/data slots place `OnDialogAction` at `0x0062dd8c -> 0x0058d9f0`, the modem-response parser at `0x0062ddb4 -> 0x0058da20`, and the destructor adjustors at `0x0062dda4 -> 0x0058dbeb` / `0x0062ddd4 -> 0x0058dbf6`.
- Constructor data references include `DLGDIAL.EPD`, terminal singleton `g_pTerminalPane` at `0x0069bdf8`, `WideCharToMultiByte`, and the modem command strings `ATX3DT` plus carriage-return/newline terminators.
- `OnDialogAction` sends `\r` through the packet/modem sender, then calls the slide helper `0x0049eb90` and close helper `0x0049dad0`.
- `0x0058da20` walks incoming bytes up to length `0x64`, tracks parser state at callback-subobject offset `0x24c`, recognizes `CONNECT` and `BUSY`, and closes through the same slide/close helpers on recognized or oversized input.
- The local thunk island also contains `TerminalPane` thunks at `0x0058dc01-0x0058dc17`; keep those with [UID:0000EG][TerminalPane](by-class/TerminalPane.md), not this class.

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000EG][TerminalPane](by-class/TerminalPane.md)
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md)
- [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md)
- [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md)
- [UID:0001JI][0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md)
- [UID:0001JJ][0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks](by-memory/0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks.md)
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: dialing dialog role, constructor/action behavior, modem response parser, terminal cleanup caveat, thunk/destructor boundaries, and PhoneBook/Terminal links are documented; remaining work is final callback ownership and source-quality method naming for the nearby parser.
- 2026-06-04: Raised from `72/80` to `84/86`, marked reconstructable, and attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md).
  - Before: the class page had behavior notes but blank reconstructable/parent metadata, stale recovered-file provenance, no exact live function bounds, and no explicit vtable-slot evidence for the action handler or parser.
  - After: live IDA evidence records executable identity, exact function bounds, sole constructor caller, vtable stores/slots, dial command strings, parser state behavior, shared slide/close helpers, and TerminalPane thunk exclusions.
  - Reasoning: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) has a valid `NexusTK/login/` path and documented phone-book/dial ownership, while [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md) and [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) already have strong reconstructable evidence. Final C++ remains blank because callback prototype, virtual-slot name, and source-facing field names remain below the 95/95 threshold.
