** TARGET-REPORT-UID:000499 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000499 OldUserStatusPaneApplyLegacyMovementStep Source Quality


## Finalized Report / Current Recommendation

- Current recommendation: accept [UID:000499] `by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md` as a real retained `OldUserStatusPane` movement helper, still owned by [UID:00009U] and emitted through [UID:0001NR].
- Final disposition: implementation callback completed. UID000499 now records the raw high-bit movement gate branch, uses the current canonical config pointer name `g_pConfig`, preserves owner/emitter/range/table disposition, and validates at `89/91`.
- Applied action: updated UID000499 target C++ and evidence text; updated sibling movement helper [UID:00049A] with the same gate/name fix; updated [UID:00009U], [UID:0001NR], and [UID:0000P2] support text only where needed to preserve refined evidence and remove stale generated-output wording. No split, move, or retarget was made.
- Confidence: high for range, owner/emitter, no-entry state, internal table ownership, and behavior after the C++ gate fix; medium-high for exact original source spellings because helper/global/type names remain reconstructed.

## Supporting Research

- Assignment source: current `tools/leaser/Agents/Agent-B007/goal.md`, UID000499 report-first xHigh assignment, and subsequent supervisor implementation callback.
- Project workflow used: project-level `ntk-b-agent-workflow` skill plus `b-agent-research-and-implementation-workflow.md`, `b-agent-report-template.md`, and `score-blocker-audit-standard.md`.
- Lifecycle/status notes: historical Gate 1 for the earlier report artifact passed and the implementation callback has been completed. A later current-artifact Gate 1 audit failed on `2026-07-07T02:10:00-04:00` for report-text issues only; this repair updates that same report artifact for a fresh supervisor Gate 1 re-audit. Prior B002 work is historical accepted support evidence, not this report's current execution state.
- MCP status: live MCP session `supervisor-nexustk-20260707` was available and healthy. `idb_list` reported one active owned/adopted worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2067`.
- Old-report search terms used before finalizing: `TARGET-REPORT-UID:000499`, `000499`, `0x005bf520`, `0x005bf670`, `OldUserStatusPaneApplyLegacyMovementStep`, `ApplyLegacyMovementStep`, `OldUserStatusPane`, `00009U`, `0001NR`, `00049A`, `00049B`, `0x005bf660`.
- Old-report result: no direct prior `TARGET-REPORT-UID:000499` report was found. The matching executed report is B002 `executed-b-agent-research/B002/0001NR-OldUserStatusPane-source-quality.md`, which created UID000499 and siblings from accepted OldUserStatusPane split work. B009 `executed-b-agent-research/B009/0000P2-UserStatusPane-empty-emitter-family-source-quality.md` confirms the OldUserStatusPane body route was already handled by B002 and should not be moved by unrelated file-family work.

## Target

- Target UID: `000499`.
- Target path: `by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` row for UID000499 under by-memory not-covered reconstructable files, direct report count `0`.
- Current supervisor classification: same-report Gate 1 repair after implementation callback for a reconstructable by-memory exact helper page.
- Current scores and parent state: target is now `89/91`, owner `00009U`, emitter `0001NR`; owner class [UID:00009U] remains `88/90`; aggregate emitter [UID:0001NR] remains `89/91`; file route [UID:0000P2] remains `90/87`.

## Current Target State

- Current implemented state: the implementation callback is complete. UID000499 target and listed support docs were edited, scoped validators `000000007769` through `000000007773` ran successfully, the report ledger/checklist was updated, and leases were released.
- Current artifact review state: this repaired report is awaiting supervisor current-artifact Gate 1 re-audit, then supervisor Gate 2 claim verification against changed docs/validator output, and only then supervisor-owned `execute_report` if both gates pass. B007 did not run `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, manual report moves, or report registry commands.
- Current target metadata after callback: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR`.
- Historical/pre-callback metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR`.
- Historical/pre-callback owner/emitter/reconstructable state: correct. The helper was already an `OldUserStatusPane` member-like source body and emitted under the OldUserStatusPane memory aggregate.
- Historical/pre-callback C++/emitter state: formal C++ existed and mostly matched the raw helper, but compressed the map/config high-bit gate into `if (ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pGameConfig, direction)) direction &= 0x7f;`. Current MCP instructions prove the raw body returns `false` when the map/config gate is active and the signed direction byte is nonnegative; the pre-callback draft continued instead. The pre-callback draft also used `g_pGameConfig`, while current config support docs name the storage at `0x0067a7c8` as `g_pConfig`.
- Historical/pre-callback open questions or blockers: no external entry ref; exact original source spelling for movement gate helper and Config field remains inferred; packet byte `packet[10]` is read and discarded by the raw helper; formal C++ needed the exact early-return branch.
- Related target/support docs checked: UID00009U class page, UID0001NR aggregate page, UID00049A sibling movement helper, UID00049B status payload helper, UID000495/UID000496 invalidation/rect lookup support, UID0000P2 file page, `g_activeMapPane`, exact active-map storage UID0001OW, and exact config storage UID00028Q.
- Current artifact/lifecycle status: same-report Gate 1 repair after the implementation callback. Scoped validators `000000007769` through `000000007773` remain the callback validator record; no new validators were run for this report-text-only repair. No `execute_report`, lifecycle/archive command, dry-run/probing execute variant, manual move, or report registry command was run by B007.

## Executive Recommendation

- Keep the target range `0x005bf520-0x005bf670`: body `0x005bf520-0x005bf660` plus internal jump table `0x005bf660-0x005bf670`.
- Keep `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0001NR`.
- Update the formal C++ to preserve the gate:
  - when the active-map movement/status gate is true and `g_pConfig + 0x28de75` is `1`, a nonnegative direction byte returns `false`;
  - only a negative direction byte has its high bit cleared and proceeds into the direction switch.
- Replace source-facing `g_pGameConfig` with `g_pConfig` for this helper family, or explicitly document `g_pGameConfig` as superseded alias text. Current support evidence favors `g_pConfig`.
- Raise UID000499 to `89/91` after the target page records this evidence and the C++ correction. Do not raise to `95+` because the helper remains no-entry and several source names are inferred.

## Supervisor Active Recheck

- Current user/supervisor instruction: repair this same UID000499 report artifact for Gate 1 review from updated `goal.md`; do not edit by-* docs, do not run validators, and do not run `execute_report`, lifecycle/archive commands, manual moves, or report registry commands.
- Split repair before final report: not required. The split already exists and current MCP confirms the target table belongs to this child.
- Source-bearing children in scope: UID000499 is the target; UID00049A is a directly triggered support sibling because it has the same raw movement-gate bug in formal C++; UID00049B is support context for router/status-payload placement and needs no edit from this target except verification that its direct router call remains separate.

## Inference Research Guidance Check

- IDA facts are separated from documentation evidence and inference below.
- Wave2/Wave3/simroot content was not used as proof. Historical generated-output caveats in support docs were checked only to decide whether they are stale.
- Existing B002 assumptions were rechecked against current MCP instead of copied forward. Most range/ownership claims held; the formal movement C++ gate did not.
- `by-structure.md` owner/emitter rules support keeping `CANONICAL_OWNER` on the direct class owner and using `EMITTER_UIDS` only for the output route through the aggregate and file root.

## Heuristic / Inference Reanalysis And Validation

- No-entry/no-xref state: resolved. MCP `lookup_funcs` reports `0x005bf520`, `0x005bf660`, and `0x005bf670` are not modeled functions. `xrefs_to`, `find code_ref`, `find data_ref`, immediate searches, and VA/RVA byte-pattern searches find no route to target entry `0x005bf520`. That limits confidence but does not make the range padding because the body is valid source-shaped code.
- Router/table/pointer/sibling reachability: target entry remains no-entry. The internal table at `0x005bf660` has one data ref from `0x005bf5d3`, and the raw bytes at `0x005bf660` are four little-endian case targets inside the target body. The sibling table at `0x005bf7b0` has one data ref from `0x005bf723`. `0x005bf7c0` status payload is a real modeled function called by the router at `0x005bdf24`; the target and sibling movement helpers are not called by that router.
- Formal C++ correctness: current draft is close but not exact. MCP instruction `0x5bf57f-0x5bf59a` proves the map/config gate includes `cmp byte ptr [g_pConfig + 0x28de75], 1`, then `test direction`, `jns return_false`, else `direction &= 0x7f`. The current C++ only masks through a helper predicate and misses the early return for nonnegative direction under that gate.
- Packet fields: `packet[1]` is the signed direction byte; `packet+2` and `packet+4` are signed big-endian x/y words via `sub_575480`; `packet+10` is read through the narrow-character helper and discarded. No safer source-facing name than an unused packet byte is proven for `packet[10]`.
- Direction constants: after masking, `0` decrements y and clamps to top; `1` increments x and clamps to right minus one; `2` increments y and clamps to bottom minus one; `3` decrements x and clamps to left; `4` returns false; default does no movement and proceeds to the unchanged-position check.
- Map-bound helpers: `dword_67A764` is current documented [UID:0000PR] `g_activeMapPane`; the body reads map bounds at `+0x3f4`/`+0x3f6` and calls `sub_4B7C50` to build a `RectBounds`. Keeping `GetLegacyMovementBounds(g_activeMapPane, &movementBounds)` is a source-shaped wrapper over those raw operations.
- Config/global names: `dword_67A7C8` is current documented [UID:00028Q] `g_pConfig`; offset `+0x28de75` is the map/movement status option byte. The older B002-local support name `g_pGameConfig` should be replaced with `g_pConfig` in UID000499 and UID00049A C++ and support-name lists.
- Invalidation field id `12`: raw UID000499 does not push literal `12`; it directly builds the rectangle `(101,82,192,94)` and calls the pane invalidation vslot. UID000496 `GetStatusFieldRect` maps field id `12` to exactly that rectangle, so `InvalidateStatusFieldRect(12)` is valid source-level factoring, but the report should state it is inferred by rectangle equivalence, not a direct literal in this raw helper.
- Internal jump table coverage: fully covered by UID000499. MCP bytes at `0x005bf660` are `da f5 5b 00 e6 f5 5b 00 f3 f5 5b 00 00 f6 5b 00`, the four switch targets `0x005bf5da`, `0x005bf5e6`, `0x005bf5f3`, and `0x005bf600`. No standalone table page is needed.
- Owner/emitter route: [UID:00009U] remains the direct class owner, [UID:0001NR] remains the aggregate emitter, and [UID:0000P2] remains the file root. `g_activeMapPane` and `g_pConfig` are dependencies, not owners.
- Score movement: current page can improve because this pass resolves the target-specific C++ fidelity blocker, gives current live MCP no-entry/pointer/table evidence, and aligns global naming. It should not exceed low 90s because exact original helper/global/field names remain inferred and the raw entry is not externally referenced.

## Evidence Standards Used

- Current live IDA MCP was treated as highest evidence for function status, instruction behavior, bytes, and xrefs.
- Current by-* docs were used for owner/emitter route, source-facing global names, class/field context, and generated-output policy.
- Generated output was used as a current emission lead only, not as authority.
- Executed B-agent reports were used only after search-gating and were treated as historical accepted support evidence.
- Negative evidence included no function at raw entries, no code/data refs, no pointer-byte hits, no immediate hits, and separate router call evidence for UID00049B.
- Inference was used only for source-facing helper names and the field-id abstraction over a raw rectangle call.

## Evidence Checked

- IDA MCP/session checks:
  - `idb_list`: active session `supervisor-nexustk-20260707`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker pid `14640`.
  - `server_health`: `ok`, Hex-Rays ready, strings cache ready.
  - `lookup_funcs`: `0x005bf520`, `0x005bf660`, `0x005bf670`, and `0x005bf7b0` are not functions; `0x005bf7c0` is modeled `sub_5BF7C0` size `0x401`; router `0x005bdcb0` is modeled size `0x28c`.
  - `xrefs_to` and `find`: no code/data refs to `0x005bf520` or `0x005bf670`; one data ref to `0x005bf660` from `0x5bf5d3`; one data ref to `0x005bf7b0` from `0x5bf723`; one code ref to `0x005bf7c0` from `0x5bdf24`.
  - `find immediate`: no matches for target VA/RVA/table/entry immediates `0x005bf520`, `0x001bf520`, `0x005bf660`, `0x001bf660`, `0x005bf670`, or `0x001bf670`.
  - `find_bytes`: no pointer bytes for `20 F5 5B 00` or `20 F5 1B 00`; one target-table pointer sequence `60 F6 5B 00` at `0x5bf5d6`; no `70 F6 5B 00`.
  - `get_bytes`: `0x005bf51a-0x005bf520` is six `0xcc` bytes; target prolog begins `55 8b ec 83 ec 30`; `0x005bf660-0x005bf670` is the target jump table; `0x005bf670` begins sibling prolog.
  - `insn_query`: target instruction chunks `0x005bf520-0x005bf660`, sibling chunks `0x005bf670-0x005bf7b0`, and router snippet `0x005bdea0-0x005bdf35`.
  - `decompile 0x005bf520`: failed because raw entry is not an IDA-modeled function; this is expected evidence for raw no-entry status, not an MCP failure.
  - `int_convert`: `0x150` = decimal `336`, `0x140` = decimal `320`, `0x10` = decimal `16`, `12` = `0xc`, `0x28de75` = decimal `2678389`, `0x15c` = decimal `348`, `0x160` = decimal `352` (Verified with MCP `int_convert`).
- Documentation checked:
  - Target UID000499 by-memory page.
  - [UID:00009U] `by-class/OldUserStatusPane.md`.
  - [UID:0001NR] `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md`.
  - [UID:00049A] and [UID:00049B] sibling by-memory pages.
  - [UID:000495] `InvalidateStatusFieldRect` and [UID:000496] `GetStatusFieldRect`.
  - [UID:0000P2] `by-file/UserStatusPane.md`.
  - [UID:0000PR] `by-global/g_activeMapPane.md`, [UID:0001OW] exact active-map storage, and [UID:00028Q] exact config storage.
  - Historical/report-only generated evidence checked before callback: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp`, header `validator-command-id: 000000007740`, `validator-refreshed-at: 2026-07-06T20:08:27-04:00`. Current post-callback generated freshness is recorded under `Validator Results`.
  - Generated `auto-generated/-ag-research-tracker.md`, `-ag-memory-coverage.md`, and `-ag-coverage-report-by-memory.md` rows for UID000499 and support UIDs.
  - Executed B002 and B009 reports matching the required old-report terms.
- Failed, unavailable, or intentionally skipped checks:
  - No broad decompilation was attempted for raw UID000499 because IDA does not model it as a function; bounded disassembly was used instead.
  - No validators were run during the report-only pass; implementation callback validator metadata is recorded below.
  - No lifecycle/archive/execute commands were run.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| B007-499-C01 | UID000499 remains a real retained OldUserStatusPane movement helper, not padding. | High | MCP target instructions at `0x005bf520-0x005bf65c`, security-cookie prolog/epilog, packet reads, field writes. | UID000499 status/evidence | incorporated | applied in UID000499 status/evidence on 2026-07-07 |
| B007-499-C02 | Target entry `0x005bf520` has no external code/data/pointer route. | High | `lookup_funcs` not function; `xrefs_to`/`find code_ref`/`find data_ref` zero; VA/RVA pointer byte searches zero. | UID000499 no-entry evidence | incorporated | applied in UID000499 evidence/negative evidence on 2026-07-07 |
| B007-499-C03 | `0x005bf660-0x005bf670` is UID000499's internal switch table. | High | `xrefs_to 0x005bf660` only from `0x5bf5d3`; bytes are four targets inside body. | UID000499 range/table notes and UID0001NR child inventory | incorporated | applied in UID000499 evidence and UID0001NR evidence notes on 2026-07-07 |
| B007-499-C04 | Existing formal C++ misses the early return for nonnegative direction under the active map/config high-bit gate. | High | MCP `0x5bf57f-0x5bf59a` and matching sibling `0x5bf6cf-0x5bf6ea`. | UID000499 C++ block; UID00049A support C++ | incorporated | applied in UID000499/UID00049A C++ blocks on 2026-07-07 |
| B007-499-C05 | Use current source-facing config global `g_pConfig`, not `g_pGameConfig`, for `dword_67A7C8`. | Medium-high | UID00028Q documents `0x0067a7c8` as `g_pConfig`; MCP raw label is `dword_67A7C8`; `g_pGameConfig` appears only in B002-local movement support text. | UID000499 C++ and support-name lists | incorporated | applied in UID000499, UID00049A, UID0001NR, and UID00009U on 2026-07-07 |
| B007-499-C06 | `dword_67A764` remains dependency `g_activeMapPane`, not an OldUserStatusPane-owned global. | High | UID0000PR/UID0001OW docs; target raw `mov eax, dword_67A764`; map bounds reads. | UID000499 dependencies | already-present plus incorporated current evidence | applied in UID000499 negative evidence and UID0001NR/UID00009U evidence notes on 2026-07-07 |
| B007-499-C07 | Field id `12` is a valid source abstraction by rectangle equivalence, not a direct literal in UID000499. | High | UID000499 pushes `(101,82,192,94)`; UID000496 maps case `12` to same rectangle. | UID000499 invalidation notes | incorporated | applied in UID000499 behavior and UID00009U evidence notes on 2026-07-07 |
| B007-499-C08 | Direction cases are `0` north/up y--, `1` east/right x++, `2` south/down y++, `3` west/left x--, `4` early false. | High | MCP switch instructions `0x5bf5ce-0x5bf606`; sibling same pattern. | UID000499 behavior section | incorporated | applied in UID000499 behavior on 2026-07-07 |
| B007-499-C09 | Owner stays [UID:00009U], emitter stays [UID:0001NR], file route stays [UID:0000P2]. | High | Class/aggregate/file docs; B002 accepted split; no contrary xrefs or ownership evidence. | UID000499 metadata and support docs | already-present | verified unchanged on 2026-07-07 |
| B007-499-C10 | UID00049A needs the same C++ high-bit gate and `g_pConfig` support fix because its raw code is identical in the relevant branch. | High | MCP sibling instructions `0x5bf6cf-0x5bf6ea`; existing UID00049A C++ has same bug/name. | UID00049A C++ block/support notes | incorporated | applied in UID00049A C++/evidence on 2026-07-07 |
| B007-499-C11 | UID00049B remains separate status payload called by router; it is not a movement helper owner/emitter. | High | MCP `xrefs_to 0x005bf7c0` from router `0x5bdf24`; UID00049B docs. | Report/support scope only | already-present | verified no UID00049B edit required on 2026-07-07 |
| B007-499-C12 | Generated `UserStatusPane.cpp` is current and no longer marker-only for UID000499, making one by-file caveat stale. | High | Generated header command `000000007740`, body includes UID000499/49A/49B; callback validator refreshed header to `000000007773`. | UID0000P2 Data Caveats | incorporated | applied in UID0000P2 Data Caveats and Changes on 2026-07-07 |
| B007-499-C13 | Score should move to `89/91` after C++ and evidence incorporation, not `95+`. | Medium-high | Current MCP resolves target blockers but no-entry and inferred source names remain. | UID000499 metadata | incorporated | applied and validated by command `000000007769` on 2026-07-07 |

## Positive Evidence Summary

- Direct IDA facts support the target as a real body: stack frame, security cookie, packet byte/word reads, active map/config global reads, four-case switch, member field writes at `this+0x15c/+0x160`, rectangle construction, virtual invalidation call, and `retn 4`.
- Target table ownership is exact: one data xref from the switch instruction and four entries pointing into the target body.
- Documentation evidence supports the owner route: class [UID:00009U] lists the method; aggregate [UID:0001NR] contains the body/table rows; by-file [UID:0000P2] owns the OldUserStatusPane family.
- Current generated output confirms the formal body is emitted under `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` and can be checked after validator refresh.
- Strongest inference chain: raw function-shaped body plus OldUserStatusPane member field writes plus accepted aggregate split plus no competing owner evidence is sufficient for class ownership and child emission, while no-entry evidence caps final audit confidence.

## IDA MCP Facts

- Function/range facts:
  - `0x005bf520`: not an IDA-modeled function; decompile fails.
  - `0x005bf660`: not a function; internal table.
  - `0x005bf670`: not a function; sibling raw entry.
  - `0x005bf7c0`: modeled `sub_5BF7C0`, size `0x401`.
  - `0x005bdcb0`: modeled router `sub_5BDCB0`, size `0x28c`.
- Data/table/padding facts:
  - `0x005bf51a-0x005bf520`: six `0xcc` bytes.
  - `0x005bf660-0x005bf670`: `da f5 5b 00 e6 f5 5b 00 f3 f5 5b 00 00 f6 5b 00`.
  - `0x005bf7b0-0x005bf7c0`: sibling table `2a f7 5b 00 36 f7 5b 00 43 f7 5b 00 50 f7 5b 00`.
- Xref facts:
  - `0x005bf520`: zero xrefs.
  - `0x005bf660`: one data xref from `0x5bf5d3`.
  - `0x005bf670`: zero xrefs.
  - `0x005bf7b0`: one data xref from `0x5bf723`.
  - `0x005bf7c0`: one code xref from router `0x5bdf24`.
- Key instruction facts:
  - `0x5bf541-0x5bf569`: reads `packet[1]`, `ReadPacketInt16BE(packet+2)`, `ReadPacketInt16BE(packet+4)`, and a discarded `packet[10]`.
  - `0x5bf574-0x5bf59a`: calls map gate `sub_5055D0`; checks `g_pConfig+0x28de75`; returns for nonnegative direction under the gate; masks high bit for negative direction.
  - `0x5bf5aa-0x5bf5c2`: builds movement bounds from active map pane fields and `sub_4B7C50`.
  - `0x5bf5d3`: jumps through the table at `0x005bf660`.
  - `0x5bf60c-0x5bf647`: compares/writes `this+0x15c/+0x160`, builds rectangle `(101,82,192,94)`, calls vslot `+0x20`.
- Negative IDA facts:
  - No pointer bytes, immediates, code refs, or data refs to target entry were found in current bounded searches.
  - MCP has no named globals in the small `0x0067a740-0x0067a7e0` entity query; source-facing global names come from current by-* support docs.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005bf490-0x005bf51a` | UID000498 `OldUserStatusPaneApplyLegacyPositionPacket` | Retained position packet helper | TRUE | UID00009U | `86/90` | Sibling context |
| `0x005bf51a-0x005bf520` | aggregate row only | Alignment | FALSE as standalone | UID0001NR | n/a | Already documented |
| `0x005bf520-0x005bf660` | UID000499 target | Retained movement helper body | TRUE | UID00009U | current `86/89`, recommend `89/91` | Needs C++ gate/name correction |
| `0x005bf660-0x005bf670` | UID000499 target tail | Internal jump table | TRUE as part of UID000499 | UID00009U | same as UID000499 | Keep with target |
| `0x005bf670-0x005bf7b0` | UID00049A `OldUserStatusPaneApplyLegacyMovementStepAlt` | Sibling retained movement helper | TRUE | UID00009U | `86/89` | Needs same C++ gate/name support fix |
| `0x005bf7b0-0x005bf7c0` | UID00049A table tail | Internal jump table | TRUE as part of UID00049A | UID00009U | same as UID00049A | Keep with sibling |
| `0x005bf7c0-0x005bfbc1` | UID00049B `OldUserStatusPaneApplyLegacyStatusPayload` | Router-called status payload applicator | TRUE | UID00009U | `86/89` | Support context; no target edit required |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005bf520` | zero code/data refs | Target is retained no-entry raw helper. |
| `0x005bf5d3 -> 0x005bf660` | data xref / table dispatch | Target internal switch table ownership. |
| `0x005bf670` | zero code/data refs | Sibling movement raw helper is also retained no-entry. |
| `0x005bf723 -> 0x005bf7b0` | data xref / table dispatch | Sibling internal switch table ownership. |
| `0x005bdf24 -> 0x005bf7c0` | code call from router | Router calls status payload helper, not UID000499. |
| `0x005bf647` | virtual call `[this vtable + 0x20]` with rect | Raw invalidation call for position rectangle. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - UID000499 already records correct owner/emitter/range/table disposition.
  - UID0001NR already records body/table rows for UID000499 and UID00049A, no-entry raw helper status, and source route through OldUserStatusPane.
  - UID00009U already lists `ApplyLegacyMovementStep`, `ApplyLegacyMovementStepAlt`, and the field offsets `+0x15c/+0x160`.
  - UID000496 maps status field id `12` to rectangle `(101,82,192,94)`, supporting the target's source-level `InvalidateStatusFieldRect(12)` abstraction.
  - UID0000PR and UID00028Q provide the current source-facing names `g_activeMapPane` and `g_pConfig`.
- Existing docs that are incomplete or stale:
  - UID000499 and UID00049A C++ miss the high-bit gate early return.
  - UID000499, UID00049A, UID00009U, and UID0001NR use/support the older inferred `g_pGameConfig` name even though current config docs use `g_pConfig`.
  - UID0000P2 still says active generated output for OldUserStatusPane is marker-only/stale after B002; current generated output now contains UID000495-UID00049B bodies under validator command `000000007740`.
- Generated/coverage report state:
  - `-ag-research-tracker.md` lists UID000499 as `86/89`, direct report count `0`.
  - `-ag-memory-coverage.md` lists UID000499 coded to `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp`.
  - `-ag-coverage-report-by-memory.md` lists UID000499 as reconstructable, emits code true, current coverage score `86%`, strong.

## Ranked Ownership Analysis

### 1. [UID:00009U] OldUserStatusPane

- Evidence for: target writes OldUserStatusPane fields at `this+0x15c/+0x160`, uses status rect invalidation, sits inside the OldUserStatusPane method/helper island, and is already listed in the class and aggregate docs.
- Evidence against: no external entry refs to this raw helper; exact original method name is inferred.
- Decision: keep as canonical owner. No stronger owner exists.

### 2. [UID:0001NR] OldUserStatusPane memory aggregate as emitter/container

- Evidence for: aggregate contains target body/table and sibling helper ranges; its formal `[[CHILDREN]]` route is designed to emit exact child bodies.
- Evidence against: aggregate should not own the direct semantic method identity; child body C++ belongs on UID000499.
- Decision: keep as emitter and container only.

### 3. [UID:0000P2] UserStatusPane file root

- Evidence for: file owns the status HUD family and generated output path; OldUserStatusPane routes through this file.
- Evidence against: by-structure says class-owned methods should not bypass the direct class owner just to reach a file root.
- Decision: keep as source file root via UID00009U/UID0001NR, not direct target owner.

### 4. MapPane / Config globals

- Evidence for: target reads `g_activeMapPane` and `g_pConfig` and uses map bounds/config option.
- Evidence against: they are dependency globals; target writes no MapPane or Config-owned state except reading map bounds/config byte.
- Decision: dependency only, not ownership.

### 5. No owner / non-emitting

- Evidence for: target entry has no xrefs.
- Evidence against: body is valid source-shaped code, writes class fields, has accepted aggregate context, and already emits through a valid route.
- Decision: reject.

## Source Placement

- Recommended source file/class/global/module placement: `OldUserStatusPane::ApplyLegacyMovementStep` under the OldUserStatusPane class declaration in `UserStatusPane.cpp`, emitted from exact by-memory child UID000499 through aggregate UID0001NR.
- Why this placement fits: the body manipulates OldUserStatusPane fields and invalidation, duplicates legacy status router movement behavior, and sits with OldUserStatusPane helper siblings, not MapPane or Config implementation.
- Rejected placements:
  - MapPane: only supplies map bounds/gate dependency.
  - Config: only supplies one movement/status option byte.
  - shared destructor/thunk tail UID0001NS: range starts later at `0x005bfbd0`.
  - standalone free helper file: no evidence for a separate source module.
- Remaining placement uncertainty: exact original method name and helper names remain inferred, but class/file placement is strong.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts:
  - Target file range `0x005bf520-0x005bf670` is `0x150` bytes / decimal `336` (Verified with MCP `int_convert`).
  - Body `0x005bf520-0x005bf660` is `0x140` bytes / decimal `320` (Verified with MCP `int_convert`).
  - Table `0x005bf660-0x005bf670` is `0x10` bytes / decimal `16` (Verified with MCP `int_convert`).
  - Preceding `0x005bf51a-0x005bf520` is six `0xcc` bytes.
  - Successor `0x005bf670` starts the sibling raw helper prolog.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner:
  - No new child pages are needed.
  - Keep target body and table in UID000499.
  - Keep sibling body/table in UID00049A.
  - Keep status payload UID00049B separate.
- Padding/table/data/code distinctions:
  - `0x005bf660-0x005bf670` is data table owned by the preceding code body, not padding and not standalone source data.
  - `0x005bf51a-0x005bf520` is alignment padding and should remain aggregate-only.
- Parent/container impact: UID0001NR range map is correct; update evidence text only if accepted.

## Negative Evidence Summary

- No external code refs, data refs, immediate refs, or VA/RVA pointer bytes identify a live caller for `0x005bf520`.
- Hex-Rays cannot decompile `0x005bf520` directly because IDA does not model it as a function.
- Router evidence does not rescue target reachability: router snippet directly calls UID00049B at `0x005bdf24` but not UID000499 or UID00049A.
- `g_activeMapPane` and `g_pConfig` use is dependency evidence, not owner evidence.
- Existing `g_pGameConfig` wording is weak because current exact config storage docs use `g_pConfig`, and the `g_pGameConfig` name appears only in the B002 OldUserStatusPane movement helper context.
- Existing `InvalidateStatusFieldRect(12)` is not a direct literal in target raw code; the raw helper builds the rectangle directly. The field id is still acceptable because UID000496 maps id `12` to the same rectangle.
- No score above `95` is justified because no-entry status and inferred source names remain.

## IDA Rename / Type / Comment Recommendations

- No IDA database edits are requested.
- Source-facing names to use in by-* docs and C++:
  - `OldUserStatusPane::ApplyLegacyMovementStep`
  - `g_activeMapPane`
  - `g_pConfig`
  - `RequiresLegacyMovementDirectionTag` or keep existing `ShouldMaskLegacyMovementDirection` with clarified signature/meaning: it must represent only the active-map/config gate, not consume the direction byte.
  - `ReadPacketInt16BE`
  - `GetLegacyMovementBounds`
  - `InvalidateStatusFieldRect(12)` with note that raw target directly constructs the position rectangle.
- Items intentionally left unchanged:
  - `packet[10]` remains an explicitly discarded packet byte until a packet-layout pass proves its source label.
  - `m_positionX`/`m_positionY` can remain. `m_mapX`/`m_mapY` are plausible synonyms but no stronger current proof requires a rename.
- IDA edits are unsafe/not requested because the assignment is documentation-only and current policy uses MCP as inspection, not IDA mutation.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. UID000499 is reconstructable, has nonblank emitter route to generated output, and clears the current code-entry score gate.
- Historical/report-only recommendation, applied during the implementation callback: replace the target formal C++ block with the following exact formal content. This is not a body-only sample.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool OldUserStatusPane::ApplyLegacyMovementStep(const unsigned char *packet)
{
    signed char direction = static_cast<signed char>(packet[1]);
    int x = ReadPacketInt16BE(packet + 2);
    int y = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pConfig))
    {
        if (direction >= 0)
            return false;

        direction &= 0x7f;
    }

    if (direction == 4)
        return false;

    RectBounds movementBounds;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);

    switch (direction)
    {
    case 0:
        --y;
        if (y < movementBounds.top)
            y = movementBounds.top;
        break;
    case 1:
        ++x;
        if (x >= movementBounds.right)
            x = movementBounds.right - 1;
        break;
    case 2:
        ++y;
        if (y >= movementBounds.bottom)
            y = movementBounds.bottom - 1;
        break;
    case 3:
        --x;
        if (x < movementBounds.left)
            x = movementBounds.left;
        break;
    default:
        break;
    }

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(12);
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: the recommended block preserves packet offsets, signed big-endian coordinate reads, the `packet[10]` read marker, active-map/config high-bit gate with early false return, direction switch/clamps, position field update, and status position rectangle invalidation.
- Reason it matches plausible original source shape: it keeps class method form, source-facing helper wrappers for byte-order reads and rectangle bounds, and avoids raw IDA labels.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `OldUserStatusPane`, `RectBounds`, `ReadPacketInt16BE`, `GetLegacyMovementBounds`, `ShouldMaskLegacyMovementDirection`, `g_activeMapPane`, `g_pConfig`, `m_positionX`, `m_positionY`.
- Naming/coding style convention used: same style as existing generated `UserStatusPane.cpp` methods, but corrected to current support name `g_pConfig`.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes recommended:
  - Update UID000499 C++ and prose for the high-bit gate and `g_pConfig`.
  - Raise UID000499 to `COMPLETION:89`, `CONFIDENCE:91`.
  - Preserve UID000499 owner/emitter/reconstructable/range.
  - Update UID00049A with the same C++ gate/name correction because current MCP proves the sibling has the identical branch.
  - Update UID00009U and UID0001NR support-name/evidence text from `g_pGameConfig` to `g_pConfig` for movement helpers.
  - Update UID0000P2 stale generated-output caveat to historicalize the old marker-only state and note current generated output includes OldUserStatusPane child bodies.
- Exact parent assignments recommended: no owner/emitter changes.
- Exact items left no-owner/non-emitting and why: none.
- Exact future work outside this assignment: a broader Config/source-name pass may refine the `+0x28de75` field name and movement gate helper spelling, but it is not required to correct UID000499 behavior now.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md`.
- Exact report facts to incorporate:
  - Current MCP session `supervisor-nexustk-20260707` confirms raw no-entry status, body/table ranges, no pointer route, and internal table ownership.
  - Instruction-level behavior including early false return under the active-map/config high-bit gate.
  - Current source-facing config global should be `g_pConfig`; raw label is `dword_67A7C8`.
  - Field id `12` is source factoring by rectangle equivalence to UID000496, not a direct literal in this raw helper.
  - Direction case table and clamp behavior.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:86 -> 89`.
  - `CONFIDENCE:89 -> 91`.
  - Keep `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR`.
  - Replace formal C++ with the exact block in `First-Draft C++ Recommendation`.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve no-entry/no-xref evidence.
  - Preserve rejection of padding/no-owner/MapPane/Config ownership.
  - Preserve table ownership and router non-call evidence.

## Recommended Support Doc Changes

- Support path: `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md` ([UID:00049A]).
  - Exact facts to incorporate: current MCP sibling instructions `0x5bf6cf-0x5bf6ea` prove the same high-bit gate and early false return as UID000499; `0x005bf7b0` table has one internal data ref from `0x5bf723`.
  - Metadata/link/score/coverage/source-placement changes: no score change required for this target report. Replace `ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pGameConfig, direction)` with the same corrected gate using `ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pConfig)`, method name `ApplyLegacyMovementStepAlt`.
- Support path: `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md` ([UID:0001NR]).
  - Exact facts to incorporate: add B007 current MCP confirmation for UID000499 no-entry, table ref, high-bit gate, and `g_pConfig` source name; update support-name list from `g_pGameConfig` to `g_pConfig`.
  - Metadata/link/score/coverage/source-placement changes: no score/owner/emitter change.
- Support path: `by-class/OldUserStatusPane.md` ([UID:00009U]).
  - Exact facts to incorporate: movement helper C++ uses current config global name `g_pConfig`; the helper gate must include early false return for nonnegative direction when active-map/config gate is active; field id `12` position invalidation remains supported by UID000496.
  - Metadata/link/score/coverage/source-placement changes: no score/owner/emitter change.
- Support path: `by-file/UserStatusPane.md` ([UID:0000P2]).
  - Exact facts to incorporate: historical B002-era marker-only OldUserStatusPane generated-output caveat is superseded by current generated `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` header `000000007740`, which includes UID000495-UID00049B method bodies. Generated output remains lead material, not proof.
  - Metadata/link/score/coverage/source-placement changes: no score/owner/emitter change.
- Support path: `by-memory/0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md` ([UID:00049B]).
  - Exact facts to incorporate: none required; already documents router-called status payload. Treat as already-present support context.
  - Metadata/link/score/coverage/source-placement changes: none.

## Score And Metadata Recommendation

- Current score/metadata after implementation callback: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR`.
- Historical/pre-callback score/metadata: `COMPLETION:86`, `CONFIDENCE:89`, same owner/reconstructable/emitter. The accepted score recommendation was `89/91` and has been applied.
- Score rationale and reason not higher/lower:
  - Completion rose because the page now records current MCP bytes/xrefs/table/instruction evidence, exact no-entry state, direction gate semantics, current global-name support, and corrected formal C++.
  - Confidence rose because the behavior bug is resolved and support names align with current global docs.
  - Scores stay below `95` because raw entry remains uncalled/no-entry, exact original helper/global names are reconstructed, and `packet[10]` source role remains unknown beyond a discarded read.
- Score-improvement attempt:
  - No-entry blocker: checked `lookup_funcs`, `xrefs_to`, `find code_ref`, `find data_ref`, immediate searches, and VA/RVA pointer byte searches; result remains no-entry.
  - Pointer/table blocker: found only internal table pointer for `0x005bf660`, no entry pointer.
  - C++ correctness blocker: resolved with target/sibling instruction-level gate recheck.
  - Global-name blocker: resolved to `g_pConfig` using current exact config storage docs.
  - Invalidation id blocker: resolved by UID000496 rectangle equivalence.
  - Source placement blocker: resolved to existing class/aggregate/file route; no retarget.
- Metadata fields to change or leave unchanged:
  - Change `COMPLETION` and `CONFIDENCE` only.
  - Leave owner/emitter/reconstructable and filename/range unchanged.

## Open Questions With Attempted Resolution

- Open question: exact original helper spelling for the active-map/config high-bit gate.
  - Evidence checked: raw `sub_5055D0` call, config byte check, B002 helper name, current support docs.
  - Best supported resolution: keep a source-facing helper such as `ShouldMaskLegacyMovementDirection`, but change its meaning/signature so direction handling stays explicit in the method. Exact original spelling remains unresolved but does not block formal C++.
- Open question: exact original `Config` field name at `+0x28de75`.
  - Evidence checked: UID00028Q config storage page, known field cluster, raw target instructions.
  - Best supported resolution: use `g_pConfig` for pointer name and keep field hidden inside a source helper. Do not expose raw `+0x28de75` in final target C++.
- Open question: semantic role of `packet[10]`.
  - Evidence checked: target and sibling instructions read `packet+0x0a` through `std::_Narrow_char_traits<char,int>::to_char_type`, return unused.
  - Best supported resolution: keep `(void)packet[10];` marker and document as a discarded packet byte. More packet-layout work would be needed to name it, but that uncertainty does not alter observed target behavior.
- Open question: can no-entry status be resolved to a live caller?
  - Evidence checked: current xrefs, code/data refs, immediates, pointer bytes, router snippet, sibling/status context.
  - Best supported resolution: no live caller found. Keep no-entry as confidence cap, not as reason to unemit.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual coverage report or tracker edit is requested. Validator-owned generated tracker/coverage files should refresh through scoped validators after supervisor-approved by-* edits.

## Follow-Up Actions

- Current supervisor next action: re-audit this repaired current report artifact for Gate 1 from report text alone.
- If current-artifact Gate 1 passes: supervisor should perform Gate 2 claim verification against the changed target/support docs, report ledger/checklist, validator outputs `000000007769` through `000000007773`, and generated-output freshness notes.
- If both gates pass: only the supervisor may run `execute_report`; B007 must not run `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, manual report moves, or report registry commands.
- Later optional work: a broader Config/packet-layout pass may refine field/helper original spellings, but it is not blocking UID000499 source-quality correction.

## Confidence

- Recommendation confidence: high for behavior correction, owner/emitter route, and table disposition.
- Score confidence: medium-high; `89/91` is justified after incorporation but should not exceed low 90s.
- Remaining uncertainty: exact original source spellings for the movement gate helper, config field, and `packet[10]` role.

## Validator Results

- Current Gate 1 repair pass: no validators were run because this repair edited only the report text in the B007 research folder and did not edit by-* docs.
- Commands run from `source-3/project-documentation` during implementation callback:
  - `python .\tools\validator.py --mode file --file by-memory\0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md --apply --queue-timeout 240`
    - `command_id: 000000007769`
    - `command_timestamp: 2026-07-07T01:56:03-04:00`
    - Result: exit `0`, `ok: 1`, `completion_update 000499 ... 89`, `confidence_update 000499 ... 91`, `autogen_registry_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md --apply --queue-timeout 240`
    - `command_id: 000000007770`
    - `command_timestamp: 2026-07-07T01:56:09-04:00`
    - Result: exit `0`, `ok: 1`, `autogen_registry_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005bda40-0x005bfbc1.OldUserStatusPane.md --apply --queue-timeout 240`
    - `command_id: 000000007771`
    - `command_timestamp: 2026-07-07T01:56:20-04:00`
    - Result: exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class\OldUserStatusPane.md --apply --queue-timeout 240`
    - `command_id: 000000007772`
    - `command_timestamp: 2026-07-07T01:56:33-04:00`
    - Result: exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file\UserStatusPane.md --apply --queue-timeout 240`
    - `command_id: 000000007773`
    - `command_timestamp: 2026-07-07T01:56:42-04:00`
    - Result: exit `0`, `ok: 1`, `missing_ref_uid: 2` for pre-existing references `0003A8` and `0003AF`, `generated_refresh: deferred`.
- Generated-output freshness: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` now has header `validator-command-id: 000000007773`, `validator-refreshed-at: 2026-07-07T01:56:42-04:00`, and `validator-refresh-source: deferred-generated-refresh`. The generated body includes UID000499 at `89/91` and both movement helpers use `ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pConfig)` with the early false return.
- Any unresolved validator warnings/errors: no blocking validator errors. The by-file validator reported existing `missing_ref_uid` warnings for `0003A8` and `0003AF`.
- Explicitly not run: `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, manual report moves, generated-file edit commands, coverage-report edit commands, supervisor-ledger edits, or manual validator-state edits.

## Changed Files

- Modified during current same-report Gate 1 repair:
  - `tools/leaser/Agents/Agent-B007/research/000499-OldUserStatusPaneApplyLegacyMovementStep-source-quality.md`
- Created during report-only pass:
  - `tools/leaser/Agents/Agent-B007/research/000499-OldUserStatusPaneApplyLegacyMovementStep-source-quality.md`
- Modified manually during implementation callback:
  - `by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md`
  - `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md`
  - `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md`
  - `by-class/OldUserStatusPane.md`
  - `by-file/UserStatusPane.md`
  - `tools/leaser/Agents/Agent-B007/research/000499-OldUserStatusPaneApplyLegacyMovementStep-source-quality.md`
- Validator-owned generated artifacts refreshed or state-updated by the five scoped validators only, not by manual edits:
  - `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp`
  - generated coverage/tracker artifacts updated by validator output, including `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-class-coverage.md`, and `auto-generated/-ag-file-coverage.md`.
- Renamed:
  - None.
- Report execution: not run. B agents must not run `execute_report` or equivalent lifecycle/archive commands.

## Leases Used And Released

- Current Gate 1 repair pass: no leases were needed because only the B007-owned research report was edited.
- Lease command: `python .\tools\leaser\leaser.py B007 lease by-memory\0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md by-memory\0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md by-memory\0x005bda40-0x005bfbc1.OldUserStatusPane.md by-class\OldUserStatusPane.md by-file\UserStatusPane.md`
- Lease result: success for all five paths.
- Release command: `python .\tools\leaser\leaser.py B007 unlease by-memory\0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md by-memory\0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md by-memory\0x005bda40-0x005bfbc1.OldUserStatusPane.md by-class\OldUserStatusPane.md by-file\UserStatusPane.md`
- Release result: success for all five paths; `current_leases.md` check found no remaining B007 entries for these paths.

## Implementation Tracking Checklist

Historical initial report-only pass:

- [x] Supervisor validation required before implementation: Gate 1 passed in `tools/leaser/Agents/b-report-validation-audit.md` entry `2026-07-07T01:48:37-04:00 - B007 UID000499 Gate 1 Passed`.
- [x] Target/support docs to update: target UID000499; support UID00049A for same C++ gate/name fix; support UID0001NR and UID00009U for current evidence/name text; support UID0000P2 for stale generated-output caveat; UID00049B already-present context only.
- [x] Current target state and actual evidence checked recorded: MCP session `supervisor-nexustk-20260707`, lookup/xref/find_bytes/get_bytes/insn_query/decompile failure/int_convert results incorporated or preserved above.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows B007-499-C01 through B007-499-C13 now show `incorporated`, `already-present`, or verified state.
- [x] Metadata/score changes applied: UID000499 `COMPLETION:86 -> 89`, `CONFIDENCE:89 -> 91`; no support score changes applied.
- [x] Score-limiting blockers researched to resolution: no-entry remains as documented cap; C++ fidelity, table ownership, global name, invalidation id, and source placement blockers resolved into implementation edits.
- [x] Owner/emitter/reconstructable changes to apply: none; preserved `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR`.
- [x] Split/rename/new-child changes to apply: none; preserved target range and table containment.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: evidence text only; no IDA edits requested or made.
- [x] First-draft C++ or no-code proof applied: UID000499 formal C++ replaced with exact recommended block; UID00049A updated with same gate/name change using method name `ApplyLegacyMovementStepAlt`.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: no-entry/pointer searches, raw high-bit gate early return, table bytes/xref, `g_pConfig` name, field id 12 rectangle equivalence, generated-output current state.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: no-entry status, no target router call, no MapPane/Config ownership, stale `g_pGameConfig`/marker-only generated output caveats historicalized where in scope.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: old simroot/generated references treated as historical only.
- [x] Open questions closed or documented as evidence-backed unresolved: helper original spelling, Config field spelling, `packet[10]` role, and no-entry liveness remain documented unresolved caps.
- [x] Validators run after callback from `source-3/project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x005bda40-0x005bfbc1.OldUserStatusPane.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-class\OldUserStatusPane.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file\UserStatusPane.md --apply --queue-timeout 240`
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated files refreshed through validators only; `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` now has command header `000000007773`, timestamp `2026-07-07T01:56:42-04:00`, and corrected UID000499/UID00049A bodies.

Historical implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator; coverage/tracker artifacts were touched only by scoped validator commands, not manual edits.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

Current same-report Gate 1 repair pass:

- [x] Restored exact core heading `## Current Target State`.
- [x] Labeled pre-callback target state as historical/pre-callback detail and added accurate current implemented/review state.
- [x] Replaced stale `## Follow-Up Actions` lifecycle wording with current Gate 1 re-audit, Gate 2 claim verification, and supervisor-only `execute_report` sequence.
- [x] Scanned and repaired other stale current-state/lifecycle wording in `Supporting Research`, `Target`, `Current Target State`, `Supervisor Active Recheck`, `First-Draft C++ Recommendation`, `Score And Metadata Recommendation`, `Validator Results`, `Changed Files`, `Leases Used And Released`, and this checklist.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000007790","destination_path":"executed-b-agent-research/B007/000499-OldUserStatusPaneApplyLegacyMovementStep-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/000499-OldUserStatusPaneApplyLegacyMovementStep-source-quality.md","timestamp":"2026-07-07T02:20:26-04:00","uid":"000499"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
