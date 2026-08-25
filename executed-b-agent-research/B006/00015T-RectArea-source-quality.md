** TARGET-REPORT-UID:00015T **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015T RectArea Source-Quality / Heuristic Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00015T] as a `RectBounds` class-owned signed-area method and populate first-draft C++ after the `RectBounds` declaration shell is staged.
- Final disposition: no split, no owner change, no emitter change.
- Required action after supervisor review: update the target/support docs with the source-facing name/signature, signed arithmetic behavior, stale no-code policy correction, and first-draft C++ recommendation below.
- Confidence: strong for behavior, range, owner route, and C++ readiness; source spelling is inferred, not original-symbol proven.

## Target

- Target UID: `00015T`
- Target path: `source-3/project-documentation/by-memory/0x004b7ca0-0x004b7cb6.RectArea.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/00015T-RectArea-source-quality.md`
- Current target score: `84/90`
- Current owner/emitter: `CANONICAL_OWNER:0000BU`, `EMITTER_UIDS:0000BU`
- Current route: `00015T -> 0000BU RectBounds -> 0000N2 RectBounds.cpp -> auto-generated/NexusTK/ui/core/RectBounds.cpp`
- Current code state: `RECONSTRUCTION_CPP CODE` is blank.

## Evidence Checked

- Target page [UID:00015T]:
  - Documents `sub_4B7CA0` as a `0x16`-byte helper at `0x004b7ca0-0x004b7cb6`.
  - Prior live IDA evidence says the function returns `(right - left) * (bottom - top)` over [UID:0001VP] `RectBoundsLayout`.
  - Prior live IDA evidence gives exactly four xrefs/callers: `0x004580de`, `0x004581da`, `0x0045833d`, and `0x004b621a`.
  - Prior live IDA evidence reports no callees and `0xcc` padding before/after the helper.
- [UID:0000BU] `by-class/RectBounds.md`:
  - Documents `RectBounds` as a POD-style four-int rectangle value object with class-style and free-helper geometry methods.
  - Keeps [UID:00015T] visible as a separate exact helper while final declaration ownership remains unresolved.
- [UID:0000N2] `by-file/RectBounds.md`:
  - Routes the family to `NexusTK/ui/core/RectBounds.cpp`.
  - Records [UID:00015T] as a signed width-times-height helper.
  - Notes active generated output does not materialize `RectArea` despite IDA-confirmed callers.
- [UID:0001VP] `by-type/by-struct/RectBoundsLayout.md`:
  - Confirms the field order `left`, `top`, `right`, `bottom`.
  - Confirms `RectArea` uses `right - left` and `bottom - top` without an empty/invalid check.
- [UID:00015S] `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`:
  - Places [UID:00015T] inside the shared point/rectangle helper island.
  - 2026-06-15 notes reconfirm broad geometry helper fan-in and four narrow `RectArea` refs.
- [UID:00015Q], [UID:00015R], and [UID:00022G]:
  - Confirm neighboring `RectBounds` class-style methods and related geometry helpers use the same four-int layout and no-callee helper style.
- Caller evidence pages:
  - [UID:0000XY] `EPFTileContext` documents calls from `sub_457FF0` and `sub_458260`, both using `0x004b7ca0` for buffer sizing in decimation/allocation paths.
  - [UID:0002HT] `FontImageLibDecodeGlyphBitmap` documents the `0x004b621a` call, where the glyph rectangle area sizes the shared decoded-glyph scratch buffer.
- Generated reports/output:
  - `auto-generated/-ag-memory-coverage.md` shows [UID:00015T] currently emits through `0000BU` to `auto-generated/NexusTK/ui/core/RectBounds.cpp`.
  - `auto-generated/NexusTK/ui/core/RectBounds.cpp` currently contains only an empty emitter marker for [UID:00015T].
  - `by-memory/-coverage-report.md` still has the target at `84%` and says final C++ remains blank.
- Existing B-agent executed report search:
  - No prior executed B001/B002/B006 research report for `00015T`, `RectArea`, or `0x004b7ca0` was found.

No fresh live IDA/MCP facts were collected in this session. The documented MCP endpoint `http://127.0.0.1:13337/mcp` did not accept a `tools/list` request (`Unable to connect to the remote server`). This report therefore relies on current documentation and the prior live IDA facts already written into those docs.

## Heuristic / Inference Reanalysis And Validation

### Source-facing name

Best recommendation:

```cpp
int RectBounds::Area() const;
```

Reasoning:

- The body reads only the four fields of one rectangle and has no side effects.
- The current owner/emitter already treats it as class-owned by [UID:0000BU] `RectBounds`.
- The caller contexts pass an existing rectangle object/record and use the scalar result as a buffer-size or extent product.
- The surrounding class methods use short descriptive names such as `Offset`, `UnionWith`, and `ClampWithin`; `Area` fits that style better than a generated `sub_` name or a redundant `RectArea` member name.

Accepted alternate:

- `int RectBounds::GetArea() const` is plausible if later source-style review finds the original code favored `Get*` for queries. No current evidence requires that prefix.

Rejected alternatives:

- `sub_4B7CA0`: raw IDA name only, not source quality.
- `RectBounds::RectArea`: redundant class-name repetition; useful as a documentation title but weak as a member name.
- `int RectArea(const RectBounds* rect)`: plausible as a file-local helper by address locality, but weaker than the current class owner/emitter and thiscall/member-style evidence implied by the docs.
- `GetRectBoundsLayout` or generated layout-wrapper spellings: generated-output pollution, not source code.
- `AreaAbs`, `GetClampedArea`, `GetPositiveArea`: contradicted by the lack of empty/invalid checks.

### Signature and constness

Best source signature:

```cpp
int RectBounds::Area() const
```

The `const` qualifier is source-level inference, not binary proof. It is recommended because the function reads `left`, `top`, `right`, and `bottom` only. If a later project-wide style pass avoids const member declarations for these POD helpers, `int RectBounds::Area()` is binary-compatible with the same body, but `const` is the better first-draft source spelling.

### RectBounds field semantics

Use the source-facing type `RectBounds`, not a generated `RectBoundsLayout` wrapper, in formal C++.

Recommended field names remain:

```cpp
int left;
int top;
int right;
int bottom;
```

Semantics:

- `left` and `top` are inclusive low edges.
- `right` and `bottom` are exclusive high edges for hit-testing in the adjacent helpers.
- Width is `right - left`.
- Height is `bottom - top`.
- Empty/invalid is tested elsewhere as `right <= left || bottom <= top`; [UID:00015T] itself does not call that predicate or duplicate that guard.

### Area arithmetic and overflow behavior

The helper computes a signed 32-bit extent product:

```text
(right - left) * (bottom - top)
```

Behavioral conclusions:

- No empty check.
- No clamp to zero.
- No absolute value.
- No unsigned conversion.
- No 64-bit widening.
- No explicit overflow check.

Negative and invalid rectangle consequences:

- If one axis is inverted and the other is not, the result can be negative.
- If both axes are inverted, the product can be positive even though the rectangle is invalid by the class predicate.
- If either subtraction or multiplication exceeds signed 32-bit range, the original machine code's visible behavior is the low 32-bit result produced by the compiled arithmetic. Source reconstruction should still use the plain `int` expression because that is the most plausible original C++ and should compile to the observed short helper in the expected MSVC-era build.
- Callers that use the result for allocation sizing are expected to pass valid small rectangles. Do not add defensive allocation or bounds checks inside [UID:00015T]; that would change behavior and belongs at callers if later evidence proves it existed.

Rejected arithmetic rewrites:

- `return max(0, width) * max(0, height);`
- `return abs(width * height);`
- `return static_cast<size_t>(width) * height;`
- `return static_cast<long long>(width) * height;`
- `if (IsEmptyOrInvalid()) return 0;`

### Owner, emitter, and source-file route

Keep the current route:

```text
00015T -> 0000BU RectBounds -> 0000N2 RectBounds.cpp -> NexusTK/ui/core/RectBounds.cpp
```

Why [UID:0000BU] class ownership is stronger than file-only ownership:

- The function operates on one `RectBounds` record and returns a property of that record.
- The target page already classifies it as a class/helper method.
- [UID:00015R] `RectBoundsInset` is similarly separated from broader helper pages and class-owned.
- The class parent and file parent both clear the support gate.

Why [UID:0000N2] file ownership remains part of the route:

- The source file groups class methods and free helpers for point/rectangle geometry.
- The proposed project tree places `RectBounds.cpp` under `ui/core/`.
- The broad fanout rules out feature-owned placement in EPFTileContext, FontImageLib, Region, map, or UI dialogs.

Rejected owner alternatives:

- [UID:0000XY] `EPFTileContext`: rejected because it only uses `Area()` for allocation sizing.
- [UID:00005B] `FontImageLib`: rejected because it only uses `Area()` for glyph scratch sizing.
- [UID:0000N3] `Region`: rejected because `Region` consumes lower-level rectangle primitives but does not own this value-object helper.
- A new `Geometry.cpp` file: plausible long-term if the whole RectBounds file is moved to a generic utility folder, but not needed for this target and weaker than the existing `RectBounds.cpp` route.

### Stale no-code / generated-name issues

The target's current status text says final C++ is blank because the exact original declaration/name is below an old `95/95` code gate. That is stale under the current `by-structure.md` code-entry rule.

Current eligibility:

- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000BU`
- Generated route reaches `auto-generated/NexusTK/ui/core/RectBounds.cpp`
- `(84 + 90) / 2 = 87`, which is above the current `>85` gate.

The remaining blocker is not target behavior. The practical staging blocker is that `RectBounds` needs a declaration shell before emitting out-of-line method bodies. Once the class shell is present, [UID:00015T] should receive first-draft C++.

Generated names to retire or downgrade:

- `sub_4B7CA0` should remain only in evidence notes.
- Repeated `RectBoundsLayout` wrappers should not appear in final source.
- Empty emitter marker for [UID:00015T] should be replaced by an actual method body after implementation approval.

## First-Draft C++ Recommendation

Formal target C++ should be populated after adding or confirming a `RectBounds` declaration shell in [UID:0000BU].

Recommended by-memory body for [UID:00015T]:

```cpp
int RectBounds::Area() const
{
    return (right - left) * (bottom - top);
}
```

Recommended supporting class declaration shape:

```cpp
struct RectBounds {
    int left;
    int top;
    int right;
    int bottom;

    int Area() const;
};

[[CHILDREN]]
```

The broader class shell can include declarations for the other documented `RectBounds` methods when the supervisor accepts a larger implementation checklist. The target only requires the `Area()` declaration and the four fields to make this first-draft method coherent.

## Recommended Exact Doc Changes

Recommended target metadata for `by-memory/0x004b7ca0-0x004b7cb6.RectArea.md`:

```text
COMPLETION: 86
CONFIDENCE: 90
CANONICAL_OWNER: 0000BU
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000BU
```

Score rationale:

- Completion should rise from `84` to `86` because this report resolves the source-facing name/signature, stale code-gate issue, signed arithmetic assumptions, generated-name rejection, and first-draft C++ shape.
- Confidence should stay at `90` because behavior and routing are already strong, but no fresh MCP was available and the exact original spelling `Area` versus `GetArea` remains inferred.

Recommended target body edits after implementation approval:

- Replace the stale line about the `95/95` reconstruction-code gate with the current combined-score/emitter gate conclusion.
- State the source-facing declaration recommendation: `int RectBounds::Area() const`.
- Keep `sub_4B7CA0` as an IDA/raw alias only.
- Add the signed arithmetic note: no empty check, no clamp, no unsigned/64-bit widening, no overflow guard.
- Add the first-draft C++ block shown above.
- Preserve the existing boundary, caller, callee, and padding evidence.

Recommended [UID:0000BU] `RectBounds` class page changes after implementation approval:

- Add or refine a declaration shell for `RectBounds` with the four `int` fields and an `Area()` method declaration.
- Add [UID:00015T] to the method table as `Area` / `RectBounds::Area() const`.
- Suggested score if the declaration shell is staged: `COMPLETION:89`, `CONFIDENCE:86`.
- If no class shell is staged, keep the current `88/85` score.

Recommended [UID:0000N2] `RectBounds` file page changes after implementation approval:

- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/"`.
- Update the `RectArea` row to call it `RectBounds::Area()` while noting that the file still groups member-style and free geometry helpers.
- Keep `COMPLETION:90`, `CONFIDENCE:85`; the remaining `ui/core` versus `util` folder question still caps file confidence.

Recommended [UID:0001VP] `RectBoundsLayout` type page changes after implementation approval:

- Keep the field names `left`, `top`, `right`, `bottom`.
- Add a source-quality caveat that `RectBoundsLayout` is a documentation layout name and final source should prefer the `RectBounds` class/struct declaration rather than emitting duplicate generated layout wrappers.
- No score change required.

## Split / Merge Needs

No split is recommended.

The range is already an exact single function with padding before and after. It should remain a dedicated exact by-memory page because it has direct callers and first-draft C++ eligibility. It should not be merged back into [UID:00015S] `RectGeometryHelpers`; the aggregate can continue to list it as a covered child/helper row.

## Open Questions

- Exact original source spelling: `Area` is the best current recommendation; `GetArea` remains possible.
- Exact original constness: `const` is strongly inferred from read-only behavior but not binary-provable.
- Final folder at project level: `ui/core/RectBounds.cpp` remains active; a future broader source-tree pass could move the whole geometry primitive family to a utility folder, but this does not affect [UID:00015T]'s direct owner/emitter.
- Fresh live IDA validation was unavailable in this session.

None of these open questions block first-draft C++ for the target because the behavior, boundary, owner route, and generated output route are already strong and documented.

## Validator Needs After Implementation Callback

If the supervisor authorizes implementation edits, validate the touched docs and regenerated output in this order:

> Executable block R001 was removed from this report and preserved verbatim in [00015T-RectArea-source-quality-removed.md](00015T-RectArea-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Manual generated-file checks after validation:

- Confirm `source-3/project-documentation/auto-generated/NexusTK/ui/core/RectBounds.cpp` contains a usable `RectBounds` declaration before `RectBounds::Area()`.
- Confirm [UID:00015T] no longer appears as an empty emitter marker.
- Confirm no `RectBoundsLayout` duplicate wrapper or `sub_4B7CA0` source name appears in final emitted C++.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during this B-agent report. If implementation is later authorized, replace the current [UID:00015T] row with:

```text
    - [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) 0x004b7ca0-0x004b7cb6 | class/helper method | RectBounds::Area : reconstructable : 86% : strong : B006 source-quality report resolves the helper as a no-callee RectBounds signed area method, recommends signature `int RectBounds::Area() const`, preserves class owner/emitter [UID:0000BU] routed through RectBounds.cpp, records signed 32-bit width-times-height behavior with no empty or overflow checks, rejects generated `sub_4B7CA0`/layout-wrapper spellings and free-helper ownership as weaker, and recommends first-draft C++ once the RectBounds declaration shell is staged.
```

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/00015T-RectArea-source-quality.md`
- Modified: none outside the B006 research directory.
- Preserved: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/00011T-FontStyleCore-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00015T-RectArea-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00015T"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015T-RectArea-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/00015T-RectArea-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
