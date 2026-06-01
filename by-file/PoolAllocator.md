*** UID:0000MM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PoolAllocator

## Status

- Proposed module: `util/PoolAllocator.cpp`
- Proposed header: `util/PoolAllocator.h`
- Confidence: strong for allocator behavior and ownership of the method island, medium for final standalone file split.
- Current generated source label: `class_PoolAllocator.cpp`
- Primary class: [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md)

## File Role

`PoolAllocator.cpp` is the fixed-size block pool used by the ref-counted ANSI/UTF-16 string-buffer implementation and by additional static allocator instances still being classified. It keeps a chunk list, a free-block list, and an embedded `CRITICAL_SECTION`, then lazily allocates blocks in batches when the free list is empty.

The current generated source only materializes `PoolAllocator::Allocate` at `0x004b1400`, but IDA shows the allocator family includes constructor/init, free-list return, destructor/cleanup, and chunk allocation helpers. Treat `class_PoolAllocator.cpp` as partial generated evidence, not full source coverage.

The allocator is tracked with other shared storage helpers in [UID:0001QA][client_containers](by-meta/client_containers.md), while its concrete current user is the string-buffer pool family.

## Likely Contents

- [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md)
- [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- constructor/init at `0x004b13d0-0x004b13ff`
- allocate at `0x004b1400-0x004b14b7`
- free-list return helper at `0x004b14c0-0x004b14ef`
- destructor/cleanup at `0x004b1520-0x004b1584`
- chunk allocation helper at `0x00549bd0-0x00549bf1`
- chunk-list free helper at [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md)

The free-list return helper is also documented as [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md) because the machine-code behavior is a generic locked intrusive-list push. Current IDA xrefs make `PoolAllocator::Free` the stronger owner for the string-pool call sites; keep `ThreadSafeNodeList` as an alias until non-allocator users are proven.

## Evidence

- `class_PoolAllocator.meta_wave3` imports `PoolAllocator` from Wave2 with layout notes: `blockSize`, `blocksPerChunk`, `chunkList`, `freeList`, and an embedded `CRITICAL_SECTION` at `+0x10`.
- 2026-05-26 IDA MCP confirms `sub_4B13D0`, `sub_4B1400`, `sub_4B14C0`, and `sub_4B1520` as real functions in one compact allocator island, plus `sub_549BD0` as the non-contiguous chunk helper called from `0x004b1450`.
- 2026-05-28 IDA MCP confirms [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md) as the allocator-private chunk-list free loop called from `0x004b1553` inside the destructor/cleanup path.
- IDA decompilation shows `0x004b13d0` initializes the fixed-block dimensions and critical section.
- `0x004b1400` enters the lock, allocates a new chunk when `m_freeList` is null, chains all blocks onto the free list, pops one block, and returns it.
- `0x004b14c0` is directly called by `ReleaseAnsiBuffer` and `ReleaseWideBuffer` to return small ref-counted string buffers to the eight global pools.
- `0x004b1520` walks and frees the chunk list, clears `m_chunkList` and `m_freeList`, leaves the lock, and deletes the critical section.
- `AllocateAnsiBuffer` at `0x00582d80` and `AllocateWideBuffer` at `0x00582e30` call these pools for the 64/128/256/512 string-buffer buckets.
- Constructor xrefs at `0x0041a04c-0x0041a4bc` and destructor xrefs at `0x0060c320-0x0060c430` plus `0x0060c450` show nineteen [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md), including object-pane, `Motion`, `UserPane`, and string-buffer pools. `0x0060c440` is neighboring `UniAPIInit` cleanup, not an allocator destructor wrapper.

## Source-Structure Decision

Use `util/PoolAllocator.cpp` as the working owner for the fixed-block pool. This code belongs beside shared utility/string infrastructure rather than any one caller, because the allocator is type-agnostic and currently proven through the string-buffer globals plus other static allocator wrappers.

If later evidence shows this was a private helper inside `StringUtil.cpp` or `StringBase.cpp`, keep this file doc as an ownership alias and move the class/type docs under that module.

Concrete static pool globals should not all be migrated into `PoolAllocator.cpp`. Keep the allocator mechanics here, but declare object-pane, `Motion`, `UserPane`, and string-buffer pool instances beside their consuming modules as tracked in [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md).

## Generated Output Caveats

- Active `class_PoolAllocator.cpp` only emits `PoolAllocator::Allocate`; it omits address-scoped constructor/init, free-list return, destructor/cleanup, and static string-pool constructor/destructor records.
- `class_PoolAllocator.meta_wave3` reports an active method range ending at `0x004b14a1`, while IDA reports `sub_4B1400` size `0xb8`.
- Active `class_ThreadSafeNodeList.cpp` emits `0x004b14c0` as `ThreadSafeNodeList::PushFront`. Keep that label as a behavior alias, but do not lose the `PoolAllocator::Free`/free-list-return interpretation for allocator call sites.
- Active generated source materializes the chunk allocator as a synthetic `AllocatePoolChunk` helper inside `class_PoolAllocator.cpp`, but there is no scoped install/address ownership for the real helper at `0x00549bd0`.

## Cross-References

- [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md)
- [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md)
- [UID:0001F4][0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper](by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md)
- [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md)
- [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- [UID:0000WC][0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers](by-memory/0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md)
- [UID:0001O8][0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers](by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-06-01 reconstruction path fill-in:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank while the body proposed `util/PoolAllocator.cpp`.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: the page already documents `PoolAllocator` as shared utility/string infrastructure; this path gives allocator memory pages a valid file-level parent without promoting the ignored `ThreadSafeNodeList` alias.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents allocator role, likely contents, layout/static-instance evidence, IDA function boundaries, source-structure decision, generated-output caveats, and cross-references; confidence remains capped by final standalone-file split and `ThreadSafeNodeList` alias cleanup.
