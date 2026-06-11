*** UID:000068 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HourPane

## Status

- Confidence: strong for behavior, range, and source-file ownership; medium for exact inherited base names.
- Likely source module: [UID:0000JX][HourPane](by-file/HourPane.md)
- Autogen parent: [UID:0000JX][HourPane](by-file/HourPane.md), now valid under the strict `85/85` gate after the file page reached `88/85` and this class page reached `85/85`.
- Main range: [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- Singleton global: [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md)
- Resource doc: [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)
- Evidence basis: `simroot_v2` and IDA MCP checks on 2026-05-24.

## Responsibility

`HourPane` is the in-game hour/clock HUD pane. It receives a server/message hour update, stores the current hour byte, paints an hour icon from `TIME.EPF` or `TIME.EPD`, and shows a localized tooltip for the current hour.

## Layout Evidence

- Constructor writes vtables at object offsets `0x0`, `0xa0`, and `0xa4`, matching a primary pane object plus two adjustor subobjects.
- Current hour lives at object offset `0xf8`; constructor initializes it to `-1`.
- Paint and update paths invalidate the draw region beginning at object offset `0x44`.
- Mouse/help and packet/update methods receive subobject `this` pointers and recover the owner by subtracting `0xa0`.
- Vtable addresses observed by IDA: `0x0061b370`, `0x0061b3bc`, and `0x0061b3ec`.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004cee60-0x004ceeaf` | constructor | Registers singleton, initializes current hour to `-1`, installs vtables. |
| `0x004ceeb0-0x004ceed9` | cleanup helper | Reinstalls vtables, clears singleton, calls shared pane cleanup. Omitted from active generated output. |
| `0x004ceee0-0x004cef25` | hour update handler | Handles message/payload byte `0x20`, copies the next byte to current hour, and invalidates if changed. Omitted from active generated output. |
| `0x004cef30-0x004cf009` | `OnMouseEvent` | Handles hover event type `4`, notifies security callback, and creates localized hour tooltip. |
| `0x004cf010-0x004cf139` | `OnPaint` | Draws `TIME.EPF`/`TIME.PAL` in new mode or `TIME.EPD` in old mode. |
| `0x004cf173-0x004cf17e` | adjustor thunk | Subtracts `0xa0` and forwards to scalar deleting destructor. Disabled output says missing code. |
| `0x004cf17e-0x004cf189` | adjustor thunk | Subtracts `0xa4` and forwards to scalar deleting destructor. Disabled output has bad adjusted-this recovery. |
| `0x004cf190-0x004cf1ef` | scalar deleting destructor | Clears singleton, calls shared pane cleanup, optionally frees `this`. |

## External State

- [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md) at `0x0069b418`; generated alias `g_pItemShopPane` is wrong for this owner.
- `g_pLanguageMan` at `0x0067a750`; text id `0x4d` is used as the tooltip label.
- `g_pSecurityCallback` / `dword_69AE00`; notified with argument `1` during mouse hover handling.
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`; selects new/current EPF drawing versus old EPD drawing.
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / historical `dword_67A744`; image/resource manager used to load `TIME.EPF` and `TIME.EPD`.
- [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md) / [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md); twelve-entry frame table used as `(hour / 2) % 12`.
- `dword_69B3FC` and `dword_69B3E8`; invalidation/draw callback globals used by the paint path.

## Assignment Gate Rationale

This class now clears the corrected strict child/direct-parent gate. The direct class page is scored `85/85`, and the owning file page [UID:0000JX][HourPane](by-file/HourPane.md) is `88/85`. The source ownership is supported by one compact exact method island [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md), the exact singleton global [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md), the exact frame-table child [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md), and the resource doc [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md). The remaining open questions are class-layout naming questions, not source ownership blockers.

## Open Questions

- Confirm the exact base class name behind the shared cleanup call at `0x00544580`. Generated output currently labels it as `TextButtonExControlPane`/`Pane` in similar HUD panes, but IDA only proves shared pane-base cleanup.
- Identify the final semantic name for the hour update virtual. The handler likely belongs to a packet/message callback interface because it reads `*(a2 + 12)` and filters byte `0x20`, but the interface name is not yet established.
- Confirm final field names for the draw-region and current-hour storage once the shared pane base layout is named more completely.

## Cross-References

- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md)
- [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md)
- [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)

## Changes

- 2026-06-11 A001 strict-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:80`, `AUTOGEN_PARENT_UID:` blank because the class and direct file parent did not clear the corrected `85/85` assignment gate.
  - After: `COMPLETION:85`, `CONFIDENCE:85`, `AUTOGEN_PARENT_UID:0000JX`.
  - Summary/evidence: accepted the class-to-file parent after [UID:0000JX][HourPane](by-file/HourPane.md) reached `88/85` and the class page now records the evidence chain through exact method island [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md), singleton [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md), exact frame-table child [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md), and resource page [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md). Remaining uncertainty is limited to inherited base/interface and field names, so final C++ stays blank.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: HourPane resource-manager evidence used only historical `dword_67A744`.
  - After: the page records canonical `g_pEPFLib` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A744` to `g_pEPFLib`; existing page evidence already ties the reference to `TIME.EPF`/`TIME.EPD` resource loading.
- 2026-06-07 A008 alias cleanup: normalized `byte_66DA97` / `g_isEPFMode` to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- Completion/confidence score update: existed before as `0/0`; changed to `82/80`. Summary: HUD clock responsibility, layout offsets, vtables, methods, globals, resource usage, wrong generated alias, and open base/interface questions are documented; confidence remains limited by inherited base naming and update-interface naming. Evidence: `HourPane` memory range, `g_pHourPane`, `hourpane-time-resources`, IDA vtable addresses, and external-state notes.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JX][HourPane](by-file/HourPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the HUD clock pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000JX`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004cee60`, `0x004ceeb0`, `0x004ceee0`, `0x004cef30`, `0x004cf010`, and `0x004cf190`, with constructor callers from `0x004f7d10`. The class score `82/80` and parent score `88/82` meet the 80/80 attachment gate.
- 2026-06-10 A002 strict-gate repair:
  - Before: `AUTOGEN_PARENT_UID:0000JX` attached this class to [UID:0000JX][HourPane](by-file/HourPane.md), and the status still referenced a generated file name.
  - After: `AUTOGEN_PARENT_UID:` is blank and status records the strict `85/85` gate; score remains `82/80`.
  - Summary/evidence: the likely source file is still correct evidence, but the direct parent is only `88/82` and this child is only `82/80`, so neither side clears the current gate. The source-owner link remains informational until inherited base/update-interface naming and parent confidence are improved.
