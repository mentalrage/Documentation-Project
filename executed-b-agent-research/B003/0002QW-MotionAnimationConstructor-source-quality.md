** TARGET-REPORT-UID:0002QW **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002QW MotionAnimationConstructor Source-Quality Research

** TARGET: by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md **
** REPORT-TYPE: B-agent source-quality research with implementation callback applied **
** REPORT-TIMESTAMP: 2026-07-06T13:17:42-04:00 **

## Finalized Report / Current Recommendation

UID0002QW is source-authored `Motion` constructor logic and now has its accepted first-draft `Motion::Motion(...)` body in the target formal C++ block. Current IDA MCP session `0af70ed8` confirms the exact function at `0x00539bc0` has size `0x183`, so the executable body is `0x00539bc0-0x00539d43`; the bytes after `0x00539d43` are constructor-local switch tables and alignment before alternate constructor `0x00539de0`, not a separate source function. The only direct code xref to the constructor start is `0x0053b5f9` inside `sub_53B3D0`, the LivingObjectPane action/effect helper that allocates from the Motion pool and constructs a `Motion` object in-place.

Implementation callback state: applied. Target metadata is `COMPLETION:90`, `CONFIDENCE:92`; owner/emitter/reconstructable/optional emitter/Nested metadata is preserved; stale "unassigned" language is historicalized; support docs carry the source-readiness/caller context with no support score change; validators passed; generated `auto-generated/NexusTK/render/Motion.cpp` now contains non-empty UID0002QW constructor output.

## Supporting Research

Read and applied the current project-level `ntk-b-agent-workflow` skill, the B-agent research/implementation workflow, score-blocker standard, B-agent report template, `by-structure.md` IDA MCP Output Discipline, and `by-memory/-guidance.md`. Historical initial state was report-only before Gate 1; after supervisor callback, B003 edited only the accepted by-* scope and this report. No generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, or report execution/archive locations were edited manually. Scoped validators produced validator-owned generated/project-state side effects recorded below.

Direct old-report/doc search terms from `goal.md`: `TARGET-REPORT-UID:0002QW`, `0002QW`, `0x00539bc0`, `0x00539d43`, `MotionAnimationConstructor`, `MotionAnimationConstructorTimerCluster`, `Motion`, `MotionPool`, `sub_539BC0`, `0x0053b5f9`, `0001DD`, `00008R`, and `0000LL`.

Search results: no prior direct B-agent report for `TARGET-REPORT-UID:0002QW` was found. Relevant leads only were B007 `0002QX-MotionAnimationAlternateConstructor-source-quality.md`, B008 `000356-MotionVtableData-source-quality.md`, B001 `0003CC-ObjectOverlayFrameIndexTables.md`, and supervisor/C001 notes about narrowing the old broad Motion span into [UID:0001DD] `MotionAnimationConstructorTimerCluster`. Those reports were treated as leads, not substitutes for this UID0002QW report.

Related current docs checked: target UID0002QW, [UID:00008R] `by-class/Motion.md`, [UID:0000LL] `by-file/Motion.md`, [UID:0001DD] `by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md`, siblings UID0002QX/UID0002QY/UID0002QZ, UID000356 Motion vtable data, UID0002WR Motion pool static storage, UID00028Q `g_pConfig`, LivingObjectPane caller/support docs for `0x0053b3d0`, and generated `auto-generated/NexusTK/render/Motion.cpp`.

## Target

- UID: `0002QW`
- Target doc: `by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md`
- Current title: `MotionAnimationConstructor`
- Function: `sub_539BC0`
- Exact executable range: `0x00539bc0-0x00539d43`
- Current owner/emitter: [UID:00008R] `Motion`, emitted through [UID:0000LL] `NexusTK/render/Motion.cpp`
- Container: [UID:0001DD] `0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster`
- Related siblings: UID0002QX alternate constructor, UID0002QY timer tick, UID0002QZ scalar deleting destructor, UID000356 vtable data, UID0002WR Motion pool storage

## Current Target State

Post-callback target state: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00008R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008R`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:4`. The formal `RECONSTRUCTION_CPP CODE` block now contains the accepted first-draft `Motion::Motion(LivingObjectPane *owner, int motionType, int timerDelay, char soundOverride)` body.

The target body recognizes `AUTOGEN_PARENT_UID` as `Motion`, distinguishes the exact child from the non-emitting parent cluster, and now documents the current MCP session `0af70ed8`, exact range/size, table/padding boundary, sole caller, Motion vptr/pool evidence, pointer-search negatives, no local UDT, owner `ShowName()`/`HideName()` slot proof, score rationale, and rejected alternatives. The stale "remains unassigned" Item Summary language is no longer current truth and has been replaced with the callback-approved source-ready state.

Generated output observation: historical pre-callback read showed `auto-generated/NexusTK/render/Motion.cpp` at command `000000007524` with UID0002QW as an empty marker. After validation, current generated header is `validator-command-id: 000000007588`, `validator-refreshed-at: 2026-07-06T13:34:03-04:00`, and UID0002QW appears at generated lines 7-8 as a non-empty `Motion::Motion(LivingObjectPane *owner, int motionType, int timerDelay, char soundOverride)` block with `Completion:90 | Confidence:92`.

## Heuristic / Inference Reanalysis And Validation

The prior score blockers were exact range, table/padding split, caller route, source owner, field names, sound/config semantics, and first-draft C++ readiness. Current MCP evidence resolves them enough for a formal first draft:

- Range is exact: `lookup_funcs` reports `sub_539BC0` at `0x00539bc0` with size `0x183`; `0x00539d43` is not a function. The successor source function is alternate constructor `sub_539DE0` at `0x00539de0`.
- `0x00539d43-0x00539de0` is not a child function. It contains jump-table bytes for the two constructor switches and then `0xcc` padding before `0x00539de0`.
- Reachability is live and source-facing. `xrefs_to 0x00539bc0` returns one code xref at `0x0053b5f9` in `sub_53B3D0`, which allocates from Motion pool storage `0x0069b984`, calls the constructor, inserts the result into the active effect list, and schedules the timer view at `motion + 4`.
- The owner type is `Motion`, not the caller/helper container. Both constructors write Motion primary and adjusted vptrs at `0x00620954` and `0x00620964`; B008 already documents those vtable slots as Motion vtable data.
- The source route is `NexusTK/render/Motion.cpp`. The non-emitting cluster UID0001DD remains an index/container and should not receive emitted C++.
- Field names are no longer a blank-C++ blocker because UID0002QX and UID0002QY already stabilized `m_owner`, `m_motionType`, `m_soundEffectId`, `m_soundTriggerFrame`, `m_currentFrame`, `m_terminalFrame`, and `m_timerDelay`. UID0002QW uses the same layout and adds the LivingObjectPane name-visible virtual calls.
- The `dword_67A7C8 + 0x28de71` byte gate is already source-facing in UID00028Q and UID0002QX as `g_pConfig->m_motionType16SoundEnabled`; this constructor uses the same field for motion type `16`.
- No local IDA `Motion` UDT exists (`search_structs Motion` returned an empty result), so the C++ remains first-draft/inferred rather than final header-quality.

## Evidence Standards Used

I used current by-* docs for ownership/source placement, current generated output for emission state, and live IDA MCP evidence for function boundaries, disassembly/decompilation, xrefs, byte ranges, pointer-pattern negatives, and numeric conversions. MCP calls used session `0af70ed8` on `http://127.0.0.1:13337/mcp`, with narrow exact-address inputs and capped results. No broad unbounded callgraph, batch analysis, or write/edit MCP tools were used.

The report does not rely on failed schema attempts. One local `entity_query` names-range call timed out and is not used as evidence. The successful evidence set is sufficient: `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`, `find_bytes`, `search_structs`, `get_int`, `int_convert`, and current docs/generated reads.

## Evidence Checked

- MCP health: `server_health` for session `0af70ed8` returned `status:ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- MCP session: `idb_list` showed one active/adopted/owned worker session `0af70ed8`, PID/worker PID `9588`, created `2026-07-06T13:14:40.356823`.
- Function boundaries: `lookup_funcs` returned `0x00539bc0 sub_539BC0 size 0x183`; `0x00539d43` is not a function; `0x00539de0 sub_539DE0 size 0x172`; `0x00539fe0 sub_539FE0 size 0x12c`; `0x0053b3d0 sub_53B3D0 size 0x2e3`; `0x0053d590 sub_53D590 size 0x84`; `0x0053d800` and `0x0053d810` are 8-byte name visibility methods.
- Constructor xrefs: `xrefs_to 0x00539bc0` returned only `0x0053b5f9` in `sub_53B3D0`; `0x00539d43` and `0x00539de0` returned zero target-start xrefs.
- Table xrefs: `xrefs_to 0x00539d44` returned one data xref from `0x00539c34`; `xrefs_to 0x00539d78` returned one data xref from `0x00539c94`. These are internal constructor jump-table users.
- Vtable writes: `xrefs_to 0x00620954` returned writes from UID0002QW `0x00539c11` and UID0002QX `0x00539e47`; `xrefs_to 0x00620964` returned writes from UID0002QW `0x00539c17` and UID0002QX `0x00539e4d`.
- Pool storage xrefs: `xrefs_to 0x0069b984` returned five refs: `0x0041a124` init, `0x0053b5d5` constructor caller allocation route, `0x0053ce75` unwind free wrapper, `0x0053d5d0` scalar deleting destructor, and `0x0060c390` cleanup.
- Callees: UID0002QW calls only `sub_4F4A80` and `sub_597570` in the source-body path; `sub_53B3D0` calls `sub_53B700`, `sub_53B130`, `sub_4B1400`, `sub_539BC0`, `sub_597600`, and `sub_597910`.
- Decompile: `sub_539BC0` initializes base `this`, timer subobject `this+4`, stores timer delay at `+0x18`, writes Motion vptrs, stores owner `+0x08`, motion type `+0x0c`, current frame `+0x13 = -1`, terminal/sound-trigger bytes at `+0x14/+0x12`, sound/effect id word at `+0x10`, and returns `this`.
- Disassembly: 125 instructions, `retn 10h`, stack args `arg_0`, `arg_4`, `arg_8`, `arg_C`, two jump switches at `0x00539c34` and `0x00539c94`, and compiler EH/security-cookie unwind helpers outside the source body.
- Bytes: `0x00539bb2-0x00539bc0` is all `0xcc`; `0x00539bc0` begins `55 8b ec 6a ff 68 73 52 60 00 ...`; `0x00539d20` contains the tail store/return and immediately enters table bytes; `0x00539d43` starts table bytes; `0x00539dd0` contains the last table dword then twelve `0xcc` bytes before `0x00539de0`.
- Pointer-pattern negatives: `find_bytes` for `C0 9B 53 00`, `C0 9B 13 00`, `43 9D 53 00`, and `43 9D 13 00` returned zero matches, each with cursor done.
- Local type negative: `search_structs Motion` returned `[]`.
- LivingObjectPane vtable slots: `get_int` reads `0x006209ec -> 5485520 (0x0053b3d0)`, `0x006209f0 -> 5494784 (0x0053d800)`, and `0x006209f4 -> 5494800 (0x0053d810)`. This verifies owner virtual slot `+0x70` is `PlayActionAnimationOrEffect`, `+0x74` is `ShowName`, and `+0x78` is `HideName` in the current support docs.
- Numeric conversions: MCP `int_convert` verified `0x183 = 387`, `0x10 = 16`, `0x28de71 = 2678385`, `0x74 = 116`, `0x78 = 120`, `5485520 = 0x53b3d0`, `5494784 = 0x53d800`, and `5494800 = 0x53d810`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---:|---|---|---|---|
| C-0002QW-01 | UID0002QW exact body is `0x00539bc0-0x00539d43`, `sub_539BC0`, size `0x183`/387 bytes; `0x00539d43` is not a function. | High | MCP `lookup_funcs`; `int_convert 0x183`; disasm return at `0x00539d40`. | Target Item Summary, IDA MCP Evidence, and Change Log | incorporate | applied |
| C-0002QW-02 | `0x00539d43-0x00539de0` belongs to constructor-local jump-table bytes plus final `0xcc` padding, not a split child or separate source routine. | High | MCP `get_bytes`; table xrefs from `0x00539c34` to `0x00539d44` and `0x00539c94` to `0x00539d78`; successor `sub_539DE0` starts at `0x00539de0`. | Target IDA MCP Evidence and Source-Quality; UID0001DD child row/evidence | incorporate | applied |
| C-0002QW-03 | The only direct code xref to the constructor start is `0x0053b5f9` in `sub_53B3D0`, which allocates from `0x0069b984`, constructs Motion, inserts into the active effect list, and schedules the timer view. | High | MCP `xrefs_to`, `decompile 0x0053b3d0`, `callees`, Motion pool xrefs. | Target caller prose; optional LivingObjectPane caller support note | incorporate | applied |
| C-0002QW-04 | Constructor ownership/emission belongs to `Motion` / `NexusTK/render/Motion.cpp`, not UID0001DD, LivingObjectPane, Motion pool storage, vtable data, or helper/unwind pages. | High | Vptr stores to Motion vtables; current by-class/by-file Motion route; pool/free/destructor pages are support artifacts. | Target Source-Quality; by-class/by-file Motion source-readiness notes | already-present | applied |
| C-0002QW-05 | Preserve `CANONICAL_OWNER:00008R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008R`, blank optional emitter position, and `Nested:4`. | High | Current target metadata is already correct; evidence supports same owner/emitter. | Target metadata | already-present | already-present |
| C-0002QW-06 | Raise target metadata from `86/89` to `90/92`, not higher, because first-draft C++ and exact route are now ready while exact original header/member enum spellings remain inferred. | High | Current MCP evidence resolves range/caller/C++ blockers; `search_structs Motion` returns no local UDT; support docs keep class declaration caveats. | Target metadata, Status, and Change Log | incorporate | applied |
| C-0002QW-07 | Formal C++ was inserted for `Motion::Motion(LivingObjectPane *owner, int motionType, int timerDelay, char soundOverride)` with base/timer initialization, field stores, motion-type frame switch, name visibility calls, sound/effect switch, and config gate. | Medium-high | MCP decompile/disasm; UID0002QX/UID0002QY field-name stabilization; LivingObjectPane vtable slot reads for `ShowName`/`HideName`. | Target formal `RECONSTRUCTION_CPP CODE` block | incorporate | applied |
| C-0002QW-08 | Owner virtual calls in cases `27` and `28` are source-facing `ShowName()` and `HideName()`, via owner vtable slots `+0x74` and `+0x78`. | High | MCP disasm calls `[eax+74h]` and `[eax+78h]`; `get_int` vtable reads; LivingObjectPane docs identify `0x0053d800`/`0x0053d810`. | Target Behavior/Status/Formal C++; Motion class/file notes | incorporate | applied |
| C-0002QW-09 | Sound/effect mapping is source-authored switch logic: type `2 -> 709`, `4 -> 406`, `8 -> 403`, `9 -> 312`, `10 -> 313`, `11 -> 300`, `12/23 -> 301`, `13 -> 302`, `14/24 -> 303`, `15 -> 304`, `16 -> config-gated 305/-1`, `17 -> 306`, `18 -> 307`, `19 -> 308`, `20 -> 309`, `21 -> 310`, `22 -> 311`; negative override forces `-1`; default uses the override. | High | MCP decompile/disasm switch at `0x00539c94`; `g_pConfig + 0x28de71` evidence from UID00028Q/UID0002QX. | Target Behavior and formal C++ | incorporate | applied |
| C-0002QW-10 | The target Item Summary historicalizes stale "remains unassigned" wording; current state is assigned Motion child with first-draft C++ and source-detail confidence caps. | High | Current target text previously conflicted internally with metadata/support score state. | Target Item Summary and Status | historicalize | applied |
| C-0002QW-11 | Support docs add UID0002QW primary-constructor source-readiness context at report-level detail, with no class/file/parent score change. | Medium-high | by-class/by-file Motion already route the family; parent cluster remains non-emitting; target score movement is enough. | `by-class/Motion.md`, `by-file/Motion.md`, UID0001DD parent cluster, optional UID0003Z5 caller note | incorporate | applied |
| C-0002QW-12 | Generated `auto-generated/NexusTK/render/Motion.cpp` refreshed from UID0002QW empty marker to non-empty constructor code after validation; UID0002QX remains existing sibling output. | High | Historical report-time generated read showed UID0002QW empty marker; validators refreshed generated output. | Generated freshness observation only; no manual generated edit | incorporate | applied |
| C-0002QW-13 | Reject stale non-update alternatives: no owner migration to LivingObjectPane, no ownership by Motion pool/free/unwind/destructor pages, no split child for switch tables, no raw vtable/table byte emission, and no target no-code disposition. | High | MCP xrefs/bytes/vptr stores/caller route; current support docs. | Target rejected alternatives; support route notes | reject-invalid | applied |
| C-0002QW-14 | Scoped validators ran after callback for each changed by-* doc; B003 did not run `execute_report` or lifecycle/archive commands. | High | Validator command outputs `000000007586`-`000000007590`; assignment and workflow constraints. | Validator Results and Implementation Tracking Checklist | incorporate | applied |

## Positive Evidence Summary

The constructor is live, source-authored, and Motion-owned. MCP decompilation shows normal constructor shape: base constructor call, timer subobject constructor, vptr stores, member stores, two source-level switches, and a `this` return with `retn 10h`. The only direct caller allocates a Motion block from `0x0069b984`, passes `this` from LivingObjectPane plus action/value/facing fields, then schedules the timer subobject at `motion + 4`. Vtable writes hit the known Motion vtable data, and sibling UID0002QX confirms the same layout and source route through `Motion.cpp`.

The source names are now strong enough for first-draft C++. `m_owner`, `m_motionType`, `m_soundEffectId`, `m_soundTriggerFrame`, `m_currentFrame`, `m_terminalFrame`, and `m_timerDelay` are supported by UID0002QX/UID0002QY. `g_pConfig->m_motionType16SoundEnabled` is already documented by UID00028Q and UID0002QX. Owner virtual slot evidence plus LivingObjectPane docs identifies `ShowName()` and `HideName()` for action types `27` and `28`.

## IDA MCP Facts

Current session `0af70ed8` facts:

- `sub_539BC0` exact range is `0x00539bc0-0x00539d43`.
- `0x00539d43` is not a function; `sub_539DE0` begins at `0x00539de0`.
- Primary constructor has one direct code xref: `0x0053b5f9` in `sub_53B3D0`.
- Local constructor table addresses `0x00539d44` and `0x00539d78` each have one data xref from inside `sub_539BC0`.
- Pointer-pattern searches for UID0002QW start/end VA/RVA were negative.
- `search_structs Motion` returned no IDA UDT; C++ remains first-draft.
- Vtable-slot reads verify `0x006209ec -> 0x0053b3d0`, `0x006209f0 -> 0x0053d800`, and `0x006209f4 -> 0x0053d810`.

## Function / Child Inventory

| Range | UID | Role | Current disposition |
|---|---|---|---|
| `0x00539bc0-0x00539d43` | UID0002QW | Primary Motion constructor | Reconstructable; now emits first-draft C++ |
| `0x00539d43-0x00539de0` | none | Primary-constructor switch tables and final padding | No split; document as constructor-local data/padding |
| `0x00539de0-0x00539f52` | UID0002QX | Alternate Motion constructor | Already emits first-draft C++ |
| `0x00539f52-0x00539fe0` | none | Alternate-constructor switch tables/padding | Already documented as no split |
| `0x00539fe0-0x0053a10c` | UID0002QY | Motion timer tick | Motion-owned timer handler; blank C++ currently separate |
| `0x0053d590-0x0053d614` | UID0002QZ | Scalar deleting destructor wrapper | Motion-owned compiler wrapper, separate discontiguous destructor family member |

## Direct Xref / Caller Inventory

`xrefs_to 0x00539bc0` returns one direct code xref:

- `0x0053b5f9` in `sub_53B3D0`, documented in support docs as `LivingObjectPane::PlayActionAnimationOrEffect`. The decompile shows the caller gates non-animated object action effects, skips action `25`, checks name-visible state for selected actions, clears current effects for action `27`, allocates from `unk_69B984`, calls `sub_539BC0((int)v8, this, v7, (__int16)a3, a4)`, inserts the constructed object into the active-effects list at owner `+0x1bc`, updates current effect `+0x1c0`, and calls `sub_597910` with `v9 + 4` as the timer-handler view.

This caller proves liveness and receiver type context, but it does not make LivingObjectPane the owner of UID0002QW. The constructed object writes Motion vptrs and lives in the Motion pool.

## Documentation Evidence And IDA Status

The target and support docs already establish the right owner route but need the current source-quality details. `by-class/Motion.md` says the animation constructor/timer cluster builds timer-driven motion objects with owner pointer, motion type/duration, packed sound/frame state, and timer registration. `by-file/Motion.md` routes the animation object family through `NexusTK/render/Motion.cpp`. UID0001DD is correctly non-emitting, but still mentions primary constructor cleanup as a remaining blocker at a higher level. UID0002QX's executed report and target docs already stabilized the alternate constructor's field names and config-gate spelling. UID000356 documents the Motion vtable data and primary/adjusted vptr stores. UID0002WR documents the static pool storage used by the sole caller.

Historical pre-callback generated output confirmed the practical blocker: UID0002QW emitted as an empty marker despite being reconstructable and owner-routed. Post-callback generated output no longer has that blocker; UID0002QW is now a non-empty generated constructor block in `auto-generated/NexusTK/render/Motion.cpp`.

## Ranked Ownership Analysis

1. [UID:00008R] `Motion` / [UID:0000LL] `Motion.cpp` - Best owner. The function writes Motion vptrs, initializes the Motion object layout shared by UID0002QX/UID0002QY, uses Motion pool storage, and belongs to the Motion constructor/timer family.
2. [UID:0001DD] `MotionAnimationConstructorTimerCluster` - Container only. It indexes exact children and must stay non-emitting because it spans multiple source functions and local table gaps.
3. LivingObjectPane / `sub_53B3D0` - Consumer/caller only. It allocates and constructs Motion effects but does not own the constructor body.
4. Motion pool/free/unwind/destructor pages - Support artifacts only. Pool allocation and EH/destructor wrappers prove lifecycle, not constructor ownership.
5. UID000356 Motion vtable data - Data support only. Vptr stores prove ownership but raw vtable bytes should not own source constructor C++.

## Source Placement

Emit through [UID:0000LL] `NexusTK/render/Motion.cpp` under class [UID:00008R] `Motion`. The source-facing constructor is now represented as a normal `Motion::Motion(...)` body. The direct caller is a LivingObjectPane method, so the first parameter is best represented as `LivingObjectPane *owner` for UID0002QW because this constructor directly calls owner name-visibility methods for motion types `27` and `28`. This is slightly narrower than UID0002QX's accepted `ObjectPane *owner` spelling, but the narrowing is evidence-backed for the primary path and remains a first-draft signature caveat.

No raw switch table, EH table, vtable, or pool-storage bytes were hand-emitted. The compiler-generated SEH/security-cookie unwind helpers at `0x00605260+` are implementation details attached to constructor cleanup, not a separate source body.

## Range / Split / Padding / Reclassification Analysis

No split is recommended. The executable source body ends at `0x00539d43`; `0x00539d43-0x00539de0` is attached local data and padding:

- `0x00539d43` begins table bytes immediately after `retn 10h` and the local `0x90`.
- `0x00539d44` is the jump table reached by `jmp ds:jpt_539C34[eax*4]` at `0x00539c34`.
- `0x00539d78` is the jump table reached by `jmp ds:jpt_539C94[ecx*4]` at `0x00539c94`.
- `0x00539dd0` still contains table dword bytes, followed by twelve `0xcc` bytes before `0x00539de0`.
- `0x00539de0` is the next function and starts UID0002QX.

The target filename range is acceptable because it tracks the exact function body. The target prose now documents the trailing constructor-local table/padding relationship so future split tools do not invent a raw child.

## Negative Evidence Summary

- No direct xrefs to `0x00539d43` or `0x00539de0` from UID0002QW; the latter is the next function entry, not part of this body.
- No VA/RVA pointer-pattern hits for `0x00539bc0` or `0x00539d43`, so there is no data-table route overriding the direct caller evidence.
- No local IDA `Motion` UDT exists, so exact header/member enum names remain inferred and cap confidence.
- No evidence supports moving ownership to LivingObjectPane, because the caller constructs a Motion object and stores/schedules it as an effect.
- No evidence supports no-code or raw-data disposition; the body is source-authored constructor logic.
- No evidence supports a generated-callsite/pool-only owner; pool/free/unwind/destructor references are lifecycle support around the same Motion object.

## IDA Rename / Type / Comment Recommendations

No IDA writes were made during this research or callback implementation. If a later IDA naming pass is authorized, the best source-facing name for `sub_539BC0` is `Motion::Motion` or `Motion_ctor_primary_actionEffect`. Do not rename jump tables as source globals. The current formal C++ keeps member names already used by UID0002QX/UID0002QY and avoids inventing enum constants until the wider Motion/action enum is recovered.

## First-Draft C++ Recommendation

Insert this exact block into the target formal `RECONSTRUCTION_CPP CODE` block after supervisor callback:

```cpp
Motion::Motion(LivingObjectPane *owner, int motionType, int timerDelay, char soundOverride)
    : LObject(),
      TimerHandler()
{
    m_timerDelay = timerDelay;
    m_owner = owner;
    m_motionType = motionType;
    m_currentFrame = -1;

    switch (motionType)
    {
    case 1:
    case 2:
        m_terminalFrame = 2;
        m_soundTriggerFrame = 1;
        break;

    case 22:
        m_terminalFrame = 4;
        m_soundTriggerFrame = 0;
        break;

    case 27:
        m_terminalFrame = 2;
        m_soundTriggerFrame = 1;
        owner->ShowName();
        break;

    case 28:
        m_terminalFrame = 2;
        m_soundTriggerFrame = 0;
        owner->HideName();
        break;

    default:
        if ((motionType >= 3 && motionType <= 21) || motionType == 23 || motionType == 24)
            m_terminalFrame = 1;
        else
            m_terminalFrame = 0;
        m_soundTriggerFrame = 0;
        break;
    }

    if (soundOverride < 0)
    {
        m_soundEffectId = -1;
        return;
    }

    switch (motionType)
    {
    case 2:
        m_soundEffectId = 709;
        break;
    case 4:
        m_soundEffectId = 406;
        break;
    case 8:
        m_soundEffectId = 403;
        break;
    case 9:
        m_soundEffectId = 312;
        break;
    case 10:
        m_soundEffectId = 313;
        break;
    case 11:
        m_soundEffectId = 300;
        break;
    case 12:
    case 23:
        m_soundEffectId = 301;
        break;
    case 13:
        m_soundEffectId = 302;
        break;
    case 14:
    case 24:
        m_soundEffectId = 303;
        break;
    case 15:
        m_soundEffectId = 304;
        break;
    case 16:
        m_soundEffectId = g_pConfig->m_motionType16SoundEnabled ? 305 : -1;
        break;
    case 17:
        m_soundEffectId = 306;
        break;
    case 18:
        m_soundEffectId = 307;
        break;
    case 19:
        m_soundEffectId = 308;
        break;
    case 20:
        m_soundEffectId = 309;
        break;
    case 21:
        m_soundEffectId = 310;
        break;
    case 22:
        m_soundEffectId = 311;
        break;
    default:
        m_soundEffectId = soundOverride;
        break;
    }
}
```

## Final Recommendation

UID0002QW callback implementation is complete. The target moved to source-ready constructor documentation with formal C++ inserted, the Motion owner/emitter route stayed unchanged, and no-code/raw-data/split alternatives were rejected. Support docs were updated only to preserve Rule 26 detail about primary-constructor readiness, caller context, and generated-output expectations.

## Recommended Target Doc Changes

Applied to `by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md`:

- Changed `COMPLETION:86` to `COMPLETION:90`.
- Changed `CONFIDENCE:89` to `CONFIDENCE:92`.
- Kept `CANONICAL_OWNER:00008R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008R`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:4`.
- Inserted the formal C++ block from this report.
- Replaced stale Item Summary wording that said the target remained unassigned due old child/parent scores. Current state is Motion-owned, reconstructable, and source-ready with first-draft C++.
- Added current MCP session `0af70ed8` and report-level evidence: exact range/size, `0x00539d43` not-a-function, table/padding bytes through `0x00539de0`, one direct caller at `0x0053b5f9`, Motion vptr stores, pool storage xrefs, no VA/RVA pointer hits, no local UDT, and historical generated empty-marker state.
- Documented source-facing field names and the first-draft signature caveat: `LivingObjectPane *owner` is supported for the primary constructor because cases `27/28` call owner `ShowName()/HideName()` virtual slots; exact final public header type remains a confidence cap.
- Preserved and expanded rejected alternatives: LivingObjectPane caller owner, UID0001DD aggregate owner, Motion pool/free/unwind/destructor owner, vtable/raw table byte owner, split child for table bytes, and no-code disposition.

Callback target validator run completed with this command:

> Executable block R001 was removed from this report and preserved verbatim in [0002QW-MotionAnimationConstructor-source-quality-removed.md](0002QW-MotionAnimationConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated freshness was also inspected read-only after validation and is recorded in `Validator Results`.

## Recommended Support Doc Changes

Applied support changes:

- `by-class/Motion.md`: added UID0002QW source-readiness details beside the existing UID0002QX note, including current MCP session, one direct LivingObjectPane caller, `ShowName/HideName` owner-slot evidence, field-name reuse from UID0002QX/UID0002QY, and no local UDT confidence cap. No class score change was made.
- `by-file/Motion.md`: added a constructor-readiness paragraph that UID0002QW now emits primary constructor C++ through `NexusTK/render/Motion.cpp`, while UID0002QX remains the alternate constructor and non-Motion Region/Dialog/NewHumanImageLib exclusions remain intact. No file score change was made.
- `by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md`: updated wording that treated the primary constructor as an unresolved blank-C++ blocker. UID0001DD remains non-emitting and score unchanged because the exact child emits, not the container.
- `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md`: optional caller sync applied because the current page had the direct allocation/call route but lacked UID0002QW-specific caller-evidence context. The note ties `effect->Construct(...)` to the direct call to UID0002QW on pool-allocated Motion storage and preserves LivingObjectPane caller ownership. No formal caller C++ rewrite was made.

Every changed support doc was validated with:

> Executable block R002 was removed from this report and preserved verbatim in [0002QW-MotionAnimationConstructor-source-quality-removed.md](0002QW-MotionAnimationConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Score And Metadata Recommendation

Applied target metadata: `COMPLETION:90`, `CONFIDENCE:92`.

Why higher than prior `86/89`: current MCP evidence resolves the exact range, trailing table relationship, sole direct caller, source owner, vtable writes, field layout, config gate, pointer negatives, and formal C++ eligibility. The target is no longer an empty emitter marker.

Why not higher than `90/92`: there is no local IDA `Motion` UDT, exact original header type for the owner parameter remains inferred (`LivingObjectPane *` is best for primary constructor but not proven as the final declaration type), enum names for motion types/actions are not recovered, and exact final member spellings remain first-draft even though they are consistent with sibling docs.

Support score changes: none applied. Motion class/file and the parent cluster already clear the ownership route; they needed context notes, not score movement.

## Open Questions With Attempted Resolution

- Is UID0002QW source code or compiler glue? Resolved: source-authored constructor logic. It has normal constructor body, field initialization, switches, virtual calls, and a direct caller. EH/security-cookie pieces are compiler support and remain prose-only.
- Is `0x00539d43-0x00539de0` a child target? Resolved no. MCP bytes/xrefs show constructor-local jump tables and padding, with successor function at `0x00539de0`.
- Should owner be LivingObjectPane or Motion? Resolved: Motion owns the constructor; LivingObjectPane is the caller/owner-object type passed into Motion.
- Should the first parameter be `ObjectPane *` or `LivingObjectPane *`? Best current recommendation is `LivingObjectPane *` for UID0002QW because this primary constructor calls owner slots that support docs identify as `ShowName`/`HideName`. Confidence is capped because the final header type is not recovered.
- Are sound constants names recoverable? Not yet. Numeric sound/effect IDs are durable, but source enum names are not recovered in current docs or MCP evidence.
- Does `g_pConfig + 0x28de71` have a source name? Resolved sufficiently as `g_pConfig->m_motionType16SoundEnabled` from UID00028Q/UID0002QX, reused here.
- Do support docs need score changes? No. They need Rule 26 context sync only if edited.

## Validator Results

Callback validators run from `source-3/project-documentation`; all exited `0` with `ok: 1`.

- Target command: `python .\tools\validator.py --mode file --file by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000007586`
  - `command_timestamp: 2026-07-06T13:33:39-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Notable validator-owned side effects: `completion_update 0002QW 90`, `confidence_update 0002QW 92`, `autogen_registry_update`, UID link inserts for `00008R`, `0001DD`, and `000356`, `autogen_cpp_update 0000LL auto-generated/NexusTK/render/Motion.cpp`, `research_tracker_update`, `memory_auto_coverage_update`, projected stats update, and `validator.ini` registry rebuild. Warnings/noise were unrelated existing `autogen_children_*` and `autogen_emitter_has_no_code` rows.
  - `generated_refresh: completed`, `generated_refresh_command_id: 000000007586`, `generated_refresh_timestamp: 2026-07-06T13:33:39-04:00`.
- Support command: `python .\tools\validator.py --mode file --file by-class/Motion.md --apply --queue-timeout 240`
  - `command_id: 000000007587`
  - `command_timestamp: 2026-07-06T13:33:57-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Side effects: stats row/projected stats updates for UID00008R; `generated_refresh: deferred`.
- Support command: `python .\tools\validator.py --mode file --file by-file/Motion.md --apply --queue-timeout 240`
  - `command_id: 000000007588`
  - `command_timestamp: 2026-07-06T13:34:03-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Side effects: projected stats update; `generated_refresh: deferred`.
- Support command: `python .\tools\validator.py --mode file --file by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md --apply --queue-timeout 240`
  - `command_id: 000000007589`
  - `command_timestamp: 2026-07-06T13:34:12-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Side effects: projected stats update; `generated_refresh: deferred`.
- Optional caller-support command: `python .\tools\validator.py --mode file --file by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md --apply --queue-timeout 240`
  - `command_id: 000000007590`
  - `command_timestamp: 2026-07-06T13:34:19-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Side effects: validator inserted the missing blank header separator, refreshed UID0003Z5 metadata/registry values, added reference-index entries for `00007B`, `0001DE`, `0001DF`, and `0002QW`, projected stats update; `generated_refresh: deferred`.
  - Warnings: two existing `missing_ref_uid 0003UD` references are not present in `validator.ini`; not introduced as a target failure for UID0002QW.

Generated freshness: read-only check of `auto-generated/NexusTK/render/Motion.cpp` after validation shows header `validator-command-id: 000000007588`, `validator-refreshed-at: 2026-07-06T13:34:03-04:00`, and `validator-refresh-source: deferred-generated-refresh`. UID0002QW is present at generated lines 7-8 with `Completion:90 | Confidence:92` and non-empty `Motion::Motion(LivingObjectPane *owner, int motionType, int timerDelay, char soundOverride)` code. This header is newer than the target validator command `000000007586` because the later by-file support validator refreshed the same generated file.

No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, registry lifecycle command, manual report move, or generated/coverage/manual validator-state edit was run by B003.

## Changed Files

Manual by-* files edited under B003 leases:

- `by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md`
- `by-class/Motion.md`
- `by-file/Motion.md`
- `by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md`
- `by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md`
- `tools/leaser/Agents/Agent-B003/research/0002QW-MotionAnimationConstructor-source-quality.md`

Validator-owned side effects observed and not manually edited:

- `auto-generated/NexusTK/render/Motion.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`

Leases: acquired successfully at callback start for all five by-* docs listed above using `python .\leaser.py B003 lease ...`; released successfully after the validator batch using `python .\leaser.py B003 unlease ...`. Final `tools/leaser/Agents/Agent-B003/current_leases.md` read shows `No active leases.`

## Implementation Tracking Checklist

- [x] C-0002QW-01: Target records exact `0x00539bc0-0x00539d43` / size `0x183` body and `0x00539d43` not-a-function evidence; validator `000000007586` passed.
- [x] C-0002QW-02: Target and UID0001DD parent prose record `0x00539d43-0x00539de0` as constructor-local switch tables and padding, not a split child; validators `000000007586` and `000000007589` passed.
- [x] C-0002QW-03: Target caller/reachability prose and optional UID0003Z5 support note record the `0x0053b5f9` sole direct caller and Motion pool allocation/schedule route; validators `000000007586` and `000000007590` passed.
- [x] C-0002QW-04: Target/support preserve Motion class/file ownership and reject aggregate/caller/pool/vtable owner alternatives; target/class/file/parent/caller validators passed.
- [x] C-0002QW-05: Target preserves `CANONICAL_OWNER:00008R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008R`, blank optional emitter position, and `Nested:4`.
- [x] C-0002QW-06: Target metadata changed to `COMPLETION:90`, `CONFIDENCE:92`; validator `000000007586` reported both metadata updates and `ok: 1`.
- [x] C-0002QW-07: Target formal C++ block contains the first-draft `Motion::Motion(LivingObjectPane *owner, int motionType, int timerDelay, char soundOverride)` body from this report.
- [x] C-0002QW-08: Target documents cases `27/28` as owner `ShowName()` / `HideName()` calls via `+0x74/+0x78`; Motion class/file notes also include the caveat.
- [x] C-0002QW-09: Target formal C++/prose preserves the sound/effect mapping and config-gated type `16` behavior.
- [x] C-0002QW-10: Target Item Summary historicalizes/removes stale unassigned-score language.
- [x] C-0002QW-11: Support docs received UID0002QW source-readiness context with no support score change; optional caller note added because UID0003Z5 previously lacked direct UID0002QW caller-evidence context.
- [x] C-0002QW-12: Target validator ran with generated refresh; generated `Motion.cpp` now has non-empty UID0002QW output, current observed header `000000007588` / `2026-07-06T13:34:03-04:00`.
- [x] C-0002QW-13: Rejected alternatives are explicitly represented in target/support prose.
- [x] C-0002QW-14: Scoped validator command metadata is recorded above; no lifecycle/archive/execute command was run by B003.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000007593","destination_path":"executed-b-agent-research/B003/0002QW-MotionAnimationConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002QW-MotionAnimationConstructor-source-quality.md","timestamp":"2026-07-06T13:46:46-04:00","uid":"0002QW"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002QW-MotionAnimationConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002QW-MotionAnimationConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002QW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
