*** UID:0000OU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TimerPane

## UID00029O Status-Layer Dependency - 2026-07-21

`TimerPane.cpp` retains its complete source inventory, resource mapping, class route, and generated order. The constructor consumes `g_pStatusPaneLayer` exactly once; the global is defined in MainUiGraph.cpp and is not owned here. All timer/display/digit drawing behavior, peer methods, teardown, scores, and unrelated evidence remain unchanged.

## Status

- Implemented score `90/91`; reconstruction path remains exactly `NexusTK/map/`, producing `NexusTK/map/TimerPane.cpp`.
- Primary source declaration: [UID:0000F3][TimerPane](by-class/TimerPane.md), now `91/93` with the exact class block.
- Aggregate: [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md), now `92/94` with twelve exact children.
- Historical `source-3/simroot_v2/class_TimerPane.cpp`, unresolved private-helper placement, and omitted-method generated wording are pre-callback states only.
- MapPane owns packet parsing/dispatch; TimerPane.cpp owns the class, eight source bodies, singleton definition, and source resource literals. No raw table or compiler wrapper is handwritten.

## File Role

`TimerPane` is the in-game timer/countdown overlay. Map/server packet handling creates or updates the pane, while the pane itself owns display formatting, per-second time state, 100 ms repaint scheduling, digit drawing, and active singleton teardown.

This is not part of the generic [UID:0000OT][TimerMgr](by-file/TimerMgr.md) scheduler. `TimerPane` consumes the timer callback interface through a secondary vtable/subobject, but its behavior is UI and game-session overlay logic.

## Source Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TimerPane` | [UID:0000F3][TimerPane](by-class/TimerPane.md) class plus [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md) split | Pane-only `0x120` class, eight exact source bodies, and four documented non-emitting compiler children. |
| [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md) | `0x0069b4d8` | Active timer-pane singleton. |
| [UID:0001WE][TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md) | exact class evidence | 288-byte Pane-derived layout; `+0x11c..+0x11f` is natural tail padding, not a member. |
| [UID:0001RQ][timerpane-number-resources](by-resource/timerpane-number-resources.md) | wide strings at `0x00670294` and `0x006702ac` | Digit and colon sprites used by `DrawDigit`. |

## Method Families

| Exact child | Source/compiler placement |
| --- | --- |
| [UID:0004MG][0x005986e0-0x00598841.TimerPaneConstructor](by-memory/0x005986e0-0x00598841.TimerPaneConstructor.md) | Source; early singleton publish, 2/5/8 geometry, status layer/render region, start time, 100 ms scheduling, and deliberate `m_endTime`/`m_displaySeconds` omissions. |
| [UID:0004MH][0x00598850-0x00598878.TimerPaneDestructor](by-memory/0x00598850-0x00598878.TimerPaneDestructor.md) | Source; clears singleton. Compiler/base teardown stays outside the body. |
| [UID:0004MI][0x00598880-0x005988f6.TimerPaneSetTimer](by-memory/0x00598880-0x005988f6.TimerPaneSetTimer.md) | Source; exact two-time-read/old-end update ordering before new end-time assignment. |
| [UID:0004MJ][0x00598900-0x00598959.TimerPaneOnTimer](by-memory/0x00598900-0x00598959.TimerPaneOnTimer.md) | Source TimerHandler bool override; reschedule or MarkForDeletion, always true. |
| [UID:0004MK][0x00598960-0x00598ae3.TimerPaneOnPaint](by-memory/0x00598960-0x00598ae3.TimerPaneOnPaint.md) | Source Pane paint override; unsigned 2/5/8 glyph fall-through with no default. |
| [UID:0004ML][0x00598af0-0x00598b3e.TimerPaneGetDisplaySizeRaw](by-memory/0x00598af0-0x00598b3e.TimerPaneGetDisplaySizeRaw.md) | Retained no-xref static source body, duplicated inline in constructor. |
| [UID:0004MM][0x00598b40-0x00598bd4.TimerPaneDrawDigit](by-memory/0x00598b40-0x00598bd4.TimerPaneDrawDigit.md) | Source member; NUMBER.EPF/EPD and direct sprite callback. |
| [UID:0004MN][0x00598be0-0x00598c2c.TimerPaneUpdateDisplaySecondsRaw](by-memory/0x00598be0-0x00598c2c.TimerPaneUpdateDisplaySecondsRaw.md) | Retained no-xref member source body, duplicated inline in SetTimer/OnPaint. |
| [UID:0004MO][0x00598c30-0x00598c3a.TimerPaneConstructorUnwindClearSingleton](by-memory/0x00598c30-0x00598c3a.TimerPaneConstructorUnwindClearSingleton.md), [UID:0004MP][0x00598c3b-0x00598c45.TimerPaneEventHandlerDestructorAdjustorThunk](by-memory/0x00598c3b-0x00598c45.TimerPaneEventHandlerDestructorAdjustorThunk.md), [UID:0004MQ][0x00598c46-0x00598c50.TimerPaneTimerHandlerDestructorAdjustorThunk](by-memory/0x00598c46-0x00598c50.TimerPaneTimerHandlerDestructorAdjustorThunk.md), [UID:0004MR][0x00598c60-0x00598cbe.TimerPaneScalarDeletingDestructor](by-memory/0x00598c60-0x00598cbe.TimerPaneScalarDeletingDestructor.md) | Compiler-only constructor unwind, two destructor adjustors, and deleting wrapper; exact blank formals, generated by source declarations. |

## Packet Ownership

`MapPane::HandlePacket` handles opcode `0x67` as the live map-session timer packet:

- payload byte `1` is the timer mode;
- payload dword at `+2` is the duration/value;
- mode `0` updates a static displayed value if a pane already exists;
- mode `1` is count-up behavior;
- mode `2` is countdown behavior;
- mode `3` marks the pane for deletion.

IDA also confirms an equivalent retained MapPane body at `0x005140a0` with constructor/SetTimer calls, no inbound caller xrefs, and no absolute/RVA pointer hit. It remains source-retained duplicate packet code with no active route, not a TimerPane child and not evidence for MapPane ownership of TimerPane methods.

## Boundary Notes

- `TimerPane` starts at `0x005986e0`, immediately after [UID:0000OT][TimerMgr](by-file/TimerMgr.md) ends at `0x005986da`.
- `0x00598cbe` is the final executable byte of the TimerPane scalar deleting destructor; `0x00598cbf` is padding, and `0x00598cc0` starts `TotemFrame`.
- Historical pre-callback generated output omitted source spans, included a polluted `TextButtonExControlPane::~Pane` label, and marked an adjustor missing. The exact source/compiler split supersedes those artifacts; base teardown remains compiler/base behavior.
- Nine parent-only alignment spans stay on UID0001KB. `0x00598cbf` is the single excluded successor pad and `0x00598cc0` starts TotemFrame.
- Raw vtables, exact storage, pooled strings, layout evidence, EH funclet, adjustor thunks, and deleting wrapper are covered by declarations and remain non-emitting.

## Cross-References

- [UID:0000F3][TimerPane](by-class/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md)
- [UID:0001WE][TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md)
- [UID:0001RQ][timerpane-number-resources](by-resource/timerpane-number-resources.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)
- [UID:0004MG][0x005986e0-0x00598841.TimerPaneConstructor](by-memory/0x005986e0-0x00598841.TimerPaneConstructor.md)
- [UID:0004MI][0x00598880-0x005988f6.TimerPaneSetTimer](by-memory/0x00598880-0x005988f6.TimerPaneSetTimer.md)
- [UID:0004MJ][0x00598900-0x00598959.TimerPaneOnTimer](by-memory/0x00598900-0x00598959.TimerPaneOnTimer.md)
- [UID:0004MK][0x00598960-0x00598ae3.TimerPaneOnPaint](by-memory/0x00598960-0x00598ae3.TimerPaneOnPaint.md)
- [UID:0004ML][0x00598af0-0x00598b3e.TimerPaneGetDisplaySizeRaw](by-memory/0x00598af0-0x00598b3e.TimerPaneGetDisplaySizeRaw.md)
- [UID:0004MM][0x00598b40-0x00598bd4.TimerPaneDrawDigit](by-memory/0x00598b40-0x00598bd4.TimerPaneDrawDigit.md)
- [UID:0004MN][0x00598be0-0x00598c2c.TimerPaneUpdateDisplaySecondsRaw](by-memory/0x00598be0-0x00598c2c.TimerPaneUpdateDisplaySecondsRaw.md)

## Changes

- 2026-07-13 B003 UID0001KB callback:
  - Raised `87/86 -> 90/91` and preserved the exact `NexusTK/map/` route.
  - Replaced the unresolved aggregate inventory with class/global plus eight source and four compiler-child coverage, preserved both retained no-route/no-xref source bodies, and separated MapPane opcode parsing from TimerPane method ownership.
  - Historicalized stale omitted-method/generated-source placement, preserved exact range/padding/successor/resource/global/vtable history, and documented that declarations generate compiler tables/wrappers without manual emission.

- 2026-06-07 Batch 058 parent-chain repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:80`; [UID:0000F3][TimerPane](by-class/TimerPane.md) could not route children through this file because the file parent was below the corrected 85/85 gate.
  - After: `COMPLETION:87`, `CONFIDENCE:86`.
  - Evidence: reconciled the file page with the current [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md), including exact final byte `0x00598cbe`, singleton/resource anchors, omitted generated methods, and MapPane packet ownership. Final source split from the related packet helper remains open, so the score stays below high-confidence final-source level.
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
