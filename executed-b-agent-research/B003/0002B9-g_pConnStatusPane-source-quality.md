** TARGET-REPORT-UID:0002B9 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002B9 g_pConnStatusPane Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: implementation callback applied for [UID:0002B9] `by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md`; the target now documents source-declared `ConnStatusPane` singleton storage, keeps the `ConnStatusPane.cpp` owner/emitter route, and has the formal C++ block populated with `ConnStatusPane *g_pConnStatusPane;`.
- Final disposition: target remains reconstructable NexusTK data owned and emitted by [UID:0000IF] `ConnStatusPane`; no split, rename, reclassification, or new by-global page was required.
- Required action after supervisor Gate 1: completed. Target moved from `85/90` to `88/91`, stale file-local `static` wording was replaced with external-linkage storage rationale, the exact formal C++ declaration was inserted, and both authorized stale support generated-output notes were synchronized.
- Confidence: high for the 4-byte range, lifecycle xrefs, owner/emitter route, neighboring boundaries, and source declaration shape. Confidence stays below final-audit range because IDA has no explicit user/global/name/type row for the slot and exact original header exposure remains inferred rather than symbol-proven.

## Supporting Research

- Assignment source: `tools/leaser/Agents/Agent-B003/goal.md`, current B003 report-only target [UID:0002B9] `by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md`.
- Workflow source: project-level `ntk-b-agent-workflow` skill. Report-only Gate 1 passed at SHA256 `A798642BAD97AF9788B0D145B398C6DADF24CBBEC780FB7F56B9997D1FD66303`; implementation callback then edited only the accepted target/support docs. No generated edits, coverage edits, validator-state edits, report moves, lifecycle/archive commands, or `execute_report` were run.
- MCP source: live/current IDA MCP session `supervisor_recovery_20260705` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` reported `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and strings cache size `2067`.
- Report-time generated-output observation before callback: read-only `auto-generated/NexusTK/network/ConnStatusPane.cpp` had header `validator-command-id: 000000007318`, `validator-refreshed-at: 2026-07-05T18:48:04-04:00`; it contained UID000113 method code that referenced `g_pConnStatusPane`, and UID0002B9 was still only an `Empty Emitter Marker` because the target formal block was blank. Post-validation freshness check now shows header `validator-command-id: 000000007328`, `validator-refreshed-at: 2026-07-05T19:01:13-04:00`, with UID0002B9 emitted as `ConnStatusPane *g_pConnStatusPane;`.
- Existing research used as leads and rechecked: A001/A004 target history, C001 ConnStatusPane file/class refresh, B002 UID000113 executed report, and B006 UID0002B8 neighbor/singleton precedent. Stale report/generated assumptions were not treated as proof unless supported by current docs or current MCP.

## Target

- Target UID: `0002B9`.
- Target path: `by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> by-memory not-covered reconstructable row at report time: `85/90`, combined `87.5`, reconstructable `true`, reports `0`.
- Current supervisor classification: report-first source-quality target for singleton/global source declaration shape, source placement, owner/emitter route, xref/reachability evidence, neighboring singleton boundaries, and first-draft C++ readiness.
- Current scores and parent state after callback: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000IF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IF`, blank optional emitter position, formal C++ `ConnStatusPane *g_pConnStatusPane;`.

## Current Target State

- Existing metadata after callback: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000IF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IF`, blank `EMITTER_POSITION_OPTIONAL`, formal `RECONSTRUCTION_CPP CODE` value `ConnStatusPane *g_pConnStatusPane;`, `Nested:0`.
- Existing owner/emitter/reconstructable state: already routed through [UID:0000IF] `by-file/ConnStatusPane.md`, whose generated source root is `NexusTK/network/ConnStatusPane.cpp`.
- Existing C++/emitter state after callback: generated `ConnStatusPane.cpp` is populated and now emits UID0002B9 as `ConnStatusPane *g_pConnStatusPane;`; it no longer leaves UID0002B9 as an empty marker. Final observed generated header is `validator-command-id: 000000007328`, `validator-refreshed-at: 2026-07-05T19:01:13-04:00`.
- Existing open blockers after callback: no implementation blocker remains. Exact original source symbol/header exposure remains unresolved and is documented as the confidence cap; rejected `static`, by-global-required, class-owner, MapPane-owner, and generic-aggregate alternatives are preserved in the target.
- Related docs checked: `by-file/ConnStatusPane.md`, `by-class/ConnStatusPane.md`, [UID:000113] `by-memory/0x00494520-0x004949df.ConnStatusPane.md`, [UID:0002QH] `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md`, predecessor [UID:0002B8] `g_pCollectionDialogPane`, successor singleton docs at `0x0069adf8`/`0x0069adfc`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and generated `auto-generated/NexusTK/network/ConnStatusPane.cpp`.
- Current artifact/lifecycle status: implementation callback applied and ready for supervisor Gate 2 review. The report has not been executed or archived by B003.

## Executive Recommendation

- Best direct owner: [UID:0000IF] `ConnStatusPane` file page, not [UID:000037] class as direct owner. This is file-scope singleton storage for the active `ConnStatusPane`, not a class member field or method body.
- Emitter route: keep [UID:0000IF]. The generated source root already resolves to `auto-generated/NexusTK/network/ConnStatusPane.cpp`.
- Target disposition: no split and no rename. Keep exact half-open range `0x0069adf4-0x0069adf8`.
- C++ disposition: target is eligible for formal first-draft C++ because it is reconstructable, has a confirmed nonblank emitter route, has combined score above the code-entry gate, and current evidence resolves the declaration shape. Applied formal block:

```cpp
ConnStatusPane *g_pConnStatusPane;
```

- Implementation condition: satisfied. Supervisor Gate 1 acceptance and callback are historical/completed; the scoped target and support validators ran during the callback and are recorded under `Validator Results`. Current next state is supervisor Gate 1 re-audit of this repaired post-callback artifact, then Gate 2 claim verification.

## Supervisor Active Recheck

- Historical supervisor instruction: the original assignment was report-only research for [UID:0002B9] `by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md`, with MCP mandatory and no by-* edits before callback. Gate 1 later passed and the implementation callback has now been applied.
- Split repair: not required. MCP bytes/xrefs and neighbor docs show this is exactly one 4-byte singleton slot between [UID:0002B8] at `0x0069adf0-0x0069adf4` and the next singleton at `0x0069adf8`.
- Source-bearing child status: the target itself is the source-bearing storage definition. The source method island [UID:000113] already emits method code and its global dependency is now satisfied by this declaration.

## Inference Research Guidance Check

- IDA facts: zero-filled 4-byte storage at `0x0069adf4`, no modeled function at the slot, exact four data xrefs, exact write/clear/read instructions, no additional VA/RVA pointer-table hits beyond operand matches, and no IDA `names`/`globals`/type row for the singleton window.
- Documentation evidence: current ConnStatusPane class/file/method docs name and use `g_pConnStatusPane`; MapPane teardown docs record a gameplay UI cleanup path that consumes the pointer; the generated ConnStatusPane file currently compiles around UID000113 code but lacks the declaration.
- Inference: the source-facing name `g_pConnStatusPane` is lifecycle/documentation-derived, not IDA-symbol-proven. It is still the best source-quality name because constructor/destructor lifecycle, support docs, and existing generated method code already use it consistently.
- Existing assumptions treated as uncertain: old target/B002 wording that the declaration should be `static`; old support wording that generated `ConnStatusPane.cpp` is zero-byte/stale; any suggestion that a separate by-global page is required before the target can emit.
- Wave2/Wave3: no current Wave2/Wave3 authority was used for the final recommendation. Old generated or recovered material was treated only as historical lead context.

## Heuristic / Inference Reanalysis And Validation

- Source declaration shape: current target says `static ConnStatusPane* g_pConnStatusPane;`. That is now stale because the accepted generated source split has `ConnStatusPane.cpp` emitting the constructor/destructor while `MapPane.cpp` emits [UID:0002QH] `MapPane::ExitToMenu`; MCP and decompile show `MapPane::ExitToMenu` reads `unk_69ADF4` at `0x00504a32`. Under that source split, a file-local `static` definition would not be visible to the MapPane translation unit. The best target formal definition is `ConnStatusPane *g_pConnStatusPane;`, matching the adjacent UID0002B8 external-linkage precedent.
- Initializer shape: do not emit `= nullptr`. MCP `get_bytes`/`get_int`/`get_global_value` prove zero-initialized storage, but adjacent accepted singleton precedent emits a plain definition and relies on zero initialization. That is a plausible VC++ 6/7-era source shape and avoids inventing explicit initializer spelling.
- Owner/source placement: the write/clear lifecycle is owned by `ConnStatusPane`; the read from `MapPane::ExitToMenu` is a consumer and does not transfer ownership. Keeping owner/emitter [UID:0000IF] is stronger than moving to MapPane, class UID, a generic UI singleton page, or a new global page.
- Range/boundary: `0x0069adf4-0x0069adf8` is exactly one dword. Predecessor [UID:0002B8] has its own eight xrefs ending at `0x0069adf4`; successor `0x0069adf8` has its own four xrefs; `0x0069adfc` has five xrefs. No split/merge/padding reinterpretation is supported.
- Generated-output state: support docs that said current generated `ConnStatusPane.cpp` was zero-byte/stale were contradicted by report-time read-only generated output and have now been corrected. Before callback, generated output contained UID000113 method code and left UID0002B9 as an empty marker; after scoped validation, generated header `000000007328` emits UID0002B9 as `ConnStatusPane *g_pConnStatusPane;`.
- Rejected alternatives: `static` storage rejected due cross-file consumer; class-member ownership rejected because the address is a process-global slot and not a `this` offset; MapPane ownership rejected because it reads for teardown only; no-code marker rejected because this is a source declaration; new by-global page rejected as unnecessary for this exact callback because the current file owner/emitter route is already valid and adjacent precedent shows by-memory storage can carry the formal declaration.

## Evidence Standards Used

- Primary evidence: current IDA MCP session `supervisor_recovery_20260705`, narrow exact-address calls, xref queries, byte/value reads, entity/name/global queries, function analysis, targeted disassembly/decompilation, pointer-pattern searches, and capped neighbor checks.
- Secondary evidence: current target/support by-* docs, generated `ConnStatusPane.cpp`, generated tracker/memory coverage rows, and matching executed report leads.
- Evidence strength: strong for storage identity, range, xrefs, lifecycle, owner/emitter route, and first-draft declaration. Confidence cap remains because IDA has no explicit source symbol, no recovered UDT/type row for `ConnStatusPane` in the local type catalog, and exact original header declaration exposure remains inferred.

## Evidence Checked

- IDA MCP checks performed: `idb_list`, `server_health`, `tools/list`, `lookup_funcs` for `0x0069adf4`, xref sites, and neighboring slots; `get_bytes 0x0069adf0 size 0x20`; `get_int` and `get_global_value` for `0x0069adf0`, `0x0069adf4`, `0x0069adf8`, `0x0069adfc`; `entity_query` for `names`/`globals` over `0x0069adf0-0x0069ae10`; `xref_query to 0x0069adf4`; `find_bytes` for VA/RVA little-endian address patterns; `insn_query` scoped to the four referring functions; `analyze_function` for `0x00494520`, `0x004945e0`, `0x00494980`; `disasm`/`decompile` around `0x005047f0`; `xref_query` for the constructor and neighbor slots; `type_query *ConnStatusPane*`; `int_convert` for relevant sizes and addresses.
- by-* docs checked: assigned target, `by-file/ConnStatusPane.md`, `by-class/ConnStatusPane.md`, [UID:000113] `by-memory/0x00494520-0x004949df.ConnStatusPane.md`, [UID:0002QH] `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md`, [UID:0002B8] `by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md`, and neighbor singleton pages around `0x0069adf8`/`0x0069adfc`.
- Generated/tracker checks: `auto-generated/NexusTK/network/ConnStatusPane.cpp`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-memory-coverage.md`.
- Old report search terms: `0002B9`, `0x0069adf4`, `69ADF4`, `g_pConnStatusPane`, and `ConnStatusPane` under executed and active B-agent report areas. Relevant matches were B002 UID000113 and B006 UID0002B8; B002's `static`/zero-generated assumptions are now partially stale.
- Negative checks: no function at `0x0069adf4`; no explicit IDA name/global rows over the singleton window; no local `ConnStatusPane` type result; no extra VA address-pattern hits beyond the four xref operands; no RVA pointer-pattern hits; no neighbor xrefs crossing into this slot; no evidence that MapPane owns the storage.
- Failed/unavailable checks: none. MCP was available and used. Validators were intentionally not run in the original report-only pass; callback scoped validators are now recorded under `Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002B9-01 | Target metadata moved from `COMPLETION:85`/`CONFIDENCE:90` to `88/91`; owner `0000IF`, reconstructable true, emitter `0000IF`, blank optional position, and `Nested:0` stayed unchanged. | High | Target validator `000000007326` reported `completion_update 0002B9 ... 88`, `confidence_update 0002B9 ... 91`, `ok: 1`. | Target metadata and Score Rationale | incorporate | applied |
| C-0002B9-02 | Exact range remains `0x0069adf4-0x0069adf8`, one zero-initialized dword, not a function. | High | Target now records B003 MCP `lookup_funcs`, `get_bytes`, `get_int`, and `get_global_value` facts; validator `000000007326` passed. | Target Item Summary, Storage, Evidence | incorporate | applied |
| C-0002B9-03 | Source-facing name `g_pConnStatusPane` is documentation/lifecycle-derived, not an explicit IDA symbol; IDA still uses `unk_69ADF4`/`dword_69ADF4` style operand labels. | High | Target now records `entity_query` no-name/no-global and `type_query` no-type facts. | Target Storage/Evidence and IDA Rename section | incorporate | applied |
| C-0002B9-04 | The complete direct xref set is four data refs: constructor write `0x00494545`, ordinary reset/destructor clear `0x004945fa`, scalar deleting destructor clear `0x004949a0`, and MapPane teardown read `0x00504a32`. | High | Target now records exact xref and instruction inventory; validator `000000007326` passed. | Target Evidence, Direct Xref Inventory | incorporate | applied |
| C-0002B9-05 | ConnStatusPane constructor/destructor/scalar lifecycle owns the storage publish/clear behavior. | High | Target now records lifecycle roles; UID000113 support note remains consistent and was validated by `000000007328`. | Target Evidence and UID000113 Source Quality Notes | incorporate | applied |
| C-0002B9-06 | MapPane `ExitToMenu` is a cross-file consumer: it reads the pointer when `byte_66DA97 != 1`, tests it, pushes it, and calls `sub_469180`. | High | Target and both support sync notes now record the MapPane consumer/external-linkage rationale. | Target Evidence, rejected `static` rationale, support notes | incorporate | applied |
| C-0002B9-07 | File-local `static ConnStatusPane *g_pConnStatusPane;` is stale under the current source split; formal storage definition is `ConnStatusPane *g_pConnStatusPane;`. | High | Target formal C++ block contains exactly `ConnStatusPane *g_pConnStatusPane;`; generated output now emits UID0002B9 declaration under header `000000007328`. | Target formal C++ block and Storage prose | incorporate | applied |
| C-0002B9-08 | Pointer-pattern negatives support no hidden route: VA little-endian `F4 AD 69 00` appears only at the four operand locations; RVA `F4 AD 29 00` has no matches. | High | Target now records both pattern checks in current MCP recheck. | Target Evidence and Negative Evidence Summary | incorporate | applied |
| C-0002B9-09 | Neighbor boundaries are clean: `0x0069adf0` predecessor has eight xrefs, `0x0069adf8` successor has four xrefs, and `0x0069adfc` has five xrefs; no merge/split is needed. | High | Target Item Summary and current MCP recheck now record boundary counts; no split/rename was performed. | Target Range/Split/Boundary prose | incorporate | applied |
| C-0002B9-10 | Generated `ConnStatusPane.cpp` is populated, not zero-byte; UID0002B9 moved from empty marker to emitted declaration after target validation. | High | Pre-callback generated header `000000007318` is historical proof; post-validation generated header `000000007328` at `2026-07-05T19:01:13-04:00` contains `ConnStatusPane *g_pConnStatusPane;`. | Target Generated/Status prose; support stale-generated notes | incorporate | applied |
| C-0002B9-11 | Keep canonical owner/emitter [UID:0000IF] `ConnStatusPane`; reject class UID, MapPane, generic singleton aggregate, and required new by-global page as direct owner alternatives. | High | Target Source Placement And Rejected Alternatives now records these decisions; metadata owner/emitter unchanged. | Target ownership/source placement sections | incorporate | applied |
| C-0002B9-12 | Support sync updated stale generated-output language in `by-file/ConnStatusPane.md` and UID000113 method page; `by-class/ConnStatusPane.md` and UID0002QH already carried same-or-greater core relationship detail and were not edited. | Medium-high | Support validators `000000007327` and `000000007328` passed with `ok: 1`; no class/MapPane support drift found. | Support docs Generated Output Note / Source-Quality Notes | incorporate | applied |
| C-0002B9-13 | B003 did not run lifecycle/archive/report execution commands; scoped validators were run for every edited by-* doc and leases were released. | High | Validators `000000007326`, `000000007327`, `000000007328` all exited `0`/`ok: 1`; leases for the three edited by-* files were released successfully. | Validator Results and Implementation Tracking Checklist | incorporate | applied |

## Positive Evidence Summary

- The exact storage range is stable: one 4-byte, zero-initialized dword at `0x0069adf4`, bounded by independently documented singleton slots.
- The lifecycle xref set is complete and semantically coherent: constructor publishes, ordinary reset/destructor clears, scalar deleting destructor clears, and MapPane teardown reads/queues the active pane.
- The owner/emitter route is already valid: `ConnStatusPane` file owns the constructor/destructor lifecycle and routes to generated `NexusTK/network/ConnStatusPane.cpp`.
- Generated output corroborates readiness: UID000113 source code already uses `g_pConnStatusPane`; after callback validation, UID0002B9 is emitted as the matching storage declaration instead of an empty marker.
- Adjacent UID0002B8 provides a directly analogous external-linkage singleton declaration under a split where another source file consumes the singleton.

## IDA MCP Facts

- Function/range facts: `lookup_funcs 0x0069adf4` reports not a function. `lookup_funcs` maps the four referring addresses to `sub_494520` (`0x00494520`, size `0xc0`/192), `sub_4945E0` (`0x004945e0`, size `0x29`/41), `sub_494980` (`0x00494980`, size `0x5f`/95), and `sub_5047F0` (`0x005047f0`, size `0x37b`/891).
- Data facts: `get_bytes 0x0069adf0 size 0x20` returns 32 zero bytes spanning the adjacent singleton window. `get_int`/`get_global_value` show `0x0069adf0`, `0x0069adf4`, `0x0069adf8`, and `0x0069adfc` all read as zero.
- Xref facts: `xref_query to 0x0069adf4` reports exactly four data refs at `0x494545`, `0x4945fa`, `0x4949a0`, and `0x504a32`.
- Instruction facts: `insn_query` reports `mov dword ptr unk_69ADF4, ecx` at `0x494545`, `mov dword ptr unk_69ADF4, 0` at `0x4945fa`, `mov dword ptr unk_69ADF4, 0` at `0x4949a0`, and `mov eax, dword ptr unk_69ADF4` at `0x504a32`.
- MapPane teardown facts: targeted disassembly shows `cmp byte_66DA97, 1`, conditional skip, load of `unk_69ADF4`, null test, `push eax`, `mov ecx, esi`, `call sub_469180`; decompile renders `if (byte_66DA97 != 1 && unk_69ADF4) sub_469180(v3, unk_69ADF4);`.
- Global/type facts: `entity_query` for names/globals over `0x0069adf0-0x0069ae10` returned no entries. `type_query *ConnStatusPane*` returned no local type catalog result.
- Negative IDA facts: VA pattern `F4 AD 69 00` matches only the four operand locations; RVA pattern `F4 AD 29 00` matches none.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069adf4-0x0069adf8` | [UID:0002B9] `by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md` | Active `ConnStatusPane` singleton storage definition | TRUE | [UID:0000IF] `ConnStatusPane` file | current `88/91` | Applied and validated by command `000000007326` |
| `0x00494520-0x004949df` | [UID:000113] `by-memory/0x00494520-0x004949df.ConnStatusPane.md` | Constructor/destructor/method island that publishes and clears the singleton | TRUE | [UID:000037] `ConnStatusPane` class | `88/90` | Already emits method code; support stale generated note synchronized by validator command `000000007328` |
| `0x005047f0-0x00504b6b` | [UID:0002QH] `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` | Cross-file consumer that reads and queues active ConnStatusPane on exit-to-menu teardown | TRUE | [UID:00007Q] `MapPane` class | `88/90` | Same-or-greater consumer relationship already present |
| `0x0069adf0-0x0069adf4` | [UID:0002B8] `by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md` | Predecessor singleton and external-linkage precedent | TRUE | [UID:0000IB] `CollectionDialogPane` file | `88/91` | Already present; no edit needed |
| `0x0069adf8-0x0069adfc` | [UID:0001PB] successor singleton page | Next slot boundary | TRUE | existing docs | `86/90` at read-time docs | Boundary evidence only; no edit recommended |
| `0x0069adfc-0x0069ae00` | [UID:00029C] successor singleton page | Next-next slot boundary | TRUE | existing docs | `87/89` at read-time docs | Boundary evidence only; no edit recommended |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00494545` in `sub_494520` | `mov dword ptr unk_69ADF4, ecx` | Constructor publishes the adjusted `ConnStatusPane` `this` pointer. |
| `0x004945fa` in `sub_4945E0` | `mov dword ptr unk_69ADF4, 0` | Ordinary reset/destructor body clears the singleton before base teardown. |
| `0x004949a0` in `sub_494980` | `mov dword ptr unk_69ADF4, 0` | Scalar deleting destructor path also clears the singleton before optional free. |
| `0x00504a32` in `sub_5047F0` | `mov eax, dword ptr unk_69ADF4`; null-tested and passed to `sub_469180` | `MapPane::ExitToMenu` consumer removes/queues the active status pane during gameplay UI teardown when mode allows it. |
| `0x004f87ec` caller of constructor | call inside `sub_4F7D10` | Main UI graph setup constructs the ConnStatusPane instance that publishes this singleton. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: the target already identifies the range as `g_pConnStatusPane`; `by-file/ConnStatusPane.md` lists `g_pConnStatusPane` in proposed contents; `by-class/ConnStatusPane.md` and UID000113 describe constructor publish/destructor clear; UID0002QH includes connection-status panes in gameplay UI teardown; UID0002B8 documents adjacent external-linkage singleton precedent.
- Existing docs that are stale or incomplete: target `Storage` still recommends `static`; `by-file/ConnStatusPane.md` still says generated `ConnStatusPane.cpp` is zero-byte/stale; UID000113 confidence rationale says B002 lacked live MCP access, which remains historical for B002 but no longer describes this UID0002B9 report's MCP evidence; UID000113 support prose also depends on the global declaration but target formal block is still blank.
- Generated/coverage report state after callback: `auto-generated/-ag-memory-coverage.md` row lists UID0002B9 as `coded` through owner/emitter `0000IF`, `emits_code: yes`, with output `auto-generated/NexusTK/network/ConnStatusPane.cpp`. Generated `ConnStatusPane.cpp` header `000000007328` contains UID000113 code and the UID0002B9 declaration, not an empty marker.

## Ranked Ownership Analysis

### 1. [UID:0000IF] ConnStatusPane file

- Evidence for: ConnStatusPane constructor writes the pointer; ConnStatusPane destructor/reset/scalar paths clear it; file page already records this singleton in proposed contents; generated source root exists at `NexusTK/network/ConnStatusPane.cpp`; UID000113 method code already uses the name.
- Evidence against: one consumer read occurs in `MapPane::ExitToMenu`; IDA has no explicit global/name row.
- Decision: keep as canonical owner and emitter. The consumer read affects linkage, not ownership.

### 2. [UID:000037] ConnStatusPane class

- Evidence for: class lifecycle owns writes/clears; constructor/destructor source code references the global.
- Evidence against: the slot is process-global storage, not an instance field or vtable/class declaration range; source definition belongs to the file/module scope rather than inside the class declaration.
- Decision: keep as support/semantic class context, not target canonical owner.

### 3. [UID:00007Q]/[UID:0000L3] MapPane

- Evidence for: `MapPane::ExitToMenu` has the sole read outside the ConnStatusPane method island.
- Evidence against: read/consumer xref alone is not ownership proof; MapPane neither publishes nor clears construction/destruction lifecycle storage; MapPane teardown only queues/removes the active pane.
- Decision: reject as owner. Preserve as cross-file consumer evidence that blocks file-local `static`.

### 4. Required by-global page or generic UI singleton group

- Evidence for: source-facing globals sometimes have by-global aliases; nearby singleton slots form a visible data-section neighborhood.
- Evidence against: current target already has valid file owner/emitter route; no existing by-global page for UID0002B9 is required to emit this declaration; neighbor slots are owned by separate source files/classes and xrefs do not support a single aggregate source owner.
- Decision: no new by-global page required for this callback. A future by-global alias can be added only if project organization wants a global index, not as a blocker for this storage declaration.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable. Keep `NexusTK/network/ConnStatusPane.cpp`.
- Likely full contents: existing ConnStatusPane method island, vtable/RTTI child markers as appropriate, and file-scope `g_pConnStatusPane` declaration.
- Candidate related items rejected: MapPane teardown stays in `MapPane.cpp`; neighboring `g_pCollectionDialogPane`, `g_pDescPane`, and `g_pTabPane` stay with their own owners.
- Standalone, narrow, or broad source-file inference: narrow file-owned global storage within the existing ConnStatusPane source file.

## Source Placement

- Recommended source file/class/global/module placement: define `ConnStatusPane *g_pConnStatusPane;` in `NexusTK/network/ConnStatusPane.cpp` through [UID:0000IF].
- Why this placement fits: ConnStatusPane constructor/destructor lifecycle is the only writer/clearer family; file page already owns ConnStatusPane source; generated output is already populated at that path and references the global from methods.
- Rejected placements: `ui/status` remains only a possible future tree organization alternative; MapPane is a consumer; a standalone singleton registry file would invent a source file not supported by write/clear ownership; a class-level definition would misrepresent global storage.
- Remaining placement uncertainty: exact original header declaration exposure is unresolved. If a future source-layout pass proves `MapPane.cpp` did not need external linkage or that ConnStatusPane and MapPane were folded into one translation unit, linkage can be revisited. Current accepted source split does not justify `static`.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: `0x0069adf4-0x0069adf8`, exactly 4 bytes. The containing `0x0069adf0-0x0069ae10` window is zero-filled at load-time in MCP reads.
- Children/subranges: none. Do not split a 4-byte pointer slot.
- Padding/table/data/code distinctions: reconstructable global-data pointer, not padding, not code, not a table, not compiler-only RTTI/vtable data.
- Parent/container impact: no parent aggregate repair required. Predecessor and successor singleton pages remain independently documented.

## Negative Evidence Summary

- No function at `0x0069adf4`, so this is not code or a tiny function.
- No `entity_query` name/global row for `0x0069adf4`, so the exact source name is inferred rather than symbol-proven.
- No local type catalog result for `ConnStatusPane`, so target C++ relies on current project source-type naming rather than IDA UDT recovery.
- No extra pointer-table route was found: the VA operand pattern appears only at the four xref locations and the RVA pattern has zero matches.
- Neighbor xrefs do not cross into this target, so there is no evidence to merge with `g_pCollectionDialogPane`, `g_pDescPane`, or `g_pTabPane`.
- Consumer read in MapPane proves linkage/reachability but not direct ownership.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing name: `g_pConnStatusPane` for `0x0069adf4`.
- Evidence: ConnStatusPane lifecycle xrefs, current by-* docs, UID000113 generated method code, and naming consistency with adjacent `g_pCollectionDialogPane` / other pane singleton patterns.
- Proposed type: `ConnStatusPane *` for the formal storage declaration.
- Items intentionally left unchanged: no IDA DB rename/type/comment edits requested or performed. IDA lacks a current explicit name/type row; the documentation carries the source-facing name without modifying IDA.
- Safety: source-doc update was completed in by-* docs during callback; IDA DB edits remain out of scope and not requested.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is reconstructable, has owner/emitter route [UID:0000IF], combined current score exceeds the minimum gate, and current evidence resolves range/ownership/declaration shape.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` block insertion text:

```cpp
ConnStatusPane *g_pConnStatusPane;
```

- Third-party import directive: not applicable.
- Reason it preserves behavior: the binary contains a zero-initialized global pointer. A plain file-scope pointer definition is zero-initialized by C++ static storage rules and is then published/cleared by the existing constructor/destructor lifecycle.
- Reason it matches plausible original source shape: mid-2000s Visual C++ game client sources commonly used file/global pane singleton pointers; adjacent accepted singleton UID0002B8 uses the same pointer-definition style without explicit initializer.
- Inferred names/types: `ConnStatusPane` is the accepted class name; `g_pConnStatusPane` is the accepted lifecycle/global singleton name.
- Naming/coding style convention: `g_p...` pointer singleton style already appears in neighboring docs and generated method code.
- Reason code should remain blank: not applicable. Before callback, leaving it blank caused the generated file to keep an empty marker while UID000113 code referenced the global; the callback resolved that by inserting the formal declaration.
- Exact no-code proof: not applicable.

## Final Recommendation

- Exact changes recommended: update UID0002B9 target metadata to `88/91`, keep current owner/emitter/reconstructable fields unchanged, insert `ConnStatusPane *g_pConnStatusPane;` into the formal C++ block, and incorporate current MCP evidence/prose at report-level detail.
- Exact parent assignments recommended: keep [UID:0000IF] as canonical owner and emitter. Do not assign to MapPane or class UID directly.
- Exact items left no-owner/non-emitting: none.
- Exact future work outside this assignment: possible future by-global alias/index page for `g_pConnStatusPane` if the project wants global-index coverage; possible future source-tree reassessment of `network/` versus `ui/status`, but current docs already say this is not a blocker.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md`.
- Exact report facts to incorporate: current MCP session `supervisor_recovery_20260705`; exact zero-filled 4-byte storage; no function/name/global/type row; four direct xrefs and instruction roles; constructor/destructor/scalar lifecycle; MapPane teardown read and `byte_66DA97 != 1` mode gate; VA/RVA pointer-pattern negatives; neighbor xref counts and clean boundaries; generated `ConnStatusPane.cpp` report-time state; stale `static` rejection; owner/emitter/source placement; rejected alternatives.
- Metadata/score/owner/emitter/reconstructable/C++ changes: `COMPLETION:85 -> 88`, `CONFIDENCE:90 -> 91`, keep `CANONICAL_OWNER:0000IF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IF`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`; insert exact formal C++ declaration:

```cpp
ConnStatusPane *g_pConnStatusPane;
```

- Historical/stale assumptions to preserve as rejected: old `static` wording; old generated-zero-byte note; old "needs by-global page" confidence blocker; MapPane-as-owner alternative; generic singleton aggregate alternative.
- Scoped validator run after accepted target edit:

> Executable block R001 was removed from this report and preserved verbatim in [0002B9-g_pConnStatusPane-source-quality-removed.md](0002B9-g_pConnStatusPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Generated freshness result after validation: `auto-generated/NexusTK/network/ConnStatusPane.cpp` refreshed from UID0002B9 `Empty Emitter Marker` to the `ConnStatusPane *g_pConnStatusPane;` declaration. Final observed generated header is `validator-command-id: 000000007328`, `validator-refreshed-at: 2026-07-05T19:01:13-04:00`.

## Recommended Support Doc Changes

- Support path: `by-file/ConnStatusPane.md`.
- Exact report facts incorporated: historical report-time generated observation `validator-command-id: 000000007318`, `validator-refreshed-at: 2026-07-05T18:48:04-04:00` showed populated UID000113 code and UID0002B9 as an empty marker pending target formal declaration. The support notes now reject the stale "zero-byte/stale generated file" note and record that the singleton storage should be external-linkage because `MapPane.cpp` consumes it. Post-validation generated header `000000007328` confirms UID0002B9 now emits the declaration.
- Metadata/link/score changes: no support score change recommended.
- Validator run after edit:

> Executable block R002 was removed from this report and preserved verbatim in [0002B9-g_pConnStatusPane-source-quality-removed.md](0002B9-g_pConnStatusPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Support path: `by-memory/0x00494520-0x004949df.ConnStatusPane.md`.
- Exact report facts incorporated: its formal C++ uses `g_pConnStatusPane`; UID0002B9 now supplies the storage declaration after callback; current B003 MCP evidence resolves the singleton storage declaration even though B002's 2026-06-18 pass lacked live MCP. The stale generated-output/global-declaration linkage wording was updated in this support page.
- Metadata/link/score changes: no support score change recommended.
- Validator run after edit:

> Executable block R003 was removed from this report and preserved verbatim in [0002B9-g_pConnStatusPane-source-quality-removed.md](0002B9-g_pConnStatusPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Support docs checked but no edit recommended by default: `by-class/ConnStatusPane.md` already documents constructor publish/destructor clear and relationship detail; `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` already records connection-status pane cleanup; neighbor singleton docs already carry adequate boundary evidence.

## Score And Metadata Recommendation

- Current score/metadata after callback: `88/91`, owner/emitter [UID:0000IF], reconstructable true, formal C++ declaration inserted. Historical pre-callback state was `85/90` with blank formal C++.
- Recommended score/metadata: applied as `88/91`, owner/emitter/reconstructable/optional position unchanged, formal C++ declaration inserted.
- Score rationale: completion improves because the report resolves the prior source declaration/linkage blocker, records current MCP xrefs/instruction roles, pointer-pattern negatives, no-name/no-type evidence, boundary proof, generated-output state, and support sync needs. Confidence improves modestly because current MCP independently confirms the storage/xrefs/consumer path, but remains below `92+` because no IDA symbol/type row proves original spelling and exact header exposure is still inferred.
- Reason not higher: final source-tree/header exposure is not proven and IDA still lacks an explicit global/type entry. The stale support generated-output wording has been synchronized and no longer caps implementation readiness.
- Reason not lower: every behavioral storage use is directly accounted for, owner/emitter route is current, generated output already uses the name from UID000113, and adjacent singleton precedent supports the declaration style.
- Score-improvement attempt: checked target/support docs, old reports, tracker/coverage generated state, generated C++ freshness, exact MCP bytes/values, xrefs, function roles, disassembly/decompile, pointer patterns, neighbor boundaries, and type/name tables. The only remaining blockers are original-symbol/header proof and support-doc stale generated notes, so `88/91` is justified.
- Metadata fields to leave unchanged: `CANONICAL_OWNER:0000IF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IF`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`.

## Open Questions With Attempted Resolution

- Is `g_pConnStatusPane` source name exact? Best supported resolution: use it as source-facing name. Evidence checked: IDA no-name result, lifecycle docs, generated UID000113 code, current class/file docs, neighbor naming convention. Remaining caveat: exact original symbol spelling not recovered, so confidence remains capped.
- Should the declaration be `static`? Resolved: no under current source split. Evidence checked: MapPane teardown reads the slot from a different source owner; adjacent UID0002B8 external-linkage precedent. If future proof shows MapPane and ConnStatusPane were one translation unit, this can be revisited.
- Should the definition include `= nullptr`? Resolved: no. Evidence checked: zero-filled data, accepted adjacent singleton style, C++ static zero initialization. Plain definition is sufficient and less speculative.
- Should this move to a by-global page? Resolved for this callback: no. Evidence checked: current owner/emitter route, generated output, and support docs. A by-global alias can be future indexing work but is not required for reconstruction.
- Should any neighboring slot be merged/split? Resolved: no. Evidence checked: separate neighbor xref sets, pointer patterns, and exact 4-byte boundaries.
- Any unresolved issue with score/C++ impact: only original-symbol/header exposure remains unresolved; it limits confidence but does not block formal C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual `-coverage-report.md`, supervisor ledger, validator state, or `auto-generated/-ag-*` edit was applied or recommended for B003. Generated tracker/coverage rows refreshed through scoped validators after accepted by-* edits; no manual generated edits were made.

## Follow-Up Actions

- Supervisor actions: re-audit this repaired post-callback report artifact for Gate 1 current-state/lifecycle text, then perform Gate 2 claim verification against the changed docs, scoped validator results, lease release, and generated freshness. `execute_report` remains supervisor-only after Gate 2.
- B003 actions: implementation callback is complete. No further B003 action remains unless supervisor requests another targeted report-text or callback repair.
- A-agent actions: none requested. No IDA rename/type/comment changes are requested.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `88/91` and conservative not to exceed that.
- Remaining uncertainty: exact original symbol/header exposure and future source-tree organization are not fully proven; neither blocks the current source declaration.

## Validator Results

- Command: `python .\tools\validator.py --mode file --file by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md --apply --queue-timeout 240`
  - `command_id: 000000007326`
  - `command_timestamp: 2026-07-05T19:00:54-04:00`
  - Exit code: `0`
  - Result: `ok: 1`, `completion_update 0002B9 ... 88`, `confidence_update 0002B9 ... 91`, generated refresh initially deferred.
- Command: `python .\tools\validator.py --mode file --file by-file/ConnStatusPane.md --apply --queue-timeout 240`
  - `command_id: 000000007327`
  - `command_timestamp: 2026-07-05T19:01:02-04:00`
  - Exit code: `0`
  - Result: `ok: 1`, generated refresh initially deferred.
- Command: `python .\tools\validator.py --mode file --file by-memory/0x00494520-0x004949df.ConnStatusPane.md --apply --queue-timeout 240`
  - `command_id: 000000007328`
  - `command_timestamp: 2026-07-05T19:01:13-04:00`
  - Exit code: `0`
  - Result: `ok: 1`, generated refresh initially deferred.
- Queue/freshness check: `python .\tools\validator.py --queue-status` returned `command_id: 000000007329`, `command_timestamp: 2026-07-05T19:01:27-04:00`, worker running, `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, `processing generated refresh jobs: 0`.
- Generated freshness: read-only `auto-generated/NexusTK/network/ConnStatusPane.cpp` header is now `validator-command-id: 000000007328`, `validator-refreshed-at: 2026-07-05T19:01:13-04:00`, `validator-refresh-source: deferred-generated-refresh`. UID0002B9 is no longer an empty marker and appears as:

```cpp
// UID:0002B9 | by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md | Completion:88 | Confidence:91
ConnStatusPane *g_pConnStatusPane;
```

- Any unresolved validator warnings/errors: none for the edited files.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0002B9-g_pConnStatusPane-source-quality.md`.
- Modified:
  - `by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md`
  - `by-file/ConnStatusPane.md`
  - `by-memory/0x00494520-0x004949df.ConnStatusPane.md`
  - `tools/leaser/Agents/Agent-B003/research/0002B9-g_pConnStatusPane-source-quality.md`
- Renamed: none.
- Generated files changed only by validator refresh; B003 did not edit generated output directly.
- Report execution: not run. B003 did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, report moves, manual generated edits, coverage edits, or validator-state edits.

## Implementation Tracking Checklist

Historical initial report-only pass (completed):

- [x] Historical supervisor validation before implementation: Gate 1 passed at SHA256 `A798642BAD97AF9788B0D145B398C6DADF24CBBEC780FB7F56B9997D1FD66303`.
- [x] Target doc to update: `by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md` updated and validated by command `000000007326`.
- [x] Accepted support docs updated: `by-file/ConnStatusPane.md` and `by-memory/0x00494520-0x004949df.ConnStatusPane.md` stale generated/global-declaration notes updated and validated by commands `000000007327` and `000000007328`.
- [x] Current target state and actual evidence checked recorded: report now records post-callback `88/91`, formal C++ declaration, owner/emitter [UID:0000IF], MCP session `supervisor_recovery_20260705`, historical generated header `000000007318`, and post-validation generated header `000000007328`.
- [x] Claim And Incorporation Ledger updated with callback verification state `applied` for every claim C-0002B9-01 through C-0002B9-13.
- [x] Metadata/score changes applied: target `COMPLETION:85 -> 88`, `CONFIDENCE:90 -> 91`; owner/emitter/reconstructable/optional position/Nested unchanged.
- [x] Score-limiting blockers researched and incorporated: linkage/static blocker resolved, no-name/type blocker documented as confidence cap, generated-output stale note corrected, neighbor boundaries verified, pointer-pattern negatives recorded.
- [x] Owner/emitter/reconstructable changes: no owner/emitter/reconstructable change; [UID:0000IF] preserved.
- [x] Split/rename/new-child changes: none required; no split/rename/new child performed.
- [x] Source-placement and range decisions applied: kept `NexusTK/network/ConnStatusPane.cpp`; kept exact `0x0069adf4-0x0069adf8` range; rejected MapPane/class/generic aggregate ownership in target prose.
- [x] First-draft C++ applied in formal target block:

```cpp
ConnStatusPane *g_pConnStatusPane;
```

- [x] Third-party import directive: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: current MCP facts, exact xrefs/instruction roles, MapPane consumer, no name/global/type row, pointer-pattern negatives, boundary xref counts, generated state, rejected static/by-global/MapPane alternatives, score rationale.
- [x] Historical/stale assumptions preserved/rejected: `static` declaration, zero-byte generated file note, generated alias-pollution context, and previous by-global-page confidence blocker.
- [x] Wave2/Wave3 mentions/artifacts: no active Wave2/Wave3 authority used; old generated/recovered context treated as lead only.
- [x] Open questions closed or documented: source name inferred, header exposure unresolved as score cap, no split/new owner required.
- [x] Validators run after callback for edited files:

> Executable block R004 was removed from this report and preserved verbatim in [0002B9-g_pConnStatusPane-source-quality-removed.md](0002B9-g_pConnStatusPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- [x] Generated refresh confirmed: `auto-generated/NexusTK/network/ConnStatusPane.cpp` header `000000007328` / `2026-07-05T19:01:13-04:00` includes UID0002B9 declaration and no empty marker for that UID.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: callback received after Gate 1 pass at SHA256 `A798642BAD97AF9788B0D145B398C6DADF24CBBEC780FB7F56B9997D1FD66303`.
- [x] Leases acquired and released: B003 leased `by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md`, `by-file/ConnStatusPane.md`, and `by-memory/0x00494520-0x004949df.ConnStatusPane.md`; release command returned `Success` for all three. Post-release lease report shows only unrelated B004 NewUserDialogPane leases.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with callback state `applied` for every accepted claim.
- [x] Metadata/score/owner/emitter/C++ changes applied: target now `88/91`, owner/emitter/reconstructable unchanged, formal C++ `ConnStatusPane *g_pConnStatusPane;`.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and command id/timestamp/exit/ok recorded: `000000007326`, `000000007327`, `000000007328`, all exit `0`, all `ok: 1`.
- [x] Generated output freshness checked and recorded: generated header `000000007328`, UID0002B9 declaration present.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000007338","destination_path":"executed-b-agent-research/B003/0002B9-g_pConnStatusPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002B9-g_pConnStatusPane-source-quality.md","timestamp":"2026-07-05T19:21:57-04:00","uid":"0002B9"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002B9-g_pConnStatusPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002B9-g_pConnStatusPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002B9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
