*** UID:0001XZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000078 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LineIterator vtable

## Status

- Entity kind: non-emitting compiler vtable/RTTI layout support
- Address: `0x00624784`
- Direct owner: [UID:000078][LineIterator](by-class/LineIterator.md); the exact class declaration is the sole source cause.
- Concrete memory page: [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md)
- Confidence: very strong for the one real slot, self-only RTTI, compiler/source cause, all vptr-store xrefs, and adjacent string boundary.
- Evidence basis: IDA MCP disassembly/xref/data-neighborhood checks on 2026-05-25, 2026-05-26, 2026-05-31, 2026-06-04, and 2026-06-12.

## Slots

| Slot | Address | Target | Notes |
| --- | --- | --- | --- |
| 0 | `0x00624784` | `0x00573540` | MSVC scalar deleting destructor wrapper UID0001HO, generated from UID000078's explicit virtual destructor. |

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

`0x00624788` is not a second vtable slot. It is the start of the adjacent `LOOKEXT.EPF` wide string used by self-look rendering paths. Any analysis view that treats the string bytes as part of `LineIterator::vftable_00624784` is crossing the vtable/data boundary.

## Xrefs

IDA MCP `xrefs_to 0x00624784` reports:

| Ref | Type | Meaning |
| --- | --- | --- |
| `0x0056c13c` | data | Stack `LineIterator` construction in [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md). |
| `0x00573240` | data | Ordinary destructor resets `this[0]` to the vtable. |
| `0x0057354a` | data | Scalar deleting destructor resets `this[0]` to the vtable. |

2026-05-26 recheck: `xrefs_to 0x00624788` reports self-look rendering refs at `0x005674fa`, `0x00567529`, and `0x0056755d`. Those refs target the adjacent `LOOKEXT.EPF` string, not additional `LineIterator` vtable slots.

2026-05-31 recheck: IDA MCP `xrefs_to 0x00624784` again reports only the stack construction at `0x0056c13c`, ordinary destructor store at `0x00573240`, and scalar deleting destructor store at `0x0057354a`. IDA MCP `py_eval` reads dword `0x00573540` at `0x00624784`; bytes at `0x00624788` decode as UTF-16 `LOOKEXT.EPF`, followed by `LOOKEXT.PAL` at `0x006247a0`.

2026-06-04 recheck: live IDA MCP reports `0x00624780 -> ??_R4LineIterator@@6B@`, `0x00624784 -> 0x00573540`, and `0x00624788` as `aLookextEpf`. `XrefsTo(0x00624784)` remains limited to `0x0056c13c`, `0x00573240`, and `0x0057354a`; `XrefsTo(0x00624788)` remains the self-look `LOOKEXT.EPF` string references at `0x005674fa`, `0x00567529`, and `0x0056755d`.

2026-06-12 Agent-A004 Batch 272 recheck: direct IDA MCP `py_eval` reads dword `0x00573540` at `0x00624784`, byte-decodes UTF-16 `LOOKEXT.EPF` at `0x00624788`, and reconfirms the same three refs to the vtable address. The concrete by-memory vtable child is now [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md), which routes to [UID:000078][LineIterator](by-class/LineIterator.md). The one-slot extent is `0x4` / 4 bytes from `0x00624784` through `0x00624788` (Verified with int_convert.py); the containing RTTI-plus-slot child is `0x8` / 8 bytes (Verified with int_convert.py).

This page is intentionally false/non-emitting compiler-layout support. UID000078 now contains the complete source declaration; no raw RTTI/vtable array or duplicate class block belongs here. The former reconstructable/threshold conclusion is historical and superseded.

## Cross-References

- [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md)
- [UID:000078][LineIterator](by-class/LineIterator.md)
- [UID:0000KQ][LineIterator](by-file/LineIterator.md)
- [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md)
- [UID:0001HL][0x00573240-0x00573247.LineIteratorDestructor](by-memory/0x00573240-0x00573247.LineIteratorDestructor.md)
- [UID:0001HO][0x00573540-0x00573564.LineIteratorScalarDeletingDestructor](by-memory/0x00573540-0x00573564.LineIteratorScalarDeletingDestructor.md)
- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)

## Changes

- 2026-05-31 scoring and reconstructable classification:
  - What existed before: metadata was `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`, while the coverage row already described the vtable as reconstructable with strong confidence.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: current IDA MCP xrefs and byte reads prove the one-slot vtable boundary and adjacent string start. Scores remain below 95 because final source declaration placement is not yet fully audited.
- 2026-06-04 parent and evidence update:
  - What existed before: scored `82/90`, reconstructable, with blank `AUTOGEN_PARENT_UID`.
  - Changed to: scored `86/92` and attached to [UID:0000KQ][LineIterator](by-file/LineIterator.md).
  - Summary/evidence: live IDA MCP reverified the RTTI dword at `0x00624780`, one slot at `0x00624784`, `0x00624784 -> 0x00573540`, the limited vtable xrefs, and the `0x00624788` string boundary. Final C++ remains blank because final declaration/source placement is not 95+.
- 2026-06-12 Agent-A004 Batch 272 vtable child alignment:
  - What existed before: scored `86/92` and did not link the exact [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md) child.
  - Changed to: scored `88/93` with the concrete by-memory child cross-reference and current IDA MCP evidence.
  - Summary/evidence: live IDA MCP reverified the one dword slot, three xrefs, `LOOKEXT.EPF` boundary, and int-converted slot/child sizes.

## 2026-07-15 B003 UID0001HL Vtable Source-Cause Callback

- Current metadata is `92/94`, owner UID000078, `RECONSTRUCTABLE:FALSE`, blank emitter/position, and blank formal C++. This prevents a duplicate compiler table/class declaration while preserving exact ABI evidence.
- Exact compiler-data interval `[0x00624780,0x00624788)` contains complete-object-locator dword `0x006501b0` followed by the sole slot `0x00573540`; exact eight-byte SHA256 is `ECC0CB4E3F65595825D8336CEFAC40E50B23771D45541C6775EEF0E1DA9E465A`.
- Named RTTI chain is complete-object locator `0x006501b0`, hierarchy descriptor `0x006501c4`, base array `0x006501d4`, one base descriptor `0x006501dc`, and type descriptor `0x00679168`. Base count one plus the self-only array proves LineIterator has no base class.
- Because no base can provide virtual destruction, the root class must explicitly declare its virtual destructor. UID000078's inline empty virtual destructor is the human source cause for this one-slot vtable, UID0001HL retained complete-object body, and UID0001HO scalar wrapper.
- The vtable address has exactly three refs: parser stack construction `0x0056c13c`, UID0001HL store `0x00573240`, and UID0001HO store `0x0057354a`. UID000190 is nonvirtual and has no slot.
- Address `0x00624788` begins UTF-16 `LOOKEXT.EPF`; its three SelfLook rendering refs are unrelated string consumers. Preserve that exact successor boundary and reject every interpretation that extends the vtable into resource bytes.
- Compiler-generated layout is regenerated from UID000078. Do not emit raw tables, RTTI descriptors, scalar-wrapper flags, vptr stores, addresses, EH/cookie code, or decompiler labels.
- Historical parent UID0000KQ, reconstructable, threshold, and unresolved-declaration statements remain provenance but no longer describe the current source disposition.
