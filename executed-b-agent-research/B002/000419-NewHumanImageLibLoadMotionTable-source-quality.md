** TARGET-REPORT-UID:000419 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 000419 NewHumanImageLibLoadMotionTable Source-Quality Research

## Implementation Callback Status
- Callback disposition: accepted report details applied to the target/support by-* docs listed below; no generated/manual coverage files were manually edited.
- Lease status: B002 reacquired the eight by-* target/support paths for the edit/validator batch after B004's overlapping leases expired, then released all B002 leases successfully. `current_leases.md` reported "No active leases" after release.
- Validator status: eight scoped validators completed with `exit=0` and `ok:1`.
- Generated freshness: `auto-generated/NexusTK/render/NewHumanImageLib.cpp` was refreshed by validator deferred generation with `validator-command-id: 000000001846` at `2026-06-30T00:34:14-04:00`; it now contains `UID:000419` and a non-empty `NewHumanImageLib::LoadMotionTable` body.

## Finalized Report / Current Recommendation
- Current recommendation: promote [UID:000419] `by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md` from no-owner/non-emitting support to direct [UID:000092] `NewHumanImageLib` method ownership with formal first-draft C++.
- Final disposition: reconstructable source-authored helper, class-owned, emitted through the `NewHumanImageLib` class route and source module [UID:0000LR] `by-file/NewHumanImageLib.md`.
- Required action: update target metadata from `84/86`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank C++ to `89/90`, `CANONICAL_OWNER:000092`, `EMITTER_UIDS:000092`, and the exact formal C++ block below; synchronize support docs that still describe UID000419 as below-gate.
- Confidence: strong. Current MCP function/xref/decompile evidence, existing constructor/destructor/layout support, and direct `char.dat` payload sampling all agree on range, caller, owner, field sequence, vector destination, and source placement. Exact original spellings for some row fields remain inferred, but they no longer block first-draft C++.

## Target
- Target UID: `000419`.
- Target path: `by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> by-memory not-covered reconstructable queue shows `84/86`, average `85.0`, true reconstructable, no owner/emitter.
- Current supervisor classification: report-first research for current path/address/name; older UID-only TimerHandler reports are stale collisions.
- Current scores and parent state: target is `84/86`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank formal C++. Parent class [UID:000092] is `86/88` and emits through file [UID:0000LR]. Constructor [UID:0002JR] and destructor [UID:00017S] already emit class-owned C++ using accepted `NewHumanImageLib` member names.

## Current Target State
- Existing metadata: `COMPLETION:84`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, `Nested:0`.
- Existing owner/emitter/reconstructable state: no owner, no emitter, candidate class route only in prose.
- Existing C++/emitter state: formal C++ block is blank.
- Existing blockers now rechecked: helper signature, motion row fields, frame arrays, caller/reachability, source placement, and generated output. The only still-unresolved items are final original field spellings and exact 120-byte per-frame payload semantics; these are score caps, not first-draft blockers.
- Related target/support docs checked: target page, [UID:000092] class page, [UID:0000LR] file page, [UID:00017R] local cluster, [UID:0002JR] constructor, [UID:00017S] destructor, [UID:00017T] `VectorGrowMotion`, [UID:0001RI] resource page, [UID:0001VF] layout page, generated `auto-generated/NexusTK/render/NewHumanImageLib.cpp`, generated tracker/coverage rows, executed B010/B011 reports, and stale TimerHandler reports mentioning `UID:000419`.

## Executive Recommendation
- Best direct owner: [UID:000092] `NewHumanImageLib`.
- Source placement: method body in `NewHumanImageLib.cpp`, emitted through the class route to [UID:0000LR] `NexusTK/render/NewHumanImageLib.cpp`.
- Target action: promote target to `89/90`, owner/emitter `000092`, and insert the formal `void NewHumanImageLib::LoadMotionTable(const wchar_t *tableName)` block.
- Split/container action: no split, merge, rename, or new child page. The current range is exact for `sub_4E0E20`, and the next function starts at `0x004e1040`.
- Support action: update support docs that still say UID000419 is below-gate/non-emitting; keep the other helper pages `[UID:000417]`, `[UID:000418]`, `[UID:00041A]` through `[UID:00041G]` unchanged except where text must exclude UID000419 from the below-gate group.

## Supervisor Active Recheck
- The supervisor assigned a report-first source-quality pass for current `[UID:000419] by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md`.
- Split repair is not required. MCP reports `sub_4E0E20`, size `0x21f`, and `lookup_funcs 0x004e103f` reports not a function while `0x004e1040` is the next function.
- Every source-bearing item in scope has a precise disposition: UID000419 should now emit; `VectorGrowMotion` remains a local vector helper with blank C++ because standalone helper spelling/STL detail is still below final-source quality; sibling table helpers remain outside this callback and below-gate unless separately assigned.

## Inference Research Guidance Check
- `by-structure.md` and the B-agent workflow require owner/emitter separation and forbid assigning owner metadata below the route gate. UID000419 now clears that gate because direct MCP evidence plus accepted class/layout/destructor support resolves the former row/frame-array blocker.
- Existing B011 wording was treated as a time-bound child-page creation state, not a permanent no-code proof. Its candidate route condition was "after `NewHumanMotionEntry` and frame-array declarations are synchronized"; current layout/destructor support and this pass's payload/MCP evidence satisfy that for first-draft source.
- IDA fact: function range, xrefs, decompile read sequence, and vector callee. Documentation evidence: accepted class/file/layout/destructor/constructor names and source route. Inference: final field names `direction` and `fallbackMotionId`; these are descriptive and payload-backed, not proven original spellings.
- Wave2/Wave3/source-2 artifacts were not used. Old notes found around vector cleanup are stale historical context only and are superseded by current by-* docs plus MCP.

## Heuristic / Inference Reanalysis And Validation
- Generated-name issue: IDA names are `sub_4E0E20`, `sub_4E5240`, etc. Best source-facing name remains `NewHumanImageLib::LoadMotionTable`; it is supported by the constructor call to the `Motion.tbl` literal and by B011 accepted constructor C++.
- Type issue: `NewHumanMotionEntry` is already accepted in [UID:0001VF]. This pass refines it as a 66-byte packed in-memory entry with fixed fields at offsets `+0x17`, `+0x1b`, `+0x31`, `+0x32`, `+0x36`, `+0x3a`, and `+0x3e`.
- File payload issue: old prose saying "reads 0x42-byte motion rows" is imprecise. MCP decompile shows the helper zeroes a 0x42-byte in-memory entry, then reads a 33-byte fixed file prefix and variable frame arrays. Direct `char.dat` sampling confirms this.
- Caller/reachability issue: `xrefs_to 0x004e0e20` reports one caller at `0x004dfe5a` inside the constructor. `xrefs_to 0x004e5240` reports one caller at `0x004e0ff2` inside the loader. No generic DAT-helper route is supported.
- Source placement issue: class-owned method route is stronger than file-only helper route because the function is `thiscall`, writes the `this+0x1c` motion vector, and is called by the class constructor. File [UID:0000LR] remains the source module emitter root.
- Generated-output issue: generated `NewHumanImageLib.cpp` is fresh from validator command `000000001773` at `2026-06-30T00:05:54-04:00`; it contains the constructor call `LoadMotionTable(L"Motion.tbl");` but no UID000419 body because the target is currently non-emitting.
- Rejected stale UID collisions: executed B002/B004 TimerMgr reports and the B002 TimerHandler callback report mention `UID:000419` for `0x00597650-0x005976b3.TimerHandlerScalarDeletingDestructor`; those are path/address/name mismatches and must not be incorporated.

## Evidence Standards Used
- Evidence types used: IDA MCP `idb_list`, `server_health`, `get_bytes`, `lookup_funcs`, `xrefs_to`, `decompile`, `analyze_function`, constructor decompile refs, generated rows, by-* docs, executed reports, and direct read-only resource payload sampling.
- Evidence strength: strong for ownership and body shape because binary xrefs, constructor string literal, decompile, resource bytes, and existing class layout all converge.
- Confidence cap: field names and exact semantic meaning of the 120-byte per-frame payload remain inferred. This caps score below final-source confidence but does not justify blank C++.

## Evidence Checked
- IDA MCP checks performed: active session discovery, health, bounded memory reads, function lookup, target decompile, constructor decompile, vector helper analysis, xrefs to target/vector/string, and callgraph depth 1.
- by-* docs checked: target, class, file, local cluster, constructor, destructor, vector helper, resource page, layout page.
- Reports/generated checked: executed B011 constructor report, B010 destructor report, generated completion stats, generated memory coverage, generated research tracker, generated `NewHumanImageLib.cpp`.
- Negative checks performed: stale UID-only TimerHandler reports rejected; `find_regex` string scan returned zero for `Motion.tbl`, so the report uses stronger bytes/ref evidence at `0x0061c2e4` instead of the failed string-cache query.
- Failed/unavailable checks: none blocking. MCP was available and responsive.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID000419 is `sub_4E0E20`, size `0x21f`, exact range `0x004e0e20-0x004e103f` exclusive. | Strong | MCP `lookup_funcs`; `0x004e103f` not a function; next function `0x004e1040`. | Target Status/Evidence; constructor/local cluster support | Applied | applied - target status/evidence and local cluster child row now carry exact range/boundary proof. |
| C02 | Direct owner is class [UID:000092] `NewHumanImageLib`; source module route is [UID:0000LR]. | Strong | `thiscall` decompile, writes `this+7` vector, constructor sole caller, class/file docs. | Target metadata, class/file/cluster docs | Applied | applied - target metadata is `CANONICAL_OWNER:000092`, and class/file/cluster docs state the class-owned source route. |
| C03 | Target should emit through `EMITTER_UIDS:000092`. | Strong | Parent class clears `86/88`; constructor/destructor already emit through class; target first-draft C++ ready. | Target metadata | Applied | applied - target metadata is `EMITTER_UIDS:000092`; validator `000000001842` updated registry and marked C++ `blank -> block`. |
| C04 | Old "0x42-byte file row" wording should be corrected to "0x42-byte in-memory entry with 33-byte fixed file prefix plus variable per-frame arrays." | Strong | MCP decompile read sequence; `char.dat` payload sample. | Target Behavior/Evidence; resource/layout/constructor support | Applied | applied - target, constructor, resource, and layout docs now distinguish the 0x42-byte in-memory entry from the 33-byte fixed file prefix and per-frame payload. |
| C05 | Fixed file prefix is `int motionId`, `char name[20]`, `uint8 direction`, `int fallbackMotionId`, `int frameCount`. | Medium-high | MCP read offsets; payload rows `NormalWalkNorth/East/South/West`, direction `0..3`, `fallbackMotionId` `-1` except final test row. | Target, layout, resource page | Applied | applied - target, layout, and resource docs use these descriptive field names with the inference caveat retained. |
| C06 | Dynamic arrays are `frameOffsets` as 2 bytes per frame and `frameData` as 120 bytes per frame. | Strong for size/ownership; medium for names | MCP decompile allocates `2*frameCount` and `120*frameCount`; destructor already uses `frameOffsets`/`frameData`. | Target C++; layout/resource/destructor support | Applied | applied - target C++ reads `frameOffsets` and `frameData`, and support docs tie the names to destructor/layout evidence. |
| C07 | `VectorGrowMotion` remains a support helper, not the target body; first-draft C++ should use source vector push/append, not paste `sub_4E5240`. | Strong | Target decompile calls `sub_4E5240` only when capacity full; existing constructor/destructor C++ uses source container vocabulary. | Target C++; VectorGrowMotion notes | Applied | applied - target C++ uses `m_motionEntries.push_back(motion)`, while `VectorGrowMotion` remains blank/support with source-lowering rationale. |
| C08 | Existing generated `NewHumanImageLib.cpp` was expected to gain UID000419 once the target emitted. | Strong | Pre-callback generated header command `000000001773`; post-callback generated header command `000000001846`. | Report validator/generation notes; implementation checklist | Applied | applied - generated file now contains `UID:000419` and non-empty `NewHumanImageLib::LoadMotionTable` lines 199-237. |
| C09 | Stale TimerHandler UID000419 reports must not be incorporated. | Strong | Executed reports point to `0x00597650-0x005976b3.TimerHandlerScalarDeletingDestructor`, not current path/address/name. | Target rejected alternatives/history | Applied | applied - target rejected alternatives/history preserves stale TimerHandler UID collision rejection. |

## Positive Evidence Summary
- Direct facts: target is a `thiscall` method, sole constructor caller, table literal source at `0x0061c2e4`, destination motion vector at `+0x1c`, and vector grow callee at `0x004e0ff2`.
- Corroborating docs: class/file/layout/destructor docs already accept `NewHumanImageLib`, `m_motionEntries`, and `NewHumanMotionEntry`; constructor formal C++ already calls `LoadMotionTable(L"Motion.tbl");`.
- Strongest inference chain: constructor calls class method with `this` and `Motion.tbl` -> helper fills class motion vector -> accepted layout/destructor names define row/frame cleanup -> payload verifies field sequence -> method-level C++ is safe as first draft.

## IDA MCP Facts
- Session facts: `idb_list` returned one active worker session `supervisor_resume_20260629` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `17592`, `is_analyzing:false`.
- Health facts: `server_health` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, cache size `2067`.
- Byte facts: `get_bytes 0x00401000 size 1` returned `0x8b`; target entry bytes at `0x004e0e20` begin `55 8b ec 6a ff`; boundary bytes around `0x004e103c` include `5d c2 04 00 cc`, with next function prologue at `0x004e1040`.
- Function facts: `lookup_funcs 0x004e0e20` -> `sub_4E0E20`, size `0x21f`; `0x004e103f` not a function; `0x004e1040` -> `sub_4E1040`, size `0x170`; `0x004e5240` -> `sub_4E5240`, size `0x1d5`.
- Xref facts: `xrefs_to 0x004e0e20` -> one code xref at `0x004dfe5a` in constructor `sub_4DFD10`; `xrefs_to 0x004e5240` -> one code xref at `0x004e0ff2` in target; `xrefs_to 0x0061c2e4` -> one data xref at `0x004dfe4f` in constructor.
- Decompile facts: target opens the passed table name, reads 23-byte header, reads 4-byte count, loops count times, zeroes 0x42 bytes, reads fixed fields into offsets `+0x17/+0x1b/+0x31/+0x32/+0x36`, allocates 2-byte and 120-byte per-frame arrays, reads each frame pair, and appends into `this+7` vector, calling `sub_4E5240` at capacity.

## Resource Payload Facts
- Direct read-only file sampled: `E:\NTK\Resources\NexusTK\Data\char.dat`.
- Resource-page package row says `Motion.tbl` is entry index `41`, offset `7,384,382`, size `24,109`.
- Payload sample at that offset: 23-byte header starts `MotionStandard`; count at offset `0x17` is `68`.
- First row under the loader sequence: `motionId=0`, `name=NormalWalkNorth`, `direction=0`, `fallbackMotionId=-1`, `frameCount=4`; each frame has a 2-byte value followed by 120 bytes of frame data.
- First twelve rows confirm direction encoding and fixed field sequence: `NormalWalkNorth/East/South/West`, `WeaponWalk*`, and `Riding*` use directions `0,1,2,3`; frame counts are `4`. Across all 68 rows, `fallbackMotionId` is `-1` for 67 rows and `0` for the final `Test` row.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e0e20-0x004e103f` | [UID:000419] target | `NewHumanImageLib::LoadMotionTable` | TRUE | Recommend [UID:000092] | Recommend `89/90` | Promote and emit |
| `0x004dfd10-0x004e024a` | [UID:0002JR] constructor | Calls `LoadMotionTable(L"Motion.tbl")` | TRUE | [UID:000092] | `91/92` | Already emits |
| `0x004e5240-0x004e5415` | [UID:00017T] `VectorGrowMotion` | Motion vector grow helper | TRUE | [UID:0000LR] | `86/88` | Keep support/no C++ |
| `new-human-motion-tables` | [UID:0001RI] resource page | Table/resource provenance | TRUE | none | `88/93` | Sync row layout wording |
| `NewHumanImageLibLayout` | [UID:0001VF] layout page | Object/vector and row names | TRUE | [UID:000092] | `85/88` | Add motion-row field details |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004dfe4f` | data xref to `0x0061c2e4` | Constructor uses the `Motion.tbl` UTF-16 literal. |
| `0x004dfe5a` | code xref to `0x004e0e20` | Constructor calls loader with `this` in ECX. |
| `0x004e0ff2` | code xref to `0x004e5240` | Loader invokes motion-vector growth on capacity. |
| `0x0061c2e4` | bytes `4d 00 6f 00 ...` | UTF-16 `Motion.tbl` literal; string-cache text rendering is imperfect, bytes are exact. |

## Documentation Evidence And IDA Status
- Supporting docs: class page identifies `LoadMotionTable`; file page places NewHuman table loaders in `NewHumanImageLib.cpp`; layout page accepts `NewHumanMotionEntry`; destructor C++ frees `motion->frameOffsets`, `motion->frameData`, and clears `motion->frameCount`; resource page documents `char.dat` provenance.
- Stale/incomplete docs: target/class/file/cluster/resource/vector-helper/constructor pages still state or imply UID000419 is below-gate/non-emitting; target/resource/class pages also over-compress the loader as "0x42-byte rows" rather than the observed file-vs-memory distinction.
- Generated state: `project-level/-auto-completion-stats.md` has UID000419 at `84/86`; generated memory coverage has no owner/emitter; generated `NewHumanImageLib.cpp` has no UID000419 body yet.

## Ranked Ownership Analysis

### 1. NewHumanImageLib Class [UID:000092]
- Evidence for: `thiscall`; constructor sole caller; destination field is `m_motionEntries`; class owns table family and layout; constructor/destructor already emit class-owned source using same vocabulary.
- Evidence against: exact original field names are inferred, not proven. This affects confidence, not ownership.
- Decision: accept as direct owner and emitter route.

### 2. NewHumanImageLib File [UID:0000LR]
- Evidence for: source module owns table family and adjacent vector helpers.
- Evidence against: method has `this` semantics and class-owned vector state, so file-only ownership is less precise.
- Decision: use as source module route, not direct owner.

### 3. Generic DAT Helper / Runtime Motion Class
- Evidence for: uses generic DAT/file helpers and the word "Motion".
- Evidence against: file name, destination vector, constructor caller, and row layout are NewHumanImageLib-specific; runtime [UID:00008R] `Motion` docs explicitly exclude these helpers.
- Decision: reject.

## Source Placement
- Recommended source file/class placement: `NewHumanImageLib::LoadMotionTable` in `NexusTK/render/NewHumanImageLib.cpp`, method emission through [UID:000092], file route [UID:0000LR].
- Why this fits: constructor already calls this method out-of-line; resource and vector helpers are in the same NewHuman table family; destructor cleans the same vector.
- Rejected placements: generic DAT helper, runtime `Motion` class, resource page hard-coded table arrays, and inlining into constructor.
- Remaining placement uncertainty: exact header declaration/access specifier is class-level future work and does not block method body emission.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: `sub_4E0E20`, size `0x21f`, exclusive range `0x004e0e20-0x004e103f`. `0x004e103f` is not a function and is padding; next function `sub_4E1040` starts at `0x004e1040`.
- Children/subranges: no child creation, merge, or split. Per-frame arrays are data allocated by the function, not separate executable ranges.
- Parent/container impact: local aggregate [UID:00017R] remains a non-emitting cluster; target becomes a concrete emitting child.

## Negative Evidence Summary
- No xrefs show external or generic callers; only constructor calls the target.
- No xrefs show target belongs to runtime `Motion` class.
- No current report with path/address `0x004e0e20` contradicts the NewHuman route.
- Stale UID-only reports for TimerHandler at `0x00597650` are rejected and must not be copied.
- `LoadLayerTable` and `LoadPartTable` remain separate reusable helpers with no constructor xrefs; this report does not promote them.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing method: `NewHumanImageLib::LoadMotionTable`.
- Proposed descriptive row fields for docs/source body: `motionId`, `name[20]`, `direction`, `fallbackMotionId`, `frameCount`, `frameOffsets`, `frameData`.
- Proposed row layout note: 66-byte packed in-memory `NewHumanMotionEntry`; fixed fields begin at in-memory offset `+0x17`; the file fixed prefix is 33 bytes followed by `frameCount` pairs of 2-byte offset/value plus 120-byte raw frame data.
- IDA DB edits: not requested in this B-agent pass.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` block content to insert in the target after supervisor approval:

```cpp
void NewHumanImageLib::LoadMotionTable(const wchar_t *tableName)
{
    DATFile motionFile;
    unsigned char header[23];
    int motionCount = 0;

    motionFile.Open(tableName);
    motionFile.Read(header, sizeof(header));
    motionFile.Read(&motionCount, sizeof(motionCount));

    for (int index = 0; index < motionCount; ++index)
    {
        NewHumanMotionEntry motion = {};

        motionFile.Read(&motion.motionId, sizeof(motion.motionId));
        motionFile.Read(motion.name, sizeof(motion.name));
        motionFile.Read(&motion.direction, sizeof(motion.direction));
        motionFile.Read(&motion.fallbackMotionId,
                        sizeof(motion.fallbackMotionId));
        motionFile.Read(&motion.frameCount, sizeof(motion.frameCount));

        motion.frameOffsets = new unsigned short[motion.frameCount];
        motion.frameData = new unsigned char[motion.frameCount * 120];

        for (int frameIndex = 0;
             frameIndex < motion.frameCount;
             ++frameIndex)
        {
            motionFile.Read(&motion.frameOffsets[frameIndex],
                            sizeof(motion.frameOffsets[frameIndex]));
            motionFile.Read(&motion.frameData[frameIndex * 120], 120);
        }

        m_motionEntries.push_back(motion);
    }

    motionFile.Close();
}
```

- Reason it preserves exact behavior: it keeps the observed 23-byte header read, count read, per-record zero-initialized local row, fixed-field read order, unconditional array allocation, per-frame 2-byte plus 120-byte reads, and append to `m_motionEntries`.
- Reason it matches plausible source shape: existing generated constructor/destructor C++ uses `DATFile`, member vectors, `NewHumanMotionEntry`, `m_motionEntries`, and raw pointer cleanup. Using `push_back` mirrors the source-level abstraction behind the observed vector-growth helper.
- Inferred names: `direction` is payload-backed by 0..3 directional rows; `fallbackMotionId` is descriptive because 67 rows store `-1` and final `Test` stores `0`; `frameOffsets`/`frameData` follow accepted destructor names.
- Reason code should not remain blank: the prior blocker was synchronized row/frame declarations. Current docs already accept the row type and destructor field names, and this pass resolves the fixed field layout enough for first-draft source.
- Third-party import directive: not applicable.

## Final Recommendation
- Apply target metadata: `COMPLETION:89`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `EMITTER_UIDS:000092`, `RECONSTRUCTABLE:TRUE`.
- Apply target C++ block above.
- Preserve rejected alternatives: not generic DAT helper, not runtime `Motion`, not constructor inline body, not stale TimerHandler UID.
- Leave sibling helpers unchanged except support wording: `[UID:000417]`, `[UID:000418]`, `[UID:00041A]` through `[UID:00041G]` remain follow-up inventory only.

## Recommended Target Doc Changes
- Target path: `by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md`.
- Metadata/score/owner/emitter/C++: change to `89/90`, owner/emitter `000092`, formal C++ as above.
- Body facts to incorporate:
  - Current MCP session `supervisor_resume_20260629`, worker PID `17592`, health ok.
  - Function `sub_4E0E20`, size `0x21f`, sole caller `0x004dfe5a`, vector grow callee `0x004e0ff2`, `Motion.tbl` bytes/xref at `0x0061c2e4/0x004dfe4f`.
  - Correct row wording: 0x42-byte in-memory entry, not a simple fixed 0x42-byte file row.
  - File fixed prefix: `motionId`, `name[20]`, `direction`, `fallbackMotionId`, `frameCount`; dynamic payload: `frameCount` times 2-byte frame offset/value plus 120-byte frame data.
  - `char.dat` payload evidence: count `68`; first rows `NormalWalkNorth/East/South/West`; direction values `0..3`.

## Recommended Support Doc Changes
- `by-class/NewHumanImageLib.md`: update `LoadMotionTable` method row from below-gate `84/86` to class-owned/emitting `89/90`; update the B011 helper sync paragraph so UID000419 is excluded from the still-below-gate helper set.
- `by-file/NewHumanImageLib.md`: update constructor/table-loader support paragraph so UID000419 is now an emitting class method while `[UID:00041A]` through `[UID:00041D]` and vector helper pages keep their current dispositions; update generated-output note to expect UID000419 after validation.
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`: update child table and B011 sync notes so UID000419 is no longer grouped with the exact below-gate standalone pages; preserve that the cluster remains non-emitting.
- `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`: update loader/vector notes to link the now-emitting UID000419 body; correct "rows are 0x42 bytes" to "motion vector entries are 0x42 bytes and the loader reads a variable file payload"; preserve that constructor does not paste helper body.
- `by-resource/new-human-motion-tables.md`: correct `Motion.tbl` row wording; add field/payload facts and payload sample; update open questions so final field spelling and 120-byte payload semantics remain unresolved but no longer block UID000419 C++.
- `by-type/by-struct/NewHumanImageLibLayout.md`: add the packed `NewHumanMotionEntry` field layout and note these names are implementation-ready inference for UID000419.
- `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md`: update reconstruction note that UID000419 now emits the loader body; keep `VectorGrowMotion` blank because standalone helper/STL allocation details and original helper spelling remain not source-ready.

## Score And Metadata Recommendation
- Current score/metadata: `84/86`, average `85.0`, no owner, blank emitter, blank C++.
- Recommended score/metadata: `89/90`, owner `000092`, emitter `000092`, reconstructable true.
- Reason not higher: exact original field spellings are inferred; the 120-byte per-frame payload is still described as raw frame data; helper declaration/header placement remains class-level work.
- Reason not lower: current MCP and payload evidence resolve the former blocker and support an exact source-shaped method body.
- Score-improvement attempt: row fields were researched through MCP decompile and direct `char.dat` sampling; frame arrays were tied to accepted destructor names; caller/source placement was revalidated through xrefs; generated output was inspected for freshness.

## Open Questions With Attempted Resolution
- Exact original name of `fallbackMotionId`: payload shows mostly `-1` and final `Test` -> `0`; descriptive name is safe enough, original spelling unknown.
- Exact semantics of each 120-byte frame data block: MCP proves size and ownership, but consumer semantics are not fully decoded. Representing it as `unsigned char *frameData` avoids false structure names.
- Exact class declaration/header placement: not required for a memory-page method body; generated class/file route already emits constructor/destructor methods.
- Whether `frameOffsets` are true offsets, sentinels, or frame selectors: existing destructor uses `frameOffsets` and loader reads 2 bytes per frame; retain accepted descriptive name.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. Generated/project-level reports and coverage files are validator-owned and must not be manually edited by B002.

## Follow-Up Actions
- Supervisor: validate this report and, if accepted, send implementation callback.
- Implementation callback: edit only listed target/support by-* docs under short leases, run scoped validators, and inspect generated `NewHumanImageLib.cpp` freshness.
- Future research outside this callback: decode the 120-byte per-frame payload and sibling helper pages `[UID:000417]`, `[UID:000418]`, `[UID:00041A]` through `[UID:00041G]` if separately assigned.

## Confidence
- Recommendation confidence: strong.
- Score confidence: strong for promotion above gate; medium-high for exact final score because field names remain inferred.
- Remaining uncertainty: final original names and per-frame payload internals only.

## Validator Results
- Implementation callback validators were run from `source-3/project-documentation` with `--mode file --apply --queue-timeout 240`.
- Results:
  - `by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md`: `command_id:000000001842`, `command_timestamp:2026-06-30T00:34:06-04:00`, `exit:0`, `ok:1`. Validator updated completion `89`, confidence `90`, owner `NONE -> 000092`, emitter registry `000092`, and C++ state `blank -> block`.
  - `by-class/NewHumanImageLib.md`: `command_id:000000001843`, `command_timestamp:2026-06-30T00:34:08-04:00`, `exit:0`, `ok:1`. Non-blocking `uid_link_update` rewrote `LoadFrameDrawRecord` link text.
  - `by-file/NewHumanImageLib.md`: `command_id:000000001844`, `command_timestamp:2026-06-30T00:34:10-04:00`, `exit:0`, `ok:1`. Non-blocking `uid_link_update` rewrote `LoadFrameDrawRecord` link text.
  - `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`: `command_id:000000001845`, `command_timestamp:2026-06-30T00:34:12-04:00`, `exit:0`, `ok:1`. Warning retained: `missing_ref_uid 0003UD` appears twice and is not present in `validator.ini`.
  - `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`: `command_id:000000001846`, `command_timestamp:2026-06-30T00:34:14-04:00`, `exit:0`, `ok:1`.
  - `by-resource/new-human-motion-tables.md`: `command_id:000000001847`, `command_timestamp:2026-06-30T00:34:24-04:00`, `exit:0`, `ok:1`.
  - `by-type/by-struct/NewHumanImageLibLayout.md`: `command_id:000000001848`, `command_timestamp:2026-06-30T00:34:30-04:00`, `exit:0`, `ok:1`.
  - `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md`: `command_id:000000001849`, `command_timestamp:2026-06-30T00:34:32-04:00`, `exit:0`, `ok:1`.
- Generated refresh state: each validator reported `generated_refresh: deferred`. Read-only generated inspection found `auto-generated/NexusTK/render/NewHumanImageLib.cpp` header `validator-command-id: 000000001846`, `validator-refreshed-at: 2026-06-30T00:34:14-04:00`, `validator-refresh-source: deferred-generated-refresh`; grep found `UID:000419` at line 199 and `void NewHumanImageLib::LoadMotionTable(const wchar_t *tableName)` at line 200 with a non-empty body through line 237.

## Changed Files
- Modified by B002 under short leases:
  - `by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md`
  - `by-class/NewHumanImageLib.md`
  - `by-file/NewHumanImageLib.md`
  - `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`
  - `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`
  - `by-resource/new-human-motion-tables.md`
  - `by-type/by-struct/NewHumanImageLibLayout.md`
  - `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md`
- Modified without by-* lease requirement: `tools/leaser/Agents/Agent-B002/research/000419-NewHumanImageLibLoadMotionTable-source-quality.md`.
- Validator-owned generated output inspected, not manually edited: `auto-generated/NexusTK/render/NewHumanImageLib.cpp`.
- Generated reports and `-coverage-report.md` files were not manually edited.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation - accepted by supervisor for this bounded implementation callback.
- [x] Target/support docs to update: target, class, file, local cluster, constructor, resource page, layout page, VectorGrowMotion support note.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply: target `89/90`, owner/emitter `000092`.
- [x] Score-limiting blockers researched: helper signature, row fields, frame arrays, caller/reachability, source placement, generated output. Remaining blockers are exact spellings/frame payload semantics only.
- [x] Owner/emitter/reconstructable changes to apply: target class owner/emitter, reconstructable unchanged true.
- [x] Split/rename/new-child changes to apply: none.
- [x] Source-placement/range/padding/reclassification changes: source placement to `NewHumanImageLib` class route; no range/split changes.
- [x] First-draft C++ to apply: exact block in this report.
- [x] Third-party import directive: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail recorded.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: stale TimerHandler UID collisions, generic DAT/runtime Motion/inlining rejects, old 0x42-file-row wording correction.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: no current evidence used.
- [x] Open questions documented with evidence-backed unresolved rationale.
- [x] Validators to run listed.
- [x] Generated report refresh expected through validator only; no manual generated/coverage edits.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/C++ changes applied: target is `89/90`, `CANONICAL_OWNER:000092`, `EMITTER_UIDS:000092`, with formal C++ block.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded: command IDs `000000001842` through `000000001849`, all `exit=0`, `ok:1`.
- [x] Generated report refresh completed by validator/deferred queue and generated freshness inspected: generated C++ header `000000001846` at `2026-06-30T00:34:14-04:00`; UID000419 body emitted.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/000419-NewHumanImageLibLoadMotionTable-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/000419-NewHumanImageLibLoadMotionTable-source-quality.md","timestamp":"2026-06-30T00:38:43","uid":"000419"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
