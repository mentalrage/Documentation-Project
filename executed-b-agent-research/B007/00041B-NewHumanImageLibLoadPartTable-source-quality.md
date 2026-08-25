** TARGET-REPORT-UID:00041B **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# Agent-B007 Report: [UID:00041B] NewHumanImageLibLoadPartTable Source Quality

Report timestamp: `2026-06-30T02:47:42-04:00`

Assignment: `B007-report-00041B-NewHumanImageLibLoadPartTable-direct-research-20260630`

Mode: report-first research only. No target/support by-* docs, generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files were edited.

Target: [UID:00041B] `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B007\research\00041B-NewHumanImageLibLoadPartTable-source-quality.md`

## Finalized Report / Current Recommendation

- Current recommendation: promote [UID:00041B] from below-gate no-owner support to a direct [UID:000092] `NewHumanImageLib` class-owned emitting retained table-loader helper.
- Final disposition: reconstructable source-authored `NewHumanImageLib::LoadPartTable` method body in the `NewHumanImageLib` table-loader family, emitted through [UID:000092] to the valid [UID:0000LR] `NexusTK/render/NewHumanImageLib.cpp` file root.
- Required action after supervisor acceptance: update the target metadata from `84/86`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and blank C++ to `88/90`, `CANONICAL_OWNER:000092`, `EMITTER_UIDS:000092`, and the formal first-draft C++ block supplied below.
- Confidence: strong for function boundary, behavior, class/file source route, callee relation, zero-xref caveat, and first-draft C++ shape. Confidence remains below final-audit range because exact original field names for the two 32-bit `Part.tbl` range/index fields are still inferred from accepted constructor/layout terminology and consumer evidence.

## Target

- Target UID: `00041B`.
- Target path: `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> by-memory not-covered reconstructable queue row shows `84/86`, combined `85.0`, `reconstructable:true`, direct reports `0`, path `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md`.
- Current supervisor classification: report-first direct target-specific research for UID00041B, not a broad NewHumanImageLib family report.
- Current scores and parent state: target is `84/86`, no owner, no emitter, blank formal C++. Parent class [UID:000092] is `86/88` and emits through file [UID:0000LR] `87/85`. Sibling [UID:000419] `LoadMotionTable` and [UID:00041A] `LoadLayerTable` have now been promoted to emitting class-owned loaders after current MCP-backed passes.

## Current Target State

- Existing metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++ block, `Nested:0`.
- Existing owner/emitter state: current page records candidate class route [UID:000092] only as evidence and says the helper is intentionally below gate.
- Existing C++/emitter state: no formal code, so generated `auto-generated/NexusTK/render/NewHumanImageLib.cpp` has no UID00041B block.
- Existing blockers rechecked: caller absence, function boundary, source placement, row shape, file-row versus memory-row wording, `ResolveSpritePartPath` and `VectorGrowPart` dependency roles, source signature, and first-draft code readiness.
- Existing stale/incomplete statements: the page says the loader "reads 68-byte part rows." Current MCP plus resource sampling refines this: the function zeroes/appends a `0x44` / 68-byte in-memory `NewHumanPartEntry` (Verified with int_convert.py), but each `Part.tbl` file row is `0x20` / 32 bytes (Verified with int_convert.py): 4-byte id, 20-byte ANSI name, and two 4-byte scalar fields.
- Related target/support docs checked: [UID:000092] class, [UID:0000LR] file, [UID:0002JR] constructor, [UID:0001VF] layout, [UID:0001RI] resource page, [UID:0000VA] `ResolveSpritePartPath`, [UID:00041G] `VectorGrowPart`, [UID:00017R] local cluster, [UID:00041A] layer loader, [UID:000419] motion loader, generated tracker/coverage/code rows, matching executed reports, and stale TimerMgr UID-collision docs.

## Supervisor Active Recheck

- The active user/supervisor instruction assigned [UID:00041B] for report-first research and explicitly forbids by-* implementation during this pass.
- No split repair is needed. MCP `lookup_funcs` reports `sub_4E11B0`, size `0x1f7` / 503 bytes (Verified with int_convert.py), and the next modeled function starts at `0x004e13b0`.
- Every source-bearing item in direct scope has a disposition: UID00041B should be promoted and emitted; [UID:00041G] `VectorGrowPart` remains a support dependency and should not be promoted by this report; TimerMgr UID-collision material is rejected as unrelated stale path/address evidence.

## Inference Research Guidance Check

- `by-structure.md` requires `CANONICAL_OWNER` to be the narrowest true semantic owner and `EMITTER_UIDS` to route generated output through a valid file root. UID00041B is a `thiscall` receiver method that mutates `m_partEntries` at object offsets `+0x04/+0x08/+0x0c`, so [UID:000092] is the direct owner and emitter route; [UID:0000LR] remains the file/source root.
- Existing B011 wording was treated as a time-bound child-page creation state, not a permanent no-code proof. Its blocker was "below-gate/no-owner while row/helper support is not source-ready." Since then, constructor, destructor, layout, motion-loader, layer-loader, and composition-helper support have accepted the relevant `NewHumanImageLib`, `DATFile`, `m_partEntries`, `NewHumanPartEntry`, and `ResolveSpritePartPath` vocabulary.
- IDA fact: function range, body, callsites, caller absence, callees, and boundary bytes. Documentation evidence: accepted class/file/layout/constructor/destructor/resource support. Inference: final source-facing spellings for `LoadPartTable`, `NewHumanPartEntry`, `drawIndexBase`, and `descriptorBase`.
- Wave2/Wave3/source-2 artifacts were not used as authority. Old generated names such as `MotionTableLocalHelperB` are rejected by current MCP behavior evidence.

## Heuristic / Inference Reanalysis And Validation

- Generated-name issue: IDA still names the raw function `sub_4E11B0`. The best source-facing name remains `NewHumanImageLib::LoadPartTable`, because the body opens a passed table path, reads `Part.tbl`-shaped rows, converts part names, resolves part EPF metadata, and appends to the class part vector.
- Type/row issue: current docs accepted `NewHumanPartEntry` as a 68-byte in-memory row with `partId`, wide `name`, two 32-bit scalar fields, nested descriptor fields later populated by `LoadPartSpriteDescriptors`, and `spriteArchive` at offset `+0x40`. This pass corrects the file payload wording to 32-byte rows while preserving the 68-byte memory-row/vector stride.
- Caller/reachability issue: `xrefs_to 0x004e11b0` returns zero xrefs. This rejects constructor-call and inlining claims but does not make the body non-source. [UID:00041A] `LoadLayerTable` has the same zero-xref retained-helper pattern and was accepted as class-owned/emitting after current MCP proof.
- Source-placement issue: receiver object, `m_partEntries` destination, NewHuman table-family context, `ResolveSpritePartPath` callee ownership, and sibling loader pattern all support [UID:000092]. Resource page, local cluster, vector helper, DAT helper, and TimerMgr are rejected as owners.
- C++ readiness issue: first-draft source can mirror the accepted constructor `Part.tbl` block while using the helper path argument. The code should use source-level `m_partEntries.push_back(part)`, not paste `VectorGrowPart` or raw direct-copy/XMM paths.
- Remaining unresolved issue: the two 4-byte file fields at row offsets `+0x18` and `+0x1c` have accepted current names `drawIndexBase` and `descriptorBase` from constructor/layout support, but the sampled payload values look like part id/range or descriptor index bounds. This is a below-95 score cap and a layout follow-up, not a blocker to first-draft loader source because the loader simply copies those fields into the accepted row members.

## Evidence Standards Used

- Evidence types used: IDA MCP `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `callees`, `xrefs_to`, `xref_query`, `disasm`, `decompile`, `get_bytes`, `entity_query`; `tools/int_convert.py`; current by-* docs; generated tracker/coverage/code rows; direct read-only `char.dat` payload sampling; matching executed reports.
- Evidence strength: strong for ownership and body shape because live IDA evidence, accepted support docs, sibling-loader precedent, and resource payload facts converge.
- Confidence cap: exact original field spellings and precise semantics of the two file scalar fields remain inferred.

## Evidence Checked

### IDA MCP / Manual / Raw Checks

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- MCP schema-current flow used: `initialize` -> `tools/list` -> exact `tools/call` requests with active `database`.
- `idb_list`: active database `supervisor_resume_20260629`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, backend `worker`, adopted/owned true, PID/worker PID `17592`, `is_analyzing:false`.
- `server_health`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- `lookup_funcs`: `0x004e11b0` -> `sub_4E11B0`, size `0x1f7`; `0x004e13a7` is not a function; `0x004e13b0` -> `sub_4E13B0`, size `0x446`; `0x004e5420` -> `sub_4E5420`, size `0x1d6`; `0x004e19d0` -> `sub_4E19D0`, size `0x557`; constructor `0x004dfd10` -> `sub_4DFD10`, size `0x53a`.
- `analyze_function 0x004e11b0`: modeled prototype `int __thiscall(_DWORD *this, wchar_t *ArgList)`, size `503`, 13 basic blocks, cyclomatic complexity 3, callers `[]`, callees include DAT/file helpers, `_memset`, `MultiByteToWideChar`, `sub_4E19D0`, `sub_4E5420`, and security-cookie cleanup.
- `disasm 0x004e11b0`: 140 instructions; `retn 4` at `0x004e13a4`; SEH/security-cookie scaffolding is present and should not be hand-emitted.
- `get_bytes 0x004e13a0 size 32`: tail bytes include `8b e5 5d c2 04 00`, then nine `0xcc` bytes from `0x004e13a7-0x004e13b0`, then successor prologue `55 8b ec...` for `sub_4E13B0`.
- `entity_query` bounded to `0x004e1040-0x004e13c0`: only `sub_4E1040`, `sub_4E11B0`, and `sub_4E13B0`, supporting the local function inventory.
- Direct read-only resource sampling: `E:\NTK\Resources\NexusTK\Data\char.dat` at documented `Part.tbl` offset `7,529,802`, size `635`, confirmed header `PartInformation`, count `19`, and 32-byte file rows. First sampled rows: `Body` fields `0,19999`; `Coat` fields `20000,39999`; `Face` fields `200,999`; `Emotion` fields `1,1`; `FaceDec` fields `0,9999`.

### by-* Docs, Reports, And Generated State

- Target page [UID:00041B], by-memory guidance, [UID:000092] class, [UID:0000LR] file, [UID:0002JR] constructor, [UID:0001VF] layout, [UID:0001RI] resource, [UID:0000VA] helper, [UID:00041G] vector helper, [UID:00017R] local cluster, [UID:00041A] and [UID:000419] sibling loader pages.
- Executed reports searched/opened: B011 constructor report, B006 `LoadLayerTable` report, B002 `LoadMotionTable` report, B014 composition-bounds report. TimerMgr reports mentioning UID00041B were found and rejected as stale UID/path collisions.
- Required search terms used: `00041B`, `0x004e11b0`, `0x004e13a7`, `NewHumanImageLibLoadPartTable`, `LoadPartTable`, `Part.tbl`, `VectorGrowPart`, `NewHumanImageLib`, `LoadLayerTable`, `LoadMotionTable`, `LoadPartSpriteDescriptors`.
- Generated tracker row: UID00041B remains `84/86`, combined `85.0`, reconstructable true, direct reports `0`.
- Generated memory coverage row: UID00041B has `emits_code:false`, reconstructable, `84%`, strong, updated `2026-06-25 06:04:15`.
- Generated C++: `auto-generated/NexusTK/render/NewHumanImageLib.cpp` header `validator-command-id: 000000002089`, refreshed `2026-06-30T01:39:05-04:00`; contains UID000419 `LoadMotionTable` and UID00041A `LoadLayerTable`, but no UID00041B `LoadPartTable` block.

### Negative Checks

- `xrefs_to 0x004e11b0`: zero direct xrefs.
- `xrefs_to 0x004e1040`: zero direct xrefs, showing UID00041B shares the retained-helper reachability pattern with UID00041A rather than being a constructor callee.
- `xrefs_to 0x004e19d0`: exactly two callsites, constructor `0x004e00f0` and target `0x004e12fe`.
- `xrefs_to 0x004e5420`: exactly two callsites, constructor `0x004e0148` and target `0x004e1356`.
- `xrefs_to 0x004e13b0` and `0x004e1800`: constructor calls only, proving the constructor calls descriptor/accessory loaders out of line but not UID00041B.
- Stale TimerMgr UID00041B material points to `0x00597780-0x005977ac.TimerMgrStaticDestructorBody.md` and TimerMgr support pages, not the assigned path/address/name. It is rejected as evidence for this report and is outside this B007 report-only implementation plan unless the supervisor explicitly expands scope to UID collision repair.
- No MCP failures occurred. No fallback-only evidence path was used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00041B is `sub_4E11B0`, size `0x1f7` / 503 bytes, exact body `0x004e11b0-0x004e13a7` with padding to `0x004e13b0`. | Strong | MCP `lookup_funcs`, `disasm`, `get_bytes`, bounded `entity_query`; int_convert. | Target Status/Boundary/Evidence; local cluster support | incorporate | applied |
| C02 | Direct canonical owner should be [UID:000092] `NewHumanImageLib`; source route remains [UID:0000LR]. | Strong | `thiscall` receiver, object `+0x04` part vector writes, class/file/layout docs, sibling loader precedent. | Target metadata/source placement; class/file/local cluster | incorporate | applied |
| C03 | Target should emit through `EMITTER_UIDS:000092`. | Strong | Parent class/file route clears gate; target is reconstructable and first-draft C++ ready; sibling loaders emit same way. | Target metadata | incorporate | applied |
| C04 | The helper has zero direct callers; constructor does not call `0x004e11b0` and keeps its inline `Part.tbl` loop. | Strong | MCP `xrefs_to 0x004e11b0` returns zero; constructor docs; B011 evidence. | Target rejected alternatives; constructor/class/file support | incorporate | applied |
| C05 | File-row wording must be corrected: `Part.tbl` file rows are 32 bytes, while the in-memory/vector row is 68 bytes. | Strong | MCP read sequence; `char.dat` sample; resource doc size/count; int_convert for `0x20` and `0x44`. | Target behavior/resource evidence; layout/resource/constructor support | incorporate | applied |
| C06 | The body reads a 23-byte header and 4-byte row count, then per row reads 4-byte id, 20-byte ANSI name, two 4-byte scalar fields, converts the name to wide text, resolves EPF metadata, and appends to `m_partEntries`. | Strong | MCP `decompile`, `disasm`; resource sample; support docs. | Target behavior/raw evidence; formal C++ | incorporate | applied |
| C07 | `ResolveSpritePartPath` and `VectorGrowPart` are dependencies, not owner routes. | Strong | MCP xrefs show only constructor and target call each; by-item/by-memory helper docs; class/file ownership. | Target source placement; support docs | incorporate | applied |
| C08 | Formal source signature should be `void NewHumanImageLib::LoadPartTable(const wchar_t *tableName)`. | Strong | IDA `thiscall` with one `wchar_t *` stack arg; decompiler `int` return is DAT cleanup artifact; no caller consumes return. | Target signature/C++ section | incorporate | applied |
| C09 | Exact formal first-draft C++ should mirror the accepted constructor `Part.tbl` block, with path argument and `m_partEntries.push_back(part)`. | Strong | MCP body, accepted constructor C++, accepted layout names. | Target formal `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C10 | Score should move to `88/90`; not higher because field spellings and two scalar-field semantics remain inferred. | Strong | Current MCP proof and unresolved field caveat. | Target metadata/score rationale | incorporate | applied |
| C11 | [UID:00041G] `VectorGrowPart` should remain below-gate/no-owner/non-emitting in this callback. | Strong | It is a vector-capacity callee, not this target body; current page is `84/86`; no centralized vector-template C++ pass here. | VectorGrowPart support note; target rejected alternatives | incorporate | applied |
| C12 | Stale TimerMgr UID00041B docs/reports must not be incorporated as target evidence. | Strong | Path/address/name mismatch: `0x00597780` TimerMgr destructor versus `0x004e11b0` NewHuman helper. | Target rejected alternatives/report notes | incorporate | applied |

Callback incorporation proof (2026-06-30):
- C01-C03 applied in the target evidence/boundary sections and mirrored into the constructor/local-cluster support notes where the no-xref/no-constructor-call caveat controls the score cap.
- C04-C06 applied in the target behavior and formal `RECONSTRUCTION_CPP CODE` block, with the zero-xref/no-constructor-call caveat, 23-byte header/count, 32-byte DAT row, 68-byte in-memory entry, resource sample, and DAT cleanup artifact rationale retained.
- C07-C09 applied through UID `000092` ownership/emitter metadata, synchronized class/file/local-cluster status notes, and the generated `NexusTK/render/NewHumanImageLib.cpp` route.
- C10 applied in target metadata and score rationale: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, and blank optional position.
- C11 applied to `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md`; it remains a non-emitting vector-capacity helper while UID `00041B` owns the source-level loader.
- C12 applied in the target rejected-alternatives section. TimerMgr UID-collision docs were explicitly excluded from this callback per supervisor scope.

## Positive Evidence Summary

- Direct facts supporting promotion: live IDA confirms the target is a `thiscall` body with a NewHuman receiver, path argument, part-vector writes, `ResolveSpritePartPath` call, `VectorGrowPart` capacity path, and no competing callers/owners.
- Corroborating documentation evidence: [UID:000092], [UID:0000LR], [UID:0001VF], [UID:0002JR], [UID:00017S], [UID:0001RI], [UID:000419], and [UID:00041A] already establish the NewHuman table-loader family, accepted member names, and class/file emission route.
- Strongest inference chain: `sub_4E11B0` has the same retained path-argument table-loader source shape as promoted [UID:00041A]; it writes the `m_partEntries` vector and calls the NewHuman-specific sprite resolver; therefore [UID:000092] is the direct owner and the helper is eligible for formal first-draft C++ once the current evidence is written.

## IDA MCP Facts

- Function/range facts:
  - `lookup_funcs 0x004e11b0` -> `sub_4E11B0`, size `0x1f7` / 503 bytes (Verified with int_convert.py).
  - `analyze_function 0x004e11b0` -> modeled `int __thiscall(_DWORD *this, wchar_t *ArgList)`, 13 basic blocks, cyclomatic complexity 3, callers `[]`.
  - `disasm` returns 140 instructions; `retn 4` at `0x004e13a4`.
  - `get_bytes` shows padding begins at `0x004e13a7` and next prologue starts at `0x004e13b0`.
- Data/table/padding facts:
  - Header read uses `0x17` / 23 bytes (Verified with int_convert.py) at `0x004e1215`.
  - Row memory temp zeroing uses `0x44` / 68 bytes (Verified with int_convert.py) at `0x004e1239`.
  - File row reads are `4`, `0x14` / 20, `4`, and `4` bytes at `0x004e126f`, `0x004e1283`, `0x004e1297`, and `0x004e12ab`.
  - `MultiByteToWideChar` receives `0xff` / 255 wide-char cap (Verified with int_convert.py) at `0x004e12e1`.
- Xref facts:
  - No xrefs to target entry `0x004e11b0`.
  - `ResolveSpritePartPath` at `0x004e19d0` has two code xrefs: constructor `0x004e00f0` and target `0x004e12fe`.
  - `VectorGrowPart` at `0x004e5420` has two code xrefs: constructor `0x004e0148` and target `0x004e1356`.
  - `LoadPartSpriteDescriptors` at `0x004e13b0` and `LoadAcc2DrwTable` at `0x004e1800` each have constructor xrefs, proving those helpers are called out of line while UID00041B is retained/no-xref.
- Negative IDA facts:
  - No function starts inside `0x004e11b0-0x004e13a7`.
  - No direct call from constructor to target.
  - No string literal refs in target; it opens the supplied path argument rather than hard-coding `Part.tbl`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e11b0-0x004e13a7` | [UID:00041B] target | Retained `NewHumanImageLib::LoadPartTable` helper | TRUE | Recommend [UID:000092] | Recommend `88/90` | Promote and emit |
| `0x004dfd10-0x004e024a` | [UID:0002JR] constructor | Inlines shipped `Part.tbl` loop and calls related helpers | TRUE | [UID:000092] | `91/92` | Already emits; do not change formal C++ |
| `0x004e19d0-0x004e1f27` | [UID:0002VD]/[UID:0000VA] | NewHuman sprite part EPF resolver | TRUE | [UID:0000LR] | Item `86/90` | Dependency; not owner |
| `0x004e5420-0x004e55f6` | [UID:00041G] `VectorGrowPart` | 68-byte part vector grow/insert helper | TRUE | NONE | `84/86` | Keep support/no C++ |
| `new-human-motion-tables` | [UID:0001RI] resource page | Table/resource provenance | TRUE | NONE | `88/93` | Sync file-row wording |
| `NewHumanImageLibLayout` | [UID:0001VF] layout page | Object fields and row names | TRUE | [UID:000092] | `85/88` | Sync Part.tbl loader evidence |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004e11b0` | xrefs to target entry: none | Retained helper, no shipped direct caller. |
| `0x004e12fe` | call to `sub_4E19D0` | Target resolves each converted part name to sprite archive metadata. |
| `0x004e1356` | call to `sub_4E5420` | Target uses `VectorGrowPart` only when `m_partEntries` is full. |
| `0x004e0148` | constructor call to `sub_4E5420` | Constructor and target share the same part-vector capacity helper. |
| `0x004e00f0` | constructor call to `sub_4E19D0` | Constructor and target share the same part EPF resolver. |
| `0x004e017c` | constructor call to `sub_4E13B0` | Constructor calls descriptor loader out of line after inline Part.tbl load. |
| `0x004e0188` | constructor call to `sub_4E1800` | Constructor calls accessory-table loader out of line. |

## Documentation Evidence And IDA Status

- Existing docs supporting conclusion: class/file pages place `Part.tbl`, `ResolveSpritePartPath`, `m_partEntries`, and sibling loaders in `NewHumanImageLib`; layout accepts `NewHumanPartEntry`; constructor formal C++ already contains the same source-shaped Part.tbl loop; resource page owns `Part.tbl` as resource-derived payload under the NewHuman module; [UID:00041A] is a direct precedent for a zero-xref retained loader emitting through [UID:000092].
- Existing docs stale/incomplete: target and support pages still describe UID00041B as below-gate/no-owner/non-emitting; target says "reads 68-byte part rows" instead of distinguishing 32-byte file rows from 68-byte in-memory rows; B011 blanket below-gate helper-family wording is now stale for UID000419, UID00041A, and should become stale for UID00041B if accepted.
- Generated/coverage state: generated reports currently show `emits_code:false`; generated C++ contains UID000419 and UID00041A blocks but not UID00041B.

## Ranked Ownership Analysis

### 1. [UID:000092] NewHumanImageLib

- Evidence for: target is `thiscall`, receives `this` in `ECX`, opens a wide path argument, writes `this[2]`/`this[3]` which are `m_partEntries` end/capacity at object offsets `+0x08/+0x0c`, calls NewHuman-specific `ResolveSpritePartPath`, and belongs to the adjacent NewHuman loader/helper family.
- Evidence against: zero direct callers and inferred names. Zero xrefs are a reachability caveat, not ownership counter-proof; exact spellings affect confidence only.
- Decision: accept as direct canonical owner and emitter route.

### 2. [UID:0000LR] NewHumanImageLib file

- Evidence for: file page owns `NexusTK/render/NewHumanImageLib.cpp`, resource family, resolver helper, and source module route.
- Evidence against: target is a class receiver method, so file-only ownership is less precise.
- Decision: use as source file route through the class, not direct canonical owner.

### 3. [UID:00017R] NewHumanImageLib local method cluster

- Evidence for: target is contained in the local method cluster.
- Evidence against: cluster is an aggregate/index and explicitly non-emitting; it is not a source-level owner.
- Decision: reject as direct owner.

### 4. Resource/DAT helper/vector helper owners

- Evidence for: target reads DAT table bytes, uses generic DAT helpers, and calls `VectorGrowPart`.
- Evidence against: resource bytes are payload; DAT helpers are generic dependencies; vector helper is only a capacity callee and has its own below-gate support page.
- Decision: reject.

### 5. TimerMgr stale UID collision

- Evidence for: some docs/reports contain UID00041B on TimerMgr destructor material.
- Evidence against: address/name/path context is `0x00597780-0x005977ac.TimerMgrStaticDestructorBody`, not this target; generated tracker maps UID00041B to current NewHuman target path. This is validator/supervisor lifecycle cleanup evidence, not target ownership evidence.
- Decision: reject for this report; do not edit TimerMgr docs in the UID00041B NewHuman implementation callback unless explicitly instructed.

## Source Placement

- Recommended source file/class/module placement: `void NewHumanImageLib::LoadPartTable(const wchar_t *tableName)` in `NexusTK/render/NewHumanImageLib.cpp`, emitted from [UID:00041B] through class [UID:000092] to file [UID:0000LR].
- Why this fits source-tree and subsystem context: the body is the retained analog to `LoadLayerTable`, uses NewHuman table resources, mutates the NewHuman part vector, and shares the part resolver/vector helper with the constructor's inline `Part.tbl` loop.
- Rejected placements: constructor body, local cluster, resource page, generic DAT archive helper, generic vector helper, old `HumanImageLib`, and TimerMgr.
- Remaining placement uncertainty: final class declaration/access specifier and exact original method spelling remain future class-header work; they do not block memory-page method emission.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: current target file path `0x004e11b0-0x004e13a7` matches the modeled function start and exclusive end. `sub_4E11B0` size is `0x1f7` / 503 bytes (Verified with int_convert.py). `0x004e13a7-0x004e13b0` is nine bytes of `0xcc` padding before `sub_4E13B0`.
- Children/subranges: no child creation, merge, or split. SEH handler chunks at `0x0060035b` and `0x00600366` are compiler/runtime cleanup metadata for the function, not separate Nexus source bodies.
- Padding/table/data/code distinctions: the function body is source-authored code; adjacent `0xcc` bytes are compiler/linker alignment; `Part.tbl` bytes remain resource-derived payload.
- Parent/container impact: [UID:00017R] remains a non-emitting aggregate inventory page and should update only child-state text if implementation is accepted.

## Negative Evidence Summary

- No direct xrefs to `0x004e11b0`: reject claiming the shipped constructor calls this helper.
- No hard-coded `Part.tbl` literal in target: the helper opens the supplied path argument; constructor separately hard-codes `L"Part.tbl"` in its inline loop.
- No ownership evidence for DAT/resource/vector pages: they are payload or dependency routes.
- No reason to paste `VectorGrowPart` code into this page: source-level push/append is the correct abstraction for the direct-copy/full-capacity helper split.
- No support for preserving old `MotionTableLocalHelperB` name: current decompile/disassembly proves part-table loader behavior.
- No support for TimerMgr evidence: UID collision rows have different address/name/path and are excluded from this target-specific callback.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing method name: `NewHumanImageLib::LoadPartTable`.
- Proposed source signature: `void NewHumanImageLib::LoadPartTable(const wchar_t *tableName)`.
- Proposed row/member names for current docs and C++: `NewHumanPartEntry`, `m_partEntries`, `partId`, `name`, `drawIndexBase`, `descriptorBase`, `spriteArchive`.
- Items intentionally left as inferred: original spellings for `drawIndexBase` and `descriptorBase`, and the exact semantic names of sampled scalar values such as `0,19999` and `20000,39999`.
- IDA DB edits: not requested and not performed.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Recommended metadata clears the active rule: `RECONSTRUCTABLE:TRUE`, confirmed `EMITTER_UIDS:000092` route to a valid file root, and `(88 + 90) / 2 > 85`.
- Recommended code: paste this exact formal block into the target page after supervisor acceptance.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewHumanImageLib::LoadPartTable(const wchar_t *tableName)
{
    DATFile partFile;
    unsigned char header[23];
    int partCount = 0;

    partFile.Open(tableName);
    partFile.Read(header, sizeof(header));
    partFile.Read(&partCount, sizeof(partCount));

    for (int index = 0; index < partCount; ++index)
    {
        NewHumanPartEntry part = {};
        char partName[256];

        partFile.Read(&part.partId, sizeof(part.partId));
        partFile.Read(partName, 20);
        partFile.Read(&part.drawIndexBase, sizeof(part.drawIndexBase));
        partFile.Read(&part.descriptorBase, sizeof(part.descriptorBase));

        const int partNameLength = strlen(partName);
        MultiByteToWideChar(CP_ACP, 0, partName, partNameLength, part.name, 255);
        part.name[partNameLength] = L'\0';

        part.spriteArchive = ResolveSpritePartPath(part.name);
        m_partEntries.push_back(part);
    }

    partFile.Close();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: it keeps the observed path-argument open, 23-byte header read, count read, zero-initialized 68-byte in-memory part row, four file-field reads totaling 32 bytes, ANSI-to-wide conversion with source code page and 255 cap, explicit null terminator at converted length, `ResolveSpritePartPath` call, and append to `m_partEntries`.
- Reason it matches plausible original mid-2000s source shape: it mirrors the accepted constructor `Part.tbl` block and [UID:00041A] `LoadLayerTable` style, uses the project-accepted `DATFile` wrapper and member-vector vocabulary, and expresses the binary direct-copy/vector-grow split as a source-level `push_back`.
- Inferred source-facing names used instead of IDA labels: `LoadPartTable`, `DATFile`, `NewHumanPartEntry`, `m_partEntries`, `ResolveSpritePartPath`, `drawIndexBase`, `descriptorBase`, `spriteArchive`.
- Reason code should not remain blank: the previous no-code rationale depended on below-gate support and unresolved route. Current MCP plus accepted support docs resolve route and source shape enough for first-draft source; unresolved exact spellings only cap score below final-audit.
- Third-party import directive: not applicable.

## Final Recommendation

- Update target metadata to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, blank optional position.
- Insert the exact formal C++ block above into [UID:00041B].
- Update target prose with current MCP/session facts, row/file-payload correction, boundary/padding evidence, no-xref caveat, source signature rationale, owner/emitter decision, and rejected alternatives.
- Synchronize support docs that still call UID00041B below-gate/no-owner/non-emitting, while preserving constructor formal C++ unchanged and keeping [UID:00041G] `VectorGrowPart` below-gate.
- Do not edit generated reports, generated C++, manual coverage reports, validator/tool state, executed archives, lock files, or TimerMgr UID-collision docs during the implementation callback unless the supervisor explicitly expands scope.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md`.
- Metadata/score/owner/emitter/C++:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:000092`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:000092`
  - blank `EMITTER_POSITION_OPTIONAL`
  - formal C++ block from this report
- Body facts to incorporate:
  - Active MCP database/session/health and no MCP writes.
  - `sub_4E11B0`, size `0x1f7`, exact range `0x004e11b0-0x004e13a7`, padding to `0x004e13b0`.
  - Modeled `thiscall` receiver plus `wchar_t *` path argument; source signature `void`.
  - Zero xrefs to target entry; constructor does not call it.
  - 23-byte header/count read, 32-byte file row, 68-byte in-memory row/vector stride, ANSI-to-wide conversion, `ResolveSpritePartPath`, direct append and `VectorGrowPart` full-capacity path.
  - Resource sample and resource-doc evidence for `Part.tbl` count `19`, size `635`, 32-byte file rows, and first row names.
  - Rejected alternatives: `MotionTableLocalHelperB`, constructor-call claim, resource/vector/local-cluster/TimerMgr ownership, raw decompiler C++, stale below-gate no-code rationale.

## Recommended Support Doc Changes

- `by-class/NewHumanImageLib.md`: update the method-family row for `LoadPartTable` from below-gate support to `88/90` class-owned/emitting helper; add a 2026-06-30 B007 sync note; historicalize old B011 blanket wording so UID00041B joins UID000419 and UID00041A as promoted.
- `by-file/NewHumanImageLib.md`: update owned/nearby helper text so UID00041B is no longer grouped with unpromoted support pages; state it emits through [UID:000092] into this source module; preserve that [UID:00041C]/[UID:00041D] and vector helpers remain current-state support pages.
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`: update child inventory/current sync text for UID00041B as class-owned/emitting while the aggregate remains non-emitting.
- `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`: update support text only. Preserve constructor formal C++ unchanged and preserve the no-constructor-call fact; correct Part.tbl file row wording where it discusses UID00041B.
- `by-type/by-struct/NewHumanImageLibLayout.md`: add UID00041B consumer/loader evidence distinguishing 32-byte `Part.tbl` file rows from 68-byte `NewHumanPartEntry` memory rows; keep exact field names inferred.
- `by-resource/new-human-motion-tables.md`: update `Part.tbl` notes to state UID00041B now has first-draft loader source while resource bytes remain DAT payload; record `char.dat` sample count/row-size evidence without hard-coding payload arrays into source.
- `by-item/ResolveSpritePartPath_004E19D0.md` and/or [UID:0002VD] memory page if needed: update call-site wording to note UID00041B is now a class-owned emitting helper and still calls the resolver at `0x004e12fe`; do not change resolver ownership/C++.
- `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md`: update support text to note UID00041B now emits the loader body and remains one of two `VectorGrowPart` callers; keep `VectorGrowPart` metadata blank/no-owner/non-emitting.
- Do not edit TimerMgr docs in this callback unless the supervisor explicitly adds UID-collision cleanup.

## Score And Metadata Recommendation

- Current score/metadata: `84/86`, average `85.0`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, reconstructable true, blank C++.
- Recommended score/metadata: `88/90`, `CANONICAL_OWNER:000092`, `EMITTER_UIDS:000092`, reconstructable true, formal first-draft C++ present.
- Score rationale and reason not higher:
  - Completion rises because this pass adds current MCP session proof, exact boundary/padding evidence, decompile/disassembly facts, file-row versus memory-row correction, resource sample, owner/emitter route, first-draft C++, and support synchronization plan.
  - Confidence rises because live IDA and current support docs directly support body shape, no-xref caveat, route, and C++ source shape.
  - Score stays below final-audit/95 because exact original spellings and precise semantics of the two 32-bit `Part.tbl` scalar fields remain inferred; [UID:00041G] vector helper and [UID:00041C] descriptor loader are still separate below-gate support dependencies.
- Score-improvement attempt: investigated target MCP body, xrefs/callees, boundaries, row sizes, resource payload, accepted support docs, sibling loader reports, and stale collision reports. The remaining open issues are not blockers to promotion but are explicit score caps.

## Open Questions With Attempted Resolution

- Exact original names of the two 4-byte fields read after the ANSI part name:
  - Evidence checked: target decompile/disassembly, constructor C++/docs, layout page, resource sample rows, composition/destructor consumers.
  - Best current resolution: keep accepted `drawIndexBase` and `descriptorBase` in first-draft C++ for consistency with existing constructor/layout source, but document they are inferred and may represent part-id or descriptor index range bounds.
  - Impact: caps confidence below final audit; does not block behavior-preserving loader source.
- Exact original method spelling/access level:
  - Evidence checked: sibling source-facing method names and class/file docs.
  - Best current resolution: `LoadPartTable` is the best source-facing inferred name, matching `LoadMotionTable` and `LoadLayerTable`.
  - Impact: no owner/emitter blocker.
- Whether zero direct xrefs mean the helper is dead/retained:
  - Evidence checked: `xrefs_to 0x004e11b0`, sibling UID00041A report, constructor docs.
  - Best current resolution: retained source-shaped helper with no shipped direct caller. It should still emit because it is reconstructable source code with a confirmed class/file route, same as accepted UID00041A.
  - Impact: preserves no-constructor-call caveat but does not block C++.
- UID00041B TimerMgr collision:
  - Evidence checked: duplicate/stale TimerMgr by-memory page and TimerMgr reports/docs.
  - Best current resolution: reject as unrelated stale UID collision; do not incorporate as target evidence.
  - Impact: potential supervisor/validator cleanup outside this implementation callback.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. Generated/project-level reports and coverage files are validator-owned. After implementation, updating source by-* metadata and running scoped validators should refresh `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and generated `NexusTK/render/NewHumanImageLib.cpp`. No manual coverage-report text is requested.

## Validator And Generated Freshness Expectations

The initial report-only pass ran no validators because no by-* docs were edited. The implementation callback ran the scoped validators from `E:/NTK/GhidraBridge/source-3/project-documentation`; all returned exit code `0` and `ok: 1`.

| File | Command flags | Command ID | Timestamp | Exit | ok | Generated refresh | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md` | `--apply --queue-timeout 240 --wait-generated` | `000000002128` | `2026-06-30T03:15:32-04:00` | `0` | `1` | `completed` | `stats_incremental_noop` for UID00041B, then projected stats update. |
| `by-class/NewHumanImageLib.md` | `--apply --queue-timeout 240 --wait-generated` | `000000002129` | `2026-06-30T03:15:43-04:00` | `0` | `1` | `completed` | `stats_incremental_noop` for UID000092, then projected stats update. |
| `by-file/NewHumanImageLib.md` | `--apply --queue-timeout 240 --wait-generated` | `000000002130` | `2026-06-30T03:15:53-04:00` | `0` | `1` | `completed` | Stats row update for UID0000LR, then projected stats update. |
| `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` | `--apply --queue-timeout 240` | `000000002131` | `2026-06-30T03:16:04-04:00` | `0` | `1` | `deferred` | Pre-existing `missing_ref_uid 0003UD` warning reported twice; projected stats update. |
| `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md` | `--apply --queue-timeout 240` | `000000002132` | `2026-06-30T03:16:05-04:00` | `0` | `1` | `deferred` | `stats_incremental_noop` for UID0002JR, then projected stats update. |
| `by-type/by-struct/NewHumanImageLibLayout.md` | `--apply --queue-timeout 240` | `000000002133` | `2026-06-30T03:16:07-04:00` | `0` | `1` | `deferred` | Stats row update for UID0001VF, then projected stats update. |
| `by-resource/new-human-motion-tables.md` | `--apply --queue-timeout 240` | `000000002134` | `2026-06-30T03:16:16-04:00` | `0` | `1` | `deferred` | Stats row update for UID0001RI, then projected stats update. |
| `by-item/ResolveSpritePartPath_004E19D0.md` | `--apply --queue-timeout 240` | `000000002135` | `2026-06-30T03:16:25-04:00` | `0` | `1` | `deferred` | Stats row update for UID0000VA, then projected stats update. |
| `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md` | `--apply --queue-timeout 240` | `000000002136` | `2026-06-30T03:16:32-04:00` | `0` | `1` | `deferred` | Stats row updates for UID00041G in reconstructable low-score buckets, then projected stats update. |

Generated freshness checks after validators:

- `auto-generated/NexusTK/render/NewHumanImageLib.cpp` refreshed through validator/autogen only. Its header reports `validator-command-id: 000000002135`, `validator-refreshed-at: 2026-06-30T03:16:25-04:00`, and `validator-refresh-source: deferred-generated-refresh`.
- The generated file contains the UID00041B block with `Completion:88`, `Confidence:90`, and `void NewHumanImageLib::LoadPartTable(const wchar_t *tableName)`.
- Existing generated sibling bodies for [UID:0002JR], [UID:00017S], [UID:000419], [UID:00041A], [UID:0002V8], [UID:000437], and [UID:000438] remained present after refresh.
- `auto-generated/-ag-coverage-report-by-memory.md` now lists UID00041B as `emits_code:true`, `reconstructable`, `88%`, `very-strong`, updated `2026-06-30 03:02:30`.
- No generated files, coverage reports, validator state, project stats, or tracker files were manually edited; any changes there were validator-owned side effects.

## Changed Files

Modified by B007 in implementation scope:

- `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md`
- `by-class/NewHumanImageLib.md`
- `by-file/NewHumanImageLib.md`
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`
- `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`
- `by-type/by-struct/NewHumanImageLibLayout.md`
- `by-resource/new-human-motion-tables.md`
- `by-item/ResolveSpritePartPath_004E19D0.md`
- `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md`
- `tools/leaser/Agents/Agent-B007/research/00041B-NewHumanImageLibLoadPartTable-source-quality.md`

Excluded with reason:

- TimerMgr UID-collision docs were not edited because the supervisor callback explicitly excluded them.
- Generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, and lock files were not manually edited.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor returned `ACCEPTED for implementation callback`.
- [x] Target/support docs identified: [UID:00041B], [UID:000092], [UID:0000LR], [UID:00017R], [UID:0002JR], [UID:0001VF], [UID:0001RI], [UID:0000VA] if needed, and [UID:00041G].
- [x] Current target state and actual evidence recorded: MCP session/health, lookup/analyze/disasm/decompile/callees/xrefs/get_bytes/entity query, int_convert values, resource payload sample, current by-* docs, generated rows, and matching executed reports.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C01-C12 now show `applied`.
- [x] Score-limiting blockers researched to resolution or explicit score cap: caller absence, owner route, row-size wording, source signature, first-draft C++, stale UID collision, and unresolved scalar-field names.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback instruction identified this report as accepted.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target and support docs preserve MCP evidence, exact boundary/padding facts, zero-xref/no-constructor-call caveat, 23-byte header/count, 32-byte file-row versus 68-byte memory-row correction, resource sample, source signature rationale, owner/emitter route, score rationale, and rejected alternatives.
- [x] Metadata/score/owner/emitter/C++ changes applied. Proof: target now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, blank optional position, and the formal `void NewHumanImageLib::LoadPartTable(const wchar_t *tableName)` reconstruction.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target rejects `MotionTableLocalHelperB`, constructor-call ownership, resource/vector/local-cluster ownership, TimerMgr UID-collision evidence, raw decompiler C++, and stale below-gate/no-code rationale.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: scalar-field spellings/semantics and final class declaration/access placement remain score caps rather than generic blockers.
- [x] Validators run and results recorded with command, working directory, command id, timestamp, exit code, ok count, warnings, side effects, and generated refresh state. Proof: table above records command IDs `000000002128` through `000000002136`.
- [x] Generated report refresh completed by validator or generated-header freshness checked against returned command metadata. Proof: generated `NewHumanImageLib.cpp` header and UID00041B body are fresh after command `000000002135`; coverage now shows `emits_code:true`.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted UID00041B by-* implementation item remains unapplied; TimerMgr docs were excluded by supervisor scope, and generated/coverage/state files were left to validators.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00041B-NewHumanImageLibLoadPartTable-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00041B-NewHumanImageLibLoadPartTable-source-quality.md","timestamp":"2026-06-30T03:24:03","uid":"00041B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
