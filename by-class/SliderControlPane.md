*** UID:0000DB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SliderControlPane

## Status

- Confidence: strong for behavior, medium for final class name semantics.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) or a later `SliderControlPane.cpp` split.
- Core memory: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- Current recovered file: `source-3/simroot_v2/class_SliderControlPane.cpp`

## Class Purpose

`SliderControlPane` is a value selector rendered from `SCRL001` frames. It determines horizontal or vertical orientation from bounds, tracks part hit-testing, draws arrows/track/thumb, handles mouse drag and capture, processes keyboard scroll commands, and runs a 30 ms auto-repeat timer.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SliderControlPane` | `0x00496630-0x004967b0` | Constructs the selector, loads 12 sprite frames, clamps initial value to `[0, 30000]`. |
| `HitTestPart` | `0x00496800-0x00496ae6` | Returns arrow/track/thumb part id under a point. |
| `OnPaint` | `0x00496af0-0x004974a6` | Draws arrows, track, and proportional thumb. |
| `OnMouse` | `0x004974b0-0x00497771` | Starts drag/capture, updates thumb on move, releases on mouse-up. |
| `OnKey` | `0x00497780-0x00497817` | Dispatches keyboard scroll commands to owner. |
| `OnTimer` | `0x00497850-0x00497885` | Auto-repeat scroll/update timer. |
| Destructor/thunks | `0x0049b003-0x0049b5ea` | This-adjustor and scalar deleting destructor. |

## Evidence Notes

- Wave3 summary calls this a slider but constructor text uses scrollbar terminology. Treat it as the generic selector/slider control until caller ownership is reviewed.
- IDA MCP reports 2 direct constructor xrefs at `0x00528ffd` and `0x005290f1`.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [Wave3 noticed problems](../wave3_noticed_problems.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents behavior, likely ownership, core/destructor ranges, constructor, hit test, paint, mouse/key/timer methods, destructor thunks, and constructor xrefs; confidence is capped by final class-name/source split uncertainty.
