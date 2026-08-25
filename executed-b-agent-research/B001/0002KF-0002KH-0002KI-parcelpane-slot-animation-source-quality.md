# B001-goal2-parcelpane-slot-animation-source-quality-0002KF-0002KH-0002KI-20260617
** TARGET-REPORT-UID:0002KF **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: legacy executable/request-package material removed into inert same-stem companion; fresh Gate 1 required **

## Scope And Constraints

- Agent: B001.
- Primary targets:
  - [UID:0002KF] `by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md`
  - [UID:0002KH] `by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md`
  - [UID:0002KI] `by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md`
- Assignment type: report-only B-agent source-quality/inference work.
- Files changed by B001: this report only.
- Leases used: none. `goal.md` permits writing B001 research reports without a lease.
- Banned edits respected: no by-* docs, generated reports, generated/source files, IDA DB, or `by-memory/-coverage-report.md` were edited.

## Executive Recommendation

Keep all three targets as exact reconstructable/emitting `ParcelPane` methods owned by [UID:0000A6] `ParcelPane`, emitted through the existing `ParcelPane.cpp` source family [UID:0000MF]. Do not merge them into the aggregate and do not split them into new source method children. Add only one generated-data coverage row for the `0x00546aab-0x00546ac0` NOP/switch-table/alignment island after [UID:0002KI].

Recommended target metadata:

| UID | Recommended source-facing role | Completion | Confidence | Owner/emitter | Reconstructable | Formal C++ |
| --- | --- | ---: | ---: | --- | --- | --- |
| `0002KF` | `ParcelPane::OnTimer` / slot-animation timer callback; keep `ProcessSlotAnimations` as behavior alias | 87 | 91 | `0000A6` | true | leave blank for now |
| `0002KH` | protected virtual `AdvanceButtonAnimation` / `UpdateButtonAnimationCounter` helper | 88 | 91 | `0000A6` | true | leave blank for now |
| `0002KI` | protected virtual `ResolveButtonFrameIndex` / `GetButtonFrameIndex` helper | 89 | 92 | `0000A6` | true | leave blank for now |

Source placement should remain `NexusTK/ui/panels/ParcelPane.cpp`. Reject `PatchPane`, `FlyingParcelPane`-only, generic timer/input, and resource-library placement: the targets consume `ParcelPane` fields, sit in `ParcelPane` primary/tertiary vtables, are called by sibling `ParcelPane` paint/timer paths, and share the parcel notification resource family.

## Evidence Reviewed

- Target docs for `0x00546810-0x00546888`, `0x00546970-0x005469db`, and `0x005469e0-0x00546aab`.
- Support docs: `by-class/ParcelPane.md`, `by-file/ParcelPane.md`, `0x00545e40-0x005470ad.ParcelNotificationPanes.md`, `0x00546890-0x0054696f.ParcelPaneOnPaint.md`, `ParcelNotificationPaneLayouts.md`, `ParcelNotificationVtableData.md`, `ParcelNotificationVtableFamily.md`, `g_pParcelPane.md`, `ParcelPaneConstructor`, `ParcelPaneSetParcelSlotData`, `ParcelPaneOnKeyDown`, `ParcelPaneOnMouseEvent`, `ParcelIconPaneParcelUpdateCallback`, `FlyingParcelPaneAnimateStep`, `FlyingParcelPaneDrawParcelOrLetter`, and `TimerHandlerScheduleRemoveWrappers`.
- Coverage context from `by-memory/-coverage-report.md` around the parcel notification cluster.
- Live IDA MCP session `b003_00018a_ime_comp_20260617` against `NexusTK.exe.i64`.

Live IDA checks used:

```text
server_health
lookup_funcs 0x00546810 0x00546888 0x00546890 0x00546970 0x005469db 0x005469e0 0x00546aab 0x00546aac 0x00546ac0
analyze_function 0x00546810
analyze_function 0x00546970
analyze_function 0x005469e0
analyze_function 0x00546290
analyze_function 0x005464b0
disasm 0x005469e0 max_instructions=120 include_total=true
xrefs_to 0x00546810 0x00546970 0x005469e0 0x00621cc4 0x00621c84 0x00621c88 0x00621d50 0x00621d6c
get_bytes 0x00546888+8, 0x0054696f+1, 0x005469db+5, 0x00546aab+21, 0x00621c80+12, 0x00621cc0+8
callees 0x00546810 0x00546970 0x005469e0
```

Local conversion validation used the project integer-conversion helper. The exact historical command is already preserved in the report's linked non-authoritative `-removed.md` archive and must not be executed from this report.

Key numeric confirmations: `0xc8` is 200 ms, `0x64` is 100 ms, `0x78` is 120 bytes, `0x6b` is 107 bytes, `0xcb` is 203 bytes, `0xa0` is 160, `0xa4` is 164, `0xf8..0xff` are 248..255, `0x100` is 256, `0x110` is 272, `0x120` is 288, and `0x121` is 289.

## Range, Reachability, And Generated-Data Decision

| Range | Decision |
| --- | --- |
| `0x00546810-0x00546888` | Exact `0x78` byte function. `lookup_funcs` returns `sub_546810`; `0x00546888` is not a function. `get_bytes` confirms eight `0xcc` bytes at `0x00546888-0x00546890`. |
| `0x00546970-0x005469db` | Exact `0x6b` byte function. `lookup_funcs` returns `sub_546970`; `0x005469db` is not a function. `get_bytes` confirms five `0xcc` bytes at `0x005469db-0x005469e0`. |
| `0x005469e0-0x00546aab` | Exact `0xcb` byte modeled function. `lookup_funcs` returns `sub_5469E0`; `0x00546aab` and `0x00546aac` are not functions. |
| `0x00546aab-0x00546ac0` | Missing generated-data/alignment coverage. `get_bytes` shows one `0x90`, then four dword switch entries at `0x00546aac-0x00546abc`, then four `0xcc` bytes before `0x00546ac0` `FlyingParcelPaneConstructor`. Cover as ignored compiler switch table/padding, regenerated from [UID:0002KI]'s source switch. |

Reachability is vtable-only for all three target starts:

- `0x00546810` has one data xref from `0x00621cc4`, the `ParcelPane` tertiary `+0xa4` timer-handler slot.
- `0x00546970` has one data xref from `0x00621c84`, the `ParcelPane` primary helper slot `+0x48`.
- `0x005469e0` has one data xref from `0x00621c88`, the `ParcelPane` primary helper slot `+0x4c`.
- `analyze_function` reports no ordinary direct callers for any target. This is correct: `OnTimer` and `OnPaint` reach the helpers through virtual slots.
- `0x00546810` has one callee, `sub_5975E0` / `TimerHandler::ScheduleTimer` candidate. `0x00546970` and `0x005469e0` have no callees.

Reject the stale PatchPane caller/source route for [UID:0002KI]. Current IDA `xrefs_to 0x005469e0` reports only the `ParcelPane` vtable data xref, while ALERTBTN resource xrefs come from `ParcelPane::OnPaint` and `FlyingParcelPane::DrawParcelOrLetter`. PatchPane begins at `0x005470b0`, after the parcel cluster boundary.

## Heuristic / Inference Reanalysis And Validation

### Method Names And Signatures

Best source-facing names:

- [UID:0002KF] should be described as the `ParcelPane` timer callback, preferably `ParcelPane::OnTimer` or `ParcelPane::OnTimerEvent`. The current `ProcessSlotAnimations` name is a good behavior alias, but it is not the best source-facing method kind because the body is reached from the tertiary timer-handler vtable, ignores three callback arguments, always returns true, and reschedules itself through `TimerHandler::ScheduleTimer`.
- [UID:0002KH] should be `ParcelPane::AdvanceButtonAnimation` or `ParcelPane::UpdateButtonAnimationCounter`. Prefer `AdvanceButtonAnimation` in source-facing prose because the helper mutates a state/frame pair; keep `UpdateAnimationCounter` as a compatibility title if the file is not renamed. Source return should be `void`, not the decompiler's `char *` artifact. EAX returns the frame pointer only because the last expression leaves it there; callers ignore it.
- [UID:0002KI] should be `ParcelPane::ResolveButtonFrameIndex` or `ParcelPane::GetButtonFrameIndex`. Prefer `ResolveButtonFrameIndex` in source-facing prose because it maps state/count/side to an `ALERTBTN.EPF` frame and falls through to live animation frame bytes for state `3`.

Defensible signatures:

```text
bool ParcelPane::OnTimer(int timerId, int arg1, int arg2);
void ParcelPane::AdvanceButtonAnimation(ParcelButtonState* state, signed char* frame, bool rightSide);
int ParcelPane::ResolveButtonFrameIndex(const ParcelButtonState* state, unsigned char slotCount, bool rightSide) const;
```

The binary form differs because of calling conventions and multiple inheritance:

- `OnTimer` receives `ecx == owner + 0xa4`; normalize decompiler offsets by subtracting `0xa4`.
- `AdvanceButtonAnimation` is a primary virtual but does not read `ecx`, so IDA guesses `__stdcall`.
- `ResolveButtonFrameIndex` is a primary virtual and reads `this + 0xfe/+0xff` for live animation frames.

Rejected alternatives:

- Plain private non-virtual helpers: rejected for [UID:0002KH] and [UID:0002KI] because both are present in the primary `ParcelPane` vtable and are called through slots `+0x48/+0x4c`.
- Free/static helpers: rejected for the same vtable-slot reason and because [UID:0002KI] reads `ParcelPane` animation-frame fields.
- `ProcessSlotAnimations` as the formal source name: possible as an internal name, but weaker than `OnTimer` because [UID:0002KF] is the scheduled callback surface.

### Subobject And Field Normalization

[UID:0002KF] is the only target needing offset normalization. Its apparent decompiler fields are tertiary-subobject offsets:

| Binary expression | Owner offset | Recommended field |
| --- | ---: | --- |
| `this[85]` | `+0xf9` | `m_leftParcelCount` |
| `this[86]` | `+0xfa` | `m_rightParcelCount` |
| `this[88]` | `+0xfc` | `m_leftButtonState` |
| `this[89]` | `+0xfd` | `m_rightButtonState` |
| `this[90]` | `+0xfe` | `m_leftAnimationFrame` |
| `this[91]` | `+0xff` | `m_rightAnimationFrame` |
| `this[124]` | `+0x120` | `m_leftSlotAcknowledged` |
| `this[125]` | `+0x121` | `m_rightSlotAcknowledged` |
| `this - 96` | `+0x44` | inherited pane bounds/invalid rect |

The `ParcelPaneConstructor` and layout docs also support:

- `+0xf8`: `m_totalParcelCount`.
- `+0xfb`: `m_rightSlotActionEnabled` or `m_canOpenRightSlot`; constructor initializes it to `1`, mouse release gates the right-slot BulletinSession path on it, and `FlyingParcelPane::AnimateStep` sets it after delivery animation.
- `+0x100`: `m_leftButtonRect`, initialized to `(0,0,30,25)`.
- `+0x110`: `m_rightButtonRect`, initialized to `(31,0,62,25)`.

Use `count`, not `id`, for `+0xf8/+0xf9/+0xfa`. `ParcelIconPaneParcelUpdateCallback` reads a packed byte, splits low/high nibbles, sums them into total count, and forwards `(total, lowNibble, highNibble)` into `ParcelPaneSetParcelSlotData`, which stores them at `+0xf8/+0xf9/+0xfa`. That is stronger than the old "id/count" uncertainty.

### Button State Enum And Frame Constants

Recommended enum:

```text
enum ParcelButtonState : unsigned char {
    kParcelButtonIdle = 0,
    kParcelButtonHover = 1,
    kParcelButtonPressed = 2,
    kParcelButtonAnimating = 3,
};
```

Evidence:

- `ParcelPaneOnMouseEvent` event type `0` writes hover/idle state; event type `1` writes pressed state `2`; event type `3` release/action clears both state bytes. This proves state `2` is pressed and prevents state `3` from being another press variant.
- `ParcelPaneUpdateAnimationCounter` sets state `3` when a state-0 slot has a nonnegative frame counter, increments frames while state is `3`, and resets state to `0` after frame `13` left or `27` right.
- `ParcelPaneGetButtonFrameIndex` switches on states `0..3`. State `3` returns live frame bytes at `+0xfe/+0xff`; states `0..2` return fixed resource frames.

Recommended frame map for `ALERTBTN.EPF`:

| Side/state | Empty slot | Occupied slot | Animation frames |
| --- | ---: | ---: | --- |
| Left idle/hover/pressed | `0,1,2` | `3,4,5` | `6..13` |
| Right idle/hover/pressed | `14,15,16` | `17,18,19` | `20..27` |

`FlyingParcelPaneDrawParcelOrLetter` also uses `ALERTBTN.EPF` frame `5` for the flying parcel art, consistent with the occupied/pressed left button frame rather than a separate source module.

### Timer Interval And Animation Phasing

`ParcelPaneConstructor` schedules the first tertiary timer call with delay `100` ms (`0x64`). [UID:0002KF] reschedules itself with delay `200` ms (`0xc8`) after every tick. This supports naming the target as the recurring timer callback and interpreting `200` as the parcel-alert animation tick interval.

Constructor initialization sets the left animation frame byte `+0xfe` to `0xfd` (`-3` signed) and the right frame byte `+0xff` to `0`. [UID:0002KH] increments negative frame sentinels toward zero without entering animation state. Therefore the negative-frame path is an initial/stagger/delay mechanism, not an error state and not an alternate button state.

### Ownership, Source Placement, And Aggregate Policy

Keep all three direct children under [UID:0000A6] `ParcelPane`.

- [UID:0002KF] is in the `ParcelPane` tertiary timer-handler vtable and mutates only normalized `ParcelPane` fields.
- [UID:0002KH] and [UID:0002KI] are `ParcelPane` primary virtual helper slots adjacent to `OnPaint`.
- [UID:0002KG] `OnPaint` reaches [UID:0002KI] through primary slot `+0x4c` for both button rectangles.
- [UID:0002KF] reaches [UID:0002KH] through primary slot `+0x48` for both state/frame pairs.
- `ALERTBTN.EPF` / `ALERTBTN.PAL` resource strings are consumed by both `ParcelPane::OnPaint` and `FlyingParcelPane::DrawParcelOrLetter`, which supports the existing parcel notification source-family grouping but not a `FlyingParcelPane` owner for these three methods.

Keep [UID:0001EH] `ParcelNotificationPanes` as the broader reconstructable aggregate/source-family evidence page. It should not become the emitter for these exact methods, and it should not become a non-emitting split/index solely because of this pass. The exact method pages remain the correct coverage/emission units; the only extra child coverage needed is generated switch-table data after [UID:0002KI].

### Rejected Alternatives And Impact

- `left/right slot id`: rejected. Packet nibble parsing and total-sum behavior show counts.
- `state 3 == pressed`: rejected. Mouse press writes `2`; timer helper writes `3`; frame resolver treats `3` as live animation.
- `mouse release unknown`: bounded by support docs. Event type `3` in `ParcelPaneOnMouseEvent` is release/action because it clears pressed state, sends the left parcel action packet `0x41`, constructs the right `BulletinSession`, and sets acknowledged flags.
- `PatchPane` source/caller: rejected by current xref set and range boundary.
- `resource-library/helper owner`: rejected because `ALERTBTN` lookup is a resource dependency, not ownership. The frame map is `ParcelPane` UI behavior.
- `formal C++ ready now`: rejected for this batch only. Behavior is clear enough to raise scores, but final class declarations, timer callback spelling, scheduler wrapper spelling, and protected virtual helper names must be accepted into `ParcelPane` support docs first.

Score/source-placement/final-C++ impact:

- Scores can move above 85/85 because behavior, ranges, fields, enum values, vtable ownership, and generated-data treatment are now defensible.
- Owner/emitter and source placement should not change.
- Formal C++ should remain blank until the support pages adopt the field/enum/helper names and the `TimerHandler` callback signature is finalized.

## First-Draft C++ Recommendation

Do not populate formal C++ for [UID:0002KF], [UID:0002KH], or [UID:0002KI] in this pass.

This is not because the behavior is unknown. The behavior is now source-shape ready. The blocker is declaration/name coordination: the target pages still depend on provisional `ParcelPane` field names, the accepted source spelling of the tertiary timer callback (`OnTimer` versus `OnTimerEvent`), the `TimerHandler::ScheduleTimer` wrapper name, and the decision to expose the two primary helper slots as protected virtual methods. Populating formal C++ before the class/layout support docs are updated would bake guessed declarations into three emitting pages.

Recommended source shapes after support-doc acceptance:

```text
bool ParcelPane::OnTimer(int timerId, int arg1, int arg2);
void ParcelPane::AdvanceButtonAnimation(ParcelButtonState* state, signed char* frame, bool rightSide);
int ParcelPane::ResolveButtonFrameIndex(const ParcelButtonState* state, unsigned char slotCount, bool rightSide) const;
```

The supervisor should leave `RECONSTRUCTION_CPP` blank on all three targets for now. After `by-class/ParcelPane.md` and `ParcelNotificationPaneLayouts.md` accept the enum/field/helper names, [UID:0002KH] and [UID:0002KI] are the first eligible formal-C++ candidates; [UID:0002KF] should wait until the timer-handler callback signature and scheduler wrapper spelling are accepted.

## Support Docs To Update

- `by-class/ParcelPane.md`: add the `ParcelButtonState` enum, field names from `+0xf8..+0x121`, and source-facing helper names. Recommended support score after update: `88/90`.
- `by-type/by-struct/ParcelNotificationPaneLayouts.md`: replace `left/right slot id/count` with `m_leftParcelCount` and `m_rightParcelCount`; record `m_totalParcelCount`, `m_rightSlotActionEnabled`, `m_leftButtonState`, `m_rightButtonState`, `m_leftAnimationFrame`, `m_rightAnimationFrame`, `m_leftSlotAcknowledged`, `m_rightSlotAcknowledged`, and button rect names. Recommended support score after update: `88/90`.
- `by-file/ParcelPane.md`: keep `NexusTK/ui/panels/ParcelPane.cpp` placement; add the `ALERTBTN` frame map and note that the three methods are protected/virtual class helpers plus a timer-handler override. Recommended score can remain `87/86` or rise modestly to `88/88` after support text is updated.
- `by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md`: update the [UID:0002KI] call description to `ResolveButtonFrameIndex` and include the frame map.
- `by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md`: remove or supersede the stale PatchPane caller wording; record the current vtable-only xref and the `0x00546aab-0x00546ac0` generated switch-table/alignment coverage.
- `by-memory/-coverage-report.md`: supervisor-owned replacements/insertion below.

## Supervisor-Owned Coverage Rows

Do not let B001 edit `by-memory/-coverage-report.md`. Apply these rows if the score/source recommendations are accepted.

Replace the existing [UID:0002KF] row at the current ParcelNotificationPanes cluster position:

```text
    - [UID:0002KF][0x00546810-0x00546888.ParcelPaneProcessSlotAnimations](by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md) 0x00546810-0x00546888 | class timer callback | ParcelPaneOnTimer : reconstructable : 87% : strong : Live IDA reconfirms exact `0x78`/120-byte tertiary `TimerHandler` callback at `0x00621cc4`, adjusted `ParcelPane+0xa4` owner normalization, left/right count and acknowledgement guards, virtual animation-counter calls through primary slot `+0x48`, pane invalidation through primary slot `+0x20`, always-true return, and 200 ms `TimerHandler::ScheduleTimer` reschedule; source-facing name should be `OnTimer`/timer callback with `ProcessSlotAnimations` retained as behavior alias.
```

Replace the existing [UID:0002KH] row:

```text
    - [UID:0002KH][0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter](by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md) 0x00546970-0x005469db | protected virtual helper | ParcelPaneAdvanceButtonAnimation : reconstructable : 88% : strong : Live IDA reconfirms exact `0x6b`/107-byte primary virtual slot `0x00621c84`, no ordinary direct callers/callees, source-void helper semantics despite unused EAX artifact, button-state enum transitions from idle to animating, negative-frame sentinel increment, left frames `6..13`, right frames `20..27`, and reset to idle after the terminal frame.
```

Replace the existing [UID:0002KI] row:

```text
    - [UID:0002KI][0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex](by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md) 0x005469e0-0x00546aab | protected virtual helper | ParcelPaneResolveButtonFrameIndex : reconstructable : 89% : strong : Live IDA reconfirms exact `0xcb`/203-byte primary virtual slot `0x00621c88`, no ordinary direct callers/callees, `ALERTBTN.EPF` frame map for idle/hover/pressed/animating states, left/right occupied and empty offsets, live animation-frame reads at `+0xfe/+0xff`, and post-body switch table at `0x00546aac` that should be covered as generated data.
```

Insert immediately after the [UID:0002KI] row and before [UID:0002KJ] `FlyingParcelPaneConstructor`:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00546aab-0x00546ac0 | switch table/padding | ParcelPaneGetButtonFrameIndex switch table and alignment : ignored : 100% : strong : IDA `get_bytes` shows one `0x90` byte at `0x00546aab`, four dword jump-table entries at `0x00546aac-0x00546abc` for the `ParcelPaneResolveButtonFrameIndex` state switch, and four `0xcc` bytes at `0x00546abc-0x00546ac0` before `FlyingParcelPaneConstructor`; regenerate from the source switch, do not hand-author.
```

## Validation Command Log

Useful exact commands for supervisor/reviewer repetition:

> Executable block R001 was removed from this report and preserved verbatim in [0002KF-0002KH-0002KI-parcelpane-slot-animation-source-quality-removed.md](0002KF-0002KH-0002KI-parcelpane-slot-animation-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA MCP repetition should use the current open session from `idb_list`; this pass used `b003_00018a_ime_comp_20260617`.

## Blockers And Follow-Up

No same-task blocker remains for supervisor execution of metadata, support-doc, and coverage-row updates.

Remaining bounded blockers before formal C++:

- Accept final `TimerHandler` callback spelling and `TimerHandler::ScheduleTimer` wrapper name.
- Accept `ParcelPane` class declarations for the two primary helper virtuals.
- Apply the `ParcelButtonState` enum and field names in `ParcelPane`/layout support docs.
- Apply the generated-data coverage row for `0x00546aab-0x00546ac0`.

Next useful follow-up is a focused ParcelPane input/action naming pass for [UID:0002KD] and [UID:0002KE], because those methods decide the final source spelling for event names, action helper names, and the right-slot `BulletinSession` gate.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002KF-0002KH-0002KI-parcelpane-slot-animation-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002KF"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002KF-0002KH-0002KI-parcelpane-slot-animation-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002KF-0002KH-0002KI-parcelpane-slot-animation-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002KF"} -->
<!-- {"agent":"B001","command_id":"000000023072","details":"report marked for revalidation","event":"needs-revalidation","issue":"legacy executable/request-package material removed into inert same-stem companion; fresh Gate 1 required","source_path":"executed-b-agent-research/B001/0002KF-0002KH-0002KI-parcelpane-slot-animation-source-quality.md","timestamp":"2026-08-13T05:24:42-04:00","uid":"0002KF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
