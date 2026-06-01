*** UID:0000FF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UrlAlertPane

## Status

- Likely source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- Address range: [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- Vtables: [UID:0001YZ][UrlAlertPaneVtables](by-type/by-vtable/UrlAlertPaneVtables.md) at `0x0062e584`, `0x0062e5ec`, and `0x0062e61c`.
- Layout docs: [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md), with URL pointer at `+0x270` and exit flag at `+0x274`.
- Current recovered file: `source-3/simroot_v2/class_UrlAlertPane.cpp`
- Confidence: strong.

## Class Purpose

`UrlAlertPane` is an `AlertPane` subclass that displays a confirmation prompt for an external URL. On confirm it opens the stored URL through `ShellExecuteA`; if its exit-after-open flag is set, it then requests application shutdown.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `UrlAlertPane` | `0x00599a40-0x00599b19` | Calls `AlertPane::AlertPane`, stores [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md), allocates and copies the URL string, and records the exit flag. |
| `~UrlAlertPane` | `0x00599b20-0x00599b92` | Frees the URL buffer, clears the singleton, and tears down the alert base. |
| `OnConfirm` | `0x00599ba0-0x00599bcf` | Calls `ShellExecuteA` on the stored URL and optionally requests application exit. |
| `ClearUrlAlertPaneSingleton` | `0x00599bd0-0x00599bda` | Tiny helper that clears [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md); reached from constructor exception cleanup, not a vtable thunk. |
| `AdjustorThunk` | `0x00599bdb-0x00599bf1` | Secondary/tertiary vtable adjustor thunks into the deleting destructor. |
| `ScalarDeletingDestructor` | `0x00599c00-0x00599cb3` | Destructor wrapper with optional storage delete. |

## Evidence Notes

- IDA decompilation shows the constructor calling `AlertPane::AlertPane` with a likely OK button string at `off_613A18`.
- 2026-05-26 IDA MCP vtable pass confirms `UrlAlertPane` primary/secondary/tertiary vtables at `0x0062e584`, `0x0062e5ec`, and `0x0062e61c`, installed by constructor stores at `0x00599aac`, `0x00599ab2`, and `0x00599abc`.
- 2026-05-26 IDA layout pass confirms the heap-owned URL buffer pointer at `+0x270` and the exit-after-open flag byte at `+0x274`; see [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- IDA disassembly of the constructor exception cleanup jumps to `0x00599bd0`; that helper only clears `g_pUrlAlertPane`. The actual destructor adjustor thunks are `0x00599bdb` and `0x00599be6`.
- IDA xrefs to the constructor include calls from `0x00503034` and `0x00513f7e`/`0x0051402f`; `0x00503034` is inside [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md).
- `OnConfirm` directly calls `ShellExecuteA(0, 0, url, 0, 0, 1)`.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:0001YZ][UrlAlertPaneVtables](by-type/by-vtable/UrlAlertPaneVtables.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:90`.
  - Summary/evidence: scored from the constructor/destructor/confirm/thunk method map, URL/exit layout offsets, vtable stores, singleton handling, constructor xrefs, and direct `ShellExecuteA` behavior.
