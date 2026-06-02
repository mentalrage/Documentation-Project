*** UID:0000LL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Motion

## Status

- Proposed source path: mixed; use [UID:0000N3][Region](by-file/Region.md) / `ui/core/Region.cpp` for dirty rectangles and a separate game/render animation source for timer-driven motion.
- Current generated sources: `source-3/simroot_v2/class_Motion.cpp`, `source-3/simroot_v2/class_Region.cpp`, `source-3/simroot_v2/recovered/VectorGrowMotion_004E5240.cpp`, and `source-3/simroot_v2/recovered/DestroyMotionVector_004E5DD0.cpp`
- Confidence: strong that current generated ownership is mixed, medium for the proposed split.

## File Role

This page records the Motion/Region ownership split. The current generated `class_Motion.cpp` is not a safe one-to-one original source file. It mixes:

- timer-driven animation object code;
- dirty-rectangle/region helper code;
- a message/menu-question dialog packet dispatcher;
- `NewHumanImageLib` `Motion.tbl` vector helper names in adjacent recovered globals.

## Proposed Source Split

```text
ui/core/Region.cpp
  class Region
  class Motion rectangle/dirty-region helpers
  rectangle normalization / dirty-region primitives

game/Motion.cpp or render/Motion.cpp
  timer-driven Motion animation constructors
  Motion::OnTimerTick
  animation cleanup/destructor wrapper

ui/dialogs/MessageDialogs.cpp
  HandleDialogPacket_54C200 and related dialog allocation wrappers

render/NewHumanImageLib.cpp
  VectorGrowMotion
  DestroyMotionVector
  Motion.tbl record/vector structs
```

The exact folder names are still open. The important reconstruction rule is not to migrate all current `class_Motion.cpp` content into one original source file.

## Proposed Contents By Family

| Family | Range | Proposed owner |
| --- | --- | --- |
| Animation object | `0x00539bc0-0x0053d614` | [UID:0001DD][0x00539bc0-0x0053d614.MotionAnimation](by-memory/0x00539bc0-0x0053d614.MotionAnimation.md), likely game/render animation source. Exact children: [UID:0002QW][0x00539bc0-0x00539d43.MotionAnimationConstructor](by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md), [UID:0002QX][0x00539de0-0x00539f52.MotionAnimationAlternateConstructor](by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md), [UID:0002QY][0x00539fe0-0x0053a10c.MotionAnimationTimerTick](by-memory/0x00539fe0-0x0053a10c.MotionAnimationTimerTick.md), [UID:0002QZ][0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md). |
| Region and dirty rectangles | `0x00554680-0x00554b38` | [UID:0000N3][Region](by-file/Region.md) and [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md), likely UI core/render support. |
| Dialog packet dispatcher/wrappers | `0x0054c200-0x0054caa9` | [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) and [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md), not Motion. |
| `Motion.tbl` vector helpers | `0x004e5240`, `0x004e5dd0` | [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not Motion class methods. |
| LObject destructor | `0x004f4a90` | [UID:0000KV][LObject](by-file/LObject.md), not Motion-specific. |

## Evidence Notes

- IDA MCP caller checks on 2026-05-24 show the animation constructors/timer, rectangle helpers, message dispatcher, and `Motion.tbl` vector helpers have distinct caller families.
- Older Wave2 report notes already classify `0x004f4a90` as stale `Motion::~LObject` trace labeling over the real `LObject` base destructor.
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) and [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) document the dialog constructors and allocation wrappers called by the `0x0054c200` packet dispatcher.
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) owns `Motion.tbl`; its loader is the sole caller of `VectorGrowMotion`.

## Cross-References

- [UID:00008R][Motion](by-class/Motion.md)
- [UID:0000N3][Region](by-file/Region.md)
- [UID:0000BV][Region](by-class/Region.md)
- [UID:0001DD][0x00539bc0-0x0053d614.MotionAnimation](by-memory/0x00539bc0-0x0053d614.MotionAnimation.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000KL][Layer](by-file/Layer.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)

## Changes

- Before: the non-Motion dialog packet dispatcher was listed only as `0x0054c200-0x0054c510`.
- Changed to: the non-Motion dialog dispatcher/wrapper island is `0x0054c200-0x0054caa9`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the old range stopped at the main dispatcher, while adjacent wrappers through `0x0054caa9` are the same dialog allocation source island.
- 2026-05-28: Corrected the Region/dirty-rectangle companion range from `0x00554680-0x00554b37` to `0x00554680-0x00554b38`. Evidence: IDA MCP disassembly shows `0x00554b37` is the final `Region::ScalarDeletingDestructor` `retn 4` byte.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Summary/evidence: the page documents the mixed generated ownership, proposed source split, major range families, evidence notes, and corrected ranges; confidence is lower than adjacent file pages because this is intentionally a split/triage page rather than one clean original source file.
