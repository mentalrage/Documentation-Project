** TARGET-REPORT-UID:0001GS **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# Agent-B008 rework report: [UID:0001GS] ScrollNewGroupPaneRawAndInteractionHelpers

Status: FINISHED_REPORT
Assignment: B008-report-0001GS-scroll-new-group-pane-raw-and-interaction-helpers-20260625
Target: `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md`
Pass type: same-report correction pass; report-only; no target/support `by-*` documentation was edited.

## Final recommendation

`0001GS` should be converted from a mixed source-method bucket into a reviewed non-emitting split index. The exact source-bearing children should be created as separate `by-memory` pages under [UID:0000CL] `ScrollNewGroupPane`, emitting through [UID:0000CL] into [UID:0000JS] `Group`.

The prior report's split/index direction and boundary repair remain correct. The failed part was C++ disposition. This rework resolves that failure: every proposed exact child is source-owned, reconstructable, and eligible for formal first-draft C++ after applying the same implementation-pass class support aliases listed below. No child remains blank due to deferred split staging or unresolved support layout/signature naming.

Recommended parent metadata after implementation:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE`: blank

Parent no-code proof:

The parent range is an audit/split index over five separate source methods plus alignment/padding. Emitting C++ from the aggregate would duplicate child method bodies and violate the `by-memory` rule that reconstruction code must belong to the page's own source unit. The exact children below are the reconstruction units.

## Supervisor rework issue resolved

This correction supersedes the prior deferral wording. Resolution in this report:

- The support-layout/signature route was investigated now using the current `0001GQ` and `0001GR` reports plus the current target MCP evidence.
- The support update required for [UID:0000CL] `ScrollNewGroupPane` is specified exactly.
- All five child pages receive exact formal `RECONSTRUCTION_CPP CODE` insertion text.
- There is no remaining no-code child in this target.

## Current IDA MCP evidence

MCP was available and responsive for this correction pass.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active session: `80de0a67`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- `server_health`: `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`

Current function lookup:

- `0x005619d0`: no IDA function.
- `0x00561a40`: no IDA function.
- `0x00561b00`: `sub_561B00`, size `0xc0`.
- `0x00561bc0`: `sub_561BC0`, size `0x18d`.
- `0x00561d50`: no IDA function.
- `0x00561db0`: successor `sub_561DB0`, size `0xa1`.
- `0x00561420`: sibling `sub_561420` / `HitTestPart`, size `0x31d`.
- `0x00561740`: sibling `sub_561740` / `GetPartRect`, size `0x287`.
- `0x0056df00`: `sub_56DF00`, the `NewGroupPane` scroll-position callback, size `0x38`.

Current xref facts:

- Raw starts `0x005619d0`, `0x00561a40`, and `0x00561d50` have zero incoming code xrefs.
- `0x00561b00` has three incoming refs: `0x00560c73`, `0x00560d18`, and raw callsite `0x00561ad2`.
- `0x00561bc0` has two incoming refs, both inside `sub_561B00`: `0x00561b5b` and `0x00561b84`.
- `0x00561740` has thirteen current code xrefs, including raw callsites at `0x005619fc`, `0x00561a18`, `0x00561a71`, `0x00561a89`, `0x00561aa8`, and `0x00561d86`.

Current boundary bytes:

- `0x00561a3d` is `retn 4`; bytes `0x00561a3e-0x00561a40` are the two-byte return immediate `04 00`, not a separate tail row.
- `0x00561afc` is `retn 0Ch`; `0x00561aff-0x00561b00` is one `0xcc` alignment byte before `0x00561b00`.
- `0x00561d4a` is `retn 8`; `0x00561d4d-0x00561d50` is three `0xcc` bytes.
- `0x00561dab` is `retn`; `0x00561dac-0x00561db0` is four `0xcc` bytes before the successor.

Current modeled decompilation facts:

- `0x00561b00` reads cursor position from `g_pEventMan`, converts it through the pane origin helper, dispatches directly to `0x00561bc0` when `m_activePart == 2`, otherwise hit-tests and dispatches only when the hit part matches `m_activePart`, then invalidates and clears a stale `m_highlightPart`.
- `0x00561bc0` reads old scroll position at `+0xfe`, gets the thumb rect, uses `m_orientation`, `m_scrollRange`, `m_thumbDragOffset`, and `m_bounds` to clamp a new position, and calls `0x0056df00` through the vtable owner route when the value changes.
- `0x0056df00` updates `NewGroupPane` state, calls `ScrollNewGroupPane` set-position helper `0x00560a70`, updates scroll range through `0x0056cd30`, and invalidates the parent pane.

## Companion report and support alias sync

The class-layout/signature blocker is resolved by applying the following support aliases to [UID:0000CL] `by-class/ScrollNewGroupPane.md` in the same implementation callback that creates the children. These aliases are drawn from current `0001GQ` and `0001GR` reports and rechecked against this target's MCP evidence.

Required enum alias:

```cpp
enum ScrollNewGroupPart {
    kScrollNewGroupPartLeading = 0,
    kScrollNewGroupPartPageBeforeThumb = 1,
    kScrollNewGroupPartThumb = 2,
    kScrollNewGroupPartPageAfterThumb = 3,
    kScrollNewGroupPartTrailing = 4,
    kScrollNewGroupPartNone = -1
};
```

Required field aliases:

| Offset | Source-facing alias | Evidence |
| --- | --- | --- |
| inherited `+0x44` | `m_bounds` | Used by `HitTestPart`, `GetPartRect`, and cursor-to-scroll math. |
| `+0xf8` | `m_scrollSkinIndex` | `0001GR` constant-table index for fixed vertical extents. If `0001GQ` has already introduced `m_scrollStyle`, harmonize it to this alias or record it as the historical equivalent. |
| `+0xfb` | `m_thumbDragActive` | Vertical drag override in `0001GQ/0001GR`. |
| `+0xfc` | `m_orientation` | Zero is vertical; nonzero is horizontal. |
| `+0xfe` | `m_scrollPosition` | Old/current scroll position used by `0x00561bc0`. |
| `+0x100` | `m_scrollRange` | Positive range/divisor used by part geometry and cursor-to-scroll math. |
| `+0x102` | `m_scrollEnabled` | Geometry enable gate in `0001GQ/0001GR`. |
| `+0x103` | `m_highlightPart` | Highlighted part byte set/cleared/invalidated by this target. |
| `+0x104` | `m_activePart` | Active pressed/tracking part byte set/consumed/cleared by this target. |
| `+0x108/+0x10c` | `m_thumbDragOffset` | Point pair written by `BeginPartInteraction`, read by `UpdateScrollPositionFromCursor`; project convention is `y, x`. |

Required helper aliases:

- `ScrollNewGroupPane::HitTestPart(int mouseY, int mouseX)` for `0x00561420`.
- `ScrollNewGroupPane::GetPartRect(ScrollNewGroupPart part, RectBounds *outRect)` for `0x00561740`.
- `EventMan::GetCursorPosition(Point *out)` through `g_pEventMan`.
- `ScrollNewGroupPane::GetScreenOffset(Point *out)` for the pane screen-origin helper `0x005447c0`.
- `InitPointPair(Point *out, int y, int x)` for `0x004b7c30`.
- `InvalidateRect(RectBounds *rect)` for the inherited vtable slot `+0x20`.
- `NewGroupPane *ScrollNewGroupPane::GetOwnerPane()` for vtable slot `+0x1c`, used by `UpdateScrollPositionFromCursor`.
- `TimerHandler::ScheduleTimer(0, 200, 0, 0)` and `TimerHandler::RemovePendingTimers()` through the `this+0xa4` timer/update-handler view.

This support update removes the prior C++ blocker. The names are inferred source-facing aliases, not recovered original symbols, but they are strong enough under the current code-entry gate and are consistent with accepted sibling scrollbar pages.

## Required range repair

Recommended parent remains:

`0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md`

Exact children to create:

1. `0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md`
2. `0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md`
3. `0x00561b00-0x00561bc0.ScrollNewGroupPaneUpdateActiveInteraction.md`
4. `0x00561bc0-0x00561d4d.ScrollNewGroupPaneUpdateScrollPositionFromCursor.md`
5. `0x00561d50-0x00561dac.ScrollNewGroupPaneResetInteractionStateRaw.md`

Padding/alignment handling:

- Do not create a child for `0x005619c7-0x005619d0`; it is predecessor padding after [UID:0001GR].
- Include the `retn 4` immediate bytes in child 1. Remove the current separate `0x00561a3e-0x00561a40` tail row.
- Child 2 may include the one-byte alignment at `0x00561aff-0x00561b00`, matching the existing `ScrollVolumePane` and `ScrollCollectionPane` raw-helper child precedent.
- Keep `0x00561d4d-0x00561d50` as parent padding after modeled child 4.
- Keep `0x00561dac-0x00561db0` as parent padding before successor `0x00561db0`.

## Child 1: SetHighlightedPartRaw

Path to create:

`by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md`

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000CL`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000CL`
- `EMITTER_POSITION_OPTIONAL:70`
- C++ disposition: formal first-draft C++ ready.

Formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
void ScrollNewGroupPane::SetHighlightedPart(ScrollNewGroupPart part)
{
    RectBounds rect;
    const ScrollNewGroupPart oldPart =
        static_cast<ScrollNewGroupPart>(m_highlightPart);

    if (oldPart == part)
        return;

    if (oldPart != kScrollNewGroupPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }

    if (part != kScrollNewGroupPartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }

    m_highlightPart = static_cast<signed char>(part);
}
```

Why this is source-safe:

- MCP raw instructions read `+0x103`, compare with the stack byte, invalidate old and new non-`0xff` part rectangles through `GetPartRect` and vtable slot `+0x20`, then write `+0x103`.
- The helper ends at `retn 4`; the immediate bytes belong inside this child.
- Raw-start no-xref status remains a confidence cap, not a no-code blocker, because the body, owner, callees, field roles, and sibling pattern are exact.

## Child 2: BeginPartInteractionRaw

Path to create:

`by-memory/0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000CL`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000CL`
- `EMITTER_POSITION_OPTIONAL:71`
- C++ disposition: formal first-draft C++ ready.

Formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
void ScrollNewGroupPane::BeginPartInteraction(ScrollNewGroupPart part,
                                              int mouseY,
                                              int mouseX)
{
    RectBounds rect;

    if (part == kScrollNewGroupPartThumb) {
        if (m_highlightPart != kScrollNewGroupPartThumb) {
            if (m_highlightPart != kScrollNewGroupPartNone) {
                GetPartRect(static_cast<ScrollNewGroupPart>(m_highlightPart),
                            &rect);
                InvalidateRect(&rect);
            }

            GetPartRect(kScrollNewGroupPartThumb, &rect);
            InvalidateRect(&rect);
            m_highlightPart =
                static_cast<signed char>(kScrollNewGroupPartThumb);
        }

        GetPartRect(kScrollNewGroupPartThumb, &rect);
        InitPointPair(&m_thumbDragOffset,
                      mouseY - rect.top,
                      mouseX - rect.left);
    }

    m_activePart = static_cast<signed char>(part);
    UpdateActiveInteraction();
    ScheduleTimer(0, 200, 0, 0);
}
```

Why this is source-safe:

- MCP raw instructions read the first argument byte as the part id and use the second/third arguments as `mouseY`/`mouseX` for `InitPointPair`.
- The thumb path invalidates the previous highlighted part, invalidates thumb, writes `m_highlightPart = 2`, records `m_thumbDragOffset`, stores `m_activePart`, immediately calls `UpdateActiveInteraction`, and schedules timer id `0` with delay `0xc8` / `200`.
- This mirrors the accepted `ScrollVolumePane::BeginInteraction` raw-helper source shape while using the ScrollNewGroupPane-specific helper names and child route.

## Child 3: UpdateActiveInteraction

Path to create:

`by-memory/0x00561b00-0x00561bc0.ScrollNewGroupPaneUpdateActiveInteraction.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000CL`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000CL`
- `EMITTER_POSITION_OPTIONAL:72`
- C++ disposition: formal first-draft C++ ready.

Formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
void ScrollNewGroupPane::UpdateActiveInteraction()
{
    Point cursor;
    Point origin;
    RectBounds rect;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.x == -1000 && origin.y == -1000)
        return;

    cursor.y -= origin.y;
    cursor.x -= origin.x;

    if (m_activePart == kScrollNewGroupPartThumb) {
        UpdateScrollPositionFromCursor(cursor.y, cursor.x);
        return;
    }

    if (HitTestPart(cursor.y, cursor.x) ==
        static_cast<ScrollNewGroupPart>(m_activePart)) {
        UpdateScrollPositionFromCursor(cursor.y, cursor.x);
    }

    if (m_highlightPart != kScrollNewGroupPartNone) {
        GetPartRect(static_cast<ScrollNewGroupPart>(m_highlightPart), &rect);
        InvalidateRect(&rect);
        m_highlightPart =
            static_cast<signed char>(kScrollNewGroupPartNone);
    }
}
```

Why this is source-safe:

- Current Hex-Rays and disassembly show exactly this control flow: cursor read, screen-origin conversion, active-thumb direct update and return, non-thumb hit-test match update, then stale highlight invalidation/clear.
- The range is a modeled IDA function with exact end `0x00561bc0`; current target row must be repaired from `0x00561bbf` to the half-open end.
- The code uses `void` because the decompiler's `char` return is incidental register residue; all callers use the side effects.

## Child 4: UpdateScrollPositionFromCursor

Path to create:

`by-memory/0x00561bc0-0x00561d4d.ScrollNewGroupPaneUpdateScrollPositionFromCursor.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000CL`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000CL`
- `EMITTER_POSITION_OPTIONAL:73`
- C++ disposition: formal first-draft C++ ready.

Formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
void ScrollNewGroupPane::UpdateScrollPositionFromCursor(int mouseY,
                                                        int mouseX)
{
    Point cursor;
    Point origin;
    RectBounds thumbRect;
    RectBounds leadingRect;
    RectBounds trailingRect;
    unsigned short oldPosition;
    unsigned short newPosition;
    int thumbStart;
    int maxThumbStart;
    int trackStart;
    int trackSpan;

    oldPosition = m_scrollPosition;
    GetPartRect(kScrollNewGroupPartThumb, &thumbRect);

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    leadingRect = m_bounds;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    trailingRect = m_bounds;

    if (m_orientation != 0) {
        leadingRect.right = leadingRect.left;
        trailingRect.left = trailingRect.right;

        thumbStart = mouseX - m_thumbDragOffset.x + 1;
        trackStart = leadingRect.right;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        maxThumbStart = trailingRect.left + thumbRect.left - thumbRect.right;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        trackSpan = trailingRect.left + thumbRect.left -
                    thumbRect.right - leadingRect.right;
        newPosition = static_cast<unsigned short>(
            (m_scrollRange * (thumbStart - leadingRect.right)) / trackSpan);
    } else {
        leadingRect.bottom = leadingRect.top;
        trailingRect.top = trailingRect.bottom;

        thumbStart = mouseY - m_thumbDragOffset.y + 1;
        trackStart = leadingRect.bottom;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        maxThumbStart = trailingRect.top + thumbRect.top - thumbRect.bottom;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        trackSpan = trailingRect.top + thumbRect.top -
                    thumbRect.bottom - leadingRect.bottom;
        newPosition = static_cast<unsigned short>(
            ((m_scrollRange + 1) *
             (thumbStart - leadingRect.bottom)) / trackSpan);

        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    }

    if (oldPosition != newPosition) {
        GetOwnerPane()->SetScrollPosition(m_orientation,
                                          oldPosition,
                                          newPosition);
    }
}
```

Why this is source-safe:

- Current disassembly confirms the argument order: `arg_0` is used with `+0x108` in the vertical branch and `arg_4` is used with `+0x10c` in the horizontal branch, matching `mouseY, mouseX`.
- The binary calls the cursor/origin helpers twice after `GetPartRect`, then computes leading/trailing edge rectangles from `m_bounds`, clamps the dragged thumb start, maps to `m_scrollRange`, caps the vertical result to range, and calls `NewGroupPane::SetScrollPosition` through vtable slot `+0x1c` only when the value changes. The formal block preserves those helper calls.
- `GetOwnerPane()->SetScrollPosition(m_orientation, oldPosition, newPosition)` is the source-facing form of the call sequence at `0x00561d26-0x00561d35`.
- The modeled helper ends with `retn 8` at `0x00561d4a`; the child range must be half-open to `0x00561d4d`.

## Child 5: ResetInteractionStateRaw

Path to create:

`by-memory/0x00561d50-0x00561dac.ScrollNewGroupPaneResetInteractionStateRaw.md`

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000CL`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000CL`
- `EMITTER_POSITION_OPTIONAL:74`
- C++ disposition: formal first-draft C++ ready.

Formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
void ScrollNewGroupPane::ResetInteractionState()
{
    RectBounds rect;
    const ScrollNewGroupPart oldPart =
        static_cast<ScrollNewGroupPart>(m_highlightPart);

    RemovePendingTimers();
    m_activePart = static_cast<signed char>(kScrollNewGroupPartNone);

    if (oldPart != kScrollNewGroupPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart =
            static_cast<signed char>(kScrollNewGroupPartNone);
    }
}
```

Why this is source-safe:

- MCP raw instructions call `0x00597600` through `this+0xa4`, read `+0x103`, clear `+0x104` to `0xff`, conditionally invalidate the old highlighted part through `GetPartRect` and vtable slot `+0x20`, then clear `+0x103`.
- The source-facing name `ResetInteractionState` is stronger than `Deactivate` because the body matches accepted `ScrollVolumePane` and `ScrollCollectionPane` reset-interaction helpers.
- The raw body ends at `0x00561dac`; `0x00561dac-0x00561db0` is padding.

## Owner, emitter, and source route

Exact child owner:

- `CANONICAL_OWNER:0000CL` / `ScrollNewGroupPane`

Exact child emitter:

- `EMITTER_UIDS:0000CL`

Source route:

- [UID:0000CL] routes to [UID:0000JS] `Group`, whose source path remains `NexusTK/social/`.

Evidence for this route:

- The target's helpers call `ScrollNewGroupPane::HitTestPart` and `ScrollNewGroupPane::GetPartRect`.
- The state fields match the `ScrollNewGroupPane` constructor/core, the `0001GQ` hit-test report, and the `0001GR` part-rect report.
- `0x00561bc0` calls `NewGroupPane::SetScrollPosition` at `0x0056df00`, directly tying the scrollbar back to `NewGroupPane`.
- Existing accepted B-reports reject generated `TextEditPane` ownership for this method family.

Rejected routes:

- `TextEditPane`: stale generated pollution; contradicted by callers, fields, helper graph, and accepted B005 TextEditPane research.
- `ScrollCollectionPane`: successor starts at `0x00561db0` after padding; this target is predecessor `ScrollNewGroupPane` interaction code.
- Generic/shared scrollbar owner: sibling patterns are useful naming evidence, but the receiver, callback, and owner route are class-specific here.

## Recommended target/support doc edits

Parent target `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md`:

- Change metadata to the non-emitting split-index state listed in the final recommendation.
- Replace the mixed current table with exact child rows and padding rows.
- Delete the separate `0x00561a3e-0x00561a40` instruction-tail row.
- Repair modeled rows to half-open ends: `0x00561b00-0x00561bc0` and `0x00561bc0-0x00561d4d`.
- Preserve the no-xref/no-function raw-start evidence as a confidence cap, not as a no-code blocker.
- Add the parent no-code proof.

New child pages:

- Create all five exact child files listed above.
- Apply the exact metadata and formal C++ blocks listed in the child sections.
- Each child should record the relevant MCP boundary/xref/callee/disassembly facts and link back to the parent split index plus [UID:0000CL].

Support doc `by-class/ScrollNewGroupPane.md`:

- Add the `ScrollNewGroupPart` enum and field/helper aliases listed in this report.
- Update the method inventory for the five new children and existing [UID:0001GQ]/[UID:0001GR] support names.
- Rename the final raw helper from `Deactivate` to `ResetInteractionState`.
- Record that `m_thumbDragOffset` uses project point order `y, x` while `RectBounds` fields remain `left/top/right/bottom`.
- Keep class metadata unchanged unless the supervisor separately chooses to rescore after incorporating the child code.

Support doc `by-file/Group.md`:

- No required metadata change.
- Optional support prose: note that `0001GS` was split into exact `ScrollNewGroupPane` interaction child pages under the existing Group route.

Generated files and reports:

- Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, generated C++ output, validator state/cache, project-level generated files, or any `-coverage-report.md`.
- Let scoped validators and normal generated refresh update stale `76/86` generated rows after implementation.

## Score and blocker disposition

Current live parent target:

- `COMPLETION:87`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000CL`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000CL`

Recommended implemented state:

- Parent split index: `88/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, no emitters, no C++.
- Child 1: `87/89`, owner/emitter `0000CL`, formal C++ ready.
- Child 2: `88/90`, owner/emitter `0000CL`, formal C++ ready.
- Child 3: `88/90`, owner/emitter `0000CL`, formal C++ ready.
- Child 4: `88/90`, owner/emitter `0000CL`, formal C++ ready.
- Child 5: `87/90`, owner/emitter `0000CL`, formal C++ ready.

Resolved blockers:

- Mixed raw/modeled parent: resolved by split-index parent plus exact child pages.
- Invalid return-immediate tail row: resolved by including `0x00561a3e-0x00561a40` in child 1.
- Modeled half-open endpoints: resolved by child 3 and child 4 ranges.
- Raw-start no-xref status: documented as a confidence cap but no longer blocks child C++ because raw body, owner, helper graph, and sibling precedents are exact.
- Field/helper aliases: resolved by same-pass [UID:0000CL] support update.
- C++ readiness: resolved by exact formal blocks for every source-owned child.

Remaining confidence caps:

- Exact original source spelling is not recovered from symbols.
- Raw starts still lack modeled IDA functions and external direct xrefs.
- Generated tracker/source rows are stale until validator refresh.

These are confidence caps, not implementation blockers.

## Implementation tracking checklist

- [x] Update parent `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md` to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank C++. Proof: parent header now has those values, blank formal C++ block, and parent no-code proof explaining the split-index/non-emitting disposition.
- [x] Replace the parent table with exact child rows for `0x005619d0-0x00561a40`, `0x00561a40-0x00561b00`, `0x00561b00-0x00561bc0`, `0x00561bc0-0x00561d4d`, and `0x00561d50-0x00561dac`, plus padding rows `0x00561d4d-0x00561d50` and `0x00561dac-0x00561db0`. Proof: parent `Split Ranges` table now lists those half-open rows and padding rows with assigned child UIDs `00042L` through `00042P`.
- [x] Remove the separate `0x00561a3e-0x00561a40` tail row and document it as the `retn 4` immediate in child 1. Proof: parent and child 1 both state the bytes are the `retn 4` immediate inside `00042L`; no separate table row remains.
- [x] Create `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` with `87/89`, owner/emitter `0000CL`, position `70`, and the exact `SetHighlightedPart` C++ block from this report. Proof: validator assigned UID `00042L`; header and formal C++ block match the accepted insertion text.
- [x] Create `by-memory/0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md` with `88/90`, owner/emitter `0000CL`, position `71`, and the exact `BeginPartInteraction` C++ block from this report. Proof: validator assigned UID `00042M`; header and formal C++ block match the accepted insertion text.
- [x] Create `by-memory/0x00561b00-0x00561bc0.ScrollNewGroupPaneUpdateActiveInteraction.md` with `88/90`, owner/emitter `0000CL`, position `72`, and the exact `UpdateActiveInteraction` C++ block from this report. Proof: validator assigned UID `00042N`; header and formal C++ block match the accepted insertion text.
- [x] Create `by-memory/0x00561bc0-0x00561d4d.ScrollNewGroupPaneUpdateScrollPositionFromCursor.md` with `88/90`, owner/emitter `0000CL`, position `73`, and the exact `UpdateScrollPositionFromCursor` C++ block from this report. Proof: validator assigned UID `00042O`; header and formal C++ block match the accepted insertion text.
- [x] Create `by-memory/0x00561d50-0x00561dac.ScrollNewGroupPaneResetInteractionStateRaw.md` with `87/90`, owner/emitter `0000CL`, position `74`, and the exact `ResetInteractionState` C++ block from this report. Proof: validator assigned UID `00042P`; header and formal C++ block match the accepted insertion text; a narrow post-check wording correction removed the old helper name and was revalidated.
- [x] Update `by-class/ScrollNewGroupPane.md` with the `ScrollNewGroupPart` enum/value mapping, field aliases, helper aliases, timer/update-handler view notes, `GetOwnerPane` callback note, and `m_thumbDragOffset` `y, x` point-order note from this report. Proof: class sections `Scrollbar Part And Field Alias Notes` and `Helper Alias And Callback Notes` now contain these details while preserving B002/B005 alias history.
- [x] Update `by-class/ScrollNewGroupPane.md` method inventory to reference the five child files after UIDs are assigned, and rename the old final raw-helper wording to `ResetInteractionState`. Proof: method inventory now references `00042L`, `00042M`, `00042N`, `00042O`, and `00042P`; `ResetInteractionState` is the listed method name.
- [x] Leave `by-file/Group.md` metadata unchanged; add only optional support prose if the supervisor wants the split noted at file level. Proof: B008 did not edit `by-file/Group.md`; the optional prose was intentionally excluded because the supervisor marked it optional, so no Group validator was required for this callback.
- [x] Preserve rejected `TextEditPane`, `ScrollCollectionPane`, and generic/shared scrollbar route evidence in target/support docs. Proof: parent `Rejected Ownership And Source Routes` records all three rejected routes; class evidence notes preserve the generated `TextEditPane` pollution and successor `ScrollCollectionPane` boundary.
- [x] Do not manually edit generated reports, project-level generated files, generated C++ output, validator state/cache, IDA DB, or any `-coverage-report.md`. Proof: B008 manual edits were limited to the parent by-memory page, five new child by-memory pages, `by-class/ScrollNewGroupPane.md`, and this report. Validator commands produced normal tool-owned `validator.ini`, projected-stats, registry, and generated-refresh side effects; no generated or coverage files were manually edited.
- [x] Run the scoped validators listed below after implementation. Proof: all required file validators completed with exit code `0`; exact command IDs and `ok` counts are recorded in `Implementation validator results`.
- [x] Let generated tracker/coverage/source output refresh through validator/autogen only. Proof: every file validator reported `generated_refresh: deferred`; `python .\tools\validator.py --queue-status` returned command `000000002040` at `2026-06-26T00:53:23-04:00` with `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`, so the generated refresh queue was idle/caught up. No manual generated-output edit was made.

Unchecked implementation items: none.

## Implementation validator results

All validator commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

| File | Command | command_id | command_timestamp | Exit | ok | generated-refresh / diagnostics |
| --- | --- | --- | --- | --- | --- | --- |
| Parent split index | `python .\tools\validator.py --mode file --file by-memory\0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md --apply --queue-timeout 240` | `000000002030` | `2026-06-26T00:50:08-04:00` | `0` | `6` | `generated_refresh: deferred`; assigned child UIDs `00042L-00042P`, inserted missing child UID headers, updated parent metadata, replaced parent TMP refs, updated projected stats. |
| Child 1 `SetHighlightedPartRaw` | `python .\tools\validator.py --mode file --file by-memory\0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md --apply --queue-timeout 240` | `000000002031` | `2026-06-26T00:50:16-04:00` | `0` | `3` | `generated_refresh: deferred`; resolved successor TMP references and updated projected stats. |
| Child 2 `BeginPartInteractionRaw` | `python .\tools\validator.py --mode file --file by-memory\0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md --apply --queue-timeout 240` | `000000002032` | `2026-06-26T00:50:25-04:00` | `0` | `4` | `generated_refresh: deferred`; resolved predecessor/successor TMP references and updated projected stats. |
| Child 3 `UpdateActiveInteraction` | `python .\tools\validator.py --mode file --file by-memory\0x00561b00-0x00561bc0.ScrollNewGroupPaneUpdateActiveInteraction.md --apply --queue-timeout 240` | `000000002033` | `2026-06-26T00:50:36-04:00` | `0` | `4` | `generated_refresh: deferred`; resolved predecessor/successor TMP references and updated projected stats. |
| Child 4 `UpdateScrollPositionFromCursor` | `python .\tools\validator.py --mode file --file by-memory\0x00561bc0-0x00561d4d.ScrollNewGroupPaneUpdateScrollPositionFromCursor.md --apply --queue-timeout 240` | `000000002034` | `2026-06-26T00:50:46-04:00` | `0` | `4` | `generated_refresh: deferred`; resolved predecessor/successor TMP references and updated projected stats. |
| Child 5 `ResetInteractionStateRaw` | `python .\tools\validator.py --mode file --file by-memory\0x00561d50-0x00561dac.ScrollNewGroupPaneResetInteractionStateRaw.md --apply --queue-timeout 240` | `000000002035` | `2026-06-26T00:50:57-04:00` | `0` | `3` | `generated_refresh: deferred`; resolved predecessor TMP references and updated projected stats. |
| Class support page | `python .\tools\validator.py --mode file --file by-class\ScrollNewGroupPane.md --apply --queue-timeout 240` | `000000002036` | `2026-06-26T00:51:07-04:00` | `0` | `11` | `generated_refresh: deferred`; resolved ten class TMP references to child UIDs and updated projected stats. |
| Child 5 wording correction | `python .\tools\validator.py --mode file --file by-memory\0x00561d50-0x00561dac.ScrollNewGroupPaneResetInteractionStateRaw.md --apply --queue-timeout 240` | `000000002039` | `2026-06-26T00:52:37-04:00` | `0` | `1` | `generated_refresh: deferred`; revalidated the narrow wording correction that removed the old helper name from child 5. |
| Generated queue status | `python .\tools\validator.py --queue-status` | `000000002040` | `2026-06-26T00:53:23-04:00` | `0` | n/a | Worker running; `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, `processing generated refresh jobs: 0`. |

## Lease proof

- Initial read of `tools/leaser/Agents/Agent-B008/current_leases.md` showed no active conflicting leases on the parent/class target paths; only unrelated expired Supervisor rows were present.
- Existing-doc lease command before editing: `python .\tools\leaser\leaser.py B008 lease by-memory\0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md by-class\ScrollNewGroupPane.md` returned `Success` for both paths.
- New-child lease command after creation and before validator mutation: `python .\tools\leaser\leaser.py B008 lease by-memory\0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md by-memory\0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md by-memory\0x00561b00-0x00561bc0.ScrollNewGroupPaneUpdateActiveInteraction.md by-memory\0x00561bc0-0x00561d4d.ScrollNewGroupPaneUpdateScrollPositionFromCursor.md by-memory\0x00561d50-0x00561dac.ScrollNewGroupPaneResetInteractionStateRaw.md` returned `Success` for all five paths.
- Main release command after the validator batch returned `Success` for all five child paths; parent/class returned `Rejected[No active lease]` because those short leases had expired during validation.
- Correction lease command for `by-memory\0x00561d50-0x00561dac.ScrollNewGroupPaneResetInteractionStateRaw.md` returned `Success`; release after revalidation returned `Success`.
- Final read of `tools/leaser/Agents/Agent-B008/current_leases.md` showed no B008 lease rows.

## Validator plan for implementation callback

Run from `source-3/project-documentation` after implementing the documentation changes:

> Executable block R001 was removed from this report and preserved verbatim in [0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality-removed.md](0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run `Group.md` validation only if optional file-level prose is edited:

> Executable block R002 was removed from this report and preserved verbatim in [0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality-removed.md](0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No validators were run during this report-only correction pass.

## Changed files in this correction pass

- Report correction pass: modified this report only.
- Implementation callback pass: modified `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md` and `by-class/ScrollNewGroupPane.md`; created `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` (`00042L`), `by-memory/0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md` (`00042M`), `by-memory/0x00561b00-0x00561bc0.ScrollNewGroupPaneUpdateActiveInteraction.md` (`00042N`), `by-memory/0x00561bc0-0x00561d4d.ScrollNewGroupPaneUpdateScrollPositionFromCursor.md` (`00042O`), and `by-memory/0x00561d50-0x00561dac.ScrollNewGroupPaneResetInteractionStateRaw.md` (`00042P`).
- `by-file/Group.md` was not edited by B008 because its split note was optional and metadata was to remain unchanged.

Leases used: parent/class existing-doc lease, five-child post-creation lease, and one narrow child-5 wording-correction lease; all released or confirmed expired with no active B008 leases remaining.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality.md","timestamp":"2026-06-26T00:58:58","uid":"0001GS"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001GS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
