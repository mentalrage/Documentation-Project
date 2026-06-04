*** UID:00006C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Confidence: strong for app helper placement, startup construction, method boundaries, vtable identity, singleton lifecycle, timer-handler scheduling, and padding; lower for final field names and timer callback naming.

## Methods

- `0x004cfe60` constructor - constructs the pane base, installs vtables, sets the singleton, initializes the active flag, and stores the timer interval/argument at `+0xfc`.
- `0x004cfec0` non-deleting destructor - restores `IdleWatcher` vtables, clears the singleton, and runs base `Pane` teardown.
- `0x004cfef0` timer reset/schedule helper - clears the active flag, removes timer state for the timer-handler subobject at `+0xa4`, then reschedules it with the stored interval at `+0xfc`.
- `0x004cff20` `Activate`/timer callback slot - sets the active flag and schedules a timer through the timer-handler subobject.
- `0x004cff37` and `0x004cff42` adjustor thunks - compiler/vtable thunks to the scalar deleting destructor.
- `0x004cff50` scalar deleting destructor - resets vtables, clears `g_pIdleWatcher`, destroys the base, and optionally frees memory.

## Touched State

| State or data | Evidence | Notes |
| --- | --- | --- |
| singleton pointer | constructor/destructor behavior in [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md) | Set during construction and cleared by the non-deleting and scalar deleting destructors. The global page is not yet split out, so keep the name provisional. |
| pane base/vtables | constructor, destructor, and [UID:00025H][0x0061b344-0x0061b664.HourIconsIdleReadOnlyData](by-memory/0x0061b344-0x0061b664.HourIconsIdleReadOnlyData.md) | Confirms this is a pane-derived class with a vtable island in the mixed UI `.rdata` range. |
| active/timer flag | `0x004cfef0`, `0x004cff20` | The reset helper clears the object active flag, removes/reschedules the timer-handler subobject, and the vtable callback sets the flag before scheduling work through the generic timer-handler wrapper. Exact field name remains open. |
| timer manager path | [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) | The scheduling callee is generic `TimerHandler`/`TimerMgr` code, so timer dependency does not move ownership out of `app/`. |

## Live IDA Evidence

- Checked on 2026-06-05 with live IDA MCP/disassembly.
- `lookup_funcs` confirms `0x004cfe60` size `0x5a`, `0x004cfec0` size `0x29`, `0x004cfef0` size `0x30`, `0x004cff20` size `0x17`, `0x004cff37` and `0x004cff42` size `0xb`, and `0x004cff50` size `0x5f`; `0x004cffaf` is not a function and is the following padding byte.
- IDA MCP shows the constructor is called from `Application::Startup` at `0x004f5ffe`.
- `0x004cfef0` has direct callers at `0x004a72f6` and `0x004a7490` in the application idle-work scheduler.
- Decorated RTTI/vtable names exist for `IdleWatcher` at primary vtable `0x0061b56c`, secondary vtable `0x0061b5b8`, and tertiary vtable `0x0061b5e8`. Constructor, non-deleting destructor, and scalar deleting destructor write all three vtable pointers.
- Vtable slots anchor the source methods: primary slot `0x0061b56c -> 0x004cff50`, secondary slot `0x0061b5b8 -> 0x004cff37`, tertiary destructor slot `0x0061b5e8 -> 0x004cff42`, and tertiary callback slot `0x0061b5ec -> 0x004cff20`.
- `xrefs_to 0x0069af1c` confirms constructor assignment at `0x004cfe85`, clears at `0x004cfeda` and `0x004cff70`, application idle reads at `0x004a72f0` and `0x004a748a`, and application shutdown/session reads at `0x004f6652` and `0x004f7679`.
- Constructor decompilation shows base `Pane` construction, singleton assignment, active flag initialization at `+0xf8`, interval/argument storage at `+0xfc`, and three `IdleWatcher` vtable stores.
- `0x004cfec0` decompiles as the non-deleting destructor: restore all three vtables, clear the singleton, and call base teardown.
- `0x004cfef0` decompiles as timer reset/schedule behavior: clear `+0xf8`, call `sub_597600(this + 0xa4)`, then call `sub_5975e0(this + 0xa4, 0, *(this + 0xfc), 0, 0)`.
- `0x004cff20` decompiles as the vtable callback/activation method: set the active flag and call `sub_5975e0` using the stored interval, returning `1`.
- Raw byte checks confirm `0x004cfeba-0x004cfec0`, `0x004cfee9-0x004cfef0`, and `0x004cffaf-0x004cffb0` are `0xcc` padding.
- [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md) records `Application::Startup` as the lifecycle context and lists `IdleWatcher` among startup singleton constructors rather than application-shell method bodies.
- [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md) now carries the projected path `NexusTK/app/`, matching [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md).
- [UID:00025H][0x0061b344-0x0061b664.HourIconsIdleReadOnlyData](by-memory/0x0061b344-0x0061b664.HourIconsIdleReadOnlyData.md) records the `IdleWatcher` vtable/read-only data island in the broader UI `.rdata` span.
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) documents the timer schedule wrapper as generic `TimerHandler` code with broad caller fan-in.

## Boundary And Padding Notes

- [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md) records the corrected exclusive end at `0x004cffaf`; byte `0x004cffae` is the final operand byte of the `retn 4`.
- [by-memory/-ignored.md](by-memory/-ignored.md) records `0x004cfe5f-0x004cfe60` as padding before the constructor and `0x004cffaf-0x004cffb0` as padding before `ImageLib`.
- The two adjustor thunk starts remain documented as compiler/vtable glue rather than additional source-owned logic.

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
- 2026-06-05 live IDA rescore:
  - Changed from: `COMPLETION:72`, `CONFIDENCE:80`, reconstructable/parent unset.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:0000K0`.
  - Reason for score increase: live IDA confirmed the previously omitted `0x004cfec0` non-deleting destructor and `0x004cfef0` timer reset/schedule helper, exact sizes for all local methods, constructor and idle-scheduler callers, three decorated `IdleWatcher` vtables, vtable slots for destructor thunks and callback/activation, singleton reads/writes at `0x0069af1c`, timer remove/schedule calls on the `+0xa4` subobject, stored interval field at `+0xfc`, active flag at `+0xf8`, and padding around the local functions. The score remains below final reconstruction because final source-facing field names and callback names are still inferred from behavior.
