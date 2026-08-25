** TARGET-REPORT-UID:00021M **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00021M ClanWithdrawAndNoticePacketHelpers Source-Quality Report

Status: FINISHED_REPORT
Agent: Agent-B013
Target: [UID:00021M] `by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md`
Required report path: `tools/leaser/Agents/Agent-B013/research/00021M-ClanWithdrawAndNoticePacketHelpers-source-quality.md`
Mode: report-only research first

## Verdict

[UID:00021M] should remain a Clan-owned, retained raw helper strip under `NexusTK/social/Clan.cpp`. Current MCP evidence confirms that the strip is source-authored code, not padding or a compiler artifact, but also confirms no live call/pointer route to the raw helper starts. Keep `EMITTER_UIDS:0000I8`, but do not leave the formal C++ block blank. Use a nonblank documentation-only covered-by marker in the formal `RECONSTRUCTION_CPP CODE` block so the item is not a code-ready empty emitter.

Recommended target score movement after implementation: `COMPLETION:88`, `CONFIDENCE:91` from current `85/90`.

Recommended metadata after implementation:

- `CANONICAL_OWNER:0000I8`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000I8`
- `RECONSTRUCTION_CPP CODE`: nonblank documentation-only marker shown below; no callable helper bodies.

Reason for the cap: packet layouts, helper roles, owner/source placement, live reachability, and duplicate-helper semantics are now resolved with current MCP evidence. Subtype 13's original semantic name is still not independently proven by a live dispatcher, resource, callsite, or active submitter, so the implementation should document it conservatively as the opcode `0x4b` subtype `13` string-payload helper. If the page keeps the existing "Notice" title, state that "notice" is a project-facing descriptive/inferred label, not a recovered original function name.

## Formal Reconstruction C++ Disposition

Retain the emitter and insert this exact formal marker into the target's `RECONSTRUCTION_CPP CODE` block:

```cpp
// Retained no-route helper strip: subtype 11/12 live emissions are covered by [UID:00010H], [UID:0002NU], [UID:00010P], and [UID:00002N]; subtype 13 remains documentation-only packet evidence.
```

Do not emit callable helper functions for this range. The marker is intentionally nonblank because the target remains an emitting Clan-owned documentation item, but current MCP does not recover a live caller/vtable/pointer route for the raw starts. It also avoids claiming subtype 13 is covered by a live page; only the row-action subtype 11/12 request packets and active withdraw-money/item submitters are covered by live routed pages.

## Current MCP Session Evidence

MCP was available and IDB-backed for this pass.

- `idb_list`: active session `b010_0001DR_20260628`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active `true`, backend `worker`, worker PID `17656`.
- `server_health`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready `true`, Hex-Rays ready `true`, strings cache ready `true`, strings cache size `2067`.
- `tools/list`: 65 tools exposed. Tools used for this report: `lookup_funcs`, `entity_query`, `insn_query`, `xrefs_to`, `find_bytes`, `get_bytes`, `decompile`, `int_convert`, `server_health`, `idb_list`.
- Sanity check: `lookup_funcs` against `0x004810f0` returned an IDB-backed "Not a function" result, not a connection failure.

## Function Boundary And Raw-Strip Evidence

Current MCP `lookup_funcs` and `entity_query` show that the target range is not made of IDA function objects:

- `0x00486330`: `sub_486330`, size `0x1fe`.
- `0x00486530`, `0x00486599`, `0x004865a0`, `0x00486617`, `0x00486620`, `0x00486689`, `0x00486690`, `0x00486705`, `0x00486710`, `0x004867f2`: no function, "Not a function".
- `0x00486800`: `sub_486800`, size `0x4df`.
- Functions in `0x00486000-0x00487000`: only `sub_486330`, `sub_486800`, `sub_486D20`, and `sub_486F90`. No function starts inside `0x00486530-0x004867f2`.

Boundary disassembly confirms this is a strip between real functions, not fallthrough code:

- `sub_486330` returns at `0x00486526` with `retn 10h`.
- `0x00486529` calls `___report_rangecheckfailure`, followed by `align 10h` at `0x0048652e`.
- Raw helper code begins at `0x00486530`.
- `0x004867f2` is `align 10h`; the next function starts at `0x00486800`.

MCP `get_bytes` shows `0xCC` padding after each raw helper body:

- `0x00486599`: 7 bytes of `0xCC`.
- `0x00486617`: 9 bytes of `0xCC`.
- `0x00486689`: 7 bytes of `0xCC`.
- `0x00486705`: 11 bytes of `0xCC`.
- `0x004867f2`: 14 bytes of `0xCC`.

## Live Reachability

Current MCP xrefs are negative for all raw helper starts and the strip end:

- `xrefs_to 0x00486530`: 0.
- `xrefs_to 0x004865a0`: 0.
- `xrefs_to 0x00486620`: 0.
- `xrefs_to 0x00486690`: 0.
- `xrefs_to 0x00486710`: 0.
- `xrefs_to 0x004867f2`: 0.

Positive controls prove xref recovery is working:

- `xrefs_to 0x00486800`: 13 code xrefs from `sub_484A60`.
- `xrefs_to 0x004890b0`: data xref at `0x00615a94`.
- `xrefs_to 0x0048a810`: code xrefs at `0x004853fa` and `0x0048857b`.

Current MCP `find_bytes` found no absolute VA or RVA pointer patterns for raw helper starts/end/successor:

- No matches for `0x00486530`, `0x00086530`, `0x004865a0`, `0x000865a0`, `0x00486620`, `0x00086620`, `0x00486690`, `0x00086690`, `0x00486710`, `0x00086710`, `0x004867f2`, `0x000867f2`, `0x00486800`, or `0x00086800`.
- Positive controls: `b0 90 48 00` matched `0x00615a94` for the active withdraw-money vtable slot; `f0 ad 48 00` matched `0x00616178` for the active withdraw-item sender vtable slot.

Implementation disposition: the page can document these source-authored retained helpers, but it should not emit formal callable helper bodies unless a future pass recovers a real caller/vtable/pointer route. With `EMITTER_UIDS:0000I8` retained, the implementation must insert the nonblank formal covered-by marker above rather than leaving an empty C++ block.

## Packet Layouts

All five raw helper bodies use opcode decimal `75` / hex `0x4b`.

| Start | Suggested evidence label | Payload | Send length | Current interpretation |
|---|---|---|---:|---|
| `0x00486530` | `SendClanWithdrawMoneyOpenPacket` | `{ 0x4b, 0x0b, 0x00 }` | 3 | Withdraw-money request/open helper. |
| `0x004865a0` | `SendClanWithdrawMoneySubmitPacket` | `{ 0x4b, 0x0b, 0x01, UInt32BE(amount) }` | 7 | Withdraw-money submit helper, mirrors active `ClanWidMoneyInputDialog` submitter. |
| `0x00486620` | `SendClanWithdrawItemOpenPacket` | `{ 0x4b, 0x0c, 0x00 }` | 3 | Withdraw-item request/open helper. |
| `0x00486690` | `SendClanWithdrawItemSubmitPacket` | `{ 0x4b, 0x0c, 0x01, itemTypeByte, UInt16BE(quantity) }` | 6 | Withdraw-item submit helper, mirrors active `ClanWidItemDialog` sender. |
| `0x00486710` | `SendClanSubtype13StringPacket` | `{ 0x4b, 0x0d, byteLength, convertedBytes... }` | `convertedLen + 3` | String-payload subtype 13 helper; "notice" remains inferred/descriptive. |

Subtype 13 details from current MCP disassembly:

- Calls `WideCharToMultiByte`.
- Computes a wide-string character count from the `[ebp+8]` string argument.
- Converts into a local byte buffer with output cap `0x100`.
- Rejects converted lengths `>= 0x100` via range-check failure path.
- Writes the converted byte length at packet offset 2.
- Copies converted bytes to packet offset 3.
- Checks final packet length against `0x400`.
- Sends `convertedLen + 3`.
- It does not write an action byte.

## Packet Buffer And Send Roles

Current MCP decompilation confirms the dependency roles:

- `0x00575380 sub_575380(char value, _BYTE *dst)`: writes one byte and a local spare zero. Treat as `PacketBufferWriteUInt8` with raw ABI value-first.
- `0x005753a0 sub_5753A0(unsigned __int16 value, _BYTE *dst)`: writes high byte then low byte and a local spare zero. Treat as `PacketBufferWriteUInt16BE` with raw ABI value-first.
- `0x005753f0 sub_5753F0(int value, _BYTE *dst)`: writes four bytes high-to-low and a local spare zero. Treat as `PacketBufferWriteUInt32BE` with raw ABI value-first.
- `0x00574bb0 sub_574BB0(_BYTE *this, void *src, __int16 len)`: queues/sends caller-visible `len` bytes through the Socket packet path. The copied terminator is a local queue-buffer terminator, not an additional protocol byte.
- `dword_67A7EC` / `g_packetSender` is the Socket-owned packet sender global dependency, not a Clan ownership route.

## Mirrored Submitters And Duplicate Semantics

The raw helpers duplicate live packet emissions that already have active owner pages:

- Withdraw-money submit:
  - Raw helper `0x004865a0` writes `{ 0x4b, 0x0b, 0x01, UInt32BE(amount) }`, length 7.
  - Active method `0x004890b0` / [UID:0002NU] writes the same packet and has a live vtable data xref at `0x00615a94`.
  - The active page should remain the emitted C++ body; [UID:00021M] should only cross-reference it as a retained mirror.
- Withdraw-item submit:
  - Raw helper `0x00486690` writes `{ 0x4b, 0x0c, 0x01, itemTypeByte, UInt16BE(quantity) }`, length 6.
  - Active method `0x0048adf0` inside [UID:00010P]/[UID:00002N] writes the same packet and has a live vtable data xref at `0x00616178`.
  - The active `ClanWidItemDialog` page remains ClanBank-owned; [UID:00021M] remains Clan-owned as the raw mirror.
- Row-action request/open packets:
  - Active row-action dispatcher `0x00487600` sends subtype 11/action 0 for row 12 and subtype 12/action 0 for row 13, matching raw helpers `0x00486530` and `0x00486620`.
  - No active row-action path for subtype 13 was found in the current MCP pass.

This duplicate evidence strengthens the covered-by marker disposition: source-quality should document the raw bodies and their mirrors, but formal C++ should not create extra callable implementations for packets that are already represented by active routed methods. The formal block should contain only the documentation marker, with subtype 13 identified as retained no-route packet evidence.

## Subtype 13 Naming

Current MCP resolves the packet structure for subtype 13 but does not prove its original semantic name. The implementation should use one of these exact dispositions:

- Preferred source-quality wording: "opcode `0x4b` subtype `13` string-payload helper".
- Conservative helper evidence label: `SendClanSubtype13StringPacket`.
- If the existing title keeps "Notice", explicitly say "`Notice` is a project-facing descriptive label; current MCP confirms only subtype 13 string-payload behavior, not an original recovered name."

Do not claim that the executable independently names subtype 13 as notice unless a future pass finds a route, resource, or original string tying subtype 13 to that name.

## Source Placement And Ownership

Keep:

- `CANONICAL_OWNER:0000I8`.
- `EMITTER_UIDS:0000I8`.
- Source placement under `NexusTK/social/Clan.cpp`.
- `RECONSTRUCTABLE:TRUE`, because the raw bodies are fully understandable and source-authored.
- A nonblank formal `RECONSTRUCTION_CPP CODE` marker documenting covered-by status and subtype 13 no-route evidence.

Reject:

- ClanBank ownership: only the active withdraw-item dialog/sender belongs there. The raw subtype 12 helper is a Clan packet-helper mirror.
- ClanDialogs ownership: modal classes may be callees or UI split candidates, but this target is a packet helper strip with no live dialog method route.
- PacketBuffer/Socket/g_packetSender ownership: these are dependencies only.
- Active dialog submitter ownership: active routed methods already have their own pages and should not absorb the raw strip.
- Blank formal C++ while keeping `EMITTER_UIDS:0000I8`: that would preserve the empty-emitter defect returned by supervisor review.

## Support-Doc Recommendations

Required implementation changes:

- Update [UID:00021M] with this current MCP evidence, the packet layout table, the covered-by marker disposition, duplicate-helper semantics, and the conservative subtype 13 naming language.
- Update [UID:00021M] formal `RECONSTRUCTION_CPP CODE` to the exact nonblank marker in this report while keeping `EMITTER_UIDS:0000I8`.
- Update `by-file/Clan.md` to expand the [UID:00021M] row/change note from the current generic "opcode `0x4b`, subtype `11-13` helper strip" into the current resolved disposition: no live route, retained Clan.cpp helper strip, duplicate mirrors for withdraw-money/item, subtype 13 string-payload helper, formal C++ marker only.
- Update `by-file/ClanBank.md` with a cross-note analogous to the existing raw-helper notes: [UID:00021M] subtype 12 mirrors the active `ClanWidItemDialog` withdraw sender, but the raw helper strip remains Clan-owned while the active dialog remains ClanBank-owned.

Optional implementation changes:

- `by-file/ClanDialogs.md`: add a small negative-route note that [UID:00021M] is not a ClanDialogs migration target. Existing text already mostly covers this.
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`: add [UID:00021M] as another consumer of the byte/UInt16BE/UInt32BE packet writers only if the target update benefits from explicit support cross-linking.
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`: optional [UID:00021M] consumer note for send lengths 3, 6, 7, and `convertedLen + 3`.
- `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`: optional [UID:00021M] consumer note. Do not change ownership.

No generated, project-level, manual coverage, tool, lease, or IDA process files should be edited for this report.

## Implementation Checklist

- [x] Update target [UID:00021M] header scores to `88/91`.
  - Proof: [UID:00021M] header in `by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md` now has `COMPLETION:88` and `CONFIDENCE:91`; validator command `000000004982` recorded `completion_update` and `confidence_update`, and final UID-only validator `000000004986` returned `ok: 1`.
- [x] Keep target [UID:00021M] metadata as `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000I8`.
  - Proof: target header preserves those values; validator command `000000004982` recorded `canonical_owner_update 00021M ... 0000I8`.
- [x] Insert the exact nonblank formal `RECONSTRUCTION_CPP CODE` marker: `// Retained no-route helper strip: subtype 11/12 live emissions are covered by [UID:00010H], [UID:0002NU], [UID:00010P], and [UID:00002N]; subtype 13 remains documentation-only packet evidence.`
  - Proof: marker is present in the target formal block. The normal reference-phase validator auto-linked the UID refs inside the C++ comment, so the exact accepted marker was restored afterward and checked with target UID-only validator `000000004986` (`reference phase: False`, `ok: 1`, generated refresh skipped).
- [x] Add current MCP session/tool evidence to [UID:00021M].
  - Proof: target section `Current MCP Evidence` records session `b010_0001DR_20260628`, `server_health` OK, 65 tools, and the MCP tools used.
- [x] Add or refresh the five-row packet layout table in [UID:00021M].
  - Proof: target section `Packet Layouts` has five rows for `0x00486530`, `0x004865a0`, `0x00486620`, `0x00486690`, and `0x00486710`, including payload and send length.
- [x] Add exact live reachability proof: no function objects, no xrefs to raw helper starts, negative VA/RVA pointer pattern search, predecessor return and successor function boundary.
  - Proof: target `Current MCP Evidence` records `lookup_funcs`, `entity_query`, `insn_query`, `xrefs_to`, `find_bytes`, padding bytes, and positive controls.
- [x] Add duplicate-helper semantics tying raw withdraw-money submit to [UID:0002NU] and raw withdraw-item submit to [UID:00010P]/[UID:00002N].
  - Proof: target `Packet Layouts`, `Behavior`, and `Duplicate Semantics And Formal C++` sections document both active submitter mirrors.
- [x] Add row-action mirror note for subtype 11/action 0 and subtype 12/action 0 via `0x00487600`.
  - Proof: target `Packet Layouts` and `Behavior` sections tie subtype `11`/`12` action `0` to [UID:00010H] rows `12`/`13`.
- [x] Resolve subtype 13 naming as conservative string-payload evidence; mark "notice" as inferred/descriptive if retained.
  - Proof: target `Packet Layouts`, `Behavior`, and `Changes` sections state that `Notice` is descriptive/inferred and current evidence proves only subtype `13` string-payload behavior.
- [x] State that callable helper bodies are intentionally not emitted because the raw starts have no live route and the covered subtype 11/12 behavior is already represented by live pages.
  - Proof: target `Duplicate Semantics And Formal C++` section states marker-only formal C++ and rejects callable helper bodies.
- [x] Update `by-file/Clan.md` [UID:00021M] row/change note.
  - Proof: `by-file/Clan.md` contents row for [UID:00021M] now records retained/no-route marker disposition, current MCP evidence, duplicate mirrors, subtype `13` naming, and marker-only C++; `Changes` has a 2026-06-28 B013 entry.
- [x] Update `by-file/ClanBank.md` cross-note for the raw subtype 12 mirror.
  - Proof: `by-file/ClanBank.md` `Boundary And Data Notes` and `Changes` now record that [UID:00021M] subtype `12` mirrors active `ClanWidItemDialog` withdraw sender behavior while the raw strip stays Clan-owned.
- [x] Optionally add the `ClanDialogs.md` negative-route note.
  - Proof: intentionally not applied; the accepted callback made this optional, and required negative-route ownership is now present in the target page's owner/source section. No `ClanDialogs.md` edit was needed.
- [x] Optionally add consumer notes to PacketBuffer, QueueAndSendPacket, and g_packetSender support docs.
  - Proof: intentionally not applied; accepted callback made this optional, and the target page now preserves the dependency roles at sufficient detail without touching additional leased files.
- [x] After implementation, run scoped file validators for each edited by-* doc from `source-3/project-documentation`, for example `python .\tools\validator.py --mode file --file by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md --apply --queue-timeout 240`, and report `command_id`, `command_timestamp`, exit code, and `ok` count. Report execution/move is supervisor-owned after verification and is not a B-agent checklist item.
  - Proof: validators run from `source-3/project-documentation`: target normal validator `000000004982` at `2026-06-28T03:45:00-04:00`, exit `0`, `ok: 1`, generated refresh deferred; `Clan.md` validator `000000004983` at `2026-06-28T03:45:10-04:00`, exit `0`, `ok: 1`, generated refresh deferred, with pre-existing missing-ref diagnostics; `ClanBank.md` validator `000000004984` at `2026-06-28T03:45:17-04:00`, exit `0`, `ok: 1`, generated refresh deferred, with pre-existing missing-ref diagnostics; final target UID-only validator `000000004986` at `2026-06-28T03:46:08-04:00`, exit `0`, `ok: 1`, generated refresh skipped via `--no-generated-refresh`.

## Remaining Blockers

No blockers remain for implementation. The empty-emitter issue is resolved by retaining `EMITTER_UIDS:0000I8` with a nonblank formal covered-by marker. The only residual limitation is intentionally captured in the implementation plan: subtype 13's packet layout is proven, but its original semantic name is not. That should be handled by conservative wording and the documentation-only marker, not by delaying the target update.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00021M-ClanWithdrawAndNoticePacketHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/00021M-ClanWithdrawAndNoticePacketHelpers-source-quality.md","timestamp":"2026-06-28T03:50:23","uid":"00021M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
