*** UID:0000LL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Motion

## Status

- Current source module: `NexusTK/render/Motion.cpp` for the timer-driven animation object.
- Split-owner guard: keep [UID:0000N3][Region](by-file/Region.md) / `NexusTK/ui/core/Region.cpp` for dirty rectangles, [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) / `NexusTK/ui/dialogs/MessageDialogs.cpp` for the dialog packet dispatcher, and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) / `NexusTK/render/NewHumanImageLib.cpp` for `Motion.tbl` vector helpers.
- Confidence: very strong for the live IDA-backed source split, direct Motion animation parent role, seven-item source order, and explicit non-Motion exclusions. The exact original physical filename and private member spellings remain inferred.

## File Role

This page records the Motion/Region ownership split. The historical `Motion` label is not a safe one-to-one original source file. It mixes:

- timer-driven animation object code;
- dirty-rectangle/region helper code;
- a message/menu-question dialog packet dispatcher;
- `NewHumanImageLib` `Motion.tbl` vector helper names in adjacent globals.

## Source Split

```text
NexusTK/render/Motion.cpp
  static PoolAllocator g_motionPool(0x1c, 0x10)
  timer-driven Motion animation constructors
  Motion::OnTimer
  compiler-generated scalar deleting wrapper and adjusted thunk
  source-declared RTTI/vtable consequences

NexusTK/ui/core/Region.cpp
  one Region class and all nineteen Region method bodies
  nested Intersects/ContainsRect/Contains/HasSameBoundsAs children
  Region.h plus RectBounds geometry declarations

NexusTK/ui/dialogs/MessageDialogs.cpp
  HandleDialogPacket_54C200 and related dialog allocation wrappers

NexusTK/render/NewHumanImageLib.cpp
  VectorGrowMotion
  DestroyMotionVector
  Motion.tbl record/vector structs
```

`NexusTK/render/Motion.cpp` is the accepted source-facing route. The exact original disk filename remains unavailable from the stripped binary, but that residual uncertainty does not reopen ownership or source order. The reconstruction rule remains not to migrate every historical `Motion`-labeled range into this source file.

The accepted [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md) split resolves `Region::Intersects`, `Region::ContainsRect`, `Region::Contains`, and `Region::HasSameBoundsAs` as Region.cpp-owned methods. Their physical filenames retain historical Motion tokens, but their current source receivers are Region and they remain outside this timer-driven animation `Motion.cpp` route.

The 2026-08-11 UID0000N3 whole-file pass supersedes the mixed receiver wording retained by the 2026-07-04 callback. The complete modeled island is `Region::IsEmpty`, `SetEmpty`, `SetRect`, `CopyRectFrom`, `IntersectWith`, `IntersectWithRect`, `UnionWithRect`, `UnionWith`, `SubtractRect`, `SubtractRectFrom`, `Offset`, `IntersectsRect`, the four nested children, and pointer-returning `GetRect`. This does not change this file's animation ownership route.

[UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md) now emits only a formal no-raw-vtable marker through this `NexusTK/render/Motion.cpp` route. Its bytes are compiler-emitted RTTI/vtable data regenerated from the Motion class declaration and virtual destructor/timer slots, not source-authored dword arrays.

## Contents By Family

| Family | Range | Proposed owner |
| --- | --- | --- |
| Static Motion pool declaration | `0x0069b984-0x0069b9ac` | This page / `NexusTK/render/Motion.cpp` through [UID:00008R][Motion](by-class/Motion.md), position `20`. Exact child: [UID:0002WR][0x0069b984-0x0069b9ac.MotionPoolStaticStorage](by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md), emitting `static PoolAllocator g_motionPool(0x1c, 0x10);`. |
| Animation object | `0x00539bc0-0x0053a10c`, plus destructor `0x0053d590-0x0053d614` | This page / `NexusTK/render/Motion.cpp`, backed by non-emitting split index [UID:0001DD][0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster](by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md). Exact children are [UID:0002QW][0x00539bc0-0x00539d43.MotionAnimationConstructor](by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md) at `30`, [UID:0002QX][0x00539de0-0x00539f52.MotionAnimationAlternateConstructor](by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md) at `40`, [UID:0002QY][0x00539fe0-0x0053a10c.MotionOnTimer](by-memory/0x00539fe0-0x0053a10c.MotionOnTimer.md) at `50`, and discontiguous compiler scalar wrapper [UID:0002QZ][0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md) at `60`. |
| Region and dirty rectangles | `0x00554680-0x00554b38`, including complete UID0001FW parent bodies and split children [UID:00042Q][0x00554a20-0x00554a3c.MotionIntersectsRaw](by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md), [UID:00042R][0x00554a40-0x00554a56.MotionContainsRectRaw](by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md), [UID:00042S][0x00554a60-0x00554a9b.MotionContains](by-memory/0x00554a60-0x00554a9b.MotionContains.md), and [UID:00042T][0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw](by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md) | [UID:0000N3][Region](by-file/Region.md) and nested emitter [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md). All current receivers are Region; Motion-prefixed filenames are historical provenance only. |
| Dialog packet dispatcher/wrappers | `0x0054c200-0x0054caa9` | [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) and [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md), not Motion. |
| `Motion.tbl` vector helpers | `0x004e5240`, `0x004e5dd0` | [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not Motion class methods. |
| LObject destructor | `0x004f4a90` | [UID:0000KV][LObject](by-file/LObject.md), not Motion-specific. |

## Current Region Exclusion And Historical Dirty-Motion Assumption

Current source identifies those children as `Region::Intersects`, `Region::ContainsRect`, `Region::Contains`, and `Region::HasSameBoundsAs`. They operate on the exact `0x14` Region UDT with `RectBounds m_bounds` at `+0x04`; animation `Motion` is the separate `0x1c` timer/vtable/pool-backed object around `0x00539bc0-0x0053a10c` plus destructor wrapper `0x0053d590-0x0053d614`.

This page remains the parent for the Motion declaration, pool declaration, animation constructors, `OnTimer`, compiler scalar wrapper, and source-declared vtable disposition. It does not own any Region.cpp method.

Historical reconstruction used `Motion::` receiver names for the Region island because dirty-motion terminology and identical `+0x04` rectangle access were mistaken for a second compatible class. Current Region UDT/RTTI/vtable and complete source brackets reject that interpretation. The older spellings remain in dated history and stable filenames, not in current formal source.

## Current Source Order And Compiler Split

The source-ready order is [UID:00008R][Motion](by-class/Motion.md) class declaration at `10`, [UID:0002WR][0x0069b984-0x0069b9ac.MotionPoolStaticStorage](by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md) at `20`, [UID:0002QW][0x00539bc0-0x00539d43.MotionAnimationConstructor](by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md) at `30`, [UID:0002QX][0x00539de0-0x00539f52.MotionAnimationAlternateConstructor](by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md) at `40`, [UID:0002QY][0x00539fe0-0x0053a10c.MotionOnTimer](by-memory/0x00539fe0-0x0053a10c.MotionOnTimer.md) at `50`, [UID:0002QZ][0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md) at `60`, and [UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md) at `70`.

Only the declaration, pool declaration, two constructor bodies, and `Motion::OnTimer` are hand-authored source. The inline empty virtual destructor in the class declaration accounts for the ordinary destructor source cause. Scalar-delete flag handling, explicit vptr restoration, secondary `TimerHandler` adjustment, base teardown, pool return, EH cleanup, and RTTI/vtable arrays are compiler-generated and must not be duplicated as explicit source bodies.

UID0001FW now carries the complete Region implementation. Both historical `Motion::GetNormalizedRect` and later `Motion::IntersectWithRect` labels for `0x005547e0` are superseded by `Region::IntersectWithRect`; the body still mutates `m_bounds` through `IntersectRects(bounds, &m_bounds, &m_bounds)`.

## Constructor Source Readiness

[UID:0002QW][0x00539bc0-0x00539d43.MotionAnimationConstructor](by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md) now emits formal first-draft C++ through this `NexusTK/render/Motion.cpp` route. The accepted source shape is the primary `Motion::Motion(LivingObjectPane *owner, int motionType, int timerDelay, char soundOverride)` constructor. Current MCP session `0af70ed8` confirms exact range `0x00539bc0-0x00539d43` (`sub_539BC0` size `0x183`), `0x00539d43` not a function, constructor-local table/padding bytes before alternate constructor `0x00539de0`, sole direct caller `0x0053b5f9` in the LivingObjectPane action/effect helper, Motion vptr stores to `0x00620954`/`0x00620964`, Motion pool storage refs at `0x0069b984`, no VA/RVA pointer hits for the start/end, and no local `Motion` UDT. The primary constructor uses the same inferred field family as the alternate constructor/timer child and uses `LivingObjectPane *owner` because motion types `27` and `28` call owner slots `+0x74`/`+0x78`, support-documented as `ShowName()`/`HideName()`. Exact final public header type, enum names, and sound/effect symbolic names remain confidence caps, not blockers for this child-level first draft.

[UID:0002QX][0x00539de0-0x00539f52.MotionAnimationAlternateConstructor](by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md) now emits formal first-draft C++ through this `NexusTK/render/Motion.cpp` route. The accepted source shape is an alternate `Motion::Motion(ObjectPane *owner, int motionType, char terminalFrame, int timerDelay, char soundOverride)` constructor that preserves the exact no-direct-entry-xref caveat, field stores, two source-level switch statements, `g_pConfig + 0x28de71` / `m_motionType16SoundEnabled` type-16 sound gate, and the no-child split for the compiler switch-table bytes at `0x00539f52-0x00539fe0`.

The alternate constructor owner is now narrowed to `LivingObjectPane *`, matching the primary constructor, callback dereferences, and sole construction family. This source readiness does not weaken the split-owner guard. Region dirty rectangles, MessageDialogs packet dispatch, NewHumanImageLib `Motion.tbl` helpers, and adjacent LivingObjectPane/ObjectPane code remain outside the timer-driven `Motion.cpp` animation source bucket.

## OnTimer Source Readiness

[UID:0002QY][0x00539fe0-0x0053a10c.MotionOnTimer](by-memory/0x00539fe0-0x0053a10c.MotionOnTimer.md) emits the complete binary-faithful `bool Motion::OnTimer(int timerId, int arg0, int arg1)` body through this route. It accepts only event `3`; advances the signed current-frame byte; triggers the signed-short sound id at the configured frame with unsigned four-fifths volume scaling; preserves motion-type `27` name-visible hold behavior; reschedules and publishes `this` as the owner's current effect while frames remain; or unlinks one active-list element, clears any nonzero current pointer, queues deferred deletion, and refreshes the active MapPane on completion. The target is a source method, not a TimerHandler implementation body, scheduler wrapper, LivingObjectPane method, or compiler thunk.

## Static Pool Source Readiness

[UID:0002WR][0x0069b984-0x0069b9ac.MotionPoolStaticStorage](by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md) now emits the Motion animation pool declaration through this `NexusTK/render/Motion.cpp` route:

```cpp
static PoolAllocator g_motionPool(0x1c, 0x10);
```

The declaration belongs here because current B003 MCP evidence ties `0x0069b984` to the Motion allocation/free lifecycle: startup wrapper `0x0041a120` constructs the pool with block size `0x1c` and chunks `0x10`, `sub_53B3D0` allocates Motion objects through it, `sub_53CE50` frees constructor-failure/unwind allocations through it, `sub_53D590` frees scalar-deleting-destructor allocations through it, and cleanup wrapper `0x0060c390` destroys it at exit. [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) already records `g_motionPool` as the descriptive source-facing name for the Motion module; exact original global spelling is still inferred.

This source-readiness update does not move PoolAllocator mechanics into this file and does not merge the aggregate [UID:0002B4][0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage](by-memory/0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage.md) into the Motion route. It only gives the exact Motion pool child its declaration under the existing animation source bucket.

## Live IDA Evidence

- IDA MCP on 2026-06-04 used IDB `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Motion animation functions are exact IDA functions: `0x00539bc0-0x00539d43`, `0x00539de0-0x00539f52`, `0x00539fe0-0x0053a10c`, and `0x0053d590-0x0053d614`.
- `0x00539bc0` has one code xref at `0x0053b5f9` inside `0x0053b3d0`. The alternate constructor has no direct entry xrefs, matching a constructor variant retained as a local entry.
- Motion vtable evidence ties the timer/destructor to the animation class: `0x00620954 -> 0x0053d590`, `0x00620964 -> 0x0053cf54`, and `0x00620968 -> 0x00539fe0`; `xrefs_to` reports the data refs at `0x00620954` and `0x00620968`. B008 session `c9ac3d5b` further reconfirmed the exact seven-dword UID000356 range `0x00620950-0x0062096c`, Motion RTTI names at `0x0064cd00` and `0x0064cd6c`, primary/adjusted constructor vptr stores at `0x00539c11/0x00539c17` and `0x00539e47/0x00539e4d`, adjusted thunk `0x0053cf54` as `sub ecx, 4; jmp 0x0053d590`, and the excluded LivingObjectPane/BoxRotator successor at `0x0062096c`.
- Animation constructor callees are `0x004f4a80` and `0x00597570`; timer callees include `0x00506980`, `0x00469120`, `0x00597910`, `0x0057a5c0`, and `0x0057a6c0`; destructor callees include `0x00597580`, `0x004f4a90`, and `0x004b14c0`.
- Region/rectangle functions remain a separate broad UI/render utility island with exact IDA ranges from `0x00554680-0x005546e1` through `0x00554b00-0x00554b38`. Representative code-ref counts are constructor `89`, normalized rect `37`, Region intersect wrapper `51`, and offset `32`; Region vtable slot `0x00622f58 -> 0x00554b00`.
- 2026-07-04 B014 UID0001FW implementation sync supersedes the historical normalized-rect wording for the Region-owned helper at `0x005547e0`; accepted MCP session `nexustk_supervisor_20260704` records it as `Motion::IntersectWithRect`, keeps `0x00554a00` as `Region::IntersectsRect`, and confirms UID0001FW formal C++ now emits through Region.cpp while this file retains animation-only ownership.
- Dialog ownership is separate: `0x0054c200-0x0054c511` has callers at `0x00507e2e` and `0x0051287f`, and calls dialog/menu-question constructors and allocation wrappers including `0x0054ce10`, `0x0054fb30`, `0x0054c870`, `0x0054c8d0`, `0x0054c930`, `0x0054c990`, `0x0054c9f0`, and `0x0054ca50`.
- `Motion.tbl` vector helpers are separate render asset-table support: `0x004e5240-0x004e5415` is called at `0x004e0ff2` from `0x004e0e20`, while `0x004e5dd0-0x004e5e39` is referenced at `0x004e0547` and `0x0060025a` from the `NewHumanImageLib` constructor/destructor family.
- `0x004f4a90` is a seven-byte base destructor function with `366` code refs, so it is not Motion-specific ownership evidence.
- 2026-06-07 A001 Batch094 parent-gate refresh reconfirmed the Motion animation functions at `0x00539bc0` size `0x183`, `0x00539de0` size `0x172`, `0x00539fe0` size `0x12c`, and `0x0053d590` size `0x84`; the constructor xref remains `0x0053b5f9`, timer/destructor vtable refs remain `0x00620968` and `0x00620954`, and the Motion pool root `0x0069b984` is still referenced from initialization, creator, unwind, destructor, and cleanup paths.
- This file is the source-ready direct parent for the Motion class. The remaining filename caveat is about exact original disk naming, not whether the timer-driven animation class belongs in this Motion source bucket.

## 2026-06-16 A001 File-Confidence Refresh

Live IDA MCP session `b001_mappane_0001AW_20260616` was used to refresh the split/placement blockers:

- `lookup_funcs` reconfirmed the Motion-owned animation starts: primary constructor `0x00539bc0` size `0x183`, alternate constructor `0x00539de0` size `0x172`, timer tick `0x00539fe0` size `0x12c`, and scalar deleting destructor `0x0053d590` size `0x84`.
- `xrefs_to` still shows exactly one primary-constructor caller at `0x0053b5f9`, zero direct refs to the alternate constructor, one timer vtable/data ref at `0x00620968`, and destructor refs at `0x0053cf57` and `0x00620954`. The Motion pool root `0x0069b984` has five refs from pool initialization, creator, unwind wrapper, scalar deleting destructor, and static cleanup.
- Callee checks still match an animation object: constructors call base/timer setup; the timer tick calls sound/effect helpers, map/object invalidation, timer scheduling, and deferred cleanup; the scalar deleting destructor calls timer/base cleanup and `PoolAllocator_Free`.
- The non-Motion exclusions remain confirmed: Region helper `0x00554680` has `90` refs and Region vtable slot `0x00622f58 -> 0x00554b00`; dialog dispatcher `0x0054c200` has two packet-handler callers; `Motion.tbl` vector helpers at `0x004e5240`/`0x004e5dd0` are reached from the `NewHumanImageLib` load/destruction family. Boundary bytes at `0x0053a10c` and `0x0053d589` are `0xcc` alignment.
- `find_regex` found the `Motion` RTTI string at `0x00678330`, but no embedded `Motion.cpp` source filename string; `search_structs` found no local IDA UDT. The alternate constructor's zero direct refs and final field/member names remain real source-quality blockers.

The evidence supports a modest score raise for the file root without collapsing the explicit Region, MessageDialogs, NewHumanImageLib, and LivingObjectPane/ObjectPane split decisions back into the Motion source bucket. B007 later resolved the child-specific alternate-constructor source-shape blocker for [UID:0002QX][0x00539de0-0x00539f52.MotionAnimationAlternateConstructor](by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md) without changing this file's route or the remaining exact-original-filename caveat.

## Cross-References

- [UID:00008R][Motion](by-class/Motion.md)
- [UID:0000N3][Region](by-file/Region.md)
- [UID:0000BV][Region](by-class/Region.md)
- [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md)
- [UID:00042Q][0x00554a20-0x00554a3c.MotionIntersectsRaw](by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md)
- [UID:00042R][0x00554a40-0x00554a56.MotionContainsRectRaw](by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md)
- [UID:00042S][0x00554a60-0x00554a9b.MotionContains](by-memory/0x00554a60-0x00554a9b.MotionContains.md)
- [UID:00042T][0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw](by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md)
- [UID:0001DD][0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster](by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md)
- [UID:0002WR][0x0069b984-0x0069b9ac.MotionPoolStaticStorage](by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000KL][Layer](by-file/Layer.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0002QY][0x00539fe0-0x0053a10c.MotionOnTimer](by-memory/0x00539fe0-0x0053a10c.MotionOnTimer.md)

## Changes

- 2026-08-11 B006 UID0000N3 implementation callback: preserved the animation Motion source unit and scores, replaced active layout-compatible dirty-Motion claims with the one-Region source contract, and retained the older Motion receiver hypothesis as explicit historical reconstruction provenance.

- 2026-07-14 B001 UID0002QY implementation callback:
  - Raised this source root from historical `87/86` to `90/92` while preserving `NexusTK/render/` and the existing split-owner exclusions.
  - Recorded the complete seven-item source order at positions `10/20/30/40/50/60/70`, the finished Motion declaration, exact `OnTimer` route/body behavior, LivingObjectPane ownership/lifetime, and the source/compiler boundary for the inline destructor, scalar wrapper, adjustor, teardown, pool return, and RTTI/vtable output.
  - Historicalized `OnTimerTick`, candidate-only source placement, alternate-constructor `ObjectPane *`, and blank-class/source-order blockers without removing their provenance.

- 2026-07-09 B003 [UID:0002WR][0x0069b984-0x0069b9ac.MotionPoolStaticStorage](by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md) implementation callback:
  - Preserved file score, path, and split-owner guard.
  - Added the Motion static pool source-readiness route: UID0002WR now emits `static PoolAllocator g_motionPool(0x1c, 0x10);` through `NexusTK/render/Motion.cpp`. Current B003 evidence ties the declaration to zero-filled `.data` storage, constructor wrapper `0x0041a120`, cleanup wrapper `0x0060c390`, Motion allocation/free/destructor xrefs, and the descriptive `g_motionPool` name already carried by the static-pool inventory while preserving the exact-original-name and final-header confidence caps.

- 2026-07-06 B003 [UID:0002QW][0x00539bc0-0x00539d43.MotionAnimationConstructor](by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md) implementation callback:
  - Preserved file score, path, and split-owner guard.
  - Added primary-constructor source-readiness context: UID0002QW now emits first-draft `Motion::Motion(LivingObjectPane *owner, int motionType, int timerDelay, char soundOverride)` through `NexusTK/render/Motion.cpp`. Current MCP session `0af70ed8` records exact range/size, sole caller `0x0053b5f9`, local table/padding boundary, Motion vptr/pool evidence, negative pointer searches, no local UDT, and owner `ShowName()`/`HideName()` slot proof while preserving exact-header/enum/sound-name confidence caps.

- 2026-07-04 B014 UID0001FW implementation sync:
  - Preserved Motion file score/path/ownership.
  - Recorded that the modeled Region.cpp dirty-rectangle `Motion::` helpers on [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) are now source-ready at `90/91`.
  - Historicalized the stale `Motion::GetNormalizedRect` label as `Motion::IntersectWithRect` and preserved the animation/dirty-region split-owner guard.

- 2026-07-02 B007 [UID:0002QX][0x00539de0-0x00539f52.MotionAnimationAlternateConstructor](by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md) implementation callback:
  - Preserved file score, path, and split-owner guard.
  - Added constructor source-readiness context: UID0002QX now emits first-draft `Motion::Motion(ObjectPane *owner, int motionType, char terminalFrame, int timerDelay, char soundOverride)` through `NexusTK/render/Motion.cpp`, while zero direct start refs, inferred field names, no switch-table child, and Region/Dialog/NewHumanImageLib exclusions remain documented.

- 2026-07-03 B008 [UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md) implementation sync:
  - Preserved file score, path, and split-owner guard.
  - Recorded that UID000356 is source-declared/generated-binary Motion RTTI/vtable output marker-covered through this `NexusTK/render/Motion.cpp` route. The marker is not raw dword-array source and does not weaken the Region dirty-rectangle, MessageDialogs, NewHumanImageLib, or LivingObjectPane exclusions.

- 2026-06-26 B008 [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md) implementation sync:
  - Preserved scores, path, and animation ownership metadata.
  - Added a non-conflict note that the Motion-prefixed dirty-rectangle children emit through Region.cpp and do not belong to the timer-driven animation `Motion.cpp` source route.

- 2026-06-04:
  - Before: scored `82/76` with a blank proposed path and stale evidence phrasing.
  - After: scored `86/84`, set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, and rewrote the evidence around live IDA function, vtable, caller, callee, and source-split checks.
  - Why: the live IDA pass proves the timer-driven Motion animation class is the only Motion-owned source candidate, while Region rectangle helpers, message dialog packet dispatch, `Motion.tbl` vector helpers, and `LObject` base destruction have separate owners. Confidence remains below 90 because the exact original animation filename is still not proven.
- 2026-06-07 A001 Batch094 parent-gate refresh:
  - Before: `86/84`; the file was one confidence point below the corrected strict parent gate for the Motion class.
  - After: `86/85`.
  - Why: live IDA reconfirmed the exact Motion animation ranges, constructor/vtable/pool xrefs, callees, and explicit exclusions. The final filename remains provisional, but direct source-bucket ownership for the timer-driven Motion class is now strong enough for parent routing.

- 2026-06-13 C001 Goal 2 barrier repair:
  - Updated the animation-object row and cross-reference after [UID:0001DD][0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster](by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md) was narrowed out of the non-Motion LivingObjectPane/object-pane island.
  - No score or path change; this file still owns the timer-driven Motion class source bucket, while the broad physical-range barrier was a by-memory structure problem.

- Before: the non-Motion dialog packet dispatcher was listed only as `0x0054c200-0x0054c510`.
- Changed to: the non-Motion dialog dispatcher/wrapper island is `0x0054c200-0x0054caa9`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the old range stopped at the main dispatcher, while adjacent wrappers through `0x0054caa9` are the same dialog allocation source island.
- 2026-05-28: Corrected the Region/dirty-rectangle companion range from `0x00554680-0x00554b37` to `0x00554680-0x00554b38`. Evidence: IDA MCP disassembly shows `0x00554b37` is the final `Region::ScalarDeletingDestructor` `retn 4` byte.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Summary/evidence: the page documents the mixed historical ownership, proposed source split, major range families, evidence notes, and corrected ranges; confidence is lower than adjacent file pages because this is intentionally a split/triage page rather than one clean original source file.

- 2026-06-16 A001 Goal2 file-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`.
  - After: `COMPLETION:87`, `CONFIDENCE:86`.
  - Summary/evidence: current IDA MCP reconfirmed Motion constructor/timer/destructor boundaries, primary constructor reachability, alternate-constructor no-ref status, vtable/pool refs, animation callees, Region/Dialog/NewHumanImageLib exclusions, alignment boundaries, RTTI string evidence, no embedded source filename, and no local UDT. Remaining blockers are final animation filename, alternate-constructor source shape, and member names.

## 2026-07-15 UID0003UP Motion Config-Dependency Synchronization

- Motion file score, path, source inventory, by-file formal policy, and all animation/effect ownership remain unchanged.
- The two accepted constructor definitions use base-Config `m_hearSnoreMode`, persisted by RegistryConfig key `HearSnore`; type-16 sound 305 versus -1 behavior is exact.
- Any earlier present-tense motion-number/numeric-field alias is superseded. No source movement, duplicate definition, or unrelated formal change is made.

## 2026-08-22 UID0000MM Accepted PoolAllocator Dependency Callback

- Formal CPP dependency: `#include "../util/PoolAllocator.h"`, emitted by [UID:00008R][Motion](by-class/Motion.md) into this file's existing source route.
- Retained consumer declarations: `static PoolAllocator g_motionPool(0x1c, 0x10);`.
- Inventory linkage: P07; exact ranges, bytes, xrefs, wrapper topology, and supervisor-owned materialization actions remain on their UID-bound storage pages and the accepted UID0000MM report.
- Routing: The declaration remains on UID0002WR at child position 20 and is emitted through UID00008R/UID0000LL.
- Formal H disposition: no PoolAllocator declaration is duplicated here; the CPP include supplies the complete standalone utility type.
- Generated acceptance: the earlier command-26311/26323/26351/26355 observations are dated prestates only. The scoped callback validator must regenerate this CPP with the include and unchanged consumer declaration(s), and the dated physical file receipt is recorded in the accepted report.
