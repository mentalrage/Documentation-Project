*** UID:0000PB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# WorldMapPane

## Layer Source-Boundary Synchronization - 2026-07-14

WorldMapPane.cpp contains the client/factory path that constructs a Layer at `0x0050f326`; Layer.cpp owns the called constructor and hierarchy implementation. The owned instance relationship does not move LayerNode, HierList, Region, dirty/render, or destructor code into WorldMapPane.cpp. The current `92/93` file state preserves this boundary while adding the complete constructor/class/global source union.

## Status

- Confidence: very strong for `NexusTK/map/WorldMapPane.cpp` as a separate source module, its exact executable children, and the standard-container source disposition of the former custom-helper labels.
- Proposed module folder: `map/`
- Candidate file: `map/WorldMapPane.cpp`
- Historical stale generated artifacts used `class_WorldMapPane.cpp`, `class_WorldMapNodeEntryVector.cpp`, and `class_WorldMapReachabilityBitSet.cpp`; current reconstruction routes the source-bearing definition through this one `NexusTK/map/` emitter.
- Evidence basis: current by-* state, live IDA MCP boundary/caller/field/container checks, B001's exact source split, and the UID0003SR behavior-complete callback.

## Hypothesis

`WorldMapPane` is a separate world-map/travel UI module, not a continuation of `MapPane.cpp`. It renders the large world map, hit-tests destination nodes and special regions, computes reachable destinations from a graph, animates viewport/travel motion through the frame callback system, and sends travel packet `0x6E` to the server.

The likely original structure was:

```text
map/WorldMapPane.cpp
map/WorldMapPane.h
```

using ordinary standard-library members `std::vector<WorldMapNode>`, `std::vector<bool>`, `std::vector<int>`, and function-local `std::deque<int>`. The historical `WorldMapNodeEntryVector` and `WorldMapReachabilityBitSet` labels remain documentation navigation facades for compiler-generated specialization bodies; they are not separate human source files or classes.

## Proposed Contents

| Entity | Current range | Current file | Proposed ownership |
| --- | --- | --- | --- |
| `WorldMapPane` | [UID:0003SC][0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup](by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md) through [UID:0003SW][0x005c5200-0x005c53d0.WorldMapPaneHitTestSpecialRegions](by-memory/0x005c5200-0x005c53d0.WorldMapPaneHitTestSpecialRegions.md), plus [UID:0003T3][0x005c5660-0x005c569b.WorldMapPaneScalarDeletingDestructor](by-memory/0x005c5660-0x005c569b.WorldMapPaneScalarDeletingDestructor.md) | `class_WorldMapPane.cpp` | Main world-map UI source. |
| `std::vector<WorldMapNode>` specialization support | [UID:0003SZ][0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor](by-memory/0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor.md), [UID:0003T7][0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign](by-memory/0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign.md), [UID:0003T8][0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation](by-memory/0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation.md) | none | Non-emitting old-MSVC/Dinkumware specialization bodies for exact 0x94-byte node records; regenerate from ordinary `std::vector` source and the selected toolchain. |
| `std::vector<bool>` specialization support | [UID:0003SX][0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits](by-memory/0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits.md), [UID:0003T0][0x005c5580-0x005c55d7.WorldMapReachabilityBitSetPositionHelper](by-memory/0x005c5580-0x005c55d7.WorldMapReachabilityBitSetPositionHelper.md), [UID:0003T1][0x005c55e0-0x005c563c.WorldMapReachabilityBitSetResolveIterator](by-memory/0x005c55e0-0x005c563c.WorldMapReachabilityBitSetResolveIterator.md), [UID:0003T4][0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits](by-memory/0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits.md), [UID:0003T5][0x005c5850-0x005c58a9.WorldMapReachabilityBitSetShrinkToBitCount](by-memory/0x005c5850-0x005c58a9.WorldMapReachabilityBitSetShrinkToBitCount.md), [UID:0003T9][0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator](by-memory/0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator.md), [UID:0003TA][0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange](by-memory/0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange.md) | none | Non-emitting old-MSVC/Dinkumware `vector<bool>` reserve/iterator/insert/shrink/erase specialization bodies; regenerate from ordinary standard-container source. |
| compiler/runtime helpers | [UID:0003SY][0x005c5500-0x005c550b.WorldMapPaneSingletonClearCleanupThunk](by-memory/0x005c5500-0x005c550b.WorldMapPaneSingletonClearCleanupThunk.md), [UID:0003T2][0x005c563c-0x005c565d.WorldMapPaneAdjustorThunks](by-memory/0x005c563c-0x005c565d.WorldMapPaneAdjustorThunks.md), [UID:0003T6][0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0](by-memory/0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0.md) | none | Non-emitting cleanup/thunk/runtime support regenerated by compiler/runtime semantics. |

## Complete Constructor, Class, And Global Source Union

- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md) now supplies the complete `0x298` declaration with `Pane`, direct `FrameHandler`, empty `Singleton<WorldMapPane>` EBO, five `EPFTileContext` members, palettes, view/navigation/travel state, exact `0x94` `WorldMapNode`, standard containers, natural padding, all method declarations, and the class closed before `[[CHILDREN]]`.
- [UID:0003SC][0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup](by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md) emits the sole complete constructor. Its eight explicit inputs are map name, signed node count/current index, node positions/names, destination map IDs/positions, and copied directed adjacency.
- The constructor owns map-name detach/uppercase, value-initialized node records, deep copies, copied `std::vector<bool>`, exact EPF/PAL versus EPD/PAD branches, player/current view initialization, clamp/invalidate/BFS/timer order, and front/back boat resources. It intentionally retains branch duplication and performs no absent resource/input/index/graph guard.
- [UID:0004T9][g_pWorldMapPane](by-global/g_pWorldMapPane.md) emits the sole file-scope `WorldMapPane *g_pWorldMapPane = 0;` definition. [UID:00029E][0x0069b454-0x0069b458.g_pWorldMapPane](by-memory/0x0069b454-0x0069b458.g_pWorldMapPane.md) is loader-zero-filled physical storage and emits only a covered-storage comment.
- UID00035H vtable/RTTI data, UID00035I resource literals, and UID00035J numeric constants are non-reconstructable evidence pages. The compiler and linker regenerate them from class and method source; no raw vtable, RTTI, string, or numeric table is handwritten.
- The exact executable family keeps ordinary source-bearing children, while singleton cleanup, adjustor/scalar wrappers, EH/cookie funclets, vector specializations, throw helpers, and other old-MSVC/Dinkumware lowering remain non-emitting.
- MapPane.cpp retains UID0003TP packet parsing, temporary allocation and cleanup. WorldMapPane.cpp retains copied object state and all later lifecycle/view/travel/draw/input/frame/timer/reachability behavior. Resource libraries, FrameMgr, Layer, rendering, packet manager, and shared literal/global dependencies remain at their established owners.

The file route remains exactly `NexusTK/map/`. No second WorldMapPane source root, custom container file, generic globals file, or data-emitter translation unit is introduced.

## Behavior Summary

- Constructor loads map assets, seeds node data, centers the initial view, and builds reachable-node state.
- Draw path renders the background sprite, nodes, labels, reachability coloring, and the player marker.
- Input path handles keyboard navigation, mouse hover, click-to-travel, and drag-to-scroll.
- Frame update path advances smooth viewport and travel-marker animation through the frame registry.
- Reachability path uses an exact directed-graph BFS from signed `m_currentNodeIndex`; it resets persistent reachable/predecessor vectors, scans row-major adjacency, and records first-discovery parents.
- Travel path sends a compact server packet with the selected map node.

## World-Map Creation Packet Source Boundary

- [UID:0003TP][0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket](by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md) is the exact `MapPane.cpp` producer that constructs `WorldMapPane` at `0x005126f9`. This file owns the receiving constructor and persistent world-map state, not the packet parser.
- The caller supplies `mapName`, `nodeCount`, `currentNodeIndex`, `nodePositions`, `nodeNames`, `destinationMapIds`, `destinationPositions`, and directed row-major `adjacency` in source order. The constructor copies these values into `WorldMapPane` records and graph members and initializes both current and initial hovered indices from the one packet index.
- The caller releases temporary node-position and node-name arrays after construction. This file therefore must copy, rather than retain or take ownership of, those allocations.
- The packet producer owns length-prefixed ANSI decoding, wide-name conversion, temporary arrays, packed adjacency-bit expansion, preset-specific dependency construction, and cleanup. `WorldMapPane.cpp` owns the constructor, node-vector assignment, reachability build, persistent graph state, and later draw/navigation behavior.
- The trusted packet precondition is preserved across the source boundary: neither side invents range checks for the current-node index, graph dimensions, destination IDs, or preset indices that are absent from the binary.

### Rejected Source Placements

- UID0003TP does not move into this file merely because it allocates and constructs `WorldMapPane`; its packet dispatch siblings and [UID:00007Q][MapPane](by-class/MapPane.md) field accesses keep it in `MapPane.cpp`.
- The target's directed `std::vector<bool>` graph is not a custom `UInt32Vector`, a symmetric graph, or a second `WorldMapPane` helper body.
- The producer's post-call releases reject a constructor contract that retains packet buffers or transfers ownership of caller arrays.

## IDA MCP Evidence

2026-06-16 B001 WorldMapPane split audit confirmed:

- The broad [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) page is a non-emitting split index, not one source C++ unit.
- Exact children cover all 37 modeled function starts in the span and preserve source-bearing emission through this file where appropriate.
- `0x005c5500`, `0x005c563c-0x005c565d`, and `0x005c58b0` are non-emitting cleanup/thunk/runtime support, not handwritten source.
- The successor at `0x005c5c87` is `DirectDrawCreate` in [UID:00024B][0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport](by-memory/0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md), so the file boundary remains exact.

Targeted checks on 2026-05-23 confirmed:

- `0x005c2ac0-0x005c32aa` constructor has callers from `0x0050f270` and `0x00511db0`, matching MapPane-driven world-map creation.
- The same constructor-family range is a proven emitter for the shared [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md): B001 current no-owner recheck ties `sub_5C2AC0` ref `0x005c2eae` to appending `L".PAL"` while preparing a world-map palette lookup name before passing the completed name to PaletteLib-style lookup `sub_543D70`. This is WorldMapPane source-use evidence, not proof that WorldMapPane owns a standalone shared suffix declaration.
- The same Rule 26 current goal2 evidence keeps [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) parentless with WorldMapPane as emitter `0000PB`: `sub_5C5200` directly pushes `aWm2_0` at `0x005c5219`, Hex-Rays renders `sub_5845B0(L"WM2")` in the special-region branches, and the caller chain `0x005c3950 -> 0x005c48b0 -> 0x005c5200` places this use in WorldMapPane draw/hit-test logic. This proves source-use, but MapPane `sub_511DB0` has an equally direct comparison-ladder use, so WorldMapPane is not the canonical owner.
- `0x005c3950-0x005c3e41` draw method is a real function and calls common sprite/rectangle render helpers. A 2026-05-25 recheck shows calls at `0x005c3b60` and `0x005c3db0` into [UID:000166][0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md), which should stay under [UID:0000OC][Surface](by-file/Surface.md).
- `0x005c4bd0-0x005c5075` reachability builder calls `0x005c5b20` and `0x005c56a0`, tying the helper bitset to WorldMapPane.
- The reachability builder also calls [UID:0000FD][UInt32Vector](by-class/UInt32Vector.md) fill construction at `0x00514a10` for temporary dword-vector state; the vector implementation belongs with [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md).
- The same builder's work queue is a function-local Dinkumware `std::deque<int>`, not a project `Deque` source file or a `WorldMapPane` field. At `0x005c4e59` it appends the signed start index loaded from `*(short *)(this + 0x1ec)` through [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md); later neighbor appends are inlined and reach `_Growmap` at `0x005c4f83` when needed.
- [UID:0003SR][0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData](by-memory/0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md) now supplies the complete `BuildReachabilityData` definition with `<deque>`/`<vector>`, typed members, exact condition/write/pop ordering, and the binary's unguarded constructor precondition.
- `0x005c5510-0x005c557a` vector destructor is called by `WorldMapPane::~WorldMapPane`.
- `0x005c56a0-0x005c584b` bitset insert helper is called by `BuildReachabilityData`.
- A 2026-05-24 follow-up checked `0x004b6d00` and `0x004b6d20`: they are generic frame-registry wrappers over `FrameMgr::Insert` / `FrameMgr::RemoveFrame`, with broad callers from living-object/effect/world-map paths. They should not be treated as WorldMapPane-owned source even though the generated WorldMap file emits them as `RegisterFrameCallback` and `StopAnimation`.

IDA also confirmed that Wave3's `WorldMapPane` method at `0x00590053` is not an IDA function. That is documented as data debt in [wave3_data_issues](../wave3_data_issues.md) and should not be used for file ownership.

## Relationship To Other Modules

- [UID:0000L3][MapPane](by-file/MapPane.md) owns the server packet handler that creates or shows `WorldMapPane`.
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md) owns the generic frame callback scheduler used by world-map animation.
- `WorldMapPane` consumes render and packet-manager globals but does not own those generic systems.

## Hover Source Contract

- [UID:0003SS][0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse](by-memory/0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md) is the exact `[0x005c5080,0x005c50e6)` private `void WorldMapPane::UpdateHoverFromMouse()` definition owned by this translation unit. Its body is `0x66` bytes, 39 instructions, five blocks, and SHA256 `FDD207906B32F452FB48C445080B1C85C75E28B51EBCEF87CDF0F6E73C3F9041` in the original executable.
- The method polls `g_pEventMan->GetCursorPosition` into an eight-byte `Point`, calls `HitTestNode(cursorPosition.x, cursorPosition.y)`, accepts `-1` or a reachable nonnegative node through `m_reachableNodes`, and writes `m_hoveredNodeIndex` plus calls `InvalidateRect(0)` only when the accepted value changes. A miss therefore clears hover; an unreachable hit preserves it.
- The existing class formal in [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md) already supplies exactly one private declaration. UID0003SS owns only the out-of-line CPP definition and intentionally emits no H fragment, so no duplicate `WorldMapPane.h` declaration or target-created header is warranted.
- [UID:0003ST][0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict](by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md) remains a separate source-bearing child. It accepts only reachable nonnegative hits and therefore preserves hover on a miss. The UID0003SS callback does not populate or claim that sibling's formal body.
- Exact non-source ordering is eleven `0xcc` bytes at `[0x005c5075,0x005c5080)`, ten at `[0x005c50e6,0x005c50f0)`, and ten at `[0x005c5156,0x005c5160)`; all stay outside method definitions and emit no authored source.
- After any UID0003SS source callback, validator-owned `auto-generated/NexusTK/map/WorldMapPane.cpp` must be physically reread against the final scoped command metadata. Completion requires one class declaration, one UID0003SS definition, no UID0003SS empty marker, the still-unimplemented UID0003ST marker preserved, unchanged unrelated content, current hash/byte/line-ending receipts, and no target-created `WorldMapPane.h`.
- Rejected placements and source shapes are Event.cpp, MapPane.cpp, a generic hover helper module, a custom bitset source, raw offset/decompiler-label code, extra index guards, an explicit return value, and a duplicate child declaration.

## Reachability Source Contract

- `WorldMapPane.h` declares private `void BuildReachabilityData();`; this file emits the sole definition.
- Members used by that definition are `std::vector<WorldMapNode> m_nodes`, `std::vector<bool> m_adjacency`, `std::vector<bool> m_reachableNodes`, `std::vector<int> m_predecessors`, and signed `short m_currentNodeIndex`.
- `m_hoveredNodeIndex` at `+0x1e8` remains separate from signed route-origin/current state at `+0x1ec`; hover methods mutate the former, while reachability/travel/predecessor paths use the latter.
- The constructor calls the exact `[0x005c4bd0,0x005c5075)` body at `0x005c2f63` and `0x005c3231`. Target SHA256 is `F81D6B47E10FA69AD9564853818B59ED501F876CD8438CEC899B95198B9DB365`.
- The implementation deliberately does not add an empty graph, negative start, or upper-bound check. No such branch exists before the binary's first bit-vector indexing.
- `[0x005c5075,0x005c5080)` is eleven bytes of `0xcc` alignment, not source or part of either neighboring method.

## Open Questions

- Container source disposition is resolved: the historical helper names describe compiler-generated old-MSVC/Dinkumware standard-container specializations, not handwritten classes.
- The packet-side graph shape needed here is resolved as a packed `N*N` directed matrix. Exact unrelated world-map packet field names remain packet-documentation scope and do not block this file's reachability source.
- Original private identifier spelling remains inferential because no PDB/original source survives; the accepted names are the highest-probability source model and preserve all ABI/behavior. This lexical cap limits confidence to 93 but no longer blocks the complete class, constructor, global, or generated route.

## Cross-References

- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md)
- [UID:0000G8][WorldMapNodeEntryVector](by-class/WorldMapNodeEntryVector.md)
- [UID:0000GA][WorldMapReachabilityBitSet](by-class/WorldMapReachabilityBitSet.md)
- [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- [UID:0003SC][0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup](by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md)
- [UID:0003SK][0x005c3950-0x005c3e41.WorldMapPaneOnDraw](by-memory/0x005c3950-0x005c3e41.WorldMapPaneOnDraw.md)
- [UID:0003SR][0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData](by-memory/0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md)
- [UID:0003TA][0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange](by-memory/0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:0004T9][g_pWorldMapPane](by-global/g_pWorldMapPane.md)
- [UID:00029E][0x0069b454-0x0069b458.g_pWorldMapPane](by-memory/0x0069b454-0x0069b458.g_pWorldMapPane.md)

## Changes

- 2026-08-24 B009 UID0003SS implementation callback:
  - What existed before: `92/93` and the complete WorldMapPane source union routed both hover children, but did not carry the exact UID0003SS emitter/body contract or its generated completion criteria.
  - Changed to: added the target range/hash/ABI/behavior/field/side-effect route, its separate strict-sibling boundary, exact three alignment spans, class-owned declaration/no-child-H disposition, rejected placements, and mandatory current generated readback while preserving score, path, file owner, complete inventory, and unrelated source.
  - Evidence: exact target/sibling bodies and caller branches, accepted class/EventMan/Point contracts, existing UID0000PB emitter route, and validator-owned generated-source semantics.
- 2026-07-20 B003 UID0003SC implementation callback:
  - What existed before: `91/92` with the exact split and complete BFS route, but no complete constructor/class/global source inventory and stale singleton/data-emitter dispositions.
  - Changed to: `92/93`, preserving `NexusTK/map/`, file-root ownership, every existing child/helper/module boundary, and all historical facts. Added the complete R1/R2/R7 union, zero-filled UID00029E storage, both exact resource branches, copied node/adjacency ownership, all method-family routes, and the vtable/literal/constant/compiler/STL no-code dispositions.
  - Evidence: exact UID0003SC body/callers/hash, UID0000G9 layout/RTTI, UID0004T9 lifecycle and PE zero-fill, current split inventory, and existing UID0003SR/packet/helper evidence converge on one source module without duplicate generated bodies.
- 2026-07-14 B004 UID0003SR callback:
  - What existed before: `90/89`, a BFS-like summary, unresolved graph/member names, and separate custom node-vector/bitset source-class hypotheses.
  - Changed to: `91/92`, one complete `BuildReachabilityData` source route, exact typed fields/algorithm/precondition, and non-emitting standard-container specialization disposition for all former custom-helper pages.
  - Summary/evidence: exact target bytes/hash, constructor calls, sibling field uses, packet `N*N` graph construction, and Dinkumware helper identities account for the complete body without custom source files or duplicate generated C++.

- 2026-07-12 B003 UID000149 callback:
  - What existed before: the proposed source contents described BFS-like reachability and temporary vectors without identifying the queue's standard-library source form.
  - Changed to: recorded the local `std::deque<int>` start-index append, inlined neighbor appends, and `_Growmap` edge; retained the score, `NexusTK/map/` route, and current blank source body.
  - Summary/evidence: the toolchain helper and caller-local expansions factor to native `<deque>`/`std::deque<int>::push_back`; no separate custom `Deque.cpp` ownership or unresolved graph-name invention is warranted.

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/map/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented world-map constructor anchor at `0x005c2ac0`; proposed-source-tree keeps the travel/world-map UI under `map/`, separate from generic `MapPane.cpp` and frame-registry infrastructure.

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `90/86`. Summary/evidence: the page gives a detailed source-structure hypothesis, helper-class ownership, behavior summary, targeted IDA MCP evidence, cross-module boundaries, and open questions, supporting a high but not complete grade.

- 2026-06-16 B001 WorldMapPane executable split:
  - Before: score `90/86`; proposed contents used broad generated files/ranges.
  - After: score `90/89`; proposed contents now link the exact child split [UID:0003SC][0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup](by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md) through [UID:0003TA][0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange](by-memory/0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange.md), while [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) is a non-emitting split index.
  - Summary/evidence: B001 confirmed exact function inventory, source-bearing method/helper ownership, non-emitting cleanup/thunk/runtime support, and `DirectDrawCreate` successor boundary. Confidence remains below final audit because private helper type names and packet/source field names remain descriptive.
