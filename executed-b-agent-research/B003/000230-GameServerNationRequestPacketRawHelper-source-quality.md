** TARGET-REPORT-UID:000230 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000230 GameServerNationRequestPacketRawHelper Source-Quality Report

Assignment: `B003-goal2-gameserver-nation-request-packet-raw-helper-source-quality-000230-20260618`  
Agent: `Agent-B003`  
Date: 2026-06-18  
Target: [UID:000230] `by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md`  
Current state: `COMPLETION:84`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000JP`, `EMITTER_UIDS:0000JP`, blank formal C++.

## Recommendation

Promote [UID:000230] from a raw/blank-C++ helper to a documented retained private file-local GameServerConfig packet helper with first-draft C++ under [UID:0000JP] `by-file/GameServerConfig.md`.

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0000JP`
- `EMITTER_UIDS:0000JP`

Do not promote the helper to a confirmed `GameServerConfig` class method and do not merge it into [UID:0002HZ] `GameServerConfig::RequestNationEntries`. The body is function-shaped and source-authored enough to reconstruct, but the fresh route scan still finds no function record, no raw-start xref, no pointer-table route, and no rel32 caller to `0x00503960`. The defensible source placement is a private file-local helper in `NexusTK/map/GameServerConfig.cpp`, probably retained/dead in the linked image while [UID:0002HZ] contains the live guarded request method.

## Evidence Checked

- Read current target [UID:000230] `by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md`.
- Read modeled sibling [UID:0002HZ] `by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md`.
- Read support docs:
  - [UID:0000JP] `by-file/GameServerConfig.md`.
  - [UID:00005O] `by-class/GameServerConfig.md`.
  - [UID:0001AO] `by-memory/0x005039f0-0x0050bd13.GameServerNationAndMapInit.md`.
  - [UID:0000M8] `by-class/PacketBuffer.md`.
  - [UID:0001HZ] `by-memory/0x00575300-0x005756c6.PacketBufferHelpers.md`.
  - [UID:0003YJ] `by-memory/0x00575300-0x005753f5.PacketBufferScalarBigEndianWriteHelpers.md`.
  - [UID:0000V1] `by-memory/0x00575380.PacketBufferHelpers.md`.
  - [UID:0001HU] `by-memory/0x00574bb0-0x00574f59.QueueAndSendPacket.md`.
  - [UID:0000Q5] `by-global/g_packetSender.md`.
  - [UID:0001P0] `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`.
  - [UID:0000Q1] `by-global/g_gameServerNationTable.md`.
  - [UID:0001UP] `by-struct/GameServerNationEntry.md`.
- Searched B-agent executed reports and project docs for `000230`, `0x00503960`, `GameServerNationRequestPacketRawHelper`, `RequestNationEntries`, `0x00575380`, `0x005753a0`, `0x00574bb0`, and `g_packetSender`.
- Queried IDA MCP at `http://127.0.0.1:13337/mcp`; connection failed with `IDA_MCP_UNAVAILABLE: Unable to connect to the remote server`. Continued from existing IDA-backed docs plus raw PE/Capstone-style checks.
- Rechecked raw PE from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Ran read-only PE/section mapping, byte extraction, Capstone-style disassembly, pointer-pattern scan, and rel32 call/jump scan.
- Verified decimal/hex conversions with `tools/leaser/scripts/int_convert.py`:
  - `0x8d` = 141.
  - `0x44` = 68.
  - `0x66` = 102.
  - `0x4000` = 16384.
  - `0x09` = 9.
  - `0x00503960` = 5257568.
  - `0x005039ed` = 5257709.
  - `0x00503c70` = 5258352.
  - `0x00503d03` = 5258499.
- Checked generated state:
  - `auto-generated/NexusTK/map/GameServerConfig.cpp` exists, is currently empty, and has 0 lines.
  - `auto-generated/-ag-memory-coverage.md` routes [UID:000230] through [UID:0000JP] to `auto-generated/NexusTK/map/GameServerConfig.cpp`, with no generated code because formal C++ is blank.
  - `project-level/-auto-completion-stats.md` lists [UID:000230] at `84/88`.
  - `by-memory/-coverage-report.md` current [UID:000230] row lists `raw packet helper`, `84%`, `strong`, exact bytes/no-xrefs/fixed packet evidence.
- Ran validator dry run:
  - Command: `python tools/validator.py --mode file --file by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md`
  - Result: exit code 0, `ok:1`, no target-file errors.
  - Known unrelated project messages remained: `autogen_cpp_conflict 0000K5 auto-generated/NexusTK/input/IMEPanes.cpp nonempty file lacks validator autogen sentinel`; `autogen_cpp_noop 0000JP auto-generated/NexusTK/map/GameServerConfig.cpp no assembled code for root`.

## Raw Boundary, Bytes, And Xrefs

PE mapping:

- Image base: `0x00400000`.
- `.text`: VA `0x00401000-0x0060c600`, raw `0x00000400-0x0020ba00`.
- Target start `0x00503960` maps to raw file offset `0x00102d60`.
- Target end `0x005039ed` is half-open and maps to raw file offset `0x00102ded`.
- Target size is `0x8d` bytes / 141 bytes.

Predecessor boundary:

- `0x00503950-0x0050395e` decodes as the predecessor epilogue/tail:
  - `call 0x0041b6a0`
  - `add esp, 8`
  - `mov eax, esi`
  - `pop esi`
  - `pop ebp`
  - `ret 4`
- `0x0050395f` is `int3` padding.
- This confirms the raw helper does not borrow bytes from the previous function.

Target bytes:

```text
55 8b ec 83 ec 44 a1 24 2f 67 00 33 c5 89 45 fc
8d 45 bc 50 6a 66 e8 05 1a 07 00 8d 45 bd 50 68
00 40 00 00 e8 17 1a 07 00 8d 45 bf 50 6a 01 e8
ec 19 07 00 8d 45 c0 50 6a 01 e8 e1 19 07 00 8d
45 c1 50 6a 00 e8 d6 19 07 00 8d 45 c2 50 6a 01
e8 cb 19 07 00 8d 45 c3 50 6a 01 e8 c0 19 07 00
8d 45 c4 50 6a 00 e8 b5 19 07 00 8b 0d ec a7 67
00 8d 45 bc 83 c4 40 6a 09 50 e8 d1 11 07 00 8b
4d fc 33 cd e8 46 3d 0c 00 8b e5 5d c3
```

Target disassembly and behavior:

- `0x00503960`: standard frame prologue, `sub esp, 0x44`.
- `0x00503966`: reads security cookie from `0x00672f24`.
- Packet construction:
  - `0x00503970`: `PacketBufferWriteUInt8(0x66, &packet[0])`.
  - `0x0050397b`: `PacketBufferWriteUInt16BE(0x4000, &packet[1])`.
  - `0x0050398b`: `PacketBufferWriteUInt8(1, &packet[3])`.
  - `0x00503999`: `PacketBufferWriteUInt8(1, &packet[4])`.
  - `0x005039a7`: `PacketBufferWriteUInt8(0, &packet[5])`.
  - `0x005039b5`: `PacketBufferWriteUInt8(1, &packet[6])`.
  - `0x005039c3`: `PacketBufferWriteUInt8(1, &packet[7])`.
  - `0x005039d1`: `PacketBufferWriteUInt8(0, &packet[8])`.
- `0x005039cb`: loads `ecx` from `0x0067a7ec`, the documented `Socket *g_packetSender`.
- `0x005039d7`: sends `packet` with length `9` through `0x00574bb0`, documented as the Socket-owned queue/send helper.
- `0x005039e4`: validates the stack cookie through `0x005c772f`.
- `0x005039ec`: `ret`.

Successor boundary:

- `0x005039ed-0x005039f0` is three bytes of `int3` padding.
- `0x005039f0` starts the next GameServerConfig/nation-table raw body with a fresh prologue.
- This confirms the half-open target boundary `0x00503960-0x005039ed`.

Route/xref scan:

- Fresh scan found no direct rel32 calls or jumps to `0x00503960`.
- Fresh scan found no direct rel32 calls or jumps to `0x005039ed` or `0x005039f0`.
- Fresh scan found no absolute VA/RVA/raw-offset dword encodings for `0x00503960`, `0x00503961`, interior `0x00503970`, end `0x005039ed`, or successor `0x005039f0`.
- Positive-control scan found 489 VA references to `0x0067a7ec` (`g_packetSender`), so the pointer-pattern scan was not globally ineffective.
- Modeled sibling [UID:0002HZ] at `0x00503c70` has four rel32 callers:
  - `0x005a5029`
  - `0x005a5dcc`
  - `0x005b92fe`
  - `0x005be72c`
- This contrast is important: the live guarded request path is [UID:0002HZ]; [UID:000230] remains uncalled/unrouted by current static evidence.

## Heuristic / Inference Reanalysis And Validation

### Source-Facing Helper Role

Best source-facing role: `static void SendGameServerNationEntryRequestPacket()`.

Evidence:

- The helper has no `this` read and no parameters.
- It emits exactly one fixed packet and sends it through the process-wide packet sender.
- The packet is the same fixed packet emitted by [UID:0002HZ] after `GameServerConfig::RequestNationEntries` decides the nation table is empty.
- The file/class support docs place the surrounding nation-entry table constructor/parser/request logic in `GameServerConfig.cpp`.
- The raw body is adjacent to the `0x005039f0` GameServerConfig nation/map initialization island.

Rejected alternatives:

- `GameServerConfig::RequestNationEntries`: rejected for [UID:000230] as the source-facing method name because [UID:0002HZ] already owns the guarded class method shape and has four direct callers. [UID:000230] lacks the `this+0x08` table-count guard and has no proven member-call route.
- `GameServerConfig::SendNationRequest`: possible as a private member name, but rejected as stronger-than-evidence because no `this` is used and no caller establishes a member dispatch.
- `PacketBuffer` or `Socket` helper: rejected because the function is not a generic serialization/send primitive; it is a specific GameServerConfig nation-entry request payload.
- MapPane-owned helper: rejected because the payload, sibling body, support pages, and `g_gameServerNationTable` all tie the behavior to GameServerConfig/nation entries. The stale MapPane history in broader [UID:0001AO] is generated/caller-biased pollution for this exact helper.

Impact:

- Keep [UID:000230] under file owner/emitter [UID:0000JP].
- Do not change [UID:00005O] class docs to list this as a proven public/member method.
- First-draft C++ is appropriate as a private file-local helper.

### Retained Helper Versus Duplicate/Folded Source Shape

Best inference: retained private file-local helper, probably dead or unreachable by static routes in the current executable, while [UID:0002HZ] is the live guarded path.

Evidence:

- The raw body is a complete compiler-shaped function with security-cookie prologue/epilogue, coherent stack local, coherent callees, and exact padding on both sides.
- It duplicates the packet-construction tail used by [UID:0002HZ].
- There is no static call/pointer route to the raw start.
- [UID:0002HZ] has four direct callers and includes the missing source-level condition: only request entries when `this+0x08` table count is zero.

Rejected alternatives:

- Merge [UID:000230] into [UID:0002HZ]: rejected because [UID:000230] has its own prologue, epilogue, stack cookie, and padding, and occupies a separate exact function-shaped body outside [UID:0002HZ]'s range.
- Treat [UID:000230] as an inline artifact: rejected because the body is not an inline fragment inside a caller; it is independently framed and ends in `ret`.
- Treat [UID:000230] as live via hidden table: no direct table/pointer evidence was found. This remains possible only in a non-static or obfuscated route, but there is no current evidence to make that the primary interpretation.
- Treat [UID:000230] as arbitrary/dead bytes: rejected because the body decodes to coherent packet-send code and shares exact payload semantics with live [UID:0002HZ].

Impact:

- The no-caller state caps confidence below fully proven live method quality, but it no longer justifies blank formal C++.
- The target should remain a separate source-bearing child, not a non-emitting index and not merged into the sibling.

### Packet Layout And Protocol Names

Best supported packet layout:

| Offset | Bytes | Writer | Best descriptive name |
| --- | --- | --- | --- |
| `+0x00` | `66` | `PacketBufferWriteUInt8` | `kGameServerConfigOpcode` |
| `+0x01..+0x02` | `40 00` | `PacketBufferWriteUInt16BE` | `kNationEntryRequestCode` |
| `+0x03` | `01` | `PacketBufferWriteUInt8` | `kNationEntryRequestFlag0` |
| `+0x04` | `01` | `PacketBufferWriteUInt8` | `kNationEntryRequestFlag1` |
| `+0x05` | `00` | `PacketBufferWriteUInt8` | `kNationEntryRequestReserved0` |
| `+0x06` | `01` | `PacketBufferWriteUInt8` | `kNationEntryRequestFlag3` |
| `+0x07` | `01` | `PacketBufferWriteUInt8` | `kNationEntryRequestFlag4` |
| `+0x08` | `00` | `PacketBufferWriteUInt8` | `kNationEntryRequestReserved1` |

Exact fixed payload: `66 40 00 01 01 00 01 01 00`.

High-probability protocol inference:

- `0x66` is a GameServerConfig/game-server request opcode in this source family, not a PacketBuffer or Socket opcode.
- `0x4000` is a big-endian subcommand/request id for nation-entry data.
- The six trailing one-byte constants are request selector/flag bytes. They are part of the payload and length, not PacketBuffer scratch zeros, because they are explicitly written before the length-9 send.
- The two zero bytes at offsets `+0x05` and `+0x08` are payload bytes; they are not the writer helper's spare terminators.

Unresolved exact semantics:

- Current client-side evidence does not name the six trailing flag positions. No inbound server-side schema or symbolic parser was found that proves whether the one bytes mean language, region, enabled categories, table generation, or requested columns.
- The strongest safe field labels are descriptive ordinal labels plus reserved labels for the zero positions. The formal C++ can preserve exact behavior with local constants and comments without pretending the original names are known.

Rejected alternatives:

- Treat the `0x00` bytes as PacketBuffer helper terminators: rejected because the call sequence explicitly writes zero at packet offsets `5` and `8`, and the final send length is 9.
- Treat `0x4000` as little-endian `0x0040`: rejected because [UID:0003YJ] establishes `0x005753a0` as `PacketBufferWriteUInt16BE`, and the actual bytes are `40 00`.
- Treat the length as 10 due to helper spare zero writes: rejected because `push 9` is the send length and [UID:0000M8]/[UID:0003YJ] already distinguish helper scratch terminators from payload length.

Impact:

- Packet field semantics are sufficient for first-draft C++ with descriptive constants.
- The exact trailing flag meanings should remain a documented low-impact uncertainty; it caps confidence from 92+ but not source placement or reconstruction.

### PacketBuffer Writer And Sender Names

Best names:

- `0x00575380`: `PacketBufferWriteUInt8(unsigned char value, unsigned char* out)`.
- `0x005753a0`: `PacketBufferWriteUInt16BE(unsigned short value, unsigned char* out)`.
- `0x0067a7ec`: `Socket *g_packetSender`.
- `0x00574bb0`: `Socket::QueueAndSendPacket(const unsigned char* data, int length)` or source-equivalent `QueueAndSendPacket(g_packetSender, data, length)` depending on final Socket header style.

Evidence:

- [UID:0003YJ], [UID:0000M8], and [UID:0000V1] already support the scalar writer names and spare-zero behavior.
- [UID:0001HU] owns `0x00574bb0` as the Socket queue/send helper.
- [UID:0000Q5] and [UID:0001P0] support `g_packetSender` as the current process-wide Socket pointer, with 489 references and Socket lifecycle writes.

Rejected alternatives:

- `CashShopRequest`-owned sender names: rejected by [UID:0000Q5]/[UID:0001P0] as stale generated aliasing.
- `PacketBuffer::Send` ownership for `0x00574bb0`: rejected because [UID:0001HU] documents Socket ownership and the binary passes `g_packetSender` in `ecx`.

Impact:

- The helper can use source-facing writer and sender names without `sub_` or `dword_` placeholders.
- The generated-output blocker "packet-buffer/sender names unresolved" should be removed from [UID:000230].

### GameServerConfig Nation-Entry Table Relationship

Best relationship:

- [UID:000230] sends the unconditional nation-entry request packet.
- [UID:0002HZ] is the live class method that checks whether the `GameServerConfig` nation-entry table has entries, then emits the same request packet only if the table is empty.
- `g_gameServerNationTable` / [UID:0000Q1] is the process-wide pointer to the same nation-entry table family.
- `GameServerNationEntry` / [UID:0001UP] records are 68 bytes (`uint16_t nationId; wchar_t label[33];`), which matches the support docs' nation table parser/constructor family, not the packet scratch local by itself.

Rejected alternatives:

- This helper populates the table: rejected; it only builds and sends a fixed request. Population/parsing belongs to the sibling GameServerConfig/nation-entry parser pages.
- This helper reads table count: rejected for [UID:000230]; the table-count guard exists in [UID:0002HZ], not here.

Impact:

- Support docs should describe this helper as the unconditional send body used by the nation-entry request family, not as the parser or table owner.

### Source Placement

Ranked placement:

1. [UID:0000JP] `NexusTK/map/GameServerConfig.cpp` private/file-local helper: accepted. It matches adjacency, sibling, packet meaning, and file support docs while avoiding unproven class membership.
2. [UID:00005O] `GameServerConfig` private method: plausible but rejected for current metadata because the body has no `this` use and no proven caller.
3. [UID:0000M8]/PacketBuffer: rejected; this is not a generic serialization helper.
4. [UID:0000DD]/Socket: rejected; the only Socket behavior is the final send call.
5. MapPane or map constructor generated owner: rejected as stale caller-biased/generated pollution from the broader [UID:0001AO] mixed island.

Impact:

- Keep `CANONICAL_OWNER:0000JP`, `EMITTER_UIDS:0000JP`.
- Do not change [UID:000230] to no-owner; the GameServerConfig file route is stronger than no-owner.
- Do not claim [UID:00005O] class method ownership in by-class docs; list it as file-local/raw helper support if mentioned.

## Recommended Metadata And Score Changes

Recommended [UID:000230] metadata replacement:

```yaml
COMPLETION:86
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000JP
EMITTER_UIDS:0000JP
```

Rationale:

- Completion rises from 84 to 86 because exact PE boundary, bytes, packet layout, callees, sender/global names, sibling relation, source route, and C++ draft are now resolved to a usable level.
- Confidence rises from 88 to 90 because fresh route scanning validates the no-caller/no-pointer state and the support docs now resolve writer/sender names. Confidence should not exceed 90 yet because the raw helper still lacks a proven static caller, IDA function record, and original protocol names for the six trailing payload bytes.
- `RECONSTRUCTABLE` remains true because the body is exact and self-contained.
- Owner/emitter stay [UID:0000JP] because file-local GameServerConfig placement is strongest.

Do not use stale `95/95` gate wording. Under the current B-agent code-entry policy, this target has sufficient evidence and recommended metadata for first-draft C++.

## First-Draft C++ Recommendation

Populate [UID:000230] formal C++ with a private file-local helper. The draft intentionally uses descriptive constants for the protocol fields whose original names are not proven, while preserving exact writer calls and send length.

```cpp
static void SendGameServerNationEntryRequestPacket()
{
    enum
    {
        kGameServerConfigOpcode = 0x66,
        kNationEntryRequestCode = 0x4000,
        kNationEntryRequestPacketLength = 9
    };

    unsigned char packet[0x44];

    PacketBufferWriteUInt8(kGameServerConfigOpcode, packet);
    PacketBufferWriteUInt16BE(kNationEntryRequestCode, packet + 1);
    PacketBufferWriteUInt8(1, packet + 3);
    PacketBufferWriteUInt8(1, packet + 4);
    PacketBufferWriteUInt8(0, packet + 5);
    PacketBufferWriteUInt8(1, packet + 6);
    PacketBufferWriteUInt8(1, packet + 7);
    PacketBufferWriteUInt8(0, packet + 8);

    g_packetSender->QueueAndSendPacket(packet, kNationEntryRequestPacketLength);
}
```

Draft notes:

- `static` reflects the recommended file-local source placement.
- No `GameServerConfig *this` parameter is included because the binary body has no receiver use.
- `unsigned char packet[0x44]` matches the compiler local size and the local buffer base at `[ebp-0x44]`. The source may have used a project packet buffer type or a named scratch array; this draft preserves stack shape better than a 9-byte local.
- The packet writers are kept as helper calls instead of collapsing to a byte array because the binary emits the writer calls and PacketBuffer support docs name those helpers.
- No null check is added around `g_packetSender`; the binary directly loads the global into `ecx` and calls the Socket send helper.
- If the final Socket API is represented in generated C++ as a free helper rather than a method, the last line can be mechanically adapted to `QueueAndSendPacket(g_packetSender, packet, kNationEntryRequestPacketLength);` without changing this target's behavioral reconstruction.

Optional support-context draft for [UID:0002HZ] after supervisor review:

```cpp
void GameServerConfig::RequestNationEntries()
{
    if (this->nationEntries.Count() > 0)
        return;

    SendGameServerNationEntryRequestPacket();
}
```

That sibling draft is not a required direct edit for this assignment, but it explains why [UID:000230] should remain a separate file-local helper and why [UID:0002HZ] should own the guarded public/member source shape.

## Exact Supervisor Changes Required

### Target Page [UID:000230]

Placement context: replace the current stale reconstruction/final-C++ blocker text that says packet-buffer/sender names, retained/folded source shape, or old 95/95 gate concerns prevent formal C++.

Suggested replacement text:

```text
2026-06-18 B003 source-quality recheck: raw PE/Capstone reanalysis confirms the exact half-open range `0x00503960-0x005039ed`, predecessor `ret 4` plus `int3` padding at `0x0050395f`, successor `int3` padding at `0x005039ed-0x005039f0`, and a complete `0x44`-local stack-cookie function body. No direct rel32 caller, VA/RVA/raw-offset pointer, or table route to `0x00503960` was found in the refreshed scan; the modeled sibling [UID:0002HZ] `GameServerConfig::RequestNationEntries` at `0x00503c70` still has four rel32 callers and includes the table-count guard absent here. Treat this target as a retained private file-local GameServerConfig packet helper, not a proven `GameServerConfig` member and not a fold into [UID:0002HZ].

Packet layout is fixed and exact: byte `0x66`, big-endian word `0x4000`, then one-byte payload constants `1, 1, 0, 1, 1, 0`, sent with length 9. The writer helpers are best named `PacketBufferWriteUInt8` at `0x00575380` and `PacketBufferWriteUInt16BE` at `0x005753a0`; `0x0067a7ec` is the process-wide `Socket *g_packetSender`; `0x00574bb0` is the Socket queue/send helper. The strongest source-facing helper name is `SendGameServerNationEntryRequestPacket()`. The six trailing payload constants are request selector/flag bytes; exact original field names remain unproven from client-side evidence, so use descriptive ordinal/reserved names rather than `sub_`/`dword_` placeholders.

Formal C++ should be populated as a private file-local helper under [UID:0000JP] `GameServerConfig.cpp`. The remaining no-caller state caps confidence but is no longer a formal-C++ blocker.
```

Metadata replacement:

```text
COMPLETION:86
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000JP
EMITTER_UIDS:0000JP
```

Recommended formal C++ block: use the `SendGameServerNationEntryRequestPacket()` draft in the previous section.

### Support Doc [UID:0000JP] `by-file/GameServerConfig.md`

Placement context: in the raw helper / source contents section where `0x00503960-0x005039ed` is currently described as unresolved or blank-C++.

Suggested replacement text:

```text
- [UID:000230] `0x00503960-0x005039ed`: retained private file-local helper, best named `SendGameServerNationEntryRequestPacket()`. It builds the fixed nine-byte GameServerConfig nation-entry request packet `66 40 00 01 01 00 01 01 00` with `PacketBufferWriteUInt8` / `PacketBufferWriteUInt16BE`, reads `Socket *g_packetSender`, and queues the packet through the Socket send helper with length 9. Fresh B003 route scanning still finds no direct caller or pointer route to the raw start, so it should not be promoted to a confirmed `GameServerConfig` member. It is nevertheless source-authored and reconstructable enough for private file-local first-draft C++.
```

Also replace any stale statement that all raw GameServerConfig starts must remain blank until final 95/95 names with:

```text
The old 95/95-only C++ gate is stale for B-agent source-quality targets. For [UID:000230], the raw no-caller state remains documented, but packet writer/sender names and file-local source placement are now strong enough to emit a first-draft private helper.
```

### Support Doc [UID:00005O] `by-class/GameServerConfig.md`

Placement context: in the method/support table entry for the raw nation request helper.

Suggested replacement text:

```text
- [UID:000230] is a GameServerConfig.cpp file-local support helper rather than a confirmed `GameServerConfig` member. It sends the same fixed nation-entry request packet used by [UID:0002HZ], but it has no `this` use and no direct caller/pointer route to `0x00503960`. Keep member ownership on [UID:0002HZ] for the guarded `RequestNationEntries()` method; mention [UID:000230] only as private file-level support.
```

### Support Doc [UID:0002HZ] `GameServerConfig::RequestNationEntries`

Placement context: in reconstruction notes where the packet send is described inline or blank-C++ is deferred.

Suggested insert:

```text
B003 2026-06-18 reconciliation with [UID:000230]: the body at `0x00503c70` is the live guarded `GameServerConfig::RequestNationEntries()` method. It checks the nation-entry table count at `this+0x08` and, when empty, emits the same fixed nine-byte request packet as the retained file-local helper [UID:000230]. A clean source draft may call `SendGameServerNationEntryRequestPacket()` after the empty-table guard, but [UID:0002HZ] remains the only route-proven member method because it has four direct rel32 callers.
```

### Support Docs Not Requiring Changes

- [UID:0000M8], [UID:0001HZ], [UID:0003YJ], and [UID:0000V1] already preserve PacketBuffer writer names and spare-zero behavior at equal-or-greater specificity for this target.
- [UID:0000Q5] and [UID:0001P0] already preserve `Socket *g_packetSender` at equal-or-greater specificity.
- [UID:0001HU] already preserves `0x00574bb0` as the Socket queue/send helper at equal-or-greater specificity.
- [UID:0001AO] should not absorb [UID:000230]; it starts at `0x005039f0` and is a mixed non-emitting aggregate for following GameServerConfig/MapPane ranges.

## Coverage Report Replacement Text

Placement context: replace the existing [UID:000230] row in `by-memory/-coverage-report.md`.

```text
    - [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md) 0x00503960-0x005039ed | retained private nation-entry request packet helper | GameServerNationRequestPacketRawHelper : reconstructable : 86% : very strong : B003 2026-06-18 PE/Capstone recheck confirms exact 141-byte function-shaped body, predecessor/successor `int3` padding, fixed packet `66 40 00 01 01 00 01 01 00`, `PacketBufferWriteUInt8` / `PacketBufferWriteUInt16BE` writers, `Socket *g_packetSender`, and Socket queue/send call with length 9. Fresh VA/RVA/raw-offset and rel32 scans still find no direct caller or pointer route to `0x00503960`, while sibling [UID:0002HZ] has four rel32 callers and owns the guarded member method; keep owner/emitter [UID:0000JP] as a file-local retained helper and populate first-draft C++.
```

## Validation Commands For Supervisor

Run after applying the target/support/coverage changes:

> Executable block R001 was removed from this report and preserved verbatim in [000230-GameServerNationRequestPacketRawHelper-source-quality-removed.md](000230-GameServerNationRequestPacketRawHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected caveat from current dry run: unrelated `autogen_cpp_conflict 0000K5 auto-generated/NexusTK/input/IMEPanes.cpp nonempty file lacks validator autogen sentinel` may still appear unless separately addressed. Before formal C++ is applied, `autogen_cpp_noop 0000JP auto-generated/NexusTK/map/GameServerConfig.cpp no assembled code for root` is expected because `GameServerConfig.cpp` is currently empty; after [UID:000230] formal C++ is populated, that no-op should be rechecked.

## Remaining Blockers

- Exact original names for the six trailing one-byte payload selector fields are not proven. Evidence checked: target byte sequence, sibling [UID:0002HZ], PacketBuffer helper docs, GameServerConfig file/class docs, `g_gameServerNationTable`, `GameServerNationEntry`, and prior B-agent reports. Rejected alternatives include treating the zero bytes as helper terminators or assigning table-column semantics without a server-side schema. Impact: keep descriptive ordinal/reserved constant names in C++; confidence capped at 90 rather than 92+.
- No route to `0x00503960` is proven. Evidence checked: rel32 call/jump scan, VA/RVA/raw-offset dword scan, existing IDA-backed docs, support docs, and positive-control global pointer scan. Rejected alternatives include hidden table route as primary claim, direct live method route, and merge into [UID:0002HZ]. Impact: keep file-local retained-helper wording, do not list as confirmed class method, confidence capped at 90.
- IDA MCP was unavailable during this pass. Existing docs include prior live IDA checks, and fresh raw PE scans independently validated boundaries, bytes, and static route absence. Impact: no blocker to report completion, but supervisor may optionally refresh IDA function/xref state before applying if MCP becomes available.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/000230-GameServerNationRequestPacketRawHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"000230"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000230-GameServerNationRequestPacketRawHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/000230-GameServerNationRequestPacketRawHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000230"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
