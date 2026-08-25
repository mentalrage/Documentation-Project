** TARGET-REPORT-UID:0002RY **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002RY SendBlockListenModePacket Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](../../../../../by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) as a reconstructable raw packet-helper item owned and emitted by [UID:0000HS][BlockListenInputPanes](../../../../../by-file/BlockListenInputPanes.md).
- Final disposition: source-authored, file-local `BlockListenInputPanes.cpp` helper behavior, but still a raw no-function/no-entry-route body. Do not merge it into the preceding switch table, the following add-prompt constructor, the modeled command dispatcher, the modeled add/delete handlers, or `ProtocolSend`.
- Required action if accepted: update the target and support docs with the exact boundary, packet, naming, ownership, and no-code proof below; replace the stale supervisor-owned `by-memory/-coverage-report.md` row; do not populate the target formal C++ block.
- Proposed target metadata: `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000HS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP CODE`.
- Confidence: high for bytes, packet layout, source module, and negative route evidence; still below final-audit because the original helper name and source-level call site are not proven.

## Supporting Research

## Target

- Target UID: `0002RY`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B008\research\0002RY-SendBlockListenModePacket-source-quality.md`
- Current scores and parent state before this report: `COMPLETION:85`, `CONFIDENCE:87`, owner/emitter [UID:0000HS][BlockListenInputPanes](../../../../../by-file/BlockListenInputPanes.md), reconstructable true, formal C++ blank.
- Current coverage state: `by-memory/-coverage-report.md` still has a stale `76%` row with an old live-MCP retry caveat, while the target page and `project-level/-auto-completion-stats.md` already show `85/87`.

## Executive Recommendation

The helper should remain a file-local raw packet helper in `NexusTK/social/BlockListenInputPanes.cpp`. The exact behavior is:

- allocate a small stack packet buffer;
- write byte `0x0d` through `sub_575380`, best current source-facing name `PacketBufferWriteUInt8`;
- write byte `0x01` through the same byte writer;
- write a local scratch terminator at the next stack byte;
- read `dword_67A7EC`, best current source-facing name `g_packetSender`, best current type `Socket *`;
- call `sub_574BB0`, best current source-facing name `QueueAndSendPacket` / `Socket::QueueAndSendPacket`, with explicit length `2`.

The packet is the fixed two-byte BlockListen packet-family request: opcode `0x0d`, subcommand `0x01`. The best protocol label is `BlockListen` opcode family with subcommand `ListOrModeRequest` or `RequestListOrMode`; the existing target/helper name `SendBlockListenModePacket` is acceptable as the stable documentation/search name. `SendBlockListenListRequestPacket` is semantically plausible but not stronger because no inbound response or original symbol proves "list request" over the current "mode" wording.

Formal C++ should remain blank. The target now clears the numeric code-entry gate, but the raw body has no current IDA function object and no proven call route. Emitting a callable source helper now would risk adding a source function whose liveness and integration point are unproven; the correct source-level representation may be a dead helper compiled into the original, an inline-equivalent packet path, or an unmodeled route not currently recovered.

## Supervisor Active Recheck

- This was a report-only assignment. I did not edit by-* docs or `by-memory/-coverage-report.md`.
- The assigned target does not need split repair. The existing half-open range `0x005b6c30-0x005b6c7c` is exact.
- Local PE recheck used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, image base `0x00400000`.
- Current session did not expose a live IDA MCP tool. For IDA database facts, this report relies on the already-recorded 2026-06-02, 2026-06-14, and 2026-06-15 IDA MCP evidence in the target, aggregate, and support pages, then independently rechecks raw bytes, disassembly, and route candidates from the PE with Capstone.

## Inference Research Guidance Check

`by-structure.md` requires narrow direct semantic ownership, source-quality investigation beyond the `85/85` threshold, exact range evidence, conservative `95+` scoring, and no C++ unless the item is reconstructable, routed to a valid emitter, clears the combined score gate, and has source-quality names/routes strong enough for final-output source. It also states that `EMITTER_UIDS` is output routing, not ownership, and that by-memory C++ must cover only the page's own exact range.

`inference_research.md` warns that source-file ownership without debug or map data is probabilistic and should be built from xrefs, callers/callees, function clustering, state ownership, and disconfirming evidence. For this helper, address adjacency alone is not enough, but the opcode family, sibling add/delete helpers, local block-list pane class cluster, proposed source tree, and lack of `ProtocolSend` evidence all point to `BlockListenInputPanes.cpp`.

Existing documentation was treated as evidence to recheck, not authority. The current target page was accurate on packet bytes, but it left final helper names, route status, and C++ disposition too open. The report closes those by normalizing names to the best current support docs and by turning the caller uncertainty into a specific no-route/no-code proof.

## Heuristic / Inference Reanalysis And Validation

### Exact Range, Padding, And Split

- Accepted half-open helper range: `0x005b6c30-0x005b6c7c`.
- Local PE/Capstone confirms the target length is `0x4c` / 76 bytes.
- `0x005b6c00-0x005b6c30` is a 48-byte switch/jump table region for [UID:0001MY][BlockListenInputPaneCommandDispatcher](../../../../../by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md), not source code for this helper. The bytes begin with dwords `0x005b6a82`, `0x005b6b34`, and `0x005b6bef`, followed by small selector/index bytes. They do not contain a dword pointer to `0x005b6c30`.
- `0x005b6c7c-0x005b6c80` is exactly four `0xcc` bytes.
- [UID:0001MZ][AddToBlockListenInputPaneConstructor](../../../../../by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md) starts at `0x005b6c80` with a normal prologue and add-prompt constructor-shaped bytes.
- Rejected merge alternatives: preceding dispatcher table, trailing padding, successor add constructor, add/delete raw helpers, and modeled add/delete handlers.

### Function-Start / No-Function Status

- Existing target and aggregate docs record 2026-06-02, 2026-06-14, and 2026-06-15 IDA MCP checks showing `0x005b6c30` is not an IDA-modeled function start and has no direct `xrefs_to` / callers.
- Local PE cannot query IDA's function table, but the raw bytes match that claim: the target is function-shaped and standalone, yet not reached by any raw absolute VA or rel32 branch/call route found in this recheck.
- Route scan result: no little-endian VA occurrence for `0x005b6c30`, no occurrence for `0x005b6c7c`, and no raw rel32 `call`/`jmp`/`jcc` encoding targeting `0x005b6c30` in executable sections.
- Source-quality impact: route uncertainty no longer blocks owner/emitter assignment, because ownership is source-module based; it does block formal C++ because no integration point is proven.

### Packet / Protocol Naming

- Opcode `0x0d` is best documented as the `BlockListen` outbound packet family in this source cluster.
- Subcommand `0x01` is the no-payload request. Best descriptive enum spelling: `BlockListenSubcommand::ListOrModeRequest` or `BlockListenSubcommand::RequestListOrMode`.
- Subcommand `0x02` is add-block-listen with one converted name payload, documented by [UID:0002S0][SendAddBlockListenPacket](../../../../../by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md) and the modeled add-submit handler [UID:0001N0][AddToBlockListenInputPaneSubmitBlockedName](../../../../../by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md).
- Subcommand `0x03` is delete-block-listen with one converted name payload, documented by [UID:0002RZ][SendDeleteBlockListenPacket](../../../../../by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md) and the modeled delete-confirm handler [UID:0001N2][DeleteFromBlockListenInputPaneOnConfirm](../../../../../by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md).
- Rejected protocol alternatives: "toggle mode" is too strong because no local boolean/state write appears in this helper; "add" and "delete" are contradicted by fixed subcommand `0x01` and no name payload; generic `ProtocolSend` naming is weaker than feature-local `BlockListen`.

### Generated / Compiler Names

| Current/generated name | Best source-facing interpretation | Evidence / disposition |
| --- | --- | --- |
| `0x005b6c30` / target raw body | `SendBlockListenModePacket()` | Descriptive current target name; no original symbol proof. Keep as stable doc/search name unless a future route proves a better source name. |
| `sub_575380` | `PacketBufferWriteUInt8` | [UID:0003YJ][PacketBufferScalarBigEndianWriteHelpers](../../../../../by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md) documents this helper as byte write plus local spare zero; older alias `WriteByteZ_575380` remains historical/search-only. |
| `sub_574BB0` | `QueueAndSendPacket` / `Socket::QueueAndSendPacket` | [UID:0001HU][QueueAndSendPacket](../../../../../by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) documents the copied-packet queue handoff and Socket-owned route. |
| `dword_67A7EC` | `g_packetSender` | [UID:0000Q5][g_packetSender](../../../../../by-global/g_packetSender.md) resolves the global and current best type as `Socket *`; generated `g_pCashShopRequest` aliases are rejected for this address. |
| `0x00672f24` / `dword ptr [0x672f24]` | MSVC `__security_cookie` | Compiler-generated stack cookie; not feature source state. |
| `0x005c772f` | MSVC security-cookie check helper | Compiler-generated epilogue check; do not model as a BlockListen helper. |
| local byte at `packet[2]` / `[ebp-0x12]` | local scratch terminator | Not sent because send length is exactly `2`; mirrors PacketBuffer scratch-terminator convention. |

### Caller / Reachability

The best closure is: no entry route is currently proven. This is stronger than "unknown" because multiple independent negative checks agree:

- IDA docs record no IDA function object and no direct xrefs/callers.
- Local PE raw route scan found no absolute pointer to `0x005b6c30`.
- Local PE raw route scan found no rel32 `call`, `jmp`, or conditional branch target to `0x005b6c30`.
- Preceding jump-table bytes do not contain `0x005b6c30`; the table belongs to the modeled command dispatcher and points to dispatcher-internal blocks.
- There is no fall-through path: [UID:0001MY] ends with `ret`/padding/table data before the target, and the target returns at `0x005b6c7b`.

This does not prove the helper was not in original source. It proves the current binary/documentation evidence does not support emitting a callable C++ function body into final source yet.

### Source Placement

Best owner/source placement is [UID:0000HS][BlockListenInputPanes](../../../../../by-file/BlockListenInputPanes.md), proposed path `NexusTK/social/BlockListenInputPanes.cpp`.

Evidence for:

- The helper is embedded inside the `0x005b68c0-0x005b7354` block-list prompt source island.
- It shares opcode family `0x0d` with the block-list add/delete prompt handlers and raw add/delete helpers.
- The sibling classes [UID:00000X][BlockListenInputPane](../../../../../by-class/BlockListenInputPane.md), [UID:00000A][AddToBlockListenInputPane](../../../../../by-class/AddToBlockListenInputPane.md), and [UID:00003N][DeleteFromBlockListenInputPane](../../../../../by-class/DeleteFromBlockListenInputPane.md) all clear the direct file-parent gate and are documented under the same file.
- `by-project-structure/proposed-source-tree.md` explicitly favors `social/BlockListenInputPanes.cpp` over the broader command-input neighborhood because the config vector and opcode `0x0d` behavior are feature-specific social/block-list logic.

Rejected owners:

- `BlockListenInputPane` class: semantically plausible if a future route ties subcommand `0x01` to the top-level pane, but no direct caller, vtable slot, or constructor path reaches this raw helper today. File-level helper ownership is safer.
- `AddToBlockListenInputPane` / `DeleteFromBlockListenInputPane`: contradicted by subcommand `0x01` and no name payload.
- `PacketBuffer`: owns byte serialization helper `0x00575380`, not the feature packet.
- `Socket` / `g_packetSender`: owns outbound queue/send funnel and sender lifetime, not feature packet construction.
- `ProtocolSend`: placeholder page is explicitly non-promoted and lacks a proven shared source unit. This helper is feature-local.
- `CommandInputPanes.cpp`: address-neighborhood plausible, but current proposed source tree and block-list opcode/config evidence make `social/BlockListenInputPanes.cpp` stronger.

### Open-Question Closure

- Exact raw range: closed as `0x005b6c30-0x005b6c7c`.
- Padding and predecessor/successor ownership: closed as switch/jump table `0x005b6c00-0x005b6c30`, target `0x005b6c30-0x005b6c7c`, padding `0x005b6c7c-0x005b6c80`, add constructor starts `0x005b6c80`.
- Packet layout: closed as two sent bytes `0x0d 0x01`, plus unsent local zero.
- Helper names: closed to current best descriptive names `PacketBufferWriteUInt8`, `QueueAndSendPacket`, and `g_packetSender`; original names remain unproved but no better candidate exists.
- Caller/reachability: closed as no proven route after current IDA-doc review and local PE route scan; this caps C++ readiness but not source owner/emitter.
- Source placement: closed to `BlockListenInputPanes.cpp`.
- Formal C++: closed as "do not populate now" with target-specific no-code proof.

## Evidence Standards Used

- Existing IDA MCP facts recorded in the target, aggregate, class, file, and support docs.
- Local PE/Capstone disassembly and byte checks against the read-only NexusTK executable.
- Raw absolute-pointer and rel32 route scan for the target start.
- Adjacent range and padding checks.
- Sibling helper comparison to add/delete raw helpers and modeled handlers.
- Project structure evidence from `by-project-structure/proposed-source-tree.md`.
- Packet helper naming evidence from PacketBuffer, QueueAndSendPacket, `g_packetSender`, and `client_network` docs.
- Negative evidence: no live IDA tool in this session; no original symbols; no caller route; no `ProtocolSend` source-unit proof.

The evidence is strong enough to improve score and source-quality names because byte behavior, source island, and helper semantics all agree. It is not strong enough for formal C++ because no entry path is found.

## Local PE / Binary Facts

Local PE facts were gathered from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.

Key disassembly:

```asm
005b6c30  push ebp
005b6c31  mov  ebp, esp
005b6c33  sub  esp, 14h
005b6c36  mov  eax, dword ptr [672f24h]
005b6c3b  xor  eax, ebp
005b6c3d  mov  [ebp-4], eax
005b6c40  lea  eax, [ebp-14h]
005b6c43  push eax
005b6c44  push 0Dh
005b6c46  call 00575380
005b6c4b  lea  eax, [ebp-13h]
005b6c4e  push eax
005b6c4f  push 1
005b6c51  call 00575380
005b6c56  mov  ecx, dword ptr [67a7ech]
005b6c5c  lea  eax, [ebp-14h]
005b6c5f  add  esp, 10h
005b6c62  mov  byte ptr [ebp-12h], 0
005b6c66  push 2
005b6c68  push eax
005b6c69  call 00574bb0
005b6c6e  mov  ecx, [ebp-4]
005b6c71  xor  ecx, ebp
005b6c73  call 005c772f
005b6c78  mov  esp, ebp
005b6c7a  pop  ebp
005b6c7b  ret
005b6c7c  cc cc cc cc
```

Boundary bytes:

- `0x005b6c00-0x005b6c30`: `82 6a 5b 00 34 6b 5b 00 ef 6b 5b 00 ...`, a switch/jump-table data region for [UID:0001MY].
- `0x005b6c30`: first byte `55`, normal prologue.
- `0x005b6c7b`: `ret`.
- `0x005b6c7c-0x005b6c80`: `cc cc cc cc`.
- `0x005b6c80`: first byte of the add-prompt constructor, `55 8b ec 51 56 ...`.

Route-scan result:

- raw little-endian `0x005b6c30` occurrences in file-mapped sections: `0`;
- raw little-endian `0x005b6c7c` occurrences: `0`;
- raw rel32 encodings targeting `0x005b6c30` from `call`/`jmp`/`jcc`: none found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b6c00-0x005b6c30` | `by-memory/-ignored.md` row | Switch/jump table for [UID:0001MY] dispatcher | ignored | [UID:0001MY] support bytes | n/a | Accurate; no split change needed. |
| `0x005b6c30-0x005b6c7c` | [UID:0002RY](../../../../../by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) | Raw opcode `0x0d` / subcommand `0x01` no-payload packet helper | TRUE | [UID:0000HS] | propose `87/89` | Keep owner/emitter; no formal C++. |
| `0x005b6c7c-0x005b6c80` | `by-memory/-ignored.md` row | `0xcc` alignment padding | ignored | n/a | n/a | Accurate. |
| `0x005b6c80-0x005b6cc0` | [UID:0001MZ](../../../../../by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md) | Add prompt constructor-shaped bytes | TRUE | [UID:00000A] | existing doc | Must remain separate. |
| `0x005b7010-0x005b70f7` | [UID:0002S0](../../../../../by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md) | Sibling raw opcode `0x0d` / subcommand `0x02` helper | TRUE | [UID:0000HS] | `85/87` | Relationship should be cross-documented. |
| `0x005b7360-0x005b7447` | [UID:0002RZ](../../../../../by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md) | Sibling raw opcode `0x0d` / subcommand `0x03` helper | TRUE | [UID:0000HS] | `85/87` | Relationship should be cross-documented. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005b6c30` | existing IDA docs: `lookup_funcs` not a function | Raw/unmodeled helper start. |
| `0x005b6c30` | existing IDA docs: `xrefs_to` / callers none | No IDA caller route. |
| `0x005b6c30` | local PE route scan: no absolute VA or rel32 route | No raw route found outside IDA. |
| `0x005b6c44` / `0x005b6c46` | `push 0x0d`; call `0x00575380` | Writes packet opcode with `PacketBufferWriteUInt8`. |
| `0x005b6c4f` / `0x005b6c51` | `push 1`; call `0x00575380` | Writes subcommand `0x01`. |
| `0x005b6c56` | reads `dword_67A7EC` | Uses `g_packetSender` as send object. |
| `0x005b6c62` | writes local zero byte | Local scratch terminator, not sent. |
| `0x005b6c66-0x005b6c69` | pushes length `2`, packet pointer, call `0x00574bb0` | Sends exactly two bytes through `QueueAndSendPacket`. |
| `0x005b6c73` | call `0x005c772f` | Compiler security-cookie check. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target [UID:0002RY] already records the opcode/subcommand writes, return at `0x005b6c7b`, padding at `0x005b6c7c`, IDA no-function/no-xref status, and file owner [UID:0000HS].
- [UID:0001MW][BlockListenInputPanes aggregate](../../../../../by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md) records the full split map, raw helper statuses, switch table, padding, add/delete modeled handlers, and 2026-06-15 IDA refresh.
- [UID:0000HS][BlockListenInputPanes file](../../../../../by-file/BlockListenInputPanes.md) records the proposed source root `NexusTK/social/BlockListenInputPanes.cpp`, class grouping, raw helper inventory, vtable evidence, config vector use, and the weaker `CommandInputPanes.cpp` alternative.
- [UID:0001N0] and [UID:0001N2] prove the same opcode family for modeled add/delete successful paths.
- [UID:0002S0] and [UID:0002RZ] prove the raw add/delete helper packet layout and the same no-function/no-xref caveat.
- [UID:0003YJ] documents `sub_575380` as `PacketBufferWriteUInt8`.
- [UID:0001HU] documents `sub_574BB0` as `QueueAndSendPacket`.
- [UID:0000Q5] documents `dword_67A7EC` as `g_packetSender`, best current type `Socket *`.
- [UID:0001QH][client_network](../../../../../by-meta/client_network.md) documents the feature-local packet-builder rule and current outbound path.
- `by-project-structure/proposed-source-tree.md` lists `social/BlockListenInputPanes.cpp` and says the block-list prompts' config vector and opcode `0x0d` behavior make that social source candidate stronger than the command-input neighborhood.

Existing docs that are stale or incomplete:

- `by-memory/-coverage-report.md` still has the old `76%` row and old live-MCP retry caveat for [UID:0002RY].
- Target [UID:0002RY] still says `sub_575380` and `sub_574BB0` are provisional without applying the now-strong support-doc names.
- `client_network.md` mentions block-list add/delete subcommands `0x02`/`0x03` but omits the fixed subcommand `0x01` list/mode request helper.
- `ProtocolSend.md` contains some older wording that still describes `QueueAndSendPacket` through `CashShopRequest`; newer Socket and QueueAndSendPacket pages are stronger. This target should not be moved to `ProtocolSend`, and the support update should avoid reinforcing the older owner wording.

## Ranked Ownership Analysis

### 1. [UID:0000HS] `NexusTK/social/BlockListenInputPanes.cpp` - accepted

- Evidence for: exact address cluster with block-list prompt classes; opcode family `0x0d`; sibling add/delete helpers; modeled add/delete handlers; proposed source tree; file page clears `85/89`; target currently routed to it without dead-end.
- Evidence against: no proven source-level caller to the raw helper.
- Decision: accept as canonical owner and emitter. File-level ownership is stronger than class-level ownership because no direct top-level `BlockListenInputPane` route is proven.

### 2. [UID:00000X] `BlockListenInputPane` class - rejected for current direct owner

- Evidence for: subcommand `0x01` is the top-level no-payload request, so it likely relates to the top-level pane's show/list/mode flow.
- Evidence against: no caller from constructor, key handler, command dispatcher, vtable slot, or switch table reaches `0x005b6c30`; the raw route scan also found no route.
- Decision: do not change canonical owner to the class. A future route could justify class-level method/helper attachment, but current evidence supports only file-level helper ownership.

### 3. `ProtocolSend.cpp` / shared protocol module - rejected

- Evidence for: the helper is an outbound protocol packet builder.
- Evidence against: `ProtocolSend` is a non-promoted placeholder; packet-builder docs say feature packet builders stay with feature modules unless a real shared protocol API is proven; no name/string/source-unit evidence exists; this helper is surrounded by block-list feature code.
- Decision: do not move or duplicate ownership to `ProtocolSend`.

### 4. `PacketBuffer`, `Socket`, or `g_packetSender` owners - rejected

- Evidence for: the helper calls PacketBuffer byte writer and Socket-owned queue/send path.
- Evidence against: callees do not own feature packet semantics. PacketBuffer owns serialization helpers, Socket owns queue/transport, and `g_packetSender` owns storage/lifetime.
- Decision: keep them as support dependencies only.

### 5. `CommandInputPanes.cpp` - rejected as weaker current source root

- Evidence for: neighboring command-input pane area and prompt idioms.
- Evidence against: block-list config vector, opcode family, sibling classes, and proposed source tree all point to a social/block-list module.
- Decision: keep only as historical/alternate source placement note, not target owner.

## Negative Evidence Summary

- No IDA function object at `0x005b6c30` in recorded IDA checks.
- No IDA `xrefs_to` / callers in recorded IDA checks.
- No raw absolute pointer to `0x005b6c30` or `0x005b6c7c` in local PE scan.
- No raw rel32 `call`, `jmp`, or conditional branch route to `0x005b6c30`.
- Preceding switch/jump table bytes belong to [UID:0001MY] and do not point to the target.
- No name payload, `WideCharToMultiByte`, payload length byte, or copy helper appears in [UID:0002RY]; therefore add/delete names do not fit.
- No state change, toggle flag, or config write appears in [UID:0002RY]; therefore "mode" must be treated as a no-payload request label, not a proven local toggle.
- No evidence supports `ProtocolSend.cpp`, PacketBuffer, Socket, or CashShopRequest as semantic owners for this feature packet.

## First-Draft C++ Eligibility / Exact No-Code Proof

Numeric eligibility is present after this report's proposed score: reconstructable true, nonblank emitter [UID:0000HS], and average score `(87 + 89) / 2 = 88`.

Do not populate the formal C++ block anyway. The concrete blocker is route/source-shape, not behavior:

- IDA does not model the target as a function.
- Existing IDA docs report no direct xrefs/callers.
- Local PE route scan found no absolute or rel32 entry route.
- The immediately preceding region is dispatcher table data, not a fall-through caller.
- The helper returns normally and is padded before the add constructor, proving it is a standalone compiled island, but not proving liveness.
- The modeled add/delete handlers already inline their packet shapes, so a source-level raw helper may be dead/unreferenced, an alternate build artifact, or an unmodeled call target. Emitting a formal callable helper could create misleading generated source until the route is proven or the project adopts an explicit policy for emitting raw no-route helper islands as unused static functions.

Score impact: this caps the target below final-audit range and should keep formal C++ blank despite the numeric gate. Owner/emitter remain justified because the source module is clear.

## Proposed Score / Metadata

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion `87`: the page can now document exact bytes, range, padding, packet layout, helper names, compiler names, route scan, source owner, sibling helper relationship, and no-code proof.
- Confidence `89`: the byte and source-module evidence is strong and cross-confirmed by existing IDA docs plus local PE recheck. It stays below `90+` because original source name and caller route remain unproven.

## Exact Support-Doc Implementation Checklist

If this report is accepted, implementation should update these by-* docs under normal leases and validators. Do not compress this report into a short summary.

1. Target [UID:0002RY] `by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md`
   - Update metadata to `87/89`, keep owner/emitter [UID:0000HS], keep formal C++ blank.
   - Add local PE/Capstone recheck with SHA-256, exact range length `0x4c`, disassembly facts, and route-scan result.
   - Replace provisional helper names with best current names: `PacketBufferWriteUInt8`, `QueueAndSendPacket`, `g_packetSender`; retain `sub_575380`, `sub_574BB0`, and `dword_67A7EC` as historical/IDA names.
   - Add compiler-name closure for `__security_cookie` and `__security_check_cookie`.
   - Add protocol naming: opcode `0x0d` BlockListen family, subcommand `0x01` list/mode request, sibling subcommands `0x02` add and `0x03` delete.
   - Add exact no-code proof and remove generic "caller path/name not final" blocker wording.

2. [UID:0000HS] `by-file/BlockListenInputPanes.md`
   - Update the [UID:0002RY] row/detail with the normalized packet-buffer/send/global names, exact no-route proof, and subcommand map.
   - Preserve `NexusTK/social/BlockListenInputPanes.cpp` placement and the weaker `CommandInputPanes.cpp` alternative as rejected/weaker.

3. [UID:0001MW] `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`
   - Add the 2026-06-19 B008 local PE/Capstone confirmation for `0x005b6c00-0x005b6c80`.
   - Keep `0x005b6c00-0x005b6c30` as switch/jump table, `0x005b6c30-0x005b6c7c` as raw helper, `0x005b6c7c-0x005b6c80` as padding, and `0x005b6c80` as add constructor.

4. [UID:0001MY] `by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md`
   - Add a boundary note that the following switch/jump table does not route into [UID:0002RY] in the current route scan.
   - Do not claim this dispatcher calls [UID:0002RY].

5. Sibling raw helpers [UID:0002S0] and [UID:0002RZ]
   - Add a short cross-note that [UID:0002RY] is subcommand `0x01` fixed/no-payload, while these are subcommands `0x02`/`0x03` name-payload helpers.
   - Normalize `sub_575380` / `sub_574BB0` / `dword_67A7EC` wording if not already updated in those pages.

6. Modeled add/delete handlers [UID:0001N0] and [UID:0001N2]
   - Add or preserve the packet-family map `0x01` list/mode request, `0x02` add, `0x03` delete.
   - Preserve the distinction that modeled handlers inline successful add/delete packet construction; [UID:0002RY] has no proven modeled caller.

7. Class pages [UID:00000X], [UID:00000A], [UID:00003N]
   - No ownership reroute required.
   - Optional source-quality note for [UID:00000X]: [UID:0002RY] is semantically top-level block-list no-payload request but remains file-level because no class route is proven.

8. `by-meta/client_network.md`
   - Extend the BlockListenInputPanes feature-packet bullet to include subcommand `0x01` no-payload list/mode request through [UID:0002RY], alongside existing add/delete subcommands.

9. Packet/send support docs
   - [UID:0003YJ] `PacketBufferScalarBigEndianWriteHelpers`: add [UID:0002RY] as a simple `PacketBufferWriteUInt8` consumer writing opcode `0x0d` and subcommand `0x01`; note the spare/local zero is not sent.
   - [UID:0001HU] `QueueAndSendPacket`: add [UID:0002RY] as a raw no-route feature packet body that calls the send wrapper with length `2`; phrase as callee evidence from the raw body, not as a proven live caller route.
   - [UID:0000Q5] `g_packetSender`: optional add [UID:0002RY] as another feature packet-builder consumer of `g_packetSender`; preserve Socket lifetime ownership.
   - [UID:0000MV] `ProtocolSend`: no broad rewrite required, but do not move [UID:0002RY] there. If touched, add this as negative feature-local evidence only.

10. `by-memory/-ignored.md`
   - Existing rows for `0x005b6c00-0x005b6c30` and `0x005b6c7c-0x005b6c80` are already accurate. Update only if the implementation wants to add the 2026-06-19 local PE confirmation; no structural change required.

11. Validators to run after implementation
   - Run `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` for every edited by-* target/support file.
   - Do not edit `by-memory/-coverage-report.md`; leave the exact row below for supervisor insertion.

## Exact Supervisor-Owned Coverage Row

Replace the existing stale [UID:0002RY] row in `by-memory/-coverage-report.md` with:

```markdown
    - [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) 0x005b6c30-0x005b6c7c | raw packet helper | SendBlockListenModePacket : reconstructable : 87% : strong : B008 2026-06-19 source-quality reanalysis resolves this raw no-function/no-route helper as the fixed opcode `0x0d` BlockListen packet subcommand `0x01` list/mode request in `NexusTK/social/BlockListenInputPanes.cpp`: local PE/Capstone on SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632` confirms the exact `0x4c`-byte range, switch/jump-table lead-in `0x005b6c00-0x005b6c30`, return at `0x005b6c7b`, four `0xcc` padding bytes before [UID:0001MZ], two `PacketBufferWriteUInt8` calls for opcode/subcommand, a local unsent terminator byte, `QueueAndSendPacket(g_packetSender, packet, 2)` send length, no name payload, sibling relationship to subcommands `0x02`/`0x03` add/delete helpers, and no direct rel32/absolute route to `0x005b6c30`, keeping formal C++ blank.
```

## Validator Results

Baseline command run during report-only pass:

> Executable block R001 was removed from this report and preserved verbatim in [0002RY-SendBlockListenModePacket-source-quality-removed.md](0002RY-SendBlockListenModePacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `ok: 1`
- `apply: False`
- Important line: `ok           0002RY by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md UID header exists`
- Dry-run generated/autogen outputs reported `autogen_report_noop`; no by-* docs or coverage files were edited by this report pass.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B008\research\0002RY-SendBlockListenModePacket-source-quality.md`
- Modified: none outside the B008 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0002RY-SendBlockListenModePacket-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0002RY"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002RY-SendBlockListenModePacket-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0002RY-SendBlockListenModePacket-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002RY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
