** TARGET-REPORT-UID:000143 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000143 Application Idle Tick Baseline Source-Quality Research

Assignment: `B001-goal2-application-idle-tick-baseline-source-quality-000143-20260617`  
Agent: `Agent-B001`  
Target: [UID:000143] `by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md`  
Date: 2026-06-17

## Final Recommendation

Raise [UID:000143] from `COMPLETION:82 / CONFIDENCE:88` to `COMPLETION:86 / CONFIDENCE:90`.

Keep:

- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0000J7`
- `EMITTER_UIDS:0000J7`
- Formal target `RECONSTRUCTION_CPP` blank for now

Do not move the target to `Application.cpp`. The best source-facing model is a private `EventDispatcher` idle/message-loop helper, most defensibly named `EventDispatcher::CaptureIdleTickBaseline()` or equivalent, emitted with [UID:0000J7] `EventDispatcher`. The current `ApplicationIdleTickBaseline` page title remains acceptable as a documentation name, but it should not be treated as the final source symbol name.

The formal `RECONSTRUCTION_CPP` block should not be populated yet. This target meets the active reconstructable/emitting score gate after the recommended rescore, but the final source declaration is still coupled to the accepted companion shape for [UID:000142] `ApplicationIdleWorkScheduler`: private `EventDispatcher` methods versus a small scheduler wrapper, field naming in the `EventDispatcher` layout, and whether generated output should preserve the observed ABI return or model the original source as `void`. A first-draft C++ review artifact is included below and should stay review-only unless the supervisor explicitly decides to promote it.

## Scope Recheck

Live IDA MCP recheck confirms [UID:000143] is exactly the half-open range `0x004a7120-0x004a712c`, size `0x0c` / 12 bytes:

```asm
004a7120  mov eax, dword ptr unk_67AB80
004a7125  mov eax, [eax+18h]
004a7128  mov [ecx+2Ch], eax
004a712b  retn
```

Decompiler shape:

```c
int __thiscall sub_4A7120(_DWORD *this)
{
  int result;
  result = *(_DWORD *)(unk_67AB80 + 24);
  this[11] = result;
  return result;
}
```

Function facts:

- Function name in IDA: `sub_4A7120`
- Function size: 12 bytes
- Caller count: exactly one, `sub_464CD0` / [UID:0002H2] `Application::RunMessageLoop`, call site `0x00464ce1`
- Callees: none
- Dependencies: `g_pTimerMgr` / `unk_67AB80` at `0x0067ab80`, `TimerMgr+0x18`, and `EventDispatcher+0x2c`
- Padding: seven `0xcc` bytes before the function after `sub_4A7110`, and four `0xcc` bytes at `0x004a712c-0x004a7130`

Raw bytes around the target:

```text
0x004a7110: c6 41 28 00 b0 01 c2 0c 00 cc cc cc cc cc cc cc
0x004a7120: a1 80 ab 67 00 8b 40 18 89 41 2c c3
0x004a712c: cc cc cc cc
```

The caller setup in [UID:0002H2] is important: `Application::RunMessageLoop` loads `ecx` from `g_pEventDispatcher` / `unk_67AB30` before calling `sub_4A7120`. `Application` owns the call site, but not the object being mutated.

## Related Documentation Checked

- [UID:000142] `by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md`: companion idle scheduler worker. It drains cleanup work, gates timer refresh with [UID:00027B], dispatches timers, rebuilds traversal state through `EventDispatcher+0x4`, refreshes the idle baseline at `EventDispatcher+0x2c`, resets/compares `EventDispatcher+0x30`, divides elapsed ticks by `0x14` / 20, and dispatches frame callbacks through [UID:0000Q0].
- [UID:00000E] `by-class/ApplicationHelper_4A6C40.md`: wrapper documentation correctly warns the helper name is generated/provisional. The live recheck strengthens that this is not a standalone class layout; it is `EventDispatcher` state used by the message loop.
- [UID:0000J7] `by-file/EventDispatcher.md`: correct owner/emitter for the target. The helper sits in the `0x004a6a80-0x004a82a9` EventDispatcher neighborhood and uses `g_pEventDispatcher` as its `this` object.
- [UID:0000HG] `by-file/Application.md`: correct as a caller owner only. It already cautions against moving `0x004a6c40` / `0x004a7120` into `Application.cpp`.
- [UID:0000OT] `by-file/TimerMgr.md`, [UID:0000SI] `by-global/g_pTimerMgr.md`, and [UID:0001WD] `TimerMgrLayout`: support that `TimerMgr+0x18` is the current tick value updated from timer code.
- [UID:00027B] `by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md`: one-byte idle scheduler refresh flag used only by [UID:000142].
- [UID:0000Q0] `by-global/g_frameRegistry.md`: target of frame-slice dispatch from [UID:000142].
- [UID:000141] `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md` and [UID:00004M] `by-class/EventDispatcher.md`: constructor and method neighborhood evidence for `EventDispatcher` ownership.

Relevant coverage rows are stale relative to the improved evidence. The [UID:000143] row still reports `82%` and a final naming caveat that this report resolves enough for an `86/90` source-quality score, while still keeping formal final C++ blank.

## EventDispatcher Layout Evidence

The `EventDispatcher` constructor at `0x004a6a80` initializes the fields used by [UID:000143] and [UID:000142]:

- `EventDispatcher+0x2c` is initialized to `0xffffffff`.
- `EventDispatcher+0x30` is initialized to `0`.
- `EventDispatcher+0x34`, `+0x38`, and `+0x3c` are initialized nearby, with `+0x3c = 0x0bb8` / 3000, but those fields are used by adjacent route/timer behavior rather than the idle baseline helper.
- `EventDispatcher+0x28` is touched by `sub_4A7110` and route/event code, but it is not the baseline field.

The worker at `0x004a6c40` later uses the same state:

- On refresh, it writes the current `TimerMgr+0x18` tick to `EventDispatcher+0x2c`.
- It resets `EventDispatcher+0x30` to `0`.
- On normal idle iterations, it reads `EventDispatcher+0x2c` and `EventDispatcher+0x30`.
- It computes `(TimerMgr.currentTick - baseline) / 0x14`.
- It dispatches through `g_frameRegistry` when the computed slice differs from `EventDispatcher+0x30`, then stores the new slice into `EventDispatcher+0x30`.

Best field-name inferences:

- `EventDispatcher+0x2c`: `m_idleTickBaseline`
- `EventDispatcher+0x30`: `m_lastDispatchedIdleSlice`
- [UID:00027B] byte: `g_timerResolutionNeedsRefresh` or `g_idleTimerResolutionDirty`

These names fit both [UID:000143] and [UID:000142]. `m_idleTickBaseline` is more defensible than `m_currentTick` because the field is not continuously updated; it is a saved baseline against which later elapsed ticks are divided into 20 ms frame slices.

## Heuristic / Inference Reanalysis And Validation

Generated name `sub_4A7120`: rejected as source-facing. It is only the IDA fallback name.

Source-facing helper name: `EventDispatcher::CaptureIdleTickBaseline()` is the best current recommendation. It describes the only behavior in the function, matches the companion worker's reuse of the saved tick, and avoids implying that the helper owns all idle scheduling.

Alternative `ApplicationIdleTickBaseline`: acceptable as a documentation page title but too artifact-shaped for source. It names the message-loop context rather than the object and field being mutated.

Alternative `ApplicationHelper_4A6C40::CaptureCurrentTickBaseline`: rejected as final. [UID:00000E] is a grouping wrapper for related helper documentation, not proven source structure. Live caller evidence passes `g_pEventDispatcher` as `ecx`, and constructor evidence places `+0x2c/+0x30` in `EventDispatcher`.

Alternative `Application::CaptureIdleTickBaseline`: rejected. The only caller is in `Application::RunMessageLoop`, but the call uses `ecx = g_pEventDispatcher`, not the `Application` instance. `Application` consumes the helper; it does not own the helper's state.

Alternative `TimerMgr::CaptureIdleTickBaseline`: rejected. `TimerMgr` supplies `currentTick` at `+0x18`, but [UID:000143] writes into `EventDispatcher+0x2c` and has no TimerMgr method call.

Signature inference: the binary leaves the copied tick in `eax`, and IDA therefore decompiles an `int` return. The only caller ignores the return value, and MSVC can emit the same body for a `void` source function that assigns through a loaded `eax`. The best source-facing signature is therefore:

```cpp
void EventDispatcher::CaptureIdleTickBaseline();
```

If the reconstruction policy prefers preserving decompiler-visible ABI facts in review artifacts, an alternate draft may return `DWORD`, but this should not be treated as proven source. The report recommendation is to document the ABI return fact while using `void` as the source-facing helper shape.

Scheduler object/layout inference: there is no proven separate `ApplicationHelper_4A6C40` or `MessageLoopScheduler` object. The scheduler state is embedded in `EventDispatcher`. A conceptual `EventDispatcherIdleState` sublayout could be useful in documentation, but introducing a standalone source class would be an organizational reconstruction decision, not a fact from the binary.

Source placement inference: keep the helper in `EventDispatcher.cpp` under [UID:0000J7]. A small `MessageLoopScheduler.cpp` companion remains a weaker alternative only if the source tree later chooses to wrap `EventDispatcher` private state for readability. It is not the best recommendation for this target because both the baseline helper and companion worker directly operate on `EventDispatcher` fields and sit in the EventDispatcher code range.

Final-C++ inference: the target is reconstructable and should score above 85, but formal `RECONSTRUCTION_CPP` should remain blank. The unresolved part is no longer "unknown behavior"; it is final source shape coordination with [UID:000142] and `EventDispatcher` layout naming. A review artifact is safe; a formal emitted block is premature.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP` block for [UID:000143] yet. Keep final C++ blank in the target document.

Review artifact only:

```cpp
// Review artifact only; do not enter as final RECONSTRUCTION_CPP yet.
void EventDispatcher::CaptureIdleTickBaseline()
{
    m_idleTickBaseline = g_pTimerMgr->m_currentTick;
}
```

If the supervisor decides final reconstruction must preserve the observed `eax` value instead of the likely source-level `void` signature, this alternate review shape is ABI-compatible with the decompiler, but I do not recommend applying it as formal final C++ at this stage:

```cpp
// Alternate review artifact only.
DWORD EventDispatcher::CaptureIdleTickBaseline()
{
    m_idleTickBaseline = g_pTimerMgr->m_currentTick;
    return m_idleTickBaseline;
}
```

The `void` form is the better source-facing draft because the sole `Application::RunMessageLoop` caller ignores the result and the helper's purpose is to seed `EventDispatcher` idle state for [UID:000142].

## Metadata Recommendation

Recommended [UID:000143] metadata:

```yaml
COMPLETION: 86
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000J7
EMITTER_UIDS: [0000J7]
RECONSTRUCTION_CPP: ""
```

Rationale for `86/90`: exact bytes, range, caller, callee absence, padding, singleton dependencies, object owner, and field roles are now rechecked and cross-supported. The remaining uncertainty is final source declaration and companion helper organization, not behavior.

## Supervisor-Owned Coverage Row Replacement Text

Recommended replacement row for [UID:000143] in `by-memory/-coverage-report.md`:

```markdown
    - [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md) 0x004a7120-0x004a712c | scheduler helper | ApplicationIdleTickBaseline : reconstructable : 86% : very strong : EventDispatcher-owned idle tick-baseline capture helper; B001 2026-06-17 live IDA reconfirmed exact 12-byte body, one `Application::RunMessageLoop` caller with `ecx = g_pEventDispatcher`, no callees, `g_pTimerMgr+0x18` current-tick read, `EventDispatcher+0x2c` idle baseline write, pre/post `0xcc` padding, constructor/worker uses of `+0x2c/+0x30`, and source-facing `EventDispatcher::CaptureIdleTickBaseline` recommendation while formal final C++ remains blank.
```

Related stale coverage rows that should also be considered if the supervisor updates adjacent support docs:

```markdown
    - [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md) 0x004a6c40-0x004a6cda | scheduler helper | ApplicationIdleWorkScheduler : reconstructable : 86% : strong : EventDispatcher-owned idle/message-loop scheduler helper; B001 2026-06-17 live IDA reconfirmed exact 155-byte body, two `Application::RunMessageLoop` callers with `ecx = g_pEventDispatcher`, cleanup queue drain, timer-resolution flag gating, TimerMgr period/dispatch/current-tick calls, traversal rebuild on `EventDispatcher+0x4`, `+0x2c` idle tick-baseline and `+0x30` last dispatched slice handling, 0x14/20 tick frame-slice dispatch via g_frameRegistry, and formal final C++ blocked by companion scheduler naming.
```

```markdown
    - [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md) 0x0066d880-0x0066d888 | global flag plus padding | ApplicationIdleSchedulerStaticFlag : reconstructable : 85% : strong : One-byte EventDispatcher idle scheduler refresh flag plus padding, exact initial value `1`, three data xrefs in `ApplicationIdleWorkScheduler` (`0x004a6c4f`, `0x004a6c77`, `0x004a6c92`), timer-period/current-tick refresh gate, clear after refresh, zero padding through `0x0066d887`, and successor `EventMan` table boundary documented; final variable name remains provisional.
```

## Recommended Target Text Changes

For [UID:000143], the supervisor should update the source-quality blocker language from unresolved helper/layout/source placement to resolved recommendations:

- Best helper name: `EventDispatcher::CaptureIdleTickBaseline`
- Best source signature: `void EventDispatcher::CaptureIdleTickBaseline()`
- ABI note: binary leaves the captured tick in `eax`; this does not prove a source return because the sole caller ignores it
- Best field names: `EventDispatcher+0x2c = m_idleTickBaseline`, `EventDispatcher+0x30 = m_lastDispatchedIdleSlice`
- Placement: [UID:0000J7] `EventDispatcher.cpp`
- Rejected placement: `Application.cpp`
- Weaker alternative: small `MessageLoopScheduler` wrapper only if later source organization requires it, not as the current best model
- Formal final C++: keep blank; include review-only draft C++ if desired

## Validation Commands For Supervisor

After applying accepted documentation and coverage changes, run:

> Executable block R001 was removed from this report and preserved verbatim in [000143-application-idle-tick-baseline-source-quality-removed.md](000143-application-idle-tick-baseline-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor only accepts the primary [UID:000143] update, the minimum validation set is:

> Executable block R002 was removed from this report and preserved verbatim in [000143-application-idle-tick-baseline-source-quality-removed.md](000143-application-idle-tick-baseline-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Files Changed By Agent-B001

Created this report only:

- `tools/leaser/Agents/Agent-B001/research/000143-application-idle-tick-baseline-source-quality.md`

No by-memory documents, generated reports/source, source files, IDA database content, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000143-application-idle-tick-baseline-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"000143"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000143-application-idle-tick-baseline-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000143-application-idle-tick-baseline-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000143"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
