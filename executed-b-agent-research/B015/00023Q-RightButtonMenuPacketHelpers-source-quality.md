** TARGET-REPORT-UID:00023Q **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B015 Report - [UID:00023Q] RightButtonMenuPacketHelpers Source Quality

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/00023Q-RightButtonMenuPacketHelpers-source-quality.md`

Target: `source-3/project-documentation/by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md`

Assignment: B-agent source-quality / heuristic research for `RightButtonMenuPacketHelpers`.

No target/support `by-*` docs, generated files, IDA database state, or `by-memory/-coverage-report.md` were edited during this report pass. The superseded `0002K7` assignment was not worked.

## Summary Recommendation

`0x00555780-0x005558c2` is a source-authored right-click menu packet-helper island containing two complete private/file-local helper bodies plus six bytes of internal `0xcc` alignment. The current no-code wording is stale: the range has a valid direct class owner/emitter, the current gate is already met, and the helper bodies are source-shaped enough for first-draft C++ if the code is emitted as private static helpers in `RightButtonMenuPane.cpp`.

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:88
CANONICAL_OWNER:0000C0
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000C0
```

Recommended source route:

- Direct owner/emitter: [UID:0000C0] `RightButtonMenuPane`.
- Source-file root: [UID:0000N7] `RightButtonMenuPane`, generated at `auto-generated/NexusTK/ui/menu/RightButtonMenuPane.cpp`.
- Source shape: two `static __stdcall` file-local packet helpers adjacent to the right-click menu implementation. They have no `this` receiver, but their behavior and placement are menu-specific; do not move them to Socket/ProtocolSend only because they call the shared sender.
- C++ policy: first-draft C++ is justified. The no-direct-caller caveat caps final confidence, but it is not an exact no-code proof because the bodies are complete, bounded, non-padding packet builders and current ownership/emitter routing is valid.

Best current source-facing helper names/signatures:

```cpp
static void __stdcall SendRightButtonTargetActionPacket(int targetId);
static void __stdcall SendRightButtonNameCommandPacket(const wchar_t *targetName);
```

The second helper is probably the right-click name/whisper route because it consumes the selected target name and sends a dot-prefixed name packet, but no direct caller survives in the current static graph. Keep the first-draft name semantic-but-neutral (`NameCommand`) rather than hard-coding `Whisper` until the `OnEvent` row-to-helper mapping is proven.

## Evidence Checked

Instruction/context docs checked:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`, especially Rules 21, 24, 26, and 27.
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B015/goal.md`

Target and direct support docs checked:

- [UID:00023Q] `by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md`
- [UID:0000C0] `by-class/RightButtonMenuPane.md`
- [UID:0000N7] `by-file/RightButtonMenuPane.md`
- [UID:0001FX] `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md`
- [UID:0001HU] `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- [UID:0000Q5] `by-global/g_packetSender.md`
- [UID:0001P0] `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
- [UID:0001HZ] `by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md`
- [UID:0003YJ] `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md` through the split/index page
- [UID:0003TU] `by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md`
- [UID:00026A] `by-memory/0x00622f54-0x006230c8.RegionMenuPaneReadOnlyData.md`
- [UID:0001Q0] `by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md`
- [UID:0002LS] `by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md`
- Current `by-memory/-coverage-report.md` row for [UID:00023Q]
- Current `auto-generated/-ag-memory-coverage.md` row for [UID:00023Q]
- Current generated `auto-generated/NexusTK/ui/menu/RightButtonMenuPane.cpp`

Resolved-name/support evidence checked:

- `project-level/-resolved-multple-aliases.md`: `sub_516030` -> `GetMemoryMan`; `sub_516220` -> `MemmoveWrapper` / `memmove`.
- `project-level/-resolved.md` / `project-level/-unresolved.md` entries for stale raw names on this target.
- Ghidra combined function data:
  - `hooks-generation/tests/function_data/combined/functions/0x00555780.json`
  - `hooks-generation/tests/function_data/combined/functions/0x005557e0.json`

Current-session IDA MCP status:

- Local IDA MCP was unavailable in this session (`127.0.0.1:13337` did not connect). I did not rely on new live IDA RPC facts.
- Current conclusions combine existing IDA-backed docs with fresh raw PE/Capstone checks and the stored Ghidra function-data JSON.

Fresh raw PE checks:

- PE used: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- SHA-256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c4ac`, raw `0x00000400-0x0020ba00`

Raw range map:

| Range | Raw offset | Size | SHA1 | Result |
| --- | ---: | ---: | --- | --- |
| `0x0055577b-0x00555780` | `0x154b7b` | `0x5` / 5 | `88ff73c4951dc5fb6818cca931fe5836d7533a0b` | all `0xcc` prepad |
| `0x00555780-0x005557da` | `0x154b80` | `0x5a` / 90 | `eee44090b106d7aedb66941bd76fa3e1e0cc39e0` | first helper |
| `0x005557da-0x005557e0` | `0x154bda` | `0x6` / 6 | `dd750025890f36a60bf67d4ad12665dbab2aaa24` | all `0xcc` internal alignment |
| `0x005557e0-0x005558c2` | `0x154be0` | `0xe2` / 226 | `c35c5e15f322ef26ae3637bd18d211eb3e9bbc51` | second helper |
| `0x005558c2-0x005558d0` | `0x154cc2` | `0xe` / 14 | `4e39fb1dc8232678721303434696cefc67b72986` | all `0xcc` postpad |

Fresh liveness/reference scan:

- Whole `.text` rel32 call/jump scan found zero `E8`/`E9` targets into `0x00555780-0x005557da`.
- Whole-file absolute dword scan found zero dword values into `0x00555780-0x005557da`.
- Whole `.text` rel32 call/jump scan found zero `E8`/`E9` targets into `0x005557e0-0x005558c2`.
- Whole-file absolute dword scan found zero dword values into `0x005557e0-0x005558c2`.
- Stored Ghidra data also reports `num_callers: 0` and empty caller lists for both helpers.

This is stronger than the current target page's start-address-only no-xref caveat: no static direct refs into either body range were found, not just no refs to the two starts.

## Corrected Helper Behavior

### `0x00555780-0x005557da`

Best name/signature:

```cpp
static void __stdcall SendRightButtonTargetActionPacket(int targetId);
```

Raw behavior:

- Allocates a local packet scratch buffer at `ebp-0x14`.
- Calls `PacketBufferWriteByte(0x4a, packet + 0)`.
- Calls `PacketBufferWriteByte(0, packet + 1)`.
- Calls `PacketBufferWriteUInt32BE(targetId, packet + 2)`.
- Writes `packet[6] = 0`.
- Sends exactly 6 bytes through `g_packetSender->QueueAndSendPacket(packet, 6)`.
- Returns with `ret 4`, matching a one-argument `__stdcall` helper.

Important correction to current doc:

- The current target text says "caller byte argument." That is wrong. The argument at `[ebp+8]` is passed to the 32-bit big-endian writer at `0x005753f0`, so packet bytes are:

```text
[0x4a][0x00][targetId byte 3][targetId byte 2][targetId byte 1][targetId byte 0]
```

The zero at `packet[6]` is an unsent terminator/safety byte. It is not part of the six-byte payload.

Opcode/subcommand semantics:

- `0x4a` is the packet opcode/family for this helper.
- The second byte is fixed subcommand/action `0`.
- The 32-bit field should be named `targetId` because [UID:0001FX] documents `RightButtonMenuPane::SetTargetNameAndId` storing a target id at `this+0xfc`, and the right-click action path dispatches target-object menu actions.
- The exact right-click menu row using this helper is still not proven. Do not name it `SendTradePacket`, `SendGroupInvitePacket`, or similar until a direct caller/row mapping is recovered.

### `0x005557e0-0x005558c2`

Best name/signature:

```cpp
static void __stdcall SendRightButtonNameCommandPacket(const wchar_t *targetName);
```

Raw behavior:

- Saves `targetName` from `[ebp+8]`; returns early if `targetName[0] == L'\0'`.
- Calls `GetMemoryMan()` and later uses the returned object as the `MemmoveWrapper` receiver; source should describe this as `memmove`.
- Writes prefix byte `'.'` / `0x2e` into a local packet buffer.
- Measures the wide string manually, excluding the null terminator, then sign-extends the low 16 bits of the wide length before the Win32 call.
- Calls `WideCharToMultiByte(CP_ACP, 0, targetName, wideLength, convertedName, 0x100, NULL, NULL)`.
- If `convertedLength >= 0x100`, jumps to `___report_rangecheckfailure`.
- Writes `convertedName[convertedLength] = 0`.
- Writes converted length as one byte at packet offset `1`.
- Copies `convertedLength` bytes from `convertedName` to packet offset `2`.
- Computes `packetLength = convertedLength + 2`.
- If `packetLength >= 0x12c`, jumps to `___report_rangecheckfailure`.
- Writes `packet[packetLength] = 0`.
- Sends exactly `packetLength` bytes through `g_packetSender->QueueAndSendPacket(packet, packetLength)`.
- Returns with `ret 4`, matching a one-argument `__stdcall` helper.

Stack/array correction:

- The stack frame is `0x230` / 560 bytes.
- The conversion buffer is `0x100` / 256 bytes at `ebp-0x230`.
- The packet buffer begins at `ebp-0x130`, but the usable source array is `0x12c` / 300 bytes before the security cookie. Current wording that treats `0x130` / 304 as the packet array size should be replaced with "`packet[0x12c]` begins at `ebp-0x130`; the four bytes above it are the cookie/local trailer."

Packet layout:

```text
['.'][convertedNameLength][convertedName bytes...]
```

The trailing zero written after the payload is not sent. Empty wide strings do not send any packet. A non-empty string that converts to zero bytes still sends the two-byte prefix/zero-length packet.

Semantic inference:

- The helper is likely the right-click target-name command path, probably for the `Whisper` row, because it consumes a selected target name and sends a dot-prefixed name packet.
- The original symbol/name is still not recoverable from current static refs. Use `SendRightButtonNameCommandPacket` now; upgrade to a `Whisper`-specific name only if a caller or protocol table proves that row.

## Heuristic / Inference Reanalysis

| Issue | Best defensible conclusion | Evidence checked | Rejected alternatives | Impact |
| --- | --- | --- | --- | --- |
| Source owner/emitter | Keep direct owner/emitter [UID:0000C0] `RightButtonMenuPane`. | Target metadata, class/file docs, physical placement after the right-click menu core, packet behavior, and valid parent gate. | Socket/ProtocolSend owner; broad file-only parent; VoteMenuPane owner. | No owner/emitter change needed. |
| Source file | Keep source-file root [UID:0000N7] `RightButtonMenuPane.cpp`. | Class page emits through file page, and helpers are adjacent to `RightButtonMenuPaneCore`. | New protocol file or moving to MapPane because of a separate opcode helper. | Support docs should describe file-local static helpers in `RightButtonMenuPane.cpp`. |
| Aggregate/split policy | Keep [UID:00023Q] as one packet-helper island with two source bodies and one internal padding row. | Exact child bodies are short, adjacent, and menu-specific; internal `0xcc` is already tracked. | Merge into [UID:0001FX] core; split into two separate child pages in this pass; mark aggregate no-code. | No split required before first-draft C++. |
| Raw liveness | No direct static liveness is proven. | Existing IDA docs, stored Ghidra caller lists, fresh rel32 scan, and fresh absolute dword scan all found zero refs into either helper body. | Invent direct callers from the core method; treat no xrefs as padding. | Cap confidence; do not block source draft. |
| First helper argument | `int targetId` / 32-bit target/object id. | Call to `0x005753f0` big-endian 32-bit writer; target-name setter stores id at `this+0xfc`. | "caller byte argument" from current target doc. | Target doc must be corrected. |
| First helper opcode/subcommand | Opcode `0x4a`, subcommand/action byte `0`, big-endian target id. | Capstone disassembly and Ghidra JSON agree. | Treat trailing zero as sent payload; use raw `FUN_00555780`. | Exact packet layout is ready. |
| Second helper parameter | `const wchar_t *targetName`. | Ghidra signature `LPCWSTR`; raw code dereferences UTF-16 chars and calls `WideCharToMultiByte`. | `char *`, `CString`, or object method `this`. | Signature is source-quality. |
| Second helper packet | Dot-prefixed length-counted CP_ACP name packet. | Writes `0x2e`, length byte, copied converted bytes, sends `converted+2`. | Null-terminated sent string; packet opcode plus hidden subtype; UTF-16 packet. | Formal behavior can be documented exactly. |
| Length/range behavior | Empty name returns; conversion cap is `0x100`; packet usable cap is `0x12c`; range failures are compiler/runtime checks from indexed fixed-array writes. | Raw comparisons at `0x00555850` and `0x00555889`; Ghidra decompilation. | Handwritten `___report_rangecheckfailure` source; silent truncation. | C++ should use fixed arrays and document compiler-generated checks. |
| `g_packetSender` | Use [UID:0000Q5] `g_packetSender`, best type `Socket *`; send API `QueueAndSendPacket`. | `g_packetSender` global pages and `QueueAndSendPacket` page. | Generated `CashShopRequest::meth_0x574bb0`, `g_pCashShopRequest`, or feature-local sender. | Target doc should clear generated-name pollution. |
| PacketBuffer helpers | Use `PacketBufferWriteByte` and `PacketBufferWriteUInt32BE`. | PacketBuffer split/index, resolved aliases, Ghidra helper names. | `sub_575380`, `sub_5753F0`, or "caller byte write." | Target/support docs should use resolved names. |
| Memory helper names | `GetMemoryMan` and `MemmoveWrapper` are resolved, but source-style code should call `memmove`. | Resolved aliases and raw `ecx=edi` before `0x516220`. | Leave `sub_516030`/`sub_516220` unresolved in target. | Clear unresolved references in target text. |
| Action-row mapping | Best current inference: first helper is a target-id right-click action; second helper is a target-name command, probably `Whisper`. | Menu core docs list Look/Trade/Whisper/Group/Info; setter stores id/name; no direct refs prove row. | Final names `SendTradePacket`, `SendGroupInvitePacket`, or `SendWhisperPacket` as formal names today. | Use neutral helper names and document uncertainty. |
| C++ readiness | Ready for first-draft file-local helpers. | Reconstructable, owner/emitter valid, average gate already above 85, exact packet layouts and signatures solved. | Exact no-code proof; stale below-95/no-direct-caller blank policy. | Populate target C++ after supervisor acceptance. |
| Score | Raise `85/86` to `87/88`. | Corrected argument width, stack array sizing, no-static-liveness scan into whole body ranges, Ghidra signature confirmation, resolved helper/global names, and C++ policy. | Leave stale score; push to near-final despite no callers. | Improves source-quality without hiding liveness caveat. |

## First-Draft C++ Readiness

Recommended target `RECONSTRUCTION_CPP` after supervisor acceptance:

```cpp
static void __stdcall SendRightButtonTargetActionPacket(int targetId)
{
    unsigned char packet[7];

    PacketBufferWriteByte(0x4a, packet);
    PacketBufferWriteByte(0, packet + 1);
    PacketBufferWriteUInt32BE(targetId, packet + 2);
    packet[6] = 0;

    g_packetSender->QueueAndSendPacket(packet, 6);
}

static void __stdcall SendRightButtonNameCommandPacket(const wchar_t *targetName)
{
    char convertedName[0x100];
    unsigned char packet[0x12c];

    if (targetName[0] == L'\0')
        return;

    PacketBufferWriteByte('.', packet);

    short wideLength = (short)wcslen(targetName);
    int convertedLength = WideCharToMultiByte(
        CP_ACP,
        0,
        targetName,
        wideLength,
        convertedName,
        sizeof(convertedName),
        NULL,
        NULL);

    convertedName[convertedLength] = '\0';
    PacketBufferWriteByte((unsigned char)convertedLength, packet + 1);
    memmove(packet + 2, convertedName, convertedLength);

    int packetLength = convertedLength + 2;
    packet[packetLength] = 0;

    g_packetSender->QueueAndSendPacket(packet, (short)packetLength);
}
```

Source-style notes to include near the code:

- Do not add a null-pointer guard for `targetName`; the binary only rejects empty strings after dereferencing the pointer.
- Do not emit `___security_check_cookie`, `___report_rangecheckfailure`, `FUN_00555780`, `FUN_005557e0`, `sub_575380`, `sub_5753F0`, `sub_574BB0`, or `CashShopRequest::meth_0x574bb0` in formal source.
- The compiler-generated range-check paths correspond to indexed writes into `convertedName[0x100]` and `packet[0x12c]`. The source model should use fixed arrays and explain the checks in prose.
- The second helper's `short wideLength` is intentional: the binary sign-extends a 16-bit measured wide length before `WideCharToMultiByte`. Existing `RightButtonMenuPane` target names are fixed-size (`0x21` wide chars), so this does not create practical truncation for the known route.

## Recommended Target Doc Changes

Apply to `source-3/project-documentation/by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md` after supervisor acceptance:

1. Header metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000C0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000C0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Populate the formal C++ block with the two `static void __stdcall` helpers shown above.

3. Replace the stale status sentence:

```text
Disposition: reconstructable NexusTK project code; C++ intentionally blank because direct caller provenance and helper names are not final-source quality.
```

with:

```text
Disposition: reconstructable NexusTK project code. This page now carries first-draft source-quality C++ for two private/file-local right-click menu packet helpers. The no-direct-caller evidence remains a liveness caveat and score cap, but no longer blocks source emission because the helper bodies, signatures, packet layouts, owner route, and support names are resolved enough for a first draft.
```

4. Replace the first covered-range behavior with:

```text
`0x5a` / 90-byte raw helper that writes opcode `0x4a`, fixed subcommand/action byte `0`, and the caller's 32-bit `targetId` in big-endian order, then queues exactly six bytes through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). The explicit zero at packet offset `6` is an unsent terminator/safety byte.
```

5. Replace the second covered-range behavior with:

```text
`0xe2` / 226-byte raw helper that sends a dot-prefixed, one-byte-length, CP_ACP-converted target-name packet. It rejects empty wide strings, converts up to `0x100` bytes into a local ANSI buffer, copies the converted bytes after `'.'` and the length byte, writes an unsent terminator, and queues `convertedLength + 2` bytes through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
```

6. Replace the touched-state rows that mention `caller byte argument`, `0x130` packet size, and unresolved raw callees with:

```text
The first helper's stack packet is seven bytes: six sent bytes plus an unsent terminator. The argument is a 32-bit target id written by `PacketBufferWriteUInt32BE`, not a caller byte.
```

```text
The second helper has a `0x100` / 256-byte conversion buffer and a `0x12c` / 300-byte packet buffer beginning at `ebp-0x130`; the remaining four bytes before `ebp` are the cookie/local trailer. Source should model these as `char convertedName[0x100]` and `unsigned char packet[0x12c]`.
```

```text
Use resolved helper/global names: `PacketBufferWriteByte`, `PacketBufferWriteUInt32BE`, `memmove`/`MemmoveWrapper`, `GetMemoryMan`, `QueueAndSendPacket`, and [UID:0000Q5] `g_packetSender` (`Socket *`). Treat `CashShopRequest::meth_0x574bb0` and raw `sub_*` names as generated-name pollution.
```

7. Add the fresh liveness evidence:

```text
2026-06-19 B015 raw PE scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found zero `.text` `E8`/`E9` rel32 branches and zero whole-file absolute dword references into either helper body range (`0x00555780-0x005557da` or `0x005557e0-0x005558c2`). Stored Ghidra data likewise reports zero callers for both helpers. This preserves the no-direct-liveness caveat while strengthening the statement that the bodies themselves are exact source-authored packet helpers rather than padding.
```

8. Update the rebuild handling text:

```text
Treat these as private/file-local right-click menu packet helpers emitted through [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md) into [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md). Keep the island separate from [UID:0001FX][RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md) for coverage/range ownership, but source placement is adjacent to the core menu implementation. Direct callers and exact action-row names remain unresolved, so use neutral helper names rather than invented `Trade`/`Group`/`Whisper` names.
```

9. Replace stale score rationale with:

```text
Completion `87`: exact ranges, padding, raw hashes, stack-array sizes, byte order, opcode/subcommand layouts, packet sender, helper/global names, range-check behavior, stronger no-static-liveness evidence, direct class/file route, and first-draft C++ policy are documented. Confidence `88`: raw PE, Capstone, stored Ghidra function data, and existing IDA-backed docs agree on behavior and signatures, but no direct caller/pointer refs into the helper bodies are currently proven and the final action-row protocol names remain inferred.
```

## Recommended Support Doc Changes

Apply after supervisor acceptance; preserve Rule 26 detail.

`source-3/project-documentation/by-class/RightButtonMenuPane.md`:

- Replace the packet helper method-map/source-quality wording with:

```text
`0x00555780-0x005558c2` contains two private/file-local right-click menu packet helpers now considered first-draft C++ ready: `SendRightButtonTargetActionPacket(int targetId)` sends opcode `0x4a`, subcommand `0`, and a big-endian 32-bit target id; `SendRightButtonNameCommandPacket(const wchar_t *targetName)` sends a dot-prefixed, one-byte-length CP_ACP target-name packet. B015 found no direct rel32 or absolute refs into either helper body, so exact action-row names remain inferred, but the helper signatures and packet layouts are source-quality enough for draft emission under this class.
```

- Add a note:

```text
The target-name helper likely supports the right-click `Whisper`/name-command row, while the target-id helper supports a target-object action. Do not promote these to final row-specific names until the `OnEvent` caller or an equivalent protocol table is recovered.
```

`source-3/project-documentation/by-file/RightButtonMenuPane.md`:

- Update the proposed contents/assignment notes for [UID:00023Q]:

```text
B015 2026-06-19 resolves the packet helper island as two `static __stdcall` file-local helpers in `RightButtonMenuPane.cpp`, emitted through [UID:0000C0] `RightButtonMenuPane`: `SendRightButtonTargetActionPacket(int)` and `SendRightButtonNameCommandPacket(const wchar_t *)`. No direct caller refs are currently proven, but source placement stays in this file by right-click menu locality and target id/name semantics.
```

`source-3/project-documentation/by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md`:

- Update the final-C++ caveat so packet helper names are not passive blockers:

```text
The adjacent [UID:00023Q] packet island now has source-quality draft helper names/signatures and packet layouts. The core page still lacks final C++ because the five row action names, field names, and exact `OnEvent` dispatch calls remain to be source-shaped, not because [UID:00023Q] is unanalyzed.
```

- Update the separation wording:

```text
Keep [UID:00023Q] separate for exact range ownership and liveness evidence; source placement remains adjacent/file-local in `RightButtonMenuPane.cpp`.
```

`source-3/project-documentation/project-level/-resolved.md` / generated unresolved reports:

- No manual edit required, but target edits should remove unresolved raw mentions of `sub_516030`, `sub_516220`, `sub_574BB0`, `sub_575380`, and `sub_5753F0` by replacing them with resolved helper names. Regenerated unresolved reports should then stop flagging those target references.

`source-3/project-documentation/by-global/g_packetSender.md` and `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`:

- No required change. They already resolve the sender as `Socket *g_packetSender` with generated `CashShopRequest` aliases rejected.

`source-3/project-documentation/by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md`:

- No required change. The target should link/use the existing split/index names rather than updating the PacketBuffer index.

## Rejected Alternatives

- Exact no-code proof: rejected. The helpers are not compiler thunks, padding, runtime library fragments, or an overbroad aggregate. They are two complete source-authored packet builders with source-quality signatures and a valid emitter route.
- Merge into [UID:0001FX] `RightButtonMenuPaneCore`: rejected for coverage/range ownership. The current exact target should remain a separate by-memory page while source placement remains adjacent to the core class implementation.
- Socket/ProtocolSend owner: rejected. `g_packetSender` and `QueueAndSendPacket` are dependencies, not feature ownership evidence.
- Generated `CashShopRequest::meth_0x574bb0`: rejected as stale generated-name pollution for the shared sender path.
- First helper "caller byte argument": rejected. The helper writes a 32-bit big-endian argument.
- Second helper packet buffer as `0x130` bytes: rejected as a source array size. The buffer starts at `ebp-0x130`, but the usable guarded array is `0x12c` / 300 bytes.
- Final helper names `SendTradePacket`, `SendGroupInvitePacket`, or `SendWhisperPacket`: rejected for this pass because no direct caller/row mapping was recovered. `SendRightButtonNameCommandPacket` leaves room to rename the second helper later if the `Whisper` route is proven.

## Open Questions With Attempted Resolution

| Open question | Evidence checked | Best current answer | Remaining impact |
| --- | --- | --- | --- |
| Are the helpers live? | Existing IDA no-xref notes, stored Ghidra zero-callers, fresh rel32 scan into full body ranges, fresh absolute dword scan into full body ranges. | No static liveness is proven. Bodies may be orphaned/static helper copies or reached through evidence not recoverable in current static refs. | Caps confidence; does not block first-draft source because the bodies are exact and owner route is valid. |
| Which row calls `0x00555780`? | RightButtonMenuPane core docs, target id/name setter, MapPane opcode helper caller at `0x00554ee3`, command strings. | Best neutral answer: target-id right-click action helper using opcode `0x4a` subcommand `0`. | Do not use a row-specific formal helper name yet. |
| Is `0x005557e0` the Whisper helper? | Menu rows include `Whisper`; helper consumes target name and sends dot-prefixed name packet; no caller refs. | High-probability target-name/whisper command path, but not proven. Use neutral `NameCommand` name. | Later caller recovery can rename it. |
| Are `___report_rangecheckfailure` calls source-authored? | Raw comparisons guard direct stack-array writes after conversion/copy; no source helper state. | Treat as compiler/runtime range-check codegen from fixed local arrays, not handwritten source. | Formal C++ should use arrays and prose notes, not raw runtime calls. |
| Should helper calls keep raw names? | PacketBuffer, Socket, resolved alias docs, Ghidra helper names. | No. Use `PacketBufferWriteByte`, `PacketBufferWriteUInt32BE`, `QueueAndSendPacket`, `GetMemoryMan`, and `memmove`/`MemmoveWrapper`. | Target/support docs should clear raw-name pollution. |

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly during the B-agent report pass. If the supervisor accepts this report, replace the current [UID:00023Q] row with:

```text
    - [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md) 0x00555780-0x005558c2 | raw helper cluster | RightButtonMenuPacketHelpers : reconstructable : 87% : strong : B015 2026-06-19 source-quality pass keeps direct owner/emitter [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md), resolves two private/file-local packet helpers as first-draft C++ ready, and preserves no-static-liveness caveat after fresh raw PE scans found zero rel32 call/jump or absolute dword refs into either helper body range. Helper `0x00555780` sends `[0x4a,0x00,targetId32be]` length 6 through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md); helper `0x005557e0` sends a dot-prefixed one-byte-length CP_ACP target-name packet after empty-name and fixed-buffer range checks. Exact action-row names remain inferred.
```

The adjacent padding row for `0x005557da-0x005557e0` can remain unchanged. Optional supervisor-owned enhancement:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005557da-0x005557e0 | padding | RightButtonMenuPacketHelpers internal alignment : ignored : 100% : strong : B015 reconfirmed six `0xcc` alignment bytes between the two raw helper bodies; SHA1 `dd750025890f36a60bf67d4ad12665dbab2aaa24`.
```

## Validation Commands Needed After Implementation

Run from `source-3/project-documentation` after accepted doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [00023Q-RightButtonMenuPacketHelpers-source-quality-removed.md](00023Q-RightButtonMenuPacketHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the coverage row:

> Executable block R002 was removed from this report and preserved verbatim in [00023Q-RightButtonMenuPacketHelpers-source-quality-removed.md](00023Q-RightButtonMenuPacketHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename / Type / Comment Recommendations

Because current IDA does not model these as functions, create function starts only after supervisor/IDA owner approval:

| Address | Recommended IDA name | Prototype | Confidence | Comment |
| --- | --- | --- | --- | --- |
| `0x00555780` | `RightButtonMenuPane_SendTargetActionPacket` | `void __stdcall RightButtonMenuPane_SendTargetActionPacket(int targetId)` | High for signature, medium for semantic name | Writes opcode `0x4a`, subcommand `0`, and big-endian 32-bit `targetId`; sends 6 bytes via `g_packetSender`; no direct static refs found. |
| `0x005557e0` | `RightButtonMenuPane_SendTargetNameCommandPacket` | `void __stdcall RightButtonMenuPane_SendTargetNameCommandPacket(const wchar_t *targetName)` | High for signature, medium-high for semantic name | Sends `'.'`, one-byte CP_ACP converted target-name length, and converted name bytes; empty name returns; no direct static refs found. |

Stack variable recommendations:

- `0x00555780`: `unsigned char packet[7]`.
- `0x005557e0`: `char convertedName[0x100]`, `unsigned char packet[0x12c]`, `int convertedLength`, `short wideLength`, `int packetLength`.

Resolved callee names to use in comments/types:

- `0x00575380`: `PacketBufferWriteByte`
- `0x005753f0`: `PacketBufferWriteUInt32BE`
- `0x00574bb0`: `QueueAndSendPacket`
- `0x00516030`: `GetMemoryMan`
- `0x00516220`: `MemmoveWrapper` / source `memmove`
- `0x005c772f`: `__security_check_cookie`
- `0x005c7655`: `___report_rangecheckfailure` (compiler/runtime path, not source helper)

## Implementation Readiness

Ready for supervisor-reviewed implementation. The target can be raised to `87/88`, keep owner/emitter [UID:0000C0], carry first-draft C++ for the two static helpers, and update support docs to replace stale no-code and raw-name wording. The only material residual risk is absent static liveness/direct caller evidence and therefore unresolved final row-specific action names.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00023Q-RightButtonMenuPacketHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00023Q"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00023Q-RightButtonMenuPacketHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00023Q-RightButtonMenuPacketHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00023Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
