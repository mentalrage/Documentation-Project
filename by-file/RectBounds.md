*** UID:0000N2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# RectBounds

## Status

- Confidence: strong for behavior and shared geometry ownership; medium-strong for final folder.
- Proposed module: `ui/core/RectBounds.cpp`
- Proposed header: `ui/core/RectBounds.h` or shared geometry header.
- Current source-owner state: IDA-backed RectBounds pages cover the compact class-style method cluster plus adjacent raw geometry helpers; final split between class methods and file-local helpers remains under review.
- Main class: [UID:0000BU][RectBounds](by-class/RectBounds.md)
- Main address docs: [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md) RectBounds predicate/combination methods, [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md), [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBounds quarter-scale helpers, and [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)

## File Role

`RectBounds.cpp` is the likely shared rectangle/point geometry primitive source. It owns a four-int `left, top, right, bottom` value object and free helpers for initialization, intersection, union, offsetting, inflation/inset, point-hit tests, empty/equivalent checks, and containment.

Keep this separate from [UID:0000N3][Region](by-file/Region.md). `Region.cpp` owns dirty-region wrapper objects and later `Motion`-named dirty-rectangle helpers; `RectBounds.cpp` owns the lower-level value record and raw geometry operations reused by UI, render, map, and resource code.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000BU][RectBounds](by-class/RectBounds.md) | `0x004b7670-0x004b78c8`, `0x004b78d0`, `0x004b78f0`, [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md), `0x004b7a00`, `0x004b7a80` | Member-style predicate, containment, intersection, union, setter, translation, inset, and clamp helpers over the four-int bounds record. |
| [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBoundsQuarterScaleHelpers | `0x004b7af0-0x004b7c21` | Raw helper pair that writes quarter-inset and quarter-outset rectangles into caller-provided outputs. |
| [UID:00022I][0x004b7f90-0x004b8198.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8198.RectAnchorTransformHelpers.md) RectAnchorTransformHelpers / [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) RectAnchorAxisAdjustHelper | `0x004b7f90-0x004b8198`, `0x004b8290-0x004b83c5` | Raw 3x3 anchor remap and axis-adjust helpers; likely geometry/layout support, though final source ownership is still open. |
| [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md) | four `int` fields | Shared `left, top, right, bottom` memory layout used by class and free helpers. |
| `InitPointPair` | `0x004b7c30-0x004b7c43` | Two-int point initializer; likely same small geometry support file. |
| `InitRectBounds` / `InitRect_4B7C70` | `0x004b7c50-0x004b7c95` | Set exact edges or set from left/top/width/height. |
| [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) | `0x004b7ca0-0x004b7cb6` | Computes signed width-times-height; IDA-confirmed, with final declaration owner still open. |
| `IntersectRects`, `UnionRect_4B7D70` | `0x004b7cc0-0x004b7e03` | Free intersection/union helpers for raw rect records. |
| `OffsetRect`, `InflateRect_4B7E30` | `0x004b7e10-0x004b7e7f` | Free translate and inset/inflate helpers. |
| `PointInRect_4B7E80` | `0x004b7e80-0x004b7ea7` | Half-open point hit-test with arguments ordered `y, x, rect`. |
| `IsRectEmptyOrInvalid`, `RectsEquivalent`, `RectContainsRect` | `0x004b7eb0-0x004b7f87` | Free predicates used across layout, clipping, and dirty-region callers. |
| [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) | `0x004bb2e0-0x004bb5a5` | Related line-segment clipping helper pair used by software render line callbacks; final owner may stay with render callbacks if original source evidence points there. |

## Evidence Notes

- Active metadata imports `RectBounds` from `RectBounds.cpp` and describes it as a small four-edge value object used throughout UI and rendering.
- IDA MCP confirms class method starts and sizes: `0x004b78d0` size `0x1e`, `0x004b78f0` size `0x18`, `0x004b7a00` size `0x77`, and `0x004b7a80` size `0x68`.
- 2026-05-28 IDA MCP resolves the earlier gap before `SetLTRB` as [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md) RectBounds predicate/combination methods: modeled functions at `0x004b7670` and `0x004b76d0` plus raw function-shaped starts at `0x004b7690`, `0x004b7700`, `0x004b7780`, and `0x004b7830`.
- 2026-05-28 IDA MCP/raw disassembly resolves the gap before free geometry helpers as [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBounds quarter-scale helpers; 2026-06-06 IDA MCP corrected the end to `0x004b7c21` so both `retn 4` operands remain inside the helper bodies. No direct code or pointer xrefs were found.
- 2026-05-28 IDA MCP/raw disassembly resolves raw rect-anchor transform helpers at [UID:00022I][0x004b7f90-0x004b8198.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8198.RectAnchorTransformHelpers.md) and [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md). They use 3x3 anchor index remapping and direct calls from the transform cluster to the axis-adjust helper.
- IDA MCP also confirms an omitted class-shaped helper at `0x004b7910` size `0x4e`; the body insets/shrinks the rectangle and clamps inverted axes to their midpoint.
- IDA caller output shows broad fan-in: `SetLTRB` is truncated after 10 entries with 184 more callers, `Offset` with 157 more, `InitRectBounds` with 1560 more, and `PointInRect` with 227 more.
- 2026-05-26 IDA MCP recheck confirms the same helper family and still reports `0x004b7f90` as not a function, keeping the geometry helper island bounded at `0x004b7f87`.
- IDA-backed memory docs keep both `0x004b7910` and [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) visible as separate exact helper pages while final declaration ownership is unresolved.
- `UnionWith` caller evidence includes transfer-server/layout accumulation paths; `ClampWithin` caller evidence is narrow and currently tied to world-map visible-rectangle clamping.
- 2026-05-25 IDA MCP confirms the related [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) island calls `PointInRect_4B7E80` and is called only by the compatibility/RGB565 software line callbacks.

## Source-Structure Decision

Use a separate `RectBounds.cpp` source family rather than spreading helpers across every feature that calls them. The call fanout is too broad for UI dialogs, map panes, render image libraries, or resource loaders to own these functions.

The final folder is still open:

- `ui/core/RectBounds.cpp` is now the active placement because `by-project-structure/proposed-source-tree.md` lists it with the `Pane`, `Layer`, and `Region` core UI geometry family, and IDA caller fanout shows these helpers are base UI/render infrastructure rather than feature-owned code.
- `util/RectBounds.cpp` or `util/Geometry.cpp` may be a better late-1999/early-2000s shared utility placement if later project-structure evidence shows the original source had common geometry primitives outside UI.

For current migration planning, keep it adjacent to [UID:0000N3][Region](by-file/Region.md) and [UID:0000KL][Layer](by-file/Layer.md), but do not merge it into `Region.cpp`.

Keep [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) cross-referenced here but not locked to `RectBounds.cpp` yet. It is rectangle geometry by behavior, while its only direct callers are software-render line callbacks.

## Generated Output Caveats

- Active `class_RectBounds.cpp` omits or under-materializes several early predicate/combination methods in [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md), and also omits `0x004b7910`, even though IDA models it as a real function with direct callers.
- Active `class_RectBounds.cpp` repeats `RectBoundsLayout` and `GetRectBoundsLayout` inside every emitted method. Treat that as generated normalization noise; source reconstruction should use one shared declaration.
- Active recovered output splits the free geometry helpers into one-function `recovered/*.cpp` files. Treat those as staging containers, not likely original source files.
- Active output does not currently materialize the [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) even though IDA confirms it and caller checks find direct users.

## Cross-References

- [UID:0000BU][RectBounds](by-class/RectBounds.md)
- [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md) RectBoundsPredicateAndCombinationMethods
- [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md)
- [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBoundsQuarterScaleHelpers
- [UID:00022I][0x004b7f90-0x004b8198.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8198.RectAnchorTransformHelpers.md) RectAnchorTransformHelpers
- [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) RectAnchorAxisAdjustHelper
- [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)
- [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md)
- [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md)
- [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md)
- [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md)
- [UID:0000N3][Region](by-file/Region.md)
- [UID:0000KL][Layer](by-file/Layer.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0001QV][client_ui_core](by-meta/client_ui_core.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `90`, confidence `82`.
- Summary/evidence: the page documents geometry primitive role, contents, IDA fanout/evidence, raw helper islands, source-structure decision, generated-output caveats, type refs, and cross-references; confidence remains capped by final `ui/core` versus `util` placement and line-clip ownership uncertainty.
- 2026-06-01: Changed proposed reconstruction path from blank to `NexusTK/ui/core/`.
  - Before: the by-file page kept the path blank even though the proposed source tree already listed `ui/core/RectBounds.cpp`.
  - After: validator metadata now stages the page under `NexusTK/ui/core/`.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `RectBounds.cpp` in `ui/core`, and IDA MCP caller fanout for `SetLTRB`, `Offset`, `InitRectBounds`, and `PointInRect` supports base UI/render infrastructure ownership rather than a feature module.
