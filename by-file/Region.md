*** UID:0000N3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Region

## Status

- Confidence: strong for the local rectangle/dirty-region behavior; medium for final original filename.
- Proposed module: `ui/core/Region.cpp`, or a small `ui/core/Motion.cpp` companion if later source evidence keeps the rectangle helpers under the historical `Motion` name.
- Current recovered sources: `source-3/simroot_v2/class_Region.cpp` and the rectangle-helper portion of `class_Motion.cpp`.
- Main address doc: [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)

## File Role

`Region.cpp` should own the small rectangle/dirty-region objects used by pane, layer, GrafPort, scroll, and render invalidation code. The safe source island is the local `0x00554680-0x00554b38` range: `Region` construction/destruction plus `Motion`-named rectangle helpers for emptiness, copy, intersection, union, subtraction, offset, containment, and raw-rectangle extraction.

Keep the lower-level four-int [UID:0000N2][RectBounds](by-file/RectBounds.md) value object and point/rectangle free helpers in their own source family. `Region` consumes those primitives for dirty-region behavior, but it should not absorb the broad `0x004b78d0-0x004b7f87` geometry helper island.

This is UI-core/render-support infrastructure. It should not absorb the timer-driven animation `Motion` object at `0x00539bc0-0x0053d613`, the message/dialog packet dispatcher at `0x0054c200`, or `Motion.tbl` vector helpers used by `NewHumanImageLib`.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `Region` | `0x00554680-0x005546e1`, `0x00554a00-0x00554a18`, `0x00554b00-0x00554b38` | Empty-region construction, region/rect intersection wrapper, and scalar deleting destructor. |
| `Motion` rectangle helpers | `0x005546f0-0x00554af1` plus raw helper pocket [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md) | Dirty-rectangle helpers over the same stored `RECT` shape: empty, set, copy, intersect, union, subtract, offset, contains, and get-rect. |
| stored rectangle layout | inferred | `LObject`/vtable at `+0x00`, four-int `RECT` storage at `+0x04`. |

## Evidence Notes

- IDA MCP is reachable through the manual `/mcp` flow and confirms real function starts at `0x00554680`, `0x005546f0`, `0x00554760`, `0x005547a0`, `0x005547e0`, `0x00554a00`, and `0x00554b00`.
- IDA decompilation of `0x00554680` constructs `LObject`, installs the `Region` vtable, and clears a four-int rectangle at `this + 4`.
- IDA decompilation of `0x00554a00` calls the shared rectangle intersection helper over the stored rect, and `0x00554b00` destroys the base object then optionally frees storage.
- 2026-05-26 IDA `py_eval` recheck confirms all mapped function starts from `0x00554680` through `0x00554b00`, `Region` vtable `0x00622f58`, constructor store `0x005546c1`, and `Region` RTTI/name records.
- IDA caller checks show broad pane/layer/render fanout for the rectangle helpers, including `Layer`, `GrafPort`, `Pane`, scroll, text, and map/UI paths. That fanout supports a reusable UI-core helper file instead of feature ownership.
- `class_Region.cpp` currently includes unrelated methods such as `GetUsagePercent`, `ToLong`, a wide-string constructor, and `SimpleUString::c_str`. These are generated owner pollution outside the local rectangle island. The `0x0041a580` `GetUsagePercent` helper is now documented under [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md).
- 2026-06-01 IDA MCP recheck of [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) confirms exact modeled function endpoints, broad UI/render caller fanout, lower-level rectangle primitive callees, and raw helper bodies at `0x00554a20`, `0x00554a40`, and `0x00554aa0`.

## Boundary Rules

- Keep [UID:0001DD][0x00539bc0-0x0053d614.MotionAnimation](by-memory/0x00539bc0-0x0053d614.MotionAnimation.md) in a separate animation/game-render source candidate.
- Keep `HandleDialogPacket_54C200` with [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md).
- Keep `VectorGrowMotion_004E5240` and `DestroyMotionVector_004E5DD0` with [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) because they are `Motion.tbl` asset-vector helpers.
- Keep [UID:0000KL][Layer](by-file/Layer.md), [UID:0000MC][Pane](by-file/Pane.md), [UID:0000JR][GrafPort](by-file/GrafPort.md), and [UID:0000NF][ScrollBar](by-file/ScrollBar.md) as consumers; their broad calls into this island are dependency evidence, not ownership evidence.

## Cross-References

- [UID:0000BV][Region](by-class/Region.md)
- [UID:00008R][Motion](by-class/Motion.md)
- [UID:0000LL][Motion](by-file/Motion.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md)
- [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md)
- [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md)
- [UID:0000N2][RectBounds](by-file/RectBounds.md)
- [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)
- [UID:0000KL][Layer](by-file/Layer.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)

## Changes

- 2026-05-28:
  - Before: the safe Region/rectangle helper island was cited as `0x00554680-0x00554b37`.
  - After: corrected it to `0x00554680-0x00554b38`.
  - Evidence: IDA MCP disassembly shows `0x00554b37` is the final byte of `Region::ScalarDeletingDestructor`'s `retn 4`, with padding beginning at `0x00554b38`.

- 2026-06-01:
  - Before: the projected source path was blank and the proposed contents used shortened Region/rectangle helper endpoints.
  - After: set projected path to `NexusTK/ui/core/`, corrected the Region/rectangle helper endpoints, and added the raw helper child page reference.
  - Evidence: IDA MCP endpoint/callee/raw-byte recheck of [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md).

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents Region/dirty-rect role, contents, IDA evidence, boundary rules, generated-owner pollution, range correction, and cross-references; confidence remains capped by final original filename and historical `Motion` helper naming.
