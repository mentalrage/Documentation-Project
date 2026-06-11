*** UID:0000AM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PoolAllocator

## Summary

`PoolAllocator` is a fixed-size, thread-safe block pool. It batches allocations into chunks, links individual blocks through their first pointer-sized word, and protects both chunk/free-list mutation with an embedded `CRITICAL_SECTION`.

The currently proven consumers are the ref-counted string-buffer pools used by the ANSI and UTF-16 string helpers, plus object-pane, `Motion`, and `UserPane` static pools inventoried in [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md).

## Likely Original Placement

- Source: [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- Proposed path: `util/PoolAllocator.cpp`
- Confidence: medium for standalone file, strong for utility ownership

## Observed Layout

See [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md).

```text
+0x00  int blockSize
+0x04  int blocksPerChunk
+0x08  PoolChunkHeader* chunkList
+0x0c  PoolFreeBlock* freeList
+0x10  CRITICAL_SECTION lock
```

Observed object size is `0x28` bytes.

## Methods

| Address | Working name | Role |
| --- | --- | --- |
| `0x004b13d0-0x004b13ff` | `PoolAllocator::PoolAllocator` / `Init` | Stores block size/count, clears lists, initializes the critical section. |
| `0x004b1400-0x004b14b7` | `PoolAllocator::Allocate` | Pops a block, allocating and linking a new chunk if needed. |
| `0x004b14c0-0x004b14ef` | `PoolAllocator::Free` / `PushFreeBlock` | Pushes a non-null block back onto `freeList` under the lock. Also generated as `ThreadSafeNodeList::PushFront`. |
| `0x004b1520-0x004b1584` | `PoolAllocator::~PoolAllocator` / `Destroy` | Frees all chunks, clears lists, and deletes the critical section. |
| `0x00549bd0-0x00549bf1` | `AllocatePoolChunk` | Allocator-private helper that allocates and links a new chunk. |
| [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md) | `FreePoolChunkList` | Allocator-private helper that walks and frees the chunk list. |

## Evidence

- `source-3/simroot_v2/class_PoolAllocator.cpp` materializes `Allocate` with the same five-field layout.
- 2026-05-26 IDA MCP confirms the neighboring constructor/free/destructor starts in the same local island and the helper at `0x00549bd0`.
- IDA xrefs tie eight global string-buffer pools at `0x0069bacc-0x0069bbe4` to the constructor/destructor helpers and to the string allocation/free routines.
- IDA xrefs to `0x004b13d0` include constructor wrappers from `0x0041a040` through `0x0041a260` and `0x0041a4b0`; xrefs to `0x004b1520` include matching static cleanup wrappers from `0x0060c320` through `0x0060c430` and `0x0060c450`.
- Decompiling those wrappers identifies nineteen static instances: eleven object/class pools and eight string-buffer pools.
- `0x0060c440` is the neighboring `UniAPIInit` cleanup wrapper and should not be included in the allocator cleanup set.
- `0x00549bd0` has an IDA xref only from `0x004b1450` inside `PoolAllocator::Allocate`, supporting allocator-private ownership.
- `0x00549c00` has an IDA xref from `0x004b1553` inside `PoolAllocator::~PoolAllocator` / `Destroy`, supporting allocator-private ownership.

## Open Questions

- Whether the original source exposed `Free` as a public `PoolAllocator` method, a private helper, or compiled it from a small embedded list helper.
- Whether the final source file was standalone `PoolAllocator.cpp` or private support inside the original string-base module.
- Final source names for the concrete static pool globals.

## Cross-References

- File: [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- Memory: [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md)
- Helper memory: [UID:0001F4][0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper](by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md)
- Helper memory: [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md)
- Layout: [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- Globals: [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- Static constructors: [UID:0000WC][0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers](by-memory/0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md)
- Static destructors: [UID:0001O8][0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers](by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md)
- Globals: [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- Related: [UID:0000OB][StringUtil](by-file/StringUtil.md), [UID:0000EX][ThreadSafeNodeList](by-class/ThreadSafeNodeList.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and assigned parent `0000MM`.
  - Before: reconstruction autogen classification and parent were blank despite allocator mechanics, helper, static-instance, and layout documentation.
  - After: classified as reconstructable source attached to [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md).
  - Evidence: live IDA MCP `lookup_funcs` confirms modeled starts at `0x004b13d0`, `0x004b1400`, `0x004b14c0`, `0x004b1520`, `0x00549bd0`, and `0x00549c00`; the page documents fixed-block allocation/free/destruction behavior and source placement under `NexusTK/util/`. The class score is `86/82` and parent file score is `86/80`, satisfying the 80/80 attach gate.

- Before: completion/confidence metadata were `0/0` even though the page documented allocator responsibility, layout, methods, helpers, static instances, constructor/destructor wrappers, and open questions.
- Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
- Evidence: block/chunk/free-list structure, `CRITICAL_SECTION` layout, allocation/free/destroy paths, chunk helpers, nineteen static instances, string/object/user-pane pool usage, and ignored `ThreadSafeNodeList` alias relationship are documented; confidence remains below maximum because final public/private helper names and exact original source placement are still open.
