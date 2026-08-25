*** UID:0000MM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PoolAllocator

## Status

- Proposed module: `util/PoolAllocator.cpp`
- Proposed header: `util/PoolAllocator.h`
- Confidence: strong for allocator behavior, method/helper ownership, public API shape, and caller groups; capped only by absent embedded filename/header proof and exact original global spellings.
- Primary class: [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md)

## File Role

`PoolAllocator.cpp` is the fixed-size block pool used by the ref-counted ANSI/UTF-16 string-buffer implementation and by object-pane, `Motion`, and `UserPane` static allocator instances. It keeps a chunk list, a free-block list, and an embedded `CRITICAL_SECTION`, then lazily allocates blocks in batches when the free list is empty.

The current generated source used to materialize only `PoolAllocator::Allocate` at `0x004b1400`, but B002's 2026-06-20 source-quality pass resolves the class declaration plus exact method/helper bodies. Treat old `class_PoolAllocator.cpp` and `class_ThreadSafeNodeList.cpp` output as partial/alias evidence only; the file route is the source owner for allocator mechanics.

The allocator is tracked with other shared storage helpers in [UID:0001QA][client_containers](by-meta/client_containers.md). Concrete static pools remain distributed: string-buffer pools with the string-buffer module, object-pane pools with their object-pane modules, `Motion` with animation code, and the large local user pane pool with [UID:0000P1][UserPane](by-file/UserPane.md).

## Likely Contents

- [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md)
- [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- public constructor `PoolAllocator::PoolAllocator(int blockSize, int blocksPerChunk)` at `0x004b13d0-0x004b1400`
- public allocator method `void *PoolAllocator::Allocate()` at `0x004b1400-0x004b14b8`
- free-list return helper at `0x004b14c0-0x004b14ef`
- compiler EH cleanup funclet/scaffold at `0x004b14f0-0x004b151e`; no source method
- public destructor `PoolAllocator::~PoolAllocator()` at `0x004b1520-0x004b1585`
- file-local chunk allocation helper `AllocatePoolChunk(PoolChunkHeader **chunkListHead, int blocksPerChunk, int blockSize)` at `0x00549bd0-0x00549bf1`
- chunk-list free helper at [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md)

The free-list return helper is also documented as [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md) because the machine-code behavior is a generic locked intrusive-list push. B002 resolves the final source-facing role as public `PoolAllocator::Free(void *block)`: 30 callers use PoolAllocator-shaped state and no non-pool caller group proves a standalone `ThreadSafeNodeList` owner. Keep `ThreadSafeNodeList` only as a generated/historical behavior alias.

## Range Inventory

| Item | Exact half-open range | Source disposition |
| --- | --- | --- |
| Constructor | `0x004b13d0-0x004b1400` | Authored public `PoolAllocator::PoolAllocator(int, int)`. |
| Allocate | `0x004b1400-0x004b14b8` | Authored public exception-safe `PoolAllocator::Allocate()`. |
| Free | `0x004b14c0-0x004b14ef` | Authored public null-tolerant `PoolAllocator::Free(void *)`. |
| EH cleanup | `0x004b14f0-0x004b151e` | Fifteen-instruction MSVC cleanup scaffold; no authored method. |
| Destructor | `0x004b1520-0x004b1585` | Authored public `PoolAllocator::~PoolAllocator()`. |
| AllocatePoolChunk | `0x00549bd0-0x00549bf1` | Authored file-local helper. |
| FreePoolChunkList | `0x00549c00-0x00549c18` | Authored file-local helper with a by-value cursor. |

Six protected `0xcc` padding items are non-source: `0x004b14b8-0x004b14c0`, `0x004b14ef-0x004b14f0`, `0x004b151e-0x004b1520`, `0x004b1585-0x004b1590`, `0x00549bf1-0x00549c00`, and `0x00549c18-0x00549c20`. The previously documented zero-length `0x004b1400-0x004b1400` interval was invalid and is superseded by this exact inventory.

## Evidence

- Historical pre-callback `class_PoolAllocator.meta_wave3`/Wave2 output supplied search leads for `blockSize`, `blocksPerChunk`, `chunkList`, `freeList`, and an embedded `CRITICAL_SECTION` at `+0x10`; current IDA and formal CPP/H are the authority.
- 2026-05-26 IDA MCP confirms `sub_4B13D0`, `sub_4B1400`, `sub_4B14C0`, and `sub_4B1520` as real functions in one compact allocator island, plus `sub_549BD0` as the non-contiguous chunk helper called from `0x004b1450`.
- 2026-05-28 IDA MCP confirms [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md) as the allocator-private chunk-list free loop called from `0x004b1553` inside the destructor/cleanup path.
- IDA decompilation shows `0x004b13d0` initializes the fixed-block dimensions and critical section.
- `0x004b1400` enters the lock, allocates a new chunk when `m_freeList` is null, chains all blocks onto the free list, pops one block, and returns it.
- `0x004b14c0` is directly called by `ReleaseAnsiBuffer` and `ReleaseWideBuffer` to return small ref-counted string buffers to the eight global pools.
- `0x004b1520` walks and frees the chunk list, clears `m_chunkList` and `m_freeList`, leaves the lock, and deletes the critical section.
- `AllocateAnsiBuffer` at `0x00582d80` and `AllocateWideBuffer` at `0x00582e30` call these pools for the 64/128/256/512 string-buffer buckets.
- Constructor xrefs at `0x0041a04c-0x0041a4bc` and destructor xrefs at `0x0060c320-0x0060c430` plus `0x0060c450` show nineteen [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md), including object-pane, `Motion`, `UserPane`, and string-buffer pools. `0x0060c440` is neighboring `UniAPIInit` cleanup, not an allocator destructor wrapper.
- 2026-06-11 Agent-A006 live IDA MCP recheck reconfirmed allocator island and helper bounds: `0x004b13d0` size `0x30`, `0x004b1400` size `0xb8`, `0x004b14c0` size `0x2f`, `0x004b1520` size `0x65`, `0x00549bd0` size `0x21`, and `0x00549c00` size `0x18`. Caller checks again show nineteen static constructor wrappers to `0x004b13d0`, object/string allocation users of `0x004b1400`, object/string/UserPane free users of `0x004b14c0`, and private helper calls from `0x004b1450` to `0x00549bd0` and from `0x004b1553` to `0x00549c00`.
- 2026-06-16 C001 live IDA MCP recheck reconfirmed those same bounds and caller groups, plus representative static instance xrefs for wide/ANSI string pools, UserPane, LivingObjectPane, and BalloonObjectPane pools. The active IDB now carries saved evidence-backed function names for the allocator mechanics: `PoolAllocator_Constructor`, `PoolAllocator_Allocate`, `PoolAllocator_Free`, `PoolAllocator_Destructor`, `PoolAllocator_AllocateChunk`, and `PoolAllocator_FreeChunkList`.
- 2026-06-20 B002 source-quality report cross-checked the same local PE evidence and identified the cleanup scaffold; the current exact exclusive end is `0x004b151e`. It also resolved `Free` as public, both chunk helpers as file-local, `PoolChunkHeader` and `PoolFreeBlock` as the source-facing helper records, and concrete static pool declarations as consumer-owned.

## Whole-File Xref Transpose

| Source entity | Incoming authority | Public direct-callee authority |
| --- | ---: | --- |
| Constructor `0x004b13d0` | `xref_query.total = 19` | `InitializeCriticalSection`. |
| Allocate `0x004b1400` | `xref_query.total = 33` | `EnterCriticalSection`, `AllocatePoolChunk`, `LeaveCriticalSection`, and the preserved runtime allocation/EH dependencies. |
| Free `0x004b14c0` | `xref_query.total = 30` | `EnterCriticalSection`, `LeaveCriticalSection`. |
| Destructor `0x004b1520` | `xref_query.total = 19` | `EnterCriticalSection`, `FreePoolChunkList`, `LeaveCriticalSection`, `DeleteCriticalSection`. |
| AllocatePoolChunk `0x00549bd0` | `xref_query.total = 1` | Public `callees` readback for the allocation primitive. |
| FreePoolChunkList `0x00549c00` | `xref_query.total = 2` | Public `callees` readback for the deallocation primitive. |

Incoming totals use `xref_query.total`, not modeled caller counts. Direct-callee sets use public `callees`, not aggregate profile lists.

## 2026-06-16 A001 File-Confidence Refresh

Live IDA MCP session `b001_mappane_0001AW_20260616` was used to recheck file/source-placement blockers and generated-output caveats:

- `lookup_funcs` now returns saved IDA names for all six allocator mechanics: `PoolAllocator_Constructor` `0x004b13d0` size `0x30`, `PoolAllocator_Allocate` `0x004b1400` size `0xb8`, `PoolAllocator_Free` `0x004b14c0` size `0x2f`, `PoolAllocator_Destructor` `0x004b1520` size `0x65`, `PoolAllocator_AllocateChunk` `0x00549bd0` size `0x21`, and `PoolAllocator_FreeChunkList` `0x00549c00` size `0x18`.
- `xrefs_to` reconfirmed `19` static constructor callers, `33` allocation callers, `30` free callers, `19` static destructor callers, one allocator-private call from `PoolAllocator_Allocate` to `PoolAllocator_AllocateChunk`, and destructor/internal cleanup refs to `PoolAllocator_FreeChunkList`.
- Callee/decompilation checks still show `Allocate` locking `+0x10`, allocating a chunk when `+0x0c` is empty, linking blocks by `blockSize`, popping the free list, and unlocking; `Free` null-checks and pushes the block to `+0x0c` under the lock; the destructor calls `PoolAllocator_FreeChunkList`, clears `+0x08/+0x0c`, unlocks, and deletes the critical section.
- `search_structs` found no local IDA UDT for `PoolAllocator`, and `find_regex` found no embedded `PoolAllocator.cpp` filename or RTTI string. The missing RTTI is consistent with a non-polymorphic utility, but final source placement still cannot be proven beyond the current utility/source-root hypothesis.

These checks justified the earlier file-confidence raise. B002's Rule 26 pass closes the public/private API naming issue and source-helper naming issue; the remaining confidence cap is only exact original standalone filename/header proof and final original global spellings, so first-draft C++ is now appropriate on the class and exact method/helper pages.

## 2026-07-29 B008 UID0002WS Gate 2B Shared-Helper Readback

- Supervisor catalog entry `0350` restored and saved the five regressed source-facing helper identities/types/function-regular comments while preserving `0x004b1400 PoolAllocator_Allocate` as exact no-change:
  - `0x004b13d0 PoolAllocator_Constructor`: `PoolAllocator *__thiscall(PoolAllocator *this, int blockSize, int blocksPerChunk)`; regular comment `Constructs a fixed-block PoolAllocator and initializes its embedded critical section.`
  - `0x004b1400 PoolAllocator_Allocate`: `void *__thiscall(PoolAllocator *this)`; no rename/type/comment write.
  - `0x004b14c0 PoolAllocator_Free`: `void __thiscall(PoolAllocator *this, void *block)`; regular comment `Returns a non-null block to this allocator's free list under its embedded critical section.`
  - `0x004b1520 PoolAllocator_Destructor`: `void __thiscall(PoolAllocator *this)`; regular comment `Destroys a PoolAllocator by freeing its chunk list and deleting its embedded critical section.`
  - `0x00549bd0 PoolAllocator_AllocateChunk`: `void *__cdecl(void **chunkListHead, int blocksPerChunk, int blockSize)`; regular comment `Allocates and prepends one PoolAllocator chunk containing blocksPerChunk fixed-size blocks.`
  - `0x00549c00 PoolAllocator_FreeChunkList`: `void __thiscall(void **chunkList)`; regular comment `Walks and frees a PoolAllocator chunk list.`
- Exact ranges, first items, bytes, xrefs, calling conventions, entry/repeatable comment channels, compiler wrappers, neighboring entities, and protected internal regular comments remain unchanged. The protected comments remain at `0x004b13e4`, `0x004b14d2`, `0x004b14de`, `0x004b1549`, `0x004b1550`, `0x004b1558`, `0x004b156d`, and `0x00549c07`, with repeatable channels blank.
- Persistent type application normalized only physical argument-frame labels: A02 now uses `blockSize` and `blocksPerChunk`; A04 uses `block`; A06 uses `chunkListHead`, `blocksPerChunk`, and `blockSize`. Supervisor rename-stack dry-run rejected raw-label restoration with literal `Argument member`; no unsafe frame reconstruction followed. Hex-Rays names/types, offsets, widths, nonargument frames, A05/A07 frames, and executable ABI are exact.
- Analysis UDT state is intentionally conservative: `PoolAllocator` remains opaque ordinal `444`, size `40`, one `_opaque : unsigned __int8[40]` member; already-present `PoolChunkHeader` ordinal `934` and `PoolFreeBlock` ordinal `935` remain size `4` with one self-pointer `next` member each. No UDT/member/comment was changed.
- The ItemObjectPane concrete instance now reads as one exact 40-byte `struct PoolAllocator g_itemObjectPanePool` item at `[0x0069b9ac,0x0069b9d4)` with accepted comments, forty unchanged zero bytes, five preserved base xrefs, and no checked interior xrefs or item heads. This does not move the consumer-owned static declaration into `PoolAllocator.cpp`.
- Saved IDB SHA256 `41977C87379D1A8BDC199A9A17DE3E117E365E3A596828DFA6FA0D7C2FA60DD3`, size `143190178`, last write `2026-07-29T03:12:58.7364596-04:00`; prestate backup `source-3/project-documentation/tools/leaser/Agents/ida-backups/NexusTK.exe.before-B008-UID0002WS-20260729-031039.i64`, SHA256 `B46BEB1B347B569129E0B9F9BB53C51E4560EF6249081256D31EAC53A95F1A41`.

## Source-Structure Decision

Use `util/PoolAllocator.cpp` as the working owner for the fixed-block pool. This code belongs beside shared utility/string/container infrastructure rather than any one caller, because the allocator is type-agnostic and currently proven through nineteen static pools spanning string buffers, object panes, `Motion`, and `UserPane`.

The ownership split is closed for reconstruction: this is not a private helper inside `StringUtil.cpp` or `StringBase.cpp`. Eleven of nineteen static pools are non-string consumers, and no consumer module owns the shared six-body allocator vocabulary.

Concrete static pool globals should not all be migrated into `PoolAllocator.cpp`. Keep the allocator mechanics here, but declare object-pane, `Motion`, `UserPane`, and string-buffer pool instances beside their consuming modules as tracked in [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md).

The current score is `94/94`: exact behavior, whole-file inventory, public API, file-local helpers, formal CPP/H routing, consumers, compiler exclusions, and source placement are complete. Exact historical filename/header spelling and private/global spellings remain inference-capped.

Source order is the class CPP prelude, constructor, Allocate, nested Free, destructor, AllocatePoolChunk, and FreePoolChunkList. [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md) is the sole H declaration/layout authority. Nineteen constructor wrappers, nineteen destructor wrappers, and eleven constructor-failure wrappers are compiler-generated consequences of the nineteen consumer-owned static declarations.

## Generated Output Caveats

- Historical pre-callback `class_PoolAllocator.cpp` emitted only `Allocate`, and historical metadata shortened its range to `0x004b14a1`. Those snapshots are superseded by the exact formal route and the current `[0x004b1400,0x004b14b8)` boundary.
- Historical `class_ThreadSafeNodeList.cpp` emitted `0x004b14c0` as `ThreadSafeNodeList::PushFront`; that remains search vocabulary only. Current source emits `PoolAllocator::Free` through UID000153 nested under UID000152.
- Historical generated output lacked complete address-scoped ownership for both non-contiguous helpers. The accepted class/by-memory emitter route now supplies all six authored bodies in `NexusTK/util/PoolAllocator.cpp` and the complete declaration in `PoolAllocator.h`.
- Dated generated snapshots are evidence only. Current acceptance requires a physical reread of validator-owned CPP/H output after the scoped validator refresh.

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

- 2026-08-22 B001 UID0000MM Gate 2A ordinary repair:
  - Consolidated the accepted standalone route, seven-row authored/compiler inventory, six real padding ranges, `19/33/30/19/1/2` xref transpose, public-callees authority, compiler-wrapper topology, source order, closed owner exclusions, `94/94` rationale, and generated-output disposition into the named active sections.
  - Superseded the active `class_PoolAllocator.cpp` label, cleanup end `0x004b151d`, `88/89` score, incomplete-output claims, and invalid zero-length padding without deleting their dated historical context.

- 2026-07-29 B008 UID0002WS Gate 2B support reconciliation:
  - Added exact catalog entry `0350` helper/type/comment/frame-normalization/target-item/save readback. Metadata, `NexusTK/util/` source route, distributed-static-instance decision, and existing source declarations remain unchanged.

- 2026-06-20 B002 Rule 26 source-quality incorporation:
  - Before: `87/86`, with source placement still hedged against StringBase/StringUtil/private container support and final C++ blocked by public/private API names.
  - After: `88/89`, keeping `NexusTK/util/PoolAllocator.cpp` as the allocator-mechanics source route.
  - Summary/evidence: B002 resolved public constructor/`Allocate`/`Free`/destructor API, file-local `AllocatePoolChunk` and `FreePoolChunkList` helper signatures, `PoolChunkHeader`/`PoolFreeBlock` helper records, `m_blockSize`/`m_blocksPerChunk`/`m_chunkList`/`m_freeList`/`m_lock` field names, `0x004b14f0-0x004b151d` compiler cleanup funclet treatment, current executable caller counts, distributed static-pool placement, rejection of `ThreadSafeNodeList`/StringBase/StringUtil/object-pane ownership alternatives, generated-output caveats, and first-draft C++ readiness through class and exact by-memory pages.
- 2026-06-01 reconstruction path fill-in:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank while the body proposed `util/PoolAllocator.cpp`.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: the page already documents `PoolAllocator` as shared utility/string infrastructure; this path gives allocator memory pages a valid file-level parent without promoting the ignored `ThreadSafeNodeList` alias.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents allocator role, likely contents, layout/static-instance evidence, IDA function boundaries, source-structure decision, generated-output caveats, and cross-references; confidence remains capped by final standalone-file split and `ThreadSafeNodeList` alias cleanup.
- 2026-06-11 Agent-A006 Batch 147 parent/source refresh:
  - Before: `CONFIDENCE:80`.
  - After: `CONFIDENCE:85`.
  - Summary/evidence: live IDA reconfirmed the allocator method/helper bounds and caller groups, including static constructor wrappers, allocation/free consumers, and private chunk helper ownership. The page now clears the strict parent/source confidence gate for allocator mechanics; concrete static pool globals remain distributed by consumer module per [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md).

- 2026-06-16 A001 Goal2 file-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`.
  - After: `COMPLETION:87`, `CONFIDENCE:86`.
  - Summary/evidence: current IDA MCP reconfirmed saved allocator function names, exact method/helper bounds, static constructor/allocate/free/destructor caller counts, private helper edges, decompiled allocator state transitions, no local UDT, no embedded source filename, and no RTTI string. Confidence remains conservative because standalone `PoolAllocator.cpp` versus private string/container support and final API names are unresolved.
