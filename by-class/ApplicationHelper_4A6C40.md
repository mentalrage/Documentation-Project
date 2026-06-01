*** UID:00000E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:65 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ApplicationHelper_4A6C40

## Summary

`ApplicationHelper_4A6C40` is a projected helper owner for message-loop idle work. It captures a timer baseline and processes queued idle-side work between batches of Win32 messages, including draining the [UID:00000W][BlackHole](by-class/BlackHole.md) deferred deletion queue, dispatching timers, rebuilding event traversal state, and dispatching frame callbacks.

## Likely Original Placement

- Source: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Proposed path: `ui/core/EventDispatcher.cpp` or a small `ui/core/MessageLoopScheduler.cpp`
- Confidence: medium

## Methods

- `0x004a6c40-0x004a6cda` `ProcessIdleWork` - drains [UID:00000W][BlackHole](by-class/BlackHole.md), performs timer updates, traversal rebuild, and tick-slice advancement.
- `0x004a7120-0x004a712b` `CaptureCurrentTickBaseline` - captures the current timer tick before the message loop waits.

## Evidence

- Wave3 notes a queue-state subobject at `+0x4` and tick/slice fields at `+0x2c` and `+0x30`.
- IDA MCP confirms `ProcessIdleWork` at `0x004a6c40-0x004a6cda` and shows it is called from `Application::RunMessageLoop` at `0x00464df7` and `0x00464e0e`.
- IDA decompilation shows `ProcessIdleWork` begins by calling `BlackHole::ReleaseQueuedOwnedObjects(dword_67A74C)`.
- IDA MCP confirms `CaptureCurrentTickBaseline` at `0x004a7120-0x004a712b`.
- IDA MCP disassembly on 2026-05-26 confirms `ProcessIdleWork` calls [UID:0000HR][BlackHole](by-file/BlackHole.md), [UID:0000OT][TimerMgr](by-file/TimerMgr.md), `EventDispatcher::RebuildHandlerTraversalOrder`, and [UID:0000JM][FrameMgr](by-file/FrameMgr.md) through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md).
- The code is physically adjacent to `EventDispatcher` methods, not to `Application`.

## Open Questions

- Decide whether this is a real class, a generated owner for static helpers, or an unnamed scheduler struct.
- Resolve the substructure under the queue-state object at `+0x4`.
- Do not keep `ApplicationHelper_4A6C40.cpp` as a final source-file name unless stronger source evidence appears.

## Cross-References

- File: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Related classes: [UID:00000D][Application](by-class/Application.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:00000W][BlackHole](by-class/BlackHole.md), [UID:0000F1][TimerMgr](by-class/TimerMgr.md), [UID:00005H][FrameMgr](by-class/FrameMgr.md)
- Globals: [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md), [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md), [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- Memory: [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md), [UID:000143][0x004a7120-0x004a712b.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712b.ApplicationIdleTickBaseline.md), [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md), [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)

## Changes

- What existed before: the page documented the helper role and evidence but still had unevaluated `0/0` metadata.
- What it was changed to: scores were set to `65/75` without promoting this projected helper to a final class name.
- Summary and evidence: IDA MCP confirms the two helper ranges and message-loop callers, but confidence stays medium because this may be a generated owner/static helper grouping rather than an original C++ class.
