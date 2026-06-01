*** UID:00008B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiniMapButtonPane

## Status

- Confidence: strong for class behavior and IDA starts; medium for final source placement inside minimap versus main-HUD code.
- Likely source file: [UID:0000LE][MiniMap](by-file/MiniMap.md)
- Address range: [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- Current recovered file: `source-3/simroot_v2/class_MiniMapButtonPane.cpp`

## Class Purpose

`MiniMapButtonPane` is the small in-game minimap button created by [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) in the newer layout. It initializes a pane/tile context, paints `MMAPBUT.EPF` with `FRMPART.PAL`, tracks mouse hover/down state, dispatches a click handler, and clears [UID:0000RN][g_pMiniMapButtonPane](by-global/g_pMiniMapButtonPane.md) during teardown.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00503580-0x0050361d` | Constructs `Pane`, stores `g_pMiniMapButtonPane`, installs vtables, initializes an `EPFTileContext`, and clears state fields. |
| cleanup body | [UID:0001AM][0x00503620-0x00503648.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503648.MiniMapButtonPaneCleanup.md) | Reinstalls vtables, clears the singleton, and calls shared pane cleanup. Current active generated output omits this body. |
| `OnPaint` | `0x00503650-0x00503691` | Loads `MMAPBUT.EPF` frame data and renders it with `FRMPART.PAL`. |
| `OnMouseEvent` | `0x005036a0-0x005037ec` | Handles hover, press, release, state repaint, and click dispatch. |
| singleton clear helper | [UID:0001AN][0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks.md) | Clears `g_pMiniMapButtonPane`. Current active generated output omits this body. |
| adjustor thunks | [UID:0001AN][0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks.md), [UID:0001AN][0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks.md) | MiniMapButtonPane destructor adjustors that forward to `0x00503900`. |
| scalar deleting destructor | `0x00503900-0x0050395f` | Runs cleanup and conditionally deletes storage; `0x0050395e` is the final `retn 4` immediate byte. |

## Boundary Notes

- IDA `callers 0x00503580` reports one constructor caller from `InitializeMainUiGraph` at `0x004f80c2`.
- The local code island is interleaved with [UID:00007P][MapNamePane](by-class/MapNamePane.md): `MapNamePane` owns `0x005031f0`, `0x005032d0`, `0x00503350`, `0x0050380b`, `0x00503816`, and `0x00503840`, while `MiniMapButtonPane` owns `0x00503580`, `0x00503620`, `0x00503650`, `0x005036a0`, `0x00503800`, `0x00503821`, `0x0050382c`, and `0x00503900`.
- The older [UID:0001AK][0x005031f0-0x005038fd.MapNamePane](by-memory/0x005031f0-0x005038fd.MapNamePane.md) is retained for existing links, but the shared island doc is the safer migration anchor.

## Source Placement

The final source placement remains open. The class is a minimap control pane and uses minimap button art, so [UID:0000LE][MiniMap](by-file/MiniMap.md) is the most likely source family. It is also constructed directly by the main UI bootstrap, so `ui/MainUiGraph.cpp` should cross-reference it but not own the class.

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000RN][g_pMiniMapButtonPane](by-global/g_pMiniMapButtonPane.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AM][0x00503620-0x00503648.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503648.MiniMapButtonPaneCleanup.md)
- [UID:0001AN][0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503836.MiniMapButtonPaneClearAndThunks.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)

## Changes

- 2026-05-28: Corrected the scalar deleting destructor range from `0x00503900-0x0050395e` to `0x00503900-0x0050395f`. Evidence: IDA MCP reports the function end at `0x0050395f`, and raw bytes show `0x0050395e` is the `retn 4` immediate byte.
- Completion/confidence score update: existed before as `0/0`; changed to `80/78`. Summary: the minimap button pane has detailed singleton, constructor, cleanup, paint, mouse, thunk, island-boundary, and source-placement notes, but final source placement between minimap and main UI bootstrap remains medium confidence. Evidence: linked shared MapName/MiniMapButton range, cleanup/clear/thunk memory pages, `g_pMiniMapButtonPane`, constructor caller from `InitializeMainUiGraph`, and interleaved `MapNamePane` boundary notes.
