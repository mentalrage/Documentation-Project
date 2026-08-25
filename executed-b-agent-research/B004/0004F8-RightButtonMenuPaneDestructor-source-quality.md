** TARGET-REPORT-UID:0004F8 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004F8 RightButtonMenuPane Destructor Source Closure Research


## Finalized Report / Current Recommendation

- Current recommendation: accept the implemented [UID:0004F8] source-emitting `92/94` ordinary destructor child under [UID:0000C0] `RightButtonMenuPane`.
- Final disposition: `[0x00554ba0,0x00554c33)` is the ordinary non-deleting `RightButtonMenuPane::~RightButtonMenuPane()` body. The handwritten body clears the active map's highlighted object, removes the pane from its layer, and unregisters its inherited event-handler facet.
- Implemented action: the target now carries the exact formal destructor, `EMITTER_UIDS:0000C0`, source position `30`, preserved `CANONICAL_OWNER:0000C0`/`RECONSTRUCTABLE:TRUE`, and report-level synchronization across the accepted class/file/container/constructor/wrapper/singleton support pages without pruning prior evidence.
- Confidence: very strong for range, destructor variant, behavior, owner, emitter, source file, helper roles, client-state type/member, direct-base lowering, and behavior-exact C++; high for the inferred original source spellings.
- Lifecycle: the supervisor accepted pre-callback SHA `26ED382A572EA1020C0C8D68B02E7A923BB7DD1B905AB96824830D090226E09E` at Gate 1; B004 completed the authorized ordinary-doc callback and scoped validation. Manual coverage application, fresh full Gate 1, independent Gate 2, report execution, and archival remain supervisor-owned. B004 made no manual coverage, generated, IDA, audit, supervisor-state, or lifecycle edit and did not run/probe `execute_report`.

## Supporting Research

- Live IDA MCP database/session `9b0396a3` is active for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`.
- Read-only MCP `server_health` request `706` reported `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Current-target read-only MCP requests used in this pass:
  - `707` `lookup_funcs` for constructor, target, target end, successor, and scalar wrapper.
  - `708` `analyze_component` for the target and four direct cleanup callees.
  - `709` `analyze_function(0x00554ba0)`.
  - `711` `analyze_function(0x00554b40)`.
  - `712` `analyze_function(0x00556240)`.
  - `713` `xrefs_to` for the target, three vtable bases, and singleton storage.
  - `714` `get_bytes` for target boundaries and the RightButtonMenuPane RTTI block.
  - `715`/`721` `entity_query` for RightButtonMenuPane, Pane, inherited-facet, and Singleton RTTI names.
  - `716` `analyze_function(0x0053b1b0)`.
  - `717` `analyze_function(0x00544ce0)`.
  - `718` `analyze_function(0x00544d70)`.
  - `719` `analyze_function(0x00544580)`.
  - `720` `get_int` for the complete RightButtonMenuPane RTTI base array and Singleton PMD.
- Prior family research was rechecked rather than copied forward:
  - `executed-b-agent-research/B005/0001FX-RightButtonMenuPaneCore-source-quality.md`.
  - `executed-b-agent-research/B008/0001G2-RightButtonMenuPaneScalarDeletingDestructor-source-quality.md`.
- The B005 report's historical conclusion that UID0004F8 had to stay blank until teardown helper and client-slot names were synchronized is now superseded by this pass.
- The B008 wrapper report correctly established that UID0001G2 is compiler-generated scalar deleting destructor glue and that source-authored cleanup belongs to UID0004F8. This pass closes that deferred ordinary-destructor source work.

## Target

- Target UID: `0004F8`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0004F8] `by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md`, ordinary non-deleting destructor body.
- Target path: `by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md`.
- Current source queue/report row: `auto-generated/-ag-research-tracker.md`, latest observed command `000000016666`, refreshed `2026-07-22T23:36:37-04:00`, source `foreground-generated-refresh`, SHA256 `E21076DC1AD30D15DB629B89373762CB61DD29A67697D94ECE01DBE92845AE47`, 1,635,363 bytes, 6,508 lines; by-memory section line 1664, reconstructable queue line 1666, target row line 3285.
- Current tracker tuple: `92/94`, combined `93.0`, reconstructable true, zero direct/additional report counts pending supervisor report execution.
- Current supervisor classification: accepted ordinary-doc implementation callback complete; manual coverage, fresh Gate 1/Gate 2, and execution remain supervisor stages.
- Current scores and parent state: target `92/94`; direct class owner [UID:0000C0] remains `86/89`; file root [UID:0000N7] remains `86/88`.

## Current Target State

- Current metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000C0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000C0`, source position `30`, and exact formal ordinary-destructor C++.
- Current owner/emitter/reconstructable state: semantic owner remains UID0000C0; the accepted emitter route and position now place the exact child body in UID0000N7 `NexusTK/ui/menu/RightButtonMenuPane.cpp`.
- Current C++/emitter state: source-facing `SetHighlightState`, `RemoveFromLayer`, `UnregisterEventHandler`, `g_activeMapPane`, and `m_highlightedObjectPane` are applied; compiler-lowered vptr, Singleton, Pane-base, EH, and scalar-delete effects remain excluded.
- Historical assumptions preserved and labeled superseded:
  - "destructor variant remains inferred" described the pre-callback page. UID0004F8 is now the ordinary non-deleting body; UID0001G2 is the separate scalar deleting wrapper.
  - "teardown helpers remain inferred" is historical. They resolve to `LivingObjectPane::SetHighlightState`, `Pane::RemoveFromLayer`, `Pane::UnregisterEventHandler`, and `Pane::~Pane`.
  - "client object slot remains inferred" is historical. It is `g_activeMapPane->m_highlightedObjectPane`, a `LivingObjectPane *` at `MapPane+0x104`.
  - Treating the singleton clear or `Pane::~Pane()` call as handwritten destructor statements remains rejected. RTTI, constructor lowering, and the project Singleton precedent show both are compiler-generated direct-base teardown.
- Related target/support docs checked: RightButtonMenuPane class/file/core/constructor/scalar-wrapper/vtable/singleton pages, Pane file/layout/vtable pages, LivingObjectPane helper/class pages, MapPane layout/global pages, ParcelIconPane destructor precedent, manual coverage roots, current tracker, and current generated `RightButtonMenuPane.cpp`.
- Current target file identity: SHA256 `3D3D5363BD3DAEC54ACF142571F06363DF47AF2F9161230C5C6EF2BEA7315DF0`, 9,545 bytes, 113 lines.
- Current artifact/lifecycle status: pre-callback Gate 1 passed and the accepted ordinary-doc callback is implemented/validated. The report remains active and unexecuted pending supervisor manual rows, fresh Gate 1, independent Gate 2, and lifecycle execution.

## Executive Recommendation

- Implemented direct owner [UID:0000C0] `RightButtonMenuPane` and source route [UID:0000N7] `NexusTK/ui/menu/RightButtonMenuPane.cpp`.
- Implemented target `EMITTER_UIDS:0000C0`, `EMITTER_POSITION_OPTIONAL:30`, and `92/94`.
- Emitted only the three handwritten source actions:
  1. clear highlight state on `g_activeMapPane->m_highlightedObjectPane` and null the slot;
  2. call inherited `RemoveFromLayer()`;
  3. call inherited `UnregisterEventHandler()`.
- Excluded compiler-lowered vptr stores, SEH/security-cookie scaffolding, `Singleton<RightButtonMenuPane>` global clear, implicit `Pane::~Pane()`, adjusted deleting-destructor thunks, delete flags, and operator delete.
- No split, merge, range extension, new owner, or new source file was needed.

## Supervisor Active Recheck

- The supervisor assigned direct UID0004F8 closure and explicitly prohibited deferring the blank emitter/formal or raw names.
- The broad UID0001FX core was already split before this assignment. UID0004F8 is an exact registered child and does not require another split.
- Every source-bearing operation in UID0004F8 is resolved to an implementation-ready source expression.
- All compiler-only effects in the machine range have a concrete exclusion reason and an inducing source construct.
- No additional target UID is claimed. Related pages are support synchronization destinations only.

## Inference Research Guidance Check

- The by-structure rule requires this by-memory page to emit only source represented by its exact range. The recommended body does that: it emits the ordinary destructor, not the scalar wrapper, RTTI, vtable data, singleton storage, or Pane implementation.
- Existing documentation was treated as evidence, not authority. In particular, the old no-code proof and generated `SetHighlighted` spelling were rechecked against live bytes, current accepted class formal C++, and current support docs.
- Direct IDA facts:
  - exact function boundaries and calls;
  - three destructor-phase vptr stores;
  - global/member loads and writes;
  - no inbound target xrefs;
  - scalar-wrapper parity;
  - RTTI base descriptors and PMD offsets.
- Documentation facts:
  - accepted names `g_activeMapPane`, `m_highlightedObjectPane`, `SetHighlightState`, `RemoveFromLayer`, and `UnregisterEventHandler`;
  - accepted class/file ownership and Singleton source convention.
- Inference:
  - the most plausible handwritten source uses direct repeated `g_activeMapPane->m_highlightedObjectPane` expressions because the machine reloads the global after the virtual/helper call rather than preserving a local across it;
  - `false` and `NULL` match current project source style and preserve the observed zero values.
- No Wave2/Wave3 evidence was used. Historical mentions in older class documentation were ignored as stale workflow artifacts.

## Heuristic / Inference Reanalysis And Validation

### Destructor variant

- `lookup_funcs` request `707` confirms `sub_554BA0` at `0x00554ba0`, size `0x93`, with no function at exclusive end `0x00554c33`; successor `sub_554C40` begins at `0x00554c40`.
- `analyze_function` request `709` shows a `void __thiscall` body with no delete flag, no operator delete, and no return of the object pointer.
- `analyze_function` request `712` separately shows `sub_556240` at `0x00556240`, size `0xd4`, returning the object pointer and testing scalar-delete flag bits before optional `sub_4F4AC0`.
- Best resolution: UID0004F8 is the ordinary non-deleting destructor; UID0001G2 is the compiler-generated scalar deleting wrapper.

### `dword_67A764 + 260`

- Live target decompilation reads `*(_BYTE **)(dword_67A764 + 260)`, conditionally calls `sub_53B1B0(pointer,0)`, reloads `dword_67A764`, and clears offset `260` / `0x104`.
- [UID:0000PR] identifies `dword_67A764` as `MapPane *g_activeMapPane`.
- [UID:00042K] identifies `MapPane+0x104` as `LivingObjectPane *m_highlightedObjectPane`.
- Best resolution: `g_activeMapPane->m_highlightedObjectPane`. The older generic "client/menu object pointer" wording is too weak.
- Rejected alternatives: parcel pointer, selected object, target object, or menu-owned field. The typed MapPane layout and existing MapPane paint/lifecycle consumers establish highlighted-object semantics.

### `sub_53B1B0`

- Request `716` shows a `LivingObjectPane` method that compares and writes byte `this+0x1e8`, starts/stops state at `this+0x1f0`, and invalidates/redraws through virtual slot `+0x20`.
- Current LivingObjectPane formal C++ declares and defines `void SetHighlightState(bool highlighted)` for this exact address.
- Best resolution: `LivingObjectPane::SetHighlightState(bool)`.
- Rejected names:
  - raw `sub_53B1B0`;
  - generated MapPane-only alias `SetHighlighted`, which conflicts with the current accepted LivingObjectPane declaration;
  - `SetTargetHighlight`, which is a historical descriptive alias but not the current canonical class method spelling.

### `sub_544CE0`

- Request `717` shows the Pane method unregistering `this+0xa0` from dispatcher state, removing the pane from its cached layer at `this+0xa8`, and clearing that layer pointer.
- Pane layout/vtable documentation maps exact address `0x00544ce0` and primary virtual slot `+0x38` to `Pane::RemoveFromLayer`.
- Best resolution: inherited `RemoveFromLayer()`.

### `sub_544D70`

- Request `718` shows the Pane method passing `this+0xa0` to the EventDispatcher removal route.
- Pane layout/vtable documentation maps exact address `0x00544d70` and primary virtual slot `+0x40` to `Pane::UnregisterEventHandler`.
- Best resolution: inherited `UnregisterEventHandler()`.

### `sub_544580`

- Request `719` restores Pane vtables, repeats layer/dispatcher cleanup defensively, destroys Pane-owned regions/handler facets, and tears down GrafPort state.
- Pane documentation identifies exact range `0x00544580-0x00544687` as ordinary `Pane::~Pane()`.
- Best resolution: implicit direct-base destruction. It must not be written as `Pane::~Pane()` in the derived destructor body.

### `unk_69B4F0`

- Request `713` reports ten xrefs to `0x0069b4f0`, including constructor publish at `0x00554b65`, ordinary-destructor clear at `0x00554c14`, scalar-wrapper clear at `0x005562bb`, and menu lifetime consumers.
- The storage page identifies it as `g_pRightButtonMenuPane`.
- RTTI requests `714`, `715`, `720`, and `721` establish direct `Singleton<RightButtonMenuPane>` base metadata at PMD `mdisp=0xf8`, `pdisp=-1`, `vdisp=0`, attributes `0x40`.
- Constructor request `711` shows the null-preserving adjusted publication associated with that base at the same `+0xf8` location.
- Best resolution: source declaration inherits `Singleton<RightButtonMenuPane>`; its destructor generates the unconditional `g_pRightButtonMenuPane = NULL` store. Do not handwrite the clear.

### Vptr stores and inheritance facets

- Request `713` reports exactly three xrefs to each vtable base from constructor, ordinary destructor, and scalar wrapper:
  - primary `0x00622f68`: `0x00554b70`, `0x00554bc5`, `0x00556265`;
  - secondary `0x00622fbc`: `0x00554b76`, `0x00554bcb`, `0x0055626b`;
  - tertiary `0x00622fec`: `0x00554b80`, `0x00554bd5`, `0x00556275`.
- The primary RightButtonMenuPane RTTI hierarchy contains RightButtonMenuPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<RightButtonMenuPane>`.
- `Pane` supplies the inherited EventHandler facet at `+0xa0` and TimerHandler facet at `+0xa4`; they are not additional direct bases to spell on `RightButtonMenuPane`.
- Best source shape: `RightButtonMenuPane : public Pane, public Singleton<RightButtonMenuPane>`. Vptr stores remain compiler output.

### Source expression shape

- The target reloads `dword_67A764` after `SetHighlightState(false)` before clearing `+0x104`.
- A retained local `LivingObjectPane *highlightedPane` would normally allow the compiler to retain the pointer, but the observed reload is naturally generated by two direct global/member expressions around a call that may alias global state.
- Recommended source therefore repeats `g_activeMapPane->m_highlightedObjectPane` rather than inventing a local.
- No null check for `g_activeMapPane` is allowed: the binary dereferences it unconditionally. Adding one would change failure behavior.

### Score blocker closure

- Blank formal: resolved with behavior-exact C++.
- Blank emitter: resolved with direct class owner [UID:0000C0].
- Destructor variant: resolved by ordinary/scalar comparison.
- Raw helper names: all four resolved.
- Raw global/member: resolved to typed accepted names.
- Singleton clear: resolved as direct-base lowering.
- Base destructor: resolved as implicit lowering.
- Range/padding: exact.
- Source placement: exact existing class/file route.
- No score-limiting blocker remains for draft emission. Scores remain below 95 because original source spellings are inferred rather than symbol-proven and the broader class still has other blank children.

## Evidence Standards Used

- Live IDA MCP function lookup, decompilation, component analysis, xrefs, bytes, RTTI names, and typed integer reads.
- Constructor/ordinary-destructor/scalar-wrapper behavioral parity.
- Vtable triad stores and adjusted destructor thunk family.
- Accepted typed class/global/layout documentation.
- Current generated-output absence and empty-marker checks.
- Negative evidence: no direct target xrefs, no separate source owner, no delete flags in the ordinary body, and no need for another split.
- Evidence ladder:
  1. exact live binary facts;
  2. accepted current by-* names/types;
  3. cross-family destructor and Singleton precedent;
  4. source-shape inference constrained by machine behavior.
- The executable lacks original local/source symbols for most project methods. That limits original-spelling certainty but does not justify raw IDA labels in source.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - requests `706-721` listed under Supporting Research;
  - exact target bytes and boundary padding;
  - exact scalar-wrapper duplicate sequence;
  - exact vtable and singleton xrefs;
  - RTTI hierarchy and Singleton PMD.
- by-* docs checked:
  - target [UID:0004F8];
  - [UID:0000C0] class and [UID:0000N7] file;
  - [UID:0001FX] core split;
  - [UID:0004F7] constructor;
  - [UID:0001G0] thunks and [UID:0001G2] scalar wrapper;
  - [UID:0003CX] vtable data and [UID:00029Z] singleton storage;
  - [UID:00042K] MapPane layout and [UID:0000PR] g_activeMapPane;
  - LivingObjectPane helper/class pages;
  - Pane file/layout/vtable pages;
  - [UID:0001EI] ParcelIconPane ordinary destructor precedent.
- Old reports checked:
  - B005 UID0001FX split report;
  - B008 UID0001G2 scalar-wrapper report.
- Generated/tracker checked:
  - historical report-only tracker command `16628`;
  - historical pre-callback `RightButtonMenuPane.cpp` command `16594`, which omitted UID0004F8;
  - historical initial callback tracker/generated checkpoint command `16650` and intervening external refresh command `16659`;
  - latest observed tracker command `16666`, SHA256 `E21076DC1AD30D15DB629B89373762CB61DD29A67697D94ECE01DBE92845AE47`, 1,635,363 bytes, 6,508 lines;
  - latest observed `auto-generated/NexusTK/ui/menu/RightButtonMenuPane.cpp`, command `16666`, refreshed `2026-07-22T23:36:37-04:00`, source `foreground-generated-refresh`, SHA256 `AC9708AE35A849D5FD0F88C642088C355F00BF5797A74483E2A44970DB546BA3`, 4,213 bytes, 126 lines.
- Current generated semantic counts:
  - `UID:0004F8`: one;
  - `RightButtonMenuPane::~RightButtonMenuPane`: one;
  - `Empty Emitter Marker`: five;
  - UID0004F8 empty marker: zero;
  - UID0001G2 marker: one.
- Negative checks:
  - no xrefs to ordinary destructor start;
  - no delete flag/operator delete in UID0004F8;
  - no target range overlap with constructor or OnEvent;
  - no evidence for VoteMenuPane, Pane, LivingObjectPane, MapPane, or singleton storage as direct owner.
- Intentionally skipped:
  - no IDA database mutation because the callback authorized ordinary documentation only;
  - no manual coverage edit because all `-coverage-report.md` roots are supervisor-only;
  - no generated/tracker direct edit because validator commands own those outputs;
  - no lifecycle/execute_report command because B agents may never execute their own reports.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C4F8-001 | 0004F8 | Exact half-open target is `[0x00554ba0,0x00554c33)`, size `0x93`. | very high | MCP 707/709/714 | target Address Range | already-present | already-present |
| C4F8-002 | 0004F8 | UID0004F8 is the ordinary non-deleting destructor, not the scalar deleting wrapper. | very high | MCP 709/712 | target Status/Signature | incorporate | applied |
| C4F8-003 | 0004F8 | No inbound xref reaches the ordinary start; ABI family parity still proves the source destructor. | high | MCP 709/713 | target Callers/Negative Evidence | incorporate | applied |
| C4F8-004 | 0004F8 | Three vptr stores target `0x622f68`, `0x622fbc`, and `0x622fec`. | very high | MCP 709/713 | target Raw Evidence | already-present | already-present |
| C4F8-005 | 0004F8 | Constructor, ordinary destructor, and scalar wrapper are the only writers to each vtable base. | very high | MCP 713 | target Vtable Evidence; class support | incorporate | applied |
| C4F8-006 | 0004F8 | `sub_53B1B0` is `LivingObjectPane::SetHighlightState(bool)`. | high | MCP 716; accepted LivingObjectPane formal | target Helpers/C++ | incorporate | applied |
| C4F8-007 | 0004F8 | `dword_67A764` is `MapPane *g_activeMapPane`. | very high | UID0000PR; MCP target data access | target Touched State/C++ | incorporate | applied |
| C4F8-008 | 0004F8 | `MapPane+0x104` is `m_highlightedObjectPane`. | very high | UID00042K; MCP 709 | target Touched State/C++ | incorporate | applied |
| C4F8-009 | 0004F8 | `m_highlightedObjectPane` has type `LivingObjectPane *`. | very high | UID00042K | target Types/C++ | incorporate | applied |
| C4F8-010 | 0004F8 | Highlight clear occurs only when the slot is non-null. | very high | MCP 709 | target Behavior/C++ | incorporate | applied |
| C4F8-011 | 0004F8 | Source must not add a `g_activeMapPane` null guard. | very high | unconditional binary dereference | target C++ rationale | reject-invalid | excluded-with-reason |
| C4F8-012 | 0004F8 | `sub_544CE0` is inherited `Pane::RemoveFromLayer()`. | very high | MCP 717; Pane layout/vtable | target Helpers/C++ | incorporate | applied |
| C4F8-013 | 0004F8 | `sub_544D70` is inherited `Pane::UnregisterEventHandler()`. | very high | MCP 718; Pane layout/vtable | target Helpers/C++ | incorporate | applied |
| C4F8-014 | 0004F8 | `unk_69B4F0` is `g_pRightButtonMenuPane`. | very high | MCP 713; UID00029Z | target Touched State | incorporate | applied |
| C4F8-015 | 0004F8 | Unconditional singleton clear is generated by direct `Singleton<RightButtonMenuPane>` destruction. | high | MCP 711/714/715/720/721; Singleton precedent | target Source Lowering; class/singleton support | incorporate | applied |
| C4F8-016 | 0004F8 | `sub_544580` is implicit `Pane::~Pane()` and must not appear as a handwritten call. | very high | MCP 719; Pane docs | target Source Lowering/C++ | reject-invalid | excluded-with-reason |
| C4F8-017 | 0004F8 | Destructor-phase vptr writes are compiler output and must not be represented as fields/assignments. | very high | MCP 709/713; RTTI | target Source Lowering/C++ | reject-invalid | excluded-with-reason |
| C4F8-018 | 0004F8 | SEH/security-cookie setup and teardown are compiler output. | very high | target bytes/decompile | target Source Lowering | reject-invalid | excluded-with-reason |
| C4F8-019 | 0004F8 | Exact source body contains highlight clear, RemoveFromLayer, and UnregisterEventHandler only. | high | complete lowering analysis | target formal C++ | incorporate | applied |
| C4F8-020 | 0004F8 | Direct semantic owner remains UID0000C0 RightButtonMenuPane. | very high | vtables, singleton, cluster | target metadata | already-present | already-present |
| C4F8-021 | 0004F8 | Source placement remains `NexusTK/ui/menu/RightButtonMenuPane.cpp` through UID0000N7. | very high | class/file route | target/class/file | already-present | already-present |
| C4F8-022 | 0004F8 | Emitter must change from blank to UID0000C0. | very high | source body and owner closure | target metadata | incorporate | applied |
| C4F8-023 | 0004F8 | Destructor source position should be `30`. | high | ordinary destructor ordering precedent | target metadata | incorporate | applied |
| C4F8-024 | 0004F8 | Target score should move `87/89 -> 92/94`. | high | all named blockers closed | target metadata/score rationale | incorporate | applied |
| C4F8-025 | 0004F8 | No split, merge, range extension, or reclassification is needed. | very high | exact functions/padding | target range analysis | already-present | already-present |
| C4F8-026 | 0004F8 | Old helper/member-name no-code proof is superseded and must be preserved as dated history. | very high | current closure vs target text | target history | historicalize | applied |
| C4F8-027 | 0004F8 | Class page must record exact destructor source body and direct Pane plus Singleton inheritance. | high | MCP RTTI and target lowering | by-class/RightButtonMenuPane.md | incorporate | applied |
| C4F8-028 | 0004F8 | File page must move UID0004F8 from blank child to emitting ordinary destructor. | very high | target closure | by-file/RightButtonMenuPane.md | incorporate | applied |
| C4F8-029 | 0004F8 | UID0001FX split index must historicalize its UID0004F8 helper-name blocker. | very high | child closure | RightButtonMenuPaneCore support | historicalize | applied |
| C4F8-030 | 0004F8 | Constructor support may record the now-proven direct Singleton base and field offsets without claiming constructor emission. | high | MCP 711/714/720 | constructor support | incorporate | applied |
| C4F8-031 | 0004F8 | UID0001G2 must historicalize "ordinary destructor still needs source pass" while remaining blank ABI glue. | very high | target closure; MCP 712 | scalar-wrapper support | historicalize | applied |
| C4F8-032 | 0004F8 | Singleton storage page must record direct Singleton-base RTTI/PMD and compiler-lowered destructor clear. | high | MCP 713-715/720/721 | singleton support | incorporate | applied |
| C4F8-033 | 0004F8 | Existing MapPane layout name/type is accepted without change. | very high | UID00042K | target references | already-present | already-present |
| C4F8-034 | 0004F8 | Existing `g_activeMapPane` global name/type is accepted without change. | very high | UID0000PR | target references | already-present | already-present |
| C4F8-035 | 0004F8 | Existing LivingObjectPane formal name `SetHighlightState` is accepted over stale aliases. | high | UID0003Z5/class formal | target references | already-present | already-present |
| C4F8-036 | 0004F8 | Existing Pane names RemoveFromLayer/UnregisterEventHandler are accepted without renaming. | very high | Pane layout/vtable | target references | already-present | already-present |
| C4F8-037 | 0004F8 | Historical command16594 generated file omitted UID0004F8 and its destructor body before the callback. | very high | command16594 file readback | generated historical-state evidence | already-present | already-present |
| C4F8-038 | 0004F8 | After callback validation, generated file should contain UID0004F8 and one ordinary destructor body with no target empty marker. | high | command16666 generated readback | generated verification checklist | incorporate | applied |
| C4F8-039 | 0004F8 | Supervisor manual coverage requires no-loss target/family row synchronization. | very high | current manual roots | exact handoff section | incorporate | applied |
| C4F8-040 | 0004F8 | No IDA rename/type/comment mutation is authorized in this callback. | very high | assignment restriction | IDA recommendations | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Exact target boundary and exact four direct callees are live-MCP confirmed.
- The scalar wrapper reproduces the target cleanup before adding unmistakable compiler delete-flag behavior.
- Current accepted support docs independently resolve all four raw helper labels and the raw global/member access.
- RTTI proves the direct `Singleton<RightButtonMenuPane>` base at `+0xf8`, explaining the global clear without handwritten source.
- Three vtable views and their exact constructor/destructor/wrapper stores prove class identity and inherited Pane facets.
- Existing ParcelIconPane ordinary-destructor treatment provides a project-local source-lowering precedent: emit handwritten cleanup, exclude Singleton clear and implicit Pane teardown.
- The strongest inference chain is complete and non-circular: binary operation -> typed current support evidence -> class/base lowering -> exact source expression.

## IDA MCP Facts

- Function/range facts:
  - constructor `0x00554b40`, size `0x56`;
  - ordinary destructor `0x00554ba0`, size `0x93`;
  - no function at `0x00554c33`;
  - successor OnEvent `0x00554c40`, size `0x319`;
  - scalar deleting wrapper `0x00556240`, size `0xd4`.
- Data/table/padding facts:
  - ten `0xcc` bytes separate constructor end `0x00554b96` from target start;
  - thirteen `0xcc` bytes separate target end `0x00554c33` from OnEvent start;
  - target vptr stores use `0x00622f68`, `0x00622fbc`, `0x00622fec`;
  - singleton storage is `0x0069b4f0`.
- Xref facts:
  - ordinary target start has zero inbound xrefs;
  - each vtable base has exactly constructor, ordinary destructor, and scalar wrapper data refs;
  - singleton storage has ten refs, including both destructor clears.
- Vtable/global/type facts:
  - primary RTTI hierarchy has seven entries;
  - direct Singleton BCD uses type descriptor `0x00678c30`, PMD `+0xf8/-1/0`, attributes `0x40`;
  - Pane supplies EventHandler and TimerHandler inherited facets at `+0xa0/+0xa4`.
- Negative IDA facts:
  - no source symbol preserves the original destructor/helper/member spelling;
  - no target call path indicates a separate file-local helper or alternate owner;
  - no ordinary target delete flag or free call exists.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00554b40-0x00554b96` | UID0004F7 constructor | source constructor | TRUE | UID0000C0 | `88/90` | Support; direct Singleton base/layout evidence strengthened, formal remains separate work. |
| `0x00554b96-0x00554ba0` | ignored alignment | compiler padding | FALSE | none | `100/100` | Ten `0xcc` bytes. |
| `0x00554ba0-0x00554c33` | UID0004F8 target | ordinary non-deleting destructor | TRUE | UID0000C0 | `92/94` | Implemented emitter UID0000C0, position 30, and exact formal destructor. |
| `0x00554c33-0x00554c40` | ignored alignment | compiler padding | FALSE | none | `100/100` | Thirteen `0xcc` bytes. |
| `0x00554c40-0x00554f59` | UID0004F9 OnEvent | source virtual method | TRUE | UID0000C0 | `88/90` | Adjacent successor, excluded from target. |
| `0x00556212-0x00556228` | UID0001G0 thunks | deleting-destructor adjustors | FALSE | none | `88/92` | Compiler-only. |
| `0x00556240-0x00556314` | UID0001G2 scalar wrapper | scalar deleting destructor ABI glue | TRUE/no handwritten body | UID0000C0 | `88/93` | Remains blank formal by exact no-code proof. |
| `0x00622f64-0x00622ff4` | UID0003CX vtable data | RTTI/vtable support | TRUE/source-induced data | UID0000C0 | `87/92` | Separate support. |
| `0x0069b4f0-0x0069b4f4` | UID00029Z singleton | global storage | TRUE/source-induced data | UID0000C0 | `87/92` | Direct Singleton base lifecycle support. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00554ba0` | no inbound xrefs | Ordinary body is represented separately from inlined/duplicated deleting wrapper; no alternate owner is implied. |
| `0x00554bf0` | call `0x0053b1b0` | `LivingObjectPane::SetHighlightState(false)`. |
| `0x00554c06` | call `0x00544ce0` | `Pane::RemoveFromLayer()`. |
| `0x00554c0d` | call `0x00544d70` | `Pane::UnregisterEventHandler()`. |
| `0x00554c14` | write `0x0069b4f0 = 0` | Direct Singleton base destruction effect. |
| `0x00554c1e` | call `0x00544580` | Implicit `Pane::~Pane()`. |
| `0x00622f68` | refs `0x00554b70/0x00554bc5/0x00556265` | Primary class vptr lifecycle. |
| `0x00622fbc` | refs `0x00554b76/0x00554bcb/0x0055626b` | EventHandler-adjusted facet vptr lifecycle. |
| `0x00622fec` | refs `0x00554b80/0x00554bd5/0x00556275` | TimerHandler-adjusted facet vptr lifecycle. |
| `0x0069b4f0` | ten xrefs | Constructor publish, ordinary/scalar clears, and live menu consumers. |

## Documentation Evidence And IDA Status

- Existing docs supporting the conclusion:
  - MapPane layout and g_activeMapPane pages already carry the exact field/global names and type.
  - LivingObjectPane and Pane formal/support pages already carry the exact helper names.
  - RightButtonMenuPane scalar-wrapper page already assigns handwritten cleanup to UID0004F8.
  - RightButtonMenuPane vtable/singleton pages already establish the class lifecycle.
- Pre-callback stale/incomplete docs now reconciled:
  - target no-code proof and blank emitter are historicalized/replaced by exact source closure;
  - class/file rows now identify UID0004F8 as the emitting ordinary destructor;
  - UID0001FX retains its old UID0004F8 blocker only as labeled history;
  - UID0001G2 no longer calls the ordinary destructor a future source pass and remains blank ABI glue;
  - singleton page now carries direct Singleton RTTI/PMD and compiler-lifecycle explanation.
- Generated/coverage report state:
  - historical generated command16594 omitted UID0004F8 entirely;
  - historical callback checkpoints command16650/16659/16662 and latest observed command16666 each contain UID0004F8 and the ordinary destructor exactly once with no target empty marker;
  - current manual by-memory coverage lacks a UID0004F8 row and has stale UID0001FX/UID0001G2 rows;
  - current class/file manual rows predate the split/destructor closure.

## Ranked Ownership Analysis

### 1. RightButtonMenuPane class and source file

- Evidence for: exact RightButtonMenuPane vptr stores, exact singleton lifecycle, contiguous method cluster, direct class parent, source root, scalar wrapper, and RTTI.
- Evidence against: none.
- Decision: direct owner UID0000C0; output reaches `NexusTK/ui/menu/RightButtonMenuPane.cpp` through UID0000N7.

### 2. Pane

- Evidence for: three direct cleanup calls belong to Pane methods/base teardown.
- Evidence against: target installs RightButtonMenuPane vtables, clears RightButtonMenuPane singleton state, and is paired with the RightButtonMenuPane scalar wrapper. Pane is a dependency/base owner only.
- Decision: reject as direct owner.

### 3. MapPane or LivingObjectPane

- Evidence for: target mutates a MapPane field and invokes a LivingObjectPane method.
- Evidence against: both are consumed objects; neither owns the destructor, vtables, singleton, range, or source cluster.
- Decision: reject as direct owner.

### Proposed new file/grouping, if applicable

- Not applicable. Existing class/file route is exact.

## Source Placement

- Applied placement: member definition in `NexusTK/ui/menu/RightButtonMenuPane.cpp`.
- Applied semantic owner/emitter: [UID:0000C0] `RightButtonMenuPane`.
- Why: all lifecycle, RTTI, vtable, singleton, adjacent method, and existing project source-tree evidence converges on this class/file.
- Rejected placements:
  - `Pane.cpp`: owns inherited callees, not the derived destructor.
  - `MapPane.cpp`: owns the highlighted-object slot, not the menu destructor.
  - `LivingObjectPane.cpp`: owns `SetHighlightState`, not the caller.
  - separate destructor file: no source-tree or binary evidence.
- Remaining placement uncertainty: none.

## Range / Split / Padding / Reclassification Analysis

- Exact target is one modeled function `[0x00554ba0,0x00554c33)`.
- Preceding constructor is separate `[0x00554b40,0x00554b96)`.
- `0x00554b96-0x00554ba0` is ten bytes of `0xcc` alignment.
- `0x00554c33-0x00554c40` is thirteen bytes of `0xcc` alignment.
- Successor OnEvent begins exactly at `0x00554c40`.
- UID0001G0 and UID0001G2 remain separate compiler ABI support ranges.
- No child creation, split, merge, reclassification, range extension, or ignored-ledger change is required.
- UID0001FX remains a non-emitting split index; UID0004F8 becomes one of its exact source-emitting children.

## Negative Evidence Summary

- No direct caller xref to `0x00554ba0`; this does not disprove a source destructor because the scalar wrapper duplicates the body and the vtables route through compiler-generated deleting entrypoints.
- No original project symbol proves exact method/member spelling; current accepted source vocabulary and behavior provide high-probability human names.
- No evidence supports hand-writing `g_pRightButtonMenuPane = NULL`; direct Singleton RTTI and constructor lowering reject that shape.
- No evidence supports hand-calling `Pane::~Pane()`; normal C++ reverse base destruction generates it.
- No evidence supports explicit vptr fields or assignments; RTTI/vtable lifecycle proves compiler lowering.
- No evidence supports a target-local helper or separate file.
- No evidence supports adding null protection for `g_activeMapPane`.
- The generated `SetHighlighted` alias is rejected for this target because current LivingObjectPane declaration and exact helper page use `SetHighlightState`.

## IDA Rename / Type / Comment Recommendations

- Source-facing names/types:
  - `sub_554BA0` -> `RightButtonMenuPane::~RightButtonMenuPane`.
  - `sub_53B1B0` -> `LivingObjectPane::SetHighlightState(bool)`.
  - `sub_544CE0` -> `Pane::RemoveFromLayer()`.
  - `sub_544D70` -> `Pane::UnregisterEventHandler()`.
  - `sub_544580` -> `Pane::~Pane()`.
  - `dword_67A764` -> `MapPane *g_activeMapPane`.
  - `MapPane+0x104` -> `LivingObjectPane *m_highlightedObjectPane`.
  - `unk_69B4F0` -> `RightButtonMenuPane *g_pRightButtonMenuPane`.
- Evidence for each is detailed in Heuristic Reanalysis and live MCP requests `709`, `713`, `716-721`.
- No IDA DB edit was requested or made. Current assignment permits report-only evidence, not mutation.
- A future supervisor-authorized IDA pass could apply these names/types, but report acceptance does not depend on mutating IDA.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Exact managed target header/block:

```cpp
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000C0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000C0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
RightButtonMenuPane::~RightButtonMenuPane()
{
    if (g_activeMapPane->m_highlightedObjectPane != NULL)
    {
        g_activeMapPane->m_highlightedObjectPane->SetHighlightState(false);
        g_activeMapPane->m_highlightedObjectPane = NULL;
    }

    RemoveFromLayer();
    UnregisterEventHandler();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Recommended Item Summary:
  - `Exact ordinary RightButtonMenuPane destructor body clears the active MapPane highlighted LivingObjectPane through SetHighlightState(false), nulls m_highlightedObjectPane, removes the pane from its layer, and unregisters its inherited event handler; direct Singleton clearing, Pane base destruction, vptr restores, EH scaffolding, and scalar-delete behavior remain compiler lowering.`
- Behavior preservation:
  - preserves unconditional dereference of `g_activeMapPane`;
  - preserves conditional highlighted-pointer check;
  - preserves call-before-null order;
  - preserves RemoveFromLayer before UnregisterEventHandler;
  - relies on reverse direct-base destruction for singleton clear then Pane teardown.
- Original-source shape:
  - normal human C++ destructor;
  - no IDA labels, explicit vptr manipulation, manual base destructor, or scalar-delete flags;
  - current project `NULL`/`false` and class/member naming conventions.
- Inferred source-facing names used instead of raw labels: all seven names listed in IDA Rename / Type / Comment Recommendations.
- Reason code should remain blank: not applicable. The old no-code proof is superseded.

## Final Recommendation

- The exact target metadata/formal block above is applied and generated.
- Keep parent UID0000C0 and file route UID0000N7.
- Keep UID0001FX non-reconstructable/non-emitting as a split index.
- Keep UID0001G0 non-emitting compiler thunks.
- Keep UID0001G2's formal block blank as compiler-generated scalar deleting destructor glue.
- Historicalize the old helper/member/destructor-variant blockers; do not delete them.
- Exact ordinary support destinations below are synchronized.
- Supervisor still must apply/rebase the six exact manual coverage rows after fresh review of the current roots.
- No out-of-scope future investigation is required for UID0004F8 source emission. Broader RightButtonMenuPane constructor/OnEvent/paint/background/border source work remains separate and must not be represented as a blocker on this destructor.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md`.
- Callback disposition: applied and independently read back by B004.
- Exact facts incorporated:
  - live MCP session and request evidence;
  - exact ordinary non-deleting variant;
  - exact caller/callee/xref inventory;
  - exact vtable triad and RTTI interpretation;
  - exact typed global/member/helper names;
  - source-vs-compiler lowering;
  - scalar-wrapper parity and boundaries;
  - exact positive/negative evidence and rejected alternatives.
- Applied metadata changes:
  - `87/89 -> 92/94`;
  - owner unchanged `0000C0`;
  - reconstructable unchanged true;
  - emitter blank -> `0000C0`;
  - position blank -> `30`;
  - blank formal -> exact destructor block.
- Applied historical preservation:
  - retain the former no-code rationale under a dated "Historical Superseded Blocker" section;
  - state exactly that it was reasonable before helper/global/member/direct-base synchronization and is now superseded.

## Recommended Support Doc Changes

All ordinary support changes in this section were applied under the accepted callback and read back at report-level detail. The exact six manual coverage rows remain supervisor-owned and are not ordinary-doc callback edits.

### `by-class/RightButtonMenuPane.md`

- Preserve all method/action/packet-helper evidence.
- Update UID0004F8 method-map row to identify the exact three handwritten actions and compiler-lowered exclusions.
- Add direct source inheritance evidence: `Pane` plus `Singleton<RightButtonMenuPane>`, with the Singleton empty-base descriptor at `+0xf8`.
- Add layout/lifecycle evidence without overclaiming a complete class formal:
  - total allocation/object size `0x144`;
  - inherited Pane prefix through `+0xf8`;
  - direct empty Singleton base overlapping `+0xf8`;
  - existing right-click state fields at `+0xf8/+0xf9/+0xfc/+0x100`;
  - inherited EventHandler/TimerHandler facets at `+0xa0/+0xa4`.
- Keep class score `86/89`, owner/emitter, and blank class formal unchanged because other class children remain incomplete.
- Preserve packet-helper and generated-owner caveats as separate issues.

### `by-file/RightButtonMenuPane.md`

- Update Proposed Contents and split history so UID0004F8 is an emitting ordinary destructor child, not a blank helper-name-blocked child.
- Record source lowering and exact source placement.
- Keep file score `86/88`; one child closure does not finish the broad file.
- Preserve all packet-helper liveness, VoteMenuPane boundary, and generated-owner history.

### `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md`

- Preserve the non-emitting split-index disposition.
- Update UID0004F8 child status to `92/94`, emitter UID0000C0, position 30, and formal destructor.
- Historicalize the old "teardown helper/client-slot names block destructor C++" statement.
- Do not add aggregate C++.

### `by-memory/0x00554b40-0x00554b96.RightButtonMenuPaneConstructor.md`

- Add the direct `Pane` plus `Singleton<RightButtonMenuPane>` RTTI/PMD evidence and field-layout facts discovered here.
- Preserve constructor score/emitter/formal pending a constructor-specific source pass; this report does not claim UID0004F7 coverage.
- Clarify that direct-base layout itself is no longer the constructor blocker.

### `by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md`

- Preserve exact no-code proof and `88/93`.
- Historicalize statements that UID0004F8 still needs a future helper/name/source pass.
- State that UID0004F8 now emits the source-authored destructor and UID0001G2 remains compiler ABI glue.

### `by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md`

- Preserve storage, initialization, ten xrefs, boundaries, and consumer evidence.
- Add direct `Singleton<RightButtonMenuPane>` RTTI/PMD `+0xf8/-1/0` evidence.
- Explain constructor publish and ordinary/scalar clear as inlined template base lifecycle.
- Keep current score/metadata/formal unchanged.

### Already sufficient support, no edits required

- `by-type/by-struct/MapPaneLayout.md`: already defines `LivingObjectPane *m_highlightedObjectPane` at `+0x104`.
- `by-global/g_activeMapPane.md`: already defines `MapPane *g_activeMapPane`.
- LivingObjectPane helper/class docs: already define `SetHighlightState(bool)`.
- Pane layout/vtable/file docs: already define `RemoveFromLayer`, `UnregisterEventHandler`, and `Pane::~Pane`.
- RightButtonMenuPane vtable page: already records primary/adjusted tables and destructor slots.

## Score And Metadata Recommendation

- Pre-callback target: `87/89`, owner `0000C0`, reconstructable true, blank emitter/position/formal.
- Current implemented target: `92/94`, owner `0000C0`, reconstructable true, emitter `0000C0`, position `30`, exact formal destructor.
- Score rationale:
  - completion rises five points because helper names, field/global names, destructor variant, source lowering, emitter route, and formal C++ are all closed;
  - confidence rises five points because live MCP, accepted typed support docs, RTTI, scalar-wrapper parity, and project-local Singleton destructor precedent independently converge.
- Reason not higher:
  - original source spellings are inferred rather than symbol-proven;
  - the broader class still has unresolved constructor/event/paint/resource source work;
  - scores at or above 95 are reserved for significantly final code and broader declaration consistency.
- Reason not lower:
  - there is no unresolved behavior, owner, range, helper, member, type, emitter, or C++ blocker for this exact destructor.
- Support metadata:
  - class stays `86/89`;
  - file stays `86/88`;
  - core split stays `90/92`, reconstructable false, blank emitter;
  - constructor stays `88/90`, blank emitter/formal;
  - scalar wrapper stays `88/93`, owner/emitter UID0000C0, blank formal by no-code proof;
  - singleton stays `87/92`, owner/emitter UID0000C0, blank formal.

## Open Questions With Attempted Resolution

- Original spelling of highlight helper:
  - checked live body, LivingObjectPane formal declaration/definition, generated MapPane aliases, and older reports;
  - resolution: use canonical current `SetHighlightState(bool)`, preserve `SetHighlighted`/`SetTargetHighlight` as rejected historical aliases.
- Original spelling of MapPane field:
  - checked exact offset, typed MapPane layout, generated MapPane declaration, and consumers;
  - resolution: `m_highlightedObjectPane`.
- Whether to use a local pointer:
  - checked target register/data-flow shape and post-call global reload;
  - resolution: direct repeated global/member expressions better match observed code generation.
- Whether singleton clear is handwritten:
  - checked constructor lowering, ten singleton xrefs, RTTI BCD/PMD, and analogous Singleton-derived pane destructors;
  - resolution: compiler-generated direct-base destruction.
- Whether Pane helper/base calls are handwritten:
  - checked exact helper bodies and Pane destructor;
  - resolution: RemoveFromLayer/UnregisterEventHandler are explicit derived-body actions; final Pane destructor is implicit base teardown.
- Whether zero inbound xrefs blocks source emission:
  - checked vtables, thunks, scalar wrapper, and ordinary/scalar sequence parity;
  - resolution: no. ABI generation explains reachability and duplication.
- Remaining unresolved question: exact original identifier spellings cannot be proven without symbols/source, but current names are high-probability, consistent, behavior-specific, and implementation-safe. This does not cap the target below draft emission.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current manual roots were read only before and after the callback. B004 did not edit them. UID0001FX, UID0001G2, UID00029Z, UID0000C0, and UID0000N7 each still occur once at the anchors below; UID0004F8 remains absent and still needs the exact insertion below.

### Current root identities

- `by-memory/-coverage-report.md`: SHA256 `A7D812B60CB35399C541461DC0E214A8380B61D7793E2BB499B9247449A1A70B`, 1,982,596 bytes, 4,564 lines.
- `by-class/-coverage-report.md`: SHA256 `E4F6985825BD360CD322C6099EC097CF87E7597BCD9F328E500829A02937875E`, 257,808 bytes, 624 lines.
- `by-file/-coverage-report.md`: SHA256 `78B5F2C81A5BDD86AC67655EA7152F0FC8541F1AF5A7DACF8EB7AB7ACB2B0D90`, 154,448 bytes, 317 lines.

### by-memory parent replacement

Replace current UID0001FX row at line 3011 without deleting any valid old fact:

```text
    - [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md) 0x00554b40-0x0055577b | non-emitting split index | RightButtonMenuPaneCore : not_reconstructable : 90% : very-strong : Reviewed right-click gameplay context-menu split index with exact constructor/destructor/event/cancel/paint/background/border/row-rect/hit-test child ranges, source-authored child rebuild handling, RightButtonMenuPane class/file attachment, generated BulletinSession hit-test ownership correction, singleton/vtable/vote-popup relationships, adjacent packet-helper separation, and compiler jump-table/padding exclusions; UID0004F8 is now source-closed as the ordinary destructor while remaining child-specific C++ blockers stay documented.
```

### by-memory target insertion

Insert immediately after the UID0001FX row and before the existing `0x0055577b-0x00555780` padding row:

```text
        - [UID:0004F8][0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor](by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md) 0x00554ba0-0x00554c33 | ordinary destructor | RightButtonMenuPaneDestructor : reconstructable : 92% : very-strong : Exact ordinary non-deleting RightButtonMenuPane destructor clears g_activeMapPane->m_highlightedObjectPane through LivingObjectPane::SetHighlightState(false), nulls the slot, calls inherited RemoveFromLayer and UnregisterEventHandler, and emits through UID0000C0 at position 30; three vptr restores, direct Singleton<RightButtonMenuPane> clear, implicit Pane teardown, EH scaffolding, adjustor thunks, scalar-delete flags, and operator delete are preserved as compiler lowering rather than handwritten source.
```

### by-memory scalar-wrapper replacement

Replace current UID0001G2 row at line 3040 without deleting its wrapper proof:

```text
    - [UID:0001G2][0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor](by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md) 0x00556240-0x00556314 | scalar deleting destructor wrapper | RightButtonMenuPaneScalarDeletingDestructor : reconstructable : 88% : very-strong : Exact 0xd4 compiler-generated RightButtonMenuPane scalar deleting destructor with three vtable restores, highlighted-object cleanup through g_activeMapPane+0x104, Pane cleanup helpers, g_pRightButtonMenuPane clear, scalar-delete and flag-4 helper paths, adjustor-thunk and primary-vtable xrefs, no direct static callers, and exact padding; formal C++ remains blank ABI glue while UID0004F8 now owns and emits the source-authored ordinary destructor.
```

### by-memory singleton replacement

Replace current UID00029Z row at line 4501 without deleting storage/xref/boundary history:

```text
    - [UID:00029Z][0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton](by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md) 0x0069b4f0-0x0069b4f4 | global pointer | RightButtonMenuPaneSingleton : reconstructable : 87% : strong : Exact initialized g_pRightButtonMenuPane storage with ten direct xrefs, constructor publish, ordinary/scalar destructor clears, menu/open-state consumers, and exact neighboring singleton boundaries; live RTTI proves direct Singleton<RightButtonMenuPane> empty-base lifecycle at PMD +0xf8/-1/0, so source derives from the template while compiler lowering supplies publication/clear, and ownership remains UID0000C0.
```

### by-class replacement

Replace current UID0000C0 row at line 455 without deleting method/boundary/packet-helper facts:

```text
- [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md) : reconstructable : 86% : strong : Right-click target-menu class routed to RightButtonMenuPane.cpp with exact split method boundaries, target fields/actions, packet-helper island caveat, neighboring VoteMenuPane separation, singleton storage/lifecycle, destructor thunks/scalar-wrapper no-code handling, and three inherited Pane vtable facets; direct Pane plus Singleton<RightButtonMenuPane> RTTI now closes UID0004F8 as an emitting ordinary destructor while broader class declaration and remaining child source work keep the class at 86/89.
```

### by-file replacement

Replace current UID0000N7 row at line 232 without deleting source-root/generated-owner history:

```text
- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md) : reconstructable : 86% : strong : NexusTK/ui/menu/ right-click gameplay context-menu source with exact method boundaries, Look/Trade/Whisper/Group/Info behavior, target id/name fields, singleton storage/lifecycle, packet-helper liveness caveat, generated BulletinSession/global-owner corrections, destructor thunk/scalar-wrapper compiler handling, neighboring VoteMenuPane exclusions, and UID0004F8 source-closed as the emitting ordinary destructor; remaining constructor/event/paint/resource children keep the broad file below final completion.
```

### Tracker handling

- Do not manually edit `auto-generated/-ag-research-tracker.md`.
- Historical report-only tracker command16628/row1696 recorded the `87/89` blank-emitter state.
- Latest observed validator-owned tracker command16666, refreshed `2026-07-22T23:36:37-04:00`, source `foreground-generated-refresh`, SHA256 `E21076DC1AD30D15DB629B89373762CB61DD29A67697D94ECE01DBE92845AE47`, 1,635,363 bytes, 6,508 lines, records UID0004F8 at line3285 as `92/94`, combined `93.0`, reconstructable true, and zero report counts.
- The row remains under the not-covered reconstructable lifecycle queue because B004 cannot execute the report. Supervisor execution should refresh report counts and tracker placement.

### Reason B004 must not apply manual rows

- All `-coverage-report.md` roots are supervisor-only under the active workflow.
- Concurrent agents make manual root edits collision-prone.
- Supervisor must re-read current roots and merge any intervening unrelated facts before applying these no-loss replacements.

## Follow-Up Actions

- Supervisor:
  - perform fresh full Gate 1 on this exact post-callback artifact;
  - independently verify all 40 ledger claims and seven ordinary destinations for Gate 2;
  - re-read and apply/rebase the six manual rows serially against current roots;
  - validate manual roots and independently re-read generated output;
  - run report lifecycle execution only after current exact-artifact Gate 1/Gate 2 proof.
- A-agent actions: none.
- B004 remaining open actions: none. The accepted ordinary-doc callback, scoped validators, generated readback, ledger transition, checklist, manual handoff, and zero-lease verification are complete.
- B004 boundary: never edit manual coverage or execute the report.

## Confidence

- Recommendation confidence: very high.
- Score confidence: high for `92/94`.
- Remaining uncertainty: original source identifier spellings are inferred, not symbol-proven. Current names are canonical in project docs, internally consistent, and behavior-exact.
- No remaining uncertainty affects behavior, target boundary, owner, emitter, source placement, split, metadata disposition, or draft C++ eligibility.

## Validator Results

- All scoped commands ran serially from `E:\NTK\GhidraBridge\source-3\project-documentation` and exited `0` with `ok: 1`.
- Target: command `000000016636`, timestamp `2026-07-22T23:21:33-04:00`, `python .\tools\validator.py --mode file --file by-memory\0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md --apply --queue-timeout 240`; applied completion `92`, confidence `94`, emitter UID0000C0, position `30`, formal blank-to-block, three reference-index additions, projected stats update, generated refresh deferred.
- Class: command `000000016638`, timestamp `2026-07-22T23:22:17-04:00`, `python .\tools\validator.py --mode file --file by-class\RightButtonMenuPane.md --apply --queue-timeout 240`; projected stats update, generated refresh deferred.
- File: command `000000016641`, timestamp `2026-07-22T23:23:17-04:00`, `python .\tools\validator.py --mode file --file by-file\RightButtonMenuPane.md --apply --queue-timeout 240`; projected stats update, generated refresh deferred.
- Core: command `000000016642`, timestamp `2026-07-22T23:24:00-04:00`, `python .\tools\validator.py --mode file --file by-memory\0x00554b40-0x0055577b.RightButtonMenuPaneCore.md --apply --queue-timeout 240`; projected stats update, generated refresh deferred.
- Constructor: command `000000016645`, timestamp `2026-07-22T23:24:37-04:00`, `python .\tools\validator.py --mode file --file by-memory\0x00554b40-0x00554b96.RightButtonMenuPaneConstructor.md --apply --queue-timeout 240`; projected stats update, generated refresh deferred.
- Scalar wrapper: command `000000016648`, timestamp `2026-07-22T23:25:38-04:00`, `python .\tools\validator.py --mode file --file by-memory\0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md --apply --queue-timeout 240`; projected stats update, generated refresh deferred.
- Singleton/final generated wait: command `000000016649`, timestamp `2026-07-22T23:26:17-04:00`, `python .\tools\validator.py --mode file --file by-memory\0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md --apply --queue-timeout 240 --wait-generated`; one target reference-index addition, projected stats update, registry rebuild, generated metadata/report refresh, and `generated_refresh: completed`.
- Command16649 also reported broad pre-existing generator diagnostics (`autogen_children_fallback_insert:13`, `autogen_children_marker_missing:71`, `autogen_emitter_has_no_code:110`); no UID0004F8 target validation error occurred.
- Read-only queue inspection: command `000000016663`, timestamp `2026-07-22T23:34:43-04:00`, `python .\tools\validator.py --queue-status`, observed one unrelated processing job and zero queued/generated-refresh jobs; command `000000016664`, timestamp `2026-07-22T23:34:55-04:00`, repeated the same read-only command and confirmed zero queued/processing/generated-refresh jobs. Neither command validated, edited, or executed a report.
- Initial callback generated checkpoint command16650 and intervening commands16659/16662 are historical. Latest observed generated checkpoint is command `000000016666`, refreshed `2026-07-22T23:36:37-04:00`, source `foreground-generated-refresh`. `RightButtonMenuPane.cpp` SHA256 is `AC9708AE35A849D5FD0F88C642088C355F00BF5797A74483E2A44970DB546BA3`, 4,213 bytes, 126 lines; UID0004F8 and `RightButtonMenuPane::~RightButtonMenuPane` each occur once, UID0004F8 empty marker occurs zero times, UID0001G2 empty marker occurs once, and total empty markers remain five for unrelated/blank children.
- Report execution: not run and not probed.

## Changed Files

- Modified ordinary destinations:
  - `by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md`: SHA256 `3D3D5363BD3DAEC54ACF142571F06363DF47AF2F9161230C5C6EF2BEA7315DF0`, 9,545 bytes, 113 lines.
  - `by-class/RightButtonMenuPane.md`: SHA256 `D8844DA9C3B1978EB466CFBE0885AF5E95C20D58134DA8A6E3C26838234D42FA`, 21,832 bytes, 126 lines.
  - `by-file/RightButtonMenuPane.md`: SHA256 `195FB3F87489FC5B3EF489A23E9B8076E7FD66B819C010EDA462D16FE15BA070`, 20,290 bytes, 125 lines.
  - `by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md`: SHA256 `40239245297A4D522F0FAC4F6F3466B21780E843CE8A283C4733B6A60BCB7D7F`, 16,197 bytes, 153 lines.
  - `by-memory/0x00554b40-0x00554b96.RightButtonMenuPaneConstructor.md`: SHA256 `BD298EA85D85B52C9FA89B197F9E9DCFA4DBA140171C9890DB2A5A9B3C8002F0`, 5,913 bytes, 86 lines.
  - `by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md`: SHA256 `5B2D6F349C89896133FBBF014E664CEC25329D9BA6ACABB37F5689535A6E4C33`, 18,661 bytes, 126 lines.
  - `by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md`: SHA256 `63A808E69A2E822E71ECDDB9C232FBC3CF7B957A501A89C25DDF3B4122F0CBEF`, 5,963 bytes, 69 lines.
- Modified callback record:
  - `tools/leaser/Agents/Agent-B004/research/0004F8-RightButtonMenuPaneDestructor-source-quality.md`.
- Renamed: none.
- Leases: each of the seven ordinary destinations was leased only for its immediate edit/validator batch and released immediately; current B004 leases are zero.
- IDA changes: none.
- Validators: scoped commands `16636`, `16638`, `16641`, `16642`, `16645`, `16648`, and `16649`; read-only queue-status commands `16663`/`16664`; initial validator-owned generated checkpoint `16650`, intervening external checkpoints `16659`/`16662`, and latest observed external checkpoint `16666`.
- Manual coverage edits: none; the six exact supervisor-owned rows below remain pending supervisor application/rebase.
- Generated/tracker direct edits: none; changes were validator-owned.
- Lifecycle/archive/execute_report actions: none.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation accepted pre-callback SHA `26ED382A...E09E`.
- [x] Updated UID0004F8 target at report-level detail.
- [x] Applied exact UID0004F8 formal header/C++ block.
- [x] Applied target `87/89 -> 92/94`.
- [x] Set target emitter UID0000C0 and source position 30.
- [x] Preserved owner UID0000C0 and reconstructable true.
- [x] Historicalized the old helper/member/variant no-code proof without pruning it.
- [x] Updated by-class/RightButtonMenuPane.md with destructor/base/layout/source-lowering evidence.
- [x] Updated by-file/RightButtonMenuPane.md so UID0004F8 is no longer a blank child.
- [x] Updated UID0001FX split index child status without adding aggregate C++.
- [x] Added constructor support evidence without claiming constructor coverage or emission.
- [x] Updated UID0001G2 history while retaining blank compiler-wrapper C++.
- [x] Updated UID00029Z direct Singleton-base lifecycle evidence.
- [x] Confirmed MapPane/LivingObjectPane/Pane canonical names remain unchanged.
- [x] Transitioned all C4F8-001 through C4F8-040 Verification states only after the accepted callback and destination readback.
- [x] Verified no accepted detail, negative evidence, or historical assumption was pruned.
- [x] Leased each ordinary destination only immediately before edit and released immediately after validation.
- [x] Ran ordinary scoped validators serially only after callback authorization.
- [x] Read back generated RightButtonMenuPane.cpp through latest observed command16666; commands16650/16659/16662 retained as historical checkpoints.
- [x] Verified generated UID0004F8 exactly once.
- [x] Verified generated `RightButtonMenuPane::~RightButtonMenuPane` exactly once.
- [x] Verified no UID0004F8 empty marker.
- [x] Preserved UID0001G2 as one blank-formal compiler ABI marker.
- [x] Reconciled all six exact supervisor-owned manual rows against unchanged current roots and anchors.
- [x] Confirmed no `-coverage-report.md` was edited.
- [x] Confirmed no IDA mutation occurred.
- [x] Confirmed execute_report/lifecycle commands were neither run nor probed.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support details incorporated at report-level detail.
- [x] Verified each ledger claim independently against its destination before transition to `applied`, `already-present`, or `excluded-with-reason`; zero claims remain blocked.
- [x] Metadata/score/owner/emitter/position/C++ changes applied exactly.
- [x] Compiler-lowered effects remain excluded from handwritten C++.
- [x] Historical/stale assumptions and rejected alternatives preserved.
- [x] Open questions terminalized as resolved or evidence-backed inference.
- [x] Scoped validator command IDs/timestamps/results recorded.
- [x] Generated command/hash/metrics/counts recorded.
- [x] Remaining unapplied B004-accepted ordinary items: none.
- [x] Supervisor-only manual rows remain clearly handed off for application/rebase.
- [x] Current B004 leases are zero at return.
- [x] Report execution remains not run or probed by B004.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000016684","destination_path":"executed-b-agent-research/B004/0004F8-RightButtonMenuPaneDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0004F8-RightButtonMenuPaneDestructor-source-quality.md","timestamp":"2026-07-22T23:54:46-04:00","uid":"0004F8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
