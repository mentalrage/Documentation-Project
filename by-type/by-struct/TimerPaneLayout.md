*** UID:0001WE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000F3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TimerPaneLayout

## Status

- Type kind: inferred class/layout support.
- Direct owner: [UID:0000F3][TimerPane](by-class/TimerPane.md). [UID:0000OU][TimerPane](by-file/TimerPane.md) remains the source-module owner.
- Confidence: strong for the documented offsets and class ownership; field names are behavior-backed, but base-class inheritance names need final reconciliation.
- Parent assignment: attached to [UID:0000F3][TimerPane](by-class/TimerPane.md), which already clears the strict gate at `88/90`.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `86` | The page documents the `0x120` object extent, three vtable/subobject offsets, all timer display fields from `+0x0f8` through `+0x118`, method evidence for constructor/configure/tick/draw/destruction, singleton context, and direct parent routing. It remains below final-audit level because the full inherited base-class layout and final source member spellings are not completely reconciled. |
| Confidence | `91` | The constructor, `SetTimer`, `OnTimerTick`, `OnDraw`, destructor helpers, singleton xrefs, and adjacent `TotemFrame` boundary all support this exact layout. Confidence stays below 95 because inherited base-class names and final source declaration shape remain open. |

## Working Layout

IDA and generated source agree that `TimerPane` is allocated with size `288` bytes (`0x120`).

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x000` | primary pane vtable/base | Main pane/render/event surface. |
| `+0x0a0` | secondary vtable/subobject | Destructor adjustor at `0x00598c3b` subtracts `0xa0`. |
| `+0x0a4` | timer callback vtable/subobject | `OnTimerTick` receives this pointer and subtracts `0xa4` to reach the base. |
| `+0x0f8` | `__time64_t startTime` | Written by constructor and timer configuration. |
| `+0x100` | `__time64_t endTime` | Compared by timer callback; used by countdown draw mode. |
| `+0x108` | `displayFormat` | `0 = SS`, `1 = MM:SS`, `2 = HH:MM:SS`. |
| `+0x10c` | `posX` | Screen X coordinate passed to constructor. |
| `+0x110` | `posY` | Screen Y coordinate passed to constructor and used by `DrawDigit`. |
| `+0x114` | `timerMode` | `0` static, `1` count-up, `2` countdown, `3` initial/delete mode. |
| `+0x118` | `displaySeconds` | Current value rendered by `OnDraw`; updated from time in modes `1` and `2`. |
| `+0x11c` | tail/padding or unknown | Not yet assigned. |

## Evidence

- `MapPane::HandlePacket` allocates `288` bytes before calling `TimerPane::TimerPane`.
- `TimerPane::TimerPane` writes vtables at `+0`, `+0xa0`, and `+0xa4`.
- `TimerPane::OnTimerTick` operates on the `+0xa4` subobject and compares `base + 0x100` against current time.
- `TimerPane::OnDraw` reads `+0x108`, `+0x110`, `+0x114`, and `+0x118`.
- `TimerPane::SetTimer` writes `+0x0f8`, `+0x100`, `+0x114`, and `+0x118`.
- 2026-05-31 IDA MCP recheck confirms the constructor at `0x005986e0` writes `g_pTimerPane`, installs vtables at `+0x00/+0xa0/+0xa4`, writes `posX`/`posY` at `+0x10c/+0x110`, initializes mode `+0x114` to `3`, writes display format `+0x108`, initializes `startTime` at `+0x0f8`, and schedules the timer callback through `this + 0xa4`.
- 2026-05-31 IDA MCP recheck confirms `SetTimer` at `0x00598880` writes mode `+0x114`, displayed seconds `+0x118`, start time `+0x0f8`, and end time `+0x100`.
- 2026-05-31 IDA MCP recheck confirms `OnDraw` at `0x00598960` reads display format `+0x108`, `posY` `+0x110`, mode `+0x114`, and displayed seconds `+0x118`, then emits `SS`, `MM:SS`, or `HH:MM:SS`.
- 2026-05-31 IDA MCP boundary check confirms the final `TimerPane` executable byte is `0x00598cbe`; `0x00598cbf-0x00598cc0` is the one-byte alignment gap before `TotemFrame`.
- 2026-06-08 live IDA MCP rechecked the TimerPane function boundaries: constructor `0x005986e0-0x00598842`, destructor body `0x00598850-0x00598879`, `SetTimer` `0x00598880-0x005988f7`, tick callback `0x00598900-0x0059895a`, draw `0x00598960-0x00598ae4`, digit draw `0x00598b40-0x00598bd5`, scalar deleting destructor `0x00598c60-0x00598cbf`, and a single `0xcc` byte at `0x00598cbf` before `TotemFrame`.
- 2026-06-08 live IDA MCP also rechecked [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md) at `0x0069b4d8`: eight xrefs across seven functions, including constructor writes at `0x00598731`/`0x00598738`, destructor clear at `0x0059886a`, explicit clear helper `0x00598c30`, scalar deleting destructor clear at `0x00598c80`, and MapPane-side packet helpers.

## Cross-References

- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:0000F3][TimerPane](by-class/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md)

## Changes

- 2026-06-08 Batch 141 parent-gate refresh:
  - Before: `COMPLETION:78`, `CONFIDENCE:88`, and no parent assignment.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:91`, and `AUTOGEN_PARENT_UID:0000F3`.
  - Summary/evidence: live IDA MCP rechecked TimerPane method boundaries, singleton xrefs, and the `0xcc` byte immediately after the scalar deleting destructor; the direct class parent [UID:0000F3][TimerPane](by-class/TimerPane.md) already clears `88/90`, so the layout now routes to the actual class owner.
- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing layout notes. Changed to `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor/configure/tick/draw/destructor field use and corrected the memory page reference to the last executable byte `0x00598cbe`. The score remains below final-source level because base-class inheritance names and final source split from `MapPane` remain open.
