*** UID:0000NB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScreenPane

## Status

- Confidence: strong for root ScreenPane source-module ownership; medium for final cursor/surface/palette helper split.
- Proposed module: `ui/core/ScreenPane.cpp`
- Projected reconstruction path: `NexusTK/ui/core/ScreenPane.cpp`
- Main method cluster: `0x00556910-0x00557132`

## File Role

`ScreenPane` is the full-screen pane/controller. It is constructed during application startup, installs the [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) singleton, owns its instance screen-dimension fields and frame/fade state, releases DirectDraw surfaces during shutdown, and handles fade messages and frame callbacks.

It depends on [UID:0000IW][DirectX](by-file/DirectX.md), [UID:0000MC][Pane](by-file/Pane.md), `FrameHandler`, map/world-map panes, and palette/screen state. `ScreenPane` triggers [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md) during message handling, but current IDA evidence places that state on [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md), so keep implementation ownership with [UID:0000MA][Palette](by-file/Palette.md) unless new original-source evidence proves otherwise.

The small layer-list helpers at `0x00556ce0` and `0x00556d20` are root screen helpers even though earlier ownership notes placed them with `MapPane`. They operate on the screen object's layer-list field and are called during application startup/shutdown plus map/world-map layer changes.

Generic surface/presentation helpers around `0x00557140-0x00559aef` are tracked under [UID:0000OC][Surface](by-file/Surface.md). Keep those as a source-boundary review bucket instead of automatically merging every DirectDraw presentation function into `ScreenPane.cpp`.

The visible-tile redraw helper at [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) is called by `ScreenPane::HandleMessage` when repainting the active screen child. Current `class_ParcelPane.cpp` ownership is false; final owner is still open between `ScreenPane`, `Surface`, and a shared root-render helper.

[UID:0000IL][CursorManager](by-file/CursorManager.md) is currently documented as a ScreenPane companion or typed subobject view, not a proven separate singleton. Its screen-dimension getters and active-cursor helper operate on the same root object stored in `g_pScreenPane`; [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) is an alias over this storage in current evidence. The latest IDA check leans toward keeping the cursor helper island in `ScreenPane.cpp` unless a later cursor-resource initialization path proves a separate original file.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ScreenPane` | `0x00556910-0x00557132` plus thunks | Full-screen pane, fade state, DirectDraw surface release, startup singleton. |
| root layer-list helpers | `0x00556ce0-0x00556d41` | Set or remove screen layer-list entries used by startup/shutdown and map/world-map layer transitions. |
| browser notification handler | `0x00556f70-0x00557070` | ScreenPane vtable slot for `Bros` browser notifications; toggles the root screen byte at `+0x511`, closes the legacy browser dialog, and can open an alert with payload text. |
| frame callback helper | `0x004b6d30-0x004b6d4b` | Inserts a delayed frame callback into the global frame registry. |
| visible-tile redraw helper | `0x005051c0-0x00505228` | Begins painting a cached surface, draws visible tiles, and ends painting; current ParcelPane ownership is false. |
| screen/cursor helper island | `0x00557380-0x00557467` | Dirty/update helper, repaint/timer helper through the `+0xa4` timer-handler subobject, cursor switching from the `+0x550` handle table, cursor visibility wrappers, and screen dimension accessors. |
| destructor support island | `0x00559b20-0x00559b8b` | Singleton clear helper, adjustor thunks, and scalar deleting destructor support tied to ScreenPane vtable slots and destructor stores. |
| ScreenPane read-only data | `0x006230e8-0x00623174` within [UID:00026B][0x006230c8-0x00623480.RingBufferScreenPaneReadOnlyData](by-memory/0x006230c8-0x00623480.RingBufferScreenPaneReadOnlyData.md) | ScreenPane COL/vtable region containing the `HandleMessage`, browser handler, destructor, and adjustor slots. |
| [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) | [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) | Singleton set by constructor and cleared by destructor. |

## Evidence Notes

- IDA MCP reports `ScreenPane::ScreenPane` has one direct caller from application startup around `0x004645ea`.
- IDA MCP decompilation confirms `ScreenPane::ScreenPane` writes `dword_67A7CC = this`, stores width/height in the same fields later read by `CursorManager::GetScreenWidth` and `CursorManager::GetScreenHeight`, and `~ScreenPane` clears `dword_67A7CC`.
- Destructor evidence shows tile/sprite cache cleanup, DirectDraw surface release, display mode/cooperative-level restore, `g_pScreenPane` clearing, and the final chain to `Pane`.
- IDA MCP decompilation of `0x00556ce0` and `0x00556d20` shows layer-list operations through the root screen object at offset `0x10c`; caller checks include `Application::Startup`, `Application::Shutdown`, MapPane cleanup, and world-map creation.
- The exact browser notification child at [UID:0002VO][0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler](by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md) is reached through ScreenPane vtable slot `0x00623150`, handles `0x42726f73` / `Bros` payloads, and mutates ScreenPane field byte `+0x511`; this is direct evidence for keeping that handler in the root ScreenPane file rather than the Browser source file.
- The exact destructor-support island at [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md) covers the singleton clear helper, three adjustor thunks, and the scalar deleting destructor, with vtable-slot refs at `0x006230ec`, `0x00623138`, `0x00623168`, and `0x00623174`.
- [UID:00026B][0x006230c8-0x00623480.RingBufferScreenPaneReadOnlyData](by-memory/0x006230c8-0x00623480.RingBufferScreenPaneReadOnlyData.md) contains the ScreenPane vtable/read-only data region and adjacent screen/cursor resource strings; the mixed RingBuffer prefix keeps the broader data page separate, but the ScreenPane subregion strengthens the `ScreenPane.cpp` source-root placement.
- Live IDA references alias the same global as `g_pCursorManager` in cursor-helper contexts and as `g_browserRuntime` in browser dispatch fallback code. Treat both as typed views over the screen singleton until a separate object is proven.
- 2026-05-26 recheck: IDA MCP reports `0x0067a7cc` as a 4-byte `.data` item with 145 refs, with no separate cursor-manager constructor/lifetime evidence.
- 2026-05-26 IDA MCP decompilation of `ScreenPane::ScreenPane` initializes `g_pScreenPane`, ScreenPane vtables, the root layer list at `+0x10c`, dimensions at `+0x112/+0x114/+0x116`, and frame/fade state, but does not initialize the cursor handle table used later at `+0x550`. Cursor handle loading remains a follow-up path, not proof of a separate singleton.
- 2026-06-07 A010 parent-gate refresh: live IDA xrefs for [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) reconfirm constructor publish `0x00556962`, constructor fallback clear `0x00556969`, destructor clear `0x00556c16`, helper clear `0x00559b20`, and broad UI/browser/cursor consumers over the same root ScreenPane object. The successor dword at `0x0067a7d0` has a distinct xref family, confirming the singleton's exact storage boundary.
- 2026-06-08 A009 Batch 125 checked [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) and [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) as possible source-owner candidates. `ScreenPane` remains a screen subsystem consumer/instance-field owner, not a proven declaration owner for the process-wide default width/height globals. Keep the globals parentless upward until declaration-side source ownership is proven.

## Cross-References

- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
- [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md)
- [UID:0002VO][0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler](by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md)
- [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md)
- [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:00026B][0x006230c8-0x00623480.RingBufferScreenPaneReadOnlyData](by-memory/0x006230c8-0x00623480.RingBufferScreenPaneReadOnlyData.md)
- [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)
- [UID:0000NC][ScreenPanePaletteState](by-file/ScreenPanePaletteState.md)
- [UID:0000IL][CursorManager](by-file/CursorManager.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md)
- [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-06-07 A010 Batch032 parent-gate update:
  - Before: `86/82`; completion already covered the root ScreenPane method/data inventory, but confidence stayed below the corrected 85/85 gate because the cursor/surface helper split was still over-weighted.
  - After: `86/85`; live singleton xrefs and the separate successor-global boundary strengthen the ScreenPane file-root confidence enough for direct parent-chain routing. Cursor/surface/palette split caveats remain, and no final C++ was emitted.
- 2026-06-08 A009 Batch 125 screen-size global owner check:
  - Score unchanged at `86/85`.
  - Clarified that `ScreenPane` owns its instance dimension fields but is not currently proven as the direct declaration owner for the process-wide default width/height globals.
- 2026-06-06 A008:
  - Before: the page had a valid `NexusTK/ui/core/` path but was still `84/78` because it omitted the newly split browser-notification handler, destructor-support island, and ScreenPane vtable/read-only evidence already documented in class and memory pages.
  - After: changed completion/confidence to `86/82`, added those exact children and data references to proposed contents, and clarified that the remaining uncertainty is the cursor/surface/palette helper split rather than the root ScreenPane source-module owner.
  - Evidence: [UID:0002VO][0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler](by-memory/0x00556f70-0x00557070.ScreenPaneBrowserNotificationHandler.md), [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md), [UID:00026B][0x006230c8-0x00623480.RingBufferScreenPaneReadOnlyData](by-memory/0x006230c8-0x00623480.RingBufferScreenPaneReadOnlyData.md), and [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) give exact bounds, vtable slots, singleton lifecycle, and source-owned ScreenPane behavior.
- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/core/` to resolve the by-file generated-root coverage error.
  - Before: the validator path metadata was blank even though the document and proposed source tree both placed `ScreenPane.cpp` under `ui/core/`.
  - After: set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/core/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `ScreenPane.cpp` in `ui/core`, and live IDA evidence ties [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) plus the layer-list helper set to this root screen-pane module.
- 2026-05-28:
  - Before: the main `ScreenPane` method cluster was cited as `0x00556910-0x00557131`.
  - After: corrected it to `0x00556910-0x00557132` and kept surface/presentation ownership separate at `0x00557140-0x00559aef`.
  - Evidence: IDA MCP disassembly shows `0x00557131` is the final byte of the `OnFrameTick` tail jump to `ShowCursor`; padding starts at `0x00557132`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document covers the root screen-pane role, proposed contents, singleton/global evidence, layer-list helpers, cursor alias caveats, surface-helper boundaries, and cross-references; confidence is limited by unresolved final file split with palette/cursor/surface helper families.
