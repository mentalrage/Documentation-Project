** TARGET-REPORT-UID:00010D **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00010D] SendClanLeaveResponse Source-Quality Report

Agent: B014  
Date: 2026-06-19  
Target: `by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md`  
Required scope: B-preferred source-quality and heuristic/inference reanalysis only. I did not edit `by-memory/-coverage-report.md`.

## Verdict

`0x00485700` should stay reconstructable and should be upgraded from a loose `Clan.cpp` helper to a source-facing `ClanStatusPane` member helper:

```cpp
void ClanStatusPane::SendClanLeaveResponse(bool confirmed)
```

The binary helper sends the four-byte packet `{0x4b, 3, 1, response}` through the shared socket sender. The only modeled callers are `ClanLeaveConfirmDialog::OnConfirm` and `ClanLeaveConfirmDialog::OnCancel`; they load `g_pClanStatusPane` into `ECX`, push `1` or `0`, and call `0x00485700`. That call shape is stronger evidence for a `ClanStatusPane` member call than for a free file helper. The current descriptive name `SendClanLeaveResponse` is good, but the best source-facing fully qualified name is `ClanStatusPane::SendClanLeaveResponse`.

Recommended metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 92
CANONICAL_OWNER: 00002K
EMITTER_UIDS: 00002K
RECONSTRUCTABLE: TRUE
```

The route still emits to `social/Clan.cpp` through the `ClanStatusPane` class parent. This is not a request to move the function into a different source file.

## Evidence Checked

- Target doc [UID:00010D] records a real function at `0x00485700`, length `0x79`, with two callers: [UID:0002O7] `ClanLeaveConfirmDialog::OnConfirm` and [UID:0002O8] `ClanLeaveConfirmDialog::OnCancel`.
- Live IDA MCP was unavailable in this session (`127.0.0.1:13337` connection failed), so I used the already-recorded IDA evidence in the docs and read-only local fallback decompile/disassembly exports for ABI/body confirmation.
- The fallback body is:
  - `PacketBufferWriteUInt8(0x4b, &packet[0])`
  - `PacketBufferWriteUInt8(3, &packet[1])`
  - `PacketBufferWriteUInt8(1, &packet[2])`
  - `PacketBufferWriteUInt8(response, &packet[3])`
  - clear the byte after the four-byte payload
  - call `QueueAndSendPacket(g_packetSender, packet, 4)`
- Confirm callback bytes load `g_pClanStatusPane`, push `1`, call `0x00485700`, return.
- Cancel callback bytes load `g_pClanStatusPane`, push `0`, call `0x00485700`, return.
- [UID:00002I] `ClanLeaveConfirmDialog` already documents the semantic pairing: confirm sends accept/yes and cancel sends cancel/no.
- [UID:00021H] `SendClanLeaveRequestPacket` sends `{0x4b, 3, 0}`. This validates subtype `3` as clan leave and action `0` as the initial leave request.
- [UID:00010H] `ClanStatusRowActionPacket` maps the clan status leave row to subtype `3`, action `0`, matching [UID:00021H].
- [UID:00021I] clan deposit helpers use the same packet-family pattern with subtype-specific request and submit actions; that supports reading the third byte as an action byte, not a count or size.
- [UID:0003YJ], [UID:0001HZ], [UID:0000M8], and [UID:0000V1] support naming `0x00575380` as `PacketBufferWriteUInt8` or equivalent one-byte packet-buffer writer.
- [UID:0001HU] supports naming `0x00574bb0` as `Socket::QueueAndSendPacket` or equivalent socket queue-send method.
- [UID:0000Q5] and [UID:0001P0] support naming global `0x0067a7ec` as `Socket *g_packetSender`.

## Source-Facing Signature And Name

Recommended source-facing method:

```cpp
void ClanStatusPane::SendClanLeaveResponse(bool confirmed)
```

Rationale:

- The source name `SendClanLeaveResponse` remains the clearest descriptive name. It distinguishes this response helper from [UID:00021H] `SendClanLeaveRequestPacket`.
- The parameter should be semantic, not generated. `confirmed` is the best high-probability argument name because the two callers are confirm and cancel callbacks and pass only `1` and `0`.
- A byte-exact alternative is `unsigned char response`. I reject it as the primary source-facing signature because it preserves decompiler shape but loses the UI-level boolean semantics proven by the only two callers.
- `accepted`, `accept`, and `declined` are weaker than `confirmed`: the UI text is a leave-confirm dialog, and the confirm/cancel callbacks are the direct evidence. `confirmed` names what the source callsite decides.
- `SendClanLeaveConfirmResponse` would be more verbose and is not necessary because the existing helper name already distinguishes request versus response by action byte and callsite.

The binary ABI still consumes one stack byte. A source `bool` parameter is compatible with the observed `push 1` / `push 0` callsites and the callee reading a byte-sized response value before writing it into the packet.

## Packet Layout Validation

The validated packet layout is:

```text
byte 0: 0x4b  clan packet opcode
byte 1: 0x03  clan leave subtype
byte 2: 0x01  leave response action
byte 3: 0/1   cancel/confirm response byte
```

Rejected alternatives:

- `byte 2 == 1` as a length/count: rejected because the sender length is a separate literal `4`, and neighboring clan helpers use the third byte as an action.
- `byte 3` as a generic state code: possible at protocol level, but the only source callers provide a boolean confirm/cancel decision. Source-facing reconstruction should expose that as `confirmed`.
- `{0x4b, 3, 1}` as an independent request plus trailing byte padding: rejected because byte 3 is passed from the caller and the send length is exactly 4.

The explicit clear after byte 3 is not sent because the send length is 4. It is a local packet-buffer terminator/scratch byte, consistent with the shared one-byte writer behavior.

## Helper And Global Names

Recommended support naming:

```cpp
PacketBufferWriteUInt8(value, out);
g_packetSender->QueueAndSendPacket(packet, length);
extern Socket *g_packetSender;
```

Specific resolutions:

- `0x00575380`: `PacketBufferWriteUInt8`. The support docs identify this family as scalar big-endian packet-buffer write helpers; this member writes one byte and clears the following scratch byte. A shorter spelling like `WriteByte` is plausible, but the PacketBuffer support pages already prefer the unsigned-width naming.
- `0x00574bb0`: `Socket::QueueAndSendPacket`. The support docs show a `Socket` owner, queue allocation/copy behavior, trailing zero append, and command posting rather than final transport framing. `SendPacket` alone is too broad; `QueueAndSendPacket` preserves the observed role.
- `0x0067a7ec`: `Socket *g_packetSender`. The global support pages document many packet send xrefs and Socket constructor/destructor ownership. Generated aliases tied to unrelated feature packets should remain rejected.

These support names are sufficiently resolved for a first-draft target reconstruction. Remaining uncertainty is exact original spelling only, not role or source placement.

## Ownership And Source Placement

Ranked ownership recommendation:

1. [UID:00002K] `ClanStatusPane`: accept as canonical owner. Both callers materialize `g_pClanStatusPane` in `ECX` immediately before calling `0x00485700`, the helper belongs to the status-pane leave workflow, and [UID:00010H] already owns status-row packet behavior under `ClanStatusPane`.
2. [UID:0000I8] `Clan`: keep as source file route only. The emitted implementation should still land in `social/Clan.cpp`, but file-level ownership is less precise than the class member evidence.
3. [UID:00002I] `ClanLeaveConfirmDialog`: reject as canonical owner. The dialog callbacks provide the boolean decision but deliberately route through the status pane singleton.
4. PacketBuffer, Socket, and `g_packetSender`: reject as target owners. They are shared transport dependencies, not feature ownership.
5. [UID:00021H] and [UID:00021I] helper clusters: reject as owners. They validate the protocol pattern but do not own this live response method.

Support docs that should be updated if this recommendation is applied:

- [UID:00010D] target: change owner/emitter from `0000I8` to `00002K`, keep reconstructable true, add formal C++.
- [UID:00002K] `ClanStatusPane`: add `SendClanLeaveResponse(bool confirmed)` to the method/helper list or notes.
- [UID:0000I8] `Clan`: keep the function in the file contents list, but describe it as `ClanStatusPane::SendClanLeaveResponse`, not a loose helper.
- [UID:00002I], [UID:0002O7], and [UID:0002O8]: update callback call shape to member syntax.

## First-Draft C++ Recommendation

The item is reconstructable and now clears the confidence gate. Recommended formal C++ block:

```cpp
void ClanStatusPane::SendClanLeaveResponse(bool confirmed)
{
    unsigned char packet[5];

    PacketBufferWriteUInt8(0x4b, &packet[0]);
    PacketBufferWriteUInt8(3, &packet[1]);
    PacketBufferWriteUInt8(1, &packet[2]);
    PacketBufferWriteUInt8(confirmed ? 1 : 0, &packet[3]);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);
}
```

If the project prefers protocol-byte signatures over semantic booleans in packet helpers, use this mechanically equivalent variant:

```cpp
void ClanStatusPane::SendClanLeaveResponse(unsigned char response)
{
    unsigned char packet[5];

    PacketBufferWriteUInt8(0x4b, &packet[0]);
    PacketBufferWriteUInt8(3, &packet[1]);
    PacketBufferWriteUInt8(1, &packet[2]);
    PacketBufferWriteUInt8(response, &packet[3]);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);
}
```

I recommend the `bool confirmed` version as the source-facing first draft because both direct callers are boolean UI decisions.

Callback support C++ should become:

```cpp
void ClanLeaveConfirmDialog::OnConfirm()
{
    g_pClanStatusPane->SendClanLeaveResponse(true);
}

void ClanLeaveConfirmDialog::OnCancel()
{
    g_pClanStatusPane->SendClanLeaveResponse(false);
}
```

This replaces the current file-helper call shape `SendClanLeaveResponse(g_pClanStatusPane, 1/0)`.

## Heuristic / Inference Reanalysis And Validation

The main prior uncertainty was whether `SendClanLeaveResponse` was a file-local packet helper or a method-like helper whose `this` pointer was optimized away inside the callee. Reanalysis favors the method interpretation.

Evidence for method shape:

- Both callsites load `g_pClanStatusPane` into `ECX` immediately before pushing the response byte and calling `0x00485700`.
- The callee does not read `ECX`, which explains why decompilers present it as a one-argument `stdcall` or plain helper. That is a compiler/decompiler artifact, not enough to erase the source call shape at the callsites.
- A true one-argument free helper would not need the `ECX` load. A true two-argument free helper would push the status-pane pointer, not load it into the this register.
- The two direct callers are class virtual callbacks, making `g_pClanStatusPane->SendClanLeaveResponse(...)` source-plausible and consistent with the UI object routing.
- The neighboring [UID:00010H] row-action helper is already `ClanStatusPane`-owned, supporting a narrow class owner for status-pane packet emission.

Rejected source-shape alternatives:

- `void SendClanLeaveResponse(unsigned char response)`: rejected as source-facing primary because it does not explain the otherwise dead `ECX = g_pClanStatusPane` setup at every caller.
- `void SendClanLeaveResponse(ClanStatusPane *pane, unsigned char response)`: rejected because the pointer is not pushed and the callee does not receive a normal stack pointer argument.
- `void ClanLeaveConfirmDialog::SendClanLeaveResponse(bool confirmed)`: rejected because the callers route through the global status pane pointer, not through `this`.
- No-code/compiler-glue treatment: rejected because this is a real, non-EH, non-thunk function with direct feature behavior, direct callers, and a stable source file route.

The remaining uncertainty is exact original spelling of shared support helpers and whether the original parameter was spelled `bool`, `BYTE`, `unsigned char`, or `int`. That uncertainty affects polish, not reconstructability. The role and source shape are strong enough for first-draft C++.

Score impact:

- Completion improves from 84 to 88 because the formal C++ block can be populated, callback call shape is resolved, and helper/global roles are no longer open target blockers.
- Confidence improves from 90 to 92 because the callsite ABI, packet family, and support docs mutually reinforce the reconstruction. I do not recommend a higher confidence score because live IDA MCP could not be queried in this session and helper original spellings remain inferred.

## Coverage Replacement Text

Do not edit `by-memory/-coverage-report.md` directly. If the supervisor applies this report, replace the current [UID:00010D] row with:

```text
    - [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md) : reconstructable : 88% : very strong : B014 2026-06-19 source-quality reanalysis resolves this as `ClanStatusPane::SendClanLeaveResponse(bool confirmed)` rather than a loose file helper, based on both callers loading `g_pClanStatusPane` into ECX before pushing response byte `1`/`0`; validates packet bytes `{0x4b, 3, 1, response}` where subtype `3` is clan leave and action `1` is confirm/cancel response; names `0x00575380` as `PacketBufferWriteUInt8`, `0x00574bb0` as Socket `QueueAndSendPacket`, and `0x0067a7ec` as `Socket *g_packetSender`; keeps source route through [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md) to `social/Clan.cpp`; and marks first-draft C++ ready with callback callsites updated to `g_pClanStatusPane->SendClanLeaveResponse(true/false)`.
```

If generated route tables are updated manually before regeneration, the target should use:

```text
owner: 00002K
emitter: 00002K
generated path: auto-generated/NexusTK/social/Clan.cpp
```

## Final Recommendation

Apply this as a source-ready `ClanStatusPane` method, not as a file-only helper. Keep the public descriptive name `SendClanLeaveResponse`, use `confirmed` as the semantic argument, update confirm/cancel callback drafts to member-call syntax, and retain the shared support helper names from the PacketBuffer, Socket, and `g_packetSender` support docs.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/00010D-SendClanLeaveResponse-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"00010D"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
