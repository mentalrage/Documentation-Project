*** UID:0000K0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# IdleWatcher

## Status

- Confidence: very strong for standalone placement, complete source order, class/global/method routes, layout, singleton lifecycle, TimerHandler behavior, and compiler exclusions. Exact private spelling/header organization remains inferred.
- Proposed module: `NexusTK/app/IdleWatcher.cpp`.
- Current materialization: source-ready through class/global/exact method emitters. This by-file page owns ordering/routing and does not itself carry a C++ block.
- Primary class doc: [UID:00006C][IdleWatcher](by-class/IdleWatcher.md)
- Main address doc: [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md)

## File Role

`IdleWatcher` is a `0x100`-byte `Pane`/`Singleton<IdleWatcher>` helper created from `Application::Startup`. It owns zero-initialized `g_pIdleWatcher`, resets idle state on pointer/key activity, handles periodic TimerHandler expiry, and relies on normal base/compiler destruction for Singleton clear, Pane teardown, adjustors, and scalar deletion.

The standalone placement is accepted rather than provisional. [UID:0000HG][Application](by-file/Application.md) owns allocation/construction and shutdown deletion callsites, but its current documentation explicitly excludes `IdleWatcher` absorption; dedicated class, global, RTTI/vtables, fields, and timer behavior form this narrow file.

[UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places this module under `NexusTK/app/` with `ChangeMan`, `MiscWorkThread`, and `MSGHandler`: small helpers with direct application lifecycle/dispatch relationships that are not the broad application shell itself.

## Exact Generated Source Order

| Position | Entity | Source role |
| ---: | --- | --- |
| `10` | [UID:00006C][IdleWatcher](by-class/IdleWatcher.md) | Complete `Pane, Singleton<IdleWatcher>` declaration, inline `IsIdle`, fields, virtuals, and `[[CHILDREN]]`. |
| `20` | [UID:0002VY][0x0069af1c-0x0069af20.g_pIdleWatcher](by-memory/0x0069af1c-0x0069af20.g_pIdleWatcher.md) | `IdleWatcher *g_pIdleWatcher = 0;`. |
| `30` | [UID:0004LE][0x004cfe60-0x004cfeba.IdleWatcherConstructor](by-memory/0x004cfe60-0x004cfeba.IdleWatcherConstructor.md) | `Pane(4)`, Singleton base, initial idle true, interval member. |
| `40` | [UID:0004LF][0x004cfec0-0x004cfee9.IdleWatcherDestructor](by-memory/0x004cfec0-0x004cfee9.IdleWatcherDestructor.md) | Empty authored body; implicit base teardown. |
| `50` | [UID:0004LG][0x004cfef0-0x004cff20.IdleWatcherResetIdleTimer](by-memory/0x004cfef0-0x004cff20.IdleWatcherResetIdleTimer.md) | User-activity state clear/remove/restart. |
| `60` | [UID:0004LH][0x004cff20-0x004cff37.IdleWatcherOnTimer](by-memory/0x004cff20-0x004cff37.IdleWatcherOnTimer.md) | Timer expiry state set/rearm/true return. |

Compiler-generated and deliberately excluded from source emission: [UID:0004LI][0x004cff37-0x004cff4d.IdleWatcherDestructorAdjustorThunks](by-memory/0x004cff37-0x004cff4d.IdleWatcherDestructorAdjustorThunks.md), [UID:0004LJ][0x004cff50-0x004cffaf.IdleWatcherScalarDeletingDestructor](by-memory/0x004cff50-0x004cffaf.IdleWatcherScalarDeletingDestructor.md), and [UID:0003BP][0x0061b568-0x0061b640.IdleWatcherVtableData](by-memory/0x0061b568-0x0061b640.IdleWatcherVtableData.md). UID000171 is only the non-emitting split index.

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction | `0x004cfe60` | Allocated as `0x100`, receives initial interval 20000, builds Pane kind 4 and Singleton, starts idle. |
| Activity reset | `0x004cfef0` | Clears `m_isIdle`, removes pending timers for inherited TimerHandler `+0xa4`, schedules ID 0/interval/zero/zero. |
| Timer callback | `0x004cff20` | TimerHandler `OnTimer`: sets idle, rearms ID 0/interval/zero/zero, returns true. |
| State read | inline class source | `IsIdle() const` explains MainMenu's direct `+0xf8` load without an out-of-line body. |
| Destruction | `0x004cfec0` source plus compiler children | Empty ordinary destructor; Singleton clear, Pane teardown, adjustors, flags, guarded size, and delete are implicit/compiler-generated. |

## Layout, Lifecycle, And Ownership

- Complete layout: Pane primary `+0`, EventHandler `+0xa0`, TimerHandler `+0xa4`, empty Singleton base plus private bool `m_isIdle` `+0xf8`, natural alignment `+0xf9-+0xfb`, unsigned interval `+0xfc`, total `0x100`.
- `g_pIdleWatcher` has exactly seven meaningful refs: constructor publication, ordinary/scalar clears, two EventDispatcher activity reads, Application shutdown read, and MainMenu state read.
- Consumer refs do not move ownership: EventDispatcher invokes reset, MainMenu reads inline state, TimerMgr implements generic wrappers, and Application owns lifecycle callsites.
- No duplicate by-global page, `Application.cpp` fold, manual vtable/RTTI table, manual singleton assignment/clear, explicit padding field, or compiler-wrapper source is accepted.

## Boundary Notes

- 2026-07-13 live session `c81909be` reconfirmed exact starts/ranges, all internal `0xcc` pads, layout/RTTI, three vtable views, callers, global refs, and source/compiler dispositions.
- [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md) records `Application::Startup` calling the `IdleWatcher` constructor at `0x004f5ffe`.
- Live IDA confirms `0x004cfef0` is called from EventDispatcher route sites `0x004a72f6` after pointer activity and `0x004a7490` after key/text activity.
- Live IDA confirms decorated `IdleWatcher` vtables at `0x0061b56c`, `0x0061b5b8`, and `0x0061b5e8`, with callback slot `0x0061b5ec -> 0x004cff20` and destructor/thunk slots at `0x0061b56c`, `0x0061b5b8`, and `0x0061b5e8`.
- `xrefs_to 0x0069af1c` confirms singleton assignment/clears and application idle/shutdown readers.
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) documents the schedule wrapper used by many timer clients; this supports `IdleWatcher` as a timer-handler consumer, not as generic timer-manager ownership.
- [UID:00025H][0x0061b340-0x0061b660.HourIconsIdleReadOnlyData](by-memory/0x0061b340-0x0061b660.HourIconsIdleReadOnlyData.md) records the mixed UI read-only span that includes `IdleWatcher` vtable data and nearby `ImageLib` vtable tail.
- `list missing-ref --class IdleWatcher` returns zero entries.
- Internal padding is exact at `0x004cfeba-0x004cfec0`, `0x004cfee9-0x004cfef0`, and `0x004cff4d-0x004cff50`; outer predecessor/successor pads remain unchanged.

## Cross-References

- [UID:00006C][IdleWatcher](by-class/IdleWatcher.md)
- [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-07-13 B001 Gate-1-accepted source-file implementation:
  - Changed from `86/88`, documentation-only/provisional placement, aggregate method inventory, `Activate`/active-state wording, and unresolved field/callback/source shape.
  - Changed to `91/93`, source-ready standalone `NexusTK/app/IdleWatcher.cpp`, exact positions 10/20/30/40/50/60, six real source routes, full layout/lifecycle, and explicit aggregate/compiler/vtable exclusions.
  - Preserved startup/shutdown caller evidence while superseding private-in-Application, manual-global, active-polarity, and handwritten compiler-glue assumptions.

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
