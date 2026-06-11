*** UID:0000KG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ItemObjectPane

## Status

- Confidence: strong for `ItemObjectPane` and `FlyingObjectPane` as item-object companions, their exact executable anchors, vtable-store evidence, and static pool ownership; medium-high for final field names and exact source spelling.
- Proposed module: `map/ItemObjectPane.cpp`
- Projected reconstruction path: `NexusTK/map/ItemObjectPane.cpp`
- Primary class docs: [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md), [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md)
- Main address doc: [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- Vtable data: [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md), [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md)
- Static pool storage: [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md), [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md)
- Parent gate: this file now clears the corrected `85/85` direct-parent gate for [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md) and other independently refreshed item-object children.

## File Role

`ItemObjectPane.cpp` likely owns item-shaped map objects: static ground item panes and the temporary flying/thrown item pane used during launch, impact, and drop flows.

This should stay separate from [UID:0000M5][ObjectPane](by-file/ObjectPane.md). The base file owns common object-pane state; this file owns item image selection, item hit/action drawing, and item projectile animation.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ItemObjectPane` | `0x00537b40-0x00537c65`, destructor at `0x0053d2e0` | Ground item object with item glyph centering and item-image dispatch. |
| `FlyingObjectPane` | `0x00537cb0-0x005380af`, destructor at `0x0053d1a0` | Temporary flying/thrown item object with arc bounds, timer stepping, impact sound/effects, and drop/removal handling. |
| Item/flying vtable data | `0x006203f0`, `0x00620460`, `0x00620490` in [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md); `0x0062049c`, `0x0062050c`, `0x0062053c` in [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md) | Compiler-emitted tables regenerated from the item and flying class declarations. |
| Static pools | `0x0069b9ac-0x0069b9d4`, `0x0069b9d4-0x0069b9fc` | Source-declared pool storage for ground item and flying item panes. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Ground item creation | `0x00537b40` | Constructed by [UID:0000L3][MapPane](by-file/MapPane.md) object creation at `0x00505e00`. |
| Item drawing bounds | `0x00537bf0`, `0x00537c70` | Centers item glyphs on map tiles and delegates item drawing to the item image library. |
| Flying object creation | `0x00537cb0` | Called by MapPane packet/update handlers at `0x0050dfa0` and `0x00512d60`. |
| Flying object animation | `0x00537d80`, `0x00537f20` | Computes arc bounds and handles timer-driven position updates, impact animation, sound, and final object drop/removal. |
| Destruction and pool free | `0x00537ba0`, `0x00537d60`, `0x0053d1a0`, `0x0053d2e0` | Non-deleting cleanup shims restore vtables and delegate to `ObjectPane`; scalar deleting destructors use the per-class pool gates. |

## Boundary Notes

- The constructor/virtual cluster is contiguous from `0x00537b40` through `0x005380af`; scalar deleting destructors are in the nearby object-pane destructor island at `0x0053d1a0` and `0x0053d2e0`.
- IDA confirms `0x0050dfa0` as a real FlyingObjectPane constructor caller. Treat that caller as MapPane-side evidence until ownership is repaired.
- Do not merge these classes into [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md). `FlyingObjectPane` derives through the item/object path and uses item glyphs; attached overlays derive through attached object behavior.
- 2026-05-26 IDA static-pool review identifies [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) for `ItemObjectPane` at `0x0069b9ac` and `FlyingObjectPane` at `0x0069b9d4`.
- The 2026-06-07 item/flying executable audit separates the physically adjacent `0x00537bc0-0x00537be9` LivingObjectPane-linked helper from item/flying ownership; keep that as locality evidence only.
- Confirmed padding after the current cluster is `0x005380af-0x005380b0`, immediately before [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md).

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed exact function starts/ranges for:

- `0x00537b40-0x00537b91`, `0x00537bf0-0x00537c65`, `0x00537c70-0x00537ca2`
- `0x00537cb0-0x00537d60`, `0x00537d80-0x00537f1d`, `0x00537f20-0x005380af`
- `0x0053d1a0-0x0053d237`, `0x0053d2e0-0x0053d377`

The later [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md) audit adds omitted in-range starts `0x00537ba0`, `0x00537bc0`, and `0x00537d60`, confirms constructor callers at `0x00505e8f`, `0x0050e09b`, and `0x00512ebe`, records item-image/tile and MapPane helper refs, and documents the exact padding around the item/flying cluster.

## Corrected Parent Gate Audit

- Current file-root score after Batch 089: `COMPLETION:85`, `CONFIDENCE:86`.
- Direct child now eligible: [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md), refreshed to `85/88`.
- Assignment basis: `ItemObjectPane.cpp` is the direct source root for the ground item and flying item map-object companions because the method cluster, vtable data, destructor island, and pool storage all distinguish item/flying objects from base `ObjectPane`, attached overlays, and MapPane caller-side packet handling.
- Remaining caveat: this file still needs final field naming, source-ready method names, and final C++ for item glyph and flying-item motion behavior, so it stays below high-audit scores and emits no reconstruction body here.

## Cross-References

- [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md)
- [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md)
- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md)
- [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md)
- [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md)
- [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)

## Changes

- 2026-06-05: Assigned projected reconstruction path `NexusTK/map/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree both place `ItemObjectPane.cpp` under `map/`.
  - After: set the validator path to `NexusTK/map/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `ItemObjectPane.cpp` under `map`, and live IDA MCP lookup on 2026-06-05 confirms the `ItemObjectPane` constructor anchor at `0x00537b40` as a real function of size `0x51`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:82`.
  - Summary/evidence: item/flying object pane roles, constructor/destructor anchors, method families, MapPane caller evidence, object-pane boundary, static-pool globals, and exact IDA ranges are documented; completion is lower because source-form detail for animation/drop flows is still summarized.
- 2026-06-07 Batch 089 parent-gate refresh:
  - Before: `COMPLETION:82`, `CONFIDENCE:82`; the page had a valid `NexusTK/map/` path but was below the corrected direct-parent gate for [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md).
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: incorporated the current item/flying executable audit, vtable-data evidence, destructor-island support, and exact item/flying pool-storage pages. The file now documents why it is the direct source root for the refreshed FlyingObjectPane class while preserving the MapPane caller boundary and the LivingObjectPane-adjacent helper caveat.
