*** UID:0001YL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- 2026-06-07 live IDA MCP recheck reconfirmed the exact four dwords represented by this type page: COL pointer `0x00622f54 -> 0x0064ebbc`, destructor slot `0x00622f58 -> 0x00554b00`, inherited/shared slot `0x00622f5c -> 0x004f4b10`, and default no-op slot `0x00622f60 -> 0x0041b6c0`.
- The same live pass reconfirmed the single vtable-base xref at constructor store `0x005546c1`, and `lookup_funcs` reconfirmed `Region` constructor `0x00554680-0x005546e1` and scalar deleting destructor `0x00554b00-0x00554b38`.

## Reconstruction Notes

Model `Region` as a small `LObject`-derived dirty-rectangle wrapper. Keep the neighboring `Motion` rectangle helpers documented with [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) until the final source split is decided.

The exact vtable-data child [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md) uses this page as its direct type-layout evidence anchor: this page is `85/90`, the child is `86/91`, and the relationship is direct ownership for the concrete `Region` vtable bytes. The child remains autogen-unassigned because generated memory coverage currently reports by-type/by-vtable parents as `autogen_parent_unknown`; keep this relationship as a cross-reference until that generated parent path is supported.

## Cross-References

- [UID:0000BV][Region](by-class/Region.md)
- [UID:0000N3][Region](by-file/Region.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md)
- [UID:00008R][Motion](by-class/Motion.md)

## Changes

- 2026-06-07 A007 Batch064 coverage-error repair: Kept this page as the `0002OP` evidence anchor but documented that the memory child must remain autogen-unassigned because generated memory coverage rejects by-type/by-vtable parent `0001YL` as `autogen_parent_unknown`.
- 2026-06-01:
  - Before: the page had stale `0/0` metadata and listed only the vtable slots from `0x00622f58`, leaving the complete-object locator implicit.
  - Changed to: marked the page reconstructable at `84/90`, added exact child [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md), and recorded the exact `0x00622f54-0x00622f64` data range.
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 confirmed the `Region` COL pointer, three vtable slots, constructor store, scalar deleting destructor span, and `RightButtonMenuPane` boundary.
- 2026-06-07:
  - Before: the page was `84/90`, one completion point below the supervisor parent-side assignment gate for the exact Region vtable-data child.
  - Changed to: raised completion to `85` after adding live IDA MCP evidence for all cells, the sole vtable-base xref, and constructor/destructor sizes.
  - Summary/evidence: the associated update directly supports the [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md) type-layout relationship because both child and direct vtable page meet at least `85/85`; Batch064 later withheld the autogen parent only because generated memory coverage does not currently accept by-type/by-vtable parents.
