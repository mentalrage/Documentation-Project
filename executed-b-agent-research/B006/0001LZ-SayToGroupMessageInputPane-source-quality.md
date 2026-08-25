** TARGET-REPORT-UID:0001LZ **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001LZ SayToGroupMessageInputPane Source-Quality Report

## Status

Implementation callback completed by B006 on 2026-06-26 after supervisor acceptance. The report-only phase created/updated only this report file; the accepted callback then edited the scoped by-* docs listed in the checklist below, ran scoped validators, and released all B006 leases. No generated files, project-level generated files, `by-memory/-coverage-report.md`, manual `-coverage-report.md` files, or IDA DB state were manually edited. Validator-owned side effects and generated-refresh state are recorded in the checklist proof.

## Target And Assignment

- Assignment id: `B006-report-0001LZ-say-to-group-message-input-pane-source-quality-20260626`.
- Target: [UID:0001LZ] `by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md`.
- Report path: `tools/leaser/Agents/Agent-B006/research/0001LZ-SayToGroupMessageInputPane-source-quality.md`.
- Queue source: `auto-generated/-ag-research-tracker.md` still listed this by-memory row as not-covered from older `78/84`-era state. That generated tracker is validator-owned and should refresh only after supervisor execution of this report.
- Current target metadata before implementation:
  - `COMPLETION:87`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000C4`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000C4`
  - blank `EMITTER_POSITION_OPTIONAL`
  - `Nested:0`
- Current formal C++ has a correct constructor outline but the submit body ends in `SendTargetMessagePacket(m_groupName, messageText);`. Current MCP evidence does not support that as a live call in this method.

## Executive Recommendation

Update the target to `COMPLETION:90`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:0000C4`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000C4`, keep `Nested:0`, and keep blank `EMITTER_POSITION_OPTIONAL`.

The main implementation blocker is resolved: `SayToGroupMessageInputPane::OnSubmitInput()` builds opcode `0x19` target-message bytes inline. It does not call either adjacent no-route helper clone at `0x005b1d50` or `0x005b2160`, and the current formal C++ should stop emitting a synthetic `SendTargetMessagePacket(...)` call. The constructor should also use the same first-draft base initializer style as accepted sibling target-message pages: `LineInputPane(0)`.

Required support updates:

- `by-class/SayToGroupMessageInputPane.md`: raise to `88/91`, keep owner/emitter `0000N9`, keep declaration C++, replace stale `AUTOGEN_PARENT_UID` prose with current `CANONICAL_OWNER`/emitter language, and record that the method body now emits inline packet serialization on the exact by-memory child.
- `by-file/SayInputPanes.md`: update the [UID:0001LZ] row with UID link, current C++ disposition, inline opcode `0x19` packet serialization, `m_groupName[128]`, vtable slot, and no-route helper exclusion. Remove or supersede the old migration note that says to consider attaching this class to `Group.cpp`.
- `by-file/Group.md`: make `SayToGroupMessageInputPane` explicitly a feature cross-reference only under current evidence, not a pending direct-owner candidate.
- `by-memory/0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB.md` and `by-memory/0x005b2160-0x005b22c3.SayTargetMessagePacketHelperNoRouteC.md`: add current B006 MCP no-function/no-xref confirmation and raise both to `86/90`; keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank formal C++.
- `by-global/g_packetSender.md`: add this group target-message submit path as another feature packet-builder consumer of `Socket *g_packetSender` / `QueueAndSendPacket`, with no score or owner change.

No edit is required for the aggregate [UID:0001LY] `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`: its B001 MCP-unavailable note is historical for that aggregate pass, while this target page should carry current B006 MCP evidence for [UID:0001LZ].

## Current Evidence Checked

### Local Documentation

Read and compared:

- target [UID:0001LZ] `by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md`;
- [UID:0000C4] `by-class/SayToGroupMessageInputPane.md`;
- [UID:0000N9] `by-file/SayInputPanes.md`;
- [UID:0000JS] `by-file/Group.md`;
- adjacent no-route helper pages [UID:000404] `0x005b1d50-0x005b1eb3` and [UID:000405] `0x005b2160-0x005b22c3`;
- sibling exact target-message pages [UID:000401] `SayToUserMessageInputPaneMethods`, [UID:000403] `NewSayToUserMessageInputPaneMethods`, and [UID:000406] `SayToClanMessageInputPaneMethods`;
- non-emitting aggregate [UID:0001LY] `SayTargetMessageInputPanes`;
- [UID:0001MJ]/[UID:00005W] `GroupInputPane` docs to preserve the command-input separation;
- support/dependency docs for `ValidateChatInputOrThrowPasswordError`, `SanitizeWideTextForChat`, `g_pTextFilter`, `PacketBufferWriteUInt8`, `MemmoveWrapper`, `QueueAndSendPacket`, and `g_packetSender`;
- executed reports `executed-b-agent-research/B001/0001LY-SayTargetMessageInputPanes-source-quality.md`, `executed-b-agent-research/B013/0000C6-SayToUserMessageInputPane-class-source-quality.md`, and `executed-b-agent-research/B014/000099-NewSayToUserMessageInputPane-source-quality.md`.

Key stale or superseded content found:

- Target formal C++ still calls inferred `SendTargetMessagePacket(...)`; current MCP proves the live method serializes inline.
- Target status still treats `SendTargetMessagePacket` as a method-C++ role name instead of only a no-route helper role for adjacent helper clones.
- `by-class/SayToGroupMessageInputPane.md` still says "Assignment decision: keep `AUTOGEN_PARENT_UID:0000N9`"; implementation should use current `CANONICAL_OWNER`/emitter terminology.
- `by-file/SayInputPanes.md` has an unlinked `SayToGroupMessageInputPane` row and a stale migration note saying to consider leaving the class attached to `Group`. Current evidence supports `SayInputPanes.cpp` as direct file owner and `Group.cpp` as a feature cross-reference only.
- `by-file/Group.md` still phrases the group message input as "may belong" with say/chat input. Current evidence supports making that decisive.
- Manual `by-memory/-coverage-report.md` still has a stale `78%` row for [UID:0001LZ]. B006 must not edit it; see supervisor-owned note below.

### IDA MCP Evidence

Current MCP endpoint `http://127.0.0.1:13337/mcp` responded. Active session:

- session id: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- module: `NexusTK.exe`
- imagebase: `0x400000`
- `auto_analysis_ready:true`
- `hexrays_ready:true`
- `strings_cache_ready:true`

Current schema note: the 2026-06-26 audit rechecked `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, and `xrefs_to`. The active `ida-pro-mcp` server reports protocol version `2025-06-18`; IDB-backed calls require `database:'80de0a67'` in `arguments`. A no-database `server_health`/`lookup_funcs` probe returned the expected `"database is required"` tool error, so implementation/supervisor rechecks should use the explicit database argument.

Current B006 JSON-RPC checks in this pass:

- `idb_list` confirmed the active session `80de0a67`.
- `server_health` returned `status:"ok"` for session `80de0a67`.
- `lookup_funcs`:
  - `0x005b1ec0` -> `sub_5B1EC0`, size `0xbe`.
  - `0x005b1f80` -> `sub_5B1F80`, size `0x1d2`.
  - `0x005b2152` -> not a function.
  - `0x005b1d50` -> not a function.
  - `0x005b2160` -> not a function.
  - dependency starts: `0x004f2310`, `0x004f2300`, `0x00465890`, `0x005957c0`, `0x00575380`, `0x00516220`, and `0x00574bb0` all resolve to the documented helper functions.
- `xrefs_to`:
  - `0x005b1ec0`: zero xrefs.
  - `0x005b1f80`: one data xref from `0x0062f85c`.
  - `0x005b1d50`: zero xrefs.
  - `0x005b2160`: zero xrefs.
  - `0x00630a44` (`Group => `): data refs at `0x005a525d`, `0x005a55f9`, and `0x005b1f38`.
  - `0x00630a58` (`Clan => `): data refs at `0x005a52ef`, `0x005a56c9`, and `0x005b2348`.
  - `0x00465890`: 13 code xrefs, including this target call at `0x005b1fc0`.
  - `0x005957c0`: 14 code xrefs, including this target call at `0x005b1fef`.
- `analyze_function 0x005b1ec0`:
  - prototype: `int __thiscall(int this, wchar_t *Source)`;
  - size: `190`;
  - no callers;
  - calls `sub_4F1C00(this, 0)`, stores `SayToGroupMessageInputPane` vtables at `this+0`, `this+160`, and `this+164`, copies `Source` into `this+264` with `_wcscpy_s(..., 0x80, Source)`, formats `L"Group => "`, calls prompt setter `sub_4F20A0`, and returns `this`.
- `analyze_function 0x005b1f80`:
  - prototype: `__int16 __thiscall(WCHAR *this)`;
  - size: `466`;
  - no direct callers; one data xref at `0x0062f85c`;
  - checks `sub_4F2310` result and returns on non-positive text length;
  - copies text through `sub_4F2300(..., WideCharStr, 255)`;
  - calls `sub_465890(WideCharStr)` at `0x005b1fc0`;
  - loads `g_pTextFilter`/`unk_67ADC8` then calls `sub_5957C0(WideCharStr, wcslen(WideCharStr))` at `0x005b1fef`;
  - uses `this+0x108` / `this + 132` wide chars as the stored group name;
  - calls `sub_575380(25, &Src)` to write opcode `0x19`;
  - converts group name and message via `WideCharToMultiByte(0, 0, ..., 256, ...)`;
  - rejects converted lengths `>= 0x100`;
  - writes one-byte group-name length, group-name bytes, one-byte message length, and message bytes;
  - rejects final payload length `>= 0x12c`;
  - writes a local-only trailing zero at `packet[payloadLength]`;
  - loads `dword_67A7EC` and calls `sub_574BB0(g_packetSender, &Src, payloadLength)`.
- `disasm 0x005b1f80` confirms the same packet sequence with key instructions:
  - `0x005b1fa6 push 0FFh`, `0x005b1fb4 call sub_4F2300`;
  - `0x005b1fc0 call sub_465890`;
  - `0x005b1fe8 mov ecx, dword ptr unk_67ADC8`, `0x005b1fef call sub_5957C0`;
  - `0x005b1ff4 lea edi, [esi+108h]`;
  - `0x005b204c call sub_575380` after pushing `0x19`;
  - `0x005b2075` group-name `WideCharToMultiByte`, `0x005b207d` cap check against `0x100`;
  - `0x005b2093 call sub_575380` group-name length, `0x005b20b0 call sub_516220` group-name bytes;
  - `0x005b20d4` message `WideCharToMultiByte`, `0x005b20d9` cap check against `0x100`;
  - `0x005b20f3 call sub_575380` message length, `0x005b2111 call sub_516220` message bytes;
  - `0x005b211c cmp eax, 12Ch`;
  - `0x005b2123 mov ecx, dword_67A7EC`, `0x005b212a` local terminator write, `0x005b2139 call sub_574BB0`.
- `make_signature_for_range 0x005b1ec0-0x005b2152` returned `unique:true` for the full target range. The report should not paste the long wildcarded signature into target docs; record uniqueness only if useful.

### int_convert.py Evidence

Numeric conversions used in this report were verified with:

> Executable block R001 was removed from this report and preserved verbatim in [0001LZ-SayToGroupMessageInputPane-source-quality-removed.md](0001LZ-SayToGroupMessageInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Successful converted values:

- `0xbe` = `190` (Verified with int_convert.py).
- `0x1d2` = `466` (Verified with int_convert.py).
- `0x292` = `658` for the full half-open target span length `0x005b2152 - 0x005b1ec0` (Verified with int_convert.py).
- `0x80` = `128` (Verified with int_convert.py).
- `0x108` = `264` (Verified with int_convert.py).
- `0xa0` = `160` and `0xa4` = `164` (Verified with int_convert.py).
- `0x19` = `25` (Verified with int_convert.py).
- `0x100` = `256` (Verified with int_convert.py).
- `0x12c` = `300` (Verified with int_convert.py).
- `0x230` = `560` (Verified with int_convert.py).

## Behavior And C++ Reanalysis

The constructor is source-ready as a first draft with one correction: use `LineInputPane(0)`, matching the actual `sub_4F1C00(this, 0)` call and the accepted direct-message sibling pages. `wcscpy_s(m_groupName, _countof(m_groupName), groupName)` matches the `0x80` / 128-wide-character bound, and `SetPromptText(L"Group => ")` is a source-level representation of the decompiled local prompt buffer path.

The submit method is source-ready as a first draft only if it inlines packet serialization. Current decompilation and disassembly contain no call edge to `0x005b1d50` or `0x005b2160`; the method performs its own `WideCharToMultiByte`, byte-length writes, payload copies, length guard, local terminator write, and `QueueAndSendPacket` call.

Use the same packet-source style already accepted for [UID:000401] `SayToUserMessageInputPaneMethods` and [UID:000403] `NewSayToUserMessageInputPaneMethods`: local `char` conversion buffers, a zero-initialized packet buffer, inline byte appends, `memcpy`, and `g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength))`. The docs should still preserve binary evidence that the compiler output calls `PacketBufferWriteUInt8` / `sub_575380`, `MemmoveWrapper` / `sub_516220`, and `QueueAndSendPacket` / `sub_574BB0`.

The binary's oversized-conversion/packet path branches to `___report_rangecheckfailure`; accepted sibling first-draft C++ currently models these guards as early returns. This report keeps that sibling style for consistency and caps confidence below near-final because final source-level range-failure policy and exact original helper spelling remain unproven.

## Exact Formal RECONSTRUCTION_CPP CODE For [UID:0001LZ]

The following is the exact formal reconstruction header/block content for [UID:0001LZ]. During implementation, replace the target's formal `RECONSTRUCTION_CPP CODE` marker/block with this exact marker/block content, preserving the surrounding non-C++ metadata lines. Do not treat this as an illustrative snippet, and do not include this report's Markdown fence in the target document.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SayToGroupMessageInputPane::SayToGroupMessageInputPane(const wchar_t *groupName)
    : LineInputPane(0)
{
    wcscpy_s(m_groupName, _countof(m_groupName), groupName);
    SetPromptText(L"Group => ");
}

void SayToGroupMessageInputPane::OnSubmitInput()
{
    if (TextLength() <= 0) {
        return;
    }

    wchar_t messageText[256] = {};
    CopyText(messageText, _countof(messageText) - 1);
    ValidateChatInputOrThrowPasswordError(messageText);
    SanitizeWideTextForChat(messageText, wcslen(messageText));

    char groupNameBytes[256] = {};
    const int groupNameLen = WideCharToMultiByte(
        CP_ACP, 0, m_groupName, static_cast<int>(wcslen(m_groupName)),
        groupNameBytes, sizeof(groupNameBytes), nullptr, nullptr);
    if (groupNameLen >= 0x100) {
        return;
    }

    char messageBytes[256] = {};
    const int messageLen = WideCharToMultiByte(
        CP_ACP, 0, messageText, static_cast<int>(wcslen(messageText)),
        messageBytes, sizeof(messageBytes), nullptr, nullptr);
    if (messageLen >= 0x100) {
        return;
    }

    unsigned char packet[0x230] = {};
    int packetLength = 0;

    packet[packetLength++] = 0x19;
    packet[packetLength++] = static_cast<unsigned char>(groupNameLen);
    memcpy(packet + packetLength, groupNameBytes, groupNameLen);
    packetLength += groupNameLen;
    packet[packetLength++] = static_cast<unsigned char>(messageLen);
    memcpy(packet + packetLength, messageBytes, messageLen);
    packetLength += messageLen;

    if (packetLength >= 0x12c) {
        return;
    }

    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Packet Layout And State Names

Target docs should preserve these facts at report-level detail:

| Fact | Decision |
| --- | --- |
| callback role | Keep `OnSubmitInput()` as the vtable/source callback role. `SendGroupMessage` may remain a behavioral role alias only. |
| destination field | `m_groupName[128]` at `this+0x108` / 264 (Verified with int_convert.py), copied with `0x80` / 128-wide-character bound (Verified with int_convert.py). |
| line text read | `TextLength()` via `0x004f2310`; `CopyText(..., 0xff)` via `0x004f2300`. |
| password guard | `ValidateChatInputOrThrowPasswordError(messageText)` at `0x005b1fc0`; shared [UID:0002VH] guard already documents this xref. |
| sanitizer | `SanitizeWideTextForChat(messageText, wcslen(messageText))` at `0x005b1fef`; `g_pTextFilter` is loaded before the call, but accepted sanitizer docs prove the helper itself is a two-stack-argument free helper with no `ecx` use. |
| opcode | `0x19` / 25 (Verified with int_convert.py), written at packet offset `0`. |
| group payload | group-name byte length, then group-name bytes after `WideCharToMultiByte`. |
| message payload | message byte length, then sanitized message bytes after `WideCharToMultiByte`. |
| conversion cap | each converted field rejected on `>= 0x100` / 256 bytes (Verified with int_convert.py). |
| packet cap | final payload length `groupNameLen + messageLen + 3`, rejected on `>= 0x12c` / 300 bytes (Verified with int_convert.py). |
| local terminator | binary writes `packet[packetLength] = 0` before sending; the zero is local scratch/convenience terminator and not part of the explicit send length. |
| sender | `g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength))`; `g_packetSender` remains Socket-owned infrastructure, not `SayInputPanes` ownership evidence. |

## Ownership, Split, And Source Placement

### Accepted Direct Owner

Keep [UID:0000C4] `SayToGroupMessageInputPane` as the direct class owner and emitter for [UID:0001LZ]. The child and class both clear the strict gate after this pass. The exact method bodies belong on the by-memory child; the class page should keep a declaration-only shell.

### Accepted File Route

Keep [UID:0000N9] `SayInputPanes` as direct file/source route. Current evidence supporting this:

- physical and behavioral membership in the target-message input family;
- shared opcode `0x19` target/message packet shape with legacy and modern direct-message siblings;
- `Group => ` prompt refs in `OpenInputPaneForCurrentSayMode`, standalone group open helper, and this constructor;
- sibling direct-message pages [UID:000401] and [UID:000403] already route through `SayInputPanes.cpp` and now use the inline packet style;
- `GroupInputPane` is separate command input with opcode `0x2e`, not this target.

### Rejected Direct Owners

| Candidate | Decision |
| --- | --- |
| [UID:0000JS] `Group.cpp` | Feature cross-reference only. It owns group panes/list/markers; current target is a social say-mode input class under `SayInputPanes.cpp`. |
| [UID:00005W] `GroupInputPane` / [UID:0000ID] `CommandInputPanes` | Rejected. That class sends generic group-command opcode `0x2e` and has separate vtables/prompt-id construction. |
| [UID:000404] / [UID:000405] no-route helpers | Rejected as class members or callees. Current MCP reports no function object and zero xrefs to both raw starts, and `OnSubmitInput()` serializes inline. |
| `Socket`, `PacketBuffer`, `PasswordGuard`, `TextFilter`, `MemoryMan` | Dependencies only. They own shared helper/global behavior, not the feature class. |
| central `ProtocolSend` | Not supported. The target-message packet builder is feature-local inline code feeding the generic Socket send funnel. |

### Adjacent No-Route Helper Policy

[UID:000404] and [UID:000405] remain ownerless, non-reconstructable, non-emitting retained helper clones. Current B006 MCP adds fresh no-function/no-xref confirmation but does not change the B001 no-route policy:

- no IDA function object at `0x005b1d50` or `0x005b2160`;
- zero xrefs to each raw start in current MCP `xrefs_to`;
- no `this` receiver or vtable route documented by B001;
- no call edge from [UID:0001LZ] submit; the live method builds the same packet inline;
- the inferred helper name `SendTargetMessagePacket(const wchar_t *, const wchar_t *)` remains a role description for dead/unreferenced helper-shaped bytes, not a source call to emit from this target.

## Score And Metadata Rationale

### Target [UID:0001LZ]

Recommended:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000C4`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000C4`
- blank `EMITTER_POSITION_OPTIONAL`
- `Nested:0`

Completion improves from `87` to `90` because current MCP directly confirms function boundaries, vtable slot, prompt refs, exact field offset/bound, input guard/sanitizer route, inline packet serialization, sender path, unique signature, and no-route helper exclusions, and because the formal C++ can now be repaired rather than left as a helper-call approximation.

Confidence improves from `90` to `92` because live MCP, sibling accepted pages, and support docs align. It remains below near-final because exact original callback spelling, original helper/constant names, and the source-level oversized-buffer failure style are inferred rather than source-proven.

### Class [UID:0000C4]

Recommended:

- `COMPLETION:88`
- `CONFIDENCE:91`
- keep `CANONICAL_OWNER:0000N9`
- keep `RECONSTRUCTABLE:TRUE`
- keep `EMITTER_UIDS:0000N9`

The class page should not gain method-body C++; the exact child emits. The score bump is justified by replacing stale ownership wording, adding current B006 MCP evidence, and recording that the child C++ now models inline packet serialization.

### Helper Pages [UID:000404] And [UID:000405]

Recommended for both:

- `COMPLETION:86`
- `CONFIDENCE:90`
- keep `CANONICAL_OWNER:NONE`
- keep `RECONSTRUCTABLE:FALSE`
- keep blank `EMITTER_UIDS`
- keep formal C++ blank

The score bump is modest and comes only from current MCP corroboration of the previously documented no-route state. It should not be treated as source-emission readiness.

### Support Docs Without Score Change

- [UID:0000N9] `SayInputPanes`: update row/evidence/migration note; keep `88/87` because broader file split and plan/clan naming caveats remain.
- [UID:0000JS] `Group`: update cross-reference wording; keep `89/85` because this does not change core Group.cpp completeness.
- [UID:0000Q5] `g_packetSender`: add consumer note; keep `86/88` and Socket ownership.

## Support Doc Decisions And No-Edit Proofs

Required support edits:

- `by-class/SayToGroupMessageInputPane.md`: add current B006 evidence and C++ disposition; replace stale `AUTOGEN_PARENT_UID` wording.
- `by-file/SayInputPanes.md`: update [UID:0001LZ] row and migration note.
- `by-file/Group.md`: make Group feature-reference status decisive.
- `by-memory/0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB.md`: add current MCP no-function/no-xref proof.
- `by-memory/0x005b2160-0x005b22c3.SayTargetMessagePacketHelperNoRouteC.md`: add current MCP no-function/no-xref proof.
- `by-global/g_packetSender.md`: add group target-message consumer note.

Explicit no-edit decisions:

- `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`: no edit required. The current B001 MCP-unavailable caveat is historical for that aggregate report; this target-specific page should carry B006 current MCP proof.
- `by-memory/0x005b5440-0x005b5547.GroupInputPane.md` and `by-class/GroupInputPane.md`: no edit required. They already document the separate command-input class/opcode `0x2e` route, and current target docs can cite them as rejected owner evidence.
- `by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md`: no edit under this target callback. Its formal C++ still uses `SendTargetMessagePacket`, which is analogous stale evidence, but it is a separate source-bearing child and should receive its own UID-specific callback before changing its code.
- `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md`, `by-global/SanitizeWideTextForChat.md`, `by-global/g_pTextFilter.md`, and `by-file/TextFilter.md`: no edit required. They already document this target's guard/sanitizer xrefs and accepted free-helper/global signatures.
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`: no edit required. It already documents `PacketBufferWriteUInt8`, value-first raw ABI, and local trailing zero semantics; target-specific consumer note is not needed because the formal C++ follows accepted sibling inline assignment style.
- `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`: no edit required. It already documents the `memmove` wrapper; source C++ should use `memcpy`/inline copy style as accepted siblings do.
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`: no edit required. The `g_packetSender` page is the better focused global support location for this new consumer note.
- prompt/prefix pages `by-memory/0x006309d0-0x006309dc.SayModeGroupClanPrefixFragments.md` and `by-memory/0x00630a44-0x00630a6c.GroupClanPromptFragments.md`: no edit required. They already record the `Group => ` refs and group/clan split.

## Generated And Coverage State

- Do not edit `auto-generated/-ag-research-tracker.md`. It should refresh after the supervisor executes this report through validator `execute_report`.
- Do not edit `auto-generated/-ag-coverage-report-by-memory.md`. Target metadata and `Item Summary` should drive any validator refresh.
- Do not edit `by-memory/-coverage-report.md` or any manual `-coverage-report.md`.
- Read-only generated-output audit: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/social/SayInputPanes.cpp` still show stale pre-implementation `78/84`-era target data and the old helper-call C++. These are validator-owned outputs; implementation should refresh them only through scoped validators and later supervisor `execute_report`, not by manual edits.
- Supervisor-owned manual coverage note, only if the supervisor still maintains `by-memory/-coverage-report.md` manually after implementation:

```text
- [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md) 0x005b1ec0-0x005b2152 | class-method-cluster | SayToGroupMessageInputPane : reconstructable : 90% : very-strong : Group-message line input constructor/submit under `SayInputPanes.cpp`; B006 current IDA MCP confirms constructor `0x005b1ec0-0x005b1f7e`, submit `0x005b1f80-0x005b2152`, vtable slot `0x0062f85c`, `m_groupName[128]` at `+0x108`, `Group => ` prompt refs, inline opcode `0x19` group/message packet serialization, `0x100` conversion caps, `0x12c` packet cap, local-only trailing zero, `g_packetSender->QueueAndSendPacket(packet, groupNameLen + messageLen + 3)`, and adjacent no-route helper clones [UID:000404]/[UID:000405] excluded from class ownership and formal C++.
```

## Implementation Tracking Checklist

Implementation callback completed by B006 on 2026-06-26. Working directory for all validators was `E:\NTK\GhidraBridge\source-3\project-documentation`. All scoped validator commands below exited `0`; each returned `ok:1`. Generated refresh was `deferred` for every scoped validator, and validator-owned `projected_stats_update`/registry updates were reported by the validator. B006 did not manually edit generated files, project-level generated files, validator/tool state, `by-memory/-coverage-report.md`, or any manual `-coverage-report.md`.

- [x] Edit `by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md`.
  - Proof: set `COMPLETION:90`, `CONFIDENCE:92`; preserved `CANONICAL_OWNER:0000C4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000C4`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
  - Proof: replaced the formal `RECONSTRUCTION_CPP CODE` marker/block with the exact accepted block from this report, including `RECONSTRUCTION_CPP CODE:[[[]]]`, `BEGIN`, the first-draft constructor plus `OnSubmitInput()` body, and `END`. No Markdown fence was inserted.
  - Proof: updated status/range/packet/ownership/change sections so `OnSubmitInput()` emits inline opcode `0x19` group/message packet serialization and `SendTargetMessagePacket` is only an adjacent no-route helper role.
  - Proof: preserved MCP session `80de0a67`, constructor/submit sizes `0xbe`/`0x1d2`, vtable data xref `0x0062f85c`, no constructor xrefs, prompt refs, password/sanitizer calls, `g_pTextFilter` load/free-helper caveat, `m_groupName[128]`, packet fields/caps/local terminator/sender call, unique signature, no helper route, and rejected owners.
  - Validator: `python .\tools\validator.py --mode file --file by-memory\0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md --apply --queue-timeout 240`; final result `command_id:000000002427`, `command_timestamp:2026-06-26T05:15:19-04:00`, exit `0`, `ok:1`, warnings none, `generated_refresh:deferred`.

- [x] Edit `by-class/SayToGroupMessageInputPane.md`.
  - Proof: set `COMPLETION:88`, `CONFIDENCE:91`; preserved `CANONICAL_OWNER:0000N9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N9`.
  - Proof: kept declaration-only formal C++ with `[[CHILDREN]]` and no method bodies; added current B006 evidence and method-body C++ placement pointing to [UID:0001LZ] with inline packet serialization.
  - Proof: replaced stale `AUTOGEN_PARENT_UID` wording with current `CANONICAL_OWNER`/emitter/source-route wording.
  - Validator: `python .\tools\validator.py --mode file --file by-class\SayToGroupMessageInputPane.md --apply --queue-timeout 240`; final result `command_id:000000002428`, `command_timestamp:2026-06-26T05:15:28-04:00`, exit `0`, `ok:1`, warnings none, `generated_refresh:deferred`.

- [x] Edit `by-file/SayInputPanes.md`.
  - Proof: kept score `88/87`.
  - Proof: updated the [UID:0001LZ] row and boundary/change notes with UID link, `m_groupName[128]`, `Group => ` prompt, submit vtable slot `0x0062f85c`, inline opcode `0x19` group/message packet serialization, local-only terminator, first-draft C++ readiness, and adjacent [UID:000404]/[UID:000405] no-route exclusion.
  - Proof: replaced the old migration note about possibly attaching the class to `Group` with the decisive current-state note: direct route stays under `SayInputPanes.cpp`; `Group.cpp` is a feature cross-reference only unless future original source metadata proves otherwise.
  - Validator: `python .\tools\validator.py --mode file --file by-file\SayInputPanes.md --apply --queue-timeout 240`; final result `command_id:000000002429`, `command_timestamp:2026-06-26T05:15:35-04:00`, exit `0`, `ok:1`, warnings `missing_ref_uid:18` and `missing_ref_target:11` for pre-existing stale sibling/prompt/old-path references including `0003JM`, `000401`, `000402`, `000403`, `000406`, `0003JQ`, `0003JR`, old [UID:0001ME] path, and old [UID:0002S8] path; accepted [UID:000404]/[UID:000405] links were inserted/normalized; `generated_refresh:deferred`.

- [x] Edit `by-file/Group.md`.
  - Proof: kept score `89/85`.
  - Proof: updated hypothesis/proposed-content/migration/change wording so `SayToGroupMessageInputPane` is feature-related but routed to `SayInputPanes.cpp`, not a pending `Group.cpp` ownership candidate.
  - Proof: preserved `GroupInputPane` as command-input/CommandInputPanes-owned and separate from the target-message class.
  - Validator: `python .\tools\validator.py --mode file --file by-file\Group.md --apply --queue-timeout 240`; result `command_id:000000002423`, `command_timestamp:2026-06-26T05:14:25-04:00`, exit `0`, `ok:1`, warnings `missing_ref_target:2` for the pre-existing old [UID:00023W] path and `missing_ref_uid:1` for pre-existing `0003XA`; [UID:0001LZ] link inserted; `generated_refresh:deferred`.

- [x] Edit `by-memory/0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB.md`.
  - Proof: set `COMPLETION:86`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
  - Proof: added current B006 MCP proof that `lookup_funcs 0x005b1d50` is not a function, `xrefs_to 0x005b1d50` returns zero, and target submit `0x005b1f80` does not call this helper because it serializes inline.
  - Validator: `python .\tools\validator.py --mode file --file by-memory\0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB.md --apply --queue-timeout 240`; result `command_id:000000002424`, `command_timestamp:2026-06-26T05:14:33-04:00`, exit `0`, `ok:1`, warnings `missing_ref_uid:2` for pre-existing neighbor UID `000403`; path/registry mapping for `000404` created; `generated_refresh:deferred`.

- [x] Edit `by-memory/0x005b2160-0x005b22c3.SayTargetMessagePacketHelperNoRouteC.md`.
  - Proof: set `COMPLETION:86`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
  - Proof: added current B006 MCP proof that `lookup_funcs 0x005b2160` is not a function, `xrefs_to 0x005b2160` returns zero, and target submit `0x005b1f80` does not call this helper because it serializes inline.
  - Validator: `python .\tools\validator.py --mode file --file by-memory\0x005b2160-0x005b22c3.SayTargetMessagePacketHelperNoRouteC.md --apply --queue-timeout 240`; result `command_id:000000002425`, `command_timestamp:2026-06-26T05:14:40-04:00`, exit `0`, `ok:1`, warnings `missing_ref_uid:2` for pre-existing neighbor UID `000406`; path/registry mapping for `000405` created; `generated_refresh:deferred`.

- [x] Edit `by-global/g_packetSender.md`.
  - Proof: kept score `86/88`, owner/emitter `0000NS`, and blank formal C++.
  - Proof: added [UID:0001LZ] as a feature packet-builder consumer with opcode `0x19`, group-name length/bytes, message length/bytes, `packetLength = groupNameLen + messageLen + 3`, local-only terminator, and `g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength))`.
  - Proof: stated this is consumer/type evidence only and does not change Socket ownership of `g_packetSender`.
  - Validator: `python .\tools\validator.py --mode file --file by-global\g_packetSender.md --apply --queue-timeout 240`; result `command_id:000000002426`, `command_timestamp:2026-06-26T05:14:54-04:00`, exit `0`, `ok:1`, warnings `missing_ref_uid:2` for pre-existing `0003UT`; `generated_refresh:deferred`.

- [x] Record no-edit proof in the implementation checklist for read-only/excluded support docs.
  - No edit to [UID:0001LY] aggregate: its MCP-unavailable caveat is historical aggregate evidence, not a contradiction after target-specific B006 MCP proof on [UID:0001LZ].
  - No edit to `GroupInputPane` docs: existing docs already separate opcode `0x2e` command input from this opcode `0x19` target-message class.
  - No edit to clan/plan sibling [UID:000406]: analogous stale helper-call C++ may need a future UID-specific pass, but changing it was outside this accepted target callback.
  - No edit to PasswordGuard/TextFilter/PacketBuffer/Memmove/QueueAndSendPacket/prompt pages: current accepted docs already carry the dependency/helper facts, and target-specific consumer details were added to the target plus `g_packetSender`.

- [x] Run and record every scoped validator listed above for files actually edited.
  - Validators run and recorded above for all seven edited by-* files. Final command IDs used for proof: `000000002427`, `000000002428`, `000000002429`, `000000002423`, `000000002424`, `000000002425`, and `000000002426`.
  - Earlier validator passes `000000002420`, `000000002421`, and `000000002422` were superseded by final reruns after helper UID registration; they also exited `0` with `ok:1`.

- [x] Release leases immediately after the edit/validator batch and record lease proof.
  - Initial lease check found an Agent-B014 lease on `by-file/SayInputPanes.md` expiring `2026-06-26T09:08:12Z`; B006 waited and rechecked at `2026-06-26T09:09:18Z`, when `lease.json` was empty.
  - B006 leased the seven edited by-* files at approximately `2026-06-26T09:09:26Z`. Because the tool would not extend self-held leases (`Rejected[Already has lease]`), B006 released/reacquired the same seven-file lease set at approximately `2026-06-26T09:13:49Z` for the validator batch.
  - B006 released all seven leases at `2026-06-26T09:16:03Z`. Lease proof after release: `lease.json` contained no active `Agent-B006` entries; only unrelated active leases by Agent-B002/B007 remained.

- [x] Generated/coverage handling.
  - No manual edits were made to `auto-generated/*`, project-level generated files, `by-memory/-coverage-report.md`, or any manual `-coverage-report.md`.
  - Scoped validators reported `generated_refresh:deferred` and `projected_stats_update` where applicable; generated tracker/coverage refresh is expected through validator/supervisor execution, not B006 manual edits.
  - The supervisor-owned manual `by-memory/-coverage-report.md` row text remains in this report for supervisor use only; B006 did not edit that coverage report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001LZ-SayToGroupMessageInputPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001LZ-SayToGroupMessageInputPane-source-quality.md","timestamp":"2026-06-26T05:19:53","uid":"0001LZ"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001LZ-SayToGroupMessageInputPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0001LZ-SayToGroupMessageInputPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001LZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
