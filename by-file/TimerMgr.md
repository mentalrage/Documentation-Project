*** UID:0000OT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TimerMgr

## Status

- Proposed module: `util/TimerMgr.cpp`
- Proposed header: `util/TimerMgr.h`
- Confidence: strong for `TimerMgr` plus `TimerMgrTimerQueue`; medium for folding `TimerHandler` and wrapper thunks into the same source file.
- Current recovered sources: `class_TimerMgr.cpp`, `class_TimerMgrTimerQueue.cpp`, `class_TimerHandler.cpp`
- Evidence basis: Wave2 import source filenames, active `simroot_v2` output, and IDA MCP boundary/caller checks on 2026-05-24.

## File Role

`TimerMgr.cpp` owns the client-side timer scheduler. It keeps a singleton pointer in [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md), stores a static process-wide `TimerMgr` instance at `0x0069b3ac`, initializes multimedia timer resolution through `timeGetDevCaps`/`timeBeginPeriod`, mirrors current tick values into globals, and maintains a sorted ring queue of scheduled timer events.

The queue is not a generic container. It stores [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md) records sorted by due tick and dispatches them through the owner's `TimerHandler` virtual callback.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000F0][TimerHandler](by-class/TimerHandler.md) | `0x00597570-0x005976b3` | Base class for timer callback owners plus thin helpers around the global manager; exact wrapper pages cover [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md), [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md), and [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md). |
| [UID:0000F1][TimerMgr](by-class/TimerMgr.md) | `0x005976c0-0x00597eaa`, `0x00598090-0x005986da` | Singleton scheduler, multimedia timer setup, dispatch, cancellation, and queue mutation. The queue-helper tail is mapped at [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md). |
| [UID:0000F2][TimerMgrTimerQueue](by-class/TimerMgrTimerQueue.md) | `0x00597fe0-0x00598083` plus queue helpers | Embedded ring queue for scheduled timer records. |
| [UID:0002KX][0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick.md) | `0x00597dc0-0x00597e3e` | Scans queued events for an owner/event pair and returns its due tick. |
| [UID:0002L0][0x00597eb0-0x00597f16.TimerQueueReverseRange](by-memory/0x00597eb0-0x00597f16.TimerQueueReverseRange.md) | `0x00597eb0-0x00597f16` | Reverses queue slots; called only by rotate helper. |
| [UID:0002L1][0x00597f20-0x00597fc8.TimerQueueRotateRange](by-memory/0x00597f20-0x00597fc8.TimerQueueRotateRange.md) | `0x00597f20-0x00597fc8` | Rotate helper used by `InsertTimer`. |
| [UID:0002L5][0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity](by-memory/0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity.md) | `0x005980f0-0x00598281` | Reallocates/grows the slot-entry array with MSVC aligned-allocation handling. |
| timer globals | `0x0067ab80`, `0x0069b3ac`, `0x0069be0c`, `0x0069be10` | Singleton pointer, static instance, and tick mirrors. |

## Evidence Notes

- `TimerMgr` and `TimerMgrTimerQueue` both report `TimerMgr.cpp` as import/source provenance in generated metadata.
- `TimerHandler` reports `TimerHandler.cpp`, but IDA places its constructor/destructor/default-callback/wrapper functions immediately before `TimerMgr`; caller evidence shows the wrappers forward to `g_pTimerMgr`.
- IDA confirms the compact cluster from `0x00597570` through `0x005986da`, ending before `TimerPane` at `0x005986e0`.
- 2026-05-31 IDA MCP split pass confirmed exact queue-helper children inside [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md), including timer-period/tick helpers, queue reverse/rotate, clear, destructor, grow, splice, and insert pages.
- `TimerMgr::ScheduleTimer` has broad caller fan-in from UI, object, map, and application systems. That supports a utility scheduler module rather than feature-local timer ownership.
- `TimerMgr::DispatchDueTimers` is called by the application helper/message-loop path at `0x004a6c40`, after the timer resolution setup call.

## Generated Output Caveats

- Active `class_TimerHandler.cpp` omits the non-deleting destructor body at `0x00597580`, the default timer callback at `0x005975d0`, and wrapper helpers at `0x005975e0`, `0x00597600`, `0x00597610`, and `0x00597630`.
- IDA decompiles the `0x00597580` non-deleting destructor with a `boost::exception` type label, but its body installs the `TimerHandler` vtable and unregisters from `g_pTimerMgr`.
- `0x00597580` was previously documented as an `EventDispatcher` destructor and `0x00597600` as an `InterfaceEfx` removal helper. IDA body checks resolve both as generic `TimerHandler` cleanup/wrapper code.
- Active `class_TimerMgr.cpp` omits queue-local helpers at `0x00597dc0`, `0x00597eb0`, `0x00597f20`, and `0x005980f0`.
- Active `class_TimerMgrTimerQueue.cpp` only emits the destructor at `0x00597fe0`, even though its insert/remove/grow helpers are emitted under `TimerMgr` or omitted.
- The exact queue-helper page records IDA evidence for `FindQueuedTimerDueTick`, timer-period setup, current-tick refresh, queue reverse/rotate, capacity grow, splice, and insert behavior.
- IDA names `0x00597780` as `sub_60C270`, but the instruction addresses and behavior are the static `TimerMgr` destructor body for the instance at `0x0069b3ac`.

## Source-Structure Decision

Preserve `TimerMgr`, `TimerMgrTimerQueue`, the timer queue helper functions, and probably `TimerHandler` in one timer scheduler module. If a future original-source clue proves a separate `TimerHandler.cpp`, keep it as a tiny companion source with `TimerMgr.h` owning the shared declarations.

## Cross-References

- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0000F2][TimerMgrTimerQueue](by-class/TimerMgrTimerQueue.md)
- [UID:0000F0][TimerHandler](by-class/TimerHandler.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md)
- [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md)
- [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md)
- [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)
- [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document covers timer scheduler role, contents, TimerHandler/TimerQueue relation, queue helper functions, static/global data, IDA evidence, generated-output caveats, source-structure decision, and cross-references; confidence is capped by final TimerHandler split.
- 2026-05-31: Assigned projected reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: set path to `NexusTK/util/`.
  - Evidence: the page already documents `util/TimerMgr.cpp` as the working module, and the 2026-05-31 IDA MCP recheck reconfirmed the `g_pTimerMgr` storage at `0x0067ab80`, broad timer xrefs, the constructor at `0x005976c0`, and application dispatch use around `0x004a6c40`.
- 2026-05-31: Replaced plain queue-helper rows with exact by-memory child references.
  - Before: `FindQueuedTimerDueTick`, `ReverseTimerQueueRange`, `RotateTimerQueueRange`, and `EnsureTimerQueueCapacity` were listed as plain address rows with broad/inclusive-end drift.
  - After: rows link to exact IDA-verified child pages under [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md).
  - Evidence: IDA MCP `lookup_funcs`, `callers`, and byte-padding checks confirmed the exact function ranges and helper relationships.
