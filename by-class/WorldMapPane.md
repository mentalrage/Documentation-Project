*** UID:0000G9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WorldMapPane

## Status

- Confidence: strong for behavior and separate source module.
- Likely source file: [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- Address range: [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- Current recovered file: `source-3/simroot_v2/class_WorldMapPane.cpp`
- Boundary note: generated `RegisterFrameCallback` / `StopAnimation` wrappers at `0x004b6d00` and `0x004b6d20` are now treated as generic [UID:00005G][FrameHandler](by-class/FrameHandler.md) helpers, not WorldMapPane ownership.

## Class Purpose

`WorldMapPane` is the modal/overlay world-map travel pane. It renders a scrollable world map, displays destination labels, determines reachable nodes, handles keyboard/mouse navigation, animates viewport movement, and sends travel requests to the server.

## Method Families

| Family | Representative methods | Role |
| --- | --- | --- |
| Lifecycle | `WorldMapPane`, `~WorldMapPane`, `ScalarDeletingDestructor` | Loads assets/node state and releases helper buffers. |
| View positioning | `SetViewPosition`, `ScrollViewBy`, `AnimateToPosition`, `ClampViewPosition`, `GetVisibleRect` | Maintains the scrollable world-map viewport. |
| Navigation | `NavigateToNode`, `FindPredecessorNode`, `SendMapTravelPacket` | Follows parent-link route data and sends server travel packet `0x6E`. |
| Drawing | `OnDraw`, `DrawPlayerMarker` | Draws map background, nodes/labels, reachability coloring, and player marker. |
| Input | `OnKeyDown`, `OnMouseEvent`, `UpdateHoverFromMouse`, `UpdateHoverFromMouseStrict`, `HitTestNode`, `HitTestSpecialRegions` | Handles keyboard, mouse hover/click, drag scroll, and node/special-region hit tests. |
| Animation | `OnFrameUpdate`, `OnTimerTick`, generic `FrameHandler` schedule/remove wrappers | Uses the frame callback system for smooth travel/viewport animation. |
| Reachability | `BuildReachabilityData` | Builds route reachability through private vector/bitset helpers. |

## Evidence Notes

- IDA MCP confirms `0x005c2ac0-0x005c32aa`, `0x005c3950-0x005c3e41`, and `0x005c4bd0-0x005c5075`.
- `BuildReachabilityData` calls [UID:0000GA][WorldMapReachabilityBitSet](by-class/WorldMapReachabilityBitSet.md) methods at `0x005c56a0` and `0x005c5b20`.
- `WorldMapPane::~WorldMapPane` calls [UID:0000G8][WorldMapNodeEntryVector](by-class/WorldMapNodeEntryVector.md) cleanup.
- IDA MCP on 2026-05-24 shows `0x004b6d00` and `0x004b6d20` have broad callers and only delegate to `g_frameRegistry`; keep them under [UID:0000JM][FrameMgr](by-file/FrameMgr.md).
- Wave3 currently attaches a method at `0x00590053`; IDA reports no function there. Treat that entry as data debt until corrected.

## Cross-References

- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- [UID:0000G8][WorldMapNodeEntryVector](by-class/WorldMapNodeEntryVector.md)
- [UID:0000GA][WorldMapReachabilityBitSet](by-class/WorldMapReachabilityBitSet.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:00005G][FrameHandler](by-class/FrameHandler.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the lifecycle, viewport, navigation, drawing, input, animation, and reachability method-family documentation, helper-class links, IDA-confirmed representative ranges, frame-handler ownership correction, and Wave3 data-debt caveat.
