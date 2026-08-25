** TARGET-REPORT-UID:0003H4 **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003H4 **
# Agent-B015 Source-Quality Report: [UID:0003H4] LivingObjectPaneSendDirectionPacketRawHelper

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0003H4-LivingObjectPaneSendDirectionPacketRawHelper-source-quality.md`

Target path: `source-3/project-documentation/by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md`

Assignment: report-only B-agent source-quality / heuristic pass. I did not edit by-* docs, generated output, IDA, or `by-memory/-coverage-report.md`.

## Recommendation Summary

Keep [UID:0003H4] as reconstructable, source-shaped `LivingObjectPane` action-tail packet helper code with `CANONICAL_OWNER:00007B` and `EMITTER_UIDS:00007B`, but do not populate formal reconstruction C++ yet.

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:00007B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007B
```

Rationale:

- The body is a real 0x3f-byte source-shaped packet sender, not padding and not compiler glue. It has a normal stack-cookie prologue, one stack argument, a three-byte stack packet `{0x11, direction, 0}`, a `QueueAndSendPacket` call with length `2`, and `ret 4`.
- Fresh PE/Capstone recheck confirms exact range `0x005acae0-0x005acb1f`, raw offset `0x1abee0-0x1abf1f`, SHA1 `90caaac24bdccbd664724849352447d104d2b299`, eleven-byte prepad `0x005acad5-0x005acae0`, and one-byte postpad `0x005acb1f-0x005acb20`.
- Fresh route scan found no external rel32/short branch into the body, no branch to the start, no VA/RVA dword route to the body, and no exact VA/RVA/raw-offset start pointer. The positive controls found the live call `0x005a5956 -> 0x005acc30` and 416 direct calls to [UID:0001HU] `QueueAndSendPacket`, so the scan is not blind.
- The helper does not read `this` or any `LivingObjectPane` fields. This corrects the older passive "method-shaped thiscall" wording: source shape is best described as a small direction/facing packet helper in `LivingObjectPane.cpp`, possibly a private member with unused `this`, a static member, or a file-local helper. Because no caller route is proven, the original declaration shape cannot be frozen.
- The `0x11` packet semantics are strong: [UID:0003H5] and live [UID:0003UZ] derive a facing/direction byte, compare it to the actor's current facing byte at `this+0x1c5`, and send opcode `0x11` when facing changes. [UID:0003H4] is the minimal one-argument sender for that same packet shape.
- Current code-entry numerics are already above the active `(COMPLETION + CONFIDENCE) / 2 > 85` gate, so stale "below 95+" wording should be removed. Formal C++ is deferred for target-specific source/route reasons, not because of the old numeric gate.

Recommended formal C++ policy:

- Keep the target `RECONSTRUCTION_CPP` block blank.
- Add a route-contingent source-shape note only:

```cpp
// Route-contingent draft only; do not paste into the formal C++ block yet.
void LivingObjectPane::SendDirectionPacket(unsigned char direction)
{
    unsigned char packet[3];
    packet[0] = 0x11;
    packet[1] = direction;
    packet[2] = 0; // local terminator/scratch byte; QueueAndSendPacket sends length 2

    g_packetSender->QueueAndSendPacket(packet, 2);
}
```

If future policy requires no-`this` helpers to be emitted as file-local functions, the same behavior should be represented as `static void SendDirectionPacket(unsigned char direction)` in `LivingObjectPane.cpp`. Current evidence does not justify choosing formal member vs file-local/static declaration.

## Evidence Checked

Target/support docs read:

- `by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md`
- `by-memory/0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md`
- `by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md`
- `by-memory/0x005acc30-0x005acd85.LivingObjectPaneSendActionPacketWithAutoFace.md`
- `by-memory/0x005a58c0-0x005a5983.LivingObjectPaneTryPerformAction.md`
- `by-memory/0x005a8cf0-0x005a8e67.LivingObjectPaneSendMovementPacket.md`
- `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
- `by-class/LivingObjectPane.md`
- `by-file/LivingObjectPane.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-memory/0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`
- `auto-generated/NexusTK/map/LivingObjectPane.cpp`
- Prior reports used as leads only:
  - `Agent-B001/research/00007B-LivingObjectPane-class-source-quality.md`
  - `Agent-B001/research/executed/older/0001KM-livingobject-localplayer-source-split-audit.md`
  - `Agent-B001/research/executed/older/0003EB-LivingObjectPaneActionNegativeOneFloatConstant.md`
  - `Agent-B015/research/0003UJ-LivingObjectPaneRawFunctionKeyDebounceHelper-source-quality.md`

Searches and binary checks performed:

- `rg -n "0003H4|005acae0|005acb1f|LivingObjectPaneSendDirectionPacketRawHelper|SendDirectionPacket|direction packet|opcode 0x11|auto.?face|local-player action|g_packetSender|QueueAndSendPacket" source-3/project-documentation -S`
- `Select-String -LiteralPath by-memory/-coverage-report.md -Pattern "0003H4|005acae0|005acb1f"`
- `rg -n "005acb1f|005acb20|005acad5|005acae0|LivingObjectPane direction helper|auto-face helper alignment|0003H4|0003H5" by-memory/-ignored.md by-memory/-coverage-report.md -S`
- PE-aware Python scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:
  - parsed PE headers and section mapping;
  - extracted target bytes and SHA1;
  - decoded target and selected neighbor bytes through Capstone;
  - scanned loaded/executable sections for rel32 `call`/`jmp`, conditional rel32, short jump, and short conditional branch targets into the target range;
  - scanned dword values for VA/RVA/raw-offset hits into the target range and exact VA/RVA/raw-offset hits for the target start/end;
  - checked positive controls for `0x005acc30` and `0x00574bb0`.

Positive controls:

- Branch scan found one live direct call to [UID:0003UZ] `0x005acc30` at `0x005a5956`.
- Branch scan found 416 direct calls to [UID:0001HU] `QueueAndSendPacket` at `0x00574bb0`, including early examples `0x0045891c`, `0x00458b12`, `0x004594ba`, and many more.
- The same PE's current `.text` mapping is image base `0x00400000`, `.text` RVA `0x1000`, `.text` raw `0x400`, so target VA `0x005acae0` maps cleanly to raw `0x1abee0`.

Negative route evidence:

- No rel32/short branch target to `0x005acae0`.
- No rel32/short branch target to any byte in `0x005acae0-0x005acb1f`.
- No VA dword values into `0x005acae0-0x005acb1f`.
- No RVA dword values into `0x001acae0-0x001acb1f`.
- No exact target-start VA/RVA/raw-offset hits:
  - VA start `0x005acae0`: zero hits.
  - RVA start `0x001acae0`: zero hits.
  - raw start `0x001abee0`: zero hits.
- One dword-sized value equal to raw offset `0x1abefd` appears at raw `0x20b06` / VA `0x00421706`, but Capstone decodes the surrounding code as an unrelated `call 0x005cd607` at `0x00421705` with that value as the rel32 displacement bytes. It is not a pointer/table route to this helper.

## Raw Body Findings

Exact body:

```text
VA range:  0x005acae0-0x005acb1f
Raw range: 0x001abee0-0x001abf1f
Length:    0x3f / 63 bytes
SHA1:      90caaac24bdccbd664724849352447d104d2b299
```

Raw bytes:

```text
55 8b ec 83 ec 10 a1 24 2f 67 00 33 c5 89 45 fc
8a 45 08 8b 0d ec a7 67 00 88 45 f1 8d 45 f0 6a
02 50 c6 45 f0 11 c6 45 f2 00 e8 a1 80 fc ff 8b
4d fc 33 cd e8 16 ac 01 00 8b e5 5d c2 04 00
```

Capstone decode:

```asm
005acae0  push     ebp
005acae1  mov      ebp, esp
005acae3  sub      esp, 0x10
005acae6  mov      eax, dword ptr [0x672f24]
005acaeb  xor      eax, ebp
005acaed  mov      dword ptr [ebp - 4], eax
005acaf0  mov      al, byte ptr [ebp + 8]
005acaf3  mov      ecx, dword ptr [0x67a7ec]
005acaf9  mov      byte ptr [ebp - 0xf], al
005acafc  lea      eax, [ebp - 0x10]
005acaff  push     2
005acb01  push     eax
005acb02  mov      byte ptr [ebp - 0x10], 0x11
005acb06  mov      byte ptr [ebp - 0xe], 0
005acb0a  call     0x574bb0
005acb0f  mov      ecx, dword ptr [ebp - 4]
005acb12  xor      ecx, ebp
005acb14  call     0x5c772f
005acb19  mov      esp, ebp
005acb1b  pop      ebp
005acb1c  ret      4
```

Behavior:

- The function has one explicit argument at `[ebp+8]`, read as a byte. Best source-facing name: `direction`, `facing`, or `directionByte`. Prefer `direction` in the target title and support docs, while noting opcode `0x11` is the facing/direction update packet.
- The function does not read `ecx` as a `LivingObjectPane *` receiver. It overwrites `ecx` with [UID:0000Q5] `g_packetSender` before the send.
- It writes local packet bytes:
  - `packet[0] = 0x11`;
  - `packet[1] = direction`;
  - `packet[2] = 0`.
- It calls [UID:0001HU] `QueueAndSendPacket` with length `2`, so `packet[2]` is a local scratch terminator and is not transmitted by this call. `QueueAndSendPacket` itself copies the two caller bytes and appends its own zero byte to the queued buffer.
- The stack cookie setup/check is compiler-generated `/GS` code; it should not appear as authored C++.
- The helper returns with `ret 4`, consistent with one explicit argument under `__stdcall`-style helper code or `__thiscall` with unused `this`. Caller evidence is absent, so do not freeze a calling convention beyond "one byte/int stack argument, returns void."

Boundary and padding:

- Previous raw helper [UID:0003UY] ends at `0x005acad5`.
- `0x005acad5-0x005acae0` is eleven bytes of `0xcc` alignment.
- [UID:0003H4] ends at `0x005acb1f`; the final instruction `c2 04 00` starts at `0x005acb1c` and occupies bytes through `0x005acb1e`.
- `0x005acb1f-0x005acb20` is one byte of `0xcc` alignment.
- [UID:0003H5] starts at `0x005acb20`.

## Heuristic / Inference Reanalysis And Validation

### Raw Helper Status

Conclusion: [UID:0003H4] is source-shaped retained/orphan helper code, not compiler-generated glue and not padding.

Evidence:

- Complete function-like prologue/epilogue and stack-cookie structure.
- Stack packet construction and a real `QueueAndSendPacket` call.
- Exact alignment before and after.
- Neighbor pages [UID:0003UY], [UID:0003H5], and [UID:0003UZ] place it in the same `LivingObjectPane` local-player packet/action tail.

Rejected alternatives:

- Compiler-generated wrapper/thunk: rejected. The body contains authored packet semantics and a caller argument; security-cookie code is compiler-inserted but the packet sender is project logic.
- Padding/data: rejected. The bytes decode as a coherent function body with one external call and `ret 4`.
- Queue/send infrastructure owner: rejected. [UID:0001HU] and [UID:0000Q5] own the transport helper/global, but this body owns the feature-specific opcode `0x11` packet layout.

### Source-Facing Name And Signature

Best current source-facing name: `SendDirectionPacketRaw` in documentation; route-contingent source name `SendDirectionPacket`.

Best current source-facing parameter name: `direction`, with a note that it is the local facing/direction byte for opcode `0x11`.

Signature recommendation for prose only:

```cpp
// Candidate only.
void LivingObjectPane::SendDirectionPacket(unsigned char direction);
// or, under a file-local helper policy:
static void SendDirectionPacket(unsigned char direction);
```

Evidence:

- The target writes opcode `0x11` and a single caller-supplied byte, then sends length `2`.
- [UID:0003H5] and [UID:0003UZ] use the same opcode to update facing/direction after comparing a derived facing byte against current facing at `this+0x1c5`.
- The function title and previous docs already use "direction packet"; this remains the least surprising name.

Rejected names:

- `SendActionPacket`: rejected because live [UID:0003UZ] sends action opcode `0x13` after any direction update. [UID:0003H4] only sends opcode `0x11`.
- `SendMovementPacket`: rejected because [UID:0003UI] owns the movement/path packet sender and this body has no movement path/history fields.
- `AutoFaceDirectionPacket`: rejected for this exact target because auto-face computation is in [UID:0003H5]/[UID:0003UZ]; [UID:0003H4] only serializes a caller-supplied byte.
- `QueueAndSendPacket`: rejected because that name belongs to [UID:0001HU] `0x00574bb0`.

### Byte Order And Packet Semantics

Conclusion: opcode `0x11` is a two-byte facing/direction update packet with an unsent local terminator.

Packet layout:

```text
packet[0] = 0x11      // facing/direction opcode
packet[1] = direction // caller-supplied facing/direction byte
packet[2] = 0         // local terminator/scratch only; not included in length 2
send length = 2
```

No multi-byte byte-order issue exists in this target because the transmitted payload is two one-byte fields. The only "byte order" guidance needed is to avoid inventing a 16-bit opcode or transmitting the local zero terminator. `QueueAndSendPacket` later appends its own zero to the copied queued buffer.

### Owner / Emitter / Source Placement

Recommended metadata: keep direct owner/emitter [UID:00007B] `LivingObjectPane`.

Source-placement conclusion: `NexusTK/map/LivingObjectPane.cpp`, under the local-player action/facing packet helper family.

Evidence for `LivingObjectPane` family:

- Physical placement is inside [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`, immediately between [UID:0003UY] raw facing packet helper and [UID:0003H5] raw auto-face direction helper.
- [UID:0003H5] and [UID:0003UZ] use the same opcode `0x11` send semantics with `LivingObjectPane` target/facing fields.
- [UID:0003UZ] has a live direct caller from [UID:0003UD] `0x005a58c0` at `0x005a5956`, tying the neighboring action-tail behavior to ordinary local-player action flow.
- [UID:0000KU] `LivingObjectPane.cpp` is the file route for movement/action/local-player helpers and already emits the empty marker for [UID:0003H4] through [UID:00007B].

Why not change direct owner to [UID:0000KU] now:

- The project currently attaches small private packet helpers to the semantic class when they are class-family helpers, even if they do not read `ecx`; examples include item-action packet helpers that docs describe as private file-scope/static possibilities but still route through the owning pane class when source-family evidence is class-specific.
- This target has no cross-class callers or shared module evidence. A file owner would be defensible only if the project adopts a strict "no `this` read means file-local" policy for all such helpers.
- Keeping [UID:00007B] preserves the existing route and avoids a support churn that current evidence does not require.

Important prose correction:

- Do not call this body "method-shaped thiscall" without qualification. It has no `this` field read. Say "one-argument raw helper in the LivingObjectPane action-tail source family; possible private member with unused `this`, static member, or file-local helper."

Rejected owner alternatives:

- [UID:0000FQ]/[UID:0000P1] `UserPane`: rejected. `UserPane` owns local UI/event dispatch, but this body is in the LivingObjectPane local-player action/facing packet tail and has no UserPane event fields or direct route.
- [UID:0001HU] `QueueAndSendPacket` / [UID:0000DD] `Socket`: rejected. Those docs own the transport queue/send funnel, not the feature opcode builder.
- [UID:0000MV] `ProtocolSend`: rejected. Current source-tree guidance says feature packet builders stay with their feature files unless shared routing is proven.

### Raw-Retained Liveness Versus Emitter Readiness

Conclusion: source-family ownership is strong enough to keep `RECONSTRUCTABLE:TRUE` and owner/emitter metadata, but not strong enough to emit formal method C++.

Route proof checked:

- Existing target/parent docs report no current IDA function object and zero `xrefs_to` start results from earlier B001 live IDA checks.
- Fresh PE scan found no direct branch into the target start or body.
- Fresh PE scan found no VA/RVA pointer values into the target body and no exact start VA/RVA/raw-offset pointer values.
- The only raw-offset-sized full-range dword value found is an unrelated call displacement at `0x00421705 -> 0x005cd607`; it is not a pointer route.

Positive controls:

- Live modeled neighbor [UID:0003UZ] is called from `0x005a5956`.
- `QueueAndSendPacket` has 416 direct call references in the same scan.

No-code/defer proof:

- No proven live caller, pointer table, switch table, vtable entry, or indirect route reaches `0x005acae0`.
- The original declaration form is not recoverable: member with unused `this`, static member, and file-local helper all compile plausibly to this body under different call/declaration contexts.
- Live [UID:0003UZ] and raw [UID:0003H5] contain inline opcode `0x11` sends; they do not call [UID:0003H4]. Emitting [UID:0003H4] as ordinary called C++ would overstate reachability.
- The helper is not behaviorally blocked: the packet C++ shape is obvious. It is source-route/declaration blocked.

Implementation policy:

- Formal C++ remains blank.
- Replace stale old-gate text with the target-specific no-code proof above.
- Include route-contingent draft source only as prose.

### Relationship To Auto-Face Helper And Local-Player Action Tail

Conclusion: [UID:0003H4] is the minimal direction/facing packet sender for the same opcode used by [UID:0003H5] and [UID:0003UZ], but current compiled code around the live path inlines the send rather than calling this helper.

Evidence:

- [UID:0003H5] raw auto-face helper:
  - receives `LivingObjectPane *this` in `ecx`;
  - reads action/target/facing state;
  - computes target-facing slope using `1.0f` and [UID:0003EB] `-1.0f`;
  - compares derived facing against byte `this+0x1c5`;
  - sends opcode `0x11` only when facing changes.
- [UID:0003UZ] live action helper:
  - has one modeled caller at `0x005a5956` from [UID:0003UD] `TryPerformAction`;
  - performs the same auto-face calculation;
  - sends opcode `0x11` if needed;
  - then sends action opcode `0x13`.
- [UID:0003H4] has no target lookup/facing math. It serializes `{0x11, direction}` for a caller that would already have selected the byte.

Rejected interpretation:

- [UID:0003H4] is not itself the auto-face routine. It is a lower-level serializer/helper candidate.

### Compiler-Generated / Raw Names

Final names to prefer in docs:

| Raw/generated name | Source-quality direction |
| --- | --- |
| `sub_574BB0` | [UID:0001HU] `QueueAndSendPacket`; source-facing likely `Socket::QueueAndSendPacket` or equivalent queue-send wrapper. |
| `dword_67A7EC` | [UID:0000Q5] `g_packetSender`, best current source type `Socket *`. |
| `___security_cookie` / `0x00672f24` | compiler-generated stack cookie, not authored source state. |
| `0x005c772f` | security-cookie check helper, compiler-generated. |
| `LivingObjectPaneSendDirectionPacketRawHelper` | documentation title; source-facing candidate `SendDirectionPacketRaw` / `SendDirectionPacket`. |

Do not leave raw names as passive blockers. The only remaining source blocker is not helper naming for `g_packetSender` or `QueueAndSendPacket`; those are already resolved well enough. The blocker is the missing caller/declaration route for the target itself.

## Open Questions With Attempted Resolution

1. Is there a live route to the helper?

   Evidence checked: target docs, [UID:0001KM], prior B001 reports, PE rel32/short branch scan, VA/RVA/raw-start dword scan, positive controls.

   Result: no live route found. Best conclusion is retained/orphan source-shaped helper, not an ordinary live-called method.

2. Is the helper an instance member method?

   Evidence checked: raw body, Capstone decode, comparison to no-`this` packet helpers, `ret 4`, source-family docs.

   Result: no safe proof. It could be a private member with unused `this`, a static member, or a file-local helper. Keep semantic owner [UID:00007B] but do not place formal C++ until a caller/declaration route is proven.

3. What is the packet opcode semantics?

   Evidence checked: [UID:0003H4] raw bytes, [UID:0003H5] auto-face helper, [UID:0003UZ] live action sender, [UID:0003EB] constant docs.

   Result: opcode `0x11` is the local facing/direction update packet. It sends a single direction/facing byte. The local zero after it is not sent.

4. Should `g_packetSender`/`QueueAndSendPacket` names still block C++?

   Evidence checked: [UID:0000Q5] and [UID:0001HU].

   Result: no. Those names/types are sufficiently documented for a draft. They are dependencies, not current blockers for this target.

5. Should the target become non-reconstructable/no-owner because there is no route?

   Evidence checked: raw body, neighboring raw helper policy, [UID:0003UJ] and [UID:0003US] no-route precedents.

   Result: no. The body is real source-shaped feature code in a coherent source family. Lack of route caps confidence and blocks formal C++, but does not require `RECONSTRUCTABLE:FALSE`.

## Exact Recommended Target Doc Changes

File: `source-3/project-documentation/by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md`

1. Update metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Replace stale reconstruction guidance:

Before direction:

- Remove wording that says final C++ is blank because "below the `95+` gate."

After direction:

```text
Formal C++ remains blank for a target-specific route/declaration reason, not because of the stale 95+ gate. The current active numeric gate is satisfied, but no caller, pointer table, switch table, vtable route, or external branch reaches `0x005acae0`, and the body does not prove whether the original declaration was a private `LivingObjectPane` member with unused `this`, a static member, or a file-local helper.
```

3. Add raw PE facts:

```text
B015 2026-06-19 raw PE/Capstone recheck against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirms `0x005acae0-0x005acb1f` maps to raw `0x1abee0-0x1abf1f`, length `0x3f`, SHA1 `90caaac24bdccbd664724849352447d104d2b299`. The previous helper's alignment is eleven `0xcc` bytes at `0x005acad5-0x005acae0`; this helper's successor alignment is one `0xcc` byte at `0x005acb1f-0x005acb20`.
```

4. Add exact behavior:

```text
The helper accepts one stack byte argument at `[ebp+8]`, best named `direction` / `facingDirection`. It builds local stack bytes `{0x11, direction, 0}`, loads [UID:0000Q5] `g_packetSender`, and calls [UID:0001HU] `QueueAndSendPacket` with length `2`. The third local zero byte is a local terminator/scratch byte and is not transmitted by this call; `QueueAndSendPacket` appends its own terminator after copying the two-byte payload.
```

5. Add the source-shape correction:

```text
This body should not be described as proven `thiscall` instance logic. It does not read `ecx` or any `LivingObjectPane` field; it overwrites `ecx` with `g_packetSender`. Its source family is still `LivingObjectPane` because it sits in the local-player action/facing packet tail and matches the opcode `0x11` send used by [UID:0003H5] and [UID:0003UZ], but the exact declaration remains unresolved between private member, static member, or file-local helper.
```

6. Add route evidence:

```text
B015 PE route scan found no rel32/short branch into `0x005acae0-0x005acb1f`, no branch to the start, no loaded VA/RVA dword into the target range, and no exact VA/RVA/raw-offset pointer for the target start. One raw-offset-sized full-range dword value at VA `0x00421706` is an unrelated call displacement for `0x00421705 -> 0x005cd607`, not a route. Positive controls found the live `0x005a5956 -> 0x005acc30` call and 416 direct calls to [UID:0001HU] `QueueAndSendPacket`.
```

7. Add relationship wording:

```text
[UID:0003H4] is the minimal opcode `0x11` direction/facing serializer. [UID:0003H5] and live [UID:0003UZ] compute when facing should change and inline the same send shape before action opcode `0x13`; current evidence does not show either body calling [UID:0003H4].
```

8. Add route-contingent draft source note, not formal C++:

```cpp
// Candidate source shape only; keep the formal C++ block blank until a route/declaration is proven.
void LivingObjectPane::SendDirectionPacket(unsigned char direction)
{
    unsigned char packet[3] = {0x11, direction, 0};
    g_packetSender->QueueAndSendPacket(packet, 2);
}
```

9. Preserve rejected alternatives:

- Not `UserPane` direct owner.
- Not Socket/QueueAndSendPacket owner.
- Not compiler glue.
- Not auto-face computation itself.
- Not a reason to emit direct formal C++ while no live route/declaration exists.

## Exact Support Doc Updates

File: `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`

- Update the [UID:0003H4] child mention:

```text
[UID:0003H4] `0x005acae0-0x005acb1f` is a retained/no-live-route raw direction/facing packet serializer. B015 raw PE/Capstone recheck confirms the exact 0x3f-byte body, packet `{0x11, direction, 0}`, send length `2`, one-byte postpad before [UID:0003H5], and no rel32/short/VA/RVA route to the helper. It belongs to the `LivingObjectPane` action-tail source family but should not be described as a proven instance method because it does not read `this`.
```

- Replace any broad "raw projected starts remain unresolved" wording that mentions `0x005acae0` with the stronger conclusion: behavior and source family resolved; live route/declaration unresolved; formal C++ deferred.

File: `by-class/LivingObjectPane.md`

- Under local-player packet-tail caveats, add:

```text
[UID:0003H4] `0x005acae0-0x005acb1f` is the simple opcode `0x11` direction/facing packet serializer in the action tail. It sends `{0x11, direction}` through `g_packetSender` with length `2` and has no live route in B015's PE scan. The body does not read `this`, so final class C++ must not force it as an ordinary instance method until a caller/declaration route is proven; keep it as retained source-shaped `LivingObjectPane` helper evidence.
```

File: `by-file/LivingObjectPane.md`

- Add/update proposed contents or boundary notes for local-player action-tail raw helpers:

```text
Local-player action-tail packet helpers include [UID:0003H4] `SendDirectionPacketRaw`, [UID:0003H5] auto-face direction helper, and live [UID:0003UZ] action sender. B015 resolves [UID:0003H4] as a no-live-route one-argument opcode `0x11` serializer with an unsent local terminator and no `this` field reads. It remains routed through `LivingObjectPane.cpp`, but formal C++ stays blank until the source declaration form is proven.
```

File: `by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md`

- Add:

```text
The neighboring [UID:0003H4] helper is the minimal `{0x11, direction}` serializer. This auto-face body currently inlines its opcode `0x11` send and has no proven call to [UID:0003H4].
```

File: `by-memory/0x005acc30-0x005acd85.LivingObjectPaneSendActionPacketWithAutoFace.md`

- Add:

```text
The live action sender at `0x005acc30` is the positive-control route for the action tail: B015 PE scan finds the direct call at `0x005a5956`. It computes auto-facing, sends opcode `0x11` inline when the facing byte changes, and then sends action opcode `0x13`. It does not prove liveness for [UID:0003H4].
```

File: `by-memory/-ignored.md`

- No required support edit for this target if the existing combined local-player padding note is considered sufficient. It already includes `0x005acb1f-0x005acb20` and cites [UID:0003H4]/[UID:0003H5].
- Optional precision update if touched:

```text
B015 2026-06-19 raw PE/Capstone recheck reconfirms `0x005acb1f-0x005acb20` is exactly one `0xcc` byte after [UID:0003H4]'s `ret 4` and before [UID:0003H5]'s prologue.
```

File: `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`

- No required edit. It already documents that callers pass packet length and the wrapper appends its own terminator. If a cross-link is desired, add [UID:0003H4] as another two-byte packet caller/no-route raw helper, but do not clutter the generic queue-send page unless maintaining a caller examples table.

File: `by-global/g_packetSender.md`

- No required edit. The global's `Socket *` and broad feature sender role are already documented. [UID:0003H4] is another feature packet builder consumer, not new ownership evidence.

## Coverage Report Text For Supervisor

`by-memory/-coverage-report.md` currently has the [UID:0001KM] split-index parent but no direct [UID:0003H4] child row. Do not apply this from the B-agent report. Supervisor-owned suggested insertion under [UID:0001KM], in address order with the local-player tail children:

```markdown
        - [UID:0003H4][0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper](by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md) 0x005acae0-0x005acb1f | raw retained/no-live-route direction packet helper | LivingObjectPaneSendDirectionPacketRawHelper : reconstructable : 86% : strong : B015 2026-06-19 raw PE/Capstone recheck confirms the exact 0x3f-byte body at raw offset `0x1abee0` (SHA1 `90caaac24bdccbd664724849352447d104d2b299`), security-cookie prologue, one stack direction/facing byte at `[ebp+8]`, packet bytes `{0x11, direction, 0}`, [UID:0000Q5] `g_packetSender` / [UID:0001HU] `QueueAndSendPacket` send length `2`, and one-byte `0xcc` postpad before [UID:0003H5]. The local zero byte is not transmitted by this call. Fresh route scan found no branch to `0x005acae0`, no rel32/short branch into `0x005acae0-0x005acb1f`, no VA/RVA dword route into the body, and no exact VA/RVA/raw-offset start pointer; the only raw-offset-sized full-range hit is an unrelated call displacement at `0x00421705`. Positive controls found the live `0x005a5956 -> 0x005acc30` action-tail call and 416 direct calls to `QueueAndSendPacket`. Keep owner/emitter [UID:00007B] as `LivingObjectPane` action-tail source-family code, but formal C++ stays blank/deferred because no live caller/declaration route proves member vs static/file-local helper shape.
```

If supervisor also wants the immediate padding row exposed separately in coverage:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005acb1f-0x005acb20 | padding | LivingObjectPane direction helper to auto-face helper alignment : ignored : 100% : strong : B015 2026-06-19 raw PE/Capstone recheck confirms exactly one `0xcc` byte after [UID:0003H4]'s `ret 4` and before [UID:0003H5]'s prologue.
```

Optional replacement for the [UID:0001KM] parent row if supervisor is refreshing stale broad wording:

```markdown
    - [UID:0001KM][0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md) 0x005a2de0-0x005ad441 | mixed source-family split index | LivingObjectPaneLocalPlayerExtensions : ignored : 88% : strong : Non-emitting split index for the local-player movement/command/server-packet neighborhood; exact children carry LivingObjectPane/UserPane/SayInputPanes/Chatting/Quit/SelfSave ownership. Raw retained/no-live-route helpers such as [UID:0003UJ] `0x005a9250`, [UID:0003H4] `0x005acae0`, and [UID:0003H5] `0x005acb20` now have explicit behavior/source-family/no-formal-C++ policy rather than stale generic blockers.
```

## IDA Rename, Type, And Comment Recommendations

Do not make IDA changes from this report unless a supervisor implementation callback explicitly requests them.

If IDA modeling/commenting is allowed later:

- Consider creating a function at `0x005acae0` only if the project policy allows no-route raw helpers to be modeled.
- Preferred IDA label:

```text
LivingObjectPane_SendDirectionPacketRaw
```

- Conservative function type:

```c
void __stdcall LivingObjectPane_SendDirectionPacketRaw(unsigned char direction);
```

- Alternate type only if a member route is later proven:

```c
void __thiscall LivingObjectPane::SendDirectionPacket(unsigned char direction);
```

- Comments:
  - `0x005acaf0`: `direction/facing packet byte argument`.
  - `0x005acaf3`: `load g_packetSender; this/ecx is not used as LivingObjectPane here`.
  - `0x005acb02`: `packet[0] = 0x11 direction/facing update opcode`.
  - `0x005acb06`: `local terminator/scratch byte; QueueAndSendPacket length is 2, so this zero is not transmitted by caller length`.
  - `0x005acb0a`: `QueueAndSendPacket(g_packetSender, packet, 2)`.
  - Function-level comment: `Raw retained LivingObjectPane action-tail packet helper; no caller/pointer route found in B015 PE scan. Do not treat as proven live member method.`

Do not rename [UID:0003H5] or [UID:0003UZ] as part of this target. Their docs should only receive cross-link/prose updates if the implementation callback includes support-doc edits.

## Implementation Checklist For Later Callback

1. Edit `by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md`:
   - Raise metadata to `86/88`.
   - Keep owner/emitter [UID:00007B].
   - Keep formal C++ blank.
   - Remove stale `95+` gate wording.
   - Add raw PE facts, exact bytes/behavior, no-route scan, source-shape correction, relationship to [UID:0003H5]/[UID:0003UZ], and target-specific no-code proof.
   - Include route-contingent C++ only as prose.

2. Edit support docs if accepted:
   - `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
   - `by-class/LivingObjectPane.md`
   - `by-file/LivingObjectPane.md`
   - `by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md`
   - `by-memory/0x005acc30-0x005acd85.LivingObjectPaneSendActionPacketWithAutoFace.md`
   - Optional: `by-memory/-ignored.md`

3. Do not edit `by-memory/-coverage-report.md`; supervisor should apply the exact row text above if accepted.

4. Run scoped validators from `source-3/project-documentation` for every edited file:

> Executable block R001 was removed from this report and preserved verbatim in [0003H4-LivingObjectPaneSendDirectionPacketRawHelper-source-quality-removed.md](0003H4-LivingObjectPaneSendDirectionPacketRawHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

5. If the supervisor applies coverage row text, validate:

> Executable block R002 was removed from this report and preserved verbatim in [0003H4-LivingObjectPaneSendDirectionPacketRawHelper-source-quality-removed.md](0003H4-LivingObjectPaneSendDirectionPacketRawHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

6. Inspect `auto-generated/NexusTK/map/LivingObjectPane.cpp` after autogen. Expected result: [UID:0003H4] remains an empty emitter marker with updated score metadata, not a method body.

## Final State

This pass resolves the target's source-quality questions as follows:

- Raw helper status: source-shaped retained/orphan packet helper, not compiler glue.
- Opcode semantics: `0x11` is the local facing/direction update packet.
- Packet length: send length is `2`; local `packet[2] = 0` is not transmitted by caller length.
- Source route: `LivingObjectPane.cpp` action-tail source family, direct metadata owner/emitter [UID:00007B] retained.
- Source declaration: unresolved between member with unused `this`, static member, or file-local helper; do not freeze.
- Live route: no caller/pointer/branch route found; positive controls confirm the route scan works.
- Formal C++: blank/deferred, with route-contingent source sketch only.
- Score recommendation: raise from `85/86` to `86/88`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003H4","source_path":"executed-b-agent-research/B015/0003H4-LivingObjectPaneSendDirectionPacketRawHelper-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
