*** UID:0001VK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000AM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PoolAllocatorLayout

## Status

- Entity kind: class layout support struct
- Confidence: strong for offsets, object size, source-facing field names, and helper record roles.
- Direct semantic owner: [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md); source-file route: [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md).
- Emission disposition: this support page remains reconstructable layout evidence but has blank emitter, position, CPP, and H channels. UID0000AM emits the class declaration exactly once.
- Current score: `94/94`; exact x86 offsets, size, overlays, consumer instances, and one declaration route are complete, while platform/compiler ABI and original formatting remain inference-capped.
- Evidence basis: IDA MCP `lookup_funcs` and decompilation of the allocator island, chunk helpers, string-pool users, plus the 2026-06-20 B002 Rule 26 source-quality report. Generated output remains only a lead/caveat source, not authority.

## Layout

```text
PoolAllocatorLayout
  +0x00  int32_t m_blockSize
  +0x04  int32_t m_blocksPerChunk
  +0x08  PoolChunkHeader* m_chunkList
  +0x0c  PoolFreeBlock* m_freeList
  +0x10  CRITICAL_SECTION m_lock
```

Observed object size is `0x28` bytes. The embedded `CRITICAL_SECTION` occupies `0x18` bytes on this build.

## IDA Verification Notes

- `lookup_funcs 0x004b13d0` reports size `0x30`; decompilation writes `blockSize` at `+0x00`, `blocksPerChunk` at `+0x04`, clears `chunkList`/`freeList` at `+0x08`/`+0x0c`, and calls `InitializeCriticalSection(this + 0x10)`.
- `lookup_funcs 0x004b1400` reports size `0xb8`; decompilation enters the critical section at `+0x10`, allocates a new chunk through [UID:0001F4][0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper](by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md) when `freeList` is empty, threads blocks through the first word of each free block, then pops `freeList`.
- `lookup_funcs 0x004b14c0` reports size `0x2f`; decompilation pushes a non-null freed block onto `freeList` under the same critical section.
- `lookup_funcs 0x004b1520` reports size `0x65`; decompilation enters the lock, frees the `chunkList`, clears both lists, leaves the lock, and calls `DeleteCriticalSection(this + 0x10)`.
- `lookup_funcs 0x00549bd0` and `0x00549c00` confirm the chunk-allocation and chunk-list-free helper sizes used by the core allocator methods.
- 2026-06-16 C001 live IDA MCP refresh reconfirmed the same offsets after applying safe function names in IDA: `PoolAllocator_Constructor`, `PoolAllocator_Allocate`, `PoolAllocator_Free`, `PoolAllocator_Destructor`, `PoolAllocator_AllocateChunk`, and `PoolAllocator_FreeChunkList`.
- 2026-06-16 representative static instance xrefs reconfirmed that every sampled static pool uses the same `0x28`-byte layout contract: wide string pool `0x0069bacc`, ANSI string pool `0x0069bb6c`, UserPane pool `0x0069bf34`, LivingObjectPane pool `0x0069b894`, and BalloonObjectPane pool `0x0069b9fc`.

## Helper Records

```text
PoolChunkHeader
  +0x00  PoolChunkHeader* next
  +0x04  first block byte

PoolFreeBlock
  +0x00  PoolFreeBlock* next
```

`PoolChunkHeader` is a whole-chunk header. The first client block begins immediately after the header, and the helper allocates `m_blocksPerChunk * m_blockSize + sizeof(PoolChunkHeader)` bytes. `PoolFreeBlock` overlays the first pointer-sized word of a block only while that block is on `m_freeList`; allocated blocks are caller-owned and do not carry a separate per-block allocator header.

Source-facing declaration ownership is intentionally centralized in [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md). This page records the layout contract and does not emit a duplicate struct/class block.

## Allocation Rules

- `PoolAllocator::Allocate` enters `m_lock`.
- If `m_freeList` is empty, it allocates one chunk containing `m_blocksPerChunk * m_blockSize + sizeof(PoolChunkHeader)` bytes.
- The newly allocated blocks are linked into `m_freeList` in reverse address order.
- Allocation pops the head of `m_freeList`.
- `PoolAllocator::Free` pushes a non-null block to `m_freeList` under the same lock.
- Destruction walks `m_chunkList`, frees each chunk allocation, clears both lists, and deletes the critical section.

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

## 2026-07-29 B008 UID0002WS Gate 2B Analysis-Type Readback

- Catalog entry `0350` deliberately preserves the IDA analysis type as opaque rather than replacing it with this source-facing layout: `PoolAllocator` remains ordinal `444`, size `40`, with exactly one `_opaque : unsigned __int8[40]` member. This page's five-field layout remains the evidence-backed source contract; the opaque IDA UDT avoids an unverified member/comment rewrite.
- The two helper records are now independently present and preserved: `PoolChunkHeader` ordinal `934`, size `4`, sole member `PoolChunkHeader *next` at `+0x00`; `PoolFreeBlock` ordinal `935`, size `4`, sole member `PoolFreeBlock *next` at `+0x00`. They were already present from accepted B009 UID0002WT Gate 2B and were not removed, redeclared, retyped, commented, or otherwise changed by B008.
- All six allocator functions read back with the expected source-facing identities and ABI-safe types. The five restored functions are `PoolAllocator_Constructor`, `PoolAllocator_Free`, `PoolAllocator_Destructor`, `PoolAllocator_AllocateChunk`, and `PoolAllocator_FreeChunkList`; `PoolAllocator_Allocate` remains exact no-change. Their accepted function-regular comments are present, while protected internal regular comments and blank repeatable channels remain unchanged.
- Persistent signature application normalized only physical argument-frame labels: constructor A02 uses `blockSize`/`blocksPerChunk`, free A04 uses `block`, and chunk allocator A06 uses `chunkListHead`/`blocksPerChunk`/`blockSize`. Supervisor rename-stack dry-run rejected raw-label restoration with literal `Argument member`; Hex-Rays names/types, calling conventions, offsets, widths, nonargument frames, A05/A07 frames, bytes, xrefs, and executable ABI remain exact.
- UID0002WS now reads as one exact 40-byte `struct PoolAllocator g_itemObjectPanePool` data item at `[0x0069b9ac,0x0069b9d4)` with accepted comments, forty preserved zero bytes, five base xrefs, and no checked interior xrefs or heads. This demonstrates the concrete layout width without changing this support page into a second source emitter.
- Saved IDB SHA256 `41977C87379D1A8BDC199A9A17DE3E117E365E3A596828DFA6FA0D7C2FA60DD3`, size `143190178`, last write `2026-07-29T03:12:58.7364596-04:00`; prestate backup `source-3/project-documentation/tools/leaser/Agents/ida-backups/NexusTK.exe.before-B008-UID0002WS-20260729-031039.i64`, SHA256 `B46BEB1B347B569129E0B9F9BB53C51E4560EF6249081256D31EAC53A95F1A41`.

## Source-Quality Notes

- The `ThreadSafeNodeList` alias was rechecked again through the B002 Rule 26 report. The helper at `0x004b14c0` uses `+0x0c` and `+0x10`, matching `m_freeList` and `m_lock`; the 30 confirmed caller groups are allocator returns, not proof of a separate list layout.
- Source-facing field names are now resolved as `m_blockSize`, `m_blocksPerChunk`, `m_chunkList`, `m_freeList`, and `m_lock`. They are supported by constructor writes, allocation/free transitions, destructor cleanup, and representative static-pool xrefs.
- `PoolAllocator` remains a standalone utility-owned layout, not private `StringBase`/`StringUtil` storage and not a concrete object-pane layout. Eight of nineteen static pools are string buffers; eleven are object-pane, `Motion`, or `UserPane` consumers.
- Final C++ declaration is emitted by the class page. This layout page stays prose-only to avoid duplicate generated declarations while still documenting helper records and field offsets for method pages.

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

- 2026-08-22 B001 UID0000MM Gate 2A ordinary repair:
  - Consolidated the exact `0x28` field layout, one-pointer private overlays, nineteen static users, blank formal/emitter disposition, direct UID0000AM owner, UID0000MM source route, and `94/94` rationale into Status, Layout, Helper Records, and Source-Quality Notes.
  - Removed the malformed callback appendix without changing metadata or formal channels.

- 2026-07-29 B008 UID0002WS Gate 2B support reconciliation:
  - Added exact catalog entry `0350` opaque/type-helper/function/frame-normalization/target-item/save readback while preserving `88/91`, the source-facing five-field contract, prose-only support disposition, and class-owned formal declaration.

- 2026-06-06: Attached the allocator layout to [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md). Scores remain `84/88`; this parent metadata update follows the already documented class ownership and allocator method evidence.
- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank, and the evidence basis still cited generated `class_PoolAllocator` output as if it were primary evidence.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `84`, confidence `88`, with IDA MCP evidence as the stated authority.
- Evidence: IDA MCP verified the constructor, allocate, free, destructor, chunk-allocation helper, and chunk-free helper offsets and behavior. Scores remain below `95+` because final public/private names, complete static-pool source placement, and all concrete pool owner declarations still need a full source-structure audit.
- 2026-06-16 C001 PoolAllocator refresh:
  - Before: `84/88`.
  - After: `86/90`.
  - Summary/evidence: live IDA MCP reconfirmed all allocator offsets, representative static pool xref patterns, and the `ThreadSafeNodeList` alias as allocator-shaped free-list use. IDA function names were safely updated for allocator mechanics, but no struct/member/prototype edit was made because final field names and source declaration placement remain provisional.
- 2026-06-20 B002 Rule 26 source-quality incorporation:
  - Before: `86/90`, with final field names still described as provisional and declaration emission still blocked.
  - After: `88/91`, with source-facing field names, helper record names, and overlay semantics accepted.
  - Summary/evidence: B002's report incorporated current executable caller counts, exact allocator method/helper boundaries, public `PoolAllocator::Free` resolution, standalone utility ownership over StringBase/StringUtil/ThreadSafeNodeList alternatives, `PoolChunkHeader` and `PoolFreeBlock` helper records, and the decision that [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md) emits the declaration while this layout page remains a support contract.
