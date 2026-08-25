** TARGET-REPORT-UID:00049V **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
TARGET-REPORT-UID:00049V
TARGET: by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md
ASSIGNMENT: B006-implementation-00049V-ExchangeDialogSubmitExchangeAmount-source-quality-20260629
AGENT: Agent-B006
MODE: implementation callback - applied, awaiting supervisor verification

# UID00049V ExchangeDialogSubmitExchangeAmount Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: promote [UID:00049V] `ExchangeDialogSubmitExchangeAmount` to first-draft C++ emission through [UID:00004R] `ExchangeDialog`.
- Final disposition: source-authored `ExchangeDialog::SubmitExchangeAmount(unsigned int amount)` helper, not covered-by/no-code and not a rare no-improvement case.
- Required action after supervisor acceptance: update the target, ExchangeDialog class/file support pages, and the ExchangeDialog aggregate child row; run scoped validators and generated freshness checks.
- Confidence: high for behavior, packet layout, owner/emitter route, and helper names; medium-high for exact original member spellings and the `void` source return shape.

## Target

- Target UID: `00049V`
- Target path: `by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` not-covered reconstructable row, current `83/87`, average `85.0`, executed report count `0`.
- Current supervisor classification: report-only source-quality audit for blank `EMITTER_UIDS` and blank formal C++.
- Current scores and parent state: target `83/87`; direct owner [UID:00004R] `ExchangeDialog` is `86/88`; source file [UID:0000J9] `ExchangeDialog` is `88/86`.

## Current Target State

- Existing metadata: `COMPLETION:83`, `CONFIDENCE:87`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Existing owner/emitter/reconstructable state: direct owner and source route are already correct as [UID:00004R] `ExchangeDialog` -> [UID:0000J9] `ExchangeDialog`.
- Existing C++/emitter state: target explicitly says non-emitting because "fallback confirm/cancel source shape and packet helper abstraction names are not finalized".
- Existing blocker status after recheck: resolved. Current support pages and accepted sibling reports already define `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, `g_packetSender->QueueAndSendPacket`, and `g_pUserPane->m_itemCommandBusy`; the fallback path is the same `0x4A` subcommand `4` six-byte shape used by emitted UID00049U and UID00049Q.
- Related target/support docs checked: target page, [UID:00049U] `SendCancelPacket`, [UID:00049Q] `OnButtonAction`, [UID:00049T] `OnKeyEvent`, [UID:00049Y] `OnControlFocusChange`, [UID:00049W] `SetExchangeAmount`, [UID:00004R] class, [UID:0000J9] file, [UID:00014K] aggregate, [UID:0003YJ] PacketBuffer helpers, [UID:0001HU] `QueueAndSendPacket`, [UID:0000Q5]/[UID:0001P0] `g_packetSender`, and [UID:0000QK]/[UID:0001OR] `g_pUserPane` alias/global pages.

## Evidence Checked

IDA MCP current session:

- MCP endpoint initialized successfully; server `ida-pro-mcp` version `1.0.0`, tools/list count `65`.
- `idb_list` returned active session `691d4db6`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `7744`, `is_analyzing:false`.
- `server_health(database=691d4db6)` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, string count `2067`.
- `lookup_funcs(database=691d4db6)` confirmed `0x004ad960` as `sub_4AD960`, size `0xb6`; `0x004ada15` inside the same function; `0x004ada16` not a function; related starts `0x004ada20`, `0x004ad900`, `0x004ad0b0`, `0x00575380`, `0x005753f0`, and `0x00574bb0` are modeled functions.
- `analyze_function(addr=0x004ad960)` confirmed prototype `int __thiscall(unsigned int *this, unsigned int)`, size `182`, callees `sub_4ADA20`, `sub_575380`, `sub_5753F0`, `sub_574BB0`, and security-cookie support, callers `sub_4AC8A0`, `sub_4AD7D0`, `sub_4ADFB0`, and xrefs at `0x004acff9`, `0x004ad845`, and `0x004ae030`.
- `decompile(addr=0x004ad960)` confirmed `SetExchangeAmount(amount)` first, branch on `dword_67A748 + 16064`, fallback packet `{0x4A,4,exchangeId}` length `6`, and normal packet `{0x4A,3,exchangeId,amount}` length `10`.
- `disasm(addr=0x004ad960)` confirmed instruction-level branch `cmp byte ptr [eax+3EC0h],0` at `0x004ad980`; fallback calls `sub_575380(0x4A)`, `sub_575380(4)`, `sub_5753F0([this+0x26c])`, then sends length `6`; normal calls `sub_575380(0x4A)`, `sub_575380(3)`, `sub_5753F0([this+0x26c])`, `sub_5753F0(amount)`, then sends length `0x0a`.
- `analyze_function(addr=0x00575380)` confirmed `sub_575380` writes one byte and a spare zero byte, matching `PacketBufferWriteUInt8`.
- `analyze_function/disasm(addr=0x005753f0)` confirmed `sub_5753F0` writes four big-endian payload bytes and `byte ptr [dest+4]=0`, matching `PacketBufferWriteUInt32BE`.
- `analyze_function(addr=0x00574bb0)` confirmed the queue/send helper copies `packetSize` bytes, appends a zero to the allocated copy, and dispatches command `8` when the sender is not disabled.
- `int_convert.py` verified `0x3ec0` = `16064`, `0x26c` = `620`, `0x274` = `628`, `0x278` = `632`, `0x4A` = `74`, `0x0A` = `10`, `0x06` = `6`, `0xb6` = `182`, `0x64` = `100`, `0x5f` = `95`, and `0x11a` = `282`.

Documentation and report search:

- Required searches were run for `00049V`, `0x004ad960`, `ExchangeDialogSubmitExchangeAmount`, `SubmitExchangeAmount`, `0x4A`, `subcommand 3`, `subcommand 4`, `QueueAndSendPacket`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, `m_itemCommandBusy`, `dword_67A748`, and `dword_67A7EC`.
- Executed/active report search found no prior executed UID00049V report. Relevant supporting reports found: B001 UID00014K split report, B001 UID00049T, B002 UID00049Y, B003 UID00049Q/UID00049U, B012 UID00049S, and active B012 UID00049W report.
- Archived markdown search for UID00049V/address/name terms returned no matching report files.
- Generated file `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` is read-only evidence only: header `validator-command-id: 000000000986`, refreshed `2026-06-29T17:47:24-04:00`; it currently emits callers of `SubmitExchangeAmount(amount)` but no UID00049V body.

## Positive Evidence Summary

- UID00049V is an exact IDA-modeled function with live callsites, not a retained raw duplicate.
- The direct receiver, fields, and callers are ExchangeDialog-local: `this+0x26c` is `m_exchangeSessionId`, UID00049T and UID00049Y call this method after parsing local money control `6`, and the method always delegates local amount state to UID00049W.
- The previous packet-helper-name blocker is resolved by current docs and sibling implementations. UID00049U and UID00049Q already emit the same helper names and `g_pUserPane->m_itemCommandBusy` expression.
- The fallback source shape is no longer ambiguous: it is the six-byte `0x4A/4/sessionId` packet already represented by `ExchangeDialog::SendCancelPacket()`, selected here when `g_pUserPane->m_itemCommandBusy != 0`.
- The normal path is exactly a ten-byte `0x4A/3/sessionId/amount` money-submit packet.

## Negative Evidence Summary

- No evidence supports leaving `EMITTER_UIDS` blank: the target has live callsites, known owner route, current packet helper names, and no no-route/duplicate condition.
- A covered-by marker is not appropriate. UID00049V is a distinct modeled function called by UID00049T and UID00049Y; no other emitted function covers its `SetExchangeAmount(amount)` plus conditional send behavior.
- Socket/PacketBuffer/UserPane support pages are dependencies, not direct owners. Their helpers and globals explain call targets and field names but do not own this ExchangeDialog method.
- `ExchangeMoneyEditControlPane` is a caller/control dependency only; it supplies the amount text to callers, not this packet sender body.
- Exact original symbol spelling remains unknown, but project policy and current support precedent do not require original-name proof before first-draft emission when behavior and source role are this constrained.

## Heuristic / Inference Reanalysis And Validation

The old blocker named two issues: packet helper names and fallback confirm/cancel shape. Both were rechecked against current evidence rather than carried forward.

Packet helpers:

- [UID:0003YJ] documents `sub_575380` as `PacketBufferWriteUInt8` and `sub_5753F0` as `PacketBufferWriteUInt32BE`; current MCP reconfirmed those helper bodies.
- [UID:0001HU] and [UID:0000Q5]/[UID:0001P0] document `sub_574BB0(dword_67A7EC, packet, len)` as `g_packetSender->QueueAndSendPacket(packet, len)` with Socket-owned sender lifetime.
- The local spare zero written by the packet helper is not sent because the explicit send lengths are `6` and `10`.

Fallback shape:

- Current disassembly shows the branch operand is `dword_67A748 + 0x3ec0`; support docs close `dword_67A748` as source-facing `g_pUserPane` and `+0x3ec0` as `m_itemCommandBusy`.
- UID00049Q already uses the same source expression to select `0x4A` subcommand `4` versus `5`; UID00049U emits the same subcommand `4`/session id packet as a standalone cancel helper.
- Therefore UID00049V's fallback can be represented directly rather than hidden behind unresolved prose.

Return/source shape:

- The decompiler reports `int` because the final call returns the result of `QueueAndSendPacket`, but all source-facing callers ignore the result and the emitted sibling `SendCancelPacket()` is `void`.
- Best source reconstruction is `void ExchangeDialog::SubmitExchangeAmount(unsigned int amount)`, matching UI helper semantics and current ExchangeDialog style.

Rejected alternatives:

- `int ExchangeDialog::SubmitExchangeAmount(...)`: lower source plausibility; return value is decompiler/tail-call artifact and not used by callers.
- Fold into UID00049W: rejected because UID00049V adds packet-send behavior and has distinct callers.
- Fold into UID00049U: rejected because UID00049V has a normal subcommand `3` money-submit path with amount.
- Leave blank until UID00049W implementation: rejected as a UID00049V blocker. UID00049W is a stable callable sibling and an active B012 report separately recommends first-draft emission; UID00049V should still document and emit its own body.

## Ranked Ownership Analysis

### 1. [UID:00004R] ExchangeDialog

- Evidence for: `this` receiver uses ExchangeDialog state at `+0x26c`; callers are ExchangeDialog methods; class/file docs already route the method through `ExchangeDialog.cpp`; packet semantics are exchange-specific.
- Evidence against: none material. Some dependencies live in PacketBuffer, Socket, and UserPane, but those are helper/global supports.
- Decision: direct owner and emitter should be [UID:00004R].

### 2. [UID:0000J9] ExchangeDialog file root

- Evidence for: correct source-file route and generated output destination.
- Evidence against: by-structure direct owner should remain the class, not the file root, for a method with an ExchangeDialog receiver.
- Decision: support/source route only.

### 3. PacketBuffer, Socket, UserPane, or ProtocolSend

- Evidence for: helper/global dependencies.
- Evidence against: no ownership of ExchangeDialog receiver, fields, callers, or UI state.
- Decision: dependencies only; do not move ownership.

## Source Placement

- Recommended placement: `ExchangeDialog::SubmitExchangeAmount(unsigned int amount)` in `NexusTK/ui/dialogs/ExchangeDialog.cpp` through [UID:00004R] `ExchangeDialog`.
- Why this fits: adjacent emitted methods in the same generated file already call `SubmitExchangeAmount`, and sibling exchange packet helpers now emit through the same route.
- Remaining placement uncertainty: exact original member spellings are inferred; this affects final-audit confidence but not first-draft source placement.

## Range / Split / Padding / Reclassification Analysis

- UID00049V should remain a single exact child: `0x004ad960-0x004ada16`, IDA start `0x004ad960`, size `0xb6`, final instruction `retn 4` at `0x004ada13`, with `0x004ada16-0x004ada20` alignment before UID00049W.
- No split, merge, rename, or reclassification is recommended.
- The aggregate [UID:00014K] should remain non-emitting; only its child row for UID00049V needs update after implementation.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Recommended formal `RECONSTRUCTION_CPP CODE` insertion text for UID00049V:

```cpp
void ExchangeDialog::SubmitExchangeAmount(unsigned int amount)
{
    unsigned char packet[11];

    SetExchangeAmount(amount);

    PacketBufferWriteUInt8(0x4A, packet);

    if (g_pUserPane->m_itemCommandBusy != 0) {
        PacketBufferWriteUInt8(4, packet + 1);
        PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
        packet[6] = 0;

        g_packetSender->QueueAndSendPacket(packet, 6);
        return;
    }

    PacketBufferWriteUInt8(3, packet + 1);
    PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
    PacketBufferWriteUInt32BE(amount, packet + 6);
    packet[10] = 0;

    g_packetSender->QueueAndSendPacket(packet, 10);
}
```

Behavior preservation:

- Calls `SetExchangeAmount(amount)` before any send decision, matching `0x004ad971-0x004ad976`.
- Uses opcode `0x4A`, verified as decimal `74`, matching both branches.
- Uses subcommand `4` and length `6` when `g_pUserPane->m_itemCommandBusy` is nonzero.
- Uses subcommand `3`, `m_exchangeSessionId`, amount, and length `10` otherwise.
- Keeps local-only spare zero bytes at `packet[6]` or `packet[10]`, outside explicit send length, matching PacketBuffer helper side effects and sibling style.

Source-quality caveats:

- `SubmitExchangeAmount`, `m_exchangeSessionId`, `m_itemCommandBusy`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, and `g_packetSender` are source-facing inferred/descriptive names, not original-symbol proof.
- The `void` method return is source-shape inference from ignored callers and sibling UI helper style, while IDA's decompiler reports an `int` tail-return artifact.

## Score And Metadata Recommendation

- Current target metadata: `83/87`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004R`, blank `EMITTER_POSITION_OPTIONAL`, formal C++ populated as above.
- Rationale: first-draft code blocker is resolved; the method has exact range/callers, current MCP behavior, resolved helper/global names, and matching sibling packet precedent.
- Reason not higher: exact original field names, exact original helper declarations, and `void` return shape are inferred; UID00049W's own body is separately active report work.
- Rare no-improvement/no-code proof: not applicable. The evidence supports improvement and first-draft emission.

## Recommended Target Doc Changes

Target path: `by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md`

- Update metadata from `83/87`, blank `EMITTER_UIDS`, blank C++ to `88/90`, `EMITTER_UIDS:00004R`, formal `ExchangeDialog::SubmitExchangeAmount(unsigned int amount)` C++.
- Replace item summary and C++/no-code disposition so the old packet-helper/fallback blocker is marked resolved.
- Update MCP evidence to current session `691d4db6`, including exact range, callers, branch on `g_pUserPane + 0x3ec0`, packet layouts, helper names, and send lengths.
- Preserve boundary `0x004ada16-0x004ada20` alignment.
- Add support cross-references to PacketBuffer helpers, `QueueAndSendPacket`, `g_packetSender`, and `g_pUserPane` if not already present.

## Recommended Support Doc Changes

Support path: `by-class/ExchangeDialog.md`

- Update UID00049V method row to first-draft emitting `88/90` through UID00004R.
- Add or update class notes that `SubmitExchangeAmount` uses `m_exchangeSessionId`, `SetExchangeAmount`, `g_pUserPane->m_itemCommandBusy`, opcode `0x4A`, subcommand `3` normal money-submit, and subcommand `4` fallback send.

Support path: `by-file/ExchangeDialog.md`

- Add UID00049V to the Packet And Control Model as emitting `ExchangeDialog::SubmitExchangeAmount(unsigned int amount)` through `ExchangeDialog.cpp`.
- Note that this resolves the previous missing generated body behind current generated calls from UID00049T/UID00049Y.

Support path: `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`

- Update the UID00049V child row from non-emitting `83/87` to first-draft emitting `88/90`.
- Add a change note for current MCP session `691d4db6` and the resolved packet-helper/fallback blocker.

Already-present / no edit required support:

- [UID:0003YJ] PacketBuffer helper names already document the scalar writer family.
- [UID:0001HU] `QueueAndSendPacket` already documents the send funnel.
- [UID:0000Q5]/[UID:0001P0] already document `g_packetSender`.
- [UID:0000QK]/[UID:0001OR] already document `g_pUserPane` and `+0x3ec0` as `m_itemCommandBusy`.
- [UID:00049W] remains a separate active target; this report should only cite it as the stable callee unless the supervisor explicitly merges implementation scopes.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00049V-01 | UID00049V is exact IDA function `0x004ad960-0x004ada16`, size `0xb6`, with `0x004ada16` not a function. | 0.98 | MCP `lookup_funcs`, `analyze_function`, `disasm`. | Target Status/MCP Evidence; aggregate child row. | incorporate | applied |
| C-00049V-02 | Direct owner remains [UID:00004R] `ExchangeDialog`; source route remains [UID:0000J9]. | 0.96 | Target/class/file docs; receiver fields; callers. | Target metadata/status; class/file method rows. | incorporate | applied |
| C-00049V-03 | The method always calls `SetExchangeAmount(amount)` before packet send logic. | 0.98 | MCP decompile/disasm call at `0x004ad976`; UID00049W docs. | Target Behavior/C++; class/file notes. | incorporate | applied |
| C-00049V-04 | Branch condition is `dword_67A748 + 0x3ec0`, source-facing `g_pUserPane->m_itemCommandBusy`. | 0.94 | MCP disasm `0x004ad97b/0x004ad980`; g_pCollectionData/UserPane support pages; B003 UID00049Q report. | Target Behavior/C++; class/file notes. | incorporate | applied |
| C-00049V-05 | Normal path sends opcode `0x4A` subcommand `3`, exchange session id, amount, explicit length `10`. | 0.98 | MCP decompile/disasm; int_convert; PacketBuffer helper docs. | Target Behavior/C++; class/file packet model. | incorporate | applied |
| C-00049V-06 | Fallback path sends opcode `0x4A` subcommand `4`, exchange session id, explicit length `6`. | 0.98 | MCP decompile/disasm; UID00049U and UID00049Q sibling docs. | Target Behavior/C++; class/file packet model. | incorporate | applied |
| C-00049V-07 | `this+0x26c` is `m_exchangeSessionId`. | 0.94 | MCP disasm `[esi+26Ch]`; class/file docs; UID00049U/49Q precedent. | Target Behavior/C++; class Data And Controls. | incorporate | applied |
| C-00049V-08 | `sub_575380` and `sub_5753F0` are source-facing PacketBuffer scalar writers and no longer block first-draft C++. | 0.92 | UID0003YJ docs; current MCP helper analysis. | Target C++ disposition; support mention if needed. | incorporate | applied |
| C-00049V-09 | `sub_574BB0(dword_67A7EC,...)` maps to `g_packetSender->QueueAndSendPacket(...)`. | 0.92 | UID0001HU, UID0000Q5, UID0001P0; current MCP sender analysis. | Target C++ disposition; support mention if needed. | incorporate | applied |
| C-00049V-10 | Callers are constructor/setup `0x004acff9`, UID00049T at `0x004ad845`, and UID00049Y at `0x004ae030`. | 0.96 | MCP `analyze_function` xrefs/callers; caller docs. | Target MCP Evidence/Cross-References; aggregate row. | incorporate | applied |
| C-00049V-11 | Formal first-draft source should use `void ExchangeDialog::SubmitExchangeAmount(unsigned int amount)` despite decompiler `int`. | 0.86 | Ignored callers; UID00049U void sibling style; UI helper source-shape inference. | Target formal C++ and C++ disposition. | incorporate | applied |
| C-00049V-12 | No covered-by/no-code disposition is appropriate because this modeled live function has unique behavior not covered by any single emitted child. | 0.94 | MCP exact function/callers; comparison with retained raw duplicate policy. | Target C++ disposition. | incorporate | applied |
| C-00049V-13 | Recommended score is `88/90` and `EMITTER_UIDS:00004R`. | 0.88 | All current evidence; comparison with UID00049T/49Y/49S scores and UID00049U packet helper precedent. | Target metadata; class/file/aggregate rows. | incorporate | applied |
| C-00049V-14 | Existing generated `ExchangeDialog.cpp` is fresh to command `000000000986`, calls `SubmitExchangeAmount`, and currently lacks UID00049V body. | 0.92 | Read-only generated file header and body search. | Target generated-state note; file support note. | incorporate | applied |
| C-00049V-15 | PacketBuffer, Socket/g_packetSender, and UserPane support pages already contain sufficient helper/global facts; no direct edits to those support pages are required. | 0.90 | Support docs read; sibling accepted reports. | Implementation checklist exclusion. | already-present | already-present |
| C-00049V-16 | Active B012 UID00049W report separately recommends first-draft `SetExchangeAmount`; UID00049V should cite but not implement that target in this report. | 0.86 | Active B012 report; current UID00049W target docs. | Open caveat/checklist exclusion. | not-applicable | excluded-with-reason |

## Open Questions With Attempted Resolution

- Original exact member names: unresolved, but bounded to descriptive names already used in support docs. Score cap only.
- Original exact return type: inferred as `void` for source shape. The binary returns the queue/send result, but callers ignore it and sibling packet helper source uses `void`.
- UID00049W body emission: active B012 report handles that sibling. UID00049V's recommendation does not depend on editing UID00049W in this report-only pass.
- No Wave2/Wave3 directives were used as authority. Generated output was used only as read-only freshness/caller evidence.

## Validator Results

- `python .\tools\validator.py --mode file --file by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md --apply --queue-timeout 240`
  - `command_id: 000000001041`
  - `command_timestamp: 2026-06-29T18:27:33-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Warnings/errors: none reported for the target file.
  - Reported validator-owned side effects: `completion_update`, `confidence_update`, `autogen_registry_update`, `reference_index_add`, `projected_stats_update`; `generated_refresh: deferred`.
- `python .\tools\validator.py --queue-status`
  - `command_id: 000000001045`
  - `command_timestamp: 2026-06-29T18:27:51-04:00`
  - Exit code: `0`
  - Purpose: generated-refresh status check; at that instant UID00049V's generated refresh job was processing.
- `python .\tools\validator.py --queue-status`
  - `command_id: 000000001055`
  - `command_timestamp: 2026-06-29T18:31:09-04:00`
  - Exit code: `0`
  - Purpose: final queue check; queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- `python .\tools\validator.py --mode file --file by-class/ExchangeDialog.md --apply --queue-timeout 240`
  - `command_id: 000000001062`
  - `command_timestamp: 2026-06-29T18:38:36-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Warnings/errors: none reported for the class file.
  - Reported validator-owned side effects: `projected_stats_update`; `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-file/ExchangeDialog.md --apply --queue-timeout 240`
  - `command_id: 000000001063`
  - `command_timestamp: 2026-06-29T18:38:44-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Warnings/errors: none reported for the file page.
  - Reported validator-owned side effects: `projected_stats_update`; `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --queue-timeout 240`
  - `command_id: 000000001064`
  - `command_timestamp: 2026-06-29T18:38:52-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Warnings/errors: none reported for the aggregate file.
  - Reported validator-owned side effects: `projected_stats_update`; `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-class/ExchangeDialog.md --apply --queue-timeout 240`
  - `command_id: 000000001066`
  - `command_timestamp: 2026-06-29T18:41:39-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Purpose: final revalidation after stale historical wording cleanup; warnings/errors: none reported.
  - Reported validator-owned side effects: `projected_stats_update`; `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-file/ExchangeDialog.md --apply --queue-timeout 240`
  - `command_id: 000000001067`
  - `command_timestamp: 2026-06-29T18:41:46-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Purpose: final revalidation after stale historical wording cleanup; warnings/errors: none reported.
  - Reported validator-owned side effects: `projected_stats_update`; `generated_refresh: deferred`.
- `python .\tools\validator.py --queue-status`
  - `command_id: 000000001068`
  - `command_timestamp: 2026-06-29T18:41:56-04:00`
  - Exit code: `0`
  - Purpose: final generated-refresh status check; queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- Generated freshness check:
  - `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` header is now `validator-command-id: 000000001067`, `validator-refreshed-at: 2026-06-29T18:41:46-04:00`, `validator-refresh-source: deferred-generated-refresh`, which is newer than the target validator command `000000001041` and equal to the final file-support validator command `000000001067`.
  - The generated file now contains `// UID:00049V ... Completion:88 | Confidence:90` followed by `void ExchangeDialog::SubmitExchangeAmount(unsigned int amount)` with the accepted packet body; UID00049V is no longer omitted as a missing body.

## Changed Files

- Modified under a successful short B006 lease: `by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md`.
- Modified under a successful resumed short B006 lease: `by-class/ExchangeDialog.md`, `by-file/ExchangeDialog.md`, and `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`.
- Modified inside Agent-B006 report scope: `tools/leaser/Agents/Agent-B006/research/00049V-ExchangeDialogSubmitExchangeAmount-source-quality.md`.
- Validator-owned/generated side effects observed: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` refreshed from target command `000000001041` and later advanced to generated header `000000001067`; validator also reported projected stats and registry/index updates. These generated/tool-owned files were not manually edited.
- Renamed: none.
- Report execution: not performed. The supervisor runs `tools/validator.py execute_report ... --apply` only after verification.

## Implementation Tracking Checklist

- [x] Supervisor validation received before implementation callback.
- [x] Took a short B006 lease only for the immediate target edit/validator slice; did not take report-only leases.
- [x] Updated [UID:00049V] metadata to `COMPLETION:88`, `CONFIDENCE:90`, `EMITTER_UIDS:00004R`, with owner/reconstructable unchanged.
- [x] Populated [UID:00049V] formal `RECONSTRUCTION_CPP CODE` with `void ExchangeDialog::SubmitExchangeAmount(unsigned int amount)` exactly as recommended in this report.
- [x] Replaced [UID:00049V] old C++/no-code blocker text with the resolved first-draft C++ disposition, preserving exact MCP evidence and final-audit caveats.
- [x] Updated [UID:00049V] item summary, behavior, MCP evidence, cross-references, and change log with session `691d4db6`, packet layouts, `g_pUserPane->m_itemCommandBusy`, PacketBuffer helper names, `g_packetSender`, xrefs, and generated-state note.
- [x] Updated [UID:00004R] `by-class/ExchangeDialog.md` method row and relevant packet/control notes for UID00049V first-draft emission after shared leases were released.
- [x] Updated [UID:0000J9] `by-file/ExchangeDialog.md` Packet And Control Model / changes to state UID00049V now emits `SubmitExchangeAmount` through `ExchangeDialog.cpp`, including the resolved missing generated body behind UID00049T/UID00049Y calls.
- [x] Updated [UID:00014K] `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md` child inventory/change notes from UID00049V non-emitting `83/87` to first-draft emitting `88/90` while preserving boundary/padding and split-container facts.
- [x] Did not edit PacketBuffer, QueueAndSendPacket, g_packetSender, g_pUserPane/global, generated files by hand, coverage reports, project-level generated reports by hand, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files.
- [x] Preserved negative evidence on the target: no covered-by/no-code disposition, no PacketBuffer/Socket/UserPane owner move, no merge into UID00049U/UID00049W, no original-name overclaim.
- [x] Preserved active-sibling note: UID00049W remains separate B012 report/callback scope unless supervisor combines scopes.
- [x] Ran scoped validator from `source-3/project-documentation` after accepted target edits: `python .\tools\validator.py --mode file --file by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md --apply --queue-timeout 240`, command `000000001041`, timestamp `2026-06-29T18:27:33-04:00`, exit `0`, `ok: 1`.
- [x] Ran scoped validators for edited support docs `by-class/ExchangeDialog.md`, `by-file/ExchangeDialog.md`, and `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`; commands `000000001062`, `000000001063`, and `000000001064` all exited `0` with `ok: 1`. After cleanup of stale historical wording, final class/file revalidators `000000001066` and `000000001067` also exited `0` with `ok: 1`.
- [x] Recorded validator command, command_id, command_timestamp, exit code, and ok count in this report and callback result.
- [x] Checked generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` freshness after validation: header `000000001067` is newer than target validator command `000000001041` and equal to final file-support validator command `000000001067`, and UID00049V emits as a body rather than an empty marker.
- [x] Updated this report's Claim And Incorporation Ledger verification states for applied/already-present/excluded items; no accepted UID00049V implementation claim remains blocked.
- [x] Left supervisor-owned executed-report archival to the supervisor; did not move this report.

Lease history: B006 first completed and released the target-page lease, then paused on a real support-doc lease conflict. On resume, shared `tools/leaser/Agents/current_leases.md` showed no active leases. B006 leased `by-class/ExchangeDialog.md`, `by-file/ExchangeDialog.md`, and `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`, applied the remaining support-doc details, validated all three files, and released the leases immediately after the edit/validator/generated-freshness batch.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00049V-ExchangeDialogSubmitExchangeAmount-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/00049V-ExchangeDialogSubmitExchangeAmount-source-quality.md","timestamp":"2026-06-29T18:44:12","uid":"00049V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
