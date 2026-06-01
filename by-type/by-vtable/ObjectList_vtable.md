*** UID:0001YB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectList vtable

## Status

- Entity kind: vtable layout
- Address: `0x00620288`
- Confidence: strong for the three-slot table, preceding RTTI pointer, constructor/destructor stores, and adjacent `ObjectPane` RTTI boundary.
- Proposed owner: [UID:0000M4][ObjectList](by-file/ObjectList.md)
- Exact vtable-data child: [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md)

## Slots

IDA MCP memory inspection on 2026-05-24 shows:

| Slot | Address | Target | Notes |
| --- | --- | --- | --- |
| 0 | `0x00620288` | `0x00537290` | `ObjectList::ScalarDeletingDestructor`. |
| 1 | `0x0062028c` | `0x004f4b10` | inherited `LObject` runtime/type helper. |
| 2 | `0x00620290` | `0x0041b6c0` | inherited no-op/null virtual. |

The preceding dword at `0x00620284` resolves to `??_R4ObjectList@@6B@`. The next dword at `0x00620294` resolves to `??_R4ObjectPane@@6B@`, so the concrete `ObjectList` vtable is the three-slot `LObject`-style surface.

## Evidence

- `ObjectList::ObjectList` writes `ObjectList::vftable` after constructing the base object.
- `ObjectList` non-lifecycle helpers around `0x00530d00-0x0053728e` are non-virtual direct calls and helper-table dispatch code, not vtable slots.
- The destructor wrapper at `0x00537290` has no direct callers in IDA, consistent with vtable dispatch.

## 2026-06-01 IDA Recheck

- IDA MCP `py_eval` reports `??_7ObjectList@@6B@` at `0x00620288` and reads `0x00620284 -> ??_R4ObjectList@@6B@`, slots `0x00620288-0x00620290`, and `0x00620294 -> ??_R4ObjectPane@@6B@`.
- IDA xrefs to `0x00620288` report vptr stores at `0x00530f19` and `0x00531288`.
- IDA xrefs to `0x00537290` report the vtable data reference at `0x00620288`, confirming slot `0` as the scalar deleting destructor.
- This recheck closes the former boundary caveat and splits exact data page [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md).

## Cross-References

- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md)
- [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)
- [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md)
- [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md)

## Changes

### 2026-05-28 - Non-Virtual Helper Range Expanded

- What existed before: the evidence note only mentioned non-lifecycle helpers around `0x00532530-0x00532f67`.
- What changed: it now covers the broader non-virtual helper surface through `0x0053728e`.
- Why: IDA MCP and manual disassembly classify the formerly unknown span as ObjectList direct-call/helper-table code, not new vtable slots.

### 2026-06-01 - Boundary And Exact Data Split

- What existed before: the page was unevaluated in validator metadata and still carried an open caveat around the adjacent RTTI boundary after slot `2`.
- What changed: the page is marked reconstructable, graded `84/90`, and links the exact `0x00620284-0x00620294` ObjectList vtable-data child.
- Why: IDA MCP `py_eval` and xref checks verify the preceding ObjectList RTTI dword, the three vtable slots, the following ObjectPane RTTI dword, and the ObjectList vptr stores.
