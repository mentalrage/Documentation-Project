*** UID:00008G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiniMapSymbolControlPane

## Status

- Confidence: strong for class behavior, method starts, minimap ownership, and timer/draw evidence; medium for exact timer-host/base-class naming.
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

## Ownership And Parent Gate

This class is assigned to [UID:0000LE][MiniMap](by-file/MiniMap.md). The direct parent is now scored `85/86`, and the child is raised to `85/86` because the class page, [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md), and the MiniMap file page all identify the same minimap-local symbol-control role.

The ownership evidence is direct rather than merely topical: the memory aggregate records the constructor/destructor/animation/draw helper ranges, `MiniMapDialog` construction and use sites, and the generic timer-registration caveat. No other candidate source owner currently explains the marker sprite/text state, minimap dialog callers, and minimap control-type helper as well as `MiniMap.cpp`.

## Boundary Caveats

- Active generated output currently keeps `0x00456303` in the disabled partition even though IDA has a real thunk there. Treat it as compiler glue, not a missing behavior method.
- The `StartAnimation` decompile uses a polluted `FittingRoomDialog` timer-host cast. IDA shows the callee is generic timer registration (`0x005975e0`), so source migration should name this through the timer base/handler path rather than fitting-room code.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page now records the complete known method set, class purpose, direct minimap parent, caller/ownership evidence through the main memory range, and timer-host caveat. Completion remains below 90 until exact member layout, inherited base names, and final timer wrapper naming are audited. |
| Confidence | 86 | Confidence is strong because the class page, memory aggregate, and MiniMap file page agree on minimap-local ownership and method boundaries. It remains below final quality because the timer-host cast is polluted in decompilation and the compiler-generated thunks are not source declarations. |
| Parent | [UID:0000LE][MiniMap](by-file/MiniMap.md) | Child `85/86` and parent `85/86` both clear the strict 85/85 gate; by-structure ownership is direct because this is a minimap marker control constructed and used by the MiniMap dialog/renderer family. |

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)

## Changes

- 2026-06-07 Batch 093 parent-gate refresh:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`, and `AUTOGEN_PARENT_UID` blank because the parent-gate note was stale.
  - After: `COMPLETION:85`, `CONFIDENCE:86`, and parent [UID:0000LE][MiniMap](by-file/MiniMap.md).
  - Why: [UID:0000LE][MiniMap](by-file/MiniMap.md) now clears `85/86`, and [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) already documents the minimap-local constructor/destructor/animation/draw/control-type method set, MiniMapDialog construction/use evidence, and generic timer-registration caveat.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor/destructor/animation/draw/thunk/deleting-destructor/type-helper starts at `0x00455e60`, `0x00456040`, `0x004560a0`, `0x00456180`, `0x004562a0`, `0x004562f8`, `0x00456303`, `0x00456310`, and `0x004563b0`. Left `AUTOGEN_PARENT_UID` blank at that time because the likely MiniMap parent had not yet cleared the attachment gate.
- 2026-05-30: Grading changed from `0/0` to `82/84`.
  - Before: page documented the animated symbol-control role and method ranges but remained unevaluated.
  - After: score reflects documented constructor/destructor, animation timer, draw path, destructor thunks, control-type helper, and the polluted fitting-room timer-host caveat.
  - Evidence: linked memory page [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) records IDA-confirmed method starts, multiple constructions from [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md), and generic timer registration through `0x005975e0`.
