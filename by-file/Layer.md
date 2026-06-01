*** UID:0000KL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Layer

## Status

- Confidence: strong for class behavior, medium for final folder (`ui/core` versus `render`).
- Proposed module: `ui/core/Layer.cpp` or `render/Layer.cpp`
- Current recovered source: `source-3/simroot_v2/class_Layer.cpp`
- Main address range: `0x004f0480-0x004f1bf6`

## File Role

`Layer` owns the pane tree used for z-ordering, clipping, dirty-region propagation, motion updates, and recursive rendering. It is the bridge between UI pane ownership and render traversal.

The strongest current source-structure placement is `ui/core/Layer.cpp` because `Pane` attach/remove methods are its direct API users. A `render/Layer.cpp` placement remains plausible because `RenderRecursive` and dirty-region traversal are render-facing and use `MapPane`, `Motion`, and `Region`.

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

- Wave3 metadata says `Layer` is an 8-byte object with `LObject` plus a tree pointer.
- IDA MCP reports `Layer::AddChildAfter` and `AddChildBefore` are directly called by `Pane` layer attach/insert methods.
- IDA MCP confirms the layer tree operations call [UID:0000JV][HierList](by-file/HierList.md): add-after calls `HierList::InsertAfter`, add-before calls `HierList::InsertBefore`, and remove-child calls the `0x004ceb00` HierList remove helper.
- IDA MCP reports `Layer::Layer` has a smaller constructor caller set, including repeated startup/map setup call sites and `MapPane` construction.
- Generated `MapPane.cpp` constructs `Layer` for map/render setup, so final placement should be revisited when `MapPane` is documented.

## Cross-References

- [UID:000073][Layer](by-class/Layer.md)
- [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000JV][HierList](by-file/HierList.md)

## Changes

### 2026-05-28 - Corrected Layer terminal byte

- What existed before: `Layer` file-level contents listed the aggregate range as `0x004f0480-0x004f1bf5`.
- What changed: the aggregate range now ends at `0x004f1bf6`.
- Evidence: IDA MCP shows `sub_4F1B40` ending at `0x004f1bf6`; `0x004f1bf5` is the final byte of the scalar deleting destructor's `retn 4`, while `0x004f1bf6-0x004f1c00` is alignment before `InputPaneBases`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: pane tree role, method families, `HierList` relationships, constructor callers, MapPane/render placement caveat, and terminal-byte correction are documented; completion/confidence are capped by missing deeper per-method behavior, inferred `LayerNode` layout, and unresolved `ui/core` versus `render` placement.
