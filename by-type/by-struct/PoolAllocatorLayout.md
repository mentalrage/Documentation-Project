*** UID:0001VK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000AM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PoolAllocatorLayout

## Status

- Entity kind: class layout support struct
- Confidence: strong for offsets and object size, medium for final field names.
- Proposed owner: [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- Autogen parent: attached to [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md); the class scores `86/82` and this layout scores `84/88`, so both sides satisfy the 80/80 parent gate.
- Evidence basis: IDA MCP `lookup_funcs` and decompilation of the allocator island, chunk helpers, and string-pool users. Generated `simroot_v2` output remains only a lead/caveat source, not authority.

## Layout

```text
PoolAllocatorLayout
  +0x00  int32_t blockSize
  +0x04  int32_t blocksPerChunk
  +0x08  PoolChunkHeader* chunkList
  +0x0c  PoolFreeBlock* freeList
  +0x10  CRITICAL_SECTION lock
```

Observed object size is `0x28` bytes. The embedded `CRITICAL_SECTION` occupies `0x18` bytes on this build.

## IDA Verification Notes

- `lookup_funcs 0x004b13d0` reports size `0x30`; decompilation writes `blockSize` at `+0x00`, `blocksPerChunk` at `+0x04`, clears `chunkList`/`freeList` at `+0x08`/`+0x0c`, and calls `InitializeCriticalSection(this + 0x10)`.
- `lookup_funcs 0x004b1400` reports size `0xb8`; decompilation enters the critical section at `+0x10`, allocates a new chunk through [UID:0001F4][0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper](by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md) when `freeList` is empty, threads blocks through the first word of each free block, then pops `freeList`.
- `lookup_funcs 0x004b14c0` reports size `0x2f`; decompilation pushes a non-null freed block onto `freeList` under the same critical section.
- `lookup_funcs 0x004b1520` reports size `0x65`; decompilation enters the lock, frees the `chunkList`, clears both lists, leaves the lock, and calls `DeleteCriticalSection(this + 0x10)`.
- `lookup_funcs 0x00549bd0` and `0x00549c00` confirm the chunk-allocation and chunk-list-free helper sizes used by the core allocator methods.

## Helper Records

```text
PoolChunkHeader
  +0x00  PoolChunkHeader* nextChunk
  +0x04  first block byte

PoolFreeBlock
  +0x00  PoolFreeBlock* nextFreeBlock
```

Free blocks are threaded through the first pointer-sized word of each returned block. Allocated blocks are caller-owned and do not carry a separate allocator header.

## Allocation Rules

- `PoolAllocator::Allocate` enters `lock`.
- If `freeList` is empty, it allocates one chunk containing `blocksPerChunk * blockSize + sizeof(PoolChunkHeader)` bytes.
- The newly allocated blocks are linked into `freeList` in reverse address order.
- Allocation pops the head of `freeList`.
- Free-list return pushes a non-null block to `freeList` under the same lock.
- Destruction walks `chunkList`, frees each chunk allocation, clears both lists, and deletes the critical section.

## Confirmed String Pool Instances

The recovered string implementation uses eight static `PoolAllocatorLayout` instances for 64/128/256/512 buckets. These are confirmed string-buffer users, not the complete inventory of PoolAllocator globals in the binary.

| Address | Use |
| --- | --- |
| `0x0069bacc` | wide string 64 bucket |
| `0x0069baf4` | wide string 128 bucket |
| `0x0069bb1c` | wide string 256 bucket |
| `0x0069bb44` | wide string 512 bucket |
| `0x0069bb6c` | ANSI string 64 bucket |
| `0x0069bb94` | ANSI string 128 bucket |
| `0x0069bbbc` | ANSI string 256 bucket |
| `0x0069bbe4` | ANSI string 512 bucket |

Each pool occupies `0x28` bytes and matches this layout.

## Additional Static Instances

IDA xrefs to the constructor at `0x004b13d0` show nineteen static constructor wrappers, and xrefs to the destructor at `0x004b1520` show nineteen matching cleanup wrappers at `0x0060c320-0x0060c430` and `0x0060c450`. The eight string pools above are only the subset currently tied to `AllocateAnsiBuffer`, `AllocateWideBuffer`, `ReleaseAnsiBuffer`, and `ReleaseWideBuffer`.

The full current inventory is tracked in [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md), including object-pane, `Motion`, and `UserPane` pools.

## Cross-References

- [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md)
- [UID:0001F4][0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper](by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- [UID:0000WC][0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers](by-memory/0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md)
- [UID:0001O8][0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers](by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)

## Changes

- 2026-06-06: Attached the allocator layout to [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md). Scores remain `84/88`; this parent metadata update follows the already documented class ownership and allocator method evidence.
- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank, and the evidence basis still cited generated `class_PoolAllocator` output as if it were primary evidence.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `84`, confidence `88`, with IDA MCP evidence as the stated authority.
- Evidence: IDA MCP verified the constructor, allocate, free, destructor, chunk-allocation helper, and chunk-free helper offsets and behavior. Scores remain below `95+` because final public/private names, complete static-pool source placement, and all concrete pool owner declarations still need a full source-structure audit.
