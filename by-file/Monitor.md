*** UID:0000LI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Monitor

## Status

- Proposed module: `util/Monitor.cpp`
- Proposed header: `util/Monitor.h`
- Confidence: strong for synchronization ownership, medium for exact source-file split.
- Current recovered sources: `class_Monitor.cpp`, `class_MonitorCondition.cpp`, `class_RequestSyncGate.cpp`, `class_CriticalSectionLock.cpp`

## File Role

`Monitor.cpp` is the likely shared synchronization primitive module. It should group the Win32 mutex/semaphore monitor class, its condition object, the tiny request-sync gate helper, and the RAII critical-section lock wrapper.

This code is lower-level than `Thread.cpp`: [UID:0000OR][Thread](by-file/Thread.md) and [UID:0000N8][RingBuffer](by-file/RingBuffer.md) consume these primitives, but the primitives do not depend on those higher-level classes.

## Likely Contents

- [UID:00008L][Monitor](by-class/Monitor.md)
- [UID:00008M][MonitorCondition](by-class/MonitorCondition.md)
- [UID:0000BX][RequestSyncGate](by-class/RequestSyncGate.md)
- [UID:00003C][CriticalSectionLock](by-class/CriticalSectionLock.md)

## Evidence

- IDA MCP confirms the monitor/condition/gate cluster at `0x005285e0-0x00528929`.
- `Monitor::Monitor` creates an unnamed mutex and semaphore and throws `Win32Error` on handle creation failure.
- `RequestSyncGate::Lock` and `RequestSyncGate::Unlock` sit between `Monitor` and `MonitorCondition` in memory and operate on the same mutex/semaphore-style handle layout.
- `MonitorCondition::Wait` releases the parent monitor lock while waiting on the condition semaphore, then reacquires monitor state by decrementing the condition waiter count.
- `MonitorCondition::Signal` releases one condition waiter and synchronizes through the monitor semaphore when waiters exist.
- [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md) and `CriticalSectionLock` at `0x0049bcf0-0x0049bd19` are not memory-adjacent to the monitor cluster, but they are tiny Win32 critical-section synchronization helpers. The RAII lock has application message-loop callers.

## Generated Output Caveats

Active `class_MonitorCondition.cpp` currently has a malformed constructor marker and emits only the scalar deleting destructor body. IDA confirms real omitted methods at:

- `0x00528740`: `MonitorCondition` constructor
- `0x00528810`: wait helper
- `0x00528860`: signal helper

The active `class_CriticalSectionLock.cpp` duplicates local struct declarations and includes, but the behavior is simple and IDA-aligned.

## Source-Structure Decision

Use one `util/Monitor.cpp` module for these synchronization primitives. A later split into `CriticalSectionLock.cpp` is possible if original import/source evidence appears, but the current codebase benefits from documenting it as the same synchronization family.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `82` | The page records the synchronization primitive family, valid projected path, exact monitor/condition/gate aggregate, critical-section companion helpers, consumer boundaries, generated-output caveats, and source-structure decision. Completion remains capped because final original split between Monitor and CriticalSectionLock is still not proven. |
| Confidence `82` | Confidence is strong enough for child attachment because IDA-backed docs tie `Monitor`, `MonitorCondition`, and `RequestSyncGate` into one exact Win32 synchronization cluster under `util/Monitor.cpp`. It is not higher because `CriticalSectionLock` may later split into a companion file. |

## Cross-References

- [UID:00008L][Monitor](by-class/Monitor.md)
- [UID:00008M][MonitorCondition](by-class/MonitorCondition.md)
- [UID:0000BX][RequestSyncGate](by-class/RequestSyncGate.md)
- [UID:00003C][CriticalSectionLock](by-class/CriticalSectionLock.md)
- [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md)
- [UID:00012A][0x0049bcf0-0x0049bd19.CriticalSectionLock](by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- [UID:0001QT][client_threading](by-meta/client_threading.md)

## Changes

- 2026-06-02:
  - Before: scored `80/78`.
  - After: scored `82/82`.
  - Why: the exact monitor/condition/gate cluster, valid `NexusTK/util/` path, generated-output caveats, and lower-level synchronization role are now sufficient for child attachment; the only remaining uncertainty is final split from `CriticalSectionLock`.
- Before: this file only mentioned `CriticalSectionLock` at `0x0049bcf0-0x0049bd19` as the low-address synchronization helper.
- Changed to: include the adjacent critical-section API wrapper family at `0x0049bcb0-0x0049bce8`.
- Summary/evidence: IDA MCP/raw disassembly shows wrappers for `InitializeCriticalSection`, `DeleteCriticalSection`, `EnterCriticalSection`, and `LeaveCriticalSection` immediately before the RAII lock constructor/destructor.

- Before: the monitor/condition cluster was recorded as ending at `0x00528928`.
- Changed to: the cluster ends at `0x00528929`.
- Summary/evidence: 2026-05-28 IDA MCP shows `MonitorCondition::ScalarDeletingDestructor` ends at `0x00528929`; `0x00528928` is the final `retn 4` operand byte.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `80`, confidence `78`.
- Summary/evidence: the page documents synchronization ownership, contained classes, IDA evidence, generated-output caveats, and range corrections; confidence remains medium-high because the original source-file split for `CriticalSectionLock` versus monitor primitives is still unresolved.
