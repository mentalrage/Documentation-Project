** TARGET-REPORT-UID:0001AW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AW MapPane Packet Source Split Continuation Batch6

Assignment: `B001-goal2-memory-tool-mappane-packet-source-split-continuation6-0001AW-20260616`  
Agent: B001  
Target: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](../../../../../by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)

## Final Recommendation

Create the next bounded executable broad-leaf child batch now:

- [UID:0003TK] `0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md`, `86/90`, owner/emitter [UID:00007Q][MapPane](../../../../../by-class/MapPane.md).
- [UID:0003TL] `0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md`, `86/89`, owner/emitter [UID:00007Q][MapPane](../../../../../by-class/MapPane.md).
- Add ignored padding rows for `0x005104c7-0x005104d0`, `0x00510958-0x00510960`, and `0x00511347-0x00511350`.
- Keep [UID:0001AW] `COMPLETION:85`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q`, and blank final C++.

Do not create children in this batch for the raw/no-function body at `0x00511350-0x00511414`, the no-caller true-return stubs at `0x00511420` and `0x00511430`, or the later modeled handlers starting at `0x00511440`, `0x00511710`, `0x00511c90`, `0x00511db0`, `0x00512960`, `0x00512d60`, `0x00512f20`, and `0x00513310`. The later modeled handlers are likely valid future children, but this batch should stop at the first raw/no-function seam so the supervisor can apply a clean first slice of the broad leaf.

No by-* documentation, generated report, IDA DB, or `by-memory/-coverage-report.md` file was directly edited by B001. This report is the only file created.

## Current State Checked

- Parent [UID:0001AW] is currently `85/88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, with blank final C++.
- Supervisor notes record executed MapPanePacketHandlers children [UID:0003TB]-[UID:0003TJ], ending the last executable split at [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](../../../../../by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md), plus ignored padding through `0x0050f270`.
- `auto-generated/by-memory-tool-report.md` was regenerated at `2026-06-16 05:47:55`; Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan all report `None`.
- The largest-range report still lists [UID:0001AW] leaf `0x005104c7-0x00513800` as rank 18, `13113` bytes, reconstructable.
- UID allocation assumption: latest executed child is [UID:0003TJ]. If no intervening supervisor allocation occurred, use [UID:0003TK] and [UID:0003TL] for this batch. If the supervisor's allocator has advanced, replace every [UID:0003TK]/[UID:0003TL] reference in the proposed text consistently.

## Evidence Checked

### Live IDA MCP

Session: `b001_mappane_0001AW_20260616`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`. `idb_list` shows the worker session is not analyzing; `server_health` returns status `ok`, Hex-Rays ready, and strings cache ready.

Function inventory for the broad leaf:

| Start | IDA name | Size | Current result |
|---|---|---:|---|
| `0x005104d0` | `sub_5104D0` | `0x488` | Executable child for this batch; live dispatcher call at `0x00507f10`, opcode `0x15` in [UID:0001SO][MapServerPacketOpcode](../../../../../by-type/by-enum/MapServerPacketOpcode.md). |
| `0x00510960` | `sub_510960` | `0x9e7` | Executable child for this batch; live dispatcher call at `0x00507ffa`, opcode `0x06`; calls [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](../../../../../by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) at two sites. |
| `0x00511350` | not modeled | none | Raw function-shaped body between modeled handler and stubs; `lookup_funcs` says not a function, and raw route scans found no callers/pointers. Roadmap-only. |
| `0x00511420` | `sub_511420` | `0x5` | Modeled true-return stub, no callers/xrefs. Roadmap-only. |
| `0x00511430` | `sub_511430` | `0x5` | Modeled true-return stub, no callers/xrefs. Roadmap-only. |
| `0x00511440` | `sub_511440` | `0x2c3` | Later live dispatcher child candidate, call at `0x0050800b`, opcode `0x07`; not in this batch because it is after the raw seam. |
| `0x00511710` | `sub_511710` | `0x287` | Later live dispatcher child candidate, call at `0x0050801c`, opcode `0x0d`; not in this batch. |
| `0x00511c90` | `sub_511C90` | `0x11e` | Later effect/object helper candidate, calls [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](../../../../../by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md) and [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](../../../../../by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md); dispatcher call at `0x005082f6`, plus internal call from `0x00512c04`. |
| `0x00511db0` | `sub_511DB0` | `0xa8a` | Later object-create/world-map packet candidate, dispatcher call at `0x00508307`, opcode `0x2e`; calls [UID:0000G9][WorldMapPane](../../../../../by-class/WorldMapPane.md) construction and UInt32Vector support. |
| `0x00512840` | `sub_512840` | `0x5f` | No-caller support/free helper candidate after `0x00511db0`; roadmap-only. |
| `0x005128a0` | `___std_parallel_algorithms_hw_threads@0_1` | `0x5d` | No-caller allocator/support helper with generated-name pollution; roadmap-only. |
| `0x00512900` | `sub_512900` | `0x5d` | No-caller allocator/support helper; raw scan found an RVA byte-pattern hit but no IDA xref or branch route, so roadmap-only. |
| `0x00512960` | `sub_512960` | `0x344` | Later combat/action/status packet candidate, dispatcher call at `0x0050837e`, opcode `0x13`; calls [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay](../../../../../by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md) and `0x00511c90`. |
| `0x00512d60` | `sub_512D60` | `0x1bc` | Later object update/action packet candidate, dispatcher call at `0x0050838f`, opcode `0x16`. |
| `0x00512f20` | `sub_512F20` | `0x3e5` | Later animation/sound packet candidate, dispatcher call at `0x005083a0`, opcode `0x19`; not in this batch. |
| `0x00513310` | `sub_513310` | `0x36b` | Later status packet candidate, dispatcher call at `0x005083b1`, opcode `0x1d`; not in this batch. |
| `0x00513800` | `sub_513800` | `0x120` | Existing child [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](../../../../../by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md), no direct xrefs currently reported. |

Important IDA facts for `0x005104d0`:

- `analyze_function(0x005104d0)` reports prototype `char __thiscall(int this, int)`, size `0x488`, caller `sub_507C90`, and xref-to at `0x00507f10`.
- Callees include `sub_516030`, `sub_575480`, `sub_516220`, `MultiByteToWideChar`, `ObjectList_Constructor`, `sub_50DB50`, `sub_50D840`, `sub_50A8B0`, `sub_504B90`, `sub_504E00`, `sub_505CC0`, and object/list cleanup support.
- Decompilation parses multiple packet fields: three 16-bit values near payload offsets `+1`, `+3`, and `+5`; flag bytes at later payload offsets; a counted ANSI string converted to UTF-16; and a packed value later split into weather/lighting factors.
- The handler updates MapPane state fields around map dimensions/identity, rebuilds object-list state when map identity/dimensions change, calls the map-state/weather setter, invalidates/redraws map view state, updates day/night/fade math through `dword_66DD78` and `0x0050a8b0`, clears old transient child pointers, and touches the current asset/layout selector `byte_66DA97` / `g_useEpfAssets`.

Important IDA facts for `0x00510960`:

- `analyze_function(0x00510960)` reports prototype `char __thiscall(int this, int)`, size `0x9e7`, caller `sub_507C90`, and xref-to at `0x00507ffa`.
- Callees include `sub_516030`, `sub_516220`, `MultiByteToWideChar`, `wcscpy_s`, `wcscat_s`, `sub_4B7C50`, `sub_4B7CC0`, `sub_575480`, `sub_575730`, `sub_50D8E0`, `sub_505370`, `sub_5040A0`, and [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](../../../../../by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md).
- Decompilation branches on `byte_66DA97` / `g_useEpfAssets`, parses optional map/palette name strings into `MapPane` string buffers, appends EPF/PAL-style suffixes, updates a map-mode byte, constructs/clips rectangular tile regions, writes tile descriptor words/flags into the MapPane tile buffer, marks changed tiles through `sub_50D8E0`, computes a dirty/refresh region, and calls `0x0050f130` at `0x00510e28` and `0x00511318`.
- This is the strongest source route for opcode `0x06` map-info/tile-region update behavior. It depends on [UID:0003TJ] but remains MapPane-owned packet parsing rather than StaticObjectPane or ObjectList ownership.

Padding and raw seam facts:

- `make_signature_for_range(0x005104c7, 0x005104d0, wildcard_operands=false)` returns nine `0xcc` bytes.
- `make_signature_for_range(0x00510958, 0x00510960, wildcard_operands=false)` returns eight `0xcc` bytes.
- `make_signature_for_range(0x00511347, 0x00511350, wildcard_operands=false)` returns nine `0xcc` bytes.
- `lookup_funcs 0x00511350` reports `Not a function`; `make_signature_for_range(0x00511340, 0x00511440, wildcard_operands=false)` shows the tail of `sub_510960`, nine `0xcc` bytes, a raw prologue/body starting at `0x00511350`, twelve `0xcc` bytes at `0x00511414-0x00511420`, then the two `B0 01 C2 04 00` true-return stubs at `0x00511420` and `0x00511430`.
- `decompile(0x00511420)` and `decompile(0x00511430)` each produce `char __stdcall ... { return 1; }`, with no callers or xrefs-to.

Later broad-leaf raw seam facts:

- Raw bytes `0x00511997-0x00511c90` are not pure padding. They contain jump-table-like dwords and raw prologue-shaped starts at `0x005119b0`, `0x005119f0`, `0x00511ad0`, `0x00511b70`, and `0x00511c60`; `lookup_funcs` reports none of those starts as IDA functions.
- Raw bytes `0x00512ca4-0x00512d60` are not pure padding. They contain a raw prologue-shaped start at `0x00512cb0`; `lookup_funcs` reports not a function.
- Raw bytes `0x0051367b-0x00513800` are not pure padding. They contain raw prologue-shaped starts at `0x00513680`, `0x00513780`, and `0x005137d0`; `lookup_funcs` reports not functions.
- Local PE route scans for those raw starts found no absolute VA dwords, RVA dwords, or `E8`/`E9` rel32 branch hits. They need a separate retained-helper/dead-duplicate/source-placement pass before any exact child or ignored row can be recommended.

### Raw PE Scan

Local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` searched absolute VA dwords, RVA dwords, and executable `E8`/`E9` rel32 branch/call encodings for the required route leads:

| Target | Absolute VA hits | RVA hits | Relative call/jump hits |
|---|---:|---:|---|
| `0x005104d0` | 0 | 0 | 1: call at `0x00507f10` |
| `0x00510960` | 0 | 0 | 1: call at `0x00507ffa` |
| `0x00511350` | 0 | 0 | 0 |
| `0x00511420` | 0 | 0 | 0 |
| `0x00511430` | 0 | 0 | 0 |
| `0x00511440` | 0 | 1 byte-pattern hit not backed by IDA xrefs | 1: call at `0x0050800b` |
| `0x00511710` | 0 | 0 | 1: call at `0x0050801c` |
| `0x00511c90` | 0 | 0 | 2: calls at `0x005082f6` and `0x00512c04` |
| `0x00511db0` | 0 | 0 | 1: call at `0x00508307` |
| `0x00512840` | 0 | 0 | 0 |
| `0x005128a0` | 0 | 0 | 0 |
| `0x00512900` | 0 | 1 byte-pattern hit not backed by IDA xrefs | 0 |
| `0x00512960` | 0 | 0 | 1: call at `0x0050837e` |
| `0x00512d60` | 0 | 0 | 1: call at `0x0050838f` |
| `0x00512f20` | 0 | 0 | 1: call at `0x005083a0` |
| `0x00513310` | 0 | 0 | 1: call at `0x005083b1` |
| `0x00513800` | 0 | 0 | 0 |

The raw scan agrees with IDA for the two recommended children and for the later modeled dispatcher routes. It also confirms that the raw/no-function starts and no-caller stubs are not safely reachable through obvious pointer or branch encodings.

### Documentation Evidence

Checked support pages:

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](../../../../../by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) already identifies `0x005104d0` as the modeled effect/map-state packet handler and `0x00510960` as the map info/object-removal packet helper, but leaves both inside the largest broad leaf.
- [UID:00007Q][MapPane](../../../../../by-class/MapPane.md) and [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) already place packet/object/weather/map-transition methods under MapPane and track unresolved packet structures/final names.
- [UID:0001SO][MapServerPacketOpcode](../../../../../by-type/by-enum/MapServerPacketOpcode.md) maps opcode `0x15` to `0x005104d0` and opcode `0x06` to `0x00510960`, with explicit caveats that names are working labels and payload structures are not final.
- [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](../../../../../by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) confirms the tile-region refresh helper called by `0x00510960` at two sites.
- [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](../../../../../by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) ends immediately before the first new padding row and documents the neighboring raw duplicate day/night body and its dispatcher equivalence.
- [UID:0000PB][WorldMapPane](../../../../../by-file/WorldMapPane.md), [UID:0000G9][WorldMapPane](../../../../../by-class/WorldMapPane.md), and [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](../../../../../by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) confirm that WorldMapPane implementation is a separate `map/WorldMapPane.cpp` module. The later `0x00511db0` packet helper may construct WorldMapPane, but current source-placement evidence keeps packet parsing and world-map route selection under MapPane.
- [UID:0003JH][0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings](../../../../../by-memory/0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md) and [UID:0003JJ][0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings](../../../../../by-memory/0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md) show the later `0x00511db0` world-map string comparisons are MapPane-side source data, reinforcing MapPane ownership for packet parsing while preserving WorldMapPane implementation ownership.

## Rejected Alternatives

- Reclassify [UID:0001AW] now: rejected. This batch removes the first clean broad-leaf slice, but the parent still contains source-bearing modeled handlers, raw no-function bodies, no-caller stubs, and existing children after `0x00511350`. Parent remains reconstructable and emitting through MapPane until later batches cover or reclassify those remaining leaves.
- Create one large child `0x005104c7-0x00513800`: rejected. Live IDA proves this is not one function or one source method; it mixes padding, modeled handlers, raw function-shaped no-function bodies, true-return stubs, jump-table-like data, and existing child [UID:0001AY].
- Create `0x00511350-0x00511414` now: rejected. It is function-shaped but not an IDA function, has no xrefs/callers, and raw PE scan found no absolute VA/RVA/relative branch route. It may be retained duplicate/dead code or a source-local helper with lost route evidence. That cannot clear an 85/85 executable child gate.
- Create `0x00511420-0x00511425` or `0x00511430-0x00511435` now: rejected. They decompile to no-caller `return 1` stubs. Without a dispatcher/table/pointer route, they should stay roadmap-only no-op/ack evidence.
- Create later direct handlers in this batch: rejected only for batch scope. `0x00511440`, `0x00511710`, `0x00511c90`, `0x00511db0`, `0x00512960`, `0x00512d60`, `0x00512f20`, and `0x00513310` have direct evidence and likely can become future child pages, but crossing the unresolved raw seam would make this batch less directly executable.
- Reroute `0x00510960` to StaticObjectPane or ObjectList: rejected. It calls the MapPane-owned static-object tile refresh helper and object/list helpers, but it owns packet parsing, tile descriptor updates, and MapPane dirty-region computation.
- Reroute the later `0x00511db0` world-map path to WorldMapPane: rejected for this batch and as an ownership model. MapPane owns the packet parsing and selection of when to create/show a WorldMapPane; WorldMapPane owns the constructed UI implementation and its exact children.
- Emit final C++ for the new children: rejected. Exact helper names, packet payload structures, MapPane field names, string/palette suffix naming, and global names remain provisional.

## Executable Supervisor Batch

### Create Child Page [UID:0003TK]

Create:

`by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md`

With exact content:

```markdown
*** UID:0003TK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x005104d0-0x00510958 MapPane Handle Effect Map-State Packet

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane packet-handler child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneHandleEffectMapStatePacket`.
- Packet route: opcode `0x15` / effect packet in [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md).
- Confidence: strong for exact range, dispatcher caller, raw PE branch route, map-state/weather/effect behavior, MapPane ownership, and adjacent padding; medium-high for final packet-field, helper, and MapPane field names.
- Reconstruction note: C++ intentionally blank. Final source needs named packet payload fields, map-state/weather helper names, day/night table ownership, and MapPane field names.

## Address Range

- Start: `0x005104d0`
- End: `0x00510958` end-exclusive
- IDA function: `sub_5104D0`
- IDA size: `0x488` bytes
- Preceded by ignored padding `0x005104c7-0x005104d0` after [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md).
- Followed by ignored padding `0x00510958-0x00510960` before sibling child [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md).

## Behavior

This packet handler applies map-state, environment/effect, and day-night related state to the live `MapPane`:

- reads several packed payload fields, including 16-bit map/dimension values, flag bytes, a counted ANSI string converted to UTF-16, and a packed weather/lighting factor;
- detects map identity or dimension changes, clears transient state, rebuilds object-list state, stores new dimensions/identity fields, and invalidates/redraws MapPane state;
- calls the MapPane map-state/weather helper `sub_50DB50`, tile/render refresh helper `sub_50D840`, map-file or map-cache helpers `sub_504B90`/`sub_504E00`, and state refresh helper `sub_505CC0`;
- updates day/night scale and bias behavior through the same `dword_66DD78` table and `0x0050a8b0` apply helper used by the raw day/night evidence [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md);
- clears old transient child pointers and schedules object/list cleanup as needed;
- returns success.

## IDA MCP Evidence

- B001 live IDA MCP session `b001_mappane_0001AW_20260616` reports `sub_5104D0` at `0x005104d0`, size `0x488`.
- `analyze_function(0x005104d0)` reports prototype `char __thiscall(int this, int)`.
- Callers: `sub_507C90`.
- Xrefs-to: one code xref at `0x00507f10`.
- Direct callees include `sub_516030`, `sub_575480`, `sub_516220`, `MultiByteToWideChar`, `ObjectList_Constructor`, `sub_50DB50`, `sub_50D840`, `sub_50A8B0`, `sub_504B90`, `sub_504E00`, `sub_505CC0`, `sub_532B80`, and child cleanup support.
- Decompilation shows payload parsing, map identity/dimension comparison, ObjectList reconstruction, map-state/weather update, redraw/invalidations, day/night factor computation from `dword_66DD78`, and a final success return.
- Raw PE scan of `NexusTK.exe` confirms one `E8` rel32 call to `0x005104d0` at `0x00507f10`; no absolute VA or RVA pointer hits were found.
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) records opcode `0x15` dispatching to `0x005104d0`.
- B001 byte-signature review confirms preceding bytes `0x005104c7-0x005104d0` are nine `0xcc` bytes and following bytes `0x00510958-0x00510960` are eight `0xcc` bytes.

## Ownership Decision

This body belongs to `MapPane` because it parses a map-scoped inbound packet and directly mutates MapPane map-state, object-list, weather/effect, day/night, and redraw fields. ObjectList, packet reader helpers, and map-cache helpers are dependencies; they are not stronger source owners for the packet handler body.

## Rejected Owners

- [UID:0000L3][MapPane](by-file/MapPane.md) as direct canonical owner: rejected only as too broad for this child; [UID:00007Q][MapPane](by-class/MapPane.md) is the narrower direct owner, with file emission through MapPane.
- [UID:00009Q][ObjectList](by-class/ObjectList.md): constructed/reset storage dependency only.
- Socket/protocol table owners: dispatcher metadata and byte readers support the route, but MapPane owns this map-state behavior.
- [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md): neighboring raw duplicate evidence for opcode `0x20`, not the owner of this modeled opcode `0x15` handler.

## Score Rationale

Completion is `86` because exact range, dispatcher caller, raw PE call hit, decompiled behavior, map-state/weather/day-night behavior, ObjectList dependency, ownership decision, rejected owners, and adjacent padding are documented. Confidence is `90` because IDA, raw PE, opcode documentation, and MapPane support docs agree on the source route; confidence remains below final-source quality because packet payload, helper, field, and global names remain provisional.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md)
- [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md)
- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch6 recommendation: create this exact child from the remaining [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) broad leaf. Parent remains reconstructable because later source-bearing leaves, raw no-function bodies, and no-caller stubs remain unsplit.
```

### Create Child Page [UID:0003TL]

Create:

`by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md`

With exact content:

```markdown
*** UID:0003TL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x00510960-0x00511347 MapPane Handle Map-Info Tile-Region Packet

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane packet-handler child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneHandleMapInfoTileRegionPacket`.
- Packet route: opcode `0x06` / map info-update route in [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md).
- Confidence: strong for exact range, dispatcher caller, raw PE branch route, map-name/palette/tile-region behavior, two calls to [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md), MapPane ownership, and adjacent padding; medium-high for final packet-field and helper names.
- Reconstruction note: C++ intentionally blank. Final source needs named packet payload structures, map-name/palette buffers, tile descriptor fields, dirty-region helpers, and object-list helper names.

## Address Range

- Start: `0x00510960`
- End: `0x00511347` end-exclusive
- IDA function: `sub_510960`
- IDA size: `0x9e7` bytes
- Preceded by ignored padding `0x00510958-0x00510960` after sibling child [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md).
- Followed by ignored padding `0x00511347-0x00511350` before a raw no-function body at `0x00511350`.

## Behavior

This packet handler updates map-information strings and tile-region state for the live `MapPane`:

- branches on `byte_66DA97` / `g_useEpfAssets`, preserving two layout/resource parsing shapes currently visible in the decompilation;
- reads optional map-name and palette/resource-name strings from the packet, converts ANSI payload text to UTF-16, stores into MapPane string buffers, and appends EPF/PAL-style suffixes for local resource names;
- updates a MapPane map-mode byte and clears/rebuilds dependent state when that mode changes;
- parses a rectangular tile region, clips it against current map dimensions, and writes tile descriptor words/flags into the MapPane tile buffer;
- marks changed tiles through `sub_50D8E0` and computes a dirty/refresh region through `sub_505370`;
- calls [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) at `0x00510e28` and `0x00511318` to reconcile StaticObjectPane children after tile data changes;
- returns success.

## IDA MCP Evidence

- B001 live IDA MCP session `b001_mappane_0001AW_20260616` reports `sub_510960` at `0x00510960`, size `0x9e7`.
- `analyze_function(0x00510960)` reports prototype `char __thiscall(int this, int)`.
- Callers: `sub_507C90`.
- Xrefs-to: one code xref at `0x00507ffa`.
- Direct callees include `sub_516030`, `sub_516220`, `MultiByteToWideChar`, `wcscpy_s`, `wcscat_s`, `sub_4B7C50`, `sub_4B7CC0`, `sub_575480`, `sub_575730`, `sub_50D8E0`, `sub_505370`, `sub_5040A0`, `sub_4F4A90`, and [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md).
- Decompilation shows the handler updating map/resource strings, tile descriptor data, changed-tile invalidation, dirty/refresh regions, and the static-object tile-region reconciliation calls.
- Raw PE scan of `NexusTK.exe` confirms one `E8` rel32 call to `0x00510960` at `0x00507ffa`; no absolute VA or RVA pointer hits were found.
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) records opcode `0x06` dispatching to `0x00510960`.
- B001 byte-signature review confirms preceding bytes `0x00510958-0x00510960` are eight `0xcc` bytes and following bytes `0x00511347-0x00511350` are nine `0xcc` bytes.

## Ownership Decision

This body belongs to `MapPane` because it parses a map-scoped inbound packet, updates MapPane map/resource strings, mutates tile descriptor storage, computes dirty tile regions, and invokes the MapPane static-object refresh helper. StaticObjectPane, ObjectList, and StaticObjImageLib remain dependency/constructed-object/provider owners, not owners of this packet parser.

## Rejected Owners

- [UID:0000L3][MapPane](by-file/MapPane.md) as direct canonical owner: rejected only as too broad for this child; [UID:00007Q][MapPane](by-class/MapPane.md) is the narrower direct owner, with file emission through MapPane.
- [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md): constructed object class reached through [UID:0003TJ], not this packet parser's owner.
- [UID:00009Q][ObjectList](by-class/ObjectList.md): storage/index dependency only.
- Socket/protocol table owners: the packet route is protocol-driven, but the behavior is map/tile state mutation owned by MapPane.
- [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md): callee helper that reconciles static objects after this packet updates tile descriptors.

## Score Rationale

Completion is `86` because exact range, dispatcher caller, raw PE call hit, decompiled string/tile-region behavior, calls to the exact static-object refresh child, ownership decision, rejected owners, and adjacent padding are documented. Confidence is `89` because IDA, raw PE, opcode documentation, and MapPane support docs agree on the route; confidence is one point below the sibling because this function has two layout/resource parsing branches and still depends on unresolved map-name, palette, tile-descriptor, and dirty-region field names.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md)
- [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md)
- [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md)
- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch6 recommendation: create this exact child from the remaining [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) broad leaf. Parent remains reconstructable because later source-bearing leaves, raw no-function bodies, and no-caller stubs remain unsplit.
```

### Parent [UID:0001AW] Edits

Do not change [UID:0001AW] metadata. Keep:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

In the parent exact child table, insert after [UID:0001AX] and before [UID:0001AY]:

```markdown
| [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) | Exact modeled MapPane opcode `0x15` effect/map-state packet handler; updates map identity/dimensions, object-list state, map-state/weather, day/night factors, and redraw state. |
| [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md) | Exact modeled MapPane opcode `0x06` map-info/tile-region packet handler; updates map/resource strings, tile descriptor words/flags, changed-tile invalidation, dirty regions, and calls [UID:0003TJ] for static-object reconciliation. |
```

In `## Current Exact Boundary Inventory`, replace the `0x005104d0` and `0x00510960` rows and insert rows for the newly checked raw seam so the sequence reads:

```markdown
| `0x00510400` | not modeled | none | Raw function-shaped day/night packet duplicate body, separately tracked at [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md). |
| `0x005104d0` | `sub_5104D0` | `0x488` | Exact child [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md); opcode `0x15` effect/map-state packet handler called from dispatcher case at `0x00507f10`. |
| `0x00510960` | `sub_510960` | `0x9e7` | Exact child [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md); opcode `0x06` map-info/tile-region packet handler called from dispatcher case at `0x00507ffa` and calling [UID:0003TJ] at `0x00510e28` and `0x00511318`. |
| `0x00511350` | not modeled | none | Roadmap-only raw function-shaped body after `sub_510960`; live `lookup_funcs` reports no IDA function, raw PE scan found no direct VA/RVA/relative-branch route, and the source placement/reachability question is unresolved. |
| `0x00511420` | `sub_511420` | `0x5` | Roadmap-only no-caller true-return stub; decompiles to `return 1`, with no xrefs-to and no raw PE route hits. |
| `0x00511430` | `sub_511430` | `0x5` | Roadmap-only no-caller true-return stub; decompiles to `return 1`, with no xrefs-to and no raw PE route hits. |
| `0x00511440` | `sub_511440` | `0x2c3` | Spawn/movement/chat packet helper called from dispatcher case at `0x0050800b`; likely future child after the raw seam is resolved. |
```

Append to the parent evidence/history near the existing batch5 evidence:

```markdown
- 2026-06-16 B001 continuation batch6 live IDA MCP session `b001_mappane_0001AW_20260616`: `entity_query` over `0x005104c7-0x00513800` reports modeled starts at `0x005104d0`, `0x00510960`, `0x00511420`, `0x00511430`, `0x00511440`, `0x00511710`, `0x00511c90`, `0x00511db0`, `0x00512840`, `0x005128a0`, `0x00512900`, `0x00512960`, `0x00512d60`, `0x00512f20`, `0x00513310`, and existing child start `0x00513800`. `analyze_function(0x005104d0)` reports `sub_5104D0` size `0x488`, caller `sub_507C90`, xref at `0x00507f10`, map-state/weather/day-night callees including `sub_50DB50`, `sub_50D840`, `sub_50A8B0`, and ObjectList reconstruction behavior. `analyze_function(0x00510960)` reports `sub_510960` size `0x9e7`, caller `sub_507C90`, xref at `0x00507ffa`, map/resource string and tile-region behavior, and calls to [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) at `0x00510e28` and `0x00511318`. A raw PE scan confirms one relative call each to `0x005104d0` and `0x00510960`, direct later dispatcher calls to `0x00511440`, `0x00511710`, `0x00511c90`, `0x00511db0`, `0x00512960`, `0x00512d60`, `0x00512f20`, and `0x00513310`, and no route hits to raw/no-caller starts `0x00511350`, `0x00511420`, or `0x00511430`. `make_signature_for_range` confirms `0x005104c7-0x005104d0`, `0x00510958-0x00510960`, and `0x00511347-0x00511350` as `0xcc` padding. The same pass found raw no-function prologue-shaped seams at `0x00511350`, `0x005119b0`, `0x005119f0`, `0x00511ad0`, `0x00511b70`, `0x00511c60`, `0x00512cb0`, `0x00513680`, `0x00513780`, and `0x005137d0`; these remain roadmap-only retained-helper/source-placement questions.
```

Append to the parent Cross-References list after [UID:0001AX]:

```markdown
- [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md)
- [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md)
```

Append to the parent Changes section:

```markdown
- 2026-06-16 B001 continuation split batch6: create exact children [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) and [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md), plus ignored padding `0x005104c7-0x005104d0`, `0x00510958-0x00510960`, and `0x00511347-0x00511350`. Parent [UID:0001AW] remains `RECONSTRUCTABLE:TRUE`, `85/88`, and owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md) because later modeled packet handlers, raw no-function helper bodies, true-return stubs, and existing child islands still need exact split/source-placement work.
```

### Support Doc Edits

No support doc score or metadata changes are recommended.

In [UID:00007Q][MapPane](../../../../../by-class/MapPane.md), insert these Cross-References lines after [UID:0001AX]:

```markdown
- [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md)
- [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md)
```

In [UID:00007Q][MapPane](../../../../../by-class/MapPane.md), append this Changes entry above the existing batch5 entry:

```markdown
- 2026-06-16 B001 continuation split batch6:
  - Score unchanged at `85/85`.
  - Added exact MapPane packet children [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) and [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md). The children document MapPane-owned effect/map-state and map-info/tile-region packet routes while keeping ObjectList, StaticObjectPane, resource libraries, and protocol tables as dependencies rather than owners.
```

In [UID:0000L3][MapPane](../../../../../by-file/MapPane.md), insert these Cross-References lines after [UID:0001AX]:

```markdown
- [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md)
- [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md)
```

In [UID:0000L3][MapPane](../../../../../by-file/MapPane.md), append this Changes entry above the existing batch5 entry:

```markdown
- 2026-06-16 B001 continuation split batch6:
  - Score unchanged at `89/85`.
  - Added exact children [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) and [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md) under the MapPane packet/map-state/tile-region family. ObjectList, StaticObjectPane, resource libraries, and Socket/protocol documentation remain dependency/provider/index owners rather than owners of these MapPane methods.
```

No changes are required to [UID:0001SO][MapServerPacketOpcode](../../../../../by-type/by-enum/MapServerPacketOpcode.md). It already records opcode `0x15 -> 0x005104d0` and `0x06 -> 0x00510960`, and its score remains capped by broader packet-name/payload questions rather than by the absence of these exact child pages.

No changes are required to WorldMapPane support pages in this batch. The later `0x00511db0` route was checked against [UID:0000PB][WorldMapPane](../../../../../by-file/WorldMapPane.md), [UID:0000G9][WorldMapPane](../../../../../by-class/WorldMapPane.md), and [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](../../../../../by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md); current ownership split is already correct.

### by-memory/-ignored.md Entries

Insert after the existing `0x0050f26d-0x0050f270` entry and before `0x00514e1b-0x00514e20`:

```markdown
- `0x005104c7-0x005104d0` - alignment padding after `MapPaneDayNightPacketRawBody`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the retained raw day/night packet body and before the exact modeled effect/map-state packet handler.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows nine `0xcc` bytes at `0x005104c7-0x005104d0`; [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) ends at `0x005104c7`, and `analyze_function(0x005104d0)` reports the next modeled function starts at `0x005104d0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md), [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md), and [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md).

- `0x00510958-0x00510960` - alignment padding after `MapPaneHandleEffectMapStatePacket`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the exact effect/map-state packet child and before the exact map-info/tile-region packet child.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eight `0xcc` bytes at `0x00510958-0x00510960`; `analyze_function(0x005104d0)` reports `sub_5104D0` size `0x488`, and `analyze_function(0x00510960)` reports the next modeled function starts at `0x00510960`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md), [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md), and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x00511347-0x00511350` - alignment padding after `MapPaneHandleMapInfoTileRegionPacket`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the exact map-info/tile-region packet child and before a raw no-function body at `0x00511350`.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows nine `0xcc` bytes at `0x00511347-0x00511350`; `analyze_function(0x00510960)` reports `sub_510960` size `0x9e7`, and `lookup_funcs 0x00511350` reports `Not a function` even though raw bytes show a function-shaped prologue there.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md) and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
```

### by-memory/-coverage-report.md Rows

Do not edit `by-memory/-coverage-report.md` directly as B001. Use this existing row as placement context only; do not duplicate it:

```markdown
        - [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) 0x00510400-0x005104c7 | raw duplicate packet-handler body | MapPaneDayNightPacketRawBody : reconstructable : 84% : strong : Retained raw MapPane opcode `0x20` day/night body; live IDA confirms no modeled function, exact `retn 4` endpoint and padding, no raw-start xrefs/callers/pointer-table hits, dispatcher case `32` equivalence, day/night table and apply-helper xrefs, touched MapPane lighting/fade fields, MapPane parent, and final C++ gate remains blank.
```

Insert the following five rows immediately after that existing context row and before the existing [UID:0001AY] row:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005104c7-0x005104d0 | padding | MapPaneDayNightPacketRawBody to MapPaneHandleEffectMapStatePacket alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows nine `0xcc` bytes after [UID:0001AX] end-exclusive `0x005104c7` and before modeled function `sub_5104D0` starts at `0x005104d0`.
        - [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) 0x005104d0-0x00510958 | class method/packet handler | MapPaneHandleEffectMapStatePacket : reconstructable : 86% : strong : Exact modeled `sub_5104D0` child split from MapPanePacketHandlers; live IDA and raw PE confirm the dispatcher call at `0x00507f10`; handler parses opcode `0x15` map-state/effect payload data, updates map identity/dimensions, object-list state, map-state/weather, day/night factors, and redraw state. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); ObjectList, packet reader helpers, and resource helpers remain dependencies. Final C++ blank pending final packet, field, helper, and global names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00510958-0x00510960 | padding | MapPaneHandleEffectMapStatePacket to MapPaneHandleMapInfoTileRegionPacket alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eight `0xcc` bytes after `sub_5104D0` end-exclusive `0x00510958` and before modeled function `sub_510960` starts at `0x00510960`.
        - [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md) 0x00510960-0x00511347 | class method/packet handler | MapPaneHandleMapInfoTileRegionPacket : reconstructable : 86% : strong : Exact modeled `sub_510960` child split from MapPanePacketHandlers; live IDA and raw PE confirm the dispatcher call at `0x00507ffa`; handler parses opcode `0x06` map-info/tile-region data, updates map/resource strings, tile descriptor words/flags, changed-tile invalidation, dirty regions, and calls [UID:0003TJ] at `0x00510e28` and `0x00511318` for static-object reconciliation. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); StaticObjectPane, ObjectList, and protocol tables remain dependencies/providers. Final C++ blank pending final packet, field, string-buffer, and helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00511347-0x00511350 | padding | MapPaneHandleMapInfoTileRegionPacket to raw no-function packet body alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows nine `0xcc` bytes after `sub_510960` end-exclusive `0x00511347` and before raw no-function bytes at `0x00511350`.
```

Parent [UID:0001AW] row remains unchanged.

### IDA DB Recommendation

No IDA DB edits are recommended.

IDA already has correct modeled boundaries for `sub_5104D0` and `sub_510960`. Do not force-create a function at `0x00511350` or rename the no-caller stubs at `0x00511420`/`0x00511430`: current raw PE scans found no branch or pointer routes, and the source-placement question is unresolved. Manual IDA function repair there would overstate reachability.

### Validation Order

Supervisor validation order after applying the batch:

1. Create [UID:0003TK] and [UID:0003TL] child pages exactly as above.
2. Apply [UID:0001AW] parent child-table, boundary-inventory, evidence, cross-reference, and Changes additions.
3. Apply MapPane class/file cross-reference and Changes additions.
4. Apply the three `by-memory/-ignored.md` entries.
5. Insert the five coverage rows under [UID:0001AW] after the existing [UID:0001AX] row and before [UID:0001AY].
6. Run scoped validator passes for both new child pages, [UID:0001AW], [UID:00007Q], [UID:0000L3], `by-memory/-ignored.md`, and `by-memory/-coverage-report.md`.
7. Run `python .\tools\memory_ranges.py report` and confirm Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan remain `None`.
8. Confirm [UID:0001AW] still remains `RECONSTRUCTABLE:TRUE`, `85/88`, owner/emitter [UID:00007Q], and blank final C++.

## Remaining Blockers and Next Follow-Up

- `0x00511350-0x00511414`: investigated with IDA `lookup_funcs`, raw byte signature, and raw PE route scan. It is function-shaped, but not an IDA function and has no xrefs/callers/pointer/branch route. It cannot safely be classified as source-emitting, retained duplicate, or dead code yet.
- `0x00511420-0x00511425` and `0x00511430-0x00511435`: investigated with IDA `analyze_function`, `decompile`, xrefs, and raw PE scan. Both are 5-byte `return 1` stubs with no callers or route hits. Keep roadmap-only until their packet/no-op role is proven.
- `0x00511440`, `0x00511710`, `0x00511c90`, `0x00511db0`, `0x00512960`, `0x00512d60`, `0x00512f20`, and `0x00513310`: investigated with IDA function inventory, `analyze_function` summaries, opcode docs, and raw PE branch scans. They are likely direct future children, but they are after unresolved raw seams and need their own exact page content and source-quality naming before creation.
- `0x00511997-0x00511c90`, `0x00512ca4-0x00512d60`, and `0x0051367b-0x00513800`: investigated with raw-byte scans and `lookup_funcs`. They include jump-table-like data and raw prologue-shaped no-function starts. Do not ignore or emit them until a focused raw-helper/source-placement pass resolves them.
- WorldMapPane boundary: checked [UID:0000PB], [UID:0000G9], [UID:0001O4], [UID:0003JH], and [UID:0003JJ]. Current evidence keeps `0x00511db0` as a MapPane packet parser that constructs or routes to WorldMapPane, not a WorldMapPane-owned source body.
- Final C++ blockers for the new children: exact packet structure names, original helper names, MapPane field names, map string/palette buffer names, tile descriptor fields, day/night table name, and layout/global names remain provisional. The new child pages clear the documentation/ownership gate but should keep final C++ blank.

## No-Direct-Edit Confirmation

B001 created this research report only:

- Created: `tools/leaser/Agents/Agent-B001/research/0001AW-mappane-packet-source-split-continuation-batch6.md`
- Modified: none outside the research report.
- IDA DB: no edits.
- Generated reports and `by-memory/-coverage-report.md`: no direct edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch6.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001AW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
