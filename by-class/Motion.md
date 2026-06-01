*** UID:00008R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Motion

## Status

- Likely source file: [UID:0000LL][Motion](by-file/Motion.md), but current generated ownership is mixed.
- Current recovered file: `source-3/simroot_v2/class_Motion.cpp`
- Core animation range: [UID:0001DD][0x00539bc0-0x0053d614.MotionAnimation](by-memory/0x00539bc0-0x0053d614.MotionAnimation.md)
- Region/dirty-rectangle range: [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- Confidence: strong that current `class_Motion.cpp` is a mixed ownership container, medium for final class/file names.

## Class Purpose

`Motion` currently covers two different behavior families in generated output:

- a timer-driven animation/motion controller around `0x00539bc0-0x0053d614`, with frame progression, optional sound trigger, map/object refresh, timer rescheduling, and pool-backed scalar deleting cleanup;
- a rectangle/dirty-region helper family around `0x005546f0-0x00554ae0`, adjacent to [UID:0000BV][Region](by-class/Region.md), used heavily by panes, layers, GrafPort, dirty-region accumulation, and clipping.

These may be two original source concepts that share the historical `Motion` name, or a generated merge caused by common rectangle state and broad vtable/base use. Treat final naming as open until struct/vtable ownership is rechecked.

## Method Families

| Family | Address range | Role |
| --- | --- | --- |
| Animation constructors | `0x00539bc0-0x00539f52` | Build timer-driven motion objects with owner pointer, motion type/duration, packed sound/frame state, and timer registration. Exact pages: [UID:0002QW][0x00539bc0-0x00539d43.MotionAnimationConstructor](by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md), [UID:0002QX][0x00539de0-0x00539f52.MotionAnimationAlternateConstructor](by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md). |
| Animation timer | `0x00539fe0-0x0053a10c` | Advances current frame, triggers sound, updates owner/map animation state, and reschedules or cleans up. Exact page: [UID:0002QY][0x00539fe0-0x0053a10c.MotionAnimationTimerTick](by-memory/0x00539fe0-0x0053a10c.MotionAnimationTimerTick.md). |
| Animation destructor wrapper | `0x0053d590-0x0053d614` | Scalar deleting destructor for the animation object. Exact page: [UID:0002QZ][0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md). |
| Rect emptiness/copy/intersection | `0x005546f0-0x005547f6` | Empty-state, set/copy, intersect, and normalized-rectangle helpers. |
| Rect union/subtract/offset/contains | `0x00554800-0x00554af0` | Dirty-region union/subtract, offset, containment, and raw rect extraction. |

## Explicit Exclusions

- `0x004f4a90` is [UID:00007D][LObject](by-class/LObject.md) base destructor behavior, not Motion-specific cleanup.
- `0x0054c200` is the message/menu-question dialog packet dispatcher. It is currently emitted as `Motion::HandleDialogPacket`, but source ownership belongs with [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md).
- `VectorGrowMotion` at `0x004e5240` and `DestroyMotionVector` at `0x004e5dd0` are [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) `Motion.tbl` vector helpers, not methods on this class.

## Evidence Notes

- IDA MCP on 2026-05-24 confirms all generated Motion starts as real functions except that their ownership separates by caller cluster.
- `0x00539bc0` has a concrete constructor caller in an animation/spawn path, while `0x00539fe0` is reached through timer/vtable style dispatch.
- The rectangle helpers have broad pane/layer/render caller fanout and match older Wave2 notes for dirty-region and clip-region behavior.
- `0x0054c200` callers are message/menu dialog packet paths; its callees instantiate message and menu-question dialog classes.
- `0x004e5240` is called only by `NewHumanImageLib::LoadMotionTable`; `0x004e5dd0` is called only from `NewHumanImageLib` destruction/cleanup.
- 2026-05-26 IDA static-pool review identifies the animation-object [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) at `0x0069b984`, constructed by `0x0041a120` with block size `28` and `16` blocks per chunk. The related constructor-failure cleanup wrapper is [UID:0001DK][0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper](by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md).

## Cross-References

- [UID:0000LL][Motion](by-file/Motion.md)
- [UID:0001DD][0x00539bc0-0x0053d614.MotionAnimation](by-memory/0x00539bc0-0x0053d614.MotionAnimation.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0000BV][Region](by-class/Region.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000073][Layer](by-class/Layer.md)
- [UID:00005V][GrafPort](by-class/GrafPort.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- [UID:0001DK][0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper](by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/70`. Summary: the page now clearly separates timer-driven animation motion from rectangle/dirty-region helper behavior and documents explicit generated-owner exclusions, but confidence stays capped because current generated ownership is mixed and final class/file names remain unresolved. Evidence: linked animation and region/motion ranges, caller-cluster separation, exclusions for `LObject`, message dialogs, and NewHumanImageLib vector helpers, IDA static-pool review, and pool-free unwind wrapper reference.
