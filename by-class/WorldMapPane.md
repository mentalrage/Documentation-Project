*** UID:0000G9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/core/FrameMgr.h"
#include <vector>

struct WorldMapNode {
    MapPoint position;
    wchar_t name[64];
    unsigned short destinationMapId;
    MapPoint destinationPosition;
};

class WorldMapPane;
extern WorldMapPane *g_pWorldMapPane;

class WorldMapPane : public Pane,
                     public FrameHandler,
                     public Singleton<WorldMapPane> {
public:
    WorldMapPane(const wchar_t *mapName,
                 short nodeCount,
                 short currentNodeIndex,
                 const MapPoint *nodePositions,
                 const wchar_t *const *nodeNames,
                 const unsigned short *destinationMapIds,
                 const MapPoint *destinationPositions,
                 const std::vector<bool> &adjacency);
    virtual ~WorldMapPane();

private:
    void SetViewPosition(float viewX, float viewY);
    void StartViewAnimation(float viewX, float viewY);
    void StartTravelToNode(int nodeIndex);
    void SendTravelPacket(int nodeIndex);
    RectBounds *ApplyVisibleClipRect(RectBounds *outBounds);
    int HitTestNode(int mouseX, int mouseY);
    virtual void OnDraw();
    virtual bool HandleKeyEvent(Event *event);
    virtual bool HandleMouseEvent(Event *event);
    virtual void OnFrameUpdate(const FrameUpdateContext *context);
    virtual bool OnTimerTick(int timerId, int userData, int flags);
    void ClampViewPosition(float *viewX, float *viewY);
    void DrawPlayerMarker(int screenX, int screenY);
    void BuildReachabilityData();
    void UpdateHoverFromMouse();
    void UpdateHoverFromMouseStrict();
    int FindPredecessorNode();
    void ScreenPointHelper(int *screenX, int *screenY);
    bool HitTestSpecialRegions(int screenX, int screenY);

    EPFTileContext m_mapImage;
    EPFTileContext m_reachableNodeSymbol;
    EPFTileContext m_unreachableNodeSymbol;
    EPFTileContext m_boatBackImage;
    EPFTileContext m_boatFrontImage;
    DLPalette *m_boatPalette;
    DLPalette *m_mapPalette;
    float m_currentViewX;
    float m_currentViewY;
    float m_targetViewX;
    float m_targetViewY;
    bool m_navigationActive;
    bool m_draggingView;
    float m_playerColumn;
    float m_playerRow;
    int m_hoveredNodeIndex;
    short m_currentNodeIndex;
    LivingSpriteConfig m_playerSpriteConfig;
    int m_currentRouteNode;
    int m_finalTravelTarget;
    double m_travelHeading;
    int m_dragStartScreenX;
    int m_dragStartScreenY;
    int m_playerAnimationFrame;
    SimpleUString m_mapName;
    std::vector<WorldMapNode> m_nodes;
    std::vector<bool> m_adjacency;
    std::vector<bool> m_reachableNodes;
    std::vector<int> m_predecessors;
    bool m_playerOverSpecialRegion;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WorldMapPane

## Layer Client Synchronization - 2026-07-14

The WorldMapPane construction/factory path calls [UID:0004NR][0x004f0480-0x004f0597.LayerConstructor](by-memory/0x004f0480-0x004f0597.LayerConstructor.md) at `0x0050f326` for an owned Layer instance used by the world-map UI. This proves a reusable Layer client, not WorldMapPane ownership of Layer source. Layer's root HierList/Region lifetime and all hierarchy methods remain in UID000073/UID0000KL. The current complete class formal and `93/94` score preserve that boundary and all unrelated Layer detail.

## Status

- Confidence: very strong for behavior, separate source module, singleton lifecycle, exact executable child split, direct ownership of the WorldMap read-only-data children, and the typed reachability/route data model.
- Likely source file: [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- Address range: [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md), now a non-emitting split index with exact source-bearing children.
- Historical stale recovered artifact: `source-3/simroot_v2/class_WorldMapPane.cpp`; current source reconstruction routes through [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) at `NexusTK/map/`.
- Boundary note: generated `RegisterFrameCallback` / `StopAnimation` wrappers at `0x004b6d00` and `0x004b6d20` are now treated as generic [UID:00005G][FrameHandler](by-class/FrameHandler.md) helpers, not WorldMapPane ownership.

## Exact Inheritance And 0x298 Layout

RTTI rooted at COL `0x00654208` and CHD `0x0065421c` contains eight base descriptors. PMDs put `WorldMapPane`, `Pane`, `GrafPort`, and `LObject` at zero, inherited `EventHandler` at `+0xa0`, inherited `TimerHandler` at `+0xa4`, direct `FrameHandler` at `+0xf8`, and empty direct `Singleton<WorldMapPane>` at `+0xfc`. Constructor lowering calls `Pane(0)`, constructs `FrameHandler`, then publishes through Singleton. The source direct-base order in the formal is therefore exact. Old MSVC EBO lets the empty Singleton base overlap the first data member at `+0xfc`.

| Offset | Size | Source member / role |
| --- | ---: | --- |
| `+0x000..+0x0f7` | `0xf8` | `Pane` base including inherited EventHandler and TimerHandler facets. |
| `+0x0f8..+0x0fb` | 4 | Direct `FrameHandler` base. |
| `+0x0fc` | 0 by EBO | Empty direct `Singleton<WorldMapPane>` base overlaps the first member. |
| `+0x0fc..+0x123` | `0x28` | `EPFTileContext m_mapImage`. |
| `+0x124..+0x14b` | `0x28` | `EPFTileContext m_reachableNodeSymbol`. |
| `+0x14c..+0x173` | `0x28` | `EPFTileContext m_unreachableNodeSymbol`. |
| `+0x174..+0x19b` | `0x28` | `EPFTileContext m_boatBackImage`. |
| `+0x19c..+0x1c3` | `0x28` | `EPFTileContext m_boatFrontImage`. |
| `+0x1c4/+0x1c8` | 4 each | `DLPalette *m_boatPalette`, `DLPalette *m_mapPalette`. |
| `+0x1cc..+0x1d8` | 4 each | Current X/Y and target X/Y floats. |
| `+0x1dc/+0x1dd` | 1 each | Navigation/travel active and dragging-view booleans. |
| `+0x1de..+0x1df` | 2 | Natural alignment; no source member. |
| `+0x1e0/+0x1e4` | 4 each | Player column and row floats. |
| `+0x1e8` | 4 | `int m_hoveredNodeIndex`. |
| `+0x1ec` | 2 | `short m_currentNodeIndex`. |
| `+0x1ee..+0x1ef` | 2 | Natural alignment. |
| `+0x1f0..+0x233` | `0x44` | `LivingSpriteConfig m_playerSpriteConfig`. |
| `+0x234/+0x238` | 4 each | Current route/progress node and final travel target. |
| `+0x23c..+0x23f` | 4 | Natural alignment for the following double. |
| `+0x240` | 8 | Travel heading/angle double. |
| `+0x248/+0x24c` | 4 each | Drag-start screen X/Y. |
| `+0x250` | 4 | Player animation frame. |
| `+0x254` | 4 | `SimpleUString m_mapName`. |
| `+0x258..+0x263` | 12 | `std::vector<WorldMapNode> m_nodes`. |
| `+0x264..+0x273` | 16 | `std::vector<bool> m_adjacency`. |
| `+0x274..+0x283` | 16 | `std::vector<bool> m_reachableNodes`. |
| `+0x284..+0x28f` | 12 | `std::vector<int> m_predecessors`. |
| `+0x290` | 1 | Player-over-special-region boolean. |
| `+0x291..+0x297` | 7 | Natural tail/alignment to exact `0x298`. |

The constructor does not initialize `+0x234`, `+0x238`, `+0x240`, `+0x248`, or `+0x24c`; those members are deliberately absent from its initializer list. Default construction writes the internal `LivingSpriteConfig` state and each resource branch then copies the complete current user sprite configuration. These facts are expressed as normal class/member construction, never raw offset assignments.

`WorldMapNode` is exactly `0x94` bytes: `MapPoint position` at `+0x00`, `wchar_t name[64]` at `+0x08`, `unsigned short destinationMapId` at `+0x88`, natural two-byte padding at `+0x8a`, and `MapPoint destinationPosition` at `+0x8c`. Its declaration order closes the stride naturally without a packed or raw-layout surrogate.

## Constructor, Global, And Compiler Source Contract

- [UID:0003SC][0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup](by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md) supplies the complete eight-input constructor and the exact two resource branches. It deep-copies packet-owned input and preserves trusted-input/no-check behavior.
- [UID:0004T9][g_pWorldMapPane](by-global/g_pWorldMapPane.md) supplies the sole zero-initialized source definition. The class formal declares the matching extern before the class.
- UID00035H vtable/RTTI, UID00035I literals, and UID00035J constants arise naturally from this declaration and the exact method bodies. Raw arrays, explicit vptr stores, PMD tables, EH/cookie state, adjustor/scalar wrappers, and old-MSVC standard-container helper bodies remain excluded.
- Private helper/member names are the best source-facing names supported by cross-method behavior. Missing symbols cap confidence at 94 but do not leave a type, signature, layout, access, source placement, or code blocker.
- The complete class closes before `[[CHILDREN]]`; all emitted qualified definitions therefore assemble at namespace scope.

## Class Purpose

`WorldMapPane` is the modal/overlay world-map travel pane. It renders a scrollable world map, displays destination labels, determines reachable nodes, handles keyboard/mouse navigation, animates viewport movement, and sends travel requests to the server.

## Method Families

| Family | Representative methods | Role |
| --- | --- | --- |
| Lifecycle | `WorldMapPane`, `~WorldMapPane`, `ScalarDeletingDestructor` | Loads assets/node state and releases helper buffers. |
| View positioning | `SetViewPosition`, `ScrollViewBy`, `AnimateToPosition`, `ClampViewPosition`, `GetVisibleRect` | Maintains the scrollable world-map viewport. |
| Navigation | `NavigateToNode`, `FindPredecessorNode`, `SendMapTravelPacket` | Follows parent-link route data and sends server travel packet `0x6E`. |
| Drawing | `OnDraw`, `DrawPlayerMarker` | Draws map background, nodes/labels, reachability coloring, and player marker. |
| Input | `OnKeyDown`, `OnMouseEvent`, `UpdateHoverFromMouse`, `UpdateHoverFromMouseStrict`, `HitTestNode`, `HitTestSpecialRegions` | Handles keyboard, mouse hover/click, drag scroll, and node/special-region hit tests. |
| Animation | `OnFrameUpdate`, `OnTimerTick`, generic `FrameHandler` schedule/remove wrappers | Uses the frame callback system for smooth travel/viewport animation. |
| Reachability | `BuildReachabilityData` | Runs a complete directed-graph BFS from the signed current node, sets persistent reachable flags, and records first-discovery predecessors. |

## Hover Input Method Contract

- The existing private declarations `void UpdateHoverFromMouse();` and `void UpdateHoverFromMouseStrict();` are descriptive source-facing names for the exact `[0x005c5080,0x005c50e6)` and `[0x005c50f0,0x005c5156)` helpers. No original private symbol survives, so the spellings are high-confidence descriptive names rather than original-proof.
- Both methods create one eight-byte `Point`, poll `g_pEventMan->GetCursorPosition(&cursorPosition)`, and call `HitTestNode(cursorPosition.x, cursorPosition.y)`. `Point` stores `y` at `+0x00` and `x` at `+0x04`; no `Event` payload is passed into either helper.
- Both read `std::vector<bool> m_reachableNodes` at `+0x274`, reject unreachable nonnegative nodes, compare against `int m_hoveredNodeIndex` at `+0x1e8`, and call inherited `Pane::InvalidateRect(0)` only after changing that field. The compiler-lowered word/bit sequence is ordinary `m_reachableNodes[nodeIndex]` indexing.
- `UpdateHoverFromMouse` is clear-capable: it accepts `-1` or a reachable nonnegative hit, so a miss replaces the stored hover with `-1`. It is called at `0x005c40f5` for left-button down and `0x005c4187` after ending a drag on left-button up.
- `UpdateHoverFromMouseStrict` is reachable-hit-only: it accepts only a reachable nonnegative hit, preserving hover on a miss or unreachable node. It is called at `0x005c4237` for passive cursor motion when the pane is not dragging and navigation is inactive.
- `m_hoveredNodeIndex` remains distinct from signed `short m_currentNodeIndex` at `+0x1ec`; mouse hover writes the former, while route/reachability logic uses the latter. Neither helper has an explicit source argument or coherent return contract, so both declarations correctly remain `void`.
- Rejected source models include Event-payload input, clearing unreachable hits, clearing misses in the strict sibling, unconditional invalidation, a custom reachability bitset, raw offset source, an extra index guard, a new helper file, and duplicate method declarations in child H fragments.

## Evidence Notes

- B001 WorldMapPane source-split audit on 2026-06-16 created exact method children [UID:0003SC][0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup](by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md) through [UID:0003SW][0x005c5200-0x005c53d0.WorldMapPaneHitTestSpecialRegions](by-memory/0x005c5200-0x005c53d0.WorldMapPaneHitTestSpecialRegions.md), plus [UID:0003T3][0x005c5660-0x005c569b.WorldMapPaneScalarDeletingDestructor](by-memory/0x005c5660-0x005c569b.WorldMapPaneScalarDeletingDestructor.md).
- The same audit isolates non-emitting compiler/runtime context [UID:0003SY][0x005c5500-0x005c550b.WorldMapPaneSingletonClearCleanupThunk](by-memory/0x005c5500-0x005c550b.WorldMapPaneSingletonClearCleanupThunk.md), [UID:0003T2][0x005c563c-0x005c565d.WorldMapPaneAdjustorThunks](by-memory/0x005c563c-0x005c565d.WorldMapPaneAdjustorThunks.md), and [UID:0003T6][0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0](by-memory/0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0.md), so class source reconstruction should express normal constructors/destructors and private helpers rather than those generated bodies.
- IDA MCP on 2026-06-10 B001-038 confirms `0x006313fc -> ??_R4WorldMapPane@@6B@`, named vtable bases at `0x00631400`, `0x0063144c`, `0x0063147c`, and `0x00631488`, and constructor/destructor store xrefs from `0x005c2ac0-0x005c32aa` and `0x005c32b0-0x005c341e`.
- The same pass confirms WorldMap resource literals `WMSYMBOL.EPF`, `BOAT.EPF`, `BOAT.PAL`, `.EPD`, `.PAD`, `BBOAT.EPD`, `BOAT.PAD`, and `FBOAT.EPD` in `0x00631490-0x00631528` are referenced only by the constructor-family function.
- IDA MCP confirms numeric constants in `0x00631528-0x00631570` are referenced only by WorldMapPane method ranges `0x005c36d0`, `0x005c37e0`, `0x005c3950`, `0x005c4250`, and `0x005c4740`; `0x00631570` has a non-WorldMap xref and starts the Browser/OLE successor page.
- IDA MCP reconfirms `g_pWorldMapPane` xrefs at `0x005c2b1f`, `0x005c2b26`, `0x005c3401`, and `0x005c5500` for publish/clear lifecycle, plus read sites at `0x004d7d03` and `0x004d9186`.
- IDA MCP confirms `0x005c2ac0-0x005c32aa`, `0x005c3950-0x005c3e41`, and `0x005c4bd0-0x005c5075`.
- `BuildReachabilityData` reaches generated old-MSVC `std::vector<bool>` specialization bodies documented under [UID:0000GA][WorldMapReachabilityBitSet](by-class/WorldMapReachabilityBitSet.md) at `0x005c56a0` and `0x005c5b20`; those bodies are not handwritten class methods.
- [UID:0003SR][0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData](by-memory/0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md) uses a function-local Dinkumware `std::deque<int>` work queue. Its first append at `0x005c4e59` takes a signed start index loaded from `*(short *)(this + 0x1ec)`; later discovered-neighbor appends inline the same operation and reach `_Growmap` at `0x005c4f83` when required.
- That deque is local algorithm state, not a `WorldMapPane` data member. Cross-function field analysis resolves the source model used by UID0003SR and the complete class declaration above; the former blank-formal limitation is historical.
- `WorldMapPane::~WorldMapPane` reaches generated `std::vector<WorldMapNode>` cleanup documented under [UID:0000G8][WorldMapNodeEntryVector](by-class/WorldMapNodeEntryVector.md); it does not prove a handwritten custom vector class.
- IDA MCP on 2026-05-24 shows `0x004b6d00` and `0x004b6d20` have broad callers and only delegate to `g_frameRegistry`; keep them under [UID:0000JM][FrameMgr](by-file/FrameMgr.md).
- Wave3 currently attaches a method at `0x00590053`; IDA reports no function there. Treat that entry as data debt until corrected.

## Reachability And Route Field Contract

| Offset | Source-facing field | Exact role |
| --- | --- | --- |
| `+0x1e8` | `int m_hoveredNodeIndex` | Mutable hover/selection state written by both hover helpers and read by `OnDraw`; constructor initially mirrors the packet node value here. |
| `+0x1ec` | `short m_currentNodeIndex` | Signed route-origin/current-node state written by the constructor and read by `BuildReachabilityData`, `StartTravelToNode`, and `FindPredecessorNode`. |
| `+0x258..+0x260` | `std::vector<WorldMapNode> m_nodes` | Exact 0x94-byte node records; `BuildReachabilityData` derives node count from this vector. |
| `+0x264..+0x270` | `std::vector<bool> m_adjacency` | Flattened row-major `nodeCount * nodeCount` directed adjacency matrix supplied by the packet parser/constructor. |
| `+0x274..+0x280` | `std::vector<bool> m_reachableNodes` | Persistent reachability flags rebuilt by UID0003SR and consumed by hover/draw paths. |
| `+0x284..+0x28c` | `std::vector<int> m_predecessors` | First-discovery BFS parent for each node, initialized to `-1` and consumed by travel/route helpers. |

- `WorldMapNode` is exactly `0x94` bytes. Coordinates are at `+0x00/+0x04`, `wchar_t name[64]` at `+0x08`, a 16-bit travel field at `+0x88`, natural padding at `+0x8a`, and 32-bit travel payload fields at `+0x8c/+0x90`.
- `m_hoveredNodeIndex` and `m_currentNodeIndex` are distinct despite constructor initialization from the same value. Their independent writers/readers reject the former single-field interpretation.
- `WorldMapReachabilityBitSet` and `WorldMapNodeEntryVector` are retained as documentation navigation labels only. The actual source types are `std::vector<bool>` and `std::vector<WorldMapNode>`; their exact machine helpers are compiler/library generated and non-emitting.

## World-Map Creation Packet Producer Contract

- [UID:0003TP][0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket](by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md) is the `MapPane.cpp` packet producer for the constructor call at `0x005126f9`; it is not a `WorldMapPane` method or source body.
- Its constructor argument order is `mapName`, `nodeCount`, `currentNodeIndex`, `nodePositions`, `nodeNames`, `destinationMapIds`, `destinationPositions`, and `adjacency` after the implicit destination object. The constructor copies these inputs into `m_nodes` and `m_adjacency` and mirrors `currentNodeIndex` into both `m_currentNodeIndex` and initial `m_hoveredNodeIndex`.
- The packet producer decodes one node position and one bounded wide node name for each node, one destination map ID and destination position for each node, and a directed row-major `nodeCount * nodeCount` `std::vector<bool>` adjacency matrix. The destination fields belong to the corresponding `WorldMapNode` records; they are not a second independent graph.
- The preset is trusted exactly as received. The source does not validate the current-node index against `nodeCount`, symmetrize adjacency, or add empty-graph guards before construction and reachability setup.
- `WorldMapPane` copies persistent state. The `MapPane` producer frees its temporary node-position and node-name arrays after the constructor returns, so those buffers are not transferred or retained by this class.
- The source ownership boundary is explicit: packet parsing, temporary allocation, and cleanup remain in [UID:00007Q][MapPane](by-class/MapPane.md); constructor storage and graph setup remain in this class and [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md).

### Rejected And Superseded Interpretations

- The directed adjacency storage is native old-MSVC `std::vector<bool>`, not a custom `UInt32Vector` or an undirected/symmetric matrix.
- Mirrored constructor initialization does not collapse `m_hoveredNodeIndex` and `m_currentNodeIndex` into one field; their independent readers and writers preserve the two-field model.
- Caller-side release of node positions and names rejects borrowed-pointer or ownership-transfer class layouts. No packet buffer pointer survives in `WorldMapPane` state.

## BuildReachabilityData Contract

- Private declaration: `void BuildReachabilityData();` in `WorldMapPane.h`; complete definition belongs to [UID:0003SR][0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData](by-memory/0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md) and emitter [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md).
- The method resets `m_reachableNodes` to false and `m_predecessors` to `-1`, constructs local `std::vector<bool>` visited state and `std::deque<int>` pending state, then traverses from signed `m_currentNodeIndex`.
- For each dequeued node it scans every candidate and preserves exact short-circuit order: unvisited, adjacent, then non-self. Each first discovery sets visited/reachable, records its predecessor, and enqueues it. Queue removal occurs only after the complete row scan.
- The adjacency matrix is directed; there is no symmetry assumption, distance vector, weighting, recursion, target argument, or early destination stop.
- No empty-graph/start-index guard exists before initial indexing. Constructor/input invariants are the binary precondition; source must not add a guard or clamp.
- Exact target SHA256 `F81D6B47E10FA69AD9564853818B59ED501F876CD8438CEC899B95198B9DB365`; sole caller is the constructor with calls at `0x005c2f63` and `0x005c3231`.

## Cross-References

- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- [UID:0003SC][0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup](by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md)
- [UID:0003SK][0x005c3950-0x005c3e41.WorldMapPaneOnDraw](by-memory/0x005c3950-0x005c3e41.WorldMapPaneOnDraw.md)
- [UID:0003SN][0x005c4250-0x005c46e9.WorldMapPaneOnFrameUpdate](by-memory/0x005c4250-0x005c46e9.WorldMapPaneOnFrameUpdate.md)
- [UID:0003T3][0x005c5660-0x005c569b.WorldMapPaneScalarDeletingDestructor](by-memory/0x005c5660-0x005c569b.WorldMapPaneScalarDeletingDestructor.md)
- [UID:000271][0x006313fc-0x00631570.WorldMapReadOnlyData](by-memory/0x006313fc-0x00631570.WorldMapReadOnlyData.md)
- [UID:00035H][0x006313fc-0x00631490.WorldMapPaneVtableData](by-memory/0x006313fc-0x00631490.WorldMapPaneVtableData.md)
- [UID:00035I][0x00631490-0x00631528.WorldMapPaneResourceStrings](by-memory/0x00631490-0x00631528.WorldMapPaneResourceStrings.md)
- [UID:00035J][0x00631528-0x00631570.WorldMapPaneNumericConstants](by-memory/0x00631528-0x00631570.WorldMapPaneNumericConstants.md)
- [UID:00029E][0x0069b454-0x0069b458.g_pWorldMapPane](by-memory/0x0069b454-0x0069b458.g_pWorldMapPane.md)
- [UID:0000G8][WorldMapNodeEntryVector](by-class/WorldMapNodeEntryVector.md)
- [UID:0000GA][WorldMapReachabilityBitSet](by-class/WorldMapReachabilityBitSet.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:00005G][FrameHandler](by-class/FrameHandler.md)

## Changes

- 2026-08-24 B009 UID0003SS implementation callback:
  - What existed before: the complete `93/94` class formal already declared both hover helpers and named the hover/reachability fields, but class prose did not distinguish their input source, miss behavior, caller routes, or side effects.
  - Changed to: added the exact clear-capable versus reachable-hit-only contract, EventMan/Point input, HitTestNode argument order, field offsets/types, caller addresses and gates, conditional invalidation, source-void rationale, and rejected alternatives while preserving the complete declaration, layout, score, owner, emitter, and unrelated class research.
  - Evidence: exact 39-instruction/five-block sibling bodies, the one miss-branch difference, accepted `WorldMapPane`/`Point`/`EventMan` declarations, and the full `HandleMouseEvent` branch inventory.
- 2026-07-20 B003 UID0003SC implementation callback:
  - What existed before: `90/93` with resolved graph fields but a blank formal and an explicit incomplete-class limitation.
  - Changed to: `93/94` with the accepted complete class declaration, exact `0x298` inheritance/member layout, exact `0x94` node declaration, all lifecycle/view/travel/draw/input/frame/timer/reachability declarations, singleton extern, and class closure before `[[CHILDREN]]`.
  - Evidence: RTTI PMDs/direct-base order, constructor stores and `0x298` allocation, cross-method field access, old-MSVC container sizes, UID0003SC's complete body, UID0003SR graph contract, and UID0004T9 source-global factorization. Existing Layer client, packet boundary, BFS, shared resources, frame-handler ownership, siblings, and history are preserved.
- 2026-07-14 B004 UID0003SR callback:
  - What existed before: the class was `88/90`, treated vector specializations as private custom helpers, and left graph fields/source body unresolved.
  - Changed to: `90/93`, resolved the complete field/container contract and signed current-versus-hover distinction, documented the exact BFS/source precondition, and reclassified helper buckets as non-emitting old-MSVC standard-container specializations.
  - Summary/evidence: UID0003SR's 398-instruction/66-block body, two constructor calls, route/hover/draw sibling uses, packet-supplied `N*N` graph, and standard helper identities converged on the typed source model. Its then-blank class-formal limitation is superseded by the 2026-07-20 complete declaration.

- 2026-07-12 B003 UID000149 callback:
  - What existed before: reachability behavior named temporary lists but did not identify the queue as native toolchain `std::deque<int>` or separate it from class storage.
  - Changed to: documented the exact local signed start-index append, caller-inlined neighbor appends, and `_Growmap` evidence while retaining the class score, source route, and blank formal block.
  - Summary/evidence: the shared helper at `0x004a88e0` and inlined builder sequence are one Dinkumware `std::deque<int>::push_back(const int&)` family; unresolved graph field names still block a complete source body.

- 2026-06-10 B001-038 parent-gate repair:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:82`; the class summarized method families but did not carry the direct read-only-data ownership evidence needed for `000271` child assignments.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, with live IDA MCP evidence for WorldMapPane RTTI/vtable stores, constructor-only resource literals, WorldMapPane-only numeric constants, singleton lifecycle xrefs, and the Browser/OLE successor boundary.
  - Summary/evidence: B001-038 split [UID:000271][0x006313fc-0x00631570.WorldMapReadOnlyData](by-memory/0x006313fc-0x00631570.WorldMapReadOnlyData.md) into exact children [UID:00035H][0x006313fc-0x00631490.WorldMapPaneVtableData](by-memory/0x006313fc-0x00631490.WorldMapPaneVtableData.md), [UID:00035I][0x00631490-0x00631528.WorldMapPaneResourceStrings](by-memory/0x00631490-0x00631528.WorldMapPaneResourceStrings.md), and [UID:00035J][0x00631528-0x00631570.WorldMapPaneNumericConstants](by-memory/0x00631528-0x00631570.WorldMapPaneNumericConstants.md). The class is the direct semantic parent for all three children and now clears the strict `85/85` gate.

- 2026-06-16 B001 WorldMapPane executable split:
  - What existed before: `COMPLETION:86`, `CONFIDENCE:88`; class method evidence still depended on the broad [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) aggregate.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`; exact child pages now cover constructor, destructor, view/navigation, packet send, draw, input, frame/timer, marker, reachability, hover, route/coordinate, special-region helpers, and scalar deleting destructor. Compiler cleanup/thunk and STL throw-helper children are explicitly non-emitting.
  - Summary/evidence: B001 live IDA/MCP and PE scans confirmed function starts, vtable slots, singleton writes/reads, internal call graph, and `DirectDrawCreate` successor boundary. The then-blank C++ and unresolved-name limitation is historical and was closed by the 2026-07-20 complete class pass.

- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed representative world-map constructor/lifecycle, view/input, and reachability-builder starts at `0x005c2ac0`, `0x005c3950`, and `0x005c4bd0`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the lifecycle, viewport, navigation, drawing, input, animation, and reachability method-family documentation, helper-class links, IDA-confirmed representative ranges, frame-handler ownership correction, and Wave3 data-debt caveat.

## 2026-08-24 B001 UID0000JM Frame Callback Reconciliation

- Preserved `93/94`, owner/emitter UID0000PB, complete `0x298` layout, all WorldMap source and dependencies, and the CPP-hosted class route.
- Added `#include "../ui/core/FrameMgr.h"` before `<vector>` and changed only the callback declaration from historical `bool OnFrameUpdate(int elapsedTime)` to `void OnFrameUpdate(const FrameUpdateContext *context)`, matching the FrameHandler vtable and dispatcher ABI.
- Exact callback child UID0003SN remains `[0x005c4250,0x005c46e9)`, 1177 bytes/284 instructions, with sole vtable xref `0x0063148c`. Its body advances viewport/travel animation, schedules or removes frame callbacks, and ignores the context payload.
- UID0003SN remains formal CPP/H blank at `86/89`: the ABI/declaration is complete, but its independent 284-instruction body reconstruction is not fabricated by this bounded dependency correction. No unrelated WorldMap method, field, source, score, or owner changed.
