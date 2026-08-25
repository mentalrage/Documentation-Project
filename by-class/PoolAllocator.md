*** UID:0000AM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "PoolAllocator.h"

#include <new>

struct PoolChunkHeader
{
    PoolChunkHeader *next;
};

struct PoolFreeBlock
{
    PoolFreeBlock *next;
};

static PoolChunkHeader *AllocatePoolChunk(
    PoolChunkHeader **chunkListHead,
    int blocksPerChunk,
    int blockSize);
static void FreePoolChunkList(PoolChunkHeader *chunkList);

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_POOLALLOCATOR_H
#define NEXUSTK_UTIL_POOLALLOCATOR_H

#include <windows.h>

struct PoolChunkHeader;
struct PoolFreeBlock;

class PoolAllocator
{
public:
    PoolAllocator(int blockSize, int blocksPerChunk);
    ~PoolAllocator();

    void *Allocate();
    void Free(void *block);

private:
    int m_blockSize;
    int m_blocksPerChunk;
    PoolChunkHeader *m_chunkList;
    PoolFreeBlock *m_freeList;
    CRITICAL_SECTION m_lock;
};

typedef char PoolAllocatorSizeMustBe40[
    sizeof(PoolAllocator) == 0x28 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PoolAllocator

## Summary

`PoolAllocator` is a fixed-size, thread-safe block pool in [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md). It batches allocations into chunks, links reusable blocks through their first pointer-sized word, and protects chunk/free-list mutation with an embedded `CRITICAL_SECTION`.

The allocator mechanics are source-routed to `NexusTK/util/PoolAllocator.cpp`. Concrete static pool globals stay with their consuming modules: object-pane pools with object-pane modules, the `Motion` pool with animation/motion code, the `UserPane` pool with [UID:0000P1][UserPane](by-file/UserPane.md), and string-buffer pools with the string-buffer support module. [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) owns allocator mechanics only, not every concrete static pool declaration.

## Source Placement

- Source: [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- Proposed path: `util/PoolAllocator.cpp`
- Proposed header: `util/PoolAllocator.h`
- Confidence: strong for standalone utility ownership and behavior, capped only by the lack of embedded filename/header proof and exact original global spellings.
- Generated caveats: historical pre-callback `class_PoolAllocator.cpp` emitted only `Allocate`, and historical `class_ThreadSafeNodeList.cpp` misrouted the free-list return body. The accepted formal route now emits the complete CPP/H pair under `NexusTK/util/`.

Rejected owner alternatives:

- Private `StringBase.cpp` or `StringUtil.cpp`: rejected because only eight of nineteen static pools are string-buffer pools and the allocator mechanics fan out through object-pane, `Motion`, and `UserPane` consumers.
- A concrete object-pane owner: rejected because the same allocator mechanics serve many unrelated concrete modules.
- `ThreadSafeNodeList.cpp`: rejected because no standalone list layout, constructor, destructor, or non-pool caller group is proven; the body uses PoolAllocator offsets `+0x0c/+0x10`.
- No-owner/non-emitting: rejected because a valid shared utility owner, exact allocator methods, layout, helper records, and C++ declaration are now documented.

## Public API

| Address | Source-facing method | Evidence |
| --- | --- | --- |
| `0x004b13d0-0x004b1400` | `PoolAllocator::PoolAllocator(int blockSize, int blocksPerChunk)` | Nineteen static constructor-wrapper callers; stores dimensions, clears lists, initializes `CRITICAL_SECTION`. |
| `0x004b1400-0x004b14b8` | `void *PoolAllocator::Allocate()` | Thirty-three allocation callers; locks, lazily allocates a chunk, threads free blocks, pops the head block, unlocks. |
| `0x004b14c0-0x004b14ef` | `void PoolAllocator::Free(void *block)` | Thirty external return callers across string, object-pane, `Motion`, and `UserPane` pools; null-checks and pushes through the block's first word under the lock. |
| `0x004b1520-0x004b1585` | `PoolAllocator::~PoolAllocator()` | Nineteen static cleanup-wrapper callers; locks, frees all chunks, clears lists, unlocks, deletes `CRITICAL_SECTION`. |

`Free` is public, not private: it has 30 external call sites, is semantically paired with `Allocate`, null-checks input, and is used by string release helpers plus object-pane, `Motion`, `UserPane`, and BalloonObjectPane-related pool return paths.

## File-Local Helpers

| Address | Source-facing helper | Evidence |
| --- | --- | --- |
| `0x00549bd0-0x00549bf1` | `static PoolChunkHeader *AllocatePoolChunk(PoolChunkHeader **chunkListHead, int blocksPerChunk, int blockSize)` | Sole direct caller at `0x004b1450` inside `PoolAllocator::Allocate`; allocation size is `blocksPerChunk * blockSize + sizeof(PoolChunkHeader)`, then helper prepends the chunk. |
| `0x00549c00-0x00549c18` | `static void FreePoolChunkList(PoolChunkHeader *chunkList)` | Destructor call at `0x004b1553` and compiler cleanup ref at `0x004b1501`; walks first-dword chunk links and frees whole chunks. |

`0x004b14f0-0x004b151e` is not a source API. It is a fifteen-instruction MSVC EH cleanup funclet/scaffold between `Free` and the destructor; local PE checks found no function object or xref at `0x004b14f0`, while `0x0065cb1c -> 0x004b14a2` supplies the cleanup-landing evidence. Its `0x004b1501` reference to `FreePoolChunkList` is cleanup metadata/effect, not proof of a second public/private allocator method.

## Layout

See [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md).

```text
+0x00  int m_blockSize
+0x04  int m_blocksPerChunk
+0x08  PoolChunkHeader *m_chunkList
+0x0c  PoolFreeBlock *m_freeList
+0x10  CRITICAL_SECTION m_lock
```

Observed object size is `0x28` bytes. The embedded `CRITICAL_SECTION` occupies `0x18` bytes.

Helper records:

```cpp
struct PoolChunkHeader
{
    PoolChunkHeader *next;
};

struct PoolFreeBlock
{
    PoolFreeBlock *next;
};
```

`PoolChunkHeader` is a whole-chunk header; the first client block begins at `chunk + sizeof(PoolChunkHeader)`. `PoolFreeBlock` overlays the first word of a block only while that block is on the free list. Allocated blocks do not carry per-block allocator headers.

## Evidence

- Local executable scan against `NexusTK.exe` verified code reference counts: 19 rel32 constructor-wrapper calls to `0x004b13d0`, 33 allocation calls to `0x004b1400`, 30 free/return calls to `0x004b14c0`, 19 destructor-wrapper calls to `0x004b1520`, one `AllocatePoolChunk` caller from `0x004b1450`, and two `FreePoolChunkList` refs at `0x004b1501` and `0x004b1553`.
- Representative static pool absolute refs were rechecked: wide string 64 pool `0x0069bacc`, ANSI string 64 pool `0x0069bb6c`, UserPane pool `0x0069bf34`, LivingObjectPane pool `0x0069b894`, and BalloonObjectPane pool `0x0069b9fc`.
- `0x004b13d0-0x004b1400`: constructor stores block size/count, clears free/chunk lists, and initializes `CRITICAL_SECTION`.
- `0x004b1400-0x004b14b8`: `Allocate` uses MSVC EH/cookie scaffolding around lock handling, lazily allocates and reverse-threads blocks when free list is empty, pops free-list head, and unlocks.
- `0x004b14c0-0x004b14ef`: `Free` null-checks, locks, stores old `m_freeList` into the returned block's first word, updates `m_freeList`, and unlocks.
- `0x004b14f0-0x004b151e`: fifteen-instruction compiler EH cleanup funclet that frees/clears chunk/free lists under lock without deleting the critical section. Do not model it as source `Clear()` or a public/private helper.
- `0x004b1520-0x004b1585`: destructor locks, calls `FreePoolChunkList`, clears lists, unlocks, and deletes the critical section.
- `0x00549bd0-0x00549bf1`: cdecl-shaped chunk allocation helper with argument order `(PoolChunkHeader **chunkListHead, int blocksPerChunk, int blockSize)`.
- `0x00549c00-0x00549c18`: ecx/thiscall-shaped binary helper, source-facing file-local `FreePoolChunkList(PoolChunkHeader *chunkList)`.
- Negative checks found no source filename, RTTI, or local IDA UDT proving exact original filename/header. This caps confidence below final audit but does not block source routing or first-draft C++.
- `CriticalSectionLock` exists elsewhere, but allocator methods directly call `EnterCriticalSection` / `LeaveCriticalSection`; no allocator call to the `CriticalSectionLock` constructor/destructor pair was found, so the draft should not force that guard abstraction.

## Static Pool Placement

Concrete static pools should use descriptive names in support docs and IDA comments while staying with their owning modules:

| Address | Recommended descriptive name | Owner placement |
| --- | --- | --- |
| `0x0069b9fc` | `g_balloonObjectPanePool` | BalloonObjectPane module |
| `0x0069b95c` | `g_damageNumberObjectPanePool` | DamageNumberObjectPane module |
| `0x0069b90c` | `g_effectObjectPanePool` | EffectObjectPane module |
| `0x0069b9d4` | `g_flyingObjectPanePool` | FlyingObjectPane module |
| `0x0069b934` | `g_hitBarObjectPanePool` | HitBarObjectPane module |
| `0x0069b9ac` | `g_itemObjectPanePool` | ItemObjectPane module |
| `0x0069b894` | `g_livingObjectPanePool` | LivingObjectPane module |
| `0x0069b984` | `g_motionPool` | Motion module |
| `0x0069b8e4` | `g_soundObjectPanePool` | SoundObjectPane module |
| `0x0069b8bc` | `g_staticObjectPanePool` | StaticObjectPane module |
| `0x0069bf34` | `g_userPanePool` | UserPane module |
| `0x0069bb94` | `g_ansiPool128` | string-buffer module |
| `0x0069baf4` | `g_widePool128` | string-buffer module |
| `0x0069bbbc` | `g_ansiPool256` | string-buffer module |
| `0x0069bb1c` | `g_widePool256` | string-buffer module |
| `0x0069bbe4` | `g_ansiPool512` | string-buffer module |
| `0x0069bb44` | `g_widePool512` | string-buffer module |
| `0x0069bb6c` | `g_ansiPool64` | string-buffer module |
| `0x0069bacc` | `g_widePool64` | string-buffer module |

The string names are already established in string global support docs. The object/Motion/UserPane names are descriptive inferred names, not original-name proof; they are still preferable to raw `dword_` labels when kept with that caveat.

## 2026-07-29 B008 UID0002WS Gate 2B IDA Readback

- Catalog entry `0350` preserves the source declaration and behavior while restoring exact analysis identities. `PoolAllocator` remains opaque analysis ordinal `444`, size `40`, sole `_opaque : unsigned __int8[40]`; already-present `PoolChunkHeader` ordinal `934` and `PoolFreeBlock` ordinal `935` remain size `4`, each with sole self-pointer `next` member at `+0x00`. No type/member/comment mutation was performed.
- Exact current function readback is:
  - `0x004b13d0 PoolAllocator_Constructor`, `PoolAllocator *__thiscall(PoolAllocator *this, int blockSize, int blocksPerChunk)`, regular comment `Constructs a fixed-block PoolAllocator and initializes its embedded critical section.`
  - `0x004b1400 PoolAllocator_Allocate`, `void *__thiscall(PoolAllocator *this)`, exact no-change with blank accepted entry/function comments.
  - `0x004b14c0 PoolAllocator_Free`, `void __thiscall(PoolAllocator *this, void *block)`, regular comment `Returns a non-null block to this allocator's free list under its embedded critical section.`
  - `0x004b1520 PoolAllocator_Destructor`, `void __thiscall(PoolAllocator *this)`, regular comment `Destroys a PoolAllocator by freeing its chunk list and deleting its embedded critical section.`
  - `0x00549bd0 PoolAllocator_AllocateChunk`, `void *__cdecl(void **chunkListHead, int blocksPerChunk, int blockSize)`, regular comment `Allocates and prepends one PoolAllocator chunk containing blocksPerChunk fixed-size blocks.`
  - `0x00549c00 PoolAllocator_FreeChunkList`, `void __thiscall(void **chunkList)`, regular comment `Walks and frees a PoolAllocator chunk list.`
- Applying those typed signatures persistently normalized physical argument-frame labels for A02 to `blockSize`/`blocksPerChunk`, A04 to `block`, and A06 to `chunkListHead`/`blocksPerChunk`/`blockSize`. Supervisor rename-stack dry-run returned literal `Argument member` when asked to restore raw argument labels, so no unsafe frame recreation was attempted. Hex-Rays names/types, ABI, offsets, widths, nonargument frame members, A05/A07 frames, ranges, bytes, xrefs, and protected internal comments remain exact.
- Exact UID0002WS storage readback is one 40-byte `struct PoolAllocator g_itemObjectPanePool` data item at `[0x0069b9ac,0x0069b9d4)` with accepted regular/repeatable comments, forty zero bytes, five base xrefs, and no checked interior xrefs or heads. This supports the existing file-local `static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);` source without moving ownership to this utility class.
- Saved IDB SHA256 `41977C87379D1A8BDC199A9A17DE3E117E365E3A596828DFA6FA0D7C2FA60DD3`, size `143190178`, last write `2026-07-29T03:12:58.7364596-04:00`; prestate backup `source-3/project-documentation/tools/leaser/Agents/ida-backups/NexusTK.exe.before-B008-UID0002WS-20260729-031039.i64`, SHA256 `B46BEB1B347B569129E0B9F9BB53C51E4560EF6249081256D31EAC53A95F1A41`.

## C++ Readiness

The class-level declaration is now source-ready and emitted from this page. Exact method/helper bodies are emitted by the matching by-memory pages:

- [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md): constructor, `Allocate`, and destructor, with `Free` delegated to exact [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md) to avoid duplicate output.
- [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md): `PoolAllocator::Free(void *)`.
- [UID:0001F4][0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper](by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md): `AllocatePoolChunk`.
- [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md): `FreePoolChunkList`.

The draft is source-style and intentionally omits MSVC EH/security-cookie scaffolding, `fs:[0]` setup, handler constants `0x005fe830`/`0x005fe84b`, and cleanup funclet entries.

CPP source order is the include/prelude, private records and prototypes, UID000152 constructor/Allocate, nested UID000153 Free, UID000152 destructor, UID0001F4 AllocatePoolChunk, and UID00023L FreePoolChunkList. This page's H channel is the single declaration/layout authority; child H channels remain blank.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `94` | Public constructor/`Allocate`/`Free`/destructor API, both file-local helpers, exact `0x28` layout, private overlay records, nested emitter order, distributed static-pool placement, compiler cleanup exclusion, and complete formal CPP/H are resolved. |
| Confidence `94` | Binary behavior, xref totals, method/helper bounds, representative static-pool references, layout evidence, and source-owner ranking are strong. Exact historical filename/header formatting and some private/global spellings remain inferred. |

## Cross-References

- File: [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- Memory: [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md)
- Free alias: [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md)
- Chunk allocation helper: [UID:0001F4][0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper](by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md)
- Chunk free helper: [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md)
- Layout: [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- Globals: [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- Static constructors: [UID:0000WC][0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers](by-memory/0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md)
- Static destructors: [UID:0001O8][0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers](by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md)
- String pools: [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- Related alias: [UID:0000EX][ThreadSafeNodeList](by-class/ThreadSafeNodeList.md), [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md)

## Changes

- 2026-08-22 B001 UID0000MM Gate 2A ordinary repair:
  - Merged the accepted exact layout/API/private-record/formal-route/source-order facts into Layout, Public API, File-Local Helpers, C++ Readiness, and Score Rationale.
  - Corrected the active cleanup endpoint to `0x004b151e`, established the current `94/94` rationale, and retained old `88/90` and generated-alias facts only inside dated history.

- 2026-07-29 B008 UID0002WS Gate 2B support reconciliation:
  - Added exact catalog entry `0350` UDT/function/type/comment/frame-normalization/target-item/save readback while preserving `88/90`, owner/emitter route, class formal declaration, public/file-local source split, and all historical source-quality reasoning.

- 2026-06-20 B002 Rule 26 source-quality incorporation:
  - Before: `86/85`, blank C++, unresolved public/private `Free`, unresolved standalone-vs-string/container owner caveat, no class-level declaration, and `ThreadSafeNodeList` alias still treated as an open source identity.
  - After: `88/90`, owner/emitter still [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md), class-level declaration C++ populated, `PoolAllocator::Free` accepted as public API, helper signatures named, static-pool ownership kept distributed, and compiler cleanup funclet/scaffolding explicitly excluded from source.
  - Incorporated evidence: local PE caller counts for constructor/allocate/free/destructor/helper refs; representative static pool references; exact method ranges and half-open endpoints; `0x004b14f0-0x004b151d` cleanup-funclet decision; field names `m_blockSize`, `m_blocksPerChunk`, `m_chunkList`, `m_freeList`, and `m_lock`; `PoolChunkHeader` and `PoolFreeBlock` overlay types; `AllocatePoolChunk` and `FreePoolChunkList` helper signatures; rejection of `StringBase`/`StringUtil`, concrete object-pane, standalone `ThreadSafeNodeList`, and no-owner routes; concrete static pool descriptive-name table; C++ readiness and remaining final filename/header/global-spelling caveats.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and assigned parent `0000MM`.
  - Before: reconstruction autogen classification and parent were blank despite allocator mechanics, helper, static-instance, and layout documentation.
  - After: classified as reconstructable source attached to [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md).
  - Evidence: live IDA MCP `lookup_funcs` confirms modeled starts at `0x004b13d0`, `0x004b1400`, `0x004b14c0`, `0x004b1520`, `0x00549bd0`, and `0x00549c00`; the page documents fixed-block allocation/free/destruction behavior and source placement under `NexusTK/util/`.
- 2026-06-11 Agent-A006 Batch 147 parent/source refresh:
  - Before: `CONFIDENCE:82`.
  - After: `CONFIDENCE:85`.
  - Evidence: live IDA reconfirmed allocator method/helper bounds, constructor/free/allocate caller groups, and allocator-private chunk helper calls. Confidence cleared the strict parent gate for allocator-owned children, while final helper names and exact standalone-vs-string-module source placement remained open.
- Before: completion/confidence metadata were `0/0` even though the page documented allocator responsibility, layout, methods, helpers, static instances, constructor/destructor wrappers, and open questions.
- Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
- Evidence: block/chunk/free-list structure, `CRITICAL_SECTION` layout, allocation/free/destroy paths, chunk helpers, nineteen static instances, string/object/user-pane pool usage, and ignored `ThreadSafeNodeList` alias relationship are documented; confidence remained below maximum because final public/private helper names and exact original source placement were still open.
