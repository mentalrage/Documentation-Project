** TARGET-REPORT-UID:00003A **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B015 Source-Quality Report: [UID:00003A] Crasher

## Assignment Scope

- Agent: B015
- Target: [UID:00003A] `Crasher`
- Target doc: `source-3/project-documentation/by-class/Crasher.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/00003A-Crasher-class-source-quality.md`
- Mode: B-agent source-quality / heuristic research report only.

No `by-*` documentation, generated source, coverage report, or IDA database was edited. This report creates only the required Agent-B015 research file.

## Short Recommendation

Raise [UID:00003A] from `COMPLETION:85`, `CONFIDENCE:86` to:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000II
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000II
```

Keep source route [UID:0000II] `NexusTK/platform/Crasher.cpp`. Do not fold the class into `ExceptionHandler.cpp`, `Application.cpp`, `Pane.cpp`, `EventDispatcher.cpp`, timer-manager code, command/menu/debug UI files, or `CheatDetector`.

First-draft source shape is now ready for normal class/source code: class declaration, constructor, ordinary destructor, and the crash-trigger callback body. The remaining uncertainty should cap score but should not keep the class as passive no-code:

- exact inherited base virtual spelling for the Pane `+0xa4` tertiary timer/event callback;
- exact higher-level event/timer/hidden command that dispatches to the callback;
- project-wide handling for singleton globals initialized as `0xffffffff`.

Do not hand-author vtable stores, RTTI/COL data, secondary/tertiary destructor adjustor thunks, scalar deleting destructor wrappers, or raw subobject-layout overlays. Those are compiler-generated from the class declaration and virtual destructor.

## Evidence Checked

- Required guidance: `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `Agent-B015/goal.md`, `by-structure.md`, and `inference_research.md`.
- Target/support docs: [UID:00003A] `by-class/Crasher.md`, [UID:0000II] `by-file/Crasher.md`, [UID:000129] `by-memory/0x0049bae0-0x0049bbef.Crasher.md`, [UID:0002UU] `by-memory/0x00618858-0x006188e0.CrasherVtableData.md`, [UID:0000QM] / [UID:000298] `g_pCrasher`, [UID:0000QN] / [UID:000297] `g_pCrashTarget`, [UID:00004P]/[UID:0000J8]/[UID:00014D]/[UID:00014F] `ExceptionHandler`, [UID:0000A2] `Pane`, [UID:0003JA] `PaneVtables`, [UID:0001EA] `PaneCore`, [UID:00004N] `EventHandler`, [UID:0000F0] `TimerHandler`, [UID:0000HG] `Application`, and [UID:0001QB] `client_crash_diagnostics`.
- Prior reports treated as leads and revalidated against current docs: B001 `000129-crasher-source-quality.md`, B005 `00014D-ExceptionHandler-source-quality.md`, B005 `000259-ExceptionHandlerDiagnosticsReadOnlyData-source-quality.md`, and B015 `00014F-TopLevelExceptionFilter-source-quality.md`.
- Generated-output check: `source-3/simroot_v2/class_Crasher.cpp` and `source-3/project-documentation/auto-generated/NexusTK/platform/Crasher.cpp`.
- Coverage/status checks: `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-memory/-coverage-report.md`, and `project-level/-auto-completion-stats.md`.
- Fresh local PE route scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`.

## Current Target State

[UID:00003A] is already reconstructable and attached to [UID:0000II] `Crasher.cpp`, with blank formal C++. The current page correctly records the class as a small [UID:0000A2] `Pane`-derived diagnostic singleton constructed by `Application::Initialize`, owning [UID:0000QM] `g_pCrasher`, and consuming [UID:0000QN] `g_pCrashTarget`.

The stale part is not owner/range; it is source-quality policy. The class page still treats final C++ as intentionally blank because of callback-path/generated-source cleanup, even though B005 has now resolved the ExceptionHandler offset `+4` field to `m_skipCrashReport` for draft source and the active gate is `85/85` combined route quality. The exact callback name remains a score cap, but the source shape is sufficiently resolved for first-draft class/source C++.

## Fresh Route / Liveness Evidence

Local PE scan findings:

- `0x0049bae0` has one direct rel32 call: `0x004646ec call -> 0x0049bae0`, matching `Application::Initialize` construction.
- `0x0049bb60` has no rel32 call/jump/jcc target. Its only VA pointer hit is `.rdata` `0x006188dc`, the tertiary Crasher vtable slot.
- `0x0049bb90` has one VA pointer hit at `0x0061885c`, the primary scalar-deleting-destructor vtable slot.
- Adjustors `0x0049bb78` and `0x0049bb83` have one VA pointer hit each at `0x006188a8` and `0x006188d8`.
- Rel32 hits to `0x0049bb90` are only the two local adjustor jumps at `0x0049bb7e` and `0x0049bb89`.
- Dword immediate hits to Crasher vtable bases match constructor/ordinary-destructor/scalar-destructor store triads:
  - `0x0061885c` at `0x0049bb0d`, `0x0049bb32`, `0x0049bb98`;
  - `0x006188a8` at `0x0049bb17`, `0x0049bb3c`, `0x0049bba2`;
  - `0x006188d8` at `0x0049bb21`, `0x0049bb46`, `0x0049bbac`.
- `g_pCrasher` VA `0x0067ab38` has four local PE immediate hits at `0x00464c50`, `0x0049bb05`, `0x0049bb4c`, and `0x0049bbb2`, matching Application cleanup plus constructor/destructor/scalar-destructor lifecycle.
- `g_pCrashTarget` VA `0x0067ab34` has nine immediate hits, including the Crasher write at `0x0049bb61`, ExceptionHandler constructor/filter/destructor refs, Application cleanup, fatal cleanup, and stored-report path refs.
- No RVA/raw-offset dword encodings were found for `0x0049bb60`, `0x0049bae0`, `0x006188dc`, or `0x006188d8`.

This confirms the current class route: constructor is directly constructed by Application, `TriggerCrash` is vtable-only through the Crasher tertiary callback slot, and no direct command/menu/hotkey/UI route is statically proven.

## Source Placement

Best source route remains `platform/Crasher.cpp`, separate from but companion to `platform/ExceptionHandler.cpp`.

Evidence for `platform/Crasher.cpp`:

- Crasher has its own RTTI/COL/vtable cluster, constructor, ordinary destructor, trigger callback, scalar deleting destructor wrapper, and singleton global `g_pCrasher`.
- Application constructs and cleans up the singleton but does not own its behavior.
- ExceptionHandler owns `g_pCrashTarget`, `m_skipCrashReport`, the top-level filter, and crash-report writing. Crasher only writes the flag before forcing an intentional crash.
- The proposed source tree already lists `platform/ExceptionHandler.cpp` and `platform/Crasher.cpp` as separate crash/platform diagnostics files.
- Current `by-file/Application.md` explicitly says Application constructs both diagnostics singletons but keeps their behavior out of `Application.cpp`.

Rejected alternatives:

- `ExceptionHandler.cpp` as direct owner: rejected because it does not own Crasher Pane/vtable/singleton lifecycle. It is a companion dependency and owns the flag/global consumed by Crasher.
- `Application.cpp`: rejected because Application is lifecycle orchestration only.
- `Pane.cpp`, `EventDispatcher.cpp`, or `TimerMgr.cpp`: rejected because they provide base dispatch mechanics, not the Crasher-specific override body or singleton.
- command/menu/UI/debug files: rejected because no direct caller, string, hotkey, menu item, visible UI label, or registration path reaches `0x0049bb60`.
- `CheatDetector`/anti-tamper: rejected because Crasher interacts with crash reporting, not the timer-based CheatDetector singleton. The marker write is diagnostic/developer crash behavior, not evidence of anti-cheat ownership.

## Callback / Event Path Naming

Best current route: `Crasher::TriggerCrash` is a source-authored override body reached through the [UID:0000A2] `Pane` tertiary `+0xa4` timer/event callback view.

Evidence:

- `0x006188dc -> 0x0049bb60` is the second entry of the tertiary Crasher vtable view at object offset `+0xa4`.
- `PaneVtables.md` documents the base tertiary view at `+0xa4`; `PaneCore.md` describes `0x00544e90-0x00544e95` as the inherited tertiary default event/update slot.
- `0x0049bb60` and base default `0x00544e90` both use a three-explicit-argument callback shape ending in `retn 0Ch`.
- Concrete timer-handler pages use the same three-argument shape for `OnTimer` / `OnTimerEvent` style callbacks.

Source-name recommendation:

- Use `Crasher::TriggerCrash` as the target-specific documentation name for the body because the method intentionally sets the skip-report flag and writes the crash marker.
- In class/header C++ drafts, document that this is the `+0xa4` Pane/TimerHandler callback override. If the reconstruction framework requires a base-virtual spelling before codegen, use a provisional `OnTimerEvent(int eventId, int arg0, int arg1)` or the final UI-core tertiary callback name once [UID:0000A2]/[UID:0000F0] finalizes it.
- Do not claim a direct user-visible trigger source yet. The exact event/timer/hidden command route is not proven.

This is not a passive blocker: the high-probability behavior is resolved, and the only remaining issue is final inherited slot spelling.

## Behavior And Field Names

Constructor `0x0049bae0-0x0049bb2a`:

- Calls `Pane::Pane(this, 0)`.
- Publishes `g_pCrasher = this`.
- Compiler installs three Crasher vtable views at object offsets `+0x00`, `+0xa0`, and `+0xa4`.

Ordinary destructor `0x0049bb30-0x0049bb59`:

- Reinstalls Crasher vtables in binary as destructor codegen.
- Clears `g_pCrasher`.
- Chains to `Pane::~Pane`.
- This destructor is source-authored and should be represented in first-draft source. Current generated output omits it.

Trigger callback `0x0049bb60-0x0049bb78`:

- Writes `g_pCrashTarget->m_skipCrashReport = true` using raw offset `+4`.
- Writes marker `0x6675636b` through address zero.
- Returns `true`.
- Has three unused callback parameters in the binary calling convention. Parameter names should stay descriptive/provisional until the base callback declaration is finalized.

Scalar deleting destructor and adjustors:

- `0x0049bb78` and `0x0049bb83` are compiler adjustor thunks for secondary/tertiary destructor slots.
- `0x0049bb90-0x0049bbef` is MSVC scalar deleting destructor glue over the ordinary destructor plus optional delete.
- Do not enter these as handwritten source methods.

Globals:

- `g_pCrasher` is a `Crasher *` owned by `platform/Crasher.cpp`; initialized image bytes are `ff ff ff ff`, so final source initializer remains a project-wide singleton-convention question. Do not emit the generated adjusted-null artifact.
- `g_pCrashTarget` is an `ExceptionHandler *` owned by `platform/ExceptionHandler.cpp`; Crasher is a cross-module consumer.
- `m_skipCrashReport` is now the preferred source-facing name for ExceptionHandler offset `+0x04`, supported by Crasher write and TopLevelExceptionFilter read.

## Generated-Source Cleanup

`source-3/simroot_v2/class_Crasher.cpp` is not source-quality:

- emits synthetic `CrasherVtableLayout` overlays and raw vtable stores;
- emits a scalar deleting destructor as if handwritten;
- omits the ordinary destructor;
- uses adjusted-null/pointer-arithmetic artifacts for `g_pCrasher`;
- writes `g_pCrashTarget + 4` through raw pointer arithmetic instead of the resolved `m_skipCrashReport` field;
- uses modern fixed-width/`nullptr`/`constexpr` style inconsistent with surrounding source guidance.

`source-3/project-documentation/auto-generated/NexusTK/platform/Crasher.cpp` currently contains only empty markers because the by-* C++ blocks are blank. That proves the route but not behavior.

Implementation should replace generated artifact policy with ordinary source: constructor, virtual destructor, and one callback override; let compiler regenerate vtables/RTTI/adjustors/deleting destructor.

## First-Draft C++ Recommendation

Class page [UID:00003A] should receive a declaration-oriented first draft, with the callback-name caveat called out:

```cpp
class Crasher : public Pane {
public:
    Crasher();
    virtual ~Crasher();

    // Overrides the Pane +0xa4 tertiary timer/event callback.
    // Rename to the finalized base callback spelling when Pane/TimerHandler is finalized.
    virtual bool TriggerCrash(int eventId, int arg0, int arg1);
};

extern Crasher *g_pCrasher;
```

Method-body source shape for [UID:000129] / `platform/Crasher.cpp`:

```cpp
Crasher *g_pCrasher;

Crasher::Crasher()
    : Pane(0)
{
    g_pCrasher = this;
}

Crasher::~Crasher()
{
    g_pCrasher = 0;
}

bool Crasher::TriggerCrash(int eventId, int arg0, int arg1)
{
    g_pCrashTarget->m_skipCrashReport = true;
    *reinterpret_cast<volatile unsigned long *>(0) = 0x6675636bUL;
    return true;
}
```

Notes:

- `eventId`, `arg0`, and `arg1` are currently unused/provisional names. Use final `Pane`/`TimerHandler` callback parameter names when available.
- If the final base callback name is `OnTimerEvent` or similar, rename the method accordingly and keep `TriggerCrash` as the behavior label in docs.
- Do not add a null-check before `g_pCrashTarget`; the binary does not have one and startup order constructs ExceptionHandler before Crasher.
- Do not emit `0xffffffff` as the `g_pCrasher` source initializer until the singleton sentinel convention is settled. Declaration without explicit initializer is the safer draft.

## Metadata Recommendations

Target [UID:00003A] `by-class/Crasher.md`:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000II | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000II | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion increases because source placement, class/source role, method inventory, `m_skipCrashReport`, compiler-generated ABI policy, and first-draft source shape are now resolved.
- Confidence increases because current docs, accepted B reports, and fresh PE route scan agree on constructor route, vtable-only trigger route, vtable-store triads, singleton refs, and ExceptionHandler consumer/owner split.
- Score should stay below final-audit levels because the exact inherited base callback name, exact higher-level trigger route, and singleton initializer convention remain unresolved.

Support score notes:

- [UID:0000II] `by-file/Crasher.md`: after adding the generated-source cleanup and first-draft source-shape policy, `87/88` is defensible. It can also remain `86/86` if the supervisor wants class-only scoring.
- [UID:000129] memory page: keep `86/90` unless first-draft method C++ is entered. If entered, `87/91` is defensible because body source shape is now resolved, while callback spelling/path still cap final confidence.
- [UID:0002UU] vtable data: no score change needed; keep source-declared/generated-binary policy.
- [UID:0000QM] `g_pCrasher`: no score change needed; preserve singleton-sentinel caveat.
- [UID:0000QN] / ExceptionHandler pages: no required score change for this task; B005 already owns the field-name upgrade.

## Recommended Target / Support Doc Changes

### `by-class/Crasher.md`

1. Update metadata to `87/89`.
2. Replace "C++ intentionally blank until final source grouping and names are audit-ready" with:

```text
First-draft class/source C++ is ready for the normal class declaration, constructor, ordinary destructor, and crash-trigger callback body. The exact inherited `+0xa4` Pane/TimerHandler callback spelling and higher-level trigger route remain score caps, but they no longer block draft source shape. Vtables, RTTI/COL data, secondary/tertiary destructor adjustor thunks, raw vtable stores, and scalar deleting destructor wrappers are compiler-generated and must not be hand-authored.
```

3. Add the class declaration draft above to the formal C++ block if supervisor accepts class-level declarations.
4. Update Important Methods:
   - constructor: source-authored `Crasher::Crasher() : Pane(0) { g_pCrasher = this; }`;
   - ordinary destructor: source-authored and omitted from stale generated output;
   - `TriggerCrash`: source-authored `+0xa4` tertiary Pane timer/event callback override; raw body sets `m_skipCrashReport`, writes marker `0x6675636b`, returns true;
   - scalar deleting destructor/adjustors: compiler-generated.
5. Add fresh route evidence from this report: local PE scan found one rel32 call to constructor at `0x004646ec`, one pointer to `0x0049bb60` at `0x006188dc`, vtable-store triads, four `g_pCrasher` refs, nine `g_pCrashTarget` refs, and no RVA/raw-offset encodings for `0x0049bb60`.
6. Preserve rejected alternatives: not ExceptionHandler-owned, not Application-owned, not Pane/EventDispatcher/TimerMgr-owned, not command/menu/UI/debug/CheatDetector-owned.

### `by-memory/0x0049bae0-0x0049bbef.Crasher.md`

1. Keep owner/emitter [UID:00003A].
2. Replace the remaining "final C++ intentionally blank" rationale with a more precise policy:

```text
First-draft source bodies are now ready for the constructor, ordinary destructor, and crash-trigger callback. The formal block may either stay blank until exact method-child splitting or carry source-style method bodies; it must not include vtable overlays, RTTI, adjustor thunks, scalar deleting destructor source, raw vtable stores, or decompiler pointer arithmetic. The only remaining score caps are inherited callback spelling, exact external trigger path, and singleton initializer convention.
```

3. If formal C++ is entered, use the method-body draft above and keep callback parameters provisional.

### `by-file/Crasher.md`

Add a source-quality note:

```text
B015 class pass: `platform/Crasher.cpp` remains the best route. The normal source file should contain `Crasher`, `g_pCrasher`, the constructor, ordinary destructor, and the `+0xa4` Pane/TimerHandler crash-trigger callback. Generated source must be cleaned up: the ordinary destructor is source-authored and should be present, while vtable-layout overlays, adjustor thunks, scalar deleting destructor code, and raw vtable stores are compiler output.
```

### `by-global/g_pCrasher.md` and `by-memory/0x0067ab38-0x0067ab3c.g_pCrasher.md`

Add:

```text
B015 class pass recommends first-draft declaration `Crasher *g_pCrasher;` in `platform/Crasher.cpp`; do not emit the initialized `0xffffffff` image value as normal source until the project-wide singleton sentinel convention is settled.
```

### `by-global/g_pCrashTarget.md` and `by-memory/0x0067ab34-0x0067ab38.g_pCrashTarget.md`

No owner change. Add or retain:

```text
Crasher is a consumer only: `Crasher::TriggerCrash` writes `ExceptionHandler::m_skipCrashReport` at offset `+0x04` before the intentional null write; `ExceptionHandler.cpp` owns the global and field.
```

### `by-memory/0x00618858-0x006188e0.CrasherVtableData.md`

No C++ block. Add:

```text
B015 confirms the source policy: `0x006188dc -> 0x0049bb60` should be generated from the Crasher override of the inherited Pane `+0xa4` tertiary timer/event callback. Use `TriggerCrash` as the behavior/documentation name until the final base callback spelling is coordinated.
```

### `by-meta/client_crash_diagnostics.md`

Update open questions:

- Closed for draft source: `ExceptionHandler +0x04` is `m_skipCrashReport`.
- Closed: `Crasher` stays a separate `platform/Crasher.cpp` companion unless future source-order evidence proves colocation.
- Still open and score-capping only: exact higher-level callback dispatch path and final inherited Pane/TimerHandler callback spelling.

### Generated-source issue tracking

If a generated-source issue page is used, add:

```text
`class_Crasher.cpp` generated view is stale: it emits synthetic vtable-layout overlays and scalar deleting destructor code, omits source-authored `Crasher::~Crasher`, and writes `g_pCrashTarget + 4` instead of using the resolved `m_skipCrashReport` field. Final source should contain ordinary constructor/destructor/callback bodies and let the compiler generate ABI glue.
```

## Exact Coverage Text

Do not edit coverage during this report pass.

Recommended replacement for `by-class/-coverage-report.md` [UID:00003A]:

```text
- [UID:00003A][Crasher](by-class/Crasher.md) : reconstructable : 87% : very strong : B015 class source-quality pass keeps owner/emitter route [UID:0000II] `platform/Crasher.cpp`, confirms Application construction at `0x004646ec`, vtable-only `TriggerCrash` reachability through tertiary Pane/TimerHandler slot `0x006188dc -> 0x0049bb60`, `g_pCrasher` lifecycle, `g_pCrashTarget` consumer-only write to `ExceptionHandler::m_skipCrashReport`, and first-draft source shape for the class declaration, constructor, ordinary destructor, and crash-trigger callback; vtables, RTTI/COL data, adjustor thunks, scalar deleting destructor, and raw vtable stores are compiler-generated, while exact inherited callback spelling, higher-level trigger route, and singleton sentinel convention remain final-audit caps.
```

If the supervisor also syncs the source-bearing memory row, replace `by-memory/-coverage-report.md` [UID:000129] with:

```text
    - [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md) : reconstructable : 86% : very strong : Crasher diagnostic Pane singleton method cluster owned/emitted through [UID:00003A] `Crasher` and [UID:0000II] `platform/Crasher.cpp`; B015 class pass reconfirms constructor/direct Application call, ordinary destructor, `TriggerCrash`, adjustor, and scalar-destructor bounds, fresh PE route evidence for vtable-only `0x006188dc -> 0x0049bb60` reachability, vtable-store triads, `g_pCrasher` lifecycle refs, `g_pCrashTarget` consumer write to `m_skipCrashReport`, and first-draft source shape for constructor/destructor/trigger bodies. Formal C++ must exclude vtable overlays, RTTI, adjustor thunks, scalar deleting destructor code, raw vtable stores, and decompiler pointer arithmetic; exact inherited callback name, higher-level trigger route, and singleton initializer convention remain confidence caps.
```

If the supervisor syncs the source-file row, replacement for `by-file/-coverage-report.md` [UID:0000II]:

```text
- [UID:0000II][Crasher](by-file/Crasher.md) : reconstructable : 87% : very strong : Diagnostic crash Pane companion in `platform/Crasher.cpp`; B015 class pass keeps it separate from `ExceptionHandler.cpp` while documenting the dependency on `g_pCrashTarget::m_skipCrashReport`, confirms constructor/destructor/trigger source shape, Application construction/cleanup route, vtable-only tertiary callback reachability, `g_pCrasher` ownership, generated-source cleanup needs, and rejected Application/Pane/EventDispatcher/TimerMgr/command/menu/UI/CheatDetector owners.
```

No new coverage row should be added.

## IDA Rename / Type / Comment Recommendations

High confidence:

- Rename `sub_49BAE0` / function `0x0049bae0` to `Crasher::Crasher`.
- Rename `sub_49BB30` / function `0x0049bb30` to `Crasher::~Crasher`.
- Rename `sub_49BB60` / function `0x0049bb60` to `Crasher::TriggerCrash` or `Crasher::TriggerCrash_TertiaryCallback` until base callback spelling is final.
- Type `0x0049bb60` as `bool __thiscall Crasher::TriggerCrash(int eventId, int arg0, int arg1)`; note `this`/parameters are unused in the body.
- Rename/type `dword_67AB38` as `Crasher *g_pCrasher`.
- Rename/type `dword_67AB34` as `ExceptionHandler *g_pCrashTarget`.
- Add comment at `0x0049bb60`: "Pane +0xa4 tertiary timer/event callback override; sets ExceptionHandler::m_skipCrashReport, then intentionally null-writes marker 0x6675636b."

Medium-high confidence:

- Name `0x0049bb78` as `CrasherDeletingDestructorAdjustor_A0` or equivalent compiler-generated thunk comment, not source method.
- Name `0x0049bb83` as `CrasherDeletingDestructorAdjustor_A4` or equivalent compiler-generated thunk comment, not source method.
- Name `0x0049bb90` as `CrasherScalarDeletingDestructor`, with comment "compiler-generated wrapper over `Crasher::~Crasher` plus optional delete."
- Comment `0x006188dc`: "Crasher tertiary `+0xa4` callback slot; target `Crasher::TriggerCrash`."

Medium confidence / coordinate with UI-core:

- Base `0x00544e90` should be described as the default Pane tertiary timer/event callback. Do not globally rename it to `OnTimerEvent` until [UID:0000A2] `Pane` and [UID:0000F0] `TimerHandler` settle final virtual names.

## Validator Needs

No validators were run because this report only creates an Agent-B015 research file.

After a later implementation callback edits docs, run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00003A-Crasher-class-source-quality-removed.md](00003A-Crasher-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run validators for files actually edited. If coverage rows are supervisor-applied, run the normal coverage/stats refresh path used by the supervisor in addition to file/autogen validation.

Expected validation outcome after implementation:

- [UID:00003A] average becomes `88.0` in auto-completion stats.
- `auto-generated/NexusTK/platform/Crasher.cpp` should no longer be an empty marker if formal C++ is entered.
- Generated output should not contain `CrasherVtableLayout`, `ScalarDeletingDestructor` as handwritten source, raw vtable stores, or `g_pCrashTarget + 4` pointer arithmetic if the suggested source blocks are used.

## Open Questions Closed Or Carried

Closed:

- Source placement: `platform/Crasher.cpp`, separate companion to `ExceptionHandler.cpp`.
- Field name for draft source: `ExceptionHandler::m_skipCrashReport`.
- Crasher role: diagnostic Pane singleton and consumer of ExceptionHandler state, not ExceptionHandler owner.
- Generated ABI policy: vtables, RTTI/COL, adjustors, scalar deleting destructor, and raw vtable stores are compiler-generated.
- Constructor/destructor/trigger source shape: first-draft ready.

Carried forward as score caps:

- Exact inherited base callback name for the `+0xa4` tertiary Pane/TimerHandler slot.
- Exact higher-level event/timer/hidden command source that dispatches to the callback.
- Project-wide source convention for singleton globals with initialized `0xffffffff` image value.

## Implementation Checklist For Accepted Callback

1. Update [UID:00003A] metadata to `87/89`, keep owner/emitter [UID:0000II].
2. Add class declaration first-draft C++ to [UID:00003A], or explicitly state that class declaration C++ is ready but held for a later declaration pass.
3. Update [UID:00003A] status/autogen text to remove passive no-code wording and record compiler-generated ABI policy.
4. Update [UID:000129] source policy; optionally add first-draft constructor/destructor/trigger C++ bodies.
5. Update [UID:0000II] with generated-source cleanup and first-draft source-file role.
6. Add concise notes to `g_pCrasher`, `g_pCrashTarget`, Crasher vtable data, and `client_crash_diagnostics` as listed above.
7. Do not edit `by-memory/-coverage-report.md` unless supervisor applies the exact replacement row.
8. Run scoped validators for every edited file and autogen if any formal C++ or route metadata changes.

FINISHED report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/00003A-Crasher-class-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00003A-Crasher-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00003A"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00003A-Crasher-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00003A-Crasher-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00003A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
