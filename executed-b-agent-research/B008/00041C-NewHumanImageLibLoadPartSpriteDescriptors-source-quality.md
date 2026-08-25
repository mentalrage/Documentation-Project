** TARGET-REPORT-UID:00041C **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00041C NewHumanImageLibLoadPartSpriteDescriptors Ownership / Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: promote [UID:00041C 0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors](../../../../../by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md) from no-owner support status to a class-owned, class-emitting `NewHumanImageLib::LoadPartSpriteDescriptors()` source method.
- Final disposition: source-authored method body under [UID:000092 NewHumanImageLib](../../../../../by-class/NewHumanImageLib.md), routed through [UID:0000LR NewHumanImageLib](../../../../../by-file/NewHumanImageLib.md). No split, merge, range repair, or generated-file edit is recommended.
- Required action: after supervisor acceptance, update the target and related support docs; set `CANONICAL_OWNER:000092`, `EMITTER_UIDS:000092`, `COMPLETION:88`, `CONFIDENCE:90`, keep `RECONSTRUCTABLE:TRUE`, and insert the formal first-draft C++ block supplied below.
- Confidence: high for function boundary, caller, owner/source placement, `.DSC` suffix, descriptor count/array allocation, packed descriptor field offsets, motion-indexed sequence table shape, and code eligibility; medium-high for exact original field and string-wrapper spellings.

## Supporting Research

## Target
- Target UID: `00041C`.
- Target path: `source-3/project-documentation/by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` lists UID `00041C` at `84/86`, combined `85.0`, `RECONSTRUCTABLE:true`, direct reports `0`.
- Original supervisor classification: report-first research assigned to Agent-B008 for the exact by-memory target; this report was later accepted for implementation callback.
- Pre-callback scores and parent state: target was `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank C++; parent class [UID:000092] was already a valid class route at `86/88`, and source file [UID:0000LR] was already the accepted `NexusTK/render/NewHumanImageLib.cpp` source root at `87/85`.

## Current Target State
- Existing metadata: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank emitter route, blank formal C++.
- Existing owner/emitter/reconstructable state: the page already says this is a source-authored helper, but it was kept below owner/emitter gate because descriptor row and nested mapping declarations were not yet synchronized when B011 created it.
- Existing C++/emitter state: no generated method body exists; current generated `auto-generated/NexusTK/render/NewHumanImageLib.cpp` calls `LoadPartSpriteDescriptors();` from the constructor but has no UID00041C body.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: older docs sometimes call the per-part descriptor files `<part-name>.tbl`; current MCP proves the suffix literal is `.DSC`. Older support docs use `hasPrimaryFrameData` / `hasSecondaryFrameData` as loose names, but the loader proves the bytes at descriptor `+0x10` and `+0x15` are counts used to allocate `2 * count` data blocks. This is a naming cleanup, not a remaining code blocker.
- Related target/support docs checked: [UID:000092] class, [UID:0000LR] file route, constructor [UID:0002JR], local cluster [UID:00017R], layout [UID:0001VF], destructor [UID:00017S], resource table [UID:0001RI], composition consumers [UID:000417], [UID:000437], [UID:000438], motion/layer table siblings [UID:000419], [UID:00041A], and sibling below-gate pages [UID:00041B], [UID:00041D].

## Executive Recommendation
- Best direct owner: [UID:000092] `NewHumanImageLib`.
- Source file: [UID:0000LR] `NexusTK/render/NewHumanImageLib.cpp`.
- Target disposition: exact reconstructable class method with first-draft C++; no child creation, range repair, or non-code classification.
- Score/metadata disposition: raise from `84/86` to `88/90`; set `CANONICAL_OWNER:000092`, `EMITTER_UIDS:000092`, keep `RECONSTRUCTABLE:TRUE`.
- Condition before implementation: supervisor acceptance of this report. No extra MCP availability, source-placement, or score-blocker condition remains for first-draft C++.

## Supervisor Active Recheck
- The active assignment is `B008-report-00041C-NewHumanImageLibLoadPartSpriteDescriptors-direct-research-20260630` from `Agent-B008/goal.md`.
- The assigned item did not require split repair before a final report. Current MCP confirms one modeled function beginning at `0x004e13b0`, size `0x446`, ending at `0x004e17f6`; `0x004e17f6` is not a function and the next function starts at `0x004e1800`.
- Every source-bearing child in scope was either checked as support evidence or rejected as a separate target. No new child is needed to emit UID00041C.

## Inference Research Guidance Check
- `by-structure.md` current owner/emitter rules were applied: a reconstructable code target with combined score above `85`, a valid direct owner, a nonblank emitter route, and formal C++ can emit. UID00041C currently fails only owner/emitter/C++ metadata, not source-authorship.
- IDA facts are kept separate from documentation evidence and inference. IDA proves the range, caller, `.DSC` literal xref, read sizes, allocations, object offsets, and callee set. Existing docs prove the accepted class/file route and adjacent support vocabulary. The exact original names for the first two descriptor dwords, the string wrapper, and some row fields remain inferred.
- Existing documentation assumptions treated as uncertain: `<part-name>.tbl` descriptor wording, `hasPrimaryFrameData` / `hasSecondaryFrameData` as boolean-only fields, and older "descriptor row/nested mapping typedefs not promoted" blocker text.
- Wave2/Wave3 mentions in old broad reports are stale for this project pass and were not used as current evidence. Stale TimerMgr reports that reuse UID text `00041C` for a different address were rejected as UID-collision artifacts because their paths and addresses do not match this target.

## Heuristic / Inference Reanalysis And Validation
- Generated name issue: IDA still names the function `sub_4E13B0`; source-facing `NewHumanImageLib::LoadPartSpriteDescriptors` is an accepted inferred name from constructor order, class docs, local cluster docs, and the `.DSC` loader behavior. This is implementation-ready inference, not original-symbol proof.
- Field naming issue: descriptor dwords at `+0x00` and `+0x04` are read but not strongly named by current consumers. The formal C++ should use neutral source-facing names such as `descriptorId` and `frameBase`, and the target doc should explicitly preserve that these two spellings are inferred. This limits score below `95` but does not block code.
- Packed descriptor issue: current MCP decompile proves packed offset writes at descriptor `+0x11` and `+0x16`, with count bytes at `+0x10` and `+0x15`. The best source-facing model is a packed 0x20-byte `NewHumanPartFrameDescriptor` containing count bytes and unaligned pointer fields. Older boolean wording should be refined in support docs.
- Sequence table issue: current MCP proves descriptor `+0x1a` stores the motion-count-sized sequence slot count as a word, descriptor `+0x1c` stores a `16 * motionCount` slot array, each slot initializes to `-1, -1, 0, NULL`, and populated file records select a slot by motion index. This resolves the old nested mapping blocker.
- Caller/reachability issue: current MCP proves exactly one code xref to `0x004e13b0`, from constructor address `0x004e017c` inside `sub_4DFD10`. This is expected constructor-time helper reachability, not dead code.
- Source placement issue: this body is an out-of-line class helper called from the constructor. It is not constructor inline code, a local-cluster container, a resource payload page, or a shared DAT/StringBase helper.
- Generated-output pollution issue: generated output is read-only evidence only. The absence of a UID00041C body in generated `NewHumanImageLib.cpp` is expected from the current blank owner/emitter state and must be fixed through by-* docs plus validator refresh, not manual generated edits.
- Raw helper roles: DAT file helpers `sub_49C130`, `sub_49C180`, `sub_49C310`, `sub_49C240`, `sub_49C160`, StringBase helpers around `0x582560` / `0x584540`, allocator `unknown_libname_19`, and security-cookie cleanup are dependencies or compiler/runtime lowering, not target owners.
- Rejected alternatives: leave no-owner/non-emitting is stale because the old blocker is now resolved; resource-page ownership overclaims file payload bytes as source code; constructor ownership would duplicate an out-of-line helper; local-cluster ownership would emit from a non-source container; DAT/StringBase helper ownership ignores the direct class state and caller.
- Remaining unresolved issue: exact original spellings for the string wrapper and some descriptor field names are not symbol-proven. This caps confidence but does not affect owner, emitter, split, or first-draft C++ eligibility.

## Evidence Standards Used
- Evidence types used: IDA MCP `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xref_query`, `entity_query`, `find_bytes`, `analyze_function`, `decompile`, `disasm`, and `callees`; existing by-* docs; generated reports; generated source read-only checks; old B-agent report searches; negative address/string checks.
- Evidence strength: strong because the current live MCP database is healthy, Hex-Rays ready, and all key facts come from exact-address or exact-byte calls. No broad unbounded MCP search was needed.
- Tool limitation: `entity_query strings` did not return the `.DSC` row because IDA string typing/caching does not expose the adjacent UTF-16 cluster cleanly, but `find_bytes` and the data xref to `0x0061c33c` prove the suffix.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed: current MCP reached `ida-pro-mcp 1.0.0`; `idb_list` reported active adopted worker session `supervisor_resume_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, PID `17592`, not analyzing. `server_health` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- Target MCP checks: `lookup_funcs 0x004e13b0` returned `sub_4E13B0`, size `0x446`; `lookup_funcs 0x004e17f6` returned not a function; `lookup_funcs 0x004e1800` returned successor `sub_4E1800`, size `0x1c5`; `xref_query 0x004e13b0` returned exactly one code xref, from `0x004e017c` inside constructor `sub_4DFD10`; `find_bytes` for UTF-16 `.DSC` returned one match at `0x0061c33c`; `xref_query 0x0061c33c` returned exactly one data xref from `0x004e1435` inside this target.
- Current decompile/disassembly checks: `analyze_function 0x004e13b0` reported size `1094`, one caller `sub_4DFD10`, 39 basic blocks, cyclomatic complexity 12, and DAT/StringBase/allocator/security-cookie callees. `decompile 0x004e13b0` and bounded `disasm` pages were checked for the descriptor loop, allocation sizes, packed offsets, sequence slot initialization, frame-record reads, explicit file close, and epilogue.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target page, class/file/layout/resource/local-cluster pages, constructor/destructor/composition/motion/layer sibling pages, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `project-level/-auto-completion-stats.md`, and generated `auto-generated/NexusTK/render/NewHumanImageLib.cpp`.
- Initial negative checks performed before callback implementation: generated output had no UID00041C body while the target was no-owner/non-emitting; no valid owner/emitter route existed other than class/file; `.DSC` did not appear via `entity_query strings` despite raw-byte and data-xref proof; stale UID-collision reports for TimerMgr were rejected by address/path mismatch.
- Callback verification update: scoped validators were run after implementation and are recorded in `Validator Results`. No IDA DB edits, manual generated edits, coverage-report edits, supervisor-ledger edits, executed-archive edits, lock-file edits, or subagents were used.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID00041C is one exact modeled function `0x004e13b0-0x004e17f6`, `sub_4E13B0`, size `0x446`. | High | Current MCP `lookup_funcs`; `disasm`; successor `0x004e1800`; `0x004e17f6` not a function. Callback proof: target `Status` records the exact range/size/successor facts and target validator `000000002110` passed. | Target `Status` / `Evidence` | incorporate | applied |
| C2 | The sole code caller is constructor `sub_4DFD10` at `0x004e017c`. | High | Current MCP `xref_query 0x004e13b0` include function. Callback proof: target evidence, constructor support note, class method table, and generated constructor call all route `LoadPartSpriteDescriptors()` to UID00041C. | Target `Evidence`; constructor support note; class method table | incorporate | applied |
| C3 | The loader builds per-part `<part-name>.DSC` paths, not `<part-name>.tbl` descriptor paths. | High | Current MCP `find_bytes` UTF-16 `.DSC` at `0x0061c33c`; data xref from `0x004e1435`; decompile string combine with part row name. Callback proof: target, local cluster, and resource docs now use `.DSC`; local/resource validators `000000002146` and `000000002148` passed. | Target `Behavior`; local cluster/resource support docs | incorporate | applied |
| C4 | The method reads a 23-byte file header and 4-byte descriptor count per part. | High | Current MCP decompile `sub_49C310(v41, v49, 23)` then `sub_49C310(v41, &v45, 4)`. Callback proof: target behavior and formal C++ carry the 23-byte header/count reads; target validator `000000002110` passed. | Target `Behavior`; formal C++ | incorporate | applied |
| C5 | Positive descriptor count allocates `32 * descriptorCount`, stores array at part `+0x3c`, count at part `+0x34`, and total raw-record count at part `+0x38`. | High | Current MCP decompile writes `v39[15]`, `v13[13]`, `v13[14]`; destructor and consumer docs confirm offsets. Callback proof: target behavior/C++ and layout support now record descriptor count/allocation behavior; validators `000000002110` and `000000002147` passed. | Target `Behavior`; layout support | incorporate | applied |
| C6 | Each 0x20 descriptor reads four dwords, with `+0x08` accepted as `drawIndexBase` and `+0x0c` accumulated as raw-record count. | High for offsets, medium-high for names | Current MCP decompile; UID000417/437/438 consumer docs; destructor cleanup. Callback proof: target descriptor layout and layout support now record packed 0x20 rows and keep `+0x00/+0x04` names caveated as inferred. | Target `Behavior`; layout support | incorporate | applied |
| C7 | Descriptor `+0x10/+0x15` bytes are counts; pointers at `+0x11/+0x16` receive `2 * count` allocations/read data. | High | Current MCP decompile stores byte count and unaligned pointer, reads `2 * v48` / `2 * v47`; destructor frees matching fields. Callback proof: target and layout docs now preserve count-bearing semantics; destructor/composition consumer harmonization was excluded as not needed because existing cleanup/consumer docs already supplied corroborating evidence and no accepted blocker required touching them. | Target `Behavior`; layout/destructor support | incorporate | applied |
| C8 | Descriptor sequence table stores motion-count slot count at `+0x1a` and a `16 * motionCount` slot array at `+0x1c`. | High | Current MCP decompile computes `(this[8]-this[7])/66`, allocates `16 * v19`, initializes each slot, writes `+26/+28`; motion loader confirms 0x42 motion stride. Callback proof: target, layout, class/file, and resource support docs now record the motion-count sequence slot shape. | Target `Behavior`; layout/composition support | incorporate | applied |
| C9 | Populated sequence records read motion index, second dword, frame count, and `9 * frameCount` rows of 4+1+4 bytes. | High | Current MCP decompile loop through `v40` and `v46`; UID000417/437/438 consume first dword as `recordIndex`. Callback proof: target sequence evidence and layout support now record the 9-byte row layout and inferred trailing field caveats. | Target `Behavior`; layout support | incorporate | applied |
| C10 | Old below-gate blocker is resolved enough for first-draft C++; exact original field spellings remain a confidence cap only. | Medium-high | Current MCP plus accepted destructor/layout/composition support docs. Callback proof: target was promoted to `88/90` with formal C++; class/file/constructor/local/resource docs supersede the old below-gate wording while preserving original-name caveats. | Target `Status`; score rationale; support docs | incorporate | applied |
| C11 | Direct owner/emitter should be UID000092 and source route UID0000LR. | High | Class/file docs; constructor caller; sibling helpers UID000417/419/41A already promoted through same route. Callback proof: target metadata is `CANONICAL_OWNER:000092` and `EMITTER_UIDS:000092`; class/file docs route UID00041C through `NexusTK/render/NewHumanImageLib.cpp`; generated output contains UID00041C body. | Target metadata; class/file docs | incorporate | applied |
| C12 | Stale resource/local-cluster `.tbl` descriptor wording should be corrected to `.DSC`. | High | Current MCP `.DSC` byte/xref proof; target decompile. Callback proof: local cluster/resource pages now use `.DSC` and validators `000000002146`/`000000002148` passed. | Local cluster/resource support docs | incorporate | applied |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation: current MCP proves one exact function, one constructor caller, `.DSC` suffix xref, per-part descriptor loader behavior, part/vector offsets, descriptor and sequence allocation sizes, and source-like helper structure.
- Corroborating documentation/generated-report evidence: constructor already calls `LoadPartSpriteDescriptors();`; class/file routes are valid; destructor and composition helpers already use `NewHumanPartEntry`, `NewHumanPartFrameDescriptor`, and `NewHumanSequenceFrameTable`; pre-callback generated output lacked this body only because the target was no-owner/non-emitting. Callback validators now refresh generated output with the UID00041C body.
- Strongest inference chain: constructor -> out-of-line loader call -> class state offsets -> destructor/consumer cleanup and use of the same nested fields -> class/file route shared by promoted sibling helpers. This is sufficient for first-draft source method emission.

## IDA MCP Facts
- Function/range facts: `sub_4E13B0`, start `0x004e13b0`, size `0x446` decimal `1094`; target half-open range ends at `0x004e17f6`; successor modeled function starts at `0x004e1800`.
- Data/table/padding facts: UTF-16 `.DSC` byte sequence is at `0x0061c33c`; `entity_query strings` missed it, but `find_bytes` found exactly one match and `xref_query 0x0061c33c` found the target xref at `0x004e1435`.
- Xref facts: one code xref to target from `0x004e017c` inside `sub_4DFD10`.
- Vtable/global/type facts: no vtable-specific evidence is needed for this helper; class/global route is inherited from `NewHumanImageLib` class/source docs and constructor/destructor evidence.
- Negative IDA facts: `0x004e17f6` is not a function; `.DSC` string lookup through typed string query is unavailable; IDA has no source symbol for `LoadPartSpriteDescriptors`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e13b0-0x004e17f6` | [UID:00041C](../../../../../by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md) | Target per-part `.DSC` descriptor loader | True | Recommended `000092` | Current `84/86`, recommended `88/90` | Promote to emitting class method |
| `0x004dfd10-0x004e024a` | [UID:0002JR](../../../../../by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) | Sole caller, constructor load-order owner context | True | `000092` | `91/92` | Support doc update only |
| `0x004dfd10-0x004e4d79` | [UID:00017R](../../../../../by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md) | Non-emitting local cluster/index | False | None | `85/89` | Keep non-emitting; fix stale `.tbl` wording |
| `NewHumanImageLib` | [UID:000092](../../../../../by-class/NewHumanImageLib.md) | Direct class owner/emitter | True | File route `0000LR` | `86/88` | Add promoted method row |
| `NewHumanImageLib.cpp` | [UID:0000LR](../../../../../by-file/NewHumanImageLib.md) | Source file route | True | File | `87/85` | Add UID00041C as emitting child after callback |
| Layout | [UID:0001VF](../../../../../by-type/by-struct/NewHumanImageLibLayout.md) | Structure/type support | True support | `000092` | `85/88` | Add descriptor-loader field evidence |
| Resource inventory | [UID:0001RI](../../../../../by-resource/new-human-motion-tables.md) | Payload/resource inventory | Not source owner | None | `88/93` | Correct `.DSC` descriptor resource wording |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004e017c` | Code xref to `0x004e13b0` from `sub_4DFD10` | Constructor calls `LoadPartSpriteDescriptors()` after part/layer/motion setup and before later accessory loads. |
| `0x004e1435` | Data xref to `0x0061c33c` | Loader uses UTF-16 `.DSC` suffix when building per-part descriptor path. |
| `0x0061c33c` | UTF-16 bytes `2E 00 44 00 53 00 43 00` | Exact `.DSC` suffix; typed string query limitation is superseded by raw byte and xref proof. |
| `sub_49C180` / `sub_49C310` / `sub_49C240` | DAT open/read/close helpers | File I/O dependencies, not ownership candidates. |
| `sub_582560` / `sub_584540` family | StringBase/wide-string helpers | Path construction dependencies, not ownership candidates. |
| `unknown_libname_19` | Allocation helper | New-array lowering or allocator dependency, not ownership candidate. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: [UID:000092] lists UID00041C as a constructor-only `LoadPartSpriteDescriptors` helper pending promotion; [UID:0000LR] is the accepted NewHumanImageLib source root; [UID:0002JR] already calls `LoadPartSpriteDescriptors();`; [UID:00017S], [UID:000417], [UID:000437], and [UID:000438] already consume or clean the same descriptor/sequence fields with implementation-ready type names.
- Existing docs that are stale, incomplete, or contradicted: target and class/file docs still say UID00041C remains below-gate/no-owner; local cluster and resource docs use stale `.tbl` wording for per-part descriptors; some support docs use boolean-style names for count bytes.
- Generated/coverage report state: `auto-generated/-ag-memory-coverage.md` lists no-owner/no-emitter/no-code; `auto-generated/-ag-coverage-report-by-memory.md` reports `emits_code:false`; generated `NewHumanImageLib.cpp` has constructor call text but no UID00041C body. These states should change only after by-* callback and validator refresh.

## Ranked Ownership Analysis

### 1. [UID:000092] NewHumanImageLib
- Evidence for: sole constructor caller is a `NewHumanImageLib` constructor; target reads and writes `NewHumanImageLib` part/motion vectors; sibling helper targets have already promoted through the same class route; class page explicitly records this helper as a pending method.
- Evidence against: exact original method name and some field spellings are inferred, not symbol-proven.
- Decision: select as direct owner and emitter. Name uncertainty is a score cap, not an ownership blocker.

### 2. [UID:0002JR] NewHumanImageLibConstructor
- Evidence for: constructor is sole code caller and load order context.
- Evidence against: the binary uses an out-of-line function call at `0x004e017c`; constructor docs already call this helper rather than inline its body.
- Decision: reject as direct owner. Constructor should receive a support-state note only.

### 3. [UID:00017R] NewHumanImageLibLocalMethodCluster
- Evidence for: target is inside the local method cluster range.
- Evidence against: cluster is a non-emitting index/container and not a source-level owner. Promoted siblings moved to class ownership.
- Decision: reject as direct owner; keep as non-emitting index with corrected child row.

### 4. [UID:0001RI] New-human motion/resource tables
- Evidence for: target reads per-part resource payload files.
- Evidence against: resource page documents payload families, not the source method body. It cannot own the C++ implementation.
- Decision: reject as owner; update as support inventory only.

### 5. DATFile/StringBase/helper callees
- Evidence for: target calls file and string helper functions.
- Evidence against: these are generic dependencies and do not own the class-specific vector/descriptor semantics.
- Decision: reject.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file or grouping; use existing class [UID:000092] and file [UID:0000LR].
- Likely full contents: one `void NewHumanImageLib::LoadPartSpriteDescriptors()` method in `NexusTK/render/NewHumanImageLib.cpp`.
- Candidate related items that belong: target only; support docs should update references.
- Candidate related items rejected: sibling below-gate loaders [UID:00041B] and [UID:00041D] need their own passes; no broad cluster promotion.
- Standalone, narrow, or broad source-file inference: narrow class method under established source file.

## Source Placement
- Recommended source file/class/global/module placement: `NexusTK/render/NewHumanImageLib.cpp`, member of `NewHumanImageLib`.
- Why this placement fits source-tree and subsystem context: every observed state mutation is inside the `NewHumanImageLib` object; constructor/destructor and sibling table loaders already route here; generated source currently uses this file and constructor call.
- Rejected placements and why: constructor inline would duplicate an out-of-line function; local cluster is an index; resource docs are data inventory; helper callees are shared utility dependencies.
- Remaining placement uncertainty: none for owner/file route.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: `lookup_funcs 0x004e13b0` returns size `0x446`; the target's half-open end `0x004e17f6` is not a function; successor `sub_4E1800` starts at `0x004e1800`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none.
- Padding/table/data/code distinctions: target is executable code. The `.DSC` suffix at `0x0061c33c` is a data dependency, not child code. Compiler SEH/security-cookie cleanup and local destructor tails are source-lowering details.
- Parent/container impact: local cluster [UID:00017R] should stop describing UID00041C as support-only and should not emit code itself.

## Negative Evidence Summary
- Checked and rejected constructor ownership despite sole caller because the helper is a separate function with its own body and class state semantics.
- Checked and rejected resource ownership because the resource page covers data payload families, not the loader implementation.
- Checked and rejected local-cluster ownership because it is a non-emitting range/index.
- Checked and rejected stale UID collision reports by path/address mismatch.
- Checked generated output only as read-only evidence; absence of a body is not proof of non-reconstructability.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: `NewHumanImageLib::LoadPartSpriteDescriptors`, `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, `NewHumanSequenceFrame`, `primaryFrameCount`, `secondaryFrameCount`, `sequenceCount`, `sequenceFrames`, `recordIndex`, and `drawIndexBase`.
- Evidence for each proposed name/type/comment: target decompile proves load roles and offsets; destructor/composition helpers prove consumer/cleanup names; class/file docs prove source route.
- Items intentionally left unchanged and why: no IDA DB rename, type, or comment edit was requested by the accepted report or callback.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. Current MCP evidence resolves the old descriptor/nested-table blocker, owner/emitter route clears through UID000092/UID0000LR, and the function is source-authored/reconstructable.
- Recommended code: the fenced text below is the exact formal insertion text for the target page's `RECONSTRUCTION_CPP CODE` header, `BEGIN`, body, and `END` block after supervisor acceptance. It is fenced as text because the sentinel lines are documentation control markers, not C++ source lines.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewHumanImageLib::LoadPartSpriteDescriptors()
{
    for (NewHumanPartEntry *part = m_partEntries.begin();
         part != m_partEntries.end();
         ++part)
    {
        DATFile descriptorFile;
        WideString descriptorName = part->name;
        unsigned char header[23];
        int descriptorCount = 0;
        int totalRawRecordCount = 0;

        descriptorName += L".DSC";

        descriptorFile.Open(descriptorName.c_str());
        descriptorFile.Read(header, sizeof(header));
        descriptorFile.Read(&descriptorCount, sizeof(descriptorCount));

        if (descriptorCount > 0)
        {
            part->frameDescriptors =
                new NewHumanPartFrameDescriptor[descriptorCount];
            part->descriptorCount = descriptorCount;

            for (int descriptorIndex = 0;
                 descriptorIndex < descriptorCount;
                 ++descriptorIndex)
            {
                NewHumanPartFrameDescriptor &descriptor =
                    part->frameDescriptors[descriptorIndex];

                descriptor = NewHumanPartFrameDescriptor();

                descriptorFile.Read(&descriptor.descriptorId,
                                    sizeof(descriptor.descriptorId));
                descriptorFile.Read(&descriptor.frameBase,
                                    sizeof(descriptor.frameBase));
                descriptorFile.Read(&descriptor.drawIndexBase,
                                    sizeof(descriptor.drawIndexBase));
                descriptorFile.Read(&descriptor.rawRecordCount,
                                    sizeof(descriptor.rawRecordCount));
                totalRawRecordCount += descriptor.rawRecordCount;

                descriptorFile.Read(&descriptor.primaryFrameCount,
                                    sizeof(descriptor.primaryFrameCount));
                if (descriptor.primaryFrameCount > 0)
                {
                    descriptor.primaryFrameData =
                        new unsigned short[descriptor.primaryFrameCount];
                    descriptorFile.Read(
                        descriptor.primaryFrameData,
                        sizeof(descriptor.primaryFrameData[0]) *
                            descriptor.primaryFrameCount);
                }

                descriptorFile.Read(&descriptor.secondaryFrameCount,
                                    sizeof(descriptor.secondaryFrameCount));
                if (descriptor.secondaryFrameCount > 0)
                {
                    descriptor.secondaryFrameData =
                        new unsigned short[descriptor.secondaryFrameCount];
                    descriptorFile.Read(
                        descriptor.secondaryFrameData,
                        sizeof(descriptor.secondaryFrameData[0]) *
                            descriptor.secondaryFrameCount);
                }

                int populatedSequenceCount = 0;
                descriptorFile.Read(&populatedSequenceCount,
                                    sizeof(populatedSequenceCount));

                int motionCount =
                    static_cast<int>(m_motionEntries.end() -
                                     m_motionEntries.begin());
                descriptor.sequenceCount = motionCount;
                descriptor.sequenceFrames =
                    new NewHumanSequenceFrameTable[motionCount];

                for (int motionIndex = 0;
                     motionIndex < motionCount;
                     ++motionIndex)
                {
                    NewHumanSequenceFrameTable &sequenceFrames =
                        descriptor.sequenceFrames[motionIndex];

                    sequenceFrames.motionIndex = -1;
                    sequenceFrames.frameBase = -1;
                    sequenceFrames.frameCount = 0;
                    sequenceFrames.frames = NULL;
                }

                for (int sequenceIndex = 0;
                     sequenceIndex < populatedSequenceCount;
                     ++sequenceIndex)
                {
                    int motionIndex = 0;
                    descriptorFile.Read(&motionIndex, sizeof(motionIndex));

                    NewHumanSequenceFrameTable &sequenceFrames =
                        descriptor.sequenceFrames[motionIndex];
                    sequenceFrames.motionIndex = motionIndex;

                    descriptorFile.Read(&sequenceFrames.frameBase,
                                        sizeof(sequenceFrames.frameBase));
                    descriptorFile.Read(&sequenceFrames.frameCount,
                                        sizeof(sequenceFrames.frameCount));

                    sequenceFrames.frames =
                        new NewHumanSequenceFrame[sequenceFrames.frameCount];

                    for (int frameIndex = 0;
                         frameIndex < sequenceFrames.frameCount;
                         ++frameIndex)
                    {
                        NewHumanSequenceFrame &frame =
                            sequenceFrames.frames[frameIndex];

                        descriptorFile.Read(&frame.recordIndex,
                                            sizeof(frame.recordIndex));
                        descriptorFile.Read(&frame.flags,
                                            sizeof(frame.flags));
                        descriptorFile.Read(&frame.value,
                                            sizeof(frame.value));
                    }
                }
            }

            part->rawRecordCount = totalRawRecordCount;
            descriptorFile.Close();
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: it walks the part vector, builds `<part->name>.DSC`, reads the 23-byte header and 4-byte descriptor count, allocates 0x20-byte descriptor rows only for positive counts, reads the four fixed dwords, preserves count-driven primary/secondary 2-byte arrays, creates motion-count-sized 0x10 sequence slots initialized to `-1/-1/0/NULL`, loads populated motion-indexed slots, reads 9-byte frame rows, accumulates raw-record count, and calls DAT close in the same positive-count branch where the binary has the explicit close.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: it uses the same source-facing `DATFile`, `NewHumanImageLib`, vector `begin()/end()`, `new []`, `NULL`, and row-structure vocabulary already accepted by adjacent generated NewHumanImageLib pages.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `WideString`, `NewHumanPartEntry`, `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, `NewHumanSequenceFrame`, `descriptorId`, `frameBase`, `primaryFrameCount`, `secondaryFrameCount`, `motionIndex`, `flags`, and `value`.
- Naming/coding style convention used and evidence for consistency: follows [UID:000419] `DATFile` table-loader style, [UID:00017S] destructor vector-loop style, and [UID:000417]/[UID:000437]/[UID:000438] descriptor/sequence consumer vocabulary.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes recommended: promote target to owner/emitter [UID:000092], add first-draft C++, update evidence and behavior sections with current MCP facts, fix stale `.tbl` descriptor wording in support docs, refine descriptor count/pointer field discussion.
- Exact parent assignments recommended: `CANONICAL_OWNER:000092`; `EMITTER_UIDS:000092`; source file route remains [UID:0000LR] through class docs.
- Exact items left no-owner/non-emitting and why: local cluster [UID:00017R] remains non-emitting; resource page [UID:0001RI] remains not a source-code owner; sibling loaders [UID:00041B]/[UID:00041D] remain outside this target-specific report.
- Exact future work outside this assignment scope: implementation callback after supervisor acceptance; validator refresh of generated reports/source; possible later sibling passes for UID00041B/UID00041D.

## Recommended Target Doc Changes
- Target path: `source-3/project-documentation/by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md`.
- Exact report facts to incorporate: current MCP session state, function boundary, sole caller, `.DSC` suffix byte/xref proof, decompile behavior, descriptor field offset table, sequence slot mapping, rejected owner alternatives, and stale wording cleanup.
- Metadata/score/owner/emitter/reconstructable/C++ changes: `COMPLETION:88`; `CONFIDENCE:90`; `CANONICAL_OWNER:000092`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:000092`; formal C++ block as supplied above; update item summary to say class-owned first-draft `.DSC` descriptor loader.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: older B011 below-gate status was valid when created but superseded by current MCP and promoted support docs; `.tbl` descriptor wording is stale; `entity_query strings` failure is a tool limitation, not evidence against `.DSC`; exact original field spellings remain inferred.

## Recommended Support Doc Changes
- Support path: `source-3/project-documentation/by-class/NewHumanImageLib.md`.
- Exact report facts to incorporate: update UID00041C row/status from below-gate support-only to class-owned/emitting `88/90` method with first-draft C++; remove or supersede wording that UID00041C remains no-owner.
- Metadata/link/score/coverage/source-placement changes: class score can remain `86/88` unless supervisor chooses a small source-quality bump; method inventory should route UID00041C through class/file.

- Support path: `source-3/project-documentation/by-file/NewHumanImageLib.md`.
- Exact report facts to incorporate: UID00041C now emits through UID000092 to `NexusTK/render/NewHumanImageLib.cpp`; generated output should refresh to include the body. Remove UID00041C from the remaining below-gate helper list after callback.
- Metadata/link/score/coverage/source-placement changes: source-file score can remain `87/85` unless supervisor chooses to bump confidence after generated refresh.

- Support path: `source-3/project-documentation/by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`.
- Exact report facts to incorporate: constructor call to `LoadPartSpriteDescriptors();` now resolves to emitting UID00041C; old note saying UID00041C remains below-gate/no-owner should be superseded.
- Metadata/link/score/coverage/source-placement changes: no score change required.

- Support path: `source-3/project-documentation/by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`.
- Exact report facts to incorporate: update UID00041C row to `.DSC` descriptor files and class-owned/emitting status; keep cluster non-emitting.
- Metadata/link/score/coverage/source-placement changes: no ownership change to cluster.

- Support path: `source-3/project-documentation/by-type/by-struct/NewHumanImageLibLayout.md`.
- Exact report facts to incorporate: add UID00041C loader evidence for `NewHumanPartFrameDescriptor` packed 0x20-byte rows: fixed dwords at `+0x00/+0x04/+0x08/+0x0c`, count byte/pointer pairs at `+0x10/+0x11` and `+0x15/+0x16`, word motion-slot count at `+0x1a`, sequence slot array at `+0x1c`; add `NewHumanSequenceFrameTable` 0x10-byte slot layout and 9-byte frame row layout.
- Metadata/link/score/coverage/source-placement changes: no required metadata change; type-support score may remain because original field spellings are still inferred.

- Support path: `source-3/project-documentation/by-resource/new-human-motion-tables.md`.
- Exact report facts to incorporate: correct per-part descriptor resource wording from `<part-name>.tbl` to `<part-name>.DSC`; add target-specific descriptor payload outline.
- Metadata/link/score/coverage/source-placement changes: no owner/emitter change.

- Support paths: UID00017S destructor and UID000417/UID000437/UID000438 composition consumers.
- Exact report facts to incorporate: if touched in the callback, harmonize descriptor count field names. Prefer count-bearing `primaryFrameCount` / `secondaryFrameCount` aliases over boolean-only wording while preserving existing consumer semantics.
- Metadata/link/score/coverage/source-placement changes: no immediate score change required.

## Score And Metadata Recommendation
- Current score/metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Recommended score/metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, formal C++ present.
- Score rationale and reason not higher/lower: `88/90` is above code gate and appropriate because current MCP resolves the old owner/emitter/C++ blockers, but exact original field names and string-wrapper spelling remain inferred. It should not stay at `84/86` because direct owner, route, sequence slot layout, and C++ body are now evidence-backed. It should not exceed low 90s because no original symbols, debug info, or source header definitions prove the exact nested type spellings.
- Score-improvement attempt: old descriptor row/nested mapping blocker was rechecked through current decompile, destructor cleanup, composition consumers, and layout docs; resolved. `.DSC` suffix ambiguity was rechecked through byte search and data xref; resolved. Owner route was rechecked through constructor/class/file/sibling helpers; resolved. Generated no-body state was rechecked; resolved as metadata consequence. Remaining naming uncertainty is evidence-backed and score-capping only.
- Metadata fields to change or leave unchanged: change completion, confidence, owner, emitter, item summary, and C++ block; keep UID, range, `RECONSTRUCTABLE:TRUE`, and `Nested:0`.

## Open Questions With Attempted Resolution
- Open question: exact original names for descriptor dwords `+0x00` and `+0x04`. Evidence checked: decompile of loader and consumers UID000417/437/438. Best resolution: preserve neutral inferred field names and note semantics are not fully decoded. Impact: confidence cap only.
- Open question: exact original wide-string wrapper name used for path construction. Evidence checked: StringBase helper callees and project docs that use `WideString` as an inferred wrapper. Best resolution: use `WideString` in first-draft C++ and mark it inferred. Impact: confidence cap only.
- Open question: why explicit `DATFile::Close` is inside positive-count branch. Evidence checked: decompile shows explicit close only under `descriptorCount > 0`, with DATFile cleanup after the branch. Best resolution: formal code keeps explicit close in the positive-count branch; DATFile destructor handles cleanup otherwise. Impact: no blocker.
- Remaining unresolved questions: no ownership, emitter, split, or C++ eligibility question remains unresolved. Only exact original spelling questions remain.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. The affected tracker and coverage rows are validator-owned `auto-generated/-ag-*` outputs. B-agent should not write replacement rows. Updating the source by-* docs and running validator refresh after supervisor acceptance should regenerate coverage/source state.

## Follow-Up Actions
- Supervisor actions: verify this callback-complete report against the changed docs and validator proof, then execute the report through the supervisor-owned validator lifecycle if accepted.
- A-agent actions: none identified for UID00041C.
- B008 future implementation actions: none for the accepted UID00041C scope. Optional descriptor-field harmonization in destructor/composition consumer pages was excluded as not needed because the target/layout/support docs now carry the accepted count-bearing descriptor facts and the existing consumer/cleanup pages already corroborate the fields.

## Callback Coordination Note
- During any implementation callback, re-read the current target and support docs immediately before editing because B007, B009, B010, and B011 may be touching shared `NewHumanImageLib` support pages. Respect active leases, take only the short leases needed for the immediate edit/validator batch, and do not overwrite newer accepted support edits; if a current support page already contains a report fact at same-or-greater detail, mark that checklist/ledger item as already present instead of replacing it.
- Callback recheck result: `tools/leaser/Agents/current_leases.md` currently reports no active leases. The target/support docs were re-read after the callback edits, and no accepted UID00041C by-* edit is missing.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: exact original field and type spellings; no remaining route/range/code blocker.

## Callback Implementation Result
- Target implemented: `by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md` now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, blank optional emitter position, and the exact formal `RECONSTRUCTION_CPP CODE` block from this report.
- Support docs incorporated or already carried the accepted facts at same-or-greater detail: `by-class/NewHumanImageLib.md`, `by-file/NewHumanImageLib.md`, `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`, `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`, `by-type/by-struct/NewHumanImageLibLayout.md`, and `by-resource/new-human-motion-tables.md`.
- Re-read verification: current target/support docs preserve MCP provenance, exact range, sole constructor caller, `.DSC` suffix byte/xref proof, descriptor-count and allocation behavior, packed descriptor offsets, sequence table shape, stale `.tbl` correction, score rationale, unresolved name caveats, and rejected alternatives.
- Generated output verification: `auto-generated/NexusTK/render/NewHumanImageLib.cpp` is validator-owned and currently contains UID00041C at `Completion:88 | Confidence:90` with `void NewHumanImageLib::LoadPartSpriteDescriptors()`. Final observed generated header is `validator-command-id: 000000002158`, `validator-refreshed-at: 2026-06-30T03:43:19-04:00`, `validator-refresh-source: foreground-generated-refresh`, newer than the target/class/file validator commands that mattered for UID00041C emission.
- Manual edit exclusions: no generated files, no `-coverage-report.md` files, no project-level generated reports, no validator/tool state, no IDA DB, no executed archives, no supervisor ledgers, and no lock files were manually edited.

## Lease Result
- Target lease: B008 took a short lease for `by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md` for the target edit/validator batch and released it after the target validator.
- Support lease batch: B008 took a short support-doc lease batch for `by-class/NewHumanImageLib.md`, `by-file/NewHumanImageLib.md`, `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`, `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`, `by-type/by-struct/NewHumanImageLibLayout.md`, and `by-resource/new-human-motion-tables.md`, created `2026-06-30T07:35:48Z`, expiring `2026-06-30T07:40:48Z`.
- Release state: the support validator batch exceeded that lease window. A later `B008 unlease` attempt returned `Rejected[Lease owned by B009]` because B009 had acquired the same shared support docs after B008's lease expired. Current recheck shows no active leases, and no shared support-doc edits were made after B009 held them.

## Validator Results
- Target validator: `python .\tools\validator.py --mode file --file by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md --apply --queue-timeout 240 --wait-generated`; command id `000000002110`, timestamp `2026-06-30T03:04:01-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- Class validator: `python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated`; command id `000000002143`, timestamp `2026-06-30T03:38:35-04:00`, exit `0`, `ok: 1`.
- File validator: `python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated`; final wait-generated pass command id `000000002152`, timestamp `2026-06-30T03:42:05-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- Constructor validator: `python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md --apply --queue-timeout 240 --wait-generated`; command id `000000002145`, timestamp `2026-06-30T03:38:55-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- Local-cluster validator: `python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 240`; command id `000000002146`, timestamp `2026-06-30T03:39:06-04:00`, exit `0`, `ok: 1`. Existing unrelated warning: missing reference UID `0003UD` reported twice.
- Layout validator: `python .\tools\validator.py --mode file --file by-type/by-struct/NewHumanImageLibLayout.md --apply --queue-timeout 240`; command id `000000002147`, timestamp `2026-06-30T03:39:08-04:00`, exit `0`, `ok: 1`.
- Resource validator: `python .\tools\validator.py --mode file --file by-resource/new-human-motion-tables.md --apply --queue-timeout 240`; command id `000000002148`, timestamp `2026-06-30T03:39:09-04:00`, exit `0`, `ok: 1`.

## Changed Files
- Modified by-* docs: `by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md`, `by-class/NewHumanImageLib.md`, `by-file/NewHumanImageLib.md`, `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`, `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`, `by-type/by-struct/NewHumanImageLibLayout.md`, and `by-resource/new-human-motion-tables.md`.
- Modified report: `tools/leaser/Agents/Agent-B008/research/00041C-NewHumanImageLibLoadPartSpriteDescriptors-source-quality.md`.
- Validator-owned side effects: validator refreshes updated generated C++/metadata, projected stats, research tracker, registry/state, and generated reports through the documented tool flow. These were not manual edits.
- Created/renamed/split files: none. No new child files and no range split or rename were needed.

## Implementation Tracking Checklist

Completed report-only evidence and planning:
- [x] Supervisor validation required before implementation.
- [x] Current target state and actual evidence checked recorded.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or exact evidence-backed score cap.
- [x] Source-placement, range/split/padding/reclassification, and IDA rename/type/comment disposition researched and recorded.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale where applicable.
- [x] Open questions closed or documented as evidence-backed unresolved with score/C++ impact.

Accepted callback implementation items:
- [x] Re-read current target/support docs and active leases before editing because B007/B009/B010/B011 may have newer accepted `NewHumanImageLib` support edits. Proof: current callback recheck read target/support docs and `tools/leaser/Agents/current_leases.md`; no active leases currently remain.
- [x] Target/support docs updated: target page, NewHumanImageLib class/file, constructor support note, local cluster, layout/type support, and resource inventory. Proof: each changed by-* file is listed in `Changed Files` and passed its scoped validator.
- [x] Metadata/score changes applied: `84/86` to `88/90`, owner/emitter `000092`, reconstructable true. Proof: target header now records `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`.
- [x] Owner/emitter/reconstructable changes applied: owner/emitter `000092`, reconstructable unchanged true. Proof: target metadata, class row, file route, and generated source all point to UID000092/UID0000LR.
- [x] Split/rename/new-child changes applied: none. Proof: target exact range stayed `0x004e13b0-0x004e17f6`; no new child files were created.
- [x] First-draft C++ insertion applied: exact formal `RECONSTRUCTION_CPP CODE` header/BEGIN/body/END text from this report is now in the target. Proof: generated `NewHumanImageLib.cpp` contains the UID00041C body.
- [x] Third-party import directive confirmed not applicable. Proof: target is native project code, not a staged third-party source import.
- [x] Exact target/support doc facts incorporated at report-level detail. Proof: target/support docs now preserve range, caller, `.DSC`, descriptor allocation, packed offsets, sequence rows, score rationale, caveats, and rejected alternatives.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target and support docs reject old no-owner/blank-C++ state, stale `.tbl` descriptor wording, constructor/cluster/resource owner alternatives, and UID-collision TimerMgr reports.
- [x] Claim And Incorporation Ledger verification states updated from `proposed` to callback states for every accepted claim. Proof: all C1-C12 rows now end in `applied`.
- [x] Validators run after by-* implementation: scoped project validators for changed by-* pages and generated NewHumanImageLib output refresh through validator-owned flow. Proof: command ids `000000002110`, `000000002143`, `000000002145`, `000000002146`, `000000002147`, `000000002148`, and final by-file wait-generated `000000002152`.
- [x] Generated report refresh completed by validator-owned flow; no manual coverage/tracker text applied. Proof: generated `NewHumanImageLib.cpp` header is `000000002158` / `2026-06-30T03:43:19-04:00`, and no manual generated/coverage edits were made.
- [x] Optional descriptor-field harmonization in destructor/composition consumer docs excluded with reason. Proof: existing cleanup/consumer docs already supported the descriptor fields; target/layout docs now carry count-bearing details, so no extra accepted blocker required those optional edits.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail or marked already present/excluded with reason.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator-owned flow.
- [x] Remaining unapplied accepted items listed with exact disposition: no blocked UID00041C items remain; optional destructor/composition harmonization is excluded as not needed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/00041C-NewHumanImageLibLoadPartSpriteDescriptors-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/00041C-NewHumanImageLibLoadPartSpriteDescriptors-source-quality.md","timestamp":"2026-06-30T03:52:26","uid":"00041C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
