*** UID:00008R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../util/PoolAllocator.h"
#include "../ui/core/BlackHole.h"

class Motion : public LObject, public TimerHandler
{
public:
    Motion(LivingObjectPane *owner, int motionType,
           int timerDelay, char soundOverride);
    Motion(LivingObjectPane *owner, int motionType,
           char terminalFrame, int timerDelay, char soundOverride);
    virtual ~Motion() {}
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    LivingObjectPane *m_owner;
    int m_motionType;
    short m_soundEffectId;
    char m_soundTriggerFrame;
    char m_currentFrame;
    char m_terminalFrame;
    int m_timerDelay;
};
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Motion

## Status

- Direct source file: [UID:0000LL][Motion](by-file/Motion.md), the source-ready Motion animation bucket. The earlier `86/85` Batch094 state and mixed generated-owner diagnosis are retained below as history.
- Source placement: the reconstructed declaration and methods belong to `NexusTK/render/Motion.cpp`. The earlier `source-3/simroot_v2/class_Motion.cpp` path was a generated/recovered investigation artifact, not current source placement.
- Core animation constructor/timer cluster: [UID:0001DD][0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster](by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md)
- Discontiguous animation destructor wrapper: [UID:0002QZ][0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md)
- Static animation pool declaration: [UID:0002WR][0x0069b984-0x0069b9ac.MotionPoolStaticStorage](by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md) now emits `static PoolAllocator g_motionPool(0x1c, 0x10);` through this Motion class route; the exact original variable spelling remains inferred.
- Vtable data: [UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md), source-declared/generated-binary RTTI/vtable output marker-covered by the Motion class declaration and source route rather than hand-authored raw dword arrays.
- Region/dirty-rectangle range: [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- Confidence: strong for the class ABI, field layout, animation behavior, source order, generated split diagnosis, rectangle-helper relocation, and explicit exclusions. Original private member spellings remain source-facing reconstructions rather than symbol-recovered names.
- UID0001FW status: the complete nineteen-method Region implementation is source-ready at `94/94` through Region.cpp with four nested children. This page keeps only animation Motion ownership and class-level declaration evidence.

## Class Purpose

Historical generated output grouped two different behavior families under `Motion`:

- a timer-driven animation/motion controller with constructor/timer code at `0x00539bc0-0x0053a10c` and a discontiguous scalar deleting destructor at `0x0053d590-0x0053d614`, with frame progression, optional sound trigger, map/object refresh, timer rescheduling, and pool-backed cleanup;
- a rectangle/dirty-region helper family around `0x005546f0-0x00554ae0`, adjacent to [UID:0000BV][Region](by-class/Region.md), used heavily by panes, layers, GrafPort, dirty-region accumulation, and clipping.

These are split source concepts. The timer-driven object is the source-authored `Motion` class in `NexusTK/render/Motion.cpp`; the rectangle/dirty-region family is the one `Region` class attached to [UID:0000N3][Region](by-file/Region.md). The accepted UID0002R9 children use `Region::` source receivers and remain outside the animation class route; Motion-prefixed filenames are historical provenance only.

## Method Families

| Family | Address range | Role |
| --- | --- | --- |
| Animation constructors | `0x00539bc0-0x00539f52` | Build timer-driven motion objects with owner pointer, motion type/duration, packed sound/frame state, and timer registration. Exact pages: [UID:0002QW][0x00539bc0-0x00539d43.MotionAnimationConstructor](by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md), [UID:0002QX][0x00539de0-0x00539f52.MotionAnimationAlternateConstructor](by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md). |
| Animation timer | `0x00539fe0-0x0053a10c` | Source-authored `Motion::OnTimer`: validates event `3`, advances the signed frame byte, conditionally triggers the configured sound, publishes or removes the current effect, updates owner/map animation state, and reschedules or cleans up. Exact page: [UID:0002QY][0x00539fe0-0x0053a10c.MotionOnTimer](by-memory/0x00539fe0-0x0053a10c.MotionOnTimer.md). |
| Animation destructor wrapper | `0x0053d590-0x0053d614` | Scalar deleting destructor for the animation object. Exact page: [UID:0002QZ][0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md). |
| Region emptiness/copy/intersection | `0x005546f0-0x005547f6` | Region.cpp-owned methods. Historical `Motion::GetNormalizedRect` and `Motion::IntersectWithRect` wording for `0x005547e0` is superseded by `Region::IntersectWithRect`. |
| Region union/subtract/offset/contains | `0x00554800-0x00554af0`, including UID0001FW modeled helpers and [UID:00042Q][0x00554a20-0x00554a3c.MotionIntersectsRaw](by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md), [UID:00042R][0x00554a40-0x00554a56.MotionContainsRectRaw](by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md), [UID:00042S][0x00554a60-0x00554a9b.MotionContains](by-memory/0x00554a60-0x00554a9b.MotionContains.md), and [UID:00042T][0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw](by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md) | `Region` union/subtract, offset, containment, same-bounds comparison, and raw rect extraction. Physical child filenames retain old Motion tokens but current source does not. |

## Explicit Exclusions

- `0x004f4a90` is [UID:00007D][LObject](by-class/LObject.md) base destructor behavior, not Motion-specific cleanup.
- `0x0054c200` is the message/menu-question dialog packet dispatcher. It is currently emitted as `Motion::HandleDialogPacket`, but source ownership belongs with [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md).
- `VectorGrowMotion` at `0x004e5240` and `DestroyMotionVector` at `0x004e5dd0` are [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) `Motion.tbl` vector helpers, not methods on this class.

## Current Region Exclusion And Historical Dirty-Motion Assumption

[UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md) is now a non-emitting split index over four Region.cpp child methods:

| Dirty-region helper | Child page | Ownership note |
| --- | --- | --- |
| `Region::Intersects` | [UID:00042Q][0x00554a20-0x00554a3c.MotionIntersectsRaw](by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md) | Region.cpp method over receiver `+0x04` `RectBounds m_bounds`. |
| `Region::ContainsRect` | [UID:00042R][0x00554a40-0x00554a56.MotionContainsRectRaw](by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md) | Region.cpp method; `RectContainsRect(bounds, &m_bounds)` uses the supplied bounds as inner and receiver bounds as outer. |
| `Region::Contains` | [UID:00042S][0x00554a60-0x00554a9b.MotionContains](by-memory/0x00554a60-0x00554a9b.MotionContains.md) | Region.cpp method with four live dirty-region call references. |
| `Region::HasSameBoundsAs` | [UID:00042T][0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw](by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md) | Region.cpp method using `RectsEquivalent`, not animation state comparison. |

The animation class documented by this page remains the timer/vtable/pool-backed object at `0x00539bc0-0x0053a10c` plus the scalar deleting destructor at `0x0053d590-0x0053d614`. The dirty-region helpers should continue to be excluded from generated `class_Motion.cpp` cleanup decisions for animation reconstruction.

The modeled non-child methods in UID0001FW carry formal C++ through Region.cpp as `Region::IsEmpty`, `SetEmpty`, `SetRect`, `CopyRectFrom`, `IntersectWith`, `IntersectWithRect`, `UnionWithRect`, `UnionWith`, `SubtractRect`, `SubtractRectFrom`, `Offset`, `IntersectsRect`, and pointer-returning `GetRect`. They are not members of this timer-driven animation class.

Earlier reconstruction used a layout-compatible dirty-region Motion class to explain the same `+0x04` rectangle access. Current Region UDT/RTTI/vtable, exact source brackets, complete nineteen-method formal, and the separate `0x1c` dual-vptr Motion animation UDT reject that active interpretation. The old receiver names remain only in dated history and stable filenames.

## Static Pool Declaration

[UID:0002WR][0x0069b984-0x0069b9ac.MotionPoolStaticStorage](by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md) is the exact `.data` storage for the Motion animation pool and now carries the formal source declaration:

```cpp
static PoolAllocator g_motionPool(0x1c, 0x10);
```

Current B003 evidence keeps this declaration on the Motion route: the startup wrapper at `0x0041a120` pushes `0x10` chunks and block size `0x1c`, loads `unk_69B984`, calls the `PoolAllocator` constructor helper, and registers cleanup wrapper `0x0060c390`. The pool base has exactly five current refs: static construction `0x0041a124`, Motion allocation `0x0053b5d5` in `sub_53B3D0`, constructor-unwind free `0x0053ce75` in `sub_53CE50`, scalar deleting destructor free `0x0053d5d0` in `sub_53D590`, and static cleanup `0x0060c390`.

The static pool child emits its declaration through Motion. The focused UID0002QY source-quality pass resolved the former broad class-level blocker with the complete `Motion : public LObject, public TimerHandler` declaration, a binary-backed `0x1c` layout, source order, and `NexusTK/render/Motion.cpp` placement. Exact original private-member spelling remains inferred but no longer prevents reconstruction.

## Evidence Notes

- IDA MCP on 2026-05-24 confirms all generated Motion starts as real functions except that their ownership separates by caller cluster.
- `0x00539bc0` has a concrete constructor caller in an animation/spawn path, while `0x00539fe0` is reached through timer/vtable style dispatch.
- The rectangle helpers have broad pane/layer/render caller fanout and match older Wave2 notes for dirty-region and clip-region behavior.
- `0x0054c200` callers are message/menu dialog packet paths; its callees instantiate message and menu-question dialog classes.
- `0x004e5240` is called only by `NewHumanImageLib::LoadMotionTable`; `0x004e5dd0` is called only from `NewHumanImageLib` destruction/cleanup.
- 2026-05-26 IDA static-pool review identifies the animation-object [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) at `0x0069b984`, constructed by `0x0041a120` with block size `28` and `16` blocks per chunk. The related constructor-failure cleanup wrapper is [UID:0001DK][0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper](by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md).
- [UID:0001DD][0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster](by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md) now carries exact constructor/timer child pages, touched-state evidence, vtable/static-pool evidence, corrected endpoints, and the explicit split from the non-Motion LivingObjectPane island between timer and scalar deleting destructor.
- 2026-07-06 B003 UID0002QW callback adds primary-constructor source-readiness to the class route. Current MCP session `0af70ed8` confirms `sub_539BC0` at `0x00539bc0-0x00539d43` with size `0x183`, sole direct caller `0x0053b5f9` in the LivingObjectPane action/effect path, constructor-local table/padding bytes through `0x00539de0`, Motion vptr stores to `0x00620954`/`0x00620964`, Motion pool storage refs at `0x0069b984`, no VA/RVA pointer hits for the constructor start/end, and no local `Motion` UDT. UID0002QW now carries formal first-draft C++ with the same inferred field family as UID0002QX/UID0002QY plus owner `ShowName()`/`HideName()` calls for motion types `27`/`28`.
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) is reconstructable but attached to [UID:0000N3][Region](by-file/Region.md), with all modeled rectangle helper endpoints, raw helper pocket, layout, caller/callee evidence, and lower-level geometry primitive references documented.
- 2026-07-04 B014 UID0001FW implementation sync: accepted current MCP evidence (`nexustk_supervisor_20260704`) reconfirmed exact Region/Motion modeled ranges, no local UDT/source-name records, broad xrefs, and generated UID0001FW empty-marker lead state; UID0001FW now emits formal Region.cpp dirty-rectangle helper C++ at `90/91`.
- 2026-06-26 B008 implementation split [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md) into four exact Region.cpp dirty-region children. This reinforces the existing Motion class exclusion: Motion-prefixed dirty-rectangle methods are source-facing helper names but are not timer-driven animation class members.
- 2026-07-14 B001 UID0002QY implementation independently revalidated the complete timer callback against live IDA MCP session `3fc1dcef` and synchronized the class ABI. The two constructor vptr stores, seven-dword RTTI/vtable island, scalar wrapper, and `0x1c` static-pool block size establish the dual `LObject`/`TimerHandler` object shape. Relative to the primary `Motion` pointer, the accepted layout is the secondary `TimerHandler` vptr at `+0x04`, owner at `+0x08`, motion type at `+0x0c`, signed-short sound id at `+0x10`, packed trigger/current/terminal frame bytes at `+0x12/+0x13/+0x14`, and timer delay at `+0x18`. The formal declaration is the source route; raw vptr stores, adjustor thunks, scalar-delete logic, and compiler teardown remain excluded from hand-authored class source.

## Autogen Status

This class is reconstructable through [UID:0000LL][Motion](by-file/Motion.md) at source position `10`. Its formal block now supplies the complete class declaration, both constructor declarations, inline empty ordinary destructor, virtual `OnTimer` declaration, private field family, and `[[CHILDREN]]` insertion point. [UID:0002WR][0x0069b984-0x0069b9ac.MotionPoolStaticStorage](by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md) follows at position `20`, [UID:0002QW][0x00539bc0-0x00539d43.MotionAnimationConstructor](by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md) at `30`, [UID:0002QX][0x00539de0-0x00539f52.MotionAnimationAlternateConstructor](by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md) at `40`, [UID:0002QY][0x00539fe0-0x0053a10c.MotionOnTimer](by-memory/0x00539fe0-0x0053a10c.MotionOnTimer.md) at `50`, [UID:0002QZ][0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md) at `60`, and [UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md) at `70`.

The formal source intentionally excludes raw vptr writes, scalar-delete control, base teardown, the TimerHandler adjustor thunk, pool release, EH cleanup, and raw RTTI/vtable arrays because those are compiler-generated consequences of the declaration and method bodies. Region rectangle helpers, MessageDialogs, NewHumanImageLib `Motion.tbl` helpers, and the adjacent LivingObjectPane island remain outside this source route. Exact enum names, a symbolic constant for timer event `3`, and original private-member spelling remain unknown but do not change ABI or observable behavior.

[UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md) is source-ready in the narrower generated-binary sense: its formal block is a no-raw-vtable marker, not a class declaration. B008 session `c9ac3d5b` reconfirmed the seven-dword `Motion` RTTI/vtable range, constructor vptr stores at `0x00539c11/0x00539c17` and `0x00539e47/0x00539e4d`, slot targets `0x0053d590`, `0x0053cf54`, and `0x00539fe0`, and the `0x0062096c` LivingObjectPane/BoxRotator successor boundary. This marker coverage does not remove the broader class-level header/member/source-filename uncertainty.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | The page now records the complete declaration, `0x1c` ABI/layout, dual inheritance, inline ordinary destructor source cause, constructor/timer/scalar/vtable/static ordering, exact child routes, animation/rectangle split, Region relocation, static-pool evidence, explicit non-Motion exclusions, and live vtable/pool/caller/callee checks. Remaining uncertainty is limited to exact original private-member and enum spellings. |
| Confidence `93` | Independent MCP, disassembly, decompiler, constructor, caller, vtable, pool, scalar-wrapper, and generated-source evidence agree on the bounded Motion class and its `OnTimer` route. Confidence remains below symbol-perfect only because no original UDT/header symbols recover the private names or timer-event enum spelling. |

## Cross-References

- [UID:0000LL][Motion](by-file/Motion.md)
- [UID:0001DD][0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster](by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md)
- [UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md)
- [UID:00042Q][0x00554a20-0x00554a3c.MotionIntersectsRaw](by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md)
- [UID:00042R][0x00554a40-0x00554a56.MotionContainsRectRaw](by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md)
- [UID:00042S][0x00554a60-0x00554a9b.MotionContains](by-memory/0x00554a60-0x00554a9b.MotionContains.md)
- [UID:00042T][0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw](by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md)
- [UID:0000BV][Region](by-class/Region.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000073][Layer](by-class/Layer.md)
- [UID:00005V][GrafPort](by-class/GrafPort.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- [UID:0001DK][0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper](by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md)
- [UID:0002WR][0x0069b984-0x0069b9ac.MotionPoolStaticStorage](by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md)
- [UID:0002QY][0x00539fe0-0x0053a10c.MotionOnTimer](by-memory/0x00539fe0-0x0053a10c.MotionOnTimer.md)

## Batch094 Evidence

- 2026-06-07 A001 live IDA `lookup_funcs` reconfirmed the Motion-owned animation functions at `0x00539bc0-0x00539d43`, `0x00539de0-0x00539f52`, `0x00539fe0-0x0053a10c`, and `0x0053d590-0x0053d614`.
- `xrefs_to` reconfirmed the only constructor code xref at `0x0053b5f9`, the timer vtable data ref at `0x00620968`, the destructor wrapper/data refs at `0x0053cf57` and `0x00620954`, constructor stores to the vtable base at `0x00539c11` and `0x00539e47`, and Motion pool refs to `0x0069b984` from initialization, creator, unwind, destructor, and cleanup paths.
- `callees` reconfirmed constructor dependencies on base/timer setup (`0x004f4a80`, `0x00597570`), timer dependencies on map/object invalidation, timer scheduling, and sound/effect helpers (`0x00469120`, `0x00506980`, `0x00597910`, `0x0057a5c0`, `0x0057a6c0`), and destructor dependencies on timer/base cleanup plus pool free.
- Direct parent [UID:0000LL][Motion](by-file/Motion.md) is now `86/85`, so this class clears the strict child-and-parent `85/85` assignment gate. [UID:0001DD][0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster](by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md) remains unassigned because that container is non-emitting; exact Motion child pages attach directly to this class.
- 2026-06-10 B001-035 exact read-only split confirmed [UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md) as the narrow Motion `.rdata` child: it covers the RTTI locator and vtable pointer slots at `0x00620950-0x0062096c`, including the timer vtable data ref at `0x00620968` already cited by Batch094.

## 2026-06-16 Evidence Refresh

Live IDA MCP was used to recheck active reachability, vtable/pool ownership, generated-output omissions, and the non-Motion exclusions:

- `lookup_funcs` confirms the Motion-owned animation functions remain exact: primary constructor `0x00539bc0` size `0x183`, alternate constructor `0x00539de0` size `0x172`, timer tick `0x00539fe0` size `0x12c`, and scalar deleting destructor `0x0053d590` size `0x84`.
- `xrefs_to 0x00539bc0` returns the constructor caller at `0x0053b5f9`; `xrefs_to 0x00539de0` still returns zero refs, keeping the alternate constructor as a real but not directly reached entry. `xrefs_to 0x00539fe0` returns the timer vtable/data ref at `0x00620968`, and `xrefs_to 0x0053d590` returns the unwind/code ref at `0x0053cf57` plus the vtable/data slot at `0x00620954`.
- `xrefs_to 0x0069b984` returns five static pool refs from pool initialization, creator, unwind wrapper, scalar deleting destructor, and static cleanup paths. Constructor vtable writes at `0x00539c11` and `0x00539e47` remain tied to the Motion vtable data child.
- `callees` confirms both constructors call only base/timer setup, the timer tick calls sound/effect, map/object invalidation, timer scheduling, and owner refresh helpers, and the scalar deleting destructor calls `TimerHandler` teardown, `LObject` teardown, pool free, and guard-check support.

These checks raised confidence for the bounded Motion class while preserving the real blockers known at that time: the generated `Motion` file was polluted by Region, MessageDialogs, and NewHumanImageLib helper labels; the alternate constructor lacked direct entry refs; and final member names/source declaration still required a focused final-source pass. The child-specific alternate-constructor C++ blocker was later resolved by the 2026-07-02 B007 update, but the class-level declaration/header caveat remains.

## Changes

- 2026-08-11 B006 UID0000N3 implementation callback: preserved this class's animation-only declaration and scores, normalized every current Region-range exclusion to the one Region class, and historicalized the older layout-compatible dirty-region Motion hypothesis without deleting its provenance.

- 2026-07-14 B001 UID0002QY implementation callback:
  - Raised the class from historical `86/87` to source-ready `92/93`, assigned position `10`, and replaced the blank formal block with the accepted complete `Motion : public LObject, public TimerHandler` declaration.
  - Fixed current source placement to `NexusTK/render/Motion.cpp`, renamed the timer child route to `MotionOnTimer`, synchronized source positions `10/20/30/40/50/60/70`, and retained all Region, dialog, NewHumanImageLib, raw-vtable, scalar-delete, EH, and pool-cleanup exclusions.
  - Historicalized the old `class_Motion.cpp` generated path, mixed-owner state, blank-class blocker, and score caps without deleting their provenance.

- 2026-07-09 B003 [UID:0002WR][0x0069b984-0x0069b9ac.MotionPoolStaticStorage](by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md) implementation callback:
  - Preserved Motion class score, owner/emitter metadata, and broad class-level C++ blank state.
  - Recorded that the exact Motion static pool child now emits `static PoolAllocator g_motionPool(0x1c, 0x10);` through this class route. Current B003 evidence ties the declaration to zero-filled `.data` storage at `0x0069b984`, startup wrapper `0x0041a120`, cleanup wrapper `0x0060c390`, and the five construction/allocation/unwind/destructor/cleanup refs while keeping exact original global spelling and full class declaration/header as confidence caps.

- 2026-07-06 B003 [UID:0002QW][0x00539bc0-0x00539d43.MotionAnimationConstructor](by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md) implementation callback:
  - Preserved class score and owner/emitter metadata.
  - Recorded that the primary constructor child is now source-ready at `90/92` with formal first-draft C++ through the Motion class/source route. Current MCP session `0af70ed8` ties the constructor to exact range `0x00539bc0-0x00539d43`, sole caller `0x0053b5f9`, local switch-table/padding bytes through `0x00539de0`, Motion vptr/pool evidence, negative VA/RVA pointer searches, and the `LivingObjectPane` owner-slot `ShowName()`/`HideName()` caveat without changing class-level declaration/header blockers.

- 2026-07-04 B014 UID0001FW implementation sync:
  - Preserved Motion class scores and owner/emitter metadata.
  - Recorded that the Region.cpp dirty-rectangle modeled `Motion::` helpers in [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) are source-ready at `90/91` while this class keeps animation-only ownership.
  - Replaced stale normalized-rectangle wording for `0x005547e0` with `Motion::IntersectWithRect` and kept exact spelling/local UDT uncertainty as a confidence cap.

- 2026-07-02 B007 [UID:0002QX][0x00539de0-0x00539f52.MotionAnimationAlternateConstructor](by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md) implementation callback:
  - Preserved class scores and owner/emitter metadata.
  - Recorded that the alternate constructor child is now source-ready with formal first-draft C++ using inferred Motion field names and `g_pConfig->m_motionType16SoundEnabled`, while this class-level C++ block remains blank pending the full class declaration/header. The no-direct-entry-xref caveat and non-Motion Region/Dialog/NewHumanImageLib exclusions remain in force.

- 2026-07-03 B008 [UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md) source-quality implementation:
  - Preserved class metadata and broad class-level C++ caveats.
  - Synced that UID000356 now carries formal source-declared/generated-binary marker coverage through this Motion class/source route. Current MCP evidence ties the table to Motion constructor vptr stores, destructor/timer slot targets, and the adjusted thunk while preserving Region, MessageDialogs, NewHumanImageLib, and LivingObjectPane exclusions.

- 2026-06-26 B008 [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md) implementation sync:
  - Preserved scores and animation ownership metadata.
  - Added the Region.cpp dirty-region Motion non-conflict note, four exact child references, and the corrected containment direction for `Motion::ContainsRect`.

- 2026-06-16 A002 Goal2 class-confidence refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:87`; owner and emitter remain [UID:0000LL][Motion](by-file/Motion.md).
  - Evidence: live IDA MCP reconfirmed exact animation function sizes, primary constructor reachability, alternate constructor no-xref status, timer/destructor vtable refs, static pool refs, constructor/timer/destructor callees, and continued Region/MessageDialogs/NewHumanImageLib exclusions. Its old child-level alternate-constructor C++ blocker is superseded by the 2026-07-02 B007 update, while class-level C++ remains blank because the full declaration/header and exact original source file name are not source-final.
- 2026-06-07 A001 Batch094 strict parent-gate update:
  - Before: `82/82`, reconstructable, but unassigned because the class and direct file parent were below the corrected `85/85` assignment gate.
  - After: `85/85` with owner/emitter routing to [UID:0000LL][Motion](by-file/Motion.md).
  - Why: live IDA reconfirmed exact Motion-owned ranges, vtable/pool refs, callees, constructor reachability, and non-Motion exclusions; the direct Motion file parent was refreshed to `86/85`. Final C++ stays blank below the source-quality class declaration and field-name gate.
- 2026-06-10 B001-035 vtable split update:
  - Added [UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md) as the exact Motion read-only data child after the broader mixed read-only island was split into owner-specific vtable and resource ranges.
  - No score change; the Motion class and direct file parent already clear the `85/85` gate.
- 2026-06-13 C001 Goal 2 barrier repair:
  - Updated the class page after [UID:0001DD][0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster](by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md) was narrowed from the old `0x00539bc0-0x0053d614` mixed span.
  - Why: active IDA MCP proved the old broad span crossed the non-Motion LivingObjectPane/object-pane island; the scalar deleting destructor remains a separate exact Motion child at [UID:0002QZ][0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md).
- 2026-06-02:
  - Before: scored `78/70`, reconstructability blank.
  - After: scored `82/82`, marked reconstructable, and kept autogen parent/C++ blank.
  - Why: exact MotionAnimation and RegionAndMotionRect pages now provide enough evidence to classify the generated Motion page as a reconstructable split-owner record, while the final animation source path and declaration remain unresolved.
- Completion/confidence score update: existed before as `0/0`; changed to `78/70`. Summary: the page now clearly separates timer-driven animation motion from rectangle/dirty-region helper behavior and documents explicit generated-owner exclusions, but confidence stays capped because current generated ownership is mixed and final class/file names remain unresolved. Evidence: linked animation and region/motion ranges, caller-cluster separation, exclusions for `LObject`, message dialogs, and NewHumanImageLib vector helpers, IDA static-pool review, and pool-free unwind wrapper reference.

## 2026-07-15 UID0003UP Motion Config-Dependency Synchronization

- Motion class score, inheritance/layout, methods, children, complete formal block, animation behavior, and unrelated evidence remain unchanged.
- Both animation constructors read inherited base-Config `m_hearSnoreMode` at `+0x28de71`. Registry `HearSnore`, defaults/load/save, clamp behavior, and exact-value test prove an arbitrary mode byte: motion type 16 selects sound 305 only when the byte equals 1, otherwise -1.
- Earlier `m_motionType16SoundEnabled` and numeric aliases are historicalized. This dependency correction changes no Motion member layout or runtime behavior and adds no Motion C++ beyond the two accepted constructor blocks.
