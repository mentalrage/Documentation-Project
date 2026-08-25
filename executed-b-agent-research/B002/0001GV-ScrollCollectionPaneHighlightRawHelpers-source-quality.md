** TARGET-REPORT-UID:0001GV **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Report: [UID:0001GV] ScrollCollectionPane Highlight Raw Helpers

## Report Metadata

- Assignment: `B002-report-0001GV-ScrollCollectionPaneHighlightRawHelpers-source-quality-20260627`
- Mode: report-only research
- Target: `[UID:0001GV] by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md`
- Required report path: `tools/leaser/Agents/Agent-B002/research/0001GV-ScrollCollectionPaneHighlightRawHelpers-source-quality.md`
- Agent: Agent-B002
- Date: 2026-06-27

## Target

`[UID:0001GV] by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md`

## Executive Recommendation

Keep `[UID:0001GV]` as a non-emitting split/index target with blank parent C++. Promote the exact children to source-ready helper bodies using accepted ScrollCollectionPane names: `[UID:0003MX]` should become `SetHighlightedPart`, and `[UID:0003MY]` should become `BeginPartInteraction`.

## Current Target State

`[UID:0001GV] by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md` is currently a non-emitting split/index target over two exact raw helper children:

- `[UID:0003MX] by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md`
- `[UID:0003MY] by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md`

The current target metadata is:

- `COMPLETION: 87`
- `CONFIDENCE: 90`
- `CANONICAL_OWNER: NONE`
- `RECONSTRUCTABLE: FALSE`
- `EMITTER_UIDS:` blank
- `RECONSTRUCTION_CPP:` blank

The target's non-emitting status is still correct. The parent range is not itself a source-level method because it is a contiguous raw block containing two separate source-shaped helper bodies plus adjacent padding. The exact children should own source reconstruction.

The target text is now stale in three important ways:

- It still describes the field names and child helper names as provisional even though accepted ScrollCollectionPane evidence now names `m_highlightPart`, `m_activePart`, `m_thumbDragOffset`, `GetPartRect`, `UpdateDragScroll`, `UpdatePositionFromCursor`, and `ResetScrollState`.
- It uses "Region" wording for helpers that are better represented as part/interaction helpers under the accepted `ScrollCollectionPart` vocabulary.
- It treats exact child C++ as blocked by naming uncertainty, but current project precedent and the live MCP recheck support first-draft C++ on the exact children while leaving this parent index blank.

Recommended post-implementation target metadata:

- `COMPLETION: 90`
- `CONFIDENCE: 91`
- `CANONICAL_OWNER: NONE`
- `RECONSTRUCTABLE: FALSE`
- `EMITTER_UIDS:` blank
- `RECONSTRUCTION_CPP:` blank

Recommended title/path rename for the parent, if the supervisor accepts path churn:

- From `by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md`
- To `by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneRawAndInteractionHelpers.md`

The rename better matches the range contents and the sibling pattern already used by `ScrollNewGroupPaneRawAndInteractionHelpers`.

## Supporting Research

## IDA MCP Availability And Recheck

IDA MCP was available and used. This is not a fallback-only report.

Observed MCP session:

- Server: `ida-pro-mcp`
- Protocol: `2025-06-18`
- Session id: `80de0a67`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x00400000`
- Auto-analysis ready: true
- Hex-Rays ready: true
- Strings cache ready: true

Live function-boundary findings:

- `0x00562e77`: not a function
- `0x00562e80`: not a function
- `0x00562eee`: not a function
- `0x00562ef0`: not a function
- `0x00562faf`: not a function
- `0x00562fb0`: `sub_562FB0`, size `0xc0`
- `0x00562bf0`: `sub_562BF0`, size `0x287`
- `0x00563070`: `sub_563070`, size `0x18d`

Live entity scan for `0x00562bc0-0x00563090` returned only:

- `0x00562bf0 sub_562BF0`
- `0x00562fb0 sub_562FB0`
- `0x00563070 sub_563070`

It did not return function objects at `0x00562e80` or `0x00562ef0`.

Live bytes confirm the split/padding:

- `0x00562e77-0x00562e80`: nine `0xcc` bytes before the first raw child.
- `0x00562e80-0x00562ef0`: exact first raw child, ending in `retn 4`.
- `0x00562ef0-0x00562fb0`: exact second raw child, ending in `retn 0Ch` followed by one `0xcc` byte at `0x00562faf`.
- `0x00562fb0`: start of modeled `sub_562FB0`.

## Supervisor Active Recheck

The live recheck confirms the current target still has raw starts at `0x00562e80` and `0x00562ef0`, no IDA function objects at either raw start, and no discovered direct static route to either raw start. It also confirms the byte boundaries and adjacent padding described by the existing target are materially correct.

## Inference Research Guidance Check

This report separates direct IDA observations from accepted project aliases and inferred source-facing names. The child C++ recommendation does not claim a recovered original symbol name; it uses source-quality names because the behavior, owner, fields, and helper calls are now stable enough for first-draft reconstruction under the current by-structure gate.

## Evidence Standards Used

- Live IDA MCP evidence was required and obtained.
- Raw helper liveness was checked through function lookup, xrefs, instruction ranges, byte boundaries, exact pointer search, and local PE control-flow/pointer scanning.
- Support-doc aliases were treated as accepted only when already established by current ScrollCollectionPane class/type/memory pages and executed B-agent reports.
- Inferred source names are explicitly marked as inferred and capped below final-audit confidence.

## Evidence Checked

- Current target and exact child by-memory pages.
- ScrollCollectionPane class, file, aggregate memory, layout, and vtable support pages.
- Accepted sibling/precedent pages for ScrollCollectionPane `UpdateDragScroll`, `UpdatePositionFromCursor`, `ResetScrollState`, ScrollVolumePane begin interaction, and ScrollNewGroupPane raw interaction helpers.
- Live MCP function lookup, entity scan, bytes, instruction ranges, xrefs, and exact pointer searches.
- Supplemental local PE scan for exact VA pointers, range-like RVA byte sequences, and direct control-flow hits.

## Function / Child Inventory

- Parent `[UID:0001GV]`: `0x00562e80-0x00562fb0`, non-emitting split/index target.
- Child `[UID:0003MX]`: `0x00562e80-0x00562ef0`, one-argument highlighted-part helper, `retn 4`.
- Child `[UID:0003MY]`: `0x00562ef0-0x00562fb0`, three-argument begin-interaction helper, `retn 0Ch`.
- Next modeled function: `0x00562fb0 sub_562FB0`, accepted as `ScrollCollectionPane::UpdateDragScroll`.

## Positive Evidence Summary

### Child 1: 0x00562e80-0x00562ef0

Live instruction query for `0x00562e80-0x00562ef0` returned 46 instructions, all outside any IDA function object. The first instruction is at `0x00562e80`; the last is at `0x00562eed`, followed by `retn 4`.

Important anchors:

- `0x00562e97`: reads `[esi+103h]`, the accepted `m_highlightPart`.
- `0x00562e9a`: compares the old highlight byte with the incoming part byte.
- `0x00562ea1`: compares old part against `0xff`, the accepted none sentinel.
- `0x00562eac`: calls `sub_562BF0`, accepted as `ScrollCollectionPane::GetPartRect`.
- `0x00562eb9`: calls vtable slot `+0x20`, consistent with invalidating the previous part rect.
- `0x00562ebc`: compares incoming part against `0xff`.
- `0x00562ec8`: calls `sub_562BF0` again for the incoming part.
- `0x00562ed5`: calls vtable slot `+0x20`, consistent with invalidating the new part rect.
- `0x00562ed8`: stores the incoming byte to `[esi+103h]`.
- `0x00562eed`: `retn 4`.

This is a complete source-shaped helper: if the requested part differs from the current highlighted part, invalidate the old highlighted part, invalidate the new highlighted part, then store the new highlighted part.

### Child 2: 0x00562ef0-0x00562fb0

Live instruction query for `0x00562ef0-0x00562fb0` returned 71 instructions, all outside any IDA function object. The first instruction is at `0x00562ef0`; the logical return is at `0x00562fac`, followed by one alignment byte at `0x00562faf`.

Important anchors:

- `0x00562f07`: compares incoming part with `2`, the accepted thumb part.
- `0x00562f0c`: reads `[esi+103h]`, the accepted `m_highlightPart`.
- `0x00562f16`: compares current highlight against `0xff`.
- `0x00562f21`: calls `sub_562BF0`, accepted as `GetPartRect`, for the previous highlighted part.
- `0x00562f2e`: invalidates the previous highlighted part rect through vtable slot `+0x20`.
- `0x00562f39`: calls `GetPartRect` for part `2`.
- `0x00562f46`: invalidates the thumb rect through vtable slot `+0x20`.
- `0x00562f49`: stores `2` to `[esi+103h]`, making the thumb highlighted.
- `0x00562f58`: calls `GetPartRect` for part `2` again to compute the drag origin.
- `0x00562f6b`: takes `[esi+108h]`, the accepted `m_thumbDragOffset`.
- `0x00562f72`: calls `sub_4B7C30`, matching the project point-pair initialization pattern.
- `0x00562f7c`: stores incoming part to `[esi+104h]`, the accepted `m_activePart`.
- `0x00562f82`: calls `sub_562FB0`, accepted as `ScrollCollectionPane::UpdateDragScroll`.
- `0x00562f92`: takes `[esi+0A4h]`, the timer/effect member used by this pane.
- `0x00562f98`: calls `sub_5975E0`, the timer/effect scheduling helper used elsewhere as `ScheduleTimer`.
- `0x00562fac`: `retn 0Ch`.

This is a complete source-shaped interaction starter: if the thumb is the active part, force the thumb into the highlighted state as needed, compute the thumb drag offset from local coordinates, store the active part, immediately update drag scrolling, then schedule the repeat update at 200 ms.

## Direct Xref / Caller Inventory

- `0x00562e80`: no incoming xrefs.
- `0x00562ef0`: no incoming xrefs.
- `0x00562faf`: no incoming xrefs.
- `0x00562fb0`: xrefs from `0x00562123`, `0x005621c8`, and the raw-child call at `0x00562f82`.
- `0x00562bf0`: xrefs include the two raw children, `UpdateDragScroll`, `UpdatePositionFromCursor`, and `ResetScrollState`; this supports the accepted `GetPartRect` role.

## Negative Evidence

The raw helper starts remain non-emitting entrypoint fragments, not independently routed IDA functions.

Live xref findings:

- `xrefs_to(0x00562e80)`: no incoming xrefs.
- `xrefs_to(0x00562ef0)`: no incoming xrefs.
- `xrefs_to(0x00562faf)`: no incoming xrefs.
- `xrefs_to(0x00562fb0)`: three xrefs:
  - `0x00562123` in `sub_561FB0`
  - `0x005621c8` in `sub_5621B0`
  - `0x00562f82` inside the second raw child

Exact absolute pointer searches for little-endian VAs found no hits for:

- `0x00562e80`
- `0x00562ef0`
- `0x00562fb0`

Supplemental local PE scanning against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` found no exact dword pointer hits to the raw child starts or to `0x00562fb0`. It found three range-like RVA byte sequences inside `sub_4639D0`, but follow-up instruction checks show they are incidental bytes inside instruction encodings/displacements, not typed data or control-flow references to this target range.

Direct branch scanning into `0x00562e80-0x00562fb0` found only internal conditional branches within the two raw child bodies. It did not find an external direct branch or call into `0x00562e80` or `0x00562ef0`.

This negative evidence caps confidence below final-audit levels and supports keeping the parent as non-emitting. It does not block exact child C++ because both children are bounded, source-shaped, and now have accepted class/field/helper names.

## Heuristic / Inference Reanalysis And Validation

The existing page's broad split interpretation is valid, but its naming/blocked-C++ conclusion is stale. Reanalysis supports keeping the parent blank while moving exact source bodies to the child pages.

## Inference Claim Ledger

### Claims That Are Directly Observed

- The parent range is split into two raw helper bodies at `0x00562e80` and `0x00562ef0`.
- Neither raw child has an IDA function object.
- The first child takes one argument and returns with `retn 4`.
- The second child takes three arguments and returns with `retn 0Ch`.
- The first child reads and writes offset `+0x103`.
- The second child reads and writes offset `+0x103`, writes offset `+0x104`, and initializes the point-like storage at `+0x108`.
- Both children call `sub_562BF0` to obtain part rectangles and invalidate through vtable slot `+0x20`.
- The second child calls `sub_562FB0` at `0x00562f82`.
- The second child schedules a repeat effect/timer through `sub_5975E0` with interval `0xc8`.

### Claims Supported By Accepted Project Evidence

- Offset `+0x103` is `m_highlightPart`.
- Offset `+0x104` is `m_activePart`.
- Offset `+0x108` is `m_thumbDragOffset`, with project point ordering `y, x`.
- Part value `2` is the thumb part.
- Part value `0xff` is the none sentinel.
- `sub_562BF0` is `ScrollCollectionPane::GetPartRect`.
- `sub_562FB0` is `ScrollCollectionPane::UpdateDragScroll`.
- `sub_563070` is `ScrollCollectionPane::UpdatePositionFromCursor`.
- The owning class is `[UID:0000CG] ScrollCollectionPane`.
- The source file bucket remains `[UID:0000NG] ScrollCollectionPane.md`, with the existing caveat that final upstream file placement may still be `ScrollBar.cpp` or a related pane source file.

### Claims That Remain Inferred

- Exact original method names are inferred from sibling naming and behavior. Recommended names are `SetHighlightedPart` and `BeginPartInteraction`, not because IDA stores those names, but because they best match accepted `ScrollCollectionPart` vocabulary and the analogous ScrollNewGroupPane/ScrollVolumePane documentation.
- `ScheduleTimer(0, 200, 0, 0)` is a source-facing wrapper name for the `this+0xa4`/`sub_5975E0` scheduling pattern. The call shape and existing ScrollVolumePane precedent support it, but IDA does not name this wrapper.
- The parent file rename to `ScrollCollectionPaneRawAndInteractionHelpers` is a documentation-quality recommendation, not a binary fact.

No claim in the recommended child C++ depends on an uninvestigated raw entrypoint route.

## Documentation Evidence And IDA Status

### ScrollCollectionPane Class

`[UID:0000CG] by-class/ScrollCollectionPane.md` already contains accepted ScrollCollectionPane names:

- `ScrollCollectionPart`
- `kScrollCollectionPartThumb`
- `kScrollCollectionPartNone`
- `m_highlightPart`
- `m_activePart`
- `m_thumbDragOffset`
- `GetPartRect`
- `HitTestScrollRegion`
- `UpdateDragScroll`
- `UpdatePositionFromCursor`

The class page still describes the `0x00562e80-0x00562fb0` row as "`SetHighlightedRegion / active-part drag setup`" and says some raw/manual helper names remain source-quality work. That should be updated after this report is accepted.

### ScrollCollectionPane File Bucket

`[UID:0000NG] by-file/ScrollCollectionPane.md` already owns the ScrollCollectionPane class bucket. It should be updated to say that the exact raw children in `0x00562e80-0x00562fb0` now have first-draft source bodies, while retaining the final source-file placement caveat.

### ScrollCollectionPane Aggregate Range

`[UID:0001GT] by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md` should continue to keep aggregate C++ blank. Its covered-function row for `0x00562e80-0x00562fb0` should be updated to identify the child owners as `SetHighlightedPart` and `BeginPartInteraction`.

### Layout And Type Support

`[UID:0001VZ] by-type/by-struct/ScrollCollectionPaneLayout.md` already names the relevant fields and part codes. It should not need a score change, but a short cross-reference note can be added if the supervisor wants the layout page to mention that `0003MX` and `0003MY` now consume those accepted aliases in first-draft C++.

### Vtable Support

`[UID:0001YP] by-type/by-vtable/ScrollCollectionPaneVtables.md` does not provide a vtable-dispatch route for these raw helper starts. It can remain unchanged unless the supervisor wants a short no-route note for the raw helper children.

### Generated Reports

The generated tracker/coverage rows are stale for `[UID:0001GV]`. The source page shows `87/90`, while generated coverage still showed an older `74/86` style row. Do not edit generated files manually. Let validators/regeneration update them during the implementation callback.

## Source Placement

The best current source placement is still the ScrollCollectionPane class/file bucket:

- Class owner/emitter: `[UID:0000CG] ScrollCollectionPane`
- File bucket: `[UID:0000NG] ScrollCollectionPane.md`

The final upstream source file name remains unresolved. Keep the existing file-placement caveat rather than asserting a final `ScrollCollectionPane.cpp` path.

## Range / Split / Padding / Reclassification Analysis

The range should not be collapsed into `sub_562FB0`, because `sub_562FB0` starts only at `0x00562fb0` and the live entity scan does not cover the two raw child starts as part of that function. It should not be treated as a single C++ method because `0x00562e80` and `0x00562ef0` each have their own prologue, stack frame, argument count, security-cookie check, and return. The existing split into two exact raw children is correct.

## Ranked Ownership And Source Disposition

### Rank 1: ScrollCollectionPane Direct Method Children

The exact raw children should be owned by `[UID:0000CG] ScrollCollectionPane` and emitted through that class:

- `[UID:0003MX]` should remain `CANONICAL_OWNER: 0000CG`, `RECONSTRUCTABLE: TRUE`, `EMITTER_UIDS: 0000CG`.
- `[UID:0003MY]` should remain `CANONICAL_OWNER: 0000CG`, `RECONSTRUCTABLE: TRUE`, `EMITTER_UIDS: 0000CG`.

Recommended emitter positions:

- `[UID:0003MX]`: `EMITTER_POSITION_OPTIONAL: 50`
- `[UID:0003MY]`: `EMITTER_POSITION_OPTIONAL: 60`

These positions place the interaction setup helpers before `[UID:0001GW] UpdateDragScroll` at position `70` and `[UID:0001GX] UpdatePositionFromCursor` at position `80`.

### Rank 2: Parent Non-Emitting Split Index

`[UID:0001GV]` should stay a non-emitting index:

- `CANONICAL_OWNER: NONE`
- `RECONSTRUCTABLE: FALSE`
- no emitter route
- no C++ block

Its job is to document the split, padding, route/liveness evidence, and child ownership.

### Rejected Alternatives

- Do not make `[UID:0001GV]` emit aggregate C++. That would duplicate the child methods and violate the project rule that parent aggregate/index targets do not re-emit child method bodies.
- Do not assign the raw child bodies to `UpdateDragScroll`. The second child calls `UpdateDragScroll`, but it performs pre-update interaction setup and scheduling.
- Do not leave the child bodies permanently blank solely because IDA lacks function objects at the raw starts. Current by-structure rules and accepted sibling precedent allow bounded C++ for exact raw children when source semantics are strong and the route caveat is documented.

## First-Draft C++ Recommendation

### Parent [UID:0001GV]

Do not add parent C++. The parent range is a non-emitting split index.

Recommended parent no-code proof:

```text
This target is a non-emitting split index for two exact raw ScrollCollectionPane interaction helpers. IDA still has no function objects or static entrypoint routes at 0x00562e80 or 0x00562ef0, and the source-shaped child bodies are owned by [UID:0003MX] and [UID:0003MY]. The parent intentionally keeps RECONSTRUCTION_CPP blank to avoid duplicating child source.
```

### Child [UID:0003MX]

Recommended child rename:

- From `0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md`
- To `0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedPartRaw.md`

Recommended formal C++:

```cpp
void ScrollCollectionPane::SetHighlightedPart(ScrollCollectionPart part)
{
    RectBounds rect;
    ScrollCollectionPart oldPart;

    oldPart = static_cast<ScrollCollectionPart>(m_highlightPart);
    if (oldPart == part) {
        return;
    }

    if (oldPart != kScrollCollectionPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }

    if (part != kScrollCollectionPartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }

    m_highlightPart = static_cast<signed char>(part);
}
```

Recommended child metadata after implementation:

- `COMPLETION: 89`
- `CONFIDENCE: 91`
- `CANONICAL_OWNER: 0000CG`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 0000CG`
- `EMITTER_POSITION_OPTIONAL: 50`

### Child [UID:0003MY]

Recommended child rename:

- From `0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md`
- To `0x00562ef0-0x00562fb0.ScrollCollectionPaneBeginPartInteractionRaw.md`

Recommended formal C++:

```cpp
void ScrollCollectionPane::BeginPartInteraction(ScrollCollectionPart part, int mouseY, int mouseX)
{
    RectBounds rect;

    if (part == kScrollCollectionPartThumb) {
        if (m_highlightPart != kScrollCollectionPartThumb) {
            if (m_highlightPart != kScrollCollectionPartNone) {
                GetPartRect(static_cast<ScrollCollectionPart>(m_highlightPart), &rect);
                InvalidateRect(&rect);
            }

            GetPartRect(kScrollCollectionPartThumb, &rect);
            InvalidateRect(&rect);
            m_highlightPart = static_cast<signed char>(kScrollCollectionPartThumb);
        }

        GetPartRect(kScrollCollectionPartThumb, &rect);
        InitPointPair(&m_thumbDragOffset, mouseY - rect.top, mouseX - rect.left);
    }

    m_activePart = static_cast<signed char>(part);
    UpdateDragScroll();
    ScheduleTimer(0, 200, 0, 0);
}
```

Recommended child metadata after implementation:

- `COMPLETION: 89`
- `CONFIDENCE: 91`
- `CANONICAL_OWNER: 0000CG`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 0000CG`
- `EMITTER_POSITION_OPTIONAL: 60`

The argument order follows the accepted project point convention and the already-accepted `UpdatePositionFromCursor` evidence: local/mouse Y is paired with `rect.top`, and local/mouse X is paired with `rect.left`.

## Score And Metadata Disposition

Recommended score changes if this report is implemented:

| UID | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `0001GV` | `87/90` | `90/91` | Live MCP recheck confirms split, boundaries, no-route status, accepted aliases, and child source disposition; parent remains non-emitting. |
| `0003MX` | `86/89` | `89/91` | Child now has accepted field/helper names and exact first-draft C++; no-route raw start still caps final confidence. |
| `0003MY` | `86/89` | `89/91` | Child now has accepted field/helper names and exact first-draft C++; no-route raw start still caps final confidence. |
| `0000CG` | `86/88` | `88/90` | Optional support update: class interaction-helper rows can now name and emit the exact children; final source-file placement remains unresolved. |
| `0000NG` | `86/85` | unchanged | File bucket remains useful but final upstream source-file placement is still unresolved. |
| `0001GT` | `85/88` | `87/90` | Optional support update: aggregate range can record that the exact raw children are now source-ready while keeping aggregate C++ blank. |
| `0001VZ` | `85/88` | unchanged | Layout names already support these helpers. |
| `0001YP` | `86/90` | unchanged | Vtable page does not own a dispatch route for these raw starts. |

All recommended scores remain below final-audit thresholds because the raw helper starts still have no direct static route, no IDA function objects, and no recovered original source declaration spelling.

## Final Recommendation

Implement the child source bodies and metadata updates during a supervisor-authorized implementation callback. Do not emit parent C++ for `[UID:0001GV]`; keep it as the no-route split index that explains why the children own reconstruction.

## Recommended Documentation Edits For Implementation Callback

### Target [UID:0001GV]

- Refresh status text to state that accepted names are no longer provisional.
- Record the live MCP no-function/no-xref/no-pointer-route evidence.
- Keep the parent non-emitting with blank C++.
- Rename the target to `ScrollCollectionPaneRawAndInteractionHelpers` if the supervisor accepts path churn.
- Update child links to the renamed child helper names.
- Update score to `90/91`.

### Child [UID:0003MX]

- Rename to `ScrollCollectionPaneSetHighlightedPartRaw`.
- Replace old "Region" wording with `Part` wording.
- Add the recommended `SetHighlightedPart` first-draft C++.
- Set `EMITTER_POSITION_OPTIONAL: 50`.
- Update score to `89/91`.
- Preserve a clear raw no-route caveat.

### Child [UID:0003MY]

- Rename to `ScrollCollectionPaneBeginPartInteractionRaw`.
- Replace old "active region" wording with `BeginPartInteraction` / active part wording.
- Add the recommended `BeginPartInteraction` first-draft C++.
- Set `EMITTER_POSITION_OPTIONAL: 60`.
- Update score to `89/91`.
- Preserve a clear raw no-route caveat.

### Support Docs

- `by-class/ScrollCollectionPane.md`: update the covered-method row and source notes for `SetHighlightedPart`, `BeginPartInteraction`, and their emitter positions; optional score update to `88/90`.
- `by-file/ScrollCollectionPane.md`: update proposed contents/source notes to include these source-ready child helpers; keep score unchanged.
- `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`: update the aggregate row for `0x00562e80-0x00562fb0`; optional score update to `87/90`; keep aggregate C++ blank.
- `by-type/by-struct/ScrollCollectionPaneLayout.md`: no required score change; optionally add a short cross-reference note tying `m_highlightPart`, `m_activePart`, and `m_thumbDragOffset` to the now source-ready raw children.
- `by-type/by-vtable/ScrollCollectionPaneVtables.md`: no required score change; optionally add a short note that these raw helper starts have no vtable-dispatch route.
- Generated tracker/coverage files: do not edit manually; refresh through validators.

## IDA Rename / Type / Comment Recommendations

Do not modify the IDA database as part of this report-only task.

If a later implementation pass allows IDA documentation changes, the useful non-invasive names would be:

- `0x00562e80`: `ScrollCollectionPane::SetHighlightedPart` raw helper label/comment, not necessarily an IDA function definition unless the supervisor explicitly authorizes function creation.
- `0x00562ef0`: `ScrollCollectionPane::BeginPartInteraction` raw helper label/comment, not necessarily an IDA function definition unless the supervisor explicitly authorizes function creation.

Because the current project state treats these as raw starts outside IDA function objects, documentation edits are sufficient for source reconstruction. Forced IDA function creation is not required for this recommendation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual generated coverage or tracker text should be edited. The only supervisor-owned manual coverage text recommended here is the by-* documentation listed in the implementation checklist. Generated tracker and coverage rows should refresh through validators after the by-* docs are changed.

## Open Questions And Resolutions

- Original upstream method names are not directly recoverable from IDA. Resolution: use `SetHighlightedPart` and `BeginPartInteraction` as source-facing names because they match accepted ScrollCollectionPane part vocabulary and sibling ScrollNewGroupPane precedent.
- The exact upstream file path is still not final. Resolution: continue using `[UID:0000NG] ScrollCollectionPane.md` as the emitter/source bucket and keep the existing `ScrollBar.cpp`/source-placement caveat.
- The raw helper entrypoint route is still not recovered. Resolution: preserve the no-route caveat and keep confidence below final-audit levels; do not let that block bounded child C++ under the current reconstruction gate.
- The generated tracker rows are stale. Resolution: do not manually edit generated files; validate/regenerate during implementation.

## Follow-Up Actions

The next action is a supervisor implementation callback. Until that callback exists, this report is complete and no by-* docs should be edited by Agent-B002.

## Confidence

High confidence in the range split, child behavior, field/helper aliases, and ownership. Moderate confidence in the exact source-facing method names because they are inferred from project naming precedent rather than recovered symbols. Confidence remains below final-audit level because there is still no static entrypoint route for the raw starts.

## Validator Results

No validators were run for this report-only pass because no by-* target or support documentation was edited.

The implementation callback should run file validators on every touched source doc and allow generated tracker/coverage rows to refresh.

## Changed Files In This Report-Only Pass

- Created `tools/leaser/Agents/Agent-B002/research/0001GV-ScrollCollectionPaneHighlightRawHelpers-source-quality.md`

No by-* target docs, support docs, generated docs, validator state, or IDA database state were changed.

## Implementation Checklist

- [x] Confirm supervisor implementation callback is present before editing any by-* target or support documentation.
  - Proof: callback assignment `B002-implement-0001GV-ScrollCollectionPaneHighlightRawHelpers-source-quality-20260627` is present in `tools/leaser/Agents/Agent-B002/goal.md` and names this accepted report plus the exact target, child, and support docs.
- [x] Rename or retitle `[UID:0001GV]` from `ScrollCollectionPaneHighlightRawHelpers` to `ScrollCollectionPaneRawAndInteractionHelpers`, if path churn is approved.
  - Proof: retitled/body-renamed in `by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md`; physical path intentionally left stable because moving three heavily cross-linked by-memory pages would create broad UID/ref/path churn during multi-agent work. The stable-path exclusion is documented in the target Status notes and accepted by validator command `000000004030`.
- [x] Update `[UID:0001GV]` metadata to `COMPLETION: 90`, `CONFIDENCE: 91`, `CANONICAL_OWNER: NONE`, `RECONSTRUCTABLE: FALSE`, blank `EMITTER_UIDS`, and blank `RECONSTRUCTION_CPP`.
  - Proof: applied in `by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md`; validator `python .\tools\validator.py --mode file --file "by-memory\0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md" --apply --queue-timeout 240 --wait-generated` passed on rerun with command_id `000000004030`, timestamp `2026-06-27T08:43:17-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Update `[UID:0001GV]` body with the live MCP boundary, padding, xref, pointer-search, and no-route evidence from this report.
  - Proof: `by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md` now has the `2026-06-27 B002 Source-Quality Implementation` section with MCP session `80de0a67`, exact raw starts, no function objects, padding, no xrefs, no pointer hits, supplemental PE scan, no external branch route, and child-disposition evidence; validator command `000000004030` passed.
- [x] Update `[UID:0001GV]` child summary to identify `[UID:0003MX]` as `SetHighlightedPart` and `[UID:0003MY]` as `BeginPartInteraction`.
  - Proof: target Covered Ranges, touched-state notes, reconstruction notes, and cross references identify `[UID:0003MX]` as `SetHighlightedPart` and `[UID:0003MY]` as `BeginPartInteraction`; validator command `000000004030` passed.
- [x] Rename or retitle `[UID:0003MX]` to `0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedPartRaw.md`.
  - Proof: retitled/body-renamed in `by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md`; physical path intentionally left stable for the same path-churn reason documented in the child Status notes. Validator command `000000004028` registered the stable path and passed.
- [x] Update `[UID:0003MX]` metadata to `COMPLETION: 89`, `CONFIDENCE: 91`, `CANONICAL_OWNER: 0000CG`, `RECONSTRUCTABLE: TRUE`, `EMITTER_UIDS: 0000CG`, and `EMITTER_POSITION_OPTIONAL: 50`.
  - Proof: applied in `by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md`; validator command `000000004028`, timestamp `2026-06-27T08:42:36-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`, recorded completion/confidence `89/91`, owner/emitter `0000CG`, position `50`, and C++ block metadata.
- [x] Insert the recommended `ScrollCollectionPane::SetHighlightedPart(ScrollCollectionPart part)` C++ block into `[UID:0003MX]`.
  - Proof: formal `RECONSTRUCTION_CPP CODE` block in `by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md` now contains the accepted `SetHighlightedPart` body only; validator command `000000004028` accepted the block and generated C++ emits it under UID `0003MX`.
- [x] Preserve `[UID:0003MX]` raw no-function/no-static-entrypoint caveat.
  - Proof: child Parent Gate/Reconstruction Notes and the 2026-06-27 MCP recheck preserve that `0x00562e80` has no IDA function object, no direct static route, and remains confidence-capped despite being eligible for child C++; validator command `000000004028` passed.
- [x] Rename or retitle `[UID:0003MY]` to `0x00562ef0-0x00562fb0.ScrollCollectionPaneBeginPartInteractionRaw.md`.
  - Proof: retitled/body-renamed in `by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md`; physical path intentionally left stable for documented path-churn risk. Validator command `000000004029` accepted the stable path.
- [x] Update `[UID:0003MY]` metadata to `COMPLETION: 89`, `CONFIDENCE: 91`, `CANONICAL_OWNER: 0000CG`, `RECONSTRUCTABLE: TRUE`, `EMITTER_UIDS: 0000CG`, and `EMITTER_POSITION_OPTIONAL: 60`.
  - Proof: applied in `by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md`; validator command `000000004029`, timestamp `2026-06-27T08:42:55-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`, recorded completion/confidence `89/91`, owner/emitter `0000CG`, position `60`, and C++ block metadata.
- [x] Insert the recommended `ScrollCollectionPane::BeginPartInteraction(ScrollCollectionPart part, int mouseY, int mouseX)` C++ block into `[UID:0003MY]`.
  - Proof: formal `RECONSTRUCTION_CPP CODE` block in `by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md` now contains the accepted `BeginPartInteraction` body only; validator command `000000004029` accepted the block and generated C++ emits it under UID `0003MY`.
- [x] Preserve `[UID:0003MY]` raw no-function/no-static-entrypoint caveat.
  - Proof: child Parent Gate/Reconstruction Notes and the 2026-06-27 MCP recheck preserve that `0x00562ef0` has no IDA function object, no direct static route, and remains confidence-capped despite being eligible for child C++; validator command `000000004029` passed.
- [x] Update `[UID:0000CG] by-class/ScrollCollectionPane.md` method/source notes for `SetHighlightedPart`, `BeginPartInteraction`, positions `50` and `60`, and optional score `88/90`.
  - Proof: `by-class/ScrollCollectionPane.md` now records the helper aliases, child emitter positions `50`/`60`, source-quality evidence, score rationale, and score `88/90`; validator command `000000004031`, timestamp `2026-06-27T08:43:34-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Update `[UID:0000NG] by-file/ScrollCollectionPane.md` source notes to include the source-ready raw child helpers while keeping score unchanged.
  - Proof: `by-file/ScrollCollectionPane.md` proposed contents/source notes include `[UID:0003MX]` and `[UID:0003MY]` as source-ready raw child helpers; score remains `86/85`; validator command `000000004032`, timestamp `2026-06-27T08:43:49-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Update `[UID:0001GT] by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md` aggregate row and optional score `87/90`, while keeping aggregate C++ blank.
  - Proof: aggregate row/evidence now records the exact raw children, source-ready child bodies, no-route facts, and blank aggregate C++; score is `87/90`; validator command `000000004033`, timestamp `2026-06-27T08:44:09-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Optionally update `[UID:0001VZ] by-type/by-struct/ScrollCollectionPaneLayout.md` with a short cross-reference note; keep score unchanged.
  - Proof: `by-type/by-struct/ScrollCollectionPaneLayout.md` now ties `m_highlightPart`, `m_activePart`, and `m_thumbDragOffset` to `[UID:0003MX]`/`[UID:0003MY]`, including the accepted point order; score remains `85/88`. First validator command `000000004034` hit a transient generated-file `PermissionError` on unrelated `auto-generated\NexusTK\social\BlockListenInputPanes.cpp`; retry command `000000004035`, timestamp `2026-06-27T08:44:47-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Optionally update `[UID:0001YP] by-type/by-vtable/ScrollCollectionPaneVtables.md` with a short no-vtable-route note; keep score unchanged.
  - Proof: `by-type/by-vtable/ScrollCollectionPaneVtables.md` now records that `[UID:0003MX]`/`[UID:0003MY]` have no pointer/vtable/data/direct branch/call route and that invalidation dispatch is a vtable consumer, not a route; score remains `86/90`. Validator command `000000004039`, timestamp `2026-06-27T08:52:55-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`; it also added reference indexes for `0003MX` and `0003MY`. The existing `missing_ref_uid 0003CN` diagnostics are unrelated to this callback.
- [x] Run the file validator on the renamed/updated `[UID:0001GV]` target doc.
  - Proof: initial command `000000004027` at `2026-06-27T08:42:15-04:00` passed but saw `0003MX` before its UID registration; after child validation, rerun `python .\tools\validator.py --mode file --file "by-memory\0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md" --apply --queue-timeout 240 --wait-generated` returned command_id `000000004030`, timestamp `2026-06-27T08:43:17-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`, and no target-specific missing child UID.
- [x] Run the file validator on the renamed/updated `[UID:0003MX]` child doc.
  - Proof: `python .\tools\validator.py --mode file --file "by-memory\0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md" --apply --queue-timeout 240 --wait-generated` returned command_id `000000004028`, timestamp `2026-06-27T08:42:36-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Run the file validator on the renamed/updated `[UID:0003MY]` child doc.
  - Proof: `python .\tools\validator.py --mode file --file "by-memory\0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md" --apply --queue-timeout 240 --wait-generated` returned command_id `000000004029`, timestamp `2026-06-27T08:42:55-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Run the file validator on every touched support doc: class, file, aggregate, layout, and vtable docs as applicable.
  - Proof: class command `000000004031` (`2026-06-27T08:43:34-04:00`), file command `000000004032` (`2026-06-27T08:43:49-04:00`), aggregate command `000000004033` (`2026-06-27T08:44:09-04:00`), layout retry command `000000004035` (`2026-06-27T08:44:47-04:00`), and vtable command `000000004039` (`2026-06-27T08:52:55-04:00`) all exited `0` with `ok: 1` and `generated_refresh: completed`.
- [x] Confirm generated tracker/coverage rows refresh through validator output; do not edit generated files manually.
  - Proof: every successful scoped validator above reported `generated_refresh: completed` with a matching command id/timestamp; generated/project-level and validator-state side effects were validator-owned only. No manual edits were made to `auto-generated/**`, generated `project-level/**`, manual `-coverage-report.md`, validator/tool state, or the IDA DB.
- [x] Recheck that generated C++ emits `SetHighlightedPart` and `BeginPartInteraction` through `[UID:0000CG]` and does not emit duplicate parent code for `[UID:0001GV]`.
  - Proof: read-only check of `auto-generated\NexusTK\ui\core\ScrollCollectionPane.cpp` showed header `validator-command-id: 000000004043`, `validator-refreshed-at: 2026-06-27T08:53:47-04:00`, which is newer than the final scoped validator command `000000004039`. The file contains UID `0003MX` `ScrollCollectionPane::SetHighlightedPart` and UID `0003MY` `ScrollCollectionPane::BeginPartInteraction`; `Select-String` count for `UID:0003MX|UID:0003MY|SetHighlightedPart|BeginPartInteraction` was `4`, and count for `0001GV|0x00562e80-0x00562fb0|ScrollCollectionPane Raw And Interaction Helpers` was `0`.
- [x] Recheck that no unrelated user or other-agent edits were reverted.
  - Proof: no destructive git/filesystem commands or revert commands were used. Manual edits were scoped to the accepted target/support by-* docs and this Agent-B002 report checklist; broad generated/project-level changes came from validator refreshes and were not hand-edited or reverted. `git status --short` is noisy with many unrelated/generated project changes, so no status-driven cleanup was attempted.
- [x] Release leases after edit/validator batches and confirm no active B002 lease remains.
  - Proof: after the by-* validator batch, `python .\leaser.py B002 unlease` from `tools/leaser` returned `B002: No active leases`; `tools/leaser/Agents/current_leases.md` showed active leases only for other agents (`B004`/`B007` at that read), with no `B002` entry. This report checklist update is inside Agent-B002's own `research/` folder, where the workflow does not require a lease.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001GV-ScrollCollectionPaneHighlightRawHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001GV-ScrollCollectionPaneHighlightRawHelpers-source-quality.md","timestamp":"2026-06-27T08:59:32","uid":"0001GV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
