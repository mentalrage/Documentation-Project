*** UID:0000BU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "RectBounds.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CORE_RECTBOUNDS_H
#define NEXUSTK_UI_CORE_RECTBOUNDS_H

struct Point
{
    int y;
    int x;
};

struct RectBounds
{
    int left;
    int top;
    int right;
    int bottom;

    bool IsEmptyOrInvalid() const;
    bool HasSameSizeAs(const RectBounds *bounds) const;
    bool ContainsPoint(int y, int x) const;
    bool ContainsRect(const RectBounds *bounds) const;
    bool IntersectInto(const RectBounds *bounds, RectBounds *outBounds) const;
    void UnionInto(const RectBounds *bounds, RectBounds *outBounds) const;
    void SetLTRB(int leftValue, int topValue, int rightValue, int bottomValue);
    void Offset(int dx, int dy);
    void Inset(int dx, int dy);
    bool IntersectWith(const RectBounds *bounds);
    RectBounds *UnionWith(const RectBounds *bounds);
    void ClampWithin(int leftLimit, int topLimit,
                     int rightLimit, int bottomLimit);
    RectBounds *InsetByQuarter(RectBounds *outBounds) const;
    RectBounds *OutsetByHalf(RectBounds *outBounds) const;
};

[[CHILDREN]]

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RectBounds

## Status

- Confidence: strong for the POD layout, helper behavior, byte boundaries, and class shell; medium-high for exact historical helper spellings and final `ui/core` versus lower-probability utility folder spelling.
- Likely source file: [UID:0000N2][RectBounds](by-file/RectBounds.md), emitted as `NexusTK/ui/core/RectBounds.cpp`.
- Address ranges: [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) RectBounds predicate/combination methods, [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md) including raw retained `0x004b7960-0x004b79f7` `IntersectWith`, [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md), and [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md).
- Current source-owner state: the class page owns the declaration-level `struct RectBounds` shell and member prototypes; exact method bodies remain on their by-memory pages, while cdecl/free helpers beginning at `0x004b7c30` remain file-level `RectBounds.cpp` helpers.
- Final C++ status: declaration-level first draft is ready and populated here. [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md), [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md), [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md), and [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) now carry their exact method bodies through the class route; do not move exact method bodies into this class page.
- Imported source file: `RectBounds.cpp`.
- Current header closure: `Point` and `RectBounds` are each defined once under `NEXUSTK_UI_CORE_RECTBOUNDS_H`. Exact method bodies remain CPP children. The H channel now intentionally places `[[CHILDREN]]` immediately before `#endif` so UID00015S's accepted free-helper declarations emit once inside the same guard.
- Historical C134 assumption: the 2026-07 compile pass omitted the H child marker after an empty attachment produced invalid `[[No Children Attached]]` text. That failure proved an empty child route was wrong at that time; it did not prove declarations must remain absent. UID00015S now supplies a non-empty, exact H payload, so guarded child placement supersedes the old no-marker conclusion without changing either type layout.

## Class Purpose

`RectBounds` is a 16-byte POD-like rectangle value object with exactly four integer edge fields: `left`, `top`, `right`, and `bottom`. Member helpers test emptiness, compare size, test point/rectangle containment, intersect/union into outputs, set exact edges, translate in place, inset/shrink in place, intersect in place, scale inward/outward into outputs, accumulate a union, and clamp a fixed-size rectangle into containing edge limits.

The class has no confirmed vtable, no RTTI, no constructor body, no hidden flags, no ownership pointer, and no width/height stored fields. It is memory-compatible with a four-int Windows `RECT` shape, but source-facing reconstruction should keep the custom `RectBounds` type because the by-file source owner, class method island, layout page, and adjacent free helper island all use the project-specific rectangle helper route. Adding synthetic constructors or vtable machinery would overstate the binary evidence.

## Method Notes

| Source-facing signature | Address | Role |
| --- | --- | --- |
| `bool IsEmptyOrInvalid() const` | `0x004b7670-0x004b7685` | Returns true when `bottom <= top || right <= left`. |
| `bool HasSameSizeAs(const RectBounds *bounds) const` | `0x004b7690-0x004b76c8` | Raw/no-direct-xref method-shaped body; compares only width and height against another rectangle. |
| `bool ContainsPoint(int y, int x) const` | `0x004b76d0-0x004b76f8` | Half-open point hit-test. Argument order is `y, x`: the binary reads `[ebp+0x08]` as `y` and `[ebp+0x0c]` as `x`; x/y order is rejected for source-facing docs because it would invert current UI call reconstruction. |
| `bool ContainsRect(const RectBounds *bounds) const` | `0x004b7700-0x004b7775` | Raw/no-direct-xref method-shaped body; treats an empty input rectangle as contained, otherwise requires a non-empty receiver and full edge containment. |
| `bool IntersectInto(const RectBounds *bounds, RectBounds *outBounds) const` | `0x004b7780-0x004b782a` | Raw/no-direct-xref method-shaped body; writes max-left/max-top/min-right/min-bottom into optional output and clears output to zero on failure. |
| `void UnionInto(const RectBounds *bounds, RectBounds *outBounds) const` | `0x004b7830-0x004b78c7` | Exact 151-byte raw/no-direct-xref method-shaped body, SHA256 `E170AA08C5E883AE4A35C810EEA7AB2EDC55AFF3C2315C3C7AB0BE9D3C3F9BD3`; final `retn 8` ends at `0x004b78c7`. It writes a union output for all paths. EAX often contains `outBounds`, but no caller/source proof establishes a source-significant return, so the class shell uses `void`. |
| `void SetLTRB(int leftValue, int topValue, int rightValue, int bottomValue)` | `0x004b78d0-0x004b78ee` | Assigns `left`, `top`, `right`, and `bottom` directly. |
| `void Offset(int dx, int dy)` | `0x004b78f0-0x004b7908` | Adds `dx` to left/right and `dy` to top/bottom. |
| `void Inset(int dx, int dy)` | [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) | Insets/shrinks the rectangle by x/y deltas in place, collapses only strict inverted axes to their signed midpoint, preserves zero width/height, expands for negative deltas, and is not chainable. |
| `bool IntersectWith(const RectBounds *bounds)` | `0x004b7960-0x004b79f7` | Retained no-direct-xref raw member body; intersects the receiver in place with another rectangle, clears all four edges to zero and returns `false` on empty receiver/input or empty result, and returns `true` on a non-empty intersection. |
| `RectBounds *UnionWith(const RectBounds *bounds)` | `0x004b7a00-0x004b7a77` | Expands this rectangle to include another rectangle, copying the incoming rectangle if this one is empty; binary paths explicitly preserve `this` as the likely return. |
| `void ClampWithin(int leftLimit, int topLimit, int rightLimit, int bottomLimit)` | `0x004b7a80-0x004b7ae8` | Translates this rectangle enough to keep it inside four supplied containing edges while preserving size; this is not a `RectBounds *` parameter. |
| `RectBounds *InsetByQuarter(RectBounds *outBounds) const` | `0x004b7af0-0x004b7b88` | Raw/no-direct-xref member-style helper; insets by one quarter on each side, yielding a half-size centered rectangle, and returns the output pointer. |
| `RectBounds *OutsetByHalf(RectBounds *outBounds) const` | `0x004b7b90-0x004b7c21` | Raw/no-direct-xref member-style helper; corrects stale `OutsetByQuarter` wording. The second helper uses `0.5f`, outsets by one half on each side, yields a double-size rectangle, and returns the output pointer. |

## Class Versus File-Local Helpers

The member-shaped `RectBounds` helpers occupy `0x004b7670-0x004b7c21`. Their accepted source-facing route is a POD `RectBounds` class/struct declaration with method prototypes here and exact bodies on by-memory children. The member-shaped evidence is strongest where `ecx` is the source object and stack arguments are ordinary method parameters or output pointers.

The file-local/free helper island begins at `0x004b7c30` and should remain under [UID:0000N2][RectBounds](by-file/RectBounds.md), not as class methods unless later caller/source proof appears. Current source-facing file-level helpers include `InitPointPair(Point *point, int y, int x)`, `InitRectBounds`, `InitRectBoundsFromSize`, `RectArea`, `IntersectRects`, `UnionRects`, `OffsetRect`, `InsetRect`, `PointInRect(int y, int x, const RectBounds *bounds)`, `IsRectEmptyOrInvalid`, `RectsEquivalent`, and `RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)`. [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) is specifically cdecl/free-helper-shaped: it receives a stack `RectBounds *`, uses no `ecx` receiver, and ends with a plain `ret`. [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) now emits the rest of the free-helper island through the file route.

The anchor helpers [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) and [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) are file-local/static `RectBounds.cpp` geometry helpers, not class methods. They operate on rectangle pairs, anchor indices, edge-slot pointers, and optional offsets rather than one `RectBounds` receiver. The 2026-06-26 B003 callback adds accepted body-level C++ for those pages, but it stays in the file-level/static helper route and does not add member prototypes or bodies to this class shell.

## Layout Notes

See [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md). The layout is:

| Offset | Field |
| --- | --- |
| `+0x00` | `left` |
| `+0x04` | `top` |
| `+0x08` | `right` |
| `+0x0c` | `bottom` |

Empty/invalid tests use `right <= left || bottom <= top`. The class declaration should not include `width`, `height`, hidden state, base classes, or constructor-only fields. Width and height are computed as `right - left` and `bottom - top`.

## Heuristic / Inference Reanalysis And Validation

- `struct RectBounds` versus class/vtable/constructor alternatives: the accepted source form is a POD `struct` with public fields and prototypes. Evidence is the 16-byte four-int layout, no vtable/RTTI/constructor/destructor evidence, broad value-object helper use, and free initializer functions. A C++ `class` with private fields is possible stylistically, but the binary does not prove accessors or invariants; constructor/vtable alternatives are rejected.
- Four-field names: use `left`, `top`, `right`, `bottom`. `width`/`height` fields are rejected because every width/height calculation subtracts edges, and setter/free-helper bodies write right/bottom as absolute edges or `left + width` / `top + height` only in the from-size helper.
- `ContainsPoint(int y, int x) const`: source-facing order stays `y, x` because the modeled member at `0x004b76d0` and free `PointInRect` family use the same stack-order pattern. Rewriting to `x, y` would erase evidence and conflict with other UI mouseY/mouseX conventions in the docs.
- Member versus file-local split: `0x004b7670-0x004b7c21` is member-shaped, with `ecx` receiver use in the class method family. Cdecl helpers beginning at `0x004b7c30` are file-level geometry support. `RectArea` belongs to the file-level route under [UID:0000N2][RectBounds](by-file/RectBounds.md), not to [UID:0000BU], because it uses a stack pointer and no `ecx`.
- UID00015S free-helper source shape: B015 keeps the cdecl helper island off the class declaration. `InitPointPair` uses formal `Point { y, x }` storage, not a `RectBounds` receiver; `InsetRect` at `0x004b7e30` is a free helper with the same shrink/expand and midpoint-clamp behavior as the member inset family but no `ecx` receiver; `PointInRect` stays `y, x, bounds`; and `RectContainsRect` stays `innerBounds, outerBounds`. Historical `InflateRect_4B7E30` wording is stale alias/search text only.
- [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) route: despite no direct xrefs, the two scale helpers are retained source-authored class methods. They use a `thiscall`-shaped source rectangle in `ecx`, take a stack output pointer, return that pointer in `eax`, sit between class methods and free helpers, and match the accepted [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) member-style inset route.
- [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) route: B008 raw PE/Capstone reanalysis confirms the source-facing signature as `void RectBounds::Inset(int dx, int dy)`. The body is `thiscall`, ends with `ret 8`, has no callees, mutates the four fields directly, and is called only at `0x0053bcb7`, `0x0053bcd8`, and `0x0053bcf9` inside `LivingObjectPane::OnDraw`, each with `(1, 1)` and a stack `RectBounds`. Return-producing alternatives are rejected because `eax` leaves as arithmetic temporary/midpoint state, never as `this`, and the callers ignore it.
- `IntersectWith` route: B001's 2026-06-26 accepted report resolves raw retained `0x004b7960-0x004b79f7` as `bool RectBounds::IntersectWith(const RectBounds *bounds)`. The name is a strong source-facing inference from the in-place max-left/max-top/min-right/min-bottom behavior and sibling `UnionWith`; `ClipTo` is plausible but weaker, `IntersectInto` is rejected because [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) already uses that output-pointer role, and raw `sub_4B7960`/address labels are not source-facing. No direct xrefs or pointer hits were recovered, so liveness/original-name confidence is capped, but the normal prologue/body/`retn 4` shape and four-field semantics reject padding, thunk, callback-table, and compiler-artifact alternatives.
- `OutsetByHalf` correction: stale `OutsetByQuarter` is rejected. The first helper uses `0x0061a880 == 0.25f`; the second helper loads `0x006104b0 == 0.5f` as the scale and rounding-bias constant, so it outsets by one half on each side.
- Anchor transform route: [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md)/[UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) remain file-local/static `RectBounds.cpp` helpers. They are not class methods because their signatures operate on rectangle pairs, anchor indices, edge-slot pointers, and offsets. The apparent `0x004b8010` whole-file literal/RVA hit reported during PE scanning is a rel32 operand of an unrelated `call 0x005c7790`, not a pointer-table or liveness reference to the anchor helper.
- B003 anchor-helper C++ route: the formal first-draft bodies for `Transpose3x3AnchorIndex`, `AdjustRectPairForAnchor`, `AdjustRectPairForAnchorWithOffsets`, and `AdjustRectAnchorAxis` belong to [UID:0000N2][RectBounds](by-file/RectBounds.md) as static/file-local helpers. The transform helpers use input rectangle pointers, anchor/offset values, and output rectangle pointers; the axis primitive is a `void` edge-slot mutator. These signatures reinforce the class/file-local split rather than expanding the `RectBounds` method inventory.
- `UnionInto` return uncertainty: the raw helper often leaves the output pointer in `eax`, but no direct caller proves the source used a return value. Use `void` in the class shell until caller/source proof appears; this keeps the declaration conservative without losing output-pointer behavior.
- No-xref raw bodies are not no-code/compiler artifacts: [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) and [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) contain source-shaped project geometry over the `RectBoundsLayout`, with prologues/epilogues and padding. They are not thunks, CRT support, switch tables, scalar deleting destructors, or compiler-only glue. No direct xrefs cap liveness confidence but no longer justify blank/no-code classification; both pages now carry formal class-method C++ through [UID:0000BU].
- Source placement: keep `NexusTK/ui/core/RectBounds.cpp` through [UID:0000N2][RectBounds](by-file/RectBounds.md). `Region.cpp` is rejected as too narrow and higher-level dirty-region ownership. Feature-local, render-only, and no-owner alternatives are rejected because caller fanout is broad and the helper island is centralized. `util/Geometry.cpp` remains only a lower-probability historical fallback because current proposed source tree and generated route select `ui/core`.
- First-draft C++ policy: this class page emits only the declaration shell plus `[[CHILDREN]]`. Exact method bodies remain on by-memory pages, and file-local helper bodies remain with the RectBounds source file/free-helper docs. Full bodies on the class page are rejected because it would collapse exact address ownership.

## Evidence Notes

- IDA MCP `lookup_funcs` confirms all four active methods plus omitted `0x004b7910`.
- 2026-05-28 IDA MCP review resolves the prior `0x004b7660-0x004b78d0` UNKNOWN gap into the final `FramePartPane` destructor byte, padding, and [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) RectBounds predicate/combination methods.
- `0x004b7670` decompiles to the empty/invalid predicate and `0x004b76d0` decompiles to the half-open point predicate; raw disassembly confirms the size/contain/intersect/union helpers between them and `SetLTRB`.
- 2026-05-28 raw disassembly resolves the prior `0x004b7ae8-0x004b7c30` UNKNOWN gap as [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBounds quarter-scale helpers plus padding; 2026-06-06 IDA MCP corrected the helper end to include both `retn 4` operands, and the helpers use `0.25f` and `0.5f` constants.
- 2026-05-28 raw disassembly resolves anchor-transform helpers at [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) and [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md); these helpers still need caller-side naming confirmation.
- 2026-06-13 IDA MCP rechecked the raw anchor-transform family and corrected the transform helper end to `0x004b8194`: the local tables end before `0xcc` padding at `0x004b8004-0x004b8010` and `0x004b8194-0x004b81a0`, and the modeled axis primitive has exactly four xrefs from the transform bodies at `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161`.
- 2026-06-26 B003 implementation rechecked MCP availability on active session `80de0a67` and applied formal C++ only to [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) and [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md). The class page remains declaration-only; the helper pair still has no `ecx` receiver, no class-member call shape, no direct external xrefs to the raw transform starts, and exactly four internal calls into the modeled axis primitive.
- IDA MCP caller checks show very broad use for `SetLTRB` and `Offset`, while `ClampWithin` currently has only two direct callers from a world-map-style visible-bounds path.
- IDA-backed free-helper pages reuse the same layout for `InitRectBounds`, `IntersectRects`, `OffsetRect`, `IsRectEmptyOrInvalid`, and `RectContainsRect`.
- IDA-backed docs keep [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) and [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) visible as separate exact helper pages. The accepted split treats `0x004b7910` as the class member `RectBounds::Inset(int dx, int dy)` and `RectArea` as file-level `RectArea(const RectBounds *bounds)`.
- 2026-05-26 IDA MCP reconfirms `Inset` callers at `0x0053bcb7`, `0x0053bcd8`, and `0x0053bcf9`, all inside `sub_53BB20`.
- 2026-06-19 B001 implementation evidence combines existing IDA-backed docs with fresh local PE/Capstone evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`. No IDA MCP endpoint/tool was exposed in the active Codex toolset for this callback; direct fresh observations are PE/Capstone facts, while earlier live-IDA observations remain documentation evidence from existing by-* pages.
- 2026-06-19 B008 raw PE/Capstone recheck of [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) confirms `0x004b7910-0x004b795e` as the exact `RectBounds::Inset` body, `0xcc` padding at `0x004b7908-0x004b7910` and `0x004b795e-0x004b7960`, three direct caller sites in `LivingObjectPane::OnDraw`, no callees, and a void in-place return contract. The same pass found a function-shaped no-xref successor at `0x004b7960-0x004b79f7`, likely another `RectBounds` method, but that successor is outside [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) and should be handled by the parent method cluster rather than merged into the inset body.
- 2026-06-26 B001 RectBoundsMethods implementation resolves the `0x004b7960-0x004b79f7` successor under [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md). MCP session `80de0a67` reports no modeled function and no direct xrefs to `0x004b7960`; raw disassembly shows a frame-based `thiscall` member that reads another `RectBounds *`, returns `al`, clears the receiver on failure, and writes the in-place intersection on success; an independent PE scan found no direct branch/call or VA/RVA/raw-offset pointer route to the raw start. The accepted class shell now includes `bool IntersectWith(const RectBounds *bounds);`.
- 2026-06-27 B010 implementation resolves [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) from declaration-only to class-emitted first-draft method bodies. MCP session `80de0a67` reconfirmed two modeled starts, four raw retained starts, zero calls across the full target range, zero direct raw-start xrefs, zero VA/RVA literal pointer hits for all six starts, exact `0xcc` padding fences, a unique range signature, the deliberate `ContainsPoint(int y, int x)` order, and the conservative `void UnionInto` return contract. The class declaration already contained the six prototypes, so no class-shell signature change was required.
- Fresh PE/Capstone plus exact item/instruction/byte/xref boundary evidence confirms `0x004b7661-0x004b7670` padding before the class predicate island, one independent nine-byte `0x004b78c7-0x004b78d0` `cc` item with zero inbound xrefs before `SetLTRB`, `0x004b7ae8-0x004b7af0` padding before the scale helpers, `0x004b7b88-0x004b7b90` internal scale-helper padding, `0x004b7c21-0x004b7c30` padding before free helpers, `0x004b7f87-0x004b7f90` padding before anchor helpers, `0x004b8194-0x004b81a0` padding before `WideStringHashHelper`, `0x004b8284-0x004b8290` padding before the anchor-axis helper, and `0x004b83c5-0x004b83d0` padding before `GeneralPurposePanel`.
- Fresh PE branch-count evidence supports the split. Live member helpers include `IsEmptyOrInvalid` with 7 direct branch/call targets, `ContainsPoint` with 3, `SetLTRB` and `Offset` with 207 each, `Inset` with 3, `UnionWith` with 33, and `ClampWithin` with 2. Live file-level helpers include `InitPointPair` with 101, `InitRectBounds` with 1731, `InitRectBoundsFromSize` with 38, `RectArea` with 4, `IntersectRects` with 91, `UnionRects` with 37, `OffsetRect` with 368, `InsetRect` with 32, `PointInRect` with 270, `IsRectEmptyOrInvalid` with 32, `RectsEquivalent` with 7, and `RectContainsRect` with 2. Raw retained member/file-local starts with no direct branch/call route include `HasSameSizeAs` at `0x004b7690`, `ContainsRect` at `0x004b7700`, `IntersectInto` at `0x004b7780`, `UnionInto` at `0x004b7830`, `InsetByQuarter` at `0x004b7af0`, `OutsetByHalf` at `0x004b7b90`, and the anchor helpers at `0x004b7f90`, `0x004b8010`, and `0x004b80d0`.
- 2026-07-06 B015 UID00015S implementation support confirms the file-level free-helper island now emits formal C++ through [UID:0000N2][RectBounds](by-file/RectBounds.md). Live MCP session `supervisor_recovery_20260705` confirmed all UID00015S helper starts, zero callees, a unique `0x004b7c30-0x004b7f87` signature, `Point` y/x storage, primary `InsetRect` naming, canonical `PointInRect(y, x, bounds)`, and `RectContainsRect(innerBounds, outerBounds)`. These facts reinforce the class/file split rather than adding class member prototypes.
- Current boundary evidence preserves the same source-family split: `0x004b7661-0x004b7670`, `0x004b78c7-0x004b78d0`, `0x004b7ae8-0x004b7af0`, `0x004b7b88-0x004b7b90`, `0x004b7c21-0x004b7c30`, `0x004b7f87-0x004b7f90`, `0x004b8194-0x004b81a0`, `0x004b8284-0x004b8290`, and `0x004b83c5-0x004b83d0` as alignment/padding gaps. The body islands are `0x004b7670-0x004b78c7` for predicate/combination methods, `0x004b78d0-0x004b7ae8` for modeled member methods, `0x004b7af0-0x004b7c21` for the retained scale-output methods, `0x004b7c30-0x004b7f87` for cdecl free geometry helpers, `0x004b7f90-0x004b8194` for raw anchor transforms, and `0x004b8290-0x004b83c5` for the modeled anchor-axis helper. No class declaration or method body changes arise from the corrected compiler-alignment boundary.
- Float constants checked in the local PE: `0x0061a880` decodes as `0.25f` and is local to the first scale helper; `0x006104b0` decodes as `0.5f` and is used by the scale-helper pair and elsewhere as a shared constant.

## Source Placement

Use `NexusTK/ui/core/RectBounds.cpp` as the source family. It sits with the core UI geometry family (`Pane`, `Layer`, and `Region`) and is supported by broad UI/layout/render caller fanout. Do not merge this into [UID:0000N3][Region](by-file/Region.md): `Region` consumes rectangle primitives for dirty-region work, while `RectBounds` owns the lower-level value record and geometry helpers. Do not assign helpers to feature modules or render-only files merely because those modules call them; the call fanout is broad infrastructure. `util/Geometry.cpp` is a plausible historical fallback spelling only, not the current best-supported route.

## Cross-References

- [UID:0000N2][RectBounds](by-file/RectBounds.md)
- [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) RectBoundsPredicateAndCombinationMethods
- [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) RectBoundsQuarterScaleHelpers
- [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) RectAnchorTransformHelpers
- [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) RectAnchorAxisAdjustHelper
- [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md)
- [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md)
- [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)
- [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md)
- [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md)
- [UID:0000N3][Region](by-file/Region.md)
- [UID:0001QV][client_ui_core](by-meta/client_ui_core.md)

## 2026-08-18 UID0000N2 Whole-File Closure

The completed RectBounds source audit retains this page as the sole class and header owner. `Point` is exactly 8 bytes with `y` at `+0x00` and `x` at `+0x04`; `RectBounds` is exactly 16 bytes with `left`, `top`, `right`, and `bottom` at `+0x00`, `+0x04`, `+0x08`, and `+0x0c`. The binary has no RectBounds constructor, destructor, vtable, RTTI, hidden member, ownership pointer, stored width, or stored height, so the formal header intentionally remains a POD-like struct with fourteen evidence-backed member declarations and no invented object machinery.

The complete member source order is `IsEmptyOrInvalid`, `HasSameSizeAs`, `ContainsPoint`, `ContainsRect`, `IntersectInto`, `UnionInto`, `SetLTRB`, `Offset`, `Inset`, `IntersectWith`, `UnionWith`, `ClampWithin`, `InsetByQuarter`, and `OutsetByHalf`. Direct class children are ordered by address as UID00022G position 10, UID00015Q position 20, UID00022H position 30, and UID00015S position 40. UID00015R is nested at position 10 inside UID00015Q between `Offset` and `IntersectWith`; UID00015T is nested at position 10 inside UID00015S between `InitRectBoundsFromSize` and `IntersectRects`. This route prevents the earlier generated misordering without moving bodies into the class page or duplicating declarations.

The formal H channel is the only `RectBounds.h` guard owner. It defines `Point` and `RectBounds` once, then expands UID00015S's free-function declaration child inside the guard. UID00015S in turn expands the preserved UID00015T declaration `int RectArea(const RectBounds *bounds);` at its exact source position. The class CPP channel contains only `#include "RectBounds.h"` and `[[CHILDREN]]`; every definition remains on the exact by-memory page that owns its range. This preserves the current declaration integration while historicalizing the command-25640 missing-`RectArea` header defect rather than treating that old generated snapshot as current authority.

Raw/no-xref member starts remain authored source, not compiler artifacts: their complete behavior, exact ranges, hashes, boundary alignment, and supervisor-owned staged IDA handoff are documented on UID00022G and UID00022H. Compiler-pooled literals, switch tables, and all alignment spans remain outside the class declaration and emit no authored C++.

## Changes

- 2026-08-11 B006 UID0000N3 implementation callback: inserted the H child marker immediately before the final `#endif`, preserving the guard, Point/RectBounds layout, member declarations, and all CPP routing. UID00015S can now emit the accepted free geometry declarations into `RectBounds.h` without duplicate unguarded definitions.

- 2026-07-06 B015 RectGeometryHelpers implementation support:
  - Score unchanged.
  - Summary/evidence: updated the class/free-helper split after [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) received formal file-level C++ through [UID:0000N2][RectBounds](by-file/RectBounds.md). The class page now records `InitPointPair(Point *point, int y, int x)`, `InsetRect`, canonical `PointInRect(y, x, bounds)`, and `RectContainsRect(innerBounds, outerBounds)` as file-level/free helpers, not class methods. `InflateRect_4B7E30` is historical alias wording only, and [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) remains the separate `RectArea` emitter.

- 2026-06-27 B010 RectBoundsPredicateAndCombinationMethods implementation support:
  - Score unchanged.
  - Summary/evidence: recorded that [UID:00022G][0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md) now carries formal first-draft C++ through the class route for `IsEmptyOrInvalid`, `HasSameSizeAs`, `ContainsPoint`, `ContainsRect`, `IntersectInto`, and `UnionInto`. Preserved the existing prototypes, `ContainsPoint(int y, int x)` ordering, raw/no-xref liveness caveat, and `void UnionInto` decision.
- 2026-06-26 B001 RectBoundsMethods implementation support:
  - Before: `COMPLETION:90`, `CONFIDENCE:88`, and the class shell did not include the retained raw successor at `0x004b7960-0x004b79f7`.
  - Changed to: `COMPLETION:91`, `CONFIDENCE:90`, added `bool IntersectWith(const RectBounds *bounds);`, method inventory/evidence for `0x004b7960-0x004b79f7`, and explicit inference notes for the source-facing name, `bool` return, no-xref liveness caveat, and rejected alternatives.
  - Summary/evidence: B001 accepted report with MCP session `80de0a67`, raw successor disassembly, no direct xref/pointer/branch route, and in-place intersection semantics resolves the previous parent-cluster follow-up while keeping final-audit confidence below 95 because original symbol/source proof is absent.
- 2026-05-30: Changed completion/confidence from `0/0` to `88/84`.
  - Before: The page was unevaluated despite detailed method coverage, layout, raw helper splits, IDA evidence, and multiple exact memory/type cross-references.
  - After: Scored as high completion and strong confidence, with final source-folder placement and a few helper names still below perfect certainty.
  - Evidence: Existing method notes, layout notes, 2026-05-28 gap resolution, caller checks, omitted-output caveats, and memory/type references cover the rectangle helper thoroughly.
- 2026-06-01: Marked reconstructable and attached to [UID:0000N2][RectBounds](by-file/RectBounds.md).
  - Before: The page described a source-owned POD helper class but left autogen metadata blank.
  - After: `RECONSTRUCTABLE:TRUE` and parent `0000N2`.
  - Evidence: IDA MCP recheck confirmed the class-style method island boundaries, no callee dependencies, broad caller fanout, and four-int layout usage across the adjacent free helper island.
- 2026-06-13 A002 Goal2 support refresh:
  - Before: `CONFIDENCE:84`, and the anchor helper reference still used stale end `0x004b8198`.
  - Changed to: `CONFIDENCE:85` and corrected anchor helper references to `0x004b7f90-0x004b8194`.
  - Evidence: live IDA MCP reconfirmed the raw anchor-transform starts, corrected local padding/table boundaries, and the four-call relationship to [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md), strengthening the class-level geometry-helper ownership while keeping final source spellings below final-audit confidence.
- 2026-06-19 B001 accepted source-quality implementation:
  - Before: `COMPLETION:88`, `CONFIDENCE:85`, blank formal C++, stale `OutsetByQuarter`, and unresolved class/free-helper split language.
  - Changed to: `COMPLETION:90`, `CONFIDENCE:88`, declaration-level first-draft `struct RectBounds` C++ with `[[CHILDREN]]`, corrected `OutsetByHalf`, explicit member-versus-file-local helper split, and source placement `NexusTK/ui/core/RectBounds.cpp`.
  - Evidence: accepted B001 report plus current PE/Capstone evidence for exact padding, branch counts, `0.25f`/`0.5f` constants, no-vtable/no-constructor POD shape, cdecl `RectArea` split, file-local anchor-helper route, and broad helper fanout. Remaining confidence caps are exact historical helper spellings, a few return contracts such as `UnionInto`, and original folder spelling below final-audit proof.
- 2026-06-19 B008 RectBoundsInset body implementation support:
  - Score unchanged.
  - Summary/evidence: incorporated [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) source-quality proof into the class notes: `RectBounds::Inset(int dx, int dy)` is a void in-place mutator over `left/top/right/bottom`, uses strict inverted-axis midpoint collapse with signed truncation-toward-zero, rejects chainable return forms, and keeps ownership with [UID:0000BU] through [UID:0000N2][RectBounds](by-file/RectBounds.md). The adjacent raw successor at `0x004b7960-0x004b79f7` was a parent-cluster follow-up at that time and is now superseded by the 2026-06-26 B001 `IntersectWith` entry above; it remains outside the inset method.
- 2026-06-26 B003 RectAnchor helper body implementation support:
  - Score unchanged.
  - Summary/evidence: recorded that [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) and [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) now carry accepted body-level static helper C++ through [UID:0000N2][RectBounds](by-file/RectBounds.md), while this class remains a `struct RectBounds` declaration with member-shaped methods only.
