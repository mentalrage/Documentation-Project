*** UID:0000CK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollInventoryPane

## Status

- Confidence: strong for scrollbar behavior, medium for one reset-helper boundary.
- Likely source file: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md), or folded into [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md)
- Address range: [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- Layout: [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md)
- Vtables: [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)
- Current recovered file: `source-3/simroot_v2/class_ScrollInventoryPane.cpp`

## Class Purpose

`ScrollInventoryPane` is the EPF-backed scrollbar pane used by the newer item inventory UI. It manages scroll range, current position, orientation, highlighted region, drag tracking, auto-repeat timers, and scrollbar painting.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScrollInventoryPane` | `0x00563260-0x00563301` | Constructs scrollbar pane with vertical or horizontal orientation. |
| `SetMaxRange` | `0x00563370-0x005633ca` | Clamps max range and current position. |
| `SetScrollPosition` | `0x005633d0-0x005633f6` | Updates scroll position and invalidates. |
| `EnableScrollbar` | `0x00563400-0x00563419` | Enables the control and invalidates. |
| `OnMouseEvent` | `0x00563460-0x00563640` | Handles drag and click interactions. |
| `OnTimerEvent` | `0x00563660-0x00563692` | Handles held-button auto-scroll. |
| `OnPaint` | `0x005636a0-0x00563d7f` | Paints track, thumb, and arrows with EPF assets. |
| `GetScrollbarRegionRect` | `0x005640a0-0x00564326` | Returns rectangles for arrow, track, and thumb parts. |
| `SetHighlightRegion` | `0x00564330-0x0056439f` | Updates highlighted region and invalidates. |
| `UpdateFromDrag` candidate | [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) | Recomputes the scroll position from drag/click geometry and notifies the owning inventory pane. |
| `ResetScrollState` candidate | [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) | Raw method-shaped reset helper; IDA does not currently define a function at this start. |

## Evidence Notes

- IDA MCP confirms constructor, paint, and region-rect functions.
- IDA MCP caller check on 2026-05-24 shows the constructor `0x00563260` is only directly called from `NewInventoryPane::NewInventoryPane` at `0x004eb4e4`.
- IDA MCP lookup confirms the activation helper `0x00563400` as a real `0x1a`-byte function.
- IDA reports no function at `0x005646b0`; previous modeled function is `0x00564520-0x005646ad`, and raw disassembly shows method-shaped reset code through `0x0056470c` before the next function at `0x00564710`. Treat the reset-helper function-table mismatch as data debt.
- IDA-backed allocation and constructor evidence records a `0x110`-byte pane object with the scrollbar tail layout now tracked in [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md). The generated `m_highlightRegion` name at `+0x104` is weaker than the raw reset evidence, which treats `+0x103` as the stale hover/highlight part and `+0x104` as active state.
- 2026-05-26 IDA MCP confirms vtable bases `0x0062402c`, `0x00624078`, and `0x006240a8`, with paint, mouse, and timer slots mapped in [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md).

## Cross-References

- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md)
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `80/78`.
  - Before: The page was unevaluated despite documenting the inventory scrollbar methods, owner/caller, layout, vtables, and reset-helper mismatch.
  - After: Scored as high completion with medium-high confidence because scrollbar behavior is strong, while one raw reset-helper boundary and source placement remain unresolved.
  - Evidence: Existing method notes, IDA caller/evidence notes, layout/vtable references, and NewInventoryPane relationship support the score.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE`.
  - Before: The class page documented project-owned behavior but had no validator reconstructable flag.
  - Changed to: The page is flagged as rebuild-owned while `AUTOGEN_PARENT_UID` and C++ remain blank.
  - Evidence: IDA MCP confirms `NewInventoryPane::NewInventoryPane` allocates a 0x110-byte pane, calls the `0x00563260` constructor, and stores the result as an owned item-inventory scrollbar; final source-file placement and source-quality C++ are not at the 95+ gate.
