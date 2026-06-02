*** UID:00006C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IdleWatcher

## Summary

`IdleWatcher` is a small pane-derived singleton that watches idle state and schedules timer callbacks. It is created during `Application::Startup` and stores itself in `g_pIdleWatcher`.

## Likely Original Placement

- Source: [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md), projected as `NexusTK/app/IdleWatcher.cpp`.
- Caller context: [UID:0000HG][Application](by-file/Application.md) constructs the singleton from `Application::Startup`, but current source-structure docs keep `IdleWatcher` separate from `Application.cpp`.
- Confidence: medium-high for app helper placement; lower for final field names and timer callback naming.

## Methods

- `0x004cfe60` constructor - constructs the pane base, installs vtables, and sets `g_pIdleWatcher`.
- `0x004cff20` `Activate` - sets the active flag and schedules a timer.
- `0x004cff37` adjustor thunk, disabled in current active partition.
- `0x004cff42` scalar-deleting destructor adjustor thunk, disabled in current active partition.
- `0x004cff50` scalar deleting destructor - resets vtables, clears `g_pIdleWatcher`, destroys the base, and optionally frees memory.

## Touched State

| State or data | Evidence | Notes |
| --- | --- | --- |
| singleton pointer | constructor/destructor behavior in [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md) | Set during construction and cleared by the scalar deleting destructor. The global page is not yet split out, so keep the name provisional. |
| pane base/vtables | constructor, destructor, and [UID:00025H][0x0061b344-0x0061b664.HourIconsIdleReadOnlyData](by-memory/0x0061b344-0x0061b664.HourIconsIdleReadOnlyData.md) | Confirms this is a pane-derived class with a vtable island in the mixed UI `.rdata` range. |
| active/timer flag | `0x004cff20` | `Activate` marks the object active and schedules work through the generic timer-handler wrapper. Exact field name remains open. |
| timer manager path | [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) | The scheduling callee is generic `TimerHandler`/`TimerMgr` code, so timer dependency does not move ownership out of `app/`. |

## Evidence

- Wave3 reports three active methods and two disabled thunk methods.
- IDA MCP confirms constructor `0x004cfe60-0x004cfeba`, `Activate` `0x004cff20-0x004cff37`, and scalar deleting destructor `0x004cff50-0x004cffaf`.
- IDA MCP shows the constructor is called from `Application::Startup` at `0x004f5ffe`.
- [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md) records `Application::Startup` as the lifecycle context and lists `IdleWatcher` among startup singleton constructors rather than application-shell method bodies.
- [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md) now carries the projected path `NexusTK/app/`, matching [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md).
- [UID:00025H][0x0061b344-0x0061b664.HourIconsIdleReadOnlyData](by-memory/0x0061b344-0x0061b664.HourIconsIdleReadOnlyData.md) records the `IdleWatcher` vtable/read-only data island in the broader UI `.rdata` span.
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) documents the timer schedule wrapper as generic `TimerHandler` code with broad caller fan-in.

## Boundary And Padding Notes

- [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md) records the corrected exclusive end at `0x004cffaf`; byte `0x004cffae` is the final operand byte of the `retn 4`.
- [by-memory/-ignored.md](by-memory/-ignored.md) records `0x004cfe5f-0x004cfe60` as padding before the constructor and `0x004cffaf-0x004cffb0` as padding before `ImageLib`.
- The two adjustor thunk starts remain documented but disabled in the current active partition, so they are evidence for compiler/vtable glue rather than additional source-owned logic.

## Open Questions

- Determine final source-quality names for the active flag, singleton global, and timer event arguments.
- Decide whether later original-source evidence folds this tiny helper into `Application.cpp`; current docs prefer `app/IdleWatcher.cpp`.
- Keep reconstructed C++ blank until the class layout and timer callback names reach final-source quality.

## Cross-References

- File: [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md)
- Caller/module context: [UID:0000HG][Application](by-file/Application.md)
- Related classes: [UID:00000D][Application](by-class/Application.md), [UID:0000A2][Pane](by-class/Pane.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- Memory: [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md), [UID:00025H][0x0061b344-0x0061b664.HourIconsIdleReadOnlyData](by-memory/0x0061b344-0x0061b664.HourIconsIdleReadOnlyData.md), [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- Source structure: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `66/74`. Summary: singleton purpose, startup construction, method list, IDA-confirmed boundaries, and open timer/source-placement questions are documented, but the page is still a compact summary and timer callback semantics remain unresolved. Evidence: `0x004cfe60-0x004cffaf.IdleWatcher`, Application startup caller, Pane/EventDispatcher relationships, and open `0x005975e0` timer target.
- 2026-06-02 documentation expansion:
  - What existed before: the page was a compact summary scored `66/74`, with unresolved source placement and timer-target wording.
  - Changed to: scores `72/80`, app helper placement through [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md), touched-state table, vtable/read-only data evidence, timer-wrapper dependency evidence, and boundary/padding notes.
  - Summary/evidence: existing IDA-backed pages confirm startup construction, corrected function end, adjacent padding, generic timer-handler scheduling, and `IdleWatcher` vtable data. `RECONSTRUCTABLE` and C++ remain blank because the class declaration, field names, and timer event names are not final-source quality.
