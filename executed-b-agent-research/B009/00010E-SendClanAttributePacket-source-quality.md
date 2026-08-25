** TARGET-REPORT-UID:00010E **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B009 Source-Quality Report: [UID:00010E] SendClanAttributePacket

## Finalized Report / Current Recommendation

Implementation callback is applied for [UID:00010E] `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md`.

Applied disposition: the durable helper/page name `SendClanAttributePacket` is preserved, direct source owner/emitter is changed from pre-callback [UID:0000I8] `Clan` to current [UID:00002K] `ClanStatusPane`, the generated source route remains [UID:0000I8] `NexusTK/social/Clan.cpp`, and the explicit-context static helper formal C++ is replaced with a `ClanStatusPane::SendClanAttributePacket(...)` member draft.

The reason is now direct and target-specific: live IDA MCP disassembly of the sole caller [UID:0002O3] at `0x00489fc0` shows it loads `unk_67ADE4` / `g_pClanStatusPane` into `ECX` at `0x00489fdc`, pushes exactly four stack arguments, and calls [UID:00010E] at `0x00489fe3`. Live IDA MCP disassembly of [UID:00010E] shows `retn 10h` (`0x10` / 16), so the callee pops four stack arguments, not five. The previous formal header `static int SendClanAttributePacket(ClanStatusPane *statusPane, ...)` treated the status-pane context as a stack argument and was therefore not the best source-facing signature.

Applied score/metadata callback:

| Field | Previous | Applied |
|---|---:|---:|
| `COMPLETION` | `85` | `88` |
| `CONFIDENCE` | `90` | `92` |
| `CANONICAL_OWNER` | `0000I8` | `00002K` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000I8` | `00002K` |
| `EMITTER_POSITION_OPTIONAL` | blank | blank |
| Formal C++ | nonblank static helper with explicit unused `ClanStatusPane *` | nonblank `ClanStatusPane` member helper with four explicit payload arguments |

## Supporting Research

Supporting research for [UID:00010E] focused on the target by-memory page, the sole caller [UID:0002O3], current direct owner [UID:00002K], pre-callback historical owner/source-route support [UID:0000I8], sibling Clan packet helpers, packet-buffer/global send dependencies, active IDA MCP evidence, and matching executed B-agent reports.

## Target

- Target UID: `00010E`
- Target path: `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md`
- Required report path: `tools/leaser/Agents/Agent-B009/research/00010E-SendClanAttributePacket-source-quality.md`
- Queue source: `auto-generated/-ag-research-tracker.md`, `## by-memory`, `### Not-Covered Files - Reconstructable`; assignment goal recorded tracker command `000000006777`, refreshed `2026-07-05T04:47:20-04:00`, queue drained by command `000000006779`.

## Current Target State

The target is reconstructable and now emits the accepted first-draft `ClanStatusPane::SendClanAttributePacket(...)` member helper.

- Current metadata is `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`, blank optional emitter position.
- Current target C++ is `int ClanStatusPane::SendClanAttributePacket(const wchar_t *clanName, const wchar_t *descriptionText, const wchar_t *attributeText, unsigned short attributeType)`.
- The stale no-code/status wording is superseded in current prose and preserved only as historical context where explicitly marked superseded.
- Current behavior prose records opcode `0x4b` / 75, subtype `6`, action `2`, three length-prefixed converted strings, the final 16-bit type/value, the sole caller [UID:0002O3] at `0x00489fe3`, `g_pClanStatusPane` receiver load at `0x00489fdc`, and `retn 10h`.

### Applied State

Current applied state uses [UID:00002K] `ClanStatusPane` as the narrow direct owner/emitter and keeps [UID:0000I8] `Clan` as the source-file route. The source-level call is represented as:

```cpp
int ClanStatusPane::SendClanAttributePacket(
    const wchar_t *clanName,
    const wchar_t *descriptionText,
    const wchar_t *attributeText,
    unsigned short attributeType)
```

The member body may continue not to dereference `this`; that is already accepted in this Clan packet family when callers explicitly provide a `ClanStatusPane` receiver. This matches the accepted treatment of [UID:00021K] `ClanStatusPane::SendClanEnlistListRefreshPacket` and `ClanStatusPane::SendClanEnlistListSelectionPacket`, and the accepted [UID:00010D] `ClanStatusPane::SendClanLeaveResponse` explicit-context rejection.

### Supervisor Active Recheck

Implementation callback scope was limited to the target, authorized support docs, and this report. B009 leased the target, UID0002O3 support, `ClanStatusPane`, `Clan`, and this report before editing after an initial conflict/retry cycle. After edits/validators, an explicit `unlease` attempt reported `Rejected[No active lease]` for all five paths, so no active B009 leases remained. No UID00010F, UID00021L, packet-buffer/global helper docs, manual coverage files, lifecycle/archive files, executed-report records, or supervisor ledgers were manually edited. No `execute_report`, dry-run/probing variants, registry lifecycle commands, or archive/move commands were run. Scoped validators were run only for the four changed by-* docs and their validator-reported generated/index refresh side effects are recorded below.

### Inference Research Guidance Check

Direct byte/MCP facts are separated from source-shape inference:

- Direct facts: function bounds, callee/caller/xref sets, four stack arguments, `ECX` receiver setup, packet constants, conversion calls, packet writer calls, send funnel, padding bytes, and decimal conversions.
- Source-shape inference: `ClanStatusPane::SendClanAttributePacket` is inferred from the caller receiver setup and sibling accepted pattern, not from debug symbols.
- Name inference: `clanName`, `descriptionText`, `attributeText`, and `attributeType` remain descriptive field-role names from [UID:0002O3] and [UID:000024] support pages. Exact original UI/source labels for the three submitted strings remain unproven, so `88/92` is appropriate rather than a higher final-source score.

## Heuristic / Inference Reanalysis And Validation

The prior project compromise kept [UID:00010E] under [UID:0000I8] as a file-level Clan helper and modeled the receiver as an explicit unused parameter. That compromise was reasonable before the target-specific signature was audited. Current evidence makes the member form stronger:

- `0x00489fc0` is a `__thiscall` submitter on [UID:0002O3] `ClanEnlistInputDialog::OnSubmitEnlistment`.
- The submitter reads inherited [UID:000024] fields at `+0x26c` / 620, `+0x46c` / 1132, `+0x66c` / 1644, and `+0x86c` / 2156.
- Immediately before calling `sub_485AC0`, the submitter overwrites `ECX` with `unk_67ADE4`, documented as `g_pClanStatusPane`.
- The target callee returns with `retn 10h`, matching four stack arguments and an implicit receiver context. A formal source signature with `ClanStatusPane *statusPane` plus four payload arguments would imply five explicit arguments and does not fit the callee cleanup.

This is not a name-only polish issue: it affects the formal C++ declaration and the support caller expression.

## Evidence Standards Used

- Live IDA MCP evidence was mandatory and was collected from active session `supervisor_recovery_20260705`.
- MCP calls were narrow, paged, and schema-current: `idb_list`, `server_health`, `lookup_funcs` using `queries`, `callees` using `addrs`, `xrefs_to` using `addrs`, `analyze_function`, `decompile`, `disasm` with bounded instruction counts, `get_bytes` using `regions`, and `int_convert` using `inputs`.
- A schema retry was required because this MCP listener now requires `database=supervisor_recovery_20260705` on tool calls and uses `queries`/`regions`/`inputs` for several tools. Those were not MCP availability failures.
- Existing executed reports were searched with terms including `00010E`, `0x00485ac0`, `0x485ac0`, `sub_485AC0`, `SendClanAttributePacket`, `Clan`, `clan attribute`, `ClanEnlistInputDialogSubmitEnlistment`, `0002O3`, `packet helper`, `subtype 6`, `action 2`, `g_pClanStatusPane`, `00002K`, `ClanStatusPane`, `00010F`, `SubmitClanChangeHelper`, and `00021L`.

## Evidence Checked

Target/support docs checked:

- [UID:00010E] `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md`
- [UID:0002O3] `by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md`
- [UID:00002K] `by-class/ClanStatusPane.md`
- [UID:0000I8] `by-file/Clan.md`
- [UID:00010F] `by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md`
- [UID:00021L] `by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md`
- [UID:00021K] `by-memory/0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers.md`
- [UID:00021G] `by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md`
- [UID:00010D] `by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md`
- [UID:000024] `by-class/ClanAttrInputDialog.md`
- [UID:00002B] `by-class/ClanEnlistInputDialog.md`
- [UID:0001HZ] `by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md`
- [UID:0001HU] `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`

Matching executed reports opened/searched:

- `executed-b-agent-research/B004/0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality.md`
- `executed-b-agent-research/B003/0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality.md`
- `executed-b-agent-research/B015/00021K-ClanSubtype6PacketHelpers-source-quality.md`
- `executed-b-agent-research/B015/00002K-ClanStatusPane-class-source-quality.md`
- `executed-b-agent-research/B006/00021L-ClanNameActionPacketHelpers-source-quality.md`
- `executed-b-agent-research/B007/0000I8-Clan-empty-emitter-family-source-quality.md`
- `executed-b-agent-research/B001/00021D-00021J-clan-opcode4b-packet-helper-source-quality.md`

## Claim And Incorporation Ledger

| ID | Accepted Fact / Proposed Change | Evidence | Incorporation Target | State |
|---|---|---|---|---|
| 10E-C01 | Direct MCP proves [UID:00010E] is `sub_485AC0` at `0x00485ac0`, size `0x1fe` / 510 bytes, ending at `0x00485cbd`; `0x00485cbe` is not a function. | `lookup_funcs`, `int_convert`, target doc | target doc | applied |
| 10E-C02 | Post-target bytes at `0x00485cbe-0x00485cbf` are `0xcc 0xcc`; pre-target padding at `0x00485abe-0x00485abf` is also `0xcc 0xcc`; no split/merge needed for target. | `get_bytes`, [UID:00021K], [UID:00021L] | target doc | applied |
| 10E-C03 | The only code xref to target is [UID:0002O3] call site `0x00489fe3`; caller function `sub_489FC0` has size `0x29` / 41 bytes and vtable data xref `0x00615e54`. | `xrefs_to`, `analyze_function`, `disasm`, [UID:0002O3] docs | target doc and UID0002O3 support | applied |
| 10E-C04 | Caller loads `g_pClanStatusPane` / `unk_67ADE4` into `ECX` at `0x00489fdc` immediately before pushing the final argument and calling target. | `disasm 0x00489fc0`, `xrefs_to 0x0067ade4`, [UID:0002O3] docs | target doc and UID0002O3 support | applied |
| 10E-C05 | Target callee pops four stack arguments with `retn 10h` (`0x10` / 16), so an explicit `ClanStatusPane *` stack parameter is not ABI-faithful. | `disasm 0x00485ac0`, `int_convert`, [UID:00010D]/[UID:00021K] precedent | target doc | applied |
| 10E-C06 | Target packet layout is opcode `0x4b` / 75, subtype `6`, action `2`, three CP_ACP/WideCharToMultiByte converted strings capped by `0x100` / 256, then final big-endian 16-bit attribute/type value. | `analyze_function`, `decompile`, `disasm`, current target doc | target doc | applied |
| 10E-C07 | Packet writer helper call order should be source-modeled as value-first (`PacketBufferWriteUInt8(value, dest)` and `PacketBufferWriteUInt16BE(value, dest)`) because raw x86 pushes destination before value for stdcall. | `disasm 0x00485ac0`, [UID:00021G] accepted helper ABI note, [UID:0001HZ] | target doc | applied |
| 10E-C08 | Sending routes through `g_packetSender` at `0x0067a7ec` and `QueueAndSendPacket` / `sub_574BB0`; target references `g_packetSender` at `0x00485c8e`. | `xrefs_to 0x0067a7ec`, `analyze_function`, [UID:0001HU], g_packetSender docs | target doc | applied |
| 10E-C09 | Direct owner/emitter moved from pre-callback [UID:0000I8] to current/applied [UID:00002K], while generated source route remains [UID:0000I8] `NexusTK/social/Clan.cpp`. | current MCP caller/callee ABI, [UID:00021K], [UID:00010D], [UID:00002K] | target doc, ClanStatusPane support, Clan support | applied |
| 10E-C10 | [UID:0002O3] formal caller should use `g_pClanStatusPane->SendClanAttributePacket(...)` once [UID:00010E] is accepted as a member helper. | current MCP caller disasm, B004 preferred direction, UID0002O3 current caveat | UID0002O3 support | applied |
| 10E-C11 | [UID:00002K] class declaration/support should add `SendClanAttributePacket(...)` beside accepted subtype-6 status-pane packet helpers. | [UID:00021K] accepted support pattern, current MCP route | ClanStatusPane support | applied |
| 10E-C12 | [UID:0000I8] `Clan` support retains the source-file route and no longer treats [UID:00010E] as the narrow direct owner after the callback change. | Clan file, [UID:00002K] source route, current MCP route | Clan support | applied |
| 10E-C13 | [UID:00010F] `SubmitClanChangeHelper` is a sibling subtype `10`, action `2` helper and should not be modified by this UID00010E callback. | UID00010F support docs | none | excluded-with-reason: explicitly out of callback scope and not edited |
| 10E-C14 | [UID:00021L] raw subtype/name-action strip remains separate support context and should not be modified for target-only helper ownership except if supervisor explicitly scopes it. | UID00021L docs and B006 report | none | excluded-with-reason: explicitly out of callback scope and not edited |

## Positive Evidence Summary

- Live IDA MCP is healthy on `supervisor_recovery_20260705`: `server_health` reports `status: ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs` maps `0x00485ac0` and `0x00485cbd` to `sub_485AC0`, size `0x1fe` / 510. `0x00485cbe` is not a function.
- `callees` for `0x00485ac0` returns bounded callees: `sub_516030`, `sub_575380`, `sub_516220`, `sub_5753A0`, `sub_574BB0`, `@__security_check_cookie@4`, and `___report_rangecheckfailure`.
- `xrefs_to 0x00485ac0` returns exactly one code xref: `0x00489fe3` in `sub_489FC0`.
- `analyze_function 0x00489fc0` decompiles caller as forwarding `this + 620`, `this + 1132`, `this + 1644`, and `*(WORD *)(this + 2156)` to `sub_485AC0`.
- `disasm 0x00489fc0` proves the receiver load: `mov ecx, dword ptr unk_67ADE4` at `0x00489fdc` before `push eax` at `0x00489fe2` and `call sub_485AC0` at `0x00489fe3`.
- `disasm 0x00485ac0` proves target packet constants and stack cleanup: opcode `0x4b`, subtype `6`, action `2`, three `WideCharToMultiByte` conversions with `0x100` / 256 cap checks, final `sub_5753A0` 16-bit writer, `g_packetSender` load at `0x00485c8e`, `sub_574BB0` send call at `0x00485ca2`, and `retn 10h`.

## IDA MCP Facts

MCP session and health:

- Session id: `supervisor_recovery_20260705`
- `idb_list`: one active adopted worker session for `NexusTK.exe.i64`, not analyzing.
- `server_health`: `status ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis and Hex-Rays ready.

Function/boundary facts:

| Query | MCP Result |
|---|---|
| `lookup_funcs 0x00485ac0` | `sub_485AC0`, size `0x1fe` / 510 |
| `lookup_funcs 0x00485cbd` | same `sub_485AC0` |
| `lookup_funcs 0x00485cbe` | not a function |
| `lookup_funcs 0x00489fc0` | `sub_489FC0`, size `0x29` / 41 |
| `get_bytes 0x00485abe size 2` | `0xcc 0xcc` |
| `get_bytes 0x00485cbe size 2` | `0xcc 0xcc` |
| `get_bytes 0x00485cc0 size 32` | bytes begin `55 8b ec ...`, but current `lookup_funcs` does not map `0x00485cc0` to a function |

Decimal conversions from MCP `int_convert`:

- `0x1fe` = 510
- `0x30c` = 780
- `0x304` = 772
- `0x100` = 256
- `0x4b` = 75
- `0x26c` = 620
- `0x46c` = 1132
- `0x66c` = 1644
- `0x86c` = 2156
- `0x10` = 16
- `0x29` = 41

## Function / Child Inventory

| Address / Range | UID | Current / Applied Role | Current / Applied Direct Owner | Source Route / Notes |
|---|---|---|---|---|
| `0x00485960-0x00485abe` | `00021K` | subtype `6` action `0/1` refresh/selection helper cluster | `00002K` | already accepted `ClanStatusPane` packet methods |
| `0x00485abe-0x00485ac0` | none | two `0xcc` bytes | none | alignment before target |
| `0x00485ac0-0x00485cbd` | `00010E` | `ClanStatusPane::SendClanAttributePacket`, subtype `6` action `2` attribute/enlistment packet helper | `00002K` | generated source route remains [UID:0000I8] `Clan` / `NexusTK/social/Clan.cpp`; prior `0000I8` direct owner/emitter was pre-callback historical state |
| `0x00485cbe-0x00485cbf` | none | two `0xcc` bytes | none | alignment after target |
| `0x00485cc0-0x0048632e` | `00021L` | retained raw name/action helper strip | `0000I8` for that sibling/support page | support context only; no UID00010E edit required |
| `0x00486330-0x0048652d` | `00010F` | subtype `10`, action `2` sibling change helper | `0000I8` for that sibling/support page | support context only; no UID00010E edit required |

## Direct Xref / Caller Inventory

| Target | Xref Facts |
|---|---|
| `0x00485ac0` | one code xref at `0x00489fe3` from `sub_489FC0` / [UID:0002O3] |
| `0x00489fc0` | one data xref at `0x00615e54`, the `ClanEnlistInputDialog` submit vtable slot |
| `0x0067ade4` / `g_pClanStatusPane` | bounded `xrefs_to` includes [UID:0002O3] data ref at `0x00489fdc`, exactly the receiver load before target call |
| `0x0067a7ec` / `g_packetSender` | bounded `xrefs_to` includes [UID:00010E] data ref at `0x00485c8e`, immediately before packet send |

## Documentation Evidence And IDA Status

Current documentation is now consistent on behavior, direct owner/emitter, and source signature:

- [UID:0002O3] documents the four inherited submitted fields and now calls `g_pClanStatusPane->SendClanAttributePacket(...)` in formal C++.
- [UID:00002K] documents `ClanStatusPane` source placement through `Clan.cpp`, accepted subtype-6 packet helper member pattern for action `0/1`, and now lists `SendClanAttributePacket(...)`.
- [UID:0000I8] keeps the source-file route through `NexusTK/social/Clan.cpp` while reflecting [UID:00002K] as the narrow direct owner/emitter for [UID:00010E].
- [UID:00010D] already rejects an explicit `ClanStatusPane *` stack parameter for `SendClanLeaveResponse` because callers load the status pane as receiver. This is direct precedent for rejecting UID00010E's pre-callback explicit-context formal header shape.
- [UID:00021G] documents value-first packet writer ABI evidence. UID00010E now follows that helper-call direction in the formal draft.

## Ranked Ownership Analysis

1. [UID:00002K] `ClanStatusPane` direct owner/emitter

Evidence for: sole caller loads `g_pClanStatusPane` into `ECX`; callee has four stack args and `retn 10h`; accepted sibling helper pages already model unused-receiver packet helpers as `ClanStatusPane` methods; [UID:0002O3] is a dialog submitter that supplies payload fields but deliberately sends through the status pane singleton.

Evidence against: target body does not dereference `this`; pre-callback metadata was file-owned by `Clan`; exact original method visibility is unknown.

Decision: applied current direct owner/emitter for source-quality C++.

2. [UID:0000I8] `Clan` source-file route / pre-callback direct-owner candidate

Evidence for: the code belongs in the Clan packet helper island and generated source should still route through `NexusTK/social/Clan.cpp`.

Evidence against: file-level owner loses the explicit receiver evidence and conflicts with the accepted subtype-6 `ClanStatusPane` packet helper pattern.

Decision: keep as source-file route only, not narrow direct owner/emitter for UID00010E.

3. [UID:00002B] `ClanEnlistInputDialog`

Evidence for: sole direct caller is `ClanEnlistInputDialog::OnSubmitEnlistment`; caller supplies the submitted fields.

Evidence against: the caller switches `ECX` to `g_pClanStatusPane` before target call. The dialog is the payload source, not the packet helper owner.

Decision: reject as target owner; keep as caller/support.

4. File-local static helper with explicit `ClanStatusPane *`

Evidence for: pre-callback target formal C++ used it, and prior B004 allowed it as an implementation compromise before target audit.

Evidence against: `retn 10h` proves four explicit stack arguments, not five; `(void)statusPane` is a reconstruction convention rather than ABI/source evidence.

Decision: replaced with member helper in the applied target.

## Source Placement

Generated source placement remains `NexusTK/social/Clan.cpp`. The applied direct owner/emitter change does not imply a new source file; it routes the function through [UID:00002K] as the source class owner within the same Clan implementation family. Any [UID:0000I8] reference for UID00010E in this report is source-file route or pre-callback historical context, not the current direct owner/emitter.

Rejected placements:

- `ClanDialogs.cpp`: the dialog provides payload fields, but the receiver setup is `g_pClanStatusPane`.
- `ClanBank.cpp`: no bank packet or bank owner evidence.
- PacketBuffer/Socket helpers: they are dependencies, not semantic owners.

## Range / Split / Padding / Reclassification Analysis

No target range split is recommended.

- [UID:00010E] maps to one modeled function from `0x00485ac0` through `0x00485cbd`, size `0x1fe` / 510.
- The two bytes before target at `0x00485abe-0x00485abf` are `0xcc 0xcc`.
- The two bytes after target at `0x00485cbe-0x00485cbf` are `0xcc 0xcc`.
- Current `lookup_funcs` does not map `0x00485cc0` to a function even though bytes at `0x00485cc0` begin with a prologue-like sequence; [UID:00021L] remains a separate retained aggregate support page and should not be edited for this target-only pass unless supervisor scopes it.
- Reclassification to compiler thunk, duplicate raw helper, or no-code page is rejected because [UID:00010E] has a sole live caller and a concrete packet send body.

## Negative Evidence Summary

- No evidence supports keeping `ClanStatusPane *statusPane` as an explicit stack parameter. The callee cleanup and caller push count contradict it.
- No evidence supports moving the target to `ClanEnlistInputDialog`; the caller overwrites `ECX` with `g_pClanStatusPane` before the call.
- No evidence supports merging [UID:00010E] into [UID:00021K] or [UID:00021L]; padding bytes separate the ranges and the target has its own live caller and action `2` semantics.
- No evidence supports renaming the target to `SubmitClanChangeHelper`; [UID:00010F] is the subtype `10`, action `2` sibling.
- No evidence supports leaving the target's prose claim that C++ remains blank; the page already has formal C++ and current evidence improves that formal block.

## IDA Rename / Type / Comment Recommendations

These are optional IDA-side recommendations only; no IDA edits were made.

- Function `0x00485ac0`: name/comment as `ClanStatusPane::SendClanAttributePacket` or retain function name `SendClanAttributePacket` with type note `int __thiscall ClanStatusPane::SendClanAttributePacket(const wchar_t *, const wchar_t *, const wchar_t *, unsigned short)`.
- Global `0x0067ade4`: keep/source-comment as `g_pClanStatusPane`.
- Global `0x0067a7ec`: keep/source-comment as `g_packetSender`.
- Avoid raw names such as `sub_485AC0`, `unk_67ADE4`, and `dword_67A7EC` in formal source blocks.

## First-Draft C++ Recommendation

Callback-applied formal C++ currently present in the target:

```cpp
int ClanStatusPane::SendClanAttributePacket(
    const wchar_t *clanName,
    const wchar_t *descriptionText,
    const wchar_t *attributeText,
    unsigned short attributeType)
{
    unsigned char packet[0x304];
    char convertedText[0x100];
    unsigned int packetOffset = 0;

    PacketBufferWriteUInt8(0x4b, packet + packetOffset++);
    PacketBufferWriteUInt8(6, packet + packetOffset++);
    PacketBufferWriteUInt8(2, packet + packetOffset++);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP,
        0,
        clanName,
        wcslen(clanName),
        convertedText,
        sizeof(convertedText),
        NULL,
        NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + packetOffset++);
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    convertedLength = WideCharToMultiByte(
        CP_ACP,
        0,
        descriptionText,
        wcslen(descriptionText),
        convertedText,
        sizeof(convertedText),
        NULL,
        NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + packetOffset++);
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    convertedLength = WideCharToMultiByte(
        CP_ACP,
        0,
        attributeText,
        wcslen(attributeText),
        convertedText,
        sizeof(convertedText),
        NULL,
        NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + packetOffset++);
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    PacketBufferWriteUInt16BE(attributeType, packet + packetOffset);
    packetOffset += sizeof(attributeType);

    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetOffset));
}
```

Applied code notes:

- This is the formal target C++ shape after callback, not a side-only prose sample.
- Keep descriptive parameter names if no better source names are known. They are already supported by [UID:0002O3] and [UID:000024] field-role docs.
- The packet writer helper order is value-first, matching [UID:00021G] ABI analysis and raw push order in this target.
- The applied target removed `(void)statusPane` and the explicit-context static helper shape; the member header, four explicit payload arguments, `packet[0x304]`, and `convertedText[0x100]` are now current state.

## Final Recommendation

Supervisor callback implementation is complete:

1. [UID:00010E] target metadata is `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00002K`, `EMITTER_UIDS:00002K`; `RECONSTRUCTABLE:TRUE` and blank `EMITTER_POSITION_OPTIONAL` are preserved.
2. Target formal C++ now uses `ClanStatusPane::SendClanAttributePacket(...)` and value-first packet writer calls.
3. Target prose now includes current MCP provenance, exact boundary, caller, receiver, xref, packet layout, and negative signature evidence.
4. [UID:0002O3] formal caller/support prose now calls `g_pClanStatusPane->SendClanAttributePacket(...)` instead of passing `g_pClanStatusPane` as an explicit helper argument.
5. [UID:00002K] `ClanStatusPane` support now lists/documents `SendClanAttributePacket(...)` beside the accepted subtype-6 action `0/1` packet methods.
6. [UID:0000I8] `Clan` support keeps source route through `Clan.cpp` while reflecting [UID:00002K] as the direct owner/emitter.
7. [UID:00010F], [UID:00021L], packet-buffer/global helper docs, manual coverage files, lifecycle/archive files, executed reports, and supervisor ledgers were not edited.

## Recommended Target Doc Changes

Callback-applied target `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md`:

- Applied metadata transition: `COMPLETION:85 -> 88`, `CONFIDENCE:90 -> 92`, `CANONICAL_OWNER:0000I8 -> 00002K`, `EMITTER_UIDS:0000I8 -> 00002K`; `RECONSTRUCTABLE:TRUE` and blank optional emitter position are preserved.
- Applied status/provenance: active MCP session `supervisor_recovery_20260705`, healthy NexusTK IDB, `sub_485AC0`, size `0x1fe` / 510, exact `0xcc` padding after target, and sole xref/caller are now recorded.
- Applied signature replacement: explicit-context `static int SendClanAttributePacket(ClanStatusPane *statusPane, ...)` is superseded by `int ClanStatusPane::SendClanAttributePacket(const wchar_t *clanName, const wchar_t *descriptionText, const wchar_t *attributeText, unsigned short attributeType)`.
- Applied body facts: opcode `0x4b` / 75, subtype `6`, action `2`, three `WideCharToMultiByte(CP_ACP, ...)` conversions capped at `0x100` / 256, one-byte lengths, `memmove` copies, final big-endian 16-bit value, and `g_packetSender->QueueAndSendPacket` are preserved.
- Applied negative evidence: stale "C++ remains blank" wording is superseded; explicit `ClanStatusPane *` stack parameter is rejected by `ECX` receiver setup plus `retn 10h`.

## Recommended Support Doc Changes

Callback-applied support edits were limited to the docs needed for consistency:

- `by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md`: formal call now uses `g_pClanStatusPane->SendClanAttributePacket(m_submittedClanName, m_submittedDescriptionText, m_submittedAttributeText, m_submittedAttributeType);`; owner/emitter [UID:00002B], field offsets, and vtable route are preserved.
- `by-class/ClanStatusPane.md`: method declaration/child note now includes `int SendClanAttributePacket(const wchar_t *clanName, const wchar_t *descriptionText, const wchar_t *attributeText, unsigned short attributeType);`; the support note documents that the body may not dereference `this` but caller route supplies `g_pClanStatusPane`.
- `by-file/Clan.md`: [UID:00010E] row/source-family note now says direct owner/emitter is [UID:00002K] while source generation still routes through [UID:0000I8] `NexusTK/social/Clan.cpp`.
- `SubmitClanChangeHelper`, `ClanNameActionPacketHelpers`, packet-buffer/global helper docs, generated files, coverage reports, validator state, lifecycle/archive files, executed reports, and supervisor ledgers were not edited for this UID.

## Score And Metadata Recommendation

Applied `88/92` is intentionally conservative:

- Completion rose because the direct owner/emitter, formal C++ header, caller shape, support route, and stale no-code/status contradiction were fixed with target-specific evidence.
- Confidence rose because the live MCP disassembly verified the key prior B004 lead: `g_pClanStatusPane` is loaded into `ECX` immediately before the call, and target has four stack arguments.
- Completion remains below the low 90s because exact original source symbols for the three submitted text fields, exact helper visibility, and protocol enum names remain inferred/descriptive.

## Open Questions With Attempted Resolution

| Question | Attempted Resolution | Current Status |
|---|---|---|
| Is this a file-local helper or a `ClanStatusPane` member? | Checked live caller disasm, target cleanup, sibling B015/B010D support pattern. | Resolved in favor of member helper. |
| Are the three parameter names exact original symbols? | Checked UID0002O3, UID000024, and prior B004/B003 reports. | Descriptive/inferred; keep names but do not treat as final-source proof. |
| Should [UID:00021L] be edited because bytes at `0x00485cc0` begin with prologue-like code? | Checked current `lookup_funcs` and `get_bytes`; [UID:00021L] is separate aggregate support. | Not applicable to UID00010E callback. |
| Should [UID:00010F] be changed similarly? | Checked sibling helper docs; it is subtype `10`, action `2` and under separate assignment history. | Not applicable to UID00010E callback. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Do not manually edit generated coverage or tracker files. If supervisor execution later refreshes generated reports, the intended target summary is:

```text
[UID:00010E][0x00485ac0-0x00485cbd.SendClanAttributePacket](by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md) 0x00485ac0-0x00485cbd | packet helper | ClanStatusPane::SendClanAttributePacket : reconstructable : 88% : very strong : B009 2026-07-05 source-quality recheck uses live IDA MCP session supervisor_recovery_20260705 to confirm sub_485AC0 size 0x1fe / 510, exact opcode 0x4b subtype 6 action 2 packet layout with three CP_ACP converted length-prefixed strings and final big-endian 16-bit attribute/type value, sole caller [UID:0002O3] at 0x00489fe3, caller receiver load g_pClanStatusPane at 0x00489fdc, four-stack-argument callee cleanup retn 0x10, g_packetSender send path, alignment bytes at 0x00485cbe-0x00485cbf, and direct owner/emitter [UID:00002K] ClanStatusPane with generated source route through [UID:0000I8] NexusTK/social/Clan.cpp.
```

## Follow-Up Actions

Callback actions completed:

- Leased only the target, authorized support docs, and this report before editing.
- Applied target metadata/source/signature/prose update.
- Applied support consistency updates to [UID:0002O3], [UID:00002K], and [UID:0000I8] source-route support.
- Ran scoped file validators for the four changed by-* docs only.
- Recorded validator command ids, timestamps, exit codes, ok counts, warnings, and generated-refresh side effects in this report.
- Left [UID:00010F], [UID:00021L], packet-buffer/global helper docs, manual coverage files, validator state, lifecycle/archive files, executed reports, and supervisor ledgers untouched.
- Ready to return for supervisor `execute_report`; B009 did not run lifecycle/archive commands.

## Confidence

High for the applied owner/signature repair. The decisive facts are direct: current caller disassembly, target callee cleanup, xref shape, and accepted sibling pattern. Remaining uncertainty is limited to original source names/visibility and protocol enum labels, not to behavior or route.

## Validator Results

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the callback edits.

| File | Command ID | Timestamp | Exit | `ok` | Warnings / Notices | Validator-Reported Side Effects |
|---|---|---|---:|---:|---|---|
| `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md` | `000000006801` | `2026-07-05T05:25:36-04:00` | `0` | `1` | none reported | `completion_update 88`, `confidence_update 92`, `canonical_owner_update 0000I8 -> 00002K`, two `autogen_registry_update` rows, UID link inserts/updates, reference index adds, `projected_stats_update`; `generated_refresh: deferred` with same command id/timestamp. |
| `by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md` | `000000006802` | `2026-07-05T05:25:48-04:00` | `0` | `1` | none reported | `autogen_registry_update`, `uid_link_insert 00010E`, `reference_index_add 00002K`, `projected_stats_update`; `generated_refresh: deferred` with same command id/timestamp. |
| `by-class/ClanStatusPane.md` | `000000006803` | `2026-07-05T05:25:56-04:00` | `0` | `1` | `missing_ref_uid: 17` for pre-existing/unscoped references including `0003B8`, `000412`, `000413`, and `000411`; validator suppressed 7 more rows. | `autogen_registry_update`, `uid_link_insert 00010E`, `reference_index_add 00010E`, `reference_index_add 0002O3`, `projected_stats_update`; `generated_refresh: deferred` with same command id/timestamp. |
| `by-file/Clan.md` | `000000006804` | `2026-07-05T05:26:06-04:00` | `0` | `1` | `missing_ref_uid: 20` for pre-existing/unscoped references including `0003HE`, `000411`, `000412`, `000413`, `0003B8`, and `0003B9`; validator suppressed 10 more rows. | four UID link inserts, `stats_row_update 0000I8 project-level/-auto-completion-stats.md Low_Confidence_Not_Reconstructable`, `projected_stats_update`; `generated_refresh: deferred` with same command id/timestamp. |

No `execute_report`, dry-run/probing variant, registry lifecycle command, archive command, or manual report move was run.

## Changed Files

Manual callback edits:

- `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md`
- `by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md`
- `by-class/ClanStatusPane.md`
- `by-file/Clan.md`
- `tools/leaser/Agents/Agent-B009/research/00010E-SendClanAttributePacket-source-quality.md`

Excluded from manual edit scope:

- [UID:00010F] `by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md`
- [UID:00021L] `by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md`
- packet-buffer/global helper docs
- generated files, auto-generated reports, manual `-coverage-report.md` files, validator state, queue/lock files, lifecycle/archive files, executed-report records, supervisor ledgers, and report history footers

Validator-reported generated/index effects are limited to the scoped validator outputs recorded above; B009 made no manual edits to those generated/index artifacts.

## Implementation Tracking Checklist

- [x] Lease `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md`, `by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md`, `by-class/ClanStatusPane.md`, `by-file/Clan.md`, and this report before editing. Initial full-batch lease encountered existing leases for `ClanStatusPane` and `Clan`; partial leases were unleased, then the full authorized batch was leased successfully before edits.
- [x] Applied target metadata transition: `COMPLETION:85 -> 88`, `CONFIDENCE:90 -> 92`, `CANONICAL_OWNER:0000I8 -> 00002K`, `EMITTER_UIDS:0000I8 -> 00002K`; preserved `RECONSTRUCTABLE:TRUE` and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Replaced target formal C++ with `int ClanStatusPane::SendClanAttributePacket(const wchar_t *clanName, const wchar_t *descriptionText, const wchar_t *attributeText, unsigned short attributeType)`.
- [x] Incorporated target facts at report-level detail: MCP session `supervisor_recovery_20260705`, `sub_485AC0`, size `0x1fe` / 510, sole caller `0x00489fe3`, caller receiver load `0x00489fdc`, `retn 10h`, packet layout, `WideCharToMultiByte` cap, final 16-bit writer, `g_packetSender` send path, and padding bytes.
- [x] Removed/superseded stale target prose that says formal C++ remains blank; preserved rejected alternatives and negative evidence for explicit `ClanStatusPane *` parameter, dialog ownership, sibling merge, and subtype `10` confusion.
- [x] Updated [UID:0002O3] support formal caller to `g_pClanStatusPane->SendClanAttributePacket(...)` and kept submitted field offsets/names.
- [x] Updated [UID:00002K] support with the `SendClanAttributePacket(...)` method declaration/note beside subtype-6 packet helpers.
- [x] Updated [UID:0000I8] support to keep `Clan.cpp` source route while reflecting [UID:00002K] direct owner/emitter.
- [x] Confirm [UID:00010F], [UID:00021L], packet-buffer helper docs, and global helper docs are excluded from this callback and were not manually edited.
- [x] Do not edit generated files, auto-generated reports, manual `-coverage-report.md` files, validator state, queue/lock files, lifecycle/archive files, executed-report records, supervisor ledgers, or report history footers manually. Validator-reported generated/index side effects are recorded above.
- [x] Run scoped file validators only for changed by-* docs, record command id/timestamp/exit code/ok count/warnings/generated refresh side effects.
- [x] Attempt post-validator unlease for all five leased paths. The leaser returned `Rejected[No active lease]` for each path, so no active B009 lease remained to release. A prior typo using `release` instead of `unlease` failed with `unknown command` and did not change state.
- [x] Leave generated refresh/tracker changes to validator/supervisor execution only.
- [x] B009 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, or archive/move commands.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000006809","destination_path":"executed-b-agent-research/B009/00010E-SendClanAttributePacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00010E-SendClanAttributePacket-source-quality.md","timestamp":"2026-07-05T05:39:43-04:00","uid":"00010E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
