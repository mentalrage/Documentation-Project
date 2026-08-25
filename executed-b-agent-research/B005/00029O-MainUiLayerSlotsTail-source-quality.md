** TARGET-REPORT-UID:00029O **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00029O MainUiLayerSlotsTail Source-Quality Research


## Finalized Report / Current Recommendation

- Current implemented state: UID00029O is a `92/94`, owner-none, false/non-emitting split parent over exact physical children UID0004VH `[0x0069b378,0x0069b37c)` and UID0004VI `[0x0069b37c,0x0069b380)`. Sole semantic `Layer *` globals UID0004VF `g_pStatusPaneLayer` and UID0004VG `g_pIMEPaneLayer` emit from `NexusTK/ui/MainUiGraph.cpp`.
- Final disposition: the six-field `g_mainUiLayerSlots` story is rejected across the proven `0x0069b370` loader-zero/no-ref separator. The contiguous head triplet remains under UID0000T6, while UID0001PG and both target dwords are independent physical backing for UID0004VE `g_pLayoutPaneLayer`, UID0004VF `g_pStatusPaneLayer`, and UID0004VG `g_pIMEPaneLayer`.
- Callback completion: all five pages were serially registered with validator-issued UIDs before cross-linking; all brace tokens were replaced; Destinations 1-16 match the accepted blocks byte-for-byte; 50 ordinary pages were scoped-validated; final waited refresh command `000000016097` completed with zero B005 leases.
- Confidence: very strong for bytes, ranges, pointer type, independent-global shape, lifecycle, xrefs, source route, and source bodies; strong rather than symbol-exact for the three source-facing global spellings.

## Supporting Research

- Assignment source: canonical `tools/leaser/Agents/Agent-B005/goal.md`, UID00029O direct report-only research.
- Mandatory MCP evidence was collected through the healthy direct HTTP MCP endpoint. Fresh `idb_list` selected active/adopted database `9b0396a3`; `server_health(database=9b0396a3)` returned `status:ok`, image base `0x00400000`, and ready auto-analysis, Hex-Rays, and string cache.
- One initial HTTP helper attempt serialized tool arguments as a list and omitted `database`; the server correctly returned schema/database errors. This was a client-payload error, not MCP downtime. A corrected bounded pass immediately succeeded for `idb_list`, `server_health`, `get_bytes`, `xref_query`, `lookup_funcs`, `decompile`, `disasm`, and global-name checks.
- Independent PE evidence used `E:/NTK/Resources/NexusTK/NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`. `.data` spans virtual addresses `0x0066d000-0x0069ce24`, while raw-backed bytes end at `0x0067a800`; UID00029O is loader-created zero-fill, not raw `0xffffffff` data.
- Exact old-report search terms: `00029O`, `0x0069b378`, `0x0069b37c`, `MainUiLayerSlotsTail`, `statusPaneLayerContext`, `fpsOverlayLayerContext`, `dword_69B378`, and `dword_69B37C`. Broader owner/file/source-family terms also checked were `MainUiLayerSlots`, `MainUiGraph`, `ApplicationStartup`, and `ApplicationShutdown`.
- Search roots actually checked: central `executed-b-agent-research/**`; active `tools/leaser/Agents/Agent-B*/research/**`; legacy `archived/b-agent-reports-20260623/**/research/**`; and `tools/leaser/Agents/Older-Research/**`. The active and both legacy roots had no exact narrow-term report match.
- Every exact narrow-term executed match was opened:

| Matching report | Classification and current finding |
| --- | --- |
| `executed-b-agent-research/B001/0001PG-g_layoutContext_69B374-memory-range-report.md` | Incidental adjacent support. Its live zero-fill/13-ref/boundary proof remains useful; its emitting aggregate-field conclusion is superseded by this direct source-shape pass. |
| `executed-b-agent-research/B002/0001G7-ScreenCursorHelpers-source-quality.md` | Incidental startup formal provenance. Preserves lifecycle order; old tail field names are superseded. |
| `executed-b-agent-research/B002/00029L-StartupClearedUnusedDwords-source-quality.md` | Incidental neighborhood support. Confirms virtual-tail zero-fill and separation from active slots. |
| `executed-b-agent-research/B002/0002AF-g_pMainUiGraph-source-quality.md` | Incidental lifecycle/source-route support. Its current MainMenuPane de-ownership is preserved; old aggregate tail expressions are superseded. |
| `executed-b-agent-research/B003/00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality.md` | Incidental second-slot consumer evidence. Its warning that the Fps name was descriptive is confirmed; `g_pIMEPaneLayer` supersedes that alias. |
| `executed-b-agent-research/B003/00015J-FpsPaneWriteLogSummaryRaw-source-quality.md` | Incidental negative support. Confirms sibling summary logic does not consume or own the slot. |
| `executed-b-agent-research/B003/0001KB-TimerPane-source-quality.md` | Incidental first-slot constructor evidence. Confirms status-layer use and TimerPane ownership boundary. |
| `executed-b-agent-research/B004/000392-ScreenDimmerConstructor-source-quality.md` | Incidental first-slot direct consumer evidence. Constructor behavior/formal remains valid except the global expression. |
| `executed-b-agent-research/B007/0002H7-ApplicationStartup-source-quality.md` | Incidental lifecycle evidence. Exact allocation/store/register order remains valid; aggregate shape and tail spellings are superseded. |
| `executed-b-agent-research/B007/0004C1-IMECompositionPaneConstructor-source-quality.md` | Incidental second-slot source-body evidence. Confirms direct IME attachment. |
| `executed-b-agent-research/B008/00015F-FpsPaneUpdateFpsLogSessionRaw-source-quality.md` | Incidental second-slot source-body evidence. Confirms one Fps diagnostic reuse but no Fps ownership. |
| `executed-b-agent-research/B008/0002H8-ApplicationShutdown-empty-emitter-source-quality.md` | Incidental lifecycle evidence. Exact detach/delete/clear order remains valid; tail expressions are superseded. |
| `executed-b-agent-research/B008/0004CA-IMEPaneConstructor-by-memory-source-quality.md` | Incidental IME family/source route evidence. No direct target declaration proof. |
| `executed-b-agent-research/B009/0004C7-IMECandidatePaneConstructor-source-quality.md` | Incidental second-slot consumer evidence. Confirms candidate constructor and root inline-equivalent use. |
| `executed-b-agent-research/B010/0004CE-IMEPaneHandleIMEMessage-source-quality.md` | Incidental second-slot root-dispatch evidence. Confirms two inline IME constructions. |
| `executed-b-agent-research/B011/00019K-InitializeMainUiGraph-source-quality.md` | Incidental owner/file vocabulary evidence. Its declaration-shape cap is resolved for layout/tail, not for the head triplet. |
| `executed-b-agent-research/B011/00019K-InitializeMainUiGraph-source-quality-2.md` | Historical superseded broad no-code analysis. Useful only as evidence that all six prior names were inferred. |
| `executed-b-agent-research/B011/0004BX-IMEStatusPaneConstructor-source-quality.md` | Incidental second-slot constructor evidence. Confirms direct layer attachment and rejects root-singleton ownership. |

- Evidence-based old-report conclusion: no prior direct UID00029O/target-specific source-quality report exists. The 18 matches are adjacent, lifecycle, or consumer reports and therefore evidence leads only.

## Target

- Target UID: `00029O`.
- Target path: `by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md`.
- Assignment-time queue origin: validator-owned `auto-generated/-ag-research-tracker.md`, by-memory reconstructable not-covered/empty-emitter family; later validator epochs reflect the implemented callback state.
- Current supervisor classification: accepted UID00029O implementation callback complete and awaiting independent Gate 2 review; report execution/archive remains supervisor-owned.
- Current scores and parent state: `92/94`, owner NONE, reconstructable false, blank emitter/position/formal C++, `Nested:0`; exact physical children are UID0004VH (`Nested:+4`) and UID0004VI (`Nested:0`), with successor UID0001PH closing the split at `Nested:-4`.

## Current Target State

- Current target SHA256 is `814132B794A9CC38D47C1D9612F310CFAAC0F1FE73EBC4DB19D438970192AE3C`. It records the exact zero-fill split, complete 14/11 refs, lifecycle, source routes, semantic/physical ownership, rejected aliases, and blank no-code parent disposition; historical all-ff/aggregate wording is explicitly superseded.
- Fresh IDB bytes and independent PE section mapping remain the evidence-time authority for eight loader-zero bytes; the callback changed documentation/source reconstruction only and did not mutate IDA.
- Exact boundaries are four-byte aligned: status storage `[0x0069b378,0x0069b37c)` and IME storage `[0x0069b37c,0x0069b380)`. Predecessor UID0001PG ends at `0x0069b378`; successor UID0001PH starts at `0x0069b380`.
- The unused `0x0069b370-0x0069b374` dword has zero refs and is skipped by startup/shutdown. It disproves a source-complete seven-dword struct spanning head/layout/tail without requiring a forbidden unknown/reserved member.
- Generated `MainUiGraph.cpp` refreshed by callback command `000000016097` has exactly one definition each for UID0004VE/0004VF/0004VG, no UID0001PG/UID00029O/UID0004VH/UID0004VI marker, and only the separately retained UID0000T6/UID00029M head markers. Commands `000000015789` and `000000015821` are historical pre-callback provenance.
- Current report lifecycle: B005 implementation and validation responsibilities are complete. Manual coverage application and report execution/archive remain external supervisor-owned lifecycle state; no execute_report, lifecycle, move, or archive command was run by B005.

## Executive Recommendation

- Preserve UID00029O as the address-container parent, but make it false/non-emitting and split it into two exact physical children.
- Create semantic globals `g_pStatusPaneLayer` and `g_pIMEPaneLayer`, both `Layer *`, externally linked, zero-initialized, owned/emitted by UID0000L1 `MainUiGraph` at positions 50 and 60.
- Convert UID0001PG to physical backing for a third independent `Layer *` global, `g_pLayoutPaneLayer`, position 40. This resolves the declaration boundary created by the no-ref gap and removes the stale Browser-only alias as a source candidate.
- Keep UID0000T6 and UID00029M as the provisional contiguous head-triplet support family. Do not invent head members or rewrite 196 head-slot consumer refs in this tail audit.
- The callback rebased every accepted source body that used a tail alias. Prose-only consumers with blank broader bodies received exact address/name/type evidence without inventing incomplete C++.

## Supervisor Active Recheck

- The supervisor accepted exact pre-callback SHA `936A894C62CED636D58AA77E95046E193D73A0EBB0B392BD4755772D79D69418` and authorized this implementation callback.
- Split repair, real UID registration, source-global definitions, lifecycle/consumer expression updates, support synchronization, scoped validation, and waited generated verification were completed as recorded below.
- Every source-bearing destination has its accepted managed C++; every non-source physical page has destination-specific blank-formal proof. No target/layout physical slot remains an emitting blank.

## Inference Research Guidance Check

- `by-structure.md` split-first and `Nested` delta rules were applied: `Nested` is a cumulative relative delta, not a child count.
- Existing field names, aggregate membership, ff initialization, and Fps ownership were treated as hypotheses. Binary facts, current docs, generated source, and inference are separated throughout.
- Direct facts: bytes, PE mapping, xrefs, function bounds, startup/shutdown instructions, constructor type, allocation size, and consumer operands.
- Inference: source spellings and the exact human header organization. The selected names follow current project `g_p<TypeOrRole>` vocabulary and complete consumer-family evidence.
- Wave2/Wave3 references found in older provenance were ignored as stale. No Wave artifact is used as evidence.

## Heuristic / Inference Reanalysis And Validation

1. **Static bytes.** Fresh MCP returns 32 zero bytes across `0x0069b364-0x0069b383`; PE raw mapping independently proves the region is virtual-tail zero-fill. Active ff wording is rejected.
2. **Element type.** Startup performs six 8-byte allocations, calls UID0004NR `Layer::Layer()`, stores each pointer, and passes each to ScreenPane. Current UID000073 defines an 8-byte `Layer`. Exact type is `Layer *`, not `Pane *`, opaque context, list, or object-by-value.
3. **Aggregate shape.** A six-field `g_mainUiLayerSlots` object cannot cross the skipped no-ref dword without an unsupported source member. No IDB UDT/global symbol, base-pointer access, indexed loop, or object address route exists. Layout/status/IME cells are best modeled as independent globals.
4. **Head scope.** The head triplet is contiguous and has a separate accepted support model. This report does not assert whether those first three are one small struct or three globals; the target declaration and C++ no longer depend on that uncertainty.
5. **Layout name.** Thirteen refs partition into lifecycle, Browser layout/window mapping, and alert/dialog placement. `g_pLayoutPaneLayer` describes the union. Browser ownership and `g_pBrowserOverlayLayer` are rejected because non-Browser consumers and Application lifecycle own the storage.
6. **First tail name.** The 14 refs partition into six lifecycle refs and eight UI uses across HelpPane, HistoryViewingPane, ScreenDimmer, ScreenFadeOut, TimerPane, and two InputBlocker paths. `g_pStatusPaneLayer` preserves the strongest existing role vocabulary while avoiding a fake struct field.
7. **First tail alternatives.** `g_pModalPaneLayer` is too narrow because Help, History, Timer, and fade use it; `g_pTransientPaneLayer` is behaviorally possible but lacks project precedent; `g_pMainUiLayer` is too broad and conflicts with root/head semantics.
8. **Second tail name.** Five of six non-lifecycle refs are IME status/composition/candidate construction, including two root inline equivalents. `g_pIMEPaneLayer` is the strongest human role name.
9. **Second tail alternatives.** `g_pFpsPaneParentPane` and `fpsOverlayLayerContext` are rejected as one incidental diagnostics consumer naming shared storage. Generic top-layer names discard the dominant IME evidence.
10. **Linkage/source route.** Consumers span Application, login/history, UI/core, map, input, diagnostics, Help, and UserPane translation units. External linkage is required. MainUiGraph.cpp is the existing shared UI-layer source root; no consumer class owns publication or destruction.
11. **Initialization/destruction.** Human source is zero-initialized module definitions, explicit `new Layer` in startup, ScreenPane registration, detach, `delete`, and explicit null stores in shutdown. Compiler vptr/destructor lowering is not handwritten.
12. **Header contract.** The managed by-global blocks intentionally contain a local forward declaration and one module definition only. Shared-header `extern` declarations are a separate declaration-placement contract documented on MainUiGraph/Application support, not duplicate `.cpp` definitions.
13. **Fps raw body.** IDA does not model `0x004b64a0` as a function, but bounded disassembly at `0x004b65ff` proves the slot push into the inherited frame-rect call. Existing source liveness/body evidence remains unchanged; only the dependency name changes.
14. **Generated pollution.** At report-only evidence time, target/layout/aggregate aliases produced empty markers or undefined source names. The applied destinations removed target/layout markers and raw/decompiler aliases without introducing addresses, `dword_*`, fake fields, or compiler mechanics.

## Evidence Standards Used

- Highest weight: fresh MCP bytes/xrefs/function identities/disassembly/decompilation and independent PE section mapping.
- Corroboration: current by-memory/by-global/by-class/by-file pages, current generated C++, current tracker/manual rows, exact executed reports, and current Layer class/constructor source.
- Inference ladder: direct storage/type/lifecycle facts first; complete consumer-family clustering second; project naming/source-route conventions third; lexical confidence capped below symbol certainty.
- Negative evidence is used only after positive controls: exact adjacent active xref counts matched both IDA and raw absolute-VA scans, so the gap's zero-ref result is meaningful.

## Evidence Checked

- MCP `idb_list`, `server_health`, `get_bytes(0x0069b364,32)`, exact `xref_query` for `0x0069b370/378/37c/380`, `lookup_funcs` for all consumer/lifecycle entries, decompile of Help/History/ScreenDimmer/ScreenFadeOut/Timer/root IME, and bounded disassembly of Fps and both UserPane InputBlocker uses.
- Independent raw PE absolute-VA scan matched exact counts `35/60/101/0/13/14/11/13` for `0x0069b364/368/36c/370/374/378/37c/380`.
- Current target, head, gap, layout, successor, MainUiLayerSlots, MainUiGraph, Application startup/shutdown, InitializeMainUiGraph, Layer class/constructor, every direct consumer page, relevant class/file pages, generated sources, tracker, and manual coverage were read.
- Exact old-report searches and every narrow-term matching report are recorded under Supporting Research.
- Negative checks: no IDB global symbol at `*69B37*`; no MainUi UDT; no target raw initializer; no base object pointer/index loop; no ref to the gap; no second target storage; no consumer publication/clear; no target-owned RTTI/vtable; no hidden Fps ownership.
- Evidence-time research used no IDA mutation or broad expensive search. The later authorized callback ran only the scoped validators and final waited generated refresh recorded under Validator Results; no manual generated or coverage edit occurred.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00029O is exact `[0x0069b378,0x0069b380)` and currently eight zero bytes. | 99% | MCP bytes; PE map/hash | D1/target | incorporate | applied |
| C02 | The bytes are loader-zero `.data` virtual-tail storage, not raw ff initialization. | 99% | section raw/virtual bounds | target/head/gap/layout/successor | reject-stale | applied |
| C03 | UID00029O must split into two four-byte physical children. | 99% | boundaries/xref partition | D1-D3 | incorporate | applied |
| C04 | `[378,37c)` is physical backing only for `g_pStatusPaneLayer`. | 98% | 14 refs/type/one-definition | D2/D6 | incorporate | applied |
| C05 | `[37c,380)` is physical backing only for `g_pIMEPaneLayer`. | 98% | 11 refs/type/one-definition | D3/D7 | incorporate | applied |
| C06 | The no-ref `0x69b370` gap disproves one source-complete six-slot aggregate across the range. | 98% | zero refs/raw scan/lifecycle skip | target/UID0T6 | reject-invalid | applied |
| C07 | First slot has exactly 14 refs at the recorded addresses. | 99% | MCP xref_query | target/status child/global | incorporate | applied |
| C08 | First slot startup store/register is `0x4f62f5`/`0x4f6365` operand and call `0x4f636d`. | 99% | disasm/xrefs | D8/support | incorporate | applied |
| C09 | First slot shutdown detach/load/delete/clear is exact and source is delete plus null store. | 99% | disasm/decompile | D9/support | incorporate | applied |
| C10 | First-slot consumers are Help, History, ScreenDimmer, FadeOut, Timer, and two InputBlocker paths. | 99% | complete xrefs/decompile | target/support prose | incorporate | applied |
| C11 | `Layer *g_pStatusPaneLayer` is the best source declaration. | 94% | ctor/type/consumer union/style | D6/D8-D12 | incorporate | applied |
| C12 | Modal/transient/main-ui alternatives are weaker for the first slot. | 92% | consumer counterexamples | target/global history | reject-invalid | applied |
| C13 | Second slot has exactly 11 refs at the recorded addresses. | 99% | MCP xref_query | target/IME child/global | incorporate | applied |
| C14 | Second-slot lifecycle store/register/detach/delete/clear is exact. | 99% | disasm/xrefs | D8/D9 | incorporate | applied |
| C15 | Five of six second-slot consumer refs are IME construction; Fps is incidental. | 99% | complete xrefs/root decompile | D7/D13-D16 | incorporate | applied |
| C16 | `Layer *g_pIMEPaneLayer` is the best source declaration. | 96% | dominant family/type/style | D7/D8-D16 | incorporate | applied |
| C17 | `fpsOverlayLayerContext` and `g_pFpsPaneParentPane` are consumer-biased stale names. | 98% | complete consumer partition | target/Fps/UID0T6 | reject-stale | applied |
| C18 | UID0001PG is physical backing for independent `g_pLayoutPaneLayer`. | 96% | gap/13 refs/lifecycle | D4/D5 | incorporate | applied |
| C19 | Browser alias ownership is rejected; layout is shared Browser/alert UI state. | 98% | 13-ref partition | UID1PG/UID0QD/MainUiGraph | reject-stale | applied |
| C20 | UID00029M remains a separate head-triplet support page; its ff bytes are stale. | 99% bytes; scoped source | MCP/PE/current docs | UID29M/UID0T6 | historicalize | applied |
| C21 | UID0000T6 must stop claiming layout/tail as struct fields and become head-triplet support only. | 96% | gap/source-shape proof | UID0T6/MainUiGraph | incorporate | applied |
| C22 | Target parent and physical children emit no C++; semantic globals are sole definitions. | 99% | one-definition policy | D1-D7 | incorporate | applied |
| C23 | MainUiGraph.cpp owns the three definitions at positions 40/50/60. | 96% | source route/cross-module use | D5-D7/UID0L1 | incorporate | applied |
| C24 | Header externs are separate declaration placement; no duplicate extern+definition block is emitted. | 99% | project source policy | globals/file support | incorporate | applied |
| C25 | Application::Startup must use three independent globals while preserving exact order. | 99% | binary/current body | D8 | incorporate | applied |
| C26 | Application::Shutdown must use three independent globals while preserving detach/delete order. | 99% | binary/current body | D9 | incorporate | applied |
| C27 | History constructor's `g_pMainUiLayer` is the first target slot and must become `g_pStatusPaneLayer`. | 99% | xref/decompile | D10 | reject-stale | applied |
| C28 | ScreenDimmer constructor's three first-slot uses become `g_pStatusPaneLayer`. | 99% | xrefs/body | D11 | incorporate | applied |
| C29 | TimerPane constructor's first-slot use becomes `g_pStatusPaneLayer`. | 99% | xref/body | D12 | incorporate | applied |
| C30 | Three IME constructors use `g_pIMEPaneLayer`; root inline equivalents receive prose sync. | 99% | xrefs/decompile | D13-D15/support | incorporate | applied |
| C31 | FpsPane body uses `g_pIMEPaneLayer` without gaining ownership. | 98% | bounded disasm | D16/support | incorporate | applied |
| C32 | Blank Help/Fade/UserPane bodies receive address/name/type evidence only, not invented C++. | 99% | current formals/scope | support prose | incorporate | applied |
| C33 | Nesting is parent 0, status child +4, IME child 0, successor UID0001PH -4. | 99% | validator sort/delta rule | target/children/successor | incorporate | applied |
| C34 | UID00029N is loader-zero no-ref residue, not initialized ff or a seventh slot. | 99% | MCP/PE/raw scan | UID29N/manual | reject-stale | applied |
| C35 | UID0001PH starts at `0x69b380`, has 13 refs, loader-zero start, and closes the split nesting. | 99% | xrefs/PE/boundary | UID1PH/manual | incorporate | applied |
| C36 | Scores rise only for target, new physical/semantic pages, UID1PG, UID29N, and MainUiGraph file. | 94% | blocker audit | score table | incorporate | applied |
| C37 | Generated target goal is three sole definitions, no target/layout physical markers, and exact consumer names. | 99% | current generated/readback plan | generated assertions | incorporate | applied |
| C38 | Manual rows are stale/absent and require the exact supervisor-owned handoff below. | 99% | current manual comparison | coverage section | incorporate | applied |
| C39 | No direct prior target report exists; all 18 matches are incidental evidence. | 99% | exact root searches | Supporting Research | incorporate | applied |
| C40 | Raw/decompiler labels, opaque contexts, fake gap fields, compiler lowering, and IDA mutation are excluded. | 99% | source-quality policy/evidence | all destinations | reject-invalid | applied |

### Callback Verification Notes

| Claim | Terminal proof |
| --- | --- |
| Proof C01 | UID00029O current hash `814132B7...AE3C`; D1 exact; command 16088 and waited 16097 both exit 0/ok1. |
| Proof C02 | UID00029O, UID00029M, UID00029N, UID0001PG, UID0001PH, and UID0000T6 now state loader-zero current truth and label ff wording historical; commands 16088/16011/16012/16009/16014/16025. |
| Proof C03 | Real children UID0004VH and UID0004VI occupy the exact half-open ranges and were registered serially by commands 16004/16005 before cross-linking. |
| Proof C04 | UID0004VH hash `31310231...05DD` is false physical backing owned by semantic UID0004VF; D2/D6 exact. |
| Proof C05 | UID0004VI hash `6BCE5F2C...7F16` is false physical backing owned by semantic UID0004VG; D3/D7 exact. |
| Proof C06 | UID0000T6 command 16025 narrows active scope to the head triplet; target/gap/layout pages preserve no-ref-gap rejection without a fake member. |
| Proof C07 | UID00029O, UID0004VH, and UID0004VF preserve all 14 first-slot refs and exact consumer partition. |
| Proof C08 | D8 exact; startup command 16027 preserves store/register order and uses `g_pStatusPaneLayer`. |
| Proof C09 | D9 exact; shutdown command 16029 preserves detach/delete/null-store order. |
| Proof C10 | Help, History, ScreenDimmer/Fade, Timer, and both UserPane paths were synchronized and scoped-validated by commands 16074-16081 plus 16031/16033/16034/16077. |
| Proof C11 | UID0004VF D6 exact and generated MainUiGraph.cpp command 16097 contains the sole `Layer *g_pStatusPaneLayer = 0;` definition. |
| Proof C12 | UID0004VF/UID0004VH/UID00029O retain modal/transient/main-ui alternatives as rejected history. |
| Proof C13 | UID00029O, UID0004VI, and UID0004VG preserve all 11 second-slot refs and exact consumer partition. |
| Proof C14 | D8/D9 exact; commands 16027/16029 and generated Application.cpp command 16097 preserve lifecycle order. |
| Proof C15 | IME constructor commands 16036/16038/16040 and Fps command 16041 preserve the five-to-one IME/Fps partition. |
| Proof C16 | UID0004VG D7 exact and generated MainUiGraph.cpp command 16097 contains the sole `Layer *g_pIMEPaneLayer = 0;` definition. |
| Proof C17 | Target, UID0004VI/UID0004VG, Fps method/class/file, UID0000T6, IME classes/file/aggregate historicalize the two consumer-biased names. |
| Proof C18 | UID0001PG command 16009 converts the exact physical cell; UID0004VE command 16001 supplies the semantic definition. |
| Proof C19 | UID0000QD command 16082 and Browser support commands 16083-16087 preserve Browser facts while marking the alias false/non-emitting. |
| Proof C20 | UID00029M command 16011 and UID0000T6 command 16025 retain all head evidence while historicalizing ff/tail membership. |
| Proof C21 | UID0000T6 hash `C85F385A...1635` is head-only, score/formal unchanged, with independent global cross-links. |
| Proof C22 | D1-D7 match 7/7; generated MainUiGraph.cpp has no UID0001PG/00029O/0004VH/0004VI marker and exactly three semantic definitions. |
| Proof C23 | UID0000L1 command 16043 raises only to 90/92 and records positions 40/50/60; D5-D7 exact. |
| Proof C24 | Each D5-D7 block has a local forward declaration and sole module definition; MainUiGraph/Application support records separate header extern placement. |
| Proof C25 | D8 matches byte-for-byte; generated Application.cpp has five textual uses per independent global and zero old tail field spellings. |
| Proof C26 | D9 matches byte-for-byte; generated Application.cpp preserves six detach/delete/clear lifecycle groups and zero old tail field spellings. |
| Proof C27 | D10 exact; command 16031 and generated HistoryViewingPane.cpp use `g_pStatusPaneLayer` once and label `g_pMainUiLayer` superseded. |
| Proof C28 | D11 exact after command 16089; generated ScreenDimmer.cpp uses `g_pStatusPaneLayer` exactly three times. |
| Proof C29 | D12 exact; command 16034 and generated TimerPane.cpp use `g_pStatusPaneLayer` exactly once. |
| Proof C30 | D13-D15 exact; commands 16036/16038/16040 plus class/file/aggregate commands 16060/16062/16064/16067/16095 preserve complete IME detail. |
| Proof C31 | D16 exact; command 16041 and generated FpsPane.cpp use `g_pIMEPaneLayer` exactly once; class/file commands 16072/16073 deny ownership transfer. |
| Proof C32 | Help/Fade/UserPane changes are prose-only under commands 16074-16081; their broad/blank formals and scores remain unchanged. |
| Proof C33 | UID00029O/UID0004VH/UID0004VI/UID0001PH read back `Nested:0/+4/0/-4`; no provisional token remains. |
| Proof C34 | UID00029N command 16012 yields `92/94`, false/NONE, blank formal, loader-zero/no-ref/no-source disposition. |
| Proof C35 | UID0001PH command 16014 preserves range/13 refs/owner/formal and applies only loader-zero closure prose plus `Nested:-4`. |
| Proof C36 | Readback confirms raises only on UID00029O, UID0004VH/VI, UID0001PG, UID0004VE/VF/VG, UID00029N, and UID0000L1; support scores/routes remain unchanged. |
| Proof C37 | Waited command 16097 generated the exact three definitions, zero target/layout physical markers, 1/3/1 status uses, 3 IME uses, and 1 incidental FPS use. |
| Proof C38 | At the evidence-time B003-root reread recorded below, all ten existing B005-scope rows were compared line-for-line and remained unchanged in substance, while UID0004VE/VF/VG/VH/VI remained absent. The exact eleven-action handoff preserves every row-specific provenance, boundary, caller/liveness, split-inventory, handoff-count, layout/resource/session, and historical-disposition fact at same-or-greater detail; the supervisor will recheck those rows immediately before application rather than treating a mutable whole-root hash as durable authority. |
| Proof C39 | Supporting Research still records every root, term, opened match, classification, and the no-direct-report conclusion. |
| Proof C40 | Formal parity is 16/16; generated affected bodies contain no raw `dword_69B37*`, address, cookie, vptr, or decompiler label introduced by this callback; IDA was not mutated. |

## Positive Evidence Summary

- Exact bytes, raw-section mapping, xref totals, boundaries, Layer construction, allocation size, registration, teardown, and consumer operands all agree.
- The no-ref gap is a positive source-boundary discriminator because adjacent active cells reproduce exact expected counts in IDA and the PE scan.
- The first target cell has a coherent transient/status/system-overlay consumer union; the second has a dominant IME union.
- MainUiGraph.cpp is the established shared UI-layer source route, while Application owns runtime creation/destruction and consumers only read the globals.
- The selected C++ preserves binary behavior without raw addresses, decompiler labels, fake members, or ABI lowering.

## IDA MCP Facts

- Active database: `9b0396a3`; status ok; image base `0x400000`; analysis/Hex-Rays/strings ready.
- Bytes: 32 zeros at `0x0069b364`; target 8-byte SHA256 `AF5570F5A1810B7AF78CAF4BC70A660F0DF51E42BAF91D4DE5B2328DE0E83DFC`; each four-byte zero cell SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Function identities: Help `0x4c6960` size `0x44c`; History `0x4ffd80` size `0x149`; ScreenDimmer `0x559b90` size `0x156`; ScreenFadeOut `0x559e50` size `0x10e`; Timer `0x5986e0` size `0x162`; User dispatcher `0x5a76c0` size `0xbfd`; InputBlocker helper `0x5abc70` size `0x129`; IME constructors/root `0x4e71c0/0x4e7380/0x4e7b70/0x4e81b0`; startup/shutdown `0x4f5fb0` size `0x4e0` and `0x4f6490` size `0x215`; Layer ctor `0x4f0480` size `0x117`.
- `0x004b64a0` is not an IDA function, but bounded disassembly gives a coherent source-body interior and the exact `0x4b65ff` slot operand.
- No saved global name matching `*69B37*` and no MainUi UDT were returned.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069b364-0x0069b370` | UID00029M | head triplet support | true | UID0000T6 | `87/91` | preserve score; correct bytes/source scope |
| `0x0069b370-0x0069b374` | UID00029N | loader-zero no-ref residue | false | NONE | current `92/94` | no code |
| `0x0069b374-0x0069b378` | UID0001PG | layout physical backing | false | UID0004VE | current `92/94` | D4 |
| `0x0069b378-0x0069b380` | UID00029O | split parent | false | NONE | current `92/94` | D1 |
| `0x0069b378-0x0069b37c` | UID0004VH | status physical backing | false | UID0004VF | `92/94` | D2 |
| `0x0069b37c-0x0069b380` | UID0004VI | IME physical backing | false | UID0004VG | `92/94` | D3 |
| `0x0069b380-0x0069b381` | UID0001PH | active-dialog counter | true | UID0000XK | unchanged `88/91` | `Nested:-4` closure |
| semantic global | UID0004VE | `g_pLayoutPaneLayer` definition | true | UID0000L1 | `92/94` | D5 |
| semantic global | UID0004VF | `g_pStatusPaneLayer` definition | true | UID0000L1 | `92/94` | D6 |
| semantic global | UID0004VG | `g_pIMEPaneLayer` definition | true | UID0000L1 | `92/94` | D7 |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x4c6c5d` | HelpPane ctor | outer HelpPane attaches to status layer; nested text child uses head overlay slot separately |
| `0x4f62f5`, `0x4f6365` | Application startup | status pointer store and registration operand |
| `0x4f64c6`, `0x4f6550`, `0x4f6560` | Application shutdown | status detach, load/delete, clear |
| `0x4ffe73` | HistoryViewingPane ctor | full-screen history pane status-layer attachment |
| `0x559c3d`, `0x559c7e`, `0x559c9a` | ScreenDimmer ctor | initial attach and conditional rebinds to status layer |
| `0x559f2a` | ScreenFadeOut ctor | full-screen fade status-layer attachment |
| `0x5987c4` | TimerPane ctor | timer display status-layer attachment |
| `0x5a7d90`, `0x5abd49` | UserPane paths | InputBlockerPane status-layer attachment in dispatcher and helper |
| `0x4e724e` | IMEStatusPane ctor | IME layer attachment |
| `0x4e7416` | IMECompositionPane ctor | IME layer attachment |
| `0x4e7c2c` | IMECandidatePane ctor | IME layer attachment |
| `0x4e8281`, `0x4e8377` | IMEPane root dispatcher | inline-equivalent composition/candidate construction on IME layer |
| `0x4b65ff` | FpsPane raw body | diagnostic pane reuses IME layer as frame parent |
| `0x4f632c`, `0x4f6374` | Application startup | IME pointer store and registration operand |
| `0x4f6515`, `0x4f6536`, `0x4f6546` | Application shutdown | IME detach, load/delete, clear |

## Documentation Evidence And IDA Status

- Current Layer class/constructor pages are `92/94` and support exact `Layer *` typing and 8-byte allocation.
- UID0002H7/UID0002H8 bodies preserve runtime order and are source-ready; the callback replaced their three stale field expressions with the accepted independent-global expressions.
- UID000392, UID0004MG, UID0004BX, UID0004C1, UID0004C7, UID0001A1, and UID00015F contain the complete accepted current formals after exact substitution and scoped validation.
- HelpPane, ScreenFadeOut, and broad UserPane bodies are not reconstructed by this target. Their exact target operands are nevertheless decisive naming evidence and receive prose-level synchronization.
- At the terminal readback, affected generated source was independently observed at external validator command `000000016111`, refreshed `2026-07-21T17:30:34-04:00`: MainUiGraph `95AD468763260385EFE037F98BAC9F163981B0CEC1EC0974C0C848057B68F007`, 911 bytes/24 lines; Application `B96FA939BB91BE49FA4F47300502F0B61B6FAB6E215D4F25962414EE943B4012`, 34,869/896; HistoryViewingPane `E23BE4B03101FB380006B2210B0679277721EA07F80495CCE4E351D67B473550`, 3,015/105; ScreenDimmer `F7D2DB3095C56C15457518C502518CA6C247A0A0C691E0A0FD73F02786D4F280`, 2,228/59; TimerPane `7F17334835F872164AC25AC6DBAB2C0C7A3996C549538A115E68E912BB193E61`, 6,149/209; IMEPanes `7F4DB24C74633D924706A82040D9B197B3B3F23EFAD730FB1FBAAAFD66B42B2F`, 20,513/651; and FpsPane `EE077715FE5887BB18AD5B5149401BCE9783460ADB96CF1692D50D15D97B0442`, 6,468/190. These files retain the callback's exact three semantic definitions, two retained head markers, expected consumer counts, zero physical-parent/child markers, and zero old tail aliases/raw target labels.
- The terminal external tracker readback was command `000000016112`, refreshed `2026-07-21T17:33:07-04:00`, SHA256 `212078E964547C0D63F10FA07354D7B9B210A4D366732D1DA48A67201ED33A62`, 1,550,988 bytes/6,274 lines. Callback command `000000016097` remains implementation provenance. Commands `000000016108`, `000000016103`, `000000016100`, `000000015821`, `000000015806`, and `000000015789` and their recorded hashes remain historical external/evidence-time epochs, not frozen current authority; the command-15821 snapshot specifically documented the pre-callback empty-marker state that this callback superseded.

## Ranked Ownership Analysis

### 1. Independent MainUiGraph-owned semantic globals

- Evidence for: exact no-ref separator; absolute independent accesses; cross-module linkage; direct Layer construction; lifecycle owner in Application; consumer-family role clusters; current MainUiGraph source root.
- Evidence against: exact original symbol spellings are unavailable.
- Decision: accepted. Lexical uncertainty caps confidence but does not block source-clean C++.

### 2. One `MainUiLayerSlots` aggregate

- Evidence for: startup/shutdown handle the active pointers as a repeated family and old docs group them.
- Evidence against: source-complete layout requires an unknown gap member; no UDT/base/index route exists; the proposed six members are not contiguous.
- Decision: rejected for layout/tail. Retained only as provisional head-triplet documentation.

### 3. Consumer-owned globals

- Evidence for: Browser, Fps, IME, ScreenDimmer, Timer, and other consumers each expose role clues.
- Evidence against: no consumer allocates, publishes, clears, or uniquely consumes the storage; lifecycle and source route are shared.
- Decision: rejected. Consumer pages reference shared globals only.

### Proposed new file/grouping, if applicable

- Accepted and applied owner/name/path: UID0000L1 `MainUiGraph`, `NexusTK/ui/MainUiGraph.cpp`.
- Callback result: three sole externally linked zero-initialized `Layer *` definitions.
- Candidate related items retained: head triplet UID00029M/UID0000T6, no-ref gap UID00029N, active-dialog successor UID0001PH.
- Candidate related items rejected: Browser-owned alias, Fps-owned parent pointer, IME singleton ownership, ScreenDimmer/Timer ownership, one seven-dword struct.
- Source-file inference: narrow shared UI-layer globals, not a class/object module.

## Source Placement

- Definitions: `NexusTK/ui/MainUiGraph.cpp`, owner/emitter UID0000L1, positions 40/50/60 in address/role order.
- Runtime lifecycle: existing `NexusTK/app/Application.cpp` methods.
- Consumer methods retain current class/file routes: login History, UI core ScreenDimmer, map TimerPane, input IMEPanes, diagnostics FpsPane.
- Shared header declarations are documented as separate proper declaration placement and are not duplicated inside `.cpp` managed blocks.
- Rejected placements: Browser.cpp, FpsPane.cpp, IMEPanes.cpp, ScreenDimmer.cpp, TimerPane.cpp, HelpPanes.cpp, UserPane.cpp, Effects.cpp.

## Range / Split / Padding / Reclassification Analysis

- Parent UID00029O remains exact `[0x0069b378,0x0069b380)`, false/non-emitting, owner NONE, blank emitter/position/formal, `Nested:0`.
- Register semantic globals first in layout/status/IME order. Replace each global token immediately after validator issuance.
- Then create/register status child `[0x0069b378,0x0069b37c)` and IME child `[0x0069b37c,0x0069b380)` in address order. Replace each child token before the next cross-link.
- Cumulative nesting in validator sort order: UID00029O `0`; status child `+4`; IME child `0`; following UID0001PH `-4`.
- UID0001PG remains exact `[0x0069b374,0x0069b378)` but changes to false physical backing for the layout semantic global.
- UID00029N remains exact four-byte non-source residue. It is loader zero, not ff, and has no child/global owner.
- No padding is merged into any active global; no active slot is widened across the gap or successor.

## Negative Evidence Summary

- No raw target initializer, target-local RTTI/vtable, UDT, base-object route, array loop, structure offset route, or symbol proves an aggregate.
- No ref or pointer occurrence reaches the gap, while all active neighboring counts match positive controls.
- No consumer owns publication or teardown.
- No evidence supports `fpsOverlayLayerContext` as the shared role; Fps contributes one incidental ref.
- No evidence supports Browser ownership for layout or `g_pMainUiLayer` for the status slot.
- No human source requires raw addresses, `dword_*`, `unk_*`, fake reserved fields, manual vptrs, scalar-delete flags, or decompiler temporaries.

## IDA Rename / Type / Comment Recommendations

- Safe descriptive IDA names for a separate authorized curation pass: `g_pLayoutPaneLayer` at `0x0069b374`, `g_pStatusPaneLayer` at `0x0069b378`, and `g_pIMEPaneLayer` at `0x0069b37c`, each `Layer *`.
- Keep `0x0069b370` unnamed or comment it as loader-zero/no-ref residue.
- Preserve first-three-slot current names as documentation-only pending direct head research.
- Do not mutate IDA in this assignment; all recommendations are report/documentation-only.

## First-Draft C++ Recommendation

- Sixteen accepted destination blocks follow. They are the only applied C++/no-code formal changes and match their current destinations byte-for-byte. All C++ remains confined to exact managed-header blocks.
- No third-party import applies.

### Destination 1 - UID00029O split parent

```text
*** UID:00029O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Non-emitting split parent for two exact loader-zero Layer-pointer physical cells: status-layer backing at 0x0069b378 with 14 refs and IME-layer backing at 0x0069b37c with 11 refs; startup/register and shutdown/delete/clear lifecycle, independent semantic global definitions, exact boundaries/nesting, rejected six-field aggregate and Fps-owned alias, and blank parent no-code disposition are complete. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 2 - new status physical child

```text
*** UID:0004VH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0004VF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact loader-zero four-byte physical backing for g_pStatusPaneLayer with 14 direct refs: Application startup store/register, shutdown detach/delete/clear, and HelpPane, HistoryViewingPane, ScreenDimmer, ScreenFadeOut, TimerPane, and two InputBlocker consumers; sole semantic definition is external, physical source emission is intentionally blank, and modal/transient/main-ui alternatives remain rejected. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 3 - new IME physical child

```text
*** UID:0004VI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0004VG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact loader-zero four-byte physical backing for g_pIMEPaneLayer with 11 direct refs: Application startup store/register, shutdown detach/delete/clear, three exact IME constructors, two root-handler inline equivalents, and one incidental FpsPane diagnostic reuse; sole semantic definition is external, physical source emission is blank, and fpsOverlay/Fps-owned names are rejected as consumer-biased history. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 4 - UID0001PG layout physical backing

```text
*** UID:0001PG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0004VE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact loader-zero four-byte physical backing for g_pLayoutPaneLayer with 13 direct refs across Application lifecycle, Browser layout/window mapping, and alert/dialog placement; independent semantic definition is routed through MainUiGraph.cpp, Browser-owned g_pBrowserOverlayLayer and six-field aggregate interpretations are rejected, and physical source emission stays blank. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 5 - new layout semantic global

```text
*** UID:0004VE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;

Layer *g_pLayoutPaneLayer = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Sole externally linked zero-initialized Layer pointer definition for the shared Browser/alert layout layer in NexusTK/ui/MainUiGraph.cpp at position 40, backed by UID0001PG and 13 exact refs; local forward declaration plus module definition only, with shared-header extern placement documented separately and no Browser-owned duplicate. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 6 - new status semantic global

```text
*** UID:0004VF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;

Layer *g_pStatusPaneLayer = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Sole externally linked zero-initialized Layer pointer definition for the shared status/transient system-pane layer in NexusTK/ui/MainUiGraph.cpp at position 50, backed by the exact 0x0069b378 child and 14 refs; local forward declaration plus module definition only, with shared-header extern placement documented separately. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 7 - new IME semantic global

```text
*** UID:0004VG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;

Layer *g_pIMEPaneLayer = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Sole externally linked zero-initialized Layer pointer definition for IME status/composition/candidate panes in NexusTK/ui/MainUiGraph.cpp at position 60, backed by the exact 0x0069b37c child and 11 refs; local forward declaration plus module definition only, with incidental FpsPane reuse and shared-header extern placement documented separately. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 8 - UID0002H7 Application startup

```text
*** UID:0002H7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00000D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Application::Startup()
{
    Initialize();

    new IdleWatcher(20000);
    g_packetSender->StartThread();

    new ItemObjImageLib;
    new MapTileImageLib;
    new StaticObjImageLib;
    new NewHumanImageLib;
    new MonsterImageLib;
    new RidingImageLib;
    new EffectObjImageLib;
    new LightObjImageLib;

    new TextFilter;
    new MetaMan;

    g_pScreenPane->InitializeSurfacePresentation();
    new PaletteLib;
    g_pScreenPane->LoadCursorResources();

    ShowWindow(m_hMainWnd, SW_SHOW);
    UpdateWindow(m_hMainWnd);
    SetForegroundWindow(m_hMainWnd);

    DestroyLoadingDialog();
    g_pScreenPane->SetPaneOrder(0, 0);
    g_pScreenPane->StartPresentation();

    g_mainUiLayerSlots.rootPaneLayerContext = new Layer;
    g_mainUiLayerSlots.effectPaneLayerContext = new Layer;
    g_mainUiLayerSlots.overlayPaneLayerContext = new Layer;
    g_pLayoutPaneLayer = new Layer;
    g_pStatusPaneLayer = new Layer;
    g_pIMEPaneLayer = new Layer;

    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.rootPaneLayerContext, 0);
    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.effectPaneLayerContext, 0);
    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.overlayPaneLayerContext, 0);
    g_pScreenPane->SetLayerFrame(g_pLayoutPaneLayer, 0);
    g_pScreenPane->SetLayerFrame(g_pStatusPaneLayer, 0);
    g_pScreenPane->SetLayerFrame(g_pIMEPaneLayer, 0);

    new IMEPane;

    g_pScreenPane->HideCursor();
    PlayStartupLogoBinkFile();
    g_pTimerMgr->RefreshCurrentTick();

    typedef void (__thiscall BaramApp::*BaramAppCallback0)();
    FunctionObject0 *terminalCallback =
        new PlainMemberFunctionObject0<BaramAppCallback0, BaramApp>(
            &BaramApp::OpenTerminalPaneAfterStartupLogo, 0, static_cast<BaramApp *>(this));

    const wchar_t *startupLogoPath = L"NEXON.LGO";
    if (PathExistsViaStat(startupLogoPath)) {
        new LogoPane(startupLogoPath, terminalCallback);
    } else {
        g_pScreenPane->ShowCursor();
        new TerminalPane;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9 - UID0002H8 Application shutdown

```text
*** UID:0002H8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00000D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Application::Shutdown()
{
    ApplicationPhaseState = 4;

    if (g_pEventMan)
        g_pEventMan->ShutdownPacketEventSource();

    delete g_pIMEPane;

    if (g_pScreenPane) {
        g_pScreenPane->DetachLayerFrame(g_pStatusPaneLayer);
        g_pScreenPane->DetachLayerFrame(g_pLayoutPaneLayer);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.overlayPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.effectPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.rootPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_pIMEPaneLayer);
    }

    delete g_pMainMenuPane;

    delete g_pIMEPaneLayer;
    g_pIMEPaneLayer = NULL;

    delete g_pStatusPaneLayer;
    g_pStatusPaneLayer = NULL;

    delete g_mainUiLayerSlots.overlayPaneLayerContext;
    g_mainUiLayerSlots.overlayPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.effectPaneLayerContext;
    g_mainUiLayerSlots.effectPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.rootPaneLayerContext;
    g_mainUiLayerSlots.rootPaneLayerContext = NULL;

    delete g_pLayoutPaneLayer;
    g_pLayoutPaneLayer = NULL;

    delete g_pEffectObjImageLib;
    delete g_pStaticObjImageLib;
    delete g_pNewHumanImageLib;
    delete g_pMonsterImageLib;
    delete g_pRidingImageLib;
    delete g_pMapTileImageLib;
    delete g_pItemObjImageLib;
    delete g_pLightObjImageLib;

    delete g_pIdleWatcher;

    g_packetSender->ForceTerminate();
    delete g_packetSender;

    delete g_pTextFilter;
    delete g_pMetaMan;

    CleanupResources();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 10 - UID0001A1 HistoryViewingPane core

```text
*** UID:0001A1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
HistoryViewingPane::HistoryViewingPane(const wchar_t *resourceName)
    : Pane(0),
      m_frameIndex(0),
      m_totalFrames(g_pEPFLib->GetFrameCount(resourceName) - 1),
      m_delayTimer(10000)
{
    g_pHistoryViewingPane = this;
    m_resourceName.Assign(resourceName);

    RectBounds bounds;
    InitRectBounds(&bounds, 0, 0, g_screenWidth, g_screenHeight);
    Create(bounds, 0, 0, g_pStatusPaneLayer);
    SetCursor(0, g_pCursorManager);
    m_timerHandler.Start(0, m_delayTimer, 0, 0);
}

bool HistoryViewingPane::OnKeyDown(const KeyEvent &event)
{
    if (event.type == 8) {
        const char key = NarrowKeyEvent(event);
        if (key == 13 || key == 27 || key == 32) {
            if (m_frameIndex < m_totalFrames) {
                AdvancePage();
                m_timerHandler.Cancel();
                m_timerHandler.Start(0, m_delayTimer, 0, 0);
                return true;
            }

            MarkForDeletion();
        }
    }

    return true;
}

bool HistoryViewingPane::IsInteractive() const
{
    return true;
}

bool HistoryViewingPane::OnMouseEvent(const MouseEvent &event)
{
    if (event.type != 3 && event.type != 6) {
        return true;
    }

    if (m_frameIndex >= m_totalFrames) {
        MarkForDeletion();
        return true;
    }

    if (m_frameIndex < 3) {
        m_frameIndex = 3;
    } else {
        ++m_frameIndex;
    }

    Invalidate(&m_bounds);
    m_timerHandler.Cancel();
    m_timerHandler.Start(0, m_delayTimer, 0, 0);
    return true;
}

void HistoryViewingPane::OnDraw()
{
    EpfFrame frame;
    g_pEPFLib->GetFrame(m_resourceName.CStr(), m_frameIndex, &frame);
    DrawEpfFrame(frame, m_bounds, L"NPAL4.PAL", 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 11 - UID000392 ScreenDimmer constructor

```text
*** UID:000392 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000C8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000C8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ScreenDimmer::ScreenDimmer(unsigned char dimLevel, Pane *parentPane)
    : Pane(2),
      m_dimLevel(dimLevel)
{
    RectBounds bounds;

    if (g_useEpfAssets) {
        g_pScreenPane->GetBounds(&bounds);
        parentPane->GetBounds(&bounds);
        AddToLayer(&bounds, 0, NULL, g_pStatusPaneLayer);
        SetPaneOrder(NULL, NULL);

        if (parentPane != g_pScreenPane) {
            RemoveFromLayer();
            UnregisterEventHandler();
            parentPane->GetBounds(&bounds);
            AddToLayer(&bounds, 0, parentPane, g_pStatusPaneLayer);
            SetPaneOrder(NULL, parentPane);
        }
    } else {
        g_pScreenPane->GetBounds(&bounds);
        AddToLayer(&bounds, 0, NULL, g_pStatusPaneLayer);
        SetPaneOrder(NULL, NULL);
    }

    g_pEventDispatcher->AddToModalList(this);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 12 - UID0004MG TimerPane constructor

```text
*** UID:0004MG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000F3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000F3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TimerPane::TimerPane(int x, int y, TimerDisplayFormat displayFormat)
    : Pane(1),
      m_displayFormat(displayFormat),
      m_positionX(x),
      m_positionY(y),
      m_timerMode(kTimerModeInactive)
{
    g_pTimerPane = this;

    const Point displaySize = GetDisplaySize(displayFormat);
    RectBounds bounds;

    InitRectBounds(&bounds,
                   x,
                   y,
                   x + displaySize.x,
                   y + displaySize.y);
    AddToLayer(&bounds, 0, 0, g_pStatusPaneLayer);
    SetPaneOrder(0, 0);

    InitRectBounds(&bounds, 0, 0, displaySize.x, displaySize.y);
    UpdateRenderRegion(&bounds);

    _time64(&m_startTime);
    ScheduleTimer(0, 100, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 13 - UID0004BX IMEStatusPane constructor

```text
*** UID:0004BX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006I | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006I | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IMEStatusPane::IMEStatusPane()
    : Pane(0)
{
    RectBounds attachBounds;

    memset(statusText, 0, sizeof(statusText));
    InitRectBounds(&attachBounds, 0, 0, 0, 0);
    SetText(L"Closed", 6);
    AddToLayer(&attachBounds, 0, 0, g_pIMEPaneLayer);
    SetPaneOrder(0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 14 - UID0004C1 IMECompositionPane constructor

```text
*** UID:0004C1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006G | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006G | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IMECompositionPane::IMECompositionPane()
    : Pane(0)
{
    compositionCursorX = 0;
    memset(compositionText, 0, sizeof(compositionText));
    compositionDragActive = false;

    RectBounds initialBounds;
    InitRectBounds(&initialBounds, 0, 0, 0, 0);
    AddToLayer(&initialBounds, 0, NULL, g_pIMEPaneLayer);
    SetPaneOrder(NULL, NULL);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 15 - UID0004C7 IMECandidatePane constructor

```text
*** UID:0004C7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IMECandidatePane::IMECandidatePane()
    : Pane(0)
{
    RectBounds initialBounds;
    InitRectBounds(&initialBounds, 0, 0, 0, 0);
    AddToLayer(&initialBounds, 0, NULL, g_pIMEPaneLayer);

    selectedCandidateRow = -1;

    if (g_pIMEPane->activeChildPane != NULL) {
        RectBounds activeChildBounds;
        g_pIMEPane->activeChildPane->GetBounds(&activeChildBounds);

        IMECompositionPane *compositionPane =
            static_cast<IMECompositionPane *>(g_pIMEPane->activeChildPane);
        candidateAnchorX = activeChildBounds.left + compositionPane->GetCompositionWidth();
        candidateAnchorY = activeChildBounds.bottom + 4;
    } else {
        candidateAnchorX = 4;
        candidateAnchorY = 4;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 16 - UID00015F FpsPane log-session method

```text
*** UID:00015F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FpsPane::UpdateFpsLogSession(bool startNew)
{
    Rect rect(10, 10, 490, 22);

    if (startNew && !IsVisible()) {
        StartLogSession();
        SetFrameRect(&rect, 0, 0, g_pIMEPaneLayer);
        m_frameCount = 0;
        m_updateTimer.StartTimer(0, 1000, 0, 0);
        return;
    }

    WriteLogSummary();
    Hide();
    m_updateTimer.RemoveTimer();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

- Destinations 1-16 were applied only after exact-artifact Gate 1 acceptance and match the accepted managed blocks.
- Five new pages were registered serially as UID0004VE-UID0004VI, and each real UID replaced its brace token before ordinary cross-links. No UID was guessed and no token remains.
- All unrelated method behavior, scores, routes, formals, class layouts, and file inventories were preserved. Formal substitutions changed only the accepted global expressions.
- The ff/aggregate/Fps/Browser names remain explicitly superseded historical assumptions rather than deleted provenance.
- No source-bearing target body remains blank: source resides in three semantic globals and exact existing consumer methods; physical parent/children have complete no-code proof.
- No separate direct audit is deferred for a target cell. The head-triplet's already independent support question does not gate target source or generated output.

## Recommended Target Doc Changes

- Applied and verified `by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md`: D1, score `92/94`, owner NONE, false, blank emitter/position/formal, `Nested:0`, exact zero-fill, split inventory, all 25 refs, lifecycle, source route, names/types, negatives, history, and generated plan.
- Created and validator-registered UID0004VH `by-memory/0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage.md` with D2 and complete first-slot evidence.
- Created and validator-registered UID0004VI `by-memory/0x0069b37c-0x0069b380.g_pIMEPaneLayerStorage.md` with D3 and complete second-slot evidence.
- The parent UID/path/title/range was preserved. The new children use the exact half-open ranges and do not overlap the successor.

## Recommended Support Doc Changes

- Applied and verified UID0001PG D4 with complete zero-fill/13-ref/semantic-global/Browser-alias history.
- Created and validator-registered UID0004VE/UID0004VF/UID0004VG by-global pages with D5-D7, source route UID0000L1 at positions 40/50/60, and separate header extern contract.
- UID00029M preserves score/owner/emitter/formal, records loader-zero current bytes, and identifies the retained head triplet only.
- UID00029N is now `92/94` while preserving false/NONE/blank formal and recording loader-zero no-ref residue.
- UID0001PH preserves score/owner/emitter/formal, records loader-zero initial-byte truth, uses `Nested:-4`, and contains the split-closure note.
- UID0000T6 preserves `86/90`, owner/file route, and blank formal; its current scope is narrowed to the head triplet, layout/tail route through semantic globals, and all old names remain superseded history.
- UID0000L1 is now `90/92` with three sole definitions, source/header policy, exact positions/order, target split, and the remaining head-support marker caveat.
- UID0002H7/UID0002H8 contain D8/D9 byte-for-byte and preserve all other lifecycle detail.
- UID0001A1, UID000392, UID0004MG, UID0004BX, UID0004C1, UID0004C7, and UID00015F contain D10-D16 with only accepted global-expression changes plus complete target evidence/history.
- UID00019K, Application class/file, History class/file, ScreenDimmer class/file, Timer class/file, three IME classes/file/aggregate, and FpsPane class/file received bounded no-loss source-global synchronization; scores/formals stayed unchanged unless a listed destination specified otherwise.
- UID0003ZY HelpPane ctor/class/file, UID000395 ScreenFadeOut ctor/ScreenDimmer file, UID0003VB and UID0001KM plus UserPane class/file received prose-only exact first-slot consumer synchronization; no C++ was added to blank/broad bodies.
- UID0000QD and Browser class/file/aggregate retain the false/no-code alias page and Browser consumer facts while marking the alias superseded by semantic `g_pLayoutPaneLayer`.
- Verify-only/no edit absent contradiction: Layer class/constructor, ScreenPane helpers, IME root body/formal, all unrelated consumer scores/routes, manual coverage, generated files, tracker, ignored ledger, supervisor state.

## Score And Metadata Recommendation

| Page | Accepted pre-callback state | Current applied state | Rationale |
| --- | --- | --- | --- |
| UID00029O | `86/90`, true, owner/emitter UID0000T6 | `92/94`, false, owner NONE, blank emitter/formal | Exact split/no-code/source route resolved. |
| status physical child | absent | UID0004VH, `92/94`, false, owner UID0004VF | Exact bytes/14 refs/type/lifecycle/no-code. |
| IME physical child | absent | UID0004VI, `92/94`, false, owner UID0004VG | Exact bytes/11 refs/type/lifecycle/no-code. |
| UID0001PG | `86/90`, true/emitting | `92/94`, false, semantic owner | Exact independent layout global/no-code resolved. |
| three semantic globals | absent | UID0004VE/VF/VG, each `92/94`, true, UID0000L1, positions 40/50/60 | Exact type/linkage/initializer/route; lexical cap only. |
| UID00029N | `90/85`, false | `92/94`, false | Zero-fill/no-ref/raw-scan proof removes stale uncertainty. |
| UID0000L1 | `88/88` | `90/92` | Three exact source definitions and one-definition policy resolved; broader head support caps score. |
| UID00029M/UID0000T6 | `87/91`, `86/90` | unchanged | Tail report corrects bytes/scope but does not overclaim head declaration shape. |
| UID0001PH and consumers | current | unchanged | Only nesting/dependency prose/formal identifiers change. |

- Score-blocker audit: bytes, static initialization, boundaries, ref inventory, type, naming, aggregate-vs-global shape, ownership, linkage, initializer, source route/order, lifecycle, C++ bodies, no-code pages, nesting, generated state, and coverage handoff were all resolved.
- Confidence remains below 95 because original debug symbols do not survive and exact spellings are inferred, not because any source-shape blocker remains.

## Open Questions With Attempted Resolution

- Were all six active pointers one object? Checked no-ref gap, raw scan, xrefs, UDTs, access form, loops, startup/shutdown, old reports, and generated source. Resolution: layout/tail are independent globals; head remains separately provisional and does not block target.
- What is the first target role? Checked every ref and consumer body. Resolution: status/transient system-pane layer; `g_pStatusPaneLayer` best fits current vocabulary.
- What is the second target role? Checked every ref, including root inline copies and Fps. Resolution: IME pane layer; Fps is incidental.
- Does any consumer own storage? Checked publication/clear/allocation routes. Resolution: no; MainUiGraph source owns definitions and Application owns runtime lifetime.
- Should globals be raw-zero declarations or explicit nonzero sentinels? Checked PE mapping and startup. Resolution: explicit source zero initializer is correct; old ff is false.
- Remaining unresolved question: only exact original spelling/header filename. This is reflected in confidence and does not affect layout, behavior, ABI, one-definition, or C++ eligibility.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Evidence-time full-root observations immediately after unrelated supervisor-owned B003 UID0001PW coverage were: by-memory SHA256 `84F94F4F66A7D5C8A86510FAEBE6C365D3E3ADAC6B5EE43B3A61B03479FB3155` (1,932,448 bytes/4,493 lines); by-global `FE1DB81F93124008EC17A81D669F5C6B397176F36E8F21B633CCCE037448A601` (96,781/214); by-file `E84B18D59AFB9EC26BB908BBACF501EB704FF56750B3F483D703B83706042C37` (147,759/316). These whole-root hashes identify only that read-only observation epoch and are not frozen durable authority. Former B004-epoch observations `316B019A...97DC`, `DAD2BCB4...966C`, and `FD97F683...E83CF`, prior no-loss-repair observations `76E56F84...DB25`, `D603D272...65E`, and `F2230581...420`, and earlier accepted/pre-callback/intermediate hashes are all historical evidence-time snapshots superseded only by unrelated supervisor-owned coverage movement. Manual files were not edited by B005.
- Durable row-specific assertion: at that reread, the B005-scope content of all ten existing replacement rows remained unchanged in substance: UID00029M, UID00029N, UID0001PG, UID00029O, UID0001PH, UID0001A1, UID00015F, UID0000T6, UID0000QD, and UID0000L1. UID0004VH/UID0004VI and UID0004VE/UID0004VF/UID0004VG remained absent. Each replacement below remains a same-or-greater-detail union of the row-specific facts and accepted callback evidence, and disproved facts remain labeled historical with reasons. The supervisor will independently recheck these exact rows and insertion absences immediately before applying the handoff, so unrelated later whole-root movement does not invalidate this durable assertion.
- The following exact eleven actions remain pending external supervisor application. The callback is complete and every row below contains the real validator-issued UIDs; B005 did not edit manual coverage.

1. In `by-memory/-coverage-report.md`, replace UID00029M:

```text
    - [UID:00029M][0x0069b364-0x0069b370.MainUiLayerSlotsHead](by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md) 0x0069b364-0x0069b370 | global layer/context slots | MainUiLayerSlotsHead : reconstructable : 87% : strong : Renamed/split from the former mixed 0x0069b358-0x0069b370 aggregate; 2026-06-07 live IDA MCP confirmed the exact contiguous head triplet, 35/60/101 direct refs, Layer allocation/store/register and mirrored shutdown release/clear lifecycle, broad UI consumers, and the historical direct UID0000T6 assignment. Current PE/MCP evidence proves loader-zero storage rather than the former 0xffffffff characterization, and the zero-ref 0x0069b370 gap narrows UID0000T6 to the provisional head-only source model while excluding independent layout/status/IME globals; only the false initialization and old tail scope are superseded.
```

2. Replace UID00029N:

```text
    - [UID:00029N][0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370](by-memory/0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370.md) 0x0069b370-0x0069b374 | loader-zero no-source residue | UnreferencedDword_69B370 : ignored : 92% : very-strong : Exact four-byte .data virtual-tail zero-fill with zero IDA data refs and zero raw absolute-pointer hits; startup/shutdown skip it while active layer globals on both sides provide positive-control refs. The former initialized-global-data/0xffffffff row is retained as a disproved historical assumption: PE raw/virtual mapping and fresh bytes establish loader zero, so no seventh slot, source owner, or declaration is justified.
```

3. Replace UID0001PG:

```text
    - [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md) 0x0069b374-0x0069b378 | physical global backing | g_pLayoutPaneLayerStorage : ignored : 92% : very-strong : Exact loader-zero four-byte physical backing for g_pLayoutPaneLayer with 13 refs across Application startup/shutdown, Browser layout/window mapping, and alert/dialog placement, plus clean neighboring-slot boundaries after the zero-ref 0x0069b370-0x0069b374 gap and before UID00029O at 0x0069b378. The semantic one-definition route is MainUiGraph.cpp; the historical all-ff, Browser-owned, and six-field-aggregate aliases are rejected with that evidence, and physical C++ stays blank.
```

4. Replace UID00029O and insert its two children immediately below it in address order:

```text
    - [UID:00029O][0x0069b378-0x0069b380.MainUiLayerSlotsTail](by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md) 0x0069b378-0x0069b380 | split parent | MainUiLayerSlotsTail : ignored : 92% : very-strong : Non-emitting exact split parent over two loader-zero Layer-pointer physical children with separate neighboring boundaries, complete 14/11 direct-ref inventories, startup/store/register and shutdown/detach/delete/clear grouping, independent semantic definitions, exact nesting, and blank parent formal C++. The 2026-06-07 live IDA MCP all-0xffffffff observation and historical direct UID0000T6 assignment under the corrected 85/85 gate remain provenance, but PE virtual-tail bytes and the no-ref gap supersede only that initialization and old owner/six-field-aggregate disposition; the Fps-owned alias is likewise rejected by the complete consumer partition.
        - [UID:0004VH][0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage](by-memory/0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage.md) 0x0069b378-0x0069b37c | physical global backing | g_pStatusPaneLayerStorage : ignored : 92% : very-strong : Exact loader-zero four-byte physical backing for g_pStatusPaneLayer with 14 refs covering Application lifecycle and Help, History, ScreenDimmer, ScreenFadeOut, Timer, and two InputBlocker consumers; semantic definition is sole source and physical C++ stays blank.
        - [UID:0004VI][0x0069b37c-0x0069b380.g_pIMEPaneLayerStorage](by-memory/0x0069b37c-0x0069b380.g_pIMEPaneLayerStorage.md) 0x0069b37c-0x0069b380 | physical global backing | g_pIMEPaneLayerStorage : ignored : 92% : very-strong : Exact loader-zero four-byte physical backing for g_pIMEPaneLayer with 11 refs covering Application lifecycle, three IME constructors, two root inline equivalents, and one incidental FpsPane reuse; Fps-owned naming is rejected and physical C++ stays blank.
```

5. Replace UID0001PH:

```text
    - [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md) 0x0069b380-0x0069b381 | global UI gate byte | g_activeDialogCount : reconstructable : 88% : strong : DialogPane-owned loader-zero one-byte active-dialog gate with exactly 13 refs, constructor/destructor mutators, inventory/spell/take-off consumer gates, the exact clean one-byte boundary after the two-child UID00029O split and before zero-ref trailing storage, and Nested -4 closure; the historical initial-0xff wording is superseded by PE/MCP zero-fill evidence.
```

6. Replace stale UID0001A1 and UID00015F rows:

```text
    - [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md) : reconstructable : 89% : strong : Complete source-ready HistoryViewingPane cluster with exact constructor 0x004ffd80-0x004ffec9, key handler 0x004fff10-0x004fff84, true-return slot 0x004fff90-0x004fff95, mouse handler 0x004fffa0-0x0050001a, and draw 0x00500020-0x0050008b extents, plus the compiler-only cleanup island and local padding. The constructor has four direct MainMenuPane::ActivateMenuItem callers at 0x004f7b8d/0x004f7bc3/0x004f7c07/0x004f7c3d and two resource-opening helper callers, OpenStoryViewingPane at 0x004f912b and OpenHistoryViewingPane at 0x004f91ab; it publishes the singleton, stores EPF frame count/resource state, uses full-screen bounds, attaches through g_pStatusPaneLayer, configures cursor/timer behavior, and preserves key/mouse page progression, vtable refs, NPAL4.PAL draw evidence, and the rejected g_pMainUiLayer alias.
        - [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) 0x004b64a0-0x004b67a7 | raw method | FpsPaneUpdateFpsLogSessionRaw : reconstructable : 89% : strong : Source-ready FpsPane::UpdateFpsLogSession(bool) start/finalize toggle over an exact 190-instruction raw body; IDA has no modeled function, direct caller/xref, or saved pointer route, which remains a liveness confidence cap. Direct evidence includes g_fpsDebugActive/g_fpsLogEnabled refs, FpsPane fields +0x104 through +0x168, FPSDATA-* and ***NEW_CLIENT***/summary log strings, time/file APIs, timer scheduling at 0x005975e0, scheduler removal at 0x00597600, and retained StartLogSession/WriteLogSummary helper-call source shape. Its one g_pIMEPaneLayer frame-parent use is incidental and transfers no ownership; old g_pFpsPaneParentPane is superseded.
```

7. In `by-global/-coverage-report.md`, replace UID0000T6:

```text
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) : reconstructable : 86% : strong : Exact split-backing inventory retains UID00029M at 0x0069b364/368/36c as the provisional loader-zero head triplet, UID00029N as the zero-ref 0x0069b370 gap, UID0001PG as independent layout backing, and split parent UID00029O with UID0004VH/UID0004VI as independent status/IME backing. The 35/60/101/13/14/11 ref counts, six-Layer startup/shutdown mirror, broad UI consumers, InitializeMainUiGraph handoff counts of 12 pushes for dword_69B364 and 10 for dword_69B368, exact stale-alias cleanup provenance, historical direct backing-page assignments, and effect/root/overlay naming caveats are preserved. Loader-zero evidence and the gap supersede only all-0xffffffff/six-field-aggregate history and narrow the current source model to the head triplet; layout/status/IME emit as separate semantic globals.
```

8. Insert the three real-UID global rows adjacent to UID0000T6 after callback substitution:

```text
- [UID:0004VE][g_pLayoutPaneLayer](by-global/g_pLayoutPaneLayer.md) : reconstructable : 92% : very-strong : Sole externally linked zero-initialized Layer pointer definition at MainUiGraph.cpp position 40, backed by UID0001PG and 13 Application/Browser/alert refs; shared-header extern is separate, Browser alias is non-emitting, and no duplicate definition exists.
- [UID:0004VF][g_pStatusPaneLayer](by-global/g_pStatusPaneLayer.md) : reconstructable : 92% : very-strong : Sole externally linked zero-initialized Layer pointer definition at MainUiGraph.cpp position 50, backed by the exact 0x0069b378 child and 14 lifecycle/Help/History/ScreenDimmer/Fade/Timer/InputBlocker refs; shared-header extern is separate and modal/transient aliases are rejected.
- [UID:0004VG][g_pIMEPaneLayer](by-global/g_pIMEPaneLayer.md) : reconstructable : 92% : very-strong : Sole externally linked zero-initialized Layer pointer definition at MainUiGraph.cpp position 60, backed by the exact 0x0069b37c child and 11 lifecycle/IME/Fps refs; shared-header extern is separate and Fps-owned aliases are rejected.
```

9. Replace UID0000QD:

```text
- [UID:0000QD][g_pBrowserOverlayLayer](by-global/g_pBrowserOverlayLayer.md) : ignored : 86% : strong : Superseded Browser-facing alias over UID0001PG physical storage; the complete 13-ref inventory preserves Application startup/shutdown, Browser layout/window mapping, alert/dialog consumers, and clean neighboring boundaries. That evidence resolves the sole semantic source definition as shared g_pLayoutPaneLayer in MainUiGraph.cpp, so the generated dword_69B374/Browser-owned alias remains false/non-emitting with blank C++ rather than losing its historical provenance.
```

10. In `by-file/-coverage-report.md`, replace UID0000L1:

```text
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) : reconstructable : 90% : very-strong : In-game UI graph/layer support root preserving both new and legacy layout branches, FRAME.EPF/FRAME.EPD and related resource evidence, map-tile/current-and-legacy playfield setup, common-tail profile/presentation/input/music behavior, and g_pApplication->m_inMapSession state/teardown evidence. It owns the sole external zero-initialized Layer-pointer definitions g_pLayoutPaneLayer/g_pStatusPaneLayer/g_pIMEPaneLayer at positions 40/50/60 with exact loader-zero backing, 13/14/11 refs, Application lifecycle, and cross-module consumers; head-triplet support stays separate, physical layout/target pages stay non-emitting, and Browser/Fps aliases are rejected. UID0002AF/g_pMainMenuPane UID0000RF/UID00019K and receiver-bound initialization remain routed to MainMenuPane, preserving the current no-MainUiGraph-object/source split.
```

11. Verify-only manual rows, no change required after current-root reread: UID0002H7 already preserves the exact 0x4e0-byte startup, WinMain/vtable routes, singleton order, six-layer setup, logo branch, callback/fallback, and compiler exclusions; UID0002H8 preserves the exact 0x215-byte shutdown and six-layer detach/destroy order. UID000392 preserves its exact 342-byte/hash/instruction/CFG/caller/EBO/resource/attachment/EH evidence and does not freeze an obsolete target symbol; UID0004MG preserves singleton, geometry, status-layer attachment, render, timing, four MapPane routes, omitted-field, and EH facts. Separate UID0004BX/UID0004C1/UID0004C7 manual rows remain absent, while current IME file/class rows do not freeze the old global spelling; all other support scores/states remain unchanged.

- Reason B005 must not apply these rows: manual coverage is supervisor-owned and excluded by the assignment. Validator-owned tracker/coverage is not manually edited.

## Follow-Up Actions

- B005 implementation responsibilities are complete and durable: serial registration, real-UID substitution, ordinary edits, scoped validation, final waited generated refresh, readback, report reconciliation, and lease closure all completed.
- Manual coverage application and report execution/archive remain external supervisor-owned state. The repaired exact eleven-action no-loss handoff above is current and unapplied by B005.
- No A-agent action, separate B005 target research, or additional B005 implementation item remains.

## Confidence

- Recommendation confidence: 96% for independent globals and split; 92-96% for exact spellings.
- Score confidence: 94%.
- Remaining uncertainty: original symbol/header spelling only; no behavior, layout, type, linkage, source-route, or C++ blocker remains.

## Validator Results

- Serial registration validators: UID0004VE command `16001` at `16:32:09`, UID0004VF `16002` at `16:33:16`, UID0004VG `16003` at `16:34:15`, UID0004VH `16004` at `16:35:24`, and UID0004VI `16005` at `16:36:40`; all 2026-07-21 ET, exit 0/ok1. Each real UID replaced its token before later cross-linking.
- Core/split validators: target `16006`, final correction `16088`, UID0001PG `16009`, UID00029M `16011`, UID00029N `16012`, UID0001PH `16014`, UID0000T6 `16025`, UID0000L1 `16043`, and UID00019K `16045`; all exit 0/ok1.
- Formal method validators: startup `16027`, shutdown `16029`, History `16031`, ScreenDimmer `16033` plus exact-formal correction `16089`, Timer `16034`, IME constructors `16036/16038/16040`, and Fps `16041`; all exit 0/ok1.
- Class/file/aggregate support validators: Application `16047/16049`; History `16050/16052`; ScreenDimmer `16054/16055`; Timer `16057/16058`; IME classes/file/aggregate `16060/16062/16064/16067/16071/16095`; Fps `16072/16073`; Help `16074/16075/16076`; Fade `16077`; UserPane `16078/16079/16080/16081`; Browser alias/class/file/aggregate `16082/16083/16084/16085/16087`; all exit 0/ok1.
- Final authorized waited target refresh: command `000000016097`, timestamp `2026-07-21T17:15:12-04:00`, exit 0/ok1, generated refresh completed. Side effects were validator-owned registry/reference/stats and auto-generated coverage metadata; B005 did not edit those files.
- Pre-existing validator warnings were retained: missing historical UID refs on Fps/Help/User/Browser pages and project-wide children-marker/emitter warnings during waited refresh. None was introduced as a callback blocker; every scoped command returned ok1.
- Terminal external generated readback at command `000000016111` (`2026-07-21T17:30:34-04:00`) preserves callback semantics: MainUiGraph SHA `95AD4687...F007`, Application `B96FA939...4012`, History `E23BE4B0...3550`, ScreenDimmer `F7D2DB30...F280`, Timer `7F173348...3E61`, IMEPanes `7F4DB24C...B2F`, FpsPane `EE077715...0442`. Tracker was independently read at command `000000016112` (`2026-07-21T17:33:07-04:00`), SHA `212078E9...3A62`, 1,550,988 bytes/6,274 lines. Commands 16100/16108 and earlier are historical external provenance; command 16097 remains callback provenance, not frozen current authority.
- Structural assertions at the current readback: MainUiGraph.cpp has one definition each for UID0004VE/0004VF/0004VG, no UID0001PG/UID00029O/UID0004VH/UID0004VI marker, and only UID0000T6/UID00029M head markers; Application has exact independent lifecycle names and zero old tail fields; History/ScreenDimmer/Timer counts are 1/3/1; IMEPanes has three `g_pIMEPaneLayer` constructor uses; FpsPane has one incidental use; no callback body contains raw address/dword label, fake gap member, cookie, vptr, or decompiler label.
- Final ordinary readback matched 49 callback hashes exactly. UID000189 advanced concurrently to SHA `3188C624...63E4`; its current active dependency section and inventory still preserve all three accepted `g_pIMEPaneLayer` constructor facts, formal ownership, score, route, and unrelated newer detail, so this is a no-loss external-union rebase rather than a B005 ordinary edit.

## Changed Files

- Created ordinary pages: `by-global/g_pLayoutPaneLayer.md` (`1C438D69...E44D`), `by-global/g_pStatusPaneLayer.md` (`B04369D8...B204`), `by-global/g_pIMEPaneLayer.md` (`9D5090F1...337A`), `by-memory/0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage.md` (`31310231...05DD`), and `by-memory/0x0069b37c-0x0069b380.g_pIMEPaneLayerStorage.md` (`6BCE5F2C...7F16`).
- Changed core ordinary pages: target (`814132B7...AE3C`), UID0001PG (`BBFD3F3B...1274`), UID00029M (`FE62C5F6...B06D`), UID00029N (`3C0B6ACE...EBDA`), UID0001PH (`53092075...3A6F`), UID0000T6 (`C85F385A...1635`), and UID0000L1 (`CBDBC19D...D657`).
- Changed lifecycle/formal pages: UID0002H7 (`09781582...9ED0`), UID0002H8 (`13CA3178...1672`), UID00019K (`DC8DD98E...7D64`), UID0001A1 (`015C53B1...61BF`), UID000392 (`30C2BA10...748F`), UID0004MG (`DD81FD20...369B`), UID0004BX (`8C0FD28F...3F7D`), UID0004C1 (`95ACAAA4...E5EB`), UID0004C7 (`51C5935B...6D43`), and UID00015F (`AFBF5A1B...CA5D6`).
- Changed Application/History/ScreenDimmer/Timer support: `by-class/Application.md` (`5F26AA74...D8A1`), `by-file/Application.md` (`A1E19E2C...AF13`), `by-class/HistoryViewingPane.md` (`D0439D52...0F2D`), `by-file/HistoryViewingPane.md` (`0145E0FD...674B`), `by-class/ScreenDimmer.md` (`6E8D44E0...9047`), `by-file/ScreenDimmer.md` (`B94768B2...A4F9`), `by-class/TimerPane.md` (`E9117239...671A`), and `by-file/TimerPane.md` (`36100F56...0DCE`).
- Changed IME/Fps support: `by-class/IMEStatusPane.md` (`8A8E51E2...D816`), `by-class/IMECompositionPane.md` (`2D711156...9D53`), `by-class/IMECandidatePane.md` (`989D48FE...7DE0`), `by-file/IMEPanes.md` (`E0F9F686...ECE6`), UID000189 aggregate (current external-union SHA `3188C624...63E4`; B005 callback SHA `D531F94B...B876` is historical validation provenance), `by-class/FpsPane.md` (`9149FA89...224A`), and `by-file/FpsPane.md` (`28278C38...98FB`).
- Changed prose-only Help/Fade/User support: UID0003ZY (`C9532198...C0BD`), `by-class/HelpPane.md` (`6D7120C3...2CDB`), `by-file/HelpPanes.md` (`6730367B...3789`), UID000395 (`17809C11...4C76`), UID0003VB (`0BF9AAED...F1E9`), UID0001KM (`A60A7CF1...C5A8`), `by-class/UserPane.md` (`F14644F9...2F4B`), and `by-file/UserPane.md` (`4650C9DB...2109`).
- Changed Browser support: `by-global/g_pBrowserOverlayLayer.md` (`B571E745...076C`), `by-class/BrowserControlPane.md` (`F330E32A...A288`), `by-class/Browser.md` (`31684268...F784`), `by-file/Browser.md` (`174EF9E7...4055`), and UID0000Z6 aggregate (`7586FAFA...C4FD`). Total ordinary changed paths: 50.

Exact terminal ordinary manifest (current read-only union):

| Path | Current SHA256 |
| --- | --- |
| `by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md` | `814132B794A9CC38D47C1D9612F310CFAAC0F1FE73EBC4DB19D438970192AE3C` |
| `by-memory/0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage.md` | `3131023189ADA5D6B7BAAEA54ADF3EECC71C50626B34F77ADE2D30A3934105DD` |
| `by-memory/0x0069b37c-0x0069b380.g_pIMEPaneLayerStorage.md` | `6BCE5F2C871C32E10DEB955473F37F9D620A96976088DB7C31A5C34BE9767F16` |
| `by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md` | `BBFD3F3B86CC96639F166719B5C4C60FE7241817587257CFFEC7B962FC631274` |
| `by-global/g_pLayoutPaneLayer.md` | `1C438D69863633BF295996B1F5A73A9A29D003306604238370C074750A00E44D` |
| `by-global/g_pStatusPaneLayer.md` | `B04369D890B9866077F8C0F5729274E7A14BB19667D601C4587FD38D34A4B204` |
| `by-global/g_pIMEPaneLayer.md` | `9D5090F107A7FD57971F0FE67EA055CAF9A7C29D3AE1AA43CE7A8E9F8A2A337A` |
| `by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md` | `FE62C5F68B4571449269116DB06E4DAA43697B67B7FE3B22722294CF227CB06D` |
| `by-memory/0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370.md` | `3C0B6ACE6129C14CED48B8139883AAF3AC11D19E66699FE8CA8C888E821DEBDA` |
| `by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md` | `53092075D5A498398992D5A64ADB247D04AEF2814D358E2DC31B8E6B00BB3A6F` |
| `by-global/MainUiLayerSlots.md` | `C85F385AE5DA6CC2C25504AB7A783FA989A07333F21785F11AF8B3BFA84A1635` |
| `by-file/MainUiGraph.md` | `CBDBC19D608BA891F214081B3F186D30DACC06E6C1C6F833825B22309858D657` |
| `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md` | `09781582284FF8F2F162909343E8D47A680291F925CEFB658C9FD194A7509ED0` |
| `by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md` | `13CA31786C542F1440BC6D00FA56ACF74F9262DB45BF80DE344C723CBB871672` |
| `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md` | `DC8DD98E627DF3D492D779059214A7F32540B6AA2B64920903263904002D7D64` |
| `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` | `015C53B1C41FD963F889C93DD4D770907949240CA12557A1D7BC354198B561BF` |
| `by-memory/0x00559b90-0x00559ce6.ScreenDimmerConstructor.md` | `30C2BA10226B8B85FD79443FAB8A738AF88C6E085AD7B76B8819EA82DF73748F` |
| `by-memory/0x005986e0-0x00598841.TimerPaneConstructor.md` | `DD81FD205D40E68A7EDD9F52E581EDD03085AB152D56A298AE7979609A2E369B` |
| `by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md` | `8C0FD28FA9CB673700FC380A4A7C3758A406DB2A9F3606E707F811140AA33F7D` |
| `by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md` | `95ACAAA4F822143A4C28703EDFC24C0B5D246A5C148939D335BF352DF028E5EB` |
| `by-memory/0x004e7b70-0x004e7cae.IMECandidatePaneConstructor.md` | `51C5935BBC1E7F7D6D0438CD76CE10F68239CC5632E9B4F99900B19F234A6D43` |
| `by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md` | `AFBF5A1BA18D66E5C73923782F13E9A0B1C5D64635588A71C469F2DB904CA5D6` |
| `by-class/Application.md` | `5F26AA7401927083174746EEF6B6FA85DAEF125591EE4C1D9BB53BFB76E5D8A1` |
| `by-file/Application.md` | `A1E19E2C95EE34D6898A739E2EB8DD7C3D2B6DA5738DFF153ECDD6C24CA3AF13` |
| `by-class/HistoryViewingPane.md` | `D0439D52D57051E7C3F98ECFFC1C8F1E4B54190170EF0378E1F9C78A22610F2D` |
| `by-file/HistoryViewingPane.md` | `0145E0FD72FA75A53322F94F4842098908288E8839DEAF2174368A4CB7C0674B` |
| `by-class/ScreenDimmer.md` | `6E8D44E0CAEE5C7DFE965BE2F825EBF63A01C2D4D83E9D88C7EE2505E9619047` |
| `by-file/ScreenDimmer.md` | `B94768B292BCB503751E4FD5EF09F166A06E220384CF8693C19C42D1A0C8A4F9` |
| `by-class/TimerPane.md` | `E91172392EF64BC1D8AC2458C49774475BD7E8313446E716423CFE9FA487671A` |
| `by-file/TimerPane.md` | `36100F56B4EAF5DB816BFF83842EE0F5E7B3A26F6E4870CA481104C0FF730DCE` |
| `by-class/IMEStatusPane.md` | `8A8E51E2CF3271D72F7E7F0E4E5F63ACEC394702800B4A14EA9CE69D055AD816` |
| `by-class/IMECompositionPane.md` | `2D7111566183A70E41F3E66676AA0AE60002D3E86FB8E8FA10147A1B3CB39D53` |
| `by-class/IMECandidatePane.md` | `989D48FE115EDCE0F3E5A16E1328AE74EF8272F12059D9827C4A3CB3B22C7DE0` |
| `by-file/IMEPanes.md` | `E0F9F686132E62020256C5E8412F5391711D023F0B1014A5D83C7E20C9D3ECE6` |
| `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` | `3188C6248309B7F06B8160AF517CB139B4F3701A3207729B074A5551BB8A63E4` |
| `by-class/FpsPane.md` | `9149FA89D38DDC44951ADD4ECDD24FD8B3B44A05E5E0DBCBF97A41342185224A` |
| `by-file/FpsPane.md` | `28278C383C2545AEFFAE176A79A1D26806968B8F5AB4DED69F1F30C2DE2A98FB` |
| `by-memory/0x004c6960-0x004c6dac.HelpPaneConstructor.md` | `C9532198A4863388C556AC98787657BBA252916E7E6D36CE953765E76A5BC0BD` |
| `by-class/HelpPane.md` | `6D7120C33058351C5A013259C31F3520E6CC5607AC7FC8EE9FA734458DEF2CDB` |
| `by-file/HelpPanes.md` | `6730367B7E84B176EEE789ABC43FE2107EE039E500460516D138855038A13789` |
| `by-memory/0x00559e50-0x00559f5e.ScreenFadeOutConstructor.md` | `17809C11C8F4040C417A3F908A43A662F8E9C810F29F2E615FC2276D95C14C76` |
| `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md` | `0BF9AAED15021EEC8FB40D8BB97ADD8B9893C75B675C04DB49C41D667B8BF1E9` |
| `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | `A60A7CF14332009604DF0EA2C985A4F8CFEA4BC22C66A6D9414939FAF2EEC5A8` |
| `by-class/UserPane.md` | `F14644F980487F915D6EB0AC5CD00D8BA5A0D42583EFACFD6F90BF148F692F4B` |
| `by-file/UserPane.md` | `4650C9DB50AAB98A97F39B0CC7B6F025F74F0278FF44293D8AE070E9B2442109` |
| `by-global/g_pBrowserOverlayLayer.md` | `B571E745A0F042ECE00885B989ECBF85C5A2DBBA30A2AFA8734EF3181E94076C` |
| `by-class/BrowserControlPane.md` | `F330E32A0A08CDA73C7DEE084EB87E57D015ECA9C4112F9FAFF5E6D0EFD6A288` |
| `by-class/Browser.md` | `3168426841121460B539935C4A8410C17A9B451BB189DB499DC405FA3D16F784` |
| `by-file/Browser.md` | `174EF9E7AB25BCBF1BDFC1E064875EC1CA689E4C6A6C43F0DED5C5AC0D794055` |
| `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` | `7586FAFA46F10ED61998680EBBCB165A805BCB21F127FAEF0E7FF45AD762C4FD` |

- Generated/tracker/validator-state files changed only as validator-owned side effects. Manual coverage, audit, supervisor, goal, IDA, and lifecycle files were not edited by B005. Report execution/probe/move/archive/lifecycle commands were not run.

## Implementation Tracking Checklist

Initial report-only pass and completed callback obligations:
- [x] Supervisor validated the accepted pre-callback report artifact before implementation.
- [x] Preserve CHATGPT 5.6 xHigh provenance and all evidence/history.
- [x] Reread all ordinary destinations and current leases immediately before each edit.
- [x] Register UID0004VE (`g_pLayoutPaneLayer`) serially and replace its token everywhere.
- [x] Register UID0004VF (`g_pStatusPaneLayer`) serially and replace its token everywhere.
- [x] Register UID0004VG (`g_pIMEPaneLayer`) serially and replace its token everywhere.
- [x] Register UID0004VH (`g_pStatusPaneLayerStorage`) serially and replace its token everywhere.
- [x] Register UID0004VI (`g_pIMEPaneLayerStorage`) serially and replace its token everywhere.
- [x] Confirm zero provisional tokens remain before cross-link completion.
- [x] Apply C01-C40 without compression and retain destination-specific proof.
- [x] Apply Destination 1 target split-parent metadata/summary/no-code block.
- [x] Apply Destination 2 exact status physical child and `Nested:+4`.
- [x] Apply Destination 3 exact IME physical child and `Nested:0`.
- [x] Apply Destination 4 UID0001PG physical backing conversion.
- [x] Apply Destination 5 sole layout global definition at position 40.
- [x] Apply Destination 6 sole status global definition at position 50.
- [x] Apply Destination 7 sole IME global definition at position 60.
- [x] Apply Destination 8 startup body byte-for-byte except accepted expressions.
- [x] Apply Destination 9 shutdown body byte-for-byte except accepted expressions.
- [x] Apply Destination 10 History full formal with status global.
- [x] Apply Destination 11 ScreenDimmer full formal with status global.
- [x] Apply Destination 12 TimerPane full formal with status global.
- [x] Apply Destinations 13-15 exact IME constructor formals.
- [x] Apply Destination 16 exact FpsPane formal without ownership transfer.
- [x] Correct UID00029M loader-zero/current source-scope prose without score/formal change.
- [x] Correct UID00029N loader-zero/no-source state and raise only to accepted score.
- [x] Set UID0001PH `Nested:-4` and correct loader-zero current prose.
- [x] Narrow UID0000T6 to head-triplet support and preserve all head evidence.
- [x] Raise UID0000L1 only to accepted `90/92` and add complete source/one-definition plan.
- [x] Update UID00019K declaration-shape prose while preserving MainMenuPane ownership/formal.
- [x] Update Application class/file with complete head-plus-independent-global union.
- [x] Update History class/file dependency and stale alias history.
- [x] Update ScreenDimmer class/file dependency and preserve all constructor/peer detail.
- [x] Update TimerPane class/file dependency and preserve all method/resource detail.
- [x] Update three IME classes/file/aggregate with exact IME-layer union.
- [x] Update FpsPane class/file with incidental IME-layer reuse and preserve diagnostics detail.
- [x] Update HelpPane ctor/class/file with exact status-layer consumer evidence only.
- [x] Update ScreenFadeOut ctor/source support with exact status-layer evidence only.
- [x] Update UserPane dispatcher/local aggregate/class/file with both InputBlocker status-layer refs only.
- [x] Update UID0000QD/Browser support to superseded shared-layout alias without losing Browser facts.
- [x] Preserve exact PE section/raw mapping and all zero-byte hashes.
- [x] Preserve every 14/11 target xref address and every 13-ref layout fact.
- [x] Preserve startup/register and shutdown/detach/delete/clear instruction order.
- [x] Preserve Layer 8-byte constructor/type proof and source/compiler separation.
- [x] Preserve positive and negative evidence, rejected names, and historical ff/aggregate assumptions.
- [x] Preserve all unrelated scores, routes, class layouts, formals, callers, resources, and concurrent detail.
- [x] Confirm no Wave2/Wave3 evidence is incorporated.
- [x] Confirm no third-party import applies.
- [x] Lease only one ordinary file immediately around its edit/scoped validator.
- [x] Release each ordinary lease immediately after validation; never wait while holding one.
- [x] Run one scoped validator per changed ordinary page and record command/timestamp/exit/ok/warnings/side effects.
- [x] Run final authorized waited target refresh only after all ordinary leases clear.
- [x] Verify three sole semantic global definitions in MainUiGraph.cpp.
- [x] Verify no UID0001PG/UID00029O/physical-child Empty Emitter Marker remains.
- [x] Verify retained UID0000T6/UID00029M head markers are the only independent family markers unless separately resolved.
- [x] Verify Application preserves exact allocation/register/detach/delete/clear order.
- [x] Verify History/ScreenDimmer/Timer use `g_pStatusPaneLayer` exact counts 1/3/1.
- [x] Verify IMEPanes has three constructor uses of `g_pIMEPaneLayer` and no old fps field spelling.
- [x] Verify FpsPane has one incidental `g_pIMEPaneLayer` use and no old parent alias.
- [x] Verify zero raw labels, addresses, fake gap members, vptr/EH/delete flags, or decompiler artifacts introduced by this callback.
- [x] Reread all ten existing proposed manual rows plus five absent real-UID rows and preserve a same-or-greater-detail eleven-action supervisor-owned handoff.
- [x] Do not edit any manual `-coverage-report.md`, generated, tracker, audit, supervisor, validator-state, or IDA file manually.
- [x] Update C01-C40 to legal terminal callback states with separate exact proof only after implementation.
- [x] Check callback rows only when their readback is true; no accepted item is blocked.
- [x] Confirm zero B005 leases remain.
- [x] Do not run/probe execute_report, lifecycle, move, archive, or report-count commands.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support detail incorporated at report-level detail.
- [x] Claim ledger terminalized claim by claim with exact validator/generated proof.
- [x] Metadata/score/owner/emitter/split/C++ changes applied exactly; no accepted item excluded.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions remain resolved with lexical cap only.
- [x] Validators and final waited generated refresh recorded.
- [x] Exact manual supervisor-owned coverage text is current and no-loss for rename/split provenance, MCP/85-85 history, boundaries, method extents/callers, raw liveness, split inventory/handoff counts, and MainUiGraph layout/resource/session routes.
- [x] Remaining unapplied accepted items: none; only external supervisor-owned coverage/lifecycle state remains.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000016154","destination_path":"executed-b-agent-research/B005/00029O-MainUiLayerSlotsTail-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00029O-MainUiLayerSlotsTail-source-quality.md","timestamp":"2026-07-21T18:33:20-04:00","uid":"00029O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
