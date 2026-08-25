** TARGET-REPORT-UID:0000BU **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000BU RectBounds Class Source-Quality Research

Assignment: `B001-0000BU-RectBounds-class-source-quality`  
Agent: `Agent-B001`  
Target: `[UID:0000BU] E:\NTK\GhidraBridge\source-3\project-documentation\by-class\RectBounds.md`  
Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0000BU-RectBounds-class-source-quality.md`  
Current target score: `88/85`  
Current target route: `CANONICAL_OWNER:0000N2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N2`, emitted to `auto-generated/NexusTK/ui/core/RectBounds.cpp`.

## Report-Only Compliance

No by-* documentation, generated output, IDA database, or coverage report was edited. This report is the only changed file for this assignment.

The current assignment is report-only. I did not edit `by-memory/-coverage-report.md`. Exact coverage-row text that would be needed after implementation is included below for supervisor-owned application.

## Final Recommendation

Update the target class page to `COMPLETION:90`, `CONFIDENCE:88`, keep `CANONICAL_OWNER:0000N2`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000N2`, and populate the formal C++ block with a declaration-only POD shell:

```cpp
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
    RectBounds *UnionWith(const RectBounds *bounds);
    void ClampWithin(int leftLimit, int topLimit, int rightLimit, int bottomLimit);
    RectBounds *InsetByQuarter(RectBounds *outBounds) const;
    RectBounds *OutsetByHalf(RectBounds *outBounds) const;
};

[[CHILDREN]]
```

This should be class-level declaration C++ only. Exact method bodies remain with by-memory children, and free/file-local geometry helper bodies remain with the RectBounds source file docs. This follows the current class-page pattern used by pages such as `WebBoardDialog`, `ProgressBarControlPane`, and `ChattingVarietySelectPane`: the class page emits a shell and `[[CHILDREN]]`, while exact ranged method pages own implementation bodies.

The class C++ should not include constructors. No constructor body or vtable exists for this type; source callers initialize records through member setters or free helpers. Leaving the type as a simple `struct` preserves the POD/aggregate source shape better than adding synthetic constructors.

## Evidence Checked

Instruction and policy docs:

- `tools/leaser/Agents/Agent-B001/goal.md`
- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `by-structure.md` current combined-score/emitter C++ gate and class-level code rules
- `by-class/-guidance.md`
- `by-project-structure/proposed-source-tree.md` entries for `ui/core/RectBounds.cpp`

Primary target and direct support:

- `by-class/RectBounds.md`
- `by-file/RectBounds.md`
- `by-type/by-struct/RectBoundsLayout.md`
- `by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md`
- `by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md`
- `by-memory/0x004b7910-0x004b795e.RectBoundsInset.md`
- `by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-memory/0x004b7ca0-0x004b7cb6.RectArea.md`
- `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`
- `by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md`
- `by-file/Region.md`
- `by-memory/-ignored.md`
- `by-class/-coverage-report.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/ui/core/RectBounds.cpp`

Prior B-agent lead rechecked, not copied as authority:

- `tools/leaser/Agents/Agent-B001/research/00022H-RectBoundsQuarterScaleHelpers-source-quality.md`

Local binary/PE evidence:

- Parsed `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Image base `0x00400000`.
- Sections include `.text` at `0x00401000`, `.rdata` at `0x0060d000`, `.data` at `0x0066d000`, `.rsrc` at `0x0069d000`.
- Used Capstone to disassemble the RectBounds method, free-helper, quarter-helper, and anchor-helper windows.
- Scanned executable sections for direct rel8/rel32 branch/call targets to the documented starts.
- Scanned file bytes for literal VA/RVA encodings of selected raw starts and constants.
- No IDA MCP endpoint/tool is exposed in this session; current by-* docs supply prior live-IDA evidence, and the fresh local evidence is PE/Capstone based.

## Current Generated Output State

`auto-generated/NexusTK/ui/core/RectBounds.cpp` currently contains only empty markers for:

- `0000BU` RectBounds class
- `00015R` RectBoundsInset
- `00015T` RectArea
- `00022G` predicate/combination methods
- `00015Q` modeled method island
- `00022H` quarter-scale helpers
- `00015S` free geometry helpers
- `00022I` anchor transform helpers
- `00022L` anchor axis helper
- `0001VP` RectBoundsLayout

This is a source-readiness problem, not an owner-route problem. The class and by-file route already surface to `auto-generated/NexusTK/ui/core/RectBounds.cpp`. The target clears the active combined C++ gate once the source-shape issues below are documented. The old blank-C++ state should be replaced by a declaration-level class shell.

## Binary Range And Boundary Findings

Fresh PE/Capstone confirms the documented class/source-family boundaries:

| Span | Finding |
| --- | --- |
| `0x004b7661-0x004b7670` | 15 bytes of `0xcc` padding before RectBounds predicate methods. |
| `0x004b7670-0x004b78c8` | RectBounds predicate/combination island: modeled starts at `0x004b7670` and `0x004b76d0`; raw function-shaped starts at `0x004b7690`, `0x004b7700`, `0x004b7780`, and `0x004b7830`; internal padding matches current docs. |
| `0x004b78c8-0x004b78d0` | 8 bytes of `0xcc` before `SetLTRB`. |
| `0x004b78d0-0x004b7ae8` | Modeled member-method island with `SetLTRB`, `Offset`, `Inset`, `UnionWith`, and `ClampWithin`; `0x004b7908-0x004b7910` and `0x004b795e-0x004b7960` are `0xcc` padding around `RectBoundsInset`. |
| `0x004b7ae8-0x004b7af0` | 8 bytes of `0xcc` before quarter helper pair. |
| `0x004b7af0-0x004b7b88` | Raw `RectBounds` output helper, 152 bytes, `ret 4` at `0x004b7b85`. |
| `0x004b7b88-0x004b7b90` | 8 bytes of `0xcc` padding. |
| `0x004b7b90-0x004b7c21` | Raw `RectBounds` output helper, 145 bytes, `ret 4` at `0x004b7c1e`. |
| `0x004b7c21-0x004b7c30` | 15 bytes of `0xcc` before free geometry helpers. |
| `0x004b7c30-0x004b7f87` | File-level point/rect free-helper island. |
| `0x004b7f87-0x004b7f90` | 9 bytes of `0xcc` before anchor transform raw cluster. |
| `0x004b7f90-0x004b8194` | Raw 3x3 anchor transform cluster; local switch table bytes need source-control-flow reconstruction, not literal table porting. |
| `0x004b8194-0x004b81a0` | 12 bytes of `0xcc` before unrelated `WideStringHashHelper`. |
| `0x004b8284-0x004b8290` | 12 bytes of `0xcc` before anchor axis helper. |
| `0x004b8290-0x004b83c5` | Modeled/source-authored anchor axis helper plus local switch data. |
| `0x004b83c5-0x004b83d0` | 11 bytes of `0xcc` before `GeneralPurposePanel`. |

The `0x004b7c21` end remains correct: the `04 00` operands of the second quarter helper's `ret 4` belong to the helper body, not to padding.

## Direct Caller And Reachability Evidence

Fresh executable-section branch scan produced these useful counts:

| Start | Direct branch/call target count | Interpretation |
| --- | ---: | --- |
| `0x004b7670` | 7 | Modeled `IsEmptyOrInvalid` is live. |
| `0x004b7690` | 0 | Raw `HasSameSizeAs` has no direct route; source-shaped retained method. |
| `0x004b76d0` | 3 | Modeled `ContainsPoint` is live; documented IDA xrefs also show folder/tree UI hit-test callers. |
| `0x004b7700` | 0 | Raw `ContainsRect` has no direct route; source-shaped retained method. |
| `0x004b7780` | 0 | Raw `IntersectInto` has no direct route; source-shaped retained method. |
| `0x004b7830` | 0 | Raw `UnionInto` has no direct route; source-shaped retained method. |
| `0x004b78d0` | 207 | `SetLTRB` has broad fan-in. |
| `0x004b78f0` | 207 | `Offset` has broad fan-in. |
| `0x004b7910` | 3 | `Inset` callers remain the `sub_53BB20` cluster. |
| `0x004b7a00` | 33 | `UnionWith` is live. |
| `0x004b7a80` | 2 | `ClampWithin` is live, still narrow world-map visible-bounds-style behavior. |
| `0x004b7af0` | 0 | No direct branch/call route to first quarter helper. |
| `0x004b7b90` | 0 | No direct branch/call route to second scale helper. |
| `0x004b7c30` | 101 | Point-pair initializer is broadly used. |
| `0x004b7c50` | 1731 | `InitRectBounds` is extremely broad shared infrastructure. |
| `0x004b7c70` | 38 | Left/top/width/height rectangle initializer is live. |
| `0x004b7ca0` | 4 | `RectArea` is live and narrow. |
| `0x004b7cc0` | 91 | `IntersectRects` is broadly used. |
| `0x004b7d70` | 37 | Free rectangle union helper is live. |
| `0x004b7e10` | 368 | Free offset helper is broadly used. |
| `0x004b7e30` | 32 | Free inset/inflate helper is live. |
| `0x004b7e80` | 270 | `PointInRect` is broadly used. |
| `0x004b7eb0` | 32 | Free empty predicate is live. |
| `0x004b7ed0` | 7 | Free equivalence predicate is live. |
| `0x004b7f30` | 2 | Free containment predicate is live. |
| `0x004b7f90` | 0 | Anchor transpose raw start has no direct external route. |
| `0x004b8010` | 0 | First anchor transform raw start has no direct external route. |
| `0x004b80d0` | 0 | Offset anchor transform raw start has no direct external route. |
| `0x004b8290` | 4 | All four direct calls come from the raw anchor transform cluster at `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161`. |

The fresh whole-file literal scan found no literal VA/RVA entries for `0x004b7af0`, `0x004b7b90`, `0x004b7f90`, `0x004b80d0`, or `0x004b8290`. It found one apparent RVA encoding for `0x004b8010` at `0x0050f77c`, but disassembly shows this is just the rel32 operand of an unrelated `call 0x005c7790`, not a pointer-table or source-use route to the anchor helper. Do not treat it as anchor liveness evidence.

`0x0061a880` is `0.25f` and has two local VA references in the first scale helper. `0x006104b0` is `0.5f` and is a shared constant with many references; local use in the scale helper pair remains as documented.

## Class Layout And Field Names

Use exactly four public integer edge fields:

| Offset | Source-facing field | Rationale |
| --- | --- | --- |
| `+0x00` | `left` | Written by `SetLTRB` / `InitRectBounds`; compared against `right` for width/emptiness and point hit tests. |
| `+0x04` | `top` | Written by setters; compared against `bottom`; `ContainsPoint` / `PointInRect` use `top <= y`. |
| `+0x08` | `right` | Width is `right - left`; copied and unioned by member/free helpers. |
| `+0x0c` | `bottom` | Height is `bottom - top`; empty if `bottom <= top`. |

No width, height, vtable, base class, constructor state, ownership pointer, or hidden flags are supported. `RectBounds` should remain a 16-byte POD-like value type. A Windows `RECT`-compatible layout is true at memory level, but the source-facing project type should remain `RectBounds` because the by-file source owner, class docs, and method cluster all use the custom RectBounds value-object route.

## Source-Facing Method Inventory

Best source-facing declarations for class methods:

| Range | Recommended declaration | Confidence | Notes |
| --- | --- | --- | --- |
| `0x004b7670-0x004b7685` | `bool IsEmptyOrInvalid() const` | High | Returns true for `right <= left || bottom <= top`. |
| `0x004b7690-0x004b76c8` | `bool HasSameSizeAs(const RectBounds *bounds) const` | Medium-high | Raw/no-xref but signature is one stack pointer and thiscall receiver; compares width and height only. |
| `0x004b76d0-0x004b76f8` | `bool ContainsPoint(int y, int x) const` | High | Argument order is `y, x`; binary reads `[ebp+0x0c]` as x and `[ebp+0x08]` as y. Preserve this unusual order because other UI helpers also use mouseY/mouseX ordering. |
| `0x004b7700-0x004b7775` | `bool ContainsRect(const RectBounds *bounds) const` | Medium-high | Raw/no-xref; empty input is contained, empty receiver is not. |
| `0x004b7780-0x004b782a` | `bool IntersectInto(const RectBounds *bounds, RectBounds *outBounds) const` | Medium-high | Raw/no-xref; optional output pointer is allowed; clears output to zero on failure; returns success bool. |
| `0x004b7830-0x004b78c8` | `void UnionInto(const RectBounds *bounds, RectBounds *outBounds) const` | Medium | Raw/no-xref; writes output for all paths. `RectBounds *` output return is possible because EAX often contains `outBounds`, but no caller proves return use. Use `void` in the class shell until a caller or source line proves the return contract. |
| `0x004b78d0-0x004b78ee` | `void SetLTRB(int leftValue, int topValue, int rightValue, int bottomValue)` | High | Directly writes four fields; leaves EAX incidentally as the last loaded argument but no return contract is proven. |
| `0x004b78f0-0x004b7908` | `void Offset(int dx, int dy)` | High | Adds `dx` to left/right and `dy` to top/bottom. |
| `0x004b7910-0x004b795e` | `void Inset(int dx, int dy)` | High | Class-owned member-style inset/shrink helper; collapses inverted axes to midpoint. |
| `0x004b7a00-0x004b7a77` | `RectBounds *UnionWith(const RectBounds *bounds)` | Medium-high | Mutates receiver and explicitly returns `this` in both major paths; `void` is a fallback if later source-style review proves return ignored by design. |
| `0x004b7a80-0x004b7ae8` | `void ClampWithin(int leftLimit, int topLimit, int rightLimit, int bottomLimit)` | High | Four stack arguments, not a `RectBounds *`; shifts current fixed-size rect inside supplied edge limits. |
| `0x004b7af0-0x004b7b88` | `RectBounds *InsetByQuarter(RectBounds *outBounds) const` | High | Raw/no-xref but thiscall/output-pointer shape is strong; insets by one quarter of width/height on each side and returns a half-size centered rectangle. |
| `0x004b7b90-0x004b7c21` | `RectBounds *OutsetByHalf(RectBounds *outBounds) const` | High | Corrects stale `OutsetByQuarter`; second helper uses `0.5f` scale and produces a double-size rectangle. |

Rejected method-name alternatives:

- `ContainsPoint(int x, int y)`: rejected for formal declaration because binary argument order is `y, x`; using x/y would make call-site reconstruction misleading.
- `SetRect` / `SetBounds`: plausible, but local docs and `left/top/right/bottom` explicit behavior support `SetLTRB` as the clearest current source-facing name.
- `Move` instead of `Offset`: rejected because free helper naming and existing docs consistently use offset/rect movement language.
- `MakeHalfSize` / `MakeDoubleSize` for the scale helpers: plausible conceptual aliases, but `InsetByQuarter` / `OutsetByHalf` better express the actual edge operations and match neighboring `Inset`/`InflateRect` terminology.
- `OutsetByQuarter`: stale. The second helper multiplies spans by `0.5f`, not `0.25f`.

## Free/File-Local Helper Split

The class page should distinguish class methods from source-file geometry helpers. The following are RectBounds source-family helpers but should not be listed as class member methods unless later source evidence proves a static/member declaration:

| Range | Best source-facing declaration direction | Rationale |
| --- | --- | --- |
| `0x004b7c30-0x004b7c43` | `void InitPointPair(PointPair *point, int y, int x)` or local point initializer | Cdecl helper; not tied to `RectBounds` receiver. Exact point type/name remains unresolved. |
| `0x004b7c50-0x004b7c6f` | `void InitRectBounds(RectBounds *bounds, int left, int top, int right, int bottom)` | Extremely broad shared initializer; cdecl stack pointer, not member method. |
| `0x004b7c70-0x004b7c95` | `void InitRectBoundsFromSize(RectBounds *bounds, int left, int top, int width, int height)` | Writes `right = left + width`, `bottom = top + height`; `InitRect_4B7C70` is a raw-address placeholder. |
| `0x004b7ca0-0x004b7cb6` | `int RectArea(const RectBounds *bounds)` | Cdecl stack-pointer helper with four direct callers; should be file-level RectBounds geometry helper, not a thiscall class method. |
| `0x004b7cc0-0x004b7d69` | `bool IntersectRects(const RectBounds *a, const RectBounds *b, RectBounds *outBounds)` | Free-helper counterpart to `IntersectInto`; broad caller fan-in. |
| `0x004b7d70-0x004b7e03` | `void UnionRects(const RectBounds *a, const RectBounds *b, RectBounds *outBounds)` | Current `UnionRect_4B7D70` address suffix should be removed in source-facing prose. |
| `0x004b7e10-0x004b7e29` | `void OffsetRect(RectBounds *bounds, int dx, int dy)` | Free-helper counterpart to member `Offset`. |
| `0x004b7e30-0x004b7e7f` | `void InflateRect(RectBounds *bounds, int dx, int dy)` / `InsetRect` caveat | Body collapses inverted axes like member `Inset`; final name should follow observed caller semantics before C++ body entry. |
| `0x004b7e80-0x004b7ea7` | `bool PointInRect(int y, int x, const RectBounds *bounds)` | Free half-open point test; the established y/x order should be preserved. |
| `0x004b7eb0-0x004b7ecd` | `bool IsRectEmptyOrInvalid(const RectBounds *bounds)` | Free predicate with same empty convention. |
| `0x004b7ed0-0x004b7f22` | `bool RectsEquivalent(const RectBounds *a, const RectBounds *b)` | Treats two empty rectangles as equivalent. |
| `0x004b7f30-0x004b7f87` | `bool RectContainsRect(const RectBounds *outer, const RectBounds *inner)` | Free containment helper; empty inner rectangle is contained. |

Recommended support correction: [UID:00015T] `RectArea` currently has class owner/emitter `0000BU`. It should be rerouted to file/source-family owner `0000N2` because the binary signature is cdecl with a stack `RectBounds *`, not a thiscall member. It can still be cross-referenced from the class page as a closely related helper.

## Quarter-Scale Helper Route

Best route for [UID:00022H]:

```text
CANONICAL_OWNER:0000BU
EMITTER_UIDS:0000BU
```

This is the same conclusion as the earlier B001 `00022H` report, revalidated at the class level. The helpers use `ecx` as the source `RectBounds`, take one stack output pointer, end with `ret 4`, and sit between class methods and free geometry helpers. They are class-method-shaped retained source code, not cdecl free helpers.

The class page must correct the stale method row from `InsetByQuarter / OutsetByQuarter` to:

```text
InsetByQuarter(RectBounds *outBounds) const / OutsetByHalf(RectBounds *outBounds) const
```

The first helper uses `0.25f` and `0.5f` rounding bias for left/top, yielding a half-size centered rectangle. The second helper loads `0.5f` as the scale factor, not `0.25f`, yielding a double-size rectangle.

No direct callers, VA/RVA pointer-table entries, or vtable route were found for either raw start. That is a liveness confidence cap, not a no-code proof. These are source-authored project-specific geometry methods retained in `.text`.

## Anchor Transform Helper Route

Best route for [UID:00022I] and [UID:00022L]:

```text
CANONICAL_OWNER:0000N2
EMITTER_UIDS:0000N2
```

The anchor helpers should stay in the `RectBounds.cpp` source family but not be declared as `RectBounds` class member methods. They operate on rectangle pairs, anchor indices, edge-slot pointers, and optional offsets, not on one `RectBounds` receiver. The source-facing shape is file-local/static geometry support.

Recommended source-facing names:

- `Transpose3x3AnchorIndex(int anchor)` for `0x004b7f90-0x004b8004`.
- `AdjustRectPairForAnchor(int anchor, const RectBounds *sourceA, const RectBounds *sourceB, RectBounds *outA, RectBounds *outB)` for `0x004b8010-0x004b80d0`, with exact parameter names/order still requiring a body-level callback pass.
- `AdjustRectPairForAnchorWithOffsets(...)` for `0x004b80d0-0x004b8194`, preserving the horizontal and vertical offset arguments documented in [UID:00022I].
- `AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh)` for `0x004b8290-0x004b83c5`.

The switch/jump table bytes in [UID:00022I] and [UID:00022L] are compiler-generated artifacts of source switch/control flow. Do not hand-port table bytes into C++ as explicit source data unless future source evidence proves an original table declaration.

Rejected anchor alternatives:

- RectBounds class member methods: rejected because no single `this` rectangle receiver owns the operation.
- `Region.cpp`: rejected because the helpers use the lower-level RectBounds layout and predate/stand apart from dirty-region wrappers.
- `WideStringHash`, `FileExists`, `BuildFieldMapPath`, or `GeneralPurposePanel`: rejected as address-neighbor artifacts; current docs already split those unrelated helpers between the transform cluster and axis helper.
- No-owner/non-emitting: rejected for the source family because the axis helper has a closed internal caller set and all helpers are RectBounds-layout geometry logic.

## Source Placement

Use `NexusTK/ui/core/RectBounds.cpp` and a paired `RectBounds.h` or UI-core geometry header as the active source-placement recommendation.

Evidence:

- `by-project-structure/proposed-source-tree.md` lists `RectBounds.cpp` under `ui/core/` beside `Pane`, `Layer`, and `Region`.
- `by-file/RectBounds.md` already has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/"`.
- The class and helper fan-in crosses UI, render, map, menu, and resource callers; no single feature module owns these routines.
- `Region.cpp` consumes lower-level rectangle primitives but owns dirty-region wrappers and historical `Motion` rectangle behavior, not this four-int value object.

Rejected source-placement alternatives:

- Feature-local ownership: rejected by extreme shared fan-in (`InitRectBounds` 1731 direct branch targets in the fresh scan, `PointInRect` 270, `OffsetRect` 368).
- `Region.cpp`: rejected because Region stores/operates on dirty-region objects and consumes RectBounds-like primitives rather than owning the base value object.
- `render/` only: rejected because callers are not render-only; UI/layout/focus/hit-test paths are equally central.
- `util/Geometry.cpp`: plausible historical fallback, but the current proposed source tree and by-file metadata point to `ui/core`; keep `util` as a note, not the active route.

## First-Draft C++ Readiness

The target class is ready for declaration-level first-draft C++ now.

Why C++ is appropriate:

- The class has valid owner/emitter routing through [UID:0000N2] `RectBounds`.
- Current target score `88/85` already clears the active combined gate: `(88 + 85) / 2 = 86.5 > 85`.
- This report resolves the class source-shape blockers enough for a declaration shell: fields, POD/no-vtable policy, method-vs-free-helper split, quarter helper route, anchor helper route, source placement, and stale helper name correction.
- The class C++ is declaration-only and does not overrun child memory ranges.
- `[[CHILDREN]]` lets exact by-memory children provide method bodies after their own implementation callbacks.

Why the C++ should be declaration-only:

- Exact method bodies belong to ranged by-memory pages.
- Some child pages still need their own source-body callbacks, especially [UID:00022G], [UID:00015Q], [UID:00022H], and [UID:00015S].
- Anchor helpers are file-local source support and should not appear as class methods.
- `RectArea` should be file-level/free, not class member, despite current support metadata.

## Score Recommendation

For `by-class/RectBounds.md`:

| Field | Before | Recommended | Rationale |
| --- | ---: | ---: | --- |
| Completion | 88 | 90 | Class method inventory, field names, source placement, class/free split, quarter-scale correction, anchor-helper route, generated-output state, and class-level C++ readiness are now resolved at report level. |
| Confidence | 85 | 88 | Strong binary/layout/source-family evidence supports the POD class shell. Keep confidence below 90 because several exact historical method names, `UnionInto` return type, `ui/core` versus hypothetical utility placement, and raw no-xref helper liveness remain inferred rather than source-proven. |

Keep:

```text
CANONICAL_OWNER:0000N2
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N2
EMITTER_POSITION_OPTIONAL:
```

## Open Questions And Best Answers

1. Was this originally a `class` or `struct`?
   - Evidence checked: no vtable, no constructor, direct four-int field copies, free helpers, and POD layout docs.
   - Best answer: source should be represented as `struct RectBounds` with public fields. This is still a C++ class type and best matches the POD source shape.

2. Are the four fields really `left`, `top`, `right`, `bottom`?
   - Evidence checked: setters, half-open point checks, area, intersection/union, offset/inset, clamp, and helper docs.
   - Best answer: yes. Do not rename to x/y/w/h. Width/height are derived spans.

3. Should quarter helpers stay file-owned or move to class-owned?
   - Evidence checked: `ecx` receiver, one stack output pointer, `ret 4`, output pointer return pattern, adjacency to member methods, no caller/pointer evidence, prior B001 PE report.
   - Best answer: class-owned. Use [UID:0000BU] as owner/emitter for [UID:00022H] when implementation is accepted.

4. Is the second quarter helper actually quarter-scale?
   - Evidence checked: fresh PE constants and prior B001 disassembly.
   - Best answer: no. Rename source-facing role to `OutsetByHalf`.

5. Are anchor helpers class methods?
   - Evidence checked: parameter/edge-pointer docs, axis helper caller set, raw start liveness, unrelated neighbors, RectBoundsLayout use.
   - Best answer: no. Keep as file-level/static geometry helpers in `RectBounds.cpp`.

6. Should `RectArea` be class-owned?
   - Evidence checked: `0x004b7ca0` cdecl body uses `[ebp+8]` rectangle pointer, has plain `ret`, and no `ecx` receiver.
   - Best answer: no. It is source-family-owned by `RectBounds.cpp`, but its direct canonical/emitter route should be [UID:0000N2], not [UID:0000BU].

7. What is the correct point argument order?
   - Evidence checked: `ContainsPoint` reads `[ebp+0x0c]` as x and `[ebp+0x08]` as y; `PointInRect` docs also preserve `y, x`.
   - Best answer: formal source declarations should use `int y, int x` unless a later source-style pass proves a wrapper swapped names at call sites.

8. Should the class C++ include helper bodies?
   - Evidence checked: by-structure class-page guidance and recent class examples.
   - Best answer: no. Emit declaration shell plus `[[CHILDREN]]`; bodies remain on exact memory docs.

9. Is `UnionInto` return type known?
   - Evidence checked: raw body writes output in all paths and often leaves `outBounds` in EAX, but no direct callers exist to prove return use.
   - Best answer: use `void` in the class declaration for now. A `RectBounds *` return remains plausible but is not worth hardcoding at class-shell level without caller/source proof.

10. Does no-xref raw code mean no-code?
    - Evidence checked: raw prologues/epilogues, exact padding, no branch/pointer routes, project-specific RectBounds math, adjacent source family.
    - Best answer: no. These are source-authored retained helper bodies. No-xref state affects confidence/liveness notes, not reconstructability.

## Heuristic / Inference Reanalysis And Validation

This section consolidates the source-quality decisions that are otherwise supported throughout the report. No IDA MCP endpoint/tool was exposed in this session, so the evidence layers are separated explicitly:

- Direct fresh evidence: local PE parsing and Capstone disassembly of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, executable-section branch/call target scans, VA/RVA literal scans, exact `0xcc` padding checks, and local constant checks for `0.25f` / `0.5f`.
- Prior IDA-backed documentation evidence: current by-* pages that already record live IDA function boundaries, decompilation, xrefs/callees, owner/emitter routes, and generated-output state.
- Inference: source-facing method spellings, historical file path preference, return-type policy where no caller survives, and whether retained no-xref raw bodies are unused source rather than compiler artifacts.

1. `struct RectBounds` versus `class`, constructor, or vtable-backed object
   - Evidence checked: the class page, layout page, predicate/member/free-helper ranges, generated `RectBounds.cpp`, fresh PE range scan, and local disassembly all show a 16-byte value type passed by pointer. There are no vtable stores, no RTTI/vtable data, no scalar deleting destructor, no allocation-only constructor, and no hidden state. Member-shaped bodies use `ecx` as a pointer to four ints; cdecl free helpers use a stack `RectBounds *`.
   - Candidate interpretations: public POD `struct RectBounds`; private-field `class RectBounds`; Windows `RECT` typedef wrapper; compiler-synthesized class with constructors/vtable; generated support-only/no-code layout.
   - Rejected alternatives: vtable/class machinery is rejected because no vtable/RTTI/destructor evidence exists. Synthetic constructors are rejected because source callers initialize records through setters/free initializers, and adding constructors would invent source. A raw `RECT` typedef is rejected because the project has a documented RectBounds class/file/source family and many custom methods/helpers around the type.
   - Final best direction: declare `struct RectBounds` with public `int left/top/right/bottom` fields and member declarations only.
   - Score/C++ impact: raises the class target because declaration-level C++ is now safe. It also caps confidence below final-audit because original source may have used `class` with public methods and private fields, but binary evidence does not justify inventing access-control or constructors.

2. Four-field layout names `left`, `top`, `right`, `bottom`
   - Evidence checked: `SetLTRB` and `InitRectBounds` write the four fields in edge order; point tests compare `left <= x < right` and `top <= y < bottom`; area computes `(right - left) * (bottom - top)`; union/intersection choose min low edges and max high edges; `Offset` shifts both horizontal edges by the same delta and both vertical edges by the same delta; inset/quarter helpers use edge deltas.
   - Candidate interpretations: `left/top/right/bottom`; `x/y/width/height`; `minX/minY/maxX/maxY`; hidden state plus dimensions.
   - Rejected alternatives: width/height layout is rejected because the stored third/fourth fields are compared as right/bottom edges and area derives spans from differences. Hidden state is rejected because every observed read/write fits four plain signed ints and no byte/flag/pointer fields are read.
   - Final best direction: use exactly `int left; int top; int right; int bottom;`.
   - Score/C++ impact: direct PE and prior layout evidence make field names strong enough for the class shell. No method body should be emitted from the class page solely because field names are resolved.

3. `ContainsPoint(int y, int x)` argument order
   - Evidence checked: the `0x004b76d0` member body reads `[ebp+0x0c]` as the value compared with `left/right` and `[ebp+0x08]` as the value compared with `top/bottom`. The free `PointInRect` support docs preserve the same source-facing `y, x` convention. Several UI/pane helper families in this repo pass mouse coordinates as `mouseY, mouseX`, so the ordering is not unprecedented.
   - Candidate interpretations: `ContainsPoint(int y, int x)`; conventional `ContainsPoint(int x, int y)` with the caller swapping values; ambiguous `ContainsPoint(int coord0, int coord1)`.
   - Rejected alternatives: `x, y` is rejected for the formal declaration because it contradicts the actual stack-slot use and would mislead later code emission. Generic `coord0/coord1` is weaker than the proven edge comparisons.
   - Final best direction: declare `bool ContainsPoint(int y, int x) const` and keep a note that the argument order is deliberate.
   - Score/C++ impact: strong enough for class declaration C++. Exact historical parameter names remain an inference, so confidence does not move into final-audit range.

4. Member-method versus file-local helper split, including `RectArea`
   - Evidence checked: member candidates at `0x004b7670-0x004b7c21` use `ecx` as the receiver and return with thiscall-style stack cleanup where applicable. Free helpers from `0x004b7c30` onward use cdecl stack pointer arguments and plain returns. `RectArea` at `0x004b7ca0` reads the rectangle through `[ebp+8]`, has no `ecx` receiver dependency, has no callees, and returns the signed span product directly.
   - Candidate interpretations: every geometry helper is a `RectBounds` method; only thiscall-shaped helpers are methods and cdecl helpers are file-level helpers; `RectArea` is a static class method; `RectArea` belongs to a generic math utility.
   - Rejected alternatives: treating `RectArea` as a class-owned instance method is rejected because the binary signature is cdecl/file-helper-shaped. Generic utility ownership is weaker because the helper sits in the contiguous RectBounds source family and uses RectBounds layout directly.
   - Final best direction: `RectArea` should be file-level [UID:0000N2] source-family code with signature `int RectArea(const RectBounds *bounds)`, not class-owned [UID:0000BU]. It may remain cross-referenced from the class page as a related helper.
   - Score/C++ impact: the class shell excludes `RectArea`, which prevents incorrect method emission. A support-doc metadata/prose callback should reroute `RectArea` to [UID:0000N2].

5. [UID:00022H] quarter-scale helper route despite no direct xrefs
   - Evidence checked: fresh PE/Capstone reconfirms exact raw bodies, `0xcc` padding before/between/after, `ecx` receiver use, one stack output pointer, `ret 4`, and no direct branch/call or VA/RVA pointer routes to the two starts. Existing by-* docs and the prior B001 report already identify the bodies as source-shaped RectBounds helpers adjacent to the member-method island.
   - Candidate interpretations: class-owned retained member helpers; cdecl file helpers; dead compiler artifacts; no-code/unreachable bytes.
   - Rejected alternatives: cdecl/file-helper shape is rejected because the helpers use `ecx` as the source rectangle and clean one stack argument. Compiler artifact/no-code is rejected because the bodies are normal project-specific geometry code with clean function boundaries and source-level math, not thunks, unwind glue, vtable data, or padding.
   - Final best direction: keep [UID:00022H] class-owned under [UID:0000BU], source-authored and reconstructable. No-xref state should be documented as retained/unused liveness uncertainty, not as no-code proof.
   - Score/C++ impact: the class page can declare both methods. Exact method bodies should remain on [UID:00022H] and can be emitted there only after that exact page's implementation callback.

6. Correcting stale `OutsetByQuarter` to `OutsetByHalf`
   - Evidence checked: the first helper uses the `0.25f` constant at `0x0061a880` to inset by one quarter of the current width/height on each side, producing a centered half-size rectangle. The second helper uses the `0.5f` constant at `0x006104b0`, not the `0.25f` constant, and expands edges outward by one half-span on each side, producing a double-size rectangle.
   - Candidate interpretations: `InsetByQuarter` / `OutsetByQuarter`; `InsetByQuarter` / `OutsetByHalf`; `MakeHalfSize` / `MakeDoubleSize`; generic scale helpers.
   - Rejected alternatives: `OutsetByQuarter` is stale because it contradicts the `0.5f` operand. `MakeHalfSize`/`MakeDoubleSize` are plausible but less aligned with the surrounding edge-operation naming (`Inset`, `Offset`, rect helpers).
   - Final best direction: first helper `RectBounds::InsetByQuarter(RectBounds *outBounds) const`; second helper `RectBounds::OutsetByHalf(RectBounds *outBounds) const`.
   - Score/C++ impact: supports raising completion because it resolves a stale source-facing method name. Confidence remains capped because exact original names are inferred from behavior, not recovered source.

7. Anchor transform helpers as file-local/static RectBounds.cpp helpers
   - Evidence checked: [UID:00022I] and [UID:00022L] docs, fresh PE padding, branch/call target scan, and literal scan. The raw anchor helpers operate on anchor indices, rect pairs, edge-slot pointers, and optional offsets. The axis helper at `0x004b8290` has four direct callers, all from the raw anchor transform cluster. The whole-file literal scan found one apparent RVA encoding for `0x004b8010`, but disassembly at `0x0050f77c` shows it is the rel32 operand of an unrelated `call 0x005c7790`, not a pointer table or helper route.
   - Candidate interpretations: `RectBounds` class member methods; static/file-local helpers in `RectBounds.cpp`; Region/layout owner helpers; no-code raw bytes.
   - Rejected alternatives: class methods are rejected because there is no single `this` receiver and the helpers work across rect pairs/anchors. Region/layout ownership is rejected because the helpers sit in the RectBounds geometry source neighborhood and use RectBounds fields directly. The false `0x004b8010` RVA hit is rejected as liveness evidence because it is not an address reference.
   - Final best direction: keep [UID:00022I] and [UID:00022L] owner/emitter [UID:0000N2] as file-local/static `RectBounds.cpp` helpers, with descriptive names `Transpose3x3AnchorIndex`, `AdjustRectPairForAnchor`, `AdjustRectPairForAnchorWithOffsets`, and `AdjustRectAnchorAxis`.
   - Score/C++ impact: anchor helpers should not be listed in the class declaration. Their exact bodies stay blank until a body-level callback resolves exact parameter declarations and switch-shape C++.

8. `UnionInto` return-type uncertainty
   - Evidence checked: raw `0x004b7830` writes an output rectangle in all paths and often leaves the output pointer in `eax`. No direct callers or pointer routes were found, so no caller proves a returned pointer is consumed. Neighboring helpers include both true mutating-return methods and void-style setters where EAX is incidental.
   - Candidate interpretations: `void UnionInto(const RectBounds *bounds, RectBounds *outBounds) const`; `RectBounds *UnionInto(...) const`; free `UnionRects` equivalent.
   - Rejected alternatives: declaring a pointer return in the class shell is rejected for now because no caller/source proof shows return-value significance. Treating it as the free `UnionRects` helper is rejected because this raw body is thiscall/member-shaped and sits in the predicate/combination member island.
   - Final best direction: class shell should use `void UnionInto(const RectBounds *bounds, RectBounds *outBounds) const` until source/caller proof appears.
   - Score/C++ impact: this is the main method-signature confidence cap. It does not block declaration-level C++ because choosing `void` avoids over-claiming.

9. Why no-xref raw helper bodies are not no-code/compiler artifacts
   - Evidence checked: PE/Capstone shows clean raw prologues/epilogues or coherent function bodies, exact padding fences, project-specific RectBounds math, adjacency to live member/free helper bodies, and no bytes that look like vtable data, jump-table-only data, thunk stubs, scalar deleting destructors, SEH-only cleanup, or compiler-generated padding. Branch/literal scans found no external route for several raw starts, but that is negative reachability evidence, not compiler-artifact proof.
   - Candidate interpretations: retained source-authored helpers; compiler glue; dead padding/data; generated no-code rows.
   - Rejected alternatives: compiler glue and padding/data are rejected because the bodies implement full geometry algorithms with normal calling conventions. Generated no-code is rejected because the class/file route emits to real source and the functions are not aggregate-only containers.
   - Final best direction: document raw/no-xref helpers as reconstructable retained source-authored helpers with liveness confidence caps.
   - Score/C++ impact: supports retaining reconstructable status and class declarations. It prevents raising confidence above strong because some methods have no current callers.

10. Source placement: `NexusTK/ui/core/RectBounds.cpp`
    - Evidence checked: by-file route [UID:0000N2], generated output path, proposed source tree, broad UI/pane/layout caller distribution, Region doc, RectBounds layout/type docs, and the contiguous geometry helper cluster.
    - Candidate interpretations: `NexusTK/ui/core/RectBounds.cpp`; `Region.cpp`; feature-local ownership by caller modules; render-only/effects ownership; `util/Geometry.cpp`; no-owner support source.
    - Rejected alternatives: Region ownership is too narrow and owns separate region behavior, not the whole RectBounds helper family. Feature-local ownership is rejected because callers are broad and the helper cluster is centralized. Render-only/effects ownership is rejected because usage is UI/layout/general geometry, not renderer-specific. `util/Geometry.cpp` remains a possible historical spelling but is lower probability than the documented/generated `ui/core/RectBounds.cpp` route. No-owner/no-code is rejected because source and class/file routes are already established.
    - Final best direction: keep owner/emitter through [UID:0000N2] and source placement `NexusTK/ui/core/RectBounds.cpp`.
    - Score/C++ impact: sufficient for class-page emission; confidence remains below 90 because the exact historical folder name is source-tree inferred rather than proven by original project files.

11. First-draft C++ policy
    - Evidence checked: `by-structure.md` class-page guidance, active generated `RectBounds.cpp`, examples of class pages that emit declaration shells plus `[[CHILDREN]]`, and the exact child by-memory pages that own method bodies.
    - Candidate interpretations: full class declaration plus all method bodies on the class page; declaration shell plus `[[CHILDREN]]`; no C++ until every exact helper body is final; only by-memory pages emit C++.
    - Rejected alternatives: full bodies on the class page are rejected because exact ranges own the implementations and some bodies still have return/name uncertainty. No C++ is too conservative because the layout, source route, and declaration-level method inventory now clear the active class C++ gate. Only by-memory emission would leave the class type itself blank despite the class page being the right declaration owner.
    - Final best direction: class page emits the declaration shell with fields, method prototypes, and `[[CHILDREN]]`; exact method bodies remain on exact by-memory pages; file-local helpers stay out of the class declaration.
    - Score/C++ impact: supports `COMPLETION:90`, `CONFIDENCE:88`, and first-draft declaration-level C++ now. It does not change support-doc implementation recommendations from the rest of this report.

Implementation checklist note: this correction reorganizes and makes explicit the heuristic/source-quality validation, but it does not change the recommended target/support edits, score metadata, coverage text, validation commands, or implementation callback checklist already listed below.

## Recommended Target Doc Changes

For `by-class/RectBounds.md`:

1. Change metadata to:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Populate the formal C++ block with the declaration-only `struct RectBounds` block in this report.

3. Status section:
   - Replace "medium final source folder" with "strong for POD layout and class shell; medium-high for exact original helper spellings and final UI-core versus utility folder."
   - Add "Final C++ status: declaration-level first draft ready; method bodies remain on exact by-memory pages."
   - Preserve owner/emitter [UID:0000N2].

4. Class purpose:
   - State explicitly that this is a 16-byte POD-like C++ value type with no vtable and no proven constructor.
   - State that `RectBounds` is memory-compatible with a four-int `RECT` but source-facing should remain `RectBounds`.

5. Method table:
   - Add source-facing signatures, not only names.
   - Correct `ContainsPoint` to `ContainsPoint(int y, int x)`.
   - Correct `ClampWithin` to four edge-limit arguments.
   - Correct `InsetByQuarter / OutsetByQuarter` to `InsetByQuarter(RectBounds *outBounds) const / OutsetByHalf(RectBounds *outBounds) const`.
   - Move `RectArea` out of class-method wording into "related file-level helpers."

6. Add a "Class Versus File-Local Helpers" section:
   - Class methods are the `0x004b7670-0x004b7c21` thiscall/member-shaped helpers listed above.
   - Free helpers start at `0x004b7c30`; include `InitRectBounds`, `InitRectBoundsFromSize`, `RectArea`, `IntersectRects`, `UnionRects`, `OffsetRect`, `PointInRect`, etc.
   - Anchor helpers are file-local/static `RectBounds.cpp` geometry helpers, not class methods.

7. Add a 2026-06-19 B001 PE evidence section:
   - PE path used: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
   - Image base `0x00400000`.
   - Exact padding around class/free/anchor helper ranges.
   - Branch counts for representative live helpers and raw no-xref starts.
   - Literal-scan note for the false `0x004b8010` RVA hit inside an unrelated call operand.
   - Constants `0x0061a880 == 0.25f` and `0x006104b0 == 0.5f`.

8. Add source placement/rejected alternatives:
   - Select `NexusTK/ui/core/RectBounds.cpp`.
   - Reject `Region.cpp`, feature-local modules, render-only ownership, and current no-owner/no-code alternatives.

9. Add a 2026-06-19 change entry:
   - Before: `88/85`, blank formal C++, stale `OutsetByQuarter`, class/free split unresolved.
   - After: `90/88`, declaration-level first-draft `struct RectBounds` C++ with `[[CHILDREN]]`, corrected `OutsetByHalf`, explicit class/free/helper route decisions.

## Recommended Support-Doc Updates

`by-file/RectBounds.md`:

- Update the [UID:00022H] row to say: raw `RectBounds` class-method pair that writes a quarter-inset half-size rectangle and a half-outset double-size rectangle into caller-provided outputs; second helper is `OutsetByHalf`, not `OutsetByQuarter`.
- Add 2026-06-19 PE evidence with broad direct branch counts (`InitRectBounds` 1731, `PointInRect` 270, `OffsetRect` 368, `SetLTRB` and `Offset` 207 each).
- Update generated-output caveats: active `RectBounds.cpp` currently has only empty markers for the class, layout, and method/free-helper children; this should change first at the class declaration level.
- Keep source path `NexusTK/ui/core/`; mention `util/Geometry.cpp` only as a rejected/low-probability historical fallback.

`by-type/by-struct/RectBoundsLayout.md`:

- Add `sizeof(RectBounds) == 16` as a class-declaration fact if not already explicit.
- Correct the quarter-scale bullet to `InsetByQuarter` / `OutsetByHalf`.
- Add that both class and free point tests use `y, x` argument order in current binary/source-facing reconstruction.
- Add that `RectArea` is cdecl/free-helper-shaped, so layout ownership is not proof of class method ownership.

`by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md`:

- Apply the accepted direction from the prior B001 report if supervisor accepts it here:
  - `COMPLETION:89`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000BU`
  - `EMITTER_UIDS:0000BU`
  - formal C++ body from `00022H` report
  - correct second helper to `RectBounds::OutsetByHalf(RectBounds *outBounds) const`
  - keep no-xref/no-pointer route as retained unused source-authored class-method evidence.

`by-memory/0x004b7ca0-0x004b7cb6.RectArea.md`:

- Reframe owner/source declaration as file-level `RectBounds.cpp` helper:
  - recommended `CANONICAL_OWNER:0000N2`
  - recommended `EMITTER_UIDS:0000N2`
  - source-facing signature `int RectArea(const RectBounds *bounds)`
  - explain why the current class-owner wording is misleading: cdecl stack pointer, no `ecx`, plain `ret`.
- Keep cross-reference from class page as a related helper.

`by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`:

- Update `InitRect_4B7C70` to `InitRectBoundsFromSize` or equivalent non-address source-facing name.
- Update `UnionRect_4B7D70` to `UnionRects`.
- Keep `PointInRect(int y, int x, const RectBounds *bounds)` argument order visible.
- Add that the preceding [UID:00022H] island is member-style class output helpers, not part of the cdecl free-helper island.

`by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`:

- Keep owner/emitter [UID:0000N2].
- Add "file-local/static RectBounds.cpp helper" wording.
- Keep `Transpose3x3AnchorIndex`, `AdjustRectPairForAnchor`, and `AdjustRectPairForAnchorWithOffsets` as best descriptive names.
- Add the local PE false-positive note: a raw RVA encoding for `0x004b8010` appears as an unrelated `call` rel32 operand, not pointer-table evidence.
- Keep formal C++ blank until a body-level callback resolves exact parameter declarations.

`by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md`:

- Keep owner/emitter [UID:0000N2].
- Add best descriptive helper name `AdjustRectAnchorAxis`.
- Preserve switch-data/generated-table caveat and four-caller set.

`by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md`:

- Add source-facing signatures from this report.
- Keep raw/no-xref caveat for `HasSameSizeAs`, `ContainsRect`, `IntersectInto`, and `UnionInto`.
- Add `UnionInto` return-type caveat: class shell should use `void` until caller/source evidence proves the output-pointer return is source-significant.

`by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md` and `by-memory/0x004b7910-0x004b795e.RectBoundsInset.md`:

- Add source-facing signatures from this report.
- `ClampWithin` takes four edge-limit ints, not a `RectBounds *`.
- `UnionWith` likely returns `this`; note source-facing `RectBounds *UnionWith(const RectBounds *bounds)` with confidence cap.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were made.

Recommended future names/types/comments:

| Address/item | Recommendation | Confidence |
| --- | --- | --- |
| `0x004b7670` | `RectBounds::IsEmptyOrInvalid()` | High |
| `0x004b7690` | create/comment raw function as `RectBounds::HasSameSizeAs(const RectBounds *bounds)` | Medium-high |
| `0x004b76d0` | `RectBounds::ContainsPoint(int y, int x)` | High |
| `0x004b7700` | create/comment raw function as `RectBounds::ContainsRect(const RectBounds *bounds)` | Medium-high |
| `0x004b7780` | create/comment raw function as `RectBounds::IntersectInto(const RectBounds *bounds, RectBounds *outBounds)` | Medium-high |
| `0x004b7830` | create/comment raw function as `RectBounds::UnionInto(const RectBounds *bounds, RectBounds *outBounds)`; return type unresolved | Medium |
| `0x004b78d0` | `RectBounds::SetLTRB(int left, int top, int right, int bottom)` | High |
| `0x004b78f0` | `RectBounds::Offset(int dx, int dy)` | High |
| `0x004b7910` | `RectBounds::Inset(int dx, int dy)` | High |
| `0x004b7a00` | `RectBounds::UnionWith(const RectBounds *bounds)` | Medium-high |
| `0x004b7a80` | `RectBounds::ClampWithin(int leftLimit, int topLimit, int rightLimit, int bottomLimit)` | High |
| `0x004b7af0` | create/comment raw function as `RectBounds::InsetByQuarter(RectBounds *outBounds) const` | High |
| `0x004b7b90` | create/comment raw function as `RectBounds::OutsetByHalf(RectBounds *outBounds) const` | High |
| `0x004b7c50` | `InitRectBounds(RectBounds *bounds, int left, int top, int right, int bottom)` | High |
| `0x004b7c70` | `InitRectBoundsFromSize(...)` | Medium-high |
| `0x004b7ca0` | `RectArea(const RectBounds *bounds)`, file-level helper | High |
| `0x004b7d70` | `UnionRects(...)`, remove raw address suffix from source-facing docs | Medium-high |
| `0x004b7e80` | `PointInRect(int y, int x, const RectBounds *bounds)` | High |
| `0x004b7f90` | `Transpose3x3AnchorIndex(int anchor)` | Medium-high |
| `0x004b8010` | `AdjustRectPairForAnchor(...)` | Medium |
| `0x004b80d0` | `AdjustRectPairForAnchorWithOffsets(...)` | Medium |
| `0x004b8290` | `AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh)` | Medium-high |
| `0x0061a880` | comment float constant `0.25f`, local to first scale helper use | High |
| `0x006104b0` | comment shared float constant `0.5f`; local scale-helper use plus broader project uses | High |

Do not create vtable/RTTI data for `RectBounds`; no such class machinery is supported.

## Exact Coverage Text

Do not edit any coverage report in this report-only pass.

Recommended replacement row for `by-class/-coverage-report.md`:

```text
- [UID:0000BU][RectBounds](by-class/RectBounds.md) : reconstructable : 90% : strong : B001 2026-06-19 source-quality pass resolves the declaration-level POD source shape for the 16-byte four-int `left/top/right/bottom` rectangle helper, keeps owner/emitter [UID:0000N2][RectBounds](by-file/RectBounds.md), selects `NexusTK/ui/core/RectBounds.cpp` over Region/feature/render-only alternatives, adds first-draft `struct RectBounds` C++ with `[[CHILDREN]]`, preserves no-vtable/no-constructor POD policy, documents source-facing member signatures including `ContainsPoint(int y, int x)`, `ClampWithin(int leftLimit, int topLimit, int rightLimit, int bottomLimit)`, `InsetByQuarter`, and corrected `OutsetByHalf`, separates cdecl file helpers such as `InitRectBounds`, `RectArea`, `PointInRect`, and anchor transforms from class methods, and records fresh PE/Capstone range, padding, branch-count, constant, and raw no-xref evidence while leaving exact historical helper spellings and a few return contracts below final-audit confidence.
```

If the supervisor accepts the support metadata update for [UID:00022H], replace its `by-memory/-coverage-report.md` row with the row already supplied by the accepted `00022H` report:

```text
    - [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) 0x004b7af0-0x004b7c21 | raw-function-cluster | RectBoundsQuarterScaleHelpers : reconstructable : 89% : strong : B001 source-quality PE scan reconfirms exact raw helper bodies and padding at 0x004b7ae8-0x004b7af0, 0x004b7b88-0x004b7b90, and 0x004b7c21-0x004b7c30; first helper 0x004b7af0-0x004b7b88 is RectBounds::InsetByQuarter with 0.25f scale and output-pointer return, second helper 0x004b7b90-0x004b7c21 is corrected to RectBounds::OutsetByHalf using 0.5f scale, no VA/RVA pointer hits or direct branch/call routes to starts/interiors were found, retained unused source-authored class-method code is the best liveness explanation, owner/emitter should be RectBounds class 0000BU, and first-draft C++ is ready.
```

If the supervisor accepts the [UID:00015T] owner/source-declaration correction, replace its `by-memory/-coverage-report.md` row with:

```text
    - [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) 0x004b7ca0-0x004b7cb6 | file-level geometry helper | RectArea : reconstructable : 84% : strong : B001 2026-06-19 RectBounds class source-quality pass reframes this as cdecl/file-level `int RectArea(const RectBounds *bounds)` under [UID:0000N2][RectBounds](by-file/RectBounds.md), not a true `RectBounds` thiscall method; live docs and fresh PE evidence confirm the exact 0x16-byte signed `(right-left)*(bottom-top)` helper, four direct callers, no callees, stack pointer argument, plain `ret`, and cross-reference to the RectBounds class/layout while final helper-body C++ remains blank pending a support callback.
```

No replacement row is needed for `by-memory/-coverage-report.md` solely because this target is `by-class`; the two memory rows above apply only if the implementation callback includes those support metadata/prose changes.

## Validation Commands Needed After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000BU-RectBounds-class-source-quality-removed.md](0000BU-RectBounds-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If supervisor-owned coverage rows are applied, also run the relevant coverage validator after the supervisor edit. B001 must not edit `by-memory/-coverage-report.md` directly under the current ban.

Expected generated side effect after implementation: `auto-generated/NexusTK/ui/core/RectBounds.cpp` should no longer have an empty marker for `0000BU`; it should contain the `struct RectBounds` declaration and `[[CHILDREN]]` expansion point, with child entries still empty unless their own C++ bodies are accepted.

## Implementation Instructions For Supervisor Callback

When the report is accepted, send B001 an implementation callback with these exact steps:

1. Edit `by-class/RectBounds.md`.
   - Set `COMPLETION:90`, `CONFIDENCE:88`.
   - Keep `CANONICAL_OWNER:0000N2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N2`.
   - Insert the declaration-level `struct RectBounds` C++ block with `[[CHILDREN]]`.
   - Update status, purpose, method table, layout, evidence, source-placement, open-question, generated-output, and changes sections with all report facts above.

2. Edit support docs only if accepted in the callback:
   - `by-file/RectBounds.md`
   - `by-type/by-struct/RectBoundsLayout.md`
   - `by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md`
   - `by-memory/0x004b7ca0-0x004b7cb6.RectArea.md`
   - `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
   - `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`
   - `by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md`
   - `by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md`
   - `by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md`
   - `by-memory/0x004b7910-0x004b795e.RectBoundsInset.md`

3. Do not edit `by-memory/-coverage-report.md`; return the exact pending rows above.

4. Run the validators listed above and report exact command results.

5. Report generated/project-level side effects, especially changes to `auto-generated/NexusTK/ui/core/RectBounds.cpp` and `auto-generated/-ag-class-coverage.md`.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0000BU-RectBounds-class-source-quality.md`
- Modified: none
- Target/support by-* docs edited: none
- `by-memory/-coverage-report.md` edited: no

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000BU-RectBounds-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0000BU"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000BU-RectBounds-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0000BU-RectBounds-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000BU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
