*** UID:0000KB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# InventoryScrollPane

## Status

- Confidence: strong for scrollbar behavior; medium for standalone original file.
- Proposed module: `ui/inventory/InventoryScrollPane.cpp` containing `ScrollInventoryPane`, or folded into [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md).
- Projected reconstruction path: `NexusTK/ui/inventory/InventoryScrollPane.cpp`
- Evidence basis: live IDA MCP lookup/caller checks on 2026-05-24 and 2026-06-05.

## File Role

`ScrollInventoryPane.cpp` should own the item-inventory private scrollbar if final migration preserves a separate file. It handles EPF-backed track/thumb/arrow geometry, range and scroll position, mouse/timer repeat behavior, hover/highlight state, and reset-to-idle state for the newer item inventory UI.

The source may also have been a private nested/helper implementation inside `NewInventoryPane.cpp`: IDA currently observes the constructor `0x00563260` called only from `NewInventoryPane::NewInventoryPane` at `0x004eb4e4`.

## Proposed Contents

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x00563260-0x00563300` | constructor | Initializes orientation and scrollbar state. |
| `0x00563370-0x00563419` | range/position/enable helpers | Clamps scroll range and position; invalidates affected pane regions. |
| `0x00563460-0x00563692` | mouse/timer handlers | Handles drag/click interactions and auto-repeat. |
| `0x005636a0-0x00563d7f` | paint | Draws `SLIDEBG.EPF`/`SCRBUTT.EPF` track, thumb, and buttons. |
| `0x005640a0-0x0056439f` | region/highlight helpers | Computes arrow/track/thumb rectangles and updates highlighted part. |
| `0x00564520-0x005646ad` | [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) | Recomputes scroll position from drag/click geometry and calls back into `NewInventoryPane`. |
| `0x005646b0-0x0056470c` | [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) | Recovered reset helper; IDA does not currently define this as a function start, but raw disassembly is method-shaped. |
| [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md) | offsets `+0xf8` through `+0x10f` | Packed scroll style, orientation, current/range words, enabled/hover/active state, and drag point. |
| [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md) | `0x0062402c`, `0x00624078`, `0x006240a8` | Three pane views for paint, mouse input, and timer/repeat callbacks. |

## Boundary Notes

This is not the generic [UID:0000NF][ScrollBar](by-file/ScrollBar.md) module. It is a feature-specific companion used by [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md) unless later evidence proves reuse outside item inventory.

Recovered source output contains polluted helper labels from fitting-room/ranking-event/control code. Treat those as shared render/control helper names, not ownership evidence.

Current metadata reports `vtable_count: 0` even though IDA confirms three `ScrollInventoryPane` vtable bases. Keep the inventory as data debt until the vtables are recorded.

## Cross-References

- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md)
- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md)
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)

## Changes

- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/inventory/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the proposed source tree lists `InventoryScrollPane.cpp` under `ui/inventory/`.
  - After: set the validator path to `NexusTK/ui/inventory/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` places the item-inventory scrollbar file under `ui/inventory`, and live IDA MCP lookup on 2026-06-05 confirms the constructor anchor at `0x00563260` as a real function of size `0xa1`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: scrollbar role, range/position/mouse/timer/paint/highlight/drag helper groups, layout and vtable anchors, constructor caller, and feature-specific boundary are documented; confidence is capped by whether it was standalone or folded into `NewInventoryPane`.
