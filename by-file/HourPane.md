*** UID:0000JX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# HourPane

## Status

- Confidence: strong for class/file role and memory range, medium for exact inherited base naming.
- Proposed module: `ui/panels/HourPane.cpp`
- Main class: [UID:000068][HourPane](by-class/HourPane.md)
- Main address doc: [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- Singleton global: [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md)
- Resource doc: [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)
- Evidence basis: IDA MCP decompilation/function/caller/xref checks.

## File Role

`HourPane.cpp` owns the compact in-game clock/hour HUD pane. It is created by `InitializeMainUiGraph` in both the newer and older main UI layouts, tracks the current server-provided hour byte, paints the matching time icon, and creates a localized hover tooltip using text id `0x4d`.

This should remain a UI panel source. The code is resource/UI behavior rather than timekeeping infrastructure: it consumes a packet/message byte, invalidates its draw region, and selects `TIME.EPF`/`TIME.EPD` frames for display.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `HourPane` | `0x004cee60-0x004cf1ef` | Constructor, cleanup helper, server/message hour update, mouse tooltip handler, paint, destructor thunks, scalar deleting destructor. |
| `g_pHourPane` | `0x0069b418` | Singleton pointer registered by constructor, cleared by cleanup/destructor paths, and read during main UI shutdown. |
| `g_hourFrameTable` / `word_66DB04` | `0x0066db04` | Twelve-frame lookup table used as `(hour / 2) % 12` for clock art. |
| Vtable set | `0x0061b370`, `0x0061b3bc`, `0x0061b3ec` | Main and adjustor vtables installed at object offsets `0x0`, `0xa0`, and `0xa4`. |

## Behavior Notes

- The constructor at `0x004cee60` calls `Pane::Pane(..., 1)`, writes [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md), initializes current hour at offset `0xf8` to `-1`, and installs three `HourPane` vtables.
- The non-deleting cleanup helper at `0x004ceeb0` reinstalls vtables, clears the singleton, and calls the shared pane cleanup at `0x00544580`.
- The hour update handler at `0x004ceee0` accepts only payload opcode/selector byte `0x20`; it reads the following byte as the current hour and invalidates the pane if the value changed.
- `OnMouseEvent` at `0x004cef30` handles event type `4`, notifies the security callback when present, hit-tests the pane hover region, formats `"%s : %02d"` using localized text id `0x4d`, and creates a `SimpleHelpPane` for 5000 ms.
- `OnPaint` at `0x004cf010` branches on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`. The new/current branch uses `TIME.EPF` plus `TIME.PAL`; the old branch uses `TIME.EPD`.
- The destructor adjustor thunks at `0x004cf173` and `0x004cf17e` subtract `0xa0` and `0xa4` respectively before forwarding to the scalar deleting destructor at `0x004cf190`.

## Source Grouping

Keep this source adjacent to the other main HUD panels:

```text
ui/panels/
  UserStatusPane.cpp
  SoundStatusPane.cpp
  HourPane.cpp
  UserPane.cpp
```

`HourPane` should cross-reference [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md), [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md), and [UID:0000JZ][IconsPane](by-file/IconsPane.md) because all are created by `InitializeMainUiGraph` as persistent HUD/status panes, but they should not be merged. `ConnStatusPane` is network-state UI, `SoundStatusPane` is audio-control UI, `HourPane` is clock/resource display UI, and `IconsPane` is old-layout icon-strip UI.

## Data Caveats

Some recovered symbol naming aliases the singleton as `g_pItemShopPane`, but IDA confirms the global at `0x0069b418` is written by `HourPane` construction/cleanup/destruction and read during main UI shutdown. Use [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md) as the canonical documentation name and preserve `g_pItemShopPane` only as a noncanonical alias.

IDA-confirmed functions at `0x004ceeb0` and `0x004ceee0` remain important to the range even when other source views miss them. Use the memory doc as the range anchor before source migration.

[UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) is the canonical name for the old/new resource selector used by `HourPane::OnPaint`. Preserve `byte_66DA97` only as the IDA lookup alias; do not introduce a local hour-pane-specific name because the same byte is shared by startup, main UI layout, render/resource selection, attached-object cleanup, packet-send side effects, timer digits, spell-input cleanup, and weather/layer construction.

## Assignment Gate Rationale

This file now clears the corrected direct-parent gate at `88/85`. The confidence increase is supported by the exact method island [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md) at `88% : strong`, the exact singleton child [UID:00029I][0x0069b418-0x0069b41c.g_pHourPane](by-memory/0x0069b418-0x0069b41c.g_pHourPane.md) at `89% : strong`, the exact frame-table child [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) at `90/92`, and the resolved `g_useEpfAssets` alias caveat. Remaining uncertainty is limited to exact inherited base naming and final field names, not source ownership.

## Cross-References

- [UID:000068][HourPane](by-class/HourPane.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)
- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: class/file role, singleton, vtables, frame table, behavior, data caveats, resource dependencies, and main HUD grouping are well documented; confidence is capped by the exact inherited base naming and singleton alias caveat.
- 2026-06-05 reconstruction path classification:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, leaving the file row in error.
  - Changed to: `NexusTK/ui/panels/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `HourPane.cpp` under `NexusTK/ui/panels/`, and live IDA MCP xrefs/decompilation confirm `0x004cee60`, `0x004ceeb0`, and `0x004cf190` write/clear `dword_69B418` from `HourPane` lifecycle code.
- 2026-06-07 A008 alias cleanup:
  - What existed before: the page described the paint branch only as `byte_66DA97`.
  - Changed to: normalized the branch dependency to [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), while preserving `byte_66DA97` as the historical IDA alias.
  - Summary/evidence: the resolved-name report maps `byte_66DA97` to `g_useEpfAssets`, and the global page records the byte's broad old/new EPF/EPD resource-mode role including the `HourPane::OnPaint` xref at `0x004cf020`.
- 2026-06-10 A001 parent-gate repair:
  - Changed confidence from `82` to `85`; completion remains `88`.
  - Summary/evidence: exact HourPane method island, singleton storage, frame table storage, resource docs, and the resolved `g_useEpfAssets` alias now make source ownership strong enough for direct children to clear the strict `85/85` parent gate. Final inherited-base naming and field names remain below the final-code threshold.
