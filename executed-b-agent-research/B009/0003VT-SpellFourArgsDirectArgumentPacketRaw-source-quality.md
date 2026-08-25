** TARGET-REPORT-UID:0003VT **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B009 Source-Quality Report: [UID:0003VT] SpellFourArgsDirectArgumentPacketRaw

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality.md`  
Target path: `source-3/project-documentation/by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md`  
Assignment: `B009-goal2-spell-four-args-direct-argument-packet-raw-source-quality-0003VT-20260619`  
Status: implementation callback complete and ready for supervisor execute. B009 edited the target by-memory page and this report, verified the listed support docs as already-present/no-edit, ran the scoped target validator, and released the target lease. No manual generated files, coverage reports, validator state, queue/lock files, lifecycle/archive files, supervisor ledgers, IDA database files, report moves, or `execute_report` commands were used.

## Finalized Report / Current Recommendation

Current recommendation: keep [UID:0003VT] as a no-route, non-emitting raw packet island, but improve the target/support docs with the stronger source-quality analysis below.

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE: blank
```

Recommended disposition:

- Do not promote this target to [UID:0000DL] `SpellFourArgsInputPane` yet.
- Do not emit C++ for this target.
- Do not mark it compiler-generated, runtime, or padding. It is source-shaped NexusTK packet-builder bytes, but no static route proves it is live source that should be reconstructed.
- Keep the target as documented no-route executable evidence inside the [UID:0001LN] `SpellArgumentInputPanes` physical/source-family index.

Confidence in recommendation: strong for behavior, packet layout, range, and no-route static evidence; medium-high for the non-reconstructable policy because raw source-shaped retained helpers are handled differently in some nearby families when owner/liveness evidence is stronger.

Score rationale: keep the current post-validator target score at `86/88`. Supervisor scoped validator command `000000006893` already applied the `85/86 -> 86/88` target update, and this repair adds current IDA MCP confirmation instead of the old fallback-only wording. Do not raise beyond `86/88` because the current IDA session still shows no function object, no entry xrefs, no code/data refs, no VA/RVA pointer-pattern hits, no caller, no vtable route, no recovered source declaration/name, and no runtime trace.

## Target

- Target UID: [UID:0003VT]
- Target path: `by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md`
- Current target name: `SpellFourArgsDirectArgumentPacketRaw`
- Current metadata after supervisor validator command `000000006893`: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- Current coverage classification: `ignored/non-emitting`.
- Current source-family context: [UID:0000O0] `SpellInputPanes`, [UID:0000DL] `SpellFourArgsInputPane`, and parent/index [UID:0001LN] `SpellArgumentInputPanes`.

## Current Target State

The current target page exists at `by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md` and now carries `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional emitter position, and an empty formal `RECONSTRUCTION_CPP CODE` block. That state matches the accepted no-owner/non-emitting disposition after supervisor validator command `000000006893`.

Current target prose records the packet layout, `m_spellIndex` field direction at `this+0x108`, no-route/no-code proof, owner/source-placement ranking, and current `supervisor_recovery_20260705` route-negative MCP evidence. The old target-doc sentence saying B009 could not reach live IDA MCP was historicalized/replaced during this implementation callback.

## Supporting Research

The useful prior research remains valid after current MCP recheck: the body at `0x005b0a10-0x005b0abb` is source-shaped spell packet code, but it still has no static route that justifies ownership or emission. The report therefore keeps the current target metadata at `86/88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter, and blank formal C++ while proposing only documentation-quality improvements and stale-MCP-wording cleanup for a later callback.

Historical lifecycle status: the executed artifact was marked for revalidation because the old validator could not resolve target UID `0003VT`, then returned to active B009 research by validator command `000000006891` at `2026-07-05T08:09:57-04:00`. The two active top-level validator status/reason header lines were removed from this de-executed repair copy per supervisor override; the validator-owned `VALIDATOR-REPORT-HISTORY` footer is preserved unchanged.

## Evidence Standards Used

- IDA MCP evidence is current and mandatory for this repair. I used the active `supervisor_recovery_20260705` session only through narrow, schema-current calls: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `xref_query`, `find`, `find_bytes`, `get_bytes`, `find_xref_signatures`, `callees`, and `disasm` against exact target or nearby addresses.
- Ghidra/exported function data remains supplemental evidence for body shape only. It does not override current IDA route-negative evidence.
- Current by-* docs are evidence for target state and surrounding source-family context. During the Gate 1 report-only repair no by-* docs were edited; during the implementation callback B009 edited only the target by-memory page and verified the listed support docs as already-present/no-edit.
- Score and metadata recommendations are conservative: no-owner/non-emitting raw helpers need route evidence before owner/emitter/reconstructable promotion, even when the bytes are source-shaped.

## Evidence Checked

Primary target/support docs:

- `by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md`
- `by-memory/0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput.md`
- `by-memory/0x005b0780-0x005b080d.SpellFourArgsInputPaneConstructor.md`
- `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`
- `by-class/SpellFourArgsInputPane.md`
- `by-file/SpellInputPanes.md`

Sibling no-route raw helpers:

- `by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md`
- `by-memory/0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw.md`
- `by-memory/0x005b1200-0x005b1278.SpellOneArgDirectArgumentPacketRaw.md`
- `by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md`

Packet/send dependencies:

- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`

Raw-helper policy precedents:

- `by-memory/0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender.md`
- `tools/leaser/Agents/Agent-B001/research/executed/older/0002S8-chatpacket-rawsender-source-route.md`

Generated/disassembler exports used as supplemental evidence, not source authority:

- Local IDA JSON export: `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x005b08a0.json`
- Local IDA JSON export: `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x005b0780.json`
- Ghidra/exported function record: `resources/exported_data/functions/0x005b0a10.json`
- Ghidra test export: `hooks-generation/tests/function_data/ghidra/0x005b0a10.json`
- Combined function-data export: `hooks-generation/tests/function_data/combined/functions/0x005b0a10.json`

Prior live-IDB notes used as evidence leads and cross-check inputs:

- `tools/leaser/Agents/Agent-A002/notes.md`, 2026-06-16 spell-input batch and supervisor follow-up.
- `tools/leaser/Agents/Supervisor_notes.md` and `SupervisorAssignments.md` entries for the A002 split and current B009 assignment.

Read-only coverage/generated state:

- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`

Tool state:

- Current IDA MCP initialized through `http://127.0.0.1:13337/mcp`; `idb_list` returned one active adopted worker session, `supervisor_recovery_20260705`, for `NexusTK.exe.i64`.
- `server_health` for `supervisor_recovery_20260705` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`, and `strings_cache_ready: true`.
- Current MCP `lookup_funcs` returned no function at `0x005b0a10`, `0x005b0abb`, or `0x005b0abc`; the live parsed-confirm sibling at `0x005b08a0` remains `sub_5B08A0`, size `0x162`.
- Current MCP `xrefs_to` / `xref_query` found zero refs to the entry `0x005b0a10`; `find` found zero `code_ref`, `data_ref`, and immediate hits for the target start/RVA; `find_bytes` found zero matches for little-endian VA/RVA byte patterns `10 0A 5B 00`, `10 0A 1B 00`, `A0 0A 5B 00`, and `A0 0A 1B 00`.
- Current MCP `disasm 0x005b0a10` rendered the target as `<no function>` in `.text`, with packet writer calls at `0x005b0a2f`, `0x005b0a43`, `0x005b0a54`, `0x005b0a65`, `0x005b0a76`, and `0x005b0a87`, send call at `0x005b0aa5`, `retn 10h` at `0x005b0ab8`, alignment at `0x005b0abb`, and successor `sub_5B0AC0` at `0x005b0ac0`.
- Supervisor scoped target validator command `000000006893` (`2026-07-05T08:10:12-04:00`) is incorporated as current target-state evidence: it exited `0`, `ok: 1`, applied path/score/header updates, and left generated refresh deferred.
- `int_convert.py` verified `0xab` / 171, `0x10` / 16, `0x108` / 264, `0x134` / 308, `0x130` / 304, `0x12a` / 298, and `0x0f` / 15.

## Heuristic / Inference Reanalysis And Validation

### 1. Raw helper status

The target is a real helper-shaped body, not padding and not a compiler-generated thunk. Both the current target docs and the Ghidra/exported record agree that the range forms a complete function-shaped packet builder: it writes opcode `0x0f`, writes the `this+0x108` spell index byte, serializes four explicit word arguments as big-endian 16-bit fields, writes a spare zero outside the sent payload, and queues a 10-byte packet. This is behavior evidence only. The exact target C++ block should remain blank because no source route is proven.

Direct evidence:

- Current target page records raw helper-shaped body `0x005b0a10-0x005b0abb`.
- Ghidra export reports a function at `0x005b0a10`, size `0xab` / 171 bytes (Verified with `int_convert.py`), signature `__thiscall FUN_005b0a10(void *this, short param_1, short param_2, short param_3, short param_4)`.
- Ghidra export reports four callees: `0x00575380`, `0x005753a0`, `0x00574bb0`, and `0x005c772f`.
- Ghidra export reports zero callers and no data refs.
- Current MCP `lookup_funcs` confirms IDA still does not model a function at `0x005b0a10`, `0x005b0abb`, or `0x005b0abc`.

Inference:

- The helper is source-shaped application packet code, probably compiled from a source-level member or private helper with `this` in `ECX` and four stack `short` arguments.
- The `retn 0x10` ending matches four stack arguments, `0x10` / 16 bytes (Verified with `int_convert.py`), after a `__thiscall` receiver in `ECX`.
- The `__security_check_cookie` callee is compiler instrumentation around the stack local packet buffer, not application protocol logic.

Rejected alternatives:

- Padding/alignment: rejected because the body has a prologue, stack cookie, packet writes, send call, and `retn 0x10`.
- Compiler-generated thunk/destructor: rejected because it writes opcode `0x0f`, serializes spell arguments, and calls the packet sender.
- PacketBuffer-owned helper: rejected because PacketBuffer functions are callees; the body uses spell-pane state at `this+0x108`.
- Socket-owned helper: rejected because `QueueAndSendPacket` and `g_packetSender` are dependencies, not semantic owners of feature packet construction.

### 2. Route and reachability

The current static evidence still supports no-route/non-emitting classification.

Positive route evidence checked:

- [UID:0001LO] parsed confirm handler is vtable-routed through `0x0062f488`.
- [UID:0001LM] constructor has direct calls from spell inventory paths `0x0057cb12`, `0x0057e43a`, and `0x0057f13d`.
- The inline construction path in [UID:0003UC] `0x005a4530` also allocates and initializes `SpellFourArgsInputPane` with the same vtables and `this+0x108` field.

Target route-negative evidence:

- Current MCP `lookup_funcs 0x005b0a10`: no IDA function object; boundary checks at `0x005b0abb` and `0x005b0abc` also return no function.
- Current MCP `xrefs_to` / `xref_query` for `0x005b0a10`: zero entry refs.
- Current MCP `find` for `code_ref`, `data_ref`, and immediates against the target start/RVA: zero hits.
- Current MCP `find_bytes` for little-endian target-start/interior VA/RVA patterns: zero hits.
- A002's 2026-06-16 live IDA pass independently reported no function object, zero xrefs, and zero pointer-literal hits for the same target start.
- Ghidra/exported record reports `num_callers: 0` and `data_refs: []`.
- Current `auto-generated/-ag-memory-coverage.md` lists [UID:0003VT] as `not_reconstructable`, owner `NONE`, no emitted generated output.

Remaining evidence not available:

- No runtime execution trace proves that this raw helper is ever called.
- No recovered source/header declaration proves the original helper name, member spelling, or API exposure.
- No non-IDA raw PE rel32 byte sweep was run in this repair; current IDA MCP `xrefs_to`, `xref_query`, `find code_ref`, and xref-signature checks are negative and sufficient to keep the no-route recommendation, but not sufficient for a 95+ certainty claim.

Conclusion:

- Static route remains unproven. The correct current policy is no-owner/non-emitting.
- Promotion to `SpellFourArgsInputPane` would require at least one of: a direct or indirect caller, a pointer table/vtable slot, a raw PE VA/RVA/rel32 route, a runtime execution trace, or authoritative source naming showing this helper was deliberately retained and should be emitted.

### 3. Relationship to `SpellFourArgsInputPaneConfirmInput`

[UID:0001LO] is the active virtual submit handler. It parses a text line, requires three comma separators, converts four substrings through CRT `__wtol`, writes the same packet layout, and calls `QueueAndSendPacket` with length `10`.

The target [UID:0003VT] mirrors only the packet-builder half:

| Field | Parsed confirm handler [UID:0001LO] | Raw direct helper [UID:0003VT] |
| --- | --- | --- |
| Reachability | Vtable slot `0x0062f488` | no IDA xrefs, no Ghidra callers |
| Input source | `LineInputPane` text, three commas, four `__wtol` conversions | four explicit `short` stack arguments |
| Receiver | `SpellFourArgsInputPane *this` | `this` in `ECX`, inferred same class from `this+0x108` and adjacency |
| Packet opcode | `0x0f` / 15 (Verified with `int_convert.py`) | `0x0f` / 15 (Verified with `int_convert.py`) |
| Packet byte `+1` | `*(byte *)(this+0x108)` | `*(byte *)(this+0x108)` |
| Argument fields | four big-endian 16-bit words at `+2/+4/+6/+8` | four big-endian 16-bit words at `+2/+4/+6/+8` |
| Terminator | zero at `+10`, outside sent length | zero at `+10`, outside sent length |
| Sent length | 10 bytes | 10 bytes |

Best inference:

- [UID:0003VT] is a retained direct-argument variant of the same spell-use packet builder. It probably existed in source as a private method or helper used when arguments were already numeric, while [UID:0001LO] parsed typed text. However, the static binary no longer shows any route to it.

Rejected inference:

- It is not an alternate active confirm handler. The class vtable points to [UID:0001LO], not this raw helper.
- It is not a replacement for [UID:0001LO]; it lacks parsing/validation/error behavior.

### 4. Packet writer/helper names

Source-facing names should use the current PacketBuffer helper docs:

- `0x00575380`: [UID:0003YJ] `PacketBufferWriteUInt8` or `PacketBufferWriteByte`. Best descriptive name in this report: `PacketBufferWriteUInt8`.
- `0x005753a0`: [UID:0003YJ] `PacketBufferWriteUInt16BE`. This writes high byte then low byte and appends the local spare zero outside the caller's counted payload.
- `0x00574bb0`: [UID:0001HU] `QueueAndSendPacket`. It queues through [UID:0000Q5] `g_packetSender`, currently best typed as `Socket *`.
- `0x005c772f`: `__security_check_cookie`, compiler instrumentation.

Rejected names:

- `CashShopRequest::meth_0x574bb0`: stale generated/Ghidra naming. The Socket docs prove `0x00574bb0` is the shared Socket queue/send helper.
- Generic `Packet_QueueAndSend` as final name: useful shorthand but less precise than `QueueAndSendPacket` in project docs.
- `FUN_005753a0`: raw generated name only; source-facing text should use `PacketBufferWriteUInt16BE`.

### 5. `this+0x108` field name/type

Best current source-facing field name:

Use a one-byte member at offset `+0x108` with descriptive name `m_spellIndex` until original member spelling is recovered.

Confidence:

- High for one-byte width and packet position.
- High for role as selected spell record/index byte.
- Medium for exact original member name.

Evidence:

- [UID:0001LM] constructor stores the byte constructor argument to `this+0x108`.
- The same constructor uses that byte to index the local-player spell record table through `g_pCollectionData + 0x13a794 + 0x148 * signed(spellIndex)`.
- [UID:0001LO] parsed confirm handler serializes `this+0x108` as packet byte `+1`.
- [UID:0003VT] raw helper serializes the same `this+0x108` byte at packet byte `+1`.
- `0x108` / 264 was verified with `int_convert.py`.

Rejected names:

- `m_spellId`: possible at protocol level, but constructor behavior is more specifically "spell record index/slot byte" than an arbitrary spell database id.
- `m_spellSlot`: plausible in UI terms, but slot has a separate spell-slot prompt family and this constructor indexes a spell record by byte.
- `m_opcode`: rejected; opcode is hard-coded `0x0f`, not stored at this field.

### 6. Argument names/types

Best source-facing signature if a route is later proven:

The future route-proven member shape would be a `SpellFourArgsInputPane` method that accepts four `short` arguments; keep this as prose only while the formal target C++ remains blank.

Better descriptive alternatives:

- `SendFourArgumentSpellPacket`
- `SendSpellUsePacket`
- `SendDirectArgumentPacket`

Recommended current documentation name:

```text
SpellFourArgsInputPane::SendDirectArgumentPacketRaw
```

Use "descriptive/inferred" in docs, not "confirmed original." The original name is not recoverable from current binary evidence.

Argument semantics:

- All four stack arguments are word-sized values truncated/serialized as 16-bit big-endian fields.
- No local range checks appear in the helper. The parsed confirm handler obtains its values through `__wtol` and truncates to 16 bits before writing. This raw direct helper appears to assume its caller already supplied validated numeric spell arguments.
- Final semantic names for the individual words cannot be recovered from this generic helper. Use `arg1`/`arg2`/`arg3`/`arg4` or `argument1`..`argument4`, not spell-specific names.

Rejected names:

- `x/y/targetId/count`: no per-field evidence supports special meanings.
- `row/col/slot/color`: no caller exists to anchor these meanings.
- `spellId` for any of the four word arguments: the spell identifier/index is already the byte at `this+0x108`.

### 7. Source placement

Best source-family context:

- [UID:0000O0] `SpellInputPanes.cpp`.
- [UID:0000DL] `SpellFourArgsInputPane`.

Current route decision:

- Keep `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` because the helper has no caller/pointer/vtable route.

If route is later found:

- First owner candidate: [UID:0000DL] `SpellFourArgsInputPane`, because the helper is a `__thiscall` body that reads `this+0x108`, sits immediately after the class's active confirm handler, and sends the exact four-argument spell packet.
- First source file candidate: [UID:0000O0] `SpellInputPanes.cpp`.

Rejected source placements:

- [UID:0000O0] as canonical owner now: a by-file source-family context is weaker than the class candidate, and no emitting route is proven.
- [UID:0000M8] `PacketBuffer`: rejected; the target is a caller of PacketBuffer write helpers.
- [UID:0000NS]/[UID:0000DD] Socket: rejected; queue/send is a dependency.
- A new `ProtocolSend` owner: rejected; project docs warn not to centralize feature-specific packet builders solely because they call `QueueAndSendPacket`.
- `SpellInventoryPane`: constructor callers originate in spell inventory paths, but this raw helper has no caller from spell inventory and reads `this+0x108` from a spell input pane object.

### 8. Reconstructable/no-code policy

This target should remain `RECONSTRUCTABLE:FALSE` under the current project policy for no-route raw packet islands. The bytes are source-shaped, but the rebuild should not emit a function that no known source path calls. The page is valuable as coverage/evidence, not as generated source.

Target-specific no-code proof:

- IDA does not model a function at the entry.
- IDA `xrefs_to` found zero entry refs in the prior live pass.
- The prior pointer-byte scan found no little-endian pointer literal to `0x005b0a10`.
- Ghidra recognizes the body as a function but reports zero callers and no data refs.
- No vtable slot points here; the actual `SpellFourArgsInputPane` virtual confirm slot points to [UID:0001LO] at `0x005b08a0`.
- No direct constructor or inline-construction path calls this helper.
- No recovered source name or declaration proves it was retained in the original source API.

Code-entry decision:

- Keep formal target C++ blank.
- Do not emit a standalone static helper or class method unless route evidence appears.
- A future candidate source body can be preserved in support docs as "if route is found" guidance only.

### 9. Historical assumptions rechecked

Historical/current assumptions that remain valid:

- The target is a direct-argument opcode `0x0f` packet body.
- It sits between [UID:0001LO] and [UID:0001LP], separated by documented `0xcc` alignment.
- It should not be absorbed into [UID:0001LO] or [UID:0001LP].
- It should not be emitted from [UID:0000O0] solely because it is adjacent to SpellInputPanes code.

Assumptions that need stronger wording:

- "No-route raw code island" should explicitly mention that Ghidra sees a function but also sees zero callers/data refs. This resolves a possible contradiction between IDA not modeling the function and another disassembler recognizing the code body.
- "No recovered helper name" should be replaced with a best descriptive naming direction: `SpellFourArgsInputPane::SendDirectArgumentPacketRaw` / `SendFourArgumentSpellPacket` if a route is later found.
- `this+0x108` should be named `m_spellIndex` descriptively, not left as a raw offset.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b0780-0x005b080d` | [UID:0001LM] `SpellFourArgsInputPaneConstructor` | Constructor; stores `m_spellIndex` at `+0x108` | TRUE | [UID:0000DL] | `86/90` | source route proven |
| `0x005b08a0-0x005b0a02` | [UID:0001LO] `SpellFourArgsInputPaneConfirmInput` | Active virtual parsed confirm handler | TRUE | [UID:0000DL] | `86/89` | vtable route proven |
| `0x005b0a02-0x005b0a10` | [UID:0000VN] ignored row | alignment padding | FALSE | ignored | `100/strong` | fourteen `0xcc` bytes |
| `0x005b0a10-0x005b0abb` | [UID:0003VT] target | no-route direct four-argument packet body | FALSE recommended | NONE | `86/88` recommended | no route |
| `0x005b0abb-0x005b0ac0` | [UID:0000VN] ignored row | alignment padding | FALSE | ignored | `100/strong` | five `0xcc` bytes |
| `0x005b0ac0-0x005b0b4d` | [UID:0001LP] `SpellThreeArgsInputPaneConstructor` | next constructor | TRUE | [UID:0000DV] | `86/90` | source route proven |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0062f488 -> 0x005b08a0` | vtable data xref | active `SpellFourArgsInputPane` confirm handler route |
| `0x0057cb12`, `0x0057e43a`, `0x0057f13d -> 0x005b0780` | direct constructor calls | spell inventory creates four-arg prompt panes |
| `0x005b0a10` | IDA `lookup_funcs`: no function | IDA did not promote raw helper |
| `0x005b0a10` | IDA `xrefs_to`: zero | no static IDA route in prior live pass |
| `10 0A 5B 00` | IDA pointer-byte scan: zero hits | no stored pointer literal to target start in prior live pass |
| `0x005b0a10` | Ghidra/export: size `0xab` / 171, zero callers, no data refs | body recognized by Ghidra, but still no route |
| `0x00575380` | target callee | `PacketBufferWriteUInt8` |
| `0x005753a0` | target callee | `PacketBufferWriteUInt16BE` |
| `0x00574bb0` | target callee | `QueueAndSendPacket` |
| `0x005c772f` | target callee | `__security_check_cookie` |

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`, non-emitting no-route raw island

Evidence for:

- No IDA function object, no IDA xrefs, no pointer-literal hits in A002 live pass.
- Ghidra/exported function record also reports zero callers and no data refs.
- Vtable route for the live four-argument handler points to [UID:0001LO], not this target.
- The helper's source shape is clear but no source exposure is proven.
- Existing no-route raw packet precedent [UID:0002S8] uses the same conservative classification when source-shaped packet bytes lack a static route.

Evidence against:

- The body is coherent, stack-cookie protected, source-shaped application logic.
- It uses `this+0x108`, so it is probably class-related if live.
- It sits inside the SpellFour/Three numeric argument corridor, not in random padding.

Decision: accepted. The positive behavior evidence proves documentation value; the route-negative evidence blocks ownership/emission.

### 2. [UID:0000DL] `SpellFourArgsInputPane`

Evidence for:

- `__thiscall` receiver and `this+0x108` field match the class constructor and parsed confirm handler.
- Physical adjacency is immediately after [UID:0001LO].
- Packet layout is exactly the four-argument spell-use packet.
- If a caller appears, this is the likely direct semantic owner.

Evidence against:

- No vtable slot, caller, pointer, or runtime route currently targets this helper.
- The class already has an active parsed confirm handler at [UID:0001LO].
- Assigning now would emit or document a source method with no proof it was live.

Decision: best future owner if route is found; reject current promotion.

### 3. [UID:0000O0] `SpellInputPanes.cpp`

Evidence for:

- The target lies inside the spell argument input pane physical cluster.
- The file owns the spell prompt pane family.
- If the original helper was file-local, this source file is plausible.

Evidence against:

- By-structure rules prefer the narrow class owner when class receiver/field evidence exists.
- No route is proven, so even file-level ownership would be speculative.

Decision: source-family context only. Do not set canonical owner or emitter to the file.

### 4. PacketBuffer / Socket / g_packetSender / ProtocolSend

Evidence for:

- The target calls PacketBuffer writers and `QueueAndSendPacket`.
- `g_packetSender` is read for send handoff.

Evidence against:

- These are shared dependencies used by many feature packet builders.
- The target's feature opcode and `this+0x108` spell input state make it feature-side packet construction.
- Project docs explicitly reject centralizing feature packet builders under a generic protocol owner solely due to send-helper use.

Decision: rejected as owners.

### 5. Compiler/runtime/generated artifact

Evidence for:

- Stack-cookie instrumentation and security check call are compiler-generated inside the body.
- IDA did not model the raw entry.

Evidence against:

- The body writes application opcode `0x0f`, class field `this+0x108`, four protocol argument words, and calls project packet helpers.
- It is not a thunk, vtable, RTTI, EH-only, CRT, or padding span.

Decision: rejected. The body is source-shaped application code but currently non-emitting due no route.

## Source Placement

Current source placement: none. [UID:0003VT] remains a documented no-route raw code island inside the spell argument input pane address cluster, not an emitting source method or file-level helper.

Best future placement if route evidence appears:

- Direct owner: [UID:0000DL] `SpellFourArgsInputPane`.
- Source-family/file route: [UID:0000O0] `SpellInputPanes.cpp`.
- Method/helper role: direct four-explicit-argument spell packet sender that reads the class's `m_spellIndex` byte and sends opcode `0x0f`.

Rejected current placements:

- [UID:0000DL] as current owner: rejected because current MCP and exports still show no caller, xref, pointer, vtable slot, or runtime route.
- [UID:0000O0] as current direct owner/emitter: rejected because file-family adjacency is weaker than class receiver evidence and still lacks liveness proof.
- PacketBuffer, Socket, `g_packetSender`, and ProtocolSend: rejected as dependency-side transport helpers.
- Compiler/runtime/padding: rejected because the body performs application spell-packet serialization.
- [UID:0001LO] parsed confirm handler replacement: rejected because the active virtual route points to `0x005b08a0`, while [UID:0003VT] lacks parsing/validation and route evidence.

Remaining uncertainty: the original source may have had a private direct-argument helper that is now unreferenced in the linked binary, or the bytes may be dead retained code. Current evidence supports documentation but not emission.

## Claim And Incorporation Ledger

Callback verification state updated after the Gate 1 implementation callback. Only the target by-memory page required editing; support docs were checked and already carried the accepted support facts at same-or-greater detail.

| Row | Claim / accepted fact | Destination if accepted | Action | Verification state |
| --- | --- | --- | --- | --- |
| VT-C01 | Historical top-level validator status/reason header facts were lifecycle repair state from the de-executed artifact, not current report body truth. | Report body under `Supporting Research`; footer unchanged | historicalize | applied |
| VT-C02 | Current target state after supervisor validator command `000000006893`: `86/88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank optional emitter position, blank formal C++. | Target header verified unchanged after edit and validator `000000006901` | already-present | already-present |
| VT-C03 | Current MCP session `supervisor_recovery_20260705` is healthy for `NexusTK.exe.i64`; IDA still has no function object at `0x005b0a10`, `0x005b0abb`, or `0x005b0abc`. | Target `Item Summary`, `Status`, `Evidence`, `Changes` | incorporate | applied |
| VT-C04 | Current MCP xref/route checks remain negative: zero entry xrefs, zero `code_ref`/`data_ref` route hits, zero immediate hits for VA/RVA, and zero little-endian VA/RVA byte-pattern hits for target start/interior samples. | Target `Item Summary`, `Evidence`, owner table, no-code proof, score rationale | incorporate | applied |
| VT-C05 | Current MCP disassembly proves source-shaped packet body bytes even though IDA names the range `<no function>`: packet writers, `this+0x108`, send call, `retn 10h`, `0xcc` alignment at `0x005b0abb`, and successor `sub_5B0AC0`. | Target `Evidence`; existing behavior section already carried packet layout at same-or-greater detail | incorporate | applied |
| VT-C06 | Ghidra/exported data remains supplemental body-shape evidence only: it sees size `0xab` / 171, thiscall-like four-short shape, zero callers, and no data refs. | Target `Evidence`, `Score Rationale`; unchanged support docs already carry this detail | incorporate | already-present |
| VT-C07 | Best future owner if route evidence appears is [UID:0000DL] `SpellFourArgsInputPane`, with [UID:0000O0] `SpellInputPanes.cpp` as source-family placement; current owner/emitter stays `NONE`/blank. | Target owner table verified; class/file support docs already present at same-or-greater detail | incorporate | already-present |
| VT-C08 | PacketBuffer, Socket, `g_packetSender`, ProtocolSend, compiler/runtime, padding, and [UID:0001LO] active confirm handler are rejected as current direct owners/replacements. | Target owner table and relationship section verified; support docs already present | incorporate | already-present |
| VT-C09 | Formal target C++ remains blank with target-specific no-code proof. Any future route-proven C++ must be inserted only through the formal `RECONSTRUCTION_CPP CODE` block after owner/source route evidence appears. | Target formal C++ block verified blank; no-code proof updated with current MCP route-negative evidence | incorporate | applied |
| VT-C10 | Support docs should be updated only for context/caveat wording if callbacked: [UID:0001LN], [UID:0001LO], [UID:0000DL], and [UID:0000O0]; PacketBuffer/Socket/global helper docs need no score/metadata edits. | Support docs checked: `SpellArgumentInputPanes`, `SpellFourArgsInputPaneConfirmInput`, `SpellFourArgsInputPane`, and `SpellInputPanes` already carry accepted support facts at same-or-greater detail | already-present | already-present |
| VT-C11 | No generated files, manual coverage reports, validator state, queue/lock files, lifecycle/archive files, IDA DB edits, or report moves are authorized for B009. | No manual edits made outside target/report; scoped validator `000000006901` produced validator-managed projected stats/generated-refresh side effects only | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- The bytes at `0x005b0a10-0x005b0abb` are coherent application code, not padding: current MCP disassembly shows a stack-cookie prologue, packet writer calls, `g_packetSender` send path, `__security_check_cookie`, and `retn 10h`.
- Packet semantics are strong: opcode `0x0f`, `m_spellIndex` at `this+0x108`, four big-endian 16-bit argument writes at packet offsets `+2/+4/+6/+8`, spare zero at `+10`, and sent length `10`.
- Source-family relationship is strong: the body sits between the live four-argument parsed confirm handler and the three-argument constructor, and it mirrors [UID:0001LO]'s packet-builder tail without the text parsing and comma validation.
- The best future source route is defensible if liveness appears: [UID:0000DL] `SpellFourArgsInputPane` in [UID:0000O0] `SpellInputPanes.cpp`.
- Current target metadata `86/88` is justified because packet behavior, range, dependencies, field direction, rejected alternatives, and no-code proof are now documented with current MCP evidence.

## Negative Evidence Summary

Evidence checked and rejected as insufficient for promotion:

- Address adjacency: useful for source-family context, not ownership proof.
- Ghidra function recognition: validates body shape, but Ghidra also reports zero callers/data refs, so it does not prove reachability.
- Packet layout similarity to [UID:0001LO]: validates semantics, not route.
- `this+0x108` field access: makes [UID:0000DL] the best future owner, but no current call path uses the helper.
- Shared packet helper callees: dependencies, not owner evidence.
- Generated/simroot owner pollution: not used as source authority. Existing generated references broadly attach many unrelated recovered senders to class files and cannot override IDA/doc route evidence.

Missing evidence that would change the recommendation:

- A direct code call or jump to `0x005b0a10`.
- A function-pointer or table entry containing `0x005b0a10`.
- A rel32 branch to the target start or into the body.
- A runtime trace showing execution.
- Authoritative source/header naming proving this helper was retained and used.

## First-Draft C++ Recommendation

Formal target C++ should remain blank. Exact formal target C++ insertion text:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No-code proof:

- Current MCP `lookup_funcs` confirms no IDA function object at the entry or target boundaries.
- Current MCP `xrefs_to`, `xref_query`, and `find code_ref` confirm no entry route.
- Current MCP `find data_ref`, `find immediate`, and `find_bytes` confirm no pointer/immediate evidence for the checked target start/RVA patterns.
- Ghidra zero callers and no data refs.
- No vtable route.
- No source/helper name proof.
- The active source-authored UI route is [UID:0001LO], not this target.

Do not populate this target's `RECONSTRUCTION_CPP CODE` block.

If future route evidence appears, the most plausible source-style direction is a `SpellFourArgsInputPane` private/member helper that sends opcode `0x0f` with four `short` arguments and `m_spellIndex`; that future body must be supplied as exact formal `RECONSTRUCTION_CPP CODE` text only after route proof and final helper/member names are accepted.

## Recommended Target Doc Changes

Update `by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md`:

1. Metadata:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

2. Keep formal C++ blank.

3. Add behavior at report-level detail:

- Ghidra/exported size is `0xab` / 171 bytes (Verified with `int_convert.py`).
- Function-shaped signature is `__thiscall` with `this` plus four `short` stack arguments.
- Ends with `retn 0x10`, matching four 4-byte stack arguments; `0x10` / 16 verified with `int_convert.py`.
- Writes opcode `0x0f` / 15 (Verified with `int_convert.py`) at packet offset `+0`.
- Writes `this+0x108` / 264 (Verified with `int_convert.py`) at packet offset `+1`; document this field descriptively as `m_spellIndex`.
- Writes four `PacketBufferWriteUInt16BE` fields at packet offsets `+2`, `+4`, `+6`, and `+8`.
- Writes zero terminator at packet offset `+10`, outside the sent length.
- Calls `QueueAndSendPacket(g_packetSender, packet, 10)`.
- Calls `__security_check_cookie` as compiler instrumentation.

4. Add route analysis:

- IDA no function object.
- IDA zero xrefs to entry.
- IDA pointer-byte scan for `10 0A 5B 00` found no hits.
- Ghidra function recognition exists but reports zero callers and no data refs.
- No vtable slot or constructor path references the helper.

5. Add owner ranking:

- `NONE` accepted now.
- [UID:0000DL] `SpellFourArgsInputPane` is best future owner if route appears.
- [UID:0000O0] `SpellInputPanes.cpp` is source-family context only.
- PacketBuffer/Socket/g_packetSender/ProtocolSend rejected as dependencies.
- Compiler/runtime rejected because body is application packet logic.

6. Add source-facing naming recommendation:

- Current page title remains acceptable.
- Best descriptive future method name: `SpellFourArgsInputPane::SendDirectArgumentPacket` or `SendFourArgumentSpellPacket`.
- Best field name: `m_spellIndex` for `+0x108`.
- Best parameter names: `arg1`..`arg4` or `argument1`..`argument4`; no spell-specific per-word semantics are proven.

7. Add score rationale:

```text
Keep current `86/88` after supervisor command `000000006893`: behavior, packet layout, helper names, field role, owner ranking, source-placement alternatives, Ghidra zero-caller evidence, current MCP route-negative evidence, and target-specific no-code proof are documented. Confidence remains capped below final-audit levels because no caller/pointer/vtable/runtime route or recovered source declaration/name proves this helper should be emitted.
```

## Recommended Support Doc Changes

### [UID:0001LN] `SpellArgumentInputPanes`

Update open questions and direct packet row wording:

```text
[UID:0003VT] remains a no-route/non-emitting direct-argument raw body. B009 reanalysis confirms the best descriptive future source shape is a `SpellFourArgsInputPane` direct packet helper taking four `short` arguments and reading `m_spellIndex` at `+0x108`, but no caller/pointer/vtable/runtime route exists. Keep it ownerless/non-emitting unless route evidence appears.
```

Replace the stale "final C++ threshold" wording with the active code-entry policy:

```text
Do not add final reconstruction C++ for this aggregate; exact live children should carry formal code when their source routes and names are ready. No-route raw islands stay blank/non-emitting unless route evidence appears.
```

### [UID:0001LO] `SpellFourArgsInputPaneConfirmInput`

Add a sibling-helper note:

```text
Adjacent [UID:0003VT] mirrors this handler's packet-builder half without the text/comma/`__wtol` parsing: it accepts four explicit `short` arguments, writes the same opcode `0x0f`, `m_spellIndex` byte, four big-endian 16-bit argument words, and length-10 send. It is not the active virtual confirm handler because the vtable slot routes here to `0x005b08a0`, while [UID:0003VT] has no IDA entry xrefs, no pointer-literal hits, and Ghidra reports zero callers/data refs.
```

### [UID:0000DL] `SpellFourArgsInputPane`

Add a method/evidence row or note:

```text
Related no-route raw body: [UID:0003VT] `0x005b0a10-0x005b0abb` is a source-shaped direct four-argument packet sender that reads this class's stored spell index byte at `+0x108`, but it is not currently a class-owned emitting method because no caller, pointer, vtable slot, or runtime route is proven. If route evidence appears, the best descriptive method name is `SendDirectArgumentPacket(short arg1, short arg2, short arg3, short arg4)`.
```

Also add or confirm:

```text
`+0x108` should be documented as `unsigned char m_spellIndex` or `m_spellIndexByte` until original member spelling is recovered.
```

### [UID:0000O0] `SpellInputPanes`

Add the source-placement caveat:

```text
The four/three/two/one/slot direct raw packet islands are source-family evidence adjacent to the spell input pane methods, but they are not emitted from `SpellInputPanes.cpp` while they have no static route. [UID:0003VT] is the four-argument case; [UID:0000DL] is only a future owner candidate until a caller/pointer/runtime route is found.
```

### [UID:0003YJ] / [UID:0001HU] / [UID:0000Q5]

No required score or metadata changes. If touched for cross-reference clarity only:

- Use `PacketBufferWriteUInt8` for `0x00575380`.
- Use `PacketBufferWriteUInt16BE` for `0x005753a0`.
- Use `QueueAndSendPacket` for `0x00574bb0`.
- Keep `g_packetSender` as Socket-owned dependency, not feature owner.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` in this report pass. Supervisor-owned replacement row for [UID:0003VT]:

```text
    - [UID:0003VT][0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw](by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md) 0x005b0a10-0x005b0abb | no-route raw code island | SpellFourArgsDirectArgumentPacketRaw : ignored/non-emitting : 86% : strong : B009 source-quality recheck keeps this source-shaped four-explicit-argument spell packet helper non-emitting: current MCP session `supervisor_recovery_20260705` finds no IDA function object at `0x005b0a10`, zero entry xrefs/code refs/data refs, and zero target-start/interior VA/RVA pointer-pattern hits, while Ghidra/exported data recognizes a `0xab` / 171-byte `__thiscall` body with four `short` arguments but reports zero callers and no data refs. The body writes opcode `0x0f`, `m_spellIndex` from `this+0x108`, four big-endian 16-bit argument words at packet offsets `+2/+4/+6/+8`, an unsent zero at `+10`, and sends length `10` through `g_packetSender` / `QueueAndSendPacket`; keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/final C++ unless a caller, pointer table, rel32/raw PE route, or runtime trace proves liveness.
```

Coverage row score text uses `strong` rather than `very strong` because current MCP route checks are negative but no runtime trace or recovered source declaration proves original liveness/non-liveness beyond doubt.

## Validator Results

During the Gate 1 report-only repair, B009 did not run validators and did not edit target/support by-* docs. Validator evidence incorporated from the supervisor goal for that phase:

- Command: `python .\tools\validator.py --mode file --file by-memory\0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md --apply --queue-timeout 240`
- `command_id: 000000006893`
- `command_timestamp: 2026-07-05T08:10:12-04:00`
- Exit code: `0`
- `ok: 1`
- Side effects recorded by supervisor: `path_update`, `completion_update 86`, `confidence_update 88`, `canonical_owner_update NONE`, `insert_header_blank`, registry/reference/projected stats updates, `stats_incremental_noop`, and `generated_refresh: deferred`.

Future scoped validator commands for supervisor callback, if by-* docs are edited:

Run only for files edited during implementation, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality-removed.md](0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor also applies the coverage row:

> Executable block R002 was removed from this report and preserved verbatim in [0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality-removed.md](0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: validators exit `0` with `ok: 1`; [UID:0003VT] remains absent from generated C++ output and remains `not_reconstructable` in `auto-generated/-ag-memory-coverage.md`.

Implementation callback scoped validator run by B009 after the target edit:

- Command: `python .\tools\validator.py --mode file --file by-memory\0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md --apply --queue-timeout 240`
- `command_id: 000000006901`
- `command_timestamp: 2026-07-05T08:25:10-04:00`
- Exit code: `0`
- `ok: 1`
- Warnings: none reported.
- Side effects: `projected_stats_update: 1`, `stats_incremental_noop: 1` with note `0003VT project-level/-auto-completion-stats.md file is not present in generated stats lists`, `projected_stats_update ------ project-level/-auto-completion-stats.md updated projected path completion section`, and `generated_refresh: deferred` with `generated_refresh_command_id: 000000006901` / `generated_refresh_timestamp: 2026-07-05T08:25:10-04:00`.

## IDA Rename, Type, And Comment Recommendations

Do not edit IDA in this report pass. Current MCP is available, but no IDA mutation is authorized or needed for the no-route recommendation.

- Do not forcibly create an IDA function unless the project wants raw islands modeled in IDA; current no-route policy does not require it.
- If modeled for analysis, descriptive name: `SpellFourArgsInputPane_SendDirectArgumentPacket_raw`.
- Descriptive analysis type only, not an IDA edit request: thiscall receiver plus four word-sized stack arguments serialized as 16-bit big-endian packet fields.
- Comment at `0x005b0a10`: "No-route raw direct four-argument spell packet helper. Mirrors SpellFourArgsInputPane confirm packet builder but has no caller/pointer/vtable route; do not emit unless liveness is proven."
- Field comment at `SpellFourArgsInputPane+0x108`: `unsigned char m_spellIndex` / "serialized as opcode 0x0f packet byte +1."
- Callee names:
  - `0x00575380`: `PacketBufferWriteUInt8`
  - `0x005753a0`: `PacketBufferWriteUInt16BE`
  - `0x00574bb0`: `QueueAndSendPacket`
  - `0x005c772f`: `__security_check_cookie`

Confidence:

- Behavior and callee names: high.
- Future helper name: medium, descriptive only.
- Exact original member name for `+0x108`: medium.
- Liveness/owner: currently negative; do not promote without new evidence.

## Implementation Instructions For Supervisor Callback

1. Lease all target/support docs before editing. Do not edit `by-memory/-coverage-report.md` unless supervisor explicitly delegates that shared file; use the exact row above for supervisor-owned coverage work.

2. Update target [UID:0003VT]:
   - Confirm current score remains `86/88`; do not lower or raise unless callback verification finds drift.
   - Keep `CANONICAL_OWNER:NONE`.
   - Keep `RECONSTRUCTABLE:FALSE`.
   - Keep blank `EMITTER_UIDS`.
   - Keep formal C++ blank.
   - Add or refresh packet behavior, helper names, `m_spellIndex` field naming, Ghidra zero-caller evidence, current MCP route-negative proof, owner ranking, rejected alternatives, and score rationale at report-level detail.
   - Historicalize target-doc wording that says B009 could not reach live IDA MCP; current MCP session `supervisor_recovery_20260705` is healthy and route-negative.

3. Update support docs:
   - [UID:0001LN] `SpellArgumentInputPanes`: refine direct raw helper policy and remove stale 95-only C++ wording if still present.
   - [UID:0001LO] `SpellFourArgsInputPaneConfirmInput`: add sibling-helper note comparing parsed confirm behavior to [UID:0003VT].
   - [UID:0000DL] `SpellFourArgsInputPane`: document [UID:0003VT] as related no-route evidence, not a class-owned emitting method, and record `+0x108` as `m_spellIndex`.
   - [UID:0000O0] `SpellInputPanes`: clarify that direct raw packet islands remain source-family evidence only until route evidence appears.

4. Do not update PacketBuffer/Socket/global scores unless implementation reveals stale text. The current support docs already carry enough PacketBuffer and Socket ownership evidence.

5. Validate edited files with the scoped commands above. Record command IDs, timestamps, exit codes, `ok` counts, warnings, and generated-refresh side effects in this report if this becomes an implementation callback.

6. Record the exact pending coverage row above. Do not manually edit generated reports.

## Score And Metadata Recommendation

Current and recommended target metadata are identical after supervisor validator command `000000006893`:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Reason not lower: current MCP and exported evidence prove a real source-shaped packet body, exact range, packet layout, helper calls, `m_spellIndex` field use, sibling relationship, and source-family context. The page is more complete than its old `85/86` state.

Reason not higher: no current IDA function object, no entry xrefs, no code/data refs, no VA/RVA pointer-pattern hits, no vtable slot, no caller, no runtime trace, and no recovered source declaration/name prove ownership or emission. The helper remains a no-route raw island, so `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank formal C++ stay correct.

## Open Questions With Attempted Resolution

- Is [UID:0003VT] live source code? Attempted resolution: current MCP route checks (`lookup_funcs`, `xrefs_to`, `xref_query`, `find code_ref`, `find data_ref`, `find immediate`, `find_bytes`, `find_xref_signatures`) remain negative for the entry/start patterns. Result: unresolved liveness, but resolved current policy as no-owner/non-emitting.
- Should [UID:0000DL] become canonical owner? Attempted resolution: receiver/field/adjacency evidence makes it the best future owner, but no route reaches the helper. Result: reject current promotion; keep as future owner candidate.
- Should formal C++ be populated from the clear packet behavior? Attempted resolution: no, because the function has no proven source route and the project does not emit no-route raw islands. Result: formal C++ remains blank with target-specific no-code proof.
- Does current MCP remove the old score cap? Attempted resolution: it removes the old "MCP unavailable" cap, but it confirms no route rather than proving emission. Result: keep `86/88`; do not raise to route-ready/final-audit scores.
- Is the stale target-doc "B009 could not reach MCP" wording still accurate? Attempted resolution: no. Result: replaced/historicalized in the target during this implementation callback with current `supervisor_recovery_20260705` MCP route-negative evidence.

## Changed Files

B009 changed these files during the implementation callback:

- `by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md`
- `tools/leaser/Agents/Agent-B009/research/0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality.md`

Support docs checked and not edited because the accepted support facts were already present at same-or-greater detail:

- `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`
- `by-memory/0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput.md`
- `by-class/SpellFourArgsInputPane.md`
- `by-file/SpellInputPanes.md`

No manual edits were made to generated files, project-level generated files, coverage reports, validator state, queue/lock files, lifecycle/archive files, supervisor ledgers, IDA database files, or report moves. Scoped validator `000000006901` produced validator-managed projected stats/generated-refresh side effects as recorded in `Validator Results`.

## Final Recommendation

[UID:0003VT] should stay no-owner, non-reconstructable, non-emitting, and blank-C++. The binary body is source-shaped and should be documented more deeply, but the current route search does not justify promotion to `SpellFourArgsInputPane` or `SpellInputPanes.cpp`.

Best future action if new evidence appears: verify any new caller, pointer table, vtable slot, raw PE rel32/VA/RVA route, runtime trace, or recovered source declaration against the target start and interior bytes. If any route is found, promote the helper to [UID:0000DL] with emitter [UID:0000DL] and prepare exact formal `RECONSTRUCTION_CPP CODE` for a source-style `SpellFourArgsInputPane` direct-argument packet sender after final helper/member names are accepted.

## Implementation Tracking Checklist

Implementation callback status:

- [x] Leased only the file actually edited: `by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md`; lease acquired as B009 and released immediately after target validation. `current_leases.md` after release shows no active B009 lease.
- [x] Target doc `by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md`: kept `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++; historicalized stale "B009 could not reach live IDA MCP" wording and incorporated current `supervisor_recovery_20260705` route-negative evidence at report-level detail.
- [x] Target doc: preserved packet facts, range `0x005b0a10-0x005b0abb`, size `0xab` / 171, `retn 10h`, `this+0x108` as `m_spellIndex`, four big-endian 16-bit argument writes, zero outside sent payload, send length `10`, `g_packetSender` / `QueueAndSendPacket`, and `__security_check_cookie` instrumentation.
- [x] Target doc: preserved rejected alternatives and negative evidence for [UID:0000DL] current ownership, [UID:0000O0] current file ownership, PacketBuffer/Socket/g_packetSender/ProtocolSend ownership, compiler/runtime/padding classification, and [UID:0001LO] replacement.
- [x] Support doc `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`: checked and already present at same-or-greater detail; it records [UID:0003VT] as ownerless/non-emitting, direct four-argument packet body, `m_spellIndex`, no route, blank aggregate C++ policy, and direct-packet raw island caveat. No edit required.
- [x] Support doc `by-memory/0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput.md`: checked and already present at same-or-greater detail; it contains the sibling-helper comparison, parsed-confirm distinction, vtable route to `0x005b08a0`, and [UID:0003VT] no-route/non-emitting disposition. No edit required.
- [x] Support doc `by-class/SpellFourArgsInputPane.md`: checked and already present at same-or-greater detail; it documents related no-route raw body [UID:0003VT], `+0x108` as `m_spellIndex`, future method direction, and non-class-emitter caveat. No edit required.
- [x] Support doc `by-file/SpellInputPanes.md`: checked and already present at same-or-greater detail; it preserves `SpellInputPanes.cpp` as conditional future source family only, keeps [UID:0003VT] ownerless/non-emitting, and rejects dependency/alternate-file owners. No edit required.
- [x] PacketBuffer/Socket/global helper docs were not edited; no callback verification drift required touching them.
- [x] No manual edits were made to generated files, project-level generated reports, manual `-coverage-report.md` files, validator state, queue/lock files, lifecycle/archive files, executed-report records, supervisor ledgers, IDA database files, or report history footer. Validator-managed projected stats/generated-refresh side effects from scoped command `000000006901` are recorded above.
- [x] Ran the scoped validator only for the changed by-* file and recorded command metadata: `000000006901`, `2026-07-05T08:25:10-04:00`, exit `0`, `ok: 1`, no warnings, generated refresh deferred.
- [x] Did not run `execute_report`, dry-run/probing execute variants, registry/lifecycle/archive commands, manual report moves, or manual coverage edits.
- [x] Updated this ledger and checklist with `applied`, `already-present`, and `excluded-with-reason` states for every accepted claim.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003VT","source_path":"executed-b-agent-research/B009/0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B009","command_id":"000000006891","destination_path":"tools/leaser/Agents/Agent-B009/research/0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B009/0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality.md","timestamp":"2026-07-05T08:09:57-04:00"} -->
<!-- {"agent":"B009","command_id":"000000006903","destination_path":"executed-b-agent-research/B009/0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality.md","timestamp":"2026-07-05T08:29:41-04:00","uid":"0003VT"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0003VT-SpellFourArgsDirectArgumentPacketRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003VT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
