** TARGET-REPORT-UID:0001AW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AW MapPane Packet Source Split Continuation Batch7

Assignment: `B001-goal2-memory-tool-mappane-packet-source-split-continuation7-0001AW-20260616`  
Agent: B001  
Target: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](../../../../../by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)

## Final Recommendation

Create the next bounded executable child batch now:

- [UID:0003TM] `0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md`, `86/90`, owner/emitter [UID:00007Q][MapPane](../../../../../by-class/MapPane.md).
- [UID:0003TN] `0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md`, `86/90`, owner/emitter [UID:00007Q][MapPane](../../../../../by-class/MapPane.md).
- Add ignored padding rows for `0x00511414-0x00511420`, `0x00511425-0x00511430`, `0x00511435-0x00511440`, and `0x00511703-0x00511710`.
- Keep [UID:0001AW] `COMPLETION:85`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q`, and blank final C++.

Do not create children in this batch for the raw no-function body `0x00511350-0x00511414`, no-caller true-return stubs `0x00511420` and `0x00511430`, or the raw/jump-table seam `0x00511997-0x00511c90`. Do not reclassify [UID:0001AW] yet; source-bearing modeled handlers and raw seams still remain after `0x00511997`.

No by-* documentation, generated report, IDA DB, or `by-memory/-coverage-report.md` file was directly edited by B001. This report is the only file created.

## Current State Checked

- Parent [UID:0001AW] is currently `85/88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, with blank final C++.
- Supervisor-executed children [UID:0003TB]-[UID:0003TL] now cover exact ranges through [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](../../../../../by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md), plus ignored padding `0x00511347-0x00511350`.
- `auto-generated/by-memory-tool-report.md` was regenerated at `2026-06-16 06:18:38`; Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan all report `None`.
- The largest-range report still lists [UID:0001AW] leaf `0x00511347-0x00513800` as rank 28, `9401` bytes, reconstructable.
- UID allocation assumption: latest executed child is [UID:0003TL]. If no intervening supervisor allocation occurred, use [UID:0003TM] and [UID:0003TN] for this batch. If the allocator has advanced, replace every [UID:0003TM]/[UID:0003TN] reference in the proposed text consistently.

## Evidence Checked

### Live IDA MCP

Session: `b001_mappane_0001AW_20260616`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`. `idb_list` shows the worker session is active and not analyzing. `server_health` reports status `ok`, Hex-Rays ready, and strings cache ready.

Function inventory for the required focus range:

| Start | IDA name | Size | Current result |
|---|---|---:|---|
| `0x00511350` | not modeled | none | Raw function-shaped body after [UID:0003TL]; `lookup_funcs` says not a function, `xrefs_to` is empty, and raw PE scan found no VA/RVA/relative-branch route. Roadmap-only. |
| `0x00511420` | `sub_511420` | `0x5` | No-caller true-return stub; decompiles to `return 1`, no callees, empty xrefs. Roadmap-only. |
| `0x00511430` | `sub_511430` | `0x5` | No-caller true-return stub; decompiles to `return 1`, no callees, empty xrefs. Roadmap-only. |
| `0x00511440` | `sub_511440` | `0x2c3` | Executable child for this batch; direct dispatcher xref at `0x0050800b`; opcode `0x07` / `kServerDrawObjects` in [UID:0001SO][MapServerPacketOpcode](../../../../../by-type/by-enum/MapServerPacketOpcode.md). |
| `0x00511710` | `sub_511710` | `0x287` | Executable child for this batch; direct dispatcher xref at `0x0050801c`; opcode `0x0d` movement packet in [UID:0001SO][MapServerPacketOpcode](../../../../../by-type/by-enum/MapServerPacketOpcode.md). |
| `0x00511997` | not modeled | none | Raw/jump-table seam after `sub_511710`; not pure padding and not safe to ignore. |
| `0x00511c90` | `sub_511C90` | `0x11e` | Later object/effect move packet helper; direct dispatcher xref at `0x005082f6`, internal caller `0x00512c04`. Roadmap-only for later batch. |
| `0x00511db0` | `sub_511DB0` | `0xa8a` | Later object/world-map creation helper; direct dispatcher xref at `0x00508307`, calls WorldMapPane constructor path. Roadmap-only for later batch. |
| `0x00512960` | `sub_512960` | `0x344` | Later action/combat/status handler; direct dispatcher xref at `0x0050837e`, calls [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay](../../../../../by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md) and `0x00511c90`. |
| `0x00512d60` | `sub_512D60` | `0x1bc` | Later object update/flying-object handler; direct dispatcher xref at `0x0050838f`. |
| `0x00512f20` | `sub_512F20` | `0x3e5` | Later animation/sound handler; direct dispatcher xref at `0x005083a0`. |
| `0x00513310` | `sub_513310` | `0x36b` | Later status/update handler; direct dispatcher xref at `0x005083b1`. |

Important IDA facts for `0x00511440`:

- `analyze_function(0x00511440)` reports prototype `char __thiscall(int this, int)`, size `0x2c3`, caller `sub_507C90`, and xref-to at `0x0050800b`.
- Callees include `sub_575480`, `sub_5754C0`, [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](../../../../../by-memory/0x00575370-0x00575377.GetConnectionStatus.md), `_time64`, `srand`, `rand`, rectangle helpers `sub_4B7E30`/`sub_4B7E80`, object create/update helper `sub_505E00`, and [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](../../../../../by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md).
- Decompilation reads a record count, applies the same connection-status randomized gate documented for the dispatcher and `GetConnectionStatus`, loops over object placement records, clamps visible bounds from MapPane dimensions/viewport fields, creates or updates visible object panes through `0x00505e00`, optionally sets a returned object flag at `+0x1d2`, and dispatches nested object-effect descriptors through `0x0050e320`.
- [UID:000232] already records this call site at `0x005116cc` as an object-effect descriptor dispatch from the spawn/object-placement path.

Important IDA facts for `0x00511710`:

- `analyze_function(0x00511710)` reports prototype `char __thiscall(_DWORD *this, int)`, size `0x287`, caller `sub_507C90`, and xref-to at `0x0050801c`.
- Callees include object lookup `sub_532370`, `MultiByteToWideChar`, `PoolAllocator_Allocate`, `sub_5374D0`, [UID:00000U][BalloonObjectPane](../../../../../by-class/BalloonObjectPane.md) constructor `0x004682c0`, registration helper `sub_53ADA0`, ObjectList insertion `sub_5314A0`, timer scheduling `sub_597910`, and bounds helper `sub_4B8E00`.
- Decompilation reads a subtype byte, object id, text byte count, and optional two extra dwords for subtype `4`; rejects invalid subtypes and incompatible local-player state; converts packet text to UTF-16; maps subtypes `0..4` to style constants `143`, `14`, `9`, `200`, and `253`; allocates/constructs/registers a BalloonObjectPane; schedules a `3000` ms timer; and refreshes bounds.
- [UID:00000U][BalloonObjectPane](../../../../../by-class/BalloonObjectPane.md), [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](../../../../../by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md), and [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](../../../../../by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md) all record `0x00511710` as a BalloonObjectPane allocation/constructor caller.

Raw seam and padding facts:

- `make_signature_for_range(0x00511340, 0x00511440, wildcard_operands=false)` shows the tail of `sub_510960`, nine `0xcc` bytes at `0x00511347-0x00511350`, a raw prologue/body at `0x00511350-0x00511414`, twelve `0xcc` bytes at `0x00511414-0x00511420`, a `B0 01 C2 04 00` true-return stub at `0x00511420`, eleven `0xcc` bytes at `0x00511425-0x00511430`, another `B0 01 C2 04 00` true-return stub at `0x00511430`, and eleven `0xcc` bytes at `0x00511435-0x00511440`.
- `analyze_function(0x00511420, include_asm=true)` and `analyze_function(0x00511430, include_asm=true)` both show `mov al, 1; retn 4`, no strings, no constants, no callees, no callers, and empty xrefs-to.
- `make_signature_for_range(0x00511703, 0x00511710, wildcard_operands=false)` shows thirteen `0xcc` bytes after `sub_511440` and before `sub_511710`.
- `make_signature_for_range(0x00511997, 0x00511c90, wildcard_operands=false)` is unique and not padding. It starts with jump-table-like dwords around `0x00511890`, then contains raw prologue-shaped bodies at `0x005119b0`, `0x005119f0`, `0x00511ad0`, `0x00511b70`, and `0x00511c60`.
- `lookup_funcs` reports `0x00511997`, `0x005119b0`, `0x005119f0`, `0x00511ad0`, `0x00511b70`, and `0x00511c60` are not functions. `xrefs_to` reports no xrefs to any of those raw starts. [UID:0001HY][GetConnectionStatus](../../../../../by-memory/0x00575370-0x00575377.GetConnectionStatus.md) records one code reference inside this undefined island at `0x00511a3c`, but that is not a route to the island start and does not make the whole seam safely source-emitting or ignorable.

Later candidate facts checked for batch stop:

- `analyze_function(0x00511c90)` reports size `0x11e`, callers `sub_507C90` and `sub_512960`, and calls to [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](../../../../../by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md) plus [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](../../../../../by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md). This is likely an executable future child, but it is after the unresolved seam.
- `analyze_function(0x00511db0)` reports size `0xa8a`, dispatcher caller `0x00508307`, `UInt32Vector` temporary construction, MapPane world-map comparison strings, shared `WM2` string use, and a WorldMapPane construction call. Packet parsing remains MapPane-owned; WorldMapPane owns the constructed pane implementation.
- `analyze_function(0x00512960)`, `0x00512d60`, `0x00512f20`, and `0x00513310` confirms later dispatcher-called handlers with direct calls from `sub_507C90`. They remain future batches because batch7 is intentionally bounded before the raw/jump-table seam at `0x00511997`.

### Local Raw PE Scan

Local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` searched absolute VA dwords, RVA dwords, and executable `E8`/`E9` rel32 branch/call encodings for the required route leads:

| Target | Absolute VA hits | RVA hits | Relative call/jump hits |
|---|---:|---:|---|
| `0x00511350` | 0 | 0 | 0 |
| `0x00511420` | 0 | 0 | 0 |
| `0x00511430` | 0 | 0 | 0 |
| `0x00511440` | 0 | 1 byte-pattern hit at `0x00411d86`, not backed by IDA xrefs | `0x0050800b` |
| `0x00511710` | 0 | 0 | `0x0050801c` |
| `0x005119b0` | 0 | 0 | 0 |
| `0x005119f0` | 0 | 0 | 0 |
| `0x00511ad0` | 0 | 0 | 0 |
| `0x00511b70` | 0 | 0 | 0 |
| `0x00511c60` | 0 | 0 | 0 |
| `0x00511c90` | 0 | 0 | `0x005082f6`, `0x00512c04` |
| `0x00511db0` | 0 | 0 | `0x00508307` |
| `0x00512cb0` | 0 | 0 | 0 |
| `0x00512d60` | 0 | 0 | `0x0050838f` |
| `0x00512f20` | 0 | 0 | `0x005083a0` |
| `0x00513310` | 0 | 0 | `0x005083b1` |
| `0x00513680` | 0 | 0 | 0 |
| `0x00513780` | 0 | 0 | 0 |
| `0x005137d0` | 0 | 0 | 0 |
| `0x00513800` | 0 | 0 | 0 |

The raw scan agrees with IDA: the two recommended children are direct dispatcher targets; the raw no-function body and no-caller stubs have no obvious branch or pointer route; the post-`0x00511997` raw starts also have no obvious route and need a separate source-placement pass.

### Documentation Evidence

Checked support pages:

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](../../../../../by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) already lists `0x00511440-0x00511996` as spawn/movement/chat packets and tracks the raw no-function body/stubs immediately before `0x00511440`.
- [UID:0001SO][MapServerPacketOpcode](../../../../../by-type/by-enum/MapServerPacketOpcode.md) maps opcode `0x07` to spawn/object placement / `kServerDrawObjects` and dispatcher target `0x00511440`; it maps opcode `0x0d` to movement packet and target `0x00511710`.
- [UID:00007Q][MapPane](../../../../../by-class/MapPane.md), [UID:0000L3][MapPane](../../../../../by-file/MapPane.md), and [UID:0001QG][client_map_system](../../../../../by-meta/client_map_system.md) all keep map-scoped packet parsing and object/world update routing under MapPane.
- [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](../../../../../by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) records the `0x005116cc` call from `0x00511440`, matching the decompiled nested object-effect descriptor loop.
- [UID:0002QN][0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane](../../../../../by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md) records `0x00511664` as an opcode `0x07` spawn/object-placement call site that builds status blobs and creates/updates visible object panes. This page is below the strict gate (`84/strong`), so it is supporting behavioral evidence only, not a reason to route ownership away from MapPane.
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](../../../../../by-memory/0x00575370-0x00575377.GetConnectionStatus.md) documents the `0x0051147e` status gate in `sub_511440` and the raw-island status-gate ref at `0x00511a3c`, supporting both the `0x00511440` behavior and the decision not to ignore `0x00511997-0x00511c90`.
- [UID:00000U][BalloonObjectPane](../../../../../by-class/BalloonObjectPane.md), [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](../../../../../by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md), and [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](../../../../../by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md) all tie `0x00511710` to BalloonObjectPane allocation/constructor/registration while preserving BalloonObjectPane class and pool ownership.
- [UID:0000PB][WorldMapPane](../../../../../by-file/WorldMapPane.md), [UID:0000G9][WorldMapPane](../../../../../by-class/WorldMapPane.md), [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](../../../../../by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md), [UID:0003JH][0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings](../../../../../by-memory/0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md), and [UID:0003JJ][0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings](../../../../../by-memory/0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md) were checked for the later `0x00511db0` boundary. Current evidence keeps packet parsing in MapPane and WorldMapPane implementation in WorldMapPane.

## Rejected Alternatives

- Reclassify [UID:0001AW] now: rejected. This batch removes two exact modeled handlers, but the parent still contains raw/no-function bodies, no-caller stubs, direct modeled handlers after `0x00511997`, and existing child islands. It remains a reconstructable MapPane packet aggregate until those are split or reclassified.
- Create `0x00511350-0x00511414`: rejected. It is function-shaped but not an IDA function, has no xrefs/callers, and raw PE scan found no absolute VA/RVA/relative branch route. Current evidence cannot distinguish retained duplicate/dead code from a source-local helper with lost route evidence.
- Create `0x00511420-0x00511425` or `0x00511430-0x00511435`: rejected. Both are five-byte `return 1` stubs with no callers, no callees, no xrefs, and no raw route hits. They should stay roadmap-only no-op/ack evidence.
- Ignore `0x00511997-0x00511c90`: rejected. It is not padding; it contains jump-table-like data, raw prologue-shaped no-function bodies, and a documented `GetConnectionStatus` code reference at `0x00511a3c`. It needs a raw-helper/source-placement pass before any child, ignored row, or IDA repair is safe.
- Create `0x00511c90`, `0x00511db0`, `0x00512960`, `0x00512d60`, `0x00512f20`, or `0x00513310` in this batch: rejected for batch scope only. They have direct dispatcher evidence and are likely future children, but creating them now would cross an unresolved raw/jump-table seam.
- Reroute `0x00511440` to ObjectList, ItemObjectPane, LivingObjectPane, or EffectObjectPane: rejected. Those classes are created/updated by the packet body; the packet parsing, visible-range checks, object lookup, and effect descriptor dispatch are MapPane behavior.
- Reroute `0x00511710` to BalloonObjectPane: rejected. BalloonObjectPane owns the constructed overlay class, vtables, constructor, pool, and layout/rendering methods. The packet body owns MapPane-side movement/speech routing, target lookup, text conversion, style selection, attachment, timer scheduling, and object-list registration.
- Reroute `GetConnectionStatus` to MapPane: rejected. [UID:0001HY] already documents Socket ownership for the status getter; `0x00511440` is only a consumer.
- Emit final C++ for either new child: rejected. Exact packet structure names, field names, helper names, object-status blob shape, subtype names, and MapPane member names remain provisional.

## Executable Supervisor Batch

### Create Child Page [UID:0003TM]

Create:

`by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md`

With exact content:

```markdown
*** UID:0003TM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x00511440-0x00511703 MapPane Handle Draw Objects Packet

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane packet-handler child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneHandleDrawObjectsPacket`.
- Packet route: opcode `0x07` / `kServerDrawObjects` in [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md).
- Confidence: strong for exact range, dispatcher caller, raw PE branch route, spawn/object placement behavior, MapPane ownership, and adjacent padding; medium-high for final packet-field, helper, and MapPane field names.
- Reconstruction note: C++ intentionally blank. Final source needs named packet payload fields, object-status blob fields, visible-rectangle helper names, and MapPane member names.

## Address Range

- Start: `0x00511440`
- End: `0x00511703` end-exclusive
- IDA function: `sub_511440`
- IDA size: `0x2c3` bytes
- Preceded by ignored padding `0x00511435-0x00511440` after the no-caller true-return stub at `0x00511430`.
- Followed by ignored padding `0x00511703-0x00511710` before sibling child [UID:0003TN][0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md).

## Behavior

This packet handler applies server draw/spawn records to the live `MapPane`:

- reads a record count from the packet and applies a Socket status randomized throttle through [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md);
- loops over object placement records with packet-derived coordinates, object id/status, direction/type fields, flags, and a nested effect-descriptor count;
- computes and clamps the visible MapPane rectangle from current viewport and map-dimension fields;
- tests each packet record against that rectangle through rectangle helpers;
- calls `sub_505E00` / [UID:0002QN][0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane](by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md) for in-range object creation/update;
- optionally marks a flag byte on the returned object pane;
- when the config flag permits effect processing, calls [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) for nested object-effect descriptors;
- returns success.

## IDA MCP Evidence

- B001 live IDA MCP session `b001_mappane_0001AW_20260616` reports `sub_511440` at `0x00511440`, size `0x2c3`.
- `analyze_function(0x00511440)` reports prototype `char __thiscall(int this, int)`.
- Callers: `sub_507C90`.
- Xrefs-to: one code xref at `0x0050800b`.
- Direct callees include `sub_575480`, `sub_5754C0`, `sub_575370`, `_time64`, `srand`, `rand`, `sub_4B7E30`, `sub_4B7E80`, `sub_505E00`, and `sub_50E320`.
- Decompilation shows count-driven spawn/object-placement parsing, visible-rectangle clipping, object create/update through `0x00505e00`, optional returned-object flag update, and nested object-effect descriptor dispatch through `0x0050e320`.
- Raw PE scan confirms one `E8` rel32 call to `0x00511440` at `0x0050800b`; no absolute VA pointer hits were found. One RVA byte-pattern hit at `0x00411d86` is not backed by IDA xrefs and is treated as a false positive unless later evidence proves otherwise.
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) records opcode `0x07` / `kServerDrawObjects` dispatching to `0x00511440`.
- [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) records the `0x005116cc` call site from this handler.
- B001 byte-signature review confirms preceding bytes `0x00511435-0x00511440` are eleven `0xcc` bytes and following bytes `0x00511703-0x00511710` are thirteen `0xcc` bytes.

## Ownership Decision

This body belongs to `MapPane` because it parses a map-scoped inbound packet, clips records against MapPane viewport/map dimensions, creates or updates objects in the MapPane object list, and dispatches map-object effect descriptors. ObjectList, object-pane classes, EffectObjectPane, and Socket are dependencies or constructed/queried providers, not stronger owners for this packet body.

## Rejected Owners

- [UID:0000L3][MapPane](by-file/MapPane.md) as direct canonical owner: rejected only as too broad for this child; [UID:00007Q][MapPane](by-class/MapPane.md) is the narrower direct owner, with file emission through MapPane.
- [UID:00009Q][ObjectList](by-class/ObjectList.md): target lookup/insertion dependency only.
- [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) and [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md): possible constructed/updated object classes, not packet parser owners.
- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md): effect descriptor consumer/constructed child family only.
- [UID:0000DD][Socket](by-class/Socket.md): owns `GetConnectionStatus`; this handler only consumes the getter.

## Score Rationale

Completion is `86` because exact range, dispatcher caller, raw PE call hit, decompiled object-placement behavior, effect-descriptor callout, MapPane ownership, rejected owners, and adjacent padding are documented. Confidence is `90` because IDA, raw PE, opcode documentation, and MapPane support docs agree on the source route; confidence remains below final-source quality because packet payload, helper, field, and object-status names remain provisional.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md)
- [UID:0002QN][0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane](by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md)
- [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch7 recommendation: create this exact child from the remaining [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) broad leaf. Parent remains reconstructable because later source-bearing leaves, raw no-function bodies, no-caller stubs, and existing child islands remain unsplit.
```

### Create Child Page [UID:0003TN]

Create:

`by-memory/0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md`

With exact content:

```markdown
*** UID:0003TN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x00511710-0x00511997 MapPane Handle Movement Speech Balloon Packet

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane packet-handler child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneHandleMovementSpeechBalloonPacket`.
- Packet route: opcode `0x0d` movement packet in [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md).
- Confidence: strong for exact range, dispatcher caller, raw PE branch route, movement/speech-balloon behavior, MapPane ownership, and BalloonObjectPane construction dependency; medium-high for final subtype, field, and helper names.
- Reconstruction note: C++ intentionally blank. Final source needs named packet payload fields, subtype/style names, MapPane field names, and attached-overlay helper names.

## Address Range

- Start: `0x00511710`
- End: `0x00511997` end-exclusive
- IDA function: `sub_511710`
- IDA size: `0x287` bytes
- Preceded by ignored padding `0x00511703-0x00511710` after sibling child [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md).
- Followed by raw/jump-table seam `0x00511997-0x00511c90`; no ignored row is recommended for that seam.

## Behavior

This packet handler attaches speech balloon overlays to map objects from a movement/chat packet route:

- reads subtype, target object id, and text byte count from the packet;
- rejects invalid subtypes, missing object-list storage, and incompatible local-player state;
- resolves the target object through the MapPane object list;
- clears a prior attached overlay slot when present;
- converts packet text from multibyte text to a local UTF-16 buffer;
- for subtype `4`, reads two extra packet dwords after the text payload;
- maps subtypes `0..4` to style constants `143`, `14`, `9`, `200`, and `253`;
- allocates a [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md) from its static pool, obtains the target anchor coordinates through `sub_5374D0`, and calls the BalloonObjectPane constructor at `0x004682c0`;
- registers the constructed overlay through `sub_53ADA0`, inserts it into the MapPane object list with `sub_5314A0`, schedules a `3000` ms cleanup/update timer through `sub_597910`, and refreshes bounds through virtual calls;
- returns success after applying the overlay, or returns failure for invalid packet/state gates.

## IDA MCP Evidence

- B001 live IDA MCP session `b001_mappane_0001AW_20260616` reports `sub_511710` at `0x00511710`, size `0x287`.
- `analyze_function(0x00511710)` reports prototype `char __thiscall(_DWORD *this, int)`.
- Callers: `sub_507C90`.
- Xrefs-to: one code xref at `0x0050801c`.
- Direct callees include `sub_532370`, `MultiByteToWideChar`, `PoolAllocator_Allocate`, `sub_5374D0`, `sub_4682C0`, `sub_53ADA0`, `sub_5314A0`, `sub_597910`, and `sub_4B8E00`.
- Decompilation shows subtype/object/text parsing, local-player state gates, object-list lookup, UTF-16 conversion, subtype-to-style mapping, BalloonObjectPane allocation/construction, MapPane object-list insertion, timer scheduling, and bounds refresh.
- Raw PE scan confirms one `E8` rel32 call to `0x00511710` at `0x0050801c`; no absolute VA or RVA pointer hits were found.
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) records opcode `0x0d` dispatching to `0x00511710`.
- [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md), [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md), and [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md) all record `0x00511710` as a BalloonObjectPane allocation/constructor caller.
- B001 byte-signature review confirms preceding bytes `0x00511703-0x00511710` are thirteen `0xcc` bytes. The following `0x00511997-0x00511c90` bytes are not padding and are intentionally not ignored.

## Ownership Decision

This body belongs to `MapPane` because it parses a map-scoped movement/speech packet, resolves the target through MapPane object-list state, attaches the overlay to a map object, inserts it into MapPane object state, and schedules MapPane-side update/cleanup. BalloonObjectPane owns the constructed class, pool, vtables, layout, paint, and destructor behavior; it does not own the packet parser.

## Rejected Owners

- [UID:0000L3][MapPane](by-file/MapPane.md) as direct canonical owner: rejected only as too broad for this child; [UID:00007Q][MapPane](by-class/MapPane.md) is the narrower direct owner, with file emission through MapPane.
- [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md): owns constructed overlay implementation and pool, but not packet parsing or MapPane object-list insertion.
- [UID:00009Q][ObjectList](by-class/ObjectList.md): lookup/insertion dependency only.
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md): base/overlay source family for the constructed object, not owner of this packet handler.
- Socket/protocol table owners: they provide route and status context, not the MapPane-side packet behavior.

## Score Rationale

Completion is `86` because exact range, dispatcher caller, raw PE call hit, decompiled movement/speech behavior, BalloonObjectPane construction dependency, MapPane ownership, rejected owners, and adjacent boundary evidence are documented. Confidence is `90` because IDA, raw PE, opcode documentation, BalloonObjectPane support docs, and MapPane support docs agree on the source route; confidence remains below final-source quality because payload, subtype, helper, and field names remain provisional.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md)
- [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md)
- [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch7 recommendation: create this exact child from the remaining [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) broad leaf. Parent remains reconstructable because later source-bearing leaves, raw no-function bodies, no-caller stubs, and existing child islands remain unsplit.
```

### Parent [UID:0001AW] Edits

Apply these exact support edits to `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`.

In `## Exact Child Pages And Nesting`, insert these rows immediately after the existing [UID:0003TL] row and before the existing [UID:0001AY] row:

```markdown
| [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md) | Exact modeled MapPane opcode `0x07` / `kServerDrawObjects` handler; parses spawn/object placement records, creates or updates visible object panes, and applies nested object-effect descriptor updates through [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md). |
| [UID:0003TN][0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md) | Exact modeled MapPane opcode `0x0d` movement/speech-balloon handler; resolves a target object, converts packet text, constructs/registers a [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md), schedules a timer, and refreshes overlay bounds. |
```

In `## Current Exact Boundary Inventory`, replace the existing row for `0x00511440`:

```markdown
| `0x00511440` | `sub_511440` | `0x2c3` | Spawn/movement/chat packet helper called from dispatcher case at `0x0050800b`; likely future child after the raw seam is resolved. |
```

with:

```markdown
| `0x00511440` | `sub_511440` | `0x2c3` | Exact child [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md); opcode `0x07` / `kServerDrawObjects` spawn/object-placement handler called from dispatcher case at `0x0050800b`. |
| `0x00511710` | `sub_511710` | `0x287` | Exact child [UID:0003TN][0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md); opcode `0x0d` movement/speech-balloon handler called from dispatcher case at `0x0050801c`. |
| `0x00511997` | not modeled | none | Roadmap-only raw/jump-table seam after [UID:0003TN]; not padding, contains raw prologue-shaped starts at `0x005119b0`, `0x005119f0`, `0x00511ad0`, `0x00511b70`, and `0x00511c60`, and cannot be ignored or emitted until a raw-helper/source-placement pass resolves it. |
```

Append this bullet after the existing 2026-06-16 batch6 evidence bullet:

```markdown
- 2026-06-16 B001 continuation batch7 live IDA MCP session `b001_mappane_0001AW_20260616`: `analyze_function(0x00511440)` reports `sub_511440` size `0x2c3`, caller `sub_507C90`, xref at `0x0050800b`, opcode `0x07` / `kServerDrawObjects` support, connection-status gate, visible spawn/object-placement parsing, `sub_505E00` object create/update calls, and [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) calls at `0x005116cc`. `analyze_function(0x00511710)` reports `sub_511710` size `0x287`, caller `sub_507C90`, xref at `0x0050801c`, opcode `0x0d` movement support, target-object lookup, UTF-16 speech text conversion, [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md) allocation/construction at `0x00511906`, object-list insertion, timer scheduling, and bounds refresh. `analyze_function` confirms `0x00511420` and `0x00511430` are no-caller five-byte `return 1` stubs. `make_signature_for_range` confirms `0x00511414-0x00511420`, `0x00511425-0x00511430`, `0x00511435-0x00511440`, and `0x00511703-0x00511710` as `0xcc` padding, while `0x00511997-0x00511c90` is not padding and remains a roadmap-only raw/jump-table seam.
```

Add these cross-reference bullets after [UID:0003TL]:

```markdown
- [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md)
- [UID:0003TN][0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md)
```

Add this Changes bullet at the top of `## Changes`:

```markdown
- 2026-06-16 B001 continuation split batch7: create exact children [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md) and [UID:0003TN][0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md), plus ignored padding `0x00511414-0x00511420`, `0x00511425-0x00511430`, `0x00511435-0x00511440`, and `0x00511703-0x00511710`. Parent [UID:0001AW] remains `RECONSTRUCTABLE:TRUE`, `85/88`, and owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md) because raw/no-function helper bodies, true-return stubs, raw/jump-table seams, and later modeled packet handlers still need exact split/source-placement work.
```

### MapPane Class/File Support Edits

Apply these support edits after the parent and child pages are created.

In `by-class/MapPane.md`, append this bullet in `## IDA MCP Evidence` after the current packet-dispatch/downstream-start evidence:

```markdown
- 2026-06-16 B001 continuation batch7: exact children [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md) and [UID:0003TN][0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md) split the dispatcher-backed opcode `0x07` draw-objects/spawn path and opcode `0x0d` movement/speech-balloon path from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md). The first creates/updates visible object panes and dispatches nested object effects; the second constructs/registers BalloonObjectPane overlays while preserving BalloonObjectPane implementation ownership.
```

Add these cross-reference bullets near the existing [UID:0001AW] / packet-handler references:

```markdown
- [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md)
- [UID:0003TN][0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md)
```

In `by-file/MapPane.md`, append this paragraph in `## IDA MCP Evidence` after the paragraph that begins `2026-05-25 send-helper recheck`:

```markdown
2026-06-16 B001 continuation batch7 split exact MapPane packet-handler children [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md) and [UID:0003TN][0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md). Live IDA and raw PE evidence tie them to dispatcher calls `0x0050800b` and `0x0050801c`; source placement remains `map/MapPane.cpp`, while ObjectList, EffectObjectPane, BalloonObjectPane, Socket, and protocol docs remain dependency or constructed-object owners.
```

## Ignored Rows

Append these entries to `by-memory/-ignored.md`:

```markdown
- `0x00511414-0x00511420` - alignment padding after raw no-function MapPane packet body.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the raw no-function body at `0x00511350-0x00511414` and before no-caller true-return stub `sub_511420`.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows twelve `0xcc` bytes at `0x00511414-0x00511420`; the same signature shows the raw body returns through `0x00511413`, and `analyze_function(0x00511420)` reports a five-byte `return 1` stub.

- `0x00511425-0x00511430` - alignment padding between no-caller true-return stubs.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `sub_511420` and before `sub_511430`.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eleven `0xcc` bytes at `0x00511425-0x00511430`; `analyze_function(0x00511420)` and `analyze_function(0x00511430)` report adjacent five-byte `return 1` stubs with no callers.

- `0x00511435-0x00511440` - alignment padding before MapPaneHandleDrawObjectsPacket.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after no-caller true-return stub `sub_511430` and before modeled function `sub_511440`.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eleven `0xcc` bytes at `0x00511435-0x00511440`; `lookup_funcs 0x00511440` reports `sub_511440`, size `0x2c3`.

- `0x00511703-0x00511710` - alignment padding between MapPaneHandleDrawObjectsPacket and MapPaneHandleMovementSpeechBalloonPacket.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after modeled function `sub_511440` and before modeled function `sub_511710`.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows thirteen `0xcc` bytes at `0x00511703-0x00511710`; `lookup_funcs` reports `sub_511440` size `0x2c3` ending at `0x00511703` and `sub_511710` size `0x287` starting at `0x00511710`.
```

## by-memory/-coverage-report.md Rows

Do not edit `by-memory/-coverage-report.md` directly as B001. Use this existing row as placement context only; do not duplicate it:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00511347-0x00511350 | padding | MapPaneHandleMapInfoTileRegionPacket to raw no-function packet body alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows nine `0xcc` bytes after `sub_510960` end-exclusive `0x00511347` and before raw no-function bytes at `0x00511350`.
```

Insert the following six rows immediately after that existing context row and before the existing [UID:0001AY] row:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00511414-0x00511420 | padding | Raw no-function MapPane packet body to no-caller true-return stub alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows twelve `0xcc` bytes after the raw no-function body returns through `0x00511413` and before `sub_511420` starts at `0x00511420`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00511425-0x00511430 | padding | sub_511420 no-caller true-return stub to sub_511430 no-caller true-return stub alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eleven `0xcc` bytes after five-byte stub `sub_511420` and before five-byte stub `sub_511430`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00511435-0x00511440 | padding | sub_511430 no-caller true-return stub to MapPaneHandleDrawObjectsPacket alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eleven `0xcc` bytes after five-byte stub `sub_511430` and before modeled function `sub_511440`.
        - [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md) 0x00511440-0x00511703 | class method/packet handler | MapPaneHandleDrawObjectsPacket : reconstructable : 86% : strong : Exact modeled `sub_511440` child split from MapPanePacketHandlers; live IDA and raw PE confirm the dispatcher call at `0x0050800b`; handler parses opcode `0x07` / `kServerDrawObjects` spawn records, clips against MapPane visible bounds, creates or updates object panes through `0x00505e00`, and dispatches nested object-effect descriptors through [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md). Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); ObjectList, object-pane classes, EffectObjectPane, Socket, and protocol tables remain dependencies/providers. Final C++ blank pending final packet, field, object-status, helper, and global names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00511703-0x00511710 | padding | MapPaneHandleDrawObjectsPacket to MapPaneHandleMovementSpeechBalloonPacket alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows thirteen `0xcc` bytes after `sub_511440` end-exclusive `0x00511703` and before modeled function `sub_511710` starts at `0x00511710`.
        - [UID:0003TN][0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md) 0x00511710-0x00511997 | class method/packet handler | MapPaneHandleMovementSpeechBalloonPacket : reconstructable : 86% : strong : Exact modeled `sub_511710` child split from MapPanePacketHandlers; live IDA and raw PE confirm the dispatcher call at `0x0050801c`; handler parses opcode `0x0d` movement/speech data, resolves a target object, converts speech text to UTF-16, constructs/registers a BalloonObjectPane overlay, inserts it into MapPane object-list state, schedules a timer, and refreshes bounds. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); BalloonObjectPane owns the constructed overlay class, pool, and rendering implementation. Final C++ blank pending final packet, subtype, field, and helper names.
```

Parent [UID:0001AW] row remains unchanged.

## IDA DB Recommendation

No IDA DB edits are recommended.

- The recommended children are already modeled IDA functions with stable dispatcher xrefs and exact sizes.
- Defining `0x00511350` or the raw starts inside `0x00511997-0x00511c90` is not safe in this batch because current IDA xrefs, raw PE routes, and support docs do not prove those raw starts are reachable source functions rather than retained duplicate/dead bodies or jump-table-adjacent helper fragments.
- The two true-return stubs at `0x00511420` and `0x00511430` are already modeled; their no-caller/no-route status makes naming or reclassification unsafe.

## Validation Order

Supervisor validation order after applying the batch:

1. Create [UID:0003TM] and [UID:0003TN] child pages exactly as above.
2. Apply [UID:0001AW] parent child-table, boundary-inventory, evidence, cross-reference, and Changes additions.
3. Apply MapPane class/file evidence and cross-reference additions.
4. Apply the four `by-memory/-ignored.md` entries.
5. Insert the six coverage rows under [UID:0001AW] after the existing `0x00511347-0x00511350` ignored row and before [UID:0001AY].
6. Run scoped validator passes for both new child pages, [UID:0001AW], [UID:00007Q], [UID:0000L3], `by-memory/-ignored.md`, and `by-memory/-coverage-report.md`.
7. Run `python .\tools\memory_ranges.py report` and confirm Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan remain `None`.
8. Confirm [UID:0001AW] still remains `RECONSTRUCTABLE:TRUE`, `85/88`, owner/emitter [UID:00007Q], and blank final C++.

## Remaining Blockers and Next Follow-Up

- `0x00511350-0x00511414`: investigated with IDA `lookup_funcs`, `xrefs_to`, raw byte signature, and raw PE route scan. It is function-shaped, but not an IDA function and has no xrefs/callers/pointer/branch route. It cannot safely be classified as source-emitting, retained duplicate, or dead code yet.
- `0x00511420-0x00511425` and `0x00511430-0x00511435`: investigated with IDA `analyze_function`, decompilation, assembly, xrefs, and raw PE scan. Both are five-byte `return 1` stubs with no callers or route hits. Keep roadmap-only until their packet/no-op role is proven.
- `0x00511997-0x00511c90`: investigated with IDA `lookup_funcs`, `xrefs_to`, `make_signature_for_range`, [UID:0001HY][GetConnectionStatus](../../../../../by-memory/0x00575370-0x00575377.GetConnectionStatus.md), and raw PE route scan. It contains jump-table-like data and raw prologue-shaped no-function starts at `0x005119b0`, `0x005119f0`, `0x00511ad0`, `0x00511b70`, and `0x00511c60`; none has a start xref or raw route. The `0x00511a3c` status-getter code ref proves code exists inside the island but does not prove a safe start/range/source owner.
- `0x00511c90`, `0x00511db0`, `0x00512960`, `0x00512d60`, `0x00512f20`, and `0x00513310`: investigated with IDA function inventory, `analyze_function`, opcode docs, support docs, and raw PE branch scans. They are likely direct future children, but they should be handled after the `0x00511997-0x00511c90` raw seam is resolved or explicitly bracketed.
- `0x00512ca4-0x00512d60` and `0x0051367b-0x00513800`: rechecked from batch6 scope via current raw route scan for their raw starts. They still include raw no-function starts (`0x00512cb0`, `0x00513680`, `0x00513780`, `0x005137d0`) with no IDA function objects and no route hits; do not ignore or emit them until a focused pass resolves them.
- WorldMapPane boundary: checked [UID:0000PB], [UID:0000G9], [UID:0001O4], [UID:0003JH], [UID:0003JJ], and `analyze_function(0x00511db0)`. Current evidence keeps `0x00511db0` as a MapPane packet parser that constructs or routes to WorldMapPane, not a WorldMapPane-owned source body.
- Final C++ blockers for the new children: exact packet structures, original subtype/style names, MapPane field names, object-status blob field names, helper names, and global/config field names remain provisional. The new child pages clear the documentation/ownership gate but should keep final C++ blank.

## No-Direct-Edit Confirmation

B001 created this research report only:

- Created: `tools/leaser/Agents/Agent-B001/research/0001AW-mappane-packet-source-split-continuation-batch7.md`
- Modified: none outside the research report.
- IDA DB: no edits.
- Generated reports and `by-memory/-coverage-report.md`: no direct edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch7.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001AW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
