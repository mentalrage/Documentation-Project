*** UID:0000PB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# WorldMapPane

## Status

- Confidence: strong for `map/WorldMapPane.cpp` as a separate source module.
- Proposed module folder: `map/`
- Candidate file: `map/WorldMapPane.cpp`
- Current generated sources: `class_WorldMapPane.cpp`, `class_WorldMapNodeEntryVector.cpp`, and `class_WorldMapReachabilityBitSet.cpp`.
- Evidence basis: Wave3/simroot metadata and targeted IDA MCP boundary/caller checks on 2026-05-23 and 2026-05-24.

## Hypothesis

`WorldMapPane` is a separate world-map/travel UI module, not a continuation of `MapPane.cpp`. It renders the large world map, hit-tests destination nodes and special regions, computes reachable destinations from a graph, animates viewport/travel motion through the frame callback system, and sends travel packet `0x6E` to the server.

The likely original structure was:

```text
map/WorldMapPane.cpp
map/WorldMapPane.h
```

with private helper storage classes either declared in the same file or in a small internal header:

- `WorldMapNodeEntryVector`
- `WorldMapReachabilityBitSet`

## Proposed Contents

| Entity | Current range | Current file | Proposed ownership |
| --- | --- | --- | --- |
| `WorldMapPane` | `0x005c2ac0-0x005c569a` | `class_WorldMapPane.cpp` | Main world-map UI source. |
| `WorldMapNodeEntryVector` | `0x005c5510-0x005c5a8e` | `class_WorldMapNodeEntryVector.cpp` | Private storage helper for 0x94-byte node records. |
| `WorldMapReachabilityBitSet` | `0x005c56a0-0x005c5c87` | `class_WorldMapReachabilityBitSet.cpp` | Private dynamic bitset used by reachability building. |

## Behavior Summary

- Constructor loads map assets, seeds node data, centers the initial view, and builds reachable-node state.
- Draw path renders the background sprite, nodes, labels, reachability coloring, and the player marker.
- Input path handles keyboard navigation, mouse hover, click-to-travel, and drag-to-scroll.
- Frame update path advances smooth viewport and travel-marker animation through the frame registry.
- Reachability path uses a BFS-like scan from the current node to determine which destinations can be selected.
- Travel path sends a compact server packet with the selected map node.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `0x005c2ac0-0x005c32aa` constructor has callers from `0x0050f270` and `0x00511db0`, matching MapPane-driven world-map creation.
- `0x005c3950-0x005c3e41` draw method is a real function and calls common sprite/rectangle render helpers. A 2026-05-25 recheck shows calls at `0x005c3b60` and `0x005c3db0` into [UID:000166][0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md), which should stay under [UID:0000OC][Surface](by-file/Surface.md).
- `0x005c4bd0-0x005c5075` reachability builder calls `0x005c5b20` and `0x005c56a0`, tying the helper bitset to WorldMapPane.
- The reachability builder also calls [UID:0000FD][UInt32Vector](by-class/UInt32Vector.md) fill construction at `0x00514a10` for temporary dword-vector state; the vector implementation belongs with [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md).
- `0x005c5510-0x005c557a` vector destructor is called by `WorldMapPane::~WorldMapPane`.
- `0x005c56a0-0x005c584b` bitset insert helper is called by `BuildReachabilityData`.
- A 2026-05-24 follow-up checked `0x004b6d00` and `0x004b6d20`: they are generic frame-registry wrappers over `FrameMgr::Insert` / `FrameMgr::RemoveFrame`, with broad callers from living-object/effect/world-map paths. They should not be treated as WorldMapPane-owned source even though the generated WorldMap file emits them as `RegisterFrameCallback` and `StopAnimation`.

IDA also confirmed that Wave3's `WorldMapPane` method at `0x00590053` is not an IDA function. That is documented as data debt in [wave3_data_issues](../wave3_data_issues.md) and should not be used for file ownership.

## Relationship To Other Modules

- [UID:0000L3][MapPane](by-file/MapPane.md) owns the server packet handler that creates or shows `WorldMapPane`.
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md) owns the generic frame callback scheduler used by world-map animation.
- `WorldMapPane` consumes render and packet-manager globals but does not own those generic systems.

## Open Questions

- Whether `WorldMapNodeEntryVector` and `WorldMapReachabilityBitSet` were named local structs/classes or compiler-generated STL-like helper expansions in the original source.
- Exact world-map packet field layout needs a later `by-item` or packet-specific `by-memory` page.

## Cross-References

- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md)
- [UID:0000G8][WorldMapNodeEntryVector](by-class/WorldMapNodeEntryVector.md)
- [UID:0000GA][WorldMapReachabilityBitSet](by-class/WorldMapReachabilityBitSet.md)
- [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)

## Changes

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/map/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented world-map constructor anchor at `0x005c2ac0`; proposed-source-tree keeps the travel/world-map UI under `map/`, separate from generic `MapPane.cpp` and frame-registry infrastructure.

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `90/86`. Summary/evidence: the page gives a detailed source-structure hypothesis, helper-class ownership, behavior summary, targeted IDA MCP evidence, cross-module boundaries, and open questions, supporting a high but not complete grade.
