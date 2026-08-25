** TARGET-REPORT-UID:0001GR **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001GR ScrollNewGroupPanePartRect Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:0001GR] `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md` as `ScrollNewGroupPane::GetPartRect(ScrollNewGroupPart part, RectBounds *outRect)`, keep owner/emitter [UID:0000CL] `ScrollNewGroupPane`, and keep source route through [UID:0000JS] `Group`.
- Final disposition: the range is source-authored, reconstructable class geometry logic. Formal first-draft C++ is ready for supervisor implementation, with target-specific rectangle math rather than copying the FittingRoom sibling wholesale.
- Proposed score after implementation: `COMPLETION:89`, `CONFIDENCE:91`. Completion rises because the pass resolves exact part cases, constants, fields, helper aliases, and a formal C++ body. Confidence stays below final-audit because original symbol spellings remain source-facing aliases and the ScrollNewGroupPane layout is still documented through class/sibling pages rather than a dedicated exact layout page.
- Required action after supervisor acceptance: edit only the target/support by-* docs under lease, populate the target C++ block with the formal body below, sync the target evidence/score/item summary, add a small support note to [UID:0000CL] and the raw-helper sibling if needed, run scoped validators, and let generated reports refresh. Do not hand-edit generated reports, validator state/cache, IDA DB, project-level files, or `-coverage-report.md`.

## Target

- Target UID: `0001GR`
- Target path: `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md`
- Assignment id: `B005-report-0001GR-scroll-new-group-pane-part-rect-20260625`
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, `EMITTER_POSITION_OPTIONAL:60`, blank formal C++.
- Current generated tracker state is stale: `auto-generated/-ag-research-tracker.md` and generated coverage rows still render older `76/86` and blank-code state. Treat those as validator refresh outputs, not manual edit targets.

## Supervisor Active Recheck

The supervisor explicitly assigned [UID:0001GR]. I did not choose a new target, did not spawn subagents, and did not edit target/support by-* docs, generated reports, project-level files, validator state/cache, IDA DB, or any `-coverage-report.md`. IDA MCP was mandatory and was available.

Read-only MCP availability during this pass:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Active database/session: `80de0a67`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Input path reported by server health: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Module: `NexusTK.exe`, imagebase `0x400000`.
- `server_health`: `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

## Current Target State

The existing page is directionally correct: it already identifies the range as `ScrollNewGroupPane::GetPartRect`, gives owner/emitter [UID:0000CL], records sibling call sites, records the `dword_624144` constant-table dependency, and keeps the range reconstructable. The page is still blocked from source-quality implementation by:

- no formal C++ body even though behavior is now exact enough;
- stale generated lower score rows;
- source-facing field/helper names not collected in one place;
- insufficient warning that this target's horizontal endcap rectangles collapse to edge lines, unlike the FittingRoom first draft that models fixed-width endcaps;
- no explicit `Point` axis-order note, even though project geometry helpers use `y, x` argument order while `RectBounds` fields remain `left, top, right, bottom`.

These are implementation tasks, not future research blockers.

## Inference Research Guidance Check

Generated and historical names were treated as leads, not authority. The source-facing names recommended here are behavior-grounded aliases backed by current IDA and existing high-confidence support pages:

- `ScrollNewGroupPane::GetPartRect` for `0x00561740`.
- `ScrollNewGroupPart` enum values `Leading`, `PageBeforeThumb`, `Thumb`, `PageAfterThumb`, `Trailing`, plus `NoPart` sentinel for state fields.
- `m_scrollSkinIndex` at `+0xf8`.
- `m_thumbDragActive` at `+0xfb`.
- `m_orientation` at `+0xfc`.
- `m_scrollPosition` at `+0xfe`.
- `m_scrollRange` at `+0x100`.
- `m_scrollEnabled` at `+0x102`.
- `m_highlightPart` at `+0x103`.
- `m_activePart` at `+0x104`.
- `m_thumbDragOffset` at `+0x108`.
- `EventMan::GetCursorPosition` for `0x004a9090` through `dword_67A754`.
- `Pane::GetScreenOffset` for `0x005447c0`.
- `InitRectBounds` / direct zero-rectangle assignment for `0x004b7c50`.

Rejected alternatives:

- Route to `ScrollBar.cpp`: rejected for this method body. The constant table is shared scrollbar support, but the receiver, callers, vtables, and callback route are `ScrollNewGroupPane` under Group UI.
- Merge into `ScrollCollectionPane`: rejected. `ScrollCollectionPane` is a sibling pattern and useful layout evidence, not this object's owner.
- Keep C++ blank: rejected. The exact rectangle math, caller roles, field semantics, and support route are now sufficient for a first-draft target method body.
- Copy the FittingRoom C++ verbatim: rejected. This target has different endcap rectangles and only applies drag override on the vertical branch.

## Evidence Checked

IDA MCP and local documentation evidence used:

- `server_health`, `lookup_funcs`, `xref_query`, `callees`, `analyze_batch`, `decompile`, `disasm`, `get_bytes`, and `get_int`.
- Current target page and support pages [UID:0000CL], [UID:0000JS], [UID:0001GP], [UID:0001GQ], [UID:0001GS], [UID:0001YR], [UID:0002OS], [UID:000090], [UID:0003CQ], [UID:0000NF], [UID:0001VZ], [UID:0001VP], and RectBounds helper pages.
- Accepted sibling geometry page [UID:0002D7] was used for naming pattern only; target math comes from live IDA.
- `tools/int_convert_readme.md` and `tools/int_convert.py`; decimal values used in the report were checked where relevant: `0x287 = 647`, `0x26 = 38`, `0xf8 = 248`, `0xfb = 251`, `0xfc = 252`, `0xfe = 254`, `0x100 = 256`, `0x102 = 258`, `0x103 = 259`, `0x104 = 260`, `0x108 = 264`.

Unavailable/failed checks:

- None blocking. The first MCP call used `address` instead of the bridge's required `addr`; it failed with a schema error and was rerun successfully. `disasm` uses `max_instructions` rather than `count`; after reading the tool schema, the target disassembly was rerun successfully.

## IDA MCP Facts

Live IDA MCP on database `80de0a67`:

- `lookup_funcs 0x00561740` -> `sub_561740`, size `0x287`, exclusive end `0x005619c7`.
- Neighboring boundary checks:
  - `0x0056173d-0x00561740`: three `0xcc` bytes after [UID:0001GQ].
  - Function prologue at `0x00561740`: `55 8b ec 83 ec 20`.
  - Function tail returns with `retn 8` at `0x005619c4`, exclusive end `0x005619c7`.
  - `0x005619c7-0x005619d0`: nine `0xcc` bytes before raw helper island [UID:0001GS].
- Code xrefs to `0x00561740`: thirteen total:
  - `0x560b77`, `0x560c12`, `0x560c2a`, `0x560c49` in `sub_560B00` / `OnMouseEvent`.
  - `0x561396` in `sub_560D40` / `OnPaint`.
  - Raw/no-function helper refs `0x5619fc`, `0x561a18`, `0x561a71`, `0x561a89`, `0x561aa8`, `0x561d86`.
  - `0x561b9a` in `sub_561B00`.
  - `0x561be5` in `sub_561BC0`.
- `callees 0x00561740`: only `0x004a9090`, `0x005447c0`, and `0x004b7c50`.
- `analyze_batch 0x00561740`: IDA prototype `int __thiscall(int this, char, int *)`, modeled caller count 4 plus raw xrefs above, callee count 3, no strings, 39 basic blocks, 243 instructions.
- `get_int` for `0x00624138-0x00624164`: `{13,13,13,38,38,38,13,12,12,13,10,10}`. The target vertical path indexes `dword_624144`, so the in-use fixed vertical thumb/endcap extent table at `0x00624144-0x00624150` is `{38,38,38}` for indices `0..2`.

Target disassembly facts:

- `0x561753`: calls `sub_4A9090` through `dword_67A754`.
- `0x56175e`: calls `sub_5447C0`.
- `0x561771`: returns early on screen-offset sentinel `(-1000, -1000)` before writing the output rectangle.
- `0x56177d`: branches on `byte ptr [edi+0fch]` for orientation.
- Horizontal branch:
  - `0x561793-0x5617ad`: fixed extent is `bounds.bottom - bounds.top`.
  - Part `0`: `out = bounds; out.right = out.left`.
  - Part `4`: `out = bounds; out.left = out.right`.
  - Enabled/range path computes `thumbLeft = bounds.left + m_scrollPosition * (bounds.right - bounds.left - fixedExtent) / m_scrollRange`.
  - Disabled/zero-range part `2`: `out = bounds; out.left += fixedExtent; out.right -= fixedExtent`.
  - Disabled/zero-range parts `1` and `3`: call `sub_4B7C50(out, 0, 0, 0, 0)`.
- Vertical branch:
  - `0x561894-0x56189b`: fixed extent is `dword_624144[*(int16 *)(this+0xf8)]`.
  - Part `0`: `out = bounds; out.bottom = out.top`.
  - Part `4`: `out = bounds; out.top = out.bottom`.
  - Enabled/range non-drag path computes `thumbTop = bounds.top + m_scrollPosition * (bounds.bottom - bounds.top - fixedExtent) / m_scrollRange`.
  - Enabled/range drag path at `0x56192d-0x56193f`: computes `thumbTop = bounds.top + localCursorY - m_thumbDragOffset.y` and clamps to `[bounds.top, bounds.bottom - fixedExtent]` in project point-axis convention.
  - Disabled/zero-range part `2`: `out = bounds; out.top += fixedExtent; out.bottom -= fixedExtent`.
  - Disabled/zero-range parts `1` and `3`: call `sub_4B7C50(out, 0, 0, 0, 0)`.

Caller/support decompilation facts:

- Constructor `0x00560900` installs vtables, stores orientation at `+0xfc`, clears the scroll position/range dword at `+0xfe`, writes `0x10000` at `+0xf8`, writes word `-255` at `+0x102` so enabled is `1` and highlight is `0xff`, writes active part `+0x104 = 0xff`, and clears the point pair at `+0x108`.
- `OnMouseEvent` `0x00560b00` calls `GetPartRect` for invalidation and thumb setup. At `0x560c49-0x560c63`, when the thumb is pressed, it calls `GetPartRect(part 2, &thumbRect)` and stores drag offset through `sub_4B7C30((PointPair *)(this+0x108), mouseY - thumbRect.top, mouseX - thumbRect.left)` in the project's `y, x` point convention.
- Active update `0x00561b00` uses `+0x104` as active part, `+0x103` as highlighted/invalidated part, calls `HitTestPart`, calls `GetPartRect`, and invalidates the prior highlighted part.
- Cursor-to-scroll update `0x00561bc0` calls `GetPartRect(part 2, &thumbRect)`, uses the same `+0x108/+0x10c` drag-offset pair, clamps to the relevant axis, and calls `NewGroupPane::SetScrollPosition` at `0x0056df00`.
- `OnPaint` `0x00560d40` duplicates the same orientation/range/drag math for drawing and calls `GetPartRect(part 2, ...)` at `0x561396`.

## Behavior

`ScrollNewGroupPane::GetPartRect` computes the rectangle for one scrollbar part and writes it through `outRect`. IDA returns an incidental `int`; source should be `void`.

The helper first reads the current cursor point and the pane's screen offset. If `GetScreenOffset` returns sentinel `(-1000, -1000)`, the function returns before writing `outRect`. Otherwise it converts the cursor into pane-local coordinates. This local cursor matters only for the vertical drag override branch in this target.

Part IDs:

| Value | Recommended enum | Meaning |
| --- | --- | --- |
| `0` | `kScrollNewGroupPartLeading` | Leading edge/end line. |
| `1` | `kScrollNewGroupPartPageBeforeThumb` | Track/page region before the thumb. |
| `2` | `kScrollNewGroupPartThumb` | Thumb rectangle. |
| `3` | `kScrollNewGroupPartPageAfterThumb` | Track/page region after the thumb. |
| `4` | `kScrollNewGroupPartTrailing` | Trailing edge/end line. |
| `0xff` / `-1` | `kScrollNewGroupPartNone` | State sentinel in `+0x103/+0x104`, not an output rectangle case. |

Key target-specific geometry details:

- Horizontal mode uses `bounds.bottom - bounds.top` as the fixed thumb extent, but part `0` and part `4` collapse to zero-width edge rectangles. Do not model them as fixed-width arrow buttons.
- Vertical mode uses `kScrollPanePartExtentBySkin[m_scrollSkinIndex]` for the fixed extent, but part `0` and part `4` collapse to zero-height edge rectangles.
- Page-before and page-after rectangles are zeroed when the pane is disabled or range is not positive.
- Disabled/zero-range thumb returns the middle track rectangle inset by the fixed extent on the scroll axis.
- Vertical drag mode uses the first point coordinate in the project `Point`/`PointPair` convention, matching existing docs where point/hit-test helpers are `y, x` while `RectBounds` remains `left, top, right, bottom`.

## Owner, Emitter, And Source Placement

Keep:

- `CANONICAL_OWNER:0000CL`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000CL`
- `EMITTER_POSITION_OPTIONAL:60`
- Source route through [UID:0000JS] `Group`, emitted to `auto-generated/NexusTK/social/Group.cpp`.

Rationale:

- The receiver fields, vtable slot users, constructor, mouse, paint, active update, and cursor-to-scroll callback all belong to `ScrollNewGroupPane`.
- [UID:000090] `NewGroupPane` constructs/owns this child and receives scroll-position updates at `0x0056df00`.
- The shared constant table is support evidence from [UID:0003CQ]/[UID:0000NF], not source ownership for this method.
- `ScrollCollectionPane` and FittingRoom scroll panes are sibling patterns only.

## Formal C++ Recommendation

The target page should populate its `RECONSTRUCTION_CPP` block with this body. Names are source-facing aliases and should be harmonized later only if a broader scrollbar naming pass standardizes them.

```cpp
void ScrollNewGroupPane::GetPartRect(ScrollNewGroupPart part, RectBounds *outRect)
{
    Point cursor;
    Point origin;
    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    cursor.y -= origin.y;
    cursor.x -= origin.x;

    const RectBounds bounds = m_bounds;
    if (m_orientation != 0) {
        const int thumbExtent = bounds.bottom - bounds.top;

        switch (part) {
        case kScrollNewGroupPartLeading:
            *outRect = bounds;
            outRect->right = outRect->left;
            return;

        case kScrollNewGroupPartTrailing:
            *outRect = bounds;
            outRect->left = outRect->right;
            return;

        default:
            break;
        }

        if (m_scrollEnabled && m_scrollRange > 0) {
            const int thumbLeft =
                bounds.left
                + (m_scrollPosition * (bounds.right - bounds.left - thumbExtent)) / m_scrollRange;
            const int thumbRight = thumbLeft + thumbExtent;

            *outRect = bounds;
            switch (part) {
            case kScrollNewGroupPartThumb:
                outRect->left = thumbLeft;
                outRect->right = thumbRight;
                return;

            case kScrollNewGroupPartPageBeforeThumb:
                outRect->right = thumbLeft;
                return;

            case kScrollNewGroupPartPageAfterThumb:
                outRect->left = thumbRight;
                return;

            default:
                return;
            }
        }

        if (part == kScrollNewGroupPartThumb) {
            *outRect = bounds;
            outRect->left += thumbExtent;
            outRect->right -= thumbExtent;
            return;
        }

        if (part == kScrollNewGroupPartPageBeforeThumb || part == kScrollNewGroupPartPageAfterThumb) {
            outRect->left = 0;
            outRect->top = 0;
            outRect->right = 0;
            outRect->bottom = 0;
        }
        return;
    }

    const int thumbExtent = kScrollPanePartExtentBySkin[m_scrollSkinIndex];

    switch (part) {
    case kScrollNewGroupPartLeading:
        *outRect = bounds;
        outRect->bottom = outRect->top;
        return;

    case kScrollNewGroupPartTrailing:
        *outRect = bounds;
        outRect->top = outRect->bottom;
        return;

    default:
        break;
    }

    if (m_scrollEnabled && m_scrollRange > 0) {
        const int thumbLimit = bounds.bottom - thumbExtent;
        int thumbTop;

        if (m_thumbDragActive) {
            thumbTop = bounds.top + cursor.y - m_thumbDragOffset.y;
            if (thumbTop < bounds.top) {
                thumbTop = bounds.top;
            }
            if (thumbTop > thumbLimit) {
                thumbTop = thumbLimit;
            }
        } else {
            thumbTop =
                bounds.top
                + (m_scrollPosition * (thumbLimit - bounds.top)) / m_scrollRange;
        }

        const int thumbBottom = thumbTop + thumbExtent;

        *outRect = bounds;
        switch (part) {
        case kScrollNewGroupPartThumb:
            outRect->top = thumbTop;
            outRect->bottom = thumbBottom;
            return;

        case kScrollNewGroupPartPageBeforeThumb:
            outRect->bottom = thumbTop;
            return;

        case kScrollNewGroupPartPageAfterThumb:
            outRect->top = thumbBottom;
            return;

        default:
            return;
        }
    }

    if (part == kScrollNewGroupPartThumb) {
        *outRect = bounds;
        outRect->top += thumbExtent;
        outRect->bottom -= thumbExtent;
        return;
    }

    if (part == kScrollNewGroupPartPageBeforeThumb || part == kScrollNewGroupPartPageAfterThumb) {
        outRect->left = 0;
        outRect->top = 0;
        outRect->right = 0;
        outRect->bottom = 0;
    }
}
```

Notes for implementation:

- `Point`/`PointPair` should preserve the project `y, x` field order if that is the active declaration. The code above names the vertical axis as `cursor.y` and `m_thumbDragOffset.y` to match the source-facing geometry convention.
- If the codebase currently exposes `InitRectBounds(outRect, 0, 0, 0, 0)`, direct zero assignment may be replaced with that exact helper call. Direct assignment is source-safe and avoids introducing an unresolved helper name into this target body.
- The target should not introduce `Width()`/`Height()` requirements unless those methods are already emitted in the active RectBounds declarations; the body uses explicit edge subtraction for local clarity.
- The constant alias should be shared with [UID:0003CQ]/[UID:0000NF]. Preferred source-facing name in this target is `kScrollPanePartExtentBySkin`.

## Support Sync Plan

After supervisor acceptance, make these scoped edits:

- Target [UID:0001GR]:
  - Raise score to `89/91`.
  - Populate the formal C++ block above.
  - Replace the item summary with a concise source-quality summary covering exact bounds, 13 xrefs, helper callees, field map, target-specific endcap math, vertical drag math, constant table, and first-draft C++.
  - Add/update behavior, field/helper alias, and IDA evidence sections.
  - Record that generated tracker/coverage rows are stale and validator-owned.
- [UID:0000CL] `ScrollNewGroupPane`:
  - Add one support note that `GetPartRect` now has first-draft C++ and uses the existing shared scroll-tail field names.
  - Preserve owner/emitter route through [UID:0000JS] `Group`.
- [UID:0001GS] raw/interaction sibling:
  - If touched under support scope, note that `+0x108` stores the thumb drag offset in project `y, x` point order and feeds `GetPartRect` / cursor-to-scroll math.
- [UID:0003CQ] / [UID:0000NF]:
  - No required score change. If support syncing constants, state that `0x00624144-0x00624150` is the `{38,38,38}` vertical fixed-extent slice used by `ScrollNewGroupPane`.

No split/range repair is needed. The target range is exact and padding before/after is confirmed.

## Score / Source-Quality Blocker Disposition

Resolved:

- Exact boundary: resolved by `lookup_funcs`, tail bytes, and padding.
- Caller roles: resolved by xrefs to mouse, paint, raw helper contexts, active update, and cursor-to-scroll update.
- Helper names: resolved to source-facing `GetCursorPosition`, `GetScreenOffset`, and zero-rectangle initialization/direct assignment.
- Field meanings: resolved for `+0xf8`, `+0xfb`, `+0xfc`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, `+0x104`, and `+0x108`.
- Constant meaning: resolved to shared scroll fixed-extent table slice `{38,38,38}` at `0x00624144-0x00624150`.
- Rectangle math: resolved for every valid part in horizontal/vertical enabled and disabled states.
- C++ readiness: resolved; formal first-draft body is ready.

Remaining caveats that should stay as ordinary confidence caps, not blockers:

- Exact original symbol spellings are not known.
- `kScrollPanePartExtentBySkin` may be harmonized by a future shared scrollbar naming pass.
- The class does not yet have a dedicated exact `ScrollNewGroupPaneLayout` struct page, but [UID:0000CL], [UID:0001GS], and sibling [UID:0001VZ] are enough for this implementation.

## Implementation Tracking Checklist

- [x] Lease [UID:0001GR] and any support docs selected by the supervisor before editing.
  - Proof: B005 leased `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md` and `by-class/ScrollNewGroupPane.md` immediately before editing. `python .\tools\leaser\leaser.py B005 lease ...` returned `Success` for both paths. After the edit/validator batch, `python .\tools\leaser\leaser.py B005 unlease ...` returned `Success` for both paths. A post-release read of `Agent-B005/current_leases.md` showed no active B005 leases; only old expired Supervisor leases remained.
- [x] Update [UID:0001GR] metadata to `COMPLETION:89`, `CONFIDENCE:91`; keep owner/emitter/position unchanged.
  - Proof: target header now has `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, and `EMITTER_POSITION_OPTIONAL:60`.
- [x] Populate [UID:0001GR] `RECONSTRUCTION_CPP` with the formal `ScrollNewGroupPane::GetPartRect` body above.
  - Proof: target formal `RECONSTRUCTION_CPP CODE:BEGIN/END` block now contains `void ScrollNewGroupPane::GetPartRect(ScrollNewGroupPart part, RectBounds *outRect)` with the accepted horizontal/vertical rectangle math, vertical drag override, zeroed page-area fallback, and inferred source-facing names from this report.
- [x] Update [UID:0001GR] Item Summary with the resolved boundary/xref/helper/field/math/C++ status.
  - Proof: target Item Summary now records source-quality part-rectangle status, exact boundary/padding evidence, thirteen xrefs, three callees, resolved field/part aliases, table values, target-specific endcap geometry, vertical drag override, and first-draft C++.
- [x] Add target evidence for MCP session `80de0a67`, 13 call/xref sites, three callees, padding, table values, and target disassembly branch facts.
  - Proof: target `IDA MCP Evidence`, `Caller And Support Evidence`, `Geometry Details`, and `Changes` sections now include current MCP availability on database `80de0a67`, exact boundary `0x00561740-0x005619c7`, three `cc` bytes before, nine `cc` bytes after, all thirteen xref addresses, callees `0x004a9090`, `0x005447c0`, `0x004b7c50`, table values `{13,13,13,38,38,38,13,12,12,13,10,10}`, in-use vertical slice `{38,38,38}`, and disassembly anchors for the orientation, proportional division, table lookup, drag clamp, zero-rect helper, and `retn 8`.
- [x] Add the field/helper alias table and note the project `Point` `y, x` convention versus `RectBounds left/top/right/bottom`.
  - Proof: target `Field And Helper Aliases` table now maps `+0x44`, `+0xf8`, `+0xfb`, `+0xfc`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, `+0x104`, `+0x108`, `0x004a9090`, `0x005447c0`, `0x004b7c50`, and `0x00624144-0x00624150`; target `Behavior` records `Point`/hit-test `y, x` separately from `RectBounds` `left, top, right, bottom`.
- [x] Add support note to [UID:0000CL] `ScrollNewGroupPane` that `GetPartRect` now has first-draft C++ and remains child position `60`.
  - Proof: `by-class/ScrollNewGroupPane.md` method inventory now states [UID:0001GR] carries first-draft C++ at emitter position `60`; the new `Scrollbar Part And Field Alias Notes` section reconciles `ScrollNewGroupPart`, scroll-tail field aliases, and point/rectangle axis conventions with the companion HitTestPart page.
- [x] Optionally add a support note to [UID:0001GS] for `m_thumbDragOffset` setup/use if the supervisor wants sibling sync in the same callback.
  - Proof/exclusion: optional raw sibling was not edited. Current [UID:0001GS] already documents `this + 0x108` as stored drag offset/anchor point, the raw helper `GetPartRect` call relationship, and the cursor-to-scroll update path. The required y/x convention and formal C++ readiness are now carried by the target and class support page, so no raw sibling edit or validator was needed.
- [x] Do not hand-edit generated reports, project-level files, validator cache/state, IDA DB, or any `-coverage-report.md`.
  - Proof: manual edits were limited to `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md`, `by-class/ScrollNewGroupPane.md`, and this Agent-B005 report checklist. Validator commands produced tool-owned side effects including `projected_stats_update` on `project-level/-auto-completion-stats.md`; no generated/project-level/coverage/validator/IDA files were manually edited.
- [x] Run scoped validators after by-* edits and let generated report refresh handle stale generated rows.
  - Proof: target validator first ran as command `000000002003` at `2026-06-26T00:31:49-04:00`, exit code `0`, `ok: 1`, but reported a `missing_ref_uid` warning for an unregistered constant-table UID reference. I corrected that one cross-reference to path-only text without editing validator state, then reran the target validator as command `000000002007` at `2026-06-26T00:32:19-04:00`, exit code `0`, `ok: 1`, no target warning in output. Class validator ran as command `000000002009` at `2026-06-26T00:32:28-04:00`, exit code `0`, `ok: 1`. Both final validator runs reported `generated_refresh: deferred`; `python .\tools\validator.py --queue-status` returned command `000000002013` at `2026-06-26T00:33:03-04:00` with `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`.

## Final Report Status

Implementation callback is complete for the accepted target/support scope. Changed files: `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md`, `by-class/ScrollNewGroupPane.md`, and this report checklist. The optional raw interaction sibling was explicitly not edited because its required relationship facts were already present and the accepted y/x convention is now documented in the target/class pages. No accepted checklist item remains unchecked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001GR-ScrollNewGroupPanePartRect-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001GR-ScrollNewGroupPanePartRect-source-quality.md","timestamp":"2026-06-26T00:35:57","uid":"0001GR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
