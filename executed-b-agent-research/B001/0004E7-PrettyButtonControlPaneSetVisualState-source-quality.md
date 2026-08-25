** TARGET-REPORT-UID:0004E7 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0004E7 PrettyButtonControlPaneSetVisualState Source-Quality Report

## Finalized Report / Current Recommendation

UID0004E7 should stay assigned to [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md), should remain reconstructable, and is now ready for a first-draft emitted method body using the project's accepted visual-state/timer naming conventions.

Recommended target disposition:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000AR`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000AR`
- `EMITTER_POSITION_OPTIONAL:` blank
- formal `RECONSTRUCTION_CPP CODE` populated with `PrettyButtonControlPane::SetState(unsigned char state)`

The score should rise from `84/88` because current IDA MCP confirms the exact function boundary, vtable-only reachability, byte-exact body, sibling parity, timer helper behavior, base visual-state setter behavior, paint-frame consumption of the target's local flag, and padding boundaries. The blank-emitter blocker is resolved: [UID:0003N2] already documents `0x00494b80` as the inherited `ControlPane` visual-state setter, [UID:0001K8] already emits `TimerHandler::ScheduleTimer` and `TimerHandler::RemovePendingTimers`, and accepted Direction/Gender button reports use `SetState` / visual-state wording plus `m_visualState` for the same `+0x103` byte-state slot. The remaining original-spelling uncertainty should cap confidence below final audit, not block first-draft C++.

## Supporting Research

- Assignment folder: `tools/leaser/Agents/Agent-B001`.
- Assignment target: [UID:0004E7] `by-memory/0x0054b750-0x0054b7b2.PrettyButtonControlPaneSetVisualState.md`.
- Required report path: `tools/leaser/Agents/Agent-B001/research/0004E7-PrettyButtonControlPaneSetVisualState-source-quality.md`.
- Project workflow used: `ntk-b-agent-workflow` plus `references/b-agent-research-and-implementation-workflow.md`.
- IDA MCP session used: `b011_0004EC_20260702`.
- MCP health at research time: `status: ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, strings cache size `2067`.
- No by-* target/support docs, generated files, coverage reports, validator state, archives, queues, supervisor ledgers, or lifecycle state were edited.
- No validator, `execute_report`, execute-report variant, registry lifecycle command, manual report move, or archive command was run.

## Target

- UID: `0004E7`
- Target doc: `by-memory/0x0054b750-0x0054b7b2.PrettyButtonControlPaneSetVisualState.md`
- Address range: `0x0054b750-0x0054b7b2`
- Current title: `PrettyButtonControlPane SetVisualState`
- Current owner: [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md)
- Source file route: [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md), projected under `NexusTK/ui/controls/`

## Current Target State

The target currently records:

- `COMPLETION:84`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000AR`
- `RECONSTRUCTABLE:TRUE`
- blank `EMITTER_UIDS`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal `RECONSTRUCTION_CPP CODE`

Current target evidence is brief: B011 `lookup_funcs` gives `0x0054b750` size `0x62`; B011 `analyze_function` says the function compares/stores a state byte and calls `sub_5975E0`, `sub_597600`, and `sub_494B80`; UID0002UW records vtable slot `0x00622320 -> 0x0054b750`. The page correctly keeps formal C++ blank pending final state names and timer helper roles.

## Heuristic / Inference Reanalysis And Validation

The previous heuristic label "visual-state/animation scheduling" is validated. Fresh MCP decompilation shows:

- prototype: `int __thiscall(char *this, unsigned __int8)`
- function start: `0x0054b750`
- function size: `0x62` bytes, decimal `98`
- end after `retn 4` at `0x0054b7af`; `0x0054b7b2` is not a function and begins padding
- no strings
- callees: `sub_5975E0`, `sub_597600`, `sub_494B80`
- basic blocks: `5`
- cyclomatic complexity: `2`

Bounded behavior:

- Reads current base state from signed byte `this+0x103` and compares it with the unsigned byte argument.
- If `this+0x103 == a2`, skips timer state changes and calls `sub_494B80(this, a2)` anyway.
- If the state differs and `a2 == 0x0b`, sets byte `this+0x119` to `1`, calls `sub_5975E0(this+0xa4, 0, 150, 0, 0)`, then calls `sub_494B80(this, 0x0b)`.
- If the state differs and `a2 != 0x0b`, sets byte `this+0x119` to `0`, calls `sub_597600(this+0xa4)`, then calls `sub_494B80(this, a2)`.
- `sub_5975E0` is a one-block wrapper that calls `sub_597910((_DWORD *)unk_67AB80, this, a2, a3, a4, a5)`, supporting "schedule/start timer" behavior but not a final source helper name.
- `sub_597600` is a one-block wrapper that calls `sub_597A10((_DWORD *)unk_67AB80, this)`, supporting "cancel/remove timer" behavior but not a final source helper name.
- `sub_494B80` compares/writes byte `this+0x103`; when changed, it writes the new byte and calls a virtual slot at `vtable + 0x20` with `this+68`. This confirms it is the lower-level base visual-state setter/update path.

The function is source-authored class method logic, not a compiler thunk or data item. The required source-name/source-shape inference now resolves enough names for a formal first draft:

| Entity | Best source-facing name | Evidence | Rejected alternatives |
| --- | --- | --- | --- |
| Method | `PrettyButtonControlPane::SetState(unsigned char state)` | Class2 Method Notes use `SetState`; accepted Direction/Gender analyses prefer `SetState` / visual-state wording for the same `+0x103` byte-state override; target title `SetVisualState` remains a descriptive alias. | `SetEnabled` is rejected because the argument is a byte state and state `0x0b` is special-cased; not boolean-only. `OnTimer` is rejected because this method schedules/removes timers but is reached by the visual-state vtable slot. |
| `this+0x103` | inherited `m_visualState` | [UID:0003N2] documents `ControlPaneSetVisualState` as the setter for byte `+0x103`; Direction/Gender accepted reports use `m_visualState` in source-shaped snippets. | `m_enabled` is rejected because [UID:0003N2] says old `SetEnabled` wording is provisional/misleading for the byte state; `m_state` is less precise. |
| `this+0x119` | `m_visualStateFrameActive` | UID0004E7 writes it only when the visual state changes; `OnPaint` at `0x0054b7c0` reads byte `this+0x119` first and selects frame-id field `this+0x110` / decimal `272` when true. | `m_enabled`, `m_pressed`, and `m_hovered` are too specific or contradicted by the byte-state/timer behavior; `m_stateFrameOffset` fits Direction/Gender frame-index offsets but here the field is a flag selecting a stored frame id, not an integer offset added to a resource index. |
| `this+0xa4` | inherited `m_timerHandler` adjusted subobject/facet | [UID:0001K8] documents many callers using embedded timer-handler subobjects at offsets such as `+0xa4`; UID0004E7 passes `this+0xa4` as `ecx` to the TimerHandler wrappers. | `m_hoverTimer` and `m_animationTimer` are too target-specific; the actual wrapper type is the shared `TimerHandler` facet. |
| State literal `0x0b` | raw visual-state literal `0x0b`, comment as animated/alternate-frame state | Direction/Gender reports also special-case `0x0b`; UID0004E7 schedules a 150 ms timer and selects the alternate frame flag only for `0x0b`. | A named enum such as `kControlStateHover` or `kPressed` is not proven; keep literal in formal C++ to avoid false enum names. |
| `sub_5975E0` | `TimerHandler::ScheduleTimer` | [UID:0001K8] emits exactly this wrapper name/signature and documents forwarding to `g_pTimerMgr->ScheduleTimer`. | Feature-local scheduler names are rejected by UID0001K8 as caller pollution. |
| `sub_597600` | `TimerHandler::RemovePendingTimers` | [UID:0001K8] emits exactly this wrapper name/signature and documents forwarding to `g_pTimerMgr->RemovePendingTimersForOwner`. | `StopAnimation`/`CancelHoverTimer` are too target-local for the generic wrapper. |
| `sub_494B80` | `ControlPane::SetVisualState` | [UID:0003N2] title, behavior, vtable proof, and xrefs establish this as the inherited visual/control state setter. | `SetEnabled` is historical/provisional and rejected as the primary formal name for this target. |

## Evidence Standards Used

- Current by-* docs are treated as durable project evidence.
- IDA MCP calls were narrow, paged, and schema-current: `idb_list`, `server_health`, exact `lookup_funcs`, bounded `entity_query`, exact `analyze_function`, exact `xrefs_to`, exact `callees`, and small `get_bytes` reads.
- Local PE byte scanning was bounded to exact pointer byte patterns for UID0004E7 and sibling/positive-control values.
- Generated files and coverage reports were not edited or used as authority.
- Prior B011 UID0001F9 research was used as context for split inventory and prior validator provenance, not as a substitute for target-specific MCP evidence.

## Evidence Checked

- Read `tools/leaser/Agents/Agent-B001/goal.md`.
- Read the project workflow skill and required B-agent workflow reference.
- Read `by-structure.md` sections for IDA MCP Output Discipline and owner/emitter/reconstructable/C++ rules.
- Read target `by-memory/0x0054b750-0x0054b7b2.PrettyButtonControlPaneSetVisualState.md`.
- Read support docs `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`, `by-class/PrettyButtonControlPane.md`, `by-file/PrettyButtonControlPane.md`, `by-class/PrettyButtonControlPane2.md`, `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`, `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`, and sibling `by-memory/0x0054ba30-0x0054ba92.PrettyButtonControlPane2SetVisualState.md`.
- Read sibling/neighbor child docs for class1 state-byte forwarder, callback setter, paint, and related class2 entries where needed.
- Searched current and executed B-agent reports for `0004E7`, `PrettyButtonControlPaneSetVisualState`, `0x0054b750`, `SetVisualState`, `SetEnabled`, `sub_5975E0`, `sub_597600`, `sub_494B80`, and `PrettyButtonControlPane`.
- Relevant prior report found: `executed-b-agent-research/B011/0001F9-PrettyButtonControls-source-quality.md`, which created/split the exact child page and recorded the broad island inventory.
- MCP `idb_list` found active session `b011_0004EC_20260702`.
- MCP `server_health` was `ok`, with Hex-Rays ready.
- MCP `lookup_funcs` confirmed `0x0054b750 -> sub_54B750 size 0x62`; `0x0054b7b2` is not a function; sibling `0x0054ba30 -> sub_54BA30 size 0x62`; `0x0054ba92` is not a function.
- MCP bounded `entity_query` over `0x0054b700-0x0054b8c0` returned class1 functions at `0x0054b700`, `0x0054b720`, `0x0054b750`, `0x0054b7c0`, `0x0054b880`, and next constructor `0x0054b8c0`.
- MCP `analyze_function 0x0054b750` provided the exact decompiled body, assembly, callees, vtable data xref, and basic-block summary.
- MCP `analyze_function 0x0054ba30` confirmed class2 sibling parity with the same control flow and callees, with byte `this+0x11d` instead of class1 `this+0x119`.
- MCP `xrefs_to 0x0054b750` returned one xref, data at `0x00622320`, and no direct code callers.
- MCP `xrefs_to 0x0054ba30` returned one xref, data at `0x006223c4`, and no direct code callers.
- MCP `xrefs_to 0x00622320` and `0x006223c4` returned no xrefs to the slot addresses themselves, matching vtable-driven use through object vptrs.
- MCP `callees` for both `0x0054b750` and `0x0054ba30` returned exactly `sub_5975E0`, `sub_494B80`, and `sub_597600`.
- MCP `get_bytes` confirmed boundary padding and function bytes:
  - `0x0054b744` for 12 bytes: all `0xcc`
  - `0x0054b750` for 98 bytes: complete target body
  - `0x0054b7b2` for 14 bytes: all `0xcc`
  - `0x0054ba24` for 12 bytes: all `0xcc`
  - `0x0054ba30` for 98 bytes: complete sibling body
  - `0x0054ba92` for 14 bytes: all `0xcc`
  - `0x00622320` bytes `50 b7 54 00`
  - `0x006223c4` bytes `30 ba 54 00`
- Local PE pointer-byte scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` found:
  - VA bytes for `0x0054b750` exactly once at file offset `0x220d20`, matching vtable slot VA `0x00622320`
  - RVA bytes for `0x0014b750` zero times
  - sibling VA bytes for `0x0054ba30` exactly once at file offset `0x220dc4`, matching vtable slot VA `0x006223c4`
  - sibling RVA bytes for `0x0014ba30` zero times
  - positive control VA bytes for OnPaint `0x0054b7c0` exactly once at file offset `0x220d1c`
  - bytes for vtable slot address `0x00622320` zero times

## Positive Evidence Summary

UID0004E7 has exact source-method ownership under `PrettyButtonControlPane`. The primary vtable data page records slot `0x00622320 -> 0x0054b750`, and fresh MCP confirms this is the only xref to the function. The class page and file page route the range through `PrettyButtonControlPane` and `PrettyButtonControlPane.cpp`, and the class2 sibling at UID0004EE mirrors the body under `PrettyButtonControlPane2`.

The body behavior is now stronger than the current target summary. It is not merely "compares/stores a state byte"; it compares `this+0x103`, uses state value `0x0b` as a special animated/hover-like state, toggles class1 flag byte `this+0x119`, starts `this+0xa4` with a 150 ms schedule through `sub_5975E0`, stops it through `sub_597600`, and delegates the actual state write/update to `sub_494B80`.

The function boundaries are exact. The lower gap `0x0054b744-0x0054b750` and upper gap `0x0054b7b2-0x0054b7c0` are `0xcc` padding, and `lookup_funcs` says `0x0054b7b2` is not a function.

The local pointer-byte scan supports vtable-only reachability. The function VA occurs once in the PE at the expected vtable slot file offset, the RVA form is absent, and sibling/OnPaint positive controls land in adjacent vtable entries.

## Negative Evidence Summary

There is no evidence for direct code-call ownership outside the class virtual dispatch route. MCP `xrefs_to 0x0054b750` returned only the data xref at `0x00622320`; local PE VA/RVA pointer scanning found no additional function-pointer copies beyond the vtable entry.

There is no support for moving the target to [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) as direct canonical owner. The file page is the source root, but the method belongs directly to class [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md).

There is no support for moving the target to `ButtonControlPane` or base-control ownership. `sub_494B80` is the shared base visual-state setter/update path, but UID0004E7 is a derived class override/wrapper that adds PrettyButton-specific animation flag/timer behavior before delegating to the base setter.

There is no support for moving the target to CreateUser dialog owners. Constructor fan-in makes CreateUser dialog code a consumer of these controls; the vtable slot, class docs, sibling class, and file route keep this as reusable UI control source.

The remaining negative evidence is narrower: exact original enum name for state `0x0b` is still not proven, and the exact original method spelling may have been `SetState` or `SetVisualState`. That uncertainty does not block first-draft C++ because accepted sibling reports already use `SetState`/visual-state naming for this byte-state override family, and the formal body can keep raw literal `0x0b` rather than inventing an enum. A boolean-only `SetEnabled` method name remains rejected.

## Ranked Ownership Analysis

1. [UID:0000AR] `PrettyButtonControlPane` accepted.
   Evidence for: UID0002UW vtable slot `0x00622320 -> 0x0054b750`; target lives in class1 executable island; body uses class1-specific animation flag `this+0x119`; sibling UID0004EE is the class2 counterpart with `this+0x11d`; current target already has `CANONICAL_OWNER:0000AR`; file and class support docs route UID0004E7 through class1.
   Evidence against: none material. Remaining uncertainty is naming/source shape, not owner.

2. [UID:0000MP] `PrettyButtonControlPane.cpp` file route accepted as emitter chain context, rejected as direct canonical owner.
   Evidence for: source file page owns the two styled button classes under `NexusTK/ui/controls/`; target source should eventually be emitted through this file route when ready.
   Evidence against direct ownership: `by-structure.md` says direct semantic owner should be the narrowest true class owner; this is a class virtual method, not a free file-level helper.

3. [UID:0000AS] `PrettyButtonControlPane2` rejected.
   Evidence for: class2 sibling at `0x0054ba30` has the same behavior and slot pattern.
   Evidence against: UID0004E7 is pointed to by class1 vtable slot `0x00622320`; class2 owns the separate sibling at `0x006223c4 -> 0x0054ba30`.

4. `ButtonControlPane` / generic base-control ownership rejected.
   Evidence for: `sub_494B80` is a shared base visual-state setter/update helper.
   Evidence against: UID0004E7 wraps that helper with PrettyButton-specific timer/animation behavior and is reached from the PrettyButton class vtable, not from a base-control vtable/data route.

5. CreateUser dialog or caller ownership rejected.
   Evidence for: prior constructor fan-in places the class construction in CreateUser dialog code.
   Evidence against: UID0004E7 has no direct dialog caller; it is a vtable method for reusable control classes.

6. no-owner/non-emitting ownership rejected.
   Evidence for no-owner: none; class vtable slot gives direct class owner.
   Evidence against non-emitting now: class owner [UID:0000AR] has an emitter route to the source file, and accepted support pages supply source-facing names for both TimerHandler wrappers and the inherited visual-state setter.

## Source Placement

UID0004E7 should stay under [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md), with eventual source route through [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) in `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.

This stays under [UID:0000AR] because the primary PrettyButtonControlPane vtable slot at `0x00622320` contains `0x0054b750`, the sibling class2 slot at `0x006223c4` contains the separate `0x0054ba30` body, and the offset difference `this+0x119` versus `this+0x11d` matches two distinct class layouts rather than one file-level static helper.

It is not `PrettyButtonControlPane2`; that class has its own UID0004EE sibling. It is not a broad aggregate or UID0001F9 child-index emission point; UID0001F9 is now a non-emitting split/index parent. It is not no-owner handling because the vtable slot and class docs provide a direct owner.

## First-Draft C++ Recommendation

UID0004E7 is eligible for draft C++ insertion in this report.

Gate analysis: the proposed score `88/91` has an average greater than `85`, the direct class owner [UID:0000AR] is known, and the class routes to the source file [UID:0000MP]. `EMITTER_UIDS` can become `0000AR` because this is a class virtual method with a valid class-to-file emitter chain. The formal C++ below uses already accepted project names for the inherited visual-state setter and timer wrappers, and uses conservative inferred member names where the target itself proves the role.

Recommended formal insertion text:

```cpp
void PrettyButtonControlPane::SetState(unsigned char state)
{
    if (m_visualState != state)
    {
        if (state == 0x0b)
        {
            m_visualStateFrameActive = true;
            m_timerHandler.ScheduleTimer(0, 150, 0, 0);
        }
        else
        {
            m_visualStateFrameActive = false;
            m_timerHandler.RemovePendingTimers();
        }
    }

    ControlPane::SetVisualState(state);
}
```

Source-shape proof: the method has no locals other than the incoming byte state and `this`; the only branch is the state-change guard plus the `state == 0x0b` special case; the helper calls map directly to accepted `TimerHandler` and `ControlPane` source methods; and keeping `0x0b` literal avoids inventing an enum. The raw decompiler `int` return is an ABI artifact propagated from callees; a source-shaped virtual setter should be `void`, as in the accepted Direction/Gender visual-state snippets and the `TimerHandler` wrapper page's own raw-`int` to source-`void` policy.

## Recommended Target Doc Changes

- Raise UID0004E7 metadata to `COMPLETION:88` and `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000AR`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:0000AR`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Insert the formal C++ block from the First-Draft C++ Recommendation.
- Replace the current short Item Summary with a source-quality summary that mentions the exact `0x62` function, vtable-only slot `0x00622320`, `m_visualState` / `this+0x103` state comparison, `m_visualStateFrameActive` / `this+0x119` frame-selection flag, inherited `m_timerHandler` / `this+0xa4` 150 ms timer start/remove behavior, delegation to `ControlPane::SetVisualState`, sibling UID0004EE parity, and first-draft C++ readiness.
- Add report-level detail for MCP health/session, function inventory, exact boundary padding bytes, xref negatives and positive vtable controls, PE VA/RVA pointer-byte negative search, bounded instruction behavior, helper behavior, ranked naming inference, owner/source-placement rationale, rejected alternatives, score rationale, and emitted-code proof.

## Recommended Support Doc Changes

- `by-class/PrettyButtonControlPane.md`: update the Method Notes row currently naming `0x0054b750-0x0054b7b1` as `SetEnabled`. Recommended wording is `SetState` / `SetVisualState` with role "compares inherited `m_visualState` byte `this+0x103`, toggles `m_visualStateFrameActive` byte `this+0x119`, schedules/removes the inherited `m_timerHandler` at `this+0xa4` around state literal `0x0b`, and delegates to `ControlPane::SetVisualState`." This is lower-detail/stale relative to the new target evidence.
- `by-file/PrettyButtonControlPane.md`: update broad "method children intentionally keep formal C++ blank" wording if it still covers UID0004E7. The file can retain broad caveats for other method children, but UID0004E7 should be called out as first-draft C++ ready if the target is implemented.
- `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`: already records `0x00622320 -> UID0004E7` as the enabled/hover-state virtual slot. During callback, verify as already-present unless support wording must be updated to "visual-state/animation scheduling" with the vtable-only xref proof.
- `by-memory/0x0054ba30-0x0054ba92.PrettyButtonControlPane2SetVisualState.md`: sibling page is same structure but lower-detail. Do not edit unless callback scope includes sibling synchronization; record it as sibling comparison evidence or already-present support if not in callback scope.
- `by-class/PrettyButtonControlPane2.md`: already identifies the class2 sibling as `SetState` and the child as `SetVisualState`; no edit is required for UID0004E7 unless supervisor asks for symmetric sibling detail.
- `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`: already records UID0004E7 as exact child and split/index parent context. No target-driven edit is required unless it still has a stale statement contradicting vtable-only/source-method ownership.

## Score And Metadata Recommendation

Recommended metadata for UID0004E7:

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | 84 | 88 | Exact body behavior, boundary padding, vtable-only reachability, sibling comparison, helper roles, PE pointer-byte negatives, ranked source-name inference, support-page name reuse, and formal first-draft C++ are now documented. Completion stays below final-audit range because exact original method spelling and enum name remain provisional. |
| `CONFIDENCE` | 88 | 91 | Confidence rises because independent MCP facts agree: function size/end, decompilation, assembly, xrefs, callee list, vtable bytes, sibling parity, local PE pointer scan, paint consumption of `+0x119`, and accepted TimerHandler/ControlPane support names. It remains below final audit because the exact original enum spelling for state `0x0b` is unknown. |
| `CANONICAL_OWNER` | `0000AR` | `0000AR` | Direct class vtable slot and class layout evidence support `PrettyButtonControlPane`. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | This is source-authored class method logic, not padding or compiler-only thunk/data. |
| `EMITTER_UIDS` | blank | `0000AR` | The direct class owner has a valid emitter chain through the PrettyButtonControlPane source file, and this method now has behavior-ready first-draft source. |
| Formal C++ | blank | populate | Formal body uses accepted `TimerHandler::ScheduleTimer`, `TimerHandler::RemovePendingTimers`, `ControlPane::SetVisualState`, and conservative inferred member names backed by target and sibling evidence. |

## Open Questions With Attempted Resolution

- Exact source method name: resolved for first draft as `SetState`, with `SetVisualState` retained as descriptive alias. Evidence: class2 Method Notes use `SetState`, target title uses `SetVisualState`, Direction/Gender reports reject boolean `SetEnabled` and recommend `SetState`/visual-state wording for the same inherited `+0x103` state override. Score/C++ impact: formal C++ uses `SetState`; support docs should replace stale `SetEnabled` primary wording.
- State literal `0x0b`: behavior resolved, enum spelling unresolved. It is the special state that turns on the frame-selection flag and schedules a 150 ms timer before delegating to the base setter. Score/C++ impact: formal C++ keeps literal `0x0b` instead of inventing an enum.
- Member names: resolved enough for first draft. `m_visualState` for inherited `+0x103` follows [UID:0003N2] and Direction/Gender convention; `m_timerHandler` for `+0xa4` follows [UID:0001K8] and many support pages; `m_visualStateFrameActive` for `+0x119` is target-specific and backed by UID0004E7 writes plus OnPaint selecting frame id `+0x110` when the flag is true. Score/C++ impact: formal C++ can be supplied, capped below final audit for original spelling uncertainty.
- Timer helper names: resolved enough for first draft. [UID:0001K8] already emits `TimerHandler::ScheduleTimer` and `TimerHandler::RemovePendingTimers`; UID0004E7 passes `this+0xa4` as the receiver and arguments `(0,150,0,0)` or no arguments respectively.
- Reachability: resolved as vtable-only for this target. MCP and PE scanning find only the primary vtable pointer, with no direct call/xref copies.
- Ownership: resolved as UID0000AR. File route and sibling class are context, not direct owner changes.
- First-draft C++: resolved as formal code. Exact original enum spelling remains open, but the emitted body can preserve exact behavior with raw literal `0x0b` and accepted helper names.

## Validator Results

Implementation callback scoped validators:

- `python .\tools\validator.py --mode file --file by-memory/0x0054b750-0x0054b7b2.PrettyButtonControlPaneSetVisualState.md --apply --queue-timeout 240`
  - `command_id: 000000004960`
  - `command_timestamp: 2026-07-03T01:53:44-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Side effects: `completion_update 0004E7 88`, `confidence_update 0004E7 91`, `autogen_registry_update` for parent/emitter/hash/C++ block, `uid_link_insert` for UID0001K8 links, `projected_stats_update`, `generated_refresh: deferred`.
  - Warning: `missing_ref_uid 0003N2` because UID0003N2 is not present in `validator.ini`; no manual validator state edit was made.
- `python .\tools\validator.py --mode file --file by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md --apply --queue-timeout 240`
  - `command_id: 000000004961`
  - `command_timestamp: 2026-07-03T01:53:44-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Side effects: `projected_stats_update`, `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-class/PrettyButtonControlPane.md --apply --queue-timeout 240`
  - `command_id: 000000004986`
  - `command_timestamp: 2026-07-03T02:08:21-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Side effects: `projected_stats_update`, `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-file/PrettyButtonControlPane.md --apply --queue-timeout 240`
  - `command_id: 000000004987`
  - `command_timestamp: 2026-07-03T02:12:52-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Side effects: `projected_stats_update`, `generated_refresh: deferred`.

Generated freshness observation: each changed by-* validator returned `generated_refresh: deferred` with matching `generated_refresh_command_id`/timestamp. Generated project-level files were not manually edited. Generated output was not required for claim verification beyond the source by-* validators.

## Changed Files

Implementation callback changed files:

- `by-memory/0x0054b750-0x0054b7b2.PrettyButtonControlPaneSetVisualState.md`
- `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`
- `by-class/PrettyButtonControlPane.md`
- `by-file/PrettyButtonControlPane.md`
- `tools/leaser/Agents/Agent-B001/research/0004E7-PrettyButtonControlPaneSetVisualState-source-quality.md`

No generated files, coverage reports, validator state, queues, archives, supervisor ledgers, or report lifecycle state were manually edited. No `execute_report`, lifecycle/archive command, registry command, report move, or dry-run/probing variant was run.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004E7-01 | UID0004E7 is exact function `0x0054b750` size `0x62`; `0x0054b7b2` is not a function. | High | MCP `lookup_funcs` returned `sub_54B750` size `0x62`; `0x0054b7b2` returned `Not a function`. | Target `Evidence` / range summary | incorporate | applied: target Evidence records size, non-function end, half-open range, and command `000000004960` validated `ok:1`. |
| C-0004E7-02 | The method compares byte `this+0x103` with the argument and delegates final state write/update to `sub_494B80`. | High | MCP `analyze_function 0x0054b750`; `sub_494B80` analysis writes `this+0x103` and calls virtual slot `+0x20` on change. | Target `Behavior`; class/file support notes | incorporate | applied: target Behavior and Source Shape sections document `m_visualState`/`ControlPane::SetVisualState`; class/file support docs repeat source shape; validators `000000004960`, `000000004986`, `000000004987` passed. |
| C-0004E7-03 | State `0x0b` is the special animated state: set `this+0x119 = 1`, schedule `this+0xa4` for 150 ms, then call `sub_494B80(this, 0x0b)`. | High | MCP assembly/decompilation at `0x54b76e-0x54b78d`, pushes `0,0,0x96,0`, stores `+0x119 = 1`, calls `sub_5975E0`, then `sub_494B80`. | Target bounded behavior / Item Summary | incorporate | applied: target Item Summary/Behavior and class/file support docs document `m_visualStateFrameActive`, `m_timerHandler`, 150 ms, and literal `0x0b`; validators `000000004960`, `000000004986`, `000000004987` passed. |
| C-0004E7-04 | Non-`0x0b` changed states clear `this+0x119`, stop/cancel the `this+0xa4` timer, and delegate to `sub_494B80(this, a2)`. | High | MCP assembly/decompilation at `0x54b798-0x54b7a7`; call to `sub_597600`. | Target bounded behavior / Item Summary | incorporate | applied: target Behavior documents flag clear, `TimerHandler::RemovePendingTimers`, and final delegation; support docs include starts/removes timer semantics; validators passed. |
| C-0004E7-05 | Boundary bytes around UID0004E7 are padding: `0x0054b744-0x0054b750` and `0x0054b7b2-0x0054b7c0` are `0xcc`. | High | MCP `get_bytes` read 12 bytes at `0x0054b744` all `0xcc`; 14 bytes at `0x0054b7b2` all `0xcc`. | Target boundaries | incorporate | applied: target Evidence records both padding spans; class support evidence records padding at both boundaries; validator `000000004960` passed. |
| C-0004E7-06 | Reachability is vtable-only through `0x00622320`; there are no direct code xrefs to `0x0054b750`. | High | MCP `xrefs_to 0x0054b750` returned one data xref at `0x00622320`; no code xrefs. | Target xrefs / source placement; UID0002UW support | incorporate | applied: target Evidence/Sibling sections and UID0002UW IDA Evidence/Changes document vtable-only reachability; validators `000000004960` and `000000004961` passed. |
| C-0004E7-07 | Local PE pointer-byte scan found the UID0004E7 VA bytes exactly once at file offset `0x220d20` and no RVA encoding, matching the vtable slot. | High | PowerShell binary scan of `NexusTK.exe`; positive controls for sibling and OnPaint landed at adjacent vtable offsets. | Target pointer-byte search evidence; UID0002UW support | incorporate | applied: target Evidence and UID0002UW IDA Evidence include VA/RVA pointer-byte result and controls; validators `000000004960` and `000000004961` passed. |
| C-0004E7-08 | Class2 sibling UID0004EE is byte-pattern equivalent except it uses `this+0x11d` and vtable slot `0x006223c4`. | High | MCP `analyze_function 0x0054ba30`; `get_bytes` sibling body; `xrefs_to 0x0054ba30` one data xref at `0x006223c4`. | Target sibling comparison / support notes | incorporate | applied: target `Sibling And Reachability Comparison` documents class2 parity, `+0x11d`, and slot `0x006223c4`; parent/class2 support pages were verified already-present for sibling context and not edited. |
| C-0004E7-09 | Canonical owner should remain UID0000AR, not file owner, class2, base ButtonControlPane, CreateUser dialogs, or no-owner. | High | UID0002UW slot `0x00622320 -> UID0004E7`; target support docs; sibling split; `by-structure.md` narrow-owner rule. | Target ownership / Ranked Ownership Analysis | incorporate | applied: target metadata keeps `CANONICAL_OWNER:0000AR`; target Ownership/C++ Policy documents rejected owner alternatives; class/file/vtable docs support UID0000AR route; validators passed. |
| C-0004E7-10 | Formal C++ and emitter route should be enabled: set `EMITTER_UIDS:0000AR` and insert `PrettyButtonControlPane::SetState(unsigned char state)` using accepted `m_visualState`, `m_visualStateFrameActive`, `m_timerHandler`, `TimerHandler::ScheduleTimer`, `TimerHandler::RemovePendingTimers`, and `ControlPane::SetVisualState` names. | High | [UID:0003N2] documents `ControlPaneSetVisualState` at `0x00494b80`; [UID:0001K8] already emits TimerHandler wrapper names; Direction/Gender reports rank `SetState`/visual-state wording over `SetEnabled`; MCP proves the exact target body and OnPaint consumes `+0x119` as a frame-selection flag. | Target metadata / formal C++ / First-Draft C++ Recommendation | incorporate | applied: target metadata is `88/91`, `EMITTER_UIDS:0000AR`, formal C++ block populated; class/file docs mark UID0004E7 as emitting through UID0000AR; validators `000000004960`, `000000004986`, `000000004987` passed. |
| C-0004E7-11 | `by-class/PrettyButtonControlPane.md` has lower-detail/stale method-note wording `SetEnabled` for `0x0054b750`; callback should update or clarify it. | Medium | Class doc Method Notes row says `SetEnabled`; child row and target title say `SetVisualState`; fresh behavior is visual-state/timer scheduling. | `by-class/PrettyButtonControlPane.md` Method Notes | incorporate | applied: class Method Notes now use `SetState` / `SetVisualState`, child row says it emits `PrettyButtonControlPane::SetState(unsigned char state)`, and Evidence/Changes record source shape; validator `000000004986` passed. |
| C-0004E7-12 | `by-file/PrettyButtonControlPane.md` and UID0002UW already contain core route/vtable facts, but should be verified during callback for same-or-greater detail. | High | File doc has UID0004E7 split row; UID0002UW has key slot `0x00622320 -> UID0004E7`. | Support docs | incorporate | applied: file doc now marks UID0004E7 as source-ready/emitting and records method evidence; UID0002UW slot wording/evidence updated with vtable-only proof; parent split and class2 sibling docs were verified already-present for context and left unchanged. Validators `000000004987` and `000000004961` passed. |

## Implementation Tracking Checklist

- [x] Lease only files about to be edited if a supervisor implementation callback is approved. Proof: B001 leased target+UID0002UW first, released them after validators; waited through B015/B002/B011/B014 support leases; then leased/released `by-class/PrettyButtonControlPane.md`; then leased/released `by-file/PrettyButtonControlPane.md`. Final lease report showed no active B001 leases after releases.
- [x] Update UID0004E7 target metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000AR`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AR`, keep blank `EMITTER_POSITION_OPTIONAL`, and insert the formal C++ block from this report. Proof: applied in target header and formal `RECONSTRUCTION_CPP CODE`; validator `000000004960` passed.
- [x] Update UID0004E7 Item Summary and body with current MCP session/health, exact body behavior, ranked source-name inference, helper roles, xrefs, pointer-byte search, sibling comparison, owner/source-placement rationale, rejected alternatives, score rationale, and emitted-code proof. Proof: target Item Summary, Evidence, Behavior, Source Shape And Naming, Sibling And Reachability Comparison, Ownership And C++ Policy, Score Rationale, and Changes sections updated; validator `000000004960` passed.
- [x] Update `by-class/PrettyButtonControlPane.md` method-note wording for `0x0054b750` if callback scope permits support edits and the stale `SetEnabled` wording is still present; primary wording should be `SetState` / `SetVisualState`, not boolean `SetEnabled`. Proof: class Method Notes now use `SetState` / `SetVisualState`, exact child row emits `PrettyButtonControlPane::SetState(unsigned char state)`, and Evidence/Changes record source shape; validator `000000004986` passed.
- [x] Update `by-file/PrettyButtonControlPane.md` if its broad "method children keep formal C++ blank" statement still covers UID0004E7 after the target emits first-draft C++. Proof: file split inventory and source-output note now include UID0004E7 as emitting `PrettyButtonControlPane::SetState(unsigned char state)` through UID0000AR; Evidence Notes, Score Rationale, and Changes updated; validator `000000004987` passed.
- [x] Verify `by-file/PrettyButtonControlPane.md`, UID0002UW vtable data, UID0001F9 parent, and sibling UID0004EE for same-or-greater detail; mark ledger rows `already-present` where no support edit is needed. Proof: by-file was updated and validated; UID0002UW was updated with slot wording/vtable-only proof and validated; UID0001F9 already records UID0004E7 as class1 visual-state/animation child with padding and was left unchanged; UID0004EE and `by-class/PrettyButtonControlPane2.md` already identify the sibling comparison context and were left unchanged.
- [x] Run scoped validator only after implementation callback for every changed by-* file. Proof: validators `000000004960`, `000000004961`, `000000004986`, and `000000004987` all exited `0` with `ok:1`.
- [x] Do not run `execute_report`, lifecycle/archive commands, registry commands, dry-run/probing variants, manual report moves, or edit generated/project-level/coverage/validator/supervisor files. Proof: only scoped `--mode file` validators were run; no generated/project-level/coverage/validator/supervisor files were manually edited. Validator reported `projected_stats_update` and `generated_refresh: deferred` as tool side effects.
- [x] Update this report's ledger and checklist with `applied`, `already-present`, or `excluded-with-reason` states only during implementation callback. Proof: this ledger/checklist was updated during the accepted callback with applied/already-present proof and validator command IDs.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004996","destination_path":"executed-b-agent-research/B001/0004E7-PrettyButtonControlPaneSetVisualState-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0004E7-PrettyButtonControlPaneSetVisualState-source-quality.md","timestamp":"2026-07-03T02:26:07-04:00","uid":"0004E7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
