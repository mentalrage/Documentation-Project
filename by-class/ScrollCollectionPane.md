*** UID:0000CG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollCollectionPane

## Status

- Likely source file: [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md), or final merge into [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Address range: [UID:0001GT][0x00561db0-0x0056325b.ScrollCollectionPane](by-memory/0x00561db0-0x0056325b.ScrollCollectionPane.md)
- Type evidence: [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md), [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md)
- Current recovered file: `source-3/simroot_v2/class_ScrollCollectionPane.cpp`
- Confidence: strong for behavior, medium for final original source file.

## Class Purpose

`ScrollCollectionPane` is a `Pane`-derived scrollbar. It tracks orientation, range, position, enable/highlight flags, hover region, and drag offset. `CollectionPane` constructs it, but its behavior is generic scrollbar behavior and should be reviewed with the broader scroll-control family before migration.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScrollCollectionPane` | `0x00561db0-0x00561e50` | Constructs pane, installs three vtable views, and initializes orientation/state. |
| `SetMaxRange` | `0x00561ec0-0x00561f1a` | Updates max range and clamps/invalidates. |
| `SetScrollPosition` | `0x00561f20-0x00561f46` | Updates current position and invalidates. |
| `EnableScrollbar` | `0x00561f50-0x00561f69` | Enables display/interaction state. |
| `HandleScrollInput` | `0x00561fb0-0x00562190` | Handles mouse/drag input and active region transitions. |
| `CanScroll` | `0x005621a0-0x005621a4` | Boolean virtual. |
| `OnScrollReset` | `0x005621b0-0x005621e2` | Resets or schedules scroll update state. |
| `DrawScrollbar` | `0x005621f0-0x005628cf` | Draws track/thumb assets. |
| `HitTestScrollRegion` | `0x005628d0-0x00562bed` | [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) that maps a point to scrollbar region `0..4` or `-1`. |
| `GetScrollRegionRect` | `0x00562bf0-0x00562e76` | Computes part rectangles. |
| `SetHighlightedRegion` / active-region drag setup | `0x00562e80-0x00562fb0` | [UID:0001GV][0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers](by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md); IDA does not currently model either start as a function object. |
| `UpdateDragScroll` | `0x00562fb0-0x00563070` | [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md); checks cursor/active region and clears stale highlight when needed. |
| `UpdatePositionFromCursor` | `0x00563070-0x005631fd` | [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md); maps cursor coordinates to a scrollbar position and calls `CollectionPane::OnScrollPositionChanged`. |
| `ClearHighlight` | `0x00563200-0x0056325c` | [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneClearHighlightRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneClearHighlightRaw.md); IDA does not currently model this start as a function object. Clears hover/highlight state. |

## Boundary Notes

- IDA MCP confirms most function objects in this range, but `lookup_funcs` reports `0x00562e80` and `0x00563200` as not functions.
- IDA confirms the omitted hit-test helper at `0x005628d0`; active generated output calls it by name but does not emit it as a scoped method.
- Raw IDA disassembly still shows complete executable bodies at both addresses.
- Wave3 omits the raw helper at `0x00562ef0` and IDA-confirmed helpers at `0x00562fb0` and `0x00563070`.
- Constructor stores vtables `0x00623fa4`, `0x00623ff0`, and `0x00624020`; local state offsets are recorded in [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md).

## Cross-References

- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md)
- [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md)
- [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md)
- [UID:0001GV][0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers](by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/78`.
  - Before: The page was unevaluated despite detailed method, layout, vtable, raw-helper, and boundary documentation.
  - After: Scored as high completion with medium-high confidence because behavior is well mapped, while final source-file placement and several raw helper starts remain open.
  - Evidence: Existing method notes, boundary notes, layout/vtable references, and exact by-memory child pages support the score.
- 2026-05-31: Marked reconstructable in validator metadata.
  - Before: The page documented source-owned scrollbar behavior but left `RECONSTRUCTABLE` blank.
  - After: `RECONSTRUCTABLE` is set to `TRUE`; parent UID and C++ remain blank because the standalone-vs-`ScrollBar` source placement and raw helper split are not at the 95+ source-code gate.
  - Evidence: IDA MCP confirms constructor, setters, input/paint helpers, vtable stores, and associated layout offsets in the linked memory/type pages.
