*** UID:0000BV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Region

## Status

- Likely source file: [UID:0000N3][Region](by-file/Region.md), with [UID:0000LL][Motion](by-file/Motion.md) retaining the mixed animation/source-boundary note
- Address range: [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- Current recovered file: `source-3/simroot_v2/class_Region.cpp`
- Vtable: [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md)
- Confidence: strong for local `Region` construction/destruction, vtable, and rectangle helper behavior; medium for generated class ownership outside the local `0x00554680-0x00554b38` range.

## Class Purpose

`Region` is a small rectangle/region wrapper used by UI and rendering dirty-region code. Its local constructor initializes an empty `RECT`, and its local methods intersect with source rectangles and destroy the base object.

Current generated output for `class_Region.cpp` is polluted with unrelated methods such as `GetUsagePercent`, `ToLong`, a wide-string constructor, and `SimpleUString::c_str`. The `0x0041a580` `GetUsagePercent` helper is now documented as [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md), not dirty-region `Region`. Use only the local rectangle range as Region ownership evidence and keep the file-level source grouping in [UID:0000N3][Region](by-file/Region.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Region::Region` | `0x00554680-0x005546df` | Constructs an empty region rectangle after `LObject` construction. |
| `IntersectWithRect` | `0x00554a00-0x00554a16` | Intersects the region bounds with a source rectangle. |
| `ScalarDeletingDestructor` | `0x00554b00-0x00554b38` | Destroys the base object and optionally deletes storage. |

## Evidence Notes

- Older Wave2 notes already identify `0x00554680` as `Region::Region`.
- IDA caller/callee evidence places the adjacent [UID:00008R][Motion](by-class/Motion.md) rectangle helpers in the same dirty-region pipeline.
- IDA MCP checks on 2026-05-24 confirmed real function starts at `0x00554680`, `0x005546f0`, `0x00554760`, `0x005547a0`, `0x005547e0`, `0x00554a00`, and `0x00554b00`.
- 2026-05-26 IDA `py_eval` recheck confirms all mapped function starts from `0x00554680` through `0x00554b00`; representative xref counts include 90 callers for the constructor, 51 callers for `Region::IntersectWithRect`, and 32 callers for the offset helper.
- The same pass confirms `Region` vtable `0x00622f58`, constructor store `0x005546c1`, destructor slot `0x00554b00`, and `Region` RTTI/name records. See [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md).
- Generated `class_Region.cpp` includes unrelated string/numeric methods outside the local rectangle neighborhood; those should be re-owned before migration.
- 2026-05-27 IDA recheck assigns generated `Region::GetUsagePercent` at `0x0041a580` to [UID:0001UI][FittingRoomDownloadProgressState](by-type/by-struct/FittingRoomDownloadProgressState.md) because its only direct caller is `FittingRoomDialog::HandleFittingAction` at `0x0041cbbc`.

## Cross-References

- [UID:0000N3][Region](by-file/Region.md)
- [UID:0000LL][Motion](by-file/Motion.md)
- [UID:00008R][Motion](by-class/Motion.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md)
- [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md)
- [UID:000073][Layer](by-class/Layer.md)
- [UID:00005V][GrafPort](by-class/GrafPort.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the local rectangle-region methods, vtable, generated-owner pollution, and re-owned stray method were documented.
  - After: changed completion/confidence to `82/78`.
  - Evidence: existing evidence notes confirm local function starts, vtable data, constructor/destructor behavior, broad caller counts, and `GetUsagePercent` re-ownership; confidence remains below strong because generated `class_Region.cpp` contains unrelated string/numeric methods outside the local range.

- 2026-05-28:
  - Before: `Region::ScalarDeletingDestructor` and the local rectangle island ended at `0x00554b37`.
  - After: corrected the destructor and island end to `0x00554b38`.
  - Evidence: IDA MCP disassembly shows `0x00554b37` is the final byte of `retn 4`; padding begins at `0x00554b38`.
