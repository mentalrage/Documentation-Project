*** UID:0000DB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SliderControlPane

## Status

- Confidence: strong for behavior, vtable identity, constructor callers, setter callers, and control-family placement; medium for final helper names and original file split.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), with possible later `SliderControlPane.cpp` split.
- Core memory: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)

## Class Purpose

`SliderControlPane` is a value selector rendered from `SCRL001` frames. It determines horizontal or vertical orientation from bounds, tracks part hit-testing, draws arrows/track/thumb, handles mouse drag and capture, processes keyboard scroll commands, and runs a 30 ms auto-repeat timer.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SliderControlPane` | `0x00496630-0x004967b1` | Constructs the selector, initializes the frame array, chooses orientation from bounds, loads 12 frames, and clamps initial range/value to `[0, 30000]`. |
| `SetCurrentValue` | `0x004967c0-0x004967f7` | Clamps a requested value to `[0, this+0xfc]`, stores it at `this+0xfa`, and tail-calls the redraw/refresh virtual at slot `+0x20`. |
| `HitTestPart` | `0x00496800-0x00496ae7` | Returns arrow/track/thumb part id under a point. |
| `OnPaint` | `0x00496af0-0x004974a7` | Draws arrows, track, and proportional thumb for horizontal/vertical layouts. |
| `OnMouse` | `0x004974b0-0x00497772` | Starts drag/capture, updates thumb on move, calls the scroll-processing helper, and releases capture on mouse-up. |
| `OnKey` | `0x00497780-0x00497818` | Dispatches keyboard scroll commands through the four offset helpers and notifies the owner callback. |
| `OnTimer` | `0x00497850-0x00497886` | Auto-repeat scroll/update timer; skips when active part is idle and reschedules at 30 ms. |
| `ProcessScrollInput` | `0x00497c60-0x00497d6b` | Mouse/timer scroll helper that reads cursor position, hit-tests current part, updates offset helpers for part ids `13/14/16/17`, and notifies on value changes. |
| `UpdateThumbFromDrag` / `NotifyValueChanged` | `0x00497d80-0x0049803a` | Helper tail used by `ProcessScrollInput` for thumb-position math and final value-change notification. |
| Destructor/thunks | [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md), [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md) | Secondary adjustor thunks and scalar deleting destructor. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms modeled class functions at `0x00496630-0x004967b1`, `0x004967c0-0x004967f7`, `0x00496800-0x00496ae7`, `0x00496af0-0x004974a7`, `0x004974b0-0x00497772`, `0x00497780-0x00497818`, `0x00497850-0x00497886`, `0x00497c60-0x00497d6b`, `0x00497d80-0x00497fff`, `0x00498000-0x0049803a`, adjustor thunks `0x0049b003-0x0049b00e` and `0x0049b00e-0x0049b019`, and scalar deleting destructor `0x0049b5b0-0x0049b5eb`.
- 2026-06-07 A004 split-recheck created exact destructor-side children [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md) and [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md); the scalar deleting destructor is assigned here because the child is `86/88` and this direct class parent is `86/86`.
- Live IDA names the three vtable views as `??_7SliderControlPane@@6B@` at `0x00617f14`, `??_7SliderControlPane@@6B@_0` at `0x00617f7c`, and `??_7SliderControlPane@@6B@_1` at `0x00617fac`. Key slots are `0x00617f14 -> 0x0049b5b0`, `0x00617f58 -> 0x00496af0`, `0x00617f74 -> 0x00496800`, `0x00617f7c -> 0x0049b003`, `0x00617f80 -> 0x004974b0`, `0x00617f84 -> 0x00497780`, `0x00617fac -> 0x0049b00e`, and `0x00617fb0 -> 0x00497850`.
- Constructor evidence: IDA reports direct callers at `0x00528ffd` and `0x005290f1`. The body calls `ControlPane` construction at `0x004949e0`, installs the three vtable views at `0x00496672/0x0049667d/0x00496687`, initializes twelve `0x28`-byte frame records starting at `this+0x110`, selects vertical orientation through `this+0x108`, loads the frame table through `0x00543d70`/`0x004d02f0`, and clamps the limit field `this+0xfc` to `0x7530` (`30000`).
- Setter evidence: `0x004967c0` has direct callers at `0x00529659` and `0x00529677`, clamps against `this+0xfc`, writes `this+0xfa`, and tail-calls vtable slot `+0x20`.
- Input evidence: `OnKey` maps key cases `0x80/0x81`, `0x82/0x83`, `0x93`, and `0x94` to the four scroll-offset helpers [UID:000223][0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers](by-memory/0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers.md); `ProcessScrollInput` uses the same helper quartet for hit/drag result cases `13`, `14`, `16`, and `17`.
- Mouse/timer evidence: `OnMouse` calls the process helper at `0x004976e6` and timer `0x00497850` calls it at `0x0049786b`; `0x00497c60` also has a raw/unmodeled caller at `0x00497bff` from the non-padding gap before the modeled helper. The helper reads `g_pEventMan` at `0x0067a754`, calls cursor-position helper `0x004a9090`, and computes owner-relative cursor coordinates through `0x005447c0`.
- Confidence remains below final because the `0x00497886-0x00497c60` non-padding gap and helper names around `0x00497d80`/`0x00498000` still need final source-owner naming.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The page now documents exact live boundaries for the constructor, setter, hit-test, paint, mouse/key/timer virtuals, scroll-processing helper, drag/notify helper tail, vtable triplet, destructor thunks, caller evidence, and parent source family. |
| Confidence `86` | Live IDA vtable names, slot refs, constructor/setter callers, scroll-helper call graph, and destructor-thunk evidence agree with the ButtonControlPane parent and control-family memory pages. Confidence stays below final because helper names, private field names, and possible source split are still provisional. |

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md)
- [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md)
- [UID:000223][0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers](by-memory/0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers.md)
- [UID:000252][0x00617a38-0x0061885c.ControlPaneReadOnlyData](by-memory/0x00617a38-0x0061885c.ControlPaneReadOnlyData.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)

## Changes

- 2026-06-04 live IDA recheck:
  - Before: completion/confidence were `82/76`, `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, and the page omitted the `0x004967c0` value setter plus the `0x00497c60` scroll-processing helper family.
  - Changed to: completion `86`, confidence `86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000HY`.
  - Evidence: live IDA MCP confirmed the full function map, three `SliderControlPane` vtable views at `0x00617f14`, `0x00617f7c`, and `0x00617fac`, constructor xrefs at `0x00528ffd` and `0x005290f1`, setter xrefs at `0x00529659` and `0x00529677`, constructor vtable writes at `0x00496672/0x0049667d/0x00496687`, keyboard and mouse/timer links to the four scroll-offset helpers, and destructor thunks/scalar destructor at `0x0049b003-0x0049b019` and `0x0049b5b0-0x0049b5eb`.
- 2026-06-07 A004 Batch 046 split-recheck:
  - Before: destructor/thunk evidence pointed only to the broad [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) aggregate.
  - Changed to: linked exact adjustor child [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md) and exact scalar deleting destructor child [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md).
  - Evidence: A004 read-only IDA MCP confirmed two `0x0b` adjustors, `sub_49B5B0` ending at `0x0049b5eb`, vtable cell `0x00617f14`, and padding `0x0049b5eb-0x0049b5f0`.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents behavior, likely ownership, core/destructor ranges, constructor, hit test, paint, mouse/key/timer methods, destructor thunks, and constructor xrefs; confidence is capped by final class-name/source split uncertainty.
