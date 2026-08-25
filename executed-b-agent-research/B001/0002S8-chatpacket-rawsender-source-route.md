** TARGET-REPORT-UID:0002S8 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002S8 ChatPacketRawSender Raw Sender Source-Route Research

Assignment: `B001-goal2-chatpacket-raw-sender-source-route-0002S8-20260616`  
Target: [UID:0002S8] `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSender.md`  
Report-only scope: no by-* docs, generated reports, IDA DB, or `by-memory/-coverage-report.md` were edited.

## Final Recommendation

Reclassify [UID:0002S8] as a documented no-route raw code island, not an emitting Chatting helper.

Recommended target disposition:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE: blank
```

Recommended filename:

```text
by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md
```

Reason: the bytes are a real source-authored NexusTK packet builder, but live IDA and direct PE scans found no IDA function object, no inbound xrefs, no rel32 branch/call targets, and no absolute VA/RVA pointer hits to the body or any address inside the body. The current Chatting/ChatInputPane route is behaviorally plausible, but it is not an emitting source route. Existing no-route precedents such as [UID:0003VT] `SpellFourArgsDirectArgumentPacketRaw` and [UID:0003VS] `TextDialogUnreferencedSubmitPacketRaw` use `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and `ignored/non-emitting` coverage despite clear source-shaped packet bodies. [UID:0002S8] matches that evidence pattern.

No split is needed. The target body is exactly `0x005b37f0-0x005b38d5`; the adjacent bytes are already alignment padding or separate raw/modeled bodies.

Do not classify the body as compiler-generated, padding, or runtime-library code. It contains application packet constants, UTF-16 conversion, packet-buffer writes, and a socket-send dependency. The correct classification is source-shaped retained/unreferenced raw island with no proven source-emission owner.

## Evidence Checked

### Current Documentation State

Current target metadata:

```text
COMPLETION:82
CONFIDENCE:86
CANONICAL_OWNER:0000I5
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000I5
```

Current coverage row classifies it as:

```text
raw packet helper | ChatPacketRawSender : reconstructable : 82% : strong
```

Current generated memory coverage routes it to:

```text
auto-generated/NexusTK/social/Chatting.cpp
```

That generated route is stale if the supervisor accepts this recommendation.

### Exact Boundary

Live IDA MCP and raw PE byte reads agree on the boundaries:

| Range | Classification | Evidence |
| --- | --- | --- |
| `0x005b37ea-0x005b37f0` | padding | Six `0xcc` bytes after [UID:0001MB] `SayInputPane` submit. |
| `0x005b37f0-0x005b38d5` | target body | `0xe5` bytes of decoded stack-cookie packet-builder code. |
| `0x005b38d5-0x005b38e0` | padding | Eleven `0xcc` bytes before [UID:0002S9] `ChatInputPaneRawConstructor`. |

IDA instruction boundary:

```text
0x005b37f0  push ebp
...
0x005b38cd  retn 4
0x005b38d0  call ___report_rangecheckfailure
0x005b38d5  align 10h
```

There is no internal split point. The range-check tail at `0x005b38d0-0x005b38d5` belongs to the same compiler-instrumented source body. The padding before and after the body should remain separate ignored rows.

### IDA Function And Xref Inventory

IDA function lookup:

| Address | IDA result |
| --- | --- |
| `0x005b37ea` | not a function |
| `0x005b37f0` | not a function |
| `0x005b38d5` | not a function |
| `0x005b38e0` | not a function |
| `0x005b3940` | `sub_5B3940`, size `0x100` |
| `0x005b3a40` | `sub_5B3A40`, size `0x17a` |

IDA function inventory for the local corridor contains functions at:

```text
0x005b34d0, 0x005b3570, 0x005b3670, 0x005b3940, 0x005b3a40
```

It contains no function at `0x005b37f0` or `0x005b38e0`.

IDA xref checks:

| Target | Xrefs |
| --- | --- |
| `0x005b37f0` | none |
| `0x005b38d5` | none |
| `0x005b38e0` | none |
| `0x005b3940` | data xref at `0x0062fc40` |
| `0x005b3a40` | data xref at `0x0062fc30` |

The neighboring modeled ChatInputPane methods have vtable evidence. [UID:0002S8] does not.

### Raw PE Liveness Scan

Raw executable checked:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
ImageBase: 0x00400000
Target RVA: 0x001b37f0
Target raw file offset: 0x001b2bf0
```

Whole-image scan results:

| Scan | Result |
| --- | --- |
| Absolute little-endian VA `0x005b37f0` | 0 hits |
| Little-endian RVA `0x001b37f0` | 0 hits |
| rel32 `E8` direct calls to `0x005b37f0` | 0 hits |
| rel32 `E9` direct jumps to `0x005b37f0` | 0 hits |
| Absolute VA values inside `0x005b37f0-0x005b38d5` | 0 hits |
| rel32 `E8`/`E9` branch targets inside `0x005b37f0-0x005b38d5` | 0 hits |
| PE bytes for the target | match IDA bytes exactly |

This rejects hidden static direct callers, function-pointer table entries, jump-table entries, and data pointers in the shipped PE image.

### Packet Body Shape

The target is still source-shaped application code:

| Address | Operation | Meaning |
| --- | --- | --- |
| `0x005b3804` | `mov esi, [ebp+8]` | one wide-string argument |
| `0x005b3808` | `call sub_516030` | packet/buffer setup helper |
| `0x005b3816` | `push 0Eh; call sub_575380` | writes packet opcode `0x0e` |
| `0x005b3824` | `push 0; call sub_575380` | writes subtype `0` |
| `0x005b3830-0x005b383c` | UTF-16 length loop | measures source text |
| `0x005b385b` | `WideCharToMultiByte` | converts UTF-16 to MBCS payload |
| `0x005b387b` | `call sub_575380` | writes payload length |
| `0x005b3894` | `call sub_516220` | copies payload to packet+3 |
| `0x005b38a5` | `mov ecx, dword_67A7EC` | reads `g_packetSender` |
| `0x005b38bb` | `call sub_574BB0` | queues/sends `payload_len + 3` bytes |
| `0x005b38cd` | `retn 4` | one-argument callee cleanup |

Packet layout:

```text
packet[0] = 0x0e
packet[1] = 0
packet[2] = converted_payload_length
packet[3..] = MBCS payload
send length = converted_payload_length + 3
```

The stack cookie and `___report_rangecheckfailure` are compiler instrumentation around a source-authored packet builder. They do not make the range compiler-generated.

## Neighbor And Dependency Analysis

### SayInputPane Boundary

[UID:0001MB] `0x005b34d0-0x005b37ea.SayInputPane` contains active modeled submit logic at `0x005b3670-0x005b37ea`. It sends opcode `0x0e`, subtype `0`, but also includes pane-specific state gates, text reads, password guard, sanitizer, and history handling. It has a vtable data xref at `0x0062fba4`.

There is no fallthrough or call from SayInputPane into [UID:0002S8]. The six `0xcc` bytes at `0x005b37ea-0x005b37f0` separate them.

Decision: reject SayInputPane/SayInputPanes ownership.

### ChatInputPane Boundary

[UID:0002S9] `0x005b38e0-0x005b3935.ChatInputPaneRawConstructor` starts after eleven `0xcc` bytes. [UID:0001MC] `ChatInputPane` has modeled functions at `0x005b3940` and `0x005b3a40`; `0x005b3a40` is the active virtual submit/send method and has a vtable xref at `0x0062fc30`.

The ChatInputPane submit method sends the same default-chat opcode/subtype family, but it is a full UI handler. It does not call [UID:0002S8] in IDA or in the raw PE scan.

Decision: ChatInputPane is the best semantic neighborhood if a future route is found, but current evidence supports only a relationship note, not class ownership or emission.

### ShoutInputPane Contrast

[UID:0001MF] `0x005b4260-0x005b43bc.ShoutInputPane` is an active virtual submit handler with vtable pointer `0x0062fd48`. It sends opcode `0x0e`, subtype `1`.

Decision: reject Shout ownership. [UID:0002S8] sends subtype `0`.

### Socket / QueueAndSendPacket / g_packetSender

[UID:0001HU] `QueueAndSendPacket` at `0x00574bb0` is an active Socket helper with hundreds of callers. [UID:0000Q5] `g_packetSender` documents `dword_67A7EC` as shared socket state with broad feature use.

[UID:0002S8] calls these as dependencies. Shared sender use does not route feature-specific packet construction to Socket ownership.

Decision: reject Socket, `g_packetSender`, and generic network/source owner routes.

### ProtocolSend / Packet Centralization

The source-tree/network notes warn against inferring one monolithic packet-source owner from `QueueAndSendPacket`. Feature packet builders should stay feature-owned when a route exists. Here no feature route exists, so the correct fallback is no-owner non-emitting, not ProtocolSend.

Decision: reject ProtocolSend/source-centralization ownership.

## Ranked Owner / Route Decision

1. `NONE` / non-emitting no-route raw island: accepted. It fits the static evidence and existing no-route raw packet precedents.
2. [UID:0000I5] `Chatting` file: plausible semantic neighborhood, rejected as emitter/owner because there is no caller, pointer, function, vtable, or source-route evidence.
3. [UID:00001Q] `ChatInputPane` class: plausible future owner if a route appears, rejected now because the body has no `this`, no vtable slot, no class field access, and no caller.
4. [UID:0000C3]/[UID:0000N9] `SayInputPane` / `SayInputPanes`: rejected; subtype and adjacency are not enough, and active Say submit does not call it.
5. [UID:0000DD]/[UID:0000NS] Socket and [UID:0000Q5] `g_packetSender`: rejected as dependencies.
6. ProtocolSend or generic network packet owner: rejected; no static route and contrary to feature-packet source routing rules.
7. Compiler-generated/runtime artifact: rejected; the body is source-authored packet logic with compiler instrumentation.

## Final C++ Eligibility

Not eligible for final C++.

Blockers resolved:

- Exact bytes and boundaries are resolved.
- Padding on both sides is resolved.
- Packet opcode/subtype/payload layout is resolved.
- Socket-send dependency is resolved.
- Compiler-generated versus source-authored treatment is resolved: source-authored body with compiler instrumentation.

Blockers that remain and materially prevent final C++:

- No static liveness route: IDA and raw PE scans found no caller or pointer into the range.
- No recovered source helper name: `ChatPacketRawSender` is descriptive, not proven.
- No recovered source placement: Chatting/ChatInputPane is a likely semantic neighborhood, but not an emitting owner.
- Helper APIs still lack final source names: `sub_516030`, `sub_516220`, `sub_575380`, and `sub_574BB0` are behaviorally understood but not source-named enough for final C++.

Because these blockers were investigated and cannot be resolved safely from static evidence, `85/88` is appropriate. Do not raise above 85/88 without a new caller, pointer, runtime trace, or authoritative source-name/source-route evidence.

## Exact Supervisor Edits

### 1. Rename target page

> Executable block R001 was removed from this report and preserved verbatim in [0002S8-chatpacket-rawsender-source-route-removed.md](0002S8-chatpacket-rawsender-source-route-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor does not want a filename rename in this batch, keep the old filename but still apply the metadata and non-emitting coverage disposition. The source-route recommendation does not depend on the filename.

### 2. Target metadata replacement

In the renamed target page:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Set final C++ fields blank. Add a disposition note:

```text
2026-06-16 B001 live IDA/raw PE audit classifies this as a source-authored but no-route raw packet island. The body builds opcode 0x0e subtype 0 from one wide-string argument and sends through g_packetSender, but IDA has no function object/xrefs and raw PE scanning found no VA/RVA pointer or rel32 branch/call target into 0x005b37f0-0x005b38d5. Keep non-emitting unless a caller/pointer/runtime route appears.
```

### 3. Support doc edits

`by-file/Chatting.md`

- Replace the `ChatInputPane` proposed-content reference to `raw packet helper [UID:0002S8]` with:

```markdown
adjacent no-route raw packet island [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md), raw constructor [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md), confirmed submit/history block [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
```

- Add boundary note:

```markdown
2026-06-16 B001 live IDA/raw PE scan found no IDA function, inbound xref, VA/RVA pointer, or rel32 branch/call route to [UID:0002S8]. Treat it as adjacent non-emitting packet evidence, not as a Chatting-emitted source helper, unless a caller/pointer/runtime route appears.
```

- Remove [UID:0002S8] from any "emitted child" wording. Keep it only as related evidence.

`by-class/ChatInputPane.md`

- Change the method-table row from `raw packet helper` to:

```markdown
| adjacent no-route raw packet island | [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) | Non-emitting source-shaped opcode `0x0e` subtype `0` packet body immediately before the raw constructor; no `this`, vtable, caller, pointer, or class-field route was found in the 2026-06-16 B001 IDA/raw PE audit. |
```

- Update the assignment/history note that currently says it was attached as a raw child: state that it was reclassified as related non-emitting evidence.

`by-memory/0x005b3940-0x005b3bba.ChatInputPane.md`

- Replace the related range row with:

```markdown
| [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) | adjacent no-route raw packet island | Non-emitting opcode `0x0e` subtype `0` packet primitive immediately before the raw constructor; `0x005b3a40` remains the active virtual ChatInputPane submit/send method. |
```

`by-memory/0x005b34d0-0x005b37ea.SayInputPane.md`

- Replace the padding wording:

```markdown
| `0x005b37ea-0x005b37f0` | alignment padding | Six `0xcc` bytes before adjacent no-route chat packet raw island [UID:0002S8]. |
```

`by-memory/-ignored.md`

- In the SayInputPane neighborhood evidence, replace "before raw adjacent `ChatInputPane` constructor-shaped bytes" with:

```markdown
before adjacent no-route chat packet raw island [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md).
```

- In the ChatInputPane neighborhood evidence, update the [UID:0002S8] link to the renamed path and mention non-emitting no-route classification:

```markdown
[UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) ends at `0x005b38d5` and is classified as a non-emitting no-route raw packet island by B001's 2026-06-16 IDA/raw PE audit.
```

### 4. Coverage report replacement rows

Replace the target row in `by-memory/-coverage-report.md` with:

```markdown
    - [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) 0x005b37f0-0x005b38d5 | no-route raw code island | ChatPacketRawSenderNoRouteRaw : ignored/non-emitting : 85% : strong : Source-shaped default chat packet body retained without a proven source route; B001 2026-06-16 live IDA/raw PE audit confirms exact `0xe5`-byte body, no IDA function, no inbound xrefs, no VA/RVA pointer hits, no rel32 call/jump hits to the body or any interior address, opcode `0x0e` subtype `0`, one-argument UTF-16-to-MBCS length-prefixed payload builder, `g_packetSender`/`QueueAndSendPacket` dependency, and comparison against SayInputPane/ChatInputPane/ShoutInputPane submit handlers; keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/final C++ unless a caller/pointer/runtime route appears.
```

Replace the two nearby ignored padding rows only if the supervisor is touching coverage wording for this batch:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b37ea-0x005b37f0 | padding | SayInputPane submit to no-route chat packet raw island alignment : ignored : 100% : strong : B001 2026-06-16 IDA/PE byte audit confirms six `0xcc` bytes after [UID:0001MB] and before [UID:0002S8] raw no-route body at `0x005b37f0`.
```

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b38d5-0x005b38e0 | padding | no-route chat packet raw island to ChatInputPane constructor alignment : ignored : 100% : strong : B001 2026-06-16 IDA/PE byte audit confirms eleven `0xcc` bytes after [UID:0002S8] raw no-route body and before [UID:0002S9] raw constructor at `0x005b38e0`.
```

### 5. Generated output

After metadata changes, remove the stale generated route on the next autogen pass. Expected change:

```text
auto-generated/NexusTK/social/Chatting.cpp no longer emits [UID:0002S8].
```

Do not add a replacement generated C++ source file for [UID:0002S8].

## Validation Plan

After supervisor applies the recommended edits:

> Executable block R002 was removed from this report and preserved verbatim in [0002S8-chatpacket-rawsender-source-route-removed.md](0002S8-chatpacket-rawsender-source-route-removed.md). The archived block is non-authoritative and must not be executed.

Expected validation outcome:

- [UID:0002S8] validates as non-emitting at `85/88`.
- Coverage report has no overlap or missing-row issues.
- `memory_ranges.py report` keeps the target body and neighboring padding ranges distinct.
- Generated memory coverage no longer lists [UID:0002S8] as emitted to `auto-generated/NexusTK/social/Chatting.cpp`.
- [UID:0002S8] leaves Low_Completion while remaining below final-C++ eligibility.

## Work Performed

Created/updated only this report:

```text
tools/leaser/Agents/Agent-B001/research/0002S8-chatpacket-rawsender-source-route.md
```

No by-* files, generated files, coverage report, or IDA DB were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002S8-chatpacket-rawsender-source-route.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002S8"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002S8-chatpacket-rawsender-source-route-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002S8-chatpacket-rawsender-source-route.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002S8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
