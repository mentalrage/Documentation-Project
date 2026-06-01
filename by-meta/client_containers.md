*** UID:0001QA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Containers

## Scope

This page tracks reusable collection/allocation primitives that cut across feature modules. Original-source ownership lives in `by-file`; exact address evidence lives in `by-memory`.

## Current Model

- [UID:0000KS][List](by-file/List.md) is the fixed-width dynamic array container used by render, UI, map, and resource systems.
- [UID:0000NU][SortedList](by-file/SortedList.md) extends `List` with a comparator callback and sorted insert/search helpers. Current `simroot_v2` output omits the real helpers at [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md) and `0x004f3780`, so migration should use the memory/class docs.
- [UID:0000JV][HierList](by-file/HierList.md) extends `List` with parent/child node headers for tree-shaped pane/layer state. Current `simroot_v2` output omits the non-deleting destructor, remove-node helper, and recursive find helper recorded in [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md).
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) is a vtable-bearing dynamic-array template with an inline fallback record, used by render image libraries and `GameServerConfig`; the image-info destructor/accessor islands are documented at [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000186][0x004e5f20-0x004e5f64.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f64.ProtectedArrayImageInfoAccessors.md), and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md). Current generated `class_ProtectedArray_struct_*.cpp` files remain concrete template-instantiation views, not standalone original source modules.
- [UID:0000MW][Queue](by-file/Queue.md) is a fixed-slot circular queue with an `LObject` base and client memory-manager storage. Current generated output still omits the raw write/read/empty helpers, so use the exact Queue memory docs for reconstruction.
- [UID:0000KR][LinkedList](by-file/LinkedList.md) is a tiny sentinel-based intrusive-list helper family: node allocation, two-word payload nodes, and list-state cleanup used by frame scheduling, minimap hashes, monster image archive bounds, and DATIndexVector teardown.
- [UID:000245][0x00578f70-0x005797ae.StlTreeStringMapSupport](by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md) covers MSVC STL/Dinkumware tree/string-map helper code that should be regenerated from owning C++ container declarations, not ported as handwritten NexusTK source.
- [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) tracks generated vector helper artifacts such as `UInt32Vector` and `RecordVector_4E57C0`.
- [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) tracks the `_AUTOBUF<unsigned char>` owning byte-buffer template used by startup media and look/profile packet parsing.
- [UID:0000IR][Deque](by-file/Deque.md) is a 4-byte-entry block deque used by traversal queues, handler maintenance, world-map reachability work, and SoundManager directory scans.
- [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md) is a fixed-entry hash/cache helper with entry and slot-state buffers; 2026-05-26 IDA checks show no direct callers and only lifecycle refs to the vtable, so treat it as a low-priority utility/legacy candidate that still needs replication for source completeness.
- [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md) is a small sieve/algorithm utility with an embedded [UID:0000IR][Deque](by-file/Deque.md); current IDA checks show no direct constructor callers, so treat it as utility/legacy support until a construction site is found. A raw indexed-prime accessor at `0x0054bcc0` and a non-emitted Deque element-address helper at `0x0054c0c0` are now documented separately.
- [UID:0000N8][RingBuffer](by-file/RingBuffer.md) is a blocking thread queue that uses `Monitor` / `MonitorCondition`.
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is a keyed value-table helper used by archive-adjacent and other lookup code.
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) is a fixed-block allocator used by the ref-counted string-buffer pool globals.
- [UID:0000L7][MemoryMan](by-file/MemoryMan.md) is the process heap/allocation policy wrapper: `MemoryMan` singleton, `operator_new`, `AllocateBufferMemory`, `FreeBufferMemory`, `ReallocateOrThrow`, zero-alloc, and copy wrappers.

## Source-Structure Guidance

Keep generic containers under `util/` unless a later original-source clue proves a narrower folder. Caller evidence alone should not move these helpers into feature modules: many are stack-local or embedded utility members used by UI, map, audio, archive, and startup code.

Do not merge these into one monolithic container file by default. The current proposed tree keeps separate source files because each helper has a distinct layout and ownership surface.

[UID:0000L7][MemoryMan](by-file/MemoryMan.md) is lower-level allocation infrastructure rather than a collection container, but it is listed here because most reusable containers eventually depend on its allocation/free/reallocation wrappers. Keep it under `util/` beside shared containers, not inside any feature module that happens to allocate frequently.

2026-05-26 recheck: current `simroot_v2` still splits MemoryMan helpers across one-class and one-global outputs. Prefer the IDA-backed MemoryMan docs over generated file boundaries when assigning container allocation dependencies.

## Open Questions

- Whether `Deque` had additional inlined pop/front helpers that should be documented from caller bodies. The first non-emitted helper now identified is [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md).
- Whether `LinkedList` was a standalone `LinkedList.cpp`, folded into `List.cpp`, or mostly header/inlined utility support in the original project.
- Whether `CachedHashTable` is unused legacy code or constructed from a currently unmodeled raw/indirect-code path.
- Whether `PrimeNumberGenerator` is used by a currently unmodeled caller or left over as unused utility code.
- Whether `DATIndexVector` belongs under `archive/`, `util/`, or a broader lookup/index helper folder in the final project tree.
- Whether `PoolAllocator` was standalone or private string-base support.
- Whether final source should call the allocation module `MemoryMan.cpp`, `Memory.cpp`, or a runtime support source containing global `operator new`.
- Whether `ProtectedArray` was declared in a standalone `ProtectedArray.h` or bundled into a broader project container header.
- Whether `AUTOBUF`, `VectorHelpers`, and `LineIterator` were standalone headers or local helpers emitted from template-heavy owner modules. Current LineIterator evidence still favors a tiny helper used by `SpelledPane` parsing rather than a broad standalone source file.

## Cross-References

- [UID:0000KS][List](by-file/List.md)
- [UID:0000NU][SortedList](by-file/SortedList.md)
- [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md)
- [UID:0000JV][HierList](by-file/HierList.md)
- [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md)
- [UID:000186][0x004e5f20-0x004e5f64.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f64.ProtectedArrayImageInfoAccessors.md)
- [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md)
- [UID:0000MW][Queue](by-file/Queue.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001V0][ListNode](by-type/by-struct/ListNode.md)
- [UID:0001UZ][LinkedListState](by-type/by-struct/LinkedListState.md)
- [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md)
- [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md)
- [UID:0000IR][Deque](by-file/Deque.md)
- [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md)
- [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md)
- [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md)
- [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md)
- [UID:0001VM][ProtectedArrayLayout](by-type/by-struct/ProtectedArrayLayout.md)
- [UID:0001TU][CachedHashTableLayout](by-type/by-struct/CachedHashTableLayout.md)
- [UID:0001VL][PrimeNumberGeneratorLayout](by-type/by-struct/PrimeNumberGeneratorLayout.md)
- [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
