*** UID:0000TI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PoolAllocatorStaticInstances

## Status

- Entity kind: reviewed grouped global-data inventory.
- Disposition: non-emitting mixed-owner index; exact pool-storage children carry the reconstructable source declarations.
- Confidence: very strong for addresses, block sizes, block counts, and xref relationships; medium-high for final per-owner global names.
- Proposed owner: none for this aggregate. [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) owns allocator mechanics, while concrete declarations belong near each consuming class/module.
- Parent status: reviewed ownership split; parent remains blank because this inventory spans multiple concrete source owners and is not itself a single source-level global.

## Role

The binary constructs nineteen static [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) instances during startup. This page records the cross-cutting inventory only. Eight are ref-counted string-buffer pools; the remaining eleven are object/class pools for map panes, animation state, and the large local user pane.

Each instance has the [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md) shape:

```text
+0x00 blockSize
+0x04 blocksPerChunk
+0x08 chunkList
+0x0c freeList
+0x10 CRITICAL_SECTION
```

The startup wrappers call `0x004b13d0`, register a matching `atexit` cleanup wrapper, and the consuming constructors/destructors call the allocator island at `0x004b1400` and `0x004b14c0`.

This aggregate is intentionally `RECONSTRUCTABLE:FALSE`: no original source file should emit a monolithic `PoolAllocatorStaticInstances` declaration. The rebuild-relevant declarations are represented by exact storage children, including object-pane pool children under [UID:0002B4][0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage](by-memory/0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage.md), string-buffer storage [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md), and UserPane storage [UID:0002AC][0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage](by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md).

Constructor-failure cleanup wrappers are documented separately because they are compiler-generated EH/delete thunks, not normal source methods. They still provide useful evidence for concrete pool ownership.

## Descriptive Global Names

B002's 2026-06-20 source-quality pass keeps this aggregate non-emitting but resolves preferred descriptive names for comments and support docs. These are inferred names, not proof of exact original spelling; concrete declarations still belong with the consuming modules rather than in `PoolAllocator.cpp`.

| Address | Descriptive name | Owner placement |
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
| `0x0069bb94` | `g_ansiPool128` | StringBase / UID0000TM |
| `0x0069baf4` | `g_widePool128` | StringBase / UID0000TM |
| `0x0069bbbc` | `g_ansiPool256` | StringBase / UID0000TM |
| `0x0069bb1c` | `g_widePool256` | StringBase / UID0000TM |
| `0x0069bbe4` | `g_ansiPool512` | StringBase / UID0000TM |
| `0x0069bb44` | `g_widePool512` | StringBase / UID0000TM |
| `0x0069bb6c` | `g_ansiPool64` | StringBase / UID0000TM |
| `0x0069bacc` | `g_widePool64` | StringBase / UID0000TM |

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
- Some analysis aliases name these calls through `ThreadSafeNodeList::PushFront` or `cls_0x4b14c0::meth_0x4b14c0`; IDA call targets and pool layout show these are `PoolAllocator::Free` calls at the consuming destructor paths.
- The constructor-failure wrappers at `0x00502420`, `0x00514ae0-0x00514d1e`, and `0x0053ce50` all have the same MSVC EH/security-cookie wrapper shape and call `PoolAllocator::Free`; they are ignored as standalone source in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-06-07 live IDA MCP recheck confirmed the object/pane pool xref shape: each non-string pool has a static constructor wrapper, a registered cleanup wrapper, and allocator/free consumers matching the owner-hypothesis column. Examples include the `UserPane` pool at `0x0069bf34` with constructor `0x0041a4b0`, use from `0x004f7d10` and `0x00502420`, destructor use at `0x005b8230`, and cleanup `0x0060c450`.
- The same recheck confirmed that each of the eight string-buffer pools has exactly four direct xref groups: one static constructor wrapper, one allocation helper, one release helper, and one static cleanup wrapper. The ANSI pools route through `0x00582d80` / `0x005832f0`, and the wide pools route through `0x00582e30` / `0x005833a0`.
- Function-size rechecks keep the allocator island bounded: constructor helper `0x004b13d0` is `0x30` bytes, allocation helper `0x004b1400` is `0xb8` bytes, free helper `0x004b14c0` is `0x2f` bytes, and chunk cleanup `0x004b1520` is `0x65` bytes.
- 2026-06-11 Agent-A006 live IDA MCP recheck reconfirmed allocator method/helper bounds and caller groups while refreshing the parent/source context: `0x004b13d0`, `0x004b1400`, `0x004b14c0`, `0x004b1520`, `0x00549bd0`, and `0x00549c00` keep the same sizes; `0x004b13d0` still has nineteen static constructor callers; `0x004b1400` and `0x004b14c0` still fan out through object-pane, `Motion`, `UserPane`, and string-buffer consumers; `0x00549bd0` is still only called from `PoolAllocator::Allocate`; and `0x00549c00` is still only called from `PoolAllocator` destruction.
- 2026-06-12 Agent-A002 Batch 309 live IDA MCP session `b001_nexustk` reconfirmed the same ownership split. Representative object-pane pool `0x0069b894` has five direct refs through constructor `0x0041a100`, owner allocation `0x00505e00`, unwind free `0x00514c60`, scalar destructor `0x0053d430`, and cleanup `0x0060c380`; representative object-pane pool `0x0069b9fc` has six direct refs through constructor `0x0041a040`, owner/allocation paths `0x00468f80`, `0x0050e100`, `0x00511710`, unwind free `0x00514ae0`, and cleanup `0x0060c320`.
- The same live check reconfirmed string-pool direct-reference patterns: wide pool `0x0069bacc` has constructor `0x0041a260`, allocate `0x00582e30`, release `0x005833a0`, and cleanup `0x0060c430`; ANSI pool `0x0069bb6c` has constructor `0x0041a240`, allocate `0x00582d80`, release `0x005832f0`, and cleanup `0x0060c420`.
- The same live check reconfirmed the separate UserPane pool pattern at `0x0069bf34`: constructor `0x0041a4b0`, allocation sites in `0x004f7d10`, unwind free `0x00502420`, scalar destructor pool return `0x005b8230`, and cleanup `0x0060c450`.
- Live IDA `xrefs_to` reconfirmed shared allocator mechanics, not aggregate ownership: `0x004b13d0` has nineteen static constructor callers, `0x004b1400` has 33 allocation callers across object-pane/string/UserPane consumers, `0x004b14c0` has 30 free callers across the same families, and `0x004b1520` has nineteen cleanup wrapper callers.
- Live IDA `analyze_component` confirmed representative static constructor wrappers call `sub_4B13D0` and `_atexit` while cleanup wrappers are 10-byte destructor wrappers. `int_convert.py` reconfirmed `0x28` / 40-byte storage records, `0x20c` / 524-byte LivingObjectPane blocks, `0x1e0` / 480-byte BalloonObjectPane blocks, `0x8e` / 142-byte wide string-pool blocks, `0x4d` / 77-byte ANSI string-pool blocks, and 1305476 / `0x13eb84` for the large UserPane pool block size.
- Historical sampled all-`ff` storage wording is superseded by later zero-byte physical reads and the accepted isolated-TX fragmented-undefined prestate. Prior name conclusions are retained only as dated, channel-qualified evidence; a same-address name-catalog binding does not require `inspect_items.name` to display the same spelling.

## Source-Structure Decision

Declare the `PoolAllocator` type and lifecycle methods in standalone `NexusTK/util/PoolAllocator.h/.cpp`. Do not emit this aggregate as source. Declare each concrete static pool near the class module that owns the allocation policy:

- object-pane pools with their corresponding map-object source files;
- `Motion` pool with the animation/motion source;
- `UserPane` pool with `ui/panels/UserPane.cpp`;
- string-buffer pools with current `StringBase.cpp` through [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md).

Do not collapse all concrete globals into `PoolAllocator.cpp`; that file should own allocator mechanics, not every typed pool instance.

## Assignment Gate

No parent UID is set. [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) is `94/94` as the allocator-mechanics owner, but it is not the direct owner for this grouped global inventory. This page spans concrete static instances whose source declarations belong beside object-pane, `Motion`, `UserPane`, and StringBase modules rather than one single source root.

Batch 309 reclassifies the aggregate itself as `RECONSTRUCTABLE:FALSE`, matching the already-split by-memory model: the exact pool-storage children are source-declared/generated-binary reconstructable items, while this by-global page is a reviewed cross-cutting index. Do not route the aggregate to a parent to clear autogen coverage; route only exact children or homogeneous grouped globals when the child and true direct parent both clear `85/85`.

## 2026-07-29 B008 UID0002WS Gate 2B Readback

- Supervisor catalog entry `0350` materialized ItemObjectPane instance `[0x0069b9ac,0x0069b9d4)` as exactly one 40-byte `struct PoolAllocator g_itemObjectPanePool` data item with the accepted regular/repeatable comments. All forty bytes remain zero; five exact base xrefs, zero checked interior xrefs, source range, neighboring pools, and compiler startup/cleanup wrappers are unchanged.
- Type state was preserved: opaque `PoolAllocator` remains ordinal `444`, size `40`, sole `_opaque : unsigned __int8[40]`; already-present `PoolChunkHeader` ordinal `934` and `PoolFreeBlock` ordinal `935` remain size `4` with sole self-pointer `next` members. No UDT or member mutation/comment was performed.
- Shared allocator readback now resolves exact `PoolAllocator_Constructor`, `PoolAllocator_Allocate`, `PoolAllocator_Free`, `PoolAllocator_Destructor`, `PoolAllocator_AllocateChunk`, and `PoolAllocator_FreeChunkList` identities, ranges, ABI-safe types, and accepted function-regular comments. `PoolAllocator_Allocate` was exact no-change; the other five identities/types/comments were restored. Protected internal comments remain exact and their repeatable channels remain blank.
- Typed-signature persistence normalized physical argument-frame labels only for constructor A02 (`blockSize`, `blocksPerChunk`), free A04 (`block`), and chunk allocator A06 (`chunkListHead`, `blocksPerChunk`, `blockSize`). Supervisor rename-stack dry-run rejected raw-name restoration with literal `Argument member`; Hex-Rays names/types, calling conventions, offsets, widths, nonargument frames, bytes, xrefs, and ABI remain exact.
- Saved IDB SHA256 is `41977C87379D1A8BDC199A9A17DE3E117E365E3A596828DFA6FA0D7C2FA60DD3`, size `143190178`, last write `2026-07-29T03:12:58.7364596-04:00`. Prestate backup `source-3/project-documentation/tools/leaser/Agents/ida-backups/NexusTK.exe.before-B008-UID0002WS-20260729-031039.i64` has SHA256 `B46BEB1B347B569129E0B9F9BB53C51E4560EF6249081256D31EAC53A95F1A41`.

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

- 2026-08-22 B001 UID0000MM Gate 2A ordinary repair:
  - Closed P11-P18 placement under StringBase/UID0000TM, replaced the stale `86/85` parent clearance with current `94/94`, and retained this aggregate at `89/92`, owner `NONE`, non-emitting, and non-reconstructable.
  - Preserved corrected zero-byte/all-FF history and channel-qualified name evidence, and promoted the accepted P01-P19 table below to the active complete inventory.

- 2026-07-29 B008 UID0002WS Gate 2B support reconciliation:
  - Added catalog entry `0350` target-item/type/helper/function/frame-normalization/readback/save evidence without changing this distributed inventory's `89/92`, non-emitting classification, or parentless ownership decision.

- 2026-06-12 Agent-A002 Batch 309 by-structure repair:
  - Before: `COMPLETION:87`, `CONFIDENCE:89`, `RECONSTRUCTABLE:TRUE`, and blank parent, which left the global coverage item autogen-unassigned despite documented mixed ownership.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, parent still blank.
  - Summary/evidence: live IDA MCP session `b001_nexustk` reconfirmed representative object-pane, string-buffer, and UserPane pool xref patterns; allocator mechanics still fan out through nineteen constructor wrappers, 33 allocation callers, 30 free callers, and nineteen cleanup wrappers. Existing exact memory children carry the reconstructable declarations: object-pane pool children under [UID:0002B4][0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage](by-memory/0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage.md), string-buffer storage [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md), and UserPane storage [UID:0002AC][0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage](by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md).
  - Gate rationale: no single direct parent exists for the aggregate. [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) owns allocator mechanics only, not all concrete static declarations. Marking the aggregate non-emitting is the by-structure repair; routing remains reserved for exact children whose direct owners clear `85/85`.
- 2026-06-20 B002 Rule 26 source-quality incorporation:
  - Before: page documented ownership hypotheses and static pool addresses but did not record the preferred descriptive `g_*Pool` names from the PoolAllocator source-quality pass.
  - After: metadata unchanged at `89/92`, `RECONSTRUCTABLE:FALSE`, with a descriptive global-name table added for comments/support use.
  - Summary/evidence: B002's report reconfirmed that concrete static pools remain distributed by consumer module while `PoolAllocator.cpp` owns only allocator mechanics; object-pane, `Motion`, `UserPane`, and string-buffer pool names are therefore useful inferred labels but not a monolithic source declaration.
- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented the static pool instances, object/string pool tables, failure wrappers, init/cleanup ranges, evidence, and source-structure decision but remained unevaluated.
  - After: score reflects detailed addresses, block sizes/counts, constructor/destructor wrappers, owner hypotheses, wrapper classification, and concrete pool source-placement guidance.
  - Evidence: IDA notes confirm nineteen static constructor/destructor wrappers, xrefs matching class owners, PoolAllocator layout/calls, and constructor-failure wrapper shapes.
- 2026-06-05: Marked reconstructable and left parent attachment blank.
  - Reason: the static pool instances are source-declared data, but this page intentionally documents a distributed inventory whose concrete declarations belong beside multiple consuming modules rather than one single source root.
- 2026-06-07: Grading changed from `84/88` to `86/88`.
  - Before: page documented the pool inventory and source-placement rule but lacked a current grouped xref/function-boundary recheck.
  - After: score reflects live confirmation that the object/pane pools have constructor/use/free/cleanup relationships, the eight string pools each have the expected four xref groups, and the allocator core boundaries remain stable.
- 2026-06-11 Agent-A006 Batch 147 ownership-split refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`, and assignment-gate text still cited the allocator-mechanics parent as below the strict gate.
  - After: `COMPLETION:87`, `CONFIDENCE:89`, parent remains blank intentionally.
  - Evidence: live IDA reconfirmed allocator method/helper bounds, constructor/allocate/free caller groups, and helper-only ownership. [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) was refreshed to `86/85`, but the aggregate still has no single correct direct parent because concrete static pool declarations are distributed across object-pane, `Motion`, `UserPane`, and string-buffer owners.

## Complete P01-P19 Inventory

This page remains the non-emitting, mixed-owner inventory. The accepted source reconstruction is distributed to the exact owner/emitter pages below; no declaration is duplicated here.

| Pool | Exact storage range | Source-facing declaration | Constructor policy | Exact current direct xrefs | Exact source route |
|---|---|---|---|---|---|
| P01 | `0x0069b894-0x0069b8bc` | `g_livingObjectPanePool` | `0x20c, 0x20` | `0x0041a107, 0x00506071, 0x00514c85, 0x0053d542, 0x0060c380` | [UID:0002WL][0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage](by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md) -> [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) |
| P02 | `0x0069b8bc-0x0069b8e4` | `g_staticObjectPanePool` | `0x12c, 0x10` | `0x0041a167, 0x0050f086, 0x00514d05, 0x0053d776, 0x0060c3b0` | [UID:0002WM][0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage](by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md) -> [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md) |
| P03 | `0x0069b8e4-0x0069b90c` | `g_soundObjectPanePool` | `0x158, 0x20` | `0x0041a147, 0x0050ec68, 0x0050ed2c, 0x00513199, 0x00513256, 0x00514cc5, 0x0053d6f2, 0x0060c3a0` | [UID:0002WN][0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage](by-memory/0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md) -> [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md) |
| P04 | `0x0069b90c-0x0069b934` | `g_effectObjectPanePool` | `0x150, 0x10` | `0x0041a087, 0x0050eaa6, 0x00514b85, 0x0053d150, 0x0060c340` | [UID:0002WO][0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage](by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md) -> [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) |
| P05 | `0x0069b934-0x0069b95c` | `g_hitBarObjectPanePool` | `0x138, 4` | `0x0041a0c7, 0x0050e5fc, 0x0050e778, 0x0050ee2b, 0x00514c05, 0x0053d290, 0x0060c360` | [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md) -> [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) |
| P06 | `0x0069b95c-0x0069b984` | `g_damageNumberObjectPanePool` | `0x148, 8` | `0x0041a067, 0x0050ef4e, 0x00512a73, 0x00514b45, 0x0053d0b0, 0x0060c330` | [UID:0002WQ][0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage](by-memory/0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage.md) -> [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md) |
| P07 | `0x0069b984-0x0069b9ac` | `g_motionPool` | `0x1c, 0x10` | `0x0041a124, 0x0053b5d5, 0x0053ce75, 0x0053d5d0, 0x0060c390` | [UID:0002WR][0x0069b984-0x0069b9ac.MotionPoolStaticStorage](by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md) -> [UID:00008R][Motion](by-class/Motion.md) |
| P08 | `0x0069b9ac-0x0069b9d4` | `g_itemObjectPanePool` | `sizeof(ItemObjectPane), 8` (`0x12c, 8`) | `0x0041a0e7, 0x00505e66, 0x00514c45, 0x0053d330, 0x0060c370` | [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md) -> [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) |
| P09 | `0x0069b9d4-0x0069b9fc` | `g_flyingObjectPanePool` | `0x144, 4` | `0x0041a0a7, 0x0050e06b, 0x00512e8e, 0x00514bc5, 0x0053d1f0, 0x0060c350` | [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md) -> [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md) |
| P10 | `0x0069b9fc-0x0069ba24` | `g_balloonObjectPanePool` | `0x1e0, 0x10` | `0x0041a047, 0x00469007, 0x0050e17f, 0x005118b9, 0x00514b05, 0x0060c320` | [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md) -> [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md) |
| P11 | `0x0069bacc-0x0069baf4` | `mystr::g_widePool64` | `0x8e, 0x40` | `0x0041a267, 0x00582e50, 0x005833cd, 0x0060c430` | [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md) -> [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) |
| P12 | `0x0069baf4-0x0069bb1c` | `mystr::g_widePool128` | `0x10e, 0x40` | `0x0041a1a7, 0x00582e6b, 0x005833e8, 0x0060c3d0` | [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md) -> [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) |
| P13 | `0x0069bb1c-0x0069bb44` | `mystr::g_widePool256` | `0x20e, 0x40` | `0x0041a1e7, 0x00582e86, 0x00583403, 0x0060c3f0` | [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md) -> [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) |
| P14 | `0x0069bb44-0x0069bb6c` | `mystr::g_widePool512` | `0x40e, 0x40` | `0x0041a227, 0x00582ea1, 0x0058341e, 0x0060c410` | [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md) -> [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) |
| P15 | `0x0069bb6c-0x0069bb94` | `mystr::g_ansiPool64` | `0x4d, 0x40` | `0x0041a244, 0x00582da0, 0x0058331d, 0x0060c420` | [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md) -> [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) |
| P16 | `0x0069bb94-0x0069bbbc` | `mystr::g_ansiPool128` | `0x8d, 0x40` | `0x0041a187, 0x00582dbb, 0x00583338, 0x0060c3c0` | [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md) -> [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) |
| P17 | `0x0069bbbc-0x0069bbe4` | `mystr::g_ansiPool256` | `0x10d, 0x40` | `0x0041a1c7, 0x00582dd6, 0x00583353, 0x0060c3e0` | [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md) -> [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) |
| P18 | `0x0069bbe4-0x0069bc0c` | `mystr::g_ansiPool512` | `0x20d, 0x40` | `0x0041a207, 0x00582df1, 0x0058336e, 0x0060c400` | [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md) -> [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) |
| P19 | `0x0069bf34-0x0069bf5c` | `g_userPanePool` | `sizeof(UserPane), 2` (`0x13eb84, 2`) | `0x0041a4b7, 0x004f84c5, 0x004f8a2c, 0x00502445, 0x005b834e, 0x0060c450` | [UID:0002AC][0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage](by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md) -> [UID:0000P1][UserPane](by-file/UserPane.md) |

For P01-P19 the accepted isolated-TX prestate is one undefined byte item at each base followed by separate undefined bytes across the exact 40-byte range, forty zero bytes, no address comments, and zero xrefs at each of the nine field-aligned interior offsets. That fragmented presentation is historical prestate, not a source declaration. Supervisor Gate 2B owns materialization of one exact 40-byte typed item, the source-facing name, and the accepted regular comment per record; this ordinary-document callback neither mutates nor claims that IDA poststate.
