*** UID:00008G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiniMapSymbolControlPane

## Status

- Confidence: strong for class behavior and method starts; medium for exact timer-host/base-class naming.
- Likely source file: [UID:0000LE][MiniMap](by-file/MiniMap.md), probably beside [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
- Current recovered file: `source-3/simroot_v2/class_MiniMapSymbolControlPane.cpp`
- Main memory doc: [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)

## Class Purpose

`MiniMapSymbolControlPane` is the animated symbol/marker control used by `MiniMapDialog` for player, NPC, portal, and party markers. It stores EPF/palette-backed sprite state, a text label, frame range, animation timing, and a timer callback path for cycling symbol frames.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x00455e60-0x00456031` | constructor | Builds the control pane, installs minimap symbol vtables, sets symbol image/text state, and initializes animation fields. |
| `0x00456040-0x0045609e` | destructor | Tears down symbol-control resources and shared pane state. |
| `0x004560a0-0x004560e1` | `StartAnimation` | Stores frame range/interval and schedules the timer through the generic timer handler path. |
| `0x00456180-0x00456293` | `OnAnimationTick` | Advances frame state and requests redraw/reschedule. |
| `0x004562a0-0x004562f8` | `OnDraw` | Draws the symbol sprite and text through EPF/palette sprite callback paths. |
| `0x004562f8`, `0x00456303` | adjustor thunks | Compiler-generated destructor adjustors. |
| `0x00456310-0x004563af` | scalar deleting destructor | Runs cleanup and optional delete. |
| `0x004563b0-0x004563b5` | `GetControlType` | Returns the minimap symbol control type byte. |

## Boundary Caveats

- Active generated output currently keeps `0x00456303` in the disabled partition even though IDA has a real thunk there. Treat it as compiler glue, not a missing behavior method.
- The `StartAnimation` decompile uses a polluted `FittingRoomDialog` timer-host cast. IDA shows the callee is generic timer registration (`0x005975e0`), so source migration should name this through the timer base/handler path rather than fitting-room code.

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `82/84`.
  - Before: page documented the animated symbol-control role and method ranges but remained unevaluated.
  - After: score reflects documented constructor/destructor, animation timer, draw path, destructor thunks, control-type helper, and the polluted fitting-room timer-host caveat.
  - Evidence: linked memory page [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) records IDA-confirmed method starts, multiple constructions from [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md), and generic timer registration through `0x005975e0`.
