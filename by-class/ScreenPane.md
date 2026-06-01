*** UID:0000CB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScreenPane

## Status

- Confidence: strong for class role.
- Likely source file: [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- Main address range: [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md)
- Current recovered file: `source-3/simroot_v2/class_ScreenPane.cpp`

## Class Purpose

`ScreenPane` is the root full-screen pane and frame/fade controller. It stores screen dimensions, fade state, display/surface handles, an internal list, cursor state, and frame-handler state. It also owns cleanup for shared tile/sprite caches and DirectDraw display-mode restoration.

The root singleton is [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) at `0x0067a7cc`. Current generated data also calls this storage [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) for [UID:00003E][CursorManager](by-class/CursorManager.md) helper calls; keep that as a typed alias until a separate object is proven. Current IDA evidence favors ScreenPane-owned cursor helpers rather than a separately allocated manager.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScheduleFrameCallback` | `0x004b6d30-0x004b6d4b` | Schedules a frame callback at current tick plus delay. |
| `ScreenPane::ScreenPane` | `0x00556910-0x00556a5a` | Constructs base `Pane`, installs singleton/vtables, dimensions, root layer list at `+0x10c`, surface/fade defaults. |
| `~ScreenPane` | `0x00556a60-0x00556cd3` | Releases caches, DirectDraw surfaces, display mode/cooperative level, list/extra object, singleton, and base objects. |
| root layer-list helpers | `0x00556ce0-0x00556d41` | Set and remove screen layer-list entries; generated `MapPane` ownership is callsite pollution. |
| visible-tile redraw helper | `0x005051c0-0x00505228` | Shared draw helper called by `HandleMessage` on the active child; generated `ParcelPane` ownership is false. |
| `HandleMessage` | `0x00556d50-0x00556f60` | Handles fade in/out and repaint-style screen messages. |
| `OnFrameTick` | `0x00557070-0x00557131` | Advances fade animation and cleans up callback/cursor state. |
| cursor/screen helpers | `0x00557380-0x00557467` | Dirty/update, repaint/timer, active cursor, cursor visibility, and screen-dimension helper island; currently best treated as ScreenPane support with a provisional `CursorManager` typed view. |

## Layout Notes

- Root layer list pointer: dword offset `67`, byte offset `+0x10c`, allocated by `ScreenPane::ScreenPane`.
- Screen dimensions: word offsets `137`, `138`, and `139`, byte offsets `+0x112`, `+0x114`, and `+0x116`; the first two are returned by generated `CursorManager` getters.
- Cursor handle table: word offset `680`, byte offset `+0x550`; used by the active-cursor helper, but not initialized in the constructor decompilation checked on 2026-05-26.
- Active cursor index: word offset `704`, byte offset `+0x580`.
- Repaint/timer helper subobject: byte offset `+0xa4`, passed to the timer-wrapper helper at `0x005975e0`.
| deleting thunks | `0x00559b20-0x00559b8b` | Singleton clear plus multiple-inheritance adjustor/scalar delete thunks. |

## Cross-References

- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md)
- [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:00003E][CursorManager](by-class/CursorManager.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:0000CC][ScreenPanePaletteState_543D30](by-class/ScreenPanePaletteState_543D30.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page documented root-screen responsibility, singleton ownership, major methods, layout offsets, helper ownership caveats, and corrected memory ranges.
  - After: changed completion/confidence to `82/84`.
  - Evidence: existing method notes, layout notes, singleton/cursor alias discussion, IDA-backed range correction, and class/file/global cross-references support high-confidence class documentation.

- 2026-05-28:
  - Before: the main `ScreenPane` range ended at `0x00557131`, and the destructor thunk island was listed as `0x00559b2b-0x00559b8a`.
  - After: corrected the main range to `0x00556910-0x00557132` and the thunk island to `0x00559b20-0x00559b8b`.
  - Evidence: IDA MCP disassembly shows `0x00557131` is the final `ShowCursor` tail-jump byte, and `0x00559b20-0x00559b8b` contains the singleton clear plus ScreenPane destructor thunks/scalar deleting destructor.
