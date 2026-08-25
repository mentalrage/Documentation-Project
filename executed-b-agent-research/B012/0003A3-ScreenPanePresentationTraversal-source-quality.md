** TARGET-REPORT-UID:0003A3 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003A3 ScreenPanePresentationTraversal Source-Quality Report

Assignment: B012-goal2-screen-pane-presentation-traversal-source-quality-0003A3-20260619

Status: ACTIVE CALLBACK-VERIFIED REPORT, ready for supervisor execution. This artifact now includes the report-only revalidation repair plus the implementation callback verification; B012 edited only the target by-memory file and this report, ran the allowed scoped target file validator, and did not run report-execution or lifecycle commands.

## Finalized Report / Current Recommendation

Keep [UID:0003A3] source-bearing and emitting under [UID:0000NB] `ScreenPane.cpp`. Current by-* and generated state already reflects the prior accepted implementation: target metadata is `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000NB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NB`; the target formal C++ block is populated with the ScreenPane method named `TraversePresentationList` and a dirty-output Region parameter; and generated `auto-generated/NexusTK/ui/core/ScreenPane.cpp` was refreshed by validator command `000000006876`.

No additional by-* edit is recommended for this report-only repair. If supervisor later sends an implementation callback, the expected work is verification-only unless the supervisor wants the target `## IDA MCP Evidence` prose refreshed from "local exported function data" to the current MCP session wording recorded here.

## Supporting Research

- Historical lifecycle status: this report was returned from executed archive because the active validator cache reported `target_uid_unknown: 0003A3`. Under the supervisor narrow override for this active repair copy, the top-level `REPORT-VALIDATION-STATUS: needs-revalidation` and `REPORT-REVALIDATION-REASON: target_uid_unknown: 0003A3` lines were removed from the report header and preserved here as historical context. The validator-owned `VALIDATOR-REPORT-HISTORY` footer remains unchanged.
- De-execution record preserved in footer: command `000000006873`, timestamp `2026-07-05T07:27:31-04:00`, returned the report to `tools/leaser/Agents/Agent-B012/research/0003A3-ScreenPanePresentationTraversal-source-quality.md` for rework.
- Supervisor scoped repair validator already ran: `python .\tools\validator.py --mode file --file by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md --apply --queue-timeout 240`, command `000000006876`, timestamp `2026-07-05T07:28:19-04:00`, exit `0`, `ok: 1`.
- Validator `000000006876` effects incorporated here: `path_update`, `completion_update 87`, `confidence_update 89`, `canonical_owner_update 0000NB`, `insert_header_blank`, autogen registry/projected stats updates, generated refresh deferred and completed into current auto-generated files. Remaining non-fatal sibling warnings are `missing_ref_uid` for `0003A1`, `00039Z`, `0003A0`, and `00039P`; they are adjacent-support index issues, not a UID0003A3 target blocker.
- Current generated proof after `000000006876`: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/ui/core/ScreenPane.cpp` all carry validator command id `000000006876` and include UID0003A3 at `87/89`.

## Target

- Target: `source-3/project-documentation/by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0003A3-ScreenPanePresentationTraversal-source-quality.md`
- Current target metadata: `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000NB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NB`; formal C++ is populated.
- Current direct parent: [UID:0000NB] `ScreenPane.cpp`, currently at least `87/87` in current support docs and auto-generated route.
- Related class parent: [UID:0000CB] `ScreenPane`, currently `87/90`.

## Current Target State

The target doc already contains the accepted source-quality state: UID0003A3 is reconstructable, code-emitting, emitted through [UID:0000NB] `ScreenPane.cpp`, and has the formal first-draft C++ body populated. The prior blank-C++ blocker is resolved; remaining caveats are naming confidence caps only.

Support docs are also already present at same-or-greater detail: `by-file/ScreenPane.md`, `by-class/ScreenPane.md`, `by-memory/0x00556910-0x00557132.ScreenPane.md`, Surface caller docs, Pane/Layer helper docs, and Region/Motion helper docs all name or cross-link the ScreenPane `TraversePresentationList` dirty-region method and preserve the ScreenPane owner route.

## Summary Recommendation

Keep [UID:0003A3] source-bearing and emitting under [UID:0000NB] `ScreenPane.cpp`. The current child-plus-parent gate is satisfied, and the stale "blank C++ because names are not final" reasoning has already been superseded by formal C++ in the target. The function is not compiler glue and not a no-code item.

Recommended source-facing name/signature in prose: the ScreenPane method named `TraversePresentationList`, with one dirty-output `Region` pointer parameter.

This name is descriptive, not proven original-source spelling. It is stronger than `HitTest`-style generic names or the stale generated `MapPane::meth_0x559410`, because the body traverses the root ScreenPane layer list, invokes Layer render/dirty helpers, and accumulates the dirty region that Surface presentation callers later blit.

Recommended score after implementation: `COMPLETION:87`, `CONFIDENCE:89`.

Reason for cap: ownership, range, caller roles, field roles, and first-draft C++ are now strong, but exact original method spelling and exact `ScreenLayerEntry`/Layer-node declaration remain inferred. Region/Motion helper naming is also historically split, so confidence should stay below final-source levels.

## Evidence Standards Used

- Current MCP evidence is mandatory for this repaired report. I used only bounded, schema-current calls against active database `supervisor_recovery_20260705`: `idb_list`, `server_health`, `lookup_funcs` with exact addresses, `xrefs_to` for `0x00559410`, `find` for code/data/immediate references to `0x00559410`, `find_bytes` for VA/RVA pointer patterns, `get_bytes` for bounded target windows, `decompile` for `0x00559410`, and `callees` for `0x00559410`.
- Local docs and generated reports are supporting evidence, not a substitute for MCP. Older fallback/no-MCP language is historical only and is superseded by the current MCP pass recorded below.
- Source naming remains descriptive unless proven original. The accepted source route is based on receiver fields, callers, support-doc precedent, and generated output after validator command `000000006876`.

## Evidence Checked

Current MCP session evidence:

- MCP listener/database state: `idb_list` returned one active session, `supervisor_recovery_20260705`, `NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, worker pid `19604`; `server_health` with `database=supervisor_recovery_20260705` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, imagebase `0x400000`.
- `lookup_funcs` exact-address results: `0x00559410` is `sub_559410` size `0x1ba`; `0x005595ca` is not a function; `0x005595d0` is adjacent `sub_5595D0` size `0x43f`.
- Related caller/support lookup results: `0x00557140` `sub_557140` size `0x237`; `0x005583a0` `sub_5583A0` size `0x2da`; `0x00559200` `sub_559200` size `0xa9`; `0x005592b0` `sub_5592B0` size `0xa9`; `0x00556d50` `sub_556D50` size `0x211`; `0x00554680` `sub_554680` size `0x61`; `0x005446e0` `sub_5446E0` size `0x26`; `0x00544980` `sub_544980` size `0x25`; Layer/helper callees `0x004f0f30`, `0x004f0f50`, `0x004f0f70`, `0x004f0f90`, `0x004f0fd0`, `0x004f0ff0`, and `0x004f1390` all resolve as modeled helpers/nullsub.
- `xrefs_to` and `find type=code_ref` for `0x00559410` returned exactly six code refs: `0x00556e9c`, `0x00556f0c`, `0x00557237`, `0x005584f5`, `0x00559258`, and `0x00559308`. `find type=data_ref`, `find type=immediate`, and `find_bytes` for pointer patterns `10 94 55 00` and `10 94 15 00` returned zero hits.
- `get_bytes` bounded reads confirmed the start bytes at `0x00559410` begin `55 8b ec 6a ff 68 5d 74 60 00 ...`, the pre-range `0x0055940c-0x00559410` is `cc cc cc cc`, and the function epilogue at `0x005595b0` ends with `5d c2 04 00` followed by padding before the next function.
- `decompile 0x00559410 include_addresses=false` succeeded with 68 pseudocode lines and no error. The preview identifies a `thiscall` target named `sub_559410` with the receiver and one pointer argument. The body calls `sub_554680`, `sub_5446E0`, `sub_544980`, walks `*(this + 268)` (`+0x10c`), swaps `this+24` from `this+264` (`+0x108`), ORs render results into `*(this + 1436)` (`+0x59c`), checks/clears `*(this + 280)` (`+0x118`), unions `this + 284` (`+0x11c`), and clears that rectangle.
- `callees 0x00559410 limit=80` returned sixteen callees with `more:false`: `sub_554680`, `sub_5446E0`, `sub_544980`, `sub_4F0F30`, `sub_4F0F90`, `sub_554820`, `sub_4B7C30`, `sub_4F0F50`, `sub_4F0F70`, `sub_4F0FD0`, `sub_4F0FF0`, `nullsub_11`, `sub_554800`, `sub_4B7C50`, `sub_4F4A90`, and `@__security_check_cookie@4`.

Local documentation and generated evidence checked:

- Target doc `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` is already `87/89`, ScreenPane-owned, reconstructable, and formal-C++ populated.
- `by-file/ScreenPane.md`, `by-class/ScreenPane.md`, `by-memory/0x00556910-0x00557132.ScreenPane.md`, Surface caller children, ScreenPane sibling children, Pane/Layer support pages, and Region/Motion support pages all already include the named route or support dependency at same-or-greater detail.
- Generated files after validator command `000000006876`: `auto-generated/NexusTK/ui/core/ScreenPane.cpp` emits UID0003A3 as the ScreenPane `TraversePresentationList` dirty-region method; `auto-generated/-ag-memory-coverage.md` routes UID0003A3 to `auto-generated/NexusTK/ui/core/ScreenPane.cpp`; `auto-generated/-ag-research-tracker.md` lists UID0003A3 as `87/89`; `auto-generated/-ag-coverage-report-by-memory.md` contains the UID0003A3 row updated at `2026-07-05 07:28:25`.

## Function Shape

Current MCP `lookup_funcs` confirms `0x00559410` is modeled as `sub_559410` size `0x1ba` / 442 bytes, with no function at exact end `0x005595ca` and adjacent `sub_5595D0` starting at `0x005595d0`. Current MCP `decompile` succeeds and is source-shaped:

- Constructs two stack `Region` objects through `0x00554680`.
- Calls Pane helpers:
  - `0x005446e0`: documented as `Pane::GetCurrentMotionRegion`.
  - `0x00544980`: documented as `Pane::SubtractMotionFromDirtyRegion`.
- Reads the root layer-list count through `*(this + 0x10c)->+0x0c`.
- Reverse-iterates the root list:
  - gets each entry through list vtable slot `+0x10`;
  - calls `0x004f0f30` to clear/reset node dirty state;
  - calls `0x004f0f90` to aggregate dirty/motion state;
  - unions the result into the caller's output region through `Motion::UnionWith` at `0x00554820`.
- Saves inherited `GrafPort +0x18`, replaces it with ScreenPane field `+0x108`, initializes a `(0,0)` point through `InitPointPair` at `0x004b7c30`, and forward-iterates the same layer list.
- During forward traversal it:
  - pushes each node's dirty region to the next node with `0x004f0f50` / `0x004f0f70`;
  - calls `0x004f0fd0`, documented as a dirty-node/propagate wrapper;
  - calls recursive render traversal `0x004f0ff0`;
  - ORs the returned byte into ScreenPane `+0x59c`;
  - calls `nullsub_11`, which is a no-op hook and should not be modeled as behavioral source.
- Restores inherited `GrafPort +0x18`.
- If byte `this+0x118` is set, it:
  - forces `this+0x59c = 1`;
  - unions the pending rectangle at `this+0x11c` into the caller's output via `Motion::UnionWithRect` at `0x00554800`;
  - clears `this+0x118`;
  - zeros the `this+0x11c` rectangle through `InitRectBounds` at `0x004b7c50`.
- Destroys both local Region/LObject temporaries via `0x004f4a90`.

This is normal source logic plus compiler EH/security-cookie scaffolding. It is not scalar-destructor glue, not a compiler helper, and not a no-code support row.

## Positive Evidence Summary

- MCP proves a live modeled target function at the exact range (`sub_559410`, size `0x1ba`) with a valid `ret 4` epilogue and padding before the adjacent function.
- MCP code xrefs match the documented six-call route: two `ScreenPane::HandleMessage` branches, two Surface presentation callers, and two ScreenPane transition wrappers.
- MCP decompile and callee evidence prove source-shaped ScreenPane traversal behavior over `+0x10c`, `+0x108`, `+0x118`, `+0x11c`, and `+0x59c`, with Pane/Layer/Region helper dependencies.
- Current target/support/generated docs already emit the ScreenPane `TraversePresentationList` dirty-region method through [UID:0000NB] `ScreenPane.cpp`.

## Negative Evidence Summary

- No MCP data refs, immediate refs, VA pointer hits, or RVA-style pointer hits to `0x00559410` were found; the route is ordinary direct code refs from the six documented callers.
- `0x005595ca` is not a function and the bytes after the epilogue are padding before adjacent `sub_5595D0`; there is no split/range blocker inside UID0003A3.
- `MapPane::meth_0x559410` remains rejected generated-owner/type pollution: current receiver fields and caller route are ScreenPane-shaped, not MapPane-owned.
- Surface, Pane, Layer, Region, and Motion are support/dependency contexts, not direct owners of this ScreenPane traversal method.

## Caller And Reachability Analysis

Current MCP `xrefs_to` and `find type=code_ref` xrefs to `0x00559410`:

- `0x00556e9c` and `0x00556f0c` inside `ScreenPane::HandleMessage` at `0x00556d50-0x00556f61`.
  - These are the fade/presentation message branches that construct a temporary Region, set transition state, call the traversal, then transition to states matching the retained helper wrappers.
  - Generated source still types this as `MapPane::meth_0x559410(reinterpret_cast<MapPane*>(&this[-1].field_0x50f), ...)`, but current ScreenPane docs and offsets show this is a generated view-adjustment/type-pollution artifact.
- `0x00557237` inside `SurfaceRenderPresentation`.
  - Surface owns the frame-present wrapper and consumes the dirty output from ScreenPane traversal.
- `0x005584f5` inside `SurfaceDrawTilePresentation`.
  - This is a Surface tile/shake/direct-blit presentation variant. It has no direct inbound caller itself, but it calls the same ScreenPane traversal.
- `0x00559258` and `0x00559308` inside `ScreenPanePresentationTransitionHelpers`.
  - These wrappers have no recovered direct callers/pointers, but their fields and bodies match `ScreenPane::HandleMessage` transition branches.

Caller roles support ScreenPane ownership:

- ScreenPane callers establish the receiver, fields, and state machine.
- Surface callers only request traversal and use the output dirty region for presentation/blitting.
- Transition helpers are ScreenPane wrappers over the same field family.
- There is no direct MapPane caller or MapPane field evidence for this body.

## Field And Type Recommendations

Use these names as source-facing descriptive names. They should be marked inferred unless a later symbol/source artifact proves original spellings.

| Offset | Recommended direction | Evidence |
| --- | --- | --- |
| `ScreenPane +0x10c` | `m_rootLayerList` / `m_screenLayerList`, type `List<ScreenLayerEntry *> *` or equivalent list of root layer entries | `ScreenPane::ScreenPane` allocates `List(4,4)` and stores it at `+0x10c`; layer-list helpers and `ScreenPaneLayerIndexLookup` operate through the same field. Target iterates count and get-at vtable slot. |
| `ScreenPane +0x108` | `m_presentationSurface` / `m_backBufferSurface` | Constructor clears it; destructor releases DirectDraw-style state; target swaps inherited `GrafPort +0x18` to this field while rendering root entries. Exact final name remains open. |
| inherited `GrafPort +0x18` | active render surface/context pointer | Pane/GrafPort layout docs identify this as inherited primary surface pointer; target saves/restores it around the forward render pass. |
| `ScreenPane +0x118` | `m_hasPendingDirtyRegion` / `m_dirtyRegionPending` | `ScreenCursorHelpers` `0x00557380` sets it and unions into `+0x11c`; target consumes and clears it. |
| `ScreenPane +0x11c` | `m_pendingDirtyRegion` / `m_pendingDirtyRect`, 16-byte rect/Region-style state | `ScreenCursorHelpers` merges caller rects into it via `0x004b7d70`; target unions it into the output and resets it with `InitRectBounds`. |
| `ScreenPane +0x59c` | `m_presentationDirty` / `m_frameDirty` | Target ORs recursive render return bytes into it and forces it for pending dirty regions. Surface presentation callers check this flag to decide whether a dirty blit/redraw is needed. |
| `ScreenPane +0x5a4/+0x5a8/+0x5ac` | presentation/transition state, payload/object pointer, transition delay/extent | Transition helpers and `HandleMessage` initialize/use this family; target itself is called while `+0x5a4` is set to traversal state `1`. |

Layer helper names to use descriptively:

- `0x004f0f30`: `LayerNode::ClearDirtyRegion` / `ResetPresentationDirtyRegion`.
- `0x004f0f90`: `LayerNode::CollectDirtyRegion`.
- `0x004f0f50`: `LayerNode::CopyDirtyRegion`.
- `0x004f0f70`: `LayerNode::UnionDirtyRegion`.
- `0x004f0fd0`: `LayerNode::PropagateDirtyNode` or retain current `dirty-node wrapper` until the Layer-node layout is audited.
- `0x004f0ff0`: `LayerNode::RenderRecursive` / `Layer::RenderNodeRecursive`.

The final `ScreenLayerEntry` type is still provisional. The target should not leave raw `cls_0x4f0f50` names in the recommended source text; use a descriptive local type placeholder and document it as the Layer presentation entry type.

## Heuristic / Inference Reanalysis And Validation

### Helper name and signature

Candidates considered:

- `ScreenPane::TraversePresentationList` with a dirty-output Region parameter - accepted. It matches the root list traversal, dirty region accumulation, and presentation pass without overclaiming the exact original name.
- `ScreenPane::PresentLayerList` with a dirty-output Region parameter - good alternative but slightly narrower toward drawing. The first reverse loop is dirty aggregation before drawing, so `TraversePresentationList` is safer.
- `ScreenPane::CollectPresentationDirtyRegions` with a dirty-output Region parameter - rejected as too narrow because the function also swaps the active render surface and performs recursive rendering.
- `ScreenPane::AnimatePresentation` with a dirty-output Region parameter - rejected. Old Wave2/MapPane-style naming is callsite-biased and not supported by current ScreenPane field/caller evidence.
- `MapPane::meth_0x559410` / `MapPane::AnimatePresentation` - rejected. The old Ghidra/OOAnalyzer label is generated-owner pollution. `MapPane +0x118` is a separate 32-entry deferred motion/dirty queue in current MapPane docs, while this function uses ScreenPane `+0x10c`, `+0x108`, `+0x118`, `+0x11c`, and `+0x59c`.

Recommended call boundary in prose: use a `thiscall` ScreenPane member named `TraversePresentationList` with one `Region` pointer dirty-output parameter.

Use `Region *` for the source-facing parameter. The callers construct `Region` stack objects, while the helper operations call `Motion::UnionWith` / `Motion::UnionWithRect` because the Region/Motion rectangle helper family shares the same four-int rectangle layout and historical generated naming. `Motion *` is mechanically defensible but source-style weaker for this call boundary.

### ScreenPane vs Pane ownership

Accepted owner: `ScreenPane.cpp`.

Pane is a dependency, not owner. The target calls `Pane::GetCurrentMotionRegion` and `Pane::SubtractMotionFromDirtyRegion`, and it inherits `GrafPort` fields from Pane, but the root list and presentation state are ScreenPane fields. `PaneCore` and `PaneLayout` already document these helpers as generic base infrastructure consumed by Layer and presentation traversal.

### Surface ownership

Rejected as direct owner. Surface presentation helpers call this method, but the receiver is the root ScreenPane. Surface remains the owner for `SurfaceRenderPresentation`, `SurfaceDrawTilePresentation`, callback tables, blit helpers, and display presentation policy. `ScreenPane::TraversePresentationList` is the ScreenPane dependency consumed by those Surface functions.

### Layer ownership

Rejected as direct owner. The target calls many Layer helpers and iterates root layer entries, but the target's receiver and state fields are ScreenPane. Layer owns `0x004f0fxx` and `0x004f15a0` helper implementations; ScreenPane owns the method that drives those helpers for the root screen.

### Region vs Motion naming

Do not block first-draft C++ on this. The local objects and callers are `Region`, and the docs attach the dirty-rectangle island to `Region.cpp` while retaining historical `Motion::...` helper names for rectangle operations. The target can use `Region` in the signature and local variables while documenting that union/copy methods are currently named through the Motion helper family.

### Nullsub behavior

`nullsub_11` at `0x004f1390` is an empty callback slot used after each render entry. It has no observable behavior in this target and should not block C++ readiness. In a first draft, either omit it or represent it as an optional no-op `entry->OnPresented()` only if local source style elsewhere models no-op hooks. I recommend omitting it from first-draft source and mentioning the binary no-op in evidence.

### Source placement

Route to `NexusTK/ui/core/ScreenPane.cpp` through [UID:0000NB]. This matches:

- `by-project-structure/proposed-source-tree.md`, which places `ScreenPane.cpp` under `ui/core`.
- ScreenPane constructor/destructor/root-layer list evidence.
- Sibling ScreenPane presentation helpers around `0x005590e0-0x005593a2`.
- Direct `g_pScreenPane` root object evidence.

The containing `SurfacePresentation` aggregate is a mixed physical neighborhood and should not be used as a source-owner shortcut.

## Ranked Ownership Analysis

| Rank | Candidate | Current disposition | Evidence |
| --- | --- | --- | --- |
| 1 | [UID:0000NB] `ScreenPane.cpp` | Accepted owner/emitter | MCP decompile shows ScreenPane field usage at `+0x10c`, `+0x108`, `+0x118`, `+0x11c`, and `+0x59c`; current target/support/generated docs already emit the method through `ScreenPane.cpp`. |
| 2 | [UID:0000OC] `Surface.cpp` | Rejected as direct owner; caller/consumer only | Surface render/draw helpers call the traversal and consume dirty output, but the receiver state is ScreenPane. |
| 3 | [UID:0000MC] `Pane.cpp` | Rejected as owner; base-helper dependency | Target calls Pane dirty/motion helpers and temporarily swaps inherited GrafPort state, but the root list and presentation state are ScreenPane fields. |
| 4 | [UID:0000KL] `Layer.cpp` | Rejected as direct owner; helper family dependency | Target invokes Layer-node dirty/render helpers while ScreenPane owns the root traversal driver. |
| 5 | [UID:0000L3] `MapPane.cpp` | Rejected generated-owner pollution | No current MCP caller/field evidence routes the method to MapPane; current docs reject `MapPane::meth_0x559410`. |

## Source Placement

Source placement remains `NexusTK/ui/core/ScreenPane.cpp` through [UID:0000NB]. This is already reflected by target metadata, `by-file/ScreenPane.md`, `by-class/ScreenPane.md`, generated memory coverage, research tracker, and generated `auto-generated/NexusTK/ui/core/ScreenPane.cpp` after validator command `000000006876`.

## First-Draft C++ Recommendation

The target is code-emitting, clears the current source-readiness gate, and already has this first-draft C++ populated in the target formal C++ block. Exact accepted `RECONSTRUCTION_CPP CODE` insertion text:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScreenPane::TraversePresentationList(Region *dirtyRegion)
{
    Region layerDirty;
    Region currentMotion;

    GetCurrentMotionRegion(&currentMotion);
    SubtractMotionFromDirtyRegion(&currentMotion);

    const int layerCount = m_rootLayerList->GetCount();
    const int lastLayer = layerCount - 1;

    for (int index = lastLayer; index >= 0; --index) {
        ScreenLayerEntry *entry = m_rootLayerList->GetAt(index);

        entry->ClearDirtyRegion();
        entry->CollectDirtyRegion(&layerDirty, &currentMotion);
        dirtyRegion->UnionWith(layerDirty);
    }

    void *savedSurface = m_grafPort.m_surface;
    m_grafPort.m_surface = m_presentationSurface;

    Point origin;
    InitPointPair(&origin, 0, 0);

    for (int index = 0; index < layerCount; ++index) {
        ScreenLayerEntry *entry = m_rootLayerList->GetAt(index);

        if (index < lastLayer) {
            ScreenLayerEntry *nextEntry = m_rootLayerList->GetAt(index + 1);

            entry->CopyDirtyRegion(&layerDirty);
            nextEntry->UnionDirtyRegion(layerDirty);
        }

        entry->PropagateDirtyNode();

        if (entry->RenderRecursive(this, origin.x, origin.y, &layerDirty, 0)) {
            m_presentationDirty = true;
        }
    }

    m_grafPort.m_surface = savedSurface;

    if (m_hasPendingDirtyRegion) {
        m_presentationDirty = true;
        dirtyRegion->UnionWithRect(&m_pendingDirtyRegion);
        m_hasPendingDirtyRegion = false;
        InitRectBounds(&m_pendingDirtyRegion, 0, 0, 0, 0);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Draft caveats:

- `ScreenLayerEntry` is a descriptive placeholder for the root layer/list entry object used by the `0x004f0fxx` helper family.
- `m_grafPort.m_surface` is the inherited `GrafPort +0x18` field. If the GrafPort page has a stronger final name, use that instead.
- `m_presentationSurface` is inferred from `ScreenPane +0x108`; final original member spelling remains open.
- `Region::UnionWith` / `Region::UnionWithRect` may currently be documented as `Motion::UnionWith` / `Motion::UnionWithRect`; the source draft should not expose raw `sub_554820` names.
- The compiler EH local construction/destruction and `__security_check_cookie` are omitted.

## Recommended Target Doc Changes

Callback verification found the target metadata, formal C++, behavior, field roles, caller route, ownership analysis, and rejected alternatives already present. The only target edit needed in this callback was the optional current-session MCP evidence refresh in `## IDA MCP Evidence`.

Current `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` has:

- metadata `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000NB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NB`;
- formal first-draft `RECONSTRUCTION_CPP` populated with the accepted ScreenPane `TraversePresentationList` dirty-region method;
- behavior, source-facing signature, field roles, caller route, ownership analysis, rejected MapPane/generated labels, and support cross-references at report-level detail;
- current-session MCP evidence citing `supervisor_recovery_20260705`, `server_health status:ok`, exact `lookup_funcs`, six code refs, zero data/immediate/pointer hits, bounded bytes, decompile/field proof, and the sixteen-callee list.

## Recommended Support Doc Changes

No support by-* edit is recommended for this report-only repair. Current support docs are already present:

- `by-file/ScreenPane.md` and `by-class/ScreenPane.md` name UID0003A3 as the ScreenPane `TraversePresentationList` dirty-region method, route it to `NexusTK/ui/core/ScreenPane.cpp`, document `+0x10c/+0x108/+0x118/+0x11c/+0x59c`, and reject stale MapPane ownership.
- `by-memory/0x00556910-0x00557132.ScreenPane.md` records the `HandleMessage` relationship and rejects the generated MapPane call view.
- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`, `by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md`, and `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md` already name UID0003A3 as the ScreenPane traversal dependency consumed by Surface presentation paths.
- `by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md`, `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`, Pane/Layer support docs, and Region/Motion support docs already carry the required dependency and field-role links.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage or tracker text is recommended. Validator commands already regenerated the current UID0003A3 entries in `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/NexusTK/ui/core/ScreenPane.cpp`; after callback validation, the generated headers show command `000000006882` for the memory/tracker/ScreenPane outputs and `000000006883` for the by-memory coverage report. B012 did not manually edit coverage or generated reports.

## Score And Metadata Recommendation

Keep the current target metadata unchanged:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000NB
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NB
```

The score remains capped below final-source levels because exact original method spelling, root layer-entry declaration, `+0x108` member spelling, and the Region/Motion helper naming split remain inferred. These are confidence caps, not C++ blockers.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0003A3-01 | Top-level validator status/reason lines are historical lifecycle state, not active Gate 1 status. | High | Supervisor override; footer command `000000006873`; this report body Supporting Research. | Report header; report `## Supporting Research`; footer history. | Remove top-level status/reason lines from active report, preserve footer unchanged, historicalize in body. | applied |
| C-0003A3-02 | UID0003A3 target exists and is current at `87/89`, owner/emitter `0000NB`, reconstructable true. | High | Target header; supervisor validator `000000006876`; generated memory coverage/research tracker command id `000000006876`. | Target metadata/header; generated route. | No by-* edit in this repair; verify current state. | already-present |
| C-0003A3-03 | Formal C++ is source-ready and populated with the accepted ScreenPane `TraversePresentationList` dirty-region method. | High | Target formal C++ block; generated `auto-generated/NexusTK/ui/core/ScreenPane.cpp` UID0003A3 body. | Target formal C++ block; generated ScreenPane.cpp. | No by-* edit in this repair; keep existing formal C++. | already-present |
| C-0003A3-03A | Report C++ text is project-rule compliant: the first-draft body appears only as exact formal `RECONSTRUCTION_CPP CODE` insertion text, and standalone prototype snippets are recast as prose. | High | Gate 1 repair instruction for SHA256 `C2B9662E6A4A04C8FC2382461710BA6D26AE99947D95653F95A9246B481876E0`; current `## First-Draft C++ Recommendation`. | Report `## First-Draft C++ Recommendation`; report prototype prose. | Replace bare `cpp` fence and prototype snippets in report only. | applied |
| C-0003A3-04 | Current MCP proves `0x00559410` is `sub_559410` size `0x1ba`, exact end `0x005595ca`, adjacent `sub_5595D0` at `0x005595d0`. | High | MCP `lookup_funcs` against `supervisor_recovery_20260705`; `server_health status:ok`; target `## IDA MCP Evidence` after callback. | Report evidence; target `## IDA MCP Evidence`. | Applied current-session MCP range/health/function-boundary wording to target. | applied |
| C-0003A3-05 | Current MCP proves six code refs and no data/immediate/pointer hits for `0x00559410`. | High | MCP `xrefs_to`, `find code_ref/data_ref/immediate`, `find_bytes` for `10 94 55 00` and `10 94 15 00`; target `## IDA MCP Evidence` and caller table after callback. | Report `## Evidence Checked`; target `## IDA MCP Evidence`; target caller/negative-evidence sections. | Applied zero-ref/pointer detail to target; six caller route was already present. | applied |
| C-0003A3-06 | Current MCP decompile/callees support the ScreenPane traversal behavior and field roles. | High | MCP decompile line evidence for `this+268`, `this+264`, `this+1436`, `this+280`, `this+284`; sixteen-callee list; target behavior/field tables after callback. | Report function shape/positive evidence; target `## IDA MCP Evidence`; target behavior/field roles. | Applied exact current decompile/callee wording to target; behavior and field-role docs were already present. | applied |
| C-0003A3-07 | Canonical owner/source placement is [UID:0000NB] `ScreenPane.cpp`, not Surface, Pane, Layer, or MapPane. | High | Target metadata; support docs; MCP receiver field evidence; generated `ScreenPane.cpp`. | Target owner/header; `by-file/ScreenPane.md`; `by-class/ScreenPane.md`; report ownership/source placement. | No support edit; verify current route and rank alternatives. | already-present |
| C-0003A3-08 | Surface presentation docs and transition/helper docs already reference UID0003A3 as a dependency/callee. | High | Current support docs named in Recommended Support Doc Changes. | Surface aggregate/caller docs; transition and cursor helper docs. | No support edit; verify current wording. | already-present |
| C-0003A3-09 | `000000006876` repaired the validator target mapping and refreshed generated outputs; remaining warnings are sibling `missing_ref_uid` issues. | High | Supervisor command metadata; generated file headers; goal.md assignment details. | Report Supporting Research; Validator Results; Open Questions. | Incorporate command id/timestamp/effects/warnings in report. | applied |
| C-0003A3-10 | Manual coverage/tracker edits are out of scope and unnecessary. | High | Generated coverage/tracker files already contain UID0003A3 after `000000006876`; direct user boundary. | Report exact manual coverage/tracker section; generated docs only as evidence. | Do not edit coverage/tracker files. | excluded-with-reason |

## Validator Results

The earlier report-only repair phase had no B012 scoped validation step. During the implementation callback, B012 ran the allowed scoped target file validator `000000006882`. Supervisor-provided and B012-run scoped validator results incorporated:

| Command | Timestamp | Exit | Ok | File | Effects | Warnings / side effects |
| --- | --- | --- | --- | --- | --- | --- |
| `000000006876` | `2026-07-05T07:28:19-04:00` | `0` | `1` | `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` | `path_update`, `completion_update 87`, `confidence_update 89`, `canonical_owner_update 0000NB`, `insert_header_blank`, autogen registry updates, projected stats update. | Remaining sibling `missing_ref_uid` warnings for `0003A1`, `00039Z`, `0003A0`, `00039P`; generated refresh deferred and visible in current auto-generated files. |
| `000000006882` | `2026-07-05T07:52:33-04:00` | `0` | `1` | `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` | Callback validator after target IDA MCP evidence refresh; `projected_stats_update:1`, `stats_incremental_noop:1`. | Known sibling `missing_ref_uid` warnings remain for `0003A1`, `00039Z`, `0003A0`, and `00039P`; generated refresh initially deferred, then current generated headers for `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/NexusTK/ui/core/ScreenPane.cpp` show command id `000000006882`; `auto-generated/-ag-coverage-report-by-memory.md` shows background generated refresh command id `000000006883`. |

No `execute_report`, dry-run/probing execute variant, lifecycle/archive/registry command, manual report move, coverage edit, generated edit, or validator-state edit was run by B012.

## Changed Files

- Changed directly by B012 during this callback: `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` and `tools/leaser/Agents/Agent-B012/research/0003A3-ScreenPanePresentationTraversal-source-quality.md`.
- Support docs verified already-present and not edited: `by-file/ScreenPane.md`, `by-class/ScreenPane.md`, `by-memory/0x00556910-0x00557132.ScreenPane.md`, `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`, `by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md`, `by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md`, `by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md`, `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`, Pane/Layer support docs, and Region/Motion support docs.
- Validator-generated/project side effects from command `000000006882`: `project-level/-auto-completion-stats.md` projected stats update and generated refresh headers at `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/NexusTK/ui/core/ScreenPane.cpp`; background generated refresh also left `auto-generated/-ag-coverage-report-by-memory.md` at command id `000000006883`. These were validator side effects, not manual edits.
- Not changed during this callback: support by-* docs, manual coverage reports, validator state files, lifecycle/archive files, supervisor ledgers, and manual report locations.

## Final Recommendation

READY for supervisor execution after callback verification. Keep UID0003A3 source-ready under [UID:0000NB] `ScreenPane.cpp` with score `87/89` and populated first-draft C++; the optional current-session MCP wording has now been added to the target evidence section and validated.

## IDA Rename / Type / Comment Recommendations

High confidence:

- Rename `sub_559410` to `ScreenPane::TraversePresentationList`.
- Prototype guidance recast as prose: use a `thiscall` ScreenPane member named `TraversePresentationList` with one dirty-output Region pointer parameter.
- Comment on `0x00559410`: "Root ScreenPane presentation traversal. Aggregates dirty regions from root layer entries, temporarily swaps inherited GrafPort surface to ScreenPane presentation surface, renders layer entries, consumes pending dirty rectangle `+0x118/+0x11c`, and sets presentation-dirty `+0x59c`."
- Type `ScreenPane +0x10c` as root layer list pointer.
- Type `ScreenPane +0x118` as pending dirty-region flag and `+0x11c` as pending dirty rectangle.
- Type `ScreenPane +0x59c` as presentation-dirty byte.

Medium confidence, descriptive:

- Name `ScreenPane +0x108` `m_presentationSurface` or `m_backBufferSurface`.
- Name `0x004f0f30` `LayerNode::ClearDirtyRegion`.
- Name `0x004f0f90` `LayerNode::CollectDirtyRegion`.
- Name `0x004f0f50` `LayerNode::CopyDirtyRegion`.
- Name `0x004f0f70` `LayerNode::UnionDirtyRegion`.
- Name `0x004f0fd0` `LayerNode::PropagateDirtyNode`.
- Name `0x004f0ff0` `LayerNode::RenderRecursive`.
- Treat the list element type as `ScreenLayerEntry *` or `LayerNode *` until the Layer-node layout pass finalizes it.

Rejected renames:

- Do not keep `MapPane::meth_0x559410`.
- Do not rename the target as a Surface method.
- Do not make the target a Pane method solely because it calls Pane dirty/motion helpers.

## Open Questions With Attempted Resolution

1. Exact original method spelling remains unknown.
   - Best supported direction: `TraversePresentationList`.
   - Impact: caps confidence below 90; does not block first-draft C++.

2. Exact list element type remains open.
   - Evidence checked: Layer aggregate docs, `ScreenPaneLayerIndexLookup`, target decompilation, and generated source.
   - Best supported direction: root ScreenPane layer-list entries are Layer/LayerNode presentation entries, not Pane objects directly.
   - Impact: use `ScreenLayerEntry` placeholder in draft C++; cap score below final-source.

3. Exact `+0x108` member name remains open.
   - Evidence checked: ScreenPane constructor/destructor, target GrafPort swap, Surface docs.
   - Best supported role: presentation/back-buffer surface pointer.
   - Impact: use descriptive member name; no ownership/C++ blocker.

4. Region vs Motion type name at the call boundary remains historically mixed.
   - Evidence checked: callers construct `Region`, helper names in docs are `Motion::UnionWith` and `Motion::UnionWithRect`, Region/Motion rectangle aggregate documents the split.
   - Best supported source boundary: `Region *dirtyRegion`.
   - Impact: no C++ blocker.

5. Sibling validator index warnings remain outside UID0003A3.
   - Evidence checked: supervisor validator command `000000006876` exited `0` / `ok:1` for the target but retained sibling `missing_ref_uid` warnings for `0003A1`, `00039Z`, `0003A0`, and `00039P`.
   - Impact: not a UID0003A3 Gate 1 blocker; leave for supervisor/sibling repair workflow.

## Implementation Tracking Checklist

- [x] Removed active top-level `REPORT-VALIDATION-STATUS` and `REPORT-REVALIDATION-REASON` lines under supervisor override while preserving the validator-owned history footer unchanged.
- [x] Historicalized the prior `target_uid_unknown: 0003A3` status/reason under `## Supporting Research`.
- [x] Replaced stale fallback/no-MCP language with current MCP-backed evidence from active database `supervisor_recovery_20260705`.
- [x] Incorporated supervisor validator command `000000006876`, timestamp, exit/ok state, target effects, generated refresh state, and remaining sibling warning list.
- [x] Verified current target metadata and formal C++ are already present after `000000006876`; no target by-* edit made by B012 in this repair.
- [x] Implementation callback verification: re-read the Claim And Incorporation Ledger, Recommended Target Doc Changes, Recommended Support Doc Changes, and this checklist before claim-by-claim by-* verification.
- [x] Verified current target metadata, owner/emitter `0000NB`, reconstructable state, and formal C++ are present at same-or-greater detail after `000000006876`.
- [x] Applied the optional current-session MCP evidence refresh to target `## IDA MCP Evidence`: session `supervisor_recovery_20260705`, health OK, exact lookup/range facts, six code refs, zero data/immediate/pointer hits, bounded bytes, decompile/field evidence, and sixteen-callee list.
- [x] Leased `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md` as B012 for the immediate target edit and released it after validation.
- [x] Ran scoped target validator: `python .\tools\validator.py --mode file --file by-memory\0x00559410-0x005595ca.ScreenPanePresentationTraversal.md --apply --queue-timeout 240`, command `000000006882`, timestamp `2026-07-05T07:52:33-04:00`, exit `0`, `ok:1`; known sibling `missing_ref_uid` warnings remained for `0003A1`, `00039Z`, `0003A0`, and `00039P`; generated refresh initially deferred and current generated headers show command id `000000006882`.
- [x] Verified support docs already carry the ScreenPane owner route and named dependency at same-or-greater detail; no support by-* edit made by B012 in this callback.
- [x] Formal-C++ repair: replaced the bare first-draft `cpp` fence with exact target `RECONSTRUCTION_CPP CODE` insertion text and recast standalone prototype snippets as prose.
- [x] Confirmed no generated files, coverage reports, validator state, lifecycle/archive files, supervisor ledgers, or manual coverage/tracker files were manually edited by B012; validator command `000000006882` produced generated/project side effects recorded above.
- [x] Confirmed B012 did run the allowed scoped target file validator `000000006882`, and did not run `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, manual report moves, generated/manual coverage edits, validator-state edits, or supervisor-ledger edits.
- [x] Current blocker status: no UID0003A3 evidence-backed blocker remains for Gate 1; remaining warnings are sibling `missing_ref_uid` diagnostics outside this target.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003A3","source_path":"executed-b-agent-research/B012/0003A3-ScreenPanePresentationTraversal-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B012","command_id":"000000006873","destination_path":"tools/leaser/Agents/Agent-B012/research/0003A3-ScreenPanePresentationTraversal-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B012/0003A3-ScreenPanePresentationTraversal-source-quality.md","timestamp":"2026-07-05T07:27:31-04:00"} -->
<!-- {"agent":"B012","command_id":"000000006890","destination_path":"executed-b-agent-research/B012/0003A3-ScreenPanePresentationTraversal-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0003A3-ScreenPanePresentationTraversal-source-quality.md","timestamp":"2026-07-05T08:05:54-04:00","uid":"0003A3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
