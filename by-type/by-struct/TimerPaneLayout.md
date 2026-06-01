*** UID:0001WE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TimerPaneLayout

## Status

- Type kind: inferred class/layout support.
- Likely owner: [UID:0000OU][TimerPane](by-file/TimerPane.md)
- Confidence: medium-high for the documented offsets; field names are behavior-backed, but base-class inheritance names need final reconciliation.

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

## Cross-References

- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:0000F3][TimerPane](by-class/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md)

## Changes

- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing layout notes. Changed to `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor/configure/tick/draw/destructor field use and corrected the memory page reference to the last executable byte `0x00598cbe`. The score remains below final-source level because base-class inheritance names and final source split from `MapPane` remain open.
