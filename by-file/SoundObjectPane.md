*** UID:0000NW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SoundObjectPane

## Status

- Confidence: very strong for class/file responsibility, exact source order, typed ObjectPane link, playback/timer behavior, pool and compiler boundaries, and generated contract.
- Proposed module: `map/SoundObjectPane.cpp`
- Historical recovery source: `source-3/simroot_v2/class_SoundObjectPane.cpp`; current source authority is the ordinary by-* emitter route and validator-generated `NexusTK/map/SoundObjectPane.cpp`.
- Primary class doc: [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md)
- Main address docs: [UID:0001DJ][0x0053ca20-0x0053ce3c.SoundObjectPaneCore](by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md), [UID:000387][0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor](by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md), and mixed inventory [UID:0001DN][0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md)

## File Role

`SoundObjectPane.cpp` likely owns positional or map-attached sound objects. It derives through [UID:0000M5][ObjectPane](by-file/ObjectPane.md), stores sound position/target position and playback parameters, starts immediate or delayed playback, and schedules repeat/random trigger behavior through the map object/timer infrastructure.

This file is a map-object consumer of [UID:0000NV][SoundManager](by-file/SoundManager.md), not the sound system itself. The sound manager owns sample playback and audio backends; `SoundObjectPane` owns map object lifetime, linkage to an owning object, and trigger/removal rules.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| static pool | [UID:0002WN][0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage](by-memory/0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md), position 0 | Module-local PoolAllocator declaration with block `0x158`, chunk count `0x20`; compiler wrappers own initialization/cleanup/allocation/free mechanics. |
| class declaration | [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md), position 10 | Complete ObjectPane-derived `0x158` layout, typed records/enums/fields, and four source methods. |
| constructor | [UID:0004PV][0x0053ca20-0x0053cab4.SoundObjectPaneConstructor](by-memory/0x0053ca20-0x0053cab4.SoundObjectPaneConstructor.md), position 20 | Typed record construction and playback-policy initialization. |
| ordinary destructor | [UID:0004PW][0x0053cac0-0x0053cb48.SoundObjectPaneDestructor](by-memory/0x0053cac0-0x0053cb48.SoundObjectPaneDestructor.md), position 30 | Clears the typed linked-owner reference, removes from active MapPane, and relies on inherited teardown. |
| `StartPlayback` | [UID:0004PX][0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback](by-memory/0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback.md), position 40 | Five playback modes, three lifetime policies, immediate/delayed timers, and repeat-count setup. |
| `OnTimer` | [UID:0004PY][0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer](by-memory/0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer.md), position 50 | Live TimerHandler callback with deterministic/random playback, count/timeout lifecycle, rescheduling, and handled return. |
| vtable coverage | [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md), position 60 | Primary/EventHandler/TimerHandler RTTI-vtable views and adjustors regenerated from the class. |
| threshold coverage | [UID:0003CB][0x00620c6c-0x00620c70.SoundObjectPaneRandomThresholdConstant](by-memory/0x00620c6c-0x00620c70.SoundObjectPaneRandomThresholdConstant.md), position 70 | Exact source literal `32767.0f` covered inside OnTimer. |
| playback starter | `0x0053cb50-0x0053cc5c` | Consumes playback mode fields and either plays immediately, destroys itself, or arms a timer token at `this+0xa4`. |
| trigger handler | `0x0053cc70-0x0053ce3c` | Handles mode `2`, counted-play mode `3`, and probability mode `4`, scheduling follow-up triggers as needed. |
| RTTI/vtable data | [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md) | Source-declared/generated-binary class vtables assigned to the `SoundObjectPane` class parent. |

## Boundary Notes

- Active generated output omits the real non-deleting destructor at `0x0053cac0-0x0053cb48`. The scalar deleting destructor duplicates the same cleanup plus optional `operator delete`.
- 2026-06-11 exact destructor split [UID:000387][0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor](by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md) confirms the file-owned scalar deleting destructor at `0x0053d660-0x0053d739`; it clears linked-object sound references, unregisters through `0x00506cc0`, tears down `ObjectPane`, and optionally frees through the SoundObjectPane static pool at `0x0069b8e4`.
- Current scalar disposition is compiler-only/non-emitting: UID000387 retains semantic class ownership but ordinary UID0004PW source plus the class/pool declaration regenerates its vptr, adjustor, delete-flag, size-guard, base-teardown, and optional pool-return mechanics.
- Exact source order is pool/class/constructor/destructor/StartPlayback/OnTimer/vtable-covered/threshold-covered at positions `0/10/20/30/40/50/60/70`. UID0001DJ is a blank non-emitting semantic split index and never duplicates the four children.
- SoundObjectPane owns object-local lifecycle and timer behavior. MapPane owns opcode `0x19` packet parsing and construction arguments; SoundManager owns sample playback; TimerMgr owns scheduling; ObjectPane owns the typed `SoundObjectPane *` owner link methods.
- Behavior preserved at source level: five startup modes, persistent/count/timeout policies, timer ids zero/one, timeout seconds-to-milliseconds conversion, strict `probability*32767 > float(rand())`, failed-random count consumption, unconditional callback handled return, no singleton null checks, and no explicit timer cancellation.
- Compiler exclusions are both alignment spans, the five-entry StartPlayback table, vptr/EH/cookie support, EventHandler/TimerHandler adjustors, RTTI/vtable arrays, scalar deleting wrapper, delete flags, size guard, base teardown sequence, and pool-free wrapper. No duplicate handwritten compiler source belongs in this file.
- Historical `OnTriggerSound`, probability-at-`+0x144`, generic ObjectPane image-state link, all-`ff` pool source, aggregate emission, and recovery-source authority remain explicitly superseded assumptions.
- This by-file page is prose-only. It intentionally has no RECONSTRUCTION_CPP metadata; source emission flows through the class and exact by-memory leaves.
- Exact RTTI/vtable child [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md) is now routed through [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md). It starts at `0x00620ae4 -> ??_R4SoundObjectPane@@6B@`, includes primary and two adjusted views, and ends at `0x00620b90` before the BowGauge resource string tail.
- Constructor callers at `0x0050ec30` and `0x00512f20` build sound objects from map/object packet flows and call `StartPlayback` immediately in two paths.
- Adjustor thunk `0x0053cf72` is emitted; thunk `0x0053cf7d` is real in IDA but currently listed as missing code in disabled output.
- `0x0053ce40` and `0x0053ce50` are not part of this class. `0x0053ce50` is the [UID:0001DK][0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper](by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md), sitting between the sound trigger body and later object-pane destructor/allocator thunks.
- 2026-05-26 IDA static-pool review identifies the [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md) [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) at `0x0069b8e4`, constructed by `0x0041a140` with block size `344` and `32` blocks per chunk.

## Cross-References

- [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md)
- [UID:0001DJ][0x0053ca20-0x0053ce3c.SoundObjectPaneCore](by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md)
- [UID:000387][0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor](by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md)
- [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md)
- [UID:0001DN][0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- [UID:0001DK][0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper](by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md)

## Changes

- 2026-07-14 B002 UID0001DJ callback:
  - Raised `85/87 -> 92/92` and recorded the complete `NexusTK/map/SoundObjectPane.cpp` source order and ownership contract without adding by-file reconstruction metadata.
  - Added real child UIDs, pool/class/vtable/threshold positions, complete mode/policy/timer and typed-link behavior, source/compiler separation, dependency boundaries, generated contract, and historicalized stale aliases while preserving unrelated family evidence.

- 2026-06-05: Assigned projected reconstruction folder.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - After: set the folder to `NexusTK/map/`.
  - Evidence: live IDA MCP lookup confirms the documented `SoundObjectPane` constructor anchor at `0x0053ca20`; proposed-source-tree keeps positional sound objects with the map object companion files, while `SoundManager.cpp` remains the audio-backend owner.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `86`.
  - Evidence: document covers map-object role, proposed contents, destructor/playback/trigger behavior, constructor callers, boundary exclusions, pool allocator evidence, and cross-references; confidence is high because class role and core range are strongly anchored.
- 2026-06-11 A008 Batch 171: Raised completion/confidence from `82/86` to `85/87` after exact scalar destructor child [UID:000387][0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor](by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md) split and live IDA confirmation of sound destructor boundary, adjustor/vtable refs, map unregister, base cleanup, and pool-free behavior.
- 2026-06-12 A003 Batch 279: Kept file score at `85/87` and linked the exact assigned vtable child [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md). No file score increase because IDA MCP was unavailable for a fresh source-file-wide audit during this pass.

## 2026-08-22 UID0000MM Accepted PoolAllocator Dependency Callback

- Formal CPP dependency: `#include "../util/PoolAllocator.h"`, emitted by [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md) into this file's existing source route.
- Retained consumer declarations: `static PoolAllocator g_soundObjectPanePool(0x158, 0x20);`.
- Inventory linkage: P03; exact ranges, bytes, xrefs, wrapper topology, and supervisor-owned materialization actions remain on their UID-bound storage pages and the accepted UID0000MM report.
- Routing: The declaration remains on UID0002WN at child position 0 and is emitted through UID0000DH/UID0000NW.
- Formal H disposition: no PoolAllocator declaration is duplicated here; the CPP include supplies the complete standalone utility type.
- Generated acceptance: the earlier command-26311/26323/26351/26355 observations are dated prestates only. The scoped callback validator must regenerate this CPP with the include and unchanged consumer declaration(s), and the dated physical file receipt is recorded in the accepted report.
