*** UID:0000CB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScreenPane

## Status

- Confidence: strong for class role.
- Likely source file: [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- Main address range: [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md)
- Rebuild handling: source-authored root screen class with compiler-generated vtables, scalar deleting destructor support, adjustor thunks, EH/runtime glue, and alignment bytes.
- Parent/C++ status: reconstructable and attached to the owning [UID:0000NB][ScreenPane](by-file/ScreenPane.md) file root. Keep final class C++ blank until the interface names, field names, and class-layout details clear the final-source gate.

## Class Purpose

`ScreenPane` is the root full-screen pane and frame/fade controller. It stores screen dimensions, fade state, display/surface handles, an internal list, cursor state, and frame-handler state. It also owns cleanup for shared tile/sprite caches and DirectDraw display-mode restoration.

The root singleton is [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) at `0x0067a7cc`; the exact storage is also documented by [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md). Existing alias documentation also routes some cursor helper reads through [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) for [UID:00003E][CursorManager](by-class/CursorManager.md) helper calls; keep that as a typed alias until a separate object is proven. Current IDA evidence favors ScreenPane-owned cursor helpers rather than a separately allocated manager.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScheduleFrameCallback` | `0x004b6d30-0x004b6d4b` | Schedules a frame callback at current tick plus delay. |
| `ScreenPane::ScreenPane` | `0x00556910-0x00556a5a` | Constructs base `Pane`, installs singleton/vtables, dimensions, root layer list at `+0x10c`, surface/fade defaults. |
| `~ScreenPane` | `0x00556a60-0x00556cd4` | Releases caches, DirectDraw surfaces, display mode/cooperative level, list/extra object, singleton, and base objects. |
| root layer-list helpers | `0x00556ce0-0x00556d41` | Set and remove screen layer-list entries; earlier callsite-only ownership is pollution from map/world-map setup and teardown callers. |
| visible-tile redraw helper | `0x005051c0-0x00505228` | Shared draw helper called by `HandleMessage` on the active child; earlier callsite-only `ParcelPane` ownership is false. |
| `HandleMessage` | `0x00556d50-0x00556f61` | Handles fade in/out and repaint-style screen messages. |
| browser notification handler | `0x00556f70-0x00557070` | [UID:0002VO][0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler](by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md) vtable-referenced handler for `0x42726f73` / `Bros` payloads; toggles byte `+0x511`, closes the legacy browser dialog singleton, and can open an alert using payload text. |
| `OnFrameTick` | `0x00557070-0x00557132` | Advances fade animation and cleans up callback/cursor state; final byte belongs to the tail `jmp ds:ShowCursor`. |
| cursor/screen helpers | `0x00557380-0x00557467` | Dirty/update, repaint/timer, active cursor, cursor visibility, and screen-dimension helper island; currently best treated as ScreenPane support with a provisional `CursorManager` typed view. |
| deleting support island | `0x00559b20-0x00559b8b` | [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md) singleton clear, three compiler-generated adjustor thunks, scalar deleting destructor, and padding boundaries. |

## Layout Notes

- Root layer list pointer: dword offset `67`, byte offset `+0x10c`, allocated by `ScreenPane::ScreenPane`.
- Screen dimensions: word offsets `137`, `138`, and `139`, byte offsets `+0x112`, `+0x114`, and `+0x116`; the first two are returned by current `CursorManager`-typed getter aliases.
- Cursor handle table: word offset `680`, byte offset `+0x550`; used by the active-cursor helper, but not initialized in the constructor decompilation checked on 2026-05-26.
- Active cursor index: word offset `704`, byte offset `+0x580`.
- Repaint/timer helper subobject: byte offset `+0xa4`, passed to the timer-wrapper helper at `0x005975e0`.
- Browser-notification state byte: `+0x511`, set for `Bros` state `0` and cleared for state `1`.
- Deleting-support adjustors subtract `0xa0`, `0xa4`, and `0xf8` before entering the scalar deleting destructor; these offsets are strong evidence of multiple inherited ScreenPane facets, but the final interface names still need a class-layout audit.

## Cross-References

- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md)
- [UID:0002VO][0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler](by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md)
- [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md)
- [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)
- [UID:00003E][CursorManager](by-class/CursorManager.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:0000CC][ScreenPanePaletteState_543D30](by-class/ScreenPanePaletteState_543D30.md)

## Changes

- 2026-06-06 A009:
  - Before: the page still cited a recovered generated-source file, used observed-last-byte endings for several methods, omitted the split browser-notification handler, and kept the destructor-support island as a terse layout stray.
  - After: changed completion/confidence from `82/84` to `84/87`, removed generated-source provenance as an authority, normalized method ranges to end-exclusive bounds, added the browser handler TMP child link, documented the `+0x511` state byte, and linked the refreshed destructor-support island.
  - Evidence: related by-memory pages record IDA-backed function boundaries, vtable refs, `Bros` handler behavior, `g_pScreenPane` lifecycle refs, destructor callee/delete-wrapper evidence, adjustor offsets `0xa0`/`0xa4`/`0xf8`, and padding boundaries.

- 2026-06-06 A008:
  - Before: the class stayed reconstructable but unassigned because the owning [UID:0000NB][ScreenPane](by-file/ScreenPane.md) source-root page was still `84/78`, below the documented 80/80 parent gate.
  - After: changed completion/confidence to `85/88` and set `AUTOGEN_PARENT_UID` to `0000NB`; `RECONSTRUCTION_CPP CODE` remains blank because the final class declaration, inherited interface names, field names, and method signatures are still below the final-source threshold.
  - Evidence: the file page now records the exact ScreenPane method aggregate, browser notification handler, destructor-support island, vtable/read-only data, singleton storage, root layer-list helpers, and remaining cursor/surface/palette split caveats at `86/82`.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The root screen pane remained unclassified in autogen coverage despite documented singleton, frame/fade, surface cleanup, layer-list, and cursor-helper ownership evidence.
  - After: The class is reconstructable but unassigned because the likely parent file confidence is below the 80/80 parent-attach gate.
  - Evidence: Live IDA MCP lookup confirms `0x004b6d30`, `0x00556910`, `0x00556a60`, `0x00556ce0`, `0x005051c0`, `0x00556d50`, `0x00557070`, `0x00557380`, and destructor thunk start `0x00559b20`.

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page documented root-screen responsibility, singleton ownership, major methods, layout offsets, helper ownership caveats, and corrected memory ranges.
  - After: changed completion/confidence to `82/84`.
  - Evidence: existing method notes, layout notes, singleton/cursor alias discussion, IDA-backed range correction, and class/file/global cross-references support high-confidence class documentation.

- 2026-05-28:
  - Before: the main `ScreenPane` range ended at `0x00557131`, and the destructor thunk island was listed as `0x00559b2b-0x00559b8a`.
  - After: corrected the main range to `0x00556910-0x00557132` and the thunk island to `0x00559b20-0x00559b8b`.
  - Evidence: IDA MCP disassembly shows `0x00557131` is the final `ShowCursor` tail-jump byte, and `0x00559b20-0x00559b8b` contains the singleton clear plus ScreenPane destructor thunks/scalar deleting destructor.
