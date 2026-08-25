*** UID:0000N2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# RectBounds

## UID0000KA Geometry Consumer - 2026-08-15

All legacy/Pane2 fixed buttons, list/grid slots, hit tests, item bounds, and help placement use existing `RectBounds`, `InitRectBounds`, and `PointInRect(y,x,&bounds)` declarations from `ui/core/RectBounds.h`. The accepted source removes wrong-form `Rect` and `PtInRect` proxies while preserving exact coordinate order and invalid-rectangle results. RectBounds retains geometry ownership and score.

## Status

- Confidence: very strong for complete behavior, ownership, source partition, and final folder; private helper spellings remain inferred.
- Final module: `NexusTK/ui/core/RectBounds.cpp`
- Final header: `NexusTK/ui/core/RectBounds.h`
- Current source-owner state: accepted B001 source-quality pass resolves the declaration split. [UID:0000BU][RectBounds](by-class/RectBounds.md) owns the POD `struct RectBounds` shell and member-shaped methods, while cdecl helpers beginning at `0x004b7c30` are file-level/static `RectBounds.cpp` geometry helpers.
- Main class: [UID:0000BU][RectBounds](by-class/RectBounds.md)
- Main address docs: [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) RectBounds predicate/combination methods, [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md), [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBounds quarter-scale helpers, and [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)

## 2026-08-17 EPFTileContext Dependency Closure

[UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) now carries the exact formal H declaration `int RectArea(const RectBounds *bounds);` in this source family. EPFTileContext calls that free cdecl helper at `0x004580de`, `0x004581da`, and `0x0045833d` from its two half-scale implementations; the FontImageLib caller at `0x004b621a` remains unchanged. RectBounds continues to own the helper body and declaration, while EPFTileContext includes `RectBounds.h` as a dependency and does not duplicate the helper.

## File Role

`RectBounds.cpp` is the likely shared rectangle/point geometry primitive source. It owns a four-int `left, top, right, bottom` value object and free helpers for initialization, intersection, union, offsetting, inset/shrink-expand adjustment, point-hit tests, empty/equivalent checks, and containment.

Keep this separate from [UID:0000N3][Region](by-file/Region.md). `Region.cpp` owns dirty-region wrapper objects and later `Motion`-named dirty-rectangle helpers; `RectBounds.cpp` owns the lower-level value record and raw geometry operations reused by UI, render, map, and resource code.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000BU][RectBounds](by-class/RectBounds.md) | `0x004b7670-0x004b78c7`, `0x004b78d0`, `0x004b78f0`, [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md), `0x004b7960-0x004b79f7`, `0x004b7a00`, `0x004b7a80` | Member-style predicate, containment, output intersection/union, setter, translation, void in-place inset, in-place bool `IntersectWith`, in-place union, and clamp helpers over the four-int bounds record. The early island's authored end is exact; `[0x004b78c7,0x004b78d0)` is independent alignment. |
| [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBoundsQuarterScaleHelpers | `0x004b7af0-0x004b7c21` | Raw `RectBounds` class-method pair that writes a quarter-inset half-size rectangle and a half-outset double-size rectangle into caller-provided outputs. Fresh PE scan found no direct pointer or branch route, so current liveness is retained unused source-authored member code; the second helper is `OutsetByHalf`, not `OutsetByQuarter`. |
| [UID:00040U][0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant](by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md) RectBoundsQuarterScaleConstant | `0x0061a880-0x0061a884` | Exact compiler-pooled `0.25f` dword used only by `RectBounds::InsetByQuarter` at `0x004b7b15` and `0x004b7b43`; final human source uses two inline `0.25f` expressions and does not invent a named global. UID00040U is non-emitting. |
| [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) RectAnchorTransformHelpers / [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) RectAnchorAxisAdjustHelper | `0x004b7f90-0x004b8194`, `0x004b8290-0x004b83c5` | File-local/static `RectBounds.cpp` 3x3 anchor remap, rectangle-pair transform, and axis-adjust helpers. B003 supplied accepted first-draft body-level C++ for both pages; the raw transform starts still have no direct external xrefs, but the helper pair remains source-authored RectBounds geometry/layout support through the four-call axis-helper relationship. |
| [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md) | four `int` fields | Shared `left, top, right, bottom` memory layout used by class and free helpers. |
| `InitPointPair` | `0x004b7c30-0x004b7c43` | Two-int `Point` initializer in project `y, x` order; writes `Point.y` at offset `0` and `Point.x` at `+4`. `PointPair` is historical/descriptive wording only, not the formal UID00015S emitted type. |
| `InitRectBounds` / `InitRectBoundsFromSize` | `0x004b7c50-0x004b7c95` | Set exact edges or set from left/top/width/height; `InitRect_4B7C70` is only a stale address-suffixed placeholder. |
| [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) | `0x004b7ca0-0x004b7cb6` | File-level cdecl `int RectArea(const RectBounds *bounds)` helper; computes signed width-times-height with no empty/clamp/absolute/unsigned/64-bit/overflow guard and is not a true thiscall class method. |
| `IntersectRects`, `UnionRects` | `0x004b7cc0-0x004b7e03` | Free intersection/union helpers for raw rect records; `UnionRect_4B7D70` is a stale address-suffixed placeholder. |
| `OffsetRect`, `InsetRect` | `0x004b7e10-0x004b7e7f` | Free translate and inset/shrink-expand helpers. `InsetRect` positive deltas shrink/inset and negative deltas expand/outset, with strict inverted axes collapsed to signed midpoint; historical stale alias `InflateRect_4B7E30` is retained only for search provenance. |
| `PointInRect` | `0x004b7e80-0x004b7ea7` | Half-open point hit-test with arguments ordered `int y, int x, const RectBounds *bounds`; rect-first and x/y call forms in older/generated caller pages are stale caller-page issues. |
| `IsRectEmptyOrInvalid`, `RectsEquivalent`, `RectContainsRect` | `0x004b7eb0-0x004b7f87` | Free predicates used across layout, clipping, and dirty-region callers; `RectContainsRect` order is `innerBounds, outerBounds`. |
| [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) | `0x004bb2e0-0x004bb5a5` | Surface-owned line-segment clipping helper pair used exclusively by software render line callbacks. It consumes `RectBounds`/`PointInRect` but is excluded from this compilation unit. |

## Evidence Notes

- Active metadata imports `RectBounds` from `RectBounds.cpp` and describes it as a small four-edge value object used throughout UI and rendering.
- IDA MCP confirms class method starts and sizes: `0x004b78d0` size `0x1e`, `0x004b78f0` size `0x18`, `0x004b7a00` size `0x77`, and `0x004b7a80` size `0x68`.
- 2026-05-28 IDA MCP resolves the earlier gap before `SetLTRB` as [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) RectBounds predicate/combination methods: modeled functions at `0x004b7670` and `0x004b76d0` plus raw function-shaped starts at `0x004b7690`, `0x004b7700`, `0x004b7780`, and `0x004b7830`.
- 2026-06-27 B010 implementation confirms [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) now carries accepted first-draft class-method C++ through [UID:0000BU][RectBounds](by-class/RectBounds.md). MCP session `80de0a67` reconfirmed the two modeled starts, four raw retained starts, zero calls across the target range, zero direct raw-start xrefs, zero VA/RVA literal pointer hits for all six starts, exact padding fences, a unique range signature, `ContainsPoint(int y, int x)` stack order, and `void UnionInto` as the conservative return form.
- 2026-05-28 IDA MCP/raw disassembly resolves the gap before free geometry helpers as [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBounds quarter-scale helpers; 2026-06-06 IDA MCP corrected the end to `0x004b7c21` so both `retn 4` operands remain inside the helper bodies. No direct code or pointer xrefs were found.
- 2026-05-28 IDA MCP/raw disassembly resolves raw rect-anchor transform helpers at [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) and [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md). They use 3x3 anchor index remapping and direct calls from the transform cluster to the axis-adjust helper.
- 2026-06-13 IDA MCP rechecked the anchor-transform family: `0x004b7f90`, `0x004b8010`, and `0x004b80d0` are still raw unmodeled starts; the corrected transform/table range is `0x004b7f90-0x004b8194`; direct xrefs to the three raw starts are absent; and the modeled axis helper at `0x004b8290` has exactly four code xrefs, all from those raw transform bodies. This strengthens the RectBounds source-family assignment while keeping final helper spellings below final-code confidence.
- 2026-06-26 B003 implementation confirms [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) and [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) now carry accepted formal first-draft `RectBounds.cpp` static helper bodies. MCP session `80de0a67` was live and healthy; the accepted report preserves no direct xrefs to raw starts, exactly four internal calls to `0x004b8290`, exact padding/table bytes, the false `0x004b8010` RVA hit as a rel32 call operand, and the source-facing names `Transpose3x3AnchorIndex`, `AdjustRectPairForAnchor`, `AdjustRectPairForAnchorWithOffsets`, and `AdjustRectAnchorAxis` as inferred/descriptive.
- 2026-06-19 B001 PE/Capstone support evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`, confirms the class/free/anchor split used by this source file. Representative branch counts: `SetLTRB` and `Offset` each have 207 direct branch/call targets, `InitRectBounds` has 1731, `OffsetRect` has 368, and `PointInRect` has 270. Raw retained starts `0x004b7af0`, `0x004b7b90`, `0x004b7f90`, `0x004b8010`, and `0x004b80d0` have no direct branch/call route. [UID:00040U][0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant](by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md) is `0.25f` and `0x006104b0` is `0.5f`, correcting [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) to `InsetByQuarter` / `OutsetByHalf`.
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) is a caller of the member-style `RectBounds::Offset` at `0x004b78f0`, not the free `OffsetRect` helper at `0x004b7e10`. `EarthquakeEffecter::ApplyEffect` copies the source rectangle to a temporary, offsets that temporary by the chosen X/Y shake values, then passes it to `GrafPort::BlitSurface`.
- IDA MCP also confirms the previously omitted class-shaped helper at `0x004b7910` size `0x4e`; the body insets/shrinks the rectangle and clamps inverted axes to their midpoint.
- 2026-06-19 B008 raw PE/Capstone source-quality recheck resolves the omitted class-shaped helper at `0x004b7910-0x004b795e` as [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md). It has `thiscall` receiver shape, `ret 8`, no callees, only three direct rel32 callers inside `LivingObjectPane::OnDraw`, strict inverted-axis midpoint collapse with signed truncation-toward-zero, and no meaningful return value. The body now belongs to the class child rather than remaining an output omission.
- The same B008 recheck found a function-shaped raw successor at `0x004b7960-0x004b79f7`, followed by `0xcc` padding to `0x004b7a00`. B001's 2026-06-26 accepted report resolves it through [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md) as retained source-authored `bool RectBounds::IntersectWith(const RectBounds *bounds)`: no modeled IDA function, no direct xrefs or VA/RVA/raw-offset pointer route, but normal `thiscall` shape, four-field in-place intersection, failure clearing, and `bool` return. It remains outside [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) and is not folded into the inset child.
- IDA caller output shows broad fan-in: `SetLTRB` is truncated after 10 entries with 184 more callers, `Offset` with 157 more, `InitRectBounds` with 1560 more, and `PointInRect` with 227 more.
- 2026-05-26 IDA MCP recheck confirms the same helper family and still reports `0x004b7f90` as not a function, keeping the geometry helper island bounded at `0x004b7f87`.
- IDA-backed memory docs keep both `0x004b7910` and [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) visible as separate exact helper pages. The accepted class pass resolves `0x004b7910` as `RectBounds::Inset(int dx, int dy)` and `RectArea` as file-level `int RectArea(const RectBounds *bounds)`.
- 2026-07-06 B015 UID00015S implementation confirms [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) now carries formal file-level C++ for all non-`RectArea` free helpers through this `RectBounds.cpp` source route. Live MCP session `supervisor_recovery_20260705` confirmed all twelve helper starts, zero callees for each, `0x004b7f90` not a function, a unique range signature, broad xrefs including 1731 `InitRectBounds` refs and 270 `PointInRect` refs, `Point { y, x }` storage at `0x004b7c30`, `InsetRect` behavior at `0x004b7e30`, and `RectContainsRect(innerBounds, outerBounds)` order. [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) remains the separate `RectArea` emitter.
- `UnionWith` caller evidence includes transfer-server/layout accumulation paths; `ClampWithin` caller evidence is narrow and currently tied to world-map visible-rectangle clamping.
- 2026-05-25 IDA MCP confirms the related [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) island calls `PointInRect` at `0x004b7e80` and is called only by the compatibility/RGB565 software line callbacks.

## Source-Structure Decision

Use a separate `RectBounds.cpp` source family rather than spreading helpers across every feature that calls them. The call fanout is too broad for UI dialogs, map panes, render image libraries, or resource loaders to own these functions.

The final folder is closed:

- `NexusTK/ui/core/RectBounds.cpp/.h` is the final placement because `by-project-structure/proposed-source-tree.md` places it with the `Pane`, `Layer`, and `Region` core UI geometry family, and IDA/PE caller fanout shows these helpers are base UI/render infrastructure rather than feature-owned code.
- C174: `RectBounds` is NexusTK-authored first-party code; no `third_party_embeds` static-source import is required.
- `util/RectBounds.cpp` and `util/Geometry.cpp` are retained only as dated historical alternatives rejected by the complete owner/emitter/generated-source audit.
- `Region.cpp`, feature-local modules, and render-only ownership are rejected for the RectBounds source family. Region consumes rectangle primitives for dirty-region work; feature/render callsites are consumers, not owners.

For current migration planning, keep it adjacent to [UID:0000N3][Region](by-file/Region.md) and [UID:0000KL][Layer](by-file/Layer.md), but do not merge it into `Region.cpp`.

Keep [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) cross-referenced as a consumer dependency. Its canonical owner/emitter is [UID:0000OC][Surface](by-file/Surface.md) / `NexusTK/render/Surface.cpp`; it does not emit through RectBounds.

## Generated Output Caveats

- Before the 2026-06-19 callbacks, active `auto-generated/NexusTK/ui/core/RectBounds.cpp` had only empty markers for the `RectBounds` class, layout, and method/free-helper children. The class page now emits a declaration-level `struct RectBounds` shell with `[[CHILDREN]]`; exact child bodies should appear only when their by-memory pages carry accepted C++.
- [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) now carries first-draft body C++ for the early empty/size/point/contain/intersect/union methods and should emit through the [UID:0000BU][RectBounds](by-class/RectBounds.md) class route after validator/autogen refresh. Any generated output that still shows [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) as an empty emitter marker or old `80/86` row is stale validator-owned output, not source documentation to edit by hand.
- Active `class_RectBounds.cpp` repeats `RectBoundsLayout` and `GetRectBoundsLayout` inside every emitted method. Treat that as generated normalization noise; source reconstruction should use one shared declaration.
- Active recovered output splits the free geometry helpers into one-function `recovered/*.cpp` files. Treat those as staging containers, not likely original source files.
- Active output now materializes [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) as the file-level `int RectArea(const RectBounds *bounds)` helper. Earlier output omitted the helper despite IDA-confirmed EPFTileContext and FontImageLib callers.
- After the 2026-07-06 B015 callback, [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) has formal file-level C++ for `Point`, `InitPointPair`, `InitRectBounds`, `InitRectBoundsFromSize`, `IntersectRects`, `UnionRects`, `OffsetRect`, `InsetRect`, `PointInRect`, `IsRectEmptyOrInvalid`, `RectsEquivalent`, and `RectContainsRect`. `RectArea` intentionally continues to emit from [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md). Any generated output that still shows UID00015S as an empty marker is stale validator-owned output, not source documentation to edit by hand.
- After the 2026-06-26 B003 callback, [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) and [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) have first-draft file-local/static helper C++ applied and should emit through this `RectBounds.cpp` route after validator/autogen refresh. Stale generated tracker rows that still mention the old `0x004b7f90-0x004b8198` filename or old `76/82`-style metadata are validator-owned output, not source docs to edit by hand.

## Cross-References

- [UID:0000BU][RectBounds](by-class/RectBounds.md)
- [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) RectBoundsPredicateAndCombinationMethods
- [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md)
- [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBoundsQuarterScaleHelpers
- [UID:00040U][0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant](by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md) RectBoundsQuarterScaleConstant
- [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) RectAnchorTransformHelpers
- [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) RectAnchorAxisAdjustHelper
- [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)
- [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md)
- [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md)
- [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md)
- [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md)
- [UID:0000N3][Region](by-file/Region.md)
- [UID:0000KL][Layer](by-file/Layer.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md)
- [UID:0001QV][client_ui_core](by-meta/client_ui_core.md)
- C036 excluded-neighbor closure: `[0x004b81a0,0x004b8284)` is neighboring/unowned source comprising [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md), [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md), and [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md); `0x004b83d0` onward is neighboring/unowned [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md) source. These excluded ranges are not RectBounds coverage.

## 2026-08-18 UID0000N2 Whole-File Source Closure

This closure replaces sampled/current-facing status with a complete inferred translation-unit contract. `RectBounds.cpp/.h` contains exactly thirty authored functions, `Point` and `RectBounds`, no independently authored global, and no vtable, RTTI, resource, string, import, singleton, constructor, destructor, thunk, EH helper, or static object. Raw retained bodies remain authored source; jump/index tables, pooled floats, and alignment remain compiler material.

### Complete Authored Function Inventory

| Order | Exact binary range | Source definition | Owner page | Source disposition |
| --- | --- | --- | --- | --- |
| 1 | `[0x004b7670,0x004b7685)` | `bool RectBounds::IsEmptyOrInvalid() const` | UID00022G | Complete member CPP/H. |
| 2 | `[0x004b7690,0x004b76c8)` | `bool RectBounds::HasSameSizeAs(const RectBounds *) const` | UID00022G | Retained raw member; complete CPP/H. |
| 3 | `[0x004b76d0,0x004b76f8)` | `bool RectBounds::ContainsPoint(int y, int x) const` | UID00022G | Complete member CPP/H; y/x order is binary-backed. |
| 4 | `[0x004b7700,0x004b7775)` | `bool RectBounds::ContainsRect(const RectBounds *) const` | UID00022G | Retained raw member; complete CPP/H. |
| 5 | `[0x004b7780,0x004b782a)` | `bool RectBounds::IntersectInto(const RectBounds *, RectBounds *) const` | UID00022G | Retained raw member; complete nullable-output CPP/H. |
| 6 | `[0x004b7830,0x004b78c7)` | `void RectBounds::UnionInto(const RectBounds *, RectBounds *) const` | UID00022G | Retained raw member; exact 151-byte body, SHA256 `E170AA08C5E883AE4A35C810EEA7AB2EDC55AFF3C2315C3C7AB0BE9D3C3F9BD3`; complete CPP/H unchanged. |
| 7 | `[0x004b78d0,0x004b78ee)` | `void RectBounds::SetLTRB(int, int, int, int)` | UID00015Q | Complete member CPP/H. |
| 8 | `[0x004b78f0,0x004b7908)` | `void RectBounds::Offset(int dx, int dy)` | UID00015Q | Complete member CPP/H. |
| 9 | `[0x004b7910,0x004b795e)` | `void RectBounds::Inset(int dx, int dy)` | UID00015R | Complete nested member CPP/H with signed midpoint collapse. |
| 10 | `[0x004b7960,0x004b79f7)` | `bool RectBounds::IntersectWith(const RectBounds *)` | UID00015Q | Retained raw member; complete CPP/H. |
| 11 | `[0x004b7a00,0x004b7a77)` | `RectBounds *RectBounds::UnionWith(const RectBounds *)` | UID00015Q | Complete member CPP/H. |
| 12 | `[0x004b7a80,0x004b7ae8)` | `void RectBounds::ClampWithin(int, int, int, int)` | UID00015Q | Complete member CPP/H. |
| 13 | `[0x004b7af0,0x004b7b88)` | `RectBounds *RectBounds::InsetByQuarter(RectBounds *) const` | UID00022H | Retained raw member; complete CPP/H with inline `0.25f`/`0.5f`. |
| 14 | `[0x004b7b90,0x004b7c21)` | `RectBounds *RectBounds::OutsetByHalf(RectBounds *) const` | UID00022H | Retained raw member; complete CPP/H with shared `0.5f`. |
| 15 | `[0x004b7c30,0x004b7c43)` | `void InitPointPair(Point *, int y, int x)` | UID00015S | Complete free CPP/H. |
| 16 | `[0x004b7c50,0x004b7c6f)` | `void InitRectBounds(RectBounds *, int, int, int, int)` | UID00015S | Complete free CPP/H. |
| 17 | `[0x004b7c70,0x004b7c95)` | `void InitRectBoundsFromSize(RectBounds *, int, int, int, int)` | UID00015S | Complete free CPP/H. |
| 18 | `[0x004b7ca0,0x004b7cb6)` | `int RectArea(const RectBounds *)` | UID00015T | Complete nested free CPP/H; signed width-times-height. |
| 19 | `[0x004b7cc0,0x004b7d69)` | `bool IntersectRects(const RectBounds *, const RectBounds *, RectBounds *)` | UID00015S | Complete free CPP/H. |
| 20 | `[0x004b7d70,0x004b7e03)` | `void UnionRects(const RectBounds *, const RectBounds *, RectBounds *)` | UID00015S | Complete free CPP/H. |
| 21 | `[0x004b7e10,0x004b7e29)` | `void OffsetRect(RectBounds *, int, int)` | UID00015S | Complete free CPP/H. |
| 22 | `[0x004b7e30,0x004b7e7f)` | `void InsetRect(RectBounds *, int, int)` | UID00015S | Complete free CPP/H; historical `InflateRect_*` rejected. |
| 23 | `[0x004b7e80,0x004b7ea7)` | `bool PointInRect(int y, int x, const RectBounds *)` | UID00015S | Complete half-open free CPP/H. |
| 24 | `[0x004b7eb0,0x004b7ecd)` | `bool IsRectEmptyOrInvalid(const RectBounds *)` | UID00015S | Complete free CPP/H. |
| 25 | `[0x004b7ed0,0x004b7f22)` | `bool RectsEquivalent(const RectBounds *, const RectBounds *)` | UID00015S | Complete free CPP/H. |
| 26 | `[0x004b7f30,0x004b7f87)` | `bool RectContainsRect(const RectBounds *inner, const RectBounds *outer)` | UID00015S | Complete free CPP/H; inner/outer order is binary-backed. |
| 27 | code `[0x004b7f90,0x004b7fe0)` | `static int Transpose3x3AnchorIndex(int)` | UID00022I | Retained raw private CPP; following table compiler-covered. |
| 28 | code `[0x004b8010,0x004b80ac)` | `static void AdjustRectPairForAnchor(...)` | UID00022I | Retained raw private CPP; following table compiler-covered. |
| 29 | code `[0x004b80d0,0x004b8170)` | `static void AdjustRectPairForAnchorWithOffsets(...)` | UID00022I | Retained raw private CPP; following table compiler-covered. |
| 30 | code `[0x004b8290,0x004b83ae)` | `static void AdjustRectAnchorAxis(...)` | UID00022L | Complete private CPP; following NOP/table compiler-covered. |

The three anchor tables `[0x004b7fe0,0x004b8004)`, `[0x004b80ac,0x004b80d0)`, and `[0x004b8170,0x004b8194)`, plus mapping table `[0x004b83b0,0x004b83c5)`, are compiler lowering for the emitted switches. UID00040U `[0x0061a880,0x0061a884)` is compiler-pooled `0.25f`; shared `0x006104b0` is project-wide `0.5f`. No formal source body is assigned to any table or pooled datum.

### Exact Source And Emitter Order

- File root UID0000N2 emits `#include "RectBounds.h"`, then its children.
- Class/header owner UID0000BU is direct position `10`. Its CPP children are UID00022G position `10`, UID00015Q position `20`, UID00022H position `30`, and UID00015S position `40`.
- UID00015R is nested beneath UID00015Q at position `10`, inserted after `Offset` and before `IntersectWith` in CPP/H.
- UID00015T is nested beneath UID00015S at position `10`, inserted after `InitRectBoundsFromSize` and before `IntersectRects` in CPP/H. Its accepted formal CPP/H is preserved, not recreated.
- File-local UID00022I is direct file position `20`; UID00022L is direct file position `30`. UID00022I's forward declaration makes the later axis-helper body dependency-valid.
- UID00040U and UID0001VP are non-emitting evidence pages. LineClip remains UID0000OC/Surface-owned.
- UID0000BU owns the one guarded header: `Point`, `RectBounds`, fourteen member declarations, free-helper child declarations including nested `RectArea`, then one final `#endif`. Private anchor helpers remain CPP-only.

### Complete Alignment Inventory

Every span below has exact inbound-xref set `{}` and is compiler alignment, never authored C++. Thirty-three spans are pure `cc`; C162 is exact `66 90` and remains inside UID00022L rather than `by-memory/-ignored.md`.

| Claim | Half-open range | Exact bytes/length | Boundary role |
| --- | --- | --- | --- |
| C130 | `0x004b7661-0x004b7670` | 15 `cc` | FramePartPane -> UID00022G |
| C131 | `0x004b7685-0x004b7690` | 11 `cc` | member alignment |
| C132 | `0x004b76c8-0x004b76d0` | 8 `cc` | member alignment |
| C133 | `0x004b76f8-0x004b7700` | 8 `cc` | member alignment |
| C134 | `0x004b7775-0x004b7780` | 11 `cc` | member alignment |
| C135 | `0x004b782a-0x004b7830` | 6 `cc` | member alignment |
| C136 | `0x004b78c7-0x004b78d0` | 9 `cc`; one independent data item; zero inbound xrefs at `0x004b78c7` | UID00022G -> UID00015Q; compiler alignment only, no authored CPP/H |
| C137 | `0x004b78ee-0x004b78f0` | 2 `cc` | member alignment |
| C138 | `0x004b7908-0x004b7910` | 8 `cc` | parent -> nested UID00015R |
| C139 | `0x004b795e-0x004b7960` | 2 `cc` | nested UID00015R -> parent |
| C140 | `0x004b79f7-0x004b7a00` | 9 `cc` | member alignment |
| C141 | `0x004b7a77-0x004b7a80` | 9 `cc` | member alignment |
| C142 | `0x004b7ae8-0x004b7af0` | 8 `cc` | UID00015Q -> UID00022H |
| C143 | `0x004b7b88-0x004b7b90` | 8 `cc` | quarter helper alignment |
| C144 | `0x004b7c21-0x004b7c30` | 15 `cc` | UID00022H -> UID00015S |
| C145 | `0x004b7c43-0x004b7c50` | 13 `cc` | free-helper alignment |
| C146 | `0x004b7c6f-0x004b7c70` | 1 `cc` | free-helper alignment |
| C147 | `0x004b7c95-0x004b7ca0` | 11 `cc` | parent -> nested UID00015T |
| C148 | `0x004b7cb6-0x004b7cc0` | 10 `cc` | nested UID00015T -> parent |
| C149 | `0x004b7d69-0x004b7d70` | 7 `cc` | free-helper alignment |
| C150 | `0x004b7e03-0x004b7e10` | 13 `cc` | free-helper alignment |
| C151 | `0x004b7e29-0x004b7e30` | 7 `cc` | free-helper alignment |
| C152 | `0x004b7e7f-0x004b7e80` | 1 `cc` | free-helper alignment |
| C153 | `0x004b7ea7-0x004b7eb0` | 9 `cc` | free-helper alignment |
| C154 | `0x004b7ecd-0x004b7ed0` | 3 `cc` | free-helper alignment |
| C155 | `0x004b7f22-0x004b7f30` | 14 `cc` | free-helper alignment |
| C156 | `0x004b7f87-0x004b7f90` | 9 `cc` | UID00015S -> UID00022I |
| C157 | `0x004b8004-0x004b8010` | 12 `cc` | anchor table -> raw helper |
| C158 | `0x004b8194-0x004b81a0` | 12 `cc` | UID00022I -> UID00022J |
| C159 | `0x004b81eb-0x004b81f0` | 5 `cc` | UID00022J -> UID00022K |
| C160 | `0x004b821e-0x004b8220` | 2 `cc` | UID00022K -> UID00015U |
| C161 | `0x004b8284-0x004b8290` | 12 `cc` | UID00015U -> UID00022L |
| C162 | `0x004b83ae-0x004b83b0` | `66 90` | in-page code/table NOP alignment |
| C163 | `0x004b83c5-0x004b83d0` | 11 `cc` | UID00022L -> unrelated successor |

### Historical Generated Defects And Corrections

- Pre-callback generated `RectBounds.cpp` was structurally malformed: UID00015R `Inset` and UID00015T `RectArea` were late file-root siblings rather than nested at their physical/source positions; UID0001VP produced an empty emitter marker; the free/member/static groups were not deterministic.
- Validator command `000000025640` was a dated defective snapshot whose `RectBounds.h` omitted `RectArea`. Command `000000025804` was a later dated snapshot that restored the declaration but did not itself close all emitter-order defects. These identities remain historical evidence, not permanent current authority.
- The accepted callback repairs ownership in ordinary formal channels. Generated `.cpp/.h` remain validator-owned and must be judged by the latest waited-refresh command metadata plus physical source-order/header readback, never by manually editing generated artifacts.
- Historical address-suffixed names, `RectBoundsLayout` as an independent source type, a named quarter-scale global, `util` placement, RectBounds-owned LineClip, compiler tables as source arrays, and padding merged into function bodies are rejected and preserved only as research history.

## Changes

- 2026-08-18 UID0000N2 whole-file implementation callback:
  - Raised target metadata from `90/85` to `95/93` and finalized `NexusTK/ui/core/RectBounds.cpp/.h`.
  - Incorporated the exact thirty-function inventory, type/layout authority, complete emitter/source order, non-emitting literal/layout pages, compiler table disposition, all 34 alignment spans, excluded neighbors, Surface-owned LineClip decision, and generated-defect history above.
  - Kept every source body/declaration in its exact by-memory/by-class formal channel; this by-file page remains the ownership/composition root and does not duplicate formal code.

## UID000090 Shared Point Header Ownership - 2026-07-31

- `NexusTK/ui/core/RectBounds.h` is the single declaration owner for both `Point` and `RectBounds`. `Point` is the exact eight-byte value type `struct Point { int y; int x; };`; the y-then-x field order matches [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md), Pane's `m_origin` stores, and the EventHandler offset-output contract.
- [UID:0000BU][RectBounds](by-class/RectBounds.md) already emits the shared `Point` declaration immediately before `RectBounds`. [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) consumes that header declaration in its free-helper bodies and does not define a second local `Point`; historical `PointPair` wording remains search provenance only.
- `RectBounds.cpp` remains the implementation owner for the RectBounds member bodies and file-local geometry helper bodies. Header ownership of the two value declarations does not move helper bodies into the class page or duplicate any by-memory emitter.
- A separate `Point.h`, a CPP-local `Point`, a PCH-only declaration, and a duplicated `Point` declaration in UID00015S are rejected because each would create inconsistent or duplicate source declarations across Pane, EventHandler, and geometry consumers.

- 2026-07-06 B015 RectGeometryHelpers implementation support:
  - Score unchanged.
  - Summary/evidence: recorded that [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) now emits formal file-level helper C++ through this `RectBounds.cpp` route while [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) remains the separate `RectArea` emitter. The support rows now use `Point` y/x storage for `InitPointPair`, primary `InsetRect` for `0x004b7e30`, canonical `PointInRect(int y, int x, const RectBounds *bounds)`, and `RectContainsRect(innerBounds, outerBounds)`. `InflateRect_4B7E30` is historical/search alias text only; downstream caller pages with stale point-call order remain out of scope for this support sync.

- 2026-06-27 B010 RectBoundsPredicateAndCombinationMethods implementation support:
  - Score unchanged.
  - Summary/evidence: updated generated-output/source-quality wording now that [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) carries formal first-draft class-method bodies through [UID:0000BU][RectBounds](by-class/RectBounds.md). Preserved the raw/no-xref confidence cap, `ContainsPoint(int y, int x)` order, `void UnionInto` decision, and `NexusTK/ui/core/RectBounds.cpp` route.
- 2026-06-26 B001 RectBoundsMethods implementation support:
  - Score unchanged.
  - Summary/evidence: added `0x004b7960-0x004b79f7` / `RectBounds::IntersectWith` to the [UID:0000BU][RectBounds](by-class/RectBounds.md) proposed contents and replaced stale parent-follow-up wording with the current resolved state from [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md). MCP session `80de0a67` and PE negative evidence preserve the no-xref/no-pointer caveat while supporting class-owned source C++.
- 2026-06-19 B007 EarthquakeEffecter support sync:
  - Score unchanged.
  - Summary/evidence: added Earthquake as a `RectBounds::Offset` caller and preserved the distinction from the free `OffsetRect` helper.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `90`, confidence `82`.
- Summary/evidence: the page documents geometry primitive role, contents, IDA fanout/evidence, raw helper islands, source-structure decision, generated-output caveats, type refs, and cross-references; confidence remains capped by final `ui/core` versus `util` placement and line-clip ownership uncertainty.
- 2026-06-13 A002 Goal2 support refresh:
  - Before: `CONFIDENCE:82`, and the anchor helper row still used stale end `0x004b8198`.
  - Changed to: `CONFIDENCE:85`, corrected anchor helper references to `0x004b7f90-0x004b8194`, and added current IDA evidence for the raw starts, four axis-helper xrefs, and RectBounds-family ownership.
  - Summary/evidence: the parent clears the strict support gate for this child because the refreshed anchor evidence is RectBounds-layout specific, all axis-helper xrefs stay inside the transform cluster, and the unrelated intervening hash/file/path helpers are documented separately. Confidence remains below 95 because the final `ui/core` versus utility folder and some helper spellings are not final-audit proven.
- 2026-06-01: Changed proposed reconstruction path from blank to `NexusTK/ui/core/`.
  - Before: the by-file page kept the path blank even though the proposed source tree already listed `ui/core/RectBounds.cpp`.
  - After: validator metadata now stages the page under `NexusTK/ui/core/`.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `RectBounds.cpp` in `ui/core`, and IDA MCP caller fanout for `SetLTRB`, `Offset`, `InitRectBounds`, and `PointInRect` supports base UI/render infrastructure ownership rather than a feature module.
- 2026-06-19 B001 accepted RectBounds class source-quality implementation:
  - Before: the by-file page still said the class/file-local split was under review, described [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) as quarter-inset/quarter-outset helpers, kept address-suffixed helper names such as `InitRect_4B7C70` and `UnionRect_4B7D70`, and treated `RectArea` declaration ownership as open.
  - Changed to: explicit class shell versus file-local helper split, [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) corrected to `InsetByQuarter` / `OutsetByHalf`, `InitRectBoundsFromSize`, `UnionRects`, `PointInRect`, and `RectArea(const RectBounds *bounds)` file-level wording.
  - Evidence: accepted B001 report plus PE/Capstone branch counts, exact constants `0.25f`/`0.5f`, cdecl `RectArea` stack-pointer/no-`ecx` shape, and broad UI/core helper fanout. `NexusTK/ui/core/RectBounds.cpp` remains selected; `Region`, feature-local, and render-only alternatives are rejected, with `util/Geometry.cpp` retained only as a lower-probability historical fallback.
- 2026-06-19 B008 RectBoundsInset body implementation support:
  - Score unchanged.
  - Summary/evidence: [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) now carries the accepted first-draft `void RectBounds::Inset(int dx, int dy)` body. The by-file generated-output caveat was updated so `0x004b7910` is no longer treated as a true omission once validators regenerate output. B008 raw evidence also added a parent-cluster follow-up for the function-shaped no-xref successor at `0x004b7960-0x004b79f7`; that follow-up is superseded by the 2026-06-26 B001 `IntersectWith` resolution above.
- 2026-06-21 B009 read-only-data source-routing support:
  - Score unchanged.
  - Summary/evidence: added exact one-dword child [UID:00040U][0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant](by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md) for the `0.25f` literal used by [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md), with rejected frame/panel/GrafPort ownership and no-code literal-regeneration policy.
- 2026-06-26 B003 RectAnchor helper body implementation support:
  - Score unchanged.
  - Summary/evidence: recorded that [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) and [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) now have accepted first-draft file-local/static C++ applied through this `RectBounds.cpp` source route. The stale generated tracker/coverage rows are left to validator refresh; no generated or coverage files were edited by hand.
