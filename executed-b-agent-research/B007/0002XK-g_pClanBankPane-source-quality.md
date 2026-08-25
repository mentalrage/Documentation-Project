** TARGET-REPORT-UID:0002XK **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002XK g_pClanBankPane Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation/status: supervisor Gate 1 passed and the accepted implementation callback changes have been applied. [UID:0002XK] `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md` now carries current MCP byte/xref/boundary proof, remains an exact four-byte storage child, and keeps formal C++ marker-only. The single source-level global definition remains on [UID:0002XJ] `by-global/g_pClanBankPane.md`.
- Final disposition: source-declared/global storage, not a standalone raw data definition. Target [UID:0002XK] should not emit `ClanBankPane *g_pClanBankPane;`, `= NULL`, `= nullptr`, `dword_67ADE8`, or any duplicate initializer.
- Required action/status: implementation callback is complete; report is not executed, archived, lifecycle-moved, or manually moved. Awaiting supervisor execute/Gate 2 handling.
- Confidence: high. Current IDA MCP session `supervisor-nexustk-20260707` confirms zero bytes/value, exactly seven address-literal/xref uses, no successor `0x0067adec` xrefs, the `0x0048c260` cleanup helper shape, and no named IDB symbol at `0x0067ade8`.

## Supporting Research
- Lifecycle/status notes: initial report-only research passed supervisor Gate 1; this implementation callback applied only the accepted target/support by-* documentation changes, updated this report, ran scoped validators for changed by-* docs, and performed read-only generated-output checks. No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, manual report move, registry lifecycle command, supervisor-ledger edit, queue/lock edit, IDA DB edit, manual generated-file edit, manual coverage edit, or validator-state edit was performed.
- Report path: `tools/leaser/Agents/Agent-B007/research/0002XK-g_pClanBankPane-source-quality.md`.
- IDA MCP status: `idb_list` returned one active adopted worker session, `supervisor-nexustk-20260707`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, PID/worker PID `14640`, `is_analyzing:false`. `server_health` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- One broad `search_text` scan for `67ADE8` across executable code timed out at the client-side 30 second command limit. A health probe immediately after also timed out while the worker was busy. After a 10 second wait, `server_health` returned `ok`; all subsequent focused MCP calls succeeded. The broad search output is not used as evidence.
- Initial report-only pass ran no validators and took no leases. Implementation callback leases were taken for five by-* docs at `2026-07-07T07:43:43Z`; validators ran through command `000000007844`; the leases expired at `2026-07-07T07:48:43Z` during the validator batch, and the post-validator unlease command returned `Rejected[No active lease]` for all five paths. A follow-up lease-file read showed no active leases.

## Target
- Target UID: `0002XK`.
- Target path: `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md`.
- Source queue/report row: pre-callback tracker row was `86/89`, combined `87.5`, reconstructable `true`, direct report count `0`. After scoped validators, generated tracker rows show [UID:0002XK] at `89/92` and parent [UID:0002XJ] at `88/91`.
- Current supervisor classification: implementation callback after supervisor Gate 1 pass; IDA MCP evidence remains mandatory for the source-quality claim set.
- Current scores and parent state: target [UID:0002XK] is `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:0002XJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0002XJ`. Parent [UID:0002XJ] `g_pClanBankPane` is `88/91`, owner/emitter [UID:0000I9] `ClanBank`.

## Current Target State
- Existing metadata: [UID:0002XK] is a reconstructable by-memory storage child assigned to [UID:0002XJ], now scored `89/92`.
- Existing owner/emitter/reconstructable state: owner/emitter [UID:0002XJ] is correct. [UID:0002XJ] routes through [UID:0000I9] `ClanBank` / `auto-generated/NexusTK/social/ClanBank.cpp`.
- Existing C++/emitter state: target formal C++ is marker-only. Parent [UID:0002XJ] emits:

```cpp
ClanBankPane *g_pClanBankPane;
```

- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: older `0xffffffff` wording is corrected in current target/support docs, including the aggregate support change-log line repaired during this callback. Old reports may still include historical `0xffffffff` examples elsewhere. The target preserves zero-filled virtual `.data` wording and avoids reintroducing `dword_67ADE8`/IDA-auto-name language as source.
- Related target/support docs checked: `by-global/g_pClanBankPane.md`, `by-class/ClanBankPane.md`, `by-file/ClanBank.md`, `by-file/Clan.md`, `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`, `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md`, `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md`, `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md`, `by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md`, neighbor `g_pClanStatusPane` docs, and neighbor `g_pChattingHandlePane` docs.
- Current artifact/lifecycle status: implementation callback is complete and awaiting supervisor execute/Gate 2 handling. This report has not been executed, archived, lifecycle-moved, or manually moved.

## Executive Recommendation
- Best direct owner: keep [UID:0002XJ] `g_pClanBankPane` as direct owner of the storage child.
- Source file route: keep [UID:0000I9] `ClanBank` / `NexusTK/social/ClanBank.cpp`.
- Split/container disposition: no new split. [UID:0002XK] is already the exact half-open four-byte child `0x0067ade8-0x0067adec`; successor `0x0067adec` has no xrefs and the next named entity is `WideCharStr` at `0x0067adf0`.
- Metadata disposition: implemented target score `86/89 -> 89/92`; kept `CANONICAL_OWNER:0002XJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0002XJ`, and blank `EMITTER_POSITION_OPTIONAL`.
- Formal global-definition/no-code disposition: parent [UID:0002XJ] emits the single global definition `ClanBankPane *g_pClanBankPane;`. Target [UID:0002XK] remains marker-only storage proof and must not emit duplicate C++.

## Supervisor Active Recheck
- Triggering instruction: the supervisor assigned a report-only first pass for UID0002XK, Gate 1 passed on the current artifact, and the supervisor then issued an implementation callback with scoped target/support edits and validators.
- Split repair before final master report: not required. The target is already split to exact four bytes; current MCP confirms no interior or successor xrefs requiring a split adjustment.
- Source-bearing child status: [UID:0002XK] is source-bearing only as generated-binary storage evidence for the parent global. There is no separate handwritten initializer/body to create. The source-bearing parent definition already exists in [UID:0002XJ].

## Inference Research Guidance Check
- `by-structure.md` supports treating by-global pages as process-wide singleton/global ownership routes and by-memory data children as exact storage evidence. For source-declared/generated-binary storage, the source declaration/definition can live on the semantic global page while the exact binary storage child records bytes, xrefs, and section/boundary proof.
- Existing documentation assumptions treated as uncertain and rechecked: the seven-xref count, zero-filled value, successor boundary at `0x0067adec`, cleanup-helper classification at `0x0048c260`, parent/global versus storage-child emission, and generated `dword_67ADE8` risk.
- IDA facts: current bytes, xrefs, address-literal search, functions, decompilation, disassembly, names/globals query, and health/session metadata.
- Documentation evidence: current by-* docs, generated tracker/coverage rows, generated `ClanBank.cpp`, and executed B-agent reports.
- Inference: `g_pClanBankPane` is a source-facing global name from project docs and generated output, not an IDA recovered symbol; the uninitialized global definition is the most plausible source shape because the binary storage is zero-filled virtual `.data`.
- Wave2/Wave3 artifacts: none found in the relevant current docs/report search. Older stale `0xffffffff` wording is treated as historical and superseded by current MCP evidence.

## Heuristic / Inference Reanalysis And Validation
- Exact bytes and boundary: `get_bytes 0x0067ade8 size 4`, `get_int u32le`, and `get_global_value` all report zero. The aggregate `0x0067adc4` 44-byte read is all zero. `0x0067adec` is also zero but has zero xrefs; it is not part of this target. `entity_query` around `0x0067ade0-0x0067adf0` finds only `WideCharStr` at `0x0067adf0`.
- Seven-xref count: `xrefs_to 0x0067ade8` reports exactly seven refs, `more:false`. `find_bytes E8 AD 67 00` independently returns exactly seven address-literal matches at operand-byte offsets corresponding to those refs.
- Write/clear/read roles: constructor `sub_48B1C0` writes `this` at `0x0048b224` and has a decompiler fallback clear at `0x0048b22b`; vtable-reset/destructor-tail `sub_48B600` clears at `0x0048b61a`; cleanup helper `sub_48C260` clears at `0x0048c260`; scalar deleting destructor `sub_48C410` clears at `0x0048c430`; dispatcher/open paths read at `0x00508706` and `0x00513b07` before allocating/constructing `ClanBankPane`.
- Cleanup-helper classification: `get_bytes 0x0048c260 size 12` reads `c7 05 e8 ad 67 00 00 00 00 00 c3 cc`; `disasm(0x0048c260)` has only `mov dword ptr unk_67ADE8, 0` and `retn`. This is cleanup/EH/lifecycle support, not a handwritten source method.
- Source-level global definition: current generated `ClanBank.cpp` has an `extern ClanBankPane *g_pClanBankPane;` in the class-shell area and a single [UID:0002XJ] definition `ClanBankPane *g_pClanBankPane;`. That source shape matches static zero initialization without spelling an explicit initializer. Do not duplicate it in [UID:0002XK].
- IDA name versus source name: IDA currently renders the operand as `unk_67ADE8` and has no named global at `0x0067ade8`. Project docs and generated source use source-facing `g_pClanBankPane`. No IDA rename is required or recommended in this report.
- Neighboring singleton style: [UID:0002XF] `g_pChattingHandlePane` uses the same parent-global definition / storage-child marker pattern as this recommendation. [UID:0002XH] `g_pClanStatusPane` currently uses the opposite emission split, with the storage child emitting `ClanStatusPane *g_pClanStatusPane = NULL;` and the global page emitting `[[CHILDREN]]`; that was an accepted Clan-specific B007 callback and should be treated as historical neighboring style, not copied into this ClanBank target.
- Generated/coverage state after callback validators: `auto-generated/NexusTK/social/ClanBank.cpp` is current to validator command `000000007844` at `2026-07-07T03:49:01-04:00`, source `deferred-generated-refresh`. It contains [UID:0002XJ] with `ClanBankPane *g_pClanBankPane;` and no `UID:0002XK` standalone block, no `Empty Emitter Marker`, no `dword_67ADE8`, and no `unk_67ADE8`. Generated tracker rows now show [UID:0002XK] `89/92` and [UID:0002XJ] `88/91`.
- Owner alternatives rejected: [UID:0000I8] `Clan` owns neighboring `g_pClanStatusPane` but not this bank UI singleton; [UID:0002B5] is a mixed split index; [UID:00010T] is a mixed destructor/cleanup map; `ClanBankPane` class docs are class context but not the direct by-memory storage parent; IDA auto-name `unk_67ADE8`/`dword_67ADE8` is not a source owner.

## Evidence Standards Used
- Evidence types used: IDA MCP `idb_list`, `server_health`, `get_bytes`, `get_int`, `get_global_value`, `xrefs_to`, `lookup_funcs`, `decompile`, `disasm`, `find_bytes`, and `entity_query`; generated source read-only checks; by-* target/support docs; executed B-agent reports; and negative boundary/name/xref checks.
- Evidence strength: direct MCP byte/xref/function facts agree with existing docs and generated output. The address-literal search independently corroborates the xref count. The helper disassembly confirms B014's cleanup classification.
- Confidence limits: no original source symbol table proves exact declaration spelling or whether the developer wrote an explicit `= NULL`. IDA has only `unk_67ADE8`, so `g_pClanBankPane` is source-facing project nomenclature. Those limits cap confidence below final.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed: session/health probes; byte reads for `0x0067ade8`, `0x0067adc4`, `0x0067adec`, `0x0067ade4`, and `0x0048c260`; integer/global reads for `0x0067ade8`, `0x0067adec`, and `0x0067ade4`; xrefs to `0x0067ade8`, `0x0067adec`, and `0x0067ade4`; function lookup for the seven xref functions; decompile of `0x0048b1c0`, `0x0048b600`, `0x0048c260`, `0x0048c410`, `0x00507c90`, and `0x00513ab0`; disasm of `0x0048c260`; `find_bytes` for little-endian address literals `E8 AD 67 00`, `EC AD 67 00`, and `E4 AD 67 00`; names/globals query around `0x0067ade0-0x0067adf0`.
- by-* docs checked: target [UID:0002XK], parent [UID:0002XJ], class [UID:000026], file [UID:0000I9], file [UID:0000I8], aggregate [UID:0002B5], source ranges [UID:00010R], [UID:00021Y], [UID:00010S], [UID:00010T], neighbor [UID:0002XH]/[UID:0002XG], and neighbor [UID:0002XF]/[UID:0002XE].
- Old reports searched: required terms `TARGET-REPORT-UID:0002XK`, `0002XK`, `0x0067ade8`, `0x0067adec`, `g_pClanBankPane`, `ClanBankPane`, `ClanBank`, `UiChatClanSingletonSlots`, `ClanBankPaneConstructor`, `ClanBankPaneDestructor`, `ClanBankPaneRawPacketHelpers`, `ClanDestructorBand`, `ClanBankItemListPane`, `ClanItemDialog`, `g_pClanStatusPane`, `g_pChattingHandlePane`, `0002XJ`, `000026`, `0000I9`, `0000I8`, `0002B5`, `00010R`, `00021Y`, `00010S`, `00010T`, and `0002XH`.
- Old-report search results: no exact `TARGET-REPORT-UID:0002XK` hit. Direct UID0002XK hit: `executed-b-agent-research/B009/0000I9-ClanBank-empty-emitter-family-source-quality.md`. Key support hits: B010 `00021Y-ClanBankPaneRawPacketHelpers-source-quality.md`, B014 `00010T-ClanDestructorBand-source-routing.md`, B007 `0000I8-Clan-empty-emitter-family-source-quality.md`, and B015 `00002K-ClanStatusPane-class-source-quality.md`. Broad Clan/Chatting terms had many support hits; only the listed reports were opened as relevant leads.
- Generated reports/trackers checked: `auto-generated/NexusTK/social/ClanBank.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-global-coverage.md`, and `auto-generated/-ag-coverage-report-by-memory.md`.
- Negative checks performed: no xrefs to `0x0067adec`; no address-literal matches for `EC AD 67 00`; no IDB names/globals at `0x0067ade8`; no generated `dword_67ADE8`; no target `UID:0002XK` block in generated `ClanBank.cpp`; no exact direct prior target report.
- Failed, unavailable, or intentionally skipped checks and why: a broad `search_text` scan timed out during initial research and was replaced by focused xref and byte-pattern checks. Initial report-only validators were intentionally skipped. During implementation, only the scoped by-* file validators listed below were run; `execute_report`, lifecycle/archive commands, registry lifecycle commands, manual report moves, IDA DB edits, and manual generated/coverage/validator-state edits were not run.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002XK-01 | `0x0067ade8-0x0067adec` is exact four-byte zero-filled storage for `g_pClanBankPane`. | High | MCP bytes/int/global reads; aggregate all-zero read. | Target Status/Evidence/Score Rationale. | Incorporated in target Status/Evidence and aggregate support note; validators `000000007840` and `000000007842` passed. | applied |
| C-0002XK-02 | Seven current refs to `0x0067ade8` are accurate. | High | `xrefs_to` count 7; `find_bytes E8 AD 67 00` count 7. | Target Evidence; parent global Evidence; class/file support notes. | Incorporated in target, parent, class support, and file support; validators `000000007840`, `000000007841`, `000000007843`, and `000000007844` passed. | applied |
| C-0002XK-03 | `0x0067adec` is not part of this target and has zero xrefs. | High | `xrefs_to 0x0067adec` count 0; `find_bytes EC AD 67 00` count 0. | Target Range/Boundary note; aggregate support note. | Incorporated in target, parent, and aggregate support; validators `000000007840`, `000000007841`, and `000000007842` passed. | applied |
| C-0002XK-04 | `0x0048c260-0x0048c26b` is a clear-and-return cleanup helper, not a source method. | High | `get_bytes`, `disasm`, `decompile`, B014 report/docs. | Target Evidence; [UID:00010T] already-present support. | Incorporated in target and class support; destructor-band doc already had same-or-greater B014 cleanup classification and was not edited. | applied |
| C-0002XK-05 | Parent [UID:0002XJ] should emit the single source global definition. | High | B009 implementation; generated `ClanBank.cpp`; source-declared/generated-binary rules. | `by-global/g_pClanBankPane.md`; target formal marker. | Incorporated in parent global and target exact marker; validators `000000007841` and `000000007840` passed. | applied |
| C-0002XK-06 | Target [UID:0002XK] should remain marker-only/no duplicate C++. | High | Storage child role; generated output has no standalone UID0002XK block; no separate initializer. | Target formal C++ block. | Exact formal marker applied to target; generated read-only check after command `000000007844` found no standalone UID0002XK block. | applied |
| C-0002XK-07 | Do not emit `dword_67ADE8`/`unk_67ADE8` as source. | High | IDB names query lacks source symbol at target; generated output uses `g_pClanBankPane`. | Target/parent wording; generated-output notes. | Incorporated in target, parent, and file support notes; generated read-only check after command `000000007844` found no `dword_67ADE8` or `unk_67ADE8`. | applied |
| C-0002XK-08 | ClanBank remains the correct source-file route. | High | Constructor/action/destructor refs in ClanBankPane; parent global owner; B009/B010 docs. | Parent global; by-file ClanBank support. | Incorporated in parent global and by-file ClanBank support; validators `000000007841` and `000000007844` passed. | applied |
| C-0002XK-09 | Clan and Chatting neighbor singleton routes are support context, not ownership for this target. | Medium-high | Neighbor docs and distinct xref families. | Negative Evidence; support-doc recommendations. | Read/check-only neighbor docs remained consistent and no contradiction required edit; supervisor scope did not require neighbor edits. | excluded-with-reason |
| C-0002XK-10 | Generated current rows are read-only and should refresh only through scoped validators after accepted by-* edits. | High | Generated header `000000007844` after validators; report-only/callback rules. | Validator/Generated notes. | Scoped validators `000000007840` through `000000007844` ran; generated `ClanBank.cpp` refreshed to command `000000007844` and was checked read-only. | applied |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation: zero-filled storage; seven exact refs; constructor writes and dispatcher reads; destructor/reset/cleanup clears; no successor refs; no IDB source name; generated parent declaration already present.
- Corroborating documentation/generated-report evidence: B009 accepted `ClanBankPane *g_pClanBankPane;` from [UID:0002XJ] and marker-only storage child [UID:0002XK]; B010/B014 support docs agree on `ClanBankPane`/cleanup-helper behavior; generated `ClanBank.cpp` contains the parent declaration and no target empty marker.
- Strongest inference chain: current MCP proves a loader-zeroed pointer slot that is manipulated only by `ClanBankPane` lifecycle/open paths; project docs name that slot `g_pClanBankPane`; by-structure global/storage rules support one source global definition on [UID:0002XJ] and marker-only storage proof on [UID:0002XK].

## IDA MCP Facts
- Function/range facts: `lookup_funcs` reports `sub_48B1C0` size `0x433`, `sub_48B600` size `0x29`, `sub_48C260` size `0xb`, `sub_48C410` size `0x5f`, `sub_507C90` size `0x1176`, and `sub_513AB0` size `0x99`.
- Data/table/padding facts: `0x0067ade8`, `0x0067ade4`, `0x0067adec`, and the `0x0067adc4-0x0067adef` neighborhood read as zero. `0x0048c260` bytes are `c7 05 e8 ad 67 00 00 00 00 00 c3 cc`.
- Xref facts: `0x0067ade8` xrefs are `0x0048b224`, `0x0048b22b`, `0x0048b61a`, `0x0048c260`, `0x0048c430`, `0x00508706`, and `0x00513b07`. `0x0067adec` has zero xrefs. Neighbor `0x0067ade4` has 15 xrefs.
- Vtable/global/type facts: decompile of constructor/destructor paths shows `ClanBankPane` vtable stores and clears. `entity_query` names/globals over `0x0067ade0-0x0067adf0` finds only `WideCharStr` at `0x0067adf0`; no named symbol exists at `0x0067ade8`.
- Negative IDA facts: no source symbol at `0x0067ade8`, no xrefs or address-literal matches for successor `0x0067adec`, and the cleanup helper is not a method body.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0067ade8-0x0067adec` | [UID:0002XK] `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md` | exact storage child | yes | [UID:0002XJ] | implemented `89/92` | target proof refreshed, marker-only |
| `0x0067ade8` global | [UID:0002XJ] `by-global/g_pClanBankPane.md` | canonical source global | yes | [UID:0000I9] | implemented `88/91` | definition kept, evidence refreshed |
| `0x0067adc4-0x0067adec` | [UID:0002B5] `UiChatClanSingletonSlots` | mixed singleton split index | false | none | `86/92` | already-present support; optional current note |
| `0x0048b1c0-0x0048b7dc` | [UID:00010R] `ClanBankPane` | constructor/action/reset range | yes | [UID:0000I9] | `88/90` | already-present support |
| `0x0048b7e0-0x0048b8bc` | [UID:00021Y] `ClanBankPaneRawPacketHelpers` | retained raw helper island | yes, marker/no-code | [UID:0000I9] | `88/90` | already-present support |
| `0x0048b8c0-0x0048c251` | [UID:00010S] `ClanBankItemListPane` | child list parser/draw | yes | [UID:0000I9] | `88/90` | already-present support |
| `0x0048c260-0x0048c63f` | [UID:00010T] `ClanDestructorBand` | mixed cleanup/thunk/destructor map | no | none | `88/91` | already-present support |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0048b224` | `sub_48B1C0` | constructor publishes `this` into `g_pClanBankPane` |
| `0x0048b22b` | `sub_48B1C0` | decompiler fallback/null clear branch |
| `0x0048b61a` | `sub_48B600` | vtable-reset/destructor-tail clears singleton |
| `0x0048c260` | `sub_48C260` | cleanup helper stores zero and returns |
| `0x0048c430` | `sub_48C410` | scalar deleting destructor wrapper clears singleton |
| `0x00508706` | `sub_507C90` | packet dispatcher duplicate-open guard before constructing `ClanBankPane` |
| `0x00513b07` | `sub_513AB0` | clan-bank route duplicate-open guard before constructing `ClanBankPane` |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: current target and parent docs already record zero-filled virtual `.data`, seven xrefs, [UID:0002XJ] parent, and [UID:0000I9] source route. `ClanBankPane`, `ClanBank`, `ClanDestructorBand`, and raw-helper docs already contain the B009/B010/B014 support facts.
- Existing docs that are stale, incomplete, or contradicted: no current by-* target/support contradiction remains for `0xffffffff`; callback validators refreshed generated/tracker rows to target `89/92` and parent `88/91`. Neighbor [UID:0002XH] uses a different accepted emission split; do not treat that as a required style for this target.
- Generated/coverage report state: `auto-generated/NexusTK/social/ClanBank.cpp` is validator-current and contains [UID:0002XJ] definition only for the global. `auto-generated/-ag-memory-coverage.md` and `-ag-coverage-report-by-memory.md` still render [UID:0002XK] as coded/emits_code through the storage page; B009 notes this can be acceptable because the storage child is applied through the parent global block, not as a standalone generated UID section.

## Ranked Ownership Analysis

### 1. [UID:0002XJ] g_pClanBankPane
- Evidence for: direct by-global page for address `0x0067ade8`; generated source definition; target owner/emitter already set to [UID:0002XJ]; xrefs all manipulate/consume `ClanBankPane` singleton state.
- Evidence against: IDA has no recovered named global at `0x0067ade8`, so symbol spelling is project/source-facing rather than IDA-derived.
- Decision: keep as direct owner/emitter and source-global route.

### 2. [UID:0000I9] ClanBank
- Evidence for: parent global owner/emitter; constructor/action/destructor and raw helper docs route through `ClanBank.cpp`; generated source file contains the definition.
- Evidence against: by-memory target should not skip the by-global direct owner and attach directly to the file while [UID:0002XJ] exists.
- Decision: keep as file/source route through [UID:0002XJ], not direct target owner.

### 3. [UID:000026] ClanBankPane
- Evidence for: all lifecycle xrefs are class-context constructor/destructor/action/open paths.
- Evidence against: class context is not the direct global-storage owner in project documentation; the by-global page exists and emits the definition.
- Decision: support context only.

### 4. Rejected alternatives
- [UID:0000I8] `Clan`: owns neighboring ClanStatus state, but not the bank item/gold pane singleton.
- [UID:0002B5] aggregate: split index only; no source owner.
- [UID:00010T] destructor band: lifecycle cleanup support only; mixed owner/no-code aggregate.
- `unk_67ADE8`/`dword_67ADE8`: IDA auto labels; reject as source names.

## Source Placement
- Recommended source file/class/global/module placement: [UID:0002XJ] global definition emitted through [UID:0000I9] `ClanBank` / `NexusTK/social/ClanBank.cpp`.
- Why this placement fits source-tree and subsystem context: the global is constructed/guarded/destroyed by `ClanBankPane`, and `ClanBank.cpp` already carries the class shells and method bodies for this UI family.
- Rejected placements and why: `Clan.cpp` is for ClanStatus/list/dialog state; Chatting docs are neighbor storage only; Socket/PacketBuffer are only packet support; raw destructor band is cleanup support.
- Remaining placement uncertainty: exact original header/source declaration split is not recovered. Current generated source shape is sufficient for first-draft source reconstruction.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: [UID:0002XK] covers `0x0067ade8-0x0067adec`, four bytes. Prior slot `0x0067ade4-0x0067ade8` is [UID:0002XH] `g_pClanStatusPane`; successor `0x0067adec` has no xrefs; `WideCharStr` begins at `0x0067adf0`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new child, rename, merge, or reclassification recommended.
- Padding/table/data/code distinctions: target is non-code `.data` storage, zero-filled by loader/virtual `.data`; it is not a source-authored initializer table or executable helper.
- Parent/container impact: [UID:0002B5] remains an aggregate split index. Target and parent global carry the source/byte proof.

## Negative Evidence Summary
- `0x0067adec` is rejected as part of the target because xrefs and address-literal matches are zero.
- `dword_67ADE8`/`unk_67ADE8` is rejected as source-facing output because IDA does not recover `g_pClanBankPane` and generated source already uses the project global name.
- An explicit initializer is not proven. `ClanBankPane *g_pClanBankPane;` is enough to produce zero initialization at static storage duration; current bytes do not require `= NULL` or `= nullptr`.
- A standalone target C++ definition is rejected because it would duplicate [UID:0002XJ].
- Direct ownership by `ClanBankPane`, `ClanBank`, `Clan`, `Chatting`, or the destructor band is rejected because the by-global direct owner already exists and has the source definition route.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: use `g_pClanBankPane` and type `ClanBankPane *` in docs/generated source. If IDA DB comments are ever allowed, `0x0067ade8` could be commented as the `g_pClanBankPane` storage slot, but no IDA DB edit is requested or needed here.
- Evidence for each proposed name/type/comment: generated `ClanBank.cpp`, current by-global/class docs, constructor/destructor/open-path xrefs, and `ClanBankPane` vtables.
- Items intentionally left unchanged and why: no IDA rename from `unk_67ADE8`; no source `dword_67ADE8`; no cleanup-helper source prototype.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. This assignment is documentation-only; no IDA DB edit was made.

## First-Draft C++ Recommendation
- Eligible for draft C++: the parent global [UID:0002XJ] is eligible and already emits the first-draft source definition. Target [UID:0002XK] is not eligible for standalone source code beyond a formal marker comment.
- Recommended code: exact formal target insertion text for [UID:0002XK] after Gate 1 approval:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID0002XK is the exact zero-filled .data storage slot for g_pClanBankPane. The source-level definition is emitted once by UID0002XJ as ClanBankPane *g_pClanBankPane;, so this child must not emit a duplicate definition, initializer, or dword_67ADE8-style symbol.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Recommended parent global formal block for [UID:0002XJ], unchanged:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ClanBankPane *g_pClanBankPane;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: static-duration pointer definition with no explicit initializer is zero-initialized; target bytes are zero and all writes are runtime lifecycle writes.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: existing generated ClanBank source already declares class shell `extern ClanBankPane *g_pClanBankPane;` and defines the global once in the same source file.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `g_pClanBankPane` instead of `unk_67ADE8`; `ClanBankPane *` instead of raw `DWORD`.
- Naming/coding style convention used and evidence for consistency: project singleton global naming and current generated `ClanBank.cpp` convention.
- Reason code should remain blank, if applicable: [UID:0002XK] is not blank but marker-only; no duplicate source definition belongs there.
- Exact no-code proof, if not eligible: zero-filled storage child, direct parent global emits the source definition, no distinct initializer or source symbol at the storage child, and standalone target C++ would duplicate [UID:0002XJ].

## Final Recommendation
- Exact changes recommended: update target evidence/marker/score to current MCP proof; update parent global evidence/score while preserving the formal definition; optionally add a concise support note to the aggregate/class/file docs if supervisor wants current-session provenance distributed.
- Exact parent assignments recommended: keep target owner/emitter [UID:0002XJ]; keep parent global owner/emitter [UID:0000I9].
- Exact items left no-owner/non-emitting and why: [UID:0002B5] and [UID:00010T] remain non-emitting aggregate/support maps because they are mixed-owner indexes, not standalone source objects.
- Exact future work outside this assignment scope: no IDA rename/type/comment pass; no neighbor `g_pClanStatusPane` emission-style normalization unless assigned separately; no generated/manual coverage edit except validator-owned refresh after accepted by-* changes.

## Recommended Target Doc Changes
- Target path: `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md`.
- Exact report facts to incorporate: current MCP session `supervisor-nexustk-20260707`; zero bytes/value; seven xrefs and exact roles; zero xrefs to successor `0x0067adec`; `0x0048c260` two-instruction cleanup helper; parent [UID:0002XJ] emits the single source definition; no `dword_67ADE8`; no duplicate initializer; generated `ClanBank.cpp` has no standalone UID0002XK block and no empty marker.
- Metadata/score/owner/emitter/reconstructable/C++ changes: set `COMPLETION:89`, `CONFIDENCE:92`; keep `CANONICAL_OWNER:0002XJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0002XJ`, blank `EMITTER_POSITION_OPTIONAL`; replace or refresh the formal marker with the exact marker in `First-Draft C++ Recommendation`.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: older `0xffffffff` wording is historical; no direct child source definition; no source `unk_67ADE8`/`dword_67ADE8`; no split/merge/reclassification; cleanup helper is not a source method.

## Recommended Support Doc Changes
- Support path: `by-global/g_pClanBankPane.md`.
- Exact report facts to incorporate: current zero storage, seven xrefs, no successor xrefs, no IDB source name, parent/source definition remains `ClanBankPane *g_pClanBankPane;`, and [UID:0002XK] is marker-only storage.
- Metadata/link/score/coverage/source-placement changes: recommend `COMPLETION:88`, `CONFIDENCE:91`; keep owner/emitter [UID:0000I9], reconstructable true, and formal C++ unchanged.

- Support path: `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`.
- Exact report facts to incorporate: optional current-session support note that `0x0067ade8` remains seven-xref zero storage, `0x0067adec` has zero xrefs, and `0x0067adf0` is the next named `WideCharStr` item.
- Metadata/link/score/coverage/source-placement changes: no score/metadata change recommended.

- Support path: `by-class/ClanBankPane.md`.
- Exact report facts to incorporate: optional current-session support note confirming the same seven refs and roles, especially duplicate-open guards at `0x00508706` and `0x00513b07` plus cleanup clears at `0x0048b61a`, `0x0048c260`, and `0x0048c430`.
- Metadata/link/score/coverage/source-placement changes: no score/metadata/formal C++ change recommended; current class shell and `extern` declaration are already correct.

- Support path: `by-file/ClanBank.md`.
- Exact report facts to incorporate: optional current-session support note that [UID:0002XJ]/[UID:0002XK] source/global-storage split remains correct and generated output should not contain `dword_67ADE8`.
- Metadata/link/score/coverage/source-placement changes: no score/metadata/formal C++ change recommended.

- Support path: `by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md`.
- Exact report facts to incorporate: already present. Current MCP reconfirms B014's `0x0048c260-0x0048c26b` clear-and-return classification.
- Metadata/link/score/coverage/source-placement changes: no change recommended unless supervisor wants an explicit 2026-07-07 reconfirmation note.

- Support paths inspected but no change recommended: `by-file/Clan.md`, `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md`, `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md`, `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md`, `by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md`, `by-global/g_pClanStatusPane.md`, `by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md`, and `by-global/g_pChattingHandlePane.md`.

## Score And Metadata Recommendation
- Pre-callback score/metadata: target `86/89`, owner/emitter [UID:0002XJ], reconstructable true, marker-only formal block.
- Implementation result: target `89/92`, owner/emitter/reconstructable unchanged. Parent global [UID:0002XJ] is `88/91`, owner/emitter [UID:0000I9] unchanged.
- Score rationale and reason not higher/lower: completion improves because current MCP resolves the exact byte/xref/boundary/helper/no-duplicate-output questions and generated state has no target empty marker. Confidence improves because xref and byte-pattern counts agree. Scores stay below final because no original source symbol table or exact initializer spelling is recovered, and no compile/test proof exists.
- Score-improvement attempt: byte/value ambiguity resolved to zero; xref count revalidated; successor-boundary concern resolved by no-xref/no-literal evidence; cleanup helper resolved by disassembly; generated-name pollution checked in current output; neighbor style checked and rejected as a reason to change target style.
- Metadata fields to change or leave unchanged: only completion/confidence should change. Owner, emitter, reconstructable, and emitter position stay unchanged.

## Open Questions With Attempted Resolution
- Open question: should the parent or storage child emit the source definition? Evidence checked: B009 accepted callback, generated `ClanBank.cpp`, neighbor Chatting/ClanStatus docs, by-structure rules. Resolution: parent [UID:0002XJ] emits; child [UID:0002XK] marker-only.
- Open question: should the source definition include `= NULL` or `= nullptr`? Evidence checked: current bytes, generated source, old B009 report, VC-style singleton pages. Resolution: keep existing `ClanBankPane *g_pClanBankPane;`; explicit initializer remains unproven and unnecessary.
- Open question: is `0x0048c260` source code? Evidence checked: current bytes/disasm/decompile and B014. Resolution: no, it is cleanup support.
- Open question: should target use `dword_67ADE8`/`unk_67ADE8`? Evidence checked: IDB name query and generated output. Resolution: no, source-facing docs should use `g_pClanBankPane`.
- Remaining unresolved question: exact original declaration location/header visibility. Impact: confidence cap only; current source-generation placement is adequate and already accepted.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- File/placement: not applicable.
- Exact replacement/insert/delete text: none.
- Reason B agent must not apply it directly: generated `auto-generated/-ag-*` files and manual coverage/tracker files are validator/supervisor-owned. Scoped validators refreshed generated rows during implementation; no manual generated or coverage edit is requested.

## Follow-Up Actions
- Supervisor actions: review this implemented callback and proceed with the supervisor execute/Gate 2 path if accepted.
- A-agent actions: none requested.
- B007 future research actions: none unless supervisor assigns a separate callback or neighbor-style/global-emission normalization task.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for `89/92`; not higher due original-symbol/initializer uncertainty.
- Remaining uncertainty: exact original source declaration spelling and header/source placement beyond the generated `ClanBank.cpp` route.

## Validator Results
- Commands run:
  - `000000007840` at `2026-07-07T03:48:20-04:00`: `python .\tools\validator.py --mode file --file by-memory\0x0067ade8-0x0067adec.g_pClanBankPane.md --apply --queue-timeout 240`
  - `000000007841` at `2026-07-07T03:48:27-04:00`: `python .\tools\validator.py --mode file --file by-global\g_pClanBankPane.md --apply --queue-timeout 240`
  - `000000007842` at `2026-07-07T03:48:41-04:00`: `python .\tools\validator.py --mode file --file by-memory\0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md --apply --queue-timeout 240`
  - `000000007843` at `2026-07-07T03:48:49-04:00`: `python .\tools\validator.py --mode file --file by-class\ClanBankPane.md --apply --queue-timeout 240`
  - `000000007844` at `2026-07-07T03:49:01-04:00`: `python .\tools\validator.py --mode file --file by-file\ClanBank.md --apply --queue-timeout 240`
- Results: all five scoped validators returned `ok: 1`. Target validator updated [UID:0002XK] completion/confidence to `89/92`; parent validator updated [UID:0002XJ] completion/confidence to `88/91`; parent validator also performed a UID link normalization for [UID:0000I9]. Generated refresh was deferred for each command and `auto-generated/NexusTK/social/ClanBank.cpp` refreshed to command `000000007844`.
- Warnings: aggregate validator `000000007842` reported existing `missing_ref_uid 0003UD` twice. By-file validator `000000007844` reported existing `missing_ref_uid` warnings for `0003HF`, `0003BB`, and `0003BA` repeated three times each. No validator command failed.
- Generated freshness/read-only check: `auto-generated/NexusTK/social/ClanBank.cpp` header now shows `validator-command-id: 000000007844`, `validator-refreshed-at: 2026-07-07T03:49:01-04:00`, and `validator-refresh-source: deferred-generated-refresh`. Read-only search found [UID:0002XJ] definition `ClanBankPane *g_pClanBankPane;` and no standalone UID0002XK block, no `Empty Emitter Marker`, no `dword_67ADE8`, and no `unk_67ADE8`.

## Changed Files
- Created during report-only pass: `tools/leaser/Agents/Agent-B007/research/0002XK-g_pClanBankPane-source-quality.md`.
- Modified during implementation callback: `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md`, `by-global/g_pClanBankPane.md`, `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`, `by-class/ClanBankPane.md`, `by-file/ClanBank.md`, and this report.
- Validator-owned generated/project updates observed: scoped validators refreshed generated/tracker/coverage outputs, including `auto-generated/NexusTK/social/ClanBank.cpp`; these were not manually edited.
- Renamed: none.
- Report execution: not run. No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, manual report move, registry command, generated-file edit, coverage-report edit, supervisor-ledger edit, queue/lock edit, or validator-state edit was run.
- Lease status: B007 leased the five edited by-* files at `2026-07-07T07:43:43Z` with expiration `2026-07-07T07:48:43Z`. The post-validator unlease command returned `Rejected[No active lease]` for all five because the leases had already expired; `tools/leaser/Agents/current_leases.md` then showed no active leases.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update: target [UID:0002XK] and parent [UID:0002XJ] recommended; aggregate/class/file support notes optional as listed.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply: target `89/92`; parent global `88/91`; owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched to resolution, implementation-ready recommendation, or evidence-backed no-change proof.
- [x] Owner/emitter/reconstructable changes to apply: none.
- [x] Split/rename/new-child changes to apply: none.
- [x] Source-placement, range/split/padding/reclassification, and IDA rename/type/comment decisions recorded.
- [x] First-draft C++ or no-code proof to apply: target marker-only block; parent global definition unchanged.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail listed.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve listed.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: none found.
- [x] Open questions closed or documented as evidence-backed unresolved.
- [x] Validators to run: none during report-only; future callback should run scoped validators only for by-* docs actually edited.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: validator-owned refresh expected only after accepted implementation; no manual coverage/tracker text.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000007847","destination_path":"executed-b-agent-research/B007/0002XK-g_pClanBankPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002XK-g_pClanBankPane-source-quality.md","timestamp":"2026-07-07T04:02:35-04:00","uid":"0002XK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
