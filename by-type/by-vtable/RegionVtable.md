*** UID:0001YL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The Region primary vtable is compiler-generated from the virtual Region
// declaration emitted by [UID:0000BV][Region](by-class/Region.md); do not reproduce compiler table data.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Region Vtable

## Status

- Entity kind: primary MSVC vtable.
- Covered class: [UID:0000BV][Region](by-class/Region.md).
- Likely source file: [UID:0000N3][Region](by-file/Region.md).
- Memory evidence: [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md).
- Exact vtable-data child: [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md).
- Binary span: [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md), exact `.rdata` bytes `BC EB 64 00 00 4B 55 00 10 4B 4F 00 C0 B6 41 00`, SHA256 `E424D2320108B18B0584CE53D3413F2484B821E6FB82C032C9D6304D90AB7F83`.
- Confidence: very strong for address, RTTI hierarchy, constructor store, destructor slot, inherited virtual identities, and compiler-generated source disposition.
- Assignment gate: this page remains `92/94`; current direct parent [UID:0000BV][Region](by-class/Region.md) and source parent [UID:0000N3][Region](by-file/Region.md) are both `94/94`. The earlier direct-parent `85/86` and source-parent `86/85` values were pre-completion score snapshots and are superseded historical evidence, not current gate state.

## Vtable

| Address | Slot | Target | Notes |
| --- | --- | --- | --- |
| `0x00622f54` | COL | `0x0064ebbc` | `??_R4Region@@6B@` complete-object locator pointer; TypeDescriptor `0x00678bf4`, CHD `0x0064ebd0`. |
| `0x00622f58` | `+0x00` | `0x00554b00` | Compiler scalar-deleting wrapper for source virtual `Region::~Region()`. |
| `0x00622f5c` | `+0x04` | `0x004f4b10` | Inherited `RuntimeClass *__thiscall LObject__GetRuntimeClass(LObject *this)`. |
| `0x00622f60` | `+0x08` | `0x0041b6c0` | Inherited `void __thiscall LObject__OnChangeMessage(LObject *this, LObject *owner, Message *message)` default no-op. |

The next dword at `0x00622f64` is `RightButtonMenuPane` RTTI metadata (`0x0064ec08`), not another `Region` virtual slot.

## RTTI And Compiler Generation

- `??_R4Region@@6B@` leads to a Region TypeDescriptor and a class hierarchy descriptor with exactly two base entries: Region and zero-displacement `LObject`. No multiple- or virtual-inheritance structure is present.
- Current IDA defines `Region` at size `0x14`, with `vftable` at `+0x00` and 16-byte `RectBounds m_bounds` at `+0x04`. The current [UID:0000BV][Region](by-class/Region.md) formal expresses that same source layout and virtual destructor.
- `Region::Region()` at `0x00554680-0x005546e1` constructs `LObject`, stores this vtable at instruction `0x005546c1`, clears `m_bounds`, and returns `this`. The compiler-generated scalar-deleting wrapper at `0x00554b00-0x00554b38` is referenced only by slot zero.
- The table is therefore compiler output from the virtual class declaration, not a developer-authored array. This page's formal is intentionally a covered-by comment; the actual declaration remains emitted by UID0000BV.

## IDA Evidence

- 2026-05-26 IDA `py_eval` reports `??_7Region@@6B@` at `0x00622f58`.
- 2026-06-01 IDA MCP `py_eval` over the boundary reports `0x00622f54 -> ??_R4Region@@6B@`, `0x00622f58 -> ??_7Region@@6B@`, and `0x00622f64 -> ??_R4RightButtonMenuPane@@6B@`, proving the exact vtable-data child range is `0x00622f54-0x00622f64`.
- The constructor at `0x00554680` stores this vtable at `0x005546c1`.
- IDA confirms `0x00554b00-0x00554b38` as the scalar deleting destructor and finds one direct vtable reference to it through `0x00622f58`.
- IDA name inventory also contains `Region` RTTI records at `0x0064ebbc`, `0x0064ebd0`, `0x0064ebe0`, `0x0064ebec`, and `0x00678bf4`.
- 2026-06-07 live IDA MCP recheck reconfirmed the exact four dwords represented by this type page: COL pointer `0x00622f54 -> 0x0064ebbc`, destructor slot `0x00622f58 -> 0x00554b00`, inherited/shared slot `0x00622f5c -> 0x004f4b10`, and default no-op slot `0x00622f60 -> 0x0041b6c0`.
- The same live pass reconfirmed the single vtable-base xref at constructor store `0x005546c1`, and `lookup_funcs` reconfirmed `Region` constructor `0x00554680-0x005546e1` and scalar deleting destructor `0x00554b00-0x00554b38`.
- 2026-06-11 IDA MCP live refresh reconfirmed the same compact slice and parent evidence: the constructor remains `0x00554680-0x005546e1` with 90 xrefs and the vtable store at `0x005546c1`, `Region::IntersectWithRect` remains `0x00554a00-0x00554a18`, the scalar deleting destructor remains `0x00554b00-0x00554b38` with its data ref from `0x00622f58`, and `0x00622f64` is still `RightButtonMenuPane` RTTI.
- 2026-07-24 B003 live IDA/raw-file recheck resolved both inherited slots by exact cell value and current function identity. Current xref enumeration reports 489 incoming refs to `LObject__GetRuntimeClass` and 517 to `LObject__OnChangeMessage`, but does not materialize the Region cells as explicit data edges; this limitation does not change the exact dword identities.
- The same recheck walked the complete Region RTTI graph and current `Region` UDT, confirmed the two-entry Region/LObject hierarchy and exact `0x14` layout, and rejected the historical no-local-UDT and unresolved-`nullsub_18` assumptions.

## Reconstruction Notes

Model `Region` as a small `LObject`-derived dirty-rectangle wrapper. Keep the neighboring `Motion` rectangle helpers documented with [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) while preserving the current `Region.h` declaration and `Region.cpp` definition route.

The exact vtable-data child [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md) uses this page as its type-layout evidence anchor. Both pages attach to source-level [UID:0000BV][Region](by-class/Region.md) and carry destination-specific covered-by comments so generated output records coverage without reproducing raw table bytes.

Do not reconstruct this table as a `void *` array, absolute addresses, linker directives, or assembly. Such output would resemble reverse-engineered data rather than the original human C++ and would compete with the compiler's class-derived RTTI/vtable emission.

## Assignment Decision

`AUTOGEN_PARENT_UID` is set to [UID:0000BV][Region](by-class/Region.md). This is a single primary vtable for the `Region` class, not a mixed vtable family: the complete-object locator names `Region`, the sole constructor store comes from `Region::Region`, the destructor slot targets `Region` scalar deleting destructor, and the successor dword is the next class' RTTI. The class and source parent now both clear the strict parent gates at `94/94`; their historical pre-completion `85/86` and `86/85` scores are retained above only as superseded provenance.

## Score Rationale

- Completion is `92` because the page now records all four cells, exact bytes/hash, full RTTI hierarchy, exact Region UDT, constructor/destructor routes, inherited virtual identities, boundaries, source ownership, compiler-generation disposition, and a valid covered-by formal.
- Confidence is `94` because the byte inventory, RTTI graph, constructor store, deleting-destructor slot, inherited function identities, successor boundary, and matching class formal were independently rechecked in current IDA and raw PE data.
- The historical blank-below-95 rationale is superseded. A covered-by formal is the correct source-shaped representation at this evidence level because UID0000BV emits the class declaration and the compiler emits the table.

## Cross-References

- [UID:0000BV][Region](by-class/Region.md)
- [UID:0000N3][Region](by-file/Region.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md)
- [UID:00008R][Motion](by-class/Motion.md)

## Changes

- 2026-07-24 B003 UID0002OP support implementation callback: Raised `86/91 -> 92/94`, installed the exact UID0001YL covered-by formal, added exact byte/hash, RTTI hierarchy, current Region UDT, constructor/destructor, inherited slot, boundary, and compiler-generation evidence, and rejected hand-authored raw-table C++.
- Historical assumption, now superseded: the prior score rationale kept C++ blank merely because the page was below 95 and earlier routing/history treated the inherited no-op as unresolved. Current structure rules, the source-emitting UID0000BV class formal, and current IDA evidence support the covered-by formal while preserving class ownership.

- 2026-06-07 A007 Batch064 coverage-error repair: Kept this page as the `0002OP` evidence anchor but documented that the memory child must remain autogen-unassigned because generated memory coverage rejects by-type/by-vtable parent `0001YL` as `autogen_parent_unknown`.
- 2026-06-01:
  - Before: the page had stale `0/0` metadata and listed only the vtable slots from `0x00622f58`, leaving the complete-object locator implicit.
  - Changed to: marked the page reconstructable at `84/90`, added exact child [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md), and recorded the exact `0x00622f54-0x00622f64` data range.
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 confirmed the `Region` COL pointer, three vtable slots, constructor store, scalar deleting destructor span, and `RightButtonMenuPane` boundary.
- 2026-06-07:
  - Before: the page was `84/90`, one completion point below the supervisor parent-side assignment gate for the exact Region vtable-data child.
  - Changed to: raised completion to `85` after adding live IDA MCP evidence for all cells, the sole vtable-base xref, and constructor/destructor sizes.
  - Summary/evidence: the associated update directly supports the [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md) type-layout relationship because both child and direct vtable page meet at least `85/85`; Batch064 later withheld the autogen parent only because generated memory coverage does not currently accept by-type/by-vtable parents.
- 2026-06-11 A004 normal task:
  - Before: the page was `85/90` but `AUTOGEN_PARENT_UID` was blank because the `Region` class and file parents did not yet clear the strict gate.
  - Changed to: raised to `86/91`, assigned to [UID:0000BV][Region](by-class/Region.md), and added assignment/score rationale.
  - Summary/evidence: live IDA MCP reconfirmed constructor and destructor boundaries, vtable store, all vtable cells, `Region::IntersectWithRect`, and the `RightButtonMenuPane` successor boundary; [UID:0000BV][Region](by-class/Region.md) and [UID:0000N3][Region](by-file/Region.md) now both score `94/94`. Their earlier `85/86` and `86/85` values are superseded pre-completion snapshots retained only as historical provenance.
