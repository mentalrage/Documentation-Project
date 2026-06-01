*** UID:0000OU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TimerPane

## Status

- Confidence: strong for class behavior and boundaries; medium for final file split.
- Proposed module: `map/TimerPane.cpp`, or a private helper beside [UID:0000L3][MapPane](by-file/MapPane.md)
- Current generated source: `source-3/simroot_v2/class_TimerPane.cpp`
- Primary class doc: [UID:0000F3][TimerPane](by-class/TimerPane.md)
- Main address doc: [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)

## File Role

`TimerPane` is the in-game timer/countdown overlay. Map/server packet handling creates or updates the pane, while the pane itself owns display formatting, per-second time state, 100 ms repaint scheduling, digit drawing, and active singleton teardown.

This is not part of the generic [UID:0000OT][TimerMgr](by-file/TimerMgr.md) scheduler. `TimerPane` consumes the timer callback interface through a secondary vtable/subobject, but its behavior is UI and game-session overlay logic.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TimerPane` | `0x005986e0-0x00598cbe` | Pane construction, timer configuration, timer callback, draw path, digit rendering, and destructors. |
| [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md) | `0x0069b4d8` | Active timer-pane singleton. |
| [UID:0001WE][TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md) | layout evidence from IDA offsets | 288-byte pane with secondary vtables and time/display fields. |
| [UID:0001RQ][timerpane-number-resources](by-resource/timerpane-number-resources.md) | wide strings at `0x00670294` and `0x006702ac` | Digit and colon sprites used by `DrawDigit`. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction and bounds | `0x005986e0` | Creates the pane, stores the singleton, chooses 2/5/8 digit slots, sets bounds, and schedules the first repaint. |
| Timer configuration | `0x00598880` | Sets mode, duration/display seconds, start time, and expiration time. Active generated output currently omits this function. |
| Timer callback | `0x00598900` | Called through the subobject at `this + 0xa4`; destroys the pane when expired or invalidates/reschedules it. |
| Painting | `0x00598960`, `0x00598b40` | Computes elapsed/remaining seconds and draws `SS`, `MM:SS`, or `HH:MM:SS` using `NUMBER.EPF`/`NUMBER.EPD`. |
| Teardown helpers | `0x00598850`, `0x00598c30`, `0x00598c3b`, `0x00598c46`, `0x00598c60` | Non-deleting cleanup, singleton clear helper, adjustor thunks, and scalar deleting destructor. |

## Packet Ownership

`MapPane::HandlePacket` handles opcode `0x67` as the live map-session timer packet:

- payload byte `1` is the timer mode;
- payload dword at `+2` is the duration/value;
- mode `0` updates a static displayed value if a pane already exists;
- mode `1` is count-up behavior;
- mode `2` is countdown behavior;
- mode `3` marks the pane for deletion.

IDA also confirms an equivalent helper at `0x005140a0` with constructor/configuration calls into `TimerPane`, but it currently has no direct caller xrefs in IDA. Treat it as related packet-handler code until the dispatch table is decoded.

## Boundary Notes

- `TimerPane` starts at `0x005986e0`, immediately after [UID:0000OT][TimerMgr](by-file/TimerMgr.md) ends at `0x005986da`.
- `0x00598cc0` starts `TotemFrame`; do not extend `TimerPane` past `0x00598cbf`.
- Active generated output omits `0x00598850`, `0x00598880`, and `0x00598c30`; disabled output includes only one destructor thunk and marks the other as missing.
- The generated destructor label `TextButtonExControlPane::~Pane` is likely base-owner pollution. IDA shows cleanup through the shared pane teardown helper at `0x00544580`.

## Cross-References

- [UID:0000F3][TimerPane](by-class/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md)
- [UID:0001WE][TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md)
- [UID:0001RQ][timerpane-number-resources](by-resource/timerpane-number-resources.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document captures in-game timer overlay role, proposed contents, method families, packet ownership, boundaries, generated-output omissions, layout/resource refs, and cross-references; confidence remains capped by final map/private-helper source split.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `TimerPane.cpp` under `map`; IDA MCP confirms `g_pTimerPane` lifecycle and MapPane/session reads, while exact split from MapPane remains provisional.
- 2026-05-31: Corrected the main memory range to end on the final executable byte.
  - Before: references used `0x005986e0-0x00598cbf`.
  - After: references use [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md).
  - Evidence: IDA MCP reports `TimerPane::ScalarDeletingDestructor` at `0x00598c60` with size `0x5f`, so `0x00598cbe` is the final executable byte and `0x00598cbf` is padding before `TotemFrame`.
