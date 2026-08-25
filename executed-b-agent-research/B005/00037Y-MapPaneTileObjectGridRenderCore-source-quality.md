** TARGET-REPORT-UID:00037Y **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B005 source-quality report: [UID:00037Y] MapPaneTileObjectGridRenderCore

FINISHED research target: `source-3/project-documentation/by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/00037Y-MapPaneTileObjectGridRenderCore-source-quality.md`  
Assignment: report-only B source-quality pass. No by-* documentation and no coverage reports were edited.

## Final recommendation

Keep [UID:00037Y] as a source-bearing MapPane-owned helper family under [UID:00007Q] `MapPane`, emitted through [UID:0000L3] `MapPane.cpp`, but do not add one monolithic formal C++ block to this page. The range is not one source method. It is a dense class-method island containing many ordinary MapPane helpers, several route-negative/raw helper bodies, local padding, and a raw tail before [UID:000232]. A single C++ body here would duplicate future exact children and would mix routable methods with raw wrappers that have no proven source entry.

Recommended target metadata:

```yaml
COMPLETION: 87
CONFIDENCE: 89
CANONICAL_OWNER: 00007Q
RECONSTRUCTABLE: TRUE
EMITTER_UIDS:
  - 00007Q
```

Rationale for `87/89`: the current pass resolves the stale raw-tail question, rechecks exact start-route evidence for the raw helpers, improves source-facing names for the major helper groups, and confirms MapPane ownership/emission. Completion should not jump higher because the page is still an aggregate whose final C++ should be produced from exact child pages rather than this broad range. Confidence stays below 90 because IDA MCP was unavailable in this session and several path/hit-test helper names remain high-probability source-facing names rather than proven original spellings.

Recommended formal C++ policy for the target page:

```cpp
// No single C++ body should be emitted for [UID:00037Y].
// This range is a MapPane-owned method cluster. Split exact child helpers first,
// then emit C++ on the child pages that correspond to individual source methods.
```

This is a defer-to-child C++ proof, not a no-source proof. The range remains reconstructable because the component functions are MapPane source, but this aggregate should stay a source-quality inventory page until the exact child pages are created or expanded.

## Evidence checked

Workflow and policy:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`, especially Rules 21/24/26/27.
- `source-3/project-documentation/tools/leaser/Agents/Agent-B005/goal.md`.
- `.codex/AGENTS.md`.
- `source-3/project-documentation/by-structure.md`.
- `source-3/project-documentation/inference_research.md`.
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`.

Target and nearby docs:

- Target: `by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md`.
- Parent aggregate: [UID:0001AT] `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`.
- Following target: [UID:000232] `by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md`.
- MapPane owner/file docs: `by-class/MapPane.md`, `by-file/MapPane.md`.
- Related source-bearing MapPane docs: [UID:0001AR] `0x005051c0-0x00505228.DrawVisibleTilesHelper`, [UID:0003TJ] `0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion`, [UID:0002AZ] `0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag`.
- Data/support docs: [UID:00027N] `0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable`, [UID:0003ZM] `0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants`, [UID:00027O] `0x0066dd50-0x0066dd60.MapObjectDirectionMasks`.
- Callee/support docs: [UID:000235] `0x00514f70-0x005151a9.MapPathDequeSupport`, [UID:0001D6] `0x00537900-0x00537abf.StaticObjectPaneCore`, [UID:00023D] `0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper`, and B010 research for ObjectList extended type lookup helpers.
- Generated state checked: `auto-generated/-ag-memory-coverage.md`, `auto-generated/NexusTK/map/MapPane.cpp`, `by-memory/-coverage-report.md`.

Current-session binary evidence:

- Local PE used for recheck: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Matching local project PE: `E:\NTK\Resources\NexusTK\NexusTK.exe`.
- MD5 for both copies: `4247E04E20B65D6414C7238AA8FF5515`.
- Image base: `0x00400000`.
- `.text`: `0x00401000-0x0060c4ac`, virtual size `0x20b4ac`.
- `.rdata`: `0x0060d000-0x0066c0be`.
- `.data`: `0x0066d000-0x0069ce24`.
- IDA MCP was attempted at `http://127.0.0.1:13337/mcp`; current-session result was `Unable to connect to the remote server`. This report therefore separates current local PE/Capstone evidence from prior live-IDA-backed by-* documentation.

## Current target state

Current metadata in the target:

```yaml
COMPLETION: 86
CONFIDENCE: 88
CANONICAL_OWNER: 00007Q
RECONSTRUCTABLE: TRUE
EMITTER_UIDS:
  - 00007Q
```

Current formal C++ is blank. Current generated output has only an empty marker:

```cpp
// UID:00037Y | by-memory\0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md | Completion:86 | Confidence:88 | Empty Emitter Marker
```

The blank C++ is directionally correct, but the target needs a current explanation that the blank is due to broad aggregate/split policy, not because the range is non-source or below an obsolete gate.

## Boundary and range recheck

The target range remains correct as `0x0050bce0-0x0050e320`. It ends exactly before [UID:000232] `MapPaneObjectEffectDescriptorDispatch` at `0x0050e320`.

Relevant target tail recheck:

- `0x0050e2a0-0x0050e2f3`: modeled source-shaped MapPane helper that allocates/zeros `this+0x3f8` tile-buffer storage from `m_mapWidth * m_mapHeight * 6`.
- `0x0050e2f4-0x0050e300`: twelve `0xcc` alignment bytes.
- `0x0050e300-0x0050e316`: raw MapPane wrapper. It loads `ecx = [ecx+0x424]`, null-checks the `ObjectList`, and tail-jumps to [UID:00023D] `ObjectList::SyncStaticObjectLighting` / `RefreshStaticObjectLighting` at `0x00530d00` with the caller's one stack argument preserved.
- `0x0050e317-0x0050e320`: nine `0xcc` bytes. The final `0x0050e31c-0x0050e320` four-byte padding noted by the parent aggregate is part of this padding run.
- `0x0050e320`: following [UID:000232] starts here and has independent call routes; no fall-through from this target into [UID:000232].

The old wording that `0x0050e2f4-0x0050e320` is simply an unresolved raw tail is stale. The tail is a small split: padding, a route-negative ObjectList wrapper, then padding.

## Function and route inventory

Current local PE direct reference scan for modeled/raw helper starts:

| Start | Direct rel32 refs found | Source-quality role |
| --- | ---: | --- |
| `0x0050bce0` | 1 (`0x00505931`) | MapPane scrolled tile/object-grid refresh helper. |
| `0x0050c040` | 2 (`0x00505707`, `0x00505b43`) | Visible/tile-region checksum helper over legacy-aware tile-layer ids. |
| `0x0050c100` | 0 | Route-negative checksum-step helper body; no direct start refs, no VA/RVA pointer refs. |
| `0x0050c120` | 6 (`0x00505544`, `0x0050555c`, `0x0050c07c`, `0x0050c3b4`, `0x0050d95f`, `0x0050f178`) | Legacy-aware tile-layer lookup. |
| `0x0050c240` | 4 (`0x0050c3c6`, `0x0050c3f7`, `0x0050d973`, `0x0050d9ae`) | Tile draw/screen-rectangle support helper. |
| `0x0050c430` | 0 | Route-negative direction-mask accessor over `0x0066dd50`; no direct start refs, no VA/RVA pointer refs. |
| `0x0050c450` | 0 | Route-negative direction-mask accessor over `0x0066dd58`; no direct start refs, no VA/RVA pointer refs. |
| `0x0050c470` | 6 (`0x00506d04`, `0x0050726d`, `0x0050747c`, `0x005075e3`, `0x005079d9`, `0x00507a72`) | Mouse/input hit-test support. |
| `0x0050c550` | 3 (`0x005072f3`, `0x00507789`, `0x00507ace`) | Secondary mouse/input hit-test support. |
| `0x0050c5e0` | 0 | Route-negative solid static-object pixel hit-test helper; no direct start refs, no VA/RVA pointer refs. |
| `0x0050c6e0` | 3 (`0x00509127`, `0x0050cfea`, `0x0050d818`) | Path/movement candidate helper. |
| `0x0050c790` | 1 (`0x005091d0`) | Path scan/deque helper variant. |
| `0x0050d010` | 1 (`0x0050910c`) | Path scan/deque helper variant. |
| `0x0050d840` | 5 (`0x00505b27`, `0x0050959c`, `0x0050a91f`, `0x0050bcb4`, `0x0051074d`) | Cached visible tile redraw / clear-and-draw helper. |
| `0x0050d8e0` | 6 (`0x00505207`, `0x0050bf16`, `0x0050d8ae`, `0x0050daf7`, `0x00510d6f`, `0x0051125f`) | Draw one tile at map coordinate. |
| `0x0050d9f0` | 0 | Route-negative cached draw/map-state helper body in render cluster. |
| `0x0050db50` | 4 (`0x00508505`, `0x0050bc9e`, `0x00510733`, `0x005137f3`) | Weather/map-state setter or refresh helper. |
| `0x0050dcc0` | 0 | Route-negative object-grid/map support helper. |
| `0x0050dd60` | 0 | Route-negative object-grid/map support helper. |
| `0x0050de10` | 0 | Route-negative object-grid/map support helper. |
| `0x0050dfa0` | 0 | Route-negative object-grid/map save/load/render support helper. |
| `0x0050e100` | 0 | Route-negative object-grid/map save/load/render support helper. |
| `0x0050e2a0` | 3 (`0x00504c8b`, `0x00504d3e`, `0x00504dc5`) | MapPane tile-buffer allocation/reset helper. |
| `0x0050e300` | 0 | Route-negative ObjectList static-object-lighting wrapper. |

The route scan checked direct `call`/`jmp` rel32 encodings and raw VA/RVA pointer patterns in the PE. It does not prove absence of every possible computed call, but it is sufficient to keep the raw helper caveats explicit.

## Source-shape inventory

Use this as the implementation inventory for the target page. Names are source-facing recommendations, not all proven original spellings.

| Range/start | Recommended source-facing name | Signature/source shape | Evidence and uncertainty |
| --- | --- | --- | --- |
| `0x0050bce0` | `MapPane::RefreshScrolledTileData` or `MapPane::UpdateScrolledTileGrid` | `void MapPane::RefreshScrolledTileData(int deltaX, int deltaY)` is the best current source shape. | One direct call at `0x00505931`; existing B002 source-quality work ties this helper to the scroll/recenter path. It pushes object-list origin deltas into the ObjectList bucket-shift helper at `0x005347e0` and calls [UID:0003TJ] `MapPaneRefreshStaticObjectTileRegion` at `0x0050bff9`. Use `RefreshScrolledTileData` unless a later naming sweep standardizes `SetTileDataForScroll`. |
| `0x0050c040` | `MapPane::ComputeVisibleTileChecksum` / `MapPane::ComputeTileRegionChecksum` | `uint16_t MapPane::ComputeVisibleTileChecksum(...) const` with source args describing a tile span/region. | Calls `0x0050c120` and folds returned tile-layer words through [UID:00027N] checksum table. Direct callers are MapPane map-update paths. Exact parameter names need child-level work. |
| `0x0050c100` | `UpdateMapTileChecksum16` | Private/static inline-like helper, probably `static uint16_t UpdateMapTileChecksum16(uint16_t value, uint16_t accumulator)`. | Body is a compact table update: high/low byte mix, table at `0x0066db50`, `ret 8`. No direct start refs or pointer refs. Do not emit standalone child C++ unless folded into the checksum helper or given a raw no-route child. |
| `0x0050c120` | `MapPane::GetLegacyAwareMapTileLayerIds` / `GetTileRenderIds` | `MapTileLayerIds *MapPane::GetLegacyAwareMapTileLayerIds(MapTileLayerIds *out, int tileX, int tileY) const`. | Strongly supported by by-file MapPane and [UID:0003ZM]. Bounds-checks `this+0x3f4/+0x3f6`, reads six-byte records from `this+0x3f8`, and remaps first/third tile-id words through legacy constants when EPF assets are not enabled. |
| `0x0050c240` | `MapPane::BuildTileScreenRect` / `BuildTileDrawRect` | `RectBounds *MapPane::BuildTileScreenRect(RectBounds *out, int tileX, int tileY) const`. | Called by checksum/tile draw paths and by `0x0050d8e0` draw support. Name remains inferred; role is tile-to-screen rectangle/bounds construction. |
| `0x0050c430` | `GetObjectDirectionMaskA` / `GetBlockingDirectionMask` | Private direction-mask byte accessor. | Returns `byte[0x0066dd50 + index]`. No direct start refs. Prefer documenting as a raw/private accessor over [UID:00027O] rather than a public MapPane method. |
| `0x0050c450` | `GetObjectDirectionMaskB` / `GetReverseDirectionMask` | Private direction-mask byte accessor. | Returns `byte[0x0066dd58 + index]`. No direct start refs. Same raw/private policy as `0x0050c430`. |
| `0x0050c470` | `MapPane::HitTestObjectAtPoint` | `ObjectPane *MapPane::HitTestObjectAtPoint(int screenX, int screenY)` or equivalent mouse-coordinate helper. | Six direct calls from mouse/input handlers. This is the primary hit-test route that chooses objects/panes for click/mouse actions. Exact return type should match the object-pane base class in the local hierarchy. |
| `0x0050c550` | `MapPane::HitTestObjectAtPointEx` / `MapPane::HitTestTileObjectAtPoint` | Secondary hit-test helper. | Three direct mouse/input callers. Existing docs prove hit-test support role but not a safe final original name. Do not use a generated `sub_` name in by-* docs; describe as the secondary object/tile hit-test helper if the exact name is still pending. |
| `0x0050c5e0-0x0050c6da` | `MapPane::FindSolidStaticObjectAtPoint` | Raw source-shaped helper, likely `StaticObjectPane *MapPane::FindSolidStaticObjectAtPoint(int screenX, int screenY)`. | Route-negative start. Body divides by tile height, adds `m_tileOriginY`, bounds-checks with `0x00505290`, walks object-list row buckets through `this+0x424`, copies pane bounds through vslot `+0x28`, tests point-in-rect at `0x004b7e80`, computes local object coordinates, and calls [UID:0001D6] `StaticObjectPane::HitTestStaticObjectPixel` at `0x0050c691`. Keep source-shaped detail, but do not emit standalone C++ until route/split policy is accepted. |
| `0x0050c6e0` | `MapPane::CanUsePathStep` / path candidate helper | Private MapPane path/movement helper. | Directly called by the two path scan variants and a notify/path caller. It interacts with direction masks and map occupancy. Name is high-probability, not proven. |
| `0x0050c790` | `MapPane::BuildPathToPoint` / `ScanPathToPoint` variant A | Path scan/deque helper. | One direct call from movement/path caller. Calls MapPath deque append support at [UID:000235] and movement occupancy helper `0x00505430`. Exact source name depends on caller semantics; document role rather than inventing a precise original spelling. |
| `0x0050d010` | `MapPane::BuildPathFromObject` / `ScanPathFromObject` variant B | Path scan/deque helper. | One direct call from movement/path caller. Same deque/occupancy family as `0x0050c790`; likely two path modes rather than unrelated helpers. |
| `0x0050d840` | `MapPane::DrawVisibleTiles` / `RedrawVisibleTileCache` | `void MapPane::DrawVisibleTiles()` is acceptable source-facing wording if paired with the existing [UID:0001AR] `RedrawVisibleTiles()` child. | Five direct render/refresh callers. It clears/redraws cached visible tiles and calls `0x0050d8e0`. Avoid duplicating [UID:0001AR] naming unless docs distinguish the small redraw helper from the broad cached layer refresh. |
| `0x0050d8e0` | `MapPane::DrawTileAt` | `void MapPane::DrawTileAt(int tileX, int tileY, bool beginPaint)` or equivalent. | Strongly supported by [UID:0001AR] and by direct calls from tile redraw and region-refresh paths. Calls `0x0050c120`/`0x0050c240` style tile helpers. |
| `0x0050d9f0` | cached draw/map-state helper | Private render support helper. | No direct start refs. It sits in the cached draw/weather cluster. Keep as route-negative private helper until exact child analysis. |
| `0x0050db50` | `MapPane::SetWeatherState` / `MapPane::SetMapWeather` | `void MapPane::SetWeatherState(...)` or `void MapPane::UpdateWeatherState(...)`. | Four direct callers including packet/update paths. Existing [UID:0002AZ] proves render-state comparison can call `0x0050d840`; `0x0050db50` is the stronger weather/map-state setter in this range. Avoid generated `HandleWeatherPacket` wording on this helper because packet handler ownership lives elsewhere. |
| `0x0050dcc0`, `0x0050dd60`, `0x0050de10`, `0x0050dfa0`, `0x0050e100` | object-grid/map save-load support helpers | Private MapPane object-grid and map persistence/render helpers. | Existing target inventory groups these as object-grid, map save/load, and render support. Current direct-start scan found no direct refs, so names should stay descriptive pending child-level proof. Do not mark them compiler-generated merely because direct rel32 routes are absent. They are ordinary source-shaped bodies inside a MapPane island. |
| `0x0050e2a0-0x0050e2f4` | `MapPane::AllocateTileBuffer` / `ResetTileBufferStorage` | `void MapPane::AllocateTileBuffer()` is the best current source shape. | Reads `m_mapWidth`/`m_mapHeight` from `+0x3f4/+0x3f6`, multiplies by 6, allocates through `0x005c7790`, stores to `m_tileBuffer` at `+0x3f8`, then zeroes through `0x005ca0b0`. Direct calls from map-load setup at `0x00504c8b`, `0x00504d3e`, and `0x00504dc5`. This is a good future exact child with first-draft C++ readiness. |
| `0x0050e300-0x0050e316` | `MapPane::RefreshStaticObjectLighting` wrapper | `void MapPane::RefreshStaticObjectLighting(unsigned short staticObjectId)` as a wrapper over `m_objectList`. | No direct start refs, but the body is source-shaped: null-check `m_objectList` at `+0x424`, then tail-call [UID:00023D]. Keep as a route-negative raw wrapper or split into an exact no-route child; do not pretend the ObjectList method itself belongs to MapPane. |

## Field/type/helper names

Best-supported MapPane field names already present in class/file docs and used by this target:

- `this+0x3f2`: `m_mapId`.
- `this+0x3f4`: `m_mapWidth`.
- `this+0x3f6`: `m_mapHeight`.
- `this+0x3f8`: `m_tileBuffer`; six bytes per tile record.
- `this+0x3fc`: `m_tileOriginX`.
- `this+0x400`: `m_tileOriginY`.
- `this+0x404`: `m_visibleTileColumns`.
- `this+0x408`: `m_visibleTileRows`.
- `this+0x418`: `m_activeObjectPane` / `m_localPlayerObjectPane`, depending on caller context.
- `this+0x424`: `m_objectList`.
- `this+0x428`: `m_viewportGrafPort`.

Best-supported helper/data names:

- [UID:00027N] `MapPaneChecksumLookupTable`: CRC/CCITT-style `uint16_t` table at `0x0066db50`; the leading four zero bytes at `0x0066db4c` are not part of the table.
- `0x0050c040`: checksum over a visible/tile region using `MapPane::GetLegacyAwareMapTileLayerIds`.
- `0x0050c100`: raw checksum update helper, route-negative.
- [UID:0003ZM] `MapPaneLegacyMapTileRemapConstants`: static short arrays at `0x0066dac0` and `0x0066daca`, gated by `g_useEpfAssets` / `byte_66DA97`.
- [UID:00027O] `MapObjectDirectionMasks`: two eight-byte mask arrays at `0x0066dd50` and `0x0066dd58`, used by movement/path occupancy, not a MapPane class field.
- [UID:000235] `MapPathDequeSupport`: compiler/STL deque support used by path scan functions; do not assign source ownership for deque internals to MapPane.
- [UID:0001D6] `StaticObjectPane::HitTestStaticObjectPixel`: callee at `0x00537950`; the raw MapPane helper at `0x0050c5e0` is a consumer, not a StaticObjectPane owner.
- [UID:00023D] `ObjectList::SyncStaticObjectLighting` / `RefreshStaticObjectLighting`: callee at `0x00530d00`; `0x0050e300` is only a MapPane null-checking wrapper.
- B010 ObjectList report: `0x005347e0` is best described as `ObjectList::ShiftObjectBucketsForOriginDelta(int deltaX, int deltaY)`; `0x0050bce0` supplies origin deltas to that ObjectList helper and remains MapPane-owned.

## Raw-tail and raw-helper policy

The raw bodies in this target are not evidence that the whole page is dead or compiler-generated.

Accepted raw/helper conclusions:

- `0x0050c100` is a compact checksum update helper. It has no direct start refs and is probably inlined/source-private logic emitted as a helper body. It belongs with the checksum child, not as public MapPane API.
- `0x0050c430` and `0x0050c450` are route-negative direction-mask accessors. They should be documented as private/raw accessors over [UID:00027O], not given standalone source API names.
- `0x0050c5e0-0x0050c6da` is source-shaped and important for hit-testing, but no direct call/pointer route to its start was found. Keep the detailed semantics in the target/support docs. If split later, mark the child as a route-negative raw MapPane helper and keep formal C++ blank unless a route appears.
- `0x0050d9f0`, `0x0050dcc0`, `0x0050dd60`, `0x0050de10`, `0x0050dfa0`, and `0x0050e100` have no direct start refs in the current scan, but their neighborhood and bodies are still MapPane source-shaped support helpers. They should not be reclassified as generated code based only on direct xref absence.
- `0x0050e2f4-0x0050e300` is padding.
- `0x0050e300-0x0050e316` is a route-negative source-shaped wrapper around ObjectList static-object lighting sync.
- `0x0050e317-0x0050e320` is padding.

Rejected raw-tail alternatives:

- Reject treating `0x0050e2f4-0x0050e320` as one unknown executable tail. It contains two padding runs and one tiny wrapper.
- Reject merging [UID:000232] into this page. [UID:000232] starts at `0x0050e320` and has independent routes.
- Reject marking the whole target `RECONSTRUCTABLE:FALSE`. The range is not a runtime/library island; it is a MapPane method family.
- Reject adding formal C++ to this broad page. That would be a documentation generation problem, not a source-quality improvement.

## Ownership and source placement

Keep canonical owner [UID:00007Q] `MapPane` and emitter [UID:0000L3] `MapPane.cpp`.

Accepted owner route:

- The field base, caller/callee context, tile-buffer fields, object-list field, viewport fields, and render/path callers all use MapPane state.
- `by-class/MapPane.md` already documents the key fields consumed by this range.
- `by-file/MapPane.md` already places the tile draw/checksum/weather/map-state helpers in the MapPane source file.
- The parent [UID:0001AT] is a physical mixed-owner audit aggregate; it correctly stays parentless/non-emitting and delegates source-bearing MapPane children to [UID:00007Q].

Rejected owner alternatives:

- Reject `StaticObjectPane` ownership. [UID:0001D6] only supplies the solid-pixel test callee used by raw MapPane hit-test helper `0x0050c5e0`.
- Reject `ObjectList` ownership for the whole range. ObjectList owns bucket/light sync helpers such as `0x005347e0` and `0x00530d00`; MapPane owns the wrappers/call sites and its object-list field routing.
- Reject `MapPathDequeSupport` ownership. [UID:000235] is compiler/STL deque support used by path helpers; it should not own the MapPane path scan source.
- Reject `MapPaneChecksumLookupTable` or legacy-remap constant docs as owners. They are data dependencies for MapPane tile helper source.
- Reject [UID:000232] merge ownership. It is the following MapPane child, not part of this range.
- Reject assigning this range to `StaticObjectPane` caller context or `MapPaneInputPacketRenderCore` parent aggregate. Those are consumers/containers, not the canonical source owner.

## Relationship to [UID:000232]

[UID:000232] `0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch` begins immediately after this target. The current end boundary at `0x0050e320` is correct:

- This target ends with padding through `0x0050e31f`.
- [UID:000232] has direct callers at `0x005116cc`, `0x00511d34`, `0x0053bac5`, and `0x005a2ee0`.
- The `0x0050e300` wrapper tail-calls [UID:00023D] and returns/pads before [UID:000232]; it does not fall through into descriptor dispatch.

Implementation should preserve the split. Do not extend 00037Y past `0x0050e320`, and do not shrink it to exclude the `0x0050e300` raw wrapper unless a new exact child is created for that wrapper.

## Relationship to support docs

Support facts that should be incorporated or cross-checked during implementation:

- `by-class/MapPane.md`: add/expand a source-quality note that the broad `0x0050bce0-0x0050e320` range contains MapPane-owned tile/object-grid/render/path helpers, but is an aggregate that should split before formal C++. Include field names `m_tileBuffer`, dimensions/origin, visible tile counts, object-list pointer, viewport GrafPort, and note the route-negative raw helpers without making them public API.
- `by-file/MapPane.md`: mirror the source-placement decision. `NexusTK/map/MapPane.cpp` should eventually emit individual helper bodies such as `RefreshScrolledTileData`, `ComputeVisibleTileChecksum`, `GetLegacyAwareMapTileLayerIds`, `DrawTileAt`, `SetWeatherState`, and `AllocateTileBuffer`, not one monolithic range body.
- [UID:00027N] `MapPaneChecksumLookupTable`: add `0x0050c040` as the checksum region helper and `0x0050c100` as route-negative checksum-step helper if that depth is not already present.
- [UID:0003ZM] `MapPaneLegacyMapTileRemapConstants`: keep `0x0050c120` as `GetLegacyAwareMapTileLayerIds`; the current name is better than generated `sub_50C120`.
- [UID:00027O] `MapObjectDirectionMasks`: add that `0x0050c430`/`0x0050c450` are route-negative byte accessors over the two mask arrays, while `0x0050c790`/`0x0050d010` consume direction masks through movement/path occupancy.
- [UID:000235] `MapPathDequeSupport`: preserve no-code compiler/STL policy for deque internals, but record MapPane path scan consumers `0x0050c790` and `0x0050d010`.
- [UID:0001D6] `StaticObjectPaneCore`: keep the consumer note that raw MapPane helper `0x0050c5e0` calls `StaticObjectPane::HitTestStaticObjectPixel` at `0x0050c691`.
- [UID:00023D] `ObjectListStaticObjectLightingSyncHelper`: add that raw MapPane wrapper `0x0050e300` null-checks `m_objectList` and tail-jumps to this ObjectList helper; keep ObjectList as owner of the sync body.
- [UID:0003TJ] `MapPaneRefreshStaticObjectTileRegion`: keep the direct call from `0x0050bff9` inside `0x0050bce0` and the `0x0050d8e0`/`0x0050c120` dependency notes.
- [UID:0001AR] `DrawVisibleTilesHelper`: distinguish its small redraw helper from the broader `0x0050d840` cached visible-layer refresh family.

## First-draft C++ readiness

Do not emit C++ on the aggregate target. Instead, future exact child pages can use the following first-draft source shapes after split validation:

```cpp
void MapPane::RefreshScrolledTileData(int deltaX, int deltaY);
uint16_t MapPane::ComputeVisibleTileChecksum(const RectBounds *tileBounds) const;
MapTileLayerIds *MapPane::GetLegacyAwareMapTileLayerIds(MapTileLayerIds *out,
                                                        int tileX,
                                                        int tileY) const;
RectBounds *MapPane::BuildTileScreenRect(RectBounds *out, int tileX, int tileY) const;
ObjectPane *MapPane::HitTestObjectAtPoint(int screenX, int screenY);
StaticObjectPane *MapPane::FindSolidStaticObjectAtPoint(int screenX, int screenY);
void MapPane::DrawVisibleTiles();
void MapPane::DrawTileAt(int tileX, int tileY, bool beginPaint);
void MapPane::SetWeatherState(int weatherState);
void MapPane::AllocateTileBuffer();
void MapPane::RefreshStaticObjectLighting(unsigned short staticObjectId);
```

These are source-facing method prototypes for future child pages, not target formal C++. The arguments for `ComputeVisibleTileChecksum`, path scan helpers, and weather/map-state helper still need child-specific stack/field validation before final body emission. `FindSolidStaticObjectAtPoint` and `RefreshStaticObjectLighting` need route policy resolution because their current starts are route-negative.

Example first-draft C++ that is ready for a future `0x0050e2a0-0x0050e2f4` child:

```cpp
void MapPane::AllocateTileBuffer()
{
    const int tileCount = m_mapWidth * m_mapHeight;
    m_tileBuffer = new unsigned char[tileCount * sizeof(MapTileRecord)];
    memset(m_tileBuffer, 0, tileCount * sizeof(MapTileRecord));
}
```

Use `sizeof(MapTileRecord) == 6` unless/until the project introduces a named packed tile-record struct. The current helper performs no visible free/delete; ownership/lifetime belongs to the surrounding map-load/reset path.

Example source shape for the route-negative `0x0050e300` wrapper if a child is created:

```cpp
void MapPane::RefreshStaticObjectLighting(unsigned short staticObjectId)
{
    if (m_objectList != nullptr) {
        m_objectList->RefreshStaticObjectLighting(staticObjectId);
    }
}
```

Keep this as explanatory source shape unless a direct route to `0x0050e300` is found or the supervisor accepts a raw no-route child with blank formal C++ and source-shape notes.

## Recommended exact target changes

For `by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md`:

1. Change metadata:
   - `COMPLETION:86` -> `COMPLETION:87`
   - `CONFIDENCE:88` -> `CONFIDENCE:89`
   - Keep `CANONICAL_OWNER:00007Q`
   - Keep `RECONSTRUCTABLE:TRUE`
   - Keep `EMITTER_UIDS:00007Q`
2. Replace blank-C++ ambiguity with a target-specific source-bearing aggregate proof:
   - This range is a MapPane helper family, not one method.
   - It contains many modeled function starts plus raw/route-negative helper bodies and padding.
   - No formal C++ should be emitted here until exact child splits carry individual method bodies.
3. Add the current-session PE evidence:
   - PE path/hash/sections.
   - IDA MCP unavailable note.
   - Route-scan table for all modeled/raw starts listed above.
4. Replace stale raw-tail wording:
   - `0x0050e2a0-0x0050e2f4`: `MapPane::AllocateTileBuffer` source-shaped helper.
   - `0x0050e2f4-0x0050e300`: twelve `0xcc`.
   - `0x0050e300-0x0050e316`: route-negative `m_objectList` null-check wrapper tail-jumping to [UID:00023D].
   - `0x0050e317-0x0050e320`: nine `0xcc`.
5. Add source-facing names/signatures for major helpers, using descriptive names where exact original names are unproven.
6. Add rejected-owner alternatives and raw/no-route policy exactly, so later implementation does not regress to generated `sub_` labels or broad no-code classification.
7. Add child-split recommendation:
   - Create/expand exact children before C++ for checksum, tile lookup, hit-test, path scan, draw, weather/map-state, object-grid support, tile-buffer allocation, and static-object-lighting wrapper.
   - Highest-readiness child: `0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer`.
   - Route-negative/raw child candidates: `0x0050c100`, `0x0050c430`, `0x0050c450`, `0x0050c5e0-0x0050c6da`, `0x0050e300-0x0050e316`.

## Recommended support changes

Support docs to touch only if the implementation callback asks for them and the facts are missing or contradicted:

- `by-class/MapPane.md`: add the 00037Y source-quality inventory and split-before-C++ policy; keep fields under MapPane.
- `by-file/MapPane.md`: state that `MapPane.cpp` should emit individual child methods, not a monolithic 00037Y body.
- `by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md`: add `0x0050c040` / `0x0050c100` consumer details if not present.
- `by-memory/0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md`: ensure `0x0050c120` final name/signature is `GetLegacyAwareMapTileLayerIds` / `GetTileRenderIds`, not generated.
- `by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md`: record route-negative accessors `0x0050c430` and `0x0050c450`.
- `by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md`: record MapPane path-scan consumers while preserving STL/deque no-code ownership.
- `by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md`: keep/add consumer route from `0x0050c5e0` at call `0x0050c691`.
- `by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md`: add wrapper `0x0050e300` as MapPane caller/null-check wrapper.
- `by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md`: preserve direct call from `0x0050bff9` and relationship to scrolled tile data.
- `by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md`: clarify small redraw helper versus broad `0x0050d840` cached visible tile refresh.

## Exact pending coverage row

Do not edit `by-memory/-coverage-report.md` in this report-only pass. If the target row is exposed in the supervisor-owned coverage report, replace it with this row. If the row is currently hidden under the broad parent, insert it under [UID:0001AT] at the correct nested address position:

```markdown
        - [UID:00037Y][0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore](by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md) 0x0050bce0-0x0050e320 | class-method-cluster | MapPaneTileObjectGridRenderCore : reconstructable : 87% : very strong : MapPane-owned tile/object-grid/render helper family with current PE/Capstone recheck confirming modeled starts, raw helper routes, padding, and the split raw tail before [UID:000232]; source-facing roles are resolved for scrolled tile-data refresh, visible-region checksum over the MapPane CRC table, legacy-aware tile-layer lookup, tile rectangle support, object hit-testing, path scan/deque helpers, cached tile redraw, weather/map-state setup, tile-buffer allocation, ObjectList static-object-lighting wrapper, and route-negative raw/private helper bodies; ownership remains [UID:00007Q] MapPane/[UID:0000L3] MapPane.cpp, but formal C++ stays blank because this broad range contains many methods/raw helpers and exact source output should be split into child pages before emission.
```

No `by-class/-coverage-report.md` or `by-file/-coverage-report.md` replacement row is required unless support docs are changed during implementation. If they are changed, update their rows only to mention the 00037Y split-before-C++ policy and unchanged MapPane ownership.

## Validation commands for implementation

Run from `source-3/project-documentation` after any accepted implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00037Y-MapPaneTileObjectGridRenderCore-source-quality-removed.md](00037Y-MapPaneTileObjectGridRenderCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run additional scoped validators only for support docs touched:

> Executable block R002 was removed from this report and preserved verbatim in [00037Y-MapPaneTileObjectGridRenderCore-source-quality-removed.md](00037Y-MapPaneTileObjectGridRenderCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If exact child pages are created later, run validators for each new child and for the parent 00037Y page after it is converted to a non-duplicating inventory/aggregate.

## IDA rename/type/comment recommendations

Recommended names and confidence:

- `sub_50BCE0` -> `MapPane_RefreshScrolledTileData` or `MapPane_UpdateScrolledTileGrid` (medium-high).
- `sub_50C040` -> `MapPane_ComputeVisibleTileChecksum` / `MapPane_ComputeTileRegionChecksum` (medium-high).
- raw `0x0050c100` -> comment `UpdateMapTileChecksum16 route-negative helper over MapPaneChecksumLookupTable` (medium).
- `sub_50C120` -> `MapPane_GetLegacyAwareMapTileLayerIds` (high).
- `sub_50C240` -> `MapPane_BuildTileScreenRect` or `MapPane_BuildTileDrawRect` (medium).
- raw `0x0050c430` -> comment `GetMapObjectDirectionMaskA route-negative accessor over 0x0066dd50` (medium).
- raw `0x0050c450` -> comment `GetMapObjectDirectionMaskB route-negative accessor over 0x0066dd58` (medium).
- `sub_50C470` -> `MapPane_HitTestObjectAtPoint` (medium-high).
- `sub_50C550` -> `MapPane_HitTestTileObjectAtPoint` / secondary hit-test helper (medium).
- raw `0x0050c5e0` -> comment `MapPane_FindSolidStaticObjectAtPoint route-negative helper; calls StaticObjectPane::HitTestStaticObjectPixel at 0x0050c691` (medium-high for role, low for original spelling).
- `sub_50C6E0` -> path candidate/occupancy helper; do not force a final original name yet (medium-low).
- `sub_50C790` -> `MapPane_ScanPathToPoint` / path-deque scan variant A (medium).
- `sub_50D010` -> `MapPane_ScanPathFromObject` / path-deque scan variant B (medium).
- `sub_50D840` -> `MapPane_DrawVisibleTiles` / `MapPane_RedrawVisibleTileCache` (medium-high).
- `sub_50D8E0` -> `MapPane_DrawTileAt` (high).
- `sub_50DB50` -> `MapPane_SetWeatherState` / `MapPane_UpdateMapWeatherState` (medium).
- `sub_50E2A0` -> `MapPane_AllocateTileBuffer` (high).
- raw `0x0050e300` -> comment `MapPane_RefreshStaticObjectLighting route-negative wrapper over ObjectList::RefreshStaticObjectLighting` (medium-high for role, low for direct route).

Type recommendations:

- Introduce or reuse a packed six-byte `MapTileRecord` / `MapTileLayerIds` type for records read from `m_tileBuffer`.
- Keep `MapPaneChecksumLookupTable` as `uint16_t[256]` at `0x0066db50`; do not include the leading four zero bytes.
- Use `RectBounds` for tile/screen rectangle builders if consistent with the rest of the UI/map docs.
- Keep ObjectList and StaticObjectPane callee types owned by their existing class docs; MapPane should only reference them through fields/calls.

## Open questions and disposition

- Exact original names for `0x0050bce0`, path scan helpers, and some object-grid support helpers are not proven. This report supplies source-facing names ranked by evidence and avoids generated labels.
- Exact stack signatures for `0x0050c040`, `0x0050c790`, `0x0050d010`, `0x0050db50`, and the route-negative object-grid helpers need child-level validation before body C++.
- The absence of direct refs to raw helper starts does not prove dead code. It does prove they should be documented as route-negative/private helpers and not used to justify public standalone source methods.
- The aggregate target can remain reconstructable while formal C++ stays blank. This is consistent with current combined-score/emitter policy because the blocker is split/source-shape correctness, not the obsolete 95/95 gate.

## Files changed in this report pass

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/00037Y-MapPaneTileObjectGridRenderCore-source-quality.md`

No by-* documentation files and no coverage reports were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00037Y-MapPaneTileObjectGridRenderCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00037Y"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00037Y-MapPaneTileObjectGridRenderCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00037Y-MapPaneTileObjectGridRenderCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00037Y"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
