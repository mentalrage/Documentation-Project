*** UID:0000BX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Confidence: medium

## Methods

- `0x00528710-0x0052871c`: `Lock`, calls `WaitForSingleObject(primaryHandle, INFINITE)`.
- `0x00528720-0x0052873e`: `Unlock`, releases semaphore when `releaseMode > 0`, otherwise releases mutex.

## Evidence

- IDA places the methods directly between `Monitor` construction and `MonitorCondition` construction.
- The layout in generated source is `vtable`, `primaryHandle`, `releaseMode`, `semaphoreHandle`.
- Behavior matches the lock/unlock side of monitor/condition control flow.

## Open Questions

- Whether this was a real named class in original source or Wave3's recovered view of a small embedded monitor-lock helper.
- Whether the type should become private to `Monitor.cpp`.

## Cross-References

- File: [UID:0000LI][Monitor](by-file/Monitor.md)
- Memory: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- Related: [UID:00008L][Monitor](by-class/Monitor.md), [UID:00008M][MonitorCondition](by-class/MonitorCondition.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `68/72`.
  - Before: The page was unevaluated despite documenting lock/unlock behavior, observed layout, placement, and open class-identity caveats.
  - After: Scored as moderate completion and confidence because method behavior is clear but whether this was a real original named class remains unresolved.
  - Evidence: Existing method list, IDA locality notes, generated layout, and Monitor/MonitorCondition cross-references establish the helper behavior and ownership uncertainty.
