** TARGET-REPORT-UID:000171 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID000171 IdleWatcher Ownership / Split Research


## Finalized Report / Current Recommendation

- Applied disposition: UID000171 is now a non-emitting split index over four source-authored methods, two compiler-generated destructor artifacts, and three ignored alignment spans.
- Final source disposition: `IdleWatcher` remains a standalone `NexusTK/app/IdleWatcher.cpp` class owned by UID0000K0. UID00006C emits the complete class declaration, including the inline state accessor required by the MainMenu consumer; UID0002VY emits the singleton global definition; and real children UID0004LE, UID0004LF, UID0004LG, and UID0004LH emit the constructor, ordinary destructor, activity-reset helper, and `TimerHandler::OnTimer` override.
- Implementation state: C171-001 through C171-043 are incorporated. Six children were registered serially as UID0004LE through UID0004LJ, all fifteen changed by-* pages passed scoped validation, final waited command `000000009557` completed generation, and no B001 implementation work remains.
- Confidence: high. Function boundaries, inheritance, field offsets, callback slot, timer arguments, lifecycle, source/ compiler separation, and source placement are directly established. Original private identifier spellings remain inferred and cap scores below 95 without blocking reconstruction.

## Supporting Research

- Historical phase boundary: this artifact began as the report-only assignment recorded in `Agent-B001/goal.md`; no by-* implementation occurred before supervisor Gate 1 accepted SHA256 `50A7AD40E4BA334D27957E9D8EA465100D3F84705CECCF3EB3312C3F8F9B2816`. The accepted implementation callback is now complete.
- Live IDA evidence was reacquired against NexusTK database session `c81909be` after fresh transport initialization. At 2026-07-13 08:33:18 EDT, `idb_list` returned exactly that active session with worker PID 15716 and `is_analyzing:false`; `server_health` returned `status:ok` with auto-analysis, Hex-Rays, and strings ready; bounded target lookup and byte reads succeeded.
- Historical generated baseline before implementation contained only Empty Emitter Markers for UID00006C, UID000171, and UID0002VY. B001's final waited validator `000000009557` superseded that baseline at `2026-07-13T09:24:01-04:00` with complete authored source and no UID000171 aggregate marker. A later external validator command `000000009580` restamped generated metadata at `2026-07-13T09:33:44-04:00`; read-only reinspection confirmed identical 59-line source content/order/counts apart from the generated command/timestamp header.
- Current Application documentation already places allocation/construction and shutdown deletion in `Application.cpp` while explicitly rejecting absorption of the `IdleWatcher` class implementation into that file. That distinction is preserved.
- Reproducible historical-report search used the target-specific expression `UID000171|0x004cfe60|0x004cff20|0x0069af1c|g_pIdleWatcher`; a separate exact `IdleWatcher\.cpp` search checked source-placement claims without treating generic `Application.cpp` matches as target reports.
- Active roots checked: `tools/leaser/Agents/Agent-B001/research/` through `Agent-B005/research/`. The only target-specific match was this current B001 report; B002-B005 returned no match. The exact `IdleWatcher.cpp` search likewise found only this report plus B001's current goal and the supervisor audit ledger, not another research artifact.
- Executed root checked: `executed-b-agent-research/B001/` through `B015/`. All eight target-specific matching reports were opened and classified:
  - `executed-b-agent-research/B007/0002H7-ApplicationStartup-source-quality.md` records only the `0x004f5fdc-0x004f5ffe` allocation/constructor caller, 256-byte size, 20000-ms argument, and explicit caller-not-owner conclusion.
  - `executed-b-agent-research/B008/0002H8-ApplicationShutdown-empty-emitter-source-quality.md` records only the shutdown `delete g_pIdleWatcher` lifecycle caller.
  - `executed-b-agent-research/B005/00034Q-TabPaneRawRectangleBuilder-source-quality.md` mentions only the preceding `0x004cfe5f-0x004cfe60` coverage/padding boundary.
  - `executed-b-agent-research/B001/000141-EventDispatcher-source-quality.md` matches only the adjacent EventDispatcher keyboard-storage endpoint `0x0069af1c`; it does not cover IdleWatcher code.
  - `executed-b-agent-research/B001/000170-TabPaneAndIconsPaneDestructorTail.md` records only that successor IdleWatcher starts at `0x004cfe60`, outside its target.
  - `executed-b-agent-research/B001/00034V-IconsPaneScalarDeletingDestructor-source-quality.md` uses `0x004cfe60` only as the successor-function boundary after IconsPane/TabPane compiler glue.
  - `executed-b-agent-research/B012/00004M-EventDispatcher-class-source-quality.md` records only that `0x0069af1c-0x0069af20` is `g_pIdleWatcher` and explicitly excludes it from EventDispatcher storage.
  - `executed-b-agent-research/B010/0000J7-EventDispatcher-empty-emitter-family-source-quality.md` records only the separate IdleWatcher global's seven-xref ownership boundary and excludes it from EventDispatcher UID0002AV.
- Archive roots checked at research time: `executed-b-agent-research/invalidated/` returned no target-specific or exact `IdleWatcher.cpp` match. Per-agent legacy `tools/leaser/Agents/Agent-B*/research/executed/` roots were enumerated, but none existed at that evidence time.
- Conclusion after the path-specific review: no active, executed, invalidated, or legacy-archive report directly researches UID000171, the complete `0x004cfe60-0x004cffaf` range, its `0x004cff20` callback, or its full source shape. Every historical match is an incidental caller, adjacency/boundary, or dependency/ownership-exclusion mention and is used only as corroborating lead evidence.

## Target

- Target UID: UID000171.
- Target path: `by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md`.
- Historical source queue origin: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; validator-owned tracker state was refreshed by final command `000000009557` and was not edited manually.
- Supervisor classification: the exact Gate-1-passed artifact entered a bounded implementation callback for aggregate/split, inheritance, timer, global, naming, placement, and C++ blockers; that callback is complete.
- Current target state: `92/94`, `CANONICAL_OWNER:NONE`, blank emitter/position/formal C++, `RECONSTRUCTABLE:FALSE`, and `Nested:0` split-index treatment.

## Current Target State

- UID000171 now enumerates exact children UID0004LE through UID0004LJ and three internal ignored spans; it owns no source body and cannot duplicate child emission.
- The four source children are class-owned/reconstructable at positions 30/40/50/60. The two compiler children are ownerless, non-reconstructable, non-emitting, and retain exact no-code proof.
- UID00006C now emits the complete class declaration at position 10, UID0002VY emits the exact zero-initialized global at position 20, and UID0000K0 retains standalone `NexusTK/app/` file ownership at `91/93`.
- Stale `Activate`, unsplit aggregate, `Application.cpp` absorption, manual Singleton global writes/clears, explicit padding members, and handwritten compiler-wrapper assumptions are preserved only as rejected/historical alternatives.
- UID0002VY remains the single exact page for `0x0069af1c-0x0069af20`; no duplicate by-global page was created.
- Related current docs checked: UID00006C class, UID0000K0 file, UID0002VY global, UID0003BP vtable/RTTI data, UID0000F0 TimerHandler, UID0001K8 timer wrappers, UID0000A2 Pane, Application startup/shutdown/file pages, EventDispatcher class/file/core, MainMenuPane core/vtable data, ignored memory ranges, generated source, coverage, tracker, and score context.
- Current artifact/lifecycle status: B001 completed the accepted callback at this externally owned report path. B001 leased only the actively edited by-* page, released every lease after its scoped validator, and ran no `execute_report`, report-lifecycle, move, or archive command. Report validation/execution/count/path/archive state remains external supervisor/validator-owned and is neither changed nor predicted here.

## Executive Recommendation

- Make UID000171 a `92/94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, non-emitting split index with blank position and formal C++. Its only structural role is to enumerate the exact children and preserve aggregate evidence.
- Create four class-owned reconstructable source children at `0x004cfe60-0x004cfeba`, `0x004cfec0-0x004cfee9`, `0x004cfef0-0x004cff20`, and `0x004cff20-0x004cff37`.
- Create two no-owner, non-emitting, non-reconstructable compiler children at `0x004cff37-0x004cff4d` and `0x004cff50-0x004cffaf`.
- Register `0x004cfeba-0x004cfec0`, `0x004cfee9-0x004cfef0`, and `0x004cff4d-0x004cff50` as internal ignored padding, preserving existing predecessor/successor rows.
- Raise UID00006C to `92/94`, UID0000K0 to `91/93`, UID0002VY to `91/94`, and UID0003BP to `91/94` with the exact metadata and evidence below.
- No current blocker remains for source emission. The only non-proof is exact original private spelling; period-plausible descriptive names are resolved through behavior and project convention.

## Supervisor Active Recheck

- The Gate 1 instruction assigned UID000171 independently and required live MCP evidence, a complete literal report, no pre-acceptance by-* edits, and resolution rather than deferral of aggregate, split, inheritance, timer, global, naming, placement, and C++ blockers. Exact SHA acceptance satisfied that phase boundary before callback work began.
- The required split repair is now applied because the interval interleaves authored bodies, compiler thunks, and padding.
- Every source-bearing child in scope has an exact range, source role, owner/emitter route, score, formal block, and generated-output expectation. Both compiler-only children have direct no-code proofs. No child is deferred.

## Inference Research Guidance Check

- `by-structure.md` and the workflow require mixed ranges to split before ownership/emission. Accordingly, address adjacency was not treated as proof that all six code bodies are handwritten source.
- Existing names and source placement were treated as hypotheses. `Activate` was rejected after checking the TimerHandler slot, state transitions, direct callers, and MainMenu consumer. `Application.cpp` ownership was rejected after checking dedicated class/global/vtable identity and current Application source-placement evidence.
- IDA facts are reported as exact boundaries, bytes, xrefs, RTTI PMDs, vtable slots, instructions, constants, and call arguments. Documentation facts are identified as current by-* contracts. Names, access control, and file organization are explicit source-quality inferences.
- Consumer xrefs were used to infer state meaning, not to assign ownership. The MainMenu read corroborates `m_isIdle`; it does not make MainMenu the owner.
- No current Wave2/Wave3 evidence was used. Any stale references encountered in broad searches were ignored under the current workflow.

## Heuristic / Inference Reanalysis And Validation

- Aggregate shape: exact function lookup and raw gap bytes prove six code ranges plus three internal `0xCC` spans. The aggregate-as-method model is rejected; a split index is required.
- Constructor role: startup allocates `0x100` bytes and invokes `0x004cfe60(20000)`. The body calls `Pane(4)`, publishes the complete object through the empty Singleton base route, initializes `+0xf8` true and `+0xfc` from the argument, and installs three vptrs. This resolves a source constructor with `unsigned int` millisecond interval.
- Ordinary destructor role: `0x004cfec0` has no direct code callers, restores derived vptrs, clears the singleton global, and tail-calls `Pane::~Pane`. The global clear is the inlined `Singleton<IdleWatcher>` base destructor and Pane teardown is implicit C++; the most faithful authored body is empty, not missing.
- Reset helper role: `0x004cfef0` clears `+0xf8`, removes this TimerHandler owner's pending timers, and schedules timer ID 0 with delay `+0xfc` and zero payload arguments. Both callers are in event routing immediately after pointer-event or key/text-event classification. `ResetIdleTimer` is therefore preferred over stale `Activate`, `StartTimer`, or generic scheduler names.
- Callback role: `0x004cff20` is tertiary vtable slot 1 on the `TimerHandler` subobject. It receives three callback arguments, ignores them, sets `+0xf8` true, schedules timer ID 0 with the same interval/zero payloads, and returns true. The source role is `bool OnTimer(int,int,int)` under the current TimerHandler contract.
- Field `+0xf8`: activity callers clear it, timer expiry sets it, and MainMenu reads it before sending a one-byte opcode-113 active-state notification. `m_isIdle` is the strongest descriptive source name. Because MainMenu is outside the class, a private field alone is not a compilable source explanation; the project convention of inline field accessors supports `bool IsIdle() const { return m_isIdle; }`, whose inlining exactly produces the observed direct load. Public-field access and hidden friendship have weaker evidence and are rejected.
- Field `+0xfc`: startup supplies 20000 and both scheduling sites pass it as the documented delay-millisecond argument. `unsigned int m_idleIntervalMs` is preferred over raw `int`, `m_timer`, or `m_timeout` because the wrapper contract and literal behavior are exact.
- Inheritance: RTTI gives seven descriptors and exact PMDs: IdleWatcher, Pane, GrafPort, LObject, EventHandler at `+0xa0`, TimerHandler at `+0xa4`, and empty `Singleton<IdleWatcher>` at `+0xf8`. Source inheritance is `Pane, Singleton<IdleWatcher>` because Pane already contributes the EventHandler and TimerHandler subobjects.
- Empty-base overlap: Singleton's PMD is `+0xf8`, the same offset used by the first derived data member. This is valid empty-base optimization, not evidence that the bool belongs to Singleton. Natural alignment accounts for `+0xf9-+0xfb`; no explicit padding field is needed.
- Vtable roles: primary slots 1-17 match Pane and only the deleting destructor differs. The `+0xa0` secondary table matches Pane's EventHandler table except its destructor adjustor. The `+0xa4` tertiary table contains the destructor adjustor and the real `OnTimer` override. The old generic secondary/tertiary ambiguity is resolved.
- Adjustor thunks: `0x004cff37` subtracts `0xa0` and jumps to the scalar deleting destructor; `0x004cff42` subtracts `0xa4` and makes the same jump. They contain no source-authored behavior and must not emit.
- Scalar deleting destructor: `0x004cff50` performs generated vptr restoration, inlined Singleton clear, Pane teardown, flag-controlled ordinary/guarded deletion, object-size `0x100` handling, and return-this ABI. It is compiler-generated and must remain non-reconstructable/non-emitting.
- Global: `0x0069af1c` is zero-initialized and has exactly seven meaningful references across constructor, ordinary/scalar destruction, event resets, shutdown, and MainMenu. Existing UID0002VY is the canonical source-definition page. A duplicate by-global document would create conflicting emission.
- Source placement: startup and shutdown remain Application-owned caller code, but the dedicated class, RTTI, vtables, global, timer behavior, and current Application file exclusion support a narrow standalone `NexusTK/app/IdleWatcher.cpp`.
- Return semantics: raw decompiler return propagation from timer wrappers is not source behavior. Current wrapper docs establish `void RemovePendingTimers()` and `void ScheduleTimer(...)`; the reset helper is `void`, while the callback's explicit AL=1 return is `bool true`.
- Original name status: `IdleWatcher` and established globals/classes are RTTI/documentation-backed. `OnTimer` is contract/slot-backed. `ResetIdleTimer`, `m_isIdle`, and `m_idleIntervalMs` are high-probability descriptive names rather than recovered debug symbols. That distinction is preserved and reflected in scores.
- Generated-output pollution: leaving UID000171 reconstructable would duplicate the child bodies; emitting scalar/adjustor/vtable bodies would encode compiler artifacts manually. The applied owner/emitter split prevents both errors.

## Evidence Standards Used

- Direct evidence: live `lookup_funcs`, `analyze_function`, decompilation, bounded `get_bytes`, integer/data reads, code/data xrefs, RTTI complete-object locators/base arrays, and vtable slot comparison.
- Strong corroboration: Pane layout, TimerHandler virtual contract, timer wrapper formal C++, Application startup/shutdown formal C++, file-placement notes, the historical marker baseline plus final fresh generated source, and direct consumer behavior.
- Inference evidence: period-plausible C++ source shape, established project naming, empty-base optimization, implicit base construction/destruction, and compiler deleting-destructor conventions.
- Negative evidence: no ordinary-destructor code xrefs, no handwritten behavior in adjustors/scalar wrapper, no additional target functions in internal gaps, no need for duplicate global ownership, and no evidence that Application owns the class body.
- The evidence ladder is sufficient for exact behavior and implementation shape. Confidence remains below 95 only because stripped symbols prevent proof of private spelling, exact access labels, and optional source qualifiers such as `explicit`.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks: fresh `idb_list`; `server_health`; lookups for all six functions; bounded bytes for functions, all gaps, global, RTTI, and vtables; `analyze_function`/decompilation for constructor, ordinary destructor, reset helper, callback, both adjustors, scalar destructor, startup, shutdown, EventDispatcher route, and MainMenu timer handler; code/data xrefs for every function/global/vtable route; RTTI hierarchy and PMD decoding; Pane-vtable slot comparison.
- Documentation checked: target UID000171; class UID00006C; file UID0000K0; global UID0002VY; vtable UID0003BP; TimerHandler UID0000F0; wrappers UID0001K8; Pane UID0000A2; Application startup/shutdown/file; EventDispatcher class/file/core; MainMenuPane core/vtable; `by-memory/-ignored.md`; generated source; generated by-memory coverage; research tracker; completion statistics; current goal; workflow/template; and relevant analogous split/compiler/singleton pages.
- Historical-search roots/results at research time: active `tools/leaser/Agents/Agent-B001/research/` through `Agent-B005/research/` yielded only this report; central `executed-b-agent-research/B001/` through `B015/` yielded the eight opened reports listed under Supporting Research; `executed-b-agent-research/invalidated/` yielded no match; and no per-agent legacy `research/executed/` directory existed.
- Exact opened historical paths/results: B007 `0002H7` is constructor-caller evidence; B008 `0002H8` is shutdown-caller evidence; B005 `00034Q`, B001 `000170`, and B001 `00034V` are predecessor/padding/successor boundary evidence; B001 `000141`, B012 `00004M`, and B010 `0000J7` are EventDispatcher/global exclusion evidence. None covers UID000171 directly.
- Search expressions: target-specific `UID000171|0x004cfe60|0x004cff20|0x0069af1c|g_pIdleWatcher`, plus exact source-placement term `IdleWatcher\.cpp`. Generic `Application.cpp` hits were not classified as target reports because the target-specific pass identifies the only relevant startup/shutdown artifacts above.
- Explicit no-direct-report result: no active, central-executed, invalidated, or legacy-archive artifact directly researches the assigned UID/range/callback/source shape; all historical matches are incidental caller, adjacency, dependency, or ownership-exclusion mentions.
- Negative checks: no code inside the three internal padding spans; no ordinary-destructor direct caller; no non-vtable callback route; no extra target global; no separate handwritten source behavior in compiler wrappers; no justified `Application.cpp` absorption; no unaccounted interval/flag xrefs within the checked routes.
- Tool limitation: an early local PowerShell helper invocation used the reserved automatic `$args` variable and did not form a valid `tools/call` payload. It was discarded as client-side malformed input; the helper was corrected to `$toolArguments`, and all required valid bounded calls against `c81909be` succeeded. No conclusion relies on the malformed attempt.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C171-001 | Live session `c81909be` was healthy and target-backed calls succeeded. | Certain | idb_list, server_health, lookup/get_bytes at 2026-07-13 08:33:18 EDT | Report evidence/current state | Preserve evidence timestamp/session | Applied: evidence retained as research-time fact; no callback query was required. |
| C171-002 | UID000171 contains six exact functions, not one source body. | Certain | lookup_funcs/analyze_function boundaries | UID000171 | Convert to split index | Applied and validated by `000000009537`. |
| C171-003 | Three internal spans are `0xCC` alignment padding. | Certain | bounded raw bytes | `by-memory/-ignored.md` | Add three ignored rows | Applied and validated by `000000009552`; adjacent rows preserved. |
| C171-004 | Startup allocates `0x100` bytes and passes 20000 to the constructor. | Certain | Application startup decompile/callsite | UID0004LE; UID000171; Application startup already present | Incorporate; preserve already-present caller | Applied to UID0004LE/UID000171; Application caller remained already present and unchanged. |
| C171-005 | Constructor calls `Pane(4)`. | Certain | constructor instructions/call | UID0004LE | Emit exact initializer | Applied in managed block 3; validated by `000000009520`. |
| C171-006 | IdleWatcher has an empty `Singleton<IdleWatcher>` base at `+0xf8`. | Certain | RTTI hierarchy/PMD | UID00006C, UID0003BP, UID0004LE/UID0004LF | Incorporate | Applied across class/vtable/source children; validated by `000000009520`, `000000009522`, `000000009540`, and `000000009547`. |
| C171-007 | Complete inheritance chain and subobjects are Pane/GrafPort/LObject, EventHandler `+0xa0`, TimerHandler `+0xa4`. | Certain | RTTI and vtables | UID00006C, UID0003BP, UID000171 | Incorporate | Applied and validated by `000000009537`, `000000009540`, and `000000009547`. |
| C171-008 | `+0xf8` is the idle-state bool and `+0xfc` is the millisecond interval. | High | all writes/reads, timer wrapper contract, startup literal | UID00006C and source children | Use inferred names/types | Applied with explicit inferred-spelling caveat; corroborated in MainMenu support. |
| C171-009 | Existing UID0002VY is the exact zero-initialized singleton global with seven meaningful refs. | Certain | bytes/xrefs | UID0002VY | Upgrade/emit definition; no duplicate page | Applied at `91/94`, position 20; validated by `000000009543`; no duplicate page created. |
| C171-010 | Constructor source is the exact initializer-only block at position 30. | High | ctor behavior plus C++ base/member rules | UID0004LE | Create/register/emit | Applied; UID0004LE registered and validated by `000000009520`. |
| C171-011 | Ordinary destructor source body is empty; global clear and Pane teardown are implicit bases. | High | dtor body, Singleton patterns, zero direct callers | UID0004LF | Create/register/emit empty body | Applied; UID0004LF registered and validated by `000000009522`. |
| C171-012 | `0x004cfef0` is a void activity reset helper. | High | body, callers, wrapper contracts | UID0004LG | Name `ResetIdleTimer`; emit position 50 | Applied; UID0004LG registered and validated by `000000009524`. |
| C171-013 | Reset is called only after pointer or key/text activity classifications. | Certain | EventDispatcher callsites | UID000141; UID0004LG | Incorporate exact call context | Applied to both destinations; support page validated by `000000009553`. |
| C171-014 | `0x004cff20` is `TimerHandler::OnTimer`, not `Activate`. | Certain role/high spelling | tertiary slot and callback contract | UID0004LH; UID0003BP | Rename source role and emit | Applied; validated by `000000009527` and `000000009547`. |
| C171-015 | Both scheduling sites use timer ID 0, interval field, and zero/zero payloads. | Certain | call arguments and UID0001K8 contract | UID0004LG/UID0004LH | Emit exactly | Applied in managed blocks 5/6; validated by `000000009524`/`000000009527`. |
| C171-016 | MainMenu reads the idle bool, conditionally sends one-byte opcode 113 while active, then reschedules its own timer 1 for 20000. | Certain | MainMenu timer decompile/global xref | UID00036Y/UID0003BY | Incorporate as corroboration | Applied without score/C++ changes; validated by `000000009555`/`000000009556`. |
| C171-017 | Primary IdleWatcher vtable differs from Pane only in deleting destructor slot 0. | Certain | slot-by-slot table comparison | UID0003BP | Correct complete slot inventory | Applied and validated by `000000009547`. |
| C171-018 | `+0xa0` secondary table is EventHandler and differs only in destructor adjustor. | Certain | RTTI PMD/vtable comparison | UID0003BP | Correct subobject label/inventory | Applied and validated by `000000009547`. |
| C171-019 | `+0xa4` tertiary table is TimerHandler with destructor adjustor and OnTimer override. | Certain | RTTI PMD/vtable data | UID0003BP | Correct subobject label/inventory | Applied and validated by `000000009547`. |
| C171-020 | `0x004cff37-0x004cff4d` contains two compiler adjustor thunks. | Certain | instruction bodies/vtable refs | UID0004LI | Non-owner/non-emitting/no formal C++ | Applied; UID0004LI registered and validated by `000000009533`. |
| C171-021 | `0x004cff50-0x004cffaf` is a compiler scalar deleting destructor. | Certain | flags, delete calls, size, return ABI, vtable refs | UID0004LJ | Non-owner/non-emitting/no formal C++ | Applied; UID0004LJ registered and validated by `000000009535`. |
| C171-022 | Aggregate emission would duplicate child code. | Certain | split shape/generator model | UID000171 | owner NONE, false, blank emitter/formal | Applied; final output contains no UID000171 marker or aggregate body. |
| C171-023 | Six children must be created serially with validator-issued UIDs. | Certain | UID workflow | UID000171 and new pages | Never invent UIDs; link after issuance | Applied serially: UID0004LE, UID0004LF, UID0004LG, UID0004LH, UID0004LI, UID0004LJ. |
| C171-024 | UID000171 should be `92/94`, `Nested:0`, with complete child index/evidence. | High | all target blockers resolved | UID000171 | Apply score/metadata/body | Applied and validated by `000000009537`. |
| C171-025 | UID00006C should emit the complete declaration at position 10. | High | class/layout/source evidence | UID00006C | Apply `92/94` and block | Applied and validated by `000000009540`. |
| C171-026 | UID0002VY should emit `g_pIdleWatcher` at position 20. | High | exact global identity/lifecycle | UID0002VY | Apply `91/94`, Nested 0, block | Applied and validated by `000000009543`. |
| C171-027 | UID0000K0 remains the standalone file owner and should be `91/93`. | High | source placement and complete unit shape | UID0000K0 | Update file inventory/order/evidence | Applied and validated by `000000009545`; final wait `000000009557`. |
| C171-028 | UID0003BP remains class-owned evidence but needs no formal source block. | High | class declaration generates RTTI/vtables | UID0003BP | Apply `91/94`, exact tables, no-code proof | Applied and validated by `000000009547`; final output has metadata marker only, no vtable body. |
| C171-029 | Existing predecessor/successor ignored rows remain unchanged. | Certain | current ignored registry and bytes | `by-memory/-ignored.md` | Add only three internal rows | Applied exactly; validated by `000000009552`. |
| C171-030 | EventDispatcher support must record the two exact activity-reset routes. | Certain | direct callsites | UID000141 | Prose/evidence only; no score/C++ change | Applied at exact loads/calls `0x004a72f0/0x004a72f6` and `0x004a748a/0x004a7490`; validated by `000000009553`. |
| C171-031 | MainMenu core support must record the idle-state consumer behavior. | Certain | direct global read/body | UID00036Y | Prose/evidence only; no score/C++ change | Applied at report-level detail; validated by `000000009555`. |
| C171-032 | MainMenu vtable support should use the current `OnTimer` contract, not `OnTimerEvent`. | High | TimerHandler contract/table slot | UID0003BY | Normalize label/add corroboration; no score | Applied without score/C++ change; validated by `000000009556`. |
| C171-033 | Application, Pane, TimerHandler, and wrapper facts already exist at same-or-greater detail. | Certain | current docs | Named support pages | Preserve unchanged | Already present and preserved unchanged after callback re-read. |
| C171-034 | Source-facing private names are inferred, while behavior/type/offsets are exact. | High | naming analysis | All changed docs | Label inference honestly | Applied throughout target/class/method/support evidence. |
| C171-035 | No IDA database rename/type/comment mutation is required. | High | source docs can carry resolved names | Report recommendation | Keep IDB unchanged | Satisfied; no IDA mutation or process-management action performed. |
| C171-036 | No duplicate by-global page should be created. | Certain | exact UID0002VY page exists | UID0002VY/file docs | Preserve single definition route | Satisfied; only UID0002VY emits the definition. |
| C171-037 | Exactly six managed source blocks are required. | Certain | eligible destinations | UID00006C, UID0002VY, UID0004LE/LF/LG/LH | Apply complete blocks exactly | Applied exactly; no body-only C++ added. |
| C171-038 | Generated IdleWatcher.cpp must contain each source unit once and no aggregate/compiler/vtable duplicate. | High | emitter/position plan | Final generated verification | Wait for generated freshness and inspect | Satisfied by `000000009557`: each authored unit occurs once; no UID000171, adjustor, scalar, stale `Activate`, or manual vtable/RTTI body occurs. UID0003BP contributes only its expected empty metadata marker. |
| C171-039 | Recommended scores stay below 95 due stripped private spelling/header details. | High | score blocker audit | All scored destinations | Apply exact score table | Applied exactly; support prose updates received no score inflation. |
| C171-040 | `Activate`, Application absorption, manual global clear, and handwritten deleting wrappers are superseded. | High | direct evidence/source rules | Target/support histories | Historicalize, do not erase | Applied as rejected/historical alternatives across target/class/file/children. |
| C171-041 | Report-only phase permits no leases, by-* edits, or validators. | Certain | historical Gate 1 goal | Report Validator Results/Changed Files | Preserve boundary | Satisfied before Gate 1; implementation began only after exact SHA acceptance. |
| C171-042 | Callback validation must be scoped per changed by-* page, then one waited generated check. | Certain | workflow | Checklist/Validator Results | Run only after acceptance | Satisfied: fifteen scoped page validators plus final waited command `000000009557`, all exit 0/ok 1. |
| C171-043 | MainMenu's external direct load is best reconstructed through inline `IsIdle() const`, not private-member access from unrelated source. | High | direct `+0xf8` load plus current inline-accessor conventions | UID00006C; UID00036Y | Add accessor in managed class block and document inlining | Applied in UID00006C block and UID00036Y support; validated by `000000009540`/`000000009555`. |

## Positive Evidence Summary

- Exact boundaries account for every byte in the aggregate: six functions and three `0xCC` gaps.
- RTTI directly establishes the complete inheritance graph and exact subobject offsets, including the empty Singleton base at `+0xf8`.
- Constructor, ordinary destructor, scalar destructor, startup, and shutdown account for allocation, initialization, singleton publication/clear, base teardown, virtual deletion, and object size.
- Both EventDispatcher callers and the MainMenu consumer establish the flag's idle-state semantics; both method bodies establish the interval and timer contract.
- Three complete vtable views establish the primary Pane chain, EventHandler adjustor, TimerHandler adjustor, and sole semantic callback override.
- Existing source-tree documentation independently supports a dedicated `IdleWatcher.cpp` while retaining Application-owned startup/shutdown callsites.
- The inline `IsIdle()` source route explains the external MainMenu field load while retaining normal encapsulation and requiring no extra out-of-line child.
- The combined chain is sufficient to produce exact behavior without retaining decompiler labels or manually reconstructing compiler glue.

## IDA MCP Facts

- Function/range facts:
  - `0x004cfe60-0x004cfeba`: 0x5a-byte constructor.
  - `0x004cfec0-0x004cfee9`: 0x29-byte ordinary destructor.
  - `0x004cfef0-0x004cff20`: 0x30-byte reset helper.
  - `0x004cff20-0x004cff37`: 0x17-byte TimerHandler callback.
  - `0x004cff37-0x004cff42` and `0x004cff42-0x004cff4d`: two 0xb-byte deleting-destructor adjustors.
  - `0x004cff50-0x004cffaf`: 0x5f-byte scalar deleting destructor.
- Data/table/padding facts:
  - `0x004cfeba-0x004cfec0` is six `0xCC` bytes; `0x004cfee9-0x004cfef0` is seven; `0x004cff4d-0x004cff50` is three.
  - `0x0069af1c-0x0069af20` is zero-initialized storage for the complete-object pointer.
  - IdleWatcher vtable starts are `0x0061b56c`, `0x0061b5b8`, and `0x0061b5e8`.
- Xref facts:
  - Constructor caller: `0x004f5ffe`.
  - Ordinary destructor: no direct code xrefs.
  - Reset helper callers: `0x004a72f6` and `0x004a7490`.
  - Callback data xref: `0x0061b5ec`.
  - Adjustor data xrefs: `0x0061b5b8` and `0x0061b5e8`.
  - Scalar wrapper routes: primary vtable `0x0061b56c` plus both adjustor jumps.
  - Global references: reset reads at `0x004a72f0`/`0x004a748a`, constructor write `0x004cfe85`, ordinary clear `0x004cfeda`, scalar clear `0x004cff70`, shutdown read `0x004f6652`, MainMenu read `0x004f7679`.
- Vtable/global/type facts:
  - Complete-object locators are `0x006485fc` offset 0, `0x006486ac` offset `0xa0`, and `0x006486c0` offset `0xa4`, all for `.?AVIdleWatcher@@` and hierarchy `0x00648610`.
  - Hierarchy attributes indicate multiple inheritance and enumerate seven descriptors. Singleton's PMD has `mdisp 0xf8`, `pdisp -1`, `vdisp 0`.
  - Complete object size is `0x100`; startup initial interval is 20000 ms.
- Negative IDA facts: no executable bytes in internal gaps, no direct ordinary-destructor caller, no callback caller outside its TimerHandler slot, and no source-specific behavior in adjustor/scalar compiler bodies.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004cfe60-0x004cffaf` | UID000171 / existing target | Aggregate split index | False | None | `92/94` | Applied; non-emitting |
| `0x004cfe60-0x004cfeba` | UID0004LE / `by-memory/0x004cfe60-0x004cfeba.IdleWatcherConstructor.md` | Source constructor | True | UID00006C | `92/94` | Registered/emitting at position 30 |
| `0x004cfeba-0x004cfec0` | `by-memory/-ignored.md` | Alignment padding | N/A | N/A | N/A | Registered ignored |
| `0x004cfec0-0x004cfee9` | UID0004LF / `by-memory/0x004cfec0-0x004cfee9.IdleWatcherDestructor.md` | Source ordinary destructor | True | UID00006C | `91/94` | Registered/emitting at position 40 |
| `0x004cfee9-0x004cfef0` | `by-memory/-ignored.md` | Alignment padding | N/A | N/A | N/A | Registered ignored |
| `0x004cfef0-0x004cff20` | UID0004LG / `by-memory/0x004cfef0-0x004cff20.IdleWatcherResetIdleTimer.md` | Source activity-reset method | True | UID00006C | `92/94` | Registered/emitting at position 50 |
| `0x004cff20-0x004cff37` | UID0004LH / `by-memory/0x004cff20-0x004cff37.IdleWatcherOnTimer.md` | Source TimerHandler override | True | UID00006C | `92/94` | Registered/emitting at position 60 |
| `0x004cff37-0x004cff4d` | UID0004LI / `by-memory/0x004cff37-0x004cff4d.IdleWatcherDestructorAdjustorThunks.md` | Compiler MI adjustors | False | None | `90/94` | Registered; ownerless/non-emitting |
| `0x004cff4d-0x004cff50` | `by-memory/-ignored.md` | Alignment padding | N/A | N/A | N/A | Registered ignored |
| `0x004cff50-0x004cffaf` | UID0004LJ / `by-memory/0x004cff50-0x004cffaf.IdleWatcherScalarDeletingDestructor.md` | Compiler scalar deleting destructor | False | None | `92/94` | Registered; ownerless/non-emitting |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f5ff4-0x004f5ffe` | Allocates 256 bytes and calls constructor with 20000 | Exact object size and initial idle interval |
| `0x004a72f6` | EventDispatcher calls reset after pointer-event predicate | User pointer activity restarts timer |
| `0x004a7490` | EventDispatcher calls reset after key/text predicate | User keyboard/text activity restarts timer |
| `0x004cff20` via `0x0061b5ec` | TimerHandler tertiary vtable slot 1 | Exact `OnTimer` virtual role |
| `0x004cff37` via `0x0061b5b8` | EventHandler-subobject deleting adjustor | Compiler receiver correction `-0xa0` |
| `0x004cff42` via `0x0061b5e8` | TimerHandler-subobject deleting adjustor | Compiler receiver correction `-0xa4` |
| `0x004f6652` | Shutdown loads global and invokes virtual deleting destructor with flag 1 | Normal source `delete g_pIdleWatcher` route |
| `0x004f7679` | MainMenu timer reads complete `+0xf8` | Independent idle-state semantic corroboration |
| `0x004cfef0` / `0x004cff20` | Call UID0001K8 timer wrappers | Remove/reschedule and periodic callback contract |

## Documentation Evidence And IDA Status

- Existing supporting docs remained authoritative and unchanged where already at same-or-greater detail: Application startup records the 256-byte allocation and 20000 constructor argument; shutdown records virtual deletion; Application file documentation favors dedicated IdleWatcher source; TimerHandler and UID0001K8 establish callback and wrapper signatures; Pane establishes offsets and inherited subobjects.
- Superseded baseline docs are now repaired: aggregate metadata is split-index-safe; class/file/global/vtable scores and routes are current; `Activate` is historicalized; exact child pages carry source/compiler dispositions; and the old class/aggregate/global Empty Emitter Marker baseline is no longer current.
- Generated/coverage evidence at B001's final waited validator `000000009557`: `auto-generated/NexusTK/app/IdleWatcher.cpp` was fresh at `2026-07-13T09:24:01-04:00`, SHA256 `D9BB55C28A4F360E4F8033173AB2106407DCBEFDC662DCD5FCB975904C0DE652`, and contained all six authored units exactly once with no UID000171/adjustor/scalar/stale-Activate/manual-vtable body. The current externally restamped header is command `000000009580` at `2026-07-13T09:33:44-04:00`, SHA256 `D4FB943908B462F06C42056AA2B230AE002D3188B2E2A3E4E2A6EAFD564106BA`; read-only checks prove the same body lines/counts/order. B001 manually edited neither generated state.
- IDA status: session `c81909be` was healthy for all valid required reads. No mutation, rename, type application, analysis-start, or process-management action was performed.

## Ranked Ownership Analysis

### 1. UID0000K0 `NexusTK/app/IdleWatcher.cpp` with class UID00006C

- Evidence for: dedicated RTTI/class/global/vtables; compact method family; timer-specific state and behavior; current file page; current Application file explicitly rejects class absorption; startup/shutdown are ordinary external lifecycle callers.
- Evidence against: allocation and deletion occur in Application startup/shutdown, and the global is used by EventDispatcher/MainMenu.
- Decision: canonical file owner. External lifecycle and consumer references are dependencies, not ownership transfers.

### 2. `Application.cpp`

- Evidence for: sole allocation/construction caller and shutdown deletion route live in Application code.
- Evidence against: no target method bodies reside in the Application range; dedicated file/class/global docs already exist; RTTI/vtables and behavior define an independent class; current Application documentation explicitly keeps IdleWatcher separate.
- Decision: rejected as source placement. Preserve only startup/shutdown callsite documentation.

### 3. EventDispatcher or MainMenuPane

- Evidence for: EventDispatcher invokes reset on user activity; MainMenu reads the state bit.
- Evidence against: neither constructs, destroys, schedules the IdleWatcher timer directly, owns its vtables, or defines its class state. These are consumer routes only.
- Decision: rejected as owners; add support evidence without owner/emitter changes.

### Proposed new file/grouping, if applicable

- Applied owner/name/path: no new by-file page was needed; existing UID0000K0 remains at `NexusTK/app/IdleWatcher.cpp`.
- Likely full contents: complete class declaration with inline `IsIdle`, global definition, constructor, ordinary destructor, `ResetIdleTimer`, and `OnTimer` in positions 10 through 60.
- Candidate related items that belong: UID00006C, UID0002VY, and the four source children.
- Candidate related items rejected: UID000171 aggregate, adjustor child, scalar child, and UID0003BP vtable/RTTI data must not emit source bodies; Application/EventDispatcher/MainMenu bodies remain in their own files.
- Standalone, narrow, or broad inference: narrow standalone class implementation, not a broad Application aggregation.

## Source Placement

- Applied source file/class/global/module placement: `NexusTK/app/IdleWatcher.cpp`, existing file UID0000K0; class UID00006C at position 10; global UID0002VY at position 20; UID0004LE/LF/LG/LH at positions 30/40/50/60.
- This placement matches existing `NexusTK/app/` organization and the dedicated class/global/vtable identity while leaving startup and shutdown in Application code.
- `Application.cpp` is rejected because callsite ownership does not imply class-body ownership and the current Application file page expressly records separation.
- EventDispatcher and MainMenu source files are rejected because they only consume the public/global behavior.
- No placement blocker remains. Exact historical include/header split is not recoverable, but it does not alter the canonical `.cpp` route or emitted behavior.

## Range / Split / Padding / Reclassification Analysis

- Exact range facts: the aggregate begins at constructor `0x004cfe60` and ends after scalar deleting destructor at `0x004cffaf`. Function end boundaries and internal gaps are exact from IDA lookup plus raw bytes.
- Source children: constructor, ordinary destructor, reset helper, and OnTimer callback. Each is independently reconstructable and class-owned.
- Compiler children: the paired adjustor range and scalar deleting destructor. Both remain no-owner/non-emitting because normal inheritance/destructor source regenerates them.
- Padding: exactly the three internal `0xCC` spans were added. Existing ignored predecessor `0x004cfe5f-0x004cfe60` and successor `0x004cffaf-0x004cffb0` were preserved without widening or replacement.
- Parent/container impact: UID000171 now has `Nested:0`, a complete child index, false reconstructability, and no owner/emitter/formal block. Real child links were added only after each page received UID0004LE through UID0004LJ from its validator.
- Reclassification reason: mixed source/compiler/padding ranges cannot safely share one formal emitter; splitting removes duplicate coverage and makes no-code proof destination-specific.

## Negative Evidence Summary

- No executable instructions occur in the three internal gaps; treating them as hidden source helpers is rejected.
- The ordinary destructor has no direct code xrefs, but it is still source-required because virtual deletion routes through compiler glue to ordinary teardown. Zero direct callers does not make it dead or compiler-only.
- The two adjustors only normalize `this` and jump. They contain no separate source action, callback, or state transition.
- The scalar destructor's vptr writes, flag tests, size-aware guarded deletion, base teardown, and return-this convention are compiler glue. Handwritten source would duplicate compiler output.
- `Activate` is rejected because user activity clears the flag, while timer expiry sets it. The callback marks idle; it does not activate the watcher.
- `StartTimer` is rejected for the reset helper because it first clears idle state and removes all pending owner timers before scheduling.
- `m_isActive` is rejected because MainMenu's conditional route and callback/reset transitions support the opposite polarity.
- Consumer/read xrefs from EventDispatcher/MainMenu are not ownership proof. Neither defines the class lifecycle or storage.
- Application's allocation/deletion callsites are not proof that all class methods belong in `Application.cpp`; current source documentation and dedicated binary identity contradict that placement.
- No duplicate by-global page is justified because UID0002VY already covers the exact storage and can emit the one definition.
- Manual global assignment/clear in the constructor/destructor source is rejected. Those instructions are inlined Singleton base construction/destruction effects and are regenerated by `Singleton<IdleWatcher>()`.
- Explicit pad members are rejected; normal compiler alignment places the dword at `+0xfc` after the bool at `+0xf8`.

## IDA Rename / Type / Comment Recommendations

- Applied source-facing names/types: class `IdleWatcher`; global `IdleWatcher *g_pIdleWatcher`; `bool m_isIdle` at `+0xf8`; inline `bool IsIdle() const`; `unsigned int m_idleIntervalMs` at `+0xfc`; `void ResetIdleTimer()` at `0x004cfef0`; `bool OnTimer(int,int,int)` at `0x004cff20`.
- Name evidence: RTTI proves class/template identities; established docs prove global style; transitions/callers prove idle/reset semantics; TimerHandler contract and tertiary slot prove callback role; wrapper signature proves unsigned delay-millisecond use.
- Intentionally unnamed source parameters: OnTimer's three callback values are unused, and stripped symbols do not support original parameter names. Omitting names in the definition is more faithful than inventing `timerId`, `arg0`, and `arg1` there; the declaration retains descriptive contract names.
- Compiler page names are descriptive classifications, not source symbols. Their formal C++ remains blank.
- IDA DB edits are not requested. Source documentation and emitted source can use resolved names without mutating the shared database, and no assignment authorizes IDA changes.

## First-Draft C++ Recommendation

- Applied draft C++ destinations: UID00006C, UID0002VY, UID0004LE, UID0004LF, UID0004LG, and UID0004LH. UID000171, UID0004LI, UID0004LJ, and UID0003BP remain ineligible/non-emitting.
- Managed block count: exactly six. Every accepted C++ declaration/body appears only in the following complete destination-specific insertion shapes and was applied unchanged.

### Destination 1 - `by-class/IdleWatcher.md` (UID00006C, position 10)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class IdleWatcher : public Pane, public Singleton<IdleWatcher>
{
public:
    explicit IdleWatcher(unsigned int idleIntervalMs);
    virtual ~IdleWatcher();

    bool IsIdle() const { return m_isIdle; }
    void ResetIdleTimer();

protected:
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    bool m_isIdle;
    unsigned int m_idleIntervalMs;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - `by-memory/0x0069af1c-0x0069af20.g_pIdleWatcher.md` (UID0002VY, position 20)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IdleWatcher *g_pIdleWatcher = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - `by-memory/0x004cfe60-0x004cfeba.IdleWatcherConstructor.md` (UID0004LE, position 30)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IdleWatcher::IdleWatcher(unsigned int idleIntervalMs)
    : Pane(4),
      Singleton<IdleWatcher>(),
      m_isIdle(true),
      m_idleIntervalMs(idleIntervalMs)
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - `by-memory/0x004cfec0-0x004cfee9.IdleWatcherDestructor.md` (UID0004LF, position 40)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IdleWatcher::~IdleWatcher()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - `by-memory/0x004cfef0-0x004cff20.IdleWatcherResetIdleTimer.md` (UID0004LG, position 50)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IdleWatcher::ResetIdleTimer()
{
    m_isIdle = false;
    RemovePendingTimers();
    ScheduleTimer(0, m_idleIntervalMs, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - `by-memory/0x004cff20-0x004cff37.IdleWatcherOnTimer.md` (UID0004LH, position 60)

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool IdleWatcher::OnTimer(int, int, int)
{
    m_isIdle = true;
    ScheduleTimer(0, m_idleIntervalMs, 0, 0);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact behavior: the blocks preserve constructor base/member order, initial true state, 20000-ms caller-supplied interval, inline external state read, activity reset ordering, timer callback rearm, and true return while relying on the compiler for vptrs, Singleton publication/clear, Pane teardown, adjustors, and deleting wrappers.
- Plausible original source shape: ordinary class declaration plus short `.cpp` definitions matches the Visual C++ era, existing project Singleton patterns, and the binary's inlined base effects. `explicit` is a source-policy inference for a one-argument constructor and does not alter this callsite's behavior.
- Naming/coding style: `g_p`, `m_`, PascalCase methods, `0` null initialization, compact braces, and inherited wrapper calls match current reconstructed project conventions.
- Exact no-code proof:
  - UID000171 is an index; emitting it would duplicate all children.
  - Adjustor child consists only of `this -= 0xa0/0xa4` and jumps to scalar glue.
  - Scalar child consists only of compiler destructor/delete ABI behavior regenerated from the virtual destructor and inheritance.
  - UID0003BP is generated vtable/RTTI data regenerated from the complete class declaration and must retain blank formal C++.

## Final Recommendation

- C171-001 through C171-043 are applied without compression.
- UID000171 is the exact non-emitting six-child index, and all three internal gaps are registered as ignored alignment.
- UID0004LE/LF/LG/LH are owner/emitter UID00006C source children; UID0004LI/LJ are ownerless/non-emitting compiler children; UID0000K0 remains the standalone file route.
- Exactly six managed blocks exist at metadata positions 10 through 60. No manual vtable, RTTI, Singleton global clear/publication, adjustor, scalar-destructor, or padding source was added.
- Existing Application startup/shutdown source and same-or-greater Pane/TimerHandler/wrapper evidence were retained; only the accepted EventDispatcher/MainMenu support facts were added.
- No target blocker or B001 implementation item remains. Broader EventDispatcher/MainMenu reconstruction remains outside this artifact.

## Recommended Target Doc Changes

- Target path `by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md`:
  - Applied score `92/94`, owner `NONE`, reconstructable `FALSE`, blank emitter/position/formal C++, and `Nested:0`.
  - Applied exact split index naming UID0004LE through UID0004LJ and the three ignored spans.
  - Preserved full constructor/destructor/reset/callback/compiler/global/vtable/layout/xref/negative evidence and historicalized stale `Activate`, unsplit aggregate, Application absorption, manual-global, and handwritten-wrapper assumptions.
  - Applied concise non-emitting split-index Item Summary.
- New source children:
  - Registered exact constructor UID0004LE, ordinary destructor UID0004LF, reset UID0004LG, and OnTimer UID0004LH serially with owner/emitter UID00006C, reconstructable true, positions 30/40/50/60, scores `92/94`, `91/94`, `92/94`, `92/94`, and blocks 3-6.
  - Recorded complete raw/decompiled behavior, callers/callees, ABI, field offsets, source-vs-compiler reasoning, names, negative evidence, and history on each page.
- New compiler children:
  - Registered adjustor UID0004LI and scalar UID0004LJ serially with owner `NONE`, reconstructable false, blank emitter/position/formal C++, `Nested:-8`, and scores `90/94` and `92/94`.
  - Recorded exact receiver adjustments, jumps, vtable routes, flags, object size, base teardown, Singleton clear, delete routes, return ABI, and explicit no-code proof.

## Recommended Support Doc Changes

- `by-class/IdleWatcher.md` UID00006C:
  - Applied `92/94`, retained owner/emitter UID0000K0 and reconstructable true, set position 10, and replaced blank formal C++ with managed block 1.
  - Added exact size `0x100`, inheritance/PMDs, field offsets/types, natural padding, inline `IsIdle()`/MainMenu lowering, virtual route, source order, lifecycle, and real child links.
- `by-file/IdleWatcher.md` UID0000K0:
  - Applied `91/93`; preserved `NexusTK/app/` standalone placement and owner role.
  - Replaced speculative inventory with exact class/global/four-method metadata order and explicit compiler/no-code exclusions.
- `by-memory/0x0069af1c-0x0069af20.g_pIdleWatcher.md` UID0002VY:
  - Applied `91/94`, retained owner/emitter UID0000K0 and reconstructable true, set position 20 and `Nested:0`, applied managed block 2, and added all seven xrefs/lifecycle evidence.
- `by-memory/0x0061b568-0x0061b640.IdleWatcherVtableData.md` UID0003BP:
  - Applied `91/94`, retained owner/emitter UID00006C and reconstructable true, left position/formal C++ blank, and documented all complete-object locators, seven RTTI bases/PMDs, and exact primary/secondary/tertiary slot comparisons.
  - Corrected the `+0xa4` view to tertiary TimerHandler and labeled `0x004cff20` `OnTimer`; preserved generated-data no-code proof.
- `by-memory/-ignored.md`:
  - Added only `0x004cfeba-0x004cfec0`, `0x004cfee9-0x004cfef0`, and `0x004cff4d-0x004cff50` as internal `0xCC` alignment spans; preserved existing adjacent rows.
- `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md`:
  - Added exact reset callsites `0x004a72f0/0x004a72f6` and `0x004a748a/0x004a7490` following pointer and key/text predicates and their idle-timer meaning; made no score, metadata, or C++ change.
- `by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md`:
  - Added exact `g_pIdleWatcher+0xf8` read, false-state one-byte opcode-113 send, and timer-1/20000 rearm as independent field-semantic evidence; made no score, metadata, or C++ change.
- `by-memory/0x0061d264-0x0061d2ec.MainMenuPaneVtableData.md`:
  - Normalized `0x004f7660` to the current `TimerHandler::OnTimer` contract and cross-referenced the idle-state evidence; made no score, metadata, or C++ change.
- Already present at same-or-greater detail and unchanged: Application startup/shutdown/file, UID0000A2 Pane, UID0000F0 TimerHandler, UID0001K8 timer wrappers, EventDispatcher class/file, UID000172/UID000174 adjacency, and unrelated shared support.

## Score And Metadata Recommendation

| Destination | Historical baseline | Applied | Owner / emitter | Reconstructable | Position / Nested |
| --- | --- | --- | --- | --- | --- |
| UID000171 aggregate | `86/90` | `92/94` | `NONE` / blank | False | blank / `0` |
| UID00006C class | `86/90` | `92/94` | UID0000K0 / UID0000K0 | True | `10` / retain structural class value |
| UID0000K0 file | `86/88` | `91/93` | existing file route | existing documentation-file route | file ordering metadata |
| UID0002VY global | `88/91` | `91/94` | UID0000K0 / UID0000K0 | True | `20` / `0` |
| UID0003BP vtable data | `88/92` | `91/94` | UID00006C / UID00006C | True | blank / retain data value |
| UID0004LE constructor child | new | `92/94` | UID00006C / UID00006C | True | `30` / `0` |
| UID0004LF destructor child | new | `91/94` | UID00006C / UID00006C | True | `40` / `0` |
| UID0004LG reset child | new | `92/94` | UID00006C / UID00006C | True | `50` / `0` |
| UID0004LH OnTimer child | new | `92/94` | UID00006C / UID00006C | True | `60` / `0` |
| UID0004LI adjustor child | new | `90/94` | `NONE` / blank | False | blank / `-8` |
| UID0004LJ scalar child | new | `92/94` | `NONE` / blank | False | blank / `-8` |

- Score rationale: direct behavior, ranges, xrefs, inheritance, layout, global lifecycle, compiler disposition, source placement, and formal C++ are resolved. Scores remain under 95 because no symbols prove private/helper spellings, declaration access, include split, or optional `explicit` token.
- Score-improvement attempt:
  - Split blocker: resolved through exact lookup and padding bytes.
  - Constructor/destructor source blocker: resolved through body/base/Singleton/startup/shutdown evidence.
  - Callback/name blocker: resolved through TimerHandler vtable slot, contract, and state transitions.
  - Fields/types blocker: resolved through all reads/writes, wrapper units, allocation size, and RTTI PMDs.
  - External field-access blocker: resolved through the direct MainMenu load and established project inline-accessor convention; `IsIdle() const` compiles and lowers to the observed load without an out-of-line child.
  - Inheritance/vtable blocker: resolved by complete RTTI hierarchy and slot-by-slot Pane comparison.
  - Global blocker: resolved through exact page, bytes, and all seven xrefs.
  - Compiler/source blocker: resolved by instruction-level adjustor/scalar analysis and normal C++ generation rules.
  - Placement blocker: resolved through dedicated identity and current Application file exclusion.
  - Generated-output blocker: resolved by waited validator `000000009557`; the fresh file contains each authored unit once and no aggregate/compiler/vtable body duplicate. Physical output follows the validator owner tree (class subtree, then file-owned global), while the accepted metadata positions remain exactly 10/20/30/40/50/60.
- No score is inflated for support pages receiving only new prose evidence.

## Open Questions With Attempted Resolution

- Was `0x004cff20` really `Activate`? No. The TimerHandler tertiary slot and callback signature prove `OnTimer`; its state transition marks idle and rearms itself. `Activate` is superseded.
- Is `+0xf8` an inherited Singleton field? No. RTTI shows an empty base at the same offset; complete-object reads/writes and Pane's end prove the derived bool occupies that address via empty-base optimization.
- How can MainMenu read a private `m_isIdle` field? Use the inline `IsIdle() const` accessor in the class declaration. Current project classes use the same trivial-accessor pattern, and inlining explains why the binary contains only a direct load and no accessor function/xref. Public storage and friendship are less plausible and unnecessary.
- Is `+0xfc` signed or unsigned? Timer wrapper delay is documented unsigned, the value is passed unchanged, and startup supplies positive 20000. `unsigned int` is the best source type.
- Should source manually set/clear `g_pIdleWatcher`? No. Matching project Singleton patterns and constructor/destructor instruction placement identify inlined base effects. The base initializer is sufficient.
- Does an empty ordinary destructor mean no source child? No. A virtual destructor declaration/body is source-required to generate scalar deletion and implicit base teardown; the exact authored body is empty.
- Should the global receive a new by-global page? No. UID0002VY already covers exact storage and the source definition route.
- Should code live in `Application.cpp`? No. Lifecycle callsites remain there, while current file documentation and dedicated class identity support standalone source.
- Exact original spellings for `ResetIdleTimer`, `m_isIdle`, and `m_idleIntervalMs` cannot be proven without symbols. All reasonable binary/caller/family routes were exhausted; the chosen descriptive names preserve exact semantics and project style. This residual uncertainty only caps confidence and does not block C++.
- No in-scope question remains deferred. Broader MainMenu/EventDispatcher reconstruction is outside scope and unnecessary for this target.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual `-coverage-report.md` or supervisor-owned tracker edit is required.
- By-memory coverage must be driven by UID000171/new-child source metadata, concise Item Summary text, `Nested` values, scoped validators, and the validator-generated tracker refresh.
- B001 must not write validator-owned `auto-generated/-ag-*` row text or manually update report counts.

## Follow-Up Actions

- B001 implementation action is complete; no target/support/checklist work remains.
- This artifact records the no-lifecycle boundary: B001 did not execute, move, archive, or otherwise transition the report.
- Report audit, validation/execution, count, path, move, and archive state are external supervisor/validator-owned and are not asserted or directed by this artifact.
- No additional B001 research target was started.

## Confidence

- Recommendation confidence: 94/100. Direct IDA facts settle behavior, split, inheritance, compiler disposition, lifecycle, and placement.
- Score confidence: high; all recommended values reflect resolved target blockers while reserving the 95+ range for symbol/source-level proof.
- Remaining uncertainty: exact original private/helper spelling, access label, include organization, and whether the original constructor declaration used `explicit`. None changes behavior, ABI, range, owner/emitter, or generated source completeness.

## Validator Results

- Working directory for every command: `source-3/project-documentation`.
- All fifteen changed by-* pages received one scoped validator immediately after their edit. Each command exited 0 with `scanned markdown files: 1` and `ok: 1`; generation was deferred until the final authorized wait.

| Command ID | Timestamp | Exact command | Exit / ok | Result and validator-owned side effects |
| --- | --- | --- | --- | --- |
| `000000009520` | `2026-07-13T09:06:32-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004cfe60-0x004cfeba.IdleWatcherConstructor.md' --apply --queue-timeout 240` | `0 / 1` | Registered real UID0004LE; source block/metadata accepted; generated refresh deferred. |
| `000000009522` | `2026-07-13T09:07:37-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004cfec0-0x004cfee9.IdleWatcherDestructor.md' --apply --queue-timeout 240` | `0 / 1` | Registered real UID0004LF; empty source destructor accepted; generated refresh deferred. |
| `000000009524` | `2026-07-13T09:08:29-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004cfef0-0x004cff20.IdleWatcherResetIdleTimer.md' --apply --queue-timeout 240` | `0 / 1` | Registered real UID0004LG; reset block/metadata accepted; generated refresh deferred. |
| `000000009527` | `2026-07-13T09:09:26-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004cff20-0x004cff37.IdleWatcherOnTimer.md' --apply --queue-timeout 240` | `0 / 1` | Registered real UID0004LH; OnTimer block/metadata accepted; generated refresh deferred. The then-unmapped pre-existing UID0003BP reference warning was resolved by `000000009547`. |
| `000000009533` | `2026-07-13T09:10:51-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004cff37-0x004cff4d.IdleWatcherDestructorAdjustorThunks.md' --apply --queue-timeout 240` | `0 / 1` | Registered real UID0004LI; non-emitting compiler disposition accepted; generated refresh deferred. |
| `000000009535` | `2026-07-13T09:11:48-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004cff50-0x004cffaf.IdleWatcherScalarDeletingDestructor.md' --apply --queue-timeout 240` | `0 / 1` | Registered real UID0004LJ; non-emitting scalar disposition accepted; generated refresh deferred. |
| `000000009537` | `2026-07-13T09:13:40-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004cfe60-0x004cffaf.IdleWatcher.md' --apply --queue-timeout 240` | `0 / 1` | Accepted UID000171 split index, owner NONE/false disposition, and all six real child links; generated refresh deferred. |
| `000000009540` | `2026-07-13T09:15:00-04:00` | `python .\tools\validator.py --mode file --file 'by-class\IdleWatcher.md' --apply --queue-timeout 240` | `0 / 1` | Accepted UID00006C `92/94`, position-10 declaration, inline accessor, and real child links; generated refresh deferred. |
| `000000009543` | `2026-07-13T09:16:14-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x0069af1c-0x0069af20.g_pIdleWatcher.md' --apply --queue-timeout 240` | `0 / 1` | Accepted UID0002VY `91/94`, position-20 global block, and seven-reference evidence; generated refresh deferred. |
| `000000009545` | `2026-07-13T09:17:21-04:00` | `python .\tools\validator.py --mode file --file 'by-file\IdleWatcher.md' --apply --queue-timeout 240` | `0 / 1` | Accepted UID0000K0 `91/93` inventory/order/exclusions; generated refresh deferred. The then-unmapped UID0003BP warning was resolved by `000000009547`. |
| `000000009547` | `2026-07-13T09:18:46-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x0061b568-0x0061b640.IdleWatcherVtableData.md' --apply --queue-timeout 240` | `0 / 1` | Accepted UID0003BP `91/94` complete RTTI/vtable/no-code evidence and registered its existing UID mapping; generated refresh deferred. |
| `000000009552` | `2026-07-13T09:20:45-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\-ignored.md' --apply --queue-timeout 240` | `0 / 1` | Accepted the three new gap rows; added five new references and refreshed projected stats. The large registry reported pre-existing missing-UID warnings unrelated to the new rows; no scoped failure occurred. |
| `000000009553` | `2026-07-13T09:21:47-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004a6a80-0x004a82a9.EventDispatcher.md' --apply --queue-timeout 240` | `0 / 1` | Accepted exact pointer/key-text reset routes; one UID-link normalization, two reference additions, projected-stats refresh; generation deferred. |
| `000000009555` | `2026-07-13T09:22:43-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004f6700-0x004f7d10.MainMenuPaneCore.md' --apply --queue-timeout 240` | `0 / 1` | Accepted timer-ID-1/idle-state/opcode-113/rearm evidence; registered the pre-existing UID mapping/header, normalized two links, refreshed references/stats; generation deferred. |
| `000000009556` | `2026-07-13T09:23:28-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x0061d264-0x0061d2ec.MainMenuPaneVtableData.md' --apply --queue-timeout 240` | `0 / 1` | Accepted OnTimer slot normalization/cross-evidence; registered the pre-existing UID mapping/header, normalized one link, refreshed references/stats. Pre-existing UID0003P6 mapping warnings remain unrelated to this callback. |
| `000000009557` | `2026-07-13T09:24:01-04:00` | `python .\tools\validator.py --mode file --file 'by-file\IdleWatcher.md' --apply --queue-timeout 240 --wait-generated` | `0 / 1` | `generated_refresh: completed`; rebuilt autogen registry, refreshed generated metadata/coverage, and stamped IdleWatcher.cpp with this command ID/time. Validator also reported one unrelated validator-owned `LightingObjectPane.cpp` content refresh; B001 did not edit it. |

- B001 waited generated verification: `auto-generated/NexusTK/app/IdleWatcher.cpp`, 59 lines, SHA256 `D9BB55C28A4F360E4F8033173AB2106407DCBEFDC662DCD5FCB975904C0DE652`, header command `000000009557`, refreshed `2026-07-13T09:24:01-04:00`.
- External-restamp reconciliation: during the final report audit, the same 59-line file carried externally owned header command `000000009580`, refreshed `2026-07-13T09:33:44-04:00`, current SHA256 `D4FB943908B462F06C42056AA2B230AE002D3188B2E2A3E4E2A6EAFD564106BA`. Every authored-unit line/count, UID order, and negative check below was unchanged; B001 did not run command `000000009580`.
- Exact authored-unit counts: class declaration 1 at line 8; inline `IsIdle()` 1 at line 14; constructor 1 at line 26; ordinary destructor 1 at line 35; `ResetIdleTimer` 1 at line 40; `OnTimer` 1 at line 48; global definition 1 at line 57.
- Exact generated UID order is UID00006C, UID0004LE, UID0004LF, UID0004LG, UID0004LH, UID0002VY, UID0003BP. The metadata positions remain class/global/methods `10/20/30/40/50/60`; physical output follows the validator owner tree, so UID00006C's class-owned children render before the UID0000K0-owned global sibling.
- Negative generated checks: UID000171 count 0; adjustor/scalar/stale `Activate` count 0; manual Singleton publication/constructor-or-destructor clear count 0; manual vtable/RTTI body count 0. UID0003BP appears once only as the expected blank-code Empty Emitter Marker, not as a body or duplicate.
- Unresolved callback validator failures: none. All assignment pages returned `ok: 1`; warnings recorded above are pre-existing registry mappings and did not invalidate any accepted claim.

## Changed Files

- Created by-* pages: `by-memory/0x004cfe60-0x004cfeba.IdleWatcherConstructor.md` (UID0004LE), `by-memory/0x004cfec0-0x004cfee9.IdleWatcherDestructor.md` (UID0004LF), `by-memory/0x004cfef0-0x004cff20.IdleWatcherResetIdleTimer.md` (UID0004LG), `by-memory/0x004cff20-0x004cff37.IdleWatcherOnTimer.md` (UID0004LH), `by-memory/0x004cff37-0x004cff4d.IdleWatcherDestructorAdjustorThunks.md` (UID0004LI), and `by-memory/0x004cff50-0x004cffaf.IdleWatcherScalarDeletingDestructor.md` (UID0004LJ).
- Modified by-* pages: `by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md`, `by-class/IdleWatcher.md`, `by-memory/0x0069af1c-0x0069af20.g_pIdleWatcher.md`, `by-file/IdleWatcher.md`, `by-memory/0x0061b568-0x0061b640.IdleWatcherVtableData.md`, `by-memory/-ignored.md`, `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md`, `by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md`, and `by-memory/0x0061d264-0x0061d2ec.MainMenuPaneVtableData.md`.
- Modified report: this exact B001 research artifact only.
- Renamed/moved files: none.
- Validator-owned side effects: UID/reference/autogen registry and projected-stat updates; generated metadata/coverage refresh; fresh `auto-generated/NexusTK/app/IdleWatcher.cpp`; the unrelated validator-reported `LightingObjectPane.cpp` refresh. External command `000000009580` later restamped generated metadata without changing the verified IdleWatcher source body. No generated, coverage, tracker, supervisor, validator-state, or lifecycle file was edited manually.
- Leases: all released. Final `current_leases.md` check returned no B001 entry. One pre-creation lease attempt against a nonexistent child was rejected as `File not found` and created no lease; each child was then created serially while the existing aggregate parent lease was held, validated, and immediately released before the next child.
- Report execution: not run. B001 performed no execution, lifecycle, move, or archive command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact SHA256 `50A7AD40E4BA334D27957E9D8EA465100D3F84705CECCF3EB3312C3F8F9B2816` before implementation.
- [x] Re-read every exact current target/support path immediately before leasing during callback.
- [x] Created/registered constructor UID0004LE alone and captured its validator-issued UID before linking.
- [x] Created/registered destructor UID0004LF alone and captured its validator-issued UID before linking.
- [x] Created/registered reset UID0004LG alone and captured its validator-issued UID before linking.
- [x] Created/registered OnTimer UID0004LH alone and captured its validator-issued UID before linking.
- [x] Created/registered adjustor UID0004LI alone and captured its validator-issued UID before linking.
- [x] Created/registered scalar UID0004LJ alone and captured its validator-issued UID before linking.
- [x] Updated UID000171 to `92/94`, owner NONE, false/non-emitting, blank position/formal C++, `Nested:0`, exact child links, Item Summary, and complete aggregate evidence.
- [x] Applied exact source-child metadata, positions 30/40/50/60, managed blocks 3-6, and full behavior/evidence/history.
- [x] Applied compiler-child scores/metadata, `Nested:-8`, blank formal C++, and exact no-code proofs.
- [x] Added exactly three internal ignored padding spans without changing adjacent rows.
- [x] Updated UID00006C to `92/94`, position 10, exact layout/inheritance/children/evidence, and managed block 1.
- [x] Preserved private `m_isIdle` and added exact inline `IsIdle() const` for the MainMenu load route.
- [x] Updated UID0002VY to `91/94`, position 20, `Nested:0`, seven-xref lifecycle evidence, and managed block 2.
- [x] Updated UID0000K0 to `91/93` and exact standalone source inventory/metadata order/exclusions.
- [x] Updated UID0003BP to `91/94`, exact RTTI/vtable inventory and no-code proof, with no formal block.
- [x] Added exact EventDispatcher reset-route support with no score/metadata/C++ change.
- [x] Added exact MainMenu idle-state consumer support with no score/metadata/C++ change.
- [x] Normalized MainMenu vtable callback label/support with no score/metadata/C++ change.
- [x] Preserved Application, Pane, TimerHandler, wrapper, adjacency, and unrelated shared support at same-or-greater detail without edits.
- [x] Preserved all negative evidence and historicalized stale `Activate`, unsplit, Application-absorption, manual-global, and handwritten-compiler-glue assumptions.
- [x] Applied exactly six complete managed blocks and no body-only C++ snippets.
- [x] Confirmed third-party import directive is not applicable; this is native game-client class source.
- [x] Kept IDA database unchanged; no rename/type/comment mutation or process management occurred.
- [x] Kept generated, coverage, tracker, supervisor, validator-state, and lifecycle files unedited manually.
- [x] Used one short existing-file lease at a time; every lease was released immediately after its scoped validator.
- [x] Ran one scoped validator for every changed ordinary by-* page and recorded command/id/timestamp/exit/ok/side effects.
- [x] Ran final authorized waited validator `000000009557` after all target/support implementation.
- [x] Verified the complete class/inline accessor/global/constructor/destructor/reset/OnTimer each occur once; exact metadata positions and validator owner-tree physical order are recorded above.
- [x] Verified no UID000171 marker, aggregate duplicate, adjustor/scalar body, manual vtable/RTTI body, constructor/destructor Singleton write/clear, or stale `Activate` body.
- [x] Updated C171-001 through C171-043 claim states, current-state wording, Validator Results, Changed Files, and both checklist phases.
- [x] Ran no report execution, lifecycle, move, or archive command.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at exact SHA256 `50A7AD40E4BA334D27957E9D8EA465100D3F84705CECCF3EB3312C3F8F9B2816`.
- [x] All accepted target/support details incorporated at report-level detail without compression.
- [x] All six real child UIDs captured from validators and reconciled in target/class/file/report ledgers before links were finalized.
- [x] Claim And Incorporation Ledger updated claim by claim with applied/already-present/rejected state and verification destination.
- [x] Exact scores, owner/emitter/reconstructable, positions, Nested, split, names, and six formal blocks applied.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved.
- [x] No open in-scope blocker left unresolved or silently deferred.
- [x] Every one-file lease released after its scoped validator; final lease check is clear.
- [x] Every changed ordinary by-* page validated and exact proof recorded.
- [x] Final waited generated refresh completed and exact IdleWatcher.cpp content/order/no-duplicate checks recorded.
- [x] No manual generated/coverage/tracker/supervisor/validator-state/lifecycle edit performed.
- [x] B001 callback work is complete; report path/state/lifecycle remains external and B001 performed no execution, move, or archive action.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000009599","destination_path":"executed-b-agent-research/B001/000171-IdleWatcher-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/000171-IdleWatcher-source-quality.md","timestamp":"2026-07-13T09:55:12-04:00","uid":"000171"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
