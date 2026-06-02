*** UID:0000BX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RequestSyncGate

## Summary

`RequestSyncGate` is a tiny synchronization gate wrapper. Its `Lock` waits on the primary handle, and its `Unlock` releases either a semaphore or mutex depending on a mode field.

## Likely Original Placement

- Source: [UID:0000LI][Monitor](by-file/Monitor.md)
- Proposed path: `util/Monitor.cpp`
- Confidence: strong for monitor-module ownership, medium for whether this was a public named class or private helper.

## Methods

- `0x00528710-0x0052871c`: `Lock`, calls `WaitForSingleObject(primaryHandle, INFINITE)`.
- `0x00528720-0x0052873e`: `Unlock`, releases semaphore when `releaseMode > 0`, otherwise releases mutex.

## Evidence

- IDA places the methods directly between `Monitor` construction and `MonitorCondition` construction.
- The layout in generated source is `vtable`, `primaryHandle`, `releaseMode`, `semaphoreHandle`.
- Behavior matches the lock/unlock side of monitor/condition control flow.
- [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records the gate methods inside the exact monitor/condition synchronization cluster, between `Monitor::Monitor` and `MonitorCondition::MonitorCondition`.
- [UID:0000LI][Monitor](by-file/Monitor.md) now has a valid `NexusTK/util/` projected path and `82/82` score, with `RequestSyncGate` listed as part of the shared Win32 synchronization primitive module.

## Open Questions

- Whether this was a real named class in original source or Wave3's recovered view of a small embedded monitor-lock helper.
- Whether the type should become private to `Monitor.cpp`.

## Autogen Status

Attach this helper to [UID:0000LI][Monitor](by-file/Monitor.md) as reconstructable synchronization metadata. Leave C++ blank: the lock/unlock behavior is clear, but the final original declaration form, class name, and private-vs-public placement are not final-source quality.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `74` | The page records the two exact methods, handle layout, monitor-cluster placement, parent file, ownership caveat, and no-code autogen handling. Completion remains capped because the original source-level class identity is unresolved. |
| Confidence `84` | Confidence is strong for `util/Monitor.cpp` ownership because IDA places the gate inside the exact Monitor/MonitorCondition cluster and the parent file is now high-confidence. It is not higher because this may have been a private helper rather than a named exported class. |

## Cross-References

- File: [UID:0000LI][Monitor](by-file/Monitor.md)
- Memory: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- Related: [UID:00008L][Monitor](by-class/Monitor.md), [UID:00008M][MonitorCondition](by-class/MonitorCondition.md)

## Changes

- 2026-06-02:
  - Before: scored `68/72`, reconstructability and parent blank.
  - After: scored `74/84`, marked reconstructable, and attached to [UID:0000LI][Monitor](by-file/Monitor.md) with C++ blank.
  - Why: the exact monitor/condition aggregate and updated Monitor file page support high-confidence ownership, while the final helper declaration shape remains unresolved.
- 2026-05-30: Changed completion/confidence from `0/0` to `68/72`.
  - Before: The page was unevaluated despite documenting lock/unlock behavior, observed layout, placement, and open class-identity caveats.
  - After: Scored as moderate completion and confidence because method behavior is clear but whether this was a real original named class remains unresolved.
  - Evidence: Existing method list, IDA locality notes, generated layout, and Monitor/MonitorCondition cross-references establish the helper behavior and ownership uncertainty.
