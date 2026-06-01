*** UID:0000C2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RingBufferIterator

## Summary

`RingBufferIterator` is a small companion class/helper in the ring-buffer island. Current evidence supports a real iterator-like type near [UID:0000C1][RingBuffer](by-class/RingBuffer.md): IDA confirms its vtable and scalar deleting destructor, while the constructor body remains raw code that IDA has not modeled as a function.

## Likely Original Placement

- Source: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Proposed path: `util/RingBuffer.cpp`
- Confidence: medium for concrete class identity, strong for ring-buffer file ownership; active iterator caller/use sites remain unresolved.

## Observed Functions

- Raw constructor-shaped body: `0x005566c0-0x005566eb`; IDA has no function object at this start, but raw bytes initialize the base, store the `RingBuffer*`, install vtable `0x006230dc`, set the iterator index to `-1`, and return with `retn 4`.
- IDA-confirmed reset helper: `0x005566f0-0x005566fa`.
- Raw reverse/end-position helper: `0x00556700-0x00556715`; IDA has no function object at this start.
- IDA-confirmed iterator-like advance helper: `0x00556720-0x00556749`.
- Raw retreat helper: `0x00556750-0x00556767`; decrements current index with wrap-around unless already at the ring read boundary.
- Raw boundary predicates: `0x00556770-0x0055677d` and `0x00556780-0x00556794`; compare current or next wrapped index against the ring read boundary.
- Raw element pointer helper: `0x005567a0-0x005567ae`; computes `storage + elementSize * currentIndex`.
- IDA-confirmed deleting destructor-like helper: `0x00556890-0x005568c8`.
- IDA-confirmed vtable: `??_7RingBufferIterator@@6B@` at `0x006230dc`, stored by the raw constructor at `0x005566d7`.
- Current `source-3/simroot_v2/util/RingBuffer.cpp` emits the iterator constructor, reset, next, and scalar deleting destructor in the same `util/RingBuffer.cpp` output as `RingBuffer`.
- Current `source-3/simroot_v2/util/RingBuffer.meta_wave3` reports one `RingBufferIterator` vtable at `0x006230dc`, matching IDA.

## Interpretation

Treat the iterator class as a useful label for the ring-buffer tail, not as final source-file split proof. The helpers at `0x00556700-0x005567ae` walk ring storage with wrap-around behavior, check boundary conditions against the ring read index, and compute the current element address. The vtable at `0x006230dc` supports a real small polymorphic companion. The missing IDA function object at `0x005566c0` and several tiny helper starts means generated function-boundary metadata still needs review, not that the bytes are arbitrary.

The next dword after the three visible slots is adjacent RTTI data for `ScreenPane`, not a fourth iterator virtual slot.

## Cross-References

- File: [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- Class: [UID:0000C1][RingBuffer](by-class/RingBuffer.md)
- Memory: [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md)
- Vtable: [UID:0001YN][RingBufferVtables](by-type/by-vtable/RingBufferVtables.md)
- Data issue: [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `72/76`.
  - Before: The page was unevaluated despite documenting the iterator-like companion, raw constructor bytes, modeled helper starts, vtable, and unresolved caller/use sites.
  - After: Scored as moderate-high completion and medium-high confidence because ring-buffer file ownership and vtable identity are strong, but concrete class identity and active iterator use remain partly unresolved.
  - Evidence: Existing observed-functions list, interpretation notes, generated metadata comparison, and ring-buffer/vtable cross-references support the score.
- 2026-06-01: Expanded the observed raw helper set from IDA MCP disassembly.
  - Evidence: raw bytes show complete helper bodies at `0x00556750`, `0x00556770`, `0x00556780`, and `0x005567a0`; the raw constructor endpoint was corrected to include its epilogue and `retn 4`.
