*** UID:0000NB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScreenPane

## Status

- Confidence: strong for class role, medium for final file split with palette-state helpers.
- Proposed module: `ui/core/ScreenPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_ScreenPane.cpp`
- Main method cluster: `0x00556910-0x00557132`

## File Role

`ScreenPane` is the full-screen pane/controller. It is constructed during application startup, installs the [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) singleton, owns screen dimensions and frame/fade state, releases DirectDraw surfaces during shutdown, and handles fade messages and frame callbacks.

It depends on [UID:0000IW][DirectX](by-file/DirectX.md), [UID:0000MC][Pane](by-file/Pane.md), `FrameHandler`, map/world-map panes, and palette/screen state. `ScreenPane` triggers [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md) during message handling, but current IDA evidence places that state on [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md), so keep implementation ownership with [UID:0000MA][Palette](by-file/Palette.md) unless new original-source evidence proves otherwise.

The small layer-list helpers at `0x00556ce0` and `0x00556d20` are root screen helpers even though current `simroot_v2` emits them in `class_MapPane.cpp`. They operate on the screen object's layer-list field and are called during application startup/shutdown plus map/world-map layer changes.

Generic surface/presentation helpers around `0x00557140-0x00559aef` are tracked under [UID:0000OC][Surface](by-file/Surface.md). Keep those as a source-boundary review bucket instead of automatically merging every DirectDraw presentation function into `ScreenPane.cpp`.

The visible-tile redraw helper at [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) is called by `ScreenPane::HandleMessage` when repainting the active screen child. Current `class_ParcelPane.cpp` ownership is false; final owner is still open between `ScreenPane`, `Surface`, and a shared root-render helper.

[UID:0000IL][CursorManager](by-file/CursorManager.md) is currently documented as a ScreenPane companion or typed subobject view, not a proven separate singleton. Its screen-dimension getters and active-cursor helper operate on the same root object stored in `g_pScreenPane`; generated [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) is an alias over this storage in current evidence. The latest IDA check leans toward keeping the cursor helper island in `ScreenPane.cpp` unless a later cursor-resource initialization path proves a separate original file.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ScreenPane` | `0x00556910-0x00557132` plus thunks | Full-screen pane, fade state, DirectDraw surface release, startup singleton. |
| root layer-list helpers | `0x00556ce0-0x00556d41` | Set or remove screen layer-list entries used by startup/shutdown and map/world-map layer transitions. |
| frame callback helper | `0x004b6d30-0x004b6d4b` | Inserts a delayed frame callback into the global frame registry. |
| visible-tile redraw helper | `0x005051c0-0x00505228` | Begins painting a cached surface, draws visible tiles, and ends painting; current ParcelPane ownership is false. |
| screen/cursor helper island | `0x00557380-0x00557467` | Dirty/update helper, repaint/timer helper through the `+0xa4` timer-handler subobject, cursor switching from the `+0x550` handle table, cursor visibility wrappers, and screen dimension accessors. |
| [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) | [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) | Singleton set by constructor and cleared by destructor. |

## Evidence Notes

- IDA MCP reports `ScreenPane::ScreenPane` has one direct caller from application startup around `0x004645ea`.
- IDA MCP decompilation confirms `ScreenPane::ScreenPane` writes `dword_67A7CC = this`, stores width/height in the same fields later read by `CursorManager::GetScreenWidth` and `CursorManager::GetScreenHeight`, and `~ScreenPane` clears `dword_67A7CC`.
- Generated destructor frees tile/sprite caches, releases DirectDraw surfaces, restores display mode/cooperative level, clears `g_pScreenPane`, and chains to `Pane`.
- IDA MCP decompilation of `0x00556ce0` and `0x00556d20` shows layer-list operations through the root screen object at offset `0x10c`; caller checks include `Application::Startup`, `Application::Shutdown`, MapPane cleanup, and world-map creation.
- Wave3 metadata aliases the same global as `g_pCursorManager` in cursor-helper contexts and as `g_browserRuntime` in browser dispatch fallback code. Treat both as typed views over the screen singleton until a separate object is proven.
- 2026-05-26 recheck: IDA MCP reports `0x0067a7cc` as a 4-byte `.data` item with 145 refs, and current active simroot still has no separate cursor-manager constructor/lifetime evidence.
- 2026-05-26 IDA MCP decompilation of `ScreenPane::ScreenPane` initializes `g_pScreenPane`, ScreenPane vtables, the root layer list at `+0x10c`, dimensions at `+0x112/+0x114/+0x116`, and frame/fade state, but does not initialize the cursor handle table used later at `+0x550`. Cursor handle loading remains a follow-up path, not proof of a separate singleton.

## Cross-References

- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
- [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md)
- [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md)
- [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)
- [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md)
- [UID:0000IL][CursorManager](by-file/CursorManager.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-05-28:
  - Before: the main `ScreenPane` method cluster was cited as `0x00556910-0x00557131`.
  - After: corrected it to `0x00556910-0x00557132` and kept surface/presentation ownership separate at `0x00557140-0x00559aef`.
  - Evidence: IDA MCP disassembly shows `0x00557131` is the final byte of the `OnFrameTick` tail jump to `ShowCursor`; padding starts at `0x00557132`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document covers the root screen-pane role, proposed contents, singleton/global evidence, layer-list helpers, cursor alias caveats, surface-helper boundaries, and cross-references; confidence is limited by unresolved final file split with palette/cursor/surface helper families.
