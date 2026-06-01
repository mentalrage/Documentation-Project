*** UID:0001XZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LineIterator vtable

## Status

- Entity kind: vtable layout and boundary note
- Address: `0x00624784`
- Proposed owner: [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md)
- Confidence: strong for the one real slot and adjacent string boundary.
- Evidence basis: IDA MCP disassembly/xref/data-neighborhood checks on 2026-05-25, 2026-05-26, and 2026-05-31, plus generated-data caveats where current `simroot_v2` crosses the vtable/string boundary.

## Slots

| Slot | Address | Target | Notes |
| --- | --- | --- | --- |
| 0 | `0x00624784` | `0x00573540` | `LineIterator::ScalarDeletingDestructor`. |

The concrete vtable extent is one dword. The ordinary destructor at `0x00573240` writes this vtable pointer into the object, but it is not itself a vtable slot.

## Adjacent Data Boundary

IDA disassembly of the data neighborhood shows:

```text
0x00624784  dd offset sub_573540
0x00624788  UTF-16LE "LOOKEXT.EPF",0
0x006247a0  UTF-16LE "LOOKEXT.PAL",0
0x006247b8  dd offset loc_450053
0x006247bc  dd offset loc_46004C
0x006247c0  UTF-16LE "LOOK.EPF",0
```

`0x00624788` is not a second vtable slot. It is the start of the adjacent `LOOKEXT.EPF` wide string used by self-look rendering paths. Any generated view that treats the string bytes as part of `LineIterator::vftable_00624784` is crossing the vtable/data boundary.

## Xrefs

IDA MCP `xrefs_to 0x00624784` reports:

| Ref | Type | Meaning |
| --- | --- | --- |
| `0x0056c13c` | data | Stack `LineIterator` construction in [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md). |
| `0x00573240` | data | Ordinary destructor resets `this[0]` to the vtable. |
| `0x0057354a` | data | Scalar deleting destructor resets `this[0]` to the vtable. |

2026-05-26 recheck: `xrefs_to 0x00624788` reports self-look rendering refs at `0x005674fa`, `0x00567529`, and `0x0056755d`. Those refs target the adjacent `LOOKEXT.EPF` string, not additional `LineIterator` vtable slots.

2026-05-31 recheck: IDA MCP `xrefs_to 0x00624784` again reports only the stack construction at `0x0056c13c`, ordinary destructor store at `0x00573240`, and scalar deleting destructor store at `0x0057354a`. IDA MCP `py_eval` reads dword `0x00573540` at `0x00624784`; bytes at `0x00624788` decode as UTF-16 `LOOKEXT.EPF`, followed by `LOOKEXT.PAL` at `0x006247a0`.

This vtable is reconstructable as source-declared/generated-binary data, but no C++ block is emitted here because the final declaration and parent placement are still below the 95+ autogen threshold.

## Cross-References

- [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md)
- [UID:000078][LineIterator](by-class/LineIterator.md)
- [UID:0000KQ][LineIterator](by-file/LineIterator.md)
- [UID:0001HL][0x00573240-0x00573247.LineIteratorDestructor](by-memory/0x00573240-0x00573247.LineIteratorDestructor.md)
- [UID:0001HO][0x00573540-0x00573564.LineIteratorScalarDeletingDestructor](by-memory/0x00573540-0x00573564.LineIteratorScalarDeletingDestructor.md)
- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-05-31 scoring and reconstructable classification:
  - What existed before: metadata was `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`, while the coverage row already described the vtable as reconstructable with strong confidence.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: current IDA MCP xrefs and byte reads prove the one-slot vtable boundary and adjacent string start. Scores remain below 95 because final source declaration placement is not yet fully audited.
