** TARGET-REPORT-UID:00031U **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00031U FrameRecordRectCopyHelper Source-Quality Report

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00031U] `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md` as reconstructable ImageFrameTable helper code owned and emitted through [UID:0000K1] `by-file/ImageFrameTable.md`.
- Final disposition: source-authored, raw IDA-unmodeled but instruction-clean helper that copies one 16-byte `RectBounds` block from `table->records[frameIndex]` into the caller output. The existing formal C++ is semantically correct and should remain unchanged.
- Implementation disposition: supervisor Gate 1 passed for report SHA256 `E90FC625499F26770755B3BB0E57BEEF1F8CD6E6D26F62C8CD23F0CF683DE9A9`; B013 applied the accepted implementation callback to the target and narrow ImageFrameTable support docs, raised UID00031U to `COMPLETION:88`, `CONFIDENCE:90`, and ran scoped validators. Validator-owned report location and lifecycle history determine the artifact state after supervisor processing.
- Confidence: high for byte/range/behavior and ImageFrameTable source route; capped below final-audit because IDA still has no modeled function, no xrefs, no VA/RVA pointer hits, and no recovered original helper/type names.

## Supporting Research
- Lifecycle/status notes: initial report-only B013 assignment for UID00031U was followed by supervisor Gate 1 acceptance for SHA256 `E90FC625499F26770755B3BB0E57BEEF1F8CD6E6D26F62C8CD23F0CF683DE9A9` and an explicit implementation callback. B013 manually edited only the target/support by-* docs listed in `Changed Files` and this report. Generated files, tracker/coverage/projected-stats files, validator registry state, and backup folders were changed only by scoped validator commands. B013 did not edit lifecycle/archive files or supervisor ledgers and did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, manual report moves, or archive moves.
- Assignment source: `tools/leaser/Agents/Agent-B013/goal.md`; tracker row from `auto-generated/-ag-research-tracker.md`, refreshed by validator command `000000007478` at `2026-07-06T00:09:22-04:00`, lists UID00031U as `86/89`, combined `87.5`, reconstructable `true`, reports `0`.
- Required old-report search terms/results, excluding the supervisor incorporation tracker when it matched as a non-report file:
  - `TARGET-REPORT-UID:00031U`: 0 matching report files.
  - `00031U`: 5 report files: B001 `000174`, B002 `00016A`, B006 `0000K1`, B010 `0002P4`, and B004 `00031T` observed in active research at search time.
  - `0x004d1710`: 3 report files: B001 `000174`, B006 `0000K1`, and B004 `00031T` observed in active research at search time.
  - `0x004d172d`: 3 report files: B001 `000174`, B006 `0000K1`, and B004 `00031T` observed in active research at search time.
  - `FrameRecordRectCopyHelper`: 3 report files: B001 `000174`, B006 `0000K1`, and B004 `00031T` observed in active research at search time.
  - `CopyFrameRecordBounds`: 2 report files: B006 `0000K1` and B004 `00031T` observed in active research at search time.
  - `ImageFrameTable`: 28 report files; broad source-family term. Opened only direct family reports relevant to this target.
  - `ArchiveMetadataTable`: 18 report files; broad shared-structure term. Opened only direct family reports relevant to this target.
  - `PackedArchiveRecord`: 11 report files.
  - `00031T`: 6 report files: B001 `000174`, B002 `00016A`, B002 `00019V`, B006 `0000K1`, B010 `0002P4`, and B004 `00031T` observed in active research at search time.
  - `000176`: 7 report files; opened B001 `000174`, B006 `0000K1`, and B004 `00031T` as relevant leads.
  - `0002P4`: 5 report files; opened B010 `0002P4` and B006 `0000K1` as relevant leads.
  - `0002P6`: 5 report files; opened B006 `0000K1`, B010 `0002P4`, and B004 `00031T` as relevant leads.
  - `0002KU`: 1 report file: B011 `0000K2`; used only as a successor/ResourceLayout lead through current by-* docs.
  - `ResourceLayoutTable`: 62 report files; broad source-family term. Opened B001 `000174` and used current ResourceLayout docs for the rejected successor-owner alternative.
- Old reports opened as leads only: executed B006 `0000K1-ImageFrameTable-empty-emitter-family-source-quality.md`, executed B010 `0002P4-LoadImageFrameTable-source-quality.md`, executed B001 `000174-ResourceLayoutTable.md`, and B004 `00031T-FrameRecordPayloadCopyHelper-source-quality.md` observed in active research at search time. None substitutes for this direct UID00031U report.

## Target
- Target UID: `00031U`.
- Target path: `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` line for [UID:00031U] at `86/89`, combined `87.5`, reconstructable `true`, reports `0`.
- Assignment-time supervisor classification: report-only first; validator-owned lifecycle state determines report location after any later supervisor action.
- Current scores and parent state after callback: target `88/90`, `CANONICAL_OWNER:0000K1`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K1`, blank `EMITTER_POSITION_OPTIONAL`; parent [UID:0000K1] `ImageFrameTable` remains `90/88`; support aggregate [UID:000176] remains a non-emitting `88/92` ImageFrameTable neighborhood/index map.

## Current Target State
- Existing metadata before callback: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000K1`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K1`, blank `EMITTER_POSITION_OPTIONAL`. Callback metadata now applied: `COMPLETION:88`, `CONFIDENCE:90`, with owner/reconstructable/emitter fields unchanged.
- Existing owner/emitter/reconstructable state: source owner and generated output route are both [UID:0000K1] `ImageFrameTable`, producing `auto-generated/NexusTK/render/ImageFrameTable.cpp`.
- Existing C++/emitter state: formal C++ already emitted `void CopyFrameRecordBounds(const ArchiveMetadataTable *table, int frameIndex, RectBounds *outBounds)` and remained semantically unchanged during callback. Generated output now contains UID00031U at `Completion:88 | Confidence:90` under `auto-generated/NexusTK/render/ImageFrameTable.cpp` header `validator-command-id: 000000007493`, `validator-refreshed-at: 2026-07-06T00:43:20-04:00`.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: no behavior/C++ blocker remains. Exact original helper/type/member spellings remain inferred. The target still lacks a modeled IDA function, direct xrefs, and pointer hits, so reachability/linkage remains the confidence cap.
- Related target/support docs checked: target UID00031U; [UID:0000K1] `ImageFrameTable`; [UID:000176] ImageFrameTable helper neighborhood; [UID:00031T] sibling payload helper; [UID:0002P4] loader; [UID:0002P5] cleanup helper; [UID:0002P6] draw-record helper; [UID:0002KU] ResourceLayout successor; [UID:000174] mixed ResourceLayoutTable aggregate; [UID:0000UN] EPF archive metadata declarations; `by-file/ResourceLayoutTable.md`; `by-class/ResourceLayoutTable.md`; generated `ImageFrameTable.cpp` and `ResourceLayoutTable.cpp`; tracker/coverage rows.
- Lifecycle note: this is a report-only B-agent artifact; validator-owned report location and lifecycle history determine current lifecycle state after supervisor processing. No lifecycle command was run by B013.

## Executive Recommendation
- Keep UID00031U assigned to [UID:0000K1] and emitted through [UID:0000K1]. Do not move it to ResourceLayoutTable, ResourceLayoutTable class, the broad [UID:000174] aggregate, DATFile, a consumer image/effect class, or a no-owner/non-emitting state.
- Raise target score to `88/90` after incorporating the current direct MCP evidence. Do not raise higher because no caller/xref/function object/original symbol proof exists.
- Preserve the existing formal C++ body unchanged. It exactly models the stack arguments, 24-byte record stride, table `+0x08` record pointer, 16-byte `movups` rectangle copy, and `ret 0x0c`.
- Preserve precise boundaries: `0x004d1704-0x004d1710` is twelve `CC` bytes before the helper, UID00031U is `0x004d1710-0x004d172d`, and `0x004d172d-0x004d1730` is three `CC` bytes before successor `sub_4D1730`.

## Supervisor Active Recheck
- Supervisor/user instruction: create/update direct UID00031U B-agent report at `tools/leaser/Agents/Agent-B013/research/00031U-FrameRecordRectCopyHelper-source-quality.md` using live IDA MCP and report-only scope.
- Split repair before final master report: not required. The exact child page already exists and covers the half-open raw helper range.
- Source-bearing children in scope: UID00031U is the source-bearing target. Sibling UID00031T is related evidence only and has its own B004 report observed in active research at search time. No new child page is recommended in this report.

## Inference Research Guidance Check
- `by-structure.md` says singular `by-memory` pages carry exact raw function/helper evidence and formal C++ only when `RECONSTRUCTABLE:TRUE`, nonblank emitter route, and combined score above `85` are satisfied. UID00031U clears the eligibility gate.
- Existing documentation assumptions treated as uncertain: B006/B001 old reports are leads only; exact original helper name `CopyFrameRecordBounds`, type names `ArchiveMetadataTable`/`PackedArchiveRecord`, and field name `bounds` remain inferred source-facing names; no-xref raw helper reachability remains a real cap.
- IDA fact: current MCP raw bytes, instruction query, function inventory, xrefs, pointer-pattern search, and successor analysis.
- Documentation evidence: target/support by-* pages, generated `ImageFrameTable.cpp`, tracker/coverage rows, and opened old reports.
- Inference: source-facing helper/type/field names and file-local helper placement in `NexusTK/render/ImageFrameTable.cpp`.
- Wave2/Wave3 mentions encountered: only historical/generated lead context in support docs; no Wave2/Wave3 output was used as authority.

## Heuristic / Inference Reanalysis And Validation
- Range/function modeling: current MCP `lookup_funcs` reports no function at `0x004d1710`, `0x004d172c`, or `0x004d172d`. `entity_query(functions, 0x004d1600-0x004d1780)` returns only `sub_4D1600`, `sub_4D1730`, and `sub_4D1780`, proving UID00031U remains an unmodeled raw helper island.
- Boundary and byte validation: `get_bytes 0x004d1704 size 44` shows twelve `0xcc` bytes, the exact 29-byte helper body, and three `0xcc` bytes. `int_convert` verifies `0x1d == 29`, `0x18 == 24`, and `0x10 == 16`.
- Instruction semantics: `insn_query 0x004d1710-0x004d172d` decodes 11 instructions: prologue, load frame index from `[ebp+0x0c]`, compute `index * 3`, load table from `[ebp+0x08]`, read record base from table `+0x08`, load 16 bytes from `[recordBase + (index * 3) * 8]`, write 16 bytes to `[ebp+0x10]`, and return `0x0c`.
- C++ validation: `(index * 3) * 8` is the 24-byte `PackedArchiveRecord` stride; the 16-byte `movups` load/store is exactly `record->bounds` copied into `*outBounds`. The existing `CopyFrameRecordBounds` body is source-shaped and accurate.
- Name validation: `ArchiveMetadataTable`, `PackedArchiveRecord`, `records`, and `bounds` are not original-symbol proof, but they are the strongest source-facing names because UID0000UN formally declares the same layout and UID0002P4/UID0002P6 use the same record model in generated `ImageFrameTable.cpp`.
- Ownership validation: ImageFrameTable remains the best owner because UID00031U uses the same 12-byte table header and 24-byte frame-record array as `LoadImageFrameTable`, `LoadFrameDrawRecord`, and sibling UID00031T. The no-xref state weakens reachability proof but does not create stronger ResourceLayout or consumer ownership.
- Rejected alternatives:
  - ResourceLayoutTable ownership rejected: successor `0x004d1730` is a separate modeled `thiscall` frame-size accessor with one caller and ResourceLayoutNameRecord `+0x22/+0x24` field reads; UID00031U is a three-argument raw helper over ImageFrameTable records.
  - Merge into UID00031T or UID0002P6 rejected: there are `CC` alignment spans at `0x004d1704-0x004d1710` and `0x004d165d-0x004d1660`, and current IDA inventory does not model a larger function.
  - No-code/non-emitting rejected: target already emits source-shaped code through [UID:0000K1], and current bytes prove a compact source helper body.
  - DATFile or MemoryMan ownership rejected: UID00031U has no calls and touches no DATFile/MemoryMan state; it only reads an already-loaded metadata table.
  - Caller/consumer ownership rejected: current xref and pointer-pattern checks found no direct caller or pointer route.
- Unresolved issue remaining: exact original helper spelling and original linkage/staticness are not recoverable from current evidence. This caps confidence, but it does not block owner, emitter route, score improvement, or formal C++.

## Evidence Standards Used
- Evidence types used: live IDA MCP `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `get_bytes`, `insn_query`, `disasm`, `decompile`, `callees`, `analyze_function`, `xrefs_to`, `xref_query`, `find_bytes`, `make_signature_for_range`, and `int_convert`; target/support by-* docs; generated output; tracker/coverage rows; opened old reports as leads.
- Evidence strength: strong for exact range, bytes, instruction behavior, C++ equivalence, successor separation, and no-xref/pointer negatives. Medium-high for source name and owner because no direct caller or original symbol exists.
- Evidence ladder: MCP facts establish binary behavior and negative xref state; support docs establish accepted structure names and ImageFrameTable route; inference supplies helper name/static file-local source shape.
- Tool limitations: IDA cannot decompile UID00031U as a function because no function object exists at the raw helper start. Instruction-level evidence is therefore the authority for this target body.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `initialize` returned MCP protocol `2025-06-18`, server `ida-pro-mcp` version `1.0.0`.
  - `tools/list` was checked for schema-current tool availability.
  - `idb_list` returned active session `supervisor_recovery_20260705`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `19604`, `is_analyzing:false`.
  - `server_health(database=supervisor_recovery_20260705)` returned `status:ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
  - `lookup_funcs` checked `0x004d0f50`, `0x004d15c5`, `0x004d15d0`, `0x004d15fc`, `0x004d1600`, `0x004d165d`, `0x004d1660`, `0x004d1704`, `0x004d1710`, `0x004d172c`, `0x004d172d`, `0x004d1730`, `0x004d1773`, and `0x004d1780`.
  - `entity_query(functions, 0x004d1600-0x004d1780)` returned only `sub_4D1600`, `sub_4D1730`, and `sub_4D1780`.
  - `get_bytes` confirmed exact helper bytes and boundary padding at `0x004d1704-0x004d1730`.
  - `insn_query` and `disasm 0x004d1710` decoded the raw helper and successor instructions.
  - `decompile 0x004d1710` failed because no function is modeled; `callees 0x004d1710` returned `No function found`.
  - `xrefs_to` and `xref_query` confirmed zero xrefs to `0x004d1704`, `0x004d1710`, and `0x004d172d`; successor `0x004d1730` has one code xref from `0x004e99b4`.
  - `find_bytes` for VA/RVA pointer patterns `10 17 4D 00`, `2D 17 4D 00`, `10 17 0D 00`, and `2D 17 0D 00` found zero matches.
  - `make_signature_for_range 0x004d1710-0x004d172d` returned a unique signature matching the exact 29-byte body.
  - `analyze_function 0x004d1730` confirmed the successor is ResourceLayout-style `sub_4D1730`, size `67`, callees `sub_4D17C0` and `sub_4D0120`, one caller `sub_4E9950`, and field reads at offsets `+0x24` and `+0x22`.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target UID00031U; support [UID:0000K1], [UID:000176], [UID:00031T], [UID:0002P4], [UID:0002P5], [UID:0002P6], [UID:0002KU], [UID:000174], [UID:0000UN], `by-file/ResourceLayoutTable.md`, and `by-class/ResourceLayoutTable.md`.
  - Generated `auto-generated/NexusTK/render/ImageFrameTable.cpp` and `auto-generated/NexusTK/render/ResourceLayoutTable.cpp`.
  - Tracker rows in `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and secondary `project-level/-auto-completion-stats.md`.
  - Old report search across executed reports and active agent research, bounded to the required terms above.
- Negative checks performed: no direct UID00031U report; no function at target start/end; no xrefs to target start/end; no VA/RVA pointer hits; no callees/decompile; no ResourceLayout `this`/caller proof; no evidence for no-code or no-owner disposition.
- Failed, unavailable, or intentionally skipped checks and why: MCP was available. One local PowerShell wrapper attempt accidentally dropped the `database` argument and returned MCP `database is required`; the same calls were rerun successfully and no evidence from the rejected wrapper call was used. Validators and lifecycle commands were intentionally not run in report-only mode.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00031U-01 | UID00031U exact range is `0x004d1710-0x004d172d`, a 29-byte raw helper bracketed by `CC` alignment. | 0.99 | MCP `lookup_funcs`, `entity_query`, `get_bytes`, `insn_query`, `int_convert`. | Target Boundary Evidence; aggregate child inventory. | incorporate | applied |
| C-00031U-02 | IDA has no modeled function at `0x004d1710`, `0x004d172c`, or `0x004d172d`; decompile/callee queries fail because no function exists. | 0.99 | MCP `lookup_funcs`, `decompile`, `callees`. | Target Current IDA Status; Score Rationale. | incorporate | applied |
| C-00031U-03 | Body computes a 24-byte record stride, reads table `+0x08`, copies 16 bytes, and returns `0x0c`. | 0.99 | MCP `insn_query`, `disasm`, `get_bytes`. | Target Behavior; formal C++ rationale. | incorporate | applied |
| C-00031U-04 | Existing formal C++ `CopyFrameRecordBounds` is behavior-correct and should remain unchanged. | 0.96 | Instruction semantics plus UID0000UN declarations and generated output. | Target formal `RECONSTRUCTION_CPP CODE`. | already-present | already-present |
| C-00031U-05 | `ArchiveMetadataTable`, `PackedArchiveRecord`, `records`, and `bounds` remain best source-facing inferred names. | 0.9 | UID0000UN declarations, UID0002P4/UID0002P6/UID00031T support, generated `ImageFrameTable.cpp`. | Target Source Notes; ImageFrameTable support docs. | incorporate | applied |
| C-00031U-06 | Owner/emitter should remain [UID:0000K1] `ImageFrameTable`. | 0.93 | Shared record model, adjacency, current by-file route, generated output. | Target metadata; by-file ImageFrameTable row/prose. | incorporate | applied |
| C-00031U-07 | ResourceLayoutTable ownership is rejected despite successor adjacency. | 0.95 | MCP successor `analyze_function`, ResourceLayout docs, target record semantics. | Negative Evidence; support docs unchanged or narrow note. | reject-invalid | applied |
| C-00031U-08 | No-code/non-emitting and broad aggregate ownership are rejected. | 0.95 | Existing emitted body, by-structure rules, current generated output, UID000176 non-emitting aggregate policy. | Target Reconstruction Notes; aggregate support. | reject-invalid | applied |
| C-00031U-09 | Recommended score is `88/90`, not current `86/89` and not final-audit tier. | 0.88 | Current direct MCP recheck, old-report search, support docs, generated output, negative reachability proof. | Target metadata and score rationale. | incorporate | applied |
| C-00031U-10 | Support docs need only narrow synchronization; ResourceLayout docs do not require edits for this target. | 0.86 | Current support docs and successor analysis. | Recommended Support Doc Changes. | incorporate | applied |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation: exact 29-byte raw body, normal prologue, `ret 0x0c`, 24-byte stride, table record pointer at `+0x08`, one 16-byte `movups` copy, unique signature, and stable boundary padding.
- Corroborating documentation/generated-report evidence: UID0000UN declares the record/table types; UID0002P4 and UID0002P6 use the same table and record model; generated `ImageFrameTable.cpp` already emits UID00031U body under [UID:0000K1].
- Strongest inference chain and why it is sufficient: direct binary copy semantics plus accepted `PackedArchiveRecord` layout make `*outBounds = record->bounds` exact; ImageFrameTable source placement follows the shared frame-record helper family and is stronger than mere ResourceLayout address adjacency.

## IDA MCP Facts
- Function/range facts: no function at `0x004d1710`, `0x004d172c`, or `0x004d172d`; successor `0x004d1730 -> sub_4D1730`, size `0x43`; previous modeled function in bounded query is `sub_4D1600`, size `0x5d`.
- Data/table/padding facts: twelve `0xcc` bytes at `0x004d1704-0x004d1710`; target bytes at `0x004d1710-0x004d172d`; three `0xcc` bytes at `0x004d172d-0x004d1730`.
- Xref facts: zero xrefs to `0x004d1704`, `0x004d1710`, and `0x004d172d`; zero VA/RVA pointer-pattern hits for target start/end; successor `0x004d1730` has one code xref from `0x004e99b4`.
- Vtable/global/type facts: UID00031U has no direct vtable/global/type xref; type interpretation comes from UID0000UN and sibling helper docs.
- Negative IDA facts: no decompile, no callees, no function object, no pointer route, no direct caller.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004d1600-0x004d165d` | [UID:0002P6] `LoadFrameDrawRecord` | Modeled ImageFrameTable frame draw-record projection | TRUE | [UID:0000K1] | `88/92` | sibling support |
| `0x004d165d-0x004d1660` | padding | Three `CC` bytes before UID00031T | false/padding | ignored support | n/a | alignment |
| `0x004d1660-0x004d1704` | [UID:00031T] `FrameRecordPayloadCopyHelper` | Raw ImageFrameTable payload-copy helper | TRUE | [UID:0000K1] | `86/89`; B004 report observed in active research at search time recommends `88/90` | sibling support |
| `0x004d1704-0x004d1710` | padding | Twelve `CC` bytes before UID00031U | false/padding | ignored support | n/a | alignment |
| `0x004d1710-0x004d172d` | [UID:00031U] target | Raw bounds-copy helper | TRUE | [UID:0000K1] | callback-applied `88/90` | exact report target |
| `0x004d172d-0x004d1730` | padding | Three `CC` bytes before ResourceLayout successor | false/padding | ignored support | n/a | alignment |
| `0x004d1730-0x004d1773` | [UID:0002KU] `ResourceLayoutTableGetFrameSize` | Separate ResourceLayout frame-size accessor | TRUE | [UID:0000BY] | `90/92` | rejected owner alternative/successor |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004d1704` | zero xrefs | Alignment start before UID00031U; not a caller target. |
| `0x004d1710` | zero xrefs; no VA/RVA pointer-pattern hits | Raw UID00031U start has no known caller or pointer route. |
| `0x004d172d` | zero xrefs; no VA/RVA pointer-pattern hits | Target end/alignment start is not referenced. |
| `0x004d1730` | one code xref from `0x004e99b4` in `sub_4E9950` | Separate ResourceLayout successor has its own caller; does not prove UID00031U ownership. |
| `sub_4D1730` | callees `sub_4D17C0`, `sub_4D0120` | ResourceLayout lazy lookup/load path, not ImageFrameTable record copy. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: UID00031U target, UID0000K1 file page, UID000176 neighborhood map, UID0000UN declarations, UID0002P4 loader, UID0002P6 draw-record helper, UID00031T sibling helper, generated `ImageFrameTable.cpp`.
- Existing docs that are stale, incomplete, or contradicted: target lacks current session `supervisor_recovery_20260705` evidence, pointer-pattern negatives, unique signature, and direct report score rationale. UID000176 and UID0000UN contain some stale family wording around UID0002P4 no-code history or adjacent helper pages as future work.
- Generated/coverage report state: generated `ImageFrameTable.cpp` header is `validator-command-id: 000000007463`, `validator-refreshed-at: 2026-07-05T23:26:35-04:00`, and UID00031U appears with `Completion:86 | Confidence:89`. `auto-generated/-ag-memory-coverage.md` marks UID00031U as coded, owner/emitter `0000K1`, generated path `auto-generated/NexusTK/render/ImageFrameTable.cpp`.

## Ranked Ownership Analysis

### 1. [UID:0000K1] ImageFrameTable
- Evidence for: owns current generated route; contains the loader, cleanup helper, draw-record helper, sibling raw helper, and shared table/record declarations; UID00031U reads exactly that record model; generated `ImageFrameTable.cpp` already emits UID00031U.
- Evidence against: no direct xref/caller proves original linkage; exact helper name is inferred.
- Decision: best direct semantic owner and emitter. Keep `CANONICAL_OWNER:0000K1`, `EMITTER_UIDS:0000K1`.

### 2. [UID:000176] ImageFrameTable helper neighborhood
- Evidence for: records the exact child neighborhood and boundary split.
- Evidence against: intentionally `RECONSTRUCTABLE:FALSE`, owner `NONE`, blank emitter/code; exact child pages own source bodies.
- Decision: support/index page only. Do not move ownership to this aggregate.

### 3. [UID:0000N5]/[UID:0000BY] ResourceLayoutTable
- Evidence for: successor function starts at `0x004d1730` and broad aggregate [UID:000174] includes both families.
- Evidence against: successor is a separate modeled ResourceLayout accessor with `this`, lazy lookup/load callees, one caller, and ResourceLayoutNameRecord dimensions; UID00031U has no `this`, no caller, and uses ImageFrameTable `ArchiveMetadataTable` record layout.
- Decision: reject as owner/emitter for UID00031U. No ResourceLayout support-doc edit is required unless supervisor wants a narrow "current B013 recheck rejected UID00031U ownership" note.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file. Keep `NexusTK/render/ImageFrameTable.cpp`.
- Likely full contents: existing ImageFrameTable family: shared declarations, `LoadImageFrameTable`, `DestroyOwnedImageBlock`, `LoadFrameDrawRecord`, `CopyFrameRecordPayloads`, and `CopyFrameRecordBounds`.
- Candidate related items that belong: UID0000UN, UID0002P4, UID0002P5, UID0002P6, UID00031T, UID00031U.
- Candidate related items rejected: ResourceLayout class methods/raw ResourceLayout helpers, DATFile archive primitives, MemoryMan, and consumer image/effect classes.
- Standalone, narrow, or broad source-file inference: narrow helper inside existing broad `ImageFrameTable.cpp` source root.

## Source Placement
- Recommended source file/class/global/module placement: file-local or private helper in `NexusTK/render/ImageFrameTable.cpp`, routed through [UID:0000K1].
- Why this placement fits source-tree and subsystem context: it operates on the `ArchiveMetadataTable`/`PackedArchiveRecord` model created by `LoadImageFrameTable` and projected by `LoadFrameDrawRecord`.
- Rejected placements and why: ResourceLayout owns different lazy resource-layout records; DATFile owns archive access only; consumers have no caller evidence; no-owner/non-emitting contradicts current emitted source-ready helper bytes.
- Remaining placement uncertainty, if any: original linkage/static spelling and helper name are unproven, so source placement is strong but not final-audit.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: UID00031U is `[0x004d1710,0x004d172d)`. Preceding `0x004d1704-0x004d1710` is twelve `CC` bytes. Following `0x004d172d-0x004d1730` is three `CC` bytes.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no split/new child recommended. Keep UID00031U exact; leave padding spans ignored; keep successor UID0002KU separate.
- Padding/table/data/code distinctions: target bytes decode as source-looking code; adjacent `CC` spans are alignment; successor is modeled ResourceLayout code.
- Parent/container impact: [UID:000176] and [UID:000174] should preserve exact child/aggregate distinctions and not absorb UID00031U into a broad source owner.

## Negative Evidence Summary
- No direct `TARGET-REPORT-UID:00031U` old report exists.
- No IDA function object exists at the target start or end.
- No direct xrefs, code xrefs, data xrefs, VA pointer hits, or RVA pointer hits were found for target start/end.
- No decompiler output or callees exist because IDA does not model this raw helper as a function.
- No evidence supports ResourceLayout ownership; successor adjacency is weaker than record-layout semantics and generated ImageFrameTable route.
- No evidence supports changing formal C++ to use MemoryMan or DATFile helpers; UID00031U has no calls.
- No evidence supports raising to `95+` or final-audit status while original names/linkage/reachability remain unresolved.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: keep `CopyFrameRecordBounds`, `ArchiveMetadataTable`, `PackedArchiveRecord`, `records`, and `bounds` as source-facing inferred names. If target prose is refreshed, label them inferred/descriptive rather than original-symbol proof.
- Evidence for each proposed name/type/comment: UID0000UN formal declarations, UID0002P4/UID0002P6/UID00031T sibling usage, generated `ImageFrameTable.cpp`, and current MCP record-stride/bounds-copy instructions.
- Items intentionally left unchanged and why: do not create/promote an IDA function or rename the IDB raw start during this B-agent report-only pass; no current xref/function object proves a safe IDA DB edit.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested; B-agent report-only scope forbids IDA DB edits.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. UID00031U is `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:0000K1`, clears the combined-score gate, and current direct MCP evidence supports the body.
- Recommended code: keep exact formal `RECONSTRUCTION_CPP CODE` content semantically unchanged:

```cpp
void CopyFrameRecordBounds(const ArchiveMetadataTable *table,
                           int frameIndex,
                           RectBounds *outBounds)
{
    const PackedArchiveRecord *record = &table->records[frameIndex];
    *outBounds = record->bounds;
}
```

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: reads the second stack argument as the frame index, selects `table->records + 24 * frameIndex`, copies exactly 16 bytes from the record start to the caller output, and returns after cleaning 12 bytes of arguments.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: compact file-local helper over a loaded metadata table, ordinary struct names, and a direct bounds assignment rather than decompiler temporaries or raw SSE intrinsics.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `ArchiveMetadataTable`, `PackedArchiveRecord`, `records`, `RectBounds`, and `bounds`.
- Naming/coding style convention used and evidence for consistency: matches current generated ImageFrameTable helper family and accepted UID0000UN declarations.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes applied or recommended: callback applied current MCP/session evidence to the target, preserved C++ unchanged, raised score to `88/90`, and refreshed narrow ImageFrameTable support docs where stale/missing.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:0000K1`; keep `EMITTER_UIDS:0000K1`; keep `RECONSTRUCTABLE:TRUE`; leave `EMITTER_POSITION_OPTIONAL` blank.
- Exact items left no-owner/non-emitting and why: none inside UID00031U. Padding spans remain ignored/alignment; [UID:000176] remains non-emitting aggregate support.
- Exact future work, if any, outside this assignment scope: none for UID00031U. Sibling UID00031T source-body cleanup is covered by the B004 report observed in active research at search time and should not be folded into this target.

## Recommended Target Doc Changes
- Target path: `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`; callback status: applied.
- Exact report facts to incorporate:
  - Add current MCP session `supervisor_recovery_20260705` health/session evidence.
  - Record `lookup_funcs`: no function at `0x004d1710`, `0x004d172c`, or `0x004d172d`; successor `0x004d1730 -> sub_4D1730`, size `0x43`.
  - Record `entity_query` bounded inventory: only modeled functions in `0x004d1600-0x004d1780` are `sub_4D1600`, `sub_4D1730`, and `sub_4D1780`.
  - Record exact boundary bytes and instructions: twelve prepad `CC`, 29-byte helper, three postpad `CC`, 24-byte stride, 16-byte `movups` copy, `ret 0x0c`.
  - Record zero xrefs and zero VA/RVA pointer-pattern hits for start/end.
  - Record unique signature for `0x004d1710-0x004d172d`.
  - Record successor ResourceLayout separation and rejected ResourceLayout ownership.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Applied `COMPLETION:88`.
  - Applied `CONFIDENCE:90`.
  - Kept `CANONICAL_OWNER:0000K1`.
  - Kept `RECONSTRUCTABLE:TRUE`.
  - Kept `EMITTER_UIDS:0000K1`.
  - Kept blank `EMITTER_POSITION_OPTIONAL`.
  - Kept formal C++ body semantically unchanged.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve no-modeled-function/no-xref caveat, inferred-name caveat, ResourceLayout rejection, broad aggregate rejection, and no-code rejection.

## Recommended Support Doc Changes
- Support path: `by-file/ImageFrameTable.md`.
  - Exact report facts incorporated: UID00031U row/prose now mentions the current B013 direct recheck confirming the existing `CopyFrameRecordBounds` body remains accurate, still ImageFrameTable-owned at `88/90`, and still capped by no function/xrefs/pointer hits/original helper/type/linkage proof.
  - Metadata/link/score/coverage/source-placement changes: no file score or path change recommended.
- Support path: `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`.
  - Exact report facts incorporated: updated narrow family text and child rows to record UID00031U direct recheck as preserving the exact raw bounds-copy child at `88/90`.
  - Metadata/link/score/coverage/source-placement changes: no aggregate score change recommended; preserve `RECONSTRUCTABLE:FALSE`, owner `NONE`, blank emitter/code.
- Support path: `by-item/EPFArchiveMetadataTable.md`.
  - Exact report facts incorporated or excluded: no edit was needed because the page already historicalizes the stale adjacent-helper wording, already states UID00031T and UID00031U have exact by-memory pages, and already records that UID00031U copies the 16-byte bounds block using the shared `ArchiveMetadataTable`/`PackedArchiveRecord` declarations.
  - Metadata/link/score/coverage/source-placement changes: no score/metadata change made.
- Support path: `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md`.
  - Exact report facts to incorporate: no required edit. Current docs already classify UID00031U as ImageFrameTable helper and the aggregate as mixed/non-emitting. Optional narrow note could mention current B013 recheck if the supervisor wants current-session provenance.
  - Metadata/link/score/coverage/source-placement changes: none.
- Support paths: `by-file/ResourceLayoutTable.md`, `by-class/ResourceLayoutTable.md`, and [UID:0002KU].
  - Exact report facts to incorporate: no required edit. They already distinguish ResourceLayout methods/raw helpers from ImageFrameTable helpers; UID00031U does not belong there.
  - Metadata/link/score/coverage/source-placement changes: none.

## Score And Metadata Recommendation
- Current score/metadata: `86/89`, `CANONICAL_OWNER:0000K1`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K1`, blank emitter position, formal C++ present.
- Recommended score/metadata: `88/90`, same owner/reconstructable/emitter fields, same formal C++ semantics.
- Score rationale and reason not higher/lower:
  - Higher than `86/89`: this direct report adds current live MCP session health, function inventory, byte and instruction proof, xref/data-pointer negatives, unique signature, generated-output state, support-doc review, direct old-report search, and explicit rejected ownership alternatives.
  - Not higher than `88/90`: no modeled function, no decompile, no caller/xref/pointer route, no recovered original helper name, and no original type names. Reachability and exact original spelling remain unresolved.
  - Not lower than `88/90`: behavior, boundaries, C++ equivalence, owner/emitter route, and support type names are now directly rechecked and implementation-ready.
- Score-improvement attempt: checked every assignment blocker: raw no-function state, no xrefs/pointer refs, exact range/padding, 24-byte stride, 16-byte rectangle copy, relationship to UID00031T and UID0002P6, ResourceLayout alternative, formal C++ eligibility, owner/emitter route, generated output, old reports, and support docs. Each is resolved or documented as an evidence-backed score cap.
- Metadata fields to change or leave unchanged: change only `COMPLETION` and `CONFIDENCE`; leave owner, reconstructable, emitter route, emitter position, and formal C++ unchanged.

## Open Questions With Attempted Resolution
- Open questions found:
  - Is the formal C++ accurate enough?
  - Are `CopyFrameRecordBounds`, `ArchiveMetadataTable`, `PackedArchiveRecord`, `records`, and `bounds` the best source-facing names?
  - Should the helper remain ImageFrameTable-owned despite no xrefs and successor ResourceLayout adjacency?
  - Should support docs receive more detail?
- Evidence checked for each:
  - Formal C++ checked against current `insn_query`, `disasm`, `get_bytes`, and generated output.
  - Names checked against UID0000UN declarations, UID0002P4/UID0002P6/UID00031T sibling docs, and generated `ImageFrameTable.cpp`.
  - Ownership checked against current xrefs/pointer negatives, successor `analyze_function`, ResourceLayout docs, ImageFrameTable docs, and old reports.
  - Support docs checked across target, ImageFrameTable file/aggregate, EPFArchiveMetadataTable, ResourceLayout file/class/aggregate, and generated output.
- Best supported resolution or inference:
  - Formal C++ is accurate and should stay unchanged.
  - Current names are inferred but best-supported and consistent with accepted ImageFrameTable declarations.
  - ImageFrameTable ownership remains strongest; ResourceLayout adjacency is rejected.
  - Target and narrow ImageFrameTable support docs were refreshed during callback; EPF support was already present at same-or-greater detail; ResourceLayout docs need no required edit.
- Questions remaining unresolved, exhaustive evidence proving why no defensible answer is safe now, score/C++ impact, and unavailable future evidence required: exact original helper/linkage/type names and reachability route remain unresolved after xref and pointer-pattern checks. Future evidence would need original symbols/source, a recovered caller/pointer table, or an IDA function/pointer promotion with proof. Impact: score cap at `88/90`; no C++ or owner blocker.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Applicable only when an explicit manual `-coverage-report.md` or supervisor-owned tracker row needs a change.
- File/placement: not applicable.
- Exact replacement/insert/delete text: none.
- Reason B agent must not apply it directly: generated tracker/coverage files and supervisor ledgers are outside B013 report-only write scope. Source by-* metadata plus scoped validators should refresh generated coverage after an accepted implementation callback.

## Follow-Up Actions
- Supervisor-owned lifecycle actions: this report records that B013 completed the implementation callback and scoped validation batch. Validator-owned report location and lifecycle history determine the artifact state after any later supervisor processing.
- A-agent actions: none requested.
- B013 follow-up actions: none for UID00031U unless a supervisor-owned callback or repair request is issued.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for `88/90`, not final-audit.
- Remaining uncertainty: original helper/type names, linkage/staticness, and reachability route for a raw no-xref helper.

## Validator Results
- Report-only pass validators: none; validators were intentionally not run before Gate 1.
- Callback scoped validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md --apply --queue-timeout 240 --wait-generated`: command_id `000000007492`, command_timestamp `2026-07-06T00:43:04-04:00`, exit code `0`, `ok: 1`, `completion_update 00031U ... 88`, `confidence_update 00031U ... 90`, `autogen_cpp_update 0000K1 auto-generated/NexusTK/render/ImageFrameTable.cpp`, `generated_refresh: completed`.
  - `python .\tools\validator.py --mode file --file by-file/ImageFrameTable.md --apply --queue-timeout 240`: command_id `000000007493`, command_timestamp `2026-07-06T00:43:20-04:00`, exit code `0`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md --apply --queue-timeout 240`: command_id `000000007494`, command_timestamp `2026-07-06T00:43:27-04:00`, exit code `0`, `ok: 1`, `generated_refresh: deferred`.
- Generated/queue freshness check: `python .\tools\validator.py --queue-status` returned command_id `000000007496`, command_timestamp `2026-07-06T00:44:04-04:00`, exit code `0`, worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- Generated `ImageFrameTable.cpp` freshness: `auto-generated/NexusTK/render/ImageFrameTable.cpp` header is `validator-command-id: 000000007493`, `validator-refreshed-at: 2026-07-06T00:43:20-04:00`; UID00031U appears as `Completion:88 | Confidence:90` with unchanged `CopyFrameRecordBounds` body.
- Unresolved validator warnings/errors: no target-specific failures. Validator output included existing broad generated metadata/children/emitter notices and validator-owned generated side effects; no manual generated, coverage, validator-state, lifecycle, or archive file edits were made by B013.

## Changed Files
- Created during report-only pass: `tools/leaser/Agents/Agent-B013/research/00031U-FrameRecordRectCopyHelper-source-quality.md`.
- Manually modified during implementation callback:
  - `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`
  - `by-file/ImageFrameTable.md`
  - `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md`
  - `tools/leaser/Agents/Agent-B013/research/00031U-FrameRecordRectCopyHelper-source-quality.md`
- Support docs checked but not edited: `by-item/EPFArchiveMetadataTable.md` was already at same-or-greater detail; ResourceLayout support docs had no direct contradiction and were not edited.
- Validator-owned generated side effects from scoped validators included refreshed generated metadata/coverage/tracker/projected-stats output and `auto-generated/NexusTK/render/ImageFrameTable.cpp`; B013 did not manually edit generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers.
- Leases: B013 leased `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`, `by-file/ImageFrameTable.md`, and `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md` immediately before editing; release command returned `Success` for all three. Follow-up `current_leases.md` showed no active B013 leases.
- Report execution: not run by B013. B agents must never run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, manual report moves, or archive moves.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: this report was created as a report-only evidence package and no by-* implementation was attempted.
- [x] Target/support docs to update identified. Proof: target UID00031U; support [UID:0000K1], [UID:000176], and [UID:0000UN] only where stale; ResourceLayout support docs checked with no required edit.
- [x] Current target state and actual evidence checked recorded. Proof: current metadata, generated state, current MCP session, bytes, instructions, xrefs, pointer negatives, and support docs are recorded above.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C-00031U-01 through C-00031U-10 are listed with `proposed` verification states.
- [x] Metadata/score changes to apply. Proof: recommended target update from `86/89` to `88/90`; owner/reconstructable/emitter unchanged.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or evidence-backed no-improvement proof. Proof: no-function, no-xref, pointer-negative, original-name, and ResourceLayout-adjacency blockers are resolved or documented as score caps.
- [x] Owner/emitter/reconstructable changes to apply. Proof: no owner/emitter/reconstructable change recommended; keep [UID:0000K1], `TRUE`, [UID:0000K1].
- [x] Split/rename/new-child changes to apply. Proof: none recommended; exact child already exists and padding/successor boundaries are documented.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable. Proof: keep `ImageFrameTable.cpp`; preserve exact padding; no IDA DB edits requested.
- [x] First-draft C++ or no-code proof to apply. Proof: existing formal C++ is eligible and should remain semantically unchanged; exact code block is supplied.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank. Proof: not applicable; target is project source helper, not third-party import.
- [x] Exact target/support doc facts to incorporate at report-level detail. Proof: recommended target/support changes list current MCP facts, generated state, old-report context, and negative evidence.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve. Proof: no-function/no-xref/no-pointer caveats, inferred-name caveat, ResourceLayout rejection, no-code rejection, and broad aggregate rejection are recorded.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable. Proof: historical/generated leads were not used as authority; current MCP/by-* docs drive the report.
- [x] Open questions to close or document as evidence-backed unresolved. Proof: exact original names/linkage/reachability remain unresolved with score impact only.
- [x] Validators to run. Proof: during implementation callback, run scoped validator for `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md --apply --queue-timeout 240 --wait-generated`; run support validators only for support docs actually edited.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply. Proof: generated `ImageFrameTable.cpp` should refresh UID00031U to `88/90` with unchanged body after accepted implementation validation; no manual coverage/tracker text is required.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: Gate 1 passed for SHA256 `E90FC625499F26770755B3BB0E57BEEF1F8CD6E6D26F62C8CD23F0CF683DE9A9`; callback scope named target/support docs and accepted facts.
- [x] All accepted target/support doc details incorporated at report-level detail: target now records current MCP session `supervisor_recovery_20260705`, no-function/no-decompile/no-callee state, bounded inventory, boundary bytes, 29-byte body, 24-byte stride, 16-byte `movups` copy, `ret 0x0c`, zero xrefs, zero VA/RVA pointer hits, unique signature, ResourceLayout separation, confidence caps, and rejected alternatives; `by-file/ImageFrameTable.md` and `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md` carry the narrow UID00031U support sync.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C-00031U-01 through C-00031U-10 now record `applied` or `already-present`.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target changed from `86/89` to `88/90`; `CANONICAL_OWNER:0000K1`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K1`, blank `EMITTER_POSITION_OPTIONAL`, exact range, and formal C++ semantics were preserved; no split/rename/new child was needed.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: target/support docs preserve no modeled function, no decompile, no caller/xref/pointer route, no original helper/type/linkage proof, ResourceLayout rejection, merge rejection, no-code/non-emitting rejection, DATFile/MemoryMan rejection, and caller/consumer rejection.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: exact original helper/type/member names, linkage/staticness, and reachability route remain confidence caps only; they do not block the accepted C++/owner/score.
- [x] Validators run and results recorded: commands `000000007492`, `000000007493`, and `000000007494` all exited `0` with `ok: 1`; queue status command `000000007496` confirmed no queued/processing validator or generated refresh jobs.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: target validator completed generated refresh; generated `ImageFrameTable.cpp` header is `validator-command-id: 000000007493`, `validator-refreshed-at: 2026-07-06T00:43:20-04:00`, and UID00031U is `88/90` with unchanged `CopyFrameRecordBounds`; no manual coverage/tracker text is required.
- [x] Lease release and write-scope boundary verified: B013 leases on the three edited by-* docs were released successfully, follow-up lease report showed no active B013 leases, and B013 did not manually edit generated/coverage/validator-state/lifecycle/archive/supervisor-ledger files.
- [x] Remaining unapplied accepted items listed with exact blocker: none. `by-item/EPFArchiveMetadataTable.md` was already at same-or-greater detail and ResourceLayout docs had no direct contradiction, so they were intentionally not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000007500","destination_path":"executed-b-agent-research/B013/00031U-FrameRecordRectCopyHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/00031U-FrameRecordRectCopyHelper-source-quality.md","timestamp":"2026-07-06T00:48:26-04:00","uid":"00031U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
