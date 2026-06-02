*** UID:00000E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ApplicationHelper_4A6C40

## Summary

`ApplicationHelper_4A6C40` is a projected helper owner for message-loop idle work. It captures a timer baseline and processes queued idle-side work between batches of Win32 messages, including draining the [UID:00000W][BlackHole](by-class/BlackHole.md) deferred deletion queue, dispatching timers, rebuilding event traversal state, and dispatching frame callbacks.

This page is a documentation wrapper for the generated owner label, not a proven original C++ class. The concrete children are documented as UI-core scheduler helpers attached to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), with call sites from [UID:0000HG][Application](by-file/Application.md).

## Likely Original Placement

- Source: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Proposed path: `ui/core/EventDispatcher.cpp` or a small `ui/core/MessageLoopScheduler.cpp`
- Confidence: medium

## Methods

- `0x004a6c40-0x004a6cda` `ProcessIdleWork` - drains [UID:00000W][BlackHole](by-class/BlackHole.md), performs timer updates, traversal rebuild, and tick-slice advancement.
- `0x004a7120-0x004a712b` `CaptureCurrentTickBaseline` - captures the current timer tick before the message loop waits.

## Child Evidence Matrix

| Child | Score | Parent/source placement | Evidence status |
| --- | ---: | --- | --- |
| [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md) | `82/86` | [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) | Exact range, two `Application::RunMessageLoop` callers, cleanup/timer/traversal/frame callee chain, static flag behavior, and elapsed-slice math are documented. |
| [UID:000143][0x004a7120-0x004a712b.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712b.ApplicationIdleTickBaseline.md) | `78/86` | [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) | Exact `0x0c` range, single `Application::RunMessageLoop` caller, no-callee direct tick snapshot, and helper offset `+0x2c` write are documented. |
| [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md) | `78/86` | [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) | Initial flag byte, exact read/write xrefs inside `0x004a6c40`, timer-refresh gate, clear/write site, and padding boundary before `0x0066d888` are documented. |

## Scheduler Flow

| Phase | Evidence |
| --- | --- |
| Message-loop entry baseline | `Application::RunMessageLoop` calls `0x004a7120`; that helper snapshots the current timer tick into helper offset `+0x2c`. |
| Idle work wakeup | `Application::RunMessageLoop` calls `0x004a6c40` at two wake/idle call sites. |
| Deferred cleanup | `0x004a6c40` first drains [UID:0000HR][BlackHole](by-file/BlackHole.md) through [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md). |
| Timer dispatch | The idle worker calls timer-period/dispatch helpers and uses [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md). |
| Dispatcher maintenance | The idle worker calls the EventDispatcher traversal rebuild path on the helper's dispatcher-adjacent state. |
| Frame callbacks | Changed elapsed slices dispatch through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) and [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md). |

## Source-Structure Decision

Keep `ApplicationHelper_4A6C40` as a generated grouping name. The behavior is well documented, but original-source placement should be either:

- a file-local helper inside [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), or
- a small `ui/core/MessageLoopScheduler.cpp` companion if future source-line evidence proves a separate module.

Do not emit or preserve `ApplicationHelper_4A6C40.cpp` as a final source file name.

## Evidence

- Wave3 notes a queue-state subobject at `+0x4` and tick/slice fields at `+0x2c` and `+0x30`.
- IDA MCP confirms `ProcessIdleWork` at `0x004a6c40-0x004a6cda` and shows it is called from `Application::RunMessageLoop` at `0x00464df7` and `0x00464e0e`.
- IDA decompilation shows `ProcessIdleWork` begins by calling `BlackHole::ReleaseQueuedOwnedObjects(dword_67A74C)`.
- IDA MCP confirms `CaptureCurrentTickBaseline` at `0x004a7120-0x004a712b`.
- IDA MCP disassembly on 2026-05-26 confirms `ProcessIdleWork` calls [UID:0000HR][BlackHole](by-file/BlackHole.md), [UID:0000OT][TimerMgr](by-file/TimerMgr.md), `EventDispatcher::RebuildHandlerTraversalOrder`, and [UID:0000JM][FrameMgr](by-file/FrameMgr.md) through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md).
- The code is physically adjacent to `EventDispatcher` methods, not to `Application`.
- Existing child pages now carry the stronger range-local evidence: the idle worker is `82/86`, the tick-baseline helper is `78/86`, and the scheduler static flag is `78/86`.
- `by-file/EventDispatcher.md` documents the helper as UI event-routing/message-loop scheduler glue and explicitly rejects final `ApplicationHelper_4A6C40.cpp` migration.

## Open Questions

- Decide whether this is a real class, a generated owner for static helpers, or an unnamed scheduler struct.
- Resolve the substructure under the queue-state object at `+0x4`.
- Do not keep `ApplicationHelper_4A6C40.cpp` as a final source-file name unless stronger source evidence appears.

## Score Rationale

- Completion is raised because the wrapper now records the child evidence matrix, scheduler flow, source-placement decision, and static flag relationship instead of only listing two methods.
- Confidence is raised because all concrete children have exact IDA-backed ranges/xrefs and already agree on [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) as current source placement.
- Confidence remains below final rewrite/class confidence because the original source shape is still unresolved: generated owner label, file-local helper, or separate `MessageLoopScheduler` companion.

## Cross-References

- File: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Related classes: [UID:00000D][Application](by-class/Application.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:00000W][BlackHole](by-class/BlackHole.md), [UID:0000F1][TimerMgr](by-class/TimerMgr.md), [UID:00005H][FrameMgr](by-class/FrameMgr.md)
- Globals: [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md), [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md), [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- Memory: [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md), [UID:000143][0x004a7120-0x004a712b.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712b.ApplicationIdleTickBaseline.md), [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md), [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)

## Changes

- 2026-06-02 documentation pass:
  - What existed before: the page identified the generated helper owner but did not summarize the stronger child-page evidence or the source-placement decision.
  - What it was changed to: raised `65/75` to `72/84`, added child evidence and scheduler-flow tables, and documented that `ApplicationHelper_4A6C40` remains a generated grouping label rather than a final class/source file.
  - Summary/evidence: the two helper methods and related static flag are all documented with exact IDA-backed ranges/xrefs and parented to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md); open risk remains the final source split.
- What existed before: the page documented the helper role and evidence but still had unevaluated `0/0` metadata.
- What it was changed to: scores were set to `65/75` without promoting this projected helper to a final class name.
- Summary and evidence: IDA MCP confirms the two helper ranges and message-loop callers, but confidence stays medium because this may be a generated owner/static helper grouping rather than an original C++ class.
