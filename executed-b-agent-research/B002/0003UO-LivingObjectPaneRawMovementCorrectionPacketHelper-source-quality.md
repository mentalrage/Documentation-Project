** TARGET-REPORT-UID:0003UO **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003UO LivingObjectPaneRawMovementCorrectionPacketHelper Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003UO] assigned to [UID:00007B] `LivingObjectPane` with emitter [UID:00007B], but replace the generic no-route wording with the resolved source-quality interpretation: this is a retained/out-of-line standalone form of the live `UserPane::OnServerMessage` opcode `0x04` server-warp/movement-correction case.
- Final disposition: reconstructable source-authored `LivingObjectPane` packet helper. It is not padding, not compiler glue, not a thunk, and not a `UserPane` method despite the live dispatcher duplicate. The no-entry-route condition is real, but it is now best explained as retained out-of-line source body or duplicate helper while the live dispatcher contains the inlined case body.
- Required action: update the target and support docs with the resolved opcode, payload layout, helper names, linked-record field names, route evidence, rejected alternatives, and a first-draft C++ block. Do not edit `by-memory/-coverage-report.md`; use the exact supervisor-owned row below.
- Score recommendation: `COMPLETION:87`, `CONFIDENCE:89`. This raises `85/86` because opcode/layout/source route are now resolved from the dispatcher switch table and raw PE scans. Confidence remains below `90` because the exact original source spelling for the `0x00505730` MapPane no-op hook and the original public/private helper name are inferred/descriptive rather than symbol-proven.
- C++ recommendation: populate first-draft C++ if the supervisor accepts retained/out-of-line helper emission for source-authored functions with no direct binary caller. This target is `RECONSTRUCTABLE:TRUE`, already has a valid nonblank emitter, has `(87+89)/2 > 85`, and no longer has a target-specific reason to keep C++ blank. If project policy instead chooses not to emit retained no-route duplicates, keep the formal block blank but carry the first-draft body into the notes as a no-route retained duplicate proof.

## Target

- Target UID: [UID:0003UO]
- Target path: `source-3/project-documentation/by-memory/0x005aaff0-0x005ab084.LivingObjectPaneRawMovementCorrectionPacketHelper.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`.
- Current source state: formal C++ blank because caller route, packet subtype, field names, and helper names were unresolved.
- Recommended metadata after implementation: `COMPLETION:87`, `CONFIDENCE:89`, keep `CANONICAL_OWNER:00007B`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00007B`.
- Source file route: `NexusTK/map/LivingObjectPane.cpp` through [UID:00007B] `LivingObjectPane`; do not move to `UserPane.cpp`.

## Executive Recommendation

The target should be documented as:

`bool LivingObjectPane::HandleWarpPacket(const unsigned char *packet)` or, if the project wants the current descriptive name preserved, `bool LivingObjectPane::ApplyMovementCorrectionPacketRaw(const unsigned char *packet)`.

Best source-facing name ranking:

1. `HandleWarpPacket` - strongest short source-facing name because the current local-player extension page already lists `0x005aaff0` as `HandleWarpPacket`, the body reads only four position words, calls `LivingObjectPane::WarpToPosition`, calls a MapPane no-op hook, clears linked movement records, and returns false.
2. `ApplyMovementCorrectionPacketRaw` - good descriptive alias from prior class-level research; captures the server-authoritative correction behavior and the raw/no-route status, but less likely to be original handwritten name than `HandleWarpPacket`.
3. `LivingObjectPaneRawMovementCorrectionPacketHelper` - acceptable documentation filename only; too verbose for source.
4. `sub_5AAFF0` - reject except as historical/IDA alias.

Recommended implementation wording should say opcode `0x04`, not "unknown packet subtype." The live dispatcher proves this: `UserPane::OnServerMessage` subtracts `4` from `packet[0]`, looks up `packet[0]-4` in byte table `0x005a8324`, and maps opcode `0x04` to jump-table index `0`, target `0x005a7989`. The `0x005a7989-0x005a7a27` inline case performs the same sequence as the standalone `0x005aaff0-0x005ab084` body.

## Supporting Research

### Raw Range And Boundary Facts

Direct PE/Capstone inspection of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirms:

- Previous modeled function returns at `0x005aafe0` with `c2 04 00`; bytes `0x005aafe3-0x005aaff0` are `int3` alignment.
- Target starts at `0x005aaff0` with a normal function prologue: `55 8b ec 51 53 ...`.
- Target returns at `0x005ab081` with `c2 04 00`.
- Bytes `0x005ab084-0x005ab090` are `int3` alignment before the modeled successor at `0x005ab090`.
- There is no internal child split inside `0x005aaff0-0x005ab084`; the range is one small thiscall-style helper plus compiler stack/register shuffling.

The exact target operation is:

```asm
005aaff0  push ebp
005aaff5  mov ebx, [ebp+8]              ; packet pointer
005aaffa  mov [ebp-4], ecx              ; this
005aaffd  lea eax, [ebx+1]
005ab001  call 0x00575480               ; PacketBufferReadUInt16BE(packet+1)
005ab009  mov [ebp+8], eax              ; compiler reuses arg slot for first word
005ab00c  lea eax, [ebx+3]
005ab010  call 0x00575480               ; packet+3
005ab018  lea eax, [ebx+5]
005ab01c  call 0x00575480               ; packet+5
005ab024  lea eax, [ebx+7]
005ab028  call 0x00575480               ; packet+7
005ab047  call 0x005a5a90               ; LivingObjectPane::WarpToPosition
005ab04c  mov ecx, [ebx+0x1340f8]       ; cached MapPane *m_mapPane
005ab052  call 0x00505730               ; MapPane no-op hook
005ab057  xor edx, edx
005ab059  cmp [ebx+0x13eb18], edx       ; m_linkedRecordCount
005ab063  mov ecx, [ebx+0x13eb14]       ; m_linkedRecords
005ab06a  mov byte ptr [eax+ecx], 0     ; record[i].active = false
005ab07b  xor al, al
005ab081  ret 4
```

There is no SEH, vtable write, destructor pattern, scalar-deleting wrapper shape, or compiler-only helper frame here. Compiler-generated artifacts are limited to normal stack/register allocation and reuse of `[ebp+8]` as a local. The source body is handwritten packet handling logic.

### Route / Liveness Recheck

Fresh PE scans checked direct `rel32` calls/jumps, absolute VA pointers, RVA pointers, and raw file-offset pointers.

| Address | Direct calls/jumps | Absolute VA refs | RVA refs | Raw-offset refs | Meaning |
| --- | ---: | ---: | ---: | ---: | --- |
| `0x005aaff0` | 0 | 0 | 0 | 0 | Standalone raw helper has no proven entry route. |
| `0x005ab090` | 1 direct call at `0x005a7a33` | 0 | 0 | 0 | Positive control: modeled movement handler A is live from dispatcher. |
| `0x005ab410` | 1 direct call at `0x005a7a44` | 0 | 0 | 0 | Positive control: modeled movement handler B is live from dispatcher. |
| `0x005a5a90` | 12 direct calls including `0x005a79ea`, `0x005ab047`, `0x005ab133`, `0x005ab29c`, `0x005ab3b9`, `0x005ab4b1`, `0x005ab5ff`, `0x005ab706`, `0x005ac221` | 0 | 0 | 0 | `WarpToPosition` is a live shared helper and is called by both raw and modeled packet paths. |
| `0x005a87e0` | 2 direct calls at `0x005ab2ea` and `0x005ab637` | 0 | 0 | 0 | `ClearAllLinkedRecords` is live in movement handlers. |
| `0x005a8810` | 2 direct calls at `0x005ab2f4` and `0x005ab641` | 0 | 0 | 0 | `ClearLinkedRecordByIndex` is live in movement handlers. |

The no-entry-route result for `0x005aaff0` is not a reason to call it padding or compiler glue, because a live dispatcher case duplicates the same source operation. `UserPane::OnServerMessage` contains:

```asm
005a7727  movzx eax, byte ptr [edi]       ; packet[0]
005a772a  add eax, -4
005a7736  movzx eax, byte ptr [eax+0x5a8324]
005a773d  jmp dword ptr [eax*4+0x5a82c0]
...
005a7989  lea eax, [edi+1]
005a7999  call 0x00575480                 ; packet+1
005a79a5  call 0x00575480                 ; packet+3
005a79b7  call 0x00575480                 ; packet+5
005a79c9  call 0x00575480                 ; packet+7
005a79ea  call 0x005a5a90                 ; WarpToPosition
005a79ef  mov ecx, [ebx+0x1340f8]
005a79f5  call 0x00505730                 ; same no-op hook
005a79fa  cmp [ebx+0x13eb18], edx
005a7a10  mov eax, [ebx+0x13eb14]
005a7a1a  mov byte ptr [ecx+eax-0x10], 0
```

The switch table resolves the subtype:

```text
packet[0] == 0x04 -> jump index 0x00 -> 0x005a7989  inline opcode 0x04 warp/correction case
packet[0] == 0x0b -> jump index 0x04 -> 0x005a7a2c  calls 0x005ab090
packet[0] == 0x26 -> jump index 0x0c -> 0x005a7a3d  calls 0x005ab410
```

This is the strongest source-route result: the standalone body has no live entry, but the source operation is live inside `UserPane::OnServerMessage`. The target should therefore be documented as a retained/out-of-line helper or duplicate source body for opcode `0x04`, not as an unknown-orphan packet parser.

### Packet Layout

`packet` is the payload pointer, matching the `UserPane::OnServerMessage` convention where `[packetContext+0x0c]` is copied into `edi` and passed to packet handlers. For opcode `0x04`, the layout is:

| Payload offset | Read helper | Source-facing field | Signedness / use |
| --- | --- | --- | --- |
| `packet[0]` | direct byte read by dispatcher | server opcode `0x04` | Not read by standalone target because caller has already selected the case. |
| `packet+1` | `PacketBufferReadUInt16BE` / `0x00575480` | first position word, best name `x` or `tileX` | Sign-extended to `int` before `WarpToPosition`. |
| `packet+3` | `PacketBufferReadUInt16BE` / `0x00575480` | second position word, best name `y` or `tileY` | Sign-extended to `int`. |
| `packet+5` | `PacketBufferReadUInt16BE` / `0x00575480` | third position word, best name `screenX` or `pixelX` | Sign-extended to `int`. |
| `packet+7` | `PacketBufferReadUInt16BE` / `0x00575480` | fourth position word, best name `screenY` or `pixelY` | Sign-extended to `int`. |

The `tileX/tileY/screenX/screenY` names are inferred. The first two are definitely the `this+0x100/+0x104` world/tile position pair consumed by `WarpToPosition`; the last two are stored by `WarpToPosition` at `this+0x13ead8/+0x13eadc` and participate in screen/map refresh state. Because the target does not itself label axis order, the target doc should say `x/y` and `screenX/screenY` are best descriptive names pending final LivingObjectPane layout work, not symbol-proven original names.

### Helper And Field Name Resolution

| Raw name/address | Recommended source-facing name | Confidence | Evidence |
| --- | --- | ---: | --- |
| `sub_5AAFF0` | `LivingObjectPane::HandleWarpPacket(const unsigned char *packet)`; alias `ApplyMovementCorrectionPacketRaw` | 0.86 | Opcode `0x04` inline dispatcher duplicate, four position-word reads, call to `WarpToPosition`, linked-record reset. |
| `sub_575480` / `0x00575480` | `PacketBufferReadUInt16BE(const unsigned char *)` | 0.98 | Existing [UID:0003YK] packet-buffer docs name it as the scalar big-endian 16-bit reader; target reads packet+1/+3/+5/+7. |
| `sub_5A5A90` / `0x005a5a90` | `LivingObjectPane::WarpToPosition(int x, int y, int screenX, int screenY)` | 0.88 | Existing target [UID:0003UE] calls it `WarpToPosition`; body validates/reindexes map position, writes current position fields, writes `0x13ead8/0x13eadc`, cancels movement/timer state, and refreshes map placement. |
| `nullsub_12` / `0x00505730` | `MapPane::OnLocalPlayerWarpApplied()` or `MapPane::AfterLocalPlayerWarp()` no-op hook; keep `nullsub_12` as alias | 0.72 | One-byte `ret`, exactly two direct calls: dispatcher inline opcode `0x04` at `0x005a79f5` and standalone target at `0x005ab052`. It is called on cached `MapPane *` immediately after `WarpToPosition`. Exact original name is not proven. |
| `this+0x1340f8` | `m_mapPane` / cached active `MapPane *` | 0.93 | [UID:00024A] `UserPaneGetMapPane` and `UserPane` docs resolve the field from constructor copies of `g_activeMapPane` and MapPane receiver use. Target consumes it as a MapPane receiver for `0x00505730`. |
| `this+0x13eb14` | `m_linkedRecords` | 0.90 | [UID:0003VE] and [UID:0003UF]/[UID:0003UG] resolve the linked-record pointer/count pair; target indexes records by stride `0x10`. |
| `this+0x13eb18` | `m_linkedRecordCount` | 0.90 | Used as loop bound in target and related linked-record helpers. |
| `record+0x00` | `active` / `isActive` byte | 0.88 | `GetActiveLinkedRecordByIndexRaw` returns records only when first byte is nonzero; target clears this byte for every record. |
| `record+0x04` and `record+0x08` | predicted/linked coordinate pair | 0.72 | Movement handlers compare these fields with packet position words before clearing matched records. Axis order should remain descriptive until broader layout is finalized. |
| `record+0x0c` | direction/facing byte | 0.75 | Movement handlers compare it with the signed movement direction byte. |

### Relation To Sibling Packet Handlers

- `0x005ab090-0x005ab410` and `0x005ab410-0x005ab75d` are live modeled movement ack/correction handlers for opcodes `0x0b` and `0x26`. Both parse a direction byte, multiple 16-bit coordinate words, a linked-record index, and then reconcile prediction/history. They call `WarpToPosition`, MapPane helpers, TimerMgr queue removal, `ClearAllLinkedRecords`, and `ClearLinkedRecordByIndex`.
- `0x005aaff0-0x005ab084` is simpler: opcode `0x04` contains no direction byte, no linked-record index, no movement prediction comparison, and no timer scheduling/removal. It applies the authoritative position immediately and clears every linked record's active byte.
- The live opcode `0x04` body in `UserPane::OnServerMessage` is an inline/duplicated form of the target. The target should cross-reference [UID:0003VB] because the route proof comes from that dispatcher, but the target's owner should not change to `UserPane`.
- `0x005abb20` `LivingObjectPaneHandleUserListPacket` is a useful comparison: it is another retained duplicate/no-live-route packet helper. It has a live inline dispatcher implementation for opcode `0x36` and no route to the standalone helper. The same documentation policy should apply here, except this target now has enough evidence to recommend a first-draft helper body if retained duplicate emission is accepted.

## Heuristic / Inference Reanalysis And Validation

### Caller / Reachability

- Existing issue: no caller/xref to `0x005aaff0`.
- Evidence checked: direct `rel32` call/jump scan over `.text`; absolute VA, RVA, and raw file-offset pointer scans over the PE; positive controls for `0x005ab090`, `0x005ab410`, and `0x005a5a90`; dispatcher switch table decode.
- Best inference: standalone target is a retained/out-of-line source helper or duplicate body. The live source behavior is inlined in `UserPane::OnServerMessage` for opcode `0x04`.
- Rejected alternatives:
  - Padding: rejected because the target has a normal prologue/epilogue, valid calls, packet reads, and state mutation.
  - Compiler thunk/glue: rejected because there is no vtable adjust, scalar-delete wrapper, import thunk, SEH frame, or tail jump. The body is semantic packet logic.
  - Missed direct switch-table route to `0x005aaff0`: rejected by decoded `0x005a82c0/0x005a8324` tables. Opcode `0x04` routes to `0x005a7989`, not `0x005aaff0`.
  - Entirely dead unrelated code: weaker than retained source duplicate because the dispatcher contains the same operation sequence and the target sits in the LivingObjectPane packet-handler tail.

### Packet Subtype And Layout

- Existing issue: original packet subtype unknown.
- Evidence checked: `UserPane::OnServerMessage` packet switch at `0x005a7727-0x005a773d`, jump table `0x005a82c0`, byte translation table `0x005a8324`, and direct movement-handler calls at `0x005a7a33`/`0x005a7a44`.
- Best inference: opcode `0x04`; payload contains four consecutive big-endian 16-bit signed position/screen words at offsets `+1/+3/+5/+7`.
- Rejected alternatives:
  - Opcode `0x0b` or `0x26`: those are the modeled movement handlers A/B, not this helper.
  - Unknown position-sync opcode: rejected because the table gives opcode `0x04`.
  - Directional movement packet: rejected because there is no direction byte or linked-record index in this helper.

### Field / Type Names

- Existing issue: `this+0x13eb14/+0x13eb18` and record fields were only loosely described.
- Evidence checked: target loop; [UID:0003VE] `GetActiveLinkedRecordByIndexRaw`; [UID:0003UF] `ClearAllLinkedRecords`; [UID:0003UG] `ClearLinkedRecordByIndex`; movement handlers A/B.
- Best inference: `m_linkedRecords` pointer, `m_linkedRecordCount` count, `LinkedRecord::active` first byte, stride `0x10`.
- Rejected alternatives:
  - Movement buffer pointer/count: rejected because `0x005a9310` and [UID:0003US] establish deferred packet buffer at `+0x13eb20/+0x13eb24`, not `+0x13eb14/+0x13eb18`.
  - Timer queue fields: rejected because TimerMgr state is at other offsets and uses TimerHandler `this+0xa4`.
  - Object-list or MapPane-owned record array: rejected because all accesses are through `LivingObjectPane` local-player state and related LivingObjectPane helpers.

### Source Placement

Ranked source placement:

1. [UID:00007B] `LivingObjectPane` / `NexusTK/map/LivingObjectPane.cpp` - accepted. The target receiver is the LivingObjectPane/local-player subobject, calls `LivingObjectPane::WarpToPosition`, mutates LivingObjectPane linked-record state, and belongs to the local-player packet tail.
2. [UID:0000FQ] `UserPane` / `NexusTK/ui/panels/UserPane.cpp` - rejected as canonical owner. `UserPane::OnServerMessage` owns the live dispatch case and should document the inline duplicate, but the standalone helper's receiver and state are LivingObjectPane. `UserPane` is a routing surface, not the helper owner.
3. [UID:0000L3] `MapPane` / `NexusTK/map/MapPane.cpp` - rejected. The only MapPane involvement is the cached `m_mapPane` no-op callback at `0x00505730`; no MapPane fields are owned by the target.
4. No-owner/non-emitting - rejected. The target is reconstructable source-authored code with strong owner/emitter context; no-route should be documented as retained duplicate, not no-owner.
5. Mixed aggregate split - rejected. `0x005aaff0-0x005ab084` is already a clean child. The only adjacent split need is the already-ignored `0x005ab084-0x005ab090` padding.

### Final C++ Readiness

This target is eligible for first-draft C++ under the current gate:

- `RECONSTRUCTABLE:TRUE`.
- Nonblank emitter [UID:00007B].
- Combined recommended score `(87+89)/2 = 88`.
- Exact range covers one source function.
- Packet subtype, payload offsets, callee roles, and field names are resolved or have defensible descriptive names.

The previous blank-C++ blocker "no start xrefs" is no longer enough by itself. The live dispatcher duplicate proves the source operation and gives the opcode. The only remaining naming uncertainty is the original spelling of `0x00505730`; a descriptive no-op hook name is safe enough for draft C++ and should be recorded as inferred.

If the project has a policy against emitting retained no-route helper bodies, the target should keep formal C++ blank with this exact no-code/defer proof: "The standalone `0x005aaff0` body has zero rel32/VA/RVA/raw-offset entry routes, and the live opcode `0x04` source operation is already present inline in `UserPane::OnServerMessage` at `0x005a7989-0x005a7a27`; formal source emission is deferred to avoid duplicating a retained out-of-line copy until retained-dead-source policy is settled." I do not recommend this as the default because current supervisor code-entry policy expects C++ for eligible emitting targets unless a stronger target-specific safety blocker exists.

## First-Draft C++ Recommendation

Use this as the target formal block if the supervisor accepts code emission:

```cpp
bool LivingObjectPane::HandleWarpPacket(const unsigned char *packet)
{
    const int x = static_cast<short>(PacketBufferReadUInt16BE(packet + 1));
    const int y = static_cast<short>(PacketBufferReadUInt16BE(packet + 3));
    const int screenX = static_cast<short>(PacketBufferReadUInt16BE(packet + 5));
    const int screenY = static_cast<short>(PacketBufferReadUInt16BE(packet + 7));

    WarpToPosition(x, y, screenX, screenY);
    m_mapPane->OnLocalPlayerWarpApplied();

    for (int i = 0; i < m_linkedRecordCount; ++i)
        m_linkedRecords[i].active = false;

    return false;
}
```

Implementation notes for this block:

- If support docs settle on `ApplyMovementCorrectionPacketRaw` instead of `HandleWarpPacket`, use that method name but keep `HandleWarpPacket` as a source-facing alias/history note.
- `PacketBufferReadUInt16BE` is the established source-facing name for `0x00575480`.
- `WarpToPosition` is the established source-facing name for `0x005a5a90`; signature should accept four `int` arguments produced from signed 16-bit packet words.
- `OnLocalPlayerWarpApplied` is a descriptive inferred name for the direct no-op `MapPane` member at `0x00505730`. If the MapPane docs already choose a different no-op callback name, use that name and record `OnLocalPlayerWarpApplied` as a B002 alias.
- Do not add a null check around `m_mapPane`; the binary unconditionally loads and calls through the cached pointer.
- Do not call `ClearAllLinkedRecords()` in the first draft unless support docs choose to represent the compiler's inline loop that way. The target body implements the loop inline; using the loop is more faithful to the covered range.

## Recommended Target Doc Changes

Update `source-3/project-documentation/by-memory/0x005aaff0-0x005ab084.LivingObjectPaneRawMovementCorrectionPacketHelper.md`:

1. Change metadata to `COMPLETION:87`, `CONFIDENCE:89`; keep owner/emitter/reconstructable unchanged.
2. Replace "original packet subtype unresolved" with opcode `0x04`, resolved from `UserPane::OnServerMessage` switch table `0x005a82c0/0x005a8324`.
3. Replace generic parser summary with exact payload layout:
   - `packet+1`: signed big-endian 16-bit `x` / `tileX`.
   - `packet+3`: signed big-endian 16-bit `y` / `tileY`.
   - `packet+5`: signed big-endian 16-bit `screenX` / `pixelX`.
   - `packet+7`: signed big-endian 16-bit `screenY` / `pixelY`.
4. Name `0x00575480` as `PacketBufferReadUInt16BE`.
5. Name `0x005a5a90` as `LivingObjectPane::WarpToPosition(int x, int y, int screenX, int screenY)` with note that exact axis/field names remain descriptive.
6. Name `0x00505730` as a `MapPane` no-op hook, recommended alias `MapPane::OnLocalPlayerWarpApplied()` / `AfterLocalPlayerWarp`, and preserve `nullsub_12` as raw alias.
7. Map `this+0x1340f8` to cached `MapPane *m_mapPane`.
8. Map `this+0x13eb14` to `m_linkedRecords`, `this+0x13eb18` to `m_linkedRecordCount`, record stride `0x10`, record byte `+0x00` to `active`.
9. Add route/liveness section:
   - Fresh direct rel32/VA/RVA/raw-offset scans found zero entry routes to `0x005aaff0`.
   - Positive controls found dispatcher calls to `0x005ab090` and `0x005ab410`.
   - `UserPane::OnServerMessage` live inline opcode `0x04` case at `0x005a7989-0x005a7a27` duplicates the target's operation.
10. Add rejected alternatives:
    - Not padding because normal prologue/return and semantic calls.
    - Not compiler glue because no thunk/delete/SEH/vtable shape.
    - Not `UserPane`-owned despite dispatcher duplicate.
    - Not `MapPane`-owned despite no-op MapPane callback.
    - Not no-owner/non-emitting because owner/emitter and source body are strong.
11. Add first-draft C++ block above, or if supervisor chooses no-code policy for retained duplicates, add the exact no-code/defer proof from the previous section instead of leaving generic blockers.

## Recommended Support Doc Changes

### `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`

Add a detailed opcode `0x04` case note:

- `packet[0] == 0x04` routes to inline case `0x005a7989-0x005a7a27`, not to `0x005aaff0`.
- The inline case reads four signed big-endian 16-bit words from payload offsets `+1/+3/+5/+7`, calls `LivingObjectPane::WarpToPosition`, invokes MapPane no-op hook `0x00505730`, clears every linked-record active byte, and falls through to the common false/handled return path.
- Cross-reference [UID:0003UO] as the retained/out-of-line duplicate helper.
- Existing listed movement packet handlers for `0x005ab090` and `0x005ab410` should be amended with opcode mappings `0x0b` and `0x26` from the switch table.

### `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`

Update the row for `0x005aaff0`:

- Replace "HandleWarpPacket / no IDA function" caveat with "opcode `0x04` `HandleWarpPacket` retained raw helper; no entry route, live inline duplicate in `UserPane::OnServerMessage` at `0x005a7989-0x005a7a27`."
- Keep `0x005ab084-0x005ab090` as ignored alignment padding.
- Keep `0x005ab090` and `0x005ab410` as separate modeled movement ack/correction handlers with opcodes `0x0b` and `0x26`.

### `by-class/LivingObjectPane.md`

Add/refresh local-player packet family detail:

- `HandleWarpPacket` / `ApplyMovementCorrectionPacketRaw` for opcode `0x04` applies four signed 16-bit server position words through `WarpToPosition`, calls a MapPane no-op hook, and clears linked-record activity state.
- Field table or local-player notes should mention `m_linkedRecords` / `m_linkedRecordCount` and record active byte `+0x00` are used by opcode `0x04` and by the linked-record helpers.
- Preserve the no-route caveat as retained/out-of-line helper evidence, not as ownership uncertainty.

### `by-file/LivingObjectPane.md`

Update source-file routing:

- Include `0x005aaff0-0x005ab084` in the player movement/server packet section as opcode `0x04` retained helper, emitted through `NexusTK/map/LivingObjectPane.cpp` if retained duplicate emission is accepted.
- Do not move this to `UserPane.cpp`; `UserPane` owns the dispatcher case only.
- Add the support relationship to the MapPane no-op hook `0x00505730` and `PacketBufferReadUInt16BE`.

### `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`

Refresh caller/source-quality detail:

- It is called by the live `UserPane::OnServerMessage` opcode `0x04` inline case at `0x005a79ea`, by the raw retained helper at `0x005ab047`, by movement handlers A/B, and by raw position-sync helpers.
- Signature recommendation: `void __thiscall LivingObjectPane::WarpToPosition(int x, int y, int screenX, int screenY)`.
- `0x005aaff0` no longer has unknown packet layout; it passes four signed packet words.

### `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`

Update the `0x00505730` no-op callback entry:

- Exact direct callsites found in this pass: `0x005a79f5` and `0x005ab052`, both after opcode `0x04` server-warp/correction logic.
- Recommended descriptive alias: `MapPane::OnLocalPlayerWarpApplied()` or `MapPane::AfterLocalPlayerWarp()`.
- Keep the exact original name open; do not leave it as a bare `nullsub_12` in LivingObjectPane target text.

### `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`

Field layout already includes `m_linkedRecords` and `m_linkedRecordCount`; add detail:

- `0x005aaff0` clears `record[i].active` at record offset `+0x00` for every record after server opcode `0x04` warp/correction.
- Movement handlers compare record `+0x04/+0x08` against packet coordinates and record `+0x0c` against direction, supporting a provisional `LinkedRecord` layout with active byte, coordinate pair, and facing/direction byte.

### `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`

Add cross-reference:

- The opcode `0x04` retained helper and its live dispatcher duplicate clear the same first-byte active flag that this helper tests.

### `by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md` and `0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`

Add cross-reference:

- `0x005aaff0` contains an inline clear-all loop rather than a direct call to `0x005a87e0`; modeled movement handlers use both `ClearAllLinkedRecords` and `ClearLinkedRecordByIndex` after more complex prediction reconciliation.

## Exact Supervisor-Owned Coverage Row

`by-memory/-coverage-report.md` currently has no direct row for [UID:0003UO] in the manual coverage section found around the [UID:0001KM] local-player extension children. Do not edit the file during this B-report pass. Supervisor should insert this row under the [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions` child list, preferably near adjacent `0003UP`/`0003UQ` if those rows are added, or after the parent/local-player rows before the later `0003US` retained user-list row if only this pending row is applied:

```text
        - [UID:0003UO][0x005aaff0-0x005ab084.LivingObjectPaneRawMovementCorrectionPacketHelper](by-memory/0x005aaff0-0x005ab084.LivingObjectPaneRawMovementCorrectionPacketHelper.md) 0x005aaff0-0x005ab084 | retained duplicate/raw opcode 0x04 warp helper | LivingObjectPaneRawMovementCorrectionPacketHelper : reconstructable : 89% : very strong : Raw no-entry-route LivingObjectPane helper for server packet opcode 0x04. It reads signed big-endian 16-bit values from payload+1/+3/+5/+7 through PacketBufferReadUInt16BE, calls LivingObjectPane::WarpToPosition(x, y, screenX, screenY), calls the MapPane no-op hook at 0x00505730 through cached m_mapPane, clears the active byte for each 0x10-byte linked record at m_linkedRecords/m_linkedRecordCount, and returns false. Fresh PE scans found no rel32/VA/RVA/raw-offset route to 0x005aaff0, while UserPane::OnServerMessage has a live switch case for opcode 0x04 at 0x005a7989-0x005a7a27 with the same operation sequence; treat the standalone body as retained/out-of-line duplicate source under LivingObjectPane, not UserPane-owned dispatcher source or compiler glue. Formal C++ is ready if the project accepts retained duplicate emission; otherwise preserve the no-route caveat with the first-draft body in notes.
```

## Exact Implementation Checklist For Supervisor Callback

1. Update target `source-3/project-documentation/by-memory/0x005aaff0-0x005ab084.LivingObjectPaneRawMovementCorrectionPacketHelper.md`:
   - `COMPLETION:87`
   - `CONFIDENCE:89`
   - Keep owner/emitter/reconstructable unchanged.
   - Add full route/liveness findings, opcode `0x04`, packet layout, helper names, field names, rejected alternatives, and source-placement reasoning from this report.
   - Populate the first-draft C++ block unless supervisor explicitly decides retained duplicate no-code policy applies. If no-code policy applies, insert the exact no-code/defer proof above and do not leave the generic old blank-C++ blocker.
2. Update support docs at report-level detail:
   - `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`
   - `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
   - `by-class/LivingObjectPane.md`
   - `by-file/LivingObjectPane.md`
   - `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`
   - `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
   - `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`
   - `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`
   - `by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md`
   - `by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`
3. Do not edit `by-memory/-coverage-report.md`; supervisor applies the exact row above.
4. If formal C++ is added, run autogen after scoped file validators so `auto-generated/NexusTK/map/LivingObjectPane.cpp` refreshes from the target block.

## Validation Commands Expected After Implementation

Run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality-removed.md](0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No scoped validator was run in this report-only pass because no by-* files were edited.

## IDA Rename / Type / Comment Recommendations

- `0x005aaff0`: rename to `LivingObjectPane_HandleWarpPacket` or `LivingObjectPane_ApplyMovementCorrectionPacketRaw`. Type: `bool __thiscall LivingObjectPane::HandleWarpPacket(const unsigned char *packet)`.
- `0x005a7989`: add comment "inline UserPane::OnServerMessage opcode 0x04 body; same source operation as retained helper 0x005aaff0."
- `0x00575480`: keep/name as `PacketBufferReadUInt16BE`.
- `0x005a5a90`: keep/name as `LivingObjectPane::WarpToPosition`. Type: `void __thiscall LivingObjectPane::WarpToPosition(int x, int y, int screenX, int screenY)`.
- `0x00505730`: rename/comment as `MapPane::OnLocalPlayerWarpApplied` or `MapPaneOpcode04WarpNoOp`; type `void __thiscall MapPane::OnLocalPlayerWarpApplied()`. Keep `nullsub_12` as raw alias because exact original name is not proven.
- `LivingObjectPane + 0x1340f8`: `MapPane *m_mapPane`.
- `LivingObjectPane + 0x13eb14`: `LinkedRecord *m_linkedRecords`.
- `LivingObjectPane + 0x13eb18`: `int m_linkedRecordCount`.
- `LinkedRecord + 0x00`: `bool active` or `unsigned char active`.
- `LinkedRecord + 0x04/+0x08`: provisional coordinate pair; do not lock final axis order without a broader record-layout pass.
- `LinkedRecord + 0x0c`: provisional `facing` / `direction`.

## Evidence Checked

Documentation read:

- Target `by-memory/0x005aaff0-0x005ab084.LivingObjectPaneRawMovementCorrectionPacketHelper.md`.
- `by-class/LivingObjectPane.md`, `by-file/LivingObjectPane.md`.
- `by-class/UserPane.md`, `by-file/UserPane.md`.
- `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`.
- `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`.
- `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`.
- `by-memory/0x005ab090-0x005ab410.LivingObjectPaneHandleMovementPacketA.md`.
- `by-memory/0x005ab410-0x005ab75d.LivingObjectPaneHandleMovementPacketB.md`.
- `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`.
- `by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md`.
- `by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`.
- `by-memory/0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md`.
- `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`.
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`.
- Existing B001 research leads for `LivingObjectPane` class and `0001KM` split audit were treated as leads and rechecked against PE bytes, not copied as final authority.

Binary checks run:

- Capstone disassembly over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for `0x005aaff0-0x005ab090`, previous padding, successor `0x005ab090`, callee `0x005a5a90`, dispatcher `0x005a76c0-0x005a82bd`, movement handler A/B excerpts, and MapPane helpers `0x00505730`, `0x00505740`, `0x005055d0`, `0x00505080`.
- Direct `rel32` call/jump scans and VA/RVA/raw-offset scans for `0x005aaff0`, `0x005ab090`, `0x005ab410`, `0x005a5a90`, `0x005a87b0`, `0x005a87e0`, `0x005a8810`, `0x005a9310`, and `0x005aac80`.
- Dispatcher jump table decode at `0x005a82c0` and opcode translation table decode at `0x005a8324`.
- Direct call scan for `0x00505730` found exactly two callsites, both opcode `0x04` warp/correction paths.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality.md`
- Modified: none outside Agent-B002 research folder.
- `by-memory/-coverage-report.md`: not edited; exact supervisor-owned row provided above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"0003UO"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003UO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
