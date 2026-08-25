** TARGET-REPORT-UID:0003PH **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003PH WeatherLayerPane OnTimer Ownership / Split Research


## Finalized Report / Current Recommendation

- Current ordinary-document state: [UID:0003PH] is implemented as the exact source-authored `bool WeatherLayerPane::OnTimer(int timerId, int arg0, int arg1)` override at renamed path `by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md`, with human C++03 formal emitted through direct class owner [UID:0000G1].
- Applied disposition: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000G1`, and `EMITTER_UIDS:0000G1` remain unchanged; the target is now `92/94` at deterministic position `20`, after constructor position `10`, with the exact formal C++ in this report. Accepted support synchronization is applied without duplicating child bodies or compiler-generated vtable data.
- Current gate state: supervisor exact-artifact Gate 1 passed at `2026-07-24T01:31:22-04:00`, independent Gate 2A passed at `2026-07-24T01:44:10-04:00`, and C3PH-016 Gate 2B passed at `2026-07-24T01:49:30-04:00`. This report-only reconciliation changes the report artifact, so a fresh supervisor exact-artifact continuity audit remains required before supervisor-only execution/archive; C3PH-017 manual coverage remains pending until after execution. B002 did not edit coverage, IDA, generated/tracker files directly, validator state, audit/supervisor/goal files, or lifecycle state.
- Confidence: very strong for exact runtime behavior, ABI, adjusted receiver, field offsets/types, virtual dispatch, timer route, derived-class use, ownership, and current project source route. The inferred lexical spelling `OnFrameChanged` for the primary-vtable `+0x4c` extension hook is high-probability source reconstruction rather than original-symbol proof, so neither score reaches `95`.

## Supporting Research

- This began as the initial report-only artifact for the 2026-07-24 B002 assignment. Supervisor Gate 1 accepted exact pre-callback SHA256 `F43290689550AB6628E8921EEDC8F3D1B04E1211D279D2C8FB053C0570E55608`; this same artifact now records the accepted ordinary-document implementation callback without replacing or rewriting the original research.
- Live read-only MCP work used the healthy owned session `supervisor_gate2b_0002OT_20260723`. `idb_list` reported one active worker session, PID/worker PID `3368`, `is_analyzing:false`; `server_health` returned `status:ok`, module `NexusTK.exe`, image base `0x400000`, Hex-Rays ready, and string cache ready.
- The report preserves prior valid by-* research but rechecks its source-quality blockers. In particular, the old claims that field/helper names and the file split block C++ are superseded: the shared tail fields, inherited rectangle, timer signature, owner, and selected source route are now documented strongly enough for a source method.
- The report distinguishes the exact binary callback from adjacent constructor, alignment, Rain/Snow/Swallow implementations, vtable data, and compiler-generated destructor wrappers. It does not absorb sibling method bodies into the target formal.

## Target

- Target UID: `0003PH`.
- Additional target UIDs: none. Related pages below are support destinations, not additional report-covered targets.
- Declared-target inventory: [UID:0003PH] `by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md`, exact source-authored timer callback body at `[0x005c13b0,0x005c1408)`. The assignment-time path ended in `WeatherLayerPaneOnTimerEvent.md`; the safe same-root rename preserved UID/range/history and the old path no longer exists.
- Target path: `by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md`.
- Current queue/generated row: `auto-generated/-ag-research-tracker.md` lists `92/94`, reconstructable `true`, and pre-execution report coverage `0/0/0`; `auto-generated/-ag-memory-coverage.md` marks the target `coded`, position `20`, and routes it to `auto-generated/NexusTK/map/WeatherLayerPane.cpp` through emitter `0000G1`.
- Assignment-time supervisor classification: reconstructable by-memory empty emitter requiring exhaustive source-quality closure and first formal C++. Current state is a filled position-20 emitter whose Gate 1, Gate 2A, and Gate 2B work passed; final supervisor exact-artifact continuity audit, execution/archive, and post-execution coverage remain pending.
- Assignment-time scores and parent state: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000G1`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000G1`, blank position, blank formal C++.

## Current Target State

- Assignment-time metadata was internally routable but incomplete: `86/88`, reconstructable/class-owned, blank position, and blank formal. That state is historical after the accepted callback.
- Current target metadata is `92/94`, owner/emitter [UID:0000G1], reconstructable true, position `20`, and exact nonblank formal C++. [UID:0000G1] remains the narrowest semantic owner; its class route reaches [UID:0000P8] and current `NexusTK/map/WeatherLayerPane.cpp` output.
- Assignment-time generated state was an empty emitter marker. Validator command `000000017036` now emits exactly one UID0003PH marker and one `WeatherLayerPane::OnTimer` definition, with no `WeatherLayerPaneOnTimerEvent` occurrence and no target-specific empty marker.
- Target prose now records the exact `0x58` range/hash/fences, three weather-family vtable refs, adjusted TimerHandler ABI, signed frame advance, inherited visible-bounds invalidation, distinct `OnFrameChanged()` hook, reschedule behavior, derived matrix, source route, rejected historical names, and score rationale.
- Source-split uncertainty is retained as historical provenance rather than current blocking state. [UID:0000P8] selects the operational one-file `NexusTK/map/WeatherLayerPane.cpp` route and canonical `WeatherLayerPane.h`; dedicated derived-file alternatives remain documented hypotheses.
- Related target/support docs checked: [UID:0003PG], [UID:0000G1], [UID:0000P8], [UID:0000F0], [UID:0001K8], [UID:0001VX], [UID:0003PI], [UID:0003O2], [UID:0000DC], [UID:0002Z7], [UID:0002Z8], [UID:0002Z9], [UID:0002ZA], [UID:0001WJ], Pane/GrafPort layout documentation, generated source, generated research tracker, generated memory coverage, and current manual class/file/memory coverage rows.
- Current artifact/lifecycle status: Gate 1, ordinary-document Gate 2A, and C3PH-016 Gate 2B are APPLIED_VERIFIED. Because this report-only reconciliation changes the exact artifact hash, final supervisor exact-artifact continuity audit remains pending. Supervisor execution/archive and C3PH-017 post-execution manual coverage handoff remain unapplied.

## Executive Recommendation

- Direct owner: retain [UID:0000G1][WeatherLayerPane]. The callback is a source method of the abstract/shared weather base, not a free function, TimerHandler-owned helper, file-level helper, or migration-index body.
- Source method: `bool WeatherLayerPane::OnTimer(int timerId, int arg0, int arg1)`. At the ABI boundary ECX is the inherited `TimerHandler` facet at complete object `+0xa4`; the compiled body subtracts `0xa4` when it needs the complete `WeatherLayerPane`.
- Runtime contract: timer ID `0` advances signed-byte frame state, invalidates inherited visible bounds, invokes a frame-change extension hook, and reschedules timer ID `0` after the signed-short interval; every timer ID returns `true`, while nonzero IDs do no state work and do not reschedule.
- Best source-facing extension name: `virtual void OnFrameChanged()`. Weather and Rain use the shared no-op body, Snow overrides the same slot with its 200-particle movement/refill method, and Swallow retains the no-op slot while replacing `OnTimer` entirely.
- Rename the by-memory page/title to `0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md`; retain UID identity. Add the formal body, deterministic position, full evidence, rejected alternatives, and score rationale.
- The callback is not blocked by destructor wrappers. Timer teardown belongs to inherited TimerHandler destruction/unregistration; folded deleting wrappers and adjustor thunks remain compiler-generated and must not be hand-authored in this method.

## Supervisor Active Recheck

- Supervisor gate history rechecked: initial Gate 1 accepted exact pre-callback SHA `F43290689550AB6628E8921EEDC8F3D1B04E1211D279D2C8FB053C0570E55608`; post-callback exact-artifact Gate 1 passed report SHA `8501A118F9AB77A1674BD3832DA36754F6FC54248CA2F13431F7DE54744C0773` at `2026-07-24T01:31:22-04:00`; Gate 2A passed at `2026-07-24T01:44:10-04:00`; and C3PH-016 Gate 2B passed at `2026-07-24T01:49:30-04:00`. The current callback is report-only reconciliation before fresh exact-artifact continuity audit and supervisor execution.
- No split repair is required before this report. The exact child already spans one complete function, with predecessor and successor alignment separately documented.
- Every source-bearing item needed to explain this target is identified: target body [UID:0003PH], base constructor [UID:0003PG], Rain constructor [UID:0003PI], Snow frame hook [UID:0003O2], Swallow timer override under its existing exact child, class owner [UID:0000G1], file route [UID:0000P8], and the four weather-family vtable-data pages.
- No new by-memory child is needed. The second indirect call is represented by existing Snow body [UID:0003O2] when overridden and by the shared no-op function when not overridden; the target range contains only the callback body.

## Inference Research Guidance Check

- `by-structure.md` requires full-function bodies and exact binary evidence in by-memory, direct semantic class ownership, emitter routing separate from ownership, source-quality blocker resolution before formal C++, no source outside the exact range, and human precompiled source rather than decompiler-shaped code. The recommendation follows each rule.
- Existing assumptions treated as uncertain and rechecked were: `OnTimerEvent` spelling, `message/userData` payload names, `m_weatherBounds` versus inherited `m_visibleBounds`, whether the `+0x4c` call repaints, whether Snow/Rain/Swallow share the callback, whether source split remains blocking, and whether destructor coupling requires code in this range.
- Direct IDA facts are labeled as such; current by-* and generated state are documentation evidence; `OnFrameChanged`, exact access qualifier, and historical source lexical spelling are inference.
- `by-structure.md` and older pages contain Wave2/Wave3 terminology. Those mentions were ignored as stale workflow artifacts under the current assignment; no ownership, type, name, or score claim relies on them.

## Heuristic / Inference Reanalysis And Validation

- Function name: current IDA `sub_5C13B0` is synthetic. The exact TimerHandler slot, three-argument callback ABI, `timerId` branch, and current TimerHandler contract make `WeatherLayerPane::OnTimer` the best source name. `OnTimerEvent` is rejected as unnecessary divergence from the accepted base virtual.
- Receiver type: raw `int this` is rejected. ECX is provably the TimerHandler facet because field references use facet-relative `+0x54/+0x55/+0x56`, complete-object calls use `-0xa4`, and scheduling accepts the unadjusted receiver. Documentation should describe both the source object and ABI-adjusted view.
- Callback payloads: `message` and `userData` are rejected because this body never reads the second or third payload and ScheduledTimerEvent/TimerHandler use generic `arg0`/`arg1`. The C++ definition may leave both unused parameter names omitted.
- Frame fields: raw bytes/dword aliases are rejected. Signed extension proves `signed char m_currentFrame` at complete `+0xf8`, `signed char m_frameCount` at `+0xf9`, and signed-short `m_timerInterval` at `+0xfa`. The constructor dword-clear is a compiled coalescing of those three fields, not one 32-bit member.
- Frame arithmetic: the binary performs `(m_currentFrame + 1) % m_frameCount` with signed division and no zero guard. Adding a defensive guard would alter exact execution and is rejected. Rain sets count `3`; Snow initializes bytes `04 05 C8 00`, meaning current frame `4`, frame count `5`, interval `200`; both establish nonzero counts before queued dispatch.
- Rectangle identity: the first virtual argument is TimerHandler facet `-0x60`, equal to complete object `+0x44`. That is inherited `GrafPort::m_visibleBounds`, not Weather tail `m_weatherBounds` at complete `+0xfc`. The earlier generic invalidate/repaint wording is narrowed to exact `InvalidateRect(&m_visibleBounds)`.
- Primary `+0x4c` virtual: Pane's known primary virtual contract ends at `+0x48`; Weather introduces `+0x4c`. Weather, Rain, and Swallow point it to the same one-byte no-op, while Snow points it to exact body `0x005c1f50`. Since the timer calls it immediately after changing `m_currentFrame`, `OnFrameChanged` is the highest-probability human name. `Repaint`, `OnPaint`, and `RandomizeSnowParticles` as the base slot name are rejected: Rain does not repaint there, `OnPaint` already occupies `+0x44`, and only the Snow override has particle-specific behavior.
- Snow override role: live decompile proves `0x005c1f50` is a no-argument `void` method behind Snow primary cell `0x006312fc`. It skips work while `g_activeMapPane->m_waitingForLocalPlayerStatus` is set, shifts all 200 particle rectangles, and conditionally rolls 180 records and refills 20 leading entries. That behavior is a concrete response to a frame transition even though its prior physical-page title remains behavior-descriptive.
- Timer identity: first explicit argument `timerId` is compared to zero. Only ID `0` executes the shared weather path. The callback passes `(0, m_timerInterval, 0, 0)` to inherited `ScheduleTimer`; a nonzero incoming ID returns true without replacement scheduling.
- Rain interaction: Rain inherits this TimerHandler slot, sets `m_frameCount=3`, `m_timerInterval=120`, and enabled state. Its `+0x4c` hook remains no-op, so shared timer work cycles frames and invalidates visible bounds at 120 ms.
- Snow interaction: Snow inherits this TimerHandler slot and writes dword `0x00C80504` at complete `+0xf8`, yielding frame/count/interval `4/5/200`; its `+0x4c` override performs particle movement/refill. The first ID-0 callback wraps frame 4 to 0 before the hook.
- Swallow interaction: Swallow derives from Weather but replaces the TimerHandler slot with `0x005c2500`, handles only `0x100` and `0x101`, and leaves the primary `+0x4c` hook no-op. The base constructor's scheduled ID `0` therefore reaches the Swallow override and is acknowledged without shared frame work. Describing Swallow as a direct user of this target is rejected.
- Constructor/destructor coupling: Weather construction schedules initial ID `0` with zero delay; derived constructors install final vtables/state before queued dispatch. TimerHandler teardown unregisters pending owner events. No cancellation, destructor, thunk, or deleting-wrapper source belongs in this target.
- Source placement: the historical dedicated-file alternatives do not outweigh the current validated route. Exact target ownership remains the class; generated placement remains [UID:0000P8] `NexusTK/map/WeatherLayerPane.cpp`; declaration belongs in canonical `WeatherLayerPane.h`.
- Generated empty-emitter diagnosis: at assignment time the route was intact and output contained class child insertion, a filled constructor, then a UID0003PH empty marker. The accepted direct repair was to add the target formal without moving ownership or creating another file; command `000000017036` now confirms that repair is filled.

## Evidence Standards Used

- Highest-weight evidence: live IDA MCP function analysis/decompilation, exact bytes, exclusive bounds, xrefs, vtable cells, constructor stores, facet adjustment, signed-load instructions, virtual offsets, direct callee, and derived constructor/timer behavior.
- Corroborating evidence: current by-memory/class/file/type docs, current generated C++, generated memory coverage, generated research tracker, manual coverage rows, and accepted TimerHandler/ScheduledTimerEvent contracts.
- Negative evidence: no direct code caller, no target-start VA/RVA/raw pointer route beyond the three vtable cells, no fourth shared timer slot, no target-end xref, no source string/PDB proof for lexical names, no code in either alignment fence, and no Swallow slot route to this body.
- Binary context is decisive for behavior and ABI. Stripped-symbol limitations affect only exact original lexical spelling and final header formatting, not the selected human source shape or runtime semantics.
- Scores remain below `95` because no PDB/original UDT or rebuild-equivalence result proves the exact historical spelling/access declaration; this does not justify leaving synthetic names or blank C++.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: `idb_list`, `server_health`, `analyze_function` for `0x005c13b0`, `0x005c1410`, `0x005c1bd0`, `0x005c1f50`, and `0x005c2500`; exact `get_bytes` for target and both alignment fences; vtable slot and caller/callee readback from the current IDB.
- Target bytes: 88 bytes at `[0x005c13b0,0x005c1408)`, SHA256 `D22E0CA8BDB83016F49F9A24D78B13789A403E89147CA9E15E7E07EAB3FFF8D7`. The 22-byte leading signature is unique in the image.
- Boundary bytes: `[0x005c13a1,0x005c13b0)` is fifteen `0xCC` bytes, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`; `[0x005c1408,0x005c1410)` is eight `0xCC` bytes, SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`.
- by-* docs checked: exact Weather constructor/timer/Rain constructor/Snow hook/Weather-Rain-Snow-Swallow vtable pages; Weather/Snow/Rain/Swallow/TimerHandler class docs; Weather/Rain/Snow file docs; Weather layout; ScheduledTimerEvent; Pane/GrafPort fields and virtuals.
- Generated/current-state checks: after command `000000017036`, UID0003PH appears as one filled callback in `WeatherLayerPane.cpp`, remains pre-execution report coverage `0/0/0` in the research tracker, and is a coded position-20 emitter routed through `0000G1` in generated memory coverage.
- Manual coverage checks: current UID0003PH, UID0002Z7, UID0000G1, UID0000DC, and UID0000P8 rows remain stale and supervisor-owned; UID0003O2 remains absent from the manual by-memory coverage file. No B002 coverage edit occurred.
- Failed/unavailable checks: original symbols, source files, PDB/UDT declarations, and a rebuilt binary are unavailable. Those missing artifacts prevent lexical certainty and `95+`, but all current binary/documentation routes needed for an implementation-ready body were exhausted.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C3PH-001 | 0003PH | Exact range is `[0x005c13b0,0x005c1408)`, 88 bytes, with exact hash and CC fences. | exact | MCP function/bytes plus hashes | renamed target Evidence/Boundaries | incorporated | APPLIED_VERIFIED in renamed target; validator `000000017019` |
| C3PH-002 | 0003PH | Source contract is `bool WeatherLayerPane::OnTimer(int,int,int)`; ECX is TimerHandler facet `+0xa4`. | very strong | `retn 0x0c`, AL=1, facet adjustments, TimerHandler docs | target ABI/Behavior | incorporated | APPLIED_VERIFIED in target/formal |
| C3PH-003 | 0003PH | Only timer ID 0 mutates state and reschedules; every ID returns true. | exact | compare/branch and unconditional `mov al,1` | target Behavior | incorporated | APPLIED_VERIFIED in target/formal |
| C3PH-004 | 0003PH | Signed fields are `m_currentFrame +0xf8`, `m_frameCount +0xf9`, `m_timerInterval +0xfa`. | very strong | signed loads/idiv, constructors, layout docs | target Fields; class support | incorporated | APPLIED_VERIFIED in target/class/file |
| C3PH-005 | 0003PH | Target invalidates inherited `m_visibleBounds` at complete `+0x44` through Pane primary slot `+0x20`. | exact | facet `-0x60`, primary vcall, Pane/GrafPort docs | target Behavior | incorporated | APPLIED_VERIFIED in target/class/file |
| C3PH-006 | 0003PH | Primary slot `+0x4c` is a Weather-added frame-change hook, best named `OnFrameChanged`. | high inference | cross-vtable comparison and immediate post-frame call | target/class/vtable/Snow support | incorporated as inferred spelling | APPLIED_VERIFIED across target and support matrix |
| C3PH-007 | 0003PH | Timer replacement is `ScheduleTimer(0,m_timerInterval,0,0)`. | exact | direct callee and pushed arguments | target Behavior/C++ | incorporated | APPLIED_VERIFIED in target/formal |
| C3PH-008 | 0003PH | Incoming routes are exactly Weather/Rain/Snow TimerHandler cells; there is no direct code caller. | exact | xrefs `0x631218/0x6312a8/0x631338` | target Dispatch | incorporated | APPLIED_VERIFIED in target/vtable pages |
| C3PH-009 | 0003PH | Rain uses shared callback with 3 frames and 120 ms; its frame hook is no-op. | exact | Rain constructor and vtables | target Derived behavior; Rain support | incorporated | APPLIED_VERIFIED; UID0002Z8 prose synced, metadata retained `89/93` |
| C3PH-010 | 0003PH | Snow uses shared callback with state 4/5/200 and overrides frame hook at `0x5c1f50`. | very strong | Snow constructor dword and primary/Timer vtables | target Derived behavior; Snow support | incorporated | APPLIED_VERIFIED in target, UID0003O2, UID0000DC, UID0002Z9 |
| C3PH-011 | 0003PH | Swallow overrides OnTimer at `0x5c2500`; it does not dispatch to this target. | exact | Swallow Timer cell/decompile | target negative evidence; Swallow support | incorporated | APPLIED_VERIFIED in target/file/UID0002ZA |
| C3PH-012 | 0003PH | Construction schedules initial ID 0; inherited TimerHandler destruction removes pending events. | very strong | constructor and TimerHandler lifecycle docs | target lifecycle | incorporated | APPLIED_VERIFIED in target/UID0003PG/file |
| C3PH-013 | 0003PH | Direct owner/emitter is Weather class; current file route is WeatherLayerPane.cpp/header. | very strong | class/file/generated route | target metadata/source placement | retained and documented | APPLIED_VERIFIED in target/class/file/generated route |
| C3PH-014 | 0003PH | Human C++ block in this report preserves exact execution without decompiler artifacts. | very strong | all behavior/ABI claims above | target formal C++ | applied after Gate 1 | APPLIED_VERIFIED in target and generated source |
| C3PH-015 | 0003PH | Recommended target score is 92/94 and deterministic method position is 20 after constructor 10. | strong | evidence completeness and emitter ordering | target and constructor metadata | applied after Gate 1 | APPLIED_VERIFIED; target `92/94` position 20, constructor position 10 |
| C3PH-016 | 0003PH | Exact IDA rename/type/comment handoff is safe; B002 must not apply it. | strong | supervisor pre-state/action/readback/save evidence at `2026-07-24T01:49:30-04:00` | supervisor Gate 2B | supervisor-only | APPLIED_VERIFIED; Gate 2B passed with preserved xrefs and saved IDB checkpoint `C4250949...EB76E` |
| C3PH-017 | 0003PH | Manual target/class/file/vtable/Snow rows need supervisor synchronization. | exact current-state | current manual coverage reads | coverage reports | supervisor-only after execution | pending supervisor handoff |
| C3PH-018 | 0003PH | Generated empty marker should become a filled callback after ordinary-doc validation. | exact expected route | current generated source and emitter graph | generated validator output | validator-owned callback result | APPLIED_VERIFIED by generated command `000000017036` |

## Positive Evidence Summary

- Exact function shape: 88-byte body, 33 instructions, three basic blocks, complexity two, three explicit stack arguments, `retn 0x0c`, and unconditional true return.
- Exact dispatch: the only incoming data xrefs are Weather, Rain, and Snow adjusted TimerHandler vtable cells; the direct call list contains only source-quality `TimerHandler__ScheduleTimer`.
- Exact state: signed byte/byte/short instructions match constructor/layout evidence and derived configuration values.
- Exact complete-object recovery: TimerHandler facet `-0xa4` reaches the Pane/Weather complete object; `-0x60` reaches complete `+0x44` visible bounds.
- Exact virtual roles: primary slot `+0x20` is InvalidateRect; `+0x44` is the existing OnPaint slot; `+0x4c` is the new no-argument Weather hook with a Snow-only override.
- Strongest inference chain: the `+0x4c` slot is introduced by Weather, invoked only immediately after frame mutation, remains no-op in base/Rain/Swallow, and becomes particle update/refill in Snow. `OnFrameChanged` describes the stable polymorphic role without importing Snow-specific implementation naming into the base.

## IDA MCP Facts

- Function/range facts: `sub_5C13B0`, current prototype `char __thiscall(int this,int,int,int)`, address `0x005c13b0`, size `88`, exclusive end `0x005c1408`; decompile and bytes agree.
- Data/table/padding facts: target bytes/hash are exact; predecessor 15-byte and successor 8-byte spans are pure `0xCC`; target-start VA pattern occurs only in the three vtable cells and the RVA pattern has no hit.
- Xref facts: `0x00631218`, `0x006312a8`, and `0x00631338` point to the target. No direct code caller is modeled. Target-end and cell-address queries do not create another route.
- Vtable/global/type facts: Weather primary `+0x4c` and Rain/Swallow equivalents point to shared no-op `0x0041b6a0`; Snow primary `0x006312fc` points to `0x005c1f50`. Swallow Timer cell `0x006313c8` points to `0x005c2500`, not the target.
- Derived constructor facts: Rain `0x005c1410` writes interval `120`, frame count `3`, enabled `1`; Snow `0x005c1bd0` writes complete-tail dword `0x00C80504` and enabled `1` after Weather construction.
- Negative IDA facts: no original function/type/member symbols exist for the target; no fourth vtable route exists; no call or data occupies the CC fences; no direct Snow hook caller exists because its route is vtable-only.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005c12a0-0x005c13a1` | UID0003PG Weather constructor | Initializes base state/bounds and schedules ID 0 | true | UID0000G1 | 92/94 | filled source child |
| `0x005c13a1-0x005c13b0` | by-memory `-ignored.md` | 15-byte alignment | false | none | n/a | exact padding |
| `0x005c13b0-0x005c1408` | UID0003PH target | Shared Weather/Rain/Snow OnTimer | true | UID0000G1 | 86/88 -> 92/94 | callback-applied filled position-20 emitter |
| `0x005c1408-0x005c1410` | by-memory `-ignored.md` | 8-byte alignment | false | none | n/a | exact padding |
| `0x005c1410-0x005c145a` | UID0003PI Rain constructor | Configures 3 frames / 120 ms | true | UID0000BJ | 86/88 | support |
| `0x005c1bd0-0x005c1c7e` | Snow constructor child under existing method index | Configures 4/5/200 and particle array | true | UID0000DC | current support state | support |
| `0x005c1f50-0x005c20d4` | UID0003O2 | Snow override of frame-change hook | true | UID0000DC | 88/89 | support role repair; body remains separate |
| `0x005c2500-0x005c26a6` | existing Swallow OnTimer child | Swallow-only IDs 0x100/0x101 | true | UID0000E9 | current support state | rejects shared-target route |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00631218` | data xref -> `0x005c13b0` | WeatherLayerPane TimerHandler virtual slot |
| `0x006312a8` | data xref -> `0x005c13b0` | RainingLayerPane inherits shared timer callback |
| `0x00631338` | data xref -> `0x005c13b0` | SnowingLayerPane inherits shared timer callback |
| direct callers | none | normal for vtable-only callback; not no-owner evidence |
| `0x005975e0` | target direct callee `TimerHandler__ScheduleTimer` | queues replacement ID 0 event |
| primary slot `+0x20` | indirect `Pane::InvalidateRect` | invalidates complete-object inherited visible bounds |
| primary slot `+0x4c` | indirect Weather frame hook | shared no-op or Snow particle update/refill override |
| `0x005c12a0` | constructor schedules `(0,0,0,0)` | establishes initial timer lifecycle |
| `0x005c2500` | Swallow separate timer override | excludes Swallow from target dispatch |

## Documentation Evidence And IDA Status

- Supporting current docs: UID0003PG proves complete size `0x10c`, tail layout, initial timer schedule, three derived constructor callers, and current source route. UID0003PI proves Rain `3/120`. TimerHandler/ScheduledTimerEvent docs prove `OnTimer(timerId,arg0,arg1)` and `ScheduleTimer(timerId,delay,arg0,arg1)`. Pane/GrafPort docs prove inherited visible bounds and `InvalidateRect` slot.
- Stale/incomplete target claims: blank formal, score `86/88`, field/helper/source blockers, `OnTimerEvent` title, `message/userData`, and generic `invalidates/repaints` wording.
- Stale/incomplete support claims: UID0003O2 describes its physical behavior but not its base virtual role; Weather class calls the second virtual a repaint-like action rather than a frame hook; manual UID0002Z7 coverage still says `85` while its page is `88/92`; manual UID0003O2 row is absent.
- Historical IDA pre-state at callback handoff used synthetic `sub_` names and raw prototypes. B002 performed no IDA mutation during either initial research or the ordinary-document callback. Supervisor Gate 2B subsequently applied and read back the accepted target/Snow names, types, comments, and opaque Snow declaration; the exact closure evidence is recorded below.
- Generated state: class marker and constructor emit correctly into WeatherLayerPane.cpp, proving the route. UID0003PH alone remains empty at that location.

## Ranked Ownership Analysis

### 1. WeatherLayerPane class UID0000G1

- Evidence for: body adjusts TimerHandler facet to complete Weather object, reads Weather tail fields, calls Pane primary virtuals, appears in Weather/Rain/Snow TimerHandler tables, and is initialized/scheduled by the Weather constructor.
- Evidence against: none. Multiple-inheritance adjusted receiver can look TimerHandler-owned in raw decompile but is ABI mechanics, not source ownership.
- Decision: accepted direct canonical owner and emitter.

### 2. WeatherLayerPane file UID0000P8

- Evidence for: current class route, memory locality, generated source, and source-family docs place the method in `NexusTK/map/WeatherLayerPane.cpp`.
- Evidence against: a by-file page is broader than the true class owner and should not replace direct semantic ownership.
- Decision: accepted final file root through the class emitter chain, rejected as direct owner.

### 3. TimerHandler or migration aggregate UID0001NZ

- Evidence for: callback enters through TimerHandler facet; UID0001NZ historically indexed the contiguous weather/rain code island.
- Evidence against: target accesses concrete Weather state and class virtuals; TimerHandler owns only the generic callback contract/scheduler; UID0001NZ is a non-emitting migration index after exact child split.
- Decision: rejected as direct owner/emitter.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new source file. Use existing owner UID0000G1 and selected file route UID0000P8.
- Likely full contents: canonical WeatherLayerPane header declares the class, inherited interfaces, constructor, OnTimer, frame-change hook, and tail fields; WeatherLayerPane.cpp contains exact qualified child definitions.
- Candidate related items that belong: Weather constructor, this timer callback, generated vtable semantics, and shared class declarations.
- Candidate related items rejected: Rain/Snow/Swallow concrete bodies remain their own class-owned children even if current generated routing shares one source root.
- Standalone/narrow/broad source inference: target is one narrow class method, not a standalone helper or broad range.

## Source Placement

- Recommended placement: declaration in canonical `NexusTK/map/WeatherLayerPane.h`; definition in current [UID:0000P8] `NexusTK/map/WeatherLayerPane.cpp` route through [UID:0000G1].
- This fits current project structure, class ownership, contiguous Weather/Rain/Snow/Swallow implementation island, constructor route, and generated file.
- Rejected placements: `TimerMgr.cpp` (generic scheduler owns no weather state), `MapPane.cpp` (constructs concrete weather but does not own callback), a new `WeatherLayerPaneOnTimer.cpp` (implausibly granular), UID0001NZ aggregate (non-emitting index), and direct Snow/Rain files (only derived behavior).
- Remaining uncertainty: exact original physical split among dedicated concrete-weather `.cpp` files is not symbol-proven. Current one-file route is the operational source placement and is adequate; historical alternatives remain documented rather than blocking code.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: target starts at modeled function `0x005c13b0`, ends at `0x005c1408`, and is isolated by fifteen leading and eight trailing `0xCC` bytes. The next function begins at `0x005c1410`.
- Children/subranges: none. The entire 88-byte range is one callback. No jump table, EH funclet, literal pool, embedded data, or second helper exists inside it.
- Padding/data/code distinctions: both fences remain compiler alignment in by-memory ignored documentation and must not be included in target C++ or made into functions/data.
- Parent/container impact: UID0001NZ remains a non-emitting migration index; exact child UID0003PH carries source. No split/merge/reclassification is needed.
- Rename impact: UID remains stable while the physical page title/path changes from `OnTimerEvent` to `OnTimer`; validator should repair links during the later callback validation.

## Negative Evidence Summary

- No direct callers were found. This does not weaken ownership because three exact vtable data xrefs are the intended virtual route.
- No target-start pointer exists outside the three vtable cells; no RVA pattern or target-end xref adds a hidden owner.
- The first rectangle argument is not `m_weatherBounds`: complete `+0xfc` would be facet `+0x58`, while the binary passes facet `-0x60`, complete `+0x44`.
- The `+0x4c` call is not OnPaint/repaint: OnPaint already occupies primary `+0x44`, Rain uses no-op `+0x4c`, and Snow maps `+0x4c` to particle state update/refill.
- Swallow does not inherit this target's dispatch despite deriving from Weather: its TimerHandler cell points to `0x005c2500` and its callback ignores ID 0.
- No zero-count guard exists. Adding one is rejected as behavior divergence; concrete shared-target constructors establish nonzero frame counts before dispatch.
- No destructor work occurs in the range. Timer unregister behavior is inherited and compiler wrappers are outside the range.
- No authoritative original lexical name proves `OnFrameChanged`; leaving `sub_5C1F50`, `func_`, or blank code is nevertheless rejected because cross-vtable semantics support a realistic source name with high probability.

## IDA Rename / Type / Comment Recommendations

- B002 action boundary: B002 remained IDA-read-only. The supervisor independently passed Gate 2A and then applied/read back every accepted Gate 2B action. The recommendation ledger below is retained as historical authorization and reconciled to current APPLIED_VERIFIED state.

### Supervisor Gate 2B Applied/Verified State

- Audit source: `tools/leaser/Agents/b-report-validation-audit.md`, entry `2026-07-24T01:49:30-04:00`, state `GATE2B_PASSED` for C3PH-016, based on report SHA256 `8501A118F9AB77A1674BD3832DA36754F6FC54248CA2F13431F7DE54744C0773`.
- Live MCP/database: session `1a506870-31a1-4191-836d-54ef871b2064`, database `supervisor_gate2b_0002OT_20260723`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Pre-mutation backup: `E:\NTK\Resources\NexusTK\NexusTK.pre-gate2b-0003PH-20260724-0145.i64`, 143,184,835 bytes, SHA256 `DC6375D64BE25D8225EE64153BD1AE77B5EFB3822CC23E29010462BA4B65`.
- Exact pre-state: `0x005c13b0` was `sub_5C13B0`, prototype `char __thiscall(int this, int, int, int)`, size `0x58`, with data xrefs `0x00631218`, `0x006312a8`, and `0x00631338`. `0x005c1f50` was `sub_5C1F50`, prototype `void __thiscall(_DWORD *this)`, size `0x184`, with sole data xref `0x006312fc`. `TimerHandler` already existed; `SnowingLayerPane` did not.
- Applied type support: declared opaque `struct SnowingLayerPane;` without inventing any layout.
- Applied target identity/readback: `0x005c13b0` is `WeatherLayerPane__OnTimer` with prototype `bool __thiscall WeatherLayerPane__OnTimer(TimerHandler *this, int timerId, int arg0, int arg1)`, size 88, and the exact accepted function comment describing the TimerHandler facet, ID-zero frame advance, inherited visible-bounds invalidation, frame hook, timer-zero reschedule, and unconditional true result.
- Applied Snow identity/readback: `0x005c1f50` is `SnowingLayerPane__OnFrameChanged` with prototype `void __thiscall SnowingLayerPane__OnFrameChanged(SnowingLayerPane *this)`, size 388, and the exact accepted Snow override function comment. `type_inspect` confirms the opaque `SnowingLayerPane` declaration and preserves the existing four-byte `TimerHandler` UDT/vftable member.
- Applied target instruction comments/readback:
  - `0x005c13b3`: `timerId != 0 is acknowledged without changing weather state or scheduling a replacement.`
  - `0x005c13bc`: `Signed m_currentFrame at complete +0xf8 advances modulo signed m_frameCount at +0xf9; the binary has no zero-count guard.`
  - `0x005c13d2`: `Store the signed remainder back to m_currentFrame.` The report requested `0x005c13d3`, but that address is inside the instruction whose owning head is `0x005c13d2`; IDA rejected the non-head address, so the exact comment was applied and read back at `0x005c13d2`.
  - `0x005c13dc`: `Recover complete WeatherLayerPane at TimerHandler facet -0xa4 and call Pane::InvalidateRect(&m_visibleBounds), where m_visibleBounds is complete +0x44.`
  - `0x005c13eb`: `Call WeatherLayerPane primary slot +0x4c, inferred source hook OnFrameChanged(); Snowing overrides this slot at 0x005c1f50.`
  - `0x005c13fb`: `Reschedule timer ID 0 after signed-short m_timerInterval at complete +0xfa with zero payload arguments.`
- Preservation readback: target xrefs remain exactly `0x00631218`, `0x006312a8`, and `0x00631338`; Snow xref remains exactly `0x006312fc`. No bytes, boundaries, vtable cells, protected identities, or unrelated types changed.
- Save evidence: `idb_save` returned `ok:true` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The saved IDB checkpoint is 143,184,868 bytes, last write `2026-07-24T01:49:30.4754725-04:00`, SHA256 `C4250949C7705E08A6753673C2B1AF1BA285BAE6BF8AEE27DAAC78BD884EB76E`. This is the exact UID0003PH Gate 2B checkpoint; later unrelated supervisor saves may advance the shared IDB while preserving these APPLIED_VERIFIED items.

- Target function `0x005c13b0`, Gate 2B pre-state name/type `sub_5C13B0` / `char __thiscall(int this,int,int,int)`:
  - Applied name: `WeatherLayerPane__OnTimer`.
  - Applied IDA declaration: `bool __thiscall WeatherLayerPane__OnTimer(TimerHandler *this, int timerId, int arg0, int arg1);`
  - Applied exact repeatable/function comment: `WeatherLayerPane::OnTimer receives the TimerHandler facet at complete object +0xa4. Timer ID 0 advances signed frame state, invalidates inherited m_visibleBounds, invokes the primary +0x4c frame-change hook, reschedules timer 0, and returns true; nonzero IDs only return true.`
  - Action classification: APPLIED_VERIFIED after Gate 2A. `TimerHandler *this` intentionally models the ABI receiver; the source method remains WeatherLayerPane-owned.
- Target instruction comments:
  - `0x005c13b3`: `timerId != 0 is acknowledged without changing weather state or scheduling a replacement.`
  - `0x005c13bc`: `Signed m_currentFrame at complete +0xf8 advances modulo signed m_frameCount at +0xf9; the binary has no zero-count guard.`
  - Requested `0x005c13d3`; applied/read back at owning instruction head `0x005c13d2`: `Store the signed remainder back to m_currentFrame.`
  - `0x005c13dc`: `Recover complete WeatherLayerPane at TimerHandler facet -0xa4 and call Pane::InvalidateRect(&m_visibleBounds), where m_visibleBounds is complete +0x44.`
  - `0x005c13eb`: `Call WeatherLayerPane primary slot +0x4c, inferred source hook OnFrameChanged(); Snowing overrides this slot at 0x005c1f50.`
  - `0x005c13fb`: `Reschedule timer ID 0 after signed-short m_timerInterval at complete +0xfa with zero payload arguments.`
  - Action classification: APPLIED_VERIFIED. All requested addresses were instruction heads except requested `0x005c13d3`; its exact text was applied/read back at owning head `0x005c13d2`.
- Snow support function `0x005c1f50`, Gate 2B pre-state name/type `sub_5C1F50` / `void __thiscall(_DWORD *this)`:
  - Applied name: `SnowingLayerPane__OnFrameChanged`.
  - Applied declaration after safe opaque declaration `struct SnowingLayerPane;`: `void __thiscall SnowingLayerPane__OnFrameChanged(SnowingLayerPane *this);`
  - Applied exact repeatable/function comment: `SnowingLayerPane override of WeatherLayerPane::OnFrameChanged. When map rendering is ready, move all 200 snow particles and, unless the rolling-refresh flag is set, shift 180 records and refill the leading 20.`
  - Action classification: APPLIED_VERIFIED after Gate 2A. The function's physical page may retain a behavior-descriptive title while documenting this source virtual name.
- Required type invariants: complete WeatherLayerPane size `0x10c`; TimerHandler facet at `+0xa4`; inherited visible bounds at complete `+0x44`; signed char fields at `+0xf8/+0xf9`; signed short at `+0xfa`; RectBounds tail at `+0xfc`; no fabricated complete Weather/Snow UDT is required merely to type these two functions.
- Items intentionally unchanged: decorated Weather/Rain/Snow/Swallow RTTI/vtable names; source-quality `TimerHandler__ScheduleTimer`; shared no-op `0x0041b6a0`; compiler-generated deleting wrappers and adjustor thunks; both CC alignment spans.
- Negative constraints: do not name `0x0041b6a0` as a Weather-specific method because it is shared; do not create code/data in padding; do not type the target receiver as complete `WeatherLayerPane *` without preserving the `+0xa4` ABI adjustment; do not rename the Snow hook `RandomizeSnowParticles` in IDA if the accepted virtual role is `OnFrameChanged`; do not overwrite stronger existing decorated or typed entities.
- Observed readback: target name/type/comment and six instruction comments match above, with the `0x005c13d3` request correctly attached at owning head `0x005c13d2`; xrefs remain exactly the three TimerHandler cells; Snow hook name/type/comment matches above and xref remains `0x006312fc`; function bounds and bytes remain unchanged; no complete UDT layout, new function/data item, or vtable rename was created.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Reconstructable is true, combined assignment-time score already exceeds 85, emitter route is valid, and this pass resolves behavior/name/source blockers.
- Recommended exact formal header/block insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool WeatherLayerPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0) {
        m_currentFrame = (m_currentFrame + 1) % m_frameCount;
        InvalidateRect(&m_visibleBounds);
        OnFrameChanged();
        ScheduleTimer(0, m_timerInterval, 0, 0);
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable; this is NexusTK-owned class code.
- Exact behavior preservation: signed member promotions produce signed division/remainder; assignment truncates to the signed-byte field; no zero guard is introduced; nonzero IDs do no work; `true` is unconditional; rectangle and timer arguments exactly match the body.
- Plausible original source shape: short class method, inherited method calls, no explicit pointer adjustment, no vtable arithmetic, no raw offsets, no compiler cookie/thunk code, and generic unused payload parameters omitted from the definition are normal mid-2000s C++.
- Inferred source-facing names/types: `timerId`, `m_currentFrame`, `m_frameCount`, `m_timerInterval`, `m_visibleBounds`, and `OnFrameChanged`; none uses IDA `sub_`, `_DWORD`, or address-derived labels.
- Naming/style: matches current project `OnTimer`, `OnPaint`, `m_` member, PascalCase class/method, and brace conventions. Runtime exactness and human source shape take priority over stylistic inference.
- Reason code should remain blank: not applicable. Leaving it blank would preserve a resolved empty emitter and contradict current source-quality evidence.

## Final Recommendation

- The target page/title rename to WeatherLayerPaneOnTimer is APPLIED_VERIFIED with UID0003PH and exact range preserved; old path absent and new path present under the same parent.
- Target metadata `92/94`, retained owner/reconstructable/emitter, position `20`, and exact formal C++ are APPLIED_VERIFIED.
- UID0003PG constructor position `10` and deterministic constructor-before-timer source ordering are APPLIED_VERIFIED.
- Exact bytes/hash/bounds, ABI receiver, timer branch/return, signed fields, visible-bounds invalidation, frame hook, scheduling, vtable routes, derived behavior, lifecycle, negative evidence, source placement, historical assumptions, and IDA handoff are incorporated at report-level detail.
- Weather class/file/vtable support and Snow class/method/vtable support now carry exact `OnTimer`/`OnFrameChanged` relationships while preserving UID0003O2 body blockers. Rain and Swallow vtable pages contain the accepted shared/exclusion matrix without metadata churn or source vtable invention.
- Keep Rain, Snow, and Swallow concrete bodies as separate class-owned pages. Keep migration indexes non-emitting and compiler wrappers/padding excluded.
- Future work outside this assignment: reconstruct full UID0003O2 human C++ and canonical full headers from their own evidence. That does not block UID0003PH.

## Recommended Target Doc Changes

- APPLIED_VERIFIED: renamed `by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimerEvent.md` to `by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md` under UID0003PH.
- APPLIED_VERIFIED: claims C3PH-001 through C3PH-016 and C3PH-018 are closed at report-level detail. C3PH-017 remains the post-execution manual coverage handoff.
- APPLIED_VERIFIED: `COMPLETION:92`, `CONFIDENCE:94`, owner `0000G1`, reconstructable true, emitter `0000G1`, position `20`, exact formal block, exact item summary, and preserved/superseded historical assumptions.

## Recommended Support Doc Changes

- APPLIED_VERIFIED UID0003PG: position `10`, exact queued lifecycle and source-order coupling; score/formal unchanged at `92/94`.
- APPLIED_VERIFIED UID0000G1: `90/93`, exact `OnTimer`/`OnFrameChanged` contract and derived matrix, class marker/children preserved without duplicate bodies.
- APPLIED_VERIFIED UID0000P8: exact shared timer/frame-hook/source-route history; current score was already `92/93` rather than the report's stale `91/92` checkpoint, so metadata remained `92/93`.
- APPLIED_VERIFIED UID0003O2: source virtual role/call origin added; body-specific blockers, `88/89`, and blank formal preserved.
- APPLIED_VERIFIED UID0000DC: inherited `4/5/200` timer state and override relation added; `86/88` and class router preserved without body duplication.
- APPLIED_VERIFIED UID0002Z7: adjusted TimerHandler ABI and primary `+0x4c` hook added; `88/92` and no-hand-authored-vtable marker preserved.
- APPLIED_VERIFIED UID0002Z8: its matrix was not explicit, so Rain `0/3/120`, adjusted timer cell, and inherited no-op hook were added; current metadata/formal remained `89/93` and marker-only.
- APPLIED_VERIFIED UID0002Z9: its matrix was not explicit, so Snow `4/5/200`, adjusted shared timer, and Snow override were added; metadata/formal remained `88/92` and marker-only.
- APPLIED_VERIFIED UID0002ZA: its matrix was not explicit, so Swallow-specific `0x100/0x101` timer/exclusion and inherited no-op hook were added; metadata/formal remained `88/92` and marker-only.
- NO_CHANGE_VERIFIED TimerHandler/ScheduledTimerEvent/Pane/GrafPort docs: current contracts already supplied the accepted support evidence.

## Score And Metadata Recommendation

- Assignment-time target: `86/88`, owner `0000G1`, reconstructable true, emitter `0000G1`, blank position/formal.
- Current callback-applied target: `92/94`, same owner/reconstructable/emitter, position `20`, nonblank exact formal.
- Reason not lower: exact bytes/hash/bounds, signed semantics, receiver adjustment, both virtual roles, all arguments/return/control flow, three vtable routes, derived configuration, source placement, lifecycle, negative evidence, and human C++ are resolved and independently cross-supported.
- Reason not higher: exact original spelling/access of `OnFrameChanged`, original PDB/UDT/header formatting, and rebuild-equivalence output are unavailable. These are bounded final-audit uncertainties rather than blockers.
- Score-improvement attempt:
  - Field/helper blocker: resolved through signed instructions, constructor layout, Pane/GrafPort offsets, and TimerHandler helper signature.
  - Caller/reachability blocker: resolved through three exact vtable cells; absence of direct calls is expected virtual dispatch.
  - Virtual `+0x4c` blocker: resolved by cross-vtable role analysis and Snow body; best name `OnFrameChanged` selected.
  - Derived timer values: resolved exactly for Rain `3/120`, Snow `4/5/200`, and Swallow separate IDs/override.
  - Source-placement blocker: resolved to current UID0000P8 route; historical alternatives retained without blocking.
  - Destructor/final-C++ blocker: resolved by inherited timer teardown and exact target-only formal.
- Support metadata result: UID0003PG position `10`; UID0000G1 `90/93`; all other listed support metadata unchanged. Callback readback corrected report-only stale checkpoints for UID0000P8 (already `92/93`) and UID0002Z8 (already `89/93`) without changing those scores.

## Open Questions With Attempted Resolution

- Exact original lexical spelling of primary slot `+0x4c`: checked all four primary vtables, call site, Snow override body, class/method docs, current IDA names/comments, source-route docs, and generated output. No original symbol survives. `OnFrameChanged` is the highest-probability source-facing resolution; it is used rather than leaving a synthetic name. Confidence impact: caps below `95`, no C++ block.
- Exact access qualifier of `OnFrameChanged`: behavior suggests a derived override hook, so `protected virtual` is the most plausible header declaration. Public/private visibility is not encoded. This is a header-format uncertainty only; runtime method body and virtual slot remain exact.
- Exact original dedicated-file split: checked current class/file ownership, generated route, contiguous implementation/vtable context, and historical alternatives. The current selected WeatherLayerPane.cpp/header route is the implementation decision. Lack of original path string caps final-audit confidence but does not defer code.
- Base constructor zero-delay versus derived initialization: checked all three direct derived callers and concrete vtables/state. The event is queued, and concrete constructors install final state before dispatch; no standalone Weather construction caller exists. No source guard belongs in OnTimer.
- Whether UID0003O2 full C++ is now solved: no. This report solves its virtual role/name and call origin, not every particle field/table/helper. It remains a separate exact target with blank formal; UID0003PH does not depend on reconstructing that body inline.
- No other material open question remains for target behavior, ownership, source placement, range, emitter route, or first C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected manual rows: by-memory UID0003PH at line 3939, UID0002Z7 at line 4279, no UID0003O2 row; by-class UID0000G1 at line 599 and UID0000DC at line 502; by-file UID0000P8 at line 305.
- File/placement: `by-memory/-coverage-report.md`, replace the UID0003PH row in address order with:

```markdown
        - [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md) 0x005c13b0-0x005c1408 | virtual timer method | WeatherLayerPaneOnTimer : reconstructable : 92% : very-strong : Exact 88-byte/SHA256-anchored bool WeatherLayerPane::OnTimer(int,int,int) entered through the TimerHandler +0xa4 facet; timer ID 0 advances signed-byte frame state, invalidates inherited m_visibleBounds, invokes inferred source hook OnFrameChanged, and reschedules from signed-short m_timerInterval, while all IDs return true; Weather/Rain/Snow vtable routes, Rain 3/120, Snow 4/5/200 plus override behavior, Swallow exclusion, padding, source route, and human C++03 formal are documented.
```

- File/placement: `by-memory/-coverage-report.md`, replace stale UID0002Z7 row with:

```markdown
        - [UID:0002Z7][0x0063118c-0x0063121c.WeatherLayerPaneVtableData](by-memory/0x0063118c-0x0063121c.WeatherLayerPaneVtableData.md) 0x0063118c-0x0063121c | vtable-data | WeatherLayerPaneVtableData : reconstructable : 88% : very-strong : Exact base weather-layer RTTI/vtable child assigned to direct class parent UID0000G1; constructor stores, derived callers, adjusted TimerHandler OnTimer slot, primary OnPaint and +0x4c frame-change hook roles, thunk slots, pointer negatives, and source-declared/generated-binary no-hand-authored-vtable policy are documented.
```

- File/placement: `by-memory/-coverage-report.md`, insert UID0003O2 in address order after the Snow update/render child and before the Snow render child:

```markdown
        - [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) 0x005c1f50-0x005c20d4 | virtual method | SnowingLayerPaneRandomizeSnowParticles : reconstructable : 88% : strong : Exact SnowingLayerPane override of inferred WeatherLayerPane::OnFrameChanged, reached from shared UID0003PH after frame advance; the 200-entry move pass, optional 180-record shift, 20-entry refill, map-ready gate, vtable-only route, particle layout, tables, padding, and remaining body-specific no-code blockers are preserved.
```

- File/placement: `by-class/-coverage-report.md`, replace UID0000G1 row with:

```markdown
- [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md) : reconstructable : 90% : very-strong : Exact 0x10c Pane-derived weather base with source-authored constructor and bool OnTimer callback, TimerHandler facet at +0xa4, signed m_currentFrame/m_frameCount/m_timerInterval tail, RectBounds m_weatherBounds, inherited m_visibleBounds invalidation, protected inferred OnFrameChanged extension hook, exact Weather/Rain/Snow shared timer routes, Rain 3/120 and Snow 4/5/200 behavior, Swallow timer override exclusion, and current WeatherLayerPane.cpp/header route; class marker plus children emits qualified bodies without hand-authored vtables or duplicate methods.
```

- File/placement: `by-class/-coverage-report.md`, replace UID0000DC row with:

```markdown
- [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) : reconstructable : 86% : strong : Exact Snowing constructor/render/destructor family with inherited UID0003PH bool OnTimer configuration 4/5/200, primary +0x4c SnowingLayerPane::OnFrameChanged override at UID0003O2, MapPane caller, Weather base-constructor call, vtable stores, adjusted thunks, particle methods/tables, and preserved source-placement/body-specific caveats.
```

- File/placement: `by-file/-coverage-report.md`, replace UID0000P8 row with:

```markdown
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) : reconstructable : 92% : very-strong : Weather-layer source family under NexusTK/map/ with exact Weather/Rain/Snow/Swallow routes, 0x10c Weather base, source constructor and bool OnTimer, signed animation tail, inherited visible-bounds invalidation, inferred OnFrameChanged hook with Snow override, Rain 3/120 and Snow 4/5/200 semantics, weather tables/resources, and current WeatherLayerPane.cpp plus canonical header obligations; historical dedicated-file alternatives remain documented but do not block the selected route.
```

- Reason B agent must not apply directly: all `-coverage-report.md` files are supervisor-owned collision points. Manual rows are applied only after supervisor execution/archive and then validated by the supervisor.

## Follow-Up Actions

- Supervisor Gate 1, Gate 2A, and C3PH-016 Gate 2B are complete and passed. The reconciled report artifact now requires a fresh exact-artifact continuity audit before execution.
- After the fresh audit passes, the supervisor may execute/archive this report. Only afterward may the supervisor apply and validate the exact C3PH-017 manual coverage payloads.
- B002 work is complete: accepted C3PH-001..016 and C3PH-018 are APPLIED_VERIFIED. B002 did not perform IDA, coverage, audit, or report lifecycle work and must not perform the remaining supervisor-only actions.
- A-agent actions: none.
- B002 future research: no separate research assignment is required before implementation. UID0003O2 full-body reconstruction remains its own future target and must not be folded into this callback beyond the accepted support-role synchronization.

## Confidence

- Recommendation confidence: `94/100` for target behavior, ABI, ownership, emitter route, and exact body; high probability for `OnFrameChanged` lexical reconstruction.
- Score confidence: strong. `92/94` reflects an implementation-ready method while reserving `95+` for original lexical/UDT/header and rebuild-equivalence proof.
- Remaining uncertainty: exact historical hook spelling/access and original physical file split only. No remaining uncertainty changes execution behavior or justifies synthetic names/blank code.

## Validator Results

- All authorized ordinary-file validators ran serially from `source-3/project-documentation` with `--mode file --apply --queue-timeout 240`; every command exited `0` with `ok:1`:
  - UID0003PH renamed target: command `000000017019`, `2026-07-24T01:12:47-04:00`; applied path/metadata/position/formal/link updates and deferred generation.
  - UID0003PG constructor: command `000000017021`, `2026-07-24T01:13:20-04:00`; position `10`, `ok:1`.
  - UID0000G1 Weather class: command `000000017023`, `2026-07-24T01:14:16-04:00`; `90/93`, `ok:1`.
  - UID0000P8 Weather file: command `000000017025`, `2026-07-24T01:15:00-04:00`; current `92/93` retained, `ok:1`.
  - UID0003O2 Snow method: command `000000017028`, `2026-07-24T01:17:01-04:00`; registry/reference route repaired, `88/89` and blank formal retained, `ok:1`.
  - UID0000DC Snow class: command `000000017030`, `2026-07-24T01:17:42-04:00`; metadata/formal unchanged, `ok:1`.
  - UID0002Z7 Weather vtable: commands `000000017031` and focused consistency revalidation `000000017039` at `2026-07-24T01:22:23-04:00`; final `ok:1`.
  - UID0002Z8 Rain vtable: commands `000000017033` and focused current-score revalidation `000000017040` at `2026-07-24T01:22:25-04:00`; final `ok:1`.
  - UID0002Z9 Snow vtable: command `000000017034`, `2026-07-24T01:19:57-04:00`; `ok:1`.
  - UID0002ZA Swallow vtable: command `000000017036`, `2026-07-24T01:20:29-04:00`, with `--wait-generated`; `ok:1`, generated refresh completed.
- Generated readback: `auto-generated/NexusTK/map/WeatherLayerPane.cpp` is validator command `000000017036`, SHA256 `8DF6A5C15294DAEDAEF4E2912FBD6A896574F377A5449980D927443FCFD82E39`, 17,602 bytes / 425 lines. It contains one UID0003PH marker, one `WeatherLayerPane::OnTimer` definition, one new target path, zero `WeatherLayerPaneOnTimerEvent` strings, and the expected UID0003PG/UID0002Z7/UID0002Z8/UID0002Z9/UID0002ZA markers.
- Warnings: command `000000017025` observed pre-existing missing-reference warnings, including then-unregistered UID0003O2; command `000000017028` added UID0003O2 registry/reference entries. Full generated command `000000017036` reported project-wide pre-existing `autogen_children_marker_missing:71`, `autogen_children_fallback_insert:13`, and `autogen_emitter_has_no_code:103`, plus validator-owned deletion of obsolete generated `NexusTK/map/RainingLayerPane.cpp`. None is a UID0003PH callback validation failure. Later prose-only commands `000000017039/40` deferred generation and did not alter any formal block, so command `000000017036` remains the current generated-content checkpoint.

## Changed Files

- Renamed and modified: `by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimerEvent.md` -> `by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md`; old path absent, new path present under the same resolved parent; final SHA256 `7D0445A88D8D345230596FA03E664A2047F6F05229111D774A542BF5FEA60BE0`, 15,633 bytes / 133 lines, validator `000000017019`.
- Modified: UID0003PG constructor SHA256 `EE340F29E075DD1FAB492895989E9D35562D69B839C683B4BFB818FF29F1AE24`, 12,210 bytes / 113 lines, validator `000000017021`.
- Modified: UID0000G1 Weather class SHA256 `734CDD50469FBEC5730D4B3AE301526CE5C1B248E0762C7E41C29EE102EB9CBC`, 20,910 bytes / 158 lines, validator `000000017023`.
- Modified: UID0000P8 Weather file historical B002 post-callback checkpoint SHA256 `E9044749143830EAE52848D6C9F91C7B54CED060AFA89D98B04F2A429B94E4CB`, 46,698 bytes / 271 lines, validator `000000017025`. After later unrelated B003 work, the exact current continuity checkpoint is SHA256 `EA4D0C2D3B3809F53DF9F2332DAA3C7EC5162D9F62D5C691724C5DBCCB52F247`, 51,209 bytes / 297 lines; the later additions preserve every accepted B002 C3PH claim.
- Modified: UID0003O2 Snow method SHA256 `E86AFFCF85C68BA9508957198E56906EFB9897E1804F5BF3EC8A02E475BDDE2B`, 25,548 bytes / 209 lines, validator `000000017028`.
- Modified: UID0000DC Snow class SHA256 `4E410A9602366BB1FA9022C777E54D167AFA22072BA6625398CD0D23F4D3AF7D`, 17,123 bytes / 124 lines, validator `000000017030`.
- Modified: UID0002Z7 Weather vtable SHA256 `56C4F109E38E0CA1DED9F8EA7CA43815B91D2F57F98CEF3A0739973ADA881247`, 20,040 bytes / 217 lines, final validator `000000017039`.
- Modified: UID0002Z8 Rain vtable historical B002 post-callback checkpoint SHA256 `D012ABB0934D905B2BC835B0B7D3C796AF48F1F66CBA73BB92F6D9647299F65C`, 24,306 bytes / 190 lines, validator `000000017040`. After later unrelated B003 work, the exact current continuity checkpoint is SHA256 `EBB73F32CA8A64B5817D5099009AD1782800B43C86269A31888EC16176383F3B`, 26,694 bytes / 202 lines; the later additions preserve every accepted B002 C3PH claim.
- Modified: UID0002Z9 Snow vtable SHA256 `4ADD2100BEDBBA53CDF702D32B0FA1BE0704EC5DBC58207498541C89C60B5D32`, 20,441 bytes / 160 lines, validator `000000017034`.
- Modified: UID0002ZA Swallow vtable SHA256 `7EE43ECF245B01D50FEBCC4D588E2334BA30850916DDFE9240C0E75B9BCD1039`, 15,581 bytes / 134 lines, validator `000000017036`.
- Validator-owned generated refresh: historical B002 post-callback checkpoint SHA256 `8DF6A5C15294DAEDAEF4E2912FBD6A896574F377A5449980D927443FCFD82E39`, 17,602 bytes / 425 lines, command `000000017036`. After later unrelated B003 work, the exact current continuity checkpoint for `auto-generated/NexusTK/map/WeatherLayerPane.cpp` is SHA256 `CC1B1D997BF33BE75AE4F8D2E9FC50248CEE1A326C5B78E1B2DF6F16C754D41B`, 17,829 bytes / 433 lines, with one UID0003PH marker, one `WeatherLayerPane::OnTimer` definition, and zero UID0003PH empty markers. The later generated update preserves every accepted B002 C3PH claim. No B002 direct generated edit occurred.
- No ordinary support edit required for UID0002Z8/UID0002Z9/UID0002ZA was skipped: readback showed each matrix was incomplete, so each received the accepted prose-only synchronization. TimerHandler/ScheduledTimerEvent/Pane/GrafPort required no change.
- All B002 ordinary leases were released immediately after validation. Final `current_leases.md` readback reports no active leases.
- Report execution: not run. B002 did not run, probe, dry-run, or invoke `execute_report` or any lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 validation passed exact pre-callback SHA `F43290689550AB6628E8921EEDC8F3D1B04E1211D279D2C8FB053C0570E55608` before implementation.
- [x] Target/support docs to update are named exactly with claim-level content.
- [x] Additional declared UIDs are absent; support UIDs are not misrepresented as report-covered targets.
- [x] Current target state and actual evidence checked are recorded.
- [x] Claim And Incorporation Ledger contains destination and current verification state for all 18 claims.
- [x] Metadata/score changes are exact and current-state mismatches were reconciled without stale score churn.
- [x] Score-limiting blockers were researched to implementation-ready resolution; bounded lexical uncertainty has a high-probability inference rather than deferral.
- [x] Owner/emitter/reconstructable disposition is exact.
- [x] Rename/range/padding disposition is exact; no new child or split is required.
- [x] Source placement and IDA rename/type/comment handoff are exact.
- [x] Supervisor Gate 2B IDA handoff was APPLIED_VERIFIED after Gate 2A at `2026-07-24T01:49:30-04:00`, including exact readback and saved-IDB evidence.
- [x] Exact first-draft C++ formal insertion is supplied and applied.
- [x] Third-party import directive is confirmed not applicable.
- [x] Exact target/support facts are listed at report-level detail.
- [x] Historical assumptions, rejected alternatives, and negative evidence are preserved.
- [x] Wave2/Wave3 mentions encountered in guidance were ignored as stale workflow artifacts.
- [x] Open questions were resolved or bounded with exhaustive evidence and score impact.
- [x] Callback validator scope was identified during report-only work and executed only after Gate 1 acceptance.
- [x] Generated-state expectation and exact supervisor-owned manual coverage text are supplied.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at the exact Gate 1 SHA above.
- [x] All accepted target/support details incorporated at report-level detail.
- [x] Target UID0003PH verified independently against ledger and destinations.
- [x] Claim ledger updated with implementation verification for accepted C3PH-001..015 and C3PH-018.
- [x] Metadata/score/owner/emitter/position/rename/C++ changes applied exactly.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved in ordinary docs.
- [x] Open questions and bounded inferences reconciled in ordinary docs.
- [x] Authorized serial scoped ordinary-file validators run and recorded.
- [x] Generated output refreshed and UID0003PH confirmed filled at the expected route.
- [x] Supervisor independent Gate 2A passed at `2026-07-24T01:44:10-04:00`.
- [x] Supervisor-owned IDA changes passed Gate 2B and C3PH-016 is APPLIED_VERIFIED; B002 made no IDA mutation.
- [ ] Fresh supervisor exact-artifact Gate 1/Gate 2 continuity audit remains required for this reconciled report hash.
- [ ] Supervisor execute_report/archive remains supervisor-only after Gate 2A and Gate 2B clearance.
- [ ] Exact manual coverage payload remains unapplied by B002 for supervisor post-execution handoff.
- [x] Remaining unapplied items are listed exactly: fresh exact-artifact continuity audit, supervisor execution/archive, and post-execution C3PH-017 manual coverage.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000017075","destination_path":"executed-b-agent-research/B002/0003PH-WeatherLayerPaneOnTimerEvent-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0003PH-WeatherLayerPaneOnTimerEvent-empty-emitter-source-quality.md","timestamp":"2026-07-24T02:15:18-04:00","uid":"0003PH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
