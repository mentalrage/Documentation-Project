*** UID:0000BU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RectBounds

## Status

- Confidence: strong for behavior and layout; medium for final source folder.
- Likely source file: [UID:0000N2][RectBounds](by-file/RectBounds.md)
- Address ranges: [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md) RectBounds predicate/combination methods and [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md)
- Current recovered file: `source-3/simroot_v2/class_RectBounds.cpp`
- Imported source file: `RectBounds.cpp`

## Class Purpose

`RectBounds` is a lightweight four-int rectangle value object with `left`, `top`, `right`, and `bottom` edges. Member helpers test emptiness, compare size, test point/rectangle containment, intersect/union into outputs, set exact edges, translate in place, inset/shrink in place, quarter-scale inward/outward into outputs, apply anchor-based rectangle adjustments, accumulate a union, and clamp a fixed-size rectangle into a containing bounds rectangle.

The class has no confirmed vtable and should be treated as a POD-style C++ helper around a raw four-int `RECT`-like layout.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `IsEmptyOrInvalid` | `0x004b7670-0x004b7685` | Returns true when `bottom <= top || right <= left`. |
| `HasSameSizeAs` | `0x004b7690-0x004b76c8` | Compares width and height against another rectangle. |
| `ContainsPoint` | `0x004b76d0-0x004b76f8` | Half-open point hit-test. |
| `ContainsRect` | `0x004b7700-0x004b7774` | Treats an empty input rectangle as contained; otherwise tests full containment. |
| `IntersectInto` / `UnionInto` | `0x004b7780-0x004b78c8` | Writes intersection or union into an output rectangle. |
| `SetLTRB` | `0x004b78d0-0x004b78ee` | Assigns `left`, `top`, `right`, and `bottom` directly. |
| `Offset` | `0x004b78f0-0x004b7908` | Adds `dx` to left/right and `dy` to top/bottom. |
| [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) | `0x004b7910-0x004b795e` | Insets/shrinks the rectangle by x/y deltas and collapses inverted axes to their midpoint; omitted from active output. |
| `UnionWith` | `0x004b7a00-0x004b7a77` | Expands this rectangle to include another rectangle, copying the incoming rectangle if this one is empty. |
| `ClampWithin` | `0x004b7a80-0x004b7ae8` | Translates this rectangle enough to keep it inside the supplied containing edges while preserving size. |
| `InsetByQuarter` / `OutsetByQuarter` | `0x004b7af0-0x004b7c1f` | Raw helper pair that writes quarter-inset or quarter-outset rectangles into an output record. |
| Rect anchor transform helpers | `0x004b7f90-0x004b83c5` | Raw 3x3 anchor remap and axis-adjust helpers split by unrelated string/file/path helpers in the binary. |

## Layout Notes

See [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md). The layout is:

| Offset | Field |
| --- | --- |
| `+0x00` | `left` |
| `+0x04` | `top` |
| `+0x08` | `right` |
| `+0x0c` | `bottom` |

Empty/invalid tests use `right <= left || bottom <= top`.

## Evidence Notes

- IDA MCP `lookup_funcs` confirms all four active methods plus omitted `0x004b7910`.
- 2026-05-28 IDA MCP review resolves the prior `0x004b7660-0x004b78d0` UNKNOWN gap into the final `FramePartPane` destructor byte, padding, and [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md) RectBounds predicate/combination methods.
- `0x004b7670` decompiles to the empty/invalid predicate and `0x004b76d0` decompiles to the half-open point predicate; raw disassembly confirms the size/contain/intersect/union helpers between them and `SetLTRB`.
- 2026-05-28 raw disassembly resolves the prior `0x004b7ae8-0x004b7c30` UNKNOWN gap as [UID:00022H][0x004b7af0-0x004b7c1f.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c1f.RectBoundsQuarterScaleHelpers.md) RectBounds quarter-scale helpers plus padding; the helpers use `0.25f` and `0.5f` constants.
- 2026-05-28 raw disassembly resolves anchor-transform helpers at [UID:00022I][0x004b7f90-0x004b8198.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8198.RectAnchorTransformHelpers.md) and [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md); these helpers still need caller-side naming confirmation.
- IDA MCP caller checks show very broad use for `SetLTRB` and `Offset`, while `ClampWithin` currently has only two direct callers from a world-map-style visible-bounds path.
- `simroot_v2` recovered free helpers reuse the same layout for `InitRectBounds`, `IntersectRects`, `OffsetRect`, `IsRectEmptyOrInvalid`, and `RectContainsRect`.
- 2026-05-26 recheck: current generated output still omits [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md), repeats the layout helper in each emitted method body, and has no recovered [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) file.
- 2026-05-26 IDA MCP reconfirms `Inset` callers at `0x0053bcb7`, `0x0053bcd8`, and `0x0053bcf9`, all inside `sub_53BB20`.

## Cross-References

- [UID:0000N2][RectBounds](by-file/RectBounds.md)
- [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md) RectBoundsPredicateAndCombinationMethods
- [UID:00022H][0x004b7af0-0x004b7c1f.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c1f.RectBoundsQuarterScaleHelpers.md) RectBoundsQuarterScaleHelpers
- [UID:00022I][0x004b7f90-0x004b8198.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8198.RectAnchorTransformHelpers.md) RectAnchorTransformHelpers
- [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) RectAnchorAxisAdjustHelper
- [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md)
- [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md)
- [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)
- [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md)
- [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md)
- [UID:0000N3][Region](by-file/Region.md)
- [UID:0001QV][client_ui_core](by-meta/client_ui_core.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `88/84`.
  - Before: The page was unevaluated despite detailed method coverage, layout, raw helper splits, IDA evidence, and multiple exact memory/type cross-references.
  - After: Scored as high completion and strong confidence, with final source-folder placement and a few helper names still below perfect certainty.
  - Evidence: Existing method notes, layout notes, 2026-05-28 gap resolution, caller checks, omitted-output caveats, and memory/type references cover the rectangle helper thoroughly.
- 2026-06-01: Marked reconstructable and attached to [UID:0000N2][RectBounds](by-file/RectBounds.md).
  - Before: The page described a source-owned POD helper class but left autogen metadata blank.
  - After: `RECONSTRUCTABLE:TRUE` and parent `0000N2`.
  - Evidence: IDA MCP recheck confirmed the class-style method island boundaries, no callee dependencies, broad caller fanout, and four-int layout usage across the adjacent free helper island.
