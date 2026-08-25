** TARGET-REPORT-UID:0003VS **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003VS **
# Agent-B007 Research Report: [UID:0003VS] TextDialogUnreferencedSubmitPacketRaw

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality.md`

Target path: `source-3/project-documentation/by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md`

Assignment: `B007-goal2-textdialog-submit-packet-raw-source-quality-0003VS-20260619`

Status: FINISHED research pass. Report-only; no by-* docs, generated files, IDA DB, or `by-memory/-coverage-report.md` were edited.

## Final Recommendation

Keep [UID:0003VS] as a non-emitting no-route raw code island.

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE:[[[]]]
```

Disposition:

- Do not promote this target to `TextDialog` ownership/emission now.
- Do not populate formal C++ now.
- Preserve it as source-shaped retained/dead/unrouted packet code, not padding and not compiler glue.
- Best descriptive name if a future route is found: `TextDialog::SendTextReplyPacket(const wchar_t *text)` or `TextDialog::SendSubmitTextPacket(const wchar_t *text)`. For current documentation, keep the safer no-route label `TextDialogUnreferencedSubmitPacketRaw`.

Reason:

- The bytes at `0x00553350-0x00553495` are definitely a complete stack-cookie protected opcode `0x3a` text-submit packet sender.
- Current route evidence still proves no caller, pointer, vtable slot, switch-table branch, direct `rel32` branch/call, absolute VA pointer, or real RVA pointer route into the raw body.
- The strongest semantic owner if forced would be [UID:0000EL] `TextDialog`, but semantic adjacency and field-layout similarity are not sufficient to emit unreferenced code.

## Target State

Current target metadata before this report:

```text
UID:0003VS
COMPLETION:85
CONFIDENCE:86
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Current target status is broadly correct but too thin. It records the no-route raw-island disposition, the opcode `0x3a` body shape, and the accepted B001 split decision, but it should add the stronger B007 raw PE route search, packet layout, conversion semantics, owner rejection ranking, and historical scratch-report correction from this pass.

## Evidence Checked

Instructions and research guidance checked:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B007/goal.md`

Target and immediate support docs checked:

- `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md`
- `by-memory/0x00552110-0x005534a0.TextDialogCore.md`
- `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md`
- `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md`
- `by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md`
- `by-class/TextDialog.md`
- `by-file/TextDialog.md`
- `by-memory/0x00622954-0x006229f0.TextDialogVtableData.md`
- `by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md`
- `by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
- `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`
- `by-project-structure/proposed-source-tree.md`
- `auto-generated/-ag-memory-coverage.md`

Prior report evidence checked:

- `tools/leaser/Agents/Agent-B001/research/executed/older/0001FJ-textdialog-core-source-quality.md`
- `tools/leaser/Agents/Agent-B001/research/scratch/0001FJ-textdialog-core-source-split-audit.superseded-by-quality.md`

Analogous no-route/raw packet helper docs checked:

- `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md`
- `by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md`
- `by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md`

Raw executable evidence checked:

- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- PE section/RVA mapping.
- Raw bytes for `0x00553338-0x005534a0`.
- Capstone disassembly for `0x00553350-0x00553495`.
- Absolute VA, RVA, direct `rel32` call/jump, and near conditional branch scans into the raw range.
- Context disassembly for the only RVA-like false-positive value that fell inside the raw range.

IDA MCP status:

- Attempted `http://127.0.0.1:13337/mcp`.
- Result: unavailable from this session, `Unable to connect to the remote server`.
- Therefore current pass uses raw PE evidence plus existing by-* and executed B001 IDA MCP evidence. Existing B001 evidence already records live IDA no-function/no-xref status; B007 independently reconfirmed route absence at raw PE level.

## Boundary, Adjacency, And Route Evidence

Physical layout:

```text
0x00553338-0x00553348  TextDialog action-handler switch table
0x00553348-0x00553350  eight 0xcc alignment bytes
0x00553350-0x00553495  source-shaped no-route raw packet body
0x00553495-0x005534a0  eleven 0xcc alignment bytes
0x005534a0-0x00553609  NexonclubProxyDialog reply callback
```

Raw bytes checked for the local span:

```text
00553338: be 31 55 00 aa 31 55 00 b4 31 55 00 16 33 55 00
00553348: cc cc cc cc cc cc cc cc 55 8b ec 81 ec 08 03 00
00553358: 00 a1 24 2f 67 00 33 c5 89 45 fc 53 56 8b 75 08
...
00553488: 07 00 8b e5 5d c2 04 00 e8 c0 41 07 00 cc cc cc
00553498: cc cc cc cc cc cc cc cc
```

Switch table:

- The table at `0x00553338-0x00553348` contains four little-endian targets:
  - `0x005531be`
  - `0x005531aa`
  - `0x005531b4`
  - `0x00553316`
- Every table target is inside [UID:0003VR] `TextDialogHandleDialogAction`.
- No table entry targets `0x00553350` or any address inside `0x00553350-0x00553495`.
- The following `0x00553348-0x00553350` padding separates the switch table from the raw island, so the raw island is not a fall-through switch case.

Route search results from raw PE:

```text
REFS 0x00553338: abs32 at 0x005531a6, total 1; rel_calljmp total 0
REFS 0x00553350: abs32 total 0; rva32 total 0; rel_calljmp total 0
REFS 0x00553495: abs32 total 0; rva32 total 0; rel_calljmp total 0
REFS 0x005534a0: abs32 at 0x00553898, total 1; rel_calljmp total 0
REFS 0x00553610: rel_calljmp at 0x0054ca33, total 1
```

Whole-raw-range route scan for `0x00553350 <= target < 0x00553495`:

```text
abs32 into raw range total=0
rva32 into raw range total=1
rel32 branch/call into raw range total=0
external abs32=0
external rva32=1
external rel32=0
```

The one RVA-like hit is not a route:

- The RVA-like value resolves to `0x00553407`, but its file location is instruction bytes at `0x0047a24b`.
- Disassembly at `0x0047a24b` is `call 0x005cd657`; the matching bytes are the call displacement, not a pointer.
- This is a false-positive 4-byte immediate pattern and should not be treated as a route to [UID:0003VS].

Positive controls from the same scan:

- `0x00553338` has the expected action-handler switch-table reference.
- `0x005534a0` has the expected Nexonclub proxy callback pointer installation in the proxy constructor.
- `0x00553610` has the expected direct constructor call from the proxy allocation wrapper.

Conclusion:

- Current route evidence is stronger than the target page's current wording. It is not only "no xrefs to entry"; it is no entry pointer and no branch/call route into any address of the raw body, with the only RVA-like hit rejected by instruction context.

## Raw Body Behavior

Disassembly facts for `0x00553350-0x00553495`:

- Prologue: `push ebp; mov ebp, esp; sub esp, 0x308`.
- Stack cookie uses global `0x00672f24`, saves cookie at `[ebp-0x04]`, and checks through `0x005c772f`.
- `ecx` is saved as `edi`, so if this body had a route it would be a `thiscall` helper.
- `[ebp+0x08]` is the supplied wide-character text pointer.
- The body returns with `ret 4` at `0x0055348d`.
- Range-check failure tail calls `0x005c7655` at `0x00553490`.

Local buffers and temporary state:

- `[ebp-0x304]`: 256-byte converted multibyte text buffer.
- `[ebp-0x204]`: packet stack buffer.
- `[ebp-0x308]`: preserved result of `GetMemoryMan` / memory-copy context for the later `MemmoveWrapper` call.

Callee identities and source-quality names:

| Address / import | Current role |
| --- | --- |
| `0x00516030` | [UID:0001BC] `GetMemoryMan`; called before payload copy, not a packet-buffer writer. |
| `0x00575380` | [UID:0003YJ] `PacketBufferWriteUInt8` / `PacketBufferWriteByte`. |
| `0x005753f0` | [UID:0003YJ] `PacketBufferWriteUInt32BE`. |
| `0x005753a0` | [UID:0003YJ] `PacketBufferWriteUInt16BE`. |
| import slot `0x0060d170` | `WideCharToMultiByte`. |
| `0x00516220` | [UID:0001BH] `MemmoveWrapper`, source-level payload copy. |
| `0x00574bb0` | [UID:0001HU] `QueueAndSendPacket`. |
| `0x005c772f` | security-cookie check. |
| `0x005c7655` | range-check failure. |

Packet layout produced by the raw body:

| Packet offset | Writer | Source | Best current meaning |
| --- | --- | --- | --- |
| `+0x00` | `PacketBufferWriteUInt8` | literal `0x3a` | dialog/message reply opcode |
| `+0x01` | `PacketBufferWriteUInt8` | byte `this+0x26c` | dialog reply type/subtype byte |
| `+0x02..+0x05` | `PacketBufferWriteUInt32BE` | dword `this+0x270` | dialog/session/object id |
| `+0x06..+0x07` | `PacketBufferWriteUInt16BE` | word `this+0x274` | dialog state/sequence word |
| `+0x08..+0x09` | `PacketBufferWriteUInt16BE` | word `this+0x276 + 1` | one-based page/index value |
| `+0x0a` | `PacketBufferWriteUInt8` | literal `2` | text-submit subtype/action |
| `+0x0b` | `PacketBufferWriteUInt8` | converted byte count | one-byte text length |
| `+0x0c...` | `MemmoveWrapper` | converted bytes | ANSI/MBCS text payload |

Text conversion semantics:

- The function manually measures the UTF-16 input length by walking 16-bit code units until a NUL terminator.
- The computed wide length is held in `ebx`, but the call passes only `movzx eax, bl` to `WideCharToMultiByte`.
- Therefore the source count supplied to `WideCharToMultiByte` is the low byte of the measured character count.
- This is likely safe only if the caller already limits text to 255 wide characters. The routed `TextDialogHandleDialogAction` submit case does perform a 255-character text-read limit before building its inline packet; this raw helper has no visible caller to prove the same precondition.
- `WideCharToMultiByte(0, 0, wideText, low8(wideCharCount), ansiBuffer, 0x100, 0, 0)` returns the converted byte count.
- If the converted byte count is `>= 0x100`, the body calls the range-check failure helper.
- It writes `ansiBuffer[convertedLength] = 0` for local safety.
- It writes `convertedLength` as the packet length byte at offset `+0x0b`.
- It copies exactly `convertedLength` payload bytes to packet offset `+0x0c`.
- It computes send length `convertedLength + 12`, range-checks that final index against `0x200`, writes a non-sent packet terminator at `packet[convertedLength + 12]`, then queues/sends exactly `convertedLength + 12` bytes.

Important source-quality correction:

- The final packet terminator is not transmitted. It is a scratch/safety byte outside the counted send length, consistent with PacketBuffer helper zero-terminator conventions elsewhere.

## Heuristic / Inference Reanalysis And Validation

### Raw Helper Status

Best conclusion: source-shaped no-route raw code island.

Evidence:

- The bytes are not `0xcc`, not a jump table, not embedded read-only data, and not compiler-generated destructor/thunk glue.
- The body contains game-specific dialog fields, packet opcode `0x3a`, PacketBuffer writes, text conversion, packet payload copy, `g_packetSender`, and `QueueAndSendPacket`.
- The body has normal source-shaped prologue/security-cookie/epilogue and a `ret 4`.

Rejection:

- Do not classify as padding, ignored switch data, or runtime library code.
- Do not classify as reconstructable emitting source without a route.

### Source-Facing Name

Current page name `TextDialogUnreferencedSubmitPacketRaw` remains acceptable for the no-route documentation state.

Best source-facing name if a future caller/pointer route is proven:

```cpp
void TextDialog::SendTextReplyPacket(const wchar_t *text);
```

Close alternative:

```cpp
void TextDialog::SendSubmitTextPacket(const wchar_t *text);
```

Why these are best:

- The function serializes the same typed-text reply packet as TextDialog action `1`.
- It takes the text as a parameter instead of reading the edit control itself.
- It is not a general dialog navigation helper and not a region-selection helper.

Rejected names:

- `TextDialog::HandleDialogAction`: wrong range and wrong calling shape. The real action handler ends at `0x00553338`.
- `TextDialog::SendRegionSelectionPacket`: stale generated/old documentation pollution; the real later callback at `0x005534a0` belongs to `NexonclubProxyDialog`.
- `DialogNavigationPacketHelpers::SendDialogPacketCurrent`: wrong packet shape; navigation helpers send fixed ten-byte previous/next/current packets and do not append text.
- `PacketBufferWriteString`: wrong owner; this body builds a feature packet and only calls PacketBuffer helpers.

Impact:

- The high-probability source name is good enough to document as a future-route candidate, but not enough to assign owner/emitter without reachability evidence.

### Type And Signature

If a route is ever proven, the best signature is:

```cpp
void __thiscall TextDialog::SendTextReplyPacket(const wchar_t *text);
```

Evidence:

- `ecx` is used as the object pointer.
- `[ebp+0x08]` is the single wide-string argument.
- The body returns no value and uses `ret 4`.

Current action:

- Do not write this as target formal C++ because the method has no route and no owner/emitter.

### Packet Field Names

Best current field-name direction for support docs:

| Offset | Best descriptive field name | Confidence |
| --- | --- | --- |
| `this+0x26c` | `m_dialogReplyType` or `m_dialogType` | medium |
| `this+0x270` | `m_dialogId` or `m_dialogSessionId` | medium |
| `this+0x274` | `m_dialogState` or `m_dialogSequence` | medium-low |
| `this+0x276` | `m_currentPageIndex` or `m_dialogPageIndex` | medium |

Reasoning:

- `DialogNavigationPacketHelpers.md` already documents the same fields as dialog type/subtype byte, dialog/session/object id, dialog state word, and current page/index word.
- The previous/next/current helpers decrement/increment/send `this+0x276`, proving page/index semantics.
- The typed-text packet sends `this+0x276 + 1`, so the network packet appears to use a one-based page/index value for text submit.

Open limit:

- Exact original member names remain unproven, and this target should not force final class field names alone. Recommend descriptive names in target/support docs, not final header names.

### Text Conversion Semantics

Best source-quality description:

- The raw helper converts a caller-supplied `const wchar_t *` to default-codepage multibyte bytes through `WideCharToMultiByte`.
- It uses a 256-byte local output buffer.
- It writes a one-byte converted byte length and sends no terminator byte.

Important caveat:

- The raw helper passes only `low8(wideCharCount)` as the source character count. This suggests the intended caller should already limit the text to 255 characters, matching the inline TextDialog action handler path. Without a caller, this precondition is inferred but not proven.

### Action-Handler Table Adjacency

Best conclusion:

- `0x00553350` is not an unmodeled fifth action-handler switch case.

Evidence:

- The switch table entries at `0x00553338-0x00553348` all target addresses inside `0x00553180-0x00553338`.
- Eight `0xcc` bytes sit between the switch table and the raw helper.
- Raw PE direct-branch scan found no direct branch into the raw body.

### Owner And Source Placement

Accepted disposition:

- `CANONICAL_OWNER:NONE`
- `EMITTER_UIDS:` blank

Owner ranking:

1. `NONE` / no-route non-emitting child: accepted.
   - Evidence: no function object in executed B001 IDA MCP evidence, no IDA xrefs in current docs, no raw PE abs32/RVA/direct-branch route into the body.
   - This preserves the raw facts without inventing an owner.

2. [UID:0000EL] `TextDialog` class: strongest rejected promotion candidate.
   - Evidence for: same physical island, same `this+0x26c/+0x270/+0x274/+0x276` field family, same opcode `0x3a` typed-text reply as action case `1`, and same source module context.
   - Evidence against: no caller, pointer, vtable slot, switch entry, or runtime route. [UID:0003VR] already builds the routed submit packet inline rather than calling this helper.
   - Decision: document as semantic neighborhood only. If a future route is found, promote here first.

3. [UID:0000OL] `TextDialog` file: rejected as direct owner.
   - Evidence for: file-level source context and address locality.
   - Evidence against: direct class owner would be more precise if the raw helper ever routes; current no-route state blocks both class and file emission.
   - Decision: support context only.

4. [UID:00009H]/[UID:0000LZ] `NexonclubProxyDialog`: rejected.
   - Evidence for: adjacent callback at `0x005534a0` also sends opcode `0x3a` text.
   - Evidence against: proxy constructor installs only `0x005534a0` at `0x00553898`; no pointer to `0x00553350`; the `0x00553495-0x005534a0` padding separates the raw island from the proxy callback.
   - Decision: do not attach [UID:0003VS] to proxy.

5. [UID:0001FG] `DialogNavigationPacketHelpers`: rejected.
   - Evidence for: same opcode family and same field offsets.
   - Evidence against: helper family is fixed navigation packets, not variable text; it lives at `0x0054cc30-0x0054ce0f` with direct callers.
   - Decision: related support only.

6. [UID:0000M8] `PacketBuffer`, [UID:0000DD] `Socket`, [UID:0000L7] `MemoryMan`: rejected.
   - Evidence for: their helpers are callees.
   - Evidence against: the target is feature-packet construction. PacketBuffer, Socket, and MemoryMan own infrastructure only.
   - Decision: callee/support docs only.

### Promotion Versus No-Code Decision

Promotion is not justified.

Exact no-code proof:

- Current by-* evidence from executed B001 report says IDA did not model a function at `0x00553350`.
- Current by-* evidence says no IDA xrefs to the raw entry were found.
- B007 raw PE scan found no absolute VA pointer to `0x00553350`, no direct `rel32` branch/call to `0x00553350`, and no route to `0x00553495`.
- B007 whole-range scan found no absolute VA pointer into the body and no direct branch/call into the body. The one RVA-like hit was a false-positive displacement for unrelated `call 0x005cd657` at `0x0047a24b`.
- The action-handler switch table does not target the raw body.
- The TextDialog vtable page routes `0x00553180`, not `0x00553350`.
- The Nexonclub proxy callback wrapper installs `0x005534a0`, not `0x00553350`.
- The routed TextDialog action handler already emits a typed-text packet inline, so there is no proven source call to an out-of-line submit helper.

Therefore final C++ must stay blank. Adding source for this no-route body would risk reconstructing dead/unreachable retained code as if it were a live source method.

### Historical Assumptions Corrected

- The scratch B001 split audit initially proposed `0x00553350-0x00553495.TextDialogRawStringReplyPacketHelper` as reconstructable TextDialog-owned source. That scratch-only recommendation is superseded.
- The executed B001 quality report and current by-* docs changed [UID:0003VS] to `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter, because no route is proven.
- B007 validates the later accepted no-route conclusion and strengthens it with raw PE route scans.
- Stale `TextDialog::SendRegionSelectionPacket` wording belongs to historical generated-output pollution around `0x005534a0`; it must not be applied to [UID:0003VS].

## Non-Emitting Source-Shape Sketch

This sketch is for behavior documentation only. Do not insert it into `RECONSTRUCTION_CPP CODE` while the target remains no-route/non-emitting.

```cpp
// Non-emitting sketch only.
// If a route is ever proven, the source shape is likely a TextDialog member helper.
void TextDialog::SendTextReplyPacket(const wchar_t *text)
{
    char converted[256];
    unsigned char packet[512];

    int wideChars = 0;
    while (text[wideChars] != 0)
        ++wideChars;

    PacketBufferWriteUInt8(0x3a, packet + 0);
    PacketBufferWriteUInt8(m_dialogReplyType, packet + 1);
    PacketBufferWriteUInt32BE(m_dialogId, packet + 2);
    PacketBufferWriteUInt16BE(m_dialogState, packet + 6);
    PacketBufferWriteUInt16BE(m_currentPageIndex + 1, packet + 8);
    PacketBufferWriteUInt8(2, packet + 10);

    int byteCount = WideCharToMultiByte(
        0,
        0,
        text,
        static_cast<unsigned char>(wideChars),
        converted,
        sizeof(converted),
        0,
        0);
    if (byteCount >= sizeof(converted))
        _report_rangecheckfailure();

    converted[byteCount] = 0;
    PacketBufferWriteUInt8(byteCount, packet + 11);
    memmove(packet + 12, converted, byteCount);

    int packetLength = byteCount + 12;
    if (packetLength >= sizeof(packet))
        _report_rangecheckfailure();

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(packet, packetLength);
}
```

Sketch limits:

- Member names are descriptive, not original-proof.
- The `static_cast<unsigned char>(wideChars)` models the observed `movzx eax, bl`; it may be an artifact of a caller-side 255-character precondition rather than desired high-level source.
- This sketch deliberately does not imply current emission.

## Score Recommendation

Recommended score:

```text
COMPLETION:88
CONFIDENCE:90
```

Rationale:

- Completion should rise from `85` to `88` because this pass resolves the main open source-quality questions: exact route search, action-table adjacency, packet layout, conversion semantics, callee naming, best future source name, owner rejection ranking, and formal no-code proof.
- Confidence should rise from `86` to `90` because raw PE route scans independently support the accepted no-route conclusion and positive controls show the scan is finding real nearby references.
- Confidence should not exceed `90` because IDA MCP was unavailable in this B007 session, original source name remains unproven, and no runtime trace was available.

Score cap:

- Do not score as source-ready emitter. The target is behaviorally well understood but intentionally non-emitting.
- Do not use code-entry thresholds; `RECONSTRUCTABLE:FALSE` and blank emitter make formal C++ ineligible regardless of score.

## Recommended Target Doc Changes

Apply these changes to `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md` after supervisor acceptance:

1. Update metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Preserve final C++ blank and add:

```text
Final C++ remains blank by target-specific no-code proof: no function object, no xrefs, no pointer/callback/vtable/switch route, and no raw PE VA/RVA/direct-branch route into the body are proven.
```

3. Add a detailed boundary/route section:

```text
The preceding `0x00553338-0x00553348` bytes are the `TextDialogHandleDialogAction` switch table with targets `0x005531be`, `0x005531aa`, `0x005531b4`, and `0x00553316`; every target is inside [UID:0003VR]. `0x00553348-0x00553350` is eight `0xcc` bytes. The raw helper starts after that padding at `0x00553350` and ends at the range-check tail `0x00553495`; `0x00553495-0x005534a0` is eleven `0xcc` bytes before [UID:0003GL].
```

4. Add B007 raw PE route-search evidence:

```text
B007 2026-06-19 raw PE route scan found no absolute VA pointer, no real RVA pointer, and no direct `rel32` call/jump/near-conditional branch route to `0x00553350` or into `0x00553350-0x00553495`. The only RVA-like value inside the body range appears inside an unrelated `call 0x005cd657` displacement at `0x0047a24b`, so it is not a route. Positive controls found the expected switch-table reference to `0x00553338` and the expected proxy callback pointer installation for `0x005534a0`.
```

5. Add packet layout table from this report.

6. Add conversion semantics:

```text
The helper measures the UTF-16 input manually, passes only the low byte of the measured wide-character count to `WideCharToMultiByte(0,0,...)`, converts into a 256-byte local buffer, range-checks converted byte count `< 0x100`, writes the converted length as one packet byte at offset `+0x0b`, copies the payload at `+0x0c`, writes a non-sent scratch terminator at `packet[convertedLength + 12]`, and queues exactly `convertedLength + 12` bytes.
```

7. Add owner rejection ranking:

```text
If a route is ever found, [UID:0000EL] `TextDialog` is the strongest owner candidate and a likely source-facing helper name would be `SendTextReplyPacket(const wchar_t *text)` or `SendSubmitTextPacket(const wchar_t *text)`. Current evidence still rejects promotion because [UID:0003VR] sends the live submit packet inline, the switch table does not target this body, the TextDialog vtable does not reference it, and the proxy constructor installs only `0x005534a0`, not this address.
```

8. Add historical-assumption note:

```text
The older scratch split-audit proposal to make this a TextDialog-owned reconstructable `TextDialogRawStringReplyPacketHelper` is superseded by the executed B001 quality report and B007 route scan. The body is source-shaped TextDialog-family code, but it remains no-route/non-emitting until a caller, pointer, vtable slot, callback wrapper, or runtime trace proves liveness.
```

## Recommended Support Doc Updates

Update `by-memory/0x00552110-0x005534a0.TextDialogCore.md`:

- Add one sentence to the [UID:0003VS] inventory/evidence noting B007's raw PE whole-range route scan and the false-positive RVA displacement rejection.
- No parent metadata change required.

Update `by-class/TextDialog.md`:

- Keep the method-map row as no-route/non-emitting.
- Expand the row or nearby note:

```text
If the raw island ever routes, the best inferred method role is a private `SendTextReplyPacket(const wchar_t *text)` helper. Current evidence rejects emission because the live virtual action handler sends typed text inline and no route to the raw body is proven.
```

- No score change required.

Update `by-file/TextDialog.md`:

- Preserve `TextDialog.cpp` as semantic module context.
- Add that B007 rechecked raw PE route evidence and still found no route into the raw island.
- No score change required.

Update `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md`:

- Add contrast with [UID:0003VS]:

```text
The following switch table at `0x00553338-0x00553348` belongs to this action handler and does not branch to the raw island at `0x00553350`. Action `1` builds the typed-text submit packet inline; no call to [UID:0003VS] is proven.
```

Update `by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md`:

- Add or keep a note that [UID:0003VS] is not one of the previous/next/current helpers; it is a no-route variable-text submit clone using the same dialog header field family.

Update `by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md`:

- Add negative boundary support:

```text
B007 raw PE scan found the proxy callback pointer at `0x00553898` for `0x005534a0` and no pointer/branch route to the preceding raw island at `0x00553350`; this preserves the proxy/TextDialog boundary.
```

Update `by-project-structure/proposed-source-tree.md`:

- Current line is correct. Optional addition:

```text
B007 2026-06-19 rechecked the local raw island and still found no route, so the `TextDialog` source file should not emit it unless future route evidence appears.
```

No direct updates required for `PacketBuffer`, `MemoryMan`, `QueueAndSendPacket`, or `g_packetSender` beyond cross-reference consistency; their current pages already support the callee/source names used in this report.

## Exact Coverage Row Text

Supervisor-owned replacement row for the [UID:0003VS] nested row in `source-3/project-documentation/by-memory/-coverage-report.md`:

```text
        - [UID:0003VS][0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw](by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md) 0x00553350-0x00553495 | no-route raw code island | TextDialogUnreferencedSubmitPacketRaw : ignored/non-emitting : 88% : very-strong : B007 2026-06-19 source-quality reanalysis confirms source-shaped opcode `0x3a` text-submit packet body but no owner/emitter promotion: executed B001 evidence found no IDA function object or xrefs; raw PE scan found no absolute VA pointer, no real RVA pointer, and no direct branch/call route to `0x00553350` or into `0x00553350-0x00553495`; the only RVA-like hit was an unrelated call-displacement false positive at `0x0047a24b`; action-handler switch table `0x00553338-0x00553348` targets only `0x005531be`/`0x005531aa`/`0x005531b4`/`0x00553316`; body writes opcode `0x3a`, dialog fields `this+0x26c/+0x270/+0x274/+0x276+1`, subtype byte `2`, one-byte converted text length, `WideCharToMultiByte` payload, and sends `convertedLength + 12` through `g_packetSender`/`QueueAndSendPacket`; keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++ unless a caller, pointer, vtable slot, callback wrapper, or runtime trace proves liveness.
```

Placement context: replace the existing [UID:0003VS] row nested under the [UID:0001FJ] `TextDialogCore` block, currently immediately after the `0x00553338-0x00553350` switch-table/padding row and before the `0x00553495-0x005534a0` padding row.

No parent [UID:0001FJ] coverage row change is required unless the supervisor wants to mention the B007 recheck in the parent summary.

## Validator Commands

No validators were run because this was a report-only pass and no by-* docs were edited.

Expected scoped validator commands after accepted implementation, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality-removed.md](0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the coverage row:

> Executable block R002 was removed from this report and preserved verbatim in [0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality-removed.md](0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: all edited files validate cleanly. If validator rewrites link/metadata ordering, preserve the no-route proof, packet-layout details, and owner-rejection facts from this report.

## IDA Rename, Type, And Comment Recommendations

Do not promote the raw body to a normal named source function in IDA solely for ownership/emission.

Safe analysis-only label/comment direction:

- Label at `0x00553350`: `TextDialog_UnreferencedSubmitPacketRaw_553350`
- Avoid final method name `TextDialog::SendTextReplyPacket` until a route is proven.

If a future route is found, candidate prototype:

```cpp
void __thiscall TextDialog::SendTextReplyPacket(const wchar_t *text);
```

Recommended comments:

- `0x00553338`: `TextDialogHandleDialogAction switch table; targets stay inside 0x00553180-0x00553338.`
- `0x00553348`: `alignment before no-route raw packet island.`
- `0x00553350`: `no-route TextDialog-family raw text-submit packet body; no xrefs/pointers proven.`
- `0x00553393`: `write dialog opcode 0x3a.`
- `0x005533a4`: `write dialog reply type byte from this+0x26c.`
- `0x005533b8`: `write dialog/session id from this+0x270 as big-endian dword.`
- `0x005533ca`: `write dialog state word from this+0x274.`
- `0x005533de`: `write one-based page/index from this+0x276 + 1.`
- `0x005533f3`: `write text-submit subtype 2.`
- `0x00553416`: `WideCharToMultiByte with low byte of measured wide length.`
- `0x00553435`: `write converted byte count at packet+0x0b.`
- `0x00553453`: `copy converted payload to packet+0x0c.`
- `0x0055347b`: `queue packet through g_packetSender; send length convertedLength + 12.`
- `0x00553495`: `alignment before NexonclubProxyDialog reply callback.`

## Open Questions And Closure

Open question: Is this a real original source helper?

- Best answer: likely yes, but retained/unrouted in the final binary. It is too source-shaped and game-specific to be compiler data, but no route proves it was live.
- Impact: no owner/emitter promotion; no formal C++.

Open question: What was the original helper name?

- Best answer if route later appears: `SendTextReplyPacket` or `SendSubmitTextPacket`.
- Impact: not a blocker for no-route classification; do not use a final method name in target metadata.

Open question: Should this be TextDialog-owned despite no route?

- Best answer: no. TextDialog is the strongest semantic candidate, but by-structure requires a defensible source/emitter route for source-bearing emission. This target lacks that route.
- Impact: keep `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`.

Open question: Is it a hidden switch case or callback?

- Best answer: no current evidence. Switch table does not target it, padding separates it, TextDialog vtable references the action handler only, and proxy callback install targets `0x005534a0`.
- Impact: supports no-code proof.

Open question: Does conversion send a NUL terminator?

- Best answer: no. It writes scratch terminators in both local converted buffer and packet buffer, but sends exactly `convertedLength + 12`.
- Impact: target/support docs should not describe an on-wire terminator byte.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality.md`

Modified:

- None outside Agent-B007 research.

Forbidden files:

- `by-memory/-coverage-report.md` was not edited.
- Target/support by-* docs were not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003VS","source_path":"executed-b-agent-research/B007/0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
