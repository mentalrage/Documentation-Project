*** UID:0001YL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Region Vtable

## Status

- Entity kind: primary MSVC vtable.
- Covered class: [UID:0000BV][Region](by-class/Region.md).
- Likely source file: [UID:0000N3][Region](by-file/Region.md).
- Memory evidence: [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md).
- Exact vtable-data child: [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md).
- Confidence: strong for address, constructor store, and destructor slot.

## Vtable

| Address | Slot | Target | Notes |
| --- | --- | --- | --- |
| `0x00622f54` | COL | `0x0064ebbc` | `??_R4Region@@6B@` complete-object locator pointer. |
| `0x00622f58` | `+0x00` | `0x00554b00` | `Region` scalar deleting destructor. |
| `0x00622f5c` | `+0x04` | `0x004f4b10` | Shared/inherited `LObject` virtual. |
| `0x00622f60` | `+0x08` | `0x0041b6c0` | Shared/inherited no-op/default virtual. |

The next dword at `0x00622f64` is `RightButtonMenuPane` RTTI metadata (`0x0064ec08`), not another `Region` virtual slot.

## IDA Evidence

- 2026-05-26 IDA `py_eval` reports `??_7Region@@6B@` at `0x00622f58`.
- 2026-06-01 IDA MCP `py_eval` over the boundary reports `0x00622f54 -> ??_R4Region@@6B@`, `0x00622f58 -> ??_7Region@@6B@`, and `0x00622f64 -> ??_R4RightButtonMenuPane@@6B@`, proving the exact vtable-data child range is `0x00622f54-0x00622f64`.
- The constructor at `0x00554680` stores this vtable at `0x005546c1`.
- IDA confirms `0x00554b00-0x00554b38` as the scalar deleting destructor and finds one direct vtable reference to it through `0x00622f58`.
- IDA name inventory also contains `Region` RTTI records at `0x0064ebbc`, `0x0064ebd0`, `0x0064ebe0`, `0x0064ebec`, and `0x00678bf4`.

## Reconstruction Notes

Model `Region` as a small `LObject`-derived dirty-rectangle wrapper. Keep the neighboring `Motion` rectangle helpers documented with [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) until the final source split is decided.

## Cross-References

- [UID:0000BV][Region](by-class/Region.md)
- [UID:0000N3][Region](by-file/Region.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md)
- [UID:00008R][Motion](by-class/Motion.md)

## Changes

- 2026-06-01:
  - Before: the page had stale `0/0` metadata and listed only the vtable slots from `0x00622f58`, leaving the complete-object locator implicit.
  - Changed to: marked the page reconstructable at `84/90`, added exact child [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md), and recorded the exact `0x00622f54-0x00622f64` data range.
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 confirmed the `Region` COL pointer, three vtable slots, constructor store, scalar deleting destructor span, and `RightButtonMenuPane` boundary.
