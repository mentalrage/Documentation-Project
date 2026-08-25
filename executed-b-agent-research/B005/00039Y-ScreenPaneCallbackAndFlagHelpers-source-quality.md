** TARGET-REPORT-UID:00039Y **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 00039Y **
# 00039Y ScreenPaneCallbackAndFlagHelpers Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00039Y] reconstructable, but reroute its direct semantic owner from [UID:0000NB][ScreenPane](by-file/ScreenPane.md) to [UID:0000CB][ScreenPane](by-class/ScreenPane.md). Keep generated output routed through the ScreenPane class to `NexusTK/ui/core/ScreenPane.cpp`.
- Recommended metadata: raise the target from `COMPLETION:85`, `CONFIDENCE:87` to `COMPLETION:88`, `CONFIDENCE:90`; set `CANONICAL_OWNER:0000CB`; set `EMITTER_UIDS:0000CB`; keep `RECONSTRUCTABLE:TRUE`.
- Recommended source-facing names:
  - `0x005590e0`: `ScreenPane::QueueFadeInCallback` / `ScheduleFadeInCallback`.
  - `0x00559110`: `ScreenPane::QueueFadeOutCallback` / `ScheduleFadeOutCallback`.
  - `0x00559140`: `ScreenPane::SetFadeTransitionState` or `SetPresentationTransitionState`.
  - `0x00559160`: `ScreenPane::IsFadeTransitionActive` or `IsPresentationTransitionActive`.
- The callback IDs are best interpreted as screen fade event IDs: `0x4664496e` is `FdIn`, and `0x46644f74` is `FdOt`. These names are confirmed by `ScreenPane::HandleMessage`, which branches on the same two IDs and performs the fade-in/fade-out transition setup.
- The `this+0x5a4` field should no longer be documented as only a generic "flag." Best source-facing name is `m_fadeTransitionState` or `m_presentationTransitionState`; it is a dword/enum-like ScreenPane state field with values used by `HandleMessage`, the retained transition wrappers, and Surface presentation readers.
- No split is required before implementation because every executable subrange belongs to the same ScreenPane field/helper family and exact padding is already documented. A future one-function-per-page split is optional, not a blocker.
- Formal C++ is eligible and should be populated in the implementation callback if the supervisor accepts this report. The code should be a small four-method ScreenPane helper cluster, not decompiler-shaped pseudocode.
- No by-* docs, generated files, project-level reports, or `by-memory/-coverage-report.md` were edited in this report-only pass.

## Target

- Assignment id: `B005-goal2-screen-pane-callback-and-flag-helpers-source-quality-00039Y-20260619`
- Target UID: [UID:00039Y]
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\00039Y-ScreenPaneCallbackAndFlagHelpers-source-quality.md`
- Current target state: `85/87`, `CANONICAL_OWNER:0000NB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NB`, blank formal C++.
- Current generated state: `auto-generated/NexusTK/ui/core/ScreenPane.cpp` contains only an empty emitter marker for [UID:00039Y].

## Evidence Checked

- Required workflow and source-inference guidance:
  - `tools/leaser/Agents/Supervisor.md`
  - `tools/leaser/Agents/Agent-B005/goal.md`
  - `tools/leaser/Agents/Agent-B005/notes.md`
  - `by-structure.md`
  - `inference_research.md`
  - `by-project-structure/proposed-source-tree.md`
- Target and direct source route:
  - `by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md`
  - `by-class/ScreenPane.md`
  - `by-file/ScreenPane.md`
  - `auto-generated/NexusTK/ui/core/ScreenPane.cpp`
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `by-memory/-coverage-report.md`
- Parent/sibling memory docs:
  - `by-memory/0x00556910-0x00557132.ScreenPane.md`
  - `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`
  - `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`
  - `by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md`
  - `by-memory/0x00558680-0x00558688.UnresolvedPresentationFlagSetter.md`
  - `by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md`
  - `by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md`
  - `by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md`
  - `by-memory/-ignored.md`
- Caller/dependency docs:
  - `by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md`
  - `by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md`
  - `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`
  - `by-memory/0x00464f40-0x00464f47.ApplicationIsExitRequested.md`
  - `by-global/g_pScreenPane.md`
  - `by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md`
  - `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
- Prior B-agent research:
  - `tools/leaser/Agents/Agent-B001/research/executed/older/0001G6-SurfacePresentation.md`
  - `tools/leaser/Agents/Agent-B012/research/0003A3-ScreenPanePresentationTraversal-source-quality.md` was found as a sibling lead only; this report independently checked current docs and local exports.
- Local exported function data:
  - `resources/exported_data/functions/0x005590e0.json`
  - `resources/exported_data/functions/0x00559110.json`
  - `resources/exported_data/functions/0x00559140.json`
  - `resources/exported_data/functions/0x00556d50.json`
  - `resources/exported_data/functions/0x00559200.json`
  - `resources/exported_data/functions/0x005592b0.json`
  - `resources/exported_data/functions/0x005975e0.json`
- Current live IDA MCP availability: attempted `tools/list` at `http://127.0.0.1:13337/mcp`; current session returned `Unable to connect to the remote server`. Current-session facts below therefore distinguish local exported data and existing live-IDA-backed docs from a fresh live MCP pass.

## Executive Recommendation

[UID:00039Y] is best treated as a small ScreenPane class helper cluster:

1. Two modeled queue helpers schedule fade-message callbacks through the embedded `TimerHandler` facet at ScreenPane offset `+0xa4`.
2. Two raw helpers set and test the same ScreenPane fade/presentation transition state at `+0x5a4`.
3. All four bodies use a `ScreenPane *this` object, not a Surface object, TimerMgr object, LogoPane object, or free file-level helper.

The current file-level owner was defensible during the split pass because the cluster contains several tiny helpers and raw bodies. Source-quality reanalysis now favors the class as the narrow direct semantic owner. `ScreenPane.cpp` remains the source file and generated route because [UID:0000CB] already emits through [UID:0000NB].

This is not a no-code item. It is eligible for first-draft C++ under the active combined-score/emitter gate. The C++ should be small and source-shaped: two queue methods, one setter, and one predicate.

## Exact Boundary And Split Decision

The target range is exact and should remain `0x005590e0-0x0055916b`.

| Range | Existing status | Best source-facing role | Split decision |
| --- | --- | --- | --- |
| `0x005590e0-0x00559108` | modeled `sub_5590E0`, exported size 40 bytes | `ScreenPane::QueueFadeInCallback(LObject *callback)` | Keep in target; source method body ready. |
| `0x00559108-0x00559110` | padding | `0xcc` alignment | Already represented in `by-memory/-ignored.md`; do not emit. |
| `0x00559110-0x00559138` | modeled `sub_559110`, exported size 40 bytes | `ScreenPane::QueueFadeOutCallback(LObject *callback)` | Keep in target; source method body ready. |
| `0x00559138-0x00559140` | padding | `0xcc` alignment | Already represented in `by-memory/-ignored.md`; do not emit. |
| `0x00559140-0x00559151` | raw/modeled by Ghidra only, no caller list | `ScreenPane::SetFadeTransitionState(unsigned char state)` | Keep in target as retained raw helper; source body ready with liveness caveat. |
| `0x00559151-0x00559160` | padding | corrected true padding span | Already represented in `by-memory/-ignored.md`; stale `0x0055914f`/`0x00559150` padding starts are invalid. |
| `0x00559160-0x0055916b` | raw predicate, no exported function file found | `ScreenPane::IsFadeTransitionActive() const` | Keep in target as retained raw helper; source body ready with liveness caveat. |

No split is required because:

- All executable subranges have the same object owner and source file.
- The internal padding has already been recorded in the ignored ledger.
- The two raw helper starts are too small to justify separate owner decisions; their main unresolved issue is liveness, not ownership.
- The target title accurately describes a helper family, and a by-memory page may emit multiple small class methods when they form a tight source cluster.

Optional future split:

- If the project later enforces one function body per emitting by-memory page, split the four executable helpers into exact children and leave this page as a non-emitting index. That is a style/assembly choice, not a current source-quality blocker.

## Caller, Reachability, And Data-Flow Evidence

| Address / item | Evidence | Meaning |
| --- | --- | --- |
| `0x005590e0` | Local export reports exactly one caller: `0x004f4e87` in `LogoPane` constructor. | Startup logo construction queues a ready callback through the ScreenPane fade-in path. |
| `0x00559110` | Local export reports callers at `0x00464efa` in `Application::RequestExit` and `0x004f52c8` in `LogoPane::QueueAdvanceToNextScreen`. | Application exit and startup-logo advance both queue fade-out/deferred completion work. |
| `0x00559140` | Local export reports zero callers and zero callees; target docs record no direct caller xrefs. | Complete setter body but retained/no-live-xref liveness caveat remains. |
| `0x00559160` | No local export file found; target docs record raw predicate body and no direct caller xrefs. | Complete predicate body but retained/no-live-xref liveness caveat remains. |
| `0x005975e0` | TimerHandler wrapper forwards through `g_pTimerMgr` to scheduler queue helper `0x00597910`; high fan-in across UI classes. | The queue helpers are ScreenPane users of a generic timer-handler scheduler, not TimerMgr-owned behavior. |
| `0x00556d50` | `ScreenPane::HandleMessage` branches on `0x4664496e` and `0x46644f74`, updates `+0x5a4`, `+0x5a8`, and `+0x5ac`, and calls traversal/scheduling helpers. | Confirms callback IDs and the fade/presentation state field semantics. |
| `0x00559200` and `0x005592b0` | Retained transition wrappers set the same `+0x5a4` field to `1`, then `2` or `3`, and set `+0x5ac` to `0x18` or `0`. | Confirms `+0x5a4` is an enum-like transition state, not just a boolean flag. |
| Surface presentation helpers | `0x00557140` and `0x005583a0` read `+0x5a4` and use `+0x5ac`. | Surface consumes ScreenPane transition state; it does not own the field. |

## Function-Level Evidence

### `0x005590e0` Queue Fade-In Callback

Local export facts:

- IDA name: `sub_5590E0`.
- Size: 40 bytes.
- IDA signature shape: `int __thiscall(_DWORD *this, int)`.
- Decompiler body:
  - writes `this[361] = 0`, which is ScreenPane offset `+0x5a4`;
  - calls `sub_5975E0(this + 41, 1180977518, 0, callback, 0)`;
  - returns the schedule wrapper result.
- The `this + 41` dword pointer is ScreenPane offset `+0xa4`.
- The integer `1180977518` is `0x4664496e`, documented by `ScreenPane::HandleMessage` as `FdIn`.

Best name:

```cpp
int ScreenPane::QueueFadeInCallback(LObject *callback);
```

Alternative acceptable name: `ScheduleFadeInCallback`.

Rejected names:

- `sub_5590E0` / `FUN_005590e0`: generated labels, not source names.
- `TimerHandler::ScheduleTimer`: this helper calls the timer handler; it is not the timer handler itself.
- `LogoPaneReadyCallback`: LogoPane is the only direct caller, but the body is a ScreenPane queue helper and the event ID is a screen fade message.
- `SetFlagAndQueueCallback`: too generic; it loses the confirmed `FdIn` event semantics.

### `0x00559110` Queue Fade-Out Callback

Local export facts:

- IDA name: `sub_559110`.
- Size: 40 bytes.
- IDA signature shape: `int __thiscall(_DWORD *this, int)`.
- Decompiler body:
  - writes `this[361] = 0`, again ScreenPane `+0x5a4`;
  - calls `sub_5975E0(this + 41, 1180979060, 0, callback, 0)`;
  - returns the schedule wrapper result.
- The event integer `1180979060` is `0x46644f74`, documented by `ScreenPane::HandleMessage` as `FdOt`.

Best name:

```cpp
int ScreenPane::QueueFadeOutCallback(LObject *callback);
```

Alternative acceptable name: `ScheduleFadeOutCallback`.

Caller interpretation:

- `Application::RequestExit` uses this helper to defer final shutdown signaling through the root screen when a screen pane exists.
- `LogoPane::QueueAdvanceToNextScreen` uses this helper to transition out from the startup logo before invoking the next-screen callback.
- Both callers create `PlainMemberFunctionObject0<...>` callback objects and pass them as the payload argument.

### `0x00559140` Raw Transition-State Setter

Local export facts:

- Ghidra export models a 17-byte `__thiscall` helper at `0x00559140`.
- Signature shape: `void __thiscall FUN_00559140(void *this, byte state)`.
- Body: zero-extends the byte argument and stores it as a dword at ScreenPane offset `+0x5a4`.
- Export reports zero callers and zero callees.
- Existing target docs record the corrected instruction boundary: `retn 4` consumes bytes through `0x00559150`, so padding begins at `0x00559151`.

Best name:

```cpp
void ScreenPane::SetFadeTransitionState(unsigned char state);
```

Alternative acceptable name: `SetPresentationTransitionState`.

Type decision:

- The field should be modeled as an enum-like dword (`int` or `ScreenFadeTransitionState`), not as a byte. The setter accepts a byte-sized source argument or compiler-narrowed argument and writes the full dword field.
- The name should say "state" rather than "flag" because visible values include `0`, `1`, `2`, and `3`.

Liveness caveat:

- No direct caller is currently documented, and live MCP was unavailable for a fresh raw VA/RVA pointer scan in this session.
- The helper is still source-shaped: a complete thiscall setter on a ScreenPane field with exact padding on both sides.
- Treat it like other retained/no-live-xref tiny ScreenPane helpers unless a future scan proves it is unreachable compiler debris. It is not compiler debris by body shape.

### `0x00559160` Raw Transition-State Predicate

Existing target facts:

- Raw body compares the dword at `this+0x5a4` against zero, sets `al` if nonzero, and returns.
- No direct caller xrefs are documented.
- End is `0x0055916b`, followed by ignored `0x0055916b-0x00559170` padding before `SurfaceRestoreLostSurfaces`.

Best name:

```cpp
bool ScreenPane::IsFadeTransitionActive() const;
```

Alternative acceptable name: `IsPresentationTransitionActive`.

Rejected names:

- `GetFlag`: loses transition state semantics.
- `HasCallback`: wrong. The field is a state enum; the callback payload is stored separately at `+0x5a8`.
- Surface or cursor predicate names: rejected because all field semantics trace back to ScreenPane transition handling.

## Heuristic / Inference Reanalysis And Validation

### Source-Bearing Versus No-Code

Best conclusion: [UID:00039Y] is source-authored ScreenPane helper code and should not remain blank/no-code.

Evidence:

- The two modeled functions are normal thiscall methods over a ScreenPane object and call a generic timer-handler scheduler with ScreenPane fade event IDs.
- The two raw helpers are normal tiny method-shaped bodies over the same ScreenPane field.
- The field at `+0x5a4` is initialized and used by documented ScreenPane transition code.
- Padding boundaries are known and recorded; none of the executable spans is alignment.
- The generated output currently has an empty emitter marker, not a no-code proof.

Rejected no-code/compiler-output alternatives:

- Compiler-generated thunk: rejected. None of the four helpers is an adjustor thunk or tail jump. The queue helpers have full field write plus scheduler-call bodies; the raw helpers read/write source state.
- TimerMgr wrapper: rejected. `0x005975e0` is the TimerHandler/TimerMgr wrapper; this target only calls it.
- Dead padding: rejected. The raw setter and predicate decode to complete methods between `0xcc` boundaries.
- Callback object generated code: rejected. The callback object allocation and vtable writes occur in LogoPane/Application callers, not in this target.

### Callback ID Naming

Best source-facing constants:

```cpp
const int kScreenFadeInEvent = 0x4664496e;  // FdIn
const int kScreenFadeOutEvent = 0x46644f74; // FdOt
```

Evidence:

- `0x005590e0` schedules `0x4664496e`.
- `0x00559110` schedules `0x46644f74`.
- `ScreenPane::HandleMessage` has dedicated branches for exactly those two values.
- Existing ScreenPane docs already decode them as `FdIn` and `FdOt`.
- The `FdIn` branch sets the transition state to `2` and the countdown/extent field to `0x18`; the `FdOt` branch sets the transition state to `3` and clears that countdown/extent field.

Rejected alternatives:

- Treating them as arbitrary magic integers is no longer justified.
- Naming them as LogoPane events is too narrow; Application exit also uses `FdOt`, and the handler lives on ScreenPane.
- Using Win32 `MAKEFOURCC` would likely produce a different integer packing. The documentation should preserve the exact numeric constants with `FdIn`/`FdOt` comments rather than depending on a portable four-character-literal value.

### Field Name And Layout Inference

Best field map for this target and immediate transition siblings:

| Offset | Best source-facing name | Evidence | Confidence |
| --- | --- | --- | --- |
| `+0x0a4` | `m_timerHandler` / `m_frameTimerHandler` | Queue helpers pass `this+0xa4` to `TimerHandler::ScheduleTimer`; ScreenCursorHelpers use the same subobject for presentation timers. | High role, medium exact original name. |
| `+0x598` | current fade/presentation word | Transition helpers copy it into `+0x59a`; constructor initializes it. | Medium; exact field name still open. |
| `+0x59a` | saved/previous fade/presentation word | `HandleMessage` and transition wrappers copy `+0x598` into it before traversal. | Medium; exact field name still open. |
| `+0x5a4` | `m_fadeTransitionState` / `m_presentationTransitionState` | This target clears/sets/tests it; `HandleMessage` uses values `1`, `2`, and `3`; constructor initializes it; Surface presentation reads it. | High role, medium-high exact name. |
| `+0x5a8` | `m_fadeCompletionCallback` / callback payload | `HandleMessage` stores the timer payload `param_2` there; queue helpers pass caller-created callback objects as the timer payload. | High role, medium exact type. |
| `+0x5ac` | `m_fadeStepCount` / `m_fadeCountdown` | `FdIn` branch stores `0x18`; `FdOt` branch stores `0`; Surface presentation consumes it. | Medium-high role, medium exact name. |

Best enum-like interpretation for `+0x5a4`:

| Value | Best interpretation |
| --- | --- |
| `0` | no fade/presentation transition active or transition queue reset. |
| `1` | temporary preparing/traversal state before the branch commits to a fade direction. |
| `2` | `FdIn` active state after traversal setup. |
| `3` | `FdOt` active state after traversal setup. |

Score impact:

- The field role is now strong enough for source-quality C++.
- Exact original spelling remains unknown; this caps the target below final-audit scores but does not block first draft.

### Placeholder Cleanup

Best replacements:

| Placeholder | Replacement | Reason |
| --- | --- | --- |
| `sub_5590E0` / `FUN_005590e0` | `ScreenPane::QueueFadeInCallback` | Schedules `FdIn` through ScreenPane timer handler. |
| `sub_559110` / `FUN_00559110` | `ScreenPane::QueueFadeOutCallback` | Schedules `FdOt` through ScreenPane timer handler. |
| `FUN_00559140` | `ScreenPane::SetFadeTransitionState` | Sets ScreenPane `+0x5a4` state. |
| raw `0x00559160` | `ScreenPane::IsFadeTransitionActive` | Tests ScreenPane `+0x5a4` state. |
| `this+0x5a4` | `m_fadeTransitionState` / `m_presentationTransitionState` | Enum-like transition state, not generic flag. |
| `this+0xa4` | `m_timerHandler` / `m_frameTimerHandler` | Embedded `TimerHandler` scheduler facet. |
| `FittingRoomDialog::meth_0x5975e0` | `TimerHandler::ScheduleTimer` | Ghidra/OOAnalyzer owner pollution; TimerHandler docs prove generic ownership. |
| `MapPane::meth_0x559410` in transition docs | `ScreenPane::TraversePresentationRegion` or traversal helper | Generated owner pollution; sibling docs attach the traversal helper to ScreenPane. |

### Owner / Source Placement Reanalysis

Ranked candidates:

1. [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
   - Evidence for: every executable helper uses ScreenPane `this`; fields are initialized and used by ScreenPane constructor/HandleMessage; event IDs are handled by ScreenPane; class parent clears the gate and emits to ScreenPane.cpp.
   - Evidence against: current target uses file owner; some raw helpers have no direct callers.
   - Decision: accepted as direct semantic owner. No-caller raw helper liveness does not make them file-level helpers.

2. [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
   - Evidence for: owns `NexusTK/ui/core/ScreenPane.cpp`; current route already emits there; can own file-local helpers.
   - Evidence against: less narrow than the ScreenPane class for this target, because all executable bodies are class-method-shaped and operate on class state.
   - Decision: keep as source file route, not direct canonical owner.

3. [UID:0000OC][Surface](by-file/Surface.md)
   - Evidence for: the target sits inside the broad SurfacePresentation neighborhood and Surface presentation functions consume some transition state.
   - Evidence against: queue helpers are called through `g_pScreenPane`; field lives on ScreenPane; `HandleMessage` owns the event branches; Surface is a consumer.
   - Decision: rejected.

4. [UID:0000OT][TimerMgr](by-file/TimerMgr.md) / [UID:0000F0][TimerHandler](by-class/TimerHandler.md)
   - Evidence for: both queue helpers call `TimerHandler::ScheduleTimer`.
   - Evidence against: the target chooses ScreenPane event IDs and resets ScreenPane transition state before calling the generic scheduler.
   - Decision: rejected as direct owner; TimerHandler is a dependency.

5. [UID:00007G][LogoPane](by-class/LogoPane.md) and [UID:00000D][Application](by-class/Application.md)
   - Evidence for: direct callers create callback objects and pass them to these helpers.
   - Evidence against: caller evidence is consumer evidence; Application and LogoPane do not own the ScreenPane timer facet or transition state.
   - Decision: rejected.

6. [UID:00003E][CursorManager](by-class/CursorManager.md)
   - Evidence for: nearby cursor helper island has provisional cursor-manager typed view.
   - Evidence against: no cursor state is touched here; field cluster is fade/presentation state.
   - Decision: rejected.

### Open-Question Closure

Closed:

- `sub_5590E0` and `sub_559110` are no longer unnamed callback dispatch helpers. They are ScreenPane fade-in/fade-out callback queue methods.
- `0x4664496e` and `0x46644f74` are not arbitrary IDs. They are `FdIn` and `FdOt`.
- `this+0x5a4` is not only a flag. It is the ScreenPane fade/presentation transition state.
- File-level direct ownership is no longer the best source-quality answer; class-level ownership is narrower and better supported.
- The target is code-eligible; no-code proof is not applicable.

Still open:

- Exact original member names for `+0x598`, `+0x59a`, `+0x5a4`, `+0x5a8`, and `+0x5ac`.
- Exact callback base type name. Existing docs support `PlainMemberFunctionObject0<...>` callers and `LObject` base construction, but a final header pass should choose the source type used in the ScreenPane method signatures.
- Direct liveness of raw `0x00559140` and `0x00559160`. Current docs/export prove no ordinary callers; no fresh live raw pointer scan was possible in this session.
- Exact TimerHandler wrapper method spelling. `ScheduleTimer` is the best current project-wide name, but TimerHandler docs still call final names medium-high confidence.

These uncertainties cap the score at `88/90`, but they do not block first-draft C++.

## First-Draft C++ Eligibility And Candidate

Eligibility:

- Current average score is `86.0`; recommended score is `89.0`.
- `RECONSTRUCTABLE:TRUE`.
- Current emitter route is present and should be narrowed through [UID:0000CB] to [UID:0000NB].
- Every executable body is understood well enough for a source-shaped first draft.

Recommended first-draft C++:

```cpp
namespace {
const int kScreenPaneFadeInEvent = 0x4664496e;  // FdIn
const int kScreenPaneFadeOutEvent = 0x46644f74; // FdOt
}

int ScreenPane::QueueFadeInCallback(LObject *callbackObject)
{
    m_fadeTransitionState = 0;
    return m_timerHandler.ScheduleTimer(kScreenPaneFadeInEvent, 0, callbackObject, 0);
}

int ScreenPane::QueueFadeOutCallback(LObject *callbackObject)
{
    m_fadeTransitionState = 0;
    return m_timerHandler.ScheduleTimer(kScreenPaneFadeOutEvent, 0, callbackObject, 0);
}

void ScreenPane::SetFadeTransitionState(unsigned char state)
{
    m_fadeTransitionState = state;
}

bool ScreenPane::IsFadeTransitionActive() const
{
    return m_fadeTransitionState != 0;
}
```

Implementation notes:

- If the local TimerHandler wrapper requires integral payloads, use `reinterpret_cast<int>(callbackObject)` for the third payload argument. The source intent is still "pass callback object as event payload."
- If the project chooses the broader field name `m_presentationTransitionState`, use that consistently in this target and in [UID:0003A0].
- If `LObject` is too generic for final headers, use the project's callback base/interface type once FunctionObject pages finalize the name. Do not write `void *` unless no typed callback base is available.
- The two constants should preserve exact numeric values with `FdIn`/`FdOt` comments. Avoid portable `MAKEFOURCC` unless verified to produce these exact integers under the target compiler/source macro.
- The raw setter/predicate should be emitted only if the cluster remains unsplit and retained helpers are accepted as emitted source. If the implementation pass decides no-caller raw helpers should stay documented but non-emitting, keep their prose and omit only those two bodies with an explicit retained-helper policy note.

## Score Recommendation

Recommended score: `COMPLETION:88`, `CONFIDENCE:90`.

Rationale:

- Completion improves because source-facing names, callback ID meanings, field role, class ownership, caller route, and first-draft C++ shape are now resolved.
- Confidence improves because local exports for `0x005590e0`, `0x00559110`, and `0x00559140` agree with the existing live-IDA-backed ScreenPane, LogoPane, Application, TimerHandler, and SurfacePresentation docs.
- The score should stay below `90+` completion because the raw setter/predicate still lack live xrefs and final original header names are not recovered.
- The score should stay at `90` confidence, not higher, because live IDA MCP was unavailable for a fresh pointer/ref scan in this session.

## Exact Supervisor-Owned Coverage Row Text

Current active `by-memory/-coverage-report.md` does not contain a [UID:00039Y] row even though older B001 report output did. The active coverage block around `0x00557140-0x00559aef` is stale and only lists a subset of current split children. Insert this exact row as a nested child of [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) in address order. In a fully synchronized child block, it belongs after `0x005590da-0x005590e0` padding / [UID:00039X] and before `0x0055916b-0x00559170` padding / [UID:00039Z].

```text
        - [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md) 0x005590e0-0x0055916b | method/helper cluster | ScreenPaneCallbackAndFlagHelpers : reconstructable : 88% : very-strong : B005 2026-06-19 source-quality reanalysis reroutes the direct owner/emitter to [UID:0000CB][ScreenPane](by-class/ScreenPane.md) through [UID:0000NB][ScreenPane](by-file/ScreenPane.md), names `sub_5590E0`/`sub_559110` as `QueueFadeInCallback`/`QueueFadeOutCallback` for `FdIn`/`FdOt` screen fade events, resolves `this+0x5a4` as the ScreenPane fade/presentation transition state, preserves raw `0x00559140`/`0x00559160` as retained `SetFadeTransitionState`/`IsFadeTransitionActive` helpers with no direct xrefs, confirms exact internal padding including `0x00559151-0x00559160`, and recommends first-draft C++ while capping completion for raw-helper liveness plus final header/member spelling.
```

If the supervisor chooses to update the stale [UID:0001G6] master row at the same time, that is a broader SurfacePresentation coverage sync. This report's required exact row is the target row above.

## Target / Support Implementation Checklist

Target [UID:00039Y]:

- Update metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000CB`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000CB`
- Replace file-parent wording with class-owner wording:
  - Direct semantic owner: [UID:0000CB][ScreenPane](by-class/ScreenPane.md).
  - Source route: [UID:0000NB][ScreenPane](by-file/ScreenPane.md), `NexusTK/ui/core/ScreenPane.cpp`.
- Update the range table names:
  - `0x005590e0-0x00559108`: `QueueFadeInCallback` / `FdIn`.
  - `0x00559110-0x00559138`: `QueueFadeOutCallback` / `FdOt`.
  - `0x00559140-0x00559151`: `SetFadeTransitionState`.
  - `0x00559160-0x0055916b`: `IsFadeTransitionActive`.
- Add field analysis:
  - `+0xa4` is the embedded timer-handler facet used for scheduling.
  - `+0x5a4` is `m_fadeTransitionState` / `m_presentationTransitionState`.
  - `+0x5a8` is the callback payload/completion callback field used by `HandleMessage`.
  - `+0x5ac` is the fade step/countdown field consumed by presentation paths.
- Add caller/reachability:
  - `0x005590e0` caller `0x004f4e87` in LogoPane constructor.
  - `0x00559110` callers `0x00464efa` in Application exit and `0x004f52c8` in LogoPane advance.
  - raw `0x00559140` / `0x00559160` no direct xref caveat.
- Add explicit stale-name correction:
  - `sub_5590E0`, `sub_559110`, `FUN_00559140`, `this+0x5a4`, and `FittingRoomDialog::meth_0x5975e0` should be replaced or explained.
- Add first-draft C++ from this report or a compact equivalent.
- Add a Changes entry for B005 2026-06-19 source-quality reanalysis.

Support docs:

- [UID:0000CB][ScreenPane](by-class/ScreenPane.md):
  - Add these four helper methods to Method Notes.
  - Add `+0x5a4` as `m_fadeTransitionState` / `m_presentationTransitionState` in Layout Notes.
  - Cross-link [UID:00039Y].
  - A class score change to `86/89` is defensible if the class page receives report-level detail; otherwise leave score unchanged.
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md):
  - Add this helper cluster to Proposed Contents.
  - Keep source path `NexusTK/ui/core/`.
  - Mention the class-owner reroute; no major score change is required, but a confidence bump to `86/86` is defensible if the file page is refreshed.
- [UID:0001G6][SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md):
  - Update the child inventory row for [UID:00039Y] from `85/87` to `88/90` and direct owner [UID:0000CB].
  - Keep the master page `RECONSTRUCTABLE:FALSE`; this target does not change the mixed-container decision.
- [UID:0003A0][ScreenPanePresentationTransitionHelpers](by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md):
  - Optional support sync: use the same `m_fadeTransitionState` / `m_presentationTransitionState` name so the field is consistent across transition wrappers.
- [UID:0001K8][TimerHandler Schedule/Remove Wrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md):
  - No required edit. Existing `ScheduleTimer` naming is sufficient support.
- `auto-generated/NexusTK/ui/core/ScreenPane.cpp`:
  - After validation/autogen refresh, [UID:00039Y] should no longer be an empty emitter marker.
- `by-memory/-coverage-report.md`:
  - Do not edit directly as B005. Supervisor should insert the exact row above.

Suggested validation commands for the implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [00039Y-ScreenPaneCallbackAndFlagHelpers-source-quality-removed.md](00039Y-ScreenPaneCallbackAndFlagHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If first-draft C++ is inserted, run the normal autogen refresh path used by the supervisor for emitter updates.

## Validator Results

No validator was run because this was a report-only assignment and no by-* or generated docs were edited.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\00039Y-ScreenPaneCallbackAndFlagHelpers-source-quality.md`
- Modified directly: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 00039Y","source_path":"executed-b-agent-research/B005/00039Y-ScreenPaneCallbackAndFlagHelpers-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
