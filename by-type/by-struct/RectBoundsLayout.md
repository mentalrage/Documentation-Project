*** UID:0001VP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RectBoundsLayout

## Status

- Confidence: very strong.
- Canonical source owner: [UID:0000N2][RectBounds](by-file/RectBounds.md), with the sole formal declaration emitted by [UID:0000BU][RectBounds](by-class/RectBounds.md).
- Source disposition: duplicate layout evidence only; intentionally non-emitting with blank formal CPP/H.
- Primary memory evidence: [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) RectBounds predicate/combination methods, [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md), [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBounds quarter-scale helpers, and [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)
- Size evidence: `sizeof(RectBounds) == 16` from four 4-byte method writes, helper signatures, and 16-byte rectangle copies.
- Verification basis: IDA MCP `lookup_funcs`, decompilation, and raw disassembly review on 2026-05-31; older recovered metadata is not used as authority for this layout score.

## Layout

`RectBounds` and the related `RECT`-style helpers use the same four-int layout. This is a POD-style value record, not a vtable object and not a hidden-state class:

| Offset | Size | Field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | `left` | First field written by `SetLTRB` at `0x004b78d0` and `InitRectBounds` at `0x004b7c50`; compared against `right` for emptiness and point hit-testing. |
| `+0x04` | 4 | `top` | Second field written by setters; compared against `bottom`; `PointInRect` at `0x004b7e80` checks `top <= y`. |
| `+0x08` | 4 | `right` | Third field; width is `right - left`; `RectArea` multiplies this width by height without empty checks. |
| `+0x0c` | 4 | `bottom` | Fourth field; height is `bottom - top`; `PointInRect` at `0x004b7e80` checks `y < bottom`. |

## IDA Verification Notes

- `lookup_funcs 0x004b78d0` reports size `0x1e`; decompilation writes `this[0..3]` from four edge arguments in left/top/right/bottom order.
- `lookup_funcs 0x004b7c50` reports size `0x1f`; decompilation initializes the same four fields through a free helper used by many UI panes.
- `lookup_funcs 0x004b7ca0` reports size `0x16`; decompilation returns `(right - left) * (bottom - top)`.
- `lookup_funcs 0x004b7e80` reports size `0x27`; decompilation confirms the half-open point test `left <= x < right` and `top <= y < bottom`.
- IDA raw disassembly confirms unmodeled function-shaped rectangle helpers at `0x004b7690`, `0x004b7780`, `0x004b7830`, `0x004b7af0`, and `0x004b7b90`; these operate on the same four-int field order.

## Semantics

- Empty or invalid: `right <= left || bottom <= top`.
- Point hit-testing is half-open: `left <= x < right` and `top <= y < bottom`.
- Union helpers copy the non-empty input when the other input is empty.
- Inset helpers collapse inverted axes to the midpoint rather than allowing negative width or height. [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) specifically uses strict `left > right` / `top > bottom` tests, preserves exact zero width or height, treats negative deltas as expansion/outset, and computes the collapse midpoint with signed MSVC truncation-toward-zero division by two. [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) now uses the same source-facing free-helper name direction for `InsetRect`; historical `InflateRect_4B7E30` wording is stale alias/search text only.
- `RectBounds::IntersectWith(const RectBounds *bounds)` at `0x004b7960-0x004b79f7` computes an in-place intersection by taking `max(left)`, `max(top)`, `min(right)`, and `min(bottom)`. It clears all four receiver fields to zero and returns `false` when the receiver, input, or resulting intersection is empty/invalid; otherwise it writes the intersection and returns `true`.
- `0x004b7af0` / `RectBounds::InsetByQuarter` derives a half-size centered rectangle by insetting each side by `0.25f` of width/height, using `+0.5f` before truncating the left/top edges. `0x004b7b90` / `RectBounds::OutsetByHalf` derives a double-size rectangle by outsetting each side by `0.5f` of width/height, using `-0.5f` before truncating the left/top edges. Both write the same four-int `left, top, right, bottom` output layout.
- Both class and free point tests preserve current binary/source-facing argument order `y, x`; `ContainsPoint(int x, int y)` and `PointInRect(int x, int y, ...)` are rejected because they would invert the observed stack order.
- The shared point support type used by the free helper island is source-facing `Point { int y; int x; }` in project `y, x` storage order. [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) emits `InitPointPair(Point *point, int y, int x)`, writing `y` at offset `0` and `x` at `+4`. `PointPair` remains descriptive/historical wording in older layout notes; it is not the formal UID00015S emitted type.
- Anchor transform helpers remap 3x3 anchor indices and adjust low/high edge pairs in place through pointer arguments; the corrected transform range is [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md), and its axis primitive receives pointers to `left/right` or `top/bottom` edge slots of two `RectBoundsLayout` records.
- `RectArea` computes signed `(right - left) * (bottom - top)` without checking for empty/invalid rectangles.
- `RectArea` is cdecl/free-helper-shaped (`int RectArea(const RectBounds *bounds)`): it takes a stack rectangle pointer, uses no `ecx` receiver, and therefore should not be used as proof of class-method ownership even though it reads this layout.
- `RectContainsRect` in the free helper island is ordered `RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)`: empty inner rectangles are contained, while non-empty inner rectangles require a non-empty outer rectangle that fully contains all four edges.
- Older recovered method bodies repeated this layout declaration inside individual RectBounds methods. Source reconstruction should keep one shared declaration.
- B008's [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) source-quality pass reinforces that exact method bodies should use the shared `RectBounds` fields directly. Do not introduce per-method `RectBoundsLayout` structs or `GetRectBoundsLayout` helper scaffolding in source C++ for this value record.
- B008's [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) support pass adds another edge-order consumer: `InitRectBounds` receives `(screenX-r, screenY-r, screenX+r, screenY+r)` for full local-player screen bounds and `(screenX-r, screenY, screenX+r, screenY+r)` for lower-body bounds. This confirms the target stores screen-space `left, top, right, bottom` edges rather than `x, y, width, height`.

## Cross-References

- [UID:0000N2][RectBounds](by-file/RectBounds.md)
- [UID:0000BU][RectBounds](by-class/RectBounds.md)
- [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) RectBoundsPredicateAndCombinationMethods
- [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md)
- [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBoundsQuarterScaleHelpers
- [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) RectAnchorTransformHelpers
- [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) RectAnchorAxisAdjustHelper
- [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md)
- [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)
- [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md)
- [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md)

## Changes

- 2026-08-18 UID0000N2 whole-file callback:
  - Raised this duplicate-support page to `94/95`, retained canonical owner [UID:0000N2][RectBounds](by-file/RectBounds.md), and cleared its emitter route. Both formal channels remain blank.
  - Confirmed there is no distinct `RectBoundsLayout` source type or second UDT: the documented fields are the sole `RectBounds` declaration emitted by [UID:0000BU][RectBounds](by-class/RectBounds.md). This page preserves cross-family layout evidence without generating a duplicate declaration or empty-emitter marker.
  - Reconfirmed exact `sizeof(RectBounds) == 16`, fields `left@0`, `top@4`, `right@8`, `bottom@12`, no vptr/base/tail state, and source semantics shared by the member/free/private helpers.
  - Preserved the historical `RectBoundsLayout` label as documentation/search vocabulary only. Final source uses human-written `RectBounds` and `Point`, not an IDA-derived alias, accessor wrapper, or per-method layout scaffold.
  - Recorded the sole declaration route as `by-class/RectBounds.md` -> `NexusTK/ui/core/RectBounds.h`; source definitions continue through the exact by-memory children under [UID:0000N2][RectBounds](by-file/RectBounds.md).

- 2026-07-06 B015 RectGeometryHelpers implementation support:
  - Score unchanged.
  - Summary/evidence: added the UID00015S point and free-helper decisions to the layout semantics. [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) now emits `Point { y, x }`, `InitPointPair(Point *point, int y, int x)`, `InsetRect`, canonical `PointInRect(y, x, bounds)`, and `RectContainsRect(innerBounds, outerBounds)` through [UID:0000N2][RectBounds](by-file/RectBounds.md). Live MCP session `supervisor_recovery_20260705` confirmed y/x point storage, half-open point testing, midpoint-clamping inset behavior, and containment order. Historical `InflateRect_4B7E30` and `PointPair` wording is preserved only as stale/search/descriptive context where older support pages use it.

- 2026-06-26 B001 RectBoundsMethods implementation support:
  - Score unchanged.
  - Summary/evidence: added `RectBounds::IntersectWith` layout semantics from [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md): in-place max-left/max-top/min-right/min-bottom intersection, zero clearing on empty input/result, and `bool` success return.
- 2026-06-21 B008 [UID:0003UH][0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.UserPaneUpdateScreenPosition.md) support sync:
  - Added the full and lower local-player screen-bound constructions as evidence for edge-ordered `left, top, right, bottom` layout in screen space.
- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank even though the page already had useful layout notes.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `84`, confidence `88`.
- Evidence: IDA MCP verified representative modeled functions for field writes, area calculation, and half-open hit-testing; IDA raw disassembly verified additional unmodeled rectangle helper bodies using the same four-int layout. Scores stay below `95+` because original source naming, final declaration placement, and every downstream use site are not exhaustively audited.
- 2026-06-13 A002 Goal2 support refresh:
  - Before: `COMPLETION:84`, with the anchor transform helper reference still using stale end `0x004b8198`.
  - Changed to: `COMPLETION:85` and corrected the anchor helper reference to `0x004b7f90-0x004b8194`.
  - Evidence: live IDA MCP confirmed the transform helpers copy and adjust paired four-int records, call the axis primitive on `left/right` and `top/bottom` edge slots, and end before `0xcc` padding at `0x004b8194-0x004b81a0`.
- 2026-06-19 B001 accepted RectBounds class implementation:
  - Added explicit `sizeof(RectBounds) == 16`, preserved `left/top/right/bottom` edge layout, corrected quarter-scale semantics to `InsetByQuarter` / `OutsetByHalf`, preserved `y, x` point-test order, and documented the `RectArea` cdecl/free-helper split.
  - Evidence: accepted B001 report plus current RectBounds class/free-helper pages and PE/Capstone evidence for `0x0061a880 == 0.25f`, `0x006104b0 == 0.5f`, and file-level `RectArea` shape.
- 2026-06-19 B008 RectBoundsInset body implementation support:
  - Score unchanged.
  - Summary/evidence: incorporated exact [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) field behavior into the layout semantics: `left += dx`, `right -= dx`, `top += dy`, `bottom -= dy`, strict inverted-axis midpoint collapse only, signed truncation-toward-zero midpoint calculation, and no per-method generated layout scaffolding in draft source.
