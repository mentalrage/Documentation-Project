** TARGET-REPORT-UID:0002S0 **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002S0 SendAddBlockListenPacket Source-Quality Report

Assignment: `B011-goal2-send-add-block-listen-packet-source-quality-0002S0-20260619`  
Target: [UID:0002S0] `by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md`  
Required output: `tools/leaser/Agents/Agent-B011/research/0002S0-SendAddBlockListenPacket-source-quality.md`  
Mode: report-only. No `by-*` documentation files and no `by-memory/-coverage-report.md` were edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002S0] as a reconstructable file-local packet helper owned and emitted by [UID:0000HS] `BlockListenInputPanes`.
- Final disposition: source-authored raw helper body, not padding, not a compiler thunk, not a class/vtable method, and not merged into [UID:0001N0] `AddToBlockListenInputPaneSubmitBlockedName`.
- Required action: incorporate the reachability, helper-name, packet-layout, duplicate-inline-path, boundary, and C++ draft details below into the target and support docs under Rule 26.
- Confidence: strong for bytes, behavior, and source placement; medium-high for original source spelling because no direct caller/xref exists.

Recommended metadata after implementation:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000HS
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000HS
```

The target is first-draft C++ eligible under the current gate: reconstructable, nonblank emitter route to `auto-generated/NexusTK/social/BlockListenInputPanes.cpp`, and `(85 + 87) / 2 > 85`. The recommended code should be a standalone file-local helper in `BlockListenInputPanes.cpp`, not a call inserted into `AddToBlockListenInputPane::SubmitBlockedName`.

## Supporting Research

## Target

- Target UID: `0002S0`.
- Target path: `by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md`.
- Current score: `85/87`.
- Current owner/emitter: [UID:0000HS] `BlockListenInputPanes`.
- Current generated route: `auto-generated/NexusTK/social/BlockListenInputPanes.cpp`.
- Current generated state: `auto-generated/NexusTK/social/BlockListenInputPanes.cpp` contains only an empty emitter marker for `0002S0`.
- Current concern: target already documents opcode/subcommand behavior but leaves source-name, direct caller/liveness, helper names, duplicate relationship, and C++ readiness unresolved.

## Supervisor Active Recheck

The user explicitly assigned a report-only B-agent source-quality pass and prohibited edits to all `by-*` docs and `by-memory/-coverage-report.md`. This report therefore records exact implementation text and checklists for a later callback instead of applying the changes.

The target does not require a range split. It is one complete raw helper body:

- Start: `0x005b7010`, first byte `55`.
- End-exclusive: `0x005b70f7`, immediately after the range-check failure call tail.
- Preceding padding: `0x005b700e-0x005b7010`, two `0xcc` bytes after [UID:0001N0].
- Following padding: `0x005b70f7-0x005b7100`, nine `0xcc` bytes before [UID:0001N1].

The support issue is not splitting. It is how to document and emit an unmodeled, statically unreferenced, source-authored duplicate packet sender.

## Inference Research Guidance Check

`by-structure.md` requires direct semantic ownership and treats `EMITTER_UIDS` as output routing. Here the helper has no object state, no vtable route, and no direct caller proving class membership. The narrowest supported semantic owner is therefore the source file [UID:0000HS] `BlockListenInputPanes`, not [UID:00000A] `AddToBlockListenInputPane`.

`inference_research.md` guidance also matters because the absence of xrefs is evidence only after direct references, function pointers, sibling bodies, and source context have been checked. The best conclusion is not "unknown caller" in a generic sense. The best conclusion is:

- the helper body is live code bytes in `.text`;
- IDA does not model it as a function;
- current IDA docs and fresh local scans find no direct xrefs, no rel32 calls/jumps, and no absolute dword pointer references to `0x005b7010`;
- the modeled add-submit handler duplicates the send logic inline instead of calling this raw helper;
- the raw helper should remain documented and emitted as a retained file-local helper because the binary contains it, but no existing caller route should be invented.

## Heuristic / Inference Reanalysis And Validation

### Raw Helper Liveness And Caller Route

Best-supported inference: `0x005b7010-0x005b70f7` is a complete, retained, source-authored helper body that is statically unreferenced in the current image.

Evidence checked:

- Existing target doc records 2026-06-02 and 2026-06-14 live IDA MCP results: `lookup_funcs 0x005b7010` reports `Not a function`; `xrefs_to 0x005b7010` reports no inbound xrefs.
- Fresh IDA MCP attempt on 2026-06-19 failed with `IDA_MCP_UNAVAILABLE: Unable to connect to the remote server`, so no new live IDA state was added.
- Fresh local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, image base `0x00400000`, found:
  - no rel32 `call` or `jmp` references to `0x005b7010`;
  - no absolute dword references to `0x005b7010` in the image;
  - no rel32 `call` or `jmp` references and no absolute dword references to sibling raw starts `0x005b6c30` and `0x005b7360`.
- The body has a normal prologue, stack frame, security cookie, one stack argument loaded from `[ebp+8]`, helper calls, checked return path, `ret 4`, and compiler range-check failure tail. It is not data or padding.

Rejected alternatives:

- "Called indirectly through a function pointer table": rejected for current docs because the image-wide dword scan found no stored `0x005b7010` pointer, and the existing IDA xref checks found no pointer xrefs.
- "Called by AddToBlockListenInputPaneSubmitBlockedName": rejected because the modeled handler contains inline packet-send instructions at `0x005b6ef6-0x005b6fa7`; it does not call `0x005b7010`.
- "Dead padding after the add handler": rejected because Capstone disassembly shows a coherent helper with prologue, calls, bounds checks, send, epilogue, and `ret 4`.
- "Compiler-generated wrapper": rejected because it builds feature-specific packet bytes and calls Windows/packet helpers. Only the security cookie and range-check tail are compiler/runtime artifacts.

Impact: caller route should be documented as "no static caller proven" rather than left as a generic open question. This caps confidence below final audit, but it does not block source reconstruction.

### Source-Facing Name And Signature

Best-supported name:

```cpp
SendAddBlockListenPacket
```

Best-supported signature:

```cpp
static void __stdcall SendAddBlockListenPacket(const wchar_t* blockedName);
```

Evidence:

- The helper takes exactly one stack argument at `[ebp+8]`, treats it as a NUL-terminated UTF-16 string, and returns with `ret 4`.
- It does not read incoming `ecx` as `this`; later `ecx` is overwritten with `g_packetSender` before `QueueAndSendPacket`.
- The body sends opcode `0x0d`, subcommand `0x02`, matching add-block-listen semantics.
- The adjacent sibling [UID:0002RZ] mirrors the same helper body with subcommand `0x03`; that supports `SendDeleteBlockListenPacket` as the sibling name and `SendAddBlockListenPacket` for this target.

Rejected alternatives:

- `AddToBlockListenInputPane::SendAddBlockListenPacket`: weak. The code is semantically add-specific and adjacent to the add class, but no `this` state, vtable slot, callsite, or class method reference proves class ownership.
- `SendBlockListenPacket`: too broad because the subcommand is fixed to add (`0x02`); the delete and mode helpers are separate functions.
- `BuildAddBlockListenPacket`: incomplete because the function sends through `QueueAndSendPacket`, not just builds bytes.
- Original exact name unknown: true, but source-quality docs should use the strongest descriptive name instead of preserving `sub_5B7010` or only a raw address.

Calling convention caveat: `ret 4` is a hard binary fact. If final project headers use a project-wide calling-convention macro instead of spelling `__stdcall`, use that macro. Do not silently emit a default `__cdecl` free function unless the build system is known to transform it to the observed callee-cleanup form.

### Ownership And Source Placement

Best-supported canonical owner: [UID:0000HS] `BlockListenInputPanes`.

Best-supported source placement:

```text
NexusTK/social/BlockListenInputPanes.cpp
```

Evidence:

- [UID:0000HS] lists this raw helper as part of the social/block-list prompt module.
- [UID:0001MW] lists the helper in the exact block-list input pane aggregate between the add-submit handler and delete constructor.
- [UID:0001QH] `client_network` explicitly says feature packet builders should remain with feature files unless later evidence proves a central `ProtocolSend.cpp`.
- The helper uses feature-specific opcode/subcommand semantics, but no class instance state.
- The network helpers it calls are shared dependencies, not owners: [UID:0000V1] PacketBuffer helper family, [UID:0001HU] `QueueAndSendPacket`, and [UID:0000Q5] `g_packetSender`.

Rejected owners:

- [UID:00000A] `AddToBlockListenInputPane`: semantically tempting, but not supported as the direct owner because the helper is not a vtable method, not a proven class method, and does not use `this`.
- [UID:0000DD] `Socket` or [UID:0000NS] `Socket.cpp`: rejected because Socket owns the queue/send funnel and global lifetime, not feature packet construction.
- [UID:0000M8] `PacketBuffer`: rejected because `PacketBufferWriteUInt8` is only a serialization dependency.
- A new `ProtocolSend.cpp`: rejected by current `client_network` guidance and lack of cross-feature central helper evidence for this file-local block-list packet body.
- [UID:0001N0] `AddToBlockListenInputPaneSubmitBlockedName`: rejected because the physical helper range is separate and uncalled; merging would erase real binary code.

### Duplication Relationship With AddToBlockListenInputPaneSubmitBlockedName

Best-supported conclusion: [UID:0001N0] contains an inline duplicate of this packet-send sequence; [UID:0002S0] is a separate retained helper with the same packet layout and a different source input route.

Fresh local disassembly of the modeled add handler shows the inline send path:

```text
0x005b6f07 push 0x0d
0x005b6f0b call 0x00575380
0x005b6f17 push 0x02
0x005b6f19 call 0x00575380
0x005b6f40 call dword ptr [0x0060d170] ; WideCharToMultiByte
0x005b6f64 call 0x00575380              ; payload length byte
0x005b6f7d call 0x00516220              ; memmove payload
0x005b6f91 mov ecx, dword ptr [0x0067a7ec]
0x005b6fa7 call 0x00574bb0              ; QueueAndSendPacket
```

Fresh local disassembly of this raw helper shows the same packet write/send pattern from its argument:

```text
0x005b7049 push 0x0d
0x005b704d call 0x00575380
0x005b7059 push 0x02
0x005b705b call 0x00575380
0x005b707c call dword ptr [0x0060d170] ; WideCharToMultiByte
0x005b709c call 0x00575380              ; payload length byte
0x005b70b5 call 0x00516220              ; memmove payload
0x005b70c7 mov ecx, dword ptr [0x0067a7ec]
0x005b70dd call 0x00574bb0              ; QueueAndSendPacket
```

Key difference:

- [UID:0001N0] sends a validated local stack candidate after duplicate/self-name/width/list checks.
- [UID:0002S0] accepts a caller-provided `const wchar_t*` and performs only string length, conversion, stack-buffer bounds, and send.

Implementation impact:

- Do not rewrite [UID:0001N0] as a call to [UID:0002S0] unless future binary evidence proves a different build/source relationship. The current binary has both the inline send sequence and the separate raw helper.
- Do document that [UID:0002S0] is likely a retained file-local helper that duplicates the successful add-submit send path.

### Packet Buffer And Helper Names

Use these source-quality names in target/support docs:

| Address / IDA label | Best current name | Evidence |
| --- | --- | --- |
| `0x00575380` / `sub_575380` | `PacketBufferWriteUInt8` | [UID:0000V1] and [UID:0003YJ] identify it as the one-byte PacketBuffer writer with a spare local zero byte. |
| `0x00516220` / `sub_516220` | `memmove` / `MemmoveWrapper` | [UID:0001BH] documents the wrapper as a thin `_memmove(destination, source, size)` call. |
| `0x00574bb0` / `sub_574BB0` | `QueueAndSendPacket` | [UID:0001HU] documents it as the Socket-owned outbound packet queue/send wrapper. |
| `0x0067a7ec` / `dword_67A7EC` | `g_packetSender` | [UID:0000Q5] documents Socket-lifetime global storage, best current type `Socket*`. |
| `0x00516030` / `sub_516030` | `GetMemoryMan` | [UID:0001BC] documents the MemoryMan singleton accessor. Here it is a low-level helper/calling artifact before the copy wrapper, not a feature dependency. |
| `0x0060d170` | `WideCharToMultiByte` | Fresh PE import parse maps IAT `0x0060d170` to `KERNEL32.dll!WideCharToMultiByte`. |
| `0x005c772f` | security-cookie check helper | Compiler/runtime epilogue support; do not model as source-authored packet behavior. |
| `0x005c7655` | range-check failure helper | Compiler/runtime failure path for stack-buffer bounds; not source-authored protocol logic. |
| `0x00672f24` | security cookie | Compiler/runtime cookie source read in the prologue. |

Rejected helper names:

- `WriteByteZ_575380` is acceptable as a transitional alias from resolved-name reports, but [UID:0003YJ] now provides better final-source direction: `PacketBufferWriteUInt8`.
- `sub_574BB0(dword_67A7EC, ...)` should not remain in source-facing docs when [UID:0001HU] and [UID:0000Q5] provide `QueueAndSendPacket(g_packetSender, ...)`.
- `WideCharToMultiByte` should not be left as an unknown import or `dword ptr [0x60d170]`.

### Packet Family, Subcommand, And Payload Semantics

Packet layout sent by [UID:0002S0]:

```text
byte 0: 0x0d  block-listen packet family
byte 1: 0x02  add-block-listen subcommand
byte 2: N     one-byte converted name length
byte 3..:     ANSI bytes returned by WideCharToMultiByte
```

Send length is `convertedLength + 3`. The local NUL byte written after the payload is a scratch terminator/bounds artifact and is not included in the explicit send length.

Semantics:

- Source input is a UTF-16/wide name pointer.
- The helper computes the UTF-16 length by scanning for a NUL wide character.
- It calls `WideCharToMultiByte` with code page `0` and flags `0`, using the low byte of the computed wide length as the source character count.
- It stores the returned converted byte count as a single payload length byte.
- It copies exactly that many bytes into the packet after the length byte.
- It fails through the compiler range-check path if the converted byte count is `>= 0x100` or if `convertedLength + 3 >= 0x400`.

Sibling packet family:

- [UID:0002RY] sends opcode `0x0d`, subcommand `0x01`, fixed length 2, no name payload.
- [UID:0002S0] sends opcode `0x0d`, subcommand `0x02`, add name payload.
- [UID:0002RZ] sends opcode `0x0d`, subcommand `0x03`, delete name payload.

This supports a source-facing enum direction such as:

```cpp
enum BlockListenPacketSubcommand {
    kBlockListenListRequest = 0x01,
    kBlockListenAddName = 0x02,
    kBlockListenDeleteName = 0x03,
};
```

Do not create that enum as a separate owner from this report alone; record it as a source-quality direction in `BlockListenInputPanes` or a future packet enum/type doc if broader packet enum work is accepted.

### Boundary And Padding

Fresh local byte evidence:

```text
0x005b700e-0x005b7010 = cc cc
0x005b7010-0x005b7028 = 55 8b ec 81 ec 04 05 00 00 a1 24 2f 67 00 33 c5 89 45 fc 53 56 8b 75 08
0x005b70d0-0x005b70f7 = 05 fc fa ff ff 00 8d 85 fc fa ff ff 50 e8 ce da fb ff 8b 4d fc 33 cd e8 43 06 01 00 8b e5 5d c2 04 00 e8 5e 05 01 00
0x005b70f7-0x005b7100 = cc cc cc cc cc cc cc cc cc
0x005b7100-0x005b7118 = 55 8b ec 51 56 8b f1 8b 0d 50 a7 67 00 6a 29 89 75 fc e8 39 92 f3 ff 50
```

Conclusion:

- `0x005b700e-0x005b7010`: two-byte alignment gap after [UID:0001N0].
- `0x005b7010-0x005b70f7`: exact helper body.
- `0x005b70f7-0x005b7100`: nine-byte alignment gap before [UID:0001N1].
- No child split is needed inside the target.

### Compiler/Generated Name Closure

Every compiler/generated or unclear name in target scope:

- `sub_5B7010`: replace in source-facing text with `SendAddBlockListenPacket`; retain address for binary traceability.
- `sub_575380`: use `PacketBufferWriteUInt8`; describe trailing zero as local scratch terminator outside counted payload.
- `sub_516220`: use `memmove` or `MemmoveWrapper`; source draft can call `memmove`.
- `sub_574BB0`: use `QueueAndSendPacket`.
- `dword_67A7EC`: use `g_packetSender`; best current type `Socket*`.
- `sub_516030`: use `GetMemoryMan`, but document it as a low-level helper artifact rather than a feature dependency.
- `dword ptr [0x60d170]`: use `WideCharToMultiByte`.
- `___report_rangecheckfailure` path: compiler/runtime failure path for stack-buffer bounds; not ordinary protocol behavior.
- security cookie read/check: compiler/runtime stack protection; do not write it as source-authored logic.

No generic future work remains for these names. The only source-name uncertainty is original spelling/calling-convention macro, and the report provides the best-supported descriptive replacement.

## Evidence Standards Used

Evidence types used:

- Existing by-memory/class/file/network docs with recorded live IDA MCP observations.
- Fresh local PE byte reads and import parsing from the read-only NexusTK executable.
- Fresh local Capstone disassembly of the raw helper, sibling delete helper, and add-handler packet-send region.
- Fresh image-wide direct rel32 `call`/`jmp` and absolute dword reference scans for raw packet helper starts.
- Generated coverage/output used only as current-state evidence, not as source truth.
- Resolved-name/project docs used to replace raw helper/global names with current best source-facing names.

IDA MCP status:

```text
IDA_MCP_UNAVAILABLE: Unable to connect to the remote server
```

Because the live endpoint was unavailable, fresh claims in this report are local PE/disassembly claims. Prior live IDA MCP claims are attributed to the existing docs that recorded them.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b6cc0-0x005b700e` | [UID:0001N0] `AddToBlockListenInputPaneSubmitBlockedName` | Modeled add validation/persist/send handler with inline add packet send path. | TRUE | [UID:00000A] | no score change from this report | Support doc should record duplicate relationship more explicitly. |
| `0x005b700e-0x005b7010` | ignored padding | Two `0xcc` bytes. | FALSE | none | no new page required | Should remain padding under aggregate/coverage context. |
| `0x005b7010-0x005b70f7` | [UID:0002S0] `SendAddBlockListenPacket` | Raw standalone add-block-listen packet helper. | TRUE | [UID:0000HS] | `88/90` | Target of this report; first-draft C++ recommended. |
| `0x005b70f7-0x005b7100` | ignored padding | Nine `0xcc` bytes. | FALSE | none | no new page required | Already documented in target/aggregate context. |
| `0x005b7100-0x005b7140` | [UID:0001N1] `DeleteFromBlockListenInputPaneConstructor` | Delete prompt constructor. | TRUE | [UID:00003N] | no score change | Confirms successor boundary. |
| `0x005b7360-0x005b7447` | [UID:0002RZ] `SendDeleteBlockListenPacket` | Sibling raw delete helper. | TRUE | [UID:0000HS] | no target score change | Mirrors this helper with subcommand `0x03`. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005b7010` | no rel32 call/jmp refs; no absolute dword refs in fresh local scan | No static caller/function-pointer route proven. |
| `0x005b704d` | `call 0x00575380` after `push 0x0d` | Writes block-listen family opcode. |
| `0x005b705b` | `call 0x00575380` after `push 0x02` | Writes add subcommand. |
| `0x005b707c` | `call dword ptr [0x0060d170]` | Converts wide name bytes through `WideCharToMultiByte`. |
| `0x005b709c` | `call 0x00575380` after `push esi` | Writes converted payload length. |
| `0x005b70b5` | `call 0x00516220` | Copies converted payload into packet buffer. |
| `0x005b70dd` | `call 0x00574bb0` with `ecx = [0x0067a7ec]` | Queues/sends `convertedLength + 3` bytes through `g_packetSender`. |
| `0x005b70f2` | `call 0x005c7655` | Compiler range-check failure path. |
| `0x005b6f07-0x005b6fa7` | inline calls in [UID:0001N0] | Same packet sequence in modeled add handler, not a call to this helper. |

## Documentation Evidence And Status

Docs supporting the recommendation:

- [UID:0000HS] `BlockListenInputPanes`: source file route, social/block-list module placement, raw helper inventory.
- [UID:0001MW] `BlockListenInputPanes` aggregate: exact target placement, padding boundaries, sibling helper map.
- [UID:0001N0] `AddToBlockListenInputPaneSubmitBlockedName`: modeled validation/send behavior and inline opcode `0x0d`/subcommand `0x02` path.
- [UID:00000A] `AddToBlockListenInputPane`: semantic add class, but not direct owner for the raw helper.
- [UID:0002RZ] `SendDeleteBlockListenPacket`: sibling no-xref raw helper mirror.
- [UID:0000V1] and [UID:0003YJ] PacketBuffer helpers: `PacketBufferWriteUInt8` name and spare-zero semantics.
- [UID:0001HU] `QueueAndSendPacket`: Socket-owned send funnel name and behavior.
- [UID:0000Q5] `g_packetSender`: Socket-lifetime global, best current type `Socket*`.
- [UID:0001BH] `MemmoveWrapper`: `memmove` wrapper naming.
- [UID:0001QH] `client_network`: feature packet builders stay with feature files unless a central protocol-send owner is proven.

Docs stale or incomplete for this target:

- [UID:0002S0] should replace "helper naming/call ownership/duplication unresolved" with the stronger static conclusion: no direct caller or pointer reference found; it is a retained file-local helper duplicating the inline add handler send path.
- [UID:0001N0] should explicitly cross-reference [UID:0002S0] as an uncalled duplicate helper and state that the current handler body contains the same send sequence inline.
- [UID:0001MW] should update the row for [UID:0002S0] from a raw helper with unresolved caveat to a file-local retained raw helper with static no-xref proof and recommended source name/signature.
- [UID:0000HS] should add the signature/source-placement recommendation and the "do not move to Socket/PacketBuffer/ProtocolSend" negative evidence.
- `by-memory/-coverage-report.md` is stale for this row and still shows `78%`; exact replacement text is below for supervisor-owned application.

## Ranked Ownership Analysis

### 1. [UID:0000HS] BlockListenInputPanes

Evidence for:

- The helper is feature-specific, address-local to the block-list input pane method island, and listed in the file page.
- It has no class instance state.
- The file already owns sibling raw packet helpers [UID:0002RY] and [UID:0002RZ].
- Current `client_network` guidance keeps feature packet builders with their feature source files.

Evidence against:

- It is semantically add-specific and physically follows the add-submit handler.
- No direct caller proves how original source referenced it.

Decision: accepted. This is the best direct owner and emitter.

### 2. [UID:00000A] AddToBlockListenInputPane

Evidence for:

- Packet subcommand `0x02` is add-specific.
- The helper sits immediately after the add-submit handler.
- The add-submit handler duplicates the same packet layout.

Evidence against:

- No `this` usage.
- No vtable or class-method xref.
- No direct call from the add handler.
- The helper shape is suitable for a file-local helper with a wide-string argument.

Decision: rejected as canonical owner for now. Mention as semantic relationship only.

### 3. Socket / PacketBuffer / ProtocolSend

Evidence for:

- The helper calls Socket-owned `QueueAndSendPacket` and PacketBuffer writers.
- The code is packet-building logic, so a central packet module is a plausible broad concept.

Evidence against:

- Socket owns transport queueing, not block-list feature command construction.
- PacketBuffer owns scalar serialization helpers, not feature packet semantics.
- `client_network` currently rejects moving feature packet builders to `ProtocolSend.cpp` without stronger central-module evidence.

Decision: rejected.

## Negative Evidence Summary

Checked and rejected:

- Direct code calls to `0x005b7010`: none found.
- Direct jumps to `0x005b7010`: none found.
- Absolute stored pointer to `0x005b7010`: none found.
- Direct call from [UID:0001N0]: none; inline duplicate instead.
- Class method evidence: no `this`, no vtable, no class slot, no class-specific field access.
- Merge into add handler: rejected due separate real bytes and separate range/padding.
- PacketBuffer/Socket ownership: rejected as dependency ownership only.
- Central protocol-send owner: rejected by current docs and lack of module-wide evidence.

Remaining uncertainty: original source spelling and whether the helper was an unused static helper, an uncalled member, or a formerly used helper retained in the linked object cannot be proven without debug/source metadata. This does not block file-level ownership or first-draft C++ because the binary body and feature semantics are clear.

## First-Draft C++ Recommendation

Formal C++ should be populated for [UID:0002S0] during implementation callback.

Placement:

```text
File: NexusTK/social/BlockListenInputPanes.cpp
Owner/emitter: [UID:0000HS] BlockListenInputPanes
Source form: file-local helper, near the add/delete prompt helpers
```

Recommended draft:

```cpp
static void __stdcall SendAddBlockListenPacket(const wchar_t* blockedName)
{
    char packet[0x400];
    char convertedName[0x100];

    int wideLength = 0;
    while (blockedName[wideLength] != L'\0') {
        ++wideLength;
    }

    PacketBufferWriteUInt8(packet, 0x0d);
    PacketBufferWriteUInt8(packet + 1, 0x02);

    const int convertedLength = WideCharToMultiByte(
        0,
        0,
        blockedName,
        static_cast<unsigned char>(wideLength),
        convertedName,
        sizeof(convertedName),
        NULL,
        NULL);

    if (static_cast<unsigned int>(convertedLength) >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = '\0';
    PacketBufferWriteUInt8(packet + 2, convertedLength);
    memmove(packet + 3, convertedName, convertedLength);

    const int packetLength = convertedLength + 3;
    if (static_cast<unsigned int>(packetLength) >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = '\0';
    QueueAndSendPacket(g_packetSender, packet, packetLength);
}
```

Implementation notes for the draft:

- If project policy avoids explicit runtime failure calls in source, document that `__report_rangecheckfailure` represents compiler-emitted range-check lowering and replace those branches with the project's accepted bounded-array idiom. Do not silently remove the overflow behavior from the doc.
- `PacketBufferWriteUInt8` and `QueueAndSendPacket` should use the exact declarations chosen by [UID:0000M8] and [UID:0000DD].
- `g_packetSender` should use the current best type from [UID:0000Q5].
- The `static_cast<unsigned char>(wideLength)` reflects the observed `movzx eax, bl` before `WideCharToMultiByte`; if a later source-style review decides this was naturally constrained by caller validation, keep the binary note rather than overgeneralizing the helper.
- The helper may be unreferenced by reconstructed source initially. That is acceptable because the binary contains the body and current evidence does not justify inserting a call from [UID:0001N0].

No-code proof is not applicable. The page is eligible and a source-like standalone helper can be produced without crossing target range boundaries.

## Target / Support Implementation Checklist

For [UID:0002S0] target doc:

- Update scores from `85/87` to `88/90`.
- Keep `CANONICAL_OWNER:0000HS`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000HS`.
- Add the fresh PE SHA and local disassembly evidence from this report.
- Add static reachability closure: no rel32 call/jump refs and no absolute dword refs to `0x005b7010`; existing IDA xrefs remain none.
- Replace unresolved helper-name caveat with the helper-name table above.
- Record source-facing signature `static void __stdcall SendAddBlockListenPacket(const wchar_t* blockedName)`.
- Record packet layout and send length exactly.
- Record duplicate relationship with [UID:0001N0] as inline duplicate, not caller.
- Add first-draft C++ from this report, adjusted only for accepted project helper declarations.

For [UID:0001N0] `AddToBlockListenInputPaneSubmitBlockedName`:

- Add a support note that its success path inlines the same add-block-listen packet sequence as [UID:0002S0].
- State that current evidence does not support rewriting the handler as a call to [UID:0002S0].
- Use source-facing helper names `PacketBufferWriteUInt8`, `WideCharToMultiByte`, `memmove`, `QueueAndSendPacket`, and `g_packetSender`.

For [UID:0001MW] aggregate:

- Update the [UID:0002S0] row description to say file-local retained raw helper with no static caller/pointer route, not just unresolved source-name caveat.
- Preserve boundary rows for `0x005b700e-0x005b7010` and `0x005b70f7-0x005b7100`.

For [UID:0000HS] `BlockListenInputPanes`:

- Add the best signature and file-local helper decision.
- State that [UID:0002S0] remains file-owned rather than class-owned because no `this`/vtable/direct-call evidence exists.
- Add negative evidence rejecting `Socket`, `PacketBuffer`, and central `ProtocolSend.cpp` ownership.

For [UID:0001QH] `client_network`, if support sync is accepted:

- Add or refine the BlockListen packet entry with subcommand meanings:
  - `0x01`: list/mode request.
  - `0x02`: add name.
  - `0x03`: delete name.
- Note that add/delete name helpers use one-byte ANSI length plus payload and local-only terminators outside send length.

For helper support docs:

- [UID:0000V1] and [UID:0003YJ] do not need score changes, but [UID:0002S0] should reference `PacketBufferWriteUInt8` and spare-zero semantics.
- [UID:0001HU] and [UID:0000Q5] do not need score changes, but [UID:0002S0] should use their names.

## Supervisor-Owned Coverage Row Text

Current `by-memory/-coverage-report.md` target row is stale:

```text
    - [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md) 0x005b7010-0x005b70f7 | raw packet helper | SendAddBlockListenPacket : reconstructable : 78% : strong : Raw add-block-listen packet helper with opcode `0x0d`/subcommand `0x02`, UTF-16-to-ANSI name conversion, one-byte payload length, rangecheck path, sibling packet-helper contrast, and unresolved direct-caller/source-name caveat.
```

Exact replacement row recommended for supervisor-owned application:

```text
    - [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md) 0x005b7010-0x005b70f7 | file-local packet helper | SendAddBlockListenPacket : reconstructable : 88% : very-strong : File-local BlockListen add-packet helper with exact raw body, two-byte pre-padding, nine-byte successor padding, no direct rel32/pointer refs to the raw start, source-facing `static void __stdcall SendAddBlockListenPacket(const wchar_t*)` signature, opcode `0x0d`/subcommand `0x02`, one-byte ANSI payload length, `WideCharToMultiByte`, `PacketBufferWriteUInt8`, `memmove`, `QueueAndSendPacket(g_packetSender, packet, length + 3)`, local-only terminator/rangecheck behavior, and duplicated inline send sequence in AddToBlockListenInputPaneSubmitBlockedName documented.
```

Optional parent/support row refresh if the supervisor is already updating this block:

```text
    - [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md) 0x005b68c0-0x005b7354 | aggregate method/helper island | BlockListenInputPanes : reconstructable : 85% : strong : Block-listen constructor, show/add/delete handlers, switch-table bytes, raw packet-helper children, padding boundaries, config-vector behavior, direct class/file routing, vtable evidence, and social source-file attachment documented; exact children carry method/helper C++.
```

## Validator Results

Scoped validator baseline command:

> Executable block R001 was removed from this report and preserved verbatim in [0002S0-SendAddBlockListenPacket-source-quality-removed.md](0002S0-SendAddBlockListenPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Working directory:

```text
E:\NTK\GhidraBridge\source-3\project-documentation
```

Result summary:

```text
ok: 1
ok 0002S0 by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md UID header exists
dry run only; pass --apply to write changes
```

No apply mode was used.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B011/research/0002S0-SendAddBlockListenPacket-source-quality.md`

Modified:

- None outside the B011 research folder.

No `by-*` documentation files were edited. `by-memory/-coverage-report.md` was not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0002S0-SendAddBlockListenPacket-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0002S0"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002S0-SendAddBlockListenPacket-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0002S0-SendAddBlockListenPacket-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002S0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
