** TARGET-REPORT-UID:0003UV **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B010 Source-Quality Report: [UID:0003UV] LivingObjectPaneRawPositionSyncPacketHelper

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality.md`  
Target path: `source-3/project-documentation/by-memory/0x005ac1b0-0x005ac27c.LivingObjectPaneRawPositionSyncPacketHelper.md`  
Target UID: `0003UV`  
Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, formal C++ blank.  
Assignment type: report-only B-agent Rule 26 source-quality pass. No by-* docs or `by-memory/-coverage-report.md` were edited.

## Executive Recommendation

Keep [UID:0003UV] owned/emitted through [UID:00007B] `LivingObjectPane`, but document it as a retained raw no-entry packet helper rather than a normally called source method. Raise metadata to `COMPLETION:87`, `CONFIDENCE:88`, keep `RECONSTRUCTABLE:TRUE`, keep `CANONICAL_OWNER:00007B`, keep `EMITTER_UIDS:00007B`, and keep the formal `RECONSTRUCTION_CPP` block blank until a real caller/table route or an explicit retained-dead-helper emission policy is approved.

Best source-facing descriptive name: `LivingObjectPane::HandlePositionSyncPacketRaw` or `LivingObjectPane::HandleServerPositionSyncPacketRaw`. This is a descriptive reverse-engineering name, not a proven original symbol.

Behavior is now source-quality enough for prose and a reference draft: the raw body reads a reserved/status byte at `packet[1]`, reads four big-endian 16-bit fields at `packet+2/+4/+6/+8`, gates the state-changing body on `m_isMoving == false`, calls `LivingObjectPane::WarpToPosition(targetX, targetY, viewportX, viewportY)`, calls `MapPane::RecenterAndSendPosition(targetX, targetY, viewportX, viewportY, false)` through `this+0x1340f8`, calls the MapPane object-coordinate update helper, calls `LivingObjectPane::RefreshAllLinkedObjects()`, removes map-pane timer events through `g_pTimerMgr` for `m_mapPane + 0xa4`, and returns `true`.

The remaining material blocker is not behavior. It is liveness/source-shape: fresh PE scans found no direct rel32 branch/call/conditional edge, no absolute VA pointer, and no target-RVA pointer to `0x005ac1b0`, and existing UserPane switch-table docs do not route an opcode case to this helper. Emitting a normal final method body now would invent a call surface that the binary has not proven.

## Evidence Checked

- Target doc [UID:0003UV] `by-memory/0x005ac1b0-0x005ac27c.LivingObjectPaneRawPositionSyncPacketHelper.md`.
- Owner/support docs:
  - [UID:00007B] `by-class/LivingObjectPane.md`
  - [UID:0000KU] `by-file/LivingObjectPane.md`
  - [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
  - [UID:0003UE] `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`
  - [UID:0003UU] `by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md`
  - [UID:0003UW] `by-memory/0x005ac280-0x005ac69b.LivingObjectPaneParseLinkedObjectsPacket.md`
  - [UID:0003VB] `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`
  - [UID:0003VC] `by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md`
  - [UID:0002QM] `by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md`
  - [UID:00024A] `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`
  - [UID:0003Z7] `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md`
  - [UID:0001DE] `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`
  - [UID:0003YK] `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md`
  - [UID:0000M8] `by-file/PacketBuffer.md`
  - [UID:0000SI] `by-global/g_pTimerMgr.md`
  - [UID:0000F1] `by-class/TimerMgr.md`
- Generated/state docs:
  - `project-level/-auto-completion-stats.md` row confirms current `0003UV` is `85/86`.
  - `auto-generated/-ag-memory-coverage.md` row confirms current generated status is `emits`, owner/emitter `00007B`, output `auto-generated/NexusTK/map/LivingObjectPane.cpp`, and empty emitter marker.
  - `by-memory/-coverage-report.md` was searched for `0003UV`, `0x005ac1b0`, `0x005ac27c`, `0x005ac070`, and `0x005ac280`; no current matching row/context was found in that shared report.
- Prior B001 research was used only as a lead:
  - `Agent-B001/research/00007B-LivingObjectPane-class-source-quality.md`
  - `Agent-B001/research/executed/older/0001KM-livingobject-localplayer-source-split-audit.md`
  - `Agent-B001/research/executed/00024A-UserPaneVirtualDword1340F8Accessor-source-quality.md`
- IDA MCP availability check: the direct endpoint request failed with `Unable to connect to the remote server`, so live IDA MCP could not be used in this resumed run. The removed literal PowerShell command is preserved only in the linked inert archive.
- Direct executable evidence: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` was parsed with a PE-aware local Python/Capstone script. Capstone is available (`capstone` import succeeded). The script parsed image base `0x400000`, `.text` VA `0x401000`, and disassembled/scanned the relevant ranges.

## Byte Boundary And Body Facts

The target range is exactly `0x005ac1b0-0x005ac27c`, with `0x005ac27c-0x005ac280` alignment padding.

Boundary bytes:

- `0x005ac1a8-0x005ac1b0`: eight `0xcc` bytes after the message-show packet handler tail.
- `0x005ac1b0`: function-shaped prologue `55 8b ec 83 ec 08 53 56 ...`.
- `0x005ac279`: `ret 4`, matching `__thiscall` with one explicit argument.
- `0x005ac27c-0x005ac280`: four `0xcc` bytes.
- `0x005ac280`: next modeled linked-object parser prologue `55 8b ec 81 ec 9c 00 00 00 ...`.

Key disassembly:

```asm
005ac1b0  push ebp
005ac1b1  mov  ebp, esp
005ac1b3  sub  esp, 8
005ac1b8  mov  esi, [ebp+8]            ; packet pointer
005ac1bb  mov  ebx, ecx                ; LivingObjectPane/UserPane-local object view
005ac1c1  lea  eax, [esi+1]
005ac1c5  call 0x00575470              ; std::_Narrow_char_traits<char,int>::to_char_type(packet+1), result unused
005ac1ca  lea  eax, [esi+2]
005ac1ce  call 0x00575480              ; PacketBufferReadUInt16BE(packet+2)
005ac1d6  mov  [ebp+8], eax            ; targetX
005ac1d9  lea  eax, [esi+4]
005ac1dd  call 0x00575480              ; targetY
005ac1e5  mov  [ebp-8], eax
005ac1e8  lea  eax, [esi+6]
005ac1ec  call 0x00575480              ; viewportX
005ac1f1  movzx edi, ax
005ac1f4  lea  eax, [esi+8]
005ac1f8  call 0x00575480              ; viewportY
005ac203  cmp  byte ptr [ebx+0x1c4], 0 ; m_isMoving
005ac20a  jne  0x005ac271              ; if moving, skip state reconciliation and return true
005ac221  call 0x005a5a90              ; LivingObjectPane::WarpToPosition(targetX,targetY,viewportX,viewportY)
005ac235  mov  ecx, [ebx+0x1340f8]     ; m_mapPane
005ac23b  call 0x005059d0              ; MapPane::RecenterAndSendPosition(..., false)
005ac240  mov  ecx, [ebx+0x1340f8]
005ac247  call 0x00506980              ; MapPane object/coordinate update helper
005ac24e  call 0x0053c1d0              ; LivingObjectPane::RefreshAllLinkedObjects()
005ac253  mov  ecx, [ebx+0x1340f8]
005ac259  lea  eax, [ecx+0xa4]
005ac25f  neg  ecx
005ac261  sbb  ecx, ecx
005ac263  and  ecx, eax                ; NULL-safe timer-owner pointer: m_mapPane ? &m_mapPane->timerHandler : NULL
005ac266  mov  ecx, [0x0067ab80]       ; g_pTimerMgr
005ac26c  call 0x00597a10              ; TimerMgr remove timers for owner/handler
005ac273  mov  al, 1
005ac279  ret  4
```

The helper is not padding, not a compiler thunk, and not a runtime helper. It is a coherent source-shaped packet body with normal prologue/epilogue, local stack storage, packet reads, state guard, and calls into documented project classes.

## Fresh Route / Liveness Scan

The resumed run performed a section-aware `.text` scan over `NexusTK.exe` for direct rel32 `call`/`jmp`/conditional-branch destinations and whole-file scans for absolute VA and target-RVA pointer bytes.

Results for the target entry and nearby interior candidates:

| Target | Direct rel32 hits | Absolute VA/RVA hits | Interpretation |
| --- | ---: | ---: | --- |
| `0x005ac1b0` | `0` | `0` | No proven entry route. |
| `0x005ac1b4` | `0` | `0` | No branch into post-prologue bytes. |
| `0x005ac1bb` | `0` | `0` | No branch into `ecx`/receiver setup. |
| `0x005ac27c` | `0` | `0` | Padding is not a target. |

The same scan found expected positive controls:

| Callee | Direct rel32 hits found | Relevant hits |
| --- | ---: | --- |
| `0x005a5a90` | `12` | Includes `0x005ac221` from this helper plus modeled UserPane/movement correction paths. |
| `0x005059d0` | `9` | Includes `0x005ac23b`; this is the unmodeled code-reference call already reflected in the MapPane recenter doc. |
| `0x005ac280` | `1` | `0x005a8002` from `UserPane::HandleServerMessage` to the modeled linked-object parser. |
| `0x005ac070` | `1` | `0x005a8172` from `UserPane::HandleServerMessage` to message-show packet handler. |
| `0x005abda0` | `1` | `0x005a7ddc` from `UserPane::HandleServerMessage` to UI-panel packet handler. |
| `0x005ab090` | `1` | `0x005a7a33` from `UserPane::HandleServerMessage` to movement packet A. |
| `0x005ab410` | `1` | `0x005a7a44` from `UserPane::HandleServerMessage` to movement packet B. |

Existing dispatcher docs reinforce the negative route:

- [UID:0003VB] `UserPane::HandleServerMessage` lists direct delegates for `0x005aa480`, `0x005aa710`, `0x005aac80`, `0x005ab090`, `0x005ab410`, `0x005ab860`, `0x005abda0`, `0x005ac070`, and `0x005ac280`, but not `0x005ac1b0`.
- [UID:0003VC] switch-table entries all target back inside [UID:0003VB], and the documented switch-table route does not target standalone raw helpers.
- [UID:0002QM] `MapPane::RecenterAndSendPosition` already records `0x005ac23b` as an unmodeled code-reference call site, which proves the raw helper body contains a real call to MapPane code but does not prove how execution reaches the raw helper start.

Conclusion: [UID:0003UV] has a real source-shaped packet body but no proven live route in the current binary. Treat it like other retained raw LivingObjectPane packet helpers: document behavior and source placement, but do not emit a normal formal C++ method body yet.

## Packet Layout / Protocol Inference

Best descriptive role: inbound server position-sync / server-authoritative local-player position update packet body.

The exact dispatcher opcode is not proven because no caller/switch-table route reaches `0x005ac1b0`. The helper itself does not read `packet[0]`; that byte is presumably consumed by a dispatcher if the body was ever called. Do not assign a final opcode number from this page alone.

The body parses this payload layout:

| Payload offset | Read mechanism | Best field name | Notes |
| ---: | --- | --- | --- |
| `0` | not read in this helper | dispatcher opcode | No route found; exact opcode unresolved. |
| `1` | `0x00575470` `std::_Narrow_char_traits<char,int>::to_char_type` | reserved/status/subtype byte | Return value is unused. Treat as a consumed/discarded reserved or status byte; do not give it a behavioral name yet. |
| `2..3` | `0x00575480` `PacketBufferReadUInt16BE` | `targetX` | Passed as first argument to `WarpToPosition` and `MapPane::RecenterAndSendPosition`. |
| `4..5` | `0x00575480` `PacketBufferReadUInt16BE` | `targetY` | Passed as second coordinate. |
| `6..7` | `0x00575480` `PacketBufferReadUInt16BE` | `viewportX` / `viewportOffsetX` | Passed as third coordinate to both position helpers. |
| `8..9` | `0x00575480` `PacketBufferReadUInt16BE` | `viewportY` / `viewportOffsetY` | Passed as fourth coordinate to both position helpers. |

Argument-order evidence:

- `0x005a5a90` `WarpToPosition` reads `[ebp+8]` as target X and `[ebp+0xc]` as target Y, then passes all four args to the MapPane coordinate validator `0x00505230`.
- `0x005a5a90` stores the third and fourth args to `LivingObjectPane +0x13ead8/+0x13eadc`, the viewport-position pair used by [UID:0002RW] `LivingObjectPaneGetViewportPosition`.
- [UID:0002QM] documents `MapPane::RecenterAndSendPosition(int targetX, int targetY, int viewportX, int viewportY, bool useActiveObjectViewport)`.
- [UID:0003UV] pushes the fields in right-to-left order: `false`, field `+8`, field `+6`, field `+4`, field `+2`, with `ecx = this->m_mapPane`, matching `RecenterAndSendPosition(targetX, targetY, viewportX, viewportY, false)`.

Field-name caveat: the exact internal ordering of the `+0x13ead8/+0x13eadc` viewport-pair fields is still provisional in [UID:0002RW]. This report recommends using `viewportX`/`viewportY` or `viewportOffsetX`/`viewportOffsetY` as descriptive source-facing names, with a note that original struct/member names are not recovered.

## Field / Global / Helper Names

Resolved or best descriptive names:

| Binary item | Recommended name | Confidence | Evidence |
| --- | --- | --- | --- |
| `this+0x1c4` | `m_isMoving` / `m_movementActive` | High | [UID:0001DE] and [UID:0003Z7] document `SetMovingState`, `SetMapPosition`, and movement paths using `+0x1c4` as the movement-active byte. This helper only applies the correction when it is zero. |
| `this+0x1340f8` | `m_mapPane` | High | [UID:00024A] proves `UserPane +0x1340f8` is a cached `MapPane *` copied from `g_activeMapPane`; local-player LivingObjectPane/UserPane aggregate methods use the adjusted object as receiver. |
| `m_mapPane+0xa4` | MapPane embedded timer-handler facet | Medium-high | This helper passes `m_mapPane ? m_mapPane +0xa4 : NULL` to TimerMgr removal. Existing timer docs use embedded `TimerHandler` subobjects at `+0xa4` in pane/object classes. Exact MapPane field name is not finalized. |
| `0x00575470` | `std::_Narrow_char_traits<char,int>::to_char_type` / byte adapter | High | [UID:0000M8] and PacketBuffer docs classify this as Dinkumware/MSVC runtime, not PacketBuffer source. |
| `0x00575480` | `PacketBufferReadUInt16BE` | Very high | [UID:0003YK] documents 372 refs and big-endian 16-bit decode. |
| `0x005a5a90` | `LivingObjectPane::WarpToPosition` | High | [UID:0003UE] plus disassembly show target position update, timer cancellation, effect clear, and MapPane update. Signature direction: `void WarpToPosition(int targetX, int targetY, int viewportX, int viewportY)`. |
| `0x005059d0` | `MapPane::RecenterAndSendPosition` | Very high | [UID:0002QM] has first-draft C++ and exact signature direction. |
| `0x00506980` | `MapPane::UpdateObjectPosition` / object-coordinate update helper | Medium-high | MapPane support docs describe it as object lookup/update and coordinate refresh helper. Exact final method name remains descriptive, but MapPane ownership is strong. |
| `0x0053c1d0` | `LivingObjectPane::RefreshAllLinkedObjects` | High | [UID:0003Z7] provides C++ and caller scan, including `0x005ac24e`. |
| `0x0067ab80` | `g_pTimerMgr` | Very high | [UID:0000SI] exact TimerMgr singleton global. |
| `0x00597a10` | `TimerMgr::RemoveTimersForOwner` / timer removal by owner | Medium-high | TimerMgr docs classify `0x00597a10-0x00597db9` as remove-by-owner/event helpers. This call has one pushed owner/handler pointer, so descriptive `RemoveTimersForOwner(TimerHandler *)` is the safest source-facing role. |

## Ownership / Source Placement Ranking

1. Accepted: [UID:00007B] `LivingObjectPane` / [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`.
   - Evidence: `ecx` is a LivingObjectPane/local-player receiver; the body reads `m_isMoving`, calls `WarpToPosition`, calls `RefreshAllLinkedObjects`, and belongs to the same local-player server-packet tail as [UID:0003UO]-[UID:0003UW].
   - Current owner/emitter `00007B` is acceptable and should remain unchanged.
   - File route remains `LivingObjectPane.cpp` through the class, not a UserPane file-level method, because this body mutates actor position and linked-object state.

2. Rejected: [UID:0000FQ] `UserPane`.
   - Reason: the local-player object lives inside/adjacent to UserPane and uses `UserPane +0x1340f8` as `m_mapPane`, but this body is not a UserPane virtual or UI-surface method.
   - `UserPane::HandleServerMessage` does not call `0x005ac1b0`, and its switch-table child does not route to this raw start.

3. Rejected: [UID:00007Q] `MapPane`.
   - Reason: MapPane is a callee/dependency. `m_mapPane` receives recenter and object-coordinate update calls, but the owning state gate and `WarpToPosition`/linked-object refresh remain LivingObjectPane behavior.

4. Rejected: [UID:0000M8] `PacketBuffer`.
   - Reason: packet read helpers are generic utilities. They do not own feature packet bodies.

5. Rejected: [UID:0000SI]/[UID:0000F1] TimerMgr.
   - Reason: TimerMgr is a cleanup callee only.

6. Rejected: merge into [UID:0003UU] message-show packet or [UID:0003UW] linked-object parser.
   - Reason: clean `0xcc` padding separates `0x005ac1b0` from both neighbors, and the body has its own prologue/epilogue and distinct movement/position behavior.

7. Rejected: compiler thunk/destructor/runtime helper.
   - Reason: full packet-body logic, calls, and state mutation contradict thunk/runtime classification.

## First-Draft C++ Recommendation

Do not populate the target formal `RECONSTRUCTION_CPP` block yet. The target meets the numeric combined-score/emitter gate, but a specific source-shape blocker remains: no caller, vtable, switch-table, absolute pointer, target-RVA pointer, direct rel32 route, or known dispatcher case reaches `0x005ac1b0`.

Use this non-final reference draft in the target prose, not in the formal block, until route evidence changes:

```cpp
// Reference only. Do not emit as final formal C++ until a caller/table route or
// retained-raw-helper source policy is approved for this no-entry body.
bool LivingObjectPane::HandlePositionSyncPacketRaw(const unsigned char *packet)
{
    // The binary reads packet[1] through the narrow char-traits adapter and
    // discards the return value. Treat it as a reserved/status byte for now.
    (void)std::char_traits<char>::to_char_type(packet[1]);

    int targetX = PacketBufferReadUInt16BE(packet + 2);
    int targetY = PacketBufferReadUInt16BE(packet + 4);
    int viewportX = PacketBufferReadUInt16BE(packet + 6);
    int viewportY = PacketBufferReadUInt16BE(packet + 8);

    if (!m_isMoving)
    {
        WarpToPosition(targetX, targetY, viewportX, viewportY);
        m_mapPane->RecenterAndSendPosition(targetX, targetY, viewportX, viewportY, false);
        m_mapPane->UpdateObjectPosition(this);
        RefreshAllLinkedObjects();

        TimerHandler *mapTimer =
            (m_mapPane != NULL) ? &m_mapPane->m_timerHandler : NULL;
        g_pTimerMgr->RemoveTimersForOwner(mapTimer);
    }

    return true;
}
```

Draft caveats:

- `HandlePositionSyncPacketRaw`, `m_mapPane`, `m_timerHandler`, `UpdateObjectPosition`, and `RemoveTimersForOwner` are descriptive names.
- `std::char_traits<char>::to_char_type(packet[1])` is source-ugly but accurately preserves the odd runtime byte-read/discard. A future source polish may spell it as `unsigned char reserved = packet[1]; (void)reserved;` if the project standard treats `0x00575470` as a byte-read artifact rather than an explicit source call.
- If future route evidence proves this is a normal dispatcher method, the formal block can use this draft after reconciling exact opcode and packet subtype names.

## Score / Metadata Recommendation

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:88
CANONICAL_OWNER:00007B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007B
RECONSTRUCTION_CPP: keep blank
```

Score rationale:

- Completion improves from `85` to `87` because the report resolves packet field layout, packet read helper names, `this+0x1c4` as `m_isMoving`, `this+0x1340f8` as `m_mapPane`, callee roles, padding/boundaries, route scan details, ownership ranking, rejected alternatives, and first-draft C++ policy.
- Confidence improves from `86` to `88` because byte-level behavior and owner/source placement are strong and cross-validated by support docs. It remains below `90` because the entry route and exact dispatcher opcode are still unproven, and formal C++ should not be emitted as a normally called method.

## Exact Recommended Target Doc Changes

Update `source-3/project-documentation/by-memory/0x005ac1b0-0x005ac27c.LivingObjectPaneRawPositionSyncPacketHelper.md`:

1. Metadata:
   - `COMPLETION:85 -> 87`
   - `CONFIDENCE:86 -> 88`
   - Keep `CANONICAL_OWNER:00007B`
   - Keep `RECONSTRUCTABLE:TRUE`
   - Keep `EMITTER_UIDS:00007B`
   - Keep formal C++ blank.

2. Replace the current short summary with detailed behavior:
   - One explicit `packet` argument; `ret 4`.
   - `packet[1]` read through `0x00575470` and discarded.
   - Big-endian 16-bit reads through `PacketBufferReadUInt16BE` at `packet+2/+4/+6/+8`.
   - Parsed fields are `targetX`, `targetY`, `viewportX`, and `viewportY` / `viewportOffsetX/Y`.
   - If `m_isMoving` (`this+0x1c4`) is nonzero, skip mutation and return true.
   - If not moving, call `WarpToPosition`, `MapPane::RecenterAndSendPosition(..., false)`, MapPane object-coordinate update, `RefreshAllLinkedObjects`, and TimerMgr owner cleanup for `m_mapPane +0xa4` or null.

3. Add a `Route / Liveness` section:
   - IDA MCP was unavailable in B010's resumed run.
   - PE-aware scan found zero direct rel32 edges to `0x005ac1b0`, zero absolute VA pointer hits, and zero target-RVA pointer hits.
   - Positive controls found expected calls to `0x005a5a90`, `0x005059d0`, `0x005ac280`, `0x005ac070`, `0x005abda0`, `0x005ab090`, and `0x005ab410`.
   - [UID:0003VB]/[UID:0003VC] dispatcher/switch-table docs do not route an opcode case to this raw helper.

4. Add a `Packet Layout` table matching the layout above.

5. Add a `Source-Quality Names` table:
   - `this+0x1c4 = m_isMoving / m_movementActive`
   - `this+0x1340f8 = m_mapPane`
   - `0x00575470 = std::_Narrow_char_traits<char,int>::to_char_type`
   - `0x00575480 = PacketBufferReadUInt16BE`
   - `0x005a5a90 = LivingObjectPane::WarpToPosition`
   - `0x005059d0 = MapPane::RecenterAndSendPosition`
   - `0x00506980 = MapPane object-coordinate update helper`
   - `0x0053c1d0 = LivingObjectPane::RefreshAllLinkedObjects`
   - `0x0067ab80 = g_pTimerMgr`
   - `0x00597a10 = TimerMgr remove-timers-by-owner helper`

6. Replace "not final-C++ ready" with a resolved no-body disposition:
   - This is first-draft source-shape ready as a reference, but formal final C++ should stay blank because no live route is proven.
   - Do not leave "caller route unresolved" as a passive blocker. State the evidence checked and exact impact.

7. Add rejected alternatives:
   - UserPane owner/source method.
   - MapPane owner/source method.
   - PacketBuffer owner.
   - TimerMgr owner.
   - merge into message-show or linked-object packet docs.
   - compiler thunk/destructor/runtime helper.
   - full formal method-body emission before route proof.

8. Add the reference C++ draft in prose only, marked non-final.

## Exact Support-Doc Updates

Update [UID:00007B] `by-class/LivingObjectPane.md`:

- In the local player settings/server packet family, add [UID:0003UV] as a raw no-entry position-sync helper.
- Record resolved behavior: `packet+2/+4/+6/+8` big-endian position/viewport fields, `m_isMoving` gate, `WarpToPosition`, `m_mapPane` recenter/update, `RefreshAllLinkedObjects`, and `g_pTimerMgr` cleanup.
- Replace any generic `0x005ac1b0` unresolved wording with "route/liveness searched; no entry route found; no formal C++ body until route or retained-dead-helper policy".
- Keep final class declaration blocked by broader local-player layout and raw starts, not by lack of analysis on 0003UV.

Update [UID:0000KU] `by-file/LivingObjectPane.md`:

- In `Proposed Contents` and server packet/movement method families, add `0x005ac1b0-0x005ac27c` as `HandlePositionSyncPacketRaw` / retained raw position-sync packet helper.
- State it belongs to `LivingObjectPane.cpp` by source-family inference and receiver state, not `UserPane.cpp`, `MapPane.cpp`, `PacketBuffer.cpp`, or `TimerMgr.cpp`.
- State formal body emission is intentionally blank/no-body due to zero route evidence.

Update [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`:

- In exact child page table, update the `0003UV` row from "raw position-sync helper unresolved" to the resolved packet-body summary.
- In `Projected Boundary Review`, replace passive "caller route, packet subtype unresolved" wording with B010 route/liveness results:
  - no IDA function start,
  - prologue/epilogue and padding confirmed,
  - no direct branch/absolute pointer/RVA route,
  - parses `packet[1]`, BE16 fields at `+2/+4/+6/+8`,
  - calls `WarpToPosition`, `MapPane::RecenterAndSendPosition`, MapPane update, `RefreshAllLinkedObjects`, and TimerMgr cleanup.
- Keep the parent non-emitting split-index disposition.

Update [UID:0003UE] `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`:

- Replace the generic raw caller reference with exact [UID:0003UV] field usage:
  - `0003UV` passes `targetX`, `targetY`, `viewportX`, `viewportY` parsed from `packet+2/+4/+6/+8`.
  - `WarpToPosition` stores the viewport pair at `+0x13ead8/+0x13eadc`, cancels movement timers/effects, clears movement state, and updates MapPane.
- Keep C++ blank unless 0003UE itself receives a separate source-quality pass.

Optional but useful support updates if touched during callback:

- [UID:00024A] `UserPaneGetMapPane`: its displacement-user table already lists `0x005ac1b0`; update the behavior group to use `HandlePositionSyncPacketRaw`, `m_isMoving` gate, and no-entry policy.
- [UID:0002QM] `MapPaneRecenterAndSendPosition`: caller table already records unmodeled call site `0x005ac23b`; add [UID:0003UV] as the owning doc for that unmodeled code reference and note the argument fields are `packet+2/+4/+6/+8`, flag clear.
- [UID:0003VB]/[UID:0003VC] `UserPane::HandleServerMessage` / switch-table: add one negative route note only if the supervisor wants route audits centralized there: current dispatcher/switch-table docs do not route to standalone `0x005ac1b0`.
- [UID:0000SI] `g_pTimerMgr` / [UID:0000F1] `TimerMgr`: no required update; current timer docs already cover `0x00597a10` as timer-removal helper family.
- PacketBuffer docs: no required update; current docs already correctly identify `0x00575470` and `0x00575480`.

## Exact Supervisor-Owned Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. The current `by-memory/-coverage-report.md` search did not find an existing `0003UV` row or nearby `0x005ac070/0x005ac280` placement context. If the supervisor adds/refreshes the LivingObjectPane local-player split block, use this exact pending row for [UID:0003UV]:

```text
        - [UID:0003UV][0x005ac1b0-0x005ac27c.LivingObjectPaneRawPositionSyncPacketHelper](by-memory/0x005ac1b0-0x005ac27c.LivingObjectPaneRawPositionSyncPacketHelper.md) 0x005ac1b0-0x005ac27c | raw helper | LivingObjectPaneRawPositionSyncPacketHelper : reconstructable : 87% : strong : B010 2026-06-19 source-quality pass disassembles the raw no-entry body, confirms no direct rel32/absolute VA/RVA route to `0x005ac1b0`, parses `packet[1]` as an unused reserved/status byte plus BE16 target/viewport fields at `packet+2/+4/+6/+8`, gates mutation on `m_isMoving == 0`, calls `LivingObjectPane::WarpToPosition`, `MapPane::RecenterAndSendPosition`, MapPane object-coordinate update, `LivingObjectPane::RefreshAllLinkedObjects`, and `g_pTimerMgr` owner cleanup for `m_mapPane+0xa4`; keep owner/emitter [UID:00007B] and keep formal C++ blank until a real caller/table route or retained-dead-helper emission policy is approved.
```

Adjacent padding row, if missing from the supervisor-owned coverage context:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005ac27c-0x005ac280 | padding | LivingObjectPane raw position-sync helper to linked-object parser alignment : ignored : 100% : strong : B010 2026-06-19 PE byte check confirms four `0xcc` bytes after [UID:0003UV] `ret 4` at `0x005ac279` and before [UID:0003UW] prologue at `0x005ac280`.
```

If a coverage row for [UID:0003UV] is later found in a refreshed report, replace that row with the exact `0003UV` row above and keep placement between [UID:0003UU] `0x005ac070-0x005ac1a8` plus padding `0x005ac1a8-0x005ac1b0`, and [UID:0003UW] `0x005ac280-0x005ac69b`.

## Validation Commands For Implementation Callback

Run these from `source-3/project-documentation` after applying accepted target/support changes:

> Executable block R001 was removed from this report and preserved verbatim in [0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality-removed.md](0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional support docs are edited, also validate each touched file:

> Executable block R002 was removed from this report and preserved verbatim in [0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality-removed.md](0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No validator was run during this report-only pass because no by-* docs were edited.

## IDA Rename / Type / Comment Recommendations

Apply only as comments/types until route policy is accepted; do not force IDA function creation if the current database intentionally leaves raw starts unmodeled.

Recommended labels/comments:

- `0x005ac1b0`: label/comment `LivingObjectPane_HandlePositionSyncPacketRaw` / `raw retained no-entry position-sync packet helper; no direct route found`.
- Type direction if function is created for analysis only:
  ```cpp
  bool __thiscall LivingObjectPane::HandlePositionSyncPacketRaw(const unsigned char *packet);
  ```
- `0x005ac1c5`: comment `packet[1] reserved/status byte read through std::_Narrow_char_traits<char,int>::to_char_type; return value unused`.
- `0x005ac1ce`: comment `targetX = PacketBufferReadUInt16BE(packet + 2)`.
- `0x005ac1dd`: comment `targetY = PacketBufferReadUInt16BE(packet + 4)`.
- `0x005ac1ec`: comment `viewportX = PacketBufferReadUInt16BE(packet + 6)`.
- `0x005ac1f8`: comment `viewportY = PacketBufferReadUInt16BE(packet + 8)`.
- `0x005ac203`: comment `if (m_isMoving) skip correction body`.
- `0x005ac221`: call comment `LivingObjectPane::WarpToPosition(targetX, targetY, viewportX, viewportY)`.
- `0x005ac23b`: call comment `m_mapPane->RecenterAndSendPosition(targetX, targetY, viewportX, viewportY, false)`.
- `0x005ac247`: call comment `m_mapPane->UpdateObjectPosition(this)` / exact MapPane update name pending.
- `0x005ac24e`: call comment `RefreshAllLinkedObjects()`.
- `0x005ac26c`: call comment `g_pTimerMgr->RemoveTimersForOwner(m_mapPane ? &m_mapPane->timerHandler : NULL)`.

Field/type comments:

- `LivingObjectPane +0x1c4`: `m_isMoving` / `m_movementActive`.
- `local-player/UserPane aggregate +0x1340f8`: `MapPane *m_mapPane`.
- `MapPane +0xa4`: embedded timer-handler facet used for TimerMgr cleanup; final field name pending.
- `LivingObjectPane +0x13ead8/+0x13eadc`: local viewport-position pair used by [UID:0002RW]; exact member order/name remains descriptive.

Confidence:

- High for byte boundary, packet fields, callee identities, `m_isMoving`, `m_mapPane`, and LivingObjectPane source-family route.
- Medium for exact original method name, exact packet subtype/opcode, exact `MapPane +0xa4` field name, and final TimerMgr helper name.

## Open Questions Closed / Remaining With Impact

Closed:

- Raw body shape: real source-shaped packet helper, not padding/thunk/runtime.
- Callee `0x005a5a90`: `LivingObjectPane::WarpToPosition`.
- `this+0x1c4`: movement-active byte (`m_isMoving`).
- `this+0x1340f8`: `MapPane *m_mapPane`, proven by [UID:00024A].
- Packet layout: reserved/status byte at `+1`; BE16 target and viewport fields at `+2/+4/+6/+8`.
- Owner/source family: LivingObjectPane over UserPane/MapPane/PacketBuffer/TimerMgr.
- Formal C++ policy: keep blank because no entry route is proven; include reference draft only.

Remaining:

- Exact dispatcher opcode/subtype cannot be recovered from this helper because no route to the helper start was found. Impact: cap confidence below final-source level and do not assign enum/opcode name.
- Exact original helper name cannot be proven. Impact: use descriptive `HandlePositionSyncPacketRaw`, not a recovered symbol claim.
- Exact field names/order for the viewport pair `+0x13ead8/+0x13eadc` remain provisional. Impact: source draft uses descriptive `viewportX/Y`; do not push to final audit until broader local-player layout is settled.
- Exact MapPane object update method name at `0x00506980` remains descriptive. Impact: not a blocker for target prose, but final C++ would need coordinated MapPane naming if route evidence later justifies emission.

## Implementation Callback Checklist

If accepted, send Agent-B010 a callback to:

1. Lease and update the target and support docs listed above. Do not edit `by-memory/-coverage-report.md`.
2. Set [UID:0003UV] to `87/88`, keep owner/emitter `00007B`, keep reconstructable true, and keep formal C++ blank.
3. Incorporate all packet layout, route scan, byte boundary, field/global/helper naming, rejected alternatives, and no-body proof details into the target at report-level specificity.
4. Carry the support facts into `by-class/LivingObjectPane.md`, `by-file/LivingObjectPane.md`, the [UID:0001KM] split index, and [UID:0003UE] `WarpToPosition`; optionally update [UID:00024A]/[UID:0002QM]/[UID:0003VB]/[UID:0003VC] if the supervisor wants explicit back-reference/negative-route notes there.
5. Keep the reference C++ draft in prose only unless the supervisor explicitly approves retained no-route helper emission.
6. Run the scoped validators listed in this report for every touched doc.
7. Record validator exit codes, any generated side effects, changed files, and the exact pending coverage row/block text above in `Agent-B010/notes.md`.

FINISHED research report for [UID:0003UV].

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0003UV"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003UV"} -->
<!-- {"agent":"B010","command_id":"000000023047","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality.md","timestamp":"2026-08-13T02:36:38-04:00","uid":"0003UV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
