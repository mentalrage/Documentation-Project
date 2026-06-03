*** UID:0001W4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleUStringPointerBackedLayout

## Status

- Entity kind: inferred struct/layout
- Likely owner: [UID:0000OA][StringBase](by-file/StringBase.md) / [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- Proposed header: `util/StringUtil.h`
- Confidence: medium-high for the pointer/header layout; medium for final original type name and source-file owner.

## Layout Hypothesis

The pointer-backed `SimpleUString` / `StringBase` family stores a pointer to shared or allocated character data. The same 12-byte header prefix is used for ANSI and UTF-16 buffers; the object field points at character data, and the header immediately before it stores refcount, length, and capacity.

Observed access pattern:

| Expression | Meaning |
| --- | --- |
| `this->m_data` | Pointer to ANSI or UTF-16 character data, depending on specialization/helper. |
| `((int *)this->m_data)[-3]` | Reference count; formatting workers detach when this is greater than one. |
| `((int *)this->m_data)[-2]` | Stored character count; `0x005845b0` uses this as the left range length. |
| `((int *)this->m_data)[-1]` | Capacity; formatting workers grow when this is smaller than the estimated/required capacity. |
| shared sentinel at `0x00670278` / `0x00670290` | Empty/default wide and ANSI storage used by varargs initializer wrappers and release paths. |

## Evidence

- [UID:0002LJ][0x00583210-0x00583272.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583272.StringBaseAnsiFormatCtor.md) seeds the object with the ANSI empty sentinel `0x00670290` before forwarding ANSI varargs to [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md).
- [UID:0002LK][0x00583280-0x005832e2.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e2.StringBaseWideFormatCtor.md) seeds the object with the wide empty sentinel `0x00670278` before forwarding wide varargs to [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md).
- [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md) and [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md) both test `data[-3]` for sharing, compare/grow against `data[-1]` capacity, and write final length into `data[-2]`.
- [UID:0002LO][0x005845b0-0x005845eb.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845eb.StringBaseCompareWideLiteral.md) computes `lhsEnd = lhsBegin + 2 * lhsBegin[-2]`, then compares against a NUL-terminated literal range through [UID:0002LN][0x005840f0-0x00584159.WideRangeCompare](by-memory/0x005840f0-0x00584159.WideRangeCompare.md).
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) records the same 12-byte header prefix from allocation/release/copy-on-write helpers.

## Open Questions

- Whether this layout should be named `SimpleUString`, `StringBase<wchar_t>`, or another original template/type name in final source.
- How this layout relates to [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md).
- Exact ownership of the remaining un-split helper functions in [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md) and [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md).

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md)
- [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0002LJ][0x00583210-0x00583272.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583272.StringBaseAnsiFormatCtor.md)
- [UID:0002LK][0x00583280-0x005832e2.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e2.StringBaseWideFormatCtor.md)
- [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md)
- [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md)
- [UID:0002LN][0x005840f0-0x00584159.WideRangeCompare](by-memory/0x005840f0-0x00584159.WideRangeCompare.md)
- [UID:0002LO][0x005845b0-0x005845eb.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845eb.StringBaseCompareWideLiteral.md)

## Changes

- Before: the page was ungraded and described only a narrow wide-string pointer hypothesis with `m_data[-2]` and sentinel references.
- Changed to: marked the layout reconstructable, documented the 12-byte ref-counted header fields, and tied each field to IDA-confirmed exact child functions.
- Evidence: IDA MCP `lookup_funcs`, `decompile`, `callers`, `callees`, `xrefs_to`, and byte checks on 2026-05-31 for the constructor/format/compare helpers listed above. Scores remain below `95+` because final original type naming, source-file ownership, and the remaining un-split helper family are still open.
- 2026-06-03: refreshed the formatting-worker links to the corrected half-open IDA ranges `0x00583720-0x00583832` and `0x00583840-0x00583968`.
