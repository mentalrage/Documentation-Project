*** UID:00008R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Confidence: strong for the generated split diagnosis, animation behavior, rectangle-helper relocation, and explicit exclusions; medium-high for final animation class/file names.

## Class Purpose

`Motion` currently covers two different behavior families in generated output:

- a timer-driven animation/motion controller around `0x00539bc0-0x0053d614`, with frame progression, optional sound trigger, map/object refresh, timer rescheduling, and pool-backed scalar deleting cleanup;
- a rectangle/dirty-region helper family around `0x005546f0-0x00554ae0`, adjacent to [UID:0000BV][Region](by-class/Region.md), used heavily by panes, layers, GrafPort, dirty-region accumulation, and clipping.

These are now best treated as split source concepts. The timer-driven animation object remains the actual `Motion` class candidate, while the rectangle/dirty-region helper family is already attached to [UID:0000N3][Region](by-file/Region.md). Treat final animation folder/name as open, but do not merge the Region rectangle helpers back into the animation source.

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
- [UID:0001DD][0x00539bc0-0x0053d614.MotionAnimation](by-memory/0x00539bc0-0x0053d614.MotionAnimation.md) now carries exact child pages, touched-state evidence, vtable/static-pool evidence, corrected endpoints, and overlap notes for the non-Motion LivingObjectPane island between timer and scalar deleting destructor.
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) is reconstructable but attached to [UID:0000N3][Region](by-file/Region.md), with all modeled rectangle helper endpoints, raw helper pocket, layout, caller/callee evidence, and lower-level geometry primitive references documented.

## Autogen Status

Mark this class reconstructable as split-owner documentation, but leave `AUTOGEN_PARENT_UID` and C++ blank. The animation half is reconstructable and source-authored, but the current generated `class_Motion.cpp` still crosses into Region rectangle helpers, MessageDialogs, NewHumanImageLib `Motion.tbl` helpers, and LivingObjectPane adjacency. Final emitted source should wait until the actual animation file path and class declaration are stable.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `82` | The page records the animation/rectangle split, exact animation child pages, Region relocation, static-pool evidence, explicit non-Motion exclusions, generated-owner pollution, and no-code autogen handling. Completion remains capped because final animation file path and field/member names are unresolved. |
| Confidence `82` | Confidence is strong that the timer-driven object is the real Motion candidate and that rectangle helpers belong with Region, supported by exact memory pages and caller/owner evidence. It is not higher because current generated ownership is still mixed and the original source split has not been fully recovered. |

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

- 2026-06-02:
  - Before: scored `78/70`, reconstructability blank.
  - After: scored `82/82`, marked reconstructable, and kept autogen parent/C++ blank.
  - Why: exact MotionAnimation and RegionAndMotionRect pages now provide enough evidence to classify the generated Motion page as a reconstructable split-owner record, while the final animation source path and declaration remain unresolved.
- Completion/confidence score update: existed before as `0/0`; changed to `78/70`. Summary: the page now clearly separates timer-driven animation motion from rectangle/dirty-region helper behavior and documents explicit generated-owner exclusions, but confidence stays capped because current generated ownership is mixed and final class/file names remain unresolved. Evidence: linked animation and region/motion ranges, caller-cluster separation, exclusions for `LObject`, message dialogs, and NewHumanImageLib vector helpers, IDA static-pool review, and pool-free unwind wrapper reference.
