*** UID:0000G9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WorldMapPane

## Status

- Confidence: very strong for behavior, separate source module, singleton lifecycle, and direct ownership of the WorldMap read-only-data children.
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

- IDA MCP on 2026-06-10 B001-038 confirms `0x006313fc -> ??_R4WorldMapPane@@6B@`, named vtable bases at `0x00631400`, `0x0063144c`, `0x0063147c`, and `0x00631488`, and constructor/destructor store xrefs from `0x005c2ac0-0x005c32aa` and `0x005c32b0-0x005c341e`.
- The same pass confirms WorldMap resource literals `WMSYMBOL.EPF`, `BOAT.EPF`, `BOAT.PAL`, `.EPD`, `.PAD`, `BBOAT.EPD`, `BOAT.PAD`, and `FBOAT.EPD` in `0x00631490-0x00631528` are referenced only by the constructor-family function.
- IDA MCP confirms numeric constants in `0x00631528-0x00631570` are referenced only by WorldMapPane method ranges `0x005c36d0`, `0x005c37e0`, `0x005c3950`, `0x005c4250`, and `0x005c4740`; `0x00631570` has a non-WorldMap xref and starts the Browser/OLE successor page.
- IDA MCP reconfirms `g_pWorldMapPane` xrefs at `0x005c2b1f`, `0x005c2b26`, `0x005c3401`, and `0x005c5500` for publish/clear lifecycle, plus read sites at `0x004d7d03` and `0x004d9186`.
- IDA MCP confirms `0x005c2ac0-0x005c32aa`, `0x005c3950-0x005c3e41`, and `0x005c4bd0-0x005c5075`.
- `BuildReachabilityData` calls [UID:0000GA][WorldMapReachabilityBitSet](by-class/WorldMapReachabilityBitSet.md) methods at `0x005c56a0` and `0x005c5b20`.
- `WorldMapPane::~WorldMapPane` calls [UID:0000G8][WorldMapNodeEntryVector](by-class/WorldMapNodeEntryVector.md) cleanup.
- IDA MCP on 2026-05-24 shows `0x004b6d00` and `0x004b6d20` have broad callers and only delegate to `g_frameRegistry`; keep them under [UID:0000JM][FrameMgr](by-file/FrameMgr.md).
- Wave3 currently attaches a method at `0x00590053`; IDA reports no function there. Treat that entry as data debt until corrected.

## Cross-References

- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- [UID:000271][0x006313fc-0x00631570.WorldMapReadOnlyData](by-memory/0x006313fc-0x00631570.WorldMapReadOnlyData.md)
- [UID:00035H][0x006313fc-0x00631490.WorldMapPaneVtableData](by-memory/0x006313fc-0x00631490.WorldMapPaneVtableData.md)
- [UID:00035I][0x00631490-0x00631528.WorldMapPaneResourceStrings](by-memory/0x00631490-0x00631528.WorldMapPaneResourceStrings.md)
- [UID:00035J][0x00631528-0x00631570.WorldMapPaneNumericConstants](by-memory/0x00631528-0x00631570.WorldMapPaneNumericConstants.md)
- [UID:00029E][0x0069b454-0x0069b458.g_pWorldMapPane](by-memory/0x0069b454-0x0069b458.g_pWorldMapPane.md)
- [UID:0000G8][WorldMapNodeEntryVector](by-class/WorldMapNodeEntryVector.md)
- [UID:0000GA][WorldMapReachabilityBitSet](by-class/WorldMapReachabilityBitSet.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:00005G][FrameHandler](by-class/FrameHandler.md)

## Changes

- 2026-06-10 B001-038 parent-gate repair:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:82`; the class summarized method families but did not carry the direct read-only-data ownership evidence needed for `000271` child assignments.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, with live IDA MCP evidence for WorldMapPane RTTI/vtable stores, constructor-only resource literals, WorldMapPane-only numeric constants, singleton lifecycle xrefs, and the Browser/OLE successor boundary.
  - Summary/evidence: B001-038 split [UID:000271][0x006313fc-0x00631570.WorldMapReadOnlyData](by-memory/0x006313fc-0x00631570.WorldMapReadOnlyData.md) into exact children [UID:00035H][0x006313fc-0x00631490.WorldMapPaneVtableData](by-memory/0x006313fc-0x00631490.WorldMapPaneVtableData.md), [UID:00035I][0x00631490-0x00631528.WorldMapPaneResourceStrings](by-memory/0x00631490-0x00631528.WorldMapPaneResourceStrings.md), and [UID:00035J][0x00631528-0x00631570.WorldMapPaneNumericConstants](by-memory/0x00631528-0x00631570.WorldMapPaneNumericConstants.md). The class is the direct semantic parent for all three children and now clears the strict `85/85` gate.

- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed representative world-map constructor/lifecycle, view/input, and reachability-builder starts at `0x005c2ac0`, `0x005c3950`, and `0x005c4bd0`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the lifecycle, viewport, navigation, drawing, input, animation, and reachability method-family documentation, helper-class links, IDA-confirmed representative ranges, frame-handler ownership correction, and Wave3 data-debt caveat.
