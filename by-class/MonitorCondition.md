*** UID:00008M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MonitorCondition

## Summary

`MonitorCondition` is a condition/semaphore object tied to a parent [UID:00008L][Monitor](by-class/Monitor.md). It tracks its own waiter count, releases the parent monitor while waiting, wakes one waiter on signal, and synchronizes with the monitor semaphore.

## Likely Original Placement

- Source: [UID:0000LI][Monitor](by-file/Monitor.md)
- Proposed path: `util/Monitor.cpp`
- Confidence: strong

## Methods

- `0x00528740-0x005287e0`: constructor, stores owner monitor and creates the condition semaphore.
- `0x00528810-0x00528855`: wait helper.
- `0x00528860-0x00528892`: signal helper.
- `0x005288f0-0x00528929`: scalar deleting destructor.

## Evidence

- `RingBuffer::RingBuffer` constructs two conditions at `0x00556456` and `0x00556480`.
- `RingBuffer::Enqueue` waits on the not-full condition and signals the not-empty condition.
- `RingBuffer::Dequeue` waits on the not-empty condition and signals the not-full condition.
- IDA confirms all four function starts in the monitor cluster.

## Generated Data Caveats

Active `class_MonitorCondition.cpp` has a malformed constructor install marker and omits the constructor/wait/signal bodies. Use IDA-confirmed boundaries before migrating this class.

## Cross-References

- File: [UID:0000LI][Monitor](by-file/Monitor.md)
- Memory: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- Related: [UID:00008L][Monitor](by-class/Monitor.md), [UID:0000C1][RingBuffer](by-class/RingBuffer.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the condition/semaphore companion object has purpose, method ranges, RingBuffer wait/signal evidence, and generated data caveats documented, but final field names and complete monitor integration still need layout review. Evidence: linked monitor/condition memory cluster, IDA-confirmed constructor/wait/signal/destructor starts, RingBuffer construction/use sites, and active generated-source omission caveat.
