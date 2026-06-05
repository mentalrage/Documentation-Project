*** UID:0001W5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleUStringSso7Layout

## Status

- Entity kind: inferred struct/layout
- Likely owner: [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- Proposed header: `util/StringUtil.h`
- Confidence: strong for the 24-byte SSO-7 layout in the two endpoint helpers, medium for how it relates to the later pointer-backed string family.
- Reconstructable: true as a source-level string-layout declaration; C++ body remains blank because the final original class/template relationship is still unresolved.

## Layout Hypothesis

The early `SimpleUString` helper pair uses a 24-byte UTF-16 small-string layout with inline space for seven characters plus terminator:

| Offset | Size | Field | Notes |
| --- | --- | --- | --- |
| `0x00` | `0x10` | `heapBuffer` or `inlineBuffer[8]` | Inline buffer is used when capacity is `<= 7`; otherwise first dword is a heap pointer. |
| `0x10` | `0x04` | `length` | Counted wide characters, excluding terminator. |
| `0x14` | `0x04` | `capacity` | Inline capacity is `7`; heap capacity uses growth heuristics. |

## Evidence

- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) frees `heapBuffer` only when `capacity > 7`, then writes `length = 0`, `capacity = 7`, and `inlineBuffer[0] = 0`.
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) copies a counted wide buffer either into inline storage or newly allocated heap storage and preserves a NUL terminator.
- The historical [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md) aggregate is mixed; the middle functions are not layout evidence for this struct.
- Metadata explicitly calls this the UTF-16 SSO-7 subcluster.

## Open Questions

- Whether this is the same concrete class as the pointer-backed `SimpleUString` helpers around `0x00583210`, or a related `mystr::StringBase<wchar_t>` instantiation currently sharing the same canonical name.

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md)
- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md)
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md)

## Changes

- 2026-05-30: Existing layout evidence cited only raw endpoint addresses and the broad `0x00421310-0x004216cb` aggregate. Changed this to link the exact endpoint helper pages and warn that the aggregate middle is not layout evidence. Evidence: IDA MCP split of the mixed helper island and endpoint-helper decompilation.
- 2026-06-04: Marked `RECONSTRUCTABLE:TRUE` without changing scores.
  - Reasoning: the exact clear and counted-assign helper pages prove the 24-byte UTF-16 SSO-7 data layout as source-level structure information; parent attachment remains blank until this layout's relationship to the pointer-backed string family is resolved.
