** TARGET-REPORT-UID:0001AW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AW MapPane Packet Source Split Continuation Batch 8

Agent: B001  
Assignment: `B001-goal2-memory-tool-mappane-packet-source-split-continuation8-0001AW-20260616`  
Target: [UID:0001AW] `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`  
Focus leaf: `0x00511997-0x00513800`  
Mode: report only; no by-* docs, IDA DB, generated reports, or `by-memory/-coverage-report.md` edited directly.

## Final Recommendation

Apply a bounded executable child-split batch under [UID:0001AW]:

- Correct existing [UID:0003TN] from `0x00511710-0x00511997` to `0x00511710-0x005119ac` and rename it to include the owned movement/speech switch table.
- Create six new direct-call MapPane packet-handler child pages:
  - [UID:0003TO] `0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md`
  - [UID:0003TP] `0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md`
  - [UID:0003TQ] `0x00512960-0x00512ca4.MapPaneHandleActionPacket.md`
  - [UID:0003TR] `0x00512d60-0x00512f1c.MapPaneHandleFlyingObjectUpdatePacket.md`
  - [UID:0003TS] `0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md`
  - [UID:0003TT] `0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md`
- Add ignored padding/alignment rows for exact compiler fill spans between modeled functions and raw bodies.
- Leave [UID:0001AW] as `RECONSTRUCTABLE:TRUE`, `85/88`, owner/emitter [UID:00007Q][MapPane]. Do not reclassify the parent yet because raw/no-route helper bodies remain inside this leaf and the earlier `0x0050f26d-0x00510400` parent leaf still needs source-split work.
- Keep final C++ blank for the new children. The behavior and ownership are strong enough for exact child pages, but final source names for packet payload structs, MapPane fields, and helper/private method names are still not recovered.
- Do not repair IDA DB. IDA models all direct-call handlers needed for this batch. The remaining raw bodies have no xrefs or pointer/branch evidence, so making IDA functions there would be speculative.

## Current State Checked

- [UID:0001AW] current target: `85/88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`.
- Existing executed children under the first part of [UID:0001AW] include [UID:0003TB]-[UID:0003TN].
- [UID:0003TN] currently ends at `0x00511997`, but live IDA proves the function-owned switch jump table is `0x00511998-0x005119ac`.
- `auto-generated/by-memory-tool-report.md` shows remaining [UID:0001AW] leaf `0x00511997-0x00513800`, 7785 bytes.
- `tools/validator.ini` and repo search show no current use of UIDs `0003TO` through `0003TT`; this report assumes those are the next supervisor-available UIDs after [UID:0003TN].

## Evidence Checked

### IDA/MCP Session

Live MCP database: `b001_mappane_0001AW_20260616`, image base `0x00400000`, Hex-Rays ready.

Function inventory inside `0x00511997-0x00513800`:

| Start | End | IDA name | Route |
|---|---:|---|---|
| `0x00511c90` | `0x00511dae` | `sub_511C90` | dispatcher call and action-handler nested call |
| `0x00511db0` | `0x0051283a` | `sub_511DB0` | dispatcher call |
| `0x00512840` | `0x0051289f` | `sub_512840` | no caller |
| `0x005128a0` | `0x005128fd` | `___std_parallel_algorithms_hw_threads@0_1` | no caller, generated bad name |
| `0x00512900` | `0x0051295d` | `sub_512900` | no caller |
| `0x00512960` | `0x00512ca4` | `sub_512960` | dispatcher call |
| `0x00512d60` | `0x00512f1c` | `sub_512D60` | dispatcher call |
| `0x00512f20` | `0x00513305` | `sub_512F20` | dispatcher call |
| `0x00513310` | `0x0051367b` | `sub_513310` | dispatcher call |

No IDA function exists at `0x00511997`, `0x005119b0`, `0x005119f0`, `0x00511ad0`, `0x00511b70`, `0x00511c60`, `0x00512cb0`, `0x00513680`, `0x00513780`, or `0x005137d0`.

### Dispatcher Routes

IDA instruction audit around the MapPane packet dispatcher at `0x005082e0-0x005083c5` confirms:

- opcode `0x29` calls `sub_511C90` at `0x005082f6`
- opcode `0x2e` calls `sub_511DB0` at `0x00508307`
- opcode `0x13` calls `sub_512960` at `0x0050837e`
- opcode `0x16` calls `sub_512D60` at `0x0050838f`
- opcode `0x19` calls `sub_512F20` at `0x005083a0`
- opcode `0x1d` calls `sub_513310` at `0x005083b1`

`by-type/MapServerPacketOpcode.md` already names these source routes as MapPane packet handlers:

- `0x13`: action packet -> `0x00512960`
- `0x16`: object update packet -> `0x00512d60`
- `0x19`: animation packet -> `0x00512f20`
- `0x1d`: status packet -> `0x00513310`
- `0x29`: object move packet -> `0x00511c90`
- `0x2e`: object/world-map creation packet -> `0x00511db0`

### Raw PE Scans

Read-only raw PE scans of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` covered absolute VA dwords, RVA dwords, `E8/E9` rel32, and `0F8x` rel32 patterns.

Results:

- `0x00511998` has a VA/jump-table operand hit from `0x0051188c`; this is the [UID:0003TN] internal switch table.
- Raw starts `0x005119b0`, `0x005119f0`, `0x00511ad0`, `0x00511b70`, `0x00511c60` have no VA/RVA/relative branch hits.
- `0x00511c90` has rel32 hits at `0x005082f6` and `0x00512c04`.
- `0x00511db0` has rel32 hit at `0x00508307`.
- No-caller starts `0x00512840` and `0x005128a0` have no hits. `0x00512900` has one RVA-byte sequence at non-executable/data context `0x00633687`, not a code route.
- `0x00512960`, `0x00512d60`, `0x00512f20`, and `0x00513310` each have the expected dispatcher rel32 hit.
- Raw starts `0x00512cb0`, `0x00513680`, `0x00513780`, and `0x005137d0` have no VA/RVA/relative branch hits.

### Raw/Jump-Table Seam `0x00511997-0x00511c90`

`0x00511997` is not a new body. IDA shows:

- [UID:0003TN] `sub_511710` contains `cmp ecx, 4`, `ja`, and `jmp ds:jpt_511889[ecx*4]`.
- The jump table is `0x00511998-0x005119ac`, with entries for labels `0x00511890`, `0x00511897`, `0x0051189e`, `0x005118a5`, and `0x005118ac`.
- The single byte `0x00511997` is alignment before that table.
- Signature `0x00511997-0x005119b0`: `90 90 18 51 00 97 18 51 00 9E 18 51 00 A5 18 51 00 AC 18 51 00 CC CC CC CC`

Conclusion: [UID:0003TN] must be extended to end at `0x005119ac`; `0x005119ac-0x005119b0` is padding.

The raw bodies after the switch table were checked and are not executable child-page candidates in this batch:

- `0x005119b0-0x005119f0`: raw prologue body, no IDA function, no direct xrefs, no PE pointer/branch hits.
- `0x005119f0-0x00511ad0`: raw prologue body, no IDA function, no direct xrefs, no PE pointer/branch hits; it contains a `GetConnectionStatus` call but has no source route.
- `0x00511ad0-0x00511b70`: raw prologue body, no IDA function, no direct xrefs, no PE pointer/branch hits.
- `0x00511b70-0x00511c60`: raw prologue body, no IDA function, no direct xrefs, no PE pointer/branch hits.
- `0x00511c60-0x00511c90`: raw prologue body, no IDA function, no direct xrefs, no PE pointer/branch hits.

These raw bodies should stay inside the parent as roadmap-only retained helper evidence. Creating child pages for them would be below the 85/85 gate.

### WorldMapPane Boundary at `0x00511db0`

`sub_511DB0` is routed by MapPane dispatcher opcode `0x2e`, but it constructs WorldMapPane at `0x005126f9`.

Evidence checked:

- Caller is MapPane packet dispatcher only (`0x00508307`).
- `sub_511DB0` parses packet payload data: source string/name bytes, mode/dimension values, packed bitset/vector data, node/string tables, and world-map source suffix comparisons.
- It calls `sub_514A10` at `0x00511f00` for the temporary UInt32 vector constructor.
- It compares world-map source suffix strings at `0x0061ea30` (`wm`), `0x0061ea38` (`WM`), `0x0061ea40` (`wm2`), `0x0061ea48` (`WM2`), `0x0061ea50` (`wm3`), `0x0061ea58` (`WM3`), `0x0061ea60` (`wm4`), and `0x0061ea68` (`WM4`).
- It allocates `0x298` bytes at `0x005126ad`, then calls `sub_5C2AC0` at `0x005126f9`, which is the WorldMapPane constructor/source family boundary.
- It stores a helper at MapPane offset `+0x420` and activates/positions the new pane through MapPane/UI helper routes after the WorldMapPane constructor.

Conclusion: keep this handler owned/emitted by [UID:00007Q][MapPane]. WorldMapPane owns its constructor/body and data model after `sub_5C2AC0`; this MapPane packet handler owns packet decoding, UI factory routing, and installation into MapPane state. The evidence does not support rerouting the full handler to WorldMapPane.

## Rejected Alternatives and Blockers

### Do Not Reclassify [UID:0001AW] Yet

The parent still carries raw/no-route bodies and earlier unsplit source-bearing spans. Reclassifying [UID:0001AW] as a non-emitting split index now would hide unresolved executable source-placement work.

Evidence checked:

- Current memory tool leaf still includes raw/no-function blocks after the [UID:0003TN] switch table and after `0x00512ca4`.
- Raw PE scans found no safe route to promote those raw bodies.
- Existing parent final C++ remains blank, and the earlier broad parent leaf `0x0050f26d-0x00510400` still requires follow-up.

### Do Not Create No-Caller Children at `0x00512840`, `0x005128a0`, `0x00512900`

These three bodies are real compiler-shaped functions, but there is no direct call/pointer route.

Evidence checked:

- IDA shows no callers for all three starts.
- `0x00512840` builds a stack `PursuitMessageDialogCreator` vtable route and calls `sub_54C200`, but no xref reaches the start.
- `0x005128a0` has a bad generated IDA name and calls `sub_545170(a1, 0)` after allocating `0x280`, but no xref reaches the start.
- `0x00512900` calls the same allocation/constructor route with a flag value of `1`, but the only raw PE RVA-like sequence is in non-executable/data context and is not route evidence.

Conclusion: keep these below-gate as roadmap-only no-caller bodies. They may become child pages only if a later pointer-table or dispatcher route is found.

### Do Not Create Raw Body Child at `0x00512cb0`

`0x00512cb0-0x00512d59` is a function-shaped body that updates an object state or sends a missing-object/request packet, but it has no direct route.

Evidence checked:

- No IDA function at `0x00512cb0`.
- `xrefs_to 0x00512cb0` is empty.
- Raw PE VA/RVA/relative branch scan found no hit.
- The body is adjacent to direct-call handler `sub_512960`, but the preceding modeled function returns at `0x00512ca1`; no fallthrough reaches `0x00512cb0`.

Conclusion: do not create a child page. Ignore only compiler padding around it.

### Do Not Create Raw Body Children in `0x00513680-0x00513800`

`0x00513680` is a raw switch-shaped body with internal table at `0x0051376c` and case bodies near `0x00513780` and `0x005137d0`, but no external route was found.

Evidence checked:

- No IDA function at `0x00513680`, `0x00513780`, or `0x005137d0`.
- `xrefs_to 0x0051376c` is internal from `0x0051370f`, consistent with a local jump table, not an external route.
- `xrefs_to` raw starts are empty.
- Raw PE scan found no VA/RVA/relative branch hits for the raw starts.

Conclusion: keep roadmap-only. Add ignored padding only for `0x0051367b-0x00513680`.

## Executable Supervisor Batch

### UID Allocation Assumption

Assuming no concurrent UID allocation after [UID:0003TN], allocate:

- [UID:0003TO] for `0x00511c90-0x00511dae`
- [UID:0003TP] for `0x00511db0-0x0051283a`
- [UID:0003TQ] for `0x00512960-0x00512ca4`
- [UID:0003TR] for `0x00512d60-0x00512f1c`
- [UID:0003TS] for `0x00512f20-0x00513305`
- [UID:0003TT] for `0x00513310-0x0051367b`

If `tools/validator.ini` has advanced before execution, keep the same page content and substitute the next available UIDs consistently in filenames, links, parent/support docs, and coverage rows.

### Existing Child Edit: [UID:0003TN]

Rename/move:

- From: `by-memory/0x00511710-0x00511997.MapPaneHandleMovementSpeechBalloonPacket.md`
- To: `by-memory/0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md`

Recommended metadata after edit:

```text
UID: 0003TN
TITLE: MapPaneHandleMovementSpeechBalloonPacket
ADDRESS_RANGE: 0x00511710-0x005119ac
SCORE: 87/91
CANONICAL_OWNER: 00007Q
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 00007Q
```

Required content update:

- Add evidence that `0x00511998-0x005119ac` is the owned five-entry switch table used by `jmp ds:jpt_511889[ecx*4]` inside `sub_511710`.
- Add that `0x005119ac-0x005119b0` is padding after the owned table.
- Keep final C++ blank.

### New Child Page: [UID:0003TO]

Create `by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md`:

```markdown
# [UID:0003TO] MapPaneHandleObjectMoveEffectPacket

## Metadata

- `UID`: 0003TO
- `Title`: MapPaneHandleObjectMoveEffectPacket
- `Address Range`: `0x00511c90-0x00511dae`
- `Completion`: 86
- `Confidence`: 90
- `Reconstructable`: TRUE
- `Canonical Owner`: [UID:00007Q][MapPane](by-class/MapPane.md)
- `Emitter UIDs`: 00007Q
- `Parent`: [UID:0001AW][MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- `Final C++`: blank

## Summary

Modeled MapPane packet handler for server opcode `0x29`, currently named object move/effect packet in `by-type/MapServerPacketOpcode.md`. The handler parses an object id, descriptor/effect id, update argument, and optional coordinates from the packet stream, then routes either a temporary MapPane effect update or an object-specific effect/update helper.

## Evidence

- IDA function `sub_511C90` covers `0x00511c90-0x00511dae`; `0x00511dae-0x00511db0` is alignment padding.
- Direct dispatcher call at `0x005082f6` from the MapPane packet dispatcher case for opcode `0x29`.
- Nested direct call from [UID:0003TQ] at `0x00512c04`, where action packet handling reuses this object-move/effect route.
- Raw PE scan found rel32 branch hits at `0x005082f6` and `0x00512c04`, and no unrelated pointer-table owners.
- Callees include object lookup/list helpers (`sub_532370`, `sub_575480`, `sub_5754C0`), [UID:0003TE] MapPane coordinate effect descriptor dispatch (`sub_50E850`), [UID:000232] MapPane effect object action helper (`sub_50E320`), redraw/refresh helper `sub_557140`, and `Sleep`.

## Behavior Notes

- Reads object id from packet offset `+1`, descriptor/effect id from `+5`, and update argument from `+7`.
- Special-cases descriptor/effect id `134`: stores `143` at MapPane offset `+0x4c8`, forces refresh, sleeps for 100 ms, clears the field, and refreshes again.
- For ordinary effects, reads coordinate bytes at packet offsets `+9` and `+11`.
- If object id is zero, calls [UID:0003TE] `sub_50E850(this, x, y, descriptor, updateArg, compactFlag)`.
- If object id is nonzero and object lookup succeeds, calls [UID:000232] `sub_50E320(this, objectId, descriptor, updateArg, compactFlag)`.
- The compact flag is derived from descriptor range `160..162`.

## Ownership and Source Placement

This belongs to [UID:00007Q][MapPane]. The only external dispatcher route is the MapPane server packet dispatcher, and the handler updates MapPane fields/object-list state before delegating to existing MapPane effect helpers. EffectObjectPane-related callees own constructed object implementations, not this packet parser.

## Final C++ Blockers

Final C++ remains blank. The handler is behaviorally bounded, but original packet struct names, descriptor enum names, MapPane field names at `+0x4c8`, and helper method names are not recovered with source-grade confidence.

## Change Log

- `2026-06-16` B001 batch8: split from [UID:0001AW] as direct-call opcode `0x29` MapPane object move/effect packet handler.
```

### New Child Page: [UID:0003TP]

Create `by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md`:

```markdown
# [UID:0003TP] MapPaneHandleObjectWorldMapCreationPacket

## Metadata

- `UID`: 0003TP
- `Title`: MapPaneHandleObjectWorldMapCreationPacket
- `Address Range`: `0x00511db0-0x0051283a`
- `Completion`: 86
- `Confidence`: 90
- `Reconstructable`: TRUE
- `Canonical Owner`: [UID:00007Q][MapPane](by-class/MapPane.md)
- `Emitter UIDs`: 00007Q
- `Parent`: [UID:0001AW][MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- `Final C++`: blank

## Summary

Modeled MapPane packet handler for server opcode `0x2e`, the object/world-map creation packet. The handler parses a map/object source name, map dimension/mode data, packed bitset/vector records, node/string tables, and then constructs/installs a WorldMapPane when the packet source suffix selects a world-map route.

## Evidence

- IDA function `sub_511DB0` covers `0x00511db0-0x0051283a`; `0x0051283a-0x00512840` is alignment padding.
- Direct dispatcher call at `0x00508307` from the MapPane packet dispatcher case for opcode `0x2e`.
- Raw PE scan found the expected rel32 branch hit at `0x00508307` and no other owner route.
- The handler calls `sub_514A10` at `0x00511f00` for the temporary UInt32/vector storage also used by WorldMapPane source-family code.
- It references world-map source suffix literals `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, and `WM4` at `0x0061ea30-0x0061ea68`.
- It allocates `0x298` bytes and calls `sub_5C2AC0` at `0x005126f9`, the WorldMapPane constructor/source boundary.
- It stores a helper at MapPane offset `+0x420` and activates/positions the created pane through MapPane/UI helper routes after construction.

## Behavior Notes

- Converts a packet source/name string into wide-character storage.
- Reads dimension and mode values, derives a squared node count, and constructs temporary UInt32 vector/bitset storage sized as `(count + 31) >> 5`.
- Decodes packed world-map/node data and associated strings.
- Routes source-name suffix variants `wm`, `wm2`, `wm3`, and `wm4` case-insensitively through string comparisons before choosing the world-map creation path.
- Constructs WorldMapPane with the decoded map data and installs the resulting pane into MapPane UI state.

## Ownership and Source Placement

Keep this page owned by [UID:00007Q][MapPane]. The packet parser is reached only from the MapPane server packet dispatcher and owns decoding plus UI installation. [UID:0000PB][WorldMapPane] owns `sub_5C2AC0` and the resulting pane implementation, but not the server-packet handler that feeds it.

## Final C++ Blockers

Final C++ remains blank. The source boundary is clear, but original packet payload structs, temporary bitset/vector names, MapPane field names, and exact helper names remain unresolved.

## Change Log

- `2026-06-16` B001 batch8: split from [UID:0001AW] as direct-call opcode `0x2e` MapPane object/world-map creation packet handler.
```

### New Child Page: [UID:0003TQ]

Create `by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md`:

```markdown
# [UID:0003TQ] MapPaneHandleActionPacket

## Metadata

- `UID`: 0003TQ
- `Title`: MapPaneHandleActionPacket
- `Address Range`: `0x00512960-0x00512ca4`
- `Completion`: 86
- `Confidence`: 90
- `Reconstructable`: TRUE
- `Canonical Owner`: [UID:00007Q][MapPane](by-class/MapPane.md)
- `Emitter UIDs`: 00007Q
- `Parent`: [UID:0001AW][MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- `Final C++`: blank

## Summary

Modeled MapPane packet handler for server opcode `0x13`, the action/combat packet. The handler resolves target objects, plays action/effect routes, creates damage number overlays, invokes hit-bar overlay helpers, and can reuse the object move/effect packet handler for nested visual updates.

## Evidence

- IDA function `sub_512960` covers `0x00512960-0x00512ca4`; `0x00512ca4-0x00512cb0` is alignment padding before an unrelated no-route raw body.
- Direct dispatcher call at `0x0050837e` from the MapPane packet dispatcher case for opcode `0x13`.
- Raw PE scan found the expected rel32 branch hit at `0x0050837e`.
- It calls [UID:0003TH] `sub_50EDD0` at `0x00512b96` and `0x00512c7f`, matching the already split hit-bar overlay helper route.
- It calls [UID:0003TO] `sub_511C90` at `0x00512c04` for a nested object move/effect update route.
- It calls DamageNumberObjectPane constructor/source-family route `sub_539230` at `0x00512a9c` and `0x00512ac2`.

## Behavior Notes

- Gated by global byte `byte_66DA97`.
- Parses target/action data from the packet and resolves MapPane object-list entries.
- Plays action/effect updates through object/list helper routes.
- Clears or updates attached overlay pointers when required.
- Creates DamageNumberObjectPane overlays and invokes existing hit-bar overlay helper paths for visual combat feedback.
- Returns success after packet processing, with fallback object/effect routes delegated to existing MapPane helpers.

## Ownership and Source Placement

This belongs to [UID:00007Q][MapPane]. The sole direct external route is the MapPane packet dispatcher and the function mutates MapPane object-list/UI state. DamageNumberObjectPane and hit-bar helpers own constructed/rendered overlay classes; they do not own this packet parser.

## Final C++ Blockers

Final C++ remains blank. Opcode routing and behavior are clear, but original action subtype names, packet field names, global gate purpose, and helper names are not yet source-grade.

## Change Log

- `2026-06-16` B001 batch8: split from [UID:0001AW] as direct-call opcode `0x13` MapPane action/combat packet handler.
```

### New Child Page: [UID:0003TR]

Create `by-memory/0x00512d60-0x00512f1c.MapPaneHandleFlyingObjectUpdatePacket.md`:

```markdown
# [UID:0003TR] MapPaneHandleFlyingObjectUpdatePacket

## Metadata

- `UID`: 0003TR
- `Title`: MapPaneHandleFlyingObjectUpdatePacket
- `Address Range`: `0x00512d60-0x00512f1c`
- `Completion`: 86
- `Confidence`: 90
- `Reconstructable`: TRUE
- `Canonical Owner`: [UID:00007Q][MapPane](by-class/MapPane.md)
- `Emitter UIDs`: 00007Q
- `Parent`: [UID:0001AW][MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- `Final C++`: blank

## Summary

Modeled MapPane packet handler for server opcode `0x16`, the object/flying update packet. The handler resolves source/target objects, updates object state, constructs a FlyingObjectPane, inserts it into MapPane object-list state, and schedules its animation/update timer.

## Evidence

- IDA function `sub_512D60` covers `0x00512d60-0x00512f1c`; `0x00512f1c-0x00512f20` is alignment padding.
- Direct dispatcher call at `0x0050838f` from the MapPane packet dispatcher case for opcode `0x16`.
- Raw PE scan found the expected rel32 branch hit at `0x0050838f`.
- It calls FlyingObjectPane constructor/source-family route `sub_537CB0` at `0x00512ebe`.
- Callees include object lookup/list helpers (`sub_5314A0`, `sub_532370`, `sub_575480`, `sub_5754C0`), object/action helper `sub_4B97D0`, allocator route `PoolAllocator_Allocate`, and timer/registration helper `sub_597910`.

## Behavior Notes

- Reads packet object ids, effect/state bytes, target id, coordinates, duration/timer data, and object type/subtype fields.
- Applies an action/update through the resolved source object when present.
- Removes or refreshes a prior target object route if the packet references one.
- Allocates and constructs a FlyingObjectPane, inserts it into the MapPane object list, and schedules its update route.

## Ownership and Source Placement

This belongs to [UID:00007Q][MapPane]. The direct route is the MapPane packet dispatcher, and the handler owns packet decoding plus insertion into MapPane object state. FlyingObjectPane owns the constructed pane behavior, not this packet handler.

## Final C++ Blockers

Final C++ remains blank. Exact packet payload names, FlyingObjectPane constructor argument names, MapPane field names, and helper names are still unresolved.

## Change Log

- `2026-06-16` B001 batch8: split from [UID:0001AW] as direct-call opcode `0x16` MapPane flying object update packet handler.
```

### New Child Page: [UID:0003TS]

Create `by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md`:

```markdown
# [UID:0003TS] MapPaneHandleAnimationSoundPacket

## Metadata

- `UID`: 0003TS
- `Title`: MapPaneHandleAnimationSoundPacket
- `Address Range`: `0x00512f20-0x00513305`
- `Completion`: 86
- `Confidence`: 90
- `Reconstructable`: TRUE
- `Canonical Owner`: [UID:00007Q][MapPane](by-class/MapPane.md)
- `Emitter UIDs`: 00007Q
- `Parent`: [UID:0001AW][MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- `Final C++`: blank

## Summary

Modeled MapPane packet handler for server opcode `0x19`, the animation/sound packet. The handler parses subtype, sound/effect identifiers, object or coordinate targets, invokes sound helper routes, and constructs or registers SoundObjectPane visual/audio objects.

## Evidence

- IDA function `sub_512F20` covers `0x00512f20-0x00513305`; `0x00513305-0x00513310` is alignment padding.
- Direct dispatcher call at `0x005083a0` from the MapPane packet dispatcher case for opcode `0x19`.
- Raw PE scan found the expected rel32 branch hit at `0x005083a0`.
- Calls SoundObjectPane/source-family helpers `sub_53CA20` at `0x005131de`, `0x0051323c`, and `0x005132b0`, and `sub_53CB50` at `0x005132e0`.
- Calls audio helper routes `sub_526100` and `sub_526340`.
- Callees include object lookup/list helpers (`sub_5314A0`, `sub_532370`, `sub_575480`, `sub_5754C0`) and object/effect helpers (`sub_5374D0`, `sub_5376D0`, `sub_57A0B0`).

## Behavior Notes

- Parses subtype and target information from the packet stream.
- Resolves object targets or coordinate targets depending on subtype.
- Dispatches sound playback through audio helpers.
- Allocates/constructs SoundObjectPane state and registers it into MapPane object-list/UI state when needed.
- Handles subtype-specific fallback cases for sound/effect placement.

## Ownership and Source Placement

This belongs to [UID:00007Q][MapPane]. The only direct external route is the MapPane packet dispatcher and the function owns packet decoding plus MapPane object-list insertion. SoundObjectPane owns constructed visual/audio object behavior, not this packet parser.

## Final C++ Blockers

Final C++ remains blank. Exact subtype enum names, sound/effect id semantics, packet struct fields, and helper names are not recovered.

## Change Log

- `2026-06-16` B001 batch8: split from [UID:0001AW] as direct-call opcode `0x19` MapPane animation/sound packet handler.
```

### New Child Page: [UID:0003TT]

Create `by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md`:

```markdown
# [UID:0003TT] MapPaneHandleObjectStatusPacket

## Metadata

- `UID`: 0003TT
- `Title`: MapPaneHandleObjectStatusPacket
- `Address Range`: `0x00513310-0x0051367b`
- `Completion`: 86
- `Confidence`: 90
- `Reconstructable`: TRUE
- `Canonical Owner`: [UID:00007Q][MapPane](by-class/MapPane.md)
- `Emitter UIDs`: 00007Q
- `Parent`: [UID:0001AW][MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- `Final C++`: blank

## Summary

Modeled MapPane packet handler for server opcode `0x1d`, the object status/state packet. The handler parses object id, subtype/status data, optional text/name data, updates living-object or item-object state, triggers status sounds/effects, and refreshes affected MapPane UI regions.

## Evidence

- IDA function `sub_513310` covers `0x00513310-0x0051367b`; `0x0051367b-0x00513680` is alignment padding before an unrelated no-route raw switch body.
- Direct dispatcher call at `0x005083b1` from the MapPane packet dispatcher case for opcode `0x1d`.
- Raw PE scan found the expected rel32 branch hit at `0x005083b1`.
- Calls ItemObjectPane/source-family record-state update route `sub_537BC0` at `0x00513665`, matching [UID:0003HS].
- Callees include object lookup/list helpers (`sub_532370`, `sub_574BB0`), status/effect helpers (`sub_53A8C0`, `sub_53A900`, `sub_53BAD0`, `sub_539650`, `sub_57A5C0`), packet/blob helpers (`sub_4D1FA0`, `sub_4D2640`), and refresh helper `sub_50FA90`.

## Behavior Notes

- Reads object id, subtype, status/blob fields, and optional string/text payload.
- Converts multibyte packet text to wide-character storage.
- Resolves the target object in MapPane state.
- Updates living-object display/status state when the object is a living pane.
- Routes non-living/item object record-state updates through ItemObjectPane helper `sub_537BC0`.
- Triggers status-difference visual/audio effects and refreshes affected UI state.

## Ownership and Source Placement

This belongs to [UID:00007Q][MapPane]. The direct route is the MapPane packet dispatcher, and the handler owns packet decoding and MapPane object dispatch. ItemObjectPane owns the record-state update method reached in one branch, not the packet handler.

## Final C++ Blockers

Final C++ remains blank. Exact status subtype enum names, packet blob layout, living/item object type tests, MapPane field names, and helper names remain unresolved.

## Change Log

- `2026-06-16` B001 batch8: split from [UID:0001AW] as direct-call opcode `0x1d` MapPane object status/state packet handler.
```

## Parent and Support Doc Actions

### [UID:0001AW] Parent Page

Edit `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`:

- Keep metadata unchanged:
  - `Completion`: 85
  - `Confidence`: 88
  - `Reconstructable`: TRUE
  - `Canonical Owner`: 00007Q
  - `Emitter UIDs`: 00007Q
- Replace the [UID:0003TN] child reference/path with `0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md`.
- Add children [UID:0003TO]-[UID:0003TT] in address order.
- Add evidence bullets:
  - `0x00511998-0x005119ac` is [UID:0003TN]'s owned switch table.
  - `0x005119b0-0x00511c90`, `0x00512cb0-0x00512d59`, and `0x00513680-0x00513800` remain no-route raw bodies after IDA xref and raw PE VA/RVA/branch scans.
  - `0x00511db0` remains MapPane-owned because the dispatcher owns packet decoding and WorldMapPane only begins at constructor call `0x005126f9 -> sub_5C2AC0`.

### [UID:00007Q] MapPane Class Page and [UID:0000L3] MapPane File Page

Edit the MapPane support docs that list exact child packet handlers:

- Update [UID:0003TN] link/range to `0x00511710-0x005119ac`.
- Add [UID:0003TO]-[UID:0003TT] as exact MapPane packet-handler children under the [UID:0001AW] source family.
- Add a short change note:
  - `2026-06-16 B001 batch8 split six direct-call opcode handlers from [UID:0001AW] and extended [UID:0003TN] to include its owned jump table; parent remains reconstructable because no-route raw helper bodies and earlier broad leaves remain.`

### WorldMapPane Support Docs

No WorldMapPane owner/emitter reroute is recommended. If the supervisor wants a cross-reference only, add a note to WorldMapPane support docs:

```text
- [UID:0003TP][MapPaneHandleObjectWorldMapCreationPacket](by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md) is the MapPane-owned server-packet parser/factory route that constructs WorldMapPane through `sub_5C2AC0` at `0x005126f9`; WorldMapPane owns the constructor/body after that call, not the packet handler.
```

This cross-reference is optional and not required for validation.

## Ignored Ledger Rows

Add these exact rows to `by-memory/-ignored.md` in address order:

```markdown
- `0x005119ac-0x005119b0` - padding/alignment after [UID:0003TN] `MapPaneHandleMovementSpeechBalloonPacket` switch table and before no-route raw helper body at `0x005119b0`. Verified by B001 batch8 IDA instruction/signature audit.
- `0x00511dae-0x00511db0` - padding/alignment after [UID:0003TO] `MapPaneHandleObjectMoveEffectPacket` and before [UID:0003TP] `MapPaneHandleObjectWorldMapCreationPacket`. Verified by B001 batch8 IDA boundary audit.
- `0x0051283a-0x00512840` - padding/alignment after [UID:0003TP] `MapPaneHandleObjectWorldMapCreationPacket` and before no-caller body `0x00512840`. Verified by B001 batch8 IDA boundary audit.
- `0x00512ca4-0x00512cb0` - padding/alignment after [UID:0003TQ] `MapPaneHandleActionPacket` and before no-route raw helper body `0x00512cb0`. Verified by B001 batch8 IDA boundary audit.
- `0x00512d59-0x00512d60` - padding/alignment after no-route raw helper body `0x00512cb0-0x00512d59` and before [UID:0003TR] `MapPaneHandleFlyingObjectUpdatePacket`. Verified by B001 batch8 IDA boundary audit.
- `0x00512f1c-0x00512f20` - padding/alignment after [UID:0003TR] `MapPaneHandleFlyingObjectUpdatePacket` and before [UID:0003TS] `MapPaneHandleAnimationSoundPacket`. Verified by B001 batch8 IDA boundary audit.
- `0x00513305-0x00513310` - padding/alignment after [UID:0003TS] `MapPaneHandleAnimationSoundPacket` and before [UID:0003TT] `MapPaneHandleObjectStatusPacket`. Verified by B001 batch8 IDA boundary audit.
- `0x0051367b-0x00513680` - padding/alignment after [UID:0003TT] `MapPaneHandleObjectStatusPacket` and before no-route raw switch body `0x00513680`. Verified by B001 batch8 IDA boundary audit.
```

## by-memory/-coverage-report.md Pending Rows

Do not edit `by-memory/-coverage-report.md` directly as B001. Supervisor should replace the existing [UID:0003TN] row and insert the following rows in address order under [UID:0001AW], immediately after [UID:0003TM] / before the current [UID:0001AY] row.

```markdown
        - [UID:0003TN][0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md) 0x00511710-0x005119ac | class method/packet handler | MapPaneHandleMovementSpeechBalloonPacket : reconstructable : 87% : strong : Exact modeled `sub_511710` child split from MapPanePacketHandlers; live IDA and raw PE confirm dispatcher call at `0x0050801c`, and B001 batch8 extended the range to include the owned `0x00511998-0x005119ac` five-entry switch table referenced by `jmp ds:jpt_511889[ecx*4]`. Handler parses opcode `0x0d` movement/speech data, resolves a target object, converts speech text to UTF-16, constructs/registers a BalloonObjectPane overlay, inserts it into MapPane object-list state, schedules a timer, and refreshes bounds. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); BalloonObjectPane owns the constructed overlay class, pool, and rendering implementation. Final C++ blank pending final packet, subtype, field, and helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005119ac-0x005119b0 | padding | MapPaneHandleMovementSpeechBalloonPacket switch table to raw no-function helper alignment : ignored : 100% : strong : Compiler padding/alignment after [UID:0003TN] owned switch table and before no-route raw helper body at `0x005119b0`; verified by B001 batch8 IDA instruction/signature audit.
        - [UID:0003TO][0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket](by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md) 0x00511c90-0x00511dae | class method/packet handler | MapPaneHandleObjectMoveEffectPacket : reconstructable : 86% : strong : Exact modeled `sub_511C90` child split from MapPanePacketHandlers; live IDA and raw PE confirm dispatcher call at `0x005082f6` for opcode `0x29` and nested action-handler reuse at `0x00512c04`. Handler parses object id, descriptor/effect id, update argument, and coordinates, special-cases descriptor `134` through MapPane field `+0x4c8` and forced redraw/sleep/redraw, and otherwise delegates to coordinate/object effect helpers [UID:0003TE] and [UID:000232]. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md). Final C++ blank pending final packet, descriptor enum, field, and helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00511dae-0x00511db0 | padding | MapPaneHandleObjectMoveEffectPacket to MapPaneHandleObjectWorldMapCreationPacket alignment : ignored : 100% : strong : Compiler padding/alignment after [UID:0003TO] and before [UID:0003TP]; verified by B001 batch8 IDA boundary audit.
        - [UID:0003TP][0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket](by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md) 0x00511db0-0x0051283a | class method/packet handler | MapPaneHandleObjectWorldMapCreationPacket : reconstructable : 86% : strong : Exact modeled `sub_511DB0` child split from MapPanePacketHandlers; live IDA and raw PE confirm dispatcher call at `0x00508307` for opcode `0x2e`. Handler parses object/world-map creation payloads, decodes source name/dimension/mode/vector/bitset/node/string data, compares `wm`/`WM`/`wm2`/`WM2`/`wm3`/`WM3`/`wm4`/`WM4` source suffix literals, constructs WorldMapPane through `sub_5C2AC0` at `0x005126f9`, and installs the created pane into MapPane UI state. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); [UID:0000PB][WorldMapPane](by-class/WorldMapPane.md) owns the constructed pane implementation after the constructor call. Final C++ blank pending final packet, bitset/vector, field, and helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051283a-0x00512840 | padding | MapPaneHandleObjectWorldMapCreationPacket to no-caller helper alignment : ignored : 100% : strong : Compiler padding/alignment after [UID:0003TP] and before no-caller body `0x00512840`; verified by B001 batch8 IDA boundary audit.
        - [UID:0003TQ][0x00512960-0x00512ca4.MapPaneHandleActionPacket](by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md) 0x00512960-0x00512ca4 | class method/packet handler | MapPaneHandleActionPacket : reconstructable : 86% : strong : Exact modeled `sub_512960` child split from MapPanePacketHandlers; live IDA and raw PE confirm dispatcher call at `0x0050837e` for opcode `0x13`. Handler is gated by `byte_66DA97`, resolves action/combat target objects, invokes DamageNumberObjectPane construction at `0x00512a9c`/`0x00512ac2`, calls hit-bar overlay helper [UID:0003TH] at `0x00512b96`/`0x00512c7f`, and reuses [UID:0003TO] object move/effect handler at `0x00512c04` for nested visual updates. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md). Final C++ blank pending final action subtype, global, field, and helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00512ca4-0x00512cb0 | padding | MapPaneHandleActionPacket to no-route raw helper alignment : ignored : 100% : strong : Compiler padding/alignment after [UID:0003TQ] and before no-route raw helper body `0x00512cb0`; verified by B001 batch8 IDA boundary audit.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00512d59-0x00512d60 | padding | no-route raw helper to MapPaneHandleFlyingObjectUpdatePacket alignment : ignored : 100% : strong : Compiler padding/alignment after no-route raw helper body `0x00512cb0-0x00512d59` and before [UID:0003TR]; verified by B001 batch8 IDA boundary audit.
        - [UID:0003TR][0x00512d60-0x00512f1c.MapPaneHandleFlyingObjectUpdatePacket](by-memory/0x00512d60-0x00512f1c.MapPaneHandleFlyingObjectUpdatePacket.md) 0x00512d60-0x00512f1c | class method/packet handler | MapPaneHandleFlyingObjectUpdatePacket : reconstructable : 86% : strong : Exact modeled `sub_512D60` child split from MapPanePacketHandlers; live IDA and raw PE confirm dispatcher call at `0x0050838f` for opcode `0x16`. Handler parses object/flying update payload fields, resolves source/target objects, updates object action state, constructs FlyingObjectPane through `sub_537CB0` at `0x00512ebe`, inserts it into MapPane object-list state, and schedules timer/update registration. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); FlyingObjectPane owns the constructed pane behavior. Final C++ blank pending final packet, field, constructor argument, and helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00512f1c-0x00512f20 | padding | MapPaneHandleFlyingObjectUpdatePacket to MapPaneHandleAnimationSoundPacket alignment : ignored : 100% : strong : Compiler padding/alignment after [UID:0003TR] and before [UID:0003TS]; verified by B001 batch8 IDA boundary audit.
        - [UID:0003TS][0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket](by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md) 0x00512f20-0x00513305 | class method/packet handler | MapPaneHandleAnimationSoundPacket : reconstructable : 86% : strong : Exact modeled `sub_512F20` child split from MapPanePacketHandlers; live IDA and raw PE confirm dispatcher call at `0x005083a0` for opcode `0x19`. Handler parses animation/sound subtype and target payloads, invokes sound helpers `sub_526100`/`sub_526340`, routes SoundObjectPane construction/registration through `sub_53CA20` and `sub_53CB50`, resolves object/coordinate targets, and updates MapPane object-list/UI state. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); SoundObjectPane owns constructed visual/audio object behavior. Final C++ blank pending final subtype, packet, field, and helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00513305-0x00513310 | padding | MapPaneHandleAnimationSoundPacket to MapPaneHandleObjectStatusPacket alignment : ignored : 100% : strong : Compiler padding/alignment after [UID:0003TS] and before [UID:0003TT]; verified by B001 batch8 IDA boundary audit.
        - [UID:0003TT][0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket](by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md) 0x00513310-0x0051367b | class method/packet handler | MapPaneHandleObjectStatusPacket : reconstructable : 86% : strong : Exact modeled `sub_513310` child split from MapPanePacketHandlers; live IDA and raw PE confirm dispatcher call at `0x005083b1` for opcode `0x1d`. Handler parses object id, subtype/status data, text/name payloads, status blobs, and target object state; it updates living-object display/status branches, routes item-object record-state updates through [UID:0003HS] `sub_537BC0` at `0x00513665`, triggers status effects/sounds, and refreshes MapPane UI regions. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md). Final C++ blank pending final status subtype, blob layout, field, and helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051367b-0x00513680 | padding | MapPaneHandleObjectStatusPacket to no-route raw switch body alignment : ignored : 100% : strong : Compiler padding/alignment after [UID:0003TT] and before no-route raw switch body `0x00513680`; verified by B001 batch8 IDA boundary audit.
```

## Validation Order

Supervisor execution order:

1. Re-check next UID availability in `tools/validator.ini`; substitute UIDs if needed.
2. Move/rename [UID:0003TN] to range `0x00511710-0x005119ac` and update its metadata/body.
3. Create [UID:0003TO]-[UID:0003TT] child pages with the exact markdown above.
4. Edit [UID:0001AW] parent child inventory/evidence.
5. Edit [UID:00007Q] MapPane and [UID:0000L3] MapPane file support pages with cross-references.
6. Optionally add the WorldMapPane cross-reference note.
7. Add ignored ledger rows to `by-memory/-ignored.md`.
8. Replace/insert `by-memory/-coverage-report.md` rows as listed above.
9. Run validator.
10. Run `memory_ranges.py report` and verify Barrier, General, Filename, and Advanced scans remain clean.
11. Confirm largest reconstructable leaves no longer show `0x00511997-0x00513800`; remaining [UID:0001AW] leaves should be raw/no-route spans plus earlier unsplit parent ranges.

Recommended validation commands from project root:

> Executable block R001 was removed from this report and preserved verbatim in [0001AW-mappane-packet-source-split-continuation-batch8-removed.md](0001AW-mappane-packet-source-split-continuation-batch8-removed.md). The archived block is non-authoritative and must not be executed.

If the project uses a different validator command in the supervisor environment, run that canonical validator first, then refresh memory ranges.

## Remaining Follow-up

- Audit remaining no-route raw helper bodies only if new pointer-table, branch, or caller evidence appears:
  - `0x005119b0-0x00511c90`
  - `0x00512840-0x0051295d`
  - `0x00512cb0-0x00512d59`
  - `0x00513680-0x00513800`
- Continue parent [UID:0001AW] split work on earlier remaining broad leaf `0x0050f26d-0x00510400`.
- Do not attempt final C++ for these packet handlers until packet structs, subtype enums, MapPane field names, and helper names are recovered to source-grade confidence.

## No Direct Edits Confirmation

B001 directly created only this research report:

- `tools/leaser/Agents/Agent-B001/research/0001AW-mappane-packet-source-split-continuation-batch8.md`

No by-* documentation, generated report, IDA DB, or `by-memory/-coverage-report.md` file was edited by B001.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch8.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001AW"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001AW-mappane-packet-source-split-continuation-batch8-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch8.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001AW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
