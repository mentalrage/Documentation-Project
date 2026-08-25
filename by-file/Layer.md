*** UID:0000KL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Layer

## Current Implemented Source Root

- Applied score: `91/93`; projected folder remains `NexusTK/ui/core/`.
- Declaration-first emission: [UID:000073][Layer](by-class/Layer.md) emits at position 10, followed by 24 source-authored children [UID:0004NR][0x004f0480-0x004f0597.LayerConstructor](by-memory/0x004f0480-0x004f0597.LayerConstructor.md) through [UID:0004OE][0x004f1ab0-0x004f1b32.LayerFindPaneNode](by-memory/0x004f1ab0-0x004f1b32.LayerFindPaneNode.md) at positions 20 through 250 in exact address/source order.
- [UID:0004OF][0x004f1b40-0x004f1bf6.LayerScalarDeletingDestructor](by-memory/0x004f1b40-0x004f1bf6.LayerScalarDeletingDestructor.md) is compiler-only, non-emitting, and has no position. [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md) is a non-emitting 25-child index.
- The generated source must therefore contain one Layer declaration and exactly one definition for each of the 24 source methods, with no aggregate Empty Emitter Marker, scalar wrapper body, vtable body, explicit base teardown, or duplicate method.

## Current File Role And Placement

`Layer.cpp` owns the reusable pane hierarchy: root/list lifetime, add/insert/remove, masked flags and accessors, dirty-region aggregation, recursive rendering, parent/offset lookup, recursive propagation/cleanup/search, and the source no-op EndRender hook. The exact LayerNode payload and HierList row layout are class-private implementation facts, while generic HierList and Region/Motion bodies stay in their own files.

The former `ui/core` versus render split caveat is closed. Pane is the public API client, ScreenPane drives presentation, MapPane contributes one effect branch, and HierList/Region/Motion/GrafPort are dependencies. Application startup, MainMenuPane, WorldMapPane, packet construction, and FlyingParcelPane own Layer instances or invoke lifecycle methods but do not own Layer source.

## Current Evidence And History

The unique Layer RTTI/vtable, eight-byte receiver, contiguous `[0x004f0480,0x004f1bf6)` class island, direct caller/callee graph, and current project tree support this source root. Twenty-five exact child bodies are now registered: 24 source members and one compiler scalar wrapper. The three raw members are retained despite zero xrefs because their complete ABIs, shared private lookup, field offsets, and class-order placement prove source membership. `Layer::MarkAllPanesForDeletion` is independently corroborated by B002 UID0002AF, and `Layer::EndRender` is a direct ordinary call, not optional virtual glue.

Original PDB/private spelling and exact header-versus-implementation placement of LayerNode remain confidence caps. Historical 22-modeled-function, unresolved-layout, and possible render-split statements below predate this implemented split and are not current blockers.



## Historical Pre-Split Status

- Confidence: strong for class behavior, source ownership, and `ui/core` placement; medium for the not-yet-final `LayerNode` field layout.
- Proposed module: `ui/core/Layer.cpp`
- Projected reconstruction folder: `NexusTK/ui/core/`
- Main address range: `0x004f0480-0x004f1bf6`

## Historical Pre-Split File Role

`Layer` owns the pane tree used for z-ordering, clipping, dirty-region propagation, motion updates, and recursive rendering. It is the bridge between UI pane ownership and render traversal.

The strongest current source-structure placement is `ui/core/Layer.cpp` because `Pane` attach/remove methods are direct API users, the constructor fan-in includes reusable UI setup paths, and `../by-project-structure/proposed-source-tree.md` groups `Layer` with `Pane`, `RectBounds`, `Region`, `DialogPane`, `ControlPane`, and `ScreenPane`. A render-side split remains a secondary caveat because `RenderRecursive` and dirty-region traversal are render-facing and use `MapPane`, `Motion`, and `Region`.

[UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) / `ScreenPane::TraversePresentationList(Region *dirtyRegion)` is the current named ScreenPane caller that drives the root layer-list dirty aggregation and recursive render traversal through the Layer helper family. This supports the Layer-node helper roles while keeping ScreenPane as caller/owner of the traversal method and Layer as owner of the node/tree helpers.

## Historical Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `Layer` | `0x004f0480-0x004f1bf6` | Tree of pane nodes with bounds, clip bounds, flags, dirty state, and optional motion/region data. |
| `LayerNode` local struct | inferred | Per-node pane pointer, child tree, bounds/clip, flags, dirty state, and `Region`/`Motion` slot. |

## Historical Pre-Split Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction/tree ownership | `0x004f0480`, `0x004f1b40` | Root node allocation and destructor/delete path. |
| Child insertion/removal | `0x004f0630-0x004f0b3d` | Add after, add before, remove child, child-tree teardown. |
| Flags and motion | `0x004f0b80-0x004f0f81` | Node flags, containment, move propagation, root dirty region helpers. |
| Dirty/render traversal | `0x004f0f90-0x004f1905` | Build dirty region and recursively render/update child nodes. |
| Search helpers | `0x004f1910-0x004f1b31` | Recursive node lookup and node metadata helpers. |

## Historical Pre-Split Evidence Notes

- The class and memory docs identify `Layer` as an 8-byte object with an `LObject` base plus an owned tree pointer.
- IDA MCP reports `Layer::AddChildAfter` and `AddChildBefore` are directly called by `Pane` layer attach/insert methods.
- IDA MCP confirms the layer tree operations call [UID:0000JV][HierList](by-file/HierList.md): add-after calls `HierList::InsertAfter`, add-before calls `HierList::InsertBefore`, and remove-child calls the `0x004ceb00` HierList remove helper.
- IDA MCP reports `Layer::Layer` has a smaller constructor caller set, including repeated startup/map setup call sites and `MapPane` construction.
- 2026-06-06 IDA MCP recheck confirms key function anchors and sizes for the constructor `0x004f0480-0x004f0597`, child insertion/removal helpers at `0x004f0630`, `0x004f0840`, and `0x004f0a60`, recursive render traversal at `0x004f0ff0`, dirty/motion propagation at `0x004f15a0`, scalar deleting destructor at `0x004f1b40-0x004f1bf6`, and the next non-Layer function at `0x004f1c00`.
- The same caller/callee pass shows `Pane` add/insert/remove wrappers as the direct public API callers, HierList insert/remove functions as the backing container operations, and vtable writes at `0x004f04ba`, `0x004f05c9`, and `0x004f1b70` for the Layer vtable base `0x0061ca48`.
- [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md) now carries the full 22-function aggregate map, boundary padding, vtable, caller/callee, Pane, HierList, and Region/Motion evidence; this by-file page summarizes that source ownership rather than duplicating every method body.
- MapPane setup constructs `Layer` for map/render setup, so final placement should be revisited if later evidence favors a render-side split.

## Cross-References

- [UID:000073][Layer](by-class/Layer.md)
- [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000JV][HierList](by-file/HierList.md)
- [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md)

## Changes

- 2026-06-21 B012 ScreenPanePresentationTraversal support sync:
  - Score unchanged at `86/86`.
  - Added [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) / `ScreenPane::TraversePresentationList(Region *dirtyRegion)` as the named caller for root layer-list dirty aggregation and recursive render traversal, preserving Layer ownership of the helper family.
- 2026-06-06 A004 by-file evidence refresh:
  - Before: the by-file page remained at `82/78`, used a file-shaped projected-path label, and did not reflect the stronger 2026-06-05 aggregate memory evidence.
  - After: raised to `86/86`, corrected the displayed projected folder to `NexusTK/ui/core/`, expanded the `ui/core` placement rationale, and added live IDA evidence for function anchors, Pane API callers, HierList callees, vtable writes, and the aggregate memory page.
  - Evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, and `xrefs_to` confirm the constructor, insertion/removal helpers, render/dirty traversal anchors, scalar deleting destructor boundary, Pane integration, HierList backing operations, and Layer vtable references. Completion/confidence stay below final-audit quality because the `LayerNode` field layout and exact render-side split are not fully closed.
- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/core/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank while the document carried an open `ui/core` versus `render` folder caveat.
  - After: set the validator path to `NexusTK/ui/core/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `Layer.cpp` under `ui/core`, and live IDA MCP lookup on 2026-06-05 confirms the constructor anchor at `0x004f0480` as a real function of size `0x117`.
### 2026-05-28 - Corrected Layer terminal byte

- What existed before: `Layer` file-level contents listed the aggregate range as `0x004f0480-0x004f1bf5`.
- What changed: the aggregate range now ends at `0x004f1bf6`.
- Evidence: IDA MCP shows `sub_4F1B40` ending at `0x004f1bf6`; `0x004f1bf5` is the final byte of the scalar deleting destructor's `retn 4`, while `0x004f1bf6-0x004f1c00` is alignment before `InputPaneBases`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: pane tree role, method families, `HierList` relationships, constructor callers, MapPane/render placement caveat, and terminal-byte correction are documented; completion/confidence are capped by missing deeper per-method behavior, inferred `LayerNode` layout, and unresolved `ui/core` versus `render` placement.
