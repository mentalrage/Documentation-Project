*** UID:0000FF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Reconstruction parent: attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md) after that source-root page reached the `80/80` parent-side gate; final class C++ remains blank below the 95/95 code-emission gate.
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
- Exact vtable-data child [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md) records the three vtable views, confirm-handler slot, destructor adjustor thunk slots, and exclusive end before `UserInfoDialogPane`.
- Mixed read-only aggregate [UID:00026S][0x0062e57c-0x0062e624.UniApiUrlAlertReadOnlyData](by-memory/0x0062e57c-0x0062e624.UniApiUrlAlertReadOnlyData.md) keeps the preceding `UniAPIInit` vtable dword parentless/PlatformApi-owned while assigning only the nested URL-alert vtable data to this class and [UID:0000HE][AlertPanes](by-file/AlertPanes.md).

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:0001YZ][UrlAlertPaneVtables](by-type/by-vtable/UrlAlertPaneVtables.md)
- [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md)
- [UID:00026S][0x0062e57c-0x0062e624.UniApiUrlAlertReadOnlyData](by-memory/0x0062e57c-0x0062e624.UniApiUrlAlertReadOnlyData.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md)

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` while leaving `AUTOGEN_PARENT_UID` blank.
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, destructor, confirm handler, singleton-clear helper, adjustor thunks, and scalar deleting destructor at `0x00599a40`, `0x00599b20`, `0x00599ba0`, `0x00599bd0`, `0x00599bdb`, `0x00599be6`, and `0x00599c00`; at that time likely parent [UID:0000HE][AlertPanes](by-file/AlertPanes.md) was `78/85`, so the parent-side gate did not pass. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:90`.
  - Summary/evidence: scored from the constructor/destructor/confirm/thunk method map, URL/exit layout offsets, vtable stores, singleton handling, constructor xrefs, and direct `ShellExecuteA` behavior.
- 2026-06-07 parent attachment:
  - Before: `AUTOGEN_PARENT_UID` stayed blank because [UID:0000HE][AlertPanes](by-file/AlertPanes.md) was below the parent-side score gate.
  - Changed to: `AUTOGEN_PARENT_UID:0000HE`, with final C++ still blank.
  - Evidence: `AlertPanes` is now `82/86` with valid `NexusTK/ui/dialogs/` path and records the URL-alert executable, exact vtable-data child, mixed-owner `.rdata` split, and MainMenu packet-adapter separation. This class remains below the final C++ gate because inherited slot naming and source-quality class declaration details still need a final audit.
