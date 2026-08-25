** TARGET-REPORT-UID:0000AM **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 source-quality report: [UID:0000AM] PoolAllocator

## Assignment

- Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\PoolAllocator.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0000AM-PoolAllocator-class-source-quality.md`
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:85`, `CANONICAL_OWNER:0000MM`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MM`, blank formal C++.
- Guardrail followed: report-only. I did not edit target/support by-* docs and did not edit `by-memory/-coverage-report.md`.

## Executive recommendation

Raise the class to `88/90`, keep owner/emitter `[UID:0000MM] PoolAllocator`, and add first-draft class-level C++ now. The remaining uncertainty is original filename/header spelling and exact original global names, not behavior, ownership, or C++ readiness.

The best source-quality direction is:

- `PoolAllocator` is a standalone shared utility class in `NexusTK/util/PoolAllocator.cpp` plus a header, not private `StringBase`, `StringUtil`, `ThreadSafeNodeList`, or any one object-pane module.
- Public API:
  - `PoolAllocator::PoolAllocator(int blockSize, int blocksPerChunk)`
  - `PoolAllocator::~PoolAllocator()`
  - `void *PoolAllocator::Allocate()`
  - `void PoolAllocator::Free(void *block)`
- Private/file-local helpers:
  - `static PoolChunkHeader *AllocatePoolChunk(PoolChunkHeader **chunkListHead, int blocksPerChunk, int blockSize)`
  - `static void FreePoolChunkList(PoolChunkHeader *chunkList)`
- Source-facing fields:
  - `m_blockSize` at `+0x00`
  - `m_blocksPerChunk` at `+0x04`
  - `m_chunkList` at `+0x08`
  - `m_freeList` at `+0x0c`
  - `m_lock` at `+0x10`
- Helper records:
  - `PoolChunkHeader { PoolChunkHeader *next; }`, followed immediately by block bytes.
  - `PoolFreeBlock { PoolFreeBlock *next; }`, overlaid on the first word of a free block. Allocated blocks do not carry per-block allocator headers.
- `ThreadSafeNodeList::PushFront` is a generated/behavior alias for `0x004b14c0`, not the final source owner.
- Concrete static pool globals should stay with their consuming source modules. `PoolAllocator.cpp` owns allocator mechanics only.

## Evidence checked

Documentation read:

- Target class: `by-class/PoolAllocator.md`.
- File owner: `by-file/PoolAllocator.md`.
- Layout: `by-type/by-struct/PoolAllocatorLayout.md`.
- Core methods: `by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md`.
- Free alias: `by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md`.
- Chunk helper pages:
  - `by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md`
  - `by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md`
- Static instance inventory: `by-global/PoolAllocatorStaticInstances.md`.
- Static constructor/destructor wrapper support:
  - `by-memory/0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md`
  - `by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md`
- Distributed concrete storage pages for object-pane, string-buffer, Motion, and UserPane pools.
- String support pages:
  - `by-global/StringBufferSentinelsAndPools.md`
  - `by-file/StringBase.md`
  - `by-file/StringUtil.md`
- Alias pages:
  - `by-class/ThreadSafeNodeList.md`
  - `by-file/ThreadSafeNodeList.md`
- Synchronization helper page:
  - `by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md`
- Coverage rows in by-class, by-file, by-type/by-struct, by-memory, and by-global reports.

Independent executable checks:

- Source binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Local PE scan verified code reference counts:
  - `0x004b13d0`: 19 rel32 constructor-wrapper calls.
  - `0x004b1400`: 33 rel32 allocation calls.
  - `0x004b14c0`: 30 rel32 free calls.
  - `0x004b1520`: 19 rel32 destructor-wrapper calls.
  - `0x00549bd0`: 1 rel32 caller, `0x004b1450` inside `PoolAllocator::Allocate`.
  - `0x00549c00`: 2 rel32 refs, `0x004b1501` in compiler cleanup scaffolding and `0x004b1553` in `PoolAllocator::~PoolAllocator`.
- Representative static pool absolute references rechecked:
  - `0x0069bacc` wide string 64 pool: `0x0041a268`, `0x00582e51`, `0x005833ce`, `0x0060c431`.
  - `0x0069bb6c` ANSI string 64 pool: `0x0041a245`, `0x00582da1`, `0x0058331e`, `0x0060c421`.
  - `0x0069bf34` UserPane pool: `0x0041a4b8`, `0x004f84c6`, `0x004f8a2d`, `0x00502446`, `0x005b834f`, `0x0060c451`.
  - `0x0069b894` LivingObjectPane pool: `0x0041a108`, `0x00506072`, `0x00514c86`, `0x0053d543`, `0x0060c381`.
  - `0x0069b9fc` BalloonObjectPane pool: `0x0041a048`, `0x00469008`, `0x0050e180`, `0x005118ba`, `0x00514b06`, `0x0060c321`.
- Disassembly checked exact source behavior:
  - `0x004b13d0-0x004b1400`: constructor stores block size/count, clears free/chunk lists, initializes `CRITICAL_SECTION`.
  - `0x004b1400-0x004b14b8`: allocate with MSVC EH cookie/scaffold, lock, lazy chunk allocation, reverse block threading, pop free-list, unlock.
  - `0x004b14c0-0x004b14ef`: free null-checks, locks, pushes the block through its first dword to `m_freeList`, unlocks.
  - `0x004b14f0-0x004b151d`: no direct text refs; compiler EH cleanup funclet that frees/clears chunk/free lists under lock without deleting the critical section. Do not model as a source method.
  - `0x004b1520-0x004b1585`: destructor locks, calls chunk-list free helper, clears lists, unlocks, deletes critical section.
  - `0x00549bd0-0x00549bf1`: chunk allocation helper, cdecl-shaped, argument order `(PoolChunkHeader **head, int blocksPerChunk, int blockSize)`.
  - `0x00549c00-0x00549c18`: chunk-list free helper, ecx/thiscall-shaped binary helper, source-facing `static void FreePoolChunkList(PoolChunkHeader *chunkList)`.
- Negative evidence checked:
  - No direct code refs to `0x004b14f0` or `0x004b14a2`; those are EH funclet/scaffold entry points, not source API.
  - No source filename, RTTI, or local IDA UDT proves exact original filename/header. This only caps confidence, not source routing.
  - `CriticalSectionLock` exists elsewhere, but allocator methods call imported `EnterCriticalSection`/`LeaveCriticalSection` directly and do not call the `CriticalSectionLock` constructor/destructor pair. Do not rewrite allocator source around that class unless later evidence proves the calls were inlined from an identical local guard type.

## Heuristic/source-inference reanalysis

### Standalone utility vs StringBase/StringUtil/private container

Best inference: keep `PoolAllocator.cpp` as a standalone utility under `NexusTK/util/`.

Evidence:

- The allocator mechanics are type-agnostic and take only block size/count, chunk list, free list, and lock state.
- Nineteen static instances use the same class. Only eight are string-buffer pools.
- Non-string consumers include object-pane pools, the Motion animation pool, and the large UserPane pool.
- `by-meta/client_containers.md` already treats PoolAllocator as a shared fixed-block allocator rather than a string-only helper.
- `StringBase`/`StringUtil` own the string sentinels, string buffer headers, string allocation/release policy, and the eight concrete string pool declarations. They do not directly own object-pane, Motion, or UserPane pools.

Rejected alternatives:

- Private `StringBase.cpp` or `StringUtil.cpp`: rejected because 11 of 19 static pools are non-string and the public `Allocate`/`Free` calls fan out across UI/object/Motion/UserPane code.
- Concrete object-pane file owner: rejected because the same allocator mechanics serve multiple unrelated object families and strings.
- `ThreadSafeNodeList.cpp`: rejected because there is no proven standalone list type layout/constructor/destructor. The `0x004b14c0` function uses `PoolAllocator` offsets `+0x0c` and `+0x10` and all confirmed caller groups return pool allocations.
- No owner/splitless utility cluster: rejected because [UID:0000MM] already provides a valid utility file parent and all core mechanics share that file-level owner.

### Public/private method inventory

Recommended final method inventory:

| Address | Final source-facing role | Signature | Confidence |
| --- | --- | --- | --- |
| `0x004b13d0` | constructor | `PoolAllocator::PoolAllocator(int blockSize, int blocksPerChunk)` | High |
| `0x004b1400` | public allocator method | `void *PoolAllocator::Allocate()` | High |
| `0x004b14c0` | public free/return method | `void PoolAllocator::Free(void *block)` | High |
| `0x004b1520` | destructor | `PoolAllocator::~PoolAllocator()` | High |
| `0x00549bd0` | file-local chunk helper | `static PoolChunkHeader *AllocatePoolChunk(PoolChunkHeader **chunkListHead, int blocksPerChunk, int blockSize)` | High |
| `0x00549c00` | file-local chunk-list free helper | `static void FreePoolChunkList(PoolChunkHeader *chunkList)` | High |

`Free` should be public, not private:

- It has 30 external call sites, not just allocator-internal callers.
- It is semantically paired with `Allocate`.
- It null-checks input, matching a safe public return path.
- String release helpers, object-pane destruction/unwind paths, Motion, UserPane, and BalloonObjectPane-related paths all call it as a pool return API.

`0x004b14f0-0x004b151d` should not become a source method:

- It is in the gap between `PoolAllocator::Free` and `PoolAllocator::~PoolAllocator`.
- It has no direct text refs in the local PE scan.
- Its only externally visible effect here is the `0x004b1501` ref to `FreePoolChunkList`.
- Its shape matches MSVC EH/unwind cleanup for destructor-like list clearing, not handwritten public/private API. Document it in the method island as compiler-only cleanup scaffolding.

### Field and helper type names

Recommended source-facing class fields:

| Offset | Current layout term | Recommended source member | Reason |
| --- | --- | --- | --- |
| `+0x00` | `blockSize` | `m_blockSize` | Constructor writes it; allocation helper receives it as block size. |
| `+0x04` | `blocksPerChunk` | `m_blocksPerChunk` | Constructor writes it; chunk allocation and reverse threading use it as count. |
| `+0x08` | `chunkList` | `m_chunkList` | Head of all allocated chunks, prepended by helper, walked by destructor. |
| `+0x0c` | `freeList` | `m_freeList` | Head of reusable block list, popped by Allocate and pushed by Free. |
| `+0x10` | `lock` | `m_lock` | Embedded Win32 `CRITICAL_SECTION`, size `0x18`, object size `0x28`. |

Recommended helper records:

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

`PoolChunkHeader` is a whole-chunk header. The first client block begins at `chunk + sizeof(PoolChunkHeader)`. `PoolFreeBlock` overlays the first word of a block only while that block is on the free list.

### Static pool global names and placement

Do not declare all static pools in `PoolAllocator.cpp`. Concrete static pools belong with the module that owns the allocation policy. Recommended descriptive names for support docs and IDA comments:

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
| `0x0069bb94` | `g_ansiPool128` | StringBase/string-buffer module |
| `0x0069baf4` | `g_widePool128` | StringBase/string-buffer module |
| `0x0069bbbc` | `g_ansiPool256` | StringBase/string-buffer module |
| `0x0069bb1c` | `g_widePool256` | StringBase/string-buffer module |
| `0x0069bbe4` | `g_ansiPool512` | StringBase/string-buffer module |
| `0x0069bb44` | `g_widePool512` | StringBase/string-buffer module |
| `0x0069bb6c` | `g_ansiPool64` | StringBase/string-buffer module |
| `0x0069bacc` | `g_widePool64` | StringBase/string-buffer module |

The string names are already established in string global support docs. The object/Motion/UserPane names are inferred descriptive names, not original-name proof. They are still better than raw addresses or `dword_` names and should be used in comments/support docs with that caveat.

### Compiler-generated and raw-name cleanup

Resolved raw/compiler labels:

- `sub_4B13D0` -> `PoolAllocator_Constructor` / source `PoolAllocator::PoolAllocator`.
- `sub_4B1400` -> `PoolAllocator_Allocate` / source `PoolAllocator::Allocate`.
- `sub_4B14C0` -> `PoolAllocator_Free` / source `PoolAllocator::Free`.
- `sub_4B1520` -> `PoolAllocator_Destructor` / source `PoolAllocator::~PoolAllocator`.
- `sub_549BD0` -> `PoolAllocator_AllocateChunk` / source file-local `AllocatePoolChunk`.
- `sub_549C00` -> `PoolAllocator_FreeChunkList` / source file-local `FreePoolChunkList`.
- `ThreadSafeNodeList::PushFront` -> keep as historical/generated behavior alias only.
- `0x004b14a2` and `0x004b14f0` -> compiler EH cleanup funclets/scaffolding, not source methods.
- `[0x00672f24]`, `fs:[0]`, `[ebp-4]`, handler constants `0x005fe830` and `0x005fe84b` -> MSVC EH/security-cookie scaffolding, not handwritten PoolAllocator state.

## First-draft C++ recommendation

The class-level page should receive a first-draft declaration. Class files should generally emit class-level code, not full method bodies, so put the declaration in [UID:0000AM]. The method/helper bodies can be added to [UID:000152], [UID:0001F4], and [UID:00023L] during the same implementation callback if accepted.

Recommended `by-class/PoolAllocator.md` `RECONSTRUCTION_CPP` block:

```cpp
struct PoolChunkHeader
{
    PoolChunkHeader *next;
};

struct PoolFreeBlock
{
    PoolFreeBlock *next;
};

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
```

Recommended file-local helper declarations for `PoolAllocator.cpp` support docs:

```cpp
static PoolChunkHeader *AllocatePoolChunk(PoolChunkHeader **chunkListHead,
                                          int blocksPerChunk,
                                          int blockSize);
static void FreePoolChunkList(PoolChunkHeader *chunkList);
```

Source-style method body draft for implementation notes/support pages:

```cpp
static PoolChunkHeader *AllocatePoolChunk(PoolChunkHeader **chunkListHead,
                                          int blocksPerChunk,
                                          int blockSize)
{
    PoolChunkHeader *chunk = static_cast<PoolChunkHeader *>(
        operator new(blocksPerChunk * blockSize + sizeof(PoolChunkHeader)));
    chunk->next = *chunkListHead;
    *chunkListHead = chunk;
    return chunk;
}

static void FreePoolChunkList(PoolChunkHeader *chunkList)
{
    while (chunkList != 0)
    {
        PoolChunkHeader *next = chunkList->next;
        operator delete(chunkList);
        chunkList = next;
    }
}

PoolAllocator::PoolAllocator(int blockSize, int blocksPerChunk)
    : m_blockSize(blockSize),
      m_blocksPerChunk(blocksPerChunk),
      m_chunkList(0),
      m_freeList(0)
{
    InitializeCriticalSection(&m_lock);
}

PoolAllocator::~PoolAllocator()
{
    EnterCriticalSection(&m_lock);
    FreePoolChunkList(m_chunkList);
    m_chunkList = 0;
    m_freeList = 0;
    LeaveCriticalSection(&m_lock);
    DeleteCriticalSection(&m_lock);
}

void *PoolAllocator::Allocate()
{
    EnterCriticalSection(&m_lock);

    if (m_freeList == 0)
    {
        PoolChunkHeader *chunk = AllocatePoolChunk(&m_chunkList, m_blocksPerChunk, m_blockSize);
        char *block = reinterpret_cast<char *>(chunk) + sizeof(PoolChunkHeader);
        block += (m_blocksPerChunk - 1) * m_blockSize;

        for (int i = m_blocksPerChunk - 1; i >= 0; --i)
        {
            PoolFreeBlock *freeBlock = reinterpret_cast<PoolFreeBlock *>(block);
            freeBlock->next = m_freeList;
            m_freeList = freeBlock;
            block -= m_blockSize;
        }
    }

    PoolFreeBlock *block = m_freeList;
    m_freeList = block->next;

    LeaveCriticalSection(&m_lock);
    return block;
}

void PoolAllocator::Free(void *block)
{
    if (block == 0)
        return;

    EnterCriticalSection(&m_lock);

    PoolFreeBlock *freeBlock = static_cast<PoolFreeBlock *>(block);
    freeBlock->next = m_freeList;
    m_freeList = freeBlock;

    LeaveCriticalSection(&m_lock);
}
```

Implementation caveat: the binary uses MSVC EH cleanup around `Allocate` and destructor list-clearing. The above body is intentionally source-style. If the project has an established original lock guard naming pattern for this allocator, use it only if evidence shows these direct Win32 calls were inlined from that guard. Current direct evidence supports plain Win32 calls plus compiler cleanup scaffolding.

## Recommended exact target changes

For `by-class/PoolAllocator.md`:

- Change `COMPLETION:86` to `COMPLETION:88`.
- Change `CONFIDENCE:85` to `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000MM`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000MM`.
- Replace open questions about final public/private method names with the resolved inventory above.
- Add the class-level C++ declaration shown above.
- Add evidence that the executable scan confirms:
  - 19 constructor wrappers.
  - 33 allocate callers.
  - 30 free callers.
  - 19 destructor wrappers.
  - one direct allocate-chunk caller.
  - two free-chunk refs, one destructor call and one compiler cleanup ref.
- Add the source-placement decision:
  - `PoolAllocator.cpp` owns mechanics.
  - concrete static pool globals remain distributed.
  - `StringBase`/`StringUtil` are consumers/owners of string pool declarations, not allocator mechanics.
- Add the rejected alternatives:
  - no standalone `ThreadSafeNodeList` source owner for this function.
  - no string-private owner for whole allocator.
  - no monolithic static-pool aggregate emitted by `PoolAllocator.cpp`.
- Add the compiler-only note for:
  - EH/security cookie constants and `fs:[0]` setup.
  - `0x004b14a2` allocate cleanup and `0x004b14f0-0x004b151d` destructor/list cleanup funclet.

## Recommended support-doc changes

Use report-level detail, not compact summaries.

1. `by-file/PoolAllocator.md`
   - Raise to approximately `88/89`.
   - Replace "medium-high for final standalone file split" with "strong working source placement, capped only by absence of embedded filename/header proof."
   - State final method API and file-local helper names/signatures.
   - Keep utility route `NexusTK/util/PoolAllocator.cpp`.
   - Explicitly reject StringBase/StringUtil/private ThreadSafeNodeList ownership.
   - Update generated-output caveats: `class_ThreadSafeNodeList.cpp` is alias pollution, and `class_PoolAllocator.cpp` is partial because it omits constructor/free/destructor/helper bodies.

2. `by-type/by-struct/PoolAllocatorLayout.md`
   - Raise to approximately `88/91`.
   - Change field-name caveat from unresolved to source-facing names:
     `m_blockSize`, `m_blocksPerChunk`, `m_chunkList`, `m_freeList`, `m_lock`.
   - Add first-draft layout/code or point to the class-level declaration if the project avoids duplicate C++ blocks.
   - Keep `PoolChunkHeader` and `PoolFreeBlock` records with the overlay/no per-block-header explanation.

3. `by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md`
   - Raise to approximately `88/91`.
   - Correct half-open ranges in the table:
     - constructor `0x004b13d0-0x004b1400`
     - allocate `0x004b1400-0x004b14b8` including EH cleanup tail
     - free `0x004b14c0-0x004b14ef`
     - compiler cleanup funclet `0x004b14f0-0x004b151d`, no source method
     - destructor `0x004b1520-0x004b1585`
   - Add method body first-draft if accepted. This is the correct support page for constructor/allocate/free/destructor body evidence.
   - Document `0x004b14f0-0x004b151d` as compiler EH cleanup/local funclet, not a source `Clear()` method.

4. `by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md`
   - Raise to approximately `87/91`.
   - Rename source-facing description toward `PoolAllocator::Free`.
   - Keep the old title/alias only as generated/historical behavior alias unless supervisor chooses a file rename later.
   - Close open questions:
     - final source name is `PoolAllocator::Free`;
     - broad external caller set makes it public;
     - no non-pool xrefs currently prove standalone `ThreadSafeNodeList`.
   - Add first-draft `void PoolAllocator::Free(void *block)` body if accepted.

5. `by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md`
   - Raise to approximately `87/91`.
   - Set source-facing helper name/signature to `static PoolChunkHeader *AllocatePoolChunk(PoolChunkHeader **chunkListHead, int blocksPerChunk, int blockSize)`.
   - State exact argument order and evidence from caller push order/helper body.
   - Add first-draft helper body if accepted.

6. `by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md`
   - Raise to approximately `87/91`.
   - Set source-facing helper name/signature to `static void FreePoolChunkList(PoolChunkHeader *chunkList)`.
   - Explain ecx/thiscall binary shape as compiler calling convention for a file-local helper, not a class method.
   - Document refs `0x004b1501` compiler cleanup and `0x004b1553` destructor.
   - Add first-draft helper body if accepted.

7. `by-global/PoolAllocatorStaticInstances.md`
   - No score change required; it is already high and correctly non-emitting.
   - Add the recommended descriptive global names table from this report if not already present.
   - Preserve `RECONSTRUCTABLE:FALSE` and `CANONICAL_OWNER:NONE`.

8. Concrete pool storage pages
   - No direct update required for this class report unless supervisor wants to propagate global names now.
   - If touched, use `g_<class>Pool` names as descriptive inferred names and keep direct owners with concrete modules.

## Score and metadata recommendation

Target `by-class/PoolAllocator.md`:

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| Completion | 86 | 88 | Public/private API, helper names, layout names, source placement, alias cleanup, static placement, and first-draft class declaration are now resolved. |
| Confidence | 85 | 90 | Binary behavior/caller counts are strong; only exact original filename/header/global spelling remains inferred. |
| Owner | `0000MM` | `0000MM` | File owner is the correct allocator-mechanics source root. |
| Reconstructable | `TRUE` | `TRUE` | Class declaration is source-level and emitted. |
| Emitters | `0000MM` | `0000MM` | Emit through `NexusTK/util/PoolAllocator.cpp` route. |
| C++ | blank | populate | Active 85/85+ code policy applies; no target-specific no-code proof remains. |

## Exact coverage text

The supervisor should apply coverage rows only for docs actually edited in the later implementation callback. Do not edit `by-memory/-coverage-report.md` from the B-agent implementation pass.

Recommended `by-class/-coverage-report.md` replacement row:

```text
- [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md) : reconstructable : 88% : strong : Source-quality pass resolves PoolAllocator as standalone utility-owned fixed-block pool emitted through [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md), with public constructor/Allocate/Free/destructor API, file-local chunk helpers, PoolChunkHeader/PoolFreeBlock overlay types, m_blockSize/m_blocksPerChunk/m_chunkList/m_freeList/m_lock fields, current executable caller counts, rejected ThreadSafeNodeList/StringBase/StringUtil ownership alternatives, distributed static-pool placement, compiler cleanup funclet treatment, and first-draft class declaration documented.
```

Recommended `by-file/-coverage-report.md` replacement row if `by-file/PoolAllocator.md` is updated:

```text
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) : reconstructable : 88% : strong : Fixed-block allocator source file route now resolves public PoolAllocator constructor/Allocate/Free/destructor API, file-local AllocatePoolChunk/FreePoolChunkList helpers, utility placement over StringBase/StringUtil/ThreadSafeNodeList alternatives, current executable caller counts, generated-output caveats, distributed concrete static-pool ownership, and first-draft PoolAllocator.cpp readiness.
```

Recommended `by-type/by-struct/-coverage-report.md` replacement row if `PoolAllocatorLayout.md` is updated:

```text
- [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md) : reconstructable : 88% : strong : PoolAllocator layout now maps offsets to source-facing m_blockSize, m_blocksPerChunk, m_chunkList, m_freeList, and m_lock fields; documents PoolChunkHeader and PoolFreeBlock overlay records, 0x28 object size, CRITICAL_SECTION ownership, allocation/free/destructor transitions, representative static-pool xrefs, and first-draft declaration support.
```

Supervisor-owned `by-memory/-coverage-report.md` replacement rows if the listed by-memory support pages are updated:

```text
    - [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md) 0x004b13d0-0x004b1585 | class-method-island | PoolAllocatorCore : reconstructable : 88% : strong : PoolAllocator method island now resolves source-facing constructor/Allocate/Free/destructor API, exact half-open method ranges, allocator field names, public Free decision, 0x004b14f0 compiler cleanup funclet, private chunk helper calls, current executable caller counts, rejected ThreadSafeNodeList/StringBase alternatives, and first-draft method-body readiness.
    - [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md) 0x004b14c0-0x004b14ef | intrusive-list helper | ThreadSafeNodeListPushFront : reconstructable : 87% : strong : Source-facing role resolved as public PoolAllocator::Free(void*) with ThreadSafeNodeList kept only as a generated behavior alias; IDA/executable evidence confirms 30 allocator-return callers, null-check, lock at this+0x10, push through block first word to m_freeList at this+0x0c, and no proven standalone ThreadSafeNodeList owner.
    - [UID:0001F4][0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper](by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md) 0x00549bd0-0x00549bf1 | allocator-private helper | PoolAllocatorChunkHelper : reconstructable : 87% : strong : Source-facing helper resolved as file-local AllocatePoolChunk(PoolChunkHeader **chunkListHead, int blocksPerChunk, int blockSize); single caller from PoolAllocator::Allocate, exact argument order, allocation size blocksPerChunk * blockSize + sizeof(PoolChunkHeader), chunk-list prepend, and helper-body C++ readiness documented.
    - [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md) 0x00549c00-0x00549c18 | allocator-private helper | PoolAllocatorFreeChunkList : reconstructable : 87% : strong : Source-facing helper resolved as file-local FreePoolChunkList(PoolChunkHeader *chunkList); ecx-shaped binary helper walks PoolChunkHeader next links and frees chunks, with refs from destructor at 0x004b1553 and compiler cleanup at 0x004b1501, not a public method.
```

Recommended `by-global/-coverage-report.md` row: no replacement needed unless only wording is refreshed. Keep [UID:0000TI] as `ignored : 89% : very strong`.

## Validation commands for implementation callback

From `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000AM-PoolAllocator-class-source-quality-removed.md](0000AM-PoolAllocator-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run the final two only if those support docs are edited. Run the repo's autogen/rescore workflow after adding C++ if the supervisor's accepted checklist requires generated source refresh.

## IDA rename/type/comment recommendations

Function names:

- `0x004b13d0`: keep IDA-safe `PoolAllocator_Constructor`; source comment `PoolAllocator::PoolAllocator(int blockSize, int blocksPerChunk)`.
- `0x004b1400`: keep `PoolAllocator_Allocate`; type `void *__thiscall PoolAllocator_Allocate(PoolAllocator *this)`.
- `0x004b14c0`: keep `PoolAllocator_Free`; type `void __thiscall PoolAllocator_Free(PoolAllocator *this, void *block)`.
- `0x004b1520`: keep `PoolAllocator_Destructor`; source comment `PoolAllocator::~PoolAllocator()`.
- `0x00549bd0`: rename/comment as `PoolAllocator_AllocateChunk` or `AllocatePoolChunk`; type `PoolChunkHeader *__cdecl AllocatePoolChunk(PoolChunkHeader **chunkListHead, int blocksPerChunk, int blockSize)`.
- `0x00549c00`: rename/comment as `PoolAllocator_FreeChunkList` or `FreePoolChunkList`; source type `void FreePoolChunkList(PoolChunkHeader *chunkList)`, with IDA calling-convention note that the binary passes the argument in `ecx`.

Struct/type suggestions:

```cpp
struct PoolChunkHeader { PoolChunkHeader *next; };
struct PoolFreeBlock { PoolFreeBlock *next; };
struct PoolAllocator
{
    int m_blockSize;
    int m_blocksPerChunk;
    PoolChunkHeader *m_chunkList;
    PoolFreeBlock *m_freeList;
    CRITICAL_SECTION m_lock;
};
```

Comments:

- At `0x004b14f0`: "MSVC cleanup funclet for PoolAllocator chunk/free-list teardown; no direct source method/xref."
- At `0x004b1501`: "Cleanup funclet call to FreePoolChunkList, not a public caller."
- At string/object/Motion/UserPane pool globals: comment with descriptive `g_*Pool` names and "concrete static PoolAllocator owned by consuming module; mechanics owned by PoolAllocator.cpp."

## Open questions closure

- Final public/private names: resolved as public constructor, destructor, `Allocate`, and `Free`; helpers are private/file-local.
- `Free` vs `ThreadSafeNodeList::PushFront`: resolved as `PoolAllocator::Free`; ThreadSafeNodeList is only alias pollution until a real standalone list owner is proven.
- Standalone file vs StringBase/StringUtil: resolved to standalone `NexusTK/util/PoolAllocator.cpp` as best-supported route; exact historical filename remains unproven and caps confidence below final audit.
- Static pool globals: concrete declarations stay distributed; names above are descriptive inferred names where not already established.
- Layout field names: resolved to `m_*` source fields; raw layout aliases can remain as storage terms.
- Source-facing helper types: resolved to `PoolChunkHeader` and `PoolFreeBlock`.
- `0x004b14f0` cleanup body: resolved as compiler EH funclet/scaffolding; do not split into a source child or private method.
- First-draft C++: ready for class declaration now; method/helper body drafts are ready for support memory pages if supervisor accepts a broader implementation callback.

## Implementation readiness

Ready. The accepted implementation callback should apply the target class update and the support-doc updates listed above. No target-specific no-code proof remains for [UID:0000AM]; blank C++ should be replaced with the first-draft declaration.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0000AM-PoolAllocator-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"0000AM"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000AM-PoolAllocator-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0000AM-PoolAllocator-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000AM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
