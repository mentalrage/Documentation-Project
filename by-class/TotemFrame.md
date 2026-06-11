*** UID:0000F4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TotemFrame

## Status

- Confidence: strong.
- Likely source file: [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- Address range: [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- Current recovered file: `source-3/simroot_v2/class_TotemFrame.cpp`
- Singleton: [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md) at `0x0069b35c`

## Class Purpose

`TotemFrame` is a singleton `Pane` used to display the totem/status frame. It positions itself on the right side of the screen and draws a frame from `TOTFRAME.EPD` with `NPAL7.PAL`. The frame index is read from [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) through [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `TotemFrame::TotemFrame` | `0x00598cc0-0x00598d9e` | Constructs base pane, installs singleton/vtables, positions frame. |
| `~TotemFrame` / cleanup body | `0x00598da0-0x00598dc8` | Reinstalls vtables, clears `g_pTotemFrame`, and runs pane base cleanup. Omitted from active generated source. |
| `OnPaint` | `0x00598dd0-0x00598e3b` | Loads `TOTFRAME.EPD`, resolves frame index from old user status pane, renders with `NPAL7.PAL`. |
| `ClearTotemFrameSingleton` | `0x00598e40-0x00598e4a` | Clears the singleton pointer. |
| adjustor thunk | `0x00598e4b-0x00598e55` | Adjusts from secondary subobject by `-0xa0` and forwards to scalar deleting destructor. |
| adjustor thunk | `0x00598e56-0x00598e60` | Adjusts from secondary subobject by `-0xa4` and forwards to scalar deleting destructor. |
| `ScalarDeletingDestructor` | `0x00598e70-0x00598ecf` | Clears singleton, destroys base pane, optional delete. |

## Evidence Notes

- IDA MCP confirms all listed starts as real functions.
- Constructor xrefs come from old/new status update handlers at `0x005ba4a0` and `0x005bf7c0`.
- `OnPaint` reads `g_pOldUserStatusPane` at `0x0069b4ec` and calls `OldUserStatusPane::GetSpiritId` at `0x005bdc60`.
- Generated `SpellOneArgInputPane.cpp` checks `g_pTotemFrame` and marks it for deletion before opening one-argument spell input.
- Active generated output omits `0x00598da0` and `0x00598e40`; disabled output marks `0x00598e4b` as missing code and emits a suspicious expression for `0x00598e56`.
- 2026-05-28 IDA MCP boundary recheck confirms the scalar deleting destructor ends at `0x00598ecf`, followed by one `0xcc` alignment byte before `TransferServerDialogPane` at `0x00598ed0`.

## Cross-References

- [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md)
- [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md)
- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md)
- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0000MC][Pane](by-file/Pane.md)

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OV][TotemFrame](by-file/TotemFrame.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, cleanup body, paint method, singleton clear helper, adjustor thunks, and scalar deleting destructor at `0x00598cc0`, `0x00598da0`, `0x00598dd0`, `0x00598e40`, `0x00598e4b`, `0x00598e56`, and `0x00598e70`; this page and parent [UID:0000OV][TotemFrame](by-file/TotemFrame.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-28 boundary correction:
  - What existed before: class documentation pointed to `0x00598cc0-0x00598ece` and listed the scalar deleting destructor through `0x00598ece`.
  - Changed to: class documentation points to `0x00598cc0-0x00598ecf` and lists the destructor through `0x00598ecf`.
  - Summary/evidence: IDA MCP reports `sub_598E70` as `0x00598e70-0x00598ecf`; `0x00598ecf-0x00598ed0` is alignment before `TransferServerDialogPane`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:90`.
  - Summary/evidence: scored from the constructor/destructor/paint/thunk method map, singleton and resource references, status-pane source for frame selection, xrefs, and IDA-backed boundary correction.
