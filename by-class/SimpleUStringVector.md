*** UID:0000DA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Autogen parent: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Confidence: strong for utility ownership, exact helper ranges, 4-byte slot behavior, and child attachment; medium-high for exact original file split.

## Methods

- [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md): destructor, destroys all 4-byte string-handle slots and frees backing storage; B001-016 attaches this exact child directly to this class.
- [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md): grow/insert helper.
- [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md): push-back helper.

## Evidence

- Earlier metadata names this class from the raw class lead `cls_0x493f10`; this is treated only as a lead.
- Live IDA decompilation proves the layout is a standard `begin`, `end`, `capacity` pointer triplet and that element stride is four bytes.
- `DATFile::ReadAllLines` is a clear caller for grow/insert when appending converted lines.
- The string mutation helper at `0x005839c0` calls push-back at two sites and calls grow/insert directly at two other sites.
- Config and Socket override notes already model matching `SimpleUStringVector` fields.
- 2026-06-04 live IDA confirms the corrected last-byte-inclusive ranges: `0x00493f10-0x00493f79`, `0x0049cc40-0x0049ce48`, and `0x00584910-0x0058498b`, with `0xcc` padding immediately after each function.
- Live IDA caller/callee checks report 19 callers to the destructor, 7 callers to grow/insert, 2 callers to push-back, and helper calls through `0x00582a90`, `0x00582b70`, `0x0049d530`, and `0x00584ba0`.

## Batch 129 Parent-Gate Audit

This class is the direct owner for [UID:0001W6][SimpleUStringVectorLayout](by-type/by-struct/SimpleUStringVectorLayout.md). The layout page describes the class's own `begin/end/capacity` object state rather than a free helper record. 2026-06-08 live IDA MCP reconfirmed the exact helper starts and sizes: destructor `0x00493f10` size `0x6a`, grow/insert `0x0049cc40` size `0x209`, and push-back `0x00584910` size `0x7c`. The same live pass reconfirmed caller fan-in for all three helpers and callee sets through the string-handle construct/destroy helpers, supporting the 4-byte string-handle slot model.

## Recovered Metadata Caveats

Live IDA reports `GrowAndInsert` start `0x0049cc40` with size `0x209`, making `0x0049ce48` the last executable byte, while earlier metadata records an end around `0x0049ce23`. Use IDA-confirmed function size for memory-range decisions.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The page now records all three high-confidence child helpers, the attached StringUtil parent, live IDA range/caller/callee evidence, 4-byte slot behavior, vector triplet layout, metadata caveats, and the direct layout-type ownership audit. Completion remains capped because the exact original class/file split and public API names are still not final-source quality. |
| Confidence `88` | Confidence is strong for StringUtil utility ownership and vector behavior because live IDA confirms ranges, decompilation shape, caller sets, child helpers, and padding. It remains below final-source confidence because the original source could still have split this helper into a narrower string-vector implementation file. |

## Cross-References

- File: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Memory: [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md), [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md), [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md)
- Layout: [UID:0001W6][SimpleUStringVectorLayout](by-type/by-struct/SimpleUStringVectorLayout.md)
- Related: [UID:0000D9][SimpleUString](by-class/SimpleUString.md), [UID:0000IN][DATFile](by-file/DATFile.md), [UID:0000IE][Config](by-file/Config.md), [UID:0000DD][Socket](by-class/Socket.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents container layout, likely utility placement, destructor/grow/push-back ranges, key callers, layout cross-reference, and metadata range caveat; completion remains limited because it lacks source-ready C++ and full caller inventory.

- 2026-05-31: Corrected the vector element model and exact memory ranges.
  - Before: the page described contiguous `SimpleUString` elements without spelling out the recovered slot size and kept reconstructable metadata blank.
  - After: marked the class reconstructable, documented 4-byte pointer-backed string-handle slots, linked the last-byte-inclusive function pages, and raised scores to `82/84`.
  - Evidence: IDA MCP decompilation of the destructor, grow/insert, and push-back helpers shows pointer differences shifted by two and slot construction/destruction through string-handle helpers; byte checks confirm padding after each corrected function range.
- 2026-06-04 live IDA attachment pass:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`, `AUTOGEN_PARENT_UID` blank, and stale metadata caveat wording.
  - After: `COMPLETION:84`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000OB`, and live IDA evidence/caller counts recorded.
  - Evidence: live IDA reconfirmed destructor/grow/push-back bounds, 4-byte slot arithmetic, child helper calls, caller counts, and padding. C++ remains blank because final API/source split remains below the 95/95 gate.
- 2026-06-08 A002 Batch129 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`.
  - After: `COMPLETION:85`, `CONFIDENCE:88`.
  - Evidence: added the direct owner audit for [UID:0001W6][SimpleUStringVectorLayout](by-type/by-struct/SimpleUStringVectorLayout.md) and refreshed live IDA MCP evidence for the destructor, grow/insert, and push-back helper starts, caller sets, and callees. Confidence remains unchanged because the final public API/source split remains provisional.
- 2026-06-10 B001-016 split audit:
  - Changed to: no score change.
  - Evidence: [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md) was raised to `85/89` and rerouted from direct file parent [UID:0000OB][StringUtil](by-file/StringUtil.md) to this class after IDA MCP reconfirmed the destructor range, decompilation, disassembly, caller/callee set, padding, and vector triplet layout.
