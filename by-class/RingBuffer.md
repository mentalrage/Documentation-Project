*** UID:0000C1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RingBuffer

## Summary

`RingBuffer` is a blocking fixed-element circular queue. It owns raw storage, read/write/count fields, one [UID:00008L][Monitor](by-class/Monitor.md), and two [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) objects for not-empty and not-full waits.

## Likely Original Placement

- Source: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Proposed path: `util/RingBuffer.cpp`
- Confidence: strong

## Methods

| Range | Role |
| --- | --- |
| `0x005563d0-0x005564d4` | Constructor. |
| `0x005564e0-0x00556579` | Non-deleting cleanup body. |
| `0x00556580-0x005565ec` | Enqueue: blocks while full, copies one element, signals not-empty. |
| `0x005565f0-0x0055665a` | Dequeue: blocks while empty, copies one element, signals not-full. |
| `0x00556660-0x00556668` | Empty-test helper. |
| `0x00556670-0x0055667a` | Raw full/non-full predicate; IDA has no function object at this start. |
| `0x00556680-0x00556688` | Lock wrapper: forwards through the owned `Monitor`. |
| `0x00556690-0x00556698` | Unlock wrapper: forwards through the owned `Monitor`. |
| `0x005566a0-0x005566a8` | Raw empty predicate duplicate or iterator-facing alias; IDA has no function object. |
| `0x005566b0-0x005566ba` | Raw full/non-full predicate duplicate or iterator-facing alias; IDA has no function object. |
| `0x00556750-0x005567ae` | Raw iterator helper pocket for retreat, boundary checks, and element-pointer computation; IDA has no function objects at these starts. |
| `0x005567b0-0x00556887` | Scalar deleting destructor. |

## Vtable

IDA confirms `??_7RingBuffer@@6B@` at `0x006230cc`, with constructor/destructor stores at `0x00556408`, `0x00556508`, and `0x005567df`. Slots currently resolve as deleting destructor `0x005567b0`, shared `LObject` virtual `0x004f4b10`, and `nullsub_18` at `0x0041b6c0`.

See [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md). The next dword after the three slots is adjacent RTTI data for `RingBufferIterator`, not a fourth `RingBuffer` virtual slot.

## Evidence

- `Thread::Thread` constructs two `RingBuffer` instances for message queues.
- `Thread::StopThread`, sync send, async post, and sync post helpers call enqueue.
- `Thread::ThreadProc` calls dequeue.
- Constructor calls `Monitor::Monitor` and `MonitorCondition::MonitorCondition` twice.
- 2026-05-26 IDA `py_eval` recheck confirmed modeled function starts at `0x005563d0`, `0x005564e0`, `0x00556580`, `0x005565f0`, `0x00556660`, `0x00556680`, `0x00556690`, `0x005567b0`, and the iterator helpers at `0x005566f0`, `0x00556720`, and `0x00556890`.
- Current `source-3/simroot_v2/util/RingBuffer.meta_wave3` reports the `RingBuffer` vtable at `0x006230cc` and the `RingBufferIterator` vtable at `0x006230dc`, matching IDA.
- 2026-06-01 IDA MCP recheck confirmed direct Thread callers to constructor/enqueue/dequeue/empty-test, vtable stores at `0x00556408`, `0x00556508`, `0x005567df`, and additional raw iterator helper bodies between `0x00556750` and `0x005567ae`.

## Generated Data Caveats

Current active `simroot_v2/util/RingBuffer.cpp` emits the main queue methods, cleanup body, and iterator methods, and current metadata now includes the two vtables. Generated source is still incomplete around raw tiny helper starts: `0x00556670`, `0x005566a0`, `0x005566b0`, `0x00556700`, `0x00556750`, `0x00556770`, `0x00556780`, and `0x005567a0` have raw code bytes and metadata/source-map coverage but no IDA function object or active generated function body. Use [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md) for the complete binary range.

## Cross-References

- File: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Memory: [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md)
- Vtable: [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md)
- Related: [UID:0000EV][Thread](by-class/Thread.md), [UID:00008L][Monitor](by-class/Monitor.md), [UID:00008M][MonitorCondition](by-class/MonitorCondition.md), [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/84`.
  - Before: The page was unevaluated despite documenting queue semantics, method ranges, vtable, Thread usage, synchronization dependencies, and raw helper omissions.
  - After: Scored as high completion and strong confidence for the blocking ring buffer, short of perfect due to raw tiny helper starts lacking IDA function objects.
  - Evidence: Existing method table, vtable section, Thread/Monitor evidence, Wave3 metadata comparison, and generated data caveats support the score.
- 2026-06-01: Added the expanded raw iterator-helper pocket found during the memory-page rescore.
  - Evidence: IDA MCP disassembly identifies additional unmodeled helper bodies after `0x00556720`, separated by alignment padding and operating on the iterator's owner pointer/current index fields.
