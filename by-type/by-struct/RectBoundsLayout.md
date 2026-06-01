*** UID:0001VP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RectBoundsLayout

## Status

- Confidence: strong.
- Likely owner: [UID:0000N2][RectBounds](by-file/RectBounds.md)
- Primary memory evidence: [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md) RectBounds predicate/combination methods, [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md), [UID:00022H][0x004b7af0-0x004b7c1f.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c1f.RectBoundsQuarterScaleHelpers.md) RectBounds quarter-scale helpers, and [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)
- Size evidence: 16 bytes from method writes and helper signatures.
- Verification basis: IDA MCP `lookup_funcs`, decompilation, and raw disassembly review on 2026-05-31. Generated Wave3/simroot data is not used as authority for this layout score.

## Layout

`RectBounds` and the related `RECT`-style helpers use the same four-int layout:

| Offset | Size | Field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | `left` | First field written by `SetLTRB` at `0x004b78d0` and `InitRectBounds` at `0x004b7c50`; compared against `right` for emptiness and point hit-testing. |
| `+0x04` | 4 | `top` | Second field written by setters; compared against `bottom`; `PointInRect_4B7E80` checks `top <= y`. |
| `+0x08` | 4 | `right` | Third field; width is `right - left`; `RectArea` multiplies this width by height without empty checks. |
| `+0x0c` | 4 | `bottom` | Fourth field; height is `bottom - top`; `PointInRect_4B7E80` checks `y < bottom`. |

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
- Inset/inflate helpers collapse inverted axes to the midpoint rather than allowing negative width or height.
- Quarter-scale helpers derive inset/outset rectangles using `0.25f` of width/height and `0.5f` rounding offsets for left/top edges.
- Anchor transform helpers remap 3x3 anchor indices and adjust low/high edge pairs in place through pointer arguments.
- `RectArea` computes signed `(right - left) * (bottom - top)` without checking for empty/invalid rectangles.
- Current generated output repeats this layout declaration inside every `class_RectBounds.cpp` method body. Source reconstruction should keep one shared declaration.

## Cross-References

- [UID:0000N2][RectBounds](by-file/RectBounds.md)
- [UID:0000BU][RectBounds](by-class/RectBounds.md)
- [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md) RectBoundsPredicateAndCombinationMethods
- [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md)
- [UID:00022H][0x004b7af0-0x004b7c1f.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c1f.RectBoundsQuarterScaleHelpers.md) RectBoundsQuarterScaleHelpers
- [UID:00022I][0x004b7f90-0x004b8198.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8198.RectAnchorTransformHelpers.md) RectAnchorTransformHelpers
- [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) RectAnchorAxisAdjustHelper
- [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md)
- [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)
- [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md)

## Changes

- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank even though the page already had useful layout notes.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `84`, confidence `88`.
- Evidence: IDA MCP verified representative modeled functions for field writes, area calculation, and half-open hit-testing; IDA raw disassembly verified additional unmodeled rectangle helper bodies using the same four-int layout. Scores stay below `95+` because original source naming, final declaration placement, and every downstream use site are not exhaustively audited.
