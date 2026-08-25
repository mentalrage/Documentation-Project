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
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) is a vtable-bearing dynamic-array template with an inline fallback record, used by render image libraries and `GameServerConfig`; the image-info destructor/accessor islands are documented at [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md), [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md), and [UID:000187][0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors](by-memory/0x004e5fa0-0x004e629f.ProtectedArrayImageInfoDeletingDestructors.md). Current generated `class_ProtectedArray_struct_*.cpp` files remain concrete template-instantiation views, not standalone original source modules.
- [UID:0000MW][Queue](by-file/Queue.md) is a fixed-slot circular queue with an `LObject` base and client memory-manager storage. Current Queue memory docs now provide formal child C++ for `Queue::Queue`, `Queue::~Queue`, `Queue::WriteSlot`, `Queue::ReadSlot`, and `Queue::IsEmpty`; the aggregate remains a non-emitting container/route page, and the scalar deleting destructor remains compiler-wrapper handling rather than hand-authored source.
- [UID:0000KR][LinkedList](by-file/LinkedList.md) is a path-`NONE`, non-emitting MSVC/Dinkumware `std::list<T>` support index for 8-byte-value node allocation, two-word payload nodes, and list-state cleanup used by frame scheduling, minimap versions, monster image caches, and DATIndexVector teardown. Source-facing reconstruction uses direct typed caller-owned `std::list<T>` containers rather than a hand-authored NexusTK `LinkedList.cpp`, wrapper, or raw overlay header. The distinct records are `MiniMapVersionRecord { int mapId; wchar_t* expectedVersionString; }`, `FrameScheduleEntry { FrameHandler* handler; uint32_t dueFrame; }`, `MonsterArchiveCacheEntry { int archiveIndex; void* archiveReaderOrDatHandle; }`, and a bounds-cache entry pairing `archiveIndex` with `MonsterArchiveBoundsBucket*`. The former MiniMap `mapKey`/`hashKey` and broad `versionText` labels are retained only as superseded historical binary-analysis aliases; renderer and manager evidence resolves `mapId` and `expectedVersionString`.
- [UID:000245][0x00578f70-0x005797ae.StlTreeStringMapSupport](by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md) covers the STL/Dinkumware wide-string ordered-tree helper subranges inside a mixed Socket/STL/runtime support tail; reconstruct owner containers in Socket/FriendNameListSync and VirusChecker, and do not port the generated tree helper bodies, Socket scalar deleting destructor, or CRT stdout wrapper as a standalone project module.
- [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) is a path-`NONE`, non-emitting semantic index for exact MSVC/Dinkumware vector and range-fill compiler lowerings, not a source file or generated class family. [UID:0000FD][UInt32Vector](by-class/UInt32Vector.md) and [UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md) are synthetic layout/history indexes. Direct exact pages UID00030Q, UID00030Z, UID0002UD, UID00050O, UID00050P, and UID0001B2 are compiler-covered, non-reconstructable, non-emitting evidence whose behavior belongs to typed caller-owned standard-container source.

## VectorHelpers Non-File Decision

The complete current VectorHelpers inventory contains shared four-byte grow/insert, pointer-slot copy construction, vector-storage destruction, inline-allocation grow/insert, optimized dword fill, and uint32 fill-construction lowerings. Their callers span fitting-room, ItemCatalog, JsonCpp, MiniMap, DAT managers, EventDispatcher, MapPane, WorldMapPane, and NewHuman code. No product symbol, source API, dedicated class, header declaration, global state, or feature ownership supports a handwritten `VectorHelpers.cpp` or `VectorHelpers.h`.

Reconstruction should preserve the real typed `std::vector<T>` declarations and operations in each owning module and use a compatible MSVC-era standard library/toolchain to reproduce equivalent binary behavior. Raw names such as `sub_*`, synthetic `UInt32Vector`, and descriptive helper titles remain documentation search labels only. The 56 callers of shared vector-throw support are an evidence surface, not 56 children or source methods under VectorHelpers.

Earlier generated-class/header and compatibility-template suggestions are retained in historical target pages only as corrected provenance. Current metadata uses blank emitters and blank CPP/H for every direct compiler-covered item, and `PROPOSED_RECONSTRUCTION_PATH:"NONE"` for the semantic by-file index.
- [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) tracks the `_AUTOBUF<unsigned char>` owning byte-buffer template used by startup media and look/profile packet parsing.
- [UID:0000IR][Deque](by-file/Deque.md) is a 4-byte-entry block deque used by traversal queues, handler maintenance, world-map reachability work, and SoundManager directory scans.
- [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md) is a source-complete retained utility/legacy fixed-entry table rooted at `NexusTK/util/CachedHashTable.cpp/.h`. Direct class owner [UID:00001F][CachedHashTable](by-class/CachedHashTable.md) now emits the exact constructor, ordinary destructor, byte-sum/modulo hash, clear/remove/get/set operations, count accessors, and private unchecked-address helper through exact by-memory children. The 0x1c layout, all alignment, unique/shared EH objects, complete RTTI/vtable graph, and compiler scalar-deleting wrapper are documented without false independent emitters. Exhaustive IDA/PE checks still find no surviving direct construction/caller route, so retained-legacy describes liveness only and does not reduce source completeness.
- [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md) is a small sieve/algorithm utility with an embedded [UID:0000IR][Deque](by-file/Deque.md); current IDA checks show no direct constructor callers, so treat it as utility/legacy support until a construction site is found. A raw indexed-prime accessor at `0x0054bcc0` and a non-emitted Deque element-address helper at `0x0054c0c0` are now documented separately.
- [UID:0000N8][RingBuffer](by-file/RingBuffer.md) is a blocking thread queue that uses `Monitor` / `MonitorCondition`.
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is a path-`NONE`, non-emitting index for a folded old-MSVC/Dinkumware `stdext::hash_map` implementation family, not a project class or standalone keyed-container source file. Exact pages retain the `0x20` private layout, paired bucket-range vector, list node, FNV-1a insertion/find, resize/fill, unwind and destruction evidence. Source ownership is consumer-local: FittingRoom uses its accepted byte-keyed standard container, MiniMap uses `stdext::hash_map<int, wchar_t *>`, MonsterImageLib uses `stdext::hash_map<int, DATFile *>` and `stdext::hash_map<int, MonsterArchiveBoundsBucket *>`, and DATFileMgr owns its typed resolver containers. Identical-COMDAT/template folding explains why one address family serves those different mapped types.
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) is a standalone fixed-block allocator rooted at `NexusTK/util/PoolAllocator.cpp` and `PoolAllocator.h`. It serves nineteen exact pools across map objects, rendering/motion, StringBase buffers, and UserPane; consumer modules own their static pool instances, not the allocator mechanics.
- [UID:0000L7][MemoryMan](by-file/MemoryMan.md) is the process heap/allocation policy wrapper: `MemoryMan` singleton, `operator_new`, `AllocateBufferMemory`, `FreeBufferMemory`, `ReallocateOrThrow`, zero-alloc, and copy wrappers.

## Source-Structure Guidance

Keep generic containers under `util/` unless a later original-source clue proves a narrower folder. Caller evidence alone should not move these helpers into feature modules: many are stack-local or embedded utility members used by UI, map, audio, archive, and startup code.

Do not merge these into one monolithic container file by default. The current proposed tree keeps separate source files because each helper has a distinct layout and ownership surface.

[UID:0000L7][MemoryMan](by-file/MemoryMan.md) is lower-level allocation infrastructure rather than a collection container, but it is listed here because most reusable containers eventually depend on its allocation/free/reallocation wrappers. Keep it under `util/` beside shared containers, not inside any feature module that happens to allocate frequently.

2026-05-26 recheck: current `simroot_v2` still splits MemoryMan helpers across one-class and one-global outputs. Prefer the IDA-backed MemoryMan docs over generated file boundaries when assigning container allocation dependencies.

## Open Questions

- Whether `Deque` had additional inlined pop/front helpers that should be documented from caller bodies. The first non-emitted helper now identified is [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md).
- The historical direct-`std::list` versus thin-wrapper question for the LinkedList/StdList overlays is closed for reconstruction: use direct caller-owned `std::list<T>`. Current UDT/function/string/generated/source checks found no wrapper symbol, header, API, source file, or unique wrapper contract; wrapper uncertainty remains only superseded history unless new contrary evidence appears.
- Whether `CachedHashTable` has an indirect construction route remains unproven; current best classification is source-authored retained utility/legacy code after no direct IDA or PE route was found.
- Whether `PrimeNumberGenerator` is used by a currently unmodeled caller or left over as unused utility code.
- The historical DATIndexVector folder question is closed: it has no standalone source path; retain only its non-emitting compiler-family documentation index and exact binary children.
- PoolAllocator placement is resolved: it is the standalone sibling utility `NexusTK/util/PoolAllocator.{h,cpp}`, not private StringBase support and not a ThreadSafeNodeList source unit. Exact original filename spelling remains inferred, but the ownership decision is closed for reconstruction.
- Whether final source should call the allocation module `MemoryMan.cpp`, `Memory.cpp`, or a runtime support source containing global `operator new`.
- Whether `ProtectedArray` was declared in a standalone `ProtectedArray.h` or bundled into a broader project container header.
- Whether `AUTOBUF` and `LineIterator` were standalone headers or local helpers emitted from template-heavy owner modules. `VectorHelpers` is resolved separately as a non-standalone path-`NONE` documentation index; no header or source artifact should be reconstructed. Current LineIterator evidence still favors a tiny helper used by `SpelledPane` parsing rather than a broad standalone source file.

## Cross-References

- [UID:0000KS][List](by-file/List.md)
- [UID:0000NU][SortedList](by-file/SortedList.md)
- [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md)
- [UID:0000JV][HierList](by-file/HierList.md)
- [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:00017V][0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors](by-memory/0x004e5a70-0x004e5b6f.ProtectedArrayImageInfoOrdinaryDestructors.md)
- [UID:000186][0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors](by-memory/0x004e5f20-0x004e5f95.ProtectedArrayImageInfoAccessors.md)
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

## 2026-08-22 UID0000MM Accepted Ownership Closure

- Authored source: [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md), with exact class/header authority [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md) and six authored bodies routed into `NexusTK/util/PoolAllocator.cpp`.
- Compiler alias exclusion: [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md) is `PoolAllocator::Free`; [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md) and [UID:0000EX][ThreadSafeNodeList](by-class/ThreadSafeNodeList.md) remain path-NONE/non-emitting historical alias indexes.
- Consumer boundary: [UID:0000OA][StringBase](by-file/StringBase.md) owns eight pool instances and string behavior, [UID:0000OB][StringUtil](by-file/StringUtil.md) is a sibling string utility, and object/render/UI modules own the other eleven pool instances. None owns allocator mechanics.
- Evidence closure: constructor/Allocate/Free/destructor and two file-local helpers, the exact `0x28` layout, 49 compiler wrappers, and nineteen cross-subsystem pools make private StringBase, generic StringUtil, object-pane, and ThreadSafeNodeList ownership inconsistent with the complete inventory.
