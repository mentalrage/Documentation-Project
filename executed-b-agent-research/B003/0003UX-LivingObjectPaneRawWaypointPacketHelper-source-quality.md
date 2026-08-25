** TARGET-REPORT-UID:0003UX **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Source-Quality Report: [UID:0003UX] LivingObjectPaneRawWaypointPacketHelper

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality.md`
Target path: `source-3/project-documentation/by-memory/0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md`
Primary aggregate: `source-3/project-documentation/by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
Canonical owner/emitter recommended: keep [UID:00007B] `LivingObjectPane`
Report status: FINISHED for supervisor review; report-only pass; no by-* files or coverage files edited.

## Executive Recommendation

[UID:0003UX] should remain a reconstructable, source-shaped retained raw helper owned by `LivingObjectPane`, but it should not emit formal C++ yet because the current binary route proof is negative: no IDA function object at `0x005ac7e0`, no direct rel32 caller, no VA/RVA start-pointer hit, no vtable/data route, and no fallthrough route from the predecessor. The page should still be upgraded from a mostly open raw-helper page to a fully decoded source-quality packet-helper page.

Recommended metadata:

- `COMPLETION:85 -> 88`
- `CONFIDENCE:86 -> 89`
- Keep `CANONICAL_OWNER:00007B`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:00007B`
- Keep the formal `RECONSTRUCTION_CPP` block blank for now, with target-specific no-code proof replacing generic uncertainty.

Best source-facing descriptive identity:

- Preferred documentation name: `LivingObjectPane::SendMovementWaypointPacketRaw`
- Acceptable alternate if the surrounding movement protocol later proves a more specific source term: `LivingObjectPane::SendWaypointPathPacketRaw`
- Descriptive signature direction: `void LivingObjectPane::SendMovementWaypointPacketRaw(uint8_t waypointKind, uint16_t waypointToken, const LivingObjectWaypointSegment *segment)`

The helper builds and sends an opcode `0x06` movement/waypoint packet with a subtype/waypoint-kind byte, a movement-status/history token derived from `this+0x13eb1c`, a high-bit status gate using `this+0x1340f8` `m_mapPane`, `MapPane+0x40e`, and `g_pConfig+0x28de75`, the current facing byte at `this+0x1a0`, the current object map position from `ObjectPane::GetMapPosition`, a four-dword waypoint segment argument encoded as two big-endian coordinates plus two one-byte deltas, and a final big-endian uint16 token. It also advances and fills a 0x10-byte local-player movement/waypoint history record ring at `this+0x13eb14`, capacity `this+0x13eb18`, write index `this+0x13eb1c`.

## Evidence Checked

Target and support documentation reviewed:

- `by-memory/0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md`
- `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
- `by-class/LivingObjectPane.md`
- `by-file/LivingObjectPane.md`
- `by-memory/0x005a8cf0-0x005a8e67.LivingObjectPaneSendMovementPacket.md`
- `by-memory/0x005ac1b0-0x005ac27c.LivingObjectPaneRawPositionSyncPacketHelper.md`
- `by-memory/0x005ac280-0x005ac69b.LivingObjectPaneParseLinkedObjectsPacket.md`
- `by-memory/0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md`
- `by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md`
- `by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md`
- `by-memory/0x005acc30-0x005acd85.LivingObjectPaneSendActionPacketWithAutoFace.md`
- `by-memory/0x005ad360-0x005ad441.LivingObjectPaneSendAttackTargetPacket.md`
- `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`
- `by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md`
- `by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`
- `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
- `by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md`
- `resources/exported_data/functions/0x005374d0.json`
- Coverage and generated-index references: `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, and `project-level/-auto-completion-stats.md`

Binary evidence checked directly against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` with a PE section reader and Capstone disassembly:

- Exact disassembly for `0x005ac7e0-0x005ac99b`
- Local call graph from the body
- Predecessor and successor bytes around `0x005ac69b-0x005acae0`
- Rel32 call/jump scan to `0x005ac7e0`
- VA pointer scan for `0x005ac7e0`
- RVA pointer scan for `0x001ac7e0`
- Section-wide hit scan over `.text`, `.rdata`, `.data`, and `.rsrc`

Generated/unrefined source was used only as a stale lead and then checked against raw PE evidence. It confirms a source-shaped scoped install for `0x005ac7e0`, but its decompiler-derived member offsets are misleading for this target because the helper is operating in the large local-player/UserPane/LivingObjectPane object layout, not the smaller decompiler type projection.

## Boundary And Route Findings

Final target boundary:

- `0x005ac69b-0x005ac6a0`: five `0xcc` bytes after [UID:0003UU] `LivingObjectPaneParseLinkedObjectsPacket`
- `0x005ac6a0-0x005ac7d7`: separate raw function-shaped predecessor body, ending in `ret 4` at `0x005ac7cf` and range-check failure tail at `0x005ac7d2`
- `0x005ac7d7-0x005ac7e0`: nine `0xcc` bytes
- `0x005ac7e0-0x005ac99b`: [UID:0003UX] body
- `0x005ac99b-0x005ac9a0`: five `0xcc` bytes
- `0x005ac9a0-0x005acad5`: [UID:0003UY] `LivingObjectPaneRawFacingPacketHelper` successor raw helper

The target range must not be merged backward into the predecessor at `0x005ac6a0`, and it must not be merged forward into [UID:0003UY]. The predecessor raw body is real and should receive a separate future child/support investigation if it is not already documented elsewhere.

Route/liveness checks:

- IDA/model state in target doc: no IDA function object at `0x005ac7e0`.
- PE rel32 scan: no direct `call` or `jmp` target to `0x005ac7e0`.
- VA pointer scan: no direct stored `0x005ac7e0` pointer found in `.text`, `.rdata`, `.data`, or `.rsrc`.
- RVA pointer scan: no direct stored `0x001ac7e0` pointer found in `.text`, `.rdata`, `.data`, or `.rsrc`.
- Fallthrough check: blocked by `0xcc` padding before `0x005ac7e0`; predecessor returns before the padding.
- Vtable/data route: none found in currently reviewed vtable/data docs or raw pointer scans.

Conclusion: this is retained no-route raw code. It is source-shaped and behavior-complete, but not proven live. It should be documented as a retained raw LivingObjectPane movement/waypoint packet helper, not as padding, not as a child of the predecessor, and not as a confirmed call target.

## Body Behavior

The function uses a normal stack-cookie frame:

- Prologue allocates `0x24` bytes of locals and stores a security cookie at `[ebp-4]`.
- Local packet buffer begins at `[ebp-0x18]`.
- Local packet length/cursor lives at `[ebp-0x1c]`.
- Local coordinate output pair from `ObjectPane::GetMapPosition` lives at `[ebp-0x24]` and `[ebp-0x20]`.
- The body checks `packetLen < 0x12` before writing a local terminator byte and sending. If the bound check fails, it calls the range-check failure helper at `0x005c7655`.
- The normal epilogue calls the security-cookie check helper at `0x005c772f` and returns with `ret 0xc`, confirming three stack parameters.

Parameter use:

- `[ebp+8]` is loaded into `bl`, written as packet byte 1, and later stored into the history record byte at record `+0x0c`. Best source-quality name: `waypointKind` or `movementSubtype`.
- `[ebp+0xc]` is written as the final big-endian uint16 field in the packet and is not otherwise stored. Best source-quality name: `waypointToken`, `waypointSequence`, or `movementSerial`; `waypointToken` is the safest current name.
- `[ebp+0x10]` is a pointer to at least four 32-bit values. The helper writes entries 0 and 1 as big-endian uint16 coordinates, then writes one-byte deltas from entries 2 and 3 relative to entries 0 and 1. Best source-quality type: `const LivingObjectWaypointSegment *segment`.

Call/callee behavior:

- `0x005055d0`: MapPane movement/status predicate. Existing docs describe this as a MapPane `+0x40e` flag helper with source-facing directions such as `AllowsMovementStatusFlag()` or `IsNormalMovementStatusClear()`.
- `0x00575380`: scalar packet writer for one byte plus spare zero, documented as `PacketBufferWriteUInt8`.
- `0x005374d0`: `ObjectPane::GetMapPosition(MapPoint *out) const` direction. Raw JSON confirms it copies object offsets `+0x104` and `+0x100` into the caller out pair.
- `0x005753a0`: scalar big-endian uint16 writer, documented as `PacketBufferWriteUInt16BE`.
- `0x00575670`: cursor append big-endian uint16 helper, documented as `PacketBufferAppendUInt16BE`.
- `0x00575650`: cursor append uint8 helper, documented as `PacketBufferAppendUInt8`.
- `0x00574bb0`: Socket-owned queue/send funnel, documented as `QueueAndSendPacket`.

## Packet Layout

The helper always constructs opcode `0x06`. The complete successful packet length is 16 bytes. The local terminator byte written after the packet is not sent.

Recommended source-quality packet field map:

| Packet offset | Encoding | Source-quality role |
| --- | --- | --- |
| `0` | `uint8_t` | opcode `0x06` |
| `1` | `uint8_t` | `waypointKind` / movement subtype from first argument |
| `2` | `uint8_t` | movement-status/history token from `this+0x13eb1c`, with high bit conditionally set |
| `3` | `uint8_t` | current facing/direction byte from `this+0x1a0` |
| `4-5` | big-endian `uint16_t` | current object map coordinate copied from `ObjectPane+0x100` through `ObjectPane::GetMapPosition` |
| `6-7` | big-endian `uint16_t` | current object map coordinate copied from `ObjectPane+0x104` through `ObjectPane::GetMapPosition` |
| `8-9` | big-endian `uint16_t` | `segment->startCoord0` / first waypoint coordinate |
| `10-11` | big-endian `uint16_t` | `segment->startCoord1` / second waypoint coordinate |
| `12` | `uint8_t` | low byte of `segment->endCoord0 - segment->startCoord0` |
| `13` | `uint8_t` | low byte of `segment->endCoord1 - segment->startCoord1` |
| `14-15` | big-endian `uint16_t` | `waypointToken` / sequence from second argument |

Status-token details:

- The base token is the low seven bits of the byte-sized write index at `this+0x13eb1c`.
- The high bit is set when both conditions hold:
  - `MapPane::AllowsMovementStatusFlag()` / equivalent `0x005055d0` predicate returns nonzero for `this+0x1340f8`.
  - `g_pConfig+0x28de75` is nonzero. Existing `g_pConfig` documentation identifies this as a map/movement status option byte, with source-facing aliases such as `mapMovementStatusOption` and `sendMovementStatusBit`.
- If either condition is false, the helper clears the high bit with `& 0x7f`.

Segment details:

- The segment argument is not a raw byte buffer. It is indexed as four dwords.
- Entries 0 and 1 are sent as two full uint16 coordinates.
- Entries 2 and 3 are used only through differences from entries 0 and 1, then truncated to one byte by the packet append helper.
- No clamp or sign guard exists for the delta writes; the helper preserves the binary behavior by truncating to the low byte.

The opcode is therefore best described as a movement waypoint/path packet rather than a pure facing packet, pure position-sync packet, or generic action packet. The subtype/waypoint-kind byte remains descriptive because no protocol enum name or caller argument source was found.

## Field, Type, Global, And Helper Names

Recommended field/global names and confidence:

| Address/offset | Recommended name | Confidence | Evidence |
| --- | --- | --- | --- |
| `this+0x1340f8` | `m_mapPane` | High | [UID:00023N] `UserPane::GetMapPane()` returns this exact field; [UID:0003UX] loads the same offset and calls the MapPane movement/status predicate. |
| `g_pConfig+0x28de75` | `mapMovementStatusOption` / `sendMovementStatusBit` | High | Existing `g_pConfig` doc maps the byte to movement/status option behavior, with consumers in ConnStatusPane, UserStatusPane2, and LivingObjectPane packet code. |
| `MapPane+0x40e` through `0x005055d0` | movement-status predicate flag | Medium-high | Existing MapPane aggregate documents `0x005055d0-0x005055db` as a movement gate/status helper. [UID:0003UX] uses it only to decide the packet status-token high bit. |
| `this+0x1a0` | `m_facingDirection` / `m_currentFacing` | Medium-high | The byte is sent immediately after the status token and appears in nearby facing/action packet helpers. |
| `ObjectPane+0x100`, `ObjectPane+0x104` | map coordinate fields, likely `m_mapX` and `m_mapY` | Medium | `ObjectPane::GetMapPosition` copies both. Axis order remains bounded by existing ObjectPane docs, so target text should preserve exact offset/order until the MapPoint convention is finalized. |
| `this+0x13eb14` | `m_waypointHistoryRecords` / `m_movementPredictionRecords` | Medium-high | Base pointer for 0x10-byte records updated by this helper and read/cleared by adjacent linked-record helpers. |
| `this+0x13eb18` | `m_waypointHistoryCapacity` / `m_movementPredictionRecordCount` | Medium-high | Used as modulus divisor for advancing the byte write index. Adjacent raw record helpers treat it as the record count. |
| `this+0x13eb1c` | `m_waypointHistoryWriteIndex` / `m_movementPredictionWriteIndex` | Medium-high | Used as packet status token low bits, record index, and incremented modulo capacity after record fill. |

Recommended record layout:

```cpp
struct LivingObjectWaypointHistoryRecord
{
    unsigned char active;      // +0x00
    unsigned char pad01[3];    // +0x01
    int coordFromOffset104;    // +0x04, exact axis label pending MapPoint convention
    int coordFromOffset100;    // +0x08, exact axis label pending MapPoint convention
    unsigned char waypointKind;// +0x0c
    unsigned char pad0d[3];    // +0x0d
};
```

Recommended segment type:

```cpp
struct LivingObjectWaypointSegment
{
    unsigned int startCoord0;
    unsigned int startCoord1;
    unsigned int endCoord0;
    unsigned int endCoord1;
};
```

The record-family naming should be coordinated with [UID:0003H4], [UID:0003H5], and [UID:0003UY]. Existing docs currently use "linked record" language. This helper proves that the same field cluster is also a local movement/waypoint prediction history. A broad final type such as `MovementPredictionRecord`, `WaypointHistoryRecord`, or `LocalMovementRecord` is better than leaving only `linkedRecord`. If the parser docs prove the records are visually linked player/object state rather than movement prediction, preserve `linkedRecord` as the container name and add `waypoint history slot` as the role within this helper.

## Heuristic / Inference Reanalysis And Validation

### Raw helper status and reachability

Evidence checked:

- Target doc's IDA-function absence statement.
- Raw bytes and disassembly at `0x005ac7e0`.
- Rel32 scan to `0x005ac7e0`.
- VA/RVA pointer scans to `0x005ac7e0` / `0x001ac7e0`.
- Predecessor/successor fallthrough and padding.
- Adjacent LivingObjectPane local-player split index.

Candidate interpretations:

- Live helper reached through an unmodeled pointer table.
- Retained source helper whose caller was optimized/removed or hidden behind a still-unidentified route.
- Dead duplicate or historical raw packet helper.
- Padding accidentally decoded as code.

Rejected alternatives:

- Padding is rejected because the bytes form a complete stack-cookie function, make coherent packet-buffer calls, and end with `ret 0xc`.
- Confirmed live direct helper is rejected for now because no rel32, VA, RVA, vtable, or fallthrough route was found.
- Pointer-table route is not proven; the scan found no start pointer.

Final direction:

- Document as retained no-route raw LivingObjectPane helper. Do not call it padding. Do not mark it as proven live. Keep formal C++ blank until a retained-dead-helper policy permits emission or a route is found.

Score/C++ impact:

- Behavior is now strong enough for `88/89`, but route-negative proof should cap confidence below final and keep `RECONSTRUCTION_CPP` blank.

### Source-facing helper name and signature

Evidence checked:

- Packet opcode and field order.
- Argument usage: byte subtype, uint16 final token, four-dword segment pointer.
- Neighbor movement packet, facing packet, direction packet, auto-face packet, action packet, and attack packet docs.
- Existing generated target title `LivingObjectPaneRawWaypointPacketHelper`.

Candidate interpretations:

- `SendMovementWaypointPacketRaw`
- `SendWaypointPathPacketRaw`
- `SendPositionDeltaPacketRaw`
- `SendFacingPacketRaw`
- `SendActionPacketRaw`

Rejected alternatives:

- Pure facing packet is rejected because facing is one byte inside a larger packet that also includes current position, waypoint segment coordinates, and deltas.
- Pure position-sync packet is rejected because it includes waypoint subtype, segment deltas, and history-record state.
- Action packet is rejected because [UID:0003V4] already models an action sender with auto-face logic and different behavior.

Final direction:

- Use `LivingObjectPane::SendMovementWaypointPacketRaw` as the report-backed source-quality name. If a protocol enum later gives a formal name for opcode `0x06`, rename toward that enum but keep "waypoint/path" semantics.
- Recommended signature: `void __thiscall LivingObjectPane::SendMovementWaypointPacketRaw(uint8_t waypointKind, uint16_t waypointToken, const LivingObjectWaypointSegment *segment)`.

Score/C++ impact:

- Name/signature are high-probability but not original-source proof. They are sufficient for doc recommendations and IDA comments, not sufficient alone to override the no-route C++ block.

### Packet opcode and subtype semantics

Evidence checked:

- `packet[0] = 0x06`.
- `packet[1] = first argument`.
- First argument also stored in history record `+0x0c`.
- Neighbor packet helpers for direction, action, attack, position sync, and movement.

Candidate interpretations:

- Opcode `0x06` is movement waypoint/path packet.
- First argument is waypoint kind, movement command subtype, or segment action.
- Second argument is a movement serial, waypoint token, or server-side sequence.

Rejected alternatives:

- `0x06` as generic object action is weaker because this helper includes map coordinates and path deltas and updates the movement history record ring.
- First argument as a signed byte is not supported by local operations; it is carried as a byte and stored as byte. Treat as unsigned protocol subtype unless a caller proves signed enum semantics.

Final direction:

- Document opcode `0x06` and first argument as `waypointKind` / movement subtype. Document the second argument as `waypointToken` / sequence with lower confidence because no caller proves its source.

Score/C++ impact:

- Packet layout is resolved; only enum spelling and token semantic remain confidence caps.

### Movement/status high-bit gate

Evidence checked:

- Load of `this+0x1340f8` at `0x005ac802`.
- Call to `0x005055d0`.
- Read of `g_pConfig+0x28de75`.
- Existing docs for `UserPane::GetMapPane`, `g_pConfig`, and MapPane core.

Candidate interpretations:

- Hidden/disabled flag.
- Movement status broadcast flag.
- Normal-map-state flag.
- Server-side movement prediction flag.

Rejected alternatives:

- Generic hidden/disabled UI state is rejected because the target is a packet helper and the state bit is encoded into a protocol token, not used for painting or pane visibility.
- Pure map state is incomplete because `g_pConfig+0x28de75` user option also gates the high bit.

Final direction:

- Document as a movement-status/history token high bit. The high bit is set only when the MapPane predicate allows it and the user configuration movement-status option is enabled.

Score/C++ impact:

- High-bit behavior is fully decoded; exact user-facing option text remains a support-doc naming issue only.

### Field and record names

Evidence checked:

- Direct stores to `this+0x13eb14`, `this+0x13eb18`, and `this+0x13eb1c`.
- Adjacent linked-record getter/clear helper docs.
- History record stride calculation: `index * 16`.
- Record writes at offsets `+0`, `+4`, `+8`, `+0xc`.

Candidate interpretations:

- Waypoint history ring.
- Movement prediction record ring.
- Linked object record ring.
- Companion/follower record ring.

Rejected alternatives:

- Pure companion/follower record is not supported by this helper; it writes local current-position and waypoint-kind data immediately after sending a movement/waypoint packet.
- Pure object-link record remains possible for the broader field cluster because adjacent helpers use linked-record terminology, but this target's role is specifically waypoint/movement history.

Final direction:

- Use `m_waypointHistoryRecords`, `m_waypointHistoryCapacity`, and `m_waypointHistoryWriteIndex` in this target's recommended text, while noting the final class-wide type may be named more broadly after [UID:0003H4]/[UID:0003H5]/[UID:0003UY] are reconciled.

Score/C++ impact:

- Field roles are strong enough for target/support docs. Exact class-wide type name is a confidence cap but not a behavior blocker.

### Coordinate order and ObjectPane position fields

Evidence checked:

- `ObjectPane::GetMapPosition` JSON: `out[1] = this->ObjectPane.mbr_0x100; out[0] = this->ObjectPane.mbr_0x104`.
- [UID:0003UX] writes `[ebp-0x20]` before `[ebp-0x24]` into the packet and stores `[ebp-0x24]` at history record `+4`, `[ebp-0x20]` at record `+8`.
- Existing ObjectPane doc says MapPoint coordinate order is not fully finalized.

Candidate interpretations:

- `+0x100 = x`, `+0x104 = y`.
- `+0x100 = y`, `+0x104 = x`.
- Out pair order is intentionally reversed by the helper.

Rejected alternatives:

- A firm axis label is not safe from this target alone because `ObjectPane::GetMapPosition` writes a pair with reversed stores and existing docs preserve this uncertainty.

Final direction:

- Document exact offset movement instead of overclaiming axis names: packet writes the value copied from `ObjectPane+0x100` first and `ObjectPane+0x104` second; history record stores the `+0x104` value at record `+4` and the `+0x100` value at record `+8`. Use `mapCoord0/mapCoord1` or `coordFromOffset100/coordFromOffset104` unless a future MapPoint pass finalizes X/Y.

Score/C++ impact:

- Coordinate behavior is resolved, but axis labels remain a confidence cap.

### Ownership and source placement

Evidence checked:

- Parent aggregate and neighboring helper classification under `LivingObjectPaneLocalPlayerExtensions`.
- `by-file/LivingObjectPane.md` source root `NexusTK/map/`.
- Use of LivingObjectPane/ObjectPane movement fields, MapPane pointer, packet helpers, and Socket send funnel.

Candidate interpretations:

- `LivingObjectPane` method/helper.
- `UserPane` method/helper because the receiver carries `m_mapPane` at `+0x1340f8`.
- `MapPane` method/helper.
- PacketBuffer/Socket helper.
- Protocol utility.

Rejected alternatives:

- `UserPane` direct owner is rejected because the helper's behavior belongs to local-player LivingObjectPane movement/packet state and shares the `LivingObjectPaneLocalPlayerExtensions` packet-helper island. The `m_mapPane` offset is a dependency field on the large object, not ownership proof.
- `MapPane` is rejected because it supplies only a predicate.
- Socket/PacketBuffer/protocol utility ownership is rejected because those are generic send/write dependencies; this helper builds a feature-specific LivingObjectPane packet and updates LivingObjectPane-local records.

Final direction:

- Keep canonical owner/emitter [UID:00007B] `LivingObjectPane`, source route `NexusTK/map/LivingObjectPane.cpp`. Mention physical large-object/UserPane field use as a dependency, not a canonical owner change.

Score/C++ impact:

- Owner/emitter is strong. Source method spelling remains inferred.

### First-draft C++ readiness

Evidence checked:

- Full packet behavior can be reconstructed.
- No route proof found.
- Similar adjacent retained raw helpers still use blank C++ with no-route proof.
- Current B-agent policy asks for C++ unless a target-specific no-code proof exists.

Candidate interpretations:

- Emit a first-draft method now because the body is behavior-complete.
- Keep blank formal C++ because the helper is retained no-route raw code and not proven live.
- Emit only a comment/no-code marker in formal C++.

Rejected alternatives:

- Emitting normal method definitions now is rejected for this report because the missing caller/source-route proof is target-specific and concrete, not a stale score-gate excuse.
- A comment-only C++ block is not recommended unless project policy explicitly wants no-code markers inside `RECONSTRUCTION_CPP`; current neighboring docs typically leave retained raw helper C++ blank and carry proof in prose.

Final direction:

- Keep formal C++ blank. Add a no-code proof section in the target doc. Provide the source-style prototype and pseudocode direction in prose/notes only for future implementation if a route or retained-helper emission policy is accepted.

Score/C++ impact:

- Completion can rise to 88 because behavior and fields are decoded. Confidence should stop at 89 because source spelling, route, and axis/token names remain bounded inferences.

## First-Draft C++ Decision

Do not populate the formal `RECONSTRUCTION_CPP` block in the target during the first implementation callback. The target-specific no-code proof is:

- no IDA function object at `0x005ac7e0`;
- no rel32 call/jump target found;
- no VA/RVA start-pointer hit found;
- no vtable/data route found;
- no fallthrough route because `0xcc` padding separates the predecessor and the target;
- caller context is still absent, so the exact original declaration and argument source are not proven.

If the supervisor later decides retained no-route packet helpers should emit source-shaped bodies, the following source-style skeleton is the best current direction, but it should be treated as non-emitting reference material for this report:

```cpp
struct LivingObjectWaypointSegment
{
    unsigned int startCoord0;
    unsigned int startCoord1;
    unsigned int endCoord0;
    unsigned int endCoord1;
};

void LivingObjectPane::SendMovementWaypointPacketRaw(unsigned char waypointKind,
                                                     unsigned short waypointToken,
                                                     const LivingObjectWaypointSegment *segment)
{
    unsigned char packet[18];
    int packetLen = 0;
    MapPoint currentPosition;

    packet[packetLen++] = 0x06;
    packet[packetLen++] = waypointKind;

    unsigned char status = m_waypointHistoryWriteIndex;
    if (m_mapPane != 0 &&
        m_mapPane->AllowsMovementStatusFlag() &&
        g_pConfig->mapMovementStatusOption)
    {
        status |= 0x80;
    }
    else
    {
        status &= 0x7f;
    }

    PacketBufferWriteUInt8(packet, &packetLen, status);
    PacketBufferWriteUInt8(packet, &packetLen, m_facingDirection);

    GetMapPosition(&currentPosition);
    PacketBufferWriteUInt16BE(packet, &packetLen, currentPosition.coordFromOffset100);
    PacketBufferWriteUInt16BE(packet, &packetLen, currentPosition.coordFromOffset104);

    PacketBufferAppendUInt16BE(packet, &packetLen, segment->startCoord0);
    PacketBufferAppendUInt16BE(packet, &packetLen, segment->startCoord1);
    PacketBufferAppendUInt8(packet, &packetLen, segment->endCoord0 - segment->startCoord0);
    PacketBufferAppendUInt8(packet, &packetLen, segment->endCoord1 - segment->startCoord1);
    PacketBufferAppendUInt16BE(packet, &packetLen, waypointToken);

    LivingObjectWaypointHistoryRecord *record =
        &m_waypointHistoryRecords[m_waypointHistoryWriteIndex];
    record->coordFromOffset104 = currentPosition.coordFromOffset104;
    record->coordFromOffset100 = currentPosition.coordFromOffset100;
    record->waypointKind = waypointKind;
    record->active = 1;

    m_waypointHistoryWriteIndex =
        static_cast<unsigned char>((m_waypointHistoryWriteIndex + 1) % m_waypointHistoryCapacity);

    packet[packetLen] = 0;
    QueueAndSendPacket(g_packetSender, packet, packetLen);
}
```

Notes on the skeleton:

- `MapPoint` field names are intentionally descriptive, not final axis names.
- Helper extraction names are documentation-level names unless IDA/source policy later names them.
- The C++ uses normal source-level control flow rather than raw decompiler temporaries.
- It should not be copied into the target formal C++ block until route/emission policy is resolved.

## Recommended Target Doc Changes

For `by-memory/0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md`:

1. Metadata:
   - Change `COMPLETION:85` to `COMPLETION:88`.
   - Change `CONFIDENCE:86` to `CONFIDENCE:89`.
   - Keep `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00007B`.

2. Replace the open-ended packet/opcode language with an exact packet layout:
   - opcode `0x06`;
   - first argument as byte subtype/waypoint kind;
   - status/history token from `this+0x13eb1c` with high bit gated by `this+0x1340f8`, `MapPane+0x40e`, and `g_pConfig+0x28de75`;
   - facing byte from `this+0x1a0`;
   - current map position from `ObjectPane::GetMapPosition`;
   - four-dword segment argument encoded as two uint16 coordinates plus two one-byte deltas;
   - final uint16 waypoint token/sequence from second argument;
   - final sent length 16, with an unsent local terminator after the range check.

3. Add the exact body/range map:
   - `0x005ac7d7-0x005ac7e0`: nine bytes of `0xcc` padding before this target.
   - `0x005ac7e0-0x005ac99b`: full body.
   - `0x005ac99b-0x005ac9a0`: five bytes of `0xcc` padding after this target.
   - `0x005ac6a0-0x005ac7d7`: separate predecessor raw body, not part of this target.
   - `0x005ac9a0-0x005acad5`: successor [UID:0003UY], not part of this target.

4. Add route/liveness proof:
   - no IDA function object;
   - no direct rel32 calls/jumps;
   - no VA/RVA pointer hits;
   - no fallthrough from predecessor;
   - no vtable/data route found;
   - conclusion: retained no-route raw helper, source-shaped but not proven live.

5. Add source-quality helper/signature recommendations:
   - `LivingObjectPane::SendMovementWaypointPacketRaw`;
   - signature direction `void (uint8_t waypointKind, uint16_t waypointToken, const LivingObjectWaypointSegment *segment)`;
   - record type direction `LivingObjectWaypointHistoryRecord`.

6. Add final no-code proof and remove passive blockers:
   - Explain that formal C++ remains blank because of target-specific no-route evidence, not because old score-gate wording applies.
   - Add the non-emitting source skeleton only if local target-doc policy allows reference snippets outside `RECONSTRUCTION_CPP`; otherwise keep skeleton in the report only.

7. Close or rewrite current open questions:
   - Reachability: no route found after rel32/VA/RVA/fallthrough/vtable checks; retained no-route.
   - Semantic name: best current name `SendMovementWaypointPacketRaw`.
   - Opcode/subtype: opcode `0x06`, subtype/waypoint-kind first argument.
   - Field names: recommend `m_mapPane`, `m_facingDirection`, `m_waypointHistoryRecords`, `m_waypointHistoryCapacity`, `m_waypointHistoryWriteIndex`, and exact coordinate-offset caveat.

## Support Documentation Updates Needed

`by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`

- Update the [UID:0003UX] child row from provisional `SendMovementWaypointPacket` language to decoded retained raw helper language.
- Include exact route-negative status and packet layout summary.
- Add the boundary note that the predecessor `0x005ac6a0-0x005ac7d7` is a separate raw function-shaped body with `0x005ac7d7-0x005ac7e0` padding before [UID:0003UX].
- Keep aggregate C++ blank because children own emission and this child remains no-route raw.

`by-class/LivingObjectPane.md`

- Add a local-player movement/waypoint packet-helper note for [UID:0003UX].
- Add field-role inventory for the movement/waypoint record ring:
  - `+0x13eb14` record base pointer;
  - `+0x13eb18` record count/capacity;
  - `+0x13eb1c` byte write index and packet status-token low bits.
- Add that the field cluster is shared with adjacent raw linked-record/facing helpers and still needs final class-wide type naming across [UID:0003H4], [UID:0003H5], [UID:0003UY], and [UID:0003UX].
- Do not move ownership to `UserPane`, `MapPane`, Socket, or PacketBuffer.

`by-file/LivingObjectPane.md`

- Add [UID:0003UX] under the `NexusTK/map/LivingObjectPane.cpp` local-player packet-helper island as a decoded retained no-route movement/waypoint packet helper.
- State that formal C++ should stay blank for the target until a route or retained-helper emission policy is accepted.
- Preserve the distinction between feature packet helpers and the Socket/PacketBuffer send/write dependencies.

`by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`

- Refine the existing 0003UX displacement note: [UID:0003UX] reads `this+0x1340f8` at `0x005ac802` to fetch `m_mapPane`, then calls the MapPane movement/status predicate while building the opcode `0x06` movement/waypoint status token.

`by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`

- Add [UID:0003UX] as an exact consumer of `g_pConfig+0x28de75`.
- State that this byte gates the high bit of the opcode `0x06` movement/waypoint packet status/history token together with the MapPane predicate.

`by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`

- Add [UID:0003UX] as an exact consumer of helper `0x005055d0`.
- Describe the consumer role: it decides whether the opcode `0x06` status/history token may set bit `0x80`.

`by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`

- Optional but useful: add [UID:0003UX] to xref examples for `PacketBufferWriteUInt8` and `PacketBufferWriteUInt16BE`, noting the opcode `0x06` packet writes status/facing bytes and current map coordinates.

`by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md`

- Optional but useful: add [UID:0003UX] to xref examples for `PacketBufferAppendUInt16BE` and `PacketBufferAppendUInt8`, noting the segment coordinates, one-byte deltas, and final token.

`by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`

- Add [UID:0003UX] as a caller that sends through Socket-owned `QueueAndSendPacket(g_packetSender, packet, packetLen)` after the local terminator and length guard.
- Avoid stale CashShop ownership language.

`by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`

- Add [UID:0003UX] to the packet-sender consumer examples, with note that it sends a LivingObjectPane movement/waypoint packet.

`by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md`

- Add [UID:0003UX] as a caller/consumer.
- State that the helper writes the `ObjectPane+0x100` copied value first in the packet and the `ObjectPane+0x104` copied value second, then stores them into the history record in the opposite observed local order (`+0x104` value at record `+4`, `+0x100` value at record `+8`).
- Preserve the exact coordinate-order caveat until the MapPoint convention is finalized.

`by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`, `by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md`, and `by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`

- Add or cross-reference that [UID:0003UX] proves the `+0x13eb14/+0x13eb18/+0x13eb1c` field cluster also acts as a movement/waypoint history ring.
- Do not rename the whole cluster solely from [UID:0003UX] if adjacent parse/facing docs require broader `linkedRecord` terminology; instead add the role distinction.

`by-memory/0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md`

- Add a support note only if implementation scope includes adjacent raw helpers: [UID:0003UX] and [UID:0003UY] are sibling retained raw helpers in the same movement/facing packet island and likely share the same local movement record ring. Do not claim [UID:0003UX] calls [UID:0003UY].

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` during the report pass. The current coverage report has no [UID:0003UX] row. Recommended supervisor-owned insertion: place this under the [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions` child block in address order, after any `0x005ac6a0` sibling/predecessor row if it is added later and before [UID:0003UY] `0x005ac9a0-0x005acad5`.

Exact replacement/insertion row:

```markdown
        - [UID:0003UX][0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper](by-memory/0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md) 0x005ac7e0-0x005ac99b | retained no-route raw packet helper | LivingObjectPaneRawWaypointPacketHelper : reconstructable : 88% : strong : B003 source-quality pass decodes this retained LivingObjectPane waypoint/path packet helper as opcode `0x06` with subtype/waypoint-kind byte, movement/status history token from `+0x13eb1c` gated by `m_mapPane` at `+0x1340f8`, MapPane `+0x40e`, and `g_pConfig+0x28de75`, current facing byte `+0x1a0`, ObjectPane map coordinates `+0x100/+0x104`, two waypoint segment coordinates plus one-byte deltas from a four-dword segment argument, and a final uint16 waypoint token; updates 0x10-byte records at `+0x13eb14` with capacity `+0x13eb18` and write index `+0x13eb1c`; sends through Socket-owned `QueueAndSendPacket(g_packetSender, packet, packetLen)` after a local unsent terminator and `<0x12` range guard. Raw PE/Capstone scan found no IDA function object, rel32 caller, VA/RVA pointer, vtable route, or fallthrough into `0x005ac7e0`; formal C++ should remain blank until a retained-dead-helper/source-route policy or caller route is proven.
```

## Validation Commands For Future Implementation

Run from `source-3/project-documentation` after a later implementation callback edits by-* docs:

> Executable block R001 was removed from this report and preserved verbatim in [0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality-removed.md](0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation also updates adjacent linked-record/facing helpers, validate those exact files as well:

> Executable block R002 was removed from this report and preserved verbatim in [0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality-removed.md](0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No validators were run during this report-only pass because no by-* files were edited.

## IDA Rename, Type, And Comment Recommendations

Rename recommendations:

- `0x005ac7e0`: `LivingObjectPane::SendMovementWaypointPacketRaw` or IDA-safe `LivingObjectPane_SendMovementWaypointPacketRaw` (medium confidence; no-route retained raw helper).
- `0x005055d0`: if not already named, `MapPane::AllowsMovementStatusFlag` or `MapPane::IsNormalMovementStatusClear` (medium-high confidence from existing MapPane/g_pConfig docs).
- `0x005374d0`: `ObjectPane::GetMapPosition` (high confidence from existing target).
- Packet helpers should use existing documented names: `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `PacketBufferAppendUInt8`, `PacketBufferAppendUInt16BE`.
- `0x00574bb0`: `QueueAndSendPacket` / Socket send funnel (high confidence from existing doc).

Prototype recommendation for `0x005ac7e0`:

```cpp
void __thiscall LivingObjectPane::SendMovementWaypointPacketRaw(
    unsigned char waypointKind,
    unsigned short waypointToken,
    const LivingObjectWaypointSegment *segment);
```

Type recommendations:

```cpp
struct LivingObjectWaypointSegment
{
    unsigned int startCoord0;
    unsigned int startCoord1;
    unsigned int endCoord0;
    unsigned int endCoord1;
};

struct LivingObjectWaypointHistoryRecord
{
    unsigned char active;
    unsigned char pad01[3];
    int coordFromOffset104;
    int coordFromOffset100;
    unsigned char waypointKind;
    unsigned char pad0d[3];
};
```

Field-name recommendations:

- `+0x1340f8`: `m_mapPane` (existing UserPane/LivingObjectPane large-object field).
- `+0x13eb14`: `m_waypointHistoryRecords` or `m_movementPredictionRecords`.
- `+0x13eb18`: `m_waypointHistoryCapacity`.
- `+0x13eb1c`: `m_waypointHistoryWriteIndex`.
- `+0x1a0`: `m_facingDirection` / `m_currentFacing`.
- `ObjectPane+0x100/+0x104`: keep exact offset names or `mapCoordFromOffset100/mapCoordFromOffset104` until axis order is finalized.

Comment recommendation at `0x005ac7e0`:

```cpp
// Retained no-route LivingObjectPane raw movement/waypoint packet helper.
// Builds opcode 0x06 packet: subtype, movement/status history token, facing,
// current map position, segment start coordinates, one-byte deltas, and final token.
// Updates +0x13eb14/+0x13eb18/+0x13eb1c record ring and sends via QueueAndSendPacket.
// No rel32/VA/RVA/vtable/fallthrough route found; do not model as live-called until a route appears.
```

## Rejected Alternatives

- `UserPane` owner: rejected because `this+0x1340f8` is a dependency field on the large local-player object, while behavior and source neighborhood are LivingObjectPane movement/packet code.
- `MapPane` owner: rejected because MapPane provides only a status predicate.
- Socket or PacketBuffer owner: rejected because those are generic helper dependencies and do not own the feature-specific packet layout or record update.
- Merge into [UID:0003UY] `LivingObjectPaneRawFacingPacketHelper`: rejected by `0xcc` padding at `0x005ac99b-0x005ac9a0` and independent function-shaped body.
- Merge backward into predecessor `0x005ac6a0`: rejected by predecessor `ret 4`, range-check tail, and `0xcc` padding at `0x005ac7d7-0x005ac7e0`.
- Mark as dead padding: rejected by coherent stack-cookie function structure, packet construction, field updates, and queue-send call.
- Emit first-draft C++ now: rejected by target-specific no-route evidence.

## Implementation Checklist For Later Callback

1. Update target metadata to `88/89`, preserving owner/emitter/reconstructable fields.
2. Replace passive open questions with the decoded route-negative proof, packet layout, field map, and source-quality name/signature direction.
3. Keep formal C++ blank and add target-specific no-code proof.
4. Add exact boundary/padding map including predecessor and successor separation.
5. Update parent aggregate and class/file support docs with the decoded helper role and field cluster.
6. Update focused support docs for `m_mapPane`, `g_pConfig+0x28de75`, MapPane `0x005055d0`, packet writer/append helpers, `QueueAndSendPacket`, `g_packetSender`, and `ObjectPane::GetMapPosition` where local text has a natural xref section.
7. Do not edit `by-memory/-coverage-report.md`; provide the exact row above for supervisor-owned insertion.
8. Run the validator commands listed above for every edited by-* file.

## Report-Only File Changes

This report pass creates only:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality.md`

No by-* documentation, generated output, IDA database, project-level reports, or coverage files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"0003UX"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003UX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
