** TARGET-REPORT-UID:0003VU **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003VU SpellThreeArgsDirectArgumentPacketRaw Source-Quality Report

## Finalized Report / Current Recommendation

Current recommendation: keep [UID:0003VU] `by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md` as a reviewed no-owner, non-emitting, non-reconstructable raw code island. It is a source-shaped direct three-argument spell packet body, but the current IDA MCP and documentation evidence still prove no static route to the bytes.

Current disposition: `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`.

Post-callback implementation state: the target and support docs were updated or verified after Gate 1. The target metadata remains `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter fields, and blank formal C++. The 2026-07-05 B010 MCP refresh was incorporated into the target and touched support docs, the target's old side-section/body-only future C++ sketch was removed, and the support docs were synchronized without adding a standalone method body, sample body, comment-only marker, or class declaration member for [UID:0003VU].

Confidence remains strong for bytes, boundaries, packet layout, field access, helper/global roles, and negative static route evidence. Confidence stays below near-final because original source retention reason, original helper spelling, exact field spelling, argument semantic names, and dynamic/runtime route status remain unproven.

## Supporting Research

Historical lifecycle context: the previously executed B010 report was marked for revalidation because the validator could not resolve `target_uid_unknown: 0003VU`. Validator command `000000006897` returned the report from `executed-b-agent-research/B010/0003VU-SpellThreeArgsDirectArgumentPacketRaw-source-quality.md` to this active research path at `2026-07-05T08:17:50-04:00`. Those facts remain only as historical lifecycle context here and in the validator-owned footer.

Status-header repair: this active research copy previously carried top-level `REPORT-VALIDATION-STATUS: needs-revalidation` and `REPORT-REVALIDATION-REASON: target_uid_unknown: 0003VU` lines. Under the active repair assignment, those top-level status lines were removed. The validator-owned `VALIDATOR-REPORT-HISTORY` footer is preserved unchanged.

Supervisor scoped target validator command already repaired the target metadata before this report repair: `000000006899`, command `python .\tools\validator.py --mode file --file by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md --apply --queue-timeout 240`, timestamp `2026-07-05T08:18:18-04:00`, exit `0`, `ok: 1`. Reported effects were `path_update`, completion `88`, confidence `89`, canonical owner `NONE`, blank formal C++ header insertion, autogen registry/reference-index updates, projected stats update, and `generated_refresh: deferred`.

Current MCP evidence is no longer unavailable. B010 rechecked the active IDA MCP session `supervisor_recovery_20260705` during this repair. `idb_list` reported one active adopted worker session for `NexusTK.exe.i64`; `server_health` reported status `ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. The current MCP facts are recorded under `Evidence Checked`, `Positive Evidence Summary`, `Negative Evidence Summary`, and the ledger.

Older PE/Capstone whole-image scans from the original report remain useful supporting evidence: they found no entry/interior absolute VA, RVA, file-offset dword, rel32 branch/call, or decoded operand route to `0x005b0d00-0x005b0d9a`, while live sibling submit handlers had vtable pointer controls. The current MCP pass corroborates the core negative route result through IDA xrefs, exact byte-pattern searches, function lookup, bytes, and instruction decoding.

## Target

- Target UID: [UID:0003VU]
- Target path: `source-3/project-documentation/by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md`
- Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/0003VU-SpellThreeArgsDirectArgumentPacketRaw-source-quality.md`
- Current classification: no-route raw code island, non-emitting, not reconstructable.
- Current metadata: `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Containing/index context: [UID:0001LN] `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`.
- Related live handler: [UID:0001LQ] `by-memory/0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md`.
- Related class/file context: [UID:0000DV] `by-class/SpellThreeArgsInputPane.md`, [UID:0000O0] `by-file/SpellInputPanes.md`.

## Current Target State

The target page already has the correct current metadata after supervisor validator command `000000006899`: `88/89`, no owner, non-reconstructable, blank emitters, and blank formal C++.

The target page already documents the useful 2026-06-19 B010 source-quality facts: exact `0x9a` / 154-byte body, stack-cookie frame, opcode `0x0f`, stored `this+0x108` byte as best current `m_spellIndex`, three signed 16-bit stack arguments, an unsent terminator at local packet offset `+8`, `g_packetSender` / `QueueAndSendPacket` length-8 handoff, route-negative whole-image PE scans, rejected owners, and best conditional future SpellInputPanes context.

Current post-callback target state: the target page now contains the 2026-07-05 MCP refresh with `supervisor_recovery_20260705`, and the stale side-section "future route-proven" C++ body outside the formal target C++ block has been removed. Current B-agent rules reject body-only/sample/report-only C++ when formal C++ remains blank; the target now keeps the packet-layout and helper-role facts as prose-only evidence.

Current post-callback support state: [UID:0001LQ], [UID:0001LN], [UID:0000DV], and [UID:0000O0] were verified at same-or-greater factual detail and synchronized with current MCP refresh wording where touched. They preserve [UID:0003VU] as an ownerless/non-emitting no-route raw sibling, keep SpellInputPanes only as conditional future source context, reject PacketBuffer, Socket/ProtocolSend, SpellInventoryPane, CommandInputPanes, target-selection files, and standalone packet helper ownership, and make no score, owner, source-route, declaration, or formal C++ changes.

Current active report artifact status: post-callback repaired active research copy, ready for Gate 1 after this report-text repair. No by-* docs were edited in this report-text repair pass.

## Heuristic / Inference Reanalysis And Validation

Raw helper status and boundary:

- Direct MCP fact: `lookup_funcs` reports `0x005b0d00` and `0x005b0d9a` are not IDA functions.
- Direct MCP fact: successor `0x005b0da0` is modeled as `sub_5B0DA0`, size `0x8d`; preceding live handler `0x005b0be0` is modeled as `sub_5B0BE0`, size `0x11d`, ending exactly before the three-byte padding.
- Direct MCP fact: `get_bytes` confirms `0x005b0cfd-0x005b0d00` is `cc cc cc`, the body at `0x005b0d00` is 154 bytes, and `0x005b0d9a-0x005b0da0` is `cc cc cc cc cc cc`.
- Inference: this is not padding and not a compiler thunk. It is a retained source-shaped packet body, but it remains a no-route raw island because no caller/table route is proven.
- Rejected merge alternatives: do not merge into [UID:0001LQ], because a padding gap and fresh prologue separate the bodies; do not extend into [UID:0001LR], because six `0xcc` bytes precede the successor constructor.

Packet layout and helper roles:

- Direct MCP instruction facts: the body uses a stack-cookie frame, saves `ecx` as `this`, builds a local packet buffer at `[ebp-0x130]`, writes opcode `0x0f`, writes `byte ptr [esi+0x108]`, writes three `word ptr [ebp+...]` arguments through `sub_5753A0`, loads `dword_67A7EC`, writes a zero byte at `[ebp-0x128]`, calls `sub_574BB0` with pushed length `8`, and returns with `retn 0Ch`.
- Documentation evidence: current PacketBuffer and QueueAndSendPacket docs give the best source-facing helper/global names `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `g_packetSender`, and `QueueAndSendPacket`.
- Best protocol description: sent bytes are `[0x0f, m_spellIndex, arg0_hi, arg0_lo, arg1_hi, arg1_lo, arg2_hi, arg2_lo]`.
- The local zero at packet offset `+8` is not sent because the send length is `8`.
- Rejected packet alternative: do not describe a ninth protocol byte.

Field and argument inference:

- Documentation evidence: the constructor writes the original spell byte to `this+0x108`, and the live handler serializes the same byte as packet byte `+1`.
- Best source-facing field name: `m_spellIndex`, explicitly descriptive/inferred rather than recovered header spelling.
- Lower-confidence alternates such as `m_spellId` or `m_spellSlot` remain weaker because current evidence proves a stored spell-index byte, not a full source type or UI-slot semantic.
- Best argument language: three explicit signed 16-bit arguments. The body uses `movsx word ptr [ebp+8]`, `[ebp+0xc]`, and `[ebp+0x10]`; no caller exists to prove semantic names such as target coordinates, map id, item slot, or creature id.

Caller/reachability:

- Direct MCP fact: `xref_query` to `0x005b0d00`, direction `to`, any xref type, returns total `0`.
- Direct MCP fact: exact byte searches find zero matches for absolute VA pointer bytes `00 0d 5b 00`, RVA bytes `00 0d 1b 00`, and file-offset bytes `00 01 1b 00`.
- Direct MCP positive control: `xref_query` to the live handler `0x005b0be0` finds one data xref from `0x0062f514`, and exact bytes `e0 0b 5b 00` also match at `0x0062f514`.
- Supporting PE/Capstone fact from the original report: no entry/interior absolute VA, RVA, file-offset dword, rel32 call/jump, or decoded operand route was found to `0x005b0d00-0x005b0d9a`.
- Conclusion: static liveness remains negative. A dynamic/runtime or manually computed route is possible in theory, but no current static evidence supports source emission or owner promotion.

Relationship to [UID:0001LQ]:

- [UID:0001LQ] is a live virtual submit handler with vtable data xref at `0x0062f514`.
- [UID:0001LQ] parses text, requires comma separators, converts three substrings, and sends the same opcode `0x0f` layout with an 8-byte payload.
- [UID:0003VU] builds the same packet from three explicit stack arguments and has no line-input parsing path.
- Inference: [UID:0003VU] is best described as a direct-argument sibling/alternate packet sender-shaped body for the same class family, not as a callee or tail of [UID:0001LQ].

Source placement:

- Best future source family if route evidence appears: `SpellThreeArgsInputPane` inside [UID:0000O0] `SpellInputPanes`.
- Evidence for that future route: reads `this+0x108`, mirrors [UID:0001LQ] packet layout, sits in the numeric spell input pane family, and uses the same spell argument packet pattern.
- Evidence against promoting now: no function object, no xref, no pointer bytes, no generated output marker, and no proven caller/table route.
- Rejected current owners: PacketBuffer, Socket/ProtocolSend, SpellInventoryPane, CommandInputPanes, TargetSelectionInputPanes, NumberArgsInputPane, standalone `SpellPacketHelpers.cpp`, padding, compiler thunk, and runtime helper.

Generated-output pollution:

- Read-only search found no [UID:0003VU] marker in `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`.
- Current generated coverage/tracker files already list [UID:0003VU] as `not_reconstructable` / `false`, `88/89`, with no emitter route. These are read-only evidence in this report; B010 did not edit generated files.
- Old labels such as `FUN_005b0d00`, `sub_5B0D00`, or the descriptive documentation filename are analysis labels, not final source names.

Final C++ readiness:

- [UID:0003VU] fails the current C++ entry gate because it is `RECONSTRUCTABLE:FALSE`, has no owner, has blank emitters, and has no proven source route.
- Formal C++ must remain blank.
- The old report-only/body-only future sketch is rejected as a report artifact. Preserve the packet layout and candidate naming direction in prose only, not as a C++ block or comment marker.

## Evidence Standards Used

Direct IDA MCP evidence is the primary authority for current function status, exact bytes, padding, xrefs, pointer-byte searches, instruction decoding, and live-handler positive controls.

Existing by-* docs are evidence for project-local source-facing names, ownership policy, support relationships, and prior accepted implementation details. Generated reports and generated C++ are leads only; they are not authority for ownership or liveness.

Negative evidence was treated as meaningful only when paired with positive controls. Here, the live handler has an IDA data xref and pointer-byte match at `0x0062f514`, while [UID:0003VU] lacks corresponding xrefs and pointer hits.

The evidence is strong enough for `88/89` and a stable non-emitting disposition. It is not strong enough for `95+`, owner assignment, emitter assignment, or formal C++ because no caller, vtable slot, source symbol, original declaration, or runtime route proves source liveness.

## Evidence Checked

IDA MCP checks performed during this repair:

- Safe MCP flow: `initialize` succeeded; `tools/list` succeeded and exposed schema-current `idb_list`, `server_health`, `lookup_funcs`, `xref_query`, `find_bytes`, `get_bytes`, and `insn_query`.
- `idb_list`: one active adopted worker session, `supervisor_recovery_20260705`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, PID/worker PID `19604`, not analyzing.
- `server_health(database=supervisor_recovery_20260705)`: status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs` for `0x005b0d00`, `0x005b0d9a`, `0x005b0da0`, and `0x005b0be0`: target start/end are not functions; successor `0x005b0da0` is `sub_5B0DA0` size `0x8d`; live handler `0x005b0be0` is `sub_5B0BE0` size `0x11d`.
- `xref_query` to `0x005b0d00`: total `0`, no cross-references.
- `xref_query` to `0x005b0be0`: total `1`, data xref from `0x0062f514`, the live handler positive control.
- `find_bytes`: zero matches for `00 0d 5b 00`, `00 0d 1b 00`, and `00 01 1b 00`; one positive-control match for `e0 0b 5b 00` at `0x0062f514`.
- `get_bytes`: `0x005b0cfd` size `3` is `0xcc 0xcc 0xcc`; `0x005b0d00` size `154` returns the exact raw body; `0x005b0d9a` size `6` is `0xcc` repeated six times.
- `insn_query` scoped to `0x005b0d00-0x005b0d9a`, count `80`, `max_scan_insns=80`, include disassembly/function metadata: decoded 46 instructions, `fn:null` for all, not truncated.

Documentation/support evidence checked:

- Target [UID:0003VU].
- [UID:0001LQ] `SpellThreeArgsInputPaneConfirmInput`.
- [UID:0001LP] `SpellThreeArgsInputPaneConstructor`.
- [UID:0001LN] `SpellArgumentInputPanes`.
- [UID:0000DV] `SpellThreeArgsInputPane`.
- [UID:0000O0] `SpellInputPanes`.
- Packet/send support docs [UID:0003YJ], [UID:0000V1], [UID:0001HU], and [UID:0000Q5].
- Sibling raw helper reports/docs for [UID:0003VT], [UID:0003VV], [UID:0003VW], and [UID:0003VX] as context only.
- `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` for [UID:0003VU] absence.
- `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md` for read-only generated state after command `000000006899`.

Search terms used: `0003VU`, `0x005b0d00`, `SpellThreeArgsDirectArgumentPacketRaw`, `SendDirectArgumentPacket`, `direct-argument`, `m_spellIndex`, `PacketBufferWriteUInt16BE`, `SpellInputPanes`, and sibling raw helper UIDs `0003VT`/`0003VV`/`0003VW`/`0003VX`.

Checks intentionally not performed: no runtime tracing, no IDA database mutation, no broad unbounded callgraph/type/search calls, no validators run by B010 in this report-only repair, and no generated/coverage/validator-state edits.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| VU-001 | Historical `needs-revalidation` / `target_uid_unknown: 0003VU` is not current status for this active repair artifact. | High | Validator footer; command `000000006897`; active assignment. | This report `Supporting Research`; top-level status lines removed. | historicalize | applied |
| VU-002 | Target metadata is currently `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank formal C++. | High | Target header; validator command `000000006899`. | Target header; this report `Target`, `Current Target State`, `Score And Metadata Recommendation`. | already-present | already-present |
| VU-003 | Active MCP session `supervisor_recovery_20260705` is healthy and current evidence is mandatory/satisfied. | High | `idb_list`, `server_health`. | This report `Supporting Research`, `Evidence Checked`, `Validator Results`; target/support callback note. | incorporate | applied |
| VU-004 | `0x005b0d00` and `0x005b0d9a` are not IDA functions; successor `0x005b0da0` and live handler `0x005b0be0` are modeled functions. | High | MCP `lookup_funcs`. | Target `Evidence`/changes; support docs `Neighbor And Generated-Output Omissions`, `Index Scope`, `Evidence Notes`, and `Placement Notes`. | incorporate | applied |
| VU-005 | `0x005b0d00` has zero inbound xrefs; live handler `0x005b0be0` has positive-control vtable/data xref at `0x0062f514`. | High | MCP `xref_query`. | Target `Evidence`; support docs `Neighbor And Generated-Output Omissions`, `Index Scope`, `Evidence Notes`, and `Placement Notes`. | incorporate | applied |
| VU-006 | Exact pointer-byte searches remain negative for target VA/RVA/file-offset patterns and positive for live-handler bytes at `0x0062f514`. | High | MCP `find_bytes` for `00 0d 5b 00`, `00 0d 1b 00`, `00 01 1b 00`, `e0 0b 5b 00`. | Target `Evidence`; support docs `Neighbor And Generated-Output Omissions`, `Index Scope`, `Evidence Notes`, and `Placement Notes`. | incorporate | applied |
| VU-007 | Padding and target bytes are exact: three `0xcc` before, 154-byte body, six `0xcc` after. | High | MCP `get_bytes`; current target doc. | Target `Evidence` and `No-Code Proof`; support aggregate `Index Scope`. | incorporate | applied |
| VU-008 | Body builds opcode `0x0f` packet from stored `this+0x108` and three signed 16-bit stack arguments, writes unsent terminator, sends length `8`. | High | MCP `insn_query`; current target/support docs. | Target `Behavior`/`Packet Helper And Field Names`; support docs already present. | already-present | already-present |
| VU-009 | Best field name remains descriptive `m_spellIndex`; semantic argument names are unproven, so keep generic three signed 16-bit argument language. | Medium-high | Constructor/live handler docs; MCP instruction access to `[esi+108h]` and stack words. | Target/support docs; this report `Heuristic`. | already-present | already-present |
| VU-010 | Best future source context if a route appears is `SpellThreeArgsInputPane` under `SpellInputPanes`, but current owner/emitter must remain blank. | High | Field access, sibling family, support docs, negative route proof. | Target `Assignment Rationale`; class/file support docs; this report `Source Placement`. | already-present | already-present |
| VU-011 | Reject PacketBuffer, Socket/ProtocolSend, SpellInventoryPane, CommandInputPanes, TargetSelectionInputPanes, NumberArgsInputPane, standalone packet-helper file, compiler thunk, padding, and merge/tail alternatives. | High | Support docs; call/field evidence; route-negative evidence. | Target/support docs; this report `Ranked Ownership Analysis`, `Negative Evidence Summary`. | already-present | already-present |
| VU-012 | Formal target C++ must remain blank; the old side-section/body-only future C++ sketch is stale under current rules. | High | Current by-structure C++ rule; target formal blank; no-route proof. | Target `No-Code Proof`; this report `First-Draft C++ Recommendation`. | reject-stale | applied |
| VU-013 | Current generated output/tracker state does not emit [UID:0003VU] and already shows `88/89` non-reconstructable/no-emitter state. | High | Read-only `auto-generated` grep; command `000000006899` effects. | This report `Generated-output pollution`, `Validator Results`; no manual generated edit. | not-applicable | excluded-with-reason: generated/tracker edits are forbidden and unnecessary |
| VU-014 | B010 must not edit forbidden generated/coverage/validator-state/queue/lifecycle/supervisor-ledger files or run execute/lifecycle commands; callback by-* edits must be leased and validated. | High | Current callback actions and validator outputs `000000006910`-`000000006914`. | This report `Changed Files`, `Validator Results`, `Implementation Tracking Checklist`. | not-applicable | applied |

## Positive Evidence Summary

- The raw body is real code-shaped executable content, not padding: fresh prologue, stack allocation, security cookie setup/check, helper calls, and `retn 0Ch`.
- Exact boundary evidence is strong: three `0xcc` bytes before and six `0xcc` bytes after the 154-byte body.
- The packet layout is directly supported by current MCP instruction decoding: opcode `0x0f`, stored spell byte from `this+0x108`, three signed 16-bit stack arguments, local terminator at `+8`, and send length `8`.
- The live handler [UID:0001LQ] sends the same opcode/argument-family packet after text parsing, making [UID:0003VU] a direct-argument sibling-shaped body.
- Support docs already preserve the conditional future context: if a route appears, SpellInputPanes and SpellThreeArgsInputPane are the best source family.

## Negative Evidence Summary

- IDA does not model a function at `0x005b0d00` or `0x005b0d9a`.
- Current MCP xref query returns zero inbound xrefs to `0x005b0d00`.
- Current MCP exact byte searches return zero target VA/RVA/file-offset pointer pattern matches.
- Older PE/Capstone whole-image scans found zero entry/interior rel32 branch/call targets and zero decoded executable-section operand routes.
- `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` contains no [UID:0003VU] marker.
- Utility callees do not transfer ownership to PacketBuffer, Socket, or transport modules.
- Adjacency does not prove ownership/emission because sibling live submit handlers have vtable routes while this raw island does not.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b0be0-0x005b0cfd` | [UID:0001LQ] `SpellThreeArgsInputPaneConfirmInput` | live virtual text-parse submit handler | TRUE | [UID:0000DV] | `86/89` | emits through class/file route |
| `0x005b0cfd-0x005b0d00` | [UID:0000VN] ignored padding | three `0xcc` bytes | FALSE | ignored | not applicable | boundary proof |
| `0x005b0d00-0x005b0d9a` | [UID:0003VU] target | no-route direct three-argument opcode `0x0f` packet body | FALSE | NONE | `88/89` | non-emitting, blank formal C++ |
| `0x005b0d9a-0x005b0da0` | [UID:0000VN] ignored padding | six `0xcc` bytes | FALSE | ignored | not applicable | boundary proof |
| `0x005b0da0-0x005b0e2d` | [UID:0001LR] `SpellTwoArgsInputPaneConstructor` | next modeled constructor | TRUE | [UID:0000DW] | unchanged | successor boundary |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005b0d00` | MCP `xref_query` total `0` | no IDA inbound route to target entry |
| `00 0d 5b 00` | MCP `find_bytes` `n=0` | no exact absolute VA pointer-byte match |
| `00 0d 1b 00` | MCP `find_bytes` `n=0` | no exact RVA pointer-byte match |
| `00 01 1b 00` | MCP `find_bytes` `n=0` | no exact file-offset pointer-byte match |
| `0x005b0be0` | data xref from `0x0062f514` | positive-control vtable/data route for live handler |
| `e0 0b 5b 00` | MCP `find_bytes` match `0x62f514` | positive-control pointer bytes for live handler |

## Ranked Ownership Analysis

### 1. SpellThreeArgsInputPane through SpellInputPanes

Evidence for: the body reads `this+0x108`, uses the same opcode `0x0f` and packet layout as [UID:0001LQ], and sits in the numeric spell input pane family. Current class/file docs already identify this as the best conditional future source context.

Evidence against: no IDA function object, no xrefs, no pointer-byte hits, no generated output marker, no vtable slot, and no caller/table route.

Decision: keep as best future route if reachability is proven, but do not set owner/emitter now.

### 2. SpellInputPanes file-local helper

Evidence for: source family and packet helper style fit the file.

Evidence against: the body reads class instance state and no file-local route exists.

Decision: possible only behind the class/source-family route after new liveness proof; not a current owner.

### 3. PacketBuffer, Socket, ProtocolSend, or g_packetSender

Evidence for: the body calls packet serialization and queue/send helpers.

Evidence against: utility helpers and transport globals do not own feature packet construction; the opcode and `this+0x108` field are spell UI state.

Decision: reject.

### 4. SpellInventoryPane

Evidence for: spell inventory code constructs/dispatches spell prompt panes.

Evidence against: prompt methods and packet submit behavior belong to the prompt family; this body reads a `SpellThreeArgsInputPane` state byte, not inventory pane state.

Decision: reject as direct owner; retain only as reachability/context support.

### 5. CommandInputPanes, TargetSelectionInputPanes, NumberArgsInputPane, or standalone packet-helper file

Evidence for: nearby input families and shared base classes exist.

Evidence against: class state, opcode family, and current docs point to SpellInputPanes; no independent caller or neutral helper route exists.

Decision: reject.

## Source Placement

Recommended current placement: no source emission and no canonical owner. The durable by-memory target remains the canonical home for this raw island's evidence.

Conditional future placement if liveness is proven: [UID:0000DV] `SpellThreeArgsInputPane` in [UID:0000O0] `SpellInputPanes` / `NexusTK/ui/dialogs/SpellInputPanes.cpp`.

Rejected placements: PacketBuffer, Socket/ProtocolSend, SpellInventoryPane, CommandInputPanes, TargetSelectionInputPanes, NumberArgsInputPane, standalone packet-helper file, compiler thunk/padding, and merging into the live handler.

Remaining placement uncertainty: runtime/dynamic liveness is not proven or disproven by this static report. That uncertainty is why the target stays non-emitting rather than being promoted.

## Range / Split / Padding / Reclassification Analysis

No split or range change is recommended. Current exact range remains `0x005b0d00-0x005b0d9a`.

Boundary proof:

- `0x005b0cfd-0x005b0d00`: three `0xcc` bytes.
- `0x005b0d00-0x005b0d9a`: 154-byte packet body ending with `retn 0Ch` at `0x005b0d97`.
- `0x005b0d9a-0x005b0da0`: six `0xcc` bytes before successor `sub_5B0DA0`.

Reclassification: keep `RECONSTRUCTABLE:FALSE`. The body is source-shaped, but source-shaped bytes without liveness are not enough to emit or attach ownership for this exact target.

## First-Draft C++ Recommendation

Eligible for draft C++: no.

Recommended formal C++ insertion text: keep the target's formal C++ blank.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No standalone body, sample body, report-only C++ block, illustrative sketch, or comment-only marker should be inserted for [UID:0003VU]. The old "future route-proven" body-only sketch is rejected as stale under the current formal-C++ rule. Its useful facts should remain prose: local packet buffer, opcode `0x0f`, stored spell index byte, three signed 16-bit arguments, unsent terminator, and length-8 send.

Exact no-code proof:

1. Target is `RECONSTRUCTABLE:FALSE`.
2. `CANONICAL_OWNER` is `NONE`.
3. `EMITTER_UIDS` is blank.
4. IDA MCP does not model a function at `0x005b0d00`.
5. IDA MCP reports zero inbound xrefs to `0x005b0d00`.
6. IDA MCP exact pointer-byte searches for VA/RVA/file-offset patterns are negative.
7. Supporting PE/Capstone scans found no rel32 branch/call or decoded operand route.
8. Positive-control live handler has a vtable/data pointer route while this target does not.
9. Generated output does not emit or reference this raw island.
10. Emitting a method now would add source behavior with no proven caller and would mislead final generated output.

## Final Recommendation

Keep [UID:0003VU] no-owner, non-reconstructable, non-emitting, and formal-C++ blank.

Do not change scores or metadata beyond the already-applied `88/89` state from command `000000006899`.

Implementation callback state: documentation cleanup was applied and verified. The target/support docs now include current MCP refresh wording, and the target's stale body-only future C++ sketch was removed/converted to prose-only facts. Packet behavior, helper/global names, negative route evidence, best conditional SpellInputPanes source context, and rejected alternatives were preserved.

Do not run report execution, lifecycle/archive commands, generated edits, coverage-report edits, validator-state edits, queue/lock edits, or manual report moves from this B-agent pass.

## Recommended Target Doc Changes

Target path: `by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md`.

Metadata/score changes: none beyond current already-present state. Preserve:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Post-callback target verification:

- Applied: added a 2026-07-05 B010 MCP refresh note using session `supervisor_recovery_20260705`: `server_health` OK; `lookup_funcs` not-function at `0x005b0d00` and `0x005b0d9a`; successor `sub_5B0DA0` size `0x8d`; live handler `sub_5B0BE0` size `0x11d`; zero xrefs to `0x005b0d00`; zero target VA/RVA/file-offset pointer-byte hits; live handler positive-control xref/pointer at `0x0062f514`; exact padding and instruction facts from `get_bytes`/`insn_query`.
- Applied: removed the side-section/body-only future C++ sketch and kept only prose packet evidence. The formal C++ block remains blank; no comment-only marker was added.
- Already present/preserved: exact `0x9a` body, stack-cookie frame, local packet buffer at `[ebp-0x130]`, `m_spellIndex` / `this+0x108`, three signed 16-bit stack arguments, unsent terminator at `+8`, send length `8`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `g_packetSender`, and `QueueAndSendPacket`.
- Already present/preserved: rejected alternatives and conditional future source context.
- Validator: scoped target validator `000000006910`, timestamp `2026-07-05T08:36:27-04:00`, exit `0`, `ok: 1`.

## Recommended Support Doc Changes

Post-callback support verification:

- `by-memory/0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md`: verified same-or-greater relationship detail for [UID:0003VU] as a non-emitting no-route sibling, not a callee or tail; added current 2026-07-05 MCP refresh wording. No score, owner, route, or formal C++ change. Validator `000000006911`, timestamp `2026-07-05T08:36:33-04:00`, exit `0`, `ok: 1`.
- `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`: verified [UID:0003VU] remains ownerless/non-emitting with negative B010 route scans; added current MCP refresh wording. No score, owner, route, or formal C++ change. Validator `000000006912`, timestamp `2026-07-05T08:36:46-04:00`, exit `0`, `ok: 1`; unrelated sibling [UID:0003VX] missing-ref warnings remained.
- `by-class/SpellThreeArgsInputPane.md`: verified the raw body remains a retained no-route related body, not a proven class method or emitter, and preserves `m_spellIndex`; added current MCP refresh wording. No score, declaration, owner, source-route, or formal class block change. Validator `000000006913`, timestamp `2026-07-05T08:36:57-04:00`, exit `0`, `ok: 1`.
- `by-file/SpellInputPanes.md`: verified SpellInputPanes remains conditional future context and alternate owners remain rejected; added current MCP refresh wording. No score, owner, source-route, or formal C++ change. Validator `000000006914`, timestamp `2026-07-05T08:37:07-04:00`, exit `0`, `ok: 1`; unrelated sibling [UID:0003VX] missing-ref warnings remained.
- PacketBuffer, QueueAndSendPacket, and `g_packetSender` docs were not touched because existing helper/global ownership separation already supplied the needed context and the implementation callback did not expand scope to those utility/global docs.
- `by-memory/-coverage-report.md`, generated reports, tracker files, validator state, queue/lock files, lifecycle/archive files, supervisor ledgers, and manual report moves were not edited.

## Score And Metadata Recommendation

Current score/metadata:

- `COMPLETION:88`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- `EMITTER_POSITION_OPTIONAL:` blank
- Formal C++ blank

Post-callback score/metadata disposition: unchanged from the current applied state.

Rationale for `88`: the target documents exact range, boundary proof, body behavior, packet layout, helper/global names, field role, signed stack arguments, relationship to live handler, owner/source-placement ranking, rejected alternatives, negative route evidence, and no-code proof.

Rationale for `89`: current MCP verifies core function/xref/byte/instruction facts and corroborates older PE/Capstone scans. Confidence stays below near-final because original source spelling, helper declaration policy, retention reason, argument semantics, and dynamic/runtime route remain unproven.

Do not promote to reconstructable or assign owner/emitter without new route evidence. Do not downgrade score: current evidence is strong and current target docs already incorporate the core behavior and negative route proof.

## Open Questions With Attempted Resolution

| Question | Attempted resolution and current disposition |
| --- | --- |
| Is `0x005b0d00` an IDA function now? | No. Current MCP `lookup_funcs` reports "Not a function" for `0x005b0d00` and `0x005b0d9a`. |
| Is there a static xref or pointer route? | No. Current MCP reports zero xrefs to `0x005b0d00`, zero target VA/RVA/file-offset pointer-byte matches, and a positive-control live handler pointer at `0x0062f514`. Older whole-image scans also found no rel32/operand route. |
| Is the body padding or a thunk? | No. MCP bytes/instructions show a real stack-cookie packet body, not padding or a jump/adjustor thunk. |
| Should the body be assigned to SpellThreeArgsInputPane now? | No. SpellThreeArgsInputPane is the best conditional future source context, but no liveness route proves ownership/emission now. |
| Should formal C++ be populated? | No. The target is non-reconstructable, ownerless, no-emitter, no-route, and absent from generated output. |
| What evidence could change the decision? | A recovered caller, vtable slot, pointer table, runtime trace, or equivalent route to `0x005b0d00` could reopen owner/emitter and C++ readiness. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable for this active repair. B010 must not edit `by-memory/-coverage-report.md`, generated reports, tracker files, or validator state.

The old report's exact manual coverage row is now historical/superseded for this repair path. Validator command `000000006899` already updated target metadata, and current read-only generated reports show [UID:0003VU] as `88/89`, `not_reconstructable`, no owner/emitter route. Any further generated coverage/tracker freshness is supervisor/validator-owned.

## Validator Results

B010 did not run validators during the report-only repair phase before Gate 1. During this implementation callback, B010 ran scoped validators for every edited by-* file from `source-3/project-documentation`.

Historical/active validator events incorporated:

- `000000004167`: report marked for revalidation with issue `target_uid_unknown: 0003VU`, timestamp `2026-07-01T19:52:03-04:00`; preserved only in the validator-owned footer and historicalized in `Supporting Research`.
- `000000006897`: report returned from executed archive to active B010 research path at `2026-07-05T08:17:50-04:00`; preserved in the footer and historicalized in `Supporting Research`.
- `000000006899`: supervisor scoped target validator command `python .\tools\validator.py --mode file --file by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md --apply --queue-timeout 240`, timestamp `2026-07-05T08:18:18-04:00`, exit `0`, `ok: 1`; effects included path update, completion `88`, confidence `89`, canonical owner `NONE`, blank formal C++ header insertion, autogen registry/reference index updates, projected stats update, and `generated_refresh: deferred`.

Implementation callback validators:

- `000000006910`: `python .\tools\validator.py --mode file --file by-memory\0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md --apply --queue-timeout 240`, timestamp `2026-07-05T08:36:27-04:00`, exit `0`, `ok: 1`. Side effects: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
- `000000006911`: `python .\tools\validator.py --mode file --file by-memory\0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md --apply --queue-timeout 240`, timestamp `2026-07-05T08:36:33-04:00`, exit `0`, `ok: 1`. Side effects: `uid_link_insert: 1` for [UID:0003VU], `reference_index_add: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
- `000000006912`: `python .\tools\validator.py --mode file --file by-memory\0x005b0780-0x005b14e6.SpellArgumentInputPanes.md --apply --queue-timeout 240`, timestamp `2026-07-05T08:36:46-04:00`, exit `0`, `ok: 1`. Warnings: ten pre-existing `missing_ref_uid` warnings for sibling [UID:0003VX]. Side effects: `uid_link_insert: 1` for [UID:0003VU], `reference_index_add: 4` for [UID:0003VT]/[UID:0003VU]/[UID:0003VV]/[UID:0003VW], `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
- `000000006913`: `python .\tools\validator.py --mode file --file by-class\SpellThreeArgsInputPane.md --apply --queue-timeout 240`, timestamp `2026-07-05T08:36:57-04:00`, exit `0`, `ok: 1`. Side effects: `uid_link_insert: 1` for [UID:0003VU], `reference_index_add: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.
- `000000006914`: `python .\tools\validator.py --mode file --file by-file\SpellInputPanes.md --apply --queue-timeout 240`, timestamp `2026-07-05T08:37:07-04:00`, exit `0`, `ok: 1`. Warnings: seven pre-existing `missing_ref_uid` warnings for sibling [UID:0003VX]. Side effects: `uid_link_insert: 1` for [UID:0003VU], `reference_index_add: 5` for [UID:0003AG]/[UID:0003VT]/[UID:0003VU]/[UID:0003VV]/[UID:0003VW], `projected_stats_update: 1`, `stats_incremental_noop: 1`, `generated_refresh: deferred`.

No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, registry command, manual report move, generated edit, coverage edit, validator-state edit, queue/lock edit, or supervisor-ledger edit was run by B010.

## Changed Files

- Modified by B010: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/0003VU-SpellThreeArgsDirectArgumentPacketRaw-source-quality.md`.
- Modified by B010: `source-3/project-documentation/by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md`.
- Modified by B010: `source-3/project-documentation/by-memory/0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md`.
- Modified by B010: `source-3/project-documentation/by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`.
- Modified by B010: `source-3/project-documentation/by-class/SpellThreeArgsInputPane.md`.
- Modified by B010: `source-3/project-documentation/by-file/SpellInputPanes.md`.
- Not manually modified by B010: generated files, project-level generated files, `-coverage-report.md` files, validator state, queue/lock files, supervisor ledgers, lifecycle/archive files, and manual report locations. Scoped validators reported projected stats/reference-index/generated-refresh side effects as listed above.
- Status-header repair: removed only the two top-level active-copy status/reason lines and historicalized their facts under `Supporting Research`.
- Validator-owned `VALIDATOR-REPORT-HISTORY` footer: preserved unchanged.
- Report execution: not run.
- Leases: B010 leased the five edited by-* docs immediately before editing and released all five immediately after scoped validation.

## Implementation Tracking Checklist

Report-only repair completed:

- [x] Read updated `Agent-B010/goal.md`.
- [x] Used project-level `ntk-b-agent-workflow` skill and B-agent workflow reference.
- [x] Read `by-structure.md` IDA MCP Output Discipline and used narrow/schema-current MCP calls.
- [x] Removed only the top-level active-copy `REPORT-VALIDATION-STATUS` and `REPORT-REVALIDATION-REASON` lines.
- [x] Preserved the validator-owned `VALIDATOR-REPORT-HISTORY` footer unchanged.
- [x] Historicalized command `000000006897` and `target_uid_unknown: 0003VU` under `Supporting Research`.
- [x] Incorporated supervisor scoped target validator command `000000006899`, timestamp, exit, `ok`, and side effects.
- [x] Replaced stale current-state wording: target metadata is current/applied `88/89`, not historical `85/86`.
- [x] Added current MCP evidence from session `supervisor_recovery_20260705`.
- [x] Removed report-only/body-only C++ recommendation and replaced it with strict formal-blank/no-code proof.
- [x] Normalized report to current required B-agent headings.
- [x] Did not edit target/support by-* docs during this report-only repair.
- [x] Did not edit generated files, project-level generated files, coverage reports, validator state, queue/lock files, supervisor ledgers, lifecycle/archive files, or manual report locations.
- [x] Did not run validators, `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, or manual report moves.

Implementation callback pass:

- [x] Target `by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md`: preserved metadata `88/89`, owner `NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank emitter position, and blank formal C++.
- [x] Target: added 2026-07-05 MCP refresh details from `supervisor_recovery_20260705` at report-level detail.
- [x] Target: removed the stale side-section/body-only future C++ sketch and replaced it with prose-only source-shape facts plus strict formal-blank/no-standalone-body/no comment-marker wording.
- [x] Target: preserved exact packet layout, helper/global names, boundary proof, negative route evidence, positive-control live handler comparison, source-placement ranking, and rejected alternatives.
- [x] Support docs `SpellThreeArgsInputPaneConfirmInput`, `SpellArgumentInputPanes`, `SpellThreeArgsInputPane`, and `SpellInputPanes`: verified same-or-greater behavior/source-placement detail and added current MCP refresh wording; no score or ownership churn.
- [x] Did not edit PacketBuffer, QueueAndSendPacket, or `g_packetSender` docs because current helper/global ownership detail was already sufficient and supervisor did not expand scope.
- [x] Did not edit generated files, manual coverage reports, validator state, queue/lock files, supervisor ledgers, lifecycle/archive files, or manual report moves.
- [x] Leased only the five edited by-* docs, ran scoped validators `000000006910` through `000000006914`, and released all five leases immediately after validation.
- [x] Updated this ledger/checklist with `applied`, `already-present`, and `excluded-with-reason` states claim by claim.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003VU","source_path":"executed-b-agent-research/B010/0003VU-SpellThreeArgsDirectArgumentPacketRaw-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B010","command_id":"000000006897","destination_path":"tools/leaser/Agents/Agent-B010/research/0003VU-SpellThreeArgsDirectArgumentPacketRaw-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B010/0003VU-SpellThreeArgsDirectArgumentPacketRaw-source-quality.md","timestamp":"2026-07-05T08:17:50-04:00"} -->
<!-- {"agent":"B010","command_id":"000000006918","destination_path":"executed-b-agent-research/B010/0003VU-SpellThreeArgsDirectArgumentPacketRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0003VU-SpellThreeArgsDirectArgumentPacketRaw-source-quality.md","timestamp":"2026-07-05T08:49:57-04:00","uid":"0003VU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
