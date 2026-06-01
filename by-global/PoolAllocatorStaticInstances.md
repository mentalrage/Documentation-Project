*** UID:0000TI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PoolAllocatorStaticInstances

## Status

- Entity kind: grouped global-data documentation
- Confidence: strong for addresses, block sizes, block counts, and xref relationships; medium for final global names.
- Proposed owner: [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md), with concrete declarations near each consuming class/module where appropriate.

## Role

The binary constructs nineteen static [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) instances during startup. Eight are ref-counted string-buffer pools; the remaining eleven are object/class pools for map panes, animation state, and the large local user pane.

Each instance has the [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md) shape:

```text
+0x00 blockSize
+0x04 blocksPerChunk
+0x08 chunkList
+0x0c freeList
+0x10 CRITICAL_SECTION
```

The startup wrappers call `0x004b13d0`, register a matching `atexit` cleanup wrapper, and the consuming constructors/destructors call the allocator island at `0x004b1400` and `0x004b14c0`.

Constructor-failure cleanup wrappers are documented separately because they are compiler-generated EH/delete thunks, not normal source methods. They still provide useful evidence for concrete pool ownership.

## Static Object And Pane Pools

| Address | blockSize | blocksPerChunk | Constructor wrapper | Cleanup wrapper | Current owner hypothesis | Key xrefs |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069b9fc` | `480` | `16` | `0x0041a040` | `0x0060c320` | [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md) pool | `0x00469007`, `0x0050e100`, `0x00511710`, `0x00514ae0` |
| `0x0069b95c` | `328` | `8` | `0x0041a060` | `0x0060c330` | [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md) pool | `0x0050ef00`, `0x00512960`, `0x0053d060`, `0x00514b20` |
| `0x0069b90c` | `336` | `16` | `0x0041a080` | `0x0060c340` | [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) pool | `0x0050ea30`, `0x0053d100`, `0x00514b60` |
| `0x0069b9d4` | `324` | `4` | `0x0041a0a0` | `0x0060c350` | [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md) pool | `0x0050dfa0`, `0x00512d60`, `0x0053d1a0`, `0x00514ba0` |
| `0x0069b934` | `312` | `4` | `0x0041a0c0` | `0x0060c360` | [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) pool | `0x0050e4c0`, `0x0050e690`, `0x0050edd0`, `0x0053d240`, `0x00514be0` |
| `0x0069b9ac` | `300` | `8` | `0x0041a0e0` | `0x0060c370` | [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) pool | `0x00505e00`, `0x0053d2e0`, `0x00514c20` |
| `0x0069b894` | `524` | `32` | `0x0041a100` | `0x0060c380` | [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) pool | `0x00505e00`, `0x0053d430`, `0x00514c60` |
| `0x0069b984` | `28` | `16` | `0x0041a120` | `0x0060c390` | [UID:00008R][Motion](by-class/Motion.md) animation pool | `0x0053b3d0`, `0x0053ce50`, `0x0053d590` |
| `0x0069b8e4` | `344` | `32` | `0x0041a140` | `0x0060c3a0` | [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md) pool | `0x0050ec30`, `0x00512f20`, `0x0053d660`, `0x00514ca0` |
| `0x0069b8bc` | `300` | `16` | `0x0041a160` | `0x0060c3b0` | [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md) pool | `0x0050f030`, `0x0053d740`, `0x00514ce0` |
| `0x0069bf34` | `1305476` | `2` | `0x0041a4b0` | `0x0060c450` | [UID:0000FQ][UserPane](by-class/UserPane.md) pool | `0x004f7d10`, `0x00502420`, `0x005b8230` |

## String Buffer Pools

See [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) for the detailed string-buffer view.

| Address | blockSize | blocksPerChunk | Constructor wrapper | Cleanup wrapper | Use |
| --- | --- | --- | --- | --- | --- |
| `0x0069bb94` | `141` | `64` | `0x0041a180` | `0x0060c3c0` | ANSI 128 bucket |
| `0x0069baf4` | `270` | `64` | `0x0041a1a0` | `0x0060c3d0` | wide 128 bucket |
| `0x0069bbbc` | `269` | `64` | `0x0041a1c0` | `0x0060c3e0` | ANSI 256 bucket |
| `0x0069bb1c` | `526` | `64` | `0x0041a1e0` | `0x0060c3f0` | wide 256 bucket |
| `0x0069bbe4` | `525` | `64` | `0x0041a200` | `0x0060c400` | ANSI 512 bucket |
| `0x0069bb44` | `1038` | `64` | `0x0041a220` | `0x0060c410` | wide 512 bucket |
| `0x0069bb6c` | `77` | `64` | `0x0041a240` | `0x0060c420` | ANSI 64 bucket |
| `0x0069bacc` | `142` | `64` | `0x0041a260` | `0x0060c430` | wide 64 bucket |

## Constructor-Failure Free Wrappers

| Wrapper | Pool | Owner hypothesis | Notes |
| --- | --- | --- | --- |
| `0x00502420` | `0x0069bf34` | [UID:0000P1][UserPane](by-file/UserPane.md) | Non-contiguous wrapper for the large local user-pane pool. |
| `0x00514ae0` | `0x0069b9fc` | [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md) | Object-pane wrapper strip. |
| `0x00514b20` | `0x0069b95c` | [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md) | Object-pane wrapper strip. |
| `0x00514b60` | `0x0069b90c` | [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) | Object-pane wrapper strip. |
| `0x00514ba0` | `0x0069b9d4` | [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md) | Object-pane wrapper strip. |
| `0x00514be0` | `0x0069b934` | [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) | Object-pane wrapper strip. |
| `0x00514c20` | `0x0069b9ac` | [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) | Object-pane wrapper strip. |
| `0x00514c60` | `0x0069b894` | [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) | Object-pane wrapper strip. |
| `0x00514ca0` | `0x0069b8e4` | [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md) | Object-pane wrapper strip. |
| `0x00514ce0` | `0x0069b8bc` | [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md) | Object-pane wrapper strip. |
| `0x0053ce50` | `0x0069b984` | [UID:00008R][Motion](by-class/Motion.md) | Non-contiguous wrapper for the animation-object pool. |

## Static Init/Cleanup Wrapper Docs

| Range | Role | Notes |
| --- | --- | --- |
| [UID:0000WC][0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers](by-memory/0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md) | static constructors | Eighteen object/string pool init wrappers before `WideApiDispatchInit`. |
| [UID:0000WE][0x0041a4b0-0x0041a4cd.UserPanePoolStaticConstructorWrapper](by-memory/0x0041a4b0-0x0041a4cd.UserPanePoolStaticConstructorWrapper.md) | static constructor | Large `UserPane` pool init wrapper after `WideApiDispatchInit`. |
| [UID:0001O8][0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers](by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md) | static destructors | Eighteen object/string pool cleanup wrappers. |
| [UID:0001OA][0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper](by-memory/0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper.md) | static destructor | Large `UserPane` pool cleanup wrapper. |

Boundary note: `0x0060c440-0x0060c44b` is `UniAPIInit` cleanup, not a pool cleanup wrapper.

## Evidence

- 2026-05-26 IDA MCP decompiled the nineteen static constructor wrappers. Each wrapper calls `sub_4B13D0(poolAddress, blockSize, blocksPerChunk)` and registers a matching cleanup wrapper with `atexit`.
- 2026-05-26 IDA MCP decompiled nineteen matching static destructor wrappers at `0x0060c320-0x0060c430` and `0x0060c450`; `0x0060c440` is the neighboring `UniAPIInit` cleanup wrapper.
- 2026-05-26 IDA MCP xrefs to the non-string pool addresses show constructor/allocator/destructor users matching the class names in the owner-hypothesis column.
- The per-object block sizes line up with known destructor pools: for example `Motion::ScalarDeletingDestructor` at `0x0053d590` returns objects to `0x0069b984`, and `UserPane::ScalarDeletingDestructor` at `0x005b8230` returns the large local user pane allocation to `0x0069bf34`.
- Active generated output sometimes names these calls through `ThreadSafeNodeList::PushFront` or `cls_0x4b14c0::meth_0x4b14c0`; IDA call targets and pool layout show these are `PoolAllocator::Free` calls at the consuming destructor paths.
- The constructor-failure wrappers at `0x00502420`, `0x00514ae0-0x00514d1e`, and `0x0053ce50` all have the same MSVC EH/security-cookie wrapper shape and call `PoolAllocator::Free`; they are ignored as standalone source in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Source-Structure Decision

Declare the `PoolAllocator` type and lifecycle methods in the shared utility/string/container area. Declare each concrete static pool near the class module that owns the allocation policy:

- object-pane pools with their corresponding map-object source files;
- `Motion` pool with the animation/motion source;
- `UserPane` pool with `ui/panels/UserPane.cpp`;
- string-buffer pools with `StringUtil.cpp` or a future `StringBase.cpp`.

Do not collapse all concrete globals into `PoolAllocator.cpp`; that file should own allocator mechanics, not every typed pool instance.

## Cross-References

- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md)
- [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md)
- [UID:0001F4][0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper](by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md)
- [UID:0000WC][0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers](by-memory/0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md)
- [UID:0001O8][0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers](by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md)
- [UID:0001AA][0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper](by-memory/0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper.md)
- [UID:0001B3][0x00514ae0-0x00514d1e.ObjectPanePoolFreeUnwindWrappers](by-memory/0x00514ae0-0x00514d1e.ObjectPanePoolFreeUnwindWrappers.md)
- [UID:0001DK][0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper](by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md)
- [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented the static pool instances, object/string pool tables, failure wrappers, init/cleanup ranges, evidence, and source-structure decision but remained unevaluated.
  - After: score reflects detailed addresses, block sizes/counts, constructor/destructor wrappers, owner hypotheses, wrapper classification, and concrete pool source-placement guidance.
  - Evidence: IDA notes confirm nineteen static constructor/destructor wrappers, xrefs matching class owners, PoolAllocator layout/calls, and constructor-failure wrapper shapes.
