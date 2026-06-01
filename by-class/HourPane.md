*** UID:000068 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HourPane

## Status

- Confidence: strong for behavior and range, medium for exact inherited base names.
- Current generated file: `class_HourPane.cpp`
- Likely source module: [UID:0000JX][HourPane](by-file/HourPane.md)
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
- `byte_66DA97` / `g_isEPFMode`; selects new/current EPF drawing versus old EPD drawing.
- `dword_67A744`; image/resource manager used to load `TIME.EPF` and `TIME.EPD`.
- `word_66DB04`; twelve-entry frame table used as `(hour / 2) % 12`.
- `dword_69B3FC` and `dword_69B3E8`; invalidation/draw callback globals used by the paint path.

## Open Questions

- Confirm the exact base class name behind the shared cleanup call at `0x00544580`. Generated output currently labels it as `TextButtonExControlPane`/`Pane` in similar HUD panes, but IDA only proves shared pane-base cleanup.
- Identify the final semantic name for the hour update virtual. The handler likely belongs to a packet/message callback interface because it reads `*(a2 + 12)` and filters byte `0x20`, but the interface name is not yet established.
- Confirm whether `g_hourFrameTable` should live in `HourPane.cpp` or a shared resource-layout table once more time/resource users are reviewed.

## Cross-References

- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md)
- [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `82/80`. Summary: HUD clock responsibility, layout offsets, vtables, methods, globals, resource usage, wrong generated alias, and open base/interface questions are documented; confidence remains limited by inherited base naming and update-interface naming. Evidence: `HourPane` memory range, `g_pHourPane`, `hourpane-time-resources`, IDA vtable addresses, and external-state notes.
