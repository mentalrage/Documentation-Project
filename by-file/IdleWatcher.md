*** UID:0000K0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# IdleWatcher

## Status

- Confidence: strong for behavior, anchors, app helper placement, startup construction, singleton lifecycle, vtable identity, and timer-handler scheduling; medium-high for private-in-`Application.cpp` still being unproven.
- Proposed module: `NexusTK/app/IdleWatcher.cpp`.
- Current materialization: documentation-only; final C++ remains intentionally blank until field and callback names are final-source quality.
- Primary class doc: [UID:00006C][IdleWatcher](by-class/IdleWatcher.md)
- Main address doc: [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md)

## File Role

`IdleWatcher` is a small `Pane`-derived singleton created from `Application::Startup`. It stores `g_pIdleWatcher`, schedules idle/timer callbacks, and tears itself down through pane/base destruction.

The class is startup-owned, but it should not be absorbed into [UID:0000HG][Application](by-file/Application.md) unless the original source is proven to have kept singleton helper classes in the application file. Its behavior is a separate timer/idle pane helper.

[UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places this module under `NexusTK/app/` with `ChangeMan`, `MiscWorkThread`, and `MSGHandler`: small helpers with direct application lifecycle/dispatch relationships that are not the broad application shell itself.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `IdleWatcher` | `0x004cfe60-0x004cffaf` | Startup-created idle/timer watcher singleton. |
| timer reset/schedule helper | `0x004cfef0-0x004cff1f` | Called by the application idle-work scheduler; clears active state and reschedules the timer-handler subobject. |
| adjustor thunks | `0x004cff37-0x004cff4d` | Compiler/vtable thunks forwarding to the scalar deleting destructor. |
| vtable/read-only data | inside [UID:00025H][0x0061b344-0x0061b664.HourIconsIdleReadOnlyData](by-memory/0x0061b344-0x0061b664.HourIconsIdleReadOnlyData.md) | Mixed UI `.rdata` range containing the `IdleWatcher` vtable island, followed later by `ImageLib` RTTI/vtable data. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction | `0x004cfe60` | Constructs pane base, installs vtables, and sets `g_pIdleWatcher`. |
| Timer reset/schedule | `0x004cfef0` | Clears the active flag, removes timer state for `this + 0xa4`, and schedules the next idle timer with the stored interval at `+0xfc`. |
| Activation/timer callback | `0x004cff20` | Marks the watcher active and schedules timer callback work. |
| Destruction | `0x004cfec0`, `0x004cff37`, `0x004cff42`, `0x004cff50` | Non-deleting destructor plus two adjustor thunks and scalar deleting destructor. |

## Boundary Notes

- 2026-06-05 live IDA confirms exact starts at `0x004cfe60`, `0x004cfec0`, `0x004cfef0`, `0x004cff20`, `0x004cff37`, `0x004cff42`, and `0x004cff50`.
- [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md) records `Application::Startup` calling the `IdleWatcher` constructor at `0x004f5ffe`.
- Live IDA confirms `0x004cfef0` is called from application idle-work scheduler sites `0x004a72f6` and `0x004a7490`.
- Live IDA confirms decorated `IdleWatcher` vtables at `0x0061b56c`, `0x0061b5b8`, and `0x0061b5e8`, with callback slot `0x0061b5ec -> 0x004cff20` and destructor/thunk slots at `0x0061b56c`, `0x0061b5b8`, and `0x0061b5e8`.
- `xrefs_to 0x0069af1c` confirms singleton assignment/clears and application idle/shutdown readers.
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) documents the schedule wrapper used by many timer clients; this supports `IdleWatcher` as a timer-handler consumer, not as generic timer-manager ownership.
- [UID:00025H][0x0061b344-0x0061b664.HourIconsIdleReadOnlyData](by-memory/0x0061b344-0x0061b664.HourIconsIdleReadOnlyData.md) records the mixed UI read-only span that includes `IdleWatcher` vtable data and nearby `ImageLib` vtable tail.
- `list missing-ref --class IdleWatcher` returns zero entries.

## Cross-References

- [UID:00006C][IdleWatcher](by-class/IdleWatcher.md)
- [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
  - Summary/evidence: startup-created pane singleton role, construction/timer/destruction anchors, boundary notes, and neighboring app/event/timer dependencies are documented; completion is lower because the file is small and lacks deeper raw-code/source-form detail for the timer callback behavior.
- 2026-06-02 projected path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page described `app/IdleWatcher.cpp` as only one of several possible final placements.
  - Changed to: `NexusTK/app/`, with `app/IdleWatcher.cpp` as the working module while preserving the private-in-`Application.cpp` caveat.
  - Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) explicitly places `IdleWatcher.cpp` under `app/`; [UID:0000HG][Application](by-file/Application.md) documents startup construction and also says not to absorb `IdleWatcher` into `Application.cpp` without later source evidence.
- 2026-06-05 live IDA rescore:
  - Changed from: `COMPLETION:82`, `CONFIDENCE:80`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`.
  - Reason for score increase: live IDA confirmed the omitted non-deleting destructor and timer reset/schedule helper, application idle-scheduler callers, three `IdleWatcher` vtables, callback/destructor slots, singleton lifecycle xrefs, active flag and interval offsets, timer remove/schedule behavior, and local padding. The score remains below final reconstruction because original field names, callback names, and private-in-`Application.cpp` versus standalone source shape are still not proven.
