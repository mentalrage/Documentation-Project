*** UID:0000BX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RequestSyncGate

## Summary

`RequestSyncGate` is a tiny synchronization gate wrapper in the `Monitor.cpp` synchronization cluster. Its lock helper waits on the primary handle, and its unlock helper releases either a semaphore or mutex depending on a mode field.

## Likely Original Placement

- Source: [UID:0000LI][Monitor](by-file/Monitor.md)
- Proposed path: `util/Monitor.cpp`
- Confidence: strong for monitor-module ownership, medium for whether this was a public named class or private helper.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00528710-0x0052871c` | lock helper | Calls `WaitForSingleObject(primaryHandle, INFINITE)` and returns the wait result. |
| `0x00528720-0x0052873e` | unlock helper | Checks the release-mode field; positive mode releases the semaphore handle, otherwise it releases the mutex handle. |

## Evidence

- IDA places the methods directly between [UID:00008L][Monitor](by-class/Monitor.md) construction/destruction code and [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) construction.
- The layout in generated source is `vtable`, `primaryHandle`, `releaseMode`, and `semaphoreHandle`.
- Behavior matches the lock/unlock side of monitor/condition control flow: the lock path waits, while the unlock path chooses `ReleaseSemaphore` or `ReleaseMutex`.
- [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records the gate methods inside the exact monitor/condition synchronization cluster, including live Win32 callees, caller context, and padding around both methods.
- [UID:00008L][Monitor](by-class/Monitor.md) and [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) are now attached to [UID:0000LI][Monitor](by-file/Monitor.md) at positions `10` and `20`, making this gate the remaining helper in the same source family.
- [UID:0000LI][Monitor](by-file/Monitor.md) has a valid `NexusTK/util/` projected path and lists `RequestSyncGate` as part of the shared Win32 synchronization primitive module.

## Open Questions

- Whether this was a real named class in original source or Wave3's recovered view of a small embedded monitor-lock helper.
- Whether the type should become private to `Monitor.cpp`.

## Autogen And Reconstruction Notes

- Attached to [UID:0000LI][Monitor](by-file/Monitor.md) at position `30`, after `Monitor` and `MonitorCondition`.
- The helper is reconstructable because the lock/unlock behavior is source-authored synchronization logic with exact Win32 call behavior.
- `RECONSTRUCTION_CPP CODE` remains blank. Final C++ needs the original helper declaration form, public/private placement, field names, and relationship to direct `Monitor` lock/unlock exposure resolved to the 95/95 bar.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The page records the two exact methods, handle/release-mode layout, Win32 wait/release behavior, monitor-cluster placement, parent position, ownership caveat, and no-code autogen handling. Completion remains capped below the parent-attachment class pages because the original source-level class identity is unresolved. |
| Confidence `86` | Confidence is strong for `util/Monitor.cpp` ownership because existing IDA-backed memory docs place the gate inside the exact Monitor/MonitorCondition cluster and confirm the Win32 callees. It is not higher because this may have been a private helper rather than a named exported class. |

## Cross-References

- File: [UID:0000LI][Monitor](by-file/Monitor.md)
- Memory: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- Related: [UID:00008L][Monitor](by-class/Monitor.md), [UID:00008M][MonitorCondition](by-class/MonitorCondition.md)

## Changes

- 2026-06-07 A004 evidence/position refresh:
  - Before: scored `74/84`, attached to [UID:0000LI][Monitor](by-file/Monitor.md), but left the child position blank and summarized only the high-level lock/unlock behavior.
  - After: scored `78/86`, set position `30`, added a method table with exact wait/release behavior, linked the updated `Monitor` and `MonitorCondition` sibling attachments, and documented the final-C++ blockers.
  - Evidence: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records the gate methods, live `WaitForSingleObject`/`ReleaseMutex`/`ReleaseSemaphore` callees, placement between monitor and condition bodies, and padding; [UID:00008L][Monitor](by-class/Monitor.md) and [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) are now attached under the same parent at positions `10` and `20`.
- 2026-06-02:
  - Before: scored `68/72`, reconstructability and parent blank.
  - After: scored `74/84`, marked reconstructable, and attached to [UID:0000LI][Monitor](by-file/Monitor.md) with C++ blank.
  - Why: the exact monitor/condition aggregate and updated Monitor file page support high-confidence ownership, while the final helper declaration shape remains unresolved.
- 2026-05-30: Changed completion/confidence from `0/0` to `68/72`.
  - Before: The page was unevaluated despite documenting lock/unlock behavior, observed layout, placement, and open class-identity caveats.
  - After: Scored as moderate completion and confidence because method behavior is clear but whether this was a real original named class remains unresolved.
  - Evidence: Existing method list, IDA locality notes, generated layout, and Monitor/MonitorCondition cross-references establish the helper behavior and ownership uncertainty.
