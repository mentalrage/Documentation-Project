*** UID:0000N8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# RingBuffer

## Status

- Proposed module: `util/RingBuffer.cpp`
- Proposed header: `util/RingBuffer.h`
- Confidence: strong for utility ownership, current `util/` grouping, and ownership of the compiler-emitted RingBuffer/RingBufferIterator vtable data; medium for whether the original project exposed `RingBufferIterator` publicly or kept it as a private local helper.
- Current recovered source: `source-3/simroot_v2/util/RingBuffer.cpp`

## File Role

`RingBuffer.cpp` owns the blocking fixed-size ring buffer used by [UID:0000OR][Thread](by-file/Thread.md) for message queues. It combines raw element storage with [UID:0000LI][Monitor](by-file/Monitor.md) and [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) to provide producer/consumer enqueue and dequeue operations.

It is a synchronization-aware container and is tracked with the other reusable storage helpers in [UID:0001QA][client_containers](by-meta/client_containers.md).

## Batch 065 Vtable-Data Parent Gate

This file now clears the corrected `85/85` gate for exact RingBuffer vtable-data children. Completion remains `86`, and confidence rises from `82` to `85` because the file-level ownership of the vtable data is stronger than the still-open public/private iterator exposure question: IDA-backed file evidence ties both [UID:0000C1][RingBuffer](by-class/RingBuffer.md) and [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md) to the same `util/RingBuffer.cpp` source island, [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md) records the exact COL/vtable layout, and the [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) child is compiler-emitted from declarations owned by this source module. Final C++ emission is still blocked by raw helper names and iterator exposure, but those caveats do not undermine this file as the direct autogen parent for the exact vtable-data range.

## Likely Contents

- [UID:0000C1][RingBuffer](by-class/RingBuffer.md), attached class root for the blocking queue object
- [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md), a small iterator-like companion type with raw constructor evidence, IDA-confirmed RTTI/COL, and an IDA-confirmed vtable
- ring-buffer and iterator local helper/accessor functions around `0x00556670-0x005567ae`
- [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md)

## Evidence

- IDA MCP confirms a ring-buffer island at `0x005563d0-0x005568c8`.
- `RingBuffer::RingBuffer` constructs one `Monitor` and two `MonitorCondition` objects, stores element size/capacity, allocates zeroed storage, and initializes read/write/count fields.
- `Thread::Thread` constructs two ring buffers with `elementSize = 24`, matching the thread message record.
- Current active generated methods at `0x00556580`, `0x005565f0`, and `0x00556660` match blocking enqueue, blocking dequeue, and empty-test behavior.
- `RingBuffer::Enqueue` is called by `Thread::StopThread` and thread message-post helpers.
- `RingBuffer::Dequeue` is called by `Thread::ThreadProc`.
- IDA confirms two short MSVC vtables in `.rdata`: `??_7RingBuffer@@6B@` at `0x006230cc` and `??_7RingBufferIterator@@6B@` at `0x006230dc`.
- 2026-05-26 current `simroot_v2/util/RingBuffer.meta_wave3` now reports `vtable_count: 1` for both `RingBuffer` and `RingBufferIterator`, with reviewed vtable evidence at `0x006230cc` and `0x006230dc`.
- 2026-05-26 IDA `py_eval` recheck found direct code xrefs from `Thread` methods to the constructor (`0x005962da`, `0x00596306`), enqueue (`0x0059657f`, `0x005966b0`, `0x00596997`, `0x005969e7`, `0x00596a86`), dequeue (`0x00596872`), and empty test (`0x0059684d`, `0x0059685e`).
- 2026-06-01 IDA MCP recheck confirmed additional raw iterator helpers at `0x00556750`, `0x00556770`, `0x00556780`, and `0x005567a0`, plus `RingBuffer` vtable stores at `0x00556408`, `0x00556508`, and `0x005567df` and the `RingBufferIterator` vtable store at `0x005566d7`.
- 2026-06-03 IDA MCP recheck confirmed `RingBufferIterator` RTTI/COL `??_R4RingBufferIterator@@6B@` at `0x006230d8`, vtable `??_7RingBufferIterator@@6B@` at `0x006230dc`, constructor vptr store at `0x005566d7`, and the compact iterator layout `(vptr, RingBuffer* owner, int currentIndex)`.
- 2026-06-03 IDA MCP non-flow xref sweep still found no direct callers for the iterator constructor/helper starts, so the iterator class is attached to this file but remains below source-quality C++ emission.

## Generated Output Caveats

Current active `simroot_v2/util/RingBuffer.cpp` now emits the `RingBuffer` constructor, cleanup body, enqueue, dequeue, empty-test, lock/unlock wrappers, scalar deleting destructor, and the `RingBufferIterator` constructor/reset/next/scalar-deleting-destructor methods in one emitted `util/` source file. The remaining gaps are raw/non-IDA helper starts that are tracked in metadata/source maps but still have no emitted source bodies:

- `0x005564e0`: non-deleting cleanup body
- `0x00556580`: enqueue
- `0x005565f0`: dequeue
- `0x00556660`: empty-test helper
- `0x00556670`, `0x005566a0`, `0x005566b0`, `0x00556700`, `0x00556750`, `0x00556770`, `0x00556780`, `0x005567a0`: raw helper starts with no IDA function object and no active generated function body
- `0x00556680`, `0x00556690`, `0x005566f0`, `0x00556720`: IDA-modeled small helper/accessor/iterator-adjacent functions needing final names
- `0x005567b0`: scalar deleting destructor
- `0x00556890`: generated as `RingBufferIterator::ScalarDeletingDestructor`
- `0x006230cc`, `0x006230dc`: IDA-confirmed vtables, now present in current `RingBuffer.meta_wave3`

Wave3 currently emits `RingBufferIterator::RingBufferIterator` at `0x005566c0`. IDA still has no function object at that start, but raw bytes form a normal constructor-shaped body: base initialization, store of the owning `RingBuffer*`, vptr store to `0x006230dc`, `m_currentIndex = -1`, and return. Treat it as raw-confirmed code that needs IDA function-boundary recovery, not as a fully IDA-modeled function.

The 2026-06-01 IDA pass corrected the raw constructor-shaped endpoint to include the epilogue and `retn 4` at `0x005566e8`, so the body is tracked as `0x005566c0-0x005566eb` before alignment padding.

## Source-Structure Decision

Use `util/RingBuffer.cpp`. Keep it separate from [UID:0000OR][Thread](by-file/Thread.md) because it is a reusable blocking container with its own monitor/condition implementation and a compact code island. Keep it separate from [UID:0000KS][List](by-file/List.md) because it is synchronization-aware and not the same fixed-width dynamic array container.

## Cross-References

- [UID:0000C1][RingBuffer](by-class/RingBuffer.md)
- [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md)
- [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md)
- [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0000LI][Monitor](by-file/Monitor.md)
- [UID:0001QT][client_threading](by-meta/client_threading.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `82`.
  - Evidence: document captures utility ownership, class contents, IDA function island, Thread call evidence, vtable evidence, generated-output caveats, raw helper gaps, and source-structure decision; confidence is capped by unresolved raw helper names and the exact public/private status of `RingBufferIterator`.
- 2026-06-01: Filled validator-managed projected reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank despite the page and project tree already identifying `util/RingBuffer.cpp`.
  - After: set the projected folder to `NexusTK/util/` so validator-owned autogen can stage `RingBuffer.cpp` under the reconstructed root.
  - Evidence: this page's source-structure decision, [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md), and `by-project-structure/proposed-source-tree.md` all place the utility ring-buffer module in the util/threading container group.
- 2026-06-01: Added the expanded raw iterator-helper pocket from the memory-page rescore.
  - Evidence: IDA MCP disassembly found additional complete helper bodies at `0x00556750`, `0x00556770`, `0x00556780`, and `0x005567a0`, and corrected the raw iterator constructor endpoint to `0x005566eb`.
- 2026-06-03: Attached RingBuffer class pages.
  - Before: the file listed [UID:0000C1][RingBuffer](by-class/RingBuffer.md) and [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md), but both class pages were still unassigned in autogen metadata.
  - After: attached `RingBuffer` at position `10` and `RingBufferIterator` at position `20`; C++ remains blank for both.
  - Evidence: IDA MCP reconfirmed the shared code island, `RingBufferIterator` RTTI/COL and vtable, the raw constructor vptr store, and the unresolved direct-caller gap for iterator helper starts.
- 2026-06-07 A003 Batch 065: Raised confidence from `82` to `85` with a focused vtable-data parent-gate audit. Evidence is the already documented Thread caller set, shared ring-buffer code island, attached RingBuffer/RingBufferIterator classes, [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md), and exact [UID:0002OQ][0x006230c8-0x006230e8.RingBufferVtableData](by-memory/0x006230c8-0x006230e8.RingBufferVtableData.md) child. Completion remains `86`, and C++ remains blank because raw helper names and iterator source exposure are not final-code quality.
