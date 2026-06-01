*** UID:0000KG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ItemObjectPane

## Status

- Confidence: strong for `ItemObjectPane` and `FlyingObjectPane` as item-object companions.
- Proposed module: `map/ItemObjectPane.cpp`
- Current generated sources: `class_ItemObjectPane.cpp`, `class_FlyingObjectPane.cpp`
- Primary class docs: [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md), [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md)
- Main address doc: [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)

## File Role

`ItemObjectPane.cpp` likely owns item-shaped map objects: static ground item panes and the temporary flying/thrown item pane used during launch, impact, and drop flows.

This should stay separate from [UID:0000M5][ObjectPane](by-file/ObjectPane.md). The base file owns common object-pane state; this file owns item image selection, item hit/action drawing, and item projectile animation.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ItemObjectPane` | `0x00537b40-0x00537c65`, destructor at `0x0053d2e0` | Ground item object with item glyph centering and item-image dispatch. |
| `FlyingObjectPane` | `0x00537cb0-0x005380af`, destructor at `0x0053d1a0` | Temporary flying/thrown item object with arc bounds, timer stepping, impact sound/effects, and drop/removal handling. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Ground item creation | `0x00537b40` | Constructed by [UID:0000L3][MapPane](by-file/MapPane.md) object creation at `0x00505e00`. |
| Item drawing bounds | `0x00537bf0`, `0x00537c70` | Centers item glyphs on map tiles and delegates item drawing to the item image library. |
| Flying object creation | `0x00537cb0` | Called by MapPane packet/update handlers at `0x0050dfa0` and `0x00512d60`. |
| Flying object animation | `0x00537d80`, `0x00537f20` | Computes arc bounds and handles timer-driven position updates, impact animation, sound, and final object drop/removal. |

## Boundary Notes

- The constructor/virtual cluster is contiguous from `0x00537b40` through `0x005380af`; scalar deleting destructors are in the nearby object-pane destructor island at `0x0053d1a0` and `0x0053d2e0`.
- IDA confirms `0x0050dfa0` as a real FlyingObjectPane constructor caller, but Wave3 currently reports it as unknown. Treat that caller as MapPane-side evidence until ownership is repaired.
- Do not merge these classes into [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md). `FlyingObjectPane` derives through the item/object path and uses item glyphs; attached overlays derive through attached object behavior.
- 2026-05-26 IDA static-pool review identifies [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) for `ItemObjectPane` at `0x0069b9ac` and `FlyingObjectPane` at `0x0069b9d4`.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed exact function starts/ranges for:

- `0x00537b40-0x00537b91`, `0x00537bf0-0x00537c65`, `0x00537c70-0x00537ca2`
- `0x00537cb0-0x00537d60`, `0x00537d80-0x00537f1d`, `0x00537f20-0x005380af`
- `0x0053d1a0-0x0053d237`, `0x0053d2e0-0x0053d377`

## Cross-References

- [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md)
- [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md)
- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:82`.
  - Summary/evidence: item/flying object pane roles, constructor/destructor anchors, method families, MapPane caller evidence, object-pane boundary, static-pool globals, and exact IDA ranges are documented; completion is lower because source-form detail for animation/drop flows is still summarized.
