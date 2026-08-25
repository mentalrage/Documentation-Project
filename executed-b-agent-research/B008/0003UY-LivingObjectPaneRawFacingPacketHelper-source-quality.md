** TARGET-REPORT-UID:0003UY **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0003UY] LivingObjectPaneRawFacingPacketHelper Source-Quality Report

Agent: B008  
Date: 2026-06-19  
Assignment: `B008-goal2-living-object-facing-packet-helper-source-quality-0003UY-20260619`  
Target: `source-3/project-documentation/by-memory/0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md`  
Required output: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md`

## Report-Only Status

This pass is report-only. I did not edit the target by-memory page, support by-* docs, generated source, IDA database, or `by-memory/-coverage-report.md`.

The current target doc is `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank formal C++. The existing open questions say direct reachability, semantic name, packet fields, and linked-record names are unresolved. This report resolves the byte-level behavior, gives high-probability source names and field names, keeps the route/liveness caveat specific, and recommends blank formal C++ for the target until retained raw-helper emission policy is approved.

## Final Recommendation

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:00007B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007B
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: keep blank
```

Recommended source-facing role:

`LivingObjectPane::SendFaceDirectionPacket(unsigned char direction)` is the best current source/search alias because [UID:0001KM] already lists `0x005ac9a0` as `SendFaceDirectionPacket`, and generated/simroot evidence uses the same phrase. The more precise documented role should be "fixed opcode `0x32` facing/movement-history packet helper" or "normal movement/facing packet helper" because the body does more than face-only direction: it sends the facing byte, movement-history tag, movement-speed byte, current X/Y tile, and updates the 0x40-entry local movement-history ring.

Recommended IDA/raw name if a function object is created:

```text
LivingObjectPane_SendFaceDirectionPacketRaw_5AC9A0
```

Alternative acceptable comment/name:

```text
LivingObjectPane_SendFacingMovementPacketRaw_5AC9A0
```

Do not collapse this target into [UID:0003H4]. [UID:0003H4] sends the much smaller opcode `0x11` direction packet. This target sends opcode `0x32`, serializes position/history state, and updates the local movement-history ring.

Formal C++ recommendation:

Keep the target's formal `RECONSTRUCTION_CPP` blank. The body is reconstructable as behavior, but local PE route scans and existing IDA/B001 evidence show no function object and no direct route to `0x005ac9a0`; the live movement path appears to inline equivalent logic in `0x005a2e00`, and this raw helper is a retained duplicate/helper island. A source-style sketch is provided below for documentation/support use, but should not be emitted as a normal live method from this by-memory page until a retained-dead/raw-helper source policy is accepted.

## Evidence Checked

Target and support docs checked:

- Target: `by-memory/0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md`.
- Parent/split index: [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`.
- Adjacent raw helpers:
  - [UID:0003UX] `by-memory/0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md`.
  - [UID:0003H4] `by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md`.
  - [UID:0003H5] `by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md`.
  - [UID:0003UZ] `by-memory/0x005acc30-0x005acd85.LivingObjectPaneSendActionPacketWithAutoFace.md`.
- Linked-record/movement-history helpers:
  - [UID:0003VE] `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`.
  - [UID:0003UF] `by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md`.
  - [UID:0003UG] `by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`.
- Movement/action siblings:
  - [UID:0003UI] `by-memory/0x005a8cf0-0x005a8e67.LivingObjectPaneSendMovementPacket.md`.
  - [UID:0003UV] `by-memory/0x005ac1b0-0x005ac27c.LivingObjectPaneRawPositionSyncPacketHelper.md`.
  - [UID:0003Z5] `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md`.
- Support helpers/globals:
  - [UID:00024A] `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`, which records `this+0x1340f8` as `MapPane *m_mapPane` and includes a 0003UY use at `0x005ac9cf`.
  - [UID:0001HU] `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`.
  - [UID:0001P0] `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`.
  - [UID:0003YJ] `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`.
  - [UID:0003YM] `by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md`.
  - [UID:0003XP] `by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md`.
  - [UID:0001AP] `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`.
  - [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`.
- Class/file docs:
  - [UID:00007B] `by-class/LivingObjectPane.md`.
  - `by-file/LivingObjectPane.md`.
- Prior research:
  - B001 `research/00007B-LivingObjectPane-class-source-quality.md`.
  - B001 executed `research/executed/0001DE-LivingObjectPaneCore-source-quality.md`.
  - B001 executed older `research/executed/older/0001KM-livingobject-localplayer-source-split-audit.md`.
  - A004/B001 `0003EB` action float constant reports for neighboring raw helper split context.
- Generated/source comparison:
  - `source-3/simroot_v2/class_LivingObjectPane.cpp`.
  - `source-3/project-documentation/auto-generated/NexusTK/map/LivingObjectPane.cpp`.
- Coverage state:
  - `rg "0003UY|005ac9a0|LivingObjectPaneRawFacingPacketHelper" by-memory/-coverage-report.md` found no current row in supervisor-owned `by-memory/-coverage-report.md`.
  - `auto-generated/-ag-memory-coverage.md` contains the generated row for [UID:0003UY], but that file is generated support, not the banned coverage file.

Executable evidence used:

- Local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` and existing local disassembly/Capstone pass from this assignment context.
- Raw range bytes:
  - `0x005ac99b-0x005ac9a0`: five `0xcc` bytes before this helper.
  - `0x005ac9a0-0x005acad5`: 309-byte function-shaped raw body, starts `55 8b ec 83 ec 18`, uses security-cookie setup, saves `ebx`/`esi`, and ends `5d c2 04 00`.
  - `0x005acad5-0x005acae0`: eleven `0xcc` bytes before [UID:0003H4].
- Route scan:
  - No rel32 call/jump/conditional branch target, absolute VA, or RVA reference to `0x005ac9a0` in the local PE scan.
  - No route scan hits to `0x005acad5`, `0x005acae0`, `0x005ac7e0`, or notable interior labels such as `0x005ac9cf`/`0x005aca69`.
  - This agrees with B001/B004-era evidence that `lookup_funcs 0x005ac9a0` is not a function and `xrefs_to 0x005ac9a0` is empty.

## Exact Boundary And Raw Body

The target is correctly bounded as `0x005ac9a0-0x005acad5`. The prior helper [UID:0003UX] ends before `0x005ac99b`; five `0xcc` bytes align to `0x005ac9a0`. This helper returns with `ret 4` at the end of its cookie epilogue. The successor padding `0x005acad5-0x005acae0` is eleven `0xcc` bytes, and [UID:0003H4] starts at `0x005acae0`.

Important disassembly/behavior:

```text
0x005ac9a0  prologue, 0x18-byte local stack, security cookie
0x005ac9b7  PacketBufferWriteUInt8(&packet[0], 0x32)
0x005ac9bf  bl = byte ptr [ebp+8]
0x005ac9c2  PacketBufferWriteUInt8(&packet[1], sign_extended(bl))
0x005ac9cf  ecx = [this+0x1340f8]; call 0x005055d0
0x005ac9df  if zero/equal, use untagged history index
0x005ac9e1  eax = g_pConfig; cmp byte [eax+0x28de75], 0
0x005ac9ef  tagged path: tag = [this+0x13eb1c] | 0x80
0x005ac9fd  untagged path: tag = [this+0x13eb1c] & 0x7f
0x005aca07  PacketBufferWriteUInt8(&packet[2], tag)
0x005aca15  PacketBufferWriteUInt8(&packet[3], byte [this+0x1a0])
0x005aca25  ObjectPane::GetMapPosition(this, &positionPair)
0x005aca34  PacketBufferWriteUInt16BE(&packet[4], positionX)
0x005aca40  PacketBufferWriteUInt16BE(&packet[6], positionY)
0x005aca48  record = [this+0x13eb14] + ([this+0x13eb1c] * 0x10)
0x005aca57  record->tileY = positionY
0x005aca5e  record->tileX = positionX
0x005aca74  record->direction = direction
0x005aca87  record->active = 1
0x005aca8b  writeIndex = (writeIndex + 1) % [this+0x13eb18]
0x005aca9a  PacketBufferWriteUInt16BE(&packet[8], 0x32)
0x005acaab  QueueAndSendPacket(g_packetSender, packet, 9)
0x005acad1  cookie epilogue
0x005acad5  ret 4
```

The local packet buffer is effectively `packet[10]` or larger on the stack. `PacketBufferWriteUInt8` writes the payload byte and a spare NUL at the following byte; `PacketBufferWriteUInt16BE` writes high byte, low byte, and a spare NUL after the word. The explicit store at `0x005acaa7` clears the low byte after `PacketBufferWriteUInt16BE(&packet[8], 0x32)`, leaving sent byte 8 as `0x32` and a local NUL terminator at byte 9. The send length is exactly 9, so the terminator is not sent.

## Packet Layout

The sent packet is a fixed nine-byte opcode `0x32` packet:

| Offset | Size | Value | Evidence and source-quality interpretation |
|---:|---:|---|---|
| `0` | 1 | `0x32` | Written by `PacketBufferWriteUInt8` at `0x005ac9b7`; packet-family opcode for normal local movement/facing update. |
| `1` | 1 | `direction` / facing byte | Caller argument `[ebp+8]` copied through `bl`; sign-extended for the helper call but only the low byte is serialized. Treat as `unsigned char direction`, not an `int` protocol field. |
| `2` | 1 | `historyTag` | Current write index `[this+0x13eb1c]`, high bit set when both `MapPane` movement gate helper and `g_pConfig+0x28de75` allow the tag; otherwise `index & 0x7f`. |
| `3` | 1 | movement speed/delay byte | `byte [this+0x1a0]`, which corresponds to `ObjectPane.m_objectState[0x98]`; constructor/generated evidence initializes the related state byte to `0x50` and movement code uses it as animation/movement delay. |
| `4..5` | 2 | current tile X, big-endian | From `ObjectPane::GetMapPosition`, value at local `[ebp-0x14]`; helper `0x005753a0` is big-endian. |
| `6..7` | 2 | current tile Y, big-endian | From `ObjectPane::GetMapPosition`, value at local `[ebp-0x18]`; helper `0x005753a0` is big-endian. |
| `8` | 1 | `0x32` marker | Produced by writing UInt16BE(0x32) at `packet[8]`, then clearing the low byte at `packet[9]`; only byte 8 is sent. Likely a duplicated opcode/trailer marker in this protocol family. |

Rejected packet interpretations:

- This is not the same packet as [UID:0003H4]. [UID:0003H4] sends opcode `0x11` with length 2 and does not touch the movement-history ring.
- This is not a pure facing-only helper. The direction byte is important, but the body serializes current map position, movement state, and a history sequence/tag.
- The coordinate words are not little-endian. Some generated source uses `write_u16` in a way that looks little-endian, but the documented scalar helper `0x005753a0` writes high byte first (`value >> 8`) and then low byte. The target docs should explicitly preserve this correction.
- The sign-extension at `movsx eax, bl` is not a source-level signed protocol field. `PacketBufferWriteUInt8` truncates to the low byte, and all sibling direction/facing docs treat direction as a byte.

## Linked-Record / Movement-History Field Model

The target's "linked-record array" is better documented as a local movement-history or movement-prediction record ring. Existing docs use "linked record" across `0x005a87b0` and adjacent clear helpers; preserve the alias for continuity, but add the movement-history role.

Recommended field names:

| Offset from adjusted `this` | Recommended name | Type / role | Evidence |
|---:|---|---|---|
| `+0x1340f8` | `m_mapPane` | `MapPane *` | [UID:00024A] accessor and displacement table; this target calls `0x005055d0` through this pointer at `0x005ac9cf`. |
| `+0x13eb14` | `m_movementHistory` or `m_localMovementHistory` | `LocalMovementHistoryRecord *` | Constructor allocates `0x400` bytes for 0x40 records, target and clear/access helpers use it as a stride-0x10 array. |
| `+0x13eb18` | `m_movementHistoryCapacity` | `int` | Constructor initializes `0x40`; target uses as modulus divisor after incrementing write index; access/clear helpers use it as bounds/count. |
| `+0x13eb1c` | `m_movementHistoryWriteIndex` | `unsigned char` or byte-sized index | Target reads it, serializes low seven bits plus optional high-bit tag, advances modulo capacity, and stores the low byte result. |
| `+0x1a0` | `m_objectState[0x98]` / provisional `m_movementDelay` | `unsigned char` | Target sends it as packet byte 3; constructor/generated evidence sets object state byte `0x98` to `0x50`; movement code uses the same byte for animation delay/speed. Avoid naming it solely `speed` until all ObjectPane state names are normalized. |

Recommended record layout:

```cpp
struct LocalMovementHistoryRecord
{
    unsigned char active;       // +0x00, zero means free/inactive
    unsigned char reserved01[3];
    int tileY;                  // +0x04, ObjectPane::GetMapPosition out[0] / this+0x104
    int tileX;                  // +0x08, ObjectPane::GetMapPosition out[1] / this+0x100
    unsigned char direction;    // +0x0c
    unsigned char reserved0d[3];
};
```

Coordinate order evidence:

- `ObjectPane::GetMapPosition` stores `this+0x104` into output element 0 and `this+0x100` into output element 1.
- This target sends output element 1 first as packet X, then output element 0 as packet Y.
- The history record stores output element 0 at record `+4` and output element 1 at record `+8`. Therefore record `+4` is `tileY`, and record `+8` is `tileX`.
- The existing `GetActiveLinkedRecordByIndexRaw` helper returns the record only when byte `+0` is nonzero. The clear helpers only clear byte `+0`, not the coordinate fields.

Constructor/evidence route for the ring:

- The LivingObjectPane local-player constructor area initializes `[this+0x13eb18] = 0x40`, allocates `0x400` bytes, stores it at `[this+0x13eb14]`, clears each record's `active` byte, and sets `[this+0x13eb1c] = 0`.
- `0x40 * 0x10 = 0x400`, matching the observed record stride and allocation.
- Both [UID:0003UX] and [UID:0003UY] update the same `active/tileY/tileX/direction/writeIndex` tail, proving this is a shared movement-history/prediction ring rather than a packet-local scratch buffer.

## Relationship To Neighbor Targets

[UID:0003UX] `0x005ac7e0-0x005ac99b`:

- [UID:0003UX] is the extended/waypoint packet sibling. It uses opcode `0x06`, starts with the same direction byte, uses the same high-bit movement-history tag, sends the same movement-state byte and current X/Y, then appends additional path/edge/word fields through cursor helpers.
- It updates the same `m_movementHistory` record and advances the same write index.
- It sends variable length only under a packet-length range check.
- This relationship strongly supports naming [UID:0003UY] as the fixed/normal movement-facing packet helper.

[UID:0003H4] `0x005acae0-0x005acb1f`:

- [UID:0003H4] is a separate simple direction-packet raw helper. It writes opcode `0x11`, the caller-supplied direction byte, a local terminator, and sends length 2.
- It does not call `MapPane`, `g_pConfig`, `ObjectPane::GetMapPosition`, `PacketBufferWriteUInt16BE`, or update `m_movementHistory`.
- The successor relationship is padding only: `0x005acad5-0x005acae0` is alignment between the helpers. Do not merge these pages or describe [UID:0003UY] as the opcode `0x11` helper.

[UID:0003H5] and [UID:0003UZ]:

- [UID:0003H5] derives a direction to face toward a target/action using float thresholds and sends a simple direction packet only if needed. It is route-negative like the other raw helpers.
- [UID:0003UZ] is modeled and has a caller at `0x005a58c0`; it sends action packets and may auto-face. It is the live modeled sibling near this raw island.
- The raw target should be documented as local-player movement/facing support, not action-tail support.

Live movement process relationship:

- Generated/simroot `class_LivingObjectPane.cpp` contains a `SendFaceDirectionPacket(std::uint8_t direction)` body matching this target's broad behavior.
- The same generated file also shows equivalent inline normal-packet code inside the modeled movement process around the `0x005a2e00` cluster, with opcode `0x32`, history tag, movement state byte, X/Y serialization, history record update, and send length 9.
- This supports the source-body inference but also supports the no-formal-C++ recommendation: the raw helper appears retained/duplicated while the live source route is likely in the modeled movement process.

## Heuristic / Inference Reanalysis And Validation

### Raw helper status and reachability

Conclusion: retained raw helper body, no proven live route.

Evidence:

- Existing IDA/B001 docs report no function object at `0x005ac9a0` and no entry xrefs.
- This assignment's local PE route scan found zero rel32 call/jump/conditional-branch targets, absolute VA hits, or RVA hits to `0x005ac9a0`.
- Positive controls in B001 research found live routes to nearby modeled starts such as `0x005a4530`, `0x005a3e30`, `0x005a58c0`, `0x005acc30`, and `0x005a5a90`, so the zero-route result is meaningful and not a broken scan.
- The target has a normal prologue/security-cookie/epilogue and `ret 4`, so it is source-shaped even if unreferenced. The correct classification is "raw no-route retained helper", not padding and not runtime/compiler glue.

### Source-facing helper name and signature

Best-supported signature:

```cpp
void LivingObjectPane::SendFaceDirectionPacket(unsigned char direction);
```

Confidence: medium.

Evidence:

- [UID:0001KM] already lists the projected start `0x005ac9a0` as `SendFaceDirectionPacket`.
- Generated/simroot source uses `LivingObjectPane::SendFaceDirectionPacket(std::uint8_t direction)` for a body matching opcode `0x32`, direction byte, history tag, movement-state byte, X/Y position, history ring update, and send length 9.
- The binary ABI is a `thiscall`-style raw body using `ecx=this` and one 4-byte stack argument, but the body only uses `byte [ebp+8]`; source should use `unsigned char` or an enum-like facing/direction byte.

Rejected names:

- `SendDirectionPacket`: too broad and already better reserved for [UID:0003H4] opcode `0x11`.
- `SendFaceOnlyPacket`: wrong because this target includes position/history state.
- `SendWaypointPacket`: belongs to [UID:0003UX] opcode `0x06` sibling.
- `SendMovementPacket`: already too close to [UID:0003UI] and the modeled movement process; use as role text only unless class docs standardize names later.

Recommended doc wording: "best current source/search alias `SendFaceDirectionPacket`; behavior is the fixed opcode `0x32` normal movement/facing-history packet helper."

### Packet field names and helper roles

Conclusion:

- `0x00575380`: `PacketBufferWriteUInt8`.
- `0x005753a0`: `PacketBufferWriteUInt16BE`.
- `0x00574bb0`: `QueueAndSendPacket`.
- `0x0067a7ec`: `g_packetSender`.
- `0x005374d0`: `ObjectPane::GetMapPosition(MapPoint *out)` or equivalent two-int position copy helper.

Evidence:

- Existing support docs and raw disassembly agree on helper behavior.
- `PacketBufferWriteUInt16BE` high-byte-first behavior directly corrects generated little-endian-looking source.
- `QueueAndSendPacket` call uses `g_packetSender`, packet pointer, and length 9, then returns through cookie epilogue.

### MapPane/config high-bit tag semantics

Conclusion: packet byte 2 is a movement-history write index, with bit 7 optionally tagged by a MapPane movement gate plus a user/config movement-status option. The exact product label for the high bit is still not recoverable from binary alone; document it as `historyTag` / `movementStatusTag`, not as "day mode."

Evidence:

- `0x005ac9cf` calls `MapPane` helper `0x005055d0` through `this+0x1340f8`.
- `0x005055d0` is a one-byte predicate over `MapPane+0x40e`, returning true when that byte is zero.
- If that predicate is true and `g_pConfig+0x28de75` is nonzero, the target serializes `[this+0x13eb1c] | 0x80`; otherwise it serializes `[this+0x13eb1c] & 0x7f`.
- `g_pConfig+0x28de75` is already documented as a map/movement status option byte written by an option pane and consumed with the same MapPane predicate.

Rejected alternative:

- Generated/simroot calls the MapPane predicate `IsDayMode()` and config byte `useTaggedFacingHistory`. The binary and support docs only support a movement/map-status gate, not day/night semantics. Preserve the high-bit tag behavior without adopting the stale generated names.

### `this+0x1a0` field name

Conclusion: packet byte 3 should be documented conservatively as `m_objectState[0x98]` / movement delay byte, with a provisional role `m_movementDelay` or `m_moveSpeedByte`.

Evidence:

- The target uses `byte [this+0x1a0]`, which is offset `0x98` into the embedded `ObjectPane` state area if the normal LivingObjectPane/ObjectPane base layout is applied.
- Generated constructor evidence initializes state byte `0x98` to `0x50`.
- Movement code uses the same state byte as an animation/movement timing divisor or delay in generated/simroot output.

Rejected alternative:

- Do not document this as a linked-record field; it is read before the history record pointer is computed and lives in the object state area.

### Movement-history record field names

Conclusion: replace the vague linked-record names with movement-history names while preserving linked-record alias.

Best field names:

- `m_movementHistory` at `+0x13eb14`.
- `m_movementHistoryCapacity` at `+0x13eb18`.
- `m_movementHistoryWriteIndex` at `+0x13eb1c`.
- `LocalMovementHistoryRecord::active`, `tileY`, `tileX`, `direction`.

Evidence:

- Constructor allocation and clear loops prove 0x40 records of 0x10 bytes.
- `GetActiveLinkedRecordByIndexRaw` and clear helpers prove the active byte semantics.
- Target and [UID:0003UX] prove record coordinate/direction semantics and ring advancement.

Uncertainty:

- Original source spelling could have been `m_moveHistory`, `m_linkedRecord`, or a Korean/Nexon-internal term. Binary evidence does not preserve the spelling. The recommended names are descriptive source-quality names suitable for docs and generated C++ sketches.

### Owner, source placement, and emitter

Conclusion: keep owner/emitter [UID:00007B] `LivingObjectPane`; source placement belongs in `LivingObjectPane.cpp` under the local-player movement/facing packet helper neighborhood.

Evidence:

- The body operates on LivingObjectPane/ObjectPane fields, movement-history fields, and packet helpers.
- Parent [UID:0001KM] routes the local-player extension cluster through LivingObjectPane and lists this child.
- [UID:00024A] confirms the `m_mapPane` field is part of the same adjusted object layout and records this target as a MapPane-field consumer.

Caveat:

- The large offsets such as `+0x1340f8` and `+0x13eb14` are not ordinary small `LivingObjectPane` object offsets. Prior B001 work interprets them as a local-player/UserPane aggregate viewed through an adjusted LivingObjectPane pointer. That should be stated in support docs to avoid presenting these as base object layout fields.

### Split/merge policy

Conclusion: no range split is recommended for [UID:0003UY]. Keep `0x005ac9a0-0x005acad5` as one raw helper page.

Evidence:

- Single prologue, single cookie setup, single epilogue, single `ret 4`.
- Internal labels are only conditional branches for history-tag selection and ring advancement.
- Predecessor and successor padding are already covered by `-ignored.md`.

Rejected merge:

- Do not merge with [UID:0003UX], because [UID:0003UX] is a separate `ret 0x0c` extended/waypoint helper ending before padding.
- Do not merge with [UID:0003H4], because [UID:0003H4] begins after `0xcc` padding and sends a distinct opcode `0x11` packet.

## First-Draft C++ Readiness

Formal target C++ should remain blank for now.

Target-specific no-code proof:

1. IDA does not define a function at `0x005ac9a0`.
2. Current docs and this pass find no entry xrefs or PE route to `0x005ac9a0`.
3. The body is function-shaped and reconstructable, but route-negative raw helper pages in this LivingObjectPane local-player tail have been treated as retained helper/dead-code candidates unless a live route or raw-helper emission policy is accepted.
4. The live modeled movement process around `0x005a2e00` appears to inline equivalent opcode `0x32` movement/facing-history logic, so emitting this target as a normal called method would likely duplicate source unless the source policy explicitly models retained helpers.
5. The original source spelling is not proven. `SendFaceDirectionPacket` is high-probability, but not enough by itself to override the route-negative no-function caveat.

Source-style behavioral sketch for docs/support only, not recommended for the target's formal C++ block yet:

```cpp
void LivingObjectPane::SendFaceDirectionPacket(unsigned char direction)
{
    unsigned char packet[10];

    PacketBufferWriteUInt8(&packet[0], 0x32);
    PacketBufferWriteUInt8(&packet[1], direction);

    unsigned char historyTag = m_movementHistoryWriteIndex & 0x7f;
    if (m_mapPane->IsMovementStatusTagEnabled() && g_pConfig->mapMovementStatusOption != 0)
        historyTag = m_movementHistoryWriteIndex | 0x80;

    PacketBufferWriteUInt8(&packet[2], historyTag);
    PacketBufferWriteUInt8(&packet[3], m_objectState[0x98]);

    int position[2];
    GetMapPosition(position);        // position[0] = Y, position[1] = X
    PacketBufferWriteUInt16BE(&packet[4], position[1]);
    PacketBufferWriteUInt16BE(&packet[6], position[0]);

    LocalMovementHistoryRecord *record =
        &m_movementHistory[m_movementHistoryWriteIndex];
    record->tileY = position[0];
    record->tileX = position[1];
    record->direction = direction;
    record->active = 1;

    m_movementHistoryWriteIndex =
        static_cast<unsigned char>((m_movementHistoryWriteIndex + 1) %
                                   m_movementHistoryCapacity);

    PacketBufferWriteUInt16BE(&packet[8], 0x32);
    packet[9] = 0;
    QueueAndSendPacket(g_packetSender, packet, 9);
}
```

Notes for this sketch:

- `IsMovementStatusTagEnabled()` is a descriptive placeholder for `MapPane` helper `0x005055d0`; do not commit this exact method name without broader MapPane naming alignment.
- `m_objectState[0x98]` should remain bracketed/descriptive until ObjectPane state names are normalized.
- The sketch uses source-quality helper names, not raw decompiler names.
- The formal by-memory block should stay blank unless the supervisor explicitly accepts raw no-route helper emission.

## Recommended Target Doc Changes

For `by-memory/0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md`:

1. Change score metadata to `COMPLETION:87`, `CONFIDENCE:89`; keep owner/emitter as [UID:00007B].
2. Replace the current summary with:
   - Exact raw helper range `0x005ac9a0-0x005acad5`, no IDA function object, no entry xrefs.
   - Body sends fixed nine-byte opcode `0x32` movement/facing-history packet.
   - Body updates the local movement-history ring and advances write index modulo capacity.
   - Successor [UID:0003H4] is a different opcode `0x11` direction helper.
3. Add a boundary section:
   - `0x005ac99b-0x005ac9a0` five `0xcc` bytes.
   - `0x005ac9a0` prologue/security cookie.
   - `0x005acad5` `ret 4` end.
   - `0x005acad5-0x005acae0` eleven `0xcc` bytes before [UID:0003H4].
4. Add the packet layout table from this report.
5. Add the movement-history field table:
   - `m_mapPane` `+0x1340f8`.
   - `m_movementHistory` `+0x13eb14`.
   - `m_movementHistoryCapacity` `+0x13eb18`.
   - `m_movementHistoryWriteIndex` `+0x13eb1c`.
   - `m_objectState[0x98]` / movement delay byte at `+0x1a0`.
   - record fields `active`, `tileY`, `tileX`, `direction`.
6. Add source-name recommendation:
   - Best alias `SendFaceDirectionPacket(unsigned char direction)`.
   - Role name `fixed opcode 0x32 movement/facing-history packet helper`.
7. Replace open questions:
   - Reachability remains unresolved, but not generic: no function object, no xrefs, and local PE route scan found zero route hits.
   - Packet fields and linked-record names are resolved as above.
8. Keep formal C++ blank and add the no-code proof:
   - route-negative raw helper;
   - live inline-equivalent movement process evidence;
   - emitted C++ would likely duplicate source without retained-helper policy.
9. Add a 2026-06-19 change-log entry with:
   - B008 resolved exact packet layout, big-endian helper behavior, movement-history field names, sibling distinctions, generated-source stale little-endian/MapPane-name issues, and the retained raw-helper C++ policy.

## Recommended Support Doc Changes

Support docs should preserve report-level detail rather than a compact sentence.

1. [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
   - Update the `0x005ac9a0` projected row from only `SendFaceDirectionPacket`/no-function to:
     - best alias `SendFaceDirectionPacket(unsigned char direction)`;
     - fixed opcode `0x32` movement/facing-history packet;
     - no function object/no route;
     - sibling with [UID:0003UX] extended waypoint packet and [UID:0003H4] simple opcode `0x11` direction packet;
     - formal C++ remains blank unless raw helper emission policy is accepted.
   - Add exact packet layout and movement-history ring summary or a pointer to the child page.

2. [UID:00007B] `by-class/LivingObjectPane.md`
   - Add a field/layout subsection for local-player movement-history state:
     - `m_movementHistory`, `m_movementHistoryCapacity`, `m_movementHistoryWriteIndex`, and `LocalMovementHistoryRecord`.
   - State that these large offsets are local-player/UserPane aggregate offsets viewed through adjusted LivingObjectPane `this`, not ordinary compact base-object layout fields.
   - Update the method/helper list for [UID:0003UY] from unresolved raw facing helper to fixed opcode `0x32` movement/facing-history raw helper, no proven route.

3. `by-file/LivingObjectPane.md`
   - Add the source-placement note: `LivingObjectPane.cpp` local-player movement/facing packet helper neighborhood.
   - Preserve route-negative caveat for raw starts `0x005ac7e0`, `0x005ac9a0`, `0x005acae0`, and `0x005acb20`.
   - Add the best source/search alias `SendFaceDirectionPacket` with no formal emitter approval yet.

4. [UID:0003UX] `by-memory/0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md`
   - Add cross-note that [UID:0003UX] shares the same movement-history update tail and high-bit tag semantics as [UID:0003UY], but sends the extended opcode `0x06` waypoint/path packet.

5. [UID:0003H4] `by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md`
   - Add contrast note: [UID:0003H4] is the simple opcode `0x11`, length-2 direction helper and does not update movement-history state; [UID:0003UY] is the opcode `0x32`, length-9 movement/facing-history helper.

6. [UID:0003VE] `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`
   - Update "linked record" wording with the movement-history alias and record layout:
     - active byte at `+0`;
     - `tileY` at `+4`;
     - `tileX` at `+8`;
     - `direction` at `+0xc`;
     - stride `0x10`.

7. [UID:0003UF] `by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md`
   - Add that clearing only byte `+0` marks records inactive and does not zero the retained X/Y/direction payload.

8. [UID:0003UG] `by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`
   - Same movement-history alias and active-byte-only clear semantics.

9. [UID:0003UI] `by-memory/0x005a8cf0-0x005a8e67.LivingObjectPaneSendMovementPacket.md` or the modeled movement process child in the `0x005a2e00` cluster
   - Add a cross-note that live movement code appears to inline an equivalent opcode `0x32` normal movement/facing-history packet path, while [UID:0003UY] remains a retained raw no-route helper.

10. [UID:00024A] `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`
    - Optional: update the displacement table prose for `0x005ac9cf` from generic "Facing packet path" to "opcode `0x32` movement/facing-history packet path; calls MapPane movement-status gate through `m_mapPane`."

11. [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
    - Optional: add [UID:0003UY] as a consumer of `g_pConfig+0x28de75`, with semantics "enables high-bit movement-history tag when MapPane gate allows it."

12. `by-memory/-ignored.md`
    - No change required. Existing padding entry already includes `0x005ac99b-0x005ac9a0` and `0x005acad5-0x005acae0`. If target/support implementation wants stronger detail, add that the padding was reconfirmed by B008 while leaving the exact ignored ranges unchanged.

## Exact Supervisor-Owned Coverage Text

`by-memory/-coverage-report.md` currently has no `0003UY` or `0x005ac9a0` match by local `rg`. Insert the following row in the LivingObjectPane local-player raw-helper neighborhood, after the [UID:0003UX] row and its `0x005ac99b-0x005ac9a0` padding row if that padding is present, and before the `0x005acad5-0x005acae0` padding / [UID:0003H4] row. If a row is added before implementation, replace it with this exact text.

```text
        - [UID:0003UY][0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper](by-memory/0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md) 0x005ac9a0-0x005acad5 | raw packet helper | LivingObjectPaneRawFacingPacketHelper : reconstructable : 87% : strong : B008 2026-06-19 source-quality pass resolves the raw no-function/no-route helper as the fixed opcode 0x32 LivingObjectPane movement/facing-history packet helper, best source/search alias `SendFaceDirectionPacket(unsigned char direction)`: sends direction byte, high-bit-tagged movement-history index gated by `MapPane` helper `0x005055d0` and `g_pConfig+0x28de75`, ObjectPane movement-state byte `this+0x1a0`, current tile X/Y as big-endian words, and a trailing sent 0x32 marker; updates the 0x40-entry stride-0x10 local movement-history ring at `this+0x13eb14/+0x13eb18/+0x13eb1c` with active/tileY/tileX/direction fields, shares the update tail with [UID:0003UX], remains distinct from opcode 0x11 direction helper [UID:0003H4], and keeps formal C++ blank because local PE/IDA route scans found no entry route to `0x005ac9a0` and the live movement path appears to inline equivalent logic.
```

## Validator Commands For Later Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after applying accepted target/support doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality-removed.md](0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not run a validator command against `by-memory/-coverage-report.md` as part of B-agent implementation unless the supervisor explicitly owns and applies that coverage change.

Validators were not run during this report-only pass because no by-* implementation files were edited.

## IDA Rename / Type / Comment Recommendations

Function/range comments:

- `0x005ac9a0`: create function only if raw-helper policy allows; name `LivingObjectPane_SendFaceDirectionPacketRaw_5AC9A0` or `LivingObjectPane_SendFacingMovementPacketRaw_5AC9A0`. Confidence medium because route is unproven but semantics are now strong.
- Add repeatable comment: "Raw no-route LivingObjectPane helper; sends fixed opcode 0x32 movement/facing-history packet, updates local movement-history ring, ret 4; not the opcode 0x11 direction helper at 0x005acae0."

Types/structs:

```cpp
struct LocalMovementHistoryRecord
{
    unsigned char active;
    unsigned char reserved01[3];
    int tileY;
    int tileX;
    unsigned char direction;
    unsigned char reserved0d[3];
};
```

Field comments/names:

- `this+0x1340f8`: `m_mapPane`, already supported by [UID:00024A].
- `this+0x13eb14`: `m_movementHistory` / `m_localMovementHistory`.
- `this+0x13eb18`: `m_movementHistoryCapacity`.
- `this+0x13eb1c`: `m_movementHistoryWriteIndex`.
- `this+0x1a0`: `m_objectState[0x98]` / provisional movement delay byte.
- `g_pConfig+0x28de75`: movement/map-status packet high-bit tag option.

Callee names to prefer:

- `0x00575380`: `PacketBufferWriteUInt8`.
- `0x005753a0`: `PacketBufferWriteUInt16BE`.
- `0x00574bb0`: `QueueAndSendPacket`.
- `0x005374d0`: `ObjectPane::GetMapPosition`.
- `0x005055d0`: provisional `MapPane::IsMovementStatusTagAllowed` or `MapPane::IsMovementGateClear`; avoid generated `IsDayMode` unless MapPane evidence later proves it.

## Open Questions And Resolutions

- Direct reachability: not proven. Evidence checked: existing IDA docs, B001 route scans, local PE route scan, generated source. Resolution: route-negative retained raw helper; score capped below first-draft emission level.
- Exact original helper name: not proven. Evidence checked: [UID:0001KM] projected name, generated/simroot source, binary behavior. Resolution: best alias `SendFaceDirectionPacket(unsigned char direction)` with descriptive role `opcode 0x32 movement/facing-history packet helper`.
- Packet fields: resolved. Exact nine-byte layout documented above.
- Endianness: resolved. `PacketBufferWriteUInt16BE` proves big-endian X/Y serialization and corrects generated little-endian-looking helper use.
- Linked-record names: resolved to movement-history ring names with caveat that exact original spellings are not recoverable.
- Relation to [UID:0003H4]: resolved. Separate helper, opcode `0x11`, length 2, no history update.
- First-draft C++: source-style sketch is available, but formal target C++ should remain blank due to no function object/no route and likely inline live equivalent.

## Implementation Checklist For Callback

If supervisor accepts this report:

1. Lease target and support docs before editing.
2. Update target [UID:0003UY] metadata to `87/89`, keep owner/emitter [UID:00007B], keep formal C++ blank.
3. Incorporate exact packet layout, boundary bytes, route-negative evidence, movement-history field model, sibling distinctions, generated-source corrections, source alias/signature, and no-code proof into the target doc.
4. Update support docs listed above with report-level detail, especially [UID:0001KM], `by-class/LivingObjectPane.md`, `by-file/LivingObjectPane.md`, [UID:0003UX], [UID:0003H4], and the linked-record helpers.
5. Do not edit `by-memory/-coverage-report.md`; keep the exact row above for supervisor-owned application.
6. Run scoped validators for every edited file using the commands above.
7. Record implementation results and pending coverage row in Agent-B008 notes if implementation is later assigned.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0003UY"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003UY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
