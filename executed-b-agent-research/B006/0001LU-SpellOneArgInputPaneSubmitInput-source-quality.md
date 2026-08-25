** TARGET-REPORT-UID:0001LU **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0001LU SpellOneArgInputPaneSubmitInput Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0001LU] `by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md` as the source-bearing `SpellOneArgInputPane::OnSubmitInput()` virtual handler.
- Final disposition: implementation callback completed. `CANONICAL_OWNER:0000DR`, `EMITTER_UIDS:0000DR`, `RECONSTRUCTABLE:TRUE`, and the existing formal C++ block were preserved exactly; target score is now `88/90`.
- Required action: ready for supervisor Gate 2 / execute review. No support by-* docs required edits because callback-time verification found them already present at same-or-greater detail.
- Confidence: high for range, vtable/data route, parser behavior, packet layout, sender handoff, and adjacent raw-helper separation; capped below near-final by inferred original source names and by the unresolved no-route direct helper family.

## Supporting Research
- Lifecycle/status notes: this is the first B006 report for `TARGET-REPORT-UID:0001LU`. No earlier UID-specific B report was found.
- Current assignment source: `Agent-B006/goal.md`, new report-first source-quality assignment for [UID:0001LU], with `AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh`.
- Required old-report search terms were checked: `TARGET-REPORT-UID:0001LU`, `0001LU`, `0x005b1150`, `0x005b11f5`, `SpellOneArgInputPaneSubmitInput`, `SpellOneArgInputPane`, `SpellInputPanes`, `0000DX`, `0000O0`, `0003VW`, and `0x005b1200`.
- Exact `TARGET-REPORT-UID:0001LU` search result: no prior target report; the only hit was this active goal file before this report was created.
- Relevant prior executed reports:
  - B002 `0000O0-SpellInputPanes-empty-emitter-family-source-quality.md` added the accepted `SpellOneArgInputPane::OnSubmitInput()` C++ body and records validator `000000001440` for the one-arg submit body.
  - B012 `0003VW-SpellOneArgDirectArgumentPacketRaw-source-quality.md` rechecked the adjacent `0x005b1200-0x005b1278` raw island, kept it no-owner/non-emitting, and explicitly rejected merging it into [UID:0001LU].
  - B009/B010/B011/B013 raw-helper sibling reports were checked for source-shape and score comparison; only B012 is directly controlling for the one-argument raw helper.
  - B011/B004 active sibling reports mention [UID:0001LU] as packet-family corroboration only, not as authority for this target.
- Goal support UID mismatch: the goal labels `by-class/SpellOneArgInputPane.md` as [UID:0000DX], but the actual file header is [UID:0000DR]. [UID:0000DX] is `SpellWhoInputPane`. This report uses the actual path/header UID [UID:0000DR] for the direct owner and treats the goal label as stale.
- Implementation callback: supervisor Gate 1 passed at report SHA `A8E772C52D079D3BD6948CE612084EECA5B2780AF4078657400C60D55EE5C26A`; B006 applied the accepted target-only update on 2026-07-07 and ran only scoped target validators.

## Target
- Target UID: `0001LU`.
- Target path: `by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md`.
- Source queue/report row after scoped validation: `auto-generated/-ag-research-tracker.md`, row `88/90`, average `89.0`, reconstructable `true`, direct report count `0`.
- Current supervisor classification: implementation callback completed; ready for supervisor execute/Gate 2 review.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000DR`, `EMITTER_UIDS:0000DR`, `RECONSTRUCTABLE:TRUE`.

## Current Target State
- Current metadata after callback: `UID:0001LU`, `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter [UID:0000DR] `SpellOneArgInputPane`, reconstructable true. Historical pre-callback metadata was `86/89`.
- Existing owner/emitter/reconstructable state: direct class owner [UID:0000DR] routes through [UID:0000O0] `SpellInputPanes` and generated `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`.
- Existing C++/emitter state: formal C++ is already populated with `SpellOneArgInputPane::OnSubmitInput()`, including text-length guard, `CopyText(text, 255)`, `_wtol`, opcode `0x0f`, `m_spellIndex`, one `PacketBufferWriteUInt16BE`, local terminator `packet[4] = 0`, and `QueueAndSendPacket(g_packetSender, packet, 4)`.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims:
  - `m_spellIndex`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, and wrapper-style `QueueAndSendPacket` are accepted source-facing/descriptive names, not original-header proof.
  - The decompiler return type is `__int16`, but the source-facing class method is documented as virtual `void`; the return value is a void-handler artifact from callee returns.
  - The adjacent `0x005b1200-0x005b1278` raw island remains separate and no-route; it must not be used to change [UID:0001LU]'s body.
  - Historical A002 notes mention final C++ blockers, but B002 later populated the accepted formal body and current generated output emits it.
- Related target/support docs checked: target page, [UID:0000DR] `by-class/SpellOneArgInputPane.md`, [UID:0000O0] `by-file/SpellInputPanes.md`, [UID:0001LN] `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`, [UID:0003VW] raw helper, PacketBuffer scalar writers [UID:0003YJ], QueueAndSendPacket [UID:0001HU], `g_packetSender` [UID:0000Q5]/[UID:0001P0], and CRT `_wtol` [UID:0001O5].
- Current artifact/lifecycle status: this report remains in `tools/leaser/Agents/Agent-B006/research/` for supervisor verification. Target by-* implementation is complete; support by-* docs were checked and left unedited as already-present.

## Executive Recommendation
- Best direct owner: [UID:0000DR] `SpellOneArgInputPane`.
- Best source placement: [UID:0000O0] `SpellInputPanes`, projected generated path `NexusTK/ui/dialogs/SpellInputPanes.cpp`.
- Target action: completed. Target prose now contains current B006 MCP/session evidence, old-report search result, generated-output freshness, negative evidence, and score rationale; metadata changed only `COMPLETION:86` to `88` and `CONFIDENCE:89` to `90`.
- C++ action: preserve the existing formal C++ block exactly. Do not blank, rewrite, or convert to a body-only snippet.
- Support action: no default support edits recommended. [UID:0000DR], [UID:0000O0], [UID:0001LN], and [UID:0003VW] already contain the one-argument handler, raw-helper separation, and source-family context at same-or-greater detail.
- Remaining blocked assignment condition: only future recovered headers/source symbols or a proven route to `0x005b1200` could justify changing helper names, raw-helper liveness, or source helper factoring.

## Supervisor Active Recheck
- Triggering instruction: historical report-only trigger was a new xHigh B006 report for UID0001LU with mandatory live IDA MCP and no by-* implementation before Gate 1; current trigger is the Gate-1-passed implementation callback.
- Split repair requirement: no new split is required. The target range is exact and the adjacent raw helper already has its own page [UID:0003VW].
- Source-bearing child state: [UID:0001LU] is the source-bearing child; [UID:0003VW] remains a separate no-owner/non-emitting raw island unless a future route is proven.

## Inference Research Guidance Check
- `by-structure.md` and the B-agent workflow require live IDA/MCP as ground truth for function boundaries, xrefs, byte/padding checks, and decompiler evidence. The report separates IDA facts from existing documentation and generated-output corroboration.
- Existing documentation assumptions treated as uncertain and rechecked: target score sufficiency, vtable-only route versus code-call expectations, helper/source-facing names, local terminator semantics, adjacent raw helper separation, and generated-output freshness.
- IDA fact: `sub_5B1150` exists at `0x005b1150` with size `0xa5`; data pointer at `0x0062f62c` is the only direct xref to the handler; padding `0x005b11f5-0x005b1200` is eleven `0xcc` bytes.
- Documentation evidence: class/file/aggregate pages already identify the method as `SpellOneArgInputPane::OnSubmitInput()` routed through `SpellInputPanes`.
- Inference: names such as `m_spellIndex`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, and free-wrapper `QueueAndSendPacket` are accepted descriptive/source-facing names, supported by class constructor and packet-helper docs, but not original-header proof.
- Wave2/Wave3 artifacts: historical generated/simroot language and stale A002 notes were not used as authority. Current by-* docs, executed B reports, generated validator outputs, and live MCP control this recommendation.

## Heuristic / Inference Reanalysis And Validation
- Function boundary: live `lookup_funcs` validates `0x005b1150` size `0xa5`, so the modeled function ends at `0x005b11f5`. `0x005b11f5` is not a function.
- Padding/successor: live `get_bytes` reports eleven `0xcc` bytes at `0x005b11f5-0x005b1200`; `0x005b1200` and `0x005b1278` are not modeled functions; `0x005b1280` is a modeled successor function. This validates the existing split.
- Route/caller heuristic: no direct code caller is expected for this virtual method. Live `xrefs_to` finds exactly one data xref from `0x0062f62c`, and `find_bytes "50 11 5B 00"` finds the same pointer slot.
- Text-edit behavior: live decompile/disassembly shows `sub_4F2310` text-length check, return when length is not positive, `sub_4F2300` copy of up to `255` wide chars, and `unknown_libname_24` CRT wide decimal parse.
- Packet layout: live disassembly writes opcode `0x0f`, byte at `this+0x108`, one signed 16-bit value through `sub_5753A0`, local byte zero at packet `+4`, and sends explicit length `4`.
- Dependency names: PacketBuffer docs support `PacketBufferWriteUInt8` and `PacketBufferWriteUInt16BE`; QueueAndSendPacket and `g_packetSender` docs support the shared Socket-owned send funnel; CRT `_wtol` docs support runtime exclusion.
- Raw helper role: [UID:0003VW] remains a helper-shaped direct packet island and must stay separate because current and B012 evidence show no xrefs/pointer route and there is `0xcc` padding between it and [UID:0001LU].
- Generated-output pollution: current generated `SpellInputPanes.cpp` is used only as freshness/readiness evidence. It is not treated as stronger than live IDA for boundary/xref facts.
- Rejected alternatives:
  - Owner [UID:0000O0] as direct owner: rejected because the class virtual method has a concrete class owner; file remains route/placement.
  - PacketBuffer/Socket/g_packetSender ownership: rejected because these are dependencies, not feature owners.
  - CRT `_wtol` ownership by `SpellOneArgInputPane`: rejected by runtime helper doc and broad runtime identity.
  - Merge [UID:0003VW] into [UID:0001LU]: rejected by padding and no-route evidence.
  - Blank the C++ block: rejected because current behavior, source route, and generated emission are already above the C++ preservation threshold.
- Remaining unresolved issue: exact original source names for helper wrappers and `m_spellIndex` are not symbol-proven. This caps confidence and prevents a score above low 90s.

## Evidence Standards Used
- Evidence types used: IDA MCP `server_health`, `idb_list`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `callees`, `get_bytes`, `find`, `find_bytes`, and `make_signature_for_range`; current by-* target/support docs; executed B reports; generated validator outputs and tracker rows.
- Evidence strength: function boundary, body, callee set, data xref, padding, and packet layout are direct live IDA facts. Owner/source placement is a combined class/vtable/documentation inference. Helper names are descriptive but locally consistent.
- Evidence ladder: binary evidence controls exact bytes and routes; by-* docs and executed reports provide accepted source-family interpretation; generated files are freshness checks only.
- Tool limitations: `find` rejected one scoped immediate-query parameter set, but the disassembly directly covers the immediates and offsets, so no evidence gap remains for opcode/length/field layout.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `server_health`: status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, `auto_analysis_ready:true`, `hexrays_ready:true`.
  - `idb_list`: active session `supervisor-nexustk-20260707`, owned/adopted true, `is_analyzing:false`.
  - `lookup_funcs`: target, endpoints, adjacent raw helper, successor, packet helpers, queue/send helper, CRT wrapper.
  - `decompile`/`disasm`: target and supporting small helpers at `0x00575380`, `0x005753a0`, `0x00574bb0`, and `0x005cea43`.
  - `xrefs_to`, `xref_query`, `find`, and `find_bytes`: vtable/data pointer and no-route check for `0x005b1200`.
  - `get_bytes`: target body bytes, padding, raw-helper prologue, vtable slot, and sender global storage.
  - `make_signature_for_range`: unique signature for `0x005b1150-0x005b11f5`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target page, class/file/aggregate docs, [UID:0003VW], PacketBuffer/QueueAndSendPacket/g_packetSender/CRT docs, B002/B012/B009-B013 executed reports, `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-coverage-report-by-memory.md`.
- Negative checks performed: no UID-specific old report; no direct code caller to target; no xrefs/data-ref/VA pointer to raw helper `0x005b1200`; no function modeled at `0x005b11f5`, `0x005b1200`, or `0x005b1278`; no support-doc gap requiring default support edits.
- Failed, unavailable, or intentionally skipped checks and why: one MCP `find` call with unsupported scoped `start`/`end` parameters returned an invalid-params text response; it was replaced by direct disassembly and other xref/byte checks. Validators were intentionally not run during the initial report-only pass; callback validators are recorded in `Validator Results`.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | Target range remains exact at `0x005b1150-0x005b11f5`; no split/merge needed. | High | Live MCP `lookup_funcs`, `disasm`, `get_bytes`, unique range signature. | Target B006 refresh / Changes. | incorporate | applied |
| C002 | The only direct route to the handler is vtable/data pointer `0x0062f62c -> 0x005b1150`; absence of direct code callers is expected. | High | Live `xrefs_to`, `xref_query`, `find data_ref`, `find_bytes`. | Target B006 refresh / Changes. | incorporate | applied |
| C003 | The body gates on positive text length, copies up to `255` wide chars, and parses a decimal wide string through CRT `_wtol`. | High | Live `decompile`, `disasm`, CRT wrapper doc [UID:0001O5]. | Target B006 refresh. | incorporate | applied |
| C004 | Packet layout is opcode `0x0f`, `m_spellIndex` at `this+0x108`, one big-endian 16-bit argument at offset `+2`, local terminator at `+4`, send length `4`. | High | Live target `disasm`/`decompile`, PacketBuffer helper docs. | Target B006 refresh / Score Rationale. | incorporate | applied |
| C005 | `QueueAndSendPacket(g_packetSender, packet, 4)` is the correct current source-facing sender handoff, with Socket-owned dependency context. | High | Live `callees`, QueueAndSendPacket doc, `g_packetSender` docs. | Target B006 refresh / Submit Flow Notes. | incorporate | applied |
| C006 | Adjacent [UID:0003VW] must remain separate/non-emitting unless future route evidence appears. | High | Live padding/no-xref checks; B012 executed report; support docs. | Target B006 refresh / Adjacent Raw Helper Reanalysis / Changes. | incorporate | applied |
| C007 | Owner/emitter/reconstructable metadata should remain `0000DR`/`0000DR`/`TRUE`. | High | Class/file docs, vtable route, generated route. | Target metadata. | already-present | already-present |
| C008 | Existing formal C++ block should be preserved exactly. | High | Live behavior matches current formal block; generated `SpellInputPanes.cpp` emits same body. | Target `RECONSTRUCTION_CPP CODE`. | already-present | already-present |
| C009 | Raise target score from `86/89` to `88/90`. | Medium-high | Fresh B006 MCP, generated freshness, old-report synthesis; remaining original-name caps. | Target metadata and Score Rationale. | incorporate | applied |
| C010 | Support docs [UID:0000DR], [UID:0000O0], [UID:0001LN], and [UID:0003VW] are already present at same-or-greater detail. | High | Read-only inspection of each page. | Support docs. | already-present | already-present |
| C011 | Generated output refreshed and emits UID0001LU at `88/90` after callback. | High | Scoped validator command `000000007793`; generated `SpellInputPanes.cpp` and `-ag-*` headers refreshed `2026-07-07T02:22:55-04:00`. | Validator Results / Changed Files / final response. | incorporate | applied |
| C012 | No UID-specific old B report exists; B002 and B012 are relevant historical/source-family reports. | High | Required `rg` searches. | Supporting Research and target B006 refresh. | incorporate | applied |
| C013 | Goal support UID label `0000DX` is stale for `SpellOneArgInputPane.md`; actual UID is `0000DR`. | High | `SpellOneArgInputPane.md` header and `SpellWhoInputPane.md` search. | Target B006 refresh / Changes. | incorporate | applied |
| C014 | No manual supervisor-owned coverage/tracker text is needed; validator-owned generated reports were refreshed by scoped validator only. | High | Workflow rules and validator command `000000007793`. | Coverage/tracker section / Validator Results. | not-applicable | excluded-with-reason |
| C015 | Only scoped target validators were run; no support validators were needed because no support docs were edited. | High | Goal hard boundaries and validator outputs `000000007791`, `000000007793`. | Validator Results / checklist. | incorporate | applied |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation:
  - Live MCP validates a real modeled function at `0x005b1150` with exact size `0xa5`.
  - Live disassembly/decompilation matches the current formal C++ body.
  - A single vtable/data pointer at `0x0062f62c` supplies the virtual dispatch route.
  - Packet bytes and send length are direct instruction facts.
- Corroborating documentation/generated-report evidence:
  - [UID:0000DR] class doc declares `SpellOneArgInputPane`, `m_spellIndex`, and `OnSubmitInput`.
  - [UID:0000O0] file doc routes the spell prompt pane family to `SpellInputPanes.cpp`.
  - [UID:0001LN] aggregate and [UID:0003VW] raw helper docs already preserve the raw-helper split.
  - Current generated `SpellInputPanes.cpp` emits the same C++ body.
- Strongest inference chain: vtable slot plus class constructor/source family plus body behavior proves `SpellOneArgInputPane::OnSubmitInput()`; packet helper/global docs explain dependencies without moving ownership.

## IDA MCP Facts
- Function/range facts:
  - `lookup_funcs 0x005b1150` -> `sub_5B1150`, size `0xa5`.
  - `lookup_funcs 0x005b11f5` -> not a function.
  - `lookup_funcs 0x005b1200` -> not a function.
  - `lookup_funcs 0x005b1278` -> not a function.
  - `lookup_funcs 0x005b1280` -> `sub_5B1280`, size `0x8d`.
  - `make_signature_for_range 0x005b1150-0x005b11f5` reports a unique IDA-format signature.
- Data/table/padding facts:
  - `get_bytes 0x005b11f5 size 11` -> eleven `0xcc` bytes.
  - `get_bytes 0x0062f620 size 32` includes the little-endian pointer bytes `50 11 5B 00` at `0x0062f62c`.
  - `get_bytes 0x005b1200 size 32` begins with a function-shaped raw prologue but has no modeled function/xref route.
- Xref facts:
  - `xrefs_to 0x005b1150` -> one data xref from `0x0062f62c`.
  - `xrefs_to 0x005b1200` -> no cross-references.
  - `find data_ref 0x005b1150` -> `0x62f62c`; `find data_ref 0x005b1200` -> no matches.
  - `find_bytes "50 11 5B 00"` -> `0x62f62c`; `find_bytes "00 12 5B 00"` -> no matches.
- Vtable/global/type facts:
  - Target callees: `sub_4F2310`, `sub_4F2300`, `unknown_libname_24`, `sub_575380`, `sub_5753A0`, `sub_574BB0`, and security cookie check.
  - `sub_575380` writes one byte plus spare zero.
  - `sub_5753A0` writes high byte then low byte plus spare zero.
  - `sub_574BB0` queues/copies/sends via the shared sender object.
  - `unknown_libname_24` is Microsoft Visual C universal runtime wide integer parsing.
- Negative IDA facts:
  - No direct code callers to [UID:0001LU] beyond internal fall-through xref noise.
  - No proven route to adjacent raw island `0x005b1200`.
  - No function boundary at `0x005b11f5`, `0x005b1200`, or `0x005b1278`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b1030-0x005b10bd` | [UID:0001LT] `SpellOneArgInputPaneConstructor` | Constructor; stores `m_spellIndex` and prompt text. | TRUE | [UID:0000DR] | `86/90` | Support context |
| `0x005b1150-0x005b11f5` | [UID:0001LU] target | Virtual submit handler; parse one argument and send opcode `0x0f` length `4`. | TRUE | [UID:0000DR] | current `86/89`, recommend `88/90` | Target |
| `0x005b11f5-0x005b1200` | padding | Eleven `0xcc` bytes between target and raw island. | FALSE | NONE | n/a | No doc edit recommended |
| `0x005b1200-0x005b1278` | [UID:0003VW] `SpellOneArgDirectArgumentPacketRaw` | No-route direct argument packet island mirroring one-arg packet tail. | FALSE | NONE | `87/88` | Separate non-emitting raw page |
| `0x005b1278-0x005b1280` | padding | Padding before next modeled function, per B012 and current successor check. | FALSE | NONE | n/a | No doc edit recommended |
| `0x005b1280-...` | successor `sub_5B1280` | Nearby modeled sibling outside target. | TRUE | sibling context | n/a | Boundary control |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0062f62c` | data xref to `0x005b1150` | Vtable slot/data route for `SpellOneArgInputPane::OnSubmitInput()` |
| `0x005b1166` | call `sub_4F2310` | Text length check |
| `0x005b1181` | call `sub_4F2300` | Copy text into local wide buffer with max `0xff` |
| `0x005b118d` | call `unknown_libname_24` | CRT `_wtol`-style wide decimal parse |
| `0x005b119e` | call `sub_575380` | Write opcode `0x0f` |
| `0x005b11b2` | call `sub_575380` | Write stored spell index byte from `this+0x108` |
| `0x005b11c2` | call `sub_5753A0` | Write one signed 16-bit argument big-endian |
| `0x005b11e0` | call `sub_574BB0` | Send packet through `g_packetSender` with length `4` |
| `0x005b1200` | no xrefs to raw start | Adjacent raw helper is not a called child of target |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - Target page already states owner [UID:0000DR], file route [UID:0000O0], exact range, vtable slot, parse behavior, packet layout, sender dependency, raw-helper caveat, and formal C++.
  - [UID:0000DR] class page has the accepted declaration, `m_spellIndex`, constructor, destructor, and `OnSubmitInput` method table.
  - [UID:0000O0] file page places the family in `NexusTK/ui/dialogs/SpellInputPanes.cpp` and records raw-helper policy.
  - [UID:0001LN] aggregate page lists UID0001LU as the one-argument live handler and separates direct raw islands.
  - [UID:0003VW] records no-owner/non-emitting raw helper status and rejects merge into [UID:0001LU].
- Existing docs that were stale, incomplete, or contradicted before this callback:
  - Goal's [UID:0000DX] label for `SpellOneArgInputPane.md` is stale; actual UID is [UID:0000DR].
  - Historical A002 note saying final C++ was blank is superseded by B002 and current generated output.
  - The target's pre-callback `86/89` score predated this B006 live MCP/generated freshness synthesis and has now moved to `88/90`.
- Generated/coverage report state after callback:
  - `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`: `validator-command-id: 000000007793`, refreshed `2026-07-07T02:22:55-04:00`, UID0001LU marker `Completion:88 | Confidence:90`, formal body unchanged.
  - `auto-generated/-ag-research-tracker.md`: `validator-command-id: 000000007793`, refreshed `2026-07-07T02:22:55-04:00`, row `88/90`, average `89.0`, reconstructable true, direct report count `0`.
  - `auto-generated/-ag-memory-coverage.md`: `validator-command-id: 000000007793`, refreshed `2026-07-07T02:22:55-04:00`, row coded through owner/emitter `0000DR`, output `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`.
  - `auto-generated/-ag-coverage-report-by-memory.md`: `validator-command-id: 000000007793`, refreshed `2026-07-07T02:22:55-04:00`, emits_code true and describes UID0001LU as `88% : very-strong`.

## Ranked Ownership Analysis

### 1. [UID:0000DR] SpellOneArgInputPane
- Evidence for: target is reached through a class vtable/data slot, constructor stores the spell index at the same `this+0x108` offset, class declaration already contains `OnSubmitInput`, and generated output emits the method inside `SpellOneArgInputPane`.
- Evidence against: original source header name for `m_spellIndex` is inferred and no direct code caller exists because this is a virtual method.
- Decision: direct canonical owner and emitter remain [UID:0000DR].

### 2. [UID:0000O0] SpellInputPanes
- Evidence for: file page owns the spell prompt pane family, generated output path is `NexusTK/ui/dialogs/SpellInputPanes.cpp`, and class support routes through this file.
- Evidence against: file-level owner is less precise than the class for a member method.
- Decision: retain as source file route, not direct canonical owner for UID0001LU.

### 3. PacketBuffer / Socket / g_packetSender / CRT helpers
- Evidence for: target calls packet writers, sender queue helper, and CRT `_wtol`.
- Evidence against: these are dependency utilities; none own the feature-specific opcode or input-pane behavior.
- Decision: dependency context only. Do not move ownership.

### 4. [UID:0003VW] SpellOneArgDirectArgumentPacketRaw
- Evidence for: packet shape mirrors the one-arg target tail and uses the same opcode/spell-index/argument/send-length pattern.
- Evidence against: separated by `0xcc` padding, no current xrefs or pointer hits, not modeled as a function, and B012 retained no-owner/non-emitting status.
- Decision: separate raw island and future-route candidate only; do not merge into or derive from UID0001LU in this callback.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: not applicable; existing class/file placement is sufficient.
- Likely full contents: not applicable.
- Candidate related items that belong: not applicable.
- Candidate related items rejected: adjacent raw helper [UID:0003VW] remains separate.
- Standalone, narrow, or broad source-file inference: no new source file; `SpellInputPanes.cpp` remains the existing route.

## Source Placement
- Recommended source file/class/global/module placement: `SpellOneArgInputPane::OnSubmitInput()` under [UID:0000DR] `SpellOneArgInputPane`, routed through [UID:0000O0] `NexusTK/ui/dialogs/SpellInputPanes.cpp`.
- Why this placement fits source-tree and subsystem context: constructors/destructors and sibling spell prompt panes already live in the same file family; the handler uses the class's stored spell index and prompt text inherited from `NumberArgsInputPane`.
- Rejected placements and why: PacketBuffer and Socket are shared dependencies; CRT runtime is ignored source; raw helper [UID:0003VW] lacks route; [UID:0000DX] is a different spell pane class.
- Remaining placement uncertainty, if any: only exact original helper wrapper names and whether the original source used a member-style send call versus the accepted wrapper-style generated call.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: `0x005b1150-0x005b11f5` is exact by live `lookup_funcs` size `0xa5`; `0x005b11f5-0x005b1200` is eleven bytes of `0xcc` padding.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new child; keep [UID:0003VW] as a separate no-owner/non-emitting raw island.
- Padding/table/data/code distinctions: `0x0062f62c` is data pointer/vtable route; `0x005b11f5-0x005b1200` is padding; `0x005b1200` is raw function-shaped bytes but no modeled function/route.
- Parent/container impact: [UID:0001LN] aggregate and [UID:0000O0] file context already reflect this split; no support doc edits required by default.

## Negative Evidence Summary
- No direct code callers were found for `0x005b1150`; this does not weaken ownership because the target is vtable-routed.
- No xrefs, data refs, or absolute pointer bytes to `0x005b1200` were found in current MCP checks.
- No modeled function exists at `0x005b1200` or `0x005b1278`.
- PacketBuffer, Socket, sender global, and CRT helper ownership are rejected because they are shared callees/dependencies.
- Goal UID `0000DX` does not match the `SpellOneArgInputPane.md` file; current docs prove [UID:0000DR] is the class owner.
- Generated temp files under `auto-generated/tmp*` appeared in broad search output but are not used as authority; only canonical current generated files are used for freshness.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: preserve current source-facing names `SpellOneArgInputPane::OnSubmitInput`, `m_spellIndex`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `_wtol`, `g_packetSender`, and `QueueAndSendPacket`.
- Evidence for each proposed name/type/comment: class constructor/support docs for `m_spellIndex`; PacketBuffer helper docs for writer names; CRT wrapper doc for `_wtol`; Socket/global docs for sender.
- Items intentionally left unchanged and why: no IDA DB renames/comments/types requested. Report-only pass cannot and should not edit IDA or by-* docs.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes, already eligible and already populated in the target formal block.
- Recommended code: preserve the existing formal `RECONSTRUCTION_CPP CODE` header/block exactly:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SpellOneArgInputPane::OnSubmitInput()
{
    if (GetTextLength() <= 0) {
        return;
    }

    wchar_t text[256];
    CopyText(text, 255);

    const short argument = static_cast<short>(_wtol(text));

    unsigned char packet[5];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);
    PacketBufferWriteUInt16BE(argument, packet + 2);
    packet[4] = 0;

    QueueAndSendPacket(g_packetSender, packet, 4);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: live disassembly maps directly to positive length gate, 255-wide-char copy, `_wtol` low-16-bit argument narrowing, opcode write, spell-index byte write from `this+0x108`, one big-endian 16-bit write, unsent terminator, and send length `4`.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: it follows the accepted sibling SpellInputPanes style, local stack buffer pattern, CRT `_wtol` use, and small packet scratch buffer idiom already emitted by current generator.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `GetTextLength`, `CopyText`, `m_spellIndex`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `QueueAndSendPacket`, and `g_packetSender`.
- Naming/coding style convention used and evidence for consistency: existing generated `SpellInputPanes.cpp` and B002 accepted family bodies use the same style for four/three/two/one argument handlers.
- Reason code should remain blank, if applicable: not applicable; existing code should be preserved.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes applied or recommended: applied target metadata score update to `COMPLETION:88`, `CONFIDENCE:90`, plus target prose additions for B006 MCP/session evidence, generated freshness, old-report search result, stale UID label, negative evidence, and raw-helper separation.
- Exact parent assignments applied or recommended: preserved `CANONICAL_OWNER:0000DR` and `EMITTER_UIDS:0000DR`.
- Exact items left no-owner/non-emitting and why: [UID:0003VW] remains no-owner/non-emitting because live MCP and B012 evidence show no route to the raw start.
- Exact future work, if any, outside this assignment scope: recovered headers/source symbols could refine helper/member names or prove/refute source factoring for direct raw islands; no such evidence exists now.

## Recommended Target Doc Changes
- Target path: `by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md`.
- Exact report facts to incorporate:
  - B006 live MCP session `supervisor-nexustk-20260707`, server health `ok`, Hex-Rays ready, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
  - `lookup_funcs` target size `0xa5`; no function at `0x005b11f5`, `0x005b1200`, or `0x005b1278`; successor `0x005b1280` modeled.
  - One data/vtable xref from `0x0062f62c`; no direct code caller expectation; no route to `0x005b1200`.
  - Packet layout: opcode `0x0f`, `this+0x108` spell byte, one 16-bit argument, local terminator at `+4`, send length `4`.
  - Pre-callback generated state recorded in target: `SpellInputPanes.cpp` command `000000007780` refreshed `2026-07-07T02:03:47-04:00`; canonical generated reports command `000000007781` refreshed `2026-07-07T02:03:57-04:00`. Post-callback generated state refreshed to command `000000007793`.
  - Old-report state: no UID-specific B report; B002 and B012 are relevant accepted historical source-family/raw-helper reports.
- Metadata/score/owner/emitter/reconstructable/C++ changes: changed `COMPLETION:86` to `88`, `CONFIDENCE:89` to `90`; preserved owner/emitter/reconstructable and formal C++ exactly.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve raw-helper no-route caveat, helper-name inference caveat, CRT exclusion, no direct code caller/vtable route, and support UID mismatch only if useful.

## Recommended Support Doc Changes
- Support path: [UID:0000DR] `by-class/SpellOneArgInputPane.md`.
  - Exact report facts to incorporate: none required by default; current class page already lists `OnSubmitInput`, `m_spellIndex`, [UID:0003VW] caveat, and file route.
  - Metadata/link/score/coverage/source-placement changes: none recommended.
- Support path: [UID:0000O0] `by-file/SpellInputPanes.md`.
  - Exact report facts to incorporate: none required by default; current file page already records the one-arg source family and raw helper policy.
  - Metadata/link/score/coverage/source-placement changes: none recommended.
- Support path: [UID:0001LN] `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`.
  - Exact report facts to incorporate: none required by default; aggregate already distinguishes live submit handlers and direct raw islands.
  - Metadata/link/score/coverage/source-placement changes: none recommended.
- Support path: [UID:0003VW] `by-memory/0x005b1200-0x005b1278.SpellOneArgDirectArgumentPacketRaw.md`.
  - Exact report facts to incorporate: none required by default; B012 already records no-route/no-owner/non-emitting status and relation to [UID:0001LU].
  - Metadata/link/score/coverage/source-placement changes: none recommended.

## Score And Metadata Recommendation
- Current score/metadata after callback: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000DR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DR`, formal C++ populated and preserved. Historical pre-callback score was `86/89`.
- Recommended score/metadata: applied `COMPLETION:88`, `CONFIDENCE:90`, preserved `CANONICAL_OWNER:0000DR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DR`, and formal C++ exactly.
- Score rationale and reason not higher/lower:
  - Higher than current because B006 adds current live MCP validation, generated-output freshness, old-report search/no-prior-report result, dependency confirmation, and raw-helper split proof.
  - Not higher than `88/90` because original source names for helper wrappers/member field are inferred, the direct raw helper family still has no route, and the source call style for `QueueAndSendPacket` remains accepted generated/source-facing style rather than recovered-header proof.
  - Not lower because core behavior and owner route are direct binary facts and current formal C++ matches them exactly.
- Score-improvement attempt:
  - Boundary blocker: checked live `lookup_funcs`, `get_bytes`, unique signature; resolved.
  - Route blocker: checked `xrefs_to`, `xref_query`, data-ref and pointer bytes; resolved as vtable data route only.
  - Packet layout blocker: checked live decompile/disasm/helper docs; resolved.
  - Raw helper blocker: checked no xrefs/pointer bytes and B012 report; resolved as separate no-route caveat, not a target blocker.
  - Helper/source-name blocker: checked support docs and generated output; remains inference cap.
  - Generated freshness blocker: checked canonical generated headers and rows; resolved.
- Metadata fields changed or left unchanged: changed only completion/confidence; left owner, emitter, reconstructable, emitter position, and C++ unchanged.

## Open Questions With Attempted Resolution
- Open question: is `m_spellIndex` the original field name?
  - Evidence checked: class constructor, generated output, sibling spell input pages, raw helper reports.
  - Best supported resolution: keep `m_spellIndex` as accepted source-facing field name.
  - Remaining uncertainty: no recovered header proves exact spelling; score cap only.
- Open question: should the body use free `QueueAndSendPacket(g_packetSender, ...)` or member `g_packetSender->QueueAndSendPacket(...)`?
  - Evidence checked: current target formal C++, generated output, QueueAndSendPacket/g_packetSender docs.
  - Best supported resolution: preserve current formal wrapper style exactly; it is accepted in current source generation.
  - Remaining uncertainty: recovered headers may refine the call form; no current change justified.
- Open question: should [UID:0003VW] be promoted or merged?
  - Evidence checked: live no-route checks, padding, B012 report, support docs.
  - Best supported resolution: no; keep separate no-owner/non-emitting raw island.
  - Remaining uncertainty: only runtime route or pointer evidence could change this later.
- Open question: does the goal's [UID:0000DX] support label indicate a different owner?
  - Evidence checked: actual file header and UID search.
  - Best supported resolution: no; `SpellOneArgInputPane.md` is [UID:0000DR], and [UID:0000DX] is `SpellWhoInputPane`.
  - Remaining uncertainty: none for this target.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- File/placement: not applicable.
- Exact replacement/insert/delete text: none.
- Reason B agent must not apply it directly: generated `-ag-*` reports and coverage/tracker outputs are validator-owned. This report recommends source page metadata/prose changes only after supervisor callback; generated rows will refresh via scoped validators if implementation is approved.

## Follow-Up Actions
- Supervisor actions: Gate 2 / execute review of this callback implementation.
- A-agent actions: none requested.
- B006 future research actions: none for this target unless the supervisor returns a Gate 2 repair request.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high; `88/90` is conservative and aligned with sibling source-quality packet handlers.
- Remaining uncertainty: exact original names/header spellings and any future route evidence for direct raw helper [UID:0003VW].

## Validator Results
- Commands run:
  - `python .\tools\validator.py --mode file --file by-memory\0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md --apply --queue-timeout 240`
    - `command_id: 000000007791`
    - `command_timestamp: 2026-07-07T02:21:57-04:00`
    - exit code `0`, `ok: 1`
    - target effects: `completion_update: 1`, `confidence_update: 1`, UID links inserted by validator, `projected_stats_update: 1`, generated refresh deferred under command `000000007791`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md --apply --queue-timeout 240`
    - `command_id: 000000007793`
    - `command_timestamp: 2026-07-07T02:22:55-04:00`
    - exit code `0`, `ok: 1`
    - final cleanup effects: removed the unintended `0000DX` reference index after B006 changed stale-label wording to non-UID text; `projected_stats_update: 1`, generated refresh deferred under command `000000007793`.
- Generated freshness:
  - `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`: `validator-command-id: 000000007793`, `validator-refreshed-at: 2026-07-07T02:22:55-04:00`; UID0001LU marker now `Completion:88 | Confidence:90` and formal body unchanged.
  - `auto-generated/-ag-research-tracker.md`: `validator-command-id: 000000007793`, `validator-refreshed-at: 2026-07-07T02:22:55-04:00`; UID0001LU row now `88/90`, average `89.0`.
  - `auto-generated/-ag-memory-coverage.md`: `validator-command-id: 000000007793`, `validator-refreshed-at: 2026-07-07T02:22:55-04:00`; UID0001LU remains coded through owner/emitter `0000DR` to `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`.
  - `auto-generated/-ag-coverage-report-by-memory.md`: `validator-command-id: 000000007793`, `validator-refreshed-at: 2026-07-07T02:22:55-04:00`; UID0001LU is `emits_code:true`, `88% : very-strong`.
  - `project-level/-auto-completion-stats.md` was updated by the scoped validator as a projected-stats side effect.
- Any unresolved validator warnings/errors: none; final scoped validator exited `0` with `ok: 1`.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B006/research/0001LU-SpellOneArgInputPaneSubmitInput-source-quality.md` during the report-only pass.
- Modified by B006: `by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md`.
- Modified by B006: `tools/leaser/Agents/Agent-B006/research/0001LU-SpellOneArgInputPaneSubmitInput-source-quality.md`.
- Validator-generated/projected side effects from scoped validation: `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md` refreshed to command `000000007793`.
- Renamed: none.
- Support by-* docs edited: none.
- Leases used: leased `by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md` as B006 for the edit/validator batch and released it immediately after validation.
- Report execution: not run. No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, manual report move, manual generated edit, manual coverage edit, validator state edit, queue/lock edit, or supervisor-ledger edit was performed.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update: target `by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md` only by default; support docs [UID:0000DR], [UID:0000O0], [UID:0001LN], and [UID:0003VW] verified already present unless callback-time content is missing.
- [x] Current target state and actual evidence checked recorded: current `86/89`, owner/emitter `0000DR`, formal C++ populated, live MCP session `supervisor-nexustk-20260707`.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply: change target `COMPLETION:86` -> `88` and `CONFIDENCE:89` -> `90`.
- [x] Score-limiting blockers researched to resolution or evidence-backed cap: original helper/member names and raw-helper no-route family remain confidence caps after live MCP/generated/support checks.
- [x] Owner/emitter/reconstructable changes to apply: none; preserve `CANONICAL_OWNER:0000DR`, `EMITTER_UIDS:0000DR`, `RECONSTRUCTABLE:TRUE`.
- [x] Split/rename/new-child changes to apply: none; preserve [UID:0003VW] as separate no-owner/non-emitting raw island.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: source placement preserved; no IDA edits requested.
- [x] First-draft C++ or no-code proof to apply: preserve exact formal C++ block reproduced above; no blank/no-code disposition.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: listed in Recommended Target Doc Changes and support already-present sections.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: A002 blank-C++ note is historical; raw-helper no-route, CRT exclusion, vtable route, and helper-name caps are preserved.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: historical generated/simroot and temp generated files ignored as authority.
- [x] Open questions to close or document as evidence-backed unresolved: documented in Open Questions With Attempted Resolution.
- [x] Validators to run: none during report-only; if callbacked, run scoped validator for target page, plus support validators only if support docs are edited.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: no manual generated/coverage edits; scoped validator refresh only after callback.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation. Proof: callback goal records Gate 1 pass for accepted SHA `A8E772C52D079D3BD6948CE612084EECA5B2780AF4078657400C60D55EE5C26A`.
- [x] All accepted target details incorporated at report-level detail. Proof: target now has `## 2026-07-07 B006 Source-Quality Refresh`, updated Score Rationale, and 2026-07-07 Changes entry.
- [x] Support doc details checked as already-present; no support docs edited. Proof: [UID:0000DR], [UID:0000O0], [UID:0001LN], and [UID:0003VW] already contain the one-argument handler/raw-helper relationship and no-route caveat.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata score change applied: target `86/89` -> `88/90`.
- [x] Owner/emitter/reconstructable fields confirmed unchanged: `CANONICAL_OWNER:0000DR`, `EMITTER_UIDS:0000DR`, `RECONSTRUCTABLE:TRUE`.
- [x] Formal C++ block preserved exactly; generated `SpellInputPanes.cpp` still emits the same body at command `000000007793`.
- [x] No-xref/vtable-only and [UID:0003VW] no-route caveats preserved in target.
- [x] Text-edit cluster facts incorporated: positive text length, copy `255`, CRT `_wtol`, opcode `0x0f`, `m_spellIndex` / `this+0x108`, one 16-bit arg, local terminator, send length `4`.
- [x] Generated-output/freshness checked after scoped validator; final command `000000007793`, timestamp `2026-07-07T02:22:55-04:00`.
- [x] Validators run and results recorded: target scoped validator only; no support validators because support docs were not edited.
- [x] Lease used and released: B006 leased the target for the edit/validator batch and released it after final validation.
- [x] Forbidden actions avoided: no `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, manual report moves, manual generated edits, manual coverage edits, validator-state edits, queue/lock edits, or supervisor-ledger edits.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000007795","destination_path":"executed-b-agent-research/B006/0001LU-SpellOneArgInputPaneSubmitInput-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001LU-SpellOneArgInputPaneSubmitInput-source-quality.md","timestamp":"2026-07-07T02:39:38-04:00","uid":"0001LU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
