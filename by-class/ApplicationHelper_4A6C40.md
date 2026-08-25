*** UID:00000E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ApplicationHelper_4A6C40

## Summary

`ApplicationHelper_4A6C40` is a projected helper owner for message-loop idle work. It captures a timer baseline and processes queued idle-side work between batches of Win32 messages, including draining the [UID:00000W][BlackHole](by-class/BlackHole.md) deferred deletion queue, dispatching timers, rebuilding event traversal state, and dispatching frame callbacks.

This page is a documentation wrapper for the generated owner label, not a proven original C++ class. The concrete children are documented as UI-core scheduler helpers attached to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), with call sites from [UID:0000HG][Application](by-file/Application.md).

## Likely Original Placement

- Source: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Proposed path: `ui/core/EventDispatcher.cpp` or a small `ui/core/MessageLoopScheduler.cpp`
- Confidence: strong for rejecting `ApplicationHelper_4A6C40` as a final class/source file; medium for the exact helper spelling and final source split.

## Methods

- `0x004a6c40-0x004a6cda` `ProcessIdleWork` / `ApplicationIdleWorkScheduler` - drains [UID:00000W][BlackHole](by-class/BlackHole.md), performs timer updates, traversal rebuild, and tick-slice advancement.
- `0x004a7120-0x004a712c` `CaptureIdleTickBaseline` / `ApplicationIdleTickBaseline` - captures the current timer tick before the message loop waits.

## Child Evidence Matrix

| Child | Score | Parent/source placement | Evidence status |
| --- | ---: | --- | --- |
| [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md) | `86/88` | [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) | Exact range, two `Application::RunMessageLoop` callers, cleanup/timer/traversal/frame callee chain, static flag behavior, elapsed-slice math, and `m_idleTickBaseline` / `m_lastDispatchedIdleSlice` state roles are documented. |
| [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md) | `86/90` | [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) | Exact `0x0c` range, single `Application::RunMessageLoop` caller with `ecx = g_pEventDispatcher`, no-callee direct tick snapshot, `g_pTimerMgr+0x18` read, and `m_idleTickBaseline` write are documented. |
| [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md) | `90/91` | [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) | Initial flag byte, exact read/write xrefs inside `0x004a6c40`, one-shot idle timer setup gate, clear/write site, padding boundary before `0x0066d888`, and final private EventDispatcher.cpp static name `s_idleTimerSetupPending` are documented. |

## Scheduler Flow

| Phase | Evidence |
| --- | --- |
| Message-loop entry baseline | `Application::RunMessageLoop` calls `0x004a7120`; that helper snapshots the current timer tick into helper offset `+0x2c`. |
| Idle work wakeup | `Application::RunMessageLoop` calls `0x004a6c40` at two wake/idle call sites. |
| Deferred cleanup | `0x004a6c40` first drains [UID:0000HR][BlackHole](by-file/BlackHole.md) through [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md). |
| Timer dispatch | The idle worker calls timer-period/dispatch helpers and uses [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md); the one-shot setup path is gated by private EventDispatcher.cpp static `s_idleTimerSetupPending`. |
| Dispatcher maintenance | The idle worker calls the EventDispatcher traversal rebuild path on the helper's dispatcher-adjacent state. |
| Frame callbacks | Changed elapsed slices dispatch through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) and [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md). |

## 2026-06-14 A001 IDA Refresh

Live IDA MCP session `a001_goal2_class_batch` reconfirms this page as a reviewed generated wrapper rather than a source-level class. `lookup_funcs` reports only `sub_4A6C40` at `0x004a6c40`, size `0x9b`, and `sub_4A7120` at `0x004a7120`, size `0x0c`, for this projected owner.

`analyze_function 0x004a6c40` reports exactly two code xrefs, `0x00464df7` and `0x00464e0e`, both in `sub_464CD0` / `Application::RunMessageLoop`. The decompilation begins with `sub_469200(dword_67A74C)`, then conditionally refreshes `unk_67AB80` through the `byte_66D880` gate now documented as `s_idleTimerSetupPending`, calls dispatcher maintenance through `sub_4A7E70`, and computes elapsed frame slices from the timer field at `unk_67AB80 + 0x18`. The division by `0x14` equals 20 decimal (Verified with int_convert.py), so this helper dispatches frame callbacks only when the 20 ms slice count changes.

`analyze_function 0x004a7120` reports one caller, `0x00464ce1` in `Application::RunMessageLoop`, and no callees. Its entire body loads `unk_67AB80 + 0x18` and stores the value to EventDispatcher offset `+0x2c`, now best described as `m_idleTickBaseline`, which matches the baseline field used later by `0x004a6c40`.

These checks strengthen the exclusion: the generated wrapper has two small helper bodies and no independent class lifecycle, vtable, or object allocation evidence. The source-bearing work remains the exact helper/static child pages routed through [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), while this page records why `ApplicationHelper_4A6C40.cpp` should not be emitted.

## Source-Structure Decision

Keep `ApplicationHelper_4A6C40` as a generated grouping name. The behavior is well documented, but original-source placement should be either:

- a file-local helper inside [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), or
- a small `ui/core/MessageLoopScheduler.cpp` companion if future source-line evidence proves a separate module.

Do not emit or preserve `ApplicationHelper_4A6C40.cpp` as a final source file name.

The 2026-06-20 B001 aggregate audit for [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md) strengthens the rejection of `ApplicationHelper_4A6C40` as a source class. The `0x004a6c40` body receives `g_pEventDispatcher` as `ecx`, operates on dispatcher state, calls the dispatcher traversal rebuild path, drains deferred cleanup, dispatches timer/frame work, and pairs with `0x004a7120` / `EventDispatcher::CaptureIdleTickBaseline`. Keep this page as a reviewed non-reconstructable alias/wrapper only; source-bearing details belong on the exact by-memory helper pages and [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md).

## Autogen Status

- Reconstructable: false for this wrapper, because `ApplicationHelper_4A6C40` is a generated owner label rather than a source-level class or standalone module that should be reconstructed.
- Concrete source-bearing children: [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md), [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md), and [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md) remain the reconstructable items and are staged through [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md).
- Static flag child: [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md) now emits as `static bool s_idleTimerSetupPending = true;` from EventDispatcher.cpp, not from this wrapper.
- Parent/C++: intentionally blank. This reviewed false wrapper should not attach to an autogen parent and should not emit `ApplicationHelper_4A6C40.cpp`; final source should come from the concrete child pages and the eventual `EventDispatcher`/message-loop scheduler shape.

## Evidence

- IDA MCP confirms `ProcessIdleWork` at `0x004a6c40-0x004a6cda` and shows it is called from `Application::RunMessageLoop` at `0x00464df7` and `0x00464e0e`.
- IDA decompilation shows `ProcessIdleWork` begins by calling `BlackHole::ReleaseQueuedOwnedObjects(dword_67A74C)`.
- IDA MCP confirms `CaptureCurrentTickBaseline` at `0x004a7120-0x004a712b`.
- IDA MCP disassembly on 2026-05-26 confirms `ProcessIdleWork` calls [UID:0000HR][BlackHole](by-file/BlackHole.md), [UID:0000OT][TimerMgr](by-file/TimerMgr.md), `EventDispatcher::RebuildHandlerTraversalOrder`, and [UID:0000JM][FrameMgr](by-file/FrameMgr.md) through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md).
- The documented child pages cover the queue-state offset `+0x4`, tick baseline `+0x2c`, and last-dispatched slice `+0x30` relationships without requiring a standalone wrapper class.
- The code is physically adjacent to `EventDispatcher` methods, not to `Application`.
- Existing child pages now carry the stronger range-local evidence: the idle worker is `86/88`, the tick-baseline helper is `86/90`, and the scheduler static flag is `90/91` with source name `s_idleTimerSetupPending`.
- `by-file/EventDispatcher.md` documents the helper as UI event-routing/message-loop scheduler glue and explicitly rejects final `ApplicationHelper_4A6C40.cpp` migration.

## Open Questions

- Decide whether the concrete helpers become file-local `EventDispatcher.cpp` code or a small `MessageLoopScheduler` companion.
- Resolve final names for the scheduler state at offset `+0x4` and any remaining exact helper spellings. The static flag is now `s_idleTimerSetupPending`; current best descriptive names for `+0x2c` and `+0x30` are `m_idleTickBaseline` and `m_lastDispatchedIdleSlice`.
- Do not keep `ApplicationHelper_4A6C40.cpp` as a final source-file name.

## Score Rationale

- Completion is raised because the page now records the reviewed non-reconstructable wrapper status, concrete child ownership, scheduler flow, source-placement decision, static flag relationship, current function sizes, direct message-loop caller sites, and 20 ms slice-gate behavior.
- Confidence is raised because current IDA MCP data, generated coverage, the child pages, and [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) all agree that `ApplicationHelper_4A6C40` should not survive as a final class/source file.
- Confidence remains below final source confidence because the concrete helpers still need final field names and a final choice between file-local `EventDispatcher` code and a named `MessageLoopScheduler` companion.

## Cross-References

- File: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Related classes: [UID:00000D][Application](by-class/Application.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:00000W][BlackHole](by-class/BlackHole.md), [UID:0000F1][TimerMgr](by-class/TimerMgr.md), [UID:00005H][FrameMgr](by-class/FrameMgr.md)
- Globals: [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md), [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md), [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- Memory: [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md), [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md), [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md), [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)

## Changes

- 2026-06-26 B014 idle scheduler static flag implementation:
  - Score unchanged at `85/88`.
  - Summary/evidence: updated the generated-wrapper page to match UID00027B. The static flag child is now `90/91`, emits as private EventDispatcher.cpp `s_idleTimerSetupPending`, and remains source-bearing through [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), while `ApplicationHelper_4A6C40` stays a non-reconstructable wrapper and rejected final source file.
- 2026-06-02 documentation pass:
  - What existed before: the page identified the generated helper owner but did not summarize the stronger child-page evidence or the source-placement decision.
  - What it was changed to: raised `65/75` to `72/84`, added child evidence and scheduler-flow tables, and documented that `ApplicationHelper_4A6C40` remains a generated grouping label rather than a final class/source file.
  - Summary/evidence: the two helper methods and related static flag are all documented with exact IDA-backed ranges/xrefs and parented to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md); open risk remains the final source split.
- What existed before: the page documented the helper role and evidence but still had unevaluated `0/0` metadata.
- What it was changed to: scores were set to `65/75` without promoting this projected helper to a final class name.
- Summary and evidence: IDA MCP confirms the two helper ranges and message-loop callers, but confidence stays medium because this may be a generated owner/static helper grouping rather than an original C++ class.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:FALSE`. Current IDA MCP `lookup_funcs` confirmed only the two helper functions at `0x004a6c40` and `0x004a7120`, and `callers` shows both reached from `Application::RunMessageLoop`; the page's documented source decision keeps the concrete helpers under [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) instead of preserving `ApplicationHelper_4A6C40` as a standalone reconstructed class.
- 2026-06-06 exclusion/report cleanup:
  - Before: the page was correctly marked `RECONSTRUCTABLE:FALSE` but stayed at `72/84`, and the manual class report still described the wrapper as reconstructable at `65%`.
  - Changed to: `80/86`, with explicit autogen status, concrete child ownership, and narrowed open questions that keep the wrapper excluded while preserving the reconstructable child helpers under [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md).
  - Evidence: generated coverage already reports this UID as `not_reconstructable`; [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md), [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md), and [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md) carry the source-bearing scheduler evidence and are staged through [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). C++ remains blank because the wrapper is not a final source-level object.
- 2026-06-14 A001 Goal 2 class refresh: raised `80/86` to `85/88` after live IDA MCP session `a001_goal2_class_batch` reconfirmed the two helper sizes, the exact message-loop call sites, the no-callee tick baseline body, the idle-worker callee set, and the 20 ms frame-slice calculation. The wrapper remains `RECONSTRUCTABLE:FALSE` with blank emitter/code because it has no independent source-level class identity.
- 2026-06-17 B001 companion source-quality sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: B001's [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md) report raised the tick-baseline child to `86/90`, chose `EventDispatcher::CaptureIdleTickBaseline` as the best source-facing helper name, and refined the scheduler state roles as `m_idleTickBaseline` / `m_lastDispatchedIdleSlice`. This wrapper remains non-reconstructable because those source-bearing helpers route through [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), not a standalone `ApplicationHelper_4A6C40` class.
- 2026-06-20 B001 EventDispatcher aggregate source-quality execution:
  - Score unchanged at `85/88`.
  - Summary/evidence: B001's [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md) report confirms `ApplicationHelper_4A6C40` is a generated grouping label, not a final C++ class/source file. The source-bearing work is `EventDispatcher::ProcessIdleWork`, `EventDispatcher::CaptureIdleTickBaseline`, the scheduler static flag, and related dispatcher state under [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md).
