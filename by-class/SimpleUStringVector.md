*** UID:0000DA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleUStringVector

## Summary

`SimpleUStringVector` is a small begin/end/capacity container for contiguous 4-byte pointer-backed [UID:0000D9][SimpleUString](by-class/SimpleUString.md) / string-handle slots. It destroys owned string handles, grows storage by copy-constructing slots into a new buffer, and provides a push-back fast path.

## Likely Original Placement

- Source: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Proposed path: `util/StringUtil.cpp`
- Confidence: strong for utility ownership, medium for exact file split.

## Methods

- [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md): destructor, destroys all 4-byte string-handle slots and frees backing storage.
- [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md): grow/insert helper.
- [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md): push-back helper.

## Evidence

- Metadata says this class was restored from the raw missing class `cls_0x493f10`; this is treated only as a lead.
- IDA decompilation proves the layout is a standard `begin`, `end`, `capacity` pointer triplet and that element stride is four bytes.
- `DATFile::ReadAllLines` is a clear caller for grow/insert when appending converted lines.
- The string mutation helper at `0x005839c0` calls push-back at two sites and calls grow/insert directly at two other sites.
- Config and Socket override notes already model matching `SimpleUStringVector` fields.
- IDA confirms the corrected last-byte-inclusive ranges: `0x00493f10-0x00493f79`, `0x0049cc40-0x0049ce48`, and `0x00584910-0x0058498b`, with `0xcc` padding immediately after each function.

## Generated Data Caveats

IDA reports `GrowAndInsert` start `0x0049cc40` with size `0x209`, making `0x0049ce48` the last executable byte, while metadata records an end around `0x0049ce23`. Use IDA-confirmed function size for memory-range decisions until Wave3 data is rechecked.

## Cross-References

- File: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Memory: [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md), [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md), [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md)
- Layout: [UID:0001W6][SimpleUStringVectorLayout](by-type/by-struct/SimpleUStringVectorLayout.md)
- Related: [UID:0000D9][SimpleUString](by-class/SimpleUString.md), [UID:0000IN][DATFile](by-file/DATFile.md), [UID:0000IE][Config](by-file/Config.md), [UID:0000DD][Socket](by-class/Socket.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents container layout, likely utility placement, destructor/grow/push-back ranges, key callers, layout cross-reference, and generated-data range caveat; completion remains limited because it lacks source-ready C++ and full caller inventory.

- 2026-05-31: Corrected the vector element model and exact memory ranges.
  - Before: the page described contiguous `SimpleUString` elements without spelling out the recovered slot size and kept reconstructable metadata blank.
  - After: marked the class reconstructable, documented 4-byte pointer-backed string-handle slots, linked the last-byte-inclusive function pages, and raised scores to `82/84`.
  - Evidence: IDA MCP decompilation of the destructor, grow/insert, and push-back helpers shows pointer differences shifted by two and slot construction/destruction through string-handle helpers; byte checks confirm padding after each corrected function range.
