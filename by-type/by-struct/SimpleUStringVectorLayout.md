*** UID:0001W6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000DA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleUStringVectorLayout

## Status

- Entity kind: inferred struct/layout
- Direct owner: [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md)
- Proposed header: `util/StringUtil.h`
- Confidence: strong for the triplet layout and 4-byte element stride; medium-high for final source-file split.

## Layout

`SimpleUStringVector` is a standard contiguous-vector triplet whose element slots are 4-byte pointer-backed string handles. It does not store 24-byte SSO `SimpleUString` objects inline in this recovered family; IDA confirms all size/capacity arithmetic uses pointer differences shifted by two bits.

| Offset | Size | Field | Notes |
| --- | --- | --- | --- |
| `0x00` | `0x04` | `begin` | Pointer to first 4-byte string-handle slot. |
| `0x04` | `0x04` | `end` | Pointer to one-past-last constructed 4-byte slot. |
| `0x08` | `0x04` | `capacity` | Pointer to one-past-last allocated 4-byte slot. |

Each element slot contains the data pointer for a pointer-backed UTF-16 string. Element destruction/copy construction therefore operates on the slot address and calls the string-handle helpers around `0x00582a90`/`0x00582b70`, rather than stepping by a larger object size.

## Field Evidence

| Field | Primary evidence | Interpretation |
| --- | --- | --- |
| `begin` | Destructor [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md) reads offset `+0x00`, walks from `begin` to `end`, frees the backing allocation, and clears the triplet. | Start of the allocated 4-byte slot array. |
| `end` | Destructor reads offset `+0x04`; push-back [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md) compares `end` against `capacity`, constructs at `end`, then increments by four. | One-past-last constructed string-handle slot. |
| `capacity` | Grow/insert [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md) computes capacity from `(capacity - begin) >> 2`; push-back slow path delegates to grow/insert when `end == capacity`. | One-past-last allocated string-handle slot. |
| element stride | Grow/insert computes size, insertion index, and capacity with right shifts by two; destructor and push-back advance by one dword per slot. | Confirms pointer-backed string-handle slots, not inline 24-byte `SimpleUString` objects. |

## Evidence

- [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md) walks `[begin, end)` in 4-byte increments, destroys each string-handle slot with `0x00582b70`, frees `begin`, then clears all three pointers.
- [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md) computes size, insertion index, and capacity as pointer differences shifted right by two, allocates a new slot array, copy-constructs elements, destroys the old range, and updates the triplet.
- [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md) constructs at `end` and increments `end` by four when capacity remains; if full it delegates to grow/insert.
- IDA byte checks confirm padding after each reviewed function boundary: `0x00493f7a-0x00493f80`, `0x0049ce49-0x0049ce50`, and `0x0058498c-0x00584990`.
- 2026-06-08 A002 Batch129 live IDA MCP rechecked the helper starts and sizes: `0x00493f10` size `0x6a`, `0x0049cc40` size `0x209`, and `0x00584910` size `0x7c`. `callers` still reports broad use of the destructor and grow/insert plus two push-back callers from the string mutation helper, and `callees` still routes through string-handle construction/destruction and backing-storage allocation/free helpers.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md). The child layout is now `86/90`; the direct class parent was refreshed to `85/88`, and the source file parent [UID:0000OB][StringUtil](by-file/StringUtil.md) already clears `86/88`. This is the object layout for the class itself, so the class is the direct parent and the file remains source-module context.

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md)
- [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md)
- [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md)
- [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md)

## Changes

- Before: the page was ungraded and described the vector as containing `SimpleUString` elements without stating the recovered slot size.
- Changed to: marked the layout reconstructable, documented the 4-byte pointer-backed string-handle element stride, and tied each field/stride claim to IDA-confirmed destructor, grow/insert, and push-back behavior.
- Evidence: IDA MCP `lookup_funcs`, `decompile`, `callers`, `callees`, and byte checks on 2026-05-31 for `0x00493f10`, `0x0049cc40`, and `0x00584910`.
- 2026-06-08 A002 Batch129:
  - Before: `COMPLETION:78`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:86`, `CONFIDENCE:90`, `AUTOGEN_PARENT_UID:0000DA`.
  - Evidence: added field-by-field layout evidence, live IDA MCP recheck details for the three helper starts/caller/callee sets, and the strict assignment-gate rationale. The direct class parent [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md) was improved to `85/88`, while [UID:0000OB][StringUtil](by-file/StringUtil.md) remains the broader source-module parent.
