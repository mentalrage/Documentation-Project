** TARGET-REPORT-UID:0001GX **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Report: [UID:0001GX] ScrollCollectionPaneUpdatePositionFromCursor source quality

- Assignment id: `B001-report-0001GX-scroll-collection-pane-update-position-from-cursor-source-quality-20260626`
- Target: [UID:0001GX] `by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md`
- Mode: report-only research; no target/support by-* files edited.
- IDA MCP: required and available. Current session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- MCP health proof: 2026-06-26 15:16-15:19 EDT, command ids `20-27` and `120-125`; `server_health` returned `status:"ok"`, auto-analysis ready, Hex-Rays ready, strings cache ready.

## Final Recommendation

Implement [UID:0001GX] as exact first-draft source for `ScrollCollectionPane::UpdatePositionFromCursor(int localY, int localX)`.

Recommended target metadata after implementation:

- `COMPLETION:90`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000CG`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000CG`
- `EMITTER_POSITION_OPTIONAL:80`
- Formal C++: populate the target `RECONSTRUCTION_CPP CODE` block with the exact insertion text below.

The old blank-C++ blocker is no longer valid. The helper/field names needed by this body have been resolved enough for first-draft C++ by current ScrollCollectionPane support docs and the accepted B005 implementation of [UID:0001GW] `UpdateDragScroll`: `ScrollCollectionPart`, `kScrollCollectionPartThumb`, `m_scrollPosition`, `m_scrollRange`, `m_orientation`, `m_thumbDragOffset`, `m_bounds`, `GetPartRect`, `g_pEventMan->GetCursorPosition`, `GetScreenOffset`, and `UpdatePositionFromCursor(localY, localX)`.

The score should not jump to final-audit territory because the exact original spelling of the owner callback declaration and the final physical source placement (`ScrollCollectionPane.cpp` versus a broader `ScrollBar.cpp` fold) remain unresolved. Those are confidence caps, not reasons to leave the method without first-draft C++.

## Current Target State

Current [UID:0001GX] metadata:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000CG`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000CG`
- blank formal C++

Current stale blocker language says C++ remains blank because cursor/pane-position helper and member field names are not final. That was reasonable before the later sibling alias work, but it is now stale. The target's actual remaining questions are final polish questions; the function body is modeled, bounded, reachable, class-owned, and source-shaped.

## Current IDA MCP Evidence

Live MCP session `80de0a67` confirms:

- `lookup_funcs` reports `0x00563070` as `sub_563070`, size `0x18d`.
- `lookup_funcs` reports `0x005631fd` and `0x00563200` as not functions, proving the half-open target end and the next raw helper boundary.
- `get_bytes` over `0x00563070` returns one stack-cookie protected body ending in `retn 8`; `get_bytes 0x005631fd size 3` returns `cc cc cc`; `get_bytes 0x00563200 size 0x10` begins with a new prologue `55 8b ec 83 ec 14 ...`.
- `xrefs_to 0x00563070` reports exactly two code xrefs, both from [UID:0001GW] `UpdateDragScroll`: `0x0056300b` and `0x00563034`.
- `xrefs_to 0x005631fd` and `xrefs_to 0x00563200` return zero direct xrefs.
- `find_bytes` finds no absolute VA dword hits for `0x00563070`, `0x005631fd`, or `0x00563200`; this is expected for a directly-called method and supports the current non-table boundary.
- `callees 0x00563070` returns `0x00562bf0`, `0x004a9090`, `0x005447c0`, `0x0056fa90`, and `@__security_check_cookie@4`.
- `xrefs_to 0x0056fa90` reports exactly the callback from this target at `0x005631e5`.
- `find_bytes 90 FA 56 00` finds no raw absolute pointer hits to the callback, so the target's callback route is the code call after owner retrieval, not a separate data-table route.

The current decompile confirms the body shape:

- reads old position from `this+0xfe` before any geometry work;
- calls `0x00562bf0(this, 2, &thumbRect)`, where `2` is `kScrollCollectionPartThumb`;
- calls `g_pEventMan->GetCursorPosition` and `GetScreenOffset` twice;
- checks the `(-1000,-1000)` screen-origin sentinel around the copied leading/trailing bounds;
- branches on orientation byte `this+0xfc`;
- uses `this+0x108` in the vertical/local-Y branch and `this+0x10c` in the horizontal/local-X branch;
- uses `this+0x100` as the max scroll range;
- scales the clamped thumb start over the available track span;
- clamps the vertical result down to `m_scrollRange`;
- compares new position against the old `this+0xfe` value;
- retrieves the owner through vtable slot `+0x1c`;
- calls `0x0056fa90` with `(orientation, oldPosition, newPosition)`.

## Support Evidence

Relevant support docs and prior accepted reports:

- [UID:0000CG] `by-class/ScrollCollectionPane.md` now accepts `ScrollCollectionPart`, `kScrollCollectionPartThumb`, `kScrollCollectionPartNone`, `m_highlightPart`, `m_activePart`, `m_thumbDragOffset`, `GetPartRect`, `HitTestScrollRegion`, and `UpdatePositionFromCursor`.
- [UID:0001GW] `by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md` now emits formal first-draft C++ and calls `UpdatePositionFromCursor(localY, localX)`, proving the argument order for this target.
- [UID:0003MY] `by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md` initializes `m_thumbDragOffset` from incoming cursor coordinates minus the thumb rectangle top/left and then calls `UpdateDragScroll`.
- [UID:0001GY] `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md` emits `ScrollCollectionPane::ResetScrollState()` and uses the same accepted part/geometry field names.
- [UID:0001VZ] `by-type/by-struct/ScrollCollectionPaneLayout.md` records `+0x44` bounds, `+0xfc` orientation, `+0xfe` current position, `+0x100` range, and `+0x108/+0x10c` drag state.
- [UID:0003YA] `by-memory/0x0056fa90-0x0056fac8.CollectionPaneOnScrollPositionChanged.md` names the callback target as `CollectionPane::OnScrollPositionChanged(...)`; its exact prototype is still broader CollectionPane work, but the route from this method is clear.
- Executed B008 ScrollNewGroupPane report documents the same source-shaped cursor-to-scroll algorithm in a sibling class: get thumb rectangle, sample cursor/origin twice, create leading/trailing edge rectangles from bounds, branch on orientation, subtract `m_thumbDragOffset`, scale over track span, clamp to range, and notify owner on change.
- Executed B005 `0001GW-ScrollCollectionPaneUpdateDragScroll-source-quality.md` resolves `0x004a9090` as `g_pEventMan->GetCursorPosition(&cursor)` and `0x005447c0` as `GetScreenOffset(&origin)` for this exact class cluster.

## Field And Helper Naming Resolution

Use these source-facing names in target/support docs:

| Binary item | Source-facing name | Confidence | Reason |
| --- | --- | --- | --- |
| `0x00563070` | `ScrollCollectionPane::UpdatePositionFromCursor(int localY, int localX)` | high | Accepted B005 sibling calls this exact method with `localY, localX`; the target consumes arg0 in the vertical branch and arg1 in the horizontal branch. |
| `this+0xfe` | `m_scrollPosition` | high | Current/old position read before math and compared before callback; sibling collection callback and layout docs agree. |
| `this+0x100` | `m_scrollRange` | medium-high | Used as maximum range in scaling and clamp; support docs call it range/max range. Prefer `m_scrollRange` in draft C++ to match sibling scroll reports. |
| `this+0xfc` | `m_orientation` | high | Branch selector and callback argument; class/layout docs agree. |
| `this+0x44` | `m_bounds` | high | Copied into local edge rectangles and shared by hit-test/part-rect helpers. |
| `this+0x108/+0x10c` | `m_thumbDragOffset.y / .x` | medium-high | Project point order is `y, x`. `+0x108` is used with `localY`; `+0x10c` is used with `localX`. Current target doc wording should be corrected if it describes `+0x108` as horizontal or `+0x10c` as vertical. |
| `0x00562bf0` | `GetPartRect(kScrollCollectionPartThumb, &thumbRect)` | high | Class docs and B005 implementation reject older `GetScrollRegionRect` wording for new formal C++. |
| `0x004a9090` via `0x0067a754` | `g_pEventMan->GetCursorPosition(&cursor)` | high | EventMan and B005 reports agree. |
| `0x005447c0` | `GetScreenOffset(&origin)` | medium-high | Current project-facing name in recent scroll reports; `GetScreenOrigin` remains an acceptable historical alias but should not appear in this target's formal C++. |
| vtable slot `+0x1c` | `GetOwnerPane()` / owner retrieval | medium | The exact original accessor spelling is not symbol-proven; source-shaped C++ should use an owner accessor instead of a raw vtable call. |
| `0x0056fa90` | `CollectionPane::OnScrollPositionChanged(...)` | high for role, medium for exact signature | Direct callback body belongs to CollectionPane; this method passes orientation, old position, and new position. |

## Positive Evidence

- The function is a real IDA-modeled helper with an exact `0x18d` body and normal `retn 8`.
- There are exactly two callers, both from `UpdateDragScroll`, and both caller sites are documented in the current sibling body.
- The callee set is exactly the expected scroll/update set: part rectangle, cursor read, screen offset, CollectionPane callback, and stack-cookie check.
- Current docs and accepted reports now provide source-facing names for every helper needed in first-draft C++.
- The sibling ScrollNewGroupPane update-from-cursor algorithm has the same branch/math shape and has already been accepted as source-shaped first-draft C++ in project reports.
- The target has no raw/non-modeled reachability problem; it is a normal function between a modeled predecessor and a raw reset helper.
- The old support contradiction about unresolved helper/field names is obsolete after B005 and B014 ScrollCollectionPane updates.

## Negative Evidence And Rejected Alternatives

- Do not leave `sub_563070`, `sub_562BF0`, `sub_4A9090`, `sub_5447C0`, `sub_56FA90`, `dword_67A754`, or raw offsets in the formal C++.
- Do not rename the target as a free helper or generic `ScrollBar` function now. The direct semantic owner is [UID:0000CG] `ScrollCollectionPane`; a later file-family pass may move the physical source file, but this does not change method ownership.
- Do not describe `+0x108` as the horizontal component for the formal draft. The target uses `+0x108` with `localY`; `+0x10c` is the horizontal/local-X component.
- Do not claim the callback target is owned by `ScrollCollectionPane`. The receiver returned by vtable slot `+0x1c` is the owning `CollectionPane`, and the direct callback body is [UID:0003YA].
- Do not treat the sentinel checks as a reason to block C++. They are documented binary behavior around `GetScreenOffset`; the normal active-drag source shape is still recoverable and matches the accepted sibling algorithm.

## Exact Formal C++ Insertion Text

Insert this in [UID:0001GX]'s formal `RECONSTRUCTION_CPP CODE` block during implementation:

```cpp
void ScrollCollectionPane::UpdatePositionFromCursor(int localY, int localX)
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
    GetPartRect(kScrollCollectionPartThumb, &thumbRect);

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        leadingRect = m_bounds;
        if (m_orientation != 0) {
            leadingRect.right = leadingRect.left;
        } else {
            leadingRect.bottom = leadingRect.top;
        }
    }

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        trailingRect = m_bounds;
        if (m_orientation != 0) {
            trailingRect.left = trailingRect.right;
        } else {
            trailingRect.top = trailingRect.bottom;
        }
    }

    if (m_orientation != 0) {
        thumbStart = localX - m_thumbDragOffset.x + 1;
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
        thumbStart = localY - m_thumbDragOffset.y + 1;
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
        GetOwnerPane()->OnScrollPositionChanged(m_orientation,
                                                oldPosition,
                                                newPosition);
    }
}
```

This block deliberately follows the accepted sibling ScrollNewGroupPane source shape while explicitly preserving the binary's `(-1000,-1000)` screen-offset sentinel branches. It keeps the two cursor/origin calls because the binary has them, but avoids IDA register/stack local names. It also keeps project point ordering: function arguments are `localY, localX`, while `RectBounds` fields remain `left/top/right/bottom`.

## Sentinel Branch Note

The raw disassembly checks `GetScreenOffset` results against `(-1000,-1000)` before copying/collapsing edge rectangles. The formal first-draft block above includes those branches instead of treating them as a prose-only caveat. The active drag path should normally have a valid screen offset, but preserving the branch shape avoids silently changing behavior if an invalid-origin path is ever reached.

## Recommended Target Doc Edits

For `by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md`:

- Set `COMPLETION:90` and `CONFIDENCE:91`.
- Keep owner/emitter `0000CG`, `RECONSTRUCTABLE:TRUE`, and route through [UID:0000CG].
- Set `EMITTER_POSITION_OPTIONAL:80`.
- Insert the exact formal C++ block above.
- Update item summary to mention first-draft C++, exact function boundary, two `UpdateDragScroll` callers, thumb rectangle, two cursor/origin samples with sentinel checks, point order `localY/localX`, orientation split, `m_thumbDragOffset`, `m_scrollRange`, owner callback, padding, and stale blocker resolution.
- Update the behavior and touched-state sections so `+0x108` is the Y/local-vertical drag-offset component and `+0x10c` is the X/local-horizontal component.
- Replace blank-C++ rationale with current source-ready rationale and remaining confidence caps.
- Add this 2026-06-26 B001 MCP session evidence and note that no generated/tool/IDA DB files were changed.

For `by-class/ScrollCollectionPane.md`:

- Update the `UpdatePositionFromCursor` method row and score rationale to say [UID:0001GX] now has source-quality names and should emit first-draft C++ at child position `80`.
- Add a note that the old target blocker was resolved by accepted B005 alias work plus this report's MCP recheck.
- Clarify `m_thumbDragOffset` component use as project `Point` order `y,x`: `+0x108` is used with `localY`, `+0x10c` with `localX`.
- Keep the broader `ScrollCollectionPane.cpp` versus `ScrollBar.cpp` source-placement caveat as a file-family cap only.

For `by-file/ScrollCollectionPane.md`:

- Record [UID:0001GX] as source-ready formal first-draft C++ under the current `ScrollCollectionPane.cpp` route.
- Preserve the possible later `ScrollBar.cpp` merge caveat.

For `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`:

- Update the child row/status for `0x00563070-0x005631fd` to say [UID:0001GX] now emits exact first-draft C++.
- Preserve aggregate marker/children routing; do not paste the method body into the aggregate.

For `by-type/by-struct/ScrollCollectionPaneLayout.md`:

- If touched during implementation, clarify `+0x108/+0x10c` as a point-like `m_thumbDragOffset` with project `y,x` storage, and note [UID:0001GX] consumes `+0x108` with `localY` and `+0x10c` with `localX`.
- Do not change layout metadata unless the validator requires it.

For [UID:0003YA] `CollectionPaneOnScrollPositionChanged`:

- No required edit for this report. The target can call the source-facing callback name while [UID:0003YA] keeps its own prototype/name caps.

## Score And Blocker Disposition

Resolved blockers:

- Cursor helper name: resolved as `g_pEventMan->GetCursorPosition(&cursor)`.
- Pane-origin helper name: resolved as `GetScreenOffset(&origin)` for current project-facing use.
- Geometry helper name: resolved as `GetPartRect`.
- Part constant: resolved as `kScrollCollectionPartThumb`.
- Drag field names: resolved as `m_thumbDragOffset` with project point order `y,x`.
- Position/range/orientation names: resolved as `m_scrollPosition`, `m_scrollRange`, and `m_orientation`.
- Owner/emitter route: remains [UID:0000CG], no change needed.
- Formal C++ readiness: resolved; target should no longer be blank.

Remaining confidence caps:

- Exact original spelling of the owner accessor (`GetOwnerPane`) is not symbol-proven.
- Exact original `CollectionPane::OnScrollPositionChanged` prototype and parameter names remain CollectionPane-side work.
- Final physical source placement may later fold `ScrollCollectionPane.cpp` into a broader scrollbar source file.
- The formal first-draft C++ follows accepted sibling visible-pane source style while documentation preserves the sentinel checks seen in the binary.

These caps justify `90/91`, not the current blank-C++ `85/88`.

## Report-Only No-Edit Proof (Historical)

- Target/support by-* docs were read only.
- No generated files, project-level files, manual `-coverage-report.md` files, validator/tool state, or IDA DB were edited.
- No leases were needed because the only created/edited file is this B001 report in `Agent-B001/research/`.

## Implementation Callback Proof

Implementation callback completed by Agent-B001 on 2026-06-26. Accepted target/support details were incorporated or confirmed as already present. Changed target/support docs:

- `by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md`
- `by-class/ScrollCollectionPane.md`
- `by-file/ScrollCollectionPane.md`
- `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`
- `by-type/by-struct/ScrollCollectionPaneLayout.md`

Lease proof: `tools/leaser/Agents/current_leases.md` showed no active leases before the edit batch. `python .\leaser.py B001 lease ...` from `tools/leaser` returned `Success` for the five edited by-* files. After validation, `python .\leaser.py B001 unlease ...` returned `Rejected[No active lease]` for each file because the short leases had already expired; a follow-up read of `tools/leaser/Agents/current_leases.md` showed no active B001 rows.

Validator proof:

- Target clean rerun: `python .\tools\validator.py --mode file --file by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md --apply --queue-timeout 240`; `command_id: 000000002878`; `command_timestamp: 2026-06-26T16:26:26-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`.
- Class support: `python .\tools\validator.py --mode file --file by-class/ScrollCollectionPane.md --apply --queue-timeout 240`; `command_id: 000000002882`; `command_timestamp: 2026-06-26T16:26:43-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`; warning: pre-existing `missing_ref_uid 0003MX` reported four times.
- File support: `python .\tools\validator.py --mode file --file by-file/ScrollCollectionPane.md --apply --queue-timeout 240`; `command_id: 000000002890`; `command_timestamp: 2026-06-26T16:26:58-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`.
- Aggregate support: `python .\tools\validator.py --mode file --file by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md --apply --queue-timeout 240`; `command_id: 000000002895`; `command_timestamp: 2026-06-26T16:27:14-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`; warning: pre-existing `missing_ref_uid 0003MX` reported four times.
- Layout support: `python .\tools\validator.py --mode file --file by-type/by-struct/ScrollCollectionPaneLayout.md --apply --queue-timeout 240`; `command_id: 000000002897`; `command_timestamp: 2026-06-26T16:27:34-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`.

The first target validator run `000000002869` reported `missing_ref_uid 0003YA` for an optional callback-page UID reference added during implementation. That optional UID-form reference was removed because [UID:0003YA] was not a required edited support doc, and the clean target rerun `000000002878` had no missing UID warning.

Generated refresh state: the scoped validators deferred generated refresh. Readback after validation showed `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp` at `validator-command-id: 000000002897`, equal to the latest scoped by-* validator, and containing the [UID:0001GX] generated C++ block. `auto-generated/-ag-coverage-report-by-memory.md` at `validator-command-id: 000000002896` contained the updated [UID:0001GX] row. `python .\tools\validator.py --queue-status` returned `command_id: 000000002913`, `queued generated refresh jobs: 13`, and `processing generated refresh jobs: 1`; no generated/project-level/manual coverage/tool-state files were manually edited.

## Implementation Tracking Checklist

- [x] Target metadata and formal C++: updated `by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md` to `90/91`, owner/emitter `0000CG`, position `80`, and inserted the exact accepted `ScrollCollectionPane::UpdatePositionFromCursor(int localY, int localX)` C++ block.
- [x] Target report-level details: added MCP session `80de0a67` evidence, caller/callee/xref/byte facts, two cursor/origin calls, sentinel checks, branch math, owner callback route, and updated score rationale in the target doc.
- [x] Target stale wording: replaced blank-C++ blocker language with current source-ready rationale and remaining confidence caps; old historical blank-C++ language was marked superseded where it remained useful as history.
- [x] Target field correction: corrected the drag-offset prose to `+0x108` with `localY` / `m_thumbDragOffset.y` and `+0x10c` with `localX` / `m_thumbDragOffset.x`.
- [x] Support class doc: updated `by-class/ScrollCollectionPane.md` method row, source-facing alias notes, point-order note, score rationale, and current [UID:0001GX] status.
- [x] Support file doc: updated `by-file/ScrollCollectionPane.md` proposed contents/source-ready notes for [UID:0001GX] while preserving the possible later [UID:0000NF] `ScrollBar` merge caveat.
- [x] Support aggregate doc: updated `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md` child row/status for [UID:0001GX] and preserved aggregate blank C++ so child method bodies are not duplicated.
- [x] Optional layout sync: updated `by-type/by-struct/ScrollCollectionPaneLayout.md` because implementation found stale/underspecified `+0x108/+0x10c` wording; metadata remained unchanged.
- [x] No forbidden manual edits: no generated/project-level files, manual `-coverage-report.md` files, validator/tool state, or IDA DB files were manually edited. Validator-owned generated/project-level/tool-state side effects were produced only by scoped validator commands and are recorded above.
- [x] Validators after implementation: ran all five scoped validators from `source-3/project-documentation`; command ids/timestamps/exits/ok counts and generated-refresh state are recorded in `Implementation Callback Proof`.
- [x] Update this checklist with exact paths, lease proof, validator command ids/timestamps/exits/ok counts, generated-refresh state, and excluded item proof. Proof recorded above; unchecked blockers: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001GX-ScrollCollectionPaneUpdatePositionFromCursor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0001GX-ScrollCollectionPaneUpdatePositionFromCursor-source-quality.md","timestamp":"2026-06-26T16:31:58","uid":"0001GX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
