*** UID:0000KL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Layer

## Status

- Confidence: strong for class behavior, source ownership, and `ui/core` placement; medium for the not-yet-final `LayerNode` field layout.
- Proposed module: `ui/core/Layer.cpp`
- Projected reconstruction folder: `NexusTK/ui/core/`
- Main address range: `0x004f0480-0x004f1bf6`

## File Role

`Layer` owns the pane tree used for z-ordering, clipping, dirty-region propagation, motion updates, and recursive rendering. It is the bridge between UI pane ownership and render traversal.

The strongest current source-structure placement is `ui/core/Layer.cpp` because `Pane` attach/remove methods are direct API users, the constructor fan-in includes reusable UI setup paths, and `../by-project-structure/proposed-source-tree.md` groups `Layer` with `Pane`, `RectBounds`, `Region`, `DialogPane`, `ControlPane`, and `ScreenPane`. A render-side split remains a secondary caveat because `RenderRecursive` and dirty-region traversal are render-facing and use `MapPane`, `Motion`, and `Region`.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `Layer` | `0x004f0480-0x004f1bf6` | Tree of pane nodes with bounds, clip bounds, flags, dirty state, and optional motion/region data. |
| `LayerNode` local struct | inferred | Per-node pane pointer, child tree, bounds/clip, flags, dirty state, and `Region`/`Motion` slot. |

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction/tree ownership | `0x004f0480`, `0x004f1b40` | Root node allocation and destructor/delete path. |
| Child insertion/removal | `0x004f0630-0x004f0b3d` | Add after, add before, remove child, child-tree teardown. |
| Flags and motion | `0x004f0b80-0x004f0f81` | Node flags, containment, move propagation, root dirty region helpers. |
| Dirty/render traversal | `0x004f0f90-0x004f1905` | Build dirty region and recursively render/update child nodes. |
| Search helpers | `0x004f1910-0x004f1b31` | Recursive node lookup and node metadata helpers. |

## Evidence Notes

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

## Changes

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
